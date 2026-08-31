---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: alg/monoid/min2.hpp
    title: alg/monoid/min2.hpp
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\n\
    struct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\
    \u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n \
    \   u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n\
    \    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\
    \u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build\
    \ \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used), 0);\n\
    \    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\
    \n  int index(const u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] &&\
    \ key[i] != k; i = (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const\
    \ u64& k) {\n    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i])\
    \ { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64>\
    \ key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const\
    \ u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b]: dat) (*this)[a] = b;\n\
    \  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  HashMap<int> MP_FOR_EID;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n   public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) {\n        return 0;\n\
    \      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const Graph*\
    \ G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph()\
    \ : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n\
    \  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n    MP_FOR_EID.clear();\n  }\n\n  void add(int frm, int\
    \ to, T cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm &&\
    \ frm < N && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n\
    \  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off);\
    \ }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n    for (int\
    \ m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n      if\
    \ (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e : edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) {\n      indptr[v\
    \ + 1] += indptr[v];\n    }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e : edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n\
    \    print(\"Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n\
    \      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n\
    \      print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n    }\n  \
    \  flush();\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\n\
    \  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e : (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid : history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) {\n\
    \    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for (auto&\
    \ e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) {\n    if (!directed && a >\
    \ b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e : edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e : edges)\
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 1 \"alg/monoid/min2.hpp\"\
    \n\ntemplate <typename T, typename KEY>\nstruct Monoid_Min2 {\n  struct Data {\n\
    \    T min1, min2;\n    KEY key1, key2;\n    bool add_element(KEY key, T x) {\n\
    \      if (key1 == key) { return chmin(min1, x); }\n      if (key2 == key) {\n\
    \        bool upd = chmin(min2, x);\n        if (min1 > min2) swap(min1, min2),\
    \ swap(key1, key2);\n        return upd;\n      }\n      if (min1 > x) {\n   \
    \     min2 = min1, key2 = key1, min1 = x, key1 = key;\n        return 1;\n   \
    \   }\n      elif (min2 > x) {\n        min2 = x, key2 = key;\n        return\
    \ 1;\n      }\n      return 0;\n    }\n  };\n  using value_type = Data;\n  using\
    \ X = value_type;\n\n  static X op(X x, X y) {\n    x.add_element(y.key1, y.min1);\n\
    \    x.add_element(y.key2, y.min2);\n    return x;\n  }\n  static constexpr X\
    \ id() { return {infty<T>, infty<T>, -1, -1}; }\n  static constexpr bool commute\
    \ = true;\n};\n#line 3 \"graph/shortest_path/top2_dijkstra.hpp\"\n\n// \u7D4C\u8DEF\
    \u5FA9\u5143\u306F\u306A\u3057\u3067\u8DDD\u96E2\u3068\u7A2E\u985E\u3060\u3051\
    \u306B\u306A\u3063\u3066\u3044\u308B\ntemplate <typename T, typename GT>\nvc<typename\
    \ Monoid_Min2<T, int>::Data> top2_dijkstra(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  using Mono = Monoid_Min2<T, int>;\n  using Data = typename\
    \ Mono::Data;\n  vc<Data> dist(N, Mono::id());\n  pq_min<tuple<T, int, int>> que;\
    \  // \u8DDD\u96E2\u3001\u753A\u3001\u8272\n\n  auto upd = [&](int v, int c, T\
    \ x) -> void {\n    if (dist[v].add_element(x, c)) que.emplace(x, v, c);\n  };\n\
    \n  for (auto& v : vs) {\n    upd(v, v, 0);\n  }\n\n  while (len(que)) {\n   \
    \ auto [dv, v, c] = POP(que);\n    bool ok = 0;\n    auto& e = dist[v];\n    if\
    \ (e.min1 == dv && e.key1 == c) ok = 1;\n    if (e.min2 == dv && e.key2 == c)\
    \ ok = 1;\n    if (!ok) continue;\n    for (auto&& e : G[v]) {\n      upd(e.to,\
    \ c, dv + e.cost);\n    }\n  }\n  return dist;\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"alg/monoid/min2.hpp\"\n\n// \u7D4C\
    \u8DEF\u5FA9\u5143\u306F\u306A\u3057\u3067\u8DDD\u96E2\u3068\u7A2E\u985E\u3060\
    \u3051\u306B\u306A\u3063\u3066\u3044\u308B\ntemplate <typename T, typename GT>\n\
    vc<typename Monoid_Min2<T, int>::Data> top2_dijkstra(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  using Mono = Monoid_Min2<T, int>;\n  using Data = typename\
    \ Mono::Data;\n  vc<Data> dist(N, Mono::id());\n  pq_min<tuple<T, int, int>> que;\
    \  // \u8DDD\u96E2\u3001\u753A\u3001\u8272\n\n  auto upd = [&](int v, int c, T\
    \ x) -> void {\n    if (dist[v].add_element(x, c)) que.emplace(x, v, c);\n  };\n\
    \n  for (auto& v : vs) {\n    upd(v, v, 0);\n  }\n\n  while (len(que)) {\n   \
    \ auto [dv, v, c] = POP(que);\n    bool ok = 0;\n    auto& e = dist[v];\n    if\
    \ (e.min1 == dv && e.key1 == c) ok = 1;\n    if (e.min2 == dv && e.key2 == c)\
    \ ok = 1;\n    if (!ok) continue;\n    for (auto&& e : G[v]) {\n      upd(e.to,\
    \ c, dv + e.cost);\n    }\n  }\n  return dist;\n}"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - alg/monoid/min2.hpp
  isVerificationFile: false
  path: graph/shortest_path/top2_dijkstra.hpp
  requiredBy: []
  timestamp: '2026-08-30 21:09:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/shortest_path/top2_dijkstra.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/top2_dijkstra.hpp
- /library/graph/shortest_path/top2_dijkstra.hpp.html
title: graph/shortest_path/top2_dijkstra.hpp
---
