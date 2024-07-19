---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':question:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':x:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':question:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j
    - https://atcoder.jp/contests/utpc2011/tasks/utpc2011_12
  bundledCode: "#line 1 \"graph/ds/tree_wavelet_matrix.hpp\"\n\n#line 1 \"ds/bit_vector.hpp\"\
    \nstruct Bit_Vector {\n  int n;\n  vc<pair<u32, u32>> dat;\n  Bit_Vector(int n)\
    \ : n(n) { dat.assign((n + 63) >> 5, {0, 0}); }\n  void set(int i) { dat[i >>\
    \ 5].fi |= u32(1) << (i & 31); }\n  void reset() { fill(all(dat), pair<u32, u32>{0,\
    \ 0}); }\n  void build() {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se\
    \ + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n \
    \ int count(int k, bool f) {\n    auto [a, b] = dat[k >> 5];\n    int ret = b\
    \ + popcnt(a & ((u32(1) << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n\
    \  }\n  int count(int L, int R, bool f) { return count(R, f) - count(L, f); }\n\
    \  string to_string() {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i /\
    \ 32].fi >> (i % 32) & 1);\n    return ans;\n  }\n};\n#line 2 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n// \u3044\u307E\u306E CF \u3060\u3068\u3053\u308C\u5165\u308C\u308B\u3068\u52D5\
    \u304B\u306A\u3044\uFF1F\n// #pragma GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u32 = unsigned int;\nusing\
    \ u64 = unsigned long long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate\
    \ <>\nconstexpr int infty<int> = 1'000'000'000;\ntemplate <>\nconstexpr ll infty<ll>\
    \ = ll(infty<int>) * infty<int> * 2;\ntemplate <>\nconstexpr u32 infty<u32> =\
    \ infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\ntemplate <>\n\
    constexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\ntemplate <>\nconstexpr\
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
    \ 5 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\n\r\n#line 1 \"ds/bit_vector.hpp\"\
    \nstruct Bit_Vector {\n  int n;\n  vc<pair<u32, u32>> dat;\n  Bit_Vector(int n)\
    \ : n(n) { dat.assign((n + 63) >> 5, {0, 0}); }\n  void set(int i) { dat[i >>\
    \ 5].fi |= u32(1) << (i & 31); }\n  void reset() { fill(all(dat), pair<u32, u32>{0,\
    \ 0}); }\n  void build() {\n    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se\
    \ + popcnt(dat[i].fi);\n  }\n  // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n \
    \ int count(int k, bool f) {\n    auto [a, b] = dat[k >> 5];\n    int ret = b\
    \ + popcnt(a & ((u32(1) << (k & 31)) - 1));\n    return (f ? ret : k - ret);\n\
    \  }\n  int count(int L, int R, bool f) { return count(R, f) - count(L, f); }\n\
    \  string to_string() {\n    string ans;\n    FOR(i, n) ans += '0' + (dat[i /\
    \ 32].fi >> (i % 32) & 1);\n    return ans;\n  }\n};\n#line 1 \"ds/index_compression.hpp\"\
    \ntemplate <typename T>\nstruct Index_Compression_DISTINCT_SMALL {\n  static_assert(is_same_v<T,\
    \ int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi\
    \ = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma\
    \ - mi + 2, 0);\n    for (auto& x: X) dat[x - mi + 1]++;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1] += dat[i];\n    for (auto& x: X) { x = dat[x - mi]++; }\n  \
    \  FOR_R(i, 1, len(dat)) dat[i] = dat[i - 1];\n    dat[0] = 0;\n    return X;\n\
    \  }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)];\
    \ }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_SMALL {\n  static_assert(is_same_v<T,\
    \ int>);\n  int mi, ma;\n  vc<int> dat;\n  vc<int> build(vc<int> X) {\n    mi\
    \ = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma = MAX(X);\n    dat.assign(ma\
    \ - mi + 2, 0);\n    for (auto& x: X) dat[x - mi + 1] = 1;\n    FOR(i, len(dat)\
    \ - 1) dat[i + 1] += dat[i];\n    for (auto& x: X) { x = dat[x - mi]; }\n    return\
    \ X;\n  }\n  int operator()(ll x) { return dat[clamp<ll>(x - mi, 0, ma - mi +\
    \ 1)]; }\n};\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE {\n\
    \  vc<T> dat;\n  vc<int> build(vc<T> X) {\n    vc<int> I = argsort(X);\n    vc<int>\
    \ res(len(X));\n    for (auto& i: I) {\n      if (!dat.empty() && dat.back() ==\
    \ X[i]) {\n        res[i] = len(dat) - 1;\n      } else {\n        res[i] = len(dat);\n\
    \        dat.eb(X[i]);\n      }\n    }\n    dat.shrink_to_fit();\n    return res;\n\
    \  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename T>\n\
    struct Index_Compression_DISTINCT_LARGE {\n  vc<T> dat;\n  vc<int> build(vc<T>\
    \ X) {\n    vc<int> I = argsort(X);\n    vc<int> res(len(X));\n    for (auto&\
    \ i: I) { res[i] = len(dat), dat.eb(X[i]); }\n    dat.shrink_to_fit();\n    return\
    \ res;\n  }\n  int operator()(T x) { return LB(dat, x); }\n};\n\ntemplate <typename\
    \ T, bool SMALL>\nusing Index_Compression_DISTINCT =\n    typename std::conditional<SMALL,\
    \ Index_Compression_DISTINCT_SMALL<T>,\n                              Index_Compression_DISTINCT_LARGE<T>>::type;\n\
    template <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename\
    \ std::conditional<SMALL, Index_Compression_SAME_SMALL<T>,\n                 \
    \             Index_Compression_SAME_LARGE<T>>::type;\n\n// SAME: [2,3,2] -> [0,1,0]\n\
    // DISTINCT: [2,2,3] -> [0,2,1]\n// (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\
    \ntemplate <typename T, bool SAME, bool SMALL>\nusing Index_Compression =\n  \
    \  typename std::conditional<SAME, Index_Compression_SAME<T, SMALL>,\n       \
    \                       Index_Compression_DISTINCT<T, SMALL>>::type;\n#line 2\
    \ \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n\
    \  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 9 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\nstruct Dummy_Data_Structure {\r\n  using MX = Monoid_Add<bool>;\r\n  void\
    \ build(const vc<bool>& A) {}\r\n};\r\n\r\ntemplate <typename Y, bool SMALL_Y,\
    \ typename SEGTREE = Dummy_Data_Structure>\r\nstruct Wavelet_Matrix {\r\n  using\
    \ Mono = typename SEGTREE::MX;\r\n  using T = typename Mono::value_type;\r\n \
    \ static_assert(Mono::commute);\r\n\r\n  int n, log, K;\r\n  Index_Compression<Y,\
    \ true, SMALL_Y> IDX;\r\n  vc<int> mid;\r\n  vc<Bit_Vector> bv;\r\n  vc<SEGTREE>\
    \ seg;\r\n\r\n  Wavelet_Matrix() {}\r\n  Wavelet_Matrix(const vc<Y>& A) { build(A);\
    \ }\r\n  Wavelet_Matrix(const vc<Y>& A, vc<T>& SUM_Data) { build(A, SUM_Data);\
    \ }\r\n  template <typename F>\r\n  Wavelet_Matrix(int n, F f) {\r\n    build(n,\
    \ f);\r\n  }\r\n\r\n  template <typename F>\r\n  void build(int m, F f) {\r\n\
    \    vc<Y> A(m);\r\n    vc<T> S(m);\r\n    for (int i = 0; i < m; ++i) tie(A[i],\
    \ S[i]) = f(i);\r\n  }\r\n\r\n  void build(const vc<Y>& A) { build(A, vc<T>(len(A),\
    \ Mono::unit())); }\r\n  void build(const vc<Y>& A, vc<T> S) {\r\n    n = len(A);\r\
    \n    vc<int> B = IDX.build(A);\r\n    int K = 1;\r\n    for (auto& x: B) chmax(K,\
    \ x + 1);\r\n    log = 0;\r\n    while ((1 << log) < K) ++log;\r\n    mid.resize(log),\
    \ bv.assign(log, Bit_Vector(n));\r\n    vc<int> B0(n), B1(n);\r\n    vc<T> S0(n),\
    \ S1(n);\r\n    seg.resize(log + 1);\r\n    seg[log].build(S);\r\n    for (int\
    \ d = log - 1; d >= 0; --d) {\r\n      int p0 = 0, p1 = 0;\r\n      for (int i\
    \ = 0; i < n; ++i) {\r\n        bool f = (B[i] >> d & 1);\r\n        if (!f) {\
    \ B0[p0] = B[i], S0[p0] = S[i], p0++; }\r\n        if (f) { bv[d].set(i), B1[p1]\
    \ = B[i], S1[p1] = S[i], p1++; }\r\n      }\r\n      swap(B, B0), swap(S, S0);\r\
    \n      move(B1.begin(), B1.begin() + p1, B.begin() + p0);\r\n      move(S1.begin(),\
    \ S1.begin() + p1, S.begin() + p0);\r\n      mid[d] = p0, bv[d].build(), seg[d].build(S);\r\
    \n    }\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  int prefix_count(int L, int R, Y\
    \ y) {\r\n    int k = IDX(y);\r\n    if (k == 0) return 0;\r\n    if (k == K)\
    \ return R - L;\r\n    int cnt = 0;\r\n    for (int d = log - 1; d >= 0; --d)\
    \ {\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int\
    \ l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (k >> d & 1) cnt +=\
    \ r0 - l0, L = l1, R = r1;\r\n      if (!(k >> d & 1)) cnt += r1 - l1, L = l0,\
    \ R = r0;\r\n    }\r\n    return cnt;\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n \
    \ int count(int L, int R, Y y1, Y y2) {\r\n    return prefix_count(L, R, y2) -\
    \ prefix_count(L, R, y1);\r\n  }\r\n};\r\n\r\n// \u5EA7\u5727\u3059\u308B\u304B\
    \u3069\u3046\u304B\u3092 COMPRESS \u3067\u6307\u5B9A\u3059\u308B\r\n// xor \u7684\
    \u306A\u4F7F\u3044\u65B9\u3092\u3059\u308B\u5834\u5408\u306B\u306F\u3001\u30B3\
    \u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067 log \u3092\u6E21\u3059\u3053\u3068\r\
    \ntemplate <typename T, bool COMPRESS, bool USE_SUM>\r\nstruct Wavelet_Matrix_Old\
    \ {\r\n  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\r\n  int N, lg;\r\
    \n  vector<int> mid;\r\n  vector<Bit_Vector> bv;\r\n  vc<T> key;\r\n  bool set_log;\r\
    \n  vvc<T> cumsum;\r\n\r\n  Wavelet_Matrix() {}\r\n\r\n  // \u548C\u3092\u4F7F\
    \u308F\u306A\u3044\u306A\u3089\u3001SUM_data \u306F\u7A7A\u3067\u3088\u3044\r\n\
    \  Wavelet_Matrix(vc<T> A, vc<T> SUM_data = {}, int log = -1) {\r\n    build(A,\
    \ SUM_data, log);\r\n  }\r\n\r\n  void build(vc<T> A, vc<T> SUM_data = {}, int\
    \ log = -1) {\r\n    if constexpr (USE_SUM) { assert(len(SUM_data) == len(A));\
    \ }\r\n    N = len(A), lg = log, set_log = (log != -1);\r\n    if (N == 0) {\r\
    \n      lg = 0;\r\n      cumsum.resize(1);\r\n      cumsum[0] = {0};\r\n     \
    \ return;\r\n    }\r\n    vc<T>& S = SUM_data;\r\n    if (COMPRESS) {\r\n    \
    \  assert(!set_log);\r\n      key.reserve(N);\r\n      vc<int> I = argsort(A);\r\
    \n      for (auto&& i: I) {\r\n        if (key.empty() || key.back() != A[i])\
    \ key.eb(A[i]);\r\n        A[i] = len(key) - 1;\r\n      }\r\n      key.shrink_to_fit();\r\
    \n    }\r\n    if (lg == -1) lg = __lg(max<ll>(MAX(A), 1)) + 1;\r\n    mid.resize(lg),\
    \ bv.assign(lg, Bit_Vector(N));\r\n    if constexpr (USE_SUM) cumsum.assign(1\
    \ + lg, vc<T>(N + 1, 0));\r\n    S.resize(N);\r\n    vc<T> A0(N), A1(N);\r\n \
    \   vc<T> S0(N), S1(N);\r\n    FOR_R(d, -1, lg) {\r\n      int p0 = 0, p1 = 0;\r\
    \n      if constexpr (USE_SUM) {\r\n        FOR(i, N) { cumsum[d + 1][i + 1] =\
    \ cumsum[d + 1][i] + S[i]; }\r\n      }\r\n      if (d == -1) break;\r\n     \
    \ FOR(i, N) {\r\n        bool f = (A[i] >> d & 1);\r\n        if (!f) {\r\n  \
    \        if constexpr (USE_SUM) S0[p0] = S[i];\r\n          A0[p0++] = A[i];\r\
    \n        } else {\r\n          if constexpr (USE_SUM) S1[p1] = S[i];\r\n    \
    \      bv[d].set(i), A1[p1++] = A[i];\r\n        }\r\n      }\r\n      mid[d]\
    \ = p0;\r\n      bv[d].build();\r\n      swap(A, A0), swap(S, S0);\r\n      FOR(i,\
    \ p1) A[p0 + i] = A1[i], S[p0 + i] = S1[i];\r\n    }\r\n  }\r\n\r\n  // [L,R)\
    \ x [a,b), (cnt, monoid value)\r\n  pair<int, T> range_cnt_sum(int L, int R, T\
    \ a, T b, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    if\
    \ (a == b) return {0, 0};\r\n    if (COMPRESS) a = LB(key, a), b = LB(key, b);\r\
    \n    int cnt = 0;\r\n    T sm = 0;\r\n    auto dfs = [&](auto& dfs, int d, int\
    \ L, int R, T lx, T rx) -> void {\r\n      if (rx <= a || b <= lx) return;\r\n\
    \      if (a <= lx && rx <= b) {\r\n        cnt += R - L, sm += get(d, L, R);\r\
    \n        return;\r\n      }\r\n      --d;\r\n      T mx = (lx + rx) / 2;\r\n\
    \      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L\
    \ + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >> d & 1) swap(l0,\
    \ l1), swap(r0, r1);\r\n      dfs(dfs, d, l0, r0, lx, mx), dfs(dfs, d, l1, r1,\
    \ mx, rx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) << lg);\r\n    return {cnt,\
    \ sm};\r\n  }\r\n\r\n  // smallest k, sum of [0,k)\r\n  pair<T, T> kth_value_sum(int\
    \ L, int R, int k, T xor_val = 0) {\r\n    assert(0 <= k && k <= R - L);\r\n \
    \   if (k == R - L) { return {infty<T>, sum_all(L, R)}; }\r\n    if (L == R) return\
    \ {infty<T>, 0};\r\n    if (xor_val != 0) assert(set_log);\r\n    T sm = 0, val\
    \ = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      // \u3044\u307E\u5E45\
    \ d+1 \u306E trie node \u306B\u5C45\u3066, \u5E45 d \u306E\u3068\u3053\u308D\u306B\
    \u884C\u304F\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R, 0);\r\n\
    \      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val >>\
    \ d & 1) swap(l0, l1), swap(r0, r1);\r\n      if (k < r0 - l0) {\r\n        L\
    \ = l0, R = r0;\r\n      } else {\r\n        k -= r0 - l0, val |= T(1) << d, L\
    \ = l1, R = r1;\r\n        if constexpr (USE_SUM) sm += get(d, l0, r0);\r\n  \
    \    }\r\n    }\r\n    if constexpr (USE_SUM) sm += get(0, L, L + k);\r\n    if\
    \ (COMPRESS) val = key[val];\r\n\r\n    return {val, sm};\r\n  }\r\n\r\n  int\
    \ count(int L, int R, T a, T b, T xor_val = 0) {\r\n    return range_cnt_sum(L,\
    \ R, a, b, xor_val).fi;\r\n  }\r\n  T sum(int L, int R, T a, T b, T xor_val =\
    \ 0) {\r\n    static_assert(USE_SUM);\r\n    return range_cnt_sum(L, R, a, b,\
    \ xor_val).se;\r\n  }\r\n\r\n  T sum_index_range(int L, int R, int k1, int k2,\
    \ T xor_val = 0) {\r\n    static_assert(USE_SUM);\r\n    return kth_value_sum(L,\
    \ R, k2, xor_val).se\r\n           - kth_value_sum(L, R, k1, xor_val).se;\r\n\
    \  }\r\n  T kth(int L, int R, int k, T xor_val = 0) {\r\n    assert(0 <= k &&\
    \ k < R - L);\r\n    return kth_value_sum(L, R, k, xor_val).fi;\r\n  }\r\n\r\n\
    \  // x \u4EE5\u4E0A\u6700\u5C0F OR infty<T>\r\n  T next(int L, int R, T x, T\
    \ xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    if (L == R)\
    \ return infty<T>;\r\n    if (COMPRESS) x = LB(key, x);\r\n    T ans = infty<T>;\r\
    \n\r\n    auto dfs = [&](auto& dfs, int d, int L, int R, T lx, T rx) -> void {\r\
    \n      if (ans <= lx || L == R || rx <= x) return;\r\n      if (d == 0) {\r\n\
    \        chmin(ans, lx);\r\n        return;\r\n      }\r\n      --d;\r\n     \
    \ T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].count(L, 0), r0 = bv[d].count(R,\
    \ 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d] - r0;\r\n      if (xor_val\
    \ >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      dfs(dfs, d, l0, r0, lx, mx),\
    \ dfs(dfs, d, l1, r1, mx, rx);\r\n    };\r\n    dfs(dfs, lg, L, R, 0, T(1) <<\
    \ lg);\r\n    if (COMPRESS && ans < infty<T>) ans = key[ans];\r\n    return ans;\r\
    \n  }\r\n\r\n  // x \u4EE5\u4E0B\u6700\u5927 OR -infty<T>\r\n  T prev(int L, int\
    \ R, T x, T xor_val = 0) {\r\n    if (xor_val != 0) assert(set_log);\r\n    if\
    \ (L == R) return -infty<T>;\r\n    T ans = -infty<int>;\r\n    ++x;\r\n    if\
    \ (COMPRESS) x = LB(key, x);\r\n\r\n    auto dfs = [&](auto& dfs, int d, int L,\
    \ int R, T lx, T rx) -> void {\r\n      if ((rx - 1) <= ans || L == R || x <=\
    \ lx) return;\r\n      if (d == 0) {\r\n        chmax(ans, lx);\r\n        return;\r\
    \n      }\r\n      --d;\r\n      T mx = (lx + rx) / 2;\r\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      dfs(dfs,\
    \ d, l1, r1, mx, rx), dfs(dfs, d, l0, r0, lx, mx);\r\n    };\r\n    dfs(dfs, lg,\
    \ L, R, 0, T(1) << lg);\r\n    if (COMPRESS && ans != -infty<T>) ans = key[ans];\r\
    \n    return ans;\r\n  }\r\n\r\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001\
    [L, R) \u306E\u4E2D\u3067\u4E2D\u592E\u5024\u3002\r\n  // LOWER = true\uFF1A\u4E0B\
    \u5074\u4E2D\u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\r\n  T\
    \ median(bool UPPER, int L, int R, T xor_val = 0) {\r\n    int n = R - L;\r\n\
    \    int k = (UPPER ? n / 2 : (n - 1) / 2);\r\n    return kth(L, R, k, xor_val);\r\
    \n  }\r\n\r\n  T sum_all(int L, int R) { return get(lg, L, R); }\r\n\r\n  // check(cnt,\
    \ prefix sum) \u304C true \u3068\u306A\u308B\u3088\u3046\u306A\u6700\u5927\u306E\
    \ (cnt, sum)\r\n  template <typename F>\r\n  pair<int, T> max_right(F check, int\
    \ L, int R, T xor_val = 0) {\r\n    assert(check(0, 0));\r\n    if (xor_val !=\
    \ 0) assert(set_log);\r\n    if (L == R) return {0, 0};\r\n    if (check(R - L,\
    \ get(lg, L, R))) return {R - L, get(lg, L, R)};\r\n    int cnt = 0;\r\n    T\
    \ sm = 0;\r\n    for (int d = lg - 1; d >= 0; --d) {\r\n      int l0 = bv[d].count(L,\
    \ 0), r0 = bv[d].count(R, 0);\r\n      int l1 = L + mid[d] - l0, r1 = R + mid[d]\
    \ - r0;\r\n      if (xor_val >> d & 1) swap(l0, l1), swap(r0, r1);\r\n      if\
    \ (check(cnt + r0 - l0, sm + get(d, l0, r0))) {\r\n        cnt += r0 - l0, sm\
    \ += get(d, l0, r0);\r\n        L = l1, R = r1;\r\n      } else {\r\n        L\
    \ = l0, R = r0;\r\n      }\r\n    }\r\n    int k = binary_search(\r\n        [&](int\
    \ k) -> bool { return check(cnt + k, sm + get(0, L, L + k)); }, 0,\r\n       \
    \ R - L);\r\n    cnt += k, sm += get(0, L, L + k);\r\n    return {cnt, sm};\r\n\
    \  }\r\n\r\nprivate:\r\n  inline T get(int d, int L, int R) {\r\n    if constexpr\
    \ (USE_SUM) return cumsum[d][R] - cumsum[d][L];\r\n    return 0;\r\n  }\r\n};\n\
    #line 2 \"graph/tree.hpp\"\n\r\n#line 2 \"graph/base.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename\
    \ T = int, bool directed = false>\nstruct Graph {\n  static constexpr bool is_directed\
    \ = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n\
    \  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n\
    \  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges\
    \ {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r) : G(G), l(l),\
    \ r(r) {}\n\n    const edge_type* begin() const {\n      if (l == r) { return\
    \ 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type* end() const\
    \ {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n    }\n\n\
    \  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
    \ { return prepared; }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int\
    \ N) : N(N), M(0), prepared(0) {}\n\n  void build(int n) {\n    N = n, M = 0;\n\
    \    prepared = 0;\n    edges.clear();\n    indptr.clear();\n    csr_edges.clear();\n\
    \    vc_deg.clear();\n    vc_indeg.clear();\n    vc_outdeg.clear();\n  }\n\n \
    \ void add(int frm, int to, T cost = 1, int i = -1) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto\
    \ e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef\
    \ FASTIO\n  // wt, off\n  void read_tree(bool wt = false, int off = 1) { read_graph(N\
    \ - 1, wt, off); }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n\
    \    for (int m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n\
    \      if (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e: edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) { indptr[v + 1]\
    \ += indptr[v]; }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n    print(\"\
    Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n      for (auto&&\
    \ e: edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n      print(\"indptr\"\
    , indptr);\n      print(\"frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v])\
    \ print(e.frm, e.to, e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n\
    \  vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\
    \u3001\u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\
    \u306A\u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\
    \u306E n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid =\
    \ 0) {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n\
    \    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 4 \"graph/tree.hpp\"\
    \n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\u308D\u3044\u308D\u3002\
    \r\ntemplate <typename GT>\r\nstruct Tree {\r\n  using Graph_type = GT;\r\n  GT\
    \ &G;\r\n  using WT = typename GT::cost_type;\r\n  int N;\r\n  vector<int> LID,\
    \ RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\n  vc<WT> depth_weighted;\r\
    \n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G) { build(r, hld); }\r\n\r\n\
    \  void build(int r = 0, bool hld = 1) {\r\n    if (r == -1) return; // build\
    \ \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\r\n    N = G.N;\r\n    LID.assign(N,\
    \ -1), RID.assign(N, -1), head.assign(N, r);\r\n    V.assign(N, -1), parent.assign(N,\
    \ -1), VtoE.assign(N, -1);\r\n    depth.assign(N, -1), depth_weighted.assign(N,\
    \ 0);\r\n    assert(G.is_prepared());\r\n    int t1 = 0;\r\n    dfs_sz(r, -1,\
    \ hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void dfs_sz(int v, int p, bool\
    \ hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\n    depth[v] = (p ==\
    \ -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l = G.indptr[v], r = G.indptr[v\
    \ + 1];\r\n    auto &csr = G.csr_edges;\r\n    // \u4F7F\u3046\u8FBA\u304C\u3042\
    \u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n    for (int i = r - 2; i >= l;\
    \ --i) {\r\n      if (hld && depth[csr[i + 1].to] == -1) swap(csr[i], csr[i +\
    \ 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for (int i = l; i < r; ++i) {\r\n\
    \      auto e = csr[i];\r\n      if (depth[e.to] != -1) continue;\r\n      depth_weighted[e.to]\
    \ = depth_weighted[v] + e.cost;\r\n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to,\
    \ v, hld);\r\n      sz[v] += sz[e.to];\r\n      if (hld && chmax(hld_sz, sz[e.to])\
    \ && l < i) { swap(csr[l], csr[i]); }\r\n    }\r\n  }\r\n\r\n  void dfs_hld(int\
    \ v, int &times) {\r\n    LID[v] = times++;\r\n    RID[v] += LID[v];\r\n    V[LID[v]]\
    \ = v;\r\n    bool heavy = true;\r\n    for (auto &&e: G[v]) {\r\n      if (depth[e.to]\
    \ <= depth[v]) continue;\r\n      head[e.to] = (heavy ? head[v] : e.to);\r\n \
    \     heavy = false;\r\n      dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int>\
    \ heavy_path_at(int v) {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int\
    \ a = P.back();\r\n      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a]\
    \ && head[e.to] == v) {\r\n          P.eb(e.to);\r\n          break;\r\n     \
    \   }\r\n      }\r\n      if (P.back() == a) break;\r\n    }\r\n    return P;\r\
    \n  }\r\n\r\n  int heavy_child(int v) {\r\n    int k = LID[v] + 1;\r\n    if (k\
    \ == N) return -1;\r\n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\
    \n  }\r\n\r\n  int e_to_v(int eid) {\r\n    auto e = G.edges[eid];\r\n    return\
    \ (parent[e.frm] == e.to ? e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return\
    \ VtoE[v]; }\r\n  int get_eid(int u, int v) {\r\n    if (parent[u] != v) swap(u,\
    \ v);\r\n    assert(parent[u] == v);\r\n    return VtoE[u];\r\n  }\r\n\r\n  int\
    \ ELID(int v) { return 2 * LID[v] - depth[v]; }\r\n  int ERID(int v) { return\
    \ 2 * RID[v] - depth[v] - 1; }\r\n\r\n  // \u76EE\u6A19\u5730\u70B9\u3078\u9032\
    \u3080\u500B\u6570\u304C k\r\n  int LA(int v, int k) {\r\n    assert(k <= depth[v]);\r\
    \n    while (1) {\r\n      int u = head[v];\r\n      if (LID[v] - k >= LID[u])\
    \ return V[LID[v] - k];\r\n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\
    \n    }\r\n  }\r\n  int la(int u, int v) { return LA(u, v); }\r\n\r\n  int LCA(int\
    \ u, int v) {\r\n    for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v])\
    \ swap(u, v);\r\n      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\
    \n  int meet(int a, int b, int c) { return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c);\
    \ }\r\n  int lca(int u, int v) { return LCA(u, v); }\r\n\r\n  int subtree_size(int\
    \ v, int root = -1) {\r\n    if (root == -1) return RID[v] - LID[v];\r\n    if\
    \ (v == root) return N;\r\n    int x = jump(v, root, 1);\r\n    if (in_subtree(v,\
    \ x)) return RID[v] - LID[v];\r\n    return N - RID[x] + LID[x];\r\n  }\r\n\r\n\
    \  int dist(int a, int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] +\
    \ depth[b] - 2 * depth[c];\r\n  }\r\n\r\n  WT dist_weighted(int a, int b) {\r\n\
    \    int c = LCA(a, b);\r\n    return depth_weighted[a] + depth_weighted[b] -\
    \ WT(2) * depth_weighted[c];\r\n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int\
    \ a, int b) { return LID[b] <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int\
    \ a, int b, ll k) {\r\n    if (k == 1) {\r\n      if (a == b) return -1;\r\n \
    \     return (in_subtree(b, a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\
    \n    }\r\n    int c = LCA(a, b);\r\n    int d_ac = depth[a] - depth[c];\r\n \
    \   int d_bc = depth[b] - depth[c];\r\n    if (k > d_ac + d_bc) return -1;\r\n\
    \    if (k <= d_ac) return LA(a, k);\r\n    return LA(b, d_ac + d_bc - k);\r\n\
    \  }\r\n\r\n  vc<int> collect_child(int v) {\r\n    vc<int> res;\r\n    for (auto\
    \ &&e: G[v])\r\n      if (e.to != parent[v]) res.eb(e.to);\r\n    return res;\r\
    \n  }\r\n\r\n  vc<int> collect_light(int v) {\r\n    vc<int> res;\r\n    bool\
    \ skip = true;\r\n    for (auto &&e: G[v])\r\n      if (e.to != parent[v]) {\r\
    \n        if (!skip) res.eb(e.to);\r\n        skip = false;\r\n      }\r\n   \
    \ return res;\r\n  }\r\n\r\n  vc<pair<int, int>> get_path_decomposition(int u,\
    \ int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\u70B9] \u306E\"\u9589\"\u533A\
    \u9593\u5217\u3002\r\n    vc<pair<int, int>> up, down;\r\n    while (1) {\r\n\
    \      if (head[u] == head[v]) break;\r\n      if (LID[u] < LID[v]) {\r\n    \
    \    down.eb(LID[head[v]], LID[v]);\r\n        v = parent[head[v]];\r\n      }\
    \ else {\r\n        up.eb(LID[u], LID[head[u]]);\r\n        u = parent[head[u]];\r\
    \n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(LID[u] + edge, LID[v]);\r\
    \n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u], LID[v] + edge);\r\n    reverse(all(down));\r\
    \n    up.insert(up.end(), all(down));\r\n    return up;\r\n  }\r\n\r\n  vc<int>\
    \ restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a, b]: get_path_decomposition(u,\
    \ v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i, a, b + 1) P.eb(V[i]);\r\n\
    \      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\n      }\r\n    }\r\
    \n    return P;\r\n  }\r\n\r\n  // path [a,b] \u3068 [c,d] \u306E\u4EA4\u308F\u308A\
    . \u7A7A\u306A\u3089\u3070 {-1,-1}.\r\n  // https://codeforces.com/problemset/problem/500/G\r\
    \n  pair<int, int> path_intersection(int a, int b, int c, int d) {\r\n    int\
    \ ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);\r\n    int bc = lca(b, c), bd\
    \ = lca(b, d), cd = lca(c, d);\r\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^ bd;\
    \ // meet(a,b,c), meet(a,b,d)\r\n    if (x != y) return {x, y};\r\n    int z =\
    \ ac ^ ad ^ cd;\r\n    if (x != z) x = -1;\r\n    return {x, x};\r\n  }\r\n};\r\
    \n#line 4 \"graph/ds/tree_wavelet_matrix.hpp\"\n\n// https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j\n\
    // https://atcoder.jp/contests/utpc2011/tasks/utpc2011_12\ntemplate <typename\
    \ TREE, bool edge, typename T, bool COMPRESS,\n          typename Monoid = Monoid_Add<T>>\n\
    struct Tree_Wavelet_Matrix {\n  TREE& tree;\n  int N;\n  using WM = Wavelet_Matrix<T,\
    \ COMPRESS, Monoid_Add<T>>;\n  using X = typename Monoid::value_type;\n  WM wm;\n\
    \n  Tree_Wavelet_Matrix(TREE& tree, vc<T> A, vc<X> SUM_data = {}, int log = -1)\n\
    \      : tree(tree), N(tree.N) {\n    vc<X>& S = SUM_data;\n    vc<T> A1;\n  \
    \  vc<X> S1;\n    A1.resize(N);\n    if (!S.empty()) S1.resize(N);\n    if (!edge)\
    \ {\n      assert(len(A) == N && (len(S) == 0 || len(S) == N));\n      FOR(v,\
    \ N) A1[tree.LID[v]] = A[v];\n      if (len(S) == N) { FOR(v, N) S1[tree.LID[v]]\
    \ = S[v]; }\n      wm.build(A1, S1, log);\n    } else {\n      assert(len(A) ==\
    \ N - 1 && (len(S) == 0 || len(S) == N - 1));\n      if (!S.empty()) {\n     \
    \   FOR(e, N - 1) { S1[tree.LID[tree.e_to_v(e)]] = S[e]; }\n      }\n      FOR(e,\
    \ N - 1) { A1[tree.LID[tree.e_to_v(e)]] = A[e]; }\n      wm.build(A1, S1, log);\n\
    \    }\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\
    \u308B\u3082\u306E\u3092\u6570\u3048\u308B\n  int count_path(int s, int t, T a,\
    \ T b, T xor_val = 0) {\n    return wm.count(get_segments(s, t), a, b, xor_val);\n\
    \  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\u308B\
    \u3082\u306E\u3092\u6570\u3048\u308B\n  int count_subtree(int u, T a, T b, T xor_val\
    \ = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return wm.count(l + edge,\
    \ r, a, b, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L,\
    \ R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth_value_and_sum(get_segments(s,\
    \ t), k, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R)\
    \ \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_subtree(int\
    \ u, int k, T xor_val = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return\
    \ wm.kth_value_and_sum(l + edge, r, k, xor_val);\n  }\n\n  // xor \u3057\u305F\
    \u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth(get_segments(s, t), k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_subtree(int u, int k, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.kth(l + edge, r, k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067\u4E2D\u592E\u5024\u3002\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\
    \u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\n  T median_path(bool\
    \ UPPER, int s, int t, T xor_val = 0) {\n    return wm.median(UPPER, get_segments(s,\
    \ t), xor_val);\n  }\n\n  T median_subtree(bool UPPER, int u, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.median(UPPER, l + edge,\
    \ r, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2) \u756A\
    \u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\n  X sum_path(int\
    \ s, int t, int k1, int k2, T xor_val = 0) {\n    return wm.sum(get_segments(s,\
    \ t), k1, k2, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2)\
    \ \u756A\u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\
    \n  X sum_subtree(int u, int k1, int k2, T xor_val = 0) {\n    int l = tree.LID[u],\
    \ r = tree.RID[u];\n    return wm.sum(l + edge, r, k1, k2, xor_val);\n  }\n\n\
    \  X sum_all_path(int s, int t) { return wm.sum_all(get_segments(s, t)); }\n\n\
    \  X sum_all_subtree(int u) {\n    int l = tree.LID[u], r = tree.RID[u];\n   \
    \ return wm.sum_all(l + edge, r);\n  }\n\nprivate:\n  vc<pair<int, int>> get_segments(int\
    \ s, int t) {\n    vc<pair<int, int>> segments = tree.get_path_decomposition(s,\
    \ t, edge);\n    for (auto&& [a, b]: segments) {\n      if (a >= b) swap(a, b);\n\
    \      ++b;\n    }\n    return segments;\n  }\n};\n"
  code: "\n#include \"ds/wavelet_matrix/wavelet_matrix.hpp\"\n#include \"graph/tree.hpp\"\
    \n\n// https://atcoder.jp/contests/pakencamp-2022-day1/tasks/pakencamp_2022_day1_j\n\
    // https://atcoder.jp/contests/utpc2011/tasks/utpc2011_12\ntemplate <typename\
    \ TREE, bool edge, typename T, bool COMPRESS,\n          typename Monoid = Monoid_Add<T>>\n\
    struct Tree_Wavelet_Matrix {\n  TREE& tree;\n  int N;\n  using WM = Wavelet_Matrix<T,\
    \ COMPRESS, Monoid_Add<T>>;\n  using X = typename Monoid::value_type;\n  WM wm;\n\
    \n  Tree_Wavelet_Matrix(TREE& tree, vc<T> A, vc<X> SUM_data = {}, int log = -1)\n\
    \      : tree(tree), N(tree.N) {\n    vc<X>& S = SUM_data;\n    vc<T> A1;\n  \
    \  vc<X> S1;\n    A1.resize(N);\n    if (!S.empty()) S1.resize(N);\n    if (!edge)\
    \ {\n      assert(len(A) == N && (len(S) == 0 || len(S) == N));\n      FOR(v,\
    \ N) A1[tree.LID[v]] = A[v];\n      if (len(S) == N) { FOR(v, N) S1[tree.LID[v]]\
    \ = S[v]; }\n      wm.build(A1, S1, log);\n    } else {\n      assert(len(A) ==\
    \ N - 1 && (len(S) == 0 || len(S) == N - 1));\n      if (!S.empty()) {\n     \
    \   FOR(e, N - 1) { S1[tree.LID[tree.e_to_v(e)]] = S[e]; }\n      }\n      FOR(e,\
    \ N - 1) { A1[tree.LID[tree.e_to_v(e)]] = A[e]; }\n      wm.build(A1, S1, log);\n\
    \    }\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\
    \u308B\u3082\u306E\u3092\u6570\u3048\u308B\n  int count_path(int s, int t, T a,\
    \ T b, T xor_val = 0) {\n    return wm.count(get_segments(s, t), a, b, xor_val);\n\
    \  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [a, b) \u306B\u53CE\u307E\u308B\
    \u3082\u306E\u3092\u6570\u3048\u308B\n  int count_subtree(int u, T a, T b, T xor_val\
    \ = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return wm.count(l + edge,\
    \ r, a, b, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L,\
    \ R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth_value_and_sum(get_segments(s,\
    \ t), k, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R)\
    \ \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\u3068 prefix sum\n  pair<T, X> kth_value_and_sum_subtree(int\
    \ u, int k, T xor_val = 0) {\n    int l = tree.LID[u], r = tree.RID[u];\n    return\
    \ wm.kth_value_and_sum(l + edge, r, k, xor_val);\n  }\n\n  // xor \u3057\u305F\
    \u7D50\u679C\u3067\u3001[L, R) \u306E\u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_path(int\
    \ s, int t, int k, T xor_val = 0) {\n    return wm.kth(get_segments(s, t), k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067 k>=0 \u756A\u76EE\n  T kth_subtree(int u, int k, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.kth(l + edge, r, k,\
    \ xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067\u3001[L, R) \u306E\
    \u4E2D\u3067\u4E2D\u592E\u5024\u3002\n  // LOWER = true\uFF1A\u4E0B\u5074\u4E2D\
    \u592E\u5024\u3001false\uFF1A\u4E0A\u5074\u4E2D\u592E\u5024\n  T median_path(bool\
    \ UPPER, int s, int t, T xor_val = 0) {\n    return wm.median(UPPER, get_segments(s,\
    \ t), xor_val);\n  }\n\n  T median_subtree(bool UPPER, int u, T xor_val = 0) {\n\
    \    int l = tree.LID[u], r = tree.RID[u];\n    return wm.median(UPPER, l + edge,\
    \ r, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2) \u756A\
    \u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\n  X sum_path(int\
    \ s, int t, int k1, int k2, T xor_val = 0) {\n    return wm.sum(get_segments(s,\
    \ t), k1, k2, xor_val);\n  }\n\n  // xor \u3057\u305F\u7D50\u679C\u3067 [k1, k2)\
    \ \u756A\u76EE\u3067\u3042\u308B\u3068\u3053\u308D\u306E SUM_data \u306E\u548C\
    \n  X sum_subtree(int u, int k1, int k2, T xor_val = 0) {\n    int l = tree.LID[u],\
    \ r = tree.RID[u];\n    return wm.sum(l + edge, r, k1, k2, xor_val);\n  }\n\n\
    \  X sum_all_path(int s, int t) { return wm.sum_all(get_segments(s, t)); }\n\n\
    \  X sum_all_subtree(int u) {\n    int l = tree.LID[u], r = tree.RID[u];\n   \
    \ return wm.sum_all(l + edge, r);\n  }\n\nprivate:\n  vc<pair<int, int>> get_segments(int\
    \ s, int t) {\n    vc<pair<int, int>> segments = tree.get_path_decomposition(s,\
    \ t, edge);\n    for (auto&& [a, b]: segments) {\n      if (a >= b) swap(a, b);\n\
    \      ++b;\n    }\n    return segments;\n  }\n};"
  dependsOn:
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - my_template.hpp
  - other/io.hpp
  - ds/index_compression.hpp
  - alg/monoid/add.hpp
  - graph/tree.hpp
  - graph/base.hpp
  isVerificationFile: false
  path: graph/ds/tree_wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-07-19 16:31:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/tree_wavelet_matrix.hpp
layout: document
redirect_from:
- /library/graph/ds/tree_wavelet_matrix.hpp
- /library/graph/ds/tree_wavelet_matrix.hpp.html
title: graph/ds/tree_wavelet_matrix.hpp
---
