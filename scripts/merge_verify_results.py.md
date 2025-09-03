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
    \       return None\n\n\ndef dump_json(p, obj):\n    p.parent.mkdir(parents=True,\
    \ exist_ok=True)\n    with open(p, \"w\") as f:\n        json.dump(obj, f, ensure_ascii=False,\
    \ indent=2, sort_keys=True)\n\n\nmerged = {}\n\nfor d in parts:\n    jdir = os.path.join(d,\
    \ \".verify-helper\")\n    for name in CANDIDATE_JSONS:\n        src = os.path.join(jdir,\
    \ name)\n        data = load_json(src)\n        if not data:\n            continue\n\
    \        cur = merged.get(name, {})\n        for k, v in data.items():\n     \
    \       if k not in cur:\n                cur[k] = v\n            else:\n    \
    \            def ts(x):\n                    if isinstance(x, dict):\n       \
    \                 for key in (\"time\", \"timestamp\", \"updated_at\"):\n    \
    \                        if key in x:\n                                return\
    \ x[key]\n                    return None\n                if (ts(v) or 0) >=\
    \ (ts(cur[k]) or 0):\n                    cur[k] = v\n        merged[name] = cur\n\
    \nfor name, obj in merged.items():\n    dump_json(OUT / name, obj)\n\n# cache\
    \ \u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u306E\u4E2D\u8EAB\u3082\u30B3\u30D4\u30FC\
    \u3057\u3066\u304A\u304F\nfor d in parts:\n    cdir = pathlib.Path(d) / \".verify-helper\"\
    \ / \"cache\"\n    if cdir.exists():\n        dst = OUT / \"cache\"\n        dst.mkdir(parents=True,\
    \ exist_ok=True)\n        for p in cdir.rglob(\"*\"):\n            if p.is_file():\n\
    \                rel = p.relative_to(cdir)\n                (dst / rel).parent.mkdir(parents=True,\
    \ exist_ok=True)\n                shutil.copy2(p, dst / rel)\n\nprint(\"Merged\
    \ verify-helper from:\", parts)\n"
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
