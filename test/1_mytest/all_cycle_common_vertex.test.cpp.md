---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: graph/all_cycle_common_vertex.hpp
    title: graph/all_cycle_common_vertex.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/find_cycle.hpp
    title: graph/find_cycle.hpp
  - icon: ':question:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  - icon: ':question:'
    path: graph/toposort.hpp
    title: graph/toposort.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16\
    \ = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = numeric_limits<double>::infinity();\n\
    template <>\nconstexpr long double infty<long double> =\n    numeric_limits<long\
    \ double>::infinity();\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing pq_max = priority_queue<T>;\n\
    template <class T>\nusing pq_min = priority_queue<T, vector<T>, greater<T>>;\n\
    \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
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
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    UINT operator*() const { return s ^ t; }\n    iter &operator++() {\n    \
    \  (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool\
    \ operator!=(const iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  iter begin() const { return iter(s); }\n  iter end() const {\
    \ return iter(0); }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return\
    \ a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y)\
    \ {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y)\
    \ {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nconstexpr ll\
    \ TEN[] = {\n    1LL,\n    10LL,\n    100LL,\n    1000LL,\n    10000LL,\n    100000LL,\n\
    \    1000000LL,\n    10000000LL,\n    100000000LL,\n    1000000000LL,\n    10000000000LL,\n\
    \    100000000000LL,\n    1000000000000LL,\n    10000000000000LL,\n    100000000000000LL,\n\
    \    1000000000000000LL,\n    10000000000000000LL,\n    100000000000000000LL,\n\
    \    1000000000000000000LL,\n};\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n\
    \  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return\
    \ A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 2 \"test/1_mytest/all_cycle_common_vertex.test.cpp\"\
    \n// #include \"other/io.hpp\"\n\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\
    \ntemplate <typename Val>\r\nstruct HashMap {\r\n  // n \u306F\u5165\u308C\u305F\
    \u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\r\n  HashMap(u32 n = 0) { build(n);\
    \ }\r\n  void build(u32 n) {\r\n    u32 k = 8;\r\n    while (k < n * 2) k *= 2;\r\
    \n    cap = k / 2, mask = k - 1;\r\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\r\n  }\r\n\r\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\
    \u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\r\n  void clear()\
    \ {\r\n    used.assign(len(used), 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n\
    \  int size() { return len(used) / 2 - cap; }\r\n\r\n  int index(const u64& k)\
    \ {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k; i = (i\
    \ + 1) & mask) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const u64&\
    \ k) {\r\n    if (cap == 0) extend();\r\n    int i = index(k);\r\n    if (!used[i])\
    \ { used[i] = 1, key[i] = k, val[i] = Val{}, --cap; }\r\n    return val[i];\r\n\
    \  }\r\n\r\n  Val get(const u64& k, Val default_value) {\r\n    int i = index(k);\r\
    \n    return (used[i] ? val[i] : default_value);\r\n  }\r\n\r\n  bool count(const\
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
    #line 3 \"graph/strongly_connected_component.hpp\"\n\ntemplate <typename GT>\n\
    pair<int, vc<int>> strongly_connected_component(GT& G) {\n  static_assert(GT::is_directed);\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  int C = 0;\n  vc<int> comp(N),\
    \ low(N), ord(N, -1), path;\n  int now = 0;\n\n  auto dfs = [&](auto& dfs, int\
    \ v) -> void {\n    low[v] = ord[v] = now++;\n    path.eb(v);\n    for (auto&&\
    \ [frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n        dfs(dfs, to),\
    \ chmin(low[v], low[to]);\n      } else {\n        chmin(low[v], ord[to]);\n \
    \     }\n    }\n    if (low[v] == ord[v]) {\n      while (1) {\n        int u\
    \ = POP(path);\n        ord[u] = N, comp[u] = C;\n        if (u == v) break;\n\
    \      }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs,\
    \ v);\n  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n  return {C, comp};\n}\n\n\
    template <typename GT>\nGraph<int, 1> scc_dag(GT& G, int C, vc<int>& comp) {\n\
    \  Graph<int, 1> DAG(C);\n  vvc<int> edges(C);\n  for (auto&& e: G.edges) {\n\
    \    int x = comp[e.frm], y = comp[e.to];\n    if (x == y) continue;\n    edges[x].eb(y);\n\
    \  }\n  FOR(c, C) {\n    UNIQUE(edges[c]);\n    for (auto&& to: edges[c]) DAG.add(c,\
    \ to);\n  }\n  DAG.build();\n  return DAG;\n}\n#line 2 \"ds/fastset.hpp\"\n\r\n\
    // 64-ary tree\r\n// space: (N/63) * u64\r\nstruct FastSet {\r\n  static constexpr\
    \ u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\n\r\n  FastSet() {}\r\n  FastSet(int\
    \ n) { build(n); }\r\n\r\n  int size() { return n; }\r\n\r\n  template <typename\
    \ F>\r\n  FastSet(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  void build(int\
    \ m) {\r\n    seg.clear();\r\n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\r\n      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n  \
    \  log = len(seg);\r\n  }\r\n  template <typename F>\r\n  void build(int n, F\
    \ f) {\r\n    build(n);\r\n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i %\
    \ B); }\r\n    FOR(h, log - 1) {\r\n      FOR(i, len(seg[h])) {\r\n        seg[h\
    \ + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\r\n      }\r\n    }\r\n  }\r\
    \n\r\n  bool operator[](int i) const { return seg[0][i / B] >> (i % B) & 1; }\r\
    \n  void insert(int i) {\r\n    assert(0 <= i && i < n);\r\n    for (int h = 0;\
    \ h < log; h++) {\r\n      seg[h][i / B] |= u64(1) << (i % B), i /= B;\r\n   \
    \ }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int i) {\r\n  \
    \  assert(0 <= i && i < n);\r\n    u64 x = 0;\r\n    for (int h = 0; h < log;\
    \ h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i / B]\
    \ |= x << (i % B);\r\n      x = bool(seg[h][i / B]);\r\n      i /= B;\r\n    }\r\
    \n  }\r\n  void remove(int i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\n  int\
    \ next(int i) {\r\n    assert(i <= n);\r\n    chmax(i, 0);\r\n    for (int h =\
    \ 0; h < log; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      u64\
    \ d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\
    \n        continue;\r\n      }\r\n      i += lowbit(d);\r\n      for (int g =\
    \ h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += lowbit(seg[g][i / B]);\r\
    \n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n  // max\
    \ [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i >= -1);\r\n    if (i >=\
    \ n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\n      if (i == -1) break;\r\
    \n      u64 d = seg[h][i / B] << (63 - i % B);\r\n      if (!d) {\r\n        i\
    \ = i / B - 1;\r\n        continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ topbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return next(l) < r; }\r\n\r\n \
    \ // [l, r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f)\
    \ {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n\
    \  void reset() {\r\n    enumerate(0, n, [&](int i) -> void { erase(i); });\r\n\
    \  }\r\n\r\n  string to_string() {\r\n    string s(n, '?');\r\n    for (int i\
    \ = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n\
    };\n#line 3 \"graph/toposort.hpp\"\n\n// \u8F9E\u66F8\u9806\u6700\u5C0F\u306E\
    \ toposort \u3092\u8FD4\u3059\ntemplate <typename GT>\nvc<int> toposort(GT& G)\
    \ {\n  static_assert(GT::is_directed);\n  assert(G.is_prepared());\n  const int\
    \ N = G.N;\n  auto [indeg, outdeg] = G.deg_array_inout();\n  FastSet que(N);\n\
    \  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n  while (1) {\n\
    \    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v), V.eb(v);\n\
    \    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n\n// inv_perm=true: inv\
    \ perm \u304C\u8F9E\u66F8\u6700\u5C0F\uFF08\u5404\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u306E\u73FE\u308C\u308B\u5834\u6240\u306E\u5217\u304C\u6700\u5C0F\uFF09\
    \ntemplate <typename GT>\nvc<int> lex_min_toposort(GT& G, bool inv_perm = false)\
    \ {\n  static_assert(GT::is_directed);\n  assert(G.is_prepared());\n  const int\
    \ N = G.N;\n  if (inv_perm) {\n    GT H(N);\n    for (auto& e: G.edges) H.add(N\
    \ - 1 - e.to, N - 1 - e.frm);\n    H.build();\n    auto V = lex_min_toposort(H,\
    \ false);\n    reverse(all(V));\n    for (auto& x: V) x = N - 1 - x;\n    return\
    \ V;\n  }\n  auto [indeg, outdeg] = G.deg_array_inout();\n  FastSet que(N);\n\
    \  vc<int> V;\n  FOR(v, N) if (indeg[v] == 0) que.insert(v);\n  while (1) {\n\
    \    int v = que.next(0);\n    if (v == N) break;\n    que.erase(v), V.eb(v);\n\
    \    for (auto&& e: G[v]) {\n      if (--indeg[e.to] == 0) que.insert(e.to);\n\
    \    }\n  }\n  return (len(V) < N ? vc<int>{} : V);\n}\n#line 2 \"graph/find_cycle.hpp\"\
    \n\r\n// {vs, es} or empty. minimal.\r\ntemplate <typename GT>\r\npair<vc<int>,\
    \ vc<int>> find_cycle_directed(GT& G) {\r\n  static_assert(GT::is_directed);\r\
    \n  assert(G.is_prepared());\r\n\r\n  int N = G.N;\r\n  vc<int> used(N);\r\n \
    \ vc<pair<int, int>> par(N);\r\n  vector<int> es, vs;\r\n\r\n  auto dfs = [&](auto\
    \ self, int v) -> void {\r\n    used[v] = 1;\r\n    for (auto&& e: G[v]) {\r\n\
    \      if (len(es)) return;\r\n      if (!used[e.to]) {\r\n        par[e.to] =\
    \ {v, e.id};\r\n        self(self, e.to);\r\n      }\r\n      elif (used[e.to]\
    \ == 1) {\r\n        es = {e.id};\r\n        int cur = v;\r\n        while (cur\
    \ != e.to) {\r\n          es.eb(par[cur].se);\r\n          cur = par[cur].fi;\r\
    \n        }\r\n        reverse(all(es));\r\n        return;\r\n      }\r\n   \
    \ }\r\n    used[v] = 2;\r\n  };\r\n  FOR(v, N) if (!used[v]) dfs(dfs, v);\r\n\
    \  if (es.empty()) return {vs, es};\r\n\r\n  // minimal cycle\r\n  vc<int> nxt(N,\
    \ -1);\r\n  for (auto&& eid: es) nxt[G.edges[eid].frm] = eid;\r\n\r\n  for (auto&&\
    \ e: G.edges) {\r\n    int a = e.frm, b = e.to;\r\n    if (nxt[a] == -1 || nxt[b]\
    \ == -1) continue;\r\n    if (G.edges[nxt[a]].to == e.to) continue;\r\n    while\
    \ (a != b) {\r\n      int t = G.edges[nxt[a]].to;\r\n      nxt[a] = -1;\r\n  \
    \    a = t;\r\n    }\r\n    nxt[e.frm] = e.id;\r\n  }\r\n  es.clear();\r\n  FOR(v,\
    \ N) {\r\n    if (nxt[v] == -1) continue;\r\n    int x = v;\r\n    while (1) {\r\
    \n      vs.eb(x);\r\n      es.eb(nxt[x]);\r\n      x = G.edges[nxt[x]].to;\r\n\
    \      if (x == v) break;\r\n    }\r\n    break;\r\n  }\r\n  return {vs, es};\r\
    \n}\r\n\r\n// {vs, es} or empty. minimal.\r\ntemplate <typename GT>\r\npair<vc<int>,\
    \ vc<int>> find_cycle_undirected(GT& G) {\r\n  assert(!GT::is_directed);\r\n \
    \ assert(G.is_prepared());\r\n  const int N = G.N;\r\n  const int M = G.M;\r\n\
    \  vc<int> dep(N, -1);\r\n  vc<bool> used_e(M);\r\n  vc<int> par(N, -1); // edge\
    \ idx\r\n\r\n  auto dfs = [&](auto& dfs, int v, int d) -> void {\r\n    dep[v]\
    \ = d;\r\n    for (auto&& e: G[v]) {\r\n      if (dep[e.to] != -1) continue;\r\
    \n      used_e[e.id] = 1;\r\n      par[e.to] = e.id;\r\n      dfs(dfs, e.to, d\
    \ + 1);\r\n    }\r\n  };\r\n\r\n  vc<int> vs, es;\r\n  FOR(v, N) {\r\n    if (dep[v]\
    \ == -1) dfs(dfs, v, 0);\r\n  }\r\n  int mi_len = infty<int>;\r\n  int back_e\
    \ = -1;\r\n  for (auto& e: G.edges) {\r\n    if (used_e[e.id]) continue;\r\n \
    \   int d = abs(dep[e.frm] - dep[e.to]);\r\n    if (chmin(mi_len, d)) back_e =\
    \ e.id;\r\n  }\r\n  if (back_e == -1) return {vs, es};\r\n  int a = G.edges[back_e].frm,\
    \ b = G.edges[back_e].to;\r\n  if (dep[a] > dep[b]) swap(a, b);\r\n  es.eb(back_e),\
    \ vs.eb(a);\r\n  while (1) {\r\n    int x = vs.back();\r\n    auto& e = G.edges[es.back()];\r\
    \n    int y = e.frm + e.to - x;\r\n    if (y == a) break;\r\n    vs.eb(y);\r\n\
    \    es.eb(par[y]);\r\n  }\r\n  return {vs, es};\r\n}\r\n#line 4 \"graph/all_cycle_common_vertex.hpp\"\
    \n\n// v \u3092\u901A\u308B\u30B5\u30A4\u30AF\u30EB\u304C\u5B58\u5728\u3057, v\
    \ \u3092\u6D88\u3059\u3068 DAG \u306B\u306A\u308B\u3088\u3046\u306A v \u3092\u6607\
    \u9806\u5168\u5217\u6319\u3059\u308B\n// v \u3092\u6D88\u3059\u3068 \u975EDAG\
    \ -> DAG\n// loop \u306F\u306A\u3044\u3082\u306E\u3068\u3057\u305F\u304B\u3082\
    \n// https://codeforces.com/contest/982/problem/F\ntemplate <typename GT>\nvc<int>\
    \ all_cycle_common_vertex(GT& G, bool strongly_connected) {\n  static_assert(G.is_directed);\n\
    \  int N = G.N;\n  if (!strongly_connected) {\n    auto [nc, comp] = strongly_connected_component(G);\n\
    \    vc<int> sz(nc);\n    FOR(v, N) sz[comp[v]]++;\n    int k = -1;\n    FOR(i,\
    \ nc) {\n      if (sz[i] >= 2) {\n        if (k != -1) return {};\n        k =\
    \ i;\n      }\n    }\n    if (k == -1) return {};  // DAG\n    vc<int> V;\n  \
    \  FOR(v, N) if (comp[v] == k) V.eb(v);\n    Graph<int, 1> H = G.rearrange(V);\n\
    \    vc<int> ANS = all_cycle_common_vertex(H, true);\n    for (int& x : ANS) x\
    \ = V[x];\n    return ANS;\n  }\n\n  assert(strongly_connected);\n  if (N == 1)\
    \ return {};  // DAG\n\n  // main cycle\n  vc<int> C = find_cycle_directed(G).fi;\n\
    \n  int n = len(C);\n  vc<int> idx(N, -1);\n  FOR(i, n) idx[C[i]] = i;\n\n  vc<int>\
    \ other;\n  FOR(i, N) if (idx[i] == -1) other.eb(i);\n  if (len(other)) {\n  \
    \  Graph<int, 1> H = G.rearrange(other);\n    if (toposort(H).empty()) return\
    \ {};  // two vertex disjoint cycle\n  }\n\n  vc<int> F(N + 1);\n  auto arc =\
    \ [&](int s, int t) -> void {\n    if (s < t) {\n      F[s + 1]++, F[t]--;\n \
    \   } else {\n      F[s + 1]++, F[n]--;\n      F[0]++, F[t]--;\n    }\n  };\n\n\
    \  vc<int> dp(N, -2);\n\n  FOR(s, n) {\n    auto eval = [&](int i) -> int {\n\
    \      if (i < 0) return i;\n      return (s < i ? i - s : i + n - s);\n    };\n\
    \n    auto dfs = [&](auto& dfs, int v) -> int {\n      if (idx[v] != -1) return\
    \ idx[v];\n      if (dp[v] != -2) return dp[v];\n      int ans = -1;\n      for\
    \ (auto& e : G[v]) {\n        int i = dfs(dfs, e.to);\n        if (eval(ans) <\
    \ eval(i)) ans = i;\n      }\n      return dp[v] = ans;\n    };\n    int i = -1;\n\
    \    for (auto& e : G[C[s]]) {\n      int j = dfs(dfs, e.to);\n      if (eval(i)\
    \ < eval(j)) i = j;\n    }\n    if (i != -1) arc(s, i);\n  }\n  FOR(i, n) F[i\
    \ + 1] += F[i];\n  F.pop_back();\n\n  vc<int> ANS;\n  FOR(i, n) if (F[i] == 0)\
    \ ANS.eb(C[i]);\n\n  if (ANS.empty()) return {};\n  vc<int> V;\n  FOR(v, N) if\
    \ (v != ANS[0]) V.eb(v);\n  {\n    Graph<int, 1> H = G.rearrange(V);\n    if (toposort(H).empty())\
    \ return {};\n  }\n  return ANS;\n}\n#line 6 \"test/1_mytest/all_cycle_common_vertex.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 8 \"test/1_mytest/all_cycle_common_vertex.test.cpp\"\
    \n\nvc<int> naive(Graph<int, 1> G) {\n  int N = G.N;\n  vc<int> ANS;\n  auto dag\
    \ = [&](vc<int> V) -> bool {\n    Graph<int, 1> H = G.rearrange(V);\n    return\
    \ V.empty() || (!toposort(H).empty());\n  };\n  vc<int> V;\n  FOR(i, N) V.eb(i);\n\
    \  if (dag(V)) return {};\n  FOR(v, N) {\n    V.erase(find(all(V), v));\n    if\
    \ (dag(V)) ANS.eb(v);\n    V.eb(v);\n  }\n  return ANS;\n}\n\nvoid test() {\n\
    \  FOR(1 << 18) {\n    int N = RNG(1, 4);\n    Graph<int, 1> G(N);\n    int prob\
    \ = RNG(0, 100);\n    FOR(a, N) FOR(b, N) {\n      if (a == b) continue;\n   \
    \   if (RNG(0, 100) < prob) G.add(a, b);\n    }\n    G.build();\n    auto ANS1\
    \ = all_cycle_common_vertex(G, 0);\n    auto ANS2 = naive(G);\n    sort(all(ANS1));\n\
    \    sort(all(ANS2));\n    // G.debug();\n    // SHOW(ANS1, ANS2);\n    assert(ANS1\
    \ == ANS2);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout <<\
    \ a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n}\n"
  code: "#include \"my_template.hpp\"\n// #include \"other/io.hpp\"\n\n#include \"\
    graph/base.hpp\"\n#include \"graph/all_cycle_common_vertex.hpp\"\n\n#include \"\
    random/base.hpp\"\n\nvc<int> naive(Graph<int, 1> G) {\n  int N = G.N;\n  vc<int>\
    \ ANS;\n  auto dag = [&](vc<int> V) -> bool {\n    Graph<int, 1> H = G.rearrange(V);\n\
    \    return V.empty() || (!toposort(H).empty());\n  };\n  vc<int> V;\n  FOR(i,\
    \ N) V.eb(i);\n  if (dag(V)) return {};\n  FOR(v, N) {\n    V.erase(find(all(V),\
    \ v));\n    if (dag(V)) ANS.eb(v);\n    V.eb(v);\n  }\n  return ANS;\n}\n\nvoid\
    \ test() {\n  FOR(1 << 18) {\n    int N = RNG(1, 4);\n    Graph<int, 1> G(N);\n\
    \    int prob = RNG(0, 100);\n    FOR(a, N) FOR(b, N) {\n      if (a == b) continue;\n\
    \      if (RNG(0, 100) < prob) G.add(a, b);\n    }\n    G.build();\n    auto ANS1\
    \ = all_cycle_common_vertex(G, 0);\n    auto ANS2 = naive(G);\n    sort(all(ANS1));\n\
    \    sort(all(ANS2));\n    // G.debug();\n    // SHOW(ANS1, ANS2);\n    assert(ANS1\
    \ == ANS2);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout <<\
    \ a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n}\n"
  dependsOn:
  - my_template.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/all_cycle_common_vertex.hpp
  - graph/strongly_connected_component.hpp
  - graph/toposort.hpp
  - ds/fastset.hpp
  - graph/find_cycle.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/all_cycle_common_vertex.test.cpp
  requiredBy: []
  timestamp: '2026-02-03 22:59:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/all_cycle_common_vertex.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/all_cycle_common_vertex.test.cpp
- /verify/test/1_mytest/all_cycle_common_vertex.test.cpp.html
title: test/1_mytest/all_cycle_common_vertex.test.cpp
---
