---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/summax_add.hpp
    title: alg/acted_monoid/summax_add.hpp
  - icon: ':x:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/summax_add.test.cpp
    title: test/mytest/summax_add.test.cpp
  - icon: ':x:'
    path: test/mytest/summax_assign.test.cpp
    title: test/mytest/summax_assign.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X unit() { return\
    \ {E(0), numeric_limits<E>::max()}; }\n  static constexpr bool commute = 1;\n\
    };\n"
  code: "#pragma once\n\ntemplate <typename E>\nstruct Monoid_SumMax {\n  using value_type\
    \ = pair<E, E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi\
    \ + y.fi, max(x.se, y.se)}; }\n  static X from_element(E e) { return {e, e}; }\n\
    \  static constexpr X unit() { return {E(0), numeric_limits<E>::max()}; }\n  static\
    \ constexpr bool commute = 1;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/summax.hpp
  requiredBy:
  - alg/acted_monoid/summax_assign.hpp
  - alg/acted_monoid/summax_add.hpp
  timestamp: '2022-12-03 07:16:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/summax_add.test.cpp
  - test/mytest/summax_assign.test.cpp
documentation_of: alg/monoid/summax.hpp
layout: document
redirect_from:
- /library/alg/monoid/summax.hpp
- /library/alg/monoid/summax.hpp.html
title: alg/monoid/summax.hpp
---
