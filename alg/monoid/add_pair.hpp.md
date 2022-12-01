---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/cntsum_add.hpp
    title: alg/acted_monoid/cntsum_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/cntsum_affine.hpp
    title: alg/acted_monoid/cntsum_affine.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/cntsum_assign.hpp
    title: alg/acted_monoid/cntsum_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
    title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/ARC30D.test.cpp
    title: test/mytest/ARC30D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/cf702_F.test.cpp
    title: test/mytest/cf702_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/cf702_F_splay.test.cpp
    title: test/mytest/cf702_F_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_am_2.test.cpp
    title: test/mytest/rbst_am_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/splay_am.test.cpp
    title: test/mytest/splay_am.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add_pair.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct Monoid_Add_Pair {\r\n  using value_type = pair<E, E>;\r\n  using X = value_type;\r\
    \n  static constexpr X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi,\
    \ x.se + y.se};\r\n  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi,\
    \ -x.se}; }\r\n  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Monoid_Add_Pair {\r\n\
    \  using value_type = pair<E, E>;\r\n  using X = value_type;\r\n  static constexpr\
    \ X op(const X &x, const X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n\
    \  }\r\n  static constexpr X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n\
    \  static constexpr X unit() { return {0, 0}; }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/add_pair.hpp
  requiredBy:
  - alg/acted_monoid/cntsum_affine.hpp
  - alg/acted_monoid/cntsum_add.hpp
  - alg/acted_monoid/cntsum_assign.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/cf702_F.test.cpp
  - test/mytest/cf702_F_splay.test.cpp
  - test/mytest/splay_am.test.cpp
  - test/mytest/rbst_am_2.test.cpp
  - test/mytest/ARC30D.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_rbst.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay_fast.test.cpp
  - test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
documentation_of: alg/monoid/add_pair.hpp
layout: document
redirect_from:
- /library/alg/monoid/add_pair.hpp
- /library/alg/monoid/add_pair.hpp.html
title: alg/monoid/add_pair.hpp
---
