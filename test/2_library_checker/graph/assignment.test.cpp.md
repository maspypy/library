---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: flow/hungarian.hpp
    title: flow/hungarian.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/2_library_checker/graph/assignment.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n#if defined(__GNUC__)\n\
    #include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\nusing namespace\
    \ std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\n\
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
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a\
    \ < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a,\
    \ const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off =\
    \ 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i]\
    \ + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
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
    \ x) {\r\n  char buf[64];\r\n  int n = std::snprintf(buf, sizeof(buf), \"%.15g\"\
    , (double)x);\r\n\r\n  if (n == 2 && buf[0] == '-' && buf[1] == '0') {\r\n   \
    \ buf[0] = '0';\r\n    n = 1;\r\n  }\r\n  wt_range(buf, (size_t)n);\r\n}\r\n\r\
    \ntemplate <class T>\r\nenable_if_t<is_integral_v<T> || is_same_v<T, i128> ||\
    \ is_same_v<T, u128>> wt(\r\n    T x) {\r\n  wt_integer(x);\r\n}\r\n\r\ntemplate\
    \ <class T>\r\nenable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> wt(T\
    \ x) {\r\n  wt_real(x);\r\n}\r\n\r\ninline void wt(bool b) { wt(static_cast<char>('0'\
    \ + (b ? 1 : 0))); }\r\n\r\ntemplate <class T, class U>\r\nvoid wt(const pair<T,\
    \ U> &val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n  wt(val.second);\r\n}\r\ntemplate\
    \ <size_t N = 0, typename T>\r\nvoid wt_tuple(const T &t) {\r\n  if constexpr\
    \ (N < tuple_size<T>::value) {\r\n    if constexpr (N > 0) wt(' ');\r\n    wt(get<N>(t));\r\
    \n    wt_tuple<N + 1>(t);\r\n  }\r\n}\r\ntemplate <class... T>\r\nvoid wt(const\
    \ tuple<T...> &tpl) {\r\n  wt_tuple(tpl);\r\n}\r\ntemplate <class T, size_t S>\r\
    \nvoid wt(const array<T, S> &val) {\r\n  auto n = val.size();\r\n  for (size_t\
    \ i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\
    \ntemplate <class T>\r\nvoid wt(const vector<T> &val) {\r\n  auto n = val.size();\r\
    \n  for (size_t i = 0; i < n; i++) {\r\n    if (i) wt(' ');\r\n    wt(val[i]);\r\
    \n  }\r\n}\r\n\r\nvoid print() { wt('\\n'); }\r\ntemplate <class Head, class...\
    \ Tail>\r\nvoid print(Head &&head, Tail &&...tail) {\r\n  wt(head);\r\n  if (sizeof...(Tail))\
    \ wt(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\n// gcc expansion. called\
    \ automaticall after main.\r\nvoid __attribute__((destructor)) _d() { flush();\
    \ }\r\n}  // namespace fastio\r\nusing fastio::flush;\r\nusing fastio::print;\r\
    \nusing fastio::read;\r\n\r\n#if defined(LOCAL)\r\n#define HDR \"[DEBUG:\", __func__,\
    \ __LINE__, \"]\"\r\n#define SHOW(...)                                       \
    \                  \\\r\n  SHOW_IMPL(__VA_ARGS__, SHOW8, SHOW7, SHOW6, SHOW5,\
    \ SHOW4, SHOW3, SHOW2, \\\r\n            SHOW1)                              \
    \                          \\\r\n  (__VA_ARGS__)\r\n#define SHOW_IMPL(_1, _2,\
    \ _3, _4, _5, _6, _7, _8, NAME, ...) NAME\r\n#define SHOW1(x) print(HDR, #x, \"\
    =\", (x)), flush()\r\n#define SHOW2(x, y) print(HDR, #x, \"=\", (x), #y, \"=\"\
    , (y)), flush()\r\n#define SHOW3(x, y, z) \\\r\n  print(HDR, #x, \"=\", (x), #y,\
    \ \"=\", (y), #z, \"=\", (z)), flush()\r\n#define SHOW4(x, y, z, w) \\\r\n  print(HDR,\
    \ #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w)), flush()\r\n\
    #define SHOW5(x, y, z, w, v)                                                 \
    \ \\\r\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\"\
    , (w), #v, \"=\", \\\r\n        (v)),                                        \
    \                         \\\r\n      flush()\r\n#define SHOW6(x, y, z, w, v,\
    \ u)                                               \\\r\n  print(HDR, #x, \"=\"\
    , (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\r\n     \
    \   (v), #u, \"=\", (u)),                                                   \\\
    \r\n      flush()\r\n#define SHOW7(x, y, z, w, v, u, t)                      \
    \                      \\\r\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z,\
    \ \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\r\n        (v), #u, \"=\", (u), #t,\
    \ \"=\", (t)),                                     \\\r\n      flush()\r\n#define\
    \ SHOW8(x, y, z, w, v, u, t, s)                                         \\\r\n\
    \  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w),\
    \ #v, \"=\", \\\r\n        (v), #u, \"=\", (u), #t, \"=\", (t), #s, \"=\", (s)),\
    \                       \\\r\n      flush()\r\n#else\r\n#define SHOW(...)\r\n\
    #endif\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
    \ U32(...)   \\\r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define U64(...)\
    \   \\\r\n  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)   \
    \   \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)\
    \   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)  \
    \    \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type,\
    \ name, size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define\
    \ VV(type, name, h, w)                     \\\r\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ?\
    \ \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t\
    \ = 1) { print(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\n\
    void yes(bool t = 1) { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) {\
    \ yes(!t); }\r\nvoid YA(bool t = 1) { print(t ? \"YA\" : \"TIDAK\"); }\r\nvoid\
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 4 \"test/2_library_checker/graph/assignment.test.cpp\"\
    \n\n#line 1 \"flow/hungarian.hpp\"\n// returns: (ans, match, X, Y)\n// N<=M \u3092\
    \u4EEE\u5B9A, infty \u3082 valid \u3068\u3057\u3066\u8A08\u7B97\u3057\u3066\u3044\
    \u308B, O(N^2M) time\u3002\n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306F\u6B21\
    \u306E\u53CC\u5BFE\u554F\u984C\u306E\u89E3\u3067\u3042\u308B\uFF1A\n//   maximize\
    \ \\sum x_i + \\sum y_j, subj to x_i + y_j\\leq C_{ij}\n// n \u30EB\u30FC\u30D7\
    \u3067\u6253\u3061\u5207\u3063\u3066\u3082\u5927\u304D\u3055 n \u306E\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u306E\u6700\u9069\u89E3\u3067\u306F\u306A\u3044\ntemplate <typename\
    \ T, bool MINIMIZE>\ntuple<T, vc<int>, vc<T>, vc<T>> hungarian(vvc<T>& C) {\n\
    \  if (C.empty()) { return {0, {}, {}, {}}; }\n  int N = len(C);\n  int M = len(C[0]);\n\
    \  assert(N <= M);\n  vv(T, A, N + 1, M + 1);\n  FOR(i, N) FOR(j, M) A[1 + i][1\
    \ + j] = (MINIMIZE ? 1 : -1) * C[i][j];\n  ++N, ++M;\n\n  vector<int> P(M), way(M);\n\
    \  vector<T> X(N), Y(M);\n  vc<T> minV;\n  vc<bool> used;\n\n  for (int i = 1;\
    \ i < N; i++) {\n    P[0] = i;\n    minV.assign(M, infty<T>);\n    used.assign(M,\
    \ false);\n    int j0 = 0;\n    while (P[j0] != 0) {\n      int i0 = P[j0], j1\
    \ = 0;\n      used[j0] = true;\n      T delta = infty<T>;\n      for (int j =\
    \ 1; j < M; j++) {\n        if (used[j]) continue;\n        T curr = A[i0][j]\
    \ - X[i0] - Y[j];\n        if (curr < minV[j]) minV[j] = curr, way[j] = j0;\n\
    \        if (minV[j] < delta) delta = minV[j], j1 = j;\n      }\n      for (int\
    \ j = 0; j < M; j++) {\n        if (used[j])\n          X[P[j]] += delta, Y[j]\
    \ -= delta;\n        else\n          minV[j] -= delta;\n      }\n      j0 = j1;\n\
    \    }\n    do {\n      P[j0] = P[way[j0]];\n      j0 = way[j0];\n    } while\
    \ (j0 != 0);\n  }\n  T res = -Y[0];\n  X.erase(X.begin());\n  Y.erase(Y.begin());\n\
    \  vc<int> match(N);\n  FOR(i, N) match[P[i]] = i;\n  match.erase(match.begin());\n\
    \  for (auto&& i: match) --i;\n  if (!MINIMIZE) res = -res;\n  return {res, match,\
    \ X, Y};\n}\n#line 6 \"test/2_library_checker/graph/assignment.test.cpp\"\n\n\
    void solve() {\n  LL(N);\n  VV(ll, A, N, N);\n  auto [ans, match, X, Y] = hungarian<ll,\
    \ true>(A);\n  print(ans);\n  print(match);\n\n  assert(SUM<ll>(X) + SUM<ll>(Y)\
    \ == ans);\n  FOR(i, N) FOR(j, N) assert(X[i] + Y[j] <= A[i][j]);\n}\n\nsigned\
    \ main() {\n  cout << fixed << setprecision(15);\n\n  solve();\n\n  return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"flow/hungarian.hpp\"\
    \n\nvoid solve() {\n  LL(N);\n  VV(ll, A, N, N);\n  auto [ans, match, X, Y] =\
    \ hungarian<ll, true>(A);\n  print(ans);\n  print(match);\n\n  assert(SUM<ll>(X)\
    \ + SUM<ll>(Y) == ans);\n  FOR(i, N) FOR(j, N) assert(X[i] + Y[j] <= A[i][j]);\n\
    }\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n  solve();\n\n \
    \ return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/hungarian.hpp
  isVerificationFile: true
  path: test/2_library_checker/graph/assignment.test.cpp
  requiredBy: []
  timestamp: '2025-10-30 08:59:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/graph/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/graph/assignment.test.cpp
- /verify/test/2_library_checker/graph/assignment.test.cpp.html
title: test/2_library_checker/graph/assignment.test.cpp
---
