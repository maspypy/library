---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/ds/lct_node_monoid.hpp
    title: graph/ds/lct_node_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/link_cut_tree.hpp
    title: graph/ds/link_cut_tree.hpp
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
    links: []
  bundledCode: "#line 1 \"test/5_ai_generated_test/link_cut_tree_ordered_prefix.test.cpp\"\
    \n// TST-0026: link/cut \u3092\u631F\u3093\u3060\u68EE\u6797\u4E0A\u306E\u975E\
    \u53EF\u63DB\u306A\u7D4C\u8DEF prefix \u63A2\u7D22\u3002\n// \u96A3\u63A5\u884C\
    \u5217\u304B\u3089 BFS \u3067\u552F\u4E00\u306E\u7D4C\u8DEF\u3092\u5FA9\u5143\u3057\
    \u3001\u9802\u70B9\u30E9\u30D9\u30EB\u3092\u9806\u756A\u306B\u9023\u7D50\u3059\
    \u308B\u3002\n// check \u306F\u300C\u76EE\u6A19\u6587\u5B57\u5217\u306E prefix\
    \ \u304B\u3064\u9577\u3055\u4E0A\u9650\u4EE5\u4E0B\u300D\u3002\u5EF6\u9577\u3067\
    \ false \u304B\u3089 true\n// \u306B\u306F\u623B\u3089\u306A\u3044\u3002\u6700\
    \u521D\u306E\u9802\u70B9\u3067\u5931\u6557\u30FB\u4E2D\u9014\u306E\u6587\u5B57\
    \u4E0D\u4E00\u81F4\u30FB\u5168\u7D4C\u8DEF\u6210\u529F\u3092\u4E21\u65B9\u5411\
    \u3067\u78BA\u8A8D\u3002\n// evert \u3092\u631F\u307E\u305A\u6839\u3068\u89AA\u3092\
    \u7167\u5408\u3057\u3001\u63A2\u7D22\u3084 link/cut \u306E\u6839\u306B\u5BFE\u3059\
    \u308B\u526F\u4F5C\u7528\u3082\u78BA\u8A8D\u3059\u308B\u3002\n#line 1 \"my_template.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n#if\
    \ defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\n#if defined(__GNUC__)\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n#if !defined(MASPY_NON_AVX2)\n#pragma\
    \ GCC target(\"avx2,popcnt\")\n#endif\n#endif\n\n#else  // MASPY_TEMPLATE_BODY\n\
    #include <bits/stdc++.h>\n#include <cassert>\n\n#if defined(__GNUC__)\n#pragma\
    \ GCC optimize(\"Ofast,unroll-loops\")\n#endif\n\nusing namespace std;\n\nusing\
    \ ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\n\
    using u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\n\
    using f128 = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false =\
    \ false;\n\ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 4'040'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 4'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<i128>;\ntemplate <>\nconstexpr long double infty<long double> = infty<i128>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing pq_max = priority_queue<T>;\ntemplate <class T>\nusing\
    \ pq_min = priority_queue<T, vector<T>, greater<T>>;\n\n#define vv(type, name,\
    \ h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n#define\
    \ vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name( \\\n \
    \     h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR1_R(a)\
    \ for (ll i = ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a)\
    \ - 1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a);\
    \ --i)\n#define overload3(a, b, c, d, ...) d\n#define FOR(...) overload3(__VA_ARGS__,\
    \ FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define FOR_R(...) overload3(__VA_ARGS__, FOR3_R,\
    \ FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define all(x) (x).begin(), (x).end()\n#define\
    \ len(x) ll(x.size())\n#define elif else if\n\n#define eb emplace_back\n#define\
    \ mp make_pair\n#define mt make_tuple\n#define fi first\n#define se second\n\n\
    #define stoi stoll\n\n// require y > 0\ntemplate <typename T>\nT floor(T x, T\
    \ y) {\n  return x / y - (x % y < 0);\n}\n\n// require y > 0\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return (x / y) + (x % y > 0);\n}\n\n// require y >\
    \ 0\ntemplate <typename T>\nT bmod(T x, T y) {\n  T r = x % y;\n  return (r <\
    \ 0 ? r + y : r);\n}\n\n// require y > 0\ntemplate <typename T>\npair<T, T> divmod(T\
    \ x, T y) {\n  T q = x / y, r = x % y;\n  if (r < 0) --q, r += y;\n  return {q,\
    \ r};\n}\n\nconstexpr auto TEN = [] {\n  array<u64, 20> A{};\n  A[0] = 1;\n  for\
    \ (int i = 1; i < 20; ++i) A[i] = 10 * A[i - 1];\n  return A;\n}();\n\ntemplate\
    \ <typename T, typename U>\nT SUM(const U &A) {\n  return std::accumulate(A.begin(),\
    \ A.end(), T{});\n}\n\n#define MIN(v) *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n\
    template <class C, class T>\ninline long long LB(const C &c, const T &x) {\n \
    \ return lower_bound(c.begin(), c.end(), x) - c.begin();\n}\ntemplate <class C,\
    \ class T>\ninline long long UB(const C &c, const T &x) {\n  return upper_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end())\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n\
    \  que.pop_front();\n  return a;\n}\ntemplate <class T, class Container, class\
    \ Compare>\nT POP(priority_queue<T, Container, Compare> &que) {\n  T a = que.top();\n\
    \  que.pop();\n  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T\
    \ a = que.back();\n  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\n\
    i128 binary_search(F check, i128 ok, i128 ng, bool check_ok = true) {\n  if (check_ok)\
    \ assert(check(ok));\n  while (1) {\n    i128 x = (ok + ng) / 2;\n    if (x ==\
    \ ok || x == ng) break;\n    (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\
    \ntemplate <typename F>\ndouble binary_search_real(F check, double ok, double\
    \ ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\ntemplate <class T, class\
    \ S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a, b);\n  bool changed\
    \ = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n  bool changed = (c !=\
    \ a);\n  a = c;\n  return changed;\n}\n\n// bit operations\nint popcnt(int x)\
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
    T kth_bit(int k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1)\
    \ << k;\n}\ntemplate <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0\
    \ <= k && k < int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename\
    \ T>\nstruct all_bit {\n  static_assert(is_integral<T>::value);\n  T s;\n  all_bit(T\
    \ s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s;\n    int operator*()\
    \ const { return lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool\
    \ operator!=(nullptr_t) const { return s; }\n  };\n  iter begin() const { return\
    \ {s}; }\n  nullptr_t end() const { return nullptr; }\n};\n\ntemplate <typename\
    \ T>\nstruct all_subset {\n  static_assert(is_integral<T>::value);\n  T s;\n \
    \ all_subset(T s) : s(s) { assert(s >= 0); }\n  struct iter {\n    T s, t;\n \
    \   bool done = false;\n    T operator*() const { return t; }\n    void operator++()\
    \ {\n      done = (t == 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t)\
    \ const { return !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0\
    \ <= n && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n\n// ? \u306F -1\nvc<int> s_to_vi(const\
    \ string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i, S.size()) {\
    \ A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n}\n\ntemplate\
    \ <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int off = 1) {\n  int\
    \ N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n\
    \  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable sort\ntemplate\
    \ <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n      [&](int i, int j) { return (A[i] == A[j] ? i <\
    \ j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  vc<T> B(len(I));\n\
    \  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\ntemplate <typename T, typename...\
    \ Vectors>\nvoid concat(vc<T> &first, const Vectors &...others) {\n  first.reserve(first.size()\
    \ + (others.size() + ... + 0));\n  (first.insert(first.end(), others.begin(),\
    \ others.end()), ...);\n}\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T,\
    \ i128>, int> = 0>\nconstexpr i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\n\
    constexpr i128 gcd(i128 a, i128 b) {\n  while (b != 0) {\n    i128 c = a % b;\n\
    \    a = b, b = c;\n  }\n  return abs(a);\n}\n#endif  // MASPY_TEMPLATE_BODY\n\
    #line 1 \"other/io.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/other/io.hpp\n\
    #define FASTIO\n\n// https://judge.yosupo.jp/submission/21623\nnamespace fastio\
    \ {\nstatic constexpr uint32_t SZ = 1 << 17;\nchar ibuf[SZ];\nchar obuf[SZ];\n\
    char out[100];\n// pointer of ibuf, obuf\nuint32_t pil = 0, pir = 0, por = 0;\n\
    bool input_eof = false;\n\ntemplate <class T>\nconstexpr bool is_signed_integer_v\
    \ = is_signed_v<T> || is_same_v<T, i128>;\n\ntemplate <class T>\nstruct unsigned_integer\
    \ {\n  using type = make_unsigned_t<T>;\n};\ntemplate <>\nstruct unsigned_integer<i128>\
    \ {\n  using type = u128;\n};\ntemplate <>\nstruct unsigned_integer<u128> {\n\
    \  using type = u128;\n};\ntemplate <class T>\nusing unsigned_integer_t = typename\
    \ unsigned_integer<T>::type;\n\n[[noreturn]] inline void input_error(const char\
    \ *message) {\n  fputs(message, stderr);\n  fputc('\\n', stderr);\n  exit(EXIT_FAILURE);\n\
    }\n\nstruct Pre {\n  char num[10000][4];\n  constexpr Pre() : num() {\n    for\
    \ (int i = 0; i < 10000; i++) {\n      int n = i;\n      for (int j = 3; j >=\
    \ 0; j--) {\n        num[i][j] = n % 10 | '0';\n        n /= 10;\n      }\n  \
    \  }\n  }\n} constexpr pre;\n\ninline void load() {\n  uint32_t n = pir - pil;\n\
    \  memmove(ibuf, ibuf + pil, n);\n  pil = 0;\n  pir = n;\n  if (input_eof) return;\n\
    \n  pir += fread(ibuf + pir, 1, SZ - pir, stdin);\n  if (ferror(stdin)) input_error(\"\
    fastio: input error\");\n  if (feof(stdin)) {\n    input_eof = true;\n    // Allows\
    \ the last token to end exactly at EOF without a trailing\n    // whitespace.\n\
    \    if (pir < SZ) ibuf[pir++] = '\\n';\n  }\n}\n\ninline char get_char() {\n\
    \  if (pil == pir) {\n    load();\n    if (pil == pir) input_error(\"fastio: unexpected\
    \ EOF\");\n  }\n  return ibuf[pil++];\n}\n\ninline void flush() {\n  fwrite(obuf,\
    \ 1, por, stdout);\n  por = 0;\n}\n\nvoid rd(char &c) {\n  do c = get_char();\n\
    \  while (isspace(static_cast<unsigned char>(c)));\n}\n\nvoid rd(string &x) {\n\
    \  x.clear();\n  char c;\n  do c = get_char();\n  while (isspace(static_cast<unsigned\
    \ char>(c)));\n  do {\n    x += c;\n    c = get_char();\n  } while (!isspace(static_cast<unsigned\
    \ char>(c)));\n}\n\ntemplate <typename T>\nvoid rd_real(T &x) {\n  string s;\n\
    \  rd(s);\n  x = stod(s);\n}\n\ntemplate <typename T>\nvoid rd_integer_slow(T\
    \ &x) {\n  char c;\n  do c = get_char();\n  while (c < '-');\n  bool minus = 0;\n\
    \  if constexpr (is_signed_integer_v<T>) {\n    if (c == '-') {\n      minus =\
    \ 1, c = get_char();\n    }\n  }\n  x = 0;\n  assert('0' <= c && c <= '9');\n\
    \  while ('0' <= c && c <= '9') {\n    x = x * 10 + (c & 15), c = get_char();\n\
    \  }\n  assert(isspace(static_cast<unsigned char>(c)));\n  if constexpr (is_signed_integer_v<T>)\
    \ {\n    if (minus) x = -x;\n  }\n}\n\ntemplate <typename T>\nvoid rd_integer(T\
    \ &x) {\n  if (pil + 100 > pir) {\n    load();\n    if (pil + 100 > pir) {\n \
    \     rd_integer_slow(x);\n      return;\n    }\n  }\n  char c;\n  do c = ibuf[pil++];\n\
    \  while (c < '-');\n  bool minus = 0;\n  if constexpr (is_signed_integer_v<T>)\
    \ {\n    if (c == '-') {\n      minus = 1, c = ibuf[pil++];\n    }\n  }\n  x =\
    \ 0;\n  assert('0' <= c && c <= '9');\n  while ('0' <= c && c <= '9') {\n    x\
    \ = x * 10 + (c & 15), c = ibuf[pil++];\n  }\n  assert(isspace(static_cast<unsigned\
    \ char>(c)));\n  if constexpr (is_signed_integer_v<T>) {\n    if (minus) x = -x;\n\
    \  }\n}\n\ntemplate <class T>\nenable_if_t<is_integral_v<T> || is_same_v<T, i128>\
    \ || is_same_v<T, u128>> rd(\n    T &x) {\n  rd_integer(x);\n}\n\ntemplate <class\
    \ T>\nenable_if_t<is_floating_point_v<T> || is_same_v<T, f128>> rd(T &x) {\n \
    \ rd_real(x);\n}\n\ntemplate <class T, class U>\nvoid rd(pair<T, U> &p) {\n  rd(p.first),\
    \ rd(p.second);\n}\ntemplate <size_t N = 0, typename T>\nvoid rd_tuple(T &t) {\n\
    \  if constexpr (N < tuple_size<T>::value) {\n    auto &x = get<N>(t);\n    rd(x);\n\
    \    rd_tuple<N + 1>(t);\n  }\n}\ntemplate <class... T>\nvoid rd(tuple<T...> &tpl)\
    \ {\n  rd_tuple(tpl);\n}\n\ntemplate <class T, size_t N>\nvoid rd(array<T, N>\
    \ &x) {\n  for (auto &d : x) rd(d);\n}\ntemplate <class T>\nvoid rd(vc<T> &x)\
    \ {\n  for (auto &d : x) rd(d);\n}\n\ntemplate <class... T>\nvoid read(T &...x)\
    \ {\n  (rd(x), ...);\n}\n\ninline void wt_range(const char *s, size_t n) {\n \
    \ size_t i = 0;\n  while (i < n) {\n    if (por == SZ) flush();\n    size_t chunk\
    \ = min(n - i, (size_t)(SZ - por));\n    memcpy(obuf + por, s + i, chunk);\n \
    \   por += chunk;\n    i += chunk;\n  }\n}\n\nvoid wt(const char c) {\n  if (por\
    \ == SZ) flush();\n  obuf[por++] = c;\n}\nvoid wt(const char *s) { wt_range(s,\
    \ strlen(s)); }\nvoid wt(const string &s) { wt_range(s.data(), s.size()); }\n\n\
    template <typename T>\nvoid wt_integer(T x) {\n  if (por > SZ - 100) flush();\n\
    \  using U = unsigned_integer_t<T>;\n  U y = static_cast<U>(x);\n  if constexpr\
    \ (is_signed_integer_v<T>) {\n    if (x < 0) {\n      obuf[por++] = '-';\n   \
    \   y = U(0) - y;\n    }\n  }\n  int outi;\n  for (outi = 96; y >= 10000; outi\
    \ -= 4) {\n    memcpy(out + outi, pre.num[y % 10000], 4);\n    y /= 10000;\n \
    \ }\n  if (y >= 1000) {\n    memcpy(obuf + por, pre.num[y], 4);\n    por += 4;\n\
    \  } else if (y >= 100) {\n    memcpy(obuf + por, pre.num[y] + 1, 3);\n    por\
    \ += 3;\n  } else if (y >= 10) {\n    int q = (y * 103) >> 10;\n    obuf[por]\
    \ = q | '0';\n    obuf[por + 1] = (y - q * 10) | '0';\n    por += 2;\n  } else\n\
    \    obuf[por++] = y | '0';\n  memcpy(obuf + por, out + outi + 4, 96 - outi);\n\
    \  por += 96 - outi;\n}\n\ntemplate <typename T>\ninline void wt_real(T x) {\n\
    \  static char buf[1000];\n  int n = std::snprintf(buf, sizeof(buf), \"%.15f\"\
    , (double)x);\n  wt_range(buf, (size_t)n);\n}\n\ntemplate <class T>\nenable_if_t<is_integral_v<T>\
    \ || is_same_v<T, i128> || is_same_v<T, u128>> wt(\n    T x) {\n  wt_integer(x);\n\
    }\n\ntemplate <class T>\nenable_if_t<is_floating_point_v<T> || is_same_v<T, f128>>\
    \ wt(T x) {\n  wt_real(x);\n}\n\ninline void wt(bool b) { wt(static_cast<char>('0'\
    \ + (b ? 1 : 0))); }\n\ntemplate <class T, class U>\nvoid wt(const pair<T, U>\
    \ &val) {\n  wt(val.first);\n  wt(' ');\n  wt(val.second);\n}\ntemplate <size_t\
    \ N = 0, typename T>\nvoid wt_tuple(const T &t) {\n  if constexpr (N < tuple_size<T>::value)\
    \ {\n    if constexpr (N > 0) wt(' ');\n    wt(get<N>(t));\n    wt_tuple<N + 1>(t);\n\
    \  }\n}\ntemplate <class... T>\nvoid wt(const tuple<T...> &tpl) {\n  wt_tuple(tpl);\n\
    }\ntemplate <class T, size_t S>\nvoid wt(const array<T, S> &val) {\n  auto n =\
    \ val.size();\n  for (size_t i = 0; i < n; i++) {\n    if (i) wt(' ');\n    wt(val[i]);\n\
    \  }\n}\ntemplate <class T>\nvoid wt(const vector<T> &val) {\n  auto n = val.size();\n\
    \  for (size_t i = 0; i < n; i++) {\n    if (i) wt(' ');\n    wt(val[i]);\n  }\n\
    }\n\nvoid print() { wt('\\n'); }\ntemplate <class Head, class... Tail>\nvoid print(Head\
    \ &&head, Tail &&...tail) {\n  wt(forward<Head>(head));\n  ((wt(' '), wt(forward<Tail>(tail))),\
    \ ...);\n  wt('\\n');\n}\n\n// gcc expansion. called automaticall after main.\n\
    void __attribute__((destructor)) _d() { flush(); }\n}  // namespace fastio\nusing\
    \ fastio::flush;\nusing fastio::print;\nusing fastio::read;\n\n#if defined(LOCAL)\n\
    #define HDR \"[DEBUG:\", __func__, __LINE__, \"]\"\n#define SHOW(...)        \
    \                                                 \\\n  SHOW_IMPL(__VA_ARGS__,\
    \ SHOW8, SHOW7, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2, \\\n            SHOW1)    \
    \                                                    \\\n  (__VA_ARGS__)\n#define\
    \ SHOW_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME\n#define SHOW1(x)\
    \ print(HDR, #x, \"=\", (x)), flush()\n#define SHOW2(x, y) print(HDR, #x, \"=\"\
    , (x), #y, \"=\", (y)), flush()\n#define SHOW3(x, y, z) \\\n  print(HDR, #x, \"\
    =\", (x), #y, \"=\", (y), #z, \"=\", (z)), flush()\n#define SHOW4(x, y, z, w)\
    \ \\\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\",\
    \ (w)), flush()\n#define SHOW5(x, y, z, w, v)                                \
    \                  \\\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\"\
    , (z), #w, \"=\", (w), #v, \"=\", \\\n        (v)),                          \
    \                                       \\\n      flush()\n#define SHOW6(x, y,\
    \ z, w, v, u)                                               \\\n  print(HDR, #x,\
    \ \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\n\
    \        (v), #u, \"=\", (u)),                                               \
    \    \\\n      flush()\n#define SHOW7(x, y, z, w, v, u, t)                   \
    \                         \\\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z,\
    \ \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\n        (v), #u, \"=\", (u), #t,\
    \ \"=\", (t)),                                     \\\n      flush()\n#define\
    \ SHOW8(x, y, z, w, v, u, t, s)                                         \\\n \
    \ print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w), #v,\
    \ \"=\", \\\n        (v), #u, \"=\", (u), #t, \"=\", (t), #s, \"=\", (s)),   \
    \                    \\\n      flush()\n#else\n#define SHOW(...)\n#endif\n\n#define\
    \ INT(...)   \\\n  int __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define LL(...) \
    \  \\\n  ll __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define U32(...)   \\\n  u32\
    \ __VA_ARGS__; \\\n  read(__VA_ARGS__)\n#define U64(...)   \\\n  u64 __VA_ARGS__;\
    \ \\\n  read(__VA_ARGS__)\n#define STR(...)      \\\n  string __VA_ARGS__; \\\n\
    \  read(__VA_ARGS__)\n#define CHAR(...)   \\\n  char __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\
    #define DBL(...)      \\\n  double __VA_ARGS__; \\\n  read(__VA_ARGS__)\n\n#define\
    \ VEC(type, name, size) \\\n  vector<type> name(size);    \\\n  read(name)\n#define\
    \ VV(type, name, h, w)                     \\\n  vector<vector<type>> name(h,\
    \ vector<type>(w)); \\\n  read(name)\n\nvoid YES(bool t = 1) { print(t ? \"YES\"\
    \ : \"NO\"); }\nvoid NO(bool t = 1) { YES(!t); }\nvoid Yes(bool t = 1) { print(t\
    \ ? \"Yes\" : \"No\"); }\nvoid No(bool t = 1) { Yes(!t); }\nvoid yes(bool t =\
    \ 1) { print(t ? \"yes\" : \"no\"); }\nvoid no(bool t = 1) { yes(!t); }\nvoid\
    \ YA(bool t = 1) { print(t ? \"YA\" : \"TIDAK\"); }\nvoid TIDAK(bool t = 1) {\
    \ YA(!t); }\nvoid Alice(bool t = 1) { print(t ? \"Alice\" : \"Bob\"); }\nvoid\
    \ Bob(bool t = 1) { Alice(!t); }\n#line 1 \"graph/ds/link_cut_tree.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/graph/ds/link_cut_tree.hpp\n/*\n\
    \u5404 heavy path \u3092 head \u304C\u5DE6, tail \u304C\u53F3\u3068\u306A\u308B\
    \u3088\u3046\u306B splay tree \u3067\u6301\u3064.\n\u30E6\u30FC\u30B6\u30FC\u304C\
    \u76F4\u63A5\u547C\u3076\u53EF\u80FD\u6027\u304C\u3042\u308B\u3082\u306E\u3060\
    \u3051 int \u3067\u3082\u5B9F\u88C5.\nLCT \u5916\u3067\u63A2\u7D22\u3059\u308B\
    \u3068\u304D\u306A\u3069\uFF0Cpush \u3092\u5FD8\u308C\u306A\u3044\u3088\u3046\u306B\
    \u6CE8\u610F.\n*/\n\ntemplate <typename Node>\nstruct Link_Cut_Tree {\n  using\
    \ np = Node *;\n  int n;\n  vc<Node> nodes;\n\n  Link_Cut_Tree(int n = 0) : n(n),\
    \ nodes(n) { FOR(i, n) nodes[i] = Node(i); }\n\n  Node *operator[](int v) { return\
    \ &nodes[v]; }\n\n  // underlying tree \u306E\u6839\n  Node *get_root(Node *c)\
    \ {\n    expose(c);\n    c->push();\n    while (c->l) {\n      c = c->l;\n   \
    \   c->push();\n    }\n    splay(c);\n    return c;\n  }\n\n  // underlying tree\
    \ \u306E\u6839\n  int get_root(int c) { return get_root(&nodes[c])->idx; }\n\n\
    \  // parent(c)==p \u3068\u306A\u308B\u3088\u3046\u306B link. p \u306E\u6839\u306F\
    \u5909\u308F\u3089\u306A\u3044.\n  void link(Node *p, Node *c) {\n    evert(c);\n\
    \    expose(p);\n    p->push();\n    // no edge -> heavy edge\n    assert(!(c->p));\n\
    \    assert(!(p->r));\n    c->p = p;\n    p->r = c;\n    p->update();\n  }\n\n\
    \  // parent(c)==p \u3068\u306A\u308B\u3088\u3046\u306B link. p \u306E\u6839\u306F\
    \u5909\u308F\u3089\u306A\u3044.\n  void link(int p, int c) { return link(&nodes[p],\
    \ &nodes[c]); }\n\n  // a,b \u304C\u6839\u306B\u5909\u66F4\u3055\u308C\u308B\n\
    \  void cut(Node *a, Node *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n\
    \    assert((b->l) == a);\n    // heavy edge -> no edge\n    b->l->p = nullptr;\n\
    \    b->l = nullptr;\n    b->update();\n  }\n\n  // a,b \u304C\u6839\u306B\u5909\
    \u66F4\u3055\u308C\u308B\n  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]);\
    \ }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\u3059\u308B.\n  // c \u306F\
    \ splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n  // c \u306F push \u6E08\u306B\
    \u306A\u308B\n  void evert(Node *c) {\n    expose(c);\n    c->reverse();\n   \
    \ c->push();\n  }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\u3059\u308B\
    .\n  // c \u306F splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n  void evert(int\
    \ c) { evert(&nodes[c]); }\n\n  // \u6839\u306F\u5909\u3048\u306A\u3044\n  Node\
    \ *LCA(Node *u, Node *v) {\n    assert(get_root(u) == get_root(v));\n    expose(u);\n\
    \    return expose(v);\n  }\n\n  // \u6839\u306F\u5909\u3048\u306A\u3044\n  int\
    \ LCA(int u, int v) { return LCA(&nodes[u], &nodes[v])->idx; }\n\n  // \u8FBA\u306E\
    \u500B\u6570. \u6839\u306F\u5909\u3048\u306A\u3044.\n  int dist(int u, int v)\
    \ {\n    int w = LCA(u, v);\n    return depth(u) + depth(v) - 2 * depth(w);\n\
    \  }\n\n  // \u6839\u3092\u5909\u3048\u306A\u3044.\n  int depth(int v) {\n   \
    \ expose(v);\n    return ((*this)[v]->size) - 1;\n  }\n\n  // \u6839\u3092\u5909\
    \u3048\u308B.\n  Node *jump(Node *u, Node *v, int k) {\n    evert(v);\n    expose(u);\n\
    \    assert(0 <= k && k < (u->size));\n    while (1) {\n      u->push();\n   \
    \   int rs = (u->r ? u->r->size : 0);\n      if (k < rs) {\n        u = u->r;\n\
    \        continue;\n      }\n      if (k == rs) {\n        break;\n      }\n \
    \     k -= rs + 1;\n      u = u->l;\n    }\n    splay(u);\n    return u;\n  }\n\
    \n  // \u6839\u3092\u5909\u3048\u308B.\n  int jump(int u, int v, int k) {\n  \
    \  auto c = jump((*this)[u], (*this)[v], k);\n    return c->idx;\n  }\n\n  //\
    \ [root, c] \u304C\u3072\u3068\u3064\u306E splay tree \u306B\u306A\u308B\u3088\
    \u3046\u306B\u5909\u66F4\u3059\u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree\
    \ \u306E\u6839\u3068\u3044\u3046\u72B6\u614B\u306B\u306A\u308B.\n  // path query\
    \ \u306F\u3053\u306E\u72B6\u614B\u3067 c \u306E data \u3092\u898B\u308B.\n  //\
    \ c \u306F push \u6E08\u306B\u306A\u308B\n  virtual Node *expose(Node *c) {\n\
    \    Node *now = c;\n    Node *rp = nullptr;  // \u4ECA\u307E\u3067\u4F5C\u3063\
    \u305F\u30D1\u30B9\n    while (now) {\n      splay(now);\n      // heavy -> light,\
    \ light -> heavy.\n      if (now->r) {\n        now->add_light(now->r);\n    \
    \  }\n      if (rp) {\n        now->erase_light(rp);\n      }\n      now->r =\
    \ rp;\n      now->update();\n      rp = now;\n      now = now->p;\n    }\n   \
    \ splay(c);\n    return rp;\n  }\n\n  // [root, c] \u304C\u3072\u3068\u3064\u306E\
    \ splay tree \u306B\u306A\u308B\u3088\u3046\u306B\u5909\u66F4\u3059\u308B.\n \
    \ // c \u304C\u53F3\u7AEF\u3067 splay tree \u306E\u6839\u3068\u3044\u3046\u72B6\
    \u614B\u306B\u306A\u308B.\n  // path query \u306F\u3053\u306E\u72B6\u614B\u3067\
    \ c \u306E data \u3092\u898B\u308B.\n  int expose(int c) {\n    Node *x = expose(&nodes[c]);\n\
    \    if (!x) return -1;\n    return x->idx;\n  }\n\n  // \u6839\u3092\u5909\u3048\
    \u306A\u3044.\n  Node *get_parent(Node *x) {\n    expose(x);\n    x->push();\n\
    \    if (!x->l) return nullptr;\n    x = x->l, x->push();\n    while (x->r) x\
    \ = x->r, x->push();\n    return x;\n  }\n\n  // \u6839\u3092\u5909\u3048\u306A\
    \u3044.\n  int get_parent(int x) {\n    Node *p = get_parent((*this)[x]);\n  \
    \  return (p ? p->idx : -1);\n  }\n\n  // \u6839\u3092\u5909\u3048\u308B.\n  void\
    \ set(Node *c, typename Node::VX x) {\n    evert(c);\n    c->set(x);\n  }\n\n\
    \  // \u6839\u3092\u5909\u3048\u308B.\n  void set(int c, typename Node::VX x)\
    \ { set((*this)[c], x); }\n\n  // \u6839\u3092\u5909\u3048\u308B.\n  typename\
    \ Node::X prod_path(int a, int b) {\n    evert(a), expose(b);\n    return (*this)[b]->x;\n\
    \  }\n\n  // \u6839\u3092\u5909\u3048\u308B.\n  // subtree \u7528\u306E node \u3092\
    \u4F7F\u3046\n  typename Node::X prod_subtree(int v, int root) {\n    static_assert(Node::NODE_FOR_SUBTREE);\n\
    \    if (v == root) {\n      evert(root);\n      return (*this)[root]->x;\n  \
    \  }\n    root = jump(v, root, 1);\n    cut(v, root);\n    typename Node::X res\
    \ = (*this)[v]->x;\n    link(v, root);\n    return res;\n  }\n\n  vc<int> collect_heavy_path(int\
    \ v) {\n    np c = (*this)[v];\n    while (!is_root(c)) c = c->p;\n    vc<int>\
    \ res;\n    auto dfs = [&](auto &dfs, np c, bool rev) -> void {\n      if (!rev)\
    \ {\n        if (c->l) dfs(dfs, c->l, rev ^ c->rev);\n        res.eb(c->idx);\n\
    \        if (c->r) dfs(dfs, c->r, rev ^ c->rev);\n      } else {\n        if (c->r)\
    \ dfs(dfs, c->r, rev ^ c->rev);\n        res.eb(c->idx);\n        if (c->l) dfs(dfs,\
    \ c->l, rev ^ c->rev);\n      }\n    };\n    dfs(dfs, c, false);\n    return res;\n\
    \  }\n\n  void debug() {\n    print(\"p, l, r, rev\");\n    auto f = [&](np c)\
    \ -> int { return (c ? c->idx : -1); };\n    FOR(i, len(nodes)) {\n      print(i,\
    \ \",\", f((*this)[i]->p), f((*this)[i]->l), f((*this)[i]->r),\n          (*this)[i]->rev);\n\
    \    }\n    FOR(i, len(nodes)) {\n      np c = (*this)[i];\n      if (c->l) assert(c->l->p\
    \ == c);\n      if (c->r) assert(c->r->p == c);\n    }\n  }\n\n  void splay(Node\
    \ *c) {\n    c->push();\n    while (!is_root(c)) {\n      Node *p = c->p;\n  \
    \    Node *pp = (p ? p->p : nullptr);\n      if (state(p) == 0) {\n        p->push(),\
    \ c->push();\n        rotate(c);\n      }\n      elif (state(c) == state(p)) {\n\
    \        pp->push(), p->push(), c->push();\n        rotate(p);\n        rotate(c);\n\
    \      }\n      else {\n        pp->push(), p->push(), c->push();\n        rotate(c);\n\
    \        rotate(c);\n      }\n    }\n  }\n\n  // uv path \u4E0A\u3067 prod_path(u,\
    \ x) \u304C check \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E x, \u306A\u3051\u308C\
    \u3070 \uFF08\u3064\u307E\u308A\n  // path(u,u) \u304C ng \uFF09-1. \u6839\u3092\
    \u5909\u3048\u308B. \u3042\u307E\u308A verify \u3055\u308C\u3066\u306A\u3044\u3088\
    .\n  // https://codeforces.com/contest/1039/submission/320681517\n  // https://codesprintla25.kattis.com/contests/cxeqb3/submissions/17431394\n\
    \  template <class F>\n  int max_path(F check, int u, int v) {\n    evert(u),\
    \ expose(v);\n    Node *c = (*this)[v];\n    using MX = typename Node::MX;\n \
    \   using X = typename MX::value_type;\n    Node *last_ok = nullptr, *last = nullptr;\n\
    \    X lprod = MX::id();\n    while (c) {\n      last = c;\n      c->push();\n\
    \      X x = (c->l ? MX::op(c->l->x, c->vx) : c->vx);\n      x = MX::op(lprod,\
    \ x);\n      if (!check(x)) {\n        c = c->l;\n      } else {\n        last_ok\
    \ = c, c = c->r, lprod = x;\n      }\n    }\n    splay(last);\n    if (!last_ok)\
    \ return -1;\n    return last_ok->idx;\n  }\n\n private:\n  // splay tree \u5185\
    \u3067\u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy, light \u69CB\u9020\
    \u306F\u5909\u308F\u3089\u306A\u3044.\n  // light pointer \u306F rotate \u5185\
    \u3067\u30B1\u30A2\n  // c \u306F push \u6E08\u306B\u306A\u308B\n\n  // \u30D1\
    \u30B9\u3092\u8868\u3059 splay tree \u306E\u6839\u306B\u306A\u3063\u3066\u3044\
    \u308B\u304B\u3069\u3046\u304B\n  // underlying tree \u3067\u306F\u306A\u3044\n\
    \  bool is_root(Node *c) { return state(c) == 0; }\n\n  // splay tree \u5185\u3067\
    \u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy, light \u69CB\u9020\u306F\
    \u5909\u308F\u3089\u306A\u3044.\n  // light edge \u306E\u30DD\u30A4\u30F3\u30BF\
    \u306F\u5909\u66F4\u3055\u308C\u3046\u308B\n  void rotate(Node *n) {\n    // n\
    \ \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n\
    \    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r = p;\n    \
    \  p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n      p->r = c;\n\
    \    }\n    p->update(), n->update();\n\n    if (pp) {\n      if (pp->l == p)\
    \ pp->l = n;\n      elif (pp->r == p) pp->r = n;\n      else {\n        // light\
    \ edge pointer \u304C (pp-p) \u304B\u3089 (pp-n) \u306B\u5909\u308F\u308B\n  \
    \      pp->change_light(p, n);\n      }\n    }\n    n->p = pp;\n    p->p = n;\n\
    \    if (c) c->p = p;\n  }\n\n  inline int state(Node *n) {\n    if (!n->p) return\
    \ 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r == n) return -1;\n    return\
    \ 0;\n  }\n};\n#line 1 \"graph/ds/lct_node_monoid.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/ds/lct_node_monoid.hpp\n\
    \ntemplate <typename Monoid>\nstruct LCT_Node_Monoid {\n  using np = LCT_Node_Monoid\
    \ *;\n  // \u30C7\u30D5\u30A9\u30EB\u30C8\n  np l, r, p;\n  int idx, size; //\
    \ size \u306F heavy path \u306E\u9802\u70B9\u6570\n  bool rev;\n  // \u76EE\u7684\
    \u3054\u3068\u306B\u5B9A\u7FA9\u3059\u308B.\n  using MX = Monoid;\n  using X =\
    \ typename MX::value_type;\n  using VX = X;\n\n  X x, rx, vx;\n\n  LCT_Node_Monoid(int\
    \ i = 0)\n      : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n    \
    \    idx(i),\n        size(1),\n        rev(0),\n        x(MX::id()),\n      \
    \  rx(MX::id()),\n        vx(MX::id()) {}\n\n  void update() {\n    size = 1;\n\
    \    x = vx, rx = vx;\n    if (l) {\n      size += l->size, x = Monoid::op(l->x,\
    \ x), rx = Monoid::op(rx, l->rx);\n    }\n    if (r) {\n      size += r->size,\
    \ x = Monoid::op(x, r->x), rx = Monoid::op(r->rx, rx);\n    }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  // data \u306E reverse \u3082\u884C\u3046\n \
    \ void reverse() {\n    rev ^= 1;\n    swap(l, r);\n    swap(x, rx);\n  }\n\n\
    \  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\
    \u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) { vx = x; }\n\n  void add_light(np\
    \ c) {}\n  void erase_light(np c) {}\n  void change_light(np a, np b) {}\n};\n\
    #line 10 \"test/5_ai_generated_test/link_cut_tree_ordered_prefix.test.cpp\"\n\n\
    struct Concat {\n  using value_type = std::string;\n  static value_type id() {\
    \ return {}; }\n  static value_type op(const value_type& a, const value_type&\
    \ b) { return a + b; }\n  static constexpr bool commute = false;\n};\n\nint main()\
    \ {\n  constexpr unsigned seed = 772902;\n  std::mt19937 gen(seed);\n  long long\
    \ checks = 0;\n  for (int round = 0; round < 121; ++round) {\n    int n = 1 +\
    \ round % 13;\n    Link_Cut_Tree<LCT_Node_Monoid<Concat>> t(n);\n    std::vector<std::vector<bool>>\
    \ edge(n, std::vector<bool>(n));\n    std::vector<char> label(n);\n    std::vector<int>\
    \ root(n), q;\n    std::iota(root.begin(), root.end(), 0);\n    auto bfs = [&](int\
    \ s) {\n      std::vector<int> par(n, -2);\n      q.assign(1, s);\n      par[s]\
    \ = -1;\n      for (size_t i = 0; i < q.size(); ++i)\n        for (int j = 0;\
    \ j < n; ++j)\n          if (edge[q[i]][j] && par[j] == -2) {\n            par[j]\
    \ = q[i];\n            q.push_back(j);\n          }\n      return par;\n    };\n\
    \    auto reroot = [&](int s) {\n      bfs(s);\n      for (int x : q) root[x]\
    \ = s;\n    };\n    auto assign = [&](int s) {\n      label[s] = 'a' + gen() %\
    \ 4;\n      t.set(s, std::string(1, label[s]));\n      reroot(s);\n    };\n  \
    \  for (int i = 0; i < n; ++i) assign(i);\n    for (int step = 0; step < 160;\
    \ ++step) {\n      int a = gen() % n, b = gen() % n;\n      auto eq = [&](auto\
    \ got, auto want, const char* phase) {\n        ++checks;\n        if (got !=\
    \ want) {\n          std::cerr << \"seed=\" << seed << \" round=\" << round <<\
    \ \" n=\" << n\n                    << \" step=\" << step << \" a=\" << a << \"\
    \ b=\" << b\n                    << \" \" << phase << \" got=\" << got << \" want=\"\
    \ << want << '\\n';\n          std::abort();\n        }\n      };\n      switch\
    \ (gen() % 5) {\n        case 0: case 1:\n          if (root[a] != root[b]) {\n\
    \            int r = root[a];\n            t.link(a, b);\n            edge[a][b]\
    \ = edge[b][a] = true;\n            reroot(r);\n          }\n          break;\n\
    \        case 2: {\n          std::vector<std::pair<int, int>> edges;\n      \
    \    for (int i = 0; i < n; ++i)\n            for (int j = 0; j < n; ++j)\n  \
    \            if (edge[i][j]) edges.emplace_back(i, j);\n          if (!edges.empty())\
    \ {\n            auto [x, y] = edges[gen() % edges.size()];\n            t.cut(x,\
    \ y);\n            edge[x][y] = edge[y][x] = false;\n            reroot(x);\n\
    \            reroot(y);\n            eq(t.get_root(x), x, \"cut root x\");\n \
    \           eq(t.get_root(y), y, \"cut root y\");\n          }\n          break;\n\
    \        }\n        case 3: assign(a); break;\n        case 4: t.evert(a); reroot(a);\
    \ break;\n      }\n      // \u73FE\u5728\u306E\u6210\u5206\u304B\u3089\u7D42\u70B9\
    \u3092\u9078\u3076\u3002\u5B64\u7ACB\u70B9\u3067\u3082\u9577\u30551\u306E\u30D1\
    \u30B9\u3092\u8ABF\u3079\u308B\u3002\n      bfs(a);\n      b = q[gen() % q.size()];\n\
    \      for (int dir = 0; dir < 2; ++dir) {\n        auto par = bfs(a);\n     \
    \   std::vector<int> path;\n        for (int x = b; x != -1; x = par[x]) path.push_back(x);\n\
    \        std::reverse(path.begin(), path.end());\n        std::string word;\n\
    \        for (int x : path) word += label[x];\n        eq(t.get_root(b), root[b],\
    \ \"before path\");\n        eq(t.prod_path(a, b), word, \"ordered product\");\n\
    \        reroot(a);\n        std::string target = word;\n        for (size_t k\
    \ = 0; k <= path.size(); ++k) {\n          eq(t.max_path([&](const std::string&\
    \ s) {\n            return s.size() <= k && target.compare(0, s.size(), s) ==\
    \ 0;\n          }, a, b), k ? path[k - 1] : -1, \"prefix cap\");\n        }\n\
    \        size_t k = gen() % path.size();\n        target[k] = 'z';  // \u9577\u3055\
    \u3067\u306F\u306A\u304F\u6587\u5B57\u4E0D\u4E00\u81F4\u3067\u6253\u3061\u5207\
    \u308B\n        eq(t.max_path([&](const std::string& s) {\n          return target.compare(0,\
    \ s.size(), s) == 0;\n        }, a, b), k ? path[k - 1] : -1, \"prefix mismatch\"\
    );\n        eq(t.get_root(b), a, \"search root\");\n        eq(t.get_parent(b),\
    \ path.size() == 1 ? -1 : path[path.size() - 2], \"parent after search\");\n \
    \       eq(t.get_root(b), a, \"parent preserves root\");\n        std::swap(a,\
    \ b);\n      }\n    }\n  }\n  std::cout << \"LCT checks=\" << checks << '\\n';\n\
    }\n"
  code: "// TST-0026: link/cut \u3092\u631F\u3093\u3060\u68EE\u6797\u4E0A\u306E\u975E\
    \u53EF\u63DB\u306A\u7D4C\u8DEF prefix \u63A2\u7D22\u3002\n// \u96A3\u63A5\u884C\
    \u5217\u304B\u3089 BFS \u3067\u552F\u4E00\u306E\u7D4C\u8DEF\u3092\u5FA9\u5143\u3057\
    \u3001\u9802\u70B9\u30E9\u30D9\u30EB\u3092\u9806\u756A\u306B\u9023\u7D50\u3059\
    \u308B\u3002\n// check \u306F\u300C\u76EE\u6A19\u6587\u5B57\u5217\u306E prefix\
    \ \u304B\u3064\u9577\u3055\u4E0A\u9650\u4EE5\u4E0B\u300D\u3002\u5EF6\u9577\u3067\
    \ false \u304B\u3089 true\n// \u306B\u306F\u623B\u3089\u306A\u3044\u3002\u6700\
    \u521D\u306E\u9802\u70B9\u3067\u5931\u6557\u30FB\u4E2D\u9014\u306E\u6587\u5B57\
    \u4E0D\u4E00\u81F4\u30FB\u5168\u7D4C\u8DEF\u6210\u529F\u3092\u4E21\u65B9\u5411\
    \u3067\u78BA\u8A8D\u3002\n// evert \u3092\u631F\u307E\u305A\u6839\u3068\u89AA\u3092\
    \u7167\u5408\u3057\u3001\u63A2\u7D22\u3084 link/cut \u306E\u6839\u306B\u5BFE\u3059\
    \u308B\u526F\u4F5C\u7528\u3082\u78BA\u8A8D\u3059\u308B\u3002\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"graph/ds/link_cut_tree.hpp\"\n#include\
    \ \"graph/ds/lct_node_monoid.hpp\"\n\nstruct Concat {\n  using value_type = std::string;\n\
    \  static value_type id() { return {}; }\n  static value_type op(const value_type&\
    \ a, const value_type& b) { return a + b; }\n  static constexpr bool commute =\
    \ false;\n};\n\nint main() {\n  constexpr unsigned seed = 772902;\n  std::mt19937\
    \ gen(seed);\n  long long checks = 0;\n  for (int round = 0; round < 121; ++round)\
    \ {\n    int n = 1 + round % 13;\n    Link_Cut_Tree<LCT_Node_Monoid<Concat>> t(n);\n\
    \    std::vector<std::vector<bool>> edge(n, std::vector<bool>(n));\n    std::vector<char>\
    \ label(n);\n    std::vector<int> root(n), q;\n    std::iota(root.begin(), root.end(),\
    \ 0);\n    auto bfs = [&](int s) {\n      std::vector<int> par(n, -2);\n     \
    \ q.assign(1, s);\n      par[s] = -1;\n      for (size_t i = 0; i < q.size();\
    \ ++i)\n        for (int j = 0; j < n; ++j)\n          if (edge[q[i]][j] && par[j]\
    \ == -2) {\n            par[j] = q[i];\n            q.push_back(j);\n        \
    \  }\n      return par;\n    };\n    auto reroot = [&](int s) {\n      bfs(s);\n\
    \      for (int x : q) root[x] = s;\n    };\n    auto assign = [&](int s) {\n\
    \      label[s] = 'a' + gen() % 4;\n      t.set(s, std::string(1, label[s]));\n\
    \      reroot(s);\n    };\n    for (int i = 0; i < n; ++i) assign(i);\n    for\
    \ (int step = 0; step < 160; ++step) {\n      int a = gen() % n, b = gen() % n;\n\
    \      auto eq = [&](auto got, auto want, const char* phase) {\n        ++checks;\n\
    \        if (got != want) {\n          std::cerr << \"seed=\" << seed << \" round=\"\
    \ << round << \" n=\" << n\n                    << \" step=\" << step << \" a=\"\
    \ << a << \" b=\" << b\n                    << \" \" << phase << \" got=\" <<\
    \ got << \" want=\" << want << '\\n';\n          std::abort();\n        }\n  \
    \    };\n      switch (gen() % 5) {\n        case 0: case 1:\n          if (root[a]\
    \ != root[b]) {\n            int r = root[a];\n            t.link(a, b);\n   \
    \         edge[a][b] = edge[b][a] = true;\n            reroot(r);\n          }\n\
    \          break;\n        case 2: {\n          std::vector<std::pair<int, int>>\
    \ edges;\n          for (int i = 0; i < n; ++i)\n            for (int j = 0; j\
    \ < n; ++j)\n              if (edge[i][j]) edges.emplace_back(i, j);\n       \
    \   if (!edges.empty()) {\n            auto [x, y] = edges[gen() % edges.size()];\n\
    \            t.cut(x, y);\n            edge[x][y] = edge[y][x] = false;\n    \
    \        reroot(x);\n            reroot(y);\n            eq(t.get_root(x), x,\
    \ \"cut root x\");\n            eq(t.get_root(y), y, \"cut root y\");\n      \
    \    }\n          break;\n        }\n        case 3: assign(a); break;\n     \
    \   case 4: t.evert(a); reroot(a); break;\n      }\n      // \u73FE\u5728\u306E\
    \u6210\u5206\u304B\u3089\u7D42\u70B9\u3092\u9078\u3076\u3002\u5B64\u7ACB\u70B9\
    \u3067\u3082\u9577\u30551\u306E\u30D1\u30B9\u3092\u8ABF\u3079\u308B\u3002\n  \
    \    bfs(a);\n      b = q[gen() % q.size()];\n      for (int dir = 0; dir < 2;\
    \ ++dir) {\n        auto par = bfs(a);\n        std::vector<int> path;\n     \
    \   for (int x = b; x != -1; x = par[x]) path.push_back(x);\n        std::reverse(path.begin(),\
    \ path.end());\n        std::string word;\n        for (int x : path) word +=\
    \ label[x];\n        eq(t.get_root(b), root[b], \"before path\");\n        eq(t.prod_path(a,\
    \ b), word, \"ordered product\");\n        reroot(a);\n        std::string target\
    \ = word;\n        for (size_t k = 0; k <= path.size(); ++k) {\n          eq(t.max_path([&](const\
    \ std::string& s) {\n            return s.size() <= k && target.compare(0, s.size(),\
    \ s) == 0;\n          }, a, b), k ? path[k - 1] : -1, \"prefix cap\");\n     \
    \   }\n        size_t k = gen() % path.size();\n        target[k] = 'z';  // \u9577\
    \u3055\u3067\u306F\u306A\u304F\u6587\u5B57\u4E0D\u4E00\u81F4\u3067\u6253\u3061\
    \u5207\u308B\n        eq(t.max_path([&](const std::string& s) {\n          return\
    \ target.compare(0, s.size(), s) == 0;\n        }, a, b), k ? path[k - 1] : -1,\
    \ \"prefix mismatch\");\n        eq(t.get_root(b), a, \"search root\");\n    \
    \    eq(t.get_parent(b), path.size() == 1 ? -1 : path[path.size() - 2], \"parent\
    \ after search\");\n        eq(t.get_root(b), a, \"parent preserves root\");\n\
    \        std::swap(a, b);\n      }\n    }\n  }\n  std::cout << \"LCT checks=\"\
    \ << checks << '\\n';\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/ds/link_cut_tree.hpp
  - graph/ds/lct_node_monoid.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/link_cut_tree_ordered_prefix.test.cpp
  requiredBy: []
  timestamp: '2026-11-29 04:16:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/link_cut_tree_ordered_prefix.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/link_cut_tree_ordered_prefix.test.cpp
- /verify/test/5_ai_generated_test/link_cut_tree_ordered_prefix.test.cpp.html
title: test/5_ai_generated_test/link_cut_tree_ordered_prefix.test.cpp
---
