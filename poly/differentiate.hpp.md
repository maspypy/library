---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':heavy_check_mark:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sharp_p_subset_sum.hpp
    title: poly/sharp_p_subset_sum.hpp
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
    path: test/yukicoder/1321_surj.test.cpp
    title: test/yukicoder/1321_surj.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - poly/sharp_p_subset_sum.hpp
  - poly/fps_sqrt.hpp
  - poly/fps_exp.hpp
  - poly/fps_pow.hpp
  - seq/surjection.hpp
  - seq/stirling_number_1.hpp
  - seq/stirling_number_2.hpp
  timestamp: '2022-05-02 13:06:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1321_surj.test.cpp
  - test/library_checker/polynomial/exp_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/pow_of_fps_mint.test.cpp
  - test/library_checker/polynomial/pow_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/exp_of_fps.test.cpp
  - test/library_checker/polynomial/pow_of_fps.test.cpp
  - test/library_checker/polynomial/exp_of_fps_amint.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/math/sharp_p_subset_sum.test.cpp
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - test/library_checker/math/stirling_number_of_the_first_kind.test.cpp
documentation_of: poly/differentiate.hpp
layout: document
redirect_from:
- /library/poly/differentiate.hpp
- /library/poly/differentiate.hpp.html
title: poly/differentiate.hpp
---
