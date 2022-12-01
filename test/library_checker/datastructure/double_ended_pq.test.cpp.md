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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/dynamic_segtree.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/dynamic_segtree.hpp\"\
    \n#include \"alg/monoid/add.hpp\"\n\nvoid solve() {\n  // \u52D5\u7684\u30BB\u30B0\
    \u6728\u3067\u306E\u4E8C\u5206\u63A2\u7D22\n  LL(N, Q);\n  VEC(int, A, N);\n \
    \ const int LIM = 1'000'000'000;\n\n  Dynamic_SegTree<Monoid_Add<int>, 30'000'000>\
    \ seg(-LIM, LIM + 1);\n  for (auto&& a: A) seg.multiply(a, 1);\n\n  FOR(Q) {\n\
    \    LL(t);\n    if (t == 0) {\n      LL(x);\n      seg.multiply(x, 1);\n    }\n\
    \    if (t == 1) {\n      auto check = [&](auto e) -> bool { return e == 0; };\n\
    \      int ANS = seg.max_right(check, -LIM);\n      print(ANS);\n      seg.multiply(ANS,\
    \ -1);\n    }\n    if (t == 2) {\n      auto check = [&](auto e) -> bool { return\
    \ e == 0; };\n      int ANS = seg.min_left(check, LIM + 1) - 1;\n      print(ANS);\n\
    \      seg.multiply(ANS, -1);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/datastructure/double_ended_pq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/double_ended_pq.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/double_ended_pq.test.cpp
- /verify/test/library_checker/datastructure/double_ended_pq.test.cpp.html
title: test/library_checker/datastructure/double_ended_pq.test.cpp
---
