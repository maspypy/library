---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/abc139/tasks/abc139_f
    - https://codeforces.com/contest/1841/problem/F
  bundledCode: "#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n\
    \  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+=(const Point p) {\n    x +=\
    \ p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const Point p) {\n\
    \    x -= p.x, y -= p.y;\n    return *this;\n  }\n  Point operator+(Point p) const\
    \ { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x\
    \ - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x == p.x && y\
    \ == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y != p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n  Point operator*(T t) const\
    \ { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x / t, y\
    \ / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return x < p.x;\n\
    \    return y < p.y;\n  }\n  T dot(const Point& other) const { return x * other.x\
    \ + y * other.y; }\n  T det(const Point& other) const { return x * other.y - y\
    \ * other.x; }\n\n  double norm() { return sqrtl(x * x + y * y); }\n  double angle()\
    \ { return atan2(y, x); }\n\n  Point rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n\
    \    double c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s\
    \ * x + c * y};\n  }\n  Point rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y,\
    \ -x}); }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n\
    \  fastio::rd(p.x), fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>&\
    \ p) {\n  fastio::wt(p.x);\n  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\
    \n// A -> B -> C \u3068\u9032\u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\
    \u308B\u306A\u3089\u3070 +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ -1\ntemplate <typename T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n \
    \ T x = (B - A).det(C - A);\n  if (x > 0) return 1;\n  if (x < 0) return -1;\n\
    \  return 0;\n}\n\ntemplate <typename REAL, typename T, typename U>\nREAL dist(Point<T>\
    \ A, Point<U> B) {\n  REAL dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y)\
    \ - REAL(B.y);\n  return sqrt(dx * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename\
    \ T>\nstruct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c)\
    \ {}\n  Line(Point<T> A, Point<T> B) { a = A.y - B.y, b = B.x - A.x, c = A.x *\
    \ B.y - A.y * B.x; }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1),\
    \ Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n  \
    \  return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n  T\
    \ eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\
    \u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\
    \u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T, int>\
    \ || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n   \
    \ if (b == 0 && a < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2) : Segment(Point<T>(x1, y1),\
    \ Point<T>(x2, y2)) {}\n\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B\
    \ - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C\
    \ - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\
    \ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle()\
    \ {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y,\
    \ REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n#line 2 \"geo/angle_sort.hpp\"\n\r\n#line 4 \"geo/angle_sort.hpp\"\
    \n\r\n// lower: -1, origin: 0, upper: 1, (-pi,pi]\r\ntemplate <typename T> int\
    \ lower_or_upper(const Point<T> &p) {\r\n  if (p.y != 0)\r\n    return (p.y >\
    \ 0 ? 1 : -1);\r\n  if (p.x > 0)\r\n    return -1;\r\n  if (p.x < 0)\r\n    return\
    \ 1;\r\n  return 0;\r\n}\r\n\r\n// L<R:-1, L==R:0, L>R:1, (-pi,pi]\r\ntemplate\
    \ <typename T> int angle_comp_3(const Point<T> &L, const Point<T> &R) {\r\n  int\
    \ a = lower_or_upper(L), b = lower_or_upper(R);\r\n  if (a != b)\r\n    return\
    \ (a < b ? -1 : +1);\r\n  T det = L.det(R);\r\n  if (det > 0)\r\n    return -1;\r\
    \n  if (det < 0)\r\n    return 1;\r\n  return 0;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\
    \u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort, (-pi,pi]\r\ntemplate <typename T>\
    \ vector<int> angle_sort(vector<Point<T>> &P) {\r\n  vc<int> I(len(P));\r\n  FOR(i,\
    \ len(P)) I[i] = i;\r\n  sort(all(I), [&](auto &L, auto &R) -> bool {\r\n    return\
    \ angle_comp_3(P[L], P[R]) == -1;\r\n  });\r\n  return I;\r\n}\r\n\r\n// \u504F\
    \u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort, (-pi,pi]\r\ntemplate\
    \ <typename T> vector<int> angle_sort(vector<pair<T, T>> &P) {\r\n  vc<Point<T>>\
    \ tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\n  return angle_sort<T>(tmp);\r\
    \n}\r\n#line 3 \"geo/max_norm_sum.hpp\"\n\n// \u30D9\u30AF\u30C8\u30EB\u306E\u5217\
    \u304C\u4E0E\u3048\u3089\u308C\u308B. \u90E8\u5206\u5217\u3092\u9078\u3093\u3067\
    \uFF0C\u548C\u306E norm \u3092\u6700\u5C0F\u5316\u3059\u308B.\n// \u7DCF\u548C\
    \u306E\u5EA7\u6A19\u306E 2 \u4E57\u548C\u304C SM \u3067\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\u6CE8\u610F\u305B\u3088\
    \uFF0E\n// https://atcoder.jp/contests/abc139/tasks/abc139_f\n// https://codeforces.com/contest/1841/problem/F\n\
    template <typename SM, typename T>\npair<SM, vc<int>> max_norm_sum(vc<Point<T>>\
    \ dat) {\n  auto I = angle_sort(dat);\n  {\n    vc<int> J;\n    for (auto&& i:\
    \ I) {\n      if (dat[i].x != 0 || dat[i].y != 0) J.eb(i);\n    }\n    swap(I,\
    \ J);\n  }\n  dat = rearrange(dat, I);\n  const int N = len(dat);\n\n  if (N ==\
    \ 0) { return {0, {}}; }\n  SM ANS = 0;\n  pair<int, int> LR = {0, 0};\n\n  int\
    \ L = 0, R = 1;\n  Point<T> c = dat[0];\n  auto eval = [&]() -> SM { return SM(c.x)\
    \ * c.x + SM(c.y) * c.y; };\n  if (chmax(ANS, eval())) LR = {L, R};\n\n  while\
    \ (L < N) {\n    Point<T>&A = dat[L], &B = dat[R % N];\n    if (R - L < N && (A.det(B)\
    \ > 0 || (A.det(B) == 0 && A.dot(B) > 0))) {\n      c = c + B;\n      R++;\n \
    \     if (chmax(ANS, eval())) LR = {L, R};\n    } else {\n      c = c - A;\n \
    \     L++;\n      if (chmax(ANS, eval())) LR = {L, R};\n    }\n  }\n  vc<int>\
    \ ids;\n  FOR(i, LR.fi, LR.se) { ids.eb(I[i % N]); }\n  return {ANS, ids};\n}\n"
  code: "#include \"geo/base.hpp\"\n#include \"geo/angle_sort.hpp\"\n\n// \u30D9\u30AF\
    \u30C8\u30EB\u306E\u5217\u304C\u4E0E\u3048\u3089\u308C\u308B. \u90E8\u5206\u5217\
    \u3092\u9078\u3093\u3067\uFF0C\u548C\u306E norm \u3092\u6700\u5C0F\u5316\u3059\
    \u308B.\n// \u7DCF\u548C\u306E\u5EA7\u6A19\u306E 2 \u4E57\u548C\u304C SM \u3067\
    \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3088\u3046\u306B\
    \u6CE8\u610F\u305B\u3088\uFF0E\n// https://atcoder.jp/contests/abc139/tasks/abc139_f\n\
    // https://codeforces.com/contest/1841/problem/F\ntemplate <typename SM, typename\
    \ T>\npair<SM, vc<int>> max_norm_sum(vc<Point<T>> dat) {\n  auto I = angle_sort(dat);\n\
    \  {\n    vc<int> J;\n    for (auto&& i: I) {\n      if (dat[i].x != 0 || dat[i].y\
    \ != 0) J.eb(i);\n    }\n    swap(I, J);\n  }\n  dat = rearrange(dat, I);\n  const\
    \ int N = len(dat);\n\n  if (N == 0) { return {0, {}}; }\n  SM ANS = 0;\n  pair<int,\
    \ int> LR = {0, 0};\n\n  int L = 0, R = 1;\n  Point<T> c = dat[0];\n  auto eval\
    \ = [&]() -> SM { return SM(c.x) * c.x + SM(c.y) * c.y; };\n  if (chmax(ANS, eval()))\
    \ LR = {L, R};\n\n  while (L < N) {\n    Point<T>&A = dat[L], &B = dat[R % N];\n\
    \    if (R - L < N && (A.det(B) > 0 || (A.det(B) == 0 && A.dot(B) > 0))) {\n \
    \     c = c + B;\n      R++;\n      if (chmax(ANS, eval())) LR = {L, R};\n   \
    \ } else {\n      c = c - A;\n      L++;\n      if (chmax(ANS, eval())) LR = {L,\
    \ R};\n    }\n  }\n  vc<int> ids;\n  FOR(i, LR.fi, LR.se) { ids.eb(I[i % N]);\
    \ }\n  return {ANS, ids};\n}\n"
  dependsOn:
  - geo/base.hpp
  - geo/angle_sort.hpp
  isVerificationFile: false
  path: geo/max_norm_sum.hpp
  requiredBy: []
  timestamp: '2025-05-18 17:51:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/max_norm_sum.hpp
layout: document
redirect_from:
- /library/geo/max_norm_sum.hpp
- /library/geo/max_norm_sum.hpp.html
title: geo/max_norm_sum.hpp
---
