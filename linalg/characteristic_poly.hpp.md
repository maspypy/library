---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: linalg/det_A_plus_xB.hpp
    title: linalg/det_A_plus_xB.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/charactereistic_poly.test.cpp
    title: test/library_checker/matrix/charactereistic_poly.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/characteristic_poly.hpp\"\ntemplate <typename T>\r\
    \nvoid to_Hessenberg_matrix(vc<vc<T>>& A) {\r\n  /*\r\n  P^{-1}AP \u306E\u5F62\
    \u306E\u5909\u63DB\u3067\u3001Hessenberg \u884C\u5217\u306B\u5909\u5F62\u3059\u308B\
    \u3002\r\n  \u7279\u5B9A\u591A\u9805\u5F0F\u306E\u8A08\u7B97\u306B\u7528\u3044\
    \u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\r\n  */\r\n  int n = len(A);\r\
    \n  FOR(k, n - 2) {\r\n    FOR3(i, k + 1, n) if (A[i][k] != 0) {\r\n      if (i\
    \ != k + 1) {\r\n        swap(A[i], A[k + 1]);\r\n        FOR(j, n) swap(A[j][i],\
    \ A[j][k + 1]);\r\n      }\r\n      break;\r\n    }\r\n    if (A[k + 1][k] ==\
    \ 0) continue;\r\n    FOR3(i, k + 2, n) {\r\n      T c = A[i][k] / A[k + 1][k];\r\
    \n      // i \u884C\u76EE -= k+1 \u884C\u76EE * c\r\n      FOR(j, n) A[i][j] -=\
    \ A[k + 1][j] * c;\r\n      // k+1 \u5217\u76EE += i \u5217\u76EE * c\r\n    \
    \  FOR(j, n) A[j][k + 1] += A[j][i] * c;\r\n    }\r\n  }\r\n}\r\n\r\n// det(xI-A)\r\
    \ntemplate <typename T>\r\nvc<T> characteristic_poly(vc<vc<T>> A) {\r\n  /*\r\n\
    \  \u30FBHessenberg \u884C\u5217\u306B\u5909\u5F62\r\n  \u30FBHessenberg \u884C\
    \u5217\u306E\u884C\u5217\u5F0F\u306F\u3001\u6700\u5F8C\u306E\u5217\u3067\u5834\
    \u5408\u5206\u3051\u3059\u308C\u3070 dp \u3067\u304D\u308B\r\n  */\r\n  int n\
    \ = len(A);\r\n  to_Hessenberg_matrix(A);\r\n  vc<vc<T>> DP(n + 1);\r\n  DP[0]\
    \ = {1};\r\n  FOR(k, n) {\r\n    DP[k + 1].resize(k + 2);\r\n    auto& dp = DP[k\
    \ + 1];\r\n    // (k, k) \u6210\u5206\u3092\u4F7F\u3046\u5834\u5408\r\n    FOR(i,\
    \ len(DP[k])) dp[i + 1] += DP[k][i];\r\n    FOR(i, len(DP[k])) dp[i] -= DP[k][i]\
    \ * A[k][k];\r\n    // \u4E0B\u5074\u5BFE\u89D2\u306E\u7DCF\u7A4D\u3092\u7BA1\u7406\
    \r\n    T prod = 1;\r\n    FOR_R(i, k) {\r\n      // (i, k) \u6210\u5206\u3092\
    \u4F7F\u3046\u5834\u5408\r\n      prod *= A[i + 1][i];\r\n      T c = prod * A[i][k];\r\
    \n      // DP[i] \u306E c \u500D\u3092\u52A0\u7B97\r\n      FOR(j, len(DP[i]))\
    \ dp[j] -= DP[i][j] * c;\r\n    }\r\n  }\r\n  return DP[n];\r\n}\r\n"
  code: "template <typename T>\r\nvoid to_Hessenberg_matrix(vc<vc<T>>& A) {\r\n  /*\r\
    \n  P^{-1}AP \u306E\u5F62\u306E\u5909\u63DB\u3067\u3001Hessenberg \u884C\u5217\
    \u306B\u5909\u5F62\u3059\u308B\u3002\r\n  \u7279\u5B9A\u591A\u9805\u5F0F\u306E\
    \u8A08\u7B97\u306B\u7528\u3044\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\
    \r\n  */\r\n  int n = len(A);\r\n  FOR(k, n - 2) {\r\n    FOR3(i, k + 1, n) if\
    \ (A[i][k] != 0) {\r\n      if (i != k + 1) {\r\n        swap(A[i], A[k + 1]);\r\
    \n        FOR(j, n) swap(A[j][i], A[j][k + 1]);\r\n      }\r\n      break;\r\n\
    \    }\r\n    if (A[k + 1][k] == 0) continue;\r\n    FOR3(i, k + 2, n) {\r\n \
    \     T c = A[i][k] / A[k + 1][k];\r\n      // i \u884C\u76EE -= k+1 \u884C\u76EE\
    \ * c\r\n      FOR(j, n) A[i][j] -= A[k + 1][j] * c;\r\n      // k+1 \u5217\u76EE\
    \ += i \u5217\u76EE * c\r\n      FOR(j, n) A[j][k + 1] += A[j][i] * c;\r\n   \
    \ }\r\n  }\r\n}\r\n\r\n// det(xI-A)\r\ntemplate <typename T>\r\nvc<T> characteristic_poly(vc<vc<T>>\
    \ A) {\r\n  /*\r\n  \u30FBHessenberg \u884C\u5217\u306B\u5909\u5F62\r\n  \u30FB\
    Hessenberg \u884C\u5217\u306E\u884C\u5217\u5F0F\u306F\u3001\u6700\u5F8C\u306E\u5217\
    \u3067\u5834\u5408\u5206\u3051\u3059\u308C\u3070 dp \u3067\u304D\u308B\r\n  */\r\
    \n  int n = len(A);\r\n  to_Hessenberg_matrix(A);\r\n  vc<vc<T>> DP(n + 1);\r\n\
    \  DP[0] = {1};\r\n  FOR(k, n) {\r\n    DP[k + 1].resize(k + 2);\r\n    auto&\
    \ dp = DP[k + 1];\r\n    // (k, k) \u6210\u5206\u3092\u4F7F\u3046\u5834\u5408\r\
    \n    FOR(i, len(DP[k])) dp[i + 1] += DP[k][i];\r\n    FOR(i, len(DP[k])) dp[i]\
    \ -= DP[k][i] * A[k][k];\r\n    // \u4E0B\u5074\u5BFE\u89D2\u306E\u7DCF\u7A4D\u3092\
    \u7BA1\u7406\r\n    T prod = 1;\r\n    FOR_R(i, k) {\r\n      // (i, k) \u6210\
    \u5206\u3092\u4F7F\u3046\u5834\u5408\r\n      prod *= A[i + 1][i];\r\n      T\
    \ c = prod * A[i][k];\r\n      // DP[i] \u306E c \u500D\u3092\u52A0\u7B97\r\n\
    \      FOR(j, len(DP[i])) dp[j] -= DP[i][j] * c;\r\n    }\r\n  }\r\n  return DP[n];\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/characteristic_poly.hpp
  requiredBy:
  - linalg/det_A_plus_xB.hpp
  timestamp: '2022-10-12 08:04:47+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1907.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/library_checker/matrix/charactereistic_poly.test.cpp
documentation_of: linalg/characteristic_poly.hpp
layout: document
redirect_from:
- /library/linalg/characteristic_poly.hpp
- /library/linalg/characteristic_poly.hpp.html
title: linalg/characteristic_poly.hpp
---
