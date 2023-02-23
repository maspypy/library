---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_1_D.test.cpp
    title: test/aoj/DPL_1_D.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/longest_increasing_subsequence.test.cpp
    title: test/library_checker/math/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/longest_increasing_subsequence.hpp\"\n// dp[i] := \u7B2C\
    \ i \u9805\u3067\u7D42\u308F\u308B lis \u9577\u306E\u6700\u5927\u5024\uFF08[1,\
    \ LIS]\uFF09\ntemplate <typename T, bool strong = true>\nvc<int> longest_increasing_subsequence(vector<T>\
    \ A) {\n  const int N = A.size();\n  vc<T> dp(N, infty<T>);\n  vc<int> lis_rank(N);\n\
    \  FOR(i, N) {\n    int j = (strong ? LB(dp, A[i]) : UB(dp, A[i]));\n    dp[j]\
    \ = A[i];\n    lis_rank[i] = j + 1;\n  }\n  return lis_rank;\n}\n"
  code: "// dp[i] := \u7B2C i \u9805\u3067\u7D42\u308F\u308B lis \u9577\u306E\u6700\
    \u5927\u5024\uFF08[1, LIS]\uFF09\ntemplate <typename T, bool strong = true>\n\
    vc<int> longest_increasing_subsequence(vector<T> A) {\n  const int N = A.size();\n\
    \  vc<T> dp(N, infty<T>);\n  vc<int> lis_rank(N);\n  FOR(i, N) {\n    int j =\
    \ (strong ? LB(dp, A[i]) : UB(dp, A[i]));\n    dp[j] = A[i];\n    lis_rank[i]\
    \ = j + 1;\n  }\n  return lis_rank;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
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
