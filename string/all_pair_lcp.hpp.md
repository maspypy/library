---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/abc141e.test.cpp
    title: test_atcoder/abc141e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/all_pair_lcp.hpp\"\n// dp[i][j] = lcp(S[i:], T[j:])\n\
    vvc<int> all_pair_lcp(string& S, string& T) {\n  int N = len(S), M = len(T);\n\
    \  vv(int, dp, N, M);\n  FOR_R(i, N) FOR_R(j, M) {\n    if (S[i] != T[j]) continue;\n\
    \    dp[i][j] = 1 + (i + 1 < N && j + 1 < M ? dp[i + 1][j + 1] : 0);\n  }\n  return\
    \ dp;\n}\n"
  code: "// dp[i][j] = lcp(S[i:], T[j:])\nvvc<int> all_pair_lcp(string& S, string&\
    \ T) {\n  int N = len(S), M = len(T);\n  vv(int, dp, N, M);\n  FOR_R(i, N) FOR_R(j,\
    \ M) {\n    if (S[i] != T[j]) continue;\n    dp[i][j] = 1 + (i + 1 < N && j +\
    \ 1 < M ? dp[i + 1][j + 1] : 0);\n  }\n  return dp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/all_pair_lcp.hpp
  requiredBy: []
  timestamp: '2023-02-16 20:27:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc141e.test.cpp
documentation_of: string/all_pair_lcp.hpp
layout: document
redirect_from:
- /library/string/all_pair_lcp.hpp
- /library/string/all_pair_lcp.hpp.html
title: string/all_pair_lcp.hpp
---
