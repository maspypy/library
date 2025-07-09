---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: bigint/base.hpp
    title: bigint/base.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/bigint.test.cpp
    title: test/1_mytest/bigint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/digit_sum.test.cpp
    title: test/1_mytest/digit_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/big_integer/addition_of_bigintegers.test.cpp
    title: test/2_library_checker/big_integer/addition_of_bigintegers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/big_integer/multiplication_of_bigintegers.test.cpp
    title: test/2_library_checker/big_integer/multiplication_of_bigintegers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/sample/aplusb128.test.cpp
    title: test/2_library_checker/sample/aplusb128.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2440.test.cpp
    title: test/3_yukicoder/2440.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2508.test.cpp
    title: test/3_yukicoder/2508.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2525.test.cpp
    title: test/3_yukicoder/2525.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2580.test.cpp
    title: test/3_yukicoder/2580.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2595.test.cpp
    title: test/3_yukicoder/2595.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2649.test.cpp
    title: test/3_yukicoder/2649.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/303.test.cpp
    title: test/3_yukicoder/303.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/NTL_2_A.test.cpp
    title: test/4_aoj/NTL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/NTL_2_B.test.cpp
    title: test/4_aoj/NTL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/NTL_2_C.test.cpp
    title: test/4_aoj/NTL_2_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/bigint.test.cpp
  - test/1_mytest/digit_sum.test.cpp
  - test/4_aoj/NTL_2_A.test.cpp
  - test/4_aoj/NTL_2_C.test.cpp
  - test/4_aoj/NTL_2_B.test.cpp
  - test/2_library_checker/big_integer/addition_of_bigintegers.test.cpp
  - test/2_library_checker/big_integer/multiplication_of_bigintegers.test.cpp
  - test/2_library_checker/sample/aplusb128.test.cpp
  - test/3_yukicoder/2525.test.cpp
  - test/3_yukicoder/2508.test.cpp
  - test/3_yukicoder/2649.test.cpp
  - test/3_yukicoder/303.test.cpp
  - test/3_yukicoder/2595.test.cpp
  - test/3_yukicoder/2440.test.cpp
  - test/3_yukicoder/2580.test.cpp
documentation_of: nt/digit_sum.hpp
layout: document
redirect_from:
- /library/nt/digit_sum.hpp
- /library/nt/digit_sum.hpp.html
title: nt/digit_sum.hpp
---
