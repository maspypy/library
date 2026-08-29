---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/4_aoj/ALDS1_14_C.test.cpp
    title: test/4_aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/958/problem/A2
  bundledCode: "#line 1 \"mod/modint61.hpp\"\n\nstruct modint61 {\n  static constexpr\
    \ u64 mod = (1ULL << 61) - 1;\n  u64 val;\n  constexpr modint61() : val(0ULL)\
    \ {}\n  constexpr modint61(u32 x) : val(x) {}\n  constexpr modint61(u64 x) : val(x\
    \ % mod) {}\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\n  constexpr modint61(ll x) : val(((x %= static_cast<ll>(mod)) < 0)\
    \ ? (x + static_cast<ll>(mod)) : x) {}\n  static constexpr u64 get_mod() { return\
    \ mod; }\n\n  modint61 &operator+=(const modint61 &a) {\n    val = ((val += a.val)\
    \ >= mod) ? (val - mod) : val;\n    return *this;\n  }\n  modint61 &operator-=(const\
    \ modint61 &a) {\n    val = ((val -= a.val) >= mod) ? (val + mod) : val;\n   \
    \ return *this;\n  }\n  modint61 &operator*=(const modint61 &a) {\n    const unsigned\
    \ __int128 y = static_cast<unsigned __int128>(val) * a.val;\n    val = (y >> 61)\
    \ + (y & mod);\n    val = (val >= mod) ? (val - mod) : val;\n    return *this;\n\
    \  }\n  modint61 operator-() const { return modint61(val ? mod - val : u64(0));\
    \ }\n  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse());\
    \ }\n  modint61 operator+(const modint61 &p) const { return modint61(*this) +=\
    \ p; }\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\n  bool operator<(const modint61 &other) const { return val < other.val;\
    \ }\n  bool operator==(const modint61 &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint61 &p) const { return val != p.val; }\n  modint61 inverse()\
    \ const {\n    ll a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n  \
    \    t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ modint61(u);\n  }\n  modint61 pow(ll n) const {\n    assert(n >= 0);\n    modint61\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul, n >>= 1;\n    }\n    return ret;\n  }\n};\n\n#ifdef FASTIO\nvoid\
    \ rd(modint61 &x) {\n  fastio::rd(x.val);\n  assert(0 <= x.val && x.val < modint61::mod);\n\
    }\n\nvoid wt(modint61 x) { fastio::wt(x.val); }\n#endif\n#line 1 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 3 \"string/rolling_hash_2d.hpp\"\n\n// https://codeforces.com/contest/958/problem/A2\n\
    struct Rolling_Hash_2D {\n  using M61 = modint61;\n  const M61 b1, b2;\n  vc<M61>\
    \ pow1;\n  vc<M61> pow2;\n\n  Rolling_Hash_2D()\n      : b1(generate_base()),\
    \ b2(generate_base()), pow1{M61(1)}, pow2{M61(1)} {}\n\n  template <typename STRING>\n\
    \  vvc<M61> build(const vc<STRING> &S) {\n    int H = len(S);\n    int W = len(S[0]);\n\
    \    vv(M61, res, H + 1, W + 1);\n    FOR(x, H) {\n      FOR(y, W) { res[x + 1][y\
    \ + 1] = res[x + 1][y] * b2 + M61(S[x][y] + 1); }\n      FOR(y, W + 1) res[x +\
    \ 1][y] += b1 * res[x][y];\n    }\n    expand(pow1, b1, H);\n    expand(pow2,\
    \ b2, W);\n    return res;\n  }\n\n  M61 query(const vvc<M61> &A, int xl, int\
    \ xr, int yl, int yr) {\n    assert(0 <= xl && xl <= xr && xr <= len(A));\n  \
    \  assert(0 <= yl && yl <= yr && yr <= len(A[0]));\n    M61 a = A[xr][yr] - A[xr][yl]\
    \ * pow2[yr - yl];\n    M61 b = A[xl][yr] - A[xl][yl] * pow2[yr - yl];\n    return\
    \ a - b * pow1[xr - xl];\n  }\n\n private:\n  static inline u64 generate_base()\
    \ { return RNG(M61::get_mod()); }\n\n  void expand(vc<M61> &pow, const M61 &b,\
    \ int n) {\n    while (len(pow) <= n) pow.eb(pow.back() * b);\n  }\n};\n"
  code: "#include \"mod/modint61.hpp\"\n#include \"random/base.hpp\"\n\n// https://codeforces.com/contest/958/problem/A2\n\
    struct Rolling_Hash_2D {\n  using M61 = modint61;\n  const M61 b1, b2;\n  vc<M61>\
    \ pow1;\n  vc<M61> pow2;\n\n  Rolling_Hash_2D()\n      : b1(generate_base()),\
    \ b2(generate_base()), pow1{M61(1)}, pow2{M61(1)} {}\n\n  template <typename STRING>\n\
    \  vvc<M61> build(const vc<STRING> &S) {\n    int H = len(S);\n    int W = len(S[0]);\n\
    \    vv(M61, res, H + 1, W + 1);\n    FOR(x, H) {\n      FOR(y, W) { res[x + 1][y\
    \ + 1] = res[x + 1][y] * b2 + M61(S[x][y] + 1); }\n      FOR(y, W + 1) res[x +\
    \ 1][y] += b1 * res[x][y];\n    }\n    expand(pow1, b1, H);\n    expand(pow2,\
    \ b2, W);\n    return res;\n  }\n\n  M61 query(const vvc<M61> &A, int xl, int\
    \ xr, int yl, int yr) {\n    assert(0 <= xl && xl <= xr && xr <= len(A));\n  \
    \  assert(0 <= yl && yl <= yr && yr <= len(A[0]));\n    M61 a = A[xr][yr] - A[xr][yl]\
    \ * pow2[yr - yl];\n    M61 b = A[xl][yr] - A[xl][yl] * pow2[yr - yl];\n    return\
    \ a - b * pow1[xr - xl];\n  }\n\n private:\n  static inline u64 generate_base()\
    \ { return RNG(M61::get_mod()); }\n\n  void expand(vc<M61> &pow, const M61 &b,\
    \ int n) {\n    while (len(pow) <= n) pow.eb(pow.back() * b);\n  }\n};\n"
  dependsOn:
  - mod/modint61.hpp
  - random/base.hpp
  isVerificationFile: false
  path: string/rolling_hash_2d.hpp
  requiredBy: []
  timestamp: '2026-08-17 10:29:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/4_aoj/ALDS1_14_C.test.cpp
documentation_of: string/rolling_hash_2d.hpp
layout: document
redirect_from:
- /library/string/rolling_hash_2d.hpp
- /library/string/rolling_hash_2d.hpp.html
title: string/rolling_hash_2d.hpp
---
