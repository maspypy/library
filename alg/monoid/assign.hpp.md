---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/powersums_assign.hpp
    title: alg/acted_monoid/powersums_assign.hpp
  - icon: ':question:'
    path: alg/acted_monoid/sum_assign.hpp
    title: alg/acted_monoid/sum_assign.hpp
  - icon: ':question:'
    path: alg/acted_monoid/summax_assign.hpp
    title: alg/acted_monoid/summax_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/summin_assign.hpp
    title: alg/acted_monoid/summin_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dynamic_lazy_segtree.test.cpp
    title: test/1_mytest/dynamic_lazy_segtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
    title: test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/max_assign.test.cpp
    title: test/1_mytest/max_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/range_assign.test.cpp
    title: test/1_mytest/range_assign.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_am.test.cpp
    title: test/1_mytest/rbst_am.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_am_persistent.test.cpp
    title: test/1_mytest/rbst_am_persistent.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_monoid.test.cpp
    title: test/1_mytest/rbst_monoid.test.cpp
  - icon: ':x:'
    path: test/1_mytest/rbst_monoid_persistent.test.cpp
    title: test/1_mytest/rbst_monoid_persistent.test.cpp
  - icon: ':x:'
    path: test/1_mytest/splay_monoid.test.cpp
    title: test/1_mytest/splay_monoid.test.cpp
  - icon: ':x:'
    path: test/1_mytest/summax_assign.test.cpp
    title: test/1_mytest/summax_assign.test.cpp
  - icon: ':x:'
    path: test/1_mytest/summin_assign.test.cpp
    title: test/1_mytest/summin_assign.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1548.test.cpp
    title: test/3_yukicoder/1548.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2292.test.cpp
    title: test/3_yukicoder/2292.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_2_D.test.cpp
    title: test/4_aoj/DSL_2_D.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_2_F.test.cpp
    title: test/4_aoj/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DSL_2_I.test.cpp
    title: test/4_aoj/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc256ex.test.cpp
    title: test/5_atcoder/abc256ex.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc256ex2.test.cpp
    title: test/5_atcoder/abc256ex2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, int none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == X(none_val) ? x : y); }\r\n  static constexpr X unit() { return\
    \ X(none_val); }\r\n  static constexpr bool commute = false;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename X, int none_val>\r\nstruct Monoid_Assign\
    \ {\r\n  using value_type = X;\r\n  static X op(X x, X y) { return (y == X(none_val)\
    \ ? x : y); }\r\n  static constexpr X unit() { return X(none_val); }\r\n  static\
    \ constexpr bool commute = false;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/assign.hpp
  requiredBy:
  - alg/acted_monoid/min_assign.hpp
  - alg/acted_monoid/summax_assign.hpp
  - alg/acted_monoid/summin_assign.hpp
  - alg/acted_monoid/sum_assign.hpp
  - alg/acted_monoid/max_assign.hpp
  - alg/acted_monoid/powersums_assign.hpp
  timestamp: '2023-10-14 20:28:40+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/5_atcoder/abc256ex.test.cpp
  - test/5_atcoder/abc256ex2.test.cpp
  - test/3_yukicoder/1548.test.cpp
  - test/3_yukicoder/2292.test.cpp
  - test/1_mytest/summin_assign.test.cpp
  - test/1_mytest/dynamic_lazy_segtree.test.cpp
  - test/1_mytest/max_assign.test.cpp
  - test/1_mytest/range_assign.test.cpp
  - test/1_mytest/rbst_monoid_persistent.test.cpp
  - test/1_mytest/summax_assign.test.cpp
  - test/1_mytest/rbst_monoid.test.cpp
  - test/1_mytest/rbst_am.test.cpp
  - test/1_mytest/rbst_am_persistent.test.cpp
  - test/1_mytest/splay_monoid.test.cpp
  - test/1_mytest/dynamic_lazy_segtree_persistent.test.cpp
  - test/4_aoj/DSL_2_I.test.cpp
  - test/4_aoj/DSL_2_D.test.cpp
  - test/4_aoj/DSL_2_F.test.cpp
documentation_of: alg/monoid/assign.hpp
layout: document
redirect_from:
- /library/alg/monoid/assign.hpp
- /library/alg/monoid/assign.hpp.html
title: alg/monoid/assign.hpp
---
