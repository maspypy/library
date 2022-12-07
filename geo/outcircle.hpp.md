---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/triangle_area.hpp
    title: geo/triangle_area.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() = default;\n\n  template <typename A, typename B>\n  Point(A\
    \ x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n\n  bool operator<(Point p) const\
    \ {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n\n  void read()\
    \ { fastio::read(x), fastio::read(y); }\n  void write() { fastio::printer.write(pair<T,\
    \ T>({x, y})); }\n  T dot(Point other) { return x * other.x + y * other.y; }\n\
    \  T det(Point other) { return x * other.y - y * other.x; }\n};\n\ntemplate <typename\
    \ REAL, typename T>\nREAL dist(Point<T> A, Point<T> B) {\n  A -= B;\n  T p = A.dot(A);\n\
    \  return sqrt(REAL(p));\n}\n\ntemplate <typename T>\nstruct Line {\n  T a, b,\
    \ c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T>\
    \ B) {\n    a = A.y - B.y;\n    b = B.x - A.x;\n    c = A.x * B.y - A.y * B.x;\n\
    \  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n    return a * P.x +\
    \ b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return\
    \ a * x + b * y + c;\n  }\n\n  bool is_parallel(Line other) { return a * other.b\
    \ - b * other.a == 0; }\n\n  bool is_orthogonal(Line other) { return a * other.a\
    \ + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T>\
    \ A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1,\
    \ T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n\
    \  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate <typename T>\nstruct\
    \ Circle {\n  Point<T> O;\n  T r;\n  Circle(Point<T> O, T r) : O(O), r(r) {}\n\
    \  Circle(T x, T y, T r) : O(Point<T>(x, y)), r(r) {}\n};\n\ntemplate <typename\
    \ T>\nstruct Polygon {\n  vc<Point<T>> points;\n  T a;\n\n  template <typename\
    \ A, typename B>\n  Polygon(vc<pair<A, B>> pairs) {\n    for (auto&& [a, b]: pairs)\
    \ points.eb(Point<T>(a, b));\n    build();\n  }\n  Polygon(vc<Point<T>> points)\
    \ : points(points) { build(); }\n\n  int size() { return len(points); }\n\n  template\
    \ <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
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
    \ A.y;\n  return Circle<REAL>(x, y, r);\n}\n"
  code: "#include \"geo/base.hpp\"\n#include \"geo/triangle_area.hpp\"\n\ntemplate\
    \ <typename REAL, typename T>\nCircle<REAL> outcircle(Point<T> A, Point<T> B,\
    \ Point<T> C) {\n  REAL b1 = B.x - A.x, b2 = B.y - A.y;\n  REAL c1 = C.x - A.x,\
    \ c2 = C.y - A.y;\n  REAL bb = (b1 * b1 + b2 * b2) / 2;\n  REAL cc = (c1 * c1\
    \ + c2 * c2) / 2;\n\n  REAL det = b1 * c2 - b2 * c1;\n  REAL x = (bb * c2 - b2\
    \ * cc) / det;\n  REAL y = (b1 * cc - bb * c1) / det;\n  REAL r = sqrt(x * x +\
    \ y * y);\n  x += A.x, y += A.y;\n  return Circle<REAL>(x, y, r);\n}"
  dependsOn:
  - geo/base.hpp
  - geo/triangle_area.hpp
  isVerificationFile: false
  path: geo/outcircle.hpp
  requiredBy: []
  timestamp: '2022-12-07 07:51:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_7_C.test.cpp
documentation_of: geo/outcircle.hpp
layout: document
redirect_from:
- /library/geo/outcircle.hpp
- /library/geo/outcircle.hpp.html
title: geo/outcircle.hpp
---
