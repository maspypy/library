#!/usr/bin/env python3
from __future__ import annotations

import argparse
import datetime
import hashlib
import json
import pathlib
import subprocess
import sys
from typing import Any

TIMESTAMP_FORMAT = "%Y-%m-%d %H:%M:%S %z"
PIPELINE_FILES = (
    ".verify-helper/config.toml", ".github/scripts/run_verify_shard.py",
    "expander.py", "shrink.py", "shell/verify-expanded-g++",
    "shell/verify-pipeline-g++", "shell/verify-shrunk-g++",
)


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument("--shard", type=int, required=True)
    parser.add_argument("--shards", type=int, required=True)
    parser.add_argument("--jobs", type=int, default=2)
    parser.add_argument("--timeout", type=float, default=570)
    parser.add_argument("--output-dir", type=pathlib.Path, required=True)
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
    shard: int,
    shards: int,
    selected_files: list[pathlib.Path],
    verify_exit_code: int,
) -> None:
    output_dir.mkdir(parents=True, exist_ok=True)

    timestamp_path = pathlib.Path(".verify-helper/timestamps.remote.json")
    timestamps = load_timestamp_file(timestamp_path)
    (output_dir / f"timestamps-{shard}.json").write_text(
        json.dumps(timestamps, sort_keys=True, indent=0) + "\n"
    )

    manifest = {
        "shard": shard,
        "shards": shards,
        "selected_files": len(selected_files),
        "verify_exit_code": verify_exit_code,
    }
    (output_dir / f"complete-{shard}.json").write_text(
        json.dumps(manifest, sort_keys=True, indent=2) + "\n"
    )


def main() -> int:
    args = parse_args()
    if args.shards <= 0:
        raise ValueError("--shards must be positive")
    if not 0 <= args.shard < args.shards:
        raise ValueError("--shard must satisfy 0 <= shard < shards")
    if args.jobs <= 0:
        raise ValueError("--jobs must be positive")

    files = sorted(pathlib.Path("test").rglob("*.test.cpp"))
    selected = [path for path in files if shard_of(
        path, args.shards) == args.shard]

    timestamp_path = pathlib.Path(".verify-helper/timestamps.remote.json")
    pipeline_time = pipeline_timestamp()
    adjust_pipeline_timestamps(
        timestamp_path, selected, pipeline_time, before_verify=True
    )

    print(f"shard {args.shard}/{args.shards}: {len(selected)} files", flush=True)
    for path in selected:
        print(path, flush=True)

    if selected:
        command = [
            "oj-verify",
            "run",
            "-j",
            str(args.jobs),
            "--timeout",
            str(args.timeout),
            *map(str, selected),
        ]
        result = subprocess.run(command, check=False)
        verify_exit_code = result.returncode
    else:
        verify_exit_code = 0

    # Successful records are raised to the pipeline's commit time, so this
    # one-time invalidation does not repeat on later commits.
    adjust_pipeline_timestamps(
        timestamp_path, selected, pipeline_time, before_verify=False
    )

    # This is written only after oj-verify returned normally. The finalize job
    # rejects a shard whose completion manifest is missing.
    write_outputs(
        args.output_dir,
        args.shard,
        args.shards,
        selected,
        verify_exit_code,
    )
    return verify_exit_code


if __name__ == "__main__":
    try:
        sys.exit(main())
    except Exception as exc:
        print(f"run_verify_shard.py: {exc}", file=sys.stderr)
        raise
