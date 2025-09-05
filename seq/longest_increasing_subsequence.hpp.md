---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/other/longest_increasing_subsequence.test.cpp
    title: test/2_library_checker/other/longest_increasing_subsequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2230.test.cpp
    title: test/3_yukicoder/2230.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DPL_1_D.test.cpp
    title: test/4_aoj/DPL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/longest_increasing_subsequence.hpp\"\n// dp[i] := \u7B2C\
    \ i \u9805\u3067\u7D42\u308F\u308B lis \u9577\u306E\u6700\u5927\u5024\uFF08[1,\
    \ LIS]\uFF09\ntemplate <typename T, bool strong = true>\npair<int, vc<int>> longest_increasing_subsequence_dp(vector<T>\
    \ A) {\n  const int N = A.size();\n  vc<T> dp(N, infty<T>);\n  int lis = 0;\n\
    \  vc<int> lis_rank(N);\n  FOR(i, N) {\n    int j = (strong ? LB(dp, A[i]) : UB(dp,\
    \ A[i]));\n    dp[j] = A[i];\n    lis_rank[i] = j + 1;\n    chmax(lis, j + 1);\n\
    \  }\n  return {lis, lis_rank};\n}\n\ntemplate <typename T, bool strong = true>\n\
    vc<int> longest_increasing_subsequence(vector<T> A) {\n  const int N = A.size();\n\
    \  auto [lis, dp] = longest_increasing_subsequence_dp<T, strong>(A);\n  vc<int>\
    \ I;\n  FOR(i, N) if (dp[i] == lis) {\n    I.eb(i);\n    break;\n  }\n  FOR(lis\
    \ - 1) {\n    int i = I.back();\n    FOR_R(j, i) {\n      bool ok = (dp[j] ==\
    \ dp[i] - 1) && (strong ? (A[j] < A[i]) : (A[j] <= A[i]));\n      if (ok) {\n\
    \        I.eb(j);\n        break;\n      }\n    }\n  }\n  assert(len(I) == lis);\n\
    \  reverse(all(I));\n  return I;\n}\n"
  code: "// dp[i] := \u7B2C i \u9805\u3067\u7D42\u308F\u308B lis \u9577\u306E\u6700\
    \u5927\u5024\uFF08[1, LIS]\uFF09\ntemplate <typename T, bool strong = true>\n\
    pair<int, vc<int>> longest_increasing_subsequence_dp(vector<T> A) {\n  const int\
    \ N = A.size();\n  vc<T> dp(N, infty<T>);\n  int lis = 0;\n  vc<int> lis_rank(N);\n\
    \  FOR(i, N) {\n    int j = (strong ? LB(dp, A[i]) : UB(dp, A[i]));\n    dp[j]\
    \ = A[i];\n    lis_rank[i] = j + 1;\n    chmax(lis, j + 1);\n  }\n  return {lis,\
    \ lis_rank};\n}\n\ntemplate <typename T, bool strong = true>\nvc<int> longest_increasing_subsequence(vector<T>\
    \ A) {\n  const int N = A.size();\n  auto [lis, dp] = longest_increasing_subsequence_dp<T,\
    \ strong>(A);\n  vc<int> I;\n  FOR(i, N) if (dp[i] == lis) {\n    I.eb(i);\n \
    \   break;\n  }\n  FOR(lis - 1) {\n    int i = I.back();\n    FOR_R(j, i) {\n\
    \      bool ok = (dp[j] == dp[i] - 1) && (strong ? (A[j] < A[i]) : (A[j] <= A[i]));\n\
    \      if (ok) {\n        I.eb(j);\n        break;\n      }\n    }\n  }\n  assert(len(I)\
    \ == lis);\n  reverse(all(I));\n  return I;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/longest_increasing_subsequence.hpp
  requiredBy: []
  timestamp: '2024-10-23 21:57:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2230.test.cpp
  - test/2_library_checker/other/longest_increasing_subsequence.test.cpp
  - test/4_aoj/DPL_1_D.test.cpp
documentation_of: seq/longest_increasing_subsequence.hpp
layout: document
redirect_from:
- /library/seq/longest_increasing_subsequence.hpp
- /library/seq/longest_increasing_subsequence.hpp.html
title: seq/longest_increasing_subsequence.hpp
---
