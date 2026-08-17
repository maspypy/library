---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/euler_walk.hpp
    title: graph/euler_walk.hpp
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
  bundledCode: "#line 1 \"graph/vs_to_es.hpp\"\n\n#line 1 \"ds/hashmap.hpp\"\n\n//\
    \ u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\
    \u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n);\
    \ }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n  \
    \  cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\n    return\
    \ i;\n  }\n\n  Val& operator[](const u64& k) {\n    if (cap == 0) extend();\n\
    \    int i = index(k);\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] =\
    \ Val{}, --cap; }\n    return val[i];\n  }\n\n  Val get(const u64& k, Val default_value)\
    \ {\n    int i = index(k);\n    return (used[i] ? val[i] : default_value);\n \
    \ }\n\n  bool count(const u64& k) {\n    int i = index(k);\n    return used[i]\
    \ && key[i] == k;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n\
    \  u32 cap, mask;\n  vc<u64> key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64\
    \ x) {\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b]: dat) (*this)[a] = b;\n\
    \  }\n};\n#line 3 \"graph/vs_to_es.hpp\"\n\ntemplate <typename GT>\nvc<int> vs_to_es(GT&\
    \ G, vc<int>& vs, bool allow_use_twice = false) {\n  assert(!vs.empty());\n\n\
    \  HashMap<int> MP(G.M);\n  vc<int> nxt(G.M, -1);\n\n  auto get = [&](ll a, ll\
    \ b) -> u64 {\n    if (!GT::is_directed && a > b) swap(a, b);\n    return a *\
    \ G.N + b;\n  };\n\n  FOR(eid, G.M) {\n    u64 k = get(G.edges[eid].frm, G.edges[eid].to);\n\
    \    int x = MP.get(k, -1);\n    nxt[eid] = x, MP[k] = eid;\n  }\n  int n = len(vs);\n\
    \  vc<int> es(n - 1);\n  FOR(i, n - 1) {\n    u64 k = get(vs[i], vs[i + 1]);\n\
    \    int eid = MP.get(k, -1);\n    assert(eid != -1);\n    es[i] = eid;\n    if\
    \ (!allow_use_twice) { MP[k] = nxt[eid]; }\n  }\n  return es;\n}\n"
  code: "\n#include \"ds/hashmap.hpp\"\n\ntemplate <typename GT>\nvc<int> vs_to_es(GT&\
    \ G, vc<int>& vs, bool allow_use_twice = false) {\n  assert(!vs.empty());\n\n\
    \  HashMap<int> MP(G.M);\n  vc<int> nxt(G.M, -1);\n\n  auto get = [&](ll a, ll\
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
  - graph/euler_walk.hpp
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/eulerwalk_d.test.cpp
  - test/2_library_checker/graph/eulerwalk_ud.test.cpp
documentation_of: graph/vs_to_es.hpp
layout: document
redirect_from:
- /library/graph/vs_to_es.hpp
- /library/graph/vs_to_es.hpp.html
title: graph/vs_to_es.hpp
---
