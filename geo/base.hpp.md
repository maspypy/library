---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/projection.hpp
    title: geo/projection.hpp
  - icon: ':heavy_check_mark:'
    path: geo/reflection.hpp
    title: geo/reflection.hpp
  - icon: ':warning:'
    path: geo_old/angle_sort.hpp
    title: geo_old/angle_sort.hpp
  - icon: ':warning:'
    path: geo_old/convexhull.hpp
    title: geo_old/convexhull.hpp
  - icon: ':warning:'
    path: geo_old/dynamicupperhull.hpp
    title: geo_old/dynamicupperhull.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
  - icon: ':x:'
    path: test/aoj/CGL_2_A.test.cpp
    title: test/aoj/CGL_2_A.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
    \ x, U y) {\n    return a * x + b * y + c;\n  }\n};\n"
  code: "#pragma once\ntemplate <typename T>\nstruct Point {\n  T x, y;\n  template\
    \ <typename A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename\
    \ A, typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point\
    \ p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const {\
    \ return {x - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x ==\
    \ p.x && y == p.y; }\n  Point operator-() const { return {-x, -y}; }\n\n  bool\
    \ operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n    return y\
    \ < p.y;\n  }\n\n  T dot(Point other) { return x * other.x + y * other.y; }\n\
    \  T det(Point other) { return x * other.y - y * other.x; }\n};\n\ntemplate <typename\
    \ REAL, typename T>\nREAL dist(Point<T> A, Point<T> B) {\n  A -= B;\n  T p = A.dot(A);\n\
    \  return sqrt(REAL(p));\n}\n\ntemplate <typename T>\nstruct Line {\n  T a, b,\
    \ c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T>\
    \ B) {\n    a = A.y - B.y;\n    b = B.x - A.x;\n    c = A.x * B.y - A.y * B.x;\n\
    \  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n    return a * P.x +\
    \ b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return\
    \ a * x + b * y + c;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/base.hpp
  requiredBy:
  - geo_old/convexhull.hpp
  - geo_old/dynamicupperhull.hpp
  - geo_old/angle_sort.hpp
  - geo/projection.hpp
  - geo/reflection.hpp
  timestamp: '2022-08-20 05:23:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_2_A.test.cpp
documentation_of: geo/base.hpp
layout: document
redirect_from:
- /library/geo/base.hpp
- /library/geo/base.hpp.html
title: geo/base.hpp
---
