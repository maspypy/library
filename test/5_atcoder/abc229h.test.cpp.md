---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: game/dyadic_rational.hpp
    title: game/dyadic_rational.hpp
  - icon: ':x:'
    path: game/number_and_star.hpp
    title: game/number_and_star.hpp
  - icon: ':x:'
    path: game/solve_partizan_game.hpp
    title: game/solve_partizan_game.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':x:'
    path: other/mex.hpp
    title: other/mex.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc229/tasks/abc229_h
    links:
    - https://atcoder.jp/contests/abc229/tasks/abc229_h
  bundledCode: "#line 1 \"test/5_atcoder/abc229h.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc229/tasks/abc229_h\"\
    \n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16\
    \ = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n// https://trap.jp/post/1224/\n#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n\
    #define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll\
    \ i = a; i < ll(b); ++i)\n#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i\
    \ += (c))\n#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i,\
    \ a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i =\
    \ (b)-1; i >= ll(a); --i)\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a,\
    \ b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(x)\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parity(x) & 1 ? -1 : 1);\
    \ }\nint popcnt_sgn(u64 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 -\
    \ __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename T>\nT floor(T a,\
    \ T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\n\
    T ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\n\
    T bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\n\
    pair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n\
    }\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n  T sm =\
    \ 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n\
    #define MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
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
    \ vector<T> &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\
    \ [&](int i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return\
    \ ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const\
    \ vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n}\n#endif\n#line 1 \"other/io.hpp\"\n\
    #define FASTIO\r\n#include <unistd.h>\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\
    \nnamespace fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\
    \nchar obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil\
    \ = 0, pir = 0, por = 0;\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr\
    \ Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n      int n = i;\r\
    \n      for (int j = 3; j >= 0; j--) {\r\n        num[i][j] = n % 10 | '0';\r\n\
    \        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline\
    \ void load() {\r\n  memcpy(ibuf, ibuf + pil, pir - pil);\r\n  pir = pir - pil\
    \ + fread(ibuf + pir - pil, 1, SZ - pir + pil, stdin);\r\n  pil = 0;\r\n  if (pir\
    \ < SZ) ibuf[pir++] = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(obuf,\
    \ 1, por, stdout);\r\n  por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n  do {\r\n\
    \    if (pil + 1 > pir) load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\
    \n}\r\n\r\nvoid rd(string &x) {\r\n  x.clear();\r\n  char c;\r\n  do {\r\n   \
    \ if (pil + 1 > pir) load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\
    \n  do {\r\n    x += c;\r\n    if (pil == pir) load();\r\n    c = ibuf[pil++];\r\
    \n  } while (!isspace(c));\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T\
    \ &x) {\r\n  string s;\r\n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid rd_integer(T &x) {\r\n  if (pil + 100 > pir) load();\r\n  char c;\r\
    \n  do\r\n    c = ibuf[pil++];\r\n  while (c < '-');\r\n  bool minus = 0;\r\n\
    \  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (c ==\
    \ '-') { minus = 1, c = ibuf[pil++]; }\r\n  }\r\n  x = 0;\r\n  while ('0' <= c)\
    \ { x = x * 10 + (c & 15), c = ibuf[pil++]; }\r\n  if constexpr (is_signed<T>::value\
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
    using fastio::flush;\r\n\r\n#if defined(LOCAL)\r\n#define SHOW(...) SHOW_IMPL(__VA_ARGS__,\
    \ SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)\r\n#define SHOW_IMPL(_1,\
    \ _2, _3, _4, _5, _6, NAME, ...) NAME\r\n#define SHOW1(x) print(#x, \"=\", (x)),\
    \ flush()\r\n#define SHOW2(x, y) print(#x, \"=\", (x), #y, \"=\", (y)), flush()\r\
    \n#define SHOW3(x, y, z) print(#x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z)),\
    \ flush()\r\n#define SHOW4(x, y, z, w) print(#x, \"=\", (x), #y, \"=\", (y), #z,\
    \ \"=\", (z), #w, \"=\", (w)), flush()\r\n#define SHOW5(x, y, z, w, v) print(#x,\
    \ \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", (v)),\
    \ flush()\r\n#define SHOW6(x, y, z, w, v, u) print(#x, \"=\", (x), #y, \"=\",\
    \ (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", (v), #u, \"=\", (u)), flush()\r\
    \n#else\r\n#define SHOW(...)\r\n#endif\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__;\
    \ \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n\
    \  read(__VA_ARGS__)\r\n#define U32(...)   \\\r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define U64(...)   \\\r\n  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ CHAR(...)   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)\
    \      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 5 \"test/5_atcoder/abc229h.test.cpp\"\n\n#line 1 \"game/solve_partizan_game.hpp\"\
    \n\n#line 1 \"game/dyadic_rational.hpp\"\n// a+b/2^M \u306E\u5F62\u3067\u6301\u3064\
    \ntemplate <typename INTEGER>\nstruct Dyadic_Rational {\n  using X = Dyadic_Rational;\n\
    \  INTEGER a, b;\n  static constexpr int M = std::numeric_limits<INTEGER>::digits\
    \ - 2;\n\n  Dyadic_Rational(INTEGER a = 0) : a(a), b(0) {}\n\n  // x + y / z\n\
    \  Dyadic_Rational(INTEGER x, INTEGER y, INTEGER z) : a(x), b(y) {\n    auto [q,\
    \ r] = divmod(b, z);\n    a += q;\n    b = r;\n    b *= (INTEGER(1) << M) / z;\n\
    \  }\n\n  // x/y\n  Dyadic_Rational(INTEGER x, INTEGER y) : Dyadic_Rational(0,\
    \ x, y) {}\n\n  static X from_ab(INTEGER a, INTEGER b) {\n    X x(a);\n    x.b\
    \ = b;\n    return x;\n  }\n\n  // \u6BD4\u8F03\n  bool operator==(X const& rhs)\
    \ const { return (a == rhs.a && b == rhs.b); }\n  bool operator!=(X const& rhs)\
    \ const { return !(*this == rhs); }\n  bool operator<(X const& rhs) const { return\
    \ (a < rhs.a) || (a == rhs.a && b < rhs.b); }\n  bool operator<=(X const& rhs)\
    \ const { return (a < rhs.a) || (a == rhs.a && b <= rhs.b); }\n  bool operator>(X\
    \ const& rhs) const { return (a > rhs.a) || (a == rhs.a && b > rhs.b); }\n  bool\
    \ operator>=(X const& rhs) const { return (a > rhs.a) || (a == rhs.a && b >= rhs.b);\
    \ }\n\n  // \u52A0\u6CD5\n  friend X operator+(const X& x, const X& y) {\n   \
    \ INTEGER a = x.a + y.a, b = x.b + y.b;\n    while (b >= INTEGER(1) << M) {\n\
    \      ++a;\n      b -= INTEGER(1) << M;\n    }\n    return from_ab(a, b);\n \
    \ }\n  friend X operator-(const X& x, const X& y) {\n    INTEGER a = x.a - y.a,\
    \ b = x.b - y.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1) << M;\n\
    \    }\n    return from_ab(a, b);\n  }\n  friend X operator-(const X& x) {\n \
    \   INTEGER a = -x.a, b = -x.b;\n    while (b < 0) {\n      --a;\n      b += INTEGER(1)\
    \ << M;\n    }\n    return from_ab(a, b);\n  }\n  X& operator+=(const X& x) {\
    \ return (*this) = (*this) + x; }\n  X& operator-=(const X& x) { return (*this)\
    \ = (*this) - x; }\n\n  static X simplest(X x, X y, bool include_x = false, bool\
    \ include_y = false) {\n    if (include_x && x != -infinity()) {\n      // eps\
    \ \u3092\u5F15\u304F, \u3042\u3068\u3067\u3082\u3063\u3068\u5C0F\u3055\u3044 eps\
    \ \u3092\u4F7F\u3063\u3066\u3044\u308B !\n      x = x - from_ab(0, 2);\n    }\n\
    \    if (include_y && y != infinity()) {\n      // eps \u3092\u8DB3\u3059\n  \
    \    y = y + from_ab(0, 2);\n    }\n    assert(x < y);\n    if (y.a < 0) return\
    \ -simplest(-y, -x);\n    {\n      INTEGER l = x.a + 1;\n      INTEGER r = (y.b\
    \ == 0 ? y.a - 1 : y.a);\n      if (l <= 0 && 0 <= r) return X(0);\n      if (l\
    \ <= r && 0 <= l) return X(l);\n      if (l <= r && r <= 0) return X(r);\n   \
    \ }\n\n    INTEGER l = x.b + 1;\n    INTEGER r = (y.b == 0 ? (INTEGER(1) << M)\
    \ - 1 : y.b - 1);\n    if (l == r) return from_ab(x.a, l);\n    int k = topbit(l\
    \ ^ r);\n    r &= ~((INTEGER(1) << k) - 1);\n    return from_ab(x.a, r);\n  }\n\
    \n  static constexpr X infinity() { return from_ab(INTEGER(1) << M, 0); }\n\n\
    \  string to_string() {\n    ll x = a, y = b, z = INTEGER(1) << M;\n    while\
    \ (y % 2 == 0 && z % 2 == 0) { y /= 2, z /= 2; }\n    y += x * z;\n    return\
    \ std::to_string(y) + \"/\" + std::to_string(z);\n  }\n};\n#line 1 \"other/mex.hpp\"\
    \nint mex(const vc<int>& A) {\n  int n = len(A);\n  vc<bool> aru(n + 1);\n  for\
    \ (auto& x: A)\n    if (x < n) aru[x] = 1;\n  int mex = 0;\n  while (aru[mex])\
    \ ++mex;\n  return mex;\n}\n#line 3 \"game/number_and_star.hpp\"\n\nstruct Number_And_Star\
    \ {\n  using A = Dyadic_Rational<ll>;\n  // a + *b\n  A a;\n  int b;\n  using\
    \ T = Number_And_Star;\n\n  Number_And_Star(A a = 0, ll b = 0) : a(a), b(b) {}\n\
    \  T& operator+=(const T& p) {\n    a += p.a, b ^= p.b;\n    return *this;\n \
    \ }\n  T& operator-=(const T& p) {\n    a -= p.a, b ^= p.b;\n    return *this;\n\
    \  }\n  T operator-() const { return T(-a, b); }\n  bool operator==(const T& p)\
    \ const { return (a == p.a && b == p.b); }\n\n  // {\u8A08\u7B97\u3067\u304D\u305F\
    \u304B, \u5024}\n  static pair<bool, T> from_options(vc<T> left_ops, vc<T> right_ops)\
    \ {\n    A xl = -A::infinity(), xr = A::infinity();\n    vc<int> Lb, Rb;\n   \
    \ for (auto&& t: left_ops) {\n      if (chmax(xl, t.a)) Lb.clear();\n      if\
    \ (xl == t.a) Lb.eb(t.b);\n    }\n    for (auto&& t: right_ops) {\n      if (chmin(xr,\
    \ t.a)) Rb.clear();\n      if (xr == t.a) Rb.eb(t.b);\n    }\n    int Lm = mex(Lb),\
    \ Rm = mex(Rb);\n    if (xl < xr) {\n      A a = A::simplest(xl, xr, Lm == 0,\
    \ Rm == 0);\n      return {true, T(a, 0)};\n    }\n    if (xl == xr) {\n     \
    \ if (Lm == Rm) return {true, T(xl, Lm)};\n    }\n    return {false, T(0, 0)};\n\
    \  }\n\n  string to_string() {\n    string x = a.to_string();\n    x += \" + *\"\
    ;\n    x += ::to_string(b);\n    return x;\n  }\n\n  // L, R \u306F\u305D\u308C\
    \u305E\u308C\u81EA\u5206\u624B\u756A\u306E\u3068\u304D\u306B\u52DD\u3066\u308B\
    \u304B\uFF1F\n  pair<bool, bool> outcome() {\n    if (a > 0) return {1, 0};\n\
    \    if (a < 0) return {0, 1};\n    if (b == 0) return {0, 0};\n    return {1,\
    \ 1};\n  }\n};\n#line 3 \"game/solve_partizan_game.hpp\"\n\n// number, star \u3067\
    \u3044\u3044\u611F\u3058\u306B\u8A08\u7B97\u3067\u304D\u305F\u3068\u304D\u3060\
    \u3051\u6210\u529F\n// \u5931\u6557\u3057\u305F\u3068\u304D\u306F\u3001empty map\
    \ \u304C\u8FD4\u308B\n// \u30FBstates\uFF1A\u8208\u5473\u306E\u3042\u308B state\
    \ \u5168\u4F53\n// \u30FBget_options\uFF1Apair<vc<STATE>, vc<STATE>>(STATE), left\
    \ ops / right ops\n// https://qoj.ac/contest/1828/problem/9567\ntemplate <typename\
    \ STATE, typename F>\nmap<STATE, Number_And_Star> solve_partizan_game(const vector<STATE>&\
    \ states, F get_options) {\n  using X = Number_And_Star;\n  map<STATE, X> MP;\n\
    \n  bool success = 1;\n\n  auto dfs = [&](auto& dfs, const STATE& s) -> X {\n\
    \    if (!success) return X();\n    if (MP.count(s)) return MP[s];\n    vc<X>\
    \ left, right;\n    auto [lop, rop] = get_options(s);\n    for (auto&& t: lop)\
    \ left.eb(dfs(dfs, t));\n    for (auto&& t: rop) right.eb(dfs(dfs, t));\n    auto\
    \ [ok, t] = X::from_options(left, right);\n    if (!success) return X{};\n   \
    \ if (!ok) {\n      // print(\"FAILED\");\n      // print(s);\n      // print(\"\
    LEFT\");\n      // for (auto& t: lop) {\n      //   X x = dfs(dfs, t);\n     \
    \ //   print(t, x.to_string());\n      // }\n      // print(\"RIGHT\");\n    \
    \  // for (auto& t: rop) {\n      //   X x = dfs(dfs, t);\n      //   print(t,\
    \ x.to_string());\n      // }\n      success = 0;\n      return X();\n    }\n\
    \    MP[s] = t;\n    return MP[s] = t;\n  };\n\n  for (auto&& s: states) dfs(dfs,\
    \ s);\n  if (!success) MP.clear();\n  return MP;\n}\n#line 7 \"test/5_atcoder/abc229h.test.cpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VEC(string, G, N);\n  vc<string> states(N);\n\
    \  FOR(i, N) FOR(j, N) states[j] += G[i][j];\n\n  auto get_options = [&](string\
    \ s) -> pair<vc<string>, vc<string>> {\n    int n = len(s);\n    vc<string> left,\
    \ right;\n    FOR(i, 1, n) {\n      // \u9032\u3081\u308B\n      if (s[i - 1]\
    \ == '.' && s[i] == 'W') {\n        swap(s[i - 1], s[i]);\n        left.eb(s);\n\
    \        swap(s[i - 1], s[i]);\n      }\n      if (s[i - 1] == '.' && s[i] ==\
    \ 'B') {\n        swap(s[i - 1], s[i]);\n        right.eb(s);\n        swap(s[i\
    \ - 1], s[i]);\n      }\n    }\n    FOR(i, n) {\n      // \u98DF\u3079\u308B\n\
    \      if (s[i] == 'B') {\n        s[i] = '.';\n        left.eb(s);\n        s[i]\
    \ = 'B';\n      }\n      if (s[i] == 'W') {\n        s[i] = '.';\n        right.eb(s);\n\
    \        s[i] = 'W';\n      }\n    }\n    return {left, right};\n  };\n\n  using\
    \ X = Dyadic_Rational<int>;\n  auto MP = solve_partizan_game<string, int>(states,\
    \ get_options);\n  X x(0);\n  // for (auto&& [k, x]: MP) { print(k, \",\", x.to_string());\
    \ }\n  for (auto&& s: states) { x += MP[s]; }\n  print(x > X(0) ? \"Takahashi\"\
    \ : \"Snuke\");\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc229/tasks/abc229_h\"\n\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"game/solve_partizan_game.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VEC(string, G, N);\n  vc<string> states(N);\n\
    \  FOR(i, N) FOR(j, N) states[j] += G[i][j];\n\n  auto get_options = [&](string\
    \ s) -> pair<vc<string>, vc<string>> {\n    int n = len(s);\n    vc<string> left,\
    \ right;\n    FOR(i, 1, n) {\n      // \u9032\u3081\u308B\n      if (s[i - 1]\
    \ == '.' && s[i] == 'W') {\n        swap(s[i - 1], s[i]);\n        left.eb(s);\n\
    \        swap(s[i - 1], s[i]);\n      }\n      if (s[i - 1] == '.' && s[i] ==\
    \ 'B') {\n        swap(s[i - 1], s[i]);\n        right.eb(s);\n        swap(s[i\
    \ - 1], s[i]);\n      }\n    }\n    FOR(i, n) {\n      // \u98DF\u3079\u308B\n\
    \      if (s[i] == 'B') {\n        s[i] = '.';\n        left.eb(s);\n        s[i]\
    \ = 'B';\n      }\n      if (s[i] == 'W') {\n        s[i] = '.';\n        right.eb(s);\n\
    \        s[i] = 'W';\n      }\n    }\n    return {left, right};\n  };\n\n  using\
    \ X = Dyadic_Rational<int>;\n  auto MP = solve_partizan_game<string, int>(states,\
    \ get_options);\n  X x(0);\n  // for (auto&& [k, x]: MP) { print(k, \",\", x.to_string());\
    \ }\n  for (auto&& s: states) { x += MP[s]; }\n  print(x > X(0) ? \"Takahashi\"\
    \ : \"Snuke\");\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - game/solve_partizan_game.hpp
  - game/number_and_star.hpp
  - game/dyadic_rational.hpp
  - other/mex.hpp
  isVerificationFile: true
  path: test/5_atcoder/abc229h.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 23:01:41+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/5_atcoder/abc229h.test.cpp
layout: document
redirect_from:
- /verify/test/5_atcoder/abc229h.test.cpp
- /verify/test/5_atcoder/abc229h.test.cpp.html
title: test/5_atcoder/abc229h.test.cpp
---
