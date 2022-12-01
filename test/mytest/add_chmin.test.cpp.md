---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: alg/monoid/add_chmin.hpp
    title: alg/monoid/add_chmin.hpp
  - icon: ':question:'
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
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/mytest/add_chmin.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\
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
    \ \"other/io.hpp\"\nnamespace fastio { // https://nyaannyaan.github.io/library/misc/fastio.hpp\r\
    \nstatic constexpr int SZ = 1 << 17;\r\nchar inbuf[SZ], outbuf[SZ];\r\nint in_left\
    \ = 0, in_right = 0, out_right = 0;\r\n\r\nstruct Pre {\r\n  char num[40000];\r\
    \n  constexpr Pre() : num() {\r\n    for (int i = 0; i < 10000; i++) {\r\n   \
    \   int n = i;\r\n      for (int j = 3; j >= 0; j--) {\r\n        num[i * 4 +\
    \ j] = n % 10 + '0';\r\n        n /= 10;\r\n      }\r\n    }\r\n  }\r\n} constexpr\
    \ pre;\r\n\r\ninline void load() {\r\n  int len = in_right - in_left;\r\n  memmove(inbuf,\
    \ inbuf + in_left, len);\r\n  in_right = len + fread(inbuf + len, 1, SZ - len,\
    \ stdin);\r\n  in_left = 0;\r\n}\r\n\r\ninline void flush() {\r\n  fwrite(outbuf,\
    \ 1, out_right, stdout);\r\n  out_right = 0;\r\n}\r\n\r\ninline void skip_space()\
    \ {\r\n  if (in_left + 32 > in_right) load();\r\n  while (inbuf[in_left] <= '\
    \ ') in_left++;\r\n}\r\n\r\ninline void read(char &c) {\r\n  if (in_left + 32\
    \ > in_right) load();\r\n  c = inbuf[in_left++];\r\n}\r\ntemplate <typename T>\r\
    \ninline void read(T &x) {\r\n  if (in_left + 32 > in_right) load();\r\n  char\
    \ c;\r\n  do\r\n    c = inbuf[in_left++];\r\n  while (c < '-');\r\n  [[maybe_unused]]\
    \ bool minus = false;\r\n  if constexpr (is_signed<T>::value == true) {\r\n  \
    \  if (c == '-') minus = true, c = inbuf[in_left++];\r\n  }\r\n  x = 0;\r\n  while\
    \ (c >= '0') {\r\n    x = x * 10 + (c & 15);\r\n    c = inbuf[in_left++];\r\n\
    \  }\r\n  if constexpr (is_signed<T>::value == true) {\r\n    if (minus) x = -x;\r\
    \n  }\r\n}\r\ninline void read() {}\r\ntemplate <typename Head, typename... Tail>\r\
    \ninline void read(Head &head, Tail &... tail) {\r\n  read(head);\r\n  read(tail...);\r\
    \n}\r\n\r\ninline void write(char c) {\r\n  if (out_right > SZ - 32) flush();\r\
    \n  outbuf[out_right++] = c;\r\n}\r\ninline void write(bool b) {\r\n  if (out_right\
    \ > SZ - 32) flush();\r\n  outbuf[out_right++] = b ? '1' : '0';\r\n}\r\ninline\
    \ void write(const string &s) {\r\n  if (out_right + s.size() > SZ - 32) flush();\r\
    \n  memcpy(outbuf + out_right, s.data(), sizeof(char) * s.size());\r\n  out_right\
    \ += s.size();\r\n}\r\ntemplate <typename T>\r\ninline void write(T x) {\r\n \
    \ if (out_right > SZ - 32) flush();\r\n  if (!x) {\r\n    outbuf[out_right++]\
    \ = '0';\r\n    return;\r\n  }\r\n  if constexpr (is_signed<T>::value == true)\
    \ {\r\n    if (x < 0) outbuf[out_right++] = '-', x = -x;\r\n  }\r\n  int i = 12;\r\
    \n  char buf[16];\r\n  while (x >= 10000) {\r\n    memcpy(buf + i, pre.num + (x\
    \ % 10000) * 4, 4);\r\n    x /= 10000;\r\n    i -= 4;\r\n  }\r\n  if (x < 100)\
    \ {\r\n    if (x < 10) {\r\n      outbuf[out_right] = '0' + x;\r\n      ++out_right;\r\
    \n    } else {\r\n      uint32_t q = (uint32_t(x) * 205) >> 11;\r\n      uint32_t\
    \ r = uint32_t(x) - q * 10;\r\n      outbuf[out_right] = '0' + q;\r\n      outbuf[out_right\
    \ + 1] = '0' + r;\r\n      out_right += 2;\r\n    }\r\n  } else {\r\n    if (x\
    \ < 1000) {\r\n      memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);\r\n\
    \      out_right += 3;\r\n    } else {\r\n      memcpy(outbuf + out_right, pre.num\
    \ + (x << 2), 4);\r\n      out_right += 4;\r\n    }\r\n  }\r\n  memcpy(outbuf\
    \ + out_right, buf + i + 4, 12 - i);\r\n  out_right += 12 - i;\r\n}\r\ninline\
    \ void write() {}\r\ntemplate <typename Head, typename... Tail>\r\ninline void\
    \ write(Head &&head, Tail &&... tail) {\r\n  write(head);\r\n  write(forward<Tail>(tail)...);\r\
    \n}\r\ntemplate <typename... Args>\r\ninline void writen(Args &&... x) {\r\n \
    \ write(forward<Args>(x)...);\r\n  write('\\n');\r\n}\r\n\r\nstruct Dummy {\r\n\
    \  Dummy() { atexit(flush); }\r\n} dummy;\r\n} // namespace fastio\r\n\r\nvoid\
    \ print() { fastio::write('\\n'); }\r\ntemplate <class Head, class... Tail>\r\n\
    void print(Head &&head, Tail &&... tail) {\r\n  fastio::write(head);\r\n  if (sizeof...(Tail))\
    \ fastio::write(' ');\r\n  print(forward<Tail>(tail)...);\r\n}\r\n\r\nvoid read()\
    \ {}\r\ntemplate <class Head, class... Tail>\r\nvoid read(Head &head, Tail &...\
    \ tail) {\r\n  fastio::read(head);\r\n  read(tail...);\r\n}\r\n\r\n#define INT(...)\
    \   \\\r\n  int __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define LL(...)   \\\
    \r\n  ll __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define STR(...)      \\\r\n\
    \  string __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define CHAR(...)   \\\r\n\
    \  char __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n#define DBL(...)      \\\r\n\
    \  double __VA_ARGS__; \\\r\n  read(__VA_ARGS__)\r\n\r\n#define VEC(type, name,\
    \ size) \\\r\n  vector<type> name(size);    \\\r\n  read(name)\r\n#define VV(type,\
    \ name, h, w)                     \\\r\n  vector<vector<type>> name(h, vector<type>(w));\
    \ \\\r\n  read(name)\r\n\r\nvoid YES(bool t = 1) { print<string>(t ? \"YES\" :\
    \ \"NO\"); }\r\nvoid NO(bool t = 1) { YES(!t); }\r\nvoid Yes(bool t = 1) { print<string>(t\
    \ ? \"Yes\" : \"No\"); }\r\nvoid No(bool t = 1) { Yes(!t); }\r\nvoid yes(bool\
    \ t = 1) { print<string>(t ? \"yes\" : \"no\"); }\r\nvoid no(bool t = 1) { yes(!t);\
    \ }\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n   \
    \   = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n                 \
    \    chrono::high_resolution_clock::now().time_since_epoch())\n              \
    \       .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return\
    \ x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll\
    \ l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"alg/monoid/add_chmin.hpp\"\
    \n\n// min(x+a,b) \u3068\u8868\u305B\u308B\u95A2\u6570\u306E\u5408\u6210\ntemplate\
    \ <typename E>\nstruct Monoid_Add_Chmin {\n  using value_type = pair<E, E>;\n\
    \  using X = value_type;\n  static constexpr E R_INF = numeric_limits<E>::max();\n\
    \n  static X op(X x, X y) {\n    auto [a, b] = x;\n    auto [d, e] = y;\n    a\
    \ = a + d;\n    b = (b == R_INF ? b : b + d);\n    b = min(b, e);\n    return\
    \ {a, b};\n  }\n\n  static E eval(X f, E x) { return min(x + f.fi, f.se); }\n\n\
    \  static X add(E a) { return {a, R_INF}; }\n  static X chmin(E b) { return {0,\
    \ b}; }\n\n  static constexpr X unit() { return {0, R_INF}; }\n  static constexpr\
    \ bool commute = 0;\n};\n#line 6 \"test/mytest/add_chmin.test.cpp\"\n\nvoid test()\
    \ {\n  int N = RNG(1, 100);\n  vc<int> X(N);\n  FOR(i, N) X[i] = RNG(-100, 100);\n\
    \  vc<int> Y = X;\n  int Q = RNG(0, 10);\n  using Mono = Monoid_Add_Chmin<int>;\n\
    \  using F = typename Mono::value_type;\n  F f = Mono::unit();\n\n  FOR(Q) {\n\
    \    int t = RNG(0, 3);\n    int a = RNG(-100, 100);\n    if (t == 0) {\n    \
    \  FOR(i, N) Y[i] += a;\n      f = Mono::op(f, Mono::add(a));\n    }\n    if (t\
    \ == 1) {\n      FOR(i, N) chmin(Y[i], a);\n      f = Mono::op(f, Mono::chmin(a));\n\
    \    }\n  }\n  FOR(i, N) assert(Y[i] == Mono::eval(f, X[i]));\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  FOR(100) test();\n\
    \  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include \"alg/monoid/add_chmin.hpp\"\
    \n\nvoid test() {\n  int N = RNG(1, 100);\n  vc<int> X(N);\n  FOR(i, N) X[i] =\
    \ RNG(-100, 100);\n  vc<int> Y = X;\n  int Q = RNG(0, 10);\n  using Mono = Monoid_Add_Chmin<int>;\n\
    \  using F = typename Mono::value_type;\n  F f = Mono::unit();\n\n  FOR(Q) {\n\
    \    int t = RNG(0, 3);\n    int a = RNG(-100, 100);\n    if (t == 0) {\n    \
    \  FOR(i, N) Y[i] += a;\n      f = Mono::op(f, Mono::add(a));\n    }\n    if (t\
    \ == 1) {\n      FOR(i, N) chmin(Y[i], a);\n      f = Mono::op(f, Mono::chmin(a));\n\
    \    }\n  }\n  FOR(i, N) assert(Y[i] == Mono::eval(f, X[i]));\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cin.tie(nullptr);\n\
    \  ios::sync_with_stdio(false);\n  cout << setprecision(15);\n\n  FOR(100) test();\n\
    \  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - alg/monoid/add_chmin.hpp
  isVerificationFile: true
  path: test/mytest/add_chmin.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 18:57:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/add_chmin.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/add_chmin.test.cpp
- /verify/test/mytest/add_chmin.test.cpp.html
title: test/mytest/add_chmin.test.cpp
---
