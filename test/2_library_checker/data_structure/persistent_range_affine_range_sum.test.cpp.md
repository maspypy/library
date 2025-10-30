---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/acted_monoid/sum_affine.hpp
    title: alg/acted_monoid/sum_affine.hpp
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/affine.hpp
    title: alg/monoid/affine.hpp
  - icon: ':question:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
  - icon: ':question:'
    path: ds/segtree/dynamic_lazy_segtree.hpp
    title: ds/segtree/dynamic_lazy_segtree.hpp
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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/persistent_range_affine_range_sum
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/persistent_range_affine_range_sum\"\
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
    \ TIDAK(bool t = 1) { YA(!t); }\r\n#line 6 \"test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp\"\
    \n\n#line 1 \"ds/node_pool.hpp\"\ntemplate <class Node>\nstruct Node_Pool {\n\
    \  struct Slot {\n    union alignas(Node) {\n      Slot* next;\n      unsigned\
    \ char storage[sizeof(Node)];\n    };\n  };\n  using np = Node*;\n\n  static constexpr\
    \ int CHUNK_SIZE = 1 << 16;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur =\
    \ nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool()\
    \ { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&... args)\
    \ {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
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
    \ &cur[cur_used++];\n  }\n};\n#line 3 \"ds/segtree/dynamic_lazy_segtree.hpp\"\n\
    \n// Q*4logN \u7A0B\u5EA6\u5FC5\u8981? apply \u3067 4logN \u30CE\u30FC\u30C9\u4F5C\
    \u3063\u3066\u3044\u308B\u3068\u601D\u3046\ntemplate <typename ActedMonoid, bool\
    \ PERSISTENT>\nstruct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using\
    \ MX = typename AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X\
    \ = typename AM::X;\n  using A = typename AM::A;\n  using F = function<X(ll, ll)>;\n\
    \  F default_prod;\n\n  struct Node {\n    Node *l, *r;\n    X x;\n    A lazy;\n\
    \  };\n\n  Node_Pool<Node> pool;\n  const ll L0, R0;\n  using np = Node *;\n\n\
    \  Dynamic_Lazy_SegTree(\n      ll L0, ll R0, F default_prod = [](ll, ll) -> X\
    \ { return MX::unit(); })\n      : default_prod(default_prod), L0(L0), R0(R0)\
    \ {}\n\n  np new_root() { return new_node(L0, R0); }\n\n  np new_node(const X\
    \ x) {\n    np c = pool.create();\n    c->l = c->r = nullptr;\n    c->x = x, c->lazy\
    \ = MA::unit();\n    return c;\n  }\n\n  np new_node(ll l, ll r) {\n    assert(l\
    \ < r);\n    return new_node(default_prod(l, r));\n  }\n  np new_node() { return\
    \ new_node(L0, R0); }\n\n  np new_node(const vc<X> &dat) {\n    assert(L0 == 0\
    \ && R0 == len(dat));\n    auto dfs = [&](auto &dfs, ll l, ll r) -> Node * {\n\
    \      if (l == r) return nullptr;\n      if (r == l + 1) return new_node(dat[l]);\n\
    \      ll m = (l + r) / 2;\n      np l_root = dfs(dfs, l, m), r_root = dfs(dfs,\
    \ m, r);\n      X x = MX::op(l_root->x, r_root->x);\n      np root = new_node(x);\n\
    \      root->l = l_root, root->r = r_root;\n      return root;\n    };\n    return\
    \ dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np root, ll l, ll r) {\n    if (l ==\
    \ r || !root) return MX::unit();\n    assert(L0 <= l && l < r && r <= R0);\n \
    \   X x = MX::unit();\n    prod_rec(root, L0, R0, l, r, x, MA::unit());\n    return\
    \ x;\n  }\n\n  X prod_all(np root) { return prod(root, L0, R0); }\n\n  np set(np\
    \ root, ll i, const X &x) {\n    assert(root && L0 <= i && i < R0);\n    return\
    \ set_rec(root, L0, R0, i, x);\n  }\n\n  np multiply(np root, ll i, const X &x)\
    \ {\n    assert(root && L0 <= i && i < R0);\n    return multiply_rec(root, L0,\
    \ R0, i, x);\n  }\n\n  np apply(np root, ll l, ll r, const A &a) {\n    if (l\
    \ == r) return root;\n    assert(root && L0 <= l && l < r && r <= R0);\n    return\
    \ apply_rec(root, L0, R0, l, r, a);\n  }\n\n  template <typename F>\n  ll max_right(np\
    \ root, F check, ll L) {\n    assert(root && L0 <= L && L <= R0 && check(MX::unit()));\n\
    \    X x = MX::unit();\n    return max_right_rec(root, check, L0, R0, L, x);\n\
    \  }\n\n  template <typename F>\n  ll min_left(np root, F check, ll R) {\n   \
    \ assert(root && L0 <= R && R <= R0 && check(MX::unit()));\n    X x = MX::unit();\n\
    \    return min_left_rec(root, check, L0, R0, R, x);\n  }\n\n  // f(idx, val)\n\
    \  template <typename F>\n  void enumerate(np root, F f) {\n    auto dfs = [&](auto\
    \ &dfs, np c, ll l, ll r, A a) -> void {\n      if (!c) return;\n      if (r -\
    \ l == 1) {\n        f(l, AM::act(c->x, a, 1));\n        return;\n      }\n  \
    \    ll m = (l + r) / 2;\n      a = MA::op(c->lazy, a);\n      dfs(dfs, c->l,\
    \ l, m, a);\n      dfs(dfs, c->r, m, r, a);\n    };\n    dfs(dfs, root, L0, R0,\
    \ MA::unit());\n  }\n\n  void reset() { pool.reset(); }\n\n  // root[l:r) \u3092\
    \ apply(other[l:r),a) \u3067\u4E0A\u66F8\u304D\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\n  np copy_interval(np root, np other, ll l, ll r, A a) {\n    if (root\
    \ == other) return root;\n    root = clone(root);\n    copy_interval_rec(root,\
    \ other, L0, R0, l, r, a);\n    return root;\n  }\n\n private:\n  np clone(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    return pool.clone(c);\n  }\n\
    \n  void push(np c, ll l, ll r) {\n    assert(r - l >= 2);\n    ll m = (l + r)\
    \ / 2;\n    if (c->lazy == MA::unit()) return;\n    c->l = (c->l ? clone(c->l)\
    \ : new_node(l, m));\n    c->l->x = AM::act(c->l->x, c->lazy, m - l);\n    c->l->lazy\
    \ = MA::op(c->l->lazy, c->lazy);\n    c->r = (c->r ? clone(c->r) : new_node(m,\
    \ r));\n    c->r->x = AM::act(c->r->x, c->lazy, r - m);\n    c->r->lazy = MA::op(c->r->lazy,\
    \ c->lazy);\n    c->lazy = MA::unit();\n  }\n\n  void copy_interval_rec(np c,\
    \ np d, ll l, ll r, ll ql, ll qr, A a) {\n    // c[ql,qr) <- apply(d[ql,qr),a)\n\
    \    // \u3082\u3046 c \u306F\u65B0\u3057\u304F\u3057\u3066\u3042\u308B\n    assert(c);\n\
    \    chmax(ql, l), chmin(qr, r);\n    if (ql >= qr) return;\n    if (l == ql &&\
    \ r == qr) {\n      if (d) {\n        c->x = AM::act(d->x, a, r - l), c->lazy\
    \ = MA::op(d->lazy, a);\n        c->l = d->l, c->r = d->r;\n      } else {\n \
    \       c->x = AM::act(default_prod(l, r), a, r - l), c->lazy = a;\n        c->l\
    \ = nullptr, c->r = nullptr;\n      }\n      return;\n    }\n    // push\n   \
    \ ll m = (l + r) / 2;\n    c->l = (c->l ? clone(c->l) : new_node());\n    c->r\
    \ = (c->r ? clone(c->r) : new_node());\n    c->l->x = AM::act(c->l->x, c->lazy,\
    \ m - l);\n    c->l->lazy = MA::op(c->l->lazy, c->lazy);\n    c->r->x = AM::act(c->r->x,\
    \ c->lazy, r - m);\n    c->r->lazy = MA::op(c->r->lazy, c->lazy);\n    c->lazy\
    \ = MA::unit();\n    if (d) a = MA::op(d->lazy, a);\n    copy_interval_rec(c->l,\
    \ (d && d->l ? d->l : nullptr), l, m, ql, qr, a);\n    copy_interval_rec(c->r,\
    \ (d && d->r ? d->r : nullptr), m, r, ql, qr, a);\n    c->x = MX::op(c->l->x,\
    \ c->r->x);\n    return;\n  }\n\n  np set_rec(np c, ll l, ll r, ll i, const X\
    \ &x) {\n    if (r == l + 1) {\n      c = clone(c);\n      c->x = x;\n      c->lazy\
    \ = MA::unit();\n      return c;\n    }\n    push(c, l, r);\n    ll m = (l + r)\
    \ / 2;\n    if (!c->l) c->l = new_node(l, m);\n    if (!c->r) c->r = new_node(m,\
    \ r);\n\n    c = clone(c);\n    if (i < m) {\n      c->l = set_rec(c->l, l, m,\
    \ i, x);\n    } else {\n      c->r = set_rec(c->r, m, r, i, x);\n    }\n    c->x\
    \ = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\n  np multiply_rec(np c, ll\
    \ l, ll r, ll i, const X &x) {\n    if (r == l + 1) {\n      c = clone(c);\n \
    \     c->x = MX::op(c->x, x);\n      c->lazy = MA::unit();\n      return c;\n\
    \    }\n    push(c, l, r);\n    ll m = (l + r) / 2;\n    if (!c->l) c->l = new_node(l,\
    \ m);\n    if (!c->r) c->r = new_node(m, r);\n\n    c = clone(c);\n    if (i <\
    \ m) {\n      c->l = multiply_rec(c->l, l, m, i, x);\n    } else {\n      c->r\
    \ = multiply_rec(c->r, m, r, i, x);\n    }\n    c->x = MX::op(c->l->x, c->r->x);\n\
    \    return c;\n  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A\
    \ lazy) {\n    chmax(ql, l);\n    chmin(qr, r);\n    if (ql >= qr) return;\n \
    \   if (!c) {\n      x = MX::op(x, AM::act(default_prod(ql, qr), lazy, qr - ql));\n\
    \      return;\n    }\n    if (l == ql && r == qr) {\n      x = MX::op(x, AM::act(c->x,\
    \ lazy, r - l));\n      return;\n    }\n    ll m = (l + r) / 2;\n    lazy = MA::op(c->lazy,\
    \ lazy);\n    prod_rec(c->l, l, m, ql, qr, x, lazy);\n    prod_rec(c->r, m, r,\
    \ ql, qr, x, lazy);\n  }\n\n  np apply_rec(np c, ll l, ll r, ll ql, ll qr, const\
    \ A &a) {\n    if (!c) c = new_node(l, r);\n    chmax(ql, l);\n    chmin(qr, r);\n\
    \    if (ql >= qr) return c;\n    if (l == ql && r == qr) {\n      c = clone(c);\n\
    \      c->x = AM::act(c->x, a, r - l);\n      c->lazy = MA::op(c->lazy, a);\n\
    \      return c;\n    }\n    push(c, l, r);\n    ll m = (l + r) / 2;\n    c =\
    \ clone(c);\n    c->l = apply_rec(c->l, l, m, ql, qr, a);\n    c->r = apply_rec(c->r,\
    \ m, r, ql, qr, a);\n    c->x = MX::op(c->l->x, c->r->x);\n    return c;\n  }\n\
    \n  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l, ll r,\
    \ ll ql, X &x) {\n    if (r <= ql) return r;\n    if (!c) c = new_node(l, r);\n\
    \    chmax(ql, l);\n    if (l == ql && check(MX::op(x, c->x))) {\n      x = MX::op(x,\
    \ c->x);\n      return r;\n    }\n    if (r == l + 1) return l;\n    push(c, l,\
    \ r);\n    ll m = (l + r) / 2;\n    ll k = max_right_rec(c->l, check, l, m, ql,\
    \ x);\n    if (k < m) return k;\n    return max_right_rec(c->r, check, m, r, ql,\
    \ x);\n  }\n\n  template <typename F>\n  ll min_left_rec(np c, const F &check,\
    \ ll l, ll r, ll qr, X &x) {\n    if (qr <= l) return l;\n    if (!c) c = new_node(l,\
    \ r);\n    chmin(qr, r);\n    if (r == qr && check(MX::op(c->x, x))) {\n     \
    \ x = MX::op(c->x, x);\n      return l;\n    }\n    if (r == l + 1) return r;\n\
    \    push(c, l, r);\n    ll m = (l + r) / 2;\n    ll k = min_left_rec(c->r, check,\
    \ m, r, qr, x);\n    if (m < k) return k;\n    return min_left_rec(c->l, check,\
    \ l, m, qr, x);\n  }\n};\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename\
    \ E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n \
    \ static constexpr X op(const X &x, const X &y) noexcept { return x + y; }\r\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\r\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\r\n  static\
    \ constexpr X unit() { return X(0); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 2 \"alg/monoid/affine.hpp\"\n\n// op(F, G) = comp(G,F), F \u306E\
    \u3042\u3068\u3067 G\ntemplate <typename K>\nstruct Monoid_Affine {\n  using F\
    \ = pair<K, K>;\n  using value_type = F;\n  using X = value_type;\n  static constexpr\
    \ F op(const F &x, const F &y) noexcept {\n    return F({x.first * y.first, x.second\
    \ * y.first + y.second});\n  }\n  static constexpr F inverse(const F &x) {\n \
    \   auto [a, b] = x;\n    a = K(1) / a;\n    return {a, a * (-b)};\n  }\n  static\
    \ constexpr K eval(const F &f, K x) noexcept {\n    return f.first * x + f.second;\n\
    \  }\n  static constexpr F unit() { return {K(1), K(0)}; }\n  static constexpr\
    \ bool commute = false;\n};\n#line 3 \"alg/acted_monoid/sum_affine.hpp\"\n\r\n\
    template <typename E>\r\nstruct ActedMonoid_Sum_Affine {\r\n  using Monoid_X =\
    \ Monoid_Add<E>;\r\n  using Monoid_A = Monoid_Affine<E>;\r\n  using X = typename\
    \ Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\n  static\
    \ constexpr X act(const X &x, const A &a, const ll &size) {\r\n    return x *\
    \ a.fi + E(size) * a.se;\r\n  }\r\n};\r\n#line 2 \"mod/modint_common.hpp\"\n\n\
    struct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) -> decltype(x.get_mod(),\
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
    using modint998 = modint<998244353>;\n#line 10 \"test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp\"\
    \n\nusing mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  VEC(mint, A, N);\n\
    \  using AM = ActedMonoid_Sum_Affine<mint>;\n  Dynamic_Lazy_SegTree<AM, true>\
    \ seg(0, N);\n  using np = decltype(seg)::np;\n  vc<np> root(Q + 1);\n  root[0]\
    \ = seg.new_node(A);\n\n  FOR(q, 1, Q + 1) {\n    INT(t);\n    if (t == 0) {\n\
    \      INT(k, L, R, b, c);\n      ++k;\n      root[q] = seg.apply(root[k], L,\
    \ R, {mint(b), mint(c)});\n    }\n    if (t == 1) {\n      INT(k, s, l, r);\n\
    \      ++k, ++s;\n      root[q] = seg.copy_interval(root[k], root[s], l, r, {mint(1),\
    \ mint(0)});\n    }\n    if (t == 2) {\n      INT(k, l, r);\n      ++k;\n    \
    \  root[q] = root[k];\n      mint ANS = seg.prod(root[q], l, r);\n      print(ANS);\n\
    \    }\n  }\n}\n\nsigned main() { solve(); }\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/persistent_range_affine_range_sum\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/segtree/dynamic_lazy_segtree.hpp\"\
    \n#include \"alg/acted_monoid/sum_affine.hpp\"\n#include \"mod/modint.hpp\"\n\n\
    using mint = modint998;\n\nvoid solve() {\n  LL(N, Q);\n  VEC(mint, A, N);\n \
    \ using AM = ActedMonoid_Sum_Affine<mint>;\n  Dynamic_Lazy_SegTree<AM, true> seg(0,\
    \ N);\n  using np = decltype(seg)::np;\n  vc<np> root(Q + 1);\n  root[0] = seg.new_node(A);\n\
    \n  FOR(q, 1, Q + 1) {\n    INT(t);\n    if (t == 0) {\n      INT(k, L, R, b,\
    \ c);\n      ++k;\n      root[q] = seg.apply(root[k], L, R, {mint(b), mint(c)});\n\
    \    }\n    if (t == 1) {\n      INT(k, s, l, r);\n      ++k, ++s;\n      root[q]\
    \ = seg.copy_interval(root[k], root[s], l, r, {mint(1), mint(0)});\n    }\n  \
    \  if (t == 2) {\n      INT(k, l, r);\n      ++k;\n      root[q] = root[k];\n\
    \      mint ANS = seg.prod(root[q], l, r);\n      print(ANS);\n    }\n  }\n}\n\
    \nsigned main() { solve(); }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree/dynamic_lazy_segtree.hpp
  - ds/node_pool.hpp
  - alg/acted_monoid/sum_affine.hpp
  - alg/monoid/add.hpp
  - alg/monoid/affine.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2025-10-30 08:59:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
- /verify/test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp.html
title: test/2_library_checker/data_structure/persistent_range_affine_range_sum.test.cpp
---
