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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree/segtree2d.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc266/tasks/abc266_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/segtree/segtree2d.hpp\"\
    \n#include \"alg/monoid/max.hpp\"\n\nusing Mono = Monoid_Max<ll>;\n\nvoid naive()\
    \ {\n  LL(N);\n  using T = tuple<ll, ll, ll, ll>;\n\n  VEC(T, dat, N);\n  dat.eb(0,\
    \ 0, 0, 0);\n  ++N;\n\n  sort(all(dat), [&](auto& a, auto& b) -> bool {\n    auto\
    \ [at, ax, ay, aa] = a;\n    auto [bt, bx, by, bb] = b;\n    if (ay < by) return\
    \ true;\n    if (ay > by) return false;\n    return at < bt;\n  });\n\n  const\
    \ ll INF = 1LL << 60;\n  vi dp(N, -INF);\n  dp[0] = 0;\n  FOR(j, N) {\n    auto\
    \ [tj, xj, yj, vvj] = dat[j];\n    FOR(i, j) {\n      auto [ti, xi, yi, vvi] =\
    \ dat[i];\n      ll d = abs(xi - xj) + abs(yi - yj);\n      if (yi > yj) continue;\n\
    \      if (ti + d > tj) continue;\n      chmax(dp[j], dp[i] + vvj);\n    }\n \
    \   print(tj, xj, yj, vvj, dp[j]);\n  }\n  print(MAX(dp));\n}\n\nvoid solve()\
    \ {\n  // return naive();\n\n  LL(N);\n  using T = tuple<ll, ll, ll, ll>;\n\n\
    \  VEC(T, dat, N);\n  dat.eb(0, 0, 0, 0);\n  ++N;\n\n  sort(all(dat), [&](auto&\
    \ a, auto& b) -> bool {\n    auto [at, ax, ay, aa] = a;\n    auto [bt, bx, by,\
    \ bb] = b;\n    if (ay < by) return true;\n    if (ay > by) return false;\n  \
    \  return at < bt;\n  });\n\n  /*\n  \u53F3\u4E0A\u3078\u306E\u9077\u79FB\uFF1A\
    \n  (x,y,t) \u304C\u60C5\u5831 (a,b,c,v) \u3092\u53D7\u3051\u53D6\u308B\u306E\u306F\
    \n  a<=x, x+y-t<=a+b-c\n  \u30FB(a,a+b-c) \u306B\u60C5\u5831\u3092\u8FFD\u52A0\
    \u3059\u308B\n  \u30FB[-INF,x] x [x+y-t, INF] \u3067\u306E\u6700\u5927\u5024\u3092\
    \u6C42\u3081\u308B\n\n  \u5DE6\u4E0A\u3078\u306E\u9077\u79FB\uFF1A\n  (a-x)+(y-b)<=t-c\n\
    \  x<=a, a-b+c<=x-y+t\n  */\n  vi X1(N), Y1(N), X2(N), Y2(N);\n  FOR(i, N) {\n\
    \    auto [t, x, y, v] = dat[i];\n    X1[i] = x;\n    X2[i] = x;\n    Y1[i] =\
    \ x + y - t;\n    Y2[i] = x - y + t;\n  }\n  SegTree2D<Mono, ll, false> seg1(X1,\
    \ Y1);\n  SegTree2D<Mono, ll, false> seg2(X2, Y2);\n\n  const ll INF = 1LL <<\
    \ 60;\n\n  ll ANS = 0;\n  FOR(i, N) {\n    const auto [t, x, y, v] = dat[i];\n\
    \    const ll a = x, b = y, c = t;\n    if (i == 0) {\n      seg1.multiply(a,\
    \ a + b - c, 0);\n      seg2.multiply(a, a - b + c, 0);\n      continue;\n   \
    \ }\n    ll best = -INF;\n    chmax(best, seg1.prod(-INF, x + 1, x + y - t, INF));\n\
    \    chmax(best, seg2.prod(x, INF, -INF, x - y + t + 1));\n    if (best < 0) continue;\n\
    \    best += v;\n    chmax(ANS, best);\n    seg1.multiply(a, a + b - c, best);\n\
    \    seg2.multiply(a, a - b + c, best);\n  }\n  print(ANS);\n}\n\nsigned main()\
    \ {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T)\
    \ solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/atcoder/abc266h.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc266h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc266h.test.cpp
- /verify/test/atcoder/abc266h.test.cpp.html
title: test/atcoder/abc266h.test.cpp
---
