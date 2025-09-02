---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: ds/meldable_heap.hpp
    title: ds/meldable_heap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/reverse_graph.hpp
    title: graph/reverse_graph.hpp
  - icon: ':question:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/K_shortest_walk.test.cpp
    title: test/2_library_checker/graph/K_shortest_walk.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/meldable_heap.hpp\"\n\ntemplate <typename VAL, bool PERSISTENT,\
    \ bool TOP_IS_MIN>\nstruct Meldable_Heap {\n  struct Node {\n    Node *l, *r;\n\
    \    VAL x;\n    u32 size, dist; // dist: leaf \u307E\u3067\u306E\u8DDD\u96E2\n\
    \  };\n  Node *pool;\n  const int NODES;\n  int pid;\n  using np = Node *;\n\n\
    \  Meldable_Heap(int NODES) : NODES(NODES), pid(0) { pool = new Node[NODES]; }\n\
    \  ~Meldable_Heap() { delete[] pool; }\n  np new_root() { return nullptr; }\n\
    \  np new_node(const VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n   \
    \ pool[pid].x = x, pool[pid].size = 1, pool[pid].dist = 1;\n    return &(pool[pid++]);\n\
    \  }\n  np copy_node(np a) {\n    if (!a || !PERSISTENT) return a;\n    np b =\
    \ new_node(a->x);\n    b->l = a->l, b->r = a->r;\n    b->size = a->size, b->dist\
    \ = a->dist;\n    return b;\n  }\n  np meld(np a, np b) {\n    if (!a) return\
    \ b;\n    if (!b) return a;\n    a = copy_node(a);\n    b = copy_node(b);\n  \
    \  if constexpr (TOP_IS_MIN) {\n      if ((a->x) > (b->x)) swap(a, b);\n    }\
    \ else {\n      if ((a->x) < (b->x)) swap(a, b);\n    }\n    a->r = meld(a->r,\
    \ b);\n    if (!(a->l) || (a->l->dist < a->r->dist)) swap(a->l, a->r);\n    a->dist\
    \ = (a->r ? a->r->dist : 0) + 1;\n    a->size = 1;\n    if (a->l) a->size += a->l->size;\n\
    \    if (a->r) a->size += a->r->size;\n    return a;\n  }\n  np push(np a, VAL\
    \ x) { return meld(a, new_node(x)); }\n  np pop(np a) { return meld(a->l, a->r);\
    \ }\n  VAL top(np a) { return a->x; }\n  vc<VAL> get_all(np a) {\n    vc<VAL>\
    \ A;\n    auto dfs = [&](auto &dfs, np a) -> void {\n      if (!a) return;\n \
    \     A.eb(a->x), dfs(dfs, a->l), dfs(dfs, a->r);\n    };\n    dfs(dfs, a);\n\
    \    sort(all(A));\n    if (!TOP_IS_MIN) reverse(all(A));\n    return A;\n  }\n\
    };\n\n// \u5168\u4F53\u52A0\u7B97\u304C\u3067\u304D\u308B\u3088\u3046\u306B\u3059\
    \u308B\n// path sum \u304C\u5B9F\u969B\u306E\u5024\u3068\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308C\u3070\u8FFD\u52A0\u30D5\u30A3\u30FC\u30EB\u30C9\u306A\u3057\
    \u306B\u5B9F\u73FE\u3067\u304D\u308B\n// https://qoj.ac/contest/1699/problem/8518\n\
    template <typename VAL, bool PERSISTENT, bool TOP_IS_MIN>\nstruct Lazy_Meldable_Heap\
    \ {\n  struct Node {\n    Node *l, *r;\n    VAL x;\n    u32 size;\n  };\n  Node\
    \ *pool;\n  const int NODES;\n  int pid;\n  using np = Node *;\n\n  Lazy_Meldable_Heap(int\
    \ NODES) : NODES(NODES), pid(0) { pool = new Node[NODES]; }\n  ~Lazy_Meldable_Heap()\
    \ { delete[] pool; }\n  np new_root() { return nullptr; }\n  np new_node(const\
    \ VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x = x, pool[pid].size\
    \ = 1;\n    return &(pool[pid++]);\n  }\n  np copy_node(np a) {\n    if (!a ||\
    \ !PERSISTENT) return a;\n    np b = new_node(a->x);\n    b->l = a->l, b->r =\
    \ a->r;\n    b->size = a->size;\n    return b;\n  }\n  np apply(np a, VAL x) {\n\
    \    if (!a) return a;\n    a = copy_node(a);\n    a->x += x;\n    return a;\n\
    \  }\n  np meld(np a, np b, VAL add_a = 0, VAL add_b = 0) {\n    if (!a) { return\
    \ (add_b == 0 ? b : apply(b, add_b)); }\n    if (!b) { return (add_a == 0 ? a\
    \ : apply(a, add_a)); }\n    if constexpr (TOP_IS_MIN) {\n      if ((a->x + add_a)\
    \ > (b->x + add_b)) swap(a, b), swap(add_a, add_b);\n    } else {\n      if ((a->x\
    \ + add_a) < (b->x + add_b)) swap(a, b), swap(add_a, add_b);\n    }\n    a = copy_node(a);\n\
    \    a->x += add_a;\n    a->r = meld(a->r, b, 0, -a->x + add_b);\n    if (!(a->l)\
    \ || (a->l->size < a->r->size)) swap(a->l, a->r);\n    a->size = 1;\n    if (a->l)\
    \ a->size += a->l->size;\n    if (a->r) a->size += a->r->size;\n    return a;\n\
    \  }\n\n  np push(np a, VAL x) { return meld(a, new_node(x)); }\n  np pop(np a)\
    \ { return meld(a->l, a->r, a->x, a->x); }\n  VAL top(np a) { return a->x; }\n\
    \  vc<VAL> get_all(np a) {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs, np a,\
    \ VAL lazy) -> void {\n      if (!a) return;\n      A.eb(a->x + lazy);\n     \
    \ lazy += a->x;\n      dfs(dfs, a->l, lazy), dfs(dfs, a->r, lazy);\n    };\n \
    \   dfs(dfs, a, 0);\n    sort(all(A));\n    if (!TOP_IS_MIN) reverse(all(A));\n\
    \    return A;\n  }\n};\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate\
    \ <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\
    \u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void\
    \ build(u32 n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap\
    \ = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\
    \n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\
    \n    used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int\
    \ size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n\
    \    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) &\
    \ mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n\
    \    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\
    \n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\n  \
    \  return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
    \ u64& k) {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n\
    \  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n  void enumerate_all(F\
    \ f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\n\
    private:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool>\
    \ used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  static constexpr\
    \ bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int\
    \ N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N = n, M = 0;\n\
    \    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed) csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost,\
    \ e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n    print(\"Graph\");\n    if\
    \ (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n\
    \  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\
    \u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\
    \u306A\u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\
    \u306E n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid =\
    \ 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n\
    \    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  HashMap<int> MP_FOR_EID;\n\n\
    \  int get_eid(u64 a, u64 b) {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N\
    \ - 1);\n      for (auto& e: edges) {\n        u64 a = e.frm, b = e.to;\n    \
    \    u64 k = to_eid_key(a, b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n\
    \    return MP_FOR_EID.get(to_eid_key(a, b), -1);\n  }\n\n  u64 to_eid_key(u64\
    \ a, u64 b) {\n    if (!directed && a > b) swap(a, b);\n    return N * a + b;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 3 \"graph/shortest_path/dijkstra.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\npair<vc<T>, vc<int>> dijkstra_dense(GT& G, int s) {\n  const int N = G.N;\n\
    \  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  vc<bool> done(N);\n  dist[s]\
    \ = 0;\n  while (1) {\n    int v = -1;\n    T mi = infty<T>;\n    FOR(i, N) {\n\
    \      if (!done[i] && chmin(mi, dist[i])) v = i;\n    }\n    if (v == -1) break;\n\
    \    done[v] = 1;\n    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to], dist[v]\
    \ + e.cost)) par[e.to] = v;\n    }\n  }\n  return {dist, par};\n}\n\ntemplate\
    \ <typename T, typename GT, bool DENSE = false>\npair<vc<T>, vc<int>> dijkstra(GT&\
    \ G, int v) {\n  if (DENSE) return dijkstra_dense<T>(G, v);\n  auto N = G.N;\n\
    \  vector<T> dist(N, infty<T>);\n  vector<int> par(N, -1);\n  using P = pair<T,\
    \ int>;\n\n  priority_queue<P, vector<P>, greater<P>> que;\n\n  dist[v] = 0;\n\
    \  que.emplace(0, v);\n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n\
    \    que.pop();\n    if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n\
    \      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {\n        par[e.to] = e.frm;\n\
    \        que.emplace(dist[e.to], e.to);\n      }\n    }\n  }\n  return {dist,\
    \ par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\n\
    template <typename T, typename GT>\ntuple<vc<T>, vc<int>, vc<int>> dijkstra(GT&\
    \ G, vc<int> vs) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<T> dist(N,\
    \ infty<T>);\n  vc<int> par(N, -1);\n  vc<int> root(N, -1);\n\n  using P = pair<T,\
    \ int>;\n\n  priority_queue<P, vector<P>, greater<P>> que;\n\n  for (auto&& v:\
    \ vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.emplace(T(0), v);\n  }\n\n\
    \  while (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n   \
    \ if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to],\
    \ dist[e.frm] + e.cost)) {\n        root[e.to] = root[e.frm];\n        par[e.to]\
    \ = e.frm;\n        que.push(mp(dist[e.to], e.to));\n      }\n    }\n  }\n  return\
    \ {dist, par, root};\n}\n#line 2 \"graph/reverse_graph.hpp\"\n\r\ntemplate <typename\
    \ GT>\r\nGT reverse_graph(GT& G) {\r\n  static_assert(GT::is_directed);\r\n  GT\
    \ G1(G.N);\r\n  for (auto&& e: G.edges) { G1.add(e.to, e.frm, e.cost, e.id); }\r\
    \n  G1.build();\r\n  return G1;\r\n}\r\n#line 4 \"graph/shortest_path/K_shortest_walk.hpp\"\
    \n\n// infty<T> \u57CB\u3081\u3057\u3066\u5FC5\u305A\u9577\u3055 K \u306B\u3057\
    \u305F\u3082\u306E\u3092\u304B\u3048\u3059\u3002\ntemplate <typename T, typename\
    \ GT>\nvc<T> K_shortest_walk(GT &G, int s, int t, int K) {\n  static_assert(GT::is_directed);\n\
    \  int N = G.N;\n  auto RG = reverse_graph(G);\n  auto [dist, par] = dijkstra<T,\
    \ decltype(RG)>(RG, t);\n  if (dist[s] == infty<T>) { return vc<T>(K, infty<T>);\
    \ }\n\n  using P = pair<T, int>;\n  Meldable_Heap<P, true, true> X(20 * G.M);\n\
    \  using np = typename decltype(X)::np;\n  vc<np> nodes(N, nullptr);\n\n  vc<bool>\
    \ vis(N);\n  vc<int> st = {t};\n  vis[t] = 1;\n  while (len(st)) {\n    int v\
    \ = POP(st);\n    bool done = 0;\n    for (auto &&e: G[v]) {\n      if (dist[e.to]\
    \ == infty<T>) continue;\n      if (!done && par[v] == e.to && dist[v] == dist[e.to]\
    \ + e.cost) {\n        done = 1;\n        continue;\n      }\n      T cost = -dist[v]\
    \ + e.cost + dist[e.to];\n      nodes[v] = X.push(nodes[v], {cost, e.to});\n \
    \   }\n    for (auto &&e: RG[v]) {\n      if (vis[e.to]) continue;\n      if (par[e.to]\
    \ == v) {\n        nodes[e.to] = X.meld(nodes[e.to], nodes[v]);\n        vis[e.to]\
    \ = 1;\n        st.eb(e.to);\n      }\n    }\n  }\n\n  T base = dist[s];\n  vc<T>\
    \ ANS = {base};\n  if (nodes[s]) {\n    using PAIR = pair<T, np>;\n    auto comp\
    \ = [](auto a, auto b) { return a.fi > b.fi; };\n    priority_queue<PAIR, vc<PAIR>,\
    \ decltype(comp)> que(comp);\n    que.emplace(base + X.top(nodes[s]).fi, nodes[s]);\n\
    \    while (len(ANS) < K && len(que)) {\n      auto [d, n] = que.top();\n    \
    \  que.pop();\n      ANS.eb(d);\n      if (n->l) que.emplace(d + (n->l->x.fi)\
    \ - (n->x.fi), n->l);\n      if (n->r) que.emplace(d + (n->r->x.fi) - (n->x.fi),\
    \ n->r);\n      np m = nodes[n->x.se];\n      if (m) { que.emplace(d + m->x.fi,\
    \ m); }\n    }\n  }\n  while (len(ANS) < K) ANS.eb(infty<T>);\n  return ANS;\n\
    }\n"
  code: "#include \"ds/meldable_heap.hpp\"\n#include \"graph/shortest_path/dijkstra.hpp\"\
    \n#include \"graph/reverse_graph.hpp\"\n\n// infty<T> \u57CB\u3081\u3057\u3066\
    \u5FC5\u305A\u9577\u3055 K \u306B\u3057\u305F\u3082\u306E\u3092\u304B\u3048\u3059\
    \u3002\ntemplate <typename T, typename GT>\nvc<T> K_shortest_walk(GT &G, int s,\
    \ int t, int K) {\n  static_assert(GT::is_directed);\n  int N = G.N;\n  auto RG\
    \ = reverse_graph(G);\n  auto [dist, par] = dijkstra<T, decltype(RG)>(RG, t);\n\
    \  if (dist[s] == infty<T>) { return vc<T>(K, infty<T>); }\n\n  using P = pair<T,\
    \ int>;\n  Meldable_Heap<P, true, true> X(20 * G.M);\n  using np = typename decltype(X)::np;\n\
    \  vc<np> nodes(N, nullptr);\n\n  vc<bool> vis(N);\n  vc<int> st = {t};\n  vis[t]\
    \ = 1;\n  while (len(st)) {\n    int v = POP(st);\n    bool done = 0;\n    for\
    \ (auto &&e: G[v]) {\n      if (dist[e.to] == infty<T>) continue;\n      if (!done\
    \ && par[v] == e.to && dist[v] == dist[e.to] + e.cost) {\n        done = 1;\n\
    \        continue;\n      }\n      T cost = -dist[v] + e.cost + dist[e.to];\n\
    \      nodes[v] = X.push(nodes[v], {cost, e.to});\n    }\n    for (auto &&e: RG[v])\
    \ {\n      if (vis[e.to]) continue;\n      if (par[e.to] == v) {\n        nodes[e.to]\
    \ = X.meld(nodes[e.to], nodes[v]);\n        vis[e.to] = 1;\n        st.eb(e.to);\n\
    \      }\n    }\n  }\n\n  T base = dist[s];\n  vc<T> ANS = {base};\n  if (nodes[s])\
    \ {\n    using PAIR = pair<T, np>;\n    auto comp = [](auto a, auto b) { return\
    \ a.fi > b.fi; };\n    priority_queue<PAIR, vc<PAIR>, decltype(comp)> que(comp);\n\
    \    que.emplace(base + X.top(nodes[s]).fi, nodes[s]);\n    while (len(ANS) <\
    \ K && len(que)) {\n      auto [d, n] = que.top();\n      que.pop();\n      ANS.eb(d);\n\
    \      if (n->l) que.emplace(d + (n->l->x.fi) - (n->x.fi), n->l);\n      if (n->r)\
    \ que.emplace(d + (n->r->x.fi) - (n->x.fi), n->r);\n      np m = nodes[n->x.se];\n\
    \      if (m) { que.emplace(d + m->x.fi, m); }\n    }\n  }\n  while (len(ANS)\
    \ < K) ANS.eb(infty<T>);\n  return ANS;\n}\n"
  dependsOn:
  - ds/meldable_heap.hpp
  - graph/shortest_path/dijkstra.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/reverse_graph.hpp
  isVerificationFile: false
  path: graph/shortest_path/K_shortest_walk.hpp
  requiredBy: []
  timestamp: '2025-04-06 22:14:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/K_shortest_walk.test.cpp
documentation_of: graph/shortest_path/K_shortest_walk.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/K_shortest_walk.hpp
- /library/graph/shortest_path/K_shortest_walk.hpp.html
title: graph/shortest_path/K_shortest_walk.hpp
---
