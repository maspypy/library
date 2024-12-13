---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/ds/remove_one_vertex_connectivity.hpp
    title: graph/ds/remove_one_vertex_connectivity.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_graph.hpp
    title: random/random_graph.hpp
  - icon: ':question:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/remove_one_vertex.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n// https://trap.jp/post/1224/\n#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n\
    #define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll\
    \ i = a; i < ll(b); ++i)\n#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i\
    \ += (c))\n#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i,\
    \ a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i =\
    \ (b)-1; i >= ll(a); --i)\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a,\
    \ b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
    \ &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate\
    \ <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok = true)\
    \ {\n  if (check_ok) assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate\
    \ <typename F>\ndouble binary_search_real(F check, double ok, double ng, int iter\
    \ = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok :\
    \ ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline\
    \ bool chmax(T &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate\
    \ <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ?\
    \ a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char)\
    \ {\n  vc<int> A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] -\
    \ first_char : -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T>\
    \ cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N +\
    \ 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n\
    \  return B;\n}\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const\
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\
    \ [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return\
    \ ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/remove_one_vertex.test.cpp\"\
    \n\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
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
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
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
    }\n#line 6 \"test/1_mytest/remove_one_vertex.test.cpp\"\n\n#line 2 \"graph/ds/remove_one_vertex_connectivity.hpp\"\
    \n\n// 1 \u70B9\u6D88\u3057\u305F\u3068\u304D\u306B\n// u,v \u304C\u9023\u7D50\
    \u304B / \u9023\u7D50\u6210\u5206\u6570 / v \u306E\u9023\u7D50\u6210\u5206\u30B5\
    \u30A4\u30BA\nstruct Remove_One_Vertex_Connectivity {\n  int N, M, n_comp_base;\n\
    \  vc<int> root;\n  vc<int> LID, RID;\n  vc<int> low;\n  vvc<int> ch;\n  vc<int>\
    \ rm_sz, rm_comp;\n\n  template <typename GT>\n  Remove_One_Vertex_Connectivity(GT&\
    \ G) {\n    build(G);\n  }\n\n  template <typename GT>\n  void build(GT& G) {\n\
    \    N = G.N, M = G.M;\n    root.assign(N, -1);\n    LID.assign(N, -1), RID.assign(N,\
    \ -1), low.assign(N, -1);\n    ch.resize(N);\n    int p = 0;\n    n_comp_base\
    \ = 0;\n    auto dfs = [&](auto& dfs, int v, int last_e) -> void {\n      low[v]\
    \ = LID[v] = p++;\n      for (auto&& e: G[v]) {\n        if (e.id == last_e) continue;\n\
    \        if (root[e.to] == -1) {\n          root[e.to] = root[v];\n          ch[v].eb(e.to);\n\
    \          dfs(dfs, e.to, e.id);\n          chmin(low[v], low[e.to]);\n      \
    \  } else {\n          chmin(low[v], LID[e.to]);\n        }\n      }\n      RID[v]\
    \ = p;\n    };\n    FOR(v, N) {\n      if (root[v] == -1) { n_comp_base++, root[v]\
    \ = v, dfs(dfs, v, -1); }\n    }\n    rm_sz.assign(N, 0);\n    rm_comp.assign(N,\
    \ n_comp_base);\n    FOR(v, N) {\n      if (root[v] == v) {\n        rm_comp[v]\
    \ += len(ch[v]) - 1;\n      } else {\n        rm_sz[v] = subtree_size(root[v])\
    \ - 1;\n        for (auto& c: ch[v]) {\n          if (low[c] >= LID[v]) { rm_sz[v]\
    \ -= subtree_size(c), rm_comp[v]++; }\n        }\n      }\n    }\n  }\n\n  int\
    \ n_comp(int rm) { return rm_comp[rm]; }\n\n  bool is_connected(int rm, int u,\
    \ int v) {\n    assert(u != rm && v != rm);\n    if (root[u] != root[v]) return\
    \ false;\n    if (root[u] != root[rm]) return true;\n    bool in_u = in_subtree(u,\
    \ rm), in_v = in_subtree(v, rm);\n    if (in_u) { u = jump(rm, u), in_u = low[u]\
    \ >= LID[rm]; }\n    if (in_v) { v = jump(rm, v), in_v = low[v] >= LID[rm]; }\n\
    \    if (in_u != in_v) return false;\n    return (in_u ? u == v : true);\n  }\n\
    \n  int size(int rm, int v) {\n    assert(rm != v);\n    if (root[v] != root[rm])\
    \ return subtree_size(root[v]);\n    if (rm == root[v]) { return subtree_size(jump(rm,\
    \ v)); }\n    if (!in_subtree(v, rm)) { return rm_sz[rm]; }\n    v = jump(rm,\
    \ v);\n    return (LID[rm] <= low[v] ? subtree_size(v) : rm_sz[rm]);\n  }\n\n\
    private:\n  bool in_subtree(int a, int b) { return LID[b] <= LID[a] && LID[a]\
    \ < RID[b]; }\n  int subtree_size(int v) { return RID[v] - LID[v]; }\n  int jump(int\
    \ r, int v) {\n    assert(r != v && in_subtree(v, r));\n    int n = len(ch[r]);\n\
    \    int k = binary_search(\n        [&](int k) -> bool {\n          int c = ch[r][k];\n\
    \          return LID[c] <= LID[v];\n        },\n        0, n);\n    return ch[r][k];\n\
    \  }\n};\n#line 8 \"test/1_mytest/remove_one_vertex.test.cpp\"\n\nvoid test()\
    \ {\n  FOR(N, 20) {\n    FOR(1000) {\n      Graph<int, 0> G(N);\n      for (auto&\
    \ [a, b]: random_graph<false>(N, false)) G.add(a, b);\n      G.build();\n    \
    \  Remove_One_Vertex_Connectivity X(G);\n      FOR(rm, N) {\n        UnionFind\
    \ uf(N);\n        for (auto& e: G.edges) {\n          if (e.frm == rm || e.to\
    \ == rm) continue;\n          uf.merge(e.frm, e.to);\n        }\n        assert(X.n_comp(rm)\
    \ == uf.n_comp - 1);\n        FOR(u, N) FOR(v, N) {\n          if (u == rm ||\
    \ v == rm) continue;\n          assert(X.is_connected(rm, u, v) == (uf[u] == uf[v]));\n\
    \        }\n        FOR(v, N) if (v != rm) assert(X.size(rm, v) == uf.size(v));\n\
    \      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/random_graph.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\
    \n\n#include \"graph/ds/remove_one_vertex_connectivity.hpp\"\n\nvoid test() {\n\
    \  FOR(N, 20) {\n    FOR(1000) {\n      Graph<int, 0> G(N);\n      for (auto&\
    \ [a, b]: random_graph<false>(N, false)) G.add(a, b);\n      G.build();\n    \
    \  Remove_One_Vertex_Connectivity X(G);\n      FOR(rm, N) {\n        UnionFind\
    \ uf(N);\n        for (auto& e: G.edges) {\n          if (e.frm == rm || e.to\
    \ == rm) continue;\n          uf.merge(e.frm, e.to);\n        }\n        assert(X.n_comp(rm)\
    \ == uf.n_comp - 1);\n        FOR(u, N) FOR(v, N) {\n          if (u == rm ||\
    \ v == rm) continue;\n          assert(X.is_connected(rm, u, v) == (uf[u] == uf[v]));\n\
    \        }\n        FOR(v, N) if (v != rm) assert(X.size(rm, v) == uf.size(v));\n\
    \      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/random_graph.hpp
  - graph/base.hpp
  - random/base.hpp
  - random/shuffle.hpp
  - ds/unionfind/unionfind.hpp
  - graph/ds/remove_one_vertex_connectivity.hpp
  isVerificationFile: true
  path: test/1_mytest/remove_one_vertex.test.cpp
  requiredBy: []
  timestamp: '2024-12-13 13:55:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/remove_one_vertex.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/remove_one_vertex.test.cpp
- /verify/test/1_mytest/remove_one_vertex.test.cpp.html
title: test/1_mytest/remove_one_vertex.test.cpp
---
