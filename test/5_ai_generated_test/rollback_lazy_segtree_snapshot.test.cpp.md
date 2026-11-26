---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/acted_monoid/sum_add.hpp
    title: alg/acted_monoid/sum_add.hpp
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/rollback_array.hpp
    title: ds/rollback_array.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/rollback_lazy_segtree.hpp
    title: ds/segtree/rollback_lazy_segtree.hpp
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 3 \"test/5_ai_generated_test/rollback_lazy_segtree_snapshot.test.cpp\"\
    \n\n#line 1 \"alg/acted_monoid/sum_add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/sum_add.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"alg/acted_monoid/sum_add.hpp\"\n\ntemplate <typename E>\nstruct\
    \ ActedMonoid_Sum_Add {\n  using Monoid_X = Monoid_Add<E>;\n  using Monoid_A =\
    \ Monoid_Add<E>;\n  using X = typename Monoid_X::value_type;\n  using A = typename\
    \ Monoid_A::value_type;\n  static constexpr X act(const X &x, const A &a, const\
    \ ll &size) {\n    return x + a * E(size);\n  }\n};\n#line 1 \"ds/segtree/rollback_lazy_segtree.hpp\"\
    \n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/rollback_lazy_segtree.hpp\n\
    #line 1 \"ds/rollback_array.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/rollback_array.hpp\n\
    \ntemplate <typename T>\nstruct Rollback_Array {\n  int N;\n  vc<T> dat;\n  vc<pair<int,\
    \ T>> history;\n\n  Rollback_Array() {}\n  Rollback_Array(vc<T> x) : N(len(x)),\
    \ dat(x) {}\n  Rollback_Array(int N) : N(N), dat(N) {}\n  template <typename F>\n\
    \  Rollback_Array(int N, F f) : N(N) {\n    dat.reserve(N);\n    FOR(i, N) dat.eb(f(i));\n\
    \  }\n\n  int time() { return len(history); }\n  void rollback(int t) {\n    while\
    \ (t < time()) {\n      auto [idx, v] = POP(history);\n      dat[idx] = v;\n \
    \   }\n  }\n  T get(int idx) { return dat[idx]; }\n  void set(int idx, T x) {\n\
    \    history.eb(idx, dat[idx]);\n    dat[idx] = x;\n  }\n\n  vc<T> get_all() {\
    \ return dat; }\n};\n#line 3 \"ds/segtree/rollback_lazy_segtree.hpp\"\n\n// verify?\
    \ https://qoj.ac/submission/114657\ntemplate <typename ActedMonoid>\nstruct Rollback_Lazy_SegTree\
    \ {\n  using AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA\
    \ = typename AM::Monoid_A;\n  using X = typename MX::value_type;\n  using A =\
    \ typename MA::value_type;\n  int n, log, size;\n  Rollback_Array<X> dat;\n  Rollback_Array<A>\
    \ laz;\n\n  Rollback_Lazy_SegTree() {}\n  Rollback_Lazy_SegTree(int n) { build(n);\
    \ }\n  template <typename F>\n  Rollback_Lazy_SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  Rollback_Lazy_SegTree(const vc<X>& v) { build(v); }\n\n  void build(int\
    \ m) {\n    build(m, [](int i) -> X { return MX::id(); });\n  }\n  void build(const\
    \ vc<X>& v) {\n    build(len(v), [&](int i) -> X { return v[i]; });\n  }\n  template\
    \ <typename F>\n  void build(int m, F f) {\n    n = m, log = 0;\n    while ((1\
    \ << log) < n) ++log;\n    size = 1 << log;\n    dat = Rollback_Array<X>(vc<X>(size\
    \ << 1, MX::id()));\n    laz = Rollback_Array<A>(vc<A>(size, MA::id()));\n   \
    \ FOR(i, n) dat.set(size + i, f(i));\n    FOR_R(i, 1, size) update(i);\n  }\n\n\
    \  void update(int k) { dat.set(k, MX::op(dat.get(2 * k), dat.get(2 * k + 1)));\
    \ }\n  void set(int p, X x) {\n    assert(0 <= p && p < n);\n    p += size;\n\
    \    for (int i = log; i >= 1; i--) push(p >> i);\n    dat.set(p, x);\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n  void multiply(int p, const\
    \ X& x) {\n    assert(0 <= p && p < n);\n    p += size;\n    for (int i = log;\
    \ i >= 1; i--) push(p >> i);\n    dat.set(p, MX::op(dat.get(p), x));\n    for\
    \ (int i = 1; i <= log; i++) update(p >> i);\n  }\n\n  X get(int p) {\n    assert(0\
    \ <= p && p < n);\n    p += size;\n    for (int i = log; i >= 1; i--) push(p >>\
    \ i);\n    return dat.get(p);\n  }\n\n  vc<X> get_all() {\n    FOR(k, 1, size)\
    \ push(k);\n    auto tmp = dat.get_all();\n    return {tmp.begin() + size, tmp.begin()\
    \ + size + n};\n  }\n\n  X prod(int l, int r) {\n    assert(0 <= l && l <= r &&\
    \ r <= n);\n    if (l == r) return MX::id();\n    l += size, r += size;\n    for\
    \ (int i = log; i >= 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n\
    \      if (((r >> i) << i) != r) push((r - 1) >> i);\n    }\n    X xl = MX::id(),\
    \ xr = MX::id();\n    while (l < r) {\n      if (l & 1) xl = MX::op(xl, dat.get(l++));\n\
    \      if (r & 1) xr = MX::op(dat.get(--r), xr);\n      l >>= 1, r >>= 1;\n  \
    \  }\n    return MX::op(xl, xr);\n  }\n\n  X prod_all() { return dat.get(1); }\n\
    \n  void apply(int l, int r, A a) {\n    assert(0 <= l && l <= r && r <= n);\n\
    \    if (l == r) return;\n    l += size, r += size;\n    for (int i = log; i >=\
    \ 1; i--) {\n      if (((l >> i) << i) != l) push(l >> i);\n      if (((r >> i)\
    \ << i) != r) push((r - 1) >> i);\n    }\n    int l2 = l, r2 = r;\n    while (l\
    \ < r) {\n      if (l & 1) apply_at(l++, a);\n      if (r & 1) apply_at(--r, a);\n\
    \      l >>= 1, r >>= 1;\n    }\n    l = l2, r = r2;\n    for (int i = 1; i <=\
    \ log; i++) {\n      if (((l >> i) << i) != l) update(l >> i);\n      if (((r\
    \ >> i) << i) != r) update((r - 1) >> i);\n    }\n  }\n\n  template <typename\
    \ F>\n  int max_right(const F check, int l) {\n    assert(0 <= l && l <= n);\n\
    \    assert(check(MX::id()));\n    if (l == n) return n;\n    l += size;\n   \
    \ for (int i = log; i >= 1; i--) push(l >> i);\n    X sm = MX::id();\n    do {\n\
    \      while (l % 2 == 0) l >>= 1;\n      if (!check(MX::op(sm, dat.get(l))))\
    \ {\n        while (l < size) {\n          push(l);\n          l = (2 * l);\n\
    \          if (check(MX::op(sm, dat.get(l)))) {\n            sm = MX::op(sm, dat.get(l++));\n\
    \          }\n        }\n        return l - size;\n      }\n      sm = MX::op(sm,\
    \ dat.get(l++));\n    } while ((l & -l) != l);\n    return n;\n  }\n\n  template\
    \ <typename F>\n  int min_left(const F check, int r) {\n    assert(0 <= r && r\
    \ <= n);\n    assert(check(MX::id()));\n    if (r == 0) return 0;\n    r += size;\n\
    \    for (int i = log; i >= 1; i--) push((r - 1) >> i);\n    X sm = MX::id();\n\
    \    do {\n      r--;\n      while (r > 1 && (r % 2)) r >>= 1;\n      if (!check(MX::op(dat.get(r),\
    \ sm))) {\n        while (r < size) {\n          push(r);\n          r = (2 *\
    \ r + 1);\n          if (check(MX::op(dat.get(r), sm))) {\n            sm = MX::op(dat.get(r--),\
    \ sm);\n          }\n        }\n        return r + 1 - size;\n      }\n      sm\
    \ = MX::op(dat.get(r), sm);\n    } while ((r & -r) != r);\n    return 0;\n  }\n\
    \n  pair<int, int> time() { return {dat.time(), laz.time()}; }\n  void rollback(pair<int,\
    \ int> t) { dat.rollback(t.fi), laz.rollback(t.se); }\n\n  void push(int k) {\n\
    \    if (laz.get(k) == MA::id()) return;\n    apply_at(2 * k, laz.get(k)), apply_at(2\
    \ * k + 1, laz.get(k));\n    laz.set(k, MA::id());\n  }\n\n private:\n  void apply_at(int\
    \ k, A a) {\n    ll sz = 1 << (log - topbit(k));\n    dat.set(k, AM::act(dat.get(k),\
    \ a, sz));\n    if (k < size) laz.set(k, MA::op(laz.get(k), a));\n  }\n};\n#line\
    \ 6 \"test/5_ai_generated_test/rollback_lazy_segtree_snapshot.test.cpp\"\n\n//\
    \ \u5BFE\u8C61: Rollback_Lazy_SegTree<ActedMonoid_Sum_Add<ll>>\u3002\n// independent\
    \ oracle: std::vector<ll> \u306E\u66F4\u65B0\u5C65\u6B74\u3092\u6BCE\u6642\u523B\
    \u30B3\u30D4\u30FC\u3057\u3066\u4FDD\u5B58\u3059\u308B\u3002\n// set/multiply(\u70B9\
    \u3078\u306E\u52A0\u7B97)/apply/get/prod/get_all/prod_all \u3068\u3001\n// monotone\u306A\
    \ sum<=lim \u306B\u3088\u308B max_right/min_left \u3092\u6DF7\u305C\u308B\u3002\
    \n// read-only\u306E\u306F\u305A\u306E query \u304C\u5185\u90E8push\u3067\u5C65\
    \u6B74\u3092\u5897\u3084\u3059\u5834\u5408\u3082\u3042\u308B\u305F\u3081\u3001\
    \n// \u30AF\u30A8\u30EA\u76F4\u5F8C\u306E\u6642\u523B\u3092\u4FDD\u5B58\u3057\u305F\
    \ rollback \u3092\u53CD\u5FA9\u3059\u308B\u3002\n// \u975E\u8CA0\u5024\u306E\u307F\
    \u3092\u4F7F\u7528\u3057\u4E8C\u5206\u63A2\u7D22\u8FF0\u8A9E\u306E\u5358\u8ABF\
    \u6027\u3092\u6E80\u305F\u3059\u3002\n// n=0,1\u30012\u306E\u51AA\u306E\u524D\u5F8C\
    \u306E\u30B5\u30A4\u30BA\u3001\u7A7A\u533A\u9593\u3001\u5168\u533A\u9593\u3001\
    \u518Dbuild \u3092\u691C\u8A3C\u3059\u308B\u3002\n// seed: 0xF273B6D1\u3002\u30C7\
    \u30FC\u30BF\u5024\u3068\u90E8\u5206\u548C\u306F ll \u306E\u5B89\u5168\u7BC4\u56F2\
    \u306B\u9650\u5B9A\u3002\nusing Segment = Rollback_Lazy_SegTree<ActedMonoid_Sum_Add<ll>>;\n\
    struct Checkpoint {\n  pair<int, int> time;\n  vector<ll> vals;\n};\n\n[[noreturn]]\
    \ void fail(int n, int trial, int step, const string& what,\n                \
    \       ll expected, ll actual) {\n  cerr << \"rollback_lazy_segtree: n=\" <<\
    \ n << \" trial=\" << trial\n       << \" step=\" << step << \" \" << what <<\
    \ \" expected=\" << expected\n       << \" actual=\" << actual << '\\n';\n  abort();\n\
    }\n\nvoid verify(Segment& seg, const vector<ll>& a, int trial, int step,\n   \
    \         mt19937& rng, bool thorough) {\n  int n = (int)a.size();\n  ll total\
    \ = accumulate(a.begin(), a.end(), 0LL);\n  if (seg.prod_all() != total)\n   \
    \ fail(n, trial, step, \"prod_all\", total, seg.prod_all());\n  int reps = thorough\
    \ ? 22 : 5;\n  for (int k = 0; k < reps; ++k) {\n    int l = int(rng() % (n +\
    \ 1)), r = int(rng() % (n + 1));\n    if (l > r) swap(l, r);\n    ll expected\
    \ = accumulate(a.begin() + l, a.begin() + r, 0LL);\n    ll actual = seg.prod(l,\
    \ r);\n    if (actual != expected)\n      fail(n, trial, step, \"prod[\" + to_string(l)\
    \ + \",\" + to_string(r) + \")\", expected, actual);\n\n    int from = int(rng()\
    \ % (n + 1));\n    int to = int(rng() % (n + 1));\n    ll limit = ll(rng() % (total\
    \ + 3));\n    auto check = [&](ll x) { return x <= limit; };\n    int mr = from;\n\
    \    ll sum = 0;\n    while (mr < n && sum + a[mr] <= limit) sum += a[mr++];\n\
    \    actual = seg.max_right(check, from);\n    if (actual != mr)\n      fail(n,\
    \ trial, step, \"max_right(start=\" + to_string(from) + \")\", mr, actual);\n\n\
    \    int ml = to;\n    sum = 0;\n    while (ml > 0 && sum + a[ml - 1] <= limit)\
    \ sum += a[--ml];\n    actual = seg.min_left(check, to);\n    if (actual != ml)\n\
    \      fail(n, trial, step, \"min_left(end=\" + to_string(to) + \")\", ml, actual);\n\
    \  }\n  if (thorough) {\n    auto all = seg.get_all();\n    if (all != a) {\n\
    \      cerr << \"rollback_lazy_segtree: get_all mismatch n=\" << n\n         \
    \  << \" trial=\" << trial << \" step=\" << step << '\\n';\n      abort();\n \
    \   }\n    for (int i = 0; i < n; ++i)\n      if (seg.get(i) != a[i])\n      \
    \  fail(n, trial, step, \"get(\" + to_string(i) + \")\", a[i], seg.get(i));\n\
    \  }\n}\n\nint main() {\n  mt19937 rng(0xF273B6D1);\n  for (int n : {0, 1, 2,\
    \ 3, 7, 8, 9, 15, 16, 17, 31, 32, 33}) {\n    for (int trial = 0; trial < 12;\
    \ ++trial) {\n      vector<ll> a(n);\n      for (ll& x : a) x = ll(rng() % 9);\n\
    \      Segment seg;\n      // \u4E21\u5F62\u5F0F\u3067build\u3057\u3066\u3001\u518D\
    build\u5F8C\u306E\u65E7\u5C65\u6B74\u6DF7\u5165\u3092\u30C1\u30A7\u30C3\u30AF\u3059\
    \u308B\u3002\n      seg.build(n, [&](int i) -> ll { return i + 1; });\n      seg.build(a);\n\
    \      vector<Checkpoint> history = {{seg.time(), a}};\n      for (int step =\
    \ 0; step < 420; ++step) {\n        int op = int(rng() % 12);\n        if (op\
    \ == 0 && history.size() > 1) {\n          int idx = int(rng() % history.size());\n\
    \          seg.rollback(history[idx].time);\n          a = history[idx].vals;\n\
    \          history.resize(idx + 1);\n        } else if (n > 0 && (op == 1 || op\
    \ == 2)) {\n          int pos = int(rng() % n);\n          ll x = ll(rng() % 40);\n\
    \          if (op == 1) {\n            seg.set(pos, x);\n            a[pos] =\
    \ x;\n          } else {\n            seg.multiply(pos, x);\n            a[pos]\
    \ += x;\n          }\n        } else if (op <= 6) {\n          int l = int(rng()\
    \ % (n + 1)), r = int(rng() % (n + 1));\n          if (l > r) swap(l, r);\n  \
    \        ll increment = ll(rng() % 10);\n          seg.apply(l, r, increment);\n\
    \          for (int i = l; i < r; ++i) a[i] += increment;\n        } else {\n\
    \          // \u660E\u793A\u7684\u306A\u53D6\u5F97\u64CD\u4F5C\u3092\u591A\u6570\
    \u6DF7\u305C\u3001push\u306B\u3088\u308B\u5185\u90E8\u5C65\u6B74\u3082\u5DFB\u304D\
    \u623B\u3059\u3002\n          int l = int(rng() % (n + 1)), r = int(rng() % (n\
    \ + 1));\n          if (l > r) swap(l, r);\n          ll expected = accumulate(a.begin()\
    \ + l, a.begin() + r, 0LL);\n          ll actual = seg.prod(l, r);\n         \
    \ if (actual != expected) fail(n, trial, step, \"query\", expected, actual);\n\
    \        }\n        verify(seg, a, trial, step, rng, (step % 17 == 0));\n    \
    \    history.push_back({seg.time(), a});\n      }\n      seg.rollback(history[0].time);\n\
    \      verify(seg, history[0].vals, trial, 421, rng, true);\n    }\n  }\n  return\
    \ 0;\n}\n"
  code: "#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/acted_monoid/sum_add.hpp\"\
    \n#include \"ds/segtree/rollback_lazy_segtree.hpp\"\n\n// \u5BFE\u8C61: Rollback_Lazy_SegTree<ActedMonoid_Sum_Add<ll>>\u3002\
    \n// independent oracle: std::vector<ll> \u306E\u66F4\u65B0\u5C65\u6B74\u3092\u6BCE\
    \u6642\u523B\u30B3\u30D4\u30FC\u3057\u3066\u4FDD\u5B58\u3059\u308B\u3002\n// set/multiply(\u70B9\
    \u3078\u306E\u52A0\u7B97)/apply/get/prod/get_all/prod_all \u3068\u3001\n// monotone\u306A\
    \ sum<=lim \u306B\u3088\u308B max_right/min_left \u3092\u6DF7\u305C\u308B\u3002\
    \n// read-only\u306E\u306F\u305A\u306E query \u304C\u5185\u90E8push\u3067\u5C65\
    \u6B74\u3092\u5897\u3084\u3059\u5834\u5408\u3082\u3042\u308B\u305F\u3081\u3001\
    \n// \u30AF\u30A8\u30EA\u76F4\u5F8C\u306E\u6642\u523B\u3092\u4FDD\u5B58\u3057\u305F\
    \ rollback \u3092\u53CD\u5FA9\u3059\u308B\u3002\n// \u975E\u8CA0\u5024\u306E\u307F\
    \u3092\u4F7F\u7528\u3057\u4E8C\u5206\u63A2\u7D22\u8FF0\u8A9E\u306E\u5358\u8ABF\
    \u6027\u3092\u6E80\u305F\u3059\u3002\n// n=0,1\u30012\u306E\u51AA\u306E\u524D\u5F8C\
    \u306E\u30B5\u30A4\u30BA\u3001\u7A7A\u533A\u9593\u3001\u5168\u533A\u9593\u3001\
    \u518Dbuild \u3092\u691C\u8A3C\u3059\u308B\u3002\n// seed: 0xF273B6D1\u3002\u30C7\
    \u30FC\u30BF\u5024\u3068\u90E8\u5206\u548C\u306F ll \u306E\u5B89\u5168\u7BC4\u56F2\
    \u306B\u9650\u5B9A\u3002\nusing Segment = Rollback_Lazy_SegTree<ActedMonoid_Sum_Add<ll>>;\n\
    struct Checkpoint {\n  pair<int, int> time;\n  vector<ll> vals;\n};\n\n[[noreturn]]\
    \ void fail(int n, int trial, int step, const string& what,\n                \
    \       ll expected, ll actual) {\n  cerr << \"rollback_lazy_segtree: n=\" <<\
    \ n << \" trial=\" << trial\n       << \" step=\" << step << \" \" << what <<\
    \ \" expected=\" << expected\n       << \" actual=\" << actual << '\\n';\n  abort();\n\
    }\n\nvoid verify(Segment& seg, const vector<ll>& a, int trial, int step,\n   \
    \         mt19937& rng, bool thorough) {\n  int n = (int)a.size();\n  ll total\
    \ = accumulate(a.begin(), a.end(), 0LL);\n  if (seg.prod_all() != total)\n   \
    \ fail(n, trial, step, \"prod_all\", total, seg.prod_all());\n  int reps = thorough\
    \ ? 22 : 5;\n  for (int k = 0; k < reps; ++k) {\n    int l = int(rng() % (n +\
    \ 1)), r = int(rng() % (n + 1));\n    if (l > r) swap(l, r);\n    ll expected\
    \ = accumulate(a.begin() + l, a.begin() + r, 0LL);\n    ll actual = seg.prod(l,\
    \ r);\n    if (actual != expected)\n      fail(n, trial, step, \"prod[\" + to_string(l)\
    \ + \",\" + to_string(r) + \")\", expected, actual);\n\n    int from = int(rng()\
    \ % (n + 1));\n    int to = int(rng() % (n + 1));\n    ll limit = ll(rng() % (total\
    \ + 3));\n    auto check = [&](ll x) { return x <= limit; };\n    int mr = from;\n\
    \    ll sum = 0;\n    while (mr < n && sum + a[mr] <= limit) sum += a[mr++];\n\
    \    actual = seg.max_right(check, from);\n    if (actual != mr)\n      fail(n,\
    \ trial, step, \"max_right(start=\" + to_string(from) + \")\", mr, actual);\n\n\
    \    int ml = to;\n    sum = 0;\n    while (ml > 0 && sum + a[ml - 1] <= limit)\
    \ sum += a[--ml];\n    actual = seg.min_left(check, to);\n    if (actual != ml)\n\
    \      fail(n, trial, step, \"min_left(end=\" + to_string(to) + \")\", ml, actual);\n\
    \  }\n  if (thorough) {\n    auto all = seg.get_all();\n    if (all != a) {\n\
    \      cerr << \"rollback_lazy_segtree: get_all mismatch n=\" << n\n         \
    \  << \" trial=\" << trial << \" step=\" << step << '\\n';\n      abort();\n \
    \   }\n    for (int i = 0; i < n; ++i)\n      if (seg.get(i) != a[i])\n      \
    \  fail(n, trial, step, \"get(\" + to_string(i) + \")\", a[i], seg.get(i));\n\
    \  }\n}\n\nint main() {\n  mt19937 rng(0xF273B6D1);\n  for (int n : {0, 1, 2,\
    \ 3, 7, 8, 9, 15, 16, 17, 31, 32, 33}) {\n    for (int trial = 0; trial < 12;\
    \ ++trial) {\n      vector<ll> a(n);\n      for (ll& x : a) x = ll(rng() % 9);\n\
    \      Segment seg;\n      // \u4E21\u5F62\u5F0F\u3067build\u3057\u3066\u3001\u518D\
    build\u5F8C\u306E\u65E7\u5C65\u6B74\u6DF7\u5165\u3092\u30C1\u30A7\u30C3\u30AF\u3059\
    \u308B\u3002\n      seg.build(n, [&](int i) -> ll { return i + 1; });\n      seg.build(a);\n\
    \      vector<Checkpoint> history = {{seg.time(), a}};\n      for (int step =\
    \ 0; step < 420; ++step) {\n        int op = int(rng() % 12);\n        if (op\
    \ == 0 && history.size() > 1) {\n          int idx = int(rng() % history.size());\n\
    \          seg.rollback(history[idx].time);\n          a = history[idx].vals;\n\
    \          history.resize(idx + 1);\n        } else if (n > 0 && (op == 1 || op\
    \ == 2)) {\n          int pos = int(rng() % n);\n          ll x = ll(rng() % 40);\n\
    \          if (op == 1) {\n            seg.set(pos, x);\n            a[pos] =\
    \ x;\n          } else {\n            seg.multiply(pos, x);\n            a[pos]\
    \ += x;\n          }\n        } else if (op <= 6) {\n          int l = int(rng()\
    \ % (n + 1)), r = int(rng() % (n + 1));\n          if (l > r) swap(l, r);\n  \
    \        ll increment = ll(rng() % 10);\n          seg.apply(l, r, increment);\n\
    \          for (int i = l; i < r; ++i) a[i] += increment;\n        } else {\n\
    \          // \u660E\u793A\u7684\u306A\u53D6\u5F97\u64CD\u4F5C\u3092\u591A\u6570\
    \u6DF7\u305C\u3001push\u306B\u3088\u308B\u5185\u90E8\u5C65\u6B74\u3082\u5DFB\u304D\
    \u623B\u3059\u3002\n          int l = int(rng() % (n + 1)), r = int(rng() % (n\
    \ + 1));\n          if (l > r) swap(l, r);\n          ll expected = accumulate(a.begin()\
    \ + l, a.begin() + r, 0LL);\n          ll actual = seg.prod(l, r);\n         \
    \ if (actual != expected) fail(n, trial, step, \"query\", expected, actual);\n\
    \        }\n        verify(seg, a, trial, step, rng, (step % 17 == 0));\n    \
    \    history.push_back({seg.time(), a});\n      }\n      seg.rollback(history[0].time);\n\
    \      verify(seg, history[0].vals, trial, 421, rng, true);\n    }\n  }\n  return\
    \ 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/acted_monoid/sum_add.hpp
  - alg/monoid/add.hpp
  - ds/segtree/rollback_lazy_segtree.hpp
  - ds/rollback_array.hpp
  isVerificationFile: true
  path: test/5_ai_generated_test/rollback_lazy_segtree_snapshot.test.cpp
  requiredBy: []
  timestamp: '2026-11-23 02:04:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/5_ai_generated_test/rollback_lazy_segtree_snapshot.test.cpp
layout: document
redirect_from:
- /verify/test/5_ai_generated_test/rollback_lazy_segtree_snapshot.test.cpp
- /verify/test/5_ai_generated_test/rollback_lazy_segtree_snapshot.test.cpp.html
title: test/5_ai_generated_test/rollback_lazy_segtree_snapshot.test.cpp
---
