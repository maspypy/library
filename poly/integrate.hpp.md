---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':x:'
    path: poly/product_of_f_rk_x.hpp
    title: poly/product_of_f_rk_x.hpp
  - icon: ':warning:'
    path: poly/product_of_one_minus_xn.hpp
    title: poly/product_of_one_minus_xn.hpp
  - icon: ':question:'
    path: poly/product_of_one_plus_xn.hpp
    title: poly/product_of_one_plus_xn.hpp
  - icon: ':heavy_check_mark:'
    path: seq/stirling_number_1.hpp
    title: seq/stirling_number_1.hpp
  - icon: ':heavy_check_mark:'
    path: seq/stirling_number_2.hpp
    title: seq/stirling_number_2.hpp
  - icon: ':heavy_check_mark:'
    path: seq/surjection.hpp
    title: seq/surjection.hpp
  _extendedVerifiedWith:
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
    path: test/yukicoder/1321.test.cpp
    title: test/yukicoder/1321.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1392.test.cpp
    title: test/yukicoder/1392.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2062.test.cpp
    title: test/yukicoder/2062.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2097.test.cpp
    title: test/yukicoder/2097.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"poly/integrate.hpp\"\n\ntemplate <typename mint>\nvc<mint>\
    \ integrate(const vc<mint>& f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g))\
    \ g[i] = f[i - 1] * inv<mint>(i);\n  return g;\n}\n"
  code: "#pragma once\n\ntemplate <typename mint>\nvc<mint> integrate(const vc<mint>&\
    \ f) {\n  vc<mint> g(len(f) + 1);\n  FOR3(i, 1, len(g)) g[i] = f[i - 1] * inv<mint>(i);\n\
    \  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/integrate.hpp
  requiredBy:
  - seq/stirling_number_1.hpp
  - seq/stirling_number_2.hpp
  - seq/surjection.hpp
  - poly/fps_sqrt.hpp
  - poly/fps_pow.hpp
  - poly/product_of_f_rk_x.hpp
  - poly/product_of_one_minus_xn.hpp
  - poly/product_of_one_plus_xn.hpp
  - poly/fps_exp.hpp
  timestamp: '2022-05-02 13:06:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1321.test.cpp
  - test/yukicoder/2097.test.cpp
  - test/yukicoder/2062.test.cpp
  - test/yukicoder/1392.test.cpp
  - test/library_checker/polynomial/exp_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/pow_of_fps.test.cpp
  - test/library_checker/polynomial/exp_of_fps.test.cpp
  - test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
  - test/library_checker/math/sharp_p_subset_sum.test.cpp
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
documentation_of: poly/integrate.hpp
layout: document
redirect_from:
- /library/poly/integrate.hpp
- /library/poly/integrate.hpp.html
title: poly/integrate.hpp
---
