---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n  template <typename A, typename B>\n  Point(A x, B y) : x(x), y(y)\
    \ {}\n\n  template <typename A, typename B>\n  Point(pair<A, B> p) : x(p.fi),\
    \ y(p.se) {}\n\n  Point operator+(Point p) const { return {x + p.x, y + p.y};\
    \ }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n  bool operator==(Point\
    \ p) const { return x == p.x && y == p.y; }\n  Point operator-() const { return\
    \ {-x, -y}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x\
    \ < p.x;\n    return y < p.y;\n  }\n\n  T dot(Point other) { return x * other.x\
    \ + y * other.y; }\n  T det(Point other) { return x * other.y - y * other.x; }\n\
    };\n\ntemplate <typename REAL, typename T>\nREAL dist(Point<T> A, Point<T> B)\
    \ {\n  A -= B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n}\n\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y;\n    b = B.x - A.x;\n\
    \    c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U\
    \ x, U y) {\n    return a * x + b * y + c;\n  }\n};\n#line 2 \"geo_old/convexhull.hpp\"\
    \n\r\ntemplate<typename T>\r\nvector<int> ConvexHull(vector<pair<T, T>>& XY, string\
    \ mode = \"full\",\r\n                      bool inclusive = false, bool sorted\
    \ = false) {\r\n  assert(mode == \"full\" || mode == \"lower\" || mode == \"upper\"\
    );\r\n  ll N = XY.size();\r\n  if (N == 1) return {0};\r\n  if (N == 2) return\
    \ {0, 1};\r\n  vc<int> I = argsort(XY);\r\n\r\n  auto check = [&](ll i, ll j,\
    \ ll k) -> bool {\r\n    auto xi = XY[i].fi, yi = XY[i].se;\r\n    auto xj = XY[j].fi,\
    \ yj = XY[j].se;\r\n    auto xk = XY[k].fi, yk = XY[k].se;\r\n    auto dx1 = xj\
    \ - xi, dy1 = yj - yi;\r\n    auto dx2 = xk - xj, dy2 = yk - yj;\r\n    ll det\
    \ = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive ? det >= 0 : det > 0);\r\n\
    \  };\r\n\r\n  auto calc = [&]() {\r\n    vector<int> P;\r\n    for (auto&& k:\
    \ I) {\r\n      while (P.size() > 1) {\r\n        auto i = P[P.size() - 2];\r\n\
    \        auto j = P[P.size() - 1];\r\n        if (check(i, j, k)) break;\r\n \
    \       P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\n    return P;\r\
    \n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode == \"lower\") {\r\
    \n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\n  }\r\n  if (mode\
    \ == \"full\" || mode == \"upper\") {\r\n    if (!P.empty()) P.pop_back();\r\n\
    \    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P) >= 2 && P[0]\
    \ == P.back()) P.pop_back();\r\n  return P;\r\n}\r\n\r\ntemplate<typename X>\r\
    \nvc<int> ConvexHull(vector<Point<X>>& XY, string mode = \"full\",\r\n       \
    \               bool inclusive = false, bool sorted = false) {\r\n  assert(mode\
    \ == \"full\" || mode == \"lower\" || mode == \"upper\");\r\n  ll N = XY.size();\r\
    \n  if (N == 1) return {0};\r\n  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\
    \n\r\n  auto check = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].x,\
    \ yi = XY[i].y;\r\n    auto xj = XY[j].x, yj = XY[j].y;\r\n    auto xk = XY[k].x,\
    \ yk = XY[k].y;\r\n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk\
    \ - xj, dy2 = yk - yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive\
    \ ? det >= 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vc<int> P;\r\
    \n    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto i =\
    \ P[P.size() - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i,\
    \ j, k)) break;\r\n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\
    \n    return P;\r\n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode\
    \ == \"lower\") {\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"full\" || mode == \"upper\") {\r\n    if (!P.empty())\
    \ P.pop_back();\r\n    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(),\
    \ all(Q));\r\n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P)\
    \ >= 2 && P[0] == P.back()) P.pop_back();\r\n  return P;\r\n}\n"
  code: "#include \"geo/base.hpp\"\r\n\r\ntemplate<typename T>\r\nvector<int> ConvexHull(vector<pair<T,\
    \ T>>& XY, string mode = \"full\",\r\n                      bool inclusive = false,\
    \ bool sorted = false) {\r\n  assert(mode == \"full\" || mode == \"lower\" ||\
    \ mode == \"upper\");\r\n  ll N = XY.size();\r\n  if (N == 1) return {0};\r\n\
    \  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\n\r\n  auto check\
    \ = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].fi, yi = XY[i].se;\r\
    \n    auto xj = XY[j].fi, yj = XY[j].se;\r\n    auto xk = XY[k].fi, yk = XY[k].se;\r\
    \n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk - xj, dy2 = yk -\
    \ yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive ? det >=\
    \ 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vector<int> P;\r\n\
    \    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto i = P[P.size()\
    \ - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i, j, k)) break;\r\
    \n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\n    return P;\r\
    \n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode == \"lower\") {\r\
    \n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\n  }\r\n  if (mode\
    \ == \"full\" || mode == \"upper\") {\r\n    if (!P.empty()) P.pop_back();\r\n\
    \    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P) >= 2 && P[0]\
    \ == P.back()) P.pop_back();\r\n  return P;\r\n}\r\n\r\ntemplate<typename X>\r\
    \nvc<int> ConvexHull(vector<Point<X>>& XY, string mode = \"full\",\r\n       \
    \               bool inclusive = false, bool sorted = false) {\r\n  assert(mode\
    \ == \"full\" || mode == \"lower\" || mode == \"upper\");\r\n  ll N = XY.size();\r\
    \n  if (N == 1) return {0};\r\n  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\
    \n\r\n  auto check = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].x,\
    \ yi = XY[i].y;\r\n    auto xj = XY[j].x, yj = XY[j].y;\r\n    auto xk = XY[k].x,\
    \ yk = XY[k].y;\r\n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk\
    \ - xj, dy2 = yk - yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive\
    \ ? det >= 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vc<int> P;\r\
    \n    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto i =\
    \ P[P.size() - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i,\
    \ j, k)) break;\r\n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\
    \n    return P;\r\n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode\
    \ == \"lower\") {\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"full\" || mode == \"upper\") {\r\n    if (!P.empty())\
    \ P.pop_back();\r\n    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(),\
    \ all(Q));\r\n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P)\
    \ >= 2 && P[0] == P.back()) P.pop_back();\r\n  return P;\r\n}"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo_old/convexhull.hpp
  requiredBy: []
  timestamp: '2022-08-20 05:23:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo_old/convexhull.hpp
layout: document
redirect_from:
- /library/geo_old/convexhull.hpp
- /library/geo_old/convexhull.hpp.html
title: geo_old/convexhull.hpp
---
