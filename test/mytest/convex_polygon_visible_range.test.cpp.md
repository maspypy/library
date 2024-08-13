---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':x:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':x:'
    path: geo/convex_polygon.hpp
    title: geo/convex_polygon.hpp
  - icon: ':x:'
    path: geo/incremental_convexhull.hpp
    title: geo/incremental_convexhull.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
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
  bundledCode: "#line 1 \"test/mytest/convex_polygon_visible_range.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u32 = unsigned int;\nusing u64 = unsigned long\
    \ long;\nusing i128 = __int128;\nusing u128 = unsigned __int128;\nusing f128 =\
    \ __float128;\n\ntemplate <class T>\nconstexpr T infty = 0;\ntemplate <>\nconstexpr\
    \ int infty<int> = 1'010'000'000;\ntemplate <>\nconstexpr ll infty<ll> = 2'020'000'000'000'000'000;\n\
    template <>\nconstexpr u32 infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64\
    \ infty<u64> = infty<ll>;\ntemplate <>\nconstexpr i128 infty<i128> = i128(infty<ll>)\
    \ * 2'000'000'000'000'000'000;\ntemplate <>\nconstexpr double infty<double> =\
    \ infty<ll>;\ntemplate <>\nconstexpr long double infty<long double> = infty<ll>;\n\
    \nusing pi = pair<ll, ll>;\nusing vi = vector<ll>;\ntemplate <class T>\nusing\
    \ vc = vector<T>;\ntemplate <class T>\nusing vvc = vector<vc<T>>;\ntemplate <class\
    \ T>\nusing vvvc = vector<vvc<T>>;\ntemplate <class T>\nusing vvvvc = vector<vvvc<T>>;\n\
    template <class T>\nusing vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing\
    \ pq = priority_queue<T>;\ntemplate <class T>\nusing pqg = priority_queue<T, vector<T>,\
    \ greater<T>>;\n\n#define vv(type, name, h, ...) vector<vector<type>> name(h,\
    \ vector<type>(__VA_ARGS__))\n#define vvv(type, name, h, w, ...) vector<vector<vector<type>>>\
    \ name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))\n#define vvvv(type,\
    \ name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b,\
    \ vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\n// https://trap.jp/post/1224/\n\
    #define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n#define FOR2(i, a) for (ll i =\
    \ 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll i = a; i < ll(b); ++i)\n#define\
    \ FOR4(i, a, b, c) for (ll i = a; i < ll(b); i += (c))\n#define FOR1_R(a) for\
    \ (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i, a) for (ll i = (a)-1; i >=\
    \ ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i = (b)-1; i >= ll(a); --i)\n#define\
    \ overload4(a, b, c, d, e, ...) e\n#define overload3(a, b, c, d, ...) d\n#define\
    \ FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n#define\
    \ FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\n#define\
    \ FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1) & (s)))\n\
    #define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define elif else\
    \ if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
    #define fi first\n#define se second\n\n#define stoi stoll\n\nint popcnt(int x)\
    \ { return __builtin_popcount(x); }\nint popcnt(u32 x) { return __builtin_popcount(x);\
    \ }\nint popcnt(ll x) { return __builtin_popcountll(x); }\nint popcnt(u64 x) {\
    \ return __builtin_popcountll(x); }\nint popcnt_mod_2(int x) { return __builtin_parity(x);\
    \ }\nint popcnt_mod_2(u32 x) { return __builtin_parity(x); }\nint popcnt_mod_2(ll\
    \ x) { return __builtin_parityll(x); }\nint popcnt_mod_2(u64 x) { return __builtin_parityll(x);\
    \ }\n// (0, 1, 2, 3, 4) -> (-1, 0, 1, 1, 2)\nint topbit(int x) { return (x ==\
    \ 0 ? -1 : 31 - __builtin_clz(x)); }\nint topbit(u32 x) { return (x == 0 ? -1\
    \ : 31 - __builtin_clz(x)); }\nint topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x));\
    \ }\nint topbit(u64 x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n//\
    \ (0, 1, 2, 3, 4) -> (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1\
    \ : __builtin_ctz(x)); }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(ll x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\n\
    T floor(T a, T b) {\n  return a / b - (a % b && (a ^ b) < 0);\n}\ntemplate <typename\
    \ T>\nT ceil(T x, T y) {\n  return floor(x + y - 1, y);\n}\ntemplate <typename\
    \ T>\nT bmod(T x, T y) {\n  return x - y * floor(x, y);\n}\ntemplate <typename\
    \ T>\npair<T, T> divmod(T x, T y) {\n  T q = floor(x, y);\n  return {q, x - q\
    \ * y};\n}\n\ntemplate <typename T, typename U>\nT SUM(const vector<U> &A) {\n\
    \  T sm = 0;\n  for (auto &&a: A) sm += a;\n  return sm;\n}\n\n#define MIN(v)\
    \ *min_element(all(v))\n#define MAX(v) *max_element(all(v))\n#define LB(c, x)\
    \ distance((c).begin(), lower_bound(all(c), (x)))\n#define UB(c, x) distance((c).begin(),\
    \ upper_bound(all(c), (x)))\n#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)),\
    \ x.end()), x.shrink_to_fit()\n\ntemplate <typename T>\nT POP(deque<T> &que) {\n\
    \  T a = que.front();\n  que.pop_front();\n  return a;\n}\ntemplate <typename\
    \ T>\nT POP(pq<T> &que) {\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    template <typename T>\nT POP(pqg<T> &que) {\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\ntemplate <typename T>\nT POP(vc<T> &que) {\n  T a = que.back();\n\
    \  que.pop_back();\n  return a;\n}\n\ntemplate <typename F>\nll binary_search(F\
    \ check, ll ok, ll ng, bool check_ok = true) {\n  if (check_ok) assert(check(ok));\n\
    \  while (abs(ok - ng) > 1) {\n    auto x = (ng + ok) / 2;\n    (check(x) ? ok\
    \ : ng) = x;\n  }\n  return ok;\n}\ntemplate <typename F>\ndouble binary_search_real(F\
    \ check, double ok, double ng, int iter = 100) {\n  FOR(iter) {\n    double x\
    \ = (ok + ng) / 2;\n    (check(x) ? ok : ng) = x;\n  }\n  return (ok + ng) / 2;\n\
    }\n\ntemplate <class T, class S>\ninline bool chmax(T &a, const S &b) {\n  return\
    \ (a < b ? a = b, 1 : 0);\n}\ntemplate <class T, class S>\ninline bool chmin(T\
    \ &a, const S &b) {\n  return (a > b ? a = b, 1 : 0);\n}\n\n// ? \u306F -1\nvc<int>\
    \ s_to_vi(const string &S, char first_char) {\n  vc<int> A(S.size());\n  FOR(i,\
    \ S.size()) { A[i] = (S[i] != '?' ? S[i] - first_char : -1); }\n  return A;\n\
    }\n\ntemplate <typename T, typename U>\nvector<T> cumsum(vector<U> &A, int off\
    \ = 1) {\n  int N = A.size();\n  vector<T> B(N + 1);\n  FOR(i, N) { B[i + 1] =\
    \ B[i] + A[i]; }\n  if (off == 0) B.erase(B.begin());\n  return B;\n}\n\n// stable\
    \ sort\ntemplate <typename T>\nvector<int> argsort(const vector<T> &A) {\n  vector<int>\
    \ ids(len(A));\n  iota(all(ids), 0);\n  sort(all(ids), [&](int i, int j) { return\
    \ (A[i] == A[j] ? i < j : A[i] < A[j]); });\n  return ids;\n}\n\n// A[I[0]], A[I[1]],\
    \ ...\ntemplate <typename T>\nvc<T> rearrange(const vc<T> &A, const vc<int> &I)\
    \ {\n  vc<T> B(len(I));\n  FOR(i, len(I)) B[i] = A[I[i]];\n  return B;\n}\n\n\
    template <typename T, typename... Vectors>\nvoid concat(vc<T> &first, const Vectors\
    \ &... others) {\n  vc<T> &res = first;\n  (res.insert(res.end(), others.begin(),\
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/mytest/convex_polygon_visible_range.test.cpp\"\
    \n\n#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n  T x, y;\n\
    \n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n  Point(A\
    \ x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+=(const Point p) {\n    x +=\
    \ p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const Point p) {\n\
    \    x -= p.x, y -= p.y;\n    return *this;\n  }\n  Point operator+(Point p) const\
    \ { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x\
    \ - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x == p.x && y\
    \ == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y != p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n  Point operator*(T t) const\
    \ { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x / t, y\
    \ / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n\
    \    return y < p.y;\n  }\n  T dot(Point other) { return x * other.x + y * other.y;\
    \ }\n  T det(Point other) { return x * other.y - y * other.x; }\n\n  double norm()\
    \ { return sqrtl(x * x + y * y); }\n  double angle() { return atan2(y, x); }\n\
    \n  Point rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n\
    \    double c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s\
    \ * x + c * y};\n  }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>\
    \ &p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>\
    \ &p) {\n  fastio::wt(p.x);\n  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\
    \n// A -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\
    \u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n \
    \ T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if (x < 0) return -1;\n\
    \  return 0;\n}\n\ntemplate <typename REAL, typename T, typename U>\nREAL dist(Point<T>\
    \ A, Point<U> B) {\n  REAL dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y)\
    \ - REAL(B.y);\n  return sqrt(dx * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U\
    \ x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\
    \u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\
    \u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T,\
    \ long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /=\
    \ g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a\
    \ < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line other) { return\
    \ a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line other) { return\
    \ a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment\
    \ {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n \
    \ Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2,\
    \ y2)) {}\n\n  bool contain(Point<T> C) {\n    static_assert(is_integral<T>::value);\n\
    \    T det = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return (C -\
    \ A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() {\
    \ return Line(A, B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL>\
    \ O;\n  REAL r;\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL\
    \ x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n\ntemplate <typename T>\nstruct Polygon {\n  vc<Point<T>>\
    \ points;\n  T a;\n\n  template <typename A, typename B>\n  Polygon(vc<pair<A,\
    \ B>> pairs) {\n    for (auto &&[a, b]: pairs) points.eb(Point<T>(a, b));\n  \
    \  build();\n  }\n  Polygon(vc<Point<T>> points) : points(points) { build(); }\n\
    \n  int size() { return len(points); }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  T area_2() {\n    return a;\n  }\n\n  bool is_convex() {\n    FOR(j,\
    \ len(points)) {\n      int i = (j == 0 ? len(points) - 1 : j - 1);\n      int\
    \ k = (j == len(points) - 1 ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k]\
    \ - points[j]) < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n\
    \  void build() {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1\
    \ == len(points) ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n\
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n\
    #line 2 \"geo/convex_hull.hpp\"\n\n#line 4 \"geo/convex_hull.hpp\"\n\n// allow_180=true\
    \ \u3067\u540C\u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\
    \u308B\n// full \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\u306A\u308B\n\
    template <typename T, bool allow_180 = false>\nvector<int> ConvexHull(vector<Point<T>>&\
    \ XY, string mode = \"full\", bool sorted = false) {\n  assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N ==\
    \ 1) return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1]) return {0, 1};\n   \
    \ if (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n  vc<int> I(N);\n \
    \ if (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I = argsort(XY);\n \
    \ }\n  if constexpr (allow_180) { FOR(i, N - 1) assert(XY[i] != XY[i + 1]); }\n\
    \n  auto check = [&](ll i, ll j, ll k) -> bool {\n    ll det = (XY[j] - XY[i]).det(XY[k]\
    \ - XY[i]);\n    if constexpr (allow_180) return det >= 0;\n    return det > 0;\n\
    \  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k: I) {\n\
    \      while (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto\
    \ j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n\
    \      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode\
    \ == \"full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >=\
    \ 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n  return P;\n}\n#line 3 \"geo/convex_polygon.hpp\"\
    \n\n// n=2 \u306F\u73FE\u72B6\u30B5\u30DD\u30FC\u30C8\u3057\u3066\u3044\u306A\u3044\
    \ntemplate <typename T>\nstruct ConvexPolygon {\n  using P = Point<T>;\n  int\
    \ n;\n  vc<P> point;\n\n  ConvexPolygon(vc<P> point_) : n(len(point_)), point(point_)\
    \ {\n    assert(n >= 3);\n    FOR(i, n) {\n      int j = nxt_idx(i), k = nxt_idx(j);\n\
    \      assert((point[j] - point[i]).det(point[k] - point[i]) >= 0);\n    }\n \
    \ }\n\n  // \u6BD4\u8F03\u95A2\u6570 comp(i,j)\n  template <typename F>\n  int\
    \ periodic_min_comp(F comp) {\n    int L = 0, M = n, R = n + n;\n    while (1)\
    \ {\n      if (R - L == 2) break;\n      int L1 = (L + M) / 2, R1 = (M + R + 1)\
    \ / 2;\n      if (comp(L1 % n, M % n)) { R = M, M = L1; }\n      elif (comp(R1\
    \ % n, M % n)) { L = M, M = R1; }\n      else {\n        L = L1, R = R1;\n   \
    \   }\n    }\n    return M % n;\n  }\n\n  int nxt_idx(int i) { return (i + 1 ==\
    \ n ? 0 : i + 1); }\n  int prev_idx(int i) { return (i == 0 ? n - 1 : i - 1);\
    \ }\n\n  // \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1. test \u3057\u305F\
    .\n  int side(P p) {\n    int L = 1, R = n - 1;\n    T a = (point[L] - point[0]).det(p\
    \ - point[0]);\n    T b = (point[R] - point[0]).det(p - point[0]);\n    if (a\
    \ < 0 || b > 0) return -1;\n    // p \u306F 0 \u304B\u3089\u898B\u3066 [L,R] \u65B9\
    \u5411\n    while (R - L >= 2) {\n      int M = (L + R) / 2;\n      T c = (point[M]\
    \ - point[0]).det(p - point[0]);\n      if (c < 0)\n        R = M, b = c;\n  \
    \    else\n        L = M, a = c;\n    }\n    T c = (point[R] - point[L]).det(p\
    \ - point[L]);\n    T x = min({a, -b, c});\n    if (x < 0) return -1;\n    if\
    \ (x > 0) return 1;\n    // on triangle p[0]p[L]p[R]\n    if (p == point[0]) return\
    \ 0;\n    if (c != 0 && a == 0 && L != 1) return 1;\n    if (c != 0 && b == 0\
    \ && R != n - 1) return 1;\n    return 0;\n  }\n\n  // return {min, idx}. test\
    \ \u3057\u305F.\n  pair<T, int> min_dot(P p) {\n    int idx = periodic_min_comp([&](int\
    \ i, int j) -> bool { return point[i].dot(p) < point[j].dot(p); });\n    return\
    \ {point[idx].dot(p), idx};\n  }\n\n  // return {max, idx}. test \u3057\u305F\
    .\n  pair<T, int> max_dot(P p) {\n    int idx = periodic_min_comp([&](int i, int\
    \ j) -> bool { return point[i].dot(p) > point[j].dot(p); });\n    return {point[idx].dot(p),\
    \ idx};\n  }\n\n  // p \u304B\u3089\u898B\u3048\u308B\u7BC4\u56F2. p \u8FBA\u306B\
    \u6CBF\u3063\u3066\u898B\u3048\u308B\u3068\u3053\u308D\u3082\u898B\u3048\u308B\
    \u3068\u3059\u308B. test \u3057\u305F.\n  // \u591A\u89D2\u5F62\u304B\u3089\u306E\
    \u53CD\u6642\u8A08\u9806\u306F [l,r] \u3060\u304C p \u304B\u3089\u898B\u305F\u504F\
    \u89D2\u9806\u306F [r,l] \u306A\u306E\u3067\u6CE8\u610F\n  pair<int, int> visible_range(P\
    \ p) {\n    int a = periodic_min_comp([&](int i, int j) -> bool { return ((point[i]\
    \ - p).det(point[j] - p) < 0); });\n    int b = periodic_min_comp([&](int i, int\
    \ j) -> bool { return ((point[i] - p).det(point[j] - p) > 0); });\n    if ((p\
    \ - point[a]).det(p - point[prev_idx(a)]) == T(0)) a = prev_idx(a);\n    if ((p\
    \ - point[b]).det(p - point[nxt_idx(b)]) == T(0)) b = nxt_idx(b);\n    return\
    \ {a, b};\n  }\n\n  // \u7DDA\u5206\u304C\u300C\u5185\u90E8\u3068\u300D\u4EA4\u308F\
    \u308B\u304B\n  // https://codeforces.com/contest/1906/problem/D\n  bool check_cross(P\
    \ A, P B) {\n    FOR(2) {\n      swap(A, B);\n      auto [a, b] = visible_range(A);\n\
    \      if ((point[a] - A).det(B - A) >= 0) return 0;\n      if ((point[b] - A).det(B\
    \ - A) <= 0) return 0;\n    }\n    return 1;\n  }\n};\n#line 2 \"geo/incremental_convexhull.hpp\"\
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
    \ b);\n  }\n};\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t\
    \ x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n         \
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \               .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n\
    \  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim; }\n\n\
    ll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 9 \"test/mytest/convex_polygon_visible_range.test.cpp\"\
    \n\nusing P = Point<ll>;\n\nvoid test() {\n  int N = RNG(3, 10);\n  vc<P> point(N);\n\
    \  FOR(i, N) point[i] = P(RNG(-5, 5), RNG(-5, 5));\n  auto I = ConvexHull(point);\n\
    \  point = rearrange(point, I);\n  N = len(point);\n  if (N <= 2) return;\n\n\
    \  ConvexPolygon<ll> X(point);\n  FOR(x, -10, 11) FOR(y, -10, 11) {\n    P p(x,\
    \ y);\n    if (X.side(p) == 1) continue;\n    auto [l, r] = X.visible_range(p);\n\
    \    vc<int> can(N);\n    {\n      int i = l;\n      while (1) {\n        can[i]\
    \ = 1;\n        if (i == r) break;\n        i = (i + 1) % N;\n      }\n    }\n\
    \    FOR(i, N) {\n      int j = (i + N - 1) % N, k = (i + 1) % N;\n      P A =\
    \ point[j], B = point[i], C = point[k];\n      int ok = 0;\n      if ((B - A).det(p\
    \ - A) <= 0) ok = 1;\n      if ((B - C).det(p - C) >= 0) ok = 1;\n      assert(can[i]\
    \ == ok);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(30000) test();\n  solve();\n\
    \  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"geo/base.hpp\"\n#include \"geo/convex_hull.hpp\"\n#include \"geo/convex_polygon.hpp\"\
    \n#include \"geo/incremental_convexhull.hpp\"\n#include \"random/base.hpp\"\n\n\
    using P = Point<ll>;\n\nvoid test() {\n  int N = RNG(3, 10);\n  vc<P> point(N);\n\
    \  FOR(i, N) point[i] = P(RNG(-5, 5), RNG(-5, 5));\n  auto I = ConvexHull(point);\n\
    \  point = rearrange(point, I);\n  N = len(point);\n  if (N <= 2) return;\n\n\
    \  ConvexPolygon<ll> X(point);\n  FOR(x, -10, 11) FOR(y, -10, 11) {\n    P p(x,\
    \ y);\n    if (X.side(p) == 1) continue;\n    auto [l, r] = X.visible_range(p);\n\
    \    vc<int> can(N);\n    {\n      int i = l;\n      while (1) {\n        can[i]\
    \ = 1;\n        if (i == r) break;\n        i = (i + 1) % N;\n      }\n    }\n\
    \    FOR(i, N) {\n      int j = (i + N - 1) % N, k = (i + 1) % N;\n      P A =\
    \ point[j], B = point[i], C = point[k];\n      int ok = 0;\n      if ((B - A).det(p\
    \ - A) <= 0) ok = 1;\n      if ((B - C).det(p - C) >= 0) ok = 1;\n      assert(can[i]\
    \ == ok);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(30000) test();\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - geo/base.hpp
  - geo/convex_hull.hpp
  - geo/convex_polygon.hpp
  - geo/incremental_convexhull.hpp
  - random/base.hpp
  isVerificationFile: true
  path: test/mytest/convex_polygon_visible_range.test.cpp
  requiredBy: []
  timestamp: '2024-08-13 20:27:42+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/convex_polygon_visible_range.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/convex_polygon_visible_range.test.cpp
- /verify/test/mytest/convex_polygon_visible_range.test.cpp.html
title: test/mytest/convex_polygon_visible_range.test.cpp
---
