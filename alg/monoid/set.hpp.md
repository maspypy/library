---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy/cntsum_set.hpp
    title: alg/lazy/cntsum_set.hpp
  - icon: ':warning:'
    path: alg/lazy/cntsummax_set.hpp
    title: alg/lazy/cntsummax_set.hpp
  - icon: ':warning:'
    path: alg/lazy/cntsummin_set.hpp
    title: alg/lazy/cntsummin_set.hpp
  - icon: ':warning:'
    path: alg/lazy/max_set.hpp
    title: alg/lazy/max_set.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy/min_set.hpp
    title: alg/lazy/min_set.hpp
  - icon: ':x:'
    path: alg/lazy/powersums_set.hpp
    title: alg/lazy/powersums_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1548.test.cpp
    title: test/yukicoder/1548.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/set.hpp\"\ntemplate <typename E, E none_val>\r\
    \nstruct Monoid_Set {\r\n  using value_type = E;\r\n  using X = value_type;\r\n\
    \  static X op(X x, X y) { return (y == none_val ? x : y); }\r\n  static constexpr\
    \ X unit() { return none_val; }\r\n  static constexpr bool commute = false;\r\n\
    };\n"
  code: "template <typename E, E none_val>\r\nstruct Monoid_Set {\r\n  using value_type\
    \ = E;\r\n  using X = value_type;\r\n  static X op(X x, X y) { return (y == none_val\
    \ ? x : y); }\r\n  static constexpr X unit() { return none_val; }\r\n  static\
    \ constexpr bool commute = false;\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/set.hpp
  requiredBy:
  - alg/lazy/cntsum_set.hpp
  - alg/lazy/cntsummax_set.hpp
  - alg/lazy/max_set.hpp
  - alg/lazy/cntsummin_set.hpp
  - alg/lazy/powersums_set.hpp
  - alg/lazy/min_set.hpp
  timestamp: '2022-10-21 16:22:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1548.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_F.test.cpp
documentation_of: alg/monoid/set.hpp
layout: document
redirect_from:
- /library/alg/monoid/set.hpp
- /library/alg/monoid/set.hpp.html
title: alg/monoid/set.hpp
---
