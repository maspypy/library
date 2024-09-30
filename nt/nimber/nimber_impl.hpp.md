---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: nt/nimber/base.hpp
    title: nt/nimber/base.hpp
  - icon: ':heavy_check_mark:'
    path: nt/nimber/solve_quadratic.hpp
    title: nt/nimber/solve_quadratic.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/nimber.test.cpp
    title: test/1_mytest/nimber.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"nt/nimber/nimber_impl.hpp\"\nnamespace NIM_PRODUCT {\r\n\
    u16 E[65535 * 2 + 7];\r\nu16 L[65536];\r\nu64 S[4][65536];\r\nu64 SR[4][65536];\r\
    \n\r\nu16 p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 3] : 0);\
    \ }\r\nu16 p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 6]\
    \ : 0); }\r\nu16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }\r\nu16 mul_15_15(u16\
    \ a) { return (a ? E[6 + L[a]] : 0); }\r\nu32 p32_mul_31(u32 a, u32 b) {\r\n \
    \ u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\r\n  u16 x =\
    \ p16_15(al, bl);\r\n  u16 y = p16_15_15(ah, bh);\r\n  u16 z = p16_15(al ^ ah,\
    \ bl ^ bh);\r\n  return u32(y ^ z) << 16 | mul_15(z ^ x);\r\n}\r\nu32 mul_31(u32\
    \ a) {\r\n  u16 al = a & 65535, ah = a >> 16;\r\n  return u32(mul_15(al ^ ah))\
    \ << 16 | mul_15_15(ah);\r\n}\r\n\r\nu16 prod(u16 a, u16 b) { return (a && b ?\
    \ E[u32(L[a]) + L[b]] : 0); }\r\nu32 prod(u32 a, u32 b) {\r\n  u16 al = a & 65535,\
    \ ah = a >> 16, bl = b & 65535, bh = b >> 16;\r\n  u16 c = prod(al, bl);\r\n \
    \ return u32(prod(u16(al ^ ah), u16(bl ^ bh)) ^ c) << 16 | (p16_15(ah, bh) ^ c);\r\
    \n}\r\nu64 prod(u64 a, u64 b) {\r\n  u32 al = a & 0xffffffff, ah = a >> 32, bl\
    \ = b & 0xffffffff, bh = b >> 32;\r\n  u32 c = prod(al, bl);\r\n  return u64(prod(al\
    \ ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah, bh) ^ c);\r\n}\r\n\r\nu16 square(u16\
    \ a) { return S[0][a]; }\r\nu32 square(u32 a) { return S[0][a & 65535] ^ S[1][a\
    \ >> 16]; }\r\nu64 square(u64 a) { return S[0][a & 65535] ^ S[1][a >> 16 & 65535]\
    \ ^ S[2][a >> 32 & 65535] ^ S[3][a >> 48 & 65535]; }\r\nu16 sqrt(u16 a) { return\
    \ SR[0][a]; }\r\nu32 sqrt(u32 a) { return SR[0][a & 65535] ^ SR[1][a >> 16]; }\r\
    \nu64 sqrt(u64 a) { return SR[0][a & 65535] ^ SR[1][a >> 16 & 65535] ^ SR[2][a\
    \ >> 32 & 65535] ^ SR[3][a >> 48 & 65535]; }\r\n\r\n// inv: 2^16 \u306E\u5171\u5F79\
    \u304C 2^16+1 \u3067\u3042\u308B\u3053\u3068\u306A\u3069\u3092\u4F7F\u3046. x^{-1}=y(xy)^{-1}\
    \ \u3068\u3044\u3046\u8981\u9818.\r\nu16 inverse(u16 a) { return E[65535 - L[a]];\
    \ }\r\nu32 inverse(u32 a) {\r\n  if (a < 65536) return inverse(u16(a));\r\n  u16\
    \ al = a & 65535, ah = a >> 16;\r\n  u16 norm = prod(al, al ^ ah) ^ E[L[ah] *\
    \ 2 + 3];\r\n  int k = 65535 - L[norm];\r\n  al = (al ^ ah ? E[L[al ^ ah] + k]\
    \ : 0), ah = E[L[ah] + k];\r\n  return al | u32(ah) << 16;\r\n}\r\nu64 inverse(u64\
    \ a) {\r\n  if (a <= u32(-1)) return inverse(u32(a));\r\n  u32 al = a & 0xffffffff,\
    \ ah = a >> 32;\r\n  u32 norm = prod(al, al ^ ah) ^ mul_31(square(ah));\r\n  u32\
    \ i = inverse(norm);\r\n  return prod(al ^ ah, i) | u64(prod(ah, i)) << 32;\r\n\
    }\r\n\r\nvoid __attribute__((constructor)) init_nim_table() {\r\n  // 2^16 \u672A\
    \u6E80\u306E\u3068\u3053\u308D\u306B\u3064\u3044\u3066\u539F\u59CB\u6839 10279\
    \ \u3067\u306E\u6307\u6570\u5BFE\u6570\u8868\u3092\u4F5C\u308B\r\n  // 2^k \u3068\
    \u306E\u7A4D\r\n  u16 tmp[] = {10279, 15417, 35722, 52687, 44124, 62628, 15661,\
    \ 5686, 3862, 1323, 334, 647, 61560, 20636, 4267, 8445};\r\n  u16 nxt[65536];\r\
    \n  FOR(i, 16) {\r\n    FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }\r\
    \n  }\r\n  E[0] = 1;\r\n  FOR(i, 65534) E[i + 1] = nxt[E[i]];\r\n  memcpy(E +\
    \ 65535, E, 131070);\r\n  memcpy(E + 131070, E, 14);\r\n  FOR(i, 65535) L[E[i]]\
    \ = i;\r\n  FOR(t, 4) {\r\n    FOR(i, 16) {\r\n      int k = 16 * t + i;\r\n \
    \     u64 X = prod(u64(1) << k, u64(1) << k);\r\n      FOR(s, 1 << i) S[t][s |\
    \ 1 << i] = S[t][s] ^ X;\r\n    }\r\n  }\r\n  FOR(t, 4) {\r\n    FOR(i, 16) {\r\
    \n      int k = 16 * t + i;\r\n      u64 X = u64(1) << k;\r\n      FOR(63) X =\
    \ square(X);\r\n      FOR(s, 1 << i) SR[t][s | 1 << i] = SR[t][s] ^ X;\r\n   \
    \ }\r\n  }\r\n}\r\n} // namespace NIM_PRODUCT\r\n"
  code: "#pragma once\r\nnamespace NIM_PRODUCT {\r\nu16 E[65535 * 2 + 7];\r\nu16 L[65536];\r\
    \nu64 S[4][65536];\r\nu64 SR[4][65536];\r\n\r\nu16 p16_15(u16 a, u16 b) { return\
    \ (a && b ? E[u32(L[a]) + L[b] + 3] : 0); }\r\nu16 p16_15_15(u16 a, u16 b) { return\
    \ (a && b ? E[u32(L[a]) + L[b] + 6] : 0); }\r\nu16 mul_15(u16 a) { return (a ?\
    \ E[3 + L[a]] : 0); }\r\nu16 mul_15_15(u16 a) { return (a ? E[6 + L[a]] : 0);\
    \ }\r\nu32 p32_mul_31(u32 a, u32 b) {\r\n  u16 al = a & 65535, ah = a >> 16, bl\
    \ = b & 65535, bh = b >> 16;\r\n  u16 x = p16_15(al, bl);\r\n  u16 y = p16_15_15(ah,\
    \ bh);\r\n  u16 z = p16_15(al ^ ah, bl ^ bh);\r\n  return u32(y ^ z) << 16 | mul_15(z\
    \ ^ x);\r\n}\r\nu32 mul_31(u32 a) {\r\n  u16 al = a & 65535, ah = a >> 16;\r\n\
    \  return u32(mul_15(al ^ ah)) << 16 | mul_15_15(ah);\r\n}\r\n\r\nu16 prod(u16\
    \ a, u16 b) { return (a && b ? E[u32(L[a]) + L[b]] : 0); }\r\nu32 prod(u32 a,\
    \ u32 b) {\r\n  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\r\
    \n  u16 c = prod(al, bl);\r\n  return u32(prod(u16(al ^ ah), u16(bl ^ bh)) ^ c)\
    \ << 16 | (p16_15(ah, bh) ^ c);\r\n}\r\nu64 prod(u64 a, u64 b) {\r\n  u32 al =\
    \ a & 0xffffffff, ah = a >> 32, bl = b & 0xffffffff, bh = b >> 32;\r\n  u32 c\
    \ = prod(al, bl);\r\n  return u64(prod(al ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah,\
    \ bh) ^ c);\r\n}\r\n\r\nu16 square(u16 a) { return S[0][a]; }\r\nu32 square(u32\
    \ a) { return S[0][a & 65535] ^ S[1][a >> 16]; }\r\nu64 square(u64 a) { return\
    \ S[0][a & 65535] ^ S[1][a >> 16 & 65535] ^ S[2][a >> 32 & 65535] ^ S[3][a >>\
    \ 48 & 65535]; }\r\nu16 sqrt(u16 a) { return SR[0][a]; }\r\nu32 sqrt(u32 a) {\
    \ return SR[0][a & 65535] ^ SR[1][a >> 16]; }\r\nu64 sqrt(u64 a) { return SR[0][a\
    \ & 65535] ^ SR[1][a >> 16 & 65535] ^ SR[2][a >> 32 & 65535] ^ SR[3][a >> 48 &\
    \ 65535]; }\r\n\r\n// inv: 2^16 \u306E\u5171\u5F79\u304C 2^16+1 \u3067\u3042\u308B\
    \u3053\u3068\u306A\u3069\u3092\u4F7F\u3046. x^{-1}=y(xy)^{-1} \u3068\u3044\u3046\
    \u8981\u9818.\r\nu16 inverse(u16 a) { return E[65535 - L[a]]; }\r\nu32 inverse(u32\
    \ a) {\r\n  if (a < 65536) return inverse(u16(a));\r\n  u16 al = a & 65535, ah\
    \ = a >> 16;\r\n  u16 norm = prod(al, al ^ ah) ^ E[L[ah] * 2 + 3];\r\n  int k\
    \ = 65535 - L[norm];\r\n  al = (al ^ ah ? E[L[al ^ ah] + k] : 0), ah = E[L[ah]\
    \ + k];\r\n  return al | u32(ah) << 16;\r\n}\r\nu64 inverse(u64 a) {\r\n  if (a\
    \ <= u32(-1)) return inverse(u32(a));\r\n  u32 al = a & 0xffffffff, ah = a >>\
    \ 32;\r\n  u32 norm = prod(al, al ^ ah) ^ mul_31(square(ah));\r\n  u32 i = inverse(norm);\r\
    \n  return prod(al ^ ah, i) | u64(prod(ah, i)) << 32;\r\n}\r\n\r\nvoid __attribute__((constructor))\
    \ init_nim_table() {\r\n  // 2^16 \u672A\u6E80\u306E\u3068\u3053\u308D\u306B\u3064\
    \u3044\u3066\u539F\u59CB\u6839 10279 \u3067\u306E\u6307\u6570\u5BFE\u6570\u8868\
    \u3092\u4F5C\u308B\r\n  // 2^k \u3068\u306E\u7A4D\r\n  u16 tmp[] = {10279, 15417,\
    \ 35722, 52687, 44124, 62628, 15661, 5686, 3862, 1323, 334, 647, 61560, 20636,\
    \ 4267, 8445};\r\n  u16 nxt[65536];\r\n  FOR(i, 16) {\r\n    FOR(s, 1 << i) {\
    \ nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }\r\n  }\r\n  E[0] = 1;\r\n  FOR(i, 65534)\
    \ E[i + 1] = nxt[E[i]];\r\n  memcpy(E + 65535, E, 131070);\r\n  memcpy(E + 131070,\
    \ E, 14);\r\n  FOR(i, 65535) L[E[i]] = i;\r\n  FOR(t, 4) {\r\n    FOR(i, 16) {\r\
    \n      int k = 16 * t + i;\r\n      u64 X = prod(u64(1) << k, u64(1) << k);\r\
    \n      FOR(s, 1 << i) S[t][s | 1 << i] = S[t][s] ^ X;\r\n    }\r\n  }\r\n  FOR(t,\
    \ 4) {\r\n    FOR(i, 16) {\r\n      int k = 16 * t + i;\r\n      u64 X = u64(1)\
    \ << k;\r\n      FOR(63) X = square(X);\r\n      FOR(s, 1 << i) SR[t][s | 1 <<\
    \ i] = SR[t][s] ^ X;\r\n    }\r\n  }\r\n}\r\n} // namespace NIM_PRODUCT\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/nimber/nimber_impl.hpp
  requiredBy:
  - nt/nimber/base.hpp
  - nt/nimber/solve_quadratic.hpp
  timestamp: '2024-10-01 00:24:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/nimber.test.cpp
documentation_of: nt/nimber/nimber_impl.hpp
layout: document
redirect_from:
- /library/nt/nimber/nimber_impl.hpp
- /library/nt/nimber/nimber_impl.hpp.html
title: nt/nimber/nimber_impl.hpp
---
