---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: geo/minkowski_sum.hpp
    title: geo/minkowski_sum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/convex_polygon_side.test.cpp
    title: test/1_mytest/convex_polygon_side.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/convex_polygon_visible_range.test.cpp
    title: test/1_mytest/convex_polygon_visible_range.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/max_dot.test.cpp
    title: test/1_mytest/max_dot.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1906/problem/D
    - https://codeforces.com/contest/799/problem/G
  bundledCode: "#line 2 \"geo/convex_polygon.hpp\"\n\n#line 2 \"geo/base.hpp\"\ntemplate\
    \ <typename T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template\
    \ <typename A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename\
    \ A, typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+=(const\
    \ Point p) {\n    x += p.x, y += p.y;\n    return *this;\n  }\n  Point operator-=(const\
    \ Point p) {\n    x -= p.x, y -= p.y;\n    return *this;\n  }\n  Point operator+(Point\
    \ p) const { return {x + p.x, y + p.y}; }\n  Point operator-(Point p) const {\
    \ return {x - p.x, y - p.y}; }\n  bool operator==(Point p) const { return x ==\
    \ p.x && y == p.y; }\n  bool operator!=(Point p) const { return x != p.x || y\
    \ != p.y; }\n  Point operator-() const { return {-x, -y}; }\n  Point operator*(T\
    \ t) const { return {x * t, y * t}; }\n  Point operator/(T t) const { return {x\
    \ / t, y / t}; }\n\n  bool operator<(Point p) const {\n    if (x != p.x) return\
    \ x < p.x;\n    return y < p.y;\n  }\n  T dot(const Point& other) const { return\
    \ x * other.x + y * other.y; }\n  T det(const Point& other) const { return x *\
    \ other.y - y * other.x; }\n\n  double norm() { return sqrtl(x * x + y * y); }\n\
    \  double angle() { return atan2(y, x); }\n\n  Point rotate(double theta) {\n\
    \    static_assert(!is_integral<T>::value);\n    double c = cos(theta), s = sin(theta);\n\
    \    return Point{c * x - s * y, s * x + c * y};\n  }\n  Point rot90(bool ccw)\
    \ { return (ccw ? Point{-y, x} : Point{y, -x}); }\n};\n\n#ifdef FASTIO\ntemplate\
    \ <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n\
    }\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n  fastio::wt('\
    \ ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\u3080\u3068\
    \u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 +1\u3001\u53F3\
    \u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename T>\nint ccw(Point<T>\
    \ A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n  if (x > 0) return\
    \ 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename REAL, typename\
    \ T, typename U>\nREAL dist(Point<T> A, Point<U> B) {\n  REAL dx = REAL(A.x) -\
    \ REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx * dx + dy *\
    \ dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n\
    \  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\
    \ a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x; }\n  Line(T x1, T y1,\
    \ T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template <typename\
    \ U>\n  U eval(Point<U> P) {\n    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\
    \n  template <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n\
    \  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\
    \u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
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
    \ <= r * r;\n  }\n};\n#line 2 \"geo/convex_hull.hpp\"\n\n#line 4 \"geo/convex_hull.hpp\"\
    \n\n// allow_180=true \u3067\u540C\u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\
    \u3053\u308F\u308C\u308B\n// full \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\
    \u306A\u308B\ntemplate <typename T, bool allow_180 = false>\nvector<int> ConvexHull(vector<Point<T>>&\
    \ XY, string mode = \"full\", bool sorted = false) {\n  assert(mode == \"full\"\
    \ || mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N ==\
    \ 1) return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1]) return {0, 1};\n   \
    \ if (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n  vc<int> I(N);\n \
    \ if (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I = argsort(XY);\n \
    \ }\n  if constexpr (allow_180) { FOR(i, N - 1) assert(XY[i] != XY[i + 1]); }\n\
    \n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k]\
    \ - XY[i]);\n    if constexpr (allow_180) return det >= 0;\n    return det > T(0);\n\
    \  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k: I) {\n\
    \      while (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto\
    \ j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n\
    \      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode\
    \ == \"full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >=\
    \ 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n  return P;\n}\n#line 5 \"geo/convex_polygon.hpp\"\
    \n\n// n=2 \u306F\u73FE\u72B6\u30B5\u30DD\u30FC\u30C8\u3057\u3066\u3044\u306A\u3044\
    \ntemplate <typename T>\nstruct ConvexPolygon {\n  using P = Point<T>;\n  int\
    \ n;\n  vc<P> point;\n  T area2;\n\n  ConvexPolygon(vc<P> point_) : n(len(point_)),\
    \ point(point_) {\n    assert(n >= 3);\n    area2 = 0;\n    FOR(i, n) {\n    \
    \  int j = nxt_idx(i), k = nxt_idx(j);\n      assert((point[j] - point[i]).det(point[k]\
    \ - point[i]) >= 0);\n      area2 += point[i].det(point[j]);\n    }\n  }\n\n \
    \ // \u6BD4\u8F03\u95A2\u6570 comp(i,j)\n  template <typename F>\n  int periodic_min_comp(F\
    \ comp) {\n    int L = 0, M = n, R = n + n;\n    while (1) {\n      if (R - L\
    \ == 2) break;\n      int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;\n      if (comp(L1\
    \ % n, M % n)) { R = M, M = L1; }\n      elif (comp(R1 % n, M % n)) { L = M, M\
    \ = R1; }\n      else {\n        L = L1, R = R1;\n      }\n    }\n    return M\
    \ % n;\n  }\n\n  int nxt_idx(int i) { return (i + 1 == n ? 0 : i + 1); }\n  int\
    \ prev_idx(int i) { return (i == 0 ? n - 1 : i - 1); }\n\n  // \u4E2D\uFF1A1,\
    \ \u5883\u754C\uFF1A0, \u5916\uFF1A-1. test \u3057\u305F.\n  int side(P p) {\n\
    \    int L = 1, R = n - 1;\n    T a = (point[L] - point[0]).det(p - point[0]);\n\
    \    T b = (point[R] - point[0]).det(p - point[0]);\n    if (a < 0 || b > 0) return\
    \ -1;\n    // p \u306F 0 \u304B\u3089\u898B\u3066 [L,R] \u65B9\u5411\n    while\
    \ (R - L >= 2) {\n      int M = (L + R) / 2;\n      T c = (point[M] - point[0]).det(p\
    \ - point[0]);\n      if (c < 0)\n        R = M, b = c;\n      else\n        L\
    \ = M, a = c;\n    }\n    T c = (point[R] - point[L]).det(p - point[L]);\n   \
    \ T x = min({a, -b, c});\n    if (x < 0) return -1;\n    if (x > 0) return 1;\n\
    \    // on triangle p[0]p[L]p[R]\n    if (p == point[0]) return 0;\n    if (c\
    \ != 0 && a == 0 && L != 1) return 1;\n    if (c != 0 && b == 0 && R != n - 1)\
    \ return 1;\n    return 0;\n  }\n\n  // return {min, idx}. test \u3057\u305F.\n\
    \  pair<T, int> min_dot(P p) {\n    int idx = periodic_min_comp([&](int i, int\
    \ j) -> bool { return point[i].dot(p) < point[j].dot(p); });\n    return {point[idx].dot(p),\
    \ idx};\n  }\n\n  // return {max, idx}. test \u3057\u305F.\n  pair<T, int> max_dot(P\
    \ p) {\n    int idx = periodic_min_comp([&](int i, int j) -> bool { return point[i].dot(p)\
    \ > point[j].dot(p); });\n    return {point[idx].dot(p), idx};\n  }\n\n  // p\
    \ \u304B\u3089\u898B\u3048\u308B\u7BC4\u56F2. p \u8FBA\u306B\u6CBF\u3063\u3066\
    \u898B\u3048\u308B\u3068\u3053\u308D\u3082\u898B\u3048\u308B\u3068\u3059\u308B\
    . test \u3057\u305F.\n  // \u591A\u89D2\u5F62\u304B\u3089\u306E\u53CD\u6642\u8A08\
    \u9806\u306F [l,r] \u3060\u304C p \u304B\u3089\u898B\u305F\u504F\u89D2\u9806\u306F\
    \ [r,l] \u306A\u306E\u3067\u6CE8\u610F\n  pair<int, int> visible_range(P p) {\n\
    \    int a = periodic_min_comp([&](int i, int j) -> bool { return ((point[i] -\
    \ p).det(point[j] - p) < 0); });\n    int b = periodic_min_comp([&](int i, int\
    \ j) -> bool { return ((point[i] - p).det(point[j] - p) > 0); });\n    if ((p\
    \ - point[a]).det(p - point[prev_idx(a)]) == T(0)) a = prev_idx(a);\n    if ((p\
    \ - point[b]).det(p - point[nxt_idx(b)]) == T(0)) b = nxt_idx(b);\n    return\
    \ {a, b};\n  }\n\n  // \u7DDA\u5206\u304C\u300C\u5185\u90E8\u3068\u300D\u4EA4\u308F\
    \u308B\u304B\n  // https://codeforces.com/contest/1906/problem/D\n  bool check_cross(P\
    \ A, P B) {\n    FOR(2) {\n      swap(A, B);\n      auto [a, b] = visible_range(A);\n\
    \      if ((point[a] - A).det(B - A) >= 0) return 0;\n      if ((point[b] - A).det(B\
    \ - A) <= 0) return 0;\n    }\n    return 1;\n  }\n\n  vc<T> AREA;\n\n  // point[i,...,j]\
    \ (inclusive) \u306E\u9762\u7A4D\u306E 2 \u500D\n  T area_between(int i, int j)\
    \ {\n    assert(i <= j && j <= i + n);\n    if (j == i + n) return area2;\n  \
    \  i %= n, j %= n;\n    if (i > j) j += n;\n    if (AREA.empty()) build_AREA();\n\
    \    return AREA[j] - AREA[i] + (point[j % n].det(point[i]));\n  }\n\n  void build_AREA()\
    \ {\n    AREA.resize(2 * n);\n    FOR(i, n) AREA[n + i] = AREA[i] = point[i].det(point[nxt_idx(i)]);\n\
    \    AREA = cumsum<T>(AREA);\n  }\n\n  // \u76F4\u7DDA\u306E\u5DE6\u5074\u306E\
    \u9762\u7A4D. strict \u306B 2 \u56DE\u4EA4\u308F\u308B\u3053\u3068\u3092\u4EEE\
    \u5B9A.\n  // https://codeforces.com/contest/799/problem/G\n  T left_area(Line<T>\
    \ L) {\n    static_assert(is_same<T, double>::value || is_same<T, long double>::value);\n\
    \    Point<T> normal(L.a, L.b);\n    int a = min_dot(normal).se;\n    int b =\
    \ max_dot(normal).se;\n    if (b < a) b += n;\n    assert(L.eval(point[a % n])\
    \ < 0 && L.eval(point[b % n]) > 0);\n    int p = binary_search([&](int i) -> bool\
    \ { return L.eval(point[i % n]) < 0; }, a, b);\n    int q = binary_search([&](int\
    \ i) -> bool { return L.eval(point[i % n]) > 0; }, b, a + n);\n    T s, t;\n \
    \   {\n      T x = L.eval(point[p % n]);\n      T y = L.eval(point[(p + 1) % n]);\n\
    \      s = x / (x - y);\n    }\n    {\n      T x = L.eval(point[q % n]);\n   \
    \   T y = L.eval(point[(q + 1) % n]);\n      t = x / (x - y);\n    }\n    P A(point[p\
    \ % n]), B(point[(p + 1) % n]);\n    P C(point[q % n]), D(point[(q + 1) % n]);\n\
    \    P X = B * s + A * (1 - s);\n    P Y = D * t + C * (1 - t);\n    T ANS = area_between(p,\
    \ q);\n    ANS -= (A - C).det(X - C);\n    ANS += (Y - C).det(X - C);\n    return\
    \ ANS;\n  }\n};\n"
  code: "#pragma once\n\n#include \"geo/base.hpp\"\n#include \"geo/convex_hull.hpp\"\
    \n\n// n=2 \u306F\u73FE\u72B6\u30B5\u30DD\u30FC\u30C8\u3057\u3066\u3044\u306A\u3044\
    \ntemplate <typename T>\nstruct ConvexPolygon {\n  using P = Point<T>;\n  int\
    \ n;\n  vc<P> point;\n  T area2;\n\n  ConvexPolygon(vc<P> point_) : n(len(point_)),\
    \ point(point_) {\n    assert(n >= 3);\n    area2 = 0;\n    FOR(i, n) {\n    \
    \  int j = nxt_idx(i), k = nxt_idx(j);\n      assert((point[j] - point[i]).det(point[k]\
    \ - point[i]) >= 0);\n      area2 += point[i].det(point[j]);\n    }\n  }\n\n \
    \ // \u6BD4\u8F03\u95A2\u6570 comp(i,j)\n  template <typename F>\n  int periodic_min_comp(F\
    \ comp) {\n    int L = 0, M = n, R = n + n;\n    while (1) {\n      if (R - L\
    \ == 2) break;\n      int L1 = (L + M) / 2, R1 = (M + R + 1) / 2;\n      if (comp(L1\
    \ % n, M % n)) { R = M, M = L1; }\n      elif (comp(R1 % n, M % n)) { L = M, M\
    \ = R1; }\n      else {\n        L = L1, R = R1;\n      }\n    }\n    return M\
    \ % n;\n  }\n\n  int nxt_idx(int i) { return (i + 1 == n ? 0 : i + 1); }\n  int\
    \ prev_idx(int i) { return (i == 0 ? n - 1 : i - 1); }\n\n  // \u4E2D\uFF1A1,\
    \ \u5883\u754C\uFF1A0, \u5916\uFF1A-1. test \u3057\u305F.\n  int side(P p) {\n\
    \    int L = 1, R = n - 1;\n    T a = (point[L] - point[0]).det(p - point[0]);\n\
    \    T b = (point[R] - point[0]).det(p - point[0]);\n    if (a < 0 || b > 0) return\
    \ -1;\n    // p \u306F 0 \u304B\u3089\u898B\u3066 [L,R] \u65B9\u5411\n    while\
    \ (R - L >= 2) {\n      int M = (L + R) / 2;\n      T c = (point[M] - point[0]).det(p\
    \ - point[0]);\n      if (c < 0)\n        R = M, b = c;\n      else\n        L\
    \ = M, a = c;\n    }\n    T c = (point[R] - point[L]).det(p - point[L]);\n   \
    \ T x = min({a, -b, c});\n    if (x < 0) return -1;\n    if (x > 0) return 1;\n\
    \    // on triangle p[0]p[L]p[R]\n    if (p == point[0]) return 0;\n    if (c\
    \ != 0 && a == 0 && L != 1) return 1;\n    if (c != 0 && b == 0 && R != n - 1)\
    \ return 1;\n    return 0;\n  }\n\n  // return {min, idx}. test \u3057\u305F.\n\
    \  pair<T, int> min_dot(P p) {\n    int idx = periodic_min_comp([&](int i, int\
    \ j) -> bool { return point[i].dot(p) < point[j].dot(p); });\n    return {point[idx].dot(p),\
    \ idx};\n  }\n\n  // return {max, idx}. test \u3057\u305F.\n  pair<T, int> max_dot(P\
    \ p) {\n    int idx = periodic_min_comp([&](int i, int j) -> bool { return point[i].dot(p)\
    \ > point[j].dot(p); });\n    return {point[idx].dot(p), idx};\n  }\n\n  // p\
    \ \u304B\u3089\u898B\u3048\u308B\u7BC4\u56F2. p \u8FBA\u306B\u6CBF\u3063\u3066\
    \u898B\u3048\u308B\u3068\u3053\u308D\u3082\u898B\u3048\u308B\u3068\u3059\u308B\
    . test \u3057\u305F.\n  // \u591A\u89D2\u5F62\u304B\u3089\u306E\u53CD\u6642\u8A08\
    \u9806\u306F [l,r] \u3060\u304C p \u304B\u3089\u898B\u305F\u504F\u89D2\u9806\u306F\
    \ [r,l] \u306A\u306E\u3067\u6CE8\u610F\n  pair<int, int> visible_range(P p) {\n\
    \    int a = periodic_min_comp([&](int i, int j) -> bool { return ((point[i] -\
    \ p).det(point[j] - p) < 0); });\n    int b = periodic_min_comp([&](int i, int\
    \ j) -> bool { return ((point[i] - p).det(point[j] - p) > 0); });\n    if ((p\
    \ - point[a]).det(p - point[prev_idx(a)]) == T(0)) a = prev_idx(a);\n    if ((p\
    \ - point[b]).det(p - point[nxt_idx(b)]) == T(0)) b = nxt_idx(b);\n    return\
    \ {a, b};\n  }\n\n  // \u7DDA\u5206\u304C\u300C\u5185\u90E8\u3068\u300D\u4EA4\u308F\
    \u308B\u304B\n  // https://codeforces.com/contest/1906/problem/D\n  bool check_cross(P\
    \ A, P B) {\n    FOR(2) {\n      swap(A, B);\n      auto [a, b] = visible_range(A);\n\
    \      if ((point[a] - A).det(B - A) >= 0) return 0;\n      if ((point[b] - A).det(B\
    \ - A) <= 0) return 0;\n    }\n    return 1;\n  }\n\n  vc<T> AREA;\n\n  // point[i,...,j]\
    \ (inclusive) \u306E\u9762\u7A4D\u306E 2 \u500D\n  T area_between(int i, int j)\
    \ {\n    assert(i <= j && j <= i + n);\n    if (j == i + n) return area2;\n  \
    \  i %= n, j %= n;\n    if (i > j) j += n;\n    if (AREA.empty()) build_AREA();\n\
    \    return AREA[j] - AREA[i] + (point[j % n].det(point[i]));\n  }\n\n  void build_AREA()\
    \ {\n    AREA.resize(2 * n);\n    FOR(i, n) AREA[n + i] = AREA[i] = point[i].det(point[nxt_idx(i)]);\n\
    \    AREA = cumsum<T>(AREA);\n  }\n\n  // \u76F4\u7DDA\u306E\u5DE6\u5074\u306E\
    \u9762\u7A4D. strict \u306B 2 \u56DE\u4EA4\u308F\u308B\u3053\u3068\u3092\u4EEE\
    \u5B9A.\n  // https://codeforces.com/contest/799/problem/G\n  T left_area(Line<T>\
    \ L) {\n    static_assert(is_same<T, double>::value || is_same<T, long double>::value);\n\
    \    Point<T> normal(L.a, L.b);\n    int a = min_dot(normal).se;\n    int b =\
    \ max_dot(normal).se;\n    if (b < a) b += n;\n    assert(L.eval(point[a % n])\
    \ < 0 && L.eval(point[b % n]) > 0);\n    int p = binary_search([&](int i) -> bool\
    \ { return L.eval(point[i % n]) < 0; }, a, b);\n    int q = binary_search([&](int\
    \ i) -> bool { return L.eval(point[i % n]) > 0; }, b, a + n);\n    T s, t;\n \
    \   {\n      T x = L.eval(point[p % n]);\n      T y = L.eval(point[(p + 1) % n]);\n\
    \      s = x / (x - y);\n    }\n    {\n      T x = L.eval(point[q % n]);\n   \
    \   T y = L.eval(point[(q + 1) % n]);\n      t = x / (x - y);\n    }\n    P A(point[p\
    \ % n]), B(point[(p + 1) % n]);\n    P C(point[q % n]), D(point[(q + 1) % n]);\n\
    \    P X = B * s + A * (1 - s);\n    P Y = D * t + C * (1 - t);\n    T ANS = area_between(p,\
    \ q);\n    ANS -= (A - C).det(X - C);\n    ANS += (Y - C).det(X - C);\n    return\
    \ ANS;\n  }\n};"
  dependsOn:
  - geo/base.hpp
  - geo/convex_hull.hpp
  isVerificationFile: false
  path: geo/convex_polygon.hpp
  requiredBy:
  - geo/minkowski_sum.hpp
  timestamp: '2025-05-18 17:51:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/convex_polygon_visible_range.test.cpp
  - test/1_mytest/max_dot.test.cpp
  - test/1_mytest/convex_polygon_side.test.cpp
documentation_of: geo/convex_polygon.hpp
layout: document
redirect_from:
- /library/geo/convex_polygon.hpp
- /library/geo/convex_polygon.hpp.html
title: geo/convex_polygon.hpp
---
