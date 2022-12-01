---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/min.hpp
    title: alg/monoid/min.hpp
  - icon: ':question:'
    path: ds/rbst/rbst_monoid.hpp
    title: ds/rbst/rbst_monoid.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':question:'
    path: other/io.hpp
    title: other/io.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/rbst_test.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \ t = 1) { yes(!t); }\r\n#line 2 \"alg/monoid/min.hpp\"\n\r\ntemplate <class X>\r\
    \nstruct Monoid_Min {\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return min(x, y); }\r\n  static constexpr X unit()\
    \ { return numeric_limits<X>::max(); }\r\n  static constexpr bool commute = true;\r\
    \n};\r\n#line 1 \"ds/rbst/rbst_monoid.hpp\"\ntemplate <typename Monoid, bool PERSISTENT,\
    \ int NODES>\nstruct RBST_Monoid {\n  using X = typename Monoid::value_type;\n\
    \n  struct Node {\n    Node *l, *r;\n    X x, prod, rev_prod; // rev \u53CD\u6620\
    \u6E08\n    u32 size;\n    bool rev;\n  };\n\n  Node *pool;\n  int pid;\n  using\
    \ np = Node *;\n\n  RBST_Monoid() : pid(0) { pool = new Node[NODES]; }\n\n  void\
    \ reset() { pid = 0; }\n\n  np new_node(const X &x) {\n    pool[pid].l = pool[pid].r\
    \ = nullptr;\n    pool[pid].x = x;\n    pool[pid].prod = x;\n    pool[pid].rev_prod\
    \ = x;\n    pool[pid].size = 1;\n    pool[pid].rev = 0;\n    return &(pool[pid++]);\n\
    \  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs = [&](auto &dfs, u32 l,\
    \ u32 r) -> np {\n      if (l == r) return nullptr;\n      if (r == l + 1) return\
    \ new_node(dat[l]);\n      u32 m = (l + r) / 2;\n      np l_root = dfs(dfs, l,\
    \ m);\n      np r_root = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n\
    \      root->l = l_root, root->r = r_root;\n      update(root);\n      return\
    \ root;\n    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  np copy_node(np &n)\
    \ {\n    if (!n || !PERSISTENT) return n;\n    pool[pid].l = n->l, pool[pid].r\
    \ = n->r;\n    pool[pid].x = n->x;\n    pool[pid].prod = n->prod;\n    pool[pid].rev_prod\
    \ = n->rev_prod;\n    pool[pid].size = n->size;\n    pool[pid].rev = n->rev;\n\
    \    return &(pool[pid++]);\n  }\n\n  np merge(np l_root, np r_root) { return\
    \ merge_rec(l_root, r_root); }\n  np merge3(np a, np b, np c) { return merge(merge(a,\
    \ b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n  pair<np, np> split(np root, u32 k) {\n    if (!root) {\n  \
    \    assert(k == 0);\n      return {nullptr, nullptr};\n    }\n    assert(0 <=\
    \ k && k <= root->size);\n    return split_rec(root, k);\n  }\n  tuple<np, np,\
    \ np> split3(np root, u32 l, u32 r) {\n    np nm, nr;\n    tie(root, nr) = split(root,\
    \ r);\n    tie(root, nm) = split(root, l);\n    return {root, nm, nr};\n  }\n\
    \  tuple<np, np, np, np> split4(np root, u32 i, u32 j, u32 k) {\n    np d;\n \
    \   tie(root, d) = split(root, k);\n    auto [a, b, c] = split3(root, i, j);\n\
    \    return {a, b, c, d};\n  }\n\n  X prod(np root, u32 l, u32 r) {\n    if (l\
    \ == r) return Monoid::unit();\n    return prod_rec(root, l, r, false);\n  }\n\
    \  X prod(np root) { return (root ? root->prod : Monoid::unit()); }\n\n  np reverse(np\
    \ root, u32 l, u32 r) {\n    assert(0 <= l && l <= r && r <= root->size);\n  \
    \  if (r - l <= 1) return root;\n    auto [nl, nm, nr] = split3(root, l, r);\n\
    \    nm->rev ^= 1;\n    swap(nm->l, nm->r);\n    swap(nm->prod, nm->rev_prod);\n\
    \    return merge3(nl, nm, nr);\n  }\n\n  np set(np root, u32 k, const X &x) {\
    \ return set_rec(root, k, x); }\n  np multiply(np root, u32 k, const X &x) { return\
    \ multiply_rec(root, k, x); }\n  X get(np root, u32 k) { return get_rec(root,\
    \ k, false); }\n\n  vc<X> get_all(np root) {\n    vc<X> res;\n    auto dfs = [&](auto\
    \ &dfs, np root, bool rev) -> void {\n      if (!root) return;\n      dfs(dfs,\
    \ (rev ? root->r : root->l), rev ^ root->rev);\n      res.eb(root->x);\n     \
    \ dfs(dfs, (rev ? root->l : root->r), rev ^ root->rev);\n    };\n    dfs(dfs,\
    \ root, 0);\n    return res;\n  }\n\n  template <typename F>\n  pair<np, np> split_max_right(np\
    \ root, const F check) {\n    assert(check(Monoid::unit()));\n    X x = Monoid::unit();\n\
    \    return split_max_right_rec(root, check, x);\n  }\n\nprivate:\n  inline u32\
    \ xor128() {\n    static u32 x = 123456789;\n    static u32 y = 362436069;\n \
    \   static u32 z = 521288629;\n    static u32 w = 88675123;\n    u32 t = x ^ (x\
    \ << 11);\n    x = y;\n    y = z;\n    z = w;\n    return w = (w ^ (w >> 19))\
    \ ^ (t ^ (t >> 8));\n  }\n\n  void prop(np c) {\n    // \u81EA\u8EAB\u3092\u30B3\
    \u30D4\u30FC\u3059\u308B\u5FC5\u8981\u306F\u306A\u3044\u3002\n    // \u5B50\u3092\
    \u30B3\u30D4\u30FC\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\u8907\u6570\
    \u306E\u89AA\u3092\u6301\u3064\u53EF\u80FD\u6027\u304C\u3042\u308B\u305F\u3081\
    \u3002\n    if (c->rev) {\n      if (c->l) {\n        c->l = copy_node(c->l);\n\
    \        c->l->rev ^= 1;\n        swap(c->l->l, c->l->r);\n        swap(c->l->prod,\
    \ c->l->rev_prod);\n      }\n      if (c->r) {\n        c->r = copy_node(c->r);\n\
    \        c->r->rev ^= 1;\n        swap(c->r->l, c->r->r);\n        swap(c->r->prod,\
    \ c->r->rev_prod);\n      }\n      c->rev = 0;\n    }\n  }\n\n  void update(np\
    \ c) {\n    // \u30C7\u30FC\u30BF\u3092\u4FDD\u3063\u305F\u307E\u307E\u6B63\u5E38\
    \u5316\u3059\u308B\u3060\u3051\u306A\u306E\u3067\u3001\u30B3\u30D4\u30FC\u4E0D\
    \u8981\n    c->size = 1;\n    c->prod = c->rev_prod = c->x;\n    if (c->l) {\n\
    \      c->size += c->l->size;\n      c->prod = Monoid::op(c->l->prod, c->prod);\n\
    \      c->rev_prod = Monoid::op(c->rev_prod, c->l->rev_prod);\n    }\n    if (c->r)\
    \ {\n      c->size += c->r->size;\n      c->prod = Monoid::op(c->prod, c->r->prod);\n\
    \      c->rev_prod = Monoid::op(c->r->rev_prod, c->rev_prod);\n    }\n  }\n\n\
    \  np merge_rec(np l_root, np r_root) {\n    if (!l_root) return r_root;\n   \
    \ if (!r_root) return l_root;\n    u32 sl = l_root->size, sr = r_root->size;\n\
    \    if (xor128() % (sl + sr) < sl) {\n      prop(l_root);\n      l_root = copy_node(l_root);\n\
    \      l_root->r = merge_rec(l_root->r, r_root);\n      update(l_root);\n    \
    \  return l_root;\n    }\n    prop(r_root);\n    r_root = copy_node(r_root);\n\
    \    r_root->l = merge_rec(l_root, r_root->l);\n    update(r_root);\n    return\
    \ r_root;\n  }\n\n  pair<np, np> split_rec(np root, u32 k) {\n    if (!root) return\
    \ {nullptr, nullptr};\n    prop(root);\n    u32 sl = (root->l ? root->l->size\
    \ : 0);\n    if (k <= sl) {\n      auto [nl, nr] = split_rec(root->l, k);\n  \
    \    root = copy_node(root);\n      root->l = nr;\n      update(root);\n     \
    \ return {nl, root};\n    }\n    auto [nl, nr] = split_rec(root->r, k - (1 + sl));\n\
    \    root = copy_node(root);\n    root->r = nl;\n    update(root);\n    return\
    \ {root, nr};\n  }\n\n  np set_rec(np root, u32 k, const X &x) {\n    if (!root)\
    \ return root;\n    prop(root);\n    u32 sl = (root->l ? root->l->size : 0);\n\
    \    if (k < sl) {\n      root = copy_node(root);\n      root->l = set_rec(root->l,\
    \ k, x);\n      update(root);\n      return root;\n    }\n    if (k == sl) {\n\
    \      root = copy_node(root);\n      root->x = x;\n      update(root);\n    \
    \  return root;\n    }\n    root = copy_node(root);\n    root->r = set_rec(root->r,\
    \ k - (1 + sl), x);\n    update(root);\n    return root;\n  }\n\n  np multiply_rec(np\
    \ root, u32 k, const X &x) {\n    if (!root) return root;\n    prop(root);\n \
    \   u32 sl = (root->l ? root->l->size : 0);\n    if (k < sl) {\n      root = copy_node(root);\n\
    \      root->l = multiply_rec(root->l, k, x);\n      update(root);\n      return\
    \ root;\n    }\n    if (k == sl) {\n      root = copy_node(root);\n      root->x\
    \ = Monoid::op(root->x, x);\n      update(root);\n      return root;\n    }\n\
    \    root = copy_node(root);\n    root->r = multiply_rec(root->r, k - (1 + sl),\
    \ x);\n    update(root);\n    return root;\n  }\n\n  X prod_rec(np root, u32 l,\
    \ u32 r, bool rev) {\n    if (l == 0 && r == root->size) {\n      return (rev\
    \ ? root->rev_prod : root->prod);\n    }\n    np left = (rev ? root->r : root->l);\n\
    \    np right = (rev ? root->l : root->r);\n    u32 sl = (left ? left->size :\
    \ 0);\n    X res = Monoid::unit();\n    if (l < sl) {\n      X y = prod_rec(left,\
    \ l, min(r, sl), rev ^ root->rev);\n      res = Monoid::op(res, y);\n    }\n \
    \   if (l <= sl && sl < r) res = Monoid::op(res, root->x);\n    u32 k = 1 + sl;\n\
    \    if (k < r) {\n      X y = prod_rec(right, max(k, l) - k, r - k, rev ^ root->rev);\n\
    \      res = Monoid::op(res, y);\n    }\n    return res;\n  }\n\n  X get_rec(np\
    \ root, u32 k, bool rev) {\n    np left = (rev ? root->r : root->l);\n    np right\
    \ = (rev ? root->l : root->r);\n    u32 sl = (left ? left->size : 0);\n    if\
    \ (k == sl) return root->x;\n    rev ^= root->rev;\n    if (k < sl) return get_rec(left,\
    \ k, rev);\n    return get_rec(right, k - (1 + sl), rev);\n  }\n\n  template <typename\
    \ F>\n  pair<np, np> split_max_right_rec(np root, const F &check, X &x) {\n  \
    \  if (!root) return {nullptr, nullptr};\n    prop(root);\n    root = copy_node(root);\n\
    \    X y = Monoid::op(x, root->prod);\n    if (check(y)) {\n      x = y;\n   \
    \   return {root, nullptr};\n    }\n    np left = root->l, right = root->r;\n\
    \    if (left) {\n      X y = Monoid::op(x, root->l->prod);\n      if (!check(y))\
    \ {\n        auto [n1, n2] = split_max_right_rec(left, check, x);\n        root->l\
    \ = n2;\n        update(root);\n        return {n1, root};\n      }\n      x =\
    \ y;\n    }\n    y = Monoid::op(x, root->x);\n    if (!check(y)) {\n      root->l\
    \ = nullptr;\n      update(root);\n      return {left, root};\n    }\n    x =\
    \ y;\n    auto [n1, n2] = split_max_right_rec(right, check, x);\n    root->r =\
    \ n1;\n    update(root);\n    return {root, n2};\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 7 \"test/mytest/rbst_test.test.cpp\"\
    \n\nvoid test() {\n  using Mono = Monoid_Min<int>;\n  RBST_Monoid<Mono, false,\
    \ 100> X;\n  FOR(1000) {\n    X.reset();\n    int N = RNG(1, 20);\n    int Q =\
    \ RNG(1, 1000);\n    vc<int> A(N);\n    FOR(i, N) A[i] = RNG(1, 100);\n    auto\
    \ root = X.new_node(A);\n\n    FOR(Q) {\n      int t = RNG(0, 5);\n      if (t\
    \ == 0) {\n        int i = RNG(0, N);\n        assert(A[i] == X.get(root, i));\n\
    \      }\n      if (t == 1) {\n        int i = RNG(0, N);\n        int x = RNG(1,\
    \ 100);\n        root = X.set(root, i, x);\n        A[i] = x;\n      }\n     \
    \ if (t == 2) {\n        int i = RNG(0, N);\n        int x = RNG(1, 100);\n  \
    \      root = X.multiply(root, i, x);\n        A[i] = Mono::op(A[i], x);\n   \
    \   }\n      if (t == 3) {\n        int L = RNG(0, N);\n        int R = RNG(0,\
    \ N);\n        if (L > R) swap(L, R);\n        ++R;\n        vc<int> B = {A.begin()\
    \ + L, A.begin() + R};\n        assert(X.prod(root, L, R) == MIN(B));\n      }\n\
    \      if (t == 4) {\n        int L = RNG(0, N);\n        int R = RNG(0, N);\n\
    \        if (L > R) swap(L, R);\n        ++R;\n        root = X.reverse(root,\
    \ L, R);\n        reverse(A.begin() + L, A.begin() + R);\n      }\n    }\n  }\n\
    }\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"alg/monoid/min.hpp\"\n#include \"ds/rbst/rbst_monoid.hpp\"\
    \n#include \"random/base.hpp\"\n\nvoid test() {\n  using Mono = Monoid_Min<int>;\n\
    \  RBST_Monoid<Mono, false, 100> X;\n  FOR(1000) {\n    X.reset();\n    int N\
    \ = RNG(1, 20);\n    int Q = RNG(1, 1000);\n    vc<int> A(N);\n    FOR(i, N) A[i]\
    \ = RNG(1, 100);\n    auto root = X.new_node(A);\n\n    FOR(Q) {\n      int t\
    \ = RNG(0, 5);\n      if (t == 0) {\n        int i = RNG(0, N);\n        assert(A[i]\
    \ == X.get(root, i));\n      }\n      if (t == 1) {\n        int i = RNG(0, N);\n\
    \        int x = RNG(1, 100);\n        root = X.set(root, i, x);\n        A[i]\
    \ = x;\n      }\n      if (t == 2) {\n        int i = RNG(0, N);\n        int\
    \ x = RNG(1, 100);\n        root = X.multiply(root, i, x);\n        A[i] = Mono::op(A[i],\
    \ x);\n      }\n      if (t == 3) {\n        int L = RNG(0, N);\n        int R\
    \ = RNG(0, N);\n        if (L > R) swap(L, R);\n        ++R;\n        vc<int>\
    \ B = {A.begin() + L, A.begin() + R};\n        assert(X.prod(root, L, R) == MIN(B));\n\
    \      }\n      if (t == 4) {\n        int L = RNG(0, N);\n        int R = RNG(0,\
    \ N);\n        if (L > R) swap(L, R);\n        ++R;\n        root = X.reverse(root,\
    \ L, R);\n        reverse(A.begin() + L, A.begin() + R);\n      }\n    }\n  }\n\
    }\n\nvoid solve() {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  test();\n\
    \  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - alg/monoid/min.hpp
  - ds/rbst/rbst_monoid.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/rbst_test.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 23:08:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/rbst_test.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/rbst_test.test.cpp
- /verify/test/mytest/rbst_test.test.cpp.html
title: test/mytest/rbst_test.test.cpp
---
