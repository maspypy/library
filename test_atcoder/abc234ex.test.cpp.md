---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/kdtree/kdtree.hpp
    title: ds/kdtree/kdtree.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc234/tasks/abc234_Ex
    links:
    - https://atcoder.jp/contests/abc234/tasks/abc234_Ex
  bundledCode: "#line 1 \"test_atcoder/abc234ex.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc234/tasks/abc234_Ex\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// \u53C2\u8003 https://codeforces.com/blog/entry/96344\n// bmi,bmi2,lzcnt\
    \ \u306F ucup \u3067\u30B3\u30F3\u30D1\u30A4\u30EB\u30A8\u30E9\u30FC\n#pragma\
    \ GCC optimize(\"Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\")\n\n\
    #include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'000'000'000;\n\
    template <>\nconstexpr ll infty<ll> = ll(infty<int>) * infty<int> * 2;\ntemplate\
    \ <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * infty<ll>;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    using fastio::flush;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n\
    \  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define U32(...)   \\\r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ U64(...)   \\\r\n  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)\
    \      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\n#line 4 \"test_atcoder/abc234ex.test.cpp\"\n\n#line 1 \"ds/kdtree/kdtree.hpp\"\
    \ntemplate <typename XY>\nstruct KDTree {\n  // \u5C0F\u6570\u3082\u8003\u616E\
    \u3059\u308B\u3068\u3001\u9589\u3067\u6301\u3064\u8A2D\u8A08\u65B9\u91DD\u306B\
    \u306A\u308B\u3002\u305F\u3060\u3057\u3001\u30AF\u30A8\u30EA\u306F\u3044\u3064\
    \u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\n  vc<tuple<XY, XY, XY, XY>> closed_range;\n\
    \  // \u540C\u3058\u5EA7\u6A19\u306E\u70B9\u3082\u96C6\u7D04\u3057\u306A\u3044\
    \u3088\u3046\u306B\u3057\u3066\u3001\u5EA7\u6A19\u3054\u3068\u306B unique \u306A\
    \u30C7\u30FC\u30BF\u3092\u4F7F\u3046\n  vc<int> dat;\n  int n;\n\n  KDTree(vc<XY>\
    \ xs, vc<XY> ys) : n(len(xs)) {\n    int log = 0;\n    while ((1 << log) < n)\
    \ ++log;\n    dat.assign(1 << (log + 1), -1);\n    closed_range.resize(1 << (log\
    \ + 1));\n    vc<int> vs(n);\n    iota(all(vs), 0);\n    if (n > 0) build(1, xs,\
    \ ys, vs);\n  }\n\n  // [xl, xr) x [yl, yr)\n  vc<int> collect_rect(XY xl, XY\
    \ xr, XY yl, XY yr, int max_size = -1) {\n    assert(xl <= xr && yl <= yr);\n\
    \    if (max_size == -1) max_size = n;\n    vc<int> res;\n    rect_rec(1, xl,\
    \ xr, yl, yr, res, max_size);\n    return res;\n  }\n\n  // \u8A08\u7B97\u91CF\
    \u4FDD\u8A3C\u306A\u3057\u3001\u70B9\u7FA4\u304C\u30E9\u30F3\u30C0\u30E0\u306A\
    \u3089 O(logN)\n  // N = Q = 10^5 \u3067\u3001\u7D04 1 \u79D2\n  // T \u306F\u5EA7\
    \u6A19\u306E 2 \u4E57\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\
    \u3044\u3082\u306E\u3092\u4F7F\u3046\u3002XY=int, T=long \u306A\u3069\u3002\n\
    \  template <typename T>\n  int nearest_neighbor_search(XY x, XY y) {\n    if\
    \ (n == 0) return -1;\n    pair<int, T> res = {-1, -1};\n    nns_rec(1, x, y,\
    \ res);\n    return res.fi;\n  }\n\nprivate:\n  void build(int idx, vc<XY> xs,\
    \ vc<XY> ys, vc<int> vs, bool divx = true) {\n    int n = len(xs);\n    auto&\
    \ [xmin, xmax, ymin, ymax] = closed_range[idx];\n    xmin = ymin = infty<XY>;\n\
    \    xmax = ymax = -infty<XY>;\n\n    FOR(i, n) {\n      auto x = xs[i], y = ys[i];\n\
    \      chmin(xmin, x), chmax(xmax, x), chmin(ymin, y), chmax(ymax, y);\n    }\n\
    \    if (n == 1) {\n      dat[idx] = vs[0];\n      return;\n    }\n\n    int m\
    \ = n / 2;\n    vc<int> I(n);\n    iota(all(I), 0);\n    if (divx) {\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\n                  [xs](int i, int j) { return xs[i]\
    \ < xs[j]; });\n    } else {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n\
    \                  [ys](int i, int j) { return ys[i] < ys[j]; });\n    }\n   \
    \ xs = rearrange(xs, I), ys = rearrange(ys, I), vs = rearrange(vs, I);\n    build(2\
    \ * idx + 0, {xs.begin(), xs.begin() + m},\n          {ys.begin(), ys.begin()\
    \ + m}, {vs.begin(), vs.begin() + m}, !divx);\n    build(2 * idx + 1, {xs.begin()\
    \ + m, xs.end()}, {ys.begin() + m, ys.end()},\n          {vs.begin() + m, vs.end()},\
    \ !divx);\n  }\n\n  void rect_rec(int i, XY x1, XY x2, XY y1, XY y2, vc<int>&\
    \ res, int ms) {\n    if (len(res) == ms) return;\n    auto& [xmin, xmax, ymin,\
    \ ymax] = closed_range[i];\n    if (x2 <= xmin || xmax < x1) return;\n    if (y2\
    \ <= ymin || ymax < y1) return;\n    if (dat[i] != -1) {\n      res.eb(dat[i]);\n\
    \      return;\n    }\n    rect_rec(2 * i + 0, x1, x2, y1, y2, res, ms);\n   \
    \ rect_rec(2 * i + 1, x1, x2, y1, y2, res, ms);\n  }\n\n  template <typename T>\n\
    \  T best_dist_squared(int i, XY x, XY y) {\n    auto& [xmin, xmax, ymin, ymax]\
    \ = closed_range[i];\n    T dx = x - clamp(x, xmin, xmax);\n    T dy = y - clamp(y,\
    \ ymin, ymax);\n    return dx * dx + dy * dy;\n  }\n\n  template <typename T>\n\
    \  void nns_rec(int i, XY x, XY y, pair<int, T>& res) {\n    T d = best_dist_squared<T>(i,\
    \ x, y);\n    if (res.fi != -1 && d >= res.se) return;\n    if (dat[i] != -1)\
    \ {\n      res = {dat[i], d};\n      return;\n    }\n    T d0 = best_dist_squared<T>(2\
    \ * i + 0, x, y);\n    T d1 = best_dist_squared<T>(2 * i + 1, x, y);\n    if (d0\
    \ < d1) {\n      nns_rec(2 * i + 0, x, y, res), nns_rec(2 * i + 1, x, y, res);\n\
    \    } else {\n      nns_rec(2 * i + 1, x, y, res), nns_rec(2 * i + 0, x, y, res);\n\
    \    }\n  }\n};\n#line 6 \"test_atcoder/abc234ex.test.cpp\"\n\nvoid solve() {\n\
    \  LL(N, K);\n  vc<int> X(N), Y(N);\n  FOR(i, N) {\n    INT(a, b);\n    X[i] =\
    \ a, Y[i] = b;\n  }\n  KDTree<int> KDT(X, Y);\n\n  int x_min = MIN(X);\n  int\
    \ x_max = MAX(X);\n  int y_min = MIN(Y);\n  int y_max = MAX(Y);\n\n  vc<pair<int,\
    \ int>> ANS;\n  FOR(i, N) {\n    ll a = X[i] - K, b = X[i] + K + 1, c = Y[i] -\
    \ K, d = Y[i] + K + 1;\n    chmax(a, x_min), chmin(b, x_max + 1);\n    chmax(c,\
    \ y_min), chmin(d, y_max + 1);\n    vc<int> I = KDT.collect_rect(a, b, c, d);\n\
    \    sort(all(I));\n    for (auto&& j: I) {\n      if (i >= j) continue;\n   \
    \   ll dx = X[i] - X[j], dy = Y[i] - Y[j];\n      if (dx * dx + dy * dy <= K *\
    \ K) { ANS.eb(i, j); }\n    }\n  }\n  print(len(ANS));\n  for (auto&& [i, j]:\
    \ ANS) print(1 + i, 1 + j);\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc234/tasks/abc234_Ex\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/kdtree/kdtree.hpp\"\
    \n\nvoid solve() {\n  LL(N, K);\n  vc<int> X(N), Y(N);\n  FOR(i, N) {\n    INT(a,\
    \ b);\n    X[i] = a, Y[i] = b;\n  }\n  KDTree<int> KDT(X, Y);\n\n  int x_min =\
    \ MIN(X);\n  int x_max = MAX(X);\n  int y_min = MIN(Y);\n  int y_max = MAX(Y);\n\
    \n  vc<pair<int, int>> ANS;\n  FOR(i, N) {\n    ll a = X[i] - K, b = X[i] + K\
    \ + 1, c = Y[i] - K, d = Y[i] + K + 1;\n    chmax(a, x_min), chmin(b, x_max +\
    \ 1);\n    chmax(c, y_min), chmin(d, y_max + 1);\n    vc<int> I = KDT.collect_rect(a,\
    \ b, c, d);\n    sort(all(I));\n    for (auto&& j: I) {\n      if (i >= j) continue;\n\
    \      ll dx = X[i] - X[j], dy = Y[i] - Y[j];\n      if (dx * dx + dy * dy <=\
    \ K * K) { ANS.eb(i, j); }\n    }\n  }\n  print(len(ANS));\n  for (auto&& [i,\
    \ j]: ANS) print(1 + i, 1 + j);\n}\n\nsigned main() {\n  solve();\n\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/kdtree/kdtree.hpp
  isVerificationFile: true
  path: test_atcoder/abc234ex.test.cpp
  requiredBy: []
  timestamp: '2024-02-02 01:26:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_atcoder/abc234ex.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc234ex.test.cpp
- /verify/test_atcoder/abc234ex.test.cpp.html
title: test_atcoder/abc234ex.test.cpp
---