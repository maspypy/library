---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/count_P3_P4_P5.hpp
    title: graph/count/count_P3_P4_P5.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_P3P4P5.test.cpp
    title: test/1_mytest/count_P3P4P5.test.cpp
  - icon: ':x:'
    path: test/1_mytest/find_C4.test.cpp
    title: test/1_mytest/find_C4.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://codeforces.com/gym/104053/problem/K
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
    #line 2 \"graph/count/count_C3_C4.hpp\"\n\n// \u5404\u70B9\u306B\u5BFE\u3057\u3066\
    \u305D\u306E\u70B9\u3092\u542B\u3080 C3, C4 \u3092\u6570\u3048\u308B\n// simple\
    \ graph \u3092\u4EEE\u5B9A\ntemplate <typename GT>\npair<vi, vi> count_C3_C4_pointwise(GT\
    \ &G) {\n  static_assert(!GT::is_directed);\n  int N = G.N;\n  auto deg = G.deg_array();\n\
    \  auto I = argsort(deg);\n  reverse(all(I));\n  vc<int> rk(N);\n  FOR(i, N) rk[I[i]]\
    \ = i;\n\n  // \u9077\u79FB\u5148\u3092\u964D\u9806\u306B\u4E26\u3079\u308B\n\
    \  vvc<int> TO(N);\n  for (auto &&e: G.edges) {\n    int a = rk[e.frm], b = rk[e.to];\n\
    \    TO[a].eb(b), TO[b].eb(a);\n  }\n  FOR(v, N) { sort(all(TO[v])), reverse(all(TO[v]));\
    \ }\n\n  vc<int> A(N);\n  vi C3(N), C4(N);\n  FOR(a, N) {\n    for (auto &b: TO[a])\
    \ TO[b].pop_back();\n    for (auto &b: TO[a]) {\n      for (auto &c: TO[b]) {\
    \ C4[a] += A[c], C4[c] += A[c], A[c] += 1; }\n    }\n    for (auto &b: TO[a])\
    \ {\n      C3[a] += A[b], C3[b] += A[b] + A[b];\n      for (auto &c: TO[b]) {\
    \ C4[b] += A[c] - 1; }\n    }\n    for (auto &b: TO[a]) {\n      for (auto &c:\
    \ TO[b]) { A[c] = 0; }\n    }\n  }\n  for (auto &x: C3) x /= 2;\n  C3 = rearrange(C3,\
    \ rk), C4 = rearrange(C4, rk);\n  return {C3, C4};\n}\n\n// (2e5,5e5) \u3067 500\
    \ ms\n// https://codeforces.com/gym/104053/problem/K\ntemplate <typename GT>\n\
    pair<ll, ll> count_C3_C4(GT &G) {\n  static_assert(!GT::is_directed);\n  int N\
    \ = G.N;\n  ll x3 = 0, x4 = 0;\n  auto deg = G.deg_array();\n  auto I = argsort(deg);\n\
    \  reverse(all(I));\n  vc<int> rk(N);\n  FOR(i, N) rk[I[i]] = i;\n\n  // \u9077\
    \u79FB\u5148\u3092\u964D\u9806\u306B\u4E26\u3079\u308B\n  vvc<int> TO(N);\n  for\
    \ (auto &&e: G.edges) {\n    int a = rk[e.frm], b = rk[e.to];\n    if (a != b)\
    \ TO[a].eb(b), TO[b].eb(a);\n  }\n  FOR(v, N) {\n    sort(all(TO[v]));\n    reverse(all(TO[v]));\n\
    \  }\n\n  vc<int> A(N);\n  FOR(a, N) {\n    for (auto &&b: TO[a]) TO[b].pop_back();\n\
    \    for (auto &&b: TO[a]) {\n      for (auto &&c: TO[b]) { x4 += A[c]++; }\n\
    \    }\n    for (auto &&b: TO[a]) { x3 += A[b]; }\n    for (auto &&b: TO[a]) {\n\
    \      for (auto &&c: TO[b]) { A[c] = 0; }\n    }\n  }\n  x3 /= 2;\n  return {x3,\
    \ x4};\n}\n"
  code: "#include \"graph/base.hpp\"\n\n// \u5404\u70B9\u306B\u5BFE\u3057\u3066\u305D\
    \u306E\u70B9\u3092\u542B\u3080 C3, C4 \u3092\u6570\u3048\u308B\n// simple graph\
    \ \u3092\u4EEE\u5B9A\ntemplate <typename GT>\npair<vi, vi> count_C3_C4_pointwise(GT\
    \ &G) {\n  static_assert(!GT::is_directed);\n  int N = G.N;\n  auto deg = G.deg_array();\n\
    \  auto I = argsort(deg);\n  reverse(all(I));\n  vc<int> rk(N);\n  FOR(i, N) rk[I[i]]\
    \ = i;\n\n  // \u9077\u79FB\u5148\u3092\u964D\u9806\u306B\u4E26\u3079\u308B\n\
    \  vvc<int> TO(N);\n  for (auto &&e: G.edges) {\n    int a = rk[e.frm], b = rk[e.to];\n\
    \    TO[a].eb(b), TO[b].eb(a);\n  }\n  FOR(v, N) { sort(all(TO[v])), reverse(all(TO[v]));\
    \ }\n\n  vc<int> A(N);\n  vi C3(N), C4(N);\n  FOR(a, N) {\n    for (auto &b: TO[a])\
    \ TO[b].pop_back();\n    for (auto &b: TO[a]) {\n      for (auto &c: TO[b]) {\
    \ C4[a] += A[c], C4[c] += A[c], A[c] += 1; }\n    }\n    for (auto &b: TO[a])\
    \ {\n      C3[a] += A[b], C3[b] += A[b] + A[b];\n      for (auto &c: TO[b]) {\
    \ C4[b] += A[c] - 1; }\n    }\n    for (auto &b: TO[a]) {\n      for (auto &c:\
    \ TO[b]) { A[c] = 0; }\n    }\n  }\n  for (auto &x: C3) x /= 2;\n  C3 = rearrange(C3,\
    \ rk), C4 = rearrange(C4, rk);\n  return {C3, C4};\n}\n\n// (2e5,5e5) \u3067 500\
    \ ms\n// https://codeforces.com/gym/104053/problem/K\ntemplate <typename GT>\n\
    pair<ll, ll> count_C3_C4(GT &G) {\n  static_assert(!GT::is_directed);\n  int N\
    \ = G.N;\n  ll x3 = 0, x4 = 0;\n  auto deg = G.deg_array();\n  auto I = argsort(deg);\n\
    \  reverse(all(I));\n  vc<int> rk(N);\n  FOR(i, N) rk[I[i]] = i;\n\n  // \u9077\
    \u79FB\u5148\u3092\u964D\u9806\u306B\u4E26\u3079\u308B\n  vvc<int> TO(N);\n  for\
    \ (auto &&e: G.edges) {\n    int a = rk[e.frm], b = rk[e.to];\n    if (a != b)\
    \ TO[a].eb(b), TO[b].eb(a);\n  }\n  FOR(v, N) {\n    sort(all(TO[v]));\n    reverse(all(TO[v]));\n\
    \  }\n\n  vc<int> A(N);\n  FOR(a, N) {\n    for (auto &&b: TO[a]) TO[b].pop_back();\n\
    \    for (auto &&b: TO[a]) {\n      for (auto &&c: TO[b]) { x4 += A[c]++; }\n\
    \    }\n    for (auto &&b: TO[a]) { x3 += A[b]; }\n    for (auto &&b: TO[a]) {\n\
    \      for (auto &&c: TO[b]) { A[c] = 0; }\n    }\n  }\n  x3 /= 2;\n  return {x3,\
    \ x4};\n}\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: false
  path: graph/count/count_C3_C4.hpp
  requiredBy:
  - graph/count/count_P3_P4_P5.hpp
  timestamp: '2025-04-06 22:14:02+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/count_P3P4P5.test.cpp
  - test/1_mytest/find_C4.test.cpp
documentation_of: graph/count/count_C3_C4.hpp
layout: document
redirect_from:
- /library/graph/count/count_C3_C4.hpp
- /library/graph/count/count_C3_C4.hpp.html
title: graph/count/count_C3_C4.hpp
---
