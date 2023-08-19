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
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2102.test.cpp
    title: test/yukicoder/2102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2231.test.cpp
    title: test/yukicoder/2231.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/263.test.cpp
    title: test/yukicoder/263.test.cpp
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
    \n\r\nstruct modint61 {\r\n  static constexpr u64 mod = (1ULL << 61) - 1;\r\n\
    \  u64 val;\r\n  constexpr modint61() : val(0ULL) {}\r\n  constexpr modint61(u32\
    \ x) : val(x) {}\r\n  constexpr modint61(u64 x) : val(x % mod) {}\r\n  constexpr\
    \ modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod)) : x) {}\r\n  constexpr\
    \ modint61(ll x)\r\n      : val(((x %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod))\r\
    \n                                              : x) {}\r\n  static constexpr\
    \ u64 get_mod() { return mod; }\r\n  modint61 &operator+=(const modint61 &a) {\r\
    \n    val = ((val += a.val) >= mod) ? (val - mod) : val;\r\n    return *this;\r\
    \n  }\r\n  modint61 &operator-=(const modint61 &a) {\r\n    val = ((val -= a.val)\
    \ >= mod) ? (val + mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const\
    \ modint61 &a) {\r\n    const unsigned __int128 y = static_cast<unsigned __int128>(val)\
    \ * a.val;\r\n    val = (y >> 61) + (y & mod);\r\n    val = (val >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator/=(const modint61\
    \ &a) { return (*this *= a.inverse()); }\r\n  modint61 operator+(const modint61\
    \ &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const modint61\
    \ &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const modint61\
    \ &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const modint61\
    \ &p) const { return modint61(*this) /= p; }\r\n  bool operator==(const modint61\
    \ &p) const { return val == p.val; }\r\n  bool operator!=(const modint61 &p) const\
    \ { return val != p.val; }\r\n  modint61 inverse() const {\r\n    ll a = val,\
    \ b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\n   \
    \   swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\
    \n  }\r\n  modint61 pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1),\
    \ mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul\
    \ *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n#ifdef FASTIO\r\n  void\
    \ write() { fastio::printer.write(val); }\r\n  void read() {\r\n    ll x;\r\n\
    \    fastio::scanner.read(x);\r\n    val = (val >= 0 ? val % mod : (mod - (-val)\
    \ % mod) % mod);\r\n  }\r\n#endif\r\n};\n#line 4 \"string/rollinghash.hpp\"\n\n\
    struct RollingHash {\n  using mint = modint61;\n  static constexpr u64 mod = mint::get_mod();\n\
    \  const mint base;\n  vc<mint> power;\n\n  static inline mint generate_base()\
    \ { return RNG(mod); }\n\n  inline void expand(size_t sz) {\n    if (power.size()\
    \ < sz + 1) {\n      int pre_sz = (int)power.size();\n      power.resize(sz +\
    \ 1);\n      FOR(i, pre_sz - 1, sz) power[i + 1] = power[i] * base;\n    }\n \
    \ }\n\n  explicit RollingHash(mint base = generate_base()) : base(base), power{1}\
    \ {}\n\n  template <typename STRING>\n  vector<mint> build(const STRING& s) const\
    \ {\n    int sz = s.size();\n    vector<mint> hashed(sz + 1, mint(0));\n    for\
    \ (int i = 0; i < sz; i++) { hashed[i + 1] = hashed[i] * base + s[i]; }\n    return\
    \ hashed;\n  }\n\n  mint from_char(char x) { return x; }\n\n  mint query(const\
    \ vc<mint>& s, int l, int r) {\n    expand(r - l);\n    return (s[r] - s[l] *\
    \ power[r - l]);\n  }\n\n  mint combine(mint h1, mint h2, int h2len) {\n    expand(h2len);\n\
    \    return h1 * power[h2len] + h2;\n  }\n\n  mint add_char(mint h, int x) { return\
    \ h * base + mint(x); }\n\n  int lcp(const vc<mint>& a, int l1, int r1, const\
    \ vc<mint>& b, int l2,\n          int r2) {\n    int len = min(r1 - l1, r2 - l2);\n\
    \    int low = 0, high = len + 1;\n    while (high - low > 1) {\n      int mid\
    \ = (low + high) / 2;\n      if (query(a, l1, l1 + mid) == query(b, l2, l2 + mid))\n\
    \        low = mid;\n      else\n        high = mid;\n    }\n    return low;\n\
    \  }\n};\n"
  code: "#pragma once\n#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\
    \n\nstruct RollingHash {\n  using mint = modint61;\n  static constexpr u64 mod\
    \ = mint::get_mod();\n  const mint base;\n  vc<mint> power;\n\n  static inline\
    \ mint generate_base() { return RNG(mod); }\n\n  inline void expand(size_t sz)\
    \ {\n    if (power.size() < sz + 1) {\n      int pre_sz = (int)power.size();\n\
    \      power.resize(sz + 1);\n      FOR(i, pre_sz - 1, sz) power[i + 1] = power[i]\
    \ * base;\n    }\n  }\n\n  explicit RollingHash(mint base = generate_base()) :\
    \ base(base), power{1} {}\n\n  template <typename STRING>\n  vector<mint> build(const\
    \ STRING& s) const {\n    int sz = s.size();\n    vector<mint> hashed(sz + 1,\
    \ mint(0));\n    for (int i = 0; i < sz; i++) { hashed[i + 1] = hashed[i] * base\
    \ + s[i]; }\n    return hashed;\n  }\n\n  mint from_char(char x) { return x; }\n\
    \n  mint query(const vc<mint>& s, int l, int r) {\n    expand(r - l);\n    return\
    \ (s[r] - s[l] * power[r - l]);\n  }\n\n  mint combine(mint h1, mint h2, int h2len)\
    \ {\n    expand(h2len);\n    return h1 * power[h2len] + h2;\n  }\n\n  mint add_char(mint\
    \ h, int x) { return h * base + mint(x); }\n\n  int lcp(const vc<mint>& a, int\
    \ l1, int r1, const vc<mint>& b, int l2,\n          int r2) {\n    int len = min(r1\
    \ - l1, r2 - l2);\n    int low = 0, high = len + 1;\n    while (high - low > 1)\
    \ {\n      int mid = (low + high) / 2;\n      if (query(a, l1, l1 + mid) == query(b,\
    \ l2, l2 + mid))\n        low = mid;\n      else\n        high = mid;\n    }\n\
    \    return low;\n  }\n};\n"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  isVerificationFile: false
  path: string/rollinghash.hpp
  requiredBy: []
  timestamp: '2023-08-13 16:19:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2231.test.cpp
  - test/yukicoder/263.test.cpp
  - test/yukicoder/2102.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
documentation_of: string/rollinghash.hpp
layout: document
redirect_from:
- /library/string/rollinghash.hpp
- /library/string/rollinghash.hpp.html
title: string/rollinghash.hpp
---
