---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/all_but_one_products.test.cpp
    title: test/1_mytest/all_but_one_products.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/all_but_one_products.hpp\"\ntemplate <typename Monoid,\
    \ typename X = typename Monoid::value_type>\nvector<X> all_but_one_products(const\
    \ vc<X>& A) {\n  int N = len(A);\n  vc<X> res(N, Monoid::unit());\n  FOR(i, N\
    \ - 1) res[i + 1] = Monoid::op(res[i], A[i]);\n  X x = Monoid::unit();\n  FOR_R(i,\
    \ N) {\n    res[i] = Monoid::op(res[i], x);\n    x = Monoid::op(A[i], x);\n  }\n\
    \  return res;\n}\n"
  code: "template <typename Monoid, typename X = typename Monoid::value_type>\nvector<X>\
    \ all_but_one_products(const vc<X>& A) {\n  int N = len(A);\n  vc<X> res(N, Monoid::unit());\n\
    \  FOR(i, N - 1) res[i + 1] = Monoid::op(res[i], A[i]);\n  X x = Monoid::unit();\n\
    \  FOR_R(i, N) {\n    res[i] = Monoid::op(res[i], x);\n    x = Monoid::op(A[i],\
    \ x);\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/all_but_one_products.hpp
  requiredBy: []
  timestamp: '2022-10-01 13:28:06+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/all_but_one_products.test.cpp
documentation_of: other/all_but_one_products.hpp
layout: document
redirect_from:
- /library/other/all_but_one_products.hpp
- /library/other/all_but_one_products.hpp.html
title: other/all_but_one_products.hpp
---
