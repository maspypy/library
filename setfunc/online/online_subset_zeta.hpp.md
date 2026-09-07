---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: setfunc/online/online_or_convolution.hpp
    title: setfunc/online/online_or_convolution.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"other/bit.hpp\"\n\nint\
    \ popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(u64 x) { return __builtin_popcountll(x); }\nint popcnt_sgn(int\
    \ x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 : 1); }\nint popcnt_sgn(u32\
    \ x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\nint popcnt_sgn(ll x) { return\
    \ (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x)\
    \ & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x)\
    \ { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return\
    \ (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0\
    \ ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x == 0 ? -1\
    \ : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32 x) { return\
    \ (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1 : __builtin_ctzll(x));\
    \ }\n\ntemplate <typename T>\nT kth_bit(int k) {\n  assert(0 <= k && k < int(8\
    \ * sizeof(T)));\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return x >> k &\
    \ 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  UINT s;\n  all_bit(UINT s) : s(s) {}\n  struct iter {\n    UINT s;\n    int\
    \ operator*() const { return lowbit(s); }\n    void operator++() { s &= s - 1;\
    \ }\n    bool operator!=(nullptr_t) const { return s; }\n  };\n  iter begin()\
    \ const { return {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate\
    \ <typename UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  UINT s;\n  all_subset(UINT s) : s(s) {}\n  struct iter {\n    UINT s, t;\n\
    \    bool done = false;\n    UINT operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"enumerate/bits.hpp\"\n\
    template <typename BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int\
    \ R, F&& f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename\
    \ UINT, typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n#line 3 \"setfunc/online/online_subset_zeta.hpp\"\
    \n\n/*\nsegtree \u3092\u8003\u3048\u308B\n\u73FE\u5728\u306E\u30DD\u30A4\u30F3\
    \u30BF\u306E\u4F4D\u7F6E\u304C\u3042\u308B\n\u3082\u3046\u5168\u90E8\u306E\u5024\
    \u304C\u8AAD\u307E\u308C\u305F subtree \u3067\u306F\u30BC\u30FC\u30BF\u3055\u308C\
    \u305F\u72B6\u614B\u306B\u3057\u3066\u304A\u304F\n*/\ntemplate <typename T>\n\
    struct Online_Subset_Zeta {\n  int n;\n  int p = 0;\n  vc<T> A;\n  Online_Subset_Zeta(int\
    \ LOG) : n(LOG), A(1 << n) {}\n\n  // set a[i], return zeta(a)[i]\n  T set(int\
    \ i, T a) {\n    assert(p == i);\n    T ans = assume(i, 0) + a;\n    A[p++] =\
    \ a;\n    int K = lowbit(p);\n    for (int k = 0; k < K; ++k)\n      for (int\
    \ j = p - (1 << k); j < p; ++j) A[j] += A[j - (1 << k)];\n    return ans;\n  }\n\
    \n  // assume a[i], return zeta(a)[i]. not increment the pointer.\n  T assume(int\
    \ i, T ai) {\n    assert(p == i);\n    T ans = ai;\n    enumerate_all_bit<u32>(i,\
    \ [&](int j) -> void { ans += A[i - (1 << j)]; });\n    return ans;\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n#include \"enumerate/bits.hpp\"\n\n/*\nsegtree\
    \ \u3092\u8003\u3048\u308B\n\u73FE\u5728\u306E\u30DD\u30A4\u30F3\u30BF\u306E\u4F4D\
    \u7F6E\u304C\u3042\u308B\n\u3082\u3046\u5168\u90E8\u306E\u5024\u304C\u8AAD\u307E\
    \u308C\u305F subtree \u3067\u306F\u30BC\u30FC\u30BF\u3055\u308C\u305F\u72B6\u614B\
    \u306B\u3057\u3066\u304A\u304F\n*/\ntemplate <typename T>\nstruct Online_Subset_Zeta\
    \ {\n  int n;\n  int p = 0;\n  vc<T> A;\n  Online_Subset_Zeta(int LOG) : n(LOG),\
    \ A(1 << n) {}\n\n  // set a[i], return zeta(a)[i]\n  T set(int i, T a) {\n  \
    \  assert(p == i);\n    T ans = assume(i, 0) + a;\n    A[p++] = a;\n    int K\
    \ = lowbit(p);\n    for (int k = 0; k < K; ++k)\n      for (int j = p - (1 <<\
    \ k); j < p; ++j) A[j] += A[j - (1 << k)];\n    return ans;\n  }\n\n  // assume\
    \ a[i], return zeta(a)[i]. not increment the pointer.\n  T assume(int i, T ai)\
    \ {\n    assert(p == i);\n    T ans = ai;\n    enumerate_all_bit<u32>(i, [&](int\
    \ j) -> void { ans += A[i - (1 << j)]; });\n    return ans;\n  }\n};\n"
  dependsOn:
  - other/bit.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: setfunc/online/online_subset_zeta.hpp
  requiredBy:
  - setfunc/online/online_or_convolution.hpp
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/online/online_subset_zeta.hpp
layout: document
redirect_from:
- /library/setfunc/online/online_subset_zeta.hpp
- /library/setfunc/online/online_subset_zeta.hpp.html
title: setfunc/online/online_subset_zeta.hpp
---
