---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/doubling.hpp
    title: ds/doubling.hpp
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 1 \"ds/doubling.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/doubling.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/doubling.hpp\"\n\n// \u72B6\u614B a \u304B\u3089 1 \u56DE\u64CD\
    \u4F5C\u3059\u308B\u3068\u3001\u72B6\u614B b \u306B\u9077\u79FB\u3057\u3001\u30E2\
    \u30CE\u30A4\u30C9\u306E\u5143 x \u3092\u52A0\u3048\u308B\u3002\n// \u884C\u304D\
    \u5148\u304C\u306A\u3044\u5834\u5408\uFF1A-1 \uFF08add \u4E0D\u8981\uFF09\ntemplate\
    \ <typename Monoid, int LOG>\nstruct Doubling {\n  using X = typename Monoid::value_type;\n\
    \  int N;\n  bool is_prepared;\n  vvc<int> TO;\n  vvc<X> DP;\n\n  Doubling(int\
    \ N) : N(N), is_prepared(0) {\n    TO.assign(LOG, vc<int>(N, -1));\n    DP.assign(LOG,\
    \ vc<X>(N, Monoid::id()));\n  }\n\n  void add(int i, int to, X x) {\n    assert(!is_prepared);\n\
    \    assert(-1 <= to && to < N);\n    TO[0][i] = to;\n    DP[0][i] = x;\n  }\n\
    \n  void build() {\n    assert(!is_prepared);\n    is_prepared = 1;\n    FOR(k,\
    \ LOG - 1) {\n      FOR(v, N) {\n        int w = TO[k][v];\n        if (w == -1)\
    \ {\n          TO[k + 1][v] = -1;\n          DP[k + 1][v] = DP[k][v];\n      \
    \    continue;\n        }\n        TO[k + 1][v] = TO[k][w];\n        DP[k + 1][v]\
    \ = Monoid::op(DP[k][v], DP[k][w]);\n      }\n    }\n  }\n\n  // (to, val)\n \
    \ pair<int, X> calc(int i, ll step) {\n    assert(is_prepared);\n    assert(0\
    \ <= step && step < (1LL << LOG));\n    X x = Monoid::id();\n    while (step &&\
    \ i != -1) {\n      int k = topbit(step);\n      step ^= 1LL << k;\n      x =\
    \ Monoid::op(x, DP[k][i]);\n      i = TO[k][i];\n    }\n    return {i, x};\n \
    \ }\n\n  // check(to, monoid_sum)\n  template <typename F>\n  ll max_step(F check,\
    \ int i) {\n    assert(is_prepared);\n    X x = Monoid::id();\n    ll step = 0;\n\
    \    assert(check(i, x));\n    FOR_R(k, LOG) {\n      int j = TO[k][i];\n    \
    \  if (j == -1) continue;\n      X y = Monoid::op(x, DP[k][i]);\n      if (check(j,\
    \ y)) {\n        step |= 1LL << k;\n        i = j;\n        x = y;\n        assert(i\
    \ != -1);\n      }\n    }\n    return step;\n  }\n\n  void debug() {\n    print(\"\
    TO\");\n    FOR(k, LOG) print(TO[k]);\n    print(\"DP\");\n    FOR(k, LOG) print(DP[k]);\n\
    \  }\n};\n#line 4 \"test/5_ai_generated_test/doubling_noncommutative.test.cpp\"\
    \n\n/*\n\u5BFE\u8C61: ds/doubling.hpp \u306E Doubling::add, build, calc, max_step\u3002\
    \n\u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB: next \u914D\u5217\u3092\u4E00\u6B69\u305A\
    \u3064\u8FBF\u308A\u3001\u6587\u5B57\u5217\u9023\u7D50\u30FB\u91CD\u307F\u548C\
    \u3092\u9010\u6B21\u8A08\u7B97\u3002\n\u72D9\u3046\u4E0D\u5177\u5408: 2\u51AA\u306E\
    \u5883\u754C\u3001bit \u3092\u4E0A\u4F4D\u304B\u3089\u51E6\u7406\u3059\u308B\u3068\
    \u304D\u306E\u975E\u53EF\u63DB\u306A\u7A4D\u306E\u9806\u5E8F\u3001\n\u9077\u79FB\
    \u5148 -1 \u306E\u505C\u6B62\u51E6\u7406\u3001\u672A\u767B\u9332\u9077\u79FB\u3001\
    \u81EA\u5DF1\u30EB\u30FC\u30D7\u30FB\u5468\u671F\u3001max_step \u306E\u5883\u754C\
    \u3002\nmax_step \u306E check \u306F\u3001\u5358\u8ABF\u306A\u300E\u7D2F\u7A4D\
    \u6587\u5B57\u6570/\u975E\u8CA0\u91CD\u307F\u304C\u4E0A\u9650\u4EE5\u4E0B\u300F\
    \u306E\u307F\u3092\u4F7F\u3046\u3002\nto=-1 \u306E\u5834\u5408\u306F add \u306B\
    \u6052\u7B49\u5143\u3092\u6E21\u3059\uFF08\u516C\u958B\u30B3\u30E1\u30F3\u30C8\
    \u306E\u300Cadd \u4E0D\u8981\u300D\u306B\u5F93\u3046\uFF09\u3002\nLOG=11 \u3067\
    \ step < 2048\u3001\u4E71\u629Eseed=0xD0B11A20261118ULL\u3002\n*/\n\nstruct Word_Monoid\
    \ {\n  using value_type = string;\n  static string id() { return \"\"; }\n  static\
    \ string op(const string& a, const string& b) { return a + b; }\n};\n\n[[noreturn]]\
    \ static void fail(int trial, int query, int start, int step,\n              \
    \                const string& name) {\n  cerr << \"doubling mismatch trial=\"\
    \ << trial << \" query=\" << query\n       << \" start=\" << start << \" step=\"\
    \ << step << \" \" << name << '\\n';\n  abort();\n}\n\nint main() {\n  constexpr\
    \ int LOG = 11;\n  constexpr int LIMIT = (1 << LOG) - 1;\n  mt19937_64 rng(0xD0B11A20261118ULL);\n\
    \  int queries = 0;\n  for (int trial = 0; trial < 25; ++trial) {\n    int n =\
    \ (trial == 0 ? 0 : trial == 1 ? 1 : trial == 2 ? 2\n             : trial == 3\
    \ ? 31 : trial == 4 ? 64 : int(rng() % 80) + 1);\n    Doubling<Word_Monoid, LOG>\
    \ dw(n);\n    Doubling<Monoid_Add<ll>, LOG> ds(n);\n    vector<int> nx(n, -1);\n\
    \    vector<string> word(n);\n    vector<ll> cost(n);\n    for (int i = 0; i <\
    \ n; ++i) {\n      // \u4E00\u90E8\u306F add \u305B\u305A\u3001\u30C7\u30D5\u30A9\
    \u30EB\u30C8\u306E -1 \u9077\u79FB\u3092\u78BA\u304B\u3081\u308B\u3002\n     \
    \ if (rng() % 11 == 0) continue;\n      int to = (rng() % 5 == 0 ? -1 : int(rng()\
    \ % n));\n      nx[i] = to;\n      if (to >= 0) {\n        word[i] = \"{\" + to_string(i)\
    \ + \"}\";  // \u9802\u70B9\u3054\u3068\u306B\u7570\u306A\u308B\u975E\u53EF\u63DB\
    \u306A\u8981\u7D20\n        cost[i] = 1 + ll(rng() % 7);\n      }\n      dw.add(i,\
    \ to, word[i]);\n      ds.add(i, to, cost[i]);\n    }\n    dw.build(); ds.build();\n\
    \    if (!n) continue;\n\n    auto slow = [&](int start, int steps) -> tuple<int,\
    \ string, ll> {\n      string s;\n      ll w = 0;\n      int at = start;\n   \
    \   for (int t = 0; t < steps && at != -1; ++t) {\n        int old = at;\n   \
    \     at = nx[old];\n        if (at == -1) break;\n        s += word[old];\n \
    \       w += cost[old];\n      }\n      return {at, s, w};\n    };\n    auto slow_max\
    \ = [&](int start, int letters, ll budget, bool by_weight) {\n      string s;\n\
    \      ll w = 0;\n      int at = start, answer = 0;\n      for (int step = 0;\
    \ step < LIMIT; ++step) {\n        int nxt = nx[at];\n        if (nxt == -1) break;\n\
    \        if (by_weight && w + cost[at] > budget) break;\n        if (!by_weight\
    \ && int(s.size() + word[at].size()) > letters) break;\n        s += word[at];\n\
    \        w += cost[at];\n        at = nxt;\n        ++answer;\n      }\n     \
    \ return answer;\n    };\n\n    for (int query = 0; query < 250; ++query) {\n\
    \      int i = int(rng() % n);\n      const int fixed[] = {0,1,2,3,7,8,15,16,31,32,63,64,127,128,\n\
    \                           255,256,511,512,1023,1024,2046,2047};\n      int step\
    \ = query < int(size(fixed)) ? fixed[query] : int(rng() % 2048);\n      auto [expected_at,\
    \ expected_word, expected_sum] = slow(i, step);\n      auto got_word = dw.calc(i,\
    \ step);\n      auto got_sum = ds.calc(i, step);\n      if (got_word.first !=\
    \ expected_at || got_word.second != expected_word)\n        fail(trial, query,\
    \ i, step, \"calc word\");\n      if (got_sum.first != expected_at || got_sum.second\
    \ != expected_sum)\n        fail(trial, query, i, step, \"calc sum\");\n\n   \
    \   // 2\u3064\u306E\u72EC\u7ACB\u3057\u305F\u5358\u8ABF\u6761\u4EF6\u306B\u5BFE\
    \u3057\u3066\u3001\u9650\u754C\u6B69\u6570\u3092\u5168\u9010\u6B21\u8D70\u67FB\
    \u3067\u7167\u5408\u3002\n      const int letter_bound = int(rng() % 80);\n  \
    \    const ll budget = ll(rng() % 80);\n      auto check_word = [&](int, const\
    \ string& s) { return int(s.size()) <= letter_bound; };\n      auto check_cost\
    \ = [&](int, ll w) { return w <= budget; };\n      auto k_word = dw.max_step(check_word,\
    \ i);\n      auto k_sum = ds.max_step(check_cost, i);\n      if (k_word != slow_max(i,\
    \ letter_bound, 0, false))\n        fail(trial, query, i, step, \"max_step word\"\
    );\n      if (k_sum != slow_max(i, 0, budget, true))\n        fail(trial, query,\
    \ i, step, \"max_step sum\");\n      ++queries;\n    }\n  }\n  cerr << \"PASS\
    \ doubling \" << queries << \" queries\\n\";\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/doubling.hpp\"\
    \n\n/*\n\u5BFE\u8C61: ds/doubling.hpp \u306E Doubling::add, build, calc, max_step\u3002\
    \n\u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB: next \u914D\u5217\u3092\u4E00\u6B69\u305A\
    \u3064\u8FBF\u308A\u3001\u6587\u5B57\u5217\u9023\u7D50\u30FB\u91CD\u307F\u548C\
    \u3092\u9010\u6B21\u8A08\u7B97\u3002\n\u72D9\u3046\u4E0D\u5177\u5408: 2\u51AA\u306E\
    \u5883\u754C\u3001bit \u3092\u4E0A\u4F4D\u304B\u3089\u51E6\u7406\u3059\u308B\u3068\
    \u304D\u306E\u975E\u53EF\u63DB\u306A\u7A4D\u306E\u9806\u5E8F\u3001\n\u9077\u79FB\
    \u5148 -1 \u306E\u505C\u6B62\u51E6\u7406\u3001\u672A\u767B\u9332\u9077\u79FB\u3001\
    \u81EA\u5DF1\u30EB\u30FC\u30D7\u30FB\u5468\u671F\u3001max_step \u306E\u5883\u754C\
    \u3002\nmax_step \u306E check \u306F\u3001\u5358\u8ABF\u306A\u300E\u7D2F\u7A4D\
    \u6587\u5B57\u6570/\u975E\u8CA0\u91CD\u307F\u304C\u4E0A\u9650\u4EE5\u4E0B\u300F\
    \u306E\u307F\u3092\u4F7F\u3046\u3002\nto=-1 \u306E\u5834\u5408\u306F add \u306B\
    \u6052\u7B49\u5143\u3092\u6E21\u3059\uFF08\u516C\u958B\u30B3\u30E1\u30F3\u30C8\
    \u306E\u300Cadd \u4E0D\u8981\u300D\u306B\u5F93\u3046\uFF09\u3002\nLOG=11 \u3067\
    \ step < 2048\u3001\u4E71\u629Eseed=0xD0B11A20261118ULL\u3002\n*/\n\nstruct Word_Monoid\
    \ {\n  using value_type = string;\n  static string id() { return \"\"; }\n  static\
    \ string op(const string& a, const string& b) { return a + b; }\n};\n\n[[noreturn]]\
    \ static void fail(int trial, int query, int start, int step,\n              \
    \                const string& name) {\n  cerr << \"doubling mismatch trial=\"\
    \ << trial << \" query=\" << query\n       << \" start=\" << start << \" step=\"\
    \ << step << \" \" << name << '\\n';\n  abort();\n}\n\nint main() {\n  constexpr\
    \ int LOG = 11;\n  constexpr int LIMIT = (1 << LOG) - 1;\n  mt19937_64 rng(0xD0B11A20261118ULL);\n\
    \  int queries = 0;\n  for (int trial = 0; trial < 25; ++trial) {\n    int n =\
    \ (trial == 0 ? 0 : trial == 1 ? 1 : trial == 2 ? 2\n             : trial == 3\
    \ ? 31 : trial == 4 ? 64 : int(rng() % 80) + 1);\n    Doubling<Word_Monoid, LOG>\
    \ dw(n);\n    Doubling<Monoid_Add<ll>, LOG> ds(n);\n    vector<int> nx(n, -1);\n\
    \    vector<string> word(n);\n    vector<ll> cost(n);\n    for (int i = 0; i <\
    \ n; ++i) {\n      // \u4E00\u90E8\u306F add \u305B\u305A\u3001\u30C7\u30D5\u30A9\
    \u30EB\u30C8\u306E -1 \u9077\u79FB\u3092\u78BA\u304B\u3081\u308B\u3002\n     \
    \ if (rng() % 11 == 0) continue;\n      int to = (rng() % 5 == 0 ? -1 : int(rng()\
    \ % n));\n      nx[i] = to;\n      if (to >= 0) {\n        word[i] = \"{\" + to_string(i)\
    \ + \"}\";  // \u9802\u70B9\u3054\u3068\u306B\u7570\u306A\u308B\u975E\u53EF\u63DB\
    \u306A\u8981\u7D20\n        cost[i] = 1 + ll(rng() % 7);\n      }\n      dw.add(i,\
    \ to, word[i]);\n      ds.add(i, to, cost[i]);\n    }\n    dw.build(); ds.build();\n\
    \    if (!n) continue;\n\n    auto slow = [&](int start, int steps) -> tuple<int,\
    \ string, ll> {\n      string s;\n      ll w = 0;\n      int at = start;\n   \
    \   for (int t = 0; t < steps && at != -1; ++t) {\n        int old = at;\n   \
    \     at = nx[old];\n        if (at == -1) break;\n        s += word[old];\n \
    \       w += cost[old];\n      }\n      return {at, s, w};\n    };\n    auto slow_max\
    \ = [&](int start, int letters, ll budget, bool by_weight) {\n      string s;\n\
    \      ll w = 0;\n      int at = start, answer = 0;\n      for (int step = 0;\
    \ step < LIMIT; ++step) {\n        int nxt = nx[at];\n        if (nxt == -1) break;\n\
    \        if (by_weight && w + cost[at] > budget) break;\n        if (!by_weight\
    \ && int(s.size() + word[at].size()) > letters) break;\n        s += word[at];\n\
    \        w += cost[at];\n        at = nxt;\n        ++answer;\n      }\n     \
    \ return answer;\n    };\n\n    for (int query = 0; query < 250; ++query) {\n\
    \      int i = int(rng() % n);\n      const int fixed[] = {0,1,2,3,7,8,15,16,31,32,63,64,127,128,\n\
    \                           255,256,511,512,1023,1024,2046,2047};\n      int step\
    \ = query < int(size(fixed)) ? fixed[query] : int(rng() % 2048);\n      auto [expected_at,\
    \ expected_word, expected_sum] = slow(i, step);\n      auto got_word = dw.calc(i,\
    \ step);\n      auto got_sum = ds.calc(i, step);\n      if (got_word.first !=\
    \ expected_at || got_word.second != expected_word)\n        fail(trial, query,\
    \ i, step, \"calc word\");\n      if (got_sum.first != expected_at || got_sum.second\
    \ != expected_sum)\n        fail(trial, query, i, step, \"calc sum\");\n\n   \
    \   // 2\u3064\u306E\u72EC\u7ACB\u3057\u305F\u5358\u8ABF\u6761\u4EF6\u306B\u5BFE\
    \u3057\u3066\u3001\u9650\u754C\u6B69\u6570\u3092\u5168\u9010\u6B21\u8D70\u67FB\
    \u3067\u7167\u5408\u3002\n      const int letter_bound = int(rng() % 80);\n  \
    \    const ll budget = ll(rng() % 80);\n      auto check_word = [&](int, const\
    \ string& s) { return int(s.size()) <= letter_bound; };\n      auto check_cost\
    \ = [&](int, ll w) { return w <= budget; };\n      auto k_word = dw.max_step(check_word,\
    \ i);\n      auto k_sum = ds.max_step(check_cost, i);\n      if (k_word != slow_max(i,\
    \ letter_bound, 0, false))\n        fail(trial, query, i, step, \"max_step word\"\
    );\n      if (k_sum != slow_max(i, 0, budget, true))\n        fail(trial, query,\
    \ i, step, \"max_step sum\");\n      ++queries;\n    }\n  }\n  cerr << \"PASS\
    \ doubling \" << queries << \" queries\\n\";\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/doubling.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/doubling_noncommutative.test.cpp
  requiredBy: []
  timestamp: '2026-11-18 16:45:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/doubling_noncommutative.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/doubling_noncommutative.test.cpp
- /verify/test/5_ai_generated_test/doubling_noncommutative.test.cpp.html
title: test/5_ai_generated_test/doubling_noncommutative.test.cpp
---
