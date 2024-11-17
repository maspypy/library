---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/lct_node_monoid.hpp
    title: graph/ds/lct_node_monoid.hpp
  - icon: ':question:'
    path: graph/ds/link_cut_tree.hpp
    title: graph/ds/link_cut_tree.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite
  bundledCode: "#line 1 \"test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
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
    \ yes(!t); }\r\n#line 5 \"test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n\n#line 1 \"graph/ds/link_cut_tree.hpp\"\n/*\n\u5404 heavy path \u3092 head\
    \ \u304C\u5DE6, tail \u304C\u53F3\u3068\u306A\u308B\u3088\u3046\u306B splay tree\
    \ \u3067\u6301\u3064.\n\u30E6\u30FC\u30B6\u30FC\u304C\u76F4\u63A5\u547C\u3076\u53EF\
    \u80FD\u6027\u304C\u3042\u308B\u3082\u306E\u3060\u3051 int \u3067\u3082\u5B9F\u88C5\
    .\nLCT \u5916\u3067\u63A2\u7D22\u3059\u308B\u3068\u304D\u306A\u3069\uFF0Cpush\
    \ \u3092\u5FD8\u308C\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F.\n*/\n\ntemplate\
    \ <typename Node>\nstruct Link_Cut_Tree {\n  using np = Node *;\n  int n;\n  vc<Node>\
    \ nodes;\n\n  Link_Cut_Tree(int n = 0) : n(n), nodes(n) { FOR(i, n) nodes[i] =\
    \ Node(i); }\n\n  Node *operator[](int v) { return &nodes[v]; }\n\n  // underlying\
    \ tree \u306E\u6839\n  Node *get_root(Node *c) {\n    expose(c);\n    c->push();\n\
    \    while (c->l) {\n      c = c->l;\n      c->push();\n    }\n    splay(c);\n\
    \    return c;\n  }\n\n  // underlying tree \u306E\u6839\n  int get_root(int c)\
    \ { return get_root(&nodes[c])->idx; }\n\n  // parent(c)==p \u3068\u306A\u308B\
    \u3088\u3046\u306B link.\n  void link(Node *c, Node *p) {\n    evert(c);\n   \
    \ expose(p);\n    p->push();\n    // no edge -> heavy edge\n    assert(!(c->p));\n\
    \    assert(!(p->r));\n    c->p = p;\n    p->r = c;\n    p->update();\n  }\n\n\
    \  // parent(c)==p \u3068\u306A\u308B\u3088\u3046\u306B link.\n  void link(int\
    \ c, int p) { return link(&nodes[c], &nodes[p]); }\n\n  void cut(Node *a, Node\
    \ *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n    assert((b->l)\
    \ == a);\n    // heavy edge -> no edge\n    b->l->p = nullptr;\n    b->l = nullptr;\n\
    \    b->update();\n  }\n\n  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]);\
    \ }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\u3059\u308B.\n  // c \u306F\
    \ splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n  // c \u306F push \u6E08\u306B\
    \u306A\u308B\n  void evert(Node *c) {\n    expose(c);\n    c->reverse();\n   \
    \ c->push();\n  }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\u3059\u308B\
    .\n  // c \u306F splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n  void evert(int\
    \ c) { evert(&nodes[c]); }\n\n  Node *lca(Node *u, Node *v) {\n    assert(get_root(u)\
    \ == get_root(v));\n    expose(u);\n    return expose(v);\n  }\n\n  int lca(int\
    \ u, int v) { return lca(&nodes[u], &nodes[v])->idx; }\n\n  // \u8FBA\u306E\u500B\
    \u6570\n  int dist(int u, int v) {\n    evert(u), expose(v);\n    return ((*this)[v]->size)\
    \ - 1;\n  }\n\n  Node *jump(Node *u, Node *v, int k) {\n    evert(v);\n    expose(u);\n\
    \    assert(0 <= k && k < (u->size));\n    while (1) {\n      u->push();\n   \
    \   int rs = (u->r ? u->r->size : 0);\n      if (k < rs) {\n        u = u->r;\n\
    \        continue;\n      }\n      if (k == rs) { break; }\n      k -= rs + 1;\n\
    \      u = u->l;\n    }\n    splay(u);\n    return u;\n  }\n\n  int jump(int u,\
    \ int v, int k) {\n    auto c = jump((*this)[u], (*this)[v], k);\n    return c->idx;\n\
    \  }\n\n  // [root, c] \u304C\u3072\u3068\u3064\u306E splay tree \u306B\u306A\u308B\
    \u3088\u3046\u306B\u5909\u66F4\u3059\u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay\
    \ tree \u306E\u6839\u3068\u3044\u3046\u72B6\u614B\u306B\u306A\u308B.\n  // path\
    \ query \u306F\u3053\u306E\u72B6\u614B\u3067 c \u306E data \u3092\u898B\u308B\
    .\n  // c \u306F push \u6E08\u306B\u306A\u308B\n  virtual Node *expose(Node *c)\
    \ {\n    Node *now = c;\n    Node *rp = nullptr; // \u4ECA\u307E\u3067\u4F5C\u3063\
    \u305F\u30D1\u30B9\n    while (now) {\n      splay(now);\n      // heavy -> light,\
    \ light -> heavy.\n      if (now->r) { now->add_light(now->r); }\n      if (rp)\
    \ { now->erase_light(rp); }\n      now->r = rp;\n      now->update();\n      rp\
    \ = now;\n      now = now->p;\n    }\n    splay(c);\n    return rp;\n  }\n\n \
    \ // [root, c] \u304C\u3072\u3068\u3064\u306E splay tree \u306B\u306A\u308B\u3088\
    \u3046\u306B\u5909\u66F4\u3059\u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree\
    \ \u306E\u6839\u3068\u3044\u3046\u72B6\u614B\u306B\u306A\u308B.\n  // path query\
    \ \u306F\u3053\u306E\u72B6\u614B\u3067 c \u306E data \u3092\u898B\u308B.\n  int\
    \ expose(int c) {\n    Node *x = expose(&nodes[c]);\n    if (!x) return -1;\n\
    \    return x->idx;\n  }\n\n  Node *get_parent(Node *x) {\n    expose(x);\n  \
    \  x->push();\n    if (!x->l) return nullptr;\n    x = x->l, x->push();\n    while\
    \ (x->r) x = x->r, x->push();\n    return x;\n  }\n\n  int get_parent(int x) {\n\
    \    Node *p = get_parent((*this)[x]);\n    return (p ? p->idx : -1);\n  }\n\n\
    \  void set(Node *c, typename Node::VX x) {\n    evert(c);\n    c->set(x);\n \
    \ }\n\n  void set(int c, typename Node::VX x) { set((*this)[c], x); }\n\n  typename\
    \ Node::X prod_path(int a, int b) {\n    evert(a), expose(b);\n    return (*this)[b]->x;\n\
    \  }\n\n  // subtree \u7528\u306E node \u3092\u4F7F\u3046\n  typename Node::X\
    \ prod_subtree(int v, int root) {\n    static_assert(Node::NODE_FOR_SUBTREE);\n\
    \    if (v == root) {\n      evert(root);\n      return (*this)[root]->x;\n  \
    \  }\n    root = jump(v, root, 1);\n    cut(v, root);\n    typename Node::X res\
    \ = (*this)[v]->x;\n    link(v, root);\n    return res;\n  }\n\n  vc<int> collect_heavy_path(int\
    \ v) {\n    np c = (*this)[v];\n    while (!is_root(c)) c = c->p;\n    vc<int>\
    \ res;\n    auto dfs = [&](auto &dfs, np c, bool rev) -> void {\n      if (!rev)\
    \ {\n        if (c->l) dfs(dfs, c->l, rev ^ c->rev);\n        res.eb(c->idx);\n\
    \        if (c->r) dfs(dfs, c->r, rev ^ c->rev);\n      } else {\n        if (c->r)\
    \ dfs(dfs, c->r, rev ^ c->rev);\n        res.eb(c->idx);\n        if (c->l) dfs(dfs,\
    \ c->l, rev ^ c->rev);\n      }\n    };\n    dfs(dfs, c, false);\n    return res;\n\
    \  }\n\n  void debug() {\n    print(\"p, l, r, rev\");\n    auto f = [&](np c)\
    \ -> int { return (c ? c->idx : -1); };\n    FOR(i, len(nodes)) { print(i, \"\
    ,\", f((*this)[i]->p), f((*this)[i]->l), f((*this)[i]->r), (*this)[i]->rev); }\n\
    \    FOR(i, len(nodes)) {\n      np c = (*this)[i];\n      if (c->l) assert(c->l->p\
    \ == c);\n      if (c->r) assert(c->r->p == c);\n    }\n  }\n\nprivate:\n  //\
    \ splay tree \u5185\u3067\u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy,\
    \ light \u69CB\u9020\u306F\u5909\u308F\u3089\u306A\u3044.\n  // light pointer\
    \ \u306F rotate \u5185\u3067\u30B1\u30A2\n  // c \u306F push \u6E08\u306B\u306A\
    \u308B\n  void splay(Node *c) {\n    c->push();\n    while (!is_root(c)) {\n \
    \     Node *p = c->p;\n      Node *pp = (p ? p->p : nullptr);\n      if (state(p)\
    \ == 0) {\n        p->push(), c->push();\n        rotate(c);\n      }\n      elif\
    \ (state(c) == state(p)) {\n        pp->push(), p->push(), c->push();\n      \
    \  rotate(p);\n        rotate(c);\n      }\n      else {\n        pp->push(),\
    \ p->push(), c->push();\n        rotate(c);\n        rotate(c);\n      }\n   \
    \ }\n  }\n\n  // \u30D1\u30B9\u3092\u8868\u3059 splay tree \u306E\u6839\u306B\u306A\
    \u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n  // underlying tree \u3067\u306F\
    \u306A\u3044\n  bool is_root(Node *c) { return state(c) == 0; }\n\n  // splay\
    \ tree \u5185\u3067\u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy, light\
    \ \u69CB\u9020\u306F\u5909\u308F\u3089\u306A\u3044.\n  // light edge \u306E\u30DD\
    \u30A4\u30F3\u30BF\u306F\u5909\u66F4\u3055\u308C\u3046\u308B\n  void rotate(Node\
    \ *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\n    Node *pp, *p,\
    \ *c;\n    p = n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n\
    \      n->r = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l =\
    \ p;\n      p->r = c;\n    }\n    p->update(), n->update();\n\n    if (pp) {\n\
    \      if (pp->l == p) pp->l = n;\n      elif (pp->r == p) pp->r = n;\n      else\
    \ {\n        // light edge pointer \u304C (pp-p) \u304B\u3089 (pp-n) \u306B\u5909\
    \u308F\u308B\n        pp->change_light(p, n);\n      }\n    }\n    n->p = pp;\n\
    \    p->p = n;\n    if (c) c->p = p;\n  }\n\n  inline int state(Node *n) {\n \
    \   if (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r ==\
    \ n) return -1;\n    return 0;\n  }\n};\n#line 1 \"graph/ds/lct_node_monoid.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct LCT_Node_Monoid {\n  using np = LCT_Node_Monoid\
    \ *;\n  // \u30C7\u30D5\u30A9\u30EB\u30C8\n  np l, r, p;\n  int idx, size; //\
    \ size \u306F heavy path \u306E\u9802\u70B9\u6570\n  bool rev;\n  // \u76EE\u7684\
    \u3054\u3068\u306B\u5B9A\u7FA9\u3059\u308B.\n  using MX = Monoid;\n  using X =\
    \ typename MX::value_type;\n  using VX = X;\n\n  X x, rx, vx;\n\n  LCT_Node_Monoid(int\
    \ i = 0)\n      : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n    \
    \    idx(i),\n        size(1),\n        rev(0),\n        x(MX::unit()),\n    \
    \    rx(MX::unit()),\n        vx(MX::unit()) {}\n\n  void update() {\n    size\
    \ = 1;\n    x = vx, rx = vx;\n    if (l) {\n      size += l->size, x = Monoid::op(l->x,\
    \ x), rx = Monoid::op(rx, l->rx);\n    }\n    if (r) {\n      size += r->size,\
    \ x = Monoid::op(x, r->x), rx = Monoid::op(r->rx, rx);\n    }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  // data \u306E reverse \u3082\u884C\u3046\n \
    \ void reverse() {\n    rev ^= 1;\n    swap(l, r);\n    swap(x, rx);\n  }\n\n\
    \  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\
    \u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) { vx = x; }\n\n  void add_light(np\
    \ c) {}\n  void erase_light(np c) {}\n  void change_light(np a, np b) {}\n};\n\
    #line 2 \"alg/monoid/affine.hpp\"\n\n// op(F, G) = comp(G,F), F \u306E\u3042\u3068\
    \u3067 G\ntemplate <typename K>\nstruct Monoid_Affine {\n  using F = pair<K, K>;\n\
    \  using value_type = F;\n  using X = value_type;\n  static constexpr F op(const\
    \ F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second * y.first\
    \ + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n    auto [a,\
    \ b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static constexpr\
    \ K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n  }\n\
    \  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr bool\
    \ commute = false;\n};\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n  static\
    \ const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static vector<mint>\
    \ dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1] * mint::raw(len(dat)));\n\
    \  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  static\
    \ vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while (len(dat)\
    \ <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n}\n\
    \ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return (mint(1)\
    \ * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head, class...\
    \ Tail>\nmint multinomial(Head &&head, Tail &&... tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) { return (d == 0 ? mint(1)\
    \ : mint(0)); }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"\
    mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr u32\
    \ umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n  static\
    \ modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n  }\n  constexpr\
    \ modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod) {}\n  constexpr\
    \ modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x) : val(x % umod)\
    \ {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr\
    \ modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(i128\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const modint &other)\
    \ const { return val < other.val; }\n  modint &operator+=(const modint &p) {\n\
    \    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint &p) {\n    if ((val += umod - p.val) >= umod) val -=\
    \ umod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n   \
    \ val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint::raw(val ? mod - val : u32(0)); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  modint inverse() const {\n    int a = val, b = mod, u = 1, v = 0, t;\n\
    \    while (b > 0) {\n      t = a / b;\n      swap(a -= t * b, b), swap(u -= t\
    \ * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll n) const {\n  \
    \  assert(n >= 0);\n    modint ret(1), mul(val);\n    while (n > 0) {\n      if\
    \ (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n\
    \  }\n  static constexpr int get_mod() { return mod; }\n  // (n, r), r \u306F\
    \ 1 \u306E 2^n \u4E57\u6839\n  static constexpr pair<int, int> ntt_info() {\n\
    \    if (mod == 120586241) return {20, 74066978};\n    if (mod == 167772161) return\
    \ {25, 17};\n    if (mod == 469762049) return {26, 30};\n    if (mod == 754974721)\
    \ return {24, 362};\n    if (mod == 880803841) return {23, 211};\n    if (mod\
    \ == 943718401) return {22, 663003469};\n    if (mod == 998244353) return {23,\
    \ 31};\n    if (mod == 1004535809) return {21, 582313106};\n    if (mod == 1012924417)\
    \ return {21, 368093570};\n    return {-1, -1};\n  }\n  static constexpr bool\
    \ can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int\
    \ mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  //\
    \ assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 10 \"test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp\"\
    \n\nusing mint = modint998;\n\nusing Mono = Monoid_Affine<mint>;\nusing Node =\
    \ LCT_Node_Monoid<Mono>;\n\nvoid solve() {\n  LL(N, Q);\n  Link_Cut_Tree<Node>\
    \ LCT(N);\n  FOR(i, N) {\n    mint a, b;\n    read(a, b);\n    LCT.set(i, {a,\
    \ b});\n  }\n  FOR(N - 1) {\n    INT(a, b);\n    LCT.link(a, b);\n  }\n\n  FOR(Q)\
    \ {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n      LCT.cut(a, b),\
    \ LCT.link(c, d);\n    }\n    if (t == 1) {\n      LL(i);\n      mint a, b;\n\
    \      read(a, b);\n      LCT.set(i, {a, b});\n    }\n    if (t == 2) {\n    \
    \  LL(a, b);\n      auto f = LCT.prod_path(a, b);\n      u32 x;\n      read(x);\n\
    \      mint ans = Mono::eval(f, mint::raw(x));\n      print(ans);\n    }\n  }\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/ds/link_cut_tree.hpp\"\
    \n#include \"graph/ds/lct_node_monoid.hpp\"\n#include \"alg/monoid/affine.hpp\"\
    \n#include \"mod/modint.hpp\"\n\nusing mint = modint998;\n\nusing Mono = Monoid_Affine<mint>;\n\
    using Node = LCT_Node_Monoid<Mono>;\n\nvoid solve() {\n  LL(N, Q);\n  Link_Cut_Tree<Node>\
    \ LCT(N);\n  FOR(i, N) {\n    mint a, b;\n    read(a, b);\n    LCT.set(i, {a,\
    \ b});\n  }\n  FOR(N - 1) {\n    INT(a, b);\n    LCT.link(a, b);\n  }\n\n  FOR(Q)\
    \ {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n      LCT.cut(a, b),\
    \ LCT.link(c, d);\n    }\n    if (t == 1) {\n      LL(i);\n      mint a, b;\n\
    \      read(a, b);\n      LCT.set(i, {a, b});\n    }\n    if (t == 2) {\n    \
    \  LL(a, b);\n      auto f = LCT.prod_path(a, b);\n      u32 x;\n      read(x);\n\
    \      mint ans = Mono::eval(f, mint::raw(x));\n      print(ans);\n    }\n  }\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/ds/link_cut_tree.hpp
  - graph/ds/lct_node_monoid.hpp
  - alg/monoid/affine.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2024-11-16 23:01:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
- /verify/test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp.html
title: test/2_library_checker/tree/dynamic_tree_vertex_set_path_composite.test.cpp
---
