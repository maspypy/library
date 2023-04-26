---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':x:'
    path: mod/mod_kth_root.hpp
    title: mod/mod_kth_root.hpp
  - icon: ':x:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':x:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_mod
    links:
    - https://judge.yosupo.jp/problem/kth_root_mod
  bundledCode: "#line 1 \"test/library_checker/math/kth_root_mod.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/kth_root_mod\"\r\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC\
    \ optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\nconstexpr\
    \ T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate\
    \ <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
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
    \ yes(!t); }\n#line 2 \"nt/primetest.hpp\"\nstruct m64 {\r\n  using i64 = int64_t;\r\
    \n  using u64 = uint64_t;\r\n  using u128 = __uint128_t;\r\n\r\n  inline static\
    \ u64 m, r, n2; // r * m = -1 (mod 1<<64), n2 = 1<<128 (mod m)\r\n  static void\
    \ set_mod(u64 m) {\r\n    assert((m & 1) == 1);\r\n    m64::m = m;\r\n    n2 =\
    \ -u128(m) % m;\r\n    r = m;\r\n    FOR(_, 5) r *= 2 - m * r;\r\n    r = -r;\r\
    \n    assert(r * m == -1ull);\r\n  }\r\n  static u64 reduce(u128 b) { return (b\
    \ + u128(u64(b) * r) * m) >> 64; }\r\n\r\n  u64 x;\r\n  m64() : x(0) {}\r\n  m64(u64\
    \ x) : x(reduce(u128(x) * n2)){};\r\n  u64 val() const {\r\n    u64 y = reduce(x);\r\
    \n    return y >= m ? y - m : y;\r\n  }\r\n  m64 &operator+=(m64 y) {\r\n    x\
    \ += y.x - (m << 1);\r\n    x = (i64(x) < 0 ? x + (m << 1) : x);\r\n    return\
    \ *this;\r\n  }\r\n  m64 &operator-=(m64 y) {\r\n    x -= y.x;\r\n    x = (i64(x)\
    \ < 0 ? x + (m << 1) : x);\r\n    return *this;\r\n  }\r\n  m64 &operator*=(m64\
    \ y) {\r\n    x = reduce(u128(x) * y.x);\r\n    return *this;\r\n  }\r\n  m64\
    \ operator+(m64 y) const { return m64(*this) += y; }\r\n  m64 operator-(m64 y)\
    \ const { return m64(*this) -= y; }\r\n  m64 operator*(m64 y) const { return m64(*this)\
    \ *= y; }\r\n  bool operator==(m64 y) const {\r\n    return (x >= m ? x - m :\
    \ x) == (y.x >= m ? y.x - m : y.x);\r\n  }\r\n  bool operator!=(m64 y) const {\
    \ return not operator==(y); }\r\n  m64 pow(u64 n) const {\r\n    m64 y = 1, z\
    \ = *this;\r\n    for (; n; n >>= 1, z *= z)\r\n      if (n & 1) y *= z;\r\n \
    \   return y;\r\n  }\r\n};\r\n\r\nbool primetest(const uint64_t x) {\r\n  using\
    \ u64 = uint64_t;\r\n  if (x == 2 or x == 3 or x == 5 or x == 7) return true;\r\
    \n  if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;\r\n\
    \  if (x < 121) return x > 1;\r\n  const u64 d = (x - 1) >> __builtin_ctzll(x\
    \ - 1);\r\n  m64::set_mod(x);\r\n  const m64 one(1), minus_one(x - 1);\r\n  auto\
    \ ok = [&](u64 a) {\r\n    auto y = m64(a).pow(d);\r\n    u64 t = d;\r\n    while\
    \ (y != one and y != minus_one and t != x - 1) y *= y, t <<= 1;\r\n    if (y !=\
    \ minus_one and t % 2 == 0) return false;\r\n    return true;\r\n  };\r\n  if\
    \ (x < (1ull << 32)) {\r\n    for (u64 a: {2, 7, 61})\r\n      if (not ok(a))\
    \ return false;\r\n  } else {\r\n    for (u64 a: {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022}) {\r\n      if (x <= a) return true;\r\n      if (not ok(a))\
    \ return false;\r\n    }\r\n  }\r\n  return true;\r\n}\n#line 2 \"mod/primitive_root.hpp\"\
    \n\r\n#line 3 \"nt/factor.hpp\"\n\nmt19937_64 rng_mt{random_device{}()};\nll rnd(ll\
    \ n) { return uniform_int_distribution<ll>(0, n - 1)(rng_mt); }\n\nll rho(ll n,\
    \ ll c) {\n  m64::set_mod(n);\n  assert(n > 1);\n  const m64 cc(c);\n  auto f\
    \ = [&](m64 x) { return x * x + cc; };\n  m64 x = 1, y = 2, z = 1, q = 1;\n  ll\
    \ g = 1;\n  const ll m = 1LL << (__lg(n) / 5); // ?\n  for (ll r = 1; g == 1;\
    \ r <<= 1) {\n    x = y;\n    FOR(_, r) y = f(y);\n    for (ll k = 0; k < r and\
    \ g == 1; k += m) {\n      z = y;\n      FOR(_, min(m, r - k)) y = f(y), q *=\
    \ x - y;\n      g = gcd(q.val(), n);\n    }\n  }\n  if (g == n) do {\n      z\
    \ = f(z);\n      g = gcd((x - z).val(), n);\n    } while (g == 1);\n  return g;\n\
    }\n\nll find_prime_factor(ll n) {\n  assert(n > 1);\n  if (primetest(n)) return\
    \ n;\n  FOR(_, 100) {\n    ll m = rho(n, rnd(n));\n    if (primetest(m)) return\
    \ m;\n    n = m;\n  }\n  cerr << \"failed\" << endl;\n  assert(false);\n  return\
    \ -1;\n}\n\n// \u30BD\u30FC\u30C8\u3057\u3066\u304F\u308C\u308B\nvc<pair<ll, int>>\
    \ factor(ll n) {\n  assert(n >= 1);\n  vc<pair<ll, int>> pf;\n  FOR3(p, 2, 100)\
    \ {\n    if (p * p > n) break;\n    if (n % p == 0) {\n      ll e = 0;\n     \
    \ do { n /= p, e += 1; } while (n % p == 0);\n      pf.eb(p, e);\n    }\n  }\n\
    \  while (n > 1) {\n    ll p = find_prime_factor(n);\n    ll e = 0;\n    do {\
    \ n /= p, e += 1; } while (n % p == 0);\n    pf.eb(p, e);\n  }\n  sort(all(pf));\n\
    \  return pf;\n}\n\nvc<pair<ll, int>> factor_by_lpf(ll n, vc<int>& lpf) {\n  vc<pair<ll,\
    \ int>> res;\n  while (n > 1) {\n    int p = lpf[n];\n    int e = 0;\n    while\
    \ (n % p == 0) {\n      n /= p;\n      ++e;\n    }\n    res.eb(p, e);\n  }\n \
    \ return res;\n}\n#line 2 \"mod/barret.hpp\"\n\nstruct Barret_Reduction {\n  using\
    \ i64 = long long;\n  using u64 = unsigned long long;\n  using u128 = __uint128_t;\n\
    \  int m, s;\n  u64 x;\n  constexpr Barret_Reduction() : m(), s(), x() {}\n  constexpr\
    \ Barret_Reduction(int n)\n      : m(n), s(std::__lg(n - 1)), x(((u128(1) << (s\
    \ + 64)) + n - 1) / n) {}\n  constexpr friend u64 operator/(u64 n, const Barret_Reduction&\
    \ d) {\n    return (u128(n) * d.x >> d.s) >> 64;\n  }\n  constexpr friend int\
    \ operator%(u64 n, const Barret_Reduction& d) {\n    return n - n / d * d.m;\n\
    \  }\n  constexpr pair<i64, int> divmod(u64 n) const {\n    u64 q = n / *this;\n\
    \    return {q, n - q * m};\n  }\n};\n#line 3 \"mod/mod_pow.hpp\"\n\r\n// int\r\
    \nll mod_pow(ll a, ll n, int mod) {\r\n  Barret_Reduction BR(mod);\r\n  a = a\
    \ % BR;\r\n  ll p = a;\r\n  ll v = 1;\r\n  while (n) {\r\n    if (n & 1) v = v\
    \ * p % BR;\r\n    p = p * p % BR;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\
    \n\r\nll mod_pow_long(ll a, ll n, ll mod) {\r\n  a %= mod;\r\n  ll p = a;\r\n\
    \  ll v = 1;\r\n  while (n) {\r\n    if (n & 1) v = i128(v) * p % mod;\r\n   \
    \ p = i128(p) * p % mod;\r\n    n >>= 1;\r\n  }\r\n  return v;\r\n}\r\n#line 2\
    \ \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 6 \"mod/primitive_root.hpp\"\
    \n\r\n// int\r\nint primitive_root(int p) {\r\n  auto pf = factor(p - 1);\r\n\
    \  auto is_ok = [&](int g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if\
    \ (mod_pow(g, (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\
    \n  FOR3(x, 1, p) {\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return -1;\r\n\
    }\r\n\r\nll primitive_root_long(ll p) {\r\n  auto pf = factor(p - 1);\r\n  auto\
    \ is_ok = [&](ll g) -> bool {\r\n    for (auto&& [q, e]: pf)\r\n      if (mod_pow_long(g,\
    \ (p - 1) / q, p) == 1) return false;\r\n    return true;\r\n  };\r\n  while (1)\
    \ {\r\n    ll x = RNG(1, p);\r\n    if (is_ok(x)) return x;\r\n  }\r\n  return\
    \ -1;\r\n}\r\n#line 2 \"mod/mod_inv.hpp\"\n// long \u3067\u3082\u5927\u4E08\u592B\
    \r\nll mod_inv(ll val, ll mod) {\r\n  val %= mod;\r\n  if (val < 0) val += mod;\r\
    \n  ll a = val, b = mod, u = 1, v = 0, t;\r\n  while (b > 0) {\r\n    t = a /\
    \ b;\r\n    swap(a -= t * b, b), swap(u -= t * v, v);\r\n  }\r\n  if (u < 0) u\
    \ += mod;\r\n  return u;\r\n}\r\n#line 3 \"ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\
    \ntemplate <typename Val, int LOG = 20>\r\nstruct HashMap {\r\n  int N;\r\n  u64*\
    \ keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1 << LOG> used;\r\n  const\
    \ int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\n  HashMap()\r\n  \
    \    : N(1 << LOG), keys(new u64[N]), vals(new Val[N]), shift(64 - __lg(N)) {}\r\
    \n  int hash(ll x) {\r\n    static const u64 FIXED_RANDOM\r\n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i]\
    \ != key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  // [] \u3057\
    \u305F\u6642\u70B9\u3067\u8981\u7D20\u306F\u4F5C\u3089\u308C\u308B\r\n  Val& operator[](const\
    \ u64& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const u64& key, Val default_value) {\r\n    int i = index(key);\r\n\
    \    if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const u64& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key, val)\r\n  template\
    \ <typename F>\r\n  void enumerate_all(F f) {\r\n    for (auto&& i: IDS) f(keys[i],\
    \ vals[i]);\r\n  }\r\n};\r\n#line 5 \"mod/mod_kth_root.hpp\"\n\r\n// mod \u306F\
    \ int\r\nint mod_kth_root(ll k, ll a, int mod) {\r\n  assert(primetest(mod) &&\
    \ 0 <= a && a < mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a ==\
    \ 0) return 0;\r\n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n  fast_div fd(mod);\r\
    \n\r\n  ll g = gcd(k, mod - 1);\r\n  if (mod_pow(a, (mod - 1) / g, mod) != 1)\
    \ return -1;\r\n\r\n  ll c = mod_inv(k / g, (mod - 1) / g);\r\n  a = mod_pow(a,\
    \ c, mod);\r\n  k = (k * c) % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n  g\
    \ = primitive_root(mod);\r\n\r\n  auto solve_pp = [&](ll p, int e, ll a) -> ll\
    \ {\r\n    int f = 0;\r\n    ll pf = 1;\r\n    while ((mod - 1) % (pf * p) ==\
    \ 0) ++f, pf *= p;\r\n    ll m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\
    \u6570 Qm \u306E\u5DE1\u56DE\u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\
    \u3068\u308A\u305F\u3044\u3002\u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\
    \u3066\u3044\u308B\r\n    \u30FBa / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\
    \u3002\u307E\u305A\u306F\u3001b \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\
    \u5897\u3084\u3057\u3066\u3044\u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c\
    \ = f - e; // b ^ {mp^c} = 1\r\n    int pc = 1;\r\n    FOR(c) pc *= p;\r\n   \
    \ int pe = 1;\r\n    FOR(e) pe *= p;\r\n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\
    \u59CB p \u4E57\u6839\u306B\u95A2\u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\
    \u306E\u30BB\u30C3\u30C8\u30A2\u30C3\u30D7\r\n    ll G = mod_pow(g, (mod - 1)\
    \ / p, mod);\r\n    int M = 0;\r\n    unordered_map<ll, int> MP;\r\n    ll GM_inv\
    \ = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n      MP.reserve(M\
    \ + 1);\r\n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow] = m;\r\n\
    \        Gpow = Gpow * G % fd;\r\n      }\r\n      GM_inv = mod_pow(Gpow, mod\
    \ - 2, mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c} = 1\
    \ \u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}} = 1\
    \ \u306B\u3057\u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\u3066\
    \u63A2\u3059\u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B B\
    \ = G^k \u306B\u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow(b, m * pc\
    \ / p, mod);\r\n      int k = [&](ll B) -> int {\r\n        FOR(m, M + 1) {\r\n\
    \          if (MP.count(B)) return m * M + MP[B];\r\n          B = B * GM_inv\
    \ % fd;\r\n        }\r\n        return -1;\r\n      }(B);\r\n      x = x * mod_pow(g,\
    \ pf / pc / pe * k, mod) % fd;\r\n      ll exp = pf / pc * k % (mod - 1);\r\n\
    \      b = b * mod_pow(g, mod - 1 - exp, mod) % fd;\r\n      --c;\r\n      pc\
    \ /= p;\r\n    }\r\n    int k = pe - mod_inv(m, pe);\r\n    k = (k * m + 1) /\
    \ pe;\r\n    ll y = mod_pow(b, k, mod);\r\n    x = x * y % fd;\r\n    return x;\r\
    \n  };\r\n\r\n  auto pf = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p,\
    \ e, a);\r\n  return a;\r\n}\r\n\r\nll mod_kth_root_long(ll k, ll a, ll mod) {\r\
    \n  static HashMap<ll, 20> MP;\r\n\r\n  assert(primetest(mod) && 0 <= a && a <\
    \ mod);\r\n  if (k == 0) return (a == 1 ? 1 : -1);\r\n  if (a == 0) return 0;\r\
    \n  if (mod == 2) return a;\r\n  k %= mod - 1;\r\n\r\n  ll g = gcd(k, mod - 1);\r\
    \n  if (mod_pow_long(a, (mod - 1) / g, mod) != 1) return -1;\r\n\r\n  ll c = mod_inv(k\
    \ / g, (mod - 1) / g);\r\n  a = mod_pow_long(a, c, mod);\r\n  k = i128(k) * c\
    \ % (mod - 1);\r\n  if (k == 0) return 1;\r\n\r\n  g = primitive_root_long(mod);\r\
    \n\r\n  auto solve_pp = [&](ll p, ll e, ll a) -> ll {\r\n    ll f = 0;\r\n   \
    \ ll pf = 1;\r\n    while (((mod - 1) / pf) % p == 0) ++f, pf *= p;\r\n    ll\
    \ m = (mod - 1) / pf;\r\n    /*\r\n    \u30FB\u4F4D\u6570 Qm \u306E\u5DE1\u56DE\
    \u7FA4\r\n    \u30FBa \u306E p^e \u4E57\u6839\u3092\u3068\u308A\u305F\u3044\u3002\
    \u6301\u3064\u3053\u3068\u306F\u5206\u304B\u3063\u3066\u3044\u308B\r\n    \u30FB\
    a / x^{p^e} = b \u3092\u7DAD\u6301\u3059\u308B\u3002\u307E\u305A\u306F\u3001b\
    \ \u304C p \u3067\u5272\u308C\u308B\u56DE\u6570\u3092\u5897\u3084\u3057\u3066\u3044\
    \u304F\u3002\r\n    */\r\n    ll x = 1, b = a, c = f - e; // b ^ {mp^c} = 1\r\n\
    \    ll pc = 1;\r\n    FOR(c) pc *= p;\r\n    ll pe = 1;\r\n    FOR(e) pe *= p;\r\
    \n    // \u5FC5\u8981\u306A\u3089\u3070\u539F\u59CB p \u4E57\u6839\u306B\u95A2\
    \u3059\u308B\u96E2\u6563\u5BFE\u6570\u554F\u984C\u306E\u30BB\u30C3\u30C8\u30A2\
    \u30C3\u30D7\r\n    ll G = mod_pow_long(g, (mod - 1) / p, mod);\r\n    ll M =\
    \ 0;\r\n    ll GM_inv = -1;\r\n    if (c) {\r\n      while (M * M < p) ++M;\r\n\
    \      MP.reset();\r\n      ll Gpow = 1;\r\n      FOR(m, M) {\r\n        MP[Gpow]\
    \ = m;\r\n        Gpow = i128(Gpow) * G % mod;\r\n      }\r\n      GM_inv = mod_pow_long(Gpow,\
    \ mod - 2, mod);\r\n    }\r\n\r\n    while (c) {\r\n      /*\r\n      b^{mp^c}\
    \ = 1 \u304C\u5206\u304B\u3063\u3066\u3044\u308B\u3002(b/x^{p^e}})^{mp^{c-1}}\
    \ = 1 \u306B\u3057\u305F\u3044\u3002\r\n      x = g^{p^{f-c-e}*k} \u3068\u3057\
    \u3066\u63A2\u3059\u3002\u539F\u59CB p \u4E57\u6839 B, G \u306B\u5BFE\u3059\u308B\
    \ B = G^k \u306B\u5E30\u7740\u3002\r\n      */\r\n      ll B = mod_pow_long(b,\
    \ pc / p * m, mod);\r\n      ll k = [&](ll B) -> ll {\r\n        FOR(m, M + 1)\
    \ {\r\n          if (MP.count(B)) return m * M + MP[B];\r\n          B = i128(B)\
    \ * GM_inv % mod;\r\n        }\r\n        return -1;\r\n      }(B);\r\n      x\
    \ = i128(x) * mod_pow_long(g, pf / pc / pe * k, mod) % mod;\r\n\r\n      ll exp\
    \ = pf / pc * i128(k) % (mod - 1);\r\n      b = i128(b) * mod_pow_long(g, mod\
    \ - 1 - exp, mod) % mod;\r\n      --c;\r\n      pc /= p;\r\n    }\r\n    ll k\
    \ = pe - mod_inv(m, pe);\r\n    k = (i128(k) * m + 1) / pe;\r\n    ll y = mod_pow_long(b,\
    \ k, mod);\r\n    x = i128(x) * y % mod;\r\n    return x;\r\n  };\r\n\r\n  auto\
    \ pf = factor(k);\r\n  for (auto&& [p, e]: pf) a = solve_pp(p, e, a);\r\n  return\
    \ a;\r\n}\r\n#line 5 \"test/library_checker/math/kth_root_mod.test.cpp\"\n\r\n\
    void solve() {\r\n  LL(k, y, p);\r\n  ll x = mod_kth_root(k, y % p, p);\r\n  print(x);\r\
    \n}\r\n\r\nsigned main() {\r\n  LL(T);\r\n  FOR(T) solve();\r\n\r\n  return 0;\r\
    \n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_mod\"\r\n#include\
    \ \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"mod/mod_kth_root.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(k, y, p);\r\n  ll x = mod_kth_root(k, y % p, p);\r\
    \n  print(x);\r\n}\r\n\r\nsigned main() {\r\n  LL(T);\r\n  FOR(T) solve();\r\n\
    \r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/mod_kth_root.hpp
  - nt/primetest.hpp
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - mod/mod_pow.hpp
  - mod/barret.hpp
  - random/base.hpp
  - mod/mod_inv.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/library_checker/math/kth_root_mod.test.cpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/math/kth_root_mod.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/math/kth_root_mod.test.cpp
- /verify/test/library_checker/math/kth_root_mod.test.cpp.html
title: test/library_checker/math/kth_root_mod.test.cpp
---
