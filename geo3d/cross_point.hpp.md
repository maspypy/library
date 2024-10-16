---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo3d/base.hpp
    title: geo3d/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/5_atcoder/abc301g.test.cpp
    title: test/5_atcoder/abc301g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \ T(0) && p.z == T(0));\n  }\n};\n#line 2 \"geo3d/cross_point.hpp\"\n\n// 0: \u4EA4\
    \u70B9\u306A\u3057\n// 1: \u4E00\u610F\u306A\u4EA4\u70B9\n// 2\uFF1A2 \u3064\u4EE5\
    \u4E0A\u306E\u4EA4\u70B9\ntemplate <typename T>\nint count_cross(Line_3d<T> L1,\
    \ Line_3d<T> L2) {\n  static_assert(!std::is_floating_point<T>::value);\n  if\
    \ (L1.is_parallel(L2)) {\n    if (L1.contain(L2.a)) return 2;\n    return 0;\n\
    \  }\n  Point_3d<T> norm = L1.d.cross(L2.d);\n  return ((L1.a - L2.a).dot(norm)\
    \ == 0 ? 1 : 0);\n}\n\n// count_cross == 1 \u306E\u3068\u304D\u306B\u3060\u3051\
    \u547C\u3076\u3053\u3068\ntemplate <typename REAL, typename T>\nPoint_3d<REAL>\
    \ cross_point(Line_3d<T> L1, Line_3d<T> L2) {\n  Point_3d<T> d1 = L1.d;\n  Point_3d<T>\
    \ d2 = L2.d;\n  Point_3d<T> a = L2.a - L1.a;\n  REAL t1 = [&]() -> REAL {\n  \
    \  FOR(3) {\n      d1 = {d1.y, d1.z, d1.x};\n      d2 = {d2.y, d2.z, d2.x};\n\
    \      a = {a.y, a.z, a.x};\n      T det = d1.x * d2.y - d1.y * d2.x;\n      if\
    \ (det != 0) { return REAL(a.x * d2.y - a.y * d2.x) / REAL(det); }\n    }\n  \
    \  assert(0);\n    return 0;\n  }();\n  REAL x = REAL(L1.a.x) + t1 * REAL(L1.d.x);\n\
    \  REAL y = REAL(L1.a.y) + t1 * REAL(L1.d.y);\n  REAL z = REAL(L1.a.z) + t1 *\
    \ REAL(L1.d.z);\n  return {x, y, z};\n}\n"
  code: "#include \"geo3d/base.hpp\"\n\n// 0: \u4EA4\u70B9\u306A\u3057\n// 1: \u4E00\
    \u610F\u306A\u4EA4\u70B9\n// 2\uFF1A2 \u3064\u4EE5\u4E0A\u306E\u4EA4\u70B9\ntemplate\
    \ <typename T>\nint count_cross(Line_3d<T> L1, Line_3d<T> L2) {\n  static_assert(!std::is_floating_point<T>::value);\n\
    \  if (L1.is_parallel(L2)) {\n    if (L1.contain(L2.a)) return 2;\n    return\
    \ 0;\n  }\n  Point_3d<T> norm = L1.d.cross(L2.d);\n  return ((L1.a - L2.a).dot(norm)\
    \ == 0 ? 1 : 0);\n}\n\n// count_cross == 1 \u306E\u3068\u304D\u306B\u3060\u3051\
    \u547C\u3076\u3053\u3068\ntemplate <typename REAL, typename T>\nPoint_3d<REAL>\
    \ cross_point(Line_3d<T> L1, Line_3d<T> L2) {\n  Point_3d<T> d1 = L1.d;\n  Point_3d<T>\
    \ d2 = L2.d;\n  Point_3d<T> a = L2.a - L1.a;\n  REAL t1 = [&]() -> REAL {\n  \
    \  FOR(3) {\n      d1 = {d1.y, d1.z, d1.x};\n      d2 = {d2.y, d2.z, d2.x};\n\
    \      a = {a.y, a.z, a.x};\n      T det = d1.x * d2.y - d1.y * d2.x;\n      if\
    \ (det != 0) { return REAL(a.x * d2.y - a.y * d2.x) / REAL(det); }\n    }\n  \
    \  assert(0);\n    return 0;\n  }();\n  REAL x = REAL(L1.a.x) + t1 * REAL(L1.d.x);\n\
    \  REAL y = REAL(L1.a.y) + t1 * REAL(L1.d.y);\n  REAL z = REAL(L1.a.z) + t1 *\
    \ REAL(L1.d.z);\n  return {x, y, z};\n}\n"
  dependsOn:
  - geo3d/base.hpp
  isVerificationFile: false
  path: geo3d/cross_point.hpp
  requiredBy: []
  timestamp: '2024-10-16 22:34:39+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/5_atcoder/abc301g.test.cpp
documentation_of: geo3d/cross_point.hpp
layout: document
redirect_from:
- /library/geo3d/cross_point.hpp
- /library/geo3d/cross_point.hpp.html
title: geo3d/cross_point.hpp
---
