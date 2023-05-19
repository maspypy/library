---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: ds/sortable_array.hpp
    title: ds/sortable_array.hpp
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
  bundledCode: "#line 1 \"test/mytest/sortable_array.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
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
    \ yes(!t); }\n#line 5 \"test/mytest/sortable_array.test.cpp\"\n\n#line 1 \"ds/fastset.hpp\"\
    \n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\n[]\u3067\u306E\u5B58\u5728\u5224\
    \u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet {\r\n  using uint = unsigned;\r\n\
    \  using ull = unsigned long long;\r\n\r\n  int bsr(ull x) { return 63 - __builtin_clzll(x);\
    \ }\r\n  int bsf(ull x) { return __builtin_ctzll(x); }\r\n\r\n  static constexpr\
    \ uint B = 64;\r\n  int n, lg;\r\n  vector<vector<ull>> seg;\r\n  FastSet(int\
    \ _n) : n(_n) {\r\n    do {\r\n      seg.push_back(vector<ull>((_n + B - 1) /\
    \ B));\r\n      _n = (_n + B - 1) / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\
    \n  }\r\n  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1)\
    \ != 0; }\r\n  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n\
    \      seg[h][i / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n\
    \  void add(int i) { insert(i); }\r\n  void erase(int i) {\r\n    for (int h =\
    \ 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL << (i % B));\r\n      if\
    \ (seg[h][i / B]) break;\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int\
    \ i) { insert(i); }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int\
    \ next(int i) {\r\n    chmax(i, 0);\r\n    if (i >= n) return n;\r\n    for (int\
    \ h = 0; h < lg; h++) {\r\n      if (i / B == seg[h].size()) break;\r\n      ull\
    \ d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n        i = i / B + 1;\r\
    \n        continue;\r\n      }\r\n      // find\r\n      i += bsf(d);\r\n    \
    \  for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += bsf(seg[g][i\
    \ / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return n;\r\n  }\r\n\r\n\
    \  // x\u4EE5\u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\u8FD4\u3059\u3002\u5B58\
    \u5728\u3057\u306A\u3051\u308C\u3070 -1\u3002\r\n  int prev(int i) {\r\n    if\
    \ (i < 0) return -1;\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h <\
    \ lg; h++) {\r\n      if (i == -1) break;\r\n      ull d = seg[h][i / B] << (63\
    \ - i % 64);\r\n      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\
    \n      }\r\n      // find\r\n      i += bsr(d) - (B - 1);\r\n      for (int g\
    \ = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += bsr(seg[g][i / B]);\r\
    \n      }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  // [l,\
    \ r)\r\n  template <typename F>\r\n  void enumerate(int l, int r, F f) {\r\n \
    \   int x = l - 1;\r\n    while (1) {\r\n      x = next(x + 1);\r\n      if (x\
    \ >= r) break;\r\n      f(x);\r\n    }\r\n  }\r\n\r\n  void debug() {\r\n    string\
    \ s;\r\n    for (int i = 0; i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n   \
    \ print(s);\r\n  }\r\n};\r\n#line 2 \"ds/sortable_array.hpp\"\n\n// int \u5217\
    \u3092\u6271\u3046. key \u306E\u91CD\u8907\u53EF.\ntemplate <int NODES>\nstruct\
    \ Sortable_Array {\n  const int N, KEY_MAX;\n\n  struct Node {\n    int size;\n\
    \    Node *l, *r;\n  };\n  Node* pool;\n  int pid;\n  using np = Node*;\n\n  FastSet\
    \ ss;      // \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\u3092\u8868\u3059 fastset\n\
    \  vector<np> root; // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic segtree\
    \ \u306E node \u3092\u4E57\u305B\u308B\n  vector<bool> rev;\n\n  Sortable_Array(int\
    \ KEY_MAX, vector<int> key)\n      : N(key.size()), KEY_MAX(KEY_MAX), pid(0),\
    \ ss(key.size()) {\n    pool = new Node[NODES];\n    init(key);\n  }\n\n  void\
    \ set(int i, int key) {\n    assert(0 <= key && key < KEY_MAX);\n    split_at(i),\
    \ split_at(i + 1);\n    rev[i] = 0, root[i] = new_node(0);\n    set_rec(root[i],\
    \ 0, KEY_MAX, key);\n  }\n\n  void sort_inc(int l, int r) {\n    if (l == r) return;\n\
    \    split_at(l), split_at(r);\n    while (1) {\n      if (pid > NODES * 0.9)\
    \ rebuild();\n      np c = root[l];\n      int i = ss.next(l + 1);\n      if (i\
    \ == r) break;\n      root[l] = merge(0, KEY_MAX, c, root[i]);\n      ss.erase(i);\n\
    \    }\n    rev[l] = 0;\n  };\n\n  void sort_dec(int l, int r) {\n    if (l ==\
    \ r) return;\n    if (pid > NODES * 0.9) rebuild();\n    sort_inc(l, r), rev[l]\
    \ = 1;\n  };\n\n  vc<int> get_all() {\n    vector<int> key;\n    key.reserve(N);\n\
    \    auto dfs = [&](auto& dfs, np n, int l, int r, bool rev) -> void {\n     \
    \ if (!n || !n->size) return;\n      if (r == l + 1) {\n        FOR(n->size) key.eb(l);\n\
    \        return;\n      }\n      int m = (l + r) / 2;\n      if (!rev) { dfs(dfs,\
    \ n->l, l, m, rev), dfs(dfs, n->r, m, r, rev); }\n      if (rev) { dfs(dfs, n->r,\
    \ m, r, rev), dfs(dfs, n->l, l, m, rev); }\n    };\n    for (int i = 0; i < N;\
    \ ++i) {\n      if (ss[i]) dfs(dfs, root[i], 0, KEY_MAX, rev[i]);\n    }\n   \
    \ return key;\n  }\n\n  int get(int idx) {\n    auto dfs = [&](auto& dfs, np n,\
    \ int l, int r, int k) -> int {\n      if (r == l + 1) { return l; }\n      int\
    \ m = (l + r) / 2;\n      int s = (n->l ? n->l->size : 0);\n      if (k < s) return\
    \ dfs(dfs, n->l, l, m, k);\n      return dfs(dfs, n->r, m, r, k - s);\n    };\n\
    \    int i = ss.prev(idx);\n    int k = idx - i;\n    int s = root[i]->size;\n\
    \    if (rev[i]) k = s - 1 - k;\n    return dfs(dfs, root[i], 0, KEY_MAX, k);\n\
    \  }\n\nprivate:\n  void init(vector<int>& key) {\n    rev.assign(N, 0), root.clear(),\
    \ root.reserve(N);\n    for (int i = 0; i < N; ++i) {\n      ss.insert(i);\n \
    \     root.eb(new_node(0));\n      assert(key[i] < KEY_MAX);\n      set_rec(root[i],\
    \ 0, KEY_MAX, key[i]);\n    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\
    \u3088\u3046\u306B\u3059\u308B\n  void split_at(int x) {\n    if (x == N || ss[x])\
    \ return;\n    int a = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n  \
    \  if (!rev[a]) {\n      auto [nl, nr] = split(root[a], 0, KEY_MAX, x - a);\n\
    \      root[a] = nl, root[x] = nr;\n      rev[a] = rev[x] = 0;\n    } else {\n\
    \      auto [nl, nr] = split(root[a], 0, KEY_MAX, b - x);\n      root[a] = nr,\
    \ root[x] = nl;\n      rev[a] = rev[x] = 1;\n    }\n  }\n\n  void rebuild() {\n\
    \    auto key = get_all();\n    pid = 0;\n    init(key);\n  }\n\n  np new_node(int\
    \ size) {\n    assert(pid < NODES);\n    pool[pid].l = pool[pid].r = nullptr;\n\
    \    pool[pid].size = size;\n    return &(pool[pid++]);\n  }\n\n  pair<np, np>\
    \ split(np n, int l, int r, int k) {\n    if (k == 0) { return {nullptr, n}; }\n\
    \    if (k == n->size) { return {n, nullptr}; }\n    if (r == l + 1) {\n     \
    \ int s = n->size;\n      n->size = k;\n      Node* b = new_node(s - k);\n   \
    \   return {n, b};\n    }\n    int s = (n->l ? n->l->size : 0);\n    Node* b =\
    \ new_node(0);\n    int m = (l + r) / 2;\n    if (k <= s) {\n      auto [nl, nr]\
    \ = split(n->l, l, m, k);\n      b->l = nr, b->r = n->r, n->l = nl, n->r = nullptr;\n\
    \    }\n    if (k > s) {\n      auto [nl, nr] = split(n->r, m, r, k - s);\n  \
    \    n->l = n->l, n->r = nl, b->l = nullptr, b->r = nr;\n    }\n    update(n),\
    \ update(b);\n    return {n, b};\n  }\n\n  np merge(int l, int r, np a, np b)\
    \ {\n    if (!a) return b;\n    if (!b) return a;\n    if (r == l + 1) {\n   \
    \   a->size += b->size;\n      return a;\n    }\n    int m = (l + r) / 2;\n  \
    \  a->l = merge(l, m, a->l, b->l), a->r = merge(m, r, a->r, b->r);\n    update(a);\n\
    \    return a;\n  }\n\n  void update(np n) {\n    if (!(n->l) && !(n->r)) { return;\
    \ }\n    if (!(n->l)) {\n      n->size = n->r->size;\n      return;\n    }\n \
    \   if (!(n->r)) {\n      n->size = n->l->size;\n      return;\n    }\n    n->size\
    \ = n->l->size + n->r->size;\n  }\n\n  void set_rec(np n, int l, int r, int k)\
    \ {\n    if (r == l + 1) {\n      n->size = 1;\n      return;\n    }\n    int\
    \ m = (l + r) / 2;\n    if (k < m) {\n      if (!(n->l)) n->l = new_node(0);\n\
    \      set_rec(n->l, l, m, k);\n    }\n    if (m <= k) {\n      if (!(n->r)) n->r\
    \ = new_node(0);\n      set_rec(n->r, m, r, k);\n    }\n    update(n);\n  }\n\
    };\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n    \
    \  = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n                  \
    \   chrono::high_resolution_clock::now().time_since_epoch())\n               \
    \      .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll\
    \ l, ll r) { return l + RNG_64() % (r - l); }\n#line 8 \"test/mytest/sortable_array.test.cpp\"\
    \n\nvoid test() {\n  int N = RNG(1, 64);\n  int MAX = RNG(2, 20);\n  vc<int> A(N);\n\
    \  FOR(i, N) A[i] = RNG(MAX);\n  Sortable_Array<1000> X(MAX, A);\n\n  int Q =\
    \ 1000;\n  FOR(Q) {\n    int t = RNG(0, 5);\n    if (t == 0) {\n      vc<int>\
    \ B = X.get_all();\n      assert(A == B);\n    }\n    if (t == 0) {\n      int\
    \ idx = RNG(0, N);\n      assert(A[idx] == X.get(idx));\n    }\n    if (t == 2)\
    \ {\n      int idx = RNG(0, N);\n      int x = RNG(MAX);\n      A[idx] = x;\n\
    \      X.set(idx, x);\n    }\n    if (t == 3) {\n      int L = RNG(0, N);\n  \
    \    int R = RNG(0, N);\n      if (L > R) swap(L, R);\n      ++R;\n      X.sort_inc(L,\
    \ R);\n      sort(A.begin() + L, A.begin() + R);\n    }\n    if (t == 4) {\n \
    \     int L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n\
    \      ++R;\n      X.sort_dec(L, R);\n      sort(A.begin() + L, A.begin() + R);\n\
    \      reverse(A.begin() + L, A.begin() + R);\n    }\n  }\n}\n\nvoid solve() {\n\
    \  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  FOR(100) test();\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/sortable_array.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  int N = RNG(1, 64);\n  int\
    \ MAX = RNG(2, 20);\n  vc<int> A(N);\n  FOR(i, N) A[i] = RNG(MAX);\n  Sortable_Array<1000>\
    \ X(MAX, A);\n\n  int Q = 1000;\n  FOR(Q) {\n    int t = RNG(0, 5);\n    if (t\
    \ == 0) {\n      vc<int> B = X.get_all();\n      assert(A == B);\n    }\n    if\
    \ (t == 0) {\n      int idx = RNG(0, N);\n      assert(A[idx] == X.get(idx));\n\
    \    }\n    if (t == 2) {\n      int idx = RNG(0, N);\n      int x = RNG(MAX);\n\
    \      A[idx] = x;\n      X.set(idx, x);\n    }\n    if (t == 3) {\n      int\
    \ L = RNG(0, N);\n      int R = RNG(0, N);\n      if (L > R) swap(L, R);\n   \
    \   ++R;\n      X.sort_inc(L, R);\n      sort(A.begin() + L, A.begin() + R);\n\
    \    }\n    if (t == 4) {\n      int L = RNG(0, N);\n      int R = RNG(0, N);\n\
    \      if (L > R) swap(L, R);\n      ++R;\n      X.sort_dec(L, R);\n      sort(A.begin()\
    \ + L, A.begin() + R);\n      reverse(A.begin() + L, A.begin() + R);\n    }\n\
    \  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n\
    \  FOR(100) test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/sortable_array.hpp
  - ds/fastset.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/sortable_array.test.cpp
  requiredBy: []
  timestamp: '2023-05-20 05:12:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/sortable_array.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/sortable_array.test.cpp
- /verify/test/mytest/sortable_array.test.cpp.html
title: test/mytest/sortable_array.test.cpp
---
