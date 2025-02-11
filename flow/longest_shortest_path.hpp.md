---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: flow/mincostflow.hpp
    title: flow/mincostflow.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://qoj.ac/contest/1435/problem/7737
  bundledCode: "#line 2 \"flow/mincostflow.hpp\"\n\n// atcoder library \u306E\u3082\
    \u306E\u3092\u6539\u5909\nnamespace internal {\ntemplate <class E>\nstruct csr\
    \ {\n  vector<int> start;\n  vector<E> elist;\n  explicit csr(int n, const vector<pair<int,\
    \ E>>& edges) : start(n + 1), elist(edges.size()) {\n    for (auto e: edges) {\
    \ start[e.first + 1]++; }\n    for (int i = 1; i <= n; i++) { start[i] += start[i\
    \ - 1]; }\n    auto counter = start;\n    for (auto e: edges) { elist[counter[e.first]++]\
    \ = e.second; }\n  }\n};\n\ntemplate <class T>\nstruct simple_queue {\n  vector<T>\
    \ payload;\n  int pos = 0;\n  void reserve(int n) { payload.reserve(n); }\n  int\
    \ size() const { return int(payload.size()) - pos; }\n  bool empty() const { return\
    \ pos == int(payload.size()); }\n  void push(const T& t) { payload.push_back(t);\
    \ }\n  T& front() { return payload[pos]; }\n  void clear() {\n    payload.clear();\n\
    \    pos = 0;\n  }\n  void pop() { pos++; }\n};\n\n} // namespace internal\n\n\
    /*\n\u30FBatcoder library \u3092\u3059\u3053\u3057\u6539\u5909\u3057\u305F\u3082\
    \u306E\n\u30FBDAG = true \u3067\u3042\u308C\u3070\u3001\u8CA0\u8FBA OK \uFF08\
    1 \u56DE\u76EE\u306E\u6700\u77ED\u8DEF\u3092 dp \u3067\u884C\u3046\uFF09\n\u305F\
    \u3060\u3057\u3001\u9802\u70B9\u756A\u53F7\u306F toposort \u3055\u308C\u3066\u3044\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\u3002\n*/\ntemplate\
    \ <class Cap = int, class Cost = ll, bool DAG = false>\nstruct Min_Cost_Flow {\n\
    public:\n  Min_Cost_Flow() {}\n  explicit Min_Cost_Flow(int n, int source, int\
    \ sink) : n(n), source(source), sink(sink) {\n    assert(0 <= source && source\
    \ < n);\n    assert(0 <= sink && sink < n);\n    assert(source != sink);\n  }\n\
    \n  // frm, to, cap, cost\n  int add(int frm, int to, Cap cap, Cost cost) {\n\
    \    assert(0 <= frm && frm < n);\n    assert(0 <= to && to < n);\n    assert(0\
    \ <= cap);\n    assert(DAG || 0 <= cost);\n    if (DAG) assert(frm < to);\n  \
    \  int m = int(_edges.size());\n    _edges.push_back({frm, to, cap, 0, cost});\n\
    \    return m;\n  }\n\n  void debug() {\n    print(\"flow graph\");\n    print(\"\
    frm, to, cap, cost\");\n    for (auto&& [frm, to, cap, flow, cost]: _edges) {\
    \ print(frm, to, cap, cost); }\n  }\n\n  struct edge {\n    int frm, to;\n   \
    \ Cap cap, flow;\n    Cost cost;\n  };\n\n  edge get_edge(int i) {\n    int m\
    \ = int(_edges.size());\n    assert(0 <= i && i < m);\n    return _edges[i];\n\
    \  }\n  vector<edge> edges() { return _edges; }\n\n  // (\u6D41\u91CF, \u8CBB\u7528\
    )\n  pair<Cap, Cost> flow() { return flow(infty<Cap>); }\n  // (\u6D41\u91CF,\
    \ \u8CBB\u7528)\n  pair<Cap, Cost> flow(Cap flow_limit) { return slope(flow_limit).back();\
    \ }\n  vector<pair<Cap, Cost>> slope() { return slope(infty<Cap>); }\n  vector<pair<Cap,\
    \ Cost>> slope(Cap flow_limit) {\n    int m = int(_edges.size());\n    vector<int>\
    \ edge_idx(m);\n\n    auto g = [&]() {\n      vector<int> degree(n), redge_idx(m);\n\
    \      vector<pair<int, _edge>> elist;\n      elist.reserve(2 * m);\n      for\
    \ (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ = degree[e.frm]++;\n        redge_idx[i] = degree[e.to]++;\n        elist.push_back({e.frm,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n        elist.push_back({e.to, {e.frm,\
    \ -1, e.flow, -e.cost}});\n      }\n      auto _g = internal::csr<_edge>(n, elist);\n\
    \      for (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ += _g.start[e.frm];\n        redge_idx[i] += _g.start[e.to];\n        _g.elist[edge_idx[i]].rev\
    \ = redge_idx[i];\n        _g.elist[redge_idx[i]].rev = edge_idx[i];\n      }\n\
    \      return _g;\n    }();\n\n    auto result = slope(g, flow_limit);\n\n   \
    \ for (int i = 0; i < m; i++) {\n      auto e = g.elist[edge_idx[i]];\n      _edges[i].flow\
    \ = _edges[i].cap - e.cap;\n    }\n\n    return result;\n  }\n\n  // O(F(N+M))\
    \ \u304F\u3089\u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  vvc<int> path_decomposition()\
    \ {\n    vvc<int> TO(n);\n    for (auto&& e: edges()) { FOR(e.flow) TO[e.frm].eb(e.to);\
    \ }\n    vvc<int> res;\n    vc<int> vis(n);\n\n    while (!TO[source].empty())\
    \ {\n      vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ { vis[POP(path)] = 0; }\n        path.eb(to), vis[to] = 1;\n      }\n      for\
    \ (auto&& v: path) vis[v] = 0;\n      res.eb(path);\n    }\n    return res;\n\
    \  }\n\n  vc<Cost> get_potentials() { return potential; }\n\nprivate:\n  int n,\
    \ source, sink;\n  vector<edge> _edges;\n\n  // inside edge\n  struct _edge {\n\
    \    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\n  vc<Cost> potential;\n\
    \n  vector<pair<Cap, Cost>> slope(internal::csr<_edge>& g, Cap flow_limit) {\n\
    \    if (DAG) assert(source == 0 && sink == n - 1);\n    vector<pair<Cost, Cost>>\
    \ dual_dist(n);\n    vector<int> prev_e(n);\n    vector<bool> vis(n);\n    struct\
    \ Q {\n      Cost key;\n      int to;\n      bool operator<(Q r) const { return\
    \ key > r.key; }\n    };\n    vector<int> que_min;\n    vector<Q> que;\n    auto\
    \ dual_ref = [&]() {\n      for (int i = 0; i < n; i++) { dual_dist[i].second\
    \ = infty<Cost>; }\n      fill(vis.begin(), vis.end(), false);\n      que_min.clear();\n\
    \      que.clear();\n\n      // que[0..heap_r) was heapified\n      size_t heap_r\
    \ = 0;\n\n      dual_dist[source].second = 0;\n      que_min.push_back(source);\n\
    \      while (!que_min.empty() || !que.empty()) {\n        int v;\n        if\
    \ (!que_min.empty()) {\n          v = que_min.back();\n          que_min.pop_back();\n\
    \        } else {\n          while (heap_r < que.size()) {\n            heap_r++;\n\
    \            push_heap(que.begin(), que.begin() + heap_r);\n          }\n    \
    \      v = que.front().to;\n          pop_heap(que.begin(), que.end());\n    \
    \      que.pop_back();\n          heap_r--;\n        }\n        if (vis[v]) continue;\n\
    \        vis[v] = true;\n        if (v == sink) break;\n        Cost dual_v =\
    \ dual_dist[v].first, dist_v = dual_dist[v].second;\n        for (int i = g.start[v];\
    \ i < g.start[v + 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap)\
    \ continue;\n          Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n\
    \          if (dual_dist[e.to].second > dist_v + cost) {\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n            if (dist_to == dist_v) {\n             \
    \ que_min.push_back(e.to);\n            } else {\n              que.push_back(Q{dist_to,\
    \ e.to});\n            }\n          }\n        }\n      }\n      if (!vis[sink])\
    \ { return false; }\n\n      for (int v = 0; v < n; v++) {\n        if (!vis[v])\
    \ continue;\n        dual_dist[v].first -= dual_dist[sink].second - dual_dist[v].second;\n\
    \      }\n      return true;\n    };\n\n    auto dual_ref_dag = [&]() {\n    \
    \  FOR(i, n) dual_dist[i].se = infty<Cost>;\n      dual_dist[source].se = 0;\n\
    \      fill(vis.begin(), vis.end(), false);\n      vis[0] = true;\n\n      FOR(v,\
    \ n) {\n        if (!vis[v]) continue;\n        Cost dual_v = dual_dist[v].fi,\
    \ dist_v = dual_dist[v].se;\n        for (int i = g.start[v]; i < g.start[v +\
    \ 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n\
    \          Cost cost = e.cost - dual_dist[e.to].fi + dual_v;\n          if (dual_dist[e.to].se\
    \ > dist_v + cost) {\n            vis[e.to] = true;\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n          }\n        }\n      }\n      if (!vis[sink])\
    \ { return false; }\n\n      for (int v = 0; v < n; v++) {\n        if (!vis[v])\
    \ continue;\n        dual_dist[v].fi -= dual_dist[sink].se - dual_dist[v].se;\n\
    \      }\n      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0,\
    \ prev_cost_per_flow = -1;\n    vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \    while (flow < flow_limit) {\n      if (DAG && flow == 0) {\n        if (!dual_ref_dag())\
    \ break;\n      } else {\n        if (!dual_ref()) break;\n      }\n      Cap\
    \ c = flow_limit - flow;\n      for (int v = sink; v != source; v = g.elist[prev_e[v]].to)\
    \ { c = min(c, g.elist[g.elist[prev_e[v]].rev].cap); }\n      for (int v = sink;\
    \ v != source; v = g.elist[prev_e[v]].to) {\n        auto& e = g.elist[prev_e[v]];\n\
    \        e.cap += c;\n        g.elist[e.rev].cap -= c;\n      }\n      Cost d\
    \ = -dual_dist[source].first;\n      flow += c;\n      cost += c * d;\n      if\
    \ (prev_cost_per_flow == d) { result.pop_back(); }\n      result.push_back({flow,\
    \ cost});\n      prev_cost_per_flow = d;\n    }\n    dual_ref();\n    potential.resize(n);\n\
    \    FOR(v, n) potential[v] = dual_dist[v].fi;\n    return result;\n  }\n};\n\
    #line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct\
    \ HashMap {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\
    \u3067 ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32 n) {\r\n \
    \   u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k -\
    \ 1;\r\n    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  //\
    \ size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\
    \u306F build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used),\
    \ 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) /\
    \ 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i\
    \ = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\
    \n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\
    \n    int i = index(k);\r\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i]\
    \ = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k,\
    \ Val default_value) {\r\n    int i = index(k);\r\n    return (used[i] ? val[i]\
    \ : default_value);\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i =\
    \ index(k);\r\n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\
    \n  template <typename F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\
    \n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x)\
    \ {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
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
    #line 3 \"graph/shortest_path/dijkstra.hpp\"\n\ntemplate <typename T, typename\
    \ GT>\npair<vc<T>, vc<int>> dijkstra_dense(GT& G, int s) {\n  const int N = G.N;\n\
    \  vc<T> dist(N, infty<T>);\n  vc<int> par(N, -1);\n  vc<bool> done(N);\n  dist[s]\
    \ = 0;\n  while (1) {\n    int v = -1;\n    T mi = infty<T>;\n    FOR(i, N) {\n\
    \      if (!done[i] && chmin(mi, dist[i])) v = i;\n    }\n    if (v == -1) break;\n\
    \    done[v] = 1;\n    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to], dist[v]\
    \ + e.cost)) par[e.to] = v;\n    }\n  }\n  return {dist, par};\n}\n\ntemplate\
    \ <typename T, typename GT, bool DENSE = false>\npair<vc<T>, vc<int>> dijkstra(GT&\
    \ G, int v) {\n  if (DENSE) return dijkstra_dense<T>(G, v);\n  auto N = G.N;\n\
    \  vector<T> dist(N, infty<T>);\n  vector<int> par(N, -1);\n  using P = pair<T,\
    \ int>;\n\n  priority_queue<P, vector<P>, greater<P>> que;\n\n  dist[v] = 0;\n\
    \  que.emplace(0, v);\n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n\
    \    que.pop();\n    if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n\
    \      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {\n        par[e.to] = e.frm;\n\
    \        que.emplace(dist[e.to], e.to);\n      }\n    }\n  }\n  return {dist,\
    \ par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\n\
    template <typename T, typename GT>\ntuple<vc<T>, vc<int>, vc<int>> dijkstra(GT&\
    \ G, vc<int> vs) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<T> dist(N,\
    \ infty<T>);\n  vc<int> par(N, -1);\n  vc<int> root(N, -1);\n\n  using P = pair<T,\
    \ int>;\n\n  priority_queue<P, vector<P>, greater<P>> que;\n\n  for (auto&& v:\
    \ vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.emplace(T(0), v);\n  }\n\n\
    \  while (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n   \
    \ if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to],\
    \ dist[e.frm] + e.cost)) {\n        root[e.to] = root[e.frm];\n        par[e.to]\
    \ = e.frm;\n        que.push(mp(dist[e.to], e.to));\n      }\n    }\n  }\n  return\
    \ {dist, par, root};\n}\n#line 3 \"flow/longest_shortest_path.hpp\"\n\n/*\npotential\
    \ p[v]\n\u8DDD\u96E2\u3092 L \u4EE5\u4E0A\u306B\u3057\u305F\u3044 : L<=p[t]-p[s]\n\
    \u8FBA (u,v,w)\n\u4F38\u3070\u3059\u91CF max(0,p[v]-p[u]-w)\n- t \u304B\u3089\
    \ s \u306B\u8CBB\u7528-L, \u5BB9\u91CFINF\n- u \u304B\u3089 v \u306B\u8CBB\u7528\
    \ w, \u5BB9\u91CF 1\n\u3053\u308C\u306E\u5FAA\u74B0\u6D41\n*/\n\n// https://qoj.ac/contest/1435/problem/7737\n\
    template <typename T = ll, bool DAG = false>\nstruct Longest_Shortest_Path {\n\
    \  int N, s, t;\n  T F, L, K;\n  bool solved;\n  vc<tuple<int, int, T, T>> dat;\n\
    \  vc<T> pot;\n  Longest_Shortest_Path(int N, int s, int t) : N(N), s(s), t(t),\
    \ F(0), solved(0) {}\n\n  // \u73FE\u5728\u306E\u9577\u3055, \u9577\u3055\u3092\
    +1\u3059\u308B\u30B3\u30B9\u30C8\n  void add(int frm, int to, T length, T cost)\
    \ {\n    assert(0 <= frm && frm < N && 0 <= to && to < N && !solved);\n    if\
    \ (DAG) assert(frm < to);\n    dat.eb(frm, to, length, cost);\n  }\n\n  T init_dist()\
    \ {\n    Graph<T, 1> G(N);\n    for (auto& [a, b, c, d]: dat) G.add(a, b, c);\n\
    \    G.build();\n    auto [dist, par] = dijkstra<T>(G, s);\n    return dist[t];\n\
    \  }\n\n  // \u8DDD\u96E2\u304C L \u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\u306B\
    \u305B\u3088. return: min cost.\n  T solve_by_target_length(T target_length) {\n\
    \    L = target_length;\n    assert(!solved && L >= init_dist());\n    solved\
    \ = 1;\n    Min_Cost_Flow<T, T, DAG> G(N, s, t);\n    for (auto& [a, b, length,\
    \ cost]: dat) { G.add(a, b, cost, length); }\n    T ans = -infty<T>;\n    for\
    \ (auto& [x, y]: G.slope()) {\n      if (chmax(ans, x * L - y)) F = x;\n    }\n\
    \    return K = ans;\n  }\n\n  // \u30B3\u30B9\u30C8\u304C K \u3067\u6700\u5927\
    \u8DDD\u96E2\u306B\u305B\u3088. return: max dist.\n  T solve_by_cost(T K) {}\n\
    \n  // frm, to, cost. add_edge \u9806.\n  vc<T> get_potentials() {\n    assert(solved);\n\
    \    if (len(pot)) return pot;\n    Min_Cost_Flow<T, T, DAG> G(N, s, t);\n   \
    \ for (auto& [a, b, length, cost]: dat) { G.add(a, b, cost, length); }\n    G.flow(F);\n\
    \    pot = G.get_potentials();\n    Graph<T, 1> resG(N);\n    auto add = [&](int\
    \ a, int b, T x) -> void {\n      x = x + pot[a] - pot[b];\n      resG.add(a,\
    \ b, x);\n    };\n    for (auto& e: G.edges()) {\n      if (e.cap > e.flow) add(e.frm,\
    \ e.to, e.cost);\n      if (e.flow > 0) add(e.to, e.frm, -e.cost);\n    }\n  \
    \  add(s, t, L), add(t, s, -L);\n    resG.build();\n    vc<T> dist = dijkstra<ll>(resG,\
    \ s).fi;\n    FOR(x, N) pot[x] += dist[x];\n    return pot;\n  }\n\n  // \u5909\
    \u66F4\u5F8C\u306E\u9577\u3055\n  vc<T> get_edges() {\n    get_potentials();\n\
    \    vc<T> res;\n    for (auto [frm, to, length, cost]: dat) { res.eb(max<T>(length,\
    \ pot[to] - pot[frm])); }\n    return res;\n  }\n};\n"
  code: "#include \"flow/mincostflow.hpp\"\n#include \"graph/shortest_path/dijkstra.hpp\"\
    \n\n/*\npotential p[v]\n\u8DDD\u96E2\u3092 L \u4EE5\u4E0A\u306B\u3057\u305F\u3044\
    \ : L<=p[t]-p[s]\n\u8FBA (u,v,w)\n\u4F38\u3070\u3059\u91CF max(0,p[v]-p[u]-w)\n\
    - t \u304B\u3089 s \u306B\u8CBB\u7528-L, \u5BB9\u91CFINF\n- u \u304B\u3089 v \u306B\
    \u8CBB\u7528 w, \u5BB9\u91CF 1\n\u3053\u308C\u306E\u5FAA\u74B0\u6D41\n*/\n\n//\
    \ https://qoj.ac/contest/1435/problem/7737\ntemplate <typename T = ll, bool DAG\
    \ = false>\nstruct Longest_Shortest_Path {\n  int N, s, t;\n  T F, L, K;\n  bool\
    \ solved;\n  vc<tuple<int, int, T, T>> dat;\n  vc<T> pot;\n  Longest_Shortest_Path(int\
    \ N, int s, int t) : N(N), s(s), t(t), F(0), solved(0) {}\n\n  // \u73FE\u5728\
    \u306E\u9577\u3055, \u9577\u3055\u3092+1\u3059\u308B\u30B3\u30B9\u30C8\n  void\
    \ add(int frm, int to, T length, T cost) {\n    assert(0 <= frm && frm < N &&\
    \ 0 <= to && to < N && !solved);\n    if (DAG) assert(frm < to);\n    dat.eb(frm,\
    \ to, length, cost);\n  }\n\n  T init_dist() {\n    Graph<T, 1> G(N);\n    for\
    \ (auto& [a, b, c, d]: dat) G.add(a, b, c);\n    G.build();\n    auto [dist, par]\
    \ = dijkstra<T>(G, s);\n    return dist[t];\n  }\n\n  // \u8DDD\u96E2\u304C L\
    \ \u4EE5\u4E0A\u306B\u306A\u308B\u3088\u3046\u306B\u305B\u3088. return: min cost.\n\
    \  T solve_by_target_length(T target_length) {\n    L = target_length;\n    assert(!solved\
    \ && L >= init_dist());\n    solved = 1;\n    Min_Cost_Flow<T, T, DAG> G(N, s,\
    \ t);\n    for (auto& [a, b, length, cost]: dat) { G.add(a, b, cost, length);\
    \ }\n    T ans = -infty<T>;\n    for (auto& [x, y]: G.slope()) {\n      if (chmax(ans,\
    \ x * L - y)) F = x;\n    }\n    return K = ans;\n  }\n\n  // \u30B3\u30B9\u30C8\
    \u304C K \u3067\u6700\u5927\u8DDD\u96E2\u306B\u305B\u3088. return: max dist.\n\
    \  T solve_by_cost(T K) {}\n\n  // frm, to, cost. add_edge \u9806.\n  vc<T> get_potentials()\
    \ {\n    assert(solved);\n    if (len(pot)) return pot;\n    Min_Cost_Flow<T,\
    \ T, DAG> G(N, s, t);\n    for (auto& [a, b, length, cost]: dat) { G.add(a, b,\
    \ cost, length); }\n    G.flow(F);\n    pot = G.get_potentials();\n    Graph<T,\
    \ 1> resG(N);\n    auto add = [&](int a, int b, T x) -> void {\n      x = x +\
    \ pot[a] - pot[b];\n      resG.add(a, b, x);\n    };\n    for (auto& e: G.edges())\
    \ {\n      if (e.cap > e.flow) add(e.frm, e.to, e.cost);\n      if (e.flow > 0)\
    \ add(e.to, e.frm, -e.cost);\n    }\n    add(s, t, L), add(t, s, -L);\n    resG.build();\n\
    \    vc<T> dist = dijkstra<ll>(resG, s).fi;\n    FOR(x, N) pot[x] += dist[x];\n\
    \    return pot;\n  }\n\n  // \u5909\u66F4\u5F8C\u306E\u9577\u3055\n  vc<T> get_edges()\
    \ {\n    get_potentials();\n    vc<T> res;\n    for (auto [frm, to, length, cost]:\
    \ dat) { res.eb(max<T>(length, pot[to] - pot[frm])); }\n    return res;\n  }\n\
    };\n"
  dependsOn:
  - flow/mincostflow.hpp
  - graph/shortest_path/dijkstra.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: flow/longest_shortest_path.hpp
  requiredBy: []
  timestamp: '2024-12-25 20:50:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/longest_shortest_path.hpp
layout: document
redirect_from:
- /library/flow/longest_shortest_path.hpp
- /library/flow/longest_shortest_path.hpp.html
title: flow/longest_shortest_path.hpp
---
