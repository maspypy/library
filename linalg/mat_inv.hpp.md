---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/matrix/inverse_matrix.test.cpp
    title: test/library_checker/matrix/inverse_matrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/mat_inv.hpp\"\ntemplate <typename T>\r\nvc<vc<T>>\
    \ mat_inv(vc<vc<T>> A) {\r\n  int N = len(A);\r\n  vv(T, B, N, N);\r\n  FOR(n,\
    \ N) B[n][n] = 1;\r\n  FOR(i, N) {\r\n    FOR3(k, i, N) if (A[k][i] != 0) {\r\n\
    \      if (k != i) swap(A[i], A[k]), swap(B[i], B[k]);\r\n      break;\r\n   \
    \ }\r\n    if (A[i][i] == 0) return {};\r\n    T c = T(1) / A[i][i];\r\n    FOR(j,\
    \ N) {\r\n      A[i][j] *= c;\r\n      B[i][j] *= c;\r\n    }\r\n    FOR(k, N)\
    \ if (i != k) {\r\n      T c = A[k][i];\r\n      FOR(j, N) A[k][j] -= A[i][j]\
    \ * c;\r\n      FOR(j, N) B[k][j] -= B[i][j] * c;\r\n    }\r\n  }\r\n  return\
    \ B;\r\n}\r\n"
  code: "template <typename T>\r\nvc<vc<T>> mat_inv(vc<vc<T>> A) {\r\n  int N = len(A);\r\
    \n  vv(T, B, N, N);\r\n  FOR(n, N) B[n][n] = 1;\r\n  FOR(i, N) {\r\n    FOR3(k,\
    \ i, N) if (A[k][i] != 0) {\r\n      if (k != i) swap(A[i], A[k]), swap(B[i],\
    \ B[k]);\r\n      break;\r\n    }\r\n    if (A[i][i] == 0) return {};\r\n    T\
    \ c = T(1) / A[i][i];\r\n    FOR(j, N) {\r\n      A[i][j] *= c;\r\n      B[i][j]\
    \ *= c;\r\n    }\r\n    FOR(k, N) if (i != k) {\r\n      T c = A[k][i];\r\n  \
    \    FOR(j, N) A[k][j] -= A[i][j] * c;\r\n      FOR(j, N) B[k][j] -= B[i][j] *\
    \ c;\r\n    }\r\n  }\r\n  return B;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/mat_inv.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/matrix/inverse_matrix.test.cpp
documentation_of: linalg/mat_inv.hpp
layout: document
redirect_from:
- /library/linalg/mat_inv.hpp
- /library/linalg/mat_inv.hpp.html
title: linalg/mat_inv.hpp
---
