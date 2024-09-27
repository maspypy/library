---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/segtree/beats_kinetic.hpp
    title: ds/segtree/beats_kinetic.hpp
  - icon: ':question:'
    path: ds/segtree/segtree_beats.hpp
    title: ds/segtree/segtree_beats.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/kinetic.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \ yes(!t); }\r\n#line 4 \"test/1_mytest/kinetic.test.cpp\"\n\n#line 2 \"ds/segtree/segtree_beats.hpp\"\
    \n\ntemplate <typename ActedMonoid>\nstruct SegTree_Beats {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n\n  SegTree_Beats() {}\n  SegTree_Beats(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree_Beats(int n, F f) {\n \
    \   build(n, f);\n  }\n  SegTree_Beats(const vc<X>& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n\
    \  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m, log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::unit());\n    laz.assign(size, MA::unit());\n    FOR(i, n) dat[size\
    \ + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void update(int k)\
    \ { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n  void set(int p, X x) {\n\
    \    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n\
    \  /*\n  void all_apply(int k, A a) {\n    dat[k] = ActedMonoid::act(dat[k], a);\n\
    \    if (k < size) {\n      laz[k] = MA::op(laz[k], a);\n      if (dat[k].fail)\
    \ push(k), update(k);\n    }\n  }\n  */\n\n  vc<X> get_all() {\n    FOR(k, 1,\
    \ size) { push(k); }\n    return {dat.begin() + size, dat.begin() + size + n};\n\
    \  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n  \
    \  if (l == r) return MX::unit();\n    l += size, r += size;\n    for (int i =\
    \ log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X xl = MX::unit(), xr\
    \ = MX::unit();\n    while (l < r) {\n      if (l & 1) xl = MX::op(xl, dat[l++]);\n\
    \      if (r & 1) xr = MX::op(dat[--r], xr);\n      l >>= 1, r >>= 1;\n    }\n\
    \    return MX::op(xl, xr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  void\
    \ apply(int l, int r, A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if\
    \ (l == r) return;\n    l += size, r += size;\n    for (int i = log; i >= 1; i--)\
    \ {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l < r)\
    \ {\n      if (l & 1) apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n\
    \      l >>= 1, r >>= 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\nprivate:\n  void apply_at(int\
    \ k, A a) {\n    int sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k],\
    \ a, sz);\n    if (k < size) {\n      laz[k] = MA::op(laz[k], a);\n      if (dat[k].fail)\
    \ push(k), update(k);\n    }\n  }\n\n  void push(int k) {\n    if (laz[k] == MA::unit())\
    \ return;\n    apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::unit();\n  }\n};\n#line 2 \"ds/segtree/beats_kinetic.hpp\"\n\n// (x[i],y[i])\
    \ \u304B\u3089\u306A\u308B\u5217. a>=0 \u3067\u3042\u308B\u3068\u304D\u306B y[i]\
    \ :- y[i] + ax[i] + b \u3068\u3044\u3046\u4F5C\u7528\u304C\u3067\u304D\u308B\n\
    // x \u306B\u306F\u5358\u8ABF\u6027\u306F\u8981\u3089\u306A\u3044. x,sum(a):T1,\
    \ y,sum(b):T2, T1*T1<=T2.\n// https://codeforces.com/blog/entry/82094#comment-688448\n\
    // https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d\ntemplate <typename\
    \ T1, typename T2>\nstruct Beats_Kinetic_Max {\n  struct Mono_X {\n    struct\
    \ X {\n      T1 x;\n      T2 y;\n      T1 nxt_change;\n      bool fail;\n    };\n\
    \    using value_type = X;\n    static X op(X L, X R) {\n      X M;\n      if\
    \ (L.y < R.y) { swap(L, R); }\n      M.x = L.x, M.y = L.y;\n      M.nxt_change\
    \ = min(L.nxt_change, R.nxt_change);\n      if (L.x < R.x) {\n        T2 t = floor<T2>(L.y\
    \ - R.y, R.x - L.x);\n        chmin(M.nxt_change, t + 1);\n      }\n      M.fail\
    \ = 0;\n      return M;\n    }\n    static constexpr X unit() { return {0, -infty<T2>,\
    \ infty<T1>, 0}; }\n    bool commute = true;\n  };\n  struct Mono_A {\n    using\
    \ X = pair<T1, T2>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) { return {x.fi + y.fi, x.se + y.se}; }\n    static constexpr\
    \ X unit() { return {0, 0}; }\n    bool commute = true;\n  };\n  struct Beats\
    \ {\n    using Monoid_X = Mono_X;\n    using Monoid_A = Mono_A;\n    using X =\
    \ typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& M, const A& a, int cnt) {\n      assert(!M.fail && a.fi >=\
    \ 0);\n      if (M.nxt_change <= a.fi) {\n        M.fail = 1;\n        return\
    \ M;\n      }\n      M.y += T2(a.fi) * M.x + a.se;\n      M.nxt_change -= a.fi;\n\
    \      return M;\n    }\n  };\n  using S = typename Mono_X::X;\n  SegTree_Beats<Beats>\
    \ seg;\n  Beats_Kinetic_Max(vc<T1>& X, vc<T2>& Y) {\n    seg.build(len(X), [&](int\
    \ i) -> S { return {X[i], Y[i], infty<T1>, 0}; });\n  }\n  template <typename\
    \ F>\n  Beats_Kinetic_Max(int n, F f) {\n    seg.build(n, [&](int i) -> S {\n\
    \      auto [x, y] = f(i);\n      return {x, y, infty<T1>, 0};\n    });\n  }\n\
    \n  void set(int i, T1 x, T2 y) { seg.set(i, {x, y, infty<T1>, 0}); }\n\n  //\
    \ (x,y)\n  pair<T1, T2> prod(int l, int r) {\n    auto e = seg.prod(l, r);\n \
    \   return {e.x, e.y};\n  }\n  pair<T1, T2> prod_all() {\n    auto e = seg.prod_all();\n\
    \    return {e.x, e.y};\n  }\n  void apply(int l, int r, T1 a, T2 b) { seg.apply(l,\
    \ r, {a, b}); }\n};\n\n// (x[i],y[i]) \u304B\u3089\u306A\u308B\u5217. a>=0 \u3067\
    \u3042\u308B\u3068\u304D\u306B y[i] :- y[i] + ax[i] + b \u3068\u3044\u3046\u4F5C\
    \u7528\u304C\u3067\u304D\u308B\n// x \u306B\u306F\u5358\u8ABF\u6027\u306F\u8981\
    \u3089\u306A\u3044. x,sum(a):T1, y,sum(b):T2, T1*T1<=T2.\n// https://codeforces.com/blog/entry/82094#comment-688448\n\
    // https://atcoder.jp/contests/jsc2024-final/tasks/jsc2024_final_d\ntemplate <typename\
    \ T1, typename T2>\nstruct Beats_Kinetic_Min {\n  struct Mono_X {\n    struct\
    \ X {\n      T1 x;\n      T2 y;\n      T1 nxt_change;\n      bool fail;\n    };\n\
    \    using value_type = X;\n    static X op(X L, X R) {\n      X M;\n      if\
    \ (L.y > R.y) { swap(L, R); }\n      M.x = L.x, M.y = L.y;\n      M.nxt_change\
    \ = min(L.nxt_change, R.nxt_change);\n      if (L.x > R.x) {\n        T2 t = floor<T2>(R.y\
    \ - L.y, L.x - R.x);\n        chmin(M.nxt_change, t + 1);\n      }\n      M.fail\
    \ = 0;\n      return M;\n    }\n    static constexpr X unit() { return {0, infty<T2>,\
    \ infty<T1>, 0}; }\n    bool commute = true;\n  };\n  struct Mono_A {\n    using\
    \ X = pair<T1, T2>;\n    using value_type = X;\n    static constexpr X op(const\
    \ X& x, const X& y) { return {x.fi + y.fi, x.se + y.se}; }\n    static constexpr\
    \ X unit() { return {0, 0}; }\n    bool commute = true;\n  };\n  struct Beats\
    \ {\n    using Monoid_X = Mono_X;\n    using Monoid_A = Mono_A;\n    using X =\
    \ typename Monoid_X::value_type;\n    using A = typename Monoid_A::value_type;\n\
    \    static X act(X& M, const A& a, int cnt) {\n      assert(!M.fail && a.fi >=\
    \ 0);\n      if (M.nxt_change <= a.fi) {\n        M.fail = 1;\n        return\
    \ M;\n      }\n      M.y += T2(a.fi) * M.x + a.se;\n      M.nxt_change -= a.fi;\n\
    \      return M;\n    }\n  };\n  using S = typename Mono_X::X;\n  SegTree_Beats<Beats>\
    \ seg;\n  Beats_Kinetic_Min(vc<T1>& X, vc<T2>& Y) {\n    seg.build(len(X), [&](int\
    \ i) -> S { return {X[i], Y[i], infty<T1>, 0}; });\n  }\n  template <typename\
    \ F>\n  Beats_Kinetic_Min(int n, F f) {\n    seg.build(n, [&](int i) -> S {\n\
    \      auto [x, y] = f(i);\n      return {x, y, infty<T1>, 0};\n    });\n  }\n\
    \n  void set(int i, T1 x, T2 y) { seg.set(i, {x, y, infty<T1>, 0}); }\n\n  //\
    \ (x,y)\n  pair<T1, T2> prod(int l, int r) {\n    auto e = seg.prod(l, r);\n \
    \   return {e.x, e.y};\n  }\n  pair<T1, T2> prod_all() {\n    auto e = seg.prod_all();\n\
    \    return {e.x, e.y};\n  }\n  void apply(int l, int r, T1 a, T2 b) { seg.apply(l,\
    \ r, {a, b}); }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t\
    \ x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 7 \"test/1_mytest/kinetic.test.cpp\"\n\nvoid test_mi()\
    \ {\n  FOR(N, 1, 100) {\n    vi X(N), Y(N);\n    FOR(i, N) X[i] = RNG(-100, 100);\n\
    \    FOR(i, N) Y[i] = RNG(-100, 100);\n    Beats_Kinetic_Min<ll, ll> seg(N, [&](int\
    \ i) -> pair<int, int> { return {X[i], Y[i]}; });\n    ll Q = 100;\n    FOR(Q)\
    \ {\n      ll t = RNG(0, 3);\n      ll i = RNG(0, N);\n      ll L = RNG(0, N);\n\
    \      ll R = RNG(L, N + 1);\n      ll a = RNG(-100, 100);\n      ll b = RNG(-100,\
    \ 100);\n      if (t == 0) {\n        // set\n        seg.set(i, a, b);\n    \
    \    X[i] = a, Y[i] = b;\n      }\n      if (t == 1) {\n        // apply\n   \
    \     a = abs(a);\n        seg.apply(L, R, a, b);\n        FOR(i, L, R) Y[i] +=\
    \ a * X[i] + b;\n      }\n      if (t == 2) {\n        // prod\n        ll mi\
    \ = infty<ll>;\n        FOR(i, L, R) chmin(mi, Y[i]);\n        auto [x, y] = seg.prod(L,\
    \ R);\n        assert(mi == y);\n      }\n    }\n  }\n}\n\nvoid test_ma() {\n\
    \  FOR(N, 1, 100) {\n    vi X(N), Y(N);\n    FOR(i, N) X[i] = RNG(-100, 100);\n\
    \    FOR(i, N) Y[i] = RNG(-100, 100);\n    Beats_Kinetic_Max<ll, ll> seg(N, [&](int\
    \ i) -> pair<int, int> { return {X[i], Y[i]}; });\n    ll Q = 100;\n    FOR(Q)\
    \ {\n      ll t = RNG(0, 3);\n      ll i = RNG(0, N);\n      ll L = RNG(0, N);\n\
    \      ll R = RNG(L, N + 1);\n      ll a = RNG(-100, 100);\n      ll b = RNG(-100,\
    \ 100);\n      if (t == 0) {\n        // set\n        seg.set(i, a, b);\n    \
    \    X[i] = a, Y[i] = b;\n      }\n      if (t == 1) {\n        // apply\n   \
    \     a = abs(a);\n        seg.apply(L, R, a, b);\n        FOR(i, L, R) Y[i] +=\
    \ a * X[i] + b;\n      }\n      if (t == 2) {\n        // prod\n        ll ma\
    \ = -infty<ll>;\n        FOR(i, L, R) chmax(ma, Y[i]);\n        auto [x, y] =\
    \ seg.prod(L, R);\n        assert(ma == y);\n      }\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  FOR(100) {\n    test_mi();\n    test_ma();\n  }\n  solve();\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"ds/segtree/beats_kinetic.hpp\"\n#include\
    \ \"random/base.hpp\"\n\nvoid test_mi() {\n  FOR(N, 1, 100) {\n    vi X(N), Y(N);\n\
    \    FOR(i, N) X[i] = RNG(-100, 100);\n    FOR(i, N) Y[i] = RNG(-100, 100);\n\
    \    Beats_Kinetic_Min<ll, ll> seg(N, [&](int i) -> pair<int, int> { return {X[i],\
    \ Y[i]}; });\n    ll Q = 100;\n    FOR(Q) {\n      ll t = RNG(0, 3);\n      ll\
    \ i = RNG(0, N);\n      ll L = RNG(0, N);\n      ll R = RNG(L, N + 1);\n     \
    \ ll a = RNG(-100, 100);\n      ll b = RNG(-100, 100);\n      if (t == 0) {\n\
    \        // set\n        seg.set(i, a, b);\n        X[i] = a, Y[i] = b;\n    \
    \  }\n      if (t == 1) {\n        // apply\n        a = abs(a);\n        seg.apply(L,\
    \ R, a, b);\n        FOR(i, L, R) Y[i] += a * X[i] + b;\n      }\n      if (t\
    \ == 2) {\n        // prod\n        ll mi = infty<ll>;\n        FOR(i, L, R) chmin(mi,\
    \ Y[i]);\n        auto [x, y] = seg.prod(L, R);\n        assert(mi == y);\n  \
    \    }\n    }\n  }\n}\n\nvoid test_ma() {\n  FOR(N, 1, 100) {\n    vi X(N), Y(N);\n\
    \    FOR(i, N) X[i] = RNG(-100, 100);\n    FOR(i, N) Y[i] = RNG(-100, 100);\n\
    \    Beats_Kinetic_Max<ll, ll> seg(N, [&](int i) -> pair<int, int> { return {X[i],\
    \ Y[i]}; });\n    ll Q = 100;\n    FOR(Q) {\n      ll t = RNG(0, 3);\n      ll\
    \ i = RNG(0, N);\n      ll L = RNG(0, N);\n      ll R = RNG(L, N + 1);\n     \
    \ ll a = RNG(-100, 100);\n      ll b = RNG(-100, 100);\n      if (t == 0) {\n\
    \        // set\n        seg.set(i, a, b);\n        X[i] = a, Y[i] = b;\n    \
    \  }\n      if (t == 1) {\n        // apply\n        a = abs(a);\n        seg.apply(L,\
    \ R, a, b);\n        FOR(i, L, R) Y[i] += a * X[i] + b;\n      }\n      if (t\
    \ == 2) {\n        // prod\n        ll ma = -infty<ll>;\n        FOR(i, L, R)\
    \ chmax(ma, Y[i]);\n        auto [x, y] = seg.prod(L, R);\n        assert(ma ==\
    \ y);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n\
    \  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(100) {\n    test_mi();\n\
    \    test_ma();\n  }\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree/beats_kinetic.hpp
  - ds/segtree/segtree_beats.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/1_mytest/kinetic.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 04:06:11+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/kinetic.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/kinetic.test.cpp
- /verify/test/1_mytest/kinetic.test.cpp.html
title: test/1_mytest/kinetic.test.cpp
---
