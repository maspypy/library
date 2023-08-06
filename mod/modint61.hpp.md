---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/rollinghash.hpp
    title: alg/monoid/rollinghash.hpp
  - icon: ':warning:'
    path: ds/unionfind/parallel_unionfind.hpp
    title: ds/unionfind/parallel_unionfind.hpp
  - icon: ':x:'
    path: graph/max_matching_size.hpp
    title: graph/max_matching_size.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_dp/subtree_hash.hpp
    title: graph/tree_dp/subtree_hash.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  - icon: ':heavy_check_mark:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash_vector.hpp
    title: random/hash_vector.hpp
  - icon: ':question:'
    path: string/rollinghash.hpp
    title: string/rollinghash.hpp
  - icon: ':heavy_check_mark:'
    path: string/rollinghash_2d.hpp
    title: string/rollinghash_2d.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/classify_tree.test.cpp
    title: test/library_checker/graph/classify_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
    title: test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - icon: ':x:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':x:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1397.test.cpp
    title: test/yukicoder/1397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2102.test.cpp
    title: test/yukicoder/2102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2231.test.cpp
    title: test/yukicoder/2231.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/263.test.cpp
    title: test/yukicoder/263.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/4_1.test.cpp
    title: test/yukicoder/4_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\n\r\n// https : // yosupo.hatenablog.com/entry/2023/08/06/181942\r\
    \n// x \u306E\u4EE3\u308F\u308A\u306B 8x \u3092 [8, 8MOD] \u3067\u6301\u3064\r\
    \nstruct modint61 {\r\n  using u128 = unsigned __int128;\r\n  static constexpr\
    \ u64 MOD = (1ULL << 61) - 1;\r\n  static constexpr u64 MOD8 = MOD * 8;\r\n  u64\
    \ x8;\r\n  constexpr modint61() : x8(0ULL) {}\r\n  constexpr modint61(u32 x) :\
    \ x8((x + MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(u64 x) : x8((x +\
    \ MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(int x) : x8((x + MOD - 1)\
    \ % MOD * 8 + 8) {}\r\n  constexpr modint61(ll x)\r\n      : x8(8 * (((x %= ll(MOD))\
    \ <= 0) ? (x + ll(MOD)) : x)) {}\r\n\r\n  static constexpr u64 get_mod() { return\
    \ MOD; }\r\n  modint61 &operator+=(const modint61 &a) {\r\n    if (__builtin_uaddll_overflow(x8,\
    \ a.x8, &x8)) x8 -= MOD8;\r\n    return *this;\r\n  }\r\n  modint61 &operator-=(const\
    \ modint61 &a) {\r\n    if (__builtin_uaddll_overflow(x8, MOD8 - a.x8, &x8)) x8\
    \ -= MOD8;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &a) {\r\n    u128 c = u128(x8) * (a.x8);\r\n    u64 x = c >> 67 << 3, y = c\
    \ << 61 >> 64;\r\n    if (__builtin_uaddll_overflow(x, y, &x8)) x8 -= MOD8;\r\n\
    \    return *this;\r\n  }\r\n  modint61 &operator/=(const modint61 &a) { return\
    \ (*this *= a.inverse()); }\r\n  modint61 operator+(const modint61 &p) const {\
    \ return modint61(*this) += p; }\r\n  modint61 operator-(const modint61 &p) const\
    \ { return modint61(*this) -= p; }\r\n  modint61 operator*(const modint61 &p)\
    \ const { return modint61(*this) *= p; }\r\n  modint61 operator/(const modint61\
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
    \ (x + ll(MOD)) : x);\r\n  }\r\n#endif\r\n};\n"
  code: "#pragma once\r\n\r\n// https : // yosupo.hatenablog.com/entry/2023/08/06/181942\r\
    \n// x \u306E\u4EE3\u308F\u308A\u306B 8x \u3092 [8, 8MOD] \u3067\u6301\u3064\r\
    \nstruct modint61 {\r\n  using u128 = unsigned __int128;\r\n  static constexpr\
    \ u64 MOD = (1ULL << 61) - 1;\r\n  static constexpr u64 MOD8 = MOD * 8;\r\n  u64\
    \ x8;\r\n  constexpr modint61() : x8(0ULL) {}\r\n  constexpr modint61(u32 x) :\
    \ x8((x + MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(u64 x) : x8((x +\
    \ MOD - 1) % MOD * 8 + 8) {}\r\n  constexpr modint61(int x) : x8((x + MOD - 1)\
    \ % MOD * 8 + 8) {}\r\n  constexpr modint61(ll x)\r\n      : x8(8 * (((x %= ll(MOD))\
    \ <= 0) ? (x + ll(MOD)) : x)) {}\r\n\r\n  static constexpr u64 get_mod() { return\
    \ MOD; }\r\n  modint61 &operator+=(const modint61 &a) {\r\n    if (__builtin_uaddll_overflow(x8,\
    \ a.x8, &x8)) x8 -= MOD8;\r\n    return *this;\r\n  }\r\n  modint61 &operator-=(const\
    \ modint61 &a) {\r\n    if (__builtin_uaddll_overflow(x8, MOD8 - a.x8, &x8)) x8\
    \ -= MOD8;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &a) {\r\n    u128 c = u128(x8) * (a.x8);\r\n    u64 x = c >> 67 << 3, y = c\
    \ << 61 >> 64;\r\n    if (__builtin_uaddll_overflow(x, y, &x8)) x8 -= MOD8;\r\n\
    \    return *this;\r\n  }\r\n  modint61 &operator/=(const modint61 &a) { return\
    \ (*this *= a.inverse()); }\r\n  modint61 operator+(const modint61 &p) const {\
    \ return modint61(*this) += p; }\r\n  modint61 operator-(const modint61 &p) const\
    \ { return modint61(*this) -= p; }\r\n  modint61 operator*(const modint61 &p)\
    \ const { return modint61(*this) *= p; }\r\n  modint61 operator/(const modint61\
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
    \ (x + ll(MOD)) : x);\r\n  }\r\n#endif\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint61.hpp
  requiredBy:
  - ds/unionfind/parallel_unionfind.hpp
  - mod/modular_subset_sum.hpp
  - string/rollinghash.hpp
  - string/rollinghash_2d.hpp
  - random/hash_vector.hpp
  - alg/monoid/rollinghash.hpp
  - other/connected_dp.hpp
  - graph/tree_dp/subtree_hash.hpp
  - graph/max_matching_size.hpp
  timestamp: '2023-08-06 21:51:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/matching_line_graph.test.cpp
  - test/mytest/tutte.test.cpp
  - test/mytest/tdpc_grid_dp.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/1397.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/2231.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/263.test.cpp
  - test/yukicoder/2102.test.cpp
  - test/yukicoder/4_1.test.cpp
  - test/yukicoder/578.test.cpp
  - test/aoj/ALDS1_14_C.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - test/library_checker/graph/classify_tree.test.cpp
documentation_of: mod/modint61.hpp
layout: document
redirect_from:
- /library/mod/modint61.hpp
- /library/mod/modint61.hpp.html
title: mod/modint61.hpp
---
