---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: convex/fenchel.hpp
    title: convex/fenchel.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/arc130f.test.cpp
    title: test_atcoder/arc130f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() = default;\n\n  template <typename A, typename B>\n  Point(A\
    \ x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  bool operator!=(Point p) const { return x != p.x || y != p.y || z == p.z; }\n\
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
    \      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n#line 2 \"geo/convex_hull.hpp\"\
    \n\ntemplate <typename T>\nvector<int> ConvexHull(vector<pair<T, T>>& XY, string\
    \ mode = \"full\",\n                       bool inclusive = false, bool sorted\
    \ = false) {\n  assert(mode == \"full\" || mode == \"lower\" || mode == \"upper\"\
    );\n  ll N = XY.size();\n  if (N == 1) return {0};\n  if (N == 2) return {0, 1};\n\
    \  vc<int> I = argsort(XY);\n\n  auto check = [&](ll i, ll j, ll k) -> bool {\n\
    \    auto xi = XY[i].fi, yi = XY[i].se;\n    auto xj = XY[j].fi, yj = XY[j].se;\n\
    \    auto xk = XY[k].fi, yk = XY[k].se;\n    auto dx1 = xj - xi, dy1 = yj - yi;\n\
    \    auto dx2 = xk - xj, dy2 = yk - yj;\n    T det = dx1 * dy2 - dy1 * dx2;\n\
    \    return (inclusive ? det >= 0 : det > 0);\n  };\n\n  auto calc = [&]() {\n\
    \    vector<int> P;\n    for (auto&& k: I) {\n      while (P.size() > 1) {\n \
    \       auto i = P[P.size() - 2];\n        auto j = P[P.size() - 1];\n       \
    \ if (check(i, j, k)) break;\n        P.pop_back();\n      }\n      P.eb(k);\n\
    \    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode == \"full\" || mode ==\
    \ \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n\
    \  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty()) P.pop_back();\n\
    \    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n\
    \  }\n  if (mode == \"upper\") reverse(all(P));\n  if (len(P) >= 2 && P[0] ==\
    \ P.back()) P.pop_back();\n  return P;\n}\n\ntemplate <typename T>\nvector<int>\
    \ ConvexHull(vector<Point<T>>& XY, string mode = \"full\",\n                 \
    \      bool inclusive = false, bool sorted = false) {\n  assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N ==\
    \ 1) return {0};\n  if (N == 2) return {0, 1};\n  vc<int> I = argsort(XY);\n\n\
    \  auto check = [&](ll i, ll j, ll k) -> bool {\n    auto xi = XY[i].x, yi = XY[i].y;\n\
    \    auto xj = XY[j].x, yj = XY[j].y;\n    auto xk = XY[k].x, yk = XY[k].y;\n\
    \    auto dx1 = xj - xi, dy1 = yj - yi;\n    auto dx2 = xk - xj, dy2 = yk - yj;\n\
    \    T det = dx1 * dy2 - dy1 * dx2;\n    return (inclusive ? det >= 0 : det >\
    \ 0);\n  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k: I)\
    \ {\n      while (P.size() > 1) {\n        auto i = P[P.size() - 2];\n       \
    \ auto j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n\
    \      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode\
    \ == \"full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  if (len(P) >= 2\
    \ && P[0] == P.back()) P.pop_back();\n  return P;\n}\n"
  code: "#include \"geo/base.hpp\"\n\ntemplate <typename T>\nvector<int> ConvexHull(vector<pair<T,\
    \ T>>& XY, string mode = \"full\",\n                       bool inclusive = false,\
    \ bool sorted = false) {\n  assert(mode == \"full\" || mode == \"lower\" || mode\
    \ == \"upper\");\n  ll N = XY.size();\n  if (N == 1) return {0};\n  if (N == 2)\
    \ return {0, 1};\n  vc<int> I = argsort(XY);\n\n  auto check = [&](ll i, ll j,\
    \ ll k) -> bool {\n    auto xi = XY[i].fi, yi = XY[i].se;\n    auto xj = XY[j].fi,\
    \ yj = XY[j].se;\n    auto xk = XY[k].fi, yk = XY[k].se;\n    auto dx1 = xj -\
    \ xi, dy1 = yj - yi;\n    auto dx2 = xk - xj, dy2 = yk - yj;\n    T det = dx1\
    \ * dy2 - dy1 * dx2;\n    return (inclusive ? det >= 0 : det > 0);\n  };\n\n \
    \ auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k: I) {\n      while\
    \ (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto j = P[P.size()\
    \ - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n      }\n\
    \      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode == \"\
    full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  if (len(P) >= 2\
    \ && P[0] == P.back()) P.pop_back();\n  return P;\n}\n\ntemplate <typename T>\n\
    vector<int> ConvexHull(vector<Point<T>>& XY, string mode = \"full\",\n       \
    \                bool inclusive = false, bool sorted = false) {\n  assert(mode\
    \ == \"full\" || mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n\
    \  if (N == 1) return {0};\n  if (N == 2) return {0, 1};\n  vc<int> I = argsort(XY);\n\
    \n  auto check = [&](ll i, ll j, ll k) -> bool {\n    auto xi = XY[i].x, yi =\
    \ XY[i].y;\n    auto xj = XY[j].x, yj = XY[j].y;\n    auto xk = XY[k].x, yk =\
    \ XY[k].y;\n    auto dx1 = xj - xi, dy1 = yj - yi;\n    auto dx2 = xk - xj, dy2\
    \ = yk - yj;\n    T det = dx1 * dy2 - dy1 * dx2;\n    return (inclusive ? det\
    \ >= 0 : det > 0);\n  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for\
    \ (auto&& k: I) {\n      while (P.size() > 1) {\n        auto i = P[P.size() -\
    \ 2];\n        auto j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n\
    \        P.pop_back();\n      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n\
    \  vc<int> P;\n  if (mode == \"full\" || mode == \"lower\") {\n    vc<int> Q =\
    \ calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"full\" || mode\
    \ == \"upper\") {\n    if (!P.empty()) P.pop_back();\n    reverse(all(I));\n \
    \   vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"\
    upper\") reverse(all(P));\n  if (len(P) >= 2 && P[0] == P.back()) P.pop_back();\n\
    \  return P;\n}"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/convex_hull.hpp
  requiredBy:
  - convex/fenchel.hpp
  timestamp: '2023-06-23 23:20:58+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc130f.test.cpp
documentation_of: geo/convex_hull.hpp
layout: document
redirect_from:
- /library/geo/convex_hull.hpp
- /library/geo/convex_hull.hpp.html
title: geo/convex_hull.hpp
---
