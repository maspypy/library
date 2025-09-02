import argparse
import subprocess
import sys
import glob


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--split", type=int, required=True)
    parser.add_argument("--index", type=int, required=True)
    parser.add_argument("-j", "--jobs", type=int, default=1)
    args = parser.parse_args()

    # verify 対象の test ファイル一覧を取得
    files = sorted(glob.glob("verify/**/*.test.cpp", recursive=True))

    selected = [f for i, f in enumerate(files) if i % args.split == args.index]

    if not selected:
        print("No tests for this partition.")
        return 0

    cmd = ["oj-verify", "run", "-j", str(args.jobs)] + selected
    print("Running:", " ".join(cmd))
    return subprocess.call(cmd)


if __name__ == "__main__":
    sys.exit(main())
