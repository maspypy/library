---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: ds/static_range_frequency.hpp
    title: ds/static_range_frequency.hpp
  - icon: ':heavy_check_mark:'
    path: ds/to_small_key.hpp
    title: ds/to_small_key.hpp
  - icon: ':heavy_check_mark:'
    path: geo/closest_pair.hpp
    title: geo/closest_pair.hpp
  - icon: ':x:'
    path: geo/range_closest_pair_query.hpp
    title: geo/range_closest_pair_query.hpp
  - icon: ':x:'
    path: graph/eulerwalk.hpp
    title: graph/eulerwalk.hpp
  - icon: ':x:'
    path: graph/vs_to_es.hpp
    title: graph/vs_to_es.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':heavy_check_mark:'
    path: mod/mod_log.hpp
    title: mod/mod_log.hpp
  - icon: ':question:'
    path: nt/discrete_log.hpp
    title: nt/discrete_log.hpp
  - icon: ':x:'
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
    path: test/library_checker/datastructure/static_range_freq.test.cpp
    title: test/library_checker/datastructure/static_range_freq.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':x:'
    path: test/mytest/range_closest_pair.test.cpp
    title: test/mytest/range_closest_pair.test.cpp
  - icon: ':x:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1383.test.cpp
    title: test/yukicoder/1383.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1397.test.cpp
    title: test/yukicoder/1397.test.cpp
  - icon: ':x:'
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
  - icon: ':x:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc220g.test.cpp
    title: test_atcoder/abc220g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222g.test.cpp
    title: test_atcoder/abc222g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc227g.test.cpp
    title: test_atcoder/abc227g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc270_g.test.cpp
    title: test_atcoder/abc270_g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc273_e.test.cpp
    title: test_atcoder/abc273_e.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc157a.test.cpp
    title: test_atcoder/arc157a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val, int LOG = 20, bool KEEP_IDS = false>\r\nstruct HashMap {\r\n  static constexpr\
    \ int N = (1 << LOG);\r\n  u64* key;\r\n  Val* val;\r\n  vc<int> IDS;\r\n  bitset<N>\
    \ used;\r\n  const int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\n\
    \  HashMap() : key(new u64[N]), val(new Val[N]), shift(64 - LOG) {}\r\n  u32 hash(u64\
    \ x) {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    int i = index(k);\r\n    if (!used[i]) {\r\n      used[i] =\
    \ 1, key[i] = k, val[i] = Val{};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\
    \n    }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value)\
    \ {\r\n    int i = index(k);\r\n    if (!used[i]) return default_value;\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\
    \n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  void reset() {\r\n    static_assert(KEEP_IDS);\r\
    \n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  //\
    \ f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\n  \
    \  static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) f(key[i], val[i]);\r\n\
    \  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n// u64 -> Val\r\ntemplate <typename Val, int LOG = 20,\
    \ bool KEEP_IDS = false>\r\nstruct HashMap {\r\n  static constexpr int N = (1\
    \ << LOG);\r\n  u64* key;\r\n  Val* val;\r\n  vc<int> IDS;\r\n  bitset<N> used;\r\
    \n  const int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\n  HashMap()\
    \ : key(new u64[N]), val(new Val[N]), shift(64 - LOG) {}\r\n  u32 hash(u64 x)\
    \ {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    int i = index(k);\r\n    if (!used[i]) {\r\n      used[i] =\
    \ 1, key[i] = k, val[i] = Val{};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\
    \n    }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value)\
    \ {\r\n    int i = index(k);\r\n    if (!used[i]) return default_value;\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\
    \n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  void reset() {\r\n    static_assert(KEEP_IDS);\r\
    \n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  //\
    \ f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\n  \
    \  static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) f(key[i], val[i]);\r\n\
    \  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/hashmap.hpp
  requiredBy:
  - ds/static_range_frequency.hpp
  - ds/to_small_key.hpp
  - geo/range_closest_pair_query.hpp
  - geo/closest_pair.hpp
  - mod/mod_kth_root.hpp
  - mod/mod_log.hpp
  - nt/discrete_log.hpp
  - graph/vs_to_es.hpp
  - graph/eulerwalk.hpp
  - other/connected_dp.hpp
  timestamp: '2023-11-21 19:08:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc270_g.test.cpp
  - test_atcoder/abc220g.test.cpp
  - test_atcoder/abc222g.test.cpp
  - test_atcoder/arc157a.test.cpp
  - test_atcoder/abc273_e.test.cpp
  - test_atcoder/abc227g.test.cpp
  - test/library_checker/datastructure/associative_array_hashmap.test.cpp
  - test/library_checker/datastructure/set_xor_min.test.cpp
  - test/library_checker/datastructure/static_range_freq.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/mytest/tdpc_grid_dp.test.cpp
  - test/mytest/range_closest_pair.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/2102.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/1726.test.cpp
  - test/yukicoder/1769.test.cpp
  - test/yukicoder/1383.test.cpp
  - test/yukicoder/1634.test.cpp
  - test/yukicoder/263.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/2167.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/578.test.cpp
  - test/yukicoder/1397.test.cpp
  - test/aoj/CGL_5_A.test.cpp
documentation_of: ds/hashmap.hpp
layout: document
redirect_from:
- /library/ds/hashmap.hpp
- /library/ds/hashmap.hpp.html
title: ds/hashmap.hpp
---
