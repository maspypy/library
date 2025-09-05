---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/xor/basis.hpp
    title: linalg/xor/basis.hpp
  - icon: ':heavy_check_mark:'
    path: nt/nimber/base.hpp
    title: nt/nimber/base.hpp
  - icon: ':heavy_check_mark:'
    path: nt/nimber/nimber_impl.hpp
    title: nt/nimber/nimber_impl.hpp
  _extendedRequiredBy: []
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
    \ }\r\n  }\r\n}\r\n} // namespace NIM_PRODUCT\r\n#line 3 \"nt/nimber/base.hpp\"\
    \n\ntemplate <typename UINT>\nstruct Nimber {\n  using F = Nimber;\n  UINT val;\n\
    \n  constexpr Nimber(UINT x = 0) : val(x) {}\n  F &operator+=(const F &p) {\n\
    \    val ^= p.val;\n    return *this;\n  }\n  F &operator-=(const F &p) {\n  \
    \  val ^= p.val;\n    return *this;\n  }\n  F &operator*=(const F &p) {\n    val\
    \ = NIM_PRODUCT::prod(val, p.val);\n    return *this;\n  }\n  F &operator/=(const\
    \ F &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  F operator-()\
    \ const { return *this; }\n  F operator+(const F &p) const { return F(*this) +=\
    \ p; }\n  F operator-(const F &p) const { return F(*this) -= p; }\n  F operator*(const\
    \ F &p) const { return F(*this) *= p; }\n  F operator/(const F &p) const { return\
    \ F(*this) /= p; }\n  bool operator==(const F &p) const { return val == p.val;\
    \ }\n  bool operator!=(const F &p) const { return val != p.val; }\n  F inverse()\
    \ const { return NIM_PRODUCT::inverse(val); }\n  F pow(u64 n) const {\n    assert(n\
    \ >= 0);\n    UINT ret = 1, mul = val;\n    while (n > 0) {\n      if (n & 1)\
    \ ret = NIM_PRODUCT::prod(ret, mul);\n      mul = NIM_PRODUCT::square(mul);\n\
    \      n >>= 1;\n    }\n    return F(ret);\n  }\n  F square() { return F(NIM_PRODUCT::square(val));\
    \ }\n  F sqrt() { return F(NIM_PRODUCT::sqrt(val)); }\n};\n\n#ifdef FASTIO\ntemplate\
    \ <typename T>\nvoid rd(Nimber<T> &x) {\n  fastio::rd(x.val);\n}\ntemplate <typename\
    \ T>\nvoid wt(Nimber<T> &x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing Nimber16\
    \ = Nimber<u16>;\nusing Nimber32 = Nimber<u32>;\nusing Nimber64 = Nimber<u64>;\n\
    #line 1 \"linalg/xor/basis.hpp\"\n\n// basis[i]: i \u756A\u76EE\u306B\u8FFD\u52A0\
    \u6210\u529F\u3057\u305F\u3082\u306E. \u5225\u306E\u30E9\u30D9\u30EB\u304C\u3042\
    \u308B\u306A\u3089\u5916\u3067\u7BA1\u7406\u3059\u308B.\n// array<UINT, MAX_DIM>\
    \ rbasis: \u4E0A\u4E09\u89D2\u5316\u3055\u308C\u305F\u57FA\u5E95. [i][i]==1.\n\
    // way<UINT,UINT> rbasis[i] \u3092 basis[j] \u3067\u4F5C\u308B\u65B9\u6CD5\ntemplate\
    \ <int MAX_DIM>\nstruct Basis {\n  static_assert(MAX_DIM <= 128);\n  using UINT\
    \ = conditional_t<(MAX_DIM <= 32), u32, conditional_t<(MAX_DIM <= 64), u64, u128>>;\n\
    \  int rank;\n  array<UINT, MAX_DIM> basis;\n  array<UINT, MAX_DIM> rbasis;\n\
    \  array<UINT, MAX_DIM> way;\n  Basis() : rank(0), basis{}, rbasis{}, way{} {}\n\
    \n  // return : (sum==x \u306B\u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5\
    )\n  pair<bool, UINT> solve(UINT x) {\n    UINT c = 0;\n    FOR(i, MAX_DIM) {\n\
    \      if ((x >> i & 1) && (rbasis[i] != 0)) { c ^= way[i], x ^= rbasis[i]; }\n\
    \    }\n    if (x == 0) return {true, c};\n    return {false, 0};\n  }\n\n  //\
    \ return : (sum==x \u306B\u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5).\
    \ false \u306E\u5834\u5408\u306B\u306F\u8FFD\u52A0\u3059\u308B\n  pair<bool, UINT>\
    \ solve_or_add(UINT x) {\n    UINT y = x, c = 0;\n    FOR(i, MAX_DIM) {\n    \
    \  if ((x >> i & 1) && (rbasis[i] != 0)) { c ^= way[i], x ^= rbasis[i]; }\n  \
    \  }\n    if (x == 0) return {true, c};\n    int k = lowbit(x);\n    basis[rank]\
    \ = y, rbasis[k] = x, way[k] = c | UINT(1) << rank, ++rank;\n    return {false,\
    \ 0};\n  }\n};\n#line 3 \"nt/nimber/solve_quadratic.hpp\"\n\nnamespace NIMBER_QUADRATIC\
    \ {\n// x^2+x==a \u3092\u89E3\u304F. Trace(a)==0 \u304C\u5FC5\u8981.\n// Nimber\
    \ \u3067\u306F Trace \u306F topbit.\n// topbit==0 \u3067\u3042\u308B\u7A7A\u9593\
    \u304B\u3089\u5076\u6570\u5168\u4F53\u3078\u306E\u5168\u5358\u5C04\u304C\u3042\
    \u308B.\n// \u3053\u308C\u3092\u524D\u8A08\u7B97\u3057\u305F\u3044. \u7DDA\u5F62\
    \u5199\u50CF\u306A\u306E\u3067\u9023\u7ACB\u65B9\u7A0B\u5F0F\u3092\u89E3\u3044\
    \u3066\u57CB\u3081\u8FBC\u3080\u3060\u3051\u3067\u3088\u3044.\n\nu64 Q[4][65536];\n\
    \nvoid __attribute__((constructor)) precalc() {\n  Basis<63> B;\n  FOR(i, 63)\
    \ {\n    Nimber64 x(u64(1) << (i + 1));\n    x = x.square() + x;\n    assert(!B.solve_or_add(x.val).fi);\n\
    \  }\n  FOR(k, 63) {\n    int t = k / 16, i = k % 16;\n    u64 X = B.way[k] *\
    \ 2;\n    FOR(s, 1 << i) Q[t][s | 1 << i] = Q[t][s] ^ X;\n  }\n}\n\nu16 f(u16\
    \ a) { return Q[0][a]; }\nu32 f(u32 a) { return Q[0][a & 65535] ^ Q[1][a >> 16];\
    \ }\nu64 f(u64 a) { return Q[0][a & 65535] ^ Q[1][a >> 16 & 65535] ^ Q[2][a >>\
    \ 32 & 65535] ^ Q[3][a >> 48 & 65535]; }\n\ntemplate <typename U>\nvc<U> solve_quadratic_1(U\
    \ a) {\n  constexpr int k = numeric_limits<U>::digits - 1;\n  if (a >> k & 1)\
    \ return {};\n  return {f(a), U(f(a) | 1)};\n}\n} // namespace NIMBER_QUADRATIC\n\
    \ntemplate <typename F>\nvc<F> solve_quadratic(F a, F b) {\n  if (a == F(0)) return\
    \ {b.sqrt()};\n  b /= a.square();\n  vc<F> ANS;\n  for (auto& x: NIMBER_QUADRATIC::solve_quadratic_1(b.val))\
    \ { ANS.eb(a * F(x)); }\n  return ANS;\n}\n"
  code: "#include \"nt/nimber/base.hpp\"\n#include \"linalg/xor/basis.hpp\"\n\nnamespace\
    \ NIMBER_QUADRATIC {\n// x^2+x==a \u3092\u89E3\u304F. Trace(a)==0 \u304C\u5FC5\
    \u8981.\n// Nimber \u3067\u306F Trace \u306F topbit.\n// topbit==0 \u3067\u3042\
    \u308B\u7A7A\u9593\u304B\u3089\u5076\u6570\u5168\u4F53\u3078\u306E\u5168\u5358\
    \u5C04\u304C\u3042\u308B.\n// \u3053\u308C\u3092\u524D\u8A08\u7B97\u3057\u305F\
    \u3044. \u7DDA\u5F62\u5199\u50CF\u306A\u306E\u3067\u9023\u7ACB\u65B9\u7A0B\u5F0F\
    \u3092\u89E3\u3044\u3066\u57CB\u3081\u8FBC\u3080\u3060\u3051\u3067\u3088\u3044\
    .\n\nu64 Q[4][65536];\n\nvoid __attribute__((constructor)) precalc() {\n  Basis<63>\
    \ B;\n  FOR(i, 63) {\n    Nimber64 x(u64(1) << (i + 1));\n    x = x.square() +\
    \ x;\n    assert(!B.solve_or_add(x.val).fi);\n  }\n  FOR(k, 63) {\n    int t =\
    \ k / 16, i = k % 16;\n    u64 X = B.way[k] * 2;\n    FOR(s, 1 << i) Q[t][s |\
    \ 1 << i] = Q[t][s] ^ X;\n  }\n}\n\nu16 f(u16 a) { return Q[0][a]; }\nu32 f(u32\
    \ a) { return Q[0][a & 65535] ^ Q[1][a >> 16]; }\nu64 f(u64 a) { return Q[0][a\
    \ & 65535] ^ Q[1][a >> 16 & 65535] ^ Q[2][a >> 32 & 65535] ^ Q[3][a >> 48 & 65535];\
    \ }\n\ntemplate <typename U>\nvc<U> solve_quadratic_1(U a) {\n  constexpr int\
    \ k = numeric_limits<U>::digits - 1;\n  if (a >> k & 1) return {};\n  return {f(a),\
    \ U(f(a) | 1)};\n}\n} // namespace NIMBER_QUADRATIC\n\ntemplate <typename F>\n\
    vc<F> solve_quadratic(F a, F b) {\n  if (a == F(0)) return {b.sqrt()};\n  b /=\
    \ a.square();\n  vc<F> ANS;\n  for (auto& x: NIMBER_QUADRATIC::solve_quadratic_1(b.val))\
    \ { ANS.eb(a * F(x)); }\n  return ANS;\n}\n"
  dependsOn:
  - nt/nimber/base.hpp
  - nt/nimber/nimber_impl.hpp
  - linalg/xor/basis.hpp
  isVerificationFile: false
  path: nt/nimber/solve_quadratic.hpp
  requiredBy: []
  timestamp: '2024-10-16 04:41:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/nimber.test.cpp
documentation_of: nt/nimber/solve_quadratic.hpp
layout: document
redirect_from:
- /library/nt/nimber/solve_quadratic.hpp
- /library/nt/nimber/solve_quadratic.hpp.html
title: nt/nimber/solve_quadratic.hpp
---
