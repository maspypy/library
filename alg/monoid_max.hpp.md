---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
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
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1117_swag.test.cpp
    title: test/yukicoder/1117_swag.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625_kdtree.test.cpp
    title: test/yukicoder/1625_kdtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625_seg2d.test.cpp
    title: test/yukicoder/1625_seg2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1826_dseg.test.cpp
    title: test/yukicoder/1826_dseg.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/bbst_max_right.test.cpp
    title: test/yukicoder/bbst_max_right.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - alg/lazy_max_max.hpp
  - alg/lazy_max_set.hpp
  - alg/lazy_max_add.hpp
  timestamp: '2022-06-05 12:22:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1625_kdtree.test.cpp
  - test/yukicoder/1625_seg2d.test.cpp
  - test/yukicoder/1826_dseg.test.cpp
  - test/yukicoder/1117_swag.test.cpp
  - test/yukicoder/bbst_max_right.test.cpp
documentation_of: alg/monoid_max.hpp
layout: document
redirect_from:
- /library/alg/monoid_max.hpp
- /library/alg/monoid_max.hpp.html
title: alg/monoid_max.hpp
---
