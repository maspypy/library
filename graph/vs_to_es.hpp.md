---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/eulerwalk.hpp
    title: graph/eulerwalk.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/eulerwalk_d.test.cpp
    title: test/2_library_checker/graph/eulerwalk_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/eulerwalk_ud.test.cpp
    title: test/2_library_checker/graph/eulerwalk_ud.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/vs_to_es.hpp\"\n\n#line 2 \"ds/hashmap.hpp\"\n\r\n\
    // u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n =\
    \ 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while (k\
    \ < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k),\
    \ used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E\
    . size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\
    \n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap = (mask + 1) /\
    \ 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if\
    \ (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return\
    \ val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\n    int\
    \ i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\
    \n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return used[i]\
    \ && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n\
    \  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\
    \n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\
    \n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\r\n    x += FIXED_RANDOM;\r\
    \n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n    return (x ^ (x >> 31)) & mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64,\
    \ Val>> dat;\r\n    dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used))\
    \ {\r\n      if (used[i]) dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\
    \n    for (auto& [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 4 \"graph/vs_to_es.hpp\"\
    \n\ntemplate <typename GT>\nvc<int> vs_to_es(GT& G, vc<int>& vs, bool allow_use_twice\
    \ = false) {\n  assert(!vs.empty());\n\n  HashMap<int> MP(G.M);\n  vc<int> nxt(G.M,\
    \ -1);\n\n  auto get = [&](ll a, ll b) -> u64 {\n    if (!GT::is_directed && a\
    \ > b) swap(a, b);\n    return a * G.N + b;\n  };\n\n  FOR(eid, G.M) {\n    u64\
    \ k = get(G.edges[eid].frm, G.edges[eid].to);\n    int x = MP.get(k, -1);\n  \
    \  nxt[eid] = x, MP[k] = eid;\n  }\n  int n = len(vs);\n  vc<int> es(n - 1);\n\
    \  FOR(i, n - 1) {\n    u64 k = get(vs[i], vs[i + 1]);\n    int eid = MP.get(k,\
    \ -1);\n    assert(eid != -1);\n    es[i] = eid;\n    if (!allow_use_twice) {\
    \ MP[k] = nxt[eid]; }\n  }\n  return es;\n}\n"
  code: "#pragma once\n\n#include \"ds/hashmap.hpp\"\n\ntemplate <typename GT>\nvc<int>\
    \ vs_to_es(GT& G, vc<int>& vs, bool allow_use_twice = false) {\n  assert(!vs.empty());\n\
    \n  HashMap<int> MP(G.M);\n  vc<int> nxt(G.M, -1);\n\n  auto get = [&](ll a, ll\
    \ b) -> u64 {\n    if (!GT::is_directed && a > b) swap(a, b);\n    return a *\
    \ G.N + b;\n  };\n\n  FOR(eid, G.M) {\n    u64 k = get(G.edges[eid].frm, G.edges[eid].to);\n\
    \    int x = MP.get(k, -1);\n    nxt[eid] = x, MP[k] = eid;\n  }\n  int n = len(vs);\n\
    \  vc<int> es(n - 1);\n  FOR(i, n - 1) {\n    u64 k = get(vs[i], vs[i + 1]);\n\
    \    int eid = MP.get(k, -1);\n    assert(eid != -1);\n    es[i] = eid;\n    if\
    \ (!allow_use_twice) { MP[k] = nxt[eid]; }\n  }\n  return es;\n}"
  dependsOn:
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/vs_to_es.hpp
  requiredBy:
  - graph/eulerwalk.hpp
  timestamp: '2024-08-26 01:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/eulerwalk_ud.test.cpp
  - test/2_library_checker/graph/eulerwalk_d.test.cpp
documentation_of: graph/vs_to_es.hpp
layout: document
redirect_from:
- /library/graph/vs_to_es.hpp
- /library/graph/vs_to_es.hpp.html
title: graph/vs_to_es.hpp
---
