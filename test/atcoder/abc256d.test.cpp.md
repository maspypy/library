---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':x:'
    path: ds/intervals.hpp
    title: ds/intervals.hpp
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
    PROBLEM: https://atcoder.jp/contests/abc256/tasks/abc256_d
    links:
    - https://atcoder.jp/contests/abc256/tasks/abc256_d
  bundledCode: "#line 1 \"test/atcoder/abc256d.test.cpp\"\n#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_d\"\
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
    \ t = 1) { yes(!t); }\r\n#line 1 \"ds/intervals.hpp\"\n// https://codeforces.com/contest/1638/problem/E\n\
    // https://codeforces.com/contest/897/problem/E\n// \u6301\u3064\u5024\u306E\u30BF\
    \u30A4\u30D7 T\u3001\u5EA7\u6A19\u30BF\u30A4\u30D7 X\n// \u30B3\u30F3\u30B9\u30C8\
    \u30E9\u30AF\u30BF\u3067\u306F T none_val \u3092\u6307\u5B9A\u3059\u308B\ntemplate\
    \ <typename T = ll, typename X = ll>\nstruct Intervals {\n  static constexpr X\
    \ LLIM = numeric_limits<X>::lowest();\n  static constexpr X RLIM = numeric_limits<X>::max();\n\
    \  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\u500B\
    \u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  X total_len;\n  map<X,\
    \ T> dat;\n\n  Intervals(T none_val) : none_val(none_val), total_num(0), total_len(0)\
    \ {\n    dat[LLIM] = none_val;\n    dat[RLIM] = none_val;\n  }\n\n  tuple<X, X,\
    \ T> get(X x) {\n    auto it = dat.upper_bound(x);\n    X r = (*it).fi;\n    auto\
    \ [l, t] = *prev(it);\n    return {l, r, t};\n  }\n\n  template <typename ADD,\
    \ typename RM>\n  void set(X L, X R, T t, ADD& add_f, RM& rm_f) {\n    if (L ==\
    \ R) return;\n    assert(L < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\
    \u66F4\u3059\u308B\n    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\
    \u308A\u5408\u3046\u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<X, X, T>>\
    \ tmp;\n    auto it = prev(dat.lower_bound(L));\n    while (1) {\n      auto [l,\
    \ t] = *it;\n      if (R < l) break;\n      it = next(it);\n      X r = (*it).fi;\n\
    \      tmp.eb(l, r, t);\n    }\n    auto [lx, _, lt] = tmp[0];\n    auto [__,\
    \ rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\u3048\u305A\u5168\u90E8\u524A\
    \u9664\n    for (auto&& [l, r, t]: tmp) {\n      dat.erase(l);\n      if (t ==\
    \ none_val) continue;\n      total_num--;\n      total_len -= r - l;\n      rm_f(l,\
    \ r, t);\n    }\n    if (lt == t) chmin(L, lx);\n    if (rt == t) chmax(R, rx);\n\
    \    if (lx < L) {\n      // [lx, L)\n      dat[lx] = lt;\n      if (lt != none_val)\
    \ {\n        total_num++;\n        total_len += L - lx;\n        add_f(lx, L,\
    \ lt);\n      }\n    }\n    if (R < rx) {\n      // [R, rx)\n      dat[R] = rt;\n\
    \      if (rt != none_val) {\n        total_num++;\n        total_len += rx -\
    \ R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    dat[L] = t;\n\
    \    if (t != none_val) {\n      total_num++;\n      total_len += R - L;\n   \
    \   add_f(L, R, t);\n    }\n  }\n\n  void set(X L, X R, T t = 1) {\n    auto f\
    \ = [&](X L, X R, T t) -> void {};\n    set(L, R, t, f, f);\n  }\n\n  void erase(X\
    \ L, X R) {\n    auto f = [&](X L, X R, T t) -> void {};\n    set(L, R, none_val,\
    \ f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\u30BF (l, r, t) \u3092\u5168\
    \u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<X, X, T>> get(X L, X R) {\n    vc<tuple<X,\
    \ X, T>> res;\n    auto it = dat.lower_bound(L);\n    if(it != dat.begin()) it\
    \ = prev(it);\n    while (1) {\n      auto [l, t] = *it;\n      if (R <= l) break;\n\
    \      it = next(it);\n      X r = (*it).fi;\n      X l0 = max(l, L);\n      X\
    \ r0 = min(r, R);\n      if (l0 < r0) res.eb(l0, r0, t);\n    }\n    return res;\n\
    \  }\n\n  vc<tuple<X, X, T>> get_all() {\n    return get(LLIM, RLIM);\n  }\n\n\
    \  void debug() {\n    auto it = dat.begin();\n    print(\"Intervals\");\n   \
    \ print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n   \
    \ while (1) {\n      auto [l, t] = *it;\n      ++it;\n      if (it == dat.end())\
    \ break;\n      X r = (*it).fi;\n      print(\"l, r, t\", l, r, t);\n    }\n \
    \ }\n};\n\n\n#line 1 \"ds/fastset.hpp\"\n/* 64\u5206\u6728\u3002\r\ninsert, erase\r\
    \n[]\u3067\u306E\u5B58\u5728\u5224\u5B9A\r\nnext, prev\r\n*/\r\nstruct FastSet\
    \ {\r\n  using uint = unsigned;\r\n  using ull = unsigned long long;\r\n\r\n \
    \ int bsr(ull x) { return 63 - __builtin_clzll(x); }\r\n  int bsf(ull x) { return\
    \ __builtin_ctzll(x); }\r\n\r\n  static constexpr uint B = 64;\r\n  int n, lg;\r\
    \n  vector<vector<ull>> seg;\r\n  FastSet(int _n) : n(_n) {\r\n    do {\r\n  \
    \    seg.push_back(vector<ull>((_n + B - 1) / B));\r\n      _n = (_n + B - 1)\
    \ / B;\r\n    } while (_n > 1);\r\n    lg = int(seg.size());\r\n  }\r\n  bool\
    \ operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }\r\n\
    \  void insert(int i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i\
    \ / B] |= 1ULL << (i % B);\r\n      i /= B;\r\n    }\r\n  }\r\n  void erase(int\
    \ i) {\r\n    for (int h = 0; h < lg; h++) {\r\n      seg[h][i / B] &= ~(1ULL\
    \ << (i % B));\r\n      if (seg[h][i / B]) break;\r\n      i /= B;\r\n    }\r\n\
    \  }\r\n\r\n  // x\u4EE5\u4E0A\u6700\u5C0F\u306E\u8981\u7D20\u3092\u8FD4\u3059\
    \u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 n\u3002\r\n  int next(int i)\
    \ {\r\n    for (int h = 0; h < lg; h++) {\r\n      if (i / B == seg[h].size())\
    \ break;\r\n      ull d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n   \
    \     i = i / B + 1;\r\n        continue;\r\n      }\r\n      // find\r\n    \
    \  i += bsf(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\
    \n        i += bsf(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n\
    \    return n;\r\n  }\r\n\r\n  // x\u4EE5\u4E0B\u6700\u5927\u306E\u8981\u7D20\u3092\
    \u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1\u3002\r\n  int\
    \ prev(int i) {\r\n    if (i < 0) return -1;\r\n    if (i >= n) i = n - 1;\r\n\
    \    for (int h = 0; h < lg; h++) {\r\n      if (i == -1) break;\r\n      ull\
    \ d = seg[h][i / B] << (63 - i % 64);\r\n      if (!d) {\r\n        i = i / B\
    \ - 1;\r\n        continue;\r\n      }\r\n      // find\r\n      i += bsr(d) -\
    \ (B - 1);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n\
    \        i += bsr(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n \
    \   return -1;\r\n  }\r\n\r\n  // [l, r) \u5185\u306E\u8981\u7D20\u3092\u5168\u90E8\
    \u96C6\u3081\u308B\r\n  vector<int> collect(int l, int r) {\r\n    vector<int>\
    \ res;\r\n    int x = l - 1;\r\n    while (1) {\r\n      x = next(x + 1);\r\n\
    \      if (x >= r) break;\r\n      res.emplace_back(x);\r\n    }\r\n    return\
    \ res;\r\n  }\r\n\r\n  void debug() {\r\n    string s;\r\n    for (int i = 0;\
    \ i < n; ++i) s += ((*this)[i] ? '1' : '0');\r\n    print(s);\r\n  }\r\n};\r\n\
    #line 129 \"ds/intervals.hpp\"\n\n// FastSet \u3067\u9AD8\u901F\u5316\u3057\u305F\
    \u3082\u306E\ntemplate <typename T>\nstruct Intervals_Fast {\n  const int LLIM,\
    \ RLIM;\n  const T none_val;\n  // none_val \u3067\u306A\u3044\u533A\u9593\u306E\
    \u500B\u6570\u3068\u9577\u3055\u5408\u8A08\n  int total_num;\n  int total_len;\n\
    \  vc<T> dat;\n  FastSet ss;\n\n  Intervals_Fast(int N, T none_val)\n      : LLIM(0),\n\
    \        RLIM(N),\n        none_val(none_val),\n        total_num(0),\n      \
    \  total_len(0),\n        dat(N, none_val),\n        ss(N + 1) {\n    ss.insert(0);\n\
    \    ss.insert(N);\n  }\n\n  tuple<int, int, T> get(int x) {\n    auto l = ss.prev(x);\n\
    \    auto r = ss.next(x + 1);\n    return {l, r, dat[l]};\n  }\n\n  template <typename\
    \ ADD, typename RM>\n  void set(int L, int R, T t, ADD& add_f, RM& rm_f) {\n \
    \   assert(LLIM <= L && L <= R && R <= RLIM);\n    if (L == R) return;\n    assert(L\
    \ < R);\n    // \u533A\u9593 [l, r) \u3092 t \u306B\u5909\u66F4\u3059\u308B\n\
    \    // \u307E\u305A\u306F\u3001\u91CD\u306A\u308B\u304B\u96A3\u308A\u5408\u3046\
    \u533A\u9593\u3092\u5168\u5217\u6319\n    vc<tuple<int, int, T>> tmp;\n    auto\
    \ l = ss.prev(L);\n    while (l < R) {\n      auto r = ss.next(l + 1);\n     \
    \ auto t = dat[l];\n      tmp.eb(l, r, t);\n      l = r;\n    }\n    auto [lx,\
    \ _, lt] = tmp[0];\n    auto [__, rx, rt] = tmp.back();\n    // \u3068\u308A\u3042\
    \u3048\u305A\u5168\u90E8\u524A\u9664\n    for (auto&& [l, r, t]: tmp) {\n    \
    \  ss.erase(l);\n      if (t == none_val) continue;\n      total_num--;\n    \
    \  total_len -= r - l;\n      rm_f(l, r, t);\n    }\n    if (lt == t) chmin(L,\
    \ lx);\n    if (rt == t) chmax(R, rx);\n    if (lx < L) {\n      // [lx, L)\n\
    \      ss.insert(lx);\n      dat[lx] = lt;\n      if (lt != none_val) {\n    \
    \    total_num++;\n        total_len += L - lx;\n        add_f(lx, L, lt);\n \
    \     }\n    }\n    if (R < rx) {\n      // [R, rx)\n      ss.insert(R);\n   \
    \   dat[R] = rt;\n      if (rt != none_val) {\n        total_num++;\n        total_len\
    \ += rx - R;\n        add_f(R, rx, rt);\n      }\n    }\n    // [L, R)\n    ss.insert(L);\n\
    \    dat[L] = t;\n    if (t != none_val) {\n      total_num++;\n      total_len\
    \ += R - L;\n      add_f(L, R, t);\n    }\n  }\n\n  void set(int L, int R, T t)\
    \ {\n    auto f = [&](int L, int R, T t) -> void {};\n    set(L, R, t, f, f);\n\
    \  }\n\n  void erase(int L, int R) {\n    auto f = [&](int L, int R, T t) -> void\
    \ {};\n    set(L, R, none_val, f, f);\n  }\n\n  // L, R \u5185\u306E\u30C7\u30FC\
    \u30BF (l, r, t) \u3092\u5168\u90E8\u53D6\u5F97\u3059\u308B\n  vc<tuple<int, int,\
    \ T>> get(int L, int R) {\n    assert(LLIM <= L && L <= R && R <= RLIM);\n   \
    \ vc<tuple<int, int, T>> res;\n    auto l = ss.prev(L);\n    while (l < R) {\n\
    \      auto t = dat[l];\n      auto r = ss.next(l + 1);\n      int l0 = max(l,\
    \ L);\n      int r0 = min(r, R);\n      if (l0 < r0) res.eb(l0, r0, t);\n    \
    \  l = r;\n    }\n    return res;\n  }\n\n  vc<tuple<int, int, T>> get_all() {\
    \ return get(LLIM, RLIM); }\n\n  void debug() {\n    print(\"Intervals\");\n \
    \   print(\"total_num\", total_num);\n    print(\"total_len\", total_len);\n \
    \   int l = 0;\n    while (l < RLIM) {\n      auto t = dat[l];\n      auto r =\
    \ ss.next(l + 1);\n      print(\"l, r, t\", l, r, t);\n      l = r;\n    }\n \
    \ }\n};\n#line 5 \"test/atcoder/abc256d.test.cpp\"\n\nvoid solve() {\n  Intervals<ll,\
    \ int> I(0);\n  LL(N);\n  FOR(N) {\n    LL(l, r);\n    I.set(l, r, 1);\n  }\n\
    \  for (auto [l, r, x]: I.get_all()) {\n    if (x) print(l, r);\n  };\n}\n\nsigned\
    \ main() {\n  cout << fixed << setprecision(15);\n\n  ll T = 1;\n  // LL(T);\n\
    \  FOR(T) solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc256/tasks/abc256_d\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"ds/intervals.hpp\"\
    \n\nvoid solve() {\n  Intervals<ll, int> I(0);\n  LL(N);\n  FOR(N) {\n    LL(l,\
    \ r);\n    I.set(l, r, 1);\n  }\n  for (auto [l, r, x]: I.get_all()) {\n    if\
    \ (x) print(l, r);\n  };\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - ds/intervals.hpp
  - ds/fastset.hpp
  isVerificationFile: true
  path: test/atcoder/abc256d.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 21:30:40+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/atcoder/abc256d.test.cpp
layout: document
redirect_from:
- /verify/test/atcoder/abc256d.test.cpp
- /verify/test/atcoder/abc256d.test.cpp.html
title: test/atcoder/abc256d.test.cpp
---
