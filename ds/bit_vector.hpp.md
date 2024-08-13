---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - icon: ':warning:'
    path: ds/wavelet_matrix/wavelet_matrix_old.hpp
    title: ds/wavelet_matrix/wavelet_matrix_old.hpp
  - icon: ':warning:'
    path: graph/ds/tree_wavelet_matrix.hpp
    title: graph/ds/tree_wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
    path: string/prefix_substring_LCS.hpp
    title: string/prefix_substring_LCS.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/wavelet_matrix.test.cpp
    title: test/1_mytest/wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/2_library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
    title: test/2_library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/datastructure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/datastructure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/prefix_substring_lcs.test.cpp
    title: test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/3_yukicoder/2065.test.cpp
    title: test/3_yukicoder/2065.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/919.test.cpp
    title: test/3_yukicoder/919.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/924.test.cpp
    title: test/3_yukicoder/924.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc127f_1.test.cpp
    title: test/5_atcoder/abc127f_1.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc324g.test.cpp
    title: test/5_atcoder/abc324g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  int n;\n  bool\
    \ prepared = 0;\n  vc<pair<u64, u32>> dat;\n  Bit_Vector(int n) : n(n) { dat.assign((n\
    \ + 127) >> 6, {0, 0}); }\n  void set(int i) {\n    assert(!prepared);\n    dat[i\
    \ >> 6].fi |= u64(1) << (i & 63);\n  }\n  void reset() {\n    fill(all(dat), pair<u64,\
    \ u32>{0, 0});\n    prepared = 0;\n  }\n  void build() {\n    prepared = 1;\n\
    \    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n\
    \  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  bool operator[](int i) { return\
    \ dat[i >> 6].fi >> (i & 63) & 1; }\n  int count_prefix(int k, bool f = true)\
    \ {\n    assert(prepared);\n    auto [a, b] = dat[k >> 6];\n    int ret = b +\
    \ popcnt(a & ((u64(1) << (k & 63)) - 1));\n    return (f ? ret : k - ret);\n \
    \ }\n  int count(int L, int R, bool f = true) { return count_prefix(R, f) - count_prefix(L,\
    \ f); }\n  string to_string() {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i\
    \ / 64].fi >> (i % 64) & 1);\n    return ans;\n  }\n};\n"
  code: "struct Bit_Vector {\n  int n;\n  bool prepared = 0;\n  vc<pair<u64, u32>>\
    \ dat;\n  Bit_Vector(int n) : n(n) { dat.assign((n + 127) >> 6, {0, 0}); }\n \
    \ void set(int i) {\n    assert(!prepared);\n    dat[i >> 6].fi |= u64(1) << (i\
    \ & 63);\n  }\n  void reset() {\n    fill(all(dat), pair<u64, u32>{0, 0});\n \
    \   prepared = 0;\n  }\n  void build() {\n    prepared = 1;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\
    \u306E 1 \u306E\u500B\u6570\n  bool operator[](int i) { return dat[i >> 6].fi\
    \ >> (i & 63) & 1; }\n  int count_prefix(int k, bool f = true) {\n    assert(prepared);\n\
    \    auto [a, b] = dat[k >> 6];\n    int ret = b + popcnt(a & ((u64(1) << (k &\
    \ 63)) - 1));\n    return (f ? ret : k - ret);\n  }\n  int count(int L, int R,\
    \ bool f = true) { return count_prefix(R, f) - count_prefix(L, f); }\n  string\
    \ to_string() {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i / 64].fi >>\
    \ (i % 64) & 1);\n    return ans;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/bit_vector.hpp
  requiredBy:
  - string/prefix_substring_LCS.hpp
  - graph/ds/tree_wavelet_matrix.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/wavelet_matrix/wavelet_matrix_old.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  timestamp: '2024-08-08 19:22:51+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/5_atcoder/abc324g.test.cpp
  - test/5_atcoder/abc127f_1.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/3_yukicoder/2065.test.cpp
  - test/3_yukicoder/1332.test.cpp
  - test/3_yukicoder/924.test.cpp
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/1919_2.test.cpp
  - test/3_yukicoder/919.test.cpp
  - test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - test/2_library_checker/datastructure/range_kth_smallest_wavelet.test.cpp
  - test/2_library_checker/datastructure/point_add_rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/datastructure/rectangle_sum_wm.test.cpp
  - test/2_library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/2_library_checker/datastructure/rectangle_sum_wm_abel.test.cpp
  - test/1_mytest/wavelet_matrix.test.cpp
documentation_of: ds/bit_vector.hpp
layout: document
redirect_from:
- /library/ds/bit_vector.hpp
- /library/ds/bit_vector.hpp.html
title: ds/bit_vector.hpp
---
