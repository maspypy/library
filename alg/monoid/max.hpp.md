---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy/max_add.hpp
    title: alg/lazy/max_add.hpp
  - icon: ':question:'
    path: alg/lazy/max_max.hpp
    title: alg/lazy/max_max.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy/max_min.hpp
    title: alg/lazy/max_min.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy/max_set.hpp
    title: alg/lazy/max_set.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy/min_max.hpp
    title: alg/lazy/min_max.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_tree.hpp
    title: graph/minimum_spanning_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc266h.test.cpp
    title: test/atcoder/abc266h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc266h_2.test.cpp
    title: test/atcoder/abc266h_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc270_f.test.cpp
    title: test/atcoder/abc270_f.test.cpp
  - icon: ':x:'
    path: test/mytest/cntsummax_add.test.cpp
    title: test/mytest/cntsummax_add.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_max.test.cpp
    title: test/mytest/max_max.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_min.test.cpp
    title: test/mytest/max_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_set.test.cpp
    title: test/mytest/max_set.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1826.test.cpp
    title: test/yukicoder/1826.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2026.test.cpp
    title: test/yukicoder/2026.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/686.test.cpp
    title: test/yukicoder/686.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/max.hpp\"\ntemplate <class X>\r\nstruct Monoid_Max\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return max(x, y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest();\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\ntemplate <class X>\r\nstruct Monoid_Max {\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return max(x,\
    \ y); }\r\n  static constexpr X unit() { return numeric_limits<X>::lowest(); }\r\
    \n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/max.hpp
  requiredBy:
  - alg/lazy/max_max.hpp
  - alg/lazy/max_add.hpp
  - alg/lazy/min_max.hpp
  - alg/lazy/max_set.hpp
  - alg/lazy/max_min.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/686.test.cpp
  - test/yukicoder/1625.test.cpp
  - test/yukicoder/2026.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/yukicoder/1826.test.cpp
  - test/yukicoder/1625_2.test.cpp
  - test/yukicoder/1117.test.cpp
  - test/mytest/min_max.test.cpp
  - test/mytest/max_max.test.cpp
  - test/mytest/max_min.test.cpp
  - test/mytest/max_set.test.cpp
  - test/mytest/cntsummax_add.test.cpp
  - test/atcoder/abc270_f.test.cpp
  - test/atcoder/abc266h_2.test.cpp
  - test/atcoder/abc266h.test.cpp
  - test/aoj/GRL_2_A.test.cpp
documentation_of: alg/monoid/max.hpp
layout: document
redirect_from:
- /library/alg/monoid/max.hpp
- /library/alg/monoid/max.hpp.html
title: alg/monoid/max.hpp
---
