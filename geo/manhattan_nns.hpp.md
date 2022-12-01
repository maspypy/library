---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/gym/103577/problem/K
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ds/segtree.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/segtree.hpp\"\r\n#include \"alg/monoid/min_idx.hpp\"\r\n\r\n\
    // https://codeforces.com/gym/103577/problem/K\r\n// \u70B9\u7FA4 FRM \u304B\u3089\
    \u70B9\u7FA4 TO \u3078\u306E\u6700\u8FD1\u70B9\u63A2\u7D22\r\n// vector \u306E\
    \ pair \u3092\u8FD4\u3059\uFF1Adist, nbd_idx\r\ntemplate <typename X = ll>\r\n\
    pair<vc<X>, vc<int>> manhattan_nns(vc<pair<X, X>> FRM, vc<pair<X, X>>& TO) {\r\
    \n  assert(len(TO) >= 1);\r\n  int N = len(FRM), M = len(TO);\r\n  vc<pair<X,\
    \ X>> points(N + M);\r\n  FOR(i, N) points[i] = FRM[i];\r\n  FOR(i, M) points[N\
    \ + i] = TO[i];\r\n  vc<X> Y(M);\r\n  FOR(i, M) Y[i] = TO[i].se;\r\n  UNIQUE(Y);\r\
    \n\r\n  const X INF = numeric_limits<X>::max();\r\n\r\n  vc<int> nbd_idx(N, -1);\r\
    \n  vc<X> dist(N, INF);\r\n\r\n  auto add_ans = [&](int i, int j) -> void {\r\n\
    \    if (j == -1) return;\r\n    X dx = points[i].fi - points[j].fi;\r\n    X\
    \ dy = points[i].se - points[j].se;\r\n    if (chmin(dist[i], abs(dx) + abs(dy)))\
    \ nbd_idx[i] = j - N;\r\n  };\r\n\r\n  vc<int> I(N + M);\r\n  iota(all(I), 0);\r\
    \n  sort(all(I), [&](auto& i, auto& j) { return (points[i].fi < points[j].fi);\
    \ });\r\n  auto calc = [&]() -> void {\r\n    SegTree<Monoid_Min_Idx<ll, INF>>\
    \ seg1(len(Y)), seg2(len(Y));\r\n    for (auto&& i: I) {\r\n      auto [x, y]\
    \ = points[i];\r\n      int idx = LB(Y, y);\r\n      if (i < N) {\r\n        add_ans(i,\
    \ seg1.prod(idx, len(Y)).se);\r\n        add_ans(i, seg2.prod(0, idx).se);\r\n\
    \      }\r\n      elif (i >= N) {\r\n        seg1.set(idx, {y - x, i});\r\n  \
    \      seg2.set(idx, {-(x + y), i});\r\n      }\r\n    }\r\n  };\r\n\r\n  calc();\r\
    \n  reverse(all(I));\r\n  FOR(i, N + M) points[i].fi *= -1;\r\n  calc();\r\n\r\
    \n  return {dist, nbd_idx};\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: geo/manhattan_nns.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/manhattan_nns.hpp
layout: document
redirect_from:
- /library/geo/manhattan_nns.hpp
- /library/geo/manhattan_nns.hpp.html
title: geo/manhattan_nns.hpp
---
