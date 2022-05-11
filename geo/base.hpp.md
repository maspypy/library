---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':warning:'
    path: geo/convexhull.hpp
    title: geo/convexhull.hpp
  - icon: ':x:'
    path: geo/dynamicupperhull.hpp
    title: geo/dynamicupperhull.hpp
  - icon: ':warning:'
    path: geo/points_diameter.hpp
    title: geo/points_diameter.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/geometry/convex_layers.test.cpp
    title: test/library_checker/geometry/convex_layers.test.cpp
  - icon: ':x:'
    path: test/library_checker/geometry/sort_points_by_argument.test.cpp
    title: test/library_checker/geometry/sort_points_by_argument.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ }\n};\n"
  code: "#pragma once\n\ntemplate<typename X = long long>\nstruct Point {\n  X x,\
    \ y;\n  Point(X x=0, X y=0) : x(x), y(y) {}\n\n  template <typename S, typename\
    \ T>\n  Point(pair<S, T> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p)\
    \ const { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const { return\
    \ {x - p.x, y - p.y}; }\n  X det(Point p) const { return x * p.y - y * p.x; }\n\
    \  X dot(Point p) const { return x * p.x + y * p.y; }\n  pair<double,double> polar(){\n\
    \    double r = sqrt(x * x + y * y);\n    double theta = atan2(y, x);\n    return\
    \ {r, theta};\n  }\n  bool operator<(Point p) const {\n    if (x != p.x) return\
    \ x < p.x;\n    return y < p.y;\n  }\n  bool operator==(Point p) const { return\
    \ x == p.x && y == p.y; }\n  Point operator-() const { return {-x, -y}; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/base.hpp
  requiredBy:
  - geo/dynamicupperhull.hpp
  - geo/angle_sort.hpp
  - geo/points_diameter.hpp
  - geo/convexhull.hpp
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/geometry/sort_points_by_argument.test.cpp
  - test/library_checker/geometry/convex_layers.test.cpp
documentation_of: geo/base.hpp
layout: document
redirect_from:
- /library/geo/base.hpp
- /library/geo/base.hpp.html
title: geo/base.hpp
---
