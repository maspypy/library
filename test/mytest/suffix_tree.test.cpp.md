---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: alg/monoid/min_idx.hpp
    title: alg/monoid/min_idx.hpp
  - icon: ':question:'
    path: ds/disjointsparse/disjointsparse.hpp
    title: ds/disjointsparse/disjointsparse.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: string/suffix_array.hpp
    title: string/suffix_array.hpp
  - icon: ':x:'
    path: string/suffix_tree.hpp
    title: string/suffix_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/suffix_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
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
    \ UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    }\n#endif\n#line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\
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
    \ yes(!t); }\n#line 5 \"test/mytest/suffix_tree.test.cpp\"\n\n#line 1 \"string/suffix_tree.hpp\"\
    \n\n#line 2 \"string/suffix_array.hpp\"\n\n#line 2 \"alg/monoid/min.hpp\"\n\r\n\
    template <class X>\r\nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return min(x, y); }\r\n  static\
    \ constexpr X unit() { return numeric_limits<X>::max(); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"ds/disjointsparse/disjointsparse.hpp\"\
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
    \ len(SA);\n    if (i == j) return n - i;\n    if (!build_ds) {\n      build_ds\
    \ = 1;\n      seg.build(LCP);\n    }\n    i = ISA[i], j = ISA[j];\n    if (i >\
    \ j) swap(i, j);\n    return seg.prod(i, j);\n  }\n\nprivate:\n  void induced_sort(const\
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
    \     LCP[ISA[i]] = k;\n    }\n    LCP.resize(n - 1);\n  }\n};\n#line 2 \"alg/monoid/min_idx.hpp\"\
    \n\r\ntemplate <typename T, bool tie_is_left = true>\r\nstruct Monoid_Min_Idx\
    \ {\r\n  using value_type = pair<T, int>;\r\n  using X = value_type;\r\n  static\
    \ constexpr bool is_small(const X& x, const X& y) {\r\n    if (x.fi < y.fi) return\
    \ true;\r\n    if (x.fi > y.fi) return false;\r\n    return (tie_is_left ? (x.se\
    \ < y.se) : (x.se >= y.se));\r\n  }\r\n  static X op(X x, X y) { return (is_small(x,\
    \ y) ? x : y); }\r\n  static constexpr X unit() { return {numeric_limits<T>::max(),\
    \ -1}; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/segtree/segtree.hpp\"\
    \n\ntemplate <class Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X\
    \ = typename MX::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int n,\
    \ log, size;\n\n  SegTree() {}\n  SegTree(int n) { build(n); }\n  template <typename\
    \ F>\n  SegTree(int n, F f) {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v)\
    \ { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) -> X { return\
    \ MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v), [&](int\
    \ i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    dat.assign(size << 1, MX::unit());\n    FOR(i, n) dat[size + i]\
    \ = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  X get(int i) { return dat[size\
    \ + i]; }\n  vc<X> get_all() { return {dat.begin() + size, dat.begin() + size\
    \ + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i\
    \ + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n    dat[i +=\
    \ size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int i, const\
    \ X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F& check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\u30C9\
    \u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r} A[i xor x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
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
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 6 \"string/suffix_tree.hpp\"\
    \n\n// https://twitter.com/maspy_stars/status/1565901414236205057?s=20&t=S2Tu6ayozHcakxai8dmh4g\n\
    // \u5404\u30CE\u30FC\u30C9\u306F\u3001suffix array \u3067\u306E\u9577\u65B9\u5F62\
    \u9818\u57DF\u3068\u898B\u306A\u3057\u3066\u3001\n// \u30B0\u30E9\u30D5\u304A\u3088\
    \u3073\u3001\u9818\u57DF\u30C7\u30FC\u30BF\u3092\u4F5C\u308B\u3002\n// sample:\
    \ test/my_test/suffix_tree.test.cpp\npair<Graph<int, 1>, vc<tuple<int, int, int,\
    \ int>>> suffix_tree(\n    Suffix_Array& X) {\n  auto SA = X.SA;\n  auto ISA =\
    \ X.ISA;\n  auto LCP = X.LCP;\n\n  int N = len(SA);\n\n  using Mono = Monoid_Min_Idx<int,\
    \ 1>;\n\n  SegTree<Mono> seg(N - 1, [&](int i) -> Mono::X { return {LCP[i], i};\
    \ });\n\n  using T = tuple<int, int, int, int>;\n  vc<T> dat;\n  Graph<int, 1>\
    \ G;\n  dat.eb(0, N, 0, 0);\n\n  auto dfs = [&](auto& dfs, int p, int l, int r,\
    \ int h) -> void {\n    if (r == l + 1) {\n      int i = SA[l];\n      int sz\
    \ = N - i;\n      if (h == sz) return;\n      int k = len(dat);\n      dat.eb(l,\
    \ l + 1, h, sz);\n      G.resize(k + 1);\n      G.add(p, k);\n      return;\n\
    \    }\n    auto [lcp, i] = seg.prod(l, r - 1);\n    if (lcp == h) {\n      dfs(dfs,\
    \ p, l, i + 1, h);\n      dfs(dfs, p, i + 1, r, h);\n      return;\n    }\n  \
    \  int k = len(dat);\n    dat.eb(l, r, h, lcp);\n    G.resize(k + 1);\n    G.add(p,\
    \ k);\n    dfs(dfs, k, l, r, lcp);\n  };\n  dfs(dfs, 0, 0, N, 0);\n  G.build();\n\
    \  return {G, dat};\n}\n#line 7 \"test/mytest/suffix_tree.test.cpp\"\n\n/*\nS\
    \ = aabbabbaa\n\nsuffix array\na--------\naa-------\naabbabbaa\nabbaa----\nabbabbaa-\n\
    baa------\nbabbaa---\nbbaa-----\nbbabbaa--\n\nsuffix tree \u306E node \u306F\u3053\
    \u306E\u9577\u65B9\u5F62\u9818\u57DF\u3092\u8868\u3059\n1--------\n12-------\n\
    123333333\n14445----\n14446666-\n789------\n780000---\n7112-----\n7113-----\n\
    */\nvoid test() {\n  string S = \"aabbabbaa\";\n  SuffixArray X(S);\n  auto [G,\
    \ dat] = suffix_tree(X);\n  using T = tuple<int, int, int, int>;\n  auto check_dat\
    \ = [&](T t, int xl, int xr, int yl, int yr) -> void {\n    auto [a, b, c, d]\
    \ = t;\n    assert(a == xl && b == yl && c == xr && d == yr);\n  };\n  auto check_edge\
    \ = [&](auto e, int frm, int to) -> void {\n    assert(e.frm == frm && e.to ==\
    \ to);\n  };\n  check_dat(dat[0], 0, 0, 9, 0);\n  check_dat(dat[1], 0, 0, 5, 1);\n\
    \  check_dat(dat[2], 1, 1, 3, 2);\n  check_dat(dat[3], 2, 2, 3, 9);\n  check_dat(dat[4],\
    \ 3, 1, 5, 4);\n  check_dat(dat[5], 3, 4, 4, 5);\n  check_dat(dat[6], 4, 4, 5,\
    \ 8);\n  check_dat(dat[7], 5, 0, 9, 1);\n  check_dat(dat[8], 5, 1, 7, 2);\n  check_dat(dat[9],\
    \ 5, 2, 6, 3);\n  check_dat(dat[10], 6, 2, 7, 6);\n  check_dat(dat[11], 7, 1,\
    \ 9, 3);\n  check_dat(dat[12], 7, 3, 8, 4);\n  check_dat(dat[13], 8, 3, 9, 7);\n\
    \  check_edge(G.edges[0], 0, 1);\n  check_edge(G.edges[1], 1, 2);\n  check_edge(G.edges[2],\
    \ 2, 3);\n  check_edge(G.edges[3], 1, 4);\n  check_edge(G.edges[4], 4, 5);\n \
    \ check_edge(G.edges[5], 4, 6);\n  check_edge(G.edges[6], 0, 7);\n  check_edge(G.edges[7],\
    \ 7, 8);\n  check_edge(G.edges[8], 8, 9);\n  check_edge(G.edges[9], 8, 10);\n\
    \  check_edge(G.edges[10], 7, 11);\n  check_edge(G.edges[11], 11, 12);\n  check_edge(G.edges[12],\
    \ 11, 13);\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main()\
    \ {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\
    \n  test();\n\n  ll T = 1;\n  FOR(T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"string/suffix_tree.hpp\"\
    \n\n/*\nS = aabbabbaa\n\nsuffix array\na--------\naa-------\naabbabbaa\nabbaa----\n\
    abbabbaa-\nbaa------\nbabbaa---\nbbaa-----\nbbabbaa--\n\nsuffix tree \u306E node\
    \ \u306F\u3053\u306E\u9577\u65B9\u5F62\u9818\u57DF\u3092\u8868\u3059\n1--------\n\
    12-------\n123333333\n14445----\n14446666-\n789------\n780000---\n7112-----\n\
    7113-----\n*/\nvoid test() {\n  string S = \"aabbabbaa\";\n  SuffixArray X(S);\n\
    \  auto [G, dat] = suffix_tree(X);\n  using T = tuple<int, int, int, int>;\n \
    \ auto check_dat = [&](T t, int xl, int xr, int yl, int yr) -> void {\n    auto\
    \ [a, b, c, d] = t;\n    assert(a == xl && b == yl && c == xr && d == yr);\n \
    \ };\n  auto check_edge = [&](auto e, int frm, int to) -> void {\n    assert(e.frm\
    \ == frm && e.to == to);\n  };\n  check_dat(dat[0], 0, 0, 9, 0);\n  check_dat(dat[1],\
    \ 0, 0, 5, 1);\n  check_dat(dat[2], 1, 1, 3, 2);\n  check_dat(dat[3], 2, 2, 3,\
    \ 9);\n  check_dat(dat[4], 3, 1, 5, 4);\n  check_dat(dat[5], 3, 4, 4, 5);\n  check_dat(dat[6],\
    \ 4, 4, 5, 8);\n  check_dat(dat[7], 5, 0, 9, 1);\n  check_dat(dat[8], 5, 1, 7,\
    \ 2);\n  check_dat(dat[9], 5, 2, 6, 3);\n  check_dat(dat[10], 6, 2, 7, 6);\n \
    \ check_dat(dat[11], 7, 1, 9, 3);\n  check_dat(dat[12], 7, 3, 8, 4);\n  check_dat(dat[13],\
    \ 8, 3, 9, 7);\n  check_edge(G.edges[0], 0, 1);\n  check_edge(G.edges[1], 1, 2);\n\
    \  check_edge(G.edges[2], 2, 3);\n  check_edge(G.edges[3], 1, 4);\n  check_edge(G.edges[4],\
    \ 4, 5);\n  check_edge(G.edges[5], 4, 6);\n  check_edge(G.edges[6], 0, 7);\n \
    \ check_edge(G.edges[7], 7, 8);\n  check_edge(G.edges[8], 8, 9);\n  check_edge(G.edges[9],\
    \ 8, 10);\n  check_edge(G.edges[10], 7, 11);\n  check_edge(G.edges[11], 11, 12);\n\
    \  check_edge(G.edges[12], 11, 13);\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a\
    \ + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  test();\n\n  ll T = 1;\n  FOR(T) solve();\n\n\
    \  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - string/suffix_tree.hpp
  - string/suffix_array.hpp
  - alg/monoid/min.hpp
  - ds/disjointsparse/disjointsparse.hpp
  - alg/monoid/min_idx.hpp
  - ds/segtree/segtree.hpp
  - graph/base.hpp
  isVerificationFile: true
  path: test/mytest/suffix_tree.test.cpp
  requiredBy: []
  timestamp: '2022-12-15 08:14:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/suffix_tree.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/suffix_tree.test.cpp
- /verify/test/mytest/suffix_tree.test.cpp.html
title: test/mytest/suffix_tree.test.cpp
---
