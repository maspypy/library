---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/sum_mul.hpp
    title: alg/acted_monoid/sum_mul.hpp
  - icon: ':heavy_check_mark:'
    path: ds/power_query.hpp
    title: ds/power_query.hpp
  - icon: ':heavy_check_mark:'
    path: graph/count/count_labeled_bipartite.hpp
    title: graph/count/count_labeled_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':heavy_check_mark:'
    path: nt/discrete_log.hpp
    title: nt/discrete_log.hpp
  - icon: ':heavy_check_mark:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':question:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':question:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  - icon: ':warning:'
    path: poly/sum_of_C_negative.hpp
    title: poly/sum_of_C_negative.hpp
  - icon: ':heavy_check_mark:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  - icon: ':question:'
    path: seq/p_recursive.hpp
    title: seq/p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_bipartite.test.cpp
    title: test/1_mytest/count_bipartite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/factorial_998.test.cpp
    title: test/1_mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/powerquery.test.cpp
    title: test/1_mytest/powerquery.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/enumerative_combinatorics/factorial.test.cpp
    title: test/2_library_checker/enumerative_combinatorics/factorial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
    title: test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
    title: test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/2_library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1080_2.test.cpp
    title: test/3_yukicoder/1080_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1339.test.cpp
    title: test/3_yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2005.test.cpp
    title: test/3_yukicoder/2005.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2166.test.cpp
    title: test/3_yukicoder/2166.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2747.test.cpp
    title: test/3_yukicoder/2747.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/502_2.test.cpp
    title: test/3_yukicoder/502_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/899.test.cpp
    title: test/3_yukicoder/899.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Monoid_Mul\
    \ {\r\n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T>\r\nstruct Monoid_Mul {\r\n  using\
    \ value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const X &x)\
    \ noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return X(1);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/monoid/mul.hpp
  requiredBy:
  - mod/mod_log.hpp
  - seq/interpolate_poly_exp_sum.hpp
  - seq/p_recursive.hpp
  - poly/sparse_exp_of_div.hpp
  - poly/lagrange_interpolate_iota.hpp
  - poly/prefix_product_of_poly.hpp
  - poly/sum_of_C_negative.hpp
  - poly/from_log_differentiation.hpp
  - nt/discrete_log.hpp
  - ds/power_query.hpp
  - graph/count/count_labeled_bipartite.hpp
  - alg/acted_monoid/sum_mul.hpp
  timestamp: '2022-11-27 14:10:12+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/count_bipartite.test.cpp
  - test/1_mytest/powerquery.test.cpp
  - test/1_mytest/factorial_998.test.cpp
  - test/2_library_checker/number_theory/discrete_logarithm_mod.test.cpp
  - test/2_library_checker/enumerative_combinatorics/factorial.test.cpp
  - test/2_library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/2_library_checker/other/sum_of_exp_times_poly.test.cpp
  - test/3_yukicoder/1080_2.test.cpp
  - test/3_yukicoder/2005.test.cpp
  - test/3_yukicoder/899.test.cpp
  - test/3_yukicoder/1339.test.cpp
  - test/3_yukicoder/2166.test.cpp
  - test/3_yukicoder/2747.test.cpp
  - test/3_yukicoder/502_2.test.cpp
documentation_of: alg/monoid/mul.hpp
layout: document
redirect_from:
- /library/alg/monoid/mul.hpp
- /library/alg/monoid/mul.hpp.html
title: alg/monoid/mul.hpp
---
