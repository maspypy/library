---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':question:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':x:'
    path: poly/product_of_f_rk_x.hpp
    title: poly/product_of_f_rk_x.hpp
  - icon: ':x:'
    path: poly/product_of_one_minus_xn.hpp
    title: poly/product_of_one_minus_xn.hpp
  - icon: ':question:'
    path: poly/product_of_one_plus_xn.hpp
    title: poly/product_of_one_plus_xn.hpp
  - icon: ':x:'
    path: poly/product_of_pow_of_linear.hpp
    title: poly/product_of_pow_of_linear.hpp
  - icon: ':question:'
    path: seq/famous/stirling_number_2.hpp
    title: seq/famous/stirling_number_2.hpp
  - icon: ':x:'
    path: seq/famous/surjection.hpp
    title: seq/famous/surjection.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sharp_p_subset_sum.test.cpp
    title: test/library_checker/math/sharp_p_subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps.test.cpp
    title: test/library_checker/polynomial/exp_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/exp_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/exp_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/pow_of_fps.test.cpp
    title: test/library_checker/polynomial/pow_of_fps.test.cpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/mytest/bell.test.cpp
    title: test/mytest/bell.test.cpp
  - icon: ':x:'
    path: test/mytest/online_exp.test.cpp
    title: test/mytest/online_exp.test.cpp
  - icon: ':x:'
    path: test/mytest/online_pow.test.cpp
    title: test/mytest/online_pow.test.cpp
  - icon: ':x:'
    path: test/mytest/product_of_one_pm_xn.test.cpp
    title: test/mytest/product_of_one_pm_xn.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080.test.cpp
    title: test/yukicoder/1080.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1321.test.cpp
    title: test/yukicoder/1321.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1392.test.cpp
    title: test/yukicoder/1392.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1533.test.cpp
    title: test/yukicoder/1533.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1549.test.cpp
    title: test/yukicoder/1549.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1875.test.cpp
    title: test/yukicoder/1875.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1939.test.cpp
    title: test/yukicoder/1939.test.cpp
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
  bundledCode: "#line 2 \"poly/differentiate.hpp\"\n\ntemplate <typename mint>\nvc<mint>\
    \ differentiate(const vc<mint>& f) {\n  if (len(f) <= 1) return {};\n  vc<mint>\
    \ g(len(f) - 1);\n  FOR(i, len(g)) g[i] = f[i + 1] * mint(i + 1);\n  return g;\n\
    }\n"
  code: "#pragma once\n\ntemplate <typename mint>\nvc<mint> differentiate(const vc<mint>&\
    \ f) {\n  if (len(f) <= 1) return {};\n  vc<mint> g(len(f) - 1);\n  FOR(i, len(g))\
    \ g[i] = f[i + 1] * mint(i + 1);\n  return g;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/differentiate.hpp
  requiredBy:
  - poly/fps_exp.hpp
  - poly/product_of_one_minus_xn.hpp
  - poly/fps_pow.hpp
  - poly/product_of_f_rk_x.hpp
  - poly/fps_sqrt.hpp
  - poly/product_of_one_plus_xn.hpp
  - poly/product_of_pow_of_linear.hpp
  - seq/famous/stirling_number_2.hpp
  - seq/famous/surjection.hpp
  timestamp: '2022-05-02 13:06:43+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1392.test.cpp
  - test/yukicoder/1939.test.cpp
  - test/yukicoder/1080.test.cpp
  - test/yukicoder/1549.test.cpp
  - test/yukicoder/1875.test.cpp
  - test/yukicoder/2097.test.cpp
  - test/yukicoder/2062.test.cpp
  - test/yukicoder/1321.test.cpp
  - test/yukicoder/1533.test.cpp
  - test/mytest/online_pow.test.cpp
  - test/mytest/bell.test.cpp
  - test/mytest/online_exp.test.cpp
  - test/mytest/product_of_one_pm_xn.test.cpp
  - test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/pow_of_fps.test.cpp
  - test/library_checker/polynomial/exp_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/exp_of_fps.test.cpp
  - test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
  - test/library_checker/math/sharp_p_subset_sum.test.cpp
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
documentation_of: poly/differentiate.hpp
layout: document
redirect_from:
- /library/poly/differentiate.hpp
- /library/poly/differentiate.hpp.html
title: poly/differentiate.hpp
---
