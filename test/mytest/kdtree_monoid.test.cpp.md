---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/summax.hpp
    title: alg/monoid/summax.hpp
  - icon: ':question:'
    path: ds/kdtree/kdtree_monoid.hpp
    title: ds/kdtree/kdtree_monoid.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/kdtree_monoid.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n#pragma GCC optimize(\"Ofast\")\n\
    #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing i128 = __int128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr\
    \ u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate\
    \ <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long\
    \ double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi\
    \ = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\n\
    using vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
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
    \ yes(!t); }\n#line 4 \"test/mytest/kdtree_monoid.test.cpp\"\n\n#line 1 \"ds/kdtree/kdtree_monoid.hpp\"\
    \ntemplate <class Monoid, typename XY>\r\nstruct KDTree_Monoid {\r\n  using MX\
    \ = Monoid;\r\n  using X = typename MX::value_type;\r\n  static_assert(MX::commute);\r\
    \n\r\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\
    \u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\
    \u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\
    \r\n  vc<tuple<XY, XY, XY, XY>> closed_range;\r\n  vc<X> dat;\r\n  int n;\r\n\r\
    \n  KDTree_Monoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\r\n    assert(n\
    \ > 0);\r\n    int log = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1\
    \ << (log + 1));\r\n    closed_range.resize(1 << (log + 1));\r\n    build(1, xs,\
    \ ys, vs);\r\n  }\r\n\r\n  void multiply(XY x, XY y, const X& v) { multiply_rec(1,\
    \ x, y, v); }\r\n\r\n  // [xl, xr) x [yl, yr)\r\n  X prod(XY xl, XY xr, XY yl,\
    \ XY yr) {\r\n    assert(xl <= xr && yl <= yr);\r\n    return prod_rec(1, xl,\
    \ xr, yl, yr);\r\n  }\r\n\r\n  X prod_all() { return dat[1]; }\r\n\r\nprivate:\r\
    \n  void build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {\r\n\
    \    int n = len(xs);\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\
    \n    xmin = ymin = infty<XY>;\r\n    xmax = ymax = -infty<XY>;\r\n\r\n    FOR(i,\
    \ n) {\r\n      auto x = xs[i], y = ys[i];\r\n      chmin(xmin, x), chmax(xmax,\
    \ x), chmin(ymin, y), chmax(ymax, y);\r\n    }\r\n    if (xmin == xmax && ymin\
    \ == ymax) {\r\n      X x = MX::unit();\r\n      for (auto&& v: vs) x = MX::op(x,\
    \ v);\r\n      dat[idx] = x;\r\n      return;\r\n    }\r\n\r\n    int m = n /\
    \ 2;\r\n    vc<int> I(n);\r\n    iota(all(I), 0);\r\n    if (divx) {\r\n     \
    \ nth_element(I.begin(), I.begin() + m, I.end(),\r\n                  [xs](int\
    \ i, int j) { return xs[i] < xs[j]; });\r\n    } else {\r\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\r\n                  [ys](int i, int j) { return ys[i]\
    \ < ys[j]; });\r\n    }\r\n    xs = rearrange(xs, I), ys = rearrange(ys, I), vs\
    \ = rearrange(vs, I);\r\n    build(2 * idx + 0, {xs.begin(), xs.begin() + m},\r\
    \n          {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);\r\
    \n    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\r\
    \n          {vs.begin() + m, vs.end()}, !divx);\r\n    dat[idx] = MX::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  inline bool is_leaf(int idx)\
    \ {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    return xmin\
    \ == xmax && ymin == ymax;\r\n  }\r\n\r\n  inline bool isin(XY x, XY y, int idx)\
    \ {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    return (xmin\
    \ <= x && x <= xmax && ymin <= y && y <= ymax);\r\n  }\r\n\r\n  bool multiply_rec(int\
    \ idx, XY x, XY y, X v) {\r\n    if (!isin(x, y, idx)) return false;\r\n    if\
    \ (is_leaf(idx)) {\r\n      dat[idx] = MX::op(dat[idx], v);\r\n      return true;\r\
    \n    }\r\n    bool done = 0;\r\n    if (multiply_rec(2 * idx + 0, x, y, v)) done\
    \ = 1;\r\n    if (!done && multiply_rec(2 * idx + 1, x, y, v)) done = 1;\r\n \
    \   if (done) { dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]); }\r\n \
    \   return done;\r\n  }\r\n\r\n  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2)\
    \ {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    if (x2 <=\
    \ xmin || xmax < x1) return MX::unit();\r\n    if (y2 <= ymin || ymax < y1) return\
    \ MX::unit();\r\n    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) {\
    \ return dat[idx]; }\r\n    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),\r\
    \n                  prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\n};\r\n#line\
    \ 2 \"alg/monoid/summax.hpp\"\n\ntemplate <typename E>\nstruct Monoid_SumMax {\n\
    \  using value_type = pair<E, E>;\n  using X = value_type;\n  static X op(X x,\
    \ X y) { return {x.fi + y.fi, max(x.se, y.se)}; }\n  static X from_element(E e)\
    \ { return {e, e}; }\n  static constexpr X unit() { return {E(0), -infty<E>};\
    \ }\n  static constexpr bool commute = 1;\n};\n#line 2 \"random/base.hpp\"\n\n\
    u64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 8 \"test/mytest/kdtree_monoid.test.cpp\"\
    \n\nvoid test() {\n  ll LIM = RNG(1, 100);\n  int N = RNG(1, 100);\n  using MX\
    \ = Monoid_SumMax<int>;\n\n  vc<int> dat[100][100];\n\n  vc<int> X, Y;\n  vc<typename\
    \ MX::value_type> val;\n  FOR(i, N) {\n    int x = RNG(0, LIM);\n    int y = RNG(0,\
    \ LIM);\n    int v = RNG(0, 100);\n    dat[x][y].eb(v);\n    X.eb(x), Y.eb(y),\
    \ val.eb(v, v);\n  }\n  KDTree_Monoid<MX, int> KDT(X, Y, val);\n\n  int Q = 100;\n\
    \  FOR(Q) {\n    int t = RNG(0, 3);\n    int xl = RNG(0, LIM), xr = RNG(0, LIM),\
    \ yl = RNG(0, LIM), yr = RNG(0, LIM);\n    if (xl > xr) swap(xl, xr);\n    if\
    \ (yl > yr) swap(yl, yr);\n    if (t == 0) {\n      // multiply\n      int k =\
    \ RNG(0, N);\n      int x = X[k], y = Y[k];\n      int v = RNG(0, 100);\n    \
    \  dat[x][y].eb(v);\n      KDT.multiply(x, y, {v, v});\n    }\n    if (t == 1)\
    \ {\n      // prod\n      int sm = 0, mx = MX::unit().se;\n      FOR(i, xl, xr)\
    \ FOR(j, yl, yr) {\n        for (auto&& x: dat[i][j]) sm += x, chmax(mx, x);\n\
    \      }\n      auto res = KDT.prod(xl, xr, yl, yr);\n      assert(res.fi == sm\
    \ && res.se == mx);\n    }\n    if (t == 2) {\n      // prod all\n      int sm\
    \ = 0, mx = MX::unit().se;\n      FOR(i, LIM) FOR(j, LIM) {\n        for (auto&&\
    \ x: dat[i][j]) sm += x, chmax(mx, x);\n      }\n      auto res = KDT.prod_all();\n\
    \      assert(res.fi == sm && res.se == mx);\n    }\n  }\n}\n\nvoid solve() {\n\
    \  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  FOR(100) test();\n  solve();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"ds/kdtree/kdtree_monoid.hpp\"\n#include\
    \ \"alg/monoid/summax.hpp\"\n#include \"random/base.hpp\"\n\nvoid test() {\n \
    \ ll LIM = RNG(1, 100);\n  int N = RNG(1, 100);\n  using MX = Monoid_SumMax<int>;\n\
    \n  vc<int> dat[100][100];\n\n  vc<int> X, Y;\n  vc<typename MX::value_type> val;\n\
    \  FOR(i, N) {\n    int x = RNG(0, LIM);\n    int y = RNG(0, LIM);\n    int v\
    \ = RNG(0, 100);\n    dat[x][y].eb(v);\n    X.eb(x), Y.eb(y), val.eb(v, v);\n\
    \  }\n  KDTree_Monoid<MX, int> KDT(X, Y, val);\n\n  int Q = 100;\n  FOR(Q) {\n\
    \    int t = RNG(0, 3);\n    int xl = RNG(0, LIM), xr = RNG(0, LIM), yl = RNG(0,\
    \ LIM), yr = RNG(0, LIM);\n    if (xl > xr) swap(xl, xr);\n    if (yl > yr) swap(yl,\
    \ yr);\n    if (t == 0) {\n      // multiply\n      int k = RNG(0, N);\n     \
    \ int x = X[k], y = Y[k];\n      int v = RNG(0, 100);\n      dat[x][y].eb(v);\n\
    \      KDT.multiply(x, y, {v, v});\n    }\n    if (t == 1) {\n      // prod\n\
    \      int sm = 0, mx = MX::unit().se;\n      FOR(i, xl, xr) FOR(j, yl, yr) {\n\
    \        for (auto&& x: dat[i][j]) sm += x, chmax(mx, x);\n      }\n      auto\
    \ res = KDT.prod(xl, xr, yl, yr);\n      assert(res.fi == sm && res.se == mx);\n\
    \    }\n    if (t == 2) {\n      // prod all\n      int sm = 0, mx = MX::unit().se;\n\
    \      FOR(i, LIM) FOR(j, LIM) {\n        for (auto&& x: dat[i][j]) sm += x, chmax(mx,\
    \ x);\n      }\n      auto res = KDT.prod_all();\n      assert(res.fi == sm &&\
    \ res.se == mx);\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n\
    }\n\nsigned main() {\n  FOR(100) test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/kdtree/kdtree_monoid.hpp
  - alg/monoid/summax.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/kdtree_monoid.test.cpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/kdtree_monoid.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/kdtree_monoid.test.cpp
- /verify/test/mytest/kdtree_monoid.test.cpp.html
title: test/mytest/kdtree_monoid.test.cpp
---
