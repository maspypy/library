---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':x:'
    path: graph/ds/link_cut.hpp
    title: graph/ds/link_cut.hpp
  - icon: ':x:'
    path: graph/ds/link_cut_path.hpp
    title: graph/ds/link_cut_path.hpp
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum
  bundledCode: "#line 1 \"test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n#line 1 \"my_template.hpp\"\n#pragma GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"\
    unroll-loops\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll\
    \ = long long;\nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 =\
    \ unsigned int;\nusing u64 = unsigned long long;\nusing i128 = __int128;\n\ntemplate\
    \ <class T>\nusing vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\n\
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
    \ SZ - 32) flush();\r\n  outbuf[out_right++] = c;\r\n}\r\ninline void write(const\
    \ string &s) {\r\n  if (out_right + s.size() > SZ - 32) flush();\r\n  memcpy(outbuf\
    \ + out_right, s.data(), sizeof(char) * s.size());\r\n  out_right += s.size();\r\
    \n}\r\ntemplate <class T, enable_if_t<is_integral<T>::value, int> = 0>\r\ninline\
    \ void write(T x) {\r\n  if (out_right > SZ - 32) flush();\r\n  if (!x) {\r\n\
    \    outbuf[out_right++] = '0';\r\n    return;\r\n  }\r\n  if constexpr (is_signed<T>::value\
    \ == true) {\r\n    if (x < 0) outbuf[out_right++] = '-', x = -x;\r\n  }\r\n \
    \ int i = 12;\r\n  char buf[16];\r\n  while (x >= 10000) {\r\n    memcpy(buf +\
    \ i, pre.num + (x % 10000) * 4, 4);\r\n    x /= 10000;\r\n    i -= 4;\r\n  }\r\
    \n  if (x < 100) {\r\n    if (x < 10) {\r\n      outbuf[out_right] = '0' + x;\r\
    \n      ++out_right;\r\n    } else {\r\n      uint32_t q = (uint32_t(x) * 205)\
    \ >> 11;\r\n      uint32_t r = uint32_t(x) - q * 10;\r\n      outbuf[out_right]\
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
    \ t = 1) { yes(!t); }\r\n#line 5 \"test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct Monoid_Add\
    \ {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x, const X\
    \ &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept\
    \ { return -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return\
    \ X(n) * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 2 \"graph/ds/link_cut.hpp\"\n\ntemplate\
    \ <typename Node, int NODES>\nstruct LinkCutTree_base {\n  int n;\n  Node *nodes;\n\
    \n  LinkCutTree_base(int n = 0) : n(n) {\n    nodes = new Node[NODES];\n    FOR(i,\
    \ n) nodes[i] = Node(i);\n  }\n\n  Node *operator[](int v) { return &nodes[v];\
    \ }\n\n  // \u30D1\u30B9\u3092\u8868\u3059 splay tree \u306E\u6839\u306B\u306A\
    \u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\n  bool is_root(Node *c) { return\
    \ state(c) == 0; }\n  bool is_root(int c) { return state(&nodes[c]) == 0; }\n\n\
    \  Node *get_root(Node *c) {\n    expose(c);\n    while (c->l) {\n      c->push();\n\
    \      c = c->l;\n    }\n    splay(c);\n    return c;\n  }\n\n  int get_root(int\
    \ c) { return get_root(&nodes[c])->idx; }\n\n  // c \u306E\u89AA\u3092 p \u306B\
    \u3059\u308B\u3002\n  virtual void link(Node *c, Node *p) {\n    evert(c);\n \
    \   expose(p);\n    c->p = p;\n    p->r = c;\n    p->update();\n  }\n\n  // c\
    \ \u306E\u89AA\u3092 p \u306B\u3059\u308B\n  virtual void link(int c, int p) {\
    \ return link(&nodes[c], &nodes[p]); }\n\n  void cut(Node *a, Node *b) {\n   \
    \ evert(a);\n    expose(b);\n    assert(!b->p);\n    assert((b->l) == a);\n  \
    \  b->l->p = nullptr;\n    b->l = nullptr;\n    b->update();\n  }\n\n  void cut(int\
    \ a, int b) { return cut(&nodes[a], &nodes[b]); }\n\n  void evert(Node *c) {\n\
    \    expose(c);\n    c->reverse();\n    c->push();\n  }\n\n  void evert(int c)\
    \ { evert(&nodes[c]); }\n\n  Node *lca(Node *u, Node *v) {\n    assert(get_root(u)\
    \ == get_root(v));\n    expose(u);\n    return expose(v);\n  }\n\n  int lca(int\
    \ u, int v) { return lca(&nodes[u], &nodes[v])->idx; }\n\n  // c \u3068\u6839\u307E\
    \u3067\u304C\u7E4B\u304C\u308C\u3066\u3044\u308B\u72B6\u614B\u306B\u5909\u66F4\
    \u3057\u3066\u3001\u6839\u3092 return \u3059\u308B\n  virtual Node *expose(Node\
    \ *c) {\n    Node *now = c;\n    Node *rp = nullptr; // \u4ECA\u307E\u3067\u4F5C\
    \u3063\u305F\u30D1\u30B9\n    while (now) {\n      splay(now);\n      now->r =\
    \ rp; // \u5B50\u65B9\u5411\u306E\u5909\u66F4\n      now->update();\n      rp\
    \ = now;\n      now = now->p;\n    }\n    splay(c);\n    return rp;\n  }\n\n \
    \ int expose(int c) {\n    Node *x = expose(&nodes[c]);\n    if (!x) return -1;\n\
    \    return x->idx;\n  }\n\n  Node *get_parent(Node *x) {\n    expose(x);\n  \
    \  if (!x->l) return nullptr;\n    x = x->l;\n    while (x->r) x = x->r;\n   \
    \ return x;\n  }\n\n  int get_parent(int x) {\n    Node *p = get_parent((*this)[x]);\n\
    \    return (p ? p->idx : -1);\n  }\n\n  void debug() {\n    FOR(i, n) { nodes[i].debug();\
    \ }\n  }\n\n  virtual void rotate(Node *n) {\n    // n \u3092\u6839\u306B\u8FD1\
    \u3065\u3051\u308B\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n\n \
    \   if (p->l == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    }\
    \ else {\n      c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n\n    if (pp\
    \ && pp->l == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p =\
    \ pp;\n    p->p = n;\n    if (c) c->p = p;\n  }\n\n  inline int state(Node *n)\
    \ {\n    if (!n->p) return 0;\n    if (n->p->l == n) return 1;\n    if (n->p->r\
    \ == n) return -1;\n    return 0;\n  }\n\n  void splay(Node *c) {\n    c->push();\n\
    \    while (!is_root(c)) {\n      Node *p = c->p;\n      Node *pp = (p ? p->p\
    \ : nullptr);\n      if (state(p) == 0) {\n        p->push(), c->push();\n   \
    \     rotate(c);\n        if (p) p->update();\n      }\n      elif (state(c) ==\
    \ state(p)) {\n        pp->push(), p->push(), c->push();\n        rotate(p);\n\
    \        rotate(c);\n        if (pp) pp->update();\n        if (p) p->update();\n\
    \      }\n      else {\n        pp->push(), p->push(), c->push();\n        rotate(c);\n\
    \        rotate(c);\n        if (p) p->update();\n        if (pp) pp->update();\n\
    \      }\n    }\n    c->update();\n  }\n};\n\nstruct LCT_Node_base {\n  LCT_Node_base\
    \ *l, *r, *p;\n  int idx;\n  bool rev;\n  LCT_Node_base(int i = 0) : l(nullptr),\
    \ r(nullptr), p(nullptr), idx(i) {}\n\n  void update() {}\n\n  void push() {\n\
    \    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n    \
    \  rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l, r);\n\
    \  }\n};\n\ntemplate <int NODES>\nusing LinkCutTree = LinkCutTree_base<LCT_Node_base,\
    \ NODES>;\n#line 2 \"graph/ds/link_cut_path.hpp\"\n\ntemplate <typename Node,\
    \ int NODES>\nstruct LinkCutTree_Path_base : public LinkCutTree_base<Node, NODES>\
    \ {\n  using X = typename Node::X;\n\n  LinkCutTree_Path_base(int n) : LinkCutTree_base<Node,\
    \ NODES>(n) {}\n\n  LinkCutTree_Path_base(vc<X> dat) : LinkCutTree_base<Node,\
    \ NODES>(len(dat)) {\n    FOR(v, len(dat)) {\n      Node *c = (*this)[v];\n  \
    \    set(c, dat[v]);\n    }\n  }\n\n  template <typename F>\n  LinkCutTree_Path_base(int\
    \ n, F f) : LinkCutTree_base<Node, NODES>(n) {\n    FOR(v, n) {\n      X x = f(v);\n\
    \      Node *c = (*this)[v];\n      set(c, x);\n    }\n  }\n\n  void set(Node\
    \ *c, X x) {\n    this->evert(c);\n    c->x = x;\n    c->update();\n  }\n\n  void\
    \ set(int c, X x) { set((*this)[c], x); }\n\n  void multiply(Node *c, X x) { set(c,\
    \ Node::Mono::op(c->x, x)); }\n\n  void multiply(int c, X x) { multiply((*this)[c],\
    \ x); }\n\n  X prod_path(Node *a, Node *b) {\n    this->evert(a);\n    this->expose(b);\n\
    \    return b->prod;\n  }\n\n  X prod_path(int a, int b) { return prod_path((*this)[a],\
    \ (*this)[b]); }\n};\n\ntemplate <typename Monoid>\nstruct LCT_Node_Monoid {\n\
    \  using Mono = Monoid;\n  using X = typename Monoid::value_type;\n  LCT_Node_Monoid\
    \ *l, *r, *p;\n  int idx;\n  X x, prod, rev_prod;\n  bool rev;\n  LCT_Node_Monoid(int\
    \ i = 0)\n      : l(nullptr),\n        r(nullptr),\n        p(nullptr),\n    \
    \    idx(i),\n        x(Monoid::unit()),\n        prod(Monoid::unit()),\n    \
    \    rev_prod(Monoid::unit()) {}\n\n  void update() {\n    prod = rev_prod = x;\n\
    \    if (l) {\n      prod = Monoid::op(l->prod, prod);\n      rev_prod = Monoid::op(rev_prod,\
    \ l->rev_prod);\n    }\n    if (r) {\n      prod = Monoid::op(prod, r->prod);\n\
    \      rev_prod = Monoid::op(r->rev_prod, rev_prod);\n    }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n    swap(prod, rev_prod);\n  }\n\n  void debug() {\n    int li = (l ? l->idx\
    \ : -1);\n    int ri = (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n \
    \   print(\"idx\", idx, \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod,\n\
    \          \"rev_prod\", rev_prod);\n  }\n};\n\ntemplate <typename Monoid>\nstruct\
    \ LCT_Node_CommutativeMonoid {\n  using Mono = Monoid;\n  using X = typename Mono::value_type;\n\
    \  LCT_Node_CommutativeMonoid *l, *r, *p;\n  int idx;\n  X x, prod;\n  bool rev;\n\
    \  LCT_Node_CommutativeMonoid(int i = 0)\n      : l(nullptr),\n        r(nullptr),\n\
    \        p(nullptr),\n        idx(i),\n        x(Mono::unit()),\n        prod(Mono::unit())\
    \ {}\n\n  void update() {\n    prod = x;\n    if (l) { prod = Mono::op(l->prod,\
    \ prod); }\n    if (r) { prod = Mono::op(prod, r->prod); }\n  }\n\n  void push()\
    \ {\n    if (rev) {\n      if (l) l->reverse();\n      if (r) r->reverse();\n\
    \      rev = 0;\n    }\n  }\n\n  void reverse() {\n    rev ^= 1;\n    swap(l,\
    \ r);\n  }\n\n  void debug() {\n    int li = (l ? l->idx : -1);\n    int ri =\
    \ (r ? r->idx : -1);\n    int pi = (p ? p->idx : -1);\n    print(\"idx\", idx,\
    \ \"l\", li, \"r\", ri, \"p\", pi, \"x\", x, \"prod\", prod);\n  }\n};\n\ntemplate\
    \ <typename Monoid, int NODES>\nusing LinkCutTree_Path = LinkCutTree_Path_base<LCT_Node_Monoid<Monoid>,\
    \ NODES>;\n\ntemplate <typename Monoid, int NODES>\nusing LinkCutTree_Path_Commutative\n\
    \    = LinkCutTree_Path_base<LCT_Node_CommutativeMonoid<Monoid>, NODES>;\n#line\
    \ 8 \"test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp\"\
    \n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll, A, N);\n\n  LinkCutTree_Path<Monoid_Add<ll>,\
    \ 200000> X(A);\n\n  FOR(N - 1) {\n    LL(u, v);\n    X.link(u, v);\n  }\n\n \
    \ FOR(Q) {\n    LL(t);\n    if (t == 0) {\n      LL(a, b, c, d);\n      X.cut(a,\
    \ b);\n      X.link(c, d);\n    }\n    if (t == 1) {\n      LL(p, x);\n      X.multiply(p,\
    \ x);\n    }\n    if (t == 2) {\n      LL(a, b);\n      print(X.prod_path(a, b));\n\
    \    }\n  }\n}\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n\
    \  cout << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\
    \n  return 0;\n}\n"
  code: "#define PROBLEM \\\n  \"https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum\"\
    \n#include \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"alg/monoid/add.hpp\"\
    \n#include \"graph/ds/link_cut_path.hpp\"\n\nvoid solve() {\n  LL(N, Q);\n  VEC(ll,\
    \ A, N);\n\n  LinkCutTree_Path<Monoid_Add<ll>, 200000> X(A);\n\n  FOR(N - 1) {\n\
    \    LL(u, v);\n    X.link(u, v);\n  }\n\n  FOR(Q) {\n    LL(t);\n    if (t ==\
    \ 0) {\n      LL(a, b, c, d);\n      X.cut(a, b);\n      X.link(c, d);\n    }\n\
    \    if (t == 1) {\n      LL(p, x);\n      X.multiply(p, x);\n    }\n    if (t\
    \ == 2) {\n      LL(a, b);\n      print(X.prod_path(a, b));\n    }\n  }\n}\n\n\
    signed main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout <<\
    \ setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n  FOR(_, T) solve();\n\n  return\
    \ 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/monoid/add.hpp
  - graph/ds/link_cut_path.hpp
  - graph/ds/link_cut.hpp
  isVerificationFile: true
  path: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 23:08:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
- /verify/test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp.html
title: test/library_checker/datastructure/dynamic_tree_vertex_add_path_sum.test.cpp
---
