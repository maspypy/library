---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: nt/nimber/base.hpp
    title: nt/nimber/base.hpp
  - icon: ':x:'
    path: nt/nimber/nimber_impl.hpp
    title: nt/nimber/nimber_impl.hpp
  - icon: ':x:'
    path: other/io.hpp
    title: other/io.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/nim_product_64
    links:
    - https://judge.yosupo.jp/problem/nim_product_64
  bundledCode: "#line 1 \"test/2_library_checker/number_theory/nim_product.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/nim_product_64\"\r\n#line\
    \ 1 \"my_template.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/my_template.hpp\n\
    /*\nlibrary: https://github.com/maspypy/library\n*/\n#if defined(__GNUC__)\n#include\
    \ <bits/allocator.h>\n#pragma GCC optimize(\"Ofast,unroll-loops\")\n#if !defined(MASPY_NON_AVX2)\n\
    #pragma GCC target(\"avx2,popcnt\")\n#endif\n#endif\n#include <bits/stdc++.h>\n\
    #line 14 \"my_template.hpp\"\n\nusing namespace std;\n\nusing ll = long long;\n\
    using u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 =\
    \ uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128\
    \ = __float128;\n\ntemplate <class>\nconstexpr bool dependent_false = false;\n\
    \ntemplate <class T>\nconstexpr T infty = [] {\n  static_assert(dependent_false<T>,\
    \ \"infty<T> is not defined\");\n  return T{};\n}();\ntemplate <>\nconstexpr int\
    \ infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
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
    \    a = b, b = c;\n  }\n  return abs(a);\n}\n#line 1 \"other/io.hpp\"\n// Source:\
    \ https://github.com/maspypy/library/blob/main/other/io.hpp\n#define FASTIO\n\n\
    // https://judge.yosupo.jp/submission/21623\nnamespace fastio {\nstatic constexpr\
    \ uint32_t SZ = 1 << 17;\nchar ibuf[SZ];\nchar obuf[SZ];\nchar out[100];\n// pointer\
    \ of ibuf, obuf\nuint32_t pil = 0, pir = 0, por = 0;\nbool input_eof = false;\n\
    \ntemplate <class T>\nconstexpr bool is_signed_integer_v = is_signed_v<T> || is_same_v<T,\
    \ i128>;\n\ntemplate <class T>\nstruct unsigned_integer {\n  using type = make_unsigned_t<T>;\n\
    };\ntemplate <>\nstruct unsigned_integer<i128> {\n  using type = u128;\n};\ntemplate\
    \ <>\nstruct unsigned_integer<u128> {\n  using type = u128;\n};\ntemplate <class\
    \ T>\nusing unsigned_integer_t = typename unsigned_integer<T>::type;\n\n[[noreturn]]\
    \ inline void input_error(const char *message) {\n  fputs(message, stderr);\n\
    \  fputc('\\n', stderr);\n  exit(EXIT_FAILURE);\n}\n\nstruct Pre {\n  char num[10000][4];\n\
    \  constexpr Pre() : num() {\n    for (int i = 0; i < 10000; i++) {\n      int\
    \ n = i;\n      for (int j = 3; j >= 0; j--) {\n        num[i][j] = n % 10 | '0';\n\
    \        n /= 10;\n      }\n    }\n  }\n} constexpr pre;\n\ninline void load()\
    \ {\n  uint32_t n = pir - pil;\n  memmove(ibuf, ibuf + pil, n);\n  pil = 0;\n\
    \  pir = n;\n  if (input_eof) return;\n\n  pir += fread(ibuf + pir, 1, SZ - pir,\
    \ stdin);\n  if (ferror(stdin)) input_error(\"fastio: input error\");\n  if (feof(stdin))\
    \ {\n    input_eof = true;\n    // Allows the last token to end exactly at EOF\
    \ without a trailing\n    // whitespace.\n    if (pir < SZ) ibuf[pir++] = '\\\
    n';\n  }\n}\n\ninline char get_char() {\n  if (pil == pir) {\n    load();\n  \
    \  if (pil == pir) input_error(\"fastio: unexpected EOF\");\n  }\n  return ibuf[pil++];\n\
    }\n\ninline void flush() {\n  fwrite(obuf, 1, por, stdout);\n  por = 0;\n}\n\n\
    void rd(char &c) {\n  do c = get_char();\n  while (isspace(static_cast<unsigned\
    \ char>(c)));\n}\n\nvoid rd(string &x) {\n  x.clear();\n  char c;\n  do c = get_char();\n\
    \  while (isspace(static_cast<unsigned char>(c)));\n  do {\n    x += c;\n    c\
    \ = get_char();\n  } while (!isspace(static_cast<unsigned char>(c)));\n}\n\ntemplate\
    \ <typename T>\nvoid rd_real(T &x) {\n  string s;\n  rd(s);\n  x = stod(s);\n\
    }\n\ntemplate <typename T>\nvoid rd_integer_slow(T &x) {\n  char c;\n  do c =\
    \ get_char();\n  while (c < '-');\n  bool minus = 0;\n  if constexpr (is_signed_integer_v<T>)\
    \ {\n    if (c == '-') {\n      minus = 1, c = get_char();\n    }\n  }\n  x =\
    \ 0;\n  assert('0' <= c && c <= '9');\n  while ('0' <= c && c <= '9') {\n    x\
    \ = x * 10 + (c & 15), c = get_char();\n  }\n  assert(isspace(static_cast<unsigned\
    \ char>(c)));\n  if constexpr (is_signed_integer_v<T>) {\n    if (minus) x = -x;\n\
    \  }\n}\n\ntemplate <typename T>\nvoid rd_integer(T &x) {\n  if (pil + 100 > pir)\
    \ {\n    load();\n    if (pil + 100 > pir) {\n      rd_integer_slow(x);\n    \
    \  return;\n    }\n  }\n  char c;\n  do c = ibuf[pil++];\n  while (c < '-');\n\
    \  bool minus = 0;\n  if constexpr (is_signed_integer_v<T>) {\n    if (c == '-')\
    \ {\n      minus = 1, c = ibuf[pil++];\n    }\n  }\n  x = 0;\n  assert('0' <=\
    \ c && c <= '9');\n  while ('0' <= c && c <= '9') {\n    x = x * 10 + (c & 15),\
    \ c = ibuf[pil++];\n  }\n  assert(isspace(static_cast<unsigned char>(c)));\n \
    \ if constexpr (is_signed_integer_v<T>) {\n    if (minus) x = -x;\n  }\n}\n\n\
    template <class T>\nenable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T,\
    \ u128>> rd(\n    T &x) {\n  rd_integer(x);\n}\n\ntemplate <class T>\nenable_if_t<is_floating_point_v<T>\
    \ || is_same_v<T, f128>> rd(T &x) {\n  rd_real(x);\n}\n\ntemplate <class T, class\
    \ U>\nvoid rd(pair<T, U> &p) {\n  rd(p.first), rd(p.second);\n}\ntemplate <size_t\
    \ N = 0, typename T>\nvoid rd_tuple(T &t) {\n  if constexpr (N < tuple_size<T>::value)\
    \ {\n    auto &x = get<N>(t);\n    rd(x);\n    rd_tuple<N + 1>(t);\n  }\n}\ntemplate\
    \ <class... T>\nvoid rd(tuple<T...> &tpl) {\n  rd_tuple(tpl);\n}\n\ntemplate <class\
    \ T, size_t N>\nvoid rd(array<T, N> &x) {\n  for (auto &d : x) rd(d);\n}\ntemplate\
    \ <class T>\nvoid rd(vc<T> &x) {\n  for (auto &d : x) rd(d);\n}\n\ntemplate <class...\
    \ T>\nvoid read(T &...x) {\n  (rd(x), ...);\n}\n\ninline void wt_range(const char\
    \ *s, size_t n) {\n  size_t i = 0;\n  while (i < n) {\n    if (por == SZ) flush();\n\
    \    size_t chunk = min(n - i, (size_t)(SZ - por));\n    memcpy(obuf + por, s\
    \ + i, chunk);\n    por += chunk;\n    i += chunk;\n  }\n}\n\nvoid wt(const char\
    \ c) {\n  if (por == SZ) flush();\n  obuf[por++] = c;\n}\nvoid wt(const char *s)\
    \ { wt_range(s, strlen(s)); }\nvoid wt(const string &s) { wt_range(s.data(), s.size());\
    \ }\n\ntemplate <typename T>\nvoid wt_integer(T x) {\n  if (por > SZ - 100) flush();\n\
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 1 \"nt/nimber/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/nimber/base.hpp\n\
    #line 1 \"nt/nimber/nimber_impl.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/nt/nimber/nimber_impl.hpp\n\
    namespace NIM_PRODUCT {\nu16 E[65535 * 2 + 7];\nu16 L[65536];\nu64 S[4][65536];\n\
    u64 SR[4][65536];\n\nu16 p16_15(u16 a, u16 b) { return (a && b ? E[u32(L[a]) +\
    \ L[b] + 3] : 0); }\nu16 p16_15_15(u16 a, u16 b) { return (a && b ? E[u32(L[a])\
    \ + L[b] + 6] : 0); }\nu16 mul_15(u16 a) { return (a ? E[3 + L[a]] : 0); }\nu16\
    \ mul_15_15(u16 a) { return (a ? E[6 + L[a]] : 0); }\nu32 p32_mul_31(u32 a, u32\
    \ b) {\n  u16 al = a & 65535, ah = a >> 16, bl = b & 65535, bh = b >> 16;\n  u16\
    \ x = p16_15(al, bl);\n  u16 y = p16_15_15(ah, bh);\n  u16 z = p16_15(al ^ ah,\
    \ bl ^ bh);\n  return u32(y ^ z) << 16 | mul_15(z ^ x);\n}\nu32 mul_31(u32 a)\
    \ {\n  u16 al = a & 65535, ah = a >> 16;\n  return u32(mul_15(al ^ ah)) << 16\
    \ | mul_15_15(ah);\n}\n\nu16 prod(u16 a, u16 b) { return (a && b ? E[u32(L[a])\
    \ + L[b]] : 0); }\nu32 prod(u32 a, u32 b) {\n  u16 al = a & 65535, ah = a >> 16,\
    \ bl = b & 65535, bh = b >> 16;\n  u16 c = prod(al, bl);\n  return u32(prod(u16(al\
    \ ^ ah), u16(bl ^ bh)) ^ c) << 16 | (p16_15(ah, bh) ^ c);\n}\nu64 prod(u64 a,\
    \ u64 b) {\n  u32 al = a & 0xffffffff, ah = a >> 32, bl = b & 0xffffffff, bh =\
    \ b >> 32;\n  u32 c = prod(al, bl);\n  return u64(prod(al ^ ah, bl ^ bh) ^ c)\
    \ << 32 ^ (p32_mul_31(ah, bh) ^ c);\n}\n\nu16 square(u16 a) { return S[0][a];\
    \ }\nu32 square(u32 a) { return S[0][a & 65535] ^ S[1][a >> 16]; }\nu64 square(u64\
    \ a) { return S[0][a & 65535] ^ S[1][a >> 16 & 65535] ^ S[2][a >> 32 & 65535]\
    \ ^ S[3][a >> 48 & 65535]; }\nu16 sqrt(u16 a) { return SR[0][a]; }\nu32 sqrt(u32\
    \ a) { return SR[0][a & 65535] ^ SR[1][a >> 16]; }\nu64 sqrt(u64 a) { return SR[0][a\
    \ & 65535] ^ SR[1][a >> 16 & 65535] ^ SR[2][a >> 32 & 65535] ^ SR[3][a >> 48 &\
    \ 65535]; }\n\n// inv: 2^16 \u306E\u5171\u5F79\u304C 2^16+1 \u3067\u3042\u308B\
    \u3053\u3068\u306A\u3069\u3092\u4F7F\u3046. x^{-1}=y(xy)^{-1} \u3068\u3044\u3046\
    \u8981\u9818.\nu16 inverse(u16 a) { return E[65535 - L[a]]; }\nu32 inverse(u32\
    \ a) {\n  if (a < 65536) return inverse(u16(a));\n  u16 al = a & 65535, ah = a\
    \ >> 16;\n  u16 norm = prod(al, al ^ ah) ^ E[L[ah] * 2 + 3];\n  int k = 65535\
    \ - L[norm];\n  al = (al ^ ah ? E[L[al ^ ah] + k] : 0), ah = E[L[ah] + k];\n \
    \ return al | u32(ah) << 16;\n}\nu64 inverse(u64 a) {\n  if (a <= u32(-1)) return\
    \ inverse(u32(a));\n  u32 al = a & 0xffffffff, ah = a >> 32;\n  u32 norm = prod(al,\
    \ al ^ ah) ^ mul_31(square(ah));\n  u32 i = inverse(norm);\n  return prod(al ^\
    \ ah, i) | u64(prod(ah, i)) << 32;\n}\n\nvoid __attribute__((constructor)) init_nim_table()\
    \ {\n  // 2^16 \u672A\u6E80\u306E\u3068\u3053\u308D\u306B\u3064\u3044\u3066\u539F\
    \u59CB\u6839 10279 \u3067\u306E\u6307\u6570\u5BFE\u6570\u8868\u3092\u4F5C\u308B\
    \n  // 2^k \u3068\u306E\u7A4D\n  u16 tmp[] = {10279, 15417, 35722, 52687, 44124,\
    \ 62628, 15661, 5686, 3862, 1323, 334, 647, 61560, 20636, 4267, 8445};\n  u16\
    \ nxt[65536];\n  FOR(i, 16) {\n    FOR(s, 1 << i) { nxt[s | 1 << i] = nxt[s] ^\
    \ tmp[i]; }\n  }\n  E[0] = 1;\n  FOR(i, 65534) E[i + 1] = nxt[E[i]];\n  memcpy(E\
    \ + 65535, E, 131070);\n  memcpy(E + 131070, E, 14);\n  FOR(i, 65535) L[E[i]]\
    \ = i;\n  FOR(t, 4) {\n    FOR(i, 16) {\n      int k = 16 * t + i;\n      u64\
    \ X = prod(u64(1) << k, u64(1) << k);\n      FOR(s, 1 << i) S[t][s | 1 << i] =\
    \ S[t][s] ^ X;\n    }\n  }\n  FOR(t, 4) {\n    FOR(i, 16) {\n      int k = 16\
    \ * t + i;\n      u64 X = u64(1) << k;\n      FOR(63) X = square(X);\n      FOR(s,\
    \ 1 << i) SR[t][s | 1 << i] = SR[t][s] ^ X;\n    }\n  }\n}\n} // namespace NIM_PRODUCT\n\
    #line 3 \"nt/nimber/base.hpp\"\n\ntemplate <typename UINT>\nstruct Nimber {\n\
    \  using F = Nimber;\n  UINT val;\n\n  constexpr Nimber(UINT x = 0) : val(x) {}\n\
    \  F &operator+=(const F &p) {\n    val ^= p.val;\n    return *this;\n  }\n  F\
    \ &operator-=(const F &p) {\n    val ^= p.val;\n    return *this;\n  }\n  F &operator*=(const\
    \ F &p) {\n    val = NIM_PRODUCT::prod(val, p.val);\n    return *this;\n  }\n\
    \  F &operator/=(const F &p) {\n    *this *= p.inverse();\n    return *this;\n\
    \  }\n  F operator-() const { return *this; }\n  F operator+(const F &p) const\
    \ { return F(*this) += p; }\n  F operator-(const F &p) const { return F(*this)\
    \ -= p; }\n  F operator*(const F &p) const { return F(*this) *= p; }\n  F operator/(const\
    \ F &p) const { return F(*this) /= p; }\n  bool operator==(const F &p) const {\
    \ return val == p.val; }\n  bool operator!=(const F &p) const { return val !=\
    \ p.val; }\n  F inverse() const { return NIM_PRODUCT::inverse(val); }\n  F pow(u64\
    \ n) const {\n    assert(n >= 0);\n    UINT ret = 1, mul = val;\n    while (n\
    \ > 0) {\n      if (n & 1) ret = NIM_PRODUCT::prod(ret, mul);\n      mul = NIM_PRODUCT::square(mul);\n\
    \      n >>= 1;\n    }\n    return F(ret);\n  }\n  F square() { return F(NIM_PRODUCT::square(val));\
    \ }\n  F sqrt() { return F(NIM_PRODUCT::sqrt(val)); }\n};\n\n#ifdef FASTIO\ntemplate\
    \ <typename T>\nvoid rd(Nimber<T> &x) {\n  fastio::rd(x.val);\n}\ntemplate <typename\
    \ T>\nvoid wt(Nimber<T> &x) {\n  fastio::wt(x.val);\n}\n#endif\n\nusing Nimber16\
    \ = Nimber<u16>;\nusing Nimber32 = Nimber<u32>;\nusing Nimber64 = Nimber<u64>;\n\
    #line 5 \"test/2_library_checker/number_theory/nim_product.test.cpp\"\n\r\nusing\
    \ F = Nimber64;\r\nvoid solve() {\r\n  u64 a, b;\r\n  read(a, b);\r\n  F ANS =\
    \ F(a) * F(b);\r\n  print(ANS.val);\r\n}\r\n\r\nsigned main() {\r\n  LL(T);\r\n\
    \  FOR(T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/nim_product_64\"\r\n#include\
    \ \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"nt/nimber/base.hpp\"\
    \r\n\r\nusing F = Nimber64;\r\nvoid solve() {\r\n  u64 a, b;\r\n  read(a, b);\r\
    \n  F ANS = F(a) * F(b);\r\n  print(ANS.val);\r\n}\r\n\r\nsigned main() {\r\n\
    \  LL(T);\r\n  FOR(T) solve();\r\n\r\n  return 0;\r\n}\r\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - nt/nimber/base.hpp
  - nt/nimber/nimber_impl.hpp
  isVerificationFile: true
  path: test/2_library_checker/number_theory/nim_product.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 16:28:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/number_theory/nim_product.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/number_theory/nim_product.test.cpp
- /verify/test/2_library_checker/number_theory/nim_product.test.cpp.html
title: test/2_library_checker/number_theory/nim_product.test.cpp
---
