---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':x:'
    path: geo/outcircle.hpp
    title: geo/outcircle.hpp
  - icon: ':x:'
    path: geo/triangle_area.hpp
    title: geo/triangle_area.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':question:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/5_atcoder/abc151f.test.cpp
    title: test/5_atcoder/abc151f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/problemset/problem/119/E
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n\
    \  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
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
    \ 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 1 \"geo/triangle_area.hpp\"\n\
    template <typename REAL, typename T>\nREAL triangle_area(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  return abs((B - A).det(C - A)) * 0.5;\n}\n#line 3 \"geo/outcircle.hpp\"\
    \n\ntemplate <typename REAL, typename T>\nCircle<REAL> outcircle(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  REAL b1 = B.x - A.x, b2 = B.y - A.y;\n  REAL c1 = C.x -\
    \ A.x, c2 = C.y - A.y;\n  REAL bb = (b1 * b1 + b2 * b2) / 2;\n  REAL cc = (c1\
    \ * c1 + c2 * c2) / 2;\n\n  REAL det = b1 * c2 - b2 * c1;\n  REAL x = (bb * c2\
    \ - b2 * cc) / det;\n  REAL y = (b1 * cc - bb * c1) / det;\n  REAL r = sqrt(x\
    \ * x + y * y);\n  x += A.x, y += A.y;\n  return Circle<REAL>(x, y, r);\n}\n\n\
    // ABC \u306E\u5916\u63A5\u5186\u306B\u5BFE\u3057\u3066\u5185\u5916\u3069\u3061\
    \u3089\u306B\u3042\u308B\u304B\n// \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A\
    -1\n// \u5EA7\u6A19\u306E 4 \u4E57\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u3057\u306A\u3044\u3088\u3046\u306B\u3059\u308B\ntemplate <typename T>\nint outcircle_side(Point<T>\
    \ A, Point<T> B, Point<T> C, Point<T> p) {\n  T d = (B - A).det(C - A);\n  assert(d\
    \ != 0);\n  if (d < 0) swap(B, C);\n  array<Point<T>, 3> pts = {A, B, C};\n  array<array<T,\
    \ 3>, 3> mat;\n  FOR(i, 3) {\n    T dx = pts[i].x - p.x, dy = pts[i].y - p.y;\n\
    \    mat[i][0] = dx, mat[i][1] = dy, mat[i][2] = dx * dx + dy * dy;\n  }\n  T\
    \ det = 0;\n  det += mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);\n\
    \  det += mat[0][1] * (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]);\n  det\
    \ += mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);\n  if (det ==\
    \ 0) return 0;\n  return (det > 0 ? 1 : -1);\n}\n#line 4 \"geo/minimum_enclosing_circle.hpp\"\
    \n\n// randomize \u3092\u5229\u7528\u3057\u305F expected O(N) \u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0\n// https://codeforces.com/problemset/problem/119/E\n// \u4F7F\
    \u3046\u9802\u70B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u304B\u3048\
    \u3059 {0} or {i,j,-1} or {i,j,k}\n// Computational Geometry, Section 4.7\ntemplate\
    \ <typename T>\ntuple<int, int, int> minimum_enclosing_circle(vc<Point<T>> points)\
    \ {\n  const int n = len(points);\n  assert(n >= 1);\n  if (n == 1) return {0,\
    \ -1, -1};\n  vc<int> I(n);\n  FOR(i, n) I[i] = i;\n  shuffle(I);\n\n  points\
    \ = rearrange(points, I);\n\n  tuple<int, int, int> c = {0, -1, -1};\n  auto contain\
    \ = [&](Point<T> p) -> bool {\n    auto [i, j, k] = c;\n    if (j == -1) { return\
    \ p == points[i]; }\n    if (k == -1) { return (points[i] - p).dot(points[j] -\
    \ p) <= 0; }\n    return outcircle_side(points[i], points[j], points[k], p) >=\
    \ 0;\n  };\n\n  FOR(i, 1, n) {\n    if (contain(points[i])) continue;\n    c =\
    \ {0, i, -1};\n    FOR(j, 1, i) {\n      if (contain(points[j])) continue;\n \
    \     c = {i, j, -1};\n      FOR(k, j) {\n        if (contain(points[k])) continue;\n\
    \        c = {i, j, k};\n      }\n    }\n  }\n  auto [i, j, k] = c;\n  if (i !=\
    \ -1) i = I[i];\n  if (j != -1) j = I[j];\n  if (k != -1) k = I[k];\n  return\
    \ {i, j, k};\n}\n"
  code: "#include \"geo/base.hpp\"\n#include \"random/shuffle.hpp\"\n#include \"geo/outcircle.hpp\"\
    \n\n// randomize \u3092\u5229\u7528\u3057\u305F expected O(N) \u30A2\u30EB\u30B4\
    \u30EA\u30BA\u30E0\n// https://codeforces.com/problemset/problem/119/E\n// \u4F7F\
    \u3046\u9802\u70B9\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u304B\u3048\
    \u3059 {0} or {i,j,-1} or {i,j,k}\n// Computational Geometry, Section 4.7\ntemplate\
    \ <typename T>\ntuple<int, int, int> minimum_enclosing_circle(vc<Point<T>> points)\
    \ {\n  const int n = len(points);\n  assert(n >= 1);\n  if (n == 1) return {0,\
    \ -1, -1};\n  vc<int> I(n);\n  FOR(i, n) I[i] = i;\n  shuffle(I);\n\n  points\
    \ = rearrange(points, I);\n\n  tuple<int, int, int> c = {0, -1, -1};\n  auto contain\
    \ = [&](Point<T> p) -> bool {\n    auto [i, j, k] = c;\n    if (j == -1) { return\
    \ p == points[i]; }\n    if (k == -1) { return (points[i] - p).dot(points[j] -\
    \ p) <= 0; }\n    return outcircle_side(points[i], points[j], points[k], p) >=\
    \ 0;\n  };\n\n  FOR(i, 1, n) {\n    if (contain(points[i])) continue;\n    c =\
    \ {0, i, -1};\n    FOR(j, 1, i) {\n      if (contain(points[j])) continue;\n \
    \     c = {i, j, -1};\n      FOR(k, j) {\n        if (contain(points[k])) continue;\n\
    \        c = {i, j, k};\n      }\n    }\n  }\n  auto [i, j, k] = c;\n  if (i !=\
    \ -1) i = I[i];\n  if (j != -1) j = I[j];\n  if (k != -1) k = I[k];\n  return\
    \ {i, j, k};\n}"
  dependsOn:
  - geo/base.hpp
  - random/shuffle.hpp
  - random/base.hpp
  - geo/outcircle.hpp
  - geo/triangle_area.hpp
  isVerificationFile: false
  path: geo/minimum_enclosing_circle.hpp
  requiredBy: []
  timestamp: '2024-09-14 09:20:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/5_atcoder/abc151f.test.cpp
documentation_of: geo/minimum_enclosing_circle.hpp
layout: document
redirect_from:
- /library/geo/minimum_enclosing_circle.hpp
- /library/geo/minimum_enclosing_circle.hpp.html
title: geo/minimum_enclosing_circle.hpp
---
