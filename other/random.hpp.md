---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/monoid_rollinghash.hpp
    title: alg/monoid_rollinghash.hpp
  - icon: ':heavy_check_mark:'
    path: graph/chromatic.hpp
    title: graph/chromatic.hpp
  - icon: ':x:'
    path: linalg/spmat_det.hpp
    title: linalg/spmat_det.hpp
  - icon: ':x:'
    path: linalg/spmat_min_poly.hpp
    title: linalg/spmat_min_poly.hpp
  - icon: ':question:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  - icon: ':x:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: string/rollinghash.hpp
    title: string/rollinghash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C_rollinghash_2d.test.cpp
    title: test/aoj/ALDS1_14_C_rollinghash_2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':x:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/min_of_linear_segments.test.cpp
    title: test/min_of_linear_segments.test.cpp
  - icon: ':x:'
    path: test/mytest/all_inverse.test.cpp
    title: test/mytest/all_inverse.test.cpp
  - icon: ':x:'
    path: test/mytest/binom.test.cpp
    title: test/mytest/binom.test.cpp
  - icon: ':x:'
    path: test/mytest/enum_partitions.test.cpp
    title: test/mytest/enum_partitions.test.cpp
  - icon: ':x:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/max_of_linear_segments.test.cpp
    title: test/mytest/max_of_linear_segments.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/maxplus_concave.test.cpp
    title: test/mytest/maxplus_concave.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
  - icon: ':x:'
    path: test/mytest/powerquery.test.cpp
    title: test/mytest/powerquery.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_freq_of_linear.test.cpp
    title: test/mytest/range_freq_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  - icon: ':x:'
    path: test/mytest/rect_add_pt_sum.test.cpp
    title: test/mytest/rect_add_pt_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/run_length.test.cpp
    title: test/mytest/run_length.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4_modular_subset_sum.test.cpp
    title: test/yukicoder/4_modular_subset_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/random.hpp\"\nstruct RandomNumberGenerator {\n  mt19937\
    \ mt;\n\n  RandomNumberGenerator() : mt(chrono::steady_clock::now().time_since_epoch().count())\
    \ {}\n\n  ll operator()(ll a, ll b) {  // [a, b)\n    uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n    return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0,\
    \ b)\n    return (*this)(0, b);\n  }\n};\n"
  code: "struct RandomNumberGenerator {\n  mt19937 mt;\n\n  RandomNumberGenerator()\
    \ : mt(chrono::steady_clock::now().time_since_epoch().count()) {}\n\n  ll operator()(ll\
    \ a, ll b) {  // [a, b)\n    uniform_int_distribution<ll> dist(a, b - 1);\n  \
    \  return dist(mt);\n  }\n\n  ll operator()(ll b) {  // [0, b)\n    return (*this)(0,\
    \ b);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: other/random.hpp
  requiredBy:
  - graph/chromatic.hpp
  - mod/modular_subset_sum.hpp
  - mod/mod_sqrt.hpp
  - linalg/spmat_det.hpp
  - linalg/spmat_min_poly.hpp
  - string/rollinghash.hpp
  - alg/monoid_rollinghash.hpp
  - poly/fps_sqrt.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/4_modular_subset_sum.test.cpp
  - test/mytest/minplus_convex.test.cpp
  - test/mytest/all_inverse.test.cpp
  - test/mytest/range_mex.test.cpp
  - test/mytest/rect_add_pt_sum.test.cpp
  - test/mytest/maxplus_concave.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/mytest/mod_sum_of_linear.test.cpp
  - test/mytest/run_length.test.cpp
  - test/mytest/range_freq_of_linear.test.cpp
  - test/mytest/powerquery.test.cpp
  - test/mytest/binom.test.cpp
  - test/mytest/enum_partitions.test.cpp
  - test/mytest/max_of_linear_segments.test.cpp
  - test/min_of_linear_segments.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/graph/chromatic_number.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
  - test/aoj/ALDS1_14_C_rollinghash_2d.test.cpp
documentation_of: other/random.hpp
layout: document
redirect_from:
- /library/other/random.hpp
- /library/other/random.hpp.html
title: other/random.hpp
---
