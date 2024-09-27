---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/acted_monoid/sum_assign.hpp
    title: alg/acted_monoid/sum_assign.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: alg/monoid/assign.hpp
    title: alg/monoid/assign.hpp
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':x:'
    path: ds/intervals.hpp
    title: ds/intervals.hpp
  - icon: ':x:'
    path: ds/segtree/lazy_segtree.hpp
    title: ds/segtree/lazy_segtree.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_Ex
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_Ex
  bundledCode: "#line 1 \"test/5_atcoder/abc256ex2.test.cpp\"\n#define PROBLEM \"\
    https://atcoder.jp/contests/abc256/tasks/abc256_Ex\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    \ yes(!t); }\r\n#line 4 \"test/5_atcoder/abc256ex2.test.cpp\"\n\n#line 2 \"ds/fastset.hpp\"\
    \n\r\n// 64-ary tree\r\n// space: (N/63) * u64\r\nstruct FastSet {\r\n  static\
    \ constexpr u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\n\r\n  FastSet()\
    \ {}\r\n  FastSet(int n) { build(n); }\r\n\r\n  int size() { return n; }\r\n\r\
    \n  template <typename F>\r\n  FastSet(int n, F f) {\r\n    build(n, f);\r\n \
    \ }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\n    n = m;\r\n    do {\r\
    \n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n      m = (m + B - 1) / B;\r\
    \n    } while (m > 1);\r\n    log = len(seg);\r\n  }\r\n  template <typename F>\r\
    \n  void build(int n, F f) {\r\n    build(n);\r\n    FOR(i, n) { seg[0][i / B]\
    \ |= u64(f(i)) << (i % B); }\r\n    FOR(h, log - 1) {\r\n      FOR(i, len(seg[h]))\
    \ {\r\n        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\r\n     \
    \ }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const { return seg[0][i /\
    \ B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    for (int h = 0; h < log;\
    \ h++) {\r\n      seg[h][i / B] |= u64(1) << (i % B), i /= B;\r\n    }\r\n  }\r\
    \n  void add(int i) { insert(i); }\r\n  void erase(int i) {\r\n    u64 x = 0;\r\
    \n    for (int h = 0; h < log; h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i\
    \ % B));\r\n      seg[h][i / B] |= x << (i % B);\r\n      x = bool(seg[h][i /\
    \ B]);\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int i) { erase(i); }\r\
    \n\r\n  // min[x,n) or n\r\n  int next(int i) {\r\n    assert(i <= n);\r\n   \
    \ chmax(i, 0);\r\n    for (int h = 0; h < log; h++) {\r\n      if (i / B == seg[h].size())\
    \ break;\r\n      u64 d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n   \
    \     i = i / B + 1;\r\n        continue;\r\n      }\r\n      i += lowbit(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ lowbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ n;\r\n  }\r\n\r\n  // max [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i\
    \ >= -1);\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\
    \n      if (i == -1) break;\r\n      u64 d = seg[h][i / B] << (63 - i % B);\r\n\
    \      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n\
    \      i -= __builtin_clzll(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n\
    \        i *= B;\r\n        i += topbit(seg[g][i / B]);\r\n      }\r\n      return\
    \ i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return\
    \ next(l) < r; }\r\n\r\n  // [l, r)\r\n  template <typename F>\r\n  void enumerate(int\
    \ l, int r, F f) {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\
    \n  }\r\n\r\n  string to_string() {\r\n    string s(n, '?');\r\n    for (int i\
    \ = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n\
    };\n#line 2 \"ds/intervals.hpp\"\n\n// FastSet \u3067\u9AD8\u901F\u5316\u3057\u305F\
    \u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast {\n  const int LLIM,\
    \ RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\
    \u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  int total_len;\n\
    \  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val) : LLIM(0),\
    \ RLIM(N), none_val(none_val), total_num(0), total_len(0), dat(N, none_val), ss(N)\
    \ { ss.insert(0); }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\
    \u306E\u53D6\u5F97 l, r, t\n  tuple<int, int, T> get(int x, bool ERASE = false)\
    \ {\n    int l = ss.prev(x);\n    int r = ss.next(x + 1);\n    T t = dat[l];\n\
    \    if (t != none_val && ERASE) {\n      --total_num, total_len -= r - l;\n \
    \     dat[l] = none_val;\n      merge_at(l);\n      merge_at(r);\n    }\n    return\
    \ {l, r, t};\n  }\n\n  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\u53D6\
    \u5F97\n  // f(l,r,x)\n  template <typename F>\n  void enumerate_range(int L,\
    \ int R, F f, bool ERASE = false) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n\
    \    if (L == R) return;\n    if (!ERASE) {\n      int l = ss.prev(L);\n     \
    \ while (l < R) {\n        int r = ss.next(l + 1);\n        f(max(l, L), min(r,\
    \ R), dat[l]);\n        l = r;\n      }\n      return;\n    }\n    // \u534A\u7AEF\
    \u306A\u3068\u3053\u308D\u306E\u5206\u5272\n    int p = ss.prev(L);\n    if (p\
    \ < L) {\n      ss.insert(L);\n      dat[L] = dat[p];\n      if (dat[L] != none_val)\
    \ ++total_num;\n    }\n    p = ss.next(R);\n    if (R < p) {\n      dat[R] = dat[ss.prev(R)];\n\
    \      ss.insert(R);\n      if (dat[R] != none_val) ++total_num;\n    }\n    p\
    \ = L;\n    while (p < R) {\n      int q = ss.next(p + 1);\n      T x = dat[p];\n\
    \      f(p, q, x);\n      if (dat[p] != none_val) --total_num, total_len -= q\
    \ - p;\n      ss.erase(p);\n      p = q;\n    }\n    ss.insert(L);\n    dat[L]\
    \ = none_val;\n  }\n\n  void set(int L, int R, T t) {\n    if (L == R) return;\n\
    \    enumerate_range(\n        L, R, [](int l, int r, T x) -> void {}, true);\n\
    \    ss.insert(L);\n    dat[L] = t;\n    if (t != none_val) total_num++, total_len\
    \ += R - L;\n    merge_at(L);\n    merge_at(R);\n  }\n\n  template <typename F>\n\
    \  void enumerate_all(F f) {\n    enumerate_range(0, RLIM, f, false);\n  }\n\n\
    \  void merge_at(int p) {\n    if (p <= 0 || RLIM <= p) return;\n    int q = ss.prev(p\
    \ - 1);\n    if (dat[p] == dat[q]) {\n      if (dat[p] != none_val) --total_num;\n\
    \      ss.erase(p);\n    }\n  }\n};\n\n// https://codeforces.com/contest/1638/problem/E\n\
    // \u6301\u3064\u5024\u306E\u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7\
    \ X\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\
    \u6307\u5B9A\u3059\u308B\ntemplate <typename T, typename X = ll>\nstruct Intervals\
    \ {\n  static constexpr X LLIM = -infty<X>;\n  static constexpr X RLIM = infty<X>;\n\
    \  T none_val;\n  // const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\
    \u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  X\
    \ total_len;\n  map<X, T> dat;\n\n  Intervals(T none_val) : none_val(none_val),\
    \ total_num(0), total_len(0) {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<X, X, T> get(X x, bool ERASE = false) {\n    auto it2 = dat.upper_bound(x);\n\
    \    auto it1 = prev(it2);\n    auto [l, tl] = *it1;\n    auto [r, tr] = *it2;\n\
    \    if (tl != none_val && ERASE) {\n      --total_num, total_len -= r - l;\n\
    \      dat[l] = none_val;\n      merge_at(l);\n      merge_at(r);\n    }\n   \
    \ return {l, r, tl};\n  }\n\n  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\
    \u53D6\u5F97 f(l, r, t)\n  template <typename F>\n  void enumerate_range(X L,\
    \ X R, F f, bool ERASE = false) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n\
    \    if (!ERASE) {\n      auto it = prev(dat.upper_bound(L));\n      while ((*it).fi\
    \ < R) {\n        auto it2 = next(it);\n        f(max((*it).fi, L), min((*it2).fi,\
    \ R), (*it).se);\n        it = it2;\n      }\n      return;\n    }\n    // \u534A\
    \u7AEF\u306A\u3068\u3053\u308D\u306E\u5206\u5272\n    auto p = prev(dat.upper_bound(L));\n\
    \    if ((*p).fi < L) {\n      dat[L] = (*p).se;\n      if (dat[L] != none_val)\
    \ ++total_num;\n    }\n    p = dat.lower_bound(R);\n    if (R < (*p).fi) {\n \
    \     T t = (*prev(p)).se;\n      dat[R] = t;\n      if (t != none_val) ++total_num;\n\
    \    }\n    p = dat.lower_bound(L);\n    while (1) {\n      if ((*p).fi >= R)\
    \ break;\n      auto q = next(p);\n      T t = (*p).se;\n      f((*p).fi, (*q).fi,\
    \ t);\n      if (t != none_val) --total_num, total_len -= (*q).fi - (*p).fi;\n\
    \      p = dat.erase(p);\n    }\n    dat[L] = none_val;\n  }\n\n  void set(X L,\
    \ X R, T t) {\n    assert(L <= R);\n    if (L == R) return;\n    enumerate_range(\n\
    \        L, R, [](int l, int r, T x) -> void {}, true);\n    dat[L] = t;\n   \
    \ if (t != none_val) total_num++, total_len += R - L;\n    merge_at(L);\n    merge_at(R);\n\
    \  }\n\n  template <typename F>\n  void enumerate_all(F f) {\n    enumerate_range(LLIM,\
    \ RLIM, f, false);\n  }\n\n  void merge_at(X p) {\n    if (p == LLIM || RLIM ==\
    \ p) return;\n    auto itp = dat.lower_bound(p);\n    assert((*itp).fi == p);\n\
    \    auto itq = prev(itp);\n    if ((*itp).se == (*itq).se) {\n      if ((*itp).se\
    \ != none_val) --total_num;\n      dat.erase(itp);\n    }\n  }\n};\n#line 2 \"\
    ds/segtree/lazy_segtree.hpp\"\n\ntemplate <typename ActedMonoid>\nstruct Lazy_SegTree\
    \ {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA\
    \ = typename AM::Monoid_A;\n  using X = typename MX::value_type;\n  using A =\
    \ typename MA::value_type;\n  int n, log, size;\n  vc<X> dat;\n  vc<A> laz;\n\n\
    \  Lazy_SegTree() {}\n  Lazy_SegTree(int n) { build(n); }\n  template <typename\
    \ F>\n  Lazy_SegTree(int n, F f) {\n    build(n, f);\n  }\n  Lazy_SegTree(const\
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
    \ E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n \
    \ static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 2 \"alg/monoid/assign.hpp\"\n\r\ntemplate <typename X, int none_val>\r\
    \nstruct Monoid_Assign {\r\n  using value_type = X;\r\n  static X op(X x, X y)\
    \ { return (y == X(none_val) ? x : y); }\r\n  static constexpr X unit() { return\
    \ X(none_val); }\r\n  static constexpr bool commute = false;\r\n};\r\n#line 3\
    \ \"alg/acted_monoid/sum_assign.hpp\"\n\r\ntemplate <typename E, E none_val>\r\
    \nstruct ActedMonoid_Sum_Assign {\r\n  using Monoid_X = Monoid_Add<E>;\r\n  using\
    \ Monoid_A = Monoid_Assign<E, none_val>;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  static constexpr X act(const\
    \ X &x, const A &a, const ll &size) {\r\n    if (a == Monoid_A::unit()) return\
    \ x;\r\n    return a * E(size);\r\n  }\r\n};\r\n#line 8 \"test/5_atcoder/abc256ex2.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n  Intervals<int, int> I(0);\n\
    \  FOR(i, N) I.set(i, i + 1, A[i]);\n  Lazy_SegTree<ActedMonoid_Sum_Assign<ll,\
    \ -1>> seg(A);\n  FOR(Q) {\n    INT(t, L, R);\n    --L;\n    if (t == 2) {\n \
    \     LL(y);\n      I.set(L, R, y);\n      seg.apply(L, R, y);\n    }\n    if\
    \ (t == 3) { print(seg.prod(L, R)); }\n    if (t == 1) {\n      INT(d);\n    \
    \  vc<tuple<int, int, int>> tmp;\n      I.enumerate_range(\n          L, R, [&](int\
    \ l, int r, int x) -> void { tmp.eb(l, r, x / d); },\n          true);\n     \
    \ for (auto&& [l, r, x]: tmp) {\n        seg.apply(l, r, x);\n        I.set(l,\
    \ r, x);\n      }\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/intervals.hpp\"\
    \n#include \"ds/segtree/lazy_segtree.hpp\"\n#include \"alg/acted_monoid/sum_assign.hpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n  Intervals<int, int> I(0);\n\
    \  FOR(i, N) I.set(i, i + 1, A[i]);\n  Lazy_SegTree<ActedMonoid_Sum_Assign<ll,\
    \ -1>> seg(A);\n  FOR(Q) {\n    INT(t, L, R);\n    --L;\n    if (t == 2) {\n \
    \     LL(y);\n      I.set(L, R, y);\n      seg.apply(L, R, y);\n    }\n    if\
    \ (t == 3) { print(seg.prod(L, R)); }\n    if (t == 1) {\n      INT(d);\n    \
    \  vc<tuple<int, int, int>> tmp;\n      I.enumerate_range(\n          L, R, [&](int\
    \ l, int r, int x) -> void { tmp.eb(l, r, x / d); },\n          true);\n     \
    \ for (auto&& [l, r, x]: tmp) {\n        seg.apply(l, r, x);\n        I.set(l,\
    \ r, x);\n      }\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/intervals.hpp
  - ds/fastset.hpp
  - ds/segtree/lazy_segtree.hpp
  - alg/acted_monoid/sum_assign.hpp
  - alg/monoid/add.hpp
  - alg/monoid/assign.hpp
  isVerificationFile: true
  path: test/5_atcoder/abc256ex2.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 04:06:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/5_atcoder/abc256ex2.test.cpp
layout: document
redirect_from:
- /verify/test/5_atcoder/abc256ex2.test.cpp
- /verify/test/5_atcoder/abc256ex2.test.cpp.html
title: test/5_atcoder/abc256ex2.test.cpp
---
