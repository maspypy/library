---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy/max_add.hpp
    title: alg/lazy/max_add.hpp
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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1117.test.cpp
    title: test/yukicoder/1117.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1790.test.cpp
    title: test/yukicoder/1790.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1826.test.cpp
    title: test/yukicoder/1826.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - alg/lazy/max_add.hpp
  - graph/minimum_spanning_tree.hpp
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1117.test.cpp
  - test/yukicoder/1826.test.cpp
  - test/yukicoder/1790.test.cpp
  - test/aoj/GRL_2_A.test.cpp
  - test/atcoder/abc270_f.test.cpp
  - test/atcoder/abc266h.test.cpp
  - test/atcoder/abc266h_2.test.cpp
documentation_of: alg/monoid/max.hpp
layout: document
redirect_from:
- /library/alg/monoid/max.hpp
- /library/alg/monoid/max.hpp.html
title: alg/monoid/max.hpp
---
