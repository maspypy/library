---
data:
  _extendedDependsOn:
  - icon: ':x:'
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
    \ : (1ULL << n) - 1; }\n\nu64 bit_reverse(u64 x) {\n  x = ((x & 0x5555555555555555ULL)\
    \ << 1) | ((x >> 1) & 0x5555555555555555ULL);\n  x = ((x & 0x3333333333333333ULL)\
    \ << 2) | ((x >> 2) & 0x3333333333333333ULL);\n  x = ((x & 0x0f0f0f0f0f0f0f0fULL)\
    \ << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n  x = ((x & 0x00ff00ff00ff00ffULL)\
    \ << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n  x = ((x & 0x0000ffff0000ffffULL)\
    \ << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n  x = (x << 32) | (x >> 32);\n\
    \  return x;\n}\n#line 2 \"setfunc/xor_submask_lower_bound.hpp\"\n\n// a <= b\
    \ xor (submask S) \u3068\u306A\u308B\u4E2D\u3067\u53F3\u8FBA\u306E\u6700\u5C0F\
    \n// \u306A\u3051\u308C\u3070 UINT(-1)\ntemplate <typename UINT>\nUINT xor_submask_lower_bound(UINT\
    \ a, UINT b, UINT S) {\n  // a <= (b ^ submask(S)), minimize rhs\n  b &= ~S;\n\
    \  if (a <= b) return b;\n  u32 c = b | S;\n  if (a > c) return -1;\n  u32 D =\
    \ (a ^ b) & ~S;\n  if (D == 0) return a;\n  int k = topbit(D);\n  if ((b >> k)\
    \ & 1) {\n    b |= (a & S) & ~full_mask(k + 1);\n    return b;\n  }\n  u32 X =\
    \ S & ~a;\n  X &= ~full_mask(k + 1);\n  k = lowbit(X);\n  b |= (a & S) & ~full_mask(k\
    \ + 1);\n  b |= u32(1) << k;\n  assert(a <= b);\n  return b;\n};\n"
  code: "#include \"other/bit.hpp\"\n\n// a <= b xor (submask S) \u3068\u306A\u308B\
    \u4E2D\u3067\u53F3\u8FBA\u306E\u6700\u5C0F\n// \u306A\u3051\u308C\u3070 UINT(-1)\n\
    template <typename UINT>\nUINT xor_submask_lower_bound(UINT a, UINT b, UINT S)\
    \ {\n  // a <= (b ^ submask(S)), minimize rhs\n  b &= ~S;\n  if (a <= b) return\
    \ b;\n  u32 c = b | S;\n  if (a > c) return -1;\n  u32 D = (a ^ b) & ~S;\n  if\
    \ (D == 0) return a;\n  int k = topbit(D);\n  if ((b >> k) & 1) {\n    b |= (a\
    \ & S) & ~full_mask(k + 1);\n    return b;\n  }\n  u32 X = S & ~a;\n  X &= ~full_mask(k\
    \ + 1);\n  k = lowbit(X);\n  b |= (a & S) & ~full_mask(k + 1);\n  b |= u32(1)\
    \ << k;\n  assert(a <= b);\n  return b;\n};"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: setfunc/xor_submask_lower_bound.hpp
  requiredBy: []
  timestamp: '2026-08-19 06:34:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: setfunc/xor_submask_lower_bound.hpp
layout: document
redirect_from:
- /library/setfunc/xor_submask_lower_bound.hpp
- /library/setfunc/xor_submask_lower_bound.hpp.html
title: setfunc/xor_submask_lower_bound.hpp
---
