#!/usr/bin/env python3
from __future__ import annotations

import argparse
import datetime
import hashlib
import json
import os
import pathlib
import re
import shutil
import stat
import subprocess
import sys
import time
from typing import Any

# Tests import this runner by filename; CI runs it as a standalone script.
sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent))
from continue_verify import validate_state, load

TIMESTAMP_FORMAT = "%Y-%m-%d %H:%M:%S %z"
VERIFY_GROUPS = ("all",)


def group_of(path: pathlib.Path) -> str:
    return "yukicoder" if path.as_posix().startswith("test/3_yukicoder/") else "other"

# Cache/network orchestration changes should not invalidate every previously
# verified testcase. Only semantic compilation/expansion inputs go here.
# If this runner starts changing verification semantics, explicitly invalidate
# timestamps in that change instead of silently re-downloading all judges.
PIPELINE_FILES = (
    ".verify-helper/config.toml",
    "scripts/expander.py", "scripts/shrink.py", "shell/verify-expanded-g++",
    "shell/verify-pipeline-g++", "shell/verify-shrunk-g++",
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--group", choices=VERIFY_GROUPS, required=True)
    parser.add_argument("--shard", type=int, required=True)
    parser.add_argument("--shards", type=int, required=True)
    parser.add_argument("--jobs", type=int, default=2)
    parser.add_argument("--timeout", type=float, default=570)
    parser.add_argument("--output-dir", type=pathlib.Path, required=True)
    parser.add_argument("--previous-state", type=pathlib.Path)
    parser.add_argument("--previous-run-id", type=int, default=0)
    parser.add_argument("--origin-sha", default="")
    parser.add_argument("--round", type=int, default=0)
    return parser.parse_args()


def shard_of(path: pathlib.Path, shards: int) -> int:
    digest = hashlib.sha256(path.as_posix().encode()).digest()
    return int.from_bytes(digest[:8], "big") % shards


def load_timestamp_file(path: pathlib.Path) -> dict[str, str]:
    if not path.exists():
        return {}
    data: Any = json.loads(path.read_text())
    if not isinstance(data, dict):
        raise RuntimeError(f"timestamp file is not a JSON object: {path}")
    if not all(isinstance(key, str) and isinstance(value, str) for key, value in data.items()):
        raise RuntimeError(f"timestamp file has invalid entries: {path}")
    return data


def pipeline_timestamp() -> datetime.datetime:
    value = subprocess.check_output(
        ["git", "log", "-1", "--date=iso", "--pretty=%ad", "--", *PIPELINE_FILES],
        text=True,
    ).strip()
    if not value:
        raise RuntimeError("cannot determine verification pipeline timestamp")
    return datetime.datetime.strptime(value, TIMESTAMP_FORMAT)


def adjust_pipeline_timestamps(
    path: pathlib.Path,
    selected: list[pathlib.Path],
    floor: datetime.datetime,
    *, before_verify: bool,
) -> dict[str, str]:
    timestamps = load_timestamp_file(path)
    floor_text = floor.strftime(TIMESTAMP_FORMAT)
    for source in selected:
        key = source.as_posix()
        value = timestamps.get(key)
        if value is None or datetime.datetime.strptime(value, TIMESTAMP_FORMAT) >= floor:
            continue
        if before_verify:
            del timestamps[key]
        else:
            timestamps[key] = floor_text
    path.write_text(json.dumps(timestamps, sort_keys=True, indent=0) + "\n")
    return timestamps


def write_outputs(
    output_dir: pathlib.Path,
    group: str,
    shard: int,
    shards: int,
    selected_files: list[pathlib.Path],
    verify_exit_code: int,
    *,
    statuses: dict[str, str] | None = None,
    rate_limited: bool = False,
    infrastructure_error: bool = False,
    attempted_files: int = 0,
    last_429: float = 0,
) -> None:
    output_dir.mkdir(parents=True, exist_ok=True)

    timestamp_path = pathlib.Path(".verify-helper/timestamps.remote.json")
    timestamps = load_timestamp_file(timestamp_path)
    (output_dir / f"timestamps-{group}-{shard}.json").write_text(
        json.dumps(timestamps, sort_keys=True, indent=0) + "\n"
    )

    manifest = {
        "group": group,
        "shard": shard,
        "shards": shards,
        "selected_files": len(selected_files),
        "verify_exit_code": verify_exit_code,
        "rate_limited": rate_limited,
        "infrastructure_error": infrastructure_error,
        "attempted_files": attempted_files,
        "last_429": last_429,
    }
    (output_dir / f"states-{group}-{shard}.json").write_text(
        json.dumps({"group": group, "shard": shard, "statuses": statuses or {}},
                   sort_keys=True, indent=2) + "\n"
    )
    (output_dir / f"complete-{group}-{shard}.json").write_text(
        json.dumps(manifest, sort_keys=True, indent=2) + "\n"
    )



def _complete_testcase_pairs(directory: pathlib.Path) -> bool:
    if not directory.is_dir():
        return False
    inputs = {p.relative_to(directory).with_suffix("")
              for p in directory.rglob("*.in") if p.is_file()}
    outputs = {p.relative_to(directory).with_suffix("")
               for p in directory.rglob("*.out") if p.is_file()}
    return bool(inputs) and inputs == outputs


def yukicoder_cache_paths(selected: list[pathlib.Path]):
    pattern = re.compile(r'\bPROBLEM\s+"(https://yukicoder\.me/[^"\s]+)"')
    visited: set[str] = set()
    for source in selected:
        if not source.as_posix().startswith("test/3_yukicoder/"):
            continue
        match = pattern.search(source.read_text(errors="replace"))
        if match is None:
            continue
        url = match.group(1)
        if url in visited:
            continue
        visited.add(url)
        hash_name = hashlib.md5(url.encode()).hexdigest()
        current = pathlib.Path(".verify-helper/cache") / hash_name / "test"
        saved = pathlib.Path(".verify-helper/testcases") / hash_name / "test"
        yield url, current, saved


def remove_incomplete_yukicoder_caches(selected: list[pathlib.Path]) -> None:
    # A nonempty `test` directory prevents oj-verify from downloading again.
    for url, current, _ in yukicoder_cache_paths(selected):
        if current.exists() and not _complete_testcase_pairs(current):
            print(f"discarding incomplete yukicoder cache: {url}", flush=True)
            if current.is_dir():
                shutil.rmtree(current)
            else:
                current.unlink()


def restore_yukicoder_testcases(selected: list[pathlib.Path]) -> None:
    for url, current, saved in yukicoder_cache_paths(selected):
        if current.exists():
            continue
        if not (saved / ".download-complete").is_file():
            continue
        if not _complete_testcase_pairs(saved):
            print(f"ignoring corrupt saved yukicoder cases: {url}", flush=True)
            continue
        current.parent.mkdir(parents=True, exist_ok=True)
        shutil.copytree(saved, current)


def collect_yukicoder_testcases(selected: list[pathlib.Path]) -> None:
    # Copy only proven-complete downloads or tests that passed verification.
    # Compiled binaries and other judges' caches are never persisted here.
    timestamps = load_timestamp_file(pathlib.Path(
        ".verify-helper/timestamps.remote.json"))
    verified_urls = set()
    pattern = re.compile(r'\bPROBLEM\s+"(https://yukicoder\.me/[^"\s]+)"')
    for source in selected:
        if source.as_posix() not in timestamps:
            continue
        match = pattern.search(source.read_text(errors="replace"))
        if match:
            verified_urls.add(match.group(1))
    for url, current, saved in yukicoder_cache_paths(selected):
        if not _complete_testcase_pairs(current):
            continue
        if not (current / ".download-complete").is_file() and url not in verified_urls:
            continue
        if saved.exists():
            if (saved / ".download-complete").is_file() and _complete_testcase_pairs(saved):
                continue
            print(f"replacing incomplete saved yukicoder cache: {url}", flush=True)
            if saved.is_dir():
                shutil.rmtree(saved)
            else:
                saved.unlink()
        saved.parent.mkdir(parents=True, exist_ok=True)
        # Source is immutable after a successful download, as downloads are
        # atomically published by the oj shim. Store only the test directory.
        shutil.copytree(current, saved)
        if not (saved / ".download-complete").exists():
            (saved / ".download-complete").write_text("verified\n")


def verification_environment() -> dict[str, str]:
    real_oj = shutil.which("oj")
    if real_oj is None:
        raise RuntimeError("cannot find real oj executable")
    shim = pathlib.Path(__file__).with_name("oj").resolve()
    shim.chmod(shim.stat().st_mode | stat.S_IXUSR)
    env = os.environ.copy()
    env["VERIFY_REAL_OJ"] = real_oj
    env["VERIFY_YUKICODER_CIRCUIT"] = str(pathlib.Path(
        ".verify-helper/yukicoder-429.block").resolve())
    env["PATH"] = str(shim.parent) + os.pathsep + env.get("PATH", "")
    return env

def read_trace(path: pathlib.Path) -> dict[str, str]:
    statuses: dict[str, str] = {}
    if not path.exists():
        return statuses
    for line in path.read_text().splitlines():
        record = json.loads(line)
        name, status = record["path"], record["status"]
        if status not in ("ac", "failed", "rate_limited", "error") or name in statuses:
            raise RuntimeError(f"invalid or duplicate verify trace: {name}")
        statuses[name] = status
    return statuses


def prior_failures(args: argparse.Namespace, selected: list[pathlib.Path]) -> dict[str, str]:
    if args.round == 0:
        if args.previous_state is not None:
            raise ValueError("fresh run cannot receive previous state")
        return {}
    if args.previous_state is None or not args.origin_sha or not args.previous_run_id:
        raise ValueError("continuation is missing required previous state")
    previous = load(args.previous_state)
    validate_state(previous, origin=args.origin_sha,
                   round_number=args.round - 1,
                   previous_run_id=args.previous_run_id)
    result: dict[str, str] = {}
    for path in selected:
        status = previous["statuses"].get(path.as_posix())
        if status is None:
            raise ValueError(f"continuation does not contain previous file: {path}")
        if status == "failed" or (status == "rate_limited" and time.time() < previous["last_429"] + 4200):
            result[path.as_posix()] = status
    return result


def main() -> int:
    args = parse_args()
    if args.shards <= 0:
        raise ValueError("--shards must be positive")
    if not 0 <= args.shard < args.shards:
        raise ValueError("--shard must satisfy 0 <= shard < shards")
    if args.jobs <= 0:
        raise ValueError("--jobs must be positive")

    files = sorted(pathlib.Path("test").rglob("*.test.cpp"))
    selected = [path for path in files if
                shard_of(path, args.shards) == args.shard]

    previous_skips = prior_failures(args, selected)
    to_run = [path for path in selected if path.as_posix() not in previous_skips]

    timestamp_path = pathlib.Path(".verify-helper/timestamps.remote.json")
    pipeline_time = pipeline_timestamp()
    adjust_pipeline_timestamps(
        timestamp_path, selected, pipeline_time, before_verify=True
    )

    print(f"group {args.group}, shard {args.shard}/{args.shards}: "
          f"{len(selected)} files, {len(previous_skips)} previous failures ignored "
          f"for this continuation", flush=True)
    for path in to_run:
        print(path, flush=True)

    trace_path = pathlib.Path(".verify-helper") / f"trace-{args.group}-{args.shard}.jsonl"
    trace_path.unlink(missing_ok=True)
    circuit_path = pathlib.Path(".verify-helper/yukicoder-429.block")
    circuit_path.unlink(missing_ok=True)
    last_429 = load(args.previous_state)["last_429"] if args.previous_state else 0
    if last_429 and time.time() < last_429 + 4200:
        circuit_path.write_text(str(last_429))
    if to_run:
        remove_incomplete_yukicoder_caches(to_run)
        restore_yukicoder_testcases(to_run)
        env = verification_environment()
        env["VERIFY_TRACE_FILE"] = str(trace_path.resolve())
        command = [
            sys.executable, str(pathlib.Path(__file__).with_name("verify_trace.py")),
            "run", "-j", str(args.jobs), "--timeout", str(args.timeout),
            *(p.as_posix() for p in to_run),
        ]
        result = subprocess.run(command, check=False, env=env)
        verifier_exit = result.returncode
    else:
        verifier_exit = 0

    # Also enforce dependency timestamps at the end of the run.
    adjust_pipeline_timestamps(
        timestamp_path, selected, pipeline_time, before_verify=False
    )
    collect_yukicoder_testcases(to_run)

    trace = read_trace(trace_path)
    selected_for_verifier = {p.as_posix() for p in to_run}
    if any(name not in selected_for_verifier for name in trace):
        raise RuntimeError("verification trace contains unexpected file")
    timestamps = load_timestamp_file(timestamp_path)
    states: dict[str, str] = {}
    for path in selected:
        name = path.as_posix()
        if name in timestamps:
            states[name] = "ac"
        elif name in previous_skips:
            states[name] = previous_skips[name]
        else:
            state = trace.get(name, "pending")
            states[name] = "failed" if state == "error" else (
                "pending" if state == "ac" else state)

    infrastructure_error = ("error" in trace.values() or verifier_exit not in (0, 1) or
                            (verifier_exit == 1 and not any(s in ("failed", "rate_limited") for s in trace.values())))
    # A failed result is never silently made successful just because the next
    # continuation round skipped it.
    if circuit_path.exists():
        last_429 = max(last_429, float(circuit_path.read_text()))
    overall_exit = verifier_exit or (1 if any(s != "ac" for s in states.values()) else 0)
    write_outputs(
        args.output_dir, args.group, args.shard, args.shards, selected,
        overall_exit, statuses=states, rate_limited=circuit_path.exists(),
        infrastructure_error=infrastructure_error,
        attempted_files=len(trace), last_429=last_429,
    )
    return overall_exit


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception as exc:
        print(f"run_verify_shard.py: {exc}", file=sys.stderr)
        raise
