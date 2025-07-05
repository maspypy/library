---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: setfunc/and_convolution.hpp
    title: setfunc/and_convolution.hpp
  - icon: ':x:'
    path: setfunc/or_convolution.hpp
    title: setfunc/or_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/convolution/bitwise_or_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_or_convolution.test.cpp
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
    \ k] -= a[j + k];\r\n}\n"
  code: "#pragma once\r\n\r\ntemplate <typename T>\r\nvoid superset_zeta(vc<T>& a)\
    \ {\r\n  int n = len(a);\r\n  for (int i = 1; i != n; i <<= 1)\r\n    for (int\
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
    \ k] -= a[j + k];\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/zeta.hpp
  requiredBy:
  - setfunc/and_convolution.hpp
  - setfunc/or_convolution.hpp
  timestamp: '2025-05-25 23:45:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/convolution/bitwise_and_convolution.test.cpp
  - test/2_library_checker/convolution/bitwise_or_convolution.test.cpp
documentation_of: setfunc/zeta.hpp
layout: document
redirect_from:
- /library/setfunc/zeta.hpp
- /library/setfunc/zeta.hpp.html
title: setfunc/zeta.hpp
---
