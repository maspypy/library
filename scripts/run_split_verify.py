#!/usr/bin/env python3
import argparse
import subprocess
import sys
import glob


def main():
    p = argparse.ArgumentParser()
    p.add_argument("--split", type=int, required=True)
    p.add_argument("--index", type=int, required=True)
    p.add_argument("-j", "--jobs", type=int, default=1)
    args = p.parse_args()

    files = sorted(glob.glob("test/**/*.test.cpp", recursive=True))

    selected = [f for i, f in enumerate(files) if i % args.split == args.index]

    if not selected:
        print("No tests for this partition.")
        return 0

    cmd = ["oj-verify", "run", "--no-git-push",
           "-j", str(args.jobs)] + selected
    print("Running:", " ".join(cmd))
    return subprocess.call(cmd)


if __name__ == "__main__":
    sys.exit(main())
