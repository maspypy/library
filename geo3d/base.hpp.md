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
  bundledCode: "#line 1 \"geo3d/base.hpp\"\n\ntemplate <typename T>\nstruct Point\
    \ {\n  T x, y, z;\n\n  Point() = default;\n\n  template <typename A, typename\
    \ B, typename C>\n  Point(A x, B y, C z) : x(x), y(y), z(z) {}\n\n  Point operator+(Point\
    \ p) const { return {x + p.x, y + p.y, z + p.z}; }\n  Point operator-(Point p)\
    \ const { return {x - p.x, y - p.y, z - p.z}; }\n  bool operator==(Point p) const\
    \ { return x == p.x && y == p.y && z == p.z; }\n  bool operator!=(Point p) const\
    \ { return x != p.x || y != p.y || z == p.z; }\n  Point operator-() const { return\
    \ {-x, -y, -z}; }\n\n  bool is_parallel(Point p) const {\n    return x * p.y ==\
    \ y * p.x && y * p.z == z * p.y && z * p.x == x * p.z;\n  }\n\n  T dot(Point other)\
    \ { return x * other.x + y * other.y + z * other.z; }\n  Point cross(Point other)\
    \ {\n    return Point(y * other.z - z * other.y, z * other.x - x * other.z,\n\
    \                 x * other.y - y * other.x);\n  }\n};\n"
  code: "\ntemplate <typename T>\nstruct Point {\n  T x, y, z;\n\n  Point() = default;\n\
    \n  template <typename A, typename B, typename C>\n  Point(A x, B y, C z) : x(x),\
    \ y(y), z(z) {}\n\n  Point operator+(Point p) const { return {x + p.x, y + p.y,\
    \ z + p.z}; }\n  Point operator-(Point p) const { return {x - p.x, y - p.y, z\
    \ - p.z}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y &&\
    \ z == p.z; }\n  bool operator!=(Point p) const { return x != p.x || y != p.y\
    \ || z == p.z; }\n  Point operator-() const { return {-x, -y, -z}; }\n\n  bool\
    \ is_parallel(Point p) const {\n    return x * p.y == y * p.x && y * p.z == z\
    \ * p.y && z * p.x == x * p.z;\n  }\n\n  T dot(Point other) { return x * other.x\
    \ + y * other.y + z * other.z; }\n  Point cross(Point other) {\n    return Point(y\
    \ * other.z - z * other.y, z * other.x - x * other.z,\n                 x * other.y\
    \ - y * other.x);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: geo3d/base.hpp
  requiredBy: []
  timestamp: '2023-06-23 23:20:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo3d/base.hpp
layout: document
redirect_from:
- /library/geo3d/base.hpp
- /library/geo3d/base.hpp.html
title: geo3d/base.hpp
---
