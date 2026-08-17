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
    path: graph/tree_dp/rerooting_dp.hpp
    title: graph/tree_dp/rerooting_dp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/1725/J
  bundledCode: "#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\n\
    struct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\
    \u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n \
    \   u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n\
    \    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\
    \u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build\
    \ \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used), 0);\n\
    \    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\
    \n  int index(const u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] &&\
    \ key[i] != k; i = (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const\
    \ u64& k) {\n    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i])\
    \ { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64>\
    \ key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const\
    \ u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b]: dat) (*this)[a] = b;\n\
    \  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  HashMap<int> MP_FOR_EID;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n   public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) {\n        return 0;\n\
    \      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const Graph*\
    \ G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph()\
    \ : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n\
    \  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
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
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n\
    \    print(\"Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n\
    \      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n\
    \      print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n    }\n  \
    \  flush();\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\n\
    \  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
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
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) {\n\
    \    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for (auto&\
    \ e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) {\n    if (!directed && a >\
    \ b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e : edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e : edges)\
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 1 \"graph/tree.hpp\"\
    \n\n#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\nstruct\
    \ HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\
    \u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n    u32\
    \ k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\
    \u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\
    \u3068.\n  void clear() {\n    used.assign(len(used), 0);\n    cap = (mask + 1)\
    \ / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\n  int index(const\
    \ u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] && key[i] != k; i =\
    \ (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const u64& k) {\n\
    \    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\n  Val\
    \ get(const u64& k, Val default_value) {\n    int i = index(k);\n    return (used[i]\
    \ ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n    int i =\
    \ index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key, val)\n  template\
    \ <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used)) if (used[i])\
    \ f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64> key;\n  vc<Val>\
    \ val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n    x += FIXED_RANDOM;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return (x ^ (x >> 31)) & mask;\n  }\n\n  void extend() {\n    vc<pair<u64,\
    \ Val>> dat;\n    dat.reserve(len(used) / 2 - cap);\n    FOR(i, len(used)) {\n\
    \      if (used[i]) dat.eb(key[i], val[i]);\n    }\n    build(2 * len(dat));\n\
    \    for (auto& [a, b]: dat) (*this)[a] = b;\n  }\n};\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  HashMap<int>\
    \ MP_FOR_EID;\n  bool prepared;\n\n  class OutgoingEdges {\n   public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n\
    \    }\n\n    const edge_type* end() const {\n      if (l == r) {\n        return\
    \ 0;\n      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const\
    \ Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\
    \n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
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
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n\
    \    print(\"Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n\
    \      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n\
    \      print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n    }\n  \
    \  flush();\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\n\
    \  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
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
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) {\n\
    \    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for (auto&\
    \ e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) {\n    if (!directed && a >\
    \ b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e : edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e : edges)\
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\n// HLD=false:\
    \ \u5165\u529B\u8FBA\u9806\u3067 preorder\ntemplate <typename GT, bool HLD = true>\n\
    struct Tree {\n  using Graph_type = GT;\n  GT &G;\n  using WT = typename GT::cost_type;\n\
    \  int N;\n  vector<int> LID, RID, head, V, parent, VtoE;\n  vc<int> depth;\n\
    \  vc<WT> depth_weighted;\n  vc<int> memo_tail;\n\n  Tree(GT &G, int r = 0) :\
    \ G(G) { build(r); }\n\n  void build(int r = 0) {\n    if (r == -1) return;  //\
    \ build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\n    if constexpr (!HLD)\n\
    \      build_simple(r);\n    else\n      build_HLD(r);\n  }\n\n  vc<int> heavy_path_at(int\
    \ v) {\n    static_assert(HLD);\n    assert(head[v] == v);\n    int k = LID[v];\n\
    \    vc<int> P;\n    while (k < N && head[V[k]] == v) P.eb(V[k++]);\n    return\
    \ P;\n  }\n\n  int heavy_child(int v) {\n    static_assert(HLD);\n    if (RID[v]\
    \ == LID[v] + 1) return -1;\n    return V[LID[v] + 1];\n  }\n\n  int tail(int\
    \ v) {\n    static_assert(HLD);\n    if (memo_tail.empty()) {\n      memo_tail.assign(N,\
    \ -1);\n      FOR_R(i, N) {\n        int v = V[i];\n        int w = heavy_child(v);\n\
    \        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\n      }\n    }\n    return\
    \ memo_tail[v];\n  }\n\n  int e_to_v(int eid) {\n    auto e = G.edges[eid];\n\
    \    return (parent[e.frm] == e.to ? e.frm : e.to);\n  }\n  int v_to_e(int v)\
    \ { return VtoE[v]; }\n  int get_eid(int u, int v) {\n    if (parent[u] != v)\
    \ swap(u, v);\n    assert(parent[u] == v);\n    return VtoE[u];\n  }\n\n  int\
    \ ELID(int v) { return 2 * LID[v] - depth[v]; }\n  int ERID(int v) { return 2\
    \ * RID[v] - depth[v] - 1; }\n\n  // \u76EE\u6A19\u5730\u70B9\u3078\u9032\u3080\
    \u500B\u6570\u304C k\n  int LA(int v, int k) {\n    static_assert(HLD);\n    assert(k\
    \ <= depth[v]);\n    while (1) {\n      int u = head[v];\n      if (LID[v] - k\
    \ >= LID[u]) return V[LID[v] - k];\n      k -= LID[v] - LID[u] + 1;\n      v =\
    \ parent[u];\n    }\n  }\n  int la(int u, int v) { return LA(u, v); }\n\n  int\
    \ LCA(int u, int v) {\n    static_assert(HLD);\n    for (;; v = parent[head[v]])\
    \ {\n      if (LID[u] > LID[v]) swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n    }\n  }\n\n  int meet(int a, int b, int c) {\n    static_assert(HLD);\n\
    \    return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\n  }\n  int lca(int u, int v) {\
    \ return LCA(u, v); }\n\n  int subtree_size(int v) { return RID[v] - LID[v]; }\n\
    \n  int subtree_size(int v, int root) {\n    static_assert(HLD);\n    if (v ==\
    \ root) return N;\n    int x = jump(v, root, 1);\n    if (in_subtree(v, x)) return\
    \ RID[v] - LID[v];\n    return N - RID[x] + LID[x];\n  }\n\n  int dist(int a,\
    \ int b) {\n    static_assert(HLD);\n    int c = LCA(a, b);\n    return depth[a]\
    \ + depth[b] - 2 * depth[c];\n  }\n\n  WT dist_weighted(int a, int b) {\n    static_assert(HLD);\n\
    \    int c = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b] - WT(2)\
    \ * depth_weighted[c];\n  }\n\n  // a is in b\n  bool in_subtree(int a, int b)\
    \ { return LID[b] <= LID[a] && LID[a] < RID[b]; }\n\n  int jump(int a, int b,\
    \ ll k) {\n    static_assert(HLD);\n    if (k == 1) {\n      if (a == b) return\
    \ -1;\n      return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n\
    \    }\n    int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc\
    \ = depth[b] - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac)\
    \ return LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) {\n    vc<int> res;\n    for (auto &&e : G[v])\n      if (e.to != parent[v])\
    \ res.eb(e.to);\n    return res;\n  }\n\n  vc<int> collect_subtree(int v) {\n\
    \    return {V.begin() + LID[v], V.begin() + RID[v]};\n  }\n\n  vc<int> collect_light(int\
    \ v) {\n    static_assert(HLD);\n    vc<int> res;\n    for (auto &&e : G[v]) {\n\
    \      if (e.to != parent[v] && head[e.to] == e.to) res.eb(e.to);\n    }\n   \
    \ return res;\n  }\n\n  vc<pair<int, int>> get_path_decomposition(int u, int v,\
    \ bool edge) {\n    static_assert(HLD);\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\
    \"\u9589\"\u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n    while\
    \ (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v]) {\n\
    \        down.eb(LID[head[v]], LID[v]);\n        v = parent[head[v]];\n      }\
    \ else {\n        up.eb(LID[u], LID[head[u]]);\n        u = parent[head[u]];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\n  \
    \  elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n\
    \    up.insert(up.end(), all(down));\n    return up;\n  }\n\n  // \u8FBA\u306E\
    \u5217\u306E\u60C5\u5831 (frm,to,str)\n  // str = \"heavy_up\", \"heavy_down\"\
    , \"light_up\", \"light_down\"\n  vc<tuple<int, int, string>> get_path_decomposition_detail(int\
    \ u, int v) {\n    static_assert(HLD);\n    vc<tuple<int, int, string>> up, down;\n\
    \    while (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v])\
    \ {\n        if (v != head[v]) down.eb(head[v], v, \"heavy_down\"), v = head[v];\n\
    \        down.eb(parent[v], v, \"light_down\"), v = parent[v];\n      } else {\n\
    \        if (u != head[u]) up.eb(u, head[u], \"heavy_up\"), u = head[u];\n   \
    \     up.eb(u, parent[u], \"light_up\"), u = parent[u];\n      }\n    }\n    if\
    \ (LID[u] < LID[v]) down.eb(u, v, \"heavy_down\");\n    elif (LID[v] < LID[u])\
    \ up.eb(u, v, \"heavy_up\");\n    reverse(all(down));\n    concat(up, down);\n\
    \    return up;\n  }\n\n  vc<int> restore_path(int u, int v) {\n    vc<int> L,\
    \ R;\n    while (depth[u] > depth[v]) L.eb(u), u = parent[u];\n    while (depth[u]\
    \ < depth[v]) R.eb(v), v = parent[v];\n    while (u != v) L.eb(u), R.eb(v), u\
    \ = parent[u], v = parent[v];\n    L.eb(u);\n    while (len(R)) L.eb(POP(R));\n\
    \    return L;\n  }\n\n  // path [a,b] \u3068 [c,d] \u306E\u4EA4\u308F\u308A.\
    \ \u7A7A\u306A\u3089\u3070 {-1,-1}.\n  // https://codeforces.com/problemset/problem/500/G\n\
    \  pair<int, int> path_intersection(int a, int b, int c, int d) {\n    static_assert(HLD);\n\
    \    int ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);\n    int bc = lca(b,\
    \ c), bd = lca(b, d), cd = lca(c, d);\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^\
    \ bd;  // meet(a,b,c), meet(a,b,d)\n    if (x != y) return {x, y};\n    int z\
    \ = ac ^ ad ^ cd;\n    if (x != z) x = -1;\n    return {x, x};\n  }\n\n  // uv\
    \ path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E v\n  //\
    \ \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C ng \uFF09\
    -1\n  template <class F>\n  int max_path(F check, int u, int v) {\n    static_assert(HLD);\n\
    \    if (!check(u)) return -1;\n    auto pd = get_path_decomposition(u, v, false);\n\
    \    for (auto [a, b] : pd) {\n      if (!check(V[a])) return u;\n      if (check(V[b]))\
    \ {\n        u = V[b];\n        continue;\n      }\n      int c =\n          binary_search([&](int\
    \ c) -> bool { return check(V[c]); }, a, b, 0);\n      return V[c];\n    }\n \
    \   return u;\n  }\n\n private:\n  void build_simple(int r = 0) {\n    N = G.N;\n\
    \    LID.assign(N, 0), RID.assign(N, 0);\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1);\n    depth.assign(N, 0), depth_weighted.assign(N, 0);\n\
    \    assert(G.is_prepared());\n\n    // 1st dfs.\n    int k = 0;\n    vc<int>\
    \ st;\n    st.reserve(N);\n    st.eb(r);\n    while (len(st)) {\n      int v =\
    \ POP(st);\n      LID[v] = k, V[k] = v;\n      ++k;\n      for (int i = G.indptr[v\
    \ + 1] - 1; i >= G.indptr[v]; --i) {\n        auto &e = G.csr_edges[i];\n    \
    \    if (e.to == parent[v]) continue;\n        parent[e.to] = v;\n        depth[e.to]\
    \ = depth[v] + 1;\n        depth_weighted[e.to] = depth_weighted[v] + e.cost;\n\
    \        VtoE[e.to] = e.id;\n        st.eb(e.to);\n      }\n    }\n\n    FOR_R(i,\
    \ N) {\n      int v = V[i];\n      chmax(RID[v], LID[v] + 1);\n      if (parent[v]\
    \ != -1) chmax(RID[parent[v]], RID[v]);\n    }\n  }\n\n  void build_HLD(int r\
    \ = 0) {\n    N = G.N;\n    LID.assign(N, 0), RID.assign(N, 0), head.assign(N,\
    \ r);\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\n    depth.assign(N,\
    \ 0), depth_weighted.assign(N, 0);\n    memo_tail.clear();\n    assert(G.is_prepared());\n\
    \n    // 1st dfs.\n    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n\
    \      st.eb(r);\n      while (len(st)) {\n        int v = POP(st);\n        V[k++]\
    \ = v;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          parent[e.to] = v, st.eb(e.to), depth[e.to] = depth[v] + 1;\n      \
    \    depth_weighted[e.to] = depth_weighted[v] + e.cost;\n          VtoE[e.to]\
    \ = e.id;\n        }\n      }\n      // \u4E00\u6642\u7684\u306B RID[v] := sz[v]\n\
    \      FOR_R(i, N) {\n        int v = V[i];\n        RID[v] += 1;\n        if\
    \ (parent[v] != -1) RID[parent[v]] += RID[v];\n      }\n    }\n    // 2nd dfs.\n\
    \    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n      st.eb(r);\n\
    \      while (len(st)) {\n        int v = POP(st);\n        V[k] = v, LID[v] =\
    \ k;\n        RID[v] = k + RID[v];\n        ++k;\n        int max_sz = 0, max_ch\
    \ = -1;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          if (chmax(max_sz, RID[e.to])) max_ch = e.to;\n        }\n        for\
    \ (int i = G.indptr[v + 1] - 1; i >= G.indptr[v]; --i) {\n          auto &e =\
    \ G.csr_edges[i];\n          if (e.to == parent[v] || e.to == max_ch) continue;\n\
    \          st.eb(e.to), head[e.to] = e.to;\n        }\n        if (max_ch != -1)\
    \ st.eb(max_ch), head[max_ch] = head[v];\n      }\n    }\n  }\n};\n#line 3 \"\
    graph/tree_dp/rerooting_dp.hpp\"\n\ntemplate <typename TREE, typename Data>\n\
    struct Rerooting_DP {\n  static_assert(!TREE::Graph_type::is_directed);\n  TREE&\
    \ tree;\n  vc<Data> dp_1;  // \u8FBA pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\
    \u6728 v\n  vc<Data> dp_2;  // \u8FBA pv \u306B\u5BFE\u3057\u3066\u3001\u90E8\u5206\
    \u6728 p\n  vc<Data> dp;    // full tree\n\n  template <typename F1, typename\
    \ F2, typename F3>\n  Rerooting_DP(TREE& tree, F1 f_ee, F2 f_ev, F3 f_ve, const\
    \ Data unit)\n      : tree(tree) {\n    build(f_ee, f_ev, f_ve, unit);\n  }\n\n\
    \  // v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E full tree\n  Data operator[](int\
    \ v) { return dp[v]; }\n\n  // root \u3092\u6839\u3068\u3057\u305F\u3068\u304D\
    \u306E\u90E8\u5206\u6728 v\n  Data get(int v, int root) {\n    if (root == v)\
    \ return dp[v];\n    if (!tree.in_subtree(root, v)) {\n      return dp_1[v];\n\
    \    }\n    int w = tree.jump(v, root, 1);\n    return dp_2[w];\n  }\n\n  template\
    \ <typename F1, typename F2, typename F3>\n  void build(F1 f_ee, F2 f_ev, F3 f_ve,\
    \ const Data unit) {\n    int N = tree.N;\n    // dp1: subtree\n    dp_1.assign(N,\
    \ unit);\n    FOR_R(i, N) {\n      int v = tree.V[i];\n      for (auto&& e : tree.G[v])\
    \ {\n        if (e.to == tree.parent[v]) continue;\n        dp_1[v] = f_ee(dp_1[v],\
    \ f_ve(dp_1[e.to], e));\n      }\n      dp_1[v] = f_ev(dp_1[v], v);\n    }\n\n\
    \    // dp2[v]: subtree of p, rooted at v\n    dp_2.assign(N, unit);\n    // dp[v]:\
    \ fulltree, rooted at v\n    dp.assign(N, unit);\n    FOR(i, N) {\n      int p\
    \ = tree.V[i];\n      vc<int> ch;\n      vc<Data> ch_data;\n      Data x = unit;\n\
    \      for (auto&& e : tree.G[p]) {\n        if (e.to == tree.parent[p]) {\n \
    \         x = f_ve(dp_2[p], e);\n        } else {\n          ch.eb(e.to);\n  \
    \        ch_data.eb(f_ve(dp_1[e.to], e));\n        }\n      }\n      int n = len(ch);\n\
    \      if (!n) {\n        dp[p] = f_ev(x, p);\n        continue;\n      }\n  \
    \    vc<Data> prod_left(n, x);\n      FOR(i, n - 1) prod_left[i + 1] = f_ee(prod_left[i],\
    \ ch_data[i]);\n      Data prod_right = unit;\n      FOR_R(i, n) {\n        dp_2[ch[i]]\
    \ = f_ev(f_ee(prod_left[i], prod_right), p);\n        prod_right = f_ee(prod_right,\
    \ ch_data[i]);\n      }\n      dp[p] = f_ev(f_ee(x, prod_right), p);\n    }\n\
    \  }\n};\n#line 2 \"graph/tree_dp/subtree_diameter.hpp\"\n\n// https://codeforces.com/problemset/problem/1725/J\n\
    template <typename TREE, typename WT>\nstruct SubTree_Diameter {\n  struct Data\
    \ {\n    // \u4ECA\u307E\u3067\u898B\u3064\u3051\u305F\u76F4\u5F84\u8DDD\u96E2\
    \u3001\u7AEF\u70B9\n    WT diam;\n    int left, right;\n    // \u6839\u304B\u3089\
    \u51FA\u3066\u3044\u308B\u6700\u5927\u30D1\u30B9\u306E\u3001\u9577\u3055\u3001\
    \u7AEF\u70B9\n    WT path;\n    int end;\n  };\n\n  TREE& tree;\n  vc<tuple<int,\
    \ int, WT>> dp, dp_1, dp_2;\n\n  SubTree_Diameter(TREE& tree) : tree(tree) {\n\
    \    int N = tree.N;\n    Data unit = {-1, -1, -1, -1, -1};\n    auto f_ee = [&](Data\
    \ A, Data B) -> Data {\n      if (A.diam == -1) return B;\n      if (B.diam ==\
    \ -1) return A;\n      if (A.diam < B.diam) swap(A, B);\n      if (chmax(A.diam,\
    \ A.path + B.path)) {\n        A.left = A.end, A.right = B.end;\n      }\n   \
    \   if (chmax(A.path, B.path)) A.end = B.end;\n      return A;\n    };\n    auto\
    \ f_ev = [&](Data A, int v) -> Data {\n      if (A.diam == -1) {\n        A.diam\
    \ = 0, A.left = v, A.right = v, A.path = 0, A.end = v;\n      }\n      return\
    \ A;\n    };\n    auto f_ve = [&](Data A, const auto& e) -> Data {\n      A.path\
    \ += e.cost;\n      if (chmax(A.diam, A.path)) {\n        A.left = e.frm, A.right\
    \ = A.end;\n      }\n      return A;\n    };\n\n    Rerooting_DP<TREE, Data> DP(tree,\
    \ f_ee, f_ev, f_ve, unit);\n    dp.resize(N), dp_1.resize(N), dp_2.resize(N);\n\
    \    FOR(v, N) {\n      dp[v] = {DP.dp[v].left, DP.dp[v].right, DP.dp[v].diam};\n\
    \      dp_1[v] = {DP.dp_1[v].left, DP.dp_1[v].right, DP.dp_1[v].diam};\n     \
    \ dp_2[v] = {DP.dp_2[v].left, DP.dp_2[v].right, DP.dp_2[v].diam};\n    }\n  }\n\
    \n  // (u, v, diam)\n  // v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E full\
    \ tree\n  tuple<int, int, WT> operator[](int v) { return dp[v]; }\n\n  // (u,\
    \ v, diam)\n  // root \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\u5206\
    \u6728 v\n  tuple<int, int, WT> get(int v, int root) {\n    if (root == v) return\
    \ dp[v];\n    if (!tree.in_subtree(root, v)) {\n      return dp_1[v];\n    }\n\
    \    int w = tree.jump(v, root, 1);\n    return dp_2[w];\n  }\n};\n"
  code: "#include \"graph/tree_dp/rerooting_dp.hpp\"\n\n// https://codeforces.com/problemset/problem/1725/J\n\
    template <typename TREE, typename WT>\nstruct SubTree_Diameter {\n  struct Data\
    \ {\n    // \u4ECA\u307E\u3067\u898B\u3064\u3051\u305F\u76F4\u5F84\u8DDD\u96E2\
    \u3001\u7AEF\u70B9\n    WT diam;\n    int left, right;\n    // \u6839\u304B\u3089\
    \u51FA\u3066\u3044\u308B\u6700\u5927\u30D1\u30B9\u306E\u3001\u9577\u3055\u3001\
    \u7AEF\u70B9\n    WT path;\n    int end;\n  };\n\n  TREE& tree;\n  vc<tuple<int,\
    \ int, WT>> dp, dp_1, dp_2;\n\n  SubTree_Diameter(TREE& tree) : tree(tree) {\n\
    \    int N = tree.N;\n    Data unit = {-1, -1, -1, -1, -1};\n    auto f_ee = [&](Data\
    \ A, Data B) -> Data {\n      if (A.diam == -1) return B;\n      if (B.diam ==\
    \ -1) return A;\n      if (A.diam < B.diam) swap(A, B);\n      if (chmax(A.diam,\
    \ A.path + B.path)) {\n        A.left = A.end, A.right = B.end;\n      }\n   \
    \   if (chmax(A.path, B.path)) A.end = B.end;\n      return A;\n    };\n    auto\
    \ f_ev = [&](Data A, int v) -> Data {\n      if (A.diam == -1) {\n        A.diam\
    \ = 0, A.left = v, A.right = v, A.path = 0, A.end = v;\n      }\n      return\
    \ A;\n    };\n    auto f_ve = [&](Data A, const auto& e) -> Data {\n      A.path\
    \ += e.cost;\n      if (chmax(A.diam, A.path)) {\n        A.left = e.frm, A.right\
    \ = A.end;\n      }\n      return A;\n    };\n\n    Rerooting_DP<TREE, Data> DP(tree,\
    \ f_ee, f_ev, f_ve, unit);\n    dp.resize(N), dp_1.resize(N), dp_2.resize(N);\n\
    \    FOR(v, N) {\n      dp[v] = {DP.dp[v].left, DP.dp[v].right, DP.dp[v].diam};\n\
    \      dp_1[v] = {DP.dp_1[v].left, DP.dp_1[v].right, DP.dp_1[v].diam};\n     \
    \ dp_2[v] = {DP.dp_2[v].left, DP.dp_2[v].right, DP.dp_2[v].diam};\n    }\n  }\n\
    \n  // (u, v, diam)\n  // v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E full\
    \ tree\n  tuple<int, int, WT> operator[](int v) { return dp[v]; }\n\n  // (u,\
    \ v, diam)\n  // root \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\u5206\
    \u6728 v\n  tuple<int, int, WT> get(int v, int root) {\n    if (root == v) return\
    \ dp[v];\n    if (!tree.in_subtree(root, v)) {\n      return dp_1[v];\n    }\n\
    \    int w = tree.jump(v, root, 1);\n    return dp_2[w];\n  }\n};"
  dependsOn:
  - graph/tree_dp/rerooting_dp.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/tree.hpp
  isVerificationFile: false
  path: graph/tree_dp/subtree_diameter.hpp
  requiredBy: []
  timestamp: '2026-08-17 08:56:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_dp/subtree_diameter.hpp
layout: document
redirect_from:
- /library/graph/tree_dp/subtree_diameter.hpp
- /library/graph/tree_dp/subtree_diameter.hpp.html
title: graph/tree_dp/subtree_diameter.hpp
---
