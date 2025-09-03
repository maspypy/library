#!/usr/bin/env python3
import json
import os
import glob
import shutil
import pathlib

# すべてのパーティション artifact のパス
BASE = "/tmp/verify-artifacts"
parts = sorted(glob.glob(os.path.join(BASE, "verify-helper-*")))

# 出力先
OUT = pathlib.Path(".verify-helper")
OUT.mkdir(parents=True, exist_ok=True)

# マージ対象とする代表的なファイル/ディレクトリ
# - timestamps.json: ファイルごとの最終成功時刻など
# - results.json    : 直近の検証結果（存在しない環境もあるので optional 扱い）
# - cache/          : 必須ではないが、docs のリンク生成で使われる場合がある
CANDIDATE_JSONS = ["timestamps.json", "results.json"]


def load_json(p):
    try:
        with open(p, "r") as f:
            return json.load(f)
    except FileNotFoundError:
        return None


def dump_json(p, obj):
    p.parent.mkdir(parents=True, exist_ok=True)
    with open(p, "w") as f:
        json.dump(obj, f, ensure_ascii=False, indent=2, sort_keys=True)


# timestamps/results のマージ（キーごとに「新しい方」を採用）
merged = {}

for d in parts:
    jdir = os.path.join(d, ".verify-helper")
    for name in CANDIDATE_JSONS:
        src = os.path.join(jdir, name)
        data = load_json(src)
        if not data:
            continue
        # data は dict を想定（{ filepath: meta }）
        cur = merged.get(name, {})
        for k, v in data.items():
            if k not in cur:
                cur[k] = v
            else:
                # できるだけ新しい記録を残す（timestamp や status の比較）
                # timestamp は "time" or "timestamp" の数値/文字列を想定
                def ts(x):
                    if isinstance(x, dict):
                        for key in ("time", "timestamp", "updated_at"):
                            if key in x:
                                return x[key]
                    return None
                if (ts(v) or 0) >= (ts(cur[k]) or 0):
                    cur[k] = v
        merged[name] = cur

# 集約 JSON を配置
for name, obj in merged.items():
    dump_json(OUT / name, obj)

# 代表的な生成物ディレクトリをマージ（必要に応じて）
# 生成済み markdown は docs ステップで再生成するのでここでは不要。
# ただし verify-helper が参照する中間物があればマージする。
for d in parts:
    cdir = pathlib.Path(d) / ".verify-helper" / "cache"
    if cdir.exists():
        dst = OUT / "cache"
        dst.mkdir(parents=True, exist_ok=True)
        for p in cdir.rglob("*"):
            if p.is_file():
                rel = p.relative_to(cdir)
                (dst / rel).parent.mkdir(parents=True, exist_ok=True)
                shutil.copy2(p, dst / rel)

print("Merged verify-helper from:", parts)
