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
  - icon: ':warning:'
    path: geo/delaunay_triangulation_of_convex_polygon.hpp
    title: geo/delaunay_triangulation_of_convex_polygon.hpp
  - icon: ':warning:'
    path: geo/minimum_enclosing_circle.hpp
    title: geo/minimum_enclosing_circle.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_graph.hpp
    title: random/random_graph.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_K4.test.cpp
    title: test/1_mytest/count_K4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_P3P4P5.test.cpp
    title: test/1_mytest/count_P3P4P5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_clique.test.cpp
    title: test/1_mytest/count_clique.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_indep_set.test.cpp
    title: test/1_mytest/count_indep_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/extended_lichao.test.cpp
    title: test/1_mytest/extended_lichao.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/extended_lichao_2.test.cpp
    title: test/1_mytest/extended_lichao_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_C4.test.cpp
    title: test/1_mytest/find_C4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_cycle_minimum.test.cpp
    title: test/1_mytest/find_cycle_minimum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_even_cycle.test.cpp
    title: test/1_mytest/find_even_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_odd_cycle.test.cpp
    title: test/1_mytest/find_odd_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/incremental_scc.test.cpp
    title: test/1_mytest/incremental_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching_line_graph.test.cpp
    title: test/1_mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching_ve.test.cpp
    title: test/1_mytest/matching_ve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/nth_element_from_sorted_lists.test.cpp
    title: test/1_mytest/nth_element_from_sorted_lists.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/nth_element_from_sorted_matrix.test.cpp
    title: test/1_mytest/nth_element_from_sorted_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/remove_one_edge.test.cpp
    title: test/1_mytest/remove_one_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/remove_one_vertex.test.cpp
    title: test/1_mytest/remove_one_vertex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/rolling_hash_on_tree.test.cpp
    title: test/1_mytest/rolling_hash_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/slope_super.test.cpp
    title: test/1_mytest/slope_super.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/st_numbering.test.cpp
    title: test/1_mytest/st_numbering.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tree_walk_gf.test.cpp
    title: test/1_mytest/tree_walk_gf.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/closest_pair.test.cpp
    title: test/2_library_checker/geometry/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/closest_pair_dc.test.cpp
    title: test/2_library_checker/geometry/closest_pair_dc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/CGL_5_A.test.cpp
    title: test/4_aoj/CGL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n"
  code: "#include \"random/base.hpp\"\n\ntemplate <typename T>\nvoid shuffle(vc<T>&\
    \ A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n    if (i != j) swap(A[i],\
    \ A[j]);\n  }\n}"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: random/shuffle.hpp
  requiredBy:
  - geo/delaunay_triangulation_of_convex_polygon.hpp
  - geo/closest_pair.hpp
  - geo/minimum_enclosing_circle.hpp
  - random/random_graph.hpp
  timestamp: '2024-10-18 02:58:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/slope_super.test.cpp
  - test/1_mytest/matching_line_graph.test.cpp
  - test/1_mytest/rolling_hash_on_tree.test.cpp
  - test/1_mytest/find_cycle_minimum.test.cpp
  - test/1_mytest/find_odd_cycle.test.cpp
  - test/1_mytest/remove_one_edge.test.cpp
  - test/1_mytest/remove_one_vertex.test.cpp
  - test/1_mytest/count_K4.test.cpp
  - test/1_mytest/count_clique.test.cpp
  - test/1_mytest/tree_walk_gf.test.cpp
  - test/1_mytest/st_numbering.test.cpp
  - test/1_mytest/nth_element_from_sorted_lists.test.cpp
  - test/1_mytest/matching_ve.test.cpp
  - test/1_mytest/nth_element_from_sorted_matrix.test.cpp
  - test/1_mytest/extended_lichao.test.cpp
  - test/1_mytest/find_C4.test.cpp
  - test/1_mytest/count_indep_set.test.cpp
  - test/1_mytest/extended_lichao_2.test.cpp
  - test/1_mytest/find_even_cycle.test.cpp
  - test/1_mytest/count_P3P4P5.test.cpp
  - test/1_mytest/incremental_scc.test.cpp
  - test/4_aoj/CGL_5_A.test.cpp
  - test/2_library_checker/geometry/closest_pair.test.cpp
  - test/2_library_checker/geometry/closest_pair_dc.test.cpp
documentation_of: random/shuffle.hpp
layout: document
redirect_from:
- /library/random/shuffle.hpp
- /library/random/shuffle.hpp.html
title: random/shuffle.hpp
---
