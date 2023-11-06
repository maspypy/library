---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: ds/fenwicktree/fenwicktree_2d.hpp
    title: ds/fenwicktree/fenwicktree_2d.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\r\
    \n\r\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \ <unistd.h>\r\n#include <sys/mman.h>\r\n#include <sys/stat.h>\r\n\r\nnamespace\
    \ fastio {\r\n// https://judge.yosupo.jp/submission/21623\r\n// https://judge.yosupo.jp/submission/70667\r\
    \n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr Pre() : num() {\r\n\
    \    for (int i = 0; i < 10000; i++) {\r\n      int n = i;\r\n      for (int j\
    \ = 3; j >= 0; j--) {\r\n        num[i][j] = n % 10 | '0';\r\n        n /= 10;\r\
    \n      }\r\n    }\r\n  }\r\n} constexpr pre;\r\n\r\nconstexpr int BSZ = 1 <<\
    \ 19;\r\nchar *ibuf, obuf[BSZ], out[100];\r\nint outi, obufi;\r\n\r\n// gcc expansion.\
    \ called automaticall before main.\r\nvoid __attribute__((constructor)) _c() {\r\
    \n  struct stat sb;\r\n  fstat(0, &sb);\r\n  ibuf\r\n      = (char *)mmap(0, sb.st_size,\
    \ PROT_READ, MAP_SHARED | MAP_POPULATE, 0, 0);\r\n}\r\n\r\nvoid flush() {\r\n\
    \  assert(write(1, obuf, obufi) == obufi);\r\n  obufi = 0;\r\n}\r\n\r\nvoid rd(char\
    \ &c) { c = *ibuf++; }\r\nvoid rd(string &x) {\r\n  x.clear();\r\n  char c;\r\n\
    \  do { rd(c); } while (isspace(c));\r\n  do { x += c, rd(c); } while (!isspace(c));\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid rd_integer(T &x) {\r\n  char c;\r\n \
    \ do\r\n    rd(c);\r\n  while (c < '-');\r\n  bool minus = 0;\r\n  if constexpr\
    \ (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (c == '-') { minus =\
    \ 1, rd(c); }\r\n  }\r\n  x = 0;\r\n  while (c >= '0') { x = x * 10 + (c & 15),\
    \ rd(c); }\r\n  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n\
    \    if (minus) x = -x;\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T\
    \ &x) {\r\n  string s;\r\n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nstruct has_read_method {\r\n  template <typename U>\r\n  static std::true_type\
    \ test(decltype(&U::read) *);\r\n  template <typename>\r\n  static std::false_type\
    \ test(...);\r\n  using type = decltype(test<T>(nullptr));\r\n  static constexpr\
    \ bool value = type::value;\r\n};\r\n\r\ntemplate <typename T>\r\ntypename enable_if<has_read_method<T>::value,\
    \ void>::type rd(T &x) {\r\n  x.read();\r\n}\r\n\r\nvoid rd(int &x) { rd_integer(x);\
    \ }\r\nvoid rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128 &x) { rd_integer(x);\
    \ }\r\nvoid rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64 &x) { rd_integer(x);\
    \ }\r\nvoid rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double &x) { rd_real(x);\
    \ }\r\nvoid rd(long double &x) { rd_real(x); }\r\nvoid rd(f128 &x) { rd_real(x);\
    \ }\r\ntemplate <class T, class U>\r\nvoid rd(pair<T, U> &p) {\r\n  return rd(p.first),\
    \ rd(p.second);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd_tuple(T\
    \ &t) {\r\n  if constexpr (N < std::tuple_size<T>::value) {\r\n    auto &x = std::get<N>(t);\r\
    \n    rd(x);\r\n    rd_tuple<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\
    \nvoid rd(tuple<T...> &tpl) {\r\n  rd_tuple(tpl);\r\n}\r\ntemplate <class T>\r\
    \nvoid rd(vc<T> &x) {\r\n  for (auto &d: x) rd(d);\r\n}\r\ntemplate <size_t N\
    \ = 0, typename T>\r\nvoid rd(array<T, N> &x) {\r\n  for (auto &d: x) rd(d);\r\
    \n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class... T>\r\nvoid read(H &h,\
    \ T &... t) {\r\n  rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const char c) {\r\n\
    \  if (obufi == BSZ) flush();\r\n  obuf[obufi++] = c;\r\n}\r\nvoid wt(const string\
    \ &s) {\r\n  for (char c: s) wt(c);\r\n}\r\nvoid wt(const char *s) {\r\n  size_t\
    \ len = strlen(s);\r\n  for (size_t i = 0; i < len; i++) wt(s[i]);\r\n}\r\n\r\n\
    template <typename T>\r\nvoid wt_integer(T x) {\r\n  if (obufi > BSZ - 100) flush();\r\
    \n  if (x < 0) { obuf[obufi++] = '-', x = -x; }\r\n  for (outi = 96; x >= 10000;\
    \ outi -= 4) {\r\n    memcpy(out + outi, pre.num[x % 10000], 4);\r\n    x /= 10000;\r\
    \n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf + obufi, pre.num[x], 4);\r\n  \
    \  obufi += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf + obufi, pre.num[x]\
    \ + 1, 3);\r\n    obufi += 3;\r\n  } else if (x >= 10) {\r\n    int q = (x * 103)\
    \ >> 10;\r\n    obuf[obufi] = q | '0';\r\n    obuf[obufi + 1] = (x - q * 10) |\
    \ '0';\r\n    obufi += 2;\r\n  } else\r\n    obuf[obufi++] = x | '0';\r\n  memcpy(obuf\
    \ + obufi, out + outi + 4, 96 - outi);\r\n  obufi += 96 - outi;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvoid wt_real(T x) {\r\n  ostringstream oss;\r\n  oss << fixed\
    \ << setprecision(15) << double(x);\r\n  string s = oss.str();\r\n  wt(s);\r\n\
    }\r\n\r\ntemplate <typename T>\r\nstruct has_print_method {\r\n  template <typename\
    \ U>\r\n  static std::true_type test(decltype(&U::print) *);\r\n  template <typename>\r\
    \n  static std::false_type test(...);\r\n  using type = decltype(test<T>(nullptr));\r\
    \n  static constexpr bool value = type::value;\r\n};\r\n\r\ntemplate <typename\
    \ T>\r\ntypename enable_if<has_print_method<T>::value, void>::type wt(T x) {\r\
    \n  x.print();\r\n}\r\n\r\nvoid wt(bool x) { wt_integer(int(x)); }\r\nvoid wt(int\
    \ x) { wt_integer(x); }\r\nvoid wt(ll x) { wt_integer(x); }\r\nvoid wt(i128 x)\
    \ { wt_integer(x); }\r\nvoid wt(u32 x) { wt_integer(x); }\r\nvoid wt(u64 x) {\
    \ wt_integer(x); }\r\nvoid wt(u128 x) { wt_integer(x); }\r\nvoid wt(double x)\
    \ { wt_real(x); }\r\nvoid wt(long double x) { wt_real(x); }\r\nvoid wt(f128 x)\
    \ { wt_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid wt(const pair<T,\
    \ U> val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n  wt(val.second);\r\n}\r\ntemplate\
    \ <size_t N = 0, typename T>\r\nvoid wt_tuple(const T t) {\r\n  if constexpr (N\
    \ < std::tuple_size<T>::value) {\r\n    if constexpr (N > 0) { wt(' '); }\r\n\
    \    const auto x = std::get<N>(t);\r\n    wt(x);\r\n    wt_tuple<N + 1>(t);\r\
    \n  }\r\n}\r\ntemplate <class... T>\r\nvoid wt(tuple<T...> tpl) {\r\n  wt_tuple(tpl);\r\
    \n}\r\ntemplate <class T, size_t S>\r\nvoid wt(const array<T, S> val) {\r\n  auto\
    \ n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\
    \n    wt(val[i]);\r\n  }\r\n}\r\ntemplate <class T>\r\nvoid wt(const vector<T>\
    \ val) {\r\n  auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n \
    \   if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\nvoid print() { wt('\\\
    n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&... tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail)) wt(' ');\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n\r\n// gcc expansion. called automaticall after main.\r\nvoid __attribute__((destructor))\
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
    \ : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\n#line 5 \"test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp\"\
    \n\r\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct Monoid_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ X(n) * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"ds/fenwicktree/fenwicktree_2d.hpp\"\n\
    \r\ntemplate <typename Monoid, typename XY, bool SMALL_X = false>\r\nstruct FenwickTree_2D\
    \ {\r\n  using G = Monoid;\r\n  using E = typename G::value_type;\r\n  static_assert(G::commute);\r\
    \n  int N;\r\n  vc<XY> keyX;\r\n  XY min_X;\r\n  vc<int> indptr;\r\n  vc<XY> keyY;\r\
    \n  vc<E> dat;\r\n\r\n  FenwickTree_2D(vc<XY>& X, vc<XY>& Y, vc<E> wt) { build(X,\
    \ Y, wt); }\r\n  FenwickTree_2D(vc<XY>& X, vc<XY>& Y) {\r\n    vc<E> wt(len(X),\
    \ G::unit());\r\n    build(X, Y, wt);\r\n  }\r\n\r\n  inline int xtoi(XY x) {\r\
    \n    return (SMALL_X ? clamp<int>(x - min_X, 0, N) : LB(keyX, x));\r\n  }\r\n\
    \  inline int nxt(int i) { return i + ((i + 1) & -(i + 1)); }\r\n  inline int\
    \ prev(int i) { return i - ((i + 1) & -(i + 1)); }\r\n\r\n  void build(vc<XY>&\
    \ X, vc<XY>& Y, vc<E> wt) {\r\n    assert(len(X) == len(Y) && len(X) == len(wt));\r\
    \n    if (!SMALL_X) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\n      N = len(keyX);\r\
    \n    } else {\r\n      min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X)\
    \ == 0 ? 0 : MAX(X)) - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N)\
    \ keyX[i] = min_X + i;\r\n    }\r\n    vvc<XY> keyY_raw(N);\r\n    vvc<E> dat_raw(N);\r\
    \n    for (auto&& i: argsort(Y)) {\r\n      int ix = xtoi(X[i]);\r\n      XY y\
    \ = Y[i];\r\n      while (ix < N) {\r\n        auto& KY = keyY_raw[ix];\r\n  \
    \      if (len(KY) == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n       \
    \   dat_raw[ix].eb(wt[i]);\r\n        } else {\r\n          dat_raw[ix].back()\
    \ = G::op(dat_raw[ix].back(), wt[i]);\r\n        }\r\n        ix = nxt(ix);\r\n\
    \      }\r\n    }\r\n\r\n    indptr.assign(N + 1, 0);\r\n    FOR(i, N) indptr[i\
    \ + 1] = indptr[i] + len(keyY_raw[i]);\r\n    keyY.resize(indptr.back());\r\n\
    \    dat.resize(indptr.back());\r\n    FOR(i, N) FOR(j, indptr[i + 1] - indptr[i])\
    \ {\r\n      keyY[indptr[i] + j] = keyY_raw[i][j];\r\n      dat[indptr[i] + j]\
    \ = dat_raw[i][j];\r\n    }\r\n    FOR(i, N) {\r\n      int n = indptr[i + 1]\
    \ - indptr[i];\r\n      FOR(j, n - 1) {\r\n        int k = nxt(j);\r\n       \
    \ if (k < n)\r\n          dat[indptr[i] + k] = G::op(dat[indptr[i] + k], dat[indptr[i]\
    \ + j]);\r\n      }\r\n    }\r\n  }\r\n\r\n  void add(XY x, XY y, E val) { multiply(x,\
    \ y, val); }\r\n  void multiply(XY x, XY y, E val) {\r\n    int i = xtoi(x);\r\
    \n    assert(keyX[i] == x);\r\n    while (i < N) { multiply_i(i, y, val), i =\
    \ nxt(i); }\r\n  }\r\n\r\n  E sum(XY lx, XY rx, XY ly, XY ry) { return prod(lx,\
    \ rx, ly, ry); }\r\n  E prod(XY lx, XY rx, XY ly, XY ry) {\r\n    E pos = G::unit(),\
    \ neg = G::unit();\r\n    int L = xtoi(lx) - 1, R = xtoi(rx) - 1;\r\n    while\
    \ (L < R) { pos = G::op(pos, prod_i(R, ly, ry)), R = prev(R); }\r\n    while (R\
    \ < L) { neg = G::op(neg, prod_i(L, ly, ry)), L = prev(L); }\r\n    return G::op(pos,\
    \ G::inverse(neg));\r\n  }\r\n\r\n  E prefix_sum(XY rx, XY ry) { return prefix_prod(rx,\
    \ ry); }\r\n  E prefix_prod(XY rx, XY ry) {\r\n    E pos = G::unit();\r\n    int\
    \ R = xtoi(rx) - 1;\r\n    while (R >= 0) { pos = G::op(pos, prefix_prod_i(R,\
    \ ry)), R = prev(R); }\r\n    return pos;\r\n  }\r\n\r\nprivate:\r\n  void multiply_i(int\
    \ i, XY y, E val) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n    auto it = keyY.begin() + LID;\r\n    int j = lower_bound(it, it + n, y)\
    \ - it;\r\n    while (j < n) { dat[LID + j] = G::op(dat[LID + j], val), j = nxt(j);\
    \ }\r\n  }\r\n\r\n  E prod_i(int i, XY ly, XY ry) {\r\n    E pos = G::unit(),\
    \ neg = G::unit();\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it, it + n, ly)\
    \ - it - 1;\r\n    int R = lower_bound(it, it + n, ry) - it - 1;\r\n    while\
    \ (L < R) { pos = G::op(pos, dat[LID + R]), R = prev(R); }\r\n    while (R < L)\
    \ { neg = G::op(neg, dat[LID + L]), L = prev(L); }\r\n    return G::op(pos, G::inverse(neg));\r\
    \n  }\r\n\r\n  E prefix_prod_i(int i, XY ry) {\r\n    E pos = G::unit();\r\n \
    \   int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin()\
    \ + LID;\r\n    int R = lower_bound(it, it + n, ry) - it - 1;\r\n    while (R\
    \ >= 0) { pos = G::op(pos, dat[LID + R]), R = prev(R); }\r\n    return pos;\r\n\
    \  }\r\n};\r\n#line 7 \"test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  vi X(N), Y(N), W(N);\r\n  FOR(i, N) {\r\
    \n    LL(x, y, w);\r\n    X[i] = x, Y[i] = y, W[i] = w;\r\n  }\r\n  using QQ =\
    \ tuple<ll, ll, ll, ll>;\r\n  vc<QQ> query(Q);\r\n  FOR(q, Q) {\r\n    LL(t);\r\
    \n    if (t == 0) {\r\n      LL(x, y, w);\r\n      X.eb(x);\r\n      Y.eb(y);\r\
    \n      W.eb(0);\r\n      query[q] = mt(-1, x, y, w);\r\n    } else {\r\n    \
    \  LL(a, b, c, d);\r\n      query[q] = mt(a, c, b, d);\r\n    }\r\n  }\r\n\r\n\
    \  FenwickTree_2D<Monoid_Add<ll>, ll, false> bit(X, Y, W);\r\n  FOR(q, Q) {\r\n\
    \    auto [a, b, c, d] = query[q];\r\n    if (a == -1) {\r\n      bit.add(b, c,\
    \ d);\r\n    } else {\r\n      print(bit.prod(a, b, c, d));\r\n    }\r\n  }\r\n\
    }\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\n  ios::sync_with_stdio(false);\r\
    \n  cout << setprecision(15);\r\n\r\n  solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \r\n\r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n\r\n#include\
    \ \"ds/fenwicktree/fenwicktree_2d.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N, Q);\r\
    \n  vi X(N), Y(N), W(N);\r\n  FOR(i, N) {\r\n    LL(x, y, w);\r\n    X[i] = x,\
    \ Y[i] = y, W[i] = w;\r\n  }\r\n  using QQ = tuple<ll, ll, ll, ll>;\r\n  vc<QQ>\
    \ query(Q);\r\n  FOR(q, Q) {\r\n    LL(t);\r\n    if (t == 0) {\r\n      LL(x,\
    \ y, w);\r\n      X.eb(x);\r\n      Y.eb(y);\r\n      W.eb(0);\r\n      query[q]\
    \ = mt(-1, x, y, w);\r\n    } else {\r\n      LL(a, b, c, d);\r\n      query[q]\
    \ = mt(a, c, b, d);\r\n    }\r\n  }\r\n\r\n  FenwickTree_2D<Monoid_Add<ll>, ll,\
    \ false> bit(X, Y, W);\r\n  FOR(q, Q) {\r\n    auto [a, b, c, d] = query[q];\r\
    \n    if (a == -1) {\r\n      bit.add(b, c, d);\r\n    } else {\r\n      print(bit.prod(a,\
    \ b, c, d));\r\n    }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  cin.tie(nullptr);\r\
    \n  ios::sync_with_stdio(false);\r\n  cout << setprecision(15);\r\n\r\n  solve();\r\
    \n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/fenwicktree/fenwicktree_2d.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 17:27:58+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp.html
title: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
---
