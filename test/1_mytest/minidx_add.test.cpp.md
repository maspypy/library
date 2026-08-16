---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid/min_idx.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"alg/acted_monoid/minidx_add.hpp\"\n#include \"random/base.hpp\"\n\
    #include \"ds/segtree/lazy_segtree.hpp\"\n\nvoid test() {\n  int N = RNG(1, 100);\n\
    \  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(1, 100);\n  using AM = ActedMonoid_MinIdx_Add<int>;\n\
    \  using Mono = typename AM::Monoid_X;\n  Lazy_SegTree<AM> seg(N, [&](int i) ->\
    \ typename Mono::value_type {\n    return {A[i], i};\n  });\n  int Q = RNG(1,\
    \ 100);\n  FOR(Q) {\n    ll t = RNG(0, 2);\n    ll L = RNG(0, N);\n    ll R =\
    \ RNG(0, N);\n    if (L > R) swap(L, R);\n    ++R;\n    if (t == 1) {\n      ll\
    \ x = RNG(1, 100);\n      FOR(i, L, R) A[i] += x;\n      seg.apply(L, R, x);\n\
    \    }\n    if (t == 2) {\n      vc<int> B = {A.begin() + L, A.begin() + R};\n\
    \      int mx = MIN(B);\n      int idx = -1;\n      FOR_R(i, L, R) if (A[i] ==\
    \ mx) idx = i;\n      assert(seg.prod(L, R) == mp(mx, idx));\n    }\n  }\n}\n\n\
    void solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\
    \nsigned main() {\n  FOR(100) test();\n  solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/minidx_add.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/minidx_add.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/minidx_add.test.cpp
- /verify/test/1_mytest/minidx_add.test.cpp.html
title: test/1_mytest/minidx_add.test.cpp
---
