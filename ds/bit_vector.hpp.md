---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':heavy_check_mark:'
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
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
    title: test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/prefix_substring_lcs.test.cpp
    title: test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1332.test.cpp
    title: test/3_yukicoder/1332.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1600_2.test.cpp
    title: test/3_yukicoder/1600_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1625_2.test.cpp
    title: test/3_yukicoder/1625_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2065.test.cpp
    title: test/3_yukicoder/2065.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2859.test.cpp
    title: test/3_yukicoder/2859.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/919.test.cpp
    title: test/3_yukicoder/919.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/924.test.cpp
    title: test/3_yukicoder/924.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int\
    \ k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n\
    \  UINT s;\n  struct iter {\n    UINT s;\n    int operator*() const { return lowbit(s);\
    \ }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t) const\
    \ { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t end()\
    \ const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  UINT s;\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ?\
    \ -1ULL : (1ULL << n) - 1; }\n#line 2 \"ds/bit_vector.hpp\"\n\nstruct Bit_Vector\
    \ {\n  int n;\n  bool prepared = 0;\n  vc<pair<u64, u32>> dat;\n  Bit_Vector(int\
    \ n = 0) : n(n) { dat.assign((n + 127) >> 6, {0, 0}); }\n  void set(int i) {\n\
    \    assert(!prepared && (0 <= i && i < n));\n    dat[i >> 6].fi |= u64(1) <<\
    \ (i & 63);\n  }\n  void reset() {\n    fill(all(dat), pair<u64, u32>{0, 0});\n\
    \    prepared = 0;\n  }\n  void build() {\n    prepared = 1;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  bool operator[](int\
    \ i) const { return dat[i >> 6].fi >> (i & 63) & 1; }\n  // [0, k) \u5185\u306E\
    \ 1 \u306E\u500B\u6570\n  int count_prefix(int k, bool f = true) const {\n   \
    \ assert(prepared);\n    auto [a, b] = dat[k >> 6];\n    int ret = b + popcnt(a\
    \ & ((u64(1) << (k & 63)) - 1));\n    return (f ? ret : k - ret);\n  }\n  int\
    \ count(int L, int R, bool f = true) const {\n    return count_prefix(R, f) -\
    \ count_prefix(L, f);\n  }\n  string to_string() const {\n    string ans;\n  \
    \  FOR(i, n) ans += '0' + (dat[i / 64].fi >> (i % 64) & 1);\n    return ans;\n\
    \  }\n};\n"
  code: "#include \"other/bit.hpp\"\n\nstruct Bit_Vector {\n  int n;\n  bool prepared\
    \ = 0;\n  vc<pair<u64, u32>> dat;\n  Bit_Vector(int n = 0) : n(n) { dat.assign((n\
    \ + 127) >> 6, {0, 0}); }\n  void set(int i) {\n    assert(!prepared && (0 <=\
    \ i && i < n));\n    dat[i >> 6].fi |= u64(1) << (i & 63);\n  }\n  void reset()\
    \ {\n    fill(all(dat), pair<u64, u32>{0, 0});\n    prepared = 0;\n  }\n  void\
    \ build() {\n    prepared = 1;\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se\
    \ + popcnt(dat[i].fi);\n  }\n  bool operator[](int i) const { return dat[i >>\
    \ 6].fi >> (i & 63) & 1; }\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int\
    \ count_prefix(int k, bool f = true) const {\n    assert(prepared);\n    auto\
    \ [a, b] = dat[k >> 6];\n    int ret = b + popcnt(a & ((u64(1) << (k & 63)) -\
    \ 1));\n    return (f ? ret : k - ret);\n  }\n  int count(int L, int R, bool f\
    \ = true) const {\n    return count_prefix(R, f) - count_prefix(L, f);\n  }\n\
    \  string to_string() const {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i\
    \ / 64].fi >> (i % 64) & 1);\n    return ans;\n  }\n};\n"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: ds/bit_vector.hpp
  requiredBy:
  - graph/ds/tree_wavelet_matrix.hpp
  - ds/wavelet_matrix/wavelet_matrix_old.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - string/prefix_substring_LCS.hpp
  timestamp: '2026-07-26 21:24:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1332.test.cpp
  - test/3_yukicoder/919.test.cpp
  - test/3_yukicoder/2859.test.cpp
  - test/3_yukicoder/1625_2.test.cpp
  - test/3_yukicoder/1600_2.test.cpp
  - test/3_yukicoder/2065.test.cpp
  - test/3_yukicoder/924.test.cpp
  - test/2_library_checker/string/prefix_substring_lcs.test.cpp
  - test/2_library_checker/data_structure/range_kth_smallest_wavelet.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_wm_mono.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm_abel.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_wm.test.cpp
documentation_of: ds/bit_vector.hpp
layout: document
redirect_from:
- /library/ds/bit_vector.hpp
- /library/ds/bit_vector.hpp.html
title: ds/bit_vector.hpp
---
