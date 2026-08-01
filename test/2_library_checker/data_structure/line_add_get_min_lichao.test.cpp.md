---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/dynamic_lichao.hpp
    title: convex/dynamic_lichao.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#line\
    \ 1 \"my_template.hpp\"\n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n\
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
    template <>\nconstexpr double infty<double> = numeric_limits<double>::infinity();\n\
    template <>\nconstexpr long double infty<long double> =\n    numeric_limits<long\
    \ double>::infinity();\n\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing pq_max = priority_queue<T>;\n\
    template <class T>\nusing pq_min = priority_queue<T, vector<T>, greater<T>>;\n\
    \n#define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
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
    \ ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n  while (llabs(ok\
    \ - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok : ng) = x;\n \
    \ }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F check,\
    \ double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok +\
    \ ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n}\n\n\
    template <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  T c = max<T>(a,\
    \ b);\n  bool changed = (c != a);\n  a = c;\n  return changed;\n}\ntemplate <class\
    \ T, class S>\ninline bool chmin(T &a, const S &b) {\n  T c = min<T>(a, b);\n\
    \  bool changed = (c != a);\n  a = c;\n  return changed;\n}\n\n// ? \u306F -1\n\
    vc<int> s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n\
    \  FOR(i, S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return\
    \ A;\n}\n\ntemplate <typename T, typename U>\nvc<T> cumsum(const vc<U> &A, int\
    \ off = 1) {\n  int N = A.size();\n  vc<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvc<int> argsort(const vc<T> &A) {\n  vc<int> ids(len(A));\n\
    \  iota(all(ids), 0);\n  sort(all(ids),\n       [&](int i, int j) { return (A[i]\
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
    void Bob(bool t = 1) { Alice(!t); }\n#line 1 \"ds/node_pool.hpp\"\n// \u30DE\u30EB\
    \u30C1\u30C6\u30B9\u30C8\u30B1\u30FC\u30B9\u306B\u5F31\u3044\u306E\u3067 static\
    \ \u3067\u78BA\u4FDD\u3059\u308B\u3053\u3068\ntemplate <class Node>\nstruct Node_Pool\
    \ {\n  struct Slot {\n    union alignas(Node) {\n      Slot* next;\n      unsigned\
    \ char storage[sizeof(Node)];\n    };\n  };\n  using np = Node*;\n\n  static constexpr\
    \ int CHUNK_SIZE = 1 << 12;\n\n  vc<unique_ptr<Slot[]>> chunks;\n  Slot* cur =\
    \ nullptr;\n  int cur_used = 0;\n  Slot* free_head = nullptr;\n\n  Node_Pool()\
    \ { alloc_chunk(); }\n\n  template <class... Args>\n  np create(Args&&... args)\
    \ {\n    Slot* s = new_slot();\n    return ::new (s) Node(forward<Args>(args)...);\n\
    \  }\n\n  np clone(const np x) {\n    assert(x);\n    Slot* s = new_slot();\n\
    \    return ::new (s) Node(*x);  // \u30B3\u30D4\u30FC\u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u547C\u3073\u51FA\u3057\n  }\n\n  void destroy(np x) {\n  \
    \  if (!x) return;\n    x->~Node();\n    auto s = reinterpret_cast<Slot*>(x);\n\
    \    s->next = free_head;\n    free_head = s;\n  }\n\n  void reset() {\n    free_head\
    \ = nullptr;\n    if (!chunks.empty()) {\n      cur = chunks[0].get();\n     \
    \ cur_used = 0;\n    }\n  }\n\n private:\n  void alloc_chunk() {\n    chunks.emplace_back(make_unique<Slot[]>(CHUNK_SIZE));\n\
    \    cur = chunks.back().get();\n    cur_used = 0;\n  }\n\n  Slot* new_slot()\
    \ {\n    if (free_head) {\n      Slot* s = free_head;\n      free_head = free_head->next;\n\
    \      return s;\n    }\n    if (cur_used == CHUNK_SIZE) alloc_chunk();\n    return\
    \ &cur[cur_used++];\n  }\n};\n#line 2 \"convex/dynamic_lichao.hpp\"\n\n/*\nstruct\
    \ F {\n  using value_type = ll;  // operator() \u306E\u623B\u308A\u5024\n  int\
    \ a;\n  ll b;\n  ll operator()(ll x) { return a * x + b; }\n};\n*/\n\n// \u76F4\
    \u7DDA\u8FFD\u52A0\u304B\u3064\u975E\u6C38\u7D9A\u306A\u3089\u7A7A\u9593 Q \u3067\
    \u3088\u3044\u3002\n// \u95A2\u6570\u306F ll -> T\u3002[L, R) \u4E0A f \u304C\
    \ overflow \u3057\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F\u3002\n// evaluate\
    \ \u3092\u66F8\u304D\u5909\u3048\u308B\u3068\u3001totally monotone \u306A\u95A2\
    \u6570\u7FA4\u306B\u3082\u4F7F\u3048\u308B\ntemplate <typename FUNC, bool PERSISTENT,\
    \ bool MINIMIZE>\nstruct Dynamic_LiChao_Tree {\n  using T = typename FUNC::value_type;\n\
    \  vc<FUNC> funcs;\n\n  static inline T evaluate(FUNC &f, ll x) { return f(x);\
    \ }\n\n  struct Node {\n    int fid;\n    Node *l, *r;\n  };\n  Node_Pool<Node>\
    \ pool;\n  ll L, R;\n\n  using np = Node *;\n\n  Dynamic_LiChao_Tree(ll L, ll\
    \ R) : L(L), R(R) {}\n\n  void reset() { funcs.clear(), pool.reset(); }\n\n  np\
    \ new_root() { return nullptr; }\n\n  np new_node() {\n    np c = pool.create();\n\
    \    c->fid = -1, c->l = c->r = nullptr;\n    return c;\n  }\n\n  np chmin_line(np\
    \ root, FUNC f) {\n    static_assert(MINIMIZE);\n    int fid = len(funcs);\n \
    \   funcs.eb(f);\n    if (!root) root = new_node();\n    return add_line_rec(root,\
    \ fid, L, R);\n  }\n  np chmax_line(np root, FUNC f) {\n    static_assert(!MINIMIZE);\n\
    \    int fid = len(funcs);\n    funcs.eb(f);\n    if (!root) root = new_node();\n\
    \    return add_line_rec(root, fid, L, R);\n  }\n\n  // [xl, xr)\n  np chmin_segment(np\
    \ root, ll xl, ll xr, FUNC f) {\n    static_assert(MINIMIZE);\n    int fid = len(funcs);\n\
    \    funcs.eb(f);\n    if (!root) root = new_node();\n    return add_segment_rec(root,\
    \ xl, xr, fid, L, R);\n  }\n  // [xl, xr)\n  np chmax_segment(np root, ll xl,\
    \ ll xr, FUNC f) {\n    static_assert(!MINIMIZE);\n    int fid = len(funcs);\n\
    \    funcs.eb(f);\n    if (!root) root = new_node();\n    return add_segment_rec(root,\
    \ xl, xr, fid, L, R);\n  }\n\n  // (\u5024\u30FB\u95A2\u6570\u756A\u53F7)\n  pair<T,\
    \ int> query(np root, ll x) {\n    assert(L <= x && x < R);\n    if (!root) {\n\
    \      if (MINIMIZE) return {infty<T>, -1};\n      if (!MINIMIZE) return {-infty<T>,\
    \ -1};\n    }\n    return query_rec(root, x, L, R);\n  }\n\n private:\n  np clone(np\
    \ c) {\n    if (!c || !PERSISTENT) return c;\n    return pool.clone(c);\n  }\n\
    \n  inline T evaluate_inner(int fid, ll x) {\n    if (fid == -1) {\n      return\
    \ (MINIMIZE ? infty<T> : -infty<T>);\n    };\n    return evaluate(funcs[fid],\
    \ x);\n  }\n\n  np add_segment_rec(np c, ll xl, ll xr, int fid, ll node_l, ll\
    \ node_r) {\n    chmax(xl, node_l), chmin(xr, node_r);\n    if (xl >= xr) return\
    \ c;\n    if (node_l < xl || xr < node_r) {\n      c = clone(c);\n      ll node_m\
    \ = (node_l + node_r) / 2;\n      if (!c->l) c->l = new_node();\n      if (!c->r)\
    \ c->r = new_node();\n      c->l = add_segment_rec(c->l, xl, xr, fid, node_l,\
    \ node_m);\n      c->r = add_segment_rec(c->r, xl, xr, fid, node_m, node_r);\n\
    \      return c;\n    }\n    return add_line_rec(c, fid, node_l, node_r);\n  }\n\
    \n  np add_line_rec(np c, int fid, ll node_l, ll node_r) {\n    int gid = c->fid;\n\
    \    T fl = evaluate_inner(fid, node_l), fr = evaluate_inner(fid, node_r - 1);\n\
    \    T gl = evaluate_inner(gid, node_l), gr = evaluate_inner(gid, node_r - 1);\n\
    \    bool bl = (MINIMIZE ? fl < gl : gl < fl);\n    bool br = (MINIMIZE ? fr <\
    \ gr : gr < fr);\n    if (bl && br) {\n      c = clone(c);\n      c->fid = fid;\n\
    \      return c;\n    }\n    if (!bl && !br) {\n      return c;\n    }\n\n   \
    \ c = clone(c);\n    ll node_m = (node_l + node_r) / 2;\n    auto fm = evaluate_inner(fid,\
    \ node_m), gm = evaluate_inner(gid, node_m);\n    bool bm = (MINIMIZE ? fm < gm\
    \ : gm < fm);\n    if (bm) {\n      c->fid = fid;\n      if (bl) {\n        if\
    \ (!c->r) c->r = new_node();\n        c->r = add_line_rec(c->r, gid, node_m, node_r);\n\
    \      } else {\n        if (!c->l) c->l = new_node();\n        c->l = add_line_rec(c->l,\
    \ gid, node_l, node_m);\n      }\n    }\n    if (!bm) {\n      if (!bl) {\n  \
    \      if (!c->r) c->r = new_node();\n        c->r = add_line_rec(c->r, fid, node_m,\
    \ node_r);\n      } else {\n        if (!c->l) c->l = new_node();\n        c->l\
    \ = add_line_rec(c->l, fid, node_l, node_m);\n      }\n    }\n    return c;\n\
    \  }\n\n  pair<T, int> query_rec(np c, ll x, ll node_l, ll node_r) {\n    int\
    \ fid = c->fid;\n    pair<T, int> res = {evaluate_inner(fid, x), fid};\n    ll\
    \ node_m = (node_l + node_r) / 2;\n    if (x < node_m && c->l) {\n      pair<T,\
    \ int> res1 = query_rec(c->l, x, node_l, node_m);\n      res = (MINIMIZE ? min(res,\
    \ res1) : max(res, res1));\n    }\n    if (x >= node_m && c->r) {\n      pair<T,\
    \ int> res1 = query_rec(c->r, x, node_m, node_r);\n      res = (MINIMIZE ? min(res,\
    \ res1) : max(res, res1));\n    }\n    return res;\n  }\n};\n#line 5 \"test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp\"\
    \n\nstruct F {\n  using value_type = ll;  // operator() \u306E\u623B\u308A\u5024\
    \n  int a;\n  ll b;\n  ll operator()(ll x) { return a * x + b; }\n};\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  const int LIM = 1'000'000'000;\n  Dynamic_LiChao_Tree<F, 0,\
    \ 1> X(-LIM, LIM + 1);\n  using np = decltype(X)::np;\n  np root = X.new_root();\n\
    \  FOR(N) {\n    LL(a, b);\n    root = X.chmin_line(root, {int(a), b});\n  }\n\
    \  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n      LL(a, b);\n      root = X.chmin_line(root,\
    \ {int(a), b});\n    }\n    if (t == 1) {\n      INT(x);\n      print(X.query(root,\
    \ x).fi);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"convex/dynamic_lichao.hpp\"\
    \n\nstruct F {\n  using value_type = ll;  // operator() \u306E\u623B\u308A\u5024\
    \n  int a;\n  ll b;\n  ll operator()(ll x) { return a * x + b; }\n};\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  const int LIM = 1'000'000'000;\n  Dynamic_LiChao_Tree<F, 0,\
    \ 1> X(-LIM, LIM + 1);\n  using np = decltype(X)::np;\n  np root = X.new_root();\n\
    \  FOR(N) {\n    LL(a, b);\n    root = X.chmin_line(root, {int(a), b});\n  }\n\
    \  FOR(Q) {\n    INT(t);\n    if (t == 0) {\n      LL(a, b);\n      root = X.chmin_line(root,\
    \ {int(a), b});\n    }\n    if (t == 1) {\n      INT(x);\n      print(X.query(root,\
    \ x).fi);\n    }\n  }\n}\n\nsigned main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - convex/dynamic_lichao.hpp
  - ds/node_pool.hpp
  isVerificationFile: true
  path: test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp
  requiredBy: []
  timestamp: '2026-08-01 03:11:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp
- /verify/test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp.html
title: test/2_library_checker/data_structure/line_add_get_min_lichao.test.cpp
---
