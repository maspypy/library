---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/nimber/solve_quadratic.hpp
    title: nt/nimber/solve_quadratic.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/nimber.test.cpp
    title: test/1_mytest/nimber.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2895.test.cpp
    title: test/3_yukicoder/2895.test.cpp
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
    \ : (1ULL << n) - 1; }\n#line 2 \"linalg/xor/basis.hpp\"\n\n// basis[i]: i \u756A\
    \u76EE\u306B\u8FFD\u52A0\u6210\u529F\u3057\u305F\u3082\u306E. \u5225\u306E\u30E9\
    \u30D9\u30EB\u304C\u3042\u308B\u306A\u3089\u5916\u3067\u7BA1\u7406\u3059\u308B\
    .\n// array<UINT, MAX_DIM> rbasis: \u4E0A\u4E09\u89D2\u5316\u3055\u308C\u305F\u57FA\
    \u5E95. [i][i]==1.\n// way<UINT,UINT> rbasis[i] \u3092 basis[j] \u3067\u4F5C\u308B\
    \u65B9\u6CD5\ntemplate <int MAX_DIM>\nstruct Basis {\n  static_assert(MAX_DIM\
    \ <= 128);\n  using UINT = conditional_t<(MAX_DIM <= 32), u32,\n             \
    \                conditional_t<(MAX_DIM <= 64), u64, u128>>;\n  int rank;\n  array<UINT,\
    \ MAX_DIM> basis;\n  array<UINT, MAX_DIM> rbasis;\n  array<UINT, MAX_DIM> way;\n\
    \  Basis() : rank(0), basis{}, rbasis{}, way{} {}\n\n  // return : (sum==x \u306B\
    \u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5)\n  pair<bool, UINT> solve(UINT\
    \ x) {\n    UINT c = 0;\n    FOR(i, MAX_DIM) {\n      if ((x >> i & 1) && (rbasis[i]\
    \ != 0)) {\n        c ^= way[i], x ^= rbasis[i];\n      }\n    }\n    if (x ==\
    \ 0) return {true, c};\n    return {false, 0};\n  }\n\n  // return : (sum==x \u306B\
    \u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5). false \u306E\u5834\u5408\u306B\
    \u306F\u8FFD\u52A0\u3059\u308B\n  pair<bool, UINT> solve_or_add(UINT x) {\n  \
    \  UINT y = x, c = 0;\n    FOR(i, MAX_DIM) {\n      if ((x >> i & 1) && (rbasis[i]\
    \ != 0)) {\n        c ^= way[i], x ^= rbasis[i];\n      }\n    }\n    if (x ==\
    \ 0) return {true, c};\n    int k = lowbit(x);\n    basis[rank] = y, rbasis[k]\
    \ = x, way[k] = c | UINT(1) << rank, ++rank;\n    return {false, 0};\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n\n// basis[i]: i \u756A\u76EE\u306B\u8FFD\u52A0\
    \u6210\u529F\u3057\u305F\u3082\u306E. \u5225\u306E\u30E9\u30D9\u30EB\u304C\u3042\
    \u308B\u306A\u3089\u5916\u3067\u7BA1\u7406\u3059\u308B.\n// array<UINT, MAX_DIM>\
    \ rbasis: \u4E0A\u4E09\u89D2\u5316\u3055\u308C\u305F\u57FA\u5E95. [i][i]==1.\n\
    // way<UINT,UINT> rbasis[i] \u3092 basis[j] \u3067\u4F5C\u308B\u65B9\u6CD5\ntemplate\
    \ <int MAX_DIM>\nstruct Basis {\n  static_assert(MAX_DIM <= 128);\n  using UINT\
    \ = conditional_t<(MAX_DIM <= 32), u32,\n                             conditional_t<(MAX_DIM\
    \ <= 64), u64, u128>>;\n  int rank;\n  array<UINT, MAX_DIM> basis;\n  array<UINT,\
    \ MAX_DIM> rbasis;\n  array<UINT, MAX_DIM> way;\n  Basis() : rank(0), basis{},\
    \ rbasis{}, way{} {}\n\n  // return : (sum==x \u306B\u3067\u304D\u308B\u304B,\
    \ \u305D\u306E\u65B9\u6CD5)\n  pair<bool, UINT> solve(UINT x) {\n    UINT c =\
    \ 0;\n    FOR(i, MAX_DIM) {\n      if ((x >> i & 1) && (rbasis[i] != 0)) {\n \
    \       c ^= way[i], x ^= rbasis[i];\n      }\n    }\n    if (x == 0) return {true,\
    \ c};\n    return {false, 0};\n  }\n\n  // return : (sum==x \u306B\u3067\u304D\
    \u308B\u304B, \u305D\u306E\u65B9\u6CD5). false \u306E\u5834\u5408\u306B\u306F\u8FFD\
    \u52A0\u3059\u308B\n  pair<bool, UINT> solve_or_add(UINT x) {\n    UINT y = x,\
    \ c = 0;\n    FOR(i, MAX_DIM) {\n      if ((x >> i & 1) && (rbasis[i] != 0)) {\n\
    \        c ^= way[i], x ^= rbasis[i];\n      }\n    }\n    if (x == 0) return\
    \ {true, c};\n    int k = lowbit(x);\n    basis[rank] = y, rbasis[k] = x, way[k]\
    \ = c | UINT(1) << rank, ++rank;\n    return {false, 0};\n  }\n};\n"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: linalg/xor/basis.hpp
  requiredBy:
  - nt/nimber/solve_quadratic.hpp
  timestamp: '2026-07-28 12:25:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
