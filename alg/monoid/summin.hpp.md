---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summin_add.hpp
    title: alg/acted_monoid/summin_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summin_assign.hpp
    title: alg/acted_monoid/summin_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/summin_add.test.cpp
    title: test/mytest/summin_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summin_assign.test.cpp
    title: test/mytest/summin_assign.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/summin.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_SumMin {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static X op(X x, X y) { return {x.fi + y.fi, min(x.se, y.se)}; }\r\n  static\
    \ X from_element(E x) { return {x, x}; }\r\n  static constexpr X unit() { return\
    \ {E(0), infty<E>}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Monoid_SumMin {\r\n \
    \ using value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static X op(X\
    \ x, X y) { return {x.fi + y.fi, min(x.se, y.se)}; }\r\n  static X from_element(E\
    \ x) { return {x, x}; }\r\n  static constexpr X unit() { return {E(0), infty<E>};\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/summin.hpp
  requiredBy:
  - alg/acted_monoid/summin_assign.hpp
  - alg/acted_monoid/summin_add.hpp
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/summin_assign.test.cpp
  - test/mytest/summin_add.test.cpp
documentation_of: alg/monoid/summin.hpp
layout: document
redirect_from:
- /library/alg/monoid/summin.hpp
- /library/alg/monoid/summin.hpp.html
title: alg/monoid/summin.hpp
---