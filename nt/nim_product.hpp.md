---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/number_theory/nim_product.test.cpp
    title: test/2_library_checker/number_theory/nim_product.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"nt/nim_product.hpp\"\n\r\nnamespace NIM_PRODUCT {\r\nu16\
    \ E[65535 * 2 + 7];\r\nu16 L[65536];\r\n\r\nvoid __attribute__((constructor))\
    \ init_nim_table() {\r\n  // 2^16 \u672A\u6E80\u306E\u3068\u3053\u308D\u306B\u3064\
    \u3044\u3066\u539F\u59CB\u6839 10279 \u3067\u306E\u6307\u6570\u5BFE\u6570\u8868\
    \u3092\u4F5C\u308B\r\n  // 2^k \u3068\u306E\u7A4D\r\n  u16 tmp[] = {10279, 15417,\
    \ 35722, 52687, 44124, 62628, 15661, 5686, 3862, 1323, 334, 647, 61560, 20636,\
    \ 4267, 8445};\r\n  u16 nxt[65536];\r\n  FOR(i, 16) {\r\n    FOR(s, 1 << i) {\
    \ nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }\r\n  }\r\n  E[0] = 1;\r\n  FOR(i, 65534)\
    \ E[i + 1] = nxt[E[i]];\r\n  memcpy(E + 65535, E, 131070);\r\n  memcpy(E + 131070,\
    \ E, 14);\r\n  FOR(i, 65535) L[E[i]] = i;\r\n}\r\n\r\nu16 p16(u16 a, u16 b) {\
    \ return (a && b ? E[u32(L[a]) + L[b]] : 0); }\r\nu16 p16_15(u16 a, u16 b) { return\
    \ (a && b ? E[u32(L[a]) + L[b] + 3] : 0); }\r\nu16 p16_15_15(u16 a, u16 b) { return\
    \ (a && b ? E[u32(L[a]) + L[b] + 6] : 0); }\r\nu16 mul_15(u16 a) { return (a ?\
    \ E[3 + L[a]] : 0); }\r\nu32 p32(u32 a, u32 b) {\r\n  u16 al = a & 65535, ah =\
    \ a >> 16, bl = b & 65535, bh = b >> 16;\r\n  u16 c = p16(al, bl);\r\n  return\
    \ u32(p16(al ^ ah, bl ^ bh) ^ c) << 16 | (p16_15(ah, bh) ^ c);\r\n}\r\n\r\nu32\
    \ p32_mul_31(u32 a, u32 b) {\r\n  u16 al = a & 65535, ah = a >> 16, bl = b & 65535,\
    \ bh = b >> 16;\r\n  u16 x = p16_15(al, bl);\r\n  u16 y = p16_15_15(ah, bh);\r\
    \n  u16 z = p16_15(al ^ ah, bl ^ bh);\r\n  return u32(y ^ z) << 16 | mul_15(z\
    \ ^ x);\r\n}\r\n\r\nu64 p64(u64 a, u64 b) {\r\n  u32 al = a & 0xffffffff, ah =\
    \ a >> 32, bl = b & 0xffffffff, bh = b >> 32;\r\n  u32 c = p32(al, bl);\r\n  return\
    \ u64(p32(al ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah, bh) ^ c);\r\n}\r\n} //\
    \ namespace NIM_PRODUCT\r\n\r\nu64 nim_product(u64 a, u64 b) { return NIM_PRODUCT::p64(a,\
    \ b); }\r\n"
  code: "\r\nnamespace NIM_PRODUCT {\r\nu16 E[65535 * 2 + 7];\r\nu16 L[65536];\r\n\
    \r\nvoid __attribute__((constructor)) init_nim_table() {\r\n  // 2^16 \u672A\u6E80\
    \u306E\u3068\u3053\u308D\u306B\u3064\u3044\u3066\u539F\u59CB\u6839 10279 \u3067\
    \u306E\u6307\u6570\u5BFE\u6570\u8868\u3092\u4F5C\u308B\r\n  // 2^k \u3068\u306E\
    \u7A4D\r\n  u16 tmp[] = {10279, 15417, 35722, 52687, 44124, 62628, 15661, 5686,\
    \ 3862, 1323, 334, 647, 61560, 20636, 4267, 8445};\r\n  u16 nxt[65536];\r\n  FOR(i,\
    \ 16) {\r\n    FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^ tmp[i]; }\r\n  }\r\n\
    \  E[0] = 1;\r\n  FOR(i, 65534) E[i + 1] = nxt[E[i]];\r\n  memcpy(E + 65535, E,\
    \ 131070);\r\n  memcpy(E + 131070, E, 14);\r\n  FOR(i, 65535) L[E[i]] = i;\r\n\
    }\r\n\r\nu16 p16(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b]] : 0); }\r\
    \nu16 p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 3] : 0); }\r\
    \nu16 p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) + L[b] + 6] : 0);\
    \ }\r\nu16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }\r\nu32 p32(u32 a, u32\
    \ b) {\r\n  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\r\n\
    \  u16 c = p16(al, bl);\r\n  return u32(p16(al ^ ah, bl ^ bh) ^ c) << 16 | (p16_15(ah,\
    \ bh) ^ c);\r\n}\r\n\r\nu32 p32_mul_31(u32 a, u32 b) {\r\n  u16 al = a & 65535,\
    \ ah = a >> 16, bl = b & 65535, bh = b >> 16;\r\n  u16 x = p16_15(al, bl);\r\n\
    \  u16 y = p16_15_15(ah, bh);\r\n  u16 z = p16_15(al ^ ah, bl ^ bh);\r\n  return\
    \ u32(y ^ z) << 16 | mul_15(z ^ x);\r\n}\r\n\r\nu64 p64(u64 a, u64 b) {\r\n  u32\
    \ al = a & 0xffffffff, ah = a >> 32, bl = b & 0xffffffff, bh = b >> 32;\r\n  u32\
    \ c = p32(al, bl);\r\n  return u64(p32(al ^ ah, bl ^ bh) ^ c) << 32 ^ (p32_mul_31(ah,\
    \ bh) ^ c);\r\n}\r\n} // namespace NIM_PRODUCT\r\n\r\nu64 nim_product(u64 a, u64\
    \ b) { return NIM_PRODUCT::p64(a, b); }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: nt/nim_product.hpp
  requiredBy: []
  timestamp: '2024-09-28 12:24:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/number_theory/nim_product.test.cpp
documentation_of: nt/nim_product.hpp
layout: document
redirect_from:
- /library/nt/nim_product.hpp
- /library/nt/nim_product.hpp.html
title: nt/nim_product.hpp
---
