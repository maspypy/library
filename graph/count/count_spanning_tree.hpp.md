---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: linalg/blackbox/det.hpp
    title: linalg/blackbox/det.hpp
  - icon: ':question:'
    path: linalg/blackbox/min_poly.hpp
    title: linalg/blackbox/min_poly.hpp
  - icon: ':question:'
    path: linalg/det.hpp
    title: linalg/det.hpp
  - icon: ':question:'
    path: mod/barrett.hpp
    title: mod/barrett.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':question:'
    path: seq/find_linear_rec.hpp
    title: seq/find_linear_rec.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/2_library_checker/graph/count_spanning_tree_directed_sparse_test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_directed_sparse_test.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/count/count_spanning_tree.hpp\"\n\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool\
    \ prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph*\
    \ G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n    int l, r;\n\
    \  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() : N(0), M(0),\
    \ prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int\
    \ n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n\
    \    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n\
    \  }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
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
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n\
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
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 2 \"mod/barrett.hpp\"\
    \n\n// https://github.com/atcoder/ac-library/blob/master/atcoder/internal_math.hpp\n\
    struct Barrett {\n  u32 m;\n  u64 im;\n  explicit Barrett(u32 m = 1) : m(m), im(u64(-1)\
    \ / m + 1) {}\n  u32 umod() const { return m; }\n  u32 modulo(u64 z) {\n    if\
    \ (m == 1) return 0;\n    u64 x = (u64)(((unsigned __int128)(z)*im) >> 64);\n\
    \    u64 y = x * m;\n    return (z - y + (z < y ? m : 0));\n  }\n  u64 floor(u64\
    \ z) {\n    if (m == 1) return z;\n    u64 x = (u64)(((unsigned __int128)(z)*im)\
    \ >> 64);\n    u64 y = x * m;\n    return (z < y ? x - 1 : x);\n  }\n  pair<u64,\
    \ u32> divmod(u64 z) {\n    if (m == 1) return {z, 0};\n    u64 x = (u64)(((unsigned\
    \ __int128)(z)*im) >> 64);\n    u64 y = x * m;\n    if (z < y) return {x - 1,\
    \ z - y + m};\n    return {x, z - y};\n  }\n  u32 mul(u32 a, u32 b) { return modulo(u64(a)\
    \ * b); }\n};\n\nstruct Barrett_64 {\n  u128 mod, mh, ml;\n\n  explicit Barrett_64(u64\
    \ mod = 1) : mod(mod) {\n    u128 m = u128(-1) / mod;\n    if (m * mod + mod ==\
    \ u128(0)) ++m;\n    mh = m >> 64;\n    ml = m & u64(-1);\n  }\n\n  u64 umod()\
    \ const { return mod; }\n\n  u64 modulo(u128 x) {\n    u128 z = (x & u64(-1))\
    \ * ml;\n    z = (x & u64(-1)) * mh + (x >> 64) * ml + (z >> 64);\n    z = (x\
    \ >> 64) * mh + (z >> 64);\n    x -= z * mod;\n    return x < mod ? x : x - mod;\n\
    \  }\n\n  u64 mul(u64 a, u64 b) { return modulo(u128(a) * b); }\n};\n#line 2 \"\
    linalg/det.hpp\"\n\r\nint det_mod(vvc<int> A, int mod) {\r\n  Barrett bt(mod);\r\
    \n  const int n = len(A);\r\n  ll det = 1;\r\n  FOR(i, n) {\r\n    FOR(j, i, n)\
    \ {\r\n      if (A[j][i] == 0) continue;\r\n      if (i != j) { swap(A[i], A[j]),\
    \ det = mod - det; }\r\n      break;\r\n    }\r\n    FOR(j, i + 1, n) {\r\n  \
    \    while (A[i][i] != 0) {\r\n        ll c = mod - A[j][i] / A[i][i];\r\n   \
    \     FOR_R(k, i, n) { A[j][k] = bt.modulo(A[j][k] + A[i][k] * c); }\r\n     \
    \   swap(A[i], A[j]), det = mod - det;\r\n      }\r\n      swap(A[i], A[j]), det\
    \ = mod - det;\r\n    }\r\n  }\r\n  FOR(i, n) det = bt.mul(det, A[i][i]);\r\n\
    \  return det % mod;\r\n}\r\n\r\ntemplate <typename mint>\r\nmint det(vvc<mint>&\
    \ A) {\r\n  const int n = len(A);\r\n  vv(int, B, n, n);\r\n  FOR(i, n) FOR(j,\
    \ n) B[i][j] = A[i][j].val;\r\n  return det_mod(B, mint::get_mod());\r\n}\r\n\
    #line 2 \"seq/find_linear_rec.hpp\"\n\r\ntemplate <typename mint>\r\nvector<mint>\
    \ find_linear_rec(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint> B = {1},\
    \ C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\n    mint\
    \ d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n    if (d ==\
    \ 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\n    mint\
    \ q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B) + m - len(C),\
    \ 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l + l <= i) {\r\n\
    \      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\n    } else {\r\
    \n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"linalg/blackbox/min_poly.hpp\"\
    \n\r\n// \u884C\u5217 A \u3092\u304B\u3051\u308B\u3053\u3068\u3092\u8868\u3059\
    \u7DDA\u5F62\u5909\u63DB f \u3092\u6E21\u3059\r\n// auto f = [&](vc<mint> v) ->\
    \ vc<mint> {};\r\ntemplate <typename mint, typename F>\r\nvc<mint> blackbox_min_poly(int\
    \ N, F f) {\r\n  vc<mint> S(N + N + 10);\r\n  vc<mint> c(N);\r\n  vc<mint> v(N);\r\
    \n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\n  FOR(i, N) v[i] = RNG(0, mint::get_mod());\r\
    \n  FOR(k, N + N + 10) {\r\n    FOR(i, N) S[k] += c[i] * v[i];\r\n    v = f(v);\r\
    \n  }\r\n  S = find_linear_rec(S);\r\n  reverse(all(S));\r\n  return S;\r\n}\r\
    \n#line 2 \"linalg/blackbox/det.hpp\"\n\r\ntemplate <typename mint, typename F>\r\
    \nmint blackbox_det(int N, F apply) {\r\n  vc<mint> c(N);\r\n  FOR(i, N) c[i]\
    \ = RNG(1, mint::get_mod());\r\n  mint r = 1;\r\n  FOR(i, N) r *= c[i];\r\n  auto\
    \ g = [&](vc<mint> v) -> vc<mint> {\r\n    FOR(i, N) v[i] *= c[i];\r\n    return\
    \ apply(v);\r\n  };\r\n  auto f = blackbox_min_poly<mint>(N, g);\r\n  mint det\
    \ = (len(f) == N + 1 ? f[0] : mint(0));\r\n  if (N & 1) det *= -1;\r\n  det /=\
    \ r;\r\n  return det;\r\n}\r\n#line 5 \"graph/count/count_spanning_tree.hpp\"\n\
    \ntemplate <typename mint, bool sparse, typename GT>\nmint count_spanning_tree_undirected(GT&\
    \ G) {\n  int N = G.N;\n  if constexpr (!sparse) {\n    vv(mint, mat, N, N);\n\
    \    for (auto& e: G.edges) {\n      int a = e.frm, b = e.to;\n      mat[a][a]\
    \ += 1, mat[a][b] -= 1, mat[b][a] -= 1, mat[b][b] += 1;\n    }\n    FOR(i, N)\
    \ POP(mat[i]);\n    POP(mat);\n    return det(mat);\n  } else {\n    auto apply\
    \ = [&](vc<mint>& f) -> vc<mint> {\n      vc<mint> g(N);\n      FOR(v, N - 1)\
    \ {\n        g[v] += f[v] * G.deg(v);\n        for (auto& e: G[v]) g[e.to] -=\
    \ f[v];\n      }\n      POP(g);\n      return g;\n    };\n    return blackbox_det<mint>(N\
    \ - 1, apply);\n  }\n}\n\n// out-rooted-tree\ntemplate <typename mint, bool sparse,\
    \ typename GT>\nmint count_spanning_tree_directed(GT& G, int r) {\n  int N = G.N;\n\
    \  if constexpr (!sparse) {\n    vv(mint, mat, N, N);\n    for (auto& e: G.edges)\
    \ {\n      int a = e.frm, b = e.to;\n      mat[b][b] += 1, mat[a][b] -= 1;\n \
    \   }\n    FOR(i, N) mat[i].erase(mat[i].begin() + r);\n    mat.erase(mat.begin()\
    \ + r);\n    return det(mat);\n  } else {\n    auto apply = [&](vc<mint>& f) ->\
    \ vc<mint> {\n      f.insert(f.begin() + r, 0);\n      vc<mint> g(N);\n      for\
    \ (auto& e: G.edges) { g[e.to] += f[e.to], g[e.to] -= f[e.frm]; }\n      g.erase(g.begin()\
    \ + r);\n      return g;\n    };\n    return blackbox_det<mint>(N - 1, apply);\n\
    \  }\n}\n"
  code: "\n#include \"graph/base.hpp\"\n#include \"linalg/det.hpp\"\n#include \"linalg/blackbox/det.hpp\"\
    \n\ntemplate <typename mint, bool sparse, typename GT>\nmint count_spanning_tree_undirected(GT&\
    \ G) {\n  int N = G.N;\n  if constexpr (!sparse) {\n    vv(mint, mat, N, N);\n\
    \    for (auto& e: G.edges) {\n      int a = e.frm, b = e.to;\n      mat[a][a]\
    \ += 1, mat[a][b] -= 1, mat[b][a] -= 1, mat[b][b] += 1;\n    }\n    FOR(i, N)\
    \ POP(mat[i]);\n    POP(mat);\n    return det(mat);\n  } else {\n    auto apply\
    \ = [&](vc<mint>& f) -> vc<mint> {\n      vc<mint> g(N);\n      FOR(v, N - 1)\
    \ {\n        g[v] += f[v] * G.deg(v);\n        for (auto& e: G[v]) g[e.to] -=\
    \ f[v];\n      }\n      POP(g);\n      return g;\n    };\n    return blackbox_det<mint>(N\
    \ - 1, apply);\n  }\n}\n\n// out-rooted-tree\ntemplate <typename mint, bool sparse,\
    \ typename GT>\nmint count_spanning_tree_directed(GT& G, int r) {\n  int N = G.N;\n\
    \  if constexpr (!sparse) {\n    vv(mint, mat, N, N);\n    for (auto& e: G.edges)\
    \ {\n      int a = e.frm, b = e.to;\n      mat[b][b] += 1, mat[a][b] -= 1;\n \
    \   }\n    FOR(i, N) mat[i].erase(mat[i].begin() + r);\n    mat.erase(mat.begin()\
    \ + r);\n    return det(mat);\n  } else {\n    auto apply = [&](vc<mint>& f) ->\
    \ vc<mint> {\n      f.insert(f.begin() + r, 0);\n      vc<mint> g(N);\n      for\
    \ (auto& e: G.edges) { g[e.to] += f[e.to], g[e.to] -= f[e.frm]; }\n      g.erase(g.begin()\
    \ + r);\n      return g;\n    };\n    return blackbox_det<mint>(N - 1, apply);\n\
    \  }\n}"
  dependsOn:
  - graph/base.hpp
  - linalg/det.hpp
  - mod/barrett.hpp
  - linalg/blackbox/det.hpp
  - linalg/blackbox/min_poly.hpp
  - seq/find_linear_rec.hpp
  - random/base.hpp
  isVerificationFile: false
  path: graph/count/count_spanning_tree.hpp
  requiredBy:
  - test/2_library_checker/graph/count_spanning_tree_directed_sparse_test.cpp
  timestamp: '2024-06-11 17:38:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
documentation_of: graph/count/count_spanning_tree.hpp
layout: document
redirect_from:
- /library/graph/count/count_spanning_tree.hpp
- /library/graph/count/count_spanning_tree.hpp.html
title: graph/count/count_spanning_tree.hpp
---
