---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/geometry/sort_points_by_argument.test.cpp
    title: test/library_checker/geometry/sort_points_by_argument.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ }\n};\n#line 2 \"geo/angle_sort.hpp\"\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\
    \u306B\u5BFE\u3059\u308B argsort\r\ntemplate<typename Point>\r\nvector<int> angle_argsort(vector<Point>&\
    \ P) {\r\n  auto is_lower = [](Point P) { return (P.y < 0) || (P.y == 0 && P.x\
    \ > 0); };\r\n  vector<int> lower, origin, upper;\r\n  Point O = {0, 0};\r\n \
    \ FOR(i, len(P)) {\r\n    if (P[i] == O) origin.eb(i);\r\n    elif (is_lower(P[i]))\
    \ lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  sort(all(upper), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  auto& I = lower;\r\n  I.insert(I.end(),\
    \ all(origin));\r\n  I.insert(I.end(), all(upper));\r\n  return I;\r\n}\r\n\r\n\
    // inplace \u306B\u504F\u89D2\u30BD\u30FC\u30C8\u3059\u308B\r\n// index \u304C\
    \u6B32\u3057\u3044\u5834\u5408\u306F angle_argsort\r\ntemplate<typename Point>\r\
    \nvoid angle_sort(vector<Point>& P) {\r\n  auto I = angle_argsort(P);\r\n  vc<Point>\
    \ Q(len(P));\r\n  FOR(i, len(P)) Q[i] = P[I[i]];\r\n  P = Q;\r\n}\r\n"
  code: "#include \"geo/base.hpp\"\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\
    \u3059\u308B argsort\r\ntemplate<typename Point>\r\nvector<int> angle_argsort(vector<Point>&\
    \ P) {\r\n  auto is_lower = [](Point P) { return (P.y < 0) || (P.y == 0 && P.x\
    \ > 0); };\r\n  vector<int> lower, origin, upper;\r\n  Point O = {0, 0};\r\n \
    \ FOR(i, len(P)) {\r\n    if (P[i] == O) origin.eb(i);\r\n    elif (is_lower(P[i]))\
    \ lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  sort(all(upper), [&](auto&\
    \ i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  auto& I = lower;\r\n  I.insert(I.end(),\
    \ all(origin));\r\n  I.insert(I.end(), all(upper));\r\n  return I;\r\n}\r\n\r\n\
    // inplace \u306B\u504F\u89D2\u30BD\u30FC\u30C8\u3059\u308B\r\n// index \u304C\
    \u6B32\u3057\u3044\u5834\u5408\u306F angle_argsort\r\ntemplate<typename Point>\r\
    \nvoid angle_sort(vector<Point>& P) {\r\n  auto I = angle_argsort(P);\r\n  vc<Point>\
    \ Q(len(P));\r\n  FOR(i, len(P)) Q[i] = P[I[i]];\r\n  P = Q;\r\n}\r\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/angle_sort.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/geometry/sort_points_by_argument.test.cpp
documentation_of: geo/angle_sort.hpp
layout: document
redirect_from:
- /library/geo/angle_sort.hpp
- /library/geo/angle_sort.hpp.html
title: geo/angle_sort.hpp
---
