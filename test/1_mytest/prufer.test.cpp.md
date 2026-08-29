---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  - icon: ':heavy_check_mark:'
    path: enumerate/product.hpp
    title: enumerate/product.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/prufer_code.hpp
    title: graph/prufer_code.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/prufer.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n// \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6210\u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\
    \n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include\
    \ <cassert>\n\nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\n\
    using u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128\
    \ = __int128;\nusing u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate\
    \ <class>\nconstexpr bool dependent_false = false;\n\ntemplate <class T>\nconstexpr\
    \ T infty = [] {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\"\
    );\n  return T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<i128>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<i128>;\n\nusing pi = pair<ll, ll>;\n\
    using vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ pq_max = priority_queue<T>;\ntemplate <class T>\nusing pq_min = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)\n\
    #define overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n\
    #define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\n// require y > 0\n\
    template <typename T>\nT floor(T x, T y) {\n  return x / y - (x % y < 0);\n}\n\
    \n// require y > 0\ntemplate <typename T>\nT ceil(T x, T y) {\n  return (x / y)\
    \ + (x % y > 0);\n}\n\n// require y > 0\ntemplate <typename T>\nT bmod(T x, T\
    \ y) {\n  T r = x % y;\n  return (r < 0 ? r + y : r);\n}\n\n// require y > 0\n\
    template <typename T>\npair<T, T> divmod(T x, T y) {\n  T q = x / y, r = x % y;\n\
    \  if (r < 0) --q, r += y;\n  return {q, r};\n}\n\nconstexpr auto TEN = [] {\n\
    \  array<u64, 20> A{};\n  A[0] = 1;\n  for (int i = 1; i < 20; ++i) A[i] = 10\
    \ * A[i - 1];\n  return A;\n}();\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\ni128 binary_search(F check, i128 ok,\
    \ i128 ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while\
    \ (1) {\n    i128 x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n   \
    \ (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble\
    \ binary_search_real(F check, double ok, double ng, int iter = 100) {\n  FOR(iter)\
    \ {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const\
    \ S &b) {\n  T c = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return\
    \ changed;\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  T c = min<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const\
    \ vc<U> &A, int off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n\
    \  vc<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n      [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  first.reserve(first.size() + (others.size()\
    \ + ... + 0));\n  (first.insert(first.end(), others.begin(), others.end()), ...);\n\
    }\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr\
    \ i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128\
    \ b) {\n  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return\
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/prufer.test.cpp\"\n\n#line 1 \"\
    ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n\
    \  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n\
    \  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n \
    \   while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\
    \u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\
    \u3068.\n  void clear() {\n    used.assign(len(used), 0);\n    cap = (mask + 1)\
    \ / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\n  int index(const\
    \ u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] && key[i] != k; i =\
    \ (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const u64& k) {\n\
    \    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\n  Val\
    \ get(const u64& k, Val default_value) {\n    int i = index(k);\n    return (used[i]\
    \ ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n    int i =\
    \ index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key, val)\n  template\
    \ <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used)) if (used[i])\
    \ f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64> key;\n  vc<Val>\
    \ val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n    x += FIXED_RANDOM;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return (x ^ (x >> 31)) & mask;\n  }\n\n  void extend() {\n    vc<pair<u64,\
    \ Val>> dat;\n    dat.reserve(len(used) / 2 - cap);\n    FOR(i, len(used)) {\n\
    \      if (used[i]) dat.eb(key[i], val[i]);\n    }\n    build(2 * len(dat));\n\
    \    for (auto& [a, b]: dat) (*this)[a] = b;\n  }\n};\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  HashMap<int>\
    \ MP_FOR_EID;\n  bool prepared;\n\n  class OutgoingEdges {\n   public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n\
    \    }\n\n    const edge_type* end() const {\n      if (l == r) {\n        return\
    \ 0;\n      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const\
    \ Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\
    \n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
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
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n\
    \    print(\"Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n\
    \      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n\
    \      print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n    }\n  \
    \  flush();\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\n\
    \  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
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
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) {\n\
    \    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for (auto&\
    \ e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) {\n    if (!directed && a >\
    \ b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e : edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e : edges)\
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 1 \"ds/unionfind/unionfind.hpp\"\
    \n\nstruct UnionFind {\n  int n, n_comp;\n  vc<int> dat; // par or (-size)\n \
    \ UnionFind(int n = 0) { build(n); }\n\n  void build(int m) {\n    n = m, n_comp\
    \ = m;\n    dat.assign(n, -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int\
    \ x) {\n    while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp <\
    \ 0) { return dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n\
    \  ll size(int x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int\
    \ x, int y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n\
    \    if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
    \    return true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i,\
    \ n) A[i] = (*this)[i];\n    return A;\n  }\n};\n#line 1 \"enumerate/product.hpp\"\
    \n\n// [0, A0) x [0, A1) x ...\ntemplate <typename F>\nvoid enumerate_product(vc<int>\
    \ A, F query) {\n  int N = len(A);\n  auto dfs = [&](auto& dfs, vc<int>& p) ->\
    \ void {\n    int n = len(p);\n    if (n == N) return query(p);\n    FOR(x, A[n])\
    \ {\n      p.eb(x);\n      dfs(dfs, p);\n      p.pop_back();\n    }\n  };\n  vc<int>\
    \ p;\n  dfs(dfs, p);\n}\n#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate\
    \ <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\
    \u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void\
    \ build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k /\
    \ 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\
    \n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\
    \u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used),\
    \ 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() { return len(used) / 2 - cap;\
    \ }\n\n  int index(const u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const\
    \ u64& k) {\n    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i])\
    \ { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64>\
    \ key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const\
    \ u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
    \    x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x\
    \ = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b]: dat) (*this)[a] = b;\n\
    \  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg,\
    \ vc_indeg, vc_outdeg;\n  HashMap<int> MP_FOR_EID;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n   public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) {\n        return 0;\n\
    \      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const Graph*\
    \ G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph()\
    \ : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n\
    \  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
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
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n\
    \    print(\"Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n\
    \      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n\
    \      print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n    }\n  \
    \  flush();\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\n\
    \  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
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
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) {\n\
    \    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for (auto&\
    \ e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) {\n    if (!directed && a >\
    \ b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e : edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e : edges)\
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 2 \"graph/prufer_code.hpp\"\
    \n\n// [0,n-1]^{n-1}, \u305F\u3060\u3057\u672B\u5C3E\u306F n-1, \u3068\u3044\u3046\
    \u5B9A\u5F0F\u5316 (n=1 ok)\nvc<int> to_prufer_code(Graph<int, 0>& G) {\n  //\
    \ \u30E9\u30D9\u30EB\u6700\u5C0F\u306E\u8449\u3092\u3068\u308B -> \u89AA\u3092\
    \u5217\u306B\u8FFD\u52A0\n  int n = G.N;\n  vc<int> par(n);\n  {\n    auto dfs\
    \ = [&](auto& dfs, int v, int p) -> void {\n      par[v] = p;\n      for (auto&\
    \ e: G[v])\n        if (e.to != p) dfs(dfs, e.to, v);\n    };\n    dfs(dfs, n\
    \ - 1, -1);\n  }\n  vc<int> deg = G.deg_array();\n  vc<int> res(n - 1);\n  int\
    \ p = 0;\n  int leaf = -1;\n  FOR(i, n - 1) {\n    if (leaf == -1) {\n      while\
    \ (deg[p] != 1) ++p;\n      leaf = p;\n    }\n    res[i] = par[leaf];\n    deg[leaf]--,\
    \ deg[par[leaf]]--;\n    leaf = (deg[par[leaf]] == 1 && par[leaf] < p ? par[leaf]\
    \ : -1);\n  }\n  return res;\n}\n\nGraph<int, 0> from_prufer_code(vc<int> code)\
    \ {\n  int n = len(code) + 1;\n  Graph<int, 0> G(n);\n  if (n == 1) return G;\n\
    \  assert(code.back() == n - 1);\n  vc<int> deg(n, 1);\n  for (auto& v: code)\
    \ deg[v]++;\n\n  int p = 0;\n  int leaf = -1;\n  FOR(i, n - 1) {\n    if (leaf\
    \ == -1) {\n      while (deg[p] != 1) p++;\n      leaf = p;\n    }\n    G.add(code[i],\
    \ leaf);\n    deg[leaf]--, deg[code[i]]--;\n    leaf = (code[i] < p && deg[code[i]]\
    \ == 1 ? code[i] : -1);\n  }\n  G.build();\n  return G;\n}\n#line 8 \"test/1_mytest/prufer.test.cpp\"\
    \n\nvoid test(int n) {\n  /*\n  F: \u5217 -> \u6728\n  G: \u6728 -> \u5217\n \
    \ \u30FB\u5199\u50CF\u306B\u306A\u3063\u3066\u3044\u308B\u3053\u3068\n  \u30FB\
    GF(A)=A\n  \u3053\u308C\u304C\u793A\u3055\u308C\u308C\u3070\u3001\u500B\u6570\u304C\
    \u7B49\u3057\u3044\u3053\u3068\u306F\u77E5\u3063\u3066\u3044\u308B\u306E\u3067\
    \u5168\u5358\u5C04\u304C\u3044\u3048\u308B\n  */\n  enumerate_product(vc<int>(n\
    \ - 1, n), [&](vc<int> A) -> void {\n    if (n >= 2 && A.back() != n - 1) return;\n\
    \    Graph<int, 0> G = from_prufer_code(A);\n    UnionFind uf(n);\n    for (auto&\
    \ e: G.edges) assert(uf.merge(e.frm, e.to));\n    assert(uf.n_comp == 1);\n  \
    \  vc<int> B = to_prufer_code(G);\n    assert(A == B);\n  });\n}\n\nvoid solve()\
    \ {\n  int x, y;\n  cin >> x >> y;\n  cout << x + y << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(n, 2, 8) test(n);\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"graph/base.hpp\"\n#include \"ds/unionfind/unionfind.hpp\"\n#include\
    \ \"enumerate/product.hpp\"\n#include \"graph/prufer_code.hpp\"\n\nvoid test(int\
    \ n) {\n  /*\n  F: \u5217 -> \u6728\n  G: \u6728 -> \u5217\n  \u30FB\u5199\u50CF\
    \u306B\u306A\u3063\u3066\u3044\u308B\u3053\u3068\n  \u30FBGF(A)=A\n  \u3053\u308C\
    \u304C\u793A\u3055\u308C\u308C\u3070\u3001\u500B\u6570\u304C\u7B49\u3057\u3044\
    \u3053\u3068\u306F\u77E5\u3063\u3066\u3044\u308B\u306E\u3067\u5168\u5358\u5C04\
    \u304C\u3044\u3048\u308B\n  */\n  enumerate_product(vc<int>(n - 1, n), [&](vc<int>\
    \ A) -> void {\n    if (n >= 2 && A.back() != n - 1) return;\n    Graph<int, 0>\
    \ G = from_prufer_code(A);\n    UnionFind uf(n);\n    for (auto& e: G.edges) assert(uf.merge(e.frm,\
    \ e.to));\n    assert(uf.n_comp == 1);\n    vc<int> B = to_prufer_code(G);\n \
    \   assert(A == B);\n  });\n}\n\nvoid solve() {\n  int x, y;\n  cin >> x >> y;\n\
    \  cout << x + y << \"\\n\";\n}\n\nsigned main() {\n  FOR(n, 2, 8) test(n);\n\
    \  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/unionfind/unionfind.hpp
  - enumerate/product.hpp
  - graph/prufer_code.hpp
  isVerificationFile: true
  path: test/1_mytest/prufer.test.cpp
  requiredBy: []
  timestamp: '2026-08-29 09:00:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/prufer.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/prufer.test.cpp
- /verify/test/1_mytest/prufer.test.cpp.html
title: test/1_mytest/prufer.test.cpp
---
