---
data:
  _extendedDependsOn:
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
    - https://ac.nowcoder.com/acm/contest/133876/K
  bundledCode: "#line 1 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n\
    \  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename A, typename B>\n\
    \  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  template <typename U>\n  Point(Point<U> p)\
    \ : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T> || is_integral_v<U>);\n\
    \  }\n\n  Point operator+=(const Point p) {\n    x += p.x, y += p.y;\n    return\
    \ *this;\n  }\n  Point operator-=(const Point p) {\n    x -= p.x, y -= p.y;\n\
    \    return *this;\n  }\n  Point operator+(Point p) const { return {x + p.x, y\
    \ + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n\
    \  bool operator==(Point p) const { return x == p.x && y == p.y; }\n  bool operator!=(Point\
    \ p) const { return x != p.x || y != p.y; }\n  Point operator-() const { return\
    \ {-x, -y}; }\n  Point operator*(T t) const { return {x * t, y * t}; }\n  Point\
    \ operator/(T t) const { return {x / t, y / t}; }\n\n  bool operator<(Point p)\
    \ const {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(const\
    \ Point& other) const { return x * other.x + y * other.y; }\n  T det(const Point&\
    \ other) const { return x * other.y - y * other.x; }\n\n  double norm() { return\
    \ sqrtl(x * x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point\
    \ rotate(double theta) {\n    static_assert(!is_integral<T>::value);\n    double\
    \ c = cos(theta), s = sin(theta);\n    return Point{c * x - s * y, s * x + c *\
    \ y};\n  }\n  Point rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y, -x});\
    \ }\n};\n\n#ifdef FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x),\
    \ fastio::rd(p.y);\n}\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n\
    \  fastio::wt(' ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\
    \u3080\u3068\u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070\
    \ +1\u3001\u53F3\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename\
    \ T>\nint ccw(Point<T> A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n\
    \  if (x > 0) return 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename\
    \ REAL, typename T, typename U>\nREAL dist(Point<T> A, Point<U> B) {\n  REAL dx\
    \ = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx\
    \ * dx + dy * dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T\
    \ a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A,\
    \ Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n\
    \  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n    return U(a) * P.x\
    \ + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n  T eval(U x, U y) {\n\
    \    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\
    \u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\
    \n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T, long\
    \ long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /= g, c\
    \ /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n    }\n    if (b ==\
    \ 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\n  bool is_parallel(Line\
    \ other) { return a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line\
    \ other) { return a * other.a + b * other.b == 0; }\n  bool is_same(Line other)\
    \ {\n    if (a * other.b != b * other.a) return 0;\n    if (a * other.c != c *\
    \ other.a) return 0;\n    if (b * other.c != c * other.b) return 0;\n    return\
    \ 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n  Point<T> A, B;\n\n\
    \  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T x1, T y1, T x2,\
    \ T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  bool contain(Point<T>\
    \ C) {\n    T det = (C - A).det(B - A);\n    if (det != 0) return 0;\n    return\
    \ (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_line()\
    \ { return Line(A, B); }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL>\
    \ O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n\
    \  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n\
    \  bool contain(Point<T> p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return\
    \ dx * dx + dy * dy <= r * r;\n  }\n};\n#line 2 \"geo/convex_polygon_union_area.hpp\"\
    \n\n// \u305D\u308C\u305E\u308C\u304C ccw order \u306E strict convex polygon\n\
    // O(N^2logN)\n// 6\u89D2\u5F62784\u500B: 840ms\n// https://ac.nowcoder.com/acm/contest/133876/K\n\
    template <typename Re>\nRe convex_polygon_union_area(vvc<Point<ll>> dat) {\n \
    \ using P = Point<ll>;\n  /*\n  \u7DDA\u5206\u306E\u5BC4\u4E0E\u306B\u5206\u89E3\
    \n  \u5883\u754C\u306B\u73FE\u308C\u308B\u3068\u3053\u308D\u3092\u8DB3\u3059\n\
    \n  \u5404\u8FBA\u306B\u3064\u3044\u3066\u3001\u4ED6\u306E\u591A\u89D2\u5F62\u306E\
    \u5185\u90E8\u306B\u3042\u308B\u3068\u3053\u308D\u3092\u6D88\u3059\u3068\u3044\
    \u3046\u611F\u3058\n\n  \u30BF\u30A4\u30D6\u30EC\u30A4\u30AF\u3092\u614E\u91CD\
    \u306B\u3084\u308B\n  \u540C\u3058\u8FBA\uFF1A\u5C0F\u3055\u3044\u756A\u53F7\u306E\
    \u8FBA\u3092\u512A\u5148\u3059\u308B\u3053\u3068\u306B\u3059\u308B\n  */\n\n \
    \ // strict ?\n  for (auto &X : dat) {\n    int n = len(X);\n    if (n <= 2) continue;\n\
    \    FOR(i, n) {\n      P A = X[i], B = X[(i + 1) % n], C = X[(i + 2) % n];\n\
    \      assert(ccw(A, B, C) == 1);\n    }\n  }\n\n  ll N = len(dat);\n  Re ANS\
    \ = 0.0;\n  FOR(i, N) {\n    FOR(k, len(dat[i])) {\n      P A = dat[i][k];\n \
    \     P B = dat[i][(k + 1) % len(dat[i])];\n      vc<pair<Re, Re>> ng;\n\n   \
    \   FOR(j, N) {\n        if (j == i) continue;\n        Re L = 0.0, R = 1.0;\n\
    \        FOR(kk, len(dat[j])) {\n          P C = dat[j][kk];\n          P D =\
    \ dat[j][(kk + 1) % len(dat[j])];\n\n          P norm = (D - C).rot90(true);\n\
    \          ll d = norm.dot(C);\n          // left of CD: norm v > d\n\n      \
    \    if ((A - B).det(C - D) == 0) {\n            // \u5E73\u884C\u3067\u3059\n\
    \            ll sgn = A.dot(norm) - d;\n            if (sgn > 0) {\n         \
    \     continue;\n            }\n            elif (sgn == 0) {\n              if\
    \ ((B - A).dot(D - C) < 0) {\n                // \u9006\u5411\u304D\n        \
    \        continue;\n              }\n              // \u540C\u3058\u5411\u304D\
    \n              // \u5C0F\u3055\u3044\u756A\u53F7\u304B\u3089\u304F\u308B\u90E8\
    \u5206\u3092\u6D88\u3059\n              if (j < i) {\n                Re c = Re((C\
    \ - A).dot(B - A)) / Re((B - A).dot(B - A));\n                Re d = Re((D - A).dot(B\
    \ - A)) / Re((B - A).dot(B - A));\n                chmax(L, c), chmin(R, d);\n\
    \                // [c,d)]\n              } else {\n                // \u4E00\u5207\
    \u6D88\u3055\u306A\u3044\u3088\u3046\u306B\u3059\u308B\n                L = 1.0,\
    \ R = 0.0;\n              }\n            }\n            elif (sgn < 0) {\n   \
    \           // \u5185\u90E8\u306B\u306A\u3089\u306A\u3044\n              L = 1.0,\
    \ R = 0.0;\n              break;\n            }\n            else {\n        \
    \      assert(0);\n            }\n          } else {\n            // \u5E73\u884C\
    \u3067\u306F\u306A\u3044\n            // 0 \u4EE5\u4E0A\u306B\u306A\u3063\u3066\
    \u3044\u308B\u90E8\u5206\u304C\u5207\u308A\u53D6\u3089\u308C\u308B\n         \
    \   ll a = A.dot(norm) - d;\n            ll b = B.dot(norm) - d;\n           \
    \ Re t = Re(0 - a) / Re(b - a);\n            if (a < b) {\n              chmax(L,\
    \ t);\n            }\n            elif (a > b) { chmin(R, t); }\n            else\
    \ {\n              assert(0);\n            }\n          }\n        }\n       \
    \ if (L < R) ng.eb(L, R);\n      }\n      vc<pair<Re, int>> event;\n      for\
    \ (auto &[a, b] : ng) {\n        if (a >= b) continue;\n        event.eb(a, 1);\n\
    \        event.eb(b, -1);\n      }\n\n      Re prv = 0.0;\n      int cnt = 0;\n\
    \      sort(all(event));\n      Re ans = 0.0;\n      for (auto &[x, t] : event)\
    \ {\n        Re dx = x - prv;\n        prv = x;\n        if (cnt == 0) ans +=\
    \ dx;\n        cnt += t;\n      }\n      Re dx = 1.0 - prv;\n      ans += dx;\n\
    \      ll det = A.det(B);\n      ANS += det * ans;\n    }\n  }\n  ANS /= 2;\n\
    \  return ANS;\n}\n"
  code: "#include \"geo/base.hpp\"\n\n// \u305D\u308C\u305E\u308C\u304C ccw order\
    \ \u306E strict convex polygon\n// O(N^2logN)\n// 6\u89D2\u5F62784\u500B: 840ms\n\
    // https://ac.nowcoder.com/acm/contest/133876/K\ntemplate <typename Re>\nRe convex_polygon_union_area(vvc<Point<ll>>\
    \ dat) {\n  using P = Point<ll>;\n  /*\n  \u7DDA\u5206\u306E\u5BC4\u4E0E\u306B\
    \u5206\u89E3\n  \u5883\u754C\u306B\u73FE\u308C\u308B\u3068\u3053\u308D\u3092\u8DB3\
    \u3059\n\n  \u5404\u8FBA\u306B\u3064\u3044\u3066\u3001\u4ED6\u306E\u591A\u89D2\
    \u5F62\u306E\u5185\u90E8\u306B\u3042\u308B\u3068\u3053\u308D\u3092\u6D88\u3059\
    \u3068\u3044\u3046\u611F\u3058\n\n  \u30BF\u30A4\u30D6\u30EC\u30A4\u30AF\u3092\
    \u614E\u91CD\u306B\u3084\u308B\n  \u540C\u3058\u8FBA\uFF1A\u5C0F\u3055\u3044\u756A\
    \u53F7\u306E\u8FBA\u3092\u512A\u5148\u3059\u308B\u3053\u3068\u306B\u3059\u308B\
    \n  */\n\n  // strict ?\n  for (auto &X : dat) {\n    int n = len(X);\n    if\
    \ (n <= 2) continue;\n    FOR(i, n) {\n      P A = X[i], B = X[(i + 1) % n], C\
    \ = X[(i + 2) % n];\n      assert(ccw(A, B, C) == 1);\n    }\n  }\n\n  ll N =\
    \ len(dat);\n  Re ANS = 0.0;\n  FOR(i, N) {\n    FOR(k, len(dat[i])) {\n     \
    \ P A = dat[i][k];\n      P B = dat[i][(k + 1) % len(dat[i])];\n      vc<pair<Re,\
    \ Re>> ng;\n\n      FOR(j, N) {\n        if (j == i) continue;\n        Re L =\
    \ 0.0, R = 1.0;\n        FOR(kk, len(dat[j])) {\n          P C = dat[j][kk];\n\
    \          P D = dat[j][(kk + 1) % len(dat[j])];\n\n          P norm = (D - C).rot90(true);\n\
    \          ll d = norm.dot(C);\n          // left of CD: norm v > d\n\n      \
    \    if ((A - B).det(C - D) == 0) {\n            // \u5E73\u884C\u3067\u3059\n\
    \            ll sgn = A.dot(norm) - d;\n            if (sgn > 0) {\n         \
    \     continue;\n            }\n            elif (sgn == 0) {\n              if\
    \ ((B - A).dot(D - C) < 0) {\n                // \u9006\u5411\u304D\n        \
    \        continue;\n              }\n              // \u540C\u3058\u5411\u304D\
    \n              // \u5C0F\u3055\u3044\u756A\u53F7\u304B\u3089\u304F\u308B\u90E8\
    \u5206\u3092\u6D88\u3059\n              if (j < i) {\n                Re c = Re((C\
    \ - A).dot(B - A)) / Re((B - A).dot(B - A));\n                Re d = Re((D - A).dot(B\
    \ - A)) / Re((B - A).dot(B - A));\n                chmax(L, c), chmin(R, d);\n\
    \                // [c,d)]\n              } else {\n                // \u4E00\u5207\
    \u6D88\u3055\u306A\u3044\u3088\u3046\u306B\u3059\u308B\n                L = 1.0,\
    \ R = 0.0;\n              }\n            }\n            elif (sgn < 0) {\n   \
    \           // \u5185\u90E8\u306B\u306A\u3089\u306A\u3044\n              L = 1.0,\
    \ R = 0.0;\n              break;\n            }\n            else {\n        \
    \      assert(0);\n            }\n          } else {\n            // \u5E73\u884C\
    \u3067\u306F\u306A\u3044\n            // 0 \u4EE5\u4E0A\u306B\u306A\u3063\u3066\
    \u3044\u308B\u90E8\u5206\u304C\u5207\u308A\u53D6\u3089\u308C\u308B\n         \
    \   ll a = A.dot(norm) - d;\n            ll b = B.dot(norm) - d;\n           \
    \ Re t = Re(0 - a) / Re(b - a);\n            if (a < b) {\n              chmax(L,\
    \ t);\n            }\n            elif (a > b) { chmin(R, t); }\n            else\
    \ {\n              assert(0);\n            }\n          }\n        }\n       \
    \ if (L < R) ng.eb(L, R);\n      }\n      vc<pair<Re, int>> event;\n      for\
    \ (auto &[a, b] : ng) {\n        if (a >= b) continue;\n        event.eb(a, 1);\n\
    \        event.eb(b, -1);\n      }\n\n      Re prv = 0.0;\n      int cnt = 0;\n\
    \      sort(all(event));\n      Re ans = 0.0;\n      for (auto &[x, t] : event)\
    \ {\n        Re dx = x - prv;\n        prv = x;\n        if (cnt == 0) ans +=\
    \ dx;\n        cnt += t;\n      }\n      Re dx = 1.0 - prv;\n      ans += dx;\n\
    \      ll det = A.det(B);\n      ANS += det * ans;\n    }\n  }\n  ANS /= 2;\n\
    \  return ANS;\n}"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/convex_polygon_union_area.hpp
  requiredBy: []
  timestamp: '2026-08-19 20:31:51+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/convex_polygon_union_area.hpp
layout: document
redirect_from:
- /library/geo/convex_polygon_union_area.hpp
- /library/geo/convex_polygon_union_area.hpp.html
title: geo/convex_polygon_union_area.hpp
---
