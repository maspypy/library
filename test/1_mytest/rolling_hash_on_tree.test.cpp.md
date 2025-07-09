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
    path: graph/ds/rolling_hash_on_tree.hpp
    title: graph/ds/rolling_hash_on_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_graph.hpp
    title: random/random_graph.hpp
  - icon: ':heavy_check_mark:'
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
  bundledCode: "#line 1 \"test/1_mytest/rolling_hash_on_tree.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n\
    #if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    // https://codeforces.com/blog/entry/126772?#comment-1154880\n#include <bits/allocator.h>\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\"\
    )\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
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
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq_min<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pq_max<T> &que) {\n\
    \  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T>\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 4 \"test/1_mytest/rolling_hash_on_tree.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"graph/tree.hpp\"\n\r\n#line 2 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\
    \u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32\
    \ n = 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while\
    \ (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\
    \u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\
    \u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used), 0);\r\n    cap\
    \ = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) / 2 - cap; }\r\n\
    \r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i]\
    \ && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val&\
    \ operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\
    \n    if (!used[i]) { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n  \
    \  return val[i];\r\n  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\
    \n    int i = index(k);\r\n    return (used[i] ? val[i] : default_value);\r\n\
    \  }\r\n\r\n  bool count(const u64& k) {\r\n    int i = index(k);\r\n    return\
    \ used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename\
    \ F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used)) if (used[i]) f(key[i],\
    \ val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\n  vc<u64> key;\r\n  vc<Val>\
    \ val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x) {\r\n    static const u64\
    \ FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
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
    #line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\
    \u308D\u3044\u308D\u3002\r\ntemplate <typename GT>\r\nstruct Tree {\r\n  using\
    \ Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\n  int\
    \ N;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\n\
    \  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G)\
    \ { build(r, hld); }\r\n\r\n  void build(int r = 0, bool hld = 1) {\r\n    if\
    \ (r == -1) return; // build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\r\
    \n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);\r\
    \n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\r\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void\
    \ dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\
    \n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l\
    \ = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    //\
    \ \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n\
    \    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: G[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\n\
    \      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n    \
    \  dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a] && head[e.to] ==\
    \ v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\n\
    \      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ heavy_child(int v) {\r\n    int k = LID[v] + 1;\r\n    if (k == N) return -1;\r\
    \n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\n  }\r\n\r\n  vc<int>\
    \ memo_tail;\r\n\r\n  int tail(int v) {\r\n    if (memo_tail.empty()) {\r\n  \
    \    memo_tail.assign(N, -1);\r\n      FOR_R(i, N) {\r\n        int v = V[i];\r\
    \n        int w = heavy_child(v);\r\n        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\r\
    \n      }\r\n    }\r\n    return memo_tail[v];\r\n  }\r\n\r\n  int e_to_v(int\
    \ eid) {\r\n    auto e = G.edges[eid];\r\n    return (parent[e.frm] == e.to ?\
    \ e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\n  int get_eid(int\
    \ u, int v) {\r\n    if (parent[u] != v) swap(u, v);\r\n    assert(parent[u] ==\
    \ v);\r\n    return VtoE[u];\r\n  }\r\n\r\n  int ELID(int v) { return 2 * LID[v]\
    \ - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }\r\n\
    \r\n  // \u76EE\u6A19\u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\r\n  int\
    \ LA(int v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n    \
    \  int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\
    \n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\
    \  int la(int u, int v) { return LA(u, v); }\r\n\r\n  int LCA(int u, int v) {\r\
    \n    for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\
    \n      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int meet(int\
    \ a, int b, int c) { return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c); }\r\n  int lca(int\
    \ u, int v) { return LCA(u, v); }\r\n\r\n  int subtree_size(int v, int root =\
    \ -1) {\r\n    if (root == -1) return RID[v] - LID[v];\r\n    if (v == root) return\
    \ N;\r\n    int x = jump(v, root, 1);\r\n    if (in_subtree(v, x)) return RID[v]\
    \ - LID[v];\r\n    return N - RID[x] + LID[x];\r\n  }\r\n\r\n  int dist(int a,\
    \ int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2 * depth[c];\r\
    \n  }\r\n\r\n  WT dist_weighted(int a, int b) {\r\n    int c = LCA(a, b);\r\n\
    \    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\r\
    \n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int a, int b) { return LID[b]\
    \ <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int a, int b, ll k) {\r\n\
    \    if (k == 1) {\r\n      if (a == b) return -1;\r\n      return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a,\
    \ b);\r\n    int d_ac = depth[a] - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\
    \n    if (k > d_ac + d_bc) return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\
    \n    return LA(b, d_ac + d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int\
    \ v) {\r\n    vc<int> res;\r\n    for (auto &&e: G[v])\r\n      if (e.to != parent[v])\
    \ res.eb(e.to);\r\n    return res;\r\n  }\r\n\r\n  vc<int> collect_subtree(int\
    \ v) { return {V.begin() + LID[v], V.begin() + RID[v]}; }\r\n\r\n  vc<int> collect_light(int\
    \ v) {\r\n    vc<int> res;\r\n    bool skip = true;\r\n    for (auto &&e: G[v])\r\
    \n      if (e.to != parent[v]) {\r\n        if (!skip) res.eb(e.to);\r\n     \
    \   skip = false;\r\n      }\r\n    return res;\r\n  }\r\n\r\n  vc<pair<int, int>>\
    \ get_path_decomposition(int u, int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\
    \u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>> up,\
    \ down;\r\n    while (1) {\r\n      if (head[u] == head[v]) break;\r\n      if\
    \ (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]], LID[v]);\r\n        v =\
    \ parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\
    \n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v])\
    \ down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u],\
    \ LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(), all(down));\r\
    \n    return up;\r\n  }\r\n\r\n  // \u8FBA\u306E\u5217\u306E\u60C5\u5831 (frm,to,str)\r\
    \n  // str = \"heavy_up\", \"heavy_down\", \"light_up\", \"light_down\"\r\n  vc<tuple<int,\
    \ int, string>> get_path_decomposition_detail(int u, int v) {\r\n    vc<tuple<int,\
    \ int, string>> up, down;\r\n    while (1) {\r\n      if (head[u] == head[v])\
    \ break;\r\n      if (LID[u] < LID[v]) {\r\n        if (v != head[v]) down.eb(head[v],\
    \ v, \"heavy_down\"), v = head[v];\r\n        down.eb(parent[v], v, \"light_down\"\
    ), v = parent[v];\r\n      } else {\r\n        if (u != head[u]) up.eb(u, head[u],\
    \ \"heavy_up\"), u = head[u];\r\n        up.eb(u, parent[u], \"light_up\"), u\
    \ = parent[u];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(u, v, \"\
    heavy_down\");\r\n    elif (LID[v] < LID[u]) up.eb(u, v, \"heavy_up\");\r\n  \
    \  reverse(all(down));\r\n    concat(up, down);\r\n    return up;\r\n  }\r\n\r\
    \n  vc<int> restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a,\
    \ b]: get_path_decomposition(u, v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i,\
    \ a, b + 1) P.eb(V[i]);\r\n      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\
    \n      }\r\n    }\r\n    return P;\r\n  }\r\n\r\n  // path [a,b] \u3068 [c,d]\
    \ \u306E\u4EA4\u308F\u308A. \u7A7A\u306A\u3089\u3070 {-1,-1}.\r\n  // https://codeforces.com/problemset/problem/500/G\r\
    \n  pair<int, int> path_intersection(int a, int b, int c, int d) {\r\n    int\
    \ ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);\r\n    int bc = lca(b, c), bd\
    \ = lca(b, d), cd = lca(c, d);\r\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^ bd;\
    \ // meet(a,b,c), meet(a,b,d)\r\n    if (x != y) return {x, y};\r\n    int z =\
    \ ac ^ ad ^ cd;\r\n    if (x != z) x = -1;\r\n    return {x, x};\r\n  }\r\n\r\n\
    \  // uv path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\
    \ v\r\n  // \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C\
    \ ng \uFF09-1\r\n  template <class F>\r\n  int max_path(F check, int u, int v)\
    \ {\r\n    if (!check(u)) return -1;\r\n    auto pd = get_path_decomposition(u,\
    \ v, false);\r\n    for (auto [a, b]: pd) {\r\n      if (!check(V[a])) return\
    \ u;\r\n      if (check(V[b])) {\r\n        u = V[b];\r\n        continue;\r\n\
    \      }\r\n      int c = binary_search([&](int c) -> bool { return check(V[c]);\
    \ }, a, b, 0);\r\n      return V[c];\r\n    }\r\n    return u;\r\n  }\r\n};\r\n\
    #line 2 \"mod/modint61.hpp\"\n\r\nstruct modint61 {\r\n  static constexpr u64\
    \ mod = (1ULL << 61) - 1;\r\n  u64 val;\r\n  constexpr modint61() : val(0ULL)\
    \ {}\r\n  constexpr modint61(u32 x) : val(x) {}\r\n  constexpr modint61(u64 x)\
    \ : val(x % mod) {}\r\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\r\n  constexpr modint61(ll x) : val(((x %= static_cast<ll>(mod)) < 0)\
    \ ? (x + static_cast<ll>(mod)) : x) {}\r\n  static constexpr u64 get_mod() { return\
    \ mod; }\r\n\r\n  modint61 &operator+=(const modint61 &a) {\r\n    val = ((val\
    \ += a.val) >= mod) ? (val - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61\
    \ &operator-=(const modint61 &a) {\r\n    val = ((val -= a.val) >= mod) ? (val\
    \ + mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 &operator*=(const modint61\
    \ &a) {\r\n    const unsigned __int128 y = static_cast<unsigned __int128>(val)\
    \ * a.val;\r\n    val = (y >> 61) + (y & mod);\r\n    val = (val >= mod) ? (val\
    \ - mod) : val;\r\n    return *this;\r\n  }\r\n  modint61 operator-() const {\
    \ return modint61(val ? mod - val : u64(0)); }\r\n  modint61 &operator/=(const\
    \ modint61 &a) { return (*this *= a.inverse()); }\r\n  modint61 operator+(const\
    \ modint61 &p) const { return modint61(*this) += p; }\r\n  modint61 operator-(const\
    \ modint61 &p) const { return modint61(*this) -= p; }\r\n  modint61 operator*(const\
    \ modint61 &p) const { return modint61(*this) *= p; }\r\n  modint61 operator/(const\
    \ modint61 &p) const { return modint61(*this) /= p; }\r\n  bool operator<(const\
    \ modint61 &other) const { return val < other.val; }\r\n  bool operator==(const\
    \ modint61 &p) const { return val == p.val; }\r\n  bool operator!=(const modint61\
    \ &p) const { return val != p.val; }\r\n  modint61 inverse() const {\r\n    ll\
    \ a = val, b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\n      t = a / b;\r\
    \n      swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\n    return modint61(u);\r\
    \n  }\r\n  modint61 pow(ll n) const {\r\n    assert(n >= 0);\r\n    modint61 ret(1),\
    \ mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret *= mul;\r\n      mul\
    \ *= mul, n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\n};\r\n\r\n#ifdef FASTIO\r\
    \nvoid rd(modint61 &x) {\r\n  fastio::rd(x.val);\r\n  assert(0 <= x.val && x.val\
    \ < modint61::mod);\r\n}\r\n\r\nvoid wt(modint61 x) { fastio::wt(x.val); }\r\n\
    #endif\n#line 4 \"graph/ds/rolling_hash_on_tree.hpp\"\n\n// \u6728\u306E\u8FBA\
    \u306B\u6587\u5B57\u304C\u3061\u3087\u3046\u3069\u3072\u3068\u3064\u66F8\u3044\
    \u3066\u3042\u308B (static)\ntemplate <typename TREE, bool EDGE>\nstruct Rolling_Hash_On_Tree\
    \ {\n  using mint = modint61;\n\n  TREE& tree;\n  int N;\n  mint base;\n  // edge\
    \ \u306B\u6587\u5B57\u304C\u3042\u308B\u3068\u601D\u3063\u3066\n  // dp1: [root,v]\n\
    \  // dp2: [v,root]\n  vc<int> dat;\n  vc<mint> dp1, dp2;\n  vc<mint> pow, ipow;\n\
    \n  template <typename F>\n  Rolling_Hash_On_Tree(TREE& tree, F f, mint base_\
    \ = 0)\n      : tree(tree), N(tree.N), base(base_) {\n    if (base == mint(0))\
    \ base = RNG(mint::get_mod());\n    build(f);\n  }\n\n  template <typename F>\n\
    \  void build(F f) {\n    dat.resize(N);\n    if constexpr (EDGE) {\n      FOR(i,\
    \ N - 1) { dat[tree.e_to_v(i)] = f(i); }\n    } else {\n      FOR(i, N) { dat[i]\
    \ = f(i); }\n    }\n    pow.resize(N + 1), ipow.resize(N + 1);\n    pow[0] = 1,\
    \ pow[1] = base;\n    ipow[0] = 1, ipow[1] = base.inverse();\n    FOR(i, 2, N\
    \ + 1) pow[i] = pow[i - 1] * pow[1];\n    FOR(i, 2, N + 1) ipow[i] = ipow[i -\
    \ 1] * ipow[1];\n    int root = tree.V[0];\n    dp1.resize(N), dp2.resize(N);\n\
    \    dp1[root] = dp2[root] = dat[0];\n    FOR(i, 1, N) {\n      int v = tree.V[i];\n\
    \      int d = tree.depth[v], p = tree.parent[v];\n      dp1[v] = base * dp1[p]\
    \ + dat[v];\n      dp2[v] = dp2[p] + pow[d] * dat[v];\n    }\n  }\n\n  mint get(int\
    \ a, int b) {\n    int c = tree.lca(a, b);\n    mint x1 = get_du(a, c), x2 = get_ud(c,\
    \ b);\n    int n2 = tree.depth[b] - tree.depth[c];\n    if constexpr (!EDGE) {\
    \ x1 = x1 * base + dat[c]; }\n    return x1 * pow[n2] + x2;\n  }\n\n  int lcp(int\
    \ s1, int t1, int s2, int t2) {\n    return lcp_and_comp(s1, t1, s2, t2).fi;\n\
    \  }\n\n  // <=>\n  char comp(int s1, int t1, int s2, int t2) {\n    return lcp_and_comp(s1,\
    \ t1, s2, t2).se;\n  }\n\n  pair<int, char> lcp_and_comp(int s1, int t1, int s2,\
    \ int t2) {\n    int lcp = 0;\n    // heavy path \u306E\u9802\u70B9\u5217\n  \
    \  auto path1 = tree.get_path_decomposition(s1, t1, EDGE);\n    auto path2 = tree.get_path_decomposition(s2,\
    \ t2, EDGE);\n    reverse(all(path1));\n    reverse(all(path2));\n    while (len(path1)\
    \ && len(path2)) {\n      int a, b, c, d;\n      tie(a, b) = POP(path1), tie(c,\
    \ d) = POP(path2);\n      ll n1 = abs(a - b) + 1, n2 = abs(c - d) + 1;\n     \
    \ ll n = min(n1, n2);\n      if (n < n1) {\n        if (a <= b) { path1.eb(a +\
    \ n, b), b = a + n - 1; }\n        if (a > b) { path1.eb(a - n, b), b = a - n\
    \ + 1; }\n      }\n      if (n < n2) {\n        if (c <= d) { path2.eb(c + n,\
    \ d), d = c + n - 1; }\n        if (c > d) { path2.eb(c - n, d), d = c - n + 1;\
    \ }\n      }\n      mint x1 = from_hld_pair(a, b), x2 = from_hld_pair(c, d);\n\
    \      if (x1 == x2) {\n        lcp += n;\n        continue;\n      }\n      auto\
    \ check = [&](ll n) -> bool {\n        if (n == 0) return 1;\n        mint x1\
    \ = (a <= b ? from_hld_pair(a, a + n - 1)\n                          : from_hld_pair(a,\
    \ a - n + 1));\n        mint x2 = (c <= d ? from_hld_pair(c, c + n - 1)\n    \
    \                      : from_hld_pair(c, c - n + 1));\n        return x1 == x2;\n\
    \      };\n      ll k = binary_search(check, 0, n);\n      lcp += k;\n      a\
    \ = (a <= b ? a + k : a - k);\n      c = (c <= d ? c + k : c - k);\n      a =\
    \ tree.V[a], c = tree.V[c];\n      if (dat[a] < dat[c]) return {lcp, '<'};\n \
    \     if (dat[a] == dat[c]) return {lcp, '='};\n      if (dat[a] > dat[c]) return\
    \ {lcp, '>'};\n    }\n    if (!path1.empty()) return {lcp, '>'};\n    if (!path2.empty())\
    \ return {lcp, '<'};\n    return {lcp, '='};\n  }\n\nprivate:\n  mint get_ud(int\
    \ a, int b) {\n    return (a == -1 ? dp1[b]\n                    : dp1[b] - dp1[a]\
    \ * pow[tree.depth[b] - tree.depth[a]]);\n  }\n  mint get_du(int a, int b) {\n\
    \    return (b == -1 ? dp2[a] : (dp2[a] - dp2[b]) * ipow[tree.depth[b] + 1]);\n\
    \  }\n  mint from_hld_pair(int a, int b) {\n    if (a <= b) { return get_ud(tree.parent[tree.V[a]],\
    \ tree.V[b]); }\n    return get_du(tree.V[a], tree.parent[tree.V[b]]);\n  }\n\
    };\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename T>\nvoid shuffle(vc<T>&\
    \ A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n    if (i != j) swap(A[i],\
    \ A[j]);\n  }\n}\n#line 2 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n\
    \  int n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) {\
    \ build(n); }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n,\
    \ -1);\n  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n   \
    \ while (dat[x] >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return\
    \ dat[x]; }\n      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int\
    \ x) {\n    x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int\
    \ y) {\n    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n \
    \   if (-dat[x] < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n\
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
    }\n\n// |child| = 0 or 2 or (1 if can1), \u30E9\u30D9\u30EB\u306F\u30C8\u30DD\u30ED\
    \u30B8\u30AB\u30EB\n// return: par\nvc<int> random_binary_tree(int N, bool can_1)\
    \ {\n  if (can_1) {\n    vc<int> S;\n    S.eb(0), S.eb(0);\n    vc<int> par(N,\
    \ -1);\n    FOR(v, 1, N) {\n      int k = RNG(0, len(S));\n      swap(S[k], S.back());\n\
    \      par[v] = POP(S);\n      S.eb(v), S.eb(v);\n    }\n    return par;\n  }\n\
    \  // 0 or 2\n  assert(N % 2 == 1);\n  vc<int> par(N, -1);\n  vc<int> S;\n  FOR(v,\
    \ N / 2, N) S.eb(v);\n  int nxt = N / 2 - 1;\n  while (len(S) >= 2) {\n    shuffle(S);\n\
    \    int a = POP(S), b = POP(S);\n    par[a] = par[b] = nxt;\n    S.eb(nxt), --nxt;\n\
    \  }\n  return par;\n}\n#line 7 \"test/1_mytest/rolling_hash_on_tree.test.cpp\"\
    \n\nvoid test_edge() {\n  ll N = RNG(1, 20);\n  auto edges = random_tree(N);\n\
    \  Graph<int, 0> G(N);\n  for (auto& [a, b]: edges) {\n    int x = RNG(0, 3);\n\
    \    G.add(a, b, x);\n  }\n  G.build();\n  Tree<decltype(G)> tree(G);\n\n  using\
    \ mint = modint61;\n  mint base = RNG_64();\n\n  Rolling_Hash_On_Tree<decltype(tree),\
    \ true> RH(\n      tree, [&](int i) -> int { return G.edges[i].cost; }, base);\n\
    \n  vvv(int, dat, N, N, 0);\n  FOR(a, N) FOR(b, N) {\n    vc<int> P = tree.restore_path(a,\
    \ b);\n    vc<int> S;\n    FOR(i, len(P) - 1) {\n      int eid = tree.get_eid(P[i],\
    \ P[i + 1]);\n      S.eb(G.edges[eid].cost);\n    }\n    dat[a][b] = S;\n  }\n\
    \n  FOR(a, N) FOR(b, N) {\n    mint h = 0;\n    for (auto& x: dat[a][b]) { h =\
    \ h * base + x; }\n    assert(h == RH.get(a, b));\n  }\n  FOR(a, N) FOR(b, N)\
    \ FOR(c, N) FOR(d, N) {\n    vc<int> A = dat[a][b], B = dat[c][d];\n    int lcp\
    \ = 0;\n    while (lcp < len(A) && lcp < len(B) && A[lcp] == B[lcp]) ++lcp;\n\
    \    auto [k, ch] = RH.lcp_and_comp(a, b, c, d);\n    assert(k == lcp);\n    if\
    \ (ch == '<') assert(A < B);\n    if (ch == '=') assert(A == B);\n    if (ch ==\
    \ '>') assert(A > B);\n  }\n}\n\nvoid test_vertex() {\n  ll N = RNG(1, 20);\n\
    \  auto edges = random_tree(N);\n  Graph<int, 0> G(N);\n  for (auto& [a, b]: edges)\
    \ { G.add(a, b); }\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(0, 3);\n  G.build();\n\
    \  Tree<decltype(G)> tree(G);\n\n  using mint = modint61;\n  mint base = RNG_64();\n\
    \n  Rolling_Hash_On_Tree<decltype(tree), false> RH(\n      tree, [&](int i) ->\
    \ int { return A[i]; }, base);\n\n  vvv(int, dat, N, N, 0);\n  FOR(a, N) FOR(b,\
    \ N) {\n    vc<int> P = tree.restore_path(a, b);\n    vc<int> S;\n    for (auto&\
    \ v: P) S.eb(A[v]);\n    dat[a][b] = S;\n  }\n\n  FOR(a, N) FOR(b, N) {\n    mint\
    \ h = 0;\n    for (auto& x: dat[a][b]) { h = h * base + x; }\n    assert(h ==\
    \ RH.get(a, b));\n  }\n\n  FOR(a, N) FOR(b, N) FOR(c, N) FOR(d, N) {\n    vc<int>\
    \ A = dat[a][b], B = dat[c][d];\n    int lcp = 0;\n    while (lcp < len(A) &&\
    \ lcp < len(B) && A[lcp] == B[lcp]) ++lcp;\n    auto [k, ch] = RH.lcp_and_comp(a,\
    \ b, c, d);\n    assert(k == lcp);\n    if (ch == '<') assert(A < B);\n    if\
    \ (ch == '=') assert(A == B);\n    if (ch == '>') assert(A > B);\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  FOR(300) test_edge();\n  FOR(300) test_vertex();\n  solve();\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n\n#include \"graph/ds/rolling_hash_on_tree.hpp\"\n#include\
    \ \"random/random_graph.hpp\"\n\nvoid test_edge() {\n  ll N = RNG(1, 20);\n  auto\
    \ edges = random_tree(N);\n  Graph<int, 0> G(N);\n  for (auto& [a, b]: edges)\
    \ {\n    int x = RNG(0, 3);\n    G.add(a, b, x);\n  }\n  G.build();\n  Tree<decltype(G)>\
    \ tree(G);\n\n  using mint = modint61;\n  mint base = RNG_64();\n\n  Rolling_Hash_On_Tree<decltype(tree),\
    \ true> RH(\n      tree, [&](int i) -> int { return G.edges[i].cost; }, base);\n\
    \n  vvv(int, dat, N, N, 0);\n  FOR(a, N) FOR(b, N) {\n    vc<int> P = tree.restore_path(a,\
    \ b);\n    vc<int> S;\n    FOR(i, len(P) - 1) {\n      int eid = tree.get_eid(P[i],\
    \ P[i + 1]);\n      S.eb(G.edges[eid].cost);\n    }\n    dat[a][b] = S;\n  }\n\
    \n  FOR(a, N) FOR(b, N) {\n    mint h = 0;\n    for (auto& x: dat[a][b]) { h =\
    \ h * base + x; }\n    assert(h == RH.get(a, b));\n  }\n  FOR(a, N) FOR(b, N)\
    \ FOR(c, N) FOR(d, N) {\n    vc<int> A = dat[a][b], B = dat[c][d];\n    int lcp\
    \ = 0;\n    while (lcp < len(A) && lcp < len(B) && A[lcp] == B[lcp]) ++lcp;\n\
    \    auto [k, ch] = RH.lcp_and_comp(a, b, c, d);\n    assert(k == lcp);\n    if\
    \ (ch == '<') assert(A < B);\n    if (ch == '=') assert(A == B);\n    if (ch ==\
    \ '>') assert(A > B);\n  }\n}\n\nvoid test_vertex() {\n  ll N = RNG(1, 20);\n\
    \  auto edges = random_tree(N);\n  Graph<int, 0> G(N);\n  for (auto& [a, b]: edges)\
    \ { G.add(a, b); }\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(0, 3);\n  G.build();\n\
    \  Tree<decltype(G)> tree(G);\n\n  using mint = modint61;\n  mint base = RNG_64();\n\
    \n  Rolling_Hash_On_Tree<decltype(tree), false> RH(\n      tree, [&](int i) ->\
    \ int { return A[i]; }, base);\n\n  vvv(int, dat, N, N, 0);\n  FOR(a, N) FOR(b,\
    \ N) {\n    vc<int> P = tree.restore_path(a, b);\n    vc<int> S;\n    for (auto&\
    \ v: P) S.eb(A[v]);\n    dat[a][b] = S;\n  }\n\n  FOR(a, N) FOR(b, N) {\n    mint\
    \ h = 0;\n    for (auto& x: dat[a][b]) { h = h * base + x; }\n    assert(h ==\
    \ RH.get(a, b));\n  }\n\n  FOR(a, N) FOR(b, N) FOR(c, N) FOR(d, N) {\n    vc<int>\
    \ A = dat[a][b], B = dat[c][d];\n    int lcp = 0;\n    while (lcp < len(A) &&\
    \ lcp < len(B) && A[lcp] == B[lcp]) ++lcp;\n    auto [k, ch] = RH.lcp_and_comp(a,\
    \ b, c, d);\n    assert(k == lcp);\n    if (ch == '<') assert(A < B);\n    if\
    \ (ch == '=') assert(A == B);\n    if (ch == '>') assert(A > B);\n  }\n}\n\nvoid\
    \ solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\n\
    signed main() {\n  FOR(300) test_edge();\n  FOR(300) test_vertex();\n  solve();\n\
    }\n"
  dependsOn:
  - my_template.hpp
  - graph/ds/rolling_hash_on_tree.hpp
  - random/base.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - mod/modint61.hpp
  - random/random_graph.hpp
  - random/shuffle.hpp
  - ds/unionfind/unionfind.hpp
  isVerificationFile: true
  path: test/1_mytest/rolling_hash_on_tree.test.cpp
  requiredBy: []
  timestamp: '2025-07-03 18:22:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/rolling_hash_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/rolling_hash_on_tree.test.cpp
- /verify/test/1_mytest/rolling_hash_on_tree.test.cpp.html
title: test/1_mytest/rolling_hash_on_tree.test.cpp
---
