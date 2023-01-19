---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':heavy_check_mark:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/connected_dp.hpp
    title: other/connected_dp.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/hash_vector.hpp
    title: random/hash_vector.hpp
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
  bundledCode: "#line 1 \"test/mytest/tdpc_grid_dp.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n#pragma GCC optimize(\"Ofast\")\n\
    #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] == '?' ? S[i] - first_char :\
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
    \ yes(!t); }\n#line 4 \"test/mytest/tdpc_grid_dp.test.cpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 3 \"ds/hashmap.hpp\"\
    \n\r\n// long long -> Val\r\ntemplate <typename Val, int LOG = 20>\r\nstruct HashMap\
    \ {\r\n  int N;\r\n  ll* keys;\r\n  Val* vals;\r\n  vc<int> IDS;\r\n  bitset<1\
    \ << LOG> used;\r\n  const int shift;\r\n  const uint64_t r = 11995408973635179863ULL;\r\
    \n  HashMap()\r\n      : N(1 << LOG), keys(new ll[N]), vals(new Val[N]), shift(64\
    \ - __lg(N)) {}\r\n  int hash(ll x) {\r\n    static const uint64_t FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (uint64_t(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ ll& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && keys[i] !=\
    \ key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ ll& key) {\r\n    int i = index(key);\r\n    if (!used[i]) IDS.eb(i), used[i]\
    \ = 1, keys[i] = key, vals[i] = Val{};\r\n    return vals[i];\r\n  }\r\n\r\n \
    \ Val get(const ll& key, Val default_value) {\r\n    int i = index(key);\r\n \
    \   if (!used[i]) return default_value;\r\n    return vals[i];\r\n  }\r\n\r\n\
    \  bool count(const ll& key) {\r\n    int i = index(key);\r\n    return used[i]\
    \ && keys[i] == key;\r\n  }\r\n\r\n  void reset() {\r\n    for (auto&& i: IDS)\
    \ used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  vc<pair<ll, Val>> items() {\r\
    \n    vc<pair<ll, Val>> res;\r\n    res.reserve(len(IDS));\r\n    for (auto&&\
    \ i: IDS) res.eb(keys[i], vals[i]);\r\n    return res;\r\n  }\r\n};\r\n#line 2\
    \ \"random/hash_vector.hpp\"\n\n#line 2 \"mod/modint61.hpp\"\nstruct modint61\
    \ {\r\n  static constexpr bool is_modint = true;\r\n  static constexpr ll mod\
    \ = (1LL << 61) - 1;\r\n  ll val;\r\n  constexpr modint61(const ll x = 0) : val(x)\
    \ {\r\n    while (val < 0) val += mod;\r\n    while (val >= mod) val -= mod;\r\
    \n  }\r\n  bool operator<(const modint61 &other) const {\r\n    return val < other.val;\r\
    \n  } // To use std::map\r\n  bool operator==(const modint61 &p) const { return\
    \ val == p.val; }\r\n  bool operator!=(const modint61 &p) const { return val !=\
    \ p.val; }\r\n  modint61 &operator+=(const modint61 &p) {\r\n    if ((val += p.val)\
    \ >= mod) val -= mod;\r\n    return *this;\r\n  }\r\n  modint61 &operator-=(const\
    \ modint61 &p) {\r\n    if ((val += mod - p.val) >= mod) val -= mod;\r\n    return\
    \ *this;\r\n  }\r\n  modint61 &operator*=(const modint61 &p) {\r\n    ll a = val,\
    \ b = p.val;\r\n    const ll MASK30 = (1LL << 30) - 1;\r\n    const ll MASK31\
    \ = (1LL << 31) - 1;\r\n    const ll MASK61 = (1LL << 61) - 1;\r\n    ll au =\
    \ a >> 31, ad = a & MASK31;\r\n    ll bu = b >> 31, bd = b & MASK31;\r\n    ll\
    \ x = ad * bu + au * bd;\r\n    ll xu = x >> 30, xd = x & MASK30;\r\n    x = au\
    \ * bu * 2 + xu + (xd << 31) + ad * bd;\r\n    xu = x >> 61, xd = x & MASK61;\r\
    \n    x = xu + xd;\r\n    if (x >= MASK61) x -= MASK61;\r\n    val = x;\r\n  \
    \  return *this;\r\n  }\r\n  modint61 operator-() const { return modint61(get_mod()\
    \ - val); }\r\n  modint61 &operator/=(const modint61 &p) {\r\n    *this *= p.inverse();\r\
    \n    return *this;\r\n  }\r\n  modint61 operator+(const modint61 &p) const {\
    \ return modint61(*this) += p; }\r\n  modint61 operator-(const modint61 &p) const\
    \ { return modint61(*this) -= p; }\r\n  modint61 operator*(const modint61 &p)\
    \ const { return modint61(*this) *= p; }\r\n  modint61 operator/(const modint61\
    \ &p) const { return modint61(*this) /= p; }\r\n\r\n  modint61 inverse() const\
    \ {\r\n    ll a = val, b = mod, u = 1, v = 0, t;\r\n    while (b > 0) {\r\n  \
    \    t = a / b;\r\n      swap(a -= t * b, b), swap(u -= t * v, v);\r\n    }\r\n\
    \    return modint61(u);\r\n  }\r\n  modint61 pow(int64_t n) const {\r\n    modint61\
    \ ret(1), mul(val);\r\n    while (n > 0) {\r\n      if (n & 1) ret = ret * mul;\r\
    \n      mul = mul * mul;\r\n      n >>= 1;\r\n    }\r\n    return ret;\r\n  }\r\
    \n  static constexpr ll get_mod() { return mod; }\r\n  void write() { fastio::printer.write(val);\
    \ }\r\n  void read() { fastio::scanner.read(val); }\r\n};\r\n#line 5 \"random/hash_vector.hpp\"\
    \n\ntemplate <typename T>\nll hash_vector(vc<T> X) {\n  using mint = modint61;\n\
    \  static vc<mint> hash_base;\n  int n = len(X);\n  while (len(hash_base) <= n)\
    \ { hash_base.eb(RNG(mint::get_mod())); }\n  mint H = 0;\n  FOR(i, n) H += hash_base[i]\
    \ * mint(X[i]);\n  H += hash_base[n];\n  return H.val;\n}\n\ntemplate <typename\
    \ T>\nll hash_pair(pair<T, T> X) {\n  static ll hash_base = 0;\n  if (hash_base\
    \ == 0) hash_base = RNG_64();\n  return hash_base * X.fi + X.se;\n}\n#line 2 \"\
    mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  int val;\n  constexpr\
    \ modint(ll x = 0) noexcept {\n    if (0 <= x && x < mod)\n      val = x;\n  \
    \  else {\n      x %= mod;\n      val = (x < 0 ? x + mod : x);\n    }\n  }\n \
    \ bool operator<(const modint &other) const {\n    return val < other.val;\n \
    \ } // To use std::map\n  modint &operator+=(const modint &p) {\n    if ((val\
    \ += p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator-=(const\
    \ modint &p) {\n    if ((val += mod - p.val) >= mod) val -= mod;\n    return *this;\n\
    \  }\n  modint &operator*=(const modint &p) {\n    val = (int)(1LL * val * p.val\
    \ % mod);\n    return *this;\n  }\n  modint &operator/=(const modint &p) {\n \
    \   *this *= p.inverse();\n    return *this;\n  }\n  modint operator-() const\
    \ { return modint(-val); }\n  modint operator+(const modint &p) const { return\
    \ modint(*this) += p; }\n  modint operator-(const modint &p) const { return modint(*this)\
    \ -= p; }\n  modint operator*(const modint &p) const { return modint(*this) *=\
    \ p; }\n  modint operator/(const modint &p) const { return modint(*this) /= p;\
    \ }\n  bool operator==(const modint &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint &p) const { return val != p.val; }\n  modint inverse()\
    \ const {\n    int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n \
    \     t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n   \
    \ return modint(u);\n  }\n  modint pow(int64_t n) const {\n    modint ret(1),\
    \ mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n\
    \      n >>= 1;\n    }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() {\
    \ fastio::printer.write(val); }\n  void read() {\n    ll x;\n    fastio::scanner.read(x);\n\
    \    if (x < 0 || x >= mod) x %= mod;\n    if (x < 0) x += mod;\n    val += x;\n\
    \  }\n#endif\n  static constexpr int get_mod() { return mod; }\n};\n\nstruct ArbitraryModInt\
    \ {\n  static constexpr bool is_modint = true;\n  int val;\n  ArbitraryModInt()\
    \ : val(0) {}\n  ArbitraryModInt(int64_t y)\n      : val(y >= 0 ? y % get_mod()\n\
    \                   : (get_mod() - (-y) % get_mod()) % get_mod()) {}\n  bool operator<(const\
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
    \ pow(int64_t n) const {\n    ArbitraryModInt ret(1), mul(val);\n    while (n\
    \ > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n  \
    \  }\n    return ret;\n  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val);\
    \ }\n  void read() { fastio::scanner.read(val); }\n#endif\n};\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  static const int mod = mint::get_mod();\n  static\
    \ vector<mint> dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n \
    \ while (int(dat.size()) <= n) {\n    int k = dat.size();\n    auto q = (mod +\
    \ k - 1) / k;\n    int r = k * q - mod;\n    dat.emplace_back(dat[r] * mint(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  assert(0\
    \ <= n);\n  if (n >= mod) return 0;\n  while (int(dat.size()) <= n) {\n    int\
    \ k = dat.size();\n    dat.emplace_back(dat[k - 1] * mint(k));\n  }\n  return\
    \ dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static const\
    \ int mod = mint::get_mod();\n  static vector<mint> dat = {1, 1};\n  assert(-1\
    \ <= n && n < mod);\n  if (n == -1) return mint(0);\n  while (int(dat.size())\
    \ <= n) {\n    int k = dat.size();\n    dat.emplace_back(dat[k - 1] * inv<mint>(k));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts...\
    \ xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename\
    \ mint, class Head, class... Tail>\nmint multinomial(Head &&head, Tail &&... tail)\
    \ {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  static vvc<mint>\
    \ C;\n  static int H = 0, W = 0;\n\n  auto calc = [&](int i, int j) -> mint {\n\
    \    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n\n  if (W <= k) {\n    FOR(i, H) {\n   \
    \   C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n  \
    \  }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H,\
    \ n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n\
    \    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >=\
    \ 0);\n  if (k < 0 || n < k) return 0;\n  if (dense) return C_dense<mint>(n, k);\n\
    \  if (!large) return fact<mint>(n) * fact_inv<mint>(k) * fact_inv<mint>(n - k);\n\
    \  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) { x *= mint(n - i); }\n  x *=\
    \ fact_inv<mint>(k);\n  return x;\n}\n\ntemplate <typename mint, bool large =\
    \ false>\nmint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <=\
    \ n);\n  if (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n -\
    \ k);\n  return mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\
    \u8A08\u7B97\ntemplate <typename mint, bool large = false, bool dense = false>\n\
    mint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n\
    \  if (n == 0) { return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large,\
    \ dense>(n + d - 1, d);\n}\n\nusing modint107 = modint<1000000007>;\nusing modint998\
    \ = modint<998244353>;\nusing amint = ArbitraryModInt;\n#line 3 \"other/connected_dp.hpp\"\
    \n\nnamespace connected_dp_squares {\n// pair<\u65B0\u3057\u3044\u72B6\u614B\u3001\
    \u4ECA\u306E\u6210\u5206 \u2192 \u65B0\u3057\u3044\u6210\u5206>\nvc<pair<vc<int>,\
    \ vc<int>>> next_states(const vc<int>& now) {\n  int N = len(now);\n  vc<pair<vc<int>,\
    \ vc<int>>> res;\n  FOR(s, 1 << N) {\n    vc<int> par(N + N);\n    FOR(i, N) par[i]\
    \ = (s & 1 << i ? i : -1);\n    FOR(i, N) par[N + i] = (now[i] == -1 ? -1 : now[i]\
    \ + N);\n    auto find = [&](int x) -> int {\n      while (par[x] != x) { x =\
    \ par[x] = par[par[x]]; }\n      return x;\n    };\n    auto merge = [&](int a,\
    \ int b) -> void {\n      a = find(a), b = find(b);\n      if (a == b) return;\n\
    \      if (a > b) swap(a, b);\n      par[b] = a;\n    };\n\n    FOR(i, N - 1)\
    \ if (par[i] != -1 && par[i + 1] != -1) merge(i, i + 1);\n    FOR(i, N) if (par[i]\
    \ != -1 && par[N + i] != -1) merge(i, N + i);\n    FOR(i, N + N) if (par[i] !=\
    \ -1) par[i] = find(i);\n    FOR(i, N, N + N) if (par[i] >= N) par[i] = -1;\n\
    \    res.eb(vc<int>(par.begin(), par.begin() + N),\n           vc<int>(par.begin()\
    \ + N, par.end()));\n  }\n  return res;\n}\n\nvc<int> reverse_state(const vc<int>&\
    \ now) {\n  int N = len(now);\n  vc<int> max_i(N, -1);\n  FOR(i, N) if (now[i]\
    \ != -1) max_i[now[i]] = i;\n  vc<int> rev(N, -1);\n  FOR(i, N) {\n    if (now[i]\
    \ == -1) continue;\n    int x = max_i[now[i]];\n    rev[N - 1 - i] = N - 1 - x;\n\
    \  }\n  return rev;\n}\n\n// 0, 1 \uFF1A\u7A7A\u306E\u5217\u3001\u9818\u57DF\u306E\
    \u624B\u524D\u3001\u5F8C\u308D\n// \u9023\u7D50\u9818\u57DF\u3092\u3072\u3068\u3064\
    \u4F5C\u308B\u3002\u591A\u89D2\u5F62\u3068\u306F\u9650\u3089\u306A\u3044\u3002\
    \npair<vvc<int>, vc<pair<int, int>>> connedted_dp_graph(int N,\n             \
    \                                         bool merge_reverse) {\n  static HashMap<int>\
    \ MP;\n  MP.reset();\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n  states.eb(vc<int>(N,\
    \ -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])] = 0;\n\
    \n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n    if (p\
    \ == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int> now = states[p];\n\
    \    for (auto&& [nxt, convert]: next_states(now)) {\n      // \u4ECA\u306E\u6210\
    \u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n\
    \      FOR(v, N) if (now[v] == v) {\n        ++a;\n        if (convert[v] == -1)\
    \ ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\
    \u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\
    \u306E\u307F\n      if (b >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt)\
    \ != -1) continue;\n        edges.eb(p, 1);\n        continue;\n      }\n    \
    \  ll h = hash_vector<int>(nxt);\n      if (merge_reverse) { chmin(h, hash_vector<int>(reverse_state(nxt)));\
    \ }\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt);\n\
    \      }\n      edges.eb(p, MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\
    \npair<vvc<int>, vc<pair<int, int>>> polygon_dp_graph(int N) {\n  static HashMap<int>\
    \ MP;\n  MP.reset();\n  vvc<int> states;\n  vc<pair<int, int>> edges;\n\n  states.eb(vc<int>(N,\
    \ -1));\n  states.eb(vc<int>(N, -1));\n  MP[hash_vector<int>(states[0])] = 0;\n\
    \n  int p = -1;\n  while (1) {\n    if (++p == len(states)) break;\n    if (p\
    \ == 1) {\n      edges.eb(1, 1);\n      continue;\n    }\n    vc<int> now = states[p];\n\
    \    for (auto&& [nxt, convert]: next_states(now)) {\n      // \u4ECA\u306E\u6210\
    \u5206\u6570\u3001\u6D88\u3048\u308B\u6210\u5206\u6570\n      int a = 0, b = 0;\n\
    \      FOR(v, N) if (now[v] == v) {\n        ++a;\n        if (convert[v] == -1)\
    \ ++b;\n      }\n      // \u6D88\u3048\u308B\u6210\u5206\u304C\u3042\u3063\u3066\
    \u3088\u3044\u306E\u306F\u3001\u7D42\u72B6\u614B\u306B\u3044\u304F\u3068\u304D\
    \u306E\u307F\n      if (b >= 2) continue;\n      if (b == 1) {\n        if (MAX(nxt)\
    \ != -1) continue;\n        edges.eb(p, 1);\n        continue;\n      }\n    \
    \  bool ok = [&](vc<int>& now, vc<int>& nxt, vc<int>& convert) -> bool {\n   \
    \     // \u9802\u70B9\u306E\u307F\u3067\u63A5\u3059\u308B\u306E\u306F\u30C0\u30E1\
    \n        FOR(i, N - 1) {\n          bool a1 = now[i] != -1, a2 = now[i + 1] !=\
    \ -1;\n          bool b1 = nxt[i] != -1, b2 = nxt[i + 1] != -1;\n          if\
    \ (a1 && !a2 && !b1 && b2) return false;\n          if (!a1 && a2 && b1 && !b2)\
    \ return false;\n        }\n        // empty region \u3092\u9589\u3058\u308B\u3053\
    \u3068\u3068\u3001\u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u304C\u30DE\u30FC\
    \u30B8\u3055\u308C\u308B\u3053\u3068\u304C\u540C\u5024\n        int close = 0;\n\
    \        int after = 0;\n        vc<bool> is_new(N, 1);\n        FOR(i, N) if\
    \ (convert[i] != -1) is_new[convert[i]] = 0;\n        FOR(i, N) if (nxt[i] ==\
    \ i && !is_new[i])++ after;\n        vc<int> I;\n        FOR(i, N) if (now[i]\
    \ != -1) I.eb(i);\n        FOR(k, len(I) - 1) {\n          int i = I[k], j = I[k\
    \ + 1];\n          if (j == i + 1) continue;\n          bool cl = 1;\n       \
    \   FOR(p, i + 1, j) if (nxt[p] == -1) cl = 0;\n          if (cl) close++;\n \
    \       }\n        return a - close == after;\n      }(now, nxt, convert);\n \
    \     if (!ok) continue;\n      ll h = hash_vector<int>(nxt);\n      if (!MP.count(h))\
    \ {\n        MP[h] = len(states);\n        states.eb(nxt);\n      }\n      edges.eb(p,\
    \ MP[h]);\n    }\n  }\n  return {states, edges};\n}\n\n} // namespace connected_dp_squares\n\
    #line 9 \"test/mytest/tdpc_grid_dp.test.cpp\"\n\nusing mint = modint107;\n\nmint\
    \ calc_tdpc_grid(int H, int W) {\n  HashMap<int> MP;\n\n  using P = pair<vc<int>,\
    \ int>;\n  vc<P> states;\n\n  auto get_hash = [&](vc<int> a, int b) -> ll {\n\
    \    a.eb(b);\n    return hash_vector<int>(a);\n  };\n\n  vc<int> init(H, -1);\n\
    \  init[0] = 0;\n  states.eb(init, 0);\n  vc<int> end(H, -1);\n  end[H - 1] =\
    \ H - 1;\n  states.eb(end, H - 1);\n  FOR(i, 2) {\n    auto [a, b] = states[i];\n\
    \    ll h = get_hash(a, b);\n    MP[h] = i;\n  }\n\n  vc<pi> edges;\n\n  int p\
    \ = -1;\n  while (1) {\n    ++p;\n    if (p >= len(states)) break;\n    auto [now,\
    \ r] = states[p];\n    for (auto&& [nxt, convert]: connected_dp_squares::next_states(now))\
    \ {\n      int s = convert[r];\n      if (s == -1) continue;\n      ll h = get_hash(nxt,\
    \ s);\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt,\
    \ s);\n      }\n      edges.eb(p, MP[h]);\n    }\n  }\n\n  int S = len(states);\n\
    \  vc<mint> dp(S);\n  dp[0] = mint(1);\n  FOR(W + 1) {\n    vc<mint> newdp(S);\n\
    \    for (auto&& [a, b]: edges) newdp[b] += dp[a];\n    swap(dp, newdp);\n  }\n\
    \  return dp[1];\n}\n\nvoid test() {\n  assert(calc_tdpc_grid(2, 2).val == 3);\n\
    \  assert(calc_tdpc_grid(5, 8).val == 950397139);\n  assert(calc_tdpc_grid(8,\
    \ 5).val == 950397139);\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\
    \nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"ds/hashmap.hpp\"\n#include \"random/hash_vector.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"other/connected_dp.hpp\"\n\nusing mint\
    \ = modint107;\n\nmint calc_tdpc_grid(int H, int W) {\n  HashMap<int> MP;\n\n\
    \  using P = pair<vc<int>, int>;\n  vc<P> states;\n\n  auto get_hash = [&](vc<int>\
    \ a, int b) -> ll {\n    a.eb(b);\n    return hash_vector<int>(a);\n  };\n\n \
    \ vc<int> init(H, -1);\n  init[0] = 0;\n  states.eb(init, 0);\n  vc<int> end(H,\
    \ -1);\n  end[H - 1] = H - 1;\n  states.eb(end, H - 1);\n  FOR(i, 2) {\n    auto\
    \ [a, b] = states[i];\n    ll h = get_hash(a, b);\n    MP[h] = i;\n  }\n\n  vc<pi>\
    \ edges;\n\n  int p = -1;\n  while (1) {\n    ++p;\n    if (p >= len(states))\
    \ break;\n    auto [now, r] = states[p];\n    for (auto&& [nxt, convert]: connected_dp_squares::next_states(now))\
    \ {\n      int s = convert[r];\n      if (s == -1) continue;\n      ll h = get_hash(nxt,\
    \ s);\n      if (!MP.count(h)) {\n        MP[h] = len(states);\n        states.eb(nxt,\
    \ s);\n      }\n      edges.eb(p, MP[h]);\n    }\n  }\n\n  int S = len(states);\n\
    \  vc<mint> dp(S);\n  dp[0] = mint(1);\n  FOR(W + 1) {\n    vc<mint> newdp(S);\n\
    \    for (auto&& [a, b]: edges) newdp[b] += dp[a];\n    swap(dp, newdp);\n  }\n\
    \  return dp[1];\n}\n\nvoid test() {\n  assert(calc_tdpc_grid(2, 2).val == 3);\n\
    \  assert(calc_tdpc_grid(5, 8).val == 950397139);\n  assert(calc_tdpc_grid(8,\
    \ 5).val == 950397139);\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\
    \nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/hashmap.hpp
  - random/base.hpp
  - random/hash_vector.hpp
  - mod/modint61.hpp
  - mod/modint.hpp
  - other/connected_dp.hpp
  isVerificationFile: true
  path: test/mytest/tdpc_grid_dp.test.cpp
  requiredBy: []
  timestamp: '2023-01-19 03:43:58+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/tdpc_grid_dp.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/tdpc_grid_dp.test.cpp
- /verify/test/mytest/tdpc_grid_dp.test.cpp.html
title: test/mytest/tdpc_grid_dp.test.cpp
---
