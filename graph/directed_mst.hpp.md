---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/graph/directed_mst.test.cpp
    title: test/2_library_checker/graph/directed_mst.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename\
    \ Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\
    \u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32\
    \ n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2,\
    \ mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\
    \n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\
    \u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n   \
    \ used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size()\
    \ { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int\
    \ i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask)\
    \ {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if\
    \ (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i]) { used[i]\
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
    #line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int n, n_comp;\n\
    \  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n); }\n\n  void\
    \ build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n  }\n\n  void\
    \ reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x] >= 0)\
    \ {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n     \
    \ x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n    x = (*this)[x];\n\
    \    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n    x = (*this)[x],\
    \ y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x] < -dat[y]) swap(x,\
    \ y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return true;\n  }\n\n\
    \  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] = (*this)[i];\n\
    \    return A;\n  }\n};\n#line 3 \"graph/directed_mst.hpp\"\n\ntemplate <typename\
    \ GT>\nstruct Directed_MST_Solver {\n  using T = typename GT::cost_type;\n  GT\
    \ &G;\n\n  Directed_MST_Solver(GT &G) : G(G), pid(0) { pool = new Node[2 * (G.N\
    \ + G.M)]; }\n  ~Directed_MST_Solver() { delete[] pool; }\n\n  vc<int> calc(int\
    \ root) {\n    int N = G.N, M = G.M;\n    vc<np> que(N);\n    for (auto &e: G.edges)\
    \ { que[e.to] = meld(que[e.to], new_node(e.frm, e.cost, e.id)); }\n    vc<char>\
    \ used(N + M);\n    used[root] = 2;\n    vc<Edge> best_edge(N + M);\n    vc<int>\
    \ par(N + M, -1); // merge \u904E\u7A0B\u306E\u6728\n    vc<int> rt(N + M);\n\
    \    FOR(i, N) rt[i] = i;\n    UnionFind uf(N + M);\n    int nxt = N;\n    for\
    \ (int s = 0; s < N; ++s) {\n      if (used[s] != 0) continue;\n      vc<int>\
    \ path = {s};\n      while (1) {\n        int a = path.back();\n        assert(used[a]\
    \ == 0);\n        used[a] = 1;\n        if (!que[a]) { return {}; }\n        best_edge[a]\
    \ = pop(que[a]);\n        int to = rt[uf[best_edge[a].to]];\n        if (used[to]\
    \ == 0) {\n          path.eb(to);\n          continue;\n        }\n        if\
    \ (used[to] == 2) break;\n        // cycle \u767A\u898B\n        int v = nxt++;\n\
    \        que.eb(nullptr);\n        while (1) {\n          int w = POP(path);\n\
    \          T sub = best_edge[w].cost;\n          que[v] = meld(que[v], add(que[w],\
    \ -sub));\n          uf.merge(v, w), par[w] = v;\n          used[w] = 2;\n   \
    \       if (w == to) break;\n        }\n        rt[uf[v]] = v;\n        path.eb(v);\n\
    \      }\n      for (auto &v: path) used[v] = 2;\n    }\n\n    vc<int> res;\n\
    \    vc<bool> done(nxt);\n    done[root] = 1;\n    FOR_R(v, nxt) {\n      if (done[v])\
    \ continue;\n      int id = best_edge[v].id;\n      res.eb(id);\n      int x =\
    \ G.edges[id].to;\n      while (x != -1 && !done[x]) { done[x] = 1, x = par[x];\
    \ }\n    }\n    return res;\n  }\n\nprivate:\n  struct Edge {\n    int to, id;\n\
    \    T cost;\n  };\n\n  struct Node {\n    Node *l, *r;\n    Edge e;\n    T lazy;\n\
    \    int s;\n  };\n\n  Node *pool;\n  using np = Node *;\n  int pid;\n\n  np new_node(int\
    \ to, T cost, int id) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].s\
    \ = 1;\n    pool[pid].e = Edge{to, id, cost};\n    pool[pid].lazy = 0;\n    return\
    \ &(pool[pid++]);\n  }\n\n  np add(np a, T x) {\n    if (a) a->e.cost += x, a->lazy\
    \ += x;\n    return a;\n  }\n\n  np meld(np a, np b) {\n    if (!a) return b;\n\
    \    if (!b) return a;\n    if ((a->e.cost) > (b->e.cost)) swap(a, b);\n    b\
    \ = add(b, -(a->lazy));\n    a->r = (a->r ? meld(a->r, b) : b);\n    if (!(a->l)\
    \ || (a->l->s < a->r->s)) swap(a->l, a->r);\n    a->s = (a->r ? a->r->s : 0) +\
    \ 1;\n    return a;\n  }\n\n  Edge pop(np &a) {\n    Edge e = a->e;\n    a = meld(add(a->l,\
    \ a->lazy), add(a->r, a->lazy));\n    return e;\n  }\n};\n\ntemplate <typename\
    \ GT>\npair<typename GT::cost_type, vc<int>> directed_mst(GT &G, int root) {\n\
    \  Directed_MST_Solver<GT> D(G);\n  using T = typename GT::cost_type;\n  auto\
    \ I = D.calc(root);\n  T cost = 0;\n  for (auto &i: I) cost += G.edges[i].cost;\n\
    \  return {cost, I};\n};\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n\n\
    template <typename GT>\nstruct Directed_MST_Solver {\n  using T = typename GT::cost_type;\n\
    \  GT &G;\n\n  Directed_MST_Solver(GT &G) : G(G), pid(0) { pool = new Node[2 *\
    \ (G.N + G.M)]; }\n  ~Directed_MST_Solver() { delete[] pool; }\n\n  vc<int> calc(int\
    \ root) {\n    int N = G.N, M = G.M;\n    vc<np> que(N);\n    for (auto &e: G.edges)\
    \ { que[e.to] = meld(que[e.to], new_node(e.frm, e.cost, e.id)); }\n    vc<char>\
    \ used(N + M);\n    used[root] = 2;\n    vc<Edge> best_edge(N + M);\n    vc<int>\
    \ par(N + M, -1); // merge \u904E\u7A0B\u306E\u6728\n    vc<int> rt(N + M);\n\
    \    FOR(i, N) rt[i] = i;\n    UnionFind uf(N + M);\n    int nxt = N;\n    for\
    \ (int s = 0; s < N; ++s) {\n      if (used[s] != 0) continue;\n      vc<int>\
    \ path = {s};\n      while (1) {\n        int a = path.back();\n        assert(used[a]\
    \ == 0);\n        used[a] = 1;\n        if (!que[a]) { return {}; }\n        best_edge[a]\
    \ = pop(que[a]);\n        int to = rt[uf[best_edge[a].to]];\n        if (used[to]\
    \ == 0) {\n          path.eb(to);\n          continue;\n        }\n        if\
    \ (used[to] == 2) break;\n        // cycle \u767A\u898B\n        int v = nxt++;\n\
    \        que.eb(nullptr);\n        while (1) {\n          int w = POP(path);\n\
    \          T sub = best_edge[w].cost;\n          que[v] = meld(que[v], add(que[w],\
    \ -sub));\n          uf.merge(v, w), par[w] = v;\n          used[w] = 2;\n   \
    \       if (w == to) break;\n        }\n        rt[uf[v]] = v;\n        path.eb(v);\n\
    \      }\n      for (auto &v: path) used[v] = 2;\n    }\n\n    vc<int> res;\n\
    \    vc<bool> done(nxt);\n    done[root] = 1;\n    FOR_R(v, nxt) {\n      if (done[v])\
    \ continue;\n      int id = best_edge[v].id;\n      res.eb(id);\n      int x =\
    \ G.edges[id].to;\n      while (x != -1 && !done[x]) { done[x] = 1, x = par[x];\
    \ }\n    }\n    return res;\n  }\n\nprivate:\n  struct Edge {\n    int to, id;\n\
    \    T cost;\n  };\n\n  struct Node {\n    Node *l, *r;\n    Edge e;\n    T lazy;\n\
    \    int s;\n  };\n\n  Node *pool;\n  using np = Node *;\n  int pid;\n\n  np new_node(int\
    \ to, T cost, int id) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].s\
    \ = 1;\n    pool[pid].e = Edge{to, id, cost};\n    pool[pid].lazy = 0;\n    return\
    \ &(pool[pid++]);\n  }\n\n  np add(np a, T x) {\n    if (a) a->e.cost += x, a->lazy\
    \ += x;\n    return a;\n  }\n\n  np meld(np a, np b) {\n    if (!a) return b;\n\
    \    if (!b) return a;\n    if ((a->e.cost) > (b->e.cost)) swap(a, b);\n    b\
    \ = add(b, -(a->lazy));\n    a->r = (a->r ? meld(a->r, b) : b);\n    if (!(a->l)\
    \ || (a->l->s < a->r->s)) swap(a->l, a->r);\n    a->s = (a->r ? a->r->s : 0) +\
    \ 1;\n    return a;\n  }\n\n  Edge pop(np &a) {\n    Edge e = a->e;\n    a = meld(add(a->l,\
    \ a->lazy), add(a->r, a->lazy));\n    return e;\n  }\n};\n\ntemplate <typename\
    \ GT>\npair<typename GT::cost_type, vc<int>> directed_mst(GT &G, int root) {\n\
    \  Directed_MST_Solver<GT> D(G);\n  using T = typename GT::cost_type;\n  auto\
    \ I = D.calc(root);\n  T cost = 0;\n  for (auto &i: I) cost += G.edges[i].cost;\n\
    \  return {cost, I};\n};\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/directed_mst.hpp
  requiredBy: []
  timestamp: '2025-04-06 22:14:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/graph/directed_mst.test.cpp
documentation_of: graph/directed_mst.hpp
layout: document
redirect_from:
- /library/graph/directed_mst.hpp
- /library/graph/directed_mst.hpp.html
title: graph/directed_mst.hpp
---
