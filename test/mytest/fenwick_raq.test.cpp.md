---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/acted_monoid/sum_add.hpp
    title: alg/acted_monoid/sum_add.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':x:'
    path: ds/fenwicktree/fenwicktree_range_add.hpp
    title: ds/fenwicktree/fenwicktree_range_add.hpp
  - icon: ':x:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/fenwick_raq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \  return B;\n}\n#endif\n#line 1 \"other/io.hpp\"\n#include <unistd.h>\r\n#include\
    \ <sys/mman.h>\r\n#include <sys/stat.h>\r\n\r\nnamespace fastio {\r\n// https://judge.yosupo.jp/submission/21623\r\
    \n// https://judge.yosupo.jp/submission/70667\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\
    \n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n   \
    \   int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n        num[i][j] =\
    \ n % 10 | '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr\
    \ pre;\r\n\r\nconstexpr int BSZ = 1 << 19;\r\nchar *ibuf, obuf[BSZ], out[100];\r\
    \nint outi, obufi;\r\n\r\n// gcc expansion. called automaticall before main.\r\
    \nvoid __attribute__((constructor)) _c() {\r\n  struct stat sb;\r\n  fstat(0,\
    \ &sb);\r\n  ibuf\r\n      = (char *)mmap(0, sb.st_size, PROT_READ, MAP_SHARED\
    \ | MAP_POPULATE, 0, 0);\r\n}\r\n\r\nvoid flush() {\r\n  assert(write(1, obuf,\
    \ obufi) == obufi);\r\n  obufi = 0;\r\n}\r\n\r\nvoid rd(char &c) { c = *ibuf++;\
    \ }\r\nvoid rd(string &x) {\r\n  x.clear();\r\n  char c;\r\n  do { rd(c); } while\
    \ (isspace(c));\r\n  do { x += c, rd(c); } while (!isspace(c));\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvoid rd_integer(T &x) {\r\n  char c;\r\n  do\r\n    rd(c);\r\
    \n  while (c < '-');\r\n  bool minus = 0;\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (c == '-') { minus = 1, rd(c); }\r\n  }\r\
    \n  x = 0;\r\n  while (c >= '0') { x = x * 10 + (c & 15), rd(c); }\r\n  if constexpr\
    \ (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (minus) x = -x;\r\n\
    \  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n  string s;\r\
    \n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\nvoid rd(int &x) { rd_integer(x); }\r\n\
    void rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double &x) { rd_real(x); }\r\nvoid\
    \ rd(long double &x) { rd_real(x); }\r\nvoid rd(f128 &x) { rd_real(x); }\r\ntemplate\
    \ <class T, class U>\r\nvoid rd(pair<T, U> &p) {\r\n  return rd(p.first), rd(p.second);\r\
    \n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd(T &t) {\r\n  if constexpr\
    \ (N < std::tuple_size<T>::value) {\r\n    auto &x = std::get<N>(t);\r\n    rd(x);\r\
    \n    rd<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\nvoid rd(tuple<T...>\
    \ &tpl) {\r\n  rd(tpl);\r\n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\n\
    \  for (auto &d: x) rd(d);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid\
    \ rd(array<T, N> &x) {\r\n  for (auto &d: x) rd(d);\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nstruct has_read_method {\r\n  template <typename U>\r\n  static std::true_type\
    \ test(decltype(&U::read) *);\r\n  template <typename>\r\n  static std::false_type\
    \ test(...);\r\n  using type = decltype(test<T>(nullptr));\r\n  static constexpr\
    \ bool value = type::value;\r\n};\r\n\r\ntemplate <typename T>\r\ntypename enable_if<has_read_method<T>::value,\
    \ void>::type rd(T &x) {\r\n  x.read();\r\n}\r\n\r\nvoid read() {}\r\ntemplate\
    \ <class H, class... T>\r\nvoid read(H &h, T &... t) {\r\n  rd(h), read(t...);\r\
    \n}\r\n\r\nvoid wt(const char c) {\r\n  if (obufi == BSZ) flush();\r\n  obuf[obufi++]\
    \ = c;\r\n}\r\nvoid wt(const string &s) {\r\n  for (char c: s) wt(c);\r\n}\r\n\
    void wt(const char *s) {\r\n  size_t len = strlen(s);\r\n  for (size_t i = 0;\
    \ i < len; i++) wt(s[i]);\r\n}\r\n\r\ntemplate <typename T>\r\nvoid wt_integer(T\
    \ x) {\r\n  if (obufi > BSZ - 100) flush();\r\n  if (x < 0) { obuf[obufi++] =\
    \ '-', x = -x; }\r\n  for (outi = 96; x >= 10000; outi -= 4) {\r\n    memcpy(out\
    \ + outi, pre.num[x % 10000], 4);\r\n    x /= 10000;\r\n  }\r\n  if (x >= 1000)\
    \ {\r\n    memcpy(obuf + obufi, pre.num[x], 4);\r\n    obufi += 4;\r\n  } else\
    \ if (x >= 100) {\r\n    memcpy(obuf + obufi, pre.num[x] + 1, 3);\r\n    obufi\
    \ += 3;\r\n  } else if (x >= 10) {\r\n    int q = (x * 103) >> 10;\r\n    obuf[obufi]\
    \ = q | '0';\r\n    obuf[obufi + 1] = (x - q * 10) | '0';\r\n    obufi += 2;\r\
    \n  } else\r\n    obuf[obufi++] = x | '0';\r\n  memcpy(obuf + obufi, out + outi\
    \ + 4, 96 - outi);\r\n  obufi += 96 - outi;\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvoid wt_real(T x) {\r\n  ostringstream oss;\r\n  oss << fixed << setprecision(15)\
    \ << double(x);\r\n  string s = oss.str();\r\n  wt(s);\r\n}\r\n\r\nvoid wt(bool\
    \ x) { wt_integer(int(x)); }\r\nvoid wt(int x) { wt_integer(x); }\r\nvoid wt(ll\
    \ x) { wt_integer(x); }\r\nvoid wt(i128 x) { wt_integer(x); }\r\nvoid wt(u32 x)\
    \ { wt_integer(x); }\r\nvoid wt(u64 x) { wt_integer(x); }\r\nvoid wt(u128 x) {\
    \ wt_integer(x); }\r\nvoid wt(double x) { wt_real(x); }\r\nvoid wt(long double\
    \ x) { wt_real(x); }\r\nvoid wt(f128 x) { wt_real(x); }\r\n\r\ntemplate <class\
    \ T, class U>\r\nvoid wt(const pair<T, U> val) {\r\n  wt(val.first);\r\n  wt('\
    \ ');\r\n  wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid\
    \ wt_tuple(const T t) {\r\n  if constexpr (N < std::tuple_size<T>::value) {\r\n\
    \    if constexpr (N > 0) { wt(' '); }\r\n    const auto x = std::get<N>(t);\r\
    \n    wt(x);\r\n    wt_tuple<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\
    \nvoid wt(tuple<T...> tpl) {\r\n  wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t\
    \ S>\r\nvoid wt(const array<T, S> val) {\r\n  auto n = val.size();\r\n  for (size_t\
    \ i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\
    \ntemplate <class T>\r\nvoid wt(const vector<T> val) {\r\n  auto n = val.size();\r\
    \n  for (size_t i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\
    \n  }\r\n}\r\n\r\ntemplate <typename T>\r\nstruct has_print_method {\r\n  template\
    \ <typename U>\r\n  static std::true_type test(decltype(&U::print) *);\r\n  template\
    \ <typename>\r\n  static std::false_type test(...);\r\n  using type = decltype(test<T>(nullptr));\r\
    \n  static constexpr bool value = type::value;\r\n};\r\n\r\ntemplate <typename\
    \ T>\r\ntypename enable_if<has_print_method<T>::value, void>::type wt(T x) {\r\
    \n  x.print();\r\n}\r\n\r\nvoid print() { wt('\\n'); }\r\ntemplate <class Head,\
    \ class... Tail>\r\nvoid print(Head &&head, Tail &&... tail) {\r\n  wt(head);\r\
    \n  if (sizeof...(Tail)) wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\
    \r\n// gcc expansion. called automaticall after main.\r\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\r\n} // namespace fastio\r\n\r\nusing fastio::read;\r\nusing\
    \ fastio::print;\r\nusing fastio::flush;\r\n\r\n#define INT(...)   \\\r\n  int\
    \ __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__;\
    \ \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n  string __VA_ARGS__;\
    \ \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)   \\\r\n  char __VA_ARGS__; \\\
    \r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n  double __VA_ARGS__; \\\
    \r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name, size) \\\r\n  vector<type>\
    \ name(size);    \\\r\n  read(name)\r\n#define VV(type, name, h, w)          \
    \           \\\r\n  vector<vector<type>> name(h, vector<type>(w)); \\\r\n  read(name)\r\
    \n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t\
    \ = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"Yes\" : \"No\"); }\r\
    \nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1) { print(t ? \"yes\"\
    \ : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\n#line 4 \"test/mytest/fenwick_raq.test.cpp\"\
    \n\n#line 2 \"ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename ActedMonoid>\n\
    struct Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n\
    \  using MA = typename AM::Monoid_A;\n  using X = typename MX::value_type;\n \
    \ using A = typename MA::value_type;\n  int n, log, size;\n  vc<X> dat;\n  vc<A>\
    \ laz;\n\n  Lazy_SegTree() {}\n  Lazy_SegTree(int n) { build(n); }\n  template\
    \ <typename F>\n  Lazy_SegTree(int n, F f) {\n    build(n, f);\n  }\n  Lazy_SegTree(const\
    \ vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m, [](int i) ->\
    \ X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\n  }\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size\
    \ = 1 << log;\n    dat.assign(size << 1, MX::unit());\n    laz.assign(size, MA::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  void update(int k) { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n  void\
    \ set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int\
    \ i = log; i >= 1; i--) push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i\
    \ <= log; i++) update(p >> i);\n  }\n  void multiply(int p, const X& x) {\n  \
    \  assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    dat[p] = MX::op(dat[p], x);\n    for (int i = 1; i <= log;\
    \ i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n\
    \    p += size;\n    for (int i = log; i >= 1; i--) push(p >> i);\n    return\
    \ dat[p];\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size) { push(k); }\n    return\
    \ {dat.begin() + size, dat.begin() + size + n};\n  }\n\n  X prod(int l, int r)\
    \ {\n    assert(0 <= l && l <= r && r <= n);\n    if (l == r) return MX::unit();\n\
    \    l += size, r += size;\n    for (int i = log; i >= 1; i--) {\n      if (((l\
    \ >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i) != r) push((r - 1)\
    \ >> i);\n    }\n    X xl = MX::unit(), xr = MX::unit();\n    while (l < r) {\n\
    \      if (l & 1) xl = MX::op(xl, dat[l++]);\n      if (r & 1) xr = MX::op(dat[--r],\
    \ xr);\n      l >>= 1, r >>= 1;\n    }\n    return MX::op(xl, xr);\n  }\n\n  X\
    \ prod_all() { return dat[1]; }\n\n  void apply(int l, int r, A a) {\n    assert(0\
    \ <= l && l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n\
    \    for (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l\
    \ >> i);\n      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    int\
    \ l2 = l, r2 = r;\n    while (l < r) {\n      if (l & 1) apply_at(l++, a);\n \
    \     if (r & 1) apply_at(--r, a);\n      l >>= 1, r >>= 1;\n    }\n    l = l2,\
    \ r = r2;\n    for (int i = 1; i <= log; i++) {\n      if (((l >> i) << i) !=\
    \ l) update(l >> i);\n      if (((r >> i) << i) != r) update((r - 1) >> i);\n\
    \    }\n  }\n\n  template <typename F>\n  int max_right(const F check, int l)\
    \ {\n    assert(0 <= l && l <= n);\n    assert(check(MX::unit()));\n    if (l\
    \ == n) return n;\n    l += size;\n    for (int i = log; i >= 1; i--) push(l >>\
    \ i);\n    X sm = MX::unit();\n    do {\n      while (l % 2 == 0) l >>= 1;\n \
    \     if (!check(MX::op(sm, dat[l]))) {\n        while (l < size) {\n        \
    \  push(l);\n          l = (2 * l);\n          if (check(MX::op(sm, dat[l])))\
    \ { sm = MX::op(sm, dat[l++]); }\n        }\n        return l - size;\n      }\n\
    \      sm = MX::op(sm, dat[l++]);\n    } while ((l & -l) != l);\n    return n;\n\
    \  }\n\n  template <typename F>\n  int min_left(const F check, int r) {\n    assert(0\
    \ <= r && r <= n);\n    assert(check(MX::unit()));\n    if (r == 0) return 0;\n\
    \    r += size;\n    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X\
    \ sm = MX::unit();\n    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>=\
    \ 1;\n      if (!check(MX::op(dat[r], sm))) {\n        while (r < size) {\n  \
    \        push(r);\n          r = (2 * r + 1);\n          if (check(MX::op(dat[r],\
    \ sm))) { sm = MX::op(dat[r--], sm); }\n        }\n        return r + 1 - size;\n\
    \      }\n      sm = MX::op(dat[r], sm);\n    } while ((r & -r) != r);\n    return\
    \ 0;\n  }\n\nprivate:\n  void apply_at(int k, A a) {\n    ll sz = 1 << (log -\
    \ topbit(k));\n    dat[k] = AM::act(dat[k], a, sz);\n    if (k < size) laz[k]\
    \ = MA::op(laz[k], a);\n  }\n  void push(int k) {\n    if (laz[k] == MA::unit())\
    \ return;\n    apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::unit();\n  }\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename\
    \ X>\r\nstruct Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"alg/acted_monoid/sum_add.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct ActedMonoid_Sum_Add {\r\n  using Monoid_X\
    \ = Monoid_Add<E>;\r\n  using Monoid_A = Monoid_Add<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return x +\
    \ a * E(size);\r\n  }\r\n};\r\n#line 1 \"ds/fenwicktree/fenwicktree_range_add.hpp\"\
    \n\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename Monoid>\n\
    struct FenwickTree {\n  using G = Monoid;\n  using E = typename G::value_type;\n\
    \  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() {}\n  FenwickTree(int\
    \ n) { build(n); }\n  template <typename F>\n  FenwickTree(int n, F f) {\n   \
    \ build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    n = m;\n    dat.assign(m, G::unit());\n    total = G::unit();\n  }\n\
    \  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m;\n\
    \    dat.clear();\n    dat.reserve(n);\n    total = G::unit();\n    FOR(i, n)\
    \ { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int j = i + (i\
    \ & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j - 1]);\n    }\n\
    \    total = prefix_sum(m);\n  }\n\n  E prod_all() { return total; }\n  E sum_all()\
    \ { return total; }\n  E sum(int k) { return prefix_sum(k); }\n  E prod(int k)\
    \ { return prefix_prod(k); }\n  E prefix_sum(int k) { return prefix_prod(k); }\n\
    \  E prefix_prod(int k) {\n    chmin(k, n);\n    E ret = G::unit();\n    for (;\
    \ k > 0; k -= k & -k) ret = G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E\
    \ sum(int L, int R) { return prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L,\
    \ 0), chmin(R, n);\n    if (L == 0) return prefix_prod(R);\n    assert(0 <= L\
    \ && L <= R && R <= n);\n    E pos = G::unit(), neg = G::unit();\n    while (L\
    \ < R) { pos = G::op(pos, dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg\
    \ = G::op(neg, dat[L - 1]), L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check) {\n    assert(check(G::unit()));\n    int\
    \ i = 0;\n    E s = G::unit();\n    int k = 1;\n    while (2 * k <= n) k *= 2;\n\
    \    while (k) {\n      if (i + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i\
    \ + k - 1]);\n        if (check(t)) { i += k, s = t; }\n      }\n      k >>= 1;\n\
    \    }\n    return i;\n  }\n\n  // check(i, x)\n  template <class F>\n  int max_right_with_index(const\
    \ F check) {\n    assert(check(0, G::unit()));\n    int i = 0;\n    E s = G::unit();\n\
    \    int k = 1;\n    while (2 * k <= n) k *= 2;\n    while (k) {\n      if (i\
    \ + k - 1 < len(dat)) {\n        E t = G::op(s, dat[i + k - 1]);\n        if (check(i\
    \ + k, t)) { i += k, s = t; }\n      }\n      k >>= 1;\n    }\n    return i;\n\
    \  }\n\n  int kth(E k) {\n    return max_right([&k](E x) -> bool { return x <=\
    \ k; });\n  }\n};\n#line 3 \"ds/fenwicktree/fenwicktree_range_add.hpp\"\n\n//\
    \ \u9045\u5EF6\u30BB\u30B0\u6728\u3088\u308A 4 \uFF5E 5 \u500D\u9AD8\u901F\uFF1F\
    \n// https://maspypy.github.io/library/test/mytest/fenwick_raq.test.cpp\n// https://codeforces.com/contest/860/submission/228355081\n\
    template <typename AbelGroup>\nstruct FenwickTree_Range_Add {\n  using G = AbelGroup;\n\
    \  using E = typename AbelGroup::value_type;\n  int n;\n  FenwickTree<G> bit0;\n\
    \  FenwickTree<G> bit1;\n\n  FenwickTree_Range_Add() {}\n  FenwickTree_Range_Add(int\
    \ n) { build(n); }\n  template <typename F>\n  FenwickTree_Range_Add(int n, F\
    \ f) {\n    build(n, f);\n  }\n  FenwickTree_Range_Add(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    bit0.build(n), bit1.build(n);\n\
    \  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i) -> E { return\
    \ v[i]; });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n =\
    \ m;\n    bit0.build(m, f);\n    bit1.build(m);\n  }\n\n  void add_at(int i, E\
    \ val) { bit0.add(i, val); }\n\n  void add(int L, int R, E val) {\n    bit0.add(L,\
    \ G::power(val, -L));\n    bit0.add(R, G::power(val, R));\n    bit1.add(L, val);\n\
    \    bit1.add(R, G::inverse(val));\n  }\n\n  E prod(int L, int R) {\n    E prod_R\
    \ = G::op(G::power(bit1.prod(R), R), bit0.prod(R));\n    E prod_L = G::op(G::power(bit1.prod(L),\
    \ L), bit0.prod(L));\n    return G::op(G::inverse(prod_L), prod_R);\n  }\n};\n\
    #line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 9 \"test/mytest/fenwick_raq.test.cpp\"\
    \n\nvc<int> solve_seg(ll N, ll Q, vc<int> A, vc<tuple<int, int, int>> query) {\n\
    \  Lazy_SegTree<ActedMonoid_Sum_Add<int>> seg(A);\n  vc<int> ANS;\n  for (auto&\
    \ [L, R, x]: query) {\n    if (x == 0)\n      ANS.eb(seg.prod(L, R));\n    else\n\
    \      seg.apply(L, R, x);\n  }\n  return ANS;\n}\n\nvc<int> solve_bit(ll N, ll\
    \ Q, vc<int> A, vc<tuple<int, int, int>> query) {\n  FenwickTree_Range_Add<Monoid_Add<int>>\
    \ seg(A);\n  vc<int> ANS;\n  for (auto& [L, R, x]: query) {\n    if (x == 0)\n\
    \      ANS.eb(seg.prod(L, R));\n    else\n      seg.add(L, R, x);\n  }\n  return\
    \ ANS;\n}\n\nvoid test() {\n  ll N = 1 << 18, Q = 1 << 18;\n  vc<int> A(N);\n\
    \  FOR(i, N) A[i] = RNG(0, 100);\n  vc<tuple<int, int, int>> query;\n  FOR(Q)\
    \ {\n    int L = RNG(0, N), R = RNG(0, N);\n    if (L > R) swap(L, R);\n    ++R;\n\
    \    int t = RNG(0, 2);\n    int x = RNG(0, 100);\n    if (t == 1) x = 0;\n  \
    \  query.eb(L, R, x);\n  }\n  vc<int> ANS_1 = solve_seg(N, Q, A, query);\n  vc<int>\
    \ ANS_2 = solve_bit(N, Q, A, query);\n  assert(ANS_1 == ANS_2);\n\n  /*\n  int\
    \ a = clock();\n  FOR(100) solve_seg(N, Q, A, query);\n  int b = clock();\n  FOR(100)\
    \ solve_bit(N, Q, A, query);\n  int c = clock();\n  print(b - a, c - b);\n  print(double(b\
    \ - a) / double(c - b));\n  4.4 \u500D\u304F\u3089\u3044\u9AD8\u901F\u3068\u3044\
    \u3046\u3053\u3068\u306B\n  */\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a +\
    \ b);\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"ds/segtree/lazy_segtree.hpp\"\n#include\
    \ \"alg/acted_monoid/sum_add.hpp\"\n#include \"ds/fenwicktree/fenwicktree_range_add.hpp\"\
    \n#include \"random/base.hpp\"\n\nvc<int> solve_seg(ll N, ll Q, vc<int> A, vc<tuple<int,\
    \ int, int>> query) {\n  Lazy_SegTree<ActedMonoid_Sum_Add<int>> seg(A);\n  vc<int>\
    \ ANS;\n  for (auto& [L, R, x]: query) {\n    if (x == 0)\n      ANS.eb(seg.prod(L,\
    \ R));\n    else\n      seg.apply(L, R, x);\n  }\n  return ANS;\n}\n\nvc<int>\
    \ solve_bit(ll N, ll Q, vc<int> A, vc<tuple<int, int, int>> query) {\n  FenwickTree_Range_Add<Monoid_Add<int>>\
    \ seg(A);\n  vc<int> ANS;\n  for (auto& [L, R, x]: query) {\n    if (x == 0)\n\
    \      ANS.eb(seg.prod(L, R));\n    else\n      seg.add(L, R, x);\n  }\n  return\
    \ ANS;\n}\n\nvoid test() {\n  ll N = 1 << 18, Q = 1 << 18;\n  vc<int> A(N);\n\
    \  FOR(i, N) A[i] = RNG(0, 100);\n  vc<tuple<int, int, int>> query;\n  FOR(Q)\
    \ {\n    int L = RNG(0, N), R = RNG(0, N);\n    if (L > R) swap(L, R);\n    ++R;\n\
    \    int t = RNG(0, 2);\n    int x = RNG(0, 100);\n    if (t == 1) x = 0;\n  \
    \  query.eb(L, R, x);\n  }\n  vc<int> ANS_1 = solve_seg(N, Q, A, query);\n  vc<int>\
    \ ANS_2 = solve_bit(N, Q, A, query);\n  assert(ANS_1 == ANS_2);\n\n  /*\n  int\
    \ a = clock();\n  FOR(100) solve_seg(N, Q, A, query);\n  int b = clock();\n  FOR(100)\
    \ solve_bit(N, Q, A, query);\n  int c = clock();\n  print(b - a, c - b);\n  print(double(b\
    \ - a) / double(c - b));\n  4.4 \u500D\u304F\u3089\u3044\u9AD8\u901F\u3068\u3044\
    \u3046\u3053\u3068\u306B\n  */\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a +\
    \ b);\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree/lazy_segtree.hpp
  - alg/acted_monoid/sum_add.hpp
  - alg/monoid/add.hpp
  - ds/fenwicktree/fenwicktree_range_add.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/fenwick_raq.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 16:40:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/fenwick_raq.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/fenwick_raq.test.cpp
- /verify/test/mytest/fenwick_raq.test.cpp.html
title: test/mytest/fenwick_raq.test.cpp
---
