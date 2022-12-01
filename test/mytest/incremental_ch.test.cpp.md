---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':x:'
    path: geo/incremental_convexhull.hpp
    title: geo/incremental_convexhull.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':x:'
    path: other/io.hpp
    title: other/io.hpp
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
  bundledCode: "#line 1 \"test/mytest/incremental_ch.test.cpp\"\n#define PROBLEM \"\
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
    \ }\n#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n  T x, y;\n\
    \n  Point() = default;\n\n  template <typename A, typename B>\n  Point(A x, B\
    \ y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A, B>\
    \ p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x + p.x,\
    \ y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n\
    \  bool operator==(Point p) const { return x == p.x && y == p.y; }\n  Point operator-()\
    \ const { return {-x, -y}; }\n\n  bool operator<(Point p) const {\n    if (x !=\
    \ p.x) return x < p.x;\n    return y < p.y;\n  }\n\n  T dot(Point other) { return\
    \ x * other.x + y * other.y; }\n  T det(Point other) { return x * other.y - y\
    \ * other.x; }\n};\n\ntemplate <typename REAL, typename T>\nREAL dist(Point<T>\
    \ A, Point<T> B) {\n  A -= B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n}\n\
    \ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c)\
    \ : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y;\n\
    \    b = B.x - A.x;\n    c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T\
    \ x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename\
    \ U>\n  U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\n  template\
    \ <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n \
    \ bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }\n\n\
    \  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }\n\
    };\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T>\
    \ A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\
    \ntemplate <typename T>\nstruct Circle {\n  Point<T> O;\n  T r;\n  Circle(Point<T>\
    \ O, T r) : O(O), r(r) {}\n  Circle(T x, T y, T r) : O(Point<T>(x, y)), r(r) {}\n\
    };\n\ntemplate <typename T>\nstruct Polygon {\n  vc<Point<T>> points;\n  T a;\n\
    \n  template <typename A, typename B>\n  Polygon(vc<pair<A, B>> pairs) {\n   \
    \ for (auto&& [a, b]: pairs) points.eb(Point<T>(a, b));\n    build();\n  }\n \
    \ Polygon(vc<Point<T>> points) : points(points) { build(); }\n\n  int size() {\
    \ return len(points); }\n\n  template <typename REAL>\n  REAL area() {\n    return\
    \ a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value, int> = 0>\n\
    \  T area_2() {\n    return a;\n  }\n\n  bool is_convex() {\n    FOR(j, len(points))\
    \ {\n      int i = (j == 0 ? len(points) - 1 : j - 1);\n      int k = (j == len(points)\
    \ - 1 ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k] - points[j])\
    \ < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n  void build()\
    \ {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1 == len(points)\
    \ ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n    if (a < 0) {\n\
    \      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n#line 2 \"geo/incremental_convexhull.hpp\"\
    \n\n// \u4E0B\u5074\u51F8\u5305\ntemplate <typename T, bool strict = true>\nstruct\
    \ IncrementalConvexHull_Lower {\n  using P = Point<T>;\n  set<P> S;\n\n  IncrementalConvexHull_Lower()\
    \ {}\n\n  int size() { return len(S); }\n\n  template <typename ADD_V, typename\
    \ RM_V, typename ADD_E, typename RM_E>\n  void add(Point<T> p, ADD_V add_v, RM_V\
    \ rm_v, ADD_E add_e, RM_E rm_e) {\n    int s = side(p);\n    if (strict && s >=\
    \ 0) return;\n    if (!strict && s > 0) return;\n\n    // \u70B9\u8FFD\u52A0\n\
    \    add_v(p);\n    S.insert(p);\n\n    vc<P> left;\n    {\n      auto it = S.find(p);\n\
    \      while (it != S.begin()) {\n        --it;\n        if (left.empty()) {\n\
    \          left.eb(*it);\n          continue;\n        }\n        auto a = *it;\n\
    \        auto b = left.back();\n        T det = (b - a).det(p - a);\n        if\
    \ (strict && det > 0) break;\n        if (!strict && det >= 0) break;\n      \
    \  left.eb(a);\n      }\n    }\n\n    vc<P> right;\n    {\n      auto it = S.find(p);\n\
    \      while (1) {\n        ++it;\n        if (it == S.end()) break;\n       \
    \ if (right.empty()) {\n          right.eb(*it);\n          continue;\n      \
    \  }\n        auto a = right.back();\n        auto b = *it;\n        T det = (a\
    \ - p).det(b - p);\n        if (strict && det > 0) break;\n        if (!strict\
    \ && det >= 0) break;\n        right.eb(b);\n      }\n    }\n\n    // \u70B9\u524A\
    \u9664\n    if (len(left) > 1) { S.erase(next(S.find(left.back())), S.find(p));\
    \ }\n    if (len(right) > 1) { S.erase(next(S.find(p)), S.find(right.back()));\
    \ }\n    FOR(i, len(left) - 1) rm_v(left[i]);\n    FOR(i, len(right) - 1) rm_v(right[i]);\n\
    \n    // \u8FBA\u524A\u9664\n    if (len(left) && len(right)) {\n      auto a\
    \ = left[0], b = right[0];\n      rm_e(a, b);\n    }\n    FOR(i, len(left) - 1)\
    \ {\n      auto a = left[i + 1], b = left[i];\n      rm_e(a, b);\n    }\n    FOR(i,\
    \ len(right) - 1) {\n      auto a = right[i], b = right[i + 1];\n      rm_e(a,\
    \ b);\n    }\n    // \u8FBA\u8FFD\u52A0\n    if (len(left)) { add_e(left.back(),\
    \ p); }\n    if (len(right)) { add_e(p, right.back()); }\n  }\n\n  // \u4E2D\uFF1A\
    1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n  int side(Point<T> p) {\n    auto r =\
    \ S.lower_bound(p);\n    if (r == S.begin()) {\n      // \u5168\u90E8 p \u4EE5\
    \u4E0A\n      if (len(S) && (*r) == p) return 0;\n      return -1;\n    }\n  \
    \  if (r == S.end()) {\n      // p \u306F max \u3088\u308A\u5927\u304D\u3044\n\
    \      return -1;\n    }\n    auto l = prev(r);\n    auto p1 = *l, p2 = *r;\n\
    \    T det = (p - p1).det(p2 - p1);\n    if (det == 0) return 0;\n    return (det\
    \ > 0 ? -1 : 1);\n  }\n};\n\ntemplate <typename T, bool strict = true>\nstruct\
    \ Incremental_ConvexHull {\n  using P = Point<T>;\n  IncrementalConvexHull_Lower<T,\
    \ strict> LOWER, UPPER;\n  int cnt_E;\n  T det_sum;\n  bool is_empty;\n\n  Incremental_ConvexHull()\
    \ : cnt_E(0), det_sum(0), is_empty(1) {}\n\n  int size() { return cnt_E; }\n\n\
    \  bool empty() { return is_empty; }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return det_sum * 0.5;\n  }\n  T area_2() { return det_sum; }\n\n  template\
    \ <typename ADD_V, typename RM_V, typename ADD_E, typename RM_E>\n  void add(Point<T>\
    \ p, ADD_V add_v, RM_V rm_v, ADD_E add_e, RM_E rm_e) {\n    is_empty = 0;\n  \
    \  LOWER.add(\n        p, add_v, rm_v,\n        [&](Point<T> a, Point<T> b) {\n\
    \          add_e(a, b);\n          ++cnt_E;\n          det_sum += a.det(b);\n\
    \        },\n        [&](Point<T> a, Point<T> b) {\n          rm_e(a, b);\n  \
    \        --cnt_E;\n          det_sum -= a.det(b);\n        });\n    UPPER.add(\n\
    \        -p, [&](Point<T> p) { add_v(-p); }, [&](Point<T> p) { rm_v(-p); },\n\
    \        [&](Point<T> a, Point<T> b) {\n          add_e(-a, -b);\n          ++cnt_E;\n\
    \          det_sum += a.det(b);\n        },\n        [&](Point<T> a, Point<T>\
    \ b) {\n          rm_e(-a, -b);\n          --cnt_E;\n          det_sum -= a.det(b);\n\
    \        });\n  }\n  void add(Point<T> p) {\n    add(\n        p, [](Point<T>\
    \ p) {}, [](Point<T> p) {}, [](Point<T> s, Point<T> t) {},\n        [](Point<T>\
    \ s, Point<T> t) {});\n  }\n\n  // \u4E2D\uFF1A1\u3001\u5883\u754C\uFF1A0\u3001\
    \u5916\uFF1A-1\n  int side(Point<T> p) {\n    int a = LOWER.side(p);\n    int\
    \ b = UPPER.side(-p);\n    if (a == 0 || b == 0) return 0;\n    return min(a,\
    \ b);\n  }\n};\n#line 5 \"test/mytest/incremental_ch.test.cpp\"\n\n// geocon2013\
    \ c sample \u3088\u308A\nvoid test() {\n  {\n    Incremental_ConvexHull<ll> X;\n\
    \    assert(X.area_2() == 0);\n    assert(X.side(Point<ll>(2, 2)) == -1);\n  \
    \  assert(X.side(Point<ll>(1, 2)) == -1);\n    assert(X.side(Point<ll>(1, 1))\
    \ == -1);\n    assert(X.side(Point<ll>(2, 1)) == -1);\n    X.add(Point<ll>(1,\
    \ 1));\n    assert(X.side(Point<ll>(2, 2)) == -1);\n    assert(X.side(Point<ll>(1,\
    \ 2)) == -1);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == -1);\n    X.add(Point<ll>(5, 1));\n    assert(X.area_2() == 0);\n   \
    \ assert(X.side(Point<ll>(2, 2)) == -1);\n    assert(X.side(Point<ll>(1, 2)) ==\
    \ -1);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == 0);\n    X.add(Point<ll>(1, 5));\n    assert(X.area_2() == 16);\n   \
    \ assert(X.side(Point<ll>(2, 2)) == 1);\n    assert(X.side(Point<ll>(1, 2)) ==\
    \ 0);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == 0);\n  }\n  {\n    Incremental_ConvexHull<ll> X;\n    X.add(Point<ll>(2,\
    \ 1));\n    X.add(Point<ll>(4, 1));\n    X.add(Point<ll>(6, 1));\n    assert(X.side(Point<ll>(1,\
    \ 1)) == -1);\n    assert(X.side(Point<ll>(3, 1)) == 0);\n    assert(X.side(Point<ll>(5,\
    \ 1)) == 0);\n    assert(X.side(Point<ll>(7, 1)) == -1);\n  }\n}\n\nvoid solve()\
    \ {\n  LL(A, B);\n  print(A + B);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  test();\n  solve();\n\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"geo/incremental_convexhull.hpp\"\n\n//\
    \ geocon2013 c sample \u3088\u308A\nvoid test() {\n  {\n    Incremental_ConvexHull<ll>\
    \ X;\n    assert(X.area_2() == 0);\n    assert(X.side(Point<ll>(2, 2)) == -1);\n\
    \    assert(X.side(Point<ll>(1, 2)) == -1);\n    assert(X.side(Point<ll>(1, 1))\
    \ == -1);\n    assert(X.side(Point<ll>(2, 1)) == -1);\n    X.add(Point<ll>(1,\
    \ 1));\n    assert(X.side(Point<ll>(2, 2)) == -1);\n    assert(X.side(Point<ll>(1,\
    \ 2)) == -1);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == -1);\n    X.add(Point<ll>(5, 1));\n    assert(X.area_2() == 0);\n   \
    \ assert(X.side(Point<ll>(2, 2)) == -1);\n    assert(X.side(Point<ll>(1, 2)) ==\
    \ -1);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == 0);\n    X.add(Point<ll>(1, 5));\n    assert(X.area_2() == 16);\n   \
    \ assert(X.side(Point<ll>(2, 2)) == 1);\n    assert(X.side(Point<ll>(1, 2)) ==\
    \ 0);\n    assert(X.side(Point<ll>(1, 1)) == 0);\n    assert(X.side(Point<ll>(2,\
    \ 1)) == 0);\n  }\n  {\n    Incremental_ConvexHull<ll> X;\n    X.add(Point<ll>(2,\
    \ 1));\n    X.add(Point<ll>(4, 1));\n    X.add(Point<ll>(6, 1));\n    assert(X.side(Point<ll>(1,\
    \ 1)) == -1);\n    assert(X.side(Point<ll>(3, 1)) == 0);\n    assert(X.side(Point<ll>(5,\
    \ 1)) == 0);\n    assert(X.side(Point<ll>(7, 1)) == -1);\n  }\n}\n\nvoid solve()\
    \ {\n  LL(A, B);\n  print(A + B);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - other/io.hpp
  - geo/incremental_convexhull.hpp
  - geo/base.hpp
  isVerificationFile: true
  path: test/mytest/incremental_ch.test.cpp
  requiredBy: []
  timestamp: '2022-12-01 18:57:05+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/incremental_ch.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/incremental_ch.test.cpp
- /verify/test/mytest/incremental_ch.test.cpp.html
title: test/mytest/incremental_ch.test.cpp
---
