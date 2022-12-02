---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_D.test.cpp
    title: test/aoj/DPL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/longest_increasing_subsequence.test.cpp
    title: test/library_checker/math/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/longest_increasing_subsequence.hpp\"\n/*\ndp[i] := \u7B2C\
    \ i \u9805\u3067\u7D42\u308F\u308B lis \u9577\u306E\u6700\u5927\u5024\n\u3068\u306A\
    \u308B dp \u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\u3059\u3002O(Nlog N) \u6642\u9593\
    \u3002\n\u72ED\u7FA9\u30FB\u5E83\u7FA9\u306F\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\
    \u3067\u6307\u5B9A\u3002\u30C7\u30D5\u30A9\u30EB\u30C8\u306F strong\n*/\ntemplate\
    \ <typename T, bool strong = true>\nvc<int> longest_increasing_subsequence(vector<T>\
    \ A) {\n  ll N = A.size();\n\n  T INF = numeric_limits<T>::max();\n  vc<T> dp(N,\
    \ INF);\n  vc<int> lis_rank(N);\n  FOR(i, N) {\n    int j = (strong ? LB(dp, A[i])\
    \ : UB(dp, A[i]));\n    dp[j] = A[i];\n    lis_rank[i] = j + 1;\n  }\n  return\
    \ lis_rank;\n}\n"
  code: "/*\ndp[i] := \u7B2C i \u9805\u3067\u7D42\u308F\u308B lis \u9577\u306E\u6700\
    \u5927\u5024\n\u3068\u306A\u308B dp \u30C6\u30FC\u30D6\u30EB\u3092\u8FD4\u3059\
    \u3002O(Nlog N) \u6642\u9593\u3002\n\u72ED\u7FA9\u30FB\u5E83\u7FA9\u306F\u30C6\
    \u30F3\u30D7\u30EC\u30FC\u30C8\u3067\u6307\u5B9A\u3002\u30C7\u30D5\u30A9\u30EB\
    \u30C8\u306F strong\n*/\ntemplate <typename T, bool strong = true>\nvc<int> longest_increasing_subsequence(vector<T>\
    \ A) {\n  ll N = A.size();\n\n  T INF = numeric_limits<T>::max();\n  vc<T> dp(N,\
    \ INF);\n  vc<int> lis_rank(N);\n  FOR(i, N) {\n    int j = (strong ? LB(dp, A[i])\
    \ : UB(dp, A[i]));\n    dp[j] = A[i];\n    lis_rank[i] = j + 1;\n  }\n  return\
    \ lis_rank;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:59:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/math/longest_increasing_subsequence.test.cpp
  - test/aoj/DPL_1_D.test.cpp
documentation_of: seq/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/seq/longest_increasing_subsequence.hpp
- /library/seq/longest_increasing_subsequence.hpp.html
title: seq/longest_increasing_subsequence.hpp
---
