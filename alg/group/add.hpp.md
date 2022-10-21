---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/fenwick.hpp
    title: ds/fenwick.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick2d.hpp
    title: ds/fenwick2d.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwick2d_dense.hpp
    title: ds/fenwick2d_dense.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwickraq.hpp
    title: ds/fenwickraq.hpp
  - icon: ':warning:'
    path: ds/query/point_add_polygon_sum.hpp
    title: ds/query/point_add_polygon_sum.hpp
  - icon: ':warning:'
    path: ds/query/point_add_rectangle_sum.hpp
    title: ds/query/point_add_rectangle_sum.hpp
  - icon: ':heavy_check_mark:'
    path: ds/query/rectangle_add_point_sum.hpp
    title: ds/query/rectangle_add_point_sum.hpp
  - icon: ':heavy_check_mark:'
    path: ds/waveletmatrix.hpp
    title: ds/waveletmatrix.hpp
  - icon: ':warning:'
    path: graph/ds/contoursum.hpp
    title: graph/ds/contoursum.hpp
  - icon: ':warning:'
    path: graph/ds/treeabelgroup.hpp
    title: graph/ds/treeabelgroup.hpp
  - icon: ':heavy_check_mark:'
    path: seq/inversion.hpp
    title: seq/inversion.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2842.test.cpp
    title: test/aoj/2842.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_2_A.test.cpp
    title: test/aoj/ALDS1_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_range_sum.test.cpp
    title: test/library_checker/datastructure/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
    title: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/rect_add_pt_sum.test.cpp
    title: test/mytest/rect_add_pt_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/wavelet_matrix_sum.test.cpp
    title: test/mytest/wavelet_matrix_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1311.test.cpp
    title: test/yukicoder/1311.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1332.test.cpp
    title: test/yukicoder/1332.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1874.test.cpp
    title: test/yukicoder/1874.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2003.test.cpp
    title: test/yukicoder/2003.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2065.test.cpp
    title: test/yukicoder/2065.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/919.test.cpp
    title: test/yukicoder/919.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/group/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Group_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename E>\r\nstruct Group_Add {\r\n  using\
    \ X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const\
    \ X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x)\
    \ noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept\
    \ { return X(n) * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: alg/group/add.hpp
  requiredBy:
  - seq/inversion.hpp
  - graph/ds/treeabelgroup.hpp
  - graph/ds/contoursum.hpp
  - ds/waveletmatrix.hpp
  - ds/fenwick2d.hpp
  - ds/query/point_add_polygon_sum.hpp
  - ds/query/point_add_rectangle_sum.hpp
  - ds/query/rectangle_add_point_sum.hpp
  - ds/fenwick.hpp
  - ds/fenwickraq.hpp
  - ds/fenwick2d_dense.hpp
  timestamp: '2022-10-21 16:42:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/wavelet_matrix_sum.test.cpp
  - test/mytest/rect_add_pt_sum.test.cpp
  - test/yukicoder/1874.test.cpp
  - test/yukicoder/2003.test.cpp
  - test/yukicoder/919.test.cpp
  - test/yukicoder/2065.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/1311.test.cpp
  - test/yukicoder/1038.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/2842.test.cpp
  - test/aoj/ALDS1_2_A.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - test/library_checker/datastructure/point_add_range_sum.test.cpp
documentation_of: alg/group/add.hpp
layout: document
redirect_from:
- /library/alg/group/add.hpp
- /library/alg/group/add.hpp.html
title: alg/group/add.hpp
---
