---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/dynamic_segtree.hpp
    title: ds/segtree/dynamic_segtree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_kth_smallest
    links:
    - https://judge.yosupo.jp/problem/range_kth_smallest
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n#line\
    \ 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate\
    \ <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using value_type\
    \ = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept { return x\
    \ + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return -x; }\r\
    \n  static constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\
    \n  static constexpr X unit() { return X(0); }\r\n  static constexpr bool commute\
    \ = true;\r\n};\r\n#line 2 \"ds/segtree/dynamic_segtree.hpp\"\n\r\n#line 1 \"\
    ds/node_pool.hpp\"\n// \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u306B\
    \u5F31\u3044\u306E\u3067 static \u3067\u78BA\u4FDD\u3059\u308B\u3053\u3068\ntemplate\
    \ <class Node>\nstruct Node_Pool {\n  struct Slot {\n    union alignas(Node) {\n\
    \      Slot* next;\n      unsigned char storage[sizeof(Node)];\n    };\n  };\n\
    \  using np = Node*;\n\n  static constexpr int CHUNK_SIZE = 1 << 12;\n\n  vc<unique_ptr<Slot[]>>\
    \ chunks;\n  Slot* cur = nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\
    \n  Node_Pool() { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&...\
    \ args) {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
    \  }\n\n  np clone(const np x) {\n    assert(x);\n    Slot* s = new_slot();\n\
    \    return ::new (s) Node(*x);  // \u30B3\u30D4\u30FC\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u547C\u3073\u51FA\u3057\n  }\n\n  void destroy(np x) {\n  \
    \  if (!x) return;\n    x->~Node();\n    auto s = reinterpret_cast<Slot*>(x);\n\
    \    s->next = free_head;\n    free_head = s;\n  }\n\n  void reset() {\n    free_head\
    \ = nullptr;\n    if (!chunks.empty()) {\n      cur = chunks[0].get();\n     \
    \ cur_used = 0;\n    }\n  }\n\n private:\n  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 4 \"ds/segtree/dynamic_segtree.hpp\"\n\r\n\
    // sparse \u3082\u3042\u308B\u306E\u3067\u72B6\u6CC1\u306B\u3088\u3063\u3066\u306F\
    \u305D\u3063\u3061\u3067\r\ntemplate <typename Monoid, bool PERSISTENT>\r\nstruct\
    \ Dynamic_SegTree {\r\n  using MX = Monoid;\r\n  using X = typename MX::value_type;\r\
    \n  using F = function<X(ll, ll)>;\r\n  F default_prod;\r\n\r\n  struct Node {\r\
    \n    Node *l, *r;\r\n    X x;\r\n  };\r\n\r\n  const ll L0, R0;\r\n  Node_Pool<Node>\
    \ pool;\r\n  using np = Node *;\r\n\r\n  Dynamic_SegTree(\r\n      ll L0, ll R0,\
    \ F default_prod = [](ll l, ll r) -> X { return MX::unit(); })\r\n      : default_prod(default_prod),\
    \ L0(L0), R0(R0) {}\r\n\r\n  np new_root() { return new_node(L0, R0); }\r\n\r\n\
    \  np new_node(const X x) {\r\n    np n = pool.create();\r\n    n->l = nullptr,\
    \ n->r = nullptr, n->x = x;\r\n    return n;\r\n  }\r\n\r\n  np new_node(ll l,\
    \ ll r) { return new_node(default_prod(l, r)); }\r\n  np new_node() { return new_node(L0,\
    \ R0); }\r\n\r\n  np new_node(const vc<X> &dat) {\r\n    assert(L0 == 0 && R0\
    \ == len(dat));\r\n    auto dfs = [&](auto &dfs, ll l, ll r) -> np {\r\n     \
    \ if (l == r) return nullptr;\r\n      if (r == l + 1) return new_node(dat[l]);\r\
    \n      ll m = (l + r) / 2;\r\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs,\
    \ m, r);\r\n      X x = MX::op(l_root->x, r_root->x);\r\n      np root = new_node(x);\r\
    \n      root->l = l_root, root->r = r_root;\r\n      return root;\r\n    };\r\n\
    \    return dfs(dfs, 0, len(dat));\r\n  }\r\n\r\n  X prod(np root, ll l, ll r)\
    \ {\r\n    assert(L0 <= l && l <= r && r <= R0);\r\n    if (!root || l == r) return\
    \ MX::unit();\r\n    X x = MX::unit();\r\n    prod_rec(root, L0, R0, l, r, x);\r\
    \n    return x;\r\n  }\r\n\r\n  np set(np root, ll i, const X &x) {\r\n    assert(root\
    \ && L0 <= i && i < R0);\r\n    root = (root ? copy_node(root) : new_node());\r\
    \n    set_rec(root, L0, R0, i, x);\r\n    return root;\r\n  }\r\n\r\n  np multiply(np\
    \ root, ll i, const X &x) {\r\n    assert(root && L0 <= i && i < R0);\r\n    root\
    \ = (root ? copy_node(root) : new_node());\r\n    multiply_rec(root, L0, R0, i,\
    \ x);\r\n    return root;\r\n  }\r\n\r\n  template <typename F>\r\n  ll max_right(np\
    \ root, F check, ll L) {\r\n    assert(root && L0 <= L && L <= R0 && check(MX::unit()));\r\
    \n    X x = MX::unit();\r\n    return max_right_rec(root, check, L0, R0, L, x);\r\
    \n  }\r\n\r\n  template <typename F>\r\n  ll min_left(np root, F check, ll R)\
    \ {\r\n    assert(L0 <= R && R <= R0 && check(MX::unit()));\r\n    X x = MX::unit();\r\
    \n    return min_left_rec(root, check, L0, R0, R, x);\r\n  }\r\n\r\n  // (idx,\
    \ val)\r\n  template <typename F>\r\n  void enumerate(np root, F f) {\r\n    if\
    \ (!root) return;\r\n    auto dfs = [&](auto &dfs, np c, ll l, ll r) -> void {\r\
    \n      if (!c) return;\r\n      if (r - l == 1) {\r\n        f(l, c->x);\r\n\
    \        return;\r\n      }\r\n      ll m = (l + r) / 2;\r\n      dfs(dfs, c->l,\
    \ l, m);\r\n      dfs(dfs, c->r, m, r);\r\n    };\r\n    dfs(dfs, root, L0, R0);\r\
    \n    return;\r\n  }\r\n\r\n  void reset() { pool.reset(); }\r\n\r\n private:\r\
    \n  np copy_node(np c) {\r\n    if (!c || !PERSISTENT) return c;\r\n    np n =\
    \ pool.create();\r\n    n->l = c->l, n->r = c->r, n->x = c->x;\r\n    return n;\r\
    \n  }\r\n\r\n  void set_rec(np c, ll l, ll r, ll i, const X &x) {\r\n    assert(c);\r\
    \n    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\u3042\u308B\r\n \
    \   if (r == l + 1) {\r\n      c->x = x;\r\n      return;\r\n    }\r\n    ll m\
    \ = (l + r) / 2;\r\n    if (l <= i && i < m) {\r\n      c->l = (c->l ? copy_node(c->l)\
    \ : new_node());\r\n      set_rec(c->l, l, m, i, x);\r\n    }\r\n    if (m <=\
    \ i && i < r) {\r\n      c->r = (c->r ? copy_node(c->r) : new_node());\r\n   \
    \   set_rec(c->r, m, r, i, x);\r\n    }\r\n    X xl = (c->l ? c->l->x : default_prod(l,\
    \ m));\r\n    X xr = (c->r ? c->r->x : default_prod(m, r));\r\n    c->x = MX::op(xl,\
    \ xr);\r\n    return;\r\n  }\r\n\r\n  void multiply_rec(np c, ll l, ll r, ll i,\
    \ const X &x) {\r\n    assert(c);\r\n    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\
    \u3057\u3066\u3042\u308B\r\n    if (r == l + 1) {\r\n      c->x = MX::op(c->x,\
    \ x);\r\n      return;\r\n    }\r\n    ll m = (l + r) / 2;\r\n    if (l <= i &&\
    \ i < m) {\r\n      c->l = (c->l ? copy_node(c->l) : new_node());\r\n      multiply_rec(c->l,\
    \ l, m, i, x);\r\n    }\r\n    if (m <= i && i < r) {\r\n      c->r = (c->r ?\
    \ copy_node(c->r) : new_node());\r\n      multiply_rec(c->r, m, r, i, x);\r\n\
    \    }\r\n    X xl = (c->l ? c->l->x : default_prod(l, m));\r\n    X xr = (c->r\
    \ ? c->r->x : default_prod(m, r));\r\n    c->x = MX::op(xl, xr);\r\n    return;\r\
    \n  }\r\n\r\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x) {\r\n    chmax(ql,\
    \ l);\r\n    chmin(qr, r);\r\n    if (ql >= qr) return;\r\n    if (!c) {\r\n \
    \     x = MX::op(x, default_prod(ql, qr));\r\n      return;\r\n    }\r\n    if\
    \ (l == ql && r == qr) {\r\n      x = MX::op(x, c->x);\r\n      return;\r\n  \
    \  }\r\n    ll m = (l + r) / 2;\r\n    prod_rec(c->l, l, m, ql, qr, x);\r\n  \
    \  prod_rec(c->r, m, r, ql, qr, x);\r\n  }\r\n\r\n  // \u3053\u308C new node \u4F5C\
    \u3063\u3066\u308B\u306E\u306F\u3055\u307C\u308A\r\n  template <typename F>\r\n\
    \  ll max_right_rec(np c, const F &check, ll l, ll r, ll ql, X &x) {\r\n    if\
    \ (r <= ql) return R0;\r\n    if (ql <= l && check(MX::op(x, c->x))) {\r\n   \
    \   x = MX::op(x, c->x);\r\n      return R0;\r\n    }\r\n    if (r == l + 1) return\
    \ l;\r\n    ll m = (l + r) / 2;\r\n    if (!c->l) c->l = new_node(l, m);\r\n \
    \   ll k = max_right_rec(c->l, check, l, m, ql, x);\r\n    if (k != R0) return\
    \ k;\r\n    if (!c->r) c->r = new_node(m, r);\r\n    return max_right_rec(c->r,\
    \ check, m, r, ql, x);\r\n  }\r\n\r\n  // \u3053\u308C new node \u4F5C\u3063\u3066\
    \u308B\u306E\u306F\u3055\u307C\u308A\r\n  template <typename F>\r\n  ll min_left_rec(np\
    \ c, const F &check, ll l, ll r, ll qr, X &x) {\r\n    if (qr <= l) return L0;\r\
    \n    if (r <= qr && check(MX::op(c->x, x))) {\r\n      x = MX::op(x, c->x);\r\
    \n      return L0;\r\n    }\r\n    if (r == l + 1) return r;\r\n    ll m = (l\
    \ + r) / 2;\r\n    if (!c->r) c->r = new_node(m, r);\r\n    ll k = min_left_rec(c->r,\
    \ check, m, r, qr, x);\r\n    if (k != L0) return k;\r\n    if (!c->l) c->l =\
    \ new_node(l, m);\r\n    return min_left_rec(c->l, check, l, m, qr, x);\r\n  }\r\
    \n};\n#line 6 \"test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(int, A, N);\n  Dynamic_SegTree<Monoid_Add<int>,\
    \ true> seg(0, N);\n  using np = decltype(seg)::np;\n  auto I = argsort(A);\n\n\
    \  vc<np> roots;\n  roots.eb(seg.new_node(0, N));\n  FOR(k, N) { roots.eb(seg.set(roots.back(),\
    \ I[k], 1)); }\n  FOR(Q) {\n    LL(L, R, k);\n    auto check = [&](ll t) -> bool\
    \ { return seg.prod(roots[t], L, R) <= k; };\n    ll t = binary_search(check,\
    \ 0, N);\n    print(A[I[t]]);\n  }\n}\n\nsigned main() {\n  solve();\n\n  return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_kth_smallest\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"alg/monoid/add.hpp\"\
    \n#include \"ds/segtree/dynamic_segtree.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n\
    \  VEC(int, A, N);\n  Dynamic_SegTree<Monoid_Add<int>, true> seg(0, N);\n  using\
    \ np = decltype(seg)::np;\n  auto I = argsort(A);\n\n  vc<np> roots;\n  roots.eb(seg.new_node(0,\
    \ N));\n  FOR(k, N) { roots.eb(seg.set(roots.back(), I[k], 1)); }\n  FOR(Q) {\n\
    \    LL(L, R, k);\n    auto check = [&](ll t) -> bool { return seg.prod(roots[t],\
    \ L, R) <= k; };\n    ll t = binary_search(check, 0, N);\n    print(A[I[t]]);\n\
    \  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/monoid/add.hpp
  - ds/segtree/dynamic_segtree.hpp
  - ds/node_pool.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
  requiredBy: []
  timestamp: '2025-12-02 22:29:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
- /verify/test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp.html
title: test/2_library_checker/data_structure/range_kth_smallest_pseg.test.cpp
---
