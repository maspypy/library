---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/eulerwalk.hpp
    title: graph/eulerwalk.hpp
  - icon: ':x:'
    path: graph/vs_to_es.hpp
    title: graph/vs_to_es.hpp
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
    PROBLEM: https://atcoder.jp/contests/arc157/tasks/arc157_a
    links:
    - https://atcoder.jp/contests/arc157/tasks/arc157_a
  bundledCode: "#line 1 \"test_atcoder/arc157a.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc157/tasks/arc157_a\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
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
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define overload4(a,\
    \ b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__,\
    \ FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__,\
    \ FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define FOR_subset(t, s) \\\n  for (ll\
    \ t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n#define all(x) x.begin(),\
    \ x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n\
    #define mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\
    \n#define stoi stoll\n\nint popcnt(int x) { return __builtin_popcount(x); }\n\
    int popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_mod_2(int x) { return __builtin_parity(x); }\nint popcnt_mod_2(u32\
    \ x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll x) { return __builtin_parityll(x);\
    \ }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x); }\n// (0, 1, 2, 3,\
    \ 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
    \       [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n\
    \  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n#endif\n#line 1 \"other/io.hpp\"\n#include <unistd.h>\r\n#include\
    \ <sys/mman.h>\r\n#include <sys/stat.h>\r\n\r\nnamespace fastio {\r\n// https://judge.yosupo.jp/submission/21623\r\
    \n// https://judge.yosupo.jp/submission/70667\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\
    \n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n   \
    \   int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n        num[i][j] =\
    \ n % 10 | '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr\
    \ pre;\r\n\r\nconstexpr int BSZ = 1 << 19;\r\nchar *ibuf, obuf[BSZ], out[100];\r\
    \nint outi, obufi;\r\n\r\n// gcc expansion. called automaticall before main.\r\
    \nvoid __attribute__((constructor)) _c() {\r\n  struct stat sb;\r\n  fstat(0,\
    \ &sb);\r\n  ibuf\r\n      = (char *)mmap(0, sb.st_size, PROT_READ, MAP_SHARED\
    \ | MAP_POPULATE, 0, 0);\r\n}\r\n\r\nvoid flush() {\r\n  assert(write(1, obuf,\
    \ obufi) == obufi);\r\n  obufi = 0;\r\n}\r\n\r\nvoid rd(char &c) { c = *ibuf++;\
    \ }\r\nvoid rd(string &x) {\r\n  x.clear();\r\n  char c;\r\n  do { rd(c); } while\
    \ (isspace(c));\r\n  do { x += c, rd(c); } while (!isspace(c));\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvoid rd_integer(T &x) {\r\n  char c;\r\n  do\r\n    rd(c);\r\
    \n  while (c < '-');\r\n  bool minus = 0;\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (c == '-') { minus = 1, rd(c); }\r\n  }\r\
    \n  x = 0;\r\n  while (c >= '0') { x = x * 10 + (c & 15), rd(c); }\r\n  if constexpr\
    \ (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (minus) x = -x;\r\n\
    \  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n  string s;\r\
    \n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\nvoid rd(int &x) { rd_integer(x); }\r\n\
    void rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double &x) { rd_real(x); }\r\nvoid\
    \ rd(long double &x) { rd_real(x); }\r\nvoid rd(f128 &x) { rd_real(x); }\r\ntemplate\
    \ <class T, class U>\r\nvoid rd(pair<T, U> &p) {\r\n  return rd(p.first), rd(p.second);\r\
    \n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd(T &t) {\r\n  if constexpr\
    \ (N < std::tuple_size<T>::value) {\r\n    auto &x = std::get<N>(t);\r\n    rd(x);\r\
    \n    rd<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\nvoid rd(tuple<T...>\
    \ &tpl) {\r\n  rd(tpl);\r\n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\n\
    \  for (auto &d: x) rd(d);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid\
    \ rd(array<T, N> &x) {\r\n  for (auto &d: x) rd(d);\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nstruct has_read_method {\r\n  template <typename U>\r\n  static std::true_type\
    \ test(decltype(&U::read) *);\r\n  template <typename>\r\n  static std::false_type\
    \ test(...);\r\n  using type = decltype(test<T>(nullptr));\r\n  static constexpr\
    \ bool value = type::value;\r\n};\r\n\r\ntemplate <typename T>\r\ntypename enable_if<has_read_method<T>::value,\
    \ void>::type rd(T &x) {\r\n  x.read();\r\n}\r\n\r\nvoid read() {}\r\ntemplate\
    \ <class H, class... T>\r\nvoid read(H &h, T &... t) {\r\n  rd(h), read(t...);\r\
    \n}\r\n\r\nvoid wt(const char c) {\r\n  if (obufi == BSZ) flush();\r\n  obuf[obufi++]\
    \ = c;\r\n}\r\nvoid wt(const string &s) {\r\n  for (char c: s) wt(c);\r\n}\r\n\
    void wt(const char *s) {\r\n  size_t len = strlen(s);\r\n  for (size_t i = 0;\
    \ i < len; i++) wt(s[i]);\r\n}\r\n\r\ntemplate <typename T>\r\nvoid wt_integer(T\
    \ x) {\r\n  if (obufi > BSZ - 100) flush();\r\n  if (x < 0) { obuf[obufi++] =\
    \ '-', x = -x; }\r\n  for (outi = 96; x >= 10000; outi -= 4) {\r\n    memcpy(out\
    \ + outi, pre.num[x % 10000], 4);\r\n    x /= 10000;\r\n  }\r\n  if (x >= 1000)\
    \ {\r\n    memcpy(obuf + obufi, pre.num[x], 4);\r\n    obufi += 4;\r\n  } else\
    \ if (x >= 100) {\r\n    memcpy(obuf + obufi, pre.num[x] + 1, 3);\r\n    obufi\
    \ += 3;\r\n  } else if (x >= 10) {\r\n    int q = (x * 103) >> 10;\r\n    obuf[obufi]\
    \ = q | '0';\r\n    obuf[obufi + 1] = (x - q * 10) | '0';\r\n    obufi += 2;\r\
    \n  } else\r\n    obuf[obufi++] = x | '0';\r\n  memcpy(obuf + obufi, out + outi\
    \ + 4, 96 - outi);\r\n  obufi += 96 - outi;\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvoid wt_real(T x) {\r\n  ostringstream oss;\r\n  oss << fixed << setprecision(15)\
    \ << double(x);\r\n  string s = oss.str();\r\n  wt(s);\r\n}\r\n\r\nvoid wt(bool\
    \ x) { wt_integer(int(x)); }\r\nvoid wt(int x) { wt_integer(x); }\r\nvoid wt(ll\
    \ x) { wt_integer(x); }\r\nvoid wt(i128 x) { wt_integer(x); }\r\nvoid wt(u32 x)\
    \ { wt_integer(x); }\r\nvoid wt(u64 x) { wt_integer(x); }\r\nvoid wt(u128 x) {\
    \ wt_integer(x); }\r\nvoid wt(double x) { wt_real(x); }\r\nvoid wt(long double\
    \ x) { wt_real(x); }\r\nvoid wt(f128 x) { wt_real(x); }\r\n\r\ntemplate <class\
    \ T, class U>\r\nvoid wt(const pair<T, U> val) {\r\n  wt(val.first);\r\n  wt('\
    \ ');\r\n  wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid\
    \ wt_tuple(const T t) {\r\n  if constexpr (N < std::tuple_size<T>::value) {\r\n\
    \    if constexpr (N > 0) { wt(' '); }\r\n    const auto x = std::get<N>(t);\r\
    \n    wt(x);\r\n    wt_tuple<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\
    \nvoid wt(tuple<T...> tpl) {\r\n  wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t\
    \ S>\r\nvoid wt(const array<T, S> val) {\r\n  auto n = val.size();\r\n  for (size_t\
    \ i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\
    \ntemplate <class T>\r\nvoid wt(const vector<T> val) {\r\n  auto n = val.size();\r\
    \n  for (size_t i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\
    \n  }\r\n}\r\n\r\ntemplate <typename T>\r\nstruct has_print_method {\r\n  template\
    \ <typename U>\r\n  static std::true_type test(decltype(&U::print) *);\r\n  template\
    \ <typename>\r\n  static std::false_type test(...);\r\n  using type = decltype(test<T>(nullptr));\r\
    \n  static constexpr bool value = type::value;\r\n};\r\n\r\ntemplate <typename\
    \ T>\r\ntypename enable_if<has_print_method<T>::value, void>::type wt(T x) {\r\
    \n  x.print();\r\n}\r\n\r\nvoid print() { wt('\\n'); }\r\ntemplate <class Head,\
    \ class... Tail>\r\nvoid print(Head &&head, Tail &&... tail) {\r\n  wt(head);\r\
    \n  if (sizeof...(Tail)) wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\
    \r\n// gcc expansion. called automaticall after main.\r\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\r\n} // namespace fastio\r\n\r\nusing fastio::read;\r\nusing\
    \ fastio::print;\r\nusing fastio::flush;\r\n\r\n#define INT(...)   \\\r\n  int\
    \ __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__;\
    \ \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n  string __VA_ARGS__;\
    \ \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)   \\\r\n  char __VA_ARGS__; \\\
    \r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n  double __VA_ARGS__; \\\
    \r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name, size) \\\r\n  vector<type>\
    \ name(size);    \\\r\n  read(name)\r\n#define VV(type, name, h, w)          \
    \           \\\r\n  vector<vector<type>> name(h, vector<type>(w)); \\\r\n  read(name)\r\
    \n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t\
    \ = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\r\
    \nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1) { print(t ? \"yes\"\
    \ : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\n#line 4 \"test_atcoder/arc157a.test.cpp\"\
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
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid\
    \ = 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e)\
    \ != M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]]\
    \ = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n    FOR(i, n) {\n\
    \      for (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n\
    \        int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b]\
    \ != -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n       \
    \   int eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b],\
    \ e.cost, eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n\
    \    for (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 2 \"graph/vs_to_es.hpp\"\n\n#line 2 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\
    \ntemplate <typename Val, int LOG = 20, bool KEEP_IDS = false>\r\nstruct HashMap\
    \ {\r\n  using P = pair<u64, Val>;\r\n  static constexpr int N = (1 << LOG);\r\
    \n  P* dat;\r\n  vc<int> IDS;\r\n  bitset<N> used;\r\n  const int shift;\r\n \
    \ const u64 r = 11995408973635179863ULL;\r\n  HashMap() : dat(new P[N]), shift(64\
    \ - LOG) {}\r\n  int hash(ll x) {\r\n    static const u64 FIXED_RANDOM\r\n   \
    \     = std::chrono::steady_clock::now().time_since_epoch().count();\r\n    return\
    \ (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const u64& key)\
    \ {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && dat[i].fi != key;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& key) {\r\n    int i = index(key);\r\n    if (!used[i]) {\r\n      used[i]\
    \ = 1, dat[i] = {key, Val{}};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\n\
    \    }\r\n    return dat[i].se;\r\n  }\r\n\r\n  Val get(const u64& key, Val default_value)\
    \ {\r\n    int i = index(key);\r\n    if (!used[i]) return default_value;\r\n\
    \    return dat[i].se;\r\n  }\r\n\r\n  bool count(const u64& key) {\r\n    int\
    \ i = index(key);\r\n    return used[i] && dat[i].fi == key;\r\n  }\r\n\r\n  void\
    \ reset() {\r\n    static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) used[i]\
    \ = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename\
    \ F>\r\n  void enumerate_all(F f) {\r\n    static_assert(KEEP_IDS);\r\n    for\
    \ (auto&& i: IDS) f(dat[i].fi, dat[i].se);\r\n  }\r\n};\r\n#line 4 \"graph/vs_to_es.hpp\"\
    \n\ntemplate <typename GT>\nvc<int> vs_to_es(GT& G, vc<int>& vs, bool allow_use_twice\
    \ = false) {\n  assert(!vs.empty());\n\n  static HashMap<int> MP;\n  MP.reset();\n\
    \  vc<int> nxt(G.M, -1);\n\n  auto get = [&](ll a, ll b) -> u64 {\n    if (GT::is_directed\
    \ && a > b) swap(a, b);\n    return a * G.N + b;\n  };\n\n  FOR(eid, G.M) {\n\
    \    u64 k = get(G.edges[eid].frm, G.edges[eid].to);\n    int x = MP[k];\n   \
    \ nxt[eid] = x, MP[k] = eid;\n  }\n  int n = len(vs);\n  vc<int> es(n - 1);\n\
    \  FOR(i, n - 1) {\n    u64 k = get(vs[i], vs[i + 1]);\n    int eid = MP.get(k,\
    \ -1);\n    assert(eid != -1);\n    es[i] = eid;\n    if (!allow_use_twice) {\
    \ MP[k] = nxt[eid]; }\n  }\n  return es;\n}\n#line 3 \"graph/eulerwalk.hpp\"\n\
    \r\n// (vs, es) or empty\r\ntemplate <typename GT>\r\npair<vc<int>, vc<int>> euler_walk(GT&\
    \ G, int s = -1) {\r\n  const int N = G.N, M = G.M;\r\n  assert(G.is_prepared());\r\
    \n  assert(N > 0);\r\n\r\n  if (s == -1) {\r\n    vc<int> deg(N);\r\n    for (auto&&\
    \ e: G.edges) {\r\n      if constexpr (GT::is_directed) {\r\n        deg[e.frm]++,\
    \ deg[e.to]--;\r\n      } else {\r\n        deg[e.frm]++, deg[e.to]++;\r\n   \
    \   }\r\n    }\r\n    if constexpr (GT::is_directed) {\r\n      s = max_element(all(deg))\
    \ - deg.begin();\r\n      if (deg[s] == 0) s = (M == 0 ? 0 : G.edges[0].frm);\r\
    \n    } else {\r\n      s = [&]() -> int {\r\n        FOR(v, N) if (deg[v] & 1)\
    \ return v;\r\n        return (M == 0 ? 0 : G.edges[0].frm);\r\n      }();\r\n\
    \    }\r\n  }\r\n\r\n  if (M == 0) return {{s}, {}};\r\n  vc<int> D(N), its(N),\
    \ eu(M), vs, st = {s};\r\n  FOR(v, N) its[v] = G.indptr[v];\r\n  ++D[s];\r\n \
    \ while (!st.empty()) {\r\n    int x = st.back(), y, e, &it = its[x], end = G.indptr[x\
    \ + 1];\r\n    if (it == end) {\r\n      vs.eb(x);\r\n      st.pop_back();\r\n\
    \      continue;\r\n    }\r\n    auto& ee = G.csr_edges[it++];\r\n    y = ee.to,\
    \ e = ee.id;\r\n    if (!eu[e]) {\r\n      D[x]--, D[y]++;\r\n      eu[e] = 1;\r\
    \n      st.eb(y);\r\n    }\r\n  }\r\n  for (auto&& x: D)\r\n    if (x < 0) return\
    \ {{}, {}};\r\n  if (len(vs) != M + 1) return {{}, {}};\r\n  reverse(all(vs));\r\
    \n  auto es = vs_to_es(G, vs, false);\r\n  return {vs, es};\r\n}\r\n#line 6 \"\
    test_atcoder/arc157a.test.cpp\"\n\nvoid solve() {\n  LL(N, A, B, C, D);\n  Graph<bool,\
    \ 1> G(2);\n  FOR(A) G.add(0, 0);\n  FOR(B) G.add(0, 1);\n  FOR(C) G.add(1, 0);\n\
    \  FOR(D) G.add(1, 1);\n  G.build();\n  auto vs = euler_walk(G).fi;\n  Yes(!vs.empty());\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc157/tasks/arc157_a\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/eulerwalk.hpp\"\
    \n\nvoid solve() {\n  LL(N, A, B, C, D);\n  Graph<bool, 1> G(2);\n  FOR(A) G.add(0,\
    \ 0);\n  FOR(B) G.add(0, 1);\n  FOR(C) G.add(1, 0);\n  FOR(D) G.add(1, 1);\n \
    \ G.build();\n  auto vs = euler_walk(G).fi;\n  Yes(!vs.empty());\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/eulerwalk.hpp
  - graph/base.hpp
  - graph/vs_to_es.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test_atcoder/arc157a.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 16:40:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/arc157a.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/arc157a.test.cpp
- /verify/test_atcoder/arc157a.test.cpp.html
title: test_atcoder/arc157a.test.cpp
---
