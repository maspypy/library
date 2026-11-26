---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/binary_trie.hpp
    title: ds/binary_trie.hpp
  - icon: ':heavy_check_mark:'
    path: ds/node_pool.hpp
    title: ds/node_pool.hpp
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 1 \"ds/node_pool.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/node_pool.hpp\n\
    // \u30DE\u30EB\u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u3067\u3082\u78BA\u4FDD\
    \u6E08\u307F chunk \u3092\u518D\u5229\u7528\u3059\u308B\ntemplate <class Node>\n\
    struct Node_Pool {\n  union Slot {\n    Node node;\n    Slot* next;\n\n    Slot()\
    \ {}\n    ~Slot() {}\n  };\n  using np = Node*;\n\n  static constexpr int CHUNK_SIZE\
    \ = 1 << 12;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  int chunk_id = 0;\n  int pos\
    \ = 0;\n  Slot* free_head = nullptr;\n\n  ~Node_Pool() {\n    auto& cache = chunk_cache();\n\
    \    for (auto& p : chunks) cache.eb(std::move(p));\n  }\n\n  template <class...\
    \ Args>\n  np create(Args&&... args) {\n    Slot* s = new_slot();\n    return\
    \ ::new (&s->node) Node(forward<Args>(args)...);\n  }\n\n  np clone(const np x)\
    \ {\n    assert(x);\n    Slot* s = new_slot();\n    return ::new (&s->node) Node(*x);\n\
    \  }\n\n  void destroy(np x) {\n    if (!x) return;\n    x->~Node();\n    Slot*\
    \ s = reinterpret_cast<Slot*>(x);\n    s->next = free_head;\n    free_head = s;\n\
    \  }\n\n  // \u5168 node \u3092\u7121\u52B9\u5316\u3059\u308B\u3002\n  // \u78BA\
    \u4FDD\u6E08\u307F chunk \u306F\u89E3\u653E\u305B\u305A\u3001\u6B21\u56DE\u4EE5\
    \u964D\u306B\u518D\u5229\u7528\u3059\u308B\u3002\n  void reset() {\n    free_head\
    \ = nullptr;\n    chunk_id = 0;\n    pos = 0;\n  }\n\n  int used() const { return\
    \ chunk_id * CHUNK_SIZE + pos; }\n\n private:\n  static vc<unique_ptr<Slot[]>>&\
    \ chunk_cache() {\n    // static Node_Pool \u306E destructor \u3088\u308A\u5148\
    \u306B\u7834\u68C4\u3055\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u3002\
    \n    static auto* cache = new vc<unique_ptr<Slot[]>>();\n    return *cache;\n\
    \  }\n\n  void alloc_chunk() {\n    auto& cache = chunk_cache();\n    if (cache.empty())\
    \ {\n      chunks.eb(make_unique<Slot[]>(CHUNK_SIZE));\n    } else {\n      chunks.eb(std::move(cache.back()));\n\
    \      cache.pop_back();\n    }\n  }\n\n  Slot* new_slot() {\n    if (free_head)\
    \ {\n      Slot* s = free_head;\n      free_head = free_head->next;\n      return\
    \ s;\n    }\n\n    if (chunk_id == len(chunks)) alloc_chunk();\n\n    Slot* s\
    \ = &chunks[chunk_id][pos++];\n    if (pos == CHUNK_SIZE) {\n      ++chunk_id;\n\
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 2 \"ds/binary_trie.hpp\"\
    \n\ntemplate <int LOG, bool PERSISTENT, typename UINT = u64,\n    typename SIZE_TYPE\
    \ = u32>\nstruct Binary_Trie {\n  using T = SIZE_TYPE;\n  static_assert(is_same_v<T,\
    \ u32> || is_same_v<T, u64>);\n  static_assert(0 < LOG && LOG <= numeric_limits<UINT>::digits);\n\
    \n  struct Node {\n    T cnt;\n    Node *l, *r;\n  };\n\n  Node_Pool<Node> pool;\n\
    \  using np = Node*;\n\n  void reset() { pool.reset(); }\n\n  np new_root() {\
    \ return nullptr; }\n\n  np add(np root, UINT val, T cnt = 1) {\n    if constexpr\
    \ (LOG < numeric_limits<UINT>::digits) {\n      assert((val >> LOG) == 0);\n \
    \   }\n    return add_rec(root, LOG, val, cnt);\n  }\n\n  // f(val, cnt, end)\n\
    \  template <typename F>\n  void enumerate(np root, F f) {\n    bool end = false;\n\
    \    auto dfs = [&](auto& dfs, np root, UINT val, int ht) -> void {\n      if\
    \ (!root || end) return;\n      if (ht == 0) {\n        f(val, root->cnt, end);\n\
    \        return;\n      }\n      dfs(dfs, root->l, 2 * val + 0, ht - 1);\n   \
    \   dfs(dfs, root->r, 2 * val + 1, ht - 1);\n    };\n    dfs(dfs, root, 0, LOG);\n\
    \  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6607\u9806 k\
    \ \u756A\u76EE\n  UINT kth(np root, T k, UINT xor_val) {\n    assert(root && k\
    \ < root->cnt);\n    UINT val = 0;\n    for (int d = LOG - 1; d >= 0; --d) {\n\
    \      bool b = (xor_val >> d) & 1;\n      np c = (b ? root->r : root->l);\n \
    \     T sl = (c ? c->cnt : 0);\n      if (k >= sl) {\n        k -= sl;\n     \
    \   b = !b;\n      }\n      val = 2 * val + b;\n      root = (b ? root->r : root->l);\n\
    \    }\n    return val ^ xor_val;\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\
    \u306E\u5024\u3067\u6700\u5C0F\u5024\n  UINT min(np root, UINT xor_val) {\n  \
    \  assert(root && root->cnt);\n    return kth(root, 0, xor_val);\n  }\n\n  //\
    \ xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067\u6700\u5927\u5024\n  UINT\
    \ max(np root, UINT xor_val) {\n    assert(root && root->cnt);\n    return kth(root,\
    \ root->cnt - 1, xor_val);\n  }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\
    \u5024\u3067 [0, upper) \u5185\u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\
    \n  T prefix_count(np root, UINT upper, UINT xor_val) {\n    if (!root) return\
    \ 0;\n    if constexpr (LOG < numeric_limits<UINT>::digits) {\n      UINT a =\
    \ upper >> LOG, b = xor_val >> LOG;\n      if (a != b) return (a > b ? root->cnt\
    \ : 0);\n    }\n    T res = 0;\n    for (int d = LOG - 1; d >= 0 && root; --d)\
    \ {\n      np l = root->l, r = root->r;\n      if ((xor_val >> d) & 1) swap(l,\
    \ r);\n      if ((upper >> d) & 1) {\n        if (l) res += l->cnt;\n        root\
    \ = r;\n      } else {\n        root = l;\n      }\n    }\n    return res;\n \
    \ }\n\n  // xor_val \u3057\u305F\u3042\u3068\u306E\u5024\u3067 [lo, hi) \u5185\
    \u306B\u5165\u308B\u3082\u306E\u306E\u500B\u6570\n  T count(np root, UINT lo,\
    \ UINT hi, UINT xor_val) {\n    return prefix_count(root, hi, xor_val) - prefix_count(root,\
    \ lo, xor_val);\n  }\n\n private:\n  np new_node() {\n    np c = pool.create();\n\
    \    c->l = c->r = nullptr;\n    c->cnt = 0;\n    return c;\n  }\n\n  np clone(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    return pool.clone(c);\n  }\n\
    \n  np add_rec(np root, int ht, UINT val, T cnt) {\n    root = (root ? clone(root)\
    \ : new_node());\n    root->cnt += cnt;\n    if (ht == 0) return root;\n    bool\
    \ b = (val >> (ht - 1)) & 1;\n    np& c = (b ? root->r : root->l);\n    c = add_rec(c,\
    \ ht - 1, val, cnt);\n    return root;\n  }\n};\n#line 4 \"test/5_ai_generated_test/binary_trie_persistent_xor.test.cpp\"\
    \n\n// \u5BFE\u8C61: Binary_Trie<LOG, true> \u306E\u6C38\u7D9A\u5206\u5C90\u3068\
    \ xor_val \u4ED8\u304D kth/count\u3002\n// \u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB\
    : \u65E7\u30D0\u30FC\u30B8\u30E7\u30F3\u3054\u3068\u306B std::map<value,count>\
    \ \u3092\u4E38\u3054\u3068\u30B3\u30D4\u30FC\u3057\u3001\n// XOR\u5F8C\u306E\u5024\
    \u3092\u5B9F\u969B\u306B\u4E26\u3079\u3066\u30BD\u30FC\u30C8\u3059\u308B\u3002\
    \u5206\u5C90\u3057\u305F\u65E7root\u3092\u518D\u691C\u67FB\u3057\u3066\u7834\u58CA\
    \u3092\u691C\u51FA\u3002\n// LOG=6\u306863\u3001\u91CD\u8907\u633F\u5165\u30FB\
    2\u4EE5\u4E0A\u306E\u500B\u6570\u30FB\u9AD8\u4F4D\u30D3\u30C3\u30C8\u5883\u754C\
    \u3092\u4F7F\u7528\u3059\u308B\u3002\n// \u8CA0\u306E\u500B\u6570\uFF08\u524A\u9664\
    \uFF09\u3068LOG==64\u306F\u65E2\u5B58\u5B9F\u88C5\u306E\u5225\u5951\u7D04\u30FB\
    \u65E2\u77E5\u6307\u6458\u3068\u533A\u5225\u3059\u308B\u3002\n// \u56FA\u5B9A\
    seed 0xB1A7E2026ULL\u3002\u5931\u6557\u6642\u306Ftrial,step,version,mask\u3092\
    \u51FA\u529B\u3002\nnamespace {\n[[noreturn]] void fail(int log,int tr,int step,int\
    \ version,u64 mask,const string& what){\n  cerr<<\"binary trie log=\"<<log<<\"\
    \ trial=\"<<tr<<\" step=\"<<step\n      <<\" version=\"<<version<<\" mask=\"<<mask<<\"\
    \ \"<<what<<'\\n';\n  abort();\n}\ntemplate<int LOG> void run(){\n  using Trie=Binary_Trie<LOG,true,u64,u32>;\n\
    \  using np=typename Trie::np;\n  const u64 LIM=u64(1)<<LOG, MASK=LIM-1;\n  mt19937_64\
    \ rng(0xB1A7E2026ULL+LOG);\n  for(int trial=0;trial<52;trial++) {\n    Trie t;\n\
    \    vector<np> roots={t.new_root()};\n    vector<map<u64,u32>> refs(1);\n   \
    \ if(t.prefix_count(roots[0],LIM,0)!=0)fail(LOG,trial,-1,0,0,\"empty root count\"\
    );\n    for(int step=0;step<145;step++){\n      int source=int(rng()%roots.size());\n\
    \      u64 x;\n      switch(step%11){\n        case 0:x=0;break;\n        case\
    \ 1:x=MASK;break;\n        case 2:x=LIM/2;break;\n        case 3:x=LIM/2-1;break;\n\
    \        case 4:x=1;break;\n        default:x=rng()&MASK;break;\n      }\n   \
    \   u32 cnt=u32(1+rng()%3);\n      roots.push_back(t.add(roots[source],x,cnt));\n\
    \      auto next=refs[source];next[x]+=cnt;refs.push_back(std::move(next));\n\
    \      for(int check=0;check<3;check++){\n        int v=check==0?int(roots.size()-1):int(rng()%roots.size());\n\
    \        u64 mask=(check==0?(step%2?MASK:LIM/2):(rng()&MASK));\n        vector<u64>\
    \ transformed;\n        u64 total=0;\n        for(auto [val,num]:refs[v]){\n \
    \         total+=num;\n          for(u32 j=0;j<num;j++)transformed.push_back(val^mask);\n\
    \        }\n        sort(transformed.begin(),transformed.end());\n        if(t.prefix_count(roots[v],LIM,mask)!=total)\n\
    \          fail(LOG,trial,step,v,mask,\"total prefix_count\");\n        for(int\
    \ q=0;q<7;q++){\n          u64 bound=(q==0?0:q==1?1:q==2?LIM/2:q==3?LIM-1:q==4?LIM:(rng()&MASK));\n\
    \          u32 expected=lower_bound(transformed.begin(),transformed.end(),bound)-transformed.begin();\n\
    \          if(t.prefix_count(roots[v],bound,mask)!=expected)\n            fail(LOG,trial,step,v,mask,\"\
    prefix_count upper=\"+to_string(bound));\n          u64 lo=(q<2?0:(rng()&MASK)),hi=(q<2?LIM:(rng()&MASK));\n\
    \          if(lo>hi)swap(lo,hi);\n          u32 cnt0=lower_bound(transformed.begin(),transformed.end(),hi)-\n\
    \                   lower_bound(transformed.begin(),transformed.end(),lo);\n \
    \         if(t.count(roots[v],lo,hi,mask)!=cnt0)\n            fail(LOG,trial,step,v,mask,\"\
    count interval\");\n        }\n        if(!transformed.empty()){\n          int\
    \ sz=transformed.size();\n          for(int k:vector<int>{0,sz/2,sz-1,int(rng()%sz)}){\n\
    \            if(t.kth(roots[v],k,mask)!=transformed[k])\n              fail(LOG,trial,step,v,mask,\"\
    kth k=\"+to_string(k));\n          }\n          if(t.min(roots[v],mask)!=transformed.front()||\n\
    \             t.max(roots[v],mask)!=transformed.back())\n            fail(LOG,trial,step,v,mask,\"\
    min/max\");\n        }\n        map<u64,u32> enumerated;\n        t.enumerate(roots[v],[&](u64\
    \ val,u32 num,bool& end){\n          if(num)enumerated[val]+=num;\n          (void)end;\n\
    \        });\n        if(enumerated!=refs[v])fail(LOG,trial,step,v,mask,\"enumerate\
    \ distinct counts\");\n      }\n    }\n  }\n  cout<<\"PASS persistent binary trie\
    \ LOG=\"<<LOG<<'\\n';\n}\n}\nint main(){run<6>();run<63>();}\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/binary_trie.hpp\"\
    \n\n// \u5BFE\u8C61: Binary_Trie<LOG, true> \u306E\u6C38\u7D9A\u5206\u5C90\u3068\
    \ xor_val \u4ED8\u304D kth/count\u3002\n// \u72EC\u7ACB\u30AA\u30E9\u30AF\u30EB\
    : \u65E7\u30D0\u30FC\u30B8\u30E7\u30F3\u3054\u3068\u306B std::map<value,count>\
    \ \u3092\u4E38\u3054\u3068\u30B3\u30D4\u30FC\u3057\u3001\n// XOR\u5F8C\u306E\u5024\
    \u3092\u5B9F\u969B\u306B\u4E26\u3079\u3066\u30BD\u30FC\u30C8\u3059\u308B\u3002\
    \u5206\u5C90\u3057\u305F\u65E7root\u3092\u518D\u691C\u67FB\u3057\u3066\u7834\u58CA\
    \u3092\u691C\u51FA\u3002\n// LOG=6\u306863\u3001\u91CD\u8907\u633F\u5165\u30FB\
    2\u4EE5\u4E0A\u306E\u500B\u6570\u30FB\u9AD8\u4F4D\u30D3\u30C3\u30C8\u5883\u754C\
    \u3092\u4F7F\u7528\u3059\u308B\u3002\n// \u8CA0\u306E\u500B\u6570\uFF08\u524A\u9664\
    \uFF09\u3068LOG==64\u306F\u65E2\u5B58\u5B9F\u88C5\u306E\u5225\u5951\u7D04\u30FB\
    \u65E2\u77E5\u6307\u6458\u3068\u533A\u5225\u3059\u308B\u3002\n// \u56FA\u5B9A\
    seed 0xB1A7E2026ULL\u3002\u5931\u6557\u6642\u306Ftrial,step,version,mask\u3092\
    \u51FA\u529B\u3002\nnamespace {\n[[noreturn]] void fail(int log,int tr,int step,int\
    \ version,u64 mask,const string& what){\n  cerr<<\"binary trie log=\"<<log<<\"\
    \ trial=\"<<tr<<\" step=\"<<step\n      <<\" version=\"<<version<<\" mask=\"<<mask<<\"\
    \ \"<<what<<'\\n';\n  abort();\n}\ntemplate<int LOG> void run(){\n  using Trie=Binary_Trie<LOG,true,u64,u32>;\n\
    \  using np=typename Trie::np;\n  const u64 LIM=u64(1)<<LOG, MASK=LIM-1;\n  mt19937_64\
    \ rng(0xB1A7E2026ULL+LOG);\n  for(int trial=0;trial<52;trial++) {\n    Trie t;\n\
    \    vector<np> roots={t.new_root()};\n    vector<map<u64,u32>> refs(1);\n   \
    \ if(t.prefix_count(roots[0],LIM,0)!=0)fail(LOG,trial,-1,0,0,\"empty root count\"\
    );\n    for(int step=0;step<145;step++){\n      int source=int(rng()%roots.size());\n\
    \      u64 x;\n      switch(step%11){\n        case 0:x=0;break;\n        case\
    \ 1:x=MASK;break;\n        case 2:x=LIM/2;break;\n        case 3:x=LIM/2-1;break;\n\
    \        case 4:x=1;break;\n        default:x=rng()&MASK;break;\n      }\n   \
    \   u32 cnt=u32(1+rng()%3);\n      roots.push_back(t.add(roots[source],x,cnt));\n\
    \      auto next=refs[source];next[x]+=cnt;refs.push_back(std::move(next));\n\
    \      for(int check=0;check<3;check++){\n        int v=check==0?int(roots.size()-1):int(rng()%roots.size());\n\
    \        u64 mask=(check==0?(step%2?MASK:LIM/2):(rng()&MASK));\n        vector<u64>\
    \ transformed;\n        u64 total=0;\n        for(auto [val,num]:refs[v]){\n \
    \         total+=num;\n          for(u32 j=0;j<num;j++)transformed.push_back(val^mask);\n\
    \        }\n        sort(transformed.begin(),transformed.end());\n        if(t.prefix_count(roots[v],LIM,mask)!=total)\n\
    \          fail(LOG,trial,step,v,mask,\"total prefix_count\");\n        for(int\
    \ q=0;q<7;q++){\n          u64 bound=(q==0?0:q==1?1:q==2?LIM/2:q==3?LIM-1:q==4?LIM:(rng()&MASK));\n\
    \          u32 expected=lower_bound(transformed.begin(),transformed.end(),bound)-transformed.begin();\n\
    \          if(t.prefix_count(roots[v],bound,mask)!=expected)\n            fail(LOG,trial,step,v,mask,\"\
    prefix_count upper=\"+to_string(bound));\n          u64 lo=(q<2?0:(rng()&MASK)),hi=(q<2?LIM:(rng()&MASK));\n\
    \          if(lo>hi)swap(lo,hi);\n          u32 cnt0=lower_bound(transformed.begin(),transformed.end(),hi)-\n\
    \                   lower_bound(transformed.begin(),transformed.end(),lo);\n \
    \         if(t.count(roots[v],lo,hi,mask)!=cnt0)\n            fail(LOG,trial,step,v,mask,\"\
    count interval\");\n        }\n        if(!transformed.empty()){\n          int\
    \ sz=transformed.size();\n          for(int k:vector<int>{0,sz/2,sz-1,int(rng()%sz)}){\n\
    \            if(t.kth(roots[v],k,mask)!=transformed[k])\n              fail(LOG,trial,step,v,mask,\"\
    kth k=\"+to_string(k));\n          }\n          if(t.min(roots[v],mask)!=transformed.front()||\n\
    \             t.max(roots[v],mask)!=transformed.back())\n            fail(LOG,trial,step,v,mask,\"\
    min/max\");\n        }\n        map<u64,u32> enumerated;\n        t.enumerate(roots[v],[&](u64\
    \ val,u32 num,bool& end){\n          if(num)enumerated[val]+=num;\n          (void)end;\n\
    \        });\n        if(enumerated!=refs[v])fail(LOG,trial,step,v,mask,\"enumerate\
    \ distinct counts\");\n      }\n    }\n  }\n  cout<<\"PASS persistent binary trie\
    \ LOG=\"<<LOG<<'\\n';\n}\n}\nint main(){run<6>();run<63>();}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/binary_trie.hpp
  - ds/node_pool.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/binary_trie_persistent_xor.test.cpp
  requiredBy: []
  timestamp: '2026-11-24 20:56:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/binary_trie_persistent_xor.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/binary_trie_persistent_xor.test.cpp
- /verify/test/5_ai_generated_test/binary_trie_persistent_xor.test.cpp.html
title: test/5_ai_generated_test/binary_trie_persistent_xor.test.cpp
---
