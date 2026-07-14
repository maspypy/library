---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: convex/monge/monge_shortest_path.hpp
    title: convex/monge/monge_shortest_path.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':question:'
    path: random/random_monge.hpp
    title: random/random_monge.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/monge_shortest_path.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#if\
    \ defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n//\
    \ \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\u30D1\u30A4\u30EB\u6210\
    \u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\n#pragma GCC target(\"\
    avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include <cassert>\n\nusing\
    \ namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
    using u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128\
    \ = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr\
    \ T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate\
    \ <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr\
    \ u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = numeric_limits<double>::infinity();\n\
    template <>\nconstexpr long double infty<long double> =\n    numeric_limits<long\
    \ double>::infinity();\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing pq_max = priority_queue<T>;\n\
    template <class T>\nusing pq_min = priority_queue<T, vector<T>, greater<T>>;\n\
    \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a) - 1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b) - 1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
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
    \    UINT operator*() const { return s ^ t; }\n    iter &operator++() {\n    \
    \  (t == 0 ? ed = 1 : t = (t - 1) & s);\n      return *this;\n    }\n    bool\
    \ operator!=(const iter) const { return !ed; }\n  };\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  iter begin() const { return iter(s); }\n  iter end() const {\
    \ return iter(0); }\n};\n\ntemplate <typename T>\nT floor(T a, T b) {\n  return\
    \ a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename T>\nT ceil(T x, T y)\
    \ {\n  return floor(x + y - 1, y);\n}\ntemplate <typename T>\nT bmod(T x, T y)\
    \ {\n  return x - y * floor(x, y);\n}\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\nconstexpr ll\
    \ TEN[] = {\n    1LL,\n    10LL,\n    100LL,\n    1000LL,\n    10000LL,\n    100000LL,\n\
    \    1000000LL,\n    10000000LL,\n    100000000LL,\n    1000000000LL,\n    10000000000LL,\n\
    \    100000000000LL,\n    1000000000000LL,\n    10000000000000LL,\n    100000000000000LL,\n\
    \    1000000000000000LL,\n    10000000000000000LL,\n    100000000000000000LL,\n\
    \    1000000000000000000LL,\n};\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\
    \ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n\
    \  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return\
    \ A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n\
    \r\n// https://judge.yosupo.jp/submission/21623\r\nnamespace fastio {\r\nstatic\
    \ constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\nchar obuf[SZ];\r\nchar\
    \ out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil = 0, pir = 0, por = 0;\r\
    \n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr Pre() : num() {\r\n\
    \    for (int i = 0; i < 10000; i++) {\r\n      int n = i;\r\n      for (int j\
    \ = 3; j >= 0; j--) {\r\n        num[i][j] = n % 10 | '0';\r\n        n /= 10;\r\
    \n      }\r\n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n\
    \  memmove(ibuf, ibuf + pil, pir - pil);\r\n  pir = pir - pil + fread(ibuf + pir\
    \ - pil, 1, SZ - pir + pil, stdin);\r\n  pil = 0;\r\n  if (pir < SZ) ibuf[pir++]\
    \ = '\\n';\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(obuf, 1, por, stdout);\r\
    \n  por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n  do {\r\n    if (pil + 1 > pir)\
    \ load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\n}\r\n\r\nvoid\
    \ rd(string &x) {\r\n  x.clear();\r\n  char c;\r\n  do {\r\n    if (pil + 1 >\
    \ pir) load();\r\n    c = ibuf[pil++];\r\n  } while (isspace(c));\r\n  do {\r\n\
    \    x += c;\r\n    if (pil == pir) load();\r\n    c = ibuf[pil++];\r\n  } while\
    \ (!isspace(c));\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n\
    \  string s;\r\n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvoid rd_integer(T &x) {\r\n  if (pil + 100 > pir) load();\r\n  char c;\r\n \
    \ do c = ibuf[pil++];\r\n  while (c < '-');\r\n  bool minus = 0;\r\n  if constexpr\
    \ (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (c == '-') {\r\n   \
    \   minus = 1, c = ibuf[pil++];\r\n    }\r\n  }\r\n  x = 0;\r\n  while ('0' <=\
    \ c) {\r\n    x = x * 10 + (c & 15), c = ibuf[pil++];\r\n  }\r\n  if constexpr\
    \ (is_signed<T>::value || is_same_v<T, i128>) {\r\n    if (minus) x = -x;\r\n\
    \  }\r\n}\r\n\r\ntemplate <class T>\r\nenable_if_t<is_integral_v<T> || is_same_v<T,\
    \ i128> || is_same_v<T, u128>> rd(\r\n    T &x) {\r\n  rd_integer(x);\r\n}\r\n\
    \r\ntemplate <class T>\r\nenable_if_t<is_floating_point_v<T> || is_same_v<T, f128>>\
    \ rd(T &x) {\r\n  rd_real(x);\r\n}\r\n\r\ntemplate <class T, class U>\r\nvoid\
    \ rd(pair<T, U> &p) {\r\n  rd(p.first), rd(p.second);\r\n}\r\ntemplate <size_t\
    \ N = 0, typename T>\r\nvoid rd_tuple(T &t) {\r\n  if constexpr (N < tuple_size<T>::value)\
    \ {\r\n    auto &x = get<N>(t);\r\n    rd(x);\r\n    rd_tuple<N + 1>(t);\r\n \
    \ }\r\n}\r\ntemplate <class... T>\r\nvoid rd(tuple<T...> &tpl) {\r\n  rd_tuple(tpl);\r\
    \n}\r\n\r\ntemplate <size_t N = 0, typename T>\r\nvoid rd(array<T, N> &x) {\r\n\
    \  for (auto &d : x) rd(d);\r\n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\
    \n  for (auto &d : x) rd(d);\r\n}\r\n\r\nvoid read() {}\r\ntemplate <class H,\
    \ class... T>\r\nvoid read(H &h, T &...t) {\r\n  rd(h), read(t...);\r\n}\r\n\r\
    \ninline void wt_range(const char *s, size_t n) {\r\n  size_t i = 0;\r\n  while\
    \ (i < n) {\r\n    if (por == SZ) flush();\r\n    size_t chunk = min(n - i, (size_t)(SZ\
    \ - por));\r\n    memcpy(obuf + por, s + i, chunk);\r\n    por += chunk;\r\n \
    \   i += chunk;\r\n  }\r\n}\r\n\r\nvoid wt(const char c) {\r\n  if (por == SZ)\
    \ flush();\r\n  obuf[por++] = c;\r\n}\r\nvoid wt(const char *s) { wt_range(s,\
    \ strlen(s)); }\r\nvoid wt(const string &s) { wt_range(s.data(), s.size()); }\r\
    \n\r\ntemplate <typename T>\r\nvoid wt_integer(T x) {\r\n  if (por > SZ - 100)\
    \ flush();\r\n  if (x < 0) {\r\n    obuf[por++] = '-', x = -x;\r\n  }\r\n  int\
    \ outi;\r\n  for (outi = 96; x >= 10000; outi -= 4) {\r\n    memcpy(out + outi,\
    \ pre.num[x % 10000], 4);\r\n    x /= 10000;\r\n  }\r\n  if (x >= 1000) {\r\n\
    \    memcpy(obuf + por, pre.num[x], 4);\r\n    por += 4;\r\n  } else if (x >=\
    \ 100) {\r\n    memcpy(obuf + por, pre.num[x] + 1, 3);\r\n    por += 3;\r\n  }\
    \ else if (x >= 10) {\r\n    int q = (x * 103) >> 10;\r\n    obuf[por] = q | '0';\r\
    \n    obuf[por + 1] = (x - q * 10) | '0';\r\n    por += 2;\r\n  } else\r\n   \
    \ obuf[por++] = x | '0';\r\n  memcpy(obuf + por, out + outi + 4, 96 - outi);\r\
    \n  por += 96 - outi;\r\n}\r\n\r\ntemplate <typename T>\r\ninline void wt_real(T\
    \ x) {\r\n  static char buf[1000];\r\n  int n = std::snprintf(buf, sizeof(buf),\
    \ \"%.15f\", (double)x);\r\n  wt_range(buf, (size_t)n);\r\n}\r\n\r\ntemplate <class\
    \ T>\r\nenable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>>\
    \ wt(\r\n    T x) {\r\n  wt_integer(x);\r\n}\r\n\r\ntemplate <class T>\r\nenable_if_t<is_floating_point_v<T>\
    \ || is_same_v<T, f128>> wt(T x) {\r\n  wt_real(x);\r\n}\r\n\r\ninline void wt(bool\
    \ b) { wt(static_cast<char>('0' + (b ? 1 : 0))); }\r\n\r\ntemplate <class T, class\
    \ U>\r\nvoid wt(const pair<T, U> &val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n\
    \  wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid wt_tuple(const\
    \ T &t) {\r\n  if constexpr (N < tuple_size<T>::value) {\r\n    if constexpr (N\
    \ > 0) wt(' ');\r\n    wt(get<N>(t));\r\n    wt_tuple<N + 1>(t);\r\n  }\r\n}\r\
    \ntemplate <class... T>\r\nvoid wt(const tuple<T...> &tpl) {\r\n  wt_tuple(tpl);\r\
    \n}\r\ntemplate <class T, size_t S>\r\nvoid wt(const array<T, S> &val) {\r\n \
    \ auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n    if (i) wt('\
    \ ');\r\n    wt(val[i]);\r\n  }\r\n}\r\ntemplate <class T>\r\nvoid wt(const vector<T>\
    \ &val) {\r\n  auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n\
    \    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\nvoid print() { wt('\\\
    n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&...tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail)) wt(' ');\r\n  print(forward<Tail>(tail)...);\r\
    \n}\r\n\r\n// gcc expansion. called automaticall after main.\r\nvoid __attribute__((destructor))\
    \ _d() { flush(); }\r\n}  // namespace fastio\r\nusing fastio::flush;\r\nusing\
    \ fastio::print;\r\nusing fastio::read;\r\n\r\n#if defined(LOCAL)\r\n#define HDR\
    \ \"[DEBUG:\", __func__, __LINE__, \"]\"\r\n#define SHOW(...)                \
    \                                         \\\r\n  SHOW_IMPL(__VA_ARGS__, SHOW8,\
    \ SHOW7, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, \\\r\n            SHOW1)         \
    \                                               \\\r\n  (__VA_ARGS__)\r\n#define\
    \ SHOW_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME\r\n#define SHOW1(x)\
    \ print(HDR, #x, \"=\", (x)), flush()\r\n#define SHOW2(x, y) print(HDR, #x, \"\
    =\", (x), #y, \"=\", (y)), flush()\r\n#define SHOW3(x, y, z) \\\r\n  print(HDR,\
    \ #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z)), flush()\r\n#define SHOW4(x,\
    \ y, z, w) \\\r\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z),\
    \ #w, \"=\", (w)), flush()\r\n#define SHOW5(x, y, z, w, v)                   \
    \                               \\\r\n  print(HDR, #x, \"=\", (x), #y, \"=\",\
    \ (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\r\n        (v)),        \
    \                                                         \\\r\n      flush()\r\
    \n#define SHOW6(x, y, z, w, v, u)                                            \
    \   \\\r\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"\
    =\", (w), #v, \"=\", \\\r\n        (v), #u, \"=\", (u)),                     \
    \                              \\\r\n      flush()\r\n#define SHOW7(x, y, z, w,\
    \ v, u, t)                                            \\\r\n  print(HDR, #x, \"\
    =\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\r\n  \
    \      (v), #u, \"=\", (u), #t, \"=\", (t)),                                 \
    \    \\\r\n      flush()\r\n#define SHOW8(x, y, z, w, v, u, t, s)            \
    \                             \\\r\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y),\
    \ #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\r\n        (v), #u, \"=\", (u),\
    \ #t, \"=\", (t), #s, \"=\", (s)),                       \\\r\n      flush()\r\
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
    \ TIDAK(bool t = 1) { YA(!t); }\r\nvoid Alice(bool t = 1) { print(t ? \"Alice\"\
    \ : \"Bob\"); }\r\nvoid Bob(bool t = 1) { Alice(!t); }\r\n#line 4 \"test/1_mytest/monge_shortest_path.test.cpp\"\
    \n\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 3 \"random/random_monge.hpp\"\n\n// A[i1][j1] +\
    \ A[i2][j2] <= A[i1][j2] + A[i2][j1] for i1 < i2, j1 < j2.\nvvc<ll> random_monge_matrix(int\
    \ H, int W) {\n  ll LIM = 10;\n  vv(ll, D, H, W);\n  FOR(i, H) FOR(j, W) D[i][j]\
    \ = RNG(0, LIM + 1);\n\n  vv(ll, A, H, W);\n  FOR(i, H) FOR(j, W) {\n    ll x\
    \ = D[i][j];\n    if (i) x += A[i - 1][j];\n    if (j) x += A[i][j - 1];\n   \
    \ if (i && j) x -= A[i - 1][j - 1];\n    A[i][j] = x;\n  }\n\n  vc<ll> row(H),\
    \ col(W);\n  FOR(i, H) row[i] = RNG(-LIM * W, LIM * W + 1);\n  FOR(j, W) col[j]\
    \ = RNG(-LIM * H, LIM * H + 1);\n\n  FOR(i, H) FOR(j, W) A[i][j] = -A[i][j] +\
    \ row[i] + col[j];\n  return A;\n}\n#line 2 \"convex/monge/monge_shortest_path.hpp\"\
    \n\ntemplate <typename T>\nstruct Monge_Shortest_Path {\n  int N;\n  vc<T> dp;\n\
    \  vc<int> cnt, frm;\n\n  Monge_Shortest_Path(int N) : N(N) {}\n\n  template <typename\
    \ F>\n  pair<T, int> solve(F f, bool minimize_cnt = true) {\n    dp.assign(N +\
    \ 1, infty<T>);\n    cnt.assign(N + 1, infty<int>);\n    frm.assign(N + 1, 0);\n\
    \n    dp[0] = 0;\n    cnt[0] = 0;\n\n    auto better_tie = [&](int new_cnt, int\
    \ old_cnt) -> bool {\n      return minimize_cnt ? new_cnt < old_cnt : new_cnt\
    \ > old_cnt;\n    };\n\n    auto check = [&](int r, int l) -> void {\n      T\
    \ x = dp[l] + f(l, r);\n      int c = cnt[l] + 1;\n      if (dp[r] > x || (dp[r]\
    \ == x && better_tie(c, cnt[r]))) {\n        dp[r] = x;\n        cnt[r] = c;\n\
    \        frm[r] = l;\n      }\n    };\n\n    // simple larsch, https://noshi91.hatenablog.com/entry/2023/02/18/005856\n\
    \    auto dfs = [&](auto& dfs, int l, int r) -> void {\n      if (r - l == 1)\
    \ return;\n      int m = (l + r) / 2;\n\n      FOR(k, frm[l], frm[r] + 1) check(m,\
    \ k);\n      dfs(dfs, l, m);\n\n      FOR(k, l + 1, m + 1) check(r, k);\n    \
    \  dfs(dfs, m, r);\n    };\n\n    if (N > 0) {\n      check(N, 0);\n      dfs(dfs,\
    \ 0, N);\n    }\n\n    return {dp[N], cnt[N]};\n  }\n\n  vc<int> restore_path()\
    \ {\n    vc<int> path;\n    for (int v = N; v > 0; v = frm[v]) path.eb(v);\n \
    \   path.eb(0);\n    reverse(all(path));\n    return path;\n  }\n};\n\n// yuki705\
    \ \u3067\u306F simple larsch \u3088\u308A\u4F4E\u901F\u3060\u3063\u305F\u3057\u4F7F\
    \u308F\u306A\u3044\u60F3\u5B9A\u3067\u3044\u304F\n// #include \"convex/larsch.hpp\"\
    \n// // dp[r] = min_{0 <= l < r} dp[l] + f(l, r)\n// // \u9077\u79FB\u56DE\u6570\
    \u3092\u554F\u308F\u306A\u3044\n// template <typename T, typename F>\n// vc<T>\
    \ monge_shortest_path_larsch(int N, F f) {\n//   vc<T> dp(N + 1, infty<T>);\n\
    //   dp[0] = 0;\n\n//   auto g = [&](int i, int j) -> T {\n//     ++i;\n//   \
    \  if (i <= j) return infty<T>;\n//     return dp[j] + f(j, i);\n//   };\n\n//\
    \   LARSCH<T, decltype(g)> larsch(N, g);\n//   FOR(r, 1, N + 1) {\n//     int\
    \ l = larsch.get_argmin();\n//     dp[r] = dp[l] + f(l, r);\n//   }\n//   return\
    \ dp;\n// }\n#line 7 \"test/1_mytest/monge_shortest_path.test.cpp\"\n\nvoid test()\
    \ {\n  FOR(N, 1, 100) {\n    FOR(1000) {\n      auto A = random_monge_matrix(N\
    \ + 1, N + 1);\n\n      auto f = [&](int l, int r) -> ll {\n        assert(l <\
    \ r);\n        return A[l][r];\n      };\n\n      FOR(minimize_cnt, 2) {\n   \
    \     auto [dp, frm] = monge_shortest_path<ll>(N, f, minimize_cnt);\n\n      \
    \  vc<ll> dp2(N + 1, infty<ll>);\n        vc<int> cnt2(N + 1, infty<int>);\n \
    \       dp2[0] = 0;\n        cnt2[0] = 0;\n\n        FOR(r, 1, N + 1) {\n    \
    \      FOR(l, r) {\n            ll x = dp2[l] + f(l, r);\n            int c =\
    \ cnt2[l] + 1;\n            bool tie = minimize_cnt ? c < cnt2[r] : c > cnt2[r];\n\
    \            if (dp2[r] > x || (dp2[r] == x && tie)) {\n              dp2[r] =\
    \ x;\n              cnt2[r] = c;\n            }\n          }\n        }\n\n  \
    \      assert(dp == dp2);\n\n        int c = 0;\n        for (int v = N; v > 0;\
    \ v = frm[v]) ++c;\n        assert(c == cnt2[N]);\n      }\n    }\n  }\n}\n\n\
    void solve() {\n  INT(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"random/random_monge.hpp\"\n#include\
    \ \"convex/monge/monge_shortest_path.hpp\"\n\nvoid test() {\n  FOR(N, 1, 100)\
    \ {\n    FOR(1000) {\n      auto A = random_monge_matrix(N + 1, N + 1);\n\n  \
    \    auto f = [&](int l, int r) -> ll {\n        assert(l < r);\n        return\
    \ A[l][r];\n      };\n\n      FOR(minimize_cnt, 2) {\n        auto [dp, frm] =\
    \ monge_shortest_path<ll>(N, f, minimize_cnt);\n\n        vc<ll> dp2(N + 1, infty<ll>);\n\
    \        vc<int> cnt2(N + 1, infty<int>);\n        dp2[0] = 0;\n        cnt2[0]\
    \ = 0;\n\n        FOR(r, 1, N + 1) {\n          FOR(l, r) {\n            ll x\
    \ = dp2[l] + f(l, r);\n            int c = cnt2[l] + 1;\n            bool tie\
    \ = minimize_cnt ? c < cnt2[r] : c > cnt2[r];\n            if (dp2[r] > x || (dp2[r]\
    \ == x && tie)) {\n              dp2[r] = x;\n              cnt2[r] = c;\n   \
    \         }\n          }\n        }\n\n        assert(dp == dp2);\n\n        int\
    \ c = 0;\n        for (int v = N; v > 0; v = frm[v]) ++c;\n        assert(c ==\
    \ cnt2[N]);\n      }\n    }\n  }\n}\n\nvoid solve() {\n  INT(a, b);\n  print(a\
    \ + b);\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/random_monge.hpp
  - random/base.hpp
  - convex/monge/monge_shortest_path.hpp
  isVerificationFile: true
  path: test/1_mytest/monge_shortest_path.test.cpp
  requiredBy: []
  timestamp: '2026-07-14 09:59:38+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/monge_shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/monge_shortest_path.test.cpp
- /verify/test/1_mytest/monge_shortest_path.test.cpp.html
title: test/1_mytest/monge_shortest_path.test.cpp
---
