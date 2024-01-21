---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/dynamicupperhull.hpp
    title: geo/dynamicupperhull.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/convex_layers
    links:
    - https://judge.yosupo.jp/problem/convex_layers
  bundledCode: "#line 1 \"test/library_checker/geometry/convex_layers.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/convex_layers\"\r\n#line 1 \"\
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
    \ <unistd.h>\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\nnamespace fastio\
    \ {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\
    \nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil = 0, pir = 0, por\
    \ = 0;\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr Pre() : num()\
    \ {\r\n    for (int i = 0; i < 10000; i++) {\r\n      int n = i;\r\n      for\
    \ (int j = 3; j >= 0; j--) {\r\n        num[i][j] = n % 10 | '0';\r\n        n\
    \ /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline void load()\
    \ {\r\n  memcpy(ibuf, ibuf + pil, pir - pil);\r\n  pir = pir - pil + fread(ibuf\
    \ + pir - pil, 1, SZ - pir + pil, stdin);\r\n  pil = 0;\r\n  if (pir < SZ) ibuf[pir++]\
    \ = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(obuf, 1, por, stdout);\r\
    \n  por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n  do {\r\n    if (pil + 1 > pir)\
    \ load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\n}\r\n\r\nvoid\
    \ rd(string &x) {\r\n  x.clear();\r\n  char c;\r\n  do {\r\n    if (pil + 1 >\
    \ pir) load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\n  do {\r\n\
    \    x += c;\r\n    if (pil == pir) load();\r\n    c = ibuf[pil++];\r\n  } while\
    \ (!isspace(c));\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n\
    \  string s;\r\n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvoid rd_integer(T &x) {\r\n  if (pil + 100 > pir) load();\r\n  char c;\r\n \
    \ do\r\n    c = ibuf[pil++];\r\n  while (c < '-');\r\n  bool minus = 0;\r\n  if\
    \ constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (c == '-')\
    \ { minus = 1, c = ibuf[pil++]; }\r\n  }\r\n  x = 0;\r\n  while ('0' <= c) { x\
    \ = x * 10 + (c & 15), c = ibuf[pil++]; }\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (minus) x = -x;\r\n  }\r\n}\r\n\r\nvoid rd(int\
    \ &x) { rd_integer(x); }\r\nvoid rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128\
    \ &x) { rd_integer(x); }\r\nvoid rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64\
    \ &x) { rd_integer(x); }\r\nvoid rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double\
    \ &x) { rd_real(x); }\r\nvoid rd(long double &x) { rd_real(x); }\r\nvoid rd(f128\
    \ &x) { rd_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid rd(pair<T, U>\
    \ &p) {\r\n  return rd(p.first), rd(p.second);\r\n}\r\ntemplate <size_t N = 0,\
    \ typename T>\r\nvoid rd_tuple(T &t) {\r\n  if constexpr (N < std::tuple_size<T>::value)\
    \ {\r\n    auto &x = std::get<N>(t);\r\n    rd(x);\r\n    rd_tuple<N + 1>(t);\r\
    \n  }\r\n}\r\ntemplate <class... T>\r\nvoid rd(tuple<T...> &tpl) {\r\n  rd_tuple(tpl);\r\
    \n}\r\n\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd(array<T, N> &x) {\r\n\
    \  for (auto &d: x) rd(d);\r\n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\
    \n  for (auto &d: x) rd(d);\r\n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class...\
    \ T>\r\nvoid read(H &h, T &... t) {\r\n  rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const\
    \ char c) {\r\n  if (por == SZ) flush();\r\n  obuf[por++] = c;\r\n}\r\nvoid wt(const\
    \ string s) {\r\n  for (char c: s) wt(c);\r\n}\r\nvoid wt(const char *s) {\r\n\
    \  size_t len = strlen(s);\r\n  for (size_t i = 0; i < len; i++) wt(s[i]);\r\n\
    }\r\n\r\ntemplate <typename T>\r\nvoid wt_integer(T x) {\r\n  if (por > SZ - 100)\
    \ flush();\r\n  if (x < 0) { obuf[por++] = '-', x = -x; }\r\n  int outi;\r\n \
    \ for (outi = 96; x >= 10000; outi -= 4) {\r\n    memcpy(out + outi, pre.num[x\
    \ % 10000], 4);\r\n    x /= 10000;\r\n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf\
    \ + por, pre.num[x], 4);\r\n    por += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf\
    \ + por, pre.num[x] + 1, 3);\r\n    por += 3;\r\n  } else if (x >= 10) {\r\n \
    \   int q = (x * 103) >> 10;\r\n    obuf[por] = q | '0';\r\n    obuf[por + 1]\
    \ = (x - q * 10) | '0';\r\n    por += 2;\r\n  } else\r\n    obuf[por++] = x |\
    \ '0';\r\n  memcpy(obuf + por, out + outi + 4, 96 - outi);\r\n  por += 96 - outi;\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid wt_real(T x) {\r\n  ostringstream oss;\r\
    \n  oss << fixed << setprecision(15) << double(x);\r\n  string s = oss.str();\r\
    \n  wt(s);\r\n}\r\n\r\nvoid wt(int x) { wt_integer(x); }\r\nvoid wt(ll x) { wt_integer(x);\
    \ }\r\nvoid wt(i128 x) { wt_integer(x); }\r\nvoid wt(u32 x) { wt_integer(x); }\r\
    \nvoid wt(u64 x) { wt_integer(x); }\r\nvoid wt(u128 x) { wt_integer(x); }\r\n\
    void wt(double x) { wt_real(x); }\r\nvoid wt(long double x) { wt_real(x); }\r\n\
    void wt(f128 x) { wt_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid wt(const\
    \ pair<T, U> val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n  wt(val.second);\r\n\
    }\r\ntemplate <size_t N = 0, typename T>\r\nvoid wt_tuple(const T t) {\r\n  if\
    \ constexpr (N < std::tuple_size<T>::value) {\r\n    if constexpr (N > 0) { wt('\
    \ '); }\r\n    const auto x = std::get<N>(t);\r\n    wt(x);\r\n    wt_tuple<N\
    \ + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\nvoid wt(tuple<T...> tpl) {\r\
    \n  wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t S>\r\nvoid wt(const array<T,\
    \ S> val) {\r\n  auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n\
    \    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\ntemplate <class T>\r\n\
    void wt(const vector<T> val) {\r\n  auto n = val.size();\r\n  for (size_t i =\
    \ 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\
    \nvoid print() { wt('\\n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid\
    \ print(Head &&head, Tail &&... tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail))\
    \ wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\n// gcc expansion. called\
    \ automaticall after main.\r\nvoid __attribute__((destructor)) _d() { flush();\
    \ }\r\n} // namespace fastio\r\nusing fastio::read;\r\nusing fastio::print;\r\n\
    using fastio::flush;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n\
    \  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define U32(...)   \\\r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ U64(...)   \\\r\n  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)\
    \      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point\
    \ {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename\
    \ B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n\
    \  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const\
    \ { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x\
    \ - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x == p.x && y\
    \ == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y != p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n  Point operator*(T t) const\
    \ { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x / t, y\
    \ / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n\
    \    return y < p.y;\n  }\n  T dot(Point other) { return x * other.x + y * other.y;\
    \ }\n  T det(Point other) { return x * other.y - y * other.x; }\n\n  double norm()\
    \ { return sqrtl(x * x + y * y); }\n  double angle() { return atan2(y, x); }\n\
    \n  Point rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n\
    \    double c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s\
    \ * x + c * y};\n  }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>&\
    \ p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>&\
    \ p) {\n  fastio::wt(p.x);\n  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\
    \n// A -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\
    \u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n \
    \ T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if (x < 0) return -1;\n\
    \  return 0;\n}\n\ntemplate <typename REAL, typename T>\nREAL dist(Point<T> A,\
    \ Point<T> B) {\n  A = A - B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n}\n\
    \n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a,\
    \ T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y\
    \ - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T\
    \ x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename\
    \ U>\n  U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\n  template\
    \ <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n \
    \ // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\
    \u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n   \
    \ if (b == 0 && a < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  bool contain(Point<T> C) {\n    static_assert(is_integral<T>::value);\n\
    \    T det = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return (C -\
    \ A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() {\
    \ return Line(A, B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL>\
    \ O;\n  REAL r;\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL\
    \ x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n\ntemplate <typename T>\nstruct Polygon {\n  vc<Point<T>>\
    \ points;\n  T a;\n\n  template <typename A, typename B>\n  Polygon(vc<pair<A,\
    \ B>> pairs) {\n    for (auto&& [a, b]: pairs) points.eb(Point<T>(a, b));\n  \
    \  build();\n  }\n  Polygon(vc<Point<T>> points) : points(points) { build(); }\n\
    \n  int size() { return len(points); }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  T area_2() {\n    return a;\n  }\n\n  bool is_convex() {\n    FOR(j,\
    \ len(points)) {\n      int i = (j == 0 ? len(points) - 1 : j - 1);\n      int\
    \ k = (j == len(points) - 1 ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k]\
    \ - points[j]) < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n\
    \  void build() {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1\
    \ == len(points) ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n\
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n\
    #line 2 \"geo/dynamicupperhull.hpp\"\n\r\n/*\r\nhttps://codeforces.com/blog/entry/75929\r\
    \n\u52D5\u7684\u51F8\u5305\u3002\r\nx \u5EA7\u6A19\u3067\u30BD\u30FC\u30C8\u3057\
    \u3066\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u30BB\u30B0\u6728\u306E\u5F62\u306B\
    \u3057\u3066\u304A\u304F\u3002\r\n\u30BB\u30B0\u6728\u306E\u30DE\u30FC\u30B8\u90E8\
    \u5206\uFF08\u6B21\u306E bridge \u3092\u6C42\u3081\u308B\uFF09\u3067\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\u3002\r\nbridge \u540C\u58EB\u306E 4 \u70B9\u3067\u306E\
    \u4E0A\u5074\u51F8\u5305\u3092\u898B\u308C\u3070\u3001\u6B21\u306B\u63A2\u7D22\
    \u3059\u308B\u3079\u304D\u533A\u9593\u5BFE\u304C\u5206\u304B\u308B\u3002\r\n\r\
    \n\u69CB\u7BC9 O(NlogN)\u3001\u66F4\u65B0 O(Nlog^2N)\r\n\u5EA7\u6A19 10^9 \u4EE5\
    \u4E0B\u306E\u6574\u6570\u3092\u4EEE\u5B9A\r\n*/\r\ntemplate <typename Point>\r\
    \nstruct DynamicUpperHull {\r\n  struct node {\r\n    int l, r;   // \u7BC4\u56F2\
    \ (-1 if no vertex)\r\n    int bl, br; // bridge idx\r\n  };\r\n  int N, sz;\r\
    \n  vc<Point> P;\r\n  vc<node> seg;\r\n  // \u53D7\u3051\u53D6\u3063\u305F\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3068\u306E\u5BFE\u5FDC\r\n  vc<int> to_original_idx,\
    \ to_seg_idx;\r\n\r\n  DynamicUpperHull(vc<Point> P) : DynamicUpperHull(P, 0)\
    \ {}\r\n  DynamicUpperHull(vc<Point> P, bool b)\r\n      : DynamicUpperHull(P,\
    \ vc<bool>(len(P), b)) {}\r\n\r\n  DynamicUpperHull(vc<Point> _P, vc<bool> isin)\
    \ : N(len(_P)), P(_P) {\r\n    to_original_idx = argsort(P);\r\n    sort(all(P));\r\
    \n    sz = 1;\r\n    while (sz < N) sz *= 2;\r\n    to_seg_idx.resize(N);\r\n\
    \    seg.assign(sz + sz, {-1, -1, -1, -1});\r\n    for (int i = 0; i < N; ++i)\
    \ to_seg_idx[to_original_idx[i]] = i;\r\n    for (int i = 0; i < N; ++i)\r\n \
    \     if (isin[to_original_idx[i]]) { seg[sz + i] = {i, i + 1, i, i}; }\r\n  \
    \  FOR3_R(i, 1, sz) update(i);\r\n  }\r\n\r\n  void insert(int i) {\r\n    i =\
    \ to_seg_idx[i];\r\n    seg[sz + i] = {i, i + 1, i, i};\r\n    i = (sz + i) /\
    \ 2;\r\n    while (i) {\r\n      update(i);\r\n      i /= 2;\r\n    }\r\n  }\r\
    \n  void add(int i) { insert(i); }\r\n\r\n  void erase(int i) {\r\n    i = to_seg_idx[i];\r\
    \n    seg[sz + i] = {-1, -1, -1, -1};\r\n    i = (sz + i) / 2;\r\n    while (i)\
    \ {\r\n      update(i);\r\n      i /= 2;\r\n    }\r\n  }\r\n  void remove(int\
    \ i) { insert(i); }\r\n\r\n  inline bool exist(int i) { return seg[i].r != -1;\
    \ }\r\n\r\n  void update(int i) {\r\n    if (!exist(2 * i + 0) && !exist(2 * i\
    \ + 1)) {\r\n      seg[i].r = -1;\r\n      return;\r\n    }\r\n    if (!exist(2\
    \ * i + 0)) {\r\n      seg[i] = seg[2 * i + 1];\r\n      return;\r\n    }\r\n\
    \    if (!exist(2 * i + 1)) {\r\n      seg[i] = seg[2 * i + 0];\r\n      return;\r\
    \n    }\r\n    int p = 2 * i, q = 2 * i + 1;\r\n    ll X = P[seg[q].l].x;\r\n\
    \    while (p < sz || q < sz) {\r\n      if (p < sz && !exist(2 * p + 0)) {\r\n\
    \        p = 2 * p + 1;\r\n        continue;\r\n      }\r\n      if (p < sz &&\
    \ !exist(2 * p + 1)) {\r\n        p = 2 * p + 0;\r\n        continue;\r\n    \
    \  }\r\n      if (q < sz && !exist(2 * q + 0)) {\r\n        q = 2 * q + 1;\r\n\
    \        continue;\r\n      }\r\n      if (q < sz && !exist(2 * q + 1)) {\r\n\
    \        q = 2 * q + 0;\r\n        continue;\r\n      }\r\n      int a = seg[p].bl,\
    \ b = seg[p].br, c = seg[q].bl, d = seg[q].br;\r\n      if (a != b && (P[b] -\
    \ P[a]).det(P[c] - P[a]) > 0) p = p * 2 + 0;\r\n      elif (c != d && (P[c] -\
    \ P[b]).det(P[d] - P[b]) > 0) q = 2 * q + 1;\r\n      elif (a == b) q = 2 * q\
    \ + 0;\r\n      elif (c == d) p = 2 * p + 1;\r\n      else {\r\n        i128 c1\
    \ = (P[b] - P[a]).det(P[c] - P[a]);\r\n        i128 c2 = (P[a] - P[b]).det(P[d]\
    \ - P[b]);\r\n        if (c1 + c2 == 0 || c1 * P[d].x + c2 * P[c].x < X * (c1\
    \ + c2)) {\r\n          p = 2 * p + 1;\r\n        } else {\r\n          q = 2\
    \ * q + 0;\r\n        }\r\n      }\r\n    }\r\n    seg[i].l = seg[2 * i].l, seg[i].r\
    \ = seg[2 * i + 1].r;\r\n    seg[i].bl = seg[p].l, seg[i].br = seg[q].l;\r\n \
    \ }\r\n\r\n  vc<int> get() {\r\n    // output sensitive complexity\r\n    vc<int>\
    \ res;\r\n    auto dfs = [&](auto self, int k, int l, int r) -> void {\r\n   \
    \   if (!exist(k) || l >= r) return;\r\n      if (k >= sz) {\r\n        res.eb(seg[k].l);\r\
    \n        return;\r\n      }\r\n      if (!exist(2 * k + 0)) return self(self,\
    \ 2 * k + 1, l, r);\r\n      if (!exist(2 * k + 1)) return self(self, 2 * k +\
    \ 0, l, r);\r\n      if (r <= seg[k].bl) return self(self, 2 * k + 0, l, r);\r\
    \n      if (seg[k].br <= l) return self(self, 2 * k + 1, l, r);\r\n      self(self,\
    \ 2 * k + 0, l, seg[k].bl + 1);\r\n      self(self, 2 * k + 1, seg[k].br, r);\r\
    \n    };\r\n    dfs(dfs, 1, 0, N);\r\n    for (auto&& i: res) i = to_original_idx[i];\r\
    \n    return res;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"points\");\r\n\
    \    FOR(i, len(P)) print(i, P[i].x, P[i].y);\r\n    print(\"seg\");\r\n    FOR(i,\
    \ len(seg)) print(i, seg[i].l, seg[i].r, seg[i].bl, seg[i].br);\r\n    print(\"\
    get\");\r\n    print(get());\r\n  }\r\n};\r\n#line 5 \"test/library_checker/geometry/convex_layers.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N);\r\n  vc<Point<ll>> pts(N);\r\n  FOR(i, N) read(pts[i].x),\
    \ read(pts[i].y);\r\n  DynamicUpperHull DUH(pts, 1);\r\n  FOR(i, N) pts[i] = -pts[i];\r\
    \n  DynamicUpperHull DLH(pts, 1);\r\n  vc<int> ANS(N, -1);\r\n  int done = 0;\r\
    \n  int k = 0;\r\n  while (done < N) {\r\n    ++k;\r\n    auto A = DUH.get();\r\
    \n    auto B = DLH.get();\r\n    A.insert(A.end(), all(B));\r\n    for (auto&&\
    \ i: A)\r\n      if (ANS[i] == -1) {\r\n        ++done;\r\n        ANS[i] = k;\r\
    \n        DUH.erase(i);\r\n        DLH.erase(i);\r\n      }\r\n  }\r\n  for (auto&&\
    \ x: ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return\
    \ 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convex_layers\"\r\n#include\
    \ \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"geo/dynamicupperhull.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N);\r\n  vc<Point<ll>> pts(N);\r\n  FOR(i, N) read(pts[i].x),\
    \ read(pts[i].y);\r\n  DynamicUpperHull DUH(pts, 1);\r\n  FOR(i, N) pts[i] = -pts[i];\r\
    \n  DynamicUpperHull DLH(pts, 1);\r\n  vc<int> ANS(N, -1);\r\n  int done = 0;\r\
    \n  int k = 0;\r\n  while (done < N) {\r\n    ++k;\r\n    auto A = DUH.get();\r\
    \n    auto B = DLH.get();\r\n    A.insert(A.end(), all(B));\r\n    for (auto&&\
    \ i: A)\r\n      if (ANS[i] == -1) {\r\n        ++done;\r\n        ANS[i] = k;\r\
    \n        DUH.erase(i);\r\n        DLH.erase(i);\r\n      }\r\n  }\r\n  for (auto&&\
    \ x: ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - geo/dynamicupperhull.hpp
  - geo/base.hpp
  isVerificationFile: true
  path: test/library_checker/geometry/convex_layers.test.cpp
  requiredBy: []
  timestamp: '2023-12-21 22:18:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/geometry/convex_layers.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/geometry/convex_layers.test.cpp
- /verify/test/library_checker/geometry/convex_layers.test.cpp.html
title: test/library_checker/geometry/convex_layers.test.cpp
---