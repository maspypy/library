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
    path: graph/classify_subtree.hpp
    title: graph/classify_subtree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/rerooting_classify_subtree.hpp
    title: graph/rerooting_classify_subtree.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/spmat_det.hpp
    title: linalg/spmat_det.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/spmat_min_poly.hpp
    title: linalg/spmat_min_poly.hpp
  - icon: ':question:'
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
  - icon: ':x:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  - icon: ':x:'
    path: poly/fps_sqrt.hpp
    title: poly/fps_sqrt.hpp
  - icon: ':x:'
    path: string/rollinghash.hpp
    title: string/rollinghash.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/chromatic_number.test.cpp
    title: test/library_checker/graph/chromatic_number.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/classify_tree.test.cpp
    title: test/library_checker/graph/classify_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/rerooting_classify_subtree.test.cpp
    title: test/library_checker/graph/rerooting_classify_subtree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/sqrt_mod.test.cpp
    title: test/library_checker/math/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/sparse_matrix_det.test.cpp
    title: test/library_checker/matrix/sparse_matrix_det.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - icon: ':x:'
    path: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':x:'
    path: test/mytest/all_inverse.test.cpp
    title: test/mytest/all_inverse.test.cpp
  - icon: ':x:'
    path: test/mytest/binom.test.cpp
    title: test/mytest/binom.test.cpp
  - icon: ':x:'
    path: test/mytest/conv_leq.test.cpp
    title: test/mytest/conv_leq.test.cpp
  - icon: ':x:'
    path: test/mytest/enum_partitions.test.cpp
    title: test/mytest/enum_partitions.test.cpp
  - icon: ':x:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':x:'
    path: test/mytest/is_substring.test.cpp
    title: test/mytest/is_substring.test.cpp
  - icon: ':x:'
    path: test/mytest/max_of_linear_segments.test.cpp
    title: test/mytest/max_of_linear_segments.test.cpp
  - icon: ':x:'
    path: test/mytest/maxplus_concave.test.cpp
    title: test/mytest/maxplus_concave.test.cpp
  - icon: ':x:'
    path: test/mytest/min_of_linear_segments.test.cpp
    title: test/mytest/min_of_linear_segments.test.cpp
  - icon: ':x:'
    path: test/mytest/minplus_convex.test.cpp
    title: test/mytest/minplus_convex.test.cpp
  - icon: ':x:'
    path: test/mytest/mod_sum_of_linear.test.cpp
    title: test/mytest/mod_sum_of_linear.test.cpp
  - icon: ':x:'
    path: test/mytest/powerquery.test.cpp
    title: test/mytest/powerquery.test.cpp
  - icon: ':x:'
    path: test/mytest/range_freq_of_linear.test.cpp
    title: test/mytest/range_freq_of_linear.test.cpp
  - icon: ':x:'
    path: test/mytest/range_mex.test.cpp
    title: test/mytest/range_mex.test.cpp
  - icon: ':x:'
    path: test/mytest/rect_add_pt_sum.test.cpp
    title: test/mytest/rect_add_pt_sum.test.cpp
  - icon: ':x:'
    path: test/mytest/run_length.test.cpp
    title: test/mytest/run_length.test.cpp
  - icon: ':x:'
    path: test/mytest/wavelet_matrix_sum.test.cpp
    title: test/mytest/wavelet_matrix_sum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/4_1.test.cpp
    title: test/yukicoder/4_1.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/random.hpp\"\n\nll RNG(ll a, ll b) {\n  static mt19937\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n  uniform_int_distribution<ll>\
    \ dist(a, b - 1);\n  return dist(mt);\n}\n\nll RNG(ll a) { return RNG(0, a); }\n"
  code: "#pragma once\n\nll RNG(ll a, ll b) {\n  static mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \  uniform_int_distribution<ll> dist(a, b - 1);\n  return dist(mt);\n}\n\nll RNG(ll\
    \ a) { return RNG(0, a); }\n"
  dependsOn: []
  isVerificationFile: false
  path: other/random.hpp
  requiredBy:
  - graph/classify_subtree.hpp
  - graph/rerooting_classify_subtree.hpp
  - graph/chromatic.hpp
  - mod/modular_subset_sum.hpp
  - mod/mod_sqrt.hpp
  - linalg/spmat_det.hpp
  - linalg/spmat_min_poly.hpp
  - string/rollinghash.hpp
  - alg/monoid_rollinghash.hpp
  - poly/fps_sqrt.hpp
  timestamp: '2022-08-25 09:50:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/4_1.test.cpp
  - test/mytest/minplus_convex.test.cpp
  - test/mytest/all_inverse.test.cpp
  - test/mytest/range_mex.test.cpp
  - test/mytest/rect_add_pt_sum.test.cpp
  - test/mytest/conv_leq.test.cpp
  - test/mytest/maxplus_concave.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/mytest/mod_sum_of_linear.test.cpp
  - test/mytest/wavelet_matrix_sum.test.cpp
  - test/mytest/min_of_linear_segments.test.cpp
  - test/mytest/run_length.test.cpp
  - test/mytest/range_freq_of_linear.test.cpp
  - test/mytest/powerquery.test.cpp
  - test/mytest/binom.test.cpp
  - test/mytest/enum_partitions.test.cpp
  - test/mytest/max_of_linear_segments.test.cpp
  - test/mytest/is_substring.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
  - test/library_checker/graph/classify_tree.test.cpp
  - test/library_checker/graph/rerooting_classify_subtree.test.cpp
  - test/library_checker/graph/chromatic_number.test.cpp
  - test/library_checker/math/sqrt_mod.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - test/library_checker/matrix/sparse_matrix_det.test.cpp
  - test/aoj/ALDS1_14_C.test.cpp
documentation_of: other/random.hpp
layout: document
redirect_from:
- /library/other/random.hpp
- /library/other/random.hpp.html
title: other/random.hpp
---
