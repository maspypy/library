---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/adjugate_matrix.hpp
    title: linalg/adjugate_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/det_A_plus_xB.hpp
    title: linalg/det_A_plus_xB.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/frobenius.hpp
    title: linalg/frobenius.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/matrix_lowrank_update.hpp
    title: linalg/matrix_lowrank_update.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/inverse_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/inverse_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/pow_of_matrix_frobenius.test.cpp
    title: test/2_library_checker/linear_algebra/pow_of_matrix_frobenius.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1303.test.cpp
    title: test/3_yukicoder/1303.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1774.test.cpp
    title: test/3_yukicoder/1774.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1907.test.cpp
    title: test/3_yukicoder/1907.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linalg/matrix_inv.hpp\"\n\r\n// (det, invA) \u3092\u304B\
    \u3048\u3059\r\ntemplate <typename T>\r\npair<T, vc<vc<T>>> matrix_inv(vc<vc<T>>\
    \ A) {\r\n  T det = 1;\r\n  int N = len(A);\r\n  vv(T, B, N, N);\r\n  FOR(n, N)\
    \ B[n][n] = 1;\r\n  FOR(i, N) {\r\n    FOR(k, i, N) if (A[k][i] != 0) {\r\n  \
    \    if (k != i) {\r\n        swap(A[i], A[k]), swap(B[i], B[k]);\r\n        det\
    \ = -det;\r\n      }\r\n      break;\r\n    }\r\n    if (A[i][i] == 0) return\
    \ {T(0), {}};\r\n    T c = T(1) / A[i][i];\r\n    det *= A[i][i];\r\n    FOR(j,\
    \ i, N) A[i][j] *= c;\r\n    FOR(j, N) B[i][j] *= c;\r\n    FOR(k, N) if (i !=\
    \ k) {\r\n      T c = A[k][i];\r\n      FOR(j, i, N) A[k][j] -= A[i][j] * c;\r\
    \n      FOR(j, N) B[k][j] -= B[i][j] * c;\r\n    }\r\n  }\r\n  return {det, B};\r\
    \n}\r\n"
  code: "#pragma once\r\n\r\n// (det, invA) \u3092\u304B\u3048\u3059\r\ntemplate <typename\
    \ T>\r\npair<T, vc<vc<T>>> matrix_inv(vc<vc<T>> A) {\r\n  T det = 1;\r\n  int\
    \ N = len(A);\r\n  vv(T, B, N, N);\r\n  FOR(n, N) B[n][n] = 1;\r\n  FOR(i, N)\
    \ {\r\n    FOR(k, i, N) if (A[k][i] != 0) {\r\n      if (k != i) {\r\n       \
    \ swap(A[i], A[k]), swap(B[i], B[k]);\r\n        det = -det;\r\n      }\r\n  \
    \    break;\r\n    }\r\n    if (A[i][i] == 0) return {T(0), {}};\r\n    T c =\
    \ T(1) / A[i][i];\r\n    det *= A[i][i];\r\n    FOR(j, i, N) A[i][j] *= c;\r\n\
    \    FOR(j, N) B[i][j] *= c;\r\n    FOR(k, N) if (i != k) {\r\n      T c = A[k][i];\r\
    \n      FOR(j, i, N) A[k][j] -= A[i][j] * c;\r\n      FOR(j, N) B[k][j] -= B[i][j]\
    \ * c;\r\n    }\r\n  }\r\n  return {det, B};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/matrix_inv.hpp
  requiredBy:
  - linalg/det_A_plus_xB.hpp
  - linalg/adjugate_matrix.hpp
  - linalg/matrix_lowrank_update.hpp
  - linalg/frobenius.hpp
  timestamp: '2024-11-01 21:56:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1303.test.cpp
  - test/3_yukicoder/1774.test.cpp
  - test/3_yukicoder/1907.test.cpp
  - test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
  - test/2_library_checker/linear_algebra/inverse_matrix.test.cpp
  - test/2_library_checker/linear_algebra/pow_of_matrix_frobenius.test.cpp
documentation_of: linalg/matrix_inv.hpp
layout: document
redirect_from:
- /library/linalg/matrix_inv.hpp
- /library/linalg/matrix_inv.hpp.html
title: linalg/matrix_inv.hpp
---
