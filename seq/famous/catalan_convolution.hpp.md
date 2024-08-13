---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/catalan_convolution.test.cpp
    title: test/mytest/catalan_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/famous/catalan_convolution.hpp\"\n// [x^n]C(x)^pow\n\
    template <typename mint>\nmint catalan_convolution(ll pow, ll n) {\n  if (pow\
    \ == 0) return (n == 0 ? mint(1) : mint(0));\n  return mint(pow) * inv<mint>(n\
    \ + n + pow) * C<mint>(n + n + pow, n);\n}\n"
  code: "// [x^n]C(x)^pow\ntemplate <typename mint>\nmint catalan_convolution(ll pow,\
    \ ll n) {\n  if (pow == 0) return (n == 0 ? mint(1) : mint(0));\n  return mint(pow)\
    \ * inv<mint>(n + n + pow) * C<mint>(n + n + pow, n);\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/catalan_convolution.hpp
  requiredBy: []
  timestamp: '2023-06-24 05:39:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/catalan_convolution.test.cpp
documentation_of: seq/famous/catalan_convolution.hpp
layout: document
redirect_from:
- /library/seq/famous/catalan_convolution.hpp
- /library/seq/famous/catalan_convolution.hpp.html
title: seq/famous/catalan_convolution.hpp
---
