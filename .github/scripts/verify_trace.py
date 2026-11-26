#!/usr/bin/env python3
"""Run the installed verification-helper, recording which files were attempted.

The upstream marker only persists AC timestamps: without this trace a failed
file cannot be distinguished from one not reached before --timeout.
"""
from __future__ import annotations

import json
import os
import pathlib
import subprocess
import sys
import tempfile


def record(path: pathlib.Path, status: str) -> None:
    target = os.environ.get("VERIFY_TRACE_FILE")
    if not target:
        raise RuntimeError("VERIFY_TRACE_FILE must be set")
    filename = pathlib.Path(target)
    filename.parent.mkdir(parents=True, exist_ok=True)
    with filename.open("a", encoding="utf-8") as stream:
        stream.write(json.dumps({"path": path.as_posix(), "status": status}) + "\n")


STANDALONE_ROOT = pathlib.Path("test/5_ai_generated_test")


def is_standalone(path: pathlib.Path) -> bool:
    return path.resolve().is_relative_to(STANDALONE_ROOT.resolve())


def cpp_environments(path: pathlib.Path):
    import onlinejudge_verify.languages.list as languages

    language = languages.get(path)
    if language is None:
        raise RuntimeError(f"unsupported standalone test: {path}")
    environments = language.list_environments(path, basedir=pathlib.Path.cwd())
    if not environments:
        raise RuntimeError(f"no configured compiler environments for {path}")
    return environments


def timeout_seconds(name: str) -> int:
    value = int(os.environ.get(name, "120"))
    if value <= 0:
        raise ValueError(f"{name} must be positive")
    return value


def run_bounded(command: list[str], seconds: int) -> bool:
    # GNU timeout also terminates subprocesses of the compiler wrappers.
    print(f"[standalone] {command}", flush=True)
    result = subprocess.run(
        ["timeout", "--kill-after=5s", f"{seconds}s", *command],
        stdin=subprocess.DEVNULL, check=False,
    )
    if result.returncode != 0:
        print(f"[standalone] exit status {result.returncode}", flush=True)
    return result.returncode == 0


def verify_standalone(path: pathlib.Path) -> bool:
    basedir = pathlib.Path.cwd()
    compile_timeout = timeout_seconds("AI_TEST_COMPILE_TIMEOUT")
    run_timeout = timeout_seconds("AI_TEST_TIMEOUT")
    for environment in cpp_environments(path):
        # Use the configured expanded/shrunk wrappers and C++ flags, just
        # like the online-judge verifier. Keep assertions enabled.
        with tempfile.TemporaryDirectory(prefix="verify-standalone-") as tmp:
            tempdir = pathlib.Path(tmp)
            command = [str(environment.CXX), *environment.CXXFLAGS,
                       "-UNDEBUG", "-I", str(basedir), "-o",
                       str(tempdir / "a.out"), str(path.resolve())]
            if not run_bounded(command, compile_timeout):
                return False
            execute = environment.get_execute_command(
                path, basedir=basedir, tempdir=tempdir)
            if not run_bounded(execute, run_timeout):
                return False
    return True


def main() -> None:
    import onlinejudge_verify.main as cli
    import onlinejudge_verify.verify as verifier

    real_verify = verifier.verify_file

    def traced(path: pathlib.Path, **kwargs):
        rate_file = pathlib.Path(os.environ["VERIFY_TRACE_FILE"] + ".rate")
        rate_file.unlink(missing_ok=True)
        os.environ["VERIFY_RATE_FILE"] = str(rate_file.resolve())
        try:
            result = (verify_standalone(path) if is_standalone(path)
                      else real_verify(path, **kwargs))
        except BaseException:
            record(path, "error")
            raise
        record(path, "ac" if result is True else "rate_limited" if rate_file.exists() else "failed")
        return result

    verifier.verify_file = traced
    cli.main(sys.argv[1:])


if __name__ == "__main__":
    main()
