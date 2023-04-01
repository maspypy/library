---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
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
  - icon: ':x:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_assign.test.cpp
    title: test/mytest/max_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_max.test.cpp
    title: test/mytest/max_max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_min.test.cpp
    title: test/mytest/max_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/min_max.test.cpp
    title: test/mytest/min_max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1117.test.cpp
    title: test/yukicoder/1117.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625.test.cpp
    title: test/yukicoder/1625.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625_2.test.cpp
    title: test/yukicoder/1625_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1826.test.cpp
    title: test/yukicoder/1826.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1826_2.test.cpp
    title: test/yukicoder/1826_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2026.test.cpp
    title: test/yukicoder/2026.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2242.test.cpp
    title: test/yukicoder/2242.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/686.test.cpp
    title: test/yukicoder/686.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc240ex.test.cpp
    title: test_atcoder/abc240ex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc266h.test.cpp
    title: test_atcoder/abc266h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc266h_2.test.cpp
    title: test_atcoder/abc266h_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc270_f.test.cpp
    title: test_atcoder/abc270_f.test.cpp
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
  - alg/acted_monoid/min_max.hpp
  - alg/acted_monoid/max_max.hpp
  - alg/acted_monoid/max_min.hpp
  - alg/acted_monoid/max_assign.hpp
  - alg/acted_monoid/max_add.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc266h.test.cpp
  - test_atcoder/abc266h_2.test.cpp
  - test_atcoder/abc270_f.test.cpp
  - test_atcoder/abc240ex.test.cpp
  - test/mytest/min_max.test.cpp
  - test/mytest/max_min.test.cpp
  - test/mytest/max_max.test.cpp
  - test/mytest/max_assign.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/yukicoder/2026.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/yukicoder/1625.test.cpp
  - test/yukicoder/1826.test.cpp
  - test/yukicoder/1625_2.test.cpp
  - test/yukicoder/686.test.cpp
  - test/yukicoder/2242.test.cpp
  - test/yukicoder/1826_2.test.cpp
  - test/yukicoder/1117.test.cpp
documentation_of: alg/monoid/max.hpp
layout: document
redirect_from:
- /library/alg/monoid/max.hpp
- /library/alg/monoid/max.hpp.html
title: alg/monoid/max.hpp
---
