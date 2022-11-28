---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/acted_monoid/cntsum_assign.hpp
    title: alg/acted_monoid/cntsum_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/cntsummax_assign.hpp
    title: alg/acted_monoid/cntsummax_assign.hpp
  - icon: ':x:'
    path: alg/acted_monoid/cntsummin_assign.hpp
    title: alg/acted_monoid/cntsummin_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/max_assign.hpp
    title: alg/acted_monoid/max_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/powersums_assign.hpp
    title: alg/acted_monoid/powersums_assign.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/mytest/cntsummax_assign.test.cpp
    title: test/mytest/cntsummax_assign.test.cpp
  - icon: ':x:'
    path: test/mytest/cntsummin_assign.test.cpp
    title: test/mytest/cntsummin_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_assign.test.cpp
    title: test/mytest/max_assign.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rbst_lazy.test.cpp
    title: test/mytest/rbst_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1548.test.cpp
    title: test/yukicoder/1548.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/assign.hpp\"\ntemplate <typename X, X none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == none_val ? x : y); }\r\n  static constexpr X unit() { return\
    \ none_val; }\r\n  static constexpr bool commute = false;\r\n};\r\n"
  code: "template <typename X, X none_val>\r\nstruct Monoid_Assign {\r\n  using value_type\
    \ = X;\r\n  static X op(X x, X y) { return (y == none_val ? x : y); }\r\n  static\
    \ constexpr X unit() { return none_val; }\r\n  static constexpr bool commute =\
    \ false;\r\n};\r\n"
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
  timestamp: '2022-11-28 14:51:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1548.test.cpp
  - test/mytest/cntsummin_assign.test.cpp
  - test/mytest/rbst_lazy.test.cpp
  - test/mytest/cntsummax_assign.test.cpp
  - test/mytest/max_assign.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: alg/monoid/assign.hpp
layout: document
redirect_from:
- /library/alg/monoid/assign.hpp
- /library/alg/monoid/assign.hpp.html
title: alg/monoid/assign.hpp
---
