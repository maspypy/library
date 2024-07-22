---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':x:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':question:'
    path: ds/segtree/segtree.hpp
    title: ds/segtree/segtree.hpp
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
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
  bundledCode: "#line 1 \"test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
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
    \ 5 \"test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp\"\
    \n\n#line 1 \"ds/bit_vector.hpp\"\nstruct Bit_Vector {\n  int n;\n  vc<pair<u64,\
    \ u32>> dat;\n  Bit_Vector(int n) : n(n) { dat.assign((n + 127) >> 6, {0, 0});\
    \ }\n  void set(int i) { dat[i >> 6].fi |= u64(1) << (i & 63); }\n  void reset()\
    \ { fill(all(dat), pair<u64, u32>{0, 0}); }\n  void build() {\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\
    \u306E 1 \u306E\u500B\u6570\n  int count(int k, bool f) {\n    auto [a, b] = dat[k\
    \ >> 6];\n    int ret = b + popcnt(a & ((u64(1) << (k & 63)) - 1));\n    return\
    \ (f ? ret : k - ret);\n  }\n  int count(int L, int R, bool f) { return count(R,\
    \ f) - count(L, f); }\n  string to_string() {\n    string ans;\n    FOR(i, n)\
    \ ans += '0' + (dat[i / 64].fi >> (i % 64) & 1);\n    return ans;\n  }\n};\n#line\
    \ 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_SMALL\
    \ {\n  static_assert(is_same_v<T, int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x: X) dat[x - mi\
    \ + 1]++;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x: X)\
    \ { x = dat[x - mi]++; }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n   \
    \ dat[0] = 0;\n    return X;\n  }\n  int operator()(ll x) { return dat[clamp<ll>(x\
    \ - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_SMALL\
    \ {\n  static_assert(is_same_v<T, int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x: X) dat[x - mi\
    \ + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x:\
    \ X) { x = dat[x - mi]; }\n    return X;\n  }\n  int operator()(ll x) { return\
    \ dat[clamp<ll>(x - mi, 0, ma - mi + 1)]; }\n};\n\ntemplate <typename T>\nstruct\
    \ Index_Compression_SAME_LARGE {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n \
    \   vc<int> I = argsort(X);\n    vc<int> res(len(X));\n    for (auto& i: I) {\n\
    \      if (!dat.empty() && dat.back() == X[i]) {\n        res[i] = len(dat) -\
    \ 1;\n      } else {\n        res[i] = len(dat);\n        dat.eb(X[i]);\n    \
    \  }\n    }\n    dat.shrink_to_fit();\n    return res;\n  }\n  int operator()(T\
    \ x) { return LB(dat, x); }\n};\n\ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE\
    \ {\n  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n \
    \   vc<int> res(len(X));\n    for (auto& i: I) { res[i] = len(dat), dat.eb(X[i]);\
    \ }\n    dat.shrink_to_fit();\n    return res;\n  }\n  int operator()(T x) { return\
    \ LB(dat, x); }\n};\n\ntemplate <typename T, bool SMALL>\nusing Index_Compression_DISTINCT\
    \ =\n    typename std::conditional<SMALL, Index_Compression_DISTINCT_SMALL<T>,\n\
    \                              Index_Compression_DISTINCT_LARGE<T>>::type;\ntemplate\
    \ <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename std::conditional<SMALL,\
    \ Index_Compression_SAME_SMALL<T>,\n                              Index_Compression_SAME_LARGE<T>>::type;\n\
    \n// SAME: [2,3,2] -> [0,1,0]\n// DISTINCT: [2,2,3] -> [0,2,1]\n// (x): lower_bound(X,x)\
    \ \u3092\u304B\u3048\u3059\ntemplate <typename T, bool SAME, bool SMALL>\nusing\
    \ Index_Compression =\n    typename std::conditional<SAME, Index_Compression_SAME<T,\
    \ SMALL>,\n                              Index_Compression_DISTINCT<T, SMALL>>::type;\n\
    #line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 4 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\n// \u9759\u7684\u30E1\u30BD\u30C3\u30C9inverse\u306E\u5B58\u5728\u3092\u30C1\
    \u30A7\u30C3\u30AF\u3059\u308B\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\r\ntemplate\
    \ <typename, typename = std::void_t<>>\r\nstruct has_inverse : std::false_type\
    \ {};\r\n\r\ntemplate <typename T>\r\nstruct has_inverse<T, std::void_t<decltype(\r\
    \n                          T::inverse(std::declval<typename T::value_type>()))>>\r\
    \n    : std::true_type {};\r\n\r\nstruct Dummy_Data_Structure {\r\n  using MX\
    \ = Monoid_Add<bool>;\r\n  void build(const vc<bool>& A) {}\r\n};\r\n\r\ntemplate\
    \ <typename Y, bool SMALL_Y, typename SEGTREE = Dummy_Data_Structure>\r\nstruct\
    \ Wavelet_Matrix {\r\n  using Mono = typename SEGTREE::MX;\r\n  using T = typename\
    \ Mono::value_type;\r\n  static_assert(Mono::commute);\r\n\r\n  int n, log, K;\r\
    \n  Index_Compression<Y, true, SMALL_Y> IDX;\r\n  vc<Y> ItoY;\r\n  vc<int> mid;\r\
    \n  vc<Bit_Vector> bv;\r\n  vc<SEGTREE> seg;\r\n\r\n  Wavelet_Matrix() {}\r\n\
    \  Wavelet_Matrix(const vc<Y>& A) { build(A); }\r\n  Wavelet_Matrix(const vc<Y>&\
    \ A, vc<T>& SUM_Data) { build(A, SUM_Data); }\r\n  template <typename F>\r\n \
    \ Wavelet_Matrix(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  void build(int m, F f) {\r\n    vc<Y> A(m);\r\n    vc<T> S(m);\r\n \
    \   for (int i = 0; i < m; ++i) tie(A[i], S[i]) = f(i);\r\n    build(A, S);\r\n\
    \  }\r\n\r\n  void build(const vc<Y>& A) { build(A, vc<T>(len(A), Mono::unit()));\
    \ }\r\n  void build(const vc<Y>& A, vc<T> S) {\r\n    n = len(A);\r\n    vc<int>\
    \ B = IDX.build(A);\r\n    K = 0;\r\n    for (auto& x: B) chmax(K, x + 1);\r\n\
    \    ItoY.resize(K);\r\n    FOR(i, n) ItoY[B[i]] = A[i];\r\n    log = 0;\r\n \
    \   while ((1 << log) < K) ++log;\r\n    mid.resize(log), bv.assign(log, Bit_Vector(n));\r\
    \n    vc<int> B0(n), B1(n);\r\n    vc<T> S0(n), S1(n);\r\n    seg.resize(log +\
    \ 1);\r\n    seg[log].build(S);\r\n    for (int d = log - 1; d >= 0; --d) {\r\n\
    \      int p0 = 0, p1 = 0;\r\n      for (int i = 0; i < n; ++i) {\r\n        bool\
    \ f = (B[i] >> d & 1);\r\n        if (!f) { B0[p0] = B[i], S0[p0] = S[i], p0++;\
    \ }\r\n        if (f) { bv[d].set(i), B1[p1] = B[i], S1[p1] = S[i], p1++; }\r\n\
    \      }\r\n      swap(B, B0), swap(S, S0);\r\n      move(B1.begin(), B1.begin()\
    \ + p1, B.begin() + p0);\r\n      move(S1.begin(), S1.begin() + p1, S.begin()\
    \ + p0);\r\n      mid[d] = p0, bv[d].build(), seg[d].build(S);\r\n    }\r\n  }\r\
    \n\r\n  // [L,R) x [0,y)\r\n  int prefix_count(int L, int R, Y y) {\r\n    int\
    \ p = IDX(y);\r\n    if (p == 0) return 0;\r\n    if (p == K) return R - L;\r\n\
    \    int cnt = 0;\r\n    for (int d = log - 1; d >= 0; --d) {\r\n      int l0\
    \ = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] -\
    \ l0, r1 = R + mid[d] - r0;\r\n      if (p >> d & 1) cnt += r0 - l0, L = l1, R\
    \ = r1;\r\n      if (!(p >> d & 1)) L = l0, R = r0;\r\n    }\r\n    return cnt;\r\
    \n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  int count(int L, int R, Y y1, Y y2) {\r\
    \n    return prefix_count(L, R, y2) - prefix_count(L, R, y1);\r\n  }\r\n\r\n \
    \ // [L,R) x [0,y)\r\n  pair<int, T> prefix_count_and_prod(int L, int R, Y y)\
    \ {\r\n    int p = IDX(y);\r\n    if (p == 0) return {0, Mono::unit()};\r\n  \
    \  if (p == K) return {R - L, seg[log].prod(L, R)};\r\n    int cnt = 0;\r\n  \
    \  T t = Mono::unit();\r\n    for (int d = log - 1; d >= 0; --d) {\r\n      int\
    \ l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d]\
    \ - l0, r1 = R + mid[d] - r0;\r\n      if (p >> d & 1) {\r\n        cnt += r0\
    \ - l0, t = Mono::op(t, seg[d].prod(l0, r0)), L = l1, R = r1;\r\n      }\r\n \
    \     if (!(p >> d & 1)) L = l0, R = r0;\r\n    }\r\n    return {cnt, t};\r\n\
    \  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  pair<int, T> count_and_prod(int L, int R,\
    \ Y y1, Y y2) {\r\n    if constexpr (has_inverse<Mono>::value) {\r\n      auto\
    \ [c1, t1] = prefix_count_and_prod(L, R, y1);\r\n      auto [c2, t2] = prefix_count_and_prod(L,\
    \ R, y2);\r\n      return {c2 - c1, Mono::op(Mono::inverse(t1), t2)};\r\n    }\r\
    \n    int lo = IDX(y1), hi = IDX(y2), cnt = 0;\r\n    T t = Mono::unit();\r\n\
    \    auto dfs = [&](auto& dfs, int d, int L, int R, int a, int b) -> void {\r\n\
    \      assert(b - a == (1 << d));\r\n      if (hi <= a || b <= lo) return;\r\n\
    \      if (lo <= a && b <= hi) {\r\n        cnt += R - L, t = Mono::op(t, seg[d].prod(L,\
    \ R));\r\n        return;\r\n      }\r\n      --d;\r\n      int c = (a + b) /\
    \ 2;\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int\
    \ l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      dfs(dfs, d, l0, r0, a,\
    \ c), dfs(dfs, d, l1, r1, c, b);\r\n    };\r\n    dfs(dfs, log, L, R, 0, 1 <<\
    \ log);\r\n    return {cnt, t};\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  T prefix_prod(int\
    \ L, int R, Y y) { return prefix_count_and_prod(L, R, y).se; }\r\n  // [L,R) x\
    \ [y1,y2)\r\n  T prod(int L, int R, Y y1, Y y2) { return count_and_prod(L, R,\
    \ y1, y2).se; }\r\n  T prod_all(int L, int R) { return seg[log].prod(L, R); }\r\
    \n\r\n  Y kth(int L, int R, int k) {\r\n    assert(0 <= k && k < R - L);\r\n \
    \   int p = 0;\r\n    for (int d = log - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (k < r0 - l0) {\r\n        L = l0, R = r0;\r\n      } else\
    \ {\r\n        k -= r0 - l0, L = l1, R = r1, p |= 1 << d;\r\n      }\r\n    }\r\
    \n    return ItoY[p];\r\n  }\r\n\r\n  // y \u4EE5\u4E0A\u6700\u5C0F OR infty<Y>\r\
    \n  Y next(int L, int R, Y y) {\r\n    int k = IDX(y);\r\n    int p = K;\r\n\r\
    \n    auto dfs = [&](auto& dfs, int d, int L, int R, int a, int b) -> void {\r\
    \n      if (p <= a || L == R || b <= k) return;\r\n      if (d == 0) {\r\n   \
    \     chmin(p, a);\r\n        return;\r\n      }\r\n      --d;\r\n      int c\
    \ = (a + b) / 2;\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\
    \n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      dfs(dfs, d, l0,\
    \ r0, a, c), dfs(dfs, d, l1, r1, c, b);\r\n    };\r\n    dfs(dfs, log, L, R, 0,\
    \ 1 << log);\r\n    return (p == K ? infty<Y> : ItoY[p]);\r\n  }\r\n\r\n  // y\
    \ \u4EE5\u4E0B\u6700\u5927 OR -infty<T>\r\n  Y prev(int L, int R, Y y) {\r\n \
    \   int k = IDX(y + 1);\r\n    int p = -1;\r\n    auto dfs = [&](auto& dfs, int\
    \ d, int L, int R, int a, int b) -> void {\r\n      if (b - 1 <= p || L == R ||\
    \ k <= a) return;\r\n      if (d == 0) {\r\n        chmax(p, a);\r\n        return;\r\
    \n      }\r\n      --d;\r\n      int c = (a + b) / 2;\r\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      dfs(dfs, d, l1, r1, c, b), dfs(dfs, d, l0, r0, a, c);\r\n   \
    \ };\r\n    dfs(dfs, log, L, R, 0, 1 << log);\r\n    return (p == -1 ? -infty<Y>\
    \ : ItoY[p]);\r\n  }\r\n\r\n  Y median(bool UPPER, int L, int R) {\r\n    assert(0\
    \ <= L && L < R && R <= n);\r\n    int k = (UPPER ? (R - L) / 2 : (R - L - 1)\
    \ / 2);\r\n    return kth(L, R, k);\r\n  }\r\n\r\n  pair<Y, T> kth_value_and_prod(int\
    \ L, int R, int k) {\r\n    assert(0 <= k && k <= R - L);\r\n    if (k == R -\
    \ L) return {infty<Y>, seg[log].prod(L, R)};\r\n    int p = 0;\r\n    T t = Mono::unit();\r\
    \n    for (int d = log - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L, 0),\
    \ r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] -\
    \ r0;\r\n      if (k < r0 - l0) {\r\n        L = l0, R = r0;\r\n      } else {\r\
    \n        t = Mono::op(t, seg[d].prod(l0, r0)), k -= r0 - l0, L = l1, R = r1,\r\
    \n        p |= 1 << d;\r\n      }\r\n    }\r\n    t = Mono::op(t, seg[0].prod(L,\
    \ L + k));\r\n    return {ItoY[p], t};\r\n  }\r\n\r\n  T prod_index_range(int\
    \ L, int R, int k1, int k2) {\r\n    static_assert(has_inverse<Mono>::value);\r\
    \n    T t1 = kth_value_and_prod(L, R, k1).se;\r\n    T t2 = kth_value_and_prod(L,\
    \ R, k2).se;\r\n    return Mono::op(Mono::inverse(t1), t2);\r\n  }\r\n\r\n  //\
    \ [L,R) x [0,y) \u3067\u306E check(cnt, prod) \u304C true \u3068\u306A\u308B\u6700\
    \u5927\u306E (cnt,prod)\r\n  template <typename F>\r\n  pair<int, T> max_right(F\
    \ check, int L, int R) {\r\n    int cnt = 0;\r\n    T t = Mono::unit();\r\n  \
    \  assert(check(0, Mono::unit()));\r\n    if (check(R - L, seg[log].prod(L, R)))\
    \ {\r\n      return {R - L, seg[log].prod(L, R)};\r\n    }\r\n    for (int d =\
    \ log - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      int cnt1\
    \ = cnt + r0 - l0;\r\n      T t1 = Mono::op(t, seg[d].prod(l0, r0));\r\n     \
    \ if (check(cnt1, t1)) {\r\n        cnt = cnt1, t = t1, L = l1, R = r1;\r\n  \
    \    } else {\r\n        L = l0, R = r0;\r\n      }\r\n    }\r\n    return {cnt,\
    \ t};\r\n  }\r\n\r\n  void set(int i, T t) {\r\n    assert(0 <= i && i < n);\r\
    \n    int L = i, R = i + 1;\r\n    seg[log].set(L, t);\r\n    for (int d = log\
    \ - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (l0\
    \ < r0) L = l0, R = r0;\r\n      if (l0 == r0) L = l1, R = r1;\r\n      seg[d].set(L,\
    \ t);\r\n    }\r\n  }\r\n  void multiply(int i, T t) {\r\n    assert(0 <= i &&\
    \ i < n);\r\n    int L = i, R = i + 1;\r\n    seg[log].multiply(L, t);\r\n   \
    \ for (int d = log - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L, 0), r0\
    \ = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\
    \n      if (l0 < r0) L = l0, R = r0;\r\n      if (l0 == r0) L = l1, R = r1;\r\n\
    \      seg[d].multiply(L, t);\r\n    }\r\n  }\r\n};\r\n#line 2 \"ds/wavelet_matrix/wavelet_matrix_2d_range.hpp\"\
    \n\ntemplate <typename SEGTREE, typename XY, bool SMALL_X, bool SMALL_Y>\nstruct\
    \ Wavelet_Matrix_2D_Range {\n  // \u70B9\u7FA4\u3092 X \u6607\u9806\u306B\u4E26\
    \u3079\u308B.\n  Wavelet_Matrix<XY, SMALL_Y, SEGTREE> WM;\n  using Mono = typename\
    \ SEGTREE::MX;\n  using T = typename Mono::value_type;\n  static_assert(Mono::commute);\n\
    \n  Index_Compression<XY, false, SMALL_X> IDX_X;\n\n  int n;\n  vc<int> new_idx;\n\
    \n  template <typename F>\n  Wavelet_Matrix_2D_Range(int n, F f) {\n    build(n,\
    \ f);\n  }\n\n  template <typename F>\n  void build(int m, F f) {\n    n = m;\n\
    \    vc<XY> X(n), Y(n);\n    vc<T> S(n);\n    FOR(i, n) tie(X[i], Y[i], S[i])\
    \ = f(i);\n    new_idx = IDX_X.build(X);\n    vc<int> I(n);\n    FOR(i, n) I[new_idx[i]]\
    \ = i;\n    Y = rearrange(Y, I);\n    S = rearrange(S, I);\n    WM.build(Y, S);\n\
    \  }\n\n  int count(XY x1, XY x2, XY y1, XY y2) {\n    return WM.count(IDX_X(x1),\
    \ IDX_X(x2), y1, y2);\n  }\n\n  // [L,R) x [-inf,y)\n  pair<int, T> prefix_count_and_prod(XY\
    \ x1, XY x2, XY y) {\n    return WM.prefix_count_and_prod(IDX_X(x1), IDX_X(x2),\
    \ y);\n  }\n\n  // [L,R) x [y1,y2)\n  pair<int, T> count_and_prod(XY x1, XY x2,\
    \ XY y1, XY y2) {\n    return WM.count_and_prod(IDX_X(x1), IDX_X(x2), y1, y2);\n\
    \  }\n\n  // [L,R) x [-inf,inf)\n  T prod_all(XY x1, XY x2) { return WM.prod_all(IDX_X(x1),\
    \ IDX_X(x2)); }\n  // [L,R) x [-inf,y)\n  T prefix_prod(XY x1, XY x2, XY y) {\n\
    \    return WM.prefix_prod(IDX_X(x1), IDX_X(x2), y);\n  }\n  // [L,R) x [y1,y2)\n\
    \  T prod(XY x1, XY x2, XY y1, XY y2) {\n    return WM.prod(IDX_X(x1), IDX_X(x2),\
    \ y1, y2);\n  }\n\n  // [L,R) x [-inf,y) \u3067\u306E check(cnt, prod) \u304C\
    \ true \u3068\u306A\u308B\u6700\u5927\u306E (cnt,prod)\n  template <typename F>\n\
    \  pair<int, T> max_right(F check, XY x1, XY x2) {\n    return WM.max_right(check,\
    \ IDX_X(x1), IDX_X(x2));\n  }\n\n  // i \u306F\u6700\u521D\u306B\u6E21\u3057\u305F\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n  void set(int i, T t) { WM.set(new_idx[i],\
    \ t); }\n  // i \u306F\u6700\u521D\u306B\u6E21\u3057\u305F\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\n  void multiply(int i, T t) { WM.multiply(new_idx[i], t); }\n};\n\
    #line 2 \"ds/segtree/segtree.hpp\"\n\ntemplate <class Monoid>\nstruct SegTree\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type\
    \ = X;\n  vc<X> dat;\n  int n, log, size;\n\n  SegTree() {}\n  SegTree(int n)\
    \ { build(n); }\n  template <typename F>\n  SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  SegTree(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n\
    \    build(m, [](int i) -> X { return MX::unit(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size << 1, MX::unit());\n\
    \    FOR(i, n) dat[size + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  X get(int i) { return dat[size + i]; }\n  vc<X> get_all() { return {dat.begin()\
    \ + size, dat.begin() + size + n}; }\n\n  void update(int i) { dat[i] = Monoid::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n  void set(int i, const X& x) {\n    assert(i < n);\n\
    \    dat[i += size] = x;\n    while (i >>= 1) update(i);\n  }\n\n  void multiply(int\
    \ i, const X& x) {\n    assert(i < n);\n    i += size;\n    dat[i] = Monoid::op(dat[i],\
    \ x);\n    while (i >>= 1) update(i);\n  }\n\n  X prod(int L, int R) {\n    assert(0\
    \ <= L && L <= R && R <= n);\n    X vl = Monoid::unit(), vr = Monoid::unit();\n\
    \    L += size, R += size;\n    while (L < R) {\n      if (L & 1) vl = Monoid::op(vl,\
    \ dat[L++]);\n      if (R & 1) vr = Monoid::op(dat[--R], vr);\n      L >>= 1,\
    \ R >>= 1;\n    }\n    return Monoid::op(vl, vr);\n  }\n\n  X prod_all() { return\
    \ dat[1]; }\n\n  template <class F>\n  int max_right(F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(Monoid::unit()));\n    if (L == n) return n;\n    L\
    \ += size;\n    X sm = Monoid::unit();\n    do {\n      while (L % 2 == 0) L >>=\
    \ 1;\n      if (!check(Monoid::op(sm, dat[L]))) {\n        while (L < size) {\n\
    \          L = 2 * L;\n          if (check(Monoid::op(sm, dat[L]))) { sm = Monoid::op(sm,\
    \ dat[L++]); }\n        }\n        return L - size;\n      }\n      sm = Monoid::op(sm,\
    \ dat[L++]);\n    } while ((L & -L) != L);\n    return n;\n  }\n\n  template <class\
    \ F>\n  int min_left(F check, int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n\
    \    if (R == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          R = 2 * R + 1;\n          if\
    \ (check(Monoid::op(dat[R], sm))) { sm = Monoid::op(dat[R--], sm); }\n       \
    \ }\n        return R + 1 - size;\n      }\n      sm = Monoid::op(dat[R], sm);\n\
    \    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // prod_{l<=i<r} A[i xor\
    \ x]\n  X xor_prod(int l, int r, int xor_val) {\n    static_assert(Monoid::commute);\n\
    \    X x = Monoid::unit();\n    for (int k = 0; k < log + 1; ++k) {\n      if\
    \ (l >= r) break;\n      if (l & 1) { x = Monoid::op(x, dat[(size >> k) + ((l++)\
    \ ^ xor_val)]); }\n      if (r & 1) { x = Monoid::op(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]); }\n      l /= 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n\
    \  }\n};\n#line 9 \"test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n  FOR(i,\
    \ N) read(X[i], Y[i], W[i]);\n  using QQ = tuple<u32, u32, u32, u32>;\n  vc<QQ>\
    \ query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      U32(x, y, w);\n\
    \      X.eb(x);\n      Y.eb(y);\n      W.eb(0);\n      query[q] = mt(-1, x, y,\
    \ w);\n    } else {\n      U32(a, b, c, d);\n      query[q] = mt(a, c, b, d);\n\
    \    }\n  }\n\n  Wavelet_Matrix_2D_Range<SegTree<Monoid_Add<ll>>, int, false,\
    \ false> WM(\n      len(X), [&](int i) -> tuple<int, int, ll> {\n        return\
    \ {X[i], Y[i], W[i]};\n      });\n  int idx = N;\n  FOR(q, Q) {\n    auto [a,\
    \ b, c, d] = query[q];\n    if (a == u32(-1)) {\n      WM.set(idx++, d);\n   \
    \ } else {\n      print(WM.prod(a, b, c, d));\n    }\n  }\n}\n\nsigned main()\
    \ {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/wavelet_matrix/wavelet_matrix_2d_range.hpp\"\
    \n#include \"ds/segtree/segtree.hpp\"\n#include \"alg/monoid/add.hpp\"\n\nvoid\
    \ solve() {\n  LL(N, Q);\n  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n  FOR(i, N)\
    \ read(X[i], Y[i], W[i]);\n  using QQ = tuple<u32, u32, u32, u32>;\n  vc<QQ> query(Q);\n\
    \  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      U32(x, y, w);\n      X.eb(x);\n\
    \      Y.eb(y);\n      W.eb(0);\n      query[q] = mt(-1, x, y, w);\n    } else\
    \ {\n      U32(a, b, c, d);\n      query[q] = mt(a, c, b, d);\n    }\n  }\n\n\
    \  Wavelet_Matrix_2D_Range<SegTree<Monoid_Add<ll>>, int, false, false> WM(\n \
    \     len(X), [&](int i) -> tuple<int, int, ll> {\n        return {X[i], Y[i],\
    \ W[i]};\n      });\n  int idx = N;\n  FOR(q, Q) {\n    auto [a, b, c, d] = query[q];\n\
    \    if (a == u32(-1)) {\n      WM.set(idx++, d);\n    } else {\n      print(WM.prod(a,\
    \ b, c, d));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - ds/index_compression.hpp
  - alg/monoid/add.hpp
  - ds/segtree/segtree.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
  requiredBy: []
  timestamp: '2024-07-22 11:16:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
- /verify/test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp.html
title: test/library_checker/datastructure/point_add_rectangle_sum_wm_mono.test.cpp
---
