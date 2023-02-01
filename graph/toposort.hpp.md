---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/dag_path_cover.hpp
    title: graph/dag_path_cover.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2251_1.test.cpp
    title: test/aoj/2251_1.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc223d.test.cpp
    title: test_atcoder/abc223d.test.cpp
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 1 \"ds/fastset.hpp\"\
    \n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\n[]\u3067\u306E\u5B58\u5728\u5224\
    \u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet {\r\n  using uint = unsigned;\r\n\
    \  using ull = unsigned long long;\r\n\r\n  int bsr(ull x) { return 63 - __builtin_clzll(x);\
    \ }\r\n  int bsf(ull x) { return __builtin_ctzll(x); }\r\n\r\n  static constexpr\
    \ uint B = 64;\r\n  int n, lg;\r\n  vector<vector<ull>> seg;\r\n  FastSet(int\
    \ _n) : n(_n) {\r\n    do {\r\n      seg.push_back(vector<ull>((_n + B - 1) /\
    \ B));\r\n      _n = (_n + B - 1) / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\
    \n  }\r\n  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1)\
    \ != 0; }\r\n  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      seg[h][i / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n\
    \  void erase(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] &= ~(1ULL << (i % B));\r\n      if (seg[h][i / B]) break;\r\n      i /=\
    \ B;\r\n    }\r\n  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int\
    \ next(int i) {\r\n    chmax(i, 0);\r\n    if (i >= n) return n;\r\n    for (int\
    \ h = 0; h < lg; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      ull\
    \ d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\
    \n        continue;\r\n      }\r\n      // find\r\n      i += bsf(d);\r\n    \
    \  for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i\
    \ / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n\
    \  // x\u4EE5\u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if\
    \ (i < 0) return -1;\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h <\
    \ lg; h++) {\r\n      if (i == -1) break;\r\n      ull d = seg[h][i / B] << (63\
    \ - i % 64);\r\n      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\
    \n      }\r\n      // find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g\
    \ = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\
    \n      }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  // [l,\
    \ r) \u5185\u306E\u8981\u7D20\u3092\u5168\u90E8\u96C6\u3081\u308B\r\n  vector<int>\
    \ collect(int l, int r) {\r\n    vector<int> res;\r\n    int x = l - 1;\r\n  \
    \  while (1) {\r\n      x = next(x + 1);\r\n      if (x >= r) break;\r\n     \
    \ res.emplace_back(x);\r\n    }\r\n    return res;\r\n  }\r\n\r\n  void debug()\
    \ {\r\n    string s;\r\n    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1'\
    \ : '0');\r\n    print(s);\r\n  }\r\n};\r\n#line 3 \"graph/toposort.hpp\"\n\n\
    // \u8F9E\u66F8\u9806\u6700\u5C0F\u306E toposort \u3092\u8FD4\u3059\ntemplate\
    \ <typename GT>\nvc<int> toposort(GT& G) {\n  assert(G.is_prepared() && G.is_directed());\n\
    \  const int N = G.N;\n  auto [indeg, outdeg] = G.deg_array_inout();\n  FastSet\
    \ que(N);\n  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n  while\
    \ (1) {\n    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v), V.eb(v);\n\
    \    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/fastset.hpp\"\n\n// \u8F9E\u66F8\
    \u9806\u6700\u5C0F\u306E toposort \u3092\u8FD4\u3059\ntemplate <typename GT>\n\
    vc<int> toposort(GT& G) {\n  assert(G.is_prepared() && G.is_directed());\n  const\
    \ int N = G.N;\n  auto [indeg, outdeg] = G.deg_array_inout();\n  FastSet que(N);\n\
    \  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n  while (1) {\n\
    \    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v), V.eb(v);\n\
    \    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n"
  dependsOn:
  - graph/base.hpp
  - ds/fastset.hpp
  isVerificationFile: false
  path: graph/toposort.hpp
  requiredBy:
  - graph/dag_path_cover.hpp
  timestamp: '2023-01-23 16:27:51+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/2251_1.test.cpp
  - test_atcoder/abc223d.test.cpp
documentation_of: graph/toposort.hpp
layout: document
redirect_from:
- /library/graph/toposort.hpp
- /library/graph/toposort.hpp.html
title: graph/toposort.hpp
---
