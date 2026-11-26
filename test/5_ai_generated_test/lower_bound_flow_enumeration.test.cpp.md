---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/maxflow_with_lower_bound.hpp
    title: flow/maxflow_with_lower_bound.hpp
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 1 \"flow/maxflow_with_lower_bound.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/flow/maxflow_with_lower_bound.hpp\n\
    \n\ntemplate <typename Cap>\nstruct MaxFlow_with_Lower_Bound {\n  int N, s, t,\
    \ S, T;\n  Cap flow_ans;\n  bool prepared = 0;\n\n  struct Edge_raw {\n    int\
    \ frm, to;\n    Cap lo, hi;\n    Edge_raw(int frm, int to, Cap lo, Cap hi)\n \
    \       : frm(frm), to(to), lo(lo), hi(hi){};\n  };\n  vc<Edge_raw> dat;\n\n \
    \ MaxFlow_with_Lower_Bound(int N, int s, int t)\n      : N(N), s(s), t(t), S(N),\
    \ T(N + 1), flow_ans(0) {\n    assert(0 <= s && s < N);\n    assert(0 <= t &&\
    \ t < N);\n  }\n  void add(int frm, int to, Cap lo, Cap hi) {\n    assert(!prepared);\n\
    \    assert(0 <= frm && frm < N);\n    assert(0 <= to && to < N);\n    assert(Cap(0)\
    \ <= lo && lo <= hi);\n    dat.eb(Edge_raw(frm, to, lo, hi));\n  }\n\n  struct\
    \ Edge {\n    int rev, to;\n    Cap cap, flow;\n  };\n\n  vc<Edge> G;\n  vc<int>\
    \ indptr;\n  vc<int> idx;\n  vc<int> level, que, prog;\n\n  void debug() {\n \
    \   print(\"frm,to,lo,hi\");\n    for (auto &e : dat) print(e.frm, e.to, e.lo,\
    \ e.hi);\n  }\n\n  void build() {\n    assert(!prepared);\n    prepared = 1;\n\
    \    int M = len(dat);\n    idx.assign(6 * M, -1);\n    vc<int> cnt(N + 2);\n\
    \    FOR(i, M) {\n      auto [frm, to, lo, hi] = dat[i];\n      if (frm == to)\
    \ continue;\n      if (lo < hi) cnt[frm]++, cnt[to]++;\n      if (0 < lo) cnt[S]++,\
    \ cnt[to]++, cnt[frm]++, cnt[T]++;\n    }\n    indptr = cumsum<int>(cnt);\n  \
    \  int m = indptr.back();\n    G.resize(m);\n    vc<int> prog = indptr;\n    auto\
    \ add = [&](int i, int j, int a, int b, Cap c) -> void {\n      int p = prog[a]++,\
    \ q = prog[b]++;\n      idx[i] = p, idx[j] = q;\n      G[p] = {q, b, c, 0};\n\
    \      G[q] = {p, a, 0, 0};\n    };\n    FOR(i, M) {\n      auto [frm, to, lo,\
    \ hi] = dat[i];\n      if (frm == to) continue;\n      if (lo < hi) add(6 * i\
    \ + 0, 6 * i + 1, frm, to, hi - lo);\n      if (0 < lo) {\n        add(6 * i +\
    \ 2, 6 * i + 3, S, to, lo);\n        add(6 * i + 4, 6 * i + 5, frm, T, lo);\n\
    \        cnt[S]++, cnt[to]++, cnt[frm]++, cnt[T]++;\n      }\n    }\n  }\n\n \
    \ Cap flow() {\n    build();\n    Cap a = flow_st(S, T), b = flow_st(S, t), c\
    \ = flow_st(s, T),\n        d = flow_st(s, t);\n    bool valid = 1;\n    int M\
    \ = len(dat);\n    FOR(i, M) {\n      auto [frm, to, lo, hi] = dat[i];\n     \
    \ if (lo > 0 && G[idx[6 * i + 2]].cap > 0) valid = 0;\n      if (lo > 0 && G[idx[6\
    \ * i + 4]].cap > 0) valid = 0;\n    }\n    if (!valid) return flow_ans = -1;\n\
    \    assert(a + b == a + c && c + d == b + d);\n    return flow_ans = c + d;\n\
    \  }\n\n  void set_level(int s) {\n    level.assign(N + 2, infty<int>);\n    que.resize(N\
    \ + 2);\n    int ql = 0, qr = 0;\n    auto upd = [&](int v, int d) -> void {\n\
    \      if (chmin(level[v], d)) que[qr++] = v;\n    };\n    upd(s, 0);\n    while\
    \ (ql < qr) {\n      int v = que[ql++];\n      FOR(i, indptr[v], indptr[v + 1])\
    \ {\n        auto &e = G[i];\n        if (e.cap > 0) upd(e.to, level[v] + 1);\n\
    \      }\n    }\n  }\n\n  Cap flow_dfs(int s, int t) {\n    prog = indptr;\n \
    \   auto dfs = [&](auto &dfs, int v, Cap lim) -> Cap {\n      if (v == t) return\
    \ lim;\n      Cap res = 0;\n      for (int &i = prog[v]; i < indptr[v + 1]; ++i)\
    \ {\n        auto &e = G[i];\n        if (e.cap > 0 && level[e.to] == level[v]\
    \ + 1) {\n          Cap a = dfs(dfs, e.to, min(lim, e.cap));\n          if (a\
    \ == Cap(0)) continue;\n          e.cap -= a, e.flow += a;\n          G[e.rev].cap\
    \ += a, G[e.rev].flow -= a;\n          res += a, lim -= a;\n          if (lim\
    \ == Cap(0)) break;\n        }\n      }\n      return res;\n    };\n    return\
    \ dfs(dfs, s, infty<Cap>);\n  }\n\n  Cap flow_st(int s, int t) {\n    Cap ans\
    \ = 0;\n    while (1) {\n      set_level(s);\n      if (level[t] == infty<int>)\
    \ break;\n      ans += flow_dfs(s, t);\n    }\n    return ans;\n  }\n\n  // add\
    \ \u3057\u305F\u9806\u306B\u3072\u3068\u3068\u304A\u308A\n  vc<tuple<int, int,\
    \ Cap>> get_flow_result() {\n    assert(flow_ans != Cap(-1));\n    int M = len(dat);\n\
    \    vc<tuple<int, int, Cap>> res(M);\n    FOR(i, M) {\n      auto [frm, to, lo,\
    \ hi] = dat[i];\n      Cap flow = (lo < hi ? G[idx[6 * i + 1]].cap + lo : lo);\n\
    \      // print(frm, to, lo, hi, flow);\n      res[i] = {frm, to, flow};\n   \
    \ }\n    return res;\n  }\n};\n#line 4 \"test/5_ai_generated_test/lower_bound_flow_enumeration.test.cpp\"\
    \n\n// \u5BFE\u8C61: MaxFlow_with_Lower_Bound<int>::flow/get_flow_result\u3002\
    \n// \u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB: \u5404\u8FBA\u306E\u6D41\u91CF lo..hi\
    \ \u3092\u5168\u5217\u6319\u3057\u3066\u6D41\u91CF\u4FDD\u5B58\u5247\u3092\u5224\
    \u5B9A\u3057\u3001\n// \u975E\u8CA0\u306E s-t \u6D41\u91CF\u306E\u6700\u5927\u5024\
    \u3092\u6C42\u3081\u308B\u3002\u4E26\u884C\u8FBA\u3001\u9006\u5411\u304D\u8FBA\
    \u3001\u56FA\u5B9A\u6D41\u91CF\u3001\u5B9F\u73FE\u4E0D\u80FD\u3092\u542B\u3080\
    \u3002\n// \u5165\u529B\u306F s != t\u3001\u81EA\u5DF1\u30EB\u30FC\u30D7\u7121\
    \u3057\u30010 <= lo <= hi <= 3\u3001n<=5\u3001m<=6 \u306B\u9650\u5B9A\u3059\u308B\
    \u3002\n// \u56FA\u5B9Aseed 0xC0A11B0DULL\u3002\u5931\u6557\u6642\u306B\u306F\u5168\
    \u8FBA\u3068\u30AA\u30E9\u30AF\u30EB\u7D50\u679C\u3092\u8868\u793A\u3059\u308B\
    \u3002\nnamespace {\nstruct E { int u,v,lo,hi; };\nint exhaustive(int n,int s,int\
    \ t,const vector<E>& es) {\n  vector<int> bal(n,0);\n  int best=-1;\n  auto dfs=[&](auto&&\
    \ self,int i)->void {\n    if(i==(int)es.size()) {\n      for(int v=0;v<n;v++)\
    \ if(v!=s&&v!=t&&bal[v]!=0) return;\n      if(bal[s]+bal[t]!=0 || bal[t]<0) return;\n\
    \      best=max(best,bal[t]);return;\n    }\n    const auto& e=es[i];\n    for(int\
    \ f=e.lo;f<=e.hi;f++) {\n      bal[e.u]-=f;bal[e.v]+=f;\n      self(self,i+1);\n\
    \      bal[e.u]+=f;bal[e.v]-=f;\n    }\n  };\n  dfs(dfs,0);\n  return best;\n\
    }\n[[noreturn]]void fail(int n,int s,int t,const vector<E>& es,int exp,int got,const\
    \ char* msg) {\n  cerr << \"lower-bound flow: \" << msg << \" n=\" << n << \"\
    \ s=\" << s\n       << \" t=\" << t << \" expected=\" << exp << \" got=\" << got\
    \ << '\\n';\n  for(auto e:es)cerr<<e.u<<' '<<e.v<<' '<<e.lo<<' '<<e.hi<<'\\n';\n\
    \  abort();\n}\nvoid check(int n,int s,int t,const vector<E>& es) {\n  int exp=exhaustive(n,s,t,es);\n\
    \  MaxFlow_with_Lower_Bound<int> f(n,s,t);\n  for(auto e:es) f.add(e.u,e.v,e.lo,e.hi);\n\
    \  int got=f.flow();\n  if(got!=exp)fail(n,s,t,es,exp,got,\"flow value\");\n \
    \ if(got<0)return;\n  auto res=f.get_flow_result();\n  if(res.size()!=es.size())fail(n,s,t,es,exp,got,\"\
    result size\");\n  vector<int> bal(n,0);\n  for(int i=0;i<(int)es.size();i++)\
    \ {\n    auto [u,v,x]=res[i];auto e=es[i];\n    if(u!=e.u||v!=e.v||x<e.lo||x>e.hi)fail(n,s,t,es,exp,got,\"\
    edge flow\");\n    bal[u]-=x;bal[v]+=x;\n  }\n  for(int v=0;v<n;v++) if((v==s&&bal[v]!=-got)||(v==t&&bal[v]!=got)||(v!=s&&v!=t&&bal[v]!=0))\n\
    \    fail(n,s,t,es,exp,got,\"flow conservation\");\n}\n}\nint main(){\n  check(2,0,1,{});\n\
    \  check(2,0,1,{{0,1,1,1}});\n  check(2,0,1,{{0,1,1,3},{1,0,0,2}});\n  check(3,0,2,{{0,1,1,1}});\n\
    \  check(3,0,2,{{0,1,1,2},{1,2,0,3},{0,2,0,2}});\n  mt19937_64 rng(0xC0A11B0DULL);\n\
    \  int cnt=5;\n  for(int n=2;n<=5;n++)for(int rep=0;rep<650;rep++){\n    int s=rng()%n,t=rng()%(n-1);if(t>=s)t++;\n\
    \    int m=rng()%7;\n    vector<E> es;\n    for(int i=0;i<m;i++){\n      int u=rng()%n,v=rng()%(n-1);if(v>=u)v++;\n\
    \      int hi=rng()%4,lo=rng()%(hi+1);\n      es.push_back({u,v,lo,hi});\n   \
    \ }\n    check(n,s,t,es);cnt++;\n  }\n  cout<<\"PASS lower_bound_flow_enumeration\
    \ cases=\"<<cnt<<'\\n';\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/maxflow_with_lower_bound.hpp\"\
    \n\n// \u5BFE\u8C61: MaxFlow_with_Lower_Bound<int>::flow/get_flow_result\u3002\
    \n// \u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB: \u5404\u8FBA\u306E\u6D41\u91CF lo..hi\
    \ \u3092\u5168\u5217\u6319\u3057\u3066\u6D41\u91CF\u4FDD\u5B58\u5247\u3092\u5224\
    \u5B9A\u3057\u3001\n// \u975E\u8CA0\u306E s-t \u6D41\u91CF\u306E\u6700\u5927\u5024\
    \u3092\u6C42\u3081\u308B\u3002\u4E26\u884C\u8FBA\u3001\u9006\u5411\u304D\u8FBA\
    \u3001\u56FA\u5B9A\u6D41\u91CF\u3001\u5B9F\u73FE\u4E0D\u80FD\u3092\u542B\u3080\
    \u3002\n// \u5165\u529B\u306F s != t\u3001\u81EA\u5DF1\u30EB\u30FC\u30D7\u7121\
    \u3057\u30010 <= lo <= hi <= 3\u3001n<=5\u3001m<=6 \u306B\u9650\u5B9A\u3059\u308B\
    \u3002\n// \u56FA\u5B9Aseed 0xC0A11B0DULL\u3002\u5931\u6557\u6642\u306B\u306F\u5168\
    \u8FBA\u3068\u30AA\u30E9\u30AF\u30EB\u7D50\u679C\u3092\u8868\u793A\u3059\u308B\
    \u3002\nnamespace {\nstruct E { int u,v,lo,hi; };\nint exhaustive(int n,int s,int\
    \ t,const vector<E>& es) {\n  vector<int> bal(n,0);\n  int best=-1;\n  auto dfs=[&](auto&&\
    \ self,int i)->void {\n    if(i==(int)es.size()) {\n      for(int v=0;v<n;v++)\
    \ if(v!=s&&v!=t&&bal[v]!=0) return;\n      if(bal[s]+bal[t]!=0 || bal[t]<0) return;\n\
    \      best=max(best,bal[t]);return;\n    }\n    const auto& e=es[i];\n    for(int\
    \ f=e.lo;f<=e.hi;f++) {\n      bal[e.u]-=f;bal[e.v]+=f;\n      self(self,i+1);\n\
    \      bal[e.u]+=f;bal[e.v]-=f;\n    }\n  };\n  dfs(dfs,0);\n  return best;\n\
    }\n[[noreturn]]void fail(int n,int s,int t,const vector<E>& es,int exp,int got,const\
    \ char* msg) {\n  cerr << \"lower-bound flow: \" << msg << \" n=\" << n << \"\
    \ s=\" << s\n       << \" t=\" << t << \" expected=\" << exp << \" got=\" << got\
    \ << '\\n';\n  for(auto e:es)cerr<<e.u<<' '<<e.v<<' '<<e.lo<<' '<<e.hi<<'\\n';\n\
    \  abort();\n}\nvoid check(int n,int s,int t,const vector<E>& es) {\n  int exp=exhaustive(n,s,t,es);\n\
    \  MaxFlow_with_Lower_Bound<int> f(n,s,t);\n  for(auto e:es) f.add(e.u,e.v,e.lo,e.hi);\n\
    \  int got=f.flow();\n  if(got!=exp)fail(n,s,t,es,exp,got,\"flow value\");\n \
    \ if(got<0)return;\n  auto res=f.get_flow_result();\n  if(res.size()!=es.size())fail(n,s,t,es,exp,got,\"\
    result size\");\n  vector<int> bal(n,0);\n  for(int i=0;i<(int)es.size();i++)\
    \ {\n    auto [u,v,x]=res[i];auto e=es[i];\n    if(u!=e.u||v!=e.v||x<e.lo||x>e.hi)fail(n,s,t,es,exp,got,\"\
    edge flow\");\n    bal[u]-=x;bal[v]+=x;\n  }\n  for(int v=0;v<n;v++) if((v==s&&bal[v]!=-got)||(v==t&&bal[v]!=got)||(v!=s&&v!=t&&bal[v]!=0))\n\
    \    fail(n,s,t,es,exp,got,\"flow conservation\");\n}\n}\nint main(){\n  check(2,0,1,{});\n\
    \  check(2,0,1,{{0,1,1,1}});\n  check(2,0,1,{{0,1,1,3},{1,0,0,2}});\n  check(3,0,2,{{0,1,1,1}});\n\
    \  check(3,0,2,{{0,1,1,2},{1,2,0,3},{0,2,0,2}});\n  mt19937_64 rng(0xC0A11B0DULL);\n\
    \  int cnt=5;\n  for(int n=2;n<=5;n++)for(int rep=0;rep<650;rep++){\n    int s=rng()%n,t=rng()%(n-1);if(t>=s)t++;\n\
    \    int m=rng()%7;\n    vector<E> es;\n    for(int i=0;i<m;i++){\n      int u=rng()%n,v=rng()%(n-1);if(v>=u)v++;\n\
    \      int hi=rng()%4,lo=rng()%(hi+1);\n      es.push_back({u,v,lo,hi});\n   \
    \ }\n    check(n,s,t,es);cnt++;\n  }\n  cout<<\"PASS lower_bound_flow_enumeration\
    \ cases=\"<<cnt<<'\\n';\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/maxflow_with_lower_bound.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/lower_bound_flow_enumeration.test.cpp
  requiredBy: []
  timestamp: '2026-11-23 02:04:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/lower_bound_flow_enumeration.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/lower_bound_flow_enumeration.test.cpp
- /verify/test/5_ai_generated_test/lower_bound_flow_enumeration.test.cpp.html
title: test/5_ai_generated_test/lower_bound_flow_enumeration.test.cpp
---
