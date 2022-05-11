---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':warning:'
    path: graph/reverse_graph.hpp
    title: graph/reverse_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \ wt = false, int off = 1) {\n    FOR_(M) {\n      INT(a, b);\n      a -= off,\
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
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n};\n#line 2 \"graph/reverse_graph.hpp\"\
    \ntemplate <typename Graph>\r\nGraph reverse_graph(Graph& G) {\r\n  assert(G.is_directed());\r\
    \n  Graph G1(G.N);\r\n  for (auto&& e: G.edges) { G1.add(e.to, e.frm, e.cost,\
    \ e.id); }\r\n  G1.prepare();\r\n  return G1;\r\n}\r\n#line 2 \"graph/solve_dag_game.hpp\"\
    \ntemplate <typename Graph, typename INT>\r\nvoid solve_dag_game(Graph& G, vc<INT>&\
    \ DP) {\r\n  /*\r\n  -1: unknown\r\n  0 : lose\r\n  1 : win\r\n\r\n  \u4E88\u3081\
    \u9077\u79FB\u5148\u306E\u306A\u3044\u9802\u70B9\u306B\u306F\u30010 \u307E\u305F\
    \u306F 1 \u3092\u5165\u308C\u3066\u304A\u304F\r\n  */\r\n  int N = G.N;\r\n  vc<int>\
    \ outdeg(N);\r\n  for (auto&& e: G.edges) outdeg[e.frm]++;\r\n\r\n  G = reverse_graph(G);\r\
    \n  vc<int> que;\r\n  FOR(v, N) {\r\n    assert((outdeg[v] == 0) == (DP[v] !=\
    \ -1));\r\n    if (outdeg[v] == 0) que.eb(v);\r\n  }\r\n  while (!que.empty())\
    \ {\r\n    int v = que.back();\r\n    que.pop_back();\r\n    for (auto&& e: G[v])\
    \ {\r\n      if (DP[e.to] != -1) continue;\r\n      if (DP[v] == 0) {\r\n    \
    \    DP[e.to] = 1;\r\n        que.eb(e.to);\r\n      }\r\n      elif (DP[v] ==\
    \ 1) {\r\n        outdeg[e.to]--;\r\n        if (outdeg[e.to] == 0) {\r\n    \
    \      DP[e.to] = 0;\r\n          que.eb(e.to);\r\n        }\r\n      }\r\n  \
    \  }\r\n  }\r\n}\r\n"
  code: "#include \"graph/reverse_graph.hpp\"\r\ntemplate <typename Graph, typename\
    \ INT>\r\nvoid solve_dag_game(Graph& G, vc<INT>& DP) {\r\n  /*\r\n  -1: unknown\r\
    \n  0 : lose\r\n  1 : win\r\n\r\n  \u4E88\u3081\u9077\u79FB\u5148\u306E\u306A\u3044\
    \u9802\u70B9\u306B\u306F\u30010 \u307E\u305F\u306F 1 \u3092\u5165\u308C\u3066\u304A\
    \u304F\r\n  */\r\n  int N = G.N;\r\n  vc<int> outdeg(N);\r\n  for (auto&& e: G.edges)\
    \ outdeg[e.frm]++;\r\n\r\n  G = reverse_graph(G);\r\n  vc<int> que;\r\n  FOR(v,\
    \ N) {\r\n    assert((outdeg[v] == 0) == (DP[v] != -1));\r\n    if (outdeg[v]\
    \ == 0) que.eb(v);\r\n  }\r\n  while (!que.empty()) {\r\n    int v = que.back();\r\
    \n    que.pop_back();\r\n    for (auto&& e: G[v]) {\r\n      if (DP[e.to] != -1)\
    \ continue;\r\n      if (DP[v] == 0) {\r\n        DP[e.to] = 1;\r\n        que.eb(e.to);\r\
    \n      }\r\n      elif (DP[v] == 1) {\r\n        outdeg[e.to]--;\r\n        if\
    \ (outdeg[e.to] == 0) {\r\n          DP[e.to] = 0;\r\n          que.eb(e.to);\r\
    \n        }\r\n      }\r\n    }\r\n  }\r\n}\r\n"
  dependsOn:
  - graph/reverse_graph.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/solve_dag_game.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/solve_dag_game.hpp
layout: document
redirect_from:
- /library/graph/solve_dag_game.hpp
- /library/graph/solve_dag_game.hpp.html
title: graph/solve_dag_game.hpp
---
