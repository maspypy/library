#!/usr/bin/env python3
from __future__ import annotations

import argparse
import datetime
import hashlib
import json
import pathlib
from typing import Any

TIMESTAMP_FORMAT = "%Y-%m-%d %H:%M:%S %z"
VERIFY_GROUPS = ("all",)


def group_of(path: pathlib.Path) -> str:
    return "all"



def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input-dir", type=pathlib.Path, required=True)
    parser.add_argument("--output", type=pathlib.Path, required=True)
    parser.add_argument("--shards", type=int, required=True)
    parser.add_argument("--groups", choices=VERIFY_GROUPS, nargs="+", required=True)
    parser.add_argument("--baseline", type=pathlib.Path)
    return parser.parse_args()


def load_json_object(path: pathlib.Path) -> dict[str, Any]:
    if not path.exists():
        raise RuntimeError(f"missing shard output: {path}")
    data = json.loads(path.read_text())
    if not isinstance(data, dict):
        raise RuntimeError(f"JSON root is not an object: {path}")
    return data


def parse_timestamp(value: str, path: pathlib.Path, test: str) -> datetime.datetime:
    try:
        return datetime.datetime.strptime(value, TIMESTAMP_FORMAT)
    except ValueError as exc:
        raise RuntimeError(
            f"invalid timestamp for {test!r} in {path}: {value!r}") from exc


def shard_of(path: pathlib.Path, shards: int) -> int:
    digest = hashlib.sha256(path.as_posix().encode()).digest()
    return int.from_bytes(digest[:8], "big") % shards


def main() -> None:
    args = parse_args()
    if args.shards <= 0:
        raise ValueError("--shards must be positive")

    merged: dict[str, str] = {}
    # In a continuation targeting only one group, keep the untouched group's
    # previously verified timestamps. Replacing the whole JSON would lose ACs.
    if args.baseline and args.baseline.exists():
        base = load_json_object(args.baseline)
        for name, value in base.items():
            if not isinstance(name, str) or not isinstance(value, str):
                raise ValueError("invalid baseline timestamp")
            parse_timestamp(value, args.baseline, name)
            if group_of(pathlib.Path(name)) not in args.groups:
                merged[name] = value
    for group in args.groups:
        for shard in range(args.shards):
            manifest_path = args.input_dir / f"complete-{group}-{shard}.json"
            timestamp_path = args.input_dir / f"timestamps-{group}-{shard}.json"

            manifest = load_json_object(manifest_path)
            if (manifest.get("group") != group or manifest.get("shard") != shard
                    or manifest.get("shards") != args.shards):
                raise RuntimeError(f"invalid completion manifest: {manifest_path}")
            if not isinstance(manifest.get("verify_exit_code"), int):
                raise RuntimeError(f"missing verify exit code: {manifest_path}")

            timestamps = load_json_object(timestamp_path)
            for test, value in timestamps.items():
                if not isinstance(test, str) or not isinstance(value, str):
                    raise RuntimeError(
                        f"invalid timestamp entry in {timestamp_path}")
                parse_timestamp(value, timestamp_path, test)
                # Only the owning group AND shard can publish a test's state.
                # This matters when a failed test was removed from its owner
                # but stale success records remain in the other 31 artifacts.
                path = pathlib.Path(test)
                if group_of(path) == group and shard_of(path, args.shards) == shard:
                    merged[test] = value

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(merged, sort_keys=True, indent=0) + "\n")
    print(f"merged {len(merged)} verified files into {args.output}")


if __name__ == "__main__":
    main()
