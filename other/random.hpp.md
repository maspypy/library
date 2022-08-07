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
  - icon: ':heavy_check_mark:'
    path: linalg/spmat_det.hpp
    title: linalg/spmat_det.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/spmat_min_poly.hpp
    title: linalg/spmat_min_poly.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/all_inverse.test.cpp
    title: test/mytest/all_inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_freq_of_linear.test.cpp
    title: test/mytest/range_freq_of_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/run_length.test.cpp
    title: test/mytest/run_length.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4_modular_subset_sum.test.cpp
    title: test/yukicoder/4_modular_subset_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  - linalg/spmat_det.hpp
  - linalg/spmat_min_poly.hpp
  - poly/fps_sqrt.hpp
  - mod/mod_sqrt.hpp
  - mod/modular_subset_sum.hpp
  - graph/chromatic.hpp
  - string/rollinghash.hpp
  - alg/monoid_rollinghash.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_C_rollinghash_2d.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/graph/chromatic_number.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
  - test/yukicoder/4_modular_subset_sum.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/mytest/mod_sum_of_linear.test.cpp
  - test/mytest/all_inverse.test.cpp
  - test/mytest/range_freq_of_linear.test.cpp
  - test/mytest/run_length.test.cpp
documentation_of: other/random.hpp
layout: document
redirect_from:
- /library/other/random.hpp
- /library/other/random.hpp.html
title: other/random.hpp
---
