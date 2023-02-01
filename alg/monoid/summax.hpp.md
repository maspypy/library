---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summax_add.hpp
    title: alg/acted_monoid/summax_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree.test.cpp
    title: test/mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/kdtree_am.test.cpp
    title: test/mytest/kdtree_am.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/kdtree_monoid.test.cpp
    title: test/mytest/kdtree_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summax_add.test.cpp
    title: test/mytest/summax_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/summax_assign.test.cpp
    title: test/mytest/summax_assign.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_SumMax {\n  using value_type = pair<E, E>;\n  using X = value_type;\n\
    \  static X op(X x, X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static\
    \ X from_element(E e) { return {e, e}; }\n  static constexpr X unit() { return\
    \ {E(0), -infty<E>}; }\n  static constexpr bool commute = 1;\n};\n"
  code: "#pragma once\n\ntemplate <typename E>\nstruct Monoid_SumMax {\n  using value_type\
    \ = pair<E, E>;\n  using X = value_type;\n  static X op(X x, X y) { return {x.fi\
    \ + y.fi, max(x.se, y.se)}; }\n  static X from_element(E e) { return {e, e}; }\n\
    \  static constexpr X unit() { return {E(0), -infty<E>}; }\n  static constexpr\
    \ bool commute = 1;\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/summax.hpp
  requiredBy:
  - alg/acted_monoid/summax_assign.hpp
  - alg/acted_monoid/summax_add.hpp
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/summax_assign.test.cpp
  - test/mytest/kdtree_monoid.test.cpp
  - test/mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/mytest/summax_add.test.cpp
  - test/mytest/dynamic_lazy_segtree.test.cpp
  - test/mytest/kdtree_am.test.cpp
documentation_of: alg/monoid/summax.hpp
layout: document
redirect_from:
- /library/alg/monoid/summax.hpp
- /library/alg/monoid/summax.hpp.html
title: alg/monoid/summax.hpp
---
