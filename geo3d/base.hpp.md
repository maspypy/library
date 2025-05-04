---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geo3d/cross_point.hpp
    title: geo3d/cross_point.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo3d/base.hpp\"\n\ntemplate <typename T>\nstruct Point_3d\
    \ {\n  T x, y, z;\n\n  Point_3d() = default;\n\n  template <typename A, typename\
    \ B, typename C>\n  Point_3d(A x, B y, C z) : x(x), y(y), z(z) {}\n\n  Point_3d\
    \ operator+(Point_3d p) const { return {x + p.x, y + p.y, z + p.z}; }\n  Point_3d\
    \ operator-(Point_3d p) const { return {x - p.x, y - p.y, z - p.z}; }\n  Point_3d\
    \ operator*(T t) const { return {x * t, y * t, z * t}; }\n  Point_3d operator/(T\
    \ t) const { return {x / t, y / t, z / t}; }\n  bool operator==(Point_3d p) const\
    \ { return x == p.x && y == p.y && z == p.z; }\n  bool operator!=(Point_3d p)\
    \ const { return x != p.x || y != p.y || z == p.z; }\n  Point_3d operator-() const\
    \ { return {-x, -y, -z}; }\n\n  bool is_parallel(Point_3d p) const { return x\
    \ * p.y == y * p.x && y * p.z == z * p.y && z * p.x == x * p.z; }\n\n  T dot(Point_3d\
    \ other) { return x * other.x + y * other.y + z * other.z; }\n  double norm()\
    \ { return sqrt(x * x + y * y + z * z); }\n  Point_3d cross(Point_3d other) {\
    \ return Point_3d(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y\
    \ - y * other.x); }\n};\n\ntemplate <typename T>\nstruct Line_3d {\n  // a + td\n\
    \  Point_3d<T> a, d;\n\n  Line_3d(Point_3d<T> A, Point_3d<T> B) : a(A), d(B -\
    \ A) { assert(d.dot(d) != 0); }\n  bool is_parallel(Line_3d<T> other) {\n    Point_3d<T>\
    \ n = d.cross(other.d);\n    return (n.x == T(0) && n.y == T(0) && n.z == T(0));\n\
    \  }\n  bool contain(Point_3d<T> p) {\n    p = p - a;\n    p = p.cross(d);\n \
    \   return (p.x == T(0) && p.y == T(0) && p.z == T(0));\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct Plane {\n  // ax + by + cz == d\n  T a, b, c, d;\n  Point_3d<T> normal_vec;\n\
    \n  Plane(Point_3d<T> A, Point_3d<T> B, Point_3d<T> C) {\n    Point_3d<T> AB =\
    \ B - A;\n    Point_3d<T> AC = C - A;\n    normal_vec = AB.cross(AC);\n    a =\
    \ normal_vec.x, b = normal_vec.y, c = normal_vec.z;\n    d = normal_vec.dot(A);\n\
    \  }\n\n  int side(Point_3d<T> p) {\n    T x = normal_vec.dot(p) - d;\n    if\
    \ (x == 0) return 0;\n    return (x > 0 ? 1 : -1);\n  }\n\n  template <typename\
    \ Re>\n  Point_3d<Re> cross_point(Line_3d<T> L) {\n    // a + td\n    T x = normal_vec.dot(L.a);\n\
    \    T y = normal_vec.dot(L.d);\n    Re t = Re(d - x) / y;\n    Point_3d<Re> ANS;\n\
    \    ANS.x = L.a.x + t * L.d.x;\n    ANS.y = L.a.y + t * L.d.y;\n    ANS.z = L.a.z\
    \ + t * L.d.z;\n    return ANS;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Point_3d {\n  T x, y, z;\n\n\
    \  Point_3d() = default;\n\n  template <typename A, typename B, typename C>\n\
    \  Point_3d(A x, B y, C z) : x(x), y(y), z(z) {}\n\n  Point_3d operator+(Point_3d\
    \ p) const { return {x + p.x, y + p.y, z + p.z}; }\n  Point_3d operator-(Point_3d\
    \ p) const { return {x - p.x, y - p.y, z - p.z}; }\n  Point_3d operator*(T t)\
    \ const { return {x * t, y * t, z * t}; }\n  Point_3d operator/(T t) const { return\
    \ {x / t, y / t, z / t}; }\n  bool operator==(Point_3d p) const { return x ==\
    \ p.x && y == p.y && z == p.z; }\n  bool operator!=(Point_3d p) const { return\
    \ x != p.x || y != p.y || z == p.z; }\n  Point_3d operator-() const { return {-x,\
    \ -y, -z}; }\n\n  bool is_parallel(Point_3d p) const { return x * p.y == y * p.x\
    \ && y * p.z == z * p.y && z * p.x == x * p.z; }\n\n  T dot(Point_3d other) {\
    \ return x * other.x + y * other.y + z * other.z; }\n  double norm() { return\
    \ sqrt(x * x + y * y + z * z); }\n  Point_3d cross(Point_3d other) { return Point_3d(y\
    \ * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);\
    \ }\n};\n\ntemplate <typename T>\nstruct Line_3d {\n  // a + td\n  Point_3d<T>\
    \ a, d;\n\n  Line_3d(Point_3d<T> A, Point_3d<T> B) : a(A), d(B - A) { assert(d.dot(d)\
    \ != 0); }\n  bool is_parallel(Line_3d<T> other) {\n    Point_3d<T> n = d.cross(other.d);\n\
    \    return (n.x == T(0) && n.y == T(0) && n.z == T(0));\n  }\n  bool contain(Point_3d<T>\
    \ p) {\n    p = p - a;\n    p = p.cross(d);\n    return (p.x == T(0) && p.y ==\
    \ T(0) && p.z == T(0));\n  }\n};\n\ntemplate <typename T>\nstruct Plane {\n  //\
    \ ax + by + cz == d\n  T a, b, c, d;\n  Point_3d<T> normal_vec;\n\n  Plane(Point_3d<T>\
    \ A, Point_3d<T> B, Point_3d<T> C) {\n    Point_3d<T> AB = B - A;\n    Point_3d<T>\
    \ AC = C - A;\n    normal_vec = AB.cross(AC);\n    a = normal_vec.x, b = normal_vec.y,\
    \ c = normal_vec.z;\n    d = normal_vec.dot(A);\n  }\n\n  int side(Point_3d<T>\
    \ p) {\n    T x = normal_vec.dot(p) - d;\n    if (x == 0) return 0;\n    return\
    \ (x > 0 ? 1 : -1);\n  }\n\n  template <typename Re>\n  Point_3d<Re> cross_point(Line_3d<T>\
    \ L) {\n    // a + td\n    T x = normal_vec.dot(L.a);\n    T y = normal_vec.dot(L.d);\n\
    \    Re t = Re(d - x) / y;\n    Point_3d<Re> ANS;\n    ANS.x = L.a.x + t * L.d.x;\n\
    \    ANS.y = L.a.y + t * L.d.y;\n    ANS.z = L.a.z + t * L.d.z;\n    return ANS;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geo3d/base.hpp
  requiredBy:
  - geo3d/cross_point.hpp
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo3d/base.hpp
layout: document
redirect_from:
- /library/geo3d/base.hpp
- /library/geo3d/base.hpp.html
title: geo3d/base.hpp
---
