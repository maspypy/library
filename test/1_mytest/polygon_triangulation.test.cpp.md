---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':heavy_check_mark:'
    path: ds/fenwicktree/fenwicktree_01.hpp
    title: ds/fenwicktree/fenwicktree_01.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree.hpp
    title: ds/splaytree/splaytree.hpp
  - icon: ':question:'
    path: ds/splaytree/splaytree_basic.hpp
    title: ds/splaytree/splaytree_basic.hpp
  - icon: ':heavy_check_mark:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':heavy_check_mark:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':heavy_check_mark:'
    path: geo/cross_point.hpp
    title: geo/cross_point.hpp
  - icon: ':heavy_check_mark:'
    path: geo/polygon_triangulation.hpp
    title: geo/polygon_triangulation.hpp
  - icon: ':question:'
    path: graph/base.hpp
    title: graph/base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/planar_graph.hpp
    title: graph/planar_graph.hpp
  - icon: ':question:'
    path: my_template.hpp
    title: my_template.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_polygon.hpp
    title: random/random_polygon.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"test/1_mytest/polygon_triangulation.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#line 1 \"my_template.hpp\"\
    \n#if defined(LOCAL)\n#include <my_template_compiled.hpp>\n#else\n\n// https://codeforces.com/blog/entry/96344\n\
    #pragma GCC optimize(\"Ofast,unroll-loops\")\n// \u3044\u307E\u306E CF \u3060\u3068\
    \u3053\u308C\u5165\u308C\u308B\u3068\u52D5\u304B\u306A\u3044\uFF1F\n// #pragma\
    \ GCC target(\"avx2,popcnt\")\n\n#include <bits/stdc++.h>\n\nusing namespace std;\n\
    \nusing ll = long long;\nusing u8 = uint8_t;\nusing u16 = uint16_t;\nusing u32\
    \ = uint32_t;\nusing u64 = uint64_t;\nusing i128 = __int128;\nusing u128 = unsigned\
    \ __int128;\nusing f128 = __float128;\n\ntemplate <class T>\nconstexpr T infty\
    \ = 0;\ntemplate <>\nconstexpr int infty<int> = 1'010'000'000;\ntemplate <>\n\
    constexpr ll infty<ll> = 2'020'000'000'000'000'000;\ntemplate <>\nconstexpr u32\
    \ infty<u32> = infty<int>;\ntemplate <>\nconstexpr u64 infty<u64> = infty<ll>;\n\
    template <>\nconstexpr i128 infty<i128> = i128(infty<ll>) * 2'000'000'000'000'000'000;\n\
    template <>\nconstexpr double infty<double> = infty<ll>;\ntemplate <>\nconstexpr\
    \ long double infty<long double> = infty<ll>;\n\nusing pi = pair<ll, ll>;\nusing\
    \ vi = vector<ll>;\ntemplate <class T>\nusing vc = vector<T>;\ntemplate <class\
    \ T>\nusing vvc = vector<vc<T>>;\ntemplate <class T>\nusing vvvc = vector<vvc<T>>;\n\
    template <class T>\nusing vvvvc = vector<vvvc<T>>;\ntemplate <class T>\nusing\
    \ vvvvvc = vector<vvvvc<T>>;\ntemplate <class T>\nusing pq = priority_queue<T>;\n\
    template <class T>\nusing pqg = priority_queue<T, vector<T>, greater<T>>;\n\n\
    #define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))\n\
    #define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w,\
    \ vector<type>(__VA_ARGS__)))\n#define vvvv(type, name, a, b, c, ...) \\\n  vector<vector<vector<vector<type>>>>\
    \ name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))\n\
    \n// https://trap.jp/post/1224/\n#define FOR1(a) for (ll _ = 0; _ < ll(a); ++_)\n\
    #define FOR2(i, a) for (ll i = 0; i < ll(a); ++i)\n#define FOR3(i, a, b) for (ll\
    \ i = a; i < ll(b); ++i)\n#define FOR4(i, a, b, c) for (ll i = a; i < ll(b); i\
    \ += (c))\n#define FOR1_R(a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR2_R(i,\
    \ a) for (ll i = (a)-1; i >= ll(0); --i)\n#define FOR3_R(i, a, b) for (ll i =\
    \ (b)-1; i >= ll(a); --i)\n#define overload4(a, b, c, d, e, ...) e\n#define overload3(a,\
    \ b, c, d, ...) d\n#define FOR(...) overload4(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\
    #define FOR_R(...) overload3(__VA_ARGS__, FOR3_R, FOR2_R, FOR1_R)(__VA_ARGS__)\n\
    \n#define FOR_subset(t, s) for (ll t = (s); t >= 0; t = (t == 0 ? -1 : (t - 1)\
    \ & (s)))\n#define all(x) x.begin(), x.end()\n#define len(x) ll(x.size())\n#define\
    \ elif else if\n\n#define eb emplace_back\n#define mp make_pair\n#define mt make_tuple\n\
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
    \ others.end()), ...);\n}\n#endif\n#line 3 \"test/1_mytest/polygon_triangulation.test.cpp\"\
    \n\n#line 1 \"random/random_polygon.hpp\"\n\n#line 2 \"random/base.hpp\"\n\nu64\
    \ RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct\
    \ Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename\
    \ B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n\
    \  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+=(const Point\
    \ p) {\n    x += p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const\
    \ Point p) {\n    x -= p.x, y -= p.y;\n    return *this;\n  }\n  Point operator+(Point\
    \ p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const {\
    \ return {x - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x ==\
    \ p.x && y == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y\
    \ != p.y; }\n  Point operator-() const { return {-x, -y}; }\n  Point operator*(T\
    \ t) const { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x\
    \ / t, y / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return\
    \ x < p.x;\n    return y < p.y;\n  }\n  T dot(Point other) { return x * other.x\
    \ + y * other.y; }\n  T det(Point other) { return x * other.y - y * other.x; }\n\
    \n  double norm() { return sqrtl(x * x + y * y); }\n  double angle() { return\
    \ atan2(y, x); }\n\n  Point rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n\
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
    \ {}\n  Line(Point<T> A, Point<T> B) { a = A.y - B.y, b = B.x - A.x, c = A.x *\
    \ B.y - A.y * B.x; }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1),\
    \ Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n  \
    \  return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x,\
    \ U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\
    \u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T,\
    \ long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /=\
    \ g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a\
    \ < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line other) { return\
    \ a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line other) { return\
    \ a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment\
    \ {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n \
    \ Segment(T x1, T y1, T x2, T y2) : Segment(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if\
    \ (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A -\
    \ B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate\
    \ <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 2 \"geo/convex_hull.hpp\"\n\n#line 4 \"geo/convex_hull.hpp\"\n\n// allow_180=true\
    \ \u3067\u540C\u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\
    \u308B\n// full \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\u306A\u308B\n\
    template <typename T, bool allow_180 = false>\nvector<int> ConvexHull(vector<Point<T>>&\
    \ XY, string mode = \"full\", bool sorted = false) {\n  assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N ==\
    \ 1) return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1]) return {0, 1};\n   \
    \ if (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n  vc<int> I(N);\n \
    \ if (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I = argsort(XY);\n \
    \ }\n  if constexpr (allow_180) { FOR(i, N - 1) assert(XY[i] != XY[i + 1]); }\n\
    \n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k]\
    \ - XY[i]);\n    if constexpr (allow_180) return det >= 0;\n    return det > T(0);\n\
    \  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k: I) {\n\
    \      while (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto\
    \ j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n\
    \      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode\
    \ == \"full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >=\
    \ 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n  return P;\n}\n#line 2 \"geo/cross_point.hpp\"\
    \n\n#line 4 \"geo/cross_point.hpp\"\n\n// \u5E73\u884C\u3067\u306A\u3044\u3053\
    \u3068\u3092\u4EEE\u5B9A\ntemplate <typename REAL, typename T>\nPoint<REAL> cross_point(const\
    \ Line<T> L1, const Line<T> L2) {\n  T det = L1.a * L2.b - L1.b * L2.a;\n  assert(det\
    \ != 0);\n  REAL x = -REAL(L1.c) * L2.b + REAL(L1.b) * L2.c;\n  REAL y = -REAL(L1.a)\
    \ * L2.c + REAL(L1.c) * L2.a;\n  return Point<REAL>(x / det, y / det);\n}\n\n\
    // \u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u306F\u30A8\u30E9\u30FC\n// 0: \u4EA4\u70B9\
    \u306A\u3057\n// 1: \u4E00\u610F\u306A\u4EA4\u70B9\n// 2\uFF1A2 \u3064\u4EE5\u4E0A\
    \u306E\u4EA4\u70B9\uFF08\u6574\u6570\u578B\u3092\u5229\u7528\u3057\u3066\u53B3\
    \u5BC6\u306B\u3084\u308B\uFF09\ntemplate <typename T>\nint count_cross(Segment<T>\
    \ S1, Segment<T> S2, bool include_ends) {\n  static_assert(!std::is_floating_point<T>::value);\n\
    \  Line<T> L1 = S1.to_Line();\n  Line<T> L2 = S2.to_Line();\n  if (L1.is_parallel(L2))\
    \ {\n    if (L1.eval(S2.A) != 0) return 0;\n    // 4 \u70B9\u3068\u3082\u540C\u4E00\
    \u76F4\u7DDA\u4E0A\u306B\u3042\u308B\n    T a1 = S1.A.x, b1 = S1.B.x;\n    T a2\
    \ = S2.A.x, b2 = S2.B.x;\n    if (a1 == b1) {\n      a1 = S1.A.y, b1 = S1.B.y;\n\
    \      a2 = S2.A.y, b2 = S2.B.y;\n    }\n    if (a1 > b1) swap(a1, b1);\n    if\
    \ (a2 > b2) swap(a2, b2);\n    T a = max(a1, a2);\n    T b = min(b1, b2);\n  \
    \  if (a < b) return 2;\n    if (a > b) return 0;\n    return (include_ends ?\
    \ 1 : 0);\n  }\n  // \u5E73\u884C\u3067\u306A\u3044\u5834\u5408\n  T a1 = L2.eval(S1.A),\
    \ b1 = L2.eval(S1.B);\n  T a2 = L1.eval(S2.A), b2 = L1.eval(S2.B);\n  if (a1 >\
    \ b1) swap(a1, b1);\n  if (a2 > b2) swap(a2, b2);\n  bool ok1 = 0, ok2 = 0;\n\n\
    \  if (include_ends) {\n    ok1 = (a1 <= T(0)) && (T(0) <= b1);\n    ok2 = (a2\
    \ <= T(0)) && (T(0) <= b2);\n  } else {\n    ok1 = (a1 < T(0)) && (T(0) < b1);\n\
    \    ok2 = (a2 < T(0)) && (T(0) < b2);\n  }\n  return (ok1 && ok2 ? 1 : 0);\n\
    }\n\n// https://codeforces.com/contest/607/problem/E\ntemplate <typename REAL,\
    \ typename T>\nvc<Point<REAL>> cross_point(const Circle<T> C, const Line<T> L)\
    \ {\n  T a = L.a, b = L.b, c = L.a * (C.O.x) + L.b * (C.O.y) + L.c;\n  T r = C.r;\n\
    \  bool SW = 0;\n  if (abs(a) < abs(b)) {\n    swap(a, b);\n    SW = 1;\n  }\n\
    \  // ax+by+c=0, x^2+y^2=r^2\n  T D = 4 * c * c * b * b - 4 * (a * a + b * b)\
    \ * (c * c - a * a * r * r);\n  if (D < 0) return {};\n  REAL sqD = sqrtl(D);\n\
    \  REAL y1 = (-2 * b * c + sqD) / (2 * (a * a + b * b));\n  REAL y2 = (-2 * b\
    \ * c - sqD) / (2 * (a * a + b * b));\n  REAL x1 = (-b * y1 - c) / a;\n  REAL\
    \ x2 = (-b * y2 - c) / a;\n  if (SW) swap(x1, y1), swap(x2, y2);\n  x1 += C.O.x,\
    \ x2 += C.O.x;\n  y1 += C.O.y, y2 += C.O.y;\n  if (D == 0) return {Point<REAL>(x1,\
    \ y1)};\n  return {Point<REAL>(x1, y1), Point<REAL>(x2, y2)};\n}\n\n// https://codeforces.com/contest/2/problem/C\n\
    template <typename REAL, typename T>\ntuple<bool, Point<T>, Point<T>> cross_point_circle(Circle<T>\
    \ C1, Circle<T> C2) {\n  using P = Point<T>;\n  P O{0, 0};\n  P A = C1.O, B =\
    \ C2.O;\n  if (A == B) return {false, O, O};\n  T d = (B - A).norm();\n  REAL\
    \ cos_val = (C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d);\n  if (cos_val\
    \ < -1 || 1 < cos_val) return {false, O, O};\n  REAL t = acos(cos_val);\n  REAL\
    \ u = (B - A).angle();\n  P X = A + P{C1.r * cos(u + t), C1.r * sin(u + t)};\n\
    \  P Y = A + P{C1.r * cos(u - t), C1.r * sin(u - t)};\n  return {true, X, Y};\n\
    }\n#line 1 \"geo/count_points_in_triangles.hpp\"\n\n#line 2 \"geo/angle_sort.hpp\"\
    \n\r\n#line 4 \"geo/angle_sort.hpp\"\n\r\n// lower: -1, origin: 0, upper: 1\r\n\
    template <typename T>\r\nint lower_or_upper(Point<T>& p) {\r\n  if (p.y != 0)\
    \ return (p.y > 0 ? 1 : -1);\r\n  if (p.x > 0) return -1;\r\n  if (p.x < 0) return\
    \ 1;\r\n  return 0;\r\n}\r\n\r\n// -1, 0, 1\r\ntemplate <typename T>\r\nint angle_comp_3(Point<T>&\
    \ L, Point<T>& R) {\r\n  int a = lower_or_upper(L), b = lower_or_upper(R);\r\n\
    \  if (a != b) return (a < b ? -1 : +1);\r\n  T det = L.det(R);\r\n  if (det >\
    \ 0) return -1;\r\n  if (det < 0) return 1;\r\n  return 0;\r\n}\r\n// \u504F\u89D2\
    \u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\ntemplate <typename T>\r\n\
    vector<int> angle_sort(vector<Point<T>>& P) {\r\n  vc<int> I(len(P));\r\n  FOR(i,\
    \ len(P)) I[i] = i;\r\n  sort(all(I), [&](auto& L, auto& R) -> bool { return angle_comp_3(P[L],\
    \ P[R]) == -1; });\r\n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\
    \u306B\u5BFE\u3059\u308B argsort\r\ntemplate <typename T>\r\nvector<int> angle_sort(vector<pair<T,\
    \ T>>& P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_sort<T>(tmp);\r\n}\r\n#line 2 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\n#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct Monoid_Add\
    \ {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\
    \n\ntemplate <typename Monoid>\nstruct FenwickTree {\n  using G = Monoid;\n  using\
    \ MX = Monoid;\n  using E = typename G::value_type;\n  int n;\n  vector<E> dat;\n\
    \  E total;\n\n  FenwickTree() {}\n  FenwickTree(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree(int n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const\
    \ vc<E>& v) { build(v); }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m,\
    \ G::unit());\n    total = G::unit();\n  }\n  void build(const vc<E>& v) {\n \
    \   build(len(v), [&](int i) -> E { return v[i]; });\n  }\n  template <typename\
    \ F>\n  void build(int m, F f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n\
    \    total = G::unit();\n    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1;\
    \ i <= n; ++i) {\n      int j = i + (i & -i);\n      if (j <= n) dat[j - 1] =\
    \ G::op(dat[i - 1], dat[j - 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n \
    \ E prod_all() { return total; }\n  E sum_all() { return total; }\n  E sum(int\
    \ k) { return prefix_sum(k); }\n  E prod(int k) { return prefix_prod(k); }\n \
    \ E prefix_sum(int k) { return prefix_prod(k); }\n  E prefix_prod(int k) {\n \
    \   chmin(k, n);\n    E ret = G::unit();\n    for (; k > 0; k -= k & -k) ret =\
    \ G::op(ret, dat[k - 1]);\n    return ret;\n  }\n  E sum(int L, int R) { return\
    \ prod(L, R); }\n  E prod(int L, int R) {\n    chmax(L, 0), chmin(R, n);\n   \
    \ if (L == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n\
    \    E pos = G::unit(), neg = G::unit();\n    while (L < R) { pos = G::op(pos,\
    \ dat[R - 1]), R -= R & -R; }\n    while (R < L) { neg = G::op(neg, dat[L - 1]),\
    \ L -= L & -L; }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  vc<E> get_all()\
    \ {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i, i + 1);\n    return res;\n\
    \  }\n\n  void add(int k, E x) { multiply(k, x); }\n  void multiply(int k, E x)\
    \ {\n    static_assert(G::commute);\n    total = G::op(total, x);\n    for (++k;\
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n\n  template <class\
    \ F>\n  int max_right(const F check, int L = 0) {\n    assert(check(G::unit()));\n\
    \    E s = G::unit();\n    int i = L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\
    \n    int k = [&]() {\n      while (1) {\n        if (i % 2 == 1) { s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= 1; }\n        if (i == 0) { return topbit(n) +\
    \ 1; }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t)) { return\
    \ k; }\n        s = G::op(s, G::inverse(dat[i - 1])), i -= i & -i;\n      }\n\
    \    }();\n    while (k) {\n      --k;\n      if (i + (1 << k) - 1 < len(dat))\
    \ {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (check(t)) { i\
    \ += (1 << k), s = t; }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n\
    \  template <class F>\n  int max_right_with_index(const F check, int L = 0) {\n\
    \    assert(check(L, G::unit()));\n    E s = G::unit();\n    int i = L;\n    //\
    \ 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n\
    \        if (i % 2 == 1) { s = G::op(s, G::inverse(dat[i - 1])), i -= 1; }\n \
    \       if (i == 0) { return topbit(n) + 1; }\n        int k = lowbit(i) - 1;\n\
    \        if (i + (1 << k) > n) return k;\n        E t = G::op(s, dat[i + (1 <<\
    \ k) - 1]);\n        if (!check(i + (1 << k), t)) { return k; }\n        s = G::op(s,\
    \ G::inverse(dat[i - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n\
    \      --k;\n      if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s,\
    \ dat[i + (1 << k) - 1]);\n        if (check(i + (1 << k), t)) { i += (1 << k),\
    \ s = t; }\n      }\n    }\n    return i;\n  }\n\n  template <class F>\n  int\
    \ min_left(const F check, int R) {\n    assert(check(G::unit()));\n    E s = G::unit();\n\
    \    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\u308D\u307E\u3067\
    \u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s)) {\n      s = G::op(s,\
    \ dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n    }\n    if (check(s))\
    \ {\n      assert(i == 0);\n      return 0;\n    }\n    // 2^k \u9032\u3080\u3068\
    \ ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\u6301\u3057\u3066\u9032\u3080\
    \n    while (k) {\n      --k;\n      E t = G::op(s, G::inverse(dat[i + (1 << k)\
    \ - 1]));\n      if (!check(t)) { i += (1 << k), s = t; }\n    }\n    return i\
    \ + 1;\n  }\n\n  int kth(E k, int L = 0) {\n    return max_right([&k](E x) ->\
    \ bool { return x <= k; }, L);\n  }\n};\n#line 4 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\nstruct FenwickTree_01 {\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>>\
    \ bit;\n  FenwickTree_01() {}\n  FenwickTree_01(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree_01(int n, F f) {\n    build(n, f);\n  }\n\n  void\
    \ build(int m) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    bit.build(n);\n  }\n\n  template <typename F>\n  void build(int\
    \ m, F f) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n, u64(0));\n\
    \    FOR(i, N) { dat[i / 64] |= u64(f(i)) << (i % 64); }\n    bit.build(n, [&](int\
    \ i) -> int { return popcnt(dat[i]); });\n  }\n\n  int sum_all() { return bit.sum_all();\
    \ }\n  int sum(int k) { return prefix_sum(k); }\n  int prefix_sum(int k) {\n \
    \   int ans = bit.sum(k / 64);\n    ans += popcnt(dat[k / 64] & ((u64(1) << (k\
    \ % 64)) - 1));\n    return ans;\n  }\n  int sum(int L, int R) {\n    if (L ==\
    \ 0) return prefix_sum(R);\n    int ans = 0;\n    ans -= popcnt(dat[L / 64] &\
    \ ((u64(1) << (L % 64)) - 1));\n    ans += popcnt(dat[R / 64] & ((u64(1) << (R\
    \ % 64)) - 1));\n    ans += bit.sum(L / 64, R / 64);\n    return ans;\n  }\n\n\
    \  void add(int k, int x) {\n    if (x == 1) add(k);\n    if (x == -1) remove(k);\n\
    \  }\n\n  void add(int k) {\n    dat[k / 64] |= u64(1) << (k % 64);\n    bit.add(k\
    \ / 64, 1);\n  }\n  void remove(int k) {\n    dat[k / 64] &= ~(u64(1) << (k %\
    \ 64));\n    bit.add(k / 64, -1);\n  }\n\n  int kth(int k, int L = 0) {\n    if\
    \ (k >= sum_all()) return N;\n    k += popcnt(dat[L / 64] & ((u64(1) << (L % 64))\
    \ - 1));\n    L /= 64;\n    int mid = 0;\n    auto check = [&](auto e) -> bool\
    \ {\n      if (e <= k) chmax(mid, e);\n      return e <= k;\n    };\n    int idx\
    \ = bit.max_right(check, L);\n    if (idx == n) return N;\n    k -= mid;\n   \
    \ u64 x = dat[idx];\n    int p = popcnt(x);\n    if (p <= k) return N;\n    k\
    \ = binary_search([&](int n) -> bool { return (p - popcnt(x >> n)) <= k; },\n\
    \                      0, 64, 0);\n    return 64 * idx + k;\n  }\n\n  int next(int\
    \ k) {\n    int idx = k / 64;\n    k %= 64;\n    u64 x = dat[idx] & ~((u64(1)\
    \ << k) - 1);\n    if (x) return 64 * idx + lowbit(x);\n    idx = bit.kth(0, idx\
    \ + 1);\n    if (idx == n || !dat[idx]) return N;\n    return 64 * idx + lowbit(dat[idx]);\n\
    \  }\n\n  int prev(int k) {\n    if (k == N) --k;\n    int idx = k / 64;\n   \
    \ k %= 64;\n    u64 x = dat[idx];\n    if (k < 63) x &= (u64(1) << (k + 1)) -\
    \ 1;\n    if (x) return 64 * idx + topbit(x);\n    idx = bit.min_left([&](auto\
    \ e) -> bool { return e <= 0; }, idx) - 1;\n    if (idx == -1) return -1;\n  \
    \  return 64 * idx + topbit(dat[idx]);\n  }\n};\n#line 6 \"geo/count_points_in_triangles.hpp\"\
    \n\n// \u70B9\u7FA4 A, B \u3092\u5165\u529B \uFF08Point<ll>\uFF09\n// query(i,j,k)\uFF1A\
    \u4E09\u89D2\u5F62 AiAjAk \u5185\u90E8\u306E Bl \u306E\u500B\u6570\uFF08\u975E\
    \u8CA0\uFF09\u3092\u8FD4\u3059\n// \u524D\u8A08\u7B97 O(NMlogM)\u3001\u30AF\u30A8\
    \u30EA O(1)\n// https://codeforces.com/contest/13/problem/D\n// https://codeforces.com/contest/852/problem/H\n\
    struct Count_Points_In_Triangles {\n  using P = Point<ll>;\n  const int LIM =\
    \ 1'000'000'000 + 10;\n  vc<P> A, B;\n  vc<int> new_idx; // O \u304B\u3089\u898B\
    \u305F\u504F\u89D2\u30BD\u30FC\u30C8\u9806\u3092\u7BA1\u7406\n  vc<int> point;\
    \   // A[i] \u3068\u4E00\u81F4\u3059\u308B B[j] \u306E\u6570\u3048\u4E0A\u3052\
    \n  vvc<int> seg;    // \u7DDA\u5206 A[i]A[j] \u5185\u306B\u3042\u308B B[k] \u306E\
    \u6570\u3048\u4E0A\u3052\n  vvc<int> tri;    // OA[i]A[j] \u5185\u90E8\u306B\u3042\
    \u308B B[k] \u306E\u6570\u3048\u4E0A\u3052\n  Count_Points_In_Triangles(const\
    \ vc<P>& A, const vc<P>& B) : A(A), B(B) {\n    for (auto&& p: A) assert(max(abs(p.x),\
    \ abs(p.y)) < LIM);\n    for (auto&& p: B) assert(max(abs(p.x), abs(p.y)) < LIM);\n\
    \    build();\n  }\n\n  int count3(int i, int j, int k) {\n    i = new_idx[i],\
    \ j = new_idx[j], k = new_idx[k];\n    if (i > j) swap(i, j);\n    if (j > k)\
    \ swap(j, k);\n    if (i > j) swap(i, j);\n    assert(i <= j && j <= k);\n   \
    \ ll d = (A[j] - A[i]).det(A[k] - A[i]);\n    if (d == 0) return 0;\n    if (d\
    \ > 0) { return tri[i][j] + tri[j][k] - tri[i][k] - seg[i][k]; }\n    int x =\
    \ tri[i][k] - tri[i][j] - tri[j][k];\n    return x - seg[i][j] - seg[j][k] - point[j];\n\
    \  }\n\n  // segment\n  int count2(int i, int j) {\n    i = new_idx[i], j = new_idx[j];\n\
    \    if (i > j) swap(i, j);\n    return seg[i][j];\n  }\n\nprivate:\n  P take_origin()\
    \ {\n    // OAiAj, OAiBj \u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u306A\u3089\
    \u306A\u3044\u3088\u3046\u306B\u3059\u308B\n    // fail prob: at most N(N+M)/LIM\n\
    \    return P{-LIM, RNG(-LIM, LIM)};\n  }\n\n  void build() {\n    P O = take_origin();\n\
    \    for (auto&& p: A) p = p - O;\n    for (auto&& p: B) p = p - O;\n    int N\
    \ = len(A), M = len(B);\n    vc<int> I = angle_sort(A);\n    A = rearrange(A,\
    \ I);\n    new_idx.resize(N);\n    FOR(i, N) new_idx[I[i]] = i;\n\n    I = angle_sort(B);\n\
    \    B = rearrange(B, I);\n\n    point.assign(N, 0);\n    seg.assign(N, vc<int>(N));\n\
    \    tri.assign(N, vc<int>(N));\n\n    // point\n    FOR(i, N) FOR(j, M) if (A[i]\
    \ == B[j])++ point[i];\n\n    int m = 0;\n    FOR(j, N) {\n      // OA[i]A[j],\
    \ B[k]\n      while (m < M && A[j].det(B[m]) < 0) ++m;\n      vc<P> C(m);\n  \
    \    FOR(k, m) C[k] = B[k] - A[j];\n      vc<int> I(m);\n      FOR(i, m) I[i]\
    \ = i;\n      sort(all(I), [&](auto& a, auto& b) -> bool { return C[a].det(C[b])\
    \ > 0; });\n      C = rearrange(C, I);\n      vc<int> rk(m);\n      FOR(k, m)\
    \ rk[I[k]] = k;\n      FenwickTree_01 bit(m);\n\n      int k = m;\n      FOR_R(i,\
    \ j) {\n        while (k > 0 && A[i].det(B[k - 1]) > 0) { bit.add(rk[--k], 1);\
    \ }\n        P p = A[i] - A[j];\n        int lb = binary_search([&](int n) ->\
    \ bool { return (n == 0 ? true : C[n - 1].det(p) > 0); }, 0, m + 1);\n       \
    \ int ub = binary_search([&](int n) -> bool { return (n == 0 ? true : C[n - 1].det(p)\
    \ >= 0); }, 0, m + 1);\n        seg[i][j] += bit.sum(lb, ub), tri[i][j] += bit.sum(lb);\n\
    \      }\n    }\n  }\n};\n#line 7 \"random/random_polygon.hpp\"\n\nvc<Point<ll>>\
    \ random_polygon(int N, int XY_ABS_MAX = 10) {\n  assert(N >= 3);\n  using P =\
    \ Point<ll>;\n  auto trial = [&]() -> vc<P> {\n    set<Point<ll>> S;\n    while\
    \ (len(S) < N) {\n      int x = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);\n      int y\
    \ = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);\n      S.insert(Point<ll>(x, y));\n    }\n\
    \    vc<P> point(all(S));\n    auto I = ConvexHull<ll, true>(point);\n    Count_Points_In_Triangles\
    \ CT(point, point);\n    vc<int> other;\n    vc<int> done(N);\n    for (auto&\
    \ i: I) done[i]++;\n    if (MAX(done) >= 2) return {};\n    FOR(i, N) if (!done[i])\
    \ other.eb(i);\n    int fail = 0;\n    while (len(other)) {\n      if (fail >\
    \ 1000) return {};\n      ++fail;\n      int i = RNG(0, len(I)), j = RNG(0, len(other));\n\
    \      swap(other[j], other.back());\n      int a = I[i], b = I[(i + 1) % len(I)],\
    \ c = other.back();\n      if ((point[b] - point[a]).det(point[c] - point[a])\
    \ < 0) continue;\n      if (CT.count3(a, b, c)) continue;\n      if (CT.count2(a,\
    \ c) + CT.count2(b, c)) continue;\n      bool ok = 1;\n      for (auto& v: {a,\
    \ b}) {\n        FOR(i, len(I)) {\n          Segment<ll> S1(point[v], point[c]);\n\
    \          Segment<ll> S2(point[I[i]], point[I[(i + 1) % len(I)]]);\n        \
    \  if (count_cross(S1, S2, false)) ok = 0;\n        }\n      }\n      if (!ok)\
    \ continue;\n      fail = 0;\n      I.insert(I.begin() + i + 1, POP(other));\n\
    \    }\n    point = rearrange(point, I);\n    FOR(i, N) {\n      if ((point[(i\
    \ + 2) % N] - point[i]).det(point[(i + 1) % N] - point[i]) == 0) return {};\n\
    \    }\n    return point;\n  };\n  while (1) {\n    vc<P> ANS = trial();\n   \
    \ if (ANS.empty()) continue;\n    int k = RNG(0, len(ANS));\n    rotate(ANS.begin(),\
    \ ANS.begin() + k, ANS.end());\n    return ANS;\n  }\n}\n#line 2 \"ds/splaytree/splaytree.hpp\"\
    \n// Node \u578B\u3092\u5225\u306B\u5B9A\u7FA9\u3057\u3066\u4F7F\u3046\ntemplate\
    \ <typename Node>\nstruct SplayTree {\n  Node *pool;\n  const int NODES;\n  int\
    \ pid;\n  using np = Node *;\n  using X = typename Node::value_type;\n  using\
    \ A = typename Node::operator_type;\n  vc<np> FREE;\n\n  SplayTree(int NODES)\
    \ : NODES(NODES), pid(0) { pool = new Node[NODES]; }\n  ~SplayTree() { delete[]\
    \ pool; }\n\n  void free_subtree(np c) {\n    auto dfs = [&](auto &dfs, np c)\
    \ -> void {\n      if (c->l) dfs(dfs, c->l);\n      if (c->r) dfs(dfs, c->r);\n\
    \      FREE.eb(c);\n    };\n    dfs(dfs, c);\n  }\n\n  void reset() {\n    pid\
    \ = 0;\n    FREE.clear();\n  }\n\n  np new_root() { return nullptr; }\n\n  np\
    \ new_node(const X &x) {\n    assert(!FREE.empty() || pid < NODES);\n    np n\
    \ = (FREE.empty() ? &(pool[pid++]) : POP(FREE));\n    Node::new_node(n, x);\n\
    \    return n;\n  }\n\n  np new_node(const vc<X> &dat) {\n    auto dfs = [&](auto\
    \ &dfs, int l, int r) -> np {\n      if (l == r) return nullptr;\n      if (r\
    \ == l + 1) return new_node(dat[l]);\n      int m = (l + r) / 2;\n      np l_root\
    \ = dfs(dfs, l, m);\n      np r_root = dfs(dfs, m + 1, r);\n      np root = new_node(dat[m]);\n\
    \      root->l = l_root, root->r = r_root;\n      if (l_root) l_root->p = root;\n\
    \      if (r_root) r_root->p = root;\n      root->update();\n      return root;\n\
    \    };\n    return dfs(dfs, 0, len(dat));\n  }\n\n  u32 get_size(np root) { return\
    \ (root ? root->size : 0); }\n\n  np merge(np l_root, np r_root) {\n    if (!l_root)\
    \ return r_root;\n    if (!r_root) return l_root;\n    assert((!l_root->p) &&\
    \ (!r_root->p));\n    splay_kth(r_root, 0); // splay \u3057\u305F\u306E\u3067\
    \ prop \u6E08\n    r_root->l = l_root;\n    l_root->p = r_root;\n    r_root->update();\n\
    \    return r_root;\n  }\n  np merge3(np a, np b, np c) { return merge(merge(a,\
    \ b), c); }\n  np merge4(np a, np b, np c, np d) { return merge(merge(merge(a,\
    \ b), c), d); }\n\n  pair<np, np> split(np root, u32 k) {\n    assert(!root ||\
    \ !root->p);\n    if (k == 0) return {nullptr, root};\n    if (k == (root->size))\
    \ return {root, nullptr};\n    splay_kth(root, k - 1);\n    np right = root->r;\n\
    \    root->r = nullptr, right->p = nullptr;\n    root->update();\n    return {root,\
    \ right};\n  }\n  tuple<np, np, np> split3(np root, u32 l, u32 r) {\n    np nm,\
    \ nr;\n    tie(root, nr) = split(root, r);\n    tie(root, nm) = split(root, l);\n\
    \    return {root, nm, nr};\n  }\n  tuple<np, np, np, np> split4(np root, u32\
    \ i, u32 j, u32 k) {\n    np d;\n    tie(root, d) = split(root, k);\n    auto\
    \ [a, b, c] = split3(root, i, j);\n    return {a, b, c, d};\n  }\n\n  // \u90E8\
    \u5206\u6728\u304C\u533A\u9593 [l,r) \u306B\u5BFE\u5FDC\u3059\u308B\u3088\u3046\
    \u306A\u30CE\u30FC\u30C9\u3092\u4F5C\u3063\u3066\u8FD4\u3059\n  // \u305D\u306E\
    \u30CE\u30FC\u30C9\u304C root \u306B\u306A\u308B\u308F\u3051\u3067\u306F\u306A\
    \u3044\u306E\u3067\u3001\n  // \u3053\u306E\u30CE\u30FC\u30C9\u3092\u53C2\u7167\
    \u3057\u305F\u5F8C\u306B\u3059\u3050\u306B splay \u3057\u3066\u6839\u306B\u6301\
    \u3061\u4E0A\u3052\u308B\u3053\u3068\n  void goto_between(np &root, u32 l, u32\
    \ r) {\n    if (l == 0 && r == root->size) return;\n    if (l == 0) {\n      splay_kth(root,\
    \ r);\n      root = root->l;\n      return;\n    }\n    if (r == root->size) {\n\
    \      splay_kth(root, l - 1);\n      root = root->r;\n      return;\n    }\n\
    \    splay_kth(root, r);\n    np rp = root;\n    root = rp->l;\n    root->p =\
    \ nullptr;\n    splay_kth(root, l - 1);\n    root->p = rp;\n    rp->l = root;\n\
    \    rp->update();\n    root = root->r;\n  }\n\n  vc<X> get_all(const np &root)\
    \ {\n    vc<X> res;\n    auto dfs = [&](auto &dfs, np root) -> void {\n      if\
    \ (!root) return;\n      root->prop();\n      dfs(dfs, root->l);\n      res.eb(root->get());\n\
    \      dfs(dfs, root->r);\n    };\n    dfs(dfs, root);\n    return res;\n  }\n\
    \n  X get(np &root, u32 k) {\n    assert(root == nullptr || !root->p);\n    splay_kth(root,\
    \ k);\n    return root->get();\n  }\n\n  void set(np &root, u32 k, const X &x)\
    \ {\n    assert(root != nullptr && !root->p);\n    splay_kth(root, k);\n    root->set(x);\n\
    \  }\n\n  void multiply(np &root, u32 k, const X &x) {\n    assert(root != nullptr\
    \ && !root->p);\n    splay_kth(root, k);\n    root->multiply(x);\n  }\n\n  X prod(np\
    \ &root, u32 l, u32 r) {\n    assert(root == nullptr || !root->p);\n    using\
    \ Mono = typename Node::Monoid_X;\n    if (l == r) return Mono::unit();\n    assert(0\
    \ <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n    X res\
    \ = root->prod;\n    splay(root, true);\n    return res;\n  }\n\n  X prod(np &root)\
    \ {\n    assert(root == nullptr || !root->p);\n    using Mono = typename Node::Monoid_X;\n\
    \    return (root ? root->prod : Mono::unit());\n  }\n\n  void apply(np &root,\
    \ u32 l, u32 r, const A &a) {\n    if (l == r) return;\n    assert(0 <= l && l\
    \ < r && r <= root->size);\n    goto_between(root, l, r);\n    root->apply(a);\n\
    \    splay(root, true);\n  }\n  void apply(np &root, const A &a) {\n    if (!root)\
    \ return;\n    root->apply(a);\n  }\n\n  void reverse(np &root, u32 l, u32 r)\
    \ {\n    assert(root == nullptr || !root->p);\n    if (l == r) return;\n    assert(0\
    \ <= l && l < r && r <= root->size);\n    goto_between(root, l, r);\n    root->reverse();\n\
    \    splay(root, true);\n  }\n  void reverse(np root) {\n    if (!root) return;\n\
    \    root->reverse();\n  }\n\n  void rotate(Node *n) {\n    // n \u3092\u6839\u306B\
    \u8FD1\u3065\u3051\u308B\u3002prop, update \u306F rotate \u306E\u5916\u3067\u884C\
    \u3046\u3002\n    Node *pp, *p, *c;\n    p = n->p;\n    pp = p->p;\n    if (p->l\
    \ == n) {\n      c = n->r;\n      n->r = p;\n      p->l = c;\n    } else {\n \
    \     c = n->l;\n      n->l = p;\n      p->r = c;\n    }\n    if (pp && pp->l\
    \ == p) pp->l = n;\n    if (pp && pp->r == p) pp->r = n;\n    n->p = pp;\n   \
    \ p->p = n;\n    if (c) c->p = p;\n  }\n\n  void prop_from_root(np c) {\n    if\
    \ (!c->p) {\n      c->prop();\n      return;\n    }\n    prop_from_root(c->p);\n\
    \    c->prop();\n  }\n\n  void splay(Node *me, bool prop_from_root_done) {\n \
    \   // \u3053\u308C\u3092\u547C\u3076\u6642\u70B9\u3067\u3001me \u306E\u7956\u5148\
    \uFF08me \u3092\u9664\u304F\uFF09\u306F\u65E2\u306B prop \u6E08\u3067\u3042\u308B\
    \u3053\u3068\u3092\u4EEE\u5B9A\n    // \u7279\u306B\u3001splay \u7D42\u4E86\u6642\
    \u70B9\u3067 me \u306F upd / prop \u6E08\u3067\u3042\u308B\n    if (!prop_from_root_done)\
    \ prop_from_root(me);\n    me->prop();\n    while (me->p) {\n      np p = me->p;\n\
    \      np pp = p->p;\n      if (!pp) {\n        rotate(me);\n        p->update();\n\
    \        break;\n      }\n      bool same = (p->l == me && pp->l == p) || (p->r\
    \ == me && pp->r == p);\n      if (same) rotate(p), rotate(me);\n      if (!same)\
    \ rotate(me), rotate(me);\n      pp->update(), p->update();\n    }\n    // me\
    \ \u306E update \u306F\u6700\u5F8C\u3060\u3051\u3067\u3088\u3044\n    me->update();\n\
    \  }\n\n  void splay_kth(np &root, u32 k) {\n    assert(0 <= k && k < (root->size));\n\
    \    while (1) {\n      root->prop();\n      u32 sl = (root->l ? root->l->size\
    \ : 0);\n      if (k == sl) break;\n      if (k < sl)\n        root = root->l;\n\
    \      else {\n        k -= sl + 1;\n        root = root->r;\n      }\n    }\n\
    \    splay(root, true);\n  }\n\n  // check(x), \u5DE6\u5074\u306E\u30CE\u30FC\u30C9\
    \u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\u3088\u3046\u306B\u5207\u308B\
    \n  template <typename F>\n  pair<np, np> split_max_right(np root, F check) {\n\
    \    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n    np c =\
    \ find_max_right(root, check);\n    if (!c) {\n      splay(root, true);\n    \
    \  return {nullptr, root};\n    }\n    splay(c, true);\n    np right = c->r;\n\
    \    if (!right) return {c, nullptr};\n    right->p = nullptr;\n    c->r = nullptr;\n\
    \    c->update();\n    return {c, right};\n  }\n\n  // check(x, cnt), \u5DE6\u5074\
    \u306E\u30CE\u30FC\u30C9\u5168\u4F53\u304C check \u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np, np> split_max_right_cnt(np\
    \ root, F check) {\n    if (!root) return {nullptr, nullptr};\n    assert(!root->p);\n\
    \    np c = find_max_right_cnt(root, check);\n    if (!c) {\n      splay(root,\
    \ true);\n      return {nullptr, root};\n    }\n    splay(c, true);\n    np right\
    \ = c->r;\n    if (!right) return {c, nullptr};\n    right->p = nullptr;\n   \
    \ c->r = nullptr;\n    c->update();\n    return {c, right};\n  }\n\n  // \u5DE6\
    \u5074\u306E\u30CE\u30FC\u30C9\u5168\u4F53\u306E prod \u304C check \u3092\u6E80\
    \u305F\u3059\u3088\u3046\u306B\u5207\u308B\n  template <typename F>\n  pair<np,\
    \ np> split_max_right_prod(np root, F check) {\n    if (!root) return {nullptr,\
    \ nullptr};\n    assert(!root->p);\n    np c = find_max_right_prod(root, check);\n\
    \    if (!c) {\n      splay(root, true);\n      return {nullptr, root};\n    }\n\
    \    splay(c, true);\n    np right = c->r;\n    if (!right) return {c, nullptr};\n\
    \    right->p = nullptr;\n    c->r = nullptr;\n    c->update();\n    return {c,\
    \ right};\n  }\n\n  template <typename F>\n  np find_max_right(np root, const\
    \ F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\
    \u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok = nullptr,\
    \ last = nullptr;\n    while (root) {\n      last = root;\n      root->prop();\n\
    \      if (check(root->x)) {\n        last_ok = root;\n        root = root->r;\n\
    \      } else {\n        root = root->l;\n      }\n    }\n    splay(last, true);\n\
    \    return last_ok;\n  }\n\n  template <typename F>\n  np find_max_right_cnt(np\
    \ root, const F &check) {\n    // \u6700\u5F8C\u306B\u898B\u3064\u3051\u305F ok\
    \ \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\u3057\u305F\u70B9\n    np last_ok\
    \ = nullptr, last = nullptr;\n    ll n = 0;\n    while (root) {\n      last =\
    \ root;\n      root->prop();\n      ll ns = (root->l ? root->l->size : 0);\n \
    \     if (check(root->x, n + ns + 1)) {\n        last_ok = root;\n        n +=\
    \ ns + 1;\n        root = root->r;\n      } else {\n        root = root->l;\n\
    \      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n\n  template\
    \ <typename F>\n  np find_max_right_prod(np root, const F &check) {\n    using\
    \ Mono = typename Node::Monoid_X;\n    X prod = Mono::unit();\n    // \u6700\u5F8C\
    \u306B\u898B\u3064\u3051\u305F ok \u306E\u70B9\u3001\u6700\u5F8C\u306B\u63A2\u7D22\
    \u3057\u305F\u70B9\n    np last_ok = nullptr, last = nullptr;\n    while (root)\
    \ {\n      last = root;\n      root->prop();\n      X lprod = prod;\n      if\
    \ (root->l) lprod = Mono::op(lprod, root->l->prod);\n      lprod = Mono::op(lprod,\
    \ root->x);\n      if (check(lprod)) {\n        prod = lprod;\n        last_ok\
    \ = root;\n        root = root->r;\n      } else {\n        root = root->l;\n\
    \      }\n    }\n    splay(last, true);\n    return last_ok;\n  }\n};\n#line 2\
    \ \"ds/splaytree/splaytree_basic.hpp\"\n\nnamespace SplayTreeNodes {\ntemplate\
    \ <typename S>\nstruct Node_Basic {\n  using value_type = S;\n  using operator_type\
    \ = int;\n  using np = Node_Basic *;\n\n  np p, l, r;\n  bool rev;\n  S x;\n \
    \ u32 size;\n\n  static void new_node(np n, const S &x) {\n    n->p = n->l = n->r\
    \ = nullptr;\n    n->x = x, n->size = 1, n->rev = 0;\n  }\n\n  void update() {\n\
    \    size = 1;\n    if (l) { size += l->size; }\n    if (r) { size += r->size;\
    \ }\n  }\n\n  void prop() {\n    if (rev) {\n      if (l) { l->rev ^= 1, swap(l->l,\
    \ l->r); }\n      if (r) { r->rev ^= 1, swap(r->l, r->r); }\n      rev = 0;\n\
    \    }\n  }\n\n  // update, prop \u4EE5\u5916\u3067\u547C\u3070\u308C\u308B\u3082\
    \u306E\u306F\u3001splay \u5F8C\u3067\u3042\u308B\u3053\u3068\u304C\u60F3\u5B9A\
    \u3055\u308C\u3066\u3044\u308B\u3002\n  // \u3057\u305F\u304C\u3063\u3066\u305D\
    \u306E\u6642\u70B9\u3067 update, prop \u6E08\u3067\u3042\u308B\u3053\u3068\u3092\
    \u4EEE\u5B9A\u3057\u3066\u3088\u3044\u3002\n  S get() { return x; }\n  void set(const\
    \ S &xx) {\n    x = xx;\n    update();\n  }\n  void reverse() {\n    swap(l, r);\n\
    \    rev ^= 1;\n  }\n};\ntemplate <typename S>\nusing SplayTree_Basic = SplayTree<Node_Basic<S>>;\n\
    } // namespace SplayTreeNodes\n\nusing SplayTreeNodes::SplayTree_Basic;\n#line\
    \ 2 \"graph/base.hpp\"\n\ntemplate <typename T>\nstruct Edge {\n  int frm, to;\n\
    \  T cost;\n  int id;\n};\n\ntemplate <typename T = int, bool directed = false>\n\
    struct Graph {\n  static constexpr bool is_directed = directed;\n  int N, M;\n\
    \  using cost_type = T;\n  using edge_type = Edge<T>;\n  vector<edge_type> edges;\n\
    \  vector<int> indptr;\n  vector<edge_type> csr_edges;\n  vc<int> vc_deg, vc_indeg,\
    \ vc_outdeg;\n  bool prepared;\n\n  class OutgoingEdges {\n  public:\n    OutgoingEdges(const\
    \ Graph* G, int l, int r) : G(G), l(l), r(r) {}\n\n    const edge_type* begin()\
    \ const {\n      if (l == r) { return 0; }\n      return &G->csr_edges[l];\n \
    \   }\n\n    const edge_type* end() const {\n      if (l == r) { return 0; }\n\
    \      return &G->csr_edges[r];\n    }\n\n  private:\n    const Graph* G;\n  \
    \  int l, r;\n  };\n\n  bool is_prepared() { return prepared; }\n\n  Graph() :\
    \ N(0), M(0), prepared(0) {}\n  Graph(int N) : N(N), M(0), prepared(0) {}\n\n\
    \  void build(int n) {\n    N = n, M = 0;\n    prepared = 0;\n    edges.clear();\n\
    \    indptr.clear();\n    csr_edges.clear();\n    vc_deg.clear();\n    vc_indeg.clear();\n\
    \    vc_outdeg.clear();\n  }\n\n  void add(int frm, int to, T cost = 1, int i\
    \ = -1) {\n    assert(!prepared);\n    assert(0 <= frm && 0 <= to && to < N);\n\
    \    if (i == -1) i = M;\n    auto e = edge_type({frm, to, cost, i});\n    edges.eb(e);\n\
    \    ++M;\n  }\n\n#ifdef FASTIO\n  // wt, off\n  void read_tree(bool wt = false,\
    \ int off = 1) { read_graph(N - 1, wt, off); }\n\n  void read_graph(int M, bool\
    \ wt = false, int off = 1) {\n    for (int m = 0; m < M; ++m) {\n      INT(a,\
    \ b);\n      a -= off, b -= off;\n      if (!wt) {\n        add(a, b);\n     \
    \ } else {\n        T c;\n        read(c);\n        add(a, b, c);\n      }\n \
    \   }\n    build();\n  }\n#endif\n\n  void build() {\n    assert(!prepared);\n\
    \    prepared = true;\n    indptr.assign(N + 1, 0);\n    for (auto&& e: edges)\
    \ {\n      indptr[e.frm + 1]++;\n      if (!directed) indptr[e.to + 1]++;\n  \
    \  }\n    for (int v = 0; v < N; ++v) { indptr[v + 1] += indptr[v]; }\n    auto\
    \ counter = indptr;\n    csr_edges.resize(indptr.back() + 1);\n    for (auto&&\
    \ e: edges) {\n      csr_edges[counter[e.frm]++] = e;\n      if (!directed)\n\
    \        csr_edges[counter[e.to]++] = edge_type({e.to, e.frm, e.cost, e.id});\n\
    \    }\n  }\n\n  OutgoingEdges operator[](int v) const {\n    assert(prepared);\n\
    \    return {this, indptr[v], indptr[v + 1]};\n  }\n\n  vc<int> deg_array() {\n\
    \    if (vc_deg.empty()) calc_deg();\n    return vc_deg;\n  }\n\n  pair<vc<int>,\
    \ vc<int>> deg_array_inout() {\n    if (vc_indeg.empty()) calc_deg_inout();\n\
    \    return {vc_indeg, vc_outdeg};\n  }\n\n  int deg(int v) {\n    if (vc_deg.empty())\
    \ calc_deg();\n    return vc_deg[v];\n  }\n\n  int in_deg(int v) {\n    if (vc_indeg.empty())\
    \ calc_deg_inout();\n    return vc_indeg[v];\n  }\n\n  int out_deg(int v) {\n\
    \    if (vc_outdeg.empty()) calc_deg_inout();\n    return vc_outdeg[v];\n  }\n\
    \n#ifdef FASTIO\n  void debug() {\n    print(\"Graph\");\n    if (!prepared) {\n\
    \      print(\"frm to cost id\");\n      for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cost, e.id);\n    } else {\n      print(\"indptr\", indptr);\n      print(\"\
    frm to cost id\");\n      FOR(v, N) for (auto&& e: (*this)[v]) print(e.frm, e.to,\
    \ e.cost, e.id);\n    }\n  }\n#endif\n\n  vc<int> new_idx;\n  vc<bool> used_e;\n\
    \n  // G \u306B\u304A\u3051\u308B\u9802\u70B9 V[i] \u304C\u3001\u65B0\u3057\u3044\
    \u30B0\u30E9\u30D5\u3067 i \u306B\u306A\u308B\u3088\u3046\u306B\u3059\u308B\n\
    \  // {G, es}\n  // sum(deg(v)) \u306E\u8A08\u7B97\u91CF\u306B\u306A\u3063\u3066\
    \u3044\u3066\u3001\n  // \u65B0\u3057\u3044\u30B0\u30E9\u30D5\u306E n+m \u3088\
    \u308A\u5927\u304D\u3044\u53EF\u80FD\u6027\u304C\u3042\u308B\u306E\u3067\u6CE8\
    \u610F\n  Graph<T, directed> rearrange(vc<int> V, bool keep_eid = 0) {\n    if\
    \ (len(new_idx) != N) new_idx.assign(N, -1);\n    int n = len(V);\n    FOR(i,\
    \ n) new_idx[V[i]] = i;\n    Graph<T, directed> G(n);\n    vc<int> history;\n\
    \    FOR(i, n) {\n      for (auto&& e: (*this)[V[i]]) {\n        if (len(used_e)\
    \ <= e.id) used_e.resize(e.id + 1);\n        if (used_e[e.id]) continue;\n   \
    \     int a = e.frm, b = e.to;\n        if (new_idx[a] != -1 && new_idx[b] !=\
    \ -1) {\n          history.eb(e.id);\n          used_e[e.id] = 1;\n          int\
    \ eid = (keep_eid ? e.id : -1);\n          G.add(new_idx[a], new_idx[b], e.cost,\
    \ eid);\n        }\n      }\n    }\n    FOR(i, n) new_idx[V[i]] = -1;\n    for\
    \ (auto&& eid: history) used_e[eid] = 0;\n    G.build();\n    return G;\n  }\n\
    \n  Graph<T, true> to_directed_tree(int root = -1) {\n    if (root == -1) root\
    \ = 0;\n    assert(!is_directed && prepared && M == N - 1);\n    Graph<T, true>\
    \ G1(N);\n    vc<int> par(N, -1);\n    auto dfs = [&](auto& dfs, int v) -> void\
    \ {\n      for (auto& e: (*this)[v]) {\n        if (e.to == par[v]) continue;\n\
    \        par[e.to] = v, dfs(dfs, e.to);\n      }\n    };\n    dfs(dfs, root);\n\
    \    for (auto& e: edges) {\n      int a = e.frm, b = e.to;\n      if (par[a]\
    \ == b) swap(a, b);\n      assert(par[b] == a);\n      G1.add(a, b, e.cost);\n\
    \    }\n    G1.build();\n    return G1;\n  }\n\nprivate:\n  void calc_deg() {\n\
    \    assert(vc_deg.empty());\n    vc_deg.resize(N);\n    for (auto&& e: edges)\
    \ vc_deg[e.frm]++, vc_deg[e.to]++;\n  }\n\n  void calc_deg_inout() {\n    assert(vc_indeg.empty());\n\
    \    vc_indeg.resize(N);\n    vc_outdeg.resize(N);\n    for (auto&& e: edges)\
    \ { vc_indeg[e.to]++, vc_outdeg[e.frm]++; }\n  }\n};\n#line 4 \"graph/planar_graph.hpp\"\
    \n\n/*\n\u30FB\u9023\u7D50\u5E73\u9762\u30B0\u30E9\u30D5\u306B\u306A\u3063\u3066\
    \u3044\u306A\u3044\u3068\u304D\u306B\u3069\u3046\u52D5\u4F5C\u3059\u308B\u304B\
    \u306F\u4F55\u3082\u8003\u3048\u3066\u3044\u306A\u3044\n\u30FBN=1 \u3082\u6271\
    \u308F\u306A\u3044\n\u30FB0\u756A\u76EE\u306B\u5916\u9762\u304C\u5165\u308B\n\
    */\ntemplate <typename XY>\nstruct Planar_Graph {\n  using P = Point<XY>;\n  int\
    \ NV, NE, NF;\n  // \u9802\u70B9, \u8FBA\u304B\u3089\u306A\u308B\u30B0\u30E9\u30D5\
    . \u6709\u5411\u8FBA\u3092 2 \u3064\u5165\u308C\u3066\u304A\u304F\n  Graph<int,\
    \ 1> G;\n  // \u9802\u70B9\u5C5E\u6027\n  vc<P> point; // \u5EA7\u6A19\n  // \u8FBA\
    \u5C5E\u6027\n  vc<int> left_face; // \u6709\u5411\u8FBA\u306E\u5DE6\u306B\u3042\
    \u308B\u9762\u306E\u756A\u53F7\n  vc<int> nxt_edge;  // \u9762\u3092\u53CD\u6642\
    \u8A08\u56DE\u308A\u306B\u307E\u308F\u308B\u3068\u304D\u306E\u6B21\u306E\u8FBA\
    \n  // \u9762\u5C5E\u6027\n  vc<int> first_edge;\n\n  Planar_Graph(int N, vc<P>\
    \ point) : NV(N), G(N), point(point) { assert(N > 1); }\n\n  void add(int a, int\
    \ b) { G.add(a, b), G.add(b, a); }\n  void build() {\n    G.build();\n    NE =\
    \ G.M / 2;\n    nxt_edge.assign(G.M, -1);\n    left_face.assign(G.M, -1);\n  \
    \  int v0 = 0;\n    int e0 = 0;\n    FOR(v, NV) {\n      if (point[v] < point[v0])\
    \ v0 = v;\n      vc<int> eid;\n      vc<P> dir;\n      for (auto& e: G[v]) {\n\
    \        eid.eb(e.id);\n        dir.eb(point[e.to] - point[e.frm]);\n      }\n\
    \      auto I = angle_sort(dir);\n      assert(len(I) > 0);\n      FOR(k, len(I))\
    \ {\n        int i = (k == 0 ? I.back() : I[k - 1]);\n        int j = I[k];\n\
    \        i = eid[i], j = eid[j];\n        nxt_edge[j ^ 1] = i;\n      }\n    \
    \  if (v == v0) e0 = eid[I[0]] ^ 1;\n    }\n    for (auto& x: nxt_edge) assert(x\
    \ != -1);\n\n    auto make_face = [&](int e) -> void {\n      int p = len(first_edge);\n\
    \      first_edge.eb(e);\n      while (left_face[e] == -1) {\n        left_face[e]\
    \ = p;\n        e = nxt_edge[e];\n      }\n    };\n\n    make_face(e0);\n    FOR(e,\
    \ 2 * NE) {\n      if (left_face[e] == -1) make_face(e);\n    }\n    NF = len(first_edge);\n\
    \    assert(NV - NE + NF == 2);\n  }\n\n  // return {vs, es}\n  // vs = [v0,v1,v2,v0],\
    \ es = [e0,e1,e2]\n  pair<vc<int>, vc<int>> get_face_data(int fid) {\n    vc<int>\
    \ eid = {first_edge[fid]};\n    while (1) {\n      int e = nxt_edge[eid.back()];\n\
    \      if (e == first_edge[fid]) break;\n      eid.eb(e);\n    }\n    vc<int>\
    \ vid;\n    for (auto& e: eid) vid.eb(G.edges[e].frm);\n    vid.eb(vid[0]);\n\
    \    return {vid, eid};\n  }\n};\n#line 4 \"geo/polygon_triangulation.hpp\"\n\n\
    template <typename T>\nvc<tuple<int, int, int>> monotone_polygon_triangulation(vc<Point<T>>\
    \ point) {\n  int N = len(point);\n  int rot = min_element(all(point)) - point.begin();\n\
    \  rotate(point.begin(), point.begin() + rot, point.end());\n  int n = max_element(all(point))\
    \ - point.begin();\n  FOR(i, n) assert(point[i] < point[i + 1]);\n  FOR(i, n,\
    \ N) assert(point[(i + 1) % N] < point[i]);\n  vc<tuple<int, int, int>> res;\n\
    \  auto side = [&](int i) -> int {\n    assert(i != 0 && i != n);\n    return\
    \ (i < n ? 0 : 1);\n  };\n  vc<int> I = argsort(point);\n  vc<int> stack = {I[0],\
    \ I[1]};\n  int s = side(I[1]);\n  FOR(i, 2, N - 1) {\n    int v = I[i], t = side(v);\n\
    \    if (s == 0 && t == 0) {\n      while (len(stack) >= 2 && ccw(point[stack[len(stack)\
    \ - 2]], point[stack[len(stack) - 1]], point[v]) == 1) {\n        res.eb(stack[len(stack)\
    \ - 2], stack[len(stack) - 1], v), POP(stack);\n      }\n      stack.eb(v);\n\
    \    }\n    elif (s == 1 && t == 1) {\n      while (len(stack) >= 2 && ccw(point[stack[len(stack)\
    \ - 2]], point[stack[len(stack) - 1]], point[v]) == -1) {\n        res.eb(stack[len(stack)\
    \ - 2], v, stack[len(stack) - 1]), POP(stack);\n      }\n      stack.eb(v);\n\
    \    }\n    elif (s == 0 && t == 1) {\n      FOR(j, len(stack) - 1) res.eb(stack[j],\
    \ stack[j + 1], v);\n      stack = {stack.back(), v}, s = t;\n    }\n    elif\
    \ (s == 1 && t == 0) {\n      FOR(j, len(stack) - 1) res.eb(stack[j], v, stack[j\
    \ + 1]);\n      stack = {stack.back(), v}, s = t;\n    }\n  }\n  if (s == 0) {\
    \ FOR(j, len(stack) - 1) res.eb(stack[j], stack[j + 1], n); }\n  elif (s == 1)\
    \ { FOR(j, len(stack) - 1) res.eb(stack[j], n, stack[j + 1]); }\n  for (auto&\
    \ [a, b, c]: res) a = (a + rot) % N, b = (b + rot) % N, c = (c + rot) % N;\n \
    \ return res;\n}\n\n// (i,j,k), ccw\ntemplate <typename T>\nvc<tuple<int, int,\
    \ int>> polygon_triangulation(vc<Point<T>> point) {\n  using P = Point<T>;\n \
    \ int N = len(point);\n  enum vtype { MERGE, SPLIT, START, END, UPPER, LOWER };\n\
    \  auto pre = [&](int i) -> int { return (i > 0 ? i - 1 : N - 1); };\n  auto nxt\
    \ = [&](int i) -> int { return (i < N - 1 ? i + 1 : 0); };\n  auto get_vtype =\
    \ [&](int i) -> vtype {\n    int l = pre(i), r = nxt(i);\n    if (point[i] < point[l]\
    \ && point[i] < point[r]) { return (ccw(point[l], point[i], point[r]) == 1 ? START\
    \ : SPLIT); }\n    if (point[l] < point[i] && point[r] < point[i]) { return (ccw(point[l],\
    \ point[i], point[r]) == 1 ? END : MERGE); }\n    if (point[l] < point[i] && point[i]\
    \ < point[r]) return LOWER;\n    if (point[r] < point[i] && point[i] < point[l])\
    \ return UPPER;\n    assert(0);\n  };\n  SplayTree_Basic<int> ST(N);\n  using\
    \ np = decltype(ST)::np;\n  vc<np> nodes(N);\n  FOR(i, N) nodes[i] = ST.new_node(i);\n\
    \  np S = ST.new_root();\n  auto comp = [&](int i, P p) -> bool {\n    P A = point[i],\
    \ B = point[nxt(i)];\n    return ccw(A, B, p) == -1;\n  };\n\n  vc<int> helper(N,\
    \ -1);\n  vc<bool> merged(N);\n\n  Planar_Graph<T> G(N, point);\n  FOR(i, N) G.add(i,\
    \ nxt(i));\n\n  auto add_edge = [&](int v, int w) -> void { merged[w] = 1, G.add(v,\
    \ w); };\n\n  auto fix_up = [&](int v, int e) -> void {\n    int w = helper[e];\n\
    \    if (get_vtype(w) == vtype::MERGE && !merged[w]) { add_edge(v, w); }\n  };\n\
    \  auto I = argsort(point);\n  for (auto& i: I) {\n    vtype t = get_vtype(i);\n\
    \    if (t == vtype::MERGE) {\n      ST.splay(nodes[i], 1), S = nodes[i];\n  \
    \    int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n      auto [L, M, R] = ST.split3(S,\
    \ n, n + 1);\n      int j = ST.get(R, 0);\n      S = ST.merge(L, R);\n      fix_up(i,\
    \ i), fix_up(i, j);\n      helper[j] = i;\n    }\n    if (t == vtype::SPLIT) {\n\
    \      auto [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k,\
    \ point[i]); });\n      int j = ST.get(R, 0);\n      add_edge(i, helper[j]);\n\
    \      helper[j] = i, helper[pre(i)] = i;\n      S = ST.merge3(L, nodes[pre(i)],\
    \ R);\n    }\n    if (t == vtype::START) {\n      auto [L, R] = ST.split_max_right(S,\
    \ [&](int k) -> bool { return comp(k, point[i]); });\n      S = ST.merge3(L, nodes[pre(i)],\
    \ R), helper[pre(i)] = i;\n    }\n    if (t == vtype::END) {\n      ST.splay(nodes[i],\
    \ 1), S = nodes[i];\n      int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n  \
    \    auto [L, M, R] = ST.split3(S, n, n + 1);\n      S = ST.merge(L, R);\n   \
    \   fix_up(i, i);\n    }\n    if (t == vtype::UPPER) {\n      ST.splay(nodes[i],\
    \ 1), S = nodes[i];\n      int n = (nodes[i]->l ? nodes[i]->l->size : 0);\n  \
    \    auto [L, M, R] = ST.split3(S, n, n + 1);\n      S = ST.merge3(L, nodes[pre(i)],\
    \ R);\n      fix_up(i, i);\n      helper[pre(i)] = i;\n    }\n    if (t == vtype::LOWER)\
    \ {\n      auto [L, R] = ST.split_max_right(S, [&](int k) -> bool { return comp(k,\
    \ point[i]); });\n      int j = ST.get(R, 0);\n      S = ST.merge(L, R);\n   \
    \   fix_up(i, j);\n      helper[j] = i;\n    }\n  }\n  G.build();\n  vc<tuple<int,\
    \ int, int>> ANS;\n  FOR(f, 1, G.NF) {\n    auto [vs, es] = G.get_face_data(f);\n\
    \    POP(vs);\n    vc<P> sub = rearrange(point, vs);\n    for (auto& [a, b, c]:\
    \ monotone_polygon_triangulation(sub)) ANS.eb(vs[a], vs[b], vs[c]);\n  }\n  return\
    \ ANS;\n}\n#line 6 \"test/1_mytest/polygon_triangulation.test.cpp\"\n\nvoid test()\
    \ {\n  auto check = [&](vc<Point<ll>> point) -> void {\n    int N = len(point);\n\
    \    auto dat = polygon_triangulation(point);\n    assert(len(dat) == N - 2);\n\
    \    // \u7C21\u6613\u30C6\u30B9\u30C8. \u9762\u7A4D\u548C\u304C\u3044\u3044\u611F\
    \u3058\u306E N-2 \u500B\u306B\u306A\u3063\u3066\u308C\u3070\u3044\u3044\u3053\u3068\
    \u306B\u3059\u308B.\n    ll AREA = 0, AREA3 = 0;\n    FOR(i, N) AREA += point[i].det(point[(i\
    \ + 1) % N]);\n    for (auto& [a, b, c]: dat) {\n      ll S = (point[b] - point[a]).det(point[c]\
    \ - point[a]);\n      assert(S > 0);\n      AREA3 += S;\n    }\n    assert(AREA\
    \ == AREA3);\n  };\n\n  FOR(10000) {\n    int N = RNG(3, 20);\n    int K = RNG(3,\
    \ 10);\n    vc<Point<ll>> point = random_polygon(N, K);\n    check(point);\n \
    \ }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\
    \\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"random/random_polygon.hpp\"\n#include \"geo/polygon_triangulation.hpp\"\
    \n\nvoid test() {\n  auto check = [&](vc<Point<ll>> point) -> void {\n    int\
    \ N = len(point);\n    auto dat = polygon_triangulation(point);\n    assert(len(dat)\
    \ == N - 2);\n    // \u7C21\u6613\u30C6\u30B9\u30C8. \u9762\u7A4D\u548C\u304C\u3044\
    \u3044\u611F\u3058\u306E N-2 \u500B\u306B\u306A\u3063\u3066\u308C\u3070\u3044\u3044\
    \u3053\u3068\u306B\u3059\u308B.\n    ll AREA = 0, AREA3 = 0;\n    FOR(i, N) AREA\
    \ += point[i].det(point[(i + 1) % N]);\n    for (auto& [a, b, c]: dat) {\n   \
    \   ll S = (point[b] - point[a]).det(point[c] - point[a]);\n      assert(S > 0);\n\
    \      AREA3 += S;\n    }\n    assert(AREA == AREA3);\n  };\n\n  FOR(10000) {\n\
    \    int N = RNG(3, 20);\n    int K = RNG(3, 10);\n    vc<Point<ll>> point = random_polygon(N,\
    \ K);\n    check(point);\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >>\
    \ b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main() {\n  test();\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn:
  - my_template.hpp
  - random/random_polygon.hpp
  - random/base.hpp
  - geo/base.hpp
  - geo/convex_hull.hpp
  - geo/cross_point.hpp
  - geo/count_points_in_triangles.hpp
  - geo/angle_sort.hpp
  - ds/fenwicktree/fenwicktree_01.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  - geo/polygon_triangulation.hpp
  - ds/splaytree/splaytree_basic.hpp
  - ds/splaytree/splaytree.hpp
  - graph/planar_graph.hpp
  - graph/base.hpp
  isVerificationFile: true
  path: test/1_mytest/polygon_triangulation.test.cpp
  requiredBy: []
  timestamp: '2024-10-01 03:45:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/1_mytest/polygon_triangulation.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/polygon_triangulation.test.cpp
- /verify/test/1_mytest/polygon_triangulation.test.cpp.html
title: test/1_mytest/polygon_triangulation.test.cpp
---
