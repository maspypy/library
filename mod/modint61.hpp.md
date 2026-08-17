---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: alg/monoid/roling_hash.hpp
    title: alg/monoid/roling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/rolling_hash_on_tree.hpp
    title: graph/ds/rolling_hash_on_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/maximum_matching_size.hpp
    title: graph/maximum_matching_size.hpp
  - icon: ':x:'
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
  - icon: ':warning:'
    path: string/deque_rolling_hash.hpp
    title: string/deque_rolling_hash.hpp
  - icon: ':warning:'
    path: string/rolling_hash.hpp
    title: string/rolling_hash.hpp
  - icon: ':heavy_check_mark:'
    path: string/rollinghash_2d.hpp
    title: string/rollinghash_2d.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/2_library_checker/graph/classify_tree.test.cpp
    title: test/2_library_checker/graph/classify_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/general_matching.test.cpp
    title: test/2_library_checker/graph/general_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1397.test.cpp
    title: test/3_yukicoder/1397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1561.test.cpp
    title: test/3_yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1881.test.cpp
    title: test/3_yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/4_1.test.cpp
    title: test/3_yukicoder/4_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/541.test.cpp
    title: test/3_yukicoder/541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/578.test.cpp
    title: test/3_yukicoder/578.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/579.test.cpp
    title: test/3_yukicoder/579.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/ALDS1_14_C.test.cpp
    title: test/4_aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
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
    }\n\nvoid wt(modint61 x) { fastio::wt(x.val); }\n#endif\n"
  code: "\nstruct modint61 {\n  static constexpr u64 mod = (1ULL << 61) - 1;\n  u64\
    \ val;\n  constexpr modint61() : val(0ULL) {}\n  constexpr modint61(u32 x) : val(x)\
    \ {}\n  constexpr modint61(u64 x) : val(x % mod) {}\n  constexpr modint61(int\
    \ x) : val((x < 0) ? (x + static_cast<ll>(mod)) : x) {}\n  constexpr modint61(ll\
    \ x) : val(((x %= static_cast<ll>(mod)) < 0) ? (x + static_cast<ll>(mod)) : x)\
    \ {}\n  static constexpr u64 get_mod() { return mod; }\n\n  modint61 &operator+=(const\
    \ modint61 &a) {\n    val = ((val += a.val) >= mod) ? (val - mod) : val;\n   \
    \ return *this;\n  }\n  modint61 &operator-=(const modint61 &a) {\n    val = ((val\
    \ -= a.val) >= mod) ? (val + mod) : val;\n    return *this;\n  }\n  modint61 &operator*=(const\
    \ modint61 &a) {\n    const unsigned __int128 y = static_cast<unsigned __int128>(val)\
    \ * a.val;\n    val = (y >> 61) + (y & mod);\n    val = (val >= mod) ? (val -\
    \ mod) : val;\n    return *this;\n  }\n  modint61 operator-() const { return modint61(val\
    \ ? mod - val : u64(0)); }\n  modint61 &operator/=(const modint61 &a) { return\
    \ (*this *= a.inverse()); }\n  modint61 operator+(const modint61 &p) const { return\
    \ modint61(*this) += p; }\n  modint61 operator-(const modint61 &p) const { return\
    \ modint61(*this) -= p; }\n  modint61 operator*(const modint61 &p) const { return\
    \ modint61(*this) *= p; }\n  modint61 operator/(const modint61 &p) const { return\
    \ modint61(*this) /= p; }\n  bool operator<(const modint61 &other) const { return\
    \ val < other.val; }\n  bool operator==(const modint61 &p) const { return val\
    \ == p.val; }\n  bool operator!=(const modint61 &p) const { return val != p.val;\
    \ }\n  modint61 inverse() const {\n    ll a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint61(u);\n  }\n  modint61 pow(ll n) const {\n\
    \    assert(n >= 0);\n    modint61 ret(1), mul(val);\n    while (n > 0) {\n  \
    \    if (n & 1) ret *= mul;\n      mul *= mul, n >>= 1;\n    }\n    return ret;\n\
    \  }\n};\n\n#ifdef FASTIO\nvoid rd(modint61 &x) {\n  fastio::rd(x.val);\n  assert(0\
    \ <= x.val && x.val < modint61::mod);\n}\n\nvoid wt(modint61 x) { fastio::wt(x.val);\
    \ }\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: mod/modint61.hpp
  requiredBy:
  - graph/maximum_matching_size.hpp
  - graph/tree_dp/subtree_hash.hpp
  - graph/ds/rolling_hash_on_tree.hpp
  - random/hash_vector.hpp
  - other/connected_dp.hpp
  - string/rollinghash_2d.hpp
  - string/deque_rolling_hash.hpp
  - string/rolling_hash.hpp
  - alg/monoid/roling_hash.hpp
  - mod/modular_subset_sum.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/rolling_hash_on_tree.test.cpp
  - test/1_mytest/tdpc_grid_dp.test.cpp
  - test/1_mytest/matching.test.cpp
  - test/1_mytest/tutte.test.cpp
  - test/1_mytest/enumerate_unlabeled_tree.test.cpp
  - test/1_mytest/matching_line_graph.test.cpp
  - test/2_library_checker/graph/general_matching.test.cpp
  - test/2_library_checker/graph/classify_tree.test.cpp
  - test/4_aoj/ALDS1_14_C.test.cpp
  - test/3_yukicoder/578.test.cpp
  - test/3_yukicoder/1397.test.cpp
  - test/3_yukicoder/1881.test.cpp
  - test/3_yukicoder/1561.test.cpp
  - test/3_yukicoder/579.test.cpp
  - test/3_yukicoder/4_1.test.cpp
  - test/3_yukicoder/541.test.cpp
documentation_of: mod/modint61.hpp
layout: document
redirect_from:
- /library/mod/modint61.hpp
- /library/mod/modint61.hpp.html
title: mod/modint61.hpp
---
