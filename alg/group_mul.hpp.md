---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/lazy_add_mul.hpp
    title: alg/lazy_add_mul.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':question:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':x:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':heavy_check_mark:'
    path: seq/interpolate_poly_exp_sum.hpp
    title: seq/interpolate_poly_exp_sum.hpp
  - icon: ':x:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
    title: test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339_discrete_log.test.cpp
    title: test/yukicoder/1339_discrete_log.test.cpp
  - icon: ':x:'
    path: test/yukicoder/502_p_rec.test.cpp
    title: test/yukicoder/502_p_rec.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/899_bfsnumbering.test.cpp
    title: test/yukicoder/899_bfsnumbering.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/group_mul.hpp\"\ntemplate <class T>\r\nstruct Group_Mul\
    \ {\r\n  using value_type = T;\r\n  using X = T;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x * y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return X(1) / x; }\r\n  static constexpr X unit() { return\
    \ X(1); }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "template <class T>\r\nstruct Group_Mul {\r\n  using value_type = T;\r\n \
    \ using X = T;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return\
    \ x * y; }\r\n  static constexpr X inverse(const X &x) noexcept { return X(1)\
    \ / x; }\r\n  static constexpr X unit() { return X(1); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group_mul.hpp
  requiredBy:
  - mod/mod_log.hpp
  - alg/lazy_add_mul.hpp
  - seq/kth_term_of_p_recursive.hpp
  - seq/interpolate_poly_exp_sum.hpp
  - poly/lagrange_interpolate_iota.hpp
  - poly/prefix_product_of_poly.hpp
  timestamp: '2022-06-05 16:18:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/502_p_rec.test.cpp
  - test/yukicoder/899_bfsnumbering.test.cpp
  - test/yukicoder/1339_discrete_log.test.cpp
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/library_checker/polynomial/shift_of_sampling_points_of_polynomial.test.cpp
documentation_of: alg/group_mul.hpp
layout: document
redirect_from:
- /library/alg/group_mul.hpp
- /library/alg/group_mul.hpp.html
title: alg/group_mul.hpp
---
