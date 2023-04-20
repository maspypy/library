---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dsu_on_tree.hpp
    title: graph/dsu_on_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int>\
    \ = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int>\
    \ * 2;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr\
    \ u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * infty<ll>;\ntemplate <>\nconstexpr double infty<double> = infty<ll>;\ntemplate\
    \ <>\nconstexpr long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll,\
    \ ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate\
    \ <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
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
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename\
    \ U>\nT ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate\
    \ <typename T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x\
    \ - y + 1) / y);\n}\ntemplate <typename T, typename U>\npair<T, T> divmod(T x,\
    \ U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const vector<U> &A) {\n  T sum = 0;\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n \
    \ assert(!que.empty());\n  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate\
    \ <typename T>\nT POP(vc<T> &que) {\n  assert(!que.empty());\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    tie(ok, ng) =\
    \ (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return ok;\n}\ntemplate <typename\
    \ F>\ndouble binary_search_real(F check, double ok, double ng, int iter = 100)\
    \ {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    tie(ok, ng) = (check(x)\
    \ ? mp(x, ng) : mp(ok, x));\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class\
    \ T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b,\
    \ 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i];\
    \ }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n#endif\n\
    #line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\
    \n\r\nnamespace fastio {\r\n#define FASTIO\r\n// \u30AF\u30E9\u30B9\u304C read(),\
    \ print() \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\
    \u30E1\u30BF\u95A2\u6570\r\nstruct has_write_impl {\r\n  template <class T>\r\n\
    \  static auto check(T &&x) -> decltype(x.write(), std::true_type{});\r\n\r\n\
    \  template <class T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\
    \r\ntemplate <class T>\r\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
    \ {\r\n};\r\n\r\nstruct has_read_impl {\r\n  template <class T>\r\n  static auto\
    \ check(T &&x) -> decltype(x.read(), std::true_type{});\r\n\r\n  template <class\
    \ T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate <class\
    \ T>\r\nclass has_read : public decltype(has_read_impl::check<T>(std::declval<T>()))\
    \ {};\r\n\r\nstruct Scanner {\r\n  FILE *fp;\r\n  char line[(1 << 15) + 1];\r\n\
    \  size_t st = 0, ed = 0;\r\n  void reread() {\r\n    memmove(line, line + st,\
    \ ed - st);\r\n    ed -= st;\r\n    st = 0;\r\n    ed += fread(line + ed, 1, (1\
    \ << 15) - ed, fp);\r\n    line[ed] = '\\0';\r\n  }\r\n  bool succ() {\r\n   \
    \ while (true) {\r\n      if (st == ed) {\r\n        reread();\r\n        if (st\
    \ == ed) return false;\r\n      }\r\n      while (st != ed && isspace(line[st]))\
    \ st++;\r\n      if (st != ed) break;\r\n    }\r\n    if (ed - st <= 50) {\r\n\
    \      bool sep = false;\r\n      for (size_t i = st; i < ed; i++) {\r\n     \
    \   if (isspace(line[i])) {\r\n          sep = true;\r\n          break;\r\n \
    \       }\r\n      }\r\n      if (!sep) reread();\r\n    }\r\n    return true;\r\
    \n  }\r\n  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>\r\
    \n  bool read_single(T &ref) {\r\n    if (!succ()) return false;\r\n    while\
    \ (true) {\r\n      size_t sz = 0;\r\n      while (st + sz < ed && !isspace(line[st\
    \ + sz])) sz++;\r\n      ref.append(line + st, sz);\r\n      st += sz;\r\n   \
    \   if (!sz || st != ed) break;\r\n      reread();\r\n    }\r\n    return true;\r\
    \n  }\r\n  template <class T, enable_if_t<is_integral<T>::value, int> = 0>\r\n\
    \  bool read_single(T &ref) {\r\n    if (!succ()) return false;\r\n    bool neg\
    \ = false;\r\n    if (line[st] == '-') {\r\n      neg = true;\r\n      st++;\r\
    \n    }\r\n    ref = T(0);\r\n    while (isdigit(line[st])) { ref = 10 * ref +\
    \ (line[st++] & 0xf); }\r\n    if (neg) ref = -ref;\r\n    return true;\r\n  }\r\
    \n  template <typename T,\r\n            typename enable_if<has_read<T>::value>::type\
    \ * = nullptr>\r\n  inline bool read_single(T &x) {\r\n    x.read();\r\n    return\
    \ true;\r\n  }\r\n  bool read_single(double &ref) {\r\n    string s;\r\n    if\
    \ (!read_single(s)) return false;\r\n    ref = std::stod(s);\r\n    return true;\r\
    \n  }\r\n  bool read_single(char &ref) {\r\n    string s;\r\n    if (!read_single(s)\
    \ || s.size() != 1) return false;\r\n    ref = s[0];\r\n    return true;\r\n \
    \ }\r\n  template <class T>\r\n  bool read_single(vector<T> &ref) {\r\n    for\
    \ (auto &d: ref) {\r\n      if (!read_single(d)) return false;\r\n    }\r\n  \
    \  return true;\r\n  }\r\n  template <class T, class U>\r\n  bool read_single(pair<T,\
    \ U> &p) {\r\n    return (read_single(p.first) && read_single(p.second));\r\n\
    \  }\r\n  template <size_t N = 0, typename T>\r\n  void read_single_tuple(T &t)\
    \ {\r\n    if constexpr (N < std::tuple_size<T>::value) {\r\n      auto &x = std::get<N>(t);\r\
    \n      read_single(x);\r\n      read_single_tuple<N + 1>(t);\r\n    }\r\n  }\r\
    \n  template <class... T>\r\n  bool read_single(tuple<T...> &tpl) {\r\n    read_single_tuple(tpl);\r\
    \n    return true;\r\n  }\r\n  void read() {}\r\n  template <class H, class...\
    \ T>\r\n  void read(H &h, T &... t) {\r\n    bool f = read_single(h);\r\n    assert(f);\r\
    \n    read(t...);\r\n  }\r\n  Scanner(FILE *fp) : fp(fp) {}\r\n};\r\n\r\nstruct\
    \ Printer {\r\n  Printer(FILE *_fp) : fp(_fp) {}\r\n  ~Printer() { flush(); }\r\
    \n\r\n  static constexpr size_t SIZE = 1 << 15;\r\n  FILE *fp;\r\n  char line[SIZE],\
    \ small[50];\r\n  size_t pos = 0;\r\n  void flush() {\r\n    fwrite(line, 1, pos,\
    \ fp);\r\n    pos = 0;\r\n  }\r\n  void write(const char val) {\r\n    if (pos\
    \ == SIZE) flush();\r\n    line[pos++] = val;\r\n  }\r\n  template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n  void write(T val) {\r\n    if (pos > (1 << 15) - 50) flush();\r\
    \n    if (val == 0) {\r\n      write('0');\r\n      return;\r\n    }\r\n    if\
    \ (val < 0) {\r\n      write('-');\r\n      val = -val; // todo min\r\n    }\r\
    \n    size_t len = 0;\r\n    while (val) {\r\n      small[len++] = char(0x30 |\
    \ (val % 10));\r\n      val /= 10;\r\n    }\r\n    for (size_t i = 0; i < len;\
    \ i++) { line[pos + i] = small[len - 1 - i]; }\r\n    pos += len;\r\n  }\r\n \
    \ void write(const string s) {\r\n    for (char c: s) write(c);\r\n  }\r\n  void\
    \ write(const char *s) {\r\n    size_t len = strlen(s);\r\n    for (size_t i =\
    \ 0; i < len; i++) write(s[i]);\r\n  }\r\n  void write(const double x) {\r\n \
    \   ostringstream oss;\r\n    oss << fixed << setprecision(15) << x;\r\n    string\
    \ s = oss.str();\r\n    write(s);\r\n  }\r\n  void write(const long double x)\
    \ {\r\n    ostringstream oss;\r\n    oss << fixed << setprecision(15) << x;\r\n\
    \    string s = oss.str();\r\n    write(s);\r\n  }\r\n  template <typename T,\r\
    \n            typename enable_if<has_write<T>::value>::type * = nullptr>\r\n \
    \ inline void write(T x) {\r\n    x.write();\r\n  }\r\n  template <class T>\r\n\
    \  void write(const vector<T> val) {\r\n    auto n = val.size();\r\n    for (size_t\
    \ i = 0; i < n; i++) {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\n\
    \    }\r\n  }\r\n  template <class T, class U>\r\n  void write(const pair<T, U>\
    \ val) {\r\n    write(val.first);\r\n    write(' ');\r\n    write(val.second);\r\
    \n  }\r\n  template <size_t N = 0, typename T>\r\n  void write_tuple(const T t)\
    \ {\r\n    if constexpr (N < std::tuple_size<T>::value) {\r\n      if constexpr\
    \ (N > 0) { write(' '); }\r\n      const auto x = std::get<N>(t);\r\n      write(x);\r\
    \n      write_tuple<N + 1>(t);\r\n    }\r\n  }\r\n  template <class... T>\r\n\
    \  bool write(tuple<T...> tpl) {\r\n    write_tuple(tpl);\r\n    return true;\r\
    \n  }\r\n  template <class T, size_t S>\r\n  void write(const array<T, S> val)\
    \ {\r\n    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++) {\r\n  \
    \    if (i) write(' ');\r\n      write(val[i]);\r\n    }\r\n  }\r\n  void write(i128\
    \ val) {\r\n    string s;\r\n    bool negative = 0;\r\n    if (val < 0) {\r\n\
    \      negative = 1;\r\n      val = -val;\r\n    }\r\n    while (val) {\r\n  \
    \    s += '0' + int(val % 10);\r\n      val /= 10;\r\n    }\r\n    if (negative)\
    \ s += \"-\";\r\n    reverse(all(s));\r\n    if (len(s) == 0) s = \"0\";\r\n \
    \   write(s);\r\n  }\r\n};\r\nScanner scanner = Scanner(stdin);\r\nPrinter printer\
    \ = Printer(stdout);\r\nvoid flush() { printer.flush(); }\r\nvoid print() { printer.write('\\\
    n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&... tail) {\r\n  printer.write(head);\r\n  if (sizeof...(Tail)) printer.write('\
    \ ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read() {}\r\ntemplate\
    \ <class Head, class... Tail>\r\nvoid read(Head &head, Tail &... tail) {\r\n \
    \ scanner.read(head);\r\n  read(tail...);\r\n}\r\n} // namespace fastio\r\nusing\
    \ fastio::print;\r\nusing fastio::flush;\r\nusing fastio::read;\r\n\r\n#define\
    \ INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)\
    \   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)    \
    \  \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\n#line 2 \"graph/tree.hpp\"\n\r\n#line 2 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  int N, M;\n  using\
    \ cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n \
    \ vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg,\
    \ vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool\
    \ is_directed() { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n\
    \  Graph(int N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N =\
    \ n, M = 0;\n    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
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
    \    }\n  }\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  Graph<T, directed> rearrange(vc<int> V) {\n    int n = len(V);\n   \
    \ map<int, int> MP;\n    FOR(i, n) MP[V[i]] = i;\n    Graph<T, directed> G(n);\n\
    \    for (auto&& e: edges) {\n      if (MP.count(e.frm) && MP.count(e.to)) {\n\
    \        G.add(MP[e.frm], MP[e.to], e.cost);\n      }\n    }\n    G.build();\n\
    \    return G;\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\
    \u3066\u3044\u308D\u3044\u308D\u3002\r\n// \u6728\u4EE5\u5916\u3001\u975E\u9023\
    \u7D50\u3067\u3082 dfs \u9806\u5E8F\u3084\u89AA\u304C\u3068\u308C\u308B\u3002\r\
    \ntemplate <typename GT>\r\nstruct Tree {\r\n  using Graph_type = GT;\r\n  GT\
    \ *G_ptr;\r\n  using WT = typename GT::cost_type;\r\n  int N;\r\n  vector<int>\
    \ LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\
    \n\r\n  Tree() {}\r\n  Tree(GT &G, int r = 0, bool hld = 1) { build(G, r, hld);\
    \ }\r\n\r\n  void build(GT &G, int r = 0, bool hld = 1) {\r\n    G_ptr = &G;\r\
    \n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);\r\
    \n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\r\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void\
    \ dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\
    \n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l\
    \ = G_ptr->indptr[v], r = G_ptr->indptr[v + 1];\r\n    auto &csr = G_ptr->csr_edges;\r\
    \n    // \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\
    \r\n    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: (*G_ptr)[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\
    \n      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n   \
    \   dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: (*G_ptr)[a]) {\r\n        if (e.to != parent[a] && head[e.to]\
    \ == v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\
    \n      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ e_to_v(int eid) {\r\n    auto e = (*G_ptr).edges[eid];\r\n    return (parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\
    \n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v)\
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  /* k: 0-indexed */\r\n  int LA(int\
    \ v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n      int u\
    \ = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\n    \
    \  k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\r\n \
    \ int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u]\
    \ > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n\
    \  }\r\n\r\n  int lca(int u, int v) { return LCA(u, v); }\r\n  int la(int u, int\
    \ v) { return LA(u, v); }\r\n\r\n  int subtree_size(int v, int root = -1) {\r\n\
    \    if (root == -1) return RID[v] - LID[v];\r\n    if (v == root) return N;\r\
    \n    int x = jump(v, root, 1);\r\n    if (in_subtree(v, x)) return RID[v] - LID[v];\r\
    \n    return N - RID[x] + LID[x];\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n\
    \    int c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2 * depth[c];\r\n\
    \  }\r\n\r\n  WT dist(int a, int b, bool weighted) {\r\n    assert(weighted);\r\
    \n    int c = LCA(a, b);\r\n    return depth_weighted[a] + depth_weighted[b] -\
    \ WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int\
    \ a, int b, ll k) {\r\n    if (k == 1) {\r\n      if (a == b) return -1;\r\n \
    \     return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\
    \n    }\r\n    int c = LCA(a, b);\r\n    int d_ac = depth[a] - depth[c];\r\n \
    \   int d_bc = depth[b] - depth[c];\r\n    if (k > d_ac + d_bc) return -1;\r\n\
    \    if (k <= d_ac) return LA(a, k);\r\n    return LA(b, d_ac + d_bc - k);\r\n\
    \  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\n    for (auto\
    \ &&e: (*G_ptr)[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n    return\
    \ res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int u, int v,\
    \ bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\u533A\u9593\
    \u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1) {\r\n      if\
    \ (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]],\
    \ LID[v]);\r\n        v = parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u],\
    \ LID[head[u]]);\r\n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if\
    \ (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge\
    \ <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(),\
    \ all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int> restore_path(int u, int\
    \ v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n};\r\n#line 2 \"graph/dsu_on_tree.hpp\"\n\n// add(v)\
    \ : \u9802\u70B9 v \u306E\u30C7\u30FC\u30BF\u3092\u8FFD\u52A0\u3059\u308B\n//\
    \ query(v) : \u9802\u70B9 v \u306B\u304A\u3051\u308B\u30AF\u30A8\u30EA\u306B\u7B54\
    \u3048\u308B\n// reset() : \u30C7\u30FC\u30BF\u304C\u7A7A\u306E\u72B6\u614B\u306B\
    \u623B\u3059\u3002\n// \u30C7\u30FC\u30BF\u69CB\u9020\u306B\u3088\u3063\u3066\u306F\
    \u3001\u5C65\u6B74\u3092\u4F7F\u3063\u3066\u9AD8\u901F\u306B reset \u3059\u308B\
    \u3002\ntemplate <typename TREE, typename F1, typename F2, typename F3>\nvoid\
    \ DSU_on_Tree(TREE& tree, F1& add, F2& query, F3& reset) {\n  auto dfs = [&](auto&\
    \ dfs, int v) -> void {\n    int heavy = -1;\n    // solve light edge\n    for\
    \ (auto&& e: (*(tree.G_ptr))[v]) {\n      if (e.to == tree.parent[v]) continue;\n\
    \      if (tree.head[e.to] == e.to) {\n        dfs(dfs, e.to);\n      } else {\n\
    \        heavy = e.to;\n      }\n    }\n    // solve heavy edge (keep subtree\
    \ data)\n    if (heavy != -1) { dfs(dfs, heavy); }\n\n    // collect data in light\
    \ subtree\n    for (auto&& e: (*tree.G_ptr)[v]) {\n      if (e.to == tree.parent[v])\
    \ continue;\n      if (e.to == heavy) continue;\n      FOR(idx, tree.LID[e.to],\
    \ tree.RID[e.to]) { add(tree.V[idx]); }\n    }\n    add(v);\n    query(v);\n\n\
    \    if (tree.head[v] == v) reset();\n  };\n\n  int root = tree.V[0];\n  dfs(dfs,\
    \ root);\n}\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ E = typename G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree()\
    \ {}\n  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::unit());\n    total\
    \ = G::unit();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int\
    \ i) -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::unit();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() { return total;\
    \ }\n  E sum_all() { return total; }\n  E sum(int k) { return prefix_sum(k); }\n\
    \  E prod(int k) { return prefix_prod(k); }\n  E prefix_sum(int k) { return prefix_prod(k);\
    \ }\n  E prefix_prod(int k) {\n    chmin(k, n);\n    E ret = G::unit();\n    for\
    \ (; k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n\
    \  E sum(int L, int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L,\
    \ 0), chmin(R, n);\n    if (L == 0) return prefix_prod(R);\n    assert(0 <= L\
    \ && L <= R && R <= n);\n    E pos = G::unit(), neg = G::unit();\n    while (L\
    \ < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg\
    \ = G::op(neg, dat[L - 1]), L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check) {\n    assert(check(G::unit()));\n    int\
    \ i = 0;\n    E s = G::unit();\n    int k = 1;\n    while (2 * k <= n) k *= 2;\n\
    \    while (k) {\n      if (i + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i\
    \ + k - 1]);\n        if (check(t)) { i += k, s = t; }\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  int kth(E k) {\n    return max_right([&k](E x)\
    \ -> bool { return x <= k; });\n  }\n};\n#line 6 \"test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n  Graph<int, 1> G(N);\n  FOR(v,\
    \ 1, N) {\n    LL(p);\n    G.add(p, v);\n  }\n  G.build();\n  Tree tree(G);\n\n\
    \  vi ANS(Q, -1);\n  vvc<pair<int, int>> query(N);\n  FOR(q, Q) {\n    LL(t);\n\
    \    if (t == 0) {\n      LL(v, x);\n      query[v].eb(q, x);\n    }\n    if (t\
    \ == 1) {\n      LL(v);\n      query[v].eb(q, -1);\n    }\n  }\n\n  FenwickTree<Monoid_Add<ll>>\
    \ bit(Q);\n  vc<pair<int, int>> history;\n  ll base_sum = 0;\n\n  auto ADD = [&](int\
    \ v) -> void {\n    base_sum += A[v];\n    for (auto&& [q, x]: query[v]) {\n \
    \     if (x != -1) {\n        bit.add(q, x);\n        history.eb(q, x);\n    \
    \  }\n    }\n  };\n  auto QUERY = [&](int v) -> void {\n    for (auto&& [q, x]:\
    \ query[v]) {\n      if (x == -1) ANS[q] = base_sum + bit.sum(q);\n    }\n  };\n\
    \  auto RESET = [&]() -> void {\n    base_sum = 0;\n    for (auto&& [q, x]: history)\
    \ bit.add(q, -x);\n    history.clear();\n  };\n  DSU_on_Tree(tree, ADD, QUERY,\
    \ RESET);\n  for (auto&& ans: ANS)\n    if (ans != -1) print(ans);\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/dsu_on_tree.hpp\"\
    \n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n\
    \  VEC(ll, A, N);\n  Graph<int, 1> G(N);\n  FOR(v, 1, N) {\n    LL(p);\n    G.add(p,\
    \ v);\n  }\n  G.build();\n  Tree tree(G);\n\n  vi ANS(Q, -1);\n  vvc<pair<int,\
    \ int>> query(N);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(v, x);\n\
    \      query[v].eb(q, x);\n    }\n    if (t == 1) {\n      LL(v);\n      query[v].eb(q,\
    \ -1);\n    }\n  }\n\n  FenwickTree<Monoid_Add<ll>> bit(Q);\n  vc<pair<int, int>>\
    \ history;\n  ll base_sum = 0;\n\n  auto ADD = [&](int v) -> void {\n    base_sum\
    \ += A[v];\n    for (auto&& [q, x]: query[v]) {\n      if (x != -1) {\n      \
    \  bit.add(q, x);\n        history.eb(q, x);\n      }\n    }\n  };\n  auto QUERY\
    \ = [&](int v) -> void {\n    for (auto&& [q, x]: query[v]) {\n      if (x ==\
    \ -1) ANS[q] = base_sum + bit.sum(q);\n    }\n  };\n  auto RESET = [&]() -> void\
    \ {\n    base_sum = 0;\n    for (auto&& [q, x]: history) bit.add(q, -x);\n   \
    \ history.clear();\n  };\n  DSU_on_Tree(tree, ADD, QUERY, RESET);\n  for (auto&&\
    \ ans: ANS)\n    if (ans != -1) print(ans);\n}\n\nsigned main() {\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/dsu_on_tree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
  requiredBy: []
  timestamp: '2023-04-09 13:24:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
- /verify/test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp.html
title: test/library_checker/datastructure/vertex_add_subtree_sum_dsu.test.cpp
---
