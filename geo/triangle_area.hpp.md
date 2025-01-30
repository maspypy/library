---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/incircle.hpp
    title: geo/incircle.hpp
  - icon: ':warning:'
    path: geo/minimum_enclosing_circle.hpp
    title: geo/minimum_enclosing_circle.hpp
  - icon: ':heavy_check_mark:'
    path: geo/outcircle.hpp
    title: geo/outcircle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2602.test.cpp
    title: test/3_yukicoder/2602.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/3005.test.cpp
    title: test/3_yukicoder/3005.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/CGL_7_B.test.cpp
    title: test/4_aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/CGL_7_C.test.cpp
    title: test/4_aoj/CGL_7_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/triangle_area.hpp\"\ntemplate <typename REAL, typename\
    \ T>\nREAL triangle_area(Point<T> A, Point<T> B, Point<T> C) {\n  return abs((B\
    \ - A).det(C - A)) * 0.5;\n}\n"
  code: "template <typename REAL, typename T>\nREAL triangle_area(Point<T> A, Point<T>\
    \ B, Point<T> C) {\n  return abs((B - A).det(C - A)) * 0.5;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/triangle_area.hpp
  requiredBy:
  - geo/minimum_enclosing_circle.hpp
  - geo/outcircle.hpp
  - geo/incircle.hpp
  timestamp: '2022-08-20 20:06:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/3005.test.cpp
  - test/3_yukicoder/2602.test.cpp
  - test/4_aoj/CGL_7_C.test.cpp
  - test/4_aoj/CGL_7_B.test.cpp
documentation_of: geo/triangle_area.hpp
layout: document
redirect_from:
- /library/geo/triangle_area.hpp
- /library/geo/triangle_area.hpp.html
title: geo/triangle_area.hpp
---
