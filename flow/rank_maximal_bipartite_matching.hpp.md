---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_vertex_coloring.hpp
    title: graph/bipartite_vertex_coloring.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1615.test.cpp
    title: test/3_yukicoder/1615.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://qoj.ac/contest/1388/problem/6546
    - https://yukicoder.me/problems/no/1615
  bundledCode: "#line 1 \"flow/rank_maximal_bipartite_matching.hpp\"\n\n#line 2 \"\
    graph/bipartite_vertex_coloring.hpp\"\n\r\n#line 2 \"ds/hashmap.hpp\"\n\r\n//\
    \ u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\
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
    \n    for (auto& [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool\
    \ prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph*\
    \ G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n    int l, r;\n\
    \  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() : N(0), M(0),\
    \ prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int\
    \ n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n\
    \    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n\
    \  }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
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
    \    return A;\n  }\n};\n#line 5 \"graph/bipartite_vertex_coloring.hpp\"\n\r\n\
    // \u4E8C\u90E8\u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\
    \u306F empty\r\ntemplate <typename GT>\r\nvc<int> bipartite_vertex_coloring(GT&\
    \ G) {\r\n  assert(!GT::is_directed);\r\n  assert(G.is_prepared());\r\n\r\n  int\
    \ n = G.N;\r\n  UnionFind uf(2 * n);\r\n  for (auto&& e: G.edges) {\r\n    int\
    \ u = e.frm, v = e.to;\r\n    uf.merge(u + n, v), uf.merge(u, v + n);\r\n  }\r\
    \n\r\n  vc<int> color(2 * n, -1);\r\n  FOR(v, n) if (uf[v] == v && color[uf[v]]\
    \ < 0) {\r\n    color[uf[v]] = 0;\r\n    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v,\
    \ n) color[v] = color[uf[v]];\r\n  color.resize(n);\r\n  FOR(v, n) if (uf[v] ==\
    \ uf[v + n]) return {};\r\n  return color;\r\n}\r\n#line 3 \"flow/rank_maximal_bipartite_matching.hpp\"\
    \n\n// (N1, N2) bipartite graph with edge-weight 0, 1, ..., K - 1.\n// find a\
    \ matching s.t. (# of K-1, # of K-2, ...) is lex max.\n// https://yukicoder.me/problems/no/1615\n\
    // https://qoj.ac/contest/1388/problem/6546\n\ntemplate <typename GT>\nstruct\
    \ Rank_Maximal_Bipartite_Matching {\n  int N, K;\n  GT& G;\n  vc<int> color;\n\
    \  vc<int> dist, match;\n  vc<int> que;\n  vc<bool> vis;\n  vc<bool> vcover;\n\
    \n  // edge \u306E\u7BA1\u7406\n  // [L,M) : active, [M,R) : inactive\n  vc<pair<int,\
    \ int>> dat;\n  vc<int> LID, MID, RID;\n\n  Rank_Maximal_Bipartite_Matching(GT&\
    \ G) : N(G.N), G(G) {\n    color = bipartite_vertex_coloring(G);\n    if (N >\
    \ 0) assert(!color.empty());\n    dist.assign(N, -1), match.assign(N, -1);\n \
    \   que.assign(N, -1), vis.assign(N, -1);\n    vcover.assign(N, 0);\n    K = 0;\n\
    \    for (auto& e: G.edges) chmax(K, e.cost);\n    ++K;\n    build();\n    FOR_R(k,\
    \ K) solve(k);\n  }\n\n  void build() {\n    FOR(v, N) {\n      LID.eb(len(dat));\n\
    \      if (color[v] == 0) {\n        for (auto& e: G[v]) { dat.eb(e.to, e.cost);\
    \ }\n      }\n    }\n    LID.eb(len(dat));\n    MID.resize(N), RID.resize(N);\n\
    \    FOR(v, N) MID[v] = LID[v], RID[v] = LID[v + 1];\n  }\n\n  void solve(int\
    \ k) {\n    // weight k \u306E edge \u3092\u3000active \u306B\u3059\u308B\n  \
    \  FOR(v, N) {\n      if (vcover[v]) continue;\n      FOR(i, MID[v], RID[v]) {\n\
    \        auto [to, cost] = dat[i];\n        if (cost != k) continue;\n       \
    \ swap(dat[MID[v]], dat[i]), ++MID[v];\n      }\n    }\n    while (1) {\n    \
    \  bfs();\n      vis.assign(N, false);\n      int flow = 0;\n      FOR(v, N) if\
    \ (!color[v] && match[v] == -1 && dfs(v))++ flow;\n      if (!flow) break;\n \
    \   }\n\n    // update vertex cover\n    FOR(v, N) { vcover[v] = (color[v] ^ (dist[v]\
    \ == -1)); }\n    // active \u306A\u8FBA\u306E\u3046\u3061\u4E21\u7AEF\u70B9\u304C\
    \ vcover \u306B\u89E6\u308C\u3066\u3044\u308B\u3082\u306E\u3092\u524A\u9664\n\
    \    FOR(v, N) {\n      if (!vcover[v]) continue;\n      FOR_R(i, LID[v], MID[v])\
    \ {\n        auto [to, cost] = dat[i];\n        if (vcover[to]) {\n          swap(dat[i],\
    \ dat[MID[v] - 1]);\n          swap(dat[MID[v] - 1], dat[RID[v] - 1]);\n     \
    \     --MID[v], --RID[v];\n        }\n      }\n    }\n    // inactive \u306A\u8FBA\
    \u306E\u3046\u3061\u5C11\u306A\u304F\u3068\u3082\u4E00\u65B9\u304C vcover \u306B\
    \u89E6\u308C\u3066\u3044\u308B\u3082\u306E\u3092\u524A\u9664\n    FOR(v, N) {\n\
    \      if (vcover[v]) {\n        RID[v] = MID[v];\n        continue;\n      }\n\
    \      FOR_R(i, MID[v], RID[v]) {\n        auto [to, cost] = dat[i];\n       \
    \ if (vcover[to]) { swap(dat[i], dat[RID[v] - 1]), --RID[v]; }\n      }\n    }\n\
    \  }\n\n  void bfs() {\n    dist.assign(N, -1);\n    int ql = 0, qr = 0;\n   \
    \ FOR(v, N) if (!color[v] && match[v] == -1) que[qr++] = v, dist[v] = 0;\n   \
    \ while (ql < qr) {\n      int v = que[ql++];\n      FOR(i, LID[v], MID[v]) {\n\
    \        auto [to, cost] = dat[i];\n        dist[to] = 0;\n        int w = match[to];\n\
    \        if (w != -1 && dist[w] == -1) dist[w] = dist[v] + 1, que[qr++] = w;\n\
    \      }\n    }\n  }\n\n  bool dfs(int v) {\n    vis[v] = 1;\n    FOR(i, LID[v],\
    \ MID[v]) {\n      auto [to, cost] = dat[i];\n      int w = match[to];\n     \
    \ if (w == -1 || (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {\n        match[to]\
    \ = v, match[v] = to;\n        return true;\n      }\n    }\n    return false;\n\
    \  }\n\n  vc<int> get_matching_edges() {\n    vc<int> match_wt(N, -1);\n    vc<int>\
    \ match_e(N, -1);\n    for (auto& e: G.edges) {\n      int a = e.frm, b = e.to;\n\
    \      if (color[a]) swap(a, b);\n      if (match[a] == b && chmax(match_wt[a],\
    \ e.cost)) match_e[a] = e.id;\n    }\n    vc<int> res;\n    FOR(v, N) if (match_e[v]\
    \ != -1) res.eb(match_e[v]);\n    return res;\n  }\n};\n"
  code: "\n#include \"graph/bipartite_vertex_coloring.hpp\"\n\n// (N1, N2) bipartite\
    \ graph with edge-weight 0, 1, ..., K - 1.\n// find a matching s.t. (# of K-1,\
    \ # of K-2, ...) is lex max.\n// https://yukicoder.me/problems/no/1615\n// https://qoj.ac/contest/1388/problem/6546\n\
    \ntemplate <typename GT>\nstruct Rank_Maximal_Bipartite_Matching {\n  int N, K;\n\
    \  GT& G;\n  vc<int> color;\n  vc<int> dist, match;\n  vc<int> que;\n  vc<bool>\
    \ vis;\n  vc<bool> vcover;\n\n  // edge \u306E\u7BA1\u7406\n  // [L,M) : active,\
    \ [M,R) : inactive\n  vc<pair<int, int>> dat;\n  vc<int> LID, MID, RID;\n\n  Rank_Maximal_Bipartite_Matching(GT&\
    \ G) : N(G.N), G(G) {\n    color = bipartite_vertex_coloring(G);\n    if (N >\
    \ 0) assert(!color.empty());\n    dist.assign(N, -1), match.assign(N, -1);\n \
    \   que.assign(N, -1), vis.assign(N, -1);\n    vcover.assign(N, 0);\n    K = 0;\n\
    \    for (auto& e: G.edges) chmax(K, e.cost);\n    ++K;\n    build();\n    FOR_R(k,\
    \ K) solve(k);\n  }\n\n  void build() {\n    FOR(v, N) {\n      LID.eb(len(dat));\n\
    \      if (color[v] == 0) {\n        for (auto& e: G[v]) { dat.eb(e.to, e.cost);\
    \ }\n      }\n    }\n    LID.eb(len(dat));\n    MID.resize(N), RID.resize(N);\n\
    \    FOR(v, N) MID[v] = LID[v], RID[v] = LID[v + 1];\n  }\n\n  void solve(int\
    \ k) {\n    // weight k \u306E edge \u3092\u3000active \u306B\u3059\u308B\n  \
    \  FOR(v, N) {\n      if (vcover[v]) continue;\n      FOR(i, MID[v], RID[v]) {\n\
    \        auto [to, cost] = dat[i];\n        if (cost != k) continue;\n       \
    \ swap(dat[MID[v]], dat[i]), ++MID[v];\n      }\n    }\n    while (1) {\n    \
    \  bfs();\n      vis.assign(N, false);\n      int flow = 0;\n      FOR(v, N) if\
    \ (!color[v] && match[v] == -1 && dfs(v))++ flow;\n      if (!flow) break;\n \
    \   }\n\n    // update vertex cover\n    FOR(v, N) { vcover[v] = (color[v] ^ (dist[v]\
    \ == -1)); }\n    // active \u306A\u8FBA\u306E\u3046\u3061\u4E21\u7AEF\u70B9\u304C\
    \ vcover \u306B\u89E6\u308C\u3066\u3044\u308B\u3082\u306E\u3092\u524A\u9664\n\
    \    FOR(v, N) {\n      if (!vcover[v]) continue;\n      FOR_R(i, LID[v], MID[v])\
    \ {\n        auto [to, cost] = dat[i];\n        if (vcover[to]) {\n          swap(dat[i],\
    \ dat[MID[v] - 1]);\n          swap(dat[MID[v] - 1], dat[RID[v] - 1]);\n     \
    \     --MID[v], --RID[v];\n        }\n      }\n    }\n    // inactive \u306A\u8FBA\
    \u306E\u3046\u3061\u5C11\u306A\u304F\u3068\u3082\u4E00\u65B9\u304C vcover \u306B\
    \u89E6\u308C\u3066\u3044\u308B\u3082\u306E\u3092\u524A\u9664\n    FOR(v, N) {\n\
    \      if (vcover[v]) {\n        RID[v] = MID[v];\n        continue;\n      }\n\
    \      FOR_R(i, MID[v], RID[v]) {\n        auto [to, cost] = dat[i];\n       \
    \ if (vcover[to]) { swap(dat[i], dat[RID[v] - 1]), --RID[v]; }\n      }\n    }\n\
    \  }\n\n  void bfs() {\n    dist.assign(N, -1);\n    int ql = 0, qr = 0;\n   \
    \ FOR(v, N) if (!color[v] && match[v] == -1) que[qr++] = v, dist[v] = 0;\n   \
    \ while (ql < qr) {\n      int v = que[ql++];\n      FOR(i, LID[v], MID[v]) {\n\
    \        auto [to, cost] = dat[i];\n        dist[to] = 0;\n        int w = match[to];\n\
    \        if (w != -1 && dist[w] == -1) dist[w] = dist[v] + 1, que[qr++] = w;\n\
    \      }\n    }\n  }\n\n  bool dfs(int v) {\n    vis[v] = 1;\n    FOR(i, LID[v],\
    \ MID[v]) {\n      auto [to, cost] = dat[i];\n      int w = match[to];\n     \
    \ if (w == -1 || (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {\n        match[to]\
    \ = v, match[v] = to;\n        return true;\n      }\n    }\n    return false;\n\
    \  }\n\n  vc<int> get_matching_edges() {\n    vc<int> match_wt(N, -1);\n    vc<int>\
    \ match_e(N, -1);\n    for (auto& e: G.edges) {\n      int a = e.frm, b = e.to;\n\
    \      if (color[a]) swap(a, b);\n      if (match[a] == b && chmax(match_wt[a],\
    \ e.cost)) match_e[a] = e.id;\n    }\n    vc<int> res;\n    FOR(v, N) if (match_e[v]\
    \ != -1) res.eb(match_e[v]);\n    return res;\n  }\n};\n"
  dependsOn:
  - graph/bipartite_vertex_coloring.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: flow/rank_maximal_bipartite_matching.hpp
  requiredBy: []
  timestamp: '2025-04-06 22:14:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1615.test.cpp
documentation_of: flow/rank_maximal_bipartite_matching.hpp
layout: document
redirect_from:
- /library/flow/rank_maximal_bipartite_matching.hpp
- /library/flow/rank_maximal_bipartite_matching.hpp.html
title: flow/rank_maximal_bipartite_matching.hpp
---
