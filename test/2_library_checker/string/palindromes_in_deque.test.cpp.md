---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':x:'
    path: string/double_ended_palindromic_tree.hpp
    title: string/double_ended_palindromic_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/palindromes_in_deque
    links:
    - https://judge.yosupo.jp/problem/palindromes_in_deque
  bundledCode: "#line 1 \"test/2_library_checker/string/palindromes_in_deque.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/palindromes_in_deque\"\n#line\
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
    \ Bob(bool t = 1) { Alice(!t); }\n#line 4 \"test/2_library_checker/string/palindromes_in_deque.test.cpp\"\
    \n\n#line 1 \"string/double_ended_palindromic_tree.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/string/double_ended_palindromic_tree.hpp\n\
    // https://arxiv.org/abs/2210.02292\n// https://codeforces.com/contest/1738/submission/263034583\n\
    template <int sigma, char offset>\nstruct Double_Ended_Palindromic_Tree {\n  struct\
    \ Node {\n    array<int, sigma> TO;  // \u4E21\u7AEF\u306B\u3042\u308B\u6587\u5B57\
    \u3092\u8FFD\u52A0\u3057\u3066\u3067\u304D\u308B\u56DE\u6587\n    int par;   \
    \            // \u4E21\u7AEF\u306B\u3042\u308B\u6587\u5B57\u3092\u9664\u3044\u3066\
    \u3067\u304D\u308B\u56DE\u6587\n    int link;              // longest suffix palindrome\
    \ \u30CE\u30FC\u30C9\n    int length;            // \u305D\u306E\u56DE\u6587\u306E\
    \u9577\u3055\n    int cnt;\n    int linkcnt;  // suffix link tree \u3067\u306E\
    \u5B50\u306E\u500B\u6570\n\n    // link \u306E\u8A08\u7B97\u3092\u30E1\u30E2\u5316\
    \u3057\u305F\u3082\u306E\n    // str(v)+c \u306E longest palindrome suffix = c+str(w)+c\
    \ \u3068\u306A\u308B w\n    array<int, sigma> direct_link;\n  };\n  static constexpr\
    \ int ODD = 0, EVEN = 1;\n  vc<Node> nodes;\n  vc<int> FREE;  // Node \u304C\u524A\
    \u9664\u6E08\u3067\u4F7F\u308F\u308C\u3066\u3044\u306A\u3044 index\n\n  // \u6587\
    \u5B57\u5217\u306E position \u3054\u3068\u306B\u6301\u3064\u3082\u306E\n  struct\
    \ T {\n    int c;\n    // \u305D\u306E\u6587\u5B57\u304B\u3089\u5DE6\u53F3\u306B\
    \u4F38\u3073\u308B\u6975\u5927\u56DE\u6587\u304C surface \u306A\u3089\u3070\u305D\
    \u306E node\n    // surface \u3067\u306A\u3044\u306A\u3089\u3070 EVEN\n    int\
    \ left_surface, right_surface;\n  };\n\n  int mod, mask;\n  vc<T> dat;\n  int\
    \ L = 0, R = 0;  // global index range\n  int num_node = 0;\n\n  int new_node(int\
    \ par, int link, int length, int c = -1) {\n    ++num_node;\n    Node n;\n   \
    \ fill(all(n.TO), -1);\n    fill(all(n.direct_link), -1);\n    n.par = par, n.link\
    \ = link, n.length = length;\n    n.linkcnt = n.cnt = 0;\n    if (link != -1)\
    \ nodes[link].linkcnt += 1;\n    int p = 0;\n    if (FREE.empty()) {\n      p\
    \ = len(nodes);\n      nodes.eb(n);\n    } else {\n      p = POP(FREE);\n    \
    \  nodes[p] = n;\n    }\n    if (par != -1) nodes[par].TO[c] = p;\n    return\
    \ p;\n  }\n\n  void remove_node(int nid, int c) {\n    --num_node;\n    int pid\
    \ = nodes[nid].par;\n    assert(nodes[pid].TO[c] == nid);\n    nodes[pid].TO[c]\
    \ = -1;\n    int k = nodes[nid].link;\n    nodes[k].linkcnt -= 1;\n    if (nodes[k].linkcnt\
    \ == 0) FREE.eb(nid);\n  }\n\n  Double_Ended_Palindromic_Tree(int max_size) {\
    \  // odd, even\n    assert(ODD == new_node(-1, -1, -1));\n    assert(EVEN ==\
    \ new_node(-1, 0, 0));\n    nodes[ODD].cnt = infty<int>, nodes[EVEN].cnt = infty<int>;\n\
    \    mod = 4;\n    while (mod < max_size) mod *= 2;\n    dat.resize(mod);\n  \
    \  mask = mod - 1;\n  }\n\n  int suffix_node() {\n    return (L == R ? EVEN :\
    \ dat[(R - 1) & mask].left_surface);\n  }\n  int prefix_node() { return (L ==\
    \ R ? EVEN : dat[L & mask].right_surface); }\n\n  void push_back(int c) {\n  \
    \  assert(R - L <= mask);\n    c -= offset;\n    int v = suffix_node();\n    dat[R\
    \ & mask].c = c;\n    // update palindromic tree, v <- nxt suffix node\n    v\
    \ = [&]() -> int {\n      auto dfs = [&](auto& dfs, int v) -> int {\n        //\
    \ str(v)+c \u306E longest suffix palindrome = c+str(w)+c\n        int& w = nodes[v].direct_link[c];\n\
    \        if (w != -1) {\n          return w;\n        }\n        int p = nodes[v].link;\n\
    \        int j = R - 1 - nodes[p].length;\n        if (L <= j && j <= R && dat[j\
    \ & mask].c == c) {\n          return w = p;\n        }\n        return w = dfs(dfs,\
    \ p);\n      };\n      // \u3044\u307E\u306E\u30CE\u30FC\u30C9\u306B\u8DB3\u305B\
    \u306A\u3044\u306A\u3089\u623B\u308B\n      int j = R - 1 - nodes[v].length;\n\
    \      if (!(L <= j && j <= R && dat[j & mask].c == c)) {\n        v = dfs(dfs,\
    \ v);\n      }\n      // c+str(v)+c \u3092\u4F5C\u308B\n      if (nodes[v].TO[c]\
    \ != -1) {\n        return nodes[v].TO[c];\n      }\n      int link = (v == ODD\
    \ ? EVEN : nodes[dfs(dfs, v)].TO[c]);\n      return new_node(v, link, nodes[v].length\
    \ + 2, c);\n    }();\n    dat[R & mask].right_surface = EVEN;\n    dat[(R - nodes[v].length\
    \ + 1) & mask].right_surface = v;\n    dat[R & mask].left_surface = v;\n    int\
    \ w = nodes[v].link;\n\n    int k = (R - nodes[v].length + nodes[w].length);\n\
    \    if (nodes[w].length >= 1 && dat[k & mask].left_surface == w) {\n      dat[k\
    \ & mask].left_surface = EVEN;\n    }\n    ++R, nodes[v].cnt += 1;\n  }\n\n  void\
    \ pop_back() {\n    assert(L < R);\n    int v = suffix_node();\n    int w = nodes[v].link;\n\
    \    int k = R - 1 - nodes[v].length + nodes[w].length;\n    if (nodes[dat[k &\
    \ mask].left_surface].length < nodes[w].length) {\n      dat[k & mask].left_surface\
    \ = w;\n      dat[(k - nodes[w].length + 1) & mask].right_surface = w;\n    }\
    \ else {\n      dat[(k - nodes[w].length + 1) & mask].right_surface = EVEN;\n\
    \    }\n    nodes[v].cnt--;\n    if (nodes[v].linkcnt == 0 && nodes[v].cnt ==\
    \ 0) {\n      remove_node(v, dat[(R - 1) & mask].c);\n    }\n    --R;\n  }\n\n\
    \  void push_front(int c) {\n    assert(R - L <= mask);\n    c -= offset;\n  \
    \  int v = prefix_node();\n    dat[(L - 1) & mask].c = c;\n    // update palindromic\
    \ tree, v <- nxt suffix node\n    v = [&]() -> int {\n      auto dfs = [&](auto&\
    \ dfs, int v) -> int {\n        // str(v)+c \u306E longest suffix palindrome =\
    \ c+str(w)+c\n        int& w = nodes[v].direct_link[c];\n        if (w != -1)\
    \ {\n          return w;\n        }\n        int p = nodes[v].link;\n        int\
    \ j = L + nodes[p].length;\n        if (L - 1 <= j && j <= R - 1 && dat[j & mask].c\
    \ == c) {\n          return w = p;\n        }\n        return w = dfs(dfs, p);\n\
    \      };\n      // \u3044\u307E\u306E\u30CE\u30FC\u30C9\u306B\u8DB3\u305B\u306A\
    \u3044\u306A\u3089\u623B\u308B\n      int j = L + nodes[v].length;\n      if (!(L\
    \ - 1 <= j && j <= R - 1 && dat[j & mask].c == c)) {\n        v = dfs(dfs, v);\n\
    \      }\n      // c+str(v)+c \u3092\u4F5C\u308B\n      if (nodes[v].TO[c] !=\
    \ -1) {\n        return nodes[v].TO[c];\n      }\n      int link = (v == ODD ?\
    \ EVEN : nodes[dfs(dfs, v)].TO[c]);\n      return new_node(v, link, nodes[v].length\
    \ + 2, c);\n    }();\n    dat[(L - 1) & mask].left_surface = EVEN;\n    dat[(L\
    \ - 2 + nodes[v].length) & mask].left_surface = v;\n    dat[(L - 1) & mask].right_surface\
    \ = v;\n    int w = nodes[v].link;\n\n    int k = ((L - 1) + nodes[v].length -\
    \ nodes[w].length);\n    if (nodes[w].length >= 1 && dat[k & mask].right_surface\
    \ == w) {\n      dat[k & mask].right_surface = EVEN;\n    }\n    --L, nodes[v].cnt\
    \ += 1;\n  }\n\n  void pop_front() {\n    assert(L < R);\n    int v = prefix_node();\n\
    \    int w = nodes[v].link;\n    int k = L + nodes[v].length - nodes[w].length;\n\
    \    if (nodes[dat[k & mask].right_surface].length < nodes[w].length) {\n    \
    \  dat[k & mask].right_surface = w;\n      dat[(k + nodes[w].length - 1) & mask].left_surface\
    \ = w;\n    } else {\n      dat[(k + nodes[w].length - 1) & mask].left_surface\
    \ = EVEN;\n    }\n    nodes[v].cnt--;\n    if (nodes[v].linkcnt == 0 && nodes[v].cnt\
    \ == 0) {\n      remove_node(v, dat[L & mask].c);\n    }\n    ++L;\n  }\n\n  int\
    \ count_distinct_palindromes() { return num_node - 2; }\n  int maximum_prefix_palindrome()\
    \ { return nodes[prefix_node()].length; }\n  int maximum_suffix_palindrome() {\
    \ return nodes[suffix_node()].length; }\n};\n#line 6 \"test/2_library_checker/string/palindromes_in_deque.test.cpp\"\
    \n\nvoid solve() {\n  INT(Q);\n  Double_Ended_Palindromic_Tree<26, 'a'> tree(Q);\n\
    \  FOR(q, Q) {\n    INT(t);\n    if (t == 0) {\n      CHAR(c);\n      tree.push_front(c);\n\
    \    }\n    if (t == 1) {\n      CHAR(c);\n      tree.push_back(c);\n    }\n \
    \   if (t == 2) {\n      tree.pop_front();\n    }\n    if (t == 3) {\n      tree.pop_back();\n\
    \    }\n    int a = tree.count_distinct_palindromes();\n    int b = tree.maximum_prefix_palindrome();\n\
    \    int c = tree.maximum_suffix_palindrome();\n    print(a, b, c);\n  }\n}\n\n\
    signed main() { solve(); }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/palindromes_in_deque\"\n\
    #include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"string/double_ended_palindromic_tree.hpp\"\
    \n\nvoid solve() {\n  INT(Q);\n  Double_Ended_Palindromic_Tree<26, 'a'> tree(Q);\n\
    \  FOR(q, Q) {\n    INT(t);\n    if (t == 0) {\n      CHAR(c);\n      tree.push_front(c);\n\
    \    }\n    if (t == 1) {\n      CHAR(c);\n      tree.push_back(c);\n    }\n \
    \   if (t == 2) {\n      tree.pop_front();\n    }\n    if (t == 3) {\n      tree.pop_back();\n\
    \    }\n    int a = tree.count_distinct_palindromes();\n    int b = tree.maximum_prefix_palindrome();\n\
    \    int c = tree.maximum_suffix_palindrome();\n    print(a, b, c);\n  }\n}\n\n\
    signed main() { solve(); }"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - string/double_ended_palindromic_tree.hpp
  isVerificationFile: true
  path: test/2_library_checker/string/palindromes_in_deque.test.cpp
  requiredBy: []
  timestamp: '2026-10-17 16:28:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/string/palindromes_in_deque.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/string/palindromes_in_deque.test.cpp
- /verify/test/2_library_checker/string/palindromes_in_deque.test.cpp.html
title: test/2_library_checker/string/palindromes_in_deque.test.cpp
---
