---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: geo/distance.hpp
    title: geo/distance.hpp
  - icon: ':warning:'
    path: geo/minimum_three_distance_sum.hpp
    title: geo/minimum_three_distance_sum.hpp
  - icon: ':warning:'
    path: geo/polygon.hpp
    title: geo/polygon.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_polygon.hpp
    title: random/random_polygon.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  - icon: ':x:'
    path: test/4_aoj/CGL_2_B.test.cpp
    title: test/4_aoj/CGL_2_B.test.cpp
  - icon: ':x:'
    path: test/4_aoj/CGL_2_C.test.cpp
    title: test/4_aoj/CGL_2_C.test.cpp
  - icon: ':x:'
    path: test/4_aoj/CGL_2_D.test.cpp
    title: test/4_aoj/CGL_2_D.test.cpp
  - icon: ':x:'
    path: test/4_aoj/CGL_7_B.test.cpp
    title: test/4_aoj/CGL_7_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://codeforces.com/contest/2/problem/C
    - https://codeforces.com/contest/607/problem/E
  bundledCode: "#line 2 \"geo/cross_point.hpp\"\n\n#line 2 \"geo/base.hpp\"\ntemplate\
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
    \ U>\n  U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\n  template\
    \ <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n \
    \ // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\
    \u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
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
    \ <= r * r;\n  }\n};\n#line 4 \"geo/cross_point.hpp\"\n\n// \u5E73\u884C\u3067\
    \u306A\u3044\u3053\u3068\u3092\u4EEE\u5B9A\ntemplate <typename REAL, typename\
    \ T>\nPoint<REAL> cross_point(const Line<T> L1, const Line<T> L2) {\n  T det =\
    \ L1.a * L2.b - L1.b * L2.a;\n  assert(det != 0);\n  REAL x = -REAL(L1.c) * L2.b\
    \ + REAL(L1.b) * L2.c;\n  REAL y = -REAL(L1.a) * L2.c + REAL(L1.c) * L2.a;\n \
    \ return Point<REAL>(x / det, y / det);\n}\n\n// \u6D6E\u52D5\u5C0F\u6570\u70B9\
    \u6570\u306F\u30A8\u30E9\u30FC\n// 0: \u4EA4\u70B9\u306A\u3057\n// 1: \u4E00\u610F\
    \u306A\u4EA4\u70B9\n// 2\uFF1A2 \u3064\u4EE5\u4E0A\u306E\u4EA4\u70B9\uFF08\u6574\
    \u6570\u578B\u3092\u5229\u7528\u3057\u3066\u53B3\u5BC6\u306B\u3084\u308B\uFF09\
    \ntemplate <typename T>\nint count_cross(Segment<T> S1, Segment<T> S2, bool include_ends)\
    \ {\n  static_assert(!std::is_floating_point<T>::value);\n  Line<T> L1 = S1.to_Line();\n\
    \  Line<T> L2 = S2.to_Line();\n  if (L1.is_parallel(L2)) {\n    if (L1.eval(S2.A)\
    \ != 0) return 0;\n    // 4 \u70B9\u3068\u3082\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\
    \u3042\u308B\n    T a1 = S1.A.x, b1 = S1.B.x;\n    T a2 = S2.A.x, b2 = S2.B.x;\n\
    \    if (a1 == b1) {\n      a1 = S1.A.y, b1 = S1.B.y;\n      a2 = S2.A.y, b2 =\
    \ S2.B.y;\n    }\n    if (a1 > b1) swap(a1, b1);\n    if (a2 > b2) swap(a2, b2);\n\
    \    T a = max(a1, a2);\n    T b = min(b1, b2);\n    if (a < b) return 2;\n  \
    \  if (a > b) return 0;\n    return (include_ends ? 1 : 0);\n  }\n  // \u5E73\u884C\
    \u3067\u306A\u3044\u5834\u5408\n  T a1 = L2.eval(S1.A), b1 = L2.eval(S1.B);\n\
    \  T a2 = L1.eval(S2.A), b2 = L1.eval(S2.B);\n  if (a1 > b1) swap(a1, b1);\n \
    \ if (a2 > b2) swap(a2, b2);\n  bool ok1 = 0, ok2 = 0;\n\n  if (include_ends)\
    \ {\n    ok1 = (a1 <= T(0)) && (T(0) <= b1);\n    ok2 = (a2 <= T(0)) && (T(0)\
    \ <= b2);\n  } else {\n    ok1 = (a1 < T(0)) && (T(0) < b1);\n    ok2 = (a2 <\
    \ T(0)) && (T(0) < b2);\n  }\n  return (ok1 && ok2 ? 1 : 0);\n}\n\n// 4 \u6B21\
    \u5F0F\u307E\u3067\u767B\u5834\u3057\u3066\u3044\u308B\u3001\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u6CE8\u610F\uFF01\n// https://codeforces.com/contest/607/problem/E\n\
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
    }\n"
  code: "#pragma once\n\n#include \"geo/base.hpp\"\n\n// \u5E73\u884C\u3067\u306A\u3044\
    \u3053\u3068\u3092\u4EEE\u5B9A\ntemplate <typename REAL, typename T>\nPoint<REAL>\
    \ cross_point(const Line<T> L1, const Line<T> L2) {\n  T det = L1.a * L2.b - L1.b\
    \ * L2.a;\n  assert(det != 0);\n  REAL x = -REAL(L1.c) * L2.b + REAL(L1.b) * L2.c;\n\
    \  REAL y = -REAL(L1.a) * L2.c + REAL(L1.c) * L2.a;\n  return Point<REAL>(x /\
    \ det, y / det);\n}\n\n// \u6D6E\u52D5\u5C0F\u6570\u70B9\u6570\u306F\u30A8\u30E9\
    \u30FC\n// 0: \u4EA4\u70B9\u306A\u3057\n// 1: \u4E00\u610F\u306A\u4EA4\u70B9\n\
    // 2\uFF1A2 \u3064\u4EE5\u4E0A\u306E\u4EA4\u70B9\uFF08\u6574\u6570\u578B\u3092\
    \u5229\u7528\u3057\u3066\u53B3\u5BC6\u306B\u3084\u308B\uFF09\ntemplate <typename\
    \ T>\nint count_cross(Segment<T> S1, Segment<T> S2, bool include_ends) {\n  static_assert(!std::is_floating_point<T>::value);\n\
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
    }\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/cross_point.hpp
  requiredBy:
  - geo/distance.hpp
  - geo/minimum_three_distance_sum.hpp
  - geo/polygon.hpp
  - random/random_polygon.hpp
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/polygon_triangulation.test.cpp
  - test/4_aoj/CGL_7_B.test.cpp
  - test/4_aoj/CGL_2_B.test.cpp
  - test/4_aoj/CGL_2_C.test.cpp
  - test/4_aoj/CGL_2_D.test.cpp
documentation_of: geo/cross_point.hpp
layout: document
redirect_from:
- /library/geo/cross_point.hpp
- /library/geo/cross_point.hpp.html
title: geo/cross_point.hpp
---
