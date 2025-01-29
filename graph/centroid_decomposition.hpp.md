---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/shortest_path/bfs01.hpp
    title: graph/shortest_path/bfs01.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/ds/contour_query_range.hpp
    title: graph/ds/contour_query_range.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree_all_distances.hpp
    title: graph/tree_all_distances.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/frequency_table_of_tree_distance.test.cpp
    title: test/2_library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
    title: test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/frequency_table_of_tree_distance_2.test.cpp
    title: test/2_library_checker/tree/frequency_table_of_tree_distance_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/tree/vertex_get_range_contour_add_on_tree.test.cpp
    title: test/2_library_checker/tree/vertex_get_range_contour_add_on_tree.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1038.test.cpp
    title: test/3_yukicoder/1038.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1796_1.test.cpp
    title: test/3_yukicoder/1796_1.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2892.test.cpp
    title: test/3_yukicoder/2892.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d
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
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
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
    #line 3 \"graph/shortest_path/bfs01.hpp\"\n\ntemplate <typename T, typename GT>\n\
    pair<vc<T>, vc<int>> bfs01(GT& G, int v) {\n  assert(G.is_prepared());\n  int\
    \ N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  deque<int> que;\n\
    \n  dist[v] = 0;\n  que.push_front(v);\n  while (!que.empty()) {\n    auto v =\
    \ que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n      if (dist[e.to]\
    \ == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm]\
    \ + e.cost;\n        par[e.to] = e.frm;\n        if (e.cost == 0)\n          que.push_front(e.to);\n\
    \        else\n          que.push_back(e.to);\n      }\n    }\n  }\n  return {dist,\
    \ par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\n\
    template <typename T, typename GT>\ntuple<vc<T>, vc<int>, vc<int>> bfs01(GT& G,\
    \ vc<int> vs) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<T> dist(N, infty<T>);\n\
    \  vc<int> par(N, -1);\n  vc<int> root(N, -1);\n  deque<int> que;\n\n  for (auto&&\
    \ v: vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.push_front(v);\n  }\n\n\
    \  while (!que.empty()) {\n    auto v = que.front();\n    que.pop_front();\n \
    \   for (auto&& e: G[v]) {\n      if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm]\
    \ + e.cost) {\n        dist[e.to] = dist[e.frm] + e.cost;\n        root[e.to]\
    \ = root[e.frm];\n        par[e.to] = e.frm;\n        if (e.cost == 0)\n     \
    \     que.push_front(e.to);\n        else\n          que.push_back(e.to);\n  \
    \    }\n    }\n  }\n  return {dist, par, root};\n}\n#line 3 \"graph/centroid_decomposition.hpp\"\
    \n\n// \u9802\u70B9\u30D9\u30FC\u30B9\u306E\u91CD\u5FC3\u5206\u89E3\n// f(par,\
    \ V, indptr)\ntemplate <typename F>\nvoid centroid_decomposition_0_dfs(vc<int>&\
    \ par, vc<int>& vs, F f) {\n  const int N = len(par);\n  assert(N >= 1);\n  int\
    \ c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n    if (sz[i] >= ceil<int>(N,\
    \ 2)) {\n      c = i;\n      break;\n    }\n    sz[par[i]] += sz[i];\n  }\n  vc<int>\
    \ color(N);\n  vc<int> V = {c};\n  int nc = 1;\n  FOR(v, 1, N) {\n    if (par[v]\
    \ == c) { V.eb(v), color[v] = nc++; }\n  }\n  if (c > 0) {\n    for (int a = par[c];\
    \ a != -1; a = par[a]) { color[a] = nc, V.eb(a); }\n    ++nc;\n  }\n  FOR(i, N)\
    \ {\n    if (i != c && color[i] == 0) color[i] = color[par[i]], V.eb(i);\n  }\n\
    \  vc<int> indptr(nc + 1);\n  FOR(i, N) indptr[1 + color[i]]++;\n  FOR(i, nc)\
    \ indptr[i + 1] += indptr[i];\n  vc<int> counter = indptr;\n  vc<int> ord(N);\n\
    \  for (auto& v: V) { ord[counter[color[v]]++] = v; }\n  vc<int> new_idx(N);\n\
    \  FOR(i, N) new_idx[ord[i]] = i;\n  vc<int> name(N);\n  FOR(i, N) name[new_idx[i]]\
    \ = vs[i];\n  {\n    vc<int> tmp(N, -1);\n    FOR(i, 1, N) {\n      int a = new_idx[i],\
    \ b = new_idx[par[i]];\n      if (a > b) swap(a, b);\n      tmp[b] = a;\n    }\n\
    \    swap(par, tmp);\n  }\n  f(par, name, indptr);\n  FOR(k, 1, nc) {\n    int\
    \ L = indptr[k], R = indptr[k + 1];\n    vc<int> par1(R - L, -1);\n    vc<int>\
    \ name1(R - L, -1);\n    name1[0] = name[0];\n    FOR(i, L, R) name1[i - L] =\
    \ name[i];\n    FOR(i, L, R) { par1[i - L] = max(par[i] - L, -1); }\n    centroid_decomposition_0_dfs(par1,\
    \ name1, f);\n  }\n}\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    centroid_decomposition_1\uFF1A\u9577\u3055 1 \u4EE5\u4E0A\u306E\u30D1\u30B9\u5168\
    \u4F53\nf(par, V, L1, R1, L2, R2)\n[L1, R1): color 1 / [L2, R2): color 2\n*/\n\
    template <typename F>\nvoid centroid_decomposition_1_dfs(vc<int>& par, vc<int>\
    \ vs, F f) {\n  const int N = len(par);\n  assert(N > 1);\n  if (N == 2) {\n \
    \   vc<int> p = {-1, 0};\n    vc<int> v = {vs[0], vs[1]};\n    f(p, vs, 0, 1,\
    \ 1, 2);\n    return;\n  }\n  int c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N)\
    \ {\n    if (sz[i] >= ceil<int>(N, 2)) {\n      c = i;\n      break;\n    }\n\
    \    sz[par[i]] += sz[i];\n  }\n  vc<int> color(N, -1);\n  int take = 0;\n  vc<int>\
    \ ord(N, -1);\n  ord[c] = 0;\n  int p = 1;\n  FOR(v, 1, N) {\n    if (par[v] ==\
    \ c && take + sz[v] <= floor<int>(N - 1, 2)) { color[v] = 0, ord[v] = p++, take\
    \ += sz[v]; }\n  }\n  FOR(i, 1, N) {\n    if (color[par[i]] == 0) color[i] = 0,\
    \ ord[i] = p++;\n  }\n  int n0 = p - 1;\n  for (int a = par[c]; a != -1; a = par[a])\
    \ { color[a] = 1, ord[a] = p++; }\n  FOR(i, N) {\n    if (i != c && color[i] ==\
    \ -1) color[i] = 1, ord[i] = p++;\n  }\n  assert(p == N);\n  int n1 = N - 1 -\
    \ n0;\n  vc<int> par0(n0 + 1, -1), par1(n1 + 1, -1), par2(N, -1);\n  vc<int> V0(n0\
    \ + 1), V1(n1 + 1), V2(N);\n  FOR(v, N) {\n    int i = ord[v];\n    V2[i] = vs[v];\n\
    \    if (color[v] != 1) { V0[i] = vs[v]; }\n    if (color[v] != 0) { V1[max(i\
    \ - n0, 0)] = vs[v]; }\n  }\n  FOR(v, 1, N) {\n    int a = ord[v], b = ord[par[v]];\n\
    \    if (a > b) swap(a, b);\n    par2[b] = a;\n    if (color[v] != 1 && color[par[v]]\
    \ != 1) par0[b] = a;\n    if (color[v] != 0 && color[par[v]] != 0) par1[max(b\
    \ - n0, 0)] = max(a - n0, 0);\n  }\n  f(par2, V2, 1, 1 + n0, 1 + n0, 1 + n0 +\
    \ n1);\n  centroid_decomposition_1_dfs(par0, V0, f);\n  centroid_decomposition_1_dfs(par1,\
    \ V1, f);\n}\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    f(par, V, color)\ncolor in [-1,0,1], -1 is virtual.\n*/\ntemplate <typename F>\n\
    void centroid_decomposition_2_dfs(vc<int>& par, vc<int>& vs, vc<int>& real, F\
    \ f) {\n  const int N = len(par);\n  assert(N > 1);\n  if (N == 2) {\n    if (real[0]\
    \ && real[1]) {\n      vc<int> color = {0, 1};\n      f(par, vs, color);\n   \
    \ }\n    return;\n  }\n  int c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n \
    \   if (sz[i] >= ceil<int>(N, 2)) {\n      c = i;\n      break;\n    }\n    sz[par[i]]\
    \ += sz[i];\n  }\n  vc<int> color(N, -1);\n  int take = 0;\n  vc<int> ord(N, -1);\n\
    \  ord[c] = 0;\n  int p = 1;\n  FOR(v, 1, N) {\n    if (par[v] == c && take +\
    \ sz[v] <= floor<int>(N - 1, 2)) { color[v] = 0, ord[v] = p++, take += sz[v];\
    \ }\n  }\n  FOR(i, 1, N) {\n    if (color[par[i]] == 0) color[i] = 0, ord[i] =\
    \ p++;\n  }\n  int n0 = p - 1;\n  for (int a = par[c]; a != -1; a = par[a]) {\
    \ color[a] = 1, ord[a] = p++; }\n  FOR(i, N) {\n    if (i != c && color[i] ==\
    \ -1) color[i] = 1, ord[i] = p++;\n  }\n  assert(p == N);\n  int n1 = N - 1 -\
    \ n0;\n  vc<int> par0(n0 + 1, -1), par1(n1 + 1, -1), par2(N, -1);\n  vc<int> V0(n0\
    \ + 1), V1(n1 + 1), V2(N);\n  vc<int> rea0(n0 + 1), rea1(n1 + 1), rea2(N);\n \
    \ FOR(v, N) {\n    int i = ord[v];\n    V2[i] = vs[v], rea2[i] = real[v];\n  \
    \  if (color[v] != 1) { V0[i] = vs[v], rea0[i] = real[v]; }\n    if (color[v]\
    \ != 0) { V1[max(i - n0, 0)] = vs[v], rea1[max(i - n0, 0)] = real[v]; }\n  }\n\
    \  FOR(v, 1, N) {\n    int a = ord[v], b = ord[par[v]];\n    if (a > b) swap(a,\
    \ b);\n    par2[b] = a;\n    if (color[v] != 1 && color[par[v]] != 1) par0[b]\
    \ = a;\n    if (color[v] != 0 && color[par[v]] != 0) par1[max(b - n0, 0)] = max(a\
    \ - n0, 0);\n  }\n  color.assign(N, -1);\n  FOR(i, 1, N) if (rea2[i]) color[i]\
    \ = (i <= n0 ? 0 : 1);\n  if (real[c]) color[0] = 2, rea0[0] = rea1[0] = rea2[0]\
    \ = 0;\n  f(par2, V2, color);\n  centroid_decomposition_2_dfs(par0, V0, rea0,\
    \ f);\n  centroid_decomposition_2_dfs(par1, V1, rea1, f);\n}\n\n// 0: f(par, V,\
    \ indptr)\n// 1: f(par, V, L1, R1, L2, R2)\n// 2: f(par, V, color)\ntemplate <int\
    \ MODE, typename GT, typename F>\nvoid centroid_decomposition(GT& G, F f) {\n\
    \  static_assert(!GT::is_directed);\n  const int N = G.N;\n  if (MODE != 0 &&\
    \ N == 1) return;\n  vc<int> V(N), par(N, -1);\n  int l = 0, r = 0;\n  V[r++]\
    \ = 0;\n  while (l < r) {\n    int v = V[l++];\n    for (auto& e: G[v]) {\n  \
    \    if (e.to != par[v]) V[r++] = e.to, par[e.to] = v;\n    }\n  }\n  assert(r\
    \ == N);\n  vc<int> new_idx(N);\n  FOR(i, N) new_idx[V[i]] = i;\n  vc<int> tmp(N,\
    \ -1);\n  FOR(i, 1, N) {\n    int j = par[i];\n    tmp[new_idx[i]] = new_idx[j];\n\
    \  }\n  swap(par, tmp);\n  static_assert(MODE == 0 || MODE == 1 || MODE == 2);\n\
    \  if constexpr (MODE == 0) { centroid_decomposition_0_dfs(par, V, f); }\n  elif\
    \ constexpr(MODE == 1) { centroid_decomposition_1_dfs(par, V, f); }\n  else {\n\
    \    vc<int> real(N, 1);\n    centroid_decomposition_2_dfs(par, V, real, f);\n\
    \  }\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"graph/shortest_path/bfs01.hpp\"\n\
    \n// \u9802\u70B9\u30D9\u30FC\u30B9\u306E\u91CD\u5FC3\u5206\u89E3\n// f(par, V,\
    \ indptr)\ntemplate <typename F>\nvoid centroid_decomposition_0_dfs(vc<int>& par,\
    \ vc<int>& vs, F f) {\n  const int N = len(par);\n  assert(N >= 1);\n  int c =\
    \ -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n    if (sz[i] >= ceil<int>(N, 2))\
    \ {\n      c = i;\n      break;\n    }\n    sz[par[i]] += sz[i];\n  }\n  vc<int>\
    \ color(N);\n  vc<int> V = {c};\n  int nc = 1;\n  FOR(v, 1, N) {\n    if (par[v]\
    \ == c) { V.eb(v), color[v] = nc++; }\n  }\n  if (c > 0) {\n    for (int a = par[c];\
    \ a != -1; a = par[a]) { color[a] = nc, V.eb(a); }\n    ++nc;\n  }\n  FOR(i, N)\
    \ {\n    if (i != c && color[i] == 0) color[i] = color[par[i]], V.eb(i);\n  }\n\
    \  vc<int> indptr(nc + 1);\n  FOR(i, N) indptr[1 + color[i]]++;\n  FOR(i, nc)\
    \ indptr[i + 1] += indptr[i];\n  vc<int> counter = indptr;\n  vc<int> ord(N);\n\
    \  for (auto& v: V) { ord[counter[color[v]]++] = v; }\n  vc<int> new_idx(N);\n\
    \  FOR(i, N) new_idx[ord[i]] = i;\n  vc<int> name(N);\n  FOR(i, N) name[new_idx[i]]\
    \ = vs[i];\n  {\n    vc<int> tmp(N, -1);\n    FOR(i, 1, N) {\n      int a = new_idx[i],\
    \ b = new_idx[par[i]];\n      if (a > b) swap(a, b);\n      tmp[b] = a;\n    }\n\
    \    swap(par, tmp);\n  }\n  f(par, name, indptr);\n  FOR(k, 1, nc) {\n    int\
    \ L = indptr[k], R = indptr[k + 1];\n    vc<int> par1(R - L, -1);\n    vc<int>\
    \ name1(R - L, -1);\n    name1[0] = name[0];\n    FOR(i, L, R) name1[i - L] =\
    \ name[i];\n    FOR(i, L, R) { par1[i - L] = max(par[i] - L, -1); }\n    centroid_decomposition_0_dfs(par1,\
    \ name1, f);\n  }\n}\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    centroid_decomposition_1\uFF1A\u9577\u3055 1 \u4EE5\u4E0A\u306E\u30D1\u30B9\u5168\
    \u4F53\nf(par, V, L1, R1, L2, R2)\n[L1, R1): color 1 / [L2, R2): color 2\n*/\n\
    template <typename F>\nvoid centroid_decomposition_1_dfs(vc<int>& par, vc<int>\
    \ vs, F f) {\n  const int N = len(par);\n  assert(N > 1);\n  if (N == 2) {\n \
    \   vc<int> p = {-1, 0};\n    vc<int> v = {vs[0], vs[1]};\n    f(p, vs, 0, 1,\
    \ 1, 2);\n    return;\n  }\n  int c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N)\
    \ {\n    if (sz[i] >= ceil<int>(N, 2)) {\n      c = i;\n      break;\n    }\n\
    \    sz[par[i]] += sz[i];\n  }\n  vc<int> color(N, -1);\n  int take = 0;\n  vc<int>\
    \ ord(N, -1);\n  ord[c] = 0;\n  int p = 1;\n  FOR(v, 1, N) {\n    if (par[v] ==\
    \ c && take + sz[v] <= floor<int>(N - 1, 2)) { color[v] = 0, ord[v] = p++, take\
    \ += sz[v]; }\n  }\n  FOR(i, 1, N) {\n    if (color[par[i]] == 0) color[i] = 0,\
    \ ord[i] = p++;\n  }\n  int n0 = p - 1;\n  for (int a = par[c]; a != -1; a = par[a])\
    \ { color[a] = 1, ord[a] = p++; }\n  FOR(i, N) {\n    if (i != c && color[i] ==\
    \ -1) color[i] = 1, ord[i] = p++;\n  }\n  assert(p == N);\n  int n1 = N - 1 -\
    \ n0;\n  vc<int> par0(n0 + 1, -1), par1(n1 + 1, -1), par2(N, -1);\n  vc<int> V0(n0\
    \ + 1), V1(n1 + 1), V2(N);\n  FOR(v, N) {\n    int i = ord[v];\n    V2[i] = vs[v];\n\
    \    if (color[v] != 1) { V0[i] = vs[v]; }\n    if (color[v] != 0) { V1[max(i\
    \ - n0, 0)] = vs[v]; }\n  }\n  FOR(v, 1, N) {\n    int a = ord[v], b = ord[par[v]];\n\
    \    if (a > b) swap(a, b);\n    par2[b] = a;\n    if (color[v] != 1 && color[par[v]]\
    \ != 1) par0[b] = a;\n    if (color[v] != 0 && color[par[v]] != 0) par1[max(b\
    \ - n0, 0)] = max(a - n0, 0);\n  }\n  f(par2, V2, 1, 1 + n0, 1 + n0, 1 + n0 +\
    \ n1);\n  centroid_decomposition_1_dfs(par0, V0, f);\n  centroid_decomposition_1_dfs(par1,\
    \ V1, f);\n}\n\n/*\nhttps://maspypy.com/%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%83%bb1-3%e9%87%8d%e5%bf%83%e5%88%86%e8%a7%a3%e3%81%ae%e3%81%8a%e7%b5%b5%e6%8f%8f%e3%81%8d\n\
    f(par, V, color)\ncolor in [-1,0,1], -1 is virtual.\n*/\ntemplate <typename F>\n\
    void centroid_decomposition_2_dfs(vc<int>& par, vc<int>& vs, vc<int>& real, F\
    \ f) {\n  const int N = len(par);\n  assert(N > 1);\n  if (N == 2) {\n    if (real[0]\
    \ && real[1]) {\n      vc<int> color = {0, 1};\n      f(par, vs, color);\n   \
    \ }\n    return;\n  }\n  int c = -1;\n  vc<int> sz(N, 1);\n  FOR_R(i, N) {\n \
    \   if (sz[i] >= ceil<int>(N, 2)) {\n      c = i;\n      break;\n    }\n    sz[par[i]]\
    \ += sz[i];\n  }\n  vc<int> color(N, -1);\n  int take = 0;\n  vc<int> ord(N, -1);\n\
    \  ord[c] = 0;\n  int p = 1;\n  FOR(v, 1, N) {\n    if (par[v] == c && take +\
    \ sz[v] <= floor<int>(N - 1, 2)) { color[v] = 0, ord[v] = p++, take += sz[v];\
    \ }\n  }\n  FOR(i, 1, N) {\n    if (color[par[i]] == 0) color[i] = 0, ord[i] =\
    \ p++;\n  }\n  int n0 = p - 1;\n  for (int a = par[c]; a != -1; a = par[a]) {\
    \ color[a] = 1, ord[a] = p++; }\n  FOR(i, N) {\n    if (i != c && color[i] ==\
    \ -1) color[i] = 1, ord[i] = p++;\n  }\n  assert(p == N);\n  int n1 = N - 1 -\
    \ n0;\n  vc<int> par0(n0 + 1, -1), par1(n1 + 1, -1), par2(N, -1);\n  vc<int> V0(n0\
    \ + 1), V1(n1 + 1), V2(N);\n  vc<int> rea0(n0 + 1), rea1(n1 + 1), rea2(N);\n \
    \ FOR(v, N) {\n    int i = ord[v];\n    V2[i] = vs[v], rea2[i] = real[v];\n  \
    \  if (color[v] != 1) { V0[i] = vs[v], rea0[i] = real[v]; }\n    if (color[v]\
    \ != 0) { V1[max(i - n0, 0)] = vs[v], rea1[max(i - n0, 0)] = real[v]; }\n  }\n\
    \  FOR(v, 1, N) {\n    int a = ord[v], b = ord[par[v]];\n    if (a > b) swap(a,\
    \ b);\n    par2[b] = a;\n    if (color[v] != 1 && color[par[v]] != 1) par0[b]\
    \ = a;\n    if (color[v] != 0 && color[par[v]] != 0) par1[max(b - n0, 0)] = max(a\
    \ - n0, 0);\n  }\n  color.assign(N, -1);\n  FOR(i, 1, N) if (rea2[i]) color[i]\
    \ = (i <= n0 ? 0 : 1);\n  if (real[c]) color[0] = 2, rea0[0] = rea1[0] = rea2[0]\
    \ = 0;\n  f(par2, V2, color);\n  centroid_decomposition_2_dfs(par0, V0, rea0,\
    \ f);\n  centroid_decomposition_2_dfs(par1, V1, rea1, f);\n}\n\n// 0: f(par, V,\
    \ indptr)\n// 1: f(par, V, L1, R1, L2, R2)\n// 2: f(par, V, color)\ntemplate <int\
    \ MODE, typename GT, typename F>\nvoid centroid_decomposition(GT& G, F f) {\n\
    \  static_assert(!GT::is_directed);\n  const int N = G.N;\n  if (MODE != 0 &&\
    \ N == 1) return;\n  vc<int> V(N), par(N, -1);\n  int l = 0, r = 0;\n  V[r++]\
    \ = 0;\n  while (l < r) {\n    int v = V[l++];\n    for (auto& e: G[v]) {\n  \
    \    if (e.to != par[v]) V[r++] = e.to, par[e.to] = v;\n    }\n  }\n  assert(r\
    \ == N);\n  vc<int> new_idx(N);\n  FOR(i, N) new_idx[V[i]] = i;\n  vc<int> tmp(N,\
    \ -1);\n  FOR(i, 1, N) {\n    int j = par[i];\n    tmp[new_idx[i]] = new_idx[j];\n\
    \  }\n  swap(par, tmp);\n  static_assert(MODE == 0 || MODE == 1 || MODE == 2);\n\
    \  if constexpr (MODE == 0) { centroid_decomposition_0_dfs(par, V, f); }\n  elif\
    \ constexpr(MODE == 1) { centroid_decomposition_1_dfs(par, V, f); }\n  else {\n\
    \    vc<int> real(N, 1);\n    centroid_decomposition_2_dfs(par, V, real, f);\n\
    \  }\n}\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/shortest_path/bfs01.hpp
  isVerificationFile: false
  path: graph/centroid_decomposition.hpp
  requiredBy:
  - graph/tree_all_distances.hpp
  - graph/ds/contour_query_range.hpp
  timestamp: '2024-12-25 20:50:37+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1038.test.cpp
  - test/3_yukicoder/1796_1.test.cpp
  - test/3_yukicoder/2892.test.cpp
  - test/2_library_checker/tree/frequency_table_of_tree_distance.test.cpp
  - test/2_library_checker/tree/frequency_table_of_tree_distance_2.test.cpp
  - test/2_library_checker/tree/frequency_table_of_tree_distance_0.test.cpp
  - test/2_library_checker/tree/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/2_library_checker/tree/vertex_get_range_contour_add_on_tree.test.cpp
documentation_of: graph/centroid_decomposition.hpp
layout: document
redirect_from:
- /library/graph/centroid_decomposition.hpp
- /library/graph/centroid_decomposition.hpp.html
title: graph/centroid_decomposition.hpp
---
