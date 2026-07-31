---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/dummy.hpp
    title: alg/monoid/dummy.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - icon: ':warning:'
    path: graph/ds/tree_wavelet_matrix.hpp
    title: graph/ds/tree_wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: string/prefix_substring_LCS.hpp
    title: string/prefix_substring_LCS.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/prefix_substring_lcs.test.cpp
    title: test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1332.test.cpp
    title: test/3_yukicoder/1332.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1625_2.test.cpp
    title: test/3_yukicoder/1625_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1919_2.test.cpp
    title: test/3_yukicoder/1919_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2065.test.cpp
    title: test/3_yukicoder/2065.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2859.test.cpp
    title: test/3_yukicoder/2859.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/919.test.cpp
    title: test/3_yukicoder/919.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/924.test.cpp
    title: test/3_yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"alg/monoid/dummy.hpp\"\nstruct Monoid_Dummy {\n  using value_type\
    \ = char;\n  static constexpr bool commute = true;\n  static value_type op(value_type,\
    \ value_type) { return 0; }\n  static value_type unit() { return 0; }\n};\n#line\
    \ 2 \"ds/dummy_data_structure.hpp\"\n\nstruct Dummy_Data_Structure {\n  using\
    \ MX = Monoid_Dummy;\n  using T = typename MX::value_type;\n  void build(const\
    \ vc<T>& A) {}\n};\n"
  code: "#include \"alg/monoid/dummy.hpp\"\n\nstruct Dummy_Data_Structure {\n  using\
    \ MX = Monoid_Dummy;\n  using T = typename MX::value_type;\n  void build(const\
    \ vc<T>& A) {}\n};"
  dependsOn:
  - alg/monoid/dummy.hpp
  isVerificationFile: false
  path: ds/dummy_data_structure.hpp
  requiredBy:
  - graph/ds/tree_wavelet_matrix.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - string/prefix_substring_LCS.hpp
  timestamp: '2026-04-13 08:42:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1919_2.test.cpp
  - test/3_yukicoder/1332.test.cpp
  - test/3_yukicoder/919.test.cpp
  - test/3_yukicoder/2859.test.cpp
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/3_yukicoder/2065.test.cpp
  - test/3_yukicoder/924.test.cpp
  - test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
documentation_of: ds/dummy_data_structure.hpp
layout: document
redirect_from:
- /library/ds/dummy_data_structure.hpp
- /library/ds/dummy_data_structure.hpp.html
title: ds/dummy_data_structure.hpp
---
