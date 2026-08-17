---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: geo3d/base.hpp
    title: geo3d/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo3d/base.hpp\"\n\ntemplate <typename T>\nstruct Point_3D\
    \ {\n  T x, y, z;\n\n  Point_3D() = default;\n\n  template <typename A, typename\
    \ B, typename C>\n  Point_3D(A x, B y, C z) : x(x), y(y), z(z) {}\n\n  Point_3D\
    \ operator+(Point_3D p) const { return {x + p.x, y + p.y, z + p.z}; }\n  Point_3D\
    \ operator-(Point_3D p) const { return {x - p.x, y - p.y, z - p.z}; }\n  Point_3D\
    \ operator*(T t) const { return {x * t, y * t, z * t}; }\n  Point_3D operator/(T\
    \ t) const { return {x / t, y / t, z / t}; }\n  bool operator==(Point_3D p) const\
    \ { return x == p.x && y == p.y && z == p.z; }\n  bool operator!=(Point_3D p)\
    \ const { return x != p.x || y != p.y || z == p.z; }\n  Point_3D operator-() const\
    \ { return {-x, -y, -z}; }\n\n  bool is_parallel(Point_3D p) const {\n    return\
    \ x * p.y == y * p.x && y * p.z == z * p.y && z * p.x == x * p.z;\n  }\n\n  T\
    \ dot(Point_3D other) { return x * other.x + y * other.y + z * other.z; }\n  double\
    \ norm() { return sqrt(x * x + y * y + z * z); }\n  Point_3D cross(Point_3D other)\
    \ {\n    return Point_3D(y * other.z - z * other.y, z * other.x - x * other.z,\n\
    \                    x * other.y - y * other.x);\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct Line_3D {\n  // a + td\n  Point_3D<T> a, d;\n\n  Line_3D(Point_3D<T>\
    \ A, Point_3D<T> B) : a(A), d(B - A) {\n    assert(d.dot(d) != 0);\n  }\n  bool\
    \ is_parallel(Line_3D<T> other) {\n    Point_3D<T> n = d.cross(other.d);\n   \
    \ return (n.x == T(0) && n.y == T(0) && n.z == T(0));\n  }\n  bool contain(Point_3D<T>\
    \ p) {\n    p = p - a;\n    p = p.cross(d);\n    return (p.x == T(0) && p.y ==\
    \ T(0) && p.z == T(0));\n  }\n};\n\ntemplate <typename T>\nstruct Plane {\n  //\
    \ ax + by + cz == d\n  T a, b, c, d;\n  Point_3D<T> normal_vec;\n\n  Plane(Point_3D<T>\
    \ A, Point_3D<T> B, Point_3D<T> C) {\n    Point_3D<T> AB = B - A;\n    Point_3D<T>\
    \ AC = C - A;\n    normal_vec = AB.cross(AC);\n    a = normal_vec.x, b = normal_vec.y,\
    \ c = normal_vec.z;\n    d = normal_vec.dot(A);\n  }\n\n  int side(Point_3D<T>\
    \ p) {\n    T x = normal_vec.dot(p) - d;\n    if (x == 0) return 0;\n    return\
    \ (x > 0 ? 1 : -1);\n  }\n\n  template <typename Re>\n  Point_3D<Re> cross_point(Line_3D<T>\
    \ L) {\n    // a + td\n    T x = normal_vec.dot(L.a);\n    T y = normal_vec.dot(L.d);\n\
    \    Re t = Re(d - x) / y;\n    Point_3D<Re> ANS;\n    ANS.x = L.a.x + t * L.d.x;\n\
    \    ANS.y = L.a.y + t * L.d.y;\n    ANS.z = L.a.z + t * L.d.z;\n    return ANS;\n\
    \  }\n};\n#line 2 \"geo3d/cross_point.hpp\"\n\n// 0: \u4EA4\u70B9\u306A\u3057\n\
    // 1: \u4E00\u610F\u306A\u4EA4\u70B9\n// 2\uFF1A2 \u3064\u4EE5\u4E0A\u306E\u4EA4\
    \u70B9\ntemplate <typename T>\nint count_cross(Line_3D<T> L1, Line_3D<T> L2) {\n\
    \  static_assert(!std::is_floating_point<T>::value);\n  if (L1.is_parallel(L2))\
    \ {\n    if (L1.contain(L2.a)) return 2;\n    return 0;\n  }\n  Point_3D<T> norm\
    \ = L1.d.cross(L2.d);\n  return ((L1.a - L2.a).dot(norm) == 0 ? 1 : 0);\n}\n\n\
    // count_cross == 1 \u306E\u3068\u304D\u306B\u3060\u3051\u547C\u3076\u3053\u3068\
    \ntemplate <typename REAL, typename T>\nPoint_3D<REAL> cross_point(Line_3D<T>\
    \ L1, Line_3D<T> L2) {\n  Point_3D<T> d1 = L1.d;\n  Point_3D<T> d2 = L2.d;\n \
    \ Point_3D<T> a = L2.a - L1.a;\n  REAL t1 = [&]() -> REAL {\n    FOR(3) {\n  \
    \    d1 = {d1.y, d1.z, d1.x};\n      d2 = {d2.y, d2.z, d2.x};\n      a = {a.y,\
    \ a.z, a.x};\n      T det = d1.x * d2.y - d1.y * d2.x;\n      if (det != 0) {\n\
    \        return REAL(a.x * d2.y - a.y * d2.x) / REAL(det);\n      }\n    }\n \
    \   assert(0);\n    return 0;\n  }();\n  REAL x = REAL(L1.a.x) + t1 * REAL(L1.d.x);\n\
    \  REAL y = REAL(L1.a.y) + t1 * REAL(L1.d.y);\n  REAL z = REAL(L1.a.z) + t1 *\
    \ REAL(L1.d.z);\n  return {x, y, z};\n}\n"
  code: "#include \"geo3d/base.hpp\"\n\n// 0: \u4EA4\u70B9\u306A\u3057\n// 1: \u4E00\
    \u610F\u306A\u4EA4\u70B9\n// 2\uFF1A2 \u3064\u4EE5\u4E0A\u306E\u4EA4\u70B9\ntemplate\
    \ <typename T>\nint count_cross(Line_3D<T> L1, Line_3D<T> L2) {\n  static_assert(!std::is_floating_point<T>::value);\n\
    \  if (L1.is_parallel(L2)) {\n    if (L1.contain(L2.a)) return 2;\n    return\
    \ 0;\n  }\n  Point_3D<T> norm = L1.d.cross(L2.d);\n  return ((L1.a - L2.a).dot(norm)\
    \ == 0 ? 1 : 0);\n}\n\n// count_cross == 1 \u306E\u3068\u304D\u306B\u3060\u3051\
    \u547C\u3076\u3053\u3068\ntemplate <typename REAL, typename T>\nPoint_3D<REAL>\
    \ cross_point(Line_3D<T> L1, Line_3D<T> L2) {\n  Point_3D<T> d1 = L1.d;\n  Point_3D<T>\
    \ d2 = L2.d;\n  Point_3D<T> a = L2.a - L1.a;\n  REAL t1 = [&]() -> REAL {\n  \
    \  FOR(3) {\n      d1 = {d1.y, d1.z, d1.x};\n      d2 = {d2.y, d2.z, d2.x};\n\
    \      a = {a.y, a.z, a.x};\n      T det = d1.x * d2.y - d1.y * d2.x;\n      if\
    \ (det != 0) {\n        return REAL(a.x * d2.y - a.y * d2.x) / REAL(det);\n  \
    \    }\n    }\n    assert(0);\n    return 0;\n  }();\n  REAL x = REAL(L1.a.x)\
    \ + t1 * REAL(L1.d.x);\n  REAL y = REAL(L1.a.y) + t1 * REAL(L1.d.y);\n  REAL z\
    \ = REAL(L1.a.z) + t1 * REAL(L1.d.z);\n  return {x, y, z};\n}\n"
  dependsOn:
  - geo3d/base.hpp
  isVerificationFile: false
  path: geo3d/cross_point.hpp
  requiredBy: []
  timestamp: '2026-08-17 12:20:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo3d/cross_point.hpp
layout: document
redirect_from:
- /library/geo3d/cross_point.hpp
- /library/geo3d/cross_point.hpp.html
title: geo3d/cross_point.hpp
---
