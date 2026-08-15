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
    \  [Previous line repeated 3 more times]\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"random/base.hpp\"\n#include \"convex/lattice_point_sum_polynomial_pq.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\ntemplate <int K1,\
    \ int K2>\nvoid test(mint p, mint q) {\n  ll N = RNG(0, 7);\n  vc<tuple<ll, ll,\
    \ ll>> LINE;\n\n  FOR(N) {\n    while (1) {\n      ll a = RNG(-3, 4);\n      ll\
    \ b = RNG(-3, 4);\n      if (a == 0 && b == 0) continue;\n      ll c = RNG(-30,\
    \ 31);\n      LINE.eb(a, b, c);\n      break;\n    }\n  }\n\n  array<array<mint,\
    \ K2 + 1>, K1 + 1> god{};\n  auto add_point = [&](ll x, ll y) -> void {\n    FOR(i,\
    \ K1 + 1) FOR(j, K2 + 1) { god[i][j] += p.pow(x) * q.pow(y) * mint(x).pow(i) *\
    \ mint(y).pow(j); }\n  };\n\n  ll K = 200;\n  FOR(x, -2 * K, 2 * K + 1) {\n  \
    \  ll mi = -infty<ll>, ma = infty<ll>;\n    for (auto& [a, b, c]: LINE) {\n  \
    \    if (b == 0) {\n        // ax>=c\n        if (a * x <= c) continue;\n    \
    \    mi = infty<ll> + 1;\n        break;\n      }\n      if (b > 0) { chmin(ma,\
    \ floor<ll>(c - a * x, b)); }\n      if (b < 0) { chmax(mi, ceil<ll>(a * x - c,\
    \ -b)); }\n    }\n\n    if (mi > ma) continue;\n    if (abs(x) >= K || mi == -infty<ll>\
    \ || ma == infty<ll>) {\n      FOR(i, K1 + 1) FOR(j, K2 + 1) god[i][j] = 0;\n\
    \      break;\n    }\n    FOR(y, mi, ma + 1) add_point(x, y);\n  }\n\n  auto ANS\
    \ = lattice_point_sum_polynomial_pq<mint, K1, K2>(p, q, LINE);\n  assert(god ==\
    \ ANS);\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b <<\
    \ \"\\n\";\n}\n\nsigned main() {\n  FOR(100) {\n    FOR(p, 1, 4) FOR(q, 1, 4)\
    \ {\n      test<0, 0>(p, q);\n      test<0, 1>(p, q);\n      test<0, 2>(p, q);\n\
    \      test<1, 0>(p, q);\n      test<1, 1>(p, q);\n      test<1, 2>(p, q);\n \
    \     test<2, 0>(p, q);\n      test<2, 1>(p, q);\n      test<2, 2>(p, q);\n  \
    \    test<3, 3>(p, q);\n    }\n  }\n\n  solve();\n\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
- /verify/test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp.html
title: test/1_mytest/lattice_point_sum_polynomial_pq.test.cpp
---
