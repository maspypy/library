---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: linalg/implicit_matrix/vandermonde.hpp
    title: linalg/implicit_matrix/vandermonde.hpp
  - icon: ':warning:'
    path: mod/q_analogue.hpp
    title: mod/q_analogue.hpp
  - icon: ':x:'
    path: poly/composition_f_log_1_minus_x.hpp
    title: poly/composition_f_log_1_minus_x.hpp
  - icon: ':question:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':x:'
    path: poly/multivar_convolution_cyclic.hpp
    title: poly/multivar_convolution_cyclic.hpp
  - icon: ':x:'
    path: poly/partial_frac_decomposition_1.hpp
    title: poly/partial_frac_decomposition_1.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/multipoint_evaluation.test.cpp
    title: test/library_checker/polynomial/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
    title: test/library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
    title: test/library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/polynomial_interpolation.test.cpp
    title: test/library_checker/polynomial/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/all_inverse.test.cpp
    title: test/mytest/all_inverse.test.cpp
  - icon: ':x:'
    path: test/mytest/chirp_z.test.cpp
    title: test/mytest/chirp_z.test.cpp
  - icon: ':x:'
    path: test/mytest/composition_log_1_minus_x.test.cpp
    title: test/mytest/composition_log_1_minus_x.test.cpp
  - icon: ':x:'
    path: test/mytest/partial_frac.test.cpp
    title: test/mytest/partial_frac.test.cpp
  - icon: ':x:'
    path: test/mytest/vandermonde.test.cpp
    title: test/mytest/vandermonde.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2166.test.cpp
    title: test/yukicoder/2166.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2243.test.cpp
    title: test/yukicoder/2243.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc241h.test.cpp
    title: test_atcoder/abc241h.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc260h.test.cpp
    title: test_atcoder/abc260h.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc267g.test.cpp
    title: test_atcoder/abc267g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc272_h.test.cpp
    title: test_atcoder/abc272_h.test.cpp
  - icon: ':x:'
    path: test_atcoder/agc058d2.test.cpp
    title: test_atcoder/agc058d2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/all_inverse.hpp\"\ntemplate <typename mint>\nvc<mint>\
    \ all_inverse(vc<mint>& X) {\n  for (auto&& x: X) assert(x != mint(0));\n  int\
    \ N = len(X);\n  vc<mint> res(N + 1);\n  res[0] = mint(1);\n  FOR(i, N) res[i\
    \ + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n  res.pop_back();\n\
    \  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n  return res;\n}\n"
  code: "#pragma once\ntemplate <typename mint>\nvc<mint> all_inverse(vc<mint>& X)\
    \ {\n  for (auto&& x: X) assert(x != mint(0));\n  int N = len(X);\n  vc<mint>\
    \ res(N + 1);\n  res[0] = mint(1);\n  FOR(i, N) res[i + 1] = res[i] * X[i];\n\
    \  mint t = res.back().inverse();\n  res.pop_back();\n  FOR_R(i, N) {\n    res[i]\
    \ *= t;\n    t *= X[i];\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/all_inverse.hpp
  requiredBy:
  - mod/q_analogue.hpp
  - linalg/implicit_matrix/vandermonde.hpp
  - poly/composition_f_log_1_minus_x.hpp
  - poly/multivar_convolution_cyclic.hpp
  - poly/partial_frac_decomposition_1.hpp
  - poly/multipoint.hpp
  timestamp: '2022-11-23 08:11:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc272_h.test.cpp
  - test_atcoder/agc058d2.test.cpp
  - test_atcoder/abc241h.test.cpp
  - test_atcoder/abc267g.test.cpp
  - test_atcoder/abc260h.test.cpp
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
  - test/library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
  - test/library_checker/polynomial/multipoint_evaluation.test.cpp
  - test/library_checker/polynomial/polynomial_interpolation.test.cpp
  - test/library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
  - test/yukicoder/2166.test.cpp
  - test/yukicoder/2243.test.cpp
  - test/mytest/partial_frac.test.cpp
  - test/mytest/all_inverse.test.cpp
  - test/mytest/chirp_z.test.cpp
  - test/mytest/composition_log_1_minus_x.test.cpp
  - test/mytest/vandermonde.test.cpp
documentation_of: mod/all_inverse.hpp
layout: document
redirect_from:
- /library/mod/all_inverse.hpp
- /library/mod/all_inverse.hpp.html
title: mod/all_inverse.hpp
---
