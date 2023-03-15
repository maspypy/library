---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/closest_pair.hpp
    title: geo/closest_pair.hpp
  - icon: ':heavy_check_mark:'
    path: geo/range_closest_pair_query.hpp
    title: geo/range_closest_pair_query.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':heavy_check_mark:'
    path: nt/discrete_log.hpp
    title: nt/discrete_log.hpp
  - icon: ':heavy_check_mark:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/associative_array_hashmap.test.cpp
    title: test/library_checker/datastructure/associative_array_hashmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/set_xor_min.test.cpp
    title: test/library_checker/datastructure/set_xor_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/range_closest_pair.test.cpp
    title: test/mytest/range_closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1383.test.cpp
    title: test/yukicoder/1383.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1397.test.cpp
    title: test/yukicoder/1397.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1634.test.cpp
    title: test/yukicoder/1634.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1726.test.cpp
    title: test/yukicoder/1726.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1769.test.cpp
    title: test/yukicoder/1769.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2102.test.cpp
    title: test/yukicoder/2102.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2167.test.cpp
    title: test/yukicoder/2167.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/263.test.cpp
    title: test/yukicoder/263.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc222g.test.cpp
    title: test_atcoder/abc222g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc270_g.test.cpp
    title: test_atcoder/abc270_g.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc273_e.test.cpp
    title: test_atcoder/abc273_e.test.cpp
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
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val, int LOG = 20>\r\nstruct HashMap\
    \ {\r\n  int N;\r\n  u64* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1\
    \ << LOG> used;\r\n  const int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\
    \n  HashMap()\r\n      : N(1 << LOG), keys(new u64[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const u64 FIXED_RANDOM\r\n\
    \        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n  \
    \  return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i]\
    \ != key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  // [] \u3057\
    \u305F\u6642\u70B9\u3067\u8981\u7D20\u306F\u4F5C\u3089\u308C\u308B\r\n  Val& operator[](const\
    \ u64& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const u64& key, Val default_value) {\r\n    int i = index(key);\r\n\
    \    if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const u64& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key, val)\r\n  template\
    \ <typename F>\r\n  void enumerate_all(F f) {\r\n    for (auto&& i: IDS) f(keys[i],\
    \ vals[i]);\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include \"random/base.hpp\"\r\n\r\n// u64 -> Val\r\ntemplate\
    \ <typename Val, int LOG = 20>\r\nstruct HashMap {\r\n  int N;\r\n  u64* keys;\r\
    \n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1 << LOG> used;\r\n  const int shift;\r\
    \n  const u64 r = 11995408973635179863ULL;\r\n  HashMap()\r\n      : N(1 << LOG),\
    \ keys(new u64[N]), vals(new Val[N]), shift(64 - __lg(N)) {}\r\n  int hash(ll\
    \ x) {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i]\
    \ != key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  // [] \u3057\
    \u305F\u6642\u70B9\u3067\u8981\u7D20\u306F\u4F5C\u3089\u308C\u308B\r\n  Val& operator[](const\
    \ u64& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const u64& key, Val default_value) {\r\n    int i = index(key);\r\n\
    \    if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const u64& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key, val)\r\n  template\
    \ <typename F>\r\n  void enumerate_all(F f) {\r\n    for (auto&& i: IDS) f(keys[i],\
    \ vals[i]);\r\n  }\r\n};\r\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: ds/hashmap.hpp
  requiredBy:
  - geo/closest_pair.hpp
  - geo/range_closest_pair_query.hpp
  - nt/discrete_log.hpp
  - other/connected_dp.hpp
  - mod/mod_kth_root.hpp
  - mod/mod_log.hpp
  timestamp: '2023-01-31 21:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc273_e.test.cpp
  - test_atcoder/abc270_g.test.cpp
  - test_atcoder/abc222g.test.cpp
  - test/mytest/tdpc_grid_dp.test.cpp
  - test/mytest/range_closest_pair.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/yukicoder/1634.test.cpp
  - test/yukicoder/1726.test.cpp
  - test/yukicoder/1769.test.cpp
  - test/yukicoder/578.test.cpp
  - test/yukicoder/1397.test.cpp
  - test/yukicoder/1383.test.cpp
  - test/yukicoder/263.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/2167.test.cpp
  - test/yukicoder/2102.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/579.test.cpp
  - test/library_checker/datastructure/set_xor_min.test.cpp
  - test/library_checker/datastructure/associative_array_hashmap.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
documentation_of: ds/hashmap.hpp
layout: document
redirect_from:
- /library/ds/hashmap.hpp
- /library/ds/hashmap.hpp.html
title: ds/hashmap.hpp
---
