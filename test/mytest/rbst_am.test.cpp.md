---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/min_assign.hpp
    title: alg/acted_monoid/min_assign.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/randomized_bst/rbst_acted_monoid.hpp
    title: ds/randomized_bst/rbst_acted_monoid.hpp
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
  bundledCode: "#line 1 \"test/mytest/rbst_am.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \ yes(!t); }\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <class X>\r\nstruct\
    \ Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit() {\
    \ return numeric_limits<X>::max(); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 2 \"alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, X none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == none_val ? x : y); }\r\n  static constexpr X unit() { return\
    \ none_val; }\r\n  static constexpr bool commute = false;\r\n};\r\n#line 3 \"\
    alg/acted_monoid/min_assign.hpp\"\n\r\ntemplate <typename E, E none_val>\r\nstruct\
    \ ActedMonoid_Min_Assign {\r\n  using Monoid_X = Monoid_Min<E>;\r\n  using Monoid_A\
    \ = Monoid_Assign<E, none_val>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    return (a == none_val ? x : a);\r\
    \n  }\r\n};\r\n#line 1 \"ds/randomized_bst/rbst_acted_monoid.hpp\"\ntemplate <typename\
    \ ActedMonoid, bool PERSISTENT, int NODES>\nstruct RBST_ActedMonoid {\n  using\
    \ Monoid_X = typename ActedMonoid::Monoid_X;\n  using Monoid_A = typename ActedMonoid::Monoid_A;\n\
    \  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \n  struct Node {\n    Node *l, *r;\n    X x, prod; // lazy, rev \u53CD\u6620\u6E08\
    \n    A lazy;\n    u32 size;\n    bool rev;\n  };\n\n  Node *pool;\n  int pid;\n\
    \  using np = Node *;\n\n  RBST_ActedMonoid() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  void reset() { pid = 0; }\n\n  np new_node(const X &x) {\n    pool[pid].l\
    \ = pool[pid].r = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod = x;\n  \
    \  pool[pid].lazy = Monoid_A::unit();\n    pool[pid].size = 1;\n    pool[pid].rev\
    \ = 0;\n    return &(pool[pid++]);\n  }\n\n  np new_node(const vc<X> &dat) {\n\
    \    auto dfs = [&](auto &dfs, u32 l, u32 r) -> np {\n      if (l == r) return\
    \ nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n      u32 m = (l +\
    \ r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1,\
    \ r);\n      np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n\
    \      update(root);\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  np copy_node(np &n) {\n    if (!n || !PERSISTENT) return n;\n    pool[pid].l\
    \ = n->l, pool[pid].r = n->r;\n    pool[pid].x = n->x;\n    pool[pid].prod = n->prod;\n\
    \    pool[pid].lazy = n->lazy;\n    pool[pid].size = n->size;\n    pool[pid].rev\
    \ = n->rev;\n    return &(pool[pid++]);\n  }\n\n  np merge(np l_root, np r_root)\
    \ { return merge_rec(l_root, r_root); }\n  np merge3(np a, np b, np c) { return\
    \ merge(merge(a, b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n  pair<np, np> split(np root, u32 k) {\n    if (!root) {\n  \
    \    assert(k == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <=\
    \ k && k <= root->size);\n    return split_rec(root, k);\n  }\n  tuple<np, np,\
    \ np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root,\
    \ r);\n    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n\
    \  tuple<np, np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n \
    \   tie(root, d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n\
    \    return {a, b, c, d};\n  }\n\n  X prod(np root, u32 l, u32 r) {\n    if (l\
    \ == r) return Monoid_X::unit();\n    return prod_rec(root, l, r, false);\n  }\n\
    \  X prod(np root) { return (root ? root->prod : Monoid_X::unit()); }\n\n  np\
    \ reverse(np root, u32 l, u32 r) {\n    assert(Monoid_X::commute);\n    assert(0\
    \ <= l && l <= r && r <= root->size);\n    if (r - l <= 1) return root;\n    auto\
    \ [nl, nm, nr] = split3(root, l, r);\n    nm->rev ^= 1;\n    swap(nm->l, nm->r);\n\
    \    return merge3(nl, nm, nr);\n  }\n\n  np apply(np root, u32 l, u32 r, const\
    \ A a) {\n    assert(0 <= l && l <= r && r <= root->size);\n    return apply_rec(root,\
    \ l, r, a);\n  }\n  np apply(np root, const A a) {\n    if (!root) return root;\n\
    \    return apply_rec(root, 0, root->size, a);\n  }\n\n  np set(np root, u32 k,\
    \ const X &x) { return set_rec(root, k, x); }\n  np multiply(np root, u32 k, const\
    \ X &x) { return multiply_rec(root, k, x); }\n  X get(np root, u32 k) { return\
    \ get_rec(root, k, false, Monoid_A::unit()); }\n\n  vc<X> get_all(np root) {\n\
    \    vc<X> res;\n    auto dfs = [&](auto &dfs, np root, bool rev, A lazy) -> void\
    \ {\n      if (!root) return;\n      X me = ActedMonoid::act(root->x, lazy, 1);\n\
    \      lazy = Monoid_A::op(root->lazy, lazy);\n      dfs(dfs, (rev ? root->r :\
    \ root->l), rev ^ root->rev, lazy);\n      res.eb(me);\n      dfs(dfs, (rev ?\
    \ root->l : root->r), rev ^ root->rev, lazy);\n    };\n    dfs(dfs, root, 0, Monoid_A::unit());\n\
    \    return res;\n  }\n\n  template <typename F>\n  pair<np, np> split_max_right(np\
    \ root, const F check) {\n    assert(check(Monoid_X::unit()));\n    X x = Monoid_X::unit();\n\
    \    return split_max_right_rec(root, check, x);\n  }\n\nprivate:\n  inline u32\
    \ xor128() {\n    static u32 x = 123456789;\n    static u32 y = 362436069;\n \
    \   static u32 z = 521288629;\n    static u32 w = 88675123;\n    u32 t = x ^ (x\
    \ << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w = (w ^ (w >> 19))\
    \ ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n    // \u81EA\u8EAB\u3092\u30B3\
    \u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\u3044\u3002\n    // \u5B50\u3092\
    \u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\u8907\u6570\
    \u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\u304C\u3042\u308B\u305F\u3081\
    \u3002\n    bool bl_lazy = (c->lazy != Monoid_A::unit());\n    bool bl_rev = c->rev;\n\
    \    if (bl_lazy || bl_rev) {\n      c->l = copy_node(c->l);\n      c->r = copy_node(c->r);\n\
    \    }\n    if (c->lazy != Monoid_A::unit()) {\n      if (c->l) {\n        c->l->x\
    \ = ActedMonoid::act(c->l->x, c->lazy, 1);\n        c->l->prod = ActedMonoid::act(c->l->prod,\
    \ c->lazy, c->l->size);\n        c->l->lazy = Monoid_A::op(c->l->lazy, c->lazy);\n\
    \      }\n      if (c->r) {\n        c->r->x = ActedMonoid::act(c->r->x, c->lazy,\
    \ 1);\n        c->r->prod = ActedMonoid::act(c->r->prod, c->lazy, c->r->size);\n\
    \        c->r->lazy = Monoid_A::op(c->r->lazy, c->lazy);\n      }\n      c->lazy\
    \ = Monoid_A::unit();\n    }\n    if (c->rev) {\n      if (c->l) {\n        c->l->rev\
    \ ^= 1;\n        swap(c->l->l, c->l->r);\n      }\n      if (c->r) {\n       \
    \ c->r->rev ^= 1;\n        swap(c->r->l, c->r->r);\n      }\n      c->rev = 0;\n\
    \    }\n  }\n\n  void update(np c) {\n    // \u30C7\u30FC\u30BF\u3092\u4FDD\u3063\
    \u305F\u307E\u307E\u6B63\u5E38\u5316\u3059\u308B\u3060\u3051\u306A\u306E\u3067\
    \u3001\u30B3\u30D4\u30FC\u4E0D\u8981\n    c->size = 1;\n    c->prod = c->x;\n\
    \    if (c->l) {\n      c->size += c->l->size;\n      c->prod = Monoid_X::op(c->l->prod,\
    \ c->prod);\n    }\n    if (c->r) {\n      c->size += c->r->size;\n      c->prod\
    \ = Monoid_X::op(c->prod, c->r->prod);\n    }\n  }\n\n  np merge_rec(np l_root,\
    \ np r_root) {\n    if (!l_root) return r_root;\n    if (!r_root) return l_root;\n\
    \    u32 sl = l_root->size, sr = r_root->size;\n    if (xor128() % (sl + sr) <\
    \ sl) {\n      prop(l_root);\n      l_root = copy_node(l_root);\n      l_root->r\
    \ = merge_rec(l_root->r, r_root);\n      update(l_root);\n      return l_root;\n\
    \    }\n    prop(r_root);\n    r_root = copy_node(r_root);\n    r_root->l = merge_rec(l_root,\
    \ r_root->l);\n    update(r_root);\n    return r_root;\n  }\n\n  pair<np, np>\
    \ split_rec(np root, u32 k) {\n    if (!root) return {nullptr, nullptr};\n   \
    \ prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n    if (k <= sl) {\n\
    \      auto [nl, nr] = split_rec(root->l, k);\n      root = copy_node(root);\n\
    \      root->l = nr;\n      update(root);\n      return {nl, root};\n    }\n \
    \   auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n    root = copy_node(root);\n\
    \    root->r = nl;\n    update(root);\n    return {root, nr};\n  }\n\n  np set_rec(np\
    \ root, u32 k, const X &x) {\n    if (!root) return root;\n    prop(root);\n \
    \   u32 sl = (root->l ? root->l->size : 0);\n    if (k < sl) {\n      root = copy_node(root);\n\
    \      root->l = set_rec(root->l, k, x);\n      update(root);\n      return root;\n\
    \    }\n    if (k == sl) {\n      root = copy_node(root);\n      root->x = x;\n\
    \      update(root);\n      return root;\n    }\n    root = copy_node(root);\n\
    \    root->r = set_rec(root->r, k - (1 + sl), x);\n    update(root);\n    return\
    \ root;\n  }\n\n  np multiply_rec(np root, u32 k, const X &x) {\n    if (!root)\
    \ return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (k < sl) {\n      root = copy_node(root);\n      root->l = multiply_rec(root->l,\
    \ k, x);\n      update(root);\n      return root;\n    }\n    if (k == sl) {\n\
    \      root = copy_node(root);\n      root->x = Monoid_X::op(root->x, x);\n  \
    \    update(root);\n      return root;\n    }\n    root = copy_node(root);\n \
    \   root->r = multiply_rec(root->r, k - (1 + sl), x);\n    update(root);\n   \
    \ return root;\n  }\n\n  X prod_rec(np root, u32 l, u32 r, bool rev) {\n    if\
    \ (l == 0 && r == root->size) { return root->prod; }\n    np left = (rev ? root->r\
    \ : root->l);\n    np right = (rev ? root->l : root->r);\n    u32 sl = (left ?\
    \ left->size : 0);\n    X res = Monoid_X::unit();\n    if (l < sl) {\n      X\
    \ y = prod_rec(left, l, min(r, sl), rev ^ root->rev);\n      res = Monoid_X::op(res,\
    \ ActedMonoid::act(y, root->lazy, min(r, sl) - l));\n    }\n    if (l <= sl &&\
    \ sl < r) res = Monoid_X::op(res, root->x);\n    u32 k = 1 + sl;\n    if (k <\
    \ r) {\n      X y = prod_rec(right, max(k, l) - k, r - k, rev ^ root->rev);\n\
    \      res = Monoid_X::op(res, ActedMonoid::act(y, root->lazy, r - max(k, l)));\n\
    \    }\n    return res;\n  }\n\n  X get_rec(np root, u32 k, bool rev, A lazy)\
    \ {\n    np left = (rev ? root->r : root->l);\n    np right = (rev ? root->l :\
    \ root->r);\n    u32 sl = (left ? left->size : 0);\n    if (k == sl) return ActedMonoid::act(root->x,\
    \ lazy, 1);\n    lazy = Monoid_A::op(root->lazy, lazy);\n    rev ^= root->rev;\n\
    \    if (k < sl) return get_rec(left, k, rev, lazy);\n    return get_rec(right,\
    \ k - (1 + sl), rev, lazy);\n  }\n\n  np apply_rec(np root, u32 l, u32 r, const\
    \ A &a) {\n    prop(root);\n    root = copy_node(root);\n    if (l == 0 && r ==\
    \ root->size) {\n      root->x = ActedMonoid::act(root->x, a, 1);\n      root->prod\
    \ = ActedMonoid::act(root->prod, a, root->size);\n      root->lazy = a;\n    \
    \  return root;\n    }\n    u32 sl = (root->l ? root->l->size : 0);\n    if (l\
    \ < sl) root->l = apply_rec(root->l, l, min(r, sl), a);\n    if (l <= sl && sl\
    \ < r) root->x = ActedMonoid::act(root->x, a, 1);\n    u32 k = 1 + sl;\n    if\
    \ (k < r) root->r = apply_rec(root->r, max(k, l) - k, r - k, a);\n    update(root);\n\
    \    return root;\n  }\n\n  template <typename F>\n  pair<np, np> split_max_right_rec(np\
    \ root, F check, X &x) {\n    if (!root) return {nullptr, nullptr};\n    prop(root);\n\
    \    root = copy_node(root);\n    X y = Monoid_X::op(x, root->prod);\n    if (check(y))\
    \ {\n      x = y;\n      return {root, nullptr};\n    }\n    np left = root->l,\
    \ right = root->r;\n    if (left) {\n      X y = Monoid_X::op(x, root->l->prod);\n\
    \      if (!check(y)) {\n        auto [n1, n2] = split_max_right_rec(left, check,\
    \ x);\n        root->l = n2;\n        update(root);\n        return {n1, root};\n\
    \      }\n      x = y;\n    }\n    y = Monoid_X::op(x, root->x);\n    if (!check(y))\
    \ {\n      root->l = nullptr;\n      update(root);\n      return {left, root};\n\
    \    }\n    x = y;\n    auto [n1, n2] = split_max_right_rec(right, check, x);\n\
    \    root->r = n1;\n    update(root);\n    return {root, n2};\n  }\n};\n#line\
    \ 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 7 \"test/mytest/rbst_am.test.cpp\"\
    \n\nvoid test() {\n  using AM = ActedMonoid_Min_Assign<int, -1>;\n  using MonoX\
    \ = typename AM::Monoid_X;\n\n  RBST_ActedMonoid<AM, false, 100> X;\n  FOR(1000)\
    \ {\n    X.reset();\n    int N = RNG(1, 20);\n    int Q = RNG(1, 1000);\n    vc<int>\
    \ A(N);\n    FOR(i, N) A[i] = RNG(1, 100);\n    auto root = X.new_node(A);\n\n\
    \    FOR(Q) {\n      int t = RNG(0, 7);\n      if (t == 0) {\n        int i =\
    \ RNG(0, N);\n        assert(A[i] == X.get(root, i));\n      }\n      if (t ==\
    \ 1) {\n        int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root\
    \ = X.set(root, i, x);\n        A[i] = x;\n      }\n      if (t == 2) {\n    \
    \    int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root = X.multiply(root,\
    \ i, x);\n        A[i] = MonoX::op(A[i], x);\n      }\n      if (t == 3) {\n \
    \       int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        vc<int> B = {A.begin() + L, A.begin() + R};\n   \
    \     assert(X.prod(root, L, R) == MIN(B));\n      }\n      if (t == 4) {\n  \
    \      int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        root = X.reverse(root, L, R);\n        reverse(A.begin()\
    \ + L, A.begin() + R);\n      }\n      if (t == 5) {\n        int L = RNG(0, N);\n\
    \        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n  \
    \      int x = RNG(1, 100);\n        FOR(i, L, R) A[i] = x;\n        root = X.apply(root,\
    \ L, R, x);\n      }\n      if (t == 6) {\n        vc<int> B = X.get_all(root);\n\
    \        assert(A == B);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n\
    \  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/acted_monoid/min_assign.hpp\"\n#include\
    \ \"ds/randomized_bst/rbst_acted_monoid.hpp\"\n#include \"random/base.hpp\"\n\n\
    void test() {\n  using AM = ActedMonoid_Min_Assign<int, -1>;\n  using MonoX =\
    \ typename AM::Monoid_X;\n\n  RBST_ActedMonoid<AM, false, 100> X;\n  FOR(1000)\
    \ {\n    X.reset();\n    int N = RNG(1, 20);\n    int Q = RNG(1, 1000);\n    vc<int>\
    \ A(N);\n    FOR(i, N) A[i] = RNG(1, 100);\n    auto root = X.new_node(A);\n\n\
    \    FOR(Q) {\n      int t = RNG(0, 7);\n      if (t == 0) {\n        int i =\
    \ RNG(0, N);\n        assert(A[i] == X.get(root, i));\n      }\n      if (t ==\
    \ 1) {\n        int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root\
    \ = X.set(root, i, x);\n        A[i] = x;\n      }\n      if (t == 2) {\n    \
    \    int i = RNG(0, N);\n        int x = RNG(1, 100);\n        root = X.multiply(root,\
    \ i, x);\n        A[i] = MonoX::op(A[i], x);\n      }\n      if (t == 3) {\n \
    \       int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        vc<int> B = {A.begin() + L, A.begin() + R};\n   \
    \     assert(X.prod(root, L, R) == MIN(B));\n      }\n      if (t == 4) {\n  \
    \      int L = RNG(0, N);\n        int R = RNG(0, N);\n        if (L > R) swap(L,\
    \ R);\n        ++R;\n        root = X.reverse(root, L, R);\n        reverse(A.begin()\
    \ + L, A.begin() + R);\n      }\n      if (t == 5) {\n        int L = RNG(0, N);\n\
    \        int R = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n  \
    \      int x = RNG(1, 100);\n        FOR(i, L, R) A[i] = x;\n        root = X.apply(root,\
    \ L, R, x);\n      }\n      if (t == 6) {\n        vc<int> B = X.get_all(root);\n\
    \        assert(A == B);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n\
    \  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n\
    }\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/acted_monoid/min_assign.hpp
  - alg/monoid/min.hpp
  - alg/monoid/assign.hpp
  - ds/randomized_bst/rbst_acted_monoid.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/rbst_am.test.cpp
  requiredBy: []
  timestamp: '2022-12-12 09:20:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/rbst_am.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/rbst_am.test.cpp
- /verify/test/mytest/rbst_am.test.cpp.html
title: test/mytest/rbst_am.test.cpp
---
