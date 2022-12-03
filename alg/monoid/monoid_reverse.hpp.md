---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/ds/tree_monoid.hpp
    title: graph/ds/tree_monoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
    title: test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
    title: test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/monoid_reverse.hpp\"\n\r\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class Monoid>\r\nstruct Monoid_Reverse {\r\n\
    \  using value_type = typename Monoid::value_type;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\
    \n  static constexpr X unit() { return Monoid::unit(); }\r\n  static const bool\
    \ commute = Monoid::commute;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/monoid_reverse.hpp
  requiredBy:
  - graph/ds/tree_monoid.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
documentation_of: alg/monoid/monoid_reverse.hpp
layout: document
redirect_from:
- /library/alg/monoid/monoid_reverse.hpp
- /library/alg/monoid/monoid_reverse.hpp.html
title: alg/monoid/monoid_reverse.hpp
---
