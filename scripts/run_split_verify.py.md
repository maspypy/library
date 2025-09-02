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
  code: "#!/usr/bin/env python3\nimport argparse\nimport subprocess\nimport sys\n\
    import glob\n\n\ndef main():\n    p = argparse.ArgumentParser()\n    p.add_argument(\"\
    --split\", type=int, required=True)\n    p.add_argument(\"--index\", type=int,\
    \ required=True)\n    p.add_argument(\"-j\", \"--jobs\", type=int, default=1)\n\
    \    args = p.parse_args()\n\n    files = sorted(glob.glob(\"test/**/*.test.cpp\"\
    , recursive=True))\n\n    selected = [f for i, f in enumerate(files) if i % args.split\
    \ == args.index]\n\n    if not selected:\n        print(\"No tests for this partition.\"\
    )\n        return 0\n\n    cmd = [\"oj-verify\", \"run\", \"-j\", str(args.jobs)]\
    \ + selected\n    print(\"Running:\", \" \".join(cmd))\n    return subprocess.call(cmd)\n\
    \n\nif __name__ == \"__main__\":\n    sys.exit(main())\n"
  dependsOn: []
  isVerificationFile: false
  path: scripts/run_split_verify.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: scripts/run_split_verify.py
layout: document
redirect_from:
- /library/scripts/run_split_verify.py
- /library/scripts/run_split_verify.py.html
title: scripts/run_split_verify.py
---
