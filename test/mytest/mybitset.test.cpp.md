---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/my_bitset.hpp
    title: ds/my_bitset.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/mybitset.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \n#include <unistd.h>\r\n\r\nnamespace fastio {\r\n#define FASTIO\r\nstruct has_write_impl\
    \ {\r\n  template <class T>\r\n  static auto check(T &&x) -> decltype(x.write(),\
    \ std::true_type{});\r\n\r\n  template <class T>\r\n  static auto check(...) ->\
    \ std::false_type;\r\n};\r\n\r\ntemplate <class T>\r\nclass has_write : public\
    \ decltype(has_write_impl::check<T>(std::declval<T>())) {\r\n};\r\n\r\nstruct\
    \ has_read_impl {\r\n  template <class T>\r\n  static auto check(T &&x) -> decltype(x.read(),\
    \ std::true_type{});\r\n\r\n  template <class T>\r\n  static auto check(...) ->\
    \ std::false_type;\r\n};\r\n\r\ntemplate <class T>\r\nclass has_read : public\
    \ decltype(has_read_impl::check<T>(std::declval<T>())) {};\r\n\r\nstruct Scanner\
    \ {\r\n  FILE *fp;\r\n  char line[(1 << 15) + 1];\r\n  size_t st = 0, ed = 0;\r\
    \n  void reread() {\r\n    memmove(line, line + st, ed - st);\r\n    ed -= st;\r\
    \n    st = 0;\r\n    ed += fread(line + ed, 1, (1 << 15) - ed, fp);\r\n    line[ed]\
    \ = '\\0';\r\n  }\r\n  bool succ() {\r\n    while (true) {\r\n      if (st ==\
    \ ed) {\r\n        reread();\r\n        if (st == ed) return false;\r\n      }\r\
    \n      while (st != ed && isspace(line[st])) st++;\r\n      if (st != ed) break;\r\
    \n    }\r\n    if (ed - st <= 50) {\r\n      bool sep = false;\r\n      for (size_t\
    \ i = st; i < ed; i++) {\r\n        if (isspace(line[i])) {\r\n          sep =\
    \ true;\r\n          break;\r\n        }\r\n      }\r\n      if (!sep) reread();\r\
    \n    }\r\n    return true;\r\n  }\r\n  template <class T, enable_if_t<is_same<T,\
    \ string>::value, int> = 0>\r\n  bool read_single(T &ref) {\r\n    if (!succ())\
    \ return false;\r\n    while (true) {\r\n      size_t sz = 0;\r\n      while (st\
    \ + sz < ed && !isspace(line[st + sz])) sz++;\r\n      ref.append(line + st, sz);\r\
    \n      st += sz;\r\n      if (!sz || st != ed) break;\r\n      reread();\r\n\
    \    }\r\n    return true;\r\n  }\r\n  template <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\n  bool read_single(T &ref) {\r\n    if (!succ()) return false;\r\
    \n    bool neg = false;\r\n    if (line[st] == '-') {\r\n      neg = true;\r\n\
    \      st++;\r\n    }\r\n    ref = T(0);\r\n    while (isdigit(line[st])) { ref\
    \ = 10 * ref + (line[st++] & 0xf); }\r\n    if (neg) ref = -ref;\r\n    return\
    \ true;\r\n  }\r\n  template <typename T,\r\n            typename enable_if<has_read<T>::value>::type\
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
    \ yes(!t); }\n#line 4 \"test/mytest/mybitset.test.cpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"ds/my_bitset.hpp\"\
    \n\n// https://codeforces.com/contest/914/problem/F\n// https://yukicoder.me/problems/no/142\n\
    // \u308F\u305A\u304B\u306B\u666E\u901A\u306E bitset \u3088\u308A\u9045\u3044\u3068\
    \u304D\u3082\u3042\u308B\u3088\u3046\u3060\u304C\uFF0C\n// \u56FA\u5B9A\u9577\u306B\
    \u3057\u305F\u304F\u306A\u3044\u3068\u304D\u3084 slice \u64CD\u4F5C\u304C\u5FC5\
    \u8981\u306A\u3068\u304D\u306B\u4F7F\u3046\nstruct My_Bitset {\n  using T = My_Bitset;\n\
    \  int N;\n  vc<u64> dat;\n\n  // x \u3067\u57CB\u3081\u308B\n  My_Bitset(int\
    \ N = 0, int x = 0) : N(N) {\n    assert(x == 0 || x == 1);\n    u64 v = (x ==\
    \ 0 ? 0 : -1);\n    dat.assign((N + 63) >> 6, v);\n    if (N) dat.back() >>= (64\
    \ * len(dat) - N);\n  }\n\n  int size() { return N; }\n\n  void resize(int size)\
    \ {\n    dat.resize((size + 63) >> 6);\n    int remainingBits = size & 63;\n \
    \   if (remainingBits != 0) {\n      u64 mask = (u64(1) << remainingBits) - 1;\n\
    \      dat.back() &= mask;\n    }\n    N = size;\n  }\n\n  // thanks to chatgpt!\n\
    \  class Proxy {\n  public:\n    Proxy(vc<u64> &d, int i) : dat(d), index(i) {}\n\
    \    operator bool() const { return (dat[index >> 6] >> (index & 63)) & 1; }\n\
    \n    Proxy &operator=(u64 value) {\n      dat[index >> 6] &= ~(u64(1) << (index\
    \ & 63));\n      dat[index >> 6] |= (value & 1) << (index & 63);\n      return\
    \ *this;\n    }\n    void flip() {\n      dat[index >> 6] ^= (u64(1) << (index\
    \ & 63)); // XOR to flip the bit\n    }\n\n  private:\n    vc<u64> &dat;\n   \
    \ int index;\n  };\n\n  Proxy operator[](int i) { return Proxy(dat, i); }\n\n\
    \  T &operator&=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i]\
    \ &= p.dat[i];\n    return *this;\n  }\n  T &operator|=(const T &p) {\n    assert(N\
    \ == p.N);\n    FOR(i, len(dat)) dat[i] |= p.dat[i];\n    return *this;\n  }\n\
    \  T &operator^=(const T &p) {\n    assert(N == p.N);\n    FOR(i, len(dat)) dat[i]\
    \ ^= p.dat[i];\n    return *this;\n  }\n  T operator&(const T &p) const { return\
    \ T(*this) &= p; }\n  T operator|(const T &p) const { return T(*this) |= p; }\n\
    \  T operator^(const T &p) const { return T(*this) ^= p; }\n\n  int count() {\n\
    \    int ans = 0;\n    for (u64 val: dat) ans += popcnt(val);\n    return ans;\n\
    \  }\n\n  int next(int i) {\n    chmax(i, 0);\n    if (i >= N) return N;\n   \
    \ int k = i >> 6;\n    {\n      u64 x = dat[k];\n      int s = i & 63;\n     \
    \ x = (x >> s) << s;\n      if (x) return (k << 6) | lowbit(x);\n    }\n    FOR(idx,\
    \ k + 1, len(dat)) {\n      if (dat[idx] == 0) continue;\n      return (idx <<\
    \ 6) | lowbit(dat[idx]);\n    }\n    return N;\n  }\n\n  int prev(int i) {\n \
    \   chmin(i, N - 1);\n    if (i <= -1) return -1;\n    int k = i >> 6;\n    if\
    \ ((i & 63) < 63) {\n      u64 x = dat[k];\n      x &= (u64(1) << ((i & 63) +\
    \ 1)) - 1;\n      if (x) return (k << 6) | topbit(x);\n      --k;\n    }\n   \
    \ FOR_R(idx, k + 1) {\n      if (dat[idx] == 0) continue;\n      return (idx <<\
    \ 6) | topbit(dat[idx]);\n    }\n    return -1;\n  }\n\n  My_Bitset range(int\
    \ L, int R) {\n    assert(L <= R);\n    My_Bitset p(R - L);\n    int rm = (R -\
    \ L) & 63;\n    FOR(rm) {\n      p[R - L - 1] = bool((*this)[R - 1]);\n      --R;\n\
    \    }\n    int n = (R - L) >> 6;\n    int hi = L & 63;\n    int lo = 64 - hi;\n\
    \    int s = L >> 6;\n    if (hi == 0) {\n      FOR(i, n) { p.dat[i] ^= dat[s\
    \ + i]; }\n    } else {\n      FOR(i, n) { p.dat[i] ^= (dat[s + i] >> hi) ^ (dat[s\
    \ + i + 1] << lo); }\n    }\n    return p;\n  }\n\n  int count_range(int L, int\
    \ R) {\n    assert(L <= R);\n    int cnt = 0;\n    while ((L < R) && (L & 63))\
    \ cnt += (*this)[L++];\n    while ((L < R) && (R & 63)) cnt += (*this)[--R];\n\
    \    int l = L >> 6, r = R >> 6;\n    FOR(i, l, r) cnt += popcnt(dat[i]);\n  \
    \  return cnt;\n  }\n\n  // [L,R) \u306B p \u3092\u4EE3\u5165\n  void assign_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) { (*this)[L++] = bool(p[a++]); }\n    while (L\
    \ < R && (R & 63)) { (*this)[--R] = bool(p[--b]); }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] = p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] = (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n  \
    \  }\n  }\n\n  // [L,R) \u306B p \u3092 xor\n  void xor_to_range(int L, int R,\
    \ My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while\
    \ (L < R && (L & 63)) {\n      dat[L >> 6] ^= u64(p[a]) << (L & 63);\n      ++a,\
    \ ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n      dat[R >>\
    \ 6] ^= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R] \u306B\n   \
    \ int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n    int n = r\
    \ - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] ^= p.dat[s + i];\n  \
    \  } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n      FOR(i, n)\
    \ dat[l + i] ^= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n    }\n  }\n\
    \n  // [L,R) \u306B p \u3092 and\n  void and_to_range(int L, int R, My_Bitset\
    \ &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n    while (L < R\
    \ && (L & 63)) {\n      if (!p[a++]) (*this)[L++] = 0;\n    }\n    while (L <\
    \ R && (R & 63)) {\n      if (!p[--b]) (*this)[--R] = 0;\n    }\n    // p[a:b]\
    \ \u3092 [L:R] \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t\
    \ = b >> t;\n    int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l +\
    \ i] &= p.dat[s + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64\
    \ - hi;\n      FOR(i, n) dat[l + i] &= (p.dat[s + i] >> hi) | (p.dat[1 + s + i]\
    \ << lo);\n    }\n  }\n\n  // [L,R) \u306B p \u3092 or\n  void or_to_range(int\
    \ L, int R, My_Bitset &p) {\n    assert(p.N == R - L);\n    int a = 0, b = p.N;\n\
    \    while (L < R && (L & 63)) {\n      dat[L >> 6] |= u64(p[a]) << (L & 63);\n\
    \      ++a, ++L;\n    }\n    while (L < R && (R & 63)) {\n      --b, --R;\n  \
    \    dat[R >> 6] |= u64(p[b]) << (R & 63);\n    }\n    // p[a:b] \u3092 [L:R]\
    \ \u306B\n    int l = L >> 6, r = R >> 6;\n    int s = a >> 6, t = b >> t;\n \
    \   int n = r - l;\n    if (!(a & 63)) {\n      FOR(i, n) dat[l + i] |= p.dat[s\
    \ + i];\n    } else {\n      int hi = a & 63;\n      int lo = 64 - hi;\n     \
    \ FOR(i, n) dat[l + i] |= (p.dat[s + i] >> hi) | (p.dat[1 + s + i] << lo);\n \
    \   }\n  }\n\n  string to_string() const {\n    string S;\n    FOR(i, N) S +=\
    \ '0' + (dat[i >> 6] >> (i & 63) & 1);\n    return S;\n  }\n\n  // bitset \u306B\
    \u4ED5\u69D8\u3092\u5408\u308F\u305B\u308B\n  void set(int i) { (*this)[i] = 1;\
    \ }\n  void reset(int i) { (*this)[i] = 0; }\n  void flip(int i) { (*this)[i].flip();\
    \ }\n  void set() { fill(all(dat), 0); }\n  void reset() {\n    fill(all(dat),\
    \ u64(-1));\n    resize(N);\n  }\n\n  int _Find_first() { return next(0); }\n\
    \  int _Find_next(int p) { return next(p + 1); }\n};\n#line 7 \"test/mytest/mybitset.test.cpp\"\
    \n\nvoid test() {\n  FOR(N, 2000) {\n    int Q = 10 * N;\n    vc<int> A(N);\n\
    \    My_Bitset B(N);\n    FOR(Q) {\n      int t = RNG(0, 4);\n      int i = RNG(0,\
    \ N);\n      if (t == 0) {\n        A[i] = 0;\n        B[i] = 0;\n      }\n  \
    \    if (t == 1) {\n        A[i] = 1;\n        B[i] = 1;\n      }\n      if (t\
    \ == 2) {\n        int p = i;\n        while (p < N && A[p] == 0) ++p;\n     \
    \   assert(B.next(i) == p);\n      }\n      if (t == 3) {\n        int p = i;\n\
    \        while (p >= 0 && A[p] == 0) --p;\n        assert(B.prev(i) == p);\n \
    \     }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\n\
    signed main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"random/base.hpp\"\n#include \"ds/my_bitset.hpp\"\
    \n\nvoid test() {\n  FOR(N, 2000) {\n    int Q = 10 * N;\n    vc<int> A(N);\n\
    \    My_Bitset B(N);\n    FOR(Q) {\n      int t = RNG(0, 4);\n      int i = RNG(0,\
    \ N);\n      if (t == 0) {\n        A[i] = 0;\n        B[i] = 0;\n      }\n  \
    \    if (t == 1) {\n        A[i] = 1;\n        B[i] = 1;\n      }\n      if (t\
    \ == 2) {\n        int p = i;\n        while (p < N && A[p] == 0) ++p;\n     \
    \   assert(B.next(i) == p);\n      }\n      if (t == 3) {\n        int p = i;\n\
    \        while (p >= 0 && A[p] == 0) --p;\n        assert(B.prev(i) == p);\n \
    \     }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\n\
    signed main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - ds/my_bitset.hpp
  isVerificationFile: true
  path: test/mytest/mybitset.test.cpp
  requiredBy: []
  timestamp: '2023-11-01 19:16:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/mybitset.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/mybitset.test.cpp
- /verify/test/mytest/mybitset.test.cpp.html
title: test/mytest/mybitset.test.cpp
---
