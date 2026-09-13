---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: alg/monoid/dummy.hpp
    title: alg/monoid/dummy.hpp
  - icon: ':question:'
    path: ds/bit_vector.hpp
    title: ds/bit_vector.hpp
  - icon: ':question:'
    path: ds/dummy_data_structure.hpp
    title: ds/dummy_data_structure.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: ds/index_compression.hpp
    title: ds/index_compression.hpp
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix.hpp
    title: ds/wavelet_matrix/wavelet_matrix.hpp
  - icon: ':question:'
    path: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
    title: ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\
    \n#line 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\
    #else\n#if defined(__GNUC__)\n#include <bits/allocator.h>\n#pragma GCC optimize(\"\
    Ofast,unroll-loops\")\n// \u74B0\u5883\u306B\u3088\u3063\u3066\u306F\u30B3\u30F3\
    \u30D1\u30A4\u30EB\u6210\u529F\u304B\u3064\u5B9F\u884C\u6642\u30A8\u30E9\u30FC\
    \n#pragma GCC target(\"avx2,popcnt\")\n#endif\n#include <bits/stdc++.h>\n#include\
    \ <cassert>\n\nusing namespace std;\n\nusing ll = long long;\nusing u8 = uint8_t;\n\
    using u16 = uint16_t;\nusing u32 = uint32_t;\nusing u64 = uint64_t;\nusing i128\
    \ = __int128;\nusing u128 = unsigned __int128;\nusing f128 = __float128;\n\ntemplate\
    \ <class>\nconstexpr bool dependent_false = false;\n\ntemplate <class T>\nconstexpr\
    \ T infty = [] {\n  static_assert(dependent_false<T>, \"infty<T> is not defined\"\
    );\n  return T{};\n}();\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\n\
    template <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\n\
    constexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64>\
    \ = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<i128>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<i128>;\n\nusing pi = pair<ll, ll>;\n\
    using vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ pq_max = priority_queue<T>;\ntemplate <class T>\nusing pq_min = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vv(type, name, h, ...) \\\n  vector<vector<type>>\
    \ name(h, vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...)   \\\n\
    \  vector<vector<vector<type>>> name( \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n\
    #define vvvv(type, name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>>\
    \ name( \\\n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ ll(a) - 1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = ll(a) - 1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = ll(b) - 1; i >= ll(a); --i)\n\
    #define overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n\
    #define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define all(x) (x).begin(), (x).end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\n// require y > 0\n\
    template <typename T>\nT floor(T x, T y) {\n  return x / y - (x % y < 0);\n}\n\
    \n// require y > 0\ntemplate <typename T>\nT ceil(T x, T y) {\n  return (x / y)\
    \ + (x % y > 0);\n}\n\n// require y > 0\ntemplate <typename T>\nT bmod(T x, T\
    \ y) {\n  T r = x % y;\n  return (r < 0 ? r + y : r);\n}\n\n// require y > 0\n\
    template <typename T>\npair<T, T> divmod(T x, T y) {\n  T q = x / y, r = x % y;\n\
    \  if (r < 0) --q, r += y;\n  return {q, r};\n}\n\nconstexpr auto TEN = [] {\n\
    \  array<u64, 20> A{};\n  A[0] = 1;\n  for (int i = 1; i < 20; ++i) A[i] = 10\
    \ * A[i - 1];\n  return A;\n}();\n\ntemplate <typename T, typename U>\nT SUM(const\
    \ U &A) {\n  return std::accumulate(A.begin(), A.end(), T{});\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\ntemplate <class C,\
    \ class T>\ninline long long LB(const C &c, const T &x) {\n  return lower_bound(c.begin(),\
    \ c.end(), x) - c.begin();\n}\ntemplate <class C, class T>\ninline long long UB(const\
    \ C &c, const T &x) {\n  return upper_bound(c.begin(), c.end(), x) - c.begin();\n\
    }\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\ntemplate\
    \ <typename T>\nT POP(deque<T> &que) {\n  T a = que.front();\n  que.pop_front();\n\
    \  return a;\n}\ntemplate <class T, class Container, class Compare>\nT POP(priority_queue<T,\
    \ Container, Compare> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n\
    }\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n  que.pop_back();\n\
    \  return a;\n}\n\ntemplate <typename F>\ni128 binary_search(F check, i128 ok,\
    \ i128 ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while\
    \ (1) {\n    i128 x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n   \
    \ (check(x) ? ok : ng) = x;\n  }\n  return ok;\n}\n\ntemplate <typename F>\ndouble\
    \ binary_search_real(F check, double ok, double ng, int iter = 100) {\n  FOR(iter)\
    \ {\n    double x = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return\
    \ (ok + ng) / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const\
    \ S &b) {\n  T c = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return\
    \ changed;\n}\ntemplate <class T, class S>\ninline bool chmin(T &a, const S &b)\
    \ {\n  T c = min<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n\
    }\n\n// ? \u306F -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int>\
    \ A(S.size());\n  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char :\
    \ -1); }\n  return A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const\
    \ vc<U> &A, int off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N)\
    \ { B[i + 1] = B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n\
    }\n\n// stable sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n\
    \  vc<int> ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids),\n      [&](int\
    \ i, int j) { return (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n\
    }\n\n// A[I[0]], A[I[1]], ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T>\
    \ &A, const vc<int> &I) {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n\
    \  return B;\n}\n\ntemplate <typename T, typename... Vectors>\nvoid concat(vc<T>\
    \ &first, const Vectors &...others) {\n  first.reserve(first.size() + (others.size()\
    \ + ... + 0));\n  (first.insert(first.end(), others.begin(), others.end()), ...);\n\
    }\n\n// i128\ntemplate <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr\
    \ i128 abs(T x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128\
    \ b) {\n  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return\
    \ abs(a);\n}\n#endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\
    \nnamespace fastio {\r\nstatic constexpr uint32_t SZ = 1 << 17;\r\nchar ibuf[SZ];\r\
    \nchar obuf[SZ];\r\nchar out[100];\r\n// pointer of ibuf, obuf\r\nuint32_t pil\
    \ = 0, pir = 0, por = 0;\r\nbool input_eof = false;\r\n\r\ntemplate <class T>\r\
    \nconstexpr bool is_signed_integer_v = is_signed_v<T> || is_same_v<T, i128>;\r\
    \n\r\ntemplate <class T>\r\nstruct unsigned_integer {\r\n  using type = make_unsigned_t<T>;\r\
    \n};\r\ntemplate <>\r\nstruct unsigned_integer<i128> {\r\n  using type = u128;\r\
    \n};\r\ntemplate <>\r\nstruct unsigned_integer<u128> {\r\n  using type = u128;\r\
    \n};\r\ntemplate <class T>\r\nusing unsigned_integer_t = typename unsigned_integer<T>::type;\r\
    \n\r\n[[noreturn]] inline void input_error(const char *message) {\r\n  fputs(message,\
    \ stderr);\r\n  fputc('\\n', stderr);\r\n  exit(EXIT_FAILURE);\r\n}\r\n\r\nstruct\
    \ Pre {\r\n  char num[10000][4];\r\n  constexpr Pre() : num() {\r\n    for (int\
    \ i = 0; i < 10000; i++) {\r\n      int n = i;\r\n      for (int j = 3; j >= 0;\
    \ j--) {\r\n        num[i][j] = n % 10 | '0';\r\n        n /= 10;\r\n      }\r\
    \n    }\r\n  }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n  uint32_t n\
    \ = pir - pil;\r\n  memmove(ibuf, ibuf + pil, n);\r\n  pil = 0;\r\n  pir = n;\r\
    \n  if (input_eof) return;\r\n\r\n  pir += fread(ibuf + pir, 1, SZ - pir, stdin);\r\
    \n  if (ferror(stdin)) input_error(\"fastio: input error\");\r\n  if (feof(stdin))\
    \ {\r\n    input_eof = true;\r\n    // Allows the last token to end exactly at\
    \ EOF without a trailing\r\n    // whitespace.\r\n    if (pir < SZ) ibuf[pir++]\
    \ = '\\n';\r\n  }\r\n}\r\n\r\ninline char get_char() {\r\n  if (pil == pir) {\r\
    \n    load();\r\n    if (pil == pir) input_error(\"fastio: unexpected EOF\");\r\
    \n  }\r\n  return ibuf[pil++];\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(obuf,\
    \ 1, por, stdout);\r\n  por = 0;\r\n}\r\n\r\nvoid rd(char &c) {\r\n  do c = get_char();\r\
    \n  while (isspace(static_cast<unsigned char>(c)));\r\n}\r\n\r\nvoid rd(string\
    \ &x) {\r\n  x.clear();\r\n  char c;\r\n  do c = get_char();\r\n  while (isspace(static_cast<unsigned\
    \ char>(c)));\r\n  do {\r\n    x += c;\r\n    c = get_char();\r\n  } while (!isspace(static_cast<unsigned\
    \ char>(c)));\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_real(T &x) {\r\n  string\
    \ s;\r\n  rd(s);\r\n  x = stod(s);\r\n}\r\n\r\ntemplate <typename T>\r\nvoid rd_integer_slow(T\
    \ &x) {\r\n  char c;\r\n  do c = get_char();\r\n  while (c < '-');\r\n  bool minus\
    \ = 0;\r\n  if constexpr (is_signed_integer_v<T>) {\r\n    if (c == '-') {\r\n\
    \      minus = 1, c = get_char();\r\n    }\r\n  }\r\n  x = 0;\r\n  assert('0'\
    \ <= c && c <= '9');\r\n  while ('0' <= c && c <= '9') {\r\n    x = x * 10 + (c\
    \ & 15), c = get_char();\r\n  }\r\n  assert(isspace(static_cast<unsigned char>(c)));\r\
    \n  if constexpr (is_signed_integer_v<T>) {\r\n    if (minus) x = -x;\r\n  }\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvoid rd_integer(T &x) {\r\n  if (pil + 100\
    \ > pir) {\r\n    load();\r\n    if (pil + 100 > pir) {\r\n      rd_integer_slow(x);\r\
    \n      return;\r\n    }\r\n  }\r\n  char c;\r\n  do c = ibuf[pil++];\r\n  while\
    \ (c < '-');\r\n  bool minus = 0;\r\n  if constexpr (is_signed_integer_v<T>) {\r\
    \n    if (c == '-') {\r\n      minus = 1, c = ibuf[pil++];\r\n    }\r\n  }\r\n\
    \  x = 0;\r\n  assert('0' <= c && c <= '9');\r\n  while ('0' <= c && c <= '9')\
    \ {\r\n    x = x * 10 + (c & 15), c = ibuf[pil++];\r\n  }\r\n  assert(isspace(static_cast<unsigned\
    \ char>(c)));\r\n  if constexpr (is_signed_integer_v<T>) {\r\n    if (minus) x\
    \ = -x;\r\n  }\r\n}\r\n\r\ntemplate <class T>\r\nenable_if_t<is_integral_v<T>\
    \ || is_same_v<T, i128> || is_same_v<T, u128>> rd(\r\n    T &x) {\r\n  rd_integer(x);\r\
    \n}\r\n\r\ntemplate <class T>\r\nenable_if_t<is_floating_point_v<T> || is_same_v<T,\
    \ f128>> rd(T &x) {\r\n  rd_real(x);\r\n}\r\n\r\ntemplate <class T, class U>\r\
    \nvoid rd(pair<T, U> &p) {\r\n  rd(p.first), rd(p.second);\r\n}\r\ntemplate <size_t\
    \ N = 0, typename T>\r\nvoid rd_tuple(T &t) {\r\n  if constexpr (N < tuple_size<T>::value)\
    \ {\r\n    auto &x = get<N>(t);\r\n    rd(x);\r\n    rd_tuple<N + 1>(t);\r\n \
    \ }\r\n}\r\ntemplate <class... T>\r\nvoid rd(tuple<T...> &tpl) {\r\n  rd_tuple(tpl);\r\
    \n}\r\n\r\ntemplate <class T, size_t N>\r\nvoid rd(array<T, N> &x) {\r\n  for\
    \ (auto &d : x) rd(d);\r\n}\r\ntemplate <class T>\r\nvoid rd(vc<T> &x) {\r\n \
    \ for (auto &d : x) rd(d);\r\n}\r\n\r\ntemplate <class... T>\r\nvoid read(T &...x)\
    \ {\r\n  (rd(x), ...);\r\n}\r\n\r\ninline void wt_range(const char *s, size_t\
    \ n) {\r\n  size_t i = 0;\r\n  while (i < n) {\r\n    if (por == SZ) flush();\r\
    \n    size_t chunk = min(n - i, (size_t)(SZ - por));\r\n    memcpy(obuf + por,\
    \ s + i, chunk);\r\n    por += chunk;\r\n    i += chunk;\r\n  }\r\n}\r\n\r\nvoid\
    \ wt(const char c) {\r\n  if (por == SZ) flush();\r\n  obuf[por++] = c;\r\n}\r\
    \nvoid wt(const char *s) { wt_range(s, strlen(s)); }\r\nvoid wt(const string &s)\
    \ { wt_range(s.data(), s.size()); }\r\n\r\ntemplate <typename T>\r\nvoid wt_integer(T\
    \ x) {\r\n  if (por > SZ - 100) flush();\r\n  using U = unsigned_integer_t<T>;\r\
    \n  U y = static_cast<U>(x);\r\n  if constexpr (is_signed_integer_v<T>) {\r\n\
    \    if (x < 0) {\r\n      obuf[por++] = '-';\r\n      y = U(0) - y;\r\n    }\r\
    \n  }\r\n  int outi;\r\n  for (outi = 96; y >= 10000; outi -= 4) {\r\n    memcpy(out\
    \ + outi, pre.num[y % 10000], 4);\r\n    y /= 10000;\r\n  }\r\n  if (y >= 1000)\
    \ {\r\n    memcpy(obuf + por, pre.num[y], 4);\r\n    por += 4;\r\n  } else if\
    \ (y >= 100) {\r\n    memcpy(obuf + por, pre.num[y] + 1, 3);\r\n    por += 3;\r\
    \n  } else if (y >= 10) {\r\n    int q = (y * 103) >> 10;\r\n    obuf[por] = q\
    \ | '0';\r\n    obuf[por + 1] = (y - q * 10) | '0';\r\n    por += 2;\r\n  } else\r\
    \n    obuf[por++] = y | '0';\r\n  memcpy(obuf + por, out + outi + 4, 96 - outi);\r\
    \n  por += 96 - outi;\r\n}\r\n\r\ntemplate <typename T>\r\ninline void wt_real(T\
    \ x) {\r\n  static char buf[1000];\r\n  int n = std::snprintf(buf, sizeof(buf),\
    \ \"%.15f\", (double)x);\r\n  wt_range(buf, (size_t)n);\r\n}\r\n\r\ntemplate <class\
    \ T>\r\nenable_if_t<is_integral_v<T> || is_same_v<T, i128> || is_same_v<T, u128>>\
    \ wt(\r\n    T x) {\r\n  wt_integer(x);\r\n}\r\n\r\ntemplate <class T>\r\nenable_if_t<is_floating_point_v<T>\
    \ || is_same_v<T, f128>> wt(T x) {\r\n  wt_real(x);\r\n}\r\n\r\ninline void wt(bool\
    \ b) { wt(static_cast<char>('0' + (b ? 1 : 0))); }\r\n\r\ntemplate <class T, class\
    \ U>\r\nvoid wt(const pair<T, U> &val) {\r\n  wt(val.first);\r\n  wt(' ');\r\n\
    \  wt(val.second);\r\n}\r\ntemplate <size_t N = 0, typename T>\r\nvoid wt_tuple(const\
    \ T &t) {\r\n  if constexpr (N < tuple_size<T>::value) {\r\n    if constexpr (N\
    \ > 0) wt(' ');\r\n    wt(get<N>(t));\r\n    wt_tuple<N + 1>(t);\r\n  }\r\n}\r\
    \ntemplate <class... T>\r\nvoid wt(const tuple<T...> &tpl) {\r\n  wt_tuple(tpl);\r\
    \n}\r\ntemplate <class T, size_t S>\r\nvoid wt(const array<T, S> &val) {\r\n \
    \ auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n    if (i) wt('\
    \ ');\r\n    wt(val[i]);\r\n  }\r\n}\r\ntemplate <class T>\r\nvoid wt(const vector<T>\
    \ &val) {\r\n  auto n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n\
    \    if (i) wt(' ');\r\n    wt(val[i]);\r\n  }\r\n}\r\n\r\nvoid print() { wt('\\\
    n'); }\r\ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail\
    \ &&...tail) {\r\n  wt(forward<Head>(head));\r\n  ((wt(' '), wt(forward<Tail>(tail))),\
    \ ...);\r\n  wt('\\n');\r\n}\r\n\r\n// gcc expansion. called automaticall after\
    \ main.\r\nvoid __attribute__((destructor)) _d() { flush(); }\r\n}  // namespace\
    \ fastio\r\nusing fastio::flush;\r\nusing fastio::print;\r\nusing fastio::read;\r\
    \n\r\n#if defined(LOCAL)\r\n#define HDR \"[DEBUG:\", __func__, __LINE__, \"]\"\
    \r\n#define SHOW(...)                                                        \
    \ \\\r\n  SHOW_IMPL(__VA_ARGS__, SHOW8, SHOW7, SHOW6, SHOW5, SHOW4, SHOW3, SHOW2,\
    \ \\\r\n            SHOW1)                                                   \
    \     \\\r\n  (__VA_ARGS__)\r\n#define SHOW_IMPL(_1, _2, _3, _4, _5, _6, _7, _8,\
    \ NAME, ...) NAME\r\n#define SHOW1(x) print(HDR, #x, \"=\", (x)), flush()\r\n\
    #define SHOW2(x, y) print(HDR, #x, \"=\", (x), #y, \"=\", (y)), flush()\r\n#define\
    \ SHOW3(x, y, z) \\\r\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\"\
    , (z)), flush()\r\n#define SHOW4(x, y, z, w) \\\r\n  print(HDR, #x, \"=\", (x),\
    \ #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w)), flush()\r\n#define SHOW5(x,\
    \ y, z, w, v)                                                  \\\r\n  print(HDR,\
    \ #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\
    \r\n        (v)),                                                            \
    \     \\\r\n      flush()\r\n#define SHOW6(x, y, z, w, v, u)                 \
    \                              \\\r\n  print(HDR, #x, \"=\", (x), #y, \"=\", (y),\
    \ #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\r\n        (v), #u, \"=\", (u)),\
    \                                                   \\\r\n      flush()\r\n#define\
    \ SHOW7(x, y, z, w, v, u, t)                                            \\\r\n\
    \  print(HDR, #x, \"=\", (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w),\
    \ #v, \"=\", \\\r\n        (v), #u, \"=\", (u), #t, \"=\", (t)),             \
    \                        \\\r\n      flush()\r\n#define SHOW8(x, y, z, w, v, u,\
    \ t, s)                                         \\\r\n  print(HDR, #x, \"=\",\
    \ (x), #y, \"=\", (y), #z, \"=\", (z), #w, \"=\", (w), #v, \"=\", \\\r\n     \
    \   (v), #u, \"=\", (u), #t, \"=\", (t), #s, \"=\", (s)),                    \
    \   \\\r\n      flush()\r\n#else\r\n#define SHOW(...)\r\n#endif\r\n\r\n#define\
    \ INT(...)   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)\
    \   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define U32(...)   \\\
    \r\n  u32 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define U64(...)   \\\r\n\
    \  u64 __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n\
    \  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)   \\\r\n\
    \  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n\
    \  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name,\
    \ size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type,\
    \ name, h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print(t ? \"YES\" : \"NO\"\
    ); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print(t ? \"\
    Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool t = 1)\
    \ { print(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t); }\r\nvoid\
    \ YA(bool t = 1) { print(t ? \"YA\" : \"TIDAK\"); }\r\nvoid TIDAK(bool t = 1)\
    \ { YA(!t); }\r\nvoid Alice(bool t = 1) { print(t ? \"Alice\" : \"Bob\"); }\r\n\
    void Bob(bool t = 1) { Alice(!t); }\n#line 5 \"test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp\"\
    \n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 2 \"ds/bit_vector.hpp\"\n\
    \nstruct Bit_Vector {\n  int n;\n  bool prepared = 0;\n  vc<pair<u64, u32>> dat;\n\
    \  Bit_Vector(int n = 0) : n(n) { dat.assign((n + 127) >> 6, {0, 0}); }\n  void\
    \ set(int i) {\n    assert(!prepared && (0 <= i && i < n));\n    dat[i >> 6].fi\
    \ |= u64(1) << (i & 63);\n  }\n  void reset() {\n    fill(all(dat), pair<u64,\
    \ u32>{0, 0});\n    prepared = 0;\n  }\n  void build() {\n    prepared = 1;\n\
    \    FOR(i, len(dat) - 1) dat[i + 1].se = dat[i].se + popcnt(dat[i].fi);\n  }\n\
    \  bool operator[](int i) const { return dat[i >> 6].fi >> (i & 63) & 1; }\n \
    \ // [0, k) \u5185\u306E 1 \u306E\u500B\u6570\n  int count_prefix(int k, bool\
    \ f = true) const {\n    assert(prepared);\n    auto [a, b] = dat[k >> 6];\n \
    \   int ret = b + popcnt(a & ((u64(1) << (k & 63)) - 1));\n    return (f ? ret\
    \ : k - ret);\n  }\n  int count(int L, int R, bool f = true) const {\n    return\
    \ count_prefix(R, f) - count_prefix(L, f);\n  }\n  string to_string() const {\n\
    \    string ans;\n    FOR(i, n) ans += '0' + (dat[i / 64].fi >> (i % 64) & 1);\n\
    \    return ans;\n  }\n};\n#line 1 \"alg/monoid/dummy.hpp\"\nstruct Monoid_Dummy\
    \ {\n  using value_type = char;\n  static constexpr bool commute = true;\n  static\
    \ value_type op(value_type, value_type) { return 0; }\n  static value_type id()\
    \ { return 0; }\n};\n#line 2 \"ds/dummy_data_structure.hpp\"\n\nstruct Dummy_Data_Structure\
    \ {\n  using MX = Monoid_Dummy;\n  using T = typename MX::value_type;\n  void\
    \ build(const vc<T>& A) {}\n};\n#line 3 \"ds/wavelet_matrix/wavelet_matrix.hpp\"\
    \n\r\ntemplate <typename Y, typename SEGTREE>\r\nstruct Uncompressed_Wavelet_Matrix\
    \ {\r\n  using Mono = typename SEGTREE::MX;\r\n  using T = typename Mono::value_type;\r\
    \n  static_assert(Mono::commute);\r\n  static_assert(is_same_v<Y, int> || is_same_v<Y,\
    \ ll>);\r\n  int n = 0, log = 0;\r\n  vc<int> mid;\r\n  vc<Bit_Vector> bv;\r\n\
    \  vc<SEGTREE> seg;\r\n  Y limit;\r\n\r\n  Uncompressed_Wavelet_Matrix() = default;\r\
    \n\r\n  // f(i) = {A[i], dat[i]}\r\n  template <typename F>\r\n  Uncompressed_Wavelet_Matrix(int\
    \ n, F f, int log = -1) {\r\n    build(n, f, log);\r\n  }\r\n  Uncompressed_Wavelet_Matrix(const\
    \ vc<Y>& A, int log = -1) {\r\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\r\
    \n    build(len(A), [&](int i) -> pair<Y, T> { return {A[i], Mono::id()}; }, log);\r\
    \n  }\r\n\r\n  template <typename F>\r\n  void build(int n, F f, int log = -1)\
    \ {\r\n    this->n = n;\r\n    vc<Y> A(n);\r\n    vc<T> S(n);\r\n    FOR(i, n)\
    \ tie(A[i], S[i]) = f(i);\r\n    if (log == -1) {\r\n      log = (n == 0 ? 0 :\
    \ topbit(MAX(A)) + 1);\r\n    } else {\r\n      for (auto& x : A) assert(0 <=\
    \ x && topbit(x) < log);\r\n    }\r\n    this->log = log;\r\n    limit = Y(1)\
    \ << log;\r\n    if constexpr (is_same_v<Y, int>) assert(0 <= log && log <= 30);\r\
    \n    if constexpr (is_same_v<Y, ll>) assert(0 <= log && log <= 62);\r\n    mid.resize(log),\
    \ bv.assign(log, Bit_Vector(n));\r\n    vc<Y> A0(n), A1(n);\r\n    vc<T> S0(n),\
    \ S1(n);\r\n    seg.resize(log + 1);\r\n    seg[log].build(S);\r\n    for (int\
    \ d = log - 1; d >= 0; --d) {\r\n      int p0 = 0, p1 = 0;\r\n      for (int i\
    \ = 0; i < n; ++i) {\r\n        if (A[i] >> d & 1) {\r\n          bv[d].set(i),\
    \ A1[p1] = A[i], S1[p1] = S[i], p1++;\r\n        } else {\r\n          A0[p0]\
    \ = A[i], S0[p0] = S[i], p0++;\r\n        }\r\n      }\r\n      swap(A, A0), swap(S,\
    \ S0);\r\n      move(A1.begin(), A1.begin() + p1, A.begin() + p0);\r\n      move(S1.begin(),\
    \ S1.begin() + p1, S.begin() + p0);\r\n      mid[d] = p0, bv[d].build(), seg[d].build(S);\r\
    \n    }\r\n  }\r\n\r\n  tuple<int, int, int, int> get_subtree(int d, int L, int\
    \ R) const {\r\n    assert(1 <= d && d <= log);\r\n    int a = bv[d - 1].count_prefix(L),\
    \ b = bv[d - 1].count_prefix(R);\r\n    return {L - a, R - b, mid[d - 1] + a,\
    \ mid[d - 1] + b};\r\n  }\r\n\r\n  template <typename F>\r\n  void work_point(F\
    \ f, int i) {\r\n    assert(0 <= i && i < n);\r\n    f(log, i);\r\n    FOR_R(d,\
    \ log) {\r\n      int a = bv[d].count_prefix(i);\r\n      if (bv[d][i]) {\r\n\
    \        i = mid[d] + a;\r\n      } else {\r\n        i = i - a;\r\n      }\r\n\
    \      f(d, i);\r\n    }\r\n  }\r\n\r\n  template <typename F>\r\n  void work_prefix(F\
    \ f, int L, int R, Y y) const {\r\n    chmin(y, limit);\r\n    if (y == 0) return;\r\
    \n    if (y == limit) {\r\n      f(log, L, R);\r\n      return;\r\n    }\r\n \
    \   FOR_R(d, log) {\r\n      auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\
    \n      if (y >> d & 1) {\r\n        f(d, L0, R0);\r\n        L = L1, R = R1;\r\
    \n      } else {\r\n        L = L0, R = R0;\r\n      }\r\n    }\r\n  }\r\n\r\n\
    \  template <typename F>\r\n  void work_range(F f, int L, int R, Y y1, Y y2) const\
    \ {\r\n    chmin(y2, limit);\r\n    if (y1 >= y2) return;\r\n    assert(0 <= y1\
    \ && y1 <= y2 && y2 <= limit);\r\n    if (y1 == 0) return work_prefix(f, L, R,\
    \ y2);\r\n    auto dfs = [&](auto& dfs, int d, int L, int R, Y y1, Y y2) -> void\
    \ {\r\n      if (y1 == y2) return;\r\n      if (y1 == 0 && y2 == Y(1) << d) {\r\
    \n        f(d, L, R);\r\n        return;\r\n      }\r\n      assert(d > 0);\r\n\
    \      auto [L0, R0, L1, R1] = get_subtree(d, L, R);\r\n      Y m = (Y(1) << (d\
    \ - 1));\r\n\r\n      if (y2 <= m) {\r\n        dfs(dfs, d - 1, L0, R0, y1, y2);\r\
    \n      } else if (y1 >= m) {\r\n        dfs(dfs, d - 1, L1, R1, y1 - m, y2 -\
    \ m);\r\n      } else {\r\n        dfs(dfs, d - 1, L0, R0, y1, m);\r\n       \
    \ dfs(dfs, d - 1, L1, R1, 0, y2 - m);\r\n      }\r\n    };\r\n    dfs(dfs, log,\
    \ L, R, y1, y2);\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  int prefix_count(int L,\
    \ int R, Y y) const {\r\n    int cnt = 0;\r\n    work_prefix([&](int d, int a,\
    \ int b) { cnt += b - a; }, L, R, y);\r\n    return cnt;\r\n  }\r\n\r\n  // [L,R)\
    \ x [y1,y2)\r\n  int count(int L, int R, Y y1, Y y2) const {\r\n    return prefix_count(L,\
    \ R, y2) - prefix_count(L, R, y1);\r\n  }\r\n\r\n  // [L,R) x [0,y)\r\n  T prefix_prod(int\
    \ L, int R, Y y) const {\r\n    T ans = Mono::id();\r\n    work_prefix(\r\n  \
    \      [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); }, L,\r\
    \n        R, y);\r\n    return ans;\r\n  }\r\n  // [L,R) x [y1,y2)\r\n  T prod(int\
    \ L, int R, Y y1, Y y2) const {\r\n    T ans = Mono::id();\r\n    work_range(\r\
    \n        [&](int d, int a, int b) { ans = Mono::op(ans, seg[d].prod(a, b)); },\
    \ L,\r\n        R, y1, y2);\r\n    return ans;\r\n  }\r\n  T prod_all(int L, int\
    \ R) const { return seg[log].prod(L, R); }\r\n\r\n  // [L,R) x [0,y)\r\n  pair<int,\
    \ T> prefix_count_and_prod(int L, int R, Y y) const {\r\n    pair<int, T> ans\
    \ = {0, Mono::id()};\r\n    work_prefix(\r\n        [&](int d, int a, int b) {\r\
    \n          ans.fi += b - a;\r\n          ans.se = Mono::op(ans.se, seg[d].prod(a,\
    \ b));\r\n        },\r\n        L, R, y);\r\n    return ans;\r\n  }\r\n  // [L,R)\
    \ x [y1,y2)\r\n  pair<int, T> count_and_prod(int L, int R, Y y1, Y y2) const {\r\
    \n    pair<int, T> ans = {0, Mono::id()};\r\n    work_range(\r\n        [&](int\
    \ d, int a, int b) {\r\n          ans.fi += b - a;\r\n          ans.se = Mono::op(ans.se,\
    \ seg[d].prod(a, b));\r\n        },\r\n        L, R, y1, y2);\r\n    return ans;\r\
    \n  }\r\n\r\n  Y kth(int L, int R, int k) const {\r\n    assert(0 <= k && k <\
    \ R - L);\r\n    Y ans = 0;\r\n    for (int d = log - 1; d >= 0; --d) {\r\n  \
    \    auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\n      if (k < R0 - L0)\
    \ {\r\n        L = L0, R = R0;\r\n      } else {\r\n        ans |= Y(1) << d;\r\
    \n        k -= R0 - L0, L = L1, R = R1;\r\n      }\r\n    }\r\n    return ans;\r\
    \n  }\r\n\r\n  template <bool upper>\r\n  Y median(int L, int R) const {\r\n \
    \   assert(0 <= L && L < R && R <= n);\r\n    int k = (upper ? (R - L) / 2 : (R\
    \ - L - 1) / 2);\r\n    return kth(L, R, k);\r\n  }\r\n\r\n  void set(int i, T\
    \ t) {\r\n    assert(0 <= i && i < n);\r\n    work_point([&](int d, int i) { seg[d].set(i,\
    \ t); }, i);\r\n  }\r\n  void multiply(int i, T t) {\r\n    assert(0 <= i && i\
    \ < n);\r\n    work_point([&](int d, int i) { seg[d].multiply(i, t); }, i);\r\n\
    \  }\r\n  void add(int i, T t) {\r\n    assert(0 <= i && i < n);\r\n    work_point([&](int\
    \ d, int i) { seg[d].add(i, t); }, i);\r\n  }\r\n\r\n  // [L,R) x [0,y) \u3067\
    \u306E check(y, cnt, prod) \u304C true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\r\
    \n  // cnt \u306F\u30C7\u30FC\u30BF\u4EF6\u6570\u5168\u4F53\u3067\u3042\u3063\u3066\
    , activate/deactivate \u3092\u8003\u616E\u3059\u308B\u5834\u5408\u306B\u306F\r\
    \n  // prod \u306E\u65B9\u3092\u898B\u308B\u5FC5\u8981\u304C\u3042\u308B\r\n \
    \ template <typename F>\r\n  tuple<Y, int, T> max_right(F check, int L, int R)\
    \ const {\r\n    int cnt = 0;\r\n    Y y = 0;\r\n    T t = Mono::id();\r\n   \
    \ T t_all = seg[log].prod(L, R);\r\n    assert(check(0, 0, Mono::id()));\r\n \
    \   if (check(infty<Y>, R - L, t_all)) {\r\n      return {infty<Y>, R - L, t_all};\r\
    \n    }\r\n    for (int d = log - 1; d >= 0; --d) {\r\n      auto [L0, R0, L1,\
    \ R1] = get_subtree(d + 1, L, R);\r\n      Y y1 = y | Y(1) << d;\r\n      int\
    \ cnt1 = cnt + R0 - L0;\r\n      T t1 = Mono::op(t, seg[d].prod(L0, R0));\r\n\
    \      if (check(y1, cnt1, t1)) {\r\n        y = y1, cnt = cnt1, t = t1, L = L1,\
    \ R = R1;\r\n      } else {\r\n        L = L0, R = R0;\r\n      }\r\n    }\r\n\
    \    return {y, cnt, t};\r\n  }\r\n\r\n  // [L,R) x [0,y) \u3067\u306E check(y,\
    \ cnt, prod) \u304C true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\r\n\
    \  template <typename F>\r\n  tuple<Y, int, T> max_right_many(F check, vc<pair<int,\
    \ int>> LR) const {\r\n    int cnt = 0;\r\n    Y y = 0;\r\n    T t = Mono::id();\r\
    \n    T t_all = Mono::id();\r\n    int cnt_all = 0;\r\n    for (auto& [l, r] :\
    \ LR)\r\n      t_all = Mono::op(t_all, prod_all(l, r)), cnt_all += r - l;\r\n\
    \    assert(check(0, 0, Mono::id()));\r\n    if (check(infty<Y>, cnt_all, t_all))\
    \ {\r\n      return {infty<Y>, cnt_all, t_all};\r\n    }\r\n    for (int d = log\
    \ - 1; d >= 0; --d) {\r\n      Y y1 = Y(1) << d;\r\n      T t1 = t;\r\n      int\
    \ cnt1 = 0;\r\n      for (auto& [L, R] : LR) {\r\n        auto [L0, R0, L1, R1]\
    \ = get_subtree(d + 1, L, R);\r\n        cnt1 += R0 - L0;\r\n        t1 = Mono::op(t1,\
    \ seg[d].prod(L0, R0));\r\n      }\r\n      if (check(y1, cnt1, t1)) {\r\n   \
    \     y = y1, cnt = cnt1, t = t1;\r\n        for (auto& [L, R] : LR) {\r\n   \
    \       auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\n          L = L1,\
    \ R = R1;\r\n        }\r\n      } else {\r\n        for (auto& [L, R] : LR) {\r\
    \n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\n          L =\
    \ L0, R = R0;\r\n        }\r\n      }\r\n    }\r\n    return {y, cnt, t};\r\n\
    \  }\r\n\r\n  // [L,R) x [y, inf) \u3067\u306E check(y, cnt, prod) \u304C true\
    \ \u3068\u306A\u308B\u6700\u5C0F\u306E (y,cnt,prod)\r\n  // cnt==0 \u3060\u3068\
    \ true \u3067\u3042\u308B\u3053\u3068\u306F\u4EEE\u5B9A\u3059\u308B\r\n  // https://qoj.ac/contest/1047/problem/5094\r\
    \n  template <typename F>\r\n  tuple<Y, int, T> min_left_many(F check, vc<pair<int,\
    \ int>> LR) const {\r\n    assert(check(limit, 0, Mono::id()));\r\n    int cnt\
    \ = 0;\r\n    Y y = limit;\r\n    T t = Mono::id();\r\n    T t_all = Mono::id();\r\
    \n    int cnt_all = 0;\r\n    for (auto& [l, r] : LR)\r\n      t_all = Mono::op(t_all,\
    \ prod_all(l, r)), cnt_all += r - l;\r\n    if (check(0, cnt_all, t_all)) {\r\n\
    \      return {0, cnt_all, t_all};\r\n    }\r\n    for (int d = log - 1; d >=\
    \ 0; --d) {\r\n      Y y1 = y - (Y(1) << d);\r\n      T t1 = t;\r\n      int cnt1\
    \ = cnt;\r\n      for (auto& [L, R] : LR) {\r\n        auto [L0, R0, L1, R1] =\
    \ get_subtree(d + 1, L, R);\r\n        cnt1 += R1 - L1;\r\n        t1 = Mono::op(t1,\
    \ seg[d].prod(L1, R1));\r\n      }\r\n      if (check(y1, cnt1, t1)) {\r\n   \
    \     y = y1, cnt = cnt1, t = t1;\r\n        SHOW(y);\r\n        for (auto& [L,\
    \ R] : LR) {\r\n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\n\
    \          L = L0, R = R0;\r\n        }\r\n      } else {\r\n        for (auto&\
    \ [L, R] : LR) {\r\n          auto [L0, R0, L1, R1] = get_subtree(d + 1, L, R);\r\
    \n          L = L1, R = R1;\r\n        }\r\n      }\r\n    }\r\n    SHOW(y, cnt,\
    \ t);\r\n    return {y, cnt, t};\r\n  }\r\n};\r\n\r\ntemplate <typename Y, typename\
    \ SEGTREE>\r\nstruct Compressed_Wavelet_Matrix {\r\n  using Mono = typename SEGTREE::MX;\r\
    \n  using T = typename Mono::value_type;\r\n\r\n  int n = 0;\r\n  vc<Y> key;\r\
    \n  Uncompressed_Wavelet_Matrix<int, SEGTREE> wm;\r\n\r\n  Compressed_Wavelet_Matrix()\
    \ = default;\r\n\r\n  // f(i) = {A[i], dat[i]}\r\n  template <typename F>\r\n\
    \  Compressed_Wavelet_Matrix(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n\
    \  Compressed_Wavelet_Matrix(const vc<Y>& A) {\r\n    static_assert(is_same_v<SEGTREE,\
    \ Dummy_Data_Structure>);\r\n    build(A);\r\n  }\r\n\r\n  template <typename\
    \ F>\r\n  void build(int n, F f) {\r\n    this->n = n;\r\n    vc<Y> A(n);\r\n\
    \    vc<T> S(n);\r\n    FOR(i, n) tie(A[i], S[i]) = f(i);\r\n\r\n    key = A;\r\
    \n    UNIQUE(key);\r\n\r\n    wm.build(n, [&](int i) -> pair<int, T> {\r\n   \
    \   int k = LB(key, A[i]);\r\n      return {k, S[i]};\r\n    });\r\n  }\r\n\r\n\
    \  void build(const vc<Y>& A) {\r\n    static_assert(is_same_v<SEGTREE, Dummy_Data_Structure>);\r\
    \n    n = len(A);\r\n    key = A;\r\n    UNIQUE(key);\r\n\r\n    wm.build(n, [&](int\
    \ i) -> pair<int, T> {\r\n      int k = LB(key, A[i]);\r\n      return {k, Mono::id()};\r\
    \n    });\r\n  }\r\n\r\n  Y kth(int L, int R, int k) const { return key[wm.kth(L,\
    \ R, k)]; }\r\n\r\n  template <bool upper>\r\n  Y median(int L, int R) const {\r\
    \n    return key[wm.template median<upper>(L, R)];\r\n  }\r\n\r\n  // [L,R) x\
    \ [-inf,y)\r\n  int prefix_count(int L, int R, Y y) const {\r\n    return wm.prefix_count(L,\
    \ R, LB(key, y));\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  int count(int L, int\
    \ R, Y y1, Y y2) const {\r\n    return wm.count(L, R, LB(key, y1), LB(key, y2));\r\
    \n  }\r\n\r\n  // [L,R) x [-inf,y)\r\n  T prefix_prod(int L, int R, Y y) const\
    \ {\r\n    return wm.prefix_prod(L, R, LB(key, y));\r\n  }\r\n\r\n  // [L,R) x\
    \ [y1,y2)\r\n  T prod(int L, int R, Y y1, Y y2) const {\r\n    return wm.prod(L,\
    \ R, LB(key, y1), LB(key, y2));\r\n  }\r\n\r\n  T prod_all(int L, int R) const\
    \ { return wm.prod_all(L, R); }\r\n\r\n  // [L,R) x [-inf,y)\r\n  pair<int, T>\
    \ prefix_count_and_prod(int L, int R, Y y) const {\r\n    return wm.prefix_count_and_prod(L,\
    \ R, LB(key, y));\r\n  }\r\n\r\n  // [L,R) x [y1,y2)\r\n  pair<int, T> count_and_prod(int\
    \ L, int R, Y y1, Y y2) const {\r\n    return wm.count_and_prod(L, R, LB(key,\
    \ y1), LB(key, y2));\r\n  }\r\n\r\n  void set(int i, T t) { wm.set(i, t); }\r\n\
    \r\n  void multiply(int i, T t) { wm.multiply(i, t); }\r\n\r\n  void add(int i,\
    \ T t) { wm.add(i, t); }\r\n};\r\n\r\ntemplate <typename Y, bool compress, typename\
    \ SEGTREE = Dummy_Data_Structure>\r\nusing Wavelet_Matrix =\r\n    conditional_t<compress,\
    \ Compressed_Wavelet_Matrix<Y, SEGTREE>,\r\n        Uncompressed_Wavelet_Matrix<Y,\
    \ SEGTREE>>;\r\n#line 1 \"ds/index_compression.hpp\"\ntemplate <typename T>\n\
    struct Index_Compression_DISTINCT_SMALL {\n  int mi, ma;\n  vc<T> dat;\n  vc<T>\
    \ build(vc<int> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x : X) dat[x - mi\
    \ + 1]++;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x :\
    \ X) {\n      x = dat[x - mi]++;\n    }\n    FOR_R(i, 1, len(dat)) dat[i] = dat[i\
    \ - 1];\n    dat[0] = 0;\n    return X;\n  }\n  int size() const { return len(dat);\
    \ }\n  int val_to_idx(T x) const { return dat[clamp<ll>(x - mi, 0, ma - mi + 1)];\
    \ }\n  int idx_to_val(int i) const { return dat[i]; }\n};\n\ntemplate <typename\
    \ T>\nstruct Index_Compression_SAME_SMALL {\n  int mi, ma;\n  vc<T> dat;\n  vc<T>\
    \ build(vc<T> X) {\n    mi = 0, ma = -1;\n    if (!X.empty()) mi = MIN(X), ma\
    \ = MAX(X);\n    dat.assign(ma - mi + 2, 0);\n    for (auto& x : X) dat[x - mi\
    \ + 1] = 1;\n    FOR(i, len(dat) - 1) dat[i + 1] += dat[i];\n    for (auto& x\
    \ : X) {\n      x = dat[x - mi];\n    }\n    return X;\n  }\n  int size() const\
    \ { return len(dat); }\n  int val_to_idx(T x) const { return dat[clamp<ll>(x -\
    \ mi, 0, ma - mi + 1)]; }\n  int idx_to_val(int i) const { return dat[i]; }\n\
    };\n\ntemplate <typename T>\nstruct Index_Compression_SAME_LARGE {\n  vc<T> dat;\n\
    \  vc<int> build(const vc<T>& X) {\n    dat.reserve(len(X));\n    vc<pair<T, int>>\
    \ tmp(len(X));\n    FOR(i, len(X)) tmp[i] = {X[i], i};\n    sort(all(tmp));\n\
    \    vc<int> ANS(len(X));\n    for (auto [x, j] : tmp) {\n      if (dat.empty()\
    \ || dat.back() != x) dat.eb(x);\n      ANS[j] = len(dat) - 1;\n    }\n    return\
    \ ANS;\n  }\n  int size() const { return len(dat); }\n  int val_to_idx(T x) const\
    \ { return LB(dat, x); }\n  int idx_to_val(int i) const { return dat[i]; }\n};\n\
    \ntemplate <typename T>\nstruct Index_Compression_DISTINCT_LARGE {\n  vc<T> dat;\n\
    \  vc<int> build(vc<T> X) {\n    dat.reserve(len(X));\n    vc<pair<T, int>> tmp(len(X));\n\
    \    FOR(i, len(X)) tmp[i] = {X[i], i};\n    sort(all(tmp));\n    vc<int> ANS(len(X));\n\
    \    for (auto [x, j] : tmp) {\n      dat.eb(x);\n      ANS[j] = len(dat) - 1;\n\
    \    }\n    return ANS;\n  }\n  int size() const { return len(dat); }\n  int val_to_idx(T\
    \ x) const { return LB(dat, x); }\n  int idx_to_val(int i) const { return dat[i];\
    \ }\n};\n\ntemplate <typename T, bool SMALL>\nusing Index_Compression_DISTINCT\
    \ =\n    typename std::conditional<SMALL, Index_Compression_DISTINCT_SMALL<T>,\n\
    \                              Index_Compression_DISTINCT_LARGE<T>>::type;\ntemplate\
    \ <typename T, bool SMALL>\nusing Index_Compression_SAME =\n    typename std::conditional<SMALL,\
    \ Index_Compression_SAME_SMALL<T>,\n                              Index_Compression_SAME_LARGE<T>>::type;\n\
    \n// SAME: [2,3,2] -> [0,1,0]\n// DISTINCT: [2,2,3] -> [0,2,1]\n// build \u3067\
    \u5217\u3092\u5727\u7E2E\u3057\u3066\u304F\u308C\u308B. \u305D\u306E\u3042\u3068\
    \n// (x): lower_bound(X,x) \u3092\u304B\u3048\u3059\ntemplate <typename T, bool\
    \ SAME, bool SMALL>\nusing Index_Compression =\n    typename std::conditional<SAME,\
    \ Index_Compression_SAME<T, SMALL>,\n                              Index_Compression_DISTINCT<T,\
    \ SMALL>>::type;\n#line 3 \"ds/wavelet_matrix/wavelet_matrix_2d_range.hpp\"\n\n\
    template <typename XY, bool compress_X, bool compress_Y,\n          typename SEGTREE\
    \ = Dummy_Data_Structure>\nstruct Wavelet_Matrix_2D_Range {\n  // \u70B9\u7FA4\
    \u3092 X \u6607\u9806\u306B\u4E26\u3079\u308B.\n  Wavelet_Matrix<XY, compress_Y,\
    \ SEGTREE> WM;\n  using Mono = typename SEGTREE::MX;\n  using T = typename Mono::value_type;\n\
    \  static_assert(Mono::commute);\n\n  Index_Compression<XY, false, !compress_X>\
    \ IDX_X;\n\n  int n;\n  vc<int> new_idx;\n\n  template <typename F>\n  Wavelet_Matrix_2D_Range(int\
    \ n, F f) {\n    build(n, f);\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    n = m;\n    vc<XY> X(n), Y(n);\n    vc<T> S(n);\n    FOR(i, n)\
    \ {\n      auto tmp = f(i);\n      X[i] = get<0>(tmp), Y[i] = get<1>(tmp), S[i]\
    \ = get<2>(tmp);\n    }\n    new_idx = IDX_X.build(X);\n    vc<int> I(n);\n  \
    \  FOR(i, n) I[new_idx[i]] = i;\n    Y = rearrange(Y, I);\n    S = rearrange(S,\
    \ I);\n    WM.build(n, [&](int i) -> pair<XY, T> { return {Y[i], S[i]}; });\n\
    \  }\n\n  int count(XY x1, XY x2, XY y1, XY y2) {\n    return WM.count(IDX_X.val_to_idx(x1),\
    \ IDX_X.val_to_idx(x2), y1, y2);\n  }\n\n  // [L,R) x [-inf,y)\n  pair<int, T>\
    \ prefix_count_and_prod(XY x1, XY x2, XY y) {\n    return WM.prefix_count_and_prod(IDX_X.val_to_idx(x1),\
    \ IDX_X.val_to_idx(x2),\n                                    y);\n  }\n\n  //\
    \ [L,R) x [y1,y2)\n  pair<int, T> count_and_prod(XY x1, XY x2, XY y1, XY y2) {\n\
    \    return WM.count_and_prod(IDX_X.val_to_idx(x1), IDX_X.val_to_idx(x2), y1,\n\
    \                             y2);\n  }\n\n  // [L,R) x [-inf,inf)\n  T prod_all(XY\
    \ x1, XY x2) {\n    return WM.prod_all(IDX_X.val_to_idx(x1), IDX_X.val_to_idx(x2));\n\
    \  }\n  // [L,R) x [-inf,y)\n  T prefix_prod(XY x1, XY x2, XY y) {\n    return\
    \ WM.prefix_prod(IDX_X.val_to_idx(x1), IDX_X.val_to_idx(x2), y);\n  }\n  // [L,R)\
    \ x [y1,y2)\n  T prod(XY x1, XY x2, XY y1, XY y2) {\n    return WM.prod(IDX_X.val_to_idx(x1),\
    \ IDX_X.val_to_idx(x2), y1, y2);\n  }\n  // i \u306F\u6700\u521D\u306B\u6E21\u3057\
    \u305F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n  void set(int i, T t) { WM.set(new_idx[i],\
    \ t); }\n  // i \u306F\u6700\u521D\u306B\u6E21\u3057\u305F\u30A4\u30F3\u30C7\u30C3\
    \u30AF\u30B9\n  void multiply(int i, T t) { WM.multiply(new_idx[i], t); }\n  void\
    \ add(int i, T t) { WM.multiply(new_idx[i], t); }\n\n  // [L,R) x [0,y) \u3067\
    \u306E check(y, cnt, prod) \u304C true \u3068\u306A\u308B\u6700\u5927\u306E (Y,cnt,prod)\n\
    \  // cnt \u306F\u30C7\u30FC\u30BF\u4EF6\u6570\u5168\u4F53\u3067\u3042\u3063\u3066\
    , activate/deactivate \u3092\u8003\u616E\u3059\u308B\u5834\u5408\u306B\u306F\n\
    \  // prod \u306E\u65B9\u3092\u898B\u308B\u5FC5\u8981\u304C\u3042\u308B\n  template\
    \ <typename F>\n  tuple<XY, int, T> max_right(F check, XY x1, XY x2) const {\n\
    \    return WM.max_right(check, IDX_X.val_to_idx(x1), IDX_X.val_to_idx(x2));\n\
    \  }\n};\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"alg/monoid/add.hpp\"\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename Monoid>\n\
    struct FenwickTree {\n  using G = Monoid;\n  using MX = Monoid;\n  using E = typename\
    \ G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() {}\n\
    \  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::id());\n    total\
    \ = G::id();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i)\
    \ -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F\
    \ f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::id();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() const { return\
    \ total; }\n  E sum_all() const { return total; }\n  E sum(int k) const { return\
    \ prefix_sum(k); }\n  E prod(int k) const { return prefix_prod(k); }\n  E prefix_sum(int\
    \ k) const { return prefix_prod(k); }\n  E prefix_prod(int k) const {\n    chmin(k,\
    \ n);\n    E ret = G::id();\n    for (; k > 0; k -= k & -k) ret = G::op(ret, dat[k\
    \ - 1]);\n    return ret;\n  }\n  E sum(int L, int R) const { return prod(L, R);\
    \ }\n  E prod(int L, int R) const {\n    chmax(L, 0), chmin(R, n);\n    if (L\
    \ == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n    E\
    \ pos = G::id(), neg = G::id();\n    while (L < R) {\n      pos = G::op(pos, dat[R\
    \ - 1]), R -= R & -R;\n    }\n    while (R < L) {\n      neg = G::op(neg, dat[L\
    \ - 1]), L -= L & -L;\n    }\n    return G::op(pos, G::inverse(neg));\n  }\n\n\
    \  vc<E> get_all() const {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i,\
    \ i + 1);\n    return res;\n  }\n\n  void add(int k, E x) { multiply(k, x); }\n\
    \  void multiply(int k, E x) {\n    static_assert(G::commute);\n    assert(0 <=\
    \ k && k < n);\n    total = G::op(total, x);\n    for (++k; k <= n; k += k & -k)\
    \ dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int k, E x) { add(k, G::op(G::inverse(prod(k,\
    \ k + 1)), x)); }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L = 0) const {\n    assert(check(G::id()));\n    E s = G::id();\n    int i =\
    \ L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while\
    \ (1) {\n        if (i % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i -\
    \ 1])), i -= 1;\n        }\n        if (i == 0) {\n          return topbit(n)\
    \ + 1;\n        }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) >\
    \ n) return k;\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t))\
    \ {\n          return k;\n        }\n        s = G::op(s, G::inverse(dat[i - 1])),\
    \ i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n      if (i +\
    \ (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n\
    \        if (i + (1 << k) <= L || check(t)) {\n          i += (1 << k), s = t;\n\
    \        }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n  template\
    \ <class F>\n  int max_right_with_index(const F check, int L = 0) const {\n  \
    \  assert(check(L, G::id()));\n    E s = G::id();\n    int i = L;\n    // 2^k\
    \ \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n   \
    \     if (i % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i - 1])), i -=\
    \ 1;\n        }\n        if (i == 0) {\n          return topbit(n) + 1;\n    \
    \    }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(i + (1 <<\
    \ k), t)) {\n          return k;\n        }\n        s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n     \
    \ if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k)\
    \ - 1]);\n        if (i + (1 << k) <= L || check(i + (1 << k), t)) {\n       \
    \   i += (1 << k), s = t;\n        }\n      }\n    }\n    return i;\n  }\n\n \
    \ template <class F>\n  int min_left(const F check, int R) const {\n    assert(check(G::id()));\n\
    \    E s = G::id();\n    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\
    \u308D\u307E\u3067\u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s))\
    \ {\n      s = G::op(s, dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n\
    \    }\n    if (check(s)) {\n      assert(i == 0);\n      return 0;\n    }\n \
    \   // 2^k \u9032\u3080\u3068 ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\
    \u6301\u3057\u3066\u9032\u3080\n    while (k) {\n      --k;\n      E t = G::op(s,\
    \ G::inverse(dat[i + (1 << k) - 1]));\n      if (!check(t)) {\n        i += (1\
    \ << k), s = t;\n      }\n    }\n    return i + 1;\n  }\n\n  int kth(E k, int\
    \ L = 0) const {\n    return max_right([&k](E x) -> bool { return x <= k; }, L);\n\
    \  }\n};\n#line 8 \"test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n  FOR(i,\
    \ N) read(X[i], Y[i], W[i]);\n  using QQ = tuple<u32, u32, u32, u32>;\n  vc<QQ>\
    \ query(Q);\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      U32(x, y, w);\n\
    \      X.eb(x);\n      Y.eb(y);\n      W.eb(0);\n      query[q] = mt(-1, x, y,\
    \ w);\n    } else {\n      U32(a, b, c, d);\n      query[q] = mt(a, c, b, d);\n\
    \    }\n  }\n\n  Wavelet_Matrix_2D_Range<int, true, true, FenwickTree<Monoid_Add<ll>>>\
    \ WM(\n      len(X), [&](int i) -> tuple<int, int, ll> { return {X[i], Y[i], W[i]};\
    \ });\n  int idx = N;\n  FOR(q, Q) {\n    auto [a, b, c, d] = query[q];\n    if\
    \ (a == u32(-1)) {\n      WM.multiply(idx++, d);\n    } else {\n      print(WM.prod(a,\
    \ b, c, d));\n    }\n  }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"ds/wavelet_matrix/wavelet_matrix_2d_range.hpp\"\
    \n#include \"ds/fenwicktree/fenwicktree.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n\
    \  vc<u32> X(N), Y(N);\n  vc<u64> W(N);\n  FOR(i, N) read(X[i], Y[i], W[i]);\n\
    \  using QQ = tuple<u32, u32, u32, u32>;\n  vc<QQ> query(Q);\n  FOR(q, Q) {\n\
    \    LL(t);\n    if (t == 0) {\n      U32(x, y, w);\n      X.eb(x);\n      Y.eb(y);\n\
    \      W.eb(0);\n      query[q] = mt(-1, x, y, w);\n    } else {\n      U32(a,\
    \ b, c, d);\n      query[q] = mt(a, c, b, d);\n    }\n  }\n\n  Wavelet_Matrix_2D_Range<int,\
    \ true, true, FenwickTree<Monoid_Add<ll>>> WM(\n      len(X), [&](int i) -> tuple<int,\
    \ int, ll> { return {X[i], Y[i], W[i]}; });\n  int idx = N;\n  FOR(q, Q) {\n \
    \   auto [a, b, c, d] = query[q];\n    if (a == u32(-1)) {\n      WM.multiply(idx++,\
    \ d);\n    } else {\n      print(WM.prod(a, b, c, d));\n    }\n  }\n}\n\nsigned\
    \ main() {\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/wavelet_matrix/wavelet_matrix_2d_range.hpp
  - ds/wavelet_matrix/wavelet_matrix.hpp
  - ds/bit_vector.hpp
  - other/bit.hpp
  - ds/dummy_data_structure.hpp
  - alg/monoid/dummy.hpp
  - ds/index_compression.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
  requiredBy: []
  timestamp: '2026-09-01 06:26:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
- /verify/test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp.html
title: test/2_library_checker/data_structure/point_add_rectangle_sum_wm_abel.test.cpp
---
