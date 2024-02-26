---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: linalg/blackbox/det.hpp
    title: linalg/blackbox/det.hpp
  - icon: ':x:'
    path: linalg/blackbox/min_poly.hpp
    title: linalg/blackbox/min_poly.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: seq/find_linear_rec.hpp
    title: seq/find_linear_rec.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n\
    \    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) != M)\
    \ used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] = i;\n\
    \    Graph<T, directed> G(n);\n    vc<int> history;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          history.eb(e.id);\n          used_e[e.id] = 1;\n          int eid =\
    \ (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost, eid);\n\
    \        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for (auto&&\
    \ eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\nprivate:\n\
    \  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n   \
    \ for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
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
    \ y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return true;\n  }\n};\n\
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
    \ r;\r\n  return det;\r\n}\r\n#line 4 \"graph/count/BEST.hpp\"\n\n/*\n\u3072\u3068\
    \u3064\u9078\u3093\u3060\u8FBA\u304B\u3089\u59CB\u3081\u3066\u5168\u3066\u306E\
    \u8FBA\u3092\u901A\u308B closed walk \u3092\u6570\u3048\u308B.\n\u591A\u91CD\u8FBA\
    \u306F vc<int>(eid) \u3067\u6E21\u3059\uFF0C\u306A\u3051\u308C\u3070\u3059\u3079\
    \u3066 1. e.cost \u306F\u53C2\u7167\u3057\u306A\u3044.\n\u8FBA\u306F\u30E9\u30D9\
    \u30EB\u4ED8\u304D\u3067\u8003\u3048\u308B. \u591A\u91CD\u8FBA\u3092\u540C\u4E00\
    \u8996\u3059\u308B\u5834\u5408\u306A\u3069\u306F\u5F8C\u3067\u968E\u4E57\u3067\
    \u5272\u308B\u3053\u3068.\nO(N^2+NM) \uFF08 + \u6700\u5F8C\u306B\u91CD\u8907\u5EA6\
    \u306E\u968E\u4E57\u3092\u304B\u3051\u308B\uFF09\uFF0E\n*/\ntemplate <typename\
    \ mint, typename GT>\nmint BEST_theorem(GT G, vc<int> edge_multiplicity = {})\
    \ {\n  static_assert(GT::is_directed);\n  int N = G.N, M = G.M;\n  if (M == 0)\
    \ return 0;\n  if (edge_multiplicity.empty()) edge_multiplicity.assign(M, 1);\n\
    \  vc<int> vs;\n  for (auto& e: G.edges) {\n    if (edge_multiplicity[e.id] ==\
    \ 0) continue;\n    vs.eb(e.frm), vs.eb(e.to);\n  }\n\n  UNIQUE(vs);\n  G = G.rearrange(vs,\
    \ true);\n  N = G.N;\n\n  vc<int> indeg(N), outdeg(N);\n  vc<tuple<int, int, mint>>\
    \ mat;\n  for (auto& e: G.edges) {\n    int a = e.frm, b = e.to, x = edge_multiplicity[e.id];\n\
    \    outdeg[a] += x, indeg[b] += x;\n    if (a < N - 1 && b < N - 1) mat.eb(a,\
    \ b, -x);\n    if (a < N - 1) mat.eb(a, a, x);\n  }\n  FOR(v, N) if (indeg[v]\
    \ != outdeg[v]) return 0;\n\n  auto apply = [&](vc<mint> A) -> vc<mint> {\n  \
    \  vc<mint> B(N - 1);\n    for (auto& [a, b, c]: mat) B[b] += A[a] * c;\n    return\
    \ B;\n  };\n  mint d = blackbox_det<mint>(N - 1, apply);\n  for (auto& x: outdeg)\
    \ { d *= fact<mint>(x - 1); }\n  return d;\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n#include\
    \ \"linalg/blackbox/det.hpp\"\n\n/*\n\u3072\u3068\u3064\u9078\u3093\u3060\u8FBA\
    \u304B\u3089\u59CB\u3081\u3066\u5168\u3066\u306E\u8FBA\u3092\u901A\u308B closed\
    \ walk \u3092\u6570\u3048\u308B.\n\u591A\u91CD\u8FBA\u306F vc<int>(eid) \u3067\
    \u6E21\u3059\uFF0C\u306A\u3051\u308C\u3070\u3059\u3079\u3066 1. e.cost \u306F\u53C2\
    \u7167\u3057\u306A\u3044.\n\u8FBA\u306F\u30E9\u30D9\u30EB\u4ED8\u304D\u3067\u8003\
    \u3048\u308B. \u591A\u91CD\u8FBA\u3092\u540C\u4E00\u8996\u3059\u308B\u5834\u5408\
    \u306A\u3069\u306F\u5F8C\u3067\u968E\u4E57\u3067\u5272\u308B\u3053\u3068.\nO(N^2+NM)\
    \ \uFF08 + \u6700\u5F8C\u306B\u91CD\u8907\u5EA6\u306E\u968E\u4E57\u3092\u304B\u3051\
    \u308B\uFF09\uFF0E\n*/\ntemplate <typename mint, typename GT>\nmint BEST_theorem(GT\
    \ G, vc<int> edge_multiplicity = {}) {\n  static_assert(GT::is_directed);\n  int\
    \ N = G.N, M = G.M;\n  if (M == 0) return 0;\n  if (edge_multiplicity.empty())\
    \ edge_multiplicity.assign(M, 1);\n  vc<int> vs;\n  for (auto& e: G.edges) {\n\
    \    if (edge_multiplicity[e.id] == 0) continue;\n    vs.eb(e.frm), vs.eb(e.to);\n\
    \  }\n\n  UNIQUE(vs);\n  G = G.rearrange(vs, true);\n  N = G.N;\n\n  vc<int> indeg(N),\
    \ outdeg(N);\n  vc<tuple<int, int, mint>> mat;\n  for (auto& e: G.edges) {\n \
    \   int a = e.frm, b = e.to, x = edge_multiplicity[e.id];\n    outdeg[a] += x,\
    \ indeg[b] += x;\n    if (a < N - 1 && b < N - 1) mat.eb(a, b, -x);\n    if (a\
    \ < N - 1) mat.eb(a, a, x);\n  }\n  FOR(v, N) if (indeg[v] != outdeg[v]) return\
    \ 0;\n\n  auto apply = [&](vc<mint> A) -> vc<mint> {\n    vc<mint> B(N - 1);\n\
    \    for (auto& [a, b, c]: mat) B[b] += A[a] * c;\n    return B;\n  };\n  mint\
    \ d = blackbox_det<mint>(N - 1, apply);\n  for (auto& x: outdeg) { d *= fact<mint>(x\
    \ - 1); }\n  return d;\n}\n"
  dependsOn:
  - graph/base.hpp
  - ds/unionfind/unionfind.hpp
  - linalg/blackbox/det.hpp
  - linalg/blackbox/min_poly.hpp
  - seq/find_linear_rec.hpp
  - random/base.hpp
  isVerificationFile: false
  path: graph/count/BEST.hpp
  requiredBy: []
  timestamp: '2024-02-23 19:59:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/BEST.hpp
layout: document
redirect_from:
- /library/graph/count/BEST.hpp
- /library/graph/count/BEST.hpp.html
title: graph/count/BEST.hpp
---
