---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/sum_add.hpp
    title: alg/acted_monoid/sum_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: mod/factorial.hpp
    title: mod/factorial.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':heavy_check_mark:'
    path: seq/cartesian_tree.hpp
    title: seq/cartesian_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc234/tasks/abc234_g
    links:
    - https://atcoder.jp/contests/abc234/tasks/abc234_g
  bundledCode: "#line 1 \"test_atcoder/abc234g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc234/tasks/abc234_g\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \ yes(!t); }\n#line 1 \"seq/cartesian_tree.hpp\"\n/*\r\n\u8F9E\u66F8\u9806\u3067\
    \u9AD8\u3055\u3092 unique \u3057\u3066\u3001\u6728\u306B\u3057\u3066\u3044\u308B\
    \u3002\r\n\u6975\u5927\u9577\u65B9\u5F62\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3067\
    \u7DDA\u5F62\u6642\u9593\u69CB\u7BC9\u3002\r\n*/\r\ntemplate <typename T, bool\
    \ IS_MIN>\r\nstruct CartesianTree {\r\n  int n;\r\n  vc<T>& A;\r\n  vc<pair<int,\
    \ int>> range;\r\n  vc<int> lch, rch, par;\r\n\r\n  CartesianTree(vc<T>& A) :\
    \ n(len(A)), A(A) {\r\n    range.assign(n, {-1, -1});\r\n    lch.assign(n, -1);\r\
    \n    rch.assign(n, -1);\r\n    par.assign(n, -1);\r\n    if (n == 1) {\r\n  \
    \    range[0] = {0, 1};\r\n      return;\r\n    }\r\n    auto is_sm = [&](int\
    \ i, int j) -> bool {\r\n      if (IS_MIN) return (A[i] < A[j]) || (A[i] == A[j]\
    \ && i < j);\r\n      return (A[i] > A[j]) || (A[i] == A[j] && i < j);\r\n   \
    \ };\r\n    vc<int> st;\r\n    FOR(i, n) {\r\n      while (!st.empty() && is_sm(i,\
    \ st.back())) {\r\n        lch[i] = st.back();\r\n        st.pop_back();\r\n \
    \     }\r\n      range[i].fi = (st.empty() ? 0 : st.back() + 1);\r\n      st.eb(i);\r\
    \n    }\r\n    st.clear();\r\n    FOR_R(i, n) {\r\n      while (!st.empty() &&\
    \ is_sm(i, st.back())) {\r\n        rch[i] = st.back();\r\n        st.pop_back();\r\
    \n      }\r\n      range[i].se = (st.empty() ? n : st.back());\r\n      st.eb(i);\r\
    \n    }\r\n    FOR(i, n) if (lch[i] != -1) par[lch[i]] = i;\r\n    FOR(i, n) if\
    \ (rch[i] != -1) par[rch[i]] = i;\r\n  }\r\n\r\n  // (l, r, h)\r\n  tuple<int,\
    \ int, T> maximum_rectangle(int i) {\r\n    auto [l, r] = range[i];\r\n    return\
    \ {l, r, A[i]};\r\n  }\r\n\r\n  // (l, r, h)\r\n  T max_rectangle_area() {\r\n\
    \    assert(IS_MIN);\r\n    T res = 0;\r\n    FOR(i, n) {\r\n      auto [l, r,\
    \ h] = maximum_rectangle(i);\r\n      chmax(res, (r - l) * h);\r\n    }\r\n  \
    \  return res;\r\n  }\r\n\r\n  ll count_subrectangle(bool baseline) {\r\n    assert(IS_MIN);\r\
    \n    ll res = 0;\r\n    FOR(i, n) {\r\n      auto [l, r, h] = maximum_rectangle(i);\r\
    \n      ll x = (baseline ? h : h * (h + 1) / 2);\r\n      res += x * (i - l +\
    \ 1) * (r - i);\r\n    }\r\n    return res;\r\n  }\r\n};\r\n#line 2 \"ds/segtree/lazy_segtree.hpp\"\
    \n\ntemplate <typename ActedMonoid>\nstruct Lazy_SegTree {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int\
    \ n) { build(n); }\n  template <typename F>\n  Lazy_SegTree(int n, F f) {\n  \
    \  build(n, f);\n  }\n  Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    laz.assign(size, MA::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i,\
    \ 1, size) update(i);\n  }\n\n  void update(int k) { dat[k] = MX::op(dat[2 * k],\
    \ dat[2 * k + 1]); }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    dat[p]\
    \ = x;\n    for (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int\
    \ p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n  vc<X> get_all() {\n \
    \   FOR(k, 1, size) { push(k); }\n    return {dat.begin() + size, dat.begin()\
    \ + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r &&\
    \ r <= n);\n    if (l == r) return MX::unit();\n    l += size, r += size;\n  \
    \  for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >>\
    \ i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X xl =\
    \ MX::unit(), xr = MX::unit();\n    while (l < r) {\n      if (l & 1) xl = MX::op(xl,\
    \ dat[l++]);\n      if (r & 1) xr = MX::op(dat[--r], xr);\n      l >>= 1, r >>=\
    \ 1;\n    }\n    return MX::op(xl, xr);\n  }\n\n  X prod_all() { return dat[1];\
    \ }\n\n  void apply(int l, int r, A a) {\n    assert(0 <= l && l <= r && r <=\
    \ n);\n    if (l == r) return;\n    l += size, r += size;\n    for (int i = log;\
    \ i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r\
    \ >> i) << i) != r) push((r - 1) >> i);\n    }\n    int l2 = l, r2 = r;\n    while\
    \ (l < r) {\n      if (l & 1) apply_at(l++, a);\n      if (r & 1) apply_at(--r,\
    \ a);\n      l >>= 1, r >>= 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1;\
    \ i <= log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if\
    \ (((r >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  template <typename\
    \ F>\n  int max_right(const F check, int l) {\n    assert(0 <= l && l <= n);\n\
    \    assert(check(MX::unit()));\n    if (l == n) return n;\n    l += size;\n \
    \   for (int i = log; i >= 1; i--) push(l >> i);\n    X sm = MX::unit();\n   \
    \ do {\n      while (l % 2 == 0) l >>= 1;\n      if (!check(MX::op(sm, dat[l])))\
    \ {\n        while (l < size) {\n          push(l);\n          l = (2 * l);\n\
    \          if (check(MX::op(sm, dat[l]))) { sm = MX::op(sm, dat[l++]); }\n   \
    \     }\n        return l - size;\n      }\n      sm = MX::op(sm, dat[l++]);\n\
    \    } while ((l & -l) != l);\n    return n;\n  }\n\n  template <typename F>\n\
    \  int min_left(const F check, int r) {\n    assert(0 <= r && r <= n);\n    assert(check(MX::unit()));\n\
    \    if (r == 0) return 0;\n    r += size;\n    for (int i = log; i >= 1; i--)\
    \ push((r - 1) >> i);\n    X sm = MX::unit();\n    do {\n      r--;\n      while\
    \ (r > 1 && (r % 2)) r >>= 1;\n      if (!check(MX::op(dat[r], sm))) {\n     \
    \   while (r < size) {\n          push(r);\n          r = (2 * r + 1);\n     \
    \     if (check(MX::op(dat[r], sm))) { sm = MX::op(dat[r--], sm); }\n        }\n\
    \        return r + 1 - size;\n      }\n      sm = MX::op(dat[r], sm);\n    }\
    \ while ((r & -r) != r);\n    return 0;\n  }\n\nprivate:\n  void apply_at(int\
    \ k, A a) {\n    ll sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k],\
    \ a, sz);\n    if (k < size) laz[k] = MA::op(laz[k], a);\n  }\n  void push(int\
    \ k) {\n    if (laz[k] == MA::unit()) return;\n    apply_at(2 * k, laz[k]), apply_at(2\
    \ * k + 1, laz[k]);\n    laz[k] = MA::unit();\n  }\n};\n#line 2 \"alg/monoid/add.hpp\"\
    \n\r\ntemplate <typename X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\
    \n  static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\
    \n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 2 \"alg/acted_monoid/sum_add.hpp\"\n\r\ntemplate <typename E>\r\n\
    struct ActedMonoid_Sum_Add {\r\n  using Monoid_X = Monoid_Add<E>;\r\n  using Monoid_A\
    \ = Monoid_Add<E>;\r\n  using X = typename Monoid_X::value_type;\r\n  using A\
    \ = typename Monoid_A::value_type;\r\n  static constexpr X act(const X &x, const\
    \ A &a, const ll &size) {\r\n    return x + a * E(size);\r\n  }\r\n};\r\n#line\
    \ 1 \"mod/factorial.hpp\"\n\ntemplate <typename mint>\nmint inv(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0\
    \ <= n);\n  if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint(q));\n  }\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  static vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat)\
    \ - 1] * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  assert(-1 <=\
    \ n && n < mod);\n  static vector<mint> dat = {1, 1};\n  if (n == -1) return mint(0);\n\
    \  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return\
    \ dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n\
    \  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint,\
    \ class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n\
    \  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\
    \ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint> C;\n\
    \  static int H = 0, W = 0;\n  auto calc = [&](int i, int j) -> mint {\n    if\
    \ (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j] + (j ?\
    \ C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k\
    \ + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n    W = k +\
    \ 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n   \
    \   C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n    }\n    H =\
    \ n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool large = false,\
    \ bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n  if (k < 0 ||\
    \ n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n  if (!large) return\
    \ multinomial<mint>(n, k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i,\
    \ k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename\
    \ mint, bool large = false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0\
    \ <= k && k <= n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n\
    \ - k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\
    \u8A08\u7B97\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n\
    \  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large,\
    \ dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\n\
    struct modint {\n  int val;\n  constexpr modint(const ll val = 0) noexcept\n \
    \     : val(val >= 0 ? val % mod : (mod - (-val) % mod) % mod) {}\n  bool operator<(const\
    \ modint &other) const {\n    return val < other.val;\n  } // To use std::map\n\
    \  modint &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val -=\
    \ mod;\n    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if\
    \ ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint\
    \ &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n\
    \    return *this;\n  }\n  modint &operator/=(const modint &p) {\n    *this *=\
    \ p.inverse();\n    return *this;\n  }\n  modint operator-() const { return modint(-val);\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 998244353) return {23, 31};\n    if (mod == 1045430273) return {20, 363};\n\
    \    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881) return\
    \ {20, 2789};\n    return {-1, -1};\n  }\n};\n\nstruct ArbitraryModInt {\n  static\
    \ constexpr bool is_modint = true;\n  int val;\n  ArbitraryModInt() : val(0) {}\n\
    \  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n          \
    \         : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
    \ ArbitraryModInt &other) const {\n    return val < other.val;\n  } // To use\
    \ std::map<ArbitraryModInt, T>\n  static int &get_mod() {\n    static int mod\
    \ = 0;\n    return mod;\n  }\n  static void set_mod(int md) { get_mod() = md;\
    \ }\n  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {\n    if ((val +=\
    \ p.val) >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt\
    \ &operator-=(const ArbitraryModInt &p) {\n    if ((val += get_mod() - p.val)\
    \ >= get_mod()) val -= get_mod();\n    return *this;\n  }\n  ArbitraryModInt &operator*=(const\
    \ ArbitraryModInt &p) {\n    long long a = (long long)val * p.val;\n    int xh\
    \ = (int)(a >> 32), xl = (int)a, d, m;\n    asm(\"divl %4; \\n\\t\" : \"=a\"(d),\
    \ \"=d\"(m) : \"d\"(xh), \"a\"(xl), \"r\"(get_mod()));\n    val = m;\n    return\
    \ *this;\n  }\n  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {\n   \
    \ *this *= p.inverse();\n    return *this;\n  }\n  ArbitraryModInt operator-()\
    \ const { return ArbitraryModInt(get_mod() - val); }\n  ArbitraryModInt operator+(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) += p;\n  }\n\
    \  ArbitraryModInt operator-(const ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this)\
    \ -= p;\n  }\n  ArbitraryModInt operator*(const ArbitraryModInt &p) const {\n\
    \    return ArbitraryModInt(*this) *= p;\n  }\n  ArbitraryModInt operator/(const\
    \ ArbitraryModInt &p) const {\n    return ArbitraryModInt(*this) /= p;\n  }\n\
    \  bool operator==(const ArbitraryModInt &p) const { return val == p.val; }\n\
    \  bool operator!=(const ArbitraryModInt &p) const { return val != p.val; }\n\
    \  ArbitraryModInt inverse() const {\n    int a = val, b = get_mod(), u = 1, v\
    \ = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u\
    \ -= t * v, v);\n    }\n    return ArbitraryModInt(u);\n  }\n  ArbitraryModInt\
    \ pow(int64_t n) const {\n    assert(n >= 0);\n    ArbitraryModInt ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n  static constexpr\
    \ pair<int, int> ntt_info() { return {-1, -1}; }\n};\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\nusing amint = ArbitraryModInt;\n\nstruct\
    \ has_mod_impl {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n#line 8 \"test_atcoder/abc234g.test.cpp\"\n\nusing mint = modint998;\n\n\
    void solve() {\n  LL(N);\n  VEC(int, A, N);\n  CartesianTree<int, 1> X1(A);\n\
    \  CartesianTree<int, 0> X2(A);\n  Lazy_SegTree<ActedMonoid_Sum_Add<mint>> seg(N\
    \ + 1);\n  seg.set(0, mint(1));\n\n  FOR(i, N) {\n    auto [L1, R1] = X1.range[i];\n\
    \    mint x1 = seg.prod(L1, i + 1);\n    seg.apply(i + 1, R1 + 1, -x1 * mint(A[i]));\n\
    \n    auto [L2, R2] = X2.range[i];\n    mint x2 = seg.prod(L2, i + 1);\n    seg.apply(i\
    \ + 1, R2 + 1, x2 * mint(A[i]));\n  }\n  print(seg.get(N));\n}\n\nsigned main()\
    \ {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc234/tasks/abc234_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"seq/cartesian_tree.hpp\"\
    \n#include \"ds/segtree/lazy_segtree.hpp\"\n#include \"alg/acted_monoid/sum_add.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nvoid solve() {\n \
    \ LL(N);\n  VEC(int, A, N);\n  CartesianTree<int, 1> X1(A);\n  CartesianTree<int,\
    \ 0> X2(A);\n  Lazy_SegTree<ActedMonoid_Sum_Add<mint>> seg(N + 1);\n  seg.set(0,\
    \ mint(1));\n\n  FOR(i, N) {\n    auto [L1, R1] = X1.range[i];\n    mint x1 =\
    \ seg.prod(L1, i + 1);\n    seg.apply(i + 1, R1 + 1, -x1 * mint(A[i]));\n\n  \
    \  auto [L2, R2] = X2.range[i];\n    mint x2 = seg.prod(L2, i + 1);\n    seg.apply(i\
    \ + 1, R2 + 1, x2 * mint(A[i]));\n  }\n  print(seg.get(N));\n}\n\nsigned main()\
    \ {\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - seq/cartesian_tree.hpp
  - ds/segtree/lazy_segtree.hpp
  - alg/acted_monoid/sum_add.hpp
  - alg/monoid/add.hpp
  - mod/modint.hpp
  - mod/factorial.hpp
  isVerificationFile: true
  path: test_atcoder/abc234g.test.cpp
  requiredBy: []
  timestamp: '2023-02-24 07:14:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_atcoder/abc234g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc234g.test.cpp
- /verify/test_atcoder/abc234g.test.cpp.html
title: test_atcoder/abc234g.test.cpp
---
