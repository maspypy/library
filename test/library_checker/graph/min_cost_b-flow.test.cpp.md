---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/bflow.hpp
    title: flow/bflow.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/min_cost_b_flow
    links:
    - https://judge.yosupo.jp/problem/min_cost_b_flow
  bundledCode: "#line 1 \"test/library_checker/graph/min_cost_b-flow.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#line 1 \"\
    my_template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\"\
    )\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\n\
    using pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\n\
    using u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\n\
    using vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate\
    \ <class T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vec(type, name, ...) vector<type> name(__VA_ARGS__)\n\
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
    \u30BF\u95A2\u6570\r\nstruct has_print_impl {\r\n  template <class T>\r\n  static\
    \ auto check(T &&x) -> decltype(x.print(), std::true_type{});\r\n\r\n  template\
    \ <class T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate\
    \ <class T>\r\nclass has_print : public decltype(has_print_impl::check<T>(std::declval<T>()))\
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
    \ x) {\r\n  x.read();\r\n}\r\ntemplate <class T>\r\ninline void read_single(vector<T>\
    \ &ref) {\r\n  for (auto &d: ref) read_single(d);\r\n}\r\ntemplate <class T, int\
    \ N>\r\ninline void read_single(array<T, N> &ref) {\r\n  for (auto &d: ref) read_single(d);\r\
    \n}\r\ntemplate <class T, class U>\r\ninline void read_single(pair<T, U> &p) {\r\
    \n  read_single(p.first), read_single(p.second);\r\n}\r\ntemplate <class... T>\r\
    \ninline void read_single(tuple<T...> &tpl) {\r\n  apply([&](auto... t) { (read(t),\
    \ ...); }, tpl);\r\n}\r\n\r\ninline void read() {}\r\ntemplate <typename Head,\
    \ typename... Tail>\r\ninline void read(Head &head, Tail &... tail) {\r\n  read_single(head);\r\
    \n  read(tail...);\r\n}\r\n\r\ninline void write(char c) {\r\n  if (out_right\
    \ > SZ - 32) flush();\r\n  outbuf[out_right++] = c;\r\n}\r\ninline void write(bool\
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
    \n}\r\ntemplate <typename T, typename enable_if<has_print<T>::value>::type * =\
    \ nullptr>\r\ninline void write(T x) {\r\n  x.print();\r\n}\r\ntemplate <class\
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
    \ t = 1) { yes(!t); }\r\n#line 2 \"flow/bflow.hpp\"\nenum Objective {\n  MINIMIZE\
    \ = 1,\n  MAXIMIZE = -1,\n};\nenum class Status {\n  OPTIMAL,\n  INFEASIBLE,\n\
    };\n\ntemplate <class Flow = ll, class Cost = ll,\n          Objective objective\
    \ = Objective::MINIMIZE, Flow SCALING_FACTOR = 2>\nstruct MinCostFlow {\nprivate:\n\
    \  using V_id = uint32_t;\n  using E_id = uint32_t;\n\n  struct Edge {\n    friend\
    \ struct MinCostFlow;\n\n  private:\n    V_id frm, to;\n    Flow flow, cap;\n\
    \    Cost cost;\n    E_id rev;\n\n  public:\n    Edge() = default;\n\n    Edge(const\
    \ V_id frm, const V_id to, const Flow cap, const Cost cost,\n         const E_id\
    \ rev)\n        : frm(frm), to(to), flow(0), cap(cap), cost(cost), rev(rev) {}\n\
    \n    [[nodiscard]] Flow residual_cap() const { return cap - flow; }\n  };\n\n\
    public:\n  struct EdgePtr {\n    friend struct MinCostFlow;\n\n  private:\n  \
    \  const MinCostFlow *instance;\n    const V_id v;\n    const E_id e;\n\n    EdgePtr(const\
    \ MinCostFlow *instance, const V_id v, const E_id e)\n        : instance(instance),\
    \ v(v), e(e) {}\n\n    [[nodiscard]] const Edge &edge() const { return instance->g[v][e];\
    \ }\n\n    [[nodiscard]] const Edge &rev() const {\n      const Edge &e = edge();\n\
    \      return instance->g[e.to][e.rev];\n    }\n\n  public:\n    [[nodiscard]]\
    \ V_id frm() const { return rev().to; }\n\n    [[nodiscard]] V_id to() const {\
    \ return edge().to; }\n\n    [[nodiscard]] Flow flow() const { return edge().flow;\
    \ }\n\n    [[nodiscard]] Flow lower() const { return -rev().cap; }\n\n    [[nodiscard]]\
    \ Flow upper() const { return edge().cap; }\n\n    [[nodiscard]] Cost cost() const\
    \ { return edge().cost; }\n\n    [[nodiscard]] Cost gain() const { return -edge().cost;\
    \ }\n  };\n\nprivate:\n  V_id n;\n  std::vector<std::vector<Edge>> g;\n  std::vector<Flow>\
    \ b;\n\npublic:\n  MinCostFlow(int n) : n(n) {\n    g.resize(n);\n    b.resize(n);\n\
    \  }\n\n  V_id add_vertex() {\n    ++n;\n    g.resize(n);\n    b.resize(n);\n\
    \    return n - 1;\n  }\n\n  std::vector<V_id> add_vertices(const size_t size)\
    \ {\n    std::vector<V_id> ret;\n    for (V_id i = 0; i < size; ++i) ret.emplace_back(n\
    \ + i);\n    n += size;\n    g.resize(n);\n    b.resize(n);\n    return ret;\n\
    \  }\n\n  void add(const V_id frm, const V_id to, const Flow lo, const Flow hi,\n\
    \           const Cost cost) {\n    const E_id e = g[frm].size(), re = frm ==\
    \ to ? e + 1 : g[to].size();\n    assert(lo <= hi);\n    g[frm].emplace_back(Edge{frm,\
    \ to, hi, cost * objective, re});\n    g[to].emplace_back(Edge{to, frm, -lo, -cost\
    \ * objective, e});\n    edges.eb(EdgePtr{this, frm, e});\n  }\n\n  void add_source(const\
    \ V_id v, const Flow amount) { b[v] += amount; }\n\n  void add_sink(const V_id\
    \ v, const Flow amount) { b[v] -= amount; }\n\nprivate:\n  static Cost constexpr\
    \ unreachable = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  std::vector<Cost>\
    \ potential;\n  std::vector<Cost> dist;\n  std::vector<Edge *> parent;\n  std::priority_queue<std::pair<Cost,\
    \ int>, std::vector<std::pair<Cost, int>>,\n                      std::greater<>>\n\
    \      pq;\n  std::vector<V_id> excess_vs, deficit_vs;\n  std::vector<EdgePtr>\
    \ edges;\n  Edge &rev(const Edge &e) { return g[e.to][e.rev]; }\n\n  void push(Edge\
    \ &e, const Flow amount) {\n    e.flow += amount;\n    g[e.to][e.rev].flow -=\
    \ amount;\n  }\n\n  Cost residual_cost(const V_id frm, const V_id to, const Edge\
    \ &e) {\n    return e.cost + potential[frm] - potential[to];\n  }\n\n  bool dual(const\
    \ Flow delta) {\n    dist.assign(n, unreachable);\n    parent.assign(n, nullptr);\n\
    \    excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),\n\
    \                                   [&](const V_id v) { return b[v] < delta; }),\n\
    \                    std::end(excess_vs));\n    deficit_vs.erase(\n        std::remove_if(std::begin(deficit_vs),\
    \ std::end(deficit_vs),\n                       [&](const V_id v) { return b[v]\
    \ > -delta; }),\n        std::end(deficit_vs));\n    for (const auto v: excess_vs)\
    \ pq.emplace(dist[v] = 0, v);\n    farthest = 0;\n    std::size_t deficit_count\
    \ = 0;\n    while (!pq.empty()) {\n      const auto [d, u] = pq.top();\n     \
    \ pq.pop();\n      if (dist[u] < d) continue;\n      farthest = d;\n      if (b[u]\
    \ <= -delta) ++deficit_count;\n      if (deficit_count >= deficit_vs.size()) break;\n\
    \      for (auto &e: g[u]) {\n        if (e.residual_cap() < delta) continue;\n\
    \        const auto v = e.to;\n        const auto new_dist = d + residual_cost(u,\
    \ v, e);\n        if (new_dist >= dist[v]) continue;\n        pq.emplace(dist[v]\
    \ = new_dist, v);\n        parent[v] = &e;\n      }\n    }\n    pq = decltype(pq)();\n\
    \    for (V_id v = 0; v < n; ++v) {\n      potential[v] += std::min(dist[v], farthest);\n\
    \    }\n    return deficit_count > 0;\n  }\n\n  void primal(const Flow delta)\
    \ {\n    for (const auto t: deficit_vs) {\n      if (dist[t] > farthest) continue;\n\
    \      Flow f = -b[t];\n      V_id v;\n      for (v = t; parent[v] != nullptr\
    \ && f >= delta; v = parent[v]->frm) {\n        f = std::min(f, parent[v]->residual_cap());\n\
    \      }\n      f = std::min(f, b[v]);\n      if (f < delta) continue;\n     \
    \ for (v = t; parent[v] != nullptr;) {\n        auto &e = *parent[v];\n      \
    \  push(e, f);\n        const size_t u = parent[v]->frm;\n        parent[v] =\
    \ nullptr;\n        v = u;\n      }\n      b[t] += f;\n      b[v] -= f;\n    }\n\
    \  }\n\n  void saturate_negative(const Flow delta) {\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for (auto &es: g)\n      for (auto &e: es) {\n \
    \       const Flow rcap = e.residual_cap();\n        const Cost rcost = residual_cost(e.frm,\
    \ e.to, e);\n        if (rcost < 0 && rcap >= delta) {\n          push(e, rcap);\n\
    \          b[e.frm] -= rcap;\n          b[e.to] += rcap;\n        }\n      }\n\
    \    for (V_id v = 0; v < n; ++v)\n      if (b[v] != 0) { (b[v] > 0 ? excess_vs\
    \ : deficit_vs).emplace_back(v); }\n  }\n\npublic:\n  std::pair<Status, i128>\
    \ solve() {\n    potential.resize(n);\n    for (auto &es: g)\n      for (auto\
    \ &e: es) {\n        const Flow rcap = e.residual_cap();\n        if (rcap < 0)\
    \ {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n          b[e.to]\
    \ += rcap;\n        }\n      }\n\n    Flow inf_flow = 1;\n    for (const auto\
    \ &es: g)\n      for (const auto &e: es) inf_flow = std::max(inf_flow, e.residual_cap());\n\
    \    Flow delta = 1;\n    while (delta <= inf_flow) delta *= SCALING_FACTOR;\n\
    \n    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {\n      saturate_negative(delta);\n\
    \      while (dual(delta)) primal(delta);\n    }\n\n    i128 value = 0;\n    for\
    \ (const auto &es: g)\n      for (const auto &e: es) { value += e.flow * e.cost;\
    \ }\n    value /= 2;\n\n    if (excess_vs.empty() && deficit_vs.empty()) {\n \
    \     return {Status::OPTIMAL, value / objective};\n    } else {\n      return\
    \ {Status::INFEASIBLE, value / objective};\n    }\n  }\n\n  template <class T>\n\
    \  T get_result_value() {\n    T value = 0;\n    for (const auto &es: g)\n   \
    \   for (const auto &e: es) { value += (T)(e.flow) * (T)(e.cost); }\n    value\
    \ /= (T)2;\n    return value / objective;\n  }\n\n  std::vector<Cost> get_potential()\
    \ {\n    std::fill(potential.begin(), potential.end(), 0);\n    for (int i = 0;\
    \ i < (int)n; i++)\n      for (const auto &es: g)\n        for (const auto &e:\
    \ es)\n          if (e.residual_cap() > 0)\n            potential[e.to]\n    \
    \            = std::min(potential[e.to], potential[e.frm] + e.cost);\n    return\
    \ potential;\n  }\n\n  std::vector<EdgePtr> get_edges() { return edges; }\n};\n\
    #line 5 \"test/library_checker/graph/min_cost_b-flow.test.cpp\"\n\nvoid solve()\
    \ {\n  LL(N, M);\n  MinCostFlow<ll, ll> G(N);\n  FOR(i, N) {\n    LL(b);\n   \
    \ G.add_source(i, b);\n  }\n  FOR(i, M) {\n    LL(frm, to, lo, hi, cost);\n  \
    \  G.add(frm, to, lo, hi, cost);\n  }\n  auto [status, cost] = G.solve();\n  if\
    \ (status == Status::INFEASIBLE) return print(\"infeasible\");\n  print(cost);\n\
    \  for (auto &&p: G.get_potential()) print(p);\n  for (auto &&e: G.get_edges())\
    \ { print(e.flow()); }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_cost_b_flow\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"flow/bflow.hpp\"\n\
    \nvoid solve() {\n  LL(N, M);\n  MinCostFlow<ll, ll> G(N);\n  FOR(i, N) {\n  \
    \  LL(b);\n    G.add_source(i, b);\n  }\n  FOR(i, M) {\n    LL(frm, to, lo, hi,\
    \ cost);\n    G.add(frm, to, lo, hi, cost);\n  }\n  auto [status, cost] = G.solve();\n\
    \  if (status == Status::INFEASIBLE) return print(\"infeasible\");\n  print(cost);\n\
    \  for (auto &&p: G.get_potential()) print(p);\n  for (auto &&e: G.get_edges())\
    \ { print(e.flow()); }\n}\n\nsigned main() {\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - flow/bflow.hpp
  isVerificationFile: true
  path: test/library_checker/graph/min_cost_b-flow.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 21:03:20+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/graph/min_cost_b-flow.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/graph/min_cost_b-flow.test.cpp
- /verify/test/library_checker/graph/min_cost_b-flow.test.cpp.html
title: test/library_checker/graph/min_cost_b-flow.test.cpp
---
