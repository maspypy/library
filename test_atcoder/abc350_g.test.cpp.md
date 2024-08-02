---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/ds/lct_node_base.hpp
    title: graph/ds/lct_node_base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/link_cut_tree.hpp
    title: graph/ds/link_cut_tree.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc350/tasks/abc350_g
    links:
    - https://atcoder.jp/contests/abc350/tasks/abc350_g
  bundledCode: "#line 1 \"test_atcoder/abc350_g.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc350/tasks/abc350_g\"\
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
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
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
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvc<T> concat(vc<T>\
    \ &first, const Vectors &... others) {\n  vc<T> res = first;\n  (res.insert(res.end(),\
    \ others.begin(), others.end()), ...);\n  return res;\n}\n#endif\n#line 1 \"other/io.hpp\"\
    \n#define FASTIO\r\n#include <unistd.h>\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\
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
    using fastio::flush;\r\n\r\n#if defined(LOCAL)\r\n#define SHOW(...) \\\r\n  SHOW_IMPL(__VA_ARGS__,\
    \ SHOW4, SHOW3, SHOW2, SHOW1)(__VA_ARGS__)\r\n#define SHOW_IMPL(_1, _2, _3, _4,\
    \ NAME, ...) NAME\r\n#define SHOW1(x) print(#x, \"=\", (x)), flush()\r\n#define\
    \ SHOW2(x, y) print(#x, \"=\", (x), #y, \"=\", (y)), flush()\r\n#define SHOW3(x,\
    \ y, z) print(#x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z)), flush()\r\n#define\
    \ SHOW4(x, y, z, w) \\\r\n  print(#x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z),\
    \ #w, \"=\", (w)), flush()\r\n#else\r\n#define SHOW(...)\r\n#endif\r\n\r\n#define\
    \ INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)\
    \   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define U32(...)   \\\
    \r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define U64(...)   \\\r\n\
    \  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n\
    \  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)   \\\r\n\
    \  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n\
    \  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name,\
    \ size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type,\
    \ name, h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"\
    ); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"\
    Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1)\
    \ { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\r\n#line\
    \ 4 \"test_atcoder/abc350_g.test.cpp\"\n\n#line 1 \"graph/ds/link_cut_tree.hpp\"\
    \n/*\n\u5404 heavy path \u3092 head \u304C\u5DE6, tail \u304C\u53F3\u3068\u306A\
    \u308B\u3088\u3046\u306B splay tree \u3067\u6301\u3064.\n\u30E6\u30FC\u30B6\u30FC\
    \u304C\u76F4\u63A5\u547C\u3076\u53EF\u80FD\u6027\u304C\u3042\u308B\u3082\u306E\
    \u3060\u3051 int \u3067\u3082\u5B9F\u88C5.\nLCT \u5916\u3067\u63A2\u7D22\u3059\
    \u308B\u3068\u304D\u306A\u3069\uFF0Cpush \u3092\u5FD8\u308C\u306A\u3044\u3088\u3046\
    \u306B\u6CE8\u610F.\n*/\n\ntemplate <typename Node>\nstruct Link_Cut_Tree {\n\
    \  using np = Node *;\n  int n;\n  vc<Node> nodes;\n\n  Link_Cut_Tree(int n =\
    \ 0) : n(n), nodes(n) { FOR(i, n) nodes[i] = Node(i); }\n\n  Node *operator[](int\
    \ v) { return &nodes[v]; }\n\n  // underlying tree \u306E\u6839\n  Node *get_root(Node\
    \ *c) {\n    expose(c);\n    c->push();\n    while (c->l) {\n      c = c->l;\n\
    \      c->push();\n    }\n    splay(c);\n    return c;\n  }\n\n  // underlying\
    \ tree \u306E\u6839\n  int get_root(int c) { return get_root(&nodes[c])->idx;\
    \ }\n\n  // parent(c)==p \u3068\u306A\u308B\u3088\u3046\u306B link.\n  void link(Node\
    \ *c, Node *p) {\n    evert(c);\n    expose(p);\n    p->push();\n    // no edge\
    \ -> heavy edge\n    assert(!(c->p));\n    assert(!(p->r));\n    c->p = p;\n \
    \   p->r = c;\n    p->update();\n  }\n\n  // parent(c)==p \u3068\u306A\u308B\u3088\
    \u3046\u306B link.\n  void link(int c, int p) { return link(&nodes[c], &nodes[p]);\
    \ }\n\n  void cut(Node *a, Node *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n\
    \    assert((b->l) == a);\n    // heavy edge -> no edge\n    b->l->p = nullptr;\n\
    \    b->l = nullptr;\n    b->update();\n  }\n\n  void cut(int a, int b) { return\
    \ cut(&nodes[a], &nodes[b]); }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\
    \u3059\u308B.\n  // c \u306F splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n\
    \  // c \u306F push \u6E08\u306B\u306A\u308B\n  void evert(Node *c) {\n    expose(c);\n\
    \    c->reverse();\n    c->push();\n  }\n\n  // c \u3092 underlying tree \u306E\
    \u6839\u3068\u3059\u308B.\n  // c \u306F splay tree \u306E\u6839\u306B\u3082\u306A\
    \u308B.\n  void evert(int c) { evert(&nodes[c]); }\n\n  Node *lca(Node *u, Node\
    \ *v) {\n    assert(get_root(u) == get_root(v));\n    expose(u);\n    return expose(v);\n\
    \  }\n\n  int lca(int u, int v) { return lca(&nodes[u], &nodes[v])->idx; }\n\n\
    \  // \u8FBA\u306E\u500B\u6570\n  int dist(int u, int v) {\n    evert(u), expose(v);\n\
    \    return ((*this)[v]->size) - 1;\n  }\n\n  Node *jump(Node *u, Node *v, int\
    \ k) {\n    evert(v);\n    expose(u);\n    assert(0 <= k && k < (u->size));\n\
    \    while (1) {\n      u->push();\n      int rs = (u->r ? u->r->size : 0);\n\
    \      if (k < rs) {\n        u = u->r;\n        continue;\n      }\n      if\
    \ (k == rs) { break; }\n      k -= rs + 1;\n      u = u->l;\n    }\n    splay(u);\n\
    \    return u;\n  }\n\n  int jump(int u, int v, int k) {\n    auto c = jump((*this)[u],\
    \ (*this)[v], k);\n    return c->idx;\n  }\n\n  // [root, c] \u304C\u3072\u3068\
    \u3064\u306E splay tree \u306B\u306A\u308B\u3088\u3046\u306B\u5909\u66F4\u3059\
    \u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree \u306E\u6839\u3068\u3044\u3046\
    \u72B6\u614B\u306B\u306A\u308B.\n  // path query \u306F\u3053\u306E\u72B6\u614B\
    \u3067 c \u306E data \u3092\u898B\u308B.\n  // c \u306F push \u6E08\u306B\u306A\
    \u308B\n  virtual Node *expose(Node *c) {\n    Node *now = c;\n    Node *rp =\
    \ nullptr; // \u4ECA\u307E\u3067\u4F5C\u3063\u305F\u30D1\u30B9\n    while (now)\
    \ {\n      splay(now);\n      // heavy -> light, light -> heavy.\n      if (now->r)\
    \ { now->add_light(now->r); }\n      if (rp) { now->erase_light(rp); }\n     \
    \ now->r = rp;\n      now->update();\n      rp = now;\n      now = now->p;\n \
    \   }\n    splay(c);\n    return rp;\n  }\n\n  // [root, c] \u304C\u3072\u3068\
    \u3064\u306E splay tree \u306B\u306A\u308B\u3088\u3046\u306B\u5909\u66F4\u3059\
    \u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree \u306E\u6839\u3068\u3044\u3046\
    \u72B6\u614B\u306B\u306A\u308B.\n  // path query \u306F\u3053\u306E\u72B6\u614B\
    \u3067 c \u306E data \u3092\u898B\u308B.\n  int expose(int c) {\n    Node *x =\
    \ expose(&nodes[c]);\n    if (!x) return -1;\n    return x->idx;\n  }\n\n  Node\
    \ *get_parent(Node *x) {\n    expose(x);\n    if (!x->l) return nullptr;\n   \
    \ x = x->l;\n    while (x->r) x = x->r;\n    return x;\n  }\n\n  int get_parent(int\
    \ x) {\n    Node *p = get_parent((*this)[x]);\n    return (p ? p->idx : -1);\n\
    \  }\n\n  void set(Node *c, typename Node::VX x) {\n    evert(c);\n    c->set(x);\n\
    \  }\n\n  void set(int c, typename Node::VX x) { set((*this)[c], x); }\n\n  typename\
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
    \ -> int { return (c ? c->idx : -1); };\n    FOR(i, len(nodes)) {\n      print(i,\
    \ \",\", f((*this)[i]->p), f((*this)[i]->l), f((*this)[i]->r),\n            (*this)[i]->rev);\n\
    \    }\n    FOR(i, len(nodes)) {\n      np c = (*this)[i];\n      if (c->l) assert(c->l->p\
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
    \ n) return -1;\n    return 0;\n  }\n};\n#line 1 \"graph/ds/lct_node_base.hpp\"\
    \n// SUBTREE : cluster \u304C subtree \u60C5\u5831\u3092\u6301\u3064\u5834\u5408\
    \nstruct LCT_Node_Base {\n  using np = LCT_Node_Base*;\n  // \u30C7\u30D5\u30A9\
    \u30EB\u30C8\n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\
    \u9802\u70B9\u6570\n  bool rev;\n  using X = int;\n  using VX = int;\n\n  LCT_Node_Base(int\
    \ i = 0)\n      : l(nullptr), r(nullptr), p(nullptr), idx(i), size(1), rev(0)\
    \ {}\n\n  void update() {\n    size = 1;\n    if (l) { size += l->size; }\n  \
    \  if (r) { size += r->size; }\n  }\n\n  void push() {\n    if (rev) {\n     \
    \ if (l) l->reverse();\n      if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\
    \n  // data \u306E reverse \u3082\u884C\u3046\n  void reverse() {\n    rev ^=\
    \ 1;\n    swap(l, r);\n  }\n\n  // LCT \u5185\u3067 expose, update \u3092\u884C\
    \u3046\u306E\u3067\u3053\u3053\u306F\u5909\u66F4\u3060\u3051\n  void set(VX x)\
    \ {}\n\n  void add_light(np c) {}\n  void erase_light(np c) {}\n\n  // b->x \u306B\
    \ subtree value \u304C\u5165\u3063\u3066\u3044\u308B.\n  void change_light(np\
    \ a, np b) {}\n};\n#line 7 \"test_atcoder/abc350_g.test.cpp\"\n\nusing Node =\
    \ LCT_Node_Base;\nvoid solve() {\n  LL(N, Q);\n  Link_Cut_Tree<Node> LCT(N);\n\
    \n  ll X = 0;\n\n  FOR(Q) {\n    LL(a, b, c);\n    ll A = 1 + ((a * (1 + X)) %\
    \ 998244353) % 2;\n    ll B = 1 + ((b * (1 + X)) % 998244353) % N;\n    ll C =\
    \ 1 + ((c * (1 + X)) % 998244353) % N;\n    // print(A, B, C);\n    if (A == 1)\
    \ {\n      ll u = B, v = C;\n      --u, --v;\n      LCT.link(u, v);\n    }\n \
    \   if (A == 2) {\n      ll u = B, v = C;\n      --u, --v;\n      ll ans = [&]()\
    \ -> ll {\n        if (LCT.get_root(u) != LCT.get_root(v)) { return 0; }\n   \
    \     ll x = LCT.jump(u, v, 1);\n        ll y = LCT.jump(v, u, 1);\n        if\
    \ (x != y) return 0;\n        return 1 + x;\n      }();\n      print(ans);\n \
    \     X = ans;\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc350/tasks/abc350_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/ds/link_cut_tree.hpp\"\
    \n#include \"graph/ds/lct_node_base.hpp\"\n\nusing Node = LCT_Node_Base;\nvoid\
    \ solve() {\n  LL(N, Q);\n  Link_Cut_Tree<Node> LCT(N);\n\n  ll X = 0;\n\n  FOR(Q)\
    \ {\n    LL(a, b, c);\n    ll A = 1 + ((a * (1 + X)) % 998244353) % 2;\n    ll\
    \ B = 1 + ((b * (1 + X)) % 998244353) % N;\n    ll C = 1 + ((c * (1 + X)) % 998244353)\
    \ % N;\n    // print(A, B, C);\n    if (A == 1) {\n      ll u = B, v = C;\n  \
    \    --u, --v;\n      LCT.link(u, v);\n    }\n    if (A == 2) {\n      ll u =\
    \ B, v = C;\n      --u, --v;\n      ll ans = [&]() -> ll {\n        if (LCT.get_root(u)\
    \ != LCT.get_root(v)) { return 0; }\n        ll x = LCT.jump(u, v, 1);\n     \
    \   ll y = LCT.jump(v, u, 1);\n        if (x != y) return 0;\n        return 1\
    \ + x;\n      }();\n      print(ans);\n      X = ans;\n    }\n  }\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/ds/link_cut_tree.hpp
  - graph/ds/lct_node_base.hpp
  isVerificationFile: true
  path: test_atcoder/abc350_g.test.cpp
  requiredBy: []
  timestamp: '2024-07-22 11:16:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_atcoder/abc350_g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc350_g.test.cpp
- /verify/test_atcoder/abc350_g.test.cpp.html
title: test_atcoder/abc350_g.test.cpp
---