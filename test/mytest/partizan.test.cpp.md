---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: game/dyadic_rational.hpp
    title: game/dyadic_rational.hpp
  - icon: ':x:'
    path: game/solve_partizan_game.hpp
    title: game/solve_partizan_game.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/partizan.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \  return B;\n}\n#endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n#include\
    \ <unistd.h>\r\n\r\nnamespace fastio {\r\nstruct Pre {\r\n  char num[10000][4];\r\
    \n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n   \
    \   int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n        num[i][j] =\
    \ n % 10 | '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr\
    \ pre;\r\n\r\ntemplate <typename T>\r\nstruct has_read_method {\r\n  template\
    \ <typename U>\r\n  static std::true_type test(decltype(&U::read) *);\r\n  template\
    \ <typename>\r\n  static std::false_type test(...);\r\n  using type = decltype(test<T>(nullptr));\r\
    \n  static constexpr bool value = type::value;\r\n};\r\n\r\ntemplate <typename\
    \ T>\r\nstruct has_print_method {\r\n  template <typename U>\r\n  static std::true_type\
    \ test(decltype(&U::print) *);\r\n  template <typename>\r\n  static std::false_type\
    \ test(...);\r\n  using type = decltype(test<T>(nullptr));\r\n  static constexpr\
    \ bool value = type::value;\r\n};\r\n\r\nstruct Scanner {\r\n  FILE *fp;\r\n \
    \ char line[(1 << 15) + 1];\r\n  size_t st = 0, ed = 0;\r\n  void reread() {\r\
    \n    memmove(line, line + st, ed - st);\r\n    ed -= st;\r\n    st = 0;\r\n \
    \   ed += fread(line + ed, 1, (1 << 15) - ed, fp);\r\n    line[ed] = '\\0';\r\n\
    \  }\r\n  void succ() {\r\n    while (true) {\r\n      if (st == ed) {\r\n   \
    \     reread();\r\n        if (st == ed) return;\r\n      }\r\n      while (st\
    \ != ed && isspace(line[st])) st++;\r\n      if (st != ed) break;\r\n    }\r\n\
    \    if (ed - st <= 100) {\r\n      bool sep = false;\r\n      for (size_t i =\
    \ st; i < ed; i++) {\r\n        if (isspace(line[i])) {\r\n          sep = true;\r\
    \n          break;\r\n        }\r\n      }\r\n      if (!sep) reread();\r\n  \
    \  }\r\n    return;\r\n  }\r\n\r\n  void rd(char &c) {\r\n    succ();\r\n    c\
    \ = line[st++];\r\n  }\r\n\r\n  void rd(string &x) {\r\n    x.clear();\r\n   \
    \ succ();\r\n    while (true) {\r\n      size_t sz = 0;\r\n      while (st + sz\
    \ < ed && !isspace(line[st + sz])) sz++;\r\n      x.append(line + st, sz);\r\n\
    \      st += sz;\r\n      if (!sz || st != ed) break;\r\n      reread();\r\n \
    \   }\r\n  }\r\n\r\n  template <typename T>\r\n  void rd_integer(T &x) {\r\n \
    \   succ();\r\n    bool minus = 0;\r\n    char c = line[st++];\r\n    if constexpr\
    \ (is_signed<T>::value || is_same_v<T, i128>) {\r\n      if (c == '-') { minus\
    \ = 1, c = line[st++]; }\r\n    }\r\n    x = 0;\r\n    while (c >= '0') { x =\
    \ x * 10 + (c & 15), c = line[st++]; }\r\n    if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n      if (minus) x = -x;\r\n    }\r\n  }\r\n\r\n\
    \  template <typename T>\r\n  void rd_real(T &x) {\r\n    string s;\r\n    rd(s);\r\
    \n    x = stod(s);\r\n  }\r\n\r\n  template <typename T>\r\n  typename enable_if<has_read_method<T>::value,\
    \ void>::type rd(T &x) {\r\n    x.read();\r\n  }\r\n\r\n  void rd(int &x) { rd_integer(x);\
    \ }\r\n  void rd(ll &x) { rd_integer(x); }\r\n  void rd(i128 &x) { rd_integer(x);\
    \ }\r\n  void rd(u32 &x) { rd_integer(x); }\r\n  void rd(u64 &x) { rd_integer(x);\
    \ }\r\n  void rd(u128 &x) { rd_integer(x); }\r\n  void rd(double &x) { rd_real(x);\
    \ }\r\n  void rd(long double &x) { rd_real(x); }\r\n  void rd(f128 &x) { rd_real(x);\
    \ }\r\n  template <class T, class U>\r\n  void rd(pair<T, U> &p) {\r\n    return\
    \ rd(p.first), rd(p.second);\r\n  }\r\n  template <size_t N = 0, typename T>\r\
    \n  void rd_tuple(T &t) {\r\n    if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n      auto &x = std::get<N>(t);\r\n      rd(x);\r\n      rd_tuple<N + 1>(t);\r\
    \n    }\r\n  }\r\n  template <class... T>\r\n  void rd(tuple<T...> &tpl) {\r\n\
    \    rd_tuple(tpl);\r\n  }\r\n  template <class T>\r\n  void rd(vc<T> &x) {\r\n\
    \    for (auto &d: x) rd(d);\r\n  }\r\n  template <size_t N = 0, typename T>\r\
    \n  void rd(array<T, N> &x) {\r\n    for (auto &d: x) rd(d);\r\n  }\r\n  Scanner(FILE\
    \ *fp) : fp(fp) {}\r\n};\r\n\r\nstruct Printer {\r\n  Printer(FILE *_fp) : fp(_fp)\
    \ {}\r\n  ~Printer() { flush(); }\r\n\r\n  static constexpr size_t SIZE = 1 <<\
    \ 15;\r\n  FILE *fp;\r\n  char line[SIZE], out[100];\r\n  size_t pos = 0;\r\n\
    \  void flush() {\r\n    fwrite(line, 1, pos, fp);\r\n    pos = 0;\r\n  }\r\n\r\
    \n  void wt(const char val) {\r\n    if (pos == SIZE) flush();\r\n    line[pos++]\
    \ = val;\r\n  }\r\n  void wt(const string &s) {\r\n    for (char c: s) wt(c);\r\
    \n  }\r\n  void wt(const char *s) {\r\n    size_t len = strlen(s);\r\n    for\
    \ (size_t i = 0; i < len; i++) wt(s[i]);\r\n  }\r\n\r\n  template <typename T>\r\
    \n  void wt_integer(T x) {\r\n    if (pos > SIZE - 100) flush();\r\n    if (x\
    \ < 0) { line[pos++] = '-', x = -x; }\r\n    int outi;\r\n    for (outi = 96;\
    \ x >= 10000; outi -= 4) {\r\n      memcpy(out + outi, pre.num[x % 10000], 4);\r\
    \n      x /= 10000;\r\n    }\r\n    if (x >= 1000) {\r\n      memcpy(line + pos,\
    \ pre.num[x], 4), pos += 4;\r\n    } else if (x >= 100) {\r\n      memcpy(line\
    \ + pos, pre.num[x] + 1, 3), pos += 3;\r\n    } else if (x >= 10) {\r\n      int\
    \ q = (x * 103) >> 10;\r\n      line[pos] = q | '0';\r\n      line[pos + 1] =\
    \ (x - q * 10) | '0';\r\n      pos += 2;\r\n    } else\r\n      line[pos++] =\
    \ x | '0';\r\n    memcpy(line + pos, out + outi + 4, 96 - outi);\r\n    pos +=\
    \ 96 - outi;\r\n  }\r\n\r\n  template <typename T>\r\n  void wt_real(T x) {\r\n\
    \    ostringstream oss;\r\n    oss << fixed << setprecision(15) << double(x);\r\
    \n    string s = oss.str();\r\n    wt(s);\r\n  }\r\n\r\n  template <typename T>\r\
    \n  typename enable_if<has_print_method<T>::value, void>::type wt(T x) {\r\n \
    \   x.print();\r\n  }\r\n\r\n  void wt(bool x) { wt_integer(int(x)); }\r\n  void\
    \ wt(int x) { wt_integer(x); }\r\n  void wt(ll x) { wt_integer(x); }\r\n  void\
    \ wt(i128 x) { wt_integer(x); }\r\n  void wt(u32 x) { wt_integer(x); }\r\n  void\
    \ wt(u64 x) { wt_integer(x); }\r\n  void wt(u128 x) { wt_integer(x); }\r\n  void\
    \ wt(double x) { wt_real(x); }\r\n  void wt(long double x) { wt_real(x); }\r\n\
    \  void wt(f128 x) { wt_real(x); }\r\n\r\n  template <class T, class U>\r\n  void\
    \ wt(const pair<T, U> val) {\r\n    wt(val.first);\r\n    wt(' ');\r\n    wt(val.second);\r\
    \n  }\r\n  template <size_t N = 0, typename T>\r\n  void wt_tuple(const T t) {\r\
    \n    if constexpr (N < std::tuple_size<T>::value) {\r\n      if constexpr (N\
    \ > 0) { wt(' '); }\r\n      const auto x = std::get<N>(t);\r\n      wt(x);\r\n\
    \      wt_tuple<N + 1>(t);\r\n    }\r\n  }\r\n  template <class... T>\r\n  void\
    \ wt(tuple<T...> tpl) {\r\n    wt_tuple(tpl);\r\n  }\r\n  template <class T, size_t\
    \ S>\r\n  void wt(const array<T, S> val) {\r\n    auto n = val.size();\r\n   \
    \ for (size_t i = 0; i < n; i++) {\r\n      if (i) wt(' ');\r\n      wt(val[i]);\r\
    \n    }\r\n  }\r\n  template <class T>\r\n  void wt(const vector<T> val) {\r\n\
    \    auto n = val.size();\r\n    for (size_t i = 0; i < n; i++) {\r\n      if\
    \ (i) wt(' ');\r\n      wt(val[i]);\r\n    }\r\n  }\r\n};\r\nScanner scanner =\
    \ Scanner(stdin);\r\nPrinter printer = Printer(stdout);\r\nvoid flush() { printer.flush();\
    \ }\r\nvoid print() { printer.wt('\\n'); }\r\ntemplate <class Head, class... Tail>\r\
    \nvoid print(Head &&head, Tail &&... tail) {\r\n  printer.wt(head);\r\n  if (sizeof...(Tail))\
    \ printer.wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head &head, Tail &...\
    \ tail) {\r\n  scanner.rd(head);\r\n  read(tail...);\r\n}\r\n} // namespace fastio\r\
    \nusing fastio::print;\r\nusing fastio::flush;\r\nusing fastio::read;\r\n\r\n\
    #define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)\
    \      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 1 \"game/dyadic_rational.hpp\"\n// a+b/2^M \u306E\u5F62\u3067\
    \u6301\u3064\ntemplate <typename INTEGER>\nstruct Dyadic_Rational {\n  using X\
    \ = Dyadic_Rational;\n  INTEGER a, b;\n  static constexpr int M = std::numeric_limits<INTEGER>::digits\
    \ - 2;\n\n  Dyadic_Rational(INTEGER a = 0) : a(a), b(0) {}\n\n  // x + y / z\n\
    \  Dyadic_Rational(INTEGER x, INTEGER y, INTEGER z) : a(x), b(y) {\n    auto [q,\
    \ r] = divmod(b, z);\n    a += q;\n    b = r;\n    b *= (INTEGER(1) << M) / z;\n\
    \  }\n\n  // x/y\n  Dyadic_Rational(INTEGER x, INTEGER y) : Dyadic_Rational(0,\
    \ x, y) {}\n\n  static X from_ab(INTEGER a, INTEGER b) {\n    X x(a);\n    x.b\
    \ = b;\n    return x;\n  }\n\n  // \u6BD4\u8F03\n  bool operator==(X const& rhs)\
    \ const { return (a == rhs.a && b == rhs.b); }\n  bool operator!=(X const& rhs)\
    \ const { return !(*this == rhs); }\n  bool operator<(X const& rhs) const {\n\
    \    return (a < rhs.a) || (a == rhs.a && b < rhs.b);\n  }\n  bool operator<=(X\
    \ const& rhs) const {\n    return (a < rhs.a) || (a == rhs.a && b <= rhs.b);\n\
    \  }\n  bool operator>(X const& rhs) const {\n    return (a > rhs.a) || (a ==\
    \ rhs.a && b > rhs.b);\n  }\n  bool operator>=(X const& rhs) const {\n    return\
    \ (a > rhs.a) || (a == rhs.a && b >= rhs.b);\n  }\n\n  // \u52A0\u6CD5\n  friend\
    \ X operator+(const X& x, const X& y) {\n    INTEGER a = x.a + y.a, b = x.b +\
    \ y.b;\n    while (b >= INTEGER(1) << M) {\n      ++a;\n      b -= INTEGER(1)\
    \ << M;\n    }\n    return from_ab(a, b);\n  }\n  friend X operator-(const X&\
    \ x, const X& y) {\n    INTEGER a = x.a - y.a, b = x.b - y.b;\n    while (b <\
    \ 0) {\n      --a;\n      b += INTEGER(1) << M;\n    }\n    return from_ab(a,\
    \ b);\n  }\n  friend X operator-(const X& x) {\n    INTEGER a = -x.a, b = -x.b;\n\
    \    while (b < 0) {\n      --a;\n      b += INTEGER(1) << M;\n    }\n    return\
    \ from_ab(a, b);\n  }\n  X& operator+=(const X& x) { return (*this) = (*this)\
    \ + x; }\n  X& operator-=(const X& x) { return (*this) = (*this) - x; }\n\n  static\
    \ X simplest(const X& x, const X& y) {\n    assert(x < y);\n    if (y.a < 0) return\
    \ -simplest(-y, -x);\n    {\n      INTEGER l = x.a + 1;\n      INTEGER r = (y.b\
    \ == 0 ? y.a - 1 : y.a);\n      if (l <= 0 && 0 <= r) return X(0);\n      if (l\
    \ <= r && 0 <= l) return X(l);\n      if (l <= r && r <= 0) return X(r);\n   \
    \ }\n\n    INTEGER l = x.b + 1;\n    INTEGER r = (y.b == 0 ? (INTEGER(1) << M)\
    \ - 1 : y.b - 1);\n    if (l == r) return from_ab(x.a, l);\n    int k = topbit(l\
    \ ^ r);\n    r &= ~((INTEGER(1) << k) - 1);\n    return from_ab(x.a, r);\n  }\n\
    \n  static constexpr X infinity() { return from_ab(INTEGER(1) << M, 0); }\n\n\
    \  string to_string() {\n    ll x = a, y = b, z = INTEGER(1) << M;\n    while\
    \ (y % 2 == 0 && z % 2 == 0) { y /= 2, z /= 2; }\n    y += x * z;\n    return\
    \ std::to_string(y) + \"/\" + std::to_string(z);\n  }\n};\n#line 2 \"game/solve_partizan_game.hpp\"\
    \n\n// \u5168\u90E8 dyadic rational number \u306B\u306A\u308B\u3068\u304D\u3060\
    \u3051\u89E3\u3051\u308B\n// \u5931\u6557\u3057\u305F\u3068\u304D\u306F\u3001\
    empty map \u304C\u8FD4\u308B\n// \u30FBstates\uFF1A\u8208\u5473\u306E\u3042\u308B\
    \ state \u5168\u4F53\n// \u30FBget_options\uFF1Apair<vc<STATE>, vc<STATE>>(STATE),\
    \ left ops / right ops\ntemplate <typename STATE, typename INTEGER, typename F>\n\
    unordered_map<STATE, Dyadic_Rational<INTEGER>> solve_partizan_game(\n    const\
    \ vector<STATE>& states, F get_options) {\n  using X = Dyadic_Rational<INTEGER>;\n\
    \  unordered_map<STATE, X> MP;\n\n  bool success = 1;\n\n  auto dfs = [&](auto&\
    \ dfs, const STATE& s) -> X {\n    if (!success) return X();\n    if (MP.count(s))\
    \ return MP[s];\n    vc<X> left, right;\n    X xl = -X::infinity(), xr = X::infinity();\n\
    \    auto [left_ops, right_ops] = get_options(s);\n    for (auto&& t: left_ops)\
    \ chmax(xl, dfs(dfs, t));\n    for (auto&& t: right_ops) chmin(xr, dfs(dfs, t));\n\
    \n    if (xl >= xr) {\n      // switch\n      success = 0;\n      MP.clear();\n\
    \      return X();\n    }\n    return (MP[s] = X::simplest(xl, xr));\n  };\n\n\
    \  for (auto&& s: states) dfs(dfs, s);\n  return MP;\n}\n#line 6 \"test/mytest/partizan.test.cpp\"\
    \n\nvoid test_push() {\n  // LESSONS IN PLAY p.113\n  vc<string> states = {\"\
    LR\", \".RL\", \".R\", \"RRL\"};\n  auto get_options = [&](string s) -> pair<vc<string>,\
    \ vc<string>> {\n    vc<string> left_ops, right_ops;\n    FOR(i, len(s)) {\n \
    \     if (s[i] == '.') continue;\n      string t = s;\n      char x = '.';\n \
    \     int p = i;\n      while (p >= 0) {\n        swap(x, t[p--]);\n        if\
    \ (x == '.') break;\n      }\n      if (s[i] == 'L') left_ops.eb(t);\n      if\
    \ (s[i] == 'R') right_ops.eb(t);\n    }\n    return {left_ops, right_ops};\n \
    \ };\n\n  auto MP = solve_partizan_game<string, ll>(states, get_options);\n  //\
    \ for (auto&& [s, x]: MP) { print(s, x.to_string()); }\n  assert(MP[\"LR\"].to_string()\
    \ == \"-3/2\");\n  assert(MP[\".RL\"].to_string() == \"7/4\");\n  assert(MP[\"\
    .R\"].to_string() == \"-2/1\");\n  assert(MP[\"RRL\"].to_string() == \"13/8\"\
    );\n}\n\nvoid test_problem_5_2() {\n  // switch \u306B\u306A\u308B\u306E\u3067\
    \u89E3\u3051\u306A\u3044\n  int LIM = 10;\n  vc<int> states(LIM);\n  iota(all(states),\
    \ 0);\n\n  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {\n    vc<int>\
    \ left_ops, right_ops;\n    if (s % 3 == 0 && s >= 1) left_ops.eb(s - 1), right_ops.eb(s\
    \ - 1);\n    if (s % 3 == 0 && s >= 2) left_ops.eb(s - 2), right_ops.eb(s - 2);\n\
    \    if (s % 3 == 1 && s >= 1) left_ops.eb(s - 1);\n    if (s % 3 == 1 && s >=\
    \ 2) left_ops.eb(s - 2);\n    if (s % 3 == 2 && s >= 1) right_ops.eb(s - 1);\n\
    \    if (s % 3 == 2 && s >= 2) right_ops.eb(s - 2);\n    return {left_ops, right_ops};\n\
    \  };\n\n  auto MP = solve_partizan_game<int, ll>(states, get_options);\n  assert(MP.empty());\n\
    }\n\nvoid test_problem_5_3() {\n  int LIM = 10;\n  vc<int> states(LIM);\n  iota(all(states),\
    \ 0);\n\n  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {\n    vc<int>\
    \ left_ops, right_ops;\n    if (s % 2 == 0 && s >= 2) left_ops.eb(s - 2);\n  \
    \  if (s % 2 == 0 && s >= 1) right_ops.eb(s - 1);\n    if (s % 2 == 1 && s >=\
    \ 1) left_ops.eb(s - 1);\n    if (s % 2 == 1 && s >= 2) right_ops.eb(s - 2);\n\
    \    return {left_ops, right_ops};\n  };\n\n  auto MP = solve_partizan_game<int,\
    \ ll>(states, get_options);\n  assert(MP[0].to_string() == \"0/1\");\n  assert(MP[1].to_string()\
    \ == \"1/1\");\n  assert(MP[2].to_string() == \"1/2\");\n  assert(MP[3].to_string()\
    \ == \"3/4\");\n  assert(MP[4].to_string() == \"5/8\");\n  assert(MP[5].to_string()\
    \ == \"11/16\");\n}\n\nint solve_cherries(string s) {\n  // LR cherries \u3092\
    \ O(N) \u3067\u89E3\u304F\n  auto eval = [&](char c) -> int {\n    if (c == 'L')\
    \ return 1;\n    if (c == 'R') return -1;\n    return 0;\n  };\n\n  int n = len(s);\n\
    \  if (n == 0) return 0;\n  int res = 0;\n\n  FOR(2) {\n    reverse(all(s));\n\
    \    while (n >= 2 && s[n - 1] == s[n - 2]) {\n      res += eval(s[n - 1]);\n\
    \      s.pop_back();\n      n = len(s);\n    }\n  }\n\n  char a = '.', b = '.';\n\
    \  FOR_R(i, n - 1) if (s[i] == s[i + 1]) a = s[i];\n  FOR(i, n - 1) if (s[i] ==\
    \ s[i + 1]) b = s[i];\n  int x = eval(s[0]) + eval(a) + eval(b) + eval(s[n - 1]);\n\
    \  return res + x / 2;\n};\n\nvoid test_cherries() {\n  int MAX_LEN = 20;\n  vc<string>\
    \ states;\n  states.eb(\"\");\n  int p = 0, q = 1;\n  FOR(MAX_LEN) {\n    FOR(i,\
    \ p, q) {\n      states.eb(states[i] + \"L\");\n      states.eb(states[i] + \"\
    R\");\n    }\n    p = q;\n    q = len(states);\n  }\n\n  auto get_options = [&](string\
    \ s) -> pair<vc<string>, vc<string>> {\n    vc<string> left, right;\n    int n\
    \ = len(s);\n\n    if (n && s[0] == 'L') left.eb(s.substr(1, n - 1));\n    if\
    \ (n && s[0] == 'R') right.eb(s.substr(1, n - 1));\n    if (n && s[n - 1] == 'L')\
    \ left.eb(s.substr(0, n - 1));\n    if (n && s[n - 1] == 'R') right.eb(s.substr(0,\
    \ n - 1));\n    return {left, right};\n  };\n\n  auto MP = solve_partizan_game<string,\
    \ ll>(states, get_options);\n\n  for (auto&& [s, x]: MP) {\n    int my_ans = solve_cherries(s);\n\
    \    assert(x == Dyadic_Rational<ll>(my_ans, 1));\n  }\n}\n\nvoid test() {\n \
    \ test_push();\n  test_problem_5_2();\n  test_problem_5_3();\n  test_cherries();\n\
    }\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  test();\n\n\
    \  ll T = 1;\n  FOR(T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"game/solve_partizan_game.hpp\"\
    \n\nvoid test_push() {\n  // LESSONS IN PLAY p.113\n  vc<string> states = {\"\
    LR\", \".RL\", \".R\", \"RRL\"};\n  auto get_options = [&](string s) -> pair<vc<string>,\
    \ vc<string>> {\n    vc<string> left_ops, right_ops;\n    FOR(i, len(s)) {\n \
    \     if (s[i] == '.') continue;\n      string t = s;\n      char x = '.';\n \
    \     int p = i;\n      while (p >= 0) {\n        swap(x, t[p--]);\n        if\
    \ (x == '.') break;\n      }\n      if (s[i] == 'L') left_ops.eb(t);\n      if\
    \ (s[i] == 'R') right_ops.eb(t);\n    }\n    return {left_ops, right_ops};\n \
    \ };\n\n  auto MP = solve_partizan_game<string, ll>(states, get_options);\n  //\
    \ for (auto&& [s, x]: MP) { print(s, x.to_string()); }\n  assert(MP[\"LR\"].to_string()\
    \ == \"-3/2\");\n  assert(MP[\".RL\"].to_string() == \"7/4\");\n  assert(MP[\"\
    .R\"].to_string() == \"-2/1\");\n  assert(MP[\"RRL\"].to_string() == \"13/8\"\
    );\n}\n\nvoid test_problem_5_2() {\n  // switch \u306B\u306A\u308B\u306E\u3067\
    \u89E3\u3051\u306A\u3044\n  int LIM = 10;\n  vc<int> states(LIM);\n  iota(all(states),\
    \ 0);\n\n  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {\n    vc<int>\
    \ left_ops, right_ops;\n    if (s % 3 == 0 && s >= 1) left_ops.eb(s - 1), right_ops.eb(s\
    \ - 1);\n    if (s % 3 == 0 && s >= 2) left_ops.eb(s - 2), right_ops.eb(s - 2);\n\
    \    if (s % 3 == 1 && s >= 1) left_ops.eb(s - 1);\n    if (s % 3 == 1 && s >=\
    \ 2) left_ops.eb(s - 2);\n    if (s % 3 == 2 && s >= 1) right_ops.eb(s - 1);\n\
    \    if (s % 3 == 2 && s >= 2) right_ops.eb(s - 2);\n    return {left_ops, right_ops};\n\
    \  };\n\n  auto MP = solve_partizan_game<int, ll>(states, get_options);\n  assert(MP.empty());\n\
    }\n\nvoid test_problem_5_3() {\n  int LIM = 10;\n  vc<int> states(LIM);\n  iota(all(states),\
    \ 0);\n\n  auto get_options = [&](int s) -> pair<vc<int>, vc<int>> {\n    vc<int>\
    \ left_ops, right_ops;\n    if (s % 2 == 0 && s >= 2) left_ops.eb(s - 2);\n  \
    \  if (s % 2 == 0 && s >= 1) right_ops.eb(s - 1);\n    if (s % 2 == 1 && s >=\
    \ 1) left_ops.eb(s - 1);\n    if (s % 2 == 1 && s >= 2) right_ops.eb(s - 2);\n\
    \    return {left_ops, right_ops};\n  };\n\n  auto MP = solve_partizan_game<int,\
    \ ll>(states, get_options);\n  assert(MP[0].to_string() == \"0/1\");\n  assert(MP[1].to_string()\
    \ == \"1/1\");\n  assert(MP[2].to_string() == \"1/2\");\n  assert(MP[3].to_string()\
    \ == \"3/4\");\n  assert(MP[4].to_string() == \"5/8\");\n  assert(MP[5].to_string()\
    \ == \"11/16\");\n}\n\nint solve_cherries(string s) {\n  // LR cherries \u3092\
    \ O(N) \u3067\u89E3\u304F\n  auto eval = [&](char c) -> int {\n    if (c == 'L')\
    \ return 1;\n    if (c == 'R') return -1;\n    return 0;\n  };\n\n  int n = len(s);\n\
    \  if (n == 0) return 0;\n  int res = 0;\n\n  FOR(2) {\n    reverse(all(s));\n\
    \    while (n >= 2 && s[n - 1] == s[n - 2]) {\n      res += eval(s[n - 1]);\n\
    \      s.pop_back();\n      n = len(s);\n    }\n  }\n\n  char a = '.', b = '.';\n\
    \  FOR_R(i, n - 1) if (s[i] == s[i + 1]) a = s[i];\n  FOR(i, n - 1) if (s[i] ==\
    \ s[i + 1]) b = s[i];\n  int x = eval(s[0]) + eval(a) + eval(b) + eval(s[n - 1]);\n\
    \  return res + x / 2;\n};\n\nvoid test_cherries() {\n  int MAX_LEN = 20;\n  vc<string>\
    \ states;\n  states.eb(\"\");\n  int p = 0, q = 1;\n  FOR(MAX_LEN) {\n    FOR(i,\
    \ p, q) {\n      states.eb(states[i] + \"L\");\n      states.eb(states[i] + \"\
    R\");\n    }\n    p = q;\n    q = len(states);\n  }\n\n  auto get_options = [&](string\
    \ s) -> pair<vc<string>, vc<string>> {\n    vc<string> left, right;\n    int n\
    \ = len(s);\n\n    if (n && s[0] == 'L') left.eb(s.substr(1, n - 1));\n    if\
    \ (n && s[0] == 'R') right.eb(s.substr(1, n - 1));\n    if (n && s[n - 1] == 'L')\
    \ left.eb(s.substr(0, n - 1));\n    if (n && s[n - 1] == 'R') right.eb(s.substr(0,\
    \ n - 1));\n    return {left, right};\n  };\n\n  auto MP = solve_partizan_game<string,\
    \ ll>(states, get_options);\n\n  for (auto&& [s, x]: MP) {\n    int my_ans = solve_cherries(s);\n\
    \    assert(x == Dyadic_Rational<ll>(my_ans, 1));\n  }\n}\n\nvoid test() {\n \
    \ test_push();\n  test_problem_5_2();\n  test_problem_5_3();\n  test_cherries();\n\
    }\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  test();\n\n\
    \  ll T = 1;\n  FOR(T) solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - game/solve_partizan_game.hpp
  - game/dyadic_rational.hpp
  isVerificationFile: true
  path: test/mytest/partizan.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 18:59:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/partizan.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/partizan.test.cpp
- /verify/test/mytest/partizan.test.cpp.html
title: test/mytest/partizan.test.cpp
---
