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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bit.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"ds/segtree/beats_kinetic.hpp\"\n#include\
    \ \"random/base.hpp\"\n\nvoid test_mi() {\n  FOR(N, 1, 100) {\n    vi X(N), Y(N);\n\
    \    FOR(i, N) X[i] = RNG(-100, 100);\n    FOR(i, N) Y[i] = RNG(-100, 100);\n\
    \    Beats_Kinetic_Min<ll, ll> seg(N, [&](int i) -> pair<int, int> { return {X[i],\
    \ Y[i]}; });\n    ll Q = 100;\n    FOR(Q) {\n      ll t = RNG(0, 3);\n      ll\
    \ i = RNG(0, N);\n      ll L = RNG(0, N);\n      ll R = RNG(L, N + 1);\n     \
    \ ll a = RNG(-100, 100);\n      ll b = RNG(-100, 100);\n      if (t == 0) {\n\
    \        // set\n        seg.set(i, a, b);\n        X[i] = a, Y[i] = b;\n    \
    \  }\n      if (t == 1) {\n        // apply\n        a = abs(a);\n        seg.apply(L,\
    \ R, a, b);\n        FOR(i, L, R) Y[i] += a * X[i] + b;\n      }\n      if (t\
    \ == 2) {\n        // prod\n        ll mi = infty<ll>;\n        FOR(i, L, R) chmin(mi,\
    \ Y[i]);\n        auto [idx, x, y] = seg.prod(L, R);\n        assert(mi == y);\n\
    \      }\n    }\n  }\n}\n\nvoid test_ma() {\n  FOR(N, 1, 100) {\n    vi X(N),\
    \ Y(N);\n    FOR(i, N) X[i] = RNG(-100, 100);\n    FOR(i, N) Y[i] = RNG(-100,\
    \ 100);\n    Beats_Kinetic_Max<ll, ll> seg(N, [&](int i) -> pair<int, int> { return\
    \ {X[i], Y[i]}; });\n    ll Q = 100;\n    FOR(Q) {\n      ll t = RNG(0, 3);\n\
    \      ll i = RNG(0, N);\n      ll L = RNG(0, N);\n      ll R = RNG(L, N + 1);\n\
    \      ll a = RNG(-100, 100);\n      ll b = RNG(-100, 100);\n      if (t == 0)\
    \ {\n        // set\n        seg.set(i, a, b);\n        X[i] = a, Y[i] = b;\n\
    \      }\n      if (t == 1) {\n        // apply\n        a = abs(a);\n       \
    \ seg.apply(L, R, a, b);\n        FOR(i, L, R) Y[i] += a * X[i] + b;\n      }\n\
    \      if (t == 2) {\n        // prod\n        ll ma = -infty<ll>;\n        FOR(i,\
    \ L, R) chmax(ma, Y[i]);\n        auto [idx, x, y] = seg.prod(L, R);\n       \
    \ assert(ma == y);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin\
    \ >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(100) {\n\
    \    test_mi();\n    test_ma();\n  }\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/kinetic.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/kinetic.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/kinetic.test.cpp
- /verify/test/1_mytest/kinetic.test.cpp.html
title: test/1_mytest/kinetic.test.cpp
---
