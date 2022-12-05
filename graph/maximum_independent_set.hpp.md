---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/graph/maximum_independent_set.test.cpp
    title: test/library_checker/graph/maximum_independent_set.test.cpp
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
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\nprivate:\n  void calc_deg()\
    \ {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"graph/maximum_independent_set.hpp\"\
    \n\r\n// vertex id \u306E vector \u3092\u8FD4\u3059\r\ntemplate <typename Graph>\r\
    \nvector<int> maximum_independent_set(Graph& G, int trial = 1000000) {\r\n  using\
    \ T = i128;\r\n  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\n \
    \ int N = G.N;\r\n  vector<T> bit(N);\r\n  FOR(a, N) for (auto&& e: G[a]) bit[a]\
    \ |= T(1) << e.to;\r\n  vector<int> ord(N);\r\n  iota(begin(ord), end(ord), 0);\r\
    \n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\n  pair<int,\
    \ T> best;\r\n  for (int i = 0; i < trial; i++) {\r\n    shuffle(begin(ord), end(ord),\
    \ mt);\r\n    T used = 0;\r\n    int add = 0;\r\n    for (int j: ord) {\r\n  \
    \    if (used & bit[j]) continue;\r\n      used |= T(1) << j;\r\n      ++add;\r\
    \n    }\r\n    if (chmax(best.fi, add)) best.se = used;\r\n  }\r\n  vector<int>\
    \ ans;\r\n  for (int i = 0; i < N; i++) {\r\n    if (best.se >> i & 1) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n\r\n// vertex id \u306E vector \u3092\u8FD4\u3059\
    \r\ntemplate <typename Graph, int MAX_V>\r\nvector<int> _maximum_independent_set(Graph&\
    \ G, int trial = 1000000) {\r\n  using BS = bitset<MAX_V>;\r\n  assert(G.is_prepared());\r\
    \n  assert(!G.is_directed());\r\n  int N = G.N;\r\n  vector<BS> bit(N);\r\n  FOR(a,\
    \ N) for (auto&& e: G[a]) bit[a][e.to] = 1;\r\n  vector<int> ord(N);\r\n  iota(begin(ord),\
    \ end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  pair<int, BS> best;\r\n  for (int i = 0; i < trial; i++) {\r\n    shuffle(begin(ord),\
    \ end(ord), mt);\r\n    BS used;\r\n    int add = 0;\r\n    for (int j: ord) {\r\
    \n      if ((used & bit[j]).any()) continue;\r\n      used[j] = 1;\r\n      ++add;\r\
    \n    }\r\n    if (chmax(best.fi, add)) best.se = used;\r\n  }\r\n  vector<int>\
    \ ans;\r\n  for (int i = 0; i < N; i++) {\r\n    if (best.se[i]) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\n// vertex id \u306E vector \u3092\u8FD4\
    \u3059\r\ntemplate <typename Graph>\r\nvector<int> maximum_independent_set(Graph&\
    \ G, int trial = 1000000) {\r\n  using T = i128;\r\n  assert(G.is_prepared());\r\
    \n  assert(!G.is_directed());\r\n  int N = G.N;\r\n  vector<T> bit(N);\r\n  FOR(a,\
    \ N) for (auto&& e: G[a]) bit[a] |= T(1) << e.to;\r\n  vector<int> ord(N);\r\n\
    \  iota(begin(ord), end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  pair<int, T> best;\r\n  for (int i = 0; i < trial; i++) {\r\n    shuffle(begin(ord),\
    \ end(ord), mt);\r\n    T used = 0;\r\n    int add = 0;\r\n    for (int j: ord)\
    \ {\r\n      if (used & bit[j]) continue;\r\n      used |= T(1) << j;\r\n    \
    \  ++add;\r\n    }\r\n    if (chmax(best.fi, add)) best.se = used;\r\n  }\r\n\
    \  vector<int> ans;\r\n  for (int i = 0; i < N; i++) {\r\n    if (best.se >> i\
    \ & 1) ans.emplace_back(i);\r\n  }\r\n  return ans;\r\n}\r\n\r\n// vertex id \u306E\
    \ vector \u3092\u8FD4\u3059\r\ntemplate <typename Graph, int MAX_V>\r\nvector<int>\
    \ _maximum_independent_set(Graph& G, int trial = 1000000) {\r\n  using BS = bitset<MAX_V>;\r\
    \n  assert(G.is_prepared());\r\n  assert(!G.is_directed());\r\n  int N = G.N;\r\
    \n  vector<BS> bit(N);\r\n  FOR(a, N) for (auto&& e: G[a]) bit[a][e.to] = 1;\r\
    \n  vector<int> ord(N);\r\n  iota(begin(ord), end(ord), 0);\r\n  mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());\r\
    \n  pair<int, BS> best;\r\n  for (int i = 0; i < trial; i++) {\r\n    shuffle(begin(ord),\
    \ end(ord), mt);\r\n    BS used;\r\n    int add = 0;\r\n    for (int j: ord) {\r\
    \n      if ((used & bit[j]).any()) continue;\r\n      used[j] = 1;\r\n      ++add;\r\
    \n    }\r\n    if (chmax(best.fi, add)) best.se = used;\r\n  }\r\n  vector<int>\
    \ ans;\r\n  for (int i = 0; i < N; i++) {\r\n    if (best.se[i]) ans.emplace_back(i);\r\
    \n  }\r\n  return ans;\r\n}\r\n"
  dependsOn:
  - graph/base.hpp
  isVerificationFile: false
  path: graph/maximum_independent_set.hpp
  requiredBy: []
  timestamp: '2022-12-05 10:41:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/graph/maximum_independent_set.test.cpp
documentation_of: graph/maximum_independent_set.hpp
layout: document
redirect_from:
- /library/graph/maximum_independent_set.hpp
- /library/graph/maximum_independent_set.hpp.html
title: graph/maximum_independent_set.hpp
---
