---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/closest_pair.hpp
    title: geo/closest_pair.hpp
  - icon: ':x:'
    path: geo/minimum_enclosing_circle.hpp
    title: geo/minimum_enclosing_circle.hpp
  - icon: ':question:'
    path: random/random_graph.hpp
    title: random/random_graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/closest_pair.test.cpp
    title: test/library_checker/geometry/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/closest_pair_dc.test.cpp
    title: test/library_checker/geometry/closest_pair_dc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_K4.test.cpp
    title: test/mytest/count_K4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_P3P4P5.test.cpp
    title: test/mytest/count_P3P4P5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_clique.test.cpp
    title: test/mytest/count_clique.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_indep_set.test.cpp
    title: test/mytest/count_indep_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/find_C4.test.cpp
    title: test/mytest/find_C4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/find_cycle_minimum.test.cpp
    title: test/mytest/find_cycle_minimum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/find_even_cycle.test.cpp
    title: test/mytest/find_even_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/find_odd_cycle.test.cpp
    title: test/mytest/find_odd_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/incremental_scc.test.cpp
    title: test/mytest/incremental_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_ve.test.cpp
    title: test/mytest/matching_ve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/nth_element_from_sorted_lists.test.cpp
    title: test/mytest/nth_element_from_sorted_lists.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/nth_element_from_sorted_matrix.test.cpp
    title: test/mytest/nth_element_from_sorted_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/remove_one_edge.test.cpp
    title: test/mytest/remove_one_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/remove_one_vertex.test.cpp
    title: test/mytest/remove_one_vertex.test.cpp
  - icon: ':x:'
    path: test/mytest/rolling_hash_on_tree.test.cpp
    title: test/mytest/rolling_hash_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/st_numbering.test.cpp
    title: test/mytest/st_numbering.test.cpp
  - icon: ':x:'
    path: test/mytest/tree_walk_gf.test.cpp
    title: test/mytest/tree_walk_gf.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc151f.test.cpp
    title: test_atcoder/abc151f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\
    \n\ntemplate <typename T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int\
    \ j = RNG(0, i + 1);\n    if (i != j) swap(A[i], A[j]);\n  }\n}\n"
  code: "#include \"random/base.hpp\"\n\ntemplate <typename T>\nvoid shuffle(vc<T>&\
    \ A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n    if (i != j) swap(A[i],\
    \ A[j]);\n  }\n}"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: random/shuffle.hpp
  requiredBy:
  - geo/minimum_enclosing_circle.hpp
  - geo/closest_pair.hpp
  - random/random_graph.hpp
  timestamp: '2024-05-29 22:32:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/matching_ve.test.cpp
  - test/mytest/find_even_cycle.test.cpp
  - test/mytest/incremental_scc.test.cpp
  - test/mytest/remove_one_vertex.test.cpp
  - test/mytest/find_cycle_minimum.test.cpp
  - test/mytest/remove_one_edge.test.cpp
  - test/mytest/nth_element_from_sorted_lists.test.cpp
  - test/mytest/count_indep_set.test.cpp
  - test/mytest/st_numbering.test.cpp
  - test/mytest/count_P3P4P5.test.cpp
  - test/mytest/count_clique.test.cpp
  - test/mytest/rolling_hash_on_tree.test.cpp
  - test/mytest/count_K4.test.cpp
  - test/mytest/find_odd_cycle.test.cpp
  - test/mytest/tree_walk_gf.test.cpp
  - test/mytest/nth_element_from_sorted_matrix.test.cpp
  - test/mytest/find_C4.test.cpp
  - test/mytest/matching_line_graph.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/library_checker/geometry/closest_pair_dc.test.cpp
  - test/library_checker/geometry/closest_pair.test.cpp
  - test_atcoder/abc151f.test.cpp
documentation_of: random/shuffle.hpp
layout: document
redirect_from:
- /library/random/shuffle.hpp
- /library/random/shuffle.hpp.html
title: random/shuffle.hpp
---
