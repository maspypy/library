---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    - https://atcoder.jp/contests/tupc2023/tasks/tupc2023_m
  bundledCode: "#line 2 \"geo/angle_sort.hpp\"\n\r\n#line 2 \"geo/base.hpp\"\ntemplate\
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
    \ U>\n  U eval(Point<U> P) {\n    return a * P.x + b * P.y + c;\n  }\n\n  template\
    \ <typename U>\n  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n \
    \ // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\
    \u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
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
    \ <= r * r;\n  }\n};\n#line 4 \"geo/angle_sort.hpp\"\n\r\n// lower: -1, origin:\
    \ 0, upper: 1, (-pi,pi]\r\ntemplate <typename T> int lower_or_upper(const Point<T>\
    \ &p) {\r\n  if (p.y != 0)\r\n    return (p.y > 0 ? 1 : -1);\r\n  if (p.x > 0)\r\
    \n    return -1;\r\n  if (p.x < 0)\r\n    return 1;\r\n  return 0;\r\n}\r\n\r\n\
    // L<R:-1, L==R:0, L>R:1, (-pi,pi]\r\ntemplate <typename T> int angle_comp_3(const\
    \ Point<T> &L, const Point<T> &R) {\r\n  int a = lower_or_upper(L), b = lower_or_upper(R);\r\
    \n  if (a != b)\r\n    return (a < b ? -1 : +1);\r\n  T det = L.det(R);\r\n  if\
    \ (det > 0)\r\n    return -1;\r\n  if (det < 0)\r\n    return 1;\r\n  return 0;\r\
    \n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort,\
    \ (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<Point<T>> &P)\
    \ {\r\n  vc<int> I(len(P));\r\n  FOR(i, len(P)) I[i] = i;\r\n  sort(all(I), [&](auto\
    \ &L, auto &R) -> bool {\r\n    return angle_comp_3(P[L], P[R]) == -1;\r\n  });\r\
    \n  return I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B\
    \ argsort, (-pi,pi]\r\ntemplate <typename T> vector<int> angle_sort(vector<pair<T,\
    \ T>> &P) {\r\n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\
    \n  return angle_sort<T>(tmp);\r\n}\r\n#line 2 \"geo/rotating_swaps.hpp\"\n\n\
    /*\nreturn : {init, events}\ninit: \u65B9\u5411\u30D9\u30AF\u30C8\u30EB (-1,-eps)\
    \ \u65B9\u5411\u306B\u3064\u3044\u3066\u30BD\u30FC\u30C8\u3057\u305F\u3068\u304D\
    \u306E\u9806\u5E8F\nevents: i,j \u306E\u9806\u4F4D\u304C\u5165\u308C\u66FF\u308F\
    \u308B (i<j \u304B\u3089 j<i)\u3068\u3044\u3046\u30A4\u30D9\u30F3\u30C8\u306E\u5217\
    \n360\u5EA6\u5206\u3042\u308B, \u6700\u5F8C\u306B\u306F init \u306B\u623B\u3063\
    \u3066\u304F\u308B\nhttps://atcoder.jp/contests/tupc2023/tasks/tupc2023_m\n*/\n\
    template <typename T>\npair<vc<int>, vc<pair<int, int>>> rotating_swaps(vc<Point<T>>\
    \ point) {\n  using P = Point<T>;\n  /*\n  \u89D2\u5EA6 t \u306B\u304A\u3051\u308B\
    \u30BF\u30A4\u30D6\u30EC\u30A4\u30AF\u306B\u3064\u3044\u3066\n  \u89D2\u5EA6 t-eps\
    \ \u306E\u3068\u304D\u306E\u30BD\u30FC\u30C8\u9806\u3092 p1,...,pk \u3068\u3059\
    \u308B\n  \u3053\u308C\u3089\u304C\u4E00\u6589\u306B\u30BF\u30A4\u306B\u306A\u3063\
    \u305F\u3042\u3068 reverse \u3055\u308C\u308B\u3068\u3044\u3046\u3053\u3068\u306B\
    \u306A\u308B\n  (i,j) \u3092\u30DA\u30A2\u8F9E\u66F8\u9806\u306B swap \u3059\u308C\
    \u3070\u3088\u3044\n\n  \u540C\u4E00\u5EA7\u6A19\u306E\u70B9\u306B\u3064\u3044\
    \u3066\n  \u540C\u3058\u5EA7\u6A19\u3067\u3042\u308B\u3082\u306E\u306F\u5E38\u306B\
    \u3082\u3068\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u9806\u3067\u3042\u308B\
    \u3068\u3059\u308B\n  (..i1,...,i2) (...,j1,...,j2)\n  j \u306F\u5C0F\u3055\u3044\
    \u3082\u306E, i \u306F\u5927\u304D\u3044\u3082\u306E\u3092\u512A\u5148\u3059\u308B\
    \n  */\n  for (auto &p: point) p = -p;\n  auto I = argsort(point);\n  for (auto\
    \ &p: point) p = -p;\n  point = rearrange(point, I);\n  int N = len(point);\n\
    \  vc<pair<int, int>> pairs;\n  pairs.reserve(N * (N - 1));\n\n  FOR(i, N) FOR(j,\
    \ N) {\n    if (point[i] != point[j]) pairs.eb(i, j);\n  }\n\n  sort(all(pairs),\
    \ [&](auto &L, auto &R) -> bool {\n    if (L == R) return 0;\n    auto [i1, j1]\
    \ = L;\n    auto [i2, j2] = R;\n    P p1 = (point[j1] - point[i1]).rot90(true);\n\
    \    P p2 = (point[j2] - point[i2]).rot90(true);\n    int c = angle_comp_3(p1,\
    \ p2);\n    if (c != 0) return c == -1;\n    // p1,p2 \u306F\u5E73\u884C\n   \
    \ if (point[i1].dot(p1) != point[i2].dot(p1)) { return point[i1].dot(p1) < point[i2].dot(p1);\
    \ }\n    // p1 - eps \u306E\u3068\u304D\u306E dot \u306E pair \u306E\u8F9E\u66F8\
    \u9806\u3067\u6BD4\u3079\u308B\n    P d = p1.rot90(false);\n    pair<T, T> s1\
    \ = {point[j1].dot(d), point[i1].dot(d)};\n    pair<T, T> s2 = {point[j2].dot(d),\
    \ point[i2].dot(d)};\n    if (s1 != s2) return s1 < s2;\n    // \u3053\u3053\u306B\
    \u6765\u305F\u6642\u70B9\u3067\u5EA7\u6A19\u306E\u7D44\u304C\u5B8C\u5168\u4E00\
    \u81F4\u3057\u3066\u3044\u308B\n    assert(point[i1] == point[i2] && point[j1]\
    \ == point[j2]);\n    if (i1 != i2) return i1 > i2;\n    return j1 < j2;\n  });\n\
    \  for (auto &[i, j]: pairs) { i = I[i], j = I[j]; }\n  return {I, pairs};\n}\n"
  code: "#include \"geo/angle_sort.hpp\"\n\n/*\nreturn : {init, events}\ninit: \u65B9\
    \u5411\u30D9\u30AF\u30C8\u30EB (-1,-eps) \u65B9\u5411\u306B\u3064\u3044\u3066\u30BD\
    \u30FC\u30C8\u3057\u305F\u3068\u304D\u306E\u9806\u5E8F\nevents: i,j \u306E\u9806\
    \u4F4D\u304C\u5165\u308C\u66FF\u308F\u308B (i<j \u304B\u3089 j<i)\u3068\u3044\u3046\
    \u30A4\u30D9\u30F3\u30C8\u306E\u5217\n360\u5EA6\u5206\u3042\u308B, \u6700\u5F8C\
    \u306B\u306F init \u306B\u623B\u3063\u3066\u304F\u308B\nhttps://atcoder.jp/contests/tupc2023/tasks/tupc2023_m\n\
    */\ntemplate <typename T>\npair<vc<int>, vc<pair<int, int>>> rotating_swaps(vc<Point<T>>\
    \ point) {\n  using P = Point<T>;\n  /*\n  \u89D2\u5EA6 t \u306B\u304A\u3051\u308B\
    \u30BF\u30A4\u30D6\u30EC\u30A4\u30AF\u306B\u3064\u3044\u3066\n  \u89D2\u5EA6 t-eps\
    \ \u306E\u3068\u304D\u306E\u30BD\u30FC\u30C8\u9806\u3092 p1,...,pk \u3068\u3059\
    \u308B\n  \u3053\u308C\u3089\u304C\u4E00\u6589\u306B\u30BF\u30A4\u306B\u306A\u3063\
    \u305F\u3042\u3068 reverse \u3055\u308C\u308B\u3068\u3044\u3046\u3053\u3068\u306B\
    \u306A\u308B\n  (i,j) \u3092\u30DA\u30A2\u8F9E\u66F8\u9806\u306B swap \u3059\u308C\
    \u3070\u3088\u3044\n\n  \u540C\u4E00\u5EA7\u6A19\u306E\u70B9\u306B\u3064\u3044\
    \u3066\n  \u540C\u3058\u5EA7\u6A19\u3067\u3042\u308B\u3082\u306E\u306F\u5E38\u306B\
    \u3082\u3068\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u9806\u3067\u3042\u308B\
    \u3068\u3059\u308B\n  (..i1,...,i2) (...,j1,...,j2)\n  j \u306F\u5C0F\u3055\u3044\
    \u3082\u306E, i \u306F\u5927\u304D\u3044\u3082\u306E\u3092\u512A\u5148\u3059\u308B\
    \n  */\n  for (auto &p: point) p = -p;\n  auto I = argsort(point);\n  for (auto\
    \ &p: point) p = -p;\n  point = rearrange(point, I);\n  int N = len(point);\n\
    \  vc<pair<int, int>> pairs;\n  pairs.reserve(N * (N - 1));\n\n  FOR(i, N) FOR(j,\
    \ N) {\n    if (point[i] != point[j]) pairs.eb(i, j);\n  }\n\n  sort(all(pairs),\
    \ [&](auto &L, auto &R) -> bool {\n    if (L == R) return 0;\n    auto [i1, j1]\
    \ = L;\n    auto [i2, j2] = R;\n    P p1 = (point[j1] - point[i1]).rot90(true);\n\
    \    P p2 = (point[j2] - point[i2]).rot90(true);\n    int c = angle_comp_3(p1,\
    \ p2);\n    if (c != 0) return c == -1;\n    // p1,p2 \u306F\u5E73\u884C\n   \
    \ if (point[i1].dot(p1) != point[i2].dot(p1)) { return point[i1].dot(p1) < point[i2].dot(p1);\
    \ }\n    // p1 - eps \u306E\u3068\u304D\u306E dot \u306E pair \u306E\u8F9E\u66F8\
    \u9806\u3067\u6BD4\u3079\u308B\n    P d = p1.rot90(false);\n    pair<T, T> s1\
    \ = {point[j1].dot(d), point[i1].dot(d)};\n    pair<T, T> s2 = {point[j2].dot(d),\
    \ point[i2].dot(d)};\n    if (s1 != s2) return s1 < s2;\n    // \u3053\u3053\u306B\
    \u6765\u305F\u6642\u70B9\u3067\u5EA7\u6A19\u306E\u7D44\u304C\u5B8C\u5168\u4E00\
    \u81F4\u3057\u3066\u3044\u308B\n    assert(point[i1] == point[i2] && point[j1]\
    \ == point[j2]);\n    if (i1 != i2) return i1 > i2;\n    return j1 < j2;\n  });\n\
    \  for (auto &[i, j]: pairs) { i = I[i], j = I[j]; }\n  return {I, pairs};\n}\n"
  dependsOn:
  - geo/angle_sort.hpp
  - geo/base.hpp
  isVerificationFile: false
  path: geo/rotating_swaps.hpp
  requiredBy: []
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/rotating_swaps.hpp
layout: document
redirect_from:
- /library/geo/rotating_swaps.hpp
- /library/geo/rotating_swaps.hpp.html
title: geo/rotating_swaps.hpp
---
