---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/partition.hpp\"\n// n \u3092 k \u500B\u306B\u5206\u5272\
    \u3059\u308B\u65B9\u6CD5 P[n][k] \u306E\u30C6\u30FC\u30D6\u30EB\r\ntemplate <typename\
    \ T>\r\nvvc<T> partition_number_2d(int n_max, int k_max) {\r\n  vv(T, dp, n_max\
    \ + 1, k_max + 1);\r\n  dp[0][0] = 1;\r\n  FOR3(n, 1, n_max + 1) FOR3(k, 1, k_max\
    \ + 1) {\r\n    // min = 1\r\n    dp[n][k] += dp[n - 1][k - 1];\r\n    // min\
    \ >= 2\r\n    if (n >= k) dp[n][k] += dp[n - k][k];\r\n  }\r\n  return dp;\r\n\
    }\r\n"
  code: "// n \u3092 k \u500B\u306B\u5206\u5272\u3059\u308B\u65B9\u6CD5 P[n][k] \u306E\
    \u30C6\u30FC\u30D6\u30EB\r\ntemplate <typename T>\r\nvvc<T> partition_number_2d(int\
    \ n_max, int k_max) {\r\n  vv(T, dp, n_max + 1, k_max + 1);\r\n  dp[0][0] = 1;\r\
    \n  FOR3(n, 1, n_max + 1) FOR3(k, 1, k_max + 1) {\r\n    // min = 1\r\n    dp[n][k]\
    \ += dp[n - 1][k - 1];\r\n    // min >= 2\r\n    if (n >= k) dp[n][k] += dp[n\
    \ - k][k];\r\n  }\r\n  return dp;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/partition.hpp
  requiredBy: []
  timestamp: '2022-04-16 22:55:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/partition.hpp
layout: document
redirect_from:
- /library/seq/partition.hpp
- /library/seq/partition.hpp.html
title: seq/partition.hpp
---
