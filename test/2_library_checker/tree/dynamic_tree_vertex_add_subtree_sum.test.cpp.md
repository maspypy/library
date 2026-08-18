---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/lct_node_commutative_monoid.hpp
    title: graph/ds/lct_node_commutative_monoid.hpp
  - icon: ':heavy_check_mark:'
    path: graph/ds/link_cut_tree.hpp
    title: graph/ds/link_cut_tree.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
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
    void Bob(bool t = 1) { Alice(!t); }\n#line 5 \"test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp\"\
    \n\n#line 1 \"graph/ds/link_cut_tree.hpp\"\n/*\n\u5404 heavy path \u3092 head\
    \ \u304C\u5DE6, tail \u304C\u53F3\u3068\u306A\u308B\u3088\u3046\u306B splay tree\
    \ \u3067\u6301\u3064.\n\u30E6\u30FC\u30B6\u30FC\u304C\u76F4\u63A5\u547C\u3076\u53EF\
    \u80FD\u6027\u304C\u3042\u308B\u3082\u306E\u3060\u3051 int \u3067\u3082\u5B9F\u88C5\
    .\nLCT \u5916\u3067\u63A2\u7D22\u3059\u308B\u3068\u304D\u306A\u3069\uFF0Cpush\
    \ \u3092\u5FD8\u308C\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F.\n*/\n\ntemplate\
    \ <typename Node>\nstruct Link_Cut_Tree {\n  using np = Node *;\n  int n;\n  vc<Node>\
    \ nodes;\n\n  Link_Cut_Tree(int n = 0) : n(n), nodes(n) { FOR(i, n) nodes[i] =\
    \ Node(i); }\n\n  Node *operator[](int v) { return &nodes[v]; }\n\n  // underlying\
    \ tree \u306E\u6839\n  Node *get_root(Node *c) {\n    expose(c);\n    c->push();\n\
    \    while (c->l) {\n      c = c->l;\n      c->push();\n    }\n    splay(c);\n\
    \    return c;\n  }\n\n  // underlying tree \u306E\u6839\n  int get_root(int c)\
    \ { return get_root(&nodes[c])->idx; }\n\n  // parent(c)==p \u3068\u306A\u308B\
    \u3088\u3046\u306B link. p \u306E\u6839\u306F\u5909\u308F\u3089\u306A\u3044.\n\
    \  void link(Node *c, Node *p) {\n    evert(c);\n    expose(p);\n    p->push();\n\
    \    // no edge -> heavy edge\n    assert(!(c->p));\n    assert(!(p->r));\n  \
    \  c->p = p;\n    p->r = c;\n    p->update();\n  }\n\n  // parent(c)==p \u3068\
    \u306A\u308B\u3088\u3046\u306B link. p \u306E\u6839\u306F\u5909\u308F\u3089\u306A\
    \u3044.\n  void link(int c, int p) { return link(&nodes[c], &nodes[p]); }\n\n\
    \  // a,b \u304C\u6839\u306B\u5909\u66F4\u3055\u308C\u308B\n  void cut(Node *a,\
    \ Node *b) {\n    evert(a);\n    expose(b);\n    assert(!b->p);\n    assert((b->l)\
    \ == a);\n    // heavy edge -> no edge\n    b->l->p = nullptr;\n    b->l = nullptr;\n\
    \    b->update();\n  }\n\n  // a,b \u304C\u6839\u306B\u5909\u66F4\u3055\u308C\u308B\
    \n  void cut(int a, int b) { return cut(&nodes[a], &nodes[b]); }\n\n  // c \u3092\
    \ underlying tree \u306E\u6839\u3068\u3059\u308B.\n  // c \u306F splay tree \u306E\
    \u6839\u306B\u3082\u306A\u308B.\n  // c \u306F push \u6E08\u306B\u306A\u308B\n\
    \  void evert(Node *c) {\n    expose(c);\n    c->reverse();\n    c->push();\n\
    \  }\n\n  // c \u3092 underlying tree \u306E\u6839\u3068\u3059\u308B.\n  // c\
    \ \u306F splay tree \u306E\u6839\u306B\u3082\u306A\u308B.\n  void evert(int c)\
    \ { evert(&nodes[c]); }\n\n  // \u6839\u306F\u5909\u3048\u306A\u3044\n  Node *LCA(Node\
    \ *u, Node *v) {\n    assert(get_root(u) == get_root(v));\n    expose(u);\n  \
    \  return expose(v);\n  }\n\n  // \u6839\u306F\u5909\u3048\u306A\u3044\n  int\
    \ LCA(int u, int v) { return LCA(&nodes[u], &nodes[v])->idx; }\n\n  // \u8FBA\u306E\
    \u500B\u6570. \u6839\u3092\u5909\u3048\u308B.\n  int dist(int u, int v) {\n  \
    \  evert(u), expose(v);\n    return ((*this)[v]->size) - 1;\n  }\n\n  // \u6839\
    \u3092\u5909\u3048\u306A\u3044.\n  int depth(int v) {\n    expose(v);\n    return\
    \ ((*this)[v]->size) - 1;\n  }\n\n  // \u6839\u3092\u5909\u3048\u308B.\n  Node\
    \ *jump(Node *u, Node *v, int k) {\n    evert(v);\n    expose(u);\n    assert(0\
    \ <= k && k < (u->size));\n    while (1) {\n      u->push();\n      int rs = (u->r\
    \ ? u->r->size : 0);\n      if (k < rs) {\n        u = u->r;\n        continue;\n\
    \      }\n      if (k == rs) {\n        break;\n      }\n      k -= rs + 1;\n\
    \      u = u->l;\n    }\n    splay(u);\n    return u;\n  }\n\n  // \u6839\u3092\
    \u5909\u3048\u308B.\n  int jump(int u, int v, int k) {\n    auto c = jump((*this)[u],\
    \ (*this)[v], k);\n    return c->idx;\n  }\n\n  // [root, c] \u304C\u3072\u3068\
    \u3064\u306E splay tree \u306B\u306A\u308B\u3088\u3046\u306B\u5909\u66F4\u3059\
    \u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree \u306E\u6839\u3068\u3044\u3046\
    \u72B6\u614B\u306B\u306A\u308B.\n  // path query \u306F\u3053\u306E\u72B6\u614B\
    \u3067 c \u306E data \u3092\u898B\u308B.\n  // c \u306F push \u6E08\u306B\u306A\
    \u308B\n  virtual Node *expose(Node *c) {\n    Node *now = c;\n    Node *rp =\
    \ nullptr;  // \u4ECA\u307E\u3067\u4F5C\u3063\u305F\u30D1\u30B9\n    while (now)\
    \ {\n      splay(now);\n      // heavy -> light, light -> heavy.\n      if (now->r)\
    \ {\n        now->add_light(now->r);\n      }\n      if (rp) {\n        now->erase_light(rp);\n\
    \      }\n      now->r = rp;\n      now->update();\n      rp = now;\n      now\
    \ = now->p;\n    }\n    splay(c);\n    return rp;\n  }\n\n  // [root, c] \u304C\
    \u3072\u3068\u3064\u306E splay tree \u306B\u306A\u308B\u3088\u3046\u306B\u5909\
    \u66F4\u3059\u308B.\n  // c \u304C\u53F3\u7AEF\u3067 splay tree \u306E\u6839\u3068\
    \u3044\u3046\u72B6\u614B\u306B\u306A\u308B.\n  // path query \u306F\u3053\u306E\
    \u72B6\u614B\u3067 c \u306E data \u3092\u898B\u308B.\n  int expose(int c) {\n\
    \    Node *x = expose(&nodes[c]);\n    if (!x) return -1;\n    return x->idx;\n\
    \  }\n\n  // \u6839\u3092\u5909\u3048\u306A\u3044.\n  Node *get_parent(Node *x)\
    \ {\n    expose(x);\n    x->push();\n    if (!x->l) return nullptr;\n    x = x->l,\
    \ x->push();\n    while (x->r) x = x->r, x->push();\n    return x;\n  }\n\n  //\
    \ \u6839\u3092\u5909\u3048\u306A\u3044.\n  int get_parent(int x) {\n    Node *p\
    \ = get_parent((*this)[x]);\n    return (p ? p->idx : -1);\n  }\n\n  // \u6839\
    \u3092\u5909\u3048\u308B.\n  void set(Node *c, typename Node::VX x) {\n    evert(c);\n\
    \    c->set(x);\n  }\n\n  // \u6839\u3092\u5909\u3048\u308B.\n  void set(int c,\
    \ typename Node::VX x) { set((*this)[c], x); }\n\n  // \u6839\u3092\u5909\u3048\
    \u308B.\n  typename Node::X prod_path(int a, int b) {\n    evert(a), expose(b);\n\
    \    return (*this)[b]->x;\n  }\n\n  // \u6839\u3092\u5909\u3048\u308B.\n  //\
    \ subtree \u7528\u306E node \u3092\u4F7F\u3046\n  typename Node::X prod_subtree(int\
    \ v, int root) {\n    static_assert(Node::NODE_FOR_SUBTREE);\n    if (v == root)\
    \ {\n      evert(root);\n      return (*this)[root]->x;\n    }\n    root = jump(v,\
    \ root, 1);\n    cut(v, root);\n    typename Node::X res = (*this)[v]->x;\n  \
    \  link(v, root);\n    return res;\n  }\n\n  vc<int> collect_heavy_path(int v)\
    \ {\n    np c = (*this)[v];\n    while (!is_root(c)) c = c->p;\n    vc<int> res;\n\
    \    auto dfs = [&](auto &dfs, np c, bool rev) -> void {\n      if (!rev) {\n\
    \        if (c->l) dfs(dfs, c->l, rev ^ c->rev);\n        res.eb(c->idx);\n  \
    \      if (c->r) dfs(dfs, c->r, rev ^ c->rev);\n      } else {\n        if (c->r)\
    \ dfs(dfs, c->r, rev ^ c->rev);\n        res.eb(c->idx);\n        if (c->l) dfs(dfs,\
    \ c->l, rev ^ c->rev);\n      }\n    };\n    dfs(dfs, c, false);\n    return res;\n\
    \  }\n\n  void debug() {\n    print(\"p, l, r, rev\");\n    auto f = [&](np c)\
    \ -> int { return (c ? c->idx : -1); };\n    FOR(i, len(nodes)) {\n      print(i,\
    \ \",\", f((*this)[i]->p), f((*this)[i]->l), f((*this)[i]->r),\n            (*this)[i]->rev);\n\
    \    }\n    FOR(i, len(nodes)) {\n      np c = (*this)[i];\n      if (c->l) assert(c->l->p\
    \ == c);\n      if (c->r) assert(c->r->p == c);\n    }\n  }\n\n  void splay(Node\
    \ *c) {\n    c->push();\n    while (!is_root(c)) {\n      Node *p = c->p;\n  \
    \    Node *pp = (p ? p->p : nullptr);\n      if (state(p) == 0) {\n        p->push(),\
    \ c->push();\n        rotate(c);\n      }\n      elif (state(c) == state(p)) {\n\
    \        pp->push(), p->push(), c->push();\n        rotate(p);\n        rotate(c);\n\
    \      }\n      else {\n        pp->push(), p->push(), c->push();\n        rotate(c);\n\
    \        rotate(c);\n      }\n    }\n  }\n\n  // uv path \u4E0A\u3067 prod_path(u,\
    \ x) \u304C check \u3092\u6E80\u305F\u3059\u6700\u5F8C\u306E x, \u306A\u3051\u308C\
    \u3070 \uFF08\u3064\u307E\u308A\n  // path(u,u) \u304C ng \uFF09-1. \u6839\u3092\
    \u5909\u3048\u308B. \u3042\u307E\u308A verify \u3055\u308C\u3066\u306A\u3044\u3088\
    .\n  // https://codeforces.com/contest/1039/submission/320681517\n  // https://codesprintla25.kattis.com/contests/cxeqb3/submissions/17431394\n\
    \  template <class F>\n  int max_path(F check, int u, int v) {\n    evert(u),\
    \ expose(v);\n    Node *c = (*this)[v];\n    using MX = typename Node::MX;\n \
    \   using X = typename MX::value_type;\n    Node *last_ok = nullptr, *last = nullptr;\n\
    \    X lprod = MX::unit();\n    while (c) {\n      last = c;\n      c->push();\n\
    \      X x = (c->l ? MX::op(c->l->x, c->vx) : c->vx);\n      x = MX::op(lprod,\
    \ x);\n      if (!check(x)) {\n        c = c->l;\n      } else {\n        last_ok\
    \ = c, c = c->r, lprod = x;\n      }\n    }\n    splay(last);\n    if (!last_ok)\
    \ return -1;\n    return last_ok->idx;\n  }\n\n private:\n  // splay tree \u5185\
    \u3067\u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy, light \u69CB\u9020\
    \u306F\u5909\u308F\u3089\u306A\u3044.\n  // light pointer \u306F rotate \u5185\
    \u3067\u30B1\u30A2\n  // c \u306F push \u6E08\u306B\u306A\u308B\n\n  // \u30D1\
    \u30B9\u3092\u8868\u3059 splay tree \u306E\u6839\u306B\u306A\u3063\u3066\u3044\
    \u308B\u304B\u3069\u3046\u304B\n  // underlying tree \u3067\u306F\u306A\u3044\n\
    \  bool is_root(Node *c) { return state(c) == 0; }\n\n  // splay tree \u5185\u3067\
    \u5B8C\u7D50\u3059\u308B\u64CD\u4F5C. \u7279\u306B heavy, light \u69CB\u9020\u306F\
    \u5909\u308F\u3089\u306A\u3044.\n  // light edge \u306E\u30DD\u30A4\u30F3\u30BF\
    \u306F\u5909\u66F4\u3055\u308C\u3046\u308B\n  void rotate(Node *n) {\n    // n\
    \ \u3092\u6839\u306B\u8FD1\u3065\u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n\
    \    pp = p->p;\n    if (p->l == n) {\n      c = n->r;\n      n->r = p;\n    \
    \  p->l = c;\n    } else {\n      c = n->l;\n      n->l = p;\n      p->r = c;\n\
    \    }\n    p->update(), n->update();\n\n    if (pp) {\n      if (pp->l == p)\
    \ pp->l = n;\n      elif (pp->r == p) pp->r = n;\n      else {\n        // light\
    \ edge pointer \u304C (pp-p) \u304B\u3089 (pp-n) \u306B\u5909\u308F\u308B\n  \
    \      pp->change_light(p, n);\n      }\n    }\n    n->p = pp;\n    p->p = n;\n\
    \    if (c) c->p = p;\n  }\n\n  inline int state(Node *n) {\n    if (!n->p) return\
    \ 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r == n) return -1;\n    return\
    \ 0;\n  }\n};\n#line 1 \"alg/monoid/add.hpp\"\n\ntemplate <typename E>\nstruct\
    \ Monoid_Add {\n  using X = E;\n  using value_type = X;\n  static constexpr X\
    \ op(const X &x, const X &y) noexcept { return x + y; }\n  static constexpr X\
    \ inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\n  static constexpr X unit() { return\
    \ X(0); }\n  static constexpr bool commute = true;\n};\n#line 1 \"graph/ds/lct_node_commutative_monoid.hpp\"\
    \n\n// SUBTREE : cluster \u304C subtree \u60C5\u5831\u3092\u6301\u3064\u5834\u5408\
    \ntemplate <typename Monoid, bool SUBTREE = false>\nstruct LCT_Node_Commutative_Monoid\
    \ {\n  static_assert(Monoid::commute);\n  static constexpr bool NODE_FOR_SUBTREE\
    \ = SUBTREE;\n  using np = LCT_Node_Commutative_Monoid *;\n  // \u30C7\u30D5\u30A9\
    \u30EB\u30C8\n  np l, r, p;\n  int idx, size; // size \u306F heavy path \u306E\
    \u9802\u70B9\u6570\n  bool rev;\n  // \u76EE\u7684\u3054\u3068\u306B\u5B9A\u7FA9\
    \u3059\u308B.\n  using MX = Monoid;\n  using X = typename MX::value_type;\n  using\
    \ VX = X;\n  X x, vx, mid;\n\n  LCT_Node_Commutative_Monoid(int i = 0)\n     \
    \ : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n        idx(i),\n \
    \       size(1),\n        rev(0),\n        x(MX::unit()),\n        vx(MX::unit()),\n\
    \        mid(MX::unit()) {}\n\n  void update() {\n    size = 1;\n    x = vx;\n\
    \    if constexpr (SUBTREE) x = MX::op(x, mid);\n    if (l) { size += l->size,\
    \ x = Monoid::op(l->x, x); }\n    if (r) { size += r->size, x = Monoid::op(x,\
    \ r->x); }\n  }\n\n  void push() {\n    if (rev) {\n      if (l) l->reverse();\n\
    \      if (r) r->reverse();\n      rev = 0;\n    }\n  }\n\n  // data \u306E reverse\
    \ \u3082\u884C\u3046\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n  }\n\
    \n  // LCT \u5185\u3067 expose, update \u3092\u884C\u3046\u306E\u3067\u3053\u3053\
    \u306F\u5909\u66F4\u3060\u3051\n  void set(VX x) { vx = x; }\n\n  void add_light(np\
    \ c) {\n    if constexpr (SUBTREE) mid = MX::op(mid, c->x);\n  }\n  void erase_light(np\
    \ c) {\n    if constexpr (SUBTREE) mid = MX::op(mid, MX::inverse(c->x));\n  }\n\
    \n  // b->x \u306B subtree value \u304C\u5165\u3063\u3066\u3044\u308B.\n  void\
    \ change_light(np a, np b) {}\n};\n#line 9 \"test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp\"\
    \n\nusing Node = LCT_Node_Commutative_Monoid<Monoid_Add<ll>, true>;\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  Link_Cut_Tree<Node> LCT(N);\n\n  VEC(ll, A, N);\n  FOR(i,\
    \ N) { LCT.set(i, A[i]); }\n  FOR(N - 1) {\n    INT(a, b);\n    LCT.link(a, b);\n\
    \  }\n\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n\
    \      LCT.cut(a, b);\n      LCT.link(c, d);\n    }\n    if (t == 1) {\n     \
    \ LL(i, x);\n      A[i] += x;\n      LCT.set(i, A[i]);\n    }\n    if (t == 2)\
    \ {\n      LL(a, b);\n      print(LCT.prod_subtree(a, b));\n    }\n  }\n}\n\n\
    signed main() {\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"graph/ds/link_cut_tree.hpp\"\
    \n#include \"alg/monoid/add.hpp\"\n#include \"graph/ds/lct_node_commutative_monoid.hpp\"\
    \n\nusing Node = LCT_Node_Commutative_Monoid<Monoid_Add<ll>, true>;\n\nvoid solve()\
    \ {\n  LL(N, Q);\n  Link_Cut_Tree<Node> LCT(N);\n\n  VEC(ll, A, N);\n  FOR(i,\
    \ N) { LCT.set(i, A[i]); }\n  FOR(N - 1) {\n    INT(a, b);\n    LCT.link(a, b);\n\
    \  }\n\n  FOR(q, Q) {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n\
    \      LCT.cut(a, b);\n      LCT.link(c, d);\n    }\n    if (t == 1) {\n     \
    \ LL(i, x);\n      A[i] += x;\n      LCT.set(i, A[i]);\n    }\n    if (t == 2)\
    \ {\n      LL(a, b);\n      print(LCT.prod_subtree(a, b));\n    }\n  }\n}\n\n\
    signed main() {\n  solve();\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - graph/ds/link_cut_tree.hpp
  - alg/monoid/add.hpp
  - graph/ds/lct_node_commutative_monoid.hpp
  isVerificationFile: true
  path: test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2026-08-17 16:42:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp
- /verify/test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp.html
title: test/2_library_checker/tree/dynamic_tree_vertex_add_subtree_sum.test.cpp
---
