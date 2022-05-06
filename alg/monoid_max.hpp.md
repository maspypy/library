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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid_max.hpp\"\ntemplate <class X, X INF>\r\nstruct\
    \ Monoid_Max {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() {\
    \ return -INF; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class X, X INF>\r\nstruct Monoid_Max {\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return max(x, y); }\r\n  static constexpr X unit() { return -INF; }\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid_max.hpp
  requiredBy:
  - graph/minimum_spanning_tree.hpp
  - alg/lazy_max_set.hpp
  - alg/lazy_max_add.hpp
  - alg/lazy_max_max.hpp
  - alg/lazy_max_min.hpp
  timestamp: '2022-05-06 16:05:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A_mst.test.cpp
documentation_of: alg/monoid_max.hpp
layout: document
redirect_from:
- /library/alg/monoid_max.hpp
- /library/alg/monoid_max.hpp.html
title: alg/monoid_max.hpp
---
