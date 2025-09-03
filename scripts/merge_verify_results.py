#!/usr/bin/env python3
import json
import os
import glob
import shutil
import pathlib
import sys

BASE = "/tmp/verify-artifacts"
parts = sorted(glob.glob(os.path.join(BASE, "verify-helper-*")))

OUT = pathlib.Path(".verify-helper")
OUT.mkdir(parents=True, exist_ok=True)

if not parts:
    print("No verify artifacts found under", BASE, file=sys.stderr)
    sys.exit(0)

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


merged = {}

for d in parts:
    jdir = os.path.join(d, ".verify-helper")
    for name in CANDIDATE_JSONS:
        src = os.path.join(jdir, name)
        data = load_json(src)
        if not data:
            continue
        cur = merged.get(name, {})
        for k, v in data.items():
            if k not in cur:
                cur[k] = v
            else:
                def ts(x):
                    if isinstance(x, dict):
                        for key in ("time", "timestamp", "updated_at"):
                            if key in x:
                                return x[key]
                    return None
                if (ts(v) or 0) >= (ts(cur[k]) or 0):
                    cur[k] = v
        merged[name] = cur

for name, obj in merged.items():
    dump_json(OUT / name, obj)

# cache ディレクトリの中身もコピーしておく
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
