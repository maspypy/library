---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':x:'
    path: ds/fenwicktree/fenwicktree_01.hpp
    title: ds/fenwicktree/fenwicktree_01.hpp
  - icon: ':x:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':x:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':x:'
    path: geo/cross_point.hpp
    title: geo/cross_point.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/random_polygon.hpp\"\n\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
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
    \ x < p.x;\n    return y < p.y;\n  }\n  T dot(const Point& other) const { return\
    \ x * other.x + y * other.y; }\n  T det(const Point& other) const { return x *\
    \ other.y - y * other.x; }\n\n  double norm() { return sqrtl(x * x + y * y); }\n\
    \  double angle() { return atan2(y, x); }\n\n  Point rotate(double theta) {\n\
    \    static_assert(!is_integral<T>::value);\n    double c = cos(theta), s = sin(theta);\n\
    \    return Point{c * x - s * y, s * x + c * y};\n  }\n  Point rot90(bool ccw)\
    \ { return (ccw ? Point{-y, x} : Point{y, -x}); }\n};\n\n#ifdef FASTIO\ntemplate\
    \ <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n\
    }\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n  fastio::wt('\
    \ ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\u3080\u3068\
    \u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 +1\u3001\u53F3\
    \u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename T>\nint ccw(Point<T>\
    \ A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n  if (x > 0) return\
    \ 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename REAL, typename\
    \ T, typename U>\nREAL dist(Point<T> A, Point<U> B) {\n  REAL dx = REAL(A.x) -\
    \ REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx * dx + dy *\
    \ dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n\
    \  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\
    \ a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x; }\n  Line(T x1, T y1,\
    \ T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename\
    \ U>\n  U eval(Point<U> P) {\n    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\
    \n  template <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n\
    \  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\
    \u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n   \
    \ if (b == 0 && a < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2) : Segment(Point<T>(x1, y1),\
    \ Point<T>(x2, y2)) {}\n\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B\
    \ - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C\
    \ - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\
    \ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle()\
    \ {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y,\
    \ REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n#line 2 \"geo/convex_hull.hpp\"\n\n#line 4 \"geo/convex_hull.hpp\"\
    \n\n// allow_180=true \u3067\u540C\u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\
    \u3053\u308F\u308C\u308B\n// full \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\
    \u306A\u308B\ntemplate <typename T, bool allow_180 = false>\nvector<int> ConvexHull(vector<Point<T>>&\
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
    }\n\n// 4 \u6B21\u5F0F\u307E\u3067\u767B\u5834\u3057\u3066\u3044\u308B\u3001\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u6CE8\u610F\uFF01\n// https://codeforces.com/contest/607/problem/E\n\
    template <typename REAL, typename T>\nvc<Point<REAL>> cross_point(const Circle<T>\
    \ C, const Line<T> L) {\n  T a = L.a, b = L.b, c = L.a * (C.O.x) + L.b * (C.O.y)\
    \ + L.c;\n  T r = C.r;\n  bool SW = 0;\n  T abs_a = (a < 0 ? -a : a);\n  T abs_b\
    \ = (b < 0 ? -b : b);\n  if (abs_a < abs_b) {\n    swap(a, b);\n    SW = 1;\n\
    \  }\n  // ax+by+c=0, x^2+y^2=r^2\n  T D = 4 * c * c * b * b - 4 * (a * a + b\
    \ * b) * (c * c - a * a * r * r);\n  if (D < 0) return {};\n  REAL sqD = sqrtl(D);\n\
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
    \n\r\n#line 4 \"geo/angle_sort.hpp\"\n\r\n// lower: -1, origin: 0, upper: 1, (-pi,pi]\r\
    \ntemplate <typename T> int lower_or_upper(const Point<T> &p) {\r\n  if (p.y !=\
    \ 0)\r\n    return (p.y > 0 ? 1 : -1);\r\n  if (p.x > 0)\r\n    return -1;\r\n\
    \  if (p.x < 0)\r\n    return 1;\r\n  return 0;\r\n}\r\n\r\n// L<R:-1, L==R:0,\
    \ L>R:1, (-pi,pi]\r\ntemplate <typename T> int angle_comp_3(const Point<T> &L,\
    \ const Point<T> &R) {\r\n  int a = lower_or_upper(L), b = lower_or_upper(R);\r\
    \n  if (a != b)\r\n    return (a < b ? -1 : +1);\r\n  T det = L.det(R);\r\n  if\
    \ (det > 0)\r\n    return -1;\r\n  if (det < 0)\r\n    return 1;\r\n  return 0;\r\
    \n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort,\
    \ (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<Point<T>> &P)\
    \ {\r\n  vc<int> I(len(P));\r\n  FOR(i, len(P)) I[i] = i;\r\n  sort(all(I), [&](auto\
    \ &L, auto &R) -> bool {\r\n    return angle_comp_3(P[L], P[R]) == -1;\r\n  });\r\
    \n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B\
    \ argsort, (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<pair<T,\
    \ T>> &P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
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
    \ k <= n; k += k & -k) dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int\
    \ k, E x) { add(k, G::op(G::inverse(prod(k, k + 1)), x)); }\n\n  template <class\
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
    \n\nstruct FenwickTree_01 {\n  using MX = Monoid_Add<int>;\n  int N, n;\n  vc<u64>\
    \ dat;\n  FenwickTree<Monoid_Add<int>> bit;\n  FenwickTree_01() {}\n  FenwickTree_01(int\
    \ n) { build(n); }\n  template <typename F>\n  FenwickTree_01(int n, F f) {\n\
    \    build(n, f);\n  }\n\n  void build(int m) {\n    N = m;\n    n = ceil<int>(N\
    \ + 1, 64);\n    dat.assign(n, u64(0));\n    bit.build(n);\n  }\n  void build(vc<int>\
    \ dat) {\n    build(len(dat), [&](int i) -> int { return dat[i]; });\n  }\n\n\
    \  template <typename F>\n  void build(int m, F f) {\n    N = m;\n    n = ceil<int>(N\
    \ + 1, 64);\n    dat.assign(n, u64(0));\n    FOR(i, N) { dat[i / 64] |= u64(f(i))\
    \ << (i % 64); }\n    bit.build(n, [&](int i) -> int { return popcnt(dat[i]);\
    \ });\n  }\n\n  int sum_all() { return bit.sum_all(); }\n  int sum(int k) { return\
    \ prefix_sum(k); }\n  int prefix_sum(int k) {\n    int ans = bit.sum(k / 64);\n\
    \    ans += popcnt(dat[k / 64] & ((u64(1) << (k % 64)) - 1));\n    return ans;\n\
    \  }\n  int sum(int L, int R) {\n    if (L == 0) return prefix_sum(R);\n    int\
    \ ans = 0;\n    ans -= popcnt(dat[L / 64] & ((u64(1) << (L % 64)) - 1));\n   \
    \ ans += popcnt(dat[R / 64] & ((u64(1) << (R % 64)) - 1));\n    ans += bit.sum(L\
    \ / 64, R / 64);\n    return ans;\n  }\n  int prod(int L, int R) { return sum(L,\
    \ R); }\n\n  void add(int k, int x) {\n    if (x == 1) add(k);\n    elif (x ==\
    \ -1) remove(k);\n    else assert(0);\n  }\n  void multiply(int k, int x) { add(k,\
    \ x); }\n\n  void add(int k) {\n    dat[k / 64] |= u64(1) << (k % 64);\n    bit.add(k\
    \ / 64, 1);\n  }\n  void remove(int k) {\n    dat[k / 64] &= ~(u64(1) << (k %\
    \ 64));\n    bit.add(k / 64, -1);\n  }\n\n  int kth(int k, int L = 0) {\n    if\
    \ (k >= sum_all()) return N;\n    k += popcnt(dat[L / 64] & ((u64(1) << (L % 64))\
    \ - 1));\n    L /= 64;\n    int mid = 0;\n    auto check = [&](auto e) -> bool\
    \ {\n      if (e <= k) chmax(mid, e);\n      return e <= k;\n    };\n    int idx\
    \ = bit.max_right(check, L);\n    if (idx == n) return N;\n    k -= mid;\n   \
    \ u64 x = dat[idx];\n    int p = popcnt(x);\n    if (p <= k) return N;\n    k\
    \ = binary_search([&](int n) -> bool { return (p - popcnt(x >> n)) <= k; }, 0,\
    \ 64, 0);\n    return 64 * idx + k;\n  }\n\n  int next(int k) {\n    int idx =\
    \ k / 64;\n    k %= 64;\n    u64 x = dat[idx] & ~((u64(1) << k) - 1);\n    if\
    \ (x) return 64 * idx + lowbit(x);\n    idx = bit.kth(0, idx + 1);\n    if (idx\
    \ == n || !dat[idx]) return N;\n    return 64 * idx + lowbit(dat[idx]);\n  }\n\
    \n  int prev(int k) {\n    if (k == N) --k;\n    int idx = k / 64;\n    k %= 64;\n\
    \    u64 x = dat[idx];\n    if (k < 63) x &= (u64(1) << (k + 1)) - 1;\n    if\
    \ (x) return 64 * idx + topbit(x);\n    idx = bit.min_left([&](auto e) -> bool\
    \ { return e <= 0; }, idx) - 1;\n    if (idx == -1) return -1;\n    return 64\
    \ * idx + topbit(dat[idx]);\n  }\n};\n#line 6 \"geo/count_points_in_triangles.hpp\"\
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
    \ ANS.begin() + k, ANS.end());\n    return ANS;\n  }\n}\n"
  code: "\n#include \"random/base.hpp\"\n#include \"geo/base.hpp\"\n#include \"geo/convex_hull.hpp\"\
    \n#include \"geo/cross_point.hpp\"\n#include \"geo/count_points_in_triangles.hpp\"\
    \n\nvc<Point<ll>> random_polygon(int N, int XY_ABS_MAX = 10) {\n  assert(N >=\
    \ 3);\n  using P = Point<ll>;\n  auto trial = [&]() -> vc<P> {\n    set<Point<ll>>\
    \ S;\n    while (len(S) < N) {\n      int x = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);\n\
    \      int y = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);\n      S.insert(Point<ll>(x,\
    \ y));\n    }\n    vc<P> point(all(S));\n    auto I = ConvexHull<ll, true>(point);\n\
    \    Count_Points_In_Triangles CT(point, point);\n    vc<int> other;\n    vc<int>\
    \ done(N);\n    for (auto& i: I) done[i]++;\n    if (MAX(done) >= 2) return {};\n\
    \    FOR(i, N) if (!done[i]) other.eb(i);\n    int fail = 0;\n    while (len(other))\
    \ {\n      if (fail > 1000) return {};\n      ++fail;\n      int i = RNG(0, len(I)),\
    \ j = RNG(0, len(other));\n      swap(other[j], other.back());\n      int a =\
    \ I[i], b = I[(i + 1) % len(I)], c = other.back();\n      if ((point[b] - point[a]).det(point[c]\
    \ - point[a]) < 0) continue;\n      if (CT.count3(a, b, c)) continue;\n      if\
    \ (CT.count2(a, c) + CT.count2(b, c)) continue;\n      bool ok = 1;\n      for\
    \ (auto& v: {a, b}) {\n        FOR(i, len(I)) {\n          Segment<ll> S1(point[v],\
    \ point[c]);\n          Segment<ll> S2(point[I[i]], point[I[(i + 1) % len(I)]]);\n\
    \          if (count_cross(S1, S2, false)) ok = 0;\n        }\n      }\n     \
    \ if (!ok) continue;\n      fail = 0;\n      I.insert(I.begin() + i + 1, POP(other));\n\
    \    }\n    point = rearrange(point, I);\n    FOR(i, N) {\n      if ((point[(i\
    \ + 2) % N] - point[i]).det(point[(i + 1) % N] - point[i]) == 0) return {};\n\
    \    }\n    return point;\n  };\n  while (1) {\n    vc<P> ANS = trial();\n   \
    \ if (ANS.empty()) continue;\n    int k = RNG(0, len(ANS));\n    rotate(ANS.begin(),\
    \ ANS.begin() + k, ANS.end());\n    return ANS;\n  }\n}"
  dependsOn:
  - random/base.hpp
  - geo/base.hpp
  - geo/convex_hull.hpp
  - geo/cross_point.hpp
  - geo/count_points_in_triangles.hpp
  - geo/angle_sort.hpp
  - ds/fenwicktree/fenwicktree_01.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: random/random_polygon.hpp
  requiredBy: []
  timestamp: '2025-05-18 17:51:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/polygon_triangulation.test.cpp
documentation_of: random/random_polygon.hpp
layout: document
redirect_from:
- /library/random/random_polygon.hpp
- /library/random/random_polygon.hpp.html
title: random/random_polygon.hpp
---
