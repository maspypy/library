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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/acted_monoid/cntsummin_assign.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/acted_monoid/cntsummin_assign.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"ds/segtree/lazysegtree.hpp\"\n\nvoid\
    \ test() {\n  int N = RNG(1, 100);\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(1,\
    \ 100);\n  using AM = ActedMonoid_CntSumMin_Assign<ll, -1>;\n  using Mono = typename\
    \ AM::Monoid_X;\n  LazySegTree<AM> seg(\n      N, [&](int i) -> Mono::value_type\
    \ { return Mono::from_element(A[i]); });\n  int Q = RNG(1, 100);\n  FOR(Q) {\n\
    \    ll t = RNG(0, 2);\n    ll L = RNG(0, N);\n    ll R = RNG(0, N);\n    if (L\
    \ > R) swap(L, R);\n    ++R;\n    if (t == 1) {\n      ll x = RNG(1, 100);\n \
    \     FOR(i, L, R) A[i] = x;\n      seg.apply(L, R, x);\n    }\n    if (t == 2)\
    \ {\n      vc<int> B = {A.begin() + L, A.begin() + R};\n      auto [cnt, sm, mi]\
    \ = seg.prod(L, R);\n      assert(cnt == len(B));\n      assert(sm == SUM<ll>(B));\n\
    \      assert(mi == MIN(B));\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n \
    \ print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n  FOR(100) test();\n  solve();\n\n  return 0;\n\
    }\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/cntsummin_assign.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/cntsummin_assign.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/cntsummin_assign.test.cpp
- /verify/test/mytest/cntsummin_assign.test.cpp.html
title: test/mytest/cntsummin_assign.test.cpp
---
