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
    - https://codeforces.com/contest/1951/problem/I
  bundledCode: "#line 1 \"matroid/K_forest.hpp\"\n// frm, to, \u91CD\u8907\u5EA6\n\
    // https://codeforces.com/contest/1951/problem/I\nbool K_Forest(ll K, int N, vc<tuple<int,\
    \ int, ll>> dat) {\n  ll sm = 0;\n  ll M = len(dat);\n  for (auto& [a, b, cnt]\
    \ : dat) sm += cnt;\n  if (sm > K * (N - 1)) return false;\n\n  int s = 0;\n \
    \ auto left = [&](int v) -> int { return 1 + v; };\n  auto right = [&](int i)\
    \ -> int { return 1 + N + i; };\n  int t = right(M);\n\n  FOR(r, N) {\n    MaxFlow<ll>\
    \ G(t + 1, s, t);\n    FOR(v, N) if (r != v) G.add(s, left(v), K);\n\n    FOR(i,\
    \ M) {\n      auto [a, b, c] = dat[i];\n      G.add(left(a), right(i), infty<ll>);\n\
    \      G.add(left(b), right(i), infty<ll>);\n      G.add(right(i), t, c);\n  \
    \  }\n    if (G.flow() < sm) return 0;\n  }\n  return 1;\n}\n"
  code: "// frm, to, \u91CD\u8907\u5EA6\n// https://codeforces.com/contest/1951/problem/I\n\
    bool K_Forest(ll K, int N, vc<tuple<int, int, ll>> dat) {\n  ll sm = 0;\n  ll\
    \ M = len(dat);\n  for (auto& [a, b, cnt] : dat) sm += cnt;\n  if (sm > K * (N\
    \ - 1)) return false;\n\n  int s = 0;\n  auto left = [&](int v) -> int { return\
    \ 1 + v; };\n  auto right = [&](int i) -> int { return 1 + N + i; };\n  int t\
    \ = right(M);\n\n  FOR(r, N) {\n    MaxFlow<ll> G(t + 1, s, t);\n    FOR(v, N)\
    \ if (r != v) G.add(s, left(v), K);\n\n    FOR(i, M) {\n      auto [a, b, c] =\
    \ dat[i];\n      G.add(left(a), right(i), infty<ll>);\n      G.add(left(b), right(i),\
    \ infty<ll>);\n      G.add(right(i), t, c);\n    }\n    if (G.flow() < sm) return\
    \ 0;\n  }\n  return 1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: matroid/K_forest.hpp
  requiredBy: []
  timestamp: '2025-10-30 08:59:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matroid/K_forest.hpp
layout: document
redirect_from:
- /library/matroid/K_forest.hpp
- /library/matroid/K_forest.hpp.html
title: matroid/K_forest.hpp
---
