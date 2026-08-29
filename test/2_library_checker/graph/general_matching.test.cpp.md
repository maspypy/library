---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/hashmap.hpp
    title: ds/hashmap.hpp
  - icon: ':x:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':x:'
    path: graph/maximum_matching.hpp
    title: graph/maximum_matching.hpp
  - icon: ':x:'
    path: graph/maximum_matching_size.hpp
    title: graph/maximum_matching_size.hpp
  - icon: ':x:'
    path: linalg/matrix_rank.hpp
    title: linalg/matrix_rank.hpp
  - icon: ':x:'
    path: mod/modint61.hpp
    title: mod/modint61.hpp
  - icon: ':x:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':x:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/general_matching
    links:
    - https://judge.yosupo.jp/problem/general_matching
  bundledCode: "#line 1 \"test/2_library_checker/graph/general_matching.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#line\
    \ 1 \"my_template.hpp\"\n#if defined(USE_PCH)\n#include <my_template_compiled.hpp>\n\
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
    \  return a;\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok, ll\
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (1)\
    \ {\n    ll x = (ok + ng) / 2;\n    if (x == ok || x == ng) break;\n    (check(x)\
    \ ? ok : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c\
    \ = max<T>(a, b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\
    template <class T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F\
    \ -1\nvc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return\
    \ A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n      [&](int i, int j) { return (A[i]\
    \ == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &...others) {\n  first.reserve(first.size() + (others.size() + ... + 0));\n\
    \  (first.insert(first.end(), others.begin(), others.end()), ...);\n}\n\n// i128\n\
    template <class T, enable_if_t<is_same_v<T, i128>, int> = 0>\nconstexpr i128 abs(T\
    \ x) {\n  return x < 0 ? -x : x;\n}\n\nconstexpr i128 gcd(i128 a, i128 b) {\n\
    \  while (b != 0) {\n    i128 c = a % b;\n    a = b, b = c;\n  }\n  return abs(a);\n\
    }\n#endif\n#line 1 \"other/io.hpp\"\n#define FASTIO\r\n\r\n// https://judge.yosupo.jp/submission/21623\r\
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
    void Bob(bool t = 1) { Alice(!t); }\n#line 4 \"test/2_library_checker/graph/general_matching.test.cpp\"\
    \n\n#line 1 \"ds/hashmap.hpp\"\n\n// u64 -> Val\ntemplate <typename Val>\nstruct\
    \ HashMap {\n  // n \u306F\u5165\u308C\u305F\u3044\u3082\u306E\u306E\u500B\u6570\
    \u3067 ok\n  HashMap(u32 n = 0) { build(n); }\n  void build(u32 n) {\n    u32\
    \ k = 8;\n    while (k < n * 2) k *= 2;\n    cap = k / 2, mask = k - 1;\n    key.resize(k),\
    \ val.resize(k), used.assign(k, 0);\n  }\n\n  // size \u3092\u4FDD\u3063\u305F\
    \u307E\u307E. size=0 \u306B\u3059\u308B\u3068\u304D\u306F build \u3059\u308B\u3053\
    \u3068.\n  void clear() {\n    used.assign(len(used), 0);\n    cap = (mask + 1)\
    \ / 2;\n  }\n  int size() { return len(used) / 2 - cap; }\n\n  int index(const\
    \ u64& k) {\n    int i = 0;\n    for (i = hash(k); used[i] && key[i] != k; i =\
    \ (i + 1) & mask) {}\n    return i;\n  }\n\n  Val& operator[](const u64& k) {\n\
    \    if (cap == 0) extend();\n    int i = index(k);\n    if (!used[i]) { used[i]\
    \ = 1, key[i] = k, val[i] = Val{}, --cap; }\n    return val[i];\n  }\n\n  Val\
    \ get(const u64& k, Val default_value) {\n    int i = index(k);\n    return (used[i]\
    \ ? val[i] : default_value);\n  }\n\n  bool count(const u64& k) {\n    int i =\
    \ index(k);\n    return used[i] && key[i] == k;\n  }\n\n  // f(key, val)\n  template\
    \ <typename F>\n  void enumerate_all(F f) {\n    FOR(i, len(used)) if (used[i])\
    \ f(key[i], val[i]);\n  }\n\nprivate:\n  u32 cap, mask;\n  vc<u64> key;\n  vc<Val>\
    \ val;\n  vc<bool> used;\n\n  u64 hash(u64 x) {\n    static const u64 FIXED_RANDOM\
    \ = std::chrono::steady_clock::now().time_since_epoch().count();\n    x += FIXED_RANDOM;\n\
    \    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;\n    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;\n\
    \    return (x ^ (x >> 31)) & mask;\n  }\n\n  void extend() {\n    vc<pair<u64,\
    \ Val>> dat;\n    dat.reserve(len(used) / 2 - cap);\n    FOR(i, len(used)) {\n\
    \      if (used[i]) dat.eb(key[i], val[i]);\n    }\n    build(2 * len(dat));\n\
    \    for (auto& [a, b]: dat) (*this)[a] = b;\n  }\n};\n#line 2 \"graph/base.hpp\"\
    \n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n  T cost;\n  int id;\n\
    };\n\ntemplate <typename T = int, bool directed = false>\nstruct Graph {\n  static\
    \ constexpr bool is_directed = directed;\n  int N, M;\n  using cost_type = T;\n\
    \  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n  vector<int> indptr;\n\
    \  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg, vc_outdeg;\n  HashMap<int>\
    \ MP_FOR_EID;\n  bool prepared;\n\n  class OutgoingEdges {\n   public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) {\n        return 0;\n      }\n      return &G->csr_edges[l];\n\
    \    }\n\n    const edge_type* end() const {\n      if (l == r) {\n        return\
    \ 0;\n      }\n      return &G->csr_edges[r];\n    }\n\n   private:\n    const\
    \ Graph* G;\n    int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\
    \n  Graph() : N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0)\
    \ {}\n\n  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n    MP_FOR_EID.clear();\n  }\n\n  void add(int frm, int\
    \ to, T cost = 1, int i = -1) {\n    assert(!prepared);\n    assert(0 <= frm &&\
    \ frm < N && 0 <= to && to < N);\n    if (i == -1) i = M;\n    auto e = edge_type({frm,\
    \ to, cost, i});\n    edges.eb(e);\n    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n\
    \  void read_tree(bool wt = false, int off = 1) { read_graph(N - 1, wt, off);\
    \ }\n\n  void read_graph(int M, bool wt = false, int off = 1) {\n    for (int\
    \ m = 0; m < M; ++m) {\n      INT(a, b);\n      a -= off, b -= off;\n      if\
    \ (!wt) {\n        add(a, b);\n      } else {\n        T c;\n        read(c);\n\
    \        add(a, b, c);\n      }\n    }\n    build();\n  }\n#endif\n\n  void build()\
    \ {\n    assert(!prepared);\n    prepared = true;\n    indptr.assign(N + 1, 0);\n\
    \    for (auto&& e : edges) {\n      indptr[e.frm + 1]++;\n      if (!directed)\
    \ indptr[e.to + 1]++;\n    }\n    for (int v = 0; v < N; ++v) {\n      indptr[v\
    \ + 1] += indptr[v];\n    }\n    auto counter = indptr;\n    csr_edges.resize(indptr.back()\
    \ + 1);\n    for (auto&& e : edges) {\n      csr_edges[counter[e.frm]++] = e;\n\
    \      if (!directed)\n        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm,\
    \ e.cost, e.id});\n    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n \
    \   assert(prepared);\n    return {this, indptr[v], indptr[v + 1]};\n  }\n\n \
    \ vc<int> deg_array() {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n\
    \  }\n\n  pair<vc<int>, vc<int>> deg_array_inout() {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v)\
    \ {\n    if (vc_deg.empty()) calc_deg();\n    return vc_deg[v];\n  }\n\n  int\
    \ in_deg(int v) {\n    if (vc_indeg.empty()) calc_deg_inout();\n    return vc_indeg[v];\n\
    \  }\n\n  int out_deg(int v) {\n    if (vc_outdeg.empty()) calc_deg_inout();\n\
    \    return vc_outdeg[v];\n  }\n\n#ifdef FASTIO\n  void debug() {\n#ifdef LOCAL\n\
    \    print(\"Graph\");\n    if (!prepared) {\n      print(\"frm to cost id\");\n\
    \      for (auto&& e : edges) print(e.frm, e.to, e.cost, e.id);\n    } else {\n\
    \      print(\"indptr\", indptr);\n      print(\"frm to cost id\");\n      FOR(v,\
    \ N) for (auto&& e : (*this)[v]) print(e.frm, e.to, e.cost, e.id);\n    }\n  \
    \  flush();\n#endif\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\n\
    \  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e : (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid : history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e : (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e : edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\n  int get_eid(u64 a, u64 b) {\n\
    \    if (len(MP_FOR_EID) == 0) {\n      MP_FOR_EID.build(N - 1);\n      for (auto&\
    \ e : edges) {\n        u64 a = e.frm, b = e.to;\n        u64 k = to_eid_key(a,\
    \ b);\n        MP_FOR_EID[k] = e.id;\n      }\n    }\n    return MP_FOR_EID.get(to_eid_key(a,\
    \ b), -1);\n  }\n\n  u64 to_eid_key(u64 a, u64 b) {\n    if (!directed && a >\
    \ b) swap(a, b);\n    return N * a + b;\n  }\n\n private:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e : edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e : edges)\
    \ {\n      vc_indeg[e.to]++, vc_outdeg[e.frm]++;\n    }\n  }\n};\n#line 2 \"graph/maximum_matching.hpp\"\
    \n\n// return : (match size, match)\n// match[v] : \u30DE\u30C3\u30C1\u30F3\u30B0\
    \u76F8\u624B OR 0\n// O(N^3)\n// \u300C\u7D44\u5408\u305B\u6700\u9069\u5316\u300D\
    \u7B2C2\u7248, \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 10.2\ntemplate <typename GT>\n\
    pair<int, vc<int>> maximum_matching(const GT& G) {\n  const int N = G.N;\n  vc<int>\
    \ mu(N), phi(N), rho(N);\n  vc<bool> scanned(N);\n  FOR(v, N) mu[v] = v;\n  ll\
    \ ans = 0;\n  for (auto&& e: G.edges) {\n    if (e.frm != e.to && mu[e.frm] ==\
    \ e.frm && mu[e.to] == e.to) {\n      mu[e.frm] = e.to, mu[e.to] = e.frm, ++ans;\n\
    \    }\n  }\n\n  auto odd = [&](int x) -> bool {\n    return mu[x] != x && phi[mu[x]]\
    \ == mu[x] && mu[x] != x;\n  };\n  auto out_of_forest = [&](int x) -> bool {\n\
    \    return mu[x] != x && phi[mu[x]] == mu[x] && phi[x] == x;\n  };\n  auto P\
    \ = [&](int x) -> vc<int> {\n    vc<int> P;\n    P.eb(x);\n    while (mu[x] !=\
    \ x) {\n      P.eb(mu[x]);\n      P.eb(phi[mu[x]]);\n      x = phi[mu[x]];\n \
    \   }\n    return P;\n  };\n\n  vc<bool> on_path(N);\n  while (1) {\n    FOR(v,\
    \ N) phi[v] = rho[v] = v, scanned[v] = 0;\n    bool aug = 0;\n    while (1) {\n\
    \      bool upd = 0;\n      FOR(x, N) {\n        if (upd) break;\n        if (scanned[x]\
    \ || odd(x)) continue;\n        for (auto&& e: G[x]) {\n          int y = e.to;\n\
    \          if (out_of_forest(y)) {\n            upd = 1;\n            // grow\n\
    \            phi[y] = x;\n          }\n          elif (rho[y] != rho[x] && !odd(y))\
    \ {\n            vc<int> F;\n            FOR(v, N) if (!out_of_forest(v)) F.eb(v);\n\
    \            upd = 1;\n            // augument OR shrink\n            vc<int>\
    \ Px = P(x);\n            vc<int> Py = P(y);\n            if (Px.back() != Py.back())\
    \ {\n              aug = 1;\n              // augument\n              FOR(2) {\n\
    \                swap(Px, Py);\n                for (int i = 1; i < len(Px); i\
    \ += 2) {\n                  int v = Px[i];\n                  mu[phi[v]] = v,\
    \ mu[v] = phi[v];\n                }\n              }\n              mu[x] = y,\
    \ mu[y] = x, ++ans;\n              break;\n            } else {\n            \
    \  // shrink\n              int r = -1;\n              int Nx = len(Px), Ny =\
    \ len(Py);\n              for (int i = 0; i < Nx; i += 2) {\n                int\
    \ v = Px[i];\n                int j = i + Ny - Nx;\n                if (0 <= j\
    \ && j < Ny && Py[j] == v && rho[v] == v) {\n                  r = v;\n      \
    \            break;\n                }\n              }\n              while (Px.back()\
    \ != r) Px.pop_back();\n              while (Py.back() != r) Py.pop_back();\n\
    \              vc<int> change;\n              FOR(2) {\n                swap(Px,\
    \ Py);\n                for (int i = 1; i < len(Px); i += 2) {\n             \
    \     int v = Px[i];\n                  if (rho[phi[v]] != r) change.eb(v);\n\
    \                }\n              }\n              for (auto&& v: change) phi[phi[v]]\
    \ = v;\n\n              if (rho[x] != r) phi[x] = y;\n              if (rho[y]\
    \ != r) phi[y] = x;\n              for (auto&& v: Px) on_path[v] = 1;\n      \
    \        for (auto&& v: Py) on_path[v] = 1;\n              FOR(v, N) if (on_path[rho[v]])\
    \ { rho[v] = r; }\n              fill(all(on_path), 0);\n            }\n     \
    \     }\n        }\n        scanned[x] = 1;\n      }\n      if (!upd || aug) break;\n\
    \    }\n    if (!aug) break;\n  }\n  FOR(v, N) if (mu[v] == v) mu[v] = -1;\n \
    \ return {ans, mu};\n}\n#line 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static\
    \ u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 1 \"mod/modint61.hpp\"\n\nstruct modint61 {\n \
    \ static constexpr u64 mod = (1ULL << 61) - 1;\n  u64 val;\n  constexpr modint61()\
    \ : val(0ULL) {}\n  constexpr modint61(u32 x) : val(x) {}\n  constexpr modint61(u64\
    \ x) : val(x % mod) {}\n  constexpr modint61(int x) : val((x < 0) ? (x + static_cast<ll>(mod))\
    \ : x) {}\n  constexpr modint61(ll x) : val(((x %= static_cast<ll>(mod)) < 0)\
    \ ? (x + static_cast<ll>(mod)) : x) {}\n  static constexpr u64 get_mod() { return\
    \ mod; }\n\n  modint61 &operator+=(const modint61 &a) {\n    val = ((val += a.val)\
    \ >= mod) ? (val - mod) : val;\n    return *this;\n  }\n  modint61 &operator-=(const\
    \ modint61 &a) {\n    val = ((val -= a.val) >= mod) ? (val + mod) : val;\n   \
    \ return *this;\n  }\n  modint61 &operator*=(const modint61 &a) {\n    const unsigned\
    \ __int128 y = static_cast<unsigned __int128>(val) * a.val;\n    val = (y >> 61)\
    \ + (y & mod);\n    val = (val >= mod) ? (val - mod) : val;\n    return *this;\n\
    \  }\n  modint61 operator-() const { return modint61(val ? mod - val : u64(0));\
    \ }\n  modint61 &operator/=(const modint61 &a) { return (*this *= a.inverse());\
    \ }\n  modint61 operator+(const modint61 &p) const { return modint61(*this) +=\
    \ p; }\n  modint61 operator-(const modint61 &p) const { return modint61(*this)\
    \ -= p; }\n  modint61 operator*(const modint61 &p) const { return modint61(*this)\
    \ *= p; }\n  modint61 operator/(const modint61 &p) const { return modint61(*this)\
    \ /= p; }\n  bool operator<(const modint61 &other) const { return val < other.val;\
    \ }\n  bool operator==(const modint61 &p) const { return val == p.val; }\n  bool\
    \ operator!=(const modint61 &p) const { return val != p.val; }\n  modint61 inverse()\
    \ const {\n    ll a = val, b = mod, u = 1, v = 0, t;\n    while (b > 0) {\n  \
    \    t = a / b;\n      swap(a -= t * b, b), swap(u -= t * v, v);\n    }\n    return\
    \ modint61(u);\n  }\n  modint61 pow(ll n) const {\n    assert(n >= 0);\n    modint61\
    \ ret(1), mul(val);\n    while (n > 0) {\n      if (n & 1) ret *= mul;\n     \
    \ mul *= mul, n >>= 1;\n    }\n    return ret;\n  }\n};\n\n#ifdef FASTIO\nvoid\
    \ rd(modint61 &x) {\n  fastio::rd(x.val);\n  assert(0 <= x.val && x.val < modint61::mod);\n\
    }\n\nvoid wt(modint61 x) { fastio::wt(x.val); }\n#endif\n#line 1 \"linalg/matrix_rank.hpp\"\
    \ntemplate <typename T>\nint matrix_rank(vc<vc<T>> a, int n = -1, int m = -1)\
    \ {\n  if (n == 0) return 0;\n  if (n == -1) { n = len(a), m = len(a[0]); }\n\
    \  assert(n == len(a) && m == len(a[0]));\n  int rk = 0;\n  FOR(j, m) {\n    if\
    \ (rk == n) break;\n    if (a[rk][j] == 0) {\n      FOR(i, rk + 1, n) if (a[i][j]\
    \ != T(0)) {\n        swap(a[rk], a[i]);\n        break;\n      }\n    }\n   \
    \ if (a[rk][j] == 0) continue;\n    T c = T(1) / a[rk][j];\n    FOR(k, j, m) a[rk][k]\
    \ *= c;\n    FOR(i, rk + 1, n) {\n      T c = a[i][j];\n      FOR3(k, j, m) {\
    \ a[i][k] -= a[rk][k] * c; }\n    }\n    ++rk;\n  }\n  return rk;\n}\n#line 4\
    \ \"graph/maximum_matching_size.hpp\"\n\ntemplate <typename GT>\nint maximum_matching_size(GT&\
    \ G) {\n  static_assert(!GT::is_directed);\n  using mint = modint61;\n  int N\
    \ = G.N;\n  vv(mint, tutte, N, N);\n  for (auto&& e: G.edges) {\n    mint x =\
    \ RNG(mint::get_mod());\n    int i = e.frm, j = e.to;\n    tutte[i][j] += x;\n\
    \    tutte[j][i] -= x;\n  }\n  return matrix_rank(tutte, N, N) / 2;\n}\n#line\
    \ 7 \"test/2_library_checker/graph/general_matching.test.cpp\"\n\nvoid solve()\
    \ {\n  LL(N, M);\n  Graph<int, 0> G(N);\n  G.read_graph(M, 0, 0);\n\n  auto [ans,\
    \ mu] = maximum_matching(G);\n\n  vc<pair<int, int>> ANS;\n  FOR(v, N) if (v <\
    \ mu[v]) ANS.eb(v, mu[v]);\n  print(ans);\n  for (auto&& x: ANS) print(x);\n \
    \ assert(ans == maximum_matching_size(G));\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/general_matching\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/maximum_matching.hpp\"\
    \n#include \"graph/maximum_matching_size.hpp\"\n\nvoid solve() {\n  LL(N, M);\n\
    \  Graph<int, 0> G(N);\n  G.read_graph(M, 0, 0);\n\n  auto [ans, mu] = maximum_matching(G);\n\
    \n  vc<pair<int, int>> ANS;\n  FOR(v, N) if (v < mu[v]) ANS.eb(v, mu[v]);\n  print(ans);\n\
    \  for (auto&& x: ANS) print(x);\n  assert(ans == maximum_matching_size(G));\n\
    }\n\nsigned main() {\n  solve();\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/maximum_matching.hpp
  - graph/base.hpp
  - ds/hashmap.hpp
  - graph/maximum_matching_size.hpp
  - random/base.hpp
  - mod/modint61.hpp
  - linalg/matrix_rank.hpp
  isVerificationFile: true
  path: test/2_library_checker/graph/general_matching.test.cpp
  requiredBy: []
  timestamp: '2026-08-29 08:55:51+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/2_library_checker/graph/general_matching.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/graph/general_matching.test.cpp
- /verify/test/2_library_checker/graph/general_matching.test.cpp.html
title: test/2_library_checker/graph/general_matching.test.cpp
---
