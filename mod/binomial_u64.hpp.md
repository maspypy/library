---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"mod/binomial_u64.hpp\"\
    \n\nstruct Binomial_u64 {\n  int LIM;\n  vc<u64> fact, ifact, exp;\n  Binomial_u64(int\
    \ LIM)\n      : LIM(LIM), fact(LIM + 1), ifact(LIM + 1), exp(LIM + 1) {\n    fact[0]\
    \ = 1;\n    for (int i = 1; i <= LIM; ++i) {\n      int k = lowbit(i);\n     \
    \ fact[i] = fact[i - 1] * (i >> k);\n      exp[i] = exp[i - 1] + k;\n    }\n \
    \   ifact[LIM] = mod_inv_u64(fact[LIM]);\n    for (u64 i = LIM; i >= 1; --i) {\n\
    \      int k = lowbit(i);\n      ifact[i - 1] = ifact[i] * (i >> k);\n    }\n\
    \  }\n\n  u64 C(int n, int k) {\n    assert(0 <= n);\n    if (k < 0 || n < k)\
    \ return 0;\n    int e = exp[n] - exp[k] - exp[n - k];\n    u64 x = fact[n] *\
    \ ifact[k] * ifact[n - k];\n    return x << e;\n  }\n};\n"
  code: "#include \"other/bit.hpp\"\n\nstruct Binomial_u64 {\n  int LIM;\n  vc<u64>\
    \ fact, ifact, exp;\n  Binomial_u64(int LIM)\n      : LIM(LIM), fact(LIM + 1),\
    \ ifact(LIM + 1), exp(LIM + 1) {\n    fact[0] = 1;\n    for (int i = 1; i <= LIM;\
    \ ++i) {\n      int k = lowbit(i);\n      fact[i] = fact[i - 1] * (i >> k);\n\
    \      exp[i] = exp[i - 1] + k;\n    }\n    ifact[LIM] = mod_inv_u64(fact[LIM]);\n\
    \    for (u64 i = LIM; i >= 1; --i) {\n      int k = lowbit(i);\n      ifact[i\
    \ - 1] = ifact[i] * (i >> k);\n    }\n  }\n\n  u64 C(int n, int k) {\n    assert(0\
    \ <= n);\n    if (k < 0 || n < k) return 0;\n    int e = exp[n] - exp[k] - exp[n\
    \ - k];\n    u64 x = fact[n] * ifact[k] * ifact[n - k];\n    return x << e;\n\
    \  }\n};"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: mod/binomial_u64.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/binomial_u64.hpp
layout: document
redirect_from:
- /library/mod/binomial_u64.hpp
- /library/mod/binomial_u64.hpp.html
title: mod/binomial_u64.hpp
---
