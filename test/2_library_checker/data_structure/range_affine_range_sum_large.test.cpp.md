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
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: Range Affine Range Sum (Large Array)
    links: []
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp\"\
    \n#define PROBLEM \"Range Affine Range Sum (Large Array)\"\n#line 1 \"my_template.hpp\"\
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 4 \"test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp\"\
    \n\n#line 1 \"mod/modint.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/mod/modint.hpp\n\
    #line 1 \"mod/modint_common.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/mod/modint_common.hpp\n\
    \n\nstruct has_mod_impl {\n  template <class T>\n  static auto check(T &&x) ->\
    \ decltype(x.get_mod(), std::true_type{});\n  template <class T>\n  static auto\
    \ check(...) -> std::false_type;\n};\n\ntemplate <class T>\nclass has_mod : public\
    \ decltype(has_mod_impl::check<T>(std::declval<T>())) {};\n\ntemplate <typename\
    \ mint>\nmint fact(int n) {\n  static vector<mint> dat = {1, 1};\n  static int\
    \ mod = 0;\n  if (mod != mint::get_mod()) {\n    mod = mint::get_mod();\n    dat\
    \ = {1, 1};\n  }\n  assert(0 <= n && n < mod);\n  if (len(dat) <= n) {\n    int\
    \ now = len(dat);\n    int m = min(mod, 1 << (topbit(n) + 1));\n    dat.resize(m);\n\
    \    FOR(i, now, m) dat[i] = dat[i - 1] * mint::raw(i);\n  }\n  return dat[n];\n\
    }\n\ntemplate <typename mint>\nmint fact_inv(int n) {\n  if (n < 0) return mint(0);\n\
    \  static vector<mint> dat = {1, 1};\n  static int mod = 0;\n  if (mod != mint::get_mod())\
    \ {\n    mod = mint::get_mod();\n    dat = {1, 1};\n  }\n  assert(0 <= n && n\
    \ < mod);\n  if (len(dat) <= n) {\n    int now = len(dat);\n    int m = min(mod,\
    \ 1 << (topbit(n) + 1));\n    dat.resize(m);\n    dat[m - 1] = fact<mint>(m -\
    \ 1).inverse();\n    FOR_R(i, now, m - 1) dat[i] = dat[i + 1] * mint::raw(i +\
    \ 1);\n  }\n  return dat[n];\n}\n\ntemplate <class mint, class... Ts>\nmint fact_invs(Ts...\
    \ xs) {\n  return (mint(1) * ... * fact_inv<mint>(xs));\n}\n\ntemplate <typename\
    \ mint>\nmint inv(int n) {\n  return fact<mint>(n - 1) * fact_inv<mint>(n);\n\
    }\n\ntemplate <>\ndouble inv<double>(int n) {\n  assert(n != 0);\n  return 1.0\
    \ / n;\n}\n\ntemplate <typename mint, class Head, class... Tail>\nmint multinomial(Head\
    \ &&head, Tail &&...tail) {\n  return fact<mint>(head) * fact_invs<mint>(std::forward<Tail>(tail)...);\n\
    }\n\ntemplate <typename mint>\nmint C_dense(int n, int k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  static vvc<mint> C;\n  static int H = 0, W\
    \ = 0;\n  static int mod = 0;\n  if (mod != mint::get_mod()) {\n    mod = mint::get_mod();\n\
    \    C.clear();\n    H = W = 0;\n  }\n  auto calc = [&](int i, int j) -> mint\
    \ {\n    if (i == 0) return (j == 0 ? mint(1) : mint(0));\n    return C[i - 1][j]\
    \ + (j ? C[i - 1][j - 1] : 0);\n  };\n  if (W <= k) {\n    FOR(i, H) {\n     \
    \ C[i].resize(k + 1);\n      FOR(j, W, k + 1) { C[i][j] = calc(i, j); }\n    }\n\
    \    W = k + 1;\n  }\n  if (H <= n) {\n    C.resize(n + 1);\n    FOR(i, H, n +\
    \ 1) {\n      C[i].resize(W);\n      FOR(j, W) { C[i][j] = calc(i, j); }\n   \
    \ }\n    H = n + 1;\n  }\n  return C[n][k];\n}\n\ntemplate <typename mint, bool\
    \ large = false, bool dense = false>\nmint C(ll n, ll k) {\n  assert(n >= 0);\n\
    \  if (k < 0 || n < k) return 0;\n  if constexpr (dense) return C_dense<mint>(n,\
    \ k);\n  if constexpr (!large) return multinomial<mint>(n, k, n - k);\n  k = min(k,\
    \ n - k);\n  mint x(1);\n  FOR(i, k) x *= mint(n - i);\n  return x * fact_inv<mint>(k);\n\
    }\n\ntemplate <typename mint, bool large = false>\nmint C_inv(ll n, ll k) {\n\
    \  assert(n >= 0);\n  assert(0 <= k && k <= n);\n  if (!large) return fact_inv<mint>(n)\
    \ * fact<mint>(k) * fact<mint>(n - k);\n  return mint(1) / C<mint, 1>(n, k);\n\
    }\n\n// [x^d](1-x)^{-n}\ntemplate <typename mint, bool large = false, bool dense\
    \ = false>\nmint C_negative(ll n, ll d) {\n  assert(n >= 0);\n  if (d < 0) return\
    \ mint(0);\n  if (n == 0) {\n    return (d == 0 ? mint(1) : mint(0));\n  }\n \
    \ return C<mint, large, dense>(n + d - 1, d);\n}\n#line 3 \"mod/modint.hpp\"\n\
    \ntemplate <int mod>\nstruct modint {\n  static constexpr u32 umod = u32(mod);\n\
    \  static_assert(0 < umod && umod < u32(1) << 31);\n  u32 val;\n\n  static modint\
    \ raw(u32 v) {\n    modint x;\n    x.val = v;\n    return x;\n  }\n  constexpr\
    \ modint() : val(0) {}\n  constexpr modint(u32 x) : val(x % umod) {}\n  constexpr\
    \ modint(u64 x) : val(x % umod) {}\n  constexpr modint(u128 x) : val(x % umod)\
    \ {}\n  constexpr modint(int x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr\
    \ modint(ll x) : val((x %= mod) < 0 ? x + mod : x){};\n  constexpr modint(i128\
    \ x) : val((x %= mod) < 0 ? x + mod : x){};\n  bool operator<(const modint &other)\
    \ const { return val < other.val; }\n  modint &operator+=(const modint &p) {\n\
    \    if ((val += p.val) >= umod) val -= umod;\n    return *this;\n  }\n  modint\
    \ &operator-=(const modint &p) {\n    if ((val += umod - p.val) >= umod) val -=\
    \ umod;\n    return *this;\n  }\n  modint &operator*=(const modint &p) {\n   \
    \ val = u64(val) * p.val % umod;\n    return *this;\n  }\n  modint &operator/=(const\
    \ modint &p) {\n    *this *= p.inverse();\n    return *this;\n  }\n  modint operator-()\
    \ const { return modint::raw(val ? mod - val : u32(0)); }\n  modint operator+(const\
    \ modint &p) const { return modint(*this) += p; }\n  modint operator-(const modint\
    \ &p) const { return modint(*this) -= p; }\n  modint operator*(const modint &p)\
    \ const { return modint(*this) *= p; }\n  modint operator/(const modint &p) const\
    \ { return modint(*this) /= p; }\n  bool operator==(const modint &p) const { return\
    \ val == p.val; }\n  bool operator!=(const modint &p) const { return val != p.val;\
    \ }\n  // gcd=1 \u3067\u3042\u308B\u524D\u63D0\n  modint inverse() const {\n \
    \   int a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n      t = a /\
    \ b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    assert(a ==\
    \ 1);\n    return modint(u);\n  }\n  modint pow(ll n) const {\n    if (n < 0)\
    \ return inverse().pow(-n);\n    assert(n >= 0);\n    modint ret(1), mul(val);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n  static constexpr int get_mod() { return\
    \ mod; }\n  // (n, r), r \u306F 1 \u306E 2^n \u4E57\u6839\n  static constexpr\
    \ pair<int, int> ntt_info() {\n    if (mod == 120586241) return {20, 74066978};\n\
    \    if (mod == 167772161) return {25, 17};\n    if (mod == 469762049) return\
    \ {26, 30};\n    if (mod == 754974721) return {24, 362};\n    if (mod == 880803841)\
    \ return {23, 211};\n    if (mod == 943718401) return {22, 663003469};\n    if\
    \ (mod == 998244353) return {23, 31};\n    if (mod == 1004535809) return {21,\
    \ 582313106};\n    if (mod == 1012924417) return {21, 368093570};\n    if (mod\
    \ == 1224736769) return {24, 1191450770};\n    if (mod == 2013265921) return {27,\
    \ 244035102};\n    return {-1, -1};\n  }\n  static constexpr bool can_ntt() {\
    \ return ntt_info().fi != -1; }\n};\n\n#ifdef FASTIO\ntemplate <int mod>\nvoid\
    \ rd(modint<mod> &x) {\n  fastio::rd(x.val);\n  x.val %= mod;\n  // assert(0 <=\
    \ x.val && x.val < mod);\n}\ntemplate <int mod>\nvoid wt(modint<mod> x) {\n  fastio::wt(x.val);\n\
    }\n#endif\n\nusing modint107 = modint<1000000007>;\nusing modint998 = modint<998244353>;\n\
    #line 1 \"alg/acted_monoid/sum_affine.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/acted_monoid/sum_affine.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 1 \"alg/monoid/affine.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/affine.hpp\n\
    \n// op(F, G) = comp(G,F), F \u306E\u3042\u3068\u3067 G\ntemplate <typename K>\n\
    struct Monoid_Affine {\n  using F = pair<K, K>;\n  using value_type = F;\n  using\
    \ X = value_type;\n  static constexpr F op(const F &x, const F &y) noexcept {\n\
    \    return F({x.first * y.first, x.second * y.first + y.second});\n  }\n  static\
    \ constexpr F inverse(const F &x) {\n    auto [a, b] = x;\n    a = K(1) / a;\n\
    \    return {a, a * (-b)};\n  }\n  static constexpr K eval(const F &f, K x) noexcept\
    \ {\n    return f.first * x + f.second;\n  }\n  static constexpr F id() { return\
    \ {K(1), K(0)}; }\n  static constexpr bool commute = false;\n};\n#line 4 \"alg/acted_monoid/sum_affine.hpp\"\
    \n\ntemplate <typename E>\nstruct ActedMonoid_Sum_Affine {\n  using Monoid_X =\
    \ Monoid_Add<E>;\n  using Monoid_A = Monoid_Affine<E>;\n  using X = typename Monoid_X::value_type;\n\
    \  using A = typename Monoid_A::value_type;\n  static constexpr X act(const X\
    \ &x, const A &a, const ll &size) {\n    return x * a.fi + E(size) * a.se;\n \
    \ }\n};\n#line 1 \"ds/segtree/dynamic_lazy_segtree.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/segtree/dynamic_lazy_segtree.hpp\n\
    #line 1 \"ds/node_pool.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/node_pool.hpp\n\
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
    \      pos = 0;\n    }\n    return s;\n  }\n};\n#line 3 \"ds/segtree/dynamic_lazy_segtree.hpp\"\
    \n\ntemplate <typename AM>\nstruct Dynamic_Lazy_SegTree_Default_Prod {\n  using\
    \ MX = typename AM::Monoid_X;\n  using X = typename AM::X;\n  X operator()(ll,\
    \ ll) const { return MX::id(); }\n};\n\n// set, multiply: 2H nodes \u7A0B\u5EA6\
    \n// apply: 4H nodes \u7A0B\u5EA6\ntemplate <typename ActedMonoid, bool PERSISTENT,\n\
    \    typename DefaultProd = Dynamic_Lazy_SegTree_Default_Prod<ActedMonoid>>\n\
    struct Dynamic_Lazy_SegTree {\n  using AM = ActedMonoid;\n  using MX = typename\
    \ AM::Monoid_X;\n  using MA = typename AM::Monoid_A;\n  using X = typename AM::X;\n\
    \  using A = typename AM::A;\n  using F = DefaultProd;\n  F default_prod;\n\n\
    \  struct Node {\n    Node *l, *r;\n    X x;\n    A lazy;\n  };\n\n  Node_Pool<Node>\
    \ pool;\n  const ll L0, R0;\n  using np = Node *;\n\n  Dynamic_Lazy_SegTree(ll\
    \ L0, ll R0, F default_prod = F{})\n      : default_prod(std::move(default_prod)),\
    \ L0(L0), R0(R0) {}\n\n  np new_root() { return new_node(); }\n\n  np new_node(const\
    \ X x) {\n    np c = pool.create();\n    c->l = c->r = nullptr;\n    c->x = x,\
    \ c->lazy = MA::id();\n    return c;\n  }\n\n  np new_node(ll l, ll r) {\n   \
    \ assert(l < r);\n    return new_node(default_prod(l, r));\n  }\n  np new_node()\
    \ { return L0 == R0 ? nullptr : new_node(L0, R0); }\n\n  np new_node(const vc<X>\
    \ &dat) {\n    assert(L0 == 0 && R0 == len(dat));\n    auto dfs = [&](auto &dfs,\
    \ ll l, ll r) -> Node * {\n      if (l == r) return nullptr;\n      if (r - l\
    \ == 1) return new_node(dat[l]);\n      ll m = (l + r) / 2;\n      np l_root =\
    \ dfs(dfs, l, m), r_root = dfs(dfs, m, r);\n      X x = MX::op(l_root->x, r_root->x);\n\
    \      np root = new_node(x);\n      root->l = l_root, root->r = r_root;\n   \
    \   return root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  X prod(np\
    \ root, ll l, ll r) {\n    if (l == r || !root) return MX::id();\n    assert(L0\
    \ <= l && l < r && r <= R0);\n    X x = MX::id();\n    prod_rec(root, L0, R0,\
    \ l, r, x, MA::id());\n    return x;\n  }\n\n  X prod_all(np root) { return prod(root,\
    \ L0, R0); }\n\n  np set(np root, ll i, const X &x) {\n    assert(root && L0 <=\
    \ i && i < R0);\n    root = clone(root);\n    set_rec(root, L0, R0, i, x);\n \
    \   return root;\n  }\n\n  np multiply(np root, ll i, const X &x) {\n    assert(root\
    \ && L0 <= i && i < R0);\n    root = clone(root);\n    multiply_rec(root, L0,\
    \ R0, i, x);\n    return root;\n  }\n\n  np apply(np root, ll l, ll r, const A\
    \ &a) {\n    if (l == r) return root;\n    assert(root && L0 <= l && l < r &&\
    \ r <= R0);\n    root = clone(root);\n    apply_rec(root, L0, R0, l, r, a);\n\
    \    return root;\n  }\n\n  template <typename F>\n  ll max_right(np root, F check,\
    \ ll L) {\n    assert(L0 <= L && L <= R0 && check(MX::id()));\n    if (L == R0)\
    \ return R0;\n    assert(root);\n    X x = MX::id();\n    return max_right_rec(root,\
    \ check, L0, R0, L, x, MA::id());\n  }\n\n  template <typename F>\n  ll min_left(np\
    \ root, F check, ll R) {\n    assert(L0 <= R && R <= R0 && check(MX::id()));\n\
    \    if (R == L0) return L0;\n    assert(root);\n    X x = MX::id();\n    return\
    \ min_left_rec(root, check, L0, R0, R, x, MA::id());\n  }\n\n  // \u751F\u6210\
    \u6E08\u307F\u306E\u8449\u306B\u3064\u3044\u3066 f(idx, val, end) \u3092\u547C\
    \u3076\n  template <typename F>\n  void enumerate(np root, F f) {\n    bool end\
    \ = false;\n    auto dfs = [&](auto &dfs, np c, ll l, ll r, A a) -> void {\n \
    \     if (!c) return;\n      if (r - l == 1) {\n        f(l, AM::act(c->x, a,\
    \ 1), end);\n        return;\n      }\n      ll m = (l + r) / 2;\n      a = MA::op(c->lazy,\
    \ a);\n      dfs(dfs, c->l, l, m, a);\n      if (end) return;\n      dfs(dfs,\
    \ c->r, m, r, a);\n      if (end) return;\n    };\n    dfs(dfs, root, L0, R0,\
    \ MA::id());\n  }\n\n  void reset() { pool.reset(); }\n\n  // root[l:r) \u3092\
    \ apply(other[l:r),a) \u3067\u4E0A\u66F8\u304D\u3057\u305F\u3082\u306E\u3092\u8FD4\
    \u3059\n  np copy_interval(np root, np other, ll l, ll r, A a) {\n    static_assert(PERSISTENT);\n\
    \    assert(L0 <= l && l <= r && r <= R0);\n    if (l == r) return root;\n   \
    \ assert(root);\n    if (root == other) return apply(root, l, r, a);\n    root\
    \ = clone(root);\n    copy_interval_rec(root, other, L0, R0, l, r, a);\n    return\
    \ root;\n  }\n\n private:\n  np clone(np c) {\n    if (!c || !PERSISTENT) return\
    \ c;\n    return pool.clone(c);\n  }\n\n  np own(np c, ll l, ll r) { return c\
    \ ? clone(c) : new_node(l, r); }\n\n  X value(np c, ll l, ll r) { return c ? c->x\
    \ : default_prod(l, r); }\n\n  void tag(np c, const A &a, ll len) {\n    c->x\
    \ = AM::act(c->x, a, len);\n    c->lazy = MA::op(c->lazy, a);\n  }\n\n  // c \u306F\
    \u66F8\u304D\u63DB\u3048\u53EF\u80FD\u3002\u5DE6\u53F3\u306E\u5B50\u3082\u66F8\
    \u304D\u63DB\u3048\u53EF\u80FD\u306B\u306A\u3063\u305F\u304B\u3092\u8FD4\u3059\
    \n  bool push(np c, ll l, ll m, ll r) {\n    assert(r - l >= 2);\n    if (c->lazy\
    \ == MA::id()) return false;\n    c->l = own(c->l, l, m);\n    c->r = own(c->r,\
    \ m, r);\n    tag(c->l, c->lazy, m - l);\n    tag(c->r, c->lazy, r - m);\n   \
    \ c->lazy = MA::id();\n    return true;\n  }\n\n  void pull(np c, ll l, ll m,\
    \ ll r) {\n    c->x = MX::op(value(c->l, l, m), value(c->r, m, r));\n  }\n\n \
    \ void copy_interval_rec(np c, np d, ll l, ll r, ll ql, ll qr, A a) {\n    //\
    \ c[ql,qr) <- apply(d[ql,qr),a)\n    // c \u306F\u3059\u3067\u306B\u65B0\u3057\
    \u304F\u3057\u3066\u3042\u308B\n    if (ql <= l && r <= qr) {\n      if (d) {\n\
    \        c->x = d->x;\n        c->lazy = d->lazy;\n        c->l = d->l, c->r =\
    \ d->r;\n      } else {\n        c->x = default_prod(l, r);\n        c->lazy =\
    \ MA::id();\n        c->l = c->r = nullptr;\n      }\n      tag(c, a, r - l);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (d) a = MA::op(d->lazy, a);\n    if (ql < m) {\n      if (!pushed)\
    \ c->l = own(c->l, l, m);\n      copy_interval_rec(c->l, d ? d->l : nullptr, l,\
    \ m, ql, qr, a);\n    }\n    if (m < qr) {\n      if (!pushed) c->r = own(c->r,\
    \ m, r);\n      copy_interval_rec(c->r, d ? d->r : nullptr, m, r, ql, qr, a);\n\
    \    }\n    pull(c, l, m, r);\n  }\n\n  // c \u306F\u3059\u3067\u306B\u65B0\u3057\
    \u304F\u3057\u3066\u3042\u308B\n  void set_rec(np c, ll l, ll r, ll i, const X\
    \ &x) {\n    if (r - l == 1) {\n      c->x = x;\n      c->lazy = MA::id();\n \
    \     return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (i < m) {\n      if (!pushed) c->l = own(c->l, l, m);\n      set_rec(c->l,\
    \ l, m, i, x);\n    } else {\n      if (!pushed) c->r = own(c->r, m, r);\n   \
    \   set_rec(c->r, m, r, i, x);\n    }\n    pull(c, l, m, r);\n  }\n\n  void multiply_rec(np\
    \ c, ll l, ll r, ll i, const X &x) {\n    if (r - l == 1) {\n      c->x = MX::op(c->x,\
    \ x);\n      c->lazy = MA::id();\n      return;\n    }\n    ll m = (l + r) / 2;\n\
    \    bool pushed = push(c, l, m, r);\n    if (i < m) {\n      if (!pushed) c->l\
    \ = own(c->l, l, m);\n      multiply_rec(c->l, l, m, i, x);\n    } else {\n  \
    \    if (!pushed) c->r = own(c->r, m, r);\n      multiply_rec(c->r, m, r, i, x);\n\
    \    }\n    pull(c, l, m, r);\n  }\n\n  void apply_rec(np c, ll l, ll r, ll ql,\
    \ ll qr, const A &a) {\n    if (ql <= l && r <= qr) {\n      tag(c, a, r - l);\n\
    \      return;\n    }\n    ll m = (l + r) / 2;\n    bool pushed = push(c, l, m,\
    \ r);\n    if (ql < m) {\n      if (!pushed) c->l = own(c->l, l, m);\n      apply_rec(c->l,\
    \ l, m, ql, qr, a);\n    }\n    if (m < qr) {\n      if (!pushed) c->r = own(c->r,\
    \ m, r);\n      apply_rec(c->r, m, r, ql, qr, a);\n    }\n    pull(c, l, m, r);\n\
    \  }\n\n  void prod_rec(np c, ll l, ll r, ll ql, ll qr, X &x, A a) {\n    if (!c)\
    \ {\n      ll L = max(l, ql), R = min(r, qr);\n      x = MX::op(x, AM::act(default_prod(L,\
    \ R), a, R - L));\n      return;\n    }\n    if (ql <= l && r <= qr) {\n     \
    \ x = MX::op(x, AM::act(c->x, a, r - l));\n      return;\n    }\n    ll m = (l\
    \ + r) / 2;\n    a = MA::op(c->lazy, a);\n    if (ql < m) prod_rec(c->l, l, m,\
    \ ql, qr, x, a);\n    if (m < qr) prod_rec(c->r, m, r, ql, qr, x, a);\n  }\n\n\
    \  template <typename F>\n  ll max_right_rec(np c, const F &check, ll l, ll r,\
    \ ll ql, X &x, A a) {\n    if (r <= ql) return r;\n    if (ql <= l) {\n      X\
    \ y = MX::op(x, AM::act(value(c, l, r), a, r - l));\n      if (check(y)) {\n \
    \       x = y;\n        return r;\n      }\n    }\n    if (r - l == 1) return\
    \ l;\n    ll m = (l + r) / 2;\n    if (c) a = MA::op(c->lazy, a);\n    if (ql\
    \ < m) {\n      ll k = max_right_rec(c ? c->l : nullptr, check, l, m, ql, x, a);\n\
    \      if (k < m) return k;\n    }\n    return max_right_rec(c ? c->r : nullptr,\
    \ check, m, r, ql, x, a);\n  }\n\n  template <typename F>\n  ll min_left_rec(np\
    \ c, const F &check, ll l, ll r, ll qr, X &x, A a) {\n    if (qr <= l) return\
    \ l;\n    if (r <= qr) {\n      X y = MX::op(AM::act(value(c, l, r), a, r - l),\
    \ x);\n      if (check(y)) {\n        x = y;\n        return l;\n      }\n   \
    \ }\n    if (r - l == 1) return r;\n    ll m = (l + r) / 2;\n    if (c) a = MA::op(c->lazy,\
    \ a);\n    if (m < qr) {\n      ll k = min_left_rec(c ? c->r : nullptr, check,\
    \ m, r, qr, x, a);\n      if (m < k) return k;\n    }\n    return min_left_rec(c\
    \ ? c->l : nullptr, check, l, m, qr, x, a);\n  }\n};\n#line 8 \"test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp\"\
    \n\nusing mint = modint998;\nusing AM = ActedMonoid_Sum_Affine<mint>;\n\nvoid\
    \ solve() {\n  LL(N, Q);\n  Dynamic_Lazy_SegTree<AM, false> seg(0, N);\n  using\
    \ np = decltype(seg)::np;\n\n  np root = seg.new_root();\n\n  FOR(Q) {\n    INT(t,\
    \ l, r);\n    if (t == 0) {\n      mint b, c;\n      read(b, c);\n      SHOW(t,\
    \ l, r, b, c);\n      pair<mint, mint> f = {b, c};\n      root = seg.apply(root,\
    \ l, r, f);\n    } else {\n      SHOW(t, l, r);\n      print(seg.prod(root, l,\
    \ r));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"Range Affine Range Sum (Large Array)\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n\n#include \"mod/modint.hpp\"\n#include \"alg/acted_monoid/sum_affine.hpp\"\
    \n#include \"ds/segtree/dynamic_lazy_segtree.hpp\"\n\nusing mint = modint998;\n\
    using AM = ActedMonoid_Sum_Affine<mint>;\n\nvoid solve() {\n  LL(N, Q);\n  Dynamic_Lazy_SegTree<AM,\
    \ false> seg(0, N);\n  using np = decltype(seg)::np;\n\n  np root = seg.new_root();\n\
    \n  FOR(Q) {\n    INT(t, l, r);\n    if (t == 0) {\n      mint b, c;\n      read(b,\
    \ c);\n      SHOW(t, l, r, b, c);\n      pair<mint, mint> f = {b, c};\n      root\
    \ = seg.apply(root, l, r, f);\n    } else {\n      SHOW(t, l, r);\n      print(seg.prod(root,\
    \ l, r));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - alg/acted_monoid/sum_affine.hpp
  - alg/monoid/add.hpp
  - alg/monoid/affine.hpp
  - ds/segtree/dynamic_lazy_segtree.hpp
  - ds/node_pool.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp
  requiredBy: []
  timestamp: '2026-11-25 16:46:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp
- /verify/test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp.html
title: test/2_library_checker/data_structure/range_affine_range_sum_large.test.cpp
---
