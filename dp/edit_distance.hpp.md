---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1818.test.cpp
    title: test/yukicoder/1818.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/edit_distance.hpp\"\ntemplate <typename STRING>\nint\
    \ edit_distance(STRING& S, STRING& T) {\n  int N = len(S), M = len(T);\n  vc<int>\
    \ dp(M + 1, 1 << 30);\n  dp[0] = 0;\n  FOR(i, N + 1) {\n    vc<int> newdp(M +\
    \ 1, 1 << 30);\n    FOR(j, M + 1) {\n      if (i < N) chmin(newdp[j], dp[j] +\
    \ 1);\n      if (j < M) chmin(dp[j + 1], dp[j] + 1);\n      if (i < N && j < M)\
    \ chmin(newdp[j + 1], dp[j] + 1);\n      if (i < N && j < M && S[i] == T[j]) chmin(newdp[j\
    \ + 1], dp[j]);\n    }\n    if (i < N) swap(dp, newdp);\n  }\n  return dp[M];\n\
    }\n"
  code: "template <typename STRING>\nint edit_distance(STRING& S, STRING& T) {\n \
    \ int N = len(S), M = len(T);\n  vc<int> dp(M + 1, 1 << 30);\n  dp[0] = 0;\n \
    \ FOR(i, N + 1) {\n    vc<int> newdp(M + 1, 1 << 30);\n    FOR(j, M + 1) {\n \
    \     if (i < N) chmin(newdp[j], dp[j] + 1);\n      if (j < M) chmin(dp[j + 1],\
    \ dp[j] + 1);\n      if (i < N && j < M) chmin(newdp[j + 1], dp[j] + 1);\n   \
    \   if (i < N && j < M && S[i] == T[j]) chmin(newdp[j + 1], dp[j]);\n    }\n \
    \   if (i < N) swap(dp, newdp);\n  }\n  return dp[M];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/edit_distance.hpp
  requiredBy: []
  timestamp: '2022-10-01 12:16:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1818.test.cpp
documentation_of: dp/edit_distance.hpp
layout: document
redirect_from:
- /library/dp/edit_distance.hpp
- /library/dp/edit_distance.hpp.html
title: dp/edit_distance.hpp
---
