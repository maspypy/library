---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/142.test.cpp
    title: test/yukicoder/142.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/914/problem/F
  bundledCode: "#line 1 \"ds/my_bitset.hpp\"\n\n// https://codeforces.com/contest/914/problem/F\n\
    struct My_Bitset {\n  using T = My_Bitset;\n  int N;\n  vc<u64> dat;\n\n  // x\
    \ \u3067\u57CB\u3081\u308B\n  My_Bitset(int N = 0, int x = 0) : N(N) {\n    assert(x\
    \ == 0 || x == 1);\n    u64 v = (x == 0 ? 0 : -1);\n    dat.assign(ceil(N, 64),\
    \ v);\n    dat.back() >>= (64 * len(dat) - N);\n  }\n\n  bool operator[](int idx)\
    \ { return dat[idx >> 6] >> (idx & 63) & 1; }\n  void on(int idx) { dat[idx >>\
    \ 6] |= u64(1) << (idx & 63); }\n  void off(int idx) { dat[idx >> 6] &= ~(u64(1)\
    \ << (idx & 63)); }\n  void flip(int idx) { dat[idx >> 6] ^= u64(1) << (idx &\
    \ 63); }\n\n  T &operator&=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat))\
    \ dat[i] &= p.dat[i];\n    return *this;\n  }\n  T &operator|=(const T &p) {\n\
    \    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] |= p.dat[i];\n    return *this;\n\
    \  }\n  T &operator^=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat))\
    \ dat[i] ^= p.dat[i];\n    return *this;\n  }\n  T operator&(const T &p) const\
    \ { return T(*this) &= p; }\n  T operator|(const T &p) const { return T(*this)\
    \ |= p; }\n  T operator^(const T &p) const { return T(*this) ^= p; }\n\n  int\
    \ count() {\n    int ans = 0;\n    for (u64 val: dat) ans += popcnt(val);\n  \
    \  return ans;\n  }\n\n  My_Bitset range(int L, int R) {\n    assert(L <= R);\n\
    \    My_Bitset p(R - L);\n    int rm = (R - L) & 63;\n    FOR(rm) {\n      if\
    \ ((*this)[R - 1]) p.on(R - L - 1);\n      --R;\n    }\n    int n = (R - L) >>\
    \ 6;\n    int hi = L & 63;\n    int lo = 64 - hi;\n    int s = L >> 6;\n    if\
    \ (hi == 0) {\n      FOR(i, n) { p.dat[i] ^= dat[s + i]; }\n    } else {\n   \
    \   FOR(i, n) { p.dat[i] ^= (dat[s + i] >> hi) ^ (dat[s + i + 1] << lo); }\n \
    \   }\n    return p;\n  }\n\n  int count_range(int L, int R) {\n    assert(L <=\
    \ R);\n    int cnt = 0;\n    while ((L < R) && (L & 63)) cnt += (*this)[L++];\n\
    \    while ((L < R) && (R & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r =\
    \ R >> 6;\n    FOR(i, l, r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n \
    \ // [L,R) \u306B p \u3092\u4EE3\u5165\n  void assign_to_range(int L, int R, My_Bitset\
    \ &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R\
    \ && (L & 63)) {\n      if (p[a++])\n        on(L++);\n      else\n        off(L++);\n\
    \    }\n    while (L < R && (R & 63)) {\n      if (p[--b])\n        on(--R);\n\
    \      else\n        off(--R);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n   \
    \ int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r\
    \ - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] = p.dat[s + i];\n   \
    \ } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l\
    \ + i] = (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  //\
    \ [L,R) \u306B p \u3092 xor\n  void xor_to_range(int L, int R, My_Bitset &p) {\n\
    \    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L &\
    \ 63)) {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n      ++a, ++L;\n    }\n\
    \    while (L < R && (R & 63)) {\n      --b, --R;\n      dat[R >> 6] ^= u64(p[b])\
    \ << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6,\
    \ r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a\
    \ & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s + i];\n    } else {\n      int\
    \ hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l + i] ^= (p.dat[s\
    \ + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092\
    \ and\n  void and_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N == R\
    \ - L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63)) {\n      if (!p[a++])\
    \ off(L++);\n    }\n    while (L < R && (R & 63)) {\n      if (!p[--b]) off(--R);\n\
    \    }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n \
    \   int s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n  \
    \    FOR(i, n) dat[l + i] &= p.dat[s + i];\n    } else {\n      int hi = a & 63;\n\
    \      int lo = 64 - hi;\n      FOR(i, n) dat[l + i] &= (p.dat[s + i] >> hi) |\
    \ (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 or\n  void\
    \ or_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int\
    \ a = 0, b = p.N;\n    while (L < R && (L & 63)) {\n      dat[L >> 6] |= u64(p[a])\
    \ << (L & 63);\n      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n    \
    \  --b, --R;\n      dat[R >> 6] |= u64(p[b]) << (R & 63);\n    }\n    // p[a:b]\
    \ \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t\
    \ = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l +\
    \ i] |= p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64\
    \ - hi;\n      FOR(i, n) dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1 + s + i]\
    \ << lo);\n    }\n  }\n\n  string to_string() const {\n    string S;\n    FOR(i,\
    \ N) S += '0' + (dat[i >> 6] >> (i & 63) & 1);\n    return S;\n  }\n};\n"
  code: "\n// https://codeforces.com/contest/914/problem/F\nstruct My_Bitset {\n \
    \ using T = My_Bitset;\n  int N;\n  vc<u64> dat;\n\n  // x \u3067\u57CB\u3081\u308B\
    \n  My_Bitset(int N = 0, int x = 0) : N(N) {\n    assert(x == 0 || x == 1);\n\
    \    u64 v = (x == 0 ? 0 : -1);\n    dat.assign(ceil(N, 64), v);\n    dat.back()\
    \ >>= (64 * len(dat) - N);\n  }\n\n  bool operator[](int idx) { return dat[idx\
    \ >> 6] >> (idx & 63) & 1; }\n  void on(int idx) { dat[idx >> 6] |= u64(1) <<\
    \ (idx & 63); }\n  void off(int idx) { dat[idx >> 6] &= ~(u64(1) << (idx & 63));\
    \ }\n  void flip(int idx) { dat[idx >> 6] ^= u64(1) << (idx & 63); }\n\n  T &operator&=(const\
    \ T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] &= p.dat[i];\n \
    \   return *this;\n  }\n  T &operator|=(const T &p) {\n    assert(N == p.N);\n\
    \    FOR(i, len(dat)) dat[i] |= p.dat[i];\n    return *this;\n  }\n  T &operator^=(const\
    \ T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] ^= p.dat[i];\n \
    \   return *this;\n  }\n  T operator&(const T &p) const { return T(*this) &= p;\
    \ }\n  T operator|(const T &p) const { return T(*this) |= p; }\n  T operator^(const\
    \ T &p) const { return T(*this) ^= p; }\n\n  int count() {\n    int ans = 0;\n\
    \    for (u64 val: dat) ans += popcnt(val);\n    return ans;\n  }\n\n  My_Bitset\
    \ range(int L, int R) {\n    assert(L <= R);\n    My_Bitset p(R - L);\n    int\
    \ rm = (R - L) & 63;\n    FOR(rm) {\n      if ((*this)[R - 1]) p.on(R - L - 1);\n\
    \      --R;\n    }\n    int n = (R - L) >> 6;\n    int hi = L & 63;\n    int lo\
    \ = 64 - hi;\n    int s = L >> 6;\n    if (hi == 0) {\n      FOR(i, n) { p.dat[i]\
    \ ^= dat[s + i]; }\n    } else {\n      FOR(i, n) { p.dat[i] ^= (dat[s + i] >>\
    \ hi) ^ (dat[s + i + 1] << lo); }\n    }\n    return p;\n  }\n\n  int count_range(int\
    \ L, int R) {\n    assert(L <= R);\n    int cnt = 0;\n    while ((L < R) && (L\
    \ & 63)) cnt += (*this)[L++];\n    while ((L < R) && (R & 63)) cnt += (*this)[--R];\n\
    \    int l = L >> 6, r = R >> 6;\n    FOR(i, l, r) cnt += popcnt(dat[i]);\n  \
    \  return cnt;\n  }\n\n  // [L,R) \u306B p \u3092\u4EE3\u5165\n  void assign_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      if (p[a++])\n        on(L++);\n      else\n\
    \        off(L++);\n    }\n    while (L < R && (R & 63)) {\n      if (p[--b])\n\
    \        on(--R);\n      else\n        off(--R);\n    }\n    // p[a:b] \u3092\
    \ [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >>\
    \ t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] = p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] = (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n  \
    \  }\n  }\n\n  // [L,R) \u306B p \u3092 xor\n  void xor_to_range(int L, int R,\
    \ My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while\
    \ (L < R && (L & 63)) {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n      ++a,\
    \ ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n      dat[R >>\
    \ 6] ^= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n   \
    \ int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r\
    \ - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s + i];\n  \
    \  } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n)\
    \ dat[l + i] ^= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\
    \n  // [L,R) \u306B p \u3092 and\n  void and_to_range(int L, int R, My_Bitset\
    \ &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R\
    \ && (L & 63)) {\n      if (!p[a++]) off(L++);\n    }\n    while (L < R && (R\
    \ & 63)) {\n      if (!p[--b]) off(--R);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\
    \n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n\
    \ = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] &= p.dat[s + i];\n\
    \    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n)\
    \ dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\
    \n  // [L,R) \u306B p \u3092 or\n  void or_to_range(int L, int R, My_Bitset &p)\
    \ {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L\
    \ & 63)) {\n      dat[L >> 6] |= u64(p[a]) << (L & 63);\n      ++a, ++L;\n   \
    \ }\n    while (L < R && (R & 63)) {\n      --b, --R;\n      dat[R >> 6] |= u64(p[b])\
    \ << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6,\
    \ r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a\
    \ & 63)) {\n      FOR(i, n) dat[l + i] |= p.dat[s + i];\n    } else {\n      int\
    \ hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n) dat[l + i] |= (p.dat[s\
    \ + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\n  string to_string()\
    \ const {\n    string S;\n    FOR(i, N) S += '0' + (dat[i >> 6] >> (i & 63) &\
    \ 1);\n    return S;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/my_bitset.hpp
  requiredBy: []
  timestamp: '2023-07-06 13:23:05+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/142.test.cpp
documentation_of: ds/my_bitset.hpp
layout: document
redirect_from:
- /library/ds/my_bitset.hpp
- /library/ds/my_bitset.hpp.html
title: ds/my_bitset.hpp
---
