---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convex/minplus_convolution.hpp
    title: convex/minplus_convolution.hpp
  - icon: ':x:'
    path: convex/monotone_minima.hpp
    title: convex/monotone_minima.hpp
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
  bundledCode: "#line 1 \"test/mytest/minplus_convex.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n\
    #include <my_template_compiled.hpp>\n#else\n#pragma GCC optimize(\"Ofast\")\n\
    #pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned\
    \ long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll> = ll(infty<int>)\
    \ * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate\
    \ <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128>\
    \ = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr double infty<double>\
    \ = infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>>\
    \ name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define\
    \ vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \r\ntemplate <typename T>\r\nvoid wt_integer(T x) {\r\n  if (obufi > BSZ - 100)\
    \ flush();\r\n  if (x < 0) { obuf[obufi++] = '-', x = -x; }\r\n  for (outi = 96;\
    \ x >= 10000; outi -= 4) {\r\n    memcpy(out + outi, pre.num[x % 10000], 4);\r\
    \n    x /= 10000;\r\n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf + obufi, pre.num[x],\
    \ 4);\r\n    obufi += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf + obufi,\
    \ pre.num[x] + 1, 3);\r\n    obufi += 3;\r\n  } else if (x >= 10) {\r\n    int\
    \ q = (x * 103) >> 10;\r\n    obuf[obufi] = q | '0';\r\n    obuf[obufi + 1] =\
    \ (x - q * 10) | '0';\r\n    obufi += 2;\r\n  } else\r\n    obuf[obufi++] = x\
    \ | '0';\r\n  memcpy(obuf + obufi, out + outi + 4, 96 - outi);\r\n  obufi += 96\
    \ - outi;\r\n}\r\n\r\ntemplate <typename T>\r\nvoid wt_real(T x) {\r\n  ostringstream\
    \ oss;\r\n  oss << fixed << setprecision(15) << double(x);\r\n  string s = oss.str();\r\
    \n  wt(s);\r\n}\r\n\r\nvoid wt(bool x) { wt_integer(int(x)); }\r\nvoid wt(int\
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
    \   if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\ntemplate <typename T>\r\
    \nstruct has_print_method {\r\n  template <typename U>\r\n  static std::true_type\
    \ test(decltype(&U::print) *);\r\n  template <typename>\r\n  static std::false_type\
    \ test(...);\r\n  using type = decltype(test<T>(nullptr));\r\n  static constexpr\
    \ bool value = type::value;\r\n};\r\n\r\ntemplate <typename T>\r\ntypename enable_if<has_print_method<T>::value,\
    \ void>::type wt(T x) {\r\n  x.print();\r\n}\r\n\r\nvoid print() { wt('\\n');\
    \ }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail &&...\
    \ tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail)) wt(' ');\r\n  print(forward<Tail>(tail)...);\r\
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
    \ : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 1 \"convex/monotone_minima.hpp\"\
    \n\n// select(i,j,k) : (i,j) -> (i,k) \u3092\u884C\u3046\u304B\u3069\u3046\u304B\
    \ntemplate <typename F>\nvc<int> monotone_minima(int H, int W, F select) {\n \
    \ vc<int> min_col(H);\n  auto dfs = [&](auto& dfs, int x1, int x2, int y1, int\
    \ y2) -> void {\n    if (x1 == x2) return;\n    int x = (x1 + x2) / 2;\n    int\
    \ best_y = y1;\n    for (int y = y1 + 1; y < y2; ++y) {\n      if (select(x, best_y,\
    \ y)) best_y = y;\n    }\n    min_col[x] = best_y;\n    dfs(dfs, x1, x, y1, best_y\
    \ + 1);\n    dfs(dfs, x + 1, x2, best_y, y2);\n  };\n  dfs(dfs, 0, H, 0, W);\n\
    \  return min_col;\n}\n#line 2 \"convex/minplus_convolution.hpp\"\n\ntemplate\
    \ <typename T>\nvc<T> minplus_convolution_convex_convex(vc<T>& A, vc<T>& B) {\n\
    \  int n = len(A), m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n\
    \ + m - 1, infty<T>);\n  while (n > 0 && A[n - 1] == infty<T>) --n;\n  while (m\
    \ > 0 && B[m - 1] == infty<T>) --m;\n  if (n == 0 && m == 0) return C;\n  int\
    \ a = 0, b = 0;\n  while (a < n && A[a] == infty<T>) ++a;\n  while (b < m && B[b]\
    \ == infty<T>) ++b;\n  C[a + b] = A[a] + B[b];\n  for (int i = a + b + 1; i <\
    \ n + m - 1; ++i) {\n    if (b == m - 1 || (a != n - 1 && A[a + 1] + B[b] < A[a]\
    \ + B[b + 1])) {\n      chmin(C[i], A[++a] + B[b]);\n    } else {\n      chmin(C[i],\
    \ A[a] + B[++b]);\n    }\n  }\n  return C;\n}\n\ntemplate <typename T>\nvc<T>\
    \ minplus_convolution_arbitrary_convex(vc<T>& A, vc<T>& B) {\n  int n = len(A),\
    \ m = len(B);\n  if (n == 0 && m == 0) return {};\n  vc<T> C(n + m - 1, infty<T>);\n\
    \  while (m > 0 && B[m - 1] == infty<T>) --m;\n  if (m == 0) return C;\n  int\
    \ b = 0;\n  while (b < m && B[b] == infty<T>) ++b;\n\n  auto select = [&](int\
    \ i, int j, int k) -> bool {\n    if (i < k) return false;\n    if (i - j >= m\
    \ - b) return true;\n    return A[j] + B[b + i - j] >= A[k] + B[b + i - k];\n\
    \  };\n  vc<int> J = monotone_minima(n + m - b - 1, n, select);\n  FOR(i, n +\
    \ m - b - 1) {\n    T x = A[J[i]], y = B[b + i - J[i]];\n    if (x < infty<T>\
    \ && y < infty<T>) C[b + i] = x + y;\n  }\n  return C;\n}\n\ntemplate <typename\
    \ T, bool convA, bool convB>\nvc<T> minplus_convolution(vc<T>& A, vc<T>& B) {\n\
    \  static_assert(convA || convB);\n  if constexpr (convA && convB) return minplus_convolution_convex_convex(A,\
    \ B);\n  if constexpr (convA && !convB)\n    return minplus_convolution_arbitrary_convex(B,\
    \ A);\n  if constexpr (convB && !convA)\n    return minplus_convolution_arbitrary_convex(A,\
    \ B);\n  return {};\n}\n#line 6 \"test/mytest/minplus_convex.test.cpp\"\n\nvc<int>\
    \ gen(int L, int N, int R, bool convex) {\n  vc<int> A(N);\n  FOR(i, N) A[i] =\
    \ RNG(-100, 100);\n  if (!convex) return A;\n  sort(all(A));\n  A = cumsum<int>(A);\n\
    \  FOR(L) A.insert(A.begin(), infty<int>);\n  FOR(R) A.insert(A.end(), infty<int>);\n\
    \  return A;\n}\n\nvc<int> naive(vc<int> A, vc<int> B) {\n  int N = len(A), M\
    \ = len(B);\n  vc<int> C(N + M - 1, infty<int>);\n  FOR(i, N) FOR(j, M) {\n  \
    \  if (A[i] == infty<int> || B[j] == infty<int>) continue;\n    chmin(C[i + j],\
    \ A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1, 5) FOR(b1, 1,\
    \ 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1, true);\n    FOR(a2, 5) FOR(b2,\
    \ 1, 10) FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2, true);\n      vc<int>\
    \ C = minplus_convolution<int, 1, 1>(A, B);\n      assert(naive(A, B) == C);\n\
    \    }\n  }\n  FOR(a1, 5) FOR(b1, 1, 10) FOR(c1, 5) {\n    vc<int> A = gen(a1,\
    \ b1, c1, true);\n    FOR(a2, 5) FOR(b2, 1, 10) FOR(c2, 5) {\n      vc<int> B\
    \ = gen(a2, b2, c2, false);\n      vc<int> C = minplus_convolution<int, 1, false>(A,\
    \ B);\n      assert(naive(A, B) == C);\n    }\n  }\n}\n\nvoid solve() {\n  LL(a,\
    \ b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include \"convex/minplus_convolution.hpp\"\
    \n\nvc<int> gen(int L, int N, int R, bool convex) {\n  vc<int> A(N);\n  FOR(i,\
    \ N) A[i] = RNG(-100, 100);\n  if (!convex) return A;\n  sort(all(A));\n  A =\
    \ cumsum<int>(A);\n  FOR(L) A.insert(A.begin(), infty<int>);\n  FOR(R) A.insert(A.end(),\
    \ infty<int>);\n  return A;\n}\n\nvc<int> naive(vc<int> A, vc<int> B) {\n  int\
    \ N = len(A), M = len(B);\n  vc<int> C(N + M - 1, infty<int>);\n  FOR(i, N) FOR(j,\
    \ M) {\n    if (A[i] == infty<int> || B[j] == infty<int>) continue;\n    chmin(C[i\
    \ + j], A[i] + B[j]);\n  }\n  return C;\n}\n\nvoid test() {\n  FOR(a1, 5) FOR(b1,\
    \ 1, 10) FOR(c1, 5) {\n    vc<int> A = gen(a1, b1, c1, true);\n    FOR(a2, 5)\
    \ FOR(b2, 1, 10) FOR(c2, 5) {\n      vc<int> B = gen(a2, b2, c2, true);\n    \
    \  vc<int> C = minplus_convolution<int, 1, 1>(A, B);\n      assert(naive(A, B)\
    \ == C);\n    }\n  }\n  FOR(a1, 5) FOR(b1, 1, 10) FOR(c1, 5) {\n    vc<int> A\
    \ = gen(a1, b1, c1, true);\n    FOR(a2, 5) FOR(b2, 1, 10) FOR(c2, 5) {\n     \
    \ vc<int> B = gen(a2, b2, c2, false);\n      vc<int> C = minplus_convolution<int,\
    \ 1, false>(A, B);\n      assert(naive(A, B) == C);\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - convex/minplus_convolution.hpp
  - convex/monotone_minima.hpp
  isVerificationFile: true
  path: test/mytest/minplus_convex.test.cpp
  requiredBy: []
  timestamp: '2023-11-06 16:12:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/minplus_convex.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/minplus_convex.test.cpp
- /verify/test/mytest/minplus_convex.test.cpp.html
title: test/mytest/minplus_convex.test.cpp
---
