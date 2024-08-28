---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/sigma_0_sum.test.cpp
    title: test/1_mytest/sigma_0_sum.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc230e.test.cpp
    title: test/5_atcoder/abc230e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://oeis.org/A006218
  bundledCode: "#line 1 \"nt/sigma_0_sum.hpp\"\n// sum_[1,N] sigma_0(n)\ntemplate\
    \ <typename T = u64>\nT sigma_0_sum_small(u64 N) {\n  u32 sq = sqrtl(N);\n  T\
    \ ANS = 0;\n  for (u32 d = 1; d <= sq; ++d) { ANS += N / d; }\n  return 2 * ANS\
    \ - u64(sq) * sq;\n}\n\n// https://oeis.org/A006218\n// sigma0(1)+...+sigma0(N)\
    \ = sum floor(N/i)\ntemplate <typename T = u64>\nT sigma_0_sum_large(u64 N) {\n\
    \  u32 sq = sqrtl(N);\n  auto above = [&](u128 x, u128 y) -> bool { return y *\
    \ (sq - x) > N; };\n  auto slope = [&](u128 x, u128 a, u128 b) -> bool {\n   \
    \ x = sq - x;\n    return a * x * x <= N * b;\n  };\n  T ANS = convex_floor_sum<u64,\
    \ T>(sq, above, slope);\n  return 2 * ANS - u64(sq) * sq;\n}\n\ntemplate <typename\
    \ T = u64>\nT sigma_0_sum(u64 N) {\n  return (N < (1e14) ? sigma_0_sum_small<T>(N)\
    \ : sigma_0_sum_large<T>(N));\n}\n"
  code: "// sum_[1,N] sigma_0(n)\ntemplate <typename T = u64>\nT sigma_0_sum_small(u64\
    \ N) {\n  u32 sq = sqrtl(N);\n  T ANS = 0;\n  for (u32 d = 1; d <= sq; ++d) {\
    \ ANS += N / d; }\n  return 2 * ANS - u64(sq) * sq;\n}\n\n// https://oeis.org/A006218\n\
    // sigma0(1)+...+sigma0(N) = sum floor(N/i)\ntemplate <typename T = u64>\nT sigma_0_sum_large(u64\
    \ N) {\n  u32 sq = sqrtl(N);\n  auto above = [&](u128 x, u128 y) -> bool { return\
    \ y * (sq - x) > N; };\n  auto slope = [&](u128 x, u128 a, u128 b) -> bool {\n\
    \    x = sq - x;\n    return a * x * x <= N * b;\n  };\n  T ANS = convex_floor_sum<u64,\
    \ T>(sq, above, slope);\n  return 2 * ANS - u64(sq) * sq;\n}\n\ntemplate <typename\
    \ T = u64>\nT sigma_0_sum(u64 N) {\n  return (N < (1e14) ? sigma_0_sum_small<T>(N)\
    \ : sigma_0_sum_large<T>(N));\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/sigma_0_sum.hpp
  requiredBy: []
  timestamp: '2024-08-28 10:30:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/5_atcoder/abc230e.test.cpp
  - test/1_mytest/sigma_0_sum.test.cpp
documentation_of: nt/sigma_0_sum.hpp
layout: document
redirect_from:
- /library/nt/sigma_0_sum.hpp
- /library/nt/sigma_0_sum.hpp.html
title: nt/sigma_0_sum.hpp
---
