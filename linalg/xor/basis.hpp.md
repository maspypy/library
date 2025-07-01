---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: nt/nimber/solve_quadratic.hpp
    title: nt/nimber/solve_quadratic.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/nimber.test.cpp
    title: test/1_mytest/nimber.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2895.test.cpp
    title: test/3_yukicoder/2895.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/xor/basis.hpp\"\n\n// basis[i]: i \u756A\u76EE\u306B\
    \u8FFD\u52A0\u6210\u529F\u3057\u305F\u3082\u306E. \u5225\u306E\u30E9\u30D9\u30EB\
    \u304C\u3042\u308B\u306A\u3089\u5916\u3067\u7BA1\u7406\u3059\u308B.\n// array<UINT,\
    \ MAX_DIM> rbasis: \u4E0A\u4E09\u89D2\u5316\u3055\u308C\u305F\u57FA\u5E95. [i][i]==1.\n\
    // way<UINT,UINT> rbasis[i] \u3092 basis[j] \u3067\u4F5C\u308B\u65B9\u6CD5\ntemplate\
    \ <int MAX_DIM>\nstruct Basis {\n  static_assert(MAX_DIM <= 128);\n  using UINT\
    \ = conditional_t<(MAX_DIM <= 32), u32, conditional_t<(MAX_DIM <= 64), u64, u128>>;\n\
    \  int rank;\n  array<UINT, MAX_DIM> basis;\n  array<UINT, MAX_DIM> rbasis;\n\
    \  array<UINT, MAX_DIM> way;\n  Basis() : rank(0), basis{}, rbasis{}, way{} {}\n\
    \n  // return : (sum==x \u306B\u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5\
    )\n  pair<bool, UINT> solve(UINT x) {\n    UINT c = 0;\n    FOR(i, MAX_DIM) {\n\
    \      if ((x >> i & 1) && (rbasis[i] != 0)) { c ^= way[i], x ^= rbasis[i]; }\n\
    \    }\n    if (x == 0) return {true, c};\n    return {false, 0};\n  }\n\n  //\
    \ return : (sum==x \u306B\u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5).\
    \ false \u306E\u5834\u5408\u306B\u306F\u8FFD\u52A0\u3059\u308B\n  pair<bool, UINT>\
    \ solve_or_add(UINT x) {\n    UINT y = x, c = 0;\n    FOR(i, MAX_DIM) {\n    \
    \  if ((x >> i & 1) && (rbasis[i] != 0)) { c ^= way[i], x ^= rbasis[i]; }\n  \
    \  }\n    if (x == 0) return {true, c};\n    int k = lowbit(x);\n    basis[rank]\
    \ = y, rbasis[k] = x, way[k] = c | UINT(1) << rank, ++rank;\n    return {false,\
    \ 0};\n  }\n};\n"
  code: "\n// basis[i]: i \u756A\u76EE\u306B\u8FFD\u52A0\u6210\u529F\u3057\u305F\u3082\
    \u306E. \u5225\u306E\u30E9\u30D9\u30EB\u304C\u3042\u308B\u306A\u3089\u5916\u3067\
    \u7BA1\u7406\u3059\u308B.\n// array<UINT, MAX_DIM> rbasis: \u4E0A\u4E09\u89D2\u5316\
    \u3055\u308C\u305F\u57FA\u5E95. [i][i]==1.\n// way<UINT,UINT> rbasis[i] \u3092\
    \ basis[j] \u3067\u4F5C\u308B\u65B9\u6CD5\ntemplate <int MAX_DIM>\nstruct Basis\
    \ {\n  static_assert(MAX_DIM <= 128);\n  using UINT = conditional_t<(MAX_DIM <=\
    \ 32), u32, conditional_t<(MAX_DIM <= 64), u64, u128>>;\n  int rank;\n  array<UINT,\
    \ MAX_DIM> basis;\n  array<UINT, MAX_DIM> rbasis;\n  array<UINT, MAX_DIM> way;\n\
    \  Basis() : rank(0), basis{}, rbasis{}, way{} {}\n\n  // return : (sum==x \u306B\
    \u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5)\n  pair<bool, UINT> solve(UINT\
    \ x) {\n    UINT c = 0;\n    FOR(i, MAX_DIM) {\n      if ((x >> i & 1) && (rbasis[i]\
    \ != 0)) { c ^= way[i], x ^= rbasis[i]; }\n    }\n    if (x == 0) return {true,\
    \ c};\n    return {false, 0};\n  }\n\n  // return : (sum==x \u306B\u3067\u304D\
    \u308B\u304B, \u305D\u306E\u65B9\u6CD5). false \u306E\u5834\u5408\u306B\u306F\u8FFD\
    \u52A0\u3059\u308B\n  pair<bool, UINT> solve_or_add(UINT x) {\n    UINT y = x,\
    \ c = 0;\n    FOR(i, MAX_DIM) {\n      if ((x >> i & 1) && (rbasis[i] != 0)) {\
    \ c ^= way[i], x ^= rbasis[i]; }\n    }\n    if (x == 0) return {true, c};\n \
    \   int k = lowbit(x);\n    basis[rank] = y, rbasis[k] = x, way[k] = c | UINT(1)\
    \ << rank, ++rank;\n    return {false, 0};\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/basis.hpp
  requiredBy:
  - nt/nimber/solve_quadratic.hpp
  timestamp: '2024-09-21 20:54:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/nimber.test.cpp
  - test/3_yukicoder/2895.test.cpp
documentation_of: linalg/xor/basis.hpp
layout: document
redirect_from:
- /library/linalg/xor/basis.hpp
- /library/linalg/xor/basis.hpp.html
title: linalg/xor/basis.hpp
---
