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
    import pathlib\n\n# \u3059\u3079\u3066\u306E\u30D1\u30FC\u30C6\u30A3\u30B7\u30E7\
    \u30F3 artifact \u306E\u30D1\u30B9\nBASE = \"/tmp/verify-artifacts\"\nparts =\
    \ sorted(glob.glob(os.path.join(BASE, \"verify-helper-*\")))\n\n# \u51FA\u529B\
    \u5148\nOUT = pathlib.Path(\".verify-helper\")\nOUT.mkdir(parents=True, exist_ok=True)\n\
    \n# \u30DE\u30FC\u30B8\u5BFE\u8C61\u3068\u3059\u308B\u4EE3\u8868\u7684\u306A\u30D5\
    \u30A1\u30A4\u30EB/\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\n# - timestamps.json:\
    \ \u30D5\u30A1\u30A4\u30EB\u3054\u3068\u306E\u6700\u7D42\u6210\u529F\u6642\u523B\
    \u306A\u3069\n# - results.json    : \u76F4\u8FD1\u306E\u691C\u8A3C\u7D50\u679C\
    \uFF08\u5B58\u5728\u3057\u306A\u3044\u74B0\u5883\u3082\u3042\u308B\u306E\u3067\
    \ optional \u6271\u3044\uFF09\n# - cache/          : \u5FC5\u9808\u3067\u306F\u306A\
    \u3044\u304C\u3001docs \u306E\u30EA\u30F3\u30AF\u751F\u6210\u3067\u4F7F\u308F\u308C\
    \u308B\u5834\u5408\u304C\u3042\u308B\nCANDIDATE_JSONS = [\"timestamps.json\",\
    \ \"results.json\"]\n\n\ndef load_json(p):\n    try:\n        with open(p, \"\
    r\") as f:\n            return json.load(f)\n    except FileNotFoundError:\n \
    \       return None\n\n\ndef dump_json(p, obj):\n    p.parent.mkdir(parents=True,\
    \ exist_ok=True)\n    with open(p, \"w\") as f:\n        json.dump(obj, f, ensure_ascii=False,\
    \ indent=2, sort_keys=True)\n\n\n# timestamps/results \u306E\u30DE\u30FC\u30B8\
    \uFF08\u30AD\u30FC\u3054\u3068\u306B\u300C\u65B0\u3057\u3044\u65B9\u300D\u3092\
    \u63A1\u7528\uFF09\nmerged = {}\n\nfor d in parts:\n    jdir = os.path.join(d,\
    \ \".verify-helper\")\n    for name in CANDIDATE_JSONS:\n        src = os.path.join(jdir,\
    \ name)\n        data = load_json(src)\n        if not data:\n            continue\n\
    \        # data \u306F dict \u3092\u60F3\u5B9A\uFF08{ filepath: meta }\uFF09\n\
    \        cur = merged.get(name, {})\n        for k, v in data.items():\n     \
    \       if k not in cur:\n                cur[k] = v\n            else:\n    \
    \            # \u3067\u304D\u308B\u3060\u3051\u65B0\u3057\u3044\u8A18\u9332\u3092\
    \u6B8B\u3059\uFF08timestamp \u3084 status \u306E\u6BD4\u8F03\uFF09\n         \
    \       # timestamp \u306F \"time\" or \"timestamp\" \u306E\u6570\u5024/\u6587\
    \u5B57\u5217\u3092\u60F3\u5B9A\n                def ts(x):\n                 \
    \   if isinstance(x, dict):\n                        for key in (\"time\", \"\
    timestamp\", \"updated_at\"):\n                            if key in x:\n    \
    \                            return x[key]\n                    return None\n\
    \                if (ts(v) or 0) >= (ts(cur[k]) or 0):\n                    cur[k]\
    \ = v\n        merged[name] = cur\n\n# \u96C6\u7D04 JSON \u3092\u914D\u7F6E\n\
    for name, obj in merged.items():\n    dump_json(OUT / name, obj)\n\n# \u4EE3\u8868\
    \u7684\u306A\u751F\u6210\u7269\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u3092\u30DE\
    \u30FC\u30B8\uFF08\u5FC5\u8981\u306B\u5FDC\u3058\u3066\uFF09\n# \u751F\u6210\u6E08\
    \u307F markdown \u306F docs \u30B9\u30C6\u30C3\u30D7\u3067\u518D\u751F\u6210\u3059\
    \u308B\u306E\u3067\u3053\u3053\u3067\u306F\u4E0D\u8981\u3002\n# \u305F\u3060\u3057\
    \ verify-helper \u304C\u53C2\u7167\u3059\u308B\u4E2D\u9593\u7269\u304C\u3042\u308C\
    \u3070\u30DE\u30FC\u30B8\u3059\u308B\u3002\nfor d in parts:\n    cdir = pathlib.Path(d)\
    \ / \".verify-helper\" / \"cache\"\n    if cdir.exists():\n        dst = OUT /\
    \ \"cache\"\n        dst.mkdir(parents=True, exist_ok=True)\n        for p in\
    \ cdir.rglob(\"*\"):\n            if p.is_file():\n                rel = p.relative_to(cdir)\n\
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
