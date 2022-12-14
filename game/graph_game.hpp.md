---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/reverse_graph.hpp
    title: graph/reverse_graph.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"game/graph_game.hpp\"\n\n#line 2 \"graph/base.hpp\"\n\n\
    template <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\
    \ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  int N,\
    \ M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n  constexpr bool is_directed() { return directed; }\n\n  Graph() : N(0),\
    \ M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void\
    \ resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost = 1, int i =\
    \ -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void read_parent(int off = 1) {\n    for (int v = 1; v < N; ++v) {\n\
    \      INT(p);\n      p -= off;\n      add(p, v);\n    }\n    build();\n  }\n\n\
    \  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\nprivate:\n  void calc_deg()\
    \ {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/reverse_graph.hpp\"\
    \n\r\ntemplate <typename T>\r\nGraph<T, 1> reverse_graph(Graph<T, 1>& G) {\r\n\
    \  assert(G.is_directed());\r\n  Graph<T, 1> G1(G.N);\r\n  for (auto&& e: G.edges)\
    \ { G1.add(e.to, e.frm, e.cost, e.id); }\r\n  G1.build();\r\n  return G1;\r\n\
    }\r\n#line 3 \"game/graph_game.hpp\"\n\n// \u6709\u5411\u30B0\u30E9\u30D5\u3001\
    \u52D5\u3051\u306A\u3044\u4EBA\u304C\u8CA0\u3051\n// \u5404\u30CE\u30FC\u30C9\u306B\
    \u5BFE\u3057\u3066\u624B\u756A\u306E\u30D7\u30EC\u30A4\u30E4\u304C\u6C7A\u307E\
    \u3063\u3066\u3044\u3066\u3001\u4EA4\u4E92\n// \u52DD\u8005\u306F\u6700\u77ED\u3001\
    \u6557\u8005\u306F\u6700\u9577\u624B\u6570\u3092\u76EE\u6307\u3059\nstruct Graph_Game\
    \ {\n  vc<bool> win;\n  vc<bool> lose;\n  vc<int> end_turn;\n  vc<int> best_strategy;\n\
    \n  template <typename GT>\n  Graph_Game(GT& G) {\n    auto RG = reverse_graph(G);\n\
    \    auto [indeg, outdeg] = G.deg_array_inout();\n    int N = G.N;\n    win.resize(N);\n\
    \    lose.resize(N);\n    end_turn.resize(N, 1 << 30);\n    best_strategy.resize(N,\
    \ -1);\n    deque<int> que;\n    FOR(v, N) {\n      if (outdeg[v] == 0) que.eb(v);\n\
    \    }\n\n    while (!que.empty()) {\n      auto v = pick(que);\n      if (win[v]\
    \ || lose[v]) continue;\n      lose[v] = 1;\n      for (auto&& e: G[v]) {\n  \
    \      if (lose[e.to]) win[v] = 1;\n        if (!win[e.to]) lose[v] = 0;\n   \
    \   }\n      assert(win[v] ^ lose[v]);\n      if (win[v]) {\n        for (auto&&\
    \ e: G[v]) {\n          if (chmin(end_turn[v], end_turn[e.to] + 1)) {\n      \
    \      best_strategy[v] = e.to;\n          }\n        }\n      }\n      if (lose[v])\
    \ {\n        end_turn[v] = 0;\n        for (auto&& e: G[v]) {\n          if (chmax(end_turn[v],\
    \ end_turn[e.to] + 1)) {\n            best_strategy[v] = e.to;\n          }\n\
    \        }\n      }\n      for (auto&& e: RG[v]) {\n        outdeg[e.to]--;\n\
    \        if (lose[v] || outdeg[e.to] == 0) que.eb(e.to);\n      }\n    }\n  }\n\
    };\n"
  code: "\n#include \"graph/reverse_graph.hpp\"\n\n// \u6709\u5411\u30B0\u30E9\u30D5\
    \u3001\u52D5\u3051\u306A\u3044\u4EBA\u304C\u8CA0\u3051\n// \u5404\u30CE\u30FC\u30C9\
    \u306B\u5BFE\u3057\u3066\u624B\u756A\u306E\u30D7\u30EC\u30A4\u30E4\u304C\u6C7A\
    \u307E\u3063\u3066\u3044\u3066\u3001\u4EA4\u4E92\n// \u52DD\u8005\u306F\u6700\u77ED\
    \u3001\u6557\u8005\u306F\u6700\u9577\u624B\u6570\u3092\u76EE\u6307\u3059\nstruct\
    \ Graph_Game {\n  vc<bool> win;\n  vc<bool> lose;\n  vc<int> end_turn;\n  vc<int>\
    \ best_strategy;\n\n  template <typename GT>\n  Graph_Game(GT& G) {\n    auto\
    \ RG = reverse_graph(G);\n    auto [indeg, outdeg] = G.deg_array_inout();\n  \
    \  int N = G.N;\n    win.resize(N);\n    lose.resize(N);\n    end_turn.resize(N,\
    \ 1 << 30);\n    best_strategy.resize(N, -1);\n    deque<int> que;\n    FOR(v,\
    \ N) {\n      if (outdeg[v] == 0) que.eb(v);\n    }\n\n    while (!que.empty())\
    \ {\n      auto v = pick(que);\n      if (win[v] || lose[v]) continue;\n     \
    \ lose[v] = 1;\n      for (auto&& e: G[v]) {\n        if (lose[e.to]) win[v] =\
    \ 1;\n        if (!win[e.to]) lose[v] = 0;\n      }\n      assert(win[v] ^ lose[v]);\n\
    \      if (win[v]) {\n        for (auto&& e: G[v]) {\n          if (chmin(end_turn[v],\
    \ end_turn[e.to] + 1)) {\n            best_strategy[v] = e.to;\n          }\n\
    \        }\n      }\n      if (lose[v]) {\n        end_turn[v] = 0;\n        for\
    \ (auto&& e: G[v]) {\n          if (chmax(end_turn[v], end_turn[e.to] + 1)) {\n\
    \            best_strategy[v] = e.to;\n          }\n        }\n      }\n     \
    \ for (auto&& e: RG[v]) {\n        outdeg[e.to]--;\n        if (lose[v] || outdeg[e.to]\
    \ == 0) que.eb(e.to);\n      }\n    }\n  }\n};"
  dependsOn:
  - graph/reverse_graph.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: game/graph_game.hpp
  requiredBy: []
  timestamp: '2022-12-05 10:41:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: game/graph_game.hpp
layout: document
redirect_from:
- /library/game/graph_game.hpp
- /library/game/graph_game.hpp.html
title: game/graph_game.hpp
---
