---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1254.test.cpp
    title: test/yukicoder/1254.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc266f.test.cpp
    title: test_atcoder/abc266f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost\
    \ = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to &&\
    \ to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n\
    \    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n\n  void read_parent(int off = 1) {\n    for (int v\
    \ = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n    }\n\
    \    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared =\
    \ true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0;\
    \ v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto counter = indptr;\n  \
    \  csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++]\
    \ = e;\n      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const\
    \ {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\
    \n  vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  // G \u306B\u304A\u3051\u308B\
    \u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\
    \u306A\u308B\u3088\u3046\u306B\u3059\u308B\n  Graph<T, directed> rearrange(vc<int>\
    \ V) {\n    int n = len(V);\n    map<int, int> MP;\n    FOR(i, n) MP[V[i]] = i;\n\
    \    Graph<T, directed> G(n);\n    for (auto&& e: edges) {\n      if (MP.count(e.frm)\
    \ && MP.count(e.to)) {\n        G.add(MP[e.frm], MP[e.to], e.cost);\n      }\n\
    \    }\n    G.build();\n    return G;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\
    \r\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\u7D50\u3067\u3082 dfs \u9806\u5E8F\
    \u3084\u89AA\u304C\u3068\u308C\u308B\u3002\r\ntemplate <typename GT>\r\nstruct\
    \ Tree {\r\n  using Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\
    \n  int N;\r\n  bool hld;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n\
    \  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int r = -1,\
    \ bool hld = 1)\r\n      : G(G),\r\n        N(G.N),\r\n        hld(hld),\r\n \
    \       LID(G.N),\r\n        RID(G.N),\r\n        head(G.N, r),\r\n        V(G.N),\r\
    \n        parent(G.N, -1),\r\n        VtoE(G.N, -1),\r\n        depth(G.N, -1),\r\
    \n        depth_weighted(G.N, 0) {\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    if (r != -1) {\r\n      dfs_sz(r, -1);\r\n      dfs_hld(r, t1);\r\
    \n    } else {\r\n      for (int r = 0; r < N; ++r) {\r\n        if (parent[r]\
    \ == -1) {\r\n          head[r] = r;\r\n          dfs_sz(r, -1);\r\n         \
    \ dfs_hld(r, t1);\r\n        }\r\n      }\r\n    }\r\n  }\r\n\r\n  void dfs_sz(int\
    \ v, int p) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p\
    \ == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r =\
    \ G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    // \u4F7F\u3046\u8FBA\
    \u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n    for (int i = r -\
    \ 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i],\
    \ csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i)\
    \ {\r\n      auto e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n  \
    \    depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\n      VtoE[e.to] =\
    \ e.id;\r\n      dfs_sz(e.to, v);\r\n      sz[v] += sz[e.to];\r\n      if (hld\
    \ && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n\
    \  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\n \
    \   RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n    for\
    \ (auto &&e: G[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\n     \
    \ head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n      dfs_hld(e.to,\
    \ times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v) {\r\n    vc<int>\
    \ P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n      for (auto &&e:\
    \ G[a]) {\r\n        if (e.to != parent[a] && head[e.to] == v) {\r\n         \
    \ P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\n      if (P.back()\
    \ == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int e_to_v(int eid) {\r\
    \n    auto e = G.edges[eid];\r\n    return (parent[e.frm] == e.to ? e.frm : e.to);\r\
    \n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\n\r\n  int ELID(int v) { return\
    \ 2 * LID[v] - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v]\
    \ - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int v, int k) {\r\n    assert(k\
    \ <= depth[v]);\r\n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v]\
    \ - k >= LID[u]) return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n\
    \      v = parent[u];\r\n    }\r\n  }\r\n\r\n  int LCA(int u, int v) {\r\n   \
    \ for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\n\
    \      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int lca(int\
    \ u, int v) { return LCA(u, v); }\r\n  int la(int u, int v) { return LA(u, v);\
    \ }\r\n\r\n  int subtree_size(int v) { return RID[v] - LID[v]; }\r\n\r\n  int\
    \ dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] + depth[b]\
    \ - 2 * depth[c];\r\n  }\r\n\r\n  WT dist(int a, int b, bool weighted) {\r\n \
    \   assert(weighted);\r\n    int c = LCA(a, b);\r\n    return depth_weighted[a]\
    \ + depth_weighted[b] - WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in\
    \ b\r\n  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b];\
    \ }\r\n\r\n  int jump(int a, int b, ll k) {\r\n    if (k == 1) {\r\n      if (a\
    \ == b) return -1;\r\n      return (in_subtree(b, a) ? LA(b, depth[b] - depth[a]\
    \ - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a, b);\r\n    int d_ac = depth[a]\
    \ - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\n    if (k > d_ac + d_bc)\
    \ return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\n    return LA(b, d_ac +\
    \ d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\
    \n    for (auto &&e: G[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n \
    \   return res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int\
    \ u, int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\
    \"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1)\
    \ {\r\n      if (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n\
    \        down.eb(LID[head[v]], LID[v]);\r\n        v = parent[head[v]];\r\n  \
    \    } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\n        u = parent[head[u]];\r\
    \n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\
    \n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\
    \n    up.insert(up.end(), all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int>\
    \ restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n};\r\n#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct\
    \ UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int\
    \ n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n,\
    \ -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n   \
    \ while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return\
    \ dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int\
    \ x) {\n    assert(dat[x] < 0);\n    return -dat[x];\n  }\n\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n};\n#line 4 \"graph/unicyclic.hpp\"\n\ntemplate <typename\
    \ GT, bool DIRECTED = true>\nstruct UnicyclicGraph {\n  using T = typename GT::cost_type;\n\
    \  GT& G0;\n  Graph<T, DIRECTED> G;\n  int N;\n  int root;\n  int out_eid;\n \
    \ vc<int> TO;\n  vc<int> cycle;     // \u6839\u306B\u5411\u304B\u3046\u3088\u3046\
    \u306A\u9802\u70B9\u5217\n  vc<bool> in_cycle; // vertex id -> bool\n\n  UnicyclicGraph(GT&\
    \ G) : G0(G), N(G.N) {\n    assert(!G.is_directed() && N == G.M);\n    UnionFind\
    \ uf(N);\n    TO.assign(N, -1);\n    FOR(eid, N) {\n      auto& e = G.edges[eid];\n\
    \      if (uf.merge(e.frm, e.to)) continue;\n      out_eid = eid;\n      root\
    \ = e.frm;\n      TO[root] = e.to;\n      break;\n    }\n    vc<bool> done(N);\n\
    \    vc<int> que = {root};\n    while (len(que)) {\n      int v = POP(que);\n\
    \      done[v] = 1;\n      for (auto&& e: G[v]) {\n        if (done[e.to] || e.id\
    \ == out_eid) continue;\n        TO[e.to] = v;\n        que.eb(e.to);\n      }\n\
    \    }\n    cycle = {TO[root]};\n    while (cycle.back() != root) cycle.eb(TO[cycle.back()]);\n\
    \    in_cycle.assign(N, 0);\n    for (auto&& v: cycle) in_cycle[v] = 1;\n  }\n\
    \n  // tree \u3092\u4F5C\u308B\n  Tree<decltype(G)> build(bool keep_eid = false)\
    \ {\n    G.resize(N);\n    FOR(eid, N) {\n      if (eid == out_eid) continue;\n\
    \      auto& e = G0.edges[eid];\n      int a = e.frm, b = e.to;\n      if (TO[a]\
    \ == b) swap(a, b);\n      assert(TO[b] == a);\n      int k = (keep_eid ? eid\
    \ : -1);\n      G.add(a, b, e.cost, k);\n    }\n    G.build();\n    return Tree<decltype(G)>(G,\
    \ root);\n  };\n};\n"
  code: "#include \"graph/base.hpp\"\n#include \"graph/tree.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\
    \n\ntemplate <typename GT, bool DIRECTED = true>\nstruct UnicyclicGraph {\n  using\
    \ T = typename GT::cost_type;\n  GT& G0;\n  Graph<T, DIRECTED> G;\n  int N;\n\
    \  int root;\n  int out_eid;\n  vc<int> TO;\n  vc<int> cycle;     // \u6839\u306B\
    \u5411\u304B\u3046\u3088\u3046\u306A\u9802\u70B9\u5217\n  vc<bool> in_cycle; //\
    \ vertex id -> bool\n\n  UnicyclicGraph(GT& G) : G0(G), N(G.N) {\n    assert(!G.is_directed()\
    \ && N == G.M);\n    UnionFind uf(N);\n    TO.assign(N, -1);\n    FOR(eid, N)\
    \ {\n      auto& e = G.edges[eid];\n      if (uf.merge(e.frm, e.to)) continue;\n\
    \      out_eid = eid;\n      root = e.frm;\n      TO[root] = e.to;\n      break;\n\
    \    }\n    vc<bool> done(N);\n    vc<int> que = {root};\n    while (len(que))\
    \ {\n      int v = POP(que);\n      done[v] = 1;\n      for (auto&& e: G[v]) {\n\
    \        if (done[e.to] || e.id == out_eid) continue;\n        TO[e.to] = v;\n\
    \        que.eb(e.to);\n      }\n    }\n    cycle = {TO[root]};\n    while (cycle.back()\
    \ != root) cycle.eb(TO[cycle.back()]);\n    in_cycle.assign(N, 0);\n    for (auto&&\
    \ v: cycle) in_cycle[v] = 1;\n  }\n\n  // tree \u3092\u4F5C\u308B\n  Tree<decltype(G)>\
    \ build(bool keep_eid = false) {\n    G.resize(N);\n    FOR(eid, N) {\n      if\
    \ (eid == out_eid) continue;\n      auto& e = G0.edges[eid];\n      int a = e.frm,\
    \ b = e.to;\n      if (TO[a] == b) swap(a, b);\n      assert(TO[b] == a);\n  \
    \    int k = (keep_eid ? eid : -1);\n      G.add(a, b, e.cost, k);\n    }\n  \
    \  G.build();\n    return Tree<decltype(G)>(G, root);\n  };\n};"
  dependsOn:
  - graph/base.hpp
  - graph/tree.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/unicyclic.hpp
  requiredBy: []
  timestamp: '2023-04-02 05:22:15+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc266f.test.cpp
  - test/yukicoder/1254.test.cpp
documentation_of: graph/unicyclic.hpp
layout: document
redirect_from:
- /library/graph/unicyclic.hpp
- /library/graph/unicyclic.hpp.html
title: graph/unicyclic.hpp
---
