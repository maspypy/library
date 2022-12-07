---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/sum_affine.hpp
    title: alg/acted_monoid/sum_affine.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_acted_monoid.hpp
    title: ds/splaytree/splaytree_acted_monoid.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
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
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    }\n#line 1 \"other/io.hpp\"\n// based on yosupo's fastio\r\n#include <unistd.h>\r\
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
    \ yes(!t); }\n#line 5 \"test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp\"\
    \n\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct Monoid_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ X(n) * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"alg/monoid/affine.hpp\"\n\ntemplate\
    \ <typename K>\nstruct Monoid_Affine {\n  using F = pair<K, K>;\n  using value_type\
    \ = F;\n  static constexpr F op(const F &x, const F &y) noexcept {\n    return\
    \ F({x.first * y.first, x.second * y.first + y.second});\n  }\n  static constexpr\
    \ F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n    return\
    \ {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f, K x) noexcept {\n\
    \    return f.first * x + f.second;\n  }\n  static constexpr F unit() { return\
    \ {K(1), K(0)}; }\n  static constexpr bool commute = false;\n};\n#line 3 \"alg/acted_monoid/sum_affine.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Sum_Affine {\r\n  using Monoid_X\
    \ = Monoid_Add<E>;\r\n  using Monoid_A = Monoid_Affine<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return x *\
    \ a.fi + E(size) * a.se;\r\n  }\r\n};\r\n#line 2 \"mod/modint.hpp\"\n\ntemplate\
    \ <int mod>\nstruct modint {\n  int val;\n  constexpr modint(ll x = 0) noexcept\
    \ {\n    if (0 <= x && x < mod)\n      val = x;\n    else {\n      x %= mod;\n\
    \      val = (x < 0 ? x + mod : x);\n    }\n  }\n  bool operator<(const modint\
    \ &other) const {\n    return val < other.val;\n  } // To use std::map\n  modint\
    \ &operator+=(const modint &p) {\n    if ((val += p.val) >= mod) val -= mod;\n\
    \    return *this;\n  }\n  modint &operator-=(const modint &p) {\n    if ((val\
    \ += mod - p.val) >= mod) val -= mod;\n    return *this;\n  }\n  modint &operator*=(const\
    \ modint &p) {\n    val = (int)(1LL * val * p.val % mod);\n    return *this;\n\
    \  }\n  modint &operator/=(const modint &p) {\n    *this *= p.inverse();\n   \
    \ return *this;\n  }\n  modint operator-() const { return modint(-val); }\n  modint\
    \ operator+(const modint &p) const { return modint(*this) += p; }\n  modint operator-(const\
    \ modint &p) const { return modint(*this) -= p; }\n  modint operator*(const modint\
    \ &p) const { return modint(*this) *= p; }\n  modint operator/(const modint &p)\
    \ const { return modint(*this) /= p; }\n  bool operator==(const modint &p) const\
    \ { return val == p.val; }\n  bool operator!=(const modint &p) const { return\
    \ val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod, u = 1,\
    \ v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b),\
    \ swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(int64_t\
    \ n) const {\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n &\
    \ 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  void write() { fastio::printer.write(val); }\n  void read() { fastio::scanner.read(val);\
    \ }\n  static constexpr int get_mod() { return mod; }\n};\n\nstruct ArbitraryModInt\
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
    \  }\n    return ret;\n  }\n  void write() { fastio::printer.write(val); }\n \
    \ void read() { fastio::scanner.read(val); }\n};\n\ntemplate <typename mint>\n\
    mint inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {0, 1};\n  assert(0 <= n);\n  if (n >= mod) n %= mod;\n  while (int(dat.size())\
    \ <= n) {\n    int k = dat.size();\n    auto q = (mod + k - 1) / k;\n    int r\
    \ = k * q - mod;\n    dat.emplace_back(dat[r] * mint(q));\n  }\n  return dat[n];\n\
    }\n\ntemplate <typename mint>\nmint fact(int n) {\n  static const int mod = mint::get_mod();\n\
    \  static vector<mint> dat = {1, 1};\n  assert(0 <= n);\n  if (n >= mod) return\
    \ 0;\n  while (int(dat.size()) <= n) {\n    int k = dat.size();\n    dat.emplace_back(dat[k\
    \ - 1] * mint(k));\n  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint\
    \ fact_inv(int n) {\n  static const int mod = mint::get_mod();\n  static vector<mint>\
    \ dat = {1, 1};\n  assert(-1 <= n && n < mod);\n  if (n == -1) return mint(0);\n\
    \  while (int(dat.size()) <= n) {\n    int k = dat.size();\n    dat.emplace_back(dat[k\
    \ - 1] * inv<mint>(k));\n  }\n  return dat[n];\n}\n\ntemplate <class mint, class...\
    \ Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n\
    }\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&... tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
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
    \ = modint<998244353>;\nusing amint = ArbitraryModInt;\n#line 2 \"ds/splaytree/splaytree.hpp\"\
    \n// Node \u578B\u3092\u5225\u306B\u5B9A\u7FA9\u3057\u3066\u4F7F\u3046\ntemplate\
    \ <typename Node, int NODES = 1'000'000>\nstruct SplayTree {\n  Node *pool;\n\
    \  int pid;\n  using np = Node *;\n  using X = typename Node::value_type;\n  using\
    \ A = typename Node::operator_type;\n\n  SplayTree() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  void reset() { pid = 0; }\n\n  np new_node(const X &x) {\n    np n =\
    \ &(pool[pid++]);\n    Node::new_node(n, x);\n    return n;\n  }\n\n  np new_node(const\
    \ vc<X> &dat) {\n    auto dfs = [&](auto &dfs, int l, int r) -> np {\n      if\
    \ (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n \
    \     int m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m);\n      np r_root\
    \ = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n      root->l = l_root,\
    \ root->r = r_root;\n      if (l_root) l_root->p = root;\n      if (r_root) r_root->p\
    \ = root;\n      root->update();\n      return root;\n    };\n    return dfs(dfs,\
    \ 0, len(dat));\n  }\n\n  u32 get_size(np root) { return (root ? root->size :\
    \ 0); }\n\n  np merge(np l_root, np r_root) {\n    if (!l_root) return r_root;\n\
    \    if (!r_root) return l_root;\n    splay_kth(r_root, 0); // splay \u3057\u305F\
    \u306E\u3067 prop \u6E08\n    r_root->l = l_root;\n    l_root->p = r_root;\n \
    \   r_root->update();\n    return r_root;\n  }\n  np merge3(np a, np b, np c)\
    \ { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np c, np d) { return\
    \ merge(merge(merge(a, b), c), d); }\n\n  pair<np, np> split(np root, u32 k) {\n\
    \    if (k == (root->size)) return {root, nullptr};\n    if (k == 0) return {nullptr,\
    \ root};\n    splay_kth(root, k - 1);\n    np right = root->r;\n    root->r =\
    \ nullptr, right->p = nullptr;\n    root->update();\n    return {root, right};\n\
    \  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n  \
    \  tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n    return\
    \ {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np root, u32 i, u32 j,\
    \ u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n    auto [a, b, c]\
    \ = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n  // \u90E8\u5206\u6728\
    \u304C\u533A\u9593 [l,r) \u306B\u5BFE\u5FDC\u3059\u308B\u3088\u3046\u306A\u30CE\
    \u30FC\u30C9\u3092\u4F5C\u3063\u3066\u8FD4\u3059\n  // \u305D\u306E\u30CE\u30FC\
    \u30C9\u304C root \u306B\u306A\u308B\u308F\u3051\u3067\u306F\u306A\u3044\u306E\
    \u3067\u3001\n  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u53C2\u7167\u3057\u305F\
    \u5F8C\u306B\u3059\u3050\u306B splay \u3057\u3066\u6839\u306B\u6301\u3061\u4E0A\
    \u3052\u308B\u3053\u3068\n  void goto_between(np &root, u32 l, u32 r) {\n    if\
    \ (l == 0 && r == root->size) return;\n    if (l == 0) {\n      splay_kth(root,\
    \ r);\n      root = root->l;\n      return;\n    }\n    if (r == root->size) {\n\
    \      splay_kth(root, l - 1);\n      root = root->r;\n      return;\n    }\n\
    \    splay_kth(root, r);\n    np rp = root;\n    root = rp->l;\n    root->p =\
    \ nullptr;\n    splay_kth(root, l - 1);\n    root->p = rp;\n    rp->l = root;\n\
    \    rp->update();\n    root = root->r;\n  }\n\n  vc<X> get_all(const np &root)\
    \ {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np root) -> void {\n      if\
    \ (!root) return;\n      root->prop();\n      dfs(dfs, root->l);\n      res.eb(root->get());\n\
    \      dfs(dfs, root->r);\n    };\n    dfs(dfs, root);\n    return res;\n  }\n\
    \n  X get(np &root, u32 k) {\n    splay_kth(root, k);\n    return root->get();\n\
    \  }\n\n  void set(np &root, u32 k, const X &x) {\n    splay_kth(root, k);\n \
    \   root->set(x);\n  }\n\n  void multiply(np &root, u32 k, const X &x) {\n   \
    \ splay_kth(root, k);\n    root->multiply(x);\n  }\n\n  X prod(np &root, u32 l,\
    \ u32 r) {\n    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root,\
    \ l, r);\n    X res = root->prod;\n    splay(root);\n    return res;\n  }\n\n\
    \  void apply(np &root, u32 l, u32 r, const A &a) {\n    assert(0 <= l && l <\
    \ r && r <= root->size);\n    goto_between(root, l, r);\n    root->apply(a);\n\
    \    splay(root);\n  }\n  void apply(np &root, const A &a) {\n    if (!root) return;\n\
    \    root->apply(a);\n  }\n\n  void reverse(np &root, u32 l, u32 r) {\n    assert(0\
    \ <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n    root->reverse();\n\
    \    splay(root);\n  }\n  void reverse(np &root) {\n    if (!root) return;\n \
    \   root->reverse();\n  }\n\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\
    \u8FD1\u3065\u3051\u308B\u3002prop, update \u306F rotate \u306E\u5916\u3067\u884C\
    \u3046\u3002\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n    if (p->l\
    \ == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n \
    \     c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n    if (pp && pp->l\
    \ == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n   \
    \ p->p = n;\n    if (c) c->p = p;\n  }\n\n  void splay(Node *me) {\n    // \u3053\
    \u308C\u3092\u547C\u3076\u6642\u70B9\u3067\u3001me \u306E\u7956\u5148\uFF08me\
    \ \u3092\u9664\u304F\uFF09\u306F\u65E2\u306B prop \u6E08\u3067\u3042\u308B\u3053\
    \u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001splay \u7D42\u4E86\u6642\u70B9\
    \u3067 me \u306F upd / prop \u6E08\u3067\u3042\u308B\n    me->prop();\n    while\
    \ (me->p) {\n      np p = me->p;\n      np pp = p->p;\n      if (!pp) {\n    \
    \    rotate(me);\n        p->update();\n        break;\n      }\n      bool same\
    \ = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);\n      if (same)\
    \ rotate(p), rotate(me);\n      if (!same) rotate(me), rotate(me);\n      pp->update(),\
    \ p->update();\n    }\n    // me \u306E update \u306F\u6700\u5F8C\u3060\u3051\u3067\
    \u3088\u3044\n    me->update();\n  }\n\n  void splay_kth(np &root, u32 k) {\n\
    \    assert(0 <= k && k < (root->size));\n    while (1) {\n      u32 sl = (root->l\
    \ ? root->l->size : 0);\n      if (k == sl) break;\n      root->prop();\n    \
    \  if (k < sl)\n        root = root->l;\n      else {\n        k -= sl + 1;\n\
    \        root = root->r;\n      }\n    }\n    splay(root);\n  }\n\n  // \u5DE6\
    \u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\
    \u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np, np> split_max_right(np\
    \ root, F check) {\n    if (!root) return {nullptr, nullptr};\n    np c = find_max_right(root,\
    \ check);\n    if (!c) {\n      splay(root);\n      return {nullptr, root};\n\
    \    }\n    splay(c);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  // \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u306E\
    \ prod \u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n \
    \ template <typename F>\n  pair<np, np> split_max_right_prod(np root, F check)\
    \ {\n    if (!root) return {nullptr, nullptr};\n    np c = find_max_right_prod(root,\
    \ check);\n    if (!c) {\n      splay(root);\n      return {nullptr, root};\n\
    \    }\n    splay(c);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last);\n \
    \   return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_prod(np\
    \ root, const F &check) {\n    using Mono = typename Node::Monoid_X;\n    X prod\
    \ = Mono::unit();\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\
    \u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok =\
    \ nullptr, last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      X lprod = prod;\n      if (root->l) lprod = Mono::op(lprod, root->l->prod);\n\
    \      lprod = Mono::op(lprod, root->x);\n      if (check(lprod)) {\n        prod\
    \ = lprod;\n        last_ok = root;\n        root = root->r;\n      } else {\n\
    \        root = root->l;\n      }\n    }\n    splay(last);\n    return last_ok;\n\
    \  }\n};\n#line 2 \"ds/splaytree/splaytree_acted_monoid.hpp\"\n\nnamespace SplayTreeNodes\
    \ {\ntemplate <typename ActedMonoid>\nstruct Node_AM {\n  using Monoid_A = typename\
    \ ActedMonoid::Monoid_A;\n  using Monoid_X = typename ActedMonoid::Monoid_X;\n\
    \  using A = typename Monoid_A::value_type;\n  using X = typename Monoid_X::value_type;\n\
    \  using value_type = X;\n  using operator_type = A;\n  using np = Node_AM *;\n\
    \n  np p, l, r;\n  X x, prod;\n  A lazy;\n  u32 size;\n  bool rev;\n\n  static\
    \ void new_node(np n, const X &x) {\n    n->p = n->l = n->r = nullptr;\n    n->x\
    \ = n->prod = x;\n    n->lazy = Monoid_A::unit();\n    n->size = 1;\n    n->rev\
    \ = 0;\n  }\n\n  void update() {\n    size = 1;\n    prod = x;\n    if (l) {\n\
    \      size += l->size;\n      prod = Monoid_X::op(l->prod, prod);\n    }\n  \
    \  if (r) {\n      size += r->size;\n      prod = Monoid_X::op(prod, r->prod);\n\
    \    }\n  }\n\n  void prop() {\n    if (lazy != Monoid_A::unit()) {\n      if\
    \ (l) { l->apply(lazy); }\n      if (r) { r->apply(lazy); }\n      lazy = Monoid_A::unit();\n\
    \    }\n    if (rev) {\n      if (l) { l->reverse(); }\n      if (r) { r->reverse();\
    \ }\n      rev = 0;\n    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\u3070\
    \u308C\u308B\u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\u3068\
    \u304C\u60F3\u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\u304C\
    \u3063\u3066\u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\u308B\
    \u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  X get() { return\
    \ x; }\n  void set(const X &xx) {\n    x = xx;\n    update();\n  }\n  void multiply(const\
    \ X &xx) {\n    x = Monoid_X::op(x, xx);\n    update();\n  }\n  void apply(const\
    \ A &a) {\n    x = ActedMonoid::act(x, a, 1);\n    prod = ActedMonoid::act(prod,\
    \ a, size);\n    lazy = Monoid_A::op(lazy, a);\n  }\n  void reverse() {\n    swap(l,\
    \ r);\n    rev ^= 1;\n  }\n};\ntemplate <typename ActedMonoid, int NODES>\nusing\
    \ SplayTree_ActedMonoid = SplayTree<Node_AM<ActedMonoid>, NODES>;\n} // namespace\
    \ SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_ActedMonoid;\n#line 9 \"test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  using AM = ActedMonoid_Sum_Affine<mint>;\n\
    \  SplayTree_ActedMonoid<AM, 1'000'000> X;\n  using P = typename AM::X;\n\n  INT(N,\
    \ Q);\n  VEC(mint, dat, N);\n  auto root = X.new_node(dat);\n\n  FOR(Q) {\n  \
    \  INT(t);\n    if (t == 0) {\n      INT(i, x);\n      auto [a, b] = X.split(root,\
    \ i);\n      root = X.merge3(a, X.new_node(mint(x)), b);\n    }\n    if (t ==\
    \ 1) {\n      INT(i);\n      auto [a, b, c] = X.split3(root, i, i + 1);\n    \
    \  root = X.merge(a, c);\n    }\n    if (t == 2) {\n      INT(L, R);\n      X.reverse(root,\
    \ L, R);\n    }\n    if (t == 3) {\n      INT(L, R, b, c);\n      X.apply(root,\
    \ L, R, {mint(b), mint(c)});\n    }\n    if (t == 4) {\n      INT(L, R);\n   \
    \   print(X.prod(root, L, R));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/acted_monoid/sum_affine.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"ds/splaytree/splaytree_acted_monoid.hpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  using AM = ActedMonoid_Sum_Affine<mint>;\n\
    \  SplayTree_ActedMonoid<AM, 1'000'000> X;\n  using P = typename AM::X;\n\n  INT(N,\
    \ Q);\n  VEC(mint, dat, N);\n  auto root = X.new_node(dat);\n\n  FOR(Q) {\n  \
    \  INT(t);\n    if (t == 0) {\n      INT(i, x);\n      auto [a, b] = X.split(root,\
    \ i);\n      root = X.merge3(a, X.new_node(mint(x)), b);\n    }\n    if (t ==\
    \ 1) {\n      INT(i);\n      auto [a, b, c] = X.split3(root, i, i + 1);\n    \
    \  root = X.merge(a, c);\n    }\n    if (t == 2) {\n      INT(L, R);\n      X.reverse(root,\
    \ L, R);\n    }\n    if (t == 3) {\n      INT(L, R, b, c);\n      X.apply(root,\
    \ L, R, {mint(b), mint(c)});\n    }\n    if (t == 4) {\n      INT(L, R);\n   \
    \   print(X.prod(root, L, R));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/acted_monoid/sum_affine.hpp
  - alg/monoid/add.hpp
  - alg/monoid/affine.hpp
  - mod/modint.hpp
  - ds/splaytree/splaytree_acted_monoid.hpp
  - ds/splaytree/splaytree.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
  requiredBy: []
  timestamp: '2022-12-07 08:14:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
- /verify/test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp.html
title: test/library_checker/datastructure/dynamic_sequence_range_affine_range_sum_splay.test.cpp
---
