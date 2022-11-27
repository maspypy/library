---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy/reverse.hpp
    title: alg/lazy/reverse.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/lazytreemonoid.hpp
    title: graph/ds/lazytreemonoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/statictreemonoid.hpp
    title: graph/ds/statictreemonoid.hpp
  - icon: ':question:'
    path: graph/ds/treemonoid.hpp
    title: graph/ds/treemonoid.hpp
  - icon: ':question:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':x:'
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
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/529.test.cpp
    title: test/yukicoder/529.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/reverse_monoid.hpp\"\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class Monoid>\r\nstruct Monoid_Reverse {\r\n  using\
    \ value_type = typename Monoid::value_type;\r\n  using X = value_type;\r\n  static\
    \ constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }\r\n  static\
    \ constexpr X unit() { return Monoid::unit(); }\r\n  static const bool commute\
    \ = Monoid::commute;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/reverse_monoid.hpp
  requiredBy:
  - alg/lazy/reverse.hpp
  - graph/ds/lazytreemonoid.hpp
  - graph/ds/treemonoid.hpp
  - graph/ds/statictreemonoid.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2022-11-27 13:06:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1216.test.cpp
  - test/yukicoder/235.test.cpp
  - test/yukicoder/1216_2.test.cpp
  - test/yukicoder/529.test.cpp
  - test/yukicoder/1212.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_monoid.test.cpp
  - test/library_checker/datastructure/vertex_set_path_composite_monoid.test.cpp
  - test/library_checker/datastructure/vertex_add_path_sum_monoid_c.test.cpp
  - test/atcoder/abc270_f.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/aoj/GRL_5_E.test.cpp
documentation_of: alg/monoid/reverse_monoid.hpp
layout: document
redirect_from:
- /library/alg/monoid/reverse_monoid.hpp
- /library/alg/monoid/reverse_monoid.hpp.html
title: alg/monoid/reverse_monoid.hpp
---
