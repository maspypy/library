---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: nt/stern_brocot_tree.hpp
    title: nt/stern_brocot_tree.hpp
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
  bundledCode: "#line 1 \"test/mytest/stern_brocot.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\n#pragma\
    \ GCC optimize(\"Ofast\")\n#pragma GCC optimize(\"unroll-loops\")\n\n#include\
    \ <bits/stdc++.h>\n\nusing namespace std;\n\nusing ll = long long;\nusing pi =\
    \ pair<ll, ll>;\nusing vi = vector<ll>;\nusing u32 = unsigned int;\nusing u64\
    \ = unsigned long long;\nusing i128 = __int128;\n\ntemplate <class T>\nusing vc\
    \ = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
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
    \ l, ll r) { return l + RNG_64() % (r - l); }\n#line 1 \"nt/stern_brocot_tree.hpp\"\
    \n\nstruct Stern_Brocot_Tree {\n  using PATH = vi; // \u306F\u3058\u3081\u306F\
    \ R\n\n  static tuple<PATH, pi, pi> get_path_and_range(pi x) {\n    PATH path;\n\
    \    pi l = {0, 1}, r = {1, 0};\n    pi m = {1, 1};\n    ll det_l = l.fi * x.se\
    \ - l.se * x.fi;\n    ll det_r = r.fi * x.se - r.se * x.fi;\n    ll det_m = det_l\
    \ + det_r;\n    while (1) {\n      if (det_m == 0) break;\n      ll k = ceil(-det_m,\
    \ det_r);\n      path.eb(k);\n      l = {l.fi + k * r.fi, l.se + k * r.se};\n\
    \      m = {l.fi + r.fi, l.se + r.se};\n      det_l += k * det_r;\n      det_m\
    \ += k * det_r;\n      if (det_m == 0) break;\n      k = ceil(det_m, -det_l);\n\
    \      path.eb(k);\n      r = {r.fi + k * l.fi, r.se + k * l.se};\n      m = {l.fi\
    \ + r.fi, l.se + r.se};\n      det_r += k * det_l;\n      det_m += k * det_l;\n\
    \    }\n    return {path, l, r};\n  }\n\n  static PATH get_path(pi x) {\n    auto\
    \ [path, l, r] = get_path_and_range(x);\n    return path;\n  }\n\n  static pair<pi,\
    \ pi> range(pi x) {\n    auto [path, l, r] = get_path_and_range(x);\n    return\
    \ {l, r};\n  }\n\n  // x in range(y)\n  static bool in_subtree(pi x, pi y) {\n\
    \    auto [l, r] = range(y);\n    bool ok_l = i128(x.fi) * l.se - i128(x.se) *\
    \ l.fi > 0;\n    bool ok_r = i128(r.fi) * x.se - i128(r.se) * x.fi > 0;\n    return\
    \ ok_l && ok_r;\n  }\n\n  template <typename T = ll>\n  static pair<T, T> from_path(PATH&\
    \ p) {\n    using P = pair<T, T>;\n    P l = {0, 1}, r = {1, 0};\n    FOR(i, len(p))\
    \ {\n      ll k = p[i];\n      if (i % 2 == 0) {\n        l.fi += T(k) * r.fi;\n\
    \        l.se += T(k) * r.se;\n      }\n      if (i % 2 == 1) {\n        r.fi\
    \ += T(k) * l.fi;\n        r.se += T(k) * l.se;\n      }\n    }\n    return {l.fi\
    \ + r.fi, l.se + r.se};\n  }\n\n  static pair<pi, pi> child(pi x) {\n    auto\
    \ [l, r] = range(x);\n    pi lc = {l.fi + x.fi, l.se + x.se};\n    pi rc = {x.fi\
    \ + r.fi, x.se + r.se};\n    return {lc, rc};\n  }\n\n  static pi LCA(pi x, pi\
    \ y) {\n    auto Px = get_path(x);\n    auto Py = get_path(y);\n    vi P;\n  \
    \  FOR(i, min(len(Px), len(Py))) {\n      ll k = min(Px[i], Py[i]);\n      P.eb(k);\n\
    \      if (k < Px[i] || k < Py[i]) break;\n    }\n    return from_path(P);\n \
    \ }\n\n  static pi LA(pi x, ll dep) {\n    pi l = {0, 1}, r = {1, 0};\n    pi\
    \ m = {1, 1};\n    ll det_l = l.fi * x.se - l.se * x.fi;\n    ll det_r = r.fi\
    \ * x.se - r.se * x.fi;\n    ll det_m = det_l + det_r;\n    while (1) {\n    \
    \  if (det_m == 0 || dep == 0) break;\n      ll k = min(dep, ceil(-det_m, det_r));\n\
    \      l = {l.fi + k * r.fi, l.se + k * r.se};\n      m = {l.fi + r.fi, l.se +\
    \ r.se};\n      det_l += k * det_r;\n      det_m += k * det_r;\n      dep -= k;\n\
    \      if (det_m == 0 || dep == 0) break;\n      k = min(dep, ceil(det_m, -det_l));\n\
    \      r = {r.fi + k * l.fi, r.se + k * l.se};\n      m = {l.fi + r.fi, l.se +\
    \ r.se};\n      det_r += k * det_l;\n      det_m += k * det_l;\n      dep -= k;\n\
    \    }\n    if (dep == 0) return m;\n    return {-1, -1};\n  }\n\n  static string\
    \ to_string(PATH& p) {\n    string res;\n    char c = 'L';\n    for (auto&& x:\
    \ p) {\n      c = 'L' + 'R' - c;\n      if (x == 0) continue;\n      res += c;\n\
    \      res += \" \" + std::to_string(x);\n    }\n    return res;\n  }\n};\n#line\
    \ 6 \"test/mytest/stern_brocot.test.cpp\"\n\nvoid test() {\n  using SBT = Stern_Brocot_Tree;\n\
    \  // get_path\n  assert(SBT::get_path({1, 1}) == vi());\n  assert(SBT::get_path({1,\
    \ 2}) == vi({0, 1}));\n  assert(SBT::get_path({2, 1}) == vi({1}));\n  assert(SBT::get_path({1,\
    \ 3}) == vi({0, 2}));\n  assert(SBT::get_path({2, 3}) == vi({0, 1, 1}));\n  assert(SBT::get_path({3,\
    \ 2}) == vi({1, 1}));\n  assert(SBT::get_path({3, 1}) == vi({2}));\n  assert(SBT::get_path({1,\
    \ 4}) == vi({0, 3}));\n  assert(SBT::get_path({2, 5}) == vi({0, 2, 1}));\n  assert(SBT::get_path({3,\
    \ 5}) == vi({0, 1, 1, 1}));\n  assert(SBT::get_path({3, 4}) == vi({0, 1, 2}));\n\
    \  assert(SBT::get_path({4, 3}) == vi({1, 2}));\n  assert(SBT::get_path({5, 3})\
    \ == vi({1, 1, 1}));\n  assert(SBT::get_path({5, 2}) == vi({2, 1}));\n  assert(SBT::get_path({4,\
    \ 1}) == vi({3}));\n  // range\n  assert(SBT::range({1, 1}) == mp(pi{0, 1}, pi{1,\
    \ 0}));\n  assert(SBT::range({1, 2}) == mp(pi{0, 1}, pi{1, 1}));\n  assert(SBT::range({2,\
    \ 1}) == mp(pi{1, 1}, pi{1, 0}));\n  assert(SBT::range({1, 3}) == mp(pi{0, 1},\
    \ pi{1, 2}));\n  assert(SBT::range({2, 3}) == mp(pi{1, 2}, pi{1, 1}));\n  assert(SBT::range({3,\
    \ 2}) == mp(pi{1, 1}, pi{2, 1}));\n  assert(SBT::range({3, 1}) == mp(pi{2, 1},\
    \ pi{1, 0}));\n  assert(SBT::range({1, 4}) == mp(pi{0, 1}, pi{1, 3}));\n  assert(SBT::range({2,\
    \ 5}) == mp(pi{1, 3}, pi{1, 2}));\n  assert(SBT::range({3, 5}) == mp(pi{1, 2},\
    \ pi{2, 3}));\n  assert(SBT::range({3, 4}) == mp(pi{2, 3}, pi{1, 1}));\n  assert(SBT::range({4,\
    \ 3}) == mp(pi{1, 1}, pi{3, 2}));\n  assert(SBT::range({5, 3}) == mp(pi{3, 2},\
    \ pi{2, 1}));\n  assert(SBT::range({5, 2}) == mp(pi{2, 1}, pi{3, 1}));\n  assert(SBT::range({4,\
    \ 1}) == mp(pi{3, 1}, pi{1, 0}));\n  // child\n  assert(SBT::child({1, 1}) ==\
    \ mp(pi{1, 2}, pi{2, 1}));\n  assert(SBT::child({1, 2}) == mp(pi{1, 3}, pi{2,\
    \ 3}));\n  assert(SBT::child({2, 1}) == mp(pi{3, 2}, pi{3, 1}));\n  assert(SBT::child({1,\
    \ 3}) == mp(pi{1, 4}, pi{2, 5}));\n  assert(SBT::child({2, 3}) == mp(pi{3, 5},\
    \ pi{3, 4}));\n  assert(SBT::child({3, 2}) == mp(pi{4, 3}, pi{5, 3}));\n  assert(SBT::child({3,\
    \ 1}) == mp(pi{5, 2}, pi{4, 1}));\n  // la\n  pi NG = {-1, -1};\n  assert(SBT::LA({1,\
    \ 1}, 0) == pi({1, 1}));\n  assert(SBT::LA({1, 1}, 1) == NG);\n  assert(SBT::LA({3,\
    \ 4}, 0) == pi({1, 1}));\n  assert(SBT::LA({3, 4}, 1) == pi({1, 2}));\n  assert(SBT::LA({3,\
    \ 4}, 2) == pi({2, 3}));\n  assert(SBT::LA({3, 4}, 3) == pi({3, 4}));\n  assert(SBT::LA({3,\
    \ 4}, 4) == NG);\n  assert(SBT::LA({3, 5}, 0) == pi({1, 1}));\n  assert(SBT::LA({3,\
    \ 5}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 5}, 2) == pi({2, 3}));\n  assert(SBT::LA({3,\
    \ 5}, 3) == pi({3, 5}));\n  assert(SBT::LA({3, 5}, 4) == NG);\n\n  auto get_random\
    \ = [&]() -> pi {\n    while (1) {\n      ll x = RNG(1, 1LL << 60);\n      ll\
    \ y = RNG(1, 1LL << 60);\n      if (gcd(x, y) > 1) continue;\n      return {x,\
    \ y};\n    }\n  };\n\n  FOR(10000) {\n    pi x = get_random();\n    auto [l, r]\
    \ = SBT::range(x);\n    assert(i128(x.fi) * l.se - i128(x.se) * l.fi == 1);\n\
    \    assert(i128(r.fi) * x.se - i128(r.se) * x.fi == 1);\n    assert(l.fi + r.fi\
    \ == x.fi && l.se + r.se == x.se);\n    tie(l, r) = SBT::child(x);\n    assert(i128(x.fi)\
    \ * l.se - i128(x.se) * l.fi == 1);\n    assert(i128(r.fi) * x.se - i128(r.se)\
    \ * x.fi == 1);\n    auto P = SBT::get_path(x);\n    assert(SBT::from_path<ll>(P)\
    \ == x);\n    pi y = get_random();\n    pi z = SBT::LCA(x, y);\n    assert(SBT::in_subtree(x,\
    \ z));\n    assert(SBT::in_subtree(y, z));\n    tie(l, r) = SBT::child(z);\n \
    \   assert(!SBT::in_subtree(x, l) || !SBT::in_subtree(y, l));\n    assert(!SBT::in_subtree(x,\
    \ r) || !SBT::in_subtree(y, r));\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a\
    \ + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"random/base.hpp\"\n#include \"nt/stern_brocot_tree.hpp\"\
    \n\nvoid test() {\n  using SBT = Stern_Brocot_Tree;\n  // get_path\n  assert(SBT::get_path({1,\
    \ 1}) == vi());\n  assert(SBT::get_path({1, 2}) == vi({0, 1}));\n  assert(SBT::get_path({2,\
    \ 1}) == vi({1}));\n  assert(SBT::get_path({1, 3}) == vi({0, 2}));\n  assert(SBT::get_path({2,\
    \ 3}) == vi({0, 1, 1}));\n  assert(SBT::get_path({3, 2}) == vi({1, 1}));\n  assert(SBT::get_path({3,\
    \ 1}) == vi({2}));\n  assert(SBT::get_path({1, 4}) == vi({0, 3}));\n  assert(SBT::get_path({2,\
    \ 5}) == vi({0, 2, 1}));\n  assert(SBT::get_path({3, 5}) == vi({0, 1, 1, 1}));\n\
    \  assert(SBT::get_path({3, 4}) == vi({0, 1, 2}));\n  assert(SBT::get_path({4,\
    \ 3}) == vi({1, 2}));\n  assert(SBT::get_path({5, 3}) == vi({1, 1, 1}));\n  assert(SBT::get_path({5,\
    \ 2}) == vi({2, 1}));\n  assert(SBT::get_path({4, 1}) == vi({3}));\n  // range\n\
    \  assert(SBT::range({1, 1}) == mp(pi{0, 1}, pi{1, 0}));\n  assert(SBT::range({1,\
    \ 2}) == mp(pi{0, 1}, pi{1, 1}));\n  assert(SBT::range({2, 1}) == mp(pi{1, 1},\
    \ pi{1, 0}));\n  assert(SBT::range({1, 3}) == mp(pi{0, 1}, pi{1, 2}));\n  assert(SBT::range({2,\
    \ 3}) == mp(pi{1, 2}, pi{1, 1}));\n  assert(SBT::range({3, 2}) == mp(pi{1, 1},\
    \ pi{2, 1}));\n  assert(SBT::range({3, 1}) == mp(pi{2, 1}, pi{1, 0}));\n  assert(SBT::range({1,\
    \ 4}) == mp(pi{0, 1}, pi{1, 3}));\n  assert(SBT::range({2, 5}) == mp(pi{1, 3},\
    \ pi{1, 2}));\n  assert(SBT::range({3, 5}) == mp(pi{1, 2}, pi{2, 3}));\n  assert(SBT::range({3,\
    \ 4}) == mp(pi{2, 3}, pi{1, 1}));\n  assert(SBT::range({4, 3}) == mp(pi{1, 1},\
    \ pi{3, 2}));\n  assert(SBT::range({5, 3}) == mp(pi{3, 2}, pi{2, 1}));\n  assert(SBT::range({5,\
    \ 2}) == mp(pi{2, 1}, pi{3, 1}));\n  assert(SBT::range({4, 1}) == mp(pi{3, 1},\
    \ pi{1, 0}));\n  // child\n  assert(SBT::child({1, 1}) == mp(pi{1, 2}, pi{2, 1}));\n\
    \  assert(SBT::child({1, 2}) == mp(pi{1, 3}, pi{2, 3}));\n  assert(SBT::child({2,\
    \ 1}) == mp(pi{3, 2}, pi{3, 1}));\n  assert(SBT::child({1, 3}) == mp(pi{1, 4},\
    \ pi{2, 5}));\n  assert(SBT::child({2, 3}) == mp(pi{3, 5}, pi{3, 4}));\n  assert(SBT::child({3,\
    \ 2}) == mp(pi{4, 3}, pi{5, 3}));\n  assert(SBT::child({3, 1}) == mp(pi{5, 2},\
    \ pi{4, 1}));\n  // la\n  pi NG = {-1, -1};\n  assert(SBT::LA({1, 1}, 0) == pi({1,\
    \ 1}));\n  assert(SBT::LA({1, 1}, 1) == NG);\n  assert(SBT::LA({3, 4}, 0) == pi({1,\
    \ 1}));\n  assert(SBT::LA({3, 4}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 4},\
    \ 2) == pi({2, 3}));\n  assert(SBT::LA({3, 4}, 3) == pi({3, 4}));\n  assert(SBT::LA({3,\
    \ 4}, 4) == NG);\n  assert(SBT::LA({3, 5}, 0) == pi({1, 1}));\n  assert(SBT::LA({3,\
    \ 5}, 1) == pi({1, 2}));\n  assert(SBT::LA({3, 5}, 2) == pi({2, 3}));\n  assert(SBT::LA({3,\
    \ 5}, 3) == pi({3, 5}));\n  assert(SBT::LA({3, 5}, 4) == NG);\n\n  auto get_random\
    \ = [&]() -> pi {\n    while (1) {\n      ll x = RNG(1, 1LL << 60);\n      ll\
    \ y = RNG(1, 1LL << 60);\n      if (gcd(x, y) > 1) continue;\n      return {x,\
    \ y};\n    }\n  };\n\n  FOR(10000) {\n    pi x = get_random();\n    auto [l, r]\
    \ = SBT::range(x);\n    assert(i128(x.fi) * l.se - i128(x.se) * l.fi == 1);\n\
    \    assert(i128(r.fi) * x.se - i128(r.se) * x.fi == 1);\n    assert(l.fi + r.fi\
    \ == x.fi && l.se + r.se == x.se);\n    tie(l, r) = SBT::child(x);\n    assert(i128(x.fi)\
    \ * l.se - i128(x.se) * l.fi == 1);\n    assert(i128(r.fi) * x.se - i128(r.se)\
    \ * x.fi == 1);\n    auto P = SBT::get_path(x);\n    assert(SBT::from_path<ll>(P)\
    \ == x);\n    pi y = get_random();\n    pi z = SBT::LCA(x, y);\n    assert(SBT::in_subtree(x,\
    \ z));\n    assert(SBT::in_subtree(y, z));\n    tie(l, r) = SBT::child(z);\n \
    \   assert(!SBT::in_subtree(x, l) || !SBT::in_subtree(y, l));\n    assert(!SBT::in_subtree(x,\
    \ r) || !SBT::in_subtree(y, r));\n  }\n}\n\nvoid solve() {\n  LL(a, b);\n  print(a\
    \ + b);\n}\n\nsigned main() {\n  test();\n  solve();\n\n  return 0;\n}"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - random/base.hpp
  - nt/stern_brocot_tree.hpp
  isVerificationFile: true
  path: test/mytest/stern_brocot.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 18:57:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/stern_brocot.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/stern_brocot.test.cpp
- /verify/test/mytest/stern_brocot.test.cpp.html
title: test/mytest/stern_brocot.test.cpp
---
