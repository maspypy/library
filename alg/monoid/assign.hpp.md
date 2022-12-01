---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/acted_monoid/cntsum_assign.hpp
    title: alg/acted_monoid/cntsum_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/cntsummax_assign.hpp
    title: alg/acted_monoid/cntsummax_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/cntsummin_assign.hpp
    title: alg/acted_monoid/cntsummin_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':warning:'
    path: alg/acted_monoid/powersums_assign.hpp
    title: alg/acted_monoid/powersums_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_am.test.cpp
    title: test/mytest/rbst_am.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_am_persistent.test.cpp
    title: test/mytest/rbst_am_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_monoid.test.cpp
    title: test/mytest/rbst_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_monoid_persistent.test.cpp
    title: test/mytest/rbst_monoid_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/splay_monoid.test.cpp
    title: test/mytest/splay_monoid.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, X none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == none_val ? x : y); }\r\n  static constexpr X unit() { return\
    \ none_val; }\r\n  static constexpr bool commute = false;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename X, X none_val>\r\nstruct Monoid_Assign\
    \ {\r\n  using value_type = X;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/assign.hpp
  requiredBy:
  - alg/acted_monoid/cntsummin_assign.hpp
  - alg/acted_monoid/max_assign.hpp
  - alg/acted_monoid/cntsummax_assign.hpp
  - alg/acted_monoid/min_assign.hpp
  - alg/acted_monoid/powersums_assign.hpp
  - alg/acted_monoid/cntsum_assign.hpp
  timestamp: '2022-12-01 09:04:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/splay_monoid.test.cpp
  - test/mytest/rbst_monoid_persistent.test.cpp
  - test/mytest/rbst_monoid.test.cpp
  - test/mytest/rbst_am.test.cpp
  - test/mytest/rbst_am_persistent.test.cpp
documentation_of: alg/monoid/assign.hpp
layout: document
redirect_from:
- /library/alg/monoid/assign.hpp
- /library/alg/monoid/assign.hpp.html
title: alg/monoid/assign.hpp
---
