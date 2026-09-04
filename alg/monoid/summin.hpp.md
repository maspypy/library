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
    path: test/1_mytest/summin_add.test.cpp
    title: test/1_mytest/summin_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/summin_assign.test.cpp
    title: test/1_mytest/summin_assign.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/summin.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMin {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, min(x.se, y.se)}; }\n  static\
    \ X from_element(E x) { return {x, x}; }\n  static constexpr X id() { return {E(0),\
    \ infty<E>}; }\n  static constexpr bool commute = true;\n};\n"
  code: "\ntemplate <typename E>\nstruct Monoid_SumMin {\n  using value_type = pair<E,\
    \ E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi + y.fi,\
    \ min(x.se, y.se)}; }\n  static X from_element(E x) { return {x, x}; }\n  static\
    \ constexpr X id() { return {E(0), infty<E>}; }\n  static constexpr bool commute\
    \ = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/summin.hpp
  requiredBy:
  - alg/acted_monoid/summin_assign.hpp
  - alg/acted_monoid/summin_add.hpp
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/summin_add.test.cpp
  - test/1_mytest/summin_assign.test.cpp
documentation_of: alg/monoid/summin.hpp
layout: document
redirect_from:
- /library/alg/monoid/summin.hpp
- /library/alg/monoid/summin.hpp.html
title: alg/monoid/summin.hpp
---
