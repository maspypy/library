---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/ds/lazy_tree_monoid.hpp
    title: graph/ds/lazy_tree_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/static_tree_monoid.hpp
    title: graph/ds/static_tree_monoid.hpp
  - icon: ':question:'
    path: graph/ds/tree_monoid.hpp
    title: graph/ds/tree_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/mo_on_tree.test.cpp
    title: test/1_mytest/mo_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/mst.test.cpp
    title: test/2_library_checker/tree/mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/vertex_add_path_sum_monoid_c.test.cpp
    title: test/2_library_checker/tree/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/vertex_add_subtree_sum_monoid.test.cpp
    title: test/2_library_checker/tree/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/vertex_set_path_composite_monoid.test.cpp
    title: test/2_library_checker/tree/vertex_set_path_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1197.test.cpp
    title: test/3_yukicoder/1197.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1212.test.cpp
    title: test/3_yukicoder/1212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1216.test.cpp
    title: test/3_yukicoder/1216.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1216_2.test.cpp
    title: test/3_yukicoder/1216_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1790.test.cpp
    title: test/3_yukicoder/1790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/235.test.cpp
    title: test/3_yukicoder/235.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/529.test.cpp
    title: test/3_yukicoder/529.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/GRL_2_A.test.cpp
    title: test/4_aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/GRL_5_E.test.cpp
    title: test/4_aoj/GRL_5_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/monoid_reverse.hpp\"\n\ntemplate <class Monoid>\n\
    struct Monoid_Reverse {\n  using value_type = typename Monoid::value_type;\n \
    \ using X = value_type;\n  static constexpr X op(const X &x, const X &y) { return\
    \ Monoid::op(y, x); }\n  static constexpr X unit() { return Monoid::unit(); }\n\
    \  static const bool commute = Monoid::commute;\n};\n"
  code: "\ntemplate <class Monoid>\nstruct Monoid_Reverse {\n  using value_type =\
    \ typename Monoid::value_type;\n  using X = value_type;\n  static constexpr X\
    \ op(const X &x, const X &y) { return Monoid::op(y, x); }\n  static constexpr\
    \ X unit() { return Monoid::unit(); }\n  static const bool commute = Monoid::commute;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/monoid_reverse.hpp
  requiredBy:
  - graph/minimum_spanning_tree.hpp
  - graph/ds/lazy_tree_monoid.hpp
  - graph/ds/tree_monoid.hpp
  - graph/ds/static_tree_monoid.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/mo_on_tree.test.cpp
  - test/2_library_checker/tree/mst.test.cpp
  - test/2_library_checker/tree/vertex_set_path_composite_monoid.test.cpp
  - test/2_library_checker/tree/vertex_add_subtree_sum_monoid.test.cpp
  - test/2_library_checker/tree/vertex_add_path_sum_monoid_c.test.cpp
  - test/4_aoj/GRL_2_A.test.cpp
  - test/4_aoj/GRL_5_E.test.cpp
  - test/3_yukicoder/1216.test.cpp
  - test/3_yukicoder/1790.test.cpp
  - test/3_yukicoder/529.test.cpp
  - test/3_yukicoder/1197.test.cpp
  - test/3_yukicoder/235.test.cpp
  - test/3_yukicoder/1216_2.test.cpp
  - test/3_yukicoder/1212.test.cpp
documentation_of: alg/monoid/monoid_reverse.hpp
layout: document
redirect_from:
- /library/alg/monoid/monoid_reverse.hpp
- /library/alg/monoid/monoid_reverse.hpp.html
title: alg/monoid/monoid_reverse.hpp
---
