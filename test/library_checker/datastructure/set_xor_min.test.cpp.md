---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/binary_trie.hpp
    title: ds/binary_trie.hpp
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/library_checker/datastructure/set_xor_min.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#line 1 \"\
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
    \ yes(!t); }\r\n#line 1 \"ds/binary_trie.hpp\"\n// \u975E\u6C38\u7D9A\u306A\u3089\
    \u3070\u30012 * \u8981\u7D20\u6570 \u306E\u30CE\u30FC\u30C9\u6570\ntemplate <int\
    \ LOG, bool PERSISTENT, int NODES, typename UINT = u64,\n          typename SIZE_TYPE\
    \ = int>\nstruct Binary_Trie {\n  using T = SIZE_TYPE;\n  struct Node {\n    int\
    \ width;\n    UINT val;\n    T cnt;\n    Node *l, *r;\n  };\n\n  Node *pool;\n\
    \  int pid;\n  using np = Node *;\n\n  Binary_Trie() : pid(0) { pool = new Node[NODES];\
    \ }\n\n  void reset() { pid = 0; }\n\n  np new_root() { return nullptr; }\n\n\
    \  np add(np root, UINT val, T cnt = 1) {\n    if (!root) root = new_node(0, 0);\n\
    \    assert(0 <= val && val < (1LL << LOG));\n    return add_rec(root, LOG, val,\
    \ cnt);\n  }\n\n  // f(val, cnt)\n  template <typename F>\n  void enumerate(np\
    \ root, F f) {\n    auto dfs = [&](auto &dfs, np root, UINT val, int ht) -> void\
    \ {\n      if (ht == 0) {\n        f(val, root->cnt);\n        return;\n     \
    \ }\n      np c = root->l;\n      if (c) { dfs(dfs, c, val << (c->width) | (c->val),\
    \ ht - (c->width)); }\n      c = root->r;\n      if (c) { dfs(dfs, c, val << (c->width)\
    \ | (c->val), ht - (c->width)); }\n    };\n    if (root) dfs(dfs, root, 0, LOG);\n\
    \  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6607\u9806 k\
    \ \u756A\u76EE\n  UINT kth(np root, T k, UINT xor_val) {\n    assert(root && 0\
    \ <= k && k < root->cnt);\n    return kth_rec(root, 0, k, LOG, xor_val) ^ xor_val;\n\
    \  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6700\u5C0F\u5024\
    \n  UINT min(np root, UINT xor_val) {\n    assert(root && root->cnt);\n    return\
    \ kth(root, 0, xor_val);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\
    \u3067\u6700\u5927\u5024\n  UINT max(np root, UINT xor_val) {\n    assert(root\
    \ && root->cnt);\n    return kth(root, (root->cnt) - 1, xor_val);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067 [0, upper) \u5185\u306B\u5165\
    \u308B\u3082\u306E\u306E\u500B\u6570\n  T prefix_count(np root, UINT upper, UINT\
    \ xor_val) {\n    if (!root) return 0;\n    return prefix_count_rec(root, LOG,\
    \ upper, xor_val, 0);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\
    \u3067 [lo, hi) \u5185\u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\n  T count(np\
    \ root, UINT lo, UINT hi, UINT xor_val) {\n    return prefix_count(root, hi, xor_val)\
    \ - prefix_count(root, lo, xor_val);\n  }\n\nprivate:\n  inline UINT mask(int\
    \ k) { return (UINT(1) << k) - 1; }\n\n  np new_node(int width, UINT val) {\n\
    \    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].width = width;\n    pool[pid].val\
    \ = val;\n    pool[pid].cnt = 0;\n    return &(pool[pid++]);\n  }\n\n  np copy_node(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    np res = &(pool[pid++]);\n \
    \   res->width = c->width, res->val = c->val;\n    res->cnt = c->cnt, res->l =\
    \ c->l, res->r = c->r;\n    return res;\n  }\n\n  np add_rec(np root, int ht,\
    \ UINT val, T cnt) {\n    root = copy_node(root);\n    root->cnt += cnt;\n   \
    \ if (ht == 0) return root;\n\n    bool go_r = (val >> (ht - 1)) & 1;\n    np\
    \ c = (go_r ? root->r : root->l);\n    if (!c) {\n      c = new_node(ht, val);\n\
    \      c->cnt = cnt;\n      if (!go_r) root->l = c;\n      if (go_r) root->r =\
    \ c;\n      return root;\n    }\n    int w = c->width;\n    if ((val >> (ht -\
    \ w)) == c->val) {\n      c = add_rec(c, ht - w, val & mask(ht - w), cnt);\n \
    \     if (!go_r) root->l = c;\n      if (go_r) root->r = c;\n      return root;\n\
    \    }\n    int same = w - 1 - topbit((val >> (ht - w)) ^ (c->val));\n    np n\
    \ = new_node(same, (c->val) >> (w - same));\n    n->cnt = c->cnt + cnt;\n    c\
    \ = copy_node(c);\n    c->width = w - same;\n    c->val = c->val & mask(w - same);\n\
    \    if ((val >> (ht - same - 1)) & 1) {\n      n->l = c;\n      n->r = new_node(ht\
    \ - same, val & mask(ht - same));\n      n->r->cnt = cnt;\n    } else {\n    \
    \  n->r = c;\n      n->l = new_node(ht - same, val & mask(ht - same));\n     \
    \ n->l->cnt = cnt;\n    }\n    if (!go_r) root->l = n;\n    if (go_r) root->r\
    \ = n;\n    return root;\n  }\n\n  UINT kth_rec(np root, UINT val, T k, int ht,\
    \ UINT xor_val) {\n    if (ht == 0) return val;\n    np left = root->l, right\
    \ = root->r;\n    if ((xor_val >> (ht - 1)) & 1) swap(left, right);\n    T sl\
    \ = (left ? left->cnt : 0);\n    np c;\n    if (k < sl) { c = left; }\n    if\
    \ (k >= sl) { c = right, k -= sl; }\n    int w = c->width;\n    return kth_rec(c,\
    \ val << w | (c->val), k, ht - w, xor_val);\n  }\n\n  T prefix_count_rec(np root,\
    \ int ht, UINT LIM, UINT xor_val, UINT val) {\n    UINT now = (val << ht) ^ (xor_val);\n\
    \    if ((LIM >> ht) > (now >> ht)) return root->cnt;\n    if (ht == 0 || (LIM\
    \ >> ht) < (now >> ht)) return 0;\n    T res = 0;\n    FOR(k, 2) {\n      np c\
    \ = (k == 0 ? root->l : root->r);\n      if (c) {\n        int w = c->width;\n\
    \        res += prefix_count_rec(c, ht - w, LIM, xor_val, val << w | c->val);\n\
    \      }\n    }\n    return res;\n  }\n};\n#line 2 \"ds/hashmap.hpp\"\n\r\n//\
    \ u64 -> Val\r\ntemplate <typename Val, int LOG = 20, bool KEEP_IDS = false>\r\
    \nstruct HashMap {\r\n  using P = pair<u64, Val>;\r\n  static constexpr int N\
    \ = (1 << LOG);\r\n  P* dat;\r\n  vc<int> IDS;\r\n  bitset<N> used;\r\n  const\
    \ int shift;\r\n  const u64 r = 11995408973635179863ULL;\r\n  HashMap() : dat(new\
    \ P[N]), shift(64 - LOG) {}\r\n  int hash(ll x) {\r\n    static const u64 FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& key) {\r\n    int i = 0;\r\n    for (i = hash(key); used[i] && dat[i].fi\
    \ != key; (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& key) {\r\n    int i = index(key);\r\n    if (!used[i]) {\r\n      used[i]\
    \ = 1, dat[i] = {key, Val{}};\r\n      if constexpr (KEEP_IDS) IDS.eb(i);\r\n\
    \    }\r\n    return dat[i].se;\r\n  }\r\n\r\n  Val get(const u64& key, Val default_value)\
    \ {\r\n    int i = index(key);\r\n    if (!used[i]) return default_value;\r\n\
    \    return dat[i].se;\r\n  }\r\n\r\n  bool count(const u64& key) {\r\n    int\
    \ i = index(key);\r\n    return used[i] && dat[i].fi == key;\r\n  }\r\n\r\n  void\
    \ reset() {\r\n    static_assert(KEEP_IDS);\r\n    for (auto&& i: IDS) used[i]\
    \ = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key, val)\r\n  template <typename\
    \ F>\r\n  void enumerate_all(F f) {\r\n    static_assert(KEEP_IDS);\r\n    for\
    \ (auto&& i: IDS) f(dat[i].fi, dat[i].se);\r\n  }\r\n};\r\n#line 6 \"test/library_checker/datastructure/set_xor_min.test.cpp\"\
    \n\nvoid solve() {\n  HashMap<bool, 20> MP;\n  Binary_Trie<30, false, 1'000'000,\
    \ int, int> X;\n  using np = decltype(X)::np;\n  np root = nullptr;\n\n  INT(Q);\n\
    \  FOR(Q) {\n    INT(t, x);\n    if (t == 0) {\n      if (MP[x] == 0) {\n    \
    \    MP[x] = 1;\n        root = X.add(root, x, 1);\n      }\n    }\n    if (t\
    \ == 1) {\n      if (MP[x] == 1) {\n        MP[x] = 0;\n        root = X.add(root,\
    \ x, -1);\n      }\n    }\n    if (t == 2) { print(X.min(root, x)); }\n  }\n}\n\
    \nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/binary_trie.hpp\"\
    \n#include \"ds/hashmap.hpp\"\n\nvoid solve() {\n  HashMap<bool, 20> MP;\n  Binary_Trie<30,\
    \ false, 1'000'000, int, int> X;\n  using np = decltype(X)::np;\n  np root = nullptr;\n\
    \n  INT(Q);\n  FOR(Q) {\n    INT(t, x);\n    if (t == 0) {\n      if (MP[x] ==\
    \ 0) {\n        MP[x] = 1;\n        root = X.add(root, x, 1);\n      }\n    }\n\
    \    if (t == 1) {\n      if (MP[x] == 1) {\n        MP[x] = 0;\n        root\
    \ = X.add(root, x, -1);\n      }\n    }\n    if (t == 2) { print(X.min(root, x));\
    \ }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/binary_trie.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 18:59:57+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/set_xor_min.test.cpp
- /verify/test/library_checker/datastructure/set_xor_min.test.cpp.html
title: test/library_checker/datastructure/set_xor_min.test.cpp
---
