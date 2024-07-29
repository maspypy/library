---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/sortable_segtree.hpp
    title: ds/segtree/sortable_segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_sort_range_composite
  bundledCode: "#line 1 \"test/library_checker/datastructure/sort_segtree_1.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
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
    \ 2 \"ds/fastset.hpp\"\n\r\n// 64-ary tree\r\n// space: (N/63) * u64\r\nstruct\
    \ FastSet {\r\n  static constexpr u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\
    \n\r\n  FastSet() {}\r\n  FastSet(int n) { build(n); }\r\n\r\n  int size() { return\
    \ n; }\r\n\r\n  template <typename F>\r\n  FastSet(int n, F f) {\r\n    build(n,\
    \ f);\r\n  }\r\n\r\n  void build(int m) {\r\n    seg.clear();\r\n    n = m;\r\n\
    \    do {\r\n      seg.push_back(vc<u64>((m + B - 1) / B));\r\n      m = (m +\
    \ B - 1) / B;\r\n    } while (m > 1);\r\n    log = len(seg);\r\n  }\r\n  template\
    \ <typename F>\r\n  void build(int n, F f) {\r\n    build(n);\r\n    FOR(i, n)\
    \ { seg[0][i / B] |= u64(f(i)) << (i % B); }\r\n    FOR(h, log - 1) {\r\n    \
    \  FOR(i, len(seg[h])) {\r\n        seg[h + 1][i / B] |= u64(bool(seg[h][i]))\
    \ << (i % B);\r\n      }\r\n    }\r\n  }\r\n\r\n  bool operator[](int i) const\
    \ { return seg[0][i / B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\n    for\
    \ (int h = 0; h < log; h++) {\r\n      seg[h][i / B] |= u64(1) << (i % B), i /=\
    \ B;\r\n    }\r\n  }\r\n  void add(int i) { insert(i); }\r\n  void erase(int i)\
    \ {\r\n    u64 x = 0;\r\n    for (int h = 0; h < log; h++) {\r\n      seg[h][i\
    \ / B] &= ~(u64(1) << (i % B));\r\n      seg[h][i / B] |= x << (i % B);\r\n  \
    \    x = bool(seg[h][i / B]);\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int\
    \ i) { erase(i); }\r\n\r\n  // min[x,n) or n\r\n  int next(int i) {\r\n    assert(i\
    \ <= n);\r\n    chmax(i, 0);\r\n    for (int h = 0; h < log; h++) {\r\n      if\
    \ (i / B == seg[h].size()) break;\r\n      u64 d = seg[h][i / B] >> (i % B);\r\
    \n      if (!d) {\r\n        i = i / B + 1;\r\n        continue;\r\n      }\r\n\
    \      i += lowbit(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n       \
    \ i *= B;\r\n        i += lowbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\
    \n    }\r\n    return n;\r\n  }\r\n\r\n  // max [0,x], or -1\r\n  int prev(int\
    \ i) {\r\n    assert(i >= -1);\r\n    if (i >= n) i = n - 1;\r\n    for (int h\
    \ = 0; h < log; h++) {\r\n      if (i == -1) break;\r\n      u64 d = seg[h][i\
    \ / B] << (63 - i % B);\r\n      if (!d) {\r\n        i = i / B - 1;\r\n     \
    \   continue;\r\n      }\r\n      i -= __builtin_clzll(d);\r\n      for (int g\
    \ = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i += topbit(seg[g][i /\
    \ B]);\r\n      }\r\n      return i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n\
    \  bool any(int l, int r) { return next(l) < r; }\r\n\r\n  // [l, r)\r\n  template\
    \ <typename F>\r\n  void enumerate(int l, int r, F f) {\r\n    for (int x = next(l);\
    \ x < r; x = next(x + 1)) f(x);\r\n  }\r\n\r\n  string to_string() {\r\n    string\
    \ s(n, '?');\r\n    for (int i = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\
    \n    return s;\r\n  }\r\n};\n#line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class\
    \ Monoid>\nstruct SegTree {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n\
    \  SegTree(int n) { build(n); }\n  template <typename F>\n  SegTree(int n, F f)\
    \ {\n    build(n, f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n\
    \  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m, log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::unit());\n    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size)\
    \ update(i);\n  }\n\n  X get(int i) { return dat[size + i]; }\n  vc<X> get_all()\
    \ { return {dat.begin() + size, dat.begin() + size + n}; }\n\n  void update(int\
    \ i) { dat[i] = Monoid::op(dat[2 * i], dat[2 * i + 1]); }\n  void set(int i, const\
    \ X& x) {\n    assert(i < n);\n    dat[i += size] = x;\n    while (i >>= 1) update(i);\n\
    \  }\n\n  void multiply(int i, const X& x) {\n    assert(i < n);\n    i += size;\n\
    \    dat[i] = Monoid::op(dat[i], x);\n    while (i >>= 1) update(i);\n  }\n\n\
    \  X prod(int L, int R) {\n    assert(0 <= L && L <= R && R <= n);\n    X vl =\
    \ Monoid::unit(), vr = Monoid::unit();\n    L += size, R += size;\n    while (L\
    \ < R) {\n      if (L & 1) vl = Monoid::op(vl, dat[L++]);\n      if (R & 1) vr\
    \ = Monoid::op(dat[--R], vr);\n      L >>= 1, R >>= 1;\n    }\n    return Monoid::op(vl,\
    \ vr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  template <class F>\n  int\
    \ max_right(F check, int L) {\n    assert(0 <= L && L <= n && check(Monoid::unit()));\n\
    \    if (L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L = 2 * L;\n          if (check(Monoid::op(sm,\
    \ dat[L]))) { sm = Monoid::op(sm, dat[L++]); }\n        }\n        return L -\
    \ size;\n      }\n      sm = Monoid::op(sm, dat[L++]);\n    } while ((L & -L)\
    \ != L);\n    return n;\n  }\n\n  template <class F>\n  int min_left(F check,\
    \ int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n    if (R\
    \ == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do {\n    \
    \  --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 3 \"ds/segtree/sortable_segtree.hpp\"\n\ntemplate <typename Monoid,\
    \ int NODES>\nstruct Sortable_SegTree {\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n  const int N, KEY_MAX;\n\n  struct Node {\n    X x, rev_x;\n\
    \    int size;\n    Node *l, *r;\n  };\n  Node* pool;\n  int pid;\n  using np\
    \ = Node*;\n\n  FastSet ss;      // \u533A\u9593\u306E\u5DE6\u7AEF\u5168\u4F53\
    \u3092\u8868\u3059 fastset\n  SegTree<MX> seg; // \u533A\u9593\u3092\u96C6\u7D04\
    \u3057\u305F\u5024\u3092\u533A\u9593\u306E\u5DE6\u7AEF\u306B\u306E\u305B\u305F\
    \ segtree\n  vector<np> root; // \u533A\u9593\u306E\u5DE6\u7AEF\u306B\u3001dynamic\
    \ segtree \u306E node \u3092\u4E57\u305B\u308B\n  vector<bool> rev;\n\n  Sortable_SegTree(int\
    \ KEY_MAX, vector<int> key, vector<X> dat)\n      : N(key.size()), KEY_MAX(KEY_MAX),\
    \ pid(0), ss(key.size()), seg(dat) {\n    pool = new Node[NODES];\n    init(key,\
    \ dat);\n  }\n\n  void set(int i, int key, const X& x) {\n    assert(key < KEY_MAX);\n\
    \    split_at(i), split_at(i + 1);\n    rev[i] = 0, root[i] = new_node();\n  \
    \  set_rec(root[i], 0, KEY_MAX, key, x);\n    seg.set(i, x);\n  }\n\n  X prod_all()\
    \ { return seg.prod_all(); }\n\n  X prod(int l, int r) {\n    if (pid > NODES\
    \ * 0.9) rebuild();\n    split_at(l), split_at(r);\n    return seg.prod(l, r);\n\
    \  }\n\n  void sort_inc(int l, int r) {\n    split_at(l), split_at(r);\n    while\
    \ (1) {\n      if (pid > NODES * 0.9) rebuild();\n      np c = root[l];\n    \
    \  int i = ss.next(l + 1);\n      if (i == r) break;\n      root[l] = merge(c,\
    \ root[i]);\n      ss.erase(i), seg.set(i, MX::unit());\n    }\n    rev[l] = 0,\
    \ seg.set(l, root[l]->x);\n  };\n\n  void sort_dec(int l, int r) {\n    if (pid\
    \ > NODES * 0.9) rebuild();\n    sort_inc(l, r), rev[l] = 1;\n    seg.set(l, root[l]->rev_x);\n\
    \  };\n\n  pair<vc<int>, vc<X>> get_all() {\n    vector<int> key;\n    vector<X>\
    \ dat;\n    key.reserve(N);\n    dat.reserve(N);\n    auto dfs = [&](auto& dfs,\
    \ np n, int l, int r, bool rev) -> void {\n      if (!n) return;\n      if (r\
    \ == l + 1) {\n        key.eb(l), dat.eb(n->x);\n        return;\n      }\n  \
    \    int m = (l + r) / 2;\n      if (!rev) { dfs(dfs, n->l, l, m, rev), dfs(dfs,\
    \ n->r, m, r, rev); }\n      if (rev) { dfs(dfs, n->r, m, r, rev), dfs(dfs, n->l,\
    \ l, m, rev); }\n    };\n    for (int i = 0; i < N; ++i) {\n      if (ss[i]) dfs(dfs,\
    \ root[i], 0, KEY_MAX, rev[i]);\n    }\n    return {key, dat};\n  }\n\nprivate:\n\
    \  void init(vector<int>& key, vector<X>& dat) {\n    rev.assign(N, 0), root.clear(),\
    \ root.reserve(N);\n    seg.build(N, [&](int i) -> X { return dat[i]; });\n  \
    \  for (int i = 0; i < N; ++i) {\n      ss.insert(i);\n      root.eb(new_node(MX::unit()));\n\
    \      assert(key[i] < KEY_MAX);\n      set_rec(root[i], 0, KEY_MAX, key[i], dat[i]);\n\
    \    }\n  }\n\n  // x \u304C\u5DE6\u7AEF\u306B\u306A\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void split_at(int x) {\n    if (x == N || ss[x]) return;\n    int a\
    \ = ss.prev(x), b = ss.next(a + 1);\n    ss.insert(x);\n    if (!rev[a]) {\n \
    \     auto [nl, nr] = split(root[a], x - a);\n      root[a] = nl, root[x] = nr;\n\
    \      rev[a] = rev[x] = 0;\n      seg.set(a, root[a]->x), seg.set(x, root[x]->x);\n\
    \    } else {\n      auto [nl, nr] = split(root[a], b - x);\n      root[a] = nr,\
    \ root[x] = nl;\n      rev[a] = rev[x] = 1;\n      seg.set(a, root[a]->rev_x),\
    \ seg.set(x, root[x]->rev_x);\n    }\n  }\n\n  void rebuild() {\n    auto [key,\
    \ dat] = get_all();\n    pid = 0;\n    init(key, dat);\n  }\n\n  np new_node(X\
    \ x = MX::unit()) {\n    assert(pid < NODES);\n    pool[pid].x = pool[pid].rev_x\
    \ = x;\n    pool[pid].l = pool[pid].r = nullptr;\n    pool[pid].size = 1;\n  \
    \  return &(pool[pid++]);\n  }\n\n  pair<np, np> split(np n, int k) {\n    if\
    \ (k == 0) { return {nullptr, n}; }\n    if (k == n->size) { return {n, nullptr};\
    \ }\n    int s = (n->l ? n->l->size : 0);\n    Node* b = new_node();\n    if (k\
    \ <= s) {\n      auto [nl, nr] = split(n->l, k);\n      b->l = nr, b->r = n->r,\
    \ n->l = nl, n->r = nullptr;\n    }\n    if (k > s) {\n      auto [nl, nr] = split(n->r,\
    \ k - s);\n      n->l = n->l, n->r = nl, b->l = nullptr, b->r = nr;\n    }\n \
    \   update(n), update(b);\n    return {n, b};\n  }\n\n  np merge(np a, np b) {\n\
    \    if (!a) return b;\n    if (!b) return a;\n    a->l = merge(a->l, b->l), a->r\
    \ = merge(a->r, b->r);\n    update(a);\n    return a;\n  }\n\n  void update(np\
    \ n) {\n    if (!(n->l) && !(n->r)) { return; }\n    if (!(n->l)) {\n      n->x\
    \ = n->r->x, n->rev_x = n->r->rev_x, n->size = n->r->size;\n      return;\n  \
    \  }\n    if (!(n->r)) {\n      n->x = n->l->x, n->rev_x = n->l->rev_x, n->size\
    \ = n->l->size;\n      return;\n    }\n    n->x = MX::op(n->l->x, n->r->x);\n\
    \    n->rev_x = MX::op(n->r->rev_x, n->l->rev_x);\n    n->size = n->l->size +\
    \ n->r->size;\n  }\n\n  void set_rec(np n, int l, int r, int k, const X& x) {\n\
    \    if (r == l + 1) {\n      n->x = n->rev_x = x;\n      return;\n    }\n   \
    \ int m = (l + r) / 2;\n    if (k < m) {\n      if (!(n->l)) n->l = new_node();\n\
    \      set_rec(n->l, l, m, k, x);\n    }\n    if (m <= k) {\n      if (!(n->r))\
    \ n->r = new_node();\n      set_rec(n->r, m, r, k, x);\n    }\n    update(n);\n\
    \  }\n};\n#line 2 \"alg/monoid/affine.hpp\"\n\n// op(F, G) = comp(G,F), F \u306E\
    \u3042\u3068\u3067 G\ntemplate <typename K>\nstruct Monoid_Affine {\n  using F\
    \ = pair<K, K>;\n  using value_type = F;\n  using X = value_type;\n  static constexpr\
    \ F op(const F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second\
    \ * y.first + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n \
    \   auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static\
    \ constexpr K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n\
    \  }\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n};\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
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
    mint C_dense(int n, int k) {\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n\
    \  auto calc = [&](int i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1)\
    \ : mint(0));\n    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if\
    \ (W <= k) {\n    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k +\
    \ 1) { C[i][j] = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n\
    \    C.resize(n + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j,\
    \ W) { C[i][j] = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n\
    }\n\ntemplate <typename mint, bool large = false, bool dense = false>\nmint C(ll\
    \ n, ll k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr\
    \ (dense) return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
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
    \ 31};\n    if (mod == 1004535809) return {21, 836905998};\n    if (mod == 1045430273)\
    \ return {20, 363};\n    if (mod == 1051721729) return {20, 330};\n    if (mod\
    \ == 1053818881) return {20, 2789};\n    return {-1, -1};\n  }\n  static constexpr\
    \ bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate\
    \ <int mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n\
    \  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 8 \"test/library_checker/datastructure/sort_segtree_1.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  // \u30AF\u30A8\u30EA\u5148\u8AAD\
    \u307F\u3059\u308B\u65B9\n\n  using AFF = Monoid_Affine<mint>;\n  LL(N, Q);\n\
    \  vc<int> key(N);\n  vc<pair<mint, mint>> seg_raw(N);\n  FOR(i, N) { read(key[i]),\
    \ read(seg_raw[i]); }\n\n  vc<int> all_key = key;\n  using QT = tuple<int, int,\
    \ int, int, int>;\n  vc<QT> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t ==\
    \ 0) {\n      LL(i, p, a, b);\n      query[q] = {t, i, p, a, b};\n      all_key.eb(p);\n\
    \    }\n    if (t == 1) {\n      LL(l, r, x);\n      query[q] = {t, l, r, x, 0};\n\
    \    }\n    if (t == 2 || t == 3) {\n      LL(l, r);\n      query[q] = {t, l,\
    \ r, 0, 0};\n    }\n  }\n\n  UNIQUE(all_key);\n  for (auto&& k: key) k = LB(all_key,\
    \ k);\n\n  Sortable_SegTree<AFF, 4000000> seg(len(all_key), key, seg_raw);\n\n\
    \  for (auto&& [t, a, b, c, d]: query) {\n    if (t == 0) {\n      b = LB(all_key,\
    \ b);\n      seg.set(a, b, {mint(c), mint(d)});\n    }\n    if (t == 1) {\n  \
    \    auto f = seg.prod(a, b);\n      print(AFF::eval(f, c));\n    }\n    if (t\
    \ == 2) { seg.sort_inc(a, b); }\n    if (t == 3) { seg.sort_dec(a, b); }\n  }\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  ll T = 1;\n  FOR(T) solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/point_set_range_sort_range_composite\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/segtree/sortable_segtree.hpp\"\
    \n#include \"alg/monoid/affine.hpp\"\n#include \"mod/modint.hpp\"\n\nusing mint\
    \ = modint998;\n\nvoid solve() {\n  // \u30AF\u30A8\u30EA\u5148\u8AAD\u307F\u3059\
    \u308B\u65B9\n\n  using AFF = Monoid_Affine<mint>;\n  LL(N, Q);\n  vc<int> key(N);\n\
    \  vc<pair<mint, mint>> seg_raw(N);\n  FOR(i, N) { read(key[i]), read(seg_raw[i]);\
    \ }\n\n  vc<int> all_key = key;\n  using QT = tuple<int, int, int, int, int>;\n\
    \  vc<QT> query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(i,\
    \ p, a, b);\n      query[q] = {t, i, p, a, b};\n      all_key.eb(p);\n    }\n\
    \    if (t == 1) {\n      LL(l, r, x);\n      query[q] = {t, l, r, x, 0};\n  \
    \  }\n    if (t == 2 || t == 3) {\n      LL(l, r);\n      query[q] = {t, l, r,\
    \ 0, 0};\n    }\n  }\n\n  UNIQUE(all_key);\n  for (auto&& k: key) k = LB(all_key,\
    \ k);\n\n  Sortable_SegTree<AFF, 4000000> seg(len(all_key), key, seg_raw);\n\n\
    \  for (auto&& [t, a, b, c, d]: query) {\n    if (t == 0) {\n      b = LB(all_key,\
    \ b);\n      seg.set(a, b, {mint(c), mint(d)});\n    }\n    if (t == 1) {\n  \
    \    auto f = seg.prod(a, b);\n      print(AFF::eval(f, c));\n    }\n    if (t\
    \ == 2) { seg.sort_inc(a, b); }\n    if (t == 3) { seg.sort_dec(a, b); }\n  }\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  ll T = 1;\n  FOR(T) solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree/sortable_segtree.hpp
  - ds/fastset.hpp
  - ds/segtree/segtree.hpp
  - alg/monoid/affine.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/sort_segtree_1.test.cpp
  requiredBy: []
  timestamp: '2024-07-22 11:16:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library_checker/datastructure/sort_segtree_1.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/sort_segtree_1.test.cpp
- /verify/test/library_checker/datastructure/sort_segtree_1.test.cpp.html
title: test/library_checker/datastructure/sort_segtree_1.test.cpp
---
