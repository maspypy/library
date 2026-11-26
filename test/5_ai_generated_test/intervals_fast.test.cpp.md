---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':heavy_check_mark:'
    path: ds/intervals.hpp
    title: ds/intervals.hpp
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 1 \"ds/intervals.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/intervals.hpp\n\
    #line 1 \"ds/fastset.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/fastset.hpp\n\
    // 64-ary tree\n// space: (N/63) * u64\nstruct FastSet {\n  static constexpr u32\
    \ B = 64;\n  int n = 0, log = 0;\n  vvc<u64> seg;\n\n  FastSet() {}\n  FastSet(int\
    \ n) { build(n); }\n\n  int size() { return n; }\n\n  void fill_one() {\n    int\
    \ cur = n;\n    for (auto& vs : seg) {\n      int p = cur / B, q = cur % B;\n\
    \      FOR(i, p) vs[i] = -1ull;\n      if (q) vs[p] = full_mask(q);\n      cur\
    \ = (cur + B - 1) / B;\n    }\n  }\n\n  template <typename F>\n  FastSet(int n,\
    \ F f) {\n    build(n, f);\n  }\n\n  void build(int m) {\n    seg.clear();\n \
    \   n = m;\n    do {\n      seg.push_back(vc<u64>((m + B - 1) / B));\n      m\
    \ = (m + B - 1) / B;\n    } while (m > 1);\n    log = len(seg);\n  }\n  template\
    \ <typename F>\n  void build(int n, F f) {\n    build(n);\n    FOR(i, n) { seg[0][i\
    \ / B] |= u64(bool(f(i))) << (i % B); }\n    FOR(h, log - 1) {\n      FOR(i, len(seg[h]))\
    \ {\n        seg[h + 1][i / B] |= u64(bool(seg[h][i])) << (i % B);\n      }\n\
    \    }\n  }\n\n  bool operator[](int i) const {\n    assert(0 <= i && i < n);\n\
    \    return seg[0][i / B] >> (i % B) & 1;\n  }\n  void insert(int i) {\n    assert(0\
    \ <= i && i < n);\n    for (int h = 0; h < log; h++) {\n      u64& x = seg[h][i\
    \ / B];\n      u64 mask = u64(1) << (i % B);\n      if (x & mask) return;\n  \
    \    x |= mask;\n      i /= B;\n    }\n  }\n  void add(int i) { insert(i); }\n\
    \  void erase(int i) {\n    assert(0 <= i && i < n);\n    for (int h = 0; h <\
    \ log; h++) {\n      u64& x = seg[h][i / B];\n      u64 mask = u64(1) << (i %\
    \ B);\n      if (!(x & mask)) return;\n      x ^= mask;\n      if (x) return;\n\
    \      i /= B;\n    }\n  }\n  void remove(int i) { erase(i); }\n\n  // min[x,n)\
    \ or n\n  int next(int i) {\n    assert(i <= n);\n    chmax(i, 0);\n    for (int\
    \ h = 0; h < log; h++) {\n      if (i / B == seg[h].size()) break;\n      u64\
    \ d = seg[h][i / B] >> (i % B);\n      if (!d) {\n        i = i / B + 1;\n   \
    \     continue;\n      }\n      i += lowbit(d);\n      for (int g = h - 1; g >=\
    \ 0; g--) {\n        i *= B;\n        i += lowbit(seg[g][i / B]);\n      }\n \
    \     return i;\n    }\n    return n;\n  }\n\n  // max [0,x], or -1\n  int prev(int\
    \ i) {\n    assert(i >= -1);\n    if (i >= n) i = n - 1;\n    for (int h = 0;\
    \ h < log; h++) {\n      if (i == -1) break;\n      u64 d = seg[h][i / B] << (63\
    \ - i % B);\n      if (!d) {\n        i = i / B - 1;\n        continue;\n    \
    \  }\n      i -= __builtin_clzll(d);\n      for (int g = h - 1; g >= 0; g--) {\n\
    \        i *= B;\n        i += topbit(seg[g][i / B]);\n      }\n      return i;\n\
    \    }\n    return -1;\n  }\n\n  bool any(int l, int r) {\n    assert(0 <= l &&\
    \ l <= r && r <= n);\n    return next(l) < r;\n  }\n\n  // [l, r). erase=true\
    \ \u306E\u3068\u304D\u3001callback \u5185\u304B\u3089 this \u3092\u5909\u66F4\u3057\
    \u3066\u306F\u3044\u3051\u306A\u3044\u3002\n  template <typename F>\n  void enumerate(int\
    \ l, int r, F f, bool erase = false) {\n    bool end = false;\n    assert(0 <=\
    \ l && l <= r && r <= n);\n    if (!erase) {\n      for (int x = next(l); x <\
    \ r; x = next(x + 1)) {\n        f(x, end);\n        if (end) return;\n      }\n\
    \      return;\n    }\n    for (int x = next(l); x < r;) {\n      int w = x /\
    \ B;\n      int lo = max(l, w * int(B)) - w * int(B);\n      int hi = min(r, (w\
    \ + 1) * int(B)) - w * int(B);\n      u64 erase_bits = seg[0][w] & (full_mask(hi)\
    \ & ~full_mask(lo));\n      u64 bits = erase_bits;\n      while (bits) {\n   \
    \     int k = lowbit(bits);\n        f(w * int(B) + k, end);\n        bits ^=\
    \ u64(1) << k;\n        assert(!end);  // \u672A\u5BFE\u5FDC\n      }\n      seg[0][w]\
    \ ^= erase_bits;\n      if (!seg[0][w]) propagate_empty_word(w);\n      x = next(min(r,\
    \ (w + 1) * int(B)));\n    }\n  }\n\n  void reset() {\n    int x = next(0);\n\
    \    while (x < n) {\n      int w = x / B;\n      seg[0][w] = 0;\n      propagate_empty_word(w);\n\
    \      x = next(min(n, (w + 1) * int(B)));\n    }\n  }\n\n  string to_string()\
    \ {\n    string s(n, '?');\n    for (int i = 0; i < n; ++i) s[i] = ((*this)[i]\
    \ ? '1' : '0');\n    return s;\n  }\n\n private:\n  // seg[0][w] \u304C 0 \u306B\
    \u306A\u3063\u305F\u5F8C\u306B\u547C\u3076\u3002\n  void propagate_empty_word(int\
    \ i) {\n    for (int h = 1; h < log; ++h) {\n      u64& y = seg[h][i / B];\n \
    \     u64 mask = u64(1) << (i % B);\n      y ^= mask;\n      if (y) break;\n \
    \     i /= B;\n    }\n  }\n};\n#line 3 \"ds/intervals.hpp\"\n\n// FastSet \u3067\
    \u9AD8\u901F\u5316\u3057\u305F\u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast\
    \ {\n  const int LLIM, RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\
    \u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n\
    \  int total_len;\n  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n\
    \      : LLIM(0),\n        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n\
    \        total_len(0),\n        dat(N, none_val),\n        ss(N) {\n    ss.insert(0);\n\
    \  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\u60C5\u5831\u306E\u53D6\u5F97\
    \ l, r, t\n  tuple<int, int, T> get(int x, bool ERASE = false) {\n    int l =\
    \ ss.prev(x);\n    int r = ss.next(x + 1);\n    T t = dat[l];\n    if (t != none_val\
    \ && ERASE) {\n      --total_num, total_len -= r - l;\n      dat[l] = none_val;\n\
    \      merge_at(l);\n      merge_at(r);\n    }\n    return {l, r, t};\n  }\n\n\
    \  // [L, R) \u5185\u306E\u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97\n  // f(l,r,x)\n\
    \  template <typename F>\n  void enumerate_range(int L, int R, F f, bool ERASE\
    \ = false) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n\
    \    bool end = false;\n    if (!ERASE) {\n      int l = ss.prev(L);\n      while\
    \ (l < R) {\n        int r = ss.next(l + 1);\n        f(max(l, L), min(r, R),\
    \ dat[l], end);\n        if (end) return;\n        l = r;\n      }\n      return;\n\
    \    }\n    // \u534A\u7AEF\u306A\u3068\u3053\u308D\u306E\u5206\u5272\n    int\
    \ p = ss.prev(L);\n    if (p < L) {\n      ss.insert(L);\n      dat[L] = dat[p];\n\
    \      if (dat[L] != none_val) ++total_num;\n    }\n    p = ss.next(R);\n    if\
    \ (R < p) {\n      dat[R] = dat[ss.prev(R)];\n      ss.insert(R);\n      if (dat[R]\
    \ != none_val) ++total_num;\n    }\n    p = L;\n    while (p < R) {\n      int\
    \ q = ss.next(p + 1);\n      T x = dat[p];\n      f(p, q, x, end);\n      assert(!end);\
    \  // \u672A\u5BFE\u5FDC\n      if (dat[p] != none_val) --total_num, total_len\
    \ -= q - p;\n      ss.erase(p);\n      p = q;\n    }\n    ss.insert(L);\n    dat[L]\
    \ = none_val;\n  }\n\n  void set(int L, int R, T t) {\n    if (L == R) return;\n\
    \    enumerate_range(L, R, [](int l, int r, T x, bool) -> void {}, true);\n  \
    \  ss.insert(L);\n    dat[L] = t;\n    if (t != none_val) total_num++, total_len\
    \ += R - L;\n    merge_at(L);\n    merge_at(R);\n  }\n\n  template <typename F>\n\
    \  void enumerate_all(F f) {\n    enumerate_range(0, RLIM, f, false);\n  }\n\n\
    \  void merge_at(int p) {\n    if (p <= 0 || RLIM <= p) return;\n    int q = ss.prev(p\
    \ - 1);\n    if (dat[p] == dat[q]) {\n      if (dat[p] != none_val) --total_num;\n\
    \      ss.erase(p);\n    }\n  }\n\n  vc<T> get_all() {\n    vc<T> res(RLIM, none_val);\n\
    \    enumerate_all([&](int a, int b, T t, bool) -> void {\n      FOR(i, a, b)\
    \ res[i] = t;\n    });\n    return res;\n  }\n};\n\n// https://codeforces.com/contest/1638/problem/E\n\
    // \u6301\u3064\u5024\u306E\u30BF\u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7\
    \ X\n// \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\
    \u6307\u5B9A\u3059\u308B\n// \u5148\u8AAD\u307F\u53EF\u80FD\u306A\u3089\u5EA7\u5727\
    \u3057\u3066 fastset \u306E\u65B9\u304C\u901F\u3044\ntemplate <typename T, typename\
    \ X = ll>\nstruct Intervals {\n  static constexpr X LLIM = -infty<X>;\n  static\
    \ constexpr X RLIM = infty<X>;\n  T none_val;\n  // const T none_val;\n  // none_val\
    \ \u3067\u306A\u3044\u533A\u9593\u306E\u500B\u6570\u3068\u9577\u3055\u5408\u8A08\
    \n  int total_num;\n  X total_len;\n  map<X, T> dat;\n\n  Intervals(T none_val\
    \ = 0) : none_val(none_val), total_num(0), total_len(0) {\n    dat[LLIM] = none_val;\n\
    \    dat[RLIM] = none_val;\n  }\n\n  // x \u3092\u542B\u3080\u533A\u9593\u306E\
    \u60C5\u5831\u306E\u53D6\u5F97 l, r, t\n  tuple<X, X, T> get(X x, bool ERASE =\
    \ false) {\n    auto it2 = dat.upper_bound(x);\n    auto it1 = prev(it2);\n  \
    \  auto [l, tl] = *it1;\n    auto [r, tr] = *it2;\n    if (tl != none_val && ERASE)\
    \ {\n      --total_num, total_len -= r - l;\n      dat[l] = none_val;\n      merge_at(l);\n\
    \      merge_at(r);\n    }\n    return {l, r, tl};\n  }\n\n  // [L, R) \u5185\u306E\
    \u5168\u30C7\u30FC\u30BF\u306E\u53D6\u5F97 f(l, r, t, end)\n  template <typename\
    \ F>\n  void enumerate_range(X L, X R, F f, bool ERASE = false) {\n    assert(LLIM\
    \ <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n    bool end = false;\n\
    \    if (!ERASE) {\n      auto it = prev(dat.upper_bound(L));\n      while ((*it).fi\
    \ < R) {\n        auto it2 = next(it);\n        f(max((*it).fi, L), min((*it2).fi,\
    \ R), (*it).se, end);\n        it = it2;\n        if (end) break;\n      }\n \
    \     return;\n    }\n    // \u534A\u7AEF\u306A\u3068\u3053\u308D\u306E\u5206\u5272\
    \n    auto p = prev(dat.upper_bound(L));\n    if ((*p).fi < L) {\n      dat[L]\
    \ = (*p).se;\n      if (dat[L] != none_val) ++total_num;\n    }\n    p = dat.lower_bound(R);\n\
    \    if (R < (*p).fi) {\n      T t = (*prev(p)).se;\n      dat[R] = t;\n     \
    \ if (t != none_val) ++total_num;\n    }\n    p = dat.lower_bound(L);\n    while\
    \ (1) {\n      if ((*p).fi >= R) break;\n      auto q = next(p);\n      T t =\
    \ (*p).se;\n      f((*p).fi, (*q).fi, t, end);\n      assert(!end);  // \u672A\
    \u5BFE\u5FDC\n      if (t != none_val) --total_num, total_len -= (*q).fi - (*p).fi;\n\
    \      p = dat.erase(p);\n    }\n    dat[L] = none_val;\n  }\n\n  void set(X L,\
    \ X R, T t) {\n    assert(L <= R);\n    if (L == R) return;\n    enumerate_range(L,\
    \ R, [](int l, int r, T x, bool) -> void {}, true);\n    dat[L] = t;\n    if (t\
    \ != none_val) total_num++, total_len += R - L;\n    merge_at(L);\n    merge_at(R);\n\
    \  }\n\n  template <typename F>\n  void enumerate_all(F f) {\n    enumerate_range(LLIM,\
    \ RLIM, f, false);\n  }\n\n  void merge_at(X p) {\n    if (p == LLIM || RLIM ==\
    \ p) return;\n    auto itp = dat.lower_bound(p);\n    assert((*itp).fi == p);\n\
    \    auto itq = prev(itp);\n    if ((*itp).se == (*itq).se) {\n      if ((*itp).se\
    \ != none_val) --total_num;\n      dat.erase(itp);\n    }\n  }\n};\n#line 4 \"\
    test/5_ai_generated_test/intervals_fast.test.cpp\"\n\n// \u5BFE\u8C61: ds/intervals.hpp\
    \ \u306E Intervals_Fast<long long>\u3002\n// \u73FE\u884C API \u306E set, get\uFF08\
    ERASE=true/false\uFF09, get_all, enumerate_range,\n// enumerate_all, total_num,\
    \ total_len \u3092\u691C\u8A3C\u3059\u308B\u3002\n//\n// \u72EC\u7ACB oracle:\
    \ \u5404\u5EA7\u6A19\u306E\u5024\u3092\u305D\u306E\u307E\u307E vector \u306B\u4FDD\
    \u6301\u3059\u308B\u3002\n// \u96A3\u63A5\u3059\u308B\u540C\u5024\u8981\u7D20\u3092\
    \u307E\u3068\u3081\u305F\u6975\u5927\u533A\u9593\u304C enumerate/get \u306E\u671F\
    \u5F85\u5024\u3068\u306A\u308B\u3002\n// \u4EE3\u5165\u30FB\u524A\u9664\u5F8C\u306E\
    \u533A\u9593\u6570\u3068\u975E none \u306E\u9577\u3055\u5408\u8A08\u3082\u3001\
    \u914D\u5217\u304B\u3089\u518D\u8A08\u7B97\u3059\u308B\u3002\n//\n// \u72D9\u3046\
    \u4E0D\u5177\u5408: \u534A\u958B\u533A\u9593\u306E off-by-one\u3001\u5DE6\u53F3\
    \u5883\u754C\u3067\u306E\u5206\u5272\u30FB\u4F75\u5408\u6F0F\u308C\u3001\n// none_val\
    \ \u3078\u306E\u4EE3\u5165\u3084 get(...,true) \u306B\u3088\u308B\u533A\u9593\u6D88\
    \u53BB\u5F8C\u306E\u96C6\u8A08\u5024\u7834\u640D\u3001\n// FastSet \u306E 64 \u8981\
    \u7D20\u5883\u754C\u3092\u307E\u305F\u3050\u533A\u9593\u306E\u5217\u6319\u6F0F\
    \u308C\u3001\u65E9\u671F\u7D42\u4E86\u306E\u8AA4\u52D5\u4F5C\u3002\n// N=0 \u3067\
    \u306E\u69CB\u7BC9\u306F\u5148\u982D\u306B\u5883\u754C 0 \u3092\u633F\u5165\u3059\
    \u308B\u5B9F\u88C5\u306E\u5BFE\u8C61\u5916\u3068\u3057\u3001N>=1 \u306E\u307F\u8A66\
    \u3059\u3002\n// \u4E71\u6570\u306F mt19937_64 \u306E\u56FA\u5B9A seed 0x1A7E4A15ULL\
    \ \u3092\u4F7F\u7528\u3057\u3001CI\u3067\u518D\u73FE\u53EF\u80FD\u3002\n\nnamespace\
    \ {\nusing i64 = long long;\nusing Run = tuple<int, int, i64>;\nconstexpr i64\
    \ NONE = -(1LL << 50);\n\n[[noreturn]] void fail(int n, int step, const string&\
    \ op, const string& why) {\n  cerr << \"Intervals_Fast FAILED: n=\" << n << \"\
    \ step=\" << step << \" op=\" << op\n       << \" reason=\" << why << '\\n';\n\
    \  abort();\n}\n\nstruct Tester {\n  int n;\n  int step = 0;\n  string op = \"\
    initial\";\n  vector<i64> a;\n  Intervals_Fast<i64> ds;\n  mt19937_64& rng;\n\n\
    \  Tester(int n_, mt19937_64& rng_)\n      : n(n_), a(n_, NONE), ds(n_, NONE),\
    \ rng(rng_) {\n    check();\n  }\n\n  void require(bool p, const string& message)\
    \ {\n    if (!p) fail(n, step, op, message);\n  }\n\n  vector<Run> runs() const\
    \ {\n    vector<Run> result;\n    for (int l = 0; l < n;) {\n      int r = l +\
    \ 1;\n      while (r < n && a[r] == a[l]) ++r;\n      result.emplace_back(l, r,\
    \ a[l]);\n      l = r;\n    }\n    return result;\n  }\n\n  void check() {\n \
    \   const auto expected = runs();\n    int expected_num = 0, expected_len = 0;\n\
    \    for (const auto& [l, r, x] : expected) {\n      if (x != NONE) {\n      \
    \  ++expected_num;\n        expected_len += r - l;\n      }\n    }\n    require(ds.total_num\
    \ == expected_num, \"total_num\");\n    require(ds.total_len == expected_len,\
    \ \"total_len\");\n    require(ds.get_all() == a, \"get_all\");\n\n    vector<Run>\
    \ actual;\n    ds.enumerate_all([&](int l, int r, i64 x, bool& end) {\n      require(!end,\
    \ \"unexpected end flag in enumerate_all\");\n      actual.emplace_back(l, r,\
    \ x);\n    });\n    require(\n        actual == expected, \"enumerate_all: maximal\
    \ intervals / boundaries\");\n\n    // \u5168\u5EA7\u6A19\u3067 get \u306E\u8FD4\
    \u3059\u533A\u9593\u304C\u6975\u5927\u3067\u3042\u308B\u3053\u3068\u3092\u691C\
    \u67FB\u3059\u308B\u3002\n    for (const auto& [l, r, x] : expected) {\n     \
    \ for (int i = l; i < r; ++i) {\n        const auto got = ds.get(i);\n       \
    \ require(got == Run(l, r, x), \"get at i=\" + to_string(i));\n      }\n    }\n\
    \n    // [L,R) \u306E\u7AEF\u70B9\u3001L==R\u3001\u975E\u6574\u5217\u533A\u9593\
    \u3001\u304A\u3088\u3073\u65E9\u671F\u7D42\u4E86\u3092\u691C\u67FB\u3059\u308B\
    \u3002\n    const int L = int(rng() % (n + 1));\n    const int R = L + int(rng()\
    \ % (n - L + 1));\n    vector<Run> clipped;\n    for (const auto& [l, r, x] :\
    \ expected) {\n      if (max(l, L) < min(r, R)) {\n        clipped.emplace_back(max(l,\
    \ L), min(r, R), x);\n      }\n    }\n    vector<Run> got;\n    ds.enumerate_range(L,\
    \ R, [&](int l, int r, i64 x, bool& end) {\n      require(!end, \"unexpected end\
    \ flag in enumerate_range\");\n      got.emplace_back(l, r, x);\n    });\n   \
    \ require(got == clipped,\n        \"enumerate_range [\" + to_string(L) + \",\"\
    \ + to_string(R) + \")\");\n\n    got.clear();\n    const size_t limit = 1 + size_t(rng()\
    \ % 3);\n    ds.enumerate_range(L, R, [&](int l, int r, i64 x, bool& end) {\n\
    \      got.emplace_back(l, r, x);\n      if (got.size() == limit) end = true;\n\
    \    });\n    if (clipped.size() > limit) clipped.resize(limit);\n    require(got\
    \ == clipped, \"enumerate_range early termination\");\n  }\n\n  void set(int l,\
    \ int r, i64 x) {\n    op = \"set(\" + to_string(l) + \",\" + to_string(r) + \"\
    ,\" + to_string(x) + \")\";\n    ds.set(l, r, x);\n    for (int i = l; i < r;\
    \ ++i) a[i] = x;\n    ++step;\n    check();\n  }\n\n  void get_and_maybe_erase(int\
    \ i, bool erase) {\n    op = \"get(\" + to_string(i) + \",ERASE=\" + to_string(erase)\
    \ + \")\";\n    int l = i, r = i + 1;\n    while (l > 0 && a[l - 1] == a[i]) --l;\n\
    \    while (r < n && a[r] == a[i]) ++r;\n    const i64 old = a[i];\n    const\
    \ auto got = ds.get(i, erase);\n    require(got == Run(l, r, old), \"returned\
    \ interval before erase\");\n    if (erase && old != NONE) {\n      for (int j\
    \ = l; j < r; ++j) a[j] = NONE;\n    }\n    ++step;\n    check();\n  }\n};\n\n\
    void run_case(int n, mt19937_64& rng) {\n  Tester t(n, rng);\n  const i64 V[]\
    \ = {NONE, -1000000000000LL, -17, -1, 0, 1, 17, 1000000000000LL};\n  auto pick\
    \ = [&]() -> i64 { return V[rng() % (sizeof(V) / sizeof(V[0]))]; };\n\n  // \u540C\
    \u3058\u5024\u306E\u518D\u4EE3\u5165\u3001\u5168\u9762\u6D88\u53BB\u3001\u7247\
    \u5074\u5883\u754C\u3001\u7A7A\u533A\u9593\u3092\u660E\u793A\u7684\u306B\u8E0F\
    \u3080\u3002\n  t.set(0, n, 17);\n  t.set(0, n, 17);\n  t.set(0, n, NONE);\n \
    \ t.set(0, 0, 1);\n  t.set(n, n, 1);\n  t.set(0, n, -17);\n  t.set(n / 4, (3 *\
    \ n) / 4, NONE);\n  t.set(n / 4, (3 * n) / 4, 0);\n  t.get_and_maybe_erase(n /\
    \ 2, true);\n  t.get_and_maybe_erase(n / 2, true);\n\n  // 64-ary FastSet \u306E\
    \u5358\u8A9E\u30FB\u968E\u5C64\u5883\u754C\u3067\u3001\u7D30\u304B\u306A\u533A\
    \u9593\u306E\u5206\u5272\u30FB\u518D\u7D50\u5408\u3092\u78BA\u8A8D\u3002\n  for\
    \ (int i : {0, 1, 62, 63, 64, 65, 126, 127, 128, 129, 190, 191, 192, 193,\n  \
    \         254, 255, 256}) {\n    if (i < n) t.set(i, i + 1, (i % 2 ? -1 : 1));\n\
    \  }\n  for (int i = 0; i < n; ++i) t.set(i, i + 1, (i % 2 ? 1 : 0));\n  t.get_and_maybe_erase(n\
    \ - 1, true);\n  t.get_and_maybe_erase(0, true);\n  t.set(0, n, NONE);\n\n  //\
    \ \u4E71\u629E\u306E\u533A\u9593\u4EE3\u5165\u30FB\u6975\u5927\u533A\u9593\u6D88\
    \u53BB\u30FB\u7167\u4F1A\u3092\u6DF7\u5728\u3055\u305B\u308B\u3002\n  for (int\
    \ rep = 0; rep < 850; ++rep) {\n    int kind = int(rng() % 12);\n    if (kind\
    \ <= 8) {\n      int l = int(rng() % (n + 1));\n      int r = int(rng() % (n +\
    \ 1));\n      if (l > r) swap(l, r);\n      if (kind == 0) l = 0;\n      if (kind\
    \ == 1) r = n;\n      if (kind == 2) r = l;\n      t.set(l, r, pick());\n    }\
    \ else {\n      const int i = int(rng() % n);\n      t.get_and_maybe_erase(i,\
    \ kind == 9 || kind == 10);\n    }\n  }\n}\n}  // namespace\n\nint main() {\n\
    \  mt19937_64 rng(0x1A7E4A15ULL);\n  for (int n : {1, 2, 3, 4, 7, 8, 9, 31, 32,\
    \ 33, 63, 64, 65, 66, 127, 128, 129,\n           191, 192, 193, 255, 256, 257})\
    \ {\n    run_case(n, rng);\n  }\n  cerr << \"PASS: Intervals_Fast independent\
    \ array oracle\\n\";\n  return 0;\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/intervals.hpp\"\
    \n\n// \u5BFE\u8C61: ds/intervals.hpp \u306E Intervals_Fast<long long>\u3002\n\
    // \u73FE\u884C API \u306E set, get\uFF08ERASE=true/false\uFF09, get_all, enumerate_range,\n\
    // enumerate_all, total_num, total_len \u3092\u691C\u8A3C\u3059\u308B\u3002\n\
    //\n// \u72EC\u7ACB oracle: \u5404\u5EA7\u6A19\u306E\u5024\u3092\u305D\u306E\u307E\
    \u307E vector \u306B\u4FDD\u6301\u3059\u308B\u3002\n// \u96A3\u63A5\u3059\u308B\
    \u540C\u5024\u8981\u7D20\u3092\u307E\u3068\u3081\u305F\u6975\u5927\u533A\u9593\
    \u304C enumerate/get \u306E\u671F\u5F85\u5024\u3068\u306A\u308B\u3002\n// \u4EE3\
    \u5165\u30FB\u524A\u9664\u5F8C\u306E\u533A\u9593\u6570\u3068\u975E none \u306E\
    \u9577\u3055\u5408\u8A08\u3082\u3001\u914D\u5217\u304B\u3089\u518D\u8A08\u7B97\
    \u3059\u308B\u3002\n//\n// \u72D9\u3046\u4E0D\u5177\u5408: \u534A\u958B\u533A\u9593\
    \u306E off-by-one\u3001\u5DE6\u53F3\u5883\u754C\u3067\u306E\u5206\u5272\u30FB\u4F75\
    \u5408\u6F0F\u308C\u3001\n// none_val \u3078\u306E\u4EE3\u5165\u3084 get(...,true)\
    \ \u306B\u3088\u308B\u533A\u9593\u6D88\u53BB\u5F8C\u306E\u96C6\u8A08\u5024\u7834\
    \u640D\u3001\n// FastSet \u306E 64 \u8981\u7D20\u5883\u754C\u3092\u307E\u305F\u3050\
    \u533A\u9593\u306E\u5217\u6319\u6F0F\u308C\u3001\u65E9\u671F\u7D42\u4E86\u306E\
    \u8AA4\u52D5\u4F5C\u3002\n// N=0 \u3067\u306E\u69CB\u7BC9\u306F\u5148\u982D\u306B\
    \u5883\u754C 0 \u3092\u633F\u5165\u3059\u308B\u5B9F\u88C5\u306E\u5BFE\u8C61\u5916\
    \u3068\u3057\u3001N>=1 \u306E\u307F\u8A66\u3059\u3002\n// \u4E71\u6570\u306F mt19937_64\
    \ \u306E\u56FA\u5B9A seed 0x1A7E4A15ULL \u3092\u4F7F\u7528\u3057\u3001CI\u3067\
    \u518D\u73FE\u53EF\u80FD\u3002\n\nnamespace {\nusing i64 = long long;\nusing Run\
    \ = tuple<int, int, i64>;\nconstexpr i64 NONE = -(1LL << 50);\n\n[[noreturn]]\
    \ void fail(int n, int step, const string& op, const string& why) {\n  cerr <<\
    \ \"Intervals_Fast FAILED: n=\" << n << \" step=\" << step << \" op=\" << op\n\
    \       << \" reason=\" << why << '\\n';\n  abort();\n}\n\nstruct Tester {\n \
    \ int n;\n  int step = 0;\n  string op = \"initial\";\n  vector<i64> a;\n  Intervals_Fast<i64>\
    \ ds;\n  mt19937_64& rng;\n\n  Tester(int n_, mt19937_64& rng_)\n      : n(n_),\
    \ a(n_, NONE), ds(n_, NONE), rng(rng_) {\n    check();\n  }\n\n  void require(bool\
    \ p, const string& message) {\n    if (!p) fail(n, step, op, message);\n  }\n\n\
    \  vector<Run> runs() const {\n    vector<Run> result;\n    for (int l = 0; l\
    \ < n;) {\n      int r = l + 1;\n      while (r < n && a[r] == a[l]) ++r;\n  \
    \    result.emplace_back(l, r, a[l]);\n      l = r;\n    }\n    return result;\n\
    \  }\n\n  void check() {\n    const auto expected = runs();\n    int expected_num\
    \ = 0, expected_len = 0;\n    for (const auto& [l, r, x] : expected) {\n     \
    \ if (x != NONE) {\n        ++expected_num;\n        expected_len += r - l;\n\
    \      }\n    }\n    require(ds.total_num == expected_num, \"total_num\");\n \
    \   require(ds.total_len == expected_len, \"total_len\");\n    require(ds.get_all()\
    \ == a, \"get_all\");\n\n    vector<Run> actual;\n    ds.enumerate_all([&](int\
    \ l, int r, i64 x, bool& end) {\n      require(!end, \"unexpected end flag in\
    \ enumerate_all\");\n      actual.emplace_back(l, r, x);\n    });\n    require(\n\
    \        actual == expected, \"enumerate_all: maximal intervals / boundaries\"\
    );\n\n    // \u5168\u5EA7\u6A19\u3067 get \u306E\u8FD4\u3059\u533A\u9593\u304C\
    \u6975\u5927\u3067\u3042\u308B\u3053\u3068\u3092\u691C\u67FB\u3059\u308B\u3002\
    \n    for (const auto& [l, r, x] : expected) {\n      for (int i = l; i < r; ++i)\
    \ {\n        const auto got = ds.get(i);\n        require(got == Run(l, r, x),\
    \ \"get at i=\" + to_string(i));\n      }\n    }\n\n    // [L,R) \u306E\u7AEF\u70B9\
    \u3001L==R\u3001\u975E\u6574\u5217\u533A\u9593\u3001\u304A\u3088\u3073\u65E9\u671F\
    \u7D42\u4E86\u3092\u691C\u67FB\u3059\u308B\u3002\n    const int L = int(rng()\
    \ % (n + 1));\n    const int R = L + int(rng() % (n - L + 1));\n    vector<Run>\
    \ clipped;\n    for (const auto& [l, r, x] : expected) {\n      if (max(l, L)\
    \ < min(r, R)) {\n        clipped.emplace_back(max(l, L), min(r, R), x);\n   \
    \   }\n    }\n    vector<Run> got;\n    ds.enumerate_range(L, R, [&](int l, int\
    \ r, i64 x, bool& end) {\n      require(!end, \"unexpected end flag in enumerate_range\"\
    );\n      got.emplace_back(l, r, x);\n    });\n    require(got == clipped,\n \
    \       \"enumerate_range [\" + to_string(L) + \",\" + to_string(R) + \")\");\n\
    \n    got.clear();\n    const size_t limit = 1 + size_t(rng() % 3);\n    ds.enumerate_range(L,\
    \ R, [&](int l, int r, i64 x, bool& end) {\n      got.emplace_back(l, r, x);\n\
    \      if (got.size() == limit) end = true;\n    });\n    if (clipped.size() >\
    \ limit) clipped.resize(limit);\n    require(got == clipped, \"enumerate_range\
    \ early termination\");\n  }\n\n  void set(int l, int r, i64 x) {\n    op = \"\
    set(\" + to_string(l) + \",\" + to_string(r) + \",\" + to_string(x) + \")\";\n\
    \    ds.set(l, r, x);\n    for (int i = l; i < r; ++i) a[i] = x;\n    ++step;\n\
    \    check();\n  }\n\n  void get_and_maybe_erase(int i, bool erase) {\n    op\
    \ = \"get(\" + to_string(i) + \",ERASE=\" + to_string(erase) + \")\";\n    int\
    \ l = i, r = i + 1;\n    while (l > 0 && a[l - 1] == a[i]) --l;\n    while (r\
    \ < n && a[r] == a[i]) ++r;\n    const i64 old = a[i];\n    const auto got = ds.get(i,\
    \ erase);\n    require(got == Run(l, r, old), \"returned interval before erase\"\
    );\n    if (erase && old != NONE) {\n      for (int j = l; j < r; ++j) a[j] =\
    \ NONE;\n    }\n    ++step;\n    check();\n  }\n};\n\nvoid run_case(int n, mt19937_64&\
    \ rng) {\n  Tester t(n, rng);\n  const i64 V[] = {NONE, -1000000000000LL, -17,\
    \ -1, 0, 1, 17, 1000000000000LL};\n  auto pick = [&]() -> i64 { return V[rng()\
    \ % (sizeof(V) / sizeof(V[0]))]; };\n\n  // \u540C\u3058\u5024\u306E\u518D\u4EE3\
    \u5165\u3001\u5168\u9762\u6D88\u53BB\u3001\u7247\u5074\u5883\u754C\u3001\u7A7A\
    \u533A\u9593\u3092\u660E\u793A\u7684\u306B\u8E0F\u3080\u3002\n  t.set(0, n, 17);\n\
    \  t.set(0, n, 17);\n  t.set(0, n, NONE);\n  t.set(0, 0, 1);\n  t.set(n, n, 1);\n\
    \  t.set(0, n, -17);\n  t.set(n / 4, (3 * n) / 4, NONE);\n  t.set(n / 4, (3 *\
    \ n) / 4, 0);\n  t.get_and_maybe_erase(n / 2, true);\n  t.get_and_maybe_erase(n\
    \ / 2, true);\n\n  // 64-ary FastSet \u306E\u5358\u8A9E\u30FB\u968E\u5C64\u5883\
    \u754C\u3067\u3001\u7D30\u304B\u306A\u533A\u9593\u306E\u5206\u5272\u30FB\u518D\
    \u7D50\u5408\u3092\u78BA\u8A8D\u3002\n  for (int i : {0, 1, 62, 63, 64, 65, 126,\
    \ 127, 128, 129, 190, 191, 192, 193,\n           254, 255, 256}) {\n    if (i\
    \ < n) t.set(i, i + 1, (i % 2 ? -1 : 1));\n  }\n  for (int i = 0; i < n; ++i)\
    \ t.set(i, i + 1, (i % 2 ? 1 : 0));\n  t.get_and_maybe_erase(n - 1, true);\n \
    \ t.get_and_maybe_erase(0, true);\n  t.set(0, n, NONE);\n\n  // \u4E71\u629E\u306E\
    \u533A\u9593\u4EE3\u5165\u30FB\u6975\u5927\u533A\u9593\u6D88\u53BB\u30FB\u7167\
    \u4F1A\u3092\u6DF7\u5728\u3055\u305B\u308B\u3002\n  for (int rep = 0; rep < 850;\
    \ ++rep) {\n    int kind = int(rng() % 12);\n    if (kind <= 8) {\n      int l\
    \ = int(rng() % (n + 1));\n      int r = int(rng() % (n + 1));\n      if (l >\
    \ r) swap(l, r);\n      if (kind == 0) l = 0;\n      if (kind == 1) r = n;\n \
    \     if (kind == 2) r = l;\n      t.set(l, r, pick());\n    } else {\n      const\
    \ int i = int(rng() % n);\n      t.get_and_maybe_erase(i, kind == 9 || kind ==\
    \ 10);\n    }\n  }\n}\n}  // namespace\n\nint main() {\n  mt19937_64 rng(0x1A7E4A15ULL);\n\
    \  for (int n : {1, 2, 3, 4, 7, 8, 9, 31, 32, 33, 63, 64, 65, 66, 127, 128, 129,\n\
    \           191, 192, 193, 255, 256, 257}) {\n    run_case(n, rng);\n  }\n  cerr\
    \ << \"PASS: Intervals_Fast independent array oracle\\n\";\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/intervals.hpp
  - ds/fastset.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/intervals_fast.test.cpp
  requiredBy: []
  timestamp: '2026-11-18 15:44:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/intervals_fast.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/intervals_fast.test.cpp
- /verify/test/5_ai_generated_test/intervals_fast.test.cpp.html
title: test/5_ai_generated_test/intervals_fast.test.cpp
---
