---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: enumerate/bits.hpp
    title: enumerate/bits.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/114.test.cpp
    title: test/3_yukicoder/114.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
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
    #line 1 \"enumerate/bits.hpp\"\ntemplate <typename BS, typename F>\nvoid enumerate_bits_bitset(BS&\
    \ b, int L, int R, F f) {\n  if (L >= len(b)) return;\n  int p = (b[L] ? L : b._Find_next(L));\n\
    \  while (p < R) {\n    f(p);\n    p = b._Find_next(p);\n  }\n}\n#line 3 \"graph/steiner_tree.hpp\"\
    \n\n// \u8FBA\u91CD\u307F\u306F e.cost\u3001\u9802\u70B9\u91CD\u307F\u306F vector\
    \ \u3067\u6E21\u3059\u3002\u8FD4\u308A\u5024\uFF1A{cost, vs, es}\n// O(3^kn +\
    \ 2^k(n+m)log n), k: terminal size\ntemplate <typename T, typename GT>\ntuple<T,\
    \ vc<int>, vc<int>> steiner_tree(GT& G, vc<int> S, vc<T> v_wt = {}) {\n  static_assert(!GT::is_directed);\n\
    \  assert(!S.empty());\n  const int N = G.N, M = G.M, K = len(S);\n  if (v_wt.empty())\
    \ v_wt.assign(N, 0);\n\n  // \u30BF\u30FC\u30DF\u30CA\u30EB\u96C6\u5408, root\
    \ -> cost\n  vv(T, DP, 1 << K, N, infty<T>);\n  FOR(v, N) DP[0][v] = v_wt[v];\n\
    \n  // 2 * t or 2 * eid + 1\n  vv(int, par, 1 << K, N, -1);\n\n  for (int s =\
    \ 1; s < (1 << K); ++s) {\n    auto& dp = DP[s];\n    for (int k: all_bit<u32>(s))\
    \ {\n      int v = S[k];\n      chmin(dp[v], DP[s ^ 1 << k][v]);\n    }\n    for\
    \ (u32 t: all_subset<u32>(s)) {\n      if (t == 0 || t == s) continue;\n     \
    \ FOR(v, N) {\n        if (chmin(dp[v], DP[t][v] + DP[s ^ t][v] - v_wt[v])) par[s][v]\
    \ = 2 * t;\n      }\n    }\n    // \u6839\u306E\u79FB\u52D5\u3092 dijkstra \u3067\
    \n    pqg<pair<T, int>> que;\n    FOR(v, N) que.emplace(dp[v], v);\n    while\
    \ (!que.empty()) {\n      auto [dv, v] = POP(que);\n      if (dv != dp[v]) continue;\n\
    \      for (auto&& e: G[v]) {\n        if (chmin(dp[e.to], dv + e.cost + v_wt[e.to]))\
    \ {\n          par[s][e.to] = 2 * e.id + 1;\n          que.emplace(dp[e.to], e.to);\n\
    \        }\n      }\n    }\n  }\n\n  // \u5FA9\u5143\u3059\u308B\n  vc<bool> used_v(N),\
    \ used_e(M);\n  vc<int> v_to_k(N, -1);\n  FOR(k, K) v_to_k[S[k]] = k;\n\n  vc<pair<int,\
    \ int>> que;\n  int root = min_element(all(DP.back())) - DP.back().begin();\n\
    \  que.eb((1 << K) - 1, root);\n  used_v[root] = 1;\n\n  while (len(que)) {\n\
    \    auto [s, v] = POP(que);\n    if (s == 0) { continue; }\n    if (par[s][v]\
    \ == -1) {\n      int k = v_to_k[v];\n      assert(k != -1 && s >> k & 1);\n \
    \     que.eb(s ^ 1 << k, v);\n      continue;\n    }\n    elif (par[s][v] & 1)\
    \ {\n      int eid = par[s][v] / 2;\n      auto& e = G.edges[eid];\n      int\
    \ w = v ^ e.frm ^ e.to;\n      used_v[w] = used_e[eid] = 1;\n      que.eb(s, w);\n\
    \      continue;\n    }\n    else {\n      int t = par[s][v] / 2;\n      que.eb(t,\
    \ v), que.eb(s ^ t, v);\n    }\n  }\n  vc<int> vs, es;\n  FOR(v, N) if (used_v[v])\
    \ vs.eb(v);\n  FOR(e, M) if (used_e[e]) es.eb(e);\n  T cost = 0;\n  for (auto&&\
    \ v: vs) cost += v_wt[v];\n  for (auto&& e: es) cost += G.edges[e].cost;\n  assert(cost\
    \ == DP.back()[root]);\n  return {cost, vs, es};\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"enumerate/bits.hpp\"\n\n// \u8FBA\
    \u91CD\u307F\u306F e.cost\u3001\u9802\u70B9\u91CD\u307F\u306F vector \u3067\u6E21\
    \u3059\u3002\u8FD4\u308A\u5024\uFF1A{cost, vs, es}\n// O(3^kn + 2^k(n+m)log n),\
    \ k: terminal size\ntemplate <typename T, typename GT>\ntuple<T, vc<int>, vc<int>>\
    \ steiner_tree(GT& G, vc<int> S, vc<T> v_wt = {}) {\n  static_assert(!GT::is_directed);\n\
    \  assert(!S.empty());\n  const int N = G.N, M = G.M, K = len(S);\n  if (v_wt.empty())\
    \ v_wt.assign(N, 0);\n\n  // \u30BF\u30FC\u30DF\u30CA\u30EB\u96C6\u5408, root\
    \ -> cost\n  vv(T, DP, 1 << K, N, infty<T>);\n  FOR(v, N) DP[0][v] = v_wt[v];\n\
    \n  // 2 * t or 2 * eid + 1\n  vv(int, par, 1 << K, N, -1);\n\n  for (int s =\
    \ 1; s < (1 << K); ++s) {\n    auto& dp = DP[s];\n    for (int k: all_bit<u32>(s))\
    \ {\n      int v = S[k];\n      chmin(dp[v], DP[s ^ 1 << k][v]);\n    }\n    for\
    \ (u32 t: all_subset<u32>(s)) {\n      if (t == 0 || t == s) continue;\n     \
    \ FOR(v, N) {\n        if (chmin(dp[v], DP[t][v] + DP[s ^ t][v] - v_wt[v])) par[s][v]\
    \ = 2 * t;\n      }\n    }\n    // \u6839\u306E\u79FB\u52D5\u3092 dijkstra \u3067\
    \n    pqg<pair<T, int>> que;\n    FOR(v, N) que.emplace(dp[v], v);\n    while\
    \ (!que.empty()) {\n      auto [dv, v] = POP(que);\n      if (dv != dp[v]) continue;\n\
    \      for (auto&& e: G[v]) {\n        if (chmin(dp[e.to], dv + e.cost + v_wt[e.to]))\
    \ {\n          par[s][e.to] = 2 * e.id + 1;\n          que.emplace(dp[e.to], e.to);\n\
    \        }\n      }\n    }\n  }\n\n  // \u5FA9\u5143\u3059\u308B\n  vc<bool> used_v(N),\
    \ used_e(M);\n  vc<int> v_to_k(N, -1);\n  FOR(k, K) v_to_k[S[k]] = k;\n\n  vc<pair<int,\
    \ int>> que;\n  int root = min_element(all(DP.back())) - DP.back().begin();\n\
    \  que.eb((1 << K) - 1, root);\n  used_v[root] = 1;\n\n  while (len(que)) {\n\
    \    auto [s, v] = POP(que);\n    if (s == 0) { continue; }\n    if (par[s][v]\
    \ == -1) {\n      int k = v_to_k[v];\n      assert(k != -1 && s >> k & 1);\n \
    \     que.eb(s ^ 1 << k, v);\n      continue;\n    }\n    elif (par[s][v] & 1)\
    \ {\n      int eid = par[s][v] / 2;\n      auto& e = G.edges[eid];\n      int\
    \ w = v ^ e.frm ^ e.to;\n      used_v[w] = used_e[eid] = 1;\n      que.eb(s, w);\n\
    \      continue;\n    }\n    else {\n      int t = par[s][v] / 2;\n      que.eb(t,\
    \ v), que.eb(s ^ t, v);\n    }\n  }\n  vc<int> vs, es;\n  FOR(v, N) if (used_v[v])\
    \ vs.eb(v);\n  FOR(e, M) if (used_e[e]) es.eb(e);\n  T cost = 0;\n  for (auto&&\
    \ v: vs) cost += v_wt[v];\n  for (auto&& e: es) cost += G.edges[e].cost;\n  assert(cost\
    \ == DP.back()[root]);\n  return {cost, vs, es};\n}\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - enumerate/bits.hpp
  isVerificationFile: false
  path: graph/steiner_tree.hpp
  requiredBy: []
  timestamp: '2025-04-06 22:14:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/114.test.cpp
documentation_of: graph/steiner_tree.hpp
layout: document
redirect_from:
- /library/graph/steiner_tree.hpp
- /library/graph/steiner_tree.hpp.html
title: graph/steiner_tree.hpp
---
