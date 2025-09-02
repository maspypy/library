---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/count/count_cycle.hpp
    title: graph/count/count_cycle.hpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/3_yukicoder/114.test.cpp
    title: test/3_yukicoder/114.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2507.test.cpp
    title: test/3_yukicoder/2507.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/4_2.test.cpp
    title: test/3_yukicoder/4_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/bits.hpp\"\ntemplate <typename BS, typename F>\n\
    void enumerate_bits_bitset(BS& b, int L, int R, F f) {\n  if (L >= len(b)) return;\n\
    \  int p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n    p\
    \ = b._Find_next(p);\n  }\n}\n"
  code: "template <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int\
    \ L, int R, F f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/bits.hpp
  requiredBy:
  - knapsack/subset_sum.hpp
  - graph/steiner_tree.hpp
  - graph/count/count_cycle.hpp
  - linalg/hafnian.hpp
  timestamp: '2025-01-04 13:02:14+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/4_2.test.cpp
  - test/3_yukicoder/2507.test.cpp
  - test/3_yukicoder/114.test.cpp
  - test/2_library_checker/linear_algebra/hafnian_of_matrix.test.cpp
  - test/1_mytest/subset_sum.test.cpp
documentation_of: enumerate/bits.hpp
layout: document
redirect_from:
- /library/enumerate/bits.hpp
- /library/enumerate/bits.hpp.html
title: enumerate/bits.hpp
---
