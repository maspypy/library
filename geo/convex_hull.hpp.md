---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/fenchel.hpp
    title: convex/fenchel.hpp
  - icon: ':warning:'
    path: convex/line_min_function.hpp
    title: convex/line_min_function.hpp
  - icon: ':heavy_check_mark:'
    path: geo/convex_polygon.hpp
    title: geo/convex_polygon.hpp
  - icon: ':heavy_check_mark:'
    path: geo/furthest_pair.hpp
    title: geo/furthest_pair.hpp
  - icon: ':warning:'
    path: geo/minkowski_sum.hpp
    title: geo/minkowski_sum.hpp
  - icon: ':heavy_check_mark:'
    path: random/random_polygon.hpp
    title: random/random_polygon.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/convex_polygon_side.test.cpp
    title: test/1_mytest/convex_polygon_side.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/convex_polygon_visible_range.test.cpp
    title: test/1_mytest/convex_polygon_visible_range.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/max_dot.test.cpp
    title: test/1_mytest/max_dot.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/furthest_pair.test.cpp
    title: test/2_library_checker/geometry/furthest_pair.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/geometry/static_convex_hull.test.cpp
    title: test/2_library_checker/geometry/static_convex_hull.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/arc130f.test.cpp
    title: test/5_atcoder/arc130f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/convex_hull.hpp\"\n\n#line 2 \"geo/base.hpp\"\ntemplate\
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
    \ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 4 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\u540C\u4E00\u5EA7\u6A19\
    \u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\n// full \u306A\u3089 I[0]\
    \ \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate <typename T, bool allow_180\
    \ = false>\nvector<int> ConvexHull(vector<Point<T>>& XY, string mode = \"full\"\
    , bool sorted = false) {\n  assert(mode == \"full\" || mode == \"lower\" || mode\
    \ == \"upper\");\n  ll N = XY.size();\n  if (N == 1) return {0};\n  if (N == 2)\
    \ {\n    if (XY[0] < XY[1]) return {0, 1};\n    if (XY[1] < XY[0]) return {1,\
    \ 0};\n    return {0};\n  }\n  vc<int> I(N);\n  if (sorted) {\n    FOR(i, N) I[i]\
    \ = i;\n  } else {\n    I = argsort(XY);\n  }\n  if constexpr (allow_180) { FOR(i,\
    \ N - 1) assert(XY[i] != XY[i + 1]); }\n\n  auto check = [&](ll i, ll j, ll k)\
    \ -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k] - XY[i]);\n    if constexpr\
    \ (allow_180) return det >= 0;\n    return det > T(0);\n  };\n\n  auto calc =\
    \ [&]() {\n    vector<int> P;\n    for (auto&& k: I) {\n      while (P.size()\
    \ > 1) {\n        auto i = P[P.size() - 2];\n        auto j = P[P.size() - 1];\n\
    \        if (check(i, j, k)) break;\n        P.pop_back();\n      }\n      P.eb(k);\n\
    \    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode == \"full\" || mode ==\
    \ \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n\
    \  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty()) P.pop_back();\n\
    \    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n\
    \  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >= 2 && XY[P[0]]\
    \ == XY[P.back()]) P.pop_back();\n  return P;\n}\n"
  code: "#pragma once\n\n#include \"geo/base.hpp\"\n\n// allow_180=true \u3067\u540C\
    \u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\n// full\
    \ \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate <typename\
    \ T, bool allow_180 = false>\nvector<int> ConvexHull(vector<Point<T>>& XY, string\
    \ mode = \"full\", bool sorted = false) {\n  assert(mode == \"full\" || mode ==\
    \ \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N == 1) return\
    \ {0};\n  if (N == 2) {\n    if (XY[0] < XY[1]) return {0, 1};\n    if (XY[1]\
    \ < XY[0]) return {1, 0};\n    return {0};\n  }\n  vc<int> I(N);\n  if (sorted)\
    \ {\n    FOR(i, N) I[i] = i;\n  } else {\n    I = argsort(XY);\n  }\n  if constexpr\
    \ (allow_180) { FOR(i, N - 1) assert(XY[i] != XY[i + 1]); }\n\n  auto check =\
    \ [&](ll i, ll j, ll k) -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k] - XY[i]);\n\
    \    if constexpr (allow_180) return det >= 0;\n    return det > T(0);\n  };\n\
    \n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k: I) {\n      while\
    \ (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto j = P[P.size()\
    \ - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n      }\n\
    \      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode == \"\
    full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >=\
    \ 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n  return P;\n}"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/convex_hull.hpp
  requiredBy:
  - random/random_polygon.hpp
  - convex/fenchel.hpp
  - convex/line_min_function.hpp
  - geo/minkowski_sum.hpp
  - geo/convex_polygon.hpp
  - geo/furthest_pair.hpp
  timestamp: '2024-10-20 23:29:28+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/5_atcoder/arc130f.test.cpp
  - test/1_mytest/polygon_triangulation.test.cpp
  - test/1_mytest/max_dot.test.cpp
  - test/1_mytest/convex_polygon_visible_range.test.cpp
  - test/1_mytest/convex_polygon_side.test.cpp
  - test/2_library_checker/geometry/furthest_pair.test.cpp
  - test/2_library_checker/geometry/static_convex_hull.test.cpp
documentation_of: geo/convex_hull.hpp
layout: document
redirect_from:
- /library/geo/convex_hull.hpp
- /library/geo/convex_hull.hpp.html
title: geo/convex_hull.hpp
---
