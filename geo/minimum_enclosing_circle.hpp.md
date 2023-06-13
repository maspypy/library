---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/outcircle.hpp
    title: geo/outcircle.hpp
  - icon: ':heavy_check_mark:'
    path: geo/triangle_area.hpp
    title: geo/triangle_area.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc151f.test.cpp
    title: test_atcoder/abc151f.test.cpp
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
    \      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n#line 2 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\
    \n\ntemplate <typename T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) swap(A[i],\
    \ A[RNG(0, i + 1)]);\n}\n#line 1 \"geo/triangle_area.hpp\"\ntemplate <typename\
    \ REAL, typename T>\nREAL triangle_area(Point<T> A, Point<T> B, Point<T> C) {\n\
    \  return abs((B - A).det(C - A)) * 0.5;\n}\n#line 3 \"geo/outcircle.hpp\"\n\n\
    template <typename REAL, typename T>\nCircle<REAL> outcircle(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  REAL b1 = B.x - A.x, b2 = B.y - A.y;\n  REAL c1 = C.x -\
    \ A.x, c2 = C.y - A.y;\n  REAL bb = (b1 * b1 + b2 * b2) / 2;\n  REAL cc = (c1\
    \ * c1 + c2 * c2) / 2;\n\n  REAL det = b1 * c2 - b2 * c1;\n  REAL x = (bb * c2\
    \ - b2 * cc) / det;\n  REAL y = (b1 * cc - bb * c1) / det;\n  REAL r = sqrt(x\
    \ * x + y * y);\n  x += A.x, y += A.y;\n  return Circle<REAL>(x, y, r);\n}\n#line\
    \ 4 \"geo/minimum_enclosing_circle.hpp\"\n\n// randomize \u3092\u5229\u7528\u3057\
    \u305F O(N) \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n// Computational Geometry, Section\
    \ 4.7\ntemplate <typename REAL, typename T>\nCircle<REAL> minimum_enclosing_circle(vc<Point<T>>\
    \ points) {\n  using C = Circle<REAL>;\n  shuffle(points);\n  const int n = len(points);\n\
    \  assert(n >= 1);\n  if (n == 1) { return C(points[0].x, points[0].y, 0); }\n\
    \  auto make2 = [&](int i, int j) -> C {\n    REAL x = (points[i].x + points[j].x)\
    \ * 0.5;\n    REAL y = (points[i].y + points[j].y) * 0.5;\n    REAL r = dist<REAL,\
    \ T>(points[i], points[j]) * 0.5;\n    return C(x, y, r);\n  };\n  auto make3\
    \ = [&](int i, int j, int k) -> C {\n    return outcircle<REAL, T>(points[i],\
    \ points[j], points[k]);\n  };\n\n  C c = make2(0, 1);\n  FOR(i, 2, n) {\n   \
    \ if (c.contain(points[i])) continue;\n    // i \u3092\u542B\u3080\u3068\u3044\
    \u3046\u5236\u7D04\u3067\u4F5C\u308A\u76F4\u3059\u3002\n    // \u3053\u308C\u3092\
    \u3084\u308B\u306E\u306F\u78BA\u7387 O(1/i) \u3067\u3001O(i) \u6642\u9593\u304B\
    \u3051\u308B\u3002\n    c = make2(0, i);\n    FOR(j, 1, i) {\n      if (c.contain(points[j]))\
    \ continue;\n      c = make2(i, j);\n      FOR(k, j) {\n        if (c.contain(points[k]))\
    \ continue;\n        c = make3(i, j, k);\n      }\n    }\n  }\n  return c;\n}\n"
  code: "#include \"geo/base.hpp\"\n#include \"random/shuffle.hpp\"\n#include \"geo/outcircle.hpp\"\
    \n\n// randomize \u3092\u5229\u7528\u3057\u305F O(N) \u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E0\n// Computational Geometry, Section 4.7\ntemplate <typename REAL, typename\
    \ T>\nCircle<REAL> minimum_enclosing_circle(vc<Point<T>> points) {\n  using C\
    \ = Circle<REAL>;\n  shuffle(points);\n  const int n = len(points);\n  assert(n\
    \ >= 1);\n  if (n == 1) { return C(points[0].x, points[0].y, 0); }\n  auto make2\
    \ = [&](int i, int j) -> C {\n    REAL x = (points[i].x + points[j].x) * 0.5;\n\
    \    REAL y = (points[i].y + points[j].y) * 0.5;\n    REAL r = dist<REAL, T>(points[i],\
    \ points[j]) * 0.5;\n    return C(x, y, r);\n  };\n  auto make3 = [&](int i, int\
    \ j, int k) -> C {\n    return outcircle<REAL, T>(points[i], points[j], points[k]);\n\
    \  };\n\n  C c = make2(0, 1);\n  FOR(i, 2, n) {\n    if (c.contain(points[i]))\
    \ continue;\n    // i \u3092\u542B\u3080\u3068\u3044\u3046\u5236\u7D04\u3067\u4F5C\
    \u308A\u76F4\u3059\u3002\n    // \u3053\u308C\u3092\u3084\u308B\u306E\u306F\u78BA\
    \u7387 O(1/i) \u3067\u3001O(i) \u6642\u9593\u304B\u3051\u308B\u3002\n    c = make2(0,\
    \ i);\n    FOR(j, 1, i) {\n      if (c.contain(points[j])) continue;\n      c\
    \ = make2(i, j);\n      FOR(k, j) {\n        if (c.contain(points[k])) continue;\n\
    \        c = make3(i, j, k);\n      }\n    }\n  }\n  return c;\n}"
  dependsOn:
  - geo/base.hpp
  - random/shuffle.hpp
  - random/base.hpp
  - geo/outcircle.hpp
  - geo/triangle_area.hpp
  isVerificationFile: false
  path: geo/minimum_enclosing_circle.hpp
  requiredBy: []
  timestamp: '2023-04-08 00:43:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc151f.test.cpp
documentation_of: geo/minimum_enclosing_circle.hpp
layout: document
redirect_from:
- /library/geo/minimum_enclosing_circle.hpp
- /library/geo/minimum_enclosing_circle.hpp.html
title: geo/minimum_enclosing_circle.hpp
---
