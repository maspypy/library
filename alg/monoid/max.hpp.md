---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/lazy/max_max.hpp
    title: alg/lazy/max_max.hpp
  - icon: ':warning:'
    path: alg/lazy/max_min.hpp
    title: alg/lazy/max_min.hpp
  - icon: ':warning:'
    path: alg/lazy/max_set.hpp
    title: alg/lazy/max_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc266h.test.cpp
    title: test/atcoder/abc266h.test.cpp
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
    path: test/yukicoder/1826.test.cpp
    title: test/yukicoder/1826.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2026.test.cpp
    title: test/yukicoder/2026.test.cpp
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
  - alg/lazy/max_max.hpp
  - alg/lazy/max_set.hpp
  - alg/lazy/max_min.hpp
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1625.test.cpp
  - test/yukicoder/2026.test.cpp
  - test/yukicoder/1826.test.cpp
  - test/yukicoder/1625_2.test.cpp
  - test/yukicoder/1117.test.cpp
  - test/atcoder/abc266h.test.cpp
documentation_of: alg/monoid/max.hpp
layout: document
redirect_from:
- /library/alg/monoid/max.hpp
- /library/alg/monoid/max.hpp.html
title: alg/monoid/max.hpp
---
