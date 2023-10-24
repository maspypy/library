---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/inverse_matrix.test.cpp
    title: test/library_checker/matrix/inverse_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/matrix_inv.hpp\"\n// (det, invA) \u3092\u304B\u3048\
    \u3059\r\ntemplate <typename T>\r\npair<T, vc<vc<T>>> matrix_inv(vc<vc<T>> A)\
    \ {\r\n  T det = 1;\r\n  int N = len(A);\r\n  vv(T, B, N, N);\r\n  FOR(n, N) B[n][n]\
    \ = 1;\r\n  FOR(i, N) {\r\n    FOR(k, i, N) if (A[k][i] != 0) {\r\n      if (k\
    \ != i) {\r\n        swap(A[i], A[k]), swap(B[i], B[k]);\r\n        det = -det;\r\
    \n      }\r\n      break;\r\n    }\r\n    if (A[i][i] == 0) return {T(0), {}};\r\
    \n    T c = T(1) / A[i][i];\r\n    det *= A[i][i];\r\n    FOR(j, i, N) A[i][j]\
    \ *= c;\r\n    FOR(j, N) B[i][j] *= c;\r\n    FOR(k, N) if (i != k) {\r\n    \
    \  T c = A[k][i];\r\n      FOR(j, i, N) A[k][j] -= A[i][j] * c;\r\n      FOR(j,\
    \ N) B[k][j] -= B[i][j] * c;\r\n    }\r\n  }\r\n  return {det, B};\r\n}\r\n"
  code: "// (det, invA) \u3092\u304B\u3048\u3059\r\ntemplate <typename T>\r\npair<T,\
    \ vc<vc<T>>> matrix_inv(vc<vc<T>> A) {\r\n  T det = 1;\r\n  int N = len(A);\r\n\
    \  vv(T, B, N, N);\r\n  FOR(n, N) B[n][n] = 1;\r\n  FOR(i, N) {\r\n    FOR(k,\
    \ i, N) if (A[k][i] != 0) {\r\n      if (k != i) {\r\n        swap(A[i], A[k]),\
    \ swap(B[i], B[k]);\r\n        det = -det;\r\n      }\r\n      break;\r\n    }\r\
    \n    if (A[i][i] == 0) return {T(0), {}};\r\n    T c = T(1) / A[i][i];\r\n  \
    \  det *= A[i][i];\r\n    FOR(j, i, N) A[i][j] *= c;\r\n    FOR(j, N) B[i][j]\
    \ *= c;\r\n    FOR(k, N) if (i != k) {\r\n      T c = A[k][i];\r\n      FOR(j,\
    \ i, N) A[k][j] -= A[i][j] * c;\r\n      FOR(j, N) B[k][j] -= B[i][j] * c;\r\n\
    \    }\r\n  }\r\n  return {det, B};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/matrix_inv.hpp
  requiredBy: []
  timestamp: '2023-10-24 14:07:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/matrix/inverse_matrix.test.cpp
documentation_of: linalg/matrix_inv.hpp
layout: document
redirect_from:
- /library/linalg/matrix_inv.hpp
- /library/linalg/matrix_inv.hpp.html
title: linalg/matrix_inv.hpp
---
