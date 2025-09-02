---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/segtree/beats_summinmax_chminchmax.hpp
    title: ds/segtree/beats_summinmax_chminchmax.hpp
  - icon: ':x:'
    path: ds/segtree/segtree_beats.hpp
    title: ds/segtree/segtree_beats.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
    #else\n\n// https://codeforces.com/blog/entry/96344\n// https://codeforces.com/blog/entry/126772?#comment-1154880\n\
    #if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\"\
    )\n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n\nusing\
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
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ ll(distance((c).begin(), lower_bound(all(c), (x))))\n#define UB(c, x) ll(distance((c).begin(),\
    \ upper_bound(all(c), (x))))\n#define UNIQUE(x) \\\n  sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <class T,\
    \ class Container, class Compare>\nT POP(priority_queue<T, Container, Compare>\
    \ &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n  return a;\n\
    }\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll ng, bool check_ok\
    \ = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok - ng) > 1)\
    \ {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check, double ok,\
    \ double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n\
    \    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class\
    \ T, class S>\ninline bool chmax(T &a, const S &b) {\n  return (a < b ? a = b,\
    \ 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  vc<T> &res\
    \ = first;\n  (res.insert(res.end(), others.begin(), others.end()), ...);\n}\n\
    #endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\
    \nnamespace fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\
    \nchar obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil\
    \ = 0, pir = 0, por = 0;\r\n\r\nstruct Pre {\r\n  char num[10000][4];\r\n  constexpr\
    \ Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n      int n = i;\r\
    \n      for (int j = 3; j >= 0; j--) {\r\n        num[i][j] = n % 10 | '0';\r\n\
    \        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline\
    \ void load() {\r\n  memmove(ibuf, ibuf + pil, pir - pil);\r\n  pir = pir - pil\
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
    \n  do c = ibuf[pil++];\r\n  while (c < '-');\r\n  bool minus = 0;\r\n  if constexpr\
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
    \n// \u5148\u306B\u7528\u610F\uFF08\u65E2\u51FA\u306A\u3089\u4E0D\u8981\uFF09\r\
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
    \ x) {\r\n  char buf[64];\r\n  // \u6709\u52B9\u6570\u5B57 15 \u6841\u3001\u901A\
    \u5E38/\u6307\u6570\u3092\u81EA\u52D5\u9078\u629E\uFF08printf(\"%.15g\") \u76F8\
    \u5F53\uFF09\r\n  int n = std::snprintf(buf, sizeof(buf), \"%.15g\", (double)x);\r\
    \n\r\n  // \uFF08\u4EFB\u610F\uFF09-0 \u3092 0 \u306B\u6B63\u898F\u5316\r\n  if\
    \ (n == 2 && buf[0] == '-' && buf[1] == '0') {\r\n    buf[0] = '0';\r\n    n =\
    \ 1;\r\n  }\r\n  wt_range(buf, (size_t)n);\r\n}\r\n\r\ntemplate <class T>\r\n\
    enable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>> wt(\r\
    \n    T x) {\r\n  wt_integer(x);\r\n}\r\n\r\ntemplate <class T>\r\nenable_if_t<is_floating_point_v<T>\
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
    \ fastio::print;\r\nusing fastio::read;\r\n\r\n#if defined(LOCAL)\r\nusing fastio::wt;\r\
    \n#define P1(x)                                                              \
    \  \\\r\n  wt(\"[DEBUG \"), wt(__func__), wt(\":\"), wt((int)__LINE__), wt(\"\
    ] \"), wt(#x), \\\r\n      wt(\" = \"), wt(x)\r\n#define P_(x) wt(\", \"), wt(#x),\
    \ wt(\" = \"), wt(x)\r\n\r\n#define SHOW1(a) P1(a), wt(\"\\n\")\r\n#define SHOW2(a,\
    \ b) P1(a), P_(b), wt(\"\\n\")\r\n#define SHOW3(a, b, c) P1(a), P_(b), P_(c),\
    \ wt(\"\\n\")\r\n#define SHOW4(a, b, c, d) P1(a), P_(b), P_(c), P_(d), wt(\"\\\
    n\")\r\n#define SHOW5(a, b, c, d, e) P1(a), P_(b), P_(c), P_(d), P_(e), wt(\"\\\
    n\")\r\n#define SHOW6(a, b, c, d, e, f) \\\r\n  P1(a), P_(b), P_(c), P_(d), P_(e),\
    \ P_(f), wt(\"\\n\")\r\n#define SHOW7(a, b, c, d, e, f, g) \\\r\n  P1(a), P_(b),\
    \ P_(c), P_(d), P_(e), P_(f), P_(g), wt(\"\\n\")\r\n#define SHOW8(a, b, c, d,\
    \ e, f, g, h) \\\r\n  P1(a), P_(b), P_(c), P_(d), P_(e), P_(f), P_(g), P_(h),\
    \ wt(\"\\n\")\r\n\r\n#define SHOW_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...)\
    \ NAME\r\n#define SHOW(...)                                                  \
    \       \\\r\n  SHOW_IMPL(__VA_ARGS__, SHOW8, SHOW7, SHOW6, SHOW5, SHOW4, SHOW3,\
    \ SHOW2, \\\r\n            SHOW1)                                            \
    \            \\\r\n  (__VA_ARGS__)\r\n#else\r\n#define SHOW(...)\r\n#endif\r\n\
    \r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define\
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
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 2 \"ds/segtree/segtree_beats.hpp\"\n\n\
    template <typename ActedMonoid>\nstruct SegTree_Beats {\n  using AM = ActedMonoid;\n\
    \  using MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using\
    \ X = typename MX::value_type;\n  using A = typename MA::value_type;\n  int n,\
    \ log, size;\n  vc<X> dat;\n  vc<A> laz;\n\n  SegTree_Beats() {}\n  SegTree_Beats(int\
    \ n) { build(n); }\n  template <typename F>\n  SegTree_Beats(int n, F f) {\n \
    \   build(n, f);\n  }\n  SegTree_Beats(const vc<X>& v) { build(v); }\n\n  void\
    \ build(int m) {\n    build(m, [](int i) -> X { return MX::unit(); });\n  }\n\
    \  void build(const vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i];\
    \ });\n  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m, log\
    \ = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    dat.assign(size\
    \ << 1, MX::unit());\n    laz.assign(size, MA::unit());\n    FOR(i, n) dat[size\
    \ + i] = f(i);\n    FOR_R(i, 1, size) update(i);\n  }\n\n  void update(int k)\
    \ { dat[k] = MX::op(dat[2 * k], dat[2 * k + 1]); }\n  void set(int p, X x) {\n\
    \    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--)\
    \ push(p >> i);\n    dat[p] = x;\n    for (int i = 1; i <= log; i++) update(p\
    \ >> i);\n  }\n\n  X get(int p) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    return dat[p];\n  }\n\n\
    \  /*\n  void all_apply(int k, A a) {\n    dat[k] = ActedMonoid::act(dat[k], a);\n\
    \    if (k < size) {\n      laz[k] = MA::op(laz[k], a);\n      if (dat[k].fail)\
    \ push(k), update(k);\n    }\n  }\n  */\n\n  vc<X> get_all() {\n    FOR(k, 1,\
    \ size) { push(k); }\n    return {dat.begin() + size, dat.begin() + size + n};\n\
    \  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r && r <= n);\n  \
    \  if (l == r) return MX::unit();\n    l += size, r += size;\n    for (int i =\
    \ log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if\
    \ (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X xl = MX::unit(), xr\
    \ = MX::unit();\n    while (l < r) {\n      if (l & 1) xl = MX::op(xl, dat[l++]);\n\
    \      if (r & 1) xr = MX::op(dat[--r], xr);\n      l >>= 1, r >>= 1;\n    }\n\
    \    return MX::op(xl, xr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  void\
    \ apply(int l, int r, A a) {\n    assert(0 <= l && l <= r && r <= n);\n    if\
    \ (l == r) return;\n    l += size, r += size;\n    for (int i = log; i >= 1; i--)\
    \ {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i) << i)\
    \ != r) push((r - 1) >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l < r)\
    \ {\n      if (l & 1) apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n\
    \      l >>= 1, r >>= 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\nprivate:\n  void apply_at(int\
    \ k, A a) {\n    int sz = 1 << (log - topbit(k));\n    dat[k] = AM::act(dat[k],\
    \ a, sz);\n    if (k < size) {\n      laz[k] = MA::op(laz[k], a);\n      if (dat[k].fail)\
    \ push(k), update(k);\n    }\n  }\n\n  void push(int k) {\n    if (laz[k] == MA::unit())\
    \ return;\n    apply_at(2 * k, laz[k]), apply_at(2 * k + 1, laz[k]);\n    laz[k]\
    \ = MA::unit();\n  }\n};\n#line 2 \"ds/segtree/beats_summinmax_chminchmax.hpp\"\
    \n\r\ntemplate <typename T>\r\nstruct Beats_SumMinMax_ChminChmax {\r\n  struct\
    \ SumMinMax {\r\n    struct X {\r\n      T sum, min, max, minc, maxc, min2, max2;\r\
    \n      bool fail;\r\n    };\r\n    using value_type = X;\r\n    static X op(const\
    \ X& x, const X& y) {\r\n      if (x.min > x.max) return y;\r\n      if (y.min\
    \ > y.max) return x;\r\n      X z;\r\n      z.sum = x.sum + y.sum;\r\n\r\n   \
    \   z.min = min(x.min, y.min), z.max = max(x.max, y.max);\r\n      z.minc = (x.min\
    \ == z.min ? x.minc : 0) + (y.min == z.min ? y.minc : 0);\r\n      z.maxc = (x.max\
    \ == z.max ? x.maxc : 0) + (y.max == z.max ? y.maxc : 0);\r\n\r\n      z.min2\
    \ = z.max;\r\n      if (z.min < x.min && x.min < z.min2) z.min2 = x.min;\r\n \
    \     if (z.min < x.min2 && x.min2 < z.min2) z.min2 = x.min2;\r\n      if (z.min\
    \ < y.min && y.min < z.min2) z.min2 = y.min;\r\n      if (z.min < y.min2 && y.min2\
    \ < z.min2) z.min2 = y.min2;\r\n\r\n      z.max2 = z.min;\r\n      if (z.max >\
    \ x.max && x.max > z.max2) z.max2 = x.max;\r\n      if (z.max > x.max2 && x.max2\
    \ > z.max2) z.max2 = x.max2;\r\n      if (z.max > y.max && y.max > z.max2) z.max2\
    \ = y.max;\r\n      if (z.max > y.max2 && y.max2 > z.max2) z.max2 = y.max2;\r\n\
    \r\n      z.fail = 0;\r\n      return z;\r\n    }\r\n    static constexpr X unit()\
    \ {\r\n      return {0, infty<T>, -infty<T>, 0, 0, infty<T>, -infty<T>, 0};\r\n\
    \    }\r\n    bool commute = true;\r\n  };\r\n  struct AddChminChmax {\r\n   \
    \ using X = tuple<T, T, T>;\r\n    using value_type = X;\r\n    static constexpr\
    \ X op(const X& x, const X& y) {\r\n      auto [a, b, c] = x;\r\n      auto [d,\
    \ e, f] = y;\r\n      a += d, b += d, c += d;\r\n      b = min(b, e), c = min(c,\
    \ e), c = max(c, f);\r\n      return {a, b, c};\r\n    }\r\n    static constexpr\
    \ X unit() { return {0, infty<T>, -infty<T>}; }\r\n    bool commute = false;\r\
    \n  };\r\n  struct Beats {\r\n    using Monoid_X = SumMinMax;\r\n    using Monoid_A\
    \ = AddChminChmax;\r\n    using X = typename Monoid_X::value_type;\r\n    using\
    \ A = typename Monoid_A::value_type;\r\n    static X act(X& x, const A& a, int\
    \ cnt) {\r\n      assert(!x.fail);\r\n      if (x.min > x.max) return x;\r\n \
    \     auto [add, mi, ma] = a;\r\n      x.sum += cnt * add;\r\n      x.min += add,\
    \ x.max += add, x.min2 += add, x.max2 += add;\r\n\r\n      if (mi == infty<T>\
    \ && ma == -infty<T>) return x;\r\n\r\n      T before_min = x.min, before_max\
    \ = x.max;\r\n      x.min = min(x.min, mi), x.min = max(x.min, ma);\r\n      x.max\
    \ = min(x.max, mi), x.max = max(x.max, ma);\r\n\r\n      if (x.min == x.max) {\r\
    \n        x.sum = x.max * cnt, x.max2 = x.min2 = x.max, x.maxc = x.minc = cnt;\r\
    \n      }\r\n      elif (x.max2 <= x.min) {\r\n        x.max2 = x.min, x.min2\
    \ = x.max, x.minc = cnt - x.maxc,\r\n        x.sum = x.max * x.maxc + x.min *\
    \ x.minc;\r\n      }\r\n      elif (x.min2 >= x.max) {\r\n        x.max2 = x.min,\
    \ x.min2 = x.max, x.maxc = cnt - x.minc,\r\n        x.sum = x.max * x.maxc + x.min\
    \ * x.minc;\r\n      }\r\n      elif (x.min < x.min2 && x.max > x.max2) {\r\n\
    \        x.sum += (x.min - before_min) * x.minc + (x.max - before_max) * x.maxc;\r\
    \n      }\r\n      else {\r\n        x.fail = 1;\r\n      }\r\n      return x;\r\
    \n    }\r\n  };\r\n\r\n  using X = typename SumMinMax::X;\r\n  SegTree_Beats<Beats>\
    \ seg;\r\n  Beats_SumMinMax_ChminChmax(vc<T>& A) {\r\n    seg.build(len(A), [&](int\
    \ i) -> X { return from_element(A[i]); });\r\n  }\r\n  template <typename F>\r\
    \n  Beats_SumMinMax_ChminChmax(int n, F f) {\r\n    seg.build(n, [&](int i) ->\
    \ X { return from_element(f(i)); });\r\n  }\r\n  void set(int i, T x) { seg.set(i,\
    \ from_element(x)); }\r\n\r\n  // (sum, max, min)\r\n  tuple<T, T, T> prod(int\
    \ l, int r) {\r\n    auto e = seg.prod(l, r);\r\n    return {e.sum, e.min, e.max};\r\
    \n  }\r\n  static X from_element(T x) { return {x, x, x, 1, 1, x, x, 0}; }\r\n\
    \r\n  void chmin(int l, int r, T x) { seg.apply(l, r, {0, x, -infty<T>}); }\r\n\
    \  void chmax(int l, int r, T x) { seg.apply(l, r, {0, infty<T>, x}); }\r\n  void\
    \ add(int l, int r, T x) { seg.apply(l, r, {x, infty<T>, -infty<T>}); }\r\n};\r\
    \n#line 7 \"test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp\"\
    \n\r\nvoid solve() {\r\n  LL(N, Q);\r\n  VEC(ll, A, N);\r\n  Beats_SumMinMax_ChminChmax<ll>\
    \ seg(A);\r\n  FOR(_, Q) {\r\n    LL(t, L, R);\r\n    if (t == 0) {\r\n      LL(x);\r\
    \n      seg.chmin(L, R, x);\r\n    }\r\n    elif (t == 1) {\r\n      LL(x);\r\n\
    \      seg.chmax(L, R, x);\r\n    }\r\n    elif (t == 2) {\r\n      LL(x);\r\n\
    \      seg.add(L, R, x);\r\n    }\r\n    elif (t == 3) { print(get<0>(seg.prod(L,\
    \ R))); }\r\n  }\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n  return 0;\r\n\
    }\r\n"
  code: "#define PROBLEM \\\r\n  \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \r\n\r\n#include \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include\
    \ \"ds/segtree/beats_summinmax_chminchmax.hpp\"\r\n\r\nvoid solve() {\r\n  LL(N,\
    \ Q);\r\n  VEC(ll, A, N);\r\n  Beats_SumMinMax_ChminChmax<ll> seg(A);\r\n  FOR(_,\
    \ Q) {\r\n    LL(t, L, R);\r\n    if (t == 0) {\r\n      LL(x);\r\n      seg.chmin(L,\
    \ R, x);\r\n    }\r\n    elif (t == 1) {\r\n      LL(x);\r\n      seg.chmax(L,\
    \ R, x);\r\n    }\r\n    elif (t == 2) {\r\n      LL(x);\r\n      seg.add(L, R,\
    \ x);\r\n    }\r\n    elif (t == 3) { print(get<0>(seg.prod(L, R))); }\r\n  }\r\
    \n}\r\n\r\nsigned main() {\r\n  solve();\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree/beats_summinmax_chminchmax.hpp
  - ds/segtree/segtree_beats.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-09-03 05:45:26+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/2_library_checker/data_structure/range_chmin_chmax_add_range_sum.test.cpp
---
