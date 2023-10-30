---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/mincostflow.hpp
    title: flow/mincostflow.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/strongly_connected_component.hpp
    title: graph/strongly_connected_component.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc214/tasks/abc214_h
    links:
    - https://atcoder.jp/contests/abc214/tasks/abc214_h
  bundledCode: "#line 1 \"test_atcoder/abc214h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc214/tasks/abc214_h\"\
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
    \  return B;\n}\n#endif\n#line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\
    \n#include <unistd.h>\r\n\r\nnamespace fastio {\r\n#define FASTIO\r\n// \u30AF\
    \u30E9\u30B9\u304C read(), print() \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\
    \u5224\u5B9A\u3059\u308B\u30E1\u30BF\u95A2\u6570\r\nstruct has_write_impl {\r\n\
    \  template <class T>\r\n  static auto check(T &&x) -> decltype(x.write(), std::true_type{});\r\
    \n\r\n  template <class T>\r\n  static auto check(...) -> std::false_type;\r\n\
    };\r\n\r\ntemplate <class T>\r\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
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
    \ yes(!t); }\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge\
    \ {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using\
    \ edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
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
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto&& eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 3 \"graph/strongly_connected_component.hpp\"\n\ntemplate <typename\
    \ Graph>\npair<int, vc<int>> strongly_connected_component(Graph& G) {\n  assert(G.is_directed());\n\
    \  assert(G.is_prepared());\n  int N = G.N;\n  int C = 0;\n  vc<int> comp(N);\n\
    \  vc<int> low(N);\n  vc<int> ord(N, -1);\n  vc<int> visited;\n  int now = 0;\n\
    \n  auto dfs = [&](auto self, int v) -> void {\n    low[v] = now;\n    ord[v]\
    \ = now;\n    ++now;\n    visited.eb(v);\n    for (auto&& [frm, to, cost, id]:\
    \ G[v]) {\n      if (ord[to] == -1) {\n        self(self, to);\n        chmin(low[v],\
    \ low[to]);\n      } else {\n        chmin(low[v], ord[to]);\n      }\n    }\n\
    \    if (low[v] == ord[v]) {\n      while (1) {\n        int u = visited.back();\n\
    \        visited.pop_back();\n        ord[u] = N;\n        comp[u] = C;\n    \
    \    if (u == v) break;\n      }\n      ++C;\n    }\n  };\n  FOR(v, N) {\n   \
    \ if (ord[v] == -1) dfs(dfs, v);\n  }\n  FOR(v, N) comp[v] = C - 1 - comp[v];\n\
    \  return {C, comp};\n}\n\ntemplate <typename GT>\nGraph<int, 1> scc_dag(GT& G,\
    \ int C, vc<int>& comp) {\n  Graph<int, 1> DAG(C);\n  vvc<int> edges(C);\n  for\
    \ (auto&& e: G.edges) {\n    int x = comp[e.frm], y = comp[e.to];\n    if (x ==\
    \ y) continue;\n    edges[x].eb(y);\n  }\n  FOR(c, C) {\n    UNIQUE(edges[c]);\n\
    \    for (auto&& to: edges[c]) DAG.add(c, to);\n  }\n  DAG.build();\n  return\
    \ DAG;\n}\n#line 2 \"flow/mincostflow.hpp\"\n\n// atcoder library \u306E\u3082\
    \u306E\u3092\u6539\u5909\nnamespace internal {\ntemplate <class E>\nstruct csr\
    \ {\n  vector<int> start;\n  vector<E> elist;\n  explicit csr(int n, const vector<pair<int,\
    \ E>>& edges)\n      : start(n + 1), elist(edges.size()) {\n    for (auto e: edges)\
    \ { start[e.first + 1]++; }\n    for (int i = 1; i <= n; i++) { start[i] += start[i\
    \ - 1]; }\n    auto counter = start;\n    for (auto e: edges) { elist[counter[e.first]++]\
    \ = e.second; }\n  }\n};\n\ntemplate <class T>\nstruct simple_queue {\n  vector<T>\
    \ payload;\n  int pos = 0;\n  void reserve(int n) { payload.reserve(n); }\n  int\
    \ size() const { return int(payload.size()) - pos; }\n  bool empty() const { return\
    \ pos == int(payload.size()); }\n  void push(const T& t) { payload.push_back(t);\
    \ }\n  T& front() { return payload[pos]; }\n  void clear() {\n    payload.clear();\n\
    \    pos = 0;\n  }\n  void pop() { pos++; }\n};\n\n} // namespace internal\n\n\
    /*\n\u30FBatcoder library \u3092\u3059\u3053\u3057\u6539\u5909\u3057\u305F\u3082\
    \u306E\n\u30FBDAG = true \u3067\u3042\u308C\u3070\u3001\u8CA0\u8FBA OK \uFF08\
    1 \u56DE\u76EE\u306E\u6700\u77ED\u8DEF\u3092 dp \u3067\u884C\u3046\uFF09\n\u305F\
    \u3060\u3057\u3001\u9802\u70B9\u756A\u53F7\u306F toposort \u3055\u308C\u3066\u3044\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\u3002\n*/\ntemplate\
    \ <class Cap = int, class Cost = ll, bool DAG = false>\nstruct Min_Cost_Flow {\n\
    public:\n  Min_Cost_Flow() {}\n  explicit Min_Cost_Flow(int n, int source, int\
    \ sink)\n      : n(n), source(source), sink(sink) {\n    assert(0 <= source &&\
    \ source < n);\n    assert(0 <= sink && sink < n);\n    assert(source != sink);\n\
    \  }\n\n  // frm, to, cap, cost\n  int add(int frm, int to, Cap cap, Cost cost)\
    \ {\n    assert(0 <= frm && frm < n);\n    assert(0 <= to && to < n);\n    assert(0\
    \ <= cap);\n    assert(DAG || 0 <= cost);\n    if (DAG) assert(frm < to);\n  \
    \  int m = int(_edges.size());\n    _edges.push_back({frm, to, cap, 0, cost});\n\
    \    return m;\n  }\n\n  void debug() {\n    print(\"flow graph\");\n    print(\"\
    frm, to, cap, cost\");\n    for (auto&& [frm, to, cap, flow, cost]: _edges) {\n\
    \      print(frm, to, cap, cost);\n    }\n  }\n\n  struct edge {\n    int frm,\
    \ to;\n    Cap cap, flow;\n    Cost cost;\n  };\n\n  edge get_edge(int i) {\n\
    \    int m = int(_edges.size());\n    assert(0 <= i && i < m);\n    return _edges[i];\n\
    \  }\n  vector<edge> edges() { return _edges; }\n\n  // (\u6D41\u91CF, \u8CBB\u7528\
    )\n  pair<Cap, Cost> flow() { return flow(infty<Cap>); }\n  // (\u6D41\u91CF,\
    \ \u8CBB\u7528)\n  pair<Cap, Cost> flow(Cap flow_limit) { return slope(flow_limit).back();\
    \ }\n  vector<pair<Cap, Cost>> slope() { return slope(infty<Cap>); }\n  vector<pair<Cap,\
    \ Cost>> slope(Cap flow_limit) {\n    int m = int(_edges.size());\n    vector<int>\
    \ edge_idx(m);\n\n    auto g = [&]() {\n      vector<int> degree(n), redge_idx(m);\n\
    \      vector<pair<int, _edge>> elist;\n      elist.reserve(2 * m);\n      for\
    \ (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ = degree[e.frm]++;\n        redge_idx[i] = degree[e.to]++;\n        elist.push_back({e.frm,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n        elist.push_back({e.to, {e.frm,\
    \ -1, e.flow, -e.cost}});\n      }\n      auto _g = internal::csr<_edge>(n, elist);\n\
    \      for (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ += _g.start[e.frm];\n        redge_idx[i] += _g.start[e.to];\n        _g.elist[edge_idx[i]].rev\
    \ = redge_idx[i];\n        _g.elist[redge_idx[i]].rev = edge_idx[i];\n      }\n\
    \      return _g;\n    }();\n\n    auto result = slope(g, flow_limit);\n\n   \
    \ for (int i = 0; i < m; i++) {\n      auto e = g.elist[edge_idx[i]];\n      _edges[i].flow\
    \ = _edges[i].cap - e.cap;\n    }\n\n    return result;\n  }\n\n  // O(F(N+M))\
    \ \u304F\u3089\u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  vvc<int> path_decomposition()\
    \ {\n    vvc<int> TO(n);\n    for (auto&& e: edges()) { FOR(e.flow) TO[e.frm].eb(e.to);\
    \ }\n    vvc<int> res;\n    vc<int> vis(n);\n\n    while (!TO[source].empty())\
    \ {\n      vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ { vis[POP(path)] = 0; }\n        path.eb(to), vis[to] = 1;\n      }\n      for\
    \ (auto&& v: path) vis[v] = 0;\n      res.eb(path);\n    }\n    return res;\n\
    \  }\n\nprivate:\n  int n, source, sink;\n  vector<edge> _edges;\n\n  // inside\
    \ edge\n  struct _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\
    \n  vector<pair<Cap, Cost>> slope(internal::csr<_edge>& g, Cap flow_limit) {\n\
    \    if (DAG) assert(source == 0 && sink == n - 1);\n    vector<pair<Cost, Cost>>\
    \ dual_dist(n);\n    vector<int> prev_e(n);\n    vector<bool> vis(n);\n    struct\
    \ Q {\n      Cost key;\n      int to;\n      bool operator<(Q r) const { return\
    \ key > r.key; }\n    };\n    vector<int> que_min;\n    vector<Q> que;\n    auto\
    \ dual_ref = [&]() {\n      for (int i = 0; i < n; i++) { dual_dist[i].second\
    \ = infty<Cost>; }\n      fill(vis.begin(), vis.end(), false);\n      que_min.clear();\n\
    \      que.clear();\n\n      // que[0..heap_r) was heapified\n      size_t heap_r\
    \ = 0;\n\n      dual_dist[source].second = 0;\n      que_min.push_back(source);\n\
    \      while (!que_min.empty() || !que.empty()) {\n        int v;\n        if\
    \ (!que_min.empty()) {\n          v = que_min.back();\n          que_min.pop_back();\n\
    \        } else {\n          while (heap_r < que.size()) {\n            heap_r++;\n\
    \            push_heap(que.begin(), que.begin() + heap_r);\n          }\n    \
    \      v = que.front().to;\n          pop_heap(que.begin(), que.end());\n    \
    \      que.pop_back();\n          heap_r--;\n        }\n        if (vis[v]) continue;\n\
    \        vis[v] = true;\n        if (v == sink) break;\n        Cost dual_v =\
    \ dual_dist[v].first, dist_v = dual_dist[v].second;\n        for (int i = g.start[v];\
    \ i < g.start[v + 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap)\
    \ continue;\n          Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n\
    \          if (dual_dist[e.to].second > dist_v + cost) {\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n            if (dist_to == dist_v) {\n             \
    \ que_min.push_back(e.to);\n            } else {\n              que.push_back(Q{dist_to,\
    \ e.to});\n            }\n          }\n        }\n      }\n      if (!vis[sink])\
    \ { return false; }\n\n      for (int v = 0; v < n; v++) {\n        if (!vis[v])\
    \ continue;\n        dual_dist[v].first -= dual_dist[sink].second - dual_dist[v].second;\n\
    \      }\n      return true;\n    };\n\n    auto dual_ref_dag = [&]() {\n    \
    \  FOR(i, n) dual_dist[i].se = infty<Cost>;\n      dual_dist[source].se = 0;\n\
    \      fill(vis.begin(), vis.end(), false);\n      vis[0] = true;\n\n      FOR(v,\
    \ n) {\n        if (!vis[v]) continue;\n        Cost dual_v = dual_dist[v].fi,\
    \ dist_v = dual_dist[v].se;\n        for (int i = g.start[v]; i < g.start[v +\
    \ 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n\
    \          Cost cost = e.cost - dual_dist[e.to].fi + dual_v;\n          if (dual_dist[e.to].se\
    \ > dist_v + cost) {\n            vis[e.to] = true;\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n          }\n        }\n      }\n      if (!vis[sink])\
    \ { return false; }\n\n      for (int v = 0; v < n; v++) {\n        if (!vis[v])\
    \ continue;\n        dual_dist[v].fi -= dual_dist[sink].se - dual_dist[v].se;\n\
    \      }\n      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0,\
    \ prev_cost_per_flow = -1;\n    vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \    while (flow < flow_limit) {\n      if (DAG && flow == 0) {\n        if (!dual_ref_dag())\
    \ break;\n      } else {\n        if (!dual_ref()) break;\n      }\n      Cap\
    \ c = flow_limit - flow;\n      for (int v = sink; v != source; v = g.elist[prev_e[v]].to)\
    \ {\n        c = min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      }\n     \
    \ for (int v = sink; v != source; v = g.elist[prev_e[v]].to) {\n        auto&\
    \ e = g.elist[prev_e[v]];\n        e.cap += c;\n        g.elist[e.rev].cap -=\
    \ c;\n      }\n      Cost d = -dual_dist[source].first;\n      flow += c;\n  \
    \    cost += c * d;\n      if (prev_cost_per_flow == d) { result.pop_back(); }\n\
    \      result.push_back({flow, cost});\n      prev_cost_per_flow = d;\n    }\n\
    \    return result;\n  }\n};\n#line 6 \"test_atcoder/abc214h.test.cpp\"\n\nvoid\
    \ solve() {\n  LL(N, M, K);\n  Graph<bool, 1> G0(N);\n  G0.read_graph(M);\n\n\
    \  auto [nc, comp] = strongly_connected_component(G0);\n  auto DAG = scc_dag(G0,\
    \ nc, comp);\n  vi X(nc);\n  FOR(v, N) {\n    INT(x);\n    X[comp[v]] += x;\n\
    \  }\n\n  auto idx1 = [&](int i) -> int { return 1 + 2 * i + 0; };\n  auto idx2\
    \ = [&](int i) -> int { return 1 + 2 * i + 1; };\n  int source = 0, sink = 1 +\
    \ nc + nc;\n\n  Min_Cost_Flow<int, ll, true> G(2 * nc + 2, source, sink);\n  G.add(source,\
    \ idx1(comp[0]), K, 0);\n  FOR(v, nc) {\n    G.add(idx1(v), idx2(v), 1, -X[v]);\n\
    \    G.add(idx1(v), idx2(v), K, 0);\n    G.add(idx2(v), sink, K, 0);\n  }\n  for\
    \ (auto&& e: DAG.edges) { G.add(idx2(e.frm), idx1(e.to), K, 0); }\n\n  auto [a,\
    \ b] = G.flow();\n  assert(a == K);\n  print(-b);\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc214/tasks/abc214_h\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/strongly_connected_component.hpp\"\
    \n#include \"flow/mincostflow.hpp\"\n\nvoid solve() {\n  LL(N, M, K);\n  Graph<bool,\
    \ 1> G0(N);\n  G0.read_graph(M);\n\n  auto [nc, comp] = strongly_connected_component(G0);\n\
    \  auto DAG = scc_dag(G0, nc, comp);\n  vi X(nc);\n  FOR(v, N) {\n    INT(x);\n\
    \    X[comp[v]] += x;\n  }\n\n  auto idx1 = [&](int i) -> int { return 1 + 2 *\
    \ i + 0; };\n  auto idx2 = [&](int i) -> int { return 1 + 2 * i + 1; };\n  int\
    \ source = 0, sink = 1 + nc + nc;\n\n  Min_Cost_Flow<int, ll, true> G(2 * nc +\
    \ 2, source, sink);\n  G.add(source, idx1(comp[0]), K, 0);\n  FOR(v, nc) {\n \
    \   G.add(idx1(v), idx2(v), 1, -X[v]);\n    G.add(idx1(v), idx2(v), K, 0);\n \
    \   G.add(idx2(v), sink, K, 0);\n  }\n  for (auto&& e: DAG.edges) { G.add(idx2(e.frm),\
    \ idx1(e.to), K, 0); }\n\n  auto [a, b] = G.flow();\n  assert(a == K);\n  print(-b);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/strongly_connected_component.hpp
  - graph/base.hpp
  - flow/mincostflow.hpp
  isVerificationFile: true
  path: test_atcoder/abc214h.test.cpp
  requiredBy: []
  timestamp: '2023-10-29 16:21:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_atcoder/abc214h.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc214h.test.cpp
- /verify/test_atcoder/abc214h.test.cpp.html
title: test_atcoder/abc214h.test.cpp
---
