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
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_maxantichain.test.cpp
    title: test/aoj/2251_maxantichain.test.cpp
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
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    int l, r;\n    const\
    \ Graph* G;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void add(int frm, int to, T\
    \ cost = 1, int i = -1) {\n    assert(!prepared && 0 <= frm && 0 <= to && to <\
    \ N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n\
    \    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    FOR(M) {\n      INT(a, b);\n      a -= off,\
    \ b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n\
    \        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n\
    \  void read_parent(int off = 1) {\n    FOR3(v, 1, N) {\n      INT(p);\n     \
    \ p -= off;\n      add(p, v);\n    }\n    build();\n  }\n\n  void build() {\n\
    \    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 2 \"ds/unionfind.hpp\"\
    \n\nstruct UnionFind {\n  int num;\n  int comp;\n  vc<int> size, par;\n  UnionFind(int\
    \ n) : num(n), comp(n), size(n, 1), par(n) {\n    iota(par.begin(), par.end(),\
    \ 0);\n  }\n  int find(int x) {\n    while (par[x] != x) {\n      par[x] = par[par[x]];\n\
    \      x = par[x];\n    }\n    return x;\n  }\n\n  int operator[](int x) { return\
    \ find(x); }\n\n  bool merge(ll x, ll y) {\n    x = find(x);\n    y = find(y);\n\
    \    if (x == y) { return false; }\n    comp--;\n    if (size[x] < size[y]) swap(x,\
    \ y);\n    size[x] += size[y];\n    size[y] = 0;\n    par[y] = x;\n    return\
    \ true;\n  }\n\n  vc<int> find_all() {\n    vc<int> A(num);\n    FOR(i, num) A[i]\
    \ = find(i);\n    return A;\n  }\n\n  void reset(){\n    comp = num;\n    size.assign(num,\
    \ 1);\n    iota(all(par), 0);\n  }\n};\n#line 3 \"graph/check_bipartite.hpp\"\n\
    \r\n// \u4E8C\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A + \u5FA9\u5143\r\n// \u4E8C\u90E8\
    \u30B0\u30E9\u30D5\u3067\u306A\u304B\u3063\u305F\u5834\u5408\u306B\u306F empty\r\
    \ntemplate <typename Graph>\r\nvc<int> check_bipartite(Graph& G) {\r\n  assert(G.is_prepared());\r\
    \n\r\n  int n = G.N;\r\n  UnionFind uf(2 * n);\r\n  for (auto&& e: G.edges) {\r\
    \n    int u = e.frm, v = e.to;\r\n    if (e.cost == 0) uf.merge(u, v), uf.merge(u\
    \ + n, v + n);\r\n    if (e.cost != 0) uf.merge(u + n, v), uf.merge(u, v + n);\r\
    \n  }\r\n\r\n  vc<int> color(2 * n, -1);\r\n  FOR(v, n) if (uf[v] == v && color[uf[v]]\
    \ < 0) {\r\n    color[uf[v]] = 0;\r\n    color[uf[v + n]] = 1;\r\n  }\r\n  FOR(v,\
    \ n) color[v] = color[uf[v]];\r\n  color.resize(n);\r\n  FOR(v, n) if (uf[v] ==\
    \ uf[v + n]) return {};\r\n  return color;\r\n}\r\n#line 3 \"flow/bipartite.hpp\"\
    \n\r\ntemplate <typename Graph>\r\nstruct BipartiteMatching {\r\n  int N;\r\n\
    \  Graph& G;\r\n  vc<int> color;\r\n  vc<int> dist, match;\r\n  vc<int> vis;\r\
    \n\r\n  BipartiteMatching(Graph& G) : G(G), N(G.N), dist(G.N, -1), match(G.N,\
    \ -1) {\r\n    color = check_bipartite(G);\r\n    assert(!color.empty());\r\n\
    \    while (1) {\r\n      bfs();\r\n      vis.assign(N, false);\r\n      int flow\
    \ = 0;\r\n      FOR(v, N) if (!color[v] && match[v] == -1 && dfs(v))++ flow;\r\
    \n      if (!flow) break;\r\n    }\r\n  }\r\n\r\n  void bfs() {\r\n    dist.assign(N,\
    \ -1);\r\n    queue<int> que;\r\n    FOR(v, N) if (!color[v] && match[v] == -1)\
    \ que.emplace(v), dist[v] = 0;\r\n    while (!que.empty()) {\r\n      int v =\
    \ que.front();\r\n      que.pop();\r\n      for (auto&& e: G[v]) {\r\n       \
    \ dist[e.to] = 0;\r\n        int w = match[e.to];\r\n        if (w != -1 && dist[w]\
    \ == -1) dist[w] = dist[v] + 1, que.emplace(w);\r\n      }\r\n    }\r\n  }\r\n\
    \r\n  bool dfs(int v) {\r\n    vis[v] = 1;\r\n    for (auto&& e: G[v]) {\r\n \
    \     int w = match[e.to];\r\n      if (w == -1 || (!vis[w] && dist[w] == dist[v]\
    \ + 1 && dfs(w))) {\r\n        match[e.to] = v, match[v] = e.to;\r\n        return\
    \ true;\r\n      }\r\n    }\r\n    return false;\r\n  }\r\n\r\n  vc<pair<int,\
    \ int>> matching() {\r\n    vc<pair<int, int>> res;\r\n    FOR(v, N) if (v < match[v])\
    \ res.eb(v, match[v]);\r\n    return res;\r\n  }\r\n\r\n  vc<int> vertex_cover()\
    \ {\r\n    vc<int> res;\r\n    FOR(v, N) if (color[v] ^ (dist[v] == -1)) {\r\n\
    \      res.eb(v);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  vc<int> independent_set()\
    \ {\r\n    vc<int> res;\r\n    FOR(v, N) if (!(color[v] ^ (dist[v] == -1))) {\r\
    \n      res.eb(v);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  vc<int> edge_cover()\
    \ {\r\n    vc<bool> done(N);\r\n    vc<int> res;\r\n    for (auto&& e: G.edges)\
    \ {\r\n      if (done[e.frm] || done[e.to]) continue;\r\n      if (match[e.frm]\
    \ == e.to) {\r\n        res.eb(e.id);\r\n        done[e.frm] = done[e.to] = 1;\r\
    \n      }\r\n    }\r\n    for (auto&& e: G.edges) {\r\n      if (!done[e.frm])\
    \ {\r\n        res.eb(e.id);\r\n        done[e.frm] = 1;\r\n      }\r\n      if\
    \ (!done[e.to]) {\r\n        res.eb(e.id);\r\n        done[e.to] = 1;\r\n    \
    \  }\r\n    }\r\n    sort(all(res));\r\n    return res;\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    print(\"match\", match);\r\n    print(\"min vertex covor\", vertex_cover());\r\
    \n    print(\"max indep set\", independent_set());\r\n    print(\"min edge cover\"\
    , edge_cover());\r\n  }\r\n};\n#line 2 \"graph/maximum_antichain.hpp\"\n\n// \u6BD4\
    \u8F03\u53EF\u80FD\u30B0\u30E9\u30D5\u3092\u4E0E\u3048\u308B\u3002DAG \u306A\u3060\
    \u3051\u3067\u306F\u30C0\u30E1\u3002\ntemplate <typename T>\nvc<int> maximum_antichain(T&\
    \ G) {\n  assert(G.is_directed());\n  int n = G.N;\n\n  Graph H(n + n);\n  for\
    \ (auto&& e: G.edges) { H.add(e.frm, e.to + n); }\n  H.build();\n  BipartiteMatching\
    \ BM(H);\n  auto cover = BM.vertex_cover();\n  auto match = BM.matching();\n \
    \ assert(len(cover) == len(match));\n  vc<bool> ok(n, 1);\n  for (auto&& v: cover)\
    \ { ok[v % n] = 0; }\n  vc<int> antichain;\n  FOR(v, n) if (ok[v]) antichain.eb(v);\n\
    \  for (auto&& e: G.edges) { assert(!ok[e.frm] || !ok[e.to]); }\n  return antichain;\n\
    }\n"
  code: "#include \"flow/bipartite.hpp\"\n\n// \u6BD4\u8F03\u53EF\u80FD\u30B0\u30E9\
    \u30D5\u3092\u4E0E\u3048\u308B\u3002DAG \u306A\u3060\u3051\u3067\u306F\u30C0\u30E1\
    \u3002\ntemplate <typename T>\nvc<int> maximum_antichain(T& G) {\n  assert(G.is_directed());\n\
    \  int n = G.N;\n\n  Graph H(n + n);\n  for (auto&& e: G.edges) { H.add(e.frm,\
    \ e.to + n); }\n  H.build();\n  BipartiteMatching BM(H);\n  auto cover = BM.vertex_cover();\n\
    \  auto match = BM.matching();\n  assert(len(cover) == len(match));\n  vc<bool>\
    \ ok(n, 1);\n  for (auto&& v: cover) { ok[v % n] = 0; }\n  vc<int> antichain;\n\
    \  FOR(v, n) if (ok[v]) antichain.eb(v);\n  for (auto&& e: G.edges) { assert(!ok[e.frm]\
    \ || !ok[e.to]); }\n  return antichain;\n}"
  dependsOn:
  - flow/bipartite.hpp
  - graph/base.hpp
  - graph/check_bipartite.hpp
  - ds/unionfind.hpp
  isVerificationFile: false
  path: graph/maximum_antichain.hpp
  requiredBy: []
  timestamp: '2022-05-11 20:22:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2251_maxantichain.test.cpp
documentation_of: graph/maximum_antichain.hpp
layout: document
redirect_from:
- /library/graph/maximum_antichain.hpp
- /library/graph/maximum_antichain.hpp.html
title: graph/maximum_antichain.hpp
---
