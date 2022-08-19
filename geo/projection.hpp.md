---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/projection.hpp\"\n\n#line 2 \"geo/base.hpp\"\ntemplate\
    \ <typename T>\nstruct Point {\n  T x, y;\n  template <typename A, typename B>\n\
    \  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n\n  bool operator<(Point p) const\
    \ {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n\n  T dot(Point\
    \ other) { return x * other.x + y * other.y; }\n  T det(Point other) { return\
    \ x * other.y - y * other.x; }\n};\n\ntemplate <typename REAL, typename T>\nREAL\
    \ dist(Point<T> A, Point<T> B) {\n  A -= B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n\
    }\n\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T\
    \ c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y;\n\
    \    b = B.x - A.x;\n    c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T\
    \ x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename\
    \ U>\n  U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\n  template\
    \ <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n \
    \ template <enable_if_t<is_integral<T>::value, int> = 0>\n  bool is_parallel(Line\
    \ other) {\n    return a * other.b - b * other.a == 0;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  bool is_orthogonal(Line other) {\n    return a * other.a + b *\
    \ other.b == 0;\n  }\n};\n#line 4 \"geo/projection.hpp\"\n\ntemplate <typename\
    \ REAL, typename T, typename U>\nPoint<REAL> projection(Point<T> P, Line<U> L)\
    \ {\n  REAL t = REAL(L.eval(P)) / (L.a * L.a + L.b * L.b);\n  REAL x = P.x - t\
    \ * L.a;\n  REAL y = P.y - t * L.b;\n  return Point<REAL>(x, y);\n};\n"
  code: "#pragma once\n\n#include \"geo/base.hpp\"\n\ntemplate <typename REAL, typename\
    \ T, typename U>\nPoint<REAL> projection(Point<T> P, Line<U> L) {\n  REAL t =\
    \ REAL(L.eval(P)) / (L.a * L.a + L.b * L.b);\n  REAL x = P.x - t * L.a;\n  REAL\
    \ y = P.y - t * L.b;\n  return Point<REAL>(x, y);\n};\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/projection.hpp
  requiredBy: []
  timestamp: '2022-08-20 06:37:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_1_A.test.cpp
documentation_of: geo/projection.hpp
layout: document
redirect_from:
- /library/geo/projection.hpp
- /library/geo/projection.hpp.html
title: geo/projection.hpp
---
