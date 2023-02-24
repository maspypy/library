---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/incremental_ch.test.cpp
    title: test/mytest/incremental_ch.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc266c.test.cpp
    title: test_atcoder/abc266c.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() = default;\n\n  template <typename A, typename B>\n  Point(A\
    \ x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n\n  bool operator<(Point p) const\
    \ {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(Point\
    \ other) { return x * other.x + y * other.y; }\n  T det(Point other) { return\
    \ x * other.y - y * other.x; }\n\n  void read() { fastio::read(x), fastio::read(y);\
    \ }\n  void write() { fastio::printer.write(pair<T, T>({x, y})); }\n};\n\ntemplate\
    \ <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C\
    \ - A);\n  if (x > 0) return 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate\
    \ <typename REAL, typename T>\nREAL dist(Point<T> A, Point<T> B) {\n  A = A -\
    \ B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n}\n\ntemplate <typename T>\n\
    struct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n \
    \ Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x *\
    \ B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1),\
    \ Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n  \
    \  return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x,\
    \ U y) {\n    return a * x + b * y + c;\n  }\n\n  bool is_parallel(Line other)\
    \ { return a * other.b - b * other.a == 0; }\n\n  bool is_orthogonal(Line other)\
    \ { return a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct\
    \ Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B)\
    \ {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2,\
    \ y2)) {}\n\n  template <enable_if_t<is_integral<T>::value, int> = 0>\n  bool\
    \ contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det != 0) return\
    \ 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n\
    \  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL> O, REAL r)\
    \ : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r) {}\n  template\
    \ <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x - O.x, dy = p.y\
    \ - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct Polygon {\n  vc<Point<T>> points;\n  T a;\n\n  template <typename\
    \ A, typename B>\n  Polygon(vc<pair<A, B>> pairs) {\n    for (auto&& [a, b]: pairs)\
    \ points.eb(Point<T>(a, b));\n    build();\n  }\n  Polygon(vc<Point<T>> points)\
    \ : points(points) { build(); }\n\n  int size() { return len(points); }\n\n  template\
    \ <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\n  template <enable_if_t<is_integral<T>::value,\
    \ int> = 0>\n  T area_2() {\n    return a;\n  }\n\n  bool is_convex() {\n    FOR(j,\
    \ len(points)) {\n      int i = (j == 0 ? len(points) - 1 : j - 1);\n      int\
    \ k = (j == len(points) - 1 ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k]\
    \ - points[j]) < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n\
    \  void build() {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1\
    \ == len(points) ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n\
    \    if (a < 0) {\n      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n\
    #line 2 \"geo/incremental_convexhull.hpp\"\n\n// \u4E0B\u5074\u51F8\u5305\ntemplate\
    \ <typename T, bool strict = true>\nstruct IncrementalConvexHull_Lower {\n  using\
    \ P = Point<T>;\n  set<P> S;\n\n  IncrementalConvexHull_Lower() {}\n\n  int size()\
    \ { return len(S); }\n\n  template <typename ADD_V, typename RM_V, typename ADD_E,\
    \ typename RM_E>\n  void add(Point<T> p, ADD_V add_v, RM_V rm_v, ADD_E add_e,\
    \ RM_E rm_e) {\n    int s = side(p);\n    if (strict && s >= 0) return;\n    if\
    \ (!strict && s > 0) return;\n\n    // \u70B9\u8FFD\u52A0\n    add_v(p);\n   \
    \ S.insert(p);\n\n    vc<P> left;\n    {\n      auto it = S.find(p);\n      while\
    \ (it != S.begin()) {\n        --it;\n        if (left.empty()) {\n          left.eb(*it);\n\
    \          continue;\n        }\n        auto a = *it;\n        auto b = left.back();\n\
    \        T det = (b - a).det(p - a);\n        if (strict && det > 0) break;\n\
    \        if (!strict && det >= 0) break;\n        left.eb(a);\n      }\n    }\n\
    \n    vc<P> right;\n    {\n      auto it = S.find(p);\n      while (1) {\n   \
    \     ++it;\n        if (it == S.end()) break;\n        if (right.empty()) {\n\
    \          right.eb(*it);\n          continue;\n        }\n        auto a = right.back();\n\
    \        auto b = *it;\n        T det = (a - p).det(b - p);\n        if (strict\
    \ && det > 0) break;\n        if (!strict && det >= 0) break;\n        right.eb(b);\n\
    \      }\n    }\n\n    // \u70B9\u524A\u9664\n    if (len(left) > 1) { S.erase(next(S.find(left.back())),\
    \ S.find(p)); }\n    if (len(right) > 1) { S.erase(next(S.find(p)), S.find(right.back()));\
    \ }\n    FOR(i, len(left) - 1) rm_v(left[i]);\n    FOR(i, len(right) - 1) rm_v(right[i]);\n\
    \n    // \u8FBA\u524A\u9664\n    if (len(left) && len(right)) {\n      auto a\
    \ = left[0], b = right[0];\n      rm_e(a, b);\n    }\n    FOR(i, len(left) - 1)\
    \ {\n      auto a = left[i + 1], b = left[i];\n      rm_e(a, b);\n    }\n    FOR(i,\
    \ len(right) - 1) {\n      auto a = right[i], b = right[i + 1];\n      rm_e(a,\
    \ b);\n    }\n    // \u8FBA\u8FFD\u52A0\n    if (len(left)) { add_e(left.back(),\
    \ p); }\n    if (len(right)) { add_e(p, right.back()); }\n  }\n\n  // \u4E2D\uFF1A\
    1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n  int side(Point<T> p) {\n    auto r =\
    \ S.lower_bound(p);\n    if (r == S.begin()) {\n      // \u5168\u90E8 p \u4EE5\
    \u4E0A\n      if (len(S) && (*r) == p) return 0;\n      return -1;\n    }\n  \
    \  if (r == S.end()) {\n      // p \u306F max \u3088\u308A\u5927\u304D\u3044\n\
    \      return -1;\n    }\n    auto l = prev(r);\n    auto p1 = *l, p2 = *r;\n\
    \    T det = (p - p1).det(p2 - p1);\n    if (det == 0) return 0;\n    return (det\
    \ > 0 ? -1 : 1);\n  }\n};\n\ntemplate <typename T, bool strict = true>\nstruct\
    \ Incremental_ConvexHull {\n  using P = Point<T>;\n  IncrementalConvexHull_Lower<T,\
    \ strict> LOWER, UPPER;\n  int cnt_E;\n  T det_sum;\n  bool is_empty;\n\n  Incremental_ConvexHull()\
    \ : cnt_E(0), det_sum(0), is_empty(1) {}\n\n  int size() { return cnt_E; }\n\n\
    \  bool empty() { return is_empty; }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return det_sum * 0.5;\n  }\n  T area_2() { return det_sum; }\n\n  template\
    \ <typename ADD_V, typename RM_V, typename ADD_E, typename RM_E>\n  void add(Point<T>\
    \ p, ADD_V add_v, RM_V rm_v, ADD_E add_e, RM_E rm_e) {\n    is_empty = 0;\n  \
    \  LOWER.add(\n        p, add_v, rm_v,\n        [&](Point<T> a, Point<T> b) {\n\
    \          add_e(a, b);\n          ++cnt_E;\n          det_sum += a.det(b);\n\
    \        },\n        [&](Point<T> a, Point<T> b) {\n          rm_e(a, b);\n  \
    \        --cnt_E;\n          det_sum -= a.det(b);\n        });\n    UPPER.add(\n\
    \        -p, [&](Point<T> p) { add_v(-p); }, [&](Point<T> p) { rm_v(-p); },\n\
    \        [&](Point<T> a, Point<T> b) {\n          add_e(-a, -b);\n          ++cnt_E;\n\
    \          det_sum += a.det(b);\n        },\n        [&](Point<T> a, Point<T>\
    \ b) {\n          rm_e(-a, -b);\n          --cnt_E;\n          det_sum -= a.det(b);\n\
    \        });\n  }\n  void add(Point<T> p) {\n    add(\n        p, [](Point<T>\
    \ p) {}, [](Point<T> p) {}, [](Point<T> s, Point<T> t) {},\n        [](Point<T>\
    \ s, Point<T> t) {});\n  }\n\n  // \u4E2D\uFF1A1\u3001\u5883\u754C\uFF1A0\u3001\
    \u5916\uFF1A-1\n  int side(Point<T> p) {\n    int a = LOWER.side(p);\n    int\
    \ b = UPPER.side(-p);\n    if (a == 0 || b == 0) return 0;\n    return min(a,\
    \ b);\n  }\n};\n"
  code: "#include \"geo/base.hpp\"\n\n// \u4E0B\u5074\u51F8\u5305\ntemplate <typename\
    \ T, bool strict = true>\nstruct IncrementalConvexHull_Lower {\n  using P = Point<T>;\n\
    \  set<P> S;\n\n  IncrementalConvexHull_Lower() {}\n\n  int size() { return len(S);\
    \ }\n\n  template <typename ADD_V, typename RM_V, typename ADD_E, typename RM_E>\n\
    \  void add(Point<T> p, ADD_V add_v, RM_V rm_v, ADD_E add_e, RM_E rm_e) {\n  \
    \  int s = side(p);\n    if (strict && s >= 0) return;\n    if (!strict && s >\
    \ 0) return;\n\n    // \u70B9\u8FFD\u52A0\n    add_v(p);\n    S.insert(p);\n\n\
    \    vc<P> left;\n    {\n      auto it = S.find(p);\n      while (it != S.begin())\
    \ {\n        --it;\n        if (left.empty()) {\n          left.eb(*it);\n   \
    \       continue;\n        }\n        auto a = *it;\n        auto b = left.back();\n\
    \        T det = (b - a).det(p - a);\n        if (strict && det > 0) break;\n\
    \        if (!strict && det >= 0) break;\n        left.eb(a);\n      }\n    }\n\
    \n    vc<P> right;\n    {\n      auto it = S.find(p);\n      while (1) {\n   \
    \     ++it;\n        if (it == S.end()) break;\n        if (right.empty()) {\n\
    \          right.eb(*it);\n          continue;\n        }\n        auto a = right.back();\n\
    \        auto b = *it;\n        T det = (a - p).det(b - p);\n        if (strict\
    \ && det > 0) break;\n        if (!strict && det >= 0) break;\n        right.eb(b);\n\
    \      }\n    }\n\n    // \u70B9\u524A\u9664\n    if (len(left) > 1) { S.erase(next(S.find(left.back())),\
    \ S.find(p)); }\n    if (len(right) > 1) { S.erase(next(S.find(p)), S.find(right.back()));\
    \ }\n    FOR(i, len(left) - 1) rm_v(left[i]);\n    FOR(i, len(right) - 1) rm_v(right[i]);\n\
    \n    // \u8FBA\u524A\u9664\n    if (len(left) && len(right)) {\n      auto a\
    \ = left[0], b = right[0];\n      rm_e(a, b);\n    }\n    FOR(i, len(left) - 1)\
    \ {\n      auto a = left[i + 1], b = left[i];\n      rm_e(a, b);\n    }\n    FOR(i,\
    \ len(right) - 1) {\n      auto a = right[i], b = right[i + 1];\n      rm_e(a,\
    \ b);\n    }\n    // \u8FBA\u8FFD\u52A0\n    if (len(left)) { add_e(left.back(),\
    \ p); }\n    if (len(right)) { add_e(p, right.back()); }\n  }\n\n  // \u4E2D\uFF1A\
    1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n  int side(Point<T> p) {\n    auto r =\
    \ S.lower_bound(p);\n    if (r == S.begin()) {\n      // \u5168\u90E8 p \u4EE5\
    \u4E0A\n      if (len(S) && (*r) == p) return 0;\n      return -1;\n    }\n  \
    \  if (r == S.end()) {\n      // p \u306F max \u3088\u308A\u5927\u304D\u3044\n\
    \      return -1;\n    }\n    auto l = prev(r);\n    auto p1 = *l, p2 = *r;\n\
    \    T det = (p - p1).det(p2 - p1);\n    if (det == 0) return 0;\n    return (det\
    \ > 0 ? -1 : 1);\n  }\n};\n\ntemplate <typename T, bool strict = true>\nstruct\
    \ Incremental_ConvexHull {\n  using P = Point<T>;\n  IncrementalConvexHull_Lower<T,\
    \ strict> LOWER, UPPER;\n  int cnt_E;\n  T det_sum;\n  bool is_empty;\n\n  Incremental_ConvexHull()\
    \ : cnt_E(0), det_sum(0), is_empty(1) {}\n\n  int size() { return cnt_E; }\n\n\
    \  bool empty() { return is_empty; }\n\n  template <typename REAL>\n  REAL area()\
    \ {\n    return det_sum * 0.5;\n  }\n  T area_2() { return det_sum; }\n\n  template\
    \ <typename ADD_V, typename RM_V, typename ADD_E, typename RM_E>\n  void add(Point<T>\
    \ p, ADD_V add_v, RM_V rm_v, ADD_E add_e, RM_E rm_e) {\n    is_empty = 0;\n  \
    \  LOWER.add(\n        p, add_v, rm_v,\n        [&](Point<T> a, Point<T> b) {\n\
    \          add_e(a, b);\n          ++cnt_E;\n          det_sum += a.det(b);\n\
    \        },\n        [&](Point<T> a, Point<T> b) {\n          rm_e(a, b);\n  \
    \        --cnt_E;\n          det_sum -= a.det(b);\n        });\n    UPPER.add(\n\
    \        -p, [&](Point<T> p) { add_v(-p); }, [&](Point<T> p) { rm_v(-p); },\n\
    \        [&](Point<T> a, Point<T> b) {\n          add_e(-a, -b);\n          ++cnt_E;\n\
    \          det_sum += a.det(b);\n        },\n        [&](Point<T> a, Point<T>\
    \ b) {\n          rm_e(-a, -b);\n          --cnt_E;\n          det_sum -= a.det(b);\n\
    \        });\n  }\n  void add(Point<T> p) {\n    add(\n        p, [](Point<T>\
    \ p) {}, [](Point<T> p) {}, [](Point<T> s, Point<T> t) {},\n        [](Point<T>\
    \ s, Point<T> t) {});\n  }\n\n  // \u4E2D\uFF1A1\u3001\u5883\u754C\uFF1A0\u3001\
    \u5916\uFF1A-1\n  int side(Point<T> p) {\n    int a = LOWER.side(p);\n    int\
    \ b = UPPER.side(-p);\n    if (a == 0 || b == 0) return 0;\n    return min(a,\
    \ b);\n  }\n};\n"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/incremental_convexhull.hpp
  requiredBy: []
  timestamp: '2023-02-18 09:57:30+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc266c.test.cpp
  - test/mytest/incremental_ch.test.cpp
documentation_of: geo/incremental_convexhull.hpp
layout: document
redirect_from:
- /library/geo/incremental_convexhull.hpp
- /library/geo/incremental_convexhull.hpp.html
title: geo/incremental_convexhull.hpp
---
