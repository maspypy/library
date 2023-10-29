---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/general_matching.test.cpp
    title: test/library_checker/graph/general_matching.test.cpp
  - icon: ':x:'
    path: test/mytest/matching.test.cpp
    title: test/mytest/matching.test.cpp
  - icon: ':x:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':x:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ % mod) % mod);\r\n  }\r\n#endif\r\n};\n#line 1 \"linalg/matrix_rank.hpp\"\n\
    template <typename T>\nint matrix_rank(const int n, const int m, vc<vc<T>> a)\
    \ {\n  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    if (a[rk][j] ==\
    \ 0) {\n      FOR3(i, rk + 1, n) if (a[i][j] != T(0)) {\n        swap(a[rk], a[i]);\n\
    \        break;\n      }\n    }\n    if (a[rk][j] == 0) continue;\n    T c = T(1)\
    \ / a[rk][j];\n    FOR(k, j, m) a[rk][k] *= c;\n    FOR(i, rk + 1, n) {\n    \
    \  T c = a[i][j];\n      FOR3(k, j, m) { a[i][k] -= a[rk][k] * c; }\n    }\n \
    \   ++rk;\n  }\n  return rk;\n}\n#line 4 \"graph/maximum_matching_size.hpp\"\n\
    \ntemplate <typename GT>\nint maximum_matching_size(GT& G) {\n  using mint = modint61;\n\
    \  assert(!G.is_directed());\n  int N = G.N;\n  vv(mint, tutte, N, N);\n  for\
    \ (auto&& e: G.edges) {\n    mint x = RNG(mint::get_mod());\n    int i = e.frm,\
    \ j = e.to;\n    tutte[i][j] += x;\n    tutte[j][i] -= x;\n  }\n  return matrix_rank(N,\
    \ N, tutte) / 2;\n}\n"
  code: "#include \"random/base.hpp\"\n#include \"mod/modint61.hpp\"\n#include \"\
    linalg/matrix_rank.hpp\"\n\ntemplate <typename GT>\nint maximum_matching_size(GT&\
    \ G) {\n  using mint = modint61;\n  assert(!G.is_directed());\n  int N = G.N;\n\
    \  vv(mint, tutte, N, N);\n  for (auto&& e: G.edges) {\n    mint x = RNG(mint::get_mod());\n\
    \    int i = e.frm, j = e.to;\n    tutte[i][j] += x;\n    tutte[j][i] -= x;\n\
    \  }\n  return matrix_rank(N, N, tutte) / 2;\n}\n"
  dependsOn:
  - random/base.hpp
  - mod/modint61.hpp
  - linalg/matrix_rank.hpp
  isVerificationFile: false
  path: graph/maximum_matching_size.hpp
  requiredBy: []
  timestamp: '2023-09-03 05:59:57+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/graph/general_matching.test.cpp
  - test/mytest/matching.test.cpp
  - test/mytest/tutte.test.cpp
  - test/mytest/matching_line_graph.test.cpp
documentation_of: graph/maximum_matching_size.hpp
layout: document
redirect_from:
- /library/graph/maximum_matching_size.hpp
- /library/graph/maximum_matching_size.hpp.html
title: graph/maximum_matching_size.hpp
---
