---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy_max_add.hpp
    title: alg/lazy_max_add.hpp
  - icon: ':warning:'
    path: alg/lazy_max_max.hpp
    title: alg/lazy_max_max.hpp
  - icon: ':warning:'
    path: alg/lazy_max_min.hpp
    title: alg/lazy_max_min.hpp
  - icon: ':warning:'
    path: alg/lazy_max_set.hpp
    title: alg/lazy_max_set.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A_mst.test.cpp
    title: test/aoj/GRL_2_A_mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1117_swag.test.cpp
    title: test/yukicoder/1117_swag.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625_kdtree.test.cpp
    title: test/yukicoder/1625_kdtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625_seg2d.test.cpp
    title: test/yukicoder/1625_seg2d.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1826_dseg.test.cpp
    title: test/yukicoder/1826_dseg.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_max.hpp\"\ntemplate <class X>\r\nstruct Monoid_Max\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class X>\r\nstruct Monoid_Max {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return max(x,\
    \ y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest(); }\r\
    \n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_max.hpp
  requiredBy:
  - alg/lazy_max_min.hpp
  - alg/lazy_max_set.hpp
  - alg/lazy_max_add.hpp
  - alg/lazy_max_max.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2022-06-05 12:22:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_2_A_mst.test.cpp
  - test/yukicoder/1625_kdtree.test.cpp
  - test/yukicoder/1826_dseg.test.cpp
  - test/yukicoder/1625_seg2d.test.cpp
  - test/yukicoder/1117_swag.test.cpp
documentation_of: alg/monoid_max.hpp
layout: document
redirect_from:
- /library/alg/monoid_max.hpp
- /library/alg/monoid_max.hpp.html
title: alg/monoid_max.hpp
---
