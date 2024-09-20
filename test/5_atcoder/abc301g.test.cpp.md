---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo3d/base.hpp
    title: geo3d/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo3d/cross_point.hpp
    title: geo3d/cross_point.hpp
  - icon: ':heavy_check_mark:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: nt/rational.hpp
    title: nt/rational.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc301/tasks/abc301_g
    links:
    - https://atcoder.jp/contests/abc301/tasks/abc301_g
  bundledCode: "#line 1 \"test/5_atcoder/abc301g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc301/tasks/abc301_g\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32 infty<u32> = infty<int>;\n\
    template <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128\
    \ infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ double infty<double> = infty<ll>;\ntemplate <>\nconstexpr long double infty<long\
    \ double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n\
    #define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i =\
    \ 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define\
    \ FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for\
    \ (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n\
    #define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n\
    #include <unistd.h>\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\nnamespace\
    \ fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar\
    \ obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil = 0,\
    \ pir = 0, por = 0;\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr\
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
    \ yes(!t); }\r\n#line 4 \"test/5_atcoder/abc301g.test.cpp\"\n\n#line 1 \"nt/rational.hpp\"\
    \ntemplate <typename T = long long, bool REDUCE = true>\nstruct Rational {\n \
    \ T num, den;\n\n  Rational() : num(0), den(1) {}\n  Rational(T x) : num(x), den(1)\
    \ {}\n  Rational(T a, T b, bool coprime = false) : num(a), den(b) {\n    if (den\
    \ < 0) num = -num, den = -den;\n    if (!coprime && REDUCE) reduce();\n  }\n\n\
    \  static T gcd(T a, T b) {\n    a = max(a, -a), b = max(b, -b);\n    while (b)\
    \ {\n      a %= b;\n      swap(a, b);\n    }\n    return a;\n  }\n\n  void reduce()\
    \ {\n    if (!REDUCE) return;\n    T g = gcd(num, den);\n    num /= g, den /=\
    \ g;\n  }\n\n  Rational &operator+=(const Rational &p) {\n    T g = (REDUCE ?\
    \ gcd(den, p.den) : 1);\n    num = num * (p.den / g) + p.num * (den / g);\n  \
    \  den *= p.den / g;\n    reduce();\n    return *this;\n  }\n  Rational &operator-=(const\
    \ Rational &p) {\n    T g = (REDUCE ? gcd(den, p.den) : 1);\n    num = num * (p.den\
    \ / g) - p.num * (den / g);\n    den *= p.den / g;\n    reduce();\n    return\
    \ *this;\n  }\n  Rational &operator*=(const Rational &p) {\n    T g1 = (REDUCE\
    \ ? gcd(num, p.den) : 1);\n    T g2 = (REDUCE ? gcd(den, p.num) : 1);\n    num\
    \ = (num / g1) * (p.num / g2);\n    den = (den / g2) * (p.den / g1);\n    return\
    \ *this;\n  }\n  Rational &operator/=(const Rational &p) {\n    T g1 = (REDUCE\
    \ ? gcd(num, p.num) : 1);\n    T g2 = (REDUCE ? gcd(den, p.den) : 1);\n    num\
    \ = (num / g1) * (p.den / g2);\n    den = (den / g2) * (p.num / g1);\n    if (den\
    \ < 0) num = -num, den = -den;\n    return *this;\n  }\n\n  Rational operator-()\
    \ const { return Rational(-num, den); }\n  Rational operator+(const Rational &p)\
    \ const { return Rational(*this) += p; }\n  Rational operator-(const Rational\
    \ &p) const { return Rational(*this) -= p; }\n  Rational operator*(const Rational\
    \ &p) const { return Rational(*this) *= p; }\n  Rational operator/(const Rational\
    \ &p) const { return Rational(*this) /= p; }\n  bool operator==(const Rational\
    \ &p) const {\n    return num * p.den == p.num * den;\n  }\n  bool operator!=(const\
    \ Rational &p) const {\n    return num * p.den != p.num * den;\n  }\n  bool operator<(const\
    \ Rational &p) const { return num * p.den < p.num * den; }\n  bool operator>(const\
    \ Rational &p) const { return num * p.den > p.num * den; }\n  bool operator<=(const\
    \ Rational &p) const {\n    return num * p.den <= p.num * den;\n  }\n  bool operator>=(const\
    \ Rational &p) const {\n    return num * p.den >= p.num * den;\n  }\n\n  string\
    \ to_string() { return std::to_string(num) + \"/\" + std::to_string(den); }\n\
    \  double to_double() { return double(num) / double(den); }\n};\n#line 2 \"geo3d/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Point_3d {\n  T x, y, z;\n\n  Point_3d() = default;\n\
    \n  template <typename A, typename B, typename C>\n  Point_3d(A x, B y, C z) :\
    \ x(x), y(y), z(z) {}\n\n  Point_3d operator+(Point_3d p) const { return {x +\
    \ p.x, y + p.y, z + p.z}; }\n  Point_3d operator-(Point_3d p) const { return {x\
    \ - p.x, y - p.y, z - p.z}; }\n  Point_3d operator*(T t) const { return {x * t,\
    \ y * t, z * t}; }\n  bool operator==(Point_3d p) const { return x == p.x && y\
    \ == p.y && z == p.z; }\n  bool operator!=(Point_3d p) const { return x != p.x\
    \ || y != p.y || z == p.z; }\n  Point_3d operator-() const { return {-x, -y, -z};\
    \ }\n\n  bool is_parallel(Point_3d p) const {\n    return x * p.y == y * p.x &&\
    \ y * p.z == z * p.y && z * p.x == x * p.z;\n  }\n\n  T dot(Point_3d other) {\
    \ return x * other.x + y * other.y + z * other.z; }\n  double norm() { return\
    \ sqrt(x * x + y * y + z * z); }\n  Point_3d cross(Point_3d other) {\n    return\
    \ Point_3d(y * other.z - z * other.y, z * other.x - x * other.z,\n           \
    \         x * other.y - y * other.x);\n  }\n};\n\ntemplate <typename T>\nstruct\
    \ Line_3d {\n  // a + td\n  Point_3d<T> a, d;\n\n  Line_3d(Point_3d<T> A, Point_3d<T>\
    \ B) : a(A), d(B - A) {\n    assert(d.dot(d) != 0);\n  }\n  bool is_parallel(Line_3d<T>\
    \ other) {\n    Point_3d<T> n = d.cross(other.d);\n    return (n.x == T(0) &&\
    \ n.y == T(0) && n.z == T(0));\n  }\n  bool contain(Point_3d<T> p) {\n    p =\
    \ p - a;\n    p = p.cross(d);\n    return (p.x == T(0) && p.y == T(0) && p.z ==\
    \ T(0));\n  }\n};\n#line 2 \"geo3d/cross_point.hpp\"\n\n// 0: \u4EA4\u70B9\u306A\
    \u3057\n// 1: \u4E00\u610F\u306A\u4EA4\u70B9\n// 2\uFF1A2 \u3064\u4EE5\u4E0A\u306E\
    \u4EA4\u70B9\ntemplate <typename T>\nint count_cross(Line_3d<T> L1, Line_3d<T>\
    \ L2) {\n  static_assert(!std::is_floating_point<T>::value);\n  if (L1.is_parallel(L2))\
    \ {\n    if (L1.contain(L2.a)) return 2;\n    return 0;\n  }\n  Point_3d<T> norm\
    \ = L1.d.cross(L2.d);\n  return ((L1.a - L2.a).dot(norm) == 0 ? 1 : 0);\n}\n\n\
    // count_cross == 1 \u306E\u3068\u304D\u306B\u3060\u3051\u547C\u3076\u3053\u3068\
    \ntemplate <typename REAL, typename T>\nPoint_3d<REAL> cross_point(Line_3d<T>\
    \ L1, Line_3d<T> L2) {\n  Point_3d<T> d1 = L1.d;\n  Point_3d<T> d2 = L2.d;\n \
    \ Point_3d<T> a = L2.a - L1.a;\n  REAL t1 = [&]() -> REAL {\n    FOR(3) {\n  \
    \    d1 = {d1.y, d1.z, d1.x};\n      d2 = {d2.y, d2.z, d2.x};\n      a = {a.y,\
    \ a.z, a.x};\n      T det = d1.x * d2.y - d1.y * d2.x;\n      if (det != 0) {\
    \ return REAL(a.x * d2.y - a.y * d2.x) / REAL(det); }\n    }\n    assert(0);\n\
    \  }();\n  REAL x = REAL(L1.a.x) + t1 * REAL(L1.d.x);\n  REAL y = REAL(L1.a.y)\
    \ + t1 * REAL(L1.d.y);\n  REAL z = REAL(L1.a.z) + t1 * REAL(L1.d.z);\n  return\
    \ {x, y, z};\n}\n#line 8 \"test/5_atcoder/abc301g.test.cpp\"\n\nusing Q = Rational<ll,\
    \ false>;\n\nusing P = Point_3d<ll>;\nusing PQ = Point_3d<Q>;\n\nvoid solve()\
    \ {\n  LL(N);\n  vc<P> point(N);\n  FOR(i, N) {\n    LL(a, b, c);\n    point[i]\
    \ = {a, b, c};\n  }\n\n  sort(all(point), [&](auto& a, auto& b) -> bool { return\
    \ a.x < b.x; });\n\n  ll ANS = N;\n\n  vv(ll, CNT, N, N);\n\n  // \u76F4\u7DDA\
    \u3072\u3068\u3064\u3060\u3051\n  FOR(i, N) FOR(j, i + 1, N) {\n    if (point[i].x\
    \ == point[j].x) continue;\n    Line_3d<ll> L(point[i], point[j]);\n    ll cnt\
    \ = 0;\n    FOR(k, N) cnt += L.contain(point[k]);\n    CNT[i][j] = cnt;\n    chmin(ANS,\
    \ N - (cnt - 1));\n  }\n\n  vc<PQ> point_PQ(N);\n  FOR(i, N) point_PQ[i] = {point[i].x,\
    \ point[i].y, point[i].z};\n\n  // \u4EA4\u70B9\u3092\u5229\u7528\u3059\u308B\n\
    \  FOR(b, N) FOR(a, b) FOR(d, b) FOR(c, d) {\n    Line_3d<ll> L1(point[a], point[b]);\n\
    \    Line_3d<ll> L2(point[c], point[d]);\n    ll n = count_cross(L1, L2);\n  \
    \  if (n != 1) continue;\n    PQ p = cross_point<Q>(L1, L2);\n    if (p.x >= Q(0))\
    \ continue;\n    vc<int> OK(N, 1);\n    FOR(i, N) {\n      PQ a = point_PQ[i]\
    \ - p;\n      FOR(j, i) {\n        PQ b = point_PQ[j] - p;\n        b = b.cross(a);\n\
    \        if (b.x == Q(0) && b.y == Q(0) && b.z == Q(0)) OK[i] = 0;\n      }\n\
    \    }\n    chmin(ANS, SUM<int>(OK));\n  }\n  print(ANS);\n}\n\nsigned main()\
    \ {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc301/tasks/abc301_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"nt/rational.hpp\"\
    \n#include \"geo3d/base.hpp\"\n#include \"geo3d/cross_point.hpp\"\n\nusing Q =\
    \ Rational<ll, false>;\n\nusing P = Point_3d<ll>;\nusing PQ = Point_3d<Q>;\n\n\
    void solve() {\n  LL(N);\n  vc<P> point(N);\n  FOR(i, N) {\n    LL(a, b, c);\n\
    \    point[i] = {a, b, c};\n  }\n\n  sort(all(point), [&](auto& a, auto& b) ->\
    \ bool { return a.x < b.x; });\n\n  ll ANS = N;\n\n  vv(ll, CNT, N, N);\n\n  //\
    \ \u76F4\u7DDA\u3072\u3068\u3064\u3060\u3051\n  FOR(i, N) FOR(j, i + 1, N) {\n\
    \    if (point[i].x == point[j].x) continue;\n    Line_3d<ll> L(point[i], point[j]);\n\
    \    ll cnt = 0;\n    FOR(k, N) cnt += L.contain(point[k]);\n    CNT[i][j] = cnt;\n\
    \    chmin(ANS, N - (cnt - 1));\n  }\n\n  vc<PQ> point_PQ(N);\n  FOR(i, N) point_PQ[i]\
    \ = {point[i].x, point[i].y, point[i].z};\n\n  // \u4EA4\u70B9\u3092\u5229\u7528\
    \u3059\u308B\n  FOR(b, N) FOR(a, b) FOR(d, b) FOR(c, d) {\n    Line_3d<ll> L1(point[a],\
    \ point[b]);\n    Line_3d<ll> L2(point[c], point[d]);\n    ll n = count_cross(L1,\
    \ L2);\n    if (n != 1) continue;\n    PQ p = cross_point<Q>(L1, L2);\n    if\
    \ (p.x >= Q(0)) continue;\n    vc<int> OK(N, 1);\n    FOR(i, N) {\n      PQ a\
    \ = point_PQ[i] - p;\n      FOR(j, i) {\n        PQ b = point_PQ[j] - p;\n   \
    \     b = b.cross(a);\n        if (b.x == Q(0) && b.y == Q(0) && b.z == Q(0))\
    \ OK[i] = 0;\n      }\n    }\n    chmin(ANS, SUM<int>(OK));\n  }\n  print(ANS);\n\
    }\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - nt/rational.hpp
  - geo3d/base.hpp
  - geo3d/cross_point.hpp
  isVerificationFile: true
  path: test/5_atcoder/abc301g.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 23:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_atcoder/abc301g.test.cpp
layout: document
redirect_from:
- /verify/test/5_atcoder/abc301g.test.cpp
- /verify/test/5_atcoder/abc301g.test.cpp.html
title: test/5_atcoder/abc301g.test.cpp
---
