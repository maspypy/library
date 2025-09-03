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
    import pathlib\nimport sys\nfrom typing import Dict, Any\n\nBASE = \"/tmp/verify-artifacts\"\
    \n# verify-helper-0,1,2,3 ... \u306E\u76F4\u4E0B\u306B .verify-helper \u306E\u300C\
    \u4E2D\u8EAB\u300D\u304C\u5C55\u958B\u3055\u308C\u3066\u3044\u308B\u524D\u63D0\
    \nparts = sorted(glob.glob(os.path.join(BASE, \"verify-helper-*\")))\nOUT = pathlib.Path(\"\
    .verify-helper\")\nOUT.mkdir(parents=True, exist_ok=True)\n\n\ndef load_json_or_empty(p:\
    \ pathlib.Path) -> Dict[str, Any]:\n    try:\n        with p.open(\"r\") as f:\n\
    \            data = json.load(f)\n        if isinstance(data, dict):\n       \
    \     return data\n        # dict \u4EE5\u5916\uFF08list\u7B49\uFF09\u304C\u6765\
    \u305F\u3089\u7A7A\u6271\u3044\u306B\u3059\u308B\n        return {}\n    except\
    \ (FileNotFoundError, json.JSONDecodeError):\n        return {}\n\n\ndef pick_ts(d:\
    \ Dict[str, Any]):\n    # \u4EE3\u8868\u7684\u306A\u30BF\u30A4\u30E0\u30B9\u30BF\
    \u30F3\u30D7\u3063\u307D\u3044\u30AD\u30FC\u3092\u62FE\u3046\n    if isinstance(d,\
    \ dict):\n        for k in (\"time\", \"timestamp\", \"updated_at\"):\n      \
    \      if k in d:\n                return d[k]\n    return None\n\n\ndef merge_maps(dst:\
    \ Dict[str, Any], src: Dict[str, Any]) -> None:\n    for k, v in src.items():\n\
    \        if k not in dst:\n            dst[k] = v\n            continue\n    \
    \    # \u65E2\u5B58\u3068\u885D\u7A81\u3057\u305F\u3089\u300C\u65B0\u3057\u3044\
    \u65B9\u300D\u3092\u63A1\u7528\uFF08\u57FA\u6E96\u30AD\u30FC\u304C\u7121\u3051\
    \u308C\u3070\u4E0A\u66F8\u304D\uFF09\n        t_new, t_old = pick_ts(v), pick_ts(dst[k])\n\
    \        if (t_new or 0) >= (t_old or 0):\n            dst[k] = v\n\n\nif not\
    \ parts:\n    print(f\"No verify artifacts found under {BASE}\", file=sys.stderr)\n\
    \    # \u7A7A\u3067\u3082 docs \u304C\u52D5\u304F\u3088\u3046\u3001\u6700\u4F4E\
    \u9650\u306E\u30D5\u30A1\u30A4\u30EB\u3092\u7528\u610F\n    (OUT / \"timestamps.json\"\
    ).write_text(\"{}\", encoding=\"utf-8\")\n    sys.exit(0)\n\nmerged_timestamps:\
    \ Dict[str, Any] = {}\nmerged_results: Dict[str, Any] = {}\n\n# \u5404\u30D1\u30FC\
    \u30C6\u30A3\u30B7\u30E7\u30F3\u3092\u7D71\u5408\nfor d in parts:\n    dpath =\
    \ pathlib.Path(d)\n    # \u4E2D\u8EAB\u69CB\u9020\u306A\u306E\u3067\u76F4\u4E0B\
    \u306B\u3053\u308C\u3089\u304C\u3044\u308B\n    ts = load_json_or_empty(dpath\
    \ / \"timestamps.json\")\n    ts_remote = load_json_or_empty(dpath / \"timestamps.remote.json\"\
    )\n    res = load_json_or_empty(dpath / \"results.json\")\n\n    # union\uFF08\
    remote \u3082\u53CD\u6620\u3057\u3066\u304A\u304F\uFF09\n    merge_maps(merged_timestamps,\
    \ ts)\n    merge_maps(merged_timestamps, ts_remote)\n    merge_maps(merged_results,\
    \ res)\n\n# \u51FA\u529B\uFF08\u5FC5\u305A\u4F5C\u308B\uFF09\nwith (OUT / \"timestamps.json\"\
    ).open(\"w\") as f:\n    json.dump(merged_timestamps, f, ensure_ascii=False,\n\
    \              indent=2, sort_keys=True)\nwith (OUT / \"results.json\").open(\"\
    w\") as f:\n    json.dump(merged_results, f, ensure_ascii=False, indent=2, sort_keys=True)\n\
    \n# cache \u306F\u5FC5\u8981\u306A\u3089\u30B3\u30D4\u30FC\uFF08\u306A\u304F\u3066\
    \u3082 OK\uFF09\nfor d in parts:\n    cdir = pathlib.Path(d) / \"cache\"\n   \
    \ if cdir.exists():\n        dst = OUT / \"cache\"\n        for p in cdir.rglob(\"\
    *\"):\n            if p.is_file():\n                rel = p.relative_to(cdir)\n\
    \                (dst / rel).parent.mkdir(parents=True, exist_ok=True)\n     \
    \           shutil.copy2(p, dst / rel)\n\nprint(\"Merged verify-helper from:\"\
    , parts)\nprint(f\"Wrote: {OUT / 'timestamps.json'}  (keys={len(merged_timestamps)})\"\
    )\nprint(f\"Wrote: {OUT / 'results.json'}     (keys={len(merged_results)})\")\n"
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
