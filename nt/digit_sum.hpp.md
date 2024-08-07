---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: bigint/base.hpp
    title: bigint/base.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_A.test.cpp
    title: test/aoj/NTL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_B.test.cpp
    title: test/aoj/NTL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_2_C.test.cpp
    title: test/aoj/NTL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/bigint/addition_of_bigintegers.test.cpp
    title: test/library_checker/bigint/addition_of_bigintegers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/bigint/multiplication_of_bigintegers.test.cpp
    title: test/library_checker/bigint/multiplication_of_bigintegers.test.cpp
  - icon: ':x:'
    path: test/library_checker/sample/aplusb128.test.cpp
    title: test/library_checker/sample/aplusb128.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/bigint.test.cpp
    title: test/mytest/bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/digit_sum.test.cpp
    title: test/mytest/digit_sum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2440.test.cpp
    title: test/yukicoder/2440.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2508.test.cpp
    title: test/yukicoder/2508.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2525.test.cpp
    title: test/yukicoder/2525.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2580.test.cpp
    title: test/yukicoder/2580.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2649.test.cpp
    title: test/yukicoder/2649.test.cpp
  - icon: ':x:'
    path: test/yukicoder/303.test.cpp
    title: test/yukicoder/303.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc339f.test.cpp
    title: test_atcoder/abc339f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/digit_sum.hpp\"\n\nint digit_sum(u64 x) {\n  const int\
    \ K = 100'000;\n  static vc<int> dp(K);\n  if (dp[1] == 0) { FOR(x, 1, K) dp[x]\
    \ = dp[x / 10] + (x % 10); }\n  int res = 0;\n  while (x) {\n    res += dp[x %\
    \ K];\n    x /= K;\n  }\n  return res;\n}\n"
  code: "#pragma once\n\nint digit_sum(u64 x) {\n  const int K = 100'000;\n  static\
    \ vc<int> dp(K);\n  if (dp[1] == 0) { FOR(x, 1, K) dp[x] = dp[x / 10] + (x % 10);\
    \ }\n  int res = 0;\n  while (x) {\n    res += dp[x % K];\n    x /= K;\n  }\n\
    \  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: nt/digit_sum.hpp
  requiredBy:
  - bigint/base.hpp
  timestamp: '2024-06-06 03:38:35+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/303.test.cpp
  - test/yukicoder/2440.test.cpp
  - test/yukicoder/2580.test.cpp
  - test/yukicoder/2649.test.cpp
  - test/yukicoder/2525.test.cpp
  - test/yukicoder/2508.test.cpp
  - test/mytest/bigint.test.cpp
  - test/mytest/digit_sum.test.cpp
  - test/aoj/NTL_2_C.test.cpp
  - test/aoj/NTL_2_B.test.cpp
  - test/aoj/NTL_2_A.test.cpp
  - test/library_checker/bigint/addition_of_bigintegers.test.cpp
  - test/library_checker/bigint/multiplication_of_bigintegers.test.cpp
  - test/library_checker/sample/aplusb128.test.cpp
  - test_atcoder/abc339f.test.cpp
documentation_of: nt/digit_sum.hpp
layout: document
redirect_from:
- /library/nt/digit_sum.hpp
- /library/nt/digit_sum.hpp.html
title: nt/digit_sum.hpp
---
