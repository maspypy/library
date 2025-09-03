---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "#!/usr/bin/env python3\nimport json\nimport os\nimport glob\nimport shutil\n\
    import pathlib\nimport sys\n\nBASE = \"/tmp/verify-artifacts\"\nparts = sorted(glob.glob(os.path.join(BASE,\
    \ \"verify-helper-*\")))\n\nOUT = pathlib.Path(\".verify-helper\")\nOUT.mkdir(parents=True,\
    \ exist_ok=True)\n\nif not parts:\n    print(\"No verify artifacts found under\"\
    , BASE, file=sys.stderr)\n    sys.exit(0)\n\nCANDIDATE_JSONS = [\"timestamps.json\"\
    , \"results.json\"]\n\n\ndef load_json(p):\n    try:\n        with open(p, \"\
    r\") as f:\n            return json.load(f)\n    except FileNotFoundError:\n \
    \       return None\n    except json.JSONDecodeError:\n        return None\n\n\
    \ndef dump_json(p, obj):\n    p.parent.mkdir(parents=True, exist_ok=True)\n  \
    \  with open(p, \"w\") as f:\n        json.dump(obj, f, ensure_ascii=False, indent=2,\
    \ sort_keys=True)\n\n\nmerged = {}\n\nfor d in parts:\n    # \u2705 \u30A2\u30C3\
    \u30D7\u30ED\u30FC\u30C9\u3057\u305F\u306E\u306F .verify-helper \u306E\u300C\u4E2D\
    \u8EAB\u300D\u306A\u306E\u3067\u3001jdir \u306F d \u3067OK\n    jdir = d\n\n \
    \   for name in CANDIDATE_JSONS:\n        src = os.path.join(jdir, name)\n   \
    \     data = load_json(src)\n        if not data:\n            continue\n    \
    \    cur = merged.get(name, {})\n        for k, v in data.items():\n         \
    \   if k not in cur:\n                cur[k] = v\n            else:\n        \
    \        # \u3067\u304D\u308B\u3060\u3051\u65B0\u3057\u3044\u8A18\u9332\u3092\u6B8B\
    \u3059\uFF08\u306A\u3051\u308C\u3070\u4E0A\u66F8\u304D\uFF09\n               \
    \ def ts(x):\n                    if isinstance(x, dict):\n                  \
    \      for key in (\"time\", \"timestamp\", \"updated_at\"):\n               \
    \             if key in x:\n                                return x[key]\n  \
    \                  return None\n                if (ts(v) or 0) >= (ts(cur[k])\
    \ or 0):\n                    cur[k] = v\n        merged[name] = cur\n\n# \u96C6\
    \u7D04 JSON \u3092\u914D\u7F6E\nfor name, obj in merged.items():\n    dump_json(OUT\
    \ / name, obj)\n\n# cache \u3082\u3042\u308C\u3070\u5BC4\u305B\u96C6\u3081\uFF08\
    \u5FC5\u9808\u3067\u306F\u306A\u3044\u304C\u4E00\u5FDC\uFF09\nfor d in parts:\n\
    \    cdir = pathlib.Path(d) / \"cache\"  # \u2705 \u3053\u3053\u3082\u76F4\u4E0B\
    \n    if cdir.exists():\n        dst = OUT / \"cache\"\n        for p in cdir.rglob(\"\
    *\"):\n            if p.is_file():\n                rel = p.relative_to(cdir)\n\
    \                (dst / rel).parent.mkdir(parents=True, exist_ok=True)\n     \
    \           shutil.copy2(p, dst / rel)\n\nprint(\"Merged verify-helper from:\"\
    , parts)\n"
  dependsOn: []
  isVerificationFile: false
  path: scripts/merge_verify_results.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: scripts/merge_verify_results.py
layout: document
redirect_from:
- /library/scripts/merge_verify_results.py
- /library/scripts/merge_verify_results.py.html
title: scripts/merge_verify_results.py
---
