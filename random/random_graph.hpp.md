---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_K4.test.cpp
    title: test/1_mytest/count_K4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_P3P4P5.test.cpp
    title: test/1_mytest/count_P3P4P5.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_clique.test.cpp
    title: test/1_mytest/count_clique.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_indep_set.test.cpp
    title: test/1_mytest/count_indep_set.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_C4.test.cpp
    title: test/1_mytest/find_C4.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_cycle_minimum.test.cpp
    title: test/1_mytest/find_cycle_minimum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_even_cycle.test.cpp
    title: test/1_mytest/find_even_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/find_odd_cycle.test.cpp
    title: test/1_mytest/find_odd_cycle.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/incremental_scc.test.cpp
    title: test/1_mytest/incremental_scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching_line_graph.test.cpp
    title: test/1_mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/matching_ve.test.cpp
    title: test/1_mytest/matching_ve.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/remove_one_edge.test.cpp
    title: test/1_mytest/remove_one_edge.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/remove_one_vertex.test.cpp
    title: test/1_mytest/remove_one_vertex.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/rolling_hash_on_tree.test.cpp
    title: test/1_mytest/rolling_hash_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/st_numbering.test.cpp
    title: test/1_mytest/st_numbering.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tree_walk_gf.test.cpp
    title: test/1_mytest/tree_walk_gf.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
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
    \    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n#endif\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
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
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 2 \"ds/unionfind/unionfind.hpp\"\
    \n\nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n \
    \ UnionFind(int n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp\
    \ = m;\n    dat.assign(n, -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int\
    \ x) {\n    while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp <\
    \ 0) { return dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n\
    \  ll size(int x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i,\
    \ n) A[i] = (*this)[i];\n    return A;\n  }\n};\n#line 5 \"random/random_graph.hpp\"\
    \n\nvoid random_relabel(int N, vc<pair<int, int>>& G) {\n  shuffle(G);\n  vc<int>\
    \ A(N);\n  FOR(i, N) A[i] = i;\n  shuffle(A);\n  for (auto& [a, b]: G) a = A[a],\
    \ b = A[b];\n}\n\ntemplate <int DIRECTED>\nvc<pair<int, int>> random_graph(int\
    \ n, bool simple) {\n  vc<pair<int, int>> G, cand;\n  FOR(a, n) FOR(b, n) {\n\
    \    if (simple && a == b) continue;\n    if (!DIRECTED && a > b) continue;\n\
    \    cand.eb(a, b);\n  }\n  int m = RNG(0, len(cand) + 1);\n  set<int> ss;\n \
    \ FOR(m) {\n    while (1) {\n      int i = RNG(0, len(cand));\n      if (simple\
    \ && ss.count(i)) continue;\n      ss.insert(i);\n      auto [a, b] = cand[i];\n\
    \      G.eb(a, b);\n      break;\n    }\n  }\n  random_relabel(n, G);\n  return\
    \ G;\n}\n\nvc<pair<int, int>> random_tree(int n) {\n  vc<pair<int, int>> G;\n\
    \  FOR(i, 1, n) { G.eb(RNG(0, i), i); }\n  random_relabel(n, G);\n  return G;\n\
    }\n\n// EDGE = true: \u5404\u8FBA\u304C\u552F\u4E00\u306E\u30B5\u30A4\u30AF\u30EB\
    \uFF08\u95A2\u7BC0\u70B9\u3067\u30B5\u30A4\u30AF\u30EB\u307E\u305F\u306F\u8FBA\
    \uFF09\n// EDGE = false\uFF1A \u5404\u9802\u70B9\u304C\u552F\u4E00\u306E\u30B5\
    \u30A4\u30AF\u30EB\uFF08\u6A4B\u3067\u30B5\u30A4\u30AF\u30EB\u307E\u305F\u306F\
    \u8FBA\uFF09\nvc<pair<int, int>> random_cactus(int N, bool EDGE) {\n  if (!EDGE)\
    \ {\n    // n \u9802\u70B9\u3092 1 \u307E\u305F\u306F 3 \u4EE5\u4E0A\u306B\u5206\
    \u5272\n    vvc<int> A;\n    int n = RNG(1, N + 1);\n    vc<int> S(n, 1);\n  \
    \  int rest = N - n;\n    while (rest > 0) {\n      int k = RNG(0, n);\n     \
    \ if (S[k] == 1) {\n        if (rest == 1) {\n          S.eb(1), rest = 0;\n \
    \       } else {\n          S[k] += 2, rest -= 2;\n        }\n      } else {\n\
    \        S[k]++, rest--;\n      }\n    }\n    n = len(S);\n    int p = 0;\n  \
    \  FOR(i, n) {\n      vc<int> C;\n      FOR(v, p, p + S[i]) C.eb(v);\n      A.eb(C);\n\
    \      p += S[i];\n    }\n    int m = len(A);\n    auto H = random_tree(m);\n\
    \    vc<pair<int, int>> G;\n    FOR(i, m) {\n      vc<int>& V = A[i];\n      if\
    \ (len(V) == 1) continue;\n      FOR(k, len(V)) { G.eb(V[k], V[(1 + k) % len(V)]);\
    \ }\n    }\n    for (auto& [c1, c2]: H) {\n      int a = A[c1][RNG(0, len(A[c1]))];\n\
    \      int b = A[c2][RNG(0, len(A[c2]))];\n      G.eb(a, b);\n    }\n    random_relabel(N,\
    \ G);\n    return G;\n  }\n  assert(EDGE);\n  if (N == 1) return {};\n  int n\
    \ = RNG(1, N);\n  vc<int> S(n, 2);\n  int rest = N - 1 - n;\n  while (rest > 0)\
    \ {\n    int k = RNG(0, n);\n    S[k]++, --rest;\n  }\n  vvc<int> A;\n  int p\
    \ = 0;\n  FOR(i, n) {\n    vc<int> C;\n    FOR(v, p, p + S[i]) C.eb(v);\n    A.eb(C);\n\
    \    p += S[i];\n  }\n  assert(p == N + n - 1);\n  UnionFind uf(p);\n  auto H\
    \ = random_tree(n);\n  for (auto& [c1, c2]: H) {\n    int a = A[c1][RNG(0, len(A[c1]))];\n\
    \    int b = A[c2][RNG(0, len(A[c2]))];\n    uf.merge(a, b);\n  }\n  vc<int> new_idx(p);\n\
    \  int x = 0;\n  FOR(i, p) if (uf[i] == i) new_idx[i] = x++;\n  assert(x == N);\n\
    \  FOR(i, p) new_idx[i] = new_idx[uf[i]];\n  vc<pair<int, int>> G;\n  FOR(i, n)\
    \ {\n    vc<int>& V = A[i];\n    for (auto& v: V) v = new_idx[v];\n    if (len(V)\
    \ == 2) {\n      G.eb(V[0], V[1]);\n    } else {\n      FOR(k, len(V)) { G.eb(V[k],\
    \ V[(1 + k) % len(V)]); }\n    }\n  }\n  random_relabel(N, G);\n  return G;\n\
    }\n"
  code: "#include \"graph/base.hpp\"\n#include \"random/base.hpp\"\n#include \"random/shuffle.hpp\"\
    \n#include \"ds/unionfind/unionfind.hpp\"\n\nvoid random_relabel(int N, vc<pair<int,\
    \ int>>& G) {\n  shuffle(G);\n  vc<int> A(N);\n  FOR(i, N) A[i] = i;\n  shuffle(A);\n\
    \  for (auto& [a, b]: G) a = A[a], b = A[b];\n}\n\ntemplate <int DIRECTED>\nvc<pair<int,\
    \ int>> random_graph(int n, bool simple) {\n  vc<pair<int, int>> G, cand;\n  FOR(a,\
    \ n) FOR(b, n) {\n    if (simple && a == b) continue;\n    if (!DIRECTED && a\
    \ > b) continue;\n    cand.eb(a, b);\n  }\n  int m = RNG(0, len(cand) + 1);\n\
    \  set<int> ss;\n  FOR(m) {\n    while (1) {\n      int i = RNG(0, len(cand));\n\
    \      if (simple && ss.count(i)) continue;\n      ss.insert(i);\n      auto [a,\
    \ b] = cand[i];\n      G.eb(a, b);\n      break;\n    }\n  }\n  random_relabel(n,\
    \ G);\n  return G;\n}\n\nvc<pair<int, int>> random_tree(int n) {\n  vc<pair<int,\
    \ int>> G;\n  FOR(i, 1, n) { G.eb(RNG(0, i), i); }\n  random_relabel(n, G);\n\
    \  return G;\n}\n\n// EDGE = true: \u5404\u8FBA\u304C\u552F\u4E00\u306E\u30B5\u30A4\
    \u30AF\u30EB\uFF08\u95A2\u7BC0\u70B9\u3067\u30B5\u30A4\u30AF\u30EB\u307E\u305F\
    \u306F\u8FBA\uFF09\n// EDGE = false\uFF1A \u5404\u9802\u70B9\u304C\u552F\u4E00\
    \u306E\u30B5\u30A4\u30AF\u30EB\uFF08\u6A4B\u3067\u30B5\u30A4\u30AF\u30EB\u307E\
    \u305F\u306F\u8FBA\uFF09\nvc<pair<int, int>> random_cactus(int N, bool EDGE) {\n\
    \  if (!EDGE) {\n    // n \u9802\u70B9\u3092 1 \u307E\u305F\u306F 3 \u4EE5\u4E0A\
    \u306B\u5206\u5272\n    vvc<int> A;\n    int n = RNG(1, N + 1);\n    vc<int> S(n,\
    \ 1);\n    int rest = N - n;\n    while (rest > 0) {\n      int k = RNG(0, n);\n\
    \      if (S[k] == 1) {\n        if (rest == 1) {\n          S.eb(1), rest = 0;\n\
    \        } else {\n          S[k] += 2, rest -= 2;\n        }\n      } else {\n\
    \        S[k]++, rest--;\n      }\n    }\n    n = len(S);\n    int p = 0;\n  \
    \  FOR(i, n) {\n      vc<int> C;\n      FOR(v, p, p + S[i]) C.eb(v);\n      A.eb(C);\n\
    \      p += S[i];\n    }\n    int m = len(A);\n    auto H = random_tree(m);\n\
    \    vc<pair<int, int>> G;\n    FOR(i, m) {\n      vc<int>& V = A[i];\n      if\
    \ (len(V) == 1) continue;\n      FOR(k, len(V)) { G.eb(V[k], V[(1 + k) % len(V)]);\
    \ }\n    }\n    for (auto& [c1, c2]: H) {\n      int a = A[c1][RNG(0, len(A[c1]))];\n\
    \      int b = A[c2][RNG(0, len(A[c2]))];\n      G.eb(a, b);\n    }\n    random_relabel(N,\
    \ G);\n    return G;\n  }\n  assert(EDGE);\n  if (N == 1) return {};\n  int n\
    \ = RNG(1, N);\n  vc<int> S(n, 2);\n  int rest = N - 1 - n;\n  while (rest > 0)\
    \ {\n    int k = RNG(0, n);\n    S[k]++, --rest;\n  }\n  vvc<int> A;\n  int p\
    \ = 0;\n  FOR(i, n) {\n    vc<int> C;\n    FOR(v, p, p + S[i]) C.eb(v);\n    A.eb(C);\n\
    \    p += S[i];\n  }\n  assert(p == N + n - 1);\n  UnionFind uf(p);\n  auto H\
    \ = random_tree(n);\n  for (auto& [c1, c2]: H) {\n    int a = A[c1][RNG(0, len(A[c1]))];\n\
    \    int b = A[c2][RNG(0, len(A[c2]))];\n    uf.merge(a, b);\n  }\n  vc<int> new_idx(p);\n\
    \  int x = 0;\n  FOR(i, p) if (uf[i] == i) new_idx[i] = x++;\n  assert(x == N);\n\
    \  FOR(i, p) new_idx[i] = new_idx[uf[i]];\n  vc<pair<int, int>> G;\n  FOR(i, n)\
    \ {\n    vc<int>& V = A[i];\n    for (auto& v: V) v = new_idx[v];\n    if (len(V)\
    \ == 2) {\n      G.eb(V[0], V[1]);\n    } else {\n      FOR(k, len(V)) { G.eb(V[k],\
    \ V[(1 + k) % len(V)]); }\n    }\n  }\n  random_relabel(N, G);\n  return G;\n\
    }\n"
  dependsOn:
  - graph/base.hpp
  - random/base.hpp
  - random/shuffle.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: random/random_graph.hpp
  requiredBy: []
  timestamp: '2024-09-14 09:20:23+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/st_numbering.test.cpp
  - test/1_mytest/incremental_scc.test.cpp
  - test/1_mytest/rolling_hash_on_tree.test.cpp
  - test/1_mytest/count_P3P4P5.test.cpp
  - test/1_mytest/count_indep_set.test.cpp
  - test/1_mytest/remove_one_vertex.test.cpp
  - test/1_mytest/find_C4.test.cpp
  - test/1_mytest/matching_ve.test.cpp
  - test/1_mytest/find_even_cycle.test.cpp
  - test/1_mytest/find_odd_cycle.test.cpp
  - test/1_mytest/find_cycle_minimum.test.cpp
  - test/1_mytest/count_K4.test.cpp
  - test/1_mytest/tree_walk_gf.test.cpp
  - test/1_mytest/count_clique.test.cpp
  - test/1_mytest/matching_line_graph.test.cpp
  - test/1_mytest/remove_one_edge.test.cpp
documentation_of: random/random_graph.hpp
layout: document
redirect_from:
- /library/random/random_graph.hpp
- /library/random/random_graph.hpp.html
title: random/random_graph.hpp
---
