---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summax_add.hpp
    title: alg/acted_monoid/summax_add.hpp
  - icon: ':question:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree.test.cpp
    title: test/mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':x:'
    path: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summax_add.test.cpp
    title: test/mytest/summax_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summax_assign.test.cpp
    title: test/mytest/summax_assign.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X unit() { return\
    \ {E(0), numeric_limits<E>::lowest()}; }\n  static constexpr bool commute = 1;\n\
    };\n"
  code: "#pragma once\n\ntemplate <typename E>\nstruct Monoid_SumMax {\n  using value_type\
    \ = pair<E, E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi\
    \ + y.fi, max(x.se, y.se)}; }\n  static X from_element(E e) { return {e, e}; }\n\
    \  static constexpr X unit() { return {E(0), numeric_limits<E>::lowest()}; }\n\
    \  static constexpr bool commute = 1;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/summax.hpp
  requiredBy:
  - alg/acted_monoid/summax_assign.hpp
  - alg/acted_monoid/summax_add.hpp
  timestamp: '2022-12-04 13:46:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/summax_add.test.cpp
  - test/mytest/summax_assign.test.cpp
  - test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/mytest/dynamic_lazy_segtree.test.cpp
documentation_of: alg/monoid/summax.hpp
layout: document
redirect_from:
- /library/alg/monoid/summax.hpp
- /library/alg/monoid/summax.hpp.html
title: alg/monoid/summax.hpp
---
