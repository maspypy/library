---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/eulerwalk.hpp
    title: graph/eulerwalk.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/arc157a.test.cpp
    title: test_atcoder/arc157a.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/vs_to_es.hpp\"\n\n#line 2 \"random/base.hpp\"\n\n\
    u64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"ds/hashmap.hpp\"\
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
    \ vals[i]);\r\n  }\r\n};\r\n#line 4 \"graph/vs_to_es.hpp\"\n\ntemplate <typename\
    \ GT>\nvc<int> vs_to_es(GT& G, vc<int>& vs, bool allow_use_twice = false) {\n\
    \  assert(!vs.empty());\n\n  static HashMap<int> MP;\n  MP.reset();\n  vc<int>\
    \ nxt(G.M, -1);\n\n  auto get = [&](ll a, ll b) -> u64 {\n    if (!G.is_directed()\
    \ && a > b) swap(a, b);\n    return a * G.N + b;\n  };\n\n  FOR(eid, G.M) {\n\
    \    u64 k = get(G.edges[eid].frm, G.edges[eid].to);\n    int x = MP[k];\n   \
    \ nxt[eid] = x, MP[k] = eid;\n  }\n  int n = len(vs);\n  vc<int> es(n - 1);\n\
    \  FOR(i, n - 1) {\n    u64 k = get(vs[i], vs[i + 1]);\n    int eid = MP.get(k,\
    \ -1);\n    assert(eid != -1);\n    es[i] = eid;\n    if (!allow_use_twice) {\
    \ MP[k] = nxt[eid]; }\n  }\n  return es;\n}\n"
  code: "#pragma once\n\n#include \"ds/hashmap.hpp\"\n\ntemplate <typename GT>\nvc<int>\
    \ vs_to_es(GT& G, vc<int>& vs, bool allow_use_twice = false) {\n  assert(!vs.empty());\n\
    \n  static HashMap<int> MP;\n  MP.reset();\n  vc<int> nxt(G.M, -1);\n\n  auto\
    \ get = [&](ll a, ll b) -> u64 {\n    if (!G.is_directed() && a > b) swap(a, b);\n\
    \    return a * G.N + b;\n  };\n\n  FOR(eid, G.M) {\n    u64 k = get(G.edges[eid].frm,\
    \ G.edges[eid].to);\n    int x = MP[k];\n    nxt[eid] = x, MP[k] = eid;\n  }\n\
    \  int n = len(vs);\n  vc<int> es(n - 1);\n  FOR(i, n - 1) {\n    u64 k = get(vs[i],\
    \ vs[i + 1]);\n    int eid = MP.get(k, -1);\n    assert(eid != -1);\n    es[i]\
    \ = eid;\n    if (!allow_use_twice) { MP[k] = nxt[eid]; }\n  }\n  return es;\n\
    }"
  dependsOn:
  - ds/hashmap.hpp
  - random/base.hpp
  isVerificationFile: false
  path: graph/vs_to_es.hpp
  requiredBy:
  - graph/eulerwalk.hpp
  timestamp: '2023-04-10 18:23:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc157a.test.cpp
documentation_of: graph/vs_to_es.hpp
layout: document
redirect_from:
- /library/graph/vs_to_es.hpp
- /library/graph/vs_to_es.hpp.html
title: graph/vs_to_es.hpp
---
