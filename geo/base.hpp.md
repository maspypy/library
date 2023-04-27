---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':heavy_check_mark:'
    path: geo/closest_pair.hpp
    title: geo/closest_pair.hpp
  - icon: ':question:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':heavy_check_mark:'
    path: geo/cross_point.hpp
    title: geo/cross_point.hpp
  - icon: ':heavy_check_mark:'
    path: geo/distance.hpp
    title: geo/distance.hpp
  - icon: ':heavy_check_mark:'
    path: geo/dynamicupperhull.hpp
    title: geo/dynamicupperhull.hpp
  - icon: ':heavy_check_mark:'
    path: geo/incircle.hpp
    title: geo/incircle.hpp
  - icon: ':heavy_check_mark:'
    path: geo/incremental_convexhull.hpp
    title: geo/incremental_convexhull.hpp
  - icon: ':heavy_check_mark:'
    path: geo/minimum_enclosing_circle.hpp
    title: geo/minimum_enclosing_circle.hpp
  - icon: ':heavy_check_mark:'
    path: geo/outcircle.hpp
    title: geo/outcircle.hpp
  - icon: ':heavy_check_mark:'
    path: geo/projection.hpp
    title: geo/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geo/reflection.hpp
    title: geo/reflection.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_A.test.cpp
    title: test/aoj/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_B.test.cpp
    title: test/aoj/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C.test.cpp
    title: test/aoj/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D.test.cpp
    title: test/aoj/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/convex_layers.test.cpp
    title: test/library_checker/geometry/convex_layers.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/sort_points_by_argument.test.cpp
    title: test/library_checker/geometry/sort_points_by_argument.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/sort_points_by_argument_pair.test.cpp
    title: test/library_checker/geometry/sort_points_by_argument_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_points_in_triangles.test.cpp
    title: test/mytest/count_points_in_triangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/incremental_ch.test.cpp
    title: test/mytest/incremental_ch.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/qoj5443.test.cpp
    title: test/mytest/qoj5443.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc151f.test.cpp
    title: test_atcoder/abc151f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc202_f.test.cpp
    title: test_atcoder/abc202_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc266c.test.cpp
    title: test_atcoder/abc266c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() = default;\n\n  template <typename A, typename B>\n  Point(A\
    \ x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n\n  bool operator<(Point p) const\
    \ {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(Point\
    \ other) { return x * other.x + y * other.y; }\n  T det(Point other) { return\
    \ x * other.y - y * other.x; }\n\n  void read() { fastio::read(x), fastio::read(y);\
    \ }\n  void write() { fastio::printer.write(pair<T, T>({x, y})); }\n};\n\n// A\
    \ -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\
    \u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n \
    \ T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if (x < 0) return -1;\n\
    \  return 0;\n}\n\ntemplate <typename REAL, typename T>\nREAL dist(Point<T> A,\
    \ Point<T> B) {\n  A = A - B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n}\n\
    \ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c)\
    \ : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y,\
    \ b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2)\
    \ : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n \
    \ U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\n  template <typename\
    \ U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n \
    \   if (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A\
    \ - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate\
    \ <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n\n\
    template <typename T>\nstruct Polygon {\n  vc<Point<T>> points;\n  T a;\n\n  template\
    \ <typename A, typename B>\n  Polygon(vc<pair<A, B>> pairs) {\n    for (auto&&\
    \ [a, b]: pairs) points.eb(Point<T>(a, b));\n    build();\n  }\n  Polygon(vc<Point<T>>\
    \ points) : points(points) { build(); }\n\n  int size() { return len(points);\
    \ }\n\n  template <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\
    \n  template <enable_if_t<is_integral<T>::value, int> = 0>\n  T area_2() {\n \
    \   return a;\n  }\n\n  bool is_convex() {\n    FOR(j, len(points)) {\n      int\
    \ i = (j == 0 ? len(points) - 1 : j - 1);\n      int k = (j == len(points) - 1\
    \ ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k] - points[j])\
    \ < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n  void build()\
    \ {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1 == len(points)\
    \ ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n    if (a < 0) {\n\
    \      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n"
  code: "#pragma once\ntemplate <typename T>\nstruct Point {\n  T x, y;\n\n  Point()\
    \ = default;\n\n  template <typename A, typename B>\n  Point(A x, B y) : x(x),\
    \ y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A, B> p) : x(p.fi),\
    \ y(p.se) {}\n\n  Point operator+(Point p) const { return {x + p.x, y + p.y};\
    \ }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n  bool operator==(Point\
    \ p) const { return x == p.x && y == p.y; }\n  Point operator-() const { return\
    \ {-x, -y}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x\
    \ < p.x;\n    return y < p.y;\n  }\n  T dot(Point other) { return x * other.x\
    \ + y * other.y; }\n  T det(Point other) { return x * other.y - y * other.x; }\n\
    \n  void read() { fastio::read(x), fastio::read(y); }\n  void write() { fastio::printer.write(pair<T,\
    \ T>({x, y})); }\n};\n\n// A -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\
    \u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\
    \u308B\u306A\u3089\u3070 -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if\
    \ (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename REAL, typename T>\n\
    REAL dist(Point<T> A, Point<T> B) {\n  A = A - B;\n  T p = A.dot(A);\n  return\
    \ sqrt(REAL(p));\n}\n\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n\
    \  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\n\
    \    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1,\
    \ T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template\
    \ <typename U>\n  U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\
    \n  template <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n\
    \  }\n\n  bool is_parallel(Line other) { return a * other.b - b * other.a == 0;\
    \ }\n\n  bool is_orthogonal(Line other) { return a * other.a + b * other.b ==\
    \ 0; }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T>\
    \ A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n \
    \   if (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A\
    \ - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate\
    \ <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n\n\
    template <typename T>\nstruct Polygon {\n  vc<Point<T>> points;\n  T a;\n\n  template\
    \ <typename A, typename B>\n  Polygon(vc<pair<A, B>> pairs) {\n    for (auto&&\
    \ [a, b]: pairs) points.eb(Point<T>(a, b));\n    build();\n  }\n  Polygon(vc<Point<T>>\
    \ points) : points(points) { build(); }\n\n  int size() { return len(points);\
    \ }\n\n  template <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\
    \n  template <enable_if_t<is_integral<T>::value, int> = 0>\n  T area_2() {\n \
    \   return a;\n  }\n\n  bool is_convex() {\n    FOR(j, len(points)) {\n      int\
    \ i = (j == 0 ? len(points) - 1 : j - 1);\n      int k = (j == len(points) - 1\
    \ ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k] - points[j])\
    \ < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n  void build()\
    \ {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1 == len(points)\
    \ ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n    if (a < 0) {\n\
    \      a = -a;\n      reverse(all(points));\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: geo/base.hpp
  requiredBy:
  - geo/incircle.hpp
  - geo/dynamicupperhull.hpp
  - geo/projection.hpp
  - geo/angle_sort.hpp
  - geo/outcircle.hpp
  - geo/minimum_enclosing_circle.hpp
  - geo/distance.hpp
  - geo/count_points_in_triangles.hpp
  - geo/incremental_convexhull.hpp
  - geo/cross_point.hpp
  - geo/reflection.hpp
  - geo/closest_pair.hpp
  timestamp: '2023-04-08 00:43:46+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc202_f.test.cpp
  - test_atcoder/abc266c.test.cpp
  - test_atcoder/abc151f.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/library_checker/geometry/sort_points_by_argument_pair.test.cpp
  - test/library_checker/geometry/sort_points_by_argument.test.cpp
  - test/library_checker/geometry/convex_layers.test.cpp
  - test/mytest/qoj5443.test.cpp
  - test/mytest/count_points_in_triangles.test.cpp
  - test/mytest/incremental_ch.test.cpp
documentation_of: geo/base.hpp
layout: document
redirect_from:
- /library/geo/base.hpp
- /library/geo/base.hpp.html
title: geo/base.hpp
---
