---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1292.test.cpp
    title: test/yukicoder/1292.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2102.test.cpp
    title: test/yukicoder/2102.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/hashset.hpp\"\n\ntemplate <int LOG = 20>\nstruct HashSetLL\
    \ {\n  int N;\n  int sz;\n  ll* keys;\n  bitset<1 << LOG> used;\n  const int shift;\n\
    \  const uint64_t r = 11995408973635179863ULL;\n  HashSetLL() : N(1 << LOG), sz(0),\
    \ keys(new ll[N]), shift(64 - __lg(N)) {}\n  int hash(ll x) {\n    static const\
    \ uint64_t FIXED_RANDOM\n        = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\n  }\n\n  int index(const\
    \ ll& key) {\n    int i = 0;\n    for (i = hash(key); used[i] && keys[i] != key;\
    \ (i += 1) &= (N - 1)) {}\n    return i;\n  }\n\n  void insert(const ll& key)\
    \ {\n    int i = index(key);\n    if (!used[i]) used[i] = 1, keys[i] = key, ++sz;\n\
    \  }\n\n  void erase(const ll& key) {\n    int i = index(key);\n    used[i] =\
    \ 0;\n    --sz;\n  }\n\n  bool count(const ll& key) {\n    int i = index(key);\n\
    \    return used[i] && keys[i] == key;\n  }\n\n  int size() { return sz; }\n};\n"
  code: "\ntemplate <int LOG = 20>\nstruct HashSetLL {\n  int N;\n  int sz;\n  ll*\
    \ keys;\n  bitset<1 << LOG> used;\n  const int shift;\n  const uint64_t r = 11995408973635179863ULL;\n\
    \  HashSetLL() : N(1 << LOG), sz(0), keys(new ll[N]), shift(64 - __lg(N)) {}\n\
    \  int hash(ll x) {\n    static const uint64_t FIXED_RANDOM\n        = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\n  }\n\n  int index(const\
    \ ll& key) {\n    int i = 0;\n    for (i = hash(key); used[i] && keys[i] != key;\
    \ (i += 1) &= (N - 1)) {}\n    return i;\n  }\n\n  void insert(const ll& key)\
    \ {\n    int i = index(key);\n    if (!used[i]) used[i] = 1, keys[i] = key, ++sz;\n\
    \  }\n\n  void erase(const ll& key) {\n    int i = index(key);\n    used[i] =\
    \ 0;\n    --sz;\n  }\n\n  bool count(const ll& key) {\n    int i = index(key);\n\
    \    return used[i] && keys[i] == key;\n  }\n\n  int size() { return sz; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/hashset.hpp
  requiredBy: []
  timestamp: '2022-10-23 22:09:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1292.test.cpp
  - test/yukicoder/2102.test.cpp
documentation_of: ds/hashset.hpp
layout: document
redirect_from:
- /library/ds/hashset.hpp
- /library/ds/hashset.hpp.html
title: ds/hashset.hpp
---
