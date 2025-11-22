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
    path: graph/block_cut.hpp
    title: graph/block_cut.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/bfs01.hpp
    title: graph/shortest_path/bfs01.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/restore_path.hpp
    title: graph/shortest_path/restore_path.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/st_numbering.test.cpp
    title: test/1_mytest/st_numbering.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/st_numbering.test.cpp
    title: test/2_library_checker/graph/st_numbering.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Bipolar_orientation
  bundledCode: "#line 1 \"graph/st_numbering.hpp\"\n\n#line 2 \"ds/hashmap.hpp\"\n\
    \r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\
    \u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32\
    \ n = 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while\
    \ (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\
    \u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\
    \u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap\
    \ = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\
    \r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val&\
    \ operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\
    \n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\
    \n    int i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n\
    \  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return\
    \ used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename\
    \ F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i],\
    \ val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val>\
    \ val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64\
    \ FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
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
    \    return A;\n  }\n};\n#line 2 \"graph/block_cut.hpp\"\n\n/*\nblock-cut tree\
    \ \u3092\u3001block \u306B\u901A\u5E38\u306E\u9802\u70B9\u3092\u96A3\u63A5\u3055\
    \u305B\u3066\u62E1\u5F35\u3057\u3066\u304A\u304F\nhttps://twitter.com/noshi91/status/1529858538650374144?s=20&t=eznpFbuD9BDhfTb4PplFUg\n\
    [0, n)\uFF1A\u3082\u3068\u306E\u9802\u70B9 [n, n + n_block)\uFF1Ablock\n\u95A2\
    \u7BC0\u70B9\uFF1A[0, n) \u306E\u3046\u3061\u3067\u3001degree >= 2 \u3092\u6E80\
    \u305F\u3059\u3082\u306E\n\u5B64\u7ACB\u70B9\u306F\u30011 \u70B9\u3060\u3051\u304B\
    \u3089\u306A\u308B block\n\u6210\u5206\u304C\u6B32\u3057\u3044\u5834\u5408\uFF1A\
    \u8FD1\u508D\u3092\u898B\u308B\u3068\u70B9\u96C6\u5408. \u8FBA\u304B\u3089\u6210\
    \u5206\u3092\u5F97\u308B\u306B\u306F tree.jump\n\u3068\u601D\u3063\u305F\u304C\
    \u975E\u9023\u7D50\u306A\u3068\u304D\u306B\u6CE8\u610F\u304C\u3044\u308B\u306A\
    \u2026\n*/\ntemplate <typename GT>\nGraph<int, 0> block_cut(GT& G) {\n  int n\
    \ = G.N;\n  vc<int> low(n), ord(n), st;\n  vc<bool> used(n);\n  st.reserve(n);\n\
    \  int nxt = n;\n  int k = 0;\n  vc<pair<int, int>> edges;\n\n  auto dfs = [&](auto&\
    \ dfs, int v, int p) -> void {\n    st.eb(v);\n    used[v] = 1;\n    low[v] =\
    \ ord[v] = k++;\n    int child = 0;\n    for (auto&& e: G[v]) {\n      if (e.to\
    \ == p) continue;\n      if (!used[e.to]) {\n        ++child;\n        int s =\
    \ len(st);\n        dfs(dfs, e.to, v);\n        chmin(low[v], low[e.to]);\n  \
    \      if ((p == -1 && child > 1) || (p != -1 && low[e.to] >= ord[v])) {\n   \
    \       edges.eb(nxt, v);\n          while (len(st) > s) {\n            edges.eb(nxt,\
    \ st.back());\n            st.pop_back();\n          }\n          ++nxt;\n   \
    \     }\n      } else {\n        chmin(low[v], ord[e.to]);\n      }\n    }\n \
    \ };\n  FOR(v, n) if (!used[v]) {\n    dfs(dfs, v, -1);\n    for (auto&& x: st)\
    \ { edges.eb(nxt, x); }\n    ++nxt;\n    st.clear();\n  }\n  Graph<int, 0> BCT(nxt);\n\
    \  for (auto&& [a, b]: edges) BCT.add(a, b);\n  BCT.build();\n  return BCT;\n\
    }\n#line 3 \"graph/shortest_path/bfs01.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\npair<vc<T>, vc<int>> bfs01(GT& G, int v) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  deque<int>\
    \ que;\n\n  dist[v] = 0;\n  que.push_front(v);\n  while (!que.empty()) {\n   \
    \ auto v = que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n  \
    \    if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n    \
    \    dist[e.to] = dist[e.frm] + e.cost;\n        par[e.to] = e.frm;\n        if\
    \ (e.cost == 0)\n          que.push_front(e.to);\n        else\n          que.push_back(e.to);\n\
    \      }\n    }\n  }\n  return {dist, par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\
    \u30C8\u3002[dist, par, root]\ntemplate <typename T, typename GT>\ntuple<vc<T>,\
    \ vc<int>, vc<int>> bfs01(GT& G, vc<int> vs) {\n  assert(G.is_prepared());\n \
    \ int N = G.N;\n  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  vc<int> root(N,\
    \ -1);\n  deque<int> que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v]\
    \ = v;\n    que.push_front(v);\n  }\n\n  while (!que.empty()) {\n    auto v =\
    \ que.front();\n    que.pop_front();\n    for (auto&& e: G[v]) {\n      if (dist[e.to]\
    \ == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {\n        dist[e.to] = dist[e.frm]\
    \ + e.cost;\n        root[e.to] = root[e.frm];\n        par[e.to] = e.frm;\n \
    \       if (e.cost == 0)\n          que.push_front(e.to);\n        else\n    \
    \      que.push_back(e.to);\n      }\n    }\n  }\n  return {dist, par, root};\n\
    }\n#line 1 \"graph/shortest_path/restore_path.hpp\"\nvector<int> restore_path(vector<int>\
    \ par, int t){\r\n  vector<int> pth = {t};\r\n  while (par[pth.back()] != -1)\
    \ pth.eb(par[pth.back()]);\r\n  reverse(all(pth));\r\n  return pth;\r\n}\n#line\
    \ 7 \"graph/st_numbering.hpp\"\n\n// https://en.wikipedia.org/wiki/Bipolar_orientation\n\
    // \u9806\u5217 p \u3092\u6C42\u3081\u308B. p[s]=0,p[t]=n-1.\n// p[u]<p[v] \u3068\
    \u306A\u308B\u5411\u304D\u306B\u8FBA\u3092\u5411\u304D\u4ED8\u3051\u308B\u3068\
    \u4EFB\u610F\u306E v \u306B\u5BFE\u3057\u3066 svt \u30D1\u30B9\u304C\u5B58\u5728\
    .\n// \u5B58\u5728\u6761\u4EF6\uFF1ABCT \u3067\u5168\u90E8\u306E\u6210\u5206\u3092\
    \u901A\u308B st \u30D1\u30B9\u304C\u3042\u308B \u4E0D\u53EF\u80FD\u306A\u3089\u3070\
    \ empty \u3092\u304B\u3048\u3059.\ntemplate <typename GT>\nvc<int> st_numbering(GT\
    \ &G, int s, int t) {\n  static_assert(!GT::is_directed);\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  if (N == 1) return {0};\n  if (s == t) return {};\n  vc<int>\
    \ par(N, -1), pre(N, -1), low(N, -1);\n  vc<int> V;\n\n  auto dfs = [&](auto &dfs,\
    \ int v) -> void {\n    pre[v] = len(V), V.eb(v);\n    low[v] = v;\n    for (auto\
    \ &e: G[v]) {\n      int w = e.to;\n      if (v == w) continue;\n      if (pre[w]\
    \ == -1) {\n        dfs(dfs, w);\n        par[w] = v;\n        if (pre[low[w]]\
    \ < pre[low[v]]) { low[v] = low[w]; }\n      }\n      elif (pre[w] < pre[low[v]])\
    \ { low[v] = w; }\n    }\n  };\n\n  pre[s] = 0, V.eb(s);\n  dfs(dfs, t);\n  if\
    \ (len(V) != N) return {};\n  vc<int> nxt(N, -1), prev(N);\n  nxt[s] = t, prev[t]\
    \ = s;\n\n  vc<int> sgn(N);\n  sgn[s] = -1;\n  FOR(i, 2, len(V)) {\n    int v\
    \ = V[i];\n    int p = par[v];\n    if (sgn[low[v]] == -1) {\n      int q = prev[p];\n\
    \      if (q == -1) return {};\n      nxt[q] = v, nxt[v] = p;\n      prev[v] =\
    \ q, prev[p] = v;\n      sgn[p] = 1;\n    } else {\n      int q = nxt[p];\n  \
    \    if (q == -1) return {};\n      nxt[p] = v, nxt[v] = q;\n      prev[v] = p,\
    \ prev[q] = v;\n      sgn[p] = -1;\n    }\n  }\n  vc<int> A = {s};\n  while (A.back()\
    \ != t) { A.eb(nxt[A.back()]); }\n  // \u4F5C\u308C\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\n  if (len(A) < N) return {};\n  assert(A[0] == s && A.back() == t);\n\
    \  vc<int> rk(N, -1);\n  FOR(i, N) rk[A[i]] = i;\n  assert(MIN(rk) != -1);\n \
    \ FOR(i, N) {\n    bool l = 0, r = 0;\n    int v = A[i];\n    for (auto &e: G[v])\
    \ {\n      if (rk[e.to] < rk[v]) l = 1;\n      if (rk[v] < rk[e.to]) r = 1;\n\
    \    }\n    if (i > 0 && !l) return {};\n    if (i < N - 1 && !r) return {};\n\
    \  }\n  vc<int> res(N);\n  FOR(i, N) res[A[i]] = i;\n  return res;\n}\n\nbool\
    \ check_st_numbering(Graph<int, 0> G, int s, int t) {\n  int N = G.N;\n  assert(N\
    \ >= 2);\n  if (s == t) return 0;\n\n  UnionFind uf(N);\n  for (auto &e: G.edges)\
    \ uf.merge(e.frm, e.to);\n  if (uf.n_comp >= 2) return 0; // disconnected\n\n\
    \  // BCT \u306B\u304A\u3044\u3066 st \u30D1\u30B9\u304C\u3059\u3079\u3066\u306E\
    \ block \u3092\u901A\u308B\u3053\u3068\u304C\u5FC5\u8981\n  auto BCT = block_cut(G);\n\
    \  auto [dist, par] = bfs01<int>(BCT, s);\n  vc<int> path = restore_path(par,\
    \ t);\n\n  vc<int> vis(BCT.N);\n  for (auto &x: path) vis[x] = 1;\n\n  FOR(i,\
    \ N, BCT.N) {\n    if (!vis[i]) return 0;\n  }\n  return 1;\n}\n"
  code: "\n#include \"graph/base.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n\
    #include \"graph/block_cut.hpp\"\n#include \"graph/shortest_path/bfs01.hpp\"\n\
    #include \"graph/shortest_path/restore_path.hpp\"\n\n// https://en.wikipedia.org/wiki/Bipolar_orientation\n\
    // \u9806\u5217 p \u3092\u6C42\u3081\u308B. p[s]=0,p[t]=n-1.\n// p[u]<p[v] \u3068\
    \u306A\u308B\u5411\u304D\u306B\u8FBA\u3092\u5411\u304D\u4ED8\u3051\u308B\u3068\
    \u4EFB\u610F\u306E v \u306B\u5BFE\u3057\u3066 svt \u30D1\u30B9\u304C\u5B58\u5728\
    .\n// \u5B58\u5728\u6761\u4EF6\uFF1ABCT \u3067\u5168\u90E8\u306E\u6210\u5206\u3092\
    \u901A\u308B st \u30D1\u30B9\u304C\u3042\u308B \u4E0D\u53EF\u80FD\u306A\u3089\u3070\
    \ empty \u3092\u304B\u3048\u3059.\ntemplate <typename GT>\nvc<int> st_numbering(GT\
    \ &G, int s, int t) {\n  static_assert(!GT::is_directed);\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  if (N == 1) return {0};\n  if (s == t) return {};\n  vc<int>\
    \ par(N, -1), pre(N, -1), low(N, -1);\n  vc<int> V;\n\n  auto dfs = [&](auto &dfs,\
    \ int v) -> void {\n    pre[v] = len(V), V.eb(v);\n    low[v] = v;\n    for (auto\
    \ &e: G[v]) {\n      int w = e.to;\n      if (v == w) continue;\n      if (pre[w]\
    \ == -1) {\n        dfs(dfs, w);\n        par[w] = v;\n        if (pre[low[w]]\
    \ < pre[low[v]]) { low[v] = low[w]; }\n      }\n      elif (pre[w] < pre[low[v]])\
    \ { low[v] = w; }\n    }\n  };\n\n  pre[s] = 0, V.eb(s);\n  dfs(dfs, t);\n  if\
    \ (len(V) != N) return {};\n  vc<int> nxt(N, -1), prev(N);\n  nxt[s] = t, prev[t]\
    \ = s;\n\n  vc<int> sgn(N);\n  sgn[s] = -1;\n  FOR(i, 2, len(V)) {\n    int v\
    \ = V[i];\n    int p = par[v];\n    if (sgn[low[v]] == -1) {\n      int q = prev[p];\n\
    \      if (q == -1) return {};\n      nxt[q] = v, nxt[v] = p;\n      prev[v] =\
    \ q, prev[p] = v;\n      sgn[p] = 1;\n    } else {\n      int q = nxt[p];\n  \
    \    if (q == -1) return {};\n      nxt[p] = v, nxt[v] = q;\n      prev[v] = p,\
    \ prev[q] = v;\n      sgn[p] = -1;\n    }\n  }\n  vc<int> A = {s};\n  while (A.back()\
    \ != t) { A.eb(nxt[A.back()]); }\n  // \u4F5C\u308C\u3066\u3044\u308B\u304B\u5224\
    \u5B9A\n  if (len(A) < N) return {};\n  assert(A[0] == s && A.back() == t);\n\
    \  vc<int> rk(N, -1);\n  FOR(i, N) rk[A[i]] = i;\n  assert(MIN(rk) != -1);\n \
    \ FOR(i, N) {\n    bool l = 0, r = 0;\n    int v = A[i];\n    for (auto &e: G[v])\
    \ {\n      if (rk[e.to] < rk[v]) l = 1;\n      if (rk[v] < rk[e.to]) r = 1;\n\
    \    }\n    if (i > 0 && !l) return {};\n    if (i < N - 1 && !r) return {};\n\
    \  }\n  vc<int> res(N);\n  FOR(i, N) res[A[i]] = i;\n  return res;\n}\n\nbool\
    \ check_st_numbering(Graph<int, 0> G, int s, int t) {\n  int N = G.N;\n  assert(N\
    \ >= 2);\n  if (s == t) return 0;\n\n  UnionFind uf(N);\n  for (auto &e: G.edges)\
    \ uf.merge(e.frm, e.to);\n  if (uf.n_comp >= 2) return 0; // disconnected\n\n\
    \  // BCT \u306B\u304A\u3044\u3066 st \u30D1\u30B9\u304C\u3059\u3079\u3066\u306E\
    \ block \u3092\u901A\u308B\u3053\u3068\u304C\u5FC5\u8981\n  auto BCT = block_cut(G);\n\
    \  auto [dist, par] = bfs01<int>(BCT, s);\n  vc<int> path = restore_path(par,\
    \ t);\n\n  vc<int> vis(BCT.N);\n  for (auto &x: path) vis[x] = 1;\n\n  FOR(i,\
    \ N, BCT.N) {\n    if (!vis[i]) return 0;\n  }\n  return 1;\n}\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/unionfind/unionfind.hpp
  - graph/block_cut.hpp
  - graph/shortest_path/bfs01.hpp
  - graph/shortest_path/restore_path.hpp
  isVerificationFile: false
  path: graph/st_numbering.hpp
  requiredBy: []
  timestamp: '2025-04-06 22:14:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/st_numbering.test.cpp
  - test/2_library_checker/graph/st_numbering.test.cpp
documentation_of: graph/st_numbering.hpp
layout: document
redirect_from:
- /library/graph/st_numbering.hpp
- /library/graph/st_numbering.hpp.html
title: graph/st_numbering.hpp
---
