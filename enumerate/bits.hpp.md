---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: enumerate/maximal_independent_set.hpp
    title: enumerate/maximal_independent_set.hpp
  - icon: ':question:'
    path: enumerate/partition.hpp
    title: enumerate/partition.hpp
  - icon: ':x:'
    path: graph/count/count_cycle.hpp
    title: graph/count/count_cycle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/minimum_hamiltonian_cycle.hpp
    title: graph/minimum_hamiltonian_cycle.hpp
  - icon: ':x:'
    path: graph/steiner_tree.hpp
    title: graph/steiner_tree.hpp
  - icon: ':heavy_check_mark:'
    path: knapsack/subset_sum.hpp
    title: knapsack/subset_sum.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/hafnian.hpp
    title: linalg/hafnian.hpp
  - icon: ':warning:'
    path: setfunc/boolean_range_add_point_get.hpp
    title: setfunc/boolean_range_add_point_get.hpp
  - icon: ':warning:'
    path: setfunc/online/online_or_convolution.hpp
    title: setfunc/online/online_or_convolution.hpp
  - icon: ':warning:'
    path: setfunc/online/online_subset_mobius.hpp
    title: setfunc/online/online_subset_mobius.hpp
  - icon: ':warning:'
    path: setfunc/online/online_subset_zeta.hpp
    title: setfunc/online/online_subset_zeta.hpp
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
  - icon: ':x:'
    path: test/3_yukicoder/114.test.cpp
    title: test/3_yukicoder/114.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1263.test.cpp
    title: test/3_yukicoder/1263.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/4_2.test.cpp
    title: test/3_yukicoder/4_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/DPL_2_A.test.cpp
    title: test/4_aoj/DPL_2_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/enumerate/bits.hpp
  bundledCode: "#line 1 \"enumerate/bits.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/enumerate/bits.hpp\n\
    template <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int\
    \ R, F&& f) {\n  if (L >= len(b)) return;\n  bool end = false;\n  int p = (b[L]\
    \ ? L : b._Find_next(L));\n  while (p < R) {\n    f(p, end);\n    if (end) break;\n\
    \    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename UINT, typename F>\ninline\
    \ void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  bool end = false;\n  while (s) {\n    f(lowbit(s), end);\n    if (end) break;\n\
    \    s &= s - 1;\n  }\n}\n\ntemplate <typename UINT, bool inc_empty, typename\
    \ F>\ninline void enumerate_all_subset(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  bool end = false;\n  for (UINT t = s; t; t = (t - 1) & s) {\n    f(t, end);\n\
    \    if (end) break;\n  }\n  if constexpr (inc_empty) {\n    if (!end) f(UINT(0),\
    \ end);\n  }\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/enumerate/bits.hpp\n\
    template <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int\
    \ R, F&& f) {\n  if (L >= len(b)) return;\n  bool end = false;\n  int p = (b[L]\
    \ ? L : b._Find_next(L));\n  while (p < R) {\n    f(p, end);\n    if (end) break;\n\
    \    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename UINT, typename F>\ninline\
    \ void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  bool end = false;\n  while (s) {\n    f(lowbit(s), end);\n    if (end) break;\n\
    \    s &= s - 1;\n  }\n}\n\ntemplate <typename UINT, bool inc_empty, typename\
    \ F>\ninline void enumerate_all_subset(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  bool end = false;\n  for (UINT t = s; t; t = (t - 1) & s) {\n    f(t, end);\n\
    \    if (end) break;\n  }\n  if constexpr (inc_empty) {\n    if (!end) f(UINT(0),\
    \ end);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/bits.hpp
  requiredBy:
  - setfunc/online/online_subset_mobius.hpp
  - setfunc/online/online_subset_zeta.hpp
  - setfunc/online/online_or_convolution.hpp
  - setfunc/boolean_range_add_point_get.hpp
  - knapsack/subset_sum.hpp
  - enumerate/maximal_independent_set.hpp
  - enumerate/partition.hpp
  - graph/steiner_tree.hpp
  - graph/minimum_hamiltonian_cycle.hpp
  - graph/count/count_cycle.hpp
  - linalg/hafnian.hpp
  timestamp: '2026-11-16 12:41:54+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - test/3_yukicoder/1263.test.cpp
  - test/3_yukicoder/4_2.test.cpp
  - test/3_yukicoder/114.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/3_yukicoder/2507.test.cpp
  - test/1_mytest/enum_partitions.test.cpp
  - test/1_mytest/subset_sum.test.cpp
  - test/4_aoj/DPL_2_A.test.cpp
documentation_of: enumerate/bits.hpp
layout: document
redirect_from:
- /library/enumerate/bits.hpp
- /library/enumerate/bits.hpp.html
title: enumerate/bits.hpp
---
