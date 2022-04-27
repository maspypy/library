---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/associative_array_hashmap.test.cpp
    title: test/library_checker/datastructure/associative_array_hashmap.test.cpp
  - icon: ':x:'
    path: test/library_checker/math/kth_root_mod.test.cpp
    title: test/library_checker/math/kth_root_mod.test.cpp
  - icon: ':x:'
    path: test/yukicoder/981_mod_kth_root.test.cpp
    title: test/yukicoder/981_mod_kth_root.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/hashmap.hpp\"\ntemplate <typename Val, int LOG = 20>\r\
    \nstruct HashMapLL {\r\n  int N;\r\n  ll* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\
    \n  bitset<1 << LOG> used;\r\n  const int shift;\r\n  const uint64_t r = 11995408973635179863ULL;\r\
    \n  HashMapLL()\r\n      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ ll& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] !=\
    \ key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ bool contain(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  bool count(const ll& key) {\r\n    int i\
    \ = index(key);\r\n    return used[i] && keys[i] == key;\r\n  }\r\n\r\n  void\
    \ reset() {\r\n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\
    \n};\r\n\r\ntemplate <typename KEY, typename VAL>\r\nstruct HashMap {\r\n  HashMapLL<VAL,\
    \ 20> MP;\r\n  function<ll(KEY)> f;\r\n  HashMap(function<ll(KEY)> f) : MP(),\
    \ f(f) {}\r\n  int index(const KEY& key) { return MP.index(f(key)); }\r\n\r\n\
    \  VAL& operator[](const KEY& key) { return MP[f(key)]; }\r\n\r\n  bool contain(const\
    \ KEY& key) { return MP.contain(f(key)); }\r\n\r\n  bool count(const KEY& key)\
    \ { return MP.count(f(key)); }\r\n\r\n  void reset() { MP.reset(); }\r\n};\r\n"
  code: "template <typename Val, int LOG = 20>\r\nstruct HashMapLL {\r\n  int N;\r\
    \n  ll* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1 << LOG> used;\r\n\
    \  const int shift;\r\n  const uint64_t r = 11995408973635179863ULL;\r\n  HashMapLL()\r\
    \n      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64 - __lg(N))\
    \ {}\r\n  int hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\n     \
    \   = std::chrono::steady_clock::now().time_since_epoch().count();\r\n    return\
    \ (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const ll&\
    \ key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] != key;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ bool contain(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  bool count(const ll& key) {\r\n    int i\
    \ = index(key);\r\n    return used[i] && keys[i] == key;\r\n  }\r\n\r\n  void\
    \ reset() {\r\n    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\
    \n};\r\n\r\ntemplate <typename KEY, typename VAL>\r\nstruct HashMap {\r\n  HashMapLL<VAL,\
    \ 20> MP;\r\n  function<ll(KEY)> f;\r\n  HashMap(function<ll(KEY)> f) : MP(),\
    \ f(f) {}\r\n  int index(const KEY& key) { return MP.index(f(key)); }\r\n\r\n\
    \  VAL& operator[](const KEY& key) { return MP[f(key)]; }\r\n\r\n  bool contain(const\
    \ KEY& key) { return MP.contain(f(key)); }\r\n\r\n  bool count(const KEY& key)\
    \ { return MP.count(f(key)); }\r\n\r\n  void reset() { MP.reset(); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/hashmap.hpp
  requiredBy:
  - mod/mod_kth_root.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/981_mod_kth_root.test.cpp
  - test/library_checker/math/kth_root_mod.test.cpp
  - test/library_checker/datastructure/associative_array_hashmap.test.cpp
documentation_of: ds/hashmap.hpp
layout: document
redirect_from:
- /library/ds/hashmap.hpp
- /library/ds/hashmap.hpp.html
title: ds/hashmap.hpp
---
