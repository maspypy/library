---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/adjugate_matrix.hpp
    title: linalg/adjugate_matrix.hpp
  - icon: ':x:'
    path: linalg/det_A_plus_xB.hpp
    title: linalg/det_A_plus_xB.hpp
  - icon: ':warning:'
    path: linalg/diagonalize_triangular_matrix.hpp
    title: linalg/diagonalize_triangular_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/frobenius.hpp
    title: linalg/frobenius.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/3_yukicoder/1303.test.cpp
    title: test/3_yukicoder/1303.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1774.test.cpp
    title: test/3_yukicoder/1774.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1907.test.cpp
    title: test/3_yukicoder/1907.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/matrix_inv.hpp\"\n\n// (det, invA) \u3092\u304B\u3048\
    \u3059\ntemplate <typename T>\npair<T, vc<vc<T>>> matrix_inv(vc<vc<T>> A) {\n\
    \  T det = 1;\n  int N = len(A);\n  vv(T, B, N, N);\n  FOR(n, N) B[n][n] = 1;\n\
    \  FOR(i, N) {\n    FOR(k, i, N) if (A[k][i] != 0) {\n      if (k != i) {\n  \
    \      swap(A[i], A[k]), swap(B[i], B[k]);\n        det = -det;\n      }\n   \
    \   break;\n    }\n    if (A[i][i] == 0) return {T(0), {}};\n    T c = T(1) /\
    \ A[i][i];\n    det *= A[i][i];\n    FOR(j, i, N) A[i][j] *= c;\n    FOR(j, N)\
    \ B[i][j] *= c;\n    FOR(k, N) if (i != k) {\n      T c = A[k][i];\n      FOR(j,\
    \ i, N) A[k][j] -= A[i][j] * c;\n      FOR(j, N) B[k][j] -= B[i][j] * c;\n   \
    \ }\n  }\n  return {det, B};\n}\n"
  code: "\n// (det, invA) \u3092\u304B\u3048\u3059\ntemplate <typename T>\npair<T,\
    \ vc<vc<T>>> matrix_inv(vc<vc<T>> A) {\n  T det = 1;\n  int N = len(A);\n  vv(T,\
    \ B, N, N);\n  FOR(n, N) B[n][n] = 1;\n  FOR(i, N) {\n    FOR(k, i, N) if (A[k][i]\
    \ != 0) {\n      if (k != i) {\n        swap(A[i], A[k]), swap(B[i], B[k]);\n\
    \        det = -det;\n      }\n      break;\n    }\n    if (A[i][i] == 0) return\
    \ {T(0), {}};\n    T c = T(1) / A[i][i];\n    det *= A[i][i];\n    FOR(j, i, N)\
    \ A[i][j] *= c;\n    FOR(j, N) B[i][j] *= c;\n    FOR(k, N) if (i != k) {\n  \
    \    T c = A[k][i];\n      FOR(j, i, N) A[k][j] -= A[i][j] * c;\n      FOR(j,\
    \ N) B[k][j] -= B[i][j] * c;\n    }\n  }\n  return {det, B};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/matrix_inv.hpp
  requiredBy:
  - linalg/adjugate_matrix.hpp
  - linalg/matrix_lowrank_update.hpp
  - linalg/det_A_plus_xB.hpp
  - linalg/diagonalize_triangular_matrix.hpp
  - linalg/frobenius.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
  - test/2_library_checker/linear_algebra/inverse_matrix.test.cpp
  - test/2_library_checker/linear_algebra/pow_of_matrix_frobenius.test.cpp
  - test/3_yukicoder/1907.test.cpp
  - test/3_yukicoder/1303.test.cpp
  - test/3_yukicoder/1774.test.cpp
documentation_of: linalg/matrix_inv.hpp
layout: document
redirect_from:
- /library/linalg/matrix_inv.hpp
- /library/linalg/matrix_inv.hpp.html
title: linalg/matrix_inv.hpp
---
