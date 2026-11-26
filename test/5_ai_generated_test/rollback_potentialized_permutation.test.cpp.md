---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/rollback_potentialized_unionfind.hpp
    title: ds/unionfind/rollback_potentialized_unionfind.hpp
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 3 \"test/5_ai_generated_test/rollback_potentialized_permutation.test.cpp\"\
    \n\n#line 1 \"ds/unionfind/rollback_potentialized_unionfind.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/ds/unionfind/rollback_potentialized_unionfind.hpp\n\
    #line 1 \"ds/rollback_array.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/rollback_array.hpp\n\
    \ntemplate <typename T>\nstruct Rollback_Array {\n  int N;\n  vc<T> dat;\n  vc<pair<int,\
    \ T>> history;\n\n  Rollback_Array() {}\n  Rollback_Array(vc<T> x) : N(len(x)),\
    \ dat(x) {}\n  Rollback_Array(int N) : N(N), dat(N) {}\n  template <typename F>\n\
    \  Rollback_Array(int N, F f) : N(N) {\n    dat.reserve(N);\n    FOR(i, N) dat.eb(f(i));\n\
    \  }\n\n  int time() { return len(history); }\n  void rollback(int t) {\n    while\
    \ (t < time()) {\n      auto [idx, v] = POP(history);\n      dat[idx] = v;\n \
    \   }\n  }\n  T get(int idx) { return dat[idx]; }\n  void set(int idx, T x) {\n\
    \    history.eb(idx, dat[idx]);\n    dat[idx] = x;\n  }\n\n  vc<T> get_all() {\
    \ return dat; }\n};\n#line 3 \"ds/unionfind/rollback_potentialized_unionfind.hpp\"\
    \n\ntemplate <typename Group>\nstruct Rollback_Potentialized_UnionFind {\n  using\
    \ E = typename Group::value_type;\n  using P = pair<int, E>;\n  Rollback_Array<P>\
    \ dat; // parent or -size\n\n  Rollback_Potentialized_UnionFind(int n) : dat(vc<P>(n,\
    \ P(-1, Group::id()))) {}\n\n  P get(int v) {\n    // \u7D4C\u8DEF\u5727\u7E2E\
    \u306F\u3057\u306A\u3044\u3088\u3046\u306B\n    E val = Group::id();\n    while\
    \ (1) {\n      auto [p, x] = dat.get(v);\n      if (p < 0) { break; }\n      val\
    \ = Group::op(x, val);\n      v = p;\n    }\n    return {v, val};\n  }\n\n  int\
    \ time() { return dat.time(); }\n  void rollback(int t) { dat.rollback(t); }\n\
    \n  bool merge(int a, int b, E x) {\n    auto [v1, x1] = get(a);\n    auto [v2,\
    \ x2] = get(b);\n    if (v1 == v2) return false;\n    int s1 = -dat.get(v1).fi;\n\
    \    int s2 = -dat.get(v2).fi;\n    if (s1 < s2) {\n      swap(s1, s2), swap(v1,\
    \ v2), swap(x1, x2);\n      x = Group::inverse(x);\n    }\n    // v1 <- v2\n \
    \   x = Group::op(x1, x);\n    x = Group::op(x, Group::inverse(x2));\n    dat.set(v2,\
    \ P({v1, x}));\n    dat.set(v1, P({-(s1 + s2), Group::id()}));\n    return true;\n\
    \  }\n};\n#line 5 \"test/5_ai_generated_test/rollback_potentialized_permutation.test.cpp\"\
    \n\n// \u5BFE\u8C61: Rollback_Potentialized_UnionFind<noncommutative Group>\u3002\
    \n// S3 (3 \u70B9\u306E\u7F6E\u63DB) \u306E\u7A4D\u3092\u4F7F\u3044\u3001\u4F75\
    \u5408\u6642\u306E\u5411\u304D\u30FB\u9006\u5143\u30FB\u91CD\u307F\u4ED8\u304D\
    union-by-size\u3068\n// rollback \u306E\u5B8C\u5168\u5FA9\u5143\u3092\u691C\u67FB\
    \u3059\u308B\u3002\u65E2\u5B58\u306E XOR \u7FA4\u306B\u3088\u308B\u554F\u984C\u30C6\
    \u30B9\u30C8\u3068\u306F\u7570\u306A\u308A\u3001\n// op(a,b)!=op(b,a) \u304C\u983B\
    \u7E41\u306B\u6210\u7ACB\u3059\u308B\u3002\n// \u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB\
    : \u63A1\u7528\u3057\u305F\u5236\u7D04 P[v]=P[u]*w \u3092\u6709\u5411\u8FBA\u3068\
    \u3057\u3066\u4FDD\u5B58\u3057\u3001\n// \u6BCE\u56DE DFS/BFS \u3067\u5168\u9802\
    \u70B9\u306E\u76F8\u5BFE\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u518D\u69CB\
    \u7BC9\u3059\u308B\u3002\n// \u56FA\u5B9Aseed: 0x51A76B19\u3002\u5C0F\u3055\u3044\
    \u68EE\u30FB\u9023\u7D9A\u4F75\u5408\u30FB\u5931\u6557\u4F75\u5408\u30FB\u6642\
    \u523B\u5DFB\u304D\u623B\u3057\u3092\u6DF7\u5728\u3002\nstruct S3 {\n  using value_type\
    \ = array<int, 3>;\n  static value_type id() { return {0, 1, 2}; }\n  static value_type\
    \ op(const value_type& a, const value_type& b) {\n    value_type c;\n    for (int\
    \ i = 0; i < 3; ++i) c[i] = a[b[i]];\n    return c;\n  }\n  static value_type\
    \ inverse(const value_type& a) {\n    value_type b;\n    for (int i = 0; i < 3;\
    \ ++i) b[a[i]] = i;\n    return b;\n  }\n};\n\nusing Perm = S3::value_type;\n\
    struct Constraint {\n  int a, b;\n  Perm w;\n};\nstruct Snapshot {\n  int time;\n\
    \  vector<Constraint> constraints;\n};\n\n[[noreturn]] void fail(int n, int trial,\
    \ int step, int a, int b, const string& reason) {\n  cerr << \"rollback_potentialized:\
    \ n=\" << n << \" trial=\" << trial\n       << \" step=\" << step << \" pair=\"\
    \ << a << \",\" << b\n       << \" : \" << reason << '\\n';\n  abort();\n}\n\n\
    struct Oracle {\n  vector<int> comp, sz;\n  vector<Perm> val;\n  explicit Oracle(int\
    \ n, const vector<Constraint>& edges)\n      : comp(n, -1), sz(n, 0), val(n, S3::id())\
    \ {\n    vector<vector<pair<int, Perm>>> adj(n);\n    for (auto [a, b, w] : edges)\
    \ {\n      adj[a].push_back({b, w});\n      adj[b].push_back({a, S3::inverse(w)});\n\
    \    }\n    for (int r = 0; r < n; ++r) if (comp[r] == -1) {\n      queue<int>\
    \ q;\n      comp[r] = r;\n      q.push(r);\n      while (!q.empty()) {\n     \
    \   int v = q.front(); q.pop();\n        ++sz[r];\n        for (auto [to, w] :\
    \ adj[v]) {\n          Perm next = S3::op(val[v], w);\n          if (comp[to]\
    \ == -1) {\n            comp[to] = r;\n            val[to] = next;\n         \
    \   q.push(to);\n          } else if (val[to] != next) {\n            cerr <<\
    \ \"inconsistent oracle forest\\n\";\n            abort();\n          }\n    \
    \    }\n      }\n    }\n  }\n  bool same(int a, int b) const { return comp[a]\
    \ == comp[b]; }\n  Perm path(int a, int b) const { return S3::op(S3::inverse(val[a]),\
    \ val[b]); }\n  int size(int v) const { return sz[comp[v]]; }\n};\n\nvoid verify(Rollback_Potentialized_UnionFind<S3>&\
    \ uf,\n            int n, const vector<Constraint>& constraints,\n           \
    \ int trial, int step, mt19937& rng, bool exhaustive) {\n  Oracle ref(n, constraints);\n\
    \  vector<pair<int, Perm>> got(n);\n  for (int v = 0; v < n; ++v) {\n    got[v]\
    \ = uf.get(v);\n    if (got[v].first < 0 || got[v].first >= n)\n      fail(n,\
    \ trial, step, v, v, \"invalid representative\");\n    if (uf.get(got[v].first).first\
    \ != got[v].first)\n      fail(n, trial, step, v, v, \"nonroot representative\"\
    );\n    if (-uf.dat.get(got[v].first).first != ref.size(v))\n      fail(n, trial,\
    \ step, v, v, \"incorrect component size\");\n  }\n  int limit = exhaustive ?\
    \ n * n : 15;\n  for (int k = 0; k < limit; ++k) {\n    int a = exhaustive ? (k\
    \ / n) : int(rng() % n);\n    int b = exhaustive ? (k % n) : int(rng() % n);\n\
    \    if ((got[a].first == got[b].first) != ref.same(a, b))\n      fail(n, trial,\
    \ step, a, b, \"incorrect connectivity\");\n    if (ref.same(a, b)) {\n      Perm\
    \ got_path = S3::op(S3::inverse(got[a].second), got[b].second);\n      if (got_path\
    \ != ref.path(a, b))\n        fail(n, trial, step, a, b, \"noncommutative potential\
    \ mismatch\");\n    }\n  }\n}\n\nint main() {\n  mt19937 rng(0x51A76B19);\n  vector<Perm>\
    \ perms;\n  Perm p = {0, 1, 2};\n  do { perms.push_back(p); } while (next_permutation(p.begin(),\
    \ p.end()));\n  assert(perms.size() == 6);\n  for (int n : {1, 2, 3, 6, 11, 24})\
    \ {\n    for (int trial = 0; trial < 24; ++trial) {\n      Rollback_Potentialized_UnionFind<S3>\
    \ uf(n);\n      vector<Constraint> edges;\n      vector<Snapshot> hist = {{uf.time(),\
    \ edges}};\n      for (int step = 0; step < 450; ++step) {\n        int action\
    \ = int(rng() % 10);\n        if (action == 0 && hist.size() > 1) {\n        \
    \  int k = int(rng() % hist.size());\n          uf.rollback(hist[k].time);\n \
    \         edges = hist[k].constraints;\n          hist.resize(k + 1);\n      \
    \  } else {\n          int a = int(rng() % n), b = int(rng() % n);\n         \
    \ Perm w = perms[rng() % 6];\n          Oracle before(n, edges);\n          int\
    \ old_time = uf.time();\n          bool joined = uf.merge(a, b, w);\n        \
    \  if (joined != !before.same(a, b))\n            fail(n, trial, step, a, b, \"\
    merge result mismatch\");\n          if (joined) {\n            edges.push_back({a,\
    \ b, w});\n            if (uf.time() != old_time + 2)\n              fail(n, trial,\
    \ step, a, b, \"successful merge history length\");\n          } else if (uf.time()\
    \ != old_time) {\n            fail(n, trial, step, a, b, \"failed merge changed\
    \ history\");\n          }\n        }\n        verify(uf, n, edges, trial, step,\
    \ rng, (step % 9 == 0));\n        hist.push_back({uf.time(), edges});\n      }\n\
    \      uf.rollback(hist[0].time);\n      verify(uf, n, {}, trial, 451, rng, true);\n\
    \    }\n  }\n  return 0;\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/unionfind/rollback_potentialized_unionfind.hpp\"\
    \n\n// \u5BFE\u8C61: Rollback_Potentialized_UnionFind<noncommutative Group>\u3002\
    \n// S3 (3 \u70B9\u306E\u7F6E\u63DB) \u306E\u7A4D\u3092\u4F7F\u3044\u3001\u4F75\
    \u5408\u6642\u306E\u5411\u304D\u30FB\u9006\u5143\u30FB\u91CD\u307F\u4ED8\u304D\
    union-by-size\u3068\n// rollback \u306E\u5B8C\u5168\u5FA9\u5143\u3092\u691C\u67FB\
    \u3059\u308B\u3002\u65E2\u5B58\u306E XOR \u7FA4\u306B\u3088\u308B\u554F\u984C\u30C6\
    \u30B9\u30C8\u3068\u306F\u7570\u306A\u308A\u3001\n// op(a,b)!=op(b,a) \u304C\u983B\
    \u7E41\u306B\u6210\u7ACB\u3059\u308B\u3002\n// \u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB\
    : \u63A1\u7528\u3057\u305F\u5236\u7D04 P[v]=P[u]*w \u3092\u6709\u5411\u8FBA\u3068\
    \u3057\u3066\u4FDD\u5B58\u3057\u3001\n// \u6BCE\u56DE DFS/BFS \u3067\u5168\u9802\
    \u70B9\u306E\u76F8\u5BFE\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u518D\u69CB\
    \u7BC9\u3059\u308B\u3002\n// \u56FA\u5B9Aseed: 0x51A76B19\u3002\u5C0F\u3055\u3044\
    \u68EE\u30FB\u9023\u7D9A\u4F75\u5408\u30FB\u5931\u6557\u4F75\u5408\u30FB\u6642\
    \u523B\u5DFB\u304D\u623B\u3057\u3092\u6DF7\u5728\u3002\nstruct S3 {\n  using value_type\
    \ = array<int, 3>;\n  static value_type id() { return {0, 1, 2}; }\n  static value_type\
    \ op(const value_type& a, const value_type& b) {\n    value_type c;\n    for (int\
    \ i = 0; i < 3; ++i) c[i] = a[b[i]];\n    return c;\n  }\n  static value_type\
    \ inverse(const value_type& a) {\n    value_type b;\n    for (int i = 0; i < 3;\
    \ ++i) b[a[i]] = i;\n    return b;\n  }\n};\n\nusing Perm = S3::value_type;\n\
    struct Constraint {\n  int a, b;\n  Perm w;\n};\nstruct Snapshot {\n  int time;\n\
    \  vector<Constraint> constraints;\n};\n\n[[noreturn]] void fail(int n, int trial,\
    \ int step, int a, int b, const string& reason) {\n  cerr << \"rollback_potentialized:\
    \ n=\" << n << \" trial=\" << trial\n       << \" step=\" << step << \" pair=\"\
    \ << a << \",\" << b\n       << \" : \" << reason << '\\n';\n  abort();\n}\n\n\
    struct Oracle {\n  vector<int> comp, sz;\n  vector<Perm> val;\n  explicit Oracle(int\
    \ n, const vector<Constraint>& edges)\n      : comp(n, -1), sz(n, 0), val(n, S3::id())\
    \ {\n    vector<vector<pair<int, Perm>>> adj(n);\n    for (auto [a, b, w] : edges)\
    \ {\n      adj[a].push_back({b, w});\n      adj[b].push_back({a, S3::inverse(w)});\n\
    \    }\n    for (int r = 0; r < n; ++r) if (comp[r] == -1) {\n      queue<int>\
    \ q;\n      comp[r] = r;\n      q.push(r);\n      while (!q.empty()) {\n     \
    \   int v = q.front(); q.pop();\n        ++sz[r];\n        for (auto [to, w] :\
    \ adj[v]) {\n          Perm next = S3::op(val[v], w);\n          if (comp[to]\
    \ == -1) {\n            comp[to] = r;\n            val[to] = next;\n         \
    \   q.push(to);\n          } else if (val[to] != next) {\n            cerr <<\
    \ \"inconsistent oracle forest\\n\";\n            abort();\n          }\n    \
    \    }\n      }\n    }\n  }\n  bool same(int a, int b) const { return comp[a]\
    \ == comp[b]; }\n  Perm path(int a, int b) const { return S3::op(S3::inverse(val[a]),\
    \ val[b]); }\n  int size(int v) const { return sz[comp[v]]; }\n};\n\nvoid verify(Rollback_Potentialized_UnionFind<S3>&\
    \ uf,\n            int n, const vector<Constraint>& constraints,\n           \
    \ int trial, int step, mt19937& rng, bool exhaustive) {\n  Oracle ref(n, constraints);\n\
    \  vector<pair<int, Perm>> got(n);\n  for (int v = 0; v < n; ++v) {\n    got[v]\
    \ = uf.get(v);\n    if (got[v].first < 0 || got[v].first >= n)\n      fail(n,\
    \ trial, step, v, v, \"invalid representative\");\n    if (uf.get(got[v].first).first\
    \ != got[v].first)\n      fail(n, trial, step, v, v, \"nonroot representative\"\
    );\n    if (-uf.dat.get(got[v].first).first != ref.size(v))\n      fail(n, trial,\
    \ step, v, v, \"incorrect component size\");\n  }\n  int limit = exhaustive ?\
    \ n * n : 15;\n  for (int k = 0; k < limit; ++k) {\n    int a = exhaustive ? (k\
    \ / n) : int(rng() % n);\n    int b = exhaustive ? (k % n) : int(rng() % n);\n\
    \    if ((got[a].first == got[b].first) != ref.same(a, b))\n      fail(n, trial,\
    \ step, a, b, \"incorrect connectivity\");\n    if (ref.same(a, b)) {\n      Perm\
    \ got_path = S3::op(S3::inverse(got[a].second), got[b].second);\n      if (got_path\
    \ != ref.path(a, b))\n        fail(n, trial, step, a, b, \"noncommutative potential\
    \ mismatch\");\n    }\n  }\n}\n\nint main() {\n  mt19937 rng(0x51A76B19);\n  vector<Perm>\
    \ perms;\n  Perm p = {0, 1, 2};\n  do { perms.push_back(p); } while (next_permutation(p.begin(),\
    \ p.end()));\n  assert(perms.size() == 6);\n  for (int n : {1, 2, 3, 6, 11, 24})\
    \ {\n    for (int trial = 0; trial < 24; ++trial) {\n      Rollback_Potentialized_UnionFind<S3>\
    \ uf(n);\n      vector<Constraint> edges;\n      vector<Snapshot> hist = {{uf.time(),\
    \ edges}};\n      for (int step = 0; step < 450; ++step) {\n        int action\
    \ = int(rng() % 10);\n        if (action == 0 && hist.size() > 1) {\n        \
    \  int k = int(rng() % hist.size());\n          uf.rollback(hist[k].time);\n \
    \         edges = hist[k].constraints;\n          hist.resize(k + 1);\n      \
    \  } else {\n          int a = int(rng() % n), b = int(rng() % n);\n         \
    \ Perm w = perms[rng() % 6];\n          Oracle before(n, edges);\n          int\
    \ old_time = uf.time();\n          bool joined = uf.merge(a, b, w);\n        \
    \  if (joined != !before.same(a, b))\n            fail(n, trial, step, a, b, \"\
    merge result mismatch\");\n          if (joined) {\n            edges.push_back({a,\
    \ b, w});\n            if (uf.time() != old_time + 2)\n              fail(n, trial,\
    \ step, a, b, \"successful merge history length\");\n          } else if (uf.time()\
    \ != old_time) {\n            fail(n, trial, step, a, b, \"failed merge changed\
    \ history\");\n          }\n        }\n        verify(uf, n, edges, trial, step,\
    \ rng, (step % 9 == 0));\n        hist.push_back({uf.time(), edges});\n      }\n\
    \      uf.rollback(hist[0].time);\n      verify(uf, n, {}, trial, 451, rng, true);\n\
    \    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/unionfind/rollback_potentialized_unionfind.hpp
  - ds/rollback_array.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/rollback_potentialized_permutation.test.cpp
  requiredBy: []
  timestamp: '2026-11-23 02:04:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/rollback_potentialized_permutation.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/rollback_potentialized_permutation.test.cpp
- /verify/test/5_ai_generated_test/rollback_potentialized_permutation.test.cpp.html
title: test/5_ai_generated_test/rollback_potentialized_permutation.test.cpp
---
