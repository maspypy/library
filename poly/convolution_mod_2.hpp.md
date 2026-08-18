---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/convolution_mod_2.hpp\"\n\n__attribute__((target(\"\
    pclmul\"))) void clmul_schoolbook(const u64* a,\n                            \
    \                            const u64* b, u64* c,\n                         \
    \                               int n) {\n  // c[0, 2n) \u306F\u3042\u3089\u304B\
    \u3058\u3081 0 \u3068\u3059\u308B\n  FOR(i, n) FOR(j, n) {\n    __m128i A = _mm_set_epi64x(0,\
    \ a[i]);\n    __m128i B = _mm_set_epi64x(0, b[j]);\n    __m128i C = _mm_clmulepi64_si128(A,\
    \ B, 0x00);\n\n    alignas(16) u64 w[2];\n    _mm_store_si128((__m128i*)w, C);\n\
    \n    c[i + j] ^= w[0];\n    c[i + j + 1] ^= w[1];\n  }\n}\n\n// a,b: n limbs,\
    \ n \u306F 2 \u51AA\n// c: 2n limbs, \u547C\u3073\u51FA\u3057\u6642\u70B9\u3067\
    \u5168\u90E8 0\n//\n// scratch \u306F 4n limbs \u3042\u308C\u3070\u5341\u5206\u3002\
    \n__attribute__((target(\"pclmul\"))) void clmul_karatsuba_rec(const u64* a,\n\
    \                                                           const u64* b, u64*\
    \ c,\n                                                           int n,\n    \
    \                                                       u64* scratch) {\n  //\
    \ \u3053\u3053\u306F\u5B9F\u6E2C\u8ABF\u6574\n  constexpr int TH = 32;\n\n  if\
    \ (n <= TH) {\n    clmul_schoolbook(a, b, c, n);\n    return;\n  }\n\n  int m\
    \ = n / 2;\n\n  // z0 = a0*b0\n  clmul_karatsuba_rec(a, b, c, m, scratch);\n\n\
    \  // z2 = a1*b1\n  clmul_karatsuba_rec(a + m, b + m, c + 2 * m, m, scratch);\n\
    \n  /*\n    scratch:\n      [0, m)     : a0+a1\n      [m, 2m)    : b0+b1\n   \
    \   [2m, 4m)   : z1\n      [4m, ...)  : recursive scratch\n  */\n  u64* sa = scratch;\n\
    \  u64* sb = scratch + m;\n  u64* z1 = scratch + 2 * m;\n  u64* sub = scratch\
    \ + 4 * m;\n\n  FOR(i, m) {\n    sa[i] = a[i] ^ a[m + i];\n    sb[i] = b[i] ^\
    \ b[m + i];\n  }\n\n  fill(z1, z1 + 2 * m, u64(0));\n\n  // z1 = (a0+a1)(b0+b1)\n\
    \  clmul_karatsuba_rec(sa, sb, z1, m, sub);\n\n  // cross = z1 + z0 + z2\n  //\
    \ \u5148\u306B\u5168\u90E8 z1 \u5185\u3067\u5B8C\u6210\u3055\u305B\u308B\u3002\
    \n  // c[m+i] \u306B\u66F8\u304D\u306A\u304C\u3089 c[i] \u3092\u8AAD\u3080\u3068\
    \ overlap \u3057\u3066\u58CA\u308C\u308B\u306E\u3067\u6CE8\u610F\u3002\n  FOR(i,\
    \ 2 * m) { z1[i] ^= c[i] ^ c[2 * m + i]; }\n\n  // c = z0 + x^m cross + x^(2m)\
    \ z2\n  FOR(i, 2 * m) { c[m + i] ^= z1[i]; }\n}\n\n__attribute__((target(\"pclmul\"\
    ))) vc<modint<2>> convolution_mod_2(\n    const vc<modint<2>>& a, const vc<modint<2>>&\
    \ b) {\n  int na = len(a), nb = len(b);\n  if (!na || !nb) return {};\n\n  int\
    \ A = (na + 63) >> 6;\n  int B = (nb + 63) >> 6;\n\n  // \u3053\u306E\u5B9F\u88C5\
    \u306F square \u306B padding \u3059\u308B\u306E\u3067\u3001\n  // \u6975\u7AEF\
    \u306B\u975E\u5BFE\u79F0\u306A\u3089 rectangular schoolbook \u306E\u65B9\u304C\
    \u3088\u3044\u3002\n  int n = 1;\n  while (n < max(A, B)) n <<= 1;\n\n  vc<u64>\
    \ x(n), y(n), z(2 * n);\n  vc<u64> scratch(4 * n);\n\n  FOR(i, na) { x[i >> 6]\
    \ |= u64(a[i].val) << (i & 63); }\n  FOR(i, nb) { y[i >> 6] |= u64(b[i].val) <<\
    \ (i & 63); }\n\n  clmul_karatsuba_rec(x.data(), y.data(), z.data(), n, scratch.data());\n\
    \n  vc<modint<2>> res(na + nb - 1);\n  FOR(i, len(res)) { res[i] = modint<2>::raw((z[i\
    \ >> 6] >> (i & 63)) & 1); }\n  return res;\n}\n"
  code: "\n__attribute__((target(\"pclmul\"))) void clmul_schoolbook(const u64* a,\n\
    \                                                        const u64* b, u64* c,\n\
    \                                                        int n) {\n  // c[0, 2n)\
    \ \u306F\u3042\u3089\u304B\u3058\u3081 0 \u3068\u3059\u308B\n  FOR(i, n) FOR(j,\
    \ n) {\n    __m128i A = _mm_set_epi64x(0, a[i]);\n    __m128i B = _mm_set_epi64x(0,\
    \ b[j]);\n    __m128i C = _mm_clmulepi64_si128(A, B, 0x00);\n\n    alignas(16)\
    \ u64 w[2];\n    _mm_store_si128((__m128i*)w, C);\n\n    c[i + j] ^= w[0];\n \
    \   c[i + j + 1] ^= w[1];\n  }\n}\n\n// a,b: n limbs, n \u306F 2 \u51AA\n// c:\
    \ 2n limbs, \u547C\u3073\u51FA\u3057\u6642\u70B9\u3067\u5168\u90E8 0\n//\n// scratch\
    \ \u306F 4n limbs \u3042\u308C\u3070\u5341\u5206\u3002\n__attribute__((target(\"\
    pclmul\"))) void clmul_karatsuba_rec(const u64* a,\n                         \
    \                                  const u64* b, u64* c,\n                   \
    \                                        int n,\n                            \
    \                               u64* scratch) {\n  // \u3053\u3053\u306F\u5B9F\
    \u6E2C\u8ABF\u6574\n  constexpr int TH = 32;\n\n  if (n <= TH) {\n    clmul_schoolbook(a,\
    \ b, c, n);\n    return;\n  }\n\n  int m = n / 2;\n\n  // z0 = a0*b0\n  clmul_karatsuba_rec(a,\
    \ b, c, m, scratch);\n\n  // z2 = a1*b1\n  clmul_karatsuba_rec(a + m, b + m, c\
    \ + 2 * m, m, scratch);\n\n  /*\n    scratch:\n      [0, m)     : a0+a1\n    \
    \  [m, 2m)    : b0+b1\n      [2m, 4m)   : z1\n      [4m, ...)  : recursive scratch\n\
    \  */\n  u64* sa = scratch;\n  u64* sb = scratch + m;\n  u64* z1 = scratch + 2\
    \ * m;\n  u64* sub = scratch + 4 * m;\n\n  FOR(i, m) {\n    sa[i] = a[i] ^ a[m\
    \ + i];\n    sb[i] = b[i] ^ b[m + i];\n  }\n\n  fill(z1, z1 + 2 * m, u64(0));\n\
    \n  // z1 = (a0+a1)(b0+b1)\n  clmul_karatsuba_rec(sa, sb, z1, m, sub);\n\n  //\
    \ cross = z1 + z0 + z2\n  // \u5148\u306B\u5168\u90E8 z1 \u5185\u3067\u5B8C\u6210\
    \u3055\u305B\u308B\u3002\n  // c[m+i] \u306B\u66F8\u304D\u306A\u304C\u3089 c[i]\
    \ \u3092\u8AAD\u3080\u3068 overlap \u3057\u3066\u58CA\u308C\u308B\u306E\u3067\u6CE8\
    \u610F\u3002\n  FOR(i, 2 * m) { z1[i] ^= c[i] ^ c[2 * m + i]; }\n\n  // c = z0\
    \ + x^m cross + x^(2m) z2\n  FOR(i, 2 * m) { c[m + i] ^= z1[i]; }\n}\n\n__attribute__((target(\"\
    pclmul\"))) vc<modint<2>> convolution_mod_2(\n    const vc<modint<2>>& a, const\
    \ vc<modint<2>>& b) {\n  int na = len(a), nb = len(b);\n  if (!na || !nb) return\
    \ {};\n\n  int A = (na + 63) >> 6;\n  int B = (nb + 63) >> 6;\n\n  // \u3053\u306E\
    \u5B9F\u88C5\u306F square \u306B padding \u3059\u308B\u306E\u3067\u3001\n  //\
    \ \u6975\u7AEF\u306B\u975E\u5BFE\u79F0\u306A\u3089 rectangular schoolbook \u306E\
    \u65B9\u304C\u3088\u3044\u3002\n  int n = 1;\n  while (n < max(A, B)) n <<= 1;\n\
    \n  vc<u64> x(n), y(n), z(2 * n);\n  vc<u64> scratch(4 * n);\n\n  FOR(i, na) {\
    \ x[i >> 6] |= u64(a[i].val) << (i & 63); }\n  FOR(i, nb) { y[i >> 6] |= u64(b[i].val)\
    \ << (i & 63); }\n\n  clmul_karatsuba_rec(x.data(), y.data(), z.data(), n, scratch.data());\n\
    \n  vc<modint<2>> res(na + nb - 1);\n  FOR(i, len(res)) { res[i] = modint<2>::raw((z[i\
    \ >> 6] >> (i & 63)) & 1); }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_mod_2.hpp
  requiredBy: []
  timestamp: '2026-08-18 11:37:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_mod_2.hpp
layout: document
redirect_from:
- /library/poly/convolution_mod_2.hpp
- /library/poly/convolution_mod_2.hpp.html
title: poly/convolution_mod_2.hpp
---
