---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: flow/binary_optimization.hpp
    title: flow/binary_optimization.hpp
  - icon: ':question:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc193/tasks/abc193_f
    links:
    - https://atcoder.jp/contests/abc193/tasks/abc193_f
  bundledCode: "#line 1 \"test_atcoder/abc193f.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc193/tasks/abc193_f\"\
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
    \ yes(!t); }\r\n#line 1 \"flow/maxflow.hpp\"\n// incremental \u306B\u8FBA\u3092\
    \u8FFD\u52A0\u3057\u3066\u3088\u3044\ntemplate <typename Cap>\nstruct MaxFlow\
    \ {\n  struct Edge {\n    int to, rev;\n    Cap cap;\n    Cap flow = 0;\n  };\n\
    \n  const int N, source, sink;\n  vvc<Edge> edges;\n  vc<int> prog, level;\n \
    \ vc<int> que;\n  bool calculated;\n  Cap flow_ans;\n\n  MaxFlow(int N, int source,\
    \ int sink)\n      : N(N),\n        source(source),\n        sink(sink),\n   \
    \     edges(N),\n        calculated(0),\n        flow_ans(0) {}\n\n  void add(int\
    \ frm, int to, Cap cap, Cap rev_cap = 0) {\n    calculated = 0;\n    assert(0\
    \ <= frm && frm < N);\n    assert(0 <= to && to < N);\n    assert(frm != to);\n\
    \    assert(Cap(0) <= cap);\n    if (frm == to) return;\n    int a = len(edges[frm]);\n\
    \    int b = len(edges[to]);\n    edges[frm].eb(Edge{to, b, cap, 0});\n    edges[to].eb(Edge{frm,\
    \ a, rev_cap, 0});\n  }\n\n  // frm, to, flow\n  vc<tuple<int, int, Cap>> get_flow_edges()\
    \ {\n    vc<tuple<int, int, Cap>> res;\n    FOR(frm, N) {\n      for (auto&& e:\
    \ edges[frm]) {\n        if (e.flow <= 0) continue;\n        res.eb(frm, e.to,\
    \ e.flow);\n      }\n    }\n    return res;\n  }\n\n  // \u5DEE\u5206\u3067\u306F\
    \u306A\u304F\u3053\u308C\u307E\u3067\u306E\u7DCF\u91CF\n  Cap flow() {\n    if\
    \ (calculated) return flow_ans;\n    calculated = true;\n    while (set_level())\
    \ {\n      prog.assign(N, 0);\n      while (1) {\n        Cap x = flow_dfs(source,\
    \ infty<Cap>);\n        if (x == 0) break;\n        flow_ans += x;\n        chmin(flow_ans,\
    \ infty<Cap>);\n        if (flow_ans == infty<Cap>) return flow_ans;\n      }\n\
    \    }\n    return flow_ans;\n  }\n\n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\
    \u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\
    \u8FD4\u3059\n  pair<Cap, vc<int>> cut() {\n    flow();\n    vc<int> res(N);\n\
    \    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);\n    return {flow_ans, res};\n\
    \  }\n\n  // O(F(N+M)) \u304F\u3089\u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\
    \n  // simple path \u306B\u306A\u308B\n  vvc<int> path_decomposition() {\n   \
    \ flow();\n    auto edges = get_flow_edges();\n    vvc<int> TO(N);\n    for (auto&&\
    \ [frm, to, flow]: edges) { FOR(flow) TO[frm].eb(to); }\n    vvc<int> res;\n \
    \   vc<int> vis(N);\n\n    FOR(flow_ans) {\n      vc<int> path = {source};\n \
    \     vis[source] = 1;\n      while (path.back() != sink) {\n        int to =\
    \ POP(TO[path.back()]);\n        while (vis[to]) { vis[POP(path)] = 0; }\n   \
    \     path.eb(to), vis[to] = 1;\n      }\n      for (auto&& v: path) vis[v] =\
    \ 0;\n      res.eb(path);\n    }\n    return res;\n  }\n\n  void debug() {\n \
    \   print(\"source\", source);\n    print(\"sink\", sink);\n    print(\"edges\
    \ (frm, to, cap, flow)\");\n    FOR(v, N) {\n      for (auto& e: edges[v]) {\n\
    \        if (e.cap == 0 && e.flow == 0) continue;\n        print(v, e.to, e.cap,\
    \ e.flow);\n      }\n    }\n  }\n\nprivate:\n  bool set_level() {\n    que.resize(N);\n\
    \    level.assign(N, -1);\n    level[source] = 0;\n    int l = 0, r = 0;\n   \
    \ que[r++] = source;\n    while (l < r) {\n      int v = que[l++];\n      for\
    \ (auto&& e: edges[v]) {\n        if (e.cap > 0 && level[e.to] == -1) {\n    \
    \      level[e.to] = level[v] + 1;\n          if (e.to == sink) return true;\n\
    \          que[r++] = e.to;\n        }\n      }\n    }\n    return false;\n  }\n\
    \n  Cap flow_dfs(int v, Cap lim) {\n    if (v == sink) return lim;\n    Cap res\
    \ = 0;\n    for (int& i = prog[v]; i < len(edges[v]); ++i) {\n      auto& e =\
    \ edges[v][i];\n      if (e.cap > 0 && level[e.to] == level[v] + 1) {\n      \
    \  Cap a = flow_dfs(e.to, min(lim, e.cap));\n        if (a > 0) {\n          e.cap\
    \ -= a, e.flow += a;\n          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow\
    \ -= a;\n          res += a;\n          lim -= a;\n          if (lim == 0) break;\n\
    \        }\n      }\n    }\n    return res;\n  }\n};\n#line 2 \"flow/binary_optimization.hpp\"\
    \n\ntemplate <typename T, bool MINIMIZE>\nstruct Binary_Optimization {\n  int\
    \ n;\n  int nxt;\n  int source, sink;\n  T base_cost;\n  map<pair<int, int>, T>\
    \ edges;\n\n  Binary_Optimization(int n) : n(n), base_cost(0) {\n    source =\
    \ n;\n    sink = n + 1;\n    nxt = n + 2;\n  }\n\n  // xi \u3092 0, 1 \u306B\u3059\
    \u308B\u3068\u304D\u306B\u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\
    \u3059\u308B\u3002\n  void add_1(int i, T x0, T x1) {\n    assert(0 <= i && i\
    \ < n);\n    if (!MINIMIZE) { x0 = -x0, x1 = -x1; }\n    _add_1(i, x0, x1);\n\
    \  }\n\n  // (xi,xj) = (00,01,10,11) \u3068\u3059\u308B\u3068\u304D\u306B\u304B\
    \u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\u3002\n  // \u30B3\
    \u30B9\u30C8\u304C\u52A3\u30E2 x00 + x11 <= x10 + x10 \u306B\u306A\u3063\u3066\
    \u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n  // \u7279\u306B\u3001\u5BFE\
    \u89D2\u6210\u5206\u306B\u5229\u5F97\u3092\u4E0E\u3048\u308B\u3053\u3068\u304C\
    \u3067\u304D\u308B\u3002\n  void add_2(int i, int j, T x00, T x01, T x10, T x11)\
    \ {\n    assert(i != j);\n    assert(0 <= i && i < n);\n    assert(0 <= j && j\
    \ < n);\n    if (!MINIMIZE) {\n      x00 = -x00, x01 = -x01;\n      x10 = -x10,\
    \ x11 = -x11;\n    }\n    _add_2(i, j, x00, x01, x10, x11);\n  }\n\n  // (xi,xj,xk)\
    \ = (000,001,010,011,100,101,110,111)\n  // \u3068\u3059\u308B\u3068\u304D\u306B\
    \u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\u3002\u52A3\
    \u30E2\u306B\u306A\u3063\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\
    \n  // \u7279\u306B\u3001000 \u3084 111 \u306B\u5229\u5F97\u3092\u4E0E\u3048\u308B\
    \u3053\u3068\u304C\u3067\u304D\u308B\u3002\n  void add_3(int i, int j, int k,\
    \ T x000, T x001, T x010, T x011, T x100,\n             T x101, T x110, T x111)\
    \ {\n    assert(i != j && i != k && j != k);\n    assert(0 <= i && i < n);\n \
    \   assert(0 <= j && j < n);\n    assert(0 <= k && k < n);\n    if (!MINIMIZE)\
    \ {\n      x000 = -x000, x001 = -x001;\n      x010 = -x010, x011 = -x011;\n  \
    \    x100 = -x100, x101 = -x101;\n      x110 = -x110, x111 = -x111;\n    }\n \
    \   _add_3(i, j, k, x000, x001, x010, x011, x100, x101, x110, x111);\n  }\n\n\
    \  // \u6700\u5C0F\u5024\u304A\u3088\u3073\u300101 \u5217\u3092\u8FD4\u3059\n\
    \  pair<T, vc<int>> calc() {\n    MaxFlow<T> G(nxt, source, sink);\n    for (auto&&\
    \ [key, cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm, to, cap);\n\
    \    }\n\n    auto [val, cut] = G.cut();\n    val += base_cost;\n    chmin(val,\
    \ infty<T>);\n    cut.resize(n);\n    if (!MINIMIZE) val = -val;\n    return {val,\
    \ cut};\n  }\n\n  void debug() {\n    print(\"base_cost\", base_cost);\n    print(\"\
    source=\", source, \"sink=\", sink);\n    for (auto&& [key, cap]: edges) print(key,\
    \ cap);\n  }\n\nprivate:\n  void add_edge(int i, int j, T t) {\n    assert(t >=\
    \ 0);\n    if (t == 0) return;\n    pair<int, int> key = mp(i, j);\n    edges[key]\
    \ += t;\n    chmin(edges[key], infty<T>);\n  }\n\n  void _add_1(int i, T x0, T\
    \ x1) {\n    if (x0 <= x1) {\n      base_cost += x0;\n      add_edge(source, i,\
    \ x1 - x0);\n    } else {\n      base_cost += x1;\n      add_edge(i, sink, x0\
    \ - x1);\n    }\n  }\n\n  void _add_2(int i, int j, T x00, T x01, T x10, T x11)\
    \ {\n    assert(x00 + x11 <= x01 + x10);\n    _add_1(i, x00, x10);\n    _add_1(j,\
    \ 0, x11 - x10);\n    add_edge(i, j, x01 + x10 - x00 - x11);\n  }\n\n  void _add_3(int\
    \ i, int j, int k, T x000, T x001, T x010, T x011, T x100,\n              T x101,\
    \ T x110, T x111) {\n    T p = x000 - x100 - x010 - x001 + x110 + x101 + x011\
    \ - x111;\n    if (p > 0) {\n      base_cost += x000;\n      _add_1(i, 0, x100\
    \ - x000);\n      _add_1(j, 0, x010 - x000);\n      _add_1(k, 0, x001 - x000);\n\
    \      _add_2(i, j, 0, 0, 0, x000 + x110 - x100 - x010);\n      _add_2(i, k, 0,\
    \ 0, 0, x000 + x101 - x100 - x001);\n      _add_2(j, k, 0, 0, 0, x000 + x011 -\
    \ x010 - x001);\n      // \u3042\u3068\u306F\u3001111 \u306E\u3068\u304D\u306B\
    \u5229\u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      //\
    \ 111 \u4EE5\u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(i, nxt, p);\n\
    \      add_edge(j, nxt, p);\n      add_edge(k, nxt, p);\n      add_edge(nxt, sink,\
    \ p);\n      ++nxt;\n    } else {\n      p = -p;\n      base_cost += x111;\n \
    \     _add_1(i, x011 - x111, 0);\n      _add_1(i, x101 - x111, 0);\n      _add_1(i,\
    \ x110 - x111, 0);\n      _add_2(i, j, x111 + x001 - x011 - x101, 0, 0, 0);\n\
    \      _add_2(i, k, x111 + x010 - x011 - x110, 0, 0, 0);\n      _add_2(j, k, x111\
    \ + x100 - x101 - x110, 0, 0, 0);\n      // 000 \u306E\u3068\u304D\u306B\u5229\
    \u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      // 000 \u4EE5\
    \u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(nxt, i, p);\n      add_edge(nxt,\
    \ j, p);\n      add_edge(nxt, k, p);\n      add_edge(source, nxt, p);\n      ++nxt;\n\
    \    }\n  }\n};\n#line 5 \"test_atcoder/abc193f.test.cpp\"\n\nvoid solve() {\n\
    \  LL(N);\n  VEC(string, G, N);\n  const int INF = infty<int>;\n  Binary_Optimization<ll,\
    \ 0> X(N * N);\n  auto idx = [&](int i, int j) -> int { return N * i + j; };\n\
    \n  FOR(i, N) FOR(j, N) {\n    int sgn = (i + j) % 2;\n    if (G[i][j] == 'B'\
    \ && sgn == 0) X.add_1(idx(i, j), -INF, 0);\n    if (G[i][j] == 'W' && sgn ==\
    \ 1) X.add_1(idx(i, j), -INF, 0);\n    if (G[i][j] == 'B' && sgn == 1) X.add_1(idx(i,\
    \ j), 0, -INF);\n    if (G[i][j] == 'W' && sgn == 0) X.add_1(idx(i, j), 0, -INF);\n\
    \  }\n\n  int dx[] = {0, 1};\n  int dy[] = {1, 0};\n\n  FOR(x, N) FOR(y, N) {\n\
    \    FOR(d, 2) {\n      int nx = x + dx[d], ny = y + dy[d];\n      if (nx >= N\
    \ || ny >= N) continue;\n      int a = idx(x, y), b = idx(nx, ny);\n      X.add_2(a,\
    \ b, 1, 0, 0, 1);\n    }\n  }\n\n  ll ANS = X.calc().fi;\n  print(ANS);\n}\n\n\
    signed main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc193/tasks/abc193_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/binary_optimization.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VEC(string, G, N);\n  const int INF = infty<int>;\n\
    \  Binary_Optimization<ll, 0> X(N * N);\n  auto idx = [&](int i, int j) -> int\
    \ { return N * i + j; };\n\n  FOR(i, N) FOR(j, N) {\n    int sgn = (i + j) % 2;\n\
    \    if (G[i][j] == 'B' && sgn == 0) X.add_1(idx(i, j), -INF, 0);\n    if (G[i][j]\
    \ == 'W' && sgn == 1) X.add_1(idx(i, j), -INF, 0);\n    if (G[i][j] == 'B' &&\
    \ sgn == 1) X.add_1(idx(i, j), 0, -INF);\n    if (G[i][j] == 'W' && sgn == 0)\
    \ X.add_1(idx(i, j), 0, -INF);\n  }\n\n  int dx[] = {0, 1};\n  int dy[] = {1,\
    \ 0};\n\n  FOR(x, N) FOR(y, N) {\n    FOR(d, 2) {\n      int nx = x + dx[d], ny\
    \ = y + dy[d];\n      if (nx >= N || ny >= N) continue;\n      int a = idx(x,\
    \ y), b = idx(nx, ny);\n      X.add_2(a, b, 1, 0, 0, 1);\n    }\n  }\n\n  ll ANS\
    \ = X.calc().fi;\n  print(ANS);\n}\n\nsigned main() {\n  solve();\n  return 0;\n\
    }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/binary_optimization.hpp
  - flow/maxflow.hpp
  isVerificationFile: true
  path: test_atcoder/abc193f.test.cpp
  requiredBy: []
  timestamp: '2024-02-02 01:26:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test_atcoder/abc193f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc193f.test.cpp
- /verify/test_atcoder/abc193f.test.cpp.html
title: test_atcoder/abc193f.test.cpp
---