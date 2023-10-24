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
  bundledCode: "#line 1 \"geo3d/base.hpp\"\n\ntemplate <typename T>\nstruct Point_3d\
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
    \                    x * other.y - y * other.x);\n  }\n};\n"
  code: "\ntemplate <typename T>\nstruct Point_3d {\n  T x, y, z;\n\n  Point_3d()\
    \ = default;\n\n  template <typename A, typename B, typename C>\n  Point_3d(A\
    \ x, B y, C z) : x(x), y(y), z(z) {}\n\n  Point_3d operator+(Point_3d p) const\
    \ { return {x + p.x, y + p.y, z + p.z}; }\n  Point_3d operator-(Point_3d p) const\
    \ { return {x - p.x, y - p.y, z - p.z}; }\n  Point_3d operator*(T t) const { return\
    \ {x * t, y * t, z * t}; }\n  bool operator==(Point_3d p) const { return x ==\
    \ p.x && y == p.y && z == p.z; }\n  bool operator!=(Point_3d p) const { return\
    \ x != p.x || y != p.y || z == p.z; }\n  Point_3d operator-() const { return {-x,\
    \ -y, -z}; }\n\n  bool is_parallel(Point_3d p) const {\n    return x * p.y ==\
    \ y * p.x && y * p.z == z * p.y && z * p.x == x * p.z;\n  }\n\n  T dot(Point_3d\
    \ other) { return x * other.x + y * other.y + z * other.z; }\n  double norm()\
    \ { return sqrt(x * x + y * y + z * z); }\n  Point_3d cross(Point_3d other) {\n\
    \    return Point_3d(y * other.z - z * other.y, z * other.x - x * other.z,\n \
    \                   x * other.y - y * other.x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: geo3d/base.hpp
  requiredBy: []
  timestamp: '2023-10-24 13:35:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo3d/base.hpp
layout: document
redirect_from:
- /library/geo3d/base.hpp
- /library/geo3d/base.hpp.html
title: geo3d/base.hpp
---
