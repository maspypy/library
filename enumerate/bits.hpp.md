---
data:
  _extendedDependsOn: []
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
  bundledCode: "#line 1 \"enumerate/bits.hpp\"\ntemplate <typename BS, typename F>\n\
    void enumerate_bits_bitset(BS& b, int L, int R, F&& f) {\n  if (L >= len(b)) return;\n\
    \  int p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n    p\
    \ = b._Find_next(p);\n  }\n}\n\ntemplate <typename UINT, typename F>\ninline void\
    \ enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n"
  code: "template <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int\
    \ L, int R, F&& f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename\
    \ UINT, typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/bits.hpp
  requiredBy:
  - knapsack/subset_sum.hpp
  - enumerate/partition.hpp
  - setfunc/submask_range_query.hpp
  - setfunc/online/online_subset_zeta.hpp
  - setfunc/online/online_subset_mobius.hpp
  - setfunc/online/online_or_convolution.hpp
  - linalg/hafnian.hpp
  - graph/steiner_tree.hpp
  - graph/count/count_cycle.hpp
  - graph/minimum_hamiltonian_cycle.hpp
  timestamp: '2025-12-16 20:51:20+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1263.test.cpp
  - test/3_yukicoder/2507.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/3_yukicoder/114.test.cpp
  - test/3_yukicoder/4_2.test.cpp
  - test/1_mytest/enum_partitions.test.cpp
  - test/1_mytest/subset_sum.test.cpp
  - test/4_aoj/DPL_2_A.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
documentation_of: enumerate/bits.hpp
layout: document
redirect_from:
- /library/enumerate/bits.hpp
- /library/enumerate/bits.hpp.html
title: enumerate/bits.hpp
---
