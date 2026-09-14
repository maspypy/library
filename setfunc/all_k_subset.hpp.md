---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/4_aoj/ITP2_11_D.test.cpp
    title: test/4_aoj/ITP2_11_D.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"setfunc/all_k_subset.hpp\"\
    \n\n#ifdef _MSC_VER\n#include <intrin.h>\n#else\n#include <x86intrin.h>\n#endif\n\
    \ntemplate <typename UINT>\nstruct all_k_subset {\n  static_assert(is_unsigned<UINT>::value);\n\
    \  struct iter {\n    const UINT n, k, s;\n    UINT t;\n    iter(UINT s, UINT\
    \ k)\n        : n(UINT(1) << popcnt(s)), k(k), s(s), t(full_mask(k)) {}\n    __attribute__((target(\"\
    bmi2\"))) auto operator*() const {\n      return _pdep_u64(t, s);\n    }\n   \
    \ auto operator++() {\n      if (k == 0) {\n        t = UINT(-1);\n      } else\
    \ {\n        UINT y = t + (-t & t);\n        t = y | ((y ^ t) >> lowbit(t << 2));\n\
    \      }\n    }\n    auto operator!=(const iter) const { return t < n; }\n  };\n\
    \  UINT s, k;\n  all_k_subset(UINT s, UINT k) : s(s), k(k) { assert(s != UINT(-1));\
    \ }\n  auto begin() { return iter(s, k); }\n  auto end() { return iter(0, 0);\
    \ }\n};\n\n// all_nCk\u95A2\u6570\u306E\u5B9F\u88C5\ntemplate <typename UINT>\n\
    auto all_nCk(int n, int k) {\n  return all_k_subset<UINT>(full_mask(n), k);\n\
    }\n"
  code: "#include \"other/bit.hpp\"\n\n#ifdef _MSC_VER\n#include <intrin.h>\n#else\n\
    #include <x86intrin.h>\n#endif\n\ntemplate <typename UINT>\nstruct all_k_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  struct iter {\n    const UINT\
    \ n, k, s;\n    UINT t;\n    iter(UINT s, UINT k)\n        : n(UINT(1) << popcnt(s)),\
    \ k(k), s(s), t(full_mask(k)) {}\n    __attribute__((target(\"bmi2\"))) auto operator*()\
    \ const {\n      return _pdep_u64(t, s);\n    }\n    auto operator++() {\n   \
    \   if (k == 0) {\n        t = UINT(-1);\n      } else {\n        UINT y = t +\
    \ (-t & t);\n        t = y | ((y ^ t) >> lowbit(t << 2));\n      }\n    }\n  \
    \  auto operator!=(const iter) const { return t < n; }\n  };\n  UINT s, k;\n \
    \ all_k_subset(UINT s, UINT k) : s(s), k(k) { assert(s != UINT(-1)); }\n  auto\
    \ begin() { return iter(s, k); }\n  auto end() { return iter(0, 0); }\n};\n\n\
    // all_nCk\u95A2\u6570\u306E\u5B9F\u88C5\ntemplate <typename UINT>\nauto all_nCk(int\
    \ n, int k) {\n  return all_k_subset<UINT>(full_mask(n), k);\n}"
  dependsOn:
  - other/bit.hpp
  isVerificationFile: false
  path: setfunc/all_k_subset.hpp
  requiredBy: []
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/4_aoj/ITP2_11_D.test.cpp
documentation_of: setfunc/all_k_subset.hpp
layout: document
redirect_from:
- /library/setfunc/all_k_subset.hpp
- /library/setfunc/all_k_subset.hpp.html
title: setfunc/all_k_subset.hpp
---
