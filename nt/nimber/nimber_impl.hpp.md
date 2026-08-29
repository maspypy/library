---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: nt/nimber/base.hpp
    title: nt/nimber/base.hpp
  - icon: ':heavy_check_mark:'
    path: nt/nimber/nimber_log.hpp
    title: nt/nimber/nimber_log.hpp
  - icon: ':heavy_check_mark:'
    path: nt/nimber/solve_quadratic.hpp
    title: nt/nimber/solve_quadratic.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/nimber.test.cpp
    title: test/1_mytest/nimber.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/nimber_log.test.cpp
    title: test/1_mytest/nimber_log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/number_theory/nim_product.test.cpp
    title: test/2_library_checker/number_theory/nim_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2907.test.cpp
    title: test/3_yukicoder/2907.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2907_2.test.cpp
    title: test/3_yukicoder/2907_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/nimber/nimber_impl.hpp\"\nnamespace NIM_PRODUCT {\nu16\
    \ E[65535 * 2 + 7];\nu16 L[65536];\nu64 S[4][65536];\nu64 SR[4][65536];\n\nu16\
    \ p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 3] : 0); }\nu16\
    \ p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 6] : 0); }\n\
    u16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }\nu16 mul_15_15(u16 a) { return\
    \ (a ? E[6 + L[a]] : 0); }\nu32 p32_mul_31(u32 a, u32 b) {\n  u16 al = a & 65535,\
    \ ah = a >> 16, bl = b & 65535, bh = b >> 16;\n  u16 x = p16_15(al, bl);\n  u16\
    \ y = p16_15_15(ah, bh);\n  u16 z = p16_15(al ^ ah, bl ^ bh);\n  return u32(y\
    \ ^ z) << 16 | mul_15(z ^ x);\n}\nu32 mul_31(u32 a) {\n  u16 al = a & 65535, ah\
    \ = a >> 16;\n  return u32(mul_15(al ^ ah)) << 16 | mul_15_15(ah);\n}\n\nu16 prod(u16\
    \ a, u16 b) { return (a && b ? E[u32(L[a]) + L[b]] : 0); }\nu32 prod(u32 a, u32\
    \ b) {\n  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\n  u16\
    \ c = prod(al, bl);\n  return u32(prod(u16(al ^ ah), u16(bl ^ bh)) ^ c) << 16\
    \ | (p16_15(ah, bh) ^ c);\n}\nu64 prod(u64 a, u64 b) {\n  u32 al = a & 0xffffffff,\
    \ ah = a >> 32, bl = b & 0xffffffff, bh = b >> 32;\n  u32 c = prod(al, bl);\n\
    \  return u64(prod(al ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah, bh) ^ c);\n\
    }\n\nu16 square(u16 a) { return S[0][a]; }\nu32 square(u32 a) { return S[0][a\
    \ & 65535] ^ S[1][a >> 16]; }\nu64 square(u64 a) { return S[0][a & 65535] ^ S[1][a\
    \ >> 16 & 65535] ^ S[2][a >> 32 & 65535] ^ S[3][a >> 48 & 65535]; }\nu16 sqrt(u16\
    \ a) { return SR[0][a]; }\nu32 sqrt(u32 a) { return SR[0][a & 65535] ^ SR[1][a\
    \ >> 16]; }\nu64 sqrt(u64 a) { return SR[0][a & 65535] ^ SR[1][a >> 16 & 65535]\
    \ ^ SR[2][a >> 32 & 65535] ^ SR[3][a >> 48 & 65535]; }\n\n// inv: 2^16 \u306E\u5171\
    \u5F79\u304C 2^16+1 \u3067\u3042\u308B\u3053\u3068\u306A\u3069\u3092\u4F7F\u3046\
    . x^{-1}=y(xy)^{-1} \u3068\u3044\u3046\u8981\u9818.\nu16 inverse(u16 a) { return\
    \ E[65535 - L[a]]; }\nu32 inverse(u32 a) {\n  if (a < 65536) return inverse(u16(a));\n\
    \  u16 al = a & 65535, ah = a >> 16;\n  u16 norm = prod(al, al ^ ah) ^ E[L[ah]\
    \ * 2 + 3];\n  int k = 65535 - L[norm];\n  al = (al ^ ah ? E[L[al ^ ah] + k] :\
    \ 0), ah = E[L[ah] + k];\n  return al | u32(ah) << 16;\n}\nu64 inverse(u64 a)\
    \ {\n  if (a <= u32(-1)) return inverse(u32(a));\n  u32 al = a & 0xffffffff, ah\
    \ = a >> 32;\n  u32 norm = prod(al, al ^ ah) ^ mul_31(square(ah));\n  u32 i =\
    \ inverse(norm);\n  return prod(al ^ ah, i) | u64(prod(ah, i)) << 32;\n}\n\nvoid\
    \ __attribute__((constructor)) init_nim_table() {\n  // 2^16 \u672A\u6E80\u306E\
    \u3068\u3053\u308D\u306B\u3064\u3044\u3066\u539F\u59CB\u6839 10279 \u3067\u306E\
    \u6307\u6570\u5BFE\u6570\u8868\u3092\u4F5C\u308B\n  // 2^k \u3068\u306E\u7A4D\n\
    \  u16 tmp[] = {10279, 15417, 35722, 52687, 44124, 62628, 15661, 5686, 3862, 1323,\
    \ 334, 647, 61560, 20636, 4267, 8445};\n  u16 nxt[65536];\n  FOR(i, 16) {\n  \
    \  FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }\n  }\n  E[0] = 1;\n \
    \ FOR(i, 65534) E[i + 1] = nxt[E[i]];\n  memcpy(E + 65535, E, 131070);\n  memcpy(E\
    \ + 131070, E, 14);\n  FOR(i, 65535) L[E[i]] = i;\n  FOR(t, 4) {\n    FOR(i, 16)\
    \ {\n      int k = 16 * t + i;\n      u64 X = prod(u64(1) << k, u64(1) << k);\n\
    \      FOR(s, 1 << i) S[t][s | 1 << i] = S[t][s] ^ X;\n    }\n  }\n  FOR(t, 4)\
    \ {\n    FOR(i, 16) {\n      int k = 16 * t + i;\n      u64 X = u64(1) << k;\n\
    \      FOR(63) X = square(X);\n      FOR(s, 1 << i) SR[t][s | 1 << i] = SR[t][s]\
    \ ^ X;\n    }\n  }\n}\n} // namespace NIM_PRODUCT\n"
  code: "namespace NIM_PRODUCT {\nu16 E[65535 * 2 + 7];\nu16 L[65536];\nu64 S[4][65536];\n\
    u64 SR[4][65536];\n\nu16 p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) +\
    \ L[b] + 3] : 0); }\nu16 p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a])\
    \ + L[b] + 6] : 0); }\nu16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }\nu16\
    \ mul_15_15(u16 a) { return (a ? E[6 + L[a]] : 0); }\nu32 p32_mul_31(u32 a, u32\
    \ b) {\n  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\n  u16\
    \ x = p16_15(al, bl);\n  u16 y = p16_15_15(ah, bh);\n  u16 z = p16_15(al ^ ah,\
    \ bl ^ bh);\n  return u32(y ^ z) << 16 | mul_15(z ^ x);\n}\nu32 mul_31(u32 a)\
    \ {\n  u16 al = a & 65535, ah = a >> 16;\n  return u32(mul_15(al ^ ah)) << 16\
    \ | mul_15_15(ah);\n}\n\nu16 prod(u16 a, u16 b) { return (a && b ? E[u32(L[a])\
    \ + L[b]] : 0); }\nu32 prod(u32 a, u32 b) {\n  u16 al = a & 65535, ah = a >> 16,\
    \ bl = b & 65535, bh = b >> 16;\n  u16 c = prod(al, bl);\n  return u32(prod(u16(al\
    \ ^ ah), u16(bl ^ bh)) ^ c) << 16 | (p16_15(ah, bh) ^ c);\n}\nu64 prod(u64 a,\
    \ u64 b) {\n  u32 al = a & 0xffffffff, ah = a >> 32, bl = b & 0xffffffff, bh =\
    \ b >> 32;\n  u32 c = prod(al, bl);\n  return u64(prod(al ^ ah, bl ^ bh) ^ c)\
    \ << 32 ^ (p32_mul_31(ah, bh) ^ c);\n}\n\nu16 square(u16 a) { return S[0][a];\
    \ }\nu32 square(u32 a) { return S[0][a & 65535] ^ S[1][a >> 16]; }\nu64 square(u64\
    \ a) { return S[0][a & 65535] ^ S[1][a >> 16 & 65535] ^ S[2][a >> 32 & 65535]\
    \ ^ S[3][a >> 48 & 65535]; }\nu16 sqrt(u16 a) { return SR[0][a]; }\nu32 sqrt(u32\
    \ a) { return SR[0][a & 65535] ^ SR[1][a >> 16]; }\nu64 sqrt(u64 a) { return SR[0][a\
    \ & 65535] ^ SR[1][a >> 16 & 65535] ^ SR[2][a >> 32 & 65535] ^ SR[3][a >> 48 &\
    \ 65535]; }\n\n// inv: 2^16 \u306E\u5171\u5F79\u304C 2^16+1 \u3067\u3042\u308B\
    \u3053\u3068\u306A\u3069\u3092\u4F7F\u3046. x^{-1}=y(xy)^{-1} \u3068\u3044\u3046\
    \u8981\u9818.\nu16 inverse(u16 a) { return E[65535 - L[a]]; }\nu32 inverse(u32\
    \ a) {\n  if (a < 65536) return inverse(u16(a));\n  u16 al = a & 65535, ah = a\
    \ >> 16;\n  u16 norm = prod(al, al ^ ah) ^ E[L[ah] * 2 + 3];\n  int k = 65535\
    \ - L[norm];\n  al = (al ^ ah ? E[L[al ^ ah] + k] : 0), ah = E[L[ah] + k];\n \
    \ return al | u32(ah) << 16;\n}\nu64 inverse(u64 a) {\n  if (a <= u32(-1)) return\
    \ inverse(u32(a));\n  u32 al = a & 0xffffffff, ah = a >> 32;\n  u32 norm = prod(al,\
    \ al ^ ah) ^ mul_31(square(ah));\n  u32 i = inverse(norm);\n  return prod(al ^\
    \ ah, i) | u64(prod(ah, i)) << 32;\n}\n\nvoid __attribute__((constructor)) init_nim_table()\
    \ {\n  // 2^16 \u672A\u6E80\u306E\u3068\u3053\u308D\u306B\u3064\u3044\u3066\u539F\
    \u59CB\u6839 10279 \u3067\u306E\u6307\u6570\u5BFE\u6570\u8868\u3092\u4F5C\u308B\
    \n  // 2^k \u3068\u306E\u7A4D\n  u16 tmp[] = {10279, 15417, 35722, 52687, 44124,\
    \ 62628, 15661, 5686, 3862, 1323, 334, 647, 61560, 20636, 4267, 8445};\n  u16\
    \ nxt[65536];\n  FOR(i, 16) {\n    FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^\
    \ tmp[i]; }\n  }\n  E[0] = 1;\n  FOR(i, 65534) E[i + 1] = nxt[E[i]];\n  memcpy(E\
    \ + 65535, E, 131070);\n  memcpy(E + 131070, E, 14);\n  FOR(i, 65535) L[E[i]]\
    \ = i;\n  FOR(t, 4) {\n    FOR(i, 16) {\n      int k = 16 * t + i;\n      u64\
    \ X = prod(u64(1) << k, u64(1) << k);\n      FOR(s, 1 << i) S[t][s | 1 << i] =\
    \ S[t][s] ^ X;\n    }\n  }\n  FOR(t, 4) {\n    FOR(i, 16) {\n      int k = 16\
    \ * t + i;\n      u64 X = u64(1) << k;\n      FOR(63) X = square(X);\n      FOR(s,\
    \ 1 << i) SR[t][s | 1 << i] = SR[t][s] ^ X;\n    }\n  }\n}\n} // namespace NIM_PRODUCT\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/nimber/nimber_impl.hpp
  requiredBy:
  - nt/nimber/solve_quadratic.hpp
  - nt/nimber/base.hpp
  - nt/nimber/nimber_log.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/nimber_log.test.cpp
  - test/1_mytest/nimber.test.cpp
  - test/2_library_checker/number_theory/nim_product.test.cpp
  - test/3_yukicoder/2907.test.cpp
  - test/3_yukicoder/2907_2.test.cpp
documentation_of: nt/nimber/nimber_impl.hpp
layout: document
redirect_from:
- /library/nt/nimber/nimber_impl.hpp
- /library/nt/nimber/nimber_impl.hpp.html
title: nt/nimber/nimber_impl.hpp
---
