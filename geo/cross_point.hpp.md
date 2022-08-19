---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C.test.cpp
    title: test/aoj/CGL_2_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n  template <typename A, typename B>\n  Point(A x, B y) : x(x), y(y)\
    \ {}\n\n  template <typename A, typename B>\n  Point(pair<A, B> p) : x(p.fi),\
    \ y(p.se) {}\n\n  Point operator+(Point p) const { return {x + p.x, y + p.y};\
    \ }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n  bool operator==(Point\
    \ p) const { return x == p.x && y == p.y; }\n  Point operator-() const { return\
    \ {-x, -y}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x\
    \ < p.x;\n    return y < p.y;\n  }\n\n  T dot(Point other) { return x * other.x\
    \ + y * other.y; }\n  T det(Point other) { return x * other.y - y * other.x; }\n\
    };\n\ntemplate <typename REAL, typename T>\nREAL dist(Point<T> A, Point<T> B)\
    \ {\n  A -= B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n}\n\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y;\n    b = B.x - A.x;\n\
    \    c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U\
    \ x, U y) {\n    return a * x + b * y + c;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  bool is_parallel(Line other) {\n    return a * other.b - b * other.a\
    \ == 0;\n  }\n\n  template <enable_if_t<is_integral<T>::value, int> = 0>\n  bool\
    \ is_orthogonal(Line other) {\n    return a * other.a + b * other.b == 0;\n  }\n\
    };\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A, B;\n  bool open;\n\
    \n  Segment(Point<T> A, Point<T> B, bool open) : A(A), B(B), open(open) {}\n \
    \ Segment(T x1, T y1, T x2, T y2, bool open)\n      : Segment(Point<T>(x1, y1),\
    \ Point<T>(x2, y2), open) {}\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\
    #line 2 \"geo/cross_point.hpp\"\n\n// \u5E73\u884C\u3067\u306A\u3044\u3053\u3068\
    \u3092\u4EEE\u5B9A\ntemplate <typename REAL, typename T>\nPoint<REAL> cross_point(const\
    \ Line<T> L1, const Line<T> L2) {\n  T det = L1.a * L2.b - L1.b * L2.a;\n  assert(det\
    \ != 0);\n  REAL x = -REAL(L1.c) * L2.b + REAL(L1.b) * L2.c;\n  REAL y = -REAL(L1.a)\
    \ * L2.c + REAL(L1.c) * L2.a;\n  return Point<REAL>(x / det, y / det);\n}\n\n\
    // 0: \u4EA4\u70B9\u306A\u3057\n// 1: \u4E00\u610F\u306A\u4EA4\u70B9\n// 2\uFF1A\
    2 \u3064\u4EE5\u4E0A\u306E\u4EA4\u70B9\uFF08\u6574\u6570\u578B\u3092\u5229\u7528\
    \u3057\u3066\u53B3\u5BC6\u306B\u3084\u308B\uFF09\ntemplate <typename T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\nint count_cross(Segment<T> S1, Segment<T> S2) {\n  return 0;\n}\n\
    \n//\ntemplate <typename T>\nint count_cross(Segment<T> S1, Segment<T> S2) {\n\
    \  return 0;\n}\n\n// \u552F\u4E00\u306E\u4EA4\u70B9\u3092\u6301\u3064\u3053\u3068\
    \u3092\u4EEE\u5B9A\ntemplate <typename REAL, typename T>\nPoint<REAL> cross_point(const\
    \ Segment<T> S1, const Segment<T> S2) {\n  return cross_point(S1.to_Line(), S2.to_Line());\n\
    }\n"
  code: "#include \"geo/base.hpp\"\n\n// \u5E73\u884C\u3067\u306A\u3044\u3053\u3068\
    \u3092\u4EEE\u5B9A\ntemplate <typename REAL, typename T>\nPoint<REAL> cross_point(const\
    \ Line<T> L1, const Line<T> L2) {\n  T det = L1.a * L2.b - L1.b * L2.a;\n  assert(det\
    \ != 0);\n  REAL x = -REAL(L1.c) * L2.b + REAL(L1.b) * L2.c;\n  REAL y = -REAL(L1.a)\
    \ * L2.c + REAL(L1.c) * L2.a;\n  return Point<REAL>(x / det, y / det);\n}\n\n\
    // 0: \u4EA4\u70B9\u306A\u3057\n// 1: \u4E00\u610F\u306A\u4EA4\u70B9\n// 2\uFF1A\
    2 \u3064\u4EE5\u4E0A\u306E\u4EA4\u70B9\uFF08\u6574\u6570\u578B\u3092\u5229\u7528\
    \u3057\u3066\u53B3\u5BC6\u306B\u3084\u308B\uFF09\ntemplate <typename T, enable_if_t<is_integral<T>::value,\
    \ int> = 0>\nint count_cross(Segment<T> S1, Segment<T> S2) {\n  return 0;\n}\n\
    \n//\ntemplate <typename T>\nint count_cross(Segment<T> S1, Segment<T> S2) {\n\
    \  return 0;\n}\n\n// \u552F\u4E00\u306E\u4EA4\u70B9\u3092\u6301\u3064\u3053\u3068\
    \u3092\u4EEE\u5B9A\ntemplate <typename REAL, typename T>\nPoint<REAL> cross_point(const\
    \ Segment<T> S1, const Segment<T> S2) {\n  return cross_point(S1.to_Line(), S2.to_Line());\n\
    }\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/cross_point.hpp
  requiredBy: []
  timestamp: '2022-08-20 06:53:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_2_C.test.cpp
documentation_of: geo/cross_point.hpp
layout: document
redirect_from:
- /library/geo/cross_point.hpp
- /library/geo/cross_point.hpp.html
title: geo/cross_point.hpp
---
