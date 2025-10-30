---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/segtree/dynamic_segtree_sparse.hpp
    title: ds/segtree/dynamic_segtree_sparse.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_priority_queue
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/double_ended_pq_2.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\
    \nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\nusing u16\
    \ = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\n\
    using u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate <class T>\n\
    constexpr T infty = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
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
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 1 \"ds/segtree/dynamic_segtree_sparse.hpp\"\
    \n\n// \u5E38\u306B\u307B\u3068\u3093\u3069\u306E\u8981\u7D20\u304C unit \u3067\
    \u3042\u308B\u3053\u3068\u304C\u4FDD\u8A3C\u3055\u308C\u308B\u3088\u3046\u306A\
    \u52D5\u7684\u30BB\u30B0\u6728\n// \u3057\u305F\u304C\u3063\u3066\u3001default_prod\
    \ \u306E\u985E\u306F\u6301\u305F\u305B\u3089\u308C\u305A\u3001acted monoid \u3082\
    \u4E00\u822C\u306B\u306F\u6271\u3048\u306A\u3044\n// \u8FFD\u52A0 N \u56DE\u306E\
    \u3068\u304D\u30CE\u30FC\u30C9\u6570 N \u4EE5\u4E0B\u304C\u4FDD\u8A3C\u3055\u308C\
    \u308B\ntemplate <typename Monoid, bool PERSISTENT>\nstruct Dynamic_SegTree_Sparse\
    \ {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\n  struct Node\
    \ {\n    int ch[2];\n    ll idx;\n    X prod, x;\n  };\n  const ll L0, R0;\n \
    \ static constexpr int NIL = 0;\n  vc<Node> node;\n  vc<int> FREE;\n\n  Dynamic_SegTree_Sparse(ll\
    \ L0, ll R0) : L0(L0), R0(R0) { reset(); }\n  void reserve(int n) { node.reserve(n\
    \ + 1); }\n  void reset() {\n    node.clear(), FREE.clear();\n    node.eb(Node{{NIL,\
    \ NIL}, 0, MX::unit(), MX::unit()});  // NIL\n  }\n\n  // \u6728 dp \u306E\u30DE\
    \u30FC\u30B8\u306E\u3068\u304D\u306A\u3069\u306B\u4F7F\u7528\u3059\u308B\u3068\
    \ MLE \u56DE\u907F\u3067\u304D\u308B\u3053\u3068\u304C\u3042\u308B\n  // https://codeforces.com/problemset/problem/671/D\n\
    \  void free_subtree(int c) {\n    assert(c != NIL);\n    auto dfs = [&](auto\
    \ &dfs, int c) -> void {\n      if (c == NIL) return;\n      dfs(dfs, node[c].ch[0]),\
    \ dfs(dfs, node[c].ch[1]);\n      FREE.eb(c);\n    };\n    dfs(dfs, c);\n  }\n\
    \n  inline int new_root() { return NIL; }\n\n  inline int new_node(ll idx, const\
    \ X x) {\n    if (!FREE.empty()) {\n      int id = POP(FREE);\n      node[id].ch[0]\
    \ = node[id].ch[1] = NIL;\n      node[id].idx = idx, node[id].x = x, node[id].prod\
    \ = x;\n      return id;\n    }\n    node.eb(Node{{NIL, NIL}, idx, x, x});\n \
    \   return int(node.size()) - 1;\n  }\n  inline Node operator[](int i) const {\
    \ return node[i]; }\n\n  X prod(int root, ll l, ll r) {\n    assert(L0 <= l &&\
    \ l <= r && r <= R0);\n    if (root == NIL || l == r) return MX::unit();\n   \
    \ X x = MX::unit();\n    prod_rec(root, L0, R0, l, r, x);\n    return x;\n  }\n\
    \n  X prod_all(int root) { return (root == NIL ? MX::unit() : node[root].prod);\
    \ }\n\n  int set(int root, ll i, const X &x) {\n    assert(L0 <= i && i < R0);\n\
    \    return set_rec(root, L0, R0, i, x);\n  }\n\n  int multiply(int root, ll i,\
    \ const X &x) {\n    assert(L0 <= i && i < R0);\n    return multiply_rec(root,\
    \ L0, R0, i, x);\n  }\n\n  template <typename F>\n  ll max_right(int root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return max_right_rec(root, check, L0, R0, L, x);\n  }\n\n  template <typename\
    \ F>\n  ll min_left(int root, F check, ll R) {\n    assert(L0 <= R && R <= R0\
    \ && check(MX::unit()));\n    X x = MX::unit();\n    return min_left_rec(root,\
    \ check, L0, R0, R, x);\n  }\n\n  vc<pair<ll, X>> get_all(int root) {\n    vc<pair<ll,\
    \ X>> res;\n    auto dfs = [&](auto &dfs, int c) -> void {\n      if (c == NIL)\
    \ return;\n      dfs(dfs, node[c].ch[0]);\n      res.eb(node[c].idx, node[c].x);\n\
    \      dfs(dfs, node[c].ch[1]);\n    };\n    dfs(dfs, root);\n    return res;\n\
    \  }\n\n  X get(int root, ll idx) {\n    auto dfs = [&](auto &dfs, int c) -> X\
    \ {\n      if (c == NIL) return MX::unit();\n      if (idx == node[c].idx) return\
    \ node[c].x;\n      return dfs(dfs, node[c].ch[idx > node[c].idx]);\n    };\n\
    \    return dfs(dfs, root);\n  }\n\n private:\n  inline void update(int c) {\n\
    \    node[c].prod = node[c].x;\n    node[c].prod = MX::op(node[node[c].ch[0]].prod,\
    \ node[c].prod);\n    node[c].prod = MX::op(node[c].prod, node[node[c].ch[1]].prod);\n\
    \  }\n\n  inline int clone(int c) {\n    if constexpr (!PERSISTENT)\n      return\
    \ c;\n    else {\n      if (c == NIL) return c;\n      node.eb(node[c]);\n   \
    \   return int(node.size()) - 1;\n    }\n  }\n\n  int set_rec(int c, ll l, ll\
    \ r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c = clone(c);\n\
    \    if (node[c].idx == i) {\n      node[c].x = x;\n      update(c);\n      return\
    \ c;\n    }\n    ll m = (l + r) / 2;\n    if (i < m) {\n      if (node[c].idx\
    \ < i) swap(node[c].idx, i), swap(node[c].x, x);\n      node[c].ch[0] = set_rec(node[c].ch[0],\
    \ l, m, i, x);\n    }\n    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx,\
    \ i), swap(node[c].x, x);\n      node[c].ch[1] = set_rec(node[c].ch[1], m, r,\
    \ i, x);\n    }\n    update(c);\n    return c;\n  }\n\n  int multiply_rec(int\
    \ c, ll l, ll r, ll i, X x) {\n    if (c == NIL) return new_node(i, x);\n    c\
    \ = clone(c);\n    if (node[c].idx == i) {\n      node[c].x = MX::op(node[c].x,\
    \ x);\n      update(c);\n      return c;\n    }\n    ll m = (l + r) / 2;\n   \
    \ if (i < m) {\n      if (node[c].idx < i) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[0] = multiply_rec(node[c].ch[0], l, m, i, x);\n    }\n\
    \    if (m <= i) {\n      if (i < node[c].idx) swap(node[c].idx, i), swap(node[c].x,\
    \ x);\n      node[c].ch[1] = multiply_rec(node[c].ch[1], m, r, i, x);\n    }\n\
    \    update(c);\n    return c;\n  }\n\n  void prod_rec(int c, ll l, ll r, ll ql,\
    \ ll qr, X &x) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr || c\
    \ == NIL) return;\n    if (l == ql && r == qr) {\n      x = MX::op(x, node[c].prod);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    prod_rec(node[c].ch[0], l,\
    \ m, ql, qr, x);\n    if (ql <= (node[c].idx) && (node[c].idx) < qr) x = MX::op(x,\
    \ node[c].x);\n    prod_rec(node[c].ch[1], m, r, ql, qr, x);\n  }\n\n  template\
    \ <typename F>\n  ll max_right_rec(int c, const F &check, ll l, ll r, ll ql, X\
    \ &x) {\n    if (c == NIL || r <= ql) return R0;\n    if (check(MX::op(x, node[c].prod)))\
    \ {\n      x = MX::op(x, node[c].prod);\n      return R0;\n    }\n    ll m = (l\
    \ + r) / 2;\n    ll k = max_right_rec(node[c].ch[0], check, l, m, ql, x);\n  \
    \  if (k != R0) return k;\n    if (ql <= node[c].idx) {\n      x = MX::op(x, node[c].x);\n\
    \      if (!check(x)) return node[c].idx;\n    }\n    return max_right_rec(node[c].ch[1],\
    \ check, m, r, ql, x);\n  }\n\n  template <typename F>\n  ll min_left_rec(int\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\n    if (c == NIL || qr <= l)\
    \ return L0;\n    if (check(MX::op(node[c].prod, x))) {\n      x = MX::op(node[c].prod,\
    \ x);\n      return L0;\n    }\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(node[c].ch[1],\
    \ check, m, r, qr, x);\n    if (k != L0) return k;\n    if (node[c].idx < qr)\
    \ {\n      x = MX::op(node[c].x, x);\n      if (!check(x)) return node[c].idx\
    \ + 1;\n    }\n    return min_left_rec(node[c].ch[0], check, l, m, qr, x);\n \
    \ }\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 7 \"test/2_library_checker/data_structure/double_ended_pq_2.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(int, A, N);\n  const int LIM = 1'000'000'000;\n\
    \n  Dynamic_SegTree_Sparse<Monoid_Add<int>, false> seg(-LIM, LIM + 1);\n  int\
    \ root = decltype(seg)::NIL;\n  for (auto&& a : A) root = seg.multiply(root, a,\
    \ 1);\n\n  FOR(Q) {\n    LL(t);\n    if (t == 0) {\n      LL(x);\n      root =\
    \ seg.multiply(root, x, 1);\n    }\n    if (t == 1) {\n      auto check = [&](auto\
    \ e) -> bool { return e == 0; };\n      int ANS = seg.max_right(root, check, -LIM);\n\
    \      print(ANS);\n      root = seg.multiply(root, ANS, -1);\n    }\n    if (t\
    \ == 2) {\n      auto check = [&](auto e) -> bool { return e == 0; };\n      int\
    \ ANS = seg.min_left(root, check, LIM + 1) - 1;\n      print(ANS);\n      root\
    \ = seg.multiply(root, ANS, -1);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/double_ended_priority_queue\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/segtree/dynamic_segtree_sparse.hpp\"\
    \n#include \"alg/monoid/add.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(int, A,\
    \ N);\n  const int LIM = 1'000'000'000;\n\n  Dynamic_SegTree_Sparse<Monoid_Add<int>,\
    \ false> seg(-LIM, LIM + 1);\n  int root = decltype(seg)::NIL;\n  for (auto&&\
    \ a : A) root = seg.multiply(root, a, 1);\n\n  FOR(Q) {\n    LL(t);\n    if (t\
    \ == 0) {\n      LL(x);\n      root = seg.multiply(root, x, 1);\n    }\n    if\
    \ (t == 1) {\n      auto check = [&](auto e) -> bool { return e == 0; };\n   \
    \   int ANS = seg.max_right(root, check, -LIM);\n      print(ANS);\n      root\
    \ = seg.multiply(root, ANS, -1);\n    }\n    if (t == 2) {\n      auto check =\
    \ [&](auto e) -> bool { return e == 0; };\n      int ANS = seg.min_left(root,\
    \ check, LIM + 1) - 1;\n      print(ANS);\n      root = seg.multiply(root, ANS,\
    \ -1);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree/dynamic_segtree_sparse.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/double_ended_pq_2.test.cpp
  requiredBy: []
  timestamp: '2025-10-30 08:59:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/double_ended_pq_2.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/double_ended_pq_2.test.cpp
- /verify/test/2_library_checker/data_structure/double_ended_pq_2.test.cpp.html
title: test/2_library_checker/data_structure/double_ended_pq_2.test.cpp
---
