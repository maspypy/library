#!/usr/bin/env python3
"""Bounded CI continuation: preserve real failures, retry only unvisited tests.

State travels as GitHub Actions artifacts, never in timestamps.remote.json.
New pushes always start a fresh attempt and recheck previously failed tests.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import os
import pathlib
import re
import subprocess
import sys
import time
import urllib.error
import urllib.request
from urllib.parse import quote
from collections import Counter
from typing import Any

GROUPS = ("all",)
STATUSES = ("ac", "failed", "pending", "rate_limited")
SCHEMA = 2
MAX_CONTINUATIONS = 3


def group_of(path: pathlib.Path) -> str:
    return "all"


def shard_of(path: pathlib.Path, shards: int) -> int:
    digest = hashlib.sha256(path.as_posix().encode()).digest()
    return int.from_bytes(digest[:8], "big") % shards


def load(path: pathlib.Path) -> dict[str, Any]:
    data = json.loads(path.read_text(encoding="utf-8"))
    if not isinstance(data, dict):
        raise ValueError(f"expected JSON object in {path}")
    return data


def validate_state(state: dict[str, Any], *, origin: str, round_number: int,
                   previous_run_id: int) -> None:
    if (state.get("schema") != SCHEMA or state.get("origin_sha") != origin or
            state.get("round") != round_number or state.get("run_id") != previous_run_id):
        raise ValueError(
            "prior state has a mismatched schema, source, round, or run_id")
    if type(round_number) is not int or not 0 <= round_number <= MAX_CONTINUATIONS:
        raise ValueError("invalid round")
    if type(previous_run_id) is not int or previous_run_id <= 0:
        raise ValueError("invalid run ID")
    last = state.get("last_429")
    if type(last) not in (int, float) or not 0 <= last <= time.time() + 60:
        raise ValueError("invalid 429 timestamp")
    statuses = state.get("statuses")
    blocked = state.get("blocked")
    if not isinstance(statuses, dict) or not isinstance(blocked, dict):
        raise ValueError("invalid previous verification state")
    if "rate_limited" in statuses.values() and not last:
        raise ValueError("rate-limited state requires a timestamp")
    expected_due = last + \
        4200 if "rate_limited" in statuses.values(
        ) and "pending" not in statuses.values() else 0
    if state.get("not_before") != expected_due or state.get("retry_target") not in ("none", "all"):
        raise ValueError("invalid continuation decision")
    if set(blocked) != set(GROUPS) or not all(type(v) is bool for v in blocked.values()):
        raise ValueError("invalid blocked groups")
    for name, status in statuses.items():
        if (not isinstance(name, str) or not name.startswith("test/") or
                not name.endswith(".test.cpp") or status not in STATUSES):
            raise ValueError(f"invalid previous status entry: {name!r}")


def unchanged_sources(origin: str, head: str = "HEAD") -> bool:
    if not re.fullmatch(r"[0-9a-f]{40}", origin):
        raise ValueError("source sha must be a complete lowercase Git SHA")
    check = subprocess.run(
        ["git", "diff", "--quiet", origin, head, "--", ".",
         ":(exclude).verify-helper/timestamps.remote.json"],
        check=False, capture_output=True, text=True,
    )
    if check.returncode not in (0, 1):
        raise RuntimeError(
            f"could not compare repository versions: {check.stderr}")
    return check.returncode == 0


def save_output(name: str, value: str) -> None:
    output = os.environ.get("GITHUB_OUTPUT")
    if output:
        with open(output, "a", encoding="utf-8") as fh:
            fh.write(f"{name}={value}\n")
    print(f"{name}={value}")


def prepare(args: argparse.Namespace) -> None:
    if args.continuation:
        if not 1 <= args.round <= MAX_CONTINUATIONS or not args.previous_run_id:
            raise ValueError("invalid continuation round/run-id")
        if not args.origin_sha or not unchanged_sources(args.origin_sha):
            raise ValueError(
                "source tree changed since original run; cancel stale continuation")
        state = load(args.previous_state)
        validate_state(state, origin=args.origin_sha,
                       round_number=args.round - 1,
                       previous_run_id=args.previous_run_id)
        if args.target not in GROUPS and args.target != "both":
            raise ValueError("invalid target")
        # Only allow targets authorized by the preceding run's decision.
        if state.get("retry_target") != args.target:
            raise ValueError("target differs from previous retry decision")
        from resume_verify import check_predecessor
        check_predecessor(args.previous_run_id, current=int(
            os.environ["GITHUB_RUN_ID"]))
        if state.get("retry_target") == "none" or time.time() < state.get("not_before", 0):
            raise ValueError("unauthorized or premature continuation")
        origin = args.origin_sha
    else:
        if args.round != 0 or args.previous_run_id or args.origin_sha or args.target != "both":
            raise ValueError(
                "a fresh verification must use default continuation inputs")
        origin = subprocess.check_output(
            ["git", "rev-parse", "HEAD"], text=True).strip()
    save_output("origin_sha", origin)


def check_shards(args: argparse.Namespace) -> None:
    """Require complete artifacts, even when verification itself failed."""
    if args.shards <= 0:
        raise ValueError("--shards must be positive")
    missing = [
        f"{kind}-{group}-{shard}.json"
        for group in GROUPS
        for shard in range(args.shards)
        for kind in ("complete", "states", "timestamps")
        if not (args.input_dir / f"{kind}-{group}-{shard}.json").is_file()
    ]
    if args.job_result not in ("success", "failure") or missing:
        raise RuntimeError(
            f"cannot finalize verification: verify_all result={args.job_result!r}; "
            f"missing shard outputs ({len(missing)}): {', '.join(missing)}. "
            "Check workflow annotations for reusable-workflow input errors, "
            "and shard setup/verification/upload logs. No state will be published.")


def summarize(args: argparse.Namespace) -> None:
    if args.round < 0 or args.round > MAX_CONTINUATIONS:
        raise ValueError("invalid round")
    run_groups = GROUPS if args.target == "both" else (args.target,)
    previous = None
    if args.previous_state:
        previous = load(args.previous_state)
        validate_state(previous, origin=args.origin_sha,
                       round_number=args.round - 1,
                       previous_run_id=args.previous_run_id)
    elif args.round:
        raise ValueError("continuation is missing the previous state")
    if args.round and previous.get("retry_target") != args.target:
        raise ValueError("this target was not authorized by the previous run")

    statuses = dict(previous["statuses"]) if previous else {}
    blocked = dict(previous["blocked"]
                   ) if previous else dict.fromkeys(GROUPS, False)
    infrastructure_error = dict.fromkeys(GROUPS, False)
    attempts = Counter()
    last_429 = previous["last_429"] if previous else 0
    for group in run_groups:
        # Previous results from this group are replaced, never resurrected.
        for name in list(statuses):
            if group_of(pathlib.Path(name)) == group:
                del statuses[name]
        blocked[group] = False
        for shard in range(args.shards):
            manifest = load(args.input_dir / f"complete-{group}-{shard}.json")
            result = load(args.input_dir / f"states-{group}-{shard}.json")
            if (manifest.get("group") != group or manifest.get("shard") != shard or
                    manifest.get("shards") != args.shards or
                    type(manifest.get("verify_exit_code")) is not int or
                    type(manifest.get("infrastructure_error")) is not bool):
                raise ValueError(
                    f"invalid completion manifest for {group}:{shard}")
            if result.get("group") != group or result.get("shard") != shard:
                raise ValueError(
                    f"invalid test status file for {group}:{shard}")
            state_map = result.get("statuses")
            if not isinstance(state_map, dict) or len(state_map) != manifest.get("selected_files"):
                raise ValueError(
                    f"test statuses incomplete for {group}:{shard}")
            for name, status in state_map.items():
                path = pathlib.Path(name)
                if (not name.startswith("test/") or not name.endswith(".test.cpp") or
                        group_of(path) != group or shard_of(path, args.shards) != shard or
                        status not in STATUSES or name in statuses):
                    raise ValueError(
                        f"unexpected or duplicate test status: {name!r}")
                statuses[name] = status
            stamp = manifest.get("last_429")
            if type(stamp) not in (int, float) or not 0 <= stamp <= time.time() + 60:
                raise ValueError("invalid 429 timestamp")
            last_429 = max(last_429, stamp)
            blocked[group] |= manifest.get("rate_limited") is True
            infrastructure_error[group] |= manifest.get(
                "infrastructure_error") is True
            count = manifest.get("attempted_files")
            if type(count) is not int or count < 0 or count > len(state_map):
                raise ValueError(
                    f"invalid attempted file count for {group}:{shard}")
            attempts[group] += count

    # A seemingly complete artifact must cover the *entire* source tree.
    # In particular, dropping a pending path must never produce a false AC.
    expected_paths = {
        p.as_posix()
        for p in pathlib.Path("test").rglob("*.test.cpp")
    }
    if set(statuses) != expected_paths:
        missing = sorted(expected_paths - set(statuses))
        extra = sorted(set(statuses) - expected_paths)
        raise ValueError(f"state does not cover all test sources: "
                         f"missing={missing[:5]}, extra={extra[:5]}")

    if previous and any(statuses.get(p) != v for p, v in previous["statuses"].items() if v in ("ac", "failed")):
        raise ValueError("terminal result regressed")
    retry = []
    for group in run_groups:
        pending = sum(status in ("pending", "rate_limited") for p, status in statuses.items()
                      if group_of(pathlib.Path(p)) == group)
        if previous:
            old_pending = sum(status in ("pending", "rate_limited") for p, status in previous["statuses"].items()
                              if group_of(pathlib.Path(p)) == group)
            made_progress = 0 <= pending < old_pending
        else:
            made_progress = any(s != "pending" for s in statuses.values())
        if (pending > 0 and made_progress and
                not infrastructure_error[group] and args.round < MAX_CONTINUATIONS):
            retry.append(group)

    target = "both" if len(retry) == 2 else retry[0] if retry else "none"
    data = {
        "schema": SCHEMA, "origin_sha": args.origin_sha,
        "run_id": args.run_id, "round": args.round,
        "statuses": dict(sorted(statuses.items())),
        "blocked": blocked,
        "last_429": last_429,
        "not_before": last_429 + 4200 if "rate_limited" in statuses.values() and "pending" not in statuses.values() else 0,
        "retry_target": target,
    }
    validate_state(data, origin=args.origin_sha, round_number=args.round,
                   previous_run_id=args.run_id)
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(
        data, sort_keys=True, indent=2) + "\n", encoding="utf-8")
    counts = Counter(statuses.values())
    print("verification states:", dict(counts), "429 blocked:", blocked,
          "infrastructure errors:", infrastructure_error,
          "round:", args.round, "retry target:", target)
    save_output("retry_target", target)
    save_output("next_round", str(args.round + 1))


def dispatch(args: argparse.Namespace) -> None:
    state = load(args.state)
    validate_state(state, origin=state["origin_sha"], round_number=state["round"],
                   previous_run_id=state["run_id"])
    target = state["retry_target"]
    if target == "none" or time.time() < state["not_before"]:
        print("no continuation needed")
        return
    if state["round"] >= MAX_CONTINUATIONS:
        raise ValueError("maximum continuation count exceeded")
    if not unchanged_sources(state["origin_sha"]):
        print("source changed, not dispatching continuation")
        return
    from resume_verify import check_predecessor
    check_predecessor(state["run_id"])
    token = os.environ["GITHUB_TOKEN"]
    api = os.environ.get(
        "GITHUB_API_URL", "https://api.github.com").rstrip("/")
    repository = os.environ["GITHUB_REPOSITORY"]
    expected = subprocess.check_output(
        ["git", "rev-parse", "HEAD"], text=True).strip()
    req = urllib.request.Request(
        f"{api}/repos/{repository}/branches/{quote(args.branch, safe='')}",
        headers={"Authorization": f"Bearer {token}",
                 "Accept": "application/vnd.github+json"},
    )
    with urllib.request.urlopen(req, timeout=30) as response:
        actual = json.load(response)["commit"]["sha"]
    if actual != expected:
        print("branch advanced after checkout, not dispatching continuation")
        return
    body = json.dumps({"ref": args.branch, "inputs": {
        "continuation": "true", "previous_run_id": str(state["run_id"]),
        "origin_sha": state["origin_sha"],
        "round": str(state["round"] + 1), "target": target,
    }}).encode("utf-8")
    dispatch_request = urllib.request.Request(
        f"{api}/repos/{repository}/actions/workflows/verify.yml/dispatches",
        data=body, method="POST",
        headers={"Authorization": f"Bearer {token}",
                 "Accept": "application/vnd.github+json",
                 "Content-Type": "application/json"},
    )
    with urllib.request.urlopen(dispatch_request, timeout=30) as response:
        if response.status != 204:
            raise RuntimeError(
                f"unexpected workflow_dispatch response: {response.status}")
    print(f"dispatched round {state['round'] + 1} for group(s): {target}")


def assert_final(args: argparse.Namespace) -> None:
    statuses = load(args.state)["statuses"]
    counts = Counter(statuses.values())
    if counts["failed"] or counts["pending"] or counts["rate_limited"]:
        print(f"unresolved verification: failed={counts['failed']}, pending={counts['pending']}, rate_limited={counts['rate_limited']}",
              file=sys.stderr)
        sys.exit(1)


def parser() -> argparse.ArgumentParser:
    p = argparse.ArgumentParser()
    subs = p.add_subparsers(dest="command", required=True)
    a = subs.add_parser("prepare")
    a.add_argument("--continuation", action="store_true")
    a.add_argument("--round", type=int, required=True)
    a.add_argument("--previous-run-id", type=int, default=0)
    a.add_argument("--origin-sha", default="")
    a.add_argument("--target", choices=("both", *GROUPS), default="both")
    a.add_argument("--previous-state", type=pathlib.Path)
    a.set_defaults(func=prepare)
    b = subs.add_parser("summarize")
    b.add_argument("--input-dir", type=pathlib.Path, required=True)
    b.add_argument("--output", type=pathlib.Path, required=True)
    b.add_argument("--shards", type=int, default=16)
    b.add_argument("--origin-sha", required=True)
    b.add_argument("--round", type=int, required=True)
    b.add_argument("--run-id", type=int, required=True)
    b.add_argument("--previous-run-id", type=int, default=0)
    b.add_argument("--target", choices=("both", *GROUPS), default="both")
    b.add_argument("--previous-state", type=pathlib.Path)
    b.set_defaults(func=summarize)
    c = subs.add_parser("dispatch")
    c.add_argument("--state", type=pathlib.Path, required=True)
    c.add_argument("--branch", required=True)
    c.set_defaults(func=dispatch)
    d = subs.add_parser("assert-final")
    d.add_argument("--state", type=pathlib.Path, required=True)
    d.set_defaults(func=assert_final)
    e = subs.add_parser("check-shards")
    e.add_argument("--input-dir", type=pathlib.Path, required=True)
    e.add_argument("--shards", type=int, required=True)
    e.add_argument("--job-result", required=True)
    e.set_defaults(func=check_shards)
    return p


def main() -> None:
    args = parser().parse_args()
    args.func(args)


if __name__ == "__main__":
    main()
