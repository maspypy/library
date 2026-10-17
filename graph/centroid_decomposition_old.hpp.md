---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/find_centroid.hpp
    title: graph/find_centroid.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/1796.test.cpp
    title: test/3_yukicoder/1796.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/graph/centroid_decomposition_old.hpp
  bundledCode: "#line 1 \"graph/centroid_decomposition_old.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/centroid_decomposition_old.hpp\n\
    #line 1 \"graph/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/base.hpp\n\
    #line 1 \"ds/hashmap.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/hashmap.hpp\n\
    \n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0)\
    \ { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2)\
    \ k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {\n    }\n\
    \    return i;\n  }\n\n  Val& operator[](const u64& k) {\n    int i = index(k);\n\
    \    if (used[i]) return val[i];\n    if (cap == 0) extend(), i = index(k);\n\
    \    used[i] = 1, key[i] = k, val[i] = Val{}, --cap;\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\n  }\n\n private:\n  u32 cap, mask;\n  vc<u64>\
    \ key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const\
    \ u64 FIXED_RANDOM =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b] : dat) (*this)[a] = b;\n\
    \  }\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
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
    \   }\n  }\n};\n#line 1 \"graph/find_centroid.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/find_centroid.hpp\n\
    #line 1 \"graph/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/base.hpp\n\
    #line 1 \"ds/hashmap.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/hashmap.hpp\n\
    \n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0)\
    \ { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2)\
    \ k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {\n    }\n\
    \    return i;\n  }\n\n  Val& operator[](const u64& k) {\n    int i = index(k);\n\
    \    if (used[i]) return val[i];\n    if (cap == 0) extend(), i = index(k);\n\
    \    used[i] = 1, key[i] = k, val[i] = Val{}, --cap;\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\n  }\n\n private:\n  u32 cap, mask;\n  vc<u64>\
    \ key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const\
    \ u64 FIXED_RANDOM =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b] : dat) (*this)[a] = b;\n\
    \  }\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
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
    \   }\n  }\n};\n#line 3 \"graph/find_centroid.hpp\"\n\n// (v,w) or (v,-1)\ntemplate\
    \ <typename GT>\npair<int, int> find_centroids(GT& G, vi weight = {}) {\n  int\
    \ N = G.N;\n  if (weight.empty()) weight.assign(N, 1);\n  vc<int> par(N, -1);\n\
    \  vc<int> V(N);\n  vc<ll> sz(N);\n  int l = 0, r = 0;\n  V[r++] = 0;\n  while\
    \ (l < r) {\n    int v = V[l++];\n    for (auto&& e : G[v])\n      if (e.to !=\
    \ par[v]) {\n        par[e.to] = v;\n        V[r++] = e.to;\n      }\n  }\n  FOR_R(i,\
    \ N) {\n    int v = V[i];\n    sz[v] += weight[v];\n    int p = par[v];\n    if\
    \ (p != -1) sz[p] += sz[v];\n  }\n\n  ll FULL = SUM<ll>(weight);\n  ll M = FULL\
    \ / 2;\n  auto check = [&](int v) -> bool {\n    if (FULL - sz[v] > M) return\
    \ false;\n    for (auto&& e : G[v]) {\n      if (e.to != par[v] && sz[e.to] >\
    \ M) return false;\n    }\n    return true;\n  };\n  pair<int, int> ANS = {-1,\
    \ -1};\n  FOR(v, N) if (check(v)) {\n    if (ANS.fi != -1) {\n      ANS.se = v;\n\
    \    } else {\n      ANS.fi = v;\n    }\n  }\n  return ANS;\n}\n#line 4 \"graph/centroid_decomposition_old.hpp\"\
    \n\n\ntemplate <typename GT>\nstruct Centroid_Decomposition {\n  using edge_type\
    \ = typename GT::edge_type;\n  GT& G;\n  int N;\n  vc<int> sz;\n  vc<int> par;\n\
    \  vector<int> cdep; // depth in centroid tree\n  bool calculated;\n\n  Centroid_Decomposition(GT&\
    \ G)\n      : G(G), N(G.N), sz(G.N), par(G.N), cdep(G.N, -1) {\n    calculated\
    \ = 0;\n    build();\n  }\n\nprivate:\n  int find(int v) {\n    vc<int> V = {v};\n\
    \    par[v] = -1;\n    int p = 0;\n    while (p < len(V)) {\n      int v = V[p++];\n\
    \      sz[v] = 0;\n      for (auto&& e: G[v]) {\n        if (e.to == par[v] ||\
    \ cdep[e.to] != -1) continue;\n        par[e.to] = v;\n        V.eb(e.to);\n \
    \     }\n    }\n    while (len(V)) {\n      int v = V.back();\n      V.pop_back();\n\
    \      sz[v] += 1;\n      if (p - sz[v] <= p / 2) return v;\n      sz[par[v]]\
    \ += sz[v];\n    }\n    return -1;\n  }\n  void build() {\n    assert(G.is_prepared());\n\
    \    assert(!calculated);\n    calculated = 1;\n\n    vc<pair<int, int>> st;\n\
    \    st.eb(0, 0);\n    while (!st.empty()) {\n      auto [lv, v] = st.back();\n\
    \      st.pop_back();\n      auto c = find(v);\n      cdep[c] = lv;\n      for\
    \ (auto&& e: G[c]) {\n        if (cdep[e.to] == -1) { st.eb(lv + 1, e.to); }\n\
    \      }\n    }\n  }\n\npublic:\n  // V, dat, indptr\n  template <typename T,\
    \ typename F>\n  tuple<vc<int>, vc<T>, vc<int>> collect_path_data(int root, T\
    \ root_val, F f) {\n    vc<int> V = {root};\n    vc<T> dp = {root_val};\n    vc<int>\
    \ indptr = {0, 1};\n    for (auto&& e: G[root]) {\n      int nxt = e.to;\n   \
    \   if (cdep[nxt] < cdep[root]) continue;\n      int p = len(V);\n      V.eb(nxt);\n\
    \      dp.eb(f(root_val, e));\n      par[nxt] = root;\n      while (p < len(V))\
    \ {\n        int v = V[p];\n        T val = dp[p];\n        p++;\n        for\
    \ (auto&& e: G[v]) {\n          if (e.to == par[v]) continue;\n          if (cdep[e.to]\
    \ < cdep[root]) continue;\n          par[e.to] = v;\n          V.eb(e.to);\n \
    \         dp.eb(f(val, e));\n        }\n      }\n      indptr.eb(len(V));\n  \
    \  }\n    return {V, dp, indptr};\n  }\n\n  // V, dist, indptr\n  tuple<vc<int>,\
    \ vc<int>, vc<int>> collect_dist(int root) {\n    auto f = [&](int x, auto e)\
    \ -> int { return x + 1; };\n    return collect_path_data(root, 0, f);\n  }\n\n\
    \  // (V, H, indptr), (V[i] in G) = (i in H).\n  // 0,1,2... is a dfs order in\
    \ H.\n  tuple<vc<int>, Graph<typename GT::cost_type, true>, vc<int>> get_subgraph(\n\
    \      int root) {\n    static vc<int> conv;\n    while (len(conv) < N) conv.eb(-1);\n\
    \n    vc<int> V = {root};\n    vc<int> indptr = {0, 1};\n    conv[root] = 0;\n\
    \    using cost_type = typename GT::cost_type;\n    vc<tuple<int, int, cost_type>>\
    \ edges;\n\n    auto dfs = [&](auto& dfs, int v, int p) -> void {\n      conv[v]\
    \ = len(V);\n      V.eb(v);\n      for (auto&& e: G[v]) {\n        int to = e.to;\n\
    \        if (to == p) continue;\n        if (cdep[to] < cdep[root]) continue;\n\
    \        dfs(dfs, to, v);\n        edges.eb(conv[v], conv[to], e.cost);\n    \
    \  }\n    };\n    for (auto&& e: G[root]) {\n      if (cdep[e.to] < cdep[root])\
    \ continue;\n      dfs(dfs, e.to, root);\n      edges.eb(conv[root], conv[e.to],\
    \ e.cost);\n      indptr.eb(len(V));\n    }\n    int n = len(V);\n    Graph<typename\
    \ GT::cost_type, true> H(n);\n    for (auto&& [a, b, c]: edges) H.add(a, b, c);\n\
    \    H.build();\n    for (auto&& v: V) conv[v] = -1;\n    return {V, H, indptr};\n\
    \  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/graph/centroid_decomposition_old.hpp\n\
    #include \"graph/base.hpp\"\n#include \"graph/find_centroid.hpp\"\n\n\ntemplate\
    \ <typename GT>\nstruct Centroid_Decomposition {\n  using edge_type = typename\
    \ GT::edge_type;\n  GT& G;\n  int N;\n  vc<int> sz;\n  vc<int> par;\n  vector<int>\
    \ cdep; // depth in centroid tree\n  bool calculated;\n\n  Centroid_Decomposition(GT&\
    \ G)\n      : G(G), N(G.N), sz(G.N), par(G.N), cdep(G.N, -1) {\n    calculated\
    \ = 0;\n    build();\n  }\n\nprivate:\n  int find(int v) {\n    vc<int> V = {v};\n\
    \    par[v] = -1;\n    int p = 0;\n    while (p < len(V)) {\n      int v = V[p++];\n\
    \      sz[v] = 0;\n      for (auto&& e: G[v]) {\n        if (e.to == par[v] ||\
    \ cdep[e.to] != -1) continue;\n        par[e.to] = v;\n        V.eb(e.to);\n \
    \     }\n    }\n    while (len(V)) {\n      int v = V.back();\n      V.pop_back();\n\
    \      sz[v] += 1;\n      if (p - sz[v] <= p / 2) return v;\n      sz[par[v]]\
    \ += sz[v];\n    }\n    return -1;\n  }\n  void build() {\n    assert(G.is_prepared());\n\
    \    assert(!calculated);\n    calculated = 1;\n\n    vc<pair<int, int>> st;\n\
    \    st.eb(0, 0);\n    while (!st.empty()) {\n      auto [lv, v] = st.back();\n\
    \      st.pop_back();\n      auto c = find(v);\n      cdep[c] = lv;\n      for\
    \ (auto&& e: G[c]) {\n        if (cdep[e.to] == -1) { st.eb(lv + 1, e.to); }\n\
    \      }\n    }\n  }\n\npublic:\n  // V, dat, indptr\n  template <typename T,\
    \ typename F>\n  tuple<vc<int>, vc<T>, vc<int>> collect_path_data(int root, T\
    \ root_val, F f) {\n    vc<int> V = {root};\n    vc<T> dp = {root_val};\n    vc<int>\
    \ indptr = {0, 1};\n    for (auto&& e: G[root]) {\n      int nxt = e.to;\n   \
    \   if (cdep[nxt] < cdep[root]) continue;\n      int p = len(V);\n      V.eb(nxt);\n\
    \      dp.eb(f(root_val, e));\n      par[nxt] = root;\n      while (p < len(V))\
    \ {\n        int v = V[p];\n        T val = dp[p];\n        p++;\n        for\
    \ (auto&& e: G[v]) {\n          if (e.to == par[v]) continue;\n          if (cdep[e.to]\
    \ < cdep[root]) continue;\n          par[e.to] = v;\n          V.eb(e.to);\n \
    \         dp.eb(f(val, e));\n        }\n      }\n      indptr.eb(len(V));\n  \
    \  }\n    return {V, dp, indptr};\n  }\n\n  // V, dist, indptr\n  tuple<vc<int>,\
    \ vc<int>, vc<int>> collect_dist(int root) {\n    auto f = [&](int x, auto e)\
    \ -> int { return x + 1; };\n    return collect_path_data(root, 0, f);\n  }\n\n\
    \  // (V, H, indptr), (V[i] in G) = (i in H).\n  // 0,1,2... is a dfs order in\
    \ H.\n  tuple<vc<int>, Graph<typename GT::cost_type, true>, vc<int>> get_subgraph(\n\
    \      int root) {\n    static vc<int> conv;\n    while (len(conv) < N) conv.eb(-1);\n\
    \n    vc<int> V = {root};\n    vc<int> indptr = {0, 1};\n    conv[root] = 0;\n\
    \    using cost_type = typename GT::cost_type;\n    vc<tuple<int, int, cost_type>>\
    \ edges;\n\n    auto dfs = [&](auto& dfs, int v, int p) -> void {\n      conv[v]\
    \ = len(V);\n      V.eb(v);\n      for (auto&& e: G[v]) {\n        int to = e.to;\n\
    \        if (to == p) continue;\n        if (cdep[to] < cdep[root]) continue;\n\
    \        dfs(dfs, to, v);\n        edges.eb(conv[v], conv[to], e.cost);\n    \
    \  }\n    };\n    for (auto&& e: G[root]) {\n      if (cdep[e.to] < cdep[root])\
    \ continue;\n      dfs(dfs, e.to, root);\n      edges.eb(conv[root], conv[e.to],\
    \ e.cost);\n      indptr.eb(len(V));\n    }\n    int n = len(V);\n    Graph<typename\
    \ GT::cost_type, true> H(n);\n    for (auto&& [a, b, c]: edges) H.add(a, b, c);\n\
    \    H.build();\n    for (auto&& v: V) conv[v] = -1;\n    return {V, H, indptr};\n\
    \  }\n};\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/find_centroid.hpp
  isVerificationFile: false
  path: graph/centroid_decomposition_old.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1796.test.cpp
documentation_of: graph/centroid_decomposition_old.hpp
layout: document
redirect_from:
- /library/graph/centroid_decomposition_old.hpp
- /library/graph/centroid_decomposition_old.hpp.html
title: graph/centroid_decomposition_old.hpp
---
