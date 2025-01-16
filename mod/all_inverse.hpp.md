---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/blackbox/vandermonde.hpp
    title: linalg/blackbox/vandermonde.hpp
  - icon: ':heavy_check_mark:'
    path: mod/q_analogue.hpp
    title: mod/q_analogue.hpp
  - icon: ':heavy_check_mark:'
    path: poly/composition_f_log_1_minus_x.hpp
    title: poly/composition_f_log_1_minus_x.hpp
  - icon: ':question:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':heavy_check_mark:'
    path: poly/multivar_convolution_cyclic.hpp
    title: poly/multivar_convolution_cyclic.hpp
  - icon: ':heavy_check_mark:'
    path: poly/partial_frac_decomposition_1.hpp
    title: poly/partial_frac_decomposition_1.hpp
  - icon: ':warning:'
    path: seq/p_recursive.hpp
    title: seq/p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/all_inverse.test.cpp
    title: test/1_mytest/all_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/chirp_z.test.cpp
    title: test/1_mytest/chirp_z.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/composition_log_1_minus_x.test.cpp
    title: test/1_mytest/composition_log_1_minus_x.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/partial_frac.test.cpp
    title: test/1_mytest/partial_frac.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/qbinom.test.cpp
    title: test/1_mytest/qbinom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/vandermonde.test.cpp
    title: test/1_mytest/vandermonde.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
    title: test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/chromatic_number.test.cpp
    title: test/2_library_checker/graph/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/chromatic_polynomial.test.cpp
    title: test/2_library_checker/graph/chromatic_polynomial.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/multipoint_evaluation.test.cpp
    title: test/2_library_checker/polynomial/multipoint_evaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
    title: test/2_library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
    title: test/2_library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/polynomial_interpolation.test.cpp
    title: test/2_library_checker/polynomial/polynomial_interpolation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/polynomial/polynomial_interpolation_on_geom.test.cpp
    title: test/2_library_checker/polynomial/polynomial_interpolation_on_geom.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1575.test.cpp
    title: test/3_yukicoder/1575.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2166.test.cpp
    title: test/3_yukicoder/2166.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2243.test.cpp
    title: test/3_yukicoder/2243.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2877.test.cpp
    title: test/3_yukicoder/2877.test.cpp
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
  - poly/composition_f_log_1_minus_x.hpp
  - poly/partial_frac_decomposition_1.hpp
  - poly/multivar_convolution_cyclic.hpp
  - poly/multipoint.hpp
  - seq/p_recursive.hpp
  - linalg/blackbox/vandermonde.hpp
  - mod/q_analogue.hpp
  - graph/chromatic.hpp
  timestamp: '2022-11-23 08:11:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/convolution/multivariate_convolution_cyclic.test.cpp
  - test/2_library_checker/polynomial/polynomial_interpolation_on_geom.test.cpp
  - test/2_library_checker/polynomial/multipoint_evaluation_on_geom_2.test.cpp
  - test/2_library_checker/polynomial/polynomial_interpolation.test.cpp
  - test/2_library_checker/polynomial/multipoint_evaluation.test.cpp
  - test/2_library_checker/polynomial/multipoint_evaluation_on_geom.test.cpp
  - test/2_library_checker/graph/chromatic_number.test.cpp
  - test/2_library_checker/graph/chromatic_polynomial.test.cpp
  - test/3_yukicoder/1575.test.cpp
  - test/3_yukicoder/2166.test.cpp
  - test/3_yukicoder/2243.test.cpp
  - test/3_yukicoder/2877.test.cpp
  - test/1_mytest/all_inverse.test.cpp
  - test/1_mytest/qbinom.test.cpp
  - test/1_mytest/composition_log_1_minus_x.test.cpp
  - test/1_mytest/vandermonde.test.cpp
  - test/1_mytest/partial_frac.test.cpp
  - test/1_mytest/chirp_z.test.cpp
documentation_of: mod/all_inverse.hpp
layout: document
redirect_from:
- /library/mod/all_inverse.hpp
- /library/mod/all_inverse.hpp.html
title: mod/all_inverse.hpp
---
