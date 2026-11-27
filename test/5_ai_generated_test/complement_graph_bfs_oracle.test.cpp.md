---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':heavy_check_mark:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/blackbox/complement_graph_bfs.hpp
    title: graph/blackbox/complement_graph_bfs.hpp
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
  bundledCode: "#line 1 \"my_template.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n\
    #if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\n#if defined(__GNUC__)\n\
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 1 \"graph/blackbox/complement_graph_bfs.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/graph/blackbox/complement_graph_bfs.hpp\n\
    #line 1 \"graph/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/base.hpp\n\
    #line 1 \"ds/hashmap.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/hashmap.hpp\n\
    \n// u64 -> Val\ntemplate <typename Val>\nstruct HashMap {\n  // n \u306F\u5165\
    \u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\u3067 ok\n  HashMap(u32 n = 0)\
    \ { build(n); }\n  void build(u32 n) {\n    u32 k = 8;\n    while (k < n * 2)\
    \ k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k), val.resize(k), used.assign(k,\
    \ 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\u307E\u307E. size=0 \u306B\u3059\
    \u308B\u3068\u304D\u306F build \u3059\u308B\u3053\u3068.\n  void clear() {\n \
    \   used.assign(len(used), 0);\n    cap = (mask + 1) / 2;\n  }\n  int size() {\
    \ return len(used) / 2 - cap; }\n\n  int index(const u64& k) {\n    int i = 0;\n\
    \    for (i = hash(k); used[i] && key[i] != k; i = (i + 1) & mask) {\n    }\n\
    \    return i;\n  }\n\n  Val& operator[](const u64& k) {\n    int i = index(k);\n\
    \    if (used[i]) return val[i];\n    if (cap == 0) extend(), i = index(k);\n\
    \    used[i] = 1, key[i] = k, val[i] = Val{}, --cap;\n    return val[i];\n  }\n\
    \n  Val get(const u64& k, Val default_value) {\n    int i = index(k);\n    return\
    \ (used[i] ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n \
    \   int i = index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key,\
    \ val)\n  template <typename F>\n  void enumerate_all(F f) {\n    bool end = false;\n\
    \    FOR(i, len(used)) {\n      if (used[i]) f(key[i], val[i], end);\n      if\
    \ (end) break;\n    }\n  }\n\n private:\n  u32 cap, mask;\n  vc<u64> key;\n  vc<Val>\
    \ val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const u64 FIXED_RANDOM\
    \ =\n        std::chrono::steady_clock::now().time_since_epoch().count();\n  \
    \  x += FIXED_RANDOM;\n    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x =\
    \ (x ^ (x >> 27)) * 0x94d049bb133111eb;\n    return (x ^ (x >> 31)) & mask;\n\
    \  }\n\n  void extend() {\n    vc<pair<u64, Val>> dat;\n    dat.reserve(len(used)\
    \ / 2 - cap);\n    FOR(i, len(used)) {\n      if (used[i]) dat.eb(key[i], val[i]);\n\
    \    }\n    build(2 * len(dat));\n    for (auto& [a, b] : dat) (*this)[a] = b;\n\
    \  }\n};\n#line 3 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \  int frm, to;\n  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool\
    \ directed = false>\nstruct Graph {\n  static constexpr bool is_directed = directed;\n\
    \  int N, M;\n  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type>\
    \ edges;\n  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  mutable vc<int>\
    \ vc_deg, vc_indeg, vc_outdeg;\n  mutable HashMap<int> MP_FOR_EID;\n  bool prepared;\n\
    \n  class OutgoingEdges {\n   public:\n    OutgoingEdges(const Graph* G, int l,\
    \ int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin() const {\n     \
    \ if (l == r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n\
    \    }\n\n    const edge_type* end() const {\n      if (l == r) {\n        return\
    \ 0;\n      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const\
    \ Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() const { return prepared;\
    \ }\n\n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n    MP_FOR_EID.clear();\n  }\n\n  void add(int frm, int\
    \ to, T cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm &&\
    \ frm < N && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n\
    \  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off);\
    \ }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n    for (int\
    \ m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n      if\
    \ (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e : edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) {\n      indptr[v\
    \ + 1] += indptr[v];\n    }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e : edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() const {\n    if (vc_deg.empty()) calc_deg();\n    return\
    \ vc_deg;\n  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() const {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ const {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n\
    \  int in_deg(int v) const {\n    if (vc_indeg.empty()) calc_deg_inout();\n  \
    \  return vc_indeg[v];\n  }\n\n  int out_deg(int v) const {\n    if (vc_outdeg.empty())\
    \ calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug()\
    \ {\n#ifdef LOCAL\n    print(\"Graph\");\n    if (!prepared) {\n      print(\"\
    frm to cost id\");\n      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n\
    \    } else {\n      print(\"indptr\", indptr);\n      print(\"frm to cost id\"\
    );\n      FOR(v, N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n\
    \    }\n    flush();\n#endif\n  }\n#endif\n\n  mutable vc<int> new_idx;\n  mutable\
    \ vc<bool> used_e;\n\n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\
    \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B\n  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\
    \u3063\u3066\u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E\
    \ n+m \u3088\u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\
    \u3067\u6CE8\u610F\n  Graph<T, directed> rearrange(const vc<int>& V, bool keep_eid\
    \ = 0) const {\n    if (len(new_idx) != N) new_idx.assign(N, -1);\n    int n =\
    \ len(V);\n    FOR(i, n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n  \
    \  vc<int> history;\n    FOR(i, n) {\n      for (auto&& e : (*this)[V[i]]) {\n\
    \        if (len(used_e) <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id])\
    \ continue;\n        int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 &&\
    \ new_idx[b] != -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n\
    \          int eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b],\
    \ e.cost, eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n\
    \    for (auto&& eid : history) used_e[eid] = 0;\n    G.build();\n    return G;\n\
    \  }\n\n  Graph<T, true> to_directed_tree(int root = -1) const {\n    if (root\
    \ == -1) root = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T,\
    \ true> G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v)\
    \ -> void {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) const\
    \ {\n    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for\
    \ (auto& e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) const {\n    if (!directed &&\
    \ a > b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg()\
    \ const {\n    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&&\
    \ e : edges) vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout()\
    \ const {\n    assert(vc_indeg.empty());\n    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n\
    \    for (auto&& e : edges) {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n \
    \   }\n  }\n};\n#line 3 \"graph/blackbox/complement_graph_bfs.hpp\"\n\ntemplate\
    \ <typename GT>\npair<vc<int>, vc<int>> complement_graph_bfs(GT& G, int s) {\n\
    \  static vc<int> que, NG, dist, par, yet;\n  const int N = G.N;\n  if (len(que)\
    \ < N) que.resize(N);\n  if (len(NG) < N) NG.resize(N);\n  if (len(yet) < N) yet.resize(N);\n\
    \  dist.assign(N, infty<int>);\n  par.assign(N, -1);\n  int ql = 0, qr = 0;\n\
    \  dist[s] = 0, que[qr++] = s;\n  int p = 0;\n  FOR(v, N) if (v != s) yet[p++]\
    \ = v;\n  while (ql < qr) {\n    int v = que[ql++];\n    for (auto& e: G[v]) NG[e.to]\
    \ = 1;\n    for (int i = p - 1; i >= 0; --i) {\n      int to = yet[i];\n     \
    \ if (NG[to]) continue;\n      dist[to] = dist[v] + 1, par[to] = v, que[qr++]\
    \ = to;\n      swap(yet[i], yet[--p]);\n    }\n    for (auto& e: G[v]) NG[e.to]\
    \ = 0;\n  }\n  return {dist, par};\n}\n#line 4 \"test/5_ai_generated_test/complement_graph_bfs_oracle.test.cpp\"\
    \n\n/*\n\u5BFE\u8C61: complement_graph_bfs(G,s) \u304C\u8FD4\u3059\u88DC\u30B0\
    \u30E9\u30D5\u5185\u306E\u8DDD\u96E2\u3068\u89AA\u3002\n\u65E2\u5B58\u306E\u554F\
    \u984C\u5225\u30C6\u30B9\u30C8\u306B\u306F\u3053\u306E\u95A2\u6570\u3078\u306E\
    \u76F4\u63A5\u306E\u691C\u8A3C\u304C\u898B\u5F53\u305F\u3089\u306A\u3044\u305F\
    \u3081\u8FFD\u52A0\u3002\n\u72EC\u7ACB oracle: \u96A3\u63A5\u884C\u5217\u3092\u53CD\
    \u8EE2\u3057\u305F\u5358\u7D14\u306A BFS\u3002\u88DC\u30B0\u30E9\u30D5\u306B\u81EA\
    \u5DF1\u30EB\u30FC\u30D7\u306F\u542B\u3081\u306A\u3044\u3002\n\u5143\u30B0\u30E9\
    \u30D5\u306F\u7121\u5411\u3067\u3001\u5E73\u884C\u8FBA\u3092\u8A31\u3057\u3001\
    \u5408\u6CD5\u306A\u59CB\u70B9\u3092\u4E0E\u3048\u308B\u3002\n\u5C0F\u3055\u3044\
    \u7121\u5411\u30B0\u30E9\u30D5\uFF08n<=5\uFF09\u3092\u5168\u5217\u6319\u3001\u3055\
    \u3089\u306B n=63/64/65/129 \u7B49\u3092\u4E71\u629E\u3002\n\u95A2\u6570\u5185\
    \u306E static \u30D0\u30C3\u30D5\u30A1\u304C\u524D\u56DE\u5B9F\u884C\u306E\u60C5\
    \u5831\u3092\u5F15\u304D\u305A\u3089\u306A\u3044\u3088\u3046\u3001n\u30FB\u59CB\
    \u70B9\u3092\u6BCE\u56DE\u5909\u3048\u308B\u3002\n\u4E71\u6570seed: 0xC0B17E2026ULL\u3002\
    \n*/\nnamespace {\nvoid fail(int n, int s, int v, const string& why) {\n  cerr\
    \ << \"complement_graph_bfs n=\" << n << \" source=\" << s\n       << \" vertex=\"\
    \ << v << \" : \" << why << '\\n';\n  abort();\n}\nvoid check(const vector<vector<unsigned\
    \ char>>& adj, int s,\n           const vector<pair<int, int>>& edges) {\n  int\
    \ n = int(adj.size());\n  Graph<int, 0> G(n);\n  for (auto [u, v] : edges) G.add(u,\
    \ v);\n  G.build();\n  const auto [dist, par] = complement_graph_bfs(G, s);\n\
    \  vector<int> expected(n, infty<int>);\n  queue<int> q;\n  expected[s] = 0;\n\
    \  q.push(s);\n  while (!q.empty()) {\n    int v = q.front(); q.pop();\n    for\
    \ (int w = 0; w < n; ++w) {\n      if (w == v || adj[v][w] || expected[w] != infty<int>)\
    \ continue;\n      expected[w] = expected[v] + 1;\n      q.push(w);\n    }\n \
    \ }\n  if (dist.size() != size_t(n) || par.size() != size_t(n))\n    fail(n, s,\
    \ -1, \"output sizes\");\n  for (int v = 0; v < n; ++v) {\n    if (dist[v] !=\
    \ expected[v])\n      fail(n, s, v, \"dist got=\" + to_string(dist[v]) +\n   \
    \                  \" expected=\" + to_string(expected[v]));\n    if (v == s ||\
    \ expected[v] == infty<int>) {\n      if (par[v] != -1) fail(n, s, v, \"parent\
    \ should be -1\");\n    } else {\n      int p = par[v];\n      if (p < 0 || p\
    \ >= n || p == v || adj[p][v] ||\n          dist[p] + 1 != dist[v])\n        fail(n,\
    \ s, v, \"parent is not a valid shortest-path predecessor\");\n    }\n  }\n}\n\
    void test_mask(int n, uint64_t mask) {\n  vector<vector<unsigned char>> adj(n,\
    \ vector<unsigned char>(n));\n  vector<pair<int, int>> edges;\n  int k = 0;\n\
    \  for (int u = 0; u < n; ++u) for (int v = u + 1; v < n; ++v) {\n    if (mask\
    \ >> k & 1ULL) adj[u][v] = adj[v][u] = 1, edges.emplace_back(u, v);\n    ++k;\n\
    \  }\n  for (int s = 0; s < n; ++s) check(adj, s, edges);\n}\nvoid random_case(int\
    \ n, mt19937_64& rng) {\n  vector<vector<unsigned char>> adj(n, vector<unsigned\
    \ char>(n));\n  vector<pair<int, int>> edges;\n  int p = int(rng() % 101);\n \
    \ for (int u = 0; u < n; ++u) for (int v = u + 1; v < n; ++v) {\n    if (rng()\
    \ % 100 < uint64_t(p)) {\n      adj[u][v] = adj[v][u] = 1;\n      edges.emplace_back(u,\
    \ v);\n      if (rng() % 31 == 0) edges.emplace_back(u, v); // \u5143\u30B0\u30E9\
    \u30D5\u306E\u5E73\u884C\u8FBA\n    }\n  }\n  for (int repeat = 0; repeat < min(n,\
    \ 5); ++repeat) {\n    int s = int(rng() % n);\n    check(adj, s, edges);\n  }\n\
    }\n} // namespace\n\nint main() {\n  for (int n = 1; n <= 5; ++n) {\n    int m\
    \ = n * (n - 1) / 2;\n    for (uint64_t mask = 0; mask < (1ULL << m); ++mask)\
    \ test_mask(n, mask);\n  }\n  mt19937_64 rng(0xC0B17E2026ULL);\n  for (int n :\
    \ {1, 2, 3, 6, 7, 8, 31, 32, 63, 64, 65, 66, 127, 128, 129}) {\n    for (int rep\
    \ = 0; rep < 28; ++rep) random_case(n, rng);\n  }\n  return 0;\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"graph/blackbox/complement_graph_bfs.hpp\"\
    \n\n/*\n\u5BFE\u8C61: complement_graph_bfs(G,s) \u304C\u8FD4\u3059\u88DC\u30B0\
    \u30E9\u30D5\u5185\u306E\u8DDD\u96E2\u3068\u89AA\u3002\n\u65E2\u5B58\u306E\u554F\
    \u984C\u5225\u30C6\u30B9\u30C8\u306B\u306F\u3053\u306E\u95A2\u6570\u3078\u306E\
    \u76F4\u63A5\u306E\u691C\u8A3C\u304C\u898B\u5F53\u305F\u3089\u306A\u3044\u305F\
    \u3081\u8FFD\u52A0\u3002\n\u72EC\u7ACB oracle: \u96A3\u63A5\u884C\u5217\u3092\u53CD\
    \u8EE2\u3057\u305F\u5358\u7D14\u306A BFS\u3002\u88DC\u30B0\u30E9\u30D5\u306B\u81EA\
    \u5DF1\u30EB\u30FC\u30D7\u306F\u542B\u3081\u306A\u3044\u3002\n\u5143\u30B0\u30E9\
    \u30D5\u306F\u7121\u5411\u3067\u3001\u5E73\u884C\u8FBA\u3092\u8A31\u3057\u3001\
    \u5408\u6CD5\u306A\u59CB\u70B9\u3092\u4E0E\u3048\u308B\u3002\n\u5C0F\u3055\u3044\
    \u7121\u5411\u30B0\u30E9\u30D5\uFF08n<=5\uFF09\u3092\u5168\u5217\u6319\u3001\u3055\
    \u3089\u306B n=63/64/65/129 \u7B49\u3092\u4E71\u629E\u3002\n\u95A2\u6570\u5185\
    \u306E static \u30D0\u30C3\u30D5\u30A1\u304C\u524D\u56DE\u5B9F\u884C\u306E\u60C5\
    \u5831\u3092\u5F15\u304D\u305A\u3089\u306A\u3044\u3088\u3046\u3001n\u30FB\u59CB\
    \u70B9\u3092\u6BCE\u56DE\u5909\u3048\u308B\u3002\n\u4E71\u6570seed: 0xC0B17E2026ULL\u3002\
    \n*/\nnamespace {\nvoid fail(int n, int s, int v, const string& why) {\n  cerr\
    \ << \"complement_graph_bfs n=\" << n << \" source=\" << s\n       << \" vertex=\"\
    \ << v << \" : \" << why << '\\n';\n  abort();\n}\nvoid check(const vector<vector<unsigned\
    \ char>>& adj, int s,\n           const vector<pair<int, int>>& edges) {\n  int\
    \ n = int(adj.size());\n  Graph<int, 0> G(n);\n  for (auto [u, v] : edges) G.add(u,\
    \ v);\n  G.build();\n  const auto [dist, par] = complement_graph_bfs(G, s);\n\
    \  vector<int> expected(n, infty<int>);\n  queue<int> q;\n  expected[s] = 0;\n\
    \  q.push(s);\n  while (!q.empty()) {\n    int v = q.front(); q.pop();\n    for\
    \ (int w = 0; w < n; ++w) {\n      if (w == v || adj[v][w] || expected[w] != infty<int>)\
    \ continue;\n      expected[w] = expected[v] + 1;\n      q.push(w);\n    }\n \
    \ }\n  if (dist.size() != size_t(n) || par.size() != size_t(n))\n    fail(n, s,\
    \ -1, \"output sizes\");\n  for (int v = 0; v < n; ++v) {\n    if (dist[v] !=\
    \ expected[v])\n      fail(n, s, v, \"dist got=\" + to_string(dist[v]) +\n   \
    \                  \" expected=\" + to_string(expected[v]));\n    if (v == s ||\
    \ expected[v] == infty<int>) {\n      if (par[v] != -1) fail(n, s, v, \"parent\
    \ should be -1\");\n    } else {\n      int p = par[v];\n      if (p < 0 || p\
    \ >= n || p == v || adj[p][v] ||\n          dist[p] + 1 != dist[v])\n        fail(n,\
    \ s, v, \"parent is not a valid shortest-path predecessor\");\n    }\n  }\n}\n\
    void test_mask(int n, uint64_t mask) {\n  vector<vector<unsigned char>> adj(n,\
    \ vector<unsigned char>(n));\n  vector<pair<int, int>> edges;\n  int k = 0;\n\
    \  for (int u = 0; u < n; ++u) for (int v = u + 1; v < n; ++v) {\n    if (mask\
    \ >> k & 1ULL) adj[u][v] = adj[v][u] = 1, edges.emplace_back(u, v);\n    ++k;\n\
    \  }\n  for (int s = 0; s < n; ++s) check(adj, s, edges);\n}\nvoid random_case(int\
    \ n, mt19937_64& rng) {\n  vector<vector<unsigned char>> adj(n, vector<unsigned\
    \ char>(n));\n  vector<pair<int, int>> edges;\n  int p = int(rng() % 101);\n \
    \ for (int u = 0; u < n; ++u) for (int v = u + 1; v < n; ++v) {\n    if (rng()\
    \ % 100 < uint64_t(p)) {\n      adj[u][v] = adj[v][u] = 1;\n      edges.emplace_back(u,\
    \ v);\n      if (rng() % 31 == 0) edges.emplace_back(u, v); // \u5143\u30B0\u30E9\
    \u30D5\u306E\u5E73\u884C\u8FBA\n    }\n  }\n  for (int repeat = 0; repeat < min(n,\
    \ 5); ++repeat) {\n    int s = int(rng() % n);\n    check(adj, s, edges);\n  }\n\
    }\n} // namespace\n\nint main() {\n  for (int n = 1; n <= 5; ++n) {\n    int m\
    \ = n * (n - 1) / 2;\n    for (uint64_t mask = 0; mask < (1ULL << m); ++mask)\
    \ test_mask(n, mask);\n  }\n  mt19937_64 rng(0xC0B17E2026ULL);\n  for (int n :\
    \ {1, 2, 3, 6, 7, 8, 31, 32, 63, 64, 65, 66, 127, 128, 129}) {\n    for (int rep\
    \ = 0; rep < 28; ++rep) random_case(n, rng);\n  }\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/blackbox/complement_graph_bfs.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/complement_graph_bfs_oracle.test.cpp
  requiredBy: []
  timestamp: '2026-11-23 00:27:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/complement_graph_bfs_oracle.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/complement_graph_bfs_oracle.test.cpp
- /verify/test/5_ai_generated_test/complement_graph_bfs_oracle.test.cpp.html
title: test/5_ai_generated_test/complement_graph_bfs_oracle.test.cpp
---
