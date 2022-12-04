---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/divisors.hpp
    title: nt/divisors.hpp
  - icon: ':heavy_check_mark:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':heavy_check_mark:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D
  bundledCode: "#line 1 \"test/aoj/ITP1_D_D.test.cpp\"\n#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
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
    \ inline void write(T x) {\r\n    x.write();\r\n  }\r\n  template <class T>\r\n\
    \  void write(const vector<T> &val) {\r\n    auto n = val.size();\r\n    for (size_t\
    \ i = 0; i < n; i++) {\r\n      if (i) write(' ');\r\n      write(val[i]);\r\n\
    \    }\r\n  }\r\n  template <class T, class U>\r\n  void write(const pair<T, U>\
    \ &val) {\r\n    write(val.first);\r\n    write(' ');\r\n    write(val.second);\r\
    \n  }\r\n  template <size_t N = 0, typename T>\r\n  void write_tuple(const T &t)\
    \ {\r\n    if constexpr (N < std::tuple_size<T>::value) {\r\n      if constexpr\
    \ (N > 0) { write(' '); }\r\n      const auto &x = std::get<N>(t);\r\n      write(x);\r\
    \n      write_tuple<N + 1>(t);\r\n    }\r\n  }\r\n  template <class... T>\r\n\
    \  bool write(tuple<T...> &tpl) {\r\n    write_tuple(tpl);\r\n    return true;\r\
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
    \ yes(!t); }\n#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using i64 = int64_t;\r\
    \n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\n\r\n  inline static\
    \ u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n  static void\
    \ set_mod(u64 m) {\r\n    assert(m < (1ull << 62));\r\n    assert((m & 1) == 1);\r\
    \n    m64::m = m;\r\n    n2 = -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *=\
    \ 2 - m * r;\r\n    r = -r;\r\n    assert(r * m == -1ull);\r\n  }\r\n  static\
    \ u64 reduce(u128 b) { return (b + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64\
    \ x;\r\n  m64() : x(0) {}\r\n  m64(u64 x) : x(reduce(u128(x) * n2)){};\r\n  u64\
    \ val() const {\r\n    u64 y = reduce(x);\r\n    return y >= m ? y - m : y;\r\n\
    \  }\r\n  m64 &operator+=(m64 y) {\r\n    x += y.x - (m << 1);\r\n    x = (i64(x)\
    \ < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64 &operator-=(m64\
    \ y) {\r\n    x -= y.x;\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return\
    \ *this;\r\n  }\r\n  m64 &operator*=(m64 y) {\r\n    x = reduce(u128(x) * y.x);\r\
    \n    return *this;\r\n  }\r\n  m64 operator+(m64 y) const { return m64(*this)\
    \ += y; }\r\n  m64 operator-(m64 y) const { return m64(*this) -= y; }\r\n  m64\
    \ operator*(m64 y) const { return m64(*this) *= y; }\r\n  bool operator==(m64\
    \ y) const {\r\n    return (x >= m ? x - m : x) == (y.x >= m ? y.x - m : y.x);\r\
    \n  }\r\n  bool operator!=(m64 y) const { return not operator==(y); }\r\n  m64\
    \ pow(u64 n) const {\r\n    m64 y = 1, z = *this;\r\n    for (; n; n >>= 1, z\
    \ *= z)\r\n      if (n & 1) y *= z;\r\n    return y;\r\n  }\r\n};\r\n\r\nbool\
    \ primetest(const uint64_t x) {\r\n  using u64 = uint64_t;\r\n  if (x == 2 or\
    \ x == 3 or x == 5 or x == 7) return true;\r\n  if (x % 2 == 0 or x % 3 == 0 or\
    \ x % 5 == 0 or x % 7 == 0) return false;\r\n  if (x < 121) return x > 1;\r\n\
    \  const u64 d = (x - 1) >> __builtin_ctzll(x - 1);\r\n  m64::set_mod(x);\r\n\
    \  const m64 one(1), minus_one(x - 1);\r\n  auto ok = [&](u64 a) {\r\n    auto\
    \ y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while (y != one and y != minus_one\
    \ and t != x - 1) y *= y, t <<= 1;\r\n    if (y != minus_one and t % 2 == 0) return\
    \ false;\r\n    return true;\r\n  };\r\n  if (x < (1ull << 32)) {\r\n    for (u64\
    \ a: {2, 7, 61})\r\n      if (not ok(a)) return false;\r\n  } else {\r\n    for\
    \ (u64 a: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {\r\n      if (x\
    \ <= a) return true;\r\n      if (not ok(a)) return false;\r\n    }\r\n  }\r\n\
    \  return true;\r\n}\n#line 3 \"nt/factor.hpp\"\n\nmt19937_64 rng_mt{random_device{}()};\n\
    ll rnd(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng_mt); }\n\nll\
    \ rho(ll n, ll c) {\n  m64::set_mod(n);\n  assert(n > 1);\n  const m64 cc(c);\n\
    \  auto f = [&](m64 x) { return x * x + cc; };\n  m64 x = 1, y = 2, z = 1, q =\
    \ 1;\n  ll g = 1;\n  const ll m = 1LL << (__lg(n) / 5); // ?\n  for (ll r = 1;\
    \ g == 1; r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n    for (ll k = 0;\
    \ k < r and g == 1; k += m) {\n      z = y;\n      FOR(_, min(m, r - k)) y = f(y),\
    \ q *= x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n  \
    \    z = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return\
    \ g;\n}\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n))\
    \ return n;\n  FOR(_, 100) {\n    ll m = rho(n, rnd(n));\n    if (primetest(m))\
    \ return m;\n    n = m;\n  }\n  cerr << \"failed\" << endl;\n  assert(false);\n\
    \  return -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll,\
    \ int>> factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>> pf;\n  FOR3(p,\
    \ 2, 100) {\n    if (p * p > n) break;\n    if (n % p == 0) {\n      ll e = 0;\n\
    \      do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p, e);\n    }\n\
    \  }\n  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n   \
    \ do { n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 2 \"nt/divisors.hpp\"\n\r\nvc<ll> divisors_by_pf(const\
    \ vc<pair<ll, int>>& pf, bool SORT) {\r\n  vi div = {1};\r\n  for (auto&& [p,\
    \ e]: pf) {\r\n    ll n = len(div);\r\n    ll pp = 1;\r\n    FOR3(i, 1, e + 1)\
    \ {\r\n      pp *= p;\r\n      FOR(j, n) div.eb(div[j] * pp);\r\n    }\r\n  }\r\
    \n  if (SORT) sort(all(div));\r\n  return div;\r\n}\r\n\r\nvc<ll> divisors(ll\
    \ N, bool SORT) {\r\n  auto pf = factor(N);\r\n  return divisors_by_pf(pf, SORT);\r\
    \n}\r\n\r\nvc<ll> divisors_by_lpf(ll N, vc<int>& lpf, bool SORT) {\r\n  auto pf\
    \ = factor_by_lpf(N, lpf);\r\n  return divisors_by_pf(pf, SORT);\r\n}\n#line 5\
    \ \"test/aoj/ITP1_D_D.test.cpp\"\n\nvoid solve() {\n  LL(a, b, c);\n  auto divs\
    \ = divisors(c, false);\n  ll ANS = 0;\n  for (auto&& d: divs)\n    if (a <= d\
    \ && d <= b) ++ANS;\n  print(ANS);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  ll T = 1;\n\
    \  // LL(T);\n  FOR(_, T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_3_D\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"nt/divisors.hpp\"\
    \n\nvoid solve() {\n  LL(a, b, c);\n  auto divs = divisors(c, false);\n  ll ANS\
    \ = 0;\n  for (auto&& d: divs)\n    if (a <= d && d <= b) ++ANS;\n  print(ANS);\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n \
    \ return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - nt/divisors.hpp
  - nt/factor.hpp
  - nt/primetest.hpp
  isVerificationFile: true
  path: test/aoj/ITP1_D_D.test.cpp
  requiredBy: []
  timestamp: '2022-12-02 07:07:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_D_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_D_D.test.cpp
- /verify/test/aoj/ITP1_D_D.test.cpp.html
title: test/aoj/ITP1_D_D.test.cpp
---
