---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':warning:'
    path: graph/to_directed_tree.hpp
    title: graph/to_directed_tree.hpp
  - icon: ':x:'
    path: graph/toposort.hpp
    title: graph/toposort.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d
  bundledCode: "#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n\
    \    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n   \
    \ const edge_type* begin() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[l];\n    }\n\n    const edge_type* end() const {\n      if (l\
    \ == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n  private:\n \
    \   const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
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
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid\
    \ = 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e)\
    \ != M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]]\
    \ = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n    FOR(i, n) {\n\
    \      for (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n\
    \        int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b]\
    \ != -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n       \
    \   int eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b],\
    \ e.cost, eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n\
    \    for (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"graph/to_directed_tree.hpp\"\n\ntemplate <typename GT>\nGraph<typename\
    \ GT::cost_type, true> to_directed_tree(GT& G, int root = 0) {\n  assert(!GT::is_directed);\n\
    \  if (!G.is_prepared()) G.build();\n  int N = G.N;\n  vc<int> par_e(N, -1);\n\
    \  vc<int> V(N);\n  int l = 0, r = 0;\n  V[r++] = root;\n  while (l < r) {\n \
    \   int v = V[l++];\n    for (auto&& e: G[v]) {\n      if (e.id != par_e[v]) {\n\
    \        par_e[e.to] = e.id;\n        V[r++] = e.to;\n      }\n    }\n  }\n  Graph<typename\
    \ GT::cost_type, true> H(N);\n  FOR(v, N) {\n    if (v == root) continue;\n  \
    \  assert(par_e[v] != -1);\n    int eid = par_e[v];\n    auto& e = G.edges[eid];\n\
    \    int p = e.frm ^ e.to ^ v;\n    H.add(p, v, e.cost, e.id);\n  }\n  H.build();\n\
    \  return H;\n}\n#line 1 \"ds/fastset.hpp\"\n/* 64\u5206\u6728\u3002\r\ninsert,\
    \ erase\r\n[]\u3067\u306E\u5B58\u5728\u5224\u5B9A\r\nnext, prev\r\n*/\r\nstruct\
    \ FastSet {\r\n  using uint = unsigned;\r\n  using ull = unsigned long long;\r\
    \n\r\n  int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull x)\
    \ { return __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n  int\
    \ n, lg;\r\n  vector<vector<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do\
    \ {\r\n      seg.push_back(vector<ull>((_n + B - 1) / B));\r\n      _n = (_n +\
    \ B - 1) / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n  }\r\n\
    \  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0;\
    \ }\r\n  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void add(int\
    \ i) { insert(i); }\r\n  void erase(int i) {\r\n    for (int h = 0; h < lg; h++)\
    \ {\r\n      seg[h][i / B] &= ~(1ULL << (i % B));\r\n      if (seg[h][i / B])\
    \ break;\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int i) { erase(i);\
    \ }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\
    \u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int next(int i) {\r\n\
    \    chmax(i, 0);\r\n    if (i >= n) return n;\r\n    for (int h = 0; h < lg;\
    \ h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      ull d = seg[h][i\
    \ / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\
    \n      }\r\n      // find\r\n      i += bsf(d);\r\n      for (int g = h - 1;\
    \ g >= 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i / B]);\r\n  \
    \    }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // x\u4EE5\
    \u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\
    \u306A\u3051\u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if (i < 0) return\
    \ -1;\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      if (i == -1) break;\r\n      ull d = seg[h][i / B] << (63 - i % 64);\r\n\
    \      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n\
    \      // find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g = h - 1; g\
    \ >= 0; g--) {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\n    \
    \  }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  // [l, r)\r\
    \n  template <typename F>\r\n  void enumerate(int l, int r, F f) {\r\n    int\
    \ x = l - 1;\r\n    while (1) {\r\n      x = next(x + 1);\r\n      if (x >= r)\
    \ break;\r\n      f(x);\r\n    }\r\n  }\r\n\r\n  void debug() {\r\n    string\
    \ s;\r\n    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n   \
    \ print(s);\r\n  }\r\n};\r\n#line 3 \"graph/toposort.hpp\"\n\n// \u8F9E\u66F8\u9806\
    \u6700\u5C0F\u306E toposort \u3092\u8FD4\u3059\ntemplate <typename GT>\nvc<int>\
    \ toposort(GT& G) {\n  static_assert(GT::is_directed);\n  assert(G.is_prepared());\n\
    \  const int N = G.N;\n  auto [indeg, outdeg] = G.deg_array_inout();\n  FastSet\
    \ que(N);\n  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n  while\
    \ (1) {\n    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v), V.eb(v);\n\
    \    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n#line 4 \"graph/centroid_decomposition.hpp\"\
    \n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    1/3 CD \u306E\u307F\u6271\u3046\ncentroid_decomposition_1\uFF1A\u9577\u3055 2\
    \ \u4EE5\u4E0A\u306E\u30D1\u30B9\u5168\u4F53\ncentroid_decomposition_2\uFF1Areal,\
    \ virtual \u30D5\u30E9\u30B0\u3092\u6301\u3063\u3066\u9577\u3055 1 \u4EE5\u4E0A\
    \u306E\u30D1\u30B9\n*/\n\ntemplate <typename GT, typename F>\nvoid centroid_decomposition_1_dfs(GT&\
    \ G, vc<int> vs, F f) {\n  const int N = G.N;\n  assert(N > 1);\n  if (N == 2)\
    \ return;\n  vc<int> sz(N, 1), par(N, -1);\n  FOR_R(i, N) {\n    for (auto& e:\
    \ G[i]) sz[i] += sz[e.to], par[e.to] = i;\n  }\n  int c = -1;\n  FOR_R(i, N) {\n\
    \    if (sz[i] >= ceil<int>(N, 2)) {\n      c = i;\n      break;\n    }\n  }\n\
    \  vc<int> color(N, -1);\n  int take = 0;\n  vc<int> ord(N, -1);\n  ord[c] = 0;\n\
    \  int p = 1;\n  for (auto& e: G[c]) {\n    if (take + sz[e.to] <= floor<int>(N\
    \ - 1, 2)) {\n      color[e.to] = 0, ord[e.to] = p++, take += sz[e.to];\n    }\n\
    \  }\n  FOR(i, N) {\n    if (color[i] == 0) {\n      for (auto& e: G[i]) { color[e.to]\
    \ = 0, ord[e.to] = p++; }\n    }\n  }\n  int n1 = p - 1;\n  int a = c;\n  while\
    \ (1) {\n    a = par[a];\n    if (a == -1) break;\n    color[a] = 1, ord[a] =\
    \ p++;\n  }\n  FOR(i, N) {\n    if (i != c && color[i] == -1) color[i] = 1, ord[i]\
    \ = p++;\n  }\n  assert(p == N);\n  int n2 = N - 1 - n1;\n  using WT = typename\
    \ GT::cost_type;\n  Graph<WT, true> H1(n1 + 1), H2(n2 + 1), H(N);\n  vc<int> V1(n1\
    \ + 1), V2(n2 + 1), V(N);\n  V1[0] = V2[0] = V[0] = c;\n  FOR(v, N) {\n    int\
    \ i = ord[v];\n    V[i] = vs[v];\n    (i <= n1 ? V1[i] : V2[i - n1]) = vs[v];\n\
    \  }\n  for (auto& e: G.edges) {\n    int a = ord[e.frm], b = ord[e.to];\n   \
    \ if (a > b) swap(a, b);\n    H.add(a, b, e.cost, e.id);\n    if (b <= n1) {\n\
    \      H1.add(a, b, e.cost, e.id);\n    } else {\n      H2.add(max(a - n1, 0),\
    \ b - n1, e.cost, e.id);\n    }\n  }\n  H.build(), H1.build(), H2.build();\n \
    \ f(H, V, n1, n2);\n  centroid_decomposition_1_dfs(H1, V1, f);\n  centroid_decomposition_1_dfs(H2,\
    \ V2, f);\n}\n\n// \u9577\u3055 1 \u306E\u30D1\u30B9\u306F\u5225\u51E6\u7406\u3059\
    \u308B\u3053\u3068\u306B\u6CE8\u610F\n// \u9577\u3055 2 \u4EE5\u4E0A\u306E\u30D1\
    \u30B9\u3059\u3079\u3066\u306B\u5BFE\u3059\u308B\u8A08\u7B97\u3092\u3057\u305F\
    \u3044\n// f(G, V, n1, n2)\n// G: oriented\n// V: label in original tree, dfs\
    \ order\n// color=1: V[1:1+n1]\n// color=2: V[1+n1:1+n1+n2]\ntemplate <typename\
    \ GT, typename F>\nvoid centroid_decomposition_1(GT& G, F f) {\n  if (G.N == 1)\
    \ return;\n  if constexpr (GT::is_directed) {\n    vc<int> V = toposort(G);\n\
    \    G = G.rearrange(V, true);\n    centroid_decomposition_1_dfs(G, V, f);\n \
    \ } else {\n    Graph<typename GT::cost_type, true> H = to_directed_tree(G);\n\
    \    vc<int> V = toposort(H);\n    H = H.rearrange(V, true);\n    centroid_decomposition_1_dfs(H,\
    \ V, f);\n  }\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"graph/to_directed_tree.hpp\"\n#include\
    \ \"graph/toposort.hpp\"\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    1/3 CD \u306E\u307F\u6271\u3046\ncentroid_decomposition_1\uFF1A\u9577\u3055 2\
    \ \u4EE5\u4E0A\u306E\u30D1\u30B9\u5168\u4F53\ncentroid_decomposition_2\uFF1Areal,\
    \ virtual \u30D5\u30E9\u30B0\u3092\u6301\u3063\u3066\u9577\u3055 1 \u4EE5\u4E0A\
    \u306E\u30D1\u30B9\n*/\n\ntemplate <typename GT, typename F>\nvoid centroid_decomposition_1_dfs(GT&\
    \ G, vc<int> vs, F f) {\n  const int N = G.N;\n  assert(N > 1);\n  if (N == 2)\
    \ return;\n  vc<int> sz(N, 1), par(N, -1);\n  FOR_R(i, N) {\n    for (auto& e:\
    \ G[i]) sz[i] += sz[e.to], par[e.to] = i;\n  }\n  int c = -1;\n  FOR_R(i, N) {\n\
    \    if (sz[i] >= ceil<int>(N, 2)) {\n      c = i;\n      break;\n    }\n  }\n\
    \  vc<int> color(N, -1);\n  int take = 0;\n  vc<int> ord(N, -1);\n  ord[c] = 0;\n\
    \  int p = 1;\n  for (auto& e: G[c]) {\n    if (take + sz[e.to] <= floor<int>(N\
    \ - 1, 2)) {\n      color[e.to] = 0, ord[e.to] = p++, take += sz[e.to];\n    }\n\
    \  }\n  FOR(i, N) {\n    if (color[i] == 0) {\n      for (auto& e: G[i]) { color[e.to]\
    \ = 0, ord[e.to] = p++; }\n    }\n  }\n  int n1 = p - 1;\n  int a = c;\n  while\
    \ (1) {\n    a = par[a];\n    if (a == -1) break;\n    color[a] = 1, ord[a] =\
    \ p++;\n  }\n  FOR(i, N) {\n    if (i != c && color[i] == -1) color[i] = 1, ord[i]\
    \ = p++;\n  }\n  assert(p == N);\n  int n2 = N - 1 - n1;\n  using WT = typename\
    \ GT::cost_type;\n  Graph<WT, true> H1(n1 + 1), H2(n2 + 1), H(N);\n  vc<int> V1(n1\
    \ + 1), V2(n2 + 1), V(N);\n  V1[0] = V2[0] = V[0] = c;\n  FOR(v, N) {\n    int\
    \ i = ord[v];\n    V[i] = vs[v];\n    (i <= n1 ? V1[i] : V2[i - n1]) = vs[v];\n\
    \  }\n  for (auto& e: G.edges) {\n    int a = ord[e.frm], b = ord[e.to];\n   \
    \ if (a > b) swap(a, b);\n    H.add(a, b, e.cost, e.id);\n    if (b <= n1) {\n\
    \      H1.add(a, b, e.cost, e.id);\n    } else {\n      H2.add(max(a - n1, 0),\
    \ b - n1, e.cost, e.id);\n    }\n  }\n  H.build(), H1.build(), H2.build();\n \
    \ f(H, V, n1, n2);\n  centroid_decomposition_1_dfs(H1, V1, f);\n  centroid_decomposition_1_dfs(H2,\
    \ V2, f);\n}\n\n// \u9577\u3055 1 \u306E\u30D1\u30B9\u306F\u5225\u51E6\u7406\u3059\
    \u308B\u3053\u3068\u306B\u6CE8\u610F\n// \u9577\u3055 2 \u4EE5\u4E0A\u306E\u30D1\
    \u30B9\u3059\u3079\u3066\u306B\u5BFE\u3059\u308B\u8A08\u7B97\u3092\u3057\u305F\
    \u3044\n// f(G, V, n1, n2)\n// G: oriented\n// V: label in original tree, dfs\
    \ order\n// color=1: V[1:1+n1]\n// color=2: V[1+n1:1+n1+n2]\ntemplate <typename\
    \ GT, typename F>\nvoid centroid_decomposition_1(GT& G, F f) {\n  if (G.N == 1)\
    \ return;\n  if constexpr (GT::is_directed) {\n    vc<int> V = toposort(G);\n\
    \    G = G.rearrange(V, true);\n    centroid_decomposition_1_dfs(G, V, f);\n \
    \ } else {\n    Graph<typename GT::cost_type, true> H = to_directed_tree(G);\n\
    \    vc<int> V = toposort(H);\n    H = H.rearrange(V, true);\n    centroid_decomposition_1_dfs(H,\
    \ V, f);\n  }\n}"
  dependsOn:
  - graph/base.hpp
  - graph/to_directed_tree.hpp
  - graph/toposort.hpp
  - ds/fastset.hpp
  isVerificationFile: false
  path: graph/centroid_decomposition.hpp
  requiredBy: []
  timestamp: '2023-11-04 05:26:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph/centroid_decomposition.hpp
- /library/graph/centroid_decomposition.hpp.html
title: graph/centroid_decomposition.hpp
---
