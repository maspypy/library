---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':question:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':question:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_divmod.hpp
    title: poly/poly_divmod.hpp
  - icon: ':heavy_check_mark:'
    path: poly/poly_gcd.hpp
    title: poly/poly_gcd.hpp
  - icon: ':warning:'
    path: poly/product_of_one_minus_xn.hpp
    title: poly/product_of_one_minus_xn.hpp
  - icon: ':question:'
    path: poly/product_of_one_plus_xn.hpp
    title: poly/product_of_one_plus_xn.hpp
  - icon: ':heavy_check_mark:'
    path: seq/partition_number.hpp
    title: seq/partition_number.hpp
  - icon: ':heavy_check_mark:'
    path: seq/stirling_number_1.hpp
    title: seq/stirling_number_1.hpp
  - icon: ':question:'
    path: seq/stirling_number_2.hpp
    title: seq/stirling_number_2.hpp
  - icon: ':x:'
    path: seq/sum_of_powers.hpp
    title: seq/sum_of_powers.hpp
  - icon: ':x:'
    path: seq/surjection.hpp
    title: seq/surjection.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/partition.test.cpp
    title: test/library_checker/math/partition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sharp_p_subset_sum.test.cpp
    title: test/library_checker/math/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps.test.cpp
    title: test/library_checker/polynomial/exp_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_fps.test.cpp
    title: test/library_checker/polynomial/inv_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_fps_amint.test.cpp
    title: test/library_checker/polynomial/inv_of_fps_amint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/inv_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/inv_of_polynomials.test.cpp
    title: test/library_checker/polynomial/inv_of_polynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/log_of_fps.test.cpp
    title: test/library_checker/polynomial/log_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/log_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/log_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/multipoint_evaluation.test.cpp
    title: test/library_checker/polynomial/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/polynomial_division.test.cpp
    title: test/library_checker/polynomial/polynomial_division.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/polynomial_interpolation.test.cpp
    title: test/library_checker/polynomial/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/pow_of_fps.test.cpp
    title: test/library_checker/polynomial/pow_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/enum_partitions.test.cpp
    title: test/mytest/enum_partitions.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1145.test.cpp
    title: test/yukicoder/1145.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1321.test.cpp
    title: test/yukicoder/1321.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2062.test.cpp
    title: test/yukicoder/2062.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/count_terms.hpp\"\ntemplate<typename mint>\r\nint count_terms(const\
    \ vc<mint>& f){\r\n  int t = 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\
    \n  return t;\r\n}\n"
  code: "#pragma once\r\ntemplate<typename mint>\r\nint count_terms(const vc<mint>&\
    \ f){\r\n  int t = 0;\r\n  FOR(i, len(f)) if(f[i] != mint(0)) ++t;\r\n  return\
    \ t;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/count_terms.hpp
  requiredBy:
  - poly/poly_divmod.hpp
  - poly/fps_log.hpp
  - poly/fps_sqrt.hpp
  - poly/poly_gcd.hpp
  - poly/fps_inv.hpp
  - poly/product_of_one_plus_xn.hpp
  - poly/fps_exp.hpp
  - poly/fps_pow.hpp
  - poly/multipoint.hpp
  - poly/product_of_one_minus_xn.hpp
  - seq/sum_of_powers.hpp
  - seq/partition_number.hpp
  - seq/surjection.hpp
  - seq/stirling_number_1.hpp
  - seq/stirling_number_2.hpp
  timestamp: '2022-05-02 13:06:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2062.test.cpp
  - test/yukicoder/1145.test.cpp
  - test/yukicoder/1321.test.cpp
  - test/mytest/enum_partitions.test.cpp
  - test/library_checker/polynomial/inv_of_fps.test.cpp
  - test/library_checker/polynomial/polynomial_interpolation.test.cpp
  - test/library_checker/polynomial/exp_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/inv_of_fps_amint.test.cpp
  - test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - test/library_checker/polynomial/log_of_fps.test.cpp
  - test/library_checker/polynomial/log_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/inv_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/multipoint_evaluation.test.cpp
  - test/library_checker/polynomial/inv_of_polynomials.test.cpp
  - test/library_checker/polynomial/polynomial_division.test.cpp
  - test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/exp_of_fps.test.cpp
  - test/library_checker/polynomial/pow_of_fps.test.cpp
  - test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/math/partition.test.cpp
  - test/library_checker/math/sharp_p_subset_sum.test.cpp
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
documentation_of: poly/count_terms.hpp
layout: document
redirect_from:
- /library/poly/count_terms.hpp
- /library/poly/count_terms.hpp.html
title: poly/count_terms.hpp
---
