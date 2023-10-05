---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/my_bitset.hpp
    title: ds/my_bitset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/my_bitset.hpp\"\n\n// https://codeforces.com/contest/914/problem/F\n\
    // https://yukicoder.me/problems/no/142\n// \u308F\u305A\u304B\u306B\u666E\u901A\
    \u306E bitset \u3088\u308A\u9045\u3044\u3068\u304D\u3082\u3042\u308B\u3088\u3046\
    \u3060\u304C\uFF0C\n// \u56FA\u5B9A\u9577\u306B\u3057\u305F\u304F\u306A\u3044\u3068\
    \u304D\u3084 slice \u64CD\u4F5C\u304C\u5FC5\u8981\u306A\u3068\u304D\u306B\u4F7F\
    \u3046\nstruct My_Bitset {\n  using T = My_Bitset;\n  int N;\n  vc<u64> dat;\n\
    \n  // x \u3067\u57CB\u3081\u308B\n  My_Bitset(int N = 0, int x = 0) : N(N) {\n\
    \    assert(x == 0 || x == 1);\n    u64 v = (x == 0 ? 0 : -1);\n    dat.assign((N\
    \ + 63) >> 6, v);\n    if (N) dat.back() >>= (64 * len(dat) - N);\n  }\n\n  int\
    \ size() { return N; }\n\n  void resize(int size) {\n    dat.resize((size + 63)\
    \ >> 6);\n    int remainingBits = size & 63;\n    if (remainingBits != 0) {\n\
    \      u64 mask = (u64(1) << remainingBits) - 1;\n      dat.back() &= mask;\n\
    \    }\n    N = size;\n  }\n\n  // thanks to chatgpt!\n  class Proxy {\n  public:\n\
    \    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}\n    operator bool() const\
    \ { return (dat[index >> 6] >> (index & 63)) & 1; }\n\n    Proxy &operator=(u64\
    \ value) {\n      dat[index >> 6] &= ~(u64(1) << (index & 63));\n      dat[index\
    \ >> 6] |= (value & 1) << (index & 63);\n      return *this;\n    }\n    void\
    \ flip() {\n      dat[index >> 6] ^= (u64(1) << (index & 63)); // XOR to flip\
    \ the bit\n    }\n\n  private:\n    vc<u64> &dat;\n    int index;\n  };\n\n  Proxy\
    \ operator[](int i) { return Proxy(dat, i); }\n\n  T &operator&=(const T &p) {\n\
    \    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] &= p.dat[i];\n    return *this;\n\
    \  }\n  T &operator|=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat))\
    \ dat[i] |= p.dat[i];\n    return *this;\n  }\n  T &operator^=(const T &p) {\n\
    \    assert(N == p.N);\n    FOR(i, len(dat)) dat[i] ^= p.dat[i];\n    return *this;\n\
    \  }\n  T operator&(const T &p) const { return T(*this) &= p; }\n  T operator|(const\
    \ T &p) const { return T(*this) |= p; }\n  T operator^(const T &p) const { return\
    \ T(*this) ^= p; }\n\n  int count() {\n    int ans = 0;\n    for (u64 val: dat)\
    \ ans += popcnt(val);\n    return ans;\n  }\n\n  int next(int i) {\n    chmax(i,\
    \ 0);\n    if (i >= N) return N;\n    int k = i >> 6;\n    {\n      u64 x = dat[k];\n\
    \      int s = i & 63;\n      x = (x >> s) << s;\n      if (x) return (k << 6)\
    \ | lowbit(x);\n    }\n    FOR(idx, k + 1, len(dat)) {\n      if (dat[idx] ==\
    \ 0) continue;\n      return (idx << 6) | lowbit(dat[idx]);\n    }\n    return\
    \ N;\n  }\n\n  int prev(int i) {\n    chmin(i, N - 1);\n    if (i <= -1) return\
    \ -1;\n    int k = i >> 6;\n    if ((i & 63) < 63) {\n      u64 x = dat[k];\n\
    \      x &= (u64(1) << ((i & 63) + 1)) - 1;\n      if (x) return (k << 6) | topbit(x);\n\
    \      --k;\n    }\n    FOR_R(idx, k + 1) {\n      if (dat[idx] == 0) continue;\n\
    \      return (idx << 6) | topbit(dat[idx]);\n    }\n    return -1;\n  }\n\n \
    \ My_Bitset range(int L, int R) {\n    assert(L <= R);\n    My_Bitset p(R - L);\n\
    \    int rm = (R - L) & 63;\n    FOR(rm) {\n      p[R - L - 1] = bool((*this)[R\
    \ - 1]);\n      --R;\n    }\n    int n = (R - L) >> 6;\n    int hi = L & 63;\n\
    \    int lo = 64 - hi;\n    int s = L >> 6;\n    if (hi == 0) {\n      FOR(i,\
    \ n) { p.dat[i] ^= dat[s + i]; }\n    } else {\n      FOR(i, n) { p.dat[i] ^=\
    \ (dat[s + i] >> hi) ^ (dat[s + i + 1] << lo); }\n    }\n    return p;\n  }\n\n\
    \  int count_range(int L, int R) {\n    assert(L <= R);\n    int cnt = 0;\n  \
    \  while ((L < R) && (L & 63)) cnt += (*this)[L++];\n    while ((L < R) && (R\
    \ & 63)) cnt += (*this)[--R];\n    int l = L >> 6, r = R >> 6;\n    FOR(i, l,\
    \ r) cnt += popcnt(dat[i]);\n    return cnt;\n  }\n\n  // [L,R) \u306B p \u3092\
    \u4EE3\u5165\n  void assign_to_range(int L, int R, My_Bitset &p) {\n    assert(p.N\
    \ == R - L);\n    int a = 0, b = p.N;\n    while (L < R && (L & 63)) { (*this)[L++]\
    \ = bool(p[a++]); }\n    while (L < R && (R & 63)) { (*this)[--R] = bool(p[--b]);\
    \ }\n    // p[a:b] \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int\
    \ s = a >> 6, t = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i,\
    \ n) dat[l + i] = p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int\
    \ lo = 64 - hi;\n      FOR(i, n) dat[l + i] = (p.dat[s + i] >> hi) | (p.dat[1\
    \ + s + i] << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 xor\n  void xor_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n\
    \      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n  \
    \    dat[R >> 6] ^= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] ^= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n \
    \   }\n  }\n\n  // [L,R) \u306B p \u3092 and\n  void and_to_range(int L, int R,\
    \ My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while\
    \ (L < R && (L & 63)) {\n      if (!p[a++]) (*this)[L++] = 0;\n    }\n    while\
    \ (L < R && (R & 63)) {\n      if (!p[--b]) (*this)[--R] = 0;\n    }\n    // p[a:b]\
    \ \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t\
    \ = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l +\
    \ i] &= p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64\
    \ - hi;\n      FOR(i, n) dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i]\
    \ << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 or\n  void or_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      dat[L >> 6] |= u64(p[a]) << (L & 63);\n\
    \      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n  \
    \    dat[R >> 6] |= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] |= p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n \
    \   }\n  }\n\n  string to_string() const {\n    string S;\n    FOR(i, N) S +=\
    \ '0' + (dat[i >> 6] >> (i & 63) & 1);\n    return S;\n  }\n\n  // bitset \u306B\
    \u4ED5\u69D8\u3092\u5408\u308F\u305B\u308B\n  void set(int i) { (*this)[i] = 1;\
    \ }\n  void reset(int i) { (*this)[i] = 0; }\n  void flip(int i) { (*this)[i].flip();\
    \ }\n  void set() { fill(all(dat), 0); }\n  void reset() {\n    fill(all(dat),\
    \ u64(-1));\n    resize(N);\n  }\n\n  int _Find_first() { return next(0); }\n\
    \  int _Find_next(int p) { return next(p + 1); }\n};\n#line 2 \"linalg/bitset/mat_inv.hpp\"\
    \n\n// det = 0 \u306E\u5834\u5408\u306B\u306F empty \u3092\u304B\u3048\u3059\n\
    template <typename BS>\nvc<BS> mat_inv(vc<BS> A) {\n  int N = len(A);\n  vc<BS>\
    \ B(N);\n  if constexpr (is_same_v<BS, My_Bitset>) { FOR(i, N) B[i] = BS(N); }\n\
    \  FOR(i, N) B[i][i] = 1;\n  FOR(i, N) {\n    FOR(k, i + 1, N) if (A[k][i]) {\n\
    \      swap(A[k], A[i]);\n      swap(B[k], B[i]);\n      break;\n    }\n    if\
    \ (!A[i][i]) return {};\n    FOR(k, N) {\n      if (i == k) continue;\n      if\
    \ (A[k][i]) {\n        A[k] ^= A[i];\n        B[k] ^= B[i];\n      }\n    }\n\
    \  }\n  return B;\n}\n"
  code: "#include \"ds/my_bitset.hpp\"\n\n// det = 0 \u306E\u5834\u5408\u306B\u306F\
    \ empty \u3092\u304B\u3048\u3059\ntemplate <typename BS>\nvc<BS> mat_inv(vc<BS>\
    \ A) {\n  int N = len(A);\n  vc<BS> B(N);\n  if constexpr (is_same_v<BS, My_Bitset>)\
    \ { FOR(i, N) B[i] = BS(N); }\n  FOR(i, N) B[i][i] = 1;\n  FOR(i, N) {\n    FOR(k,\
    \ i + 1, N) if (A[k][i]) {\n      swap(A[k], A[i]);\n      swap(B[k], B[i]);\n\
    \      break;\n    }\n    if (!A[i][i]) return {};\n    FOR(k, N) {\n      if\
    \ (i == k) continue;\n      if (A[k][i]) {\n        A[k] ^= A[i];\n        B[k]\
    \ ^= B[i];\n      }\n    }\n  }\n  return B;\n}\n"
  dependsOn:
  - ds/my_bitset.hpp
  isVerificationFile: false
  path: linalg/bitset/mat_inv.hpp
  requiredBy: []
  timestamp: '2023-10-06 05:10:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/bitset/mat_inv.hpp
layout: document
redirect_from:
- /library/linalg/bitset/mat_inv.hpp
- /library/linalg/bitset/mat_inv.hpp.html
title: linalg/bitset/mat_inv.hpp
---
