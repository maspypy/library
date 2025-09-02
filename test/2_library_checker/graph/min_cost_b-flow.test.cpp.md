---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/bflow.hpp
    title: flow/bflow.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#line 1 \"test/2_library_checker/graph/min_cost_b-flow.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#line 1 \"\
    my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\
    \n// https://codeforces.com/blog/entry/96344\n// https://codeforces.com/blog/entry/126772?#comment-1154880\n\
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
    \ all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else if\n\
    \n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n#define\
    \ fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x) { return\
    \ __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
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
    \ x, T y) {\n  T q = floor(x, y);\n  return {q, x - q * y};\n}\n\ninline constexpr\
    \ std::array<u64, 20> TEN_TAB = [] {\n  std::array<u64, 20> a{};\n  u64 x = 1;\n\
    \  for (int i = 0; i <= 19; ++i) {\n    a[i] = x, x *= 10;\n  }\n  return a;\n\
    }();\n\ninline constexpr u64 TEN(int n) {\n  assert(0 <= n && n <= 19);\n  return\
    \ TEN_TAB[n];\n}\n\ntemplate <int N>\ninline constexpr u64 TEN_v = [] {\n  static_assert(0\
    \ <= N && N <= 19);\n  return TEN_TAB[N];\n}();\n\ntemplate <typename T, typename\
    \ U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n\
    }\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    #define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c,\
    \ x) distance((c).begin(), upper_bound(all(c), (x)))\n#define UNIQUE(x) \\\n \
    \ sort(all(x)), x.erase(unique(all(x)), x.end()), x.shrink_to_fit()\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
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
    \ fastio::print;\r\nusing fastio::read;\r\n\r\n#if defined(LOCAL)\r\n#define P1(x)\
    \ print(\"[DEBUG\", __func__, \":\", __LINE__, \"]\", #x, \"=\", (x))\r\n#define\
    \ P_(x) print(\",\", #x, \"=\", (x))\r\n\r\n#define SHOW1(a) P1(a), flush()\r\n\
    #define SHOW2(a, b) P1(a), P_(b), flush()\r\n#define SHOW3(a, b, c) P1(a), P_(b),\
    \ P_(c), flush()\r\n#define SHOW4(a, b, c, d) P1(a), P_(b), P_(c), P_(d), flush()\r\
    \n#define SHOW5(a, b, c, d, e) P1(a), P_(b), P_(c), P_(d), P_(e), flush()\r\n\
    #define SHOW6(a, b, c, d, e, f) \\\r\n  P1(a), P_(b), P_(c), P_(d), P_(e), P_(f),\
    \ flush()\r\n#define SHOW7(a, b, c, d, e, f, g) \\\r\n  P1(a), P_(b), P_(c), P_(d),\
    \ P_(e), P_(f), P_(g), flush()\r\n#define SHOW8(a, b, c, d, e, f, g, h) \\\r\n\
    \  P1(a), P_(b), P_(c), P_(d), P_(e), P_(f), P_(g), P_(h), flush()\r\n\r\n#define\
    \ SHOW_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME\r\n#define SHOW(...)\
    \                                                         \\\r\n  SHOW_IMPL(__VA_ARGS__,\
    \ SHOW8, SHOW7, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, \\\r\n            SHOW1)  \
    \                                                      \\\r\n  (__VA_ARGS__)\r\
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
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 2 \"flow/bflow.hpp\"\n\n// \u8CA0\u8FBA\
    \u304C\u3042\u3063\u3066\u3082\u52D5\u4F5C\u3059\u308B\u3088\ntemplate <class\
    \ Flow = ll, class Cost = ll>\nstruct MinCostFlow {\n private:\n  static constexpr\
    \ int SCALING_FACTOR = 2;\n  using V_id = uint32_t;\n  using E_id = uint32_t;\n\
    \n  struct Edge {\n    friend struct MinCostFlow;\n\n   private:\n    V_id frm,\
    \ to;\n    Flow flow, cap;\n    Cost cost;\n    E_id rev;\n\n   public:\n    Edge()\
    \ = default;\n\n    Edge(const V_id frm, const V_id to, const Flow cap, const\
    \ Cost cost,\n         const E_id rev)\n        : frm(frm), to(to), flow(0), cap(cap),\
    \ cost(cost), rev(rev) {}\n\n    [[nodiscard]] Flow residual_cap() const { return\
    \ cap - flow; }\n  };\n\n public:\n  struct EdgePtr {\n    friend struct MinCostFlow;\n\
    \n   private:\n    const MinCostFlow *instance;\n    const V_id v;\n    const\
    \ E_id e;\n\n    EdgePtr(const MinCostFlow *instance, const V_id v, const E_id\
    \ e)\n        : instance(instance), v(v), e(e) {}\n\n    [[nodiscard]] const Edge\
    \ &edge() const { return instance->g[v][e]; }\n    [[nodiscard]] const Edge &rev()\
    \ const {\n      const Edge &e = edge();\n      return instance->g[e.to][e.rev];\n\
    \    }\n\n   public:\n    [[nodiscard]] V_id frm() const { return rev().to; }\n\
    \    [[nodiscard]] V_id to() const { return edge().to; }\n    [[nodiscard]] Flow\
    \ flow() const { return edge().flow; }\n    [[nodiscard]] Flow lower() const {\
    \ return -rev().cap; }\n    [[nodiscard]] Flow upper() const { return edge().cap;\
    \ }\n    [[nodiscard]] Cost cost() const { return edge().cost; }\n    [[nodiscard]]\
    \ Cost gain() const { return -edge().cost; }\n  };\n\n private:\n  V_id n;\n \
    \ std::vector<std::vector<Edge>> g;\n  std::vector<Flow> b;\n\n public:\n  MinCostFlow(int\
    \ n) : n(n) {\n    g.resize(n);\n    b.resize(n);\n  }\n\n  V_id add_vertex()\
    \ {\n    ++n;\n    g.resize(n);\n    b.resize(n);\n    return n - 1;\n  }\n\n\
    \  std::vector<V_id> add_vertices(const size_t size) {\n    std::vector<V_id>\
    \ ret;\n    for (V_id i = 0; i < size; ++i) ret.emplace_back(n + i);\n    n +=\
    \ size;\n    g.resize(n);\n    b.resize(n);\n    return ret;\n  }\n\n  void add(const\
    \ V_id frm, const V_id to, const Flow lo, const Flow hi,\n           const Cost\
    \ cost) {\n    const E_id e = g[frm].size(), re = frm == to ? e + 1 : g[to].size();\n\
    \    assert(lo <= hi);\n    g[frm].emplace_back(Edge{frm, to, hi, cost, re});\n\
    \    g[to].emplace_back(Edge{to, frm, -lo, -cost, e});\n    edges.eb(EdgePtr{this,\
    \ frm, e});\n  }\n\n  void add_source(const V_id v, const Flow amount) { b[v]\
    \ += amount; }\n  void add_sink(const V_id v, const Flow amount) { b[v] -= amount;\
    \ }\n\n private:\n  static Cost constexpr unreachable = std::numeric_limits<Cost>::max();\n\
    \  Cost farthest;\n  vc<Cost> potential, dist;\n  vc<Edge *> parent;\n  pq_min<pair<Cost,\
    \ int>> pq;\n  vc<V_id> excess_vs, deficit_vs;\n  vc<EdgePtr> edges;\n  Edge &rev(const\
    \ Edge &e) { return g[e.to][e.rev]; }\n\n  void push(Edge &e, const Flow amount)\
    \ {\n    e.flow += amount;\n    g[e.to][e.rev].flow -= amount;\n  }\n\n  Cost\
    \ residual_cost(const V_id frm, const V_id to, const Edge &e) {\n    return e.cost\
    \ + potential[frm] - potential[to];\n  }\n\n  bool dual(const Flow delta) {\n\
    \    dist.assign(n, unreachable);\n    parent.assign(n, nullptr);\n    excess_vs.erase(\n\
    \        remove_if(all(excess_vs), [&](const V_id v) { return b[v] < delta; }),\n\
    \        end(excess_vs));\n    deficit_vs.erase(\n        remove_if(all(deficit_vs),\
    \ [&](const V_id v) { return b[v] > -delta; }),\n        end(deficit_vs));\n \
    \   for (const auto v : excess_vs) pq.emplace(dist[v] = 0, v);\n    farthest =\
    \ 0;\n    size_t deficit_count = 0;\n    while (!pq.empty()) {\n      const auto\
    \ [d, u] = pq.top();\n      pq.pop();\n      if (dist[u] < d) continue;\n    \
    \  farthest = d;\n      if (b[u] <= -delta) ++deficit_count;\n      if (deficit_count\
    \ >= deficit_vs.size()) break;\n      for (auto &e : g[u]) {\n        if (e.residual_cap()\
    \ < delta) continue;\n        const auto v = e.to;\n        const auto new_dist\
    \ = d + residual_cost(u, v, e);\n        if (new_dist >= dist[v]) continue;\n\
    \        pq.emplace(dist[v] = new_dist, v);\n        parent[v] = &e;\n      }\n\
    \    }\n    pq = decltype(pq)();\n    for (V_id v = 0; v < n; ++v) {\n      potential[v]\
    \ += std::min(dist[v], farthest);\n    }\n    return deficit_count > 0;\n  }\n\
    \n  void primal(const Flow delta) {\n    for (const auto t : deficit_vs) {\n \
    \     if (dist[t] > farthest) continue;\n      Flow f = -b[t];\n      V_id v;\n\
    \      for (v = t; parent[v] != nullptr && f >= delta; v = parent[v]->frm) {\n\
    \        f = std::min(f, parent[v]->residual_cap());\n      }\n      f = std::min(f,\
    \ b[v]);\n      if (f < delta) continue;\n      for (v = t; parent[v] != nullptr;)\
    \ {\n        auto &e = *parent[v];\n        push(e, f);\n        const size_t\
    \ u = parent[v]->frm;\n        parent[v] = nullptr;\n        v = u;\n      }\n\
    \      b[t] += f;\n      b[v] -= f;\n    }\n  }\n\n  void saturate_negative(const\
    \ Flow delta) {\n    excess_vs.clear();\n    deficit_vs.clear();\n    for (auto\
    \ &es : g)\n      for (auto &e : es) {\n        const Flow rcap = e.residual_cap();\n\
    \        const Cost rcost = residual_cost(e.frm, e.to, e);\n        if (rcost\
    \ < 0 && rcap >= delta) {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n\
    \          b[e.to] += rcap;\n        }\n      }\n    for (V_id v = 0; v < n; ++v)\n\
    \      if (b[v] != 0) {\n        (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v);\n\
    \      }\n  }\n\n public:\n  std::pair<bool, i128> solve() {\n    potential.resize(n);\n\
    \    for (auto &es : g)\n      for (auto &e : es) {\n        const Flow rcap =\
    \ e.residual_cap();\n        if (rcap < 0) {\n          push(e, rcap);\n     \
    \     b[e.frm] -= rcap;\n          b[e.to] += rcap;\n        }\n      }\n    Flow\
    \ inf_flow = 1;\n    for (const auto &es : g)\n      for (const auto &e : es)\
    \ inf_flow = std::max(inf_flow, e.residual_cap());\n    Flow delta = 1;\n    while\
    \ (delta <= inf_flow) delta *= SCALING_FACTOR;\n\n    for (delta /= SCALING_FACTOR;\
    \ delta; delta /= SCALING_FACTOR) {\n      saturate_negative(delta);\n      while\
    \ (dual(delta)) primal(delta);\n    }\n\n    i128 value = 0;\n    for (const auto\
    \ &es : g)\n      for (const auto &e : es) {\n        value += i128(e.flow) *\
    \ e.cost;\n      }\n    value /= 2;\n\n    if (excess_vs.empty() && deficit_vs.empty())\
    \ {\n      return {true, value};\n    } else {\n      return {false, value};\n\
    \    }\n  }\n\n  template <class T>\n  T get_result_value() {\n    T value = 0;\n\
    \    for (const auto &es : g)\n      for (const auto &e : es) {\n        value\
    \ += (T)(e.flow) * (T)(e.cost);\n      }\n    value /= (T)2;\n    return value;\n\
    \  }\n\n  std::vector<Cost> get_potential() {\n    std::fill(potential.begin(),\
    \ potential.end(), 0);\n    for (int i = 0; i < (int)n; i++)\n      for (const\
    \ auto &es : g)\n        for (const auto &e : es)\n          if (e.residual_cap()\
    \ > 0)\n            potential[e.to] =\n                std::min(potential[e.to],\
    \ potential[e.frm] + e.cost);\n    return potential;\n  }\n\n  std::vector<EdgePtr>\
    \ get_edges() { return edges; }\n};\n#line 5 \"test/2_library_checker/graph/min_cost_b-flow.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, M);\n  MinCostFlow<ll, ll> G(N);\n  FOR(i, N) {\n\
    \    LL(b);\n    G.add_source(i, b);\n  }\n  FOR(i, M) {\n    LL(frm, to, lo,\
    \ hi, cost);\n    G.add(frm, to, lo, hi, cost);\n  }\n  auto [ok, cost] = G.solve();\n\
    \  if (!ok) return print(\"infeasible\");\n  print(cost);\n  for (auto &&p: G.get_potential())\
    \ print(p);\n  for (auto &&e: G.get_edges()) { print(e.flow()); }\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/bflow.hpp\"\n\
    \nvoid solve() {\n  LL(N, M);\n  MinCostFlow<ll, ll> G(N);\n  FOR(i, N) {\n  \
    \  LL(b);\n    G.add_source(i, b);\n  }\n  FOR(i, M) {\n    LL(frm, to, lo, hi,\
    \ cost);\n    G.add(frm, to, lo, hi, cost);\n  }\n  auto [ok, cost] = G.solve();\n\
    \  if (!ok) return print(\"infeasible\");\n  print(cost);\n  for (auto &&p: G.get_potential())\
    \ print(p);\n  for (auto &&e: G.get_edges()) { print(e.flow()); }\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/bflow.hpp
  isVerificationFile: true
  path: test/2_library_checker/graph/min_cost_b-flow.test.cpp
  requiredBy: []
  timestamp: '2025-09-02 10:27:54+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/graph/min_cost_b-flow.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/graph/min_cost_b-flow.test.cpp
- /verify/test/2_library_checker/graph/min_cost_b-flow.test.cpp.html
title: test/2_library_checker/graph/min_cost_b-flow.test.cpp
---
