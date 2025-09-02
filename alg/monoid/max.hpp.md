---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: alg/acted_monoid/max_add.hpp
    title: alg/acted_monoid/max_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/max_max.hpp
    title: alg/acted_monoid/max_max.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/max_min.hpp
    title: alg/acted_monoid/max_min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_max.hpp
    title: alg/acted_monoid/min_max.hpp
  - icon: ':question:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/max_assign.test.cpp
    title: test/1_mytest/max_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/max_max.test.cpp
    title: test/1_mytest/max_max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/max_min.test.cpp
    title: test/1_mytest/max_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/min_max.test.cpp
    title: test/1_mytest/min_max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_add_range_max.test.cpp
    title: test/1_mytest/range_add_range_max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/mst.test.cpp
    title: test/2_library_checker/tree/mst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1117.test.cpp
    title: test/3_yukicoder/1117.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1625.test.cpp
    title: test/3_yukicoder/1625.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1625_2.test.cpp
    title: test/3_yukicoder/1625_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1790.test.cpp
    title: test/3_yukicoder/1790.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1826.test.cpp
    title: test/3_yukicoder/1826.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1826_2.test.cpp
    title: test/3_yukicoder/1826_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2026.test.cpp
    title: test/3_yukicoder/2026.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2242.test.cpp
    title: test/3_yukicoder/2242.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2295.test.cpp
    title: test/3_yukicoder/2295.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2859.test.cpp
    title: test/3_yukicoder/2859.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/686.test.cpp
    title: test/3_yukicoder/686.test.cpp
  - icon: ':x:'
    path: test/4_aoj/GRL_2_A.test.cpp
    title: test/4_aoj/GRL_2_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Max {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return max(x, y); }\r\n  static constexpr\
    \ X unit() { return -infty<E>; }\r\n  static constexpr bool commute = true;\r\n\
    };\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Monoid_Max {\r\n  using\
    \ X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return\
    \ -infty<E>; }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/max.hpp
  requiredBy:
  - graph/minimum_spanning_tree.hpp
  - alg/acted_monoid/max_add.hpp
  - alg/acted_monoid/max_min.hpp
  - alg/acted_monoid/max_max.hpp
  - alg/acted_monoid/min_max.hpp
  - alg/acted_monoid/max_assign.hpp
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/1790.test.cpp
  - test/3_yukicoder/1117.test.cpp
  - test/3_yukicoder/1826.test.cpp
  - test/3_yukicoder/1625.test.cpp
  - test/3_yukicoder/2026.test.cpp
  - test/3_yukicoder/1826_2.test.cpp
  - test/3_yukicoder/2242.test.cpp
  - test/3_yukicoder/2295.test.cpp
  - test/3_yukicoder/2859.test.cpp
  - test/3_yukicoder/686.test.cpp
  - test/2_library_checker/tree/mst.test.cpp
  - test/1_mytest/max_min.test.cpp
  - test/1_mytest/range_add_range_max.test.cpp
  - test/1_mytest/max_max.test.cpp
  - test/1_mytest/max_assign.test.cpp
  - test/1_mytest/min_max.test.cpp
  - test/4_aoj/GRL_2_A.test.cpp
documentation_of: alg/monoid/max.hpp
layout: document
redirect_from:
- /library/alg/monoid/max.hpp
- /library/alg/monoid/max.hpp.html
title: alg/monoid/max.hpp
---
