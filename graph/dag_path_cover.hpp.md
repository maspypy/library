---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind.hpp
    title: ds/unionfind.hpp
  - icon: ':question:'
    path: flow/bipartite.hpp
    title: flow/bipartite.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/check_bipartite.hpp
    title: graph/check_bipartite.hpp
  - icon: ':heavy_check_mark:'
    path: graph/degree.hpp
    title: graph/degree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/toposort.hpp
    title: graph/toposort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_dag_path_cover.test.cpp
    title: test/aoj/2251_dag_path_cover.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <=\
    \ to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost,\
    \ i});\n    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool\
    \ wt = false, int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int\
    \ M, bool wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n    \
    \  INT(a, b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n\
    \      } else {\n        T c;\n        read(c);\n        add(a, b, c);\n     \
    \ }\n    }\n    build();\n  }\n\n  void read_parent(int off = 1) {\n    for (int\
    \ v = N - 1; v >= 1; --v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n\
    \    }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared\
    \ = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0;\
    \ v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto counter = indptr;\n  \
    \  csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++]\
    \ = e;\n      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const\
    \ {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\
    \n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n};\n#line 2 \"ds/unionfind.hpp\"\n\nstruct UnionFind {\n  int n;\n\
    \  int n_comp;\n  std::vector<int> size, par;\n  UnionFind(int n) : n(n), n_comp(n),\
    \ size(n, 1), par(n) {\n    std::iota(par.begin(), par.end(), 0);\n  }\n  int\
    \ find(int x) {\n    assert(0 <= x && x < n);\n    while (par[x] != x) {\n   \
    \   par[x] = par[par[x]];\n      x = par[x];\n    }\n    return x;\n  }\n\n  int\
    \ operator[](int x) { return find(x); }\n\n  bool merge(int x, int y) {\n    x\
    \ = find(x);\n    y = find(y);\n    if (x == y) { return false; }\n    n_comp--;\n\
    \    if (size[x] < size[y]) std::swap(x, y);\n    size[x] += size[y];\n    size[y]\
    \ = 0;\n    par[y] = x;\n    return true;\n  }\n\n  std::vector<int> find_all()\
    \ {\n    std::vector<int> A(n);\n    for (int i = 0; i < n; ++i) A[i] = find(i);\n\
    \    return A;\n  }\n\n  void reset() {\n    n_comp = n;\n    size.assign(n, 1);\n\
    \    std::iota(par.begin(), par.end(), 0);\n  }\n};\n#line 3 \"graph/check_bipartite.hpp\"\
    \n\r\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A + \u5FA9\u5143\r\n// \u4E8C\
    \u90E8\u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\u306F\
    \ empty\r\ntemplate <typename Graph>\r\nvc<int> check_bipartite(Graph& G) {\r\n\
    \  assert(G.is_prepared());\r\n\r\n  int n = G.N;\r\n  UnionFind uf(2 * n);\r\n\
    \  for (auto&& e: G.edges) {\r\n    int u = e.frm, v = e.to;\r\n    if (e.cost\
    \ == 0) uf.merge(u, v), uf.merge(u + n, v + n);\r\n    if (e.cost != 0) uf.merge(u\
    \ + n, v), uf.merge(u, v + n);\r\n  }\r\n\r\n  vc<int> color(2 * n, -1);\r\n \
    \ FOR(v, n) if (uf[v] == v && color[uf[v]] < 0) {\r\n    color[uf[v]] = 0;\r\n\
    \    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v, n) color[v] = color[uf[v]];\r\n\
    \  color.resize(n);\r\n  FOR(v, n) if (uf[v] == uf[v + n]) return {};\r\n  return\
    \ color;\r\n}\r\n#line 3 \"flow/bipartite.hpp\"\n\r\ntemplate <typename Graph>\r\
    \nstruct BipartiteMatching {\r\n  int N;\r\n  Graph& G;\r\n  vc<int> color;\r\n\
    \  vc<int> dist, match;\r\n  vc<int> vis;\r\n\r\n  BipartiteMatching(Graph& G)\
    \ : G(G), N(G.N), dist(G.N, -1), match(G.N, -1) {\r\n    color = check_bipartite(G);\r\
    \n    assert(!color.empty());\r\n    while (1) {\r\n      bfs();\r\n      vis.assign(N,\
    \ false);\r\n      int flow = 0;\r\n      FOR(v, N) if (!color[v] && match[v]\
    \ == -1 && dfs(v))++ flow;\r\n      if (!flow) break;\r\n    }\r\n  }\r\n\r\n\
    \  void bfs() {\r\n    dist.assign(N, -1);\r\n    queue<int> que;\r\n    FOR(v,\
    \ N) if (!color[v] && match[v] == -1) que.emplace(v), dist[v] = 0;\r\n    while\
    \ (!que.empty()) {\r\n      int v = que.front();\r\n      que.pop();\r\n     \
    \ for (auto&& e: G[v]) {\r\n        dist[e.to] = 0;\r\n        int w = match[e.to];\r\
    \n        if (w != -1 && dist[w] == -1) dist[w] = dist[v] + 1, que.emplace(w);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  bool dfs(int v) {\r\n    vis[v] = 1;\r\n  \
    \  for (auto&& e: G[v]) {\r\n      int w = match[e.to];\r\n      if (w == -1 ||\
    \ (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {\r\n        match[e.to] = v,\
    \ match[v] = e.to;\r\n        return true;\r\n      }\r\n    }\r\n    return false;\r\
    \n  }\r\n\r\n  vc<pair<int, int>> matching() {\r\n    vc<pair<int, int>> res;\r\
    \n    FOR(v, N) if (v < match[v]) res.eb(v, match[v]);\r\n    return res;\r\n\
    \  }\r\n\r\n  vc<int> vertex_cover() {\r\n    vc<int> res;\r\n    FOR(v, N) if\
    \ (color[v] ^ (dist[v] == -1)) {\r\n      res.eb(v);\r\n    }\r\n    return res;\r\
    \n  }\r\n\r\n  vc<int> independent_set() {\r\n    vc<int> res;\r\n    FOR(v, N)\
    \ if (!(color[v] ^ (dist[v] == -1))) {\r\n      res.eb(v);\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  vc<int> edge_cover() {\r\n    vc<bool> done(N);\r\n   \
    \ vc<int> res;\r\n    for (auto&& e: G.edges) {\r\n      if (done[e.frm] || done[e.to])\
    \ continue;\r\n      if (match[e.frm] == e.to) {\r\n        res.eb(e.id);\r\n\
    \        done[e.frm] = done[e.to] = 1;\r\n      }\r\n    }\r\n    for (auto&&\
    \ e: G.edges) {\r\n      if (!done[e.frm]) {\r\n        res.eb(e.id);\r\n    \
    \    done[e.frm] = 1;\r\n      }\r\n      if (!done[e.to]) {\r\n        res.eb(e.id);\r\
    \n        done[e.to] = 1;\r\n      }\r\n    }\r\n    sort(all(res));\r\n    return\
    \ res;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"match\", match);\r\n    print(\"\
    min vertex covor\", vertex_cover());\r\n    print(\"max indep set\", independent_set());\r\
    \n    print(\"min edge cover\", edge_cover());\r\n  }\r\n};\n#line 2 \"graph/degree.hpp\"\
    \n\r\ntemplate <typename Graph>\r\nvector<int> degree(Graph& G) {\r\n  vector<int>\
    \ deg(G.N);\r\n  for(auto&& e : G.edges) deg[e.frm]++, deg[e.to]++;\r\n  return\
    \ deg;\r\n}\r\n\r\ntemplate <typename Graph>\r\npair<vector<int>, vector<int>>\
    \ degree_inout(Graph& G) {\r\n  vector<int> indeg(G.N), outdeg(G.N);\r\n  for\
    \ (auto&& e: G.edges) { indeg[e.to]++, outdeg[e.frm]++; }\r\n  return {indeg,\
    \ outdeg};\r\n}\r\n#line 3 \"graph/toposort.hpp\"\n\n// DAG \u3058\u3083\u306A\
    \u304B\u3063\u305F\u3089\u7A7A\u914D\u5217\n// \u8F9E\u66F8\u9806\u6700\u5C0F\u3082\
    \u3067\u304D\u308B\uFF1AO(NlogN) \u2192 abc223\ntemplate <typename Graph>\nvc<int>\
    \ toposort(Graph& G, bool lex_min = false) {\n  assert(G.is_prepared());\n  assert(G.is_directed());\n\
    \  auto [indeg, outdeg] = degree_inout(G);\n  if (!lex_min) {\n    vc<int> V;\n\
    \    ll N = G.N;\n    FOR(v, N) if (indeg[v] == 0) V.eb(v);\n    ll p = 0;\n \
    \   while (p < len(V)) {\n      auto v = V[p++];\n      for (auto&& e: G[v]) {\n\
    \        if (--indeg[e.to] == 0) V.eb(e.to);\n      }\n    }\n    if (len(V) <\
    \ N) { V.clear(); }\n    return V;\n  } else {\n    pqg<int> que;\n    vc<int>\
    \ V;\n    ll N = G.N;\n    FOR(v, N) if (indeg[v] == 0) que.push(v);\n    while\
    \ (len(que)) {\n      auto v = que.top();\n      que.pop();\n      V.eb(v);\n\
    \      for (auto&& e: G[v]) {\n        if (--indeg[e.to] == 0) que.push(e.to);\n\
    \      }\n    }\n    if (len(V) < N) { V.clear(); }\n    return V;\n  }\n}\n\n\
    // https://codeforces.com/contest/798/problem/E\n// toposort \u306E\u5019\u88DC\
    \u3092\u3072\u3068\u3064\u51FA\u529B\u3059\u308B\u3002\u30C1\u30A7\u30C3\u30AF\
    \u306F\u3057\u306A\u3044\u3002\n// \u967D\u306B\u30B0\u30E9\u30D5\u3092\u4F5C\u3089\
    \u305A\u3001\u4F55\u3089\u304B\u306E\u30C7\u30FC\u30BF\u69CB\u9020\u3067\u672A\
    \u8A2A\u554F\u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u60F3\u5B9A\u3002\n// set_used(v)\uFF1A\
    v \u3092\u4F7F\u7528\u6E08\u306B\u5909\u66F4\u3059\u308B\n// find_unused(v)\uFF1A\
    v \u306E\u884C\u304D\u5148\u3092\u63A2\u3059\u3002\u306A\u3051\u308C\u3070 -1\
    \ \u3092\u8FD4\u3059\u3053\u3068\u3002\ntemplate <typename F1, typename F2>\n\
    vc<int> toposort(int N, F1 set_used, F2 find_unused) {\n  vc<int> V;\n  vc<bool>\
    \ done(N);\n  auto dfs = [&](auto self, ll v) -> void {\n    set_used(v);\n  \
    \  done[v] = 1;\n    while (1) {\n      int to = find_unused(v);\n      if (to\
    \ == -1) break;\n      self(self, to);\n    }\n    V.eb(v);\n  };\n  FOR(v, N)\
    \ if (!done[v]) dfs(dfs, v);\n  return V;\n}\n#line 3 \"graph/dag_path_cover.hpp\"\
    \n\n// path \uFF08\u9802\u70B9\u5217\uFF09\u306E vector \u3092\u8FD4\u3059 O(m\
    \ sqrt(n))\ntemplate <typename DAG>\nvc<vc<int>> dag_path_cover(DAG& G) {\n  assert(G.is_directed());\n\
    \  int n = G.N;\n  auto V = toposort(G);\n  vc<int> idx(n);\n  FOR(i, n) idx[V[i]]\
    \ = i;\n\n  // check dag\n  for (auto&& e: G.edges) assert(idx[e.frm] < idx[e.to]);\n\
    \n  Graph H(n + n);\n  for (auto&& e: G.edges) { H.add(e.frm, e.to + n); }\n \
    \ H.build();\n  BipartiteMatching BM(H);\n  auto match = BM.matching();\n  vc<int>\
    \ nxt(n, -1);\n  for (auto&& [a, b]: match) {\n    if (a > b) swap(a, b);\n  \
    \  nxt[a] = b - n;\n  }\n\n  vc<bool> done(n);\n\n  vvc<int> paths;\n  for (auto&&\
    \ v: V) {\n    if (done[v]) continue;\n    vc<int> P = {v};\n    while (1) {\n\
    \      int w = nxt[P.back()];\n      if (w == -1) break;\n      P.eb(w);\n   \
    \ }\n    for (auto&& x: P) done[x] = 1;\n    paths.eb(P);\n  }\n  return paths;\n\
    };\n"
  code: "#include \"flow/bipartite.hpp\"\n#include \"graph/toposort.hpp\"\n\n// path\
    \ \uFF08\u9802\u70B9\u5217\uFF09\u306E vector \u3092\u8FD4\u3059 O(m sqrt(n))\n\
    template <typename DAG>\nvc<vc<int>> dag_path_cover(DAG& G) {\n  assert(G.is_directed());\n\
    \  int n = G.N;\n  auto V = toposort(G);\n  vc<int> idx(n);\n  FOR(i, n) idx[V[i]]\
    \ = i;\n\n  // check dag\n  for (auto&& e: G.edges) assert(idx[e.frm] < idx[e.to]);\n\
    \n  Graph H(n + n);\n  for (auto&& e: G.edges) { H.add(e.frm, e.to + n); }\n \
    \ H.build();\n  BipartiteMatching BM(H);\n  auto match = BM.matching();\n  vc<int>\
    \ nxt(n, -1);\n  for (auto&& [a, b]: match) {\n    if (a > b) swap(a, b);\n  \
    \  nxt[a] = b - n;\n  }\n\n  vc<bool> done(n);\n\n  vvc<int> paths;\n  for (auto&&\
    \ v: V) {\n    if (done[v]) continue;\n    vc<int> P = {v};\n    while (1) {\n\
    \      int w = nxt[P.back()];\n      if (w == -1) break;\n      P.eb(w);\n   \
    \ }\n    for (auto&& x: P) done[x] = 1;\n    paths.eb(P);\n  }\n  return paths;\n\
    };"
  dependsOn:
  - flow/bipartite.hpp
  - graph/base.hpp
  - graph/check_bipartite.hpp
  - ds/unionfind.hpp
  - graph/toposort.hpp
  - graph/degree.hpp
  isVerificationFile: false
  path: graph/dag_path_cover.hpp
  requiredBy: []
  timestamp: '2022-08-11 02:13:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2251_dag_path_cover.test.cpp
documentation_of: graph/dag_path_cover.hpp
layout: document
redirect_from:
- /library/graph/dag_path_cover.hpp
- /library/graph/dag_path_cover.hpp.html
title: graph/dag_path_cover.hpp
---
