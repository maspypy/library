---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/sum_over_bit_positions.test.cpp
    title: test/1_mytest/sum_over_bit_positions.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qoj.ac/contest/1784/problem/9244
  bundledCode: "#line 1 \"ds/sum_over_bit_positions.hpp\"\n\n// https://qoj.ac/contest/1784/problem/9244\n\
    // sum bitset[i]*wt[i]\n// T \u306F 11bit sum \u304C\u304A\u3055\u307E\u308C\u3070\
    \ ok\n// (N=Q=100000:0.9 sec)\ntemplate <typename T, int MAXSIZE>\nstruct Sum_Over_Bit_Positions\
    \ {\n  int N;\n  vc<T> base;\n  static T table[MAXSIZE / 64 * 6 + 10][1 << 11];\n\
    \n  template <typename F>\n  Sum_Over_Bit_Positions(int N, F f) : N(N) {\n   \
    \ base.resize(N);\n    assert(0 <= N && N <= MAXSIZE);\n    int NB = (N + 63)\
    \ / 64;\n    FOR(block, NB) {\n      FOR(k, 6) {\n        int b = 6 * block +\
    \ k;\n        FOR(i, 11) {\n          int idx = 64 * block + 11 * k + i;\n   \
    \       T x = 0;\n          if ((k < 5 || i < 9) && idx < N) x = base[idx] = f(idx);\n\
    \          FOR(s, 1 << i) { table[b][s | 1 << i] = table[b][s] + x; }\n      \
    \  }\n      }\n    }\n  }\n\n  // bitset \u306E [l,r) \u90E8\u5206\n  template\
    \ <typename SUM_TYPE>\n  SUM_TYPE query(My_Bitset &x, int l, int r) {\n    SUM_TYPE\
    \ ANS = 0;\n    while (l < r && (l & 63)) {\n      if (x[l]) ANS += base[l];\n\
    \      l++;\n    }\n    while (l < r && (r & 63)) {\n      --r;\n      if (x[r])\
    \ ANS += base[r];\n    }\n    if (l == r) return ANS;\n    l /= 64, r /= 64;\n\
    \    FOR(b, l, r) {\n      u64 s = x.dat[b];\n      ANS += table[b * 6 + 0][s\
    \ >> 0 & 2047];\n      ANS += table[b * 6 + 1][s >> 11 & 2047];\n      ANS +=\
    \ table[b * 6 + 2][s >> 22 & 2047];\n      ANS += table[b * 6 + 3][s >> 33 & 2047];\n\
    \      ANS += table[b * 6 + 4][s >> 44 & 2047];\n      ANS += table[b * 6 + 5][s\
    \ >> 55 & 2047];\n    }\n    return ANS;\n  }\n};\ntemplate <typename T, int MAXSIZE>\n\
    T Sum_Over_Bit_Positions<T, MAXSIZE>::table[MAXSIZE / 64 * 6 + 10][1 << 11];\n"
  code: "\n// https://qoj.ac/contest/1784/problem/9244\n// sum bitset[i]*wt[i]\n//\
    \ T \u306F 11bit sum \u304C\u304A\u3055\u307E\u308C\u3070 ok\n// (N=Q=100000:0.9\
    \ sec)\ntemplate <typename T, int MAXSIZE>\nstruct Sum_Over_Bit_Positions {\n\
    \  int N;\n  vc<T> base;\n  static T table[MAXSIZE / 64 * 6 + 10][1 << 11];\n\n\
    \  template <typename F>\n  Sum_Over_Bit_Positions(int N, F f) : N(N) {\n    base.resize(N);\n\
    \    assert(0 <= N && N <= MAXSIZE);\n    int NB = (N + 63) / 64;\n    FOR(block,\
    \ NB) {\n      FOR(k, 6) {\n        int b = 6 * block + k;\n        FOR(i, 11)\
    \ {\n          int idx = 64 * block + 11 * k + i;\n          T x = 0;\n      \
    \    if ((k < 5 || i < 9) && idx < N) x = base[idx] = f(idx);\n          FOR(s,\
    \ 1 << i) { table[b][s | 1 << i] = table[b][s] + x; }\n        }\n      }\n  \
    \  }\n  }\n\n  // bitset \u306E [l,r) \u90E8\u5206\n  template <typename SUM_TYPE>\n\
    \  SUM_TYPE query(My_Bitset &x, int l, int r) {\n    SUM_TYPE ANS = 0;\n    while\
    \ (l < r && (l & 63)) {\n      if (x[l]) ANS += base[l];\n      l++;\n    }\n\
    \    while (l < r && (r & 63)) {\n      --r;\n      if (x[r]) ANS += base[r];\n\
    \    }\n    if (l == r) return ANS;\n    l /= 64, r /= 64;\n    FOR(b, l, r) {\n\
    \      u64 s = x.dat[b];\n      ANS += table[b * 6 + 0][s >> 0 & 2047];\n    \
    \  ANS += table[b * 6 + 1][s >> 11 & 2047];\n      ANS += table[b * 6 + 2][s >>\
    \ 22 & 2047];\n      ANS += table[b * 6 + 3][s >> 33 & 2047];\n      ANS += table[b\
    \ * 6 + 4][s >> 44 & 2047];\n      ANS += table[b * 6 + 5][s >> 55 & 2047];\n\
    \    }\n    return ANS;\n  }\n};\ntemplate <typename T, int MAXSIZE>\nT Sum_Over_Bit_Positions<T,\
    \ MAXSIZE>::table[MAXSIZE / 64 * 6 + 10][1 << 11];\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/sum_over_bit_positions.hpp
  requiredBy: []
  timestamp: '2024-10-14 23:15:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/sum_over_bit_positions.test.cpp
documentation_of: ds/sum_over_bit_positions.hpp
layout: document
redirect_from:
- /library/ds/sum_over_bit_positions.hpp
- /library/ds/sum_over_bit_positions.hpp.html
title: ds/sum_over_bit_positions.hpp
---
