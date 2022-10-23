---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_det.test.cpp
    title: test/library_checker/matrix/matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/det.hpp\"\ntemplate <typename T>\r\nT det(vc<vc<T>>\
    \ A) {\r\n  T det = T(1);\r\n  while (len(A)) {\r\n    int n = len(A);\r\n   \
    \ int k = n;\r\n    FOR_R(i, n) if (A[i].back() != 0) {\r\n      k = i;\r\n  \
    \    break;\r\n    }\r\n    if (k == n) return T(0);\r\n    if (k != n - 1) {\r\
    \n      det *= (-1);\r\n      swap(A[k], A[n - 1]);\r\n    }\r\n    det *= A[n\
    \ - 1][n - 1];\r\n    FOR(i, n - 1) {\r\n      T c = A[i].back() / A[n - 1].back();\r\
    \n      A[i].pop_back();\r\n      FOR(j, n - 1) A[i][j] -= A[n - 1][j] * c;\r\n\
    \    }\r\n    A.pop_back();\r\n  }\r\n  return det;\r\n}\r\n"
  code: "template <typename T>\r\nT det(vc<vc<T>> A) {\r\n  T det = T(1);\r\n  while\
    \ (len(A)) {\r\n    int n = len(A);\r\n    int k = n;\r\n    FOR_R(i, n) if (A[i].back()\
    \ != 0) {\r\n      k = i;\r\n      break;\r\n    }\r\n    if (k == n) return T(0);\r\
    \n    if (k != n - 1) {\r\n      det *= (-1);\r\n      swap(A[k], A[n - 1]);\r\
    \n    }\r\n    det *= A[n - 1][n - 1];\r\n    FOR(i, n - 1) {\r\n      T c = A[i].back()\
    \ / A[n - 1].back();\r\n      A[i].pop_back();\r\n      FOR(j, n - 1) A[i][j]\
    \ -= A[n - 1][j] * c;\r\n    }\r\n    A.pop_back();\r\n  }\r\n  return det;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/det.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1303.test.cpp
  - test/library_checker/matrix/matrix_det.test.cpp
documentation_of: linalg/det.hpp
layout: document
redirect_from:
- /library/linalg/det.hpp
- /library/linalg/det.hpp.html
title: linalg/det.hpp
---
