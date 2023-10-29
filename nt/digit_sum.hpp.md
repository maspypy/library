---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/digit_sum.test.cpp
    title: test/mytest/digit_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/digit_sum.hpp\"\nint digit_sum(u64 x) {\n  const int\
    \ K = 100'000;\n  static vc<int> dp(K);\n  if (dp[1] == 0) { FOR(x, 1, K) dp[x]\
    \ = dp[x / 10] + (x % 10); }\n  int res = 0;\n  while (x) {\n    res += dp[x %\
    \ K];\n    x /= K;\n  }\n  return res;\n}\n"
  code: "int digit_sum(u64 x) {\n  const int K = 100'000;\n  static vc<int> dp(K);\n\
    \  if (dp[1] == 0) { FOR(x, 1, K) dp[x] = dp[x / 10] + (x % 10); }\n  int res\
    \ = 0;\n  while (x) {\n    res += dp[x % K];\n    x /= K;\n  }\n  return res;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: nt/digit_sum.hpp
  requiredBy: []
  timestamp: '2023-03-02 23:02:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/digit_sum.test.cpp
documentation_of: nt/digit_sum.hpp
layout: document
redirect_from:
- /library/nt/digit_sum.hpp
- /library/nt/digit_sum.hpp.html
title: nt/digit_sum.hpp
---
