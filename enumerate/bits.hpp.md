---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: enumerate/partition.hpp
    title: enumerate/partition.hpp
  - icon: ':heavy_check_mark:'
    path: graph/count/count_cycle.hpp
    title: graph/count/count_cycle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_hamiltonian_cycle.hpp
    title: graph/minimum_hamiltonian_cycle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/steiner_tree.hpp
    title: graph/steiner_tree.hpp
  - icon: ':heavy_check_mark:'
    path: knapsack/subset_sum.hpp
    title: knapsack/subset_sum.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/hafnian.hpp
    title: linalg/hafnian.hpp
  - icon: ':warning:'
    path: setfunc/online/online_or_convolution.hpp
    title: setfunc/online/online_or_convolution.hpp
  - icon: ':warning:'
    path: setfunc/online/online_subset_mobius.hpp
    title: setfunc/online/online_subset_mobius.hpp
  - icon: ':warning:'
    path: setfunc/online/online_subset_zeta.hpp
    title: setfunc/online/online_subset_zeta.hpp
  - icon: ':warning:'
    path: setfunc/submask_range_query.hpp
    title: setfunc/submask_range_query.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/enum_partitions.test.cpp
    title: test/1_mytest/enum_partitions.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/subset_sum.test.cpp
    title: test/1_mytest/subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/114.test.cpp
    title: test/3_yukicoder/114.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1263.test.cpp
    title: test/3_yukicoder/1263.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/4_2.test.cpp
    title: test/3_yukicoder/4_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DPL_2_A.test.cpp
    title: test/4_aoj/DPL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
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
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  UINT s;\n  all_subset(UINT s) : s(s)\
    \ {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT operator*()\
    \ const { return t; }\n    void operator++() {\n      done = (t == 0);\n     \
    \ t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return !done;\
    \ }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const {\
    \ return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ? -1ULL\
    \ : (1ULL << n) - 1; }\n#line 2 \"enumerate/bits.hpp\"\ntemplate <typename BS,\
    \ typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F&& f) {\n  if\
    \ (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p <\
    \ R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename UINT,\
    \ typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n"
  code: "#include \"other/bit.hpp\"\ntemplate <typename BS, typename F>\nvoid enumerate_bits_bitset(BS&\
    \ b, int L, int R, F&& f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L :\
    \ b._Find_next(L));\n  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n\
    \  }\n}\n\ntemplate <typename UINT, typename F>\ninline void enumerate_all_bit(UINT\
    \ s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  while (s) {\n   \
    \ f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename UINT, bool inc_empty,\
    \ typename F>\ninline void enumerate_all_subset(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  for (UINT t = s; t; t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n\
    }\n"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: enumerate/bits.hpp
  requiredBy:
  - linalg/hafnian.hpp
  - graph/count/count_cycle.hpp
  - graph/steiner_tree.hpp
  - graph/minimum_hamiltonian_cycle.hpp
  - setfunc/online/online_subset_zeta.hpp
  - setfunc/online/online_subset_mobius.hpp
  - setfunc/online/online_or_convolution.hpp
  - setfunc/submask_range_query.hpp
  - enumerate/partition.hpp
  - knapsack/subset_sum.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/subset_sum.test.cpp
  - test/1_mytest/enum_partitions.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - test/4_aoj/DPL_2_A.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/3_yukicoder/2507.test.cpp
  - test/3_yukicoder/1263.test.cpp
  - test/3_yukicoder/4_2.test.cpp
  - test/3_yukicoder/114.test.cpp
documentation_of: enumerate/bits.hpp
layout: document
redirect_from:
- /library/enumerate/bits.hpp
- /library/enumerate/bits.hpp.html
title: enumerate/bits.hpp
---
