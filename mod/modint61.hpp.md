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
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
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
  - icon: ':heavy_check_mark:'
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
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\n  static constexpr\
    \ u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr modint61() : val(0ULL)\
    \ {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr modint61(u64 x)\
    \ : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\r\n  constexpr modint61(ll x)\r\n      : val(((x %= static_cast<ll>(mod))\
    \ < 0) ? (x + static_cast<ll>(mod))\r\n                                      \
    \        : x) {}\r\n  static constexpr u64 get_mod() { return mod; }\r\n  modint61\
    \ &operator+=(const modint61 &a) {\r\n    val = ((val += a.val) >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator-=(const modint61\
    \ &a) {\r\n    val = ((val -= a.val) >= mod) ? (val + mod) : val;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator*=(const modint61 &a) {\r\n    const unsigned\
    \ __int128 y = static_cast<unsigned __int128>(val) * a.val;\r\n    val = (y >>\
    \ 61) + (y & mod);\r\n    val = (val >= mod) ? (val - mod) : val;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator/=(const modint61 &a) { return (*this *=\
    \ a.inverse()); }\r\n  modint61 operator+(const modint61 &p) const { return modint61(*this)\
    \ += p; }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n  bool operator==(const modint61 &p) const { return val == p.val;\
    \ }\r\n  bool operator!=(const modint61 &p) const { return val != p.val; }\r\n\
    \  modint61 inverse() const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n\
    \    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61 pow(ll\
    \ n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1), mul(val);\r\n    while\
    \ (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul *= mul, n >>= 1;\r\n\
    \    }\r\n    return ret;\r\n  }\r\n#ifdef FASTIO\r\n  void write() { fastio::printer.write(val);\
    \ }\r\n  void read() {\r\n    ll x;\r\n    fastio::scanner.read(x);\r\n    val\
    \ = (val >= 0 ? val % mod : (mod - (-val) % mod) % mod);\r\n  }\r\n#endif\r\n\
    };\n"
  code: "#pragma once\r\n\r\nstruct modint61 {\r\n  static constexpr u64 mod = (1ULL\
    \ << 61) - 1;\r\n  u64 val;\r\n  constexpr modint61() : val(0ULL) {}\r\n  constexpr\
    \ modint61(u32 x) : val(x) {}\r\n  constexpr modint61(u64 x) : val(x % mod) {}\r\
    \n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod)) : x)\
    \ {}\r\n  constexpr modint61(ll x)\r\n      : val(((x %= static_cast<ll>(mod))\
    \ < 0) ? (x + static_cast<ll>(mod))\r\n                                      \
    \        : x) {}\r\n  static constexpr u64 get_mod() { return mod; }\r\n  modint61\
    \ &operator+=(const modint61 &a) {\r\n    val = ((val += a.val) >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator-=(const modint61\
    \ &a) {\r\n    val = ((val -= a.val) >= mod) ? (val + mod) : val;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator*=(const modint61 &a) {\r\n    const unsigned\
    \ __int128 y = static_cast<unsigned __int128>(val) * a.val;\r\n    val = (y >>\
    \ 61) + (y & mod);\r\n    val = (val >= mod) ? (val - mod) : val;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator/=(const modint61 &a) { return (*this *=\
    \ a.inverse()); }\r\n  modint61 operator+(const modint61 &p) const { return modint61(*this)\
    \ += p; }\r\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\r\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\r\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\r\n  bool operator==(const modint61 &p) const { return val == p.val;\
    \ }\r\n  bool operator!=(const modint61 &p) const { return val != p.val; }\r\n\
    \  modint61 inverse() const {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n\
    \    while (b > 0) {\r\n      t = a / b;\r\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\r\n    }\r\n    return modint61(u);\r\n  }\r\n  modint61 pow(ll\
    \ n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1), mul(val);\r\n    while\
    \ (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul *= mul, n >>= 1;\r\n\
    \    }\r\n    return ret;\r\n  }\r\n#ifdef FASTIO\r\n  void write() { fastio::printer.write(val);\
    \ }\r\n  void read() {\r\n    ll x;\r\n    fastio::scanner.read(x);\r\n    val\
    \ = (val >= 0 ? val % mod : (mod - (-val) % mod) % mod);\r\n  }\r\n#endif\r\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint61.hpp
  requiredBy:
  - string/rollinghash_2d.hpp
  - string/rollinghash.hpp
  - random/hash_vector.hpp
  - graph/tree_dp/subtree_hash.hpp
  - graph/max_matching_size.hpp
  - mod/modular_subset_sum.hpp
  - alg/monoid/rollinghash.hpp
  - other/connected_dp.hpp
  - ds/unionfind/parallel_unionfind.hpp
  timestamp: '2023-08-13 16:19:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_C.test.cpp
  - test/mytest/matching_line_graph.test.cpp
  - test/mytest/tutte.test.cpp
  - test/mytest/tdpc_grid_dp.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - test/library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - test/library_checker/graph/classify_tree.test.cpp
  - test/yukicoder/1397.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/2102.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/578.test.cpp
  - test/yukicoder/263.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/2231.test.cpp
  - test/yukicoder/4_1.test.cpp
documentation_of: mod/modint61.hpp
layout: document
redirect_from:
- /library/mod/modint61.hpp
- /library/mod/modint61.hpp.html
title: mod/modint61.hpp
---
