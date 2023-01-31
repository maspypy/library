---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/disjointsparse/disjointsparse.hpp
    title: ds/disjointsparse/disjointsparse.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path/dijkstra.hpp
    title: graph/shortest_path/dijkstra.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':heavy_check_mark:'
    path: string/longest_common_substring.hpp
    title: string/longest_common_substring.hpp
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/arc151/tasks/arc151_e
    links:
    - https://atcoder.jp/contests/arc151/tasks/arc151_e
  bundledCode: "#line 1 \"test_atcoder/arc151_e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/arc151/tasks/arc151_e\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \ check, ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n\
    \    auto x = (ng + ok) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok,\
    \ x));\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n\
    \  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T\
    \ &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U>\
    \ &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const vector<T>\
    \ &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n\
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
    \ yes(!t); }\n#line 2 \"string/suffix_array.hpp\"\n\n#line 2 \"alg/monoid/min.hpp\"\
    \n\r\ntemplate <class X>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n\
    \  static constexpr X op(const X &x, const X &y) noexcept { return min(x, y);\
    \ }\r\n  static constexpr X unit() { return numeric_limits<X>::max(); }\r\n  static\
    \ constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/disjointsparse/disjointsparse.hpp\"\
    \n\r\ntemplate <class Monoid>\r\nstruct DisjointSparse {\r\n  using MX = Monoid;\r\
    \n  using X = typename MX::value_type;\r\n  int n, log;\r\n  vvc<X> dat;\r\n\r\
    \n  DisjointSparse() {}\r\n  DisjointSparse(int n) { build(n); }\r\n  template\
    \ <typename F>\r\n  DisjointSparse(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\
    \  DisjointSparse(const vc<X>& v) { build(v); }\r\n\r\n  void build(int m) {\r\
    \n    build(m, [](int i) -> X { return MX::unit(); });\r\n  }\r\n  void build(const\
    \ vc<X>& v) {\r\n    build(len(v), [&](int i) -> X { return v[i]; });\r\n  }\r\
    \n  template <typename F>\r\n  void build(int m, F f) {\r\n    n = m, log = 1;\r\
    \n    while ((1 << log) < n) ++log;\r\n    dat.resize(log);\r\n    dat[0].reserve(n);\r\
    \n    FOR(i, n) dat[0].eb(f(i));\r\n    FOR(i, 1, log) {\r\n      auto& v = dat[i];\r\
    \n      v = dat[0];\r\n      int b = 1 << i;\r\n      for (int m = b; m <= n;\
    \ m += 2 * b) {\r\n        int L = m - b, R = min(n, m + b);\r\n        FOR3_R(j,\
    \ L + 1, m) v[j - 1] = MX::op(v[j - 1], v[j]);\r\n        FOR3(j, m, R - 1) v[j\
    \ + 1] = MX::op(v[j], v[j + 1]);\r\n      }\r\n    }\r\n  }\r\n\r\n  X prod(int\
    \ L, int R) {\r\n    if (L == R) return MX::unit();\r\n    --R;\r\n    if (L ==\
    \ R) return dat[0][L];\r\n    int k = 31 - __builtin_clz(L ^ R);\r\n    return\
    \ MX::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template <class F>\r\n  int max_right(const\
    \ F check, int L) {\r\n    assert(0 <= L && L <= n && check(MX::unit()));\r\n\
    \    if (L == n) return n;\r\n    int ok = L, ng = n + 1;\r\n    while (ok + 1\
    \ < ng) {\r\n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(L, k));\r\
    \n      if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\
    \n  }\r\n\r\n  template <class F>\r\n  int min_left(const F check, int R) {\r\n\
    \    assert(0 <= R && R <= n && check(MX::unit()));\r\n    if (R == 0) return\
    \ 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 < ok) {\r\n      int k =\
    \ (ok + ng) / 2;\r\n      bool bl = check(prod(k, R));\r\n      if (bl) ok = k;\r\
    \n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n};\n#line 5 \"string/suffix_array.hpp\"\
    \n\n// \u8F9E\u66F8\u9806 i \u756A\u76EE\u306E suffix \u304C j \u6587\u5B57\u76EE\
    \u59CB\u307E\u308A\u3067\u3042\u308B\u3068\u304D\u3001\n// SA[i] = j, ISA[j] =\
    \ i\nstruct Suffix_Array {\n  vector<int> SA;\n  vector<int> ISA;\n  vector<int>\
    \ LCP;\n  bool build_ds;\n  DisjointSparse<Monoid_Min<int>> seg;\n\n  Suffix_Array(string&\
    \ s) : build_ds(0) {\n    char first = 127, last = 0;\n    for (auto&& c: s) {\n\
    \      chmin(first, c);\n      chmax(last, c);\n    }\n    SA = calc_suffix_array(s,\
    \ first, last);\n    calc_LCP(s);\n  }\n\n  Suffix_Array(vector<int>& s) : build_ds(0)\
    \ {\n    SA = calc_suffix_array(s);\n    calc_LCP(s);\n  }\n\n  // S[i:], S[j:]\
    \ \u306E lcp \u3092\u6C42\u3081\u308B\n  int lcp(int i, int j) {\n    int n =\
    \ len(SA);\n    assert(i <= n && j <= n);\n    if (i == n || j == n) return 0;\n\
    \    if (i == j) return n - i;\n    if (!build_ds) {\n      build_ds = 1;\n  \
    \    seg.build(LCP);\n    }\n    i = ISA[i], j = ISA[j];\n    if (i > j) swap(i,\
    \ j);\n    return seg.prod(i, j);\n  }\n\nprivate:\n  void induced_sort(const\
    \ std::vector<int>& vect, int val_range,\n                    std::vector<int>&\
    \ SA, const std::vector<bool>& sl,\n                    const std::vector<int>&\
    \ lms_idx) {\n    std::vector<int> l(val_range, 0), r(val_range, 0);\n    for\
    \ (int c: vect) {\n      if (c + 1 < val_range) ++l[c + 1];\n      ++r[c];\n \
    \   }\n    std::partial_sum(l.begin(), l.end(), l.begin());\n    std::partial_sum(r.begin(),\
    \ r.end(), r.begin());\n    std::fill(SA.begin(), SA.end(), -1);\n    for (int\
    \ i = (int)lms_idx.size() - 1; i >= 0; --i)\n      SA[--r[vect[lms_idx[i]]]] =\
    \ lms_idx[i];\n    for (int i: SA)\n      if (i >= 1 && sl[i - 1]) SA[l[vect[i\
    \ - 1]]++] = i - 1;\n    std::fill(r.begin(), r.end(), 0);\n    for (int c: vect)\
    \ ++r[c];\n    std::partial_sum(r.begin(), r.end(), r.begin());\n    for (int\
    \ k = (int)SA.size() - 1, i = SA[k]; k >= 1; --k, i = SA[k])\n      if (i >= 1\
    \ && !sl[i - 1]) { SA[--r[vect[i - 1]]] = i - 1; }\n  }\n\n  std::vector<int>\
    \ SA_IS(const std::vector<int>& vect, int val_range) {\n    const int n = vect.size();\n\
    \    std::vector<int> SA(n), lms_idx;\n    std::vector<bool> sl(n);\n    sl[n\
    \ - 1] = false;\n    for (int i = n - 2; i >= 0; --i) {\n      sl[i] = (vect[i]\
    \ > vect[i + 1] || (vect[i] == vect[i + 1] && sl[i + 1]));\n      if (sl[i] &&\
    \ !sl[i + 1]) lms_idx.push_back(i + 1);\n    }\n    std::reverse(lms_idx.begin(),\
    \ lms_idx.end());\n    induced_sort(vect, val_range, SA, sl, lms_idx);\n    std::vector<int>\
    \ new_lms_idx(lms_idx.size()), lms_vec(lms_idx.size());\n    for (int i = 0, k\
    \ = 0; i < n; ++i)\n      if (!sl[SA[i]] && SA[i] >= 1 && sl[SA[i] - 1]) {\n \
    \       new_lms_idx[k++] = SA[i];\n      }\n    int cur = 0;\n    SA[n - 1] =\
    \ cur;\n    for (size_t k = 1; k < new_lms_idx.size(); ++k) {\n      int i = new_lms_idx[k\
    \ - 1], j = new_lms_idx[k];\n      if (vect[i] != vect[j]) {\n        SA[j] =\
    \ ++cur;\n        continue;\n      }\n      bool flag = false;\n      for (int\
    \ a = i + 1, b = j + 1;; ++a, ++b) {\n        if (vect[a] != vect[b]) {\n    \
    \      flag = true;\n          break;\n        }\n        if ((!sl[a] && sl[a\
    \ - 1]) || (!sl[b] && sl[b - 1])) {\n          flag = !((!sl[a] && sl[a - 1])\
    \ && (!sl[b] && sl[b - 1]));\n          break;\n        }\n      }\n      SA[j]\
    \ = (flag ? ++cur : cur);\n    }\n    for (size_t i = 0; i < lms_idx.size(); ++i)\
    \ lms_vec[i] = SA[lms_idx[i]];\n    if (cur + 1 < (int)lms_idx.size()) {\n   \
    \   auto lms_SA = SA_IS(lms_vec, cur + 1);\n      for (size_t i = 0; i < lms_idx.size();\
    \ ++i) {\n        new_lms_idx[i] = lms_idx[lms_SA[i]];\n      }\n    }\n    induced_sort(vect,\
    \ val_range, SA, sl, new_lms_idx);\n    return SA;\n  }\n\n  std::vector<int>\
    \ calc_suffix_array(const std::string& s,\n                                  \
    \   const char first = 'a',\n                                     const char last\
    \ = 'z') {\n    std::vector<int> vect(s.size() + 1);\n    std::copy(std::begin(s),\
    \ std::end(s), std::begin(vect));\n    for (auto& x: vect) x -= (int)first - 1;\n\
    \    vect.back() = 0;\n    auto ret = SA_IS(vect, (int)last - (int)first + 2);\n\
    \    ret.erase(ret.begin());\n    return ret;\n  }\n\n  std::vector<int> calc_suffix_array(const\
    \ vector<int>& s) {\n    vector<int> ss = s;\n    sort(ss.begin(), ss.end());\n\
    \    ss.erase(unique(ss.begin(), ss.end()), ss.end());\n\n    std::vector<int>\
    \ vect(s.size() + 1);\n    std::copy(std::begin(s), std::end(s), std::begin(vect));\n\
    \    for (auto& x: vect)\n      x = lower_bound(ss.begin(), ss.end(), x) - ss.begin()\
    \ + 1;\n    vect.back() = 0;\n    auto ret = SA_IS(vect, *max_element(vect.begin(),\
    \ vect.end()) + 2);\n    ret.erase(ret.begin());\n    return ret;\n  }\n\n  template\
    \ <typename STRING>\n  void calc_LCP(const STRING& s) {\n    int n = s.size(),\
    \ k = 0;\n    ISA.resize(n);\n    LCP.resize(n);\n    for (int i = 0; i < n; i++)\
    \ ISA[SA[i]] = i;\n    for (int i = 0; i < n; i++, k ? k-- : 0) {\n      if (ISA[i]\
    \ == n - 1) {\n        k = 0;\n        continue;\n      }\n      int j = SA[ISA[i]\
    \ + 1];\n      while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;\n \
    \     LCP[ISA[i]] = k;\n    }\n    LCP.resize(n - 1);\n  }\n};\n#line 2 \"string/longest_common_substring.hpp\"\
    \n\ntemplate <typename STRING>\ntuple<int, int, int, int> longest_common_substring(STRING&\
    \ S, STRING& T) {\n  int dummy = max<int>(*max_element(all(S)), *max_element(all(T)))\
    \ + 1;\n  STRING ST;\n  for (auto&& x: S) ST.push_back(x);\n  ST.push_back(dummy);\n\
    \  for (auto&& x: T) ST.push_back(x);\n  Suffix_Array X(ST);\n  auto& SA = X.SA;\n\
    \  auto& LCP = X.LCP;\n\n  tuple<int, int, int, int> res = {0, 0, 0, 0};\n  int\
    \ n = 0;\n  FOR(i, len(ST) - 1) {\n    if ((SA[i] < len(S)) != (SA[i + 1] < len(S)))\
    \ {\n      if (chmax(n, LCP[i])) {\n        int a = SA[i];\n        int b = SA[i\
    \ + 1] - len(S) - 1;\n        res = {a, a + n, b, b + n};\n      }\n    }\n  }\n\
    \  return res;\n}\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int,\
    \ bool directed = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool\
    \ prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph*\
    \ G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n\
    \    const edge_type* end() const {\n      if (l == r) { return 0; }\n      return\
    \ &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n    int l, r;\n\
    \  };\n\n  bool is_prepared() { return prepared; }\n  constexpr bool is_directed()\
    \ { return directed; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int\
    \ N) : N(N), M(0), prepared(0) {}\n\n  void resize(int n) { N = n; }\n\n  void\
    \ add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n   \
    \ assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e\
    \ = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n  // wt,\
    \ off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt,\
    \ off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n    for\
    \ (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n   \
    \   if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
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
    \ }\n  }\n};\n#line 3 \"graph/shortest_path/dijkstra.hpp\"\n\ntemplate <typename\
    \ T, typename Graph>\npair<vc<T>, vc<int>> dijkstra(Graph& G, int v, T INF) {\n\
    \  auto N = G.N;\n  vector<T> dist(N, INF);\n  vector<int> par(N, -1);\n  using\
    \ P = pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>> que;\n\n  dist[v]\
    \ = 0;\n  que.emplace(0, v);\n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n\
    \    que.pop();\n    if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n\
    \      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {\n        par[e.to] = e.frm;\n\
    \        que.emplace(dist[e.to], e.to);\n      }\n    }\n  }\n  return {dist,\
    \ par};\n}\n\n// \u591A\u70B9\u30B9\u30BF\u30FC\u30C8\u3002[dist, par, root]\n\
    template <typename T, typename Graph>\ntuple<vc<T>, vc<int>, vc<int>> dijkstra(Graph&\
    \ G, vc<int> vs, T INF) {\n  assert(G.is_prepared());\n  int N = G.N;\n  vc<ll>\
    \ dist(N, INF);\n  vc<int> par(N, -1);\n  vc<int> root(N, -1);\n\n  using P =\
    \ pair<T, int>;\n\n  priority_queue<P, vector<P>, greater<P>> que;\n\n  for (auto&&\
    \ v: vs) {\n    dist[v] = 0;\n    root[v] = v;\n    que.emplace(T(0), v);\n  }\n\
    \n  while (!que.empty()) {\n    auto [dv, v] = que.top();\n    que.pop();\n  \
    \  if (dv > dist[v]) continue;\n    for (auto&& e: G[v]) {\n      if (chmin(dist[e.to],\
    \ dist[e.frm] + e.cost)) {\n        root[e.to] = root[e.frm];\n        par[e.to]\
    \ = e.frm;\n        que.push(mp(dist[e.to], e.to));\n      }\n    }\n  }\n  return\
    \ {dist, par, root};\n}\n#line 6 \"test_atcoder/arc151_e.test.cpp\"\n\nvoid solve()\
    \ {\n  INT(N);\n  VEC(int, A, N);\n  INT(P);\n  VEC(int, B, P);\n  INT(Q);\n \
    \ VEC(int, C, Q);\n\n  int lcp = [&]() -> int {\n    auto [l1, r1, l2, r2] = longest_common_substring(B,\
    \ C);\n    return r1 - l1;\n  }();\n\n  if (lcp >= 1) { return print(P + Q - 2\
    \ * lcp); }\n\n  // \u3042\u3068\u306F\u30011 \u6587\u5B57\u3092\u7D4C\u7531\u3057\
    \u3066\u3046\u308D\u3046\u308D\u3059\u308B\u5834\u5408\n  for (auto&& x: A) --x;\n\
    \  for (auto&& x: B) --x;\n  for (auto&& x: C) --x;\n  int S = N;\n  int T = N\
    \ + 1;\n  Graph<int, 0> G(N + 2);\n  for (auto&& x: B) { G.add(S, x, P - 1); }\n\
    \  for (auto&& x: C) { G.add(x, T, Q - 1); }\n  FOR(i, N - 1) {\n    G.add(A[i],\
    \ A[i + 1], 2);\n    G.add(A[i + 1], A[i], 2);\n  }\n  G.build();\n\n  auto [dist,\
    \ par] = dijkstra(G, S, 1 << 30);\n  print(dist[T]);\n}\n\nsigned main() {\n \
    \ cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc151/tasks/arc151_e\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"string/longest_common_substring.hpp\"\
    \n#include \"graph/shortest_path/dijkstra.hpp\"\n\nvoid solve() {\n  INT(N);\n\
    \  VEC(int, A, N);\n  INT(P);\n  VEC(int, B, P);\n  INT(Q);\n  VEC(int, C, Q);\n\
    \n  int lcp = [&]() -> int {\n    auto [l1, r1, l2, r2] = longest_common_substring(B,\
    \ C);\n    return r1 - l1;\n  }();\n\n  if (lcp >= 1) { return print(P + Q - 2\
    \ * lcp); }\n\n  // \u3042\u3068\u306F\u30011 \u6587\u5B57\u3092\u7D4C\u7531\u3057\
    \u3066\u3046\u308D\u3046\u308D\u3059\u308B\u5834\u5408\n  for (auto&& x: A) --x;\n\
    \  for (auto&& x: B) --x;\n  for (auto&& x: C) --x;\n  int S = N;\n  int T = N\
    \ + 1;\n  Graph<int, 0> G(N + 2);\n  for (auto&& x: B) { G.add(S, x, P - 1); }\n\
    \  for (auto&& x: C) { G.add(x, T, Q - 1); }\n  FOR(i, N - 1) {\n    G.add(A[i],\
    \ A[i + 1], 2);\n    G.add(A[i + 1], A[i], 2);\n  }\n  G.build();\n\n  auto [dist,\
    \ par] = dijkstra(G, S, 1 << 30);\n  print(dist[T]);\n}\n\nsigned main() {\n \
    \ cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - string/longest_common_substring.hpp
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/disjointsparse/disjointsparse.hpp
  - graph/shortest_path/dijkstra.hpp
  - graph/base.hpp
  isVerificationFile: true
  path: test_atcoder/arc151_e.test.cpp
  requiredBy: []
  timestamp: '2023-01-26 19:04:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_atcoder/arc151_e.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/arc151_e.test.cpp
- /verify/test_atcoder/arc151_e.test.cpp.html
title: test_atcoder/arc151_e.test.cpp
---
