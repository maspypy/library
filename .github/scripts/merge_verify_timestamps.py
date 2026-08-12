#!/usr/bin/env python3
from __future__ import annotations

import argparse
import datetime
import hashlib
import json
import pathlib
from typing import Any

TIMESTAMP_FORMAT = "%Y-%m-%d %H:%M:%S %z"


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--input-dir", type=pathlib.Path, required=True)
    parser.add_argument("--output", type=pathlib.Path, required=True)
    parser.add_argument("--shards", type=int, required=True)
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
    merged_time: dict[str, datetime.datetime] = {}

    for shard in range(args.shards):
        manifest_path = args.input_dir / f"complete-{shard}.json"
        timestamp_path = args.input_dir / f"timestamps-{shard}.json"

        manifest = load_json_object(manifest_path)
        if manifest.get("shard") != shard or manifest.get("shards") != args.shards:
            raise RuntimeError(f"invalid completion manifest: {manifest_path}")
        if not isinstance(manifest.get("verify_exit_code"), int):
            raise RuntimeError(f"missing verify exit code: {manifest_path}")

        timestamps = load_json_object(timestamp_path)
        for test, value in timestamps.items():
            if not isinstance(test, str) or not isinstance(value, str):
                raise RuntimeError(
                    f"invalid timestamp entry in {timestamp_path}")
            current_time = parse_timestamp(value, timestamp_path, test)
            # Only the owning shard is authoritative. Otherwise an old success
            # from another shard can resurrect a failed forced rerun.
            if shard_of(pathlib.Path(test), args.shards) == shard:
                merged[test] = value
                merged_time[test] = current_time

    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(merged, sort_keys=True, indent=0) + "\n")
    print(f"merged {len(merged)} verified files into {args.output}")


if __name__ == "__main__":
    main()
