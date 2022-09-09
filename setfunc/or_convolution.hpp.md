---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: setfunc/zeta.hpp
    title: setfunc/zeta.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_or_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_or_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/zeta.hpp\"\n\r\ntemplate <typename T>\r\nvoid superset_zeta(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s < t) A[s]\
    \ += A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid superset_mobius(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s < t) A[s]\
    \ -= A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid subset_zeta(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s > t) A[s]\
    \ += A[t];\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid subset_mobius(vc<T>&\
    \ A) {\r\n  int log = topbit(len(A));\r\n  assert(1 << log == len(A));\r\n  FOR(n,\
    \ log) FOR(s, 1 << log) {\r\n    int t = s ^ (1 << n);\r\n    if (s > t) A[s]\
    \ -= A[t];\r\n  }\r\n}\n#line 2 \"setfunc/or_convolution.hpp\"\ntemplate <typename\
    \ T>\r\nvc<T> or_convolution(vc<T> A, vc<T> B) {\r\n  subset_zeta(A);\r\n  subset_zeta(B);\r\
    \n  FOR(i, len(A)) A[i] *= B[i];\r\n  subset_mobius(A);\r\n  return A;\r\n}\r\n"
  code: "#include \"setfunc/zeta.hpp\"\r\ntemplate <typename T>\r\nvc<T> or_convolution(vc<T>\
    \ A, vc<T> B) {\r\n  subset_zeta(A);\r\n  subset_zeta(B);\r\n  FOR(i, len(A))\
    \ A[i] *= B[i];\r\n  subset_mobius(A);\r\n  return A;\r\n}\r\n"
  dependsOn:
  - setfunc/zeta.hpp
  isVerificationFile: false
  path: setfunc/or_convolution.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/bitwise_or_convolution.test.cpp
documentation_of: setfunc/or_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/or_convolution.hpp
- /library/setfunc/or_convolution.hpp.html
title: setfunc/or_convolution.hpp
---
