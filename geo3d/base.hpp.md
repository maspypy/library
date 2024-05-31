---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: geo3d/cross_point.hpp
    title: geo3d/cross_point.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc301g.test.cpp
    title: test_atcoder/abc301g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo3d/base.hpp\"\n\ntemplate <typename T>\nstruct Point_3d\
    \ {\n  T x, y, z;\n\n  Point_3d() = default;\n\n  template <typename A, typename\
    \ B, typename C>\n  Point_3d(A x, B y, C z) : x(x), y(y), z(z) {}\n\n  Point_3d\
    \ operator+(Point_3d p) const { return {x + p.x, y + p.y, z + p.z}; }\n  Point_3d\
    \ operator-(Point_3d p) const { return {x - p.x, y - p.y, z - p.z}; }\n  Point_3d\
    \ operator*(T t) const { return {x * t, y * t, z * t}; }\n  bool operator==(Point_3d\
    \ p) const { return x == p.x && y == p.y && z == p.z; }\n  bool operator!=(Point_3d\
    \ p) const { return x != p.x || y != p.y || z == p.z; }\n  Point_3d operator-()\
    \ const { return {-x, -y, -z}; }\n\n  bool is_parallel(Point_3d p) const {\n \
    \   return x * p.y == y * p.x && y * p.z == z * p.y && z * p.x == x * p.z;\n \
    \ }\n\n  T dot(Point_3d other) { return x * other.x + y * other.y + z * other.z;\
    \ }\n  double norm() { return sqrt(x * x + y * y + z * z); }\n  Point_3d cross(Point_3d\
    \ other) {\n    return Point_3d(y * other.z - z * other.y, z * other.x - x * other.z,\n\
    \                    x * other.y - y * other.x);\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct Line_3d {\n  // a + td\n  Point_3d<T> a, d;\n\n  Line_3d(Point_3d<T>\
    \ A, Point_3d<T> B) : a(A), d(B - A) {\n    assert(d.dot(d) != 0);\n  }\n  bool\
    \ is_parallel(Line_3d<T> other) {\n    Point_3d<T> n = d.cross(other.d);\n   \
    \ return (n.x == T(0) && n.y == T(0) && n.z == T(0));\n  }\n  bool contain(Point_3d<T>\
    \ p) {\n    p = p - a;\n    p = p.cross(d);\n    return (p.x == T(0) && p.y ==\
    \ T(0) && p.z == T(0));\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Point_3d {\n  T x, y, z;\n\n\
    \  Point_3d() = default;\n\n  template <typename A, typename B, typename C>\n\
    \  Point_3d(A x, B y, C z) : x(x), y(y), z(z) {}\n\n  Point_3d operator+(Point_3d\
    \ p) const { return {x + p.x, y + p.y, z + p.z}; }\n  Point_3d operator-(Point_3d\
    \ p) const { return {x - p.x, y - p.y, z - p.z}; }\n  Point_3d operator*(T t)\
    \ const { return {x * t, y * t, z * t}; }\n  bool operator==(Point_3d p) const\
    \ { return x == p.x && y == p.y && z == p.z; }\n  bool operator!=(Point_3d p)\
    \ const { return x != p.x || y != p.y || z == p.z; }\n  Point_3d operator-() const\
    \ { return {-x, -y, -z}; }\n\n  bool is_parallel(Point_3d p) const {\n    return\
    \ x * p.y == y * p.x && y * p.z == z * p.y && z * p.x == x * p.z;\n  }\n\n  T\
    \ dot(Point_3d other) { return x * other.x + y * other.y + z * other.z; }\n  double\
    \ norm() { return sqrt(x * x + y * y + z * z); }\n  Point_3d cross(Point_3d other)\
    \ {\n    return Point_3d(y * other.z - z * other.y, z * other.x - x * other.z,\n\
    \                    x * other.y - y * other.x);\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct Line_3d {\n  // a + td\n  Point_3d<T> a, d;\n\n  Line_3d(Point_3d<T>\
    \ A, Point_3d<T> B) : a(A), d(B - A) {\n    assert(d.dot(d) != 0);\n  }\n  bool\
    \ is_parallel(Line_3d<T> other) {\n    Point_3d<T> n = d.cross(other.d);\n   \
    \ return (n.x == T(0) && n.y == T(0) && n.z == T(0));\n  }\n  bool contain(Point_3d<T>\
    \ p) {\n    p = p - a;\n    p = p.cross(d);\n    return (p.x == T(0) && p.y ==\
    \ T(0) && p.z == T(0));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geo3d/base.hpp
  requiredBy:
  - geo3d/cross_point.hpp
  timestamp: '2024-05-27 19:13:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc301g.test.cpp
documentation_of: geo3d/base.hpp
layout: document
redirect_from:
- /library/geo3d/base.hpp
- /library/geo3d/base.hpp.html
title: geo3d/base.hpp
---
