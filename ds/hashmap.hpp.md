---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':x:'
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
    path: test/atcoder/abc270_g.test.cpp
    title: test/atcoder/abc270_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc273_e.test.cpp
    title: test/atcoder/abc273_e.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/associative_array_hashmap.test.cpp
    title: test/library_checker/datastructure/associative_array_hashmap.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/set_xor_min.test.cpp
    title: test/library_checker/datastructure/set_xor_min.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/discrete_logarithm_mod.test.cpp
    title: test/library_checker/math/discrete_logarithm_mod.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':x:'
    path: test/mytest/tdpc_grid_dp.test.cpp
    title: test/mytest/tdpc_grid_dp.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1339.test.cpp
    title: test/yukicoder/1339.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1383.test.cpp
    title: test/yukicoder/1383.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1397.test.cpp
    title: test/yukicoder/1397.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1634.test.cpp
    title: test/yukicoder/1634.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1726.test.cpp
    title: test/yukicoder/1726.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1769.test.cpp
    title: test/yukicoder/1769.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1881.test.cpp
    title: test/yukicoder/1881.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2102.test.cpp
    title: test/yukicoder/2102.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2167.test.cpp
    title: test/yukicoder/2167.test.cpp
  - icon: ':x:'
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
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"ds/hashmap.hpp\"\
    \n\r\n// long long -> Val\r\ntemplate <typename Val, int LOG = 20>\r\nstruct HashMap\
    \ {\r\n  int N;\r\n  ll* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1\
    \ << LOG> used;\r\n  const int shift;\r\n  const uint64_t r = 11995408973635179863ULL;\r\
    \n  HashMap()\r\n      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ ll& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] !=\
    \ key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const ll& key, Val default_value) {\r\n    int i = index(key);\r\n \
    \   if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  vc<pair<ll, Val>> items() {\r\
    \n    vc<pair<ll, Val>> res;\r\n    res.reserve(len(IDS));\r\n    for (auto&&\
    \ i: IDS) res.eb(keys[i], vals[i]);\r\n    return res;\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n#include \"random/base.hpp\"\r\n\r\n// long long -> Val\r\
    \ntemplate <typename Val, int LOG = 20>\r\nstruct HashMap {\r\n  int N;\r\n  ll*\
    \ keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1 << LOG> used;\r\n  const\
    \ int shift;\r\n  const uint64_t r = 11995408973635179863ULL;\r\n  HashMap()\r\
    \n      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64 - __lg(N))\
    \ {}\r\n  int hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\n     \
    \   = std::chrono::steady_clock::now().time_since_epoch().count();\r\n    return\
    \ (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const ll&\
    \ key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] != key;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const ll& key, Val default_value) {\r\n    int i = index(key);\r\n \
    \   if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  vc<pair<ll, Val>> items() {\r\
    \n    vc<pair<ll, Val>> res;\r\n    res.reserve(len(IDS));\r\n    for (auto&&\
    \ i: IDS) res.eb(keys[i], vals[i]);\r\n    return res;\r\n  }\r\n};\r\n"
  dependsOn:
  - random/base.hpp
  isVerificationFile: false
  path: ds/hashmap.hpp
  requiredBy:
  - other/connected_dp.hpp
  - mod/mod_log.hpp
  - mod/mod_kth_root.hpp
  - nt/discrete_log.hpp
  timestamp: '2022-12-23 11:10:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/math/discrete_logarithm_mod.test.cpp
  - test/library_checker/datastructure/associative_array_hashmap.test.cpp
  - test/library_checker/datastructure/set_xor_min.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/1769.test.cpp
  - test/yukicoder/1397.test.cpp
  - test/yukicoder/1383.test.cpp
  - test/yukicoder/1339.test.cpp
  - test/yukicoder/2167.test.cpp
  - test/yukicoder/263.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/1726.test.cpp
  - test/yukicoder/1634.test.cpp
  - test/yukicoder/2102.test.cpp
  - test/yukicoder/1881.test.cpp
  - test/yukicoder/578.test.cpp
  - test/mytest/tdpc_grid_dp.test.cpp
  - test/atcoder/abc270_g.test.cpp
  - test/atcoder/abc273_e.test.cpp
documentation_of: ds/hashmap.hpp
layout: document
redirect_from:
- /library/ds/hashmap.hpp
- /library/ds/hashmap.hpp.html
title: ds/hashmap.hpp
---
