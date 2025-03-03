---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dsu_on_tree.hpp
    title: graph/dsu_on_tree.hpp
  - icon: ':heavy_check_mark:'
    path: graph/tree.hpp
    title: graph/tree.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    #line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n// https://codeforces.com/blog/entry/126772?#comment-1154880\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    \n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif\
    \ else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x))\
    \ & 1 ? -1 : 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ?\
    \ -1 : 1); }\nint popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u64 x) { return (__builtin_parityll(x) & 1 ? -1 : 1);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T kth_bit(int k) {\n  return T(1) << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T\
    \ x, int k) {\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\nstruct all_bit\
    \ {\n  struct iter {\n    UINT s;\n    iter(UINT s) : s(s) {}\n    int operator*()\
    \ const { return lowbit(s); }\n    iter &operator++() {\n      s &= s - 1;\n \
    \     return *this;\n    }\n    bool operator!=(const iter) const { return s !=\
    \ 0; }\n  };\n  UINT s;\n  all_bit(UINT s) : s(s) {}\n  iter begin() const { return\
    \ iter(s); }\n  iter end() const { return iter(0); }\n};\n\ntemplate <typename\
    \ UINT>\nstruct all_subset {\n  static_assert(is_unsigned<UINT>::value);\n  struct\
    \ iter {\n    UINT s, t;\n    bool ed;\n    iter(UINT s) : s(s), t(s), ed(0) {}\n\
    \    int operator*() const { return s ^ t; }\n    iter &operator++() {\n     \
    \ (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool operator!=(const\
    \ iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT s) : s(s) {}\n\
    \  iter begin() const { return iter(s); }\n  iter end() const { return iter(0);\
    \ }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return a / b - (a % b\
    \ && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y) {\n  return floor(x\
    \ + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y) {\n  return x - y *\
    \ floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T x, T y) {\n  T q\
    \ = floor(x, y);\n  return {q, x - q * y};\n}\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const vector<U> &A) {\n  T sm = 0;\n  for (auto &&a: A) sm += a;\n\
    \  return sm;\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)),\
    \ x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\n\
    T POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T\
    \ a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\n\
    ll binary_search(F check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\n\
    double binary_search_real(F check, double ok, double ng, int iter = 100) {\n \
    \ FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n\
    \  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T\
    \ &a, const S &b) {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class\
    \ S>\ninline bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U>\
    \ &A, int off = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvector<int> argsort(const vector<T>\
    \ &A) {\n  vector<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
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
    \ yes(!t); }\r\nvoid YA(bool t = 1) { print(t ? \"YA\" : \"TIDAK\"); }\r\nvoid\
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 2 \"graph/tree.hpp\"\n\r\n#line 2 \"\
    ds/hashmap.hpp\"\n\r\n// u64 -> Val\r\ntemplate <typename Val>\r\nstruct HashMap\
    \ {\r\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067\
    \ ok\r\n  HashMap(u32 n = 0) { build(n); }\r\n  void build(u32 n) {\r\n    u32\
    \ k = 8;\r\n    while (k < n * 2) k *= 2;\r\n    cap = k / 2, mask = k - 1;\r\n\
    \    key.resize(k), val.resize(k), used.assign(k, 0);\r\n  }\r\n\r\n  // size\
    \ \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F\
    \ build \u3059\u308B\u3053\u3068.\r\n  void clear() {\r\n    used.assign(len(used),\
    \ 0);\r\n    cap = (mask + 1) / 2;\r\n  }\r\n  int size() { return len(used) /\
    \ 2 - cap; }\r\n\r\n  int index(const u64& k) {\r\n    int i = 0;\r\n    for (i\
    \ = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {}\r\n    return i;\r\
    \n  }\r\n\r\n  Val& operator[](const u64& k) {\r\n    if (cap == 0) extend();\r\
    \n    int i = index(k);\r\n    if (!used[i]) { used[i] = 1, key[i] = k, val[i]\
    \ = Val{}, --cap; }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64& k,\
    \ Val default_value) {\r\n    int i = index(k);\r\n    return (used[i] ? val[i]\
    \ : default_value);\r\n  }\r\n\r\n  bool count(const u64& k) {\r\n    int i =\
    \ index(k);\r\n    return used[i] && key[i] == k;\r\n  }\r\n\r\n  // f(key, val)\r\
    \n  template <typename F>\r\n  void enumerate_all(F f) {\r\n    FOR(i, len(used))\
    \ if (used[i]) f(key[i], val[i]);\r\n  }\r\n\r\nprivate:\r\n  u32 cap, mask;\r\
    \n  vc<u64> key;\r\n  vc<Val> val;\r\n  vc<bool> used;\r\n\r\n  u64 hash(u64 x)\
    \ {\r\n    static const u64 FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();\r\
    \n    x += FIXED_RANDOM;\r\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\r\n\
    \    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\r\n    return (x ^ (x >> 31)) &\
    \ mask;\r\n  }\r\n\r\n  void extend() {\r\n    vc<pair<u64, Val>> dat;\r\n   \
    \ dat.reserve(len(used) / 2 - cap);\r\n    FOR(i, len(used)) {\r\n      if (used[i])\
    \ dat.eb(key[i], val[i]);\r\n    }\r\n    build(2 * len(dat));\r\n    for (auto&\
    \ [a, b]: dat) (*this)[a] = b;\r\n  }\r\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate\
    \ <typename T = int, bool directed = false>\nstruct Graph {\n  static constexpr\
    \ bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n  using edge_type\
    \ = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n  vector<edge_type>\
    \ csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  bool prepared;\n\n  class\
    \ OutgoingEdges {\n  public:\n    OutgoingEdges(const Graph* G, int l, int r)\
    \ : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n      if (l ==\
    \ r) { return 0; }\n      return &G->csr_edges[l];\n    }\n\n    const edge_type*\
    \ end() const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[r];\n\
    \    }\n\n  private:\n    const Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared()\
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
    \      if (!directed) csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost,\
    \ e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
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
    \    }\n    G1.build();\n    return G1;\n  }\n\n  HashMap<int> MP_FOR_EID;\n\n\
    \  int get_eid(u64 a, u64 b) {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N\
    \ - 1);\n      for (auto& e: edges) {\n        u64 a = e.frm, b = e.to;\n    \
    \    u64 k = to_eid_key(a, b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n\
    \    return MP_FOR_EID.get(to_eid_key(a, b), -1);\n  }\n\n  u64 to_eid_key(u64\
    \ a, u64 b) {\n    if (!directed && a > b) swap(a, b);\n    return N * a + b;\n\
    \  }\n\nprivate:\n  void calc_deg() {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n\
    \    for (auto&& e: edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e: edges) { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n\
    #line 4 \"graph/tree.hpp\"\n\r\n// HLD euler tour \u3092\u3068\u3063\u3066\u3044\
    \u308D\u3044\u308D\u3002\r\ntemplate <typename GT>\r\nstruct Tree {\r\n  using\
    \ Graph_type = GT;\r\n  GT &G;\r\n  using WT = typename GT::cost_type;\r\n  int\
    \ N;\r\n  vector<int> LID, RID, head, V, parent, VtoE;\r\n  vc<int> depth;\r\n\
    \  vc<WT> depth_weighted;\r\n\r\n  Tree(GT &G, int r = 0, bool hld = 1) : G(G)\
    \ { build(r, hld); }\r\n\r\n  void build(int r = 0, bool hld = 1) {\r\n    if\
    \ (r == -1) return; // build \u3092\u9045\u5EF6\u3057\u305F\u3044\u3068\u304D\r\
    \n    N = G.N;\r\n    LID.assign(N, -1), RID.assign(N, -1), head.assign(N, r);\r\
    \n    V.assign(N, -1), parent.assign(N, -1), VtoE.assign(N, -1);\r\n    depth.assign(N,\
    \ -1), depth_weighted.assign(N, 0);\r\n    assert(G.is_prepared());\r\n    int\
    \ t1 = 0;\r\n    dfs_sz(r, -1, hld);\r\n    dfs_hld(r, t1);\r\n  }\r\n\r\n  void\
    \ dfs_sz(int v, int p, bool hld) {\r\n    auto &sz = RID;\r\n    parent[v] = p;\r\
    \n    depth[v] = (p == -1 ? 0 : depth[p] + 1);\r\n    sz[v] = 1;\r\n    int l\
    \ = G.indptr[v], r = G.indptr[v + 1];\r\n    auto &csr = G.csr_edges;\r\n    //\
    \ \u4F7F\u3046\u8FBA\u304C\u3042\u308C\u3070\u5148\u982D\u306B\u3059\u308B\r\n\
    \    for (int i = r - 2; i >= l; --i) {\r\n      if (hld && depth[csr[i + 1].to]\
    \ == -1) swap(csr[i], csr[i + 1]);\r\n    }\r\n    int hld_sz = 0;\r\n    for\
    \ (int i = l; i < r; ++i) {\r\n      auto e = csr[i];\r\n      if (depth[e.to]\
    \ != -1) continue;\r\n      depth_weighted[e.to] = depth_weighted[v] + e.cost;\r\
    \n      VtoE[e.to] = e.id;\r\n      dfs_sz(e.to, v, hld);\r\n      sz[v] += sz[e.to];\r\
    \n      if (hld && chmax(hld_sz, sz[e.to]) && l < i) { swap(csr[l], csr[i]); }\r\
    \n    }\r\n  }\r\n\r\n  void dfs_hld(int v, int &times) {\r\n    LID[v] = times++;\r\
    \n    RID[v] += LID[v];\r\n    V[LID[v]] = v;\r\n    bool heavy = true;\r\n  \
    \  for (auto &&e: G[v]) {\r\n      if (depth[e.to] <= depth[v]) continue;\r\n\
    \      head[e.to] = (heavy ? head[v] : e.to);\r\n      heavy = false;\r\n    \
    \  dfs_hld(e.to, times);\r\n    }\r\n  }\r\n\r\n  vc<int> heavy_path_at(int v)\
    \ {\r\n    vc<int> P = {v};\r\n    while (1) {\r\n      int a = P.back();\r\n\
    \      for (auto &&e: G[a]) {\r\n        if (e.to != parent[a] && head[e.to] ==\
    \ v) {\r\n          P.eb(e.to);\r\n          break;\r\n        }\r\n      }\r\n\
    \      if (P.back() == a) break;\r\n    }\r\n    return P;\r\n  }\r\n\r\n  int\
    \ heavy_child(int v) {\r\n    int k = LID[v] + 1;\r\n    if (k == N) return -1;\r\
    \n    int w = V[k];\r\n    return (parent[w] == v ? w : -1);\r\n  }\r\n\r\n  vc<int>\
    \ memo_tail;\r\n\r\n  int tail(int v) {\r\n    if (memo_tail.empty()) {\r\n  \
    \    memo_tail.assign(N, -1);\r\n      FOR_R(i, N) {\r\n        int v = V[i];\r\
    \n        int w = heavy_child(v);\r\n        memo_tail[v] = (w == -1 ? v : memo_tail[w]);\r\
    \n      }\r\n    }\r\n    return memo_tail[v];\r\n  }\r\n\r\n  int e_to_v(int\
    \ eid) {\r\n    auto e = G.edges[eid];\r\n    return (parent[e.frm] == e.to ?\
    \ e.frm : e.to);\r\n  }\r\n  int v_to_e(int v) { return VtoE[v]; }\r\n  int get_eid(int\
    \ u, int v) {\r\n    if (parent[u] != v) swap(u, v);\r\n    assert(parent[u] ==\
    \ v);\r\n    return VtoE[u];\r\n  }\r\n\r\n  int ELID(int v) { return 2 * LID[v]\
    \ - depth[v]; }\r\n  int ERID(int v) { return 2 * RID[v] - depth[v] - 1; }\r\n\
    \r\n  // \u76EE\u6A19\u5730\u70B9\u3078\u9032\u3080\u500B\u6570\u304C k\r\n  int\
    \ LA(int v, int k) {\r\n    assert(k <= depth[v]);\r\n    while (1) {\r\n    \
    \  int u = head[v];\r\n      if (LID[v] - k >= LID[u]) return V[LID[v] - k];\r\
    \n      k -= LID[v] - LID[u] + 1;\r\n      v = parent[u];\r\n    }\r\n  }\r\n\
    \  int la(int u, int v) { return LA(u, v); }\r\n\r\n  int LCA(int u, int v) {\r\
    \n    for (;; v = parent[head[v]]) {\r\n      if (LID[u] > LID[v]) swap(u, v);\r\
    \n      if (head[u] == head[v]) return u;\r\n    }\r\n  }\r\n\r\n  int meet(int\
    \ a, int b, int c) { return LCA(a, b) ^ LCA(a, c) ^ LCA(b, c); }\r\n  int lca(int\
    \ u, int v) { return LCA(u, v); }\r\n\r\n  int subtree_size(int v, int root =\
    \ -1) {\r\n    if (root == -1) return RID[v] - LID[v];\r\n    if (v == root) return\
    \ N;\r\n    int x = jump(v, root, 1);\r\n    if (in_subtree(v, x)) return RID[v]\
    \ - LID[v];\r\n    return N - RID[x] + LID[x];\r\n  }\r\n\r\n  int dist(int a,\
    \ int b) {\r\n    int c = LCA(a, b);\r\n    return depth[a] + depth[b] - 2 * depth[c];\r\
    \n  }\r\n\r\n  WT dist_weighted(int a, int b) {\r\n    int c = LCA(a, b);\r\n\
    \    return depth_weighted[a] + depth_weighted[b] - WT(2) * depth_weighted[c];\r\
    \n  }\r\n\r\n  // a is in b\r\n  bool in_subtree(int a, int b) { return LID[b]\
    \ <= LID[a] && LID[a] < RID[b]; }\r\n\r\n  int jump(int a, int b, ll k) {\r\n\
    \    if (k == 1) {\r\n      if (a == b) return -1;\r\n      return (in_subtree(b,\
    \ a) ? LA(b, depth[b] - depth[a] - 1) : parent[a]);\r\n    }\r\n    int c = LCA(a,\
    \ b);\r\n    int d_ac = depth[a] - depth[c];\r\n    int d_bc = depth[b] - depth[c];\r\
    \n    if (k > d_ac + d_bc) return -1;\r\n    if (k <= d_ac) return LA(a, k);\r\
    \n    return LA(b, d_ac + d_bc - k);\r\n  }\r\n\r\n  vc<int> collect_child(int\
    \ v) {\r\n    vc<int> res;\r\n    for (auto &&e: G[v])\r\n      if (e.to != parent[v])\
    \ res.eb(e.to);\r\n    return res;\r\n  }\r\n\r\n  vc<int> collect_light(int v)\
    \ {\r\n    vc<int> res;\r\n    bool skip = true;\r\n    for (auto &&e: G[v])\r\
    \n      if (e.to != parent[v]) {\r\n        if (!skip) res.eb(e.to);\r\n     \
    \   skip = false;\r\n      }\r\n    return res;\r\n  }\r\n\r\n  vc<pair<int, int>>\
    \ get_path_decomposition(int u, int v, bool edge) {\r\n    // [\u59CB\u70B9, \u7D42\
    \u70B9] \u306E\"\u9589\"\u533A\u9593\u5217\u3002\r\n    vc<pair<int, int>> up,\
    \ down;\r\n    while (1) {\r\n      if (head[u] == head[v]) break;\r\n      if\
    \ (LID[u] < LID[v]) {\r\n        down.eb(LID[head[v]], LID[v]);\r\n        v =\
    \ parent[head[v]];\r\n      } else {\r\n        up.eb(LID[u], LID[head[u]]);\r\
    \n        u = parent[head[u]];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v])\
    \ down.eb(LID[u] + edge, LID[v]);\r\n    elif (LID[v] + edge <= LID[u]) up.eb(LID[u],\
    \ LID[v] + edge);\r\n    reverse(all(down));\r\n    up.insert(up.end(), all(down));\r\
    \n    return up;\r\n  }\r\n\r\n  // \u8FBA\u306E\u5217\u306E\u60C5\u5831 (frm,to,str)\r\
    \n  // str = \"heavy_up\", \"heavy_down\", \"light_up\", \"light_down\"\r\n  vc<tuple<int,\
    \ int, string>> get_path_decomposition_detail(int u, int v) {\r\n    vc<tuple<int,\
    \ int, string>> up, down;\r\n    while (1) {\r\n      if (head[u] == head[v])\
    \ break;\r\n      if (LID[u] < LID[v]) {\r\n        if (v != head[v]) down.eb(head[v],\
    \ v, \"heavy_down\"), v = head[v];\r\n        down.eb(parent[v], v, \"light_down\"\
    ), v = parent[v];\r\n      } else {\r\n        if (u != head[u]) up.eb(u, head[u],\
    \ \"heavy_up\"), u = head[u];\r\n        up.eb(u, parent[u], \"light_up\"), u\
    \ = parent[u];\r\n      }\r\n    }\r\n    if (LID[u] < LID[v]) down.eb(u, v, \"\
    heavy_down\");\r\n    elif (LID[v] < LID[u]) up.eb(u, v, \"heavy_up\");\r\n  \
    \  reverse(all(down));\r\n    concat(up, down);\r\n    return up;\r\n  }\r\n\r\
    \n  vc<int> restore_path(int u, int v) {\r\n    vc<int> P;\r\n    for (auto &&[a,\
    \ b]: get_path_decomposition(u, v, 0)) {\r\n      if (a <= b) {\r\n        FOR(i,\
    \ a, b + 1) P.eb(V[i]);\r\n      } else {\r\n        FOR_R(i, b, a + 1) P.eb(V[i]);\r\
    \n      }\r\n    }\r\n    return P;\r\n  }\r\n\r\n  // path [a,b] \u3068 [c,d]\
    \ \u306E\u4EA4\u308F\u308A. \u7A7A\u306A\u3089\u3070 {-1,-1}.\r\n  // https://codeforces.com/problemset/problem/500/G\r\
    \n  pair<int, int> path_intersection(int a, int b, int c, int d) {\r\n    int\
    \ ab = lca(a, b), ac = lca(a, c), ad = lca(a, d);\r\n    int bc = lca(b, c), bd\
    \ = lca(b, d), cd = lca(c, d);\r\n    int x = ab ^ ac ^ bc, y = ab ^ ad ^ bd;\
    \ // meet(a,b,c), meet(a,b,d)\r\n    if (x != y) return {x, y};\r\n    int z =\
    \ ac ^ ad ^ cd;\r\n    if (x != z) x = -1;\r\n    return {x, x};\r\n  }\r\n\r\n\
    \  // uv path \u4E0A\u3067 check(v) \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E\
    \ v\r\n  // \u306A\u3051\u308C\u3070 \uFF08\u3064\u307E\u308A check(v) \u304C\
    \ ng \uFF09-1\r\n  template <class F>\r\n  int max_path(F check, int u, int v)\
    \ {\r\n    if (!check(u)) return -1;\r\n    auto pd = get_path_decomposition(u,\
    \ v, false);\r\n    for (auto [a, b]: pd) {\r\n      if (!check(V[a])) return\
    \ u;\r\n      if (check(V[b])) {\r\n        u = V[b];\r\n        continue;\r\n\
    \      }\r\n      int c = binary_search([&](int c) -> bool { return check(V[c]);\
    \ }, a, b, 0);\r\n      return V[c];\r\n    }\r\n    return u;\r\n  }\r\n};\r\n\
    #line 2 \"graph/dsu_on_tree.hpp\"\n\n// add(v) : \u9802\u70B9 v \u306E\u30C7\u30FC\
    \u30BF\u3092\u8FFD\u52A0\u3059\u308B\n// query(v) : \u9802\u70B9 v \u306B\u304A\
    \u3051\u308B\u30AF\u30A8\u30EA\u306B\u7B54\u3048\u308B\n// reset() : \u30C7\u30FC\
    \u30BF\u304C\u7A7A\u306E\u72B6\u614B\u306B\u623B\u3059\u3002\n// \u30C7\u30FC\u30BF\
    \u69CB\u9020\u306B\u3088\u3063\u3066\u306F\u3001\u5C65\u6B74\u3092\u4F7F\u3063\
    \u3066\u9AD8\u901F\u306B reset \u3059\u308B\u3002\ntemplate <typename TREE, typename\
    \ F1, typename F2, typename F3>\nvoid DSU_on_Tree(TREE& tree, F1& add, F2& query,\
    \ F3& reset) {\n  int N = tree.N;\n  FOR_R(vid, N) {\n    int v = tree.V[vid];\n\
    \    add(v);\n    // collect data in light subtree\n    for (auto&& e: tree.G[v])\
    \ {\n      if (e.to == tree.parent[v]) continue;\n      if (tree.head[e.to] !=\
    \ e.to) continue;\n      FOR(idx, tree.LID[e.to], tree.RID[e.to]) { add(tree.V[idx]);\
    \ }\n    }\n    query(v);\n\n    if (tree.head[v] == v) reset();\n  }\n}\n#line\
    \ 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\
    \n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ MX = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() {}\n  FenwickTree(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree(int n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const\
    \ vc<E>& v) { build(v); }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m,\
    \ G::unit());\n    total = G::unit();\n  }\n  void build(const vc<E>& v) {\n \
    \   build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n\
    \    total = G::unit();\n    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1;\
    \ i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] =\
    \ G::op(dat[i - 1], dat[j - 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n \
    \ E prod_all() { return total; }\n  E sum_all() { return total; }\n  E sum(int\
    \ k) { return prefix_sum(k); }\n  E prod(int k) { return prefix_prod(k); }\n \
    \ E prefix_sum(int k) { return prefix_prod(k); }\n  E prefix_prod(int k) {\n \
    \   chmin(k, n);\n    E ret = G::unit();\n    for (; k > 0; k -= k & -k) ret =\
    \ G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L, int R) { return\
    \ prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L, 0), chmin(R, n);\n   \
    \ if (L == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n\
    \    E pos = G::unit(), neg = G::unit();\n    while (L < R) { pos = G::op(pos,\
    \ dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]),\
    \ L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  vc<E> get_all()\
    \ {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i, i + 1);\n    return res;\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int\
    \ k, E x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }\n\n  template <class\
    \ F>\n  int max_right(const F check, int L = 0) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) +\
    \ 1; }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t)) { return\
    \ k; }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n\
    \    }();\n    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat))\
    \ {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(t)) { i\
    \ += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n\
    \  template <class F>\n  int max_right_with_index(const F check, int L = 0) {\n\
    \    assert(check(L, G::unit()));\n    E s = G::unit();\n    int i = L;\n    //\
    \ 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n\
    \        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n \
    \       if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n\
    \        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n        s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n\
    \      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t)) { i += (1 << k),\
    \ s = t; }\n      }\n    }\n    return i;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(check(G::unit()));\n    E s = G::unit();\n\
    \    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\u308D\u307E\u3067\
    \u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s)) {\n      s = G::op(s,\
    \ dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n    }\n    if (check(s))\
    \ {\n      assert(i == 0);\n      return 0;\n    }\n    // 2^k \u9032\u3080\u3068\
    \ ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\u6301\u3057\u3066\u9032\u3080\
    \n    while (k) {\n      --k;\n      E t = G::op(s, G::inverse(dat[i + (1 << k)\
    \ - 1]));\n      if (!check(t)) { i += (1 << k), s = t; }\n    }\n    return i\
    \ + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    return max_right([&k](E x) ->\
    \ bool { return x <= k; }, L);\n  }\n};\n#line 6 \"test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n  Graph<int, 1> G(N);\n  FOR(v,\
    \ 1, N) {\n    LL(p);\n    G.add(p, v);\n  }\n  G.build();\n  Tree tree(G);\n\n\
    \  vi ANS(Q, -1);\n  vvc<pair<int, int>> query(N);\n  FOR(q, Q) {\n    LL(t);\n\
    \    if (t == 0) {\n      LL(v, x);\n      query[v].eb(q, x);\n    }\n    if (t\
    \ == 1) {\n      LL(v);\n      query[v].eb(q, -1);\n    }\n  }\n\n  FenwickTree<Monoid_Add<ll>>\
    \ bit(Q);\n  vc<pair<int, int>> history;\n  ll base_sum = 0;\n\n  auto ADD = [&](int\
    \ v) -> void {\n    base_sum += A[v];\n    for (auto&& [q, x]: query[v]) {\n \
    \     if (x != -1) {\n        bit.add(q, x);\n        history.eb(q, x);\n    \
    \  }\n    }\n  };\n  auto QUERY = [&](int v) -> void {\n    for (auto&& [q, x]:\
    \ query[v]) {\n      if (x == -1) ANS[q] = base_sum + bit.sum(q);\n    }\n  };\n\
    \  auto RESET = [&]() -> void {\n    base_sum = 0;\n    for (auto&& [q, x]: history)\
    \ bit.add(q, -x);\n    history.clear();\n  };\n  DSU_on_Tree(tree, ADD, QUERY,\
    \ RESET);\n  for (auto&& ans: ANS)\n    if (ans != -1) print(ans);\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/dsu_on_tree.hpp\"\
    \n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n\
    \  VEC(ll, A, N);\n  Graph<int, 1> G(N);\n  FOR(v, 1, N) {\n    LL(p);\n    G.add(p,\
    \ v);\n  }\n  G.build();\n  Tree tree(G);\n\n  vi ANS(Q, -1);\n  vvc<pair<int,\
    \ int>> query(N);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(v, x);\n\
    \      query[v].eb(q, x);\n    }\n    if (t == 1) {\n      LL(v);\n      query[v].eb(q,\
    \ -1);\n    }\n  }\n\n  FenwickTree<Monoid_Add<ll>> bit(Q);\n  vc<pair<int, int>>\
    \ history;\n  ll base_sum = 0;\n\n  auto ADD = [&](int v) -> void {\n    base_sum\
    \ += A[v];\n    for (auto&& [q, x]: query[v]) {\n      if (x != -1) {\n      \
    \  bit.add(q, x);\n        history.eb(q, x);\n      }\n    }\n  };\n  auto QUERY\
    \ = [&](int v) -> void {\n    for (auto&& [q, x]: query[v]) {\n      if (x ==\
    \ -1) ANS[q] = base_sum + bit.sum(q);\n    }\n  };\n  auto RESET = [&]() -> void\
    \ {\n    base_sum = 0;\n    for (auto&& [q, x]: history) bit.add(q, -x);\n   \
    \ history.clear();\n  };\n  DSU_on_Tree(tree, ADD, QUERY, RESET);\n  for (auto&&\
    \ ans: ANS)\n    if (ans != -1) print(ans);\n}\n\nsigned main() {\n  solve();\n\
    \n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/dsu_on_tree.hpp
  - graph/tree.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp
  requiredBy: []
  timestamp: '2025-02-18 22:12:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp
- /verify/test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp.html
title: test/2_library_checker/tree/vertex_add_subtree_sum_dsu.test.cpp
---
