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
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/fenwick/fenwick.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n\n#include \"ds/offline_query/rectangle_add_point_sum.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\nusing QT = tuple<ll,\
    \ ll, ll, ll, ll>;\n\npair<vc<QT>, vc<pi>> gen(int H, int W, int Q) {\n  vc<tuple<ll,\
    \ ll, ll, ll, ll>> add_query;\n  FOR(Q) {\n    ll a = RNG(0, H);\n    ll b = RNG(a\
    \ + 1, H + 1);\n    ll c = RNG(0, W);\n    ll d = RNG(c + 1, W + 1);\n    ll x\
    \ = RNG(0, mint::get_mod());\n    add_query.eb(a, b, c, d, x);\n  }\n\n  vc<pi>\
    \ sum_query;\n  FOR(Q) {\n    ll x = RNG(0, H), y = RNG(0, W);\n    sum_query.eb(x,\
    \ y);\n  }\n  return {add_query, sum_query};\n}\n\nvc<mint> sol_1(int H, int W,\
    \ vc<QT> add_query, vc<pi> sum_query) {\n  vv(mint, A, H, W);\n  for (auto&& [a,\
    \ b, c, d, x]: add_query) {\n    FOR(i, a, b) FOR(j, c, d) { A[i][j] += mint(x);\
    \ }\n  }\n  vc<mint> ANS;\n  for (auto&& [x, y]: sum_query) ANS.eb(A[x][y]);\n\
    \  return ANS;\n}\n\nvc<mint> sol_2(int H, int W, vc<QT> add_query, vc<pi> sum_query)\
    \ {\n  vc<mint> ANS;\n  for (auto&& [x, y]: sum_query) {\n    mint ans = 0;\n\
    \    for (auto&& [a, b, c, d, v]: add_query) {\n      if (a <= x && x < b && c\
    \ <= y && y < d) ans += mint(v);\n    }\n    ANS.eb(ans);\n  }\n  return ANS;\n\
    }\n\nvoid test() {\n  FOR(H, 1, 10) FOR(W, 1, 10) FOR(Q, 10) {\n    auto [add_query,\
    \ sum_query] = gen(H, W, Q);\n    Rectangle_Add_Point_Sum<Monoid_Add<mint>, 0>\
    \ X;\n    for (auto&& [a, b, c, d, v]: add_query) X.add_query(a, b, c, d, v);\n\
    \    for (auto&& [a, b]: sum_query) X.sum_query(a, b);\n    assert(X.calc() ==\
    \ sol_1(H, W, add_query, sum_query));\n  }\n  FOR(H, 1, 10) FOR(W, 1, 10) FOR(Q,\
    \ 10) {\n    auto [add_query, sum_query] = gen(H, W, Q);\n    Rectangle_Add_Point_Sum<Monoid_Add<mint>,\
    \ 1> X;\n    for (auto&& [a, b, c, d, v]: add_query) X.add_query(a, b, c, d, v);\n\
    \    for (auto&& [a, b]: sum_query) X.sum_query(a, b);\n    assert(X.calc() ==\
    \ sol_1(H, W, add_query, sum_query));\n  }\n  FOR(10) {\n    int H = RNG(1, 1'000'000'000);\n\
    \    int W = RNG(1, 1'000'000'000);\n    int Q = 100;\n    auto [add_query, sum_query]\
    \ = gen(H, W, Q);\n    Rectangle_Add_Point_Sum<Monoid_Add<mint>, 0> X;\n    for\
    \ (auto&& [a, b, c, d, v]: add_query) X.add_query(a, b, c, d, v);\n    for (auto&&\
    \ [a, b]: sum_query) X.sum_query(a, b);\n    assert(X.calc() == sol_2(H, W, add_query,\
    \ sum_query));\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\n\
    signed main() {\n  cout << fixed << setprecision(15);\n\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/rect_add_pt_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/rect_add_pt_sum.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/rect_add_pt_sum.test.cpp
- /verify/test/mytest/rect_add_pt_sum.test.cpp.html
title: test/mytest/rect_add_pt_sum.test.cpp
---
