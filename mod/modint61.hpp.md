---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/rollinghash.hpp
    title: alg/monoid/rollinghash.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/rolling_hash_on_tree.hpp
    title: graph/ds/rolling_hash_on_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum_matching_size.hpp
    title: graph/maximum_matching_size.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_dp/subtree_hash.hpp
    title: graph/tree_dp/subtree_hash.hpp
  - icon: ':x:'
    path: mod/modular_subset_sum.hpp
    title: mod/modular_subset_sum.hpp
  - icon: ':question:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  - icon: ':question:'
    path: random/hash_vector.hpp
    title: random/hash_vector.hpp
  - icon: ':warning:'
    path: string/basic_substring_structure.hpp
    title: string/basic_substring_structure.hpp
  - icon: ':warning:'
    path: string/deque_rolling_hash.hpp
    title: string/deque_rolling_hash.hpp
  - icon: ':question:'
    path: string/rollinghash.hpp
    title: string/rollinghash.hpp
  - icon: ':x:'
    path: string/rollinghash_2d.hpp
    title: string/rollinghash_2d.hpp
  - icon: ':warning:'
    path: string/substring_count_in_substring.hpp
    title: string/substring_count_in_substring.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/enumerate_unlabeled_tree.test.cpp
    title: test/1_mytest/enumerate_unlabeled_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching.test.cpp
    title: test/1_mytest/matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching_line_graph.test.cpp
    title: test/1_mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/rolling_hash_on_tree.test.cpp
    title: test/1_mytest/rolling_hash_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tdpc_grid_dp.test.cpp
    title: test/1_mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tutte.test.cpp
    title: test/1_mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/classify_tree.test.cpp
    title: test/2_library_checker/graph/classify_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/general_matching.test.cpp
    title: test/2_library_checker/graph/general_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/zalgorithm_by_rollinghash.test.cpp
    title: test/2_library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
    title: test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1397.test.cpp
    title: test/3_yukicoder/1397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1561.test.cpp
    title: test/3_yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2102.test.cpp
    title: test/3_yukicoder/2102.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2231.test.cpp
    title: test/3_yukicoder/2231.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2626.test.cpp
    title: test/3_yukicoder/2626.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/263.test.cpp
    title: test/3_yukicoder/263.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/4_1.test.cpp
    title: test/3_yukicoder/4_1.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/541.test.cpp
    title: test/3_yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/578.test.cpp
    title: test/3_yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/579.test.cpp
    title: test/3_yukicoder/579.test.cpp
  - icon: ':x:'
    path: test/4_aoj/ALDS1_14_C.test.cpp
    title: test/4_aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\n  static constexpr\
    \ u64 mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr modint61() : val(0ULL)\
    \ {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr modint61(u64 x)\
    \ : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\r\n  constexpr modint61(ll x) : val(((x %= static_cast<ll>(mod)) < 0)\
    \ ? (x + static_cast<ll>(mod)) : x) {}\r\n  static constexpr u64 get_mod() { return\
    \ mod; }\r\n\r\n  modint61 &operator+=(const modint61 &a) {\r\n    val = ((val\
    \ += a.val) >= mod) ? (val - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61\
    \ &operator-=(const modint61 &a) {\r\n    val = ((val -= a.val) >= mod) ? (val\
    \ + mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &a) {\r\n    const unsigned __int128 y = static_cast<unsigned __int128>(val)\
    \ * a.val;\r\n    val = (y >> 61) + (y & mod);\r\n    val = (val >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 operator-() const {\
    \ return modint61(val ? mod - val : u64(0)); }\r\n  modint61 &operator/=(const\
    \ modint61 &a) { return (*this *= a.inverse()); }\r\n  modint61 operator+(const\
    \ modint61 &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const\
    \ modint61 &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const\
    \ modint61 &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const\
    \ modint61 &p) const { return modint61(*this) /= p; }\r\n  bool operator<(const\
    \ modint61 &other) const { return val < other.val; }\r\n  bool operator==(const\
    \ modint61 &p) const { return val == p.val; }\r\n  bool operator!=(const modint61\
    \ &p) const { return val != p.val; }\r\n  modint61 inverse() const {\r\n    ll\
    \ a = val, b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\
    \n      swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\
    \n  }\r\n  modint61 pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1),\
    \ mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul\
    \ *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n};\r\n\r\n#ifdef FASTIO\r\
    \nvoid rd(modint61 &x) {\r\n  fastio::rd(x.val);\r\n  assert(0 <= x.val && x.val\
    \ < modint61::mod);\r\n}\r\n\r\nvoid wt(modint61 x) { fastio::wt(x.val); }\r\n\
    #endif\n"
  code: "#pragma once\r\n\r\nstruct modint61 {\r\n  static constexpr u64 mod = (1ULL\
    \ << 61) - 1;\r\n  u64 val;\r\n  constexpr modint61() : val(0ULL) {}\r\n  constexpr\
    \ modint61(u32 x) : val(x) {}\r\n  constexpr modint61(u64 x) : val(x % mod) {}\r\
    \n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod)) : x)\
    \ {}\r\n  constexpr modint61(ll x) : val(((x %= static_cast<ll>(mod)) < 0) ? (x\
    \ + static_cast<ll>(mod)) : x) {}\r\n  static constexpr u64 get_mod() { return\
    \ mod; }\r\n\r\n  modint61 &operator+=(const modint61 &a) {\r\n    val = ((val\
    \ += a.val) >= mod) ? (val - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61\
    \ &operator-=(const modint61 &a) {\r\n    val = ((val -= a.val) >= mod) ? (val\
    \ + mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &a) {\r\n    const unsigned __int128 y = static_cast<unsigned __int128>(val)\
    \ * a.val;\r\n    val = (y >> 61) + (y & mod);\r\n    val = (val >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 operator-() const {\
    \ return modint61(val ? mod - val : u64(0)); }\r\n  modint61 &operator/=(const\
    \ modint61 &a) { return (*this *= a.inverse()); }\r\n  modint61 operator+(const\
    \ modint61 &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const\
    \ modint61 &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const\
    \ modint61 &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const\
    \ modint61 &p) const { return modint61(*this) /= p; }\r\n  bool operator<(const\
    \ modint61 &other) const { return val < other.val; }\r\n  bool operator==(const\
    \ modint61 &p) const { return val == p.val; }\r\n  bool operator!=(const modint61\
    \ &p) const { return val != p.val; }\r\n  modint61 inverse() const {\r\n    ll\
    \ a = val, b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\
    \n      swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\
    \n  }\r\n  modint61 pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1),\
    \ mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul\
    \ *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n};\r\n\r\n#ifdef FASTIO\r\
    \nvoid rd(modint61 &x) {\r\n  fastio::rd(x.val);\r\n  assert(0 <= x.val && x.val\
    \ < modint61::mod);\r\n}\r\n\r\nvoid wt(modint61 x) { fastio::wt(x.val); }\r\n\
    #endif"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint61.hpp
  requiredBy:
  - random/hash_vector.hpp
  - mod/modular_subset_sum.hpp
  - string/substring_count_in_substring.hpp
  - string/rollinghash_2d.hpp
  - string/rollinghash.hpp
  - string/basic_substring_structure.hpp
  - string/deque_rolling_hash.hpp
  - graph/tree_dp/subtree_hash.hpp
  - graph/ds/rolling_hash_on_tree.hpp
  - graph/maximum_matching_size.hpp
  - alg/monoid/rollinghash.hpp
  - other/connected_dp.hpp
  timestamp: '2024-08-27 05:16:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/rolling_hash_on_tree.test.cpp
  - test/1_mytest/tutte.test.cpp
  - test/1_mytest/enumerate_unlabeled_tree.test.cpp
  - test/1_mytest/tdpc_grid_dp.test.cpp
  - test/1_mytest/matching_line_graph.test.cpp
  - test/1_mytest/matching.test.cpp
  - test/4_aoj/ALDS1_14_C.test.cpp
  - test/2_library_checker/string/zalgorithm_by_rollinghash2.test.cpp
  - test/2_library_checker/string/zalgorithm_by_rollinghash.test.cpp
  - test/2_library_checker/graph/general_matching.test.cpp
  - test/2_library_checker/graph/classify_tree.test.cpp
  - test/3_yukicoder/2231.test.cpp
  - test/3_yukicoder/579.test.cpp
  - test/3_yukicoder/1397.test.cpp
  - test/3_yukicoder/1561.test.cpp
  - test/3_yukicoder/263.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/3_yukicoder/2102.test.cpp
  - test/3_yukicoder/578.test.cpp
  - test/3_yukicoder/2626.test.cpp
  - test/3_yukicoder/4_1.test.cpp
  - test/3_yukicoder/541.test.cpp
documentation_of: mod/modint61.hpp
layout: document
redirect_from:
- /library/mod/modint61.hpp
- /library/mod/modint61.hpp.html
title: mod/modint61.hpp
---
