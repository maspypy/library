---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.7/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree/range_add_range_max.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"alg/acted_monoid/max_add.hpp\"\n#include \"ds/segtree/lazy_segtree.hpp\"\
    \n#include \"ds/segtree/range_add_range_max.hpp\"\n#include \"random/base.hpp\"\
    \n\nvi sol_0(int N, int Q, vi A, vc<tuple<int, int, int, int>> query) {\n  Lazy_SegTree<ActedMonoid_Max_Add<ll>>\
    \ seg(A);\n  vi ANS;\n  for (auto [t, l, r, x] : query) {\n    if (t == 0) {\n\
    \      ANS.eb(seg.prod(l, r));\n    }\n    if (t == 1) {\n      seg.apply(l, r,\
    \ x);\n    }\n  }\n  return ANS;\n}\n\nvi sol_1(int N, int Q, vi A, vc<tuple<int,\
    \ int, int, int>> query) {\n  Range_Add_Range_Max<ll> seg(A);\n  vi ANS;\n  for\
    \ (auto [t, l, r, x] : query) {\n    if (t == 0) {\n      ANS.eb(seg.prod(l, r));\n\
    \    }\n    if (t == 1) {\n      seg.apply(l, r, x);\n    }\n  }\n  return ANS;\n\
    }\n\nvoid test_1() {\n  int N = 1'000'000;\n  int Q = 1'000'000;\n  int K = 1'000'000'000;\n\
    \  vi A(N);\n  vc<tuple<int, int, int, int>> query(Q);\n  FOR(i, N) A[i] = RNG(-K,\
    \ K + 1);\n  FOR(q, Q) {\n    int t = RNG(0, 2);\n    int l = RNG(0, N);\n   \
    \ int r = RNG(0, N);\n    if (l > r)\n      swap(l, r);\n    ++r;\n    int x =\
    \ RNG(-K, K + 1);\n    query[q] = {t, l, r, x};\n  }\n  auto T0 = std::chrono::high_resolution_clock::now();\n\
    \  auto ANS_0 = sol_0(N, Q, A, query);\n  auto T1 = std::chrono::high_resolution_clock::now();\n\
    \  auto ANS_1 = sol_1(N, Q, A, query);\n  auto T2 = std::chrono::high_resolution_clock::now();\n\
    \  double t0 = chrono::duration<double>(T1 - T0).count();\n  double t1 = chrono::duration<double>(T2\
    \ - T1).count();\n  assert(ANS_0 == ANS_1);\n  // cout << t0 << \" \" << t1 <<\
    \ endl;\n  // 10 \u56DE\u5E73\u5747\u3067 450ms, 270ms \u7A0B\u5EA6.\n}\n\nvoid\
    \ test_2() {\n  FOR(N, 1, 10) {\n    FOR(Q, 1, 10) {\n      int K = 1'000'000'000;\n\
    \      vi A(N);\n      vc<tuple<int, int, int, int>> query(Q);\n      FOR(i, N)\
    \ A[i] = RNG(-K, K + 1);\n      FOR(q, Q) {\n        int t = RNG(0, 2);\n    \
    \    int l = RNG(0, N);\n        int r = RNG(0, N);\n        if (l > r)\n    \
    \      swap(l, r);\n        ++r;\n        int x = RNG(-K, K + 1);\n        query[q]\
    \ = {t, l, r, x};\n      }\n      auto ANS_0 = sol_0(N, Q, A, query);\n      auto\
    \ ANS_1 = sol_1(N, Q, A, query);\n      assert(ANS_0 == ANS_1);\n    }\n  }\n\
    }\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\"\
    ;\n}\n\nsigned main() {\n  test_1();\n  test_2();\n  solve();\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/range_add_range_max.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/range_add_range_max.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/range_add_range_max.test.cpp
- /verify/test/1_mytest/range_add_range_max.test.cpp.html
title: test/1_mytest/range_add_range_max.test.cpp
---
