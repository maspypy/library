---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/add_remove_query.hpp
    title: ds/offline_query/add_remove_query.hpp
  - icon: ':heavy_check_mark:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/rollback_unionfind.hpp
    title: ds/unionfind/rollback_unionfind.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/add_remove_query.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#line 1 \"my_template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll\
    \ = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 =\
    \ unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \nint popcnt(int x) { return __builtin_popcount(x); }\nint popcnt(u32 x) { return\
    \ __builtin_popcount(x); }\nint popcnt(ll x) { return __builtin_popcountll(x);\
    \ }\nint popcnt(u64 x) { return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4)\
    \ -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT pick(deque<T>\
    \ &que) {\n  T a = que.front();\n  que.pop_front();\n  return a;\n}\n\ntemplate\
    \ <typename T>\nT pick(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return\
    \ a;\n}\n\ntemplate <typename T>\nT pick(pqg<T> &que) {\n  assert(que.size());\n\
    \  T a = que.top();\n  que.pop();\n  return a;\n}\n\ntemplate <typename T>\nT\
    \ pick(vc<T> &que) {\n  assert(que.size());\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename T, typename U>\nT ceil(T x, U y) {\n  return\
    \ (x > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename T, typename U>\n\
    T floor(T x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate\
    \ <typename T, typename U>\npair<T, T> divmod(T x, U y) {\n  T q = floor(x, y);\n\
    \  return {q, x - q * y};\n}\n\ntemplate <typename F>\nll binary_search(F check,\
    \ ll ok, ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto\
    \ x = (ng + ok) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n\
    \  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return\
    \ (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const\
    \ S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\n\
    inline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i];\
    \ }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename\
    \ CNT, typename T>\nvc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n\
    \  for (auto &&x: A) { ++C[x]; }\n  return C;\n}\n\n// stable\ntemplate <typename\
    \ T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int> ids(A.size());\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i]\
    \ < A[j] || (A[i] == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  int n = len(I);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n  return B;\n\
    }\n#line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\
    \n\r\nnamespace fastio {\r\n// \u30AF\u30E9\u30B9\u304C read(), print() \u3092\
    \u6301\u3063\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u30E1\u30BF\
    \u95A2\u6570\r\nstruct has_write_impl {\r\n  template <class T>\r\n  static auto\
    \ check(T &&x) -> decltype(x.write(), std::true_type{});\r\n\r\n  template <class\
    \ T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate <class\
    \ T>\r\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
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
    \ fp);\r\n    pos = 0;\r\n  }\r\n  void write(const char &val) {\r\n    if (pos\
    \ == SIZE) flush();\r\n    line[pos++] = val;\r\n  }\r\n  template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n  void write(T val) {\r\n    if (pos > (1 << 15) - 50) flush();\r\
    \n    if (val == 0) {\r\n      write('0');\r\n      return;\r\n    }\r\n    if\
    \ (val < 0) {\r\n      write('-');\r\n      val = -val; // todo min\r\n    }\r\
    \n    size_t len = 0;\r\n    while (val) {\r\n      small[len++] = char(0x30 |\
    \ (val % 10));\r\n      val /= 10;\r\n    }\r\n    for (size_t i = 0; i < len;\
    \ i++) { line[pos + i] = small[len - 1 - i]; }\r\n    pos += len;\r\n  }\r\n \
    \ void write(const string &s) {\r\n    for (char c: s) write(c);\r\n  }\r\n  void\
    \ write(const char *s) {\r\n    size_t len = strlen(s);\r\n    for (size_t i =\
    \ 0; i < len; i++) write(s[i]);\r\n  }\r\n  void write(const double &x) {\r\n\
    \    ostringstream oss;\r\n    oss << fixed << setprecision(15) << x;\r\n    string\
    \ s = oss.str();\r\n    write(s);\r\n  }\r\n  void write(const long double &x)\
    \ {\r\n    ostringstream oss;\r\n    oss << fixed << setprecision(15) << x;\r\n\
    \    string s = oss.str();\r\n    write(s);\r\n  }\r\n  template <typename T,\r\
    \n            typename enable_if<has_write<T>::value>::type * = nullptr>\r\n \
    \ inline void write(T &x) {\r\n    x.write();\r\n  }\r\n  template <class T>\r\
    \n  void write(const vector<T> &val) {\r\n    auto n = val.size();\r\n    for\
    \ (size_t i = 0; i < n; i++) {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\
    \n    }\r\n  }\r\n  template <class T, class U>\r\n  void write(const pair<T,\
    \ U> val) {\r\n    write(val.first);\r\n    write(' ');\r\n    write(val.second);\r\
    \n  }\r\n  template <size_t N = 0, typename T>\r\n  void write_tuple(const T t)\
    \ {\r\n    if constexpr (N < std::tuple_size<T>::value) {\r\n      if constexpr\
    \ (N > 0) { write(' '); }\r\n      const auto x = std::get<N>(t);\r\n      write(x);\r\
    \n      write_tuple<N + 1>(t);\r\n    }\r\n  }\r\n  template <class... T>\r\n\
    \  bool write(tuple<T...> tpl) {\r\n    write_tuple(tpl);\r\n    return true;\r\
    \n  }\r\n  template <class T, size_t S>\r\n  void write(const array<T, S> &val)\
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
    \ yes(!t); }\n#line 1 \"ds/offline_query/add_remove_query.hpp\"\n/*\n\u30FB\u6642\
    \u523B t \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u30FB\u6642\u523B t \u306B\
    \ x \u3092\u524A\u9664\u3059\u308B\n\u304C\u3042\u308B\u3068\u304D\u306B\u3001\
    \n\u30FB\u6642\u523B [l, r) \u306B x \u3092\u8FFD\u52A0\u3059\u308B\n\u306B\u5909\
    \u63DB\u3059\u308B\u3002\n\u30AF\u30A8\u30EA\u304C\u6642\u7CFB\u5217\u9806\u306B\
    \u6765\u308B\u3053\u3068\u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3068\u304D\
    \u306F monotone = true \u306E\u65B9\u304C\u9AD8\u901F\u3002\n*/\ntemplate <typename\
    \ X, bool monotone>\nstruct AddRemove_Query {\n  map<X, int> MP;\n  vc<tuple<int,\
    \ int, X>> dat;\n  map<X, vc<int>> ADD;\n  map<X, vc<int>> RM;\n\n  void add(int\
    \ time, X x) {\n    if (monotone) return add_monotone(time, x);\n    ADD[x].eb(time);\n\
    \  }\n  void remove(int time, X x) {\n    if (monotone) return remove_monotone(time,\
    \ x);\n    RM[x].eb(time);\n  }\n\n  // \u3059\u3079\u3066\u306E\u30AF\u30A8\u30EA\
    \u304C\u7D42\u308F\u3063\u305F\u73FE\u5728\u6642\u523B\u3092\u6E21\u3059\n  vc<tuple<int,\
    \ int, X>> calc(int time) {\n    if (monotone) return calc_monotone(time);\n \
    \   vc<tuple<int, int, X>> dat;\n    for (auto&& [x, A]: ADD) {\n      vc<int>\
    \ B;\n      if (RM.count(x)) {\n        B = RM[x];\n        RM.erase(x);\n   \
    \   }\n      if (len(B) < len(A)) B.eb(time);\n      assert(len(A) == len(B));\n\
    \n      sort(all(A));\n      sort(all(B));\n      FOR(i, len(A)) {\n        assert(A[i]\
    \ <= B[i]);\n        if (A[i] < B[i]) dat.eb(A[i], B[i], x);\n      }\n    }\n\
    \    assert(len(RM) == 0);\n    return dat;\n  }\n\nprivate:\n  void add_monotone(int\
    \ time, X x) {\n    assert(!MP.count(x));\n    MP[x] = time;\n  }\n  void remove_monotone(int\
    \ time, X x) {\n    auto it = MP.find(x);\n    assert(it != MP.end());\n    int\
    \ t = (*it).se;\n    MP.erase(it);\n    if (t == time) return;\n    dat.eb(t,\
    \ time, x);\n  }\n  vc<tuple<int, int, X>> calc_monotone(int time) {\n    for\
    \ (auto&& [x, t]: MP) {\n      if (t == time) continue;\n      dat.eb(t, time,\
    \ x);\n    }\n    return dat;\n  }\n};\n#line 2 \"ds/rollback_array.hpp\"\n\r\n\
    template <typename T>\r\nstruct RollbackArray {\r\n  int N;\r\n  vc<T> dat;\r\n\
    \  vc<pair<int, T>> history;\r\n\r\n  RollbackArray(vc<T> x) : N(len(x)), dat(x)\
    \ {}\r\n  template <typename F>\r\n  RollbackArray(int N, F f) : N(N) {\r\n  \
    \  dat.reserve(N);\r\n    FOR(i, N) dat.eb(f(i));\r\n  }\r\n\r\n  int time() {\
    \ return len(history); }\r\n  void rollback(int t) {\r\n    FOR_R(i, t, time())\
    \ {\r\n      auto& [idx, v] = history[i];\r\n      dat[idx] = v;\r\n    }\r\n\
    \    history.resize(t);\r\n  }\r\n  T get(int idx) { return dat[idx]; }\r\n  void\
    \ set(int idx, T x) {\r\n    history.eb(idx, dat[idx]);\r\n    dat[idx] = x;\r\
    \n  }\r\n\r\n  vc<T> get_all() {\r\n    vc<T> res(N);\r\n    FOR(i, N) res[i]\
    \ = get(i);\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"ds/unionfind/rollback_unionfind.hpp\"\
    \n\r\nstruct RollbackUnionFind {\r\n  RollbackArray<int> dat; // parent or size\r\
    \n\r\n  RollbackUnionFind(int n) : dat(vc<int>(n, -1)) {}\r\n\r\n  int operator[](int\
    \ v) {\r\n    while (dat.get(v) >= 0) v = dat.get(v);\r\n    return v;\r\n  }\r\
    \n\r\n  int size(int v) { return -dat.get((*this)[v]); }\r\n  int time() { return\
    \ dat.time(); }\r\n  void rollback(int t) { dat.rollback(t); }\r\n\r\n  bool merge(int\
    \ a, int b) {\r\n    a = (*this)[a], b = (*this)[b];\r\n    if (a == b) return\
    \ false;\r\n    if (dat.get(a) > dat.get(b)) swap(a, b);\r\n    dat.set(a, dat.get(a)\
    \ + dat.get(b));\r\n    dat.set(b, a);\r\n    return true;\r\n  }\r\n};\r\n#line\
    \ 8 \"test/library_checker/datastructure/add_remove_query.test.cpp\"\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  VEC(ll, A0, N);\n  using P = pair<int, int>;\n\n  vc<int>\
    \ query;\n\n  AddRemove_Query<P, true> X;\n  FOR(Q) {\n    LL(t);\n    if (t ==\
    \ 0) {\n      LL(a, b);\n      if (a > b) swap(a, b);\n      P e = {a, b};\n \
    \     X.add(len(query), e);\n    }\n    if (t == 1) {\n      LL(a, b);\n     \
    \ if (a > b) swap(a, b);\n      P e = {a, b};\n      X.remove(len(query), e);\n\
    \    }\n    if (t == 2) {\n      LL(v, x);\n      P p = {~v, x};\n      X.add(len(query),\
    \ p);\n    }\n    if (t == 3) {\n      LL(v);\n      query.eb(v);\n    }\n  }\n\
    \n  auto upd = X.calc(len(query));\n  Q = len(query);\n  vi ANS(Q);\n  vc<int>\
    \ I(len(upd));\n  iota(all(I), 0);\n\n  RollbackArray<ll> A(A0);\n  RollbackUnionFind\
    \ uf(N);\n\n  auto dfs = [&](auto& dfs, vc<int>& I, int begin, int end) -> void\
    \ {\n    int a_time = A.time();\n    int uf_time = uf.time();\n\n    vc<int> IL,\
    \ IR;\n    int mid = (begin + end) / 2;\n    // \u533A\u9593\u3092\u5B8C\u5168\
    \u306B\u542B\u3080\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\
    \u3002\n    // \u90E8\u5206\u7684\u306B\u4EA4\u308F\u308B\u30AF\u30A8\u30EA\u3092\
    \ J \u306B\u5165\u308C\u308B\n    for (auto&& i: I) {\n      auto [a, b, X] =\
    \ upd[i];\n      if (a <= begin && end <= b) {\n        // update\n        auto\
    \ [u, v] = X;\n        if (u < 0) {\n          int i = uf[~u];\n          A.set(i,\
    \ A.get(i) + v);\n        } else {\n          u = uf[u], v = uf[v];\n        \
    \  if (u != v) {\n            uf.merge(u, v);\n            int r = uf[u];\n  \
    \          A.set(r, A.get(u) + A.get(v));\n          }\n        }\n        continue;\n\
    \      }\n      if (a < mid) IL.eb(i);\n      if (mid < b) IR.eb(i);\n    }\n\
    \    if (begin + 1 == end) {\n      // \u6C42\u5024\u30AF\u30A8\u30EA\n      int\
    \ v = query[begin];\n      ANS[begin] = A.get(uf[v]);\n    } else {\n      dfs(dfs,\
    \ IL, begin, mid);\n      dfs(dfs, IR, mid, end);\n    }\n    A.rollback(a_time);\n\
    \    uf.rollback(uf_time);\n  };\n  dfs(dfs, I, 0, Q);\n\n  for (auto&& x: ANS)\
    \ print(x);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/offline_query/add_remove_query.hpp\"\
    \n#include \"ds/rollback_array.hpp\"\n#include \"ds/unionfind/rollback_unionfind.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A0, N);\n  using P = pair<int, int>;\n\
    \n  vc<int> query;\n\n  AddRemove_Query<P, true> X;\n  FOR(Q) {\n    LL(t);\n\
    \    if (t == 0) {\n      LL(a, b);\n      if (a > b) swap(a, b);\n      P e =\
    \ {a, b};\n      X.add(len(query), e);\n    }\n    if (t == 1) {\n      LL(a,\
    \ b);\n      if (a > b) swap(a, b);\n      P e = {a, b};\n      X.remove(len(query),\
    \ e);\n    }\n    if (t == 2) {\n      LL(v, x);\n      P p = {~v, x};\n     \
    \ X.add(len(query), p);\n    }\n    if (t == 3) {\n      LL(v);\n      query.eb(v);\n\
    \    }\n  }\n\n  auto upd = X.calc(len(query));\n  Q = len(query);\n  vi ANS(Q);\n\
    \  vc<int> I(len(upd));\n  iota(all(I), 0);\n\n  RollbackArray<ll> A(A0);\n  RollbackUnionFind\
    \ uf(N);\n\n  auto dfs = [&](auto& dfs, vc<int>& I, int begin, int end) -> void\
    \ {\n    int a_time = A.time();\n    int uf_time = uf.time();\n\n    vc<int> IL,\
    \ IR;\n    int mid = (begin + end) / 2;\n    // \u533A\u9593\u3092\u5B8C\u5168\
    \u306B\u542B\u3080\u66F4\u65B0\u30AF\u30A8\u30EA\u3092\u51E6\u7406\u3059\u308B\
    \u3002\n    // \u90E8\u5206\u7684\u306B\u4EA4\u308F\u308B\u30AF\u30A8\u30EA\u3092\
    \ J \u306B\u5165\u308C\u308B\n    for (auto&& i: I) {\n      auto [a, b, X] =\
    \ upd[i];\n      if (a <= begin && end <= b) {\n        // update\n        auto\
    \ [u, v] = X;\n        if (u < 0) {\n          int i = uf[~u];\n          A.set(i,\
    \ A.get(i) + v);\n        } else {\n          u = uf[u], v = uf[v];\n        \
    \  if (u != v) {\n            uf.merge(u, v);\n            int r = uf[u];\n  \
    \          A.set(r, A.get(u) + A.get(v));\n          }\n        }\n        continue;\n\
    \      }\n      if (a < mid) IL.eb(i);\n      if (mid < b) IR.eb(i);\n    }\n\
    \    if (begin + 1 == end) {\n      // \u6C42\u5024\u30AF\u30A8\u30EA\n      int\
    \ v = query[begin];\n      ANS[begin] = A.get(uf[v]);\n    } else {\n      dfs(dfs,\
    \ IL, begin, mid);\n      dfs(dfs, IR, mid, end);\n    }\n    A.rollback(a_time);\n\
    \    uf.rollback(uf_time);\n  };\n  dfs(dfs, I, 0, Q);\n\n  for (auto&& x: ANS)\
    \ print(x);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/offline_query/add_remove_query.hpp
  - ds/rollback_array.hpp
  - ds/unionfind/rollback_unionfind.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/add_remove_query.test.cpp
  requiredBy: []
  timestamp: '2022-12-07 00:33:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/add_remove_query.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/add_remove_query.test.cpp
- /verify/test/library_checker/datastructure/add_remove_query.test.cpp.html
title: test/library_checker/datastructure/add_remove_query.test.cpp
---
