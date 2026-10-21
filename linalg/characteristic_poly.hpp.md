---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/adjugate_matrix.hpp
    title: linalg/adjugate_matrix.hpp
  - icon: ':question:'
    path: linalg/det_A_plus_xB.hpp
    title: linalg/det_A_plus_xB.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/charactereistic_poly.test.cpp
    title: test/2_library_checker/linear_algebra/charactereistic_poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1303.test.cpp
    title: test/3_yukicoder/1303.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1907.test.cpp
    title: test/3_yukicoder/1907.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/linalg/characteristic_poly.hpp
  bundledCode: "#line 1 \"linalg/characteristic_poly.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/linalg/characteristic_poly.hpp\n\
    template <typename T>\nvoid to_hessenberg_matrix(vc<vc<T>>& A) {\n  /*\n  P^{-1}AP\
    \ \u306E\u5F62\u306E\u5909\u63DB\u3067\u3001Hessenberg \u884C\u5217\u306B\u5909\
    \u5F62\u3059\u308B\u3002\n  \u7279\u5B9A\u591A\u9805\u5F0F\u306E\u8A08\u7B97\u306B\
    \u7528\u3044\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\n  */\n  int n =\
    \ len(A);\n  FOR(k, n - 2) {\n    FOR3(i, k + 1, n) if (A[i][k] != T(0)) {\n \
    \     if (i != k + 1) {\n        swap(A[i], A[k + 1]);\n        FOR(j, n) swap(A[j][i],\
    \ A[j][k + 1]);\n      }\n      break;\n    }\n    if (A[k + 1][k] == T(0)) continue;\n\
    \    FOR3(i, k + 2, n) {\n      T c = A[i][k] / A[k + 1][k];\n      // i \u884C\
    \u76EE -= k+1 \u884C\u76EE * c\n      FOR(j, n) A[i][j] -= A[k + 1][j] * c;\n\
    \      // k+1 \u5217\u76EE += i \u5217\u76EE * c\n      FOR(j, n) A[j][k + 1]\
    \ += A[j][i] * c;\n    }\n  }\n}\n\n// det(xI-A)\ntemplate <typename T>\nvc<T>\
    \ characteristic_poly(vc<vc<T>> A) {\n  /*\n  \u30FBHessenberg \u884C\u5217\u306B\
    \u5909\u5F62\n  \u30FBHessenberg \u884C\u5217\u306E\u884C\u5217\u5F0F\u306F\u3001\
    \u6700\u5F8C\u306E\u5217\u3067\u5834\u5408\u5206\u3051\u3059\u308C\u3070 dp \u3067\
    \u304D\u308B\n  */\n  int n = len(A);\n  to_hessenberg_matrix(A);\n  vc<vc<T>>\
    \ DP(n + 1);\n  DP[0] = {T(1)};\n  FOR(k, n) {\n    DP[k + 1].resize(k + 2);\n\
    \    auto& dp = DP[k + 1];\n    // (k, k) \u6210\u5206\u3092\u4F7F\u3046\u5834\
    \u5408\n    FOR(i, len(DP[k])) dp[i + 1] += DP[k][i];\n    FOR(i, len(DP[k]))\
    \ dp[i] -= DP[k][i] * A[k][k];\n    // \u4E0B\u5074\u5BFE\u89D2\u306E\u7DCF\u7A4D\
    \u3092\u7BA1\u7406\n    T prod = T(1);\n    FOR_R(i, k) {\n      // (i, k) \u6210\
    \u5206\u3092\u4F7F\u3046\u5834\u5408\n      prod *= A[i + 1][i];\n      T c =\
    \ prod * A[i][k];\n      // DP[i] \u306E c \u500D\u3092\u52A0\u7B97\n      FOR(j,\
    \ len(DP[i])) dp[j] -= DP[i][j] * c;\n    }\n  }\n  return DP[n];\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/linalg/characteristic_poly.hpp\n\
    template <typename T>\nvoid to_hessenberg_matrix(vc<vc<T>>& A) {\n  /*\n  P^{-1}AP\
    \ \u306E\u5F62\u306E\u5909\u63DB\u3067\u3001Hessenberg \u884C\u5217\u306B\u5909\
    \u5F62\u3059\u308B\u3002\n  \u7279\u5B9A\u591A\u9805\u5F0F\u306E\u8A08\u7B97\u306B\
    \u7528\u3044\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\n  */\n  int n =\
    \ len(A);\n  FOR(k, n - 2) {\n    FOR3(i, k + 1, n) if (A[i][k] != T(0)) {\n \
    \     if (i != k + 1) {\n        swap(A[i], A[k + 1]);\n        FOR(j, n) swap(A[j][i],\
    \ A[j][k + 1]);\n      }\n      break;\n    }\n    if (A[k + 1][k] == T(0)) continue;\n\
    \    FOR3(i, k + 2, n) {\n      T c = A[i][k] / A[k + 1][k];\n      // i \u884C\
    \u76EE -= k+1 \u884C\u76EE * c\n      FOR(j, n) A[i][j] -= A[k + 1][j] * c;\n\
    \      // k+1 \u5217\u76EE += i \u5217\u76EE * c\n      FOR(j, n) A[j][k + 1]\
    \ += A[j][i] * c;\n    }\n  }\n}\n\n// det(xI-A)\ntemplate <typename T>\nvc<T>\
    \ characteristic_poly(vc<vc<T>> A) {\n  /*\n  \u30FBHessenberg \u884C\u5217\u306B\
    \u5909\u5F62\n  \u30FBHessenberg \u884C\u5217\u306E\u884C\u5217\u5F0F\u306F\u3001\
    \u6700\u5F8C\u306E\u5217\u3067\u5834\u5408\u5206\u3051\u3059\u308C\u3070 dp \u3067\
    \u304D\u308B\n  */\n  int n = len(A);\n  to_hessenberg_matrix(A);\n  vc<vc<T>>\
    \ DP(n + 1);\n  DP[0] = {T(1)};\n  FOR(k, n) {\n    DP[k + 1].resize(k + 2);\n\
    \    auto& dp = DP[k + 1];\n    // (k, k) \u6210\u5206\u3092\u4F7F\u3046\u5834\
    \u5408\n    FOR(i, len(DP[k])) dp[i + 1] += DP[k][i];\n    FOR(i, len(DP[k]))\
    \ dp[i] -= DP[k][i] * A[k][k];\n    // \u4E0B\u5074\u5BFE\u89D2\u306E\u7DCF\u7A4D\
    \u3092\u7BA1\u7406\n    T prod = T(1);\n    FOR_R(i, k) {\n      // (i, k) \u6210\
    \u5206\u3092\u4F7F\u3046\u5834\u5408\n      prod *= A[i + 1][i];\n      T c =\
    \ prod * A[i][k];\n      // DP[i] \u306E c \u500D\u3092\u52A0\u7B97\n      FOR(j,\
    \ len(DP[i])) dp[j] -= DP[i][j] * c;\n    }\n  }\n  return DP[n];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/characteristic_poly.hpp
  requiredBy:
  - linalg/det_A_plus_xB.hpp
  - linalg/adjugate_matrix.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1907.test.cpp
  - test/3_yukicoder/1303.test.cpp
  - test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
  - test/2_library_checker/linear_algebra/charactereistic_poly.test.cpp
documentation_of: linalg/characteristic_poly.hpp
layout: document
redirect_from:
- /library/linalg/characteristic_poly.hpp
- /library/linalg/characteristic_poly.hpp.html
title: linalg/characteristic_poly.hpp
---
