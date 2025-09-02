#!/usr/bin/env python3
import argparse
import json
import subprocess
import sys


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--split", type=int, required=True)
    parser.add_argument("--index", type=int, required=True)
    parser.add_argument("-j", "--jobs", type=int, default=1)
    args = parser.parse_args()

    # テスト対象一覧を JSON で取得
    result = subprocess.check_output(["oj-verify", "list", "--json"])
    files = json.loads(result)

    # ファイルパス一覧に変換
    paths = [f["path"] for f in files]

    # インデックスで分割
    selected = [f for i, f in enumerate(paths) if i % args.split == args.index]

    if not selected:
        print("No tests for this partition.")
        return 0

    # 選択されたテストのみ実行
    cmd = ["oj-verify", "run", "-j", str(args.jobs)] + selected
    print("Running:", " ".join(cmd))
    return subprocess.call(cmd)


if __name__ == "__main__":
    sys.exit(main())
