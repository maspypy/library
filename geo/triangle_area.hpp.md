---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geo/delaunay_triangulation_of_convex_polygon.hpp
    title: geo/delaunay_triangulation_of_convex_polygon.hpp
  - icon: ':x:'
    path: geo/incircle.hpp
    title: geo/incircle.hpp
  - icon: ':warning:'
    path: geo/minimum_enclosing_circle.hpp
    title: geo/minimum_enclosing_circle.hpp
  - icon: ':x:'
    path: geo/outcircle.hpp
    title: geo/outcircle.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2602.test.cpp
    title: test/3_yukicoder/2602.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/3005.test.cpp
    title: test/3_yukicoder/3005.test.cpp
  - icon: ':x:'
    path: test/4_aoj/CGL_7_B.test.cpp
    title: test/4_aoj/CGL_7_B.test.cpp
  - icon: ':x:'
    path: test/4_aoj/CGL_7_C.test.cpp
    title: test/4_aoj/CGL_7_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/geo/triangle_area.hpp
  bundledCode: "#line 1 \"geo/triangle_area.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/triangle_area.hpp\n\
    template <typename REAL, typename T>\nREAL triangle_area(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  return abs((B - A).det(C - A)) * 0.5;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/geo/triangle_area.hpp\n\
    template <typename REAL, typename T>\nREAL triangle_area(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  return abs((B - A).det(C - A)) * 0.5;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/triangle_area.hpp
  requiredBy:
  - geo/delaunay_triangulation_of_convex_polygon.hpp
  - geo/incircle.hpp
  - geo/outcircle.hpp
  - geo/minimum_enclosing_circle.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2602.test.cpp
  - test/3_yukicoder/3005.test.cpp
  - test/4_aoj/CGL_7_C.test.cpp
  - test/4_aoj/CGL_7_B.test.cpp
documentation_of: geo/triangle_area.hpp
layout: document
redirect_from:
- /library/geo/triangle_area.hpp
- /library/geo/triangle_area.hpp.html
title: geo/triangle_area.hpp
---
