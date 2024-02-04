---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
  - icon: ':warning:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
    title: test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1919_2.test.cpp
    title: test/yukicoder/1919_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  vc<pair<u32,\
    \ u32>> dat;\n  Bit_Vector(int n) { dat.assign((n + 63) >> 5, {0, 0}); }\n\n \
    \ void set(int i) { dat[i >> 5].fi |= u32(1) << (i & 31); }\n\n  void build()\
    \ {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n\
    \  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int rank(int k, bool\
    \ f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret = b + popcnt(a & ((u32(1)\
    \ << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n  }\n};\n"
  code: "struct Bit_Vector {\n  vc<pair<u32, u32>> dat;\n  Bit_Vector(int n) { dat.assign((n\
    \ + 63) >> 5, {0, 0}); }\n\n  void set(int i) { dat[i >> 5].fi |= u32(1) << (i\
    \ & 31); }\n\n  void build() {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se\
    \ + popcnt(dat[i].fi);\n  }\n\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n\
    \  int rank(int k, bool f = 1) {\n    auto [a, b] = dat[k >> 5];\n    int ret\
    \ = b + popcnt(a & ((u32(1) << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/bit_vector.hpp
  requiredBy:
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range_dynamic_abelgroup.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range_static_monoid.hpp
  timestamp: '2022-12-12 13:31:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - test/library_checker/datastructure/range_kth_smallest_wavelet2.test.cpp
  - test/yukicoder/1919_2.test.cpp
documentation_of: ds/bit_vector.hpp
layout: document
redirect_from:
- /library/ds/bit_vector.hpp
- /library/ds/bit_vector.hpp.html
title: ds/bit_vector.hpp
---
