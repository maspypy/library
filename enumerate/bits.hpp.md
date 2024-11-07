---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/count/count_cycle.hpp
    title: graph/count/count_cycle.hpp
  - icon: ':x:'
    path: graph/minimum_hamiltonian_cycle.hpp
    title: graph/minimum_hamiltonian_cycle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/steiner_tree.hpp
    title: graph/steiner_tree.hpp
  - icon: ':question:'
    path: knapsack/subset_sum.hpp
    title: knapsack/subset_sum.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/hafnian.hpp
    title: linalg/hafnian.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/subset_sum.test.cpp
    title: test/1_mytest/subset_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/114.test.cpp
    title: test/3_yukicoder/114.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/4_2.test.cpp
    title: test/3_yukicoder/4_2.test.cpp
  - icon: ':x:'
    path: test/4_aoj/DPL_2_A.test.cpp
    title: test/4_aoj/DPL_2_A.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc180e.test.cpp
    title: test/5_atcoder/abc180e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/bits.hpp\"\ntemplate <typename F>\nvoid enumerate_bits_32(u32\
    \ s, F f) {\n  while (s) {\n    int i = __builtin_ctz(s);\n    f(i);\n    s ^=\
    \ 1 << i;\n  }\n}\n\ntemplate <typename F>\nvoid enumerate_bits_64(u64 s, F f)\
    \ {\n  while (s) {\n    int i = __builtin_ctzll(s);\n    f(i);\n    s ^= u64(1)\
    \ << i;\n  }\n}\n\ntemplate <typename BS, typename F>\nvoid enumerate_bits_bitset(BS&\
    \ b, int L, int R, F f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p\
    \ < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n"
  code: "template <typename F>\nvoid enumerate_bits_32(u32 s, F f) {\n  while (s)\
    \ {\n    int i = __builtin_ctz(s);\n    f(i);\n    s ^= 1 << i;\n  }\n}\n\ntemplate\
    \ <typename F>\nvoid enumerate_bits_64(u64 s, F f) {\n  while (s) {\n    int i\
    \ = __builtin_ctzll(s);\n    f(i);\n    s ^= u64(1) << i;\n  }\n}\n\ntemplate\
    \ <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F\
    \ f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n\
    \    p = b._Find_next(p);\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/bits.hpp
  requiredBy:
  - knapsack/subset_sum.hpp
  - linalg/hafnian.hpp
  - graph/steiner_tree.hpp
  - graph/count/count_cycle.hpp
  - graph/minimum_hamiltonian_cycle.hpp
  timestamp: '2023-05-04 20:25:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/114.test.cpp
  - test/3_yukicoder/4_2.test.cpp
  - test/3_yukicoder/2507.test.cpp
  - test/4_aoj/DPL_2_A.test.cpp
  - test/5_atcoder/abc180e.test.cpp
  - test/1_mytest/subset_sum.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
documentation_of: enumerate/bits.hpp
layout: document
redirect_from:
- /library/enumerate/bits.hpp
- /library/enumerate/bits.hpp.html
title: enumerate/bits.hpp
---
