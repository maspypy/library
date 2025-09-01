---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':warning:'
    path: geo/max_norm_sum.hpp
    title: geo/max_norm_sum.hpp
  - icon: ':warning:'
    path: geo/minkowski_sum.hpp
    title: geo/minkowski_sum.hpp
  - icon: ':heavy_check_mark:'
    path: geo/polygon_triangulation.hpp
    title: geo/polygon_triangulation.hpp
  - icon: ':warning:'
    path: geo/rotating_swaps.hpp
    title: geo/rotating_swaps.hpp
  - icon: ':question:'
    path: graph/planar_graph.hpp
    title: graph/planar_graph.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_polygon.hpp
    title: random/random_polygon.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_points_in_triangles.test.cpp
    title: test/1_mytest/count_points_in_triangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/qoj5443.test.cpp
    title: test/1_mytest/qoj5443.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/count_points_in_triangles.test.cpp
    title: test/2_library_checker/geometry/count_points_in_triangles.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/sort_points_by_argument.test.cpp
    title: test/2_library_checker/geometry/sort_points_by_argument.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/sort_points_by_argument_pair.test.cpp
    title: test/2_library_checker/geometry/sort_points_by_argument_pair.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1777.test.cpp
    title: test/3_yukicoder/1777.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/angle_sort.hpp\"\n\r\n#line 2 \"geo/base.hpp\"\ntemplate\
    \ <typename T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template\
    \ <typename A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename\
    \ A, typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+=(const\
    \ Point p) {\n    x += p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const\
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
    \ <= r * r;\n  }\n};\n#line 4 \"geo/angle_sort.hpp\"\n\r\n// lower: -1, origin:\
    \ 0, upper: 1, (-pi,pi]\r\ntemplate <typename T> int lower_or_upper(const Point<T>\
    \ &p) {\r\n  if (p.y != 0)\r\n    return (p.y > 0 ? 1 : -1);\r\n  if (p.x > 0)\r\
    \n    return -1;\r\n  if (p.x < 0)\r\n    return 1;\r\n  return 0;\r\n}\r\n\r\n\
    // L<R:-1, L==R:0, L>R:1, (-pi,pi]\r\ntemplate <typename T> int angle_comp_3(const\
    \ Point<T> &L, const Point<T> &R) {\r\n  int a = lower_or_upper(L), b = lower_or_upper(R);\r\
    \n  if (a != b)\r\n    return (a < b ? -1 : +1);\r\n  T det = L.det(R);\r\n  if\
    \ (det > 0)\r\n    return -1;\r\n  if (det < 0)\r\n    return 1;\r\n  return 0;\r\
    \n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort,\
    \ (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<Point<T>> &P)\
    \ {\r\n  vc<int> I(len(P));\r\n  FOR(i, len(P)) I[i] = i;\r\n  sort(all(I), [&](auto\
    \ &L, auto &R) -> bool {\r\n    return angle_comp_3(P[L], P[R]) == -1;\r\n  });\r\
    \n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B\
    \ argsort, (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<pair<T,\
    \ T>> &P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_sort<T>(tmp);\r\n}\r\n"
  code: "#pragma once\r\n\r\n#include \"geo/base.hpp\"\r\n\r\n// lower: -1, origin:\
    \ 0, upper: 1, (-pi,pi]\r\ntemplate <typename T> int lower_or_upper(const Point<T>\
    \ &p) {\r\n  if (p.y != 0)\r\n    return (p.y > 0 ? 1 : -1);\r\n  if (p.x > 0)\r\
    \n    return -1;\r\n  if (p.x < 0)\r\n    return 1;\r\n  return 0;\r\n}\r\n\r\n\
    // L<R:-1, L==R:0, L>R:1, (-pi,pi]\r\ntemplate <typename T> int angle_comp_3(const\
    \ Point<T> &L, const Point<T> &R) {\r\n  int a = lower_or_upper(L), b = lower_or_upper(R);\r\
    \n  if (a != b)\r\n    return (a < b ? -1 : +1);\r\n  T det = L.det(R);\r\n  if\
    \ (det > 0)\r\n    return -1;\r\n  if (det < 0)\r\n    return 1;\r\n  return 0;\r\
    \n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort,\
    \ (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<Point<T>> &P)\
    \ {\r\n  vc<int> I(len(P));\r\n  FOR(i, len(P)) I[i] = i;\r\n  sort(all(I), [&](auto\
    \ &L, auto &R) -> bool {\r\n    return angle_comp_3(P[L], P[R]) == -1;\r\n  });\r\
    \n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B\
    \ argsort, (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<pair<T,\
    \ T>> &P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_sort<T>(tmp);\r\n}\r\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/angle_sort.hpp
  requiredBy:
  - random/random_polygon.hpp
  - geo/count_points_in_triangles.hpp
  - geo/polygon_triangulation.hpp
  - geo/max_norm_sum.hpp
  - geo/rotating_swaps.hpp
  - geo/minkowski_sum.hpp
  - graph/planar_graph.hpp
  timestamp: '2025-05-18 17:51:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1777.test.cpp
  - test/2_library_checker/geometry/count_points_in_triangles.test.cpp
  - test/2_library_checker/geometry/sort_points_by_argument.test.cpp
  - test/2_library_checker/geometry/sort_points_by_argument_pair.test.cpp
  - test/1_mytest/count_points_in_triangles.test.cpp
  - test/1_mytest/qoj5443.test.cpp
  - test/1_mytest/polygon_triangulation.test.cpp
documentation_of: geo/angle_sort.hpp
layout: document
redirect_from:
- /library/geo/angle_sort.hpp
- /library/geo/angle_sort.hpp.html
title: geo/angle_sort.hpp
---
