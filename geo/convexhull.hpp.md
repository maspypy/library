---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geo/points_diameter.hpp
    title: geo/points_diameter.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\n\ntemplate<typename X = long long>\nstruct\
    \ Point {\n  X x, y;\n  Point(X x=0, X y=0) : x(x), y(y) {}\n\n  template <typename\
    \ S, typename T>\n  Point(pair<S, T> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point\
    \ p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const {\
    \ return {x - p.x, y - p.y}; }\n  X det(Point p) const { return x * p.y - y *\
    \ p.x; }\n  X dot(Point p) const { return x * p.x + y * p.y; }\n  pair<double,double>\
    \ polar(){\n    double r = sqrt(x * x + y * y);\n    double theta = atan2(y, x);\n\
    \    return {r, theta};\n  }\n  bool operator<(Point p) const {\n    if (x !=\
    \ p.x) return x < p.x;\n    return y < p.y;\n  }\n  bool operator==(Point p) const\
    \ { return x == p.x && y == p.y; }\n  Point operator-() const { return {-x, -y};\
    \ }\n};\n#line 2 \"geo/convexhull.hpp\"\n\r\ntemplate<typename T>\r\nvector<T>\
    \ ConvexHull(vector<pair<T, T>>& XY, string mode = \"full\",\r\n             \
    \         bool inclusive = false, bool sorted = false) {\r\n  assert(mode == \"\
    full\" || mode == \"lower\" || mode == \"upper\");\r\n  ll N = XY.size();\r\n\
    \  if (N == 1) return {0};\r\n  if (N == 2) return {0, 1};\r\n  vc<int> I = argsort(XY);\r\
    \n\r\n  auto check = [&](ll i, ll j, ll k) -> bool {\r\n    auto xi = XY[i].fi,\
    \ yi = XY[i].se;\r\n    auto xj = XY[j].fi, yj = XY[j].se;\r\n    auto xk = XY[k].fi,\
    \ yk = XY[k].se;\r\n    auto dx1 = xj - xi, dy1 = yj - yi;\r\n    auto dx2 = xk\
    \ - xj, dy2 = yk - yj;\r\n    ll det = dx1 * dy2 - dy1 * dx2;\r\n    return (inclusive\
    \ ? det >= 0 : det > 0);\r\n  };\r\n\r\n  auto calc = [&]() {\r\n    vector<int>\
    \ P;\r\n    for (auto&& k: I) {\r\n      while (P.size() > 1) {\r\n        auto\
    \ i = P[P.size() - 2];\r\n        auto j = P[P.size() - 1];\r\n        if (check(i,\
    \ j, k)) break;\r\n        P.pop_back();\r\n      }\r\n      P.eb(k);\r\n    }\r\
    \n    return P;\r\n  };\r\n\r\n  vc<int> P;\r\n  if (mode == \"full\" || mode\
    \ == \"lower\") {\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(), all(Q));\r\
    \n  }\r\n  if (mode == \"full\" || mode == \"upper\") {\r\n    if (!P.empty())\
    \ P.pop_back();\r\n    reverse(all(I));\r\n    vc<int> Q = calc();\r\n    P.insert(P.end(),\
    \ all(Q));\r\n  }\r\n  if (mode == \"upper\") reverse(all(P));\r\n  if(len(P)\
    \ >= 2 && P[0] == P.back()) P.pop_back();\r\n  return P;\r\n}\r\n\r\ntemplate<typename\
    \ X>\r\nvc<int> ConvexHull(vector<Point<X>>& XY, string mode = \"full\",\r\n \
    \                     bool inclusive = false, bool sorted = false) {\r\n  assert(mode\
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
  code: "#include \"geo/base.hpp\"\r\n\r\ntemplate<typename T>\r\nvector<T> ConvexHull(vector<pair<T,\
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
  path: geo/convexhull.hpp
  requiredBy:
  - geo/points_diameter.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/convexhull.hpp
layout: document
redirect_from:
- /library/geo/convexhull.hpp
- /library/geo/convexhull.hpp.html
title: geo/convexhull.hpp
---
