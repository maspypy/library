---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':question:'
    path: ds/segtree/dual_segtree.hpp
    title: ds/segtree/dual_segtree.hpp
  - icon: ':heavy_check_mark:'
    path: geo/range_closest_pair_query.hpp
    title: geo/range_closest_pair_query.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/range_closest_pair.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#pragma GCC optimize(\"\
    Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\
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
    \ yes(!t); }\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t\
    \ x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n         \
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \               .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n\
    \  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"ds/hashmap.hpp\"\
    \n\r\n// u64 -> Val\r\ntemplate <typename Val, int LOG = 20, bool KEEP_IDS = false>\r\
    \nstruct HashMap {\r\n  static constexpr int N = (1 << LOG);\r\n  u64* key;\r\n\
    \  Val* val;\r\n  vc<int> IDS;\r\n  bitset<N> used;\r\n  const int shift;\r\n\
    \  const u64 r = 11995408973635179863ULL;\r\n  HashMap() : key(new u64[N]), val(new\
    \ Val[N]), shift(64 - LOG) {}\r\n  u32 hash(u64 x) {\r\n    static const u64 FIXED_RANDOM\r\
    \n        = std::chrono::steady_clock::now().time_since_epoch().count();\r\n \
    \   return (u64(x + FIXED_RANDOM) * r) >> shift;\r\n  }\r\n\r\n  int index(const\
    \ u64& k) {\r\n    int i = 0;\r\n    for (i = hash(k); used[i] && key[i] != k;\
    \ (i += 1) &= (N - 1)) {}\r\n    return i;\r\n  }\r\n\r\n  Val& operator[](const\
    \ u64& k) {\r\n    int i = index(k);\r\n    if (!used[i]) { set_used(i), key[i]\
    \ = k, val[i] = Val{}; }\r\n    return val[i];\r\n  }\r\n\r\n  Val get(const u64&\
    \ k, Val default_value) {\r\n    int i = index(k);\r\n    if (!used[i]) return\
    \ default_value;\r\n    return val[i];\r\n  }\r\n\r\n  bool count(const u64& k)\
    \ {\r\n    int i = index(k);\r\n    return used[i] && key[i] == k;\r\n  }\r\n\r\
    \n  void set_used(int i) {\r\n    used[i] = 1;\r\n    if constexpr (KEEP_IDS)\
    \ IDS.eb(i);\r\n  }\r\n\r\n  void reset() {\r\n    static_assert(KEEP_IDS);\r\n\
    \    for (auto&& i: IDS) used[i] = 0;\r\n    IDS.clear();\r\n  }\r\n\r\n  // f(key,\
    \ val)\r\n  template <typename F>\r\n  void enumerate_all(F f) {\r\n    static_assert(KEEP_IDS);\r\
    \n    for (auto&& i: IDS) f(key[i], val[i]);\r\n  }\r\n};\r\n#line 2 \"ds/segtree/dual_segtree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct Dual_SegTree {\n  using MA = Monoid;\n\
    \  using A = typename MA::value_type;\n  int n, log, size;\n  vc<A> laz;\n\n \
    \ Dual_SegTree() : Dual_SegTree(0) {}\n  Dual_SegTree(int n) { build(n); }\n\n\
    \  void build(int m) {\n    n = m;\n    log = 1;\n    while ((1 << log) < n) ++log;\n\
    \    size = 1 << log;\n    laz.assign(size << 1, MA::unit());\n  }\n\n  A get(int\
    \ p) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i\
    \ >= 1; i--) push(p >> i);\n    return laz[p];\n  }\n\n  vc<A> get_all() {\n \
    \   FOR(i, size) push(i);\n    return {laz.begin() + size, laz.begin() + size\
    \ + n};\n  }\n\n  void apply(int l, int r, const A& a) {\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    if (l == r) return;\n    l += size, r += size;\n   \
    \ if (!MA::commute) {\n      for (int i = log; i >= 1; i--) {\n        if (((l\
    \ >> i) << i) != l) push(l >> i);\n        if (((r >> i) << i) != r) push((r -\
    \ 1) >> i);\n      }\n    }\n    while (l < r) {\n      if (l & 1) all_apply(l++,\
    \ a);\n      if (r & 1) all_apply(--r, a);\n      l >>= 1, r >>= 1;\n    }\n \
    \ }\n\nprivate:\n  void push(int k) {\n    if (laz[k] == MA::unit()) return;\n\
    \    all_apply(2 * k, laz[k]), all_apply(2 * k + 1, laz[k]);\n    laz[k] = MA::unit();\n\
    \  }\n  void all_apply(int k, A a) { laz[k] = MA::op(laz[k], a); }\n};\n#line\
    \ 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Min {\r\
    \n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit()\
    \ { return infty<E>; }\r\n  static constexpr bool commute = true;\r\n};\r\n#line\
    \ 4 \"geo/range_closest_pair_query.hpp\"\n\n// \u70B9\u7FA4 {p_i | i in [l, r)}\
    \ \u306B\u5BFE\u3059\u308B\u6700\u8FD1\u70B9\u5BFE\u306E\u8A08\u7B97\u3092\u884C\
    \u3046\u30AF\u30A8\u30EA\n// O(KNlogKN + QlogN)\n// https://qoj.ac/problem/5463\n\
    // https://codeforces.com/gym/104172/attachments/download/18933/Hong_Kong_Tutorial.pdf\n\
    struct Range_Closest_Pair_Query {\n  /*\n  \u30FBR \u3092\u5897\u3084\u3057\u306A\
    \u304C\u3089\u3001L \u3054\u3068\u306E\u7B54\u3092\u7BA1\u7406\u3059\u308B\n \
    \ \u30FB2^{k-1} <= ANS[L:R] < 2^{k} \u3068\u306A\u308B L \uFF1A\u30EC\u30D9\u30EB\
    \ k \uFF08\u30EC\u30D9\u30EB 0\uFF1A\u8DDD\u96E2 0\uFF09\n  \u30FB\u30EC\u30D9\
    \u30EB 0, 1, 2, ..., 29 \u306E\u30B0\u30EA\u30C3\u30C9\u3092\u7528\u610F\u3059\
    \u308B\n  \u3000\u30FB\u5E45\u306F 2^k\n\u3000  \u30FB\u4E00\u8FBA 1.99 \u306E\
    \u6B63\u65B9\u5F62\u5185\u3067\u70B9\u5BFE\u8DDD\u96E2\u304C 1 \u4EE5\u4E0A \u2192\
    \ 8 \u500B\u307E\u3067\u3042\u308A\u3046\u308B\n  \u30FB\u30EC\u30D9\u30EB 29,\
    \ 28, ..., 0 \u306E\u9806\u306B\u63A2\u7D22\u3059\u308B\uFF1A9 \u8FD1\u508D\n\
    \  \u3000\u30FB\u7B54\u304C\u898B\u3064\u304B\u3063\u305F\u3089\u30EC\u30D9\u30EB\
    \u3092\u4E0B\u3052\u308B\u3002\u5DE6\u5411\u304D\u306B\u4F1D\u642C\u3002\n  \u3000\
    \u30FB\u30EC\u30D9\u30EB\u306E\u6E1B\u5C11\u306F 30N \u56DE\u307E\u3067\u3057\u304B\
    \u8D77\u304D\u306A\u3044\n  */\n  const int LOG = 30;\n  vc<pair<int, int>> point;\n\
    \  vc<pair<int, int>> query;\n  void add_point(int x, int y) {\n    assert(0 <=\
    \ x && x < (1 << LOG));\n    assert(0 <= y && y < (1 << LOG));\n    point.eb(x,\
    \ y);\n  }\n  void add_query(int L, int R) {\n    assert(R - L >= 2);\n    query.eb(L,\
    \ R);\n  }\n  ll dist(int i, int j) {\n    ll dx = point[i].fi - point[j].fi;\n\
    \    ll dy = point[i].se - point[j].se;\n    return dx * dx + dy * dy;\n  }\n\n\
    \  vc<ll> calc() {\n    static HashMap<int, 20, true> MP;\n    MP.reset();\n \
    \   const int K = LOG;\n    const int N = len(point), Q = len(query);\n    using\
    \ A9 = array<int, 9>;\n    // \u305D\u308C\u305E\u308C\u306E\u30EC\u30D9\u30EB\
    \u306E\u3068\u304D\u306E\u30BB\u30EB\u756A\u53F7\n    vv(int, IDX, K, N, -1);\n\
    \    // \u5404\u30BB\u30EB\u756A\u53F7\u306B\u5BFE\u3059\u308B\u8FD1\u508D\n \
    \   vc<A9> nbd;\n    FOR(k, 1, K) {\n      MP.reset();\n      auto to_64 = [&](int\
    \ x, int y) -> u64 { return u64(x) << 30 | y; };\n      int off = len(nbd);\n\
    \      int p = off;\n      FOR(i, N) {\n        int x = point[i].fi >> (k);\n\
    \        int y = point[i].se >> (k);\n        u64 key = to_64(x, y);\n       \
    \ int idx = MP.index(key);\n        if (!MP.used[idx]) {\n          MP.set_used(idx);\n\
    \          MP.key[idx] = key, MP.val[idx] = p++;\n        }\n        IDX[k][i]\
    \ = MP.val[idx];\n      }\n      nbd.resize(p);\n      FOR(i, N) {\n        int\
    \ x = point[i].fi >> (k);\n        int y = point[i].se >> (k);\n        int me\
    \ = MP[to_64(x, y)];\n        int s = 0;\n        FOR(dx, -1, 2) FOR(dy, -1, 2)\
    \ {\n          u64 key = to_64(x + dx, y + dy);\n          nbd[me][s++] = (MP.count(key)\
    \ ? MP[key] : -1);\n        }\n      }\n    }\n\n    vc<array<int, 8>> dat(len(nbd),\
    \ {-1, -1, -1, -1, -1, -1, -1, -1});\n    auto add = [&](int k, int i) -> void\
    \ {\n      int idx = IDX[k][i];\n      for (auto&& j: dat[idx]) {\n        if\
    \ (j == -1) {\n          j = i;\n          return;\n        }\n      }\n    };\n\
    \    auto rm = [&](int k, int i) -> void {\n      int idx = IDX[k][i];\n     \
    \ for (auto&& j: dat[idx]) {\n        if (j == i) {\n          j = -1;\n     \
    \     return;\n        }\n      }\n    };\n\n    auto solve_level = [&](int k,\
    \ int i) -> vc<pair<int, ll>> {\n      // \u30EC\u30D9\u30EB k \u306E\u70B9\u7FA4\
    \u306B\u5BFE\u3059\u308B\u7B54\u306E\u8A08\u7B97\n      vc<pair<int, ll>> res;\n\
    \      int me = IDX[k][i];\n      for (auto&& idx: nbd[me]) {\n        if (idx\
    \ == -1) continue;\n        for (auto&& j: dat[idx]) {\n          if (j == -1)\
    \ continue;\n          res.eb(j, dist(i, j));\n        }\n      }\n      return\
    \ res;\n    };\n    Dual_SegTree<Monoid_Min<ll>> seg(N);\n    vc<int> LEVEL(N,\
    \ -1);\n    auto get_lv = [&](ll d) -> int {\n      if (d == 0) return 0;\n  \
    \    return topbit(d) / 2 + 1;\n    };\n\n    vc<int> left(Q);\n    vvc<int> query_at(N);\n\
    \    FOR(qid, Q) {\n      auto [L, R] = query[qid];\n      left[qid] = L;\n  \
    \    query_at[--R].eb(qid);\n    }\n\n    vi ANS(Q);\n\n    FOR(R, N) {\n    \
    \  // R \u756A\u76EE\u306E\u70B9\u3092\u7528\u3044\u305F\u7B54\u306E\u66F4\u65B0\
    \n      vc<pair<int, ll>> upd;\n      FOR(k, 1, K) {\n        auto res = solve_level(k,\
    \ R);\n        upd.insert(upd.end(), all(res));\n      }\n\n      for (auto [i,\
    \ d]: upd) {\n        int lv = get_lv(d);\n        if (seg.get(i) < d) continue;\n\
    \        // \u7B54\u3048\u306E\u66F4\u65B0\n        seg.apply(0, i + 1, d);\n\
    \        // \u30EC\u30D9\u30EB\u306E\u66F4\u65B0\n        while (i >= 0 && LEVEL[i]\
    \ > lv) {\n          rm(LEVEL[i], i);\n          LEVEL[i] = lv;\n          if\
    \ (lv) add(lv, i);\n          --i;\n        }\n      }\n      LEVEL[R] = K - 1;\n\
    \      add(K - 1, R);\n      for (auto&& qid: query_at[R]) { ANS[qid] = seg.get(left[qid]);\
    \ }\n    }\n    return ANS;\n  }\n};\n#line 6 \"test/mytest/range_closest_pair.test.cpp\"\
    \n\nvoid test() {\n  FOR(N, 2, 100) {\n    FOR(Q, 1, 100) {\n      vc<pair<int,\
    \ int>> point(N), query(Q);\n      FOR(i, N) {\n        int x = RNG(0, 20);\n\
    \        int y = RNG(0, 20);\n        point[i] = {x, y};\n      }\n      FOR(q,\
    \ Q) {\n        while (1) {\n          int L = RNG(0, N);\n          int R = RNG(0,\
    \ N);\n          if (L + 1 <= R) {\n            query[q] = {L, R + 1};\n     \
    \       break;\n          }\n        }\n      }\n      Range_Closest_Pair_Query\
    \ X;\n      for (auto&& [a, b]: point) X.add_point(a, b);\n      for (auto&& [l,\
    \ r]: query) X.add_query(l, r);\n      vi ANS = X.calc();\n      FOR(q, Q) {\n\
    \        ll ans = infty<ll>;\n        auto [L, R] = query[q];\n        FOR(i,\
    \ L, R) FOR(j, L, R) {\n          if (i == j) continue;\n          auto [x1, y1]\
    \ = point[i];\n          auto [x2, y2] = point[j];\n          ll dx = x1 - x2,\
    \ dy = y1 - y2;\n          chmin(ans, dx * dx + dy * dy);\n        }\n       \
    \ assert(ans == ANS[q]);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n\
    \  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include \"geo/range_closest_pair_query.hpp\"\
    \n\nvoid test() {\n  FOR(N, 2, 100) {\n    FOR(Q, 1, 100) {\n      vc<pair<int,\
    \ int>> point(N), query(Q);\n      FOR(i, N) {\n        int x = RNG(0, 20);\n\
    \        int y = RNG(0, 20);\n        point[i] = {x, y};\n      }\n      FOR(q,\
    \ Q) {\n        while (1) {\n          int L = RNG(0, N);\n          int R = RNG(0,\
    \ N);\n          if (L + 1 <= R) {\n            query[q] = {L, R + 1};\n     \
    \       break;\n          }\n        }\n      }\n      Range_Closest_Pair_Query\
    \ X;\n      for (auto&& [a, b]: point) X.add_point(a, b);\n      for (auto&& [l,\
    \ r]: query) X.add_query(l, r);\n      vi ANS = X.calc();\n      FOR(q, Q) {\n\
    \        ll ans = infty<ll>;\n        auto [L, R] = query[q];\n        FOR(i,\
    \ L, R) FOR(j, L, R) {\n          if (i == j) continue;\n          auto [x1, y1]\
    \ = point[i];\n          auto [x2, y2] = point[j];\n          ll dx = x1 - x2,\
    \ dy = y1 - y2;\n          chmin(ans, dx * dx + dy * dy);\n        }\n       \
    \ assert(ans == ANS[q]);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n\
    \  print(a + b);\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - geo/range_closest_pair_query.hpp
  - ds/hashmap.hpp
  - ds/segtree/dual_segtree.hpp
  - alg/monoid/min.hpp
  isVerificationFile: true
  path: test/mytest/range_closest_pair.test.cpp
  requiredBy: []
  timestamp: '2023-11-09 00:12:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/mytest/range_closest_pair.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/range_closest_pair.test.cpp
- /verify/test/mytest/range_closest_pair.test.cpp.html
title: test/mytest/range_closest_pair.test.cpp
---
