---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/ALDS1_10_C.test.cpp
    title: test/aoj/ALDS1_10_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/longest_common_subsequence.hpp\"\n\ntemplate <typename\
    \ STRING>\nll longest_common_subsequence(STRING& A, STRING& B) {\n  int N = len(B);\n\
    \  vc<int> dp(N + 1);\n  for (auto&& a: A) {\n    FOR_R(i, N) if (a == B[i]) chmax(dp[i\
    \ + 1], dp[i] + 1);\n    FOR(i, N) chmax(dp[i + 1], dp[i]);\n  }\n  return dp[N];\n\
    }\n\n/*\n\u5FA9\u5143\u3082\u3059\u308B LCS dp\u3002\n(A[i], B[j]) \u3092\u4F7F\
    \u3046\u3088\u3046\u306A (i, j) \u306E\u30DA\u30A2\u306E vector \u3092\u8FD4\u3059\
    \u3002\n*/\ntemplate <typename STRING>\nvc<pair<int, int>> longest_common_subsequence_restore(STRING&\
    \ A, STRING& B) {\n  int N = len(A), M = len(B);\n  vv(int, DP, N + 1, M + 1);\n\
    \  FOR(i, N) {\n    auto& dp = DP[i];\n    auto& newdp = DP[i + 1];\n    newdp\
    \ = dp;\n    FOR(j, M) {\n      chmax(newdp[j + 1], newdp[j]);\n      if (A[i]\
    \ == B[j]) chmax(newdp[j + 1], dp[j] + 1);\n    }\n  }\n  vc<pair<int, int>> res;\n\
    \  int n = N, m = M;\n  while (DP[n][m]) {\n    if (DP[n][m] == DP[n - 1][m])\
    \ { --n; }\n    elif (DP[n][m] == DP[n][m - 1]) { --m; }\n    else {\n      --n,\
    \ --m;\n      res.eb(n, m);\n    }\n  }\n  reverse(all(res));\n  return res;\n\
    }\n"
  code: "\ntemplate <typename STRING>\nll longest_common_subsequence(STRING& A, STRING&\
    \ B) {\n  int N = len(B);\n  vc<int> dp(N + 1);\n  for (auto&& a: A) {\n    FOR_R(i,\
    \ N) if (a == B[i]) chmax(dp[i + 1], dp[i] + 1);\n    FOR(i, N) chmax(dp[i + 1],\
    \ dp[i]);\n  }\n  return dp[N];\n}\n\n/*\n\u5FA9\u5143\u3082\u3059\u308B LCS dp\u3002\
    \n(A[i], B[j]) \u3092\u4F7F\u3046\u3088\u3046\u306A (i, j) \u306E\u30DA\u30A2\u306E\
    \ vector \u3092\u8FD4\u3059\u3002\n*/\ntemplate <typename STRING>\nvc<pair<int,\
    \ int>> longest_common_subsequence_restore(STRING& A, STRING& B) {\n  int N =\
    \ len(A), M = len(B);\n  vv(int, DP, N + 1, M + 1);\n  FOR(i, N) {\n    auto&\
    \ dp = DP[i];\n    auto& newdp = DP[i + 1];\n    newdp = dp;\n    FOR(j, M) {\n\
    \      chmax(newdp[j + 1], newdp[j]);\n      if (A[i] == B[j]) chmax(newdp[j +\
    \ 1], dp[j] + 1);\n    }\n  }\n  vc<pair<int, int>> res;\n  int n = N, m = M;\n\
    \  while (DP[n][m]) {\n    if (DP[n][m] == DP[n - 1][m]) { --n; }\n    elif (DP[n][m]\
    \ == DP[n][m - 1]) { --m; }\n    else {\n      --n, --m;\n      res.eb(n, m);\n\
    \    }\n  }\n  reverse(all(res));\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: string/longest_common_subsequence.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/ALDS1_10_C.test.cpp
documentation_of: string/longest_common_subsequence.hpp
layout: document
redirect_from:
- /library/string/longest_common_subsequence.hpp
- /library/string/longest_common_subsequence.hpp.html
title: string/longest_common_subsequence.hpp
---
