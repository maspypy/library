---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/matrix_rank.hpp
    title: linalg/matrix_rank.hpp
  - icon: ':question:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':x:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ (x + ll(MOD)) : x);\r\n  }\r\n#endif\r\n};\n#line 1 \"linalg/matrix_rank.hpp\"\
    \ntemplate <typename T>\nint matrix_rank(const int n, const int m, vc<vc<T>> a)\
    \ {\n  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    if (a[rk][j] ==\
    \ 0) {\n      FOR3(i, rk + 1, n) if (a[i][j] != T(0)) {\n        swap(a[rk], a[i]);\n\
    \        break;\n      }\n    }\n    if (a[rk][j] == 0) continue;\n    T c = T(1)\
    \ / a[rk][j];\n    FOR(k, j, m) a[rk][k] *= c;\n    FOR(i, rk + 1, n) {\n    \
    \  T c = a[i][j];\n      FOR3(k, j, m) { a[i][k] -= a[rk][k] * c; }\n    }\n \
    \   ++rk;\n  }\n  return rk;\n}\n#line 4 \"graph/max_matching_size.hpp\"\n\ntemplate\
    \ <typename GT>\nint max_matching_size(GT& G) {\n  using mint = modint61;\n  assert(!G.is_directed());\n\
    \  int N = G.N;\n  vv(mint, tutte, N, N);\n  for (auto&& e: G.edges) {\n    mint\
    \ x = RNG(mint::get_mod());\n    int i = e.frm, j = e.to;\n    tutte[i][j] +=\
    \ x;\n    tutte[j][i] -= x;\n  }\n  return matrix_rank(N, N, tutte) / 2;\n}\n"
  code: "#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\n#include \"\
    linalg/matrix_rank.hpp\"\n\ntemplate <typename GT>\nint max_matching_size(GT&\
    \ G) {\n  using mint = modint61;\n  assert(!G.is_directed());\n  int N = G.N;\n\
    \  vv(mint, tutte, N, N);\n  for (auto&& e: G.edges) {\n    mint x = RNG(mint::get_mod());\n\
    \    int i = e.frm, j = e.to;\n    tutte[i][j] += x;\n    tutte[j][i] -= x;\n\
    \  }\n  return matrix_rank(N, N, tutte) / 2;\n}\n"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  - linalg/matrix_rank.hpp
  isVerificationFile: false
  path: graph/max_matching_size.hpp
  requiredBy: []
  timestamp: '2023-08-08 01:44:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/matching_line_graph.test.cpp
  - test/mytest/tutte.test.cpp
documentation_of: graph/max_matching_size.hpp
layout: document
redirect_from:
- /library/graph/max_matching_size.hpp
- /library/graph/max_matching_size.hpp.html
title: graph/max_matching_size.hpp
---
