---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':x:'
    path: ds/intervals.hpp
    title: ds/intervals.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_d
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_d
  bundledCode: "#line 1 \"test/atcoder/abc256d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_d\"\
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
    \ \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\n\r\n\
    namespace fastio {\r\n// \u30AF\u30E9\u30B9\u304C read(), print() \u3092\u6301\
    \u3063\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u30E1\u30BF\u95A2\
    \u6570\r\nstruct has_write_impl {\r\n  template <class T>\r\n  static auto check(T\
    \ &&x) -> decltype(x.write(), std::true_type{});\r\n\r\n  template <class T>\r\
    \n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate <class T>\r\
    \nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
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
    \ yes(!t); }\n#line 1 \"ds/intervals.hpp\"\n// https://codeforces.com/contest/1638/problem/E\n\
    // https://codeforces.com/contest/897/problem/E\n// \u6301\u3064\u5024\u306E\u30BF\
    \u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n// \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\u5B9A\u3059\u308B\ntemplate\
    \ <typename T = ll, typename X = ll>\nstruct Intervals {\n  static constexpr X\
    \ LLIM = numeric_limits<X>::lowest();\n  static constexpr X RLIM = numeric_limits<X>::max();\n\
    \  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\u500B\
    \u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  X total_len;\n  map<X,\
    \ T> dat;\n\n  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0)\
    \ {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n  }\n\n  tuple<X, X,\
    \ T> get(X x) {\n    auto it = dat.upper_bound(x);\n    X r = (*it).fi;\n    auto\
    \ [l, t] = *prev(it);\n    return {l, r, t};\n  }\n\n  template <typename ADD,\
    \ typename RM>\n  void set(X L, X R, T t, ADD& add_f, RM& rm_f) {\n    if (L ==\
    \ R) return;\n    assert(L < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\
    \u66F4\u3059\u308B\n    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\
    \u308A\u5408\u3046\u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<X, X, T>>\
    \ tmp;\n    auto it = prev(dat.lower_bound(L));\n    while (1) {\n      auto [l,\
    \ t] = *it;\n      if (R < l) break;\n      it = next(it);\n      X r = (*it).fi;\n\
    \      tmp.eb(l, r, t);\n    }\n    auto [lx, _, lt] = tmp[0];\n    auto [__,\
    \ rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\u3048\u305A\u5168\u90E8\u524A\
    \u9664\n    for (auto&& [l, r, t]: tmp) {\n      dat.erase(l);\n      if (t ==\
    \ none_val) continue;\n      total_num--;\n      total_len -= r - l;\n      rm_f(l,\
    \ r, t);\n    }\n    if (lt == t) chmin(L, lx);\n    if (rt == t) chmax(R, rx);\n\
    \    if (lx < L) {\n      // [lx, L)\n      dat[lx] = lt;\n      if (lt != none_val)\
    \ {\n        total_num++;\n        total_len += L - lx;\n        add_f(lx, L,\
    \ lt);\n      }\n    }\n    if (R < rx) {\n      // [R, rx)\n      dat[R] = rt;\n\
    \      if (rt != none_val) {\n        total_num++;\n        total_len += rx -\
    \ R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    dat[L] = t;\n\
    \    if (t != none_val) {\n      total_num++;\n      total_len += R - L;\n   \
    \   add_f(L, R, t);\n    }\n  }\n\n  void set(X L, X R, T t = 1) {\n    auto f\
    \ = [&](X L, X R, T t) -> void {};\n    set(L, R, t, f, f);\n  }\n\n  void erase(X\
    \ L, X R) {\n    auto f = [&](X L, X R, T t) -> void {};\n    set(L, R, none_val,\
    \ f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\u30BF (l, r, t) \u3092\u5168\
    \u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<X, X, T>> get(X L, X R) {\n    vc<tuple<X,\
    \ X, T>> res;\n    auto it = dat.lower_bound(L);\n    if(it != dat.begin()) it\
    \ = prev(it);\n    while (1) {\n      auto [l, t] = *it;\n      if (R <= l) break;\n\
    \      it = next(it);\n      X r = (*it).fi;\n      X l0 = max(l, L);\n      X\
    \ r0 = min(r, R);\n      if (l0 < r0) res.eb(l0, r0, t);\n    }\n    return res;\n\
    \  }\n\n  vc<tuple<X, X, T>> get_all() {\n    return get(LLIM, RLIM);\n  }\n\n\
    \  void debug() {\n    auto it = dat.begin();\n    print(\"Intervals\");\n   \
    \ print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n   \
    \ while (1) {\n      auto [l, t] = *it;\n      ++it;\n      if (it == dat.end())\
    \ break;\n      X r = (*it).fi;\n      print(\"l, r, t\", l, r, t);\n    }\n \
    \ }\n};\n\n\n#line 1 \"ds/fastset.hpp\"\n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\
    \n[]\u3067\u306E\u5B58\u5728\u5224\u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet\
    \ {\r\n  using uint = unsigned;\r\n  using ull = unsigned long long;\r\n\r\n \
    \ int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull x) { return\
    \ __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n  int n, lg;\r\
    \n  vector<vector<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do {\r\n  \
    \    seg.push_back(vector<ull>((_n + B - 1) / B));\r\n      _n = (_n + B - 1)\
    \ / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n  }\r\n  bool\
    \ operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }\r\n\
    \  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void erase(int\
    \ i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL\
    \ << (i % B));\r\n      if (seg[h][i / B]) break;\r\n      i /= B;\r\n    }\r\n\
    \  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int next(int i)\
    \ {\r\n    for (int h = 0; h < lg; h++) {\r\n      if (i / B == seg[h].size())\
    \ break;\r\n      ull d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n   \
    \     i = i / B + 1;\r\n        continue;\r\n      }\r\n      // find\r\n    \
    \  i += bsf(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\
    \n        i += bsf(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n\
    \    return n;\r\n  }\r\n\r\n  // x\u4EE5\u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1\u3002\r\n  int\
    \ prev(int i) {\r\n    if (i < 0) return -1;\r\n    if (i >= n) i = n - 1;\r\n\
    \    for (int h = 0; h < lg; h++) {\r\n      if (i == -1) break;\r\n      ull\
    \ d = seg[h][i / B] << (63 - i % 64);\r\n      if (!d) {\r\n        i = i / B\
    \ - 1;\r\n        continue;\r\n      }\r\n      // find\r\n      i += bsr(d) -\
    \ (B - 1);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n\
    \        i += bsr(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n \
    \   return -1;\r\n  }\r\n\r\n  // [l, r) \u5185\u306E\u8981\u7D20\u3092\u5168\u90E8\
    \u96C6\u3081\u308B\r\n  vector<int> collect(int l, int r) {\r\n    vector<int>\
    \ res;\r\n    int x = l - 1;\r\n    while (1) {\r\n      x = next(x + 1);\r\n\
    \      if (x >= r) break;\r\n      res.emplace_back(x);\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  void debug() {\r\n    string s;\r\n    for (int i = 0;\
    \ i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n    print(s);\r\n  }\r\n};\r\n\
    #line 129 \"ds/intervals.hpp\"\n\n// FastSet \u3067\u9AD8\u901F\u5316\u3057\u305F\
    \u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast {\n  const int LLIM,\
    \ RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\
    \u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  int total_len;\n\
    \  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n      : LLIM(0),\n\
    \        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n      \
    \  total_len(0),\n        dat(N, none_val),\n        ss(N + 1) {\n    ss.insert(0);\n\
    \    ss.insert(N);\n  }\n\n  tuple<int, int, T> get(int x) {\n    auto l = ss.prev(x);\n\
    \    auto r = ss.next(x + 1);\n    return {l, r, dat[l]};\n  }\n\n  template <typename\
    \ ADD, typename RM>\n  void set(int L, int R, T t, ADD& add_f, RM& rm_f) {\n \
    \   assert(LLIM <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n    assert(L\
    \ < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\u66F4\u3059\u308B\n\
    \    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\u308A\u5408\u3046\
    \u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<int, int, T>> tmp;\n    auto\
    \ l = ss.prev(L);\n    while (l < R) {\n      auto r = ss.next(l + 1);\n     \
    \ auto t = dat[l];\n      tmp.eb(l, r, t);\n      l = r;\n    }\n    auto [lx,\
    \ _, lt] = tmp[0];\n    auto [__, rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\
    \u3048\u305A\u5168\u90E8\u524A\u9664\n    for (auto&& [l, r, t]: tmp) {\n    \
    \  ss.erase(l);\n      if (t == none_val) continue;\n      total_num--;\n    \
    \  total_len -= r - l;\n      rm_f(l, r, t);\n    }\n    if (lt == t) chmin(L,\
    \ lx);\n    if (rt == t) chmax(R, rx);\n    if (lx < L) {\n      // [lx, L)\n\
    \      ss.insert(lx);\n      dat[lx] = lt;\n      if (lt != none_val) {\n    \
    \    total_num++;\n        total_len += L - lx;\n        add_f(lx, L, lt);\n \
    \     }\n    }\n    if (R < rx) {\n      // [R, rx)\n      ss.insert(R);\n   \
    \   dat[R] = rt;\n      if (rt != none_val) {\n        total_num++;\n        total_len\
    \ += rx - R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    ss.insert(L);\n\
    \    dat[L] = t;\n    if (t != none_val) {\n      total_num++;\n      total_len\
    \ += R - L;\n      add_f(L, R, t);\n    }\n  }\n\n  void set(int L, int R, T t)\
    \ {\n    auto f = [&](int L, int R, T t) -> void {};\n    set(L, R, t, f, f);\n\
    \  }\n\n  void erase(int L, int R) {\n    auto f = [&](int L, int R, T t) -> void\
    \ {};\n    set(L, R, none_val, f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\
    \u30BF (l, r, t) \u3092\u5168\u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<int, int,\
    \ T>> get(int L, int R) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n   \
    \ vc<tuple<int, int, T>> res;\n    auto l = ss.prev(L);\n    while (l < R) {\n\
    \      auto t = dat[l];\n      auto r = ss.next(l + 1);\n      int l0 = max(l,\
    \ L);\n      int r0 = min(r, R);\n      if (l0 < r0) res.eb(l0, r0, t);\n    \
    \  l = r;\n    }\n    return res;\n  }\n\n  vc<tuple<int, int, T>> get_all() {\
    \ return get(LLIM, RLIM); }\n\n  void debug() {\n    print(\"Intervals\");\n \
    \   print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n \
    \   int l = 0;\n    while (l < RLIM) {\n      auto t = dat[l];\n      auto r =\
    \ ss.next(l + 1);\n      print(\"l, r, t\", l, r, t);\n      l = r;\n    }\n \
    \ }\n};\n#line 5 \"test/atcoder/abc256d.test.cpp\"\n\nvoid solve() {\n  Intervals<ll,\
    \ int> I(0);\n  LL(N);\n  FOR(N) {\n    LL(l, r);\n    I.set(l, r, 1);\n  }\n\
    \  for (auto [l, r, x]: I.get_all()) {\n    if (x) print(l, r);\n  };\n}\n\nsigned\
    \ main() {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n\
    \  FOR(T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_d\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/intervals.hpp\"\
    \n\nvoid solve() {\n  Intervals<ll, int> I(0);\n  LL(N);\n  FOR(N) {\n    LL(l,\
    \ r);\n    I.set(l, r, 1);\n  }\n  for (auto [l, r, x]: I.get_all()) {\n    if\
    \ (x) print(l, r);\n  };\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/intervals.hpp
  - ds/fastset.hpp
  isVerificationFile: true
  path: test/atcoder/abc256d.test.cpp
  requiredBy: []
  timestamp: '2022-12-06 17:59:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc256d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc256d.test.cpp
- /verify/test/atcoder/abc256d.test.cpp.html
title: test/atcoder/abc256d.test.cpp
---
