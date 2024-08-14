---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/sparse_table/disjoint_sparse_table.hpp
    title: ds/sparse_table/disjoint_sparse_table.hpp
  - icon: ':question:'
    path: ds/sparse_table/sparse_table.hpp
    title: ds/sparse_table/sparse_table.hpp
  - icon: ':heavy_check_mark:'
    path: ds/static_range_product.hpp
    title: ds/static_range_product.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/2_library_checker/datastructure/staticrmq.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128 =\
    \ __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
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
    \ yes(!t); }\r\n#line 4 \"test/2_library_checker/datastructure/staticrmq.test.cpp\"\
    \n\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Min\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit()\
    \ { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line\
    \ 2 \"ds/sparse_table/sparse_table.hpp\"\n\n// \u51AA\u7B49\u306A\u30E2\u30CE\u30A4\
    \u30C9\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3002disjoint sparse table\
    \ \u3088\u308A x \u500D\u9AD8\u901F\ntemplate <class Monoid>\nstruct Sparse_Table\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  int n, log;\n\
    \  vvc<X> dat;\n\n  Sparse_Table() {}\n  Sparse_Table(int n) { build(n); }\n \
    \ template <typename F>\n  Sparse_Table(int n, F f) {\n    build(n, f);\n  }\n\
    \  Sparse_Table(const vc<X>& v) { build(v); }\n\n  void build(int m) {\n    build(m,\
    \ [](int i) -> X { return MX::unit(); });\n  }\n  void build(const vc<X>& v) {\n\
    \    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m, log = 1;\n    while ((1 << log) <\
    \ n) ++log;\n    dat.resize(log);\n    dat[0].resize(n);\n    FOR(i, n) dat[0][i]\
    \ = f(i);\n\n    FOR(i, log - 1) {\n      dat[i + 1].resize(len(dat[i]) - (1 <<\
    \ i));\n      FOR(j, len(dat[i]) - (1 << i)) {\n        dat[i + 1][j] = MX::op(dat[i][j],\
    \ dat[i][j + (1 << i)]);\n      }\n    }\n  }\n\n  X prod(int L, int R) {\n  \
    \  if (L == R) return MX::unit();\n    if (R == L + 1) return dat[0][L];\n   \
    \ int k = topbit(R - L - 1);\n    return MX::op(dat[k][L], dat[k][R - (1 << k)]);\n\
    \  }\n\n  template <class F>\n  int max_right(const F check, int L) {\n    assert(0\
    \ <= L && L <= n && check(MX::unit()));\n    if (L == n) return n;\n    int ok\
    \ = L, ng = n + 1;\n    while (ok + 1 < ng) {\n      int k = (ok + ng) / 2;\n\
    \      bool bl = check(prod(L, k));\n      if (bl) ok = k;\n      if (!bl) ng\
    \ = k;\n    }\n    return ok;\n  }\n\n  template <class F>\n  int min_left(const\
    \ F check, int R) {\n    assert(0 <= R && R <= n && check(MX::unit()));\n    if\
    \ (R == 0) return 0;\n    int ok = R, ng = -1;\n    while (ng + 1 < ok) {\n  \
    \    int k = (ok + ng) / 2;\n      bool bl = check(prod(k, R));\n      if (bl)\
    \ ok = k;\n      if (!bl) ng = k;\n    }\n    return ok;\n  }\n};\n#line 2 \"\
    ds/sparse_table/disjoint_sparse_table.hpp\"\n\r\ntemplate <class Monoid>\r\nstruct\
    \ Disjoint_Sparse_Table {\r\n  using MX = Monoid;\r\n  using X = typename MX::value_type;\r\
    \n  int n, log;\r\n  vvc<X> dat;\r\n\r\n  Disjoint_Sparse_Table() {}\r\n  Disjoint_Sparse_Table(int\
    \ n) { build(n); }\r\n  template <typename F>\r\n  Disjoint_Sparse_Table(int n,\
    \ F f) {\r\n    build(n, f);\r\n  }\r\n  Disjoint_Sparse_Table(const vc<X>& v)\
    \ { build(v); }\r\n\r\n  void build(int m) {\r\n    build(m, [](int i) -> X {\
    \ return MX::unit(); });\r\n  }\r\n  void build(const vc<X>& v) {\r\n    build(len(v),\
    \ [&](int i) -> X { return v[i]; });\r\n  }\r\n  template <typename F>\r\n  void\
    \ build(int m, F f) {\r\n    n = m, log = 1;\r\n    while ((1 << log) < n) ++log;\r\
    \n    dat.resize(log);\r\n    dat[0].reserve(n);\r\n    FOR(i, n) dat[0].eb(f(i));\r\
    \n    FOR(i, 1, log) {\r\n      auto& v = dat[i];\r\n      v = dat[0];\r\n   \
    \   int b = 1 << i;\r\n      for (int m = b; m <= n; m += 2 * b) {\r\n       \
    \ int L = m - b, R = min(n, m + b);\r\n        FOR_R(j, L + 1, m) v[j - 1] = MX::op(v[j\
    \ - 1], v[j]);\r\n        FOR(j, m, R - 1) v[j + 1] = MX::op(v[j], v[j + 1]);\r\
    \n      }\r\n    }\r\n  }\r\n\r\n  X prod(int L, int R) {\r\n    if (L == R) return\
    \ MX::unit();\r\n    --R;\r\n    if (L == R) return dat[0][L];\r\n    int k =\
    \ topbit(L ^ R);\r\n    return MX::op(dat[k][L], dat[k][R]);\r\n  }\r\n\r\n  template\
    \ <class F>\r\n  int max_right(const F check, int L) {\r\n    assert(0 <= L &&\
    \ L <= n && check(MX::unit()));\r\n    if (L == n) return n;\r\n    int ok = L,\
    \ ng = n + 1;\r\n    while (ok + 1 < ng) {\r\n      int k = (ok + ng) / 2;\r\n\
    \      bool bl = check(prod(L, k));\r\n      if (bl) ok = k;\r\n      if (!bl)\
    \ ng = k;\r\n    }\r\n    return ok;\r\n  }\r\n\r\n  template <class F>\r\n  int\
    \ min_left(const F check, int R) {\r\n    assert(0 <= R && R <= n && check(MX::unit()));\r\
    \n    if (R == 0) return 0;\r\n    int ok = R, ng = -1;\r\n    while (ng + 1 <\
    \ ok) {\r\n      int k = (ok + ng) / 2;\r\n      bool bl = check(prod(k, R));\r\
    \n      if (bl) ok = k;\r\n      if (!bl) ng = k;\r\n    }\r\n    return ok;\r\
    \n  }\r\n};\n#line 3 \"ds/static_range_product.hpp\"\n\n/*\n\u53C2\u8003\uFF1A\
    https://judge.yosupo.jp/submission/106668\n\u9577\u3055 2^LOG \u306E\u30D6\u30ED\
    \u30C3\u30AF\u306B\u5206\u3051\u308B\uFF0E\u30D6\u30ED\u30C3\u30AF\u5185\u306E\
    \ prefix, suffix \u3092\u6301\u3064\uFF0E\n\u30D6\u30ED\u30C3\u30AF\u7A4D\u306E\
    \u5217\u3092 ST(DST) \u3067\u6301\u3064\uFF0E\u30D6\u30ED\u30C3\u30AF\u3092\u307E\
    \u305F\u3050\u7A4D\u306F O(1).\n\u77ED\u3044\u3082\u306E\u306F O(1) \u3092\u8AE6\
    \u3081\u3066\u611A\u76F4\u3068\u3044\u3046\u3053\u3068\u306B\u3059\u308B\uFF0E\
    \n\u524D\u8A08\u7B97\uFF1AO(Nlog(N)/2^LOG)\n\u30AF\u30A8\u30EA\uFF1AO(1) / worst\
    \ O(2^LOG)\n*/\ntemplate <typename Monoid, typename SPARSE_TABLE, int LOG = 4>\n\
    struct Static_Range_Product {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  int N, b_num;\n  vc<X> A, pre, suf; // inclusive\n  SPARSE_TABLE ST;\n\n  Static_Range_Product()\
    \ {}\n  template <typename F>\n  Static_Range_Product(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Static_Range_Product(const vc<X>& v) { build(v); }\n\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    N = m;\n    b_num = N >> LOG;\n\
    \    A.resize(N);\n    FOR(i, N) A[i] = f(i);\n    pre = A, suf = A;\n    constexpr\
    \ int mask = (1 << LOG) - 1;\n    FOR(i, 1, N) {\n      if (i & mask) pre[i] =\
    \ MX::op(pre[i - 1], A[i]);\n    }\n    FOR_R(i, 1, N) {\n      if (i & mask)\
    \ suf[i - 1] = MX::op(A[i - 1], suf[i]);\n    }\n    ST.build(b_num, [&](int i)\
    \ -> X { return suf[i << LOG]; });\n  }\n\n  // O(1) or O(R-L)\n  X prod(int L,\
    \ int R) {\n    if (L == R) return MX::unit();\n    R -= 1;\n    int a = L >>\
    \ LOG, b = R >> LOG;\n    if (a < b) {\n      X x = ST.prod(a + 1, b);\n     \
    \ x = MX::op(suf[L], x);\n      x = MX::op(x, pre[R]);\n      return x;\n    }\n\
    \    X x = A[L];\n    FOR(i, L + 1, R + 1) x = MX::op(x, A[i]);\n    return x;\n\
    \  }\n};\n#line 7 \"test/2_library_checker/datastructure/staticrmq.test.cpp\"\n\
    \nsigned main() {\n  using Mono = Monoid_Min<u32>;\n  using ST = Sparse_Table<Mono>;\n\
    \  INT(N, Q);\n  Static_Range_Product<Mono, ST> X(N, [&](int i) -> u32 {\n   \
    \ u32 x;\n    read(x);\n    return x;\n  });\n  FOR(Q) {\n    u32 L, R;\n    read(L,\
    \ R);\n    print(X.prod(L, R));\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n#include \"\
    my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/monoid/min.hpp\"\
    \n#include \"ds/static_range_product.hpp\"\n\nsigned main() {\n  using Mono =\
    \ Monoid_Min<u32>;\n  using ST = Sparse_Table<Mono>;\n  INT(N, Q);\n  Static_Range_Product<Mono,\
    \ ST> X(N, [&](int i) -> u32 {\n    u32 x;\n    read(x);\n    return x;\n  });\n\
    \  FOR(Q) {\n    u32 L, R;\n    read(L, R);\n    print(X.prod(L, R));\n  }\n \
    \ return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/monoid/min.hpp
  - ds/static_range_product.hpp
  - ds/sparse_table/sparse_table.hpp
  - ds/sparse_table/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/2_library_checker/datastructure/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 23:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/datastructure/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/datastructure/staticrmq.test.cpp
- /verify/test/2_library_checker/datastructure/staticrmq.test.cpp.html
title: test/2_library_checker/datastructure/staticrmq.test.cpp
---
