---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy_reverse.hpp
    title: alg/lazy_reverse.hpp
  - icon: ':heavy_check_mark:'
    path: graph/lazytreemonoid.hpp
    title: graph/lazytreemonoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/statictreemonoid.hpp
    title: graph/statictreemonoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/treemonoid.hpp
    title: graph/treemonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc270_f.test.cpp
    title: test/atcoder/abc270_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1212.test.cpp
    title: test/yukicoder/1212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1216.test.cpp
    title: test/yukicoder/1216.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1216_2.test.cpp
    title: test/yukicoder/1216_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/529.test.cpp
    title: test/yukicoder/529.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_reverse.hpp\"\ntemplate <class Monoid>\r\nstruct\
    \ Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\n  using\
    \ X = value_type;\r\n  static constexpr X op(const X &x, const X &y) { return\
    \ Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class Monoid>\r\nstruct Monoid_Reverse {\r\n  using\
    \ value_type = typename Monoid::value_type;\r\n  using X = value_type;\r\n  static\
    \ constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\n  static\
    \ constexpr X unit() { return Monoid::unit(); }\r\n  static const bool commute\
    \ = Monoid::commute;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_reverse.hpp
  requiredBy:
  - graph/statictreemonoid.hpp
  - graph/minimum_spanning_tree.hpp
  - graph/treemonoid.hpp
  - graph/lazytreemonoid.hpp
  - alg/lazy_reverse.hpp
  timestamp: '2022-04-23 17:49:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/GRL_5_E.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/yukicoder/529.test.cpp
  - test/yukicoder/235.test.cpp
  - test/yukicoder/1212.test.cpp
  - test/yukicoder/1216_2.test.cpp
  - test/yukicoder/1216.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/atcoder/abc270_f.test.cpp
documentation_of: alg/monoid_reverse.hpp
layout: document
redirect_from:
- /library/alg/monoid_reverse.hpp
- /library/alg/monoid_reverse.hpp.html
title: alg/monoid_reverse.hpp
---
