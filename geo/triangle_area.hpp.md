---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo/incircle.hpp
    title: geo/incircle.hpp
  - icon: ':x:'
    path: geo/minimum_enclosing_circle.hpp
    title: geo/minimum_enclosing_circle.hpp
  - icon: ':question:'
    path: geo/outcircle.hpp
    title: geo/outcircle.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc151f.test.cpp
    title: test_atcoder/abc151f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - geo/incircle.hpp
  - geo/outcircle.hpp
  - geo/minimum_enclosing_circle.hpp
  timestamp: '2022-08-20 20:06:17+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc151f.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_7_B.test.cpp
documentation_of: geo/triangle_area.hpp
layout: document
redirect_from:
- /library/geo/triangle_area.hpp
- /library/geo/triangle_area.hpp.html
title: geo/triangle_area.hpp
---
