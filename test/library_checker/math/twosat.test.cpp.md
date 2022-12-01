---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  - icon: ':x:'
    path: graph/twosat.hpp
    title: graph/twosat.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/library_checker/math/twosat.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/two_sat\"\r\n#line 1 \"my_template.hpp\"\n\
    #pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing pi =\
    \ pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\nusing u64\
    \ = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\nusing vc\
    \ = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define FOR4_R(i,\
    \ a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))\n#define overload4(a, b, c,\
    \ d, e, ...) e\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) \\\n  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) &\
    \ s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const vector<U> &A) {\n  T sum = 0;\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x ==\
    \ 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\n\
    int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x\
    \ == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT pick(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\n\ntemplate <typename\
    \ T>\nT pick(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    \ntemplate <typename T>\nT pick(pqg<T> &que) {\n  assert(que.size());\n  T a =\
    \ que.top();\n  que.pop();\n  return a;\n}\n\ntemplate <typename T>\nT pick(vc<T>\
    \ &que) {\n  assert(que.size());\n  T a = que.back();\n  que.pop_back();\n  return\
    \ a;\n}\n\ntemplate <typename T, typename U>\nT ceil(T x, U y) {\n  return (x\
    \ > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename T, typename U>\nT floor(T\
    \ x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, T> divmod(T x, U y) {\n  T q = floor(x, y);\n  return\
    \ {q, x - q * y};\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok,\
    \ ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng\
    \ + ok) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return\
    \ ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F check, double ok,\
    \ double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n\
    \    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return (ok + ng)\
    \ / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b)\
    \ {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate <typename\
    \ T, typename U>\nvector<T> cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\n// stable\ntemplate <typename T>\nvector<int>\
    \ argsort(const vector<T> &A) {\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i]\
    \ == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  int n =\
    \ len(I);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n  return B;\n}\n#line 1\
    \ \"other/io.hpp\"\nnamespace fastio { // https://nyaannyaan.github.io/library/misc/fastio.hpp\r\
    \nstatic constexpr int SZ = 1 << 17;\r\nchar inbuf[SZ], outbuf[SZ];\r\nint in_left\
    \ = 0, in_right = 0, out_right = 0;\r\n\r\nstruct Pre {\r\n  char num[40000];\r\
    \n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n   \
    \   int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n        num[i * 4 +\
    \ j] = n % 10 + '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr\
    \ pre;\r\n\r\ninline void load() {\r\n  int len = in_right - in_left;\r\n  memmove(inbuf,\
    \ inbuf + in_left, len);\r\n  in_right = len + fread(inbuf + len, 1, SZ - len,\
    \ stdin);\r\n  in_left = 0;\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(outbuf,\
    \ 1, out_right, stdout);\r\n  out_right = 0;\r\n}\r\n\r\ninline void skip_space()\
    \ {\r\n  if (in_left + 32 > in_right) load();\r\n  while (inbuf[in_left] <= '\
    \ ') in_left++;\r\n}\r\n\r\ninline void read(char &c) {\r\n  if (in_left + 32\
    \ > in_right) load();\r\n  c = inbuf[in_left++];\r\n}\r\ntemplate <typename T>\r\
    \ninline void read(T &x) {\r\n  if (in_left + 32 > in_right) load();\r\n  char\
    \ c;\r\n  do\r\n    c = inbuf[in_left++];\r\n  while (c < '-');\r\n  [[maybe_unused]]\
    \ bool minus = false;\r\n  if constexpr (is_signed<T>::value == true) {\r\n  \
    \  if (c == '-') minus = true, c = inbuf[in_left++];\r\n  }\r\n  x = 0;\r\n  while\
    \ (c >= '0') {\r\n    x = x * 10 + (c & 15);\r\n    c = inbuf[in_left++];\r\n\
    \  }\r\n  if constexpr (is_signed<T>::value == true) {\r\n    if (minus) x = -x;\r\
    \n  }\r\n}\r\ninline void read() {}\r\ntemplate <typename Head, typename... Tail>\r\
    \ninline void read(Head &head, Tail &... tail) {\r\n  read(head);\r\n  read(tail...);\r\
    \n}\r\n\r\ninline void write(char c) {\r\n  if (out_right > SZ - 32) flush();\r\
    \n  outbuf[out_right++] = c;\r\n}\r\ninline void write(bool b) {\r\n  if (out_right\
    \ > SZ - 32) flush();\r\n  outbuf[out_right++] = b ? '1' : '0';\r\n}\r\ninline\
    \ void write(const string &s) {\r\n  if (out_right + s.size() > SZ - 32) flush();\r\
    \n  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\r\n  out_right\
    \ += s.size();\r\n}\r\ntemplate <typename T>\r\ninline void write(T x) {\r\n \
    \ if (out_right > SZ - 32) flush();\r\n  if (!x) {\r\n    outbuf[out_right++]\
    \ = '0';\r\n    return;\r\n  }\r\n  if constexpr (is_signed<T>::value == true)\
    \ {\r\n    if (x < 0) outbuf[out_right++] = '-', x = -x;\r\n  }\r\n  int i = 12;\r\
    \n  char buf[16];\r\n  while (x >= 10000) {\r\n    memcpy(buf + i, pre.num + (x\
    \ % 10000) * 4, 4);\r\n    x /= 10000;\r\n    i -= 4;\r\n  }\r\n  if (x < 100)\
    \ {\r\n    if (x < 10) {\r\n      outbuf[out_right] = '0' + x;\r\n      ++out_right;\r\
    \n    } else {\r\n      uint32_t q = (uint32_t(x) * 205) >> 11;\r\n      uint32_t\
    \ r = uint32_t(x) - q * 10;\r\n      outbuf[out_right] = '0' + q;\r\n      outbuf[out_right\
    \ + 1] = '0' + r;\r\n      out_right += 2;\r\n    }\r\n  } else {\r\n    if (x\
    \ < 1000) {\r\n      memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);\r\n\
    \      out_right += 3;\r\n    } else {\r\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2), 4);\r\n      out_right += 4;\r\n    }\r\n  }\r\n  memcpy(outbuf\
    \ + out_right, buf + i + 4, 12 - i);\r\n  out_right += 12 - i;\r\n}\r\ninline\
    \ void write() {}\r\ntemplate <typename Head, typename... Tail>\r\ninline void\
    \ write(Head &&head, Tail &&... tail) {\r\n  write(head);\r\n  write(forward<Tail>(tail)...);\r\
    \n}\r\ntemplate <typename... Args>\r\ninline void writen(Args &&... x) {\r\n \
    \ write(forward<Args>(x)...);\r\n  write('\\n');\r\n}\r\n\r\nstruct Dummy {\r\n\
    \  Dummy() { atexit(flush); }\r\n} dummy;\r\n} // namespace fastio\r\n\r\nvoid\
    \ print() { fastio::write('\\n'); }\r\ntemplate <class Head, class... Tail>\r\n\
    void print(Head &&head, Tail &&... tail) {\r\n  fastio::write(head);\r\n  if (sizeof...(Tail))\
    \ fastio::write(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head &head, Tail &...\
    \ tail) {\r\n  fastio::read(head);\r\n  read(tail...);\r\n}\r\n\r\n#define INT(...)\
    \   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\
    \r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n\
    \  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)   \\\r\n\
    \  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n\
    \  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name,\
    \ size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type,\
    \ name, h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print<string>(t ? \"YES\" :\
    \ \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print<string>(t\
    \ ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool\
    \ t = 1) { print<string>(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t);\
    \ }\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void resize(int n) { N = n; }\n\n  void add(int frm, int to, T cost\
    \ = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to &&\
    \ to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n\
    \    edges.eb(e);\n    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n\n  void read_parent(int off = 1) {\n    for (int v\
    \ = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n      add(p, v);\n    }\n\
    \    build();\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared =\
    \ true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm\
    \ + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0;\
    \ v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto counter = indptr;\n  \
    \  csr_edges.resize(indptr.back() + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++]\
    \ = e;\n      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to,\
    \ e.frm, e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const\
    \ {\n    assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\
    \n  vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\nprivate:\n  void calc_deg()\
    \ {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 3 \"graph/strongly_connected_component.hpp\"\
    \n\ntemplate <typename Graph>\npair<int, vc<int>> strongly_connected_component(Graph&\
    \ G) {\n  assert(G.is_directed());\n  assert(G.is_prepared());\n  int N = G.N;\n\
    \  int C = 0;\n  vc<int> comp(N);\n  vc<int> low(N);\n  vc<int> ord(N, -1);\n\
    \  vc<int> visited;\n  int now = 0;\n\n  auto dfs = [&](auto self, int v) -> void\
    \ {\n    low[v] = now;\n    ord[v] = now;\n    ++now;\n    visited.eb(v);\n  \
    \  for (auto&& [frm, to, cost, id]: G[v]) {\n      if (ord[to] == -1) {\n    \
    \    self(self, to);\n        chmin(low[v], low[to]);\n      } else {\n      \
    \  chmin(low[v], ord[to]);\n      }\n    }\n    if (low[v] == ord[v]) {\n    \
    \  while (1) {\n        int u = visited.back();\n        visited.pop_back();\n\
    \        ord[u] = N;\n        comp[u] = C;\n        if (u == v) break;\n     \
    \ }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n    if (ord[v] == -1) dfs(dfs, v);\n\
    \  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n  return {C, comp};\n}\n\ntemplate\
    \ <typename GT>\nGraph<int, 1> scc_dag(GT& G, int C, vc<int>& comp) {\n  Graph<int,\
    \ 1> DAG(C);\n  vvc<int> edges(C);\n  for (auto&& e: G.edges) {\n    int x = comp[e.frm],\
    \ y = comp[e.to];\n    if (x == y) continue;\n    edges[x].eb(y);\n  }\n  FOR(c,\
    \ C) {\n    UNIQUE(edges[c]);\n    for (auto&& to: edges[c]) DAG.add(c, to);\n\
    \  }\n  DAG.build();\n  return DAG;\n}\n#line 2 \"graph/twosat.hpp\"\n\r\nstruct\
    \ TwoSat {\r\n  vc<int> values;\r\n\r\n  Graph<int, 1> G;\r\n  TwoSat(ll n) :\
    \ G(n + n), values(n, -1) {}\r\n  void add(int a, int b) {\r\n    a = (a >= 0\
    \ ? 2 * a + 1 : 2 * (~a));\r\n    b = (b >= 0 ? 2 * b + 1 : 2 * (~b));\r\n   \
    \ G.add(a ^ 1, b);\r\n    G.add(b ^ 1, a);\r\n  }\r\n  void set(int a) {\r\n \
    \   if (a >= 0)\r\n      values[a] = 1;\r\n    else\r\n      values[~a] = 0;\r\
    \n    a = (a >= 0 ? 2 * a + 1 : 2 * (~a));\r\n    G.add(a ^ 1, a);\r\n  }\r\n\
    \  void implies(int a, int b) { add(~a, b); }\r\n\r\n  bool calc() {\r\n    G.build();\r\
    \n    ll n = len(values);\r\n    auto [C, comp] = strongly_connected_component(G);\r\
    \n    FOR(i, n) {\r\n      if (comp[2 * i] == comp[2 * i + 1]) return false;\r\
    \n      values[i] = comp[2 * i] < comp[2 * i + 1];\r\n    }\r\n    return true;\r\
    \n  }\r\n};\n#line 5 \"test/library_checker/math/twosat.test.cpp\"\n\r\nvoid solve()\
    \ {\r\n  STR(p, cnf);\r\n  LL(N, M);\r\n  TwoSat ts(N);\r\n  FOR(i, M) {\r\n \
    \   LL(a, b, c);\r\n    a = (a > 0 ? a - 1 : a);\r\n    b = (b > 0 ? b - 1 : b);\r\
    \n    ts.add(a, b);\r\n  }\r\n  bool ok = ts.calc();\r\n  auto A = ts.values;\r\
    \n  if (ok) {\r\n    print(\"s SATISFIABLE\");\r\n    vc<int> ANS(N);\r\n    FOR(i,\
    \ N) ANS[i] = (A[i] ? i + 1 : -(i + 1));\r\n    print(\"v\", ANS, \"0\");\r\n\
    \  } else {\r\n    print(\"s UNSATISFIABLE\");\r\n  }\r\n}\r\n\r\nsigned main()\
    \ {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\
    \n\r\n  // LL(T);\r\n  ll T = 1;\r\n  FOR(_, T) solve();\r\n\r\n  return 0;\r\n\
    }\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\r\n#include \"\
    my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"graph/twosat.hpp\"\
    \r\n\r\nvoid solve() {\r\n  STR(p, cnf);\r\n  LL(N, M);\r\n  TwoSat ts(N);\r\n\
    \  FOR(i, M) {\r\n    LL(a, b, c);\r\n    a = (a > 0 ? a - 1 : a);\r\n    b =\
    \ (b > 0 ? b - 1 : b);\r\n    ts.add(a, b);\r\n  }\r\n  bool ok = ts.calc();\r\
    \n  auto A = ts.values;\r\n  if (ok) {\r\n    print(\"s SATISFIABLE\");\r\n  \
    \  vc<int> ANS(N);\r\n    FOR(i, N) ANS[i] = (A[i] ? i + 1 : -(i + 1));\r\n  \
    \  print(\"v\", ANS, \"0\");\r\n  } else {\r\n    print(\"s UNSATISFIABLE\");\r\
    \n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  // LL(T);\r\n  ll T = 1;\r\n  FOR(_, T)\
    \ solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/twosat.hpp
  - graph/strongly_connected_component.hpp
  - graph/base.hpp
  isVerificationFile: true
  path: test/library_checker/math/twosat.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 18:57:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/twosat.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/twosat.test.cpp
- /verify/test/library_checker/math/twosat.test.cpp.html
title: test/library_checker/math/twosat.test.cpp
---
