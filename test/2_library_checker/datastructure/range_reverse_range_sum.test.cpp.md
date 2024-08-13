---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/splaytree/splaytree_commutative_monoid.hpp
    title: ds/splaytree/splaytree_commutative_monoid.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_reverse_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_reverse_range_sum
  bundledCode: "#line 1 \"test/2_library_checker/datastructure/range_reverse_range_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\n\
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
    \ yes(!t); }\r\n#line 2 \"ds/splaytree/splaytree.hpp\"\n// Node \u578B\u3092\u5225\
    \u306B\u5B9A\u7FA9\u3057\u3066\u4F7F\u3046\ntemplate <typename Node, int NODES\
    \ = 1'000'000>\nstruct SplayTree {\n  Node *pool;\n  int pid;\n  using np = Node\
    \ *;\n  using X = typename Node::value_type;\n  using A = typename Node::operator_type;\n\
    \  vc<np> FREE;\n\n  SplayTree() : pid(0) { pool = new Node[NODES]; }\n\n  void\
    \ free_subtree(np c) {\n    auto dfs = [&](auto &dfs, np c) -> void {\n      if\
    \ (c->l) dfs(dfs, c->l);\n      if (c->r) dfs(dfs, c->r);\n      FREE.eb(c);\n\
    \    };\n    dfs(dfs, c);\n  }\n\n  void reset() {\n    pid = 0;\n    FREE.clear();\n\
    \  }\n\n  np new_root() { return nullptr; }\n\n  np new_node(const X &x) {\n \
    \   np n = (FREE.empty() ? &(pool[pid++]) : POP(FREE));\n    Node::new_node(n,\
    \ x);\n    return n;\n  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs =\
    \ [&](auto &dfs, int l, int r) -> np {\n      if (l == r) return nullptr;\n  \
    \    if (r == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n  \
    \    np l_root = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1, r);\n    \
    \  np root = new_node(dat[m]);\n      root->l = l_root, root->r = r_root;\n  \
    \    if (l_root) l_root->p = root;\n      if (r_root) r_root->p = root;\n    \
    \  root->update();\n      return root;\n    };\n    return dfs(dfs, 0, len(dat));\n\
    \  }\n\n  u32 get_size(np root) { return (root ? root->size : 0); }\n\n  np merge(np\
    \ l_root, np r_root) {\n    if (!l_root) return r_root;\n    if (!r_root) return\
    \ l_root;\n    assert((!l_root->p) && (!r_root->p));\n    splay_kth(r_root, 0);\
    \ // splay \u3057\u305F\u306E\u3067 prop \u6E08\n    r_root->l = l_root;\n   \
    \ l_root->p = r_root;\n    r_root->update();\n    return r_root;\n  }\n  np merge3(np\
    \ a, np b, np c) { return merge(merge(a, b), c); }\n  np merge4(np a, np b, np\
    \ c, np d) { return merge(merge(merge(a, b), c), d); }\n\n  pair<np, np> split(np\
    \ root, u32 k) {\n    assert(!root || !root->p);\n    if (k == 0) return {nullptr,\
    \ root};\n    if (k == (root->size)) return {root, nullptr};\n    splay_kth(root,\
    \ k - 1);\n    np right = root->r;\n    root->r = nullptr, right->p = nullptr;\n\
    \    root->update();\n    return {root, right};\n  }\n  tuple<np, np, np> split3(np\
    \ root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root, r);\n\
    \    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n  tuple<np,\
    \ np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n    tie(root,\
    \ d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n    return {a,\
    \ b, c, d};\n  }\n\n  // \u90E8\u5206\u6728\u304C\u533A\u9593 [l,r) \u306B\u5BFE\
    \u5FDC\u3059\u308B\u3088\u3046\u306A\u30CE\u30FC\u30C9\u3092\u4F5C\u3063\u3066\
    \u8FD4\u3059\n  // \u305D\u306E\u30CE\u30FC\u30C9\u304C root \u306B\u306A\u308B\
    \u308F\u3051\u3067\u306F\u306A\u3044\u306E\u3067\u3001\n  // \u3053\u306E\u30CE\
    \u30FC\u30C9\u3092\u53C2\u7167\u3057\u305F\u5F8C\u306B\u3059\u3050\u306B splay\
    \ \u3057\u3066\u6839\u306B\u6301\u3061\u4E0A\u3052\u308B\u3053\u3068\n  void goto_between(np\
    \ &root, u32 l, u32 r) {\n    if (l == 0 && r == root->size) return;\n    if (l\
    \ == 0) {\n      splay_kth(root, r);\n      root = root->l;\n      return;\n \
    \   }\n    if (r == root->size) {\n      splay_kth(root, l - 1);\n      root =\
    \ root->r;\n      return;\n    }\n    splay_kth(root, r);\n    np rp = root;\n\
    \    root = rp->l;\n    root->p = nullptr;\n    splay_kth(root, l - 1);\n    root->p\
    \ = rp;\n    rp->l = root;\n    rp->update();\n    root = root->r;\n  }\n\n  vc<X>\
    \ get_all(const np &root) {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np\
    \ root) -> void {\n      if (!root) return;\n      root->prop();\n      dfs(dfs,\
    \ root->l);\n      res.eb(root->get());\n      dfs(dfs, root->r);\n    };\n  \
    \  dfs(dfs, root);\n    return res;\n  }\n\n  X get(np &root, u32 k) {\n    assert(root\
    \ == nullptr || !root->p);\n    splay_kth(root, k);\n    return root->get();\n\
    \  }\n\n  void set(np &root, u32 k, const X &x) {\n    assert(root != nullptr\
    \ && !root->p);\n    splay_kth(root, k);\n    root->set(x);\n  }\n\n  void multiply(np\
    \ &root, u32 k, const X &x) {\n    assert(root != nullptr && !root->p);\n    splay_kth(root,\
    \ k);\n    root->multiply(x);\n  }\n\n  X prod(np &root, u32 l, u32 r) {\n   \
    \ assert(root == nullptr || !root->p);\n    using Mono = typename Node::Monoid_X;\n\
    \    if (l == r) return Mono::unit();\n    assert(0 <= l && l < r && r <= root->size);\n\
    \    goto_between(root, l, r);\n    X res = root->prod;\n    splay(root, true);\n\
    \    return res;\n  }\n\n  X prod(np &root) {\n    assert(root == nullptr || !root->p);\n\
    \    using Mono = typename Node::Monoid_X;\n    return (root ? root->prod : Mono::unit());\n\
    \  }\n\n  void apply(np &root, u32 l, u32 r, const A &a) {\n    if (l == r) return;\n\
    \    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n\
    \    root->apply(a);\n    splay(root, true);\n  }\n  void apply(np &root, const\
    \ A &a) {\n    if (!root) return;\n    root->apply(a);\n  }\n\n  void reverse(np\
    \ &root, u32 l, u32 r) {\n    assert(root == nullptr || !root->p);\n    if (l\
    \ == r) return;\n    assert(0 <= l && l < r && r <= root->size);\n    goto_between(root,\
    \ l, r);\n    root->reverse();\n    splay(root, true);\n  }\n  void reverse(np\
    \ root) {\n    if (!root) return;\n    root->reverse();\n  }\n\n  void rotate(Node\
    \ *n) {\n    // n \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\u3002prop, update\
    \ \u306F rotate \u306E\u5916\u3067\u884C\u3046\u3002\n    Node *pp, *p, *c;\n\
    \    p = n->p;\n    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r\
    \ = p;\n      p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n    \
    \  p->r = c;\n    }\n    if (pp && pp->l == p) pp->l = n;\n    if (pp && pp->r\
    \ == p) pp->r = n;\n    n->p = pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\
    \n  void prop_from_root(np c) {\n    if (!c->p) {\n      c->prop();\n      return;\n\
    \    }\n    prop_from_root(c->p);\n    c->prop();\n  }\n\n  void splay(Node *me,\
    \ bool prop_from_root_done) {\n    // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\
    \u3067\u3001me \u306E\u7956\u5148\uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\
    \u306B prop \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\
    \u306B\u3001splay \u7D42\u4E86\u6642\u70B9\u3067 me \u306F upd / prop \u6E08\u3067\
    \u3042\u308B\n    if (!prop_from_root_done) prop_from_root(me);\n    me->prop();\n\
    \    while (me->p) {\n      np p = me->p;\n      np pp = p->p;\n      if (!pp)\
    \ {\n        rotate(me);\n        p->update();\n        break;\n      }\n    \
    \  bool same = (p->l == me && pp->l == p) || (p->r == me && pp->r == p);\n   \
    \   if (same) rotate(p), rotate(me);\n      if (!same) rotate(me), rotate(me);\n\
    \      pp->update(), p->update();\n    }\n    // me \u306E update \u306F\u6700\
    \u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n  }\n\n  void splay_kth(np\
    \ &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n    while (1) {\n\
    \      root->prop();\n      u32 sl = (root->l ? root->l->size : 0);\n      if\
    \ (k == sl) break;\n      if (k < sl)\n        root = root->l;\n      else {\n\
    \        k -= sl + 1;\n        root = root->r;\n      }\n    }\n    splay(root,\
    \ true);\n  }\n\n  // check(x), \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\
    \u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template\
    \ <typename F>\n  pair<np, np> split_max_right(np root, F check) {\n    if (!root)\
    \ return {nullptr, nullptr};\n    assert(!root->p);\n    np c = find_max_right(root,\
    \ check);\n    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n\
    \    }\n    splay(c, true);\n    np right = c->r;\n    if (!right) return {c,\
    \ nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n\
    \    return {c, right};\n  }\n\n  // check(x, cnt), \u5DE6\u5074\u306E\u30CE\u30FC\
    \u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\
    \u308B\n  template <typename F>\n  pair<np, np> split_max_right_cnt(np root, F\
    \ check) {\n    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n\
    \    np c = find_max_right_cnt(root, check);\n    if (!c) {\n      splay(root,\
    \ true);\n      return {nullptr, root};\n    }\n    splay(c, true);\n    np right\
    \ = c->r;\n    if (!right) return {c, nullptr};\n    right->p = nullptr;\n   \
    \ c->r = nullptr;\n    c->update();\n    return {c, right};\n  }\n\n  // \u5DE6\
    \u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u306E prod \u304C check \u3092\u6E80\
    \u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np,\
    \ np> split_max_right_prod(np root, F check) {\n    if (!root) return {nullptr,\
    \ nullptr};\n    assert(!root->p);\n    np c = find_max_right_prod(root, check);\n\
    \    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n    }\n\
    \    splay(c, true);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n\
    \    return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_cnt(np\
    \ root, const F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok\
    \ \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok\
    \ = nullptr, last = nullptr;\n    ll n = 0;\n    while (root) {\n      last =\
    \ root;\n      root->prop();\n      ll ns = (root->l ? root->l->size : 0);\n \
    \     if (check(root->x, n + ns + 1)) {\n        last_ok = root;\n        n +=\
    \ ns + 1;\n        root = root->r;\n      } else {\n        root = root->l;\n\
    \      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n\n  template\
    \ <typename F>\n  np find_max_right_prod(np root, const F &check) {\n    using\
    \ Mono = typename Node::Monoid_X;\n    X prod = Mono::unit();\n    // \u6700\u5F8C\
    \u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\
    \u3057\u305F\u70B9\n    np last_ok = nullptr, last = nullptr;\n    while (root)\
    \ {\n      last = root;\n      root->prop();\n      X lprod = prod;\n      if\
    \ (root->l) lprod = Mono::op(lprod, root->l->prod);\n      lprod = Mono::op(lprod,\
    \ root->x);\n      if (check(lprod)) {\n        prod = lprod;\n        last_ok\
    \ = root;\n        root = root->r;\n      } else {\n        root = root->l;\n\
    \      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n};\n#line 2\
    \ \"ds/splaytree/splaytree_commutative_monoid.hpp\"\n\nnamespace SplayTreeNodes\
    \ {\ntemplate <typename Monoid>\nstruct Node_CM {\n  using Monoid_X = Monoid;\n\
    \  using X = typename Monoid::value_type;\n  using value_type = X;\n  using operator_type\
    \ = int; // \u5B9A\u7FA9\u3060\u3051\u3057\u3066\u304A\u304F\n  using np = Node_CM\
    \ *;\n\n  np p, l, r;\n  X x, prod;\n  u32 size;\n  bool rev;\n\n  static void\
    \ new_node(np n, const X &x) {\n    n->p = n->l = n->r = nullptr;\n    n->x =\
    \ n->prod = x;\n    n->size = 1;\n    n->rev = 0;\n  }\n\n  void update() {\n\
    \    size = 1;\n    prod = x;\n    if (l) {\n      size += l->size;\n      prod\
    \ = Monoid::op(l->prod, prod);\n    }\n    if (r) {\n      size += r->size;\n\
    \      prod = Monoid::op(prod, r->prod);\n    }\n  }\n\n  void prop() {\n    if\
    \ (rev) {\n      if (l) {\n        l->rev ^= 1;\n        swap(l->l, l->r);\n \
    \     }\n      if (r) {\n        r->rev ^= 1;\n        swap(r->l, r->r);\n   \
    \   }\n      rev = 0;\n    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\
    \u3070\u308C\u308B\u3082\u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\
    \u3068\u304C\u60F3\u5B9A\u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\
    \u304C\u3063\u3066\u305D\u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  X get()\
    \ { return x; }\n  void set(const X &xx) {\n    x = xx;\n    update();\n  }\n\
    \  void multiply(const X &xx) {\n    x = Monoid::op(x, xx);\n    update();\n \
    \ }\n  void reverse() {\n    swap(l, r);\n    rev ^= 1;\n  }\n};\ntemplate <typename\
    \ Monoid, int NODES>\nusing SplayTree_Commutative_Monoid = SplayTree<Node_CM<Monoid>,\
    \ NODES>;\n} // namespace SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_Commutative_Monoid;\n\
    #line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 7 \"test/2_library_checker/datastructure/range_reverse_range_sum.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n\n  SplayTree_Commutative_Monoid<Monoid_Add<ll>,\
    \ 200'100> ST;\n  auto root = ST.new_node(A);\n\n  FOR(Q) {\n    LL(t, L, R);\n\
    \    if (t == 0) {\n      ST.reverse(root, L, R);\n    } else {\n      print(ST.prod(root,\
    \ L, R));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_reverse_range_sum\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/splaytree/splaytree_commutative_monoid.hpp\"\
    \n#include \"alg/monoid/add.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A,\
    \ N);\n\n  SplayTree_Commutative_Monoid<Monoid_Add<ll>, 200'100> ST;\n  auto root\
    \ = ST.new_node(A);\n\n  FOR(Q) {\n    LL(t, L, R);\n    if (t == 0) {\n     \
    \ ST.reverse(root, L, R);\n    } else {\n      print(ST.prod(root, L, R));\n \
    \   }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/splaytree/splaytree_commutative_monoid.hpp
  - ds/splaytree/splaytree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/2_library_checker/datastructure/range_reverse_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 23:38:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/datastructure/range_reverse_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/datastructure/range_reverse_range_sum.test.cpp
- /verify/test/2_library_checker/datastructure/range_reverse_range_sum.test.cpp.html
title: test/2_library_checker/datastructure/range_reverse_range_sum.test.cpp
---
