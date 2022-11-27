---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy/cntsum_add.hpp
    title: alg/lazy/cntsum_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy/cntsum_affine.hpp
    title: alg/lazy/cntsum_affine.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy/cntsum_set.hpp
    title: alg/lazy/cntsum_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.test.cpp
    title: test/aoj/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_affine_range_sum.test.cpp
    title: test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/cf702_F.test.cpp
    title: test/mytest/cf702_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_lazy_2.test.cpp
    title: test/mytest/rbst_lazy_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1197.test.cpp
    title: test/yukicoder/1197.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1919.test.cpp
    title: test/yukicoder/1919.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/235.test.cpp
    title: test/yukicoder/235.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/255.test.cpp
    title: test/yukicoder/255.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/789_2.test.cpp
    title: test/yukicoder/789_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/add_pair.hpp\"\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add_Pair {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi,\
    \ x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi,\
    \ -x.se}; }\r\n  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "template <typename E>\r\nstruct Monoid_Add_Pair {\r\n  using value_type =\
    \ pair<E, E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X &x,\
    \ const X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static constexpr\
    \ X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr X unit()\
    \ { return {0, 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_pair.hpp
  requiredBy:
  - alg/lazy/cntsum_affine.hpp
  - alg/lazy/cntsum_add.hpp
  - alg/lazy/cntsum_set.hpp
  timestamp: '2022-11-27 15:24:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/235.test.cpp
  - test/yukicoder/789_2.test.cpp
  - test/yukicoder/255.test.cpp
  - test/yukicoder/1919.test.cpp
  - test/yukicoder/1197.test.cpp
  - test/mytest/cf702_F.test.cpp
  - test/mytest/rbst_lazy_2.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - test/library_checker/datastructure/range_affine_range_sum.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/GRL_5_E.test.cpp
documentation_of: alg/monoid/add_pair.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_pair.hpp
- /library/alg/monoid/add_pair.hpp.html
title: alg/monoid/add_pair.hpp
---
