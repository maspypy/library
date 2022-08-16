---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy_cntsum_set.hpp
    title: alg/lazy_cntsum_set.hpp
  - icon: ':warning:'
    path: alg/lazy_cntsummax_set.hpp
    title: alg/lazy_cntsummax_set.hpp
  - icon: ':warning:'
    path: alg/lazy_cntsummin_set.hpp
    title: alg/lazy_cntsummin_set.hpp
  - icon: ':warning:'
    path: alg/lazy_max_set.hpp
    title: alg/lazy_max_set.hpp
  - icon: ':heavy_check_mark:'
    path: alg/lazy_min_set.hpp
    title: alg/lazy_min_set.hpp
  - icon: ':x:'
    path: alg/lazy_powersums_set.hpp
    title: alg/lazy_powersums_set.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D_dualsegtree.test.cpp
    title: test/aoj/DSL_2_D_dualsegtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F_min_set_lazy.test.cpp
    title: test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I_cntsum_set_lazy.test.cpp
    title: test/aoj/DSL_2_I_cntsum_set_lazy.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1548_power_sums.test.cpp
    title: test/yukicoder/1548_power_sums.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid_set.hpp\"\ntemplate <typename E, E none_val>\r\
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
  path: alg/monoid_set.hpp
  requiredBy:
  - alg/lazy_cntsum_set.hpp
  - alg/lazy_cntsummin_set.hpp
  - alg/lazy_powersums_set.hpp
  - alg/lazy_cntsummax_set.hpp
  - alg/lazy_min_set.hpp
  - alg/lazy_max_set.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_I_cntsum_set_lazy.test.cpp
  - test/aoj/DSL_2_D_dualsegtree.test.cpp
  - test/aoj/DSL_2_F_min_set_lazy.test.cpp
  - test/yukicoder/1548_power_sums.test.cpp
documentation_of: alg/monoid_set.hpp
layout: document
redirect_from:
- /library/alg/monoid_set.hpp
- /library/alg/monoid_set.hpp.html
title: alg/monoid_set.hpp
---
