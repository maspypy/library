---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':warning:'
    path: geo/convexhull.hpp
    title: geo/convexhull.hpp
  _extendedRequiredBy: []
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
    \ }\n};\n#line 2 \"geo/convexhull.hpp\"\n\r\ntemplate<typename T>\r\nvector<int>\
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
    \ >= 2 && P[0] == P.back()) P.pop_back();\r\n  return P;\r\n}\n#line 3 \"geo/points_diameter.hpp\"\
    \n\n// \u6700\u9060\u70B9\u5BFE\u3068\u306A\u308B 2 \u70B9\u306E index \u3092\u304B\
    \u3048\u3059\u3002\u7A7A\u96C6\u5408\u306F\u30A8\u30E9\u30FC\u3002\ntemplate <typename\
    \ T>\npair<int, int> points_diameter(vc<Point<T>>& XY) {\n  ll N = len(XY);\n\
    \  assert(N >= 1);\n  if (N == 1) return {0, 0};\n  auto I = ConvexHull(XY, \"\
    full\");\n  pi res = {0, 0};\n  ll best = 0;\n  ll s = 0;\n  FOR(k, len(I)) {\n\
    \    ll i = (k == 0 ? I.back() : I[k - 1]), j = I[k];\n    Point<T> A = XY[i],\
    \ B = XY[j];\n    ll dx = B.x - A.x, dy = B.y - A.y;\n    Point<T> vec = {-dy,\
    \ dx};\n    while (1) {\n      Point<T> p = XY[I[s]], q = XY[I[(s + 1) % len(I)]];\n\
    \      if (vec.dot(p - q) < 0)\n        s = (s + 1) % len(I);\n      else\n  \
    \      break;\n    }\n    Point<T> C = XY[I[s]];\n    if (chmax(best, (A - C).dot(A\
    \ - C))) res = {i, I[s]};\n    if (chmax(best, (B - C).dot(B - C))) res = {j,\
    \ I[s]};\n  }\n  return res;\n}\n"
  code: "#include \"geo/convexhull.hpp\"\n#include \"geo/base.hpp\"\n\n// \u6700\u9060\
    \u70B9\u5BFE\u3068\u306A\u308B 2 \u70B9\u306E index \u3092\u304B\u3048\u3059\u3002\
    \u7A7A\u96C6\u5408\u306F\u30A8\u30E9\u30FC\u3002\ntemplate <typename T>\npair<int,\
    \ int> points_diameter(vc<Point<T>>& XY) {\n  ll N = len(XY);\n  assert(N >= 1);\n\
    \  if (N == 1) return {0, 0};\n  auto I = ConvexHull(XY, \"full\");\n  pi res\
    \ = {0, 0};\n  ll best = 0;\n  ll s = 0;\n  FOR(k, len(I)) {\n    ll i = (k ==\
    \ 0 ? I.back() : I[k - 1]), j = I[k];\n    Point<T> A = XY[i], B = XY[j];\n  \
    \  ll dx = B.x - A.x, dy = B.y - A.y;\n    Point<T> vec = {-dy, dx};\n    while\
    \ (1) {\n      Point<T> p = XY[I[s]], q = XY[I[(s + 1) % len(I)]];\n      if (vec.dot(p\
    \ - q) < 0)\n        s = (s + 1) % len(I);\n      else\n        break;\n    }\n\
    \    Point<T> C = XY[I[s]];\n    if (chmax(best, (A - C).dot(A - C))) res = {i,\
    \ I[s]};\n    if (chmax(best, (B - C).dot(B - C))) res = {j, I[s]};\n  }\n  return\
    \ res;\n}\n"
  dependsOn:
  - geo/convexhull.hpp
  - geo/base.hpp
  isVerificationFile: false
  path: geo/points_diameter.hpp
  requiredBy: []
  timestamp: '2022-08-13 02:22:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/points_diameter.hpp
layout: document
redirect_from:
- /library/geo/points_diameter.hpp
- /library/geo/points_diameter.hpp.html
title: geo/points_diameter.hpp
---
