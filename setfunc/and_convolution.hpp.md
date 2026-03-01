---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: setfunc/zeta.hpp
    title: setfunc/zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/zeta.hpp\"\n\r\ntemplate <typename T>\r\nvoid superset_zeta(vc<T>&\
    \ a) {\r\n  int n = len(a);\r\n  for (int i = 1; i != n; i <<= 1)\r\n    for (int\
    \ j = 0; j != n; j += i << 1)\r\n      for (int k = 0; k != i; k++) a[j + k] +=\
    \ a[i + j + k];\r\n}\r\n\r\ntemplate <typename T>\r\nvoid superset_mobius(vc<T>&\
    \ a) {\r\n  int n = len(a);\r\n  for (int i = 1; i != n; i <<= 1)\r\n    for (int\
    \ j = 0; j != n; j += i << 1)\r\n      for (int k = 0; k != i; k++) a[j + k] -=\
    \ a[i + j + k];\r\n}\r\n\r\ntemplate <typename T>\r\nvoid subset_zeta(vc<T>& a)\
    \ {\r\n  int n = len(a);\r\n  for (int i = 1; i != n; i <<= 1)\r\n    for (int\
    \ j = 0; j != n; j += i << 1)\r\n      for (int k = 0; k != i; k++) a[i + j +\
    \ k] += a[j + k];\r\n}\r\n\r\ntemplate <typename T>\r\nvoid subset_mobius(vc<T>&\
    \ a) {\r\n  int n = len(a);\r\n  for (int i = 1; i != n; i <<= 1)\r\n    for (int\
    \ j = 0; j != n; j += i << 1)\r\n      for (int k = 0; k != i; k++) a[i + j +\
    \ k] -= a[j + k];\r\n}\n#line 2 \"setfunc/and_convolution.hpp\"\ntemplate <typename\
    \ T>\r\nvc<T> and_convolution(vc<T> A, vc<T> B) {\r\n  superset_zeta(A);\r\n \
    \ superset_zeta(B);\r\n  FOR(i, len(A)) A[i] *= B[i];\r\n  superset_mobius(A);\r\
    \n  return A;\r\n}\r\n"
  code: "#include \"setfunc/zeta.hpp\"\r\ntemplate <typename T>\r\nvc<T> and_convolution(vc<T>\
    \ A, vc<T> B) {\r\n  superset_zeta(A);\r\n  superset_zeta(B);\r\n  FOR(i, len(A))\
    \ A[i] *= B[i];\r\n  superset_mobius(A);\r\n  return A;\r\n}\r\n"
  dependsOn:
  - setfunc/zeta.hpp
  isVerificationFile: false
  path: setfunc/and_convolution.hpp
  requiredBy: []
  timestamp: '2025-05-25 23:45:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
documentation_of: setfunc/and_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/and_convolution.hpp
- /library/setfunc/and_convolution.hpp.html
title: setfunc/and_convolution.hpp
---
