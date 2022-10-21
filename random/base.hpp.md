---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/all_inverse.test.cpp
    title: test/mytest/all_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/binom.test.cpp
    title: test/mytest/binom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/conv_leq.test.cpp
    title: test/mytest/conv_leq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/enum_partitions.test.cpp
    title: test/mytest/enum_partitions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/is_substring.test.cpp
    title: test/mytest/is_substring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_of_linear_segments.test.cpp
    title: test/mytest/max_of_linear_segments.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/maxplus_concave.test.cpp
    title: test/mytest/maxplus_concave.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/min_of_linear_segments.test.cpp
    title: test/mytest/min_of_linear_segments.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/powerquery.test.cpp
    title: test/mytest/powerquery.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_freq_of_linear.test.cpp
    title: test/mytest/range_freq_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rect_add_pt_sum.test.cpp
    title: test/mytest/rect_add_pt_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/splay.test.cpp
    title: test/mytest/splay.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/stern_brocot.test.cpp
    title: test/mytest/stern_brocot.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/wavelet_matrix_sum.test.cpp
    title: test/mytest/wavelet_matrix_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nll RNG(ll a, ll b) {\n  static mt19937\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n  uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n  return dist(mt);\n}\n\nll RNG(ll a) { return RNG(0, a); }\n"
  code: "#pragma once\n\nll RNG(ll a, ll b) {\n  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  uniform_int_distribution<ll> dist(a, b - 1);\n  return dist(mt);\n}\n\nll RNG(ll\
    \ a) { return RNG(0, a); }\n"
  dependsOn: []
  isVerificationFile: false
  path: random/base.hpp
  requiredBy: []
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/stern_brocot.test.cpp
  - test/mytest/max_of_linear_segments.test.cpp
  - test/mytest/wavelet_matrix_sum.test.cpp
  - test/mytest/conv_leq.test.cpp
  - test/mytest/mod_sum_of_linear.test.cpp
  - test/mytest/range_freq_of_linear.test.cpp
  - test/mytest/binom.test.cpp
  - test/mytest/all_inverse.test.cpp
  - test/mytest/min_of_linear_segments.test.cpp
  - test/mytest/splay.test.cpp
  - test/mytest/is_substring.test.cpp
  - test/mytest/maxplus_concave.test.cpp
  - test/mytest/enum_partitions.test.cpp
  - test/mytest/rect_add_pt_sum.test.cpp
  - test/mytest/powerquery.test.cpp
  - test/mytest/range_mex.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/mytest/minplus_convex.test.cpp
documentation_of: random/base.hpp
layout: document
redirect_from:
- /library/random/base.hpp
- /library/random/base.hpp.html
title: random/base.hpp
---
