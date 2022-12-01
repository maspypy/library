---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/mincostflow.hpp
    title: flow/mincostflow.hpp
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
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B
  bundledCode: "#line 1 \"test/aoj/GRL_6_B.test.cpp\"\n#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#line 1 \"my_template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC\
    \ optimize(\"unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing\
    \ u32 = unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\
    \ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
    template <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc\
    \ = vector<vvvc<T>>;\ntemplate <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate\
    \ <class T>\nusing pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T,\
    \ vector<T>, greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
    #define vv(type, name, h, ...) \\\n  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...)   \\\n  vector<vector<vector<type>>> name(\
    \ \\\n      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...)       \\\n  vector<vector<vector<vector<type>>>> name( \\\
    \n      a, vector<vector<vector<type>>>(       \\\n             b, vector<vector<type>>(c,\
    \ vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n#define FOR1(a)\
    \ for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i = 0; i < ll(a);\
    \ ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define FOR4(i,\
    \ a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for (ll i =\
    \ (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >= ll(0);\
    \ --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define FOR4_R(i,\
    \ a, b, c) for (ll i = (b)-1; i >= ll(a); i -= (c))\n#define overload4(a, b, c,\
    \ d, e, ...) e\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) \\\n  overload4(__VA_ARGS__, FOR4_R, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) &\
    \ s))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\ntemplate <typename\
    \ T, typename U>\nT SUM(const vector<U> &A) {\n  T sum = 0;\n  for (auto &&a:\
    \ A) sum += a;\n  return sum;\n}\n\n#define MIN(v) *min_element(all(v))\n#define\
    \ MAX(v) *max_element(all(v))\n#define LB(c, x) distance((c).begin(), lower_bound(all(c),\
    \ (x)))\n#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))\n#define\
    \ UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\n\
    int topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32\
    \ x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return\
    \ (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64 x) { return (x ==\
    \ 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\n\
    int lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(u32\
    \ x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll x) { return (x\
    \ == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return (x == 0 ? -1\
    \ : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT pick(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\n\ntemplate <typename\
    \ T>\nT pick(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    \ntemplate <typename T>\nT pick(pqg<T> &que) {\n  assert(que.size());\n  T a =\
    \ que.top();\n  que.pop();\n  return a;\n}\n\ntemplate <typename T>\nT pick(vc<T>\
    \ &que) {\n  assert(que.size());\n  T a = que.back();\n  que.pop_back();\n  return\
    \ a;\n}\n\ntemplate <typename T, typename U>\nT ceil(T x, U y) {\n  return (x\
    \ > 0 ? (x + y - 1) / y : x / y);\n}\n\ntemplate <typename T, typename U>\nT floor(T\
    \ x, U y) {\n  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <typename\
    \ T, typename U>\npair<T, T> divmod(T x, U y) {\n  T q = floor(x, y);\n  return\
    \ {q, x - q * y};\n}\n\ntemplate <typename F>\nll binary_search(F check, ll ok,\
    \ ll ng) {\n  assert(check(ok));\n  while (abs(ok - ng) > 1) {\n    auto x = (ng\
    \ + ok) / 2;\n    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return\
    \ ok;\n}\n\ntemplate <typename F>\ndouble binary_search_real(F check, double ok,\
    \ double ng, int iter = 100) {\n  FOR(iter) {\n    double x = (ok + ng) / 2;\n\
    \    tie(ok, ng) = (check(x) ? mp(x, ng) : mp(ok, x));\n  }\n  return (ok + ng)\
    \ / 2;\n}\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b)\
    \ {\n  return (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline\
    \ bool chmin(T &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = S[i] - first_char; }\n  return A;\n}\n\ntemplate <typename\
    \ T, typename U>\nvector<T> cumsum(vector<U> &A, int off = 1) {\n  int N = A.size();\n\
    \  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] = B[i] + A[i]; }\n  if (off ==\
    \ 0) B.erase(B.begin());\n  return B;\n}\n\ntemplate <typename CNT, typename T>\n\
    vc<CNT> bincount(const vc<T> &A, int size) {\n  vc<CNT> C(size);\n  for (auto\
    \ &&x: A) { ++C[x]; }\n  return C;\n}\n\n// stable\ntemplate <typename T>\nvector<int>\
    \ argsort(const vector<T> &A) {\n  vector<int> ids(A.size());\n  iota(all(ids),\
    \ 0);\n  sort(all(ids),\n       [&](int i, int j) { return A[i] < A[j] || (A[i]\
    \ == A[j] && i < j); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]], ...\ntemplate\
    \ <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I) {\n  int n =\
    \ len(I);\n  vc<T> B(n);\n  FOR(i, n) B[i] = A[I[i]];\n  return B;\n}\n#line 1\
    \ \"other/io.hpp\"\nnamespace fastio {\r\n// https://nyaannyaan.github.io/library/misc/fastio.hpp\
    \ \u3092\u5143\u306B\u6539\u9020\r\n\r\n// \u30AF\u30E9\u30B9\u304C read(), print()\
    \ \u3092\u6301\u3063\u3066\u3044\u308B\u304B\u3092\u5224\u5B9A\u3059\u308B\u30E1\
    \u30BF\u95A2\u6570\r\nstruct has_write_impl {\r\n  template <class T>\r\n  static\
    \ auto check(T &&x) -> decltype(x.write(), std::true_type{});\r\n\r\n  template\
    \ <class T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate\
    \ <class T>\r\nclass has_write : public decltype(has_write_impl::check<T>(std::declval<T>()))\
    \ {\r\n};\r\n\r\nstruct has_read_impl {\r\n  template <class T>\r\n  static auto\
    \ check(T &&x) -> decltype(x.read(), std::true_type{});\r\n\r\n  template <class\
    \ T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate <class\
    \ T>\r\nclass has_read : public decltype(has_read_impl::check<T>(std::declval<T>()))\
    \ {};\r\n\r\nstatic constexpr int SZ = 1 << 17;\r\nchar inbuf[SZ], outbuf[SZ];\r\
    \nint in_left = 0, in_right = 0, out_right = 0;\r\n\r\nstruct Pre {\r\n  char\
    \ num[40000];\r\n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000;\
    \ i++) {\r\n      int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n     \
    \   num[i * 4 + j] = n % 10 + '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n\
    \  }\r\n} constexpr pre;\r\n\r\ninline void load() {\r\n  int len = in_right -\
    \ in_left;\r\n  memmove(inbuf, inbuf + in_left, len);\r\n  in_right = len + fread(inbuf\
    \ + len, 1, SZ - len, stdin);\r\n  in_left = 0;\r\n}\r\n\r\ninline void flush()\
    \ {\r\n  fwrite(outbuf, 1, out_right, stdout);\r\n  out_right = 0;\r\n}\r\n\r\n\
    inline void read_single(char &c) {\r\n  if (in_left + 32 > in_right) load();\r\
    \n  c = inbuf[in_left++];\r\n}\r\n\r\ntemplate <class T, enable_if_t<is_same<T,\
    \ string>::value, int> = 0>\r\ninline void read_single(T &x) {\r\n  char c = '\
    \ ';\r\n  do {\r\n    if (in_left + 32 > in_right) load();\r\n    c = inbuf[in_left++];\r\
    \n  } while (c == ' ' || c == '\\n');\r\n  x += c;\r\n  while (1) {\r\n    if\
    \ (in_left + 32 > in_right) load();\r\n    c = inbuf[in_left++];\r\n    if (c\
    \ == ' ' || c == '\\n') break;\r\n    x += c;\r\n  }\r\n}\r\n\r\ntemplate <class\
    \ T, enable_if_t<is_integral<T>::value, int> = 0>\r\ninline void read_single(T\
    \ &x) {\r\n  if (in_left + 32 > in_right) load();\r\n  char c;\r\n  do\r\n   \
    \ c = inbuf[in_left++];\r\n  while (c < '-');\r\n  bool minus = false;\r\n  if\
    \ constexpr (is_signed<T>::value == true) {\r\n    if (c == '-') minus = true,\
    \ c = inbuf[in_left++];\r\n  }\r\n  x = 0;\r\n  while (c >= '0') {\r\n    x =\
    \ x * 10 + (c & 15);\r\n    c = inbuf[in_left++];\r\n  }\r\n  if constexpr (is_signed<T>::value\
    \ == true) {\r\n    if (minus) x = -x;\r\n  }\r\n}\r\n\r\ntemplate <typename T,\
    \ typename enable_if<has_read<T>::value>::type * = nullptr>\r\ninline void read_single(T\
    \ x) {\r\n  x.read();\r\n}\r\ntemplate <class T, class U>\r\ninline void read_single(pair<T,\
    \ U> &p) {\r\n  read_single(p.first), read_single(p.second);\r\n}\r\ntemplate\
    \ <class... T>\r\ninline void read(tuple<T...> &tpl) {\r\n  apply([&](auto...\
    \ t) { (read(t), ...); }, tpl);\r\n}\r\ntemplate <class T>\r\ninline void read_single(vector<T>\
    \ &ref) {\r\n  for (auto &d: ref) read_single(d);\r\n}\r\ntemplate <class T, int\
    \ N>\r\ninline void read_single(array<T, N> &ref) {\r\n  for (auto &d: ref) read_single(d);\r\
    \n}\r\n\r\ninline void read() {}\r\ntemplate <typename Head, typename... Tail>\r\
    \ninline void read(Head &head, Tail &... tail) {\r\n  read_single(head);\r\n \
    \ read(tail...);\r\n}\r\n\r\ninline void write(char c) {\r\n  if (out_right >\
    \ SZ - 32) flush();\r\n  outbuf[out_right++] = c;\r\n}\r\ninline void write(bool\
    \ b) {\r\n  if (out_right > SZ - 32) flush();\r\n  outbuf[out_right++] = b ? '1'\
    \ : '0';\r\n}\r\ninline void write(const string &s) {\r\n  if (out_right + s.size()\
    \ > SZ - 32) flush();\r\n  memcpy(outbuf + out_right, s.data(), sizeof(char) *\
    \ s.size());\r\n  out_right += s.size();\r\n}\r\ntemplate <class T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\r\ninline void write(T x) {\r\n  if (out_right > SZ - 32) flush();\r\
    \n  if (!x) {\r\n    outbuf[out_right++] = '0';\r\n    return;\r\n  }\r\n  if\
    \ constexpr (is_signed<T>::value == true) {\r\n    if (x < 0) outbuf[out_right++]\
    \ = '-', x = -x;\r\n  }\r\n  int i = 12;\r\n  char buf[16];\r\n  while (x >= 10000)\
    \ {\r\n    memcpy(buf + i, pre.num + (x % 10000) * 4, 4);\r\n    x /= 10000;\r\
    \n    i -= 4;\r\n  }\r\n  if (x < 100) {\r\n    if (x < 10) {\r\n      outbuf[out_right]\
    \ = '0' + x;\r\n      ++out_right;\r\n    } else {\r\n      uint32_t q = (uint32_t(x)\
    \ * 205) >> 11;\r\n      uint32_t r = uint32_t(x) - q * 10;\r\n      outbuf[out_right]\
    \ = '0' + q;\r\n      outbuf[out_right + 1] = '0' + r;\r\n      out_right += 2;\r\
    \n    }\r\n  } else {\r\n    if (x < 1000) {\r\n      memcpy(outbuf + out_right,\
    \ pre.num + (x << 2) + 1, 3);\r\n      out_right += 3;\r\n    } else {\r\n   \
    \   memcpy(outbuf + out_right, pre.num + (x << 2), 4);\r\n      out_right += 4;\r\
    \n    }\r\n  }\r\n  memcpy(outbuf + out_right, buf + i + 4, 12 - i);\r\n  out_right\
    \ += 12 - i;\r\n}\r\ninline void write(const double &x) {\r\n  ostringstream oss;\r\
    \n  oss << fixed << setprecision(15) << x;\r\n  string s = oss.str();\r\n  write(s);\r\
    \n}\r\ninline void write(const long double &x) {\r\n  ostringstream oss;\r\n \
    \ oss << fixed << setprecision(15) << x;\r\n  string s = oss.str();\r\n  write(s);\r\
    \n}\r\ntemplate <typename T, typename enable_if<has_write<T>::value>::type * =\
    \ nullptr>\r\ninline void write(T x) {\r\n  x.write();\r\n}\r\ntemplate <class\
    \ T>\r\nvoid write(const vector<T> &val) {\r\n  auto n = val.size();\r\n  for\
    \ (size_t i = 0; i < n; i++) {\r\n    if (i) write(' ');\r\n    write(val[i]);\r\
    \n  }\r\n}\r\ntemplate <class T, class U>\r\nvoid write(const pair<T, U> &val)\
    \ {\r\n  write(val.first);\r\n  write(' ');\r\n  write(val.second);\r\n}\r\ntemplate\
    \ <class T, size_t S>\r\ninline void write(const array<T, S> &val) {\r\n  auto\
    \ n = val.size();\r\n  for (size_t i = 0; i < n; i++) {\r\n    if (i) write('\
    \ ');\r\n    write(val[i]);\r\n  }\r\n}\r\ninline void write(i128 val) {\r\n \
    \ string s;\r\n  bool negative = 0;\r\n  if (val < 0) {\r\n    negative = 1;\r\
    \n    val = -val;\r\n  }\r\n  while (val) {\r\n    s += '0' + int(val % 10);\r\
    \n    val /= 10;\r\n  }\r\n  if (negative) s += \"-\";\r\n  reverse(all(s));\r\
    \n  if (len(s) == 0) s = \"0\";\r\n  write(s);\r\n}\r\nstruct Dummy {\r\n  Dummy()\
    \ { atexit(flush); }\r\n} dummy;\r\n\r\nvoid print() { fastio::write('\\n'); }\r\
    \ntemplate <class Head, class... Tail>\r\nvoid print(Head &&head, Tail &&... tail)\
    \ {\r\n  fastio::write(head);\r\n  if (sizeof...(Tail)) fastio::write(' ');\r\n\
    \  print(forward<Tail>(tail)...);\r\n}\r\n} // namespace fastio\r\nusing fastio::read;\r\
    \nusing fastio::print;\r\n\r\n#define INT(...)   \\\r\n  int __VA_ARGS__; \\\r\
    \n  read(__VA_ARGS__)\r\n#define LL(...)   \\\r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define STR(...)      \\\r\n  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\
    \n#define CHAR(...)   \\\r\n  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    #define DBL(...)      \\\r\n  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\
    \r\n#define VEC(type, name, size) \\\r\n  vector<type> name(size);    \\\r\n \
    \ read(name)\r\n#define VV(type, name, h, w)                     \\\r\n  vector<vector<type>>\
    \ name(h, vector<type>(w)); \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print<string>(t\
    \ ? \"YES\" : \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool\
    \ t = 1) { print<string>(t ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t);\
    \ }\r\nvoid yes(bool t = 1) { print<string>(t ? \"yes\" : \"no\"); }\r\nvoid no(bool\
    \ t = 1) { yes(!t); }\r\n#line 2 \"flow/mincostflow.hpp\"\n\n// atcoder library\
    \ \u306E\u3082\u306E\u3092\u6539\u5909\n\nnamespace internal {\n\ntemplate <class\
    \ E>\nstruct csr {\n  std::vector<int> start;\n  std::vector<E> elist;\n  explicit\
    \ csr(int n, const std::vector<std::pair<int, E>>& edges)\n      : start(n + 1),\
    \ elist(edges.size()) {\n    for (auto e: edges) { start[e.first + 1]++; }\n \
    \   for (int i = 1; i <= n; i++) { start[i] += start[i - 1]; }\n    auto counter\
    \ = start;\n    for (auto e: edges) { elist[counter[e.first]++] = e.second; }\n\
    \  }\n};\n\ntemplate <class T>\nstruct simple_queue {\n  std::vector<T> payload;\n\
    \  int pos = 0;\n  void reserve(int n) { payload.reserve(n); }\n  int size() const\
    \ { return int(payload.size()) - pos; }\n  bool empty() const { return pos ==\
    \ int(payload.size()); }\n  void push(const T& t) { payload.push_back(t); }\n\
    \  T& front() { return payload[pos]; }\n  void clear() {\n    payload.clear();\n\
    \    pos = 0;\n  }\n  void pop() { pos++; }\n};\n\n} // namespace internal\n\n\
    /*\n\u30FBatcoder library \u3092\u3059\u3053\u3057\u6539\u5909\u3057\u305F\u3082\
    \u306E\n\u30FBDAG = true \u3067\u3042\u308C\u3070\u3001\u8CA0\u8FBA OK \uFF08\
    1 \u56DE\u76EE\u306E\u6700\u77ED\u8DEF\u3092 dp \u3067\u884C\u3046\uFF09\n\u305F\
    \u3060\u3057\u3001\u9802\u70B9\u756A\u53F7\u306F toposort \u3055\u308C\u3066\u3044\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\u3002\n*/\ntemplate\
    \ <class Cap = int, class Cost = ll, bool DAG = false>\nstruct mcf_graph {\npublic:\n\
    \  mcf_graph() {}\n  explicit mcf_graph(int n) : _n(n) {}\n\n  // frm, to, cap,\
    \ cost\n  int add(int frm, int to, Cap cap, Cost cost) {\n    assert(0 <= frm\
    \ && frm < _n);\n    assert(0 <= to && to < _n);\n    assert(0 <= cap);\n    assert(DAG\
    \ || 0 <= cost);\n    if (DAG) assert(frm < to);\n    int m = int(_edges.size());\n\
    \    _edges.push_back({frm, to, cap, 0, cost});\n    return m;\n  }\n\n  void\
    \ debug() {\n    print(\"flow graph\");\n    print(\"frm, to, cap, cost\");\n\
    \    for (auto&& [frm, to, cap, flow, cost]: _edges) {\n      print(frm, to, cap,\
    \ cost);\n    }\n  }\n\n  struct edge {\n    int frm, to;\n    Cap cap, flow;\n\
    \    Cost cost;\n  };\n\n  edge get_edge(int i) {\n    int m = int(_edges.size());\n\
    \    assert(0 <= i && i < m);\n    return _edges[i];\n  }\n  std::vector<edge>\
    \ edges() { return _edges; }\n\n  std::pair<Cap, Cost> flow(int s, int t) {\n\
    \    return flow(s, t, std::numeric_limits<Cap>::max());\n  }\n  std::pair<Cap,\
    \ Cost> flow(int s, int t, Cap flow_limit) {\n    return slope(s, t, flow_limit).back();\n\
    \  }\n  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {\n    return slope(s,\
    \ t, std::numeric_limits<Cap>::max());\n  }\n  std::vector<std::pair<Cap, Cost>>\
    \ slope(int s, int t, Cap flow_limit) {\n    assert(0 <= s && s < _n);\n    assert(0\
    \ <= t && t < _n);\n    assert(s != t);\n\n    int m = int(_edges.size());\n \
    \   std::vector<int> edge_idx(m);\n\n    auto g = [&]() {\n      std::vector<int>\
    \ degree(_n), redge_idx(m);\n      std::vector<std::pair<int, _edge>> elist;\n\
    \      elist.reserve(2 * m);\n      for (int i = 0; i < m; i++) {\n        auto\
    \ e = _edges[i];\n        edge_idx[i] = degree[e.frm]++;\n        redge_idx[i]\
    \ = degree[e.to]++;\n        elist.push_back({e.frm, {e.to, -1, e.cap - e.flow,\
    \ e.cost}});\n        elist.push_back({e.to, {e.frm, -1, e.flow, -e.cost}});\n\
    \      }\n      auto _g = internal::csr<_edge>(_n, elist);\n      for (int i =\
    \ 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i] += _g.start[e.frm];\n\
    \        redge_idx[i] += _g.start[e.to];\n        _g.elist[edge_idx[i]].rev =\
    \ redge_idx[i];\n        _g.elist[redge_idx[i]].rev = edge_idx[i];\n      }\n\
    \      return _g;\n    }();\n\n    auto result = slope(g, s, t, flow_limit);\n\
    \n    for (int i = 0; i < m; i++) {\n      auto e = g.elist[edge_idx[i]];\n  \
    \    _edges[i].flow = _edges[i].cap - e.cap;\n    }\n\n    return result;\n  }\n\
    \nprivate:\n  int _n;\n  std::vector<edge> _edges;\n\n  // inside edge\n  struct\
    \ _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\n  std::vector<std::pair<Cap,\
    \ Cost>> slope(internal::csr<_edge>& g, int s, int t,\n                      \
    \                    Cap flow_limit) {\n    // variants (C = maxcost):\n    //\
    \ -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n    // reduced cost (= e.cost\
    \ + dual[e.frm] - dual[e.to]) >= 0 for all edge\n\n    // dual_dist[i] = (dual[i],\
    \ dist[i])\n    if (DAG) assert(s == 0 && t == _n - 1);\n    std::vector<std::pair<Cost,\
    \ Cost>> dual_dist(_n);\n    std::vector<int> prev_e(_n);\n    std::vector<bool>\
    \ vis(_n);\n    struct Q {\n      Cost key;\n      int to;\n      bool operator<(Q\
    \ r) const { return key > r.key; }\n    };\n    std::vector<int> que_min;\n  \
    \  std::vector<Q> que;\n    auto dual_ref = [&]() {\n      for (int i = 0; i <\
    \ _n; i++) {\n        dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \      }\n      std::fill(vis.begin(), vis.end(), false);\n      que_min.clear();\n\
    \      que.clear();\n\n      // que[0..heap_r) was heapified\n      size_t heap_r\
    \ = 0;\n\n      dual_dist[s].second = 0;\n      que_min.push_back(s);\n      while\
    \ (!que_min.empty() || !que.empty()) {\n        int v;\n        if (!que_min.empty())\
    \ {\n          v = que_min.back();\n          que_min.pop_back();\n        } else\
    \ {\n          while (heap_r < que.size()) {\n            heap_r++;\n        \
    \    std::push_heap(que.begin(), que.begin() + heap_r);\n          }\n       \
    \   v = que.front().to;\n          std::pop_heap(que.begin(), que.end());\n  \
    \        que.pop_back();\n          heap_r--;\n        }\n        if (vis[v])\
    \ continue;\n        vis[v] = true;\n        if (v == t) break;\n        // dist[v]\
    \ = shortest(s, v) + dual[s] - dual[v]\n        // dist[v] >= 0 (all reduced cost\
    \ are positive)\n        // dist[v] <= (n-1)C\n        Cost dual_v = dual_dist[v].first,\
    \ dist_v = dual_dist[v].second;\n        for (int i = g.start[v]; i < g.start[v\
    \ + 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n\
    \          // |-dual[e.to] + dual[v]| <= (n-1)C\n          // cost <= C - -(n-1)C\
    \ + 0 = nC\n          Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n \
    \         if (dual_dist[e.to].second > dist_v + cost) {\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n            if (dist_to == dist_v) {\n             \
    \ que_min.push_back(e.to);\n            } else {\n              que.push_back(Q{dist_to,\
    \ e.to});\n            }\n          }\n        }\n      }\n      if (!vis[t])\
    \ { return false; }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s,\n        //         t) + dual[t] + shortest(s,\
    \ v) = shortest(s, v) -\n        //         shortest(s, t) >= 0 - (n-1)C\n   \
    \     dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n     \
    \ }\n      return true;\n    };\n\n    auto dual_ref_dag = [&]() {\n      for\
    \ (int i = 0; i < _n; i++) {\n        dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \      }\n      dual_dist[s].second = 0;\n      std::fill(vis.begin(), vis.end(),\
    \ false);\n      vis[0] = true;\n\n      for (int v = 0; v < _n; ++v) {\n    \
    \    if (!vis[v]) continue;\n        Cost dual_v = dual_dist[v].first, dist_v\
    \ = dual_dist[v].second;\n        for (int i = g.start[v]; i < g.start[v + 1];\
    \ i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n  \
    \        Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n          if (dual_dist[e.to].second\
    \ > dist_v + cost) {\n            vis[e.to] = true;\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n          }\n        }\n      }\n      if (!vis[t])\
    \ { return false; }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s,\n        //         t) + dual[t] + shortest(s,\
    \ v) = shortest(s, v) -\n        //         shortest(s, t) >= 0 - (n-1)C\n   \
    \     dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n     \
    \ }\n      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n    std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \    while (flow < flow_limit) {\n      if (DAG && flow == 0) {\n        if (!dual_ref_dag())\
    \ break;\n      } else {\n        if (!dual_ref()) break;\n      }\n      Cap\
    \ c = flow_limit - flow;\n      for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n        c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      }\n\
    \      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {\n        auto& e =\
    \ g.elist[prev_e[v]];\n        e.cap += c;\n        g.elist[e.rev].cap -= c;\n\
    \      }\n      Cost d = -dual_dist[s].first;\n      flow += c;\n      cost +=\
    \ c * d;\n      if (prev_cost_per_flow == d) { result.pop_back(); }\n      result.push_back({flow,\
    \ cost});\n      prev_cost_per_flow = d;\n    }\n    return result;\n  }\n};\n\
    #line 7 \"test/aoj/GRL_6_B.test.cpp\"\n\nvoid solve() {\n  LL(N, M, F);\n  mcf_graph<int,\
    \ ll, 0> G(N);\n  FOR(M) {\n    LL(a, b, c, d);\n    G.add(a, b, c, d);\n  }\n\
    \n  auto [f, x] = G.flow(0, N - 1, F);\n  if (f < F)\n    print(-1);\n  else\n\
    \    print(x);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\n\
    \  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B\"\
    \n\n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/mincostflow.hpp\"\
    \n\nvoid solve() {\n  LL(N, M, F);\n  mcf_graph<int, ll, 0> G(N);\n  FOR(M) {\n\
    \    LL(a, b, c, d);\n    G.add(a, b, c, d);\n  }\n\n  auto [f, x] = G.flow(0,\
    \ N - 1, F);\n  if (f < F)\n    print(-1);\n  else\n    print(x);\n}\n\nsigned\
    \ main() {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n\
    \  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/mincostflow.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 22:09:18+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_B.test.cpp
- /verify/test/aoj/GRL_6_B.test.cpp.html
title: test/aoj/GRL_6_B.test.cpp
---
