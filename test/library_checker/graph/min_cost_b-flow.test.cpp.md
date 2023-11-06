---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/bflow.hpp
    title: flow/bflow.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#line 1 \"test/library_checker/graph/min_cost_b-flow.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#line 1 \"\
    my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\
    #pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing u32\
    \ = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\nusing\
    \ u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
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
    \ yes(!t); }\r\n#line 2 \"flow/bflow.hpp\"\ntemplate <class Flow = ll, class Cost\
    \ = ll>\nstruct MinCostFlow {\nprivate:\n  static constexpr int SCALING_FACTOR\
    \ = 2;\n  using V_id = uint32_t;\n  using E_id = uint32_t;\n\n  struct Edge {\n\
    \    friend struct MinCostFlow;\n\n  private:\n    V_id frm, to;\n    Flow flow,\
    \ cap;\n    Cost cost;\n    E_id rev;\n\n  public:\n    Edge() = default;\n\n\
    \    Edge(const V_id frm, const V_id to, const Flow cap, const Cost cost,\n  \
    \       const E_id rev)\n        : frm(frm), to(to), flow(0), cap(cap), cost(cost),\
    \ rev(rev) {}\n\n    [[nodiscard]] Flow residual_cap() const { return cap - flow;\
    \ }\n  };\n\npublic:\n  struct EdgePtr {\n    friend struct MinCostFlow;\n\n \
    \ private:\n    const MinCostFlow *instance;\n    const V_id v;\n    const E_id\
    \ e;\n\n    EdgePtr(const MinCostFlow *instance, const V_id v, const E_id e)\n\
    \        : instance(instance), v(v), e(e) {}\n\n    [[nodiscard]] const Edge &edge()\
    \ const { return instance->g[v][e]; }\n    [[nodiscard]] const Edge &rev() const\
    \ {\n      const Edge &e = edge();\n      return instance->g[e.to][e.rev];\n \
    \   }\n\n  public:\n    [[nodiscard]] V_id frm() const { return rev().to; }\n\
    \    [[nodiscard]] V_id to() const { return edge().to; }\n    [[nodiscard]] Flow\
    \ flow() const { return edge().flow; }\n    [[nodiscard]] Flow lower() const {\
    \ return -rev().cap; }\n    [[nodiscard]] Flow upper() const { return edge().cap;\
    \ }\n    [[nodiscard]] Cost cost() const { return edge().cost; }\n    [[nodiscard]]\
    \ Cost gain() const { return -edge().cost; }\n  };\n\nprivate:\n  V_id n;\n  std::vector<std::vector<Edge>>\
    \ g;\n  std::vector<Flow> b;\n\npublic:\n  MinCostFlow(int n) : n(n) {\n    g.resize(n);\n\
    \    b.resize(n);\n  }\n\n  V_id add_vertex() {\n    ++n;\n    g.resize(n);\n\
    \    b.resize(n);\n    return n - 1;\n  }\n\n  std::vector<V_id> add_vertices(const\
    \ size_t size) {\n    std::vector<V_id> ret;\n    for (V_id i = 0; i < size; ++i)\
    \ ret.emplace_back(n + i);\n    n += size;\n    g.resize(n);\n    b.resize(n);\n\
    \    return ret;\n  }\n\n  void add(const V_id frm, const V_id to, const Flow\
    \ lo, const Flow hi,\n           const Cost cost) {\n    const E_id e = g[frm].size(),\
    \ re = frm == to ? e + 1 : g[to].size();\n    assert(lo <= hi);\n    g[frm].emplace_back(Edge{frm,\
    \ to, hi, cost, re});\n    g[to].emplace_back(Edge{to, frm, -lo, -cost, e});\n\
    \    edges.eb(EdgePtr{this, frm, e});\n  }\n\n  void add_source(const V_id v,\
    \ const Flow amount) { b[v] += amount; }\n  void add_sink(const V_id v, const\
    \ Flow amount) { b[v] -= amount; }\n\nprivate:\n  static Cost constexpr unreachable\
    \ = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  vc<Cost> potential,\
    \ dist;\n  vc<Edge *> parent;\n  pqg<pair<Cost, int>> pq;\n  vc<V_id> excess_vs,\
    \ deficit_vs;\n  vc<EdgePtr> edges;\n  Edge &rev(const Edge &e) { return g[e.to][e.rev];\
    \ }\n\n  void push(Edge &e, const Flow amount) {\n    e.flow += amount;\n    g[e.to][e.rev].flow\
    \ -= amount;\n  }\n\n  Cost residual_cost(const V_id frm, const V_id to, const\
    \ Edge &e) {\n    return e.cost + potential[frm] - potential[to];\n  }\n\n  bool\
    \ dual(const Flow delta) {\n    dist.assign(n, unreachable);\n    parent.assign(n,\
    \ nullptr);\n    excess_vs.erase(\n        remove_if(all(excess_vs), [&](const\
    \ V_id v) { return b[v] < delta; }),\n        end(excess_vs));\n    deficit_vs.erase(\n\
    \        remove_if(all(deficit_vs), [&](const V_id v) { return b[v] > -delta;\
    \ }),\n        end(deficit_vs));\n    for (const auto v: excess_vs) pq.emplace(dist[v]\
    \ = 0, v);\n    farthest = 0;\n    size_t deficit_count = 0;\n    while (!pq.empty())\
    \ {\n      const auto [d, u] = pq.top();\n      pq.pop();\n      if (dist[u] <\
    \ d) continue;\n      farthest = d;\n      if (b[u] <= -delta) ++deficit_count;\n\
    \      if (deficit_count >= deficit_vs.size()) break;\n      for (auto &e: g[u])\
    \ {\n        if (e.residual_cap() < delta) continue;\n        const auto v = e.to;\n\
    \        const auto new_dist = d + residual_cost(u, v, e);\n        if (new_dist\
    \ >= dist[v]) continue;\n        pq.emplace(dist[v] = new_dist, v);\n        parent[v]\
    \ = &e;\n      }\n    }\n    pq = decltype(pq)();\n    for (V_id v = 0; v < n;\
    \ ++v) {\n      potential[v] += std::min(dist[v], farthest);\n    }\n    return\
    \ deficit_count > 0;\n  }\n\n  void primal(const Flow delta) {\n    for (const\
    \ auto t: deficit_vs) {\n      if (dist[t] > farthest) continue;\n      Flow f\
    \ = -b[t];\n      V_id v;\n      for (v = t; parent[v] != nullptr && f >= delta;\
    \ v = parent[v]->frm) {\n        f = std::min(f, parent[v]->residual_cap());\n\
    \      }\n      f = std::min(f, b[v]);\n      if (f < delta) continue;\n     \
    \ for (v = t; parent[v] != nullptr;) {\n        auto &e = *parent[v];\n      \
    \  push(e, f);\n        const size_t u = parent[v]->frm;\n        parent[v] =\
    \ nullptr;\n        v = u;\n      }\n      b[t] += f;\n      b[v] -= f;\n    }\n\
    \  }\n\n  void saturate_negative(const Flow delta) {\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for (auto &es: g)\n      for (auto &e: es) {\n \
    \       const Flow rcap = e.residual_cap();\n        const Cost rcost = residual_cost(e.frm,\
    \ e.to, e);\n        if (rcost < 0 && rcap >= delta) {\n          push(e, rcap);\n\
    \          b[e.frm] -= rcap;\n          b[e.to] += rcap;\n        }\n      }\n\
    \    for (V_id v = 0; v < n; ++v)\n      if (b[v] != 0) { (b[v] > 0 ? excess_vs\
    \ : deficit_vs).emplace_back(v); }\n  }\n\npublic:\n  std::pair<bool, i128> solve()\
    \ {\n    potential.resize(n);\n    for (auto &es: g)\n      for (auto &e: es)\
    \ {\n        const Flow rcap = e.residual_cap();\n        if (rcap < 0) {\n  \
    \        push(e, rcap);\n          b[e.frm] -= rcap;\n          b[e.to] += rcap;\n\
    \        }\n      }\n    Flow inf_flow = 1;\n    for (const auto &es: g)\n   \
    \   for (const auto &e: es) inf_flow = std::max(inf_flow, e.residual_cap());\n\
    \    Flow delta = 1;\n    while (delta <= inf_flow) delta *= SCALING_FACTOR;\n\
    \n    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {\n      saturate_negative(delta);\n\
    \      while (dual(delta)) primal(delta);\n    }\n\n    i128 value = 0;\n    for\
    \ (const auto &es: g)\n      for (const auto &e: es) { value += i128(e.flow) *\
    \ e.cost; }\n    value /= 2;\n\n    if (excess_vs.empty() && deficit_vs.empty())\
    \ {\n      return {true, value};\n    } else {\n      return {false, value};\n\
    \    }\n  }\n\n  template <class T>\n  T get_result_value() {\n    T value = 0;\n\
    \    for (const auto &es: g)\n      for (const auto &e: es) { value += (T)(e.flow)\
    \ * (T)(e.cost); }\n    value /= (T)2;\n    return value;\n  }\n\n  std::vector<Cost>\
    \ get_potential() {\n    std::fill(potential.begin(), potential.end(), 0);\n \
    \   for (int i = 0; i < (int)n; i++)\n      for (const auto &es: g)\n        for\
    \ (const auto &e: es)\n          if (e.residual_cap() > 0)\n            potential[e.to]\n\
    \                = std::min(potential[e.to], potential[e.frm] + e.cost);\n   \
    \ return potential;\n  }\n\n  std::vector<EdgePtr> get_edges() { return edges;\
    \ }\n};\n#line 5 \"test/library_checker/graph/min_cost_b-flow.test.cpp\"\n\nvoid\
    \ solve() {\n  LL(N, M);\n  MinCostFlow<ll, ll> G(N);\n  FOR(i, N) {\n    LL(b);\n\
    \    G.add_source(i, b);\n  }\n  FOR(i, M) {\n    LL(frm, to, lo, hi, cost);\n\
    \    G.add(frm, to, lo, hi, cost);\n  }\n  auto [ok, cost] = G.solve();\n  if\
    \ (!ok) return print(\"infeasible\");\n  print(cost);\n  for (auto &&p: G.get_potential())\
    \ print(p);\n  for (auto &&e: G.get_edges()) { print(e.flow()); }\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/bflow.hpp\"\n\
    \nvoid solve() {\n  LL(N, M);\n  MinCostFlow<ll, ll> G(N);\n  FOR(i, N) {\n  \
    \  LL(b);\n    G.add_source(i, b);\n  }\n  FOR(i, M) {\n    LL(frm, to, lo, hi,\
    \ cost);\n    G.add(frm, to, lo, hi, cost);\n  }\n  auto [ok, cost] = G.solve();\n\
    \  if (!ok) return print(\"infeasible\");\n  print(cost);\n  for (auto &&p: G.get_potential())\
    \ print(p);\n  for (auto &&e: G.get_edges()) { print(e.flow()); }\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/bflow.hpp
  isVerificationFile: true
  path: test/library_checker/graph/min_cost_b-flow.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 18:59:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/min_cost_b-flow.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/min_cost_b-flow.test.cpp
- /verify/test/library_checker/graph/min_cost_b-flow.test.cpp.html
title: test/library_checker/graph/min_cost_b-flow.test.cpp
---
