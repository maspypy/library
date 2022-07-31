---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_max_min.hpp
    title: alg/lazy_max_min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy_min_add.hpp
    title: alg/lazy_min_add.hpp
  - icon: ':warning:'
    path: alg/lazy_min_min.hpp
    title: alg/lazy_min_min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy_min_set.hpp
    title: alg/lazy_min_set.hpp
  - icon: ':warning:'
    path: ds/range_mex_query.hpp
    title: ds/range_mex_query.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1508_splay.test.cpp
    title: test/aoj/1508_splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
    title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H_min_add_lazy.test.cpp
    title: test/aoj/DSL_2_H_min_add_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A_mst.test.cpp
    title: test/aoj/GRL_2_A_mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_seg.test.cpp
    title: test/library_checker/datastructure/staticrmq_seg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/staticrmq_sparse.test.cpp
    title: test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1234_rmq.test.cpp
    title: test/yukicoder/1234_rmq.test.cpp
  - icon: ':x:'
    path: test/yukicoder/913_cht_monotone.test.cpp
    title: test/yukicoder/913_cht_monotone.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_min.hpp\"\ntemplate <class X>\r\nstruct Monoid_Min\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return min(x,\
    \ y); }\r\n  static constexpr X unit() { return numeric_limits<X>::max(); }\r\n\
    \  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_min.hpp
  requiredBy:
  - ds/range_mex_query.hpp
  - graph/minimum_spanning_tree.hpp
  - alg/lazy_min_add.hpp
  - alg/lazy_min_min.hpp
  - alg/lazy_max_min.hpp
  - alg/lazy_min_set.hpp
  timestamp: '2022-05-13 21:02:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/1508_splay.test.cpp
  - test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - test/aoj/DSL_2_H_min_add_lazy.test.cpp
  - test/aoj/GRL_2_A_mst.test.cpp
  - test/library_checker/datastructure/staticrmq_seg.test.cpp
  - test/library_checker/datastructure/staticrmq_sparse.test.cpp
  - test/yukicoder/1234_rmq.test.cpp
  - test/yukicoder/913_cht_monotone.test.cpp
documentation_of: alg/monoid_min.hpp
layout: document
redirect_from:
- /library/alg/monoid_min.hpp
- /library/alg/monoid_min.hpp.html
title: alg/monoid_min.hpp
---
