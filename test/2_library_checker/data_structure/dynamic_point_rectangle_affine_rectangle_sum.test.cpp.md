---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add_pair.hpp
    title: alg/monoid/add_pair.hpp
  - icon: ':x:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':question:'
    path: ds/kdtree/kdtree_acted_monoid.hpp
    title: ds/kdtree/kdtree_acted_monoid.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum\"\
    \n#line 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 4 \"test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp\"\
    \n\n#line 1 \"ds/kdtree/kdtree_acted_monoid.hpp\"\ntemplate <class ActedMonoid,\
    \ typename XY>\r\nstruct KDTree_ActedMonoid {\r\n  using AM = ActedMonoid;\r\n\
    \  using MX = typename AM::Monoid_X;\r\n  using MA = typename AM::Monoid_A;\r\n\
    \  using X = typename AM::X;\r\n  using A = typename AM::A;\r\n  static_assert(MX::commute);\r\
    \n\r\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\
    \u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\
    \u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\
    \r\n  vc<tuple<XY, XY, XY, XY>> closed_range;\r\n  vc<X> dat;\r\n  vc<A> lazy;\r\
    \n  vc<int> size;\r\n  vc<int> pos; // raw data -> index\r\n  int n, log;\r\n\r\
    \n  KDTree_ActedMonoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\r\n    assert(n\
    \ > 0);\r\n    log = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1\
    \ << (log + 1));\r\n    lazy.assign(1 << log, MA::unit());\r\n    closed_range.assign(1\
    \ << (log + 1), {infty<XY>, -infty<XY>, infty<XY>, -infty<XY>});\r\n    size.resize(1\
    \ << (log + 1));\r\n    vc<int> ids(n);\r\n    pos.resize(n);\r\n    FOR(i, n)\
    \ ids[i] = i;\r\n    build(1, xs, ys, vs, ids);\r\n  }\r\n\r\n  void set(int i,\
    \ const X& v) {\r\n    i = pos[i];\r\n    for (int k = log; k >= 1; k--) { push(i\
    \ >> k); }\r\n    dat[i] = v;\r\n    while (i > 1) i /= 2, dat[i] = MX::op(dat[2\
    \ * i], dat[2 * i + 1]);\r\n  }\r\n  void multiply(int i, const X& v) {\r\n  \
    \  i = pos[i];\r\n    for (int k = log; k >= 1; k--) { push(i >> k); }\r\n   \
    \ dat[i] = MX::op(dat[i], v);\r\n    while (i > 1) i /= 2, dat[i] = MX::op(dat[2\
    \ * i], dat[2 * i + 1]);\r\n  }\r\n\r\n  // [xl, xr) x [yl, yr)\r\n  X prod(XY\
    \ xl, XY xr, XY yl, XY yr) {\r\n    assert(xl <= xr && yl <= yr);\r\n    return\
    \ prod_rec(1, xl, xr, yl, yr);\r\n  }\r\n\r\n  X prod_all() { return dat[1]; }\r\
    \n\r\n  // [xl, xr) x [yl, yr)\r\n  void apply(XY xl, XY xr, XY yl, XY yr, A a)\
    \ {\r\n    assert(xl <= xr && yl <= yr);\r\n    return apply_rec(1, xl, xr, yl,\
    \ yr, a);\r\n  }\r\n\r\nprivate:\r\n  void build(int idx, vc<XY> xs, vc<XY> ys,\
    \ vc<X> vs, vc<int> ids, bool divx = true) {\r\n    int n = len(xs);\r\n    size[idx]\
    \ = n;\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    xmin\
    \ = ymin = infty<XY>;\r\n    xmax = ymax = -infty<XY>;\r\n\r\n    FOR(i, n) {\r\
    \n      auto x = xs[i], y = ys[i];\r\n      chmin(xmin, x), chmax(xmax, x), chmin(ymin,\
    \ y), chmax(ymax, y);\r\n    }\r\n    if (n == 1) {\r\n      dat[idx] = vs[0];\r\
    \n      pos[ids[0]] = idx;\r\n      return;\r\n    }\r\n\r\n    int m = n / 2;\r\
    \n    vc<int> I(n);\r\n    iota(all(I), 0);\r\n    if (divx) {\r\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(), [xs](int i, int j) { return xs[i] < xs[j]; });\r\n \
    \   } else {\r\n      nth_element(I.begin(), I.begin() + m, I.end(), [ys](int\
    \ i, int j) { return ys[i] < ys[j]; });\r\n    }\r\n    xs = rearrange(xs, I),\
    \ ys = rearrange(ys, I), vs = rearrange(vs, I), ids = rearrange(ids, I);\r\n \
    \   build(2 * idx + 0, {xs.begin(), xs.begin() + m}, {ys.begin(), ys.begin() +\
    \ m}, {vs.begin(), vs.begin() + m}, {ids.begin(), ids.begin() + m}, !divx);\r\n\
    \    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\
    \ {vs.begin() + m, vs.end()}, {ids.begin() + m, ids.end()}, !divx);\r\n    dat[idx]\
    \ = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  inline bool isin(XY\
    \ x, XY y, int idx) {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\
    \n    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);\r\n  }\r\n\r\n\
    \  void apply_at(int idx, A a) {\r\n    dat[idx] = AM::act(dat[idx], a, size[idx]);\r\
    \n    if (idx < (1 << log)) lazy[idx] = MA::op(lazy[idx], a);\r\n  }\r\n\r\n \
    \ void push(int idx) {\r\n    if (lazy[idx] == MA::unit()) return;\r\n    apply_at(2\
    \ * idx + 0, lazy[idx]), apply_at(2 * idx + 1, lazy[idx]);\r\n    lazy[idx] =\
    \ MA::unit();\r\n  }\r\n\r\n  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2)\
    \ {\r\n    if (idx >= len(closed_range)) return MX::unit();\r\n    auto& [xmin,\
    \ xmax, ymin, ymax] = closed_range[idx];\r\n    if (xmin > xmax) return MX::unit();\r\
    \n    if (x2 <= xmin || xmax < x1) return MX::unit();\r\n    if (y2 <= ymin ||\
    \ ymax < y1) return MX::unit();\r\n    if (x1 <= xmin && xmax < x2 && y1 <= ymin\
    \ && ymax < y2) { return dat[idx]; }\r\n    push(idx);\r\n    return MX::op(prod_rec(2\
    \ * idx + 0, x1, x2, y1, y2), prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\
    \n\r\n  void apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a) {\r\n    if (idx\
    \ >= len(closed_range)) return;\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\
    \n    if (xmin > xmax) return;\r\n    if (x2 <= xmin || xmax < x1) return;\r\n\
    \    if (y2 <= ymin || ymax < y1) return;\r\n    if (x1 <= xmin && xmax < x2 &&\
    \ y1 <= ymin && ymax < y2) { return apply_at(idx, a); }\r\n    push(idx);\r\n\
    \    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\r\n    apply_rec(2 * idx + 1,\
    \ x1, x2, y1, y2, a);\r\n    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx +\
    \ 1]);\r\n  }\r\n};\r\n#line 2 \"mod/modint_common.hpp\"\n\nstruct has_mod_impl\
    \ {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
    \ std::true_type{});\n  template <class T>\n  static auto check(...) -> std::false_type;\n\
    };\n\ntemplate <class T>\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\n\ntemplate <typename mint>\nmint inv(int n) {\n  static const int mod =\
    \ mint::get_mod();\n  static vector<mint> dat = {0, 1};\n  assert(0 <= n);\n \
    \ if (n >= mod) n %= mod;\n  while (len(dat) <= n) {\n    int k = len(dat);\n\
    \    int q = (mod + k - 1) / k;\n    dat.eb(dat[k * q - mod] * mint::raw(q));\n\
    \  }\n  return dat[n];\n}\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n\
    \ != 0);\n  return 1.0 / n;\n}\n\ntemplate <typename mint>\nmint fact(int n) {\n\
    \  static const int mod = mint::get_mod();\n  assert(0 <= n && n < mod);\n  static\
    \ vector<mint> dat = {1, 1};\n  while (len(dat) <= n) dat.eb(dat[len(dat) - 1]\
    \ * mint(len(dat)));\n  return dat[n];\n}\n\ntemplate <typename mint>\nmint fact_inv(int\
    \ n) {\n  static vector<mint> dat = {1, 1};\n  if (n < 0) return mint(0);\n  while\
    \ (len(dat) <= n) dat.eb(dat[len(dat) - 1] * inv<mint>(len(dat)));\n  return dat[n];\n\
    }\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts... xs) {\n  return\
    \ (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename mint, class Head,\
    \ class... Tail>\nmint multinomial(Head &&head, Tail &&...tail) {\n  return fact<mint>(head)\
    \ * fact_invs<mint>(std::forward<Tail>(tail)...);\n}\n\ntemplate <typename mint>\n\
    mint C_dense(int n, int k) {\n  assert(n >= 0);\n  if (k < 0 || n < k) return\
    \ 0;\n  static vvc<mint> C;\n  static int H = 0, W = 0;\n  auto calc = [&](int\
    \ i, int j) -> mint {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n\
    \    return C[i - 1][j] + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n\
    \    FOR(i, H) {\n      C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j]\
    \ = calc(i, j); }\n    }\n    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n\
    \ + 1);\n    FOR(i, H, n + 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j]\
    \ = calc(i, j); }\n    }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate\
    \ <typename mint, bool large = false, bool dense = false>\nmint C(ll n, ll k)\
    \ {\n  assert(n >= 0);\n  if (k < 0 || n < k) return 0;\n  if constexpr (dense)\
    \ return C_dense<mint>(n, k);\n  if constexpr (!large) return multinomial<mint>(n,\
    \ k, n - k);\n  k = min(k, n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n\
    \  return x * fact_inv<mint>(k);\n}\n\ntemplate <typename mint, bool large = false>\n\
    mint C_inv(ll n, ll k) {\n  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if\
    \ (!large) return fact_inv<mint>(n) * fact<mint>(k) * fact<mint>(n - k);\n  return\
    \ mint(1) / C<mint, 1>(n, k);\n}\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint,\
    \ bool large = false, bool dense = false>\nmint C_negative(ll n, ll d) {\n  assert(n\
    \ >= 0);\n  if (d < 0) return mint(0);\n  if (n == 0) {\n    return (d == 0 ?\
    \ mint(1) : mint(0));\n  }\n  return C<mint, large, dense>(n + d - 1, d);\n}\n\
    #line 3 \"mod/modint.hpp\"\n\ntemplate <int mod>\nstruct modint {\n  static constexpr\
    \ u32 umod = u32(mod);\n  static_assert(umod < u32(1) << 31);\n  u32 val;\n\n\
    \  static modint raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n\
    \  }\n  constexpr modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod)\
    \ {}\n  constexpr modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x)\
    \ : val(x % umod) {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod\
    \ : x){};\n  constexpr modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n \
    \ constexpr modint(i128 x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const\
    \ modint &other) const { return val < other.val; }\n  modint &operator+=(const\
    \ modint &p) {\n    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n\
    \  }\n  modint &operator-=(const modint &p) {\n    if ((val += umod - p.val) >=\
    \ umod) val -= umod;\n    return *this;\n  }\n  modint &operator*=(const modint\
    \ &p) {\n    val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint\
    \ &operator/=(const modint &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  modint operator-() const { return modint::raw(val ? mod - val : u32(0));\
    \ }\n  modint operator+(const modint &p) const { return modint(*this) += p; }\n\
    \  modint operator-(const modint &p) const { return modint(*this) -= p; }\n  modint\
    \ operator*(const modint &p) const { return modint(*this) *= p; }\n  modint operator/(const\
    \ modint &p) const { return modint(*this) /= p; }\n  bool operator==(const modint\
    \ &p) const { return val == p.val; }\n  bool operator!=(const modint &p) const\
    \ { return val != p.val; }\n  modint inverse() const {\n    int a = val, b = mod,\
    \ u = 1, v = 0, t;\n    while (b > 0) {\n      t = a / b;\n      swap(a -= t *\
    \ b, b), swap(u -= t * v, v);\n    }\n    return modint(u);\n  }\n  modint pow(ll\
    \ n) const {\n    if (n < 0) return inverse().pow(-n);\n    assert(n >= 0);\n\
    \    modint ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n\
    \      mul *= mul;\n      n >>= 1;\n    }\n    return ret;\n  }\n  static constexpr\
    \ int get_mod() { return mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\
    \n  static constexpr pair<int, int> ntt_info() {\n    if (mod == 120586241) return\
    \ {20, 74066978};\n    if (mod == 167772161) return {25, 17};\n    if (mod ==\
    \ 469762049) return {26, 30};\n    if (mod == 754974721) return {24, 362};\n \
    \   if (mod == 880803841) return {23, 211};\n    if (mod == 943718401) return\
    \ {22, 663003469};\n    if (mod == 998244353) return {23, 31};\n    if (mod ==\
    \ 1004535809) return {21, 582313106};\n    if (mod == 1012924417) return {21,\
    \ 368093570};\n    if (mod == 1224736769) return {24, 1191450770};\n    if (mod\
    \ == 2013265921) return {27, 244035102};\n    return {-1, -1};\n  }\n  static\
    \ constexpr bool can_ntt() { return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\n\
    template <int mod>\nvoid rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %=\
    \ mod;\n  // assert(0 <= x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod>\
    \ x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing modint107 = modint<1000000007>;\n\
    using modint998 = modint<998244353>;\n#line 2 \"alg/monoid/affine.hpp\"\n\n//\
    \ op(F, G) = comp(G,F), F \u306E\u3042\u3068\u3067 G\ntemplate <typename K>\n\
    struct Monoid_Affine {\n  using F = pair<K, K>;\n  using value_type = F;\n  using\
    \ X = value_type;\n  static constexpr F op(const F &x, const F &y) noexcept {\n\
    \    return F({x.first * y.first, x.second * y.first + y.second});\n  }\n  static\
    \ constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n\
    \    return {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n  static constexpr F unit() { return\
    \ {K(1), K(0)}; }\n  static constexpr bool commute = false;\n};\n#line 2 \"alg/monoid/add_pair.hpp\"\
    \n\r\ntemplate <typename E>\r\nstruct Monoid_Add_Pair {\r\n  using value_type\
    \ = pair<E, E>;\r\n  using X = value_type;\r\n  static constexpr X op(const X\
    \ &x, const X &y) {\r\n    return {x.fi + y.fi, x.se + y.se};\r\n  }\r\n  static\
    \ constexpr X inverse(const X &x) { return {-x.fi, -x.se}; }\r\n  static constexpr\
    \ X unit() { return {0, 0}; }\r\n  static constexpr bool commute = true;\r\n};\r\
    \n#line 9 \"test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp\"\
    \n\nusing mint = modint998;\nstruct ActedMonoid {\n  using Monoid_X = Monoid_Add_Pair<mint>;\n\
    \  using Monoid_A = Monoid_Affine<mint>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static X act(const X &x, const\
    \ A &a, const ll &size) { return {x.fi, a.fi * x.se + a.se * x.fi}; }\n};\n\n\
    void solve() {\n  LL(N, Q);\n  vc<int> X(N), Y(N);\n  vc<pair<mint, mint>> W(N);\n\
    \  FOR(i, N) {\n    INT(x, y, w);\n    X[i] = x, Y[i] = y, W[i] = {1, w};\n  }\n\
    \n  vc<tuple<int, int, int, int, int, int, int>> query;\n  FOR(Q) {\n    INT(t);\n\
    \    if (t == 0) {\n      INT(x, y, w);\n      int k = len(X);\n      X.eb(x),\
    \ Y.eb(y), W.eb(0, 0);\n      query.eb(0, k, w, 0, 0, 0, 0);\n    }\n    if (t\
    \ == 1) {\n      INT(k, w);\n      query.eb(1, k, w, 0, 0, 0, 0);\n    }\n   \
    \ if (t == 2) {\n      INT(a, b, c, d);\n      query.eb(2, a, c, b, d, 0, 0);\n\
    \    }\n    if (t == 3) {\n      INT(a, b, c, d, p, q);\n      query.eb(3, a,\
    \ c, b, d, p, q);\n    }\n  }\n  assert(len(X) == len(Y) && len(X) == len(W));\n\
    \  KDTree_ActedMonoid<ActedMonoid, int> KDT(X, Y, W);\n\n  for (auto &[t, a, b,\
    \ c, d, A, B]: query) {\n    if (t == 0) { KDT.set(a, {1, b}); }\n    if (t ==\
    \ 1) { KDT.set(a, {1, b}); }\n    if (t == 2) {\n      mint ANS = KDT.prod(a,\
    \ b, c, d).se;\n      print(ANS);\n    }\n    if (t == 3) { KDT.apply(a, b, c,\
    \ d, {A, B}); }\n  }\n}\n\nsigned main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_point_set_rectangle_affine_rectangle_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/kdtree/kdtree_acted_monoid.hpp\"\
    \n#include \"mod/modint.hpp\"\n#include \"alg/monoid/affine.hpp\"\n#include \"\
    alg/monoid/add_pair.hpp\"\n\nusing mint = modint998;\nstruct ActedMonoid {\n \
    \ using Monoid_X = Monoid_Add_Pair<mint>;\n  using Monoid_A = Monoid_Affine<mint>;\n\
    \  using X = typename Monoid_X::value_type;\n  using A = typename Monoid_A::value_type;\n\
    \  static X act(const X &x, const A &a, const ll &size) { return {x.fi, a.fi *\
    \ x.se + a.se * x.fi}; }\n};\n\nvoid solve() {\n  LL(N, Q);\n  vc<int> X(N), Y(N);\n\
    \  vc<pair<mint, mint>> W(N);\n  FOR(i, N) {\n    INT(x, y, w);\n    X[i] = x,\
    \ Y[i] = y, W[i] = {1, w};\n  }\n\n  vc<tuple<int, int, int, int, int, int, int>>\
    \ query;\n  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n      INT(x, y, w);\n  \
    \    int k = len(X);\n      X.eb(x), Y.eb(y), W.eb(0, 0);\n      query.eb(0, k,\
    \ w, 0, 0, 0, 0);\n    }\n    if (t == 1) {\n      INT(k, w);\n      query.eb(1,\
    \ k, w, 0, 0, 0, 0);\n    }\n    if (t == 2) {\n      INT(a, b, c, d);\n     \
    \ query.eb(2, a, c, b, d, 0, 0);\n    }\n    if (t == 3) {\n      INT(a, b, c,\
    \ d, p, q);\n      query.eb(3, a, c, b, d, p, q);\n    }\n  }\n  assert(len(X)\
    \ == len(Y) && len(X) == len(W));\n  KDTree_ActedMonoid<ActedMonoid, int> KDT(X,\
    \ Y, W);\n\n  for (auto &[t, a, b, c, d, A, B]: query) {\n    if (t == 0) { KDT.set(a,\
    \ {1, b}); }\n    if (t == 1) { KDT.set(a, {1, b}); }\n    if (t == 2) {\n   \
    \   mint ANS = KDT.prod(a, b, c, d).se;\n      print(ANS);\n    }\n    if (t ==\
    \ 3) { KDT.apply(a, b, c, d, {A, B}); }\n  }\n}\n\nsigned main() { solve(); }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/kdtree/kdtree_acted_monoid.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - alg/monoid/affine.hpp
  - alg/monoid/add_pair.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2025-09-03 07:11:11+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
- /verify/test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp.html
title: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
---
