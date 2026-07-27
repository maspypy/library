---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':question:'
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
    \  UINT s;\n  struct iter {\n    UINT s;\n    int operator*() const { return lowbit(s);\
    \ }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t) const\
    \ { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t end()\
    \ const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  UINT s;\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) { return n == 64 ?\
    \ -1ULL : (1ULL << n) - 1; }\n#line 2 \"enumerate/bits.hpp\"\ntemplate <typename\
    \ BS, typename F>\nvoid enumerate_bits_bitset(BS& b, int L, int R, F&& f) {\n\
    \  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n  while\
    \ (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n\ntemplate <typename\
    \ UINT, typename F>\ninline void enumerate_all_bit(UINT s, F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  while (s) {\n    f(lowbit(s));\n    s &= s - 1;\n  }\n}\n\ntemplate <typename\
    \ UINT, bool inc_empty, typename F>\ninline void enumerate_all_subset(UINT s,\
    \ F&& f) {\n  static_assert(is_unsigned<UINT>::value);\n  for (UINT t = s; t;\
    \ t = (t - 1) & s) f(t);\n  if constexpr (inc_empty) f(0);\n}\n#line 3 \"setfunc/online/online_subset_mobius.hpp\"\
    \n\ntemplate <typename T>\nstruct Online_Subset_Mobius {\n  int n;\n  int p =\
    \ 0;\n  vc<T> A;\n  Online_Subset_Mobius(int LOG) : n(LOG), A(1 << n) {}\n\n \
    \ // set a[i], return zeta(a)[i]\n  T set(int i, T a) {\n    assert(p == i);\n\
    \    T ans = assume(i, 0) + a;\n    A[p++] = a;\n    int K = lowbit(p);\n    for\
    \ (int k = 0; k < K; ++k)\n      for (int j = p - (1 << k); j < p; ++j) A[j] -=\
    \ A[j - (1 << k)];\n    return ans;\n  }\n\n  // assume a[i], return zeta(a)[i].\
    \ not increment the pointer.\n  T assume(int i, T ai) {\n    assert(p == i);\n\
    \    T ans = ai;\n    enumerate_all_bit<u32>(i, [&](int j) -> vood { ans -= A[i\
    \ - (1 << j)]; });\n    return ans;\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n#include \"enumerate/bits.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Online_Subset_Mobius {\n  int n;\n  int p = 0;\n  vc<T> A;\n  Online_Subset_Mobius(int\
    \ LOG) : n(LOG), A(1 << n) {}\n\n  // set a[i], return zeta(a)[i]\n  T set(int\
    \ i, T a) {\n    assert(p == i);\n    T ans = assume(i, 0) + a;\n    A[p++] =\
    \ a;\n    int K = lowbit(p);\n    for (int k = 0; k < K; ++k)\n      for (int\
    \ j = p - (1 << k); j < p; ++j) A[j] -= A[j - (1 << k)];\n    return ans;\n  }\n\
    \n  // assume a[i], return zeta(a)[i]. not increment the pointer.\n  T assume(int\
    \ i, T ai) {\n    assert(p == i);\n    T ans = ai;\n    enumerate_all_bit<u32>(i,\
    \ [&](int j) -> vood { ans -= A[i - (1 << j)]; });\n    return ans;\n  }\n};\n"
  dependsOn:
  - other/bit.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: setfunc/online/online_subset_mobius.hpp
  requiredBy:
  - setfunc/online/online_or_convolution.hpp
  timestamp: '2026-07-26 20:34:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/online/online_subset_mobius.hpp
layout: document
redirect_from:
- /library/setfunc/online/online_subset_mobius.hpp
- /library/setfunc/online/online_subset_mobius.hpp.html
title: setfunc/online/online_subset_mobius.hpp
---
