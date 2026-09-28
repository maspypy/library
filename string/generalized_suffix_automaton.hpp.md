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
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':x:'
    path: string/trie.hpp
    title: string/trie.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/generalized_suffix_automaton.hpp\"\n\n#line 1 \"\
    graph/tree.hpp\"\n\n#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename\
    \ Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\
    \u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n)\
    \ {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k\
    \ - 1;\n    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\n  // size\
    \ \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F\
    \ build \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used),\
    \ 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap;\
    \ }\n\n  int index(const u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {\n    }\n    return i;\n  }\n\n  Val& operator[](const\
    \ u64& k) {\n    int i = index(k);\n    if (used[i]) return val[i];\n    if (cap\
    \ == 0) extend(), i = index(k);\n    used[i] = 1, key[i] = k, val[i] = Val{},\
    \ --cap;\n    return val[i];\n  }\n\n  Val get(const u64& k, Val default_value)\
    \ {\n    int i = index(k);\n    return (used[i] ? val[i] : default_value);\n \
    \ }\n\n  bool count(const u64& k) {\n    int i = index(k);\n    return used[i]\
    \ && key[i] == k;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\n  }\n\n private:\n\
    \  u32 cap, mask;\n  vc<u64> key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64\
    \ x) {\n    static const u64 FIXED_RANDOM =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b] : dat) (*this)[a] = b;\n\
    \  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  mutable vc<int>\
    \ vc_deg, vc_indeg, vc_outdeg;\n  mutable HashMap<int> MP_FOR_EID;\n  bool prepared;\n\
    \n  class OutgoingEdges {\n   public:\n    OutgoingEdges(const Graph* G, int l,\
    \ int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n     \
    \ if (l == r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n\
    \    }\n\n    const edge_type* end() const {\n      if (l == r) {\n        return\
    \ 0;\n      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const\
    \ Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() const { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n    MP_FOR_EID.clear();\n  }\n\n  void add(int frm, int\
    \ to, T cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm &&\
    \ frm < N && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n\
    \  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off);\
    \ }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n    for (int\
    \ m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n      if\
    \ (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e : edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) {\n      indptr[v\
    \ + 1] += indptr[v];\n    }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e : edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() const {\n    if (vc_deg.empty()) calc_deg();\n    return\
    \ vc_deg;\n  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() const {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ const {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n\
    \  int in_deg(int v) const {\n    if (vc_indeg.empty()) calc_deg_inout();\n  \
    \  return vc_indeg[v];\n  }\n\n  int out_deg(int v) const {\n    if (vc_outdeg.empty())\
    \ calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug()\
    \ {\n#ifdef LOCAL\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n    flush();\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e : (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid : history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) const {\n    if (root == -1)\
    \ root = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T,\
    \ true> G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v)\
    \ -> void {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) const\
    \ {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for\
    \ (auto& e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) const {\n    if (!directed &&\
    \ a > b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg()\
    \ const {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&&\
    \ e : edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ const {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e : edges) {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n \
    \   }\n  }\n};\n#line 3 \"graph/tree.hpp\"\n\n// HLD euler tour \u3092\u3068\u3063\
    \u3066\u3044\u308D\u3044\u308D\n// HLD=false: \u5165\u529B\u8FBA\u9806\u3067 preorder\n\
    template <typename GT, bool HLD = true>\nstruct Tree {\n  using Graph_type = GT;\n\
    \  using WT = typename GT::cost_type;\n  int N = 0;\n  vector<int> LID, RID, head,\
    \ V, parent, VtoE, EtoV;\n  vc<int> depth;\n  vc<WT> depth_weighted;\n  vc<int>\
    \ memo_tail;\n\n  Tree() = default;\n  Tree(const GT &G, int r = 0) { build(G,\
    \ r); }\n\n  void build(const GT &G, int r = 0) {\n    N = G.N;\n    assert(G.is_prepared());\n\
    \    assert(G.M == N - 1);\n    FOR(i, N - 1) assert(G.edges[i].id == i);\n  \
    \  assert(0 <= r && r < N);\n    if constexpr (!HLD)\n      build_simple(G, r);\n\
    \    else\n      build_HLD(G, r);\n  }\n\n  vc<int> heavy_path_at(int v) const\
    \ {\n    static_assert(HLD);\n    assert(head[v] == v);\n    int k = LID[v];\n\
    \    vc<int> P;\n    while (k < N && head[V[k]] == v) P.eb(V[k++]);\n    return\
    \ P;\n  }\n\n  int heavy_child(int v) const {\n    static_assert(HLD);\n    if\
    \ (RID[v] == LID[v] + 1) return -1;\n    return V[LID[v] + 1];\n  }\n\n  int tail(int\
    \ v) {\n    static_assert(HLD);\n    if (memo_tail.empty()) {\n      memo_tail.assign(N,\
    \ -1);\n      FOR_R(i, N) {\n        int v = V[i];\n        int w = heavy_child(v);\n\
    \        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\n      }\n    }\n    return\
    \ memo_tail[v];\n  }\n\n  int e_to_v(int eid) const { return EtoV[eid]; }\n  int\
    \ v_to_e(int v) const { return VtoE[v]; }\n  int get_eid(int u, int v) const {\n\
    \    if (parent[u] != v) swap(u, v);\n    assert(parent[u] == v);\n    return\
    \ VtoE[u];\n  }\n\n  int ELID(int v) const { return 2 * LID[v] - depth[v]; }\n\
    \  int ERID(int v) const { return 2 * RID[v] - depth[v] - 1; }\n\n  // \u76EE\u6A19\
    \u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\n  int LA(int v, int k) const\
    \ {\n    static_assert(HLD);\n    assert(k <= depth[v]);\n    while (1) {\n  \
    \    int u = head[v];\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\n\
    \      k -= LID[v] - LID[u] + 1;\n      v = parent[u];\n    }\n  }\n\n  int LCA(int\
    \ u, int v) const {\n    static_assert(HLD);\n    for (;; v = parent[head[v]])\
    \ {\n      if (LID[u] > LID[v]) swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n    }\n  }\n\n  int meet(int a, int b, int c) const {\n    static_assert(HLD);\n\
    \    return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\n  }\n\n  int subtree_size(int\
    \ v) const { return RID[v] - LID[v]; }\n\n  int subtree_size(int v, int root)\
    \ const {\n    static_assert(HLD);\n    if (v == root) return N;\n    int x =\
    \ jump(v, root, 1);\n    if (in_subtree(v, x)) return RID[v] - LID[v];\n    return\
    \ N - RID[x] + LID[x];\n  }\n\n  int dist(int a, int b) const {\n    static_assert(HLD);\n\
    \    int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\
    \n  WT dist_weighted(int a, int b) const {\n    static_assert(HLD);\n    int c\
    \ = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\n\
    \  }\n\n  // a is in b\n  bool in_subtree(int a, int b) const {\n    return LID[b]\
    \ <= LID[a] && LID[a] < RID[b];\n  }\n\n  int jump(int a, int b, ll k) const {\n\
    \    static_assert(HLD);\n    if (k == 1) {\n      if (a == b) return -1;\n  \
    \    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n\
    \    }\n    int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc\
    \ = depth[b] - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac)\
    \ return LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) const {\n    vc<int> res;\n    for (int k = LID[v] + 1; k < RID[v];) {\n\
    \      res.eb(V[k]), k = RID[V[k]];\n    }\n    return res;\n  }\n\n  vc<int>\
    \ collect_subtree(int v) const {\n    return {V.begin() + LID[v], V.begin() +\
    \ RID[v]};\n  }\n\n  vc<int> collect_light(int v) const {\n    static_assert(HLD);\n\
    \    vc<int> res;\n    for (int k = LID[v] + 1; k < RID[v];) {\n      if (head[V[k]]\
    \ == V[k]) res.eb(V[k]);\n      k = RID[V[k]];\n    }\n    return res;\n  }\n\n\
    \  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge) const {\n\
    \    static_assert(HLD);\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\
    \u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n    while (1) {\n\
    \      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v]) {\n        down.eb(LID[head[v]],\
    \ LID[v]);\n        v = parent[head[v]];\n      } else {\n        up.eb(LID[u],\
    \ LID[head[u]]);\n        u = parent[head[u]];\n      }\n    }\n    if (LID[u]\
    \ < LID[v]) down.eb(LID[u] + edge, LID[v]);\n    elif (LID[v] + edge <= LID[u])\
    \ up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n    up.insert(up.end(),\
    \ all(down));\n    return up;\n  }\n\n  // \u8FBA\u306E\u5217\u306E\u60C5\u5831\
    \ (frm,to,str)\n  // str = \"heavy_up\", \"heavy_down\", \"light_up\", \"light_down\"\
    \n  vc<tuple<int, int, string>> get_path_decomposition_detail(\n      int u, int\
    \ v) const {\n    static_assert(HLD);\n    vc<tuple<int, int, string>> up, down;\n\
    \    while (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v])\
    \ {\n        if (v != head[v]) down.eb(head[v], v, \"heavy_down\"), v = head[v];\n\
    \        down.eb(parent[v], v, \"light_down\"), v = parent[v];\n      } else {\n\
    \        if (u != head[u]) up.eb(u, head[u], \"heavy_up\"), u = head[u];\n   \
    \     up.eb(u, parent[u], \"light_up\"), u = parent[u];\n      }\n    }\n    if\
    \ (LID[u] < LID[v]) down.eb(u, v, \"heavy_down\");\n    elif (LID[v] < LID[u])\
    \ up.eb(u, v, \"heavy_up\");\n    reverse(all(down));\n    concat(up, down);\n\
    \    return up;\n  }\n\n  vc<int> restore_path(int u, int v) const {\n    vc<int>\
    \ L, R;\n    while (depth[u] > depth[v]) L.eb(u), u = parent[u];\n    while (depth[u]\
    \ < depth[v]) R.eb(v), v = parent[v];\n    while (u != v) L.eb(u), R.eb(v), u\
    \ = parent[u], v = parent[v];\n    L.eb(u);\n    while (len(R)) L.eb(POP(R));\n\
    \    return L;\n  }\n\n  // path [a,b] \u3068 [c,d] \u306E\u4EA4\u308F\u308A.\
    \ \u7A7A\u306A\u3089\u3070 {-1,-1}.\n  // https://codeforces.com/problemset/problem/500/G\n\
    \  pair<int, int> path_intersection(int a, int b, int c, int d) const {\n    static_assert(HLD);\n\
    \    int ab = LCA(a, b), ac = LCA(a, c), ad = LCA(a, d);\n    int bc = LCA(b,\
    \ c), bd = LCA(b, d), cd = LCA(c, d);\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^\
    \ bd;  // meet(a,b,c), meet(a,b,d)\n    if (x != y) return {x, y};\n    int z\
    \ = ac ^ ad ^ cd;\n    if (x != z) x = -1;\n    return {x, x};\n  }\n\n  // uv\
    \ path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E v\n  //\
    \ \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C ng \uFF09\
    -1\n  template <class F>\n  int max_path(F check, int u, int v) const {\n    static_assert(HLD);\n\
    \    if (!check(u)) return -1;\n    auto pd = get_path_decomposition(u, v, false);\n\
    \    for (auto [a, b] : pd) {\n      if (!check(V[a])) return u;\n      if (check(V[b]))\
    \ {\n        u = V[b];\n        continue;\n      }\n      int c =\n          binary_search([&](int\
    \ c) -> bool { return check(V[c]); }, a, b, 0);\n      return V[c];\n    }\n \
    \   return u;\n  }\n\n private:\n  void build_simple(const GT &G, int r = 0) {\n\
    \    N = G.N;\n    LID.assign(N, 0), RID.assign(N, 0);\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1),\n        EtoV.assign(N - 1, -1);\n    depth.assign(N,\
    \ 0), depth_weighted.assign(N, 0);\n\n    // 1st dfs.\n    int k = 0;\n    vc<int>\
    \ st;\n    st.reserve(N);\n    st.eb(r);\n    while (len(st)) {\n      int v =\
    \ POP(st);\n      LID[v] = k, V[k] = v;\n      ++k;\n      for (int i = G.indptr[v\
    \ + 1] - 1; i >= G.indptr[v]; --i) {\n        auto &e = G.csr_edges[i];\n    \
    \    if (e.to == parent[v]) continue;\n        parent[e.to] = v;\n        depth[e.to]\
    \ = depth[v] + 1;\n        depth_weighted[e.to] = depth_weighted[v] + e.cost;\n\
    \        VtoE[e.to] = e.id, EtoV[e.id] = e.to;\n        st.eb(e.to);\n      }\n\
    \    }\n\n    FOR_R(i, N) {\n      int v = V[i];\n      chmax(RID[v], LID[v] +\
    \ 1);\n      if (parent[v] != -1) chmax(RID[parent[v]], RID[v]);\n    }\n  }\n\
    \n  void build_HLD(const GT &G, int r = 0) {\n    N = G.N;\n    LID.assign(N,\
    \ 0), RID.assign(N, 0), head.assign(N, r);\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1),\n        EtoV.assign(N - 1, -1);\n    depth.assign(N,\
    \ 0), depth_weighted.assign(N, 0);\n    memo_tail.clear();\n\n    // 1st dfs.\n\
    \    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n      st.eb(r);\n\
    \      while (len(st)) {\n        int v = POP(st);\n        V[k++] = v;\n    \
    \    for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n    \
    \      parent[e.to] = v, st.eb(e.to), depth[e.to] = depth[v] + 1;\n          depth_weighted[e.to]\
    \ = depth_weighted[v] + e.cost;\n          VtoE[e.to] = e.id, EtoV[e.id] = e.to;\n\
    \        }\n      }\n      // \u4E00\u6642\u7684\u306B RID[v] := sz[v]\n     \
    \ FOR_R(i, N) {\n        int v = V[i];\n        RID[v] += 1;\n        if (parent[v]\
    \ != -1) RID[parent[v]] += RID[v];\n      }\n    }\n    // 2nd dfs.\n    {\n \
    \     int k = 0;\n      vc<int> st;\n      st.reserve(N);\n      st.eb(r);\n \
    \     while (len(st)) {\n        int v = POP(st);\n        V[k] = v, LID[v] =\
    \ k;\n        RID[v] = k + RID[v];\n        ++k;\n        int max_sz = 0, max_ch\
    \ = -1;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          if (chmax(max_sz, RID[e.to])) max_ch = e.to;\n        }\n        for\
    \ (int i = G.indptr[v + 1] - 1; i >= G.indptr[v]; --i) {\n          auto &e =\
    \ G.csr_edges[i];\n          if (e.to == parent[v] || e.to == max_ch) continue;\n\
    \          st.eb(e.to), head[e.to] = e.to;\n        }\n        if (max_ch != -1)\
    \ st.eb(max_ch), head[max_ch] = head[v];\n      }\n    }\n  }\n};\n#line 1 \"\
    string/trie.hpp\"\n\r\n// sigma \u304C\u5C0F\u3055\u3044\r\n// \u4E00\u822C\u306E\
    \ n \u9802\u70B9\u306E\u6728\u69CB\u9020\u3067 O(n) \u6642\u9593\u3067\u52D5\u304F\
    \r\n// https://atcoder.jp/contests/xmascontest2015noon/tasks/xmascontest2015_d\r\
    \ntemplate <int sigma>\r\nstruct Trie {\r\n  struct Node {\r\n    array<int, sigma>\
    \ ch;\r\n    array<int, sigma> nxt; // suffix link -> add c\r\n    int parent;\r\
    \n    int suffix_link;\r\n  };\r\n  int n_node;\r\n  vc<Node> nodes;\r\n  vc<int>\
    \ words;\r\n  vc<int> BFS; // BFS \u9806\r\n\r\n  Trie() {\r\n    n_node = 0;\r\
    \n    new_node();\r\n  }\r\n\r\n  Node& operator[](int i) { return nodes[i]; }\r\
    \n\r\n  template <typename STRING>\r\n  int add(STRING S, int off) {\r\n    int\
    \ v = 0;\r\n    for (auto&& s: S) { v = add_single(v, s, off); }\r\n    words.eb(v);\r\
    \n    return v;\r\n  }\r\n\r\n  int add_single(int v, int c, int off) {\r\n  \
    \  c -= off;\r\n    assert(0 <= c && c < sigma);\r\n    if (nodes[v].ch[c] !=\
    \ -1) return nodes[v].ch[c];\r\n    nodes[v].ch[c] = new_node();\r\n    nodes.back().parent\
    \ = v;\r\n    return nodes[v].ch[c];\r\n  }\r\n\r\n  void calc_suffix_link() {\r\
    \n    BFS.resize(n_node);\r\n    int p = 0, q = 0;\r\n    BFS[q++] = 0;\r\n  \
    \  fill(all(nodes[0].nxt), 0);\r\n    while (p < q) {\r\n      int v = BFS[p++];\r\
    \n      if (v) nodes[v].nxt = nodes[nodes[v].suffix_link].nxt;\r\n      FOR(s,\
    \ sigma) {\r\n        int w = nodes[v].ch[s];\r\n        if (w == -1) continue;\r\
    \n        nodes[w].suffix_link = nodes[v].nxt[s];\r\n        nodes[v].nxt[s] =\
    \ w;\r\n        BFS[q++] = w;\r\n      }\r\n    }\r\n  }\r\n\r\n  vc<int> calc_count()\
    \ {\r\n    vc<int> count(n_node);\r\n    for (auto&& x: words) count[x]++;\r\n\
    \    for (auto&& v: BFS)\r\n      if (v) { count[v] += count[nodes[v].suffix_link];\
    \ }\r\n    return count;\r\n  }\r\n\r\nprivate:\r\n  int new_node() {\r\n    Node\
    \ c;\r\n    fill(all(c.ch), -1);\r\n    fill(all(c.nxt), -1);\r\n    c.parent\
    \ = -1;\r\n    c.suffix_link = -1;\r\n    nodes.eb(c);\r\n    return n_node++;\r\
    \n  }\r\n};\r\n#line 5 \"string/generalized_suffix_automaton.hpp\"\n\n/*\n\u5165\
    \u529B\uFF1A\u8907\u6570\u6587\u5B57\u5217 or trie\nO(|trie nodes|)\nnode \u756A\
    \u53F7\u306F topological \u9806\u306B\u4ED8\u3051\u76F4\u3057\u3066\u3044\u308B\
    \n*/\n\ntemplate <int sigma = 26>\nstruct Generalized_Suffix_Automaton {\n  struct\
    \ Node {\n    array<int, sigma> nxt;\n    int link;\n    int max_len;\n\n    Node(int\
    \ link, int max_len) : link(link), max_len(max_len) {\n      fill(all(nxt), -1);\n\
    \    }\n  };\n\n  using GT = Graph<int, 1>;\n  using TREE = Tree<GT>;\n\n  vc<Node>\
    \ nodes;\n  int n_node;\n\n  Node& operator[](int i) { return nodes[i]; }\n  const\
    \ Node& operator[](int i) const { return nodes[i]; }\n\n  Generalized_Suffix_Automaton()\
    \ {}\n\n  template <typename STRING>\n  Generalized_Suffix_Automaton(const vc<STRING>&\
    \ SS, int off) {\n    build(SS, off);\n  }\n\n  // n \u9802\u70B9 trie \u304B\u3089\
    \u69CB\u7BC9. O(n sigma).\n  void build(const Trie<sigma>& TRIE) {\n    int N\
    \ = TRIE.n_node;\n\n    nodes.clear();\n    vc<int> trie_pos(N, -1);\n    nodes.reserve(2\
    \ * N);\n\n    nodes.eb(-1, 0);\n    trie_pos[0] = 0;\n\n    // trie \u3092 BFS\
    \ (depth \u6607\u9806) \u3067\u51E6\u7406\u3059\u308B.\n    vc<int> que(N);\n\
    \    int ql = 0, qr = 0;\n    que[qr++] = 0;\n    while (ql < qr) {\n      int\
    \ v = que[ql++];\n      int p = trie_pos[v];\n      FOR(c, sigma) {\n        int\
    \ w = TRIE.nodes[v].ch[c];\n        if (w == -1) continue;\n        trie_pos[w]\
    \ = add_single(p, c);\n        que[qr++] = w;\n      }\n    }\n\n    normalize();\n\
    \  }\n\n  // \u8907\u6570\u6587\u5B57\u5217\u304B\u3089 trie \u3092\u4F5C\u308A\
    \u3001\u305D\u308C\u3092 generalized SAM \u306B\u3059\u308B.\n  template <typename\
    \ STRING>\n  void build(const vc<STRING>& SS, int off) {\n    Trie<sigma> TRIE;\n\
    \    for (auto& S : SS) TRIE.add(S, off);\n    build(TRIE);\n  }\n\n  // node\
    \ v \u304C\u8868\u3059\u6587\u5B57\u5217\u9577\u306E\u534A\u958B\u533A\u9593\n\
    \  pair<int, int> len_range(int v) const {\n    assert(0 <= v && v < len(nodes));\n\
    \    if (v == 0) return {0, 1};\n    return {nodes[nodes[v].link].max_len + 1,\
    \ nodes[v].max_len + 1};\n  }\n\n  // suffix-link tree\n  pair<GT, TREE> build_tree()\
    \ const {\n    int n = len(nodes);\n    GT G(n);\n    FOR(v, 1, n) G.add(nodes[v].link,\
    \ v);\n    G.build();\n    TREE tree(G, 0);\n    return {move(G), move(tree)};\n\
    \  }\n\n  // 1 \u6587\u5B57\u8AAD\u307F\u3001\u5165\u529B\u6587\u5B57\u5217\u7FA4\
    \u306E\u90E8\u5206\u6587\u5B57\u5217\u3067\u3042\u308B\u6700\u9577 suffix \u306B\
    \u9077\u79FB.\n  pair<int, int> next(pair<int, int> p, int c) const {\n    auto\
    \ [v, k] = p;\n    assert(0 <= c && c < sigma);\n\n    while (v != 0 && nodes[v].nxt[c]\
    \ == -1) {\n      v = nodes[v].link;\n      k = nodes[v].max_len;\n    }\n\n \
    \   int to = nodes[v].nxt[c];\n    if (to == -1) return {0, 0};\n    return {to,\
    \ k + 1};\n  }\n\n private:\n  // trie \u306E edge: SAM state p --c--> ? \u3092\
    \u8FFD\u52A0\u3059\u308B generalized extension.\n  // p \u306F trie depth \u9806\
    \u306B\u51E6\u7406\u3055\u308C\u308B.\n  int add_single(int p, int c) {\n    //\
    \ \u65E2\u306B\u9077\u79FB\u304C\u3042\u308B\u5834\u5408\u3001\u305D\u306E\u9077\
    \u79FB\u5148\u306E max_len \u304C\u3061\u3087\u3046\u3069\u306A\u3089\u518D\u5229\
    \u7528\u3059\u308B.\n    // \u9577\u3055\u304C\u98DB\u3093\u3067\u3044\u308B\u5834\
    \u5408\u306F split \u3059\u308B.\n    if (nodes[p].nxt[c] != -1) {\n      int\
    \ q = nodes[p].nxt[c];\n      if (nodes[p].max_len + 1 == nodes[q].max_len) return\
    \ q;\n\n      int clone = len(nodes);\n      nodes.eb(nodes[q].link, nodes[p].max_len\
    \ + 1);\n      nodes[clone].nxt = nodes[q].nxt;\n\n      int x = p;\n      while\
    \ (x != -1 && nodes[x].nxt[c] == q) {\n        nodes[x].nxt[c] = clone;\n    \
    \    x = nodes[x].link;\n      }\n      nodes[q].link = clone;\n      return clone;\n\
    \    }\n\n    int cur = len(nodes);\n    nodes.eb(-1, nodes[p].max_len + 1);\n\
    \n    int x = p;\n    while (x != -1 && nodes[x].nxt[c] == -1) {\n      nodes[x].nxt[c]\
    \ = cur;\n      x = nodes[x].link;\n    }\n\n    if (x == -1) {\n      nodes[cur].link\
    \ = 0;\n      return cur;\n    }\n\n    int q = nodes[x].nxt[c];\n    if (nodes[x].max_len\
    \ + 1 == nodes[q].max_len) {\n      nodes[cur].link = q;\n      return cur;\n\
    \    }\n\n    int clone = len(nodes);\n    nodes.eb(nodes[q].link, nodes[x].max_len\
    \ + 1);\n    nodes[clone].nxt = nodes[q].nxt;\n\n    while (x != -1 && nodes[x].nxt[c]\
    \ == q) {\n      nodes[x].nxt[c] = clone;\n      x = nodes[x].link;\n    }\n\n\
    \    nodes[q].link = clone;\n    nodes[cur].link = clone;\n    return cur;\n \
    \ }\n\n  // max_len \u6607\u9806\u306B reindex.\n  void normalize() {\n    int\
    \ n = len(nodes);\n    int max_len = 0;\n    for (auto& x : nodes) chmax(max_len,\
    \ x.max_len);\n\n    vc<int> cnt(max_len + 1);\n    for (auto& x : nodes) ++cnt[x.max_len];\n\
    \    FOR(i, max_len) cnt[i + 1] += cnt[i];\n\n    vc<int> ord(n);\n    FOR_R(v,\
    \ n) {\n      int k = nodes[v].max_len;\n      ord[--cnt[k]] = v;\n    }\n\n \
    \   vc<int> new_idx(n);\n    FOR(i, n) new_idx[ord[i]] = i;\n\n    vc<Node> new_nodes;\n\
    \    new_nodes.reserve(n);\n    FOR(i, n) new_nodes.eb(move(nodes[ord[i]]));\n\
    \n    FOR(v, n) {\n      auto& nd = new_nodes[v];\n      if (nd.link != -1) nd.link\
    \ = new_idx[nd.link];\n      for (auto& to : nd.nxt) {\n        if (to != -1)\
    \ to = new_idx[to];\n      }\n    }\n\n    nodes = move(new_nodes);\n    n_node\
    \ = n;\n\n    assert(nodes[0].link == -1);\n    FOR(v, 1, n) assert(nodes[v].link\
    \ < v);\n    FOR(v, n) {\n      for (auto to : nodes[v].nxt) {\n        if (to\
    \ != -1) assert(v < to);\n      }\n    }\n  }\n};\n"
  code: "#pragma once\n\n#include \"graph/tree.hpp\"\n#include \"string/trie.hpp\"\
    \n\n/*\n\u5165\u529B\uFF1A\u8907\u6570\u6587\u5B57\u5217 or trie\nO(|trie nodes|)\n\
    node \u756A\u53F7\u306F topological \u9806\u306B\u4ED8\u3051\u76F4\u3057\u3066\
    \u3044\u308B\n*/\n\ntemplate <int sigma = 26>\nstruct Generalized_Suffix_Automaton\
    \ {\n  struct Node {\n    array<int, sigma> nxt;\n    int link;\n    int max_len;\n\
    \n    Node(int link, int max_len) : link(link), max_len(max_len) {\n      fill(all(nxt),\
    \ -1);\n    }\n  };\n\n  using GT = Graph<int, 1>;\n  using TREE = Tree<GT>;\n\
    \n  vc<Node> nodes;\n  int n_node;\n\n  Node& operator[](int i) { return nodes[i];\
    \ }\n  const Node& operator[](int i) const { return nodes[i]; }\n\n  Generalized_Suffix_Automaton()\
    \ {}\n\n  template <typename STRING>\n  Generalized_Suffix_Automaton(const vc<STRING>&\
    \ SS, int off) {\n    build(SS, off);\n  }\n\n  // n \u9802\u70B9 trie \u304B\u3089\
    \u69CB\u7BC9. O(n sigma).\n  void build(const Trie<sigma>& TRIE) {\n    int N\
    \ = TRIE.n_node;\n\n    nodes.clear();\n    vc<int> trie_pos(N, -1);\n    nodes.reserve(2\
    \ * N);\n\n    nodes.eb(-1, 0);\n    trie_pos[0] = 0;\n\n    // trie \u3092 BFS\
    \ (depth \u6607\u9806) \u3067\u51E6\u7406\u3059\u308B.\n    vc<int> que(N);\n\
    \    int ql = 0, qr = 0;\n    que[qr++] = 0;\n    while (ql < qr) {\n      int\
    \ v = que[ql++];\n      int p = trie_pos[v];\n      FOR(c, sigma) {\n        int\
    \ w = TRIE.nodes[v].ch[c];\n        if (w == -1) continue;\n        trie_pos[w]\
    \ = add_single(p, c);\n        que[qr++] = w;\n      }\n    }\n\n    normalize();\n\
    \  }\n\n  // \u8907\u6570\u6587\u5B57\u5217\u304B\u3089 trie \u3092\u4F5C\u308A\
    \u3001\u305D\u308C\u3092 generalized SAM \u306B\u3059\u308B.\n  template <typename\
    \ STRING>\n  void build(const vc<STRING>& SS, int off) {\n    Trie<sigma> TRIE;\n\
    \    for (auto& S : SS) TRIE.add(S, off);\n    build(TRIE);\n  }\n\n  // node\
    \ v \u304C\u8868\u3059\u6587\u5B57\u5217\u9577\u306E\u534A\u958B\u533A\u9593\n\
    \  pair<int, int> len_range(int v) const {\n    assert(0 <= v && v < len(nodes));\n\
    \    if (v == 0) return {0, 1};\n    return {nodes[nodes[v].link].max_len + 1,\
    \ nodes[v].max_len + 1};\n  }\n\n  // suffix-link tree\n  pair<GT, TREE> build_tree()\
    \ const {\n    int n = len(nodes);\n    GT G(n);\n    FOR(v, 1, n) G.add(nodes[v].link,\
    \ v);\n    G.build();\n    TREE tree(G, 0);\n    return {move(G), move(tree)};\n\
    \  }\n\n  // 1 \u6587\u5B57\u8AAD\u307F\u3001\u5165\u529B\u6587\u5B57\u5217\u7FA4\
    \u306E\u90E8\u5206\u6587\u5B57\u5217\u3067\u3042\u308B\u6700\u9577 suffix \u306B\
    \u9077\u79FB.\n  pair<int, int> next(pair<int, int> p, int c) const {\n    auto\
    \ [v, k] = p;\n    assert(0 <= c && c < sigma);\n\n    while (v != 0 && nodes[v].nxt[c]\
    \ == -1) {\n      v = nodes[v].link;\n      k = nodes[v].max_len;\n    }\n\n \
    \   int to = nodes[v].nxt[c];\n    if (to == -1) return {0, 0};\n    return {to,\
    \ k + 1};\n  }\n\n private:\n  // trie \u306E edge: SAM state p --c--> ? \u3092\
    \u8FFD\u52A0\u3059\u308B generalized extension.\n  // p \u306F trie depth \u9806\
    \u306B\u51E6\u7406\u3055\u308C\u308B.\n  int add_single(int p, int c) {\n    //\
    \ \u65E2\u306B\u9077\u79FB\u304C\u3042\u308B\u5834\u5408\u3001\u305D\u306E\u9077\
    \u79FB\u5148\u306E max_len \u304C\u3061\u3087\u3046\u3069\u306A\u3089\u518D\u5229\
    \u7528\u3059\u308B.\n    // \u9577\u3055\u304C\u98DB\u3093\u3067\u3044\u308B\u5834\
    \u5408\u306F split \u3059\u308B.\n    if (nodes[p].nxt[c] != -1) {\n      int\
    \ q = nodes[p].nxt[c];\n      if (nodes[p].max_len + 1 == nodes[q].max_len) return\
    \ q;\n\n      int clone = len(nodes);\n      nodes.eb(nodes[q].link, nodes[p].max_len\
    \ + 1);\n      nodes[clone].nxt = nodes[q].nxt;\n\n      int x = p;\n      while\
    \ (x != -1 && nodes[x].nxt[c] == q) {\n        nodes[x].nxt[c] = clone;\n    \
    \    x = nodes[x].link;\n      }\n      nodes[q].link = clone;\n      return clone;\n\
    \    }\n\n    int cur = len(nodes);\n    nodes.eb(-1, nodes[p].max_len + 1);\n\
    \n    int x = p;\n    while (x != -1 && nodes[x].nxt[c] == -1) {\n      nodes[x].nxt[c]\
    \ = cur;\n      x = nodes[x].link;\n    }\n\n    if (x == -1) {\n      nodes[cur].link\
    \ = 0;\n      return cur;\n    }\n\n    int q = nodes[x].nxt[c];\n    if (nodes[x].max_len\
    \ + 1 == nodes[q].max_len) {\n      nodes[cur].link = q;\n      return cur;\n\
    \    }\n\n    int clone = len(nodes);\n    nodes.eb(nodes[q].link, nodes[x].max_len\
    \ + 1);\n    nodes[clone].nxt = nodes[q].nxt;\n\n    while (x != -1 && nodes[x].nxt[c]\
    \ == q) {\n      nodes[x].nxt[c] = clone;\n      x = nodes[x].link;\n    }\n\n\
    \    nodes[q].link = clone;\n    nodes[cur].link = clone;\n    return cur;\n \
    \ }\n\n  // max_len \u6607\u9806\u306B reindex.\n  void normalize() {\n    int\
    \ n = len(nodes);\n    int max_len = 0;\n    for (auto& x : nodes) chmax(max_len,\
    \ x.max_len);\n\n    vc<int> cnt(max_len + 1);\n    for (auto& x : nodes) ++cnt[x.max_len];\n\
    \    FOR(i, max_len) cnt[i + 1] += cnt[i];\n\n    vc<int> ord(n);\n    FOR_R(v,\
    \ n) {\n      int k = nodes[v].max_len;\n      ord[--cnt[k]] = v;\n    }\n\n \
    \   vc<int> new_idx(n);\n    FOR(i, n) new_idx[ord[i]] = i;\n\n    vc<Node> new_nodes;\n\
    \    new_nodes.reserve(n);\n    FOR(i, n) new_nodes.eb(move(nodes[ord[i]]));\n\
    \n    FOR(v, n) {\n      auto& nd = new_nodes[v];\n      if (nd.link != -1) nd.link\
    \ = new_idx[nd.link];\n      for (auto& to : nd.nxt) {\n        if (to != -1)\
    \ to = new_idx[to];\n      }\n    }\n\n    nodes = move(new_nodes);\n    n_node\
    \ = n;\n\n    assert(nodes[0].link == -1);\n    FOR(v, 1, n) assert(nodes[v].link\
    \ < v);\n    FOR(v, n) {\n      for (auto to : nodes[v].nxt) {\n        if (to\
    \ != -1) assert(v < to);\n      }\n    }\n  }\n};\n"
  dependsOn:
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - string/trie.hpp
  isVerificationFile: false
  path: string/generalized_suffix_automaton.hpp
  requiredBy: []
  timestamp: '2026-09-14 17:13:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/generalized_suffix_automaton.hpp
layout: document
redirect_from:
- /library/string/generalized_suffix_automaton.hpp
- /library/string/generalized_suffix_automaton.hpp.html
title: string/generalized_suffix_automaton.hpp
---
