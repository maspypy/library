---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/count_unbordered_string.test.cpp
    title: test/1_mytest/count_unbordered_string.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://oeis.org/A003000
  bundledCode: "#line 1 \"string/count_unborderd_string.hpp\"\n\n// O(N) time\n//\
    \ https://oeis.org/A003000\ntemplate <typename mint>\nvc<mint> count_unbordered_string(int\
    \ N, int sigma) {\n  // \u5168\u4F53\u304B\u3089 border \u3092\u6301\u3064\u3082\
    \u306E\u3092\u5F15\u304F, minimum border = unbordered\n  // vc<mint> dp(N + 1);\n\
    \  // FOR(n, N + 1) {\n  //   dp[n] = mint(sigma).pow(n);\n  //   FOR(i, 1, n\
    \ / 2 + 1) dp[n] -= dp[i] * mint(sigma).pow(n - 2 * i);\n  // }\n  // \u3053\u308C\
    \u3092 O(N) \u306B\n\n  vc<mint> dp(N + 1);\n  dp[0] = 1;\n  FOR(n, 1, N + 1)\
    \ {\n    if (n % 2 == 0) dp[n] = mint(sigma) * dp[n - 1] - dp[n / 2];\n    if\
    \ (n % 2 == 1) dp[n] = mint(sigma) * dp[n - 1];\n  }\n  return dp;\n}\n"
  code: "\n// O(N) time\n// https://oeis.org/A003000\ntemplate <typename mint>\nvc<mint>\
    \ count_unbordered_string(int N, int sigma) {\n  // \u5168\u4F53\u304B\u3089 border\
    \ \u3092\u6301\u3064\u3082\u306E\u3092\u5F15\u304F, minimum border = unbordered\n\
    \  // vc<mint> dp(N + 1);\n  // FOR(n, N + 1) {\n  //   dp[n] = mint(sigma).pow(n);\n\
    \  //   FOR(i, 1, n / 2 + 1) dp[n] -= dp[i] * mint(sigma).pow(n - 2 * i);\n  //\
    \ }\n  // \u3053\u308C\u3092 O(N) \u306B\n\n  vc<mint> dp(N + 1);\n  dp[0] = 1;\n\
    \  FOR(n, 1, N + 1) {\n    if (n % 2 == 0) dp[n] = mint(sigma) * dp[n - 1] - dp[n\
    \ / 2];\n    if (n % 2 == 1) dp[n] = mint(sigma) * dp[n - 1];\n  }\n  return dp;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: string/count_unborderd_string.hpp
  requiredBy: []
  timestamp: '2024-08-18 02:41:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/count_unbordered_string.test.cpp
documentation_of: string/count_unborderd_string.hpp
layout: document
redirect_from:
- /library/string/count_unborderd_string.hpp
- /library/string/count_unborderd_string.hpp.html
title: string/count_unborderd_string.hpp
---
