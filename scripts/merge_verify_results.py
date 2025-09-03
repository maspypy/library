#!/usr/bin/env python3
import json
import os
import glob
import shutil
import pathlib
import sys
from typing import Dict, Any

BASE = "/tmp/verify-artifacts"
# verify-helper-0,1,2,3 ... の直下に .verify-helper の「中身」が展開されている前提
parts = sorted(glob.glob(os.path.join(BASE, "verify-helper-*")))
OUT = pathlib.Path(".verify-helper")
OUT.mkdir(parents=True, exist_ok=True)


def load_json_or_empty(p: pathlib.Path) -> Dict[str, Any]:
    try:
        with p.open("r") as f:
            data = json.load(f)
        if isinstance(data, dict):
            return data
        # dict 以外（list等）が来たら空扱いにする
        return {}
    except (FileNotFoundError, json.JSONDecodeError):
        return {}


def pick_ts(d: Dict[str, Any]):
    # 代表的なタイムスタンプっぽいキーを拾う
    if isinstance(d, dict):
        for k in ("time", "timestamp", "updated_at"):
            if k in d:
                return d[k]
    return None


def merge_maps(dst: Dict[str, Any], src: Dict[str, Any]) -> None:
    for k, v in src.items():
        if k not in dst:
            dst[k] = v
            continue
        # 既存と衝突したら「新しい方」を採用（基準キーが無ければ上書き）
        t_new, t_old = pick_ts(v), pick_ts(dst[k])
        if (t_new or 0) >= (t_old or 0):
            dst[k] = v


if not parts:
    print(f"No verify artifacts found under {BASE}", file=sys.stderr)
    # 空でも docs が動くよう、最低限のファイルを用意
    (OUT / "timestamps.json").write_text("{}", encoding="utf-8")
    sys.exit(0)

merged_timestamps: Dict[str, Any] = {}
merged_results: Dict[str, Any] = {}

# 各パーティションを統合
for d in parts:
    dpath = pathlib.Path(d)
    # 中身構造なので直下にこれらがいる
    ts = load_json_or_empty(dpath / "timestamps.json")
    ts_remote = load_json_or_empty(dpath / "timestamps.remote.json")
    res = load_json_or_empty(dpath / "results.json")

    # union（remote も反映しておく）
    merge_maps(merged_timestamps, ts)
    merge_maps(merged_timestamps, ts_remote)
    merge_maps(merged_results, res)

# 出力（必ず作る）
with (OUT / "timestamps.json").open("w") as f:
    json.dump(merged_timestamps, f, ensure_ascii=False,
              indent=2, sort_keys=True)
with (OUT / "results.json").open("w") as f:
    json.dump(merged_results, f, ensure_ascii=False, indent=2, sort_keys=True)

# cache は必要ならコピー（なくても OK）
for d in parts:
    cdir = pathlib.Path(d) / "cache"
    if cdir.exists():
        dst = OUT / "cache"
        for p in cdir.rglob("*"):
            if p.is_file():
                rel = p.relative_to(cdir)
                (dst / rel).parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(p, dst / rel)

print("Merged verify-helper from:", parts)
print(f"Wrote: {OUT / 'timestamps.json'}  (keys={len(merged_timestamps)})")
print(f"Wrote: {OUT / 'results.json'}     (keys={len(merged_results)})")
