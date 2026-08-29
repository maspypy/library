---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/summin_add.hpp
    title: alg/acted_monoid/summin_add.hpp
  - icon: ':x:'
    path: alg/acted_monoid/summin_assign.hpp
    title: alg/acted_monoid/summin_assign.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/summin_add.test.cpp
    title: test/1_mytest/summin_add.test.cpp
  - icon: ':x:'
    path: test/1_mytest/summin_assign.test.cpp
    title: test/1_mytest/summin_assign.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/summin.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMin {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, min(x.se, y.se)}; }\n  static\
    \ X from_element(E x) { return {x, x}; }\n  static constexpr X unit() { return\
    \ {E(0), infty<E>}; }\n  static constexpr bool commute = true;\n};\n"
  code: "\ntemplate <typename E>\nstruct Monoid_SumMin {\n  using value_type = pair<E,\
    \ E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi + y.fi,\
    \ min(x.se, y.se)}; }\n  static X from_element(E x) { return {x, x}; }\n  static\
    \ constexpr X unit() { return {E(0), infty<E>}; }\n  static constexpr bool commute\
    \ = true;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/summin.hpp
  requiredBy:
  - alg/acted_monoid/summin_add.hpp
  - alg/acted_monoid/summin_assign.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/summin_assign.test.cpp
  - test/1_mytest/summin_add.test.cpp
documentation_of: alg/monoid/summin.hpp
layout: document
redirect_from:
- /library/alg/monoid/summin.hpp
- /library/alg/monoid/summin.hpp.html
title: alg/monoid/summin.hpp
---
