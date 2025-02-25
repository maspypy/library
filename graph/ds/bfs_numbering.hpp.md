---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/899.test.cpp
    title: test/3_yukicoder/899.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    #line 2 \"graph/ds/bfs_numbering.hpp\"\n\r\n// ID[v]\uFF1A\u9802\u70B9\u306E\u65B0\
    \u3057\u3044\u756A\u53F7\r\n// calc_range(v, dep)\uFF1Av \u306E\u90E8\u5206\u6728\
    \u3067\u3001\u6DF1\u3055 dep \u306E\u3082\u306E\u305F\u3061\u306E\u7BC4\u56F2\r\
    \n// \u6DF1\u3055\u306F\u7D76\u5BFE\u7684\u306A\u3082\u306E\u3067\u3042\u308B\u3053\
    \u3068\u306B\u6CE8\u610F\u305B\u3088\r\ntemplate <typename Graph>\r\nstruct BFS_Numbering\
    \ {\r\n  Graph& G;\r\n  int root;\r\n  vector<int> V;\r\n  vector<int> ID;\r\n\
    \  vector<int> depth;\r\n  vector<int> parent;\r\n  vector<int> LID, RID;\r\n\
    \  vector<int> LID_seq;\r\n  vector<int> dep_ids;\r\n  int cnt;\r\n\r\n  BFS_Numbering(Graph&\
    \ G, int root = 0) : G(G), root(root), cnt(0) { build(); }\r\n\r\n  void bfs()\
    \ {\r\n    deque<int> que = {root};\r\n    while (!que.empty()) {\r\n      int\
    \ v = POP(que);\r\n      ID[v] = V.size();\r\n      V.eb(v);\r\n      for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\r\n        if (to == parent[v]) continue;\r\n \
    \       que.eb(to), parent[to] = v, depth[to] = depth[v] + 1;\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  void dfs(int v) {\r\n    LID[v] = cnt++;\r\n    for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\r\n      if (to == parent[v]) continue;\r\n   \
    \   dfs(to);\r\n    }\r\n    RID[v] = cnt;\r\n  }\r\n\r\n  void build() {\r\n\
    \    int N = G.N;\r\n    V.reserve(N);\r\n    parent.assign(N, -1);\r\n    ID.assign(N,\
    \ 0), LID.assign(N, 0), RID.assign(N, 0), depth.assign(N, 0);\r\n    bfs();\r\n\
    \    dfs(root);\r\n    int D = MAX(depth);\r\n    dep_ids.resize(D + 2);\r\n \
    \   FOR(v, N) dep_ids[depth[v] + 1]++;\r\n    FOR(d, D + 1) dep_ids[d + 1] +=\
    \ dep_ids[d];\r\n    LID_seq.reserve(N);\r\n    FOR(i, N) LID_seq.eb(LID[V[i]]);\r\
    \n  }\r\n\r\n  // dep \u306F\u7D76\u5BFE\u7684\u306A\u6DF1\u3055\r\n  pair<int,\
    \ int> calc_range(int v, int dep) {\r\n    assert(dep >= depth[v]);\r\n    if\
    \ (dep >= len(dep_ids) - 1) return {0, 0};\r\n    int l = LID[v], r = RID[v];\r\
    \n    int L = dep_ids[dep], R = dep_ids[dep + 1];\r\n    int a = bs(L - 1, R,\
    \ l);\r\n    int b = bs(L - 1, R, r);\r\n    return {a, b};\r\n  }\r\n\r\n  //\
    \ dist(p,v)<=r\r\n  vc<pair<int, int>> disk_range(int v, int r) {\r\n    if (r\
    \ < 0) return {};\r\n    vc<pair<int, int>> res;\r\n    int d = depth[v];\r\n\
    \    FOR(k, r + 1) {\r\n      if (v == -1) break;\r\n      int hi = d + r - k;\r\
    \n      int lo = hi - 1;\r\n      chmax(lo, d);\r\n      if (parent[v] == -1)\
    \ lo = 0;\r\n      FOR(i, lo, hi + 1) { res.eb(calc_range(v, i)); }\r\n      v\
    \ = parent[v], d = d - 1;\r\n    }\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  int bs(int L, int R, int x) {\r\n    while (L + 1 < R) {\r\n      int M =\
    \ (L + R) / 2;\r\n      if (LID_seq[M] >= x)\r\n        R = M;\r\n      else\r\
    \n        L = M;\r\n    }\r\n    return R;\r\n  }\r\n};\r\n"
  code: "#include \"graph/base.hpp\"\r\n\r\n// ID[v]\uFF1A\u9802\u70B9\u306E\u65B0\
    \u3057\u3044\u756A\u53F7\r\n// calc_range(v, dep)\uFF1Av \u306E\u90E8\u5206\u6728\
    \u3067\u3001\u6DF1\u3055 dep \u306E\u3082\u306E\u305F\u3061\u306E\u7BC4\u56F2\r\
    \n// \u6DF1\u3055\u306F\u7D76\u5BFE\u7684\u306A\u3082\u306E\u3067\u3042\u308B\u3053\
    \u3068\u306B\u6CE8\u610F\u305B\u3088\r\ntemplate <typename Graph>\r\nstruct BFS_Numbering\
    \ {\r\n  Graph& G;\r\n  int root;\r\n  vector<int> V;\r\n  vector<int> ID;\r\n\
    \  vector<int> depth;\r\n  vector<int> parent;\r\n  vector<int> LID, RID;\r\n\
    \  vector<int> LID_seq;\r\n  vector<int> dep_ids;\r\n  int cnt;\r\n\r\n  BFS_Numbering(Graph&\
    \ G, int root = 0) : G(G), root(root), cnt(0) { build(); }\r\n\r\n  void bfs()\
    \ {\r\n    deque<int> que = {root};\r\n    while (!que.empty()) {\r\n      int\
    \ v = POP(que);\r\n      ID[v] = V.size();\r\n      V.eb(v);\r\n      for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\r\n        if (to == parent[v]) continue;\r\n \
    \       que.eb(to), parent[to] = v, depth[to] = depth[v] + 1;\r\n      }\r\n \
    \   }\r\n  }\r\n\r\n  void dfs(int v) {\r\n    LID[v] = cnt++;\r\n    for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\r\n      if (to == parent[v]) continue;\r\n   \
    \   dfs(to);\r\n    }\r\n    RID[v] = cnt;\r\n  }\r\n\r\n  void build() {\r\n\
    \    int N = G.N;\r\n    V.reserve(N);\r\n    parent.assign(N, -1);\r\n    ID.assign(N,\
    \ 0), LID.assign(N, 0), RID.assign(N, 0), depth.assign(N, 0);\r\n    bfs();\r\n\
    \    dfs(root);\r\n    int D = MAX(depth);\r\n    dep_ids.resize(D + 2);\r\n \
    \   FOR(v, N) dep_ids[depth[v] + 1]++;\r\n    FOR(d, D + 1) dep_ids[d + 1] +=\
    \ dep_ids[d];\r\n    LID_seq.reserve(N);\r\n    FOR(i, N) LID_seq.eb(LID[V[i]]);\r\
    \n  }\r\n\r\n  // dep \u306F\u7D76\u5BFE\u7684\u306A\u6DF1\u3055\r\n  pair<int,\
    \ int> calc_range(int v, int dep) {\r\n    assert(dep >= depth[v]);\r\n    if\
    \ (dep >= len(dep_ids) - 1) return {0, 0};\r\n    int l = LID[v], r = RID[v];\r\
    \n    int L = dep_ids[dep], R = dep_ids[dep + 1];\r\n    int a = bs(L - 1, R,\
    \ l);\r\n    int b = bs(L - 1, R, r);\r\n    return {a, b};\r\n  }\r\n\r\n  //\
    \ dist(p,v)<=r\r\n  vc<pair<int, int>> disk_range(int v, int r) {\r\n    if (r\
    \ < 0) return {};\r\n    vc<pair<int, int>> res;\r\n    int d = depth[v];\r\n\
    \    FOR(k, r + 1) {\r\n      if (v == -1) break;\r\n      int hi = d + r - k;\r\
    \n      int lo = hi - 1;\r\n      chmax(lo, d);\r\n      if (parent[v] == -1)\
    \ lo = 0;\r\n      FOR(i, lo, hi + 1) { res.eb(calc_range(v, i)); }\r\n      v\
    \ = parent[v], d = d - 1;\r\n    }\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  int bs(int L, int R, int x) {\r\n    while (L + 1 < R) {\r\n      int M =\
    \ (L + R) / 2;\r\n      if (LID_seq[M] >= x)\r\n        R = M;\r\n      else\r\
    \n        L = M;\r\n    }\r\n    return R;\r\n  }\r\n};\r\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/ds/bfs_numbering.hpp
  requiredBy: []
  timestamp: '2024-12-25 20:50:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/899.test.cpp
documentation_of: graph/ds/bfs_numbering.hpp
layout: document
redirect_from:
- /library/graph/ds/bfs_numbering.hpp
- /library/graph/ds/bfs_numbering.hpp.html
title: graph/ds/bfs_numbering.hpp
---
