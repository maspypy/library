---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy_add_mul.hpp
    title: alg/lazy_add_mul.hpp
  - icon: ':heavy_check_mark:'
    path: ds/powerquery.hpp
    title: ds/powerquery.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':heavy_check_mark:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':heavy_check_mark:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':heavy_check_mark:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  - icon: ':heavy_check_mark:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/powerquery.test.cpp
    title: test/mytest/powerquery.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2005.test.cpp
    title: test/yukicoder/2005.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/502_2.test.cpp
    title: test/yukicoder/502_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899.test.cpp
    title: test/yukicoder/899.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group_mul.hpp\"\n\r\ntemplate <class T>\r\nstruct Group_Mul\
    \ {\r\n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T>\r\nstruct Group_Mul {\r\n  using value_type\
    \ = T;\r\n  using X = T;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x * y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ X(1) / x; }\r\n  static constexpr X unit() { return X(1); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group_mul.hpp
  requiredBy:
  - poly/prefix_product_of_poly.hpp
  - poly/lagrange_interpolate_iota.hpp
  - seq/kth_term_of_p_recursive.hpp
  - seq/interpolate_poly_exp_sum.hpp
  - alg/lazy_add_mul.hpp
  - mod/mod_log.hpp
  - ds/powerquery.hpp
  timestamp: '2022-08-19 06:32:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/powerquery.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/yukicoder/2005.test.cpp
  - test/yukicoder/502_2.test.cpp
  - test/yukicoder/899.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
documentation_of: alg/group_mul.hpp
layout: document
redirect_from:
- /library/alg/group_mul.hpp
- /library/alg/group_mul.hpp.html
title: alg/group_mul.hpp
---
