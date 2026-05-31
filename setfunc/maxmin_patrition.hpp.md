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
    - https://codeforces.com/blog/entry/153948?#comment-1367191
  bundledCode: "#line 1 \"setfunc/maxmin_patrition.hpp\"\n\n// https://codeforces.com/blog/entry/153948?#comment-1367191\n\
    // O(n 2^n)\ntemplate <typename WT>\nWT maxmin_partition(int K, vc<WT> A) {\n\
    \  int N = len(A);\n  if (N < K) return 0;\n  assert(1 <= K && K <= N);\n  vc<WT>\
    \ S(1 << N);\n  FOR(i, N) FOR(s, 1 << i) S[s | 1 << i] = S[s] + A[i];\n\n  WT\
    \ ANS = 0;\n  int full = (1 << N) - 1;\n  using P = pair<int, WT>;\n  vc<P> dp(1\
    \ << N);\n  for (int s = 0; s < (1 << N); ++s) {\n    int other = full ^ s;\n\
    \    auto [k, w] = dp[s];\n    WT W = S[other] + w;\n    if (k == K - 1) {\n \
    \     chmax(ANS, W);\n      continue;\n    }\n    while (other) {\n      int i\
    \ = lowbit(other);\n      other &= other - 1;\n      int t = s | 1 << i;\n   \
    \   WT x = w + A[i];\n      P nxt = (x * (K - k) >= W ? P(k + 1, 0) : P(k, x));\n\
    \      chmax(dp[t], nxt);\n    }\n  }\n  return ANS;\n}\n"
  code: "\n// https://codeforces.com/blog/entry/153948?#comment-1367191\n// O(n 2^n)\n\
    template <typename WT>\nWT maxmin_partition(int K, vc<WT> A) {\n  int N = len(A);\n\
    \  if (N < K) return 0;\n  assert(1 <= K && K <= N);\n  vc<WT> S(1 << N);\n  FOR(i,\
    \ N) FOR(s, 1 << i) S[s | 1 << i] = S[s] + A[i];\n\n  WT ANS = 0;\n  int full\
    \ = (1 << N) - 1;\n  using P = pair<int, WT>;\n  vc<P> dp(1 << N);\n  for (int\
    \ s = 0; s < (1 << N); ++s) {\n    int other = full ^ s;\n    auto [k, w] = dp[s];\n\
    \    WT W = S[other] + w;\n    if (k == K - 1) {\n      chmax(ANS, W);\n     \
    \ continue;\n    }\n    while (other) {\n      int i = lowbit(other);\n      other\
    \ &= other - 1;\n      int t = s | 1 << i;\n      WT x = w + A[i];\n      P nxt\
    \ = (x * (K - k) >= W ? P(k + 1, 0) : P(k, x));\n      chmax(dp[t], nxt);\n  \
    \  }\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/maxmin_patrition.hpp
  requiredBy: []
  timestamp: '2026-05-31 16:42:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/maxmin_patrition.hpp
layout: document
redirect_from:
- /library/setfunc/maxmin_patrition.hpp
- /library/setfunc/maxmin_patrition.hpp.html
title: setfunc/maxmin_patrition.hpp
---
