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
    path: graph/vs_to_es.hpp
    title: graph/vs_to_es.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/eulerwalk_d.test.cpp
    title: test/2_library_checker/graph/eulerwalk_d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/eulerwalk_ud.test.cpp
    title: test/2_library_checker/graph/eulerwalk_ud.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] =\
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64\
    \ -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n =\
    \ 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while (k\
    \ < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k),\
    \ used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E\
    . size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\
    \n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap = (mask + 1) /\
    \ 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if\
    \ (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return\
    \ val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\n    int\
    \ i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\
    \n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return used[i]\
    \ && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename F>\r\n\
    \  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\r\
    \n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val> val;\r\
    \n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\r\n    x += FIXED_RANDOM;\r\
    \n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\
    \n    return (x ^ (x >> 31)) & mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64,\
    \ Val>> dat;\r\n    dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used))\
    \ {\r\n      if (used[i]) dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\
    \n    for (auto& [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\
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
    #line 2 \"graph/vs_to_es.hpp\"\n\n#line 4 \"graph/vs_to_es.hpp\"\n\ntemplate <typename\
    \ GT>\nvc<int> vs_to_es(GT& G, vc<int>& vs, bool allow_use_twice = false) {\n\
    \  assert(!vs.empty());\n\n  HashMap<int> MP(G.M);\n  vc<int> nxt(G.M, -1);\n\n\
    \  auto get = [&](ll a, ll b) -> u64 {\n    if (!GT::is_directed && a > b) swap(a,\
    \ b);\n    return a * G.N + b;\n  };\n\n  FOR(eid, G.M) {\n    u64 k = get(G.edges[eid].frm,\
    \ G.edges[eid].to);\n    int x = MP.get(k, -1);\n    nxt[eid] = x, MP[k] = eid;\n\
    \  }\n  int n = len(vs);\n  vc<int> es(n - 1);\n  FOR(i, n - 1) {\n    u64 k =\
    \ get(vs[i], vs[i + 1]);\n    int eid = MP.get(k, -1);\n    assert(eid != -1);\n\
    \    es[i] = eid;\n    if (!allow_use_twice) { MP[k] = nxt[eid]; }\n  }\n  return\
    \ es;\n}\n#line 4 \"graph/eulerwalk.hpp\"\n\r\n// (vs, es) or empty\r\ntemplate\
    \ <typename GT>\r\npair<vc<int>, vc<int>> euler_walk(GT& G, int s = -1) {\r\n\
    \  const int N = G.N, M = G.M;\r\n  assert(G.is_prepared());\r\n  assert(N > 0);\r\
    \n  assert((s == -1) || (0 < s && s < N));\r\n\r\n  if (s == -1) {\r\n    vc<int>\
    \ deg(N);\r\n    for (auto&& e: G.edges) {\r\n      if constexpr (GT::is_directed)\
    \ {\r\n        deg[e.frm]++, deg[e.to]--;\r\n      } else {\r\n        deg[e.frm]++,\
    \ deg[e.to]++;\r\n      }\r\n    }\r\n    if constexpr (GT::is_directed) {\r\n\
    \      s = max_element(all(deg)) - deg.begin();\r\n      if (deg[s] == 0) s =\
    \ (M == 0 ? 0 : G.edges[0].frm);\r\n    } else {\r\n      s = [&]() -> int {\r\
    \n        FOR(v, N) if (deg[v] & 1) return v;\r\n        return (M == 0 ? 0 :\
    \ G.edges[0].frm);\r\n      }();\r\n    }\r\n  }\r\n\r\n  if (M == 0) return {{s},\
    \ {}};\r\n  vc<int> D(N), its(N), eu(M), vs, st = {s};\r\n  FOR(v, N) its[v] =\
    \ G.indptr[v];\r\n  ++D[s];\r\n  while (!st.empty()) {\r\n    int x = st.back(),\
    \ y, e, &it = its[x], end = G.indptr[x + 1];\r\n    if (it == end) {\r\n     \
    \ vs.eb(x);\r\n      st.pop_back();\r\n      continue;\r\n    }\r\n    auto& ee\
    \ = G.csr_edges[it++];\r\n    y = ee.to, e = ee.id;\r\n    if (!eu[e]) {\r\n \
    \     D[x]--, D[y]++;\r\n      eu[e] = 1;\r\n      st.eb(y);\r\n    }\r\n  }\r\
    \n  for (auto&& x: D)\r\n    if (x < 0) return {{}, {}};\r\n  if (len(vs) != M\
    \ + 1) return {{}, {}};\r\n  reverse(all(vs));\r\n  auto es = vs_to_es(G, vs,\
    \ false);\r\n  return {vs, es};\r\n}\r\n\r\ntemplate <typename GT>\r\nbool has_euler_walk(GT&\
    \ G, int s = -1) {\r\n  int N = G.N, M = G.M;\r\n  if (M == 0) return true;\r\n\
    \  if constexpr (!GT::is_directed) {\r\n    vc<int> odd(N);\r\n    for (auto&\
    \ e: G.edges) odd[e.frm] ^= 1, odd[e.to] ^= 1;\r\n    int n_odd = 0;\r\n    for\
    \ (auto x: odd) n_odd += x;\r\n\r\n    if (n_odd >= 4) return false;\r\n    if\
    \ (s != -1 && n_odd == 2 && !odd[s]) return false;\r\n    UnionFind uf(N);\r\n\
    \    for (auto& e: G.edges) uf.merge(e.frm, e.to);\r\n    vector<int> cnt_edge(N);\r\
    \n    for (auto& e: G.edges) cnt_edge[uf[e.frm]]++;\r\n    if (s != -1 && cnt_edge[uf[s]]\
    \ == 0) return false;\r\n    // \u8FBA\u304C\u3042\u308B\u6210\u5206\u3092\u6570\
    \u3048\u308B\r\n    int nc = 0;\r\n    for (int v = 0; v < N; ++v) {\r\n     \
    \ if (uf[v] == v && cnt_edge[v] >= 1) ++nc;\r\n    }\r\n    return nc <= 1;\r\n\
    \  } else {\r\n    int N = G.N;\r\n    vc<int> in(N), out(N);\r\n    for (auto&\
    \ e: G.edges) out[e.frm]++, in[e.to]++;\r\n\r\n    int ng = 0;\r\n    FOR(v, N)\
    \ ng += abs(out[v] - in[v]);\r\n    if (ng >= 4) return false;\r\n    if (s !=\
    \ -1 && ng == 2 && out[s] != in[s] + 1) return false;\r\n\r\n    UnionFind uf(N);\r\
    \n    for (auto& e: G.edges) uf.merge(e.frm, e.to);\r\n    vector<int> cnt_edge(N);\r\
    \n    for (auto& e: G.edges) cnt_edge[uf[e.frm]]++;\r\n    if (s != -1 && cnt_edge[uf[s]]\
    \ == 0) return false;\r\n    // \u8FBA\u304C\u3042\u308B\u6210\u5206\u3092\u6570\
    \u3048\u308B\r\n    int nc = 0;\r\n    for (int v = 0; v < N; ++v) {\r\n     \
    \ if (uf[v] == v && cnt_edge[v] >= 1) ++nc;\r\n    }\r\n    return nc <= 1;\r\n\
    \  }\r\n}\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\r\n#include \"graph/base.hpp\"\r\n\
    #include \"graph/vs_to_es.hpp\"\r\n\r\n// (vs, es) or empty\r\ntemplate <typename\
    \ GT>\r\npair<vc<int>, vc<int>> euler_walk(GT& G, int s = -1) {\r\n  const int\
    \ N = G.N, M = G.M;\r\n  assert(G.is_prepared());\r\n  assert(N > 0);\r\n  assert((s\
    \ == -1) || (0 < s && s < N));\r\n\r\n  if (s == -1) {\r\n    vc<int> deg(N);\r\
    \n    for (auto&& e: G.edges) {\r\n      if constexpr (GT::is_directed) {\r\n\
    \        deg[e.frm]++, deg[e.to]--;\r\n      } else {\r\n        deg[e.frm]++,\
    \ deg[e.to]++;\r\n      }\r\n    }\r\n    if constexpr (GT::is_directed) {\r\n\
    \      s = max_element(all(deg)) - deg.begin();\r\n      if (deg[s] == 0) s =\
    \ (M == 0 ? 0 : G.edges[0].frm);\r\n    } else {\r\n      s = [&]() -> int {\r\
    \n        FOR(v, N) if (deg[v] & 1) return v;\r\n        return (M == 0 ? 0 :\
    \ G.edges[0].frm);\r\n      }();\r\n    }\r\n  }\r\n\r\n  if (M == 0) return {{s},\
    \ {}};\r\n  vc<int> D(N), its(N), eu(M), vs, st = {s};\r\n  FOR(v, N) its[v] =\
    \ G.indptr[v];\r\n  ++D[s];\r\n  while (!st.empty()) {\r\n    int x = st.back(),\
    \ y, e, &it = its[x], end = G.indptr[x + 1];\r\n    if (it == end) {\r\n     \
    \ vs.eb(x);\r\n      st.pop_back();\r\n      continue;\r\n    }\r\n    auto& ee\
    \ = G.csr_edges[it++];\r\n    y = ee.to, e = ee.id;\r\n    if (!eu[e]) {\r\n \
    \     D[x]--, D[y]++;\r\n      eu[e] = 1;\r\n      st.eb(y);\r\n    }\r\n  }\r\
    \n  for (auto&& x: D)\r\n    if (x < 0) return {{}, {}};\r\n  if (len(vs) != M\
    \ + 1) return {{}, {}};\r\n  reverse(all(vs));\r\n  auto es = vs_to_es(G, vs,\
    \ false);\r\n  return {vs, es};\r\n}\r\n\r\ntemplate <typename GT>\r\nbool has_euler_walk(GT&\
    \ G, int s = -1) {\r\n  int N = G.N, M = G.M;\r\n  if (M == 0) return true;\r\n\
    \  if constexpr (!GT::is_directed) {\r\n    vc<int> odd(N);\r\n    for (auto&\
    \ e: G.edges) odd[e.frm] ^= 1, odd[e.to] ^= 1;\r\n    int n_odd = 0;\r\n    for\
    \ (auto x: odd) n_odd += x;\r\n\r\n    if (n_odd >= 4) return false;\r\n    if\
    \ (s != -1 && n_odd == 2 && !odd[s]) return false;\r\n    UnionFind uf(N);\r\n\
    \    for (auto& e: G.edges) uf.merge(e.frm, e.to);\r\n    vector<int> cnt_edge(N);\r\
    \n    for (auto& e: G.edges) cnt_edge[uf[e.frm]]++;\r\n    if (s != -1 && cnt_edge[uf[s]]\
    \ == 0) return false;\r\n    // \u8FBA\u304C\u3042\u308B\u6210\u5206\u3092\u6570\
    \u3048\u308B\r\n    int nc = 0;\r\n    for (int v = 0; v < N; ++v) {\r\n     \
    \ if (uf[v] == v && cnt_edge[v] >= 1) ++nc;\r\n    }\r\n    return nc <= 1;\r\n\
    \  } else {\r\n    int N = G.N;\r\n    vc<int> in(N), out(N);\r\n    for (auto&\
    \ e: G.edges) out[e.frm]++, in[e.to]++;\r\n\r\n    int ng = 0;\r\n    FOR(v, N)\
    \ ng += abs(out[v] - in[v]);\r\n    if (ng >= 4) return false;\r\n    if (s !=\
    \ -1 && ng == 2 && out[s] != in[s] + 1) return false;\r\n\r\n    UnionFind uf(N);\r\
    \n    for (auto& e: G.edges) uf.merge(e.frm, e.to);\r\n    vector<int> cnt_edge(N);\r\
    \n    for (auto& e: G.edges) cnt_edge[uf[e.frm]]++;\r\n    if (s != -1 && cnt_edge[uf[s]]\
    \ == 0) return false;\r\n    // \u8FBA\u304C\u3042\u308B\u6210\u5206\u3092\u6570\
    \u3048\u308B\r\n    int nc = 0;\r\n    for (int v = 0; v < N; ++v) {\r\n     \
    \ if (uf[v] == v && cnt_edge[v] >= 1) ++nc;\r\n    }\r\n    return nc <= 1;\r\n\
    \  }\r\n}"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/vs_to_es.hpp
  isVerificationFile: false
  path: graph/eulerwalk.hpp
  requiredBy: []
  timestamp: '2025-04-06 22:14:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/graph/eulerwalk_ud.test.cpp
  - test/2_library_checker/graph/eulerwalk_d.test.cpp
documentation_of: graph/eulerwalk.hpp
layout: document
redirect_from:
- /library/graph/eulerwalk.hpp
- /library/graph/eulerwalk.hpp.html
title: graph/eulerwalk.hpp
---
