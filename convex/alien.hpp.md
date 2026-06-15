---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/alien.test.cpp
    title: test/1_mytest/alien.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convex/alien.hpp\"\n\n// T \u306F\u6574\u6570\u578B\u3092\
    \u4EEE\u5B9A\n// solve(penalty, minimize_cnt) -> {dp, frm}\n// lo: cnt > K, hi:\
    \ cnt <= K\ntemplate <typename T, typename F>\nT alien_trick(int N, int K, T lo,\
    \ T hi, F solve) {\n  while (lo + 1 < hi) {\n    T mid = lo + (hi - lo) / 2;\n\
    \n    auto [dp, frm] = solve(mid, true);\n    int cnt = 0, v = N;\n    while (v)\
    \ ++cnt, v = frm[v];\n\n    if (cnt <= K) {\n      hi = mid;\n    } else {\n \
    \     lo = mid;\n    }\n  }\n\n  auto [dp, frm] = solve(hi, true);\n  return dp[N]\
    \ - hi * K;\n}\n\n// T \u306F\u6574\u6570\u578B\u3092\u4EEE\u5B9A\n// solve(penalty,\
    \ minimize_cnt) -> {dp, frm}\n// lo: cnt > K, hi: cnt <= K\ntemplate <typename\
    \ T, typename F, typename G>\npair<T, vc<int>> alien_trick_restore(int N, int\
    \ K, type_identity_t<T> lo,\n                                     type_identity_t<T>\
    \ hi, F solve, G cost) {\n  while (lo + 1 < hi) {\n    T mid = lo + (hi - lo)\
    \ / 2;\n    auto [dp, frm] = solve(mid, true);\n    int cnt = 0, v = N;\n    while\
    \ (v) ++cnt, v = frm[v];\n\n    if (cnt <= K) {\n      hi = mid;\n    } else {\n\
    \      lo = mid;\n    }\n  }\n\n  auto [dp, frm1] = solve(hi, true);\n  auto [dp2,\
    \ frm2] = solve(hi, false);\n  assert(dp2 == dp);\n  vc<int> cnt_min(N + 1), cnt_max(N\
    \ + 1);\n  T ANS = dp[N] - hi * K;\n  FOR(i, 1, N + 1) cnt_min[i] = cnt_min[frm1[i]]\
    \ + 1;\n  FOR(i, 1, N + 1) cnt_max[i] = cnt_max[frm2[i]] + 1;\n  assert(cnt_min[N]\
    \ <= K && K <= cnt_max[N]);\n  vc<int> path;\n  path.eb(N);\n  int rest = K;\n\
    \  int j = N;\n  FOR_R(i, N) {\n    if (dp[j] == dp[i] + cost(i, j) + hi && cnt_min[i]\
    \ <= rest - 1 &&\n        rest - 1 <= cnt_max[i]) {\n      path.eb(i);\n     \
    \ --rest;\n      j = i;\n    }\n  }\n  assert(j == 0 && rest == 0);\n  reverse(all(path));\n\
    \  return {ANS, path};\n}\n"
  code: "#pragma once\n\n// T \u306F\u6574\u6570\u578B\u3092\u4EEE\u5B9A\n// solve(penalty,\
    \ minimize_cnt) -> {dp, frm}\n// lo: cnt > K, hi: cnt <= K\ntemplate <typename\
    \ T, typename F>\nT alien_trick(int N, int K, T lo, T hi, F solve) {\n  while\
    \ (lo + 1 < hi) {\n    T mid = lo + (hi - lo) / 2;\n\n    auto [dp, frm] = solve(mid,\
    \ true);\n    int cnt = 0, v = N;\n    while (v) ++cnt, v = frm[v];\n\n    if\
    \ (cnt <= K) {\n      hi = mid;\n    } else {\n      lo = mid;\n    }\n  }\n\n\
    \  auto [dp, frm] = solve(hi, true);\n  return dp[N] - hi * K;\n}\n\n// T \u306F\
    \u6574\u6570\u578B\u3092\u4EEE\u5B9A\n// solve(penalty, minimize_cnt) -> {dp,\
    \ frm}\n// lo: cnt > K, hi: cnt <= K\ntemplate <typename T, typename F, typename\
    \ G>\npair<T, vc<int>> alien_trick_restore(int N, int K, type_identity_t<T> lo,\n\
    \                                     type_identity_t<T> hi, F solve, G cost)\
    \ {\n  while (lo + 1 < hi) {\n    T mid = lo + (hi - lo) / 2;\n    auto [dp, frm]\
    \ = solve(mid, true);\n    int cnt = 0, v = N;\n    while (v) ++cnt, v = frm[v];\n\
    \n    if (cnt <= K) {\n      hi = mid;\n    } else {\n      lo = mid;\n    }\n\
    \  }\n\n  auto [dp, frm1] = solve(hi, true);\n  auto [dp2, frm2] = solve(hi, false);\n\
    \  assert(dp2 == dp);\n  vc<int> cnt_min(N + 1), cnt_max(N + 1);\n  T ANS = dp[N]\
    \ - hi * K;\n  FOR(i, 1, N + 1) cnt_min[i] = cnt_min[frm1[i]] + 1;\n  FOR(i, 1,\
    \ N + 1) cnt_max[i] = cnt_max[frm2[i]] + 1;\n  assert(cnt_min[N] <= K && K <=\
    \ cnt_max[N]);\n  vc<int> path;\n  path.eb(N);\n  int rest = K;\n  int j = N;\n\
    \  FOR_R(i, N) {\n    if (dp[j] == dp[i] + cost(i, j) + hi && cnt_min[i] <= rest\
    \ - 1 &&\n        rest - 1 <= cnt_max[i]) {\n      path.eb(i);\n      --rest;\n\
    \      j = i;\n    }\n  }\n  assert(j == 0 && rest == 0);\n  reverse(all(path));\n\
    \  return {ANS, path};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/alien.hpp
  requiredBy: []
  timestamp: '2026-06-15 22:08:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/alien.test.cpp
documentation_of: convex/alien.hpp
layout: document
redirect_from:
- /library/convex/alien.hpp
- /library/convex/alien.hpp.html
title: convex/alien.hpp
---
