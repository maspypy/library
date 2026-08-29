---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':question:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':question:'
    path: alg/monoid/monoid_reverse.hpp
    title: alg/monoid/monoid_reverse.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/offline_query/mo.hpp
    title: ds/offline_query/mo.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/mo_on_tree.hpp
    title: graph/ds/mo_on_tree.hpp
  - icon: ':question:'
    path: graph/ds/tree_monoid.hpp
    title: graph/ds/tree_monoid.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
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
  bundledCode: "#line 1 \"test/1_mytest/mo_on_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n\
    #include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u74B0\u5883\u306B\u3088\u3063\
    \u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\u529F\u304B\u3064\u5B9F\u884C\
    \u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include\
    \ <bits/stdc++.h>\n#include <cassert>\n\nusing namespace std;\n\nusing ll = long\
    \ long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing\
    \ u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing\
    \ f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false = false;\n\
    \ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<i128>;\ntemplate <>\nconstexpr long double infty<long double> = infty<i128>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing pq_max = priority_queue<T>;\ntemplate <class T>\nusing\
    \ pq_min = priority_queue<T, vector<T>, greater<T>>;\n\n#define vv(type, name,\
    \ h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name( \\\n \
    \     h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \ abs(a);\n}\n#endif\n#line 3 \"test/1_mytest/mo_on_tree.test.cpp\"\n\n#line 1\
    \ \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"graph/tree.hpp\"\n\n#line 1 \"ds/hashmap.hpp\"\
    \n\n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0)\
    \ { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2)\
    \ k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\n    return\
    \ i;\n  }\n\n  Val& operator[](const u64& k) {\n    if (cap == 0) extend();\n\
    \    int i = index(k);\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] =\
    \ Val{}, --cap; }\n    return val[i];\n  }\n\n  Val get(const u64& k, Val default_value)\
    \ {\n    int i = index(k);\n    return (used[i] ? val[i] : default_value);\n \
    \ }\n\n  bool count(const u64& k) {\n    int i = index(k);\n    return used[i]\
    \ && key[i] == k;\n  }\n\n  // f(key, val)\n  template <typename F>\n  void enumerate_all(F\
    \ f) {\n    FOR(i, len(used)) if (used[i]) f(key[i], val[i]);\n  }\n\nprivate:\n\
    \  u32 cap, mask;\n  vc<u64> key;\n  vc<Val> val;\n  vc<bool> used;\n\n  u64 hash(u64\
    \ x) {\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\n\
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
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\n// HLD=false:\
    \ \u5165\u529B\u8FBA\u9806\u3067 preorder\ntemplate <typename GT, bool HLD = true>\n\
    struct Tree {\n  using Graph_type = GT;\n  GT &G;\n  using WT = typename GT::cost_type;\n\
    \  int N;\n  vector<int> LID, RID, head, V, parent, VtoE;\n  vc<int> depth;\n\
    \  vc<WT> depth_weighted;\n  vc<int> memo_tail;\n\n  Tree(GT &G, int r = 0) :\
    \ G(G) { build(r); }\n\n  void build(int r = 0) {\n    if (r == -1) return;  //\
    \ build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\n    if constexpr (!HLD)\n\
    \      build_simple(r);\n    else\n      build_HLD(r);\n  }\n\n  vc<int> heavy_path_at(int\
    \ v) const {\n    static_assert(HLD);\n    assert(head[v] == v);\n    int k =\
    \ LID[v];\n    vc<int> P;\n    while (k < N && head[V[k]] == v) P.eb(V[k++]);\n\
    \    return P;\n  }\n\n  int heavy_child(int v) const {\n    static_assert(HLD);\n\
    \    if (RID[v] == LID[v] + 1) return -1;\n    return V[LID[v] + 1];\n  }\n\n\
    \  int tail(int v) {\n    static_assert(HLD);\n    if (memo_tail.empty()) {\n\
    \      memo_tail.assign(N, -1);\n      FOR_R(i, N) {\n        int v = V[i];\n\
    \        int w = heavy_child(v);\n        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\n\
    \      }\n    }\n    return memo_tail[v];\n  }\n\n  int e_to_v(int eid) const\
    \ {\n    auto e = G.edges[eid];\n    return (parent[e.frm] == e.to ? e.frm : e.to);\n\
    \  }\n  int v_to_e(int v) const { return VtoE[v]; }\n  int get_eid(int u, int\
    \ v) const {\n    if (parent[u] != v) swap(u, v);\n    assert(parent[u] == v);\n\
    \    return VtoE[u];\n  }\n\n  int ELID(int v) const { return 2 * LID[v] - depth[v];\
    \ }\n  int ERID(int v) const { return 2 * RID[v] - depth[v] - 1; }\n\n  // \u76EE\
    \u6A19\u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\n  int LA(int v, int\
    \ k) const {\n    static_assert(HLD);\n    assert(k <= depth[v]);\n    while (1)\
    \ {\n      int u = head[v];\n      if (LID[v] - k >= LID[u]) return V[LID[v] -\
    \ k];\n      k -= LID[v] - LID[u] + 1;\n      v = parent[u];\n    }\n  }\n\n \
    \ int LCA(int u, int v) const {\n    static_assert(HLD);\n    for (;; v = parent[head[v]])\
    \ {\n      if (LID[u] > LID[v]) swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n    }\n  }\n\n  int meet(int a, int b, int c) const {\n    static_assert(HLD);\n\
    \    return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\n  }\n\n  int subtree_size(int\
    \ v) const { return RID[v] - LID[v]; }\n\n  int subtree_size(int v, int root)\
    \ const {\n    static_assert(HLD);\n    if (v == root) return N;\n    int x =\
    \ jump(v, root, 1);\n    if (in_subtree(v, x)) return RID[v] - LID[v];\n    return\
    \ N - RID[x] + LID[x];\n  }\n\n  int dist(int a, int b) const {\n    static_assert(HLD);\n\
    \    int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\
    \n  WT dist_weighted(int a, int b) const {\n    static_assert(HLD);\n    int c\
    \ = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\n\
    \  }\n\n  // a is in b\n  bool in_subtree(int a, int b) const {\n    return LID[b]\
    \ <= LID[a] && LID[a] < RID[b];\n  }\n\n  int jump(int a, int b, ll k) const {\n\
    \    static_assert(HLD);\n    if (k == 1) {\n      if (a == b) return -1;\n  \
    \    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n\
    \    }\n    int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc\
    \ = depth[b] - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac)\
    \ return LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) const {\n    vc<int> res;\n    for (auto &&e : G[v])\n      if (e.to != parent[v])\
    \ res.eb(e.to);\n    return res;\n  }\n\n  vc<int> collect_subtree(int v) const\
    \ {\n    return {V.begin() + LID[v], V.begin() + RID[v]};\n  }\n\n  vc<int> collect_light(int\
    \ v) const {\n    static_assert(HLD);\n    vc<int> res;\n    for (auto &&e : G[v])\
    \ {\n      if (e.to != parent[v] && head[e.to] == e.to) res.eb(e.to);\n    }\n\
    \    return res;\n  }\n\n  vc<pair<int, int>> get_path_decomposition(int u, int\
    \ v, bool edge) const {\n    static_assert(HLD);\n    // [\u59CB\u70B9, \u7D42\
    \u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n\
    \    while (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v])\
    \ {\n        down.eb(LID[head[v]], LID[v]);\n        v = parent[head[v]];\n  \
    \    } else {\n        up.eb(LID[u], LID[head[u]]);\n        u = parent[head[u]];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\n  \
    \  elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n\
    \    up.insert(up.end(), all(down));\n    return up;\n  }\n\n  // \u8FBA\u306E\
    \u5217\u306E\u60C5\u5831 (frm,to,str)\n  // str = \"heavy_up\", \"heavy_down\"\
    , \"light_up\", \"light_down\"\n  vc<tuple<int, int, string>> get_path_decomposition_detail(\n\
    \      int u, int v) const {\n    static_assert(HLD);\n    vc<tuple<int, int,\
    \ string>> up, down;\n    while (1) {\n      if (head[u] == head[v]) break;\n\
    \      if (LID[u] < LID[v]) {\n        if (v != head[v]) down.eb(head[v], v, \"\
    heavy_down\"), v = head[v];\n        down.eb(parent[v], v, \"light_down\"), v\
    \ = parent[v];\n      } else {\n        if (u != head[u]) up.eb(u, head[u], \"\
    heavy_up\"), u = head[u];\n        up.eb(u, parent[u], \"light_up\"), u = parent[u];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(u, v, \"heavy_down\");\n   \
    \ elif (LID[v] < LID[u]) up.eb(u, v, \"heavy_up\");\n    reverse(all(down));\n\
    \    concat(up, down);\n    return up;\n  }\n\n  vc<int> restore_path(int u, int\
    \ v) const {\n    vc<int> L, R;\n    while (depth[u] > depth[v]) L.eb(u), u =\
    \ parent[u];\n    while (depth[u] < depth[v]) R.eb(v), v = parent[v];\n    while\
    \ (u != v) L.eb(u), R.eb(v), u = parent[u], v = parent[v];\n    L.eb(u);\n   \
    \ while (len(R)) L.eb(POP(R));\n    return L;\n  }\n\n  // path [a,b] \u3068 [c,d]\
    \ \u306E\u4EA4\u308F\u308A. \u7A7A\u306A\u3089\u3070 {-1,-1}.\n  // https://codeforces.com/problemset/problem/500/G\n\
    \  pair<int, int> path_intersection(int a, int b, int c, int d) const {\n    static_assert(HLD);\n\
    \    int ab = LCA(a, b), ac = LCA(a, c), ad = LCA(a, d);\n    int bc = LCA(b,\
    \ c), bd = LCA(b, d), cd = LCA(c, d);\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^\
    \ bd;  // meet(a,b,c), meet(a,b,d)\n    if (x != y) return {x, y};\n    int z\
    \ = ac ^ ad ^ cd;\n    if (x != z) x = -1;\n    return {x, x};\n  }\n\n  // uv\
    \ path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E v\n  //\
    \ \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C ng \uFF09\
    -1\n  template <class F>\n  int max_path(F check, int u, int v) const {\n    static_assert(HLD);\n\
    \    if (!check(u)) return -1;\n    auto pd = get_path_decomposition(u, v, false);\n\
    \    for (auto [a, b] : pd) {\n      if (!check(V[a])) return u;\n      if (check(V[b]))\
    \ {\n        u = V[b];\n        continue;\n      }\n      int c =\n          binary_search([&](int\
    \ c) -> bool { return check(V[c]); }, a, b, 0);\n      return V[c];\n    }\n \
    \   return u;\n  }\n\n private:\n  void build_simple(int r = 0) {\n    N = G.N;\n\
    \    LID.assign(N, 0), RID.assign(N, 0);\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1);\n    depth.assign(N, 0), depth_weighted.assign(N, 0);\n\
    \    assert(G.is_prepared());\n\n    // 1st dfs.\n    int k = 0;\n    vc<int>\
    \ st;\n    st.reserve(N);\n    st.eb(r);\n    while (len(st)) {\n      int v =\
    \ POP(st);\n      LID[v] = k, V[k] = v;\n      ++k;\n      for (int i = G.indptr[v\
    \ + 1] - 1; i >= G.indptr[v]; --i) {\n        auto &e = G.csr_edges[i];\n    \
    \    if (e.to == parent[v]) continue;\n        parent[e.to] = v;\n        depth[e.to]\
    \ = depth[v] + 1;\n        depth_weighted[e.to] = depth_weighted[v] + e.cost;\n\
    \        VtoE[e.to] = e.id;\n        st.eb(e.to);\n      }\n    }\n\n    FOR_R(i,\
    \ N) {\n      int v = V[i];\n      chmax(RID[v], LID[v] + 1);\n      if (parent[v]\
    \ != -1) chmax(RID[parent[v]], RID[v]);\n    }\n  }\n\n  void build_HLD(int r\
    \ = 0) {\n    N = G.N;\n    LID.assign(N, 0), RID.assign(N, 0), head.assign(N,\
    \ r);\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\n    depth.assign(N,\
    \ 0), depth_weighted.assign(N, 0);\n    memo_tail.clear();\n    assert(G.is_prepared());\n\
    \n    // 1st dfs.\n    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n\
    \      st.eb(r);\n      while (len(st)) {\n        int v = POP(st);\n        V[k++]\
    \ = v;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          parent[e.to] = v, st.eb(e.to), depth[e.to] = depth[v] + 1;\n      \
    \    depth_weighted[e.to] = depth_weighted[v] + e.cost;\n          VtoE[e.to]\
    \ = e.id;\n        }\n      }\n      // \u4E00\u6642\u7684\u306B RID[v] := sz[v]\n\
    \      FOR_R(i, N) {\n        int v = V[i];\n        RID[v] += 1;\n        if\
    \ (parent[v] != -1) RID[parent[v]] += RID[v];\n      }\n    }\n    // 2nd dfs.\n\
    \    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n      st.eb(r);\n\
    \      while (len(st)) {\n        int v = POP(st);\n        V[k] = v, LID[v] =\
    \ k;\n        RID[v] = k + RID[v];\n        ++k;\n        int max_sz = 0, max_ch\
    \ = -1;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          if (chmax(max_sz, RID[e.to])) max_ch = e.to;\n        }\n        for\
    \ (int i = G.indptr[v + 1] - 1; i >= G.indptr[v]; --i) {\n          auto &e =\
    \ G.csr_edges[i];\n          if (e.to == parent[v] || e.to == max_ch) continue;\n\
    \          st.eb(e.to), head[e.to] = e.to;\n        }\n        if (max_ch != -1)\
    \ st.eb(max_ch), head[max_ch] = head[v];\n      }\n    }\n  }\n};\n#line 1 \"\
    graph/tree.hpp\"\n\n#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename\
    \ Val>\nstruct HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\
    \u500B\u6570\u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n)\
    \ {\n    u32 k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k\
    \ - 1;\n    key.resize(k), val.resize(k), used.assign(k, 0);\n  }\n\n  // size\
    \ \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F\
    \ build \u3059\u308B\u3053\u3068.\n  void clear() {\n    used.assign(len(used),\
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
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\n// HLD=false:\
    \ \u5165\u529B\u8FBA\u9806\u3067 preorder\ntemplate <typename GT, bool HLD = true>\n\
    struct Tree {\n  using Graph_type = GT;\n  GT &G;\n  using WT = typename GT::cost_type;\n\
    \  int N;\n  vector<int> LID, RID, head, V, parent, VtoE;\n  vc<int> depth;\n\
    \  vc<WT> depth_weighted;\n  vc<int> memo_tail;\n\n  Tree(GT &G, int r = 0) :\
    \ G(G) { build(r); }\n\n  void build(int r = 0) {\n    if (r == -1) return;  //\
    \ build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\n    if constexpr (!HLD)\n\
    \      build_simple(r);\n    else\n      build_HLD(r);\n  }\n\n  vc<int> heavy_path_at(int\
    \ v) const {\n    static_assert(HLD);\n    assert(head[v] == v);\n    int k =\
    \ LID[v];\n    vc<int> P;\n    while (k < N && head[V[k]] == v) P.eb(V[k++]);\n\
    \    return P;\n  }\n\n  int heavy_child(int v) const {\n    static_assert(HLD);\n\
    \    if (RID[v] == LID[v] + 1) return -1;\n    return V[LID[v] + 1];\n  }\n\n\
    \  int tail(int v) {\n    static_assert(HLD);\n    if (memo_tail.empty()) {\n\
    \      memo_tail.assign(N, -1);\n      FOR_R(i, N) {\n        int v = V[i];\n\
    \        int w = heavy_child(v);\n        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\n\
    \      }\n    }\n    return memo_tail[v];\n  }\n\n  int e_to_v(int eid) const\
    \ {\n    auto e = G.edges[eid];\n    return (parent[e.frm] == e.to ? e.frm : e.to);\n\
    \  }\n  int v_to_e(int v) const { return VtoE[v]; }\n  int get_eid(int u, int\
    \ v) const {\n    if (parent[u] != v) swap(u, v);\n    assert(parent[u] == v);\n\
    \    return VtoE[u];\n  }\n\n  int ELID(int v) const { return 2 * LID[v] - depth[v];\
    \ }\n  int ERID(int v) const { return 2 * RID[v] - depth[v] - 1; }\n\n  // \u76EE\
    \u6A19\u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\n  int LA(int v, int\
    \ k) const {\n    static_assert(HLD);\n    assert(k <= depth[v]);\n    while (1)\
    \ {\n      int u = head[v];\n      if (LID[v] - k >= LID[u]) return V[LID[v] -\
    \ k];\n      k -= LID[v] - LID[u] + 1;\n      v = parent[u];\n    }\n  }\n\n \
    \ int LCA(int u, int v) const {\n    static_assert(HLD);\n    for (;; v = parent[head[v]])\
    \ {\n      if (LID[u] > LID[v]) swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n    }\n  }\n\n  int meet(int a, int b, int c) const {\n    static_assert(HLD);\n\
    \    return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\n  }\n\n  int subtree_size(int\
    \ v) const { return RID[v] - LID[v]; }\n\n  int subtree_size(int v, int root)\
    \ const {\n    static_assert(HLD);\n    if (v == root) return N;\n    int x =\
    \ jump(v, root, 1);\n    if (in_subtree(v, x)) return RID[v] - LID[v];\n    return\
    \ N - RID[x] + LID[x];\n  }\n\n  int dist(int a, int b) const {\n    static_assert(HLD);\n\
    \    int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\
    \n  WT dist_weighted(int a, int b) const {\n    static_assert(HLD);\n    int c\
    \ = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\n\
    \  }\n\n  // a is in b\n  bool in_subtree(int a, int b) const {\n    return LID[b]\
    \ <= LID[a] && LID[a] < RID[b];\n  }\n\n  int jump(int a, int b, ll k) const {\n\
    \    static_assert(HLD);\n    if (k == 1) {\n      if (a == b) return -1;\n  \
    \    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n\
    \    }\n    int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc\
    \ = depth[b] - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac)\
    \ return LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) const {\n    vc<int> res;\n    for (auto &&e : G[v])\n      if (e.to != parent[v])\
    \ res.eb(e.to);\n    return res;\n  }\n\n  vc<int> collect_subtree(int v) const\
    \ {\n    return {V.begin() + LID[v], V.begin() + RID[v]};\n  }\n\n  vc<int> collect_light(int\
    \ v) const {\n    static_assert(HLD);\n    vc<int> res;\n    for (auto &&e : G[v])\
    \ {\n      if (e.to != parent[v] && head[e.to] == e.to) res.eb(e.to);\n    }\n\
    \    return res;\n  }\n\n  vc<pair<int, int>> get_path_decomposition(int u, int\
    \ v, bool edge) const {\n    static_assert(HLD);\n    // [\u59CB\u70B9, \u7D42\
    \u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n\
    \    while (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v])\
    \ {\n        down.eb(LID[head[v]], LID[v]);\n        v = parent[head[v]];\n  \
    \    } else {\n        up.eb(LID[u], LID[head[u]]);\n        u = parent[head[u]];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\n  \
    \  elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n\
    \    up.insert(up.end(), all(down));\n    return up;\n  }\n\n  // \u8FBA\u306E\
    \u5217\u306E\u60C5\u5831 (frm,to,str)\n  // str = \"heavy_up\", \"heavy_down\"\
    , \"light_up\", \"light_down\"\n  vc<tuple<int, int, string>> get_path_decomposition_detail(\n\
    \      int u, int v) const {\n    static_assert(HLD);\n    vc<tuple<int, int,\
    \ string>> up, down;\n    while (1) {\n      if (head[u] == head[v]) break;\n\
    \      if (LID[u] < LID[v]) {\n        if (v != head[v]) down.eb(head[v], v, \"\
    heavy_down\"), v = head[v];\n        down.eb(parent[v], v, \"light_down\"), v\
    \ = parent[v];\n      } else {\n        if (u != head[u]) up.eb(u, head[u], \"\
    heavy_up\"), u = head[u];\n        up.eb(u, parent[u], \"light_up\"), u = parent[u];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(u, v, \"heavy_down\");\n   \
    \ elif (LID[v] < LID[u]) up.eb(u, v, \"heavy_up\");\n    reverse(all(down));\n\
    \    concat(up, down);\n    return up;\n  }\n\n  vc<int> restore_path(int u, int\
    \ v) const {\n    vc<int> L, R;\n    while (depth[u] > depth[v]) L.eb(u), u =\
    \ parent[u];\n    while (depth[u] < depth[v]) R.eb(v), v = parent[v];\n    while\
    \ (u != v) L.eb(u), R.eb(v), u = parent[u], v = parent[v];\n    L.eb(u);\n   \
    \ while (len(R)) L.eb(POP(R));\n    return L;\n  }\n\n  // path [a,b] \u3068 [c,d]\
    \ \u306E\u4EA4\u308F\u308A. \u7A7A\u306A\u3089\u3070 {-1,-1}.\n  // https://codeforces.com/problemset/problem/500/G\n\
    \  pair<int, int> path_intersection(int a, int b, int c, int d) const {\n    static_assert(HLD);\n\
    \    int ab = LCA(a, b), ac = LCA(a, c), ad = LCA(a, d);\n    int bc = LCA(b,\
    \ c), bd = LCA(b, d), cd = LCA(c, d);\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^\
    \ bd;  // meet(a,b,c), meet(a,b,d)\n    if (x != y) return {x, y};\n    int z\
    \ = ac ^ ad ^ cd;\n    if (x != z) x = -1;\n    return {x, x};\n  }\n\n  // uv\
    \ path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E v\n  //\
    \ \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C ng \uFF09\
    -1\n  template <class F>\n  int max_path(F check, int u, int v) const {\n    static_assert(HLD);\n\
    \    if (!check(u)) return -1;\n    auto pd = get_path_decomposition(u, v, false);\n\
    \    for (auto [a, b] : pd) {\n      if (!check(V[a])) return u;\n      if (check(V[b]))\
    \ {\n        u = V[b];\n        continue;\n      }\n      int c =\n          binary_search([&](int\
    \ c) -> bool { return check(V[c]); }, a, b, 0);\n      return V[c];\n    }\n \
    \   return u;\n  }\n\n private:\n  void build_simple(int r = 0) {\n    N = G.N;\n\
    \    LID.assign(N, 0), RID.assign(N, 0);\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1);\n    depth.assign(N, 0), depth_weighted.assign(N, 0);\n\
    \    assert(G.is_prepared());\n\n    // 1st dfs.\n    int k = 0;\n    vc<int>\
    \ st;\n    st.reserve(N);\n    st.eb(r);\n    while (len(st)) {\n      int v =\
    \ POP(st);\n      LID[v] = k, V[k] = v;\n      ++k;\n      for (int i = G.indptr[v\
    \ + 1] - 1; i >= G.indptr[v]; --i) {\n        auto &e = G.csr_edges[i];\n    \
    \    if (e.to == parent[v]) continue;\n        parent[e.to] = v;\n        depth[e.to]\
    \ = depth[v] + 1;\n        depth_weighted[e.to] = depth_weighted[v] + e.cost;\n\
    \        VtoE[e.to] = e.id;\n        st.eb(e.to);\n      }\n    }\n\n    FOR_R(i,\
    \ N) {\n      int v = V[i];\n      chmax(RID[v], LID[v] + 1);\n      if (parent[v]\
    \ != -1) chmax(RID[parent[v]], RID[v]);\n    }\n  }\n\n  void build_HLD(int r\
    \ = 0) {\n    N = G.N;\n    LID.assign(N, 0), RID.assign(N, 0), head.assign(N,\
    \ r);\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\n    depth.assign(N,\
    \ 0), depth_weighted.assign(N, 0);\n    memo_tail.clear();\n    assert(G.is_prepared());\n\
    \n    // 1st dfs.\n    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n\
    \      st.eb(r);\n      while (len(st)) {\n        int v = POP(st);\n        V[k++]\
    \ = v;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          parent[e.to] = v, st.eb(e.to), depth[e.to] = depth[v] + 1;\n      \
    \    depth_weighted[e.to] = depth_weighted[v] + e.cost;\n          VtoE[e.to]\
    \ = e.id;\n        }\n      }\n      // \u4E00\u6642\u7684\u306B RID[v] := sz[v]\n\
    \      FOR_R(i, N) {\n        int v = V[i];\n        RID[v] += 1;\n        if\
    \ (parent[v] != -1) RID[parent[v]] += RID[v];\n      }\n    }\n    // 2nd dfs.\n\
    \    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n      st.eb(r);\n\
    \      while (len(st)) {\n        int v = POP(st);\n        V[k] = v, LID[v] =\
    \ k;\n        RID[v] = k + RID[v];\n        ++k;\n        int max_sz = 0, max_ch\
    \ = -1;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          if (chmax(max_sz, RID[e.to])) max_ch = e.to;\n        }\n        for\
    \ (int i = G.indptr[v + 1] - 1; i >= G.indptr[v]; --i) {\n          auto &e =\
    \ G.csr_edges[i];\n          if (e.to == parent[v] || e.to == max_ch) continue;\n\
    \          st.eb(e.to), head[e.to] = e.to;\n        }\n        if (max_ch != -1)\
    \ st.eb(max_ch), head[max_ch] = head[v];\n      }\n    }\n  }\n};\n#line 1 \"\
    ds/offline_query/mo.hpp\"\n// Nsqrt(Q)\r\nstruct Mo {\r\n  vc<pair<int, int>>\
    \ LR;\r\n  void add(int L, int R) { LR.emplace_back(L, R); }\r\n\r\n  static vc<int>\
    \ get_mo_order(vc<pair<int, int>> LR) {\r\n    int N = 1;\r\n    for (auto &&[l,\
    \ r]: LR) chmax(N, l), chmax(N, r);\r\n    int Q = len(LR);\r\n    if (Q == 0)\
    \ return {};\r\n    int bs = sqrt(3) * N / sqrt(2 * Q);\r\n    chmax(bs, 1);\r\
    \n    vc<int> I(Q);\r\n    iota(all(I), 0);\r\n    sort(all(I), [&](int a, int\
    \ b) {\r\n      int aa = LR[a].fi / bs, bb = LR[b].fi / bs;\r\n      if (aa !=\
    \ bb) return aa < bb;\r\n      return (aa & 1) ? LR[a].se > LR[b].se : LR[a].se\
    \ < LR[b].se;\r\n    });\r\n\r\n    auto cost = [&](int a, int b) -> int {\r\n\
    \      return abs(LR[I[a]].fi - LR[I[b]].fi) + abs(LR[I[a]].se - LR[I[b]].se);\r\
    \n    };\r\n\r\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\u30B9\u3067\u6570\u30D1\
    \u30FC\u30BB\u30F3\u30C8\r\n    FOR(k, Q - 5) {\r\n      if (cost(k, k + 2) +\
    \ cost(k + 1, k + 3)\r\n          < cost(k, k + 1) + cost(k + 2, k + 3)) {\r\n\
    \        swap(I[k + 1], I[k + 2]);\r\n      }\r\n      if (cost(k, k + 3) + cost(k\
    \ + 1, k + 4)\r\n          < cost(k, k + 1) + cost(k + 3, k + 4)) {\r\n      \
    \  swap(I[k + 1], I[k + 3]);\r\n      }\r\n    }\r\n    return I;\r\n  }\r\n\r\
    \n  template <typename F1, typename F2, typename F3, typename F4, typename F5>\r\
    \n  void calc(F1 add_l, F2 add_r, F3 rm_l, F4 rm_r, F5 query) {\r\n    auto I\
    \ = get_mo_order(LR);\r\n    int l = 0, r = 0;\r\n    for (auto idx: I) {\r\n\
    \      while (l > LR[idx].fi) add_l(--l);\r\n      while (r < LR[idx].se) add_r(r++);\r\
    \n      while (l < LR[idx].fi) rm_l(l++);\r\n      while (r > LR[idx].se) rm_r(--r);\r\
    \n      query(idx);\r\n    }\r\n  }\r\n};\r\n#line 3 \"graph/ds/mo_on_tree.hpp\"\
    \n\n// https://codeforces.com/contest/852/problem/I\ntemplate <typename TREE,\
    \ bool ORIENTED = false>\nstruct Mo_on_Tree {\n  TREE& tree;\n  vc<pair<int, int>>\
    \ LR;\n\n  Mo mo;\n  Mo_on_Tree(TREE& tree) : tree(tree) {}\n  void add(int u,\
    \ int v) {\n    if constexpr (!ORIENTED) {\n      if (tree.LID[u] > tree.LID[v])\
    \ swap(u, v);\n    }\n    LR.eb(tree.ELID(u) + 1, tree.ELID(v) + 1);\n  }\n\n\
    \  // init(): root \u3060\u3051\u304B\u3089\u306A\u308B path\n  // add_l(v), add_r(v)\uFF1A\
    \u30D1\u30B9\u306E\u5148\u982D / \u672B\u5C3E\u306B v \u3092\u8FFD\u52A0\n  //\
    \ rm_l(v), rm_r(v)\uFF1A\u30D1\u30B9\u306E\u5148\u982D / \u672B\u5C3E\u304B\u3089\
    \ v \u3092\u524A\u9664\n  // query(qid)\n  template <typename F1, typename F2,\
    \ typename F3, typename F4, typename F5,\n            typename F6>\n  void calc_vertex(F1\
    \ init, F2 add_l, F3 add_r, F4 rm_l, F5 rm_r, F6 query) {\n    const int N = tree.G.N;\n\
    \    auto I = Mo::get_mo_order(LR);\n\n    vc<int> FRM(2 * N), TO(2 * N), idx(2\
    \ * N);\n    vc<int> cnt(N);\n    deque<int> path = {0};\n    FOR(v, N) {\n  \
    \    int a = tree.ELID(v), b = tree.ERID(v);\n      FRM[a] = tree.parent[v], TO[a]\
    \ = v;\n      FRM[b] = v, TO[b] = tree.parent[v];\n      idx[a] = idx[b] = v;\n\
    \    }\n\n    auto flip_left = [&](int i) -> void {\n      const int a = FRM[i],\
    \ b = TO[i], c = idx[i];\n      if (cnt[c] == 0) {\n        int v = path.front()\
    \ ^ a ^ b;\n        path.emplace_front(v), add_l(v);\n      } else {\n       \
    \ int v = path.front();\n        path.pop_front(), rm_l(v);\n      }\n      cnt[c]\
    \ ^= 1;\n    };\n    auto flip_right = [&](int i) -> void {\n      const int a\
    \ = FRM[i], b = TO[i], c = idx[i];\n      if (cnt[c] == 0) {\n        int v =\
    \ path.back() ^ a ^ b;\n        path.emplace_back(v), add_r(v);\n      } else\
    \ {\n        int v = path.back();\n        path.pop_back(), rm_r(v);\n      }\n\
    \      cnt[c] ^= 1;\n    };\n\n    init();\n\n    int l = 1, r = 1;\n    for (auto\
    \ idx: I) {\n      int L = LR[idx].fi, R = LR[idx].se;\n      while (l > L) {\
    \ flip_left(--l); }\n      while (r < R) { flip_right(r++); }\n      while (l\
    \ < L) { flip_left(l++); }\n      while (r > R) { flip_right(--r); }\n      query(idx);\n\
    \    }\n  }\n\n  // init(): root \u3060\u3051\u304B\u3089\u306A\u308B path\n \
    \ // add_l(frm, to), add_r(frm, to)\uFF1A\u30D1\u30B9\u306E\u5148\u982D / \u672B\
    \u5C3E\u306B (frm,to) \u3092\u8FFD\u52A0\n  // rm_l(frm, to), rm_r(frm, to)\uFF1A\
    \u30D1\u30B9\u306E\u5148\u982D / \u672B\u5C3E\u306B (frm,to) \u3092\u8FFD\u52A0\
    \n  // query(qid)\n  template <typename F1, typename F2, typename F3, typename\
    \ F4, typename F5,\n            typename F6>\n  void calc_edge(F1 init, F2 add_l,\
    \ F3 add_r, F4 rm_l, F5 rm_r, F6 query) {\n    const int N = tree.G.N;\n    auto\
    \ I = Mo::get_mo_order(LR);\n\n    vc<int> FRM(2 * N), TO(2 * N), idx(2 * N);\n\
    \    vc<int> cnt(N);\n    deque<int> path = {0};\n    FOR(v, N) {\n      int a\
    \ = tree.ELID(v), b = tree.ERID(v);\n      FRM[a] = tree.parent[v], TO[a] = v;\n\
    \      FRM[b] = v, TO[b] = tree.parent[v];\n      idx[a] = idx[b] = v;\n    }\n\
    \n    auto flip_left = [&](int i) -> void {\n      const int a = FRM[i], b = TO[i],\
    \ c = idx[i];\n      if (cnt[c] == 0) {\n        int v = path.front() ^ a ^ b;\n\
    \        path.emplace_front(v), add_l(v, v ^ a ^ b);\n      } else {\n       \
    \ int v = path.front();\n        path.pop_front(), rm_l(v, v ^ a ^ b);\n     \
    \ }\n      cnt[c] ^= 1;\n    };\n    auto flip_right = [&](int i) -> void {\n\
    \      const int a = FRM[i], b = TO[i], c = idx[i];\n      if (cnt[c] == 0) {\n\
    \        int v = path.back() ^ a ^ b;\n        path.emplace_back(v), add_r(v ^\
    \ a ^ b, v);\n      } else {\n        int v = path.back();\n        path.pop_back(),\
    \ rm_r(v ^ a ^ b, v);\n      }\n      cnt[c] ^= 1;\n    };\n\n    init();\n\n\
    \    int l = 1, r = 1;\n    for (auto idx: I) {\n      int L = LR[idx].fi, R =\
    \ LR[idx].se;\n      while (l > L) { flip_left(--l); }\n      while (r < R) {\
    \ flip_right(r++); }\n      while (l < L) { flip_left(l++); }\n      while (r\
    \ > R) { flip_right(--r); }\n      query(idx);\n    }\n  }\n};\n#line 1 \"graph/ds/tree_monoid.hpp\"\
    \n\n#line 1 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type\
    \ = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n)\
    \ { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) const { return dat[size + i]; }\n  vc<X> get_all() const { return\
    \ {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i]\
    \ = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n\
    \    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) const {\n    assert(0 <= L && L <= R && R <= n);\n   \
    \ X vl = Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n   \
    \ while (L < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R\
    \ & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return\
    \ Monoid::op(vl, vr);\n  }\n\n  vc<int> prod_ids(int L, int R) const {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    vc<int> I, J;\n    L += size, R += size;\n \
    \   while (L < R) {\n      if (L & 1) I.eb(L++);\n      if (R & 1) J.eb(--R);\n\
    \      L >>= 1, R >>= 1;\n    }\n    reverse(all(J));\n    concat(I, J);\n   \
    \ return I;\n  }\n\n  X prod_all() const { return dat[1]; }\n\n  template <class\
    \ F>\n  int max_right(F check, int L) const {\n    assert(0 <= L && L <= n &&\
    \ check(Monoid::unit()));\n    if (L == n) return n;\n    L += size;\n    X sm\
    \ = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm,\
    \ dat[L]))) {\n        while (L < size) {\n          L = 2 * L;\n          if\
    \ (check(Monoid::op(sm, dat[L]))) {\n            sm = Monoid::op(sm, dat[L++]);\n\
    \          }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) const {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) {\n            sm = Monoid::op(dat[R--], sm);\n\
    \          }\n        }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r}\
    \ A[i xor x]\n  X xor_prod(int l, int r, int xor_val) const {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) {\n        x = Monoid::op(x, dat[(size >>\
    \ k) + ((l++) ^ xor_val)]);\n      }\n      if (r & 1) {\n        x = Monoid::op(x,\
    \ dat[(size >> k) + ((--r) ^ xor_val)]);\n      }\n      l /= 2, r /= 2, xor_val\
    \ /= 2;\n    }\n    return x;\n  }\n};\n#line 1 \"graph/tree.hpp\"\n\n#line 1\
    \ \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap\
    \ {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067\
    \ ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n\
    \    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k),\
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
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 3 \"graph/tree.hpp\"\
    \n\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\n// HLD=false:\
    \ \u5165\u529B\u8FBA\u9806\u3067 preorder\ntemplate <typename GT, bool HLD = true>\n\
    struct Tree {\n  using Graph_type = GT;\n  GT &G;\n  using WT = typename GT::cost_type;\n\
    \  int N;\n  vector<int> LID, RID, head, V, parent, VtoE;\n  vc<int> depth;\n\
    \  vc<WT> depth_weighted;\n  vc<int> memo_tail;\n\n  Tree(GT &G, int r = 0) :\
    \ G(G) { build(r); }\n\n  void build(int r = 0) {\n    if (r == -1) return;  //\
    \ build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\n    if constexpr (!HLD)\n\
    \      build_simple(r);\n    else\n      build_HLD(r);\n  }\n\n  vc<int> heavy_path_at(int\
    \ v) const {\n    static_assert(HLD);\n    assert(head[v] == v);\n    int k =\
    \ LID[v];\n    vc<int> P;\n    while (k < N && head[V[k]] == v) P.eb(V[k++]);\n\
    \    return P;\n  }\n\n  int heavy_child(int v) const {\n    static_assert(HLD);\n\
    \    if (RID[v] == LID[v] + 1) return -1;\n    return V[LID[v] + 1];\n  }\n\n\
    \  int tail(int v) {\n    static_assert(HLD);\n    if (memo_tail.empty()) {\n\
    \      memo_tail.assign(N, -1);\n      FOR_R(i, N) {\n        int v = V[i];\n\
    \        int w = heavy_child(v);\n        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\n\
    \      }\n    }\n    return memo_tail[v];\n  }\n\n  int e_to_v(int eid) const\
    \ {\n    auto e = G.edges[eid];\n    return (parent[e.frm] == e.to ? e.frm : e.to);\n\
    \  }\n  int v_to_e(int v) const { return VtoE[v]; }\n  int get_eid(int u, int\
    \ v) const {\n    if (parent[u] != v) swap(u, v);\n    assert(parent[u] == v);\n\
    \    return VtoE[u];\n  }\n\n  int ELID(int v) const { return 2 * LID[v] - depth[v];\
    \ }\n  int ERID(int v) const { return 2 * RID[v] - depth[v] - 1; }\n\n  // \u76EE\
    \u6A19\u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\n  int LA(int v, int\
    \ k) const {\n    static_assert(HLD);\n    assert(k <= depth[v]);\n    while (1)\
    \ {\n      int u = head[v];\n      if (LID[v] - k >= LID[u]) return V[LID[v] -\
    \ k];\n      k -= LID[v] - LID[u] + 1;\n      v = parent[u];\n    }\n  }\n\n \
    \ int LCA(int u, int v) const {\n    static_assert(HLD);\n    for (;; v = parent[head[v]])\
    \ {\n      if (LID[u] > LID[v]) swap(u, v);\n      if (head[u] == head[v]) return\
    \ u;\n    }\n  }\n\n  int meet(int a, int b, int c) const {\n    static_assert(HLD);\n\
    \    return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\n  }\n\n  int subtree_size(int\
    \ v) const { return RID[v] - LID[v]; }\n\n  int subtree_size(int v, int root)\
    \ const {\n    static_assert(HLD);\n    if (v == root) return N;\n    int x =\
    \ jump(v, root, 1);\n    if (in_subtree(v, x)) return RID[v] - LID[v];\n    return\
    \ N - RID[x] + LID[x];\n  }\n\n  int dist(int a, int b) const {\n    static_assert(HLD);\n\
    \    int c = LCA(a, b);\n    return depth[a] + depth[b] - 2 * depth[c];\n  }\n\
    \n  WT dist_weighted(int a, int b) const {\n    static_assert(HLD);\n    int c\
    \ = LCA(a, b);\n    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\n\
    \  }\n\n  // a is in b\n  bool in_subtree(int a, int b) const {\n    return LID[b]\
    \ <= LID[a] && LID[a] < RID[b];\n  }\n\n  int jump(int a, int b, ll k) const {\n\
    \    static_assert(HLD);\n    if (k == 1) {\n      if (a == b) return -1;\n  \
    \    return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\n\
    \    }\n    int c = LCA(a, b);\n    int d_ac = depth[a] - depth[c];\n    int d_bc\
    \ = depth[b] - depth[c];\n    if (k > d_ac + d_bc) return -1;\n    if (k <= d_ac)\
    \ return LA(a, k);\n    return LA(b, d_ac + d_bc - k);\n  }\n\n  vc<int> collect_child(int\
    \ v) const {\n    vc<int> res;\n    for (auto &&e : G[v])\n      if (e.to != parent[v])\
    \ res.eb(e.to);\n    return res;\n  }\n\n  vc<int> collect_subtree(int v) const\
    \ {\n    return {V.begin() + LID[v], V.begin() + RID[v]};\n  }\n\n  vc<int> collect_light(int\
    \ v) const {\n    static_assert(HLD);\n    vc<int> res;\n    for (auto &&e : G[v])\
    \ {\n      if (e.to != parent[v] && head[e.to] == e.to) res.eb(e.to);\n    }\n\
    \    return res;\n  }\n\n  vc<pair<int, int>> get_path_decomposition(int u, int\
    \ v, bool edge) const {\n    static_assert(HLD);\n    // [\u59CB\u70B9, \u7D42\
    \u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\n    vc<pair<int, int>> up, down;\n\
    \    while (1) {\n      if (head[u] == head[v]) break;\n      if (LID[u] < LID[v])\
    \ {\n        down.eb(LID[head[v]], LID[v]);\n        v = parent[head[v]];\n  \
    \    } else {\n        up.eb(LID[u], LID[head[u]]);\n        u = parent[head[u]];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\n  \
    \  elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\n    reverse(all(down));\n\
    \    up.insert(up.end(), all(down));\n    return up;\n  }\n\n  // \u8FBA\u306E\
    \u5217\u306E\u60C5\u5831 (frm,to,str)\n  // str = \"heavy_up\", \"heavy_down\"\
    , \"light_up\", \"light_down\"\n  vc<tuple<int, int, string>> get_path_decomposition_detail(\n\
    \      int u, int v) const {\n    static_assert(HLD);\n    vc<tuple<int, int,\
    \ string>> up, down;\n    while (1) {\n      if (head[u] == head[v]) break;\n\
    \      if (LID[u] < LID[v]) {\n        if (v != head[v]) down.eb(head[v], v, \"\
    heavy_down\"), v = head[v];\n        down.eb(parent[v], v, \"light_down\"), v\
    \ = parent[v];\n      } else {\n        if (u != head[u]) up.eb(u, head[u], \"\
    heavy_up\"), u = head[u];\n        up.eb(u, parent[u], \"light_up\"), u = parent[u];\n\
    \      }\n    }\n    if (LID[u] < LID[v]) down.eb(u, v, \"heavy_down\");\n   \
    \ elif (LID[v] < LID[u]) up.eb(u, v, \"heavy_up\");\n    reverse(all(down));\n\
    \    concat(up, down);\n    return up;\n  }\n\n  vc<int> restore_path(int u, int\
    \ v) const {\n    vc<int> L, R;\n    while (depth[u] > depth[v]) L.eb(u), u =\
    \ parent[u];\n    while (depth[u] < depth[v]) R.eb(v), v = parent[v];\n    while\
    \ (u != v) L.eb(u), R.eb(v), u = parent[u], v = parent[v];\n    L.eb(u);\n   \
    \ while (len(R)) L.eb(POP(R));\n    return L;\n  }\n\n  // path [a,b] \u3068 [c,d]\
    \ \u306E\u4EA4\u308F\u308A. \u7A7A\u306A\u3089\u3070 {-1,-1}.\n  // https://codeforces.com/problemset/problem/500/G\n\
    \  pair<int, int> path_intersection(int a, int b, int c, int d) const {\n    static_assert(HLD);\n\
    \    int ab = LCA(a, b), ac = LCA(a, c), ad = LCA(a, d);\n    int bc = LCA(b,\
    \ c), bd = LCA(b, d), cd = LCA(c, d);\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^\
    \ bd;  // meet(a,b,c), meet(a,b,d)\n    if (x != y) return {x, y};\n    int z\
    \ = ac ^ ad ^ cd;\n    if (x != z) x = -1;\n    return {x, x};\n  }\n\n  // uv\
    \ path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E v\n  //\
    \ \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C ng \uFF09\
    -1\n  template <class F>\n  int max_path(F check, int u, int v) const {\n    static_assert(HLD);\n\
    \    if (!check(u)) return -1;\n    auto pd = get_path_decomposition(u, v, false);\n\
    \    for (auto [a, b] : pd) {\n      if (!check(V[a])) return u;\n      if (check(V[b]))\
    \ {\n        u = V[b];\n        continue;\n      }\n      int c =\n          binary_search([&](int\
    \ c) -> bool { return check(V[c]); }, a, b, 0);\n      return V[c];\n    }\n \
    \   return u;\n  }\n\n private:\n  void build_simple(int r = 0) {\n    N = G.N;\n\
    \    LID.assign(N, 0), RID.assign(N, 0);\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1);\n    depth.assign(N, 0), depth_weighted.assign(N, 0);\n\
    \    assert(G.is_prepared());\n\n    // 1st dfs.\n    int k = 0;\n    vc<int>\
    \ st;\n    st.reserve(N);\n    st.eb(r);\n    while (len(st)) {\n      int v =\
    \ POP(st);\n      LID[v] = k, V[k] = v;\n      ++k;\n      for (int i = G.indptr[v\
    \ + 1] - 1; i >= G.indptr[v]; --i) {\n        auto &e = G.csr_edges[i];\n    \
    \    if (e.to == parent[v]) continue;\n        parent[e.to] = v;\n        depth[e.to]\
    \ = depth[v] + 1;\n        depth_weighted[e.to] = depth_weighted[v] + e.cost;\n\
    \        VtoE[e.to] = e.id;\n        st.eb(e.to);\n      }\n    }\n\n    FOR_R(i,\
    \ N) {\n      int v = V[i];\n      chmax(RID[v], LID[v] + 1);\n      if (parent[v]\
    \ != -1) chmax(RID[parent[v]], RID[v]);\n    }\n  }\n\n  void build_HLD(int r\
    \ = 0) {\n    N = G.N;\n    LID.assign(N, 0), RID.assign(N, 0), head.assign(N,\
    \ r);\n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\n    depth.assign(N,\
    \ 0), depth_weighted.assign(N, 0);\n    memo_tail.clear();\n    assert(G.is_prepared());\n\
    \n    // 1st dfs.\n    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n\
    \      st.eb(r);\n      while (len(st)) {\n        int v = POP(st);\n        V[k++]\
    \ = v;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          parent[e.to] = v, st.eb(e.to), depth[e.to] = depth[v] + 1;\n      \
    \    depth_weighted[e.to] = depth_weighted[v] + e.cost;\n          VtoE[e.to]\
    \ = e.id;\n        }\n      }\n      // \u4E00\u6642\u7684\u306B RID[v] := sz[v]\n\
    \      FOR_R(i, N) {\n        int v = V[i];\n        RID[v] += 1;\n        if\
    \ (parent[v] != -1) RID[parent[v]] += RID[v];\n      }\n    }\n    // 2nd dfs.\n\
    \    {\n      int k = 0;\n      vc<int> st;\n      st.reserve(N);\n      st.eb(r);\n\
    \      while (len(st)) {\n        int v = POP(st);\n        V[k] = v, LID[v] =\
    \ k;\n        RID[v] = k + RID[v];\n        ++k;\n        int max_sz = 0, max_ch\
    \ = -1;\n        for (auto &e : G[v]) {\n          if (e.to == parent[v]) continue;\n\
    \          if (chmax(max_sz, RID[e.to])) max_ch = e.to;\n        }\n        for\
    \ (int i = G.indptr[v + 1] - 1; i >= G.indptr[v]; --i) {\n          auto &e =\
    \ G.csr_edges[i];\n          if (e.to == parent[v] || e.to == max_ch) continue;\n\
    \          st.eb(e.to), head[e.to] = e.to;\n        }\n        if (max_ch != -1)\
    \ st.eb(max_ch), head[max_ch] = head[v];\n      }\n    }\n  }\n};\n#line 1 \"\
    alg/monoid/monoid_reverse.hpp\"\n\ntemplate <class Monoid>\nstruct Monoid_Reverse\
    \ {\n  using value_type = typename Monoid::value_type;\n  using X = value_type;\n\
    \  static constexpr X op(const X &x, const X &y) { return Monoid::op(y, x); }\n\
    \  static constexpr X unit() { return Monoid::unit(); }\n  static const bool commute\
    \ = Monoid::commute;\n};\n#line 5 \"graph/ds/tree_monoid.hpp\"\n\ntemplate <typename\
    \ TREE, typename Monoid, bool edge>\nstruct Tree_Monoid {\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  TREE &tree;\n  int N;\n  SegTree<MX>\
    \ seg;\n  SegTree<Monoid_Reverse<MX>> seg_r;\n\n  Tree_Monoid(TREE &tree) : tree(tree),\
    \ N(tree.N) {\n    build([](int i) -> X { return MX::unit(); });\n  }\n\n  Tree_Monoid(TREE\
    \ &tree, vc<X> &dat) : tree(tree), N(tree.N) {\n    build([&](int i) -> X { return\
    \ dat[i]; });\n  }\n\n  template <typename F>\n  Tree_Monoid(TREE &tree, F f)\
    \ : tree(tree), N(tree.N) {\n    build(f);\n  }\n\n  template <typename F>\n \
    \ void build(F f) {\n    if (!edge) {\n      auto f_v = [&](int i) -> X { return\
    \ f(tree.V[i]); };\n      seg.build(N, f_v);\n      if constexpr (!MX::commute)\
    \ {\n        seg_r.build(N, f_v);\n      }\n    } else {\n      auto f_e = [&](int\
    \ i) -> X {\n        return (i == 0 ? MX::unit() : f(tree.v_to_e(tree.V[i])));\n\
    \      };\n      seg.build(N, f_e);\n      if constexpr (!MX::commute) {\n   \
    \     seg_r.build(N, f_e);\n      }\n    }\n  }\n\n  void set(int i, X x) {\n\
    \    if constexpr (edge) i = tree.e_to_v(i);\n    i = tree.LID[i];\n    seg.set(i,\
    \ x);\n    if constexpr (!MX::commute) seg_r.set(i, x);\n  }\n\n  void multiply(int\
    \ i, X x) {\n    if constexpr (edge) i = tree.e_to_v(i);\n    i = tree.LID[i];\n\
    \    seg.multiply(i, x);\n    if constexpr (!MX::commute) seg_r.multiply(i, x);\n\
    \  }\n\n  X prod_path(int u, int v) {\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\n    X val = MX::unit();\n    for (auto &&[a, b] : pd) {\n      val\
    \ = MX::op(val, _get_prod(a, b));\n    }\n    return val;\n  }\n\n  // uv path\
    \ \u4E0A\u3067 prod_path(u, x) \u304C check \u3092\u6E80\u305F\u3059\u6700\u5F8C\
    \u306E x\n  // \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A path(u,u) \u304C\
    \ ng \uFF09-1\n  template <class F>\n  int max_path(F check, int u, int v) {\n\
    \    if constexpr (edge) return max_path_edge(check, u, v);\n    if (!check(prod_path(u,\
    \ u))) return -1;\n    auto pd = tree.get_path_decomposition(u, v, edge);\n  \
    \  X val = MX::unit();\n    for (auto &&[a, b] : pd) {\n      X x = _get_prod(a,\
    \ b);\n      if (check(MX::op(val, x))) {\n        val = MX::op(val, x);\n   \
    \     u = (tree.V[b]);\n        continue;\n      }\n      auto check_tmp = [&](X\
    \ x) -> bool { return check(MX::op(val, x)); };\n      if (a <= b) {\n       \
    \ // \u4E0B\u308A\n        auto i = seg.max_right(check_tmp, a);\n        return\
    \ (i == a ? u : tree.V[i - 1]);\n      } else {\n        // \u4E0A\u308A\n   \
    \     int i = 0;\n        if constexpr (MX::commute) i = seg.min_left(check_tmp,\
    \ a + 1);\n        if constexpr (!MX::commute) i = seg_r.min_left(check_tmp, a\
    \ + 1);\n        if (i == a + 1) return u;\n        return tree.V[i];\n      }\n\
    \    }\n    return v;\n  }\n\n  X prod_subtree(int u, int root = -1) {\n    if\
    \ (root == u) return prod_all();\n    if (root == -1 || tree.in_subtree(u, root))\
    \ {\n      int l = tree.LID[u], r = tree.RID[u];\n      return seg.prod(l + edge,\
    \ r);\n    }\n    assert(!edge);  // \u3055\u307C\u308A\n    u = tree.jump(u,\
    \ root, 1);\n    int L = tree.LID[u], R = tree.RID[u];\n    return MX::op(seg.prod(0,\
    \ L), seg.prod(R, N));\n  }\n\n  X prod_all() { return prod_subtree(tree.V[0]);\
    \ }\n\n  inline X _get_prod(int a, int b) {\n    if constexpr (MX::commute) {\n\
    \      return (a <= b) ? seg.prod(a, b + 1) : seg.prod(b, a + 1);\n    }\n   \
    \ return (a <= b) ? seg.prod(a, b + 1) : seg_r.prod(b, a + 1);\n  }\n\n private:\n\
    \  template <class F>\n  int max_path_edge(F check, int u, int v) {\n    static_assert(edge);\n\
    \    if (!check(MX::unit())) return -1;\n    int lca = tree.lca(u, v);\n    auto\
    \ pd = tree.get_path_decomposition(u, lca, edge);\n    X val = MX::unit();\n\n\
    \    // climb\n    for (auto &&[a, b] : pd) {\n      assert(a >= b);\n      X\
    \ x = _get_prod(a, b);\n      if (check(MX::op(val, x))) {\n        val = MX::op(val,\
    \ x);\n        u = (tree.parent[tree.V[b]]);\n        continue;\n      }\n   \
    \   auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x)); };\n   \
    \   int i = 0;\n      if constexpr (MX::commute) i = seg.min_left(check_tmp, a\
    \ + 1);\n      if constexpr (!MX::commute) i = seg_r.min_left(check_tmp, a + 1);\n\
    \      if (i == a + 1) return u;\n      return tree.parent[tree.V[i]];\n    }\n\
    \    // down\n    pd = tree.get_path_decomposition(lca, v, edge);\n    for (auto\
    \ &&[a, b] : pd) {\n      assert(a <= b);\n      X x = _get_prod(a, b);\n    \
    \  if (check(MX::op(val, x))) {\n        val = MX::op(val, x);\n        u = (tree.V[b]);\n\
    \        continue;\n      }\n      auto check_tmp = [&](X x) -> bool { return\
    \ check(MX::op(val, x)); };\n      auto i = seg.max_right(check_tmp, a);\n   \
    \   return (i == a ? u : tree.V[i - 1]);\n    }\n    return v;\n  }\n};\n#line\
    \ 1 \"alg/monoid/affine.hpp\"\n\n// op(F, G) = comp(G,F), F \u306E\u3042\u3068\
    \u3067 G\ntemplate <typename K>\nstruct Monoid_Affine {\n  using F = pair<K, K>;\n\
    \  using value_type = F;\n  using X = value_type;\n  static constexpr F op(const\
    \ F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second * y.first\
    \ + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a,\
    \ b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr\
    \ K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n  }\n\
    \  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr bool\
    \ commute = false;\n};\n#line 1 \"alg/monoid/add_pair.hpp\"\n\ntemplate <typename\
    \ E>\nstruct Monoid_Add_Pair {\n  using value_type = pair<E, E>;\n  using X =\
    \ value_type;\n  static constexpr X op(const X &x, const X &y) {\n    return {x.fi\
    \ + y.fi, x.se + y.se};\n  }\n  static constexpr X inverse(const X &x) { return\
    \ {-x.fi, -x.se}; }\n  static constexpr X unit() { return {0, 0}; }\n  static\
    \ constexpr bool commute = true;\n};\n#line 1 \"mod/modint_common.hpp\"\n\n#line\
    \ 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 3 \"mod/modint_common.hpp\"\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n  assert(0\
    \ <= n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (len(dat) <= n)\
    \ {\n    int now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n  \
    \  dat.resize(m);\n    FOR(i, now, m) dat[i] = dat[i - 1] * mint::raw(i);\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  if\
    \ (n < 0) return mint(0);\n  if (len(dat) <= n) {\n    int now = len(dat);\n \
    \   int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n    dat[m - 1]\
    \ = fact<mint>(m - 1).inverse();\n    FOR_R(i, now, m - 1) dat[i] = dat[i + 1]\
    \ * mint::raw(i + 1);\n  }\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n\
    \  assert(1 <= n && n < mod);\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j ==\
    \ 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n\
    \  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j,\
    \ W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <=\
    \ n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n\
    \      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return\
    \ C[n][k];\n}\n\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if\
    \ constexpr (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n\
    \    return (d == 0 ? mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n\
    \ + d - 1, d);\n}\n#line 2 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(0 < umod && umod\
    \ < u32(1) << 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n\
    \    x.val = v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr\
    \ modint(u32 x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod)\
    \ {}\n  constexpr modint(u128 x) : val(x % umod) {}\n  constexpr modint(int x)\
    \ : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll x) : val((x %=\
    \ mod) < 0 ? x + mod : x){};\n  constexpr modint(i128 x) : val((x %= mod) < 0\
    \ ? x + mod : x){};\n  bool operator<(const modint &other) const { return val\
    \ < other.val; }\n  modint &operator+=(const modint &p) {\n    if ((val += p.val)\
    \ >= umod) val -= umod;\n    return *this;\n  }\n  modint &operator-=(const modint\
    \ &p) {\n    if ((val += umod - p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = u64(val) * p.val % umod;\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint::raw(val\
    \ ? mod - val : u32(0)); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0) return inverse().pow(-n);\n\
    \    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n    \
    \  if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r\
    \ \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info()\
    \ {\n    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161)\
    \ return {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod ==\
    \ 754974721) return {24, 362};\n    if (mod == 880803841) return {23, 211};\n\
    \    if (mod == 943718401) return {22, 663003469};\n    if (mod == 998244353)\
    \ return {23, 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if\
    \ (mod == 1012924417) return {21, 368093570};\n    if (mod == 1224736769) return\
    \ {24, 1191450770};\n    if (mod == 2013265921) return {27, 244035102};\n    return\
    \ {-1, -1};\n  }\n  static constexpr bool can_ntt() { return ntt_info().fi !=\
    \ -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid rd(modint<mod> &x) {\n\
    \  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <= x.val && x.val < mod);\n\
    }\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n}\n#endif\n\
    \nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 11 \"test/1_mytest/mo_on_tree.test.cpp\"\n\nusing mint = modint998;\nusing\
    \ AFF = pair<mint, mint>;\n\nAFF gen() {\n  mint a = RNG(1, 3);\n  mint b = RNG(0,\
    \ 3);\n  return {a, b};\n}\n\ntemplate <typename Mono, bool EDGE>\nvoid test()\
    \ {\n  constexpr bool ORIENTED = !(Mono::commute);\n  FOR(N, 1, 50) {\n    FOR(Q,\
    \ 1, 50) {\n      vc<pi> query(Q);\n      vc<AFF> dat;\n      if (!EDGE) {\n \
    \       FOR(v, N) dat.eb(gen());\n      } else {\n        FOR(i, N - 1) dat.eb(gen());\n\
    \      }\n      Graph<int, 0> G(N);\n      FOR(v, 1, N) {\n        int p = RNG(0,\
    \ v);\n        G.add(p, v);\n      }\n      G.build();\n      Tree<decltype(G)>\
    \ tree(G);\n      Tree_Monoid<decltype(tree), Mono, EDGE> TM(tree, dat);\n\n \
    \     FOR(q, Q) {\n        int a = RNG(0, N);\n        int b = RNG(0, N);\n  \
    \      query[q] = {a, b};\n      }\n      Mo_on_Tree<decltype(tree), ORIENTED>\
    \ mo(tree);\n      for (auto&& [a, b]: query) mo.add(a, b);\n\n      if constexpr\
    \ (!EDGE) {\n        AFF f = Mono::unit();\n        auto init = [&]() -> void\
    \ { f = dat[0]; };\n        auto add_l = [&](int v) -> void { f = Mono::op(dat[v],\
    \ f); };\n        auto rm_l = [&](int v) -> void { f = Mono::op(Mono::inverse(dat[v]),\
    \ f); };\n        auto add_r = [&](int v) -> void { f = Mono::op(f, dat[v]); };\n\
    \        auto rm_r = [&](int v) -> void { f = Mono::op(f, Mono::inverse(dat[v]));\
    \ };\n        auto ans = [&](int q) -> void { assert(f == TM.prod_path(query[q].fi,\
    \ query[q].se)); };\n        mo.calc_vertex(init, add_l, add_r, rm_l, rm_r, ans);\n\
    \      } else {\n        AFF f = Mono::unit();\n        auto get = [&](int a,\
    \ int b) -> int { return tree.v_to_e((tree.parent[a] == b ? a : b)); };\n    \
    \    auto init = [&]() -> void {};\n        auto add_l = [&](int a, int b) ->\
    \ void { f = Mono::op(dat[get(a, b)], f); };\n        auto rm_l = [&](int a, int\
    \ b) -> void { f = Mono::op(Mono::inverse(dat[get(a, b)]), f); };\n        auto\
    \ add_r = [&](int a, int b) -> void { f = Mono::op(f, dat[get(a, b)]); };\n  \
    \      auto rm_r = [&](int a, int b) -> void { f = Mono::op(f, Mono::inverse(dat[get(a,\
    \ b)])); };\n        auto ans = [&](int q) -> void { assert(f == TM.prod_path(query[q].fi,\
    \ query[q].se)); };\n        mo.calc_edge(init, add_l, add_r, rm_l, rm_r, ans);\n\
    \      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  // \u30D1\u30B9\u306E\u5411\u304D\
    \u304C\u53EF\u9006\u3067\u9802\u70B9\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\
    \n  test<Monoid_Add_Pair<mint>, false>();\n  // \u30D1\u30B9\u306E\u5411\u304D\
    \u304C\u4E0D\u53EF\u9006\u3067\u9802\u70B9\u975E\u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9\u7A4D\n  test<Monoid_Affine<mint>, false>();\n  // \u30D1\u30B9\u306E\u5411\
    \u304D\u304C\u53EF\u9006\u3067\u8FBA\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\
    \n  test<Monoid_Add_Pair<mint>, true>();\n  // \u30D1\u30B9\u306E\u5411\u304D\u304C\
    \u4E0D\u53EF\u9006\u3067\u8FBA\u975E\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\
    \n  test<Monoid_Affine<mint>, true>();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/base.hpp\"\n#include \"graph/tree.hpp\"\n#include \"graph/ds/mo_on_tree.hpp\"\
    \n#include \"graph/ds/tree_monoid.hpp\"\n#include \"alg/monoid/affine.hpp\"\n\
    #include \"alg/monoid/add_pair.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint\
    \ = modint998;\nusing AFF = pair<mint, mint>;\n\nAFF gen() {\n  mint a = RNG(1,\
    \ 3);\n  mint b = RNG(0, 3);\n  return {a, b};\n}\n\ntemplate <typename Mono,\
    \ bool EDGE>\nvoid test() {\n  constexpr bool ORIENTED = !(Mono::commute);\n \
    \ FOR(N, 1, 50) {\n    FOR(Q, 1, 50) {\n      vc<pi> query(Q);\n      vc<AFF>\
    \ dat;\n      if (!EDGE) {\n        FOR(v, N) dat.eb(gen());\n      } else {\n\
    \        FOR(i, N - 1) dat.eb(gen());\n      }\n      Graph<int, 0> G(N);\n  \
    \    FOR(v, 1, N) {\n        int p = RNG(0, v);\n        G.add(p, v);\n      }\n\
    \      G.build();\n      Tree<decltype(G)> tree(G);\n      Tree_Monoid<decltype(tree),\
    \ Mono, EDGE> TM(tree, dat);\n\n      FOR(q, Q) {\n        int a = RNG(0, N);\n\
    \        int b = RNG(0, N);\n        query[q] = {a, b};\n      }\n      Mo_on_Tree<decltype(tree),\
    \ ORIENTED> mo(tree);\n      for (auto&& [a, b]: query) mo.add(a, b);\n\n    \
    \  if constexpr (!EDGE) {\n        AFF f = Mono::unit();\n        auto init =\
    \ [&]() -> void { f = dat[0]; };\n        auto add_l = [&](int v) -> void { f\
    \ = Mono::op(dat[v], f); };\n        auto rm_l = [&](int v) -> void { f = Mono::op(Mono::inverse(dat[v]),\
    \ f); };\n        auto add_r = [&](int v) -> void { f = Mono::op(f, dat[v]); };\n\
    \        auto rm_r = [&](int v) -> void { f = Mono::op(f, Mono::inverse(dat[v]));\
    \ };\n        auto ans = [&](int q) -> void { assert(f == TM.prod_path(query[q].fi,\
    \ query[q].se)); };\n        mo.calc_vertex(init, add_l, add_r, rm_l, rm_r, ans);\n\
    \      } else {\n        AFF f = Mono::unit();\n        auto get = [&](int a,\
    \ int b) -> int { return tree.v_to_e((tree.parent[a] == b ? a : b)); };\n    \
    \    auto init = [&]() -> void {};\n        auto add_l = [&](int a, int b) ->\
    \ void { f = Mono::op(dat[get(a, b)], f); };\n        auto rm_l = [&](int a, int\
    \ b) -> void { f = Mono::op(Mono::inverse(dat[get(a, b)]), f); };\n        auto\
    \ add_r = [&](int a, int b) -> void { f = Mono::op(f, dat[get(a, b)]); };\n  \
    \      auto rm_r = [&](int a, int b) -> void { f = Mono::op(f, Mono::inverse(dat[get(a,\
    \ b)])); };\n        auto ans = [&](int q) -> void { assert(f == TM.prod_path(query[q].fi,\
    \ query[q].se)); };\n        mo.calc_edge(init, add_l, add_r, rm_l, rm_r, ans);\n\
    \      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  // \u30D1\u30B9\u306E\u5411\u304D\
    \u304C\u53EF\u9006\u3067\u9802\u70B9\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\
    \n  test<Monoid_Add_Pair<mint>, false>();\n  // \u30D1\u30B9\u306E\u5411\u304D\
    \u304C\u4E0D\u53EF\u9006\u3067\u9802\u70B9\u975E\u53EF\u63DB\u30E2\u30CE\u30A4\
    \u30C9\u7A4D\n  test<Monoid_Affine<mint>, false>();\n  // \u30D1\u30B9\u306E\u5411\
    \u304D\u304C\u53EF\u9006\u3067\u8FBA\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\
    \n  test<Monoid_Add_Pair<mint>, true>();\n  // \u30D1\u30B9\u306E\u5411\u304D\u304C\
    \u4E0D\u53EF\u9006\u3067\u8FBA\u975E\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\
    \n  test<Monoid_Affine<mint>, true>();\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/base.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/ds/mo_on_tree.hpp
  - ds/offline_query/mo.hpp
  - graph/ds/tree_monoid.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/monoid_reverse.hpp
  - alg/monoid/affine.hpp
  - alg/monoid/add_pair.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - other/bit.hpp
  isVerificationFile: true
  path: test/1_mytest/mo_on_tree.test.cpp
  requiredBy: []
  timestamp: '2026-08-29 09:24:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/mo_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/mo_on_tree.test.cpp
- /verify/test/1_mytest/mo_on_tree.test.cpp.html
title: test/1_mytest/mo_on_tree.test.cpp
---
