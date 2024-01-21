---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/triangle_area.hpp
    title: geo/triangle_area.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/minimum_enclosing_circle.hpp
    title: geo/minimum_enclosing_circle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2602.test.cpp
    title: test/yukicoder/2602.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc151f.test.cpp
    title: test_atcoder/abc151f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n\
    \  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  bool operator!=(Point p) const { return x != p.x || y != p.y; }\n  Point operator-()\
    \ const { return {-x, -y}; }\n  Point operator*(T t) const { return {x * t, y\
    \ * t}; }\n  Point operator/(T t) const { return {x / t, y / t}; }\n\n  bool operator<(Point\
    \ p) const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T\
    \ dot(Point other) { return x * other.x + y * other.y; }\n  T det(Point other)\
    \ { return x * other.y - y * other.x; }\n\n  double norm() { return sqrtl(x *\
    \ x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point rotate(double\
    \ theta) {\n    static_assert(!is_integral<T>::value);\n    double c = cos(theta),\
    \ s = sin(theta);\n    return Point{c * x - s * y, s * x + c * y};\n  }\n};\n\n\
    #ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x),\
    \ fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n\
    \  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\
    \u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename\
    \ T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n\
    \  if (x > 0) return 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename\
    \ REAL, typename T>\nREAL dist(Point<T> A, Point<T> B) {\n  A = A - B;\n  T p\
    \ = A.dot(A);\n  return sqrt(REAL(p));\n}\n\n// ax+by+c\ntemplate <typename T>\n\
    struct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n \
    \ Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x *\
    \ B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1),\
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
    \ B>> pairs) {\n    for (auto&& [a, b]: pairs) points.eb(Point<T>(a, b));\n  \
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
    #line 1 \"geo/triangle_area.hpp\"\ntemplate <typename REAL, typename T>\nREAL\
    \ triangle_area(Point<T> A, Point<T> B, Point<T> C) {\n  return abs((B - A).det(C\
    \ - A)) * 0.5;\n}\n#line 3 \"geo/outcircle.hpp\"\n\ntemplate <typename REAL, typename\
    \ T>\nCircle<REAL> outcircle(Point<T> A, Point<T> B, Point<T> C) {\n  REAL b1\
    \ = B.x - A.x, b2 = B.y - A.y;\n  REAL c1 = C.x - A.x, c2 = C.y - A.y;\n  REAL\
    \ bb = (b1 * b1 + b2 * b2) / 2;\n  REAL cc = (c1 * c1 + c2 * c2) / 2;\n\n  REAL\
    \ det = b1 * c2 - b2 * c1;\n  REAL x = (bb * c2 - b2 * cc) / det;\n  REAL y =\
    \ (b1 * cc - bb * c1) / det;\n  REAL r = sqrt(x * x + y * y);\n  x += A.x, y +=\
    \ A.y;\n  return Circle<REAL>(x, y, r);\n}\n\n// ABC \u306E\u5916\u63A5\u5186\u306B\
    \u5BFE\u3057\u3066\u5185\u5916\u3069\u3061\u3089\u306B\u3042\u308B\u304B\n// \u4E2D\
    \uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n// \u5EA7\u6A19\u306E 4 \u4E57\u304C\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\
    \u3059\u308B\ntemplate <typename T>\nint outcircle_side(Point<T> A, Point<T> B,\
    \ Point<T> C, Point<T> p) {\n  T d = (B - A).det(C - A);\n  assert(d != 0);\n\
    \  if (d < 0) swap(B, C);\n  array<Point<T>, 3> pts = {A, B, C};\n  array<array<T,\
    \ 3>, 3> mat;\n  FOR(i, 3) {\n    T dx = pts[i].x - p.x, dy = pts[i].y - p.y;\n\
    \    mat[i][0] = dx, mat[i][1] = dy, mat[i][2] = dx * dx + dy * dy;\n  }\n  T\
    \ det = 0;\n  det += mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);\n\
    \  det += mat[0][1] * (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]);\n  det\
    \ += mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);\n  if (det ==\
    \ 0) return 0;\n  return (det > 0 ? 1 : -1);\n}\n"
  code: "#include \"geo/base.hpp\"\n#include \"geo/triangle_area.hpp\"\n\ntemplate\
    \ <typename REAL, typename T>\nCircle<REAL> outcircle(Point<T> A, Point<T> B,\
    \ Point<T> C) {\n  REAL b1 = B.x - A.x, b2 = B.y - A.y;\n  REAL c1 = C.x - A.x,\
    \ c2 = C.y - A.y;\n  REAL bb = (b1 * b1 + b2 * b2) / 2;\n  REAL cc = (c1 * c1\
    \ + c2 * c2) / 2;\n\n  REAL det = b1 * c2 - b2 * c1;\n  REAL x = (bb * c2 - b2\
    \ * cc) / det;\n  REAL y = (b1 * cc - bb * c1) / det;\n  REAL r = sqrt(x * x +\
    \ y * y);\n  x += A.x, y += A.y;\n  return Circle<REAL>(x, y, r);\n}\n\n// ABC\
    \ \u306E\u5916\u63A5\u5186\u306B\u5BFE\u3057\u3066\u5185\u5916\u3069\u3061\u3089\
    \u306B\u3042\u308B\u304B\n// \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A\
    -1\n// \u5EA7\u6A19\u306E 4 \u4E57\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u3057\u306A\u3044\u3088\u3046\u306B\u3059\u308B\ntemplate <typename T>\nint outcircle_side(Point<T>\
    \ A, Point<T> B, Point<T> C, Point<T> p) {\n  T d = (B - A).det(C - A);\n  assert(d\
    \ != 0);\n  if (d < 0) swap(B, C);\n  array<Point<T>, 3> pts = {A, B, C};\n  array<array<T,\
    \ 3>, 3> mat;\n  FOR(i, 3) {\n    T dx = pts[i].x - p.x, dy = pts[i].y - p.y;\n\
    \    mat[i][0] = dx, mat[i][1] = dy, mat[i][2] = dx * dx + dy * dy;\n  }\n  T\
    \ det = 0;\n  det += mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);\n\
    \  det += mat[0][1] * (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]);\n  det\
    \ += mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);\n  if (det ==\
    \ 0) return 0;\n  return (det > 0 ? 1 : -1);\n}\n"
  dependsOn:
  - geo/base.hpp
  - geo/triangle_area.hpp
  isVerificationFile: false
  path: geo/outcircle.hpp
  requiredBy:
  - geo/minimum_enclosing_circle.hpp
  timestamp: '2024-01-13 13:20:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_7_C.test.cpp
  - test/yukicoder/2602.test.cpp
  - test_atcoder/abc151f.test.cpp
documentation_of: geo/outcircle.hpp
layout: document
redirect_from:
- /library/geo/outcircle.hpp
- /library/geo/outcircle.hpp.html
title: geo/outcircle.hpp
---