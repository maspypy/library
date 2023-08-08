---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n\
    \      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n              \
    \       chrono::high_resolution_clock::now().time_since_epoch())\n           \
    \          .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n \
    \ return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"mod/modint61.hpp\"\
    \n\r\n// https : // yosupo.hatenablog.com/entry/2023/08/06/181942\r\n// x \u306E\
    \u4EE3\u308F\u308A\u306B 8x \u3092 [8, 8MOD] \u3067\u6301\u3064\r\nstruct modint61\
    \ {\r\n  static constexpr u64 MOD = (1ULL << 61) - 1;\r\n  static constexpr u64\
    \ MOD8 = MOD * 8;\r\n  u64 x8;\r\n  constexpr modint61() : x8(MOD8) {}\r\n  constexpr\
    \ modint61(u32 x) : x8((x + MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(u64\
    \ x) : x8((x + MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(int x) : x8((x\
    \ + MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(ll x)\r\n      : x8(8 *\
    \ (((x %= ll(MOD)) <= 0) ? (x + ll(MOD)) : x)) {}\r\n\r\n  static constexpr u64\
    \ get_mod() { return MOD; }\r\n  modint61 &operator+=(const modint61 &a) {\r\n\
    \    if (__builtin_uaddll_overflow(x8, a.x8, &x8)) x8 -= MOD8;\r\n    return *this;\r\
    \n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n    if (__builtin_uaddll_overflow(x8,\
    \ MOD8 - a.x8, &x8)) x8 -= MOD8;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &a) {\r\n    u128 c = u128(x8) * (a.x8);\r\n    u64 x = c >> 67 <<\
    \ 3, y = c << 61 >> 64;\r\n    if (__builtin_uaddll_overflow(x, y, &x8)) x8 -=\
    \ MOD8;\r\n    return *this;\r\n  }\r\n  modint61 &operator/=(const modint61 &a)\
    \ { return (*this *= a.inverse()); }\r\n  modint61 operator+(const modint61 &p)\
    \ const { return modint61(*this) += p; }\r\n  modint61 operator-(const modint61\
    \ &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const modint61\
    \ &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const modint61\
    \ &p) const { return modint61(*this) /= p; }\r\n  bool operator==(const modint61\
    \ &p) const { return x8 == p.x8; }\r\n  bool operator!=(const modint61 &p) const\
    \ { return x8 != p.x8; }\r\n  u64 val() const { return (x8 == MOD8 ? 0 : x8 >>\
    \ 3); }\r\n  modint61 inverse() const {\r\n    ll a = val(), b = MOD, u = 1, v\
    \ = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b,\
    \ b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61\
    \ pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1);\r\n    modint61\
    \ mul = (*this);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n  \
    \    mul *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n\r\n#ifdef FASTIO\r\
    \n  void write() { fastio::printer.write(val()); }\r\n  void read() {\r\n    ll\
    \ x;\r\n    fastio::scanner.read(x);\r\n    x8 = 8 * (((x %= ll(MOD)) <= 0) ?\
    \ (x + ll(MOD)) : x);\r\n  }\r\n#endif\r\n};\n#line 3 \"string/rollinghash_2d.hpp\"\
    \n\nstruct RollingHash_2D {\n  using M61 = modint61;\n  const M61 b1, b2;\n  vc<M61>\
    \ pow1;\n  vc<M61> pow2;\n\n  RollingHash_2D()\n      : b1(generate_base()), b2(generate_base()),\
    \ pow1{M61(1)}, pow2{M61(1)} {}\n\n  template <typename STRING>\n  vvc<M61> build(const\
    \ vc<STRING>& S) {\n    int H = len(S);\n    int W = len(S[0]);\n    vv(M61, res,\
    \ H + 1, W + 1);\n    FOR(x, H) {\n      FOR(y, W) { res[x + 1][y + 1] = res[x\
    \ + 1][y] * b2 + M61(S[x][y] + 1); }\n      FOR(y, W + 1) res[x + 1][y] += b1\
    \ * res[x][y];\n    }\n    expand(pow1, b1, H);\n    expand(pow2, b2, W);\n  \
    \  return res;\n  }\n\n  M61 query(const vvc<M61>& A, int xl, int xr, int yl,\
    \ int yr) {\n    assert(0 <= xl && xl <= xr && xr <= len(A));\n    assert(0 <=\
    \ yl && yl <= yr && yr <= len(A[0]));\n    M61 a = A[xr][yr] - A[xr][yl] * pow2[yr\
    \ - yl];\n    M61 b = A[xl][yr] - A[xl][yl] * pow2[yr - yl];\n    return a - b\
    \ * pow1[xr - xl];\n  }\n\nprivate:\n  static inline u64 generate_base() { return\
    \ RNG(M61::get_mod()); }\n\n  void expand(vc<M61>& pow, const M61& b, int n) {\n\
    \    while (len(pow) <= n) pow.eb(pow.back() * b);\n  }\n};\n"
  code: "#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\n\nstruct RollingHash_2D\
    \ {\n  using M61 = modint61;\n  const M61 b1, b2;\n  vc<M61> pow1;\n  vc<M61>\
    \ pow2;\n\n  RollingHash_2D()\n      : b1(generate_base()), b2(generate_base()),\
    \ pow1{M61(1)}, pow2{M61(1)} {}\n\n  template <typename STRING>\n  vvc<M61> build(const\
    \ vc<STRING>& S) {\n    int H = len(S);\n    int W = len(S[0]);\n    vv(M61, res,\
    \ H + 1, W + 1);\n    FOR(x, H) {\n      FOR(y, W) { res[x + 1][y + 1] = res[x\
    \ + 1][y] * b2 + M61(S[x][y] + 1); }\n      FOR(y, W + 1) res[x + 1][y] += b1\
    \ * res[x][y];\n    }\n    expand(pow1, b1, H);\n    expand(pow2, b2, W);\n  \
    \  return res;\n  }\n\n  M61 query(const vvc<M61>& A, int xl, int xr, int yl,\
    \ int yr) {\n    assert(0 <= xl && xl <= xr && xr <= len(A));\n    assert(0 <=\
    \ yl && yl <= yr && yr <= len(A[0]));\n    M61 a = A[xr][yr] - A[xr][yl] * pow2[yr\
    \ - yl];\n    M61 b = A[xl][yr] - A[xl][yl] * pow2[yr - yl];\n    return a - b\
    \ * pow1[xr - xl];\n  }\n\nprivate:\n  static inline u64 generate_base() { return\
    \ RNG(M61::get_mod()); }\n\n  void expand(vc<M61>& pow, const M61& b, int n) {\n\
    \    while (len(pow) <= n) pow.eb(pow.back() * b);\n  }\n};\n"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: string/rollinghash_2d.hpp
  requiredBy: []
  timestamp: '2023-08-08 01:44:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_C.test.cpp
documentation_of: string/rollinghash_2d.hpp
layout: document
redirect_from:
- /library/string/rollinghash_2d.hpp
- /library/string/rollinghash_2d.hpp.html
title: string/rollinghash_2d.hpp
---
