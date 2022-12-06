---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: nt/GF2.hpp
    title: nt/GF2.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':x:'
    path: string/rollinghash_field.hpp
    title: string/rollinghash_field.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc274/tasks/abc274_Ex
    links:
    - https://atcoder.jp/contests/abc274/tasks/abc274_Ex
  bundledCode: "#line 1 \"test/atcoder/abc274_h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc274/tasks/abc274_Ex\"\
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
    \ yes(!t); }\n#line 4 \"test/atcoder/abc274_h.test.cpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 1 \"nt/GF2.hpp\"\
    \n#include <emmintrin.h>\n#include <smmintrin.h>\n#include <wmmintrin.h>\n\n__attribute__((target(\"\
    pclmul\"))) inline __m128i myclmul(const __m128i &a,\n                       \
    \                                  const __m128i &b) {\n  return _mm_clmulepi64_si128(a,\
    \ b, 0);\n}\n\n// 2^n \u5143\u4F53\ntemplate <int K>\nstruct GF2 {\n  // irreducible\
    \ poly x^K + ...\n  static constexpr int POLY[65]\n      = {0,  0, 3,  3,   3,\
    \  5,   3,  3,  27,  3,  9,  5,   9, 27, 33, 3,   43,\n         9,  9, 39, 9,\
    \   5,  3,   33, 27, 9,   27, 39, 3,   5, 3,  9,  141, 75,\n         27, 5, 53,\
    \ 63,  99, 17,  57, 9,  39,  89, 33, 27,  3, 33, 45, 113, 29,\n         75, 9,\
    \ 71, 125, 71, 149, 17, 99, 123, 3,  39, 105, 3, 27};\n\n  static constexpr u64\
    \ mask() { return u64(-1) >> (64 - K); }\n\n  __attribute__((target(\"sse4.2\"\
    ))) static u64 mul(u64 a, u64 b) {\n    static bool prepared = 0;\n    static\
    \ u64 MEMO[8][65536];\n    if (!prepared) {\n      prepared = 1;\n      vc<u64>\
    \ tmp(128);\n      tmp[0] = 1;\n      FOR(i, 127) {\n        tmp[i + 1] = tmp[i]\
    \ << 1;\n        if (tmp[i] >> (K - 1) & 1) {\n          tmp[i + 1] ^= POLY[K];\n\
    \          tmp[i + 1] &= mask();\n        }\n      }\n      FOR(k, 8) {\n    \
    \    MEMO[k][0] = 0;\n        FOR(i, 16) {\n          FOR(s, 1 << i) { MEMO[k][s\
    \ | 1 << i] = MEMO[k][s] ^ tmp[16 * k + i]; }\n        }\n      }\n    }\n   \
    \ const __m128i a_ = _mm_set_epi64x(0, a);\n    const __m128i b_ = _mm_set_epi64x(0,\
    \ b);\n    const __m128i c_ = myclmul(a_, b_);\n    u64 lo = _mm_extract_epi64(c_,\
    \ 0);\n    u64 hi = _mm_extract_epi64(c_, 1);\n    u64 x = 0;\n    x ^= MEMO[0][lo\
    \ & 65535];\n    x ^= MEMO[1][(lo >> 16) & 65535];\n    x ^= MEMO[2][(lo >> 32)\
    \ & 65535];\n    x ^= MEMO[3][(lo >> 48) & 65535];\n    x ^= MEMO[4][hi & 65535];\n\
    \    x ^= MEMO[5][(hi >> 16) & 65535];\n    x ^= MEMO[6][(hi >> 32) & 65535];\n\
    \    x ^= MEMO[7][(hi >> 48) & 65535];\n    return x;\n  }\n\n  u64 val;\n  constexpr\
    \ GF2(const u64 val = 0) noexcept : val(val & mask()) {}\n  bool operator<(const\
    \ GF2 &other) const {\n    return val < other.val;\n  } // To use std::map\n \
    \ GF2 &operator+=(const GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n\
    \  GF2 &operator-=(const GF2 &p) {\n    val ^= p.val;\n    return *this;\n  }\n\
    \  GF2 &operator*=(const GF2 &p) {\n    val = mul(val, p.val);\n    return *this;\n\
    \  }\n\n  GF2 &operator/=(const GF2 &p) {\n    *this *= p.inverse();\n    return\
    \ *this;\n  }\n  GF2 operator-() const { return GF2(-val); }\n  GF2 operator+(const\
    \ GF2 &p) const { return GF2(*this) += p; }\n  GF2 operator-(const GF2 &p) const\
    \ { return GF2(*this) -= p; }\n  GF2 operator*(const GF2 &p) const { return GF2(*this)\
    \ *= p; }\n  GF2 operator/(const GF2 &p) const { return GF2(*this) /= p; }\n \
    \ bool operator==(const GF2 &p) const { return val == p.val; }\n  bool operator!=(const\
    \ GF2 &p) const { return val != p.val; }\n  GF2 inverse() const { return pow((u64(1)\
    \ << K) - 2); }\n  GF2 pow(u64 n) const {\n    GF2 ret(1), mul(val);\n    while\
    \ (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n\
    \    }\n    return ret;\n  }\n};\n#line 1 \"string/rollinghash_field.hpp\"\n//\
    \ +, -, * \u304C\u5B9A\u7FA9\u3055\u308C\u305F\u69CB\u9020\u4F53\u3092\u6E21\u3059\
    \ntemplate <typename Field>\nstruct RollingHash_Field {\n  using F = Field;\n\
    \  const F base;\n  vector<F> power;\n\n  static inline F generate_base() { return\
    \ RNG(1LL << 60); }\n\n  inline void expand(int sz) {\n    if (int(power.size())\
    \ < sz + 1) {\n      int pre_sz = (int)power.size();\n      power.resize(sz +\
    \ 1);\n      for (int i = pre_sz - 1; i < sz; i++) { power[i + 1] = power[i] *\
    \ base; }\n    }\n  }\n\n  explicit RollingHash_Field(F base = generate_base())\
    \ : base(base), power{1} {}\n\n  template <typename STRING>\n  vector<F> build(const\
    \ STRING &s) const {\n    int sz = s.size();\n    vector<F> hashed(sz + 1);\n\
    \    for (int i = 0; i < sz; i++) {\n      hashed[i + 1] = (hashed[i] * base)\
    \ + F(s[i]);\n    }\n    return hashed;\n  }\n\n  F query(const vector<F> &s,\
    \ int l, int r) {\n    expand(r - l);\n    return s[r] - s[l] * power[r - l];\n\
    \  }\n\n  F combine(F h1, F h2, size_t h2len) {\n    expand(h2len);\n    return\
    \ add(mul(h1, power[h2len]), h2);\n  }\n\n  int lcp(const vector<F> &a, int l1,\
    \ int r1, const vector<F> &b, int l2,\n          int r2) {\n    int len = min(r1\
    \ - l1, r2 - l2);\n    int low = 0, high = len + 1;\n    while (high - low > 1)\
    \ {\n      int mid = (low + high) / 2;\n      if (query(a, l1, l1 + mid) == query(b,\
    \ l2, l2 + mid))\n        low = mid;\n      else\n        high = mid;\n    }\n\
    \    return low;\n  }\n};\n#line 8 \"test/atcoder/abc274_h.test.cpp\"\n\nvoid\
    \ solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n  using F = GF2<60>;\n  RollingHash_Field<F>\
    \ X;\n  auto HA = X.build(A);\n\n  FOR(Q) {\n    LL(a, b, c, d, e, f);\n    --a,\
    \ --c, --e;\n    ll n1 = b - a, n2 = f - e;\n\n    auto check = [&](int n) ->\
    \ bool {\n      // lcp >= n\n      if (n1 < n || n2 < n) return false;\n     \
    \ F x1 = X.query(HA, a, a + n);\n      F x2 = X.query(HA, c, c + n);\n      F\
    \ x3 = X.query(HA, e, e + n);\n      return (x1 + x2) == x3;\n    };\n\n    ll\
    \ n = binary_search(check, 0, N + 1);\n    if (n < min(n1, n2)) {\n      u64 x\
    \ = A[a + n] ^ A[c + n];\n      u64 y = A[e + n];\n      Yes(x < y);\n    } else\
    \ {\n      // prefix\n      Yes(n1 < n2);\n    }\n  }\n}\n\nsigned main() {\n\
    \  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc274/tasks/abc274_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"random/base.hpp\"\
    \n#include \"nt/GF2.hpp\"\n#include \"string/rollinghash_field.hpp\"\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  VEC(ll, A, N);\n  using F = GF2<60>;\n  RollingHash_Field<F>\
    \ X;\n  auto HA = X.build(A);\n\n  FOR(Q) {\n    LL(a, b, c, d, e, f);\n    --a,\
    \ --c, --e;\n    ll n1 = b - a, n2 = f - e;\n\n    auto check = [&](int n) ->\
    \ bool {\n      // lcp >= n\n      if (n1 < n || n2 < n) return false;\n     \
    \ F x1 = X.query(HA, a, a + n);\n      F x2 = X.query(HA, c, c + n);\n      F\
    \ x3 = X.query(HA, e, e + n);\n      return (x1 + x2) == x3;\n    };\n\n    ll\
    \ n = binary_search(check, 0, N + 1);\n    if (n < min(n1, n2)) {\n      u64 x\
    \ = A[a + n] ^ A[c + n];\n      u64 y = A[e + n];\n      Yes(x < y);\n    } else\
    \ {\n      // prefix\n      Yes(n1 < n2);\n    }\n  }\n}\n\nsigned main() {\n\
    \  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - nt/GF2.hpp
  - string/rollinghash_field.hpp
  isVerificationFile: true
  path: test/atcoder/abc274_h.test.cpp
  requiredBy: []
  timestamp: '2022-12-07 08:14:15+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc274_h.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc274_h.test.cpp
- /verify/test/atcoder/abc274_h.test.cpp.html
title: test/atcoder/abc274_h.test.cpp
---
