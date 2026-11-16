#!/usr/bin/env python3
"""Run the installed verification-helper, recording which files were attempted.

The upstream marker only persists AC timestamps: without this trace a failed
file cannot be distinguished from one not reached before --timeout.
"""
from __future__ import annotations

import json
import os
import pathlib
import sys


def record(path: pathlib.Path, status: str) -> None:
    target = os.environ.get("VERIFY_TRACE_FILE")
    if not target:
        raise RuntimeError("VERIFY_TRACE_FILE must be set")
    filename = pathlib.Path(target)
    filename.parent.mkdir(parents=True, exist_ok=True)
    with filename.open("a", encoding="utf-8") as stream:
        stream.write(json.dumps({"path": path.as_posix(), "status": status}) + "\n")


def main() -> None:
    import onlinejudge_verify.main as cli
    import onlinejudge_verify.verify as verifier

    real_verify = verifier.verify_file

    def traced(path: pathlib.Path, **kwargs):
        try:
            result = real_verify(path, **kwargs)
        except BaseException:
            record(path, "error")
            raise
        record(path, "ac" if result is True else "ignored" if result is None else "failed")
        return result

    verifier.verify_file = traced
    cli.main(sys.argv[1:])


if __name__ == "__main__":
    main()
