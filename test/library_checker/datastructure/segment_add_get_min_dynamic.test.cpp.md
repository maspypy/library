---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/func/dynamic_lichao.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/segment_add_get_min\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/func/dynamic_lichao.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  ll max = 1'000'000'000;\n  Dynamic_LiChaoTree<ll,\
    \ 14'000'000> seg(-max, max + 1);\n  FOR(N) {\n    LL(l, r, a, b);\n    seg.add_segment(l,\
    \ r, a, b);\n  }\n  const ll INF = 1LL << 60;\n  FOR(Q) {\n    LL(t);\n    if\
    \ (t == 0) {\n      LL(l, r, a, b);\n      seg.add_segment(l, r, a, b);\n    }\n\
    \    if (t == 1) {\n      LL(x);\n      ll y = seg.query(x).fi;\n      if (y >=\
    \ INF)\n        print(\"INFINITY\");\n      else\n        print(y);\n    }\n \
    \ }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
- /verify/test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp.html
title: test/library_checker/datastructure/segment_add_get_min_dynamic.test.cpp
---
