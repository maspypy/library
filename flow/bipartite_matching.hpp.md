---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/bipartite_vertex_coloring.hpp
    title: graph/bipartite_vertex_coloring.hpp
  - icon: ':question:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: graph/bipartite_balanced_edge_coloring.hpp
    title: graph/bipartite_balanced_edge_coloring.hpp
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_edge_coloring.hpp
    title: graph/bipartite_edge_coloring.hpp
  - icon: ':x:'
    path: graph/maximum_antichain.hpp
    title: graph/maximum_antichain.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching_ve.test.cpp
    title: test/1_mytest/matching_ve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tutte.test.cpp
    title: test/1_mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
    title: test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/bipartitematching.test.cpp
    title: test/2_library_checker/graph/bipartitematching.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1479.test.cpp
    title: test/3_yukicoder/1479.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1744.test.cpp
    title: test/3_yukicoder/1744.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1745.test.cpp
    title: test/3_yukicoder/1745.test.cpp
  - icon: ':x:'
    path: test/4_aoj/1566.test.cpp
    title: test/4_aoj/1566.test.cpp
  - icon: ':x:'
    path: test/4_aoj/2251_2.test.cpp
    title: test/4_aoj/2251_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf
    - https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition
    - https://github.com/maspypy/library/blob/main/flow/bipartite_matching.hpp
    - https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html
  bundledCode: "#line 1 \"flow/bipartite_matching.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/flow/bipartite_matching.hpp\n\
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
    \   }\n  }\n};\n#line 1 \"graph/bipartite_vertex_coloring.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/bipartite_vertex_coloring.hpp\n\
    \n#line 1 \"graph/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/base.hpp\n\
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
    \   }\n  }\n};\n#line 1 \"ds/unionfind/unionfind.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/unionfind/unionfind.hpp\n\
    \nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int\
    \ n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n,\
    \ -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n   \
    \ while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return\
    \ dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int\
    \ x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int\
    \ y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n \
    \   if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i,\
    \ n) A[i] = (*this)[i];\n    return A;\n  }\n};\n#line 5 \"graph/bipartite_vertex_coloring.hpp\"\
    \n\n// \u73FE\u5728\u306E\u8FBA\u91CD\u307F\u5076\u5947\u3067\u4E8C\u90E8\u30B0\
    \u30E9\u30D5\u9802\u70B9\u5F69\u8272, \u4E8C\u90E8\u3067\u306A\u304B\u3063\u305F\
    \u5834\u5408\u306B\u306F empty\n// weight_one=true: \u8FBA\u91CD\u307F\u3092 1\
    \ \u3068\u3059\u308B\ntemplate <typename GT>\nvc<int> bipartite_vertex_coloring(GT&\
    \ G, bool weight_one = false) {\n  assert(!GT::is_directed);\n  assert(G.is_prepared());\n\
    \n  int n = G.N;\n  UnionFind uf(2 * n);\n  for (auto&& e : G.edges) {\n    int\
    \ u = e.frm, v = e.to, c = (weight_one ? 1 : e.cost);\n    if (c % 2 == 0) {\n\
    \      uf.merge(u, v), uf.merge(u + n, v + n);\n    } else {\n      uf.merge(u\
    \ + n, v), uf.merge(u, v + n);\n    }\n  }\n\n  vc<int> color(2 * n, -1);\n  FOR(v,\
    \ n) if (uf[v] == v && color[uf[v]] < 0) {\n    color[uf[v]] = 0;\n    color[uf[v\
    \ + n]] = 1;\n  }\n  FOR(v, n) color[v] = color[uf[v]];\n  color.resize(n);\n\
    \  FOR(v, n) if (uf[v] == uf[v + n]) return {};\n  return color;\n}\n#line 1 \"\
    graph/strongly_connected_component.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/strongly_connected_component.hpp\n\
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
    \   }\n  }\n};\n#line 3 \"graph/strongly_connected_component.hpp\"\n\ntemplate\
    \ <typename GT>\npair<int, vc<int>> strongly_connected_component(GT& G) {\n  static_assert(GT::is_directed);\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  int C = 0;\n  vc<int> comp(N),\
    \ low(N), ord(N, -1), path;\n  int now = 0;\n\n  auto dfs = [&](auto& dfs, int\
    \ v) -> void {\n    low[v] = ord[v] = now++;\n    path.eb(v);\n    for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n        dfs(dfs, to),\
    \ chmin(low[v], low[to]);\n      } else {\n        chmin(low[v], ord[to]);\n \
    \     }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        int u\
    \ = POP(path);\n        ord[u] = N, comp[u] = C;\n        if (u == v) break;\n\
    \      }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs,\
    \ v);\n  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n  return {C, comp};\n}\n\n\
    template <typename GT>\nGraph<int, 1> scc_dag(GT& G, int C, vc<int>& comp) {\n\
    \  Graph<int, 1> DAG(C);\n  vvc<int> edges(C);\n  for (auto&& e: G.edges) {\n\
    \    int x = comp[e.frm], y = comp[e.to];\n    if (x == y) continue;\n    edges[x].eb(y);\n\
    \  }\n  FOR(c, C) {\n    UNIQUE(edges[c]);\n    for (auto&& to: edges[c]) DAG.add(c,\
    \ to);\n  }\n  DAG.build();\n  return DAG;\n}\n#line 5 \"flow/bipartite_matching.hpp\"\
    \n\ntemplate <typename GT>\nstruct Bipartite_Matching {\n  int N;\n  GT& G;\n\
    \  vc<int> color;\n  vc<int> dist, match;\n  vc<int> vis;\n\n  Bipartite_Matching(GT&\
    \ G) : N(G.N), G(G), dist(G.N, -1), match(G.N, -1) {\n    color = bipartite_vertex_coloring(G);\n\
    \    if (N > 0) assert(!color.empty());\n    while (1) {\n      bfs();\n     \
    \ vis.assign(N, false);\n      int flow = 0;\n      FOR(v, N) if (!color[v] &&\
    \ match[v] == -1 && dfs(v))++ flow;\n      if (!flow) break;\n    }\n  }\n\n \
    \ Bipartite_Matching(GT& G, vc<int> color)\n      : N(G.N), G(G), color(color),\
    \ dist(G.N, -1), match(G.N, -1) {\n    while (1) {\n      bfs();\n      vis.assign(N,\
    \ false);\n      int flow = 0;\n      FOR(v, N) if (!color[v] && match[v] == -1\
    \ && dfs(v))++ flow;\n      if (!flow) break;\n    }\n  }\n\n  void bfs() {\n\
    \    dist.assign(N, -1);\n    queue<int> que;\n    FOR(v, N) if (!color[v] &&\
    \ match[v] == -1) que.emplace(v), dist[v] = 0;\n    while (!que.empty()) {\n \
    \     int v = que.front();\n      que.pop();\n      for (auto&& e : G[v]) {\n\
    \        dist[e.to] = 0;\n        int w = match[e.to];\n        if (w != -1 &&\
    \ dist[w] == -1) dist[w] = dist[v] + 1, que.emplace(w);\n      }\n    }\n  }\n\
    \n  bool dfs(int v) {\n    vis[v] = 1;\n    for (auto&& e : G[v]) {\n      int\
    \ w = match[e.to];\n      if (w == -1 || (!vis[w] && dist[w] == dist[v] + 1 &&\
    \ dfs(w))) {\n        match[e.to] = v, match[v] = e.to;\n        return true;\n\
    \      }\n    }\n    return false;\n  }\n\n  vc<pair<int, int>> matching() {\n\
    \    vc<pair<int, int>> res;\n    FOR(v, N) if (v < match[v]) res.eb(v, match[v]);\n\
    \    return res;\n  }\n\n  vc<int> vertex_cover() {\n    vc<int> res;\n    FOR(v,\
    \ N) if (color[v] ^ (dist[v] == -1)) { res.eb(v); }\n    return res;\n  }\n\n\
    \  vc<int> independent_set() {\n    vc<int> res;\n    FOR(v, N) if (!(color[v]\
    \ ^ (dist[v] == -1))) { res.eb(v); }\n    return res;\n  }\n\n  vc<int> edge_cover()\
    \ {\n    vc<bool> done(N);\n    vc<int> res;\n    for (auto&& e : G.edges) {\n\
    \      if (done[e.frm] || done[e.to]) continue;\n      if (match[e.frm] == e.to)\
    \ {\n        res.eb(e.id);\n        done[e.frm] = done[e.to] = 1;\n      }\n \
    \   }\n    for (auto&& e : G.edges) {\n      if (!done[e.frm]) {\n        res.eb(e.id);\n\
    \        done[e.frm] = 1;\n      }\n      if (!done[e.to]) {\n        res.eb(e.id);\n\
    \        done[e.to] = 1;\n      }\n    }\n    sort(all(res));\n    return res;\n\
    \  }\n\n  /* Dulmage\u2013Mendelsohn decomposition\n  https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition\n\
    \  http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf\n\
    \  https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html\n\
    \  - \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3068\u3057\u3066\u3042\u308A\u3046\
    \u308B iff \u540C\u3058 W \u3092\u6301\u3064\n  - \u8FBA uv \u304C\u5FC5\u305A\
    \u4F7F\u308F\u308C\u308B\uFF1A\u540C\u3058 W \u3092\u6301\u3064\u8FBA\u304C\u552F\
    \u4E00\n  - \u8FBA uv \u306F\u4F7F\u308F\u308C\u308B\u3053\u3068\u306F\u306A\u3044\
    \uFF1AW[l] ! =W[r]\n  - color=0 \u304B\u3089 1 \u3078\u306E\u8FBA\uFF1AW[l] <=\
    \ W[r]\n  - color=0 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\uFF1A\
    W=1,2,...,K\n  - color=1 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\
    \uFF1AW=0,1,...,K-1\n  */\n  pair<int, vc<int>> DM_decomposition() {\n    // \u975E\
    \u98FD\u548C\u70B9\u304B\u3089\u306E\u63A2\u7D22\n    vc<int> W(N, -1);\n    vc<int>\
    \ que;\n    auto add = [&](int v, int x) -> void {\n      if (W[v] == -1) {\n\
    \        W[v] = x;\n        que.eb(v);\n      }\n    };\n    FOR(v, N) if (match[v]\
    \ == -1 && color[v] == 0) add(v, 0);\n    FOR(v, N) if (match[v] == -1 && color[v]\
    \ == 1) add(v, infty<int>);\n    while (len(que)) {\n      auto v = POP(que);\n\
    \      if (match[v] != -1) add(match[v], W[v]);\n      if (color[v] == 0 && W[v]\
    \ == 0) {\n        for (auto&& e : G[v]) {\n          add(e.to, W[v]);\n     \
    \   }\n      }\n      if (color[v] == 1 && W[v] == infty<int>) {\n        for\
    \ (auto&& e : G[v]) {\n          add(e.to, W[v]);\n        }\n      }\n    }\n\
    \    // \u6B8B\u3063\u305F\u70B9\u304B\u3089\u306A\u308B\u30B0\u30E9\u30D5\u3092\
    \u4F5C\u3063\u3066\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n    vc<int> V;\n\
    \    FOR(v, N) if (W[v] == -1) V.eb(v);\n    int n = len(V);\n    Graph<bool,\
    \ 1> DG(n);\n    FOR(i, n) {\n      int v = V[i];\n      if (match[v] != -1) {\n\
    \        int j = LB(V, match[v]);\n        DG.add(i, j);\n      }\n      if (color[v]\
    \ == 0) {\n        for (auto&& e : G[v]) {\n          if (W[e.to] != -1 || e.to\
    \ == match[v]) continue;\n          int j = LB(V, e.to);\n          DG.add(i,\
    \ j);\n        }\n      }\n    }\n    DG.build();\n    auto [K, comp] = strongly_connected_component(DG);\n\
    \    K += 1;\n    // \u7B54\n    FOR(i, n) { W[V[i]] = 1 + comp[i]; }\n    FOR(v,\
    \ N) if (W[v] == infty<int>) W[v] = K;\n    return {K, W};\n  }\n\n#ifdef FASTIO\n\
    \  void debug() {\n    print(\"match\", match);\n    print(\"min vertex covor\"\
    , vertex_cover());\n    print(\"max indep set\", independent_set());\n    print(\"\
    min edge cover\", edge_cover());\n  }\n#endif\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/flow/bipartite_matching.hpp\n\
    #include \"graph/base.hpp\"\n#include \"graph/bipartite_vertex_coloring.hpp\"\n\
    #include \"graph/strongly_connected_component.hpp\"\n\ntemplate <typename GT>\n\
    struct Bipartite_Matching {\n  int N;\n  GT& G;\n  vc<int> color;\n  vc<int> dist,\
    \ match;\n  vc<int> vis;\n\n  Bipartite_Matching(GT& G) : N(G.N), G(G), dist(G.N,\
    \ -1), match(G.N, -1) {\n    color = bipartite_vertex_coloring(G);\n    if (N\
    \ > 0) assert(!color.empty());\n    while (1) {\n      bfs();\n      vis.assign(N,\
    \ false);\n      int flow = 0;\n      FOR(v, N) if (!color[v] && match[v] == -1\
    \ && dfs(v))++ flow;\n      if (!flow) break;\n    }\n  }\n\n  Bipartite_Matching(GT&\
    \ G, vc<int> color)\n      : N(G.N), G(G), color(color), dist(G.N, -1), match(G.N,\
    \ -1) {\n    while (1) {\n      bfs();\n      vis.assign(N, false);\n      int\
    \ flow = 0;\n      FOR(v, N) if (!color[v] && match[v] == -1 && dfs(v))++ flow;\n\
    \      if (!flow) break;\n    }\n  }\n\n  void bfs() {\n    dist.assign(N, -1);\n\
    \    queue<int> que;\n    FOR(v, N) if (!color[v] && match[v] == -1) que.emplace(v),\
    \ dist[v] = 0;\n    while (!que.empty()) {\n      int v = que.front();\n     \
    \ que.pop();\n      for (auto&& e : G[v]) {\n        dist[e.to] = 0;\n       \
    \ int w = match[e.to];\n        if (w != -1 && dist[w] == -1) dist[w] = dist[v]\
    \ + 1, que.emplace(w);\n      }\n    }\n  }\n\n  bool dfs(int v) {\n    vis[v]\
    \ = 1;\n    for (auto&& e : G[v]) {\n      int w = match[e.to];\n      if (w ==\
    \ -1 || (!vis[w] && dist[w] == dist[v] + 1 && dfs(w))) {\n        match[e.to]\
    \ = v, match[v] = e.to;\n        return true;\n      }\n    }\n    return false;\n\
    \  }\n\n  vc<pair<int, int>> matching() {\n    vc<pair<int, int>> res;\n    FOR(v,\
    \ N) if (v < match[v]) res.eb(v, match[v]);\n    return res;\n  }\n\n  vc<int>\
    \ vertex_cover() {\n    vc<int> res;\n    FOR(v, N) if (color[v] ^ (dist[v] ==\
    \ -1)) { res.eb(v); }\n    return res;\n  }\n\n  vc<int> independent_set() {\n\
    \    vc<int> res;\n    FOR(v, N) if (!(color[v] ^ (dist[v] == -1))) { res.eb(v);\
    \ }\n    return res;\n  }\n\n  vc<int> edge_cover() {\n    vc<bool> done(N);\n\
    \    vc<int> res;\n    for (auto&& e : G.edges) {\n      if (done[e.frm] || done[e.to])\
    \ continue;\n      if (match[e.frm] == e.to) {\n        res.eb(e.id);\n      \
    \  done[e.frm] = done[e.to] = 1;\n      }\n    }\n    for (auto&& e : G.edges)\
    \ {\n      if (!done[e.frm]) {\n        res.eb(e.id);\n        done[e.frm] = 1;\n\
    \      }\n      if (!done[e.to]) {\n        res.eb(e.id);\n        done[e.to]\
    \ = 1;\n      }\n    }\n    sort(all(res));\n    return res;\n  }\n\n  /* Dulmage\u2013\
    Mendelsohn decomposition\n  https://en.wikipedia.org/wiki/Dulmage%E2%80%93Mendelsohn_decomposition\n\
    \  http://www.misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf\n\
    \  https://hitonanode.github.io/cplib-cpp/graph/dulmage_mendelsohn_decomposition.hpp.html\n\
    \  - \u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\u3068\u3057\u3066\u3042\u308A\u3046\
    \u308B iff \u540C\u3058 W \u3092\u6301\u3064\n  - \u8FBA uv \u304C\u5FC5\u305A\
    \u4F7F\u308F\u308C\u308B\uFF1A\u540C\u3058 W \u3092\u6301\u3064\u8FBA\u304C\u552F\
    \u4E00\n  - \u8FBA uv \u306F\u4F7F\u308F\u308C\u308B\u3053\u3068\u306F\u306A\u3044\
    \uFF1AW[l] ! =W[r]\n  - color=0 \u304B\u3089 1 \u3078\u306E\u8FBA\uFF1AW[l] <=\
    \ W[r]\n  - color=0 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\uFF1A\
    W=1,2,...,K\n  - color=1 \u306E\u70B9\u304C\u5FC5\u305A\u4F7F\u308F\u308C\u308B\
    \uFF1AW=0,1,...,K-1\n  */\n  pair<int, vc<int>> DM_decomposition() {\n    // \u975E\
    \u98FD\u548C\u70B9\u304B\u3089\u306E\u63A2\u7D22\n    vc<int> W(N, -1);\n    vc<int>\
    \ que;\n    auto add = [&](int v, int x) -> void {\n      if (W[v] == -1) {\n\
    \        W[v] = x;\n        que.eb(v);\n      }\n    };\n    FOR(v, N) if (match[v]\
    \ == -1 && color[v] == 0) add(v, 0);\n    FOR(v, N) if (match[v] == -1 && color[v]\
    \ == 1) add(v, infty<int>);\n    while (len(que)) {\n      auto v = POP(que);\n\
    \      if (match[v] != -1) add(match[v], W[v]);\n      if (color[v] == 0 && W[v]\
    \ == 0) {\n        for (auto&& e : G[v]) {\n          add(e.to, W[v]);\n     \
    \   }\n      }\n      if (color[v] == 1 && W[v] == infty<int>) {\n        for\
    \ (auto&& e : G[v]) {\n          add(e.to, W[v]);\n        }\n      }\n    }\n\
    \    // \u6B8B\u3063\u305F\u70B9\u304B\u3089\u306A\u308B\u30B0\u30E9\u30D5\u3092\
    \u4F5C\u3063\u3066\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n    vc<int> V;\n\
    \    FOR(v, N) if (W[v] == -1) V.eb(v);\n    int n = len(V);\n    Graph<bool,\
    \ 1> DG(n);\n    FOR(i, n) {\n      int v = V[i];\n      if (match[v] != -1) {\n\
    \        int j = LB(V, match[v]);\n        DG.add(i, j);\n      }\n      if (color[v]\
    \ == 0) {\n        for (auto&& e : G[v]) {\n          if (W[e.to] != -1 || e.to\
    \ == match[v]) continue;\n          int j = LB(V, e.to);\n          DG.add(i,\
    \ j);\n        }\n      }\n    }\n    DG.build();\n    auto [K, comp] = strongly_connected_component(DG);\n\
    \    K += 1;\n    // \u7B54\n    FOR(i, n) { W[V[i]] = 1 + comp[i]; }\n    FOR(v,\
    \ N) if (W[v] == infty<int>) W[v] = K;\n    return {K, W};\n  }\n\n#ifdef FASTIO\n\
    \  void debug() {\n    print(\"match\", match);\n    print(\"min vertex covor\"\
    , vertex_cover());\n    print(\"max indep set\", independent_set());\n    print(\"\
    min edge cover\", edge_cover());\n  }\n#endif\n};\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/bipartite_vertex_coloring.hpp
  - ds/unionfind/unionfind.hpp
  - graph/strongly_connected_component.hpp
  isVerificationFile: false
  path: flow/bipartite_matching.hpp
  requiredBy:
  - graph/maximum_antichain.hpp
  - graph/bipartite_balanced_edge_coloring.hpp
  - graph/bipartite_edge_coloring.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/tutte.test.cpp
  - test/1_mytest/matching_ve.test.cpp
  - test/3_yukicoder/1744.test.cpp
  - test/3_yukicoder/1745.test.cpp
  - test/3_yukicoder/1479.test.cpp
  - test/2_library_checker/graph/bipartitematching.test.cpp
  - test/2_library_checker/graph/bipartite_edge_coloring.test.cpp
  - test/4_aoj/2251_2.test.cpp
  - test/4_aoj/1566.test.cpp
documentation_of: flow/bipartite_matching.hpp
layout: document
redirect_from:
- /library/flow/bipartite_matching.hpp
- /library/flow/bipartite_matching.hpp.html
title: flow/bipartite_matching.hpp
---
