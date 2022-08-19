---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo_old/base.hpp\"\n\ntemplate<typename X = long long>\n\
    struct Point {\n  X x, y;\n  Point(X x=0, X y=0) : x(x), y(y) {}\n\n  template\
    \ <typename S, typename T>\n  Point(pair<S, T> p) : x(p.fi), y(p.se) {}\n\n  Point\
    \ operator+(Point p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point\
    \ p) const { return {x - p.x, y - p.y}; }\n  X det(Point p) const { return x *\
    \ p.y - y * p.x; }\n  X dot(Point p) const { return x * p.x + y * p.y; }\n  pair<double,double>\
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
  path: geo_old/base.hpp
  requiredBy: []
  timestamp: '2022-08-20 04:25:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo_old/base.hpp
layout: document
redirect_from:
- /library/geo_old/base.hpp
- /library/geo_old/base.hpp.html
title: geo_old/base.hpp
---
