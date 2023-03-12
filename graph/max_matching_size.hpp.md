---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
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
    \nstruct modint61 {\r\n  static constexpr bool is_modint = true;\r\n  static constexpr\
    \ ll mod = (1LL << 61) - 1;\r\n  ll val;\r\n  constexpr modint61(const ll x =\
    \ 0) : val(x) {\r\n    while (val < 0) val += mod;\r\n    while (val >= mod) val\
    \ -= mod;\r\n  }\r\n  bool operator<(const modint61 &other) const {\r\n    return\
    \ val < other.val;\r\n  } // To use std::map\r\n  bool operator==(const modint61\
    \ &p) const { return val == p.val; }\r\n  bool operator!=(const modint61 &p) const\
    \ { return val != p.val; }\r\n  modint61 &operator+=(const modint61 &p) {\r\n\
    \    if ((val += p.val) >= mod) val -= mod;\r\n    return *this;\r\n  }\r\n  modint61\
    \ &operator-=(const modint61 &p) {\r\n    if ((val += mod - p.val) >= mod) val\
    \ -= mod;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &p) {\r\n    ll a = val, b = p.val;\r\n    const ll MASK30 = (1LL << 30) - 1;\r\
    \n    const ll MASK31 = (1LL << 31) - 1;\r\n    const ll MASK61 = (1LL << 61)\
    \ - 1;\r\n    ll au = a >> 31, ad = a & MASK31;\r\n    ll bu = b >> 31, bd = b\
    \ & MASK31;\r\n    ll x = ad * bu + au * bd;\r\n    ll xu = x >> 30, xd = x &\
    \ MASK30;\r\n    x = au * bu * 2 + xu + (xd << 31) + ad * bd;\r\n    xu = x >>\
    \ 61, xd = x & MASK61;\r\n    x = xu + xd;\r\n    if (x >= MASK61) x -= MASK61;\r\
    \n    val = x;\r\n    return *this;\r\n  }\r\n  modint61 operator-() const { return\
    \ modint61(get_mod() - val); }\r\n  modint61 &operator/=(const modint61 &p) {\r\
    \n    *this *= p.inverse();\r\n    return *this;\r\n  }\r\n  modint61 operator+(const\
    \ modint61 &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const\
    \ modint61 &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const\
    \ modint61 &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const\
    \ modint61 &p) const { return modint61(*this) /= p; }\r\n\r\n  modint61 inverse()\
    \ const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\
    \n      t = a / b;\r\n      swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\
    \n    return modint61(u);\r\n  }\r\n  modint61 pow(int64_t n) const {\r\n    modint61\
    \ ret(1), mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret = ret * mul;\r\
    \n      mul = mul * mul;\r\n      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\
    \n  static constexpr ll get_mod() { return mod; }\r\n  void write() { fastio::printer.write(val);\
    \ }\r\n  void read() { fastio::scanner.read(val); }\r\n};\r\n#line 1 \"linalg/matrix_rank.hpp\"\
    \ntemplate <typename T>\nint matrix_rank(const int n, const int m, vc<vc<T>> a)\
    \ {\n  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    if (a[rk][j] ==\
    \ 0) {\n      FOR3(i, rk + 1, n) if (a[i][j] != 0) {\n        swap(a[rk], a[i]);\n\
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
  timestamp: '2023-02-28 19:14:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/tutte.test.cpp
  - test/mytest/matching_line_graph.test.cpp
documentation_of: graph/max_matching_size.hpp
layout: document
redirect_from:
- /library/graph/max_matching_size.hpp
- /library/graph/max_matching_size.hpp.html
title: graph/max_matching_size.hpp
---
