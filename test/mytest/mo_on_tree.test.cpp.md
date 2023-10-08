---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/monoid_reverse.hpp
    title: alg/monoid/monoid_reverse.hpp
  - icon: ':heavy_check_mark:'
    path: ds/offline_query/mo.hpp
    title: ds/offline_query/mo.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/mo_on_tree.hpp
    title: graph/ds/mo_on_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/tree_monoid.hpp
    title: graph/ds/tree_monoid.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
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
  bundledCode: "#line 1 \"test/mytest/mo_on_tree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T, typename U>\n\
    T ceil(T x, U y) {\n  return (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <typename\
    \ T, typename U>\nT floor(T x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) /\
    \ y);\n}\ntemplate <typename T, typename U>\nT bmod(T x, U y) {\n  return x -\
    \ y * floor(x, y);\n}\ntemplate <typename T, typename U>\npair<T, T> divmod(T\
    \ x, U y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const vector<U> &A) {\n  T sum = 0;\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
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
    \ yes(!t); }\n#line 4 \"test/mytest/mo_on_tree.test.cpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"graph/tree.hpp\"\
    \n\r\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int\
    \ frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed\
    \ = false>\nstruct Graph {\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n  constexpr bool is_directed() { return directed; }\n\n\
    \  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n  // wt, off\n  void read_tree(bool wt = false, int off = 1)\
    \ { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false,\
    \ int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a\
    \ -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n      } else {\n  \
    \      T c;\n        read(c);\n        add(a, b, c);\n      }\n    }\n    build();\n\
    \  }\n\n  void build() {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if\
    \ (!directed) indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v\
    \ + 1] += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n  void debug() {\n    print(\"Graph\");\n  \
    \  if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n\
    \      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n\n  vc<int> new_idx;\n  vc<bool>\
    \ used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\
    \u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  // {G, es}\n  pair<Graph<T, directed>, vc<int>> rearrange(vc<int> V)\
    \ {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    if (len(used_e) !=\
    \ M) used_e.assign(M, 0);\n    int n = len(V);\n    FOR(i, n) new_idx[V[i]] =\
    \ i;\n    Graph<T, directed> G(n);\n    vc<int> es;\n    FOR(i, n) {\n      for\
    \ (auto&& e: (*this)[V[i]]) {\n        if (used_e[e.id]) continue;\n        int\
    \ a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] != -1) {\n\
    \          used_e[e.id] = 1;\n          G.add(new_idx[a], new_idx[b], e.cost);\n\
    \          es.eb(e.id);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]]\
    \ = -1;\n    for (auto&& eid: es) used_e[eid] = 0;\n    G.build();\n    return\
    \ {G, es};\n  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n\
    \    vc_deg.resize(N);\n    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n\
    \  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n\
    \    vc_outdeg.resize(N);\n    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++;\
    \ }\n  }\n};\n#line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\
    \u3066\u3044\u308D\u3044\u308D\u3002\r\ntemplate <typename GT>\r\nstruct Tree\
    \ {\r\n  using Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\
    \n  int N;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\
    \n  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G)\
    \ { build(r, hld); }\r\n\r\n  void build(int r = 0, bool hld = 1) {\r\n    if\
    \ (r == -1) return; // build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\r\
    \n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);\r\
    \n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\r\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void\
    \ dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\
    \n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l\
    \ = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    //\
    \ \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n\
    \    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: G[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\n\
    \      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n    \
    \  dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a] && head[e.to] ==\
    \ v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\n\
    \      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ heavy_child(int v) {\r\n    int k = LID[v] + 1;\r\n    if (k == N) return -1;\r\
    \n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\n  }\r\n\r\n  int\
    \ e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n    return (parent[e.frm]\
    \ == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\
    \n\r\n  int ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v)\
    \ { return 2 * RID[v] - depth[v] - 1; }\r\n\r\n  // \u76EE\u6A19\u5730\u70B9\u3078\
    \u9032\u3080\u500B\u6570\u304C k\r\n  int LA(int v, int k) {\r\n    assert(k <=\
    \ depth[v]);\r\n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v]\
    \ - k >= LID[u]) return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n\
    \      v = parent[u];\r\n    }\r\n  }\r\n  int la(int u, int v) { return LA(u,\
    \ v); }\r\n\r\n  int LCA(int u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\
    \n      if (LID[u] > LID[v]) swap(u, v);\r\n      if (head[u] == head[v]) return\
    \ u;\r\n    }\r\n  }\r\n  // root \u3092\u6839\u3068\u3057\u305F\u5834\u5408\u306E\
    \ lca\r\n  int LCA_root(int u, int v, int root) {\r\n    return LCA(u, v) ^ LCA(u,\
    \ root) ^ LCA(v, root);\r\n  }\r\n  int lca(int u, int v) { return LCA(u, v);\
    \ }\r\n  int lca_root(int u, int v, int root) { return LCA_root(u, v, root); }\r\
    \n\r\n  int subtree_size(int v, int root = -1) {\r\n    if (root == -1) return\
    \ RID[v] - LID[v];\r\n    if (v == root) return N;\r\n    int x = jump(v, root,\
    \ 1);\r\n    if (in_subtree(v, x)) return RID[v] - LID[v];\r\n    return N - RID[x]\
    \ + LID[x];\r\n  }\r\n\r\n  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\
    \n    return depth[a] + depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  WT dist_weighted(int\
    \ a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth_weighted[a] + depth_weighted[b]\
    \ - WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int\
    \ a, int b, ll k) {\r\n    if (k == 1) {\r\n      if (a == b) return -1;\r\n \
    \     return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\
    \n    }\r\n    int c = LCA(a, b);\r\n    int d_ac = depth[a] - depth[c];\r\n \
    \   int d_bc = depth[b] - depth[c];\r\n    if (k > d_ac + d_bc) return -1;\r\n\
    \    if (k <= d_ac) return LA(a, k);\r\n    return LA(b, d_ac + d_bc - k);\r\n\
    \  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\n    for (auto\
    \ &&e: G[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n    return res;\r\
    \n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int u, int v, bool edge)\
    \ {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\
    \r\n    vc<pair<int, int>> up, down;\r\n    while (1) {\r\n      if (head[u] ==\
    \ head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]],\
    \ LID[v]);\r\n        v = parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u],\
    \ LID[head[u]]);\r\n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if\
    \ (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge\
    \ <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(),\
    \ all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int> restore_path(int u, int\
    \ v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n};\r\n#line 1 \"ds/offline_query/mo.hpp\"\nstruct Mo\
    \ {\r\n  vc<pair<int, int>> LR;\r\n  void add(int L, int R) { LR.emplace_back(L,\
    \ R); }\r\n\r\n  static vc<int> get_mo_order(vc<pair<int, int>> LR) {\r\n    int\
    \ N = 1;\r\n    for (auto &&[l, r]: LR) chmax(N, l), chmax(N, r);\r\n    int Q\
    \ = len(LR);\r\n    if (Q == 0) return {};\r\n    int bs = sqrt(3) * N / sqrt(2\
    \ * Q);\r\n    chmax(bs, 1);\r\n    vc<int> I(Q);\r\n    iota(all(I), 0);\r\n\
    \    sort(all(I), [&](int a, int b) {\r\n      int aa = LR[a].fi / bs, bb = LR[b].fi\
    \ / bs;\r\n      if (aa != bb) return aa < bb;\r\n      return (aa & 1) ? LR[a].se\
    \ > LR[b].se : LR[a].se < LR[b].se;\r\n    });\r\n\r\n    auto cost = [&](int\
    \ a, int b) -> int {\r\n      return abs(LR[I[a]].fi - LR[I[b]].fi) + abs(LR[I[a]].se\
    \ - LR[I[b]].se);\r\n    };\r\n\r\n    // \u30E9\u30F3\u30C0\u30E0\u30B1\u30FC\
    \u30B9\u3067\u6570\u30D1\u30FC\u30BB\u30F3\u30C8\r\n    FOR(k, Q - 5) {\r\n  \
    \    if (cost(k, k + 2) + cost(k + 1, k + 3)\r\n          < cost(k, k + 1) + cost(k\
    \ + 2, k + 3)) {\r\n        swap(I[k + 1], I[k + 2]);\r\n      }\r\n      if (cost(k,\
    \ k + 3) + cost(k + 1, k + 4)\r\n          < cost(k, k + 1) + cost(k + 3, k +\
    \ 4)) {\r\n        swap(I[k + 1], I[k + 3]);\r\n      }\r\n    }\r\n    return\
    \ I;\r\n  }\r\n\r\n  template <typename F1, typename F2, typename F3, typename\
    \ F4, typename F5>\r\n  void calc(F1 add_l, F2 add_r, F3 rm_l, F4 rm_r, F5 query)\
    \ {\r\n    auto I = get_mo_order(LR);\r\n    int l = 0, r = 0;\r\n    for (auto\
    \ idx: I) {\r\n      while (l > LR[idx].fi) add_l(--l);\r\n      while (r < LR[idx].se)\
    \ add_r(r++);\r\n      while (l < LR[idx].fi) rm_l(l++);\r\n      while (r > LR[idx].se)\
    \ rm_r(--r);\r\n      query(idx);\r\n    }\r\n  }\r\n};\r\n#line 3 \"graph/ds/mo_on_tree.hpp\"\
    \n\n// https://codeforces.com/contest/852/problem/I\n// \u3068\u308A\u3042\u3048\
    \u305A\u30D1\u30B9\u306E\u5411\u304D\u304C\u306A\u3044\u3082\u306E\u3068\u3057\
    \u3066\u4F5C\u6210\n// \u672A\u5BFE\u5FDC\uFF1A\u30D1\u30B9\u306E\u5411\u304D\u3042\
    \u308A / \u8FBA\u30C7\u30FC\u30BF\ntemplate <typename TREE, bool ORIENTED = false>\n\
    struct Mo_on_Tree {\n  TREE& tree;\n  vc<pair<int, int>> LR;\n\n  Mo mo;\n  Mo_on_Tree(TREE&\
    \ tree) : tree(tree) {}\n  void add(int u, int v) {\n    if constexpr (!ORIENTED)\
    \ {\n      if (tree.LID[u] > tree.LID[v]) swap(u, v);\n    }\n    LR.eb(tree.ELID(u)\
    \ + 1, tree.ELID(v) + 1);\n  }\n\n  // init(): root \u3060\u3051\u304B\u3089\u306A\
    \u308B path\n  // add_l(v), add_r(v)\uFF1A\u30D1\u30B9\u306E\u5148\u982D / \u672B\
    \u5C3E\u306B v \u3092\u8FFD\u52A0\n  // rm_l(v), rm_r(v)\uFF1A\u30D1\u30B9\u306E\
    \u5148\u982D / \u672B\u5C3E\u304B\u3089 v \u3092\u524A\u9664\n  // query(qid)\n\
    \  template <typename F1, typename F2, typename F3, typename F4, typename F5,\n\
    \            typename F6>\n  void calc_vertex(F1 init, F2 add_l, F3 add_r, F4\
    \ rm_l, F5 rm_r, F6 query) {\n    const int N = tree.G.N;\n    auto I = Mo::get_mo_order(LR);\n\
    \n    vc<int> FRM(2 * N), TO(2 * N), idx(2 * N);\n    vc<int> cnt(N);\n    deque<int>\
    \ path = {0};\n    FOR(v, N) {\n      int a = tree.ELID(v), b = tree.ERID(v);\n\
    \      FRM[a] = tree.parent[v], TO[a] = v;\n      FRM[b] = v, TO[b] = tree.parent[v];\n\
    \      idx[a] = idx[b] = v;\n    }\n\n    auto flip_left = [&](int i) -> void\
    \ {\n      const int a = FRM[i], b = TO[i], c = idx[i];\n      if (cnt[c] == 0)\
    \ {\n        int v = path.front() ^ a ^ b;\n        path.emplace_front(v), add_l(v);\n\
    \      } else {\n        int v = path.front();\n        path.pop_front(), rm_l(v);\n\
    \      }\n      cnt[c] ^= 1;\n    };\n    auto flip_right = [&](int i) -> void\
    \ {\n      const int a = FRM[i], b = TO[i], c = idx[i];\n      if (cnt[c] == 0)\
    \ {\n        int v = path.back() ^ a ^ b;\n        path.emplace_back(v), add_r(v);\n\
    \      } else {\n        int v = path.back();\n        path.pop_back(), rm_r(v);\n\
    \      }\n      cnt[c] ^= 1;\n    };\n\n    init();\n\n    int l = 1, r = 1;\n\
    \    for (auto idx: I) {\n      int L = LR[idx].fi, R = LR[idx].se;\n      while\
    \ (l > L) { flip_left(--l); }\n      while (r < R) { flip_right(r++); }\n    \
    \  while (l < L) { flip_left(l++); }\n      while (r > R) { flip_right(--r); }\n\
    \      query(idx);\n    }\n  }\n\n  // init(): root \u3060\u3051\u304B\u3089\u306A\
    \u308B path\n  // add_l(frm, to), add_r(frm, to)\uFF1A\u30D1\u30B9\u306E\u5148\
    \u982D / \u672B\u5C3E\u306B (frm,to) \u3092\u8FFD\u52A0\n  // rm_l(frm, to), rm_r(frm,\
    \ to)\uFF1A\u30D1\u30B9\u306E\u5148\u982D / \u672B\u5C3E\u306B (frm,to) \u3092\
    \u8FFD\u52A0\n  // query(qid)\n  template <typename F1, typename F2, typename\
    \ F3, typename F4, typename F5,\n            typename F6>\n  void calc_edge(F1\
    \ init, F2 add_l, F3 add_r, F4 rm_l, F5 rm_r, F6 query) {\n    const int N = tree.G.N;\n\
    \    auto I = Mo::get_mo_order(LR);\n\n    vc<int> FRM(2 * N), TO(2 * N), idx(2\
    \ * N);\n    vc<int> cnt(N);\n    deque<int> path = {0};\n    FOR(v, N) {\n  \
    \    int a = tree.ELID(v), b = tree.ERID(v);\n      FRM[a] = tree.parent[v], TO[a]\
    \ = v;\n      FRM[b] = v, TO[b] = tree.parent[v];\n      idx[a] = idx[b] = v;\n\
    \    }\n\n    auto flip_left = [&](int i) -> void {\n      const int a = FRM[i],\
    \ b = TO[i], c = idx[i];\n      if (cnt[c] == 0) {\n        int v = path.front()\
    \ ^ a ^ b;\n        path.emplace_front(v), add_l(v, v ^ a ^ b);\n      } else\
    \ {\n        int v = path.front();\n        path.pop_front(), rm_l(v, v ^ a ^\
    \ b);\n      }\n      cnt[c] ^= 1;\n    };\n    auto flip_right = [&](int i) ->\
    \ void {\n      const int a = FRM[i], b = TO[i], c = idx[i];\n      if (cnt[c]\
    \ == 0) {\n        int v = path.back() ^ a ^ b;\n        path.emplace_back(v),\
    \ add_r(v ^ a ^ b, v);\n      } else {\n        int v = path.back();\n       \
    \ path.pop_back(), rm_r(v ^ a ^ b, v);\n      }\n      cnt[c] ^= 1;\n    };\n\n\
    \    init();\n\n    int l = 1, r = 1;\n    for (auto idx: I) {\n      int L =\
    \ LR[idx].fi, R = LR[idx].se;\n      while (l > L) { flip_left(--l); }\n     \
    \ while (r < R) { flip_right(r++); }\n      while (l < L) { flip_left(l++); }\n\
    \      while (r > R) { flip_right(--r); }\n      query(idx);\n    }\n  }\n};\n\
    #line 2 \"graph/ds/tree_monoid.hpp\"\n\r\n#line 2 \"ds/segtree/segtree.hpp\"\n\
    \ntemplate <class Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X =\
    \ typename MX::value_type;\n  using value_type = X;\n  vc<X> dat;\n  int n, log,\
    \ size;\n\n  SegTree() {}\n  SegTree(int n) { build(n); }\n  template <typename\
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
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 2 \"alg/monoid/monoid_reverse.hpp\"\n\r\ntemplate <class Monoid>\r\
    \nstruct Monoid_Reverse {\r\n  using value_type = typename Monoid::value_type;\r\
    \n  using X = value_type;\r\n  static constexpr X op(const X &x, const X &y) {\
    \ return Monoid::op(y, x); }\r\n  static constexpr X unit() { return Monoid::unit();\
    \ }\r\n  static const bool commute = Monoid::commute;\r\n};\r\n#line 6 \"graph/ds/tree_monoid.hpp\"\
    \n\r\ntemplate <typename TREE, typename Monoid, bool edge>\r\nstruct Tree_Monoid\
    \ {\r\n  using MX = Monoid;\r\n  using X = typename MX::value_type;\r\n  TREE\
    \ &tree;\r\n  int N;\r\n  SegTree<MX> seg;\r\n  SegTree<Monoid_Reverse<MX>> seg_r;\r\
    \n\r\n  Tree_Monoid(TREE &tree) : tree(tree), N(tree.N) {\r\n    build([](int\
    \ i) -> X { return MX::unit(); });\r\n  }\r\n\r\n  Tree_Monoid(TREE &tree, vc<X>\
    \ &dat) : tree(tree), N(tree.N) {\r\n    build([&](int i) -> X { return dat[i];\
    \ });\r\n  }\r\n\r\n  template <typename F>\r\n  Tree_Monoid(TREE &tree, F f)\
    \ : tree(tree), N(tree.N) {\r\n    build(f);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  void build(F f) {\r\n    if (!edge) {\r\n      auto f_v = [&](int i)\
    \ -> X { return f(tree.V[i]); };\r\n      seg.build(N, f_v);\r\n      if constexpr\
    \ (!MX::commute) { seg_r.build(N, f_v); }\r\n    } else {\r\n      auto f_e =\
    \ [&](int i) -> X {\r\n        return (i == 0 ? MX::unit() : f(tree.v_to_e(tree.V[i])));\r\
    \n      };\r\n      seg.build(N, f_e);\r\n      if constexpr (!MX::commute) {\
    \ seg_r.build(N, f_e); }\r\n    }\r\n  }\r\n\r\n  void set(int i, X x) {\r\n \
    \   if constexpr (edge) i = tree.e_to_v(i);\r\n    i = tree.LID[i];\r\n    seg.set(i,\
    \ x);\r\n    if constexpr (!MX::commute) seg_r.set(i, x);\r\n  }\r\n\r\n  void\
    \ multiply(int i, X x) {\r\n    if constexpr (edge) i = tree.e_to_v(i);\r\n  \
    \  i = tree.LID[i];\r\n    seg.multiply(i, x);\r\n    if constexpr (!MX::commute)\
    \ seg_r.multiply(i, x);\r\n  }\r\n\r\n  X prod_path(int u, int v) {\r\n    auto\
    \ pd = tree.get_path_decomposition(u, v, edge);\r\n    X val = MX::unit();\r\n\
    \    for (auto &&[a, b]: pd) { val = MX::op(val, get_prod(a, b)); }\r\n    return\
    \ val;\r\n  }\r\n\r\n  // uv path \u4E0A\u3067 prod_path(u, x) \u304C check \u3092\
    \u6E80\u305F\u3059\u6700\u5F8C\u306E x\r\n  // \u306A\u3051\u308C\u3070 \uFF08\
    \u3064\u307E\u308A path(u,u) \u304C ng \uFF09-1\r\n  template <class F>\r\n  int\
    \ max_path(F check, int u, int v) {\r\n    if constexpr (edge) return max_path_edge(check,\
    \ u, v);\r\n    if (!check(prod_path(u, u))) return -1;\r\n    auto pd = tree.get_path_decomposition(u,\
    \ v, edge);\r\n    X val = MX::unit();\r\n    for (auto &&[a, b]: pd) {\r\n  \
    \    X x = get_prod(a, b);\r\n      if (check(MX::op(val, x))) {\r\n        val\
    \ = MX::op(val, x);\r\n        u = (tree.V[b]);\r\n        continue;\r\n     \
    \ }\r\n      auto check_tmp = [&](X x) -> bool { return check(MX::op(val, x));\
    \ };\r\n      if (a <= b) {\r\n        // \u4E0B\u308A\r\n        auto i = seg.max_right(check_tmp,\
    \ a);\r\n        return (i == a ? u : tree.V[i - 1]);\r\n      } else {\r\n  \
    \      // \u4E0A\u308A\r\n        int i = 0;\r\n        if constexpr (MX::commute)\
    \ i = seg.min_left(check_tmp, a + 1);\r\n        if constexpr (!MX::commute) i\
    \ = seg_r.min_left(check_tmp, a + 1);\r\n        if (i == a + 1) return u;\r\n\
    \        return tree.V[i];\r\n      }\r\n    }\r\n    return v;\r\n  }\r\n\r\n\
    \  X prod_subtree(int u) {\r\n    int l = tree.LID[u], r = tree.RID[u];\r\n  \
    \  return seg.prod(l + edge, r);\r\n  }\r\n\r\n  X prod_all() { return prod_subtree(tree.V[0]);\
    \ }\r\n\r\n  inline X get_prod(int a, int b) {\r\n    if constexpr (MX::commute)\
    \ {\r\n      return (a <= b) ? seg.prod(a, b + 1) : seg.prod(b, a + 1);\r\n  \
    \  }\r\n    return (a <= b) ? seg.prod(a, b + 1) : seg_r.prod(b, a + 1);\r\n \
    \ }\r\n\r\nprivate:\r\n  template <class F>\r\n  int max_path_edge(F check, int\
    \ u, int v) {\r\n    static_assert(edge);\r\n    if (!check(MX::unit())) return\
    \ -1;\r\n    int lca = tree.lca(u, v);\r\n    auto pd = tree.get_path_decomposition(u,\
    \ lca, edge);\r\n    X val = MX::unit();\r\n\r\n    // climb\r\n    for (auto\
    \ &&[a, b]: pd) {\r\n      assert(a >= b);\r\n      X x = get_prod(a, b);\r\n\
    \      if (check(MX::op(val, x))) {\r\n        val = MX::op(val, x);\r\n     \
    \   u = (tree.parent[tree.V[b]]);\r\n        continue;\r\n      }\r\n      auto\
    \ check_tmp = [&](X x) -> bool { return check(MX::op(val, x)); };\r\n      int\
    \ i = 0;\r\n      if constexpr (MX::commute) i = seg.min_left(check_tmp, a + 1);\r\
    \n      if constexpr (!MX::commute) i = seg_r.min_left(check_tmp, a + 1);\r\n\
    \      if (i == a + 1) return u;\r\n      return tree.parent[tree.V[i]];\r\n \
    \   }\r\n    // down\r\n    pd = tree.get_path_decomposition(lca, v, edge);\r\n\
    \    for (auto &&[a, b]: pd) {\r\n      assert(a <= b);\r\n      X x = get_prod(a,\
    \ b);\r\n      if (check(MX::op(val, x))) {\r\n        val = MX::op(val, x);\r\
    \n        u = (tree.V[b]);\r\n        continue;\r\n      }\r\n      auto check_tmp\
    \ = [&](X x) -> bool { return check(MX::op(val, x)); };\r\n      auto i = seg.max_right(check_tmp,\
    \ a);\r\n      return (i == a ? u : tree.V[i - 1]);\r\n    }\r\n    return v;\r\
    \n  }\r\n};\r\n#line 2 \"alg/monoid/affine.hpp\"\n\n// op(F, G) = comp(G,F), F\
    \ \u306E\u3042\u3068\u3067 G\ntemplate <typename K>\nstruct Monoid_Affine {\n\
    \  using F = pair<K, K>;\n  using value_type = F;\n  using X = value_type;\n \
    \ static constexpr F op(const F &x, const F &y) noexcept {\n    return F({x.first\
    \ * y.first, x.second * y.first + y.second});\n  }\n  static constexpr F inverse(const\
    \ F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n\
    \  }\n  static constexpr K eval(const F &f, K x) noexcept {\n    return f.first\
    \ * x + f.second;\n  }\n  static constexpr F unit() { return {K(1), K(0)}; }\n\
    \  static constexpr bool commute = false;\n};\n#line 2 \"alg/monoid/add_pair.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add_Pair {\r\n  using value_type\
    \ = pair<E, E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X\
    \ &x, const X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static\
    \ constexpr X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr\
    \ X unit() { return {0, 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\
    \n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl {\n  template <class\
    \ T>\n  static auto check(T &&x) -> decltype(x.get_mod(), std::true_type{});\n\
    \  template <class T>\n  static auto check(...) -> std::false_type;\n};\n\ntemplate\
    \ <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1)\
    \ * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head, class...\
    \ Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n\
    \  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1)\
    \ : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if\
    \ (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k +\
    \ 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n\
    \    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j,\
    \ W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n\
    }\n\ntemplate <typename mint, bool large = false, bool dense = false>\nmint C(ll\
    \ n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr\
    \ (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d] (1-x) ^ {-n} \u306E\u8A08\u7B97\n\
    template <typename mint, bool large = false, bool dense = false>\nmint C_negative(ll\
    \ n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\
    \ return (d == 0 ? mint(1) : mint(0)); }\n  return C<mint, large, dense>(n + d\
    \ - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint\
    \ {\n  static constexpr u32 umod = u32(mod);\n  static_assert(umod < u32(1) <<\
    \ 31);\n  u32 val;\n\n  static modint raw(u32 v) {\n    modint x;\n    x.val =\
    \ v;\n    return x;\n  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32\
    \ x) : val(x % umod) {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr\
    \ modint(int x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(ll\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const modint &other)\
    \ const { return val < other.val; }\n  modint &operator+=(const modint &p) {\n\
    \    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint &p) {\n    if ((val += umod - p.val) >= umod) val -=\
    \ umod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n   \
    \ val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint::raw(val ? mod - val : u32(0)); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll n) const {\n  \
    \  assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n#ifdef FASTIO\n  void write() { fastio::printer.write(val); }\n  void read()\
    \ {\n    fastio::scanner.read(val);\n    val %= mod;\n  }\n#endif\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 998244353) return {23, 31};\n    if (mod == 1045430273) return {20, 363};\n\
    \    if (mod == 1051721729) return {20, 330};\n    if (mod == 1053818881) return\
    \ {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 12 \"test/mytest/mo_on_tree.test.cpp\"\
    \n\nusing mint = modint998;\nusing AFF = pair<mint, mint>;\n\nAFF gen() {\n  mint\
    \ a = RNG(1, 3);\n  mint b = RNG(0, 3);\n  return {a, b};\n}\n\ntemplate <typename\
    \ Mono, bool EDGE>\nvoid test() {\n  constexpr bool ORIENTED = !(Mono::commute);\n\
    \  FOR(N, 1, 50) {\n    FOR(Q, 1, 50) {\n      vc<pi> query(Q);\n      vc<AFF>\
    \ dat;\n      if (!EDGE) {\n        FOR(v, N) dat.eb(gen());\n      } else {\n\
    \        FOR(i, N - 1) dat.eb(gen());\n      }\n      Graph<int, 0> G(N);\n  \
    \    FOR(v, 1, N) {\n        int p = RNG(0, v);\n        G.add(p, v);\n      }\n\
    \      G.build();\n      Tree<decltype(G)> tree(G);\n      Tree_Monoid<decltype(tree),\
    \ Mono, EDGE> TM(tree, dat);\n\n      FOR(q, Q) {\n        int a = RNG(0, N);\n\
    \        int b = RNG(0, N);\n        query[q] = {a, b};\n      }\n      Mo_on_Tree<decltype(tree),\
    \ ORIENTED> mo(tree);\n      for (auto&& [a, b]: query) mo.add(a, b);\n\n    \
    \  if constexpr (!EDGE) {\n        AFF f = Mono::unit();\n        auto init =\
    \ [&]() -> void { f = dat[0]; };\n        auto add_l = [&](int v) -> void { f\
    \ = Mono::op(dat[v], f); };\n        auto rm_l\n            = [&](int v) -> void\
    \ { f = Mono::op(Mono::inverse(dat[v]), f); };\n        auto add_r = [&](int v)\
    \ -> void { f = Mono::op(f, dat[v]); };\n        auto rm_r\n            = [&](int\
    \ v) -> void { f = Mono::op(f, Mono::inverse(dat[v])); };\n        auto ans =\
    \ [&](int q) -> void {\n          assert(f == TM.prod_path(query[q].fi, query[q].se));\n\
    \        };\n        mo.calc_vertex(init, add_l, add_r, rm_l, rm_r, ans);\n  \
    \    } else {\n        AFF f = Mono::unit();\n        auto get = [&](int a, int\
    \ b) -> int {\n          return tree.v_to_e((tree.parent[a] == b ? a : b));\n\
    \        };\n        auto init = [&]() -> void {};\n        auto add_l\n     \
    \       = [&](int a, int b) -> void { f = Mono::op(dat[get(a, b)], f); };\n  \
    \      auto rm_l = [&](int a, int b) -> void {\n          f = Mono::op(Mono::inverse(dat[get(a,\
    \ b)]), f);\n        };\n        auto add_r\n            = [&](int a, int b) ->\
    \ void { f = Mono::op(f, dat[get(a, b)]); };\n        auto rm_r = [&](int a, int\
    \ b) -> void {\n          f = Mono::op(f, Mono::inverse(dat[get(a, b)]));\n  \
    \      };\n        auto ans = [&](int q) -> void {\n          assert(f == TM.prod_path(query[q].fi,\
    \ query[q].se));\n        };\n        mo.calc_edge(init, add_l, add_r, rm_l, rm_r,\
    \ ans);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n\
    }\n\nsigned main() {\n  // \u30D1\u30B9\u306E\u5411\u304D\u304C\u53EF\u9006\u3067\
    \u9802\u70B9\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\n  test<Monoid_Add_Pair<mint>,\
    \ false>();\n  // \u30D1\u30B9\u306E\u5411\u304D\u304C\u4E0D\u53EF\u9006\u3067\
    \u9802\u70B9\u975E\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\n  test<Monoid_Affine<mint>,\
    \ false>();\n  // \u30D1\u30B9\u306E\u5411\u304D\u304C\u53EF\u9006\u3067\u8FBA\
    \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\n  test<Monoid_Add_Pair<mint>, true>();\n\
    \  // \u30D1\u30B9\u306E\u5411\u304D\u304C\u4E0D\u53EF\u9006\u3067\u8FBA\u975E\
    \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\n  test<Monoid_Affine<mint>, true>();\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"random/base.hpp\"\n#include \"graph/tree.hpp\"\
    \n#include \"graph/ds/mo_on_tree.hpp\"\n#include \"graph/ds/tree_monoid.hpp\"\n\
    #include \"alg/monoid/affine.hpp\"\n#include \"alg/monoid/add_pair.hpp\"\n#include\
    \ \"mod/modint.hpp\"\n\nusing mint = modint998;\nusing AFF = pair<mint, mint>;\n\
    \nAFF gen() {\n  mint a = RNG(1, 3);\n  mint b = RNG(0, 3);\n  return {a, b};\n\
    }\n\ntemplate <typename Mono, bool EDGE>\nvoid test() {\n  constexpr bool ORIENTED\
    \ = !(Mono::commute);\n  FOR(N, 1, 50) {\n    FOR(Q, 1, 50) {\n      vc<pi> query(Q);\n\
    \      vc<AFF> dat;\n      if (!EDGE) {\n        FOR(v, N) dat.eb(gen());\n  \
    \    } else {\n        FOR(i, N - 1) dat.eb(gen());\n      }\n      Graph<int,\
    \ 0> G(N);\n      FOR(v, 1, N) {\n        int p = RNG(0, v);\n        G.add(p,\
    \ v);\n      }\n      G.build();\n      Tree<decltype(G)> tree(G);\n      Tree_Monoid<decltype(tree),\
    \ Mono, EDGE> TM(tree, dat);\n\n      FOR(q, Q) {\n        int a = RNG(0, N);\n\
    \        int b = RNG(0, N);\n        query[q] = {a, b};\n      }\n      Mo_on_Tree<decltype(tree),\
    \ ORIENTED> mo(tree);\n      for (auto&& [a, b]: query) mo.add(a, b);\n\n    \
    \  if constexpr (!EDGE) {\n        AFF f = Mono::unit();\n        auto init =\
    \ [&]() -> void { f = dat[0]; };\n        auto add_l = [&](int v) -> void { f\
    \ = Mono::op(dat[v], f); };\n        auto rm_l\n            = [&](int v) -> void\
    \ { f = Mono::op(Mono::inverse(dat[v]), f); };\n        auto add_r = [&](int v)\
    \ -> void { f = Mono::op(f, dat[v]); };\n        auto rm_r\n            = [&](int\
    \ v) -> void { f = Mono::op(f, Mono::inverse(dat[v])); };\n        auto ans =\
    \ [&](int q) -> void {\n          assert(f == TM.prod_path(query[q].fi, query[q].se));\n\
    \        };\n        mo.calc_vertex(init, add_l, add_r, rm_l, rm_r, ans);\n  \
    \    } else {\n        AFF f = Mono::unit();\n        auto get = [&](int a, int\
    \ b) -> int {\n          return tree.v_to_e((tree.parent[a] == b ? a : b));\n\
    \        };\n        auto init = [&]() -> void {};\n        auto add_l\n     \
    \       = [&](int a, int b) -> void { f = Mono::op(dat[get(a, b)], f); };\n  \
    \      auto rm_l = [&](int a, int b) -> void {\n          f = Mono::op(Mono::inverse(dat[get(a,\
    \ b)]), f);\n        };\n        auto add_r\n            = [&](int a, int b) ->\
    \ void { f = Mono::op(f, dat[get(a, b)]); };\n        auto rm_r = [&](int a, int\
    \ b) -> void {\n          f = Mono::op(f, Mono::inverse(dat[get(a, b)]));\n  \
    \      };\n        auto ans = [&](int q) -> void {\n          assert(f == TM.prod_path(query[q].fi,\
    \ query[q].se));\n        };\n        mo.calc_edge(init, add_l, add_r, rm_l, rm_r,\
    \ ans);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n\
    }\n\nsigned main() {\n  // \u30D1\u30B9\u306E\u5411\u304D\u304C\u53EF\u9006\u3067\
    \u9802\u70B9\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\n  test<Monoid_Add_Pair<mint>,\
    \ false>();\n  // \u30D1\u30B9\u306E\u5411\u304D\u304C\u4E0D\u53EF\u9006\u3067\
    \u9802\u70B9\u975E\u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\n  test<Monoid_Affine<mint>,\
    \ false>();\n  // \u30D1\u30B9\u306E\u5411\u304D\u304C\u53EF\u9006\u3067\u8FBA\
    \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\n  test<Monoid_Add_Pair<mint>, true>();\n\
    \  // \u30D1\u30B9\u306E\u5411\u304D\u304C\u4E0D\u53EF\u9006\u3067\u8FBA\u975E\
    \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u7A4D\n  test<Monoid_Affine<mint>, true>();\n\
    \  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - graph/ds/mo_on_tree.hpp
  - ds/offline_query/mo.hpp
  - graph/ds/tree_monoid.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/monoid_reverse.hpp
  - alg/monoid/affine.hpp
  - alg/monoid/add_pair.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test/mytest/mo_on_tree.test.cpp
  requiredBy: []
  timestamp: '2023-10-06 12:12:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/mo_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/mo_on_tree.test.cpp
- /verify/test/mytest/mo_on_tree.test.cpp.html
title: test/mytest/mo_on_tree.test.cpp
---
