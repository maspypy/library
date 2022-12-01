---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/minimum_cycle_length_through_specified.hpp
    title: graph/minimum_cycle_length_through_specified.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc274_h.test.cpp
    title: test/atcoder/abc274_h.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1775.test.cpp
    title: test/yukicoder/1775.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/GF2.hpp\"\n#include <emmintrin.h>\n#include <smmintrin.h>\n\
    #include <wmmintrin.h>\n\n__attribute__((target(\"pclmul\"))) inline __m128i myclmul(const\
    \ __m128i &a,\n                                                         const\
    \ __m128i &b) {\n  return _mm_clmulepi64_si128(a, b, 0);\n}\n\n// 2^n \u5143\u4F53\
    \ntemplate <int K>\nstruct GF2 {\n  // irreducible poly x^K + ...\n  static constexpr\
    \ int POLY[65]\n      = {0,  0, 3,  3,   3,  5,   3,  3,  27,  3,  9,  5,   9,\
    \ 27, 33, 3,   43,\n         9,  9, 39, 9,   5,  3,   33, 27, 9,   27, 39, 3,\
    \   5, 3,  9,  141, 75,\n         27, 5, 53, 63,  99, 17,  57, 9,  39,  89, 33,\
    \ 27,  3, 33, 45, 113, 29,\n         75, 9, 71, 125, 71, 149, 17, 99, 123, 3,\
    \  39, 105, 3, 27};\n\n  static constexpr u64 mask() { return u64(-1) >> (64 -\
    \ K); }\n\n  __attribute__((target(\"sse4.2\"))) static u64 mul(u64 a, u64 b)\
    \ {\n    static bool prepared = 0;\n    static u64 MEMO[8][65536];\n    if (!prepared)\
    \ {\n      prepared = 1;\n      vc<u64> tmp(128);\n      tmp[0] = 1;\n      FOR(i,\
    \ 127) {\n        tmp[i + 1] = tmp[i] << 1;\n        if (tmp[i] >> (K - 1) & 1)\
    \ {\n          tmp[i + 1] ^= POLY[K];\n          tmp[i + 1] &= mask();\n     \
    \   }\n      }\n      FOR(k, 8) {\n        MEMO[k][0] = 0;\n        FOR(i, 16)\
    \ {\n          FOR(s, 1 << i) { MEMO[k][s | 1 << i] = MEMO[k][s] ^ tmp[16 * k\
    \ + i]; }\n        }\n      }\n    }\n    const __m128i a_ = _mm_set_epi64x(0,\
    \ a);\n    const __m128i b_ = _mm_set_epi64x(0, b);\n    const __m128i c_ = myclmul(a_,\
    \ b_);\n    u64 lo = _mm_extract_epi64(c_, 0);\n    u64 hi = _mm_extract_epi64(c_,\
    \ 1);\n    u64 x = 0;\n    x ^= MEMO[0][lo & 65535];\n    x ^= MEMO[1][(lo >>\
    \ 16) & 65535];\n    x ^= MEMO[2][(lo >> 32) & 65535];\n    x ^= MEMO[3][(lo >>\
    \ 48) & 65535];\n    x ^= MEMO[4][hi & 65535];\n    x ^= MEMO[5][(hi >> 16) &\
    \ 65535];\n    x ^= MEMO[6][(hi >> 32) & 65535];\n    x ^= MEMO[7][(hi >> 48)\
    \ & 65535];\n    return x;\n  }\n\n  u64 val;\n  constexpr GF2(const u64 val =\
    \ 0) noexcept : val(val & mask()) {}\n  bool operator<(const GF2 &other) const\
    \ {\n    return val < other.val;\n  } // To use std::map\n  GF2 &operator+=(const\
    \ GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n  GF2 &operator-=(const\
    \ GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n  GF2 &operator*=(const\
    \ GF2 &p) {\n    val = mul(val, p.val);\n    return *this;\n  }\n\n  GF2 &operator/=(const\
    \ GF2 &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  GF2 operator-()\
    \ const { return GF2(-val); }\n  GF2 operator+(const GF2 &p) const { return GF2(*this)\
    \ += p; }\n  GF2 operator-(const GF2 &p) const { return GF2(*this) -= p; }\n \
    \ GF2 operator*(const GF2 &p) const { return GF2(*this) *= p; }\n  GF2 operator/(const\
    \ GF2 &p) const { return GF2(*this) /= p; }\n  bool operator==(const GF2 &p) const\
    \ { return val == p.val; }\n  bool operator!=(const GF2 &p) const { return val\
    \ != p.val; }\n  GF2 inverse() const { return pow((u64(1) << K) - 2); }\n  GF2\
    \ pow(u64 n) const {\n    GF2 ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n};\n"
  code: "#include <emmintrin.h>\n#include <smmintrin.h>\n#include <wmmintrin.h>\n\n\
    __attribute__((target(\"pclmul\"))) inline __m128i myclmul(const __m128i &a,\n\
    \                                                         const __m128i &b) {\n\
    \  return _mm_clmulepi64_si128(a, b, 0);\n}\n\n// 2^n \u5143\u4F53\ntemplate <int\
    \ K>\nstruct GF2 {\n  // irreducible poly x^K + ...\n  static constexpr int POLY[65]\n\
    \      = {0,  0, 3,  3,   3,  5,   3,  3,  27,  3,  9,  5,   9, 27, 33, 3,   43,\n\
    \         9,  9, 39, 9,   5,  3,   33, 27, 9,   27, 39, 3,   5, 3,  9,  141, 75,\n\
    \         27, 5, 53, 63,  99, 17,  57, 9,  39,  89, 33, 27,  3, 33, 45, 113, 29,\n\
    \         75, 9, 71, 125, 71, 149, 17, 99, 123, 3,  39, 105, 3, 27};\n\n  static\
    \ constexpr u64 mask() { return u64(-1) >> (64 - K); }\n\n  __attribute__((target(\"\
    sse4.2\"))) static u64 mul(u64 a, u64 b) {\n    static bool prepared = 0;\n  \
    \  static u64 MEMO[8][65536];\n    if (!prepared) {\n      prepared = 1;\n   \
    \   vc<u64> tmp(128);\n      tmp[0] = 1;\n      FOR(i, 127) {\n        tmp[i +\
    \ 1] = tmp[i] << 1;\n        if (tmp[i] >> (K - 1) & 1) {\n          tmp[i + 1]\
    \ ^= POLY[K];\n          tmp[i + 1] &= mask();\n        }\n      }\n      FOR(k,\
    \ 8) {\n        MEMO[k][0] = 0;\n        FOR(i, 16) {\n          FOR(s, 1 << i)\
    \ { MEMO[k][s | 1 << i] = MEMO[k][s] ^ tmp[16 * k + i]; }\n        }\n      }\n\
    \    }\n    const __m128i a_ = _mm_set_epi64x(0, a);\n    const __m128i b_ = _mm_set_epi64x(0,\
    \ b);\n    const __m128i c_ = myclmul(a_, b_);\n    u64 lo = _mm_extract_epi64(c_,\
    \ 0);\n    u64 hi = _mm_extract_epi64(c_, 1);\n    u64 x = 0;\n    x ^= MEMO[0][lo\
    \ & 65535];\n    x ^= MEMO[1][(lo >> 16) & 65535];\n    x ^= MEMO[2][(lo >> 32)\
    \ & 65535];\n    x ^= MEMO[3][(lo >> 48) & 65535];\n    x ^= MEMO[4][hi & 65535];\n\
    \    x ^= MEMO[5][(hi >> 16) & 65535];\n    x ^= MEMO[6][(hi >> 32) & 65535];\n\
    \    x ^= MEMO[7][(hi >> 48) & 65535];\n    return x;\n  }\n\n  u64 val;\n  constexpr\
    \ GF2(const u64 val = 0) noexcept : val(val & mask()) {}\n  bool operator<(const\
    \ GF2 &other) const {\n    return val < other.val;\n  } // To use std::map\n \
    \ GF2 &operator+=(const GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n\
    \  GF2 &operator-=(const GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n\
    \  GF2 &operator*=(const GF2 &p) {\n    val = mul(val, p.val);\n    return *this;\n\
    \  }\n\n  GF2 &operator/=(const GF2 &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  GF2 operator-() const { return GF2(-val); }\n  GF2 operator+(const\
    \ GF2 &p) const { return GF2(*this) += p; }\n  GF2 operator-(const GF2 &p) const\
    \ { return GF2(*this) -= p; }\n  GF2 operator*(const GF2 &p) const { return GF2(*this)\
    \ *= p; }\n  GF2 operator/(const GF2 &p) const { return GF2(*this) /= p; }\n \
    \ bool operator==(const GF2 &p) const { return val == p.val; }\n  bool operator!=(const\
    \ GF2 &p) const { return val != p.val; }\n  GF2 inverse() const { return pow((u64(1)\
    \ << K) - 2); }\n  GF2 pow(u64 n) const {\n    GF2 ret(1), mul(val);\n    while\
    \ (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n\
    \    }\n    return ret;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/GF2.hpp
  requiredBy:
  - graph/minimum_cycle_length_through_specified.hpp
  timestamp: '2022-10-24 13:59:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1775.test.cpp
  - test/atcoder/abc274_h.test.cpp
documentation_of: nt/GF2.hpp
layout: document
redirect_from:
- /library/nt/GF2.hpp
- /library/nt/GF2.hpp.html
title: nt/GF2.hpp
---
