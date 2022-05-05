---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/convolution/subset_convolution.test.cpp
    title: test/library_checker/convolution/subset_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"setfunc/subset_convolution.hpp\"\ntemplate <typename T>\r\
    \nvc<T> subset_convolution(vc<T>& A, vc<T>& B) {\r\n  auto RA = ranked_zeta(A);\r\
    \n  auto RB = ranked_zeta(A);\r\n  FOR(s, len(RA)) RA[s] *= RB[s];\r\n  return\
    \ ranked_mobius(RA);\r\n}\r\n"
  code: "template <typename T>\r\nvc<T> subset_convolution(vc<T>& A, vc<T>& B) {\r\
    \n  auto RA = ranked_zeta(A);\r\n  auto RB = ranked_zeta(A);\r\n  FOR(s, len(RA))\
    \ RA[s] *= RB[s];\r\n  return ranked_mobius(RA);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/subset_convolution.hpp
  requiredBy: []
  timestamp: '2022-05-05 18:24:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/convolution/subset_convolution.test.cpp
documentation_of: setfunc/subset_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/subset_convolution.hpp
- /library/setfunc/subset_convolution.hpp.html
title: setfunc/subset_convolution.hpp
---
