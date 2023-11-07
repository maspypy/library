---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/my_multiset.hpp
    title: ds/my_multiset.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc281/tasks/abc281_e
    links:
    - https://atcoder.jp/contests/abc281/tasks/abc281_e
  bundledCode: "#line 1 \"test_atcoder/abc281e.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc281/tasks/abc281_e\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
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
    \ + pir - pil, 1, SZ - pir + pil, stdin);\r\n  pil = 0;\r\n}\r\n\r\ninline void\
    \ flush() {\r\n  fwrite(obuf, 1, por, stdout);\r\n  por = 0;\r\n}\r\n\r\nvoid\
    \ rd(char &c) {\r\n  do {\r\n    if (pil + 1 > pir) load();\r\n    c = ibuf[pil++];\r\
    \n  } while (isspace(c));\r\n}\r\n\r\nvoid rd(string &x) {\r\n  x.clear();\r\n\
    \  char c;\r\n  do {\r\n    if (pil + 1 > pir) load();\r\n    c = ibuf[pil++];\r\
    \n  } while (isspace(c));\r\n  do {\r\n    x += c;\r\n    if (pil == pir) load();\r\
    \n    if (pil == pir) break;\r\n    c = ibuf[pil++];\r\n  } while (!isspace(c));\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n  string s;\r\n  rd(s);\r\
    \n  x = stod(s);\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_integer(T &x) {\r\
    \n  if (pil + 100 > pir) load();\r\n  char c;\r\n  do\r\n    c = ibuf[pil++];\r\
    \n  while (c < '-');\r\n  bool minus = 0;\r\n  if constexpr (is_signed<T>::value\
    \ || is_same_v<T, i128>) {\r\n    if (c == '-') { minus = 1, c = ibuf[pil++];\
    \ }\r\n  }\r\n  x = 0;\r\n  while (c >= '0') { x = x * 10 + (c & 15), c = ibuf[pil++];\
    \ }\r\n  if constexpr (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if\
    \ (minus) x = -x;\r\n  }\r\n}\r\n\r\nvoid rd(int &x) { rd_integer(x); }\r\nvoid\
    \ rd(ll &x) { rd_integer(x); }\r\nvoid rd(i128 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u32 &x) { rd_integer(x); }\r\nvoid rd(u64 &x) { rd_integer(x); }\r\nvoid\
    \ rd(u128 &x) { rd_integer(x); }\r\nvoid rd(double &x) { rd_real(x); }\r\nvoid\
    \ rd(long double &x) { rd_real(x); }\r\nvoid rd(f128 &x) { rd_real(x); }\r\n\r\
    \ntemplate <class T, class U>\r\nvoid rd(pair<T, U> &p) {\r\n  return rd(p.first),\
    \ rd(p.second);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd_tuple(T\
    \ &t) {\r\n  if constexpr (N < std::tuple_size<T>::value) {\r\n    auto &x = std::get<N>(t);\r\
    \n    rd(x);\r\n    rd_tuple<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\
    \nvoid rd(tuple<T...> &tpl) {\r\n  rd_tuple(tpl);\r\n}\r\n\r\ntemplate <size_t\
    \ N = 0, typename T>\r\nvoid rd(array<T, N> &x) {\r\n  for (auto &d: x) rd(d);\r\
    \n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\n  for (auto &d: x) rd(d);\r\
    \n}\r\n\r\nvoid read() {}\r\ntemplate <class H, class... T>\r\nvoid read(H &h,\
    \ T &... t) {\r\n  rd(h), read(t...);\r\n}\r\n\r\nvoid wt(const char c) {\r\n\
    \  if (por == SZ) flush();\r\n  obuf[por++] = c;\r\n}\r\nvoid wt(const string\
    \ s) {\r\n  for (char c: s) wt(c);\r\n}\r\nvoid wt(const char *s) {\r\n  size_t\
    \ len = strlen(s);\r\n  for (size_t i = 0; i < len; i++) wt(s[i]);\r\n}\r\n\r\n\
    template <typename T>\r\nvoid wt_integer(T x) {\r\n  if (por > SZ - 100) flush();\r\
    \n  if (x < 0) { obuf[por++] = '-', x = -x; }\r\n  int outi;\r\n  for (outi =\
    \ 96; x >= 10000; outi -= 4) {\r\n    memcpy(out + outi, pre.num[x % 10000], 4);\r\
    \n    x /= 10000;\r\n  }\r\n  if (x >= 1000) {\r\n    memcpy(obuf + por, pre.num[x],\
    \ 4);\r\n    por += 4;\r\n  } else if (x >= 100) {\r\n    memcpy(obuf + por, pre.num[x]\
    \ + 1, 3);\r\n    por += 3;\r\n  } else if (x >= 10) {\r\n    int q = (x * 103)\
    \ >> 10;\r\n    obuf[por] = q | '0';\r\n    obuf[por + 1] = (x - q * 10) | '0';\r\
    \n    por += 2;\r\n  } else\r\n    obuf[por++] = x | '0';\r\n  memcpy(obuf + por,\
    \ out + outi + 4, 96 - outi);\r\n  por += 96 - outi;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvoid wt_real(T x) {\r\n  ostringstream oss;\r\n  oss << fixed << setprecision(15)\
    \ << double(x);\r\n  string s = oss.str();\r\n  wt(s);\r\n}\r\n\r\nvoid wt(int\
    \ x) { wt_integer(x); }\r\nvoid wt(ll x) { wt_integer(x); }\r\nvoid wt(i128 x)\
    \ { wt_integer(x); }\r\nvoid wt(u32 x) { wt_integer(x); }\r\nvoid wt(u64 x) {\
    \ wt_integer(x); }\r\nvoid wt(u128 x) { wt_integer(x); }\r\nvoid wt(double x)\
    \ { wt_real(x); }\r\nvoid wt(long double x) { wt_real(x); }\r\nvoid wt(f128 x)\
    \ { wt_real(x); }\r\n\r\ntemplate <class T, class U>\r\nvoid wt(const pair<T,\
    \ U> val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n  wt(val.second);\r\n}\r\ntemplate\
    \ <size_t N = 0, typename T>\r\nvoid wt_tuple(const T t) {\r\n  if constexpr (N\
    \ < std::tuple_size<T>::value) {\r\n    if constexpr (N > 0) { wt(' '); }\r\n\
    \    const auto x = std::get<N>(t);\r\n    wt(x);\r\n    wt_tuple<N + 1>(t);\r\
    \n  }\r\n}\r\ntemplate <class... T>\r\nvoid wt(tuple<T...> tpl) {\r\n  wt_tuple(tpl);\r\
    \n}\r\ntemplate <class T, size_t S>\r\nvoid wt(const array<T, S> val) {\r\n  auto\
    \ n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\
    \n    wt(val[i]);\r\n  }\r\n}\r\ntemplate <class T>\r\nvoid wt(const vector<T>\
    \ val) {\r\n  auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n \
    \   if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\nvoid print() { wt('\\\
    n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&... tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail)) wt(' ');\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n\r\n// gcc expansion. called automaticall after main.\r\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\r\n} // namespace fastio\r\nusing fastio::read;\r\nusing fastio::print;\r\
    \nusing fastio::flush;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\
    \n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
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
    \ yes(!t); }\r\n#line 4 \"test_atcoder/abc281e.test.cpp\"\n\n#line 1 \"ds/my_multiset.hpp\"\
    \ntemplate <typename VAL, typename SM>\nstruct My_Multiset {\n  using T = VAL;\n\
    \  int sz;\n  SM sm_all;\n  vvc<T> dat;\n  vc<SM> sm;\n  static const int BUCKET_RATIO\
    \ = 50, REBUILD_RATIO = 170;\n\n  My_Multiset() : sz(0), sm_all(0), dat(1), sm(1)\
    \ {}\n\n  void build(vc<T> vals) {\n    sort(all(vals));\n    sz = len(vals);\n\
    \    int b_cnt = sqrt(sz / BUCKET_RATIO) + 1;\n    dat.resize(b_cnt);\n    FOR(i,\
    \ b_cnt) {\n      int l = sz * i / b_cnt, r = sz * (i + 1) / b_cnt;\n      dat[i]\
    \ = {vals.begin() + l, vals.begin() + r};\n    }\n    sm.resize(b_cnt);\n    FOR(i,\
    \ b_cnt) sm[i] = SUM<SM>(dat[i]);\n    sm_all = SUM<SM>(sm);\n  }\n\n  int size()\
    \ { return sz; }\n  vc<T> get_all() {\n    vc<T> res;\n    for (auto&& x: dat)\
    \ res.insert(res.end(), all(x));\n    return res;\n  }\n\n  void rebuild() { build(get_all());\
    \ }\n\n  void insert(T x) {\n    if (sz == 0) {\n      dat[0].eb(x);\n      ++sz,\
    \ sm[0] += x, sm_all += x;\n      return;\n    }\n    FOR(idx, len(dat)) {\n \
    \     if (dat[idx].back() < x && idx < len(dat) - 1) continue;\n      dat[idx].insert(lower_bound(all(dat[idx]),\
    \ x), x);\n      ++sz, sm[idx] += x, sm_all += x;\n      if (len(dat[idx]) > len(dat)\
    \ * REBUILD_RATIO) rebuild();\n      break;\n    }\n  }\n  void add(T x) { insert(x);\
    \ }\n\n  void erase(T x) {\n    FOR(idx, len(dat)) {\n      if (dat[idx].back()\
    \ < x && idx < len(dat) - 1) continue;\n      dat[idx].erase(lower_bound(all(dat[idx]),\
    \ x));\n      --sz, sm[idx] -= x, sm_all -= x;\n      if (len(dat[idx]) == 0 &&\
    \ len(dat) > 0) {\n        dat.erase(dat.begin() + idx);\n        sm.erase(sm.begin()\
    \ + idx);\n      }\n      break;\n    }\n  }\n  void remove(T x) { erase(x); }\n\
    \n  int count(T x) {\n    int cnt = 0;\n    FOR(idx, len(dat)) {\n      if (dat[idx].back()\
    \ < x) continue;\n      if (dat[idx][0] > x) break;\n      if (dat[idx][0] ==\
    \ dat[idx].back())\n        cnt += len(dat[idx]);\n      else\n        cnt +=\
    \ upper_bound(all(dat[idx]), x) - lower_bound(all(dat[idx]), x);\n    }\n    return\
    \ cnt;\n  }\n\n  // {value[k], sum[0:k]}\n  pair<VAL, SM> get_kth(int k, bool\
    \ suffix = false) {\n    assert(0 <= k && k <= sz);\n    if (suffix) {\n     \
    \ if (k == sz) return {-infty<VAL>, sm_all};\n      auto [x, s] = get_kth(sz -\
    \ k - 1);\n      return {x, sm_all - s - x};\n    }\n    SM s = 0;\n    FOR(idx,\
    \ len(dat)) {\n      if (k >= len(dat[idx])) {\n        k -= len(dat[idx]);\n\
    \        s += sm[idx];\n        continue;\n      }\n      FOR(j, k) s += dat[idx][j];\n\
    \      return {dat[idx][k], s};\n    }\n    return {infty<VAL>, s};\n  }\n\n \
    \ // [lo, hi) \u3067 {cnt, sm}\n  pair<int, SM> get_range(T lo, T hi) {\n    if\
    \ (sz == 0) return {0, 0};\n    int cnt = 0;\n    SM s = 0;\n    FOR(idx, len(dat))\
    \ {\n      if (dat[idx].back() < lo) continue;\n      if (hi <= dat[idx][0]) break;\n\
    \      if (lo <= dat[idx][0] && dat[idx].back() < hi) {\n        cnt += len(dat[idx]),\
    \ s += sm[idx];\n        continue;\n      }\n      for (auto&& x: dat[idx])\n\
    \        if (lo <= x && x < hi) ++cnt, s += x;\n    }\n    return {cnt, s};\n\
    \  }\n};\n#line 6 \"test_atcoder/abc281e.test.cpp\"\n\nvoid solve() {\n  LL(N,\
    \ M, K);\n  My_Multiset<int, ll> X;\n  VEC(ll, A, N);\n  FOR(i, M) X.insert(A[i]);\n\
    \  vi ANS;\n  FOR(i, M, N + 1) {\n    ANS.eb(X.get_kth(K).se);\n    if (i == N)\
    \ break;\n    X.insert(A[i]), X.erase(A[i - M]);\n  }\n  print(ANS);\n}\n\nsigned\
    \ main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc281/tasks/abc281_e\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/my_multiset.hpp\"\
    \n\nvoid solve() {\n  LL(N, M, K);\n  My_Multiset<int, ll> X;\n  VEC(ll, A, N);\n\
    \  FOR(i, M) X.insert(A[i]);\n  vi ANS;\n  FOR(i, M, N + 1) {\n    ANS.eb(X.get_kth(K).se);\n\
    \    if (i == N) break;\n    X.insert(A[i]), X.erase(A[i - M]);\n  }\n  print(ANS);\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/my_multiset.hpp
  isVerificationFile: true
  path: test_atcoder/abc281e.test.cpp
  requiredBy: []
  timestamp: '2023-11-07 08:39:48+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc281e.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc281e.test.cpp
- /verify/test_atcoder/abc281e.test.cpp.html
title: test_atcoder/abc281e.test.cpp
---
