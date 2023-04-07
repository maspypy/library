---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/minimum_hamiltonian_cycle.hpp
    title: graph/minimum_hamiltonian_cycle.hpp
  - icon: ':heavy_check_mark:'
    path: graph/steiner_tree.hpp
    title: graph/steiner_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_2_A.test.cpp
    title: test/aoj/DPL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/114.test.cpp
    title: test/yukicoder/114.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/bits.hpp\"\ntemplate <typename F>\nvoid enumerate_bits(int\
    \ s, F f) {\n  while (s) {\n    int i = __builtin_ctz(s);\n    f(i);\n    s ^=\
    \ 1 << i;\n  }\n}\n\ntemplate <typename F>\nvoid enumerate_bits(u64 s, F f) {\n\
    \  while (s) {\n    int i = __builtin_ctzll(s);\n    f(i);\n    s ^= 1 << i;\n\
    \  }\n}\n\ntemplate <typename BS, typename F>\nvoid enumerate_bits_bitset(BS&\
    \ b, int L, int R, F f) {\n  int p = (b[L] ? L : b._Find_next(L));\n  while (p\
    \ < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n"
  code: "template <typename F>\nvoid enumerate_bits(int s, F f) {\n  while (s) {\n\
    \    int i = __builtin_ctz(s);\n    f(i);\n    s ^= 1 << i;\n  }\n}\n\ntemplate\
    \ <typename F>\nvoid enumerate_bits(u64 s, F f) {\n  while (s) {\n    int i =\
    \ __builtin_ctzll(s);\n    f(i);\n    s ^= 1 << i;\n  }\n}\n\ntemplate <typename\
    \ BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F f) {\n  int\
    \ p = (b[L] ? L : b._Find_next(L));\n  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n\
    \  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/bits.hpp
  requiredBy:
  - graph/minimum_hamiltonian_cycle.hpp
  - graph/steiner_tree.hpp
  timestamp: '2023-04-08 00:43:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_2_A.test.cpp
  - test/yukicoder/114.test.cpp
documentation_of: enumerate/bits.hpp
layout: document
redirect_from:
- /library/enumerate/bits.hpp
- /library/enumerate/bits.hpp.html
title: enumerate/bits.hpp
---
