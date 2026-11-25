---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':heavy_check_mark:'
    path: ds/segtree/range_min.hpp
    title: ds/segtree/range_min.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/staticrmq_simd.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#line 1 \"\
    my_template.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n\
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 5 \"test/2_library_checker/data_structure/staticrmq_simd.test.cpp\"\
    \n\n#line 1 \"ds/segtree/range_min.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/range_min.hpp\n\
    \n#line 1 \"alg/monoid/min.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/min.hpp\n\
    // require: all values x satisfy x < infty<E>\ntemplate <typename E>\nstruct Monoid_Min\
    \ {\n  using X = E;\n  using value_type = X;\n  static constexpr X op(const X\
    \ &x, const X &y) noexcept { return min(x, y); }\n  static constexpr X id() {\
    \ return infty<E>; }\n  static constexpr bool commute = true;\n};\n#line 4 \"\
    ds/segtree/range_min.hpp\"\n\n// 2026/11/04 AI generated.\n\n#if defined(__x86_64__)\
    \ && (defined(__GNUC__) || defined(__clang__))\n#include <immintrin.h>\n#define\
    \ RANGE_MIN_AVX2 1\n#else\n#define RANGE_MIN_AVX2 0\n#endif\n\ntemplate <typename\
    \ T>\nstruct Range_Min {\n  static_assert(is_same_v<T, int> || is_same_v<T, ll>);\n\
    \  using value_type = T;\n  using MX = Monoid_Min<T>;\n\n  static constexpr T\
    \ INF = infty<T>;\n  static constexpr int B = 64 / sizeof(T);\n\n  struct alignas(64)\
    \ Block {\n    T a[B];\n  };\n  static_assert(sizeof(Block) == 64);\n\n  int n\
    \ = 0;\n\n private:\n  vc<vc<Block>> dat;\n  bool use_avx2 = false;\n\n  static\
    \ T reduce_scalar(const T* p) {\n    T x = INF;\n    for (int j = 0; j < B; ++j)\
    \ x = min(x, p[j]);\n    return x;\n  }\n\n  static T range_scalar(const T* p,\
    \ int l, int r) {\n    T x = INF;\n    for (int j = l; j < r; ++j) x = min(x,\
    \ p[j]);\n    return x;\n  }\n\n#if RANGE_MIN_AVX2\n  __attribute__((target(\"\
    avx2\"))) static __m256i min64(__m256i a, __m256i b) {\n    return _mm256_blendv_epi8(a,\
    \ b, _mm256_cmpgt_epi64(a, b));\n  }\n\n  __attribute__((target(\"avx2\"))) static\
    \ T reduce_avx2(const T* p) {\n    if constexpr (is_same_v<T, int>) {\n      __m256i\
    \ a = _mm256_loadu_si256((const __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const\
    \ __m256i*)(p + 8));\n      a = _mm256_min_epi32(a, b);\n      a = _mm256_min_epi32(a,\
    \ _mm256_permute2x128_si256(a, a, 1));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a,\
    \ 0x4e));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n   \
    \   return _mm256_extract_epi32(a, 0);\n    } else {\n      __m256i a = _mm256_loadu_si256((const\
    \ __m256i*)p);\n      __m256i b = _mm256_loadu_si256((const __m256i*)(p + 4));\n\
    \      a = min64(a, b);\n      a = min64(a, _mm256_permute4x64_epi64(a, 0x4e));\n\
    \      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));\n      return (T)_mm256_extract_epi64(a,\
    \ 0);\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) static T range_avx2(\n\
    \      const T* p, int l, int r) {\n    if constexpr (is_same_v<T, int>) {\n \
    \     __m256i lo = _mm256_set1_epi32(l - 1);\n      __m256i hi = _mm256_set1_epi32(r);\n\
    \      __m256i x = _mm256_setr_epi32(0, 1, 2, 3, 4, 5, 6, 7);\n      __m256i y\
    \ = _mm256_setr_epi32(8, 9, 10, 11, 12, 13, 14, 15);\n      __m256i mx = _mm256_and_si256(\n\
    \          _mm256_cmpgt_epi32(x, lo), _mm256_cmpgt_epi32(hi, x));\n      __m256i\
    \ my = _mm256_and_si256(\n          _mm256_cmpgt_epi32(y, lo), _mm256_cmpgt_epi32(hi,\
    \ y));\n      __m256i inf = _mm256_set1_epi32(INF);\n      __m256i a =\n     \
    \     _mm256_blendv_epi8(inf, _mm256_loadu_si256((const __m256i*)p), mx);\n  \
    \    __m256i b = _mm256_blendv_epi8(\n          inf, _mm256_loadu_si256((const\
    \ __m256i*)(p + 8)), my);\n      a = _mm256_min_epi32(a, b);\n      a = _mm256_min_epi32(a,\
    \ _mm256_permute2x128_si256(a, a, 1));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a,\
    \ 0x4e));\n      a = _mm256_min_epi32(a, _mm256_shuffle_epi32(a, 0xb1));\n   \
    \   return _mm256_extract_epi32(a, 0);\n    } else {\n      __m256i lo = _mm256_set1_epi64x(l\
    \ - 1);\n      __m256i hi = _mm256_set1_epi64x(r);\n      __m256i x = _mm256_setr_epi64x(0,\
    \ 1, 2, 3);\n      __m256i y = _mm256_setr_epi64x(4, 5, 6, 7);\n      __m256i\
    \ mx = _mm256_and_si256(\n          _mm256_cmpgt_epi64(x, lo), _mm256_cmpgt_epi64(hi,\
    \ x));\n      __m256i my = _mm256_and_si256(\n          _mm256_cmpgt_epi64(y,\
    \ lo), _mm256_cmpgt_epi64(hi, y));\n      __m256i inf = _mm256_set1_epi64x(INF);\n\
    \      __m256i a =\n          _mm256_blendv_epi8(inf, _mm256_loadu_si256((const\
    \ __m256i*)p), mx);\n      __m256i b = _mm256_blendv_epi8(\n          inf, _mm256_loadu_si256((const\
    \ __m256i*)(p + 4)), my);\n      a = min64(a, b);\n      a = min64(a, _mm256_permute4x64_epi64(a,\
    \ 0x4e));\n      a = min64(a, _mm256_permute4x64_epi64(a, 0xb1));\n      return\
    \ (T)_mm256_extract_epi64(a, 0);\n    }\n  }\n#endif\n\n  // min \u56FA\u6709\u306E\
    \u66F4\u65B0\u6700\u9069\u5316\n  template <typename F>\n  void set_by(int i,\
    \ T x, F reduce) {\n    T& a = dat[0][i / B].a[i % B];\n    T old = a;\n    if\
    \ (old == x) return;\n    a = x;\n\n    for (int k = 0; k + 1 < (int)dat.size();\
    \ ++k) {\n      int b = i / B;\n      T& p = dat[k + 1][b / B].a[b % B];\n   \
    \   T old_p = p;\n      T new_p;\n\n      if (x < old) {\n        new_p = min(old_p,\
    \ x);\n      } else {\n        if (old > old_p) break;\n        new_p = reduce(dat[k][b].a);\n\
    \      }\n\n      if (new_p == old_p) break;\n      p = new_p;\n      old = old_p;\n\
    \      x = new_p;\n      i = b;\n    }\n  }\n\n  template <typename F>\n  T prod_by(int\
    \ l, int r, F reduce) const {\n    T ans = INF;\n    for (const auto& level :\
    \ dat) {\n      if (l >= r) break;\n      int a = l / B, b = (r - 1) / B;\n  \
    \    if (a == b) {\n        return min(ans, reduce(level[a].a, l % B, (r - 1)\
    \ % B + 1));\n      }\n      if (l % B) {\n        ans = min(ans, reduce(level[a].a,\
    \ l % B, B));\n        l = (a + 1) * B;\n      }\n      if (r % B) {\n       \
    \ ans = min(ans, reduce(level[b].a, 0, r % B));\n        r = b * B;\n      }\n\
    \      l /= B;\n      r /= B;\n    }\n    return ans;\n  }\n\n#if RANGE_MIN_AVX2\n\
    \  __attribute__((target(\"avx2\"))) void set_avx2(int i, T x) {\n    set_by(i,\
    \ x, reduce_avx2);\n  }\n\n  __attribute__((target(\"avx2\"))) T prod_avx2(int\
    \ l, int r) const {\n    return prod_by(l, r, range_avx2);\n  }\n#endif\n\n  //\
    \ k \u6BB5\u76EE\u306E\u5931\u6557\u3057\u305F\u8981\u7D20\u304B\u3089\u8449\u3078\
    \u964D\u308A\u308B\n  template <typename F>\n  int descend_right(int k, int i,\
    \ T sm, F& check) const {\n    for (--k; k >= 0; --k) {\n      const auto& v =\
    \ dat[k][i].a;\n      for (int j = 0; j < B; ++j) {\n        T y = min(sm, v[j]);\n\
    \        if (!check(y)) {\n          i = B * i + j;\n          break;\n      \
    \  }\n        sm = y;\n      }\n    }\n    return min(i, n);\n  }\n\n  template\
    \ <typename F>\n  int descend_left(int k, int i, T sm, F& check) const {\n   \
    \ for (--k; k >= 0; --k) {\n      const auto& v = dat[k][i].a;\n      for (int\
    \ j = B - 1; j >= 0; --j) {\n        T y = min(v[j], sm);\n        if (!check(y))\
    \ {\n          i = B * i + j;\n          break;\n        }\n        sm = y;\n\
    \      }\n    }\n    return min(i + 1, n);\n  }\n\n public:\n  Range_Min() { build(0);\
    \ }\n  Range_Min(int m) { build(m); }\n  Range_Min(const vc<T>& a) { build(a);\
    \ }\n\n  template <typename F>\n  Range_Min(int m, F f) {\n    build(m, f);\n\
    \  }\n\n  void build(int m) {\n    build(m, [](int) -> T { return INF; });\n \
    \ }\n\n  void build(const vc<T>& a) {\n    build((int)a.size(), [&](int i) ->\
    \ T { return a[i]; });\n  }\n\n  template <typename F>\n  void build(int m, F\
    \ f) {\n    assert(m >= 0);\n    n = m;\n    vc<T> cur(max(m, 1));\n    for (int\
    \ i = 0; i < m; ++i) cur[i] = f(i);\n    if (!m) cur[0] = INF;\n\n    dat.clear();\n\
    \    while (true) {\n      int sz = ((int)cur.size() + B - 1) / B;\n      dat.emplace_back(sz);\n\
    \      vc<T> nxt(sz);\n\n      for (int b = 0; b < sz; ++b) {\n        T* p =\
    \ dat.back()[b].a;\n        fill(p, p + B, INF);\n        for (int j = 0; j <\
    \ B && b * B + j < (int)cur.size(); ++j) {\n          p[j] = cur[b * B + j];\n\
    \        }\n        nxt[b] = reduce_scalar(p);\n      }\n      if (cur.size()\
    \ == 1) break;\n      cur.swap(nxt);\n    }\n\n    use_avx2 = false;\n#if RANGE_MIN_AVX2\n\
    \    __builtin_cpu_init();\n    use_avx2 = __builtin_cpu_supports(\"avx2\");\n\
    #endif\n  }\n\n  T get(int i) const {\n    assert(0 <= i && i < n);\n    return\
    \ dat[0][i / B].a[i % B];\n  }\n\n  vc<T> get_all() const {\n    vc<T> a(n);\n\
    \    for (int i = 0; i < n; ++i) {\n      a[i] = dat[0][i / B].a[i % B];\n   \
    \ }\n    return a;\n  }\n\n  void set(int i, const T& x) {\n    assert(0 <= i\
    \ && i < n);\n#if RANGE_MIN_AVX2\n    if (use_avx2) return set_avx2(i, x);\n#endif\n\
    \    set_by(i, x, reduce_scalar);\n  }\n\n  void multiply(int i, const T& x) {\
    \ set(i, min(get(i), x)); }\n\n  T prod(int l, int r) const {\n    assert(0 <=\
    \ l && l <= r && r <= n);\n#if RANGE_MIN_AVX2\n    if (use_avx2) return prod_avx2(l,\
    \ r);\n#endif\n    return prod_by(l, r, range_scalar);\n  }\n\n  T prod_all()\
    \ const { return dat.back()[0].a[0]; }\n\n  template <typename F>\n  int max_right(F\
    \ check, int L) const {\n    assert(0 <= L && L <= n && check(INF));\n    if (L\
    \ == n) return n;\n    T sm = INF;\n    int i = L;\n\n    for (int k = 0; k <\
    \ (int)dat.size(); ++k) {\n      if (i % B || k + 1 == (int)dat.size()) {\n  \
    \      int b = i / B;\n        for (int j = i % B; j < B; ++j) {\n          T\
    \ y = min(sm, dat[k][b].a[j]);\n          if (!check(y)) {\n            return\
    \ descend_right(k, b * B + j, sm, check);\n          }\n          sm = y;\n  \
    \      }\n        i = b + 1;\n      } else {\n        i /= B;\n      }\n    }\n\
    \    return n;\n  }\n\n  template <typename F>\n  int min_left(F check, int R)\
    \ const {\n    assert(0 <= R && R <= n && check(INF));\n    if (R == 0) return\
    \ 0;\n    T sm = INF;\n    int i = R;\n\n    for (int k = 0; k < (int)dat.size();\
    \ ++k) {\n      if (i % B || k + 1 == (int)dat.size()) {\n        if (i == 0)\
    \ return 0;\n        int b = (i - 1) / B;\n        for (int j = (i - 1) % B; j\
    \ >= 0; --j) {\n          T y = min(dat[k][b].a[j], sm);\n          if (!check(y))\
    \ {\n            return descend_left(k, b * B + j, sm, check);\n          }\n\
    \          sm = y;\n        }\n        i = b;\n      } else {\n        i /= B;\n\
    \      }\n    }\n    return 0;\n  }\n};\n\n#undef RANGE_MIN_AVX2\n#line 7 \"test/2_library_checker/data_structure/staticrmq_simd.test.cpp\"\
    \n\nvoid solve() {\n  INT(N, Q);\n  Range_Min<int> seg(N, [&](int i) -> int {\n\
    \    INT(x);\n    return x;\n  });\n  FOR(Q) {\n    INT(l, r);\n    print(seg.prod(l,\
    \ r));\n  }\n}\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/segtree/range_min.hpp\"\
    \n\nvoid solve() {\n  INT(N, Q);\n  Range_Min<int> seg(N, [&](int i) -> int {\n\
    \    INT(x);\n    return x;\n  });\n  FOR(Q) {\n    INT(l, r);\n    print(seg.prod(l,\
    \ r));\n  }\n}\n\nsigned main() {\n  int T = 1;\n  // INT(T);\n  FOR(T) solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/segtree/range_min.hpp
  - alg/monoid/min.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/staticrmq_simd.test.cpp
  requiredBy: []
  timestamp: '2026-11-25 16:46:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/staticrmq_simd.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/staticrmq_simd.test.cpp
- /verify/test/2_library_checker/data_structure/staticrmq_simd.test.cpp.html
title: test/2_library_checker/data_structure/staticrmq_simd.test.cpp
---
