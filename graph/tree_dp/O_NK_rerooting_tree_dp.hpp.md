---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':warning:'
    path: ds/offset_vector.hpp
    title: ds/offset_vector.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/2229/problem/I
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
    \ OutgoingEdges {\n   public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) {\n        return 0;\n\
    \      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const Graph*\
    \ G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph()\
    \ : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n\
    \  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
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
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e : edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    for (int v = 0; v < N; ++v) {\n      indptr[v + 1] += indptr[v];\n \
    \   }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n\
    \    for (auto&& e : edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if\
    \ (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost,\
    \ e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n    print(\"Graph\");\n    if\
    \ (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e : edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e : (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n    flush();\n#endif\n  }\n#endif\n\
    \n  vc<int> new_idx;\n  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\
    \u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\
    \u308B\u3088\u3046\u306B\u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\
    \u7B97\u91CF\u306B\u306A\u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u306E n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\
    \u3042\u308B\u306E\u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(vc<int> V,\
    \ bool keep_eid = 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n  \
    \  int n = len(V);\n    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n\
    \    vc<int> history;\n    FOR(i, n) {\n      for (auto&& e : (*this)[V[i]]) {\n\
    \        if (len(used_e) <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id])\
    \ continue;\n        int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 &&\
    \ new_idx[b] != -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n\
    \          int eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b],\
    \ e.cost, eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n\
    \    for (auto&& eid : history) used_e[eid] = 0;\n    G.build();\n    return G;\n\
    \  }\n\n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1)\
    \ root = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T,\
    \ true> G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v)\
    \ -> void {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  HashMap<int> MP_FOR_EID;\n\n\
    \  int get_eid(u64 a, u64 b) {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N\
    \ - 1);\n      for (auto& e : edges) {\n        u64 a = e.frm, b = e.to;\n   \
    \     u64 k = to_eid_key(a, b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n\
    \    return MP_FOR_EID.get(to_eid_key(a, b), -1);\n  }\n\n  u64 to_eid_key(u64\
    \ a, u64 b) {\n    if (!directed && a > b) swap(a, b);\n    return N * a + b;\n\
    \  }\n\n private:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e : edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e : edges) {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n \
    \   }\n  }\n};\n#line 1 \"ds/offset_vector.hpp\"\n// V[L],...,V[R-1] \u3092\u5927\
    \u304D\u3055 R-L \u306E vector \u3067\u7BA1\u7406\u3059\u308B\ntemplate <typename\
    \ T>\nstruct OffsetVector {\n  int off;\n  vc<T> dat;\n  OffsetVector(int L =\
    \ 0, int R = 0, T t = {}) : off(L), dat(R - L, t) {}\n  T& operator[](int i) {\
    \ return dat[i - off]; }\n  const T& operator[](int i) const { return dat[i -\
    \ off]; }\n  int size() const { return dat.size(); }\n  int L() const { return\
    \ off; }\n  int R() const { return off + (dat.size()); }\n};\n#line 3 \"graph/tree_dp/O_NK_rerooting_tree_dp.hpp\"\
    \n\n// 2\u4E57\u306E\u6728DP\u578B\u306EO(NK)\u5168\u65B9\u4F4D.\n// \u5404\u9802\
    \u70B9 v \u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u30B5\u30A4\u30BA K\
    \ \u306E DP \u5024\u3060\u3051\u304C\u6700\u7D42\u7684\u306B\u5FC5\u8981\u3067\
    \u3042\u308B\u5834\u5408\n// https://codeforces.com/contest/2229/problem/I\n//\n\
    // f_ee(A, B, L, R)\n// f_ev(A, v, L, R)\n// f_ve(A, v, p, L, R)\n// get_ANS(A,\
    \ v)\n// A, B \u3084\u8FD4\u308A\u5024\u306F Offset_Vector<T> \u3067\u3001\u8FD4\
    \u308A\u5024\u306F [L,R) \u306B\u306A\u308B\u7D44\u3092\u5168\u8A08\u7B97\n//\n\
    // f_ee: virtual tree \u306E\u30DE\u30FC\u30B8\n// f_ev: virtual tree \u306B\u6839\
    \u3092\u3064\u3051\u3066 real tree \u306B\u3059\u308B\n// f_ve: real tree \u306B\
    \u89AA\u8FBA\u3092\u3064\u3051\u3066 virtual tree \u306B\u3059\u308B\n// get_ANS:\
    \ virtual tree, v \u304B\u3089\u7B54\u3092\u5F97\u308B. [K-1,K]\ntemplate <typename\
    \ GT, typename T, typename F1, typename F2, typename F3,\n          typename F4>\n\
    vc<T> O_NK_rerooting_tree_dp(GT& G, int K, F1 f_ee, F2 f_ev, F3 f_ve,\n      \
    \                       F4 get_ANS, const T unit) {\n  int N = G.N;\n  vc<int>\
    \ V(N), par(N, -1), sz(N, 1);\n  vvc<int> ch(N);\n  {\n    int t = 0;\n    V[t++]\
    \ = 0;\n    FOR(i, N) {\n      int v = V[i];\n      for (auto& e : G[v]) {\n \
    \       if (e.to == par[v]) continue;\n        V[t++] = e.to;\n        par[e.to]\
    \ = v;\n        ch[v].eb(e.to);\n      }\n    }\n    FOR_R(i, 1, N) {\n      int\
    \ v = V[i];\n      sz[par[v]] += sz[v];\n    }\n  }\n\n  /*\n  dp_down[v]: virtual\
    \ tree at v.\n  dp_prefix[c]: prefix virtual tree at v, before c. (c: not included)\n\
    \  dp_up[v]: virtual tree at v, upward.\n  */\n\n  using D = OffsetVector<T>;\n\
    \  vc<D> dp_down(N), dp_prefix(N), dp_up(N);\n  vc<T> ANS(N);\n\n  // calc dp_down,\
    \ dp_prefix\n  FOR_R(i, N) {\n    int v = V[i];\n    D X(0, 1, unit);\n    int\
    \ n = 0;\n    for (int c : ch[v]) {\n      dp_prefix[c] = X;\n      D Y = f_ev(dp_down[c],\
    \ c, 0, min<int>(K, sz[c]) + 1);\n      Y = f_ve(Y, c, v, 0, min<int>(K, sz[c])\
    \ + 1);\n      n += sz[c];\n      X = f_ee(X, Y, 0, min<int>(n, K) + 1);\n   \
    \ }\n    dp_down[v] = X;\n  }\n\n  dp_up[0] = D(0, 1, unit);\n  FOR(i, N) {\n\
    \    int v = V[i];\n    int nc = len(ch[v]);\n    D X = dp_up[v];\n    int s =\
    \ sz[v];\n    FOR_R(k, nc) {\n      int c = ch[v][k];\n      D Y = f_ee(X, dp_prefix[c],\
    \ max(K - sz[c] - 1, 0), K + 1);\n      Y = f_ev(Y, v, max(K - sz[c], 0), K +\
    \ 1);\n      dp_up[c] = f_ve(Y, v, c, max(K - sz[c], 0), K + 1);\n      s -= sz[c];\n\
    \      Y = f_ev(dp_down[c], c, 0, min(K, sz[c]) + 1);\n      Y = f_ve(Y, c, v,\
    \ 0, min(K, sz[c]) + 1);\n      X = f_ee(X, Y, max(K - s, 0), K + 1);\n    }\n\
    \    ANS[v] = get_ANS(X, v);\n  }\n  return ANS;\n}\n"
  code: "#include \"graph/base.hpp\"\n#include \"ds/offset_vector.hpp\"\n\n// 2\u4E57\
    \u306E\u6728DP\u578B\u306EO(NK)\u5168\u65B9\u4F4D.\n// \u5404\u9802\u70B9 v \u3092\
    \u6839\u3068\u3057\u305F\u3068\u304D\u306E\u30B5\u30A4\u30BA K \u306E DP \u5024\
    \u3060\u3051\u304C\u6700\u7D42\u7684\u306B\u5FC5\u8981\u3067\u3042\u308B\u5834\
    \u5408\n// https://codeforces.com/contest/2229/problem/I\n//\n// f_ee(A, B, L,\
    \ R)\n// f_ev(A, v, L, R)\n// f_ve(A, v, p, L, R)\n// get_ANS(A, v)\n// A, B \u3084\
    \u8FD4\u308A\u5024\u306F Offset_Vector<T> \u3067\u3001\u8FD4\u308A\u5024\u306F\
    \ [L,R) \u306B\u306A\u308B\u7D44\u3092\u5168\u8A08\u7B97\n//\n// f_ee: virtual\
    \ tree \u306E\u30DE\u30FC\u30B8\n// f_ev: virtual tree \u306B\u6839\u3092\u3064\
    \u3051\u3066 real tree \u306B\u3059\u308B\n// f_ve: real tree \u306B\u89AA\u8FBA\
    \u3092\u3064\u3051\u3066 virtual tree \u306B\u3059\u308B\n// get_ANS: virtual\
    \ tree, v \u304B\u3089\u7B54\u3092\u5F97\u308B. [K-1,K]\ntemplate <typename GT,\
    \ typename T, typename F1, typename F2, typename F3,\n          typename F4>\n\
    vc<T> O_NK_rerooting_tree_dp(GT& G, int K, F1 f_ee, F2 f_ev, F3 f_ve,\n      \
    \                       F4 get_ANS, const T unit) {\n  int N = G.N;\n  vc<int>\
    \ V(N), par(N, -1), sz(N, 1);\n  vvc<int> ch(N);\n  {\n    int t = 0;\n    V[t++]\
    \ = 0;\n    FOR(i, N) {\n      int v = V[i];\n      for (auto& e : G[v]) {\n \
    \       if (e.to == par[v]) continue;\n        V[t++] = e.to;\n        par[e.to]\
    \ = v;\n        ch[v].eb(e.to);\n      }\n    }\n    FOR_R(i, 1, N) {\n      int\
    \ v = V[i];\n      sz[par[v]] += sz[v];\n    }\n  }\n\n  /*\n  dp_down[v]: virtual\
    \ tree at v.\n  dp_prefix[c]: prefix virtual tree at v, before c. (c: not included)\n\
    \  dp_up[v]: virtual tree at v, upward.\n  */\n\n  using D = OffsetVector<T>;\n\
    \  vc<D> dp_down(N), dp_prefix(N), dp_up(N);\n  vc<T> ANS(N);\n\n  // calc dp_down,\
    \ dp_prefix\n  FOR_R(i, N) {\n    int v = V[i];\n    D X(0, 1, unit);\n    int\
    \ n = 0;\n    for (int c : ch[v]) {\n      dp_prefix[c] = X;\n      D Y = f_ev(dp_down[c],\
    \ c, 0, min<int>(K, sz[c]) + 1);\n      Y = f_ve(Y, c, v, 0, min<int>(K, sz[c])\
    \ + 1);\n      n += sz[c];\n      X = f_ee(X, Y, 0, min<int>(n, K) + 1);\n   \
    \ }\n    dp_down[v] = X;\n  }\n\n  dp_up[0] = D(0, 1, unit);\n  FOR(i, N) {\n\
    \    int v = V[i];\n    int nc = len(ch[v]);\n    D X = dp_up[v];\n    int s =\
    \ sz[v];\n    FOR_R(k, nc) {\n      int c = ch[v][k];\n      D Y = f_ee(X, dp_prefix[c],\
    \ max(K - sz[c] - 1, 0), K + 1);\n      Y = f_ev(Y, v, max(K - sz[c], 0), K +\
    \ 1);\n      dp_up[c] = f_ve(Y, v, c, max(K - sz[c], 0), K + 1);\n      s -= sz[c];\n\
    \      Y = f_ev(dp_down[c], c, 0, min(K, sz[c]) + 1);\n      Y = f_ve(Y, c, v,\
    \ 0, min(K, sz[c]) + 1);\n      X = f_ee(X, Y, max(K - s, 0), K + 1);\n    }\n\
    \    ANS[v] = get_ANS(X, v);\n  }\n  return ANS;\n}\n"
  dependsOn:
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/offset_vector.hpp
  isVerificationFile: false
  path: graph/tree_dp/O_NK_rerooting_tree_dp.hpp
  requiredBy: []
  timestamp: '2026-07-18 00:22:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/tree_dp/O_NK_rerooting_tree_dp.hpp
layout: document
redirect_from:
- /library/graph/tree_dp/O_NK_rerooting_tree_dp.hpp
- /library/graph/tree_dp/O_NK_rerooting_tree_dp.hpp.html
title: graph/tree_dp/O_NK_rerooting_tree_dp.hpp
---
