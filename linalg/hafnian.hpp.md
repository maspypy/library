---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/matrix/hafnian_of_matrix.test.cpp
    title: test/library_checker/matrix/hafnian_of_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/hafnian.hpp\"\n// \u96A3\u63A5\u884C\u5217\u306B\u5BFE\
    \u3057\u3066\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u6570\u3048\u308B\
    \u3002\r\ntemplate <typename mint, int LIM = 20>\r\nmint Hufnian(vc<vc<mint>>&\
    \ B0) {\r\n  int N = len(B[0]);\r\n  int n = N / 2;\r\n  assert(n <= LIM);\r\n\
    \  vc<mint> cyc(1 << n);\r\n\r\n  FOR(i, N / 2) {\r\n    int A = 2 * i + 0, B\
    \ = 2 * i + 1;\r\n    int K = 2 * i;\r\n    cyc[1 << i] += mat[A][B];\r\n    vc<mint>\
    \ dp(K << i);\r\n    for (int j = 0; j < i; ++j) {\r\n      int j0 = 2 * j + 0,\
    \ j1 = 2 * j + 1;\r\n      dp[(K << j) + j0] += mat[A][j1], dp[(K << j) + j1]\
    \ += mat[A][j0];\r\n    }\r\n    for (int s = 0; s < (1 << i); ++s) {\r\n    \
    \  for (int j = 0; j < i; ++j) {\r\n        int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\
    \n        cyc[s | 1 << i] += dp[K * s + j0] * mat[B][j0];\r\n        cyc[s | 1\
    \ << i] += dp[K * s + j1] * mat[B][j1];\r\n        enumerate_bits_32((1 << i)\
    \ - 1 - s, [&](int k) -> void {\r\n          int k0 = 2 * k + 0, k1 = 2 * k +\
    \ 1;\r\n          int t = s | 1 << k;\r\n          dp[K * t + k0] += dp[K * s\
    \ + j0] * mat[j0][k1];\r\n          dp[K * t + k0] += dp[K * s + j1] * mat[j1][k1];\r\
    \n          dp[K * t + k1] += dp[K * s + j0] * mat[j0][k0];\r\n          dp[K\
    \ * t + k1] += dp[K * s + j1] * mat[j1][k0];\r\n        });\r\n      }\r\n   \
    \ }\r\n  }\r\n  return sps_exp<mint, LIM>(n, cyc).back();\r\n}\r\n"
  code: "// \u96A3\u63A5\u884C\u5217\u306B\u5BFE\u3057\u3066\u5B8C\u5168\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u3092\u6570\u3048\u308B\u3002\r\ntemplate <typename mint, int\
    \ LIM = 20>\r\nmint Hufnian(vc<vc<mint>>& B0) {\r\n  int N = len(B[0]);\r\n  int\
    \ n = N / 2;\r\n  assert(n <= LIM);\r\n  vc<mint> cyc(1 << n);\r\n\r\n  FOR(i,\
    \ N / 2) {\r\n    int A = 2 * i + 0, B = 2 * i + 1;\r\n    int K = 2 * i;\r\n\
    \    cyc[1 << i] += mat[A][B];\r\n    vc<mint> dp(K << i);\r\n    for (int j =\
    \ 0; j < i; ++j) {\r\n      int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n      dp[(K\
    \ << j) + j0] += mat[A][j1], dp[(K << j) + j1] += mat[A][j0];\r\n    }\r\n   \
    \ for (int s = 0; s < (1 << i); ++s) {\r\n      for (int j = 0; j < i; ++j) {\r\
    \n        int j0 = 2 * j + 0, j1 = 2 * j + 1;\r\n        cyc[s | 1 << i] += dp[K\
    \ * s + j0] * mat[B][j0];\r\n        cyc[s | 1 << i] += dp[K * s + j1] * mat[B][j1];\r\
    \n        enumerate_bits_32((1 << i) - 1 - s, [&](int k) -> void {\r\n       \
    \   int k0 = 2 * k + 0, k1 = 2 * k + 1;\r\n          int t = s | 1 << k;\r\n \
    \         dp[K * t + k0] += dp[K * s + j0] * mat[j0][k1];\r\n          dp[K *\
    \ t + k0] += dp[K * s + j1] * mat[j1][k1];\r\n          dp[K * t + k1] += dp[K\
    \ * s + j0] * mat[j0][k0];\r\n          dp[K * t + k1] += dp[K * s + j1] * mat[j1][k0];\r\
    \n        });\r\n      }\r\n    }\r\n  }\r\n  return sps_exp<mint, LIM>(n, cyc).back();\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/hafnian.hpp
  requiredBy: []
  timestamp: '2023-05-04 20:25:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix/hafnian_of_matrix.test.cpp
documentation_of: linalg/hafnian.hpp
layout: document
redirect_from:
- /library/linalg/hafnian.hpp
- /library/linalg/hafnian.hpp.html
title: linalg/hafnian.hpp
---
