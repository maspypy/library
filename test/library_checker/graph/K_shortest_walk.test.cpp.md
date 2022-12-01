---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/pds/persistent_meldable_heap.hpp
    title: ds/pds/persistent_meldable_heap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/reverse_graph.hpp
    title: graph/reverse_graph.hpp
  - icon: ':x:'
    path: graph/shortest_path/K_shortest_walk.hpp
    title: graph/shortest_path/K_shortest_walk.hpp
  - icon: ':question:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/k_shortest_walk
    links:
    - https://judge.yosupo.jp/problem/k_shortest_walk
  bundledCode: "#line 1 \"test/library_checker/graph/K_shortest_walk.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/k_shortest_walk\"\n#line 1 \"\
    my_template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
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
    \ \"other/io.hpp\"\nnamespace fastio {\r\n// https://nyaannyaan.github.io/library/misc/fastio.hpp\
    \ \u3092\u5143\u306B\u6539\u9020\r\n\r\n// \u30AF\u30E9\u30B9\u304C read(), print()\
    \ \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u30E1\
    \u30BF\u95A2\u6570\r\nstruct has_write_impl {\r\n  template <class T>\r\n  static\
    \ auto check(T &&x) -> decltype(x.write(), std::true_type{});\r\n\r\n  template\
    \ <class T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate\
    \ <class T>\r\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
    \ {\r\n};\r\n\r\nstruct has_read_impl {\r\n  template <class T>\r\n  static auto\
    \ check(T &&x) -> decltype(x.read(), std::true_type{});\r\n\r\n  template <class\
    \ T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate <class\
    \ T>\r\nclass has_read : public decltype(has_read_impl::check<T>(std::declval<T>()))\
    \ {};\r\n\r\nstatic constexpr int SZ = 1 << 17;\r\nchar inbuf[SZ], outbuf[SZ];\r\
    \nint in_left = 0, in_right = 0, out_right = 0;\r\n\r\nstruct Pre {\r\n  char\
    \ num[40000];\r\n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000;\
    \ i++) {\r\n      int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n     \
    \   num[i * 4 + j] = n % 10 + '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n\
    \  }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n  int len = in_right -\
    \ in_left;\r\n  memmove(inbuf, inbuf + in_left, len);\r\n  in_right = len + fread(inbuf\
    \ + len, 1, SZ - len, stdin);\r\n  in_left = 0;\r\n}\r\n\r\ninline void flush()\
    \ {\r\n  fwrite(outbuf, 1, out_right, stdout);\r\n  out_right = 0;\r\n}\r\n\r\n\
    inline void read_single(char &c) {\r\n  if (in_left + 32 > in_right) load();\r\
    \n  c = inbuf[in_left++];\r\n}\r\n\r\ntemplate <class T, enable_if_t<is_same<T,\
    \ string>::value, int> = 0>\r\ninline void read_single(T &x) {\r\n  char c = '\
    \ ';\r\n  do {\r\n    if (in_left + 32 > in_right) load();\r\n    c = inbuf[in_left++];\r\
    \n  } while (c == ' ' || c == '\\n');\r\n  x += c;\r\n  while (1) {\r\n    if\
    \ (in_left + 32 > in_right) load();\r\n    c = inbuf[in_left++];\r\n    if (c\
    \ == ' ' || c == '\\n') break;\r\n    x += c;\r\n  }\r\n}\r\n\r\ntemplate <class\
    \ T, enable_if_t<is_integral<T>::value, int> = 0>\r\ninline void read_single(T\
    \ &x) {\r\n  if (in_left + 32 > in_right) load();\r\n  char c;\r\n  do\r\n   \
    \ c = inbuf[in_left++];\r\n  while (c < '-');\r\n  bool minus = false;\r\n  if\
    \ constexpr (is_signed<T>::value == true) {\r\n    if (c == '-') minus = true,\
    \ c = inbuf[in_left++];\r\n  }\r\n  x = 0;\r\n  while (c >= '0') {\r\n    x =\
    \ x * 10 + (c & 15);\r\n    c = inbuf[in_left++];\r\n  }\r\n  if constexpr (is_signed<T>::value\
    \ == true) {\r\n    if (minus) x = -x;\r\n  }\r\n}\r\n\r\ntemplate <typename T,\
    \ typename enable_if<has_read<T>::value>::type * = nullptr>\r\ninline void read_single(T\
    \ x) {\r\n  x.read();\r\n}\r\ntemplate <class T, class U>\r\ninline void read_single(pair<T,\
    \ U> &p) {\r\n  read_single(p.first), read_single(p.second);\r\n}\r\ntemplate\
    \ <class... T>\r\ninline void read(tuple<T...> &tpl) {\r\n  apply([&](auto...\
    \ t) { (read(t), ...); }, tpl);\r\n}\r\ntemplate <class T>\r\ninline void read_single(vector<T>\
    \ &ref) {\r\n  for (auto &d: ref) read_single(d);\r\n}\r\ntemplate <class T, int\
    \ N>\r\ninline void read_single(array<T, N> &ref) {\r\n  for (auto &d: ref) read_single(d);\r\
    \n}\r\n\r\ninline void read() {}\r\ntemplate <typename Head, typename... Tail>\r\
    \ninline void read(Head &head, Tail &... tail) {\r\n  read_single(head);\r\n \
    \ read(tail...);\r\n}\r\n\r\ninline void write(char c) {\r\n  if (out_right >\
    \ SZ - 32) flush();\r\n  outbuf[out_right++] = c;\r\n}\r\ninline void write(bool\
    \ b) {\r\n  if (out_right > SZ - 32) flush();\r\n  outbuf[out_right++] = b ? '1'\
    \ : '0';\r\n}\r\ninline void write(const string &s) {\r\n  if (out_right + s.size()\
    \ > SZ - 32) flush();\r\n  memcpy(outbuf + out_right, s.data(), sizeof(char) *\
    \ s.size());\r\n  out_right += s.size();\r\n}\r\ntemplate <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\ninline void write(T x) {\r\n  if (out_right > SZ - 32) flush();\r\
    \n  if (!x) {\r\n    outbuf[out_right++] = '0';\r\n    return;\r\n  }\r\n  if\
    \ constexpr (is_signed<T>::value == true) {\r\n    if (x < 0) outbuf[out_right++]\
    \ = '-', x = -x;\r\n  }\r\n  int i = 12;\r\n  char buf[16];\r\n  while (x >= 10000)\
    \ {\r\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\r\n    x /= 10000;\r\
    \n    i -= 4;\r\n  }\r\n  if (x < 100) {\r\n    if (x < 10) {\r\n      outbuf[out_right]\
    \ = '0' + x;\r\n      ++out_right;\r\n    } else {\r\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\r\n      uint32_t r = uint32_t(x) - q * 10;\r\n      outbuf[out_right]\
    \ = '0' + q;\r\n      outbuf[out_right + 1] = '0' + r;\r\n      out_right += 2;\r\
    \n    }\r\n  } else {\r\n    if (x < 1000) {\r\n      memcpy(outbuf + out_right,\
    \ pre.num + (x << 2) + 1, 3);\r\n      out_right += 3;\r\n    } else {\r\n   \
    \   memcpy(outbuf + out_right, pre.num + (x << 2), 4);\r\n      out_right += 4;\r\
    \n    }\r\n  }\r\n  memcpy(outbuf + out_right, buf + i + 4, 12 - i);\r\n  out_right\
    \ += 12 - i;\r\n}\r\ninline void write(const double &x) {\r\n  ostringstream oss;\r\
    \n  oss << fixed << setprecision(15) << x;\r\n  string s = oss.str();\r\n  write(s);\r\
    \n}\r\ninline void write(const long double &x) {\r\n  ostringstream oss;\r\n \
    \ oss << fixed << setprecision(15) << x;\r\n  string s = oss.str();\r\n  write(s);\r\
    \n}\r\ntemplate <typename T, typename enable_if<has_write<T>::value>::type * =\
    \ nullptr>\r\ninline void write(T x) {\r\n  x.write();\r\n}\r\ntemplate <class\
    \ T>\r\nvoid write(const vector<T> &val) {\r\n  auto n = val.size();\r\n  for\
    \ (size_t i = 0; i < n; i++) {\r\n    if (i) write(' ');\r\n    write(val[i]);\r\
    \n  }\r\n}\r\ntemplate <class T, class U>\r\nvoid write(const pair<T, U> &val)\
    \ {\r\n  write(val.first);\r\n  write(' ');\r\n  write(val.second);\r\n}\r\ntemplate\
    \ <class T, size_t S>\r\ninline void write(const array<T, S> &val) {\r\n  auto\
    \ n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n    if (i) write('\
    \ ');\r\n    write(val[i]);\r\n  }\r\n}\r\ninline void write(i128 val) {\r\n \
    \ string s;\r\n  bool negative = 0;\r\n  if (val < 0) {\r\n    negative = 1;\r\
    \n    val = -val;\r\n  }\r\n  while (val) {\r\n    s += '0' + int(val % 10);\r\
    \n    val /= 10;\r\n  }\r\n  if (negative) s += \"-\";\r\n  reverse(all(s));\r\
    \n  if (len(s) == 0) s = \"0\";\r\n  write(s);\r\n}\r\nstruct Dummy {\r\n  Dummy()\
    \ { atexit(flush); }\r\n} dummy;\r\n\r\nvoid print() { fastio::write('\\n'); }\r\
    \ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail &&... tail)\
    \ {\r\n  fastio::write(head);\r\n  if (sizeof...(Tail)) fastio::write(' ');\r\n\
    \  print(forward<Tail>(tail)...);\r\n}\r\n} // namespace fastio\r\nusing fastio::read;\r\
    \nusing fastio::print;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\
    \n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define CHAR(...)   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    \r\n#define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n \
    \ read(name)\r\n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print<string>(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print<string>(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t);\
    \ }\r\nvoid yes(bool t = 1) { print<string>(t ? \"yes\" : \"no\"); }\r\nvoid no(bool\
    \ t = 1) { yes(!t); }\r\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\n\
    struct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename\
    \ T = int, bool directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type\
    \ = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int>\
    \ indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n\
    \  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void resize(int n) { N = n;\
    \ }\n\n  void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  //\
    \ wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1,\
    \ wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n  \
    \  for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n\n  void read_parent(int\
    \ off = 1) {\n    for (int v = 1; v < N; ++v) {\n      INT(p);\n      p -= off;\n\
    \      add(p, v);\n    }\n    build();\n  }\n\n  void build() {\n    assert(!prepared);\n\
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
    \n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n  \
    \  vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 1 \"ds/pds/persistent_meldable_heap.hpp\"\n\ntemplate <typename\
    \ VAL, int NODES = 5'000'000>\nstruct Persistent_Meldable_Heap {\n  struct Node\
    \ {\n    Node *l, *r;\n    VAL x;\n    int s;\n  };\n\n  Node *pool;\n  int pid;\n\
    \n  Persistent_Meldable_Heap() : pid(0) { pool = new Node[NODES]; }\n\n  Node\
    \ *new_node(const VAL &x) {\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].x\
    \ = x;\n    pool[pid].s = 1;\n    return &(pool[pid++]);\n  }\n\n  Node *copy_node(Node\
    \ *a) {\n    if (!a) return a;\n    Node *b = new_node(a->x);\n    b->s = a->s;\n\
    \    b->l = a->l;\n    b->r = a->r;\n    return b;\n  }\n\n  Node *meld(Node *a,\
    \ Node *b) {\n    a = copy_node(a);\n    b = copy_node(b);\n    if (!a) return\
    \ b;\n    if (!b) return a;\n    if ((a->x) > (b->x)) swap(a, b);\n    a->r =\
    \ (a->r ? meld(a->r, b) : b);\n    if (!(a->l) || (a->l->s < a->r->s)) swap(a->l,\
    \ a->r);\n    a->s = (a->r ? a->r->s : 0) + 1;\n    return a;\n  }\n\n  Node *push(Node\
    \ *a, VAL x) { return meld(a, new_node(x)); }\n  Node *pop(Node *a) { return meld(a->l,\
    \ a->r); }\n  VAL top(Node *a) { return a->x; }\n\n  vc<VAL> collect(Node *a)\
    \ {\n    vc<VAL> A;\n    auto dfs = [&](auto &dfs, Node *a) -> void {\n      if\
    \ (!a) return;\n      A.eb(a->x);\n      dfs(dfs, a->l);\n      dfs(dfs, a->r);\n\
    \    };\n    dfs(dfs, a);\n    return A;\n  }\n};\n#line 3 \"graph/shortest_path/dijkstra.hpp\"\
    \n\ntemplate <typename T, typename Graph>\npair<vc<T>, vc<int>> dijkstra(Graph&\
    \ G, int v, T INF) {\n  auto N = G.N;\n  vector<T> dist(N, INF);\n  vector<int>\
    \ par(N, -1);\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>>\
    \ que;\n\n  dist[v] = 0;\n  que.emplace(0, v);\n  while (!que.empty()) {\n   \
    \ auto [dv, v] = que.top();\n    que.pop();\n    if (dv > dist[v]) continue;\n\
    \    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to], dist[e.frm] + e.cost))\
    \ {\n        par[e.to] = e.frm;\n        que.emplace(dist[e.to], e.to);\n    \
    \  }\n    }\n  }\n  return {dist, par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\
    \u30C8\u3002[dist, par, root]\ntemplate <typename T, typename Graph>\ntuple<vc<T>,\
    \ vc<int>, vc<int>> dijkstra(Graph& G, vc<int> vs, T INF) {\n  assert(G.is_prepared());\n\
    \  int N = G.N;\n  vc<ll> dist(N, INF);\n  vc<int> par(N, -1);\n  vc<int> root(N,\
    \ -1);\n\n  using P = pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>>\
    \ que;\n\n  for (auto&& v: vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.emplace(T(0),\
    \ v);\n  }\n\n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n\
    \    if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to],\
    \ dist[e.frm] + e.cost)) {\n        root[e.to] = root[e.frm];\n        par[e.to]\
    \ = e.frm;\n        que.push(mp(dist[e.to], e.to));\n      }\n    }\n  }\n  return\
    \ {dist, par, root};\n}\n#line 2 \"graph/reverse_graph.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nGraph<T, 1> reverse_graph(Graph<T, 1>& G) {\r\n  assert(G.is_directed());\r\
    \n  Graph<T, 1> G1(G.N);\r\n  for (auto&& e: G.edges) { G1.add(e.to, e.frm, e.cost,\
    \ e.id); }\r\n  G1.build();\r\n  return G1;\r\n}\r\n#line 4 \"graph/shortest_path/K_shortest_walk.hpp\"\
    \n\n// INF \u57CB\u3081\u3057\u3066\u5FC5\u305A\u9577\u3055 K \u306B\u3057\u305F\
    \u3082\u306E\u3092\u304B\u3048\u3059\u3002\n// \u7121\u5411\u30B0\u30E9\u30D5\u306A\
    \u3089 2 \u500D\u8FBA\u3092\u306F\u3063\u3066\u6709\u5411\u30B0\u30E9\u30D5\u306B\
    \u3057\u3066\u4F7F\u3046\u3053\u3068\n// \u30FB\u30EB\u30FC\u30D7\u304C\u30E4\u30D0\
    \u305D\u3046\u3060\u304C\u3068\u308A\u3042\u3048\u305A\ntemplate <typename T,\
    \ typename GT>\nvc<T> K_shortest_walk(GT &G, int s, int t, int K, T INF) {\n \
    \ int N = G.N;\n  auto RG = reverse_graph(G);\n  auto [dist, par] = dijkstra<ll,\
    \ decltype(RG)>(RG, t, INF);\n  if (dist[s] == INF) { return vc<T>(K, INF); }\n\
    \n  using P = pair<T, int>;\n  Persistent_Meldable_Heap<P> X;\n  using Node =\
    \ typename Persistent_Meldable_Heap<P>::Node;\n  vc<Node *> nodes(N, nullptr);\n\
    \n  vc<bool> vis(N);\n  vc<int> st = {t};\n  vis[t] = 1;\n  while (len(st)) {\n\
    \    int v = pick(st);\n    bool done = 0;\n    for (auto &&e: G[v]) {\n     \
    \ if (dist[e.to] == INF) continue;\n      if (!done && par[v] == e.to && dist[v]\
    \ == dist[e.to] + e.cost) {\n        done = 1;\n        continue;\n      }\n \
    \     T cost = -dist[v] + e.cost + dist[e.to];\n      nodes[v] = X.push(nodes[v],\
    \ {cost, e.to});\n    }\n    for (auto &&e: RG[v]) {\n      if (vis[e.to]) continue;\n\
    \      if (par[e.to] == v) {\n        nodes[e.to] = X.meld(nodes[e.to], nodes[v]);\n\
    \        vis[e.to] = 1;\n        st.eb(e.to);\n      }\n    }\n  }\n\n  ll base\
    \ = dist[s];\n  vc<ll> ANS = {base};\n  if (nodes[s]) {\n    using PAIR = pair<ll,\
    \ Node *>;\n    auto comp = [](auto a, auto b) { return a.fi > b.fi; };\n    priority_queue<PAIR,\
    \ vc<PAIR>, decltype(comp)> que(comp);\n    que.emplace(base + X.top(nodes[s]).fi,\
    \ nodes[s]);\n    while (len(ANS) < K && len(que)) {\n      auto [d, n] = que.top();\n\
    \      que.pop();\n      ANS.eb(d);\n      if (n->l) que.emplace(d + (n->l->x.fi)\
    \ - (n->x.fi), n->l);\n      if (n->r) que.emplace(d + (n->r->x.fi) - (n->x.fi),\
    \ n->r);\n      Node *m = nodes[n->x.se];\n      if (m) { que.emplace(d + m->x.fi,\
    \ m); }\n    }\n  }\n  while (len(ANS) < K) ANS.eb(INF);\n  return ANS;\n}\n#line\
    \ 6 \"test/library_checker/graph/K_shortest_walk.test.cpp\"\n\nvoid solve() {\n\
    \  INT(N, M, s, t, K);\n  Graph<int, 1> G1(N);\n  G1.read_graph(M, 1, 0);\n  const\
    \ ll INF = 1LL << 60;\n  auto ANS = K_shortest_walk<ll>(G1, s, t, K, INF);\n \
    \ for (auto &&x: ANS) {\n    if (x == INF) x = -1;\n    print(x);\n  }\n}\n\n\
    signed main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/k_shortest_walk\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/base.hpp\"\n\
    #include \"graph/shortest_path/K_shortest_walk.hpp\"\n\nvoid solve() {\n  INT(N,\
    \ M, s, t, K);\n  Graph<int, 1> G1(N);\n  G1.read_graph(M, 1, 0);\n  const ll\
    \ INF = 1LL << 60;\n  auto ANS = K_shortest_walk<ll>(G1, s, t, K, INF);\n  for\
    \ (auto &&x: ANS) {\n    if (x == INF) x = -1;\n    print(x);\n  }\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/base.hpp
  - graph/shortest_path/K_shortest_walk.hpp
  - ds/pds/persistent_meldable_heap.hpp
  - graph/shortest_path/dijkstra.hpp
  - graph/reverse_graph.hpp
  isVerificationFile: true
  path: test/library_checker/graph/K_shortest_walk.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 22:09:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/K_shortest_walk.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/K_shortest_walk.test.cpp
- /verify/test/library_checker/graph/K_shortest_walk.test.cpp.html
title: test/library_checker/graph/K_shortest_walk.test.cpp
---
