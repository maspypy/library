---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree.hpp
    title: ds/fenwicktree/fenwicktree.hpp
  - icon: ':question:'
    path: ds/fenwicktree/fenwicktree_01.hpp
    title: ds/fenwicktree/fenwicktree_01.hpp
  - icon: ':question:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':question:'
    path: geo/count_points_in_triangles.hpp
    title: geo/count_points_in_triangles.hpp
  - icon: ':x:'
    path: geo/cross_point.hpp
    title: geo/cross_point.hpp
  - icon: ':question:'
    path: other/bit.hpp
    title: other/bit.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/polygon_triangulation.test.cpp
    title: test/1_mytest/polygon_triangulation.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"random/random_polygon.hpp\"\n\n#line 1 \"random/base.hpp\"\
    \n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"geo/base.hpp\"\ntemplate <typename\
    \ T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename\
    \ A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A,\
    \ typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  template <typename\
    \ U>\n  Point(Point<U> p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T>\
    \ || is_integral_v<U>);\n  }\n\n  Point operator+=(const Point p) {\n    x +=\
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
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n\
    \  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\
    \u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\
    \u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n\
    \    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\
    \n  bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }\n\
    \  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }\n\
    \  bool is_same(Line other) {\n    if (a * other.b != b * other.a) return 0;\n\
    \    if (a * other.c != c * other.a) return 0;\n    if (b * other.c != c * other.b)\
    \ return 0;\n    return 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n\
    \  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T\
    \ x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det !=\
    \ 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n\
    \  }\n\n  Line<T> to_line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 1 \"geo/convex_hull.hpp\"\n\n#line 1 \"geo/base.hpp\"\ntemplate <typename T>\n\
    struct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename\
    \ A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A,\
    \ typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  template <typename\
    \ U>\n  Point(Point<U> p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T>\
    \ || is_integral_v<U>);\n  }\n\n  Point operator+=(const Point p) {\n    x +=\
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
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n\
    \  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\
    \u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\
    \u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n\
    \    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\
    \n  bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }\n\
    \  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }\n\
    \  bool is_same(Line other) {\n    if (a * other.b != b * other.a) return 0;\n\
    \    if (a * other.c != c * other.a) return 0;\n    if (b * other.c != c * other.b)\
    \ return 0;\n    return 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n\
    \  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T\
    \ x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det !=\
    \ 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n\
    \  }\n\n  Line<T> to_line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 3 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\u540C\u4E00\u5EA7\u6A19\
    \u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\n// full \u306A\u3089 I[0]\
    \ \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate <typename T, bool allow_180\
    \ = false>\nvector<int> convex_hull(vector<Point<T>>& XY, string mode = \"full\"\
    ,\n                        bool sorted = false) {\n  assert(mode == \"full\" ||\
    \ mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N == 1)\
    \ return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1]) return {0, 1};\n    if\
    \ (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n  vc<int> I(N);\n  if\
    \ (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I = argsort(XY);\n  }\n\
    \  if constexpr (allow_180) {\n    FOR(i, N - 1) assert(XY[i] != XY[i + 1]);\n\
    \  }\n\n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k]\
    \ - XY[i]);\n    if constexpr (allow_180) return det >= 0;\n    return det > T(0);\n\
    \  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k : I) {\n\
    \      while (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto\
    \ j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n\
    \      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode\
    \ == \"full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >=\
    \ 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n  return P;\n}\n#line 1 \"geo/base.hpp\"\
    \ntemplate <typename T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\
    \n  template <typename A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n \
    \ template <typename A, typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se)\
    \ {}\n\n  template <typename U>\n  Point(Point<U> p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T>\
    \ || is_integral_v<U>);\n  }\n\n  Point operator+=(const Point p) {\n    x +=\
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
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n\
    \  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\
    \u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\
    \u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n\
    \    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\
    \n  bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }\n\
    \  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }\n\
    \  bool is_same(Line other) {\n    if (a * other.b != b * other.a) return 0;\n\
    \    if (a * other.c != c * other.a) return 0;\n    if (b * other.c != c * other.b)\
    \ return 0;\n    return 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n\
    \  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T\
    \ x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det !=\
    \ 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n\
    \  }\n\n  Line<T> to_line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 1 \"geo/convex_hull.hpp\"\n\n#line 1 \"geo/base.hpp\"\ntemplate <typename T>\n\
    struct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename\
    \ A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A,\
    \ typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  template <typename\
    \ U>\n  Point(Point<U> p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T>\
    \ || is_integral_v<U>);\n  }\n\n  Point operator+=(const Point p) {\n    x +=\
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
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n\
    \  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\
    \u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\
    \u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n\
    \    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\
    \n  bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }\n\
    \  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }\n\
    \  bool is_same(Line other) {\n    if (a * other.b != b * other.a) return 0;\n\
    \    if (a * other.c != c * other.a) return 0;\n    if (b * other.c != c * other.b)\
    \ return 0;\n    return 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n\
    \  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T\
    \ x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det !=\
    \ 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n\
    \  }\n\n  Line<T> to_line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 3 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\u540C\u4E00\u5EA7\u6A19\
    \u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\n// full \u306A\u3089 I[0]\
    \ \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate <typename T, bool allow_180\
    \ = false>\nvector<int> convex_hull(vector<Point<T>>& XY, string mode = \"full\"\
    ,\n                        bool sorted = false) {\n  assert(mode == \"full\" ||\
    \ mode == \"lower\" || mode == \"upper\");\n  ll N = XY.size();\n  if (N == 1)\
    \ return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1]) return {0, 1};\n    if\
    \ (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n  vc<int> I(N);\n  if\
    \ (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I = argsort(XY);\n  }\n\
    \  if constexpr (allow_180) {\n    FOR(i, N - 1) assert(XY[i] != XY[i + 1]);\n\
    \  }\n\n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k]\
    \ - XY[i]);\n    if constexpr (allow_180) return det >= 0;\n    return det > T(0);\n\
    \  };\n\n  auto calc = [&]() {\n    vector<int> P;\n    for (auto&& k : I) {\n\
    \      while (P.size() > 1) {\n        auto i = P[P.size() - 2];\n        auto\
    \ j = P[P.size() - 1];\n        if (check(i, j, k)) break;\n        P.pop_back();\n\
    \      }\n      P.eb(k);\n    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode\
    \ == \"full\" || mode == \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty())\
    \ P.pop_back();\n    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(),\
    \ all(Q));\n  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >=\
    \ 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n  return P;\n}\n#line 3 \"geo/cross_point.hpp\"\
    \n\n// strict: n>=3 \u306E\u53CD\u6642\u8A08\u56DE\u308A\u72ED\u7FA9\u51F8\u591A\
    \u89D2\u5F62\n// non-strict: n=1 \u306E\u70B9, n=2 \u306E\u7DDA\u5206, n>=3 \u306E\
    \u53CD\u6642\u8A08\u56DE\u308A\u51F8\u591A\u89D2\u5F62\ntemplate <typename T,\
    \ bool is_strict = true>\nstruct Convex_Polygon {\n  using P = Point<T>;\n  int\
    \ n;\n  vc<P> point;\n  T area2;\n\n  Convex_Polygon(vc<P> point_) : n(len(point_)),\
    \ point(point_) {\n    assert(n >= 1);\n    if constexpr (is_strict) assert(n\
    \ >= 3);\n    area2 = 0;\n    FOR(i, n) {\n      int j = nxt_idx(i);\n      if\
    \ (n >= 2) assert(point[i] != point[j]);\n      area2 += point[i].det(point[j]);\n\
    \    }\n    assert(area2 >= T(0));\n    if (n >= 3) assert(area2 > T(0));\n  \
    \  if (n >= 3) FOR(i, n) {\n        int j = nxt_idx(i), k = nxt_idx(j);\n    \
    \    T det = (point[j] - point[i]).det(point[k] - point[i]);\n        if constexpr\
    \ (is_strict)\n          assert(det > T(0));\n        else\n          assert(det\
    \ >= T(0));\n      }\n  }\n\n  template <typename F>\n  int periodic_min_comp(F\
    \ comp) const {\n    static_assert(is_strict);\n    int L = 0, M = n, R = n +\
    \ n;\n    while (R - L != 2) {\n      int L1 = (L + M) / 2, R1 = (M + R + 1) /\
    \ 2;\n      if (comp(L1 % n, M % n)) R = M, M = L1;\n      elif (comp(R1 % n,\
    \ M % n)) L = M, M = R1;\n      else L = L1, R = R1;\n    }\n    return M % n;\n\
    \  }\n\n  int nxt_idx(int i) const { return (i + 1 == n ? 0 : i + 1); }\n  int\
    \ prev_idx(int i) const { return (i == 0 ? n - 1 : i - 1); }\n\n  // \u4E2D\uFF1A\
    1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1.\n  int side(P p) const {\n    if (n ==\
    \ 1) return (p == point[0] ? 0 : -1);\n    if (n == 2) {\n      P A = point[0],\
    \ B = point[1];\n      if ((B - A).det(p - A) == 0 && (B - A).dot(p - A) >= 0\
    \ &&\n          (A - B).dot(p - B) >= 0)\n        return 0;\n      return -1;\n\
    \    }\n    int L = 1, R = n - 1;\n    T a = (point[L] - point[0]).det(p - point[0]);\n\
    \    T b = (point[R] - point[0]).det(p - point[0]);\n    if (a < 0 || b > 0) return\
    \ -1;\n    while (R - L >= 2) {\n      int M = (L + R) / 2;\n      T c = (point[M]\
    \ - point[0]).det(p - point[0]);\n      if (c < 0)\n        R = M, b = c;\n  \
    \    else\n        L = M, a = c;\n    }\n    T c = (point[R] - point[L]).det(p\
    \ - point[L]);\n    T x = min({a, -b, c});\n    if (x < 0) return -1;\n    if\
    \ (x > 0) return 1;\n    if (p == point[0]) return 0;\n    if (c != 0 && a ==\
    \ 0 && L != 1) return 1;\n    if (c != 0 && b == 0 && R != n - 1) return 1;\n\
    \    return 0;\n  }\n\n  // return {min, i, j}. i==j \u306F\u9802\u70B9, i!=j\
    \ \u306F\u6700\u9069\u8FBA i -> j.\n  tuple<T, int, int> min_dot(P p) const {\n\
    \    static_assert(is_strict);\n    assert(p != P(0, 0));\n    int idx = periodic_min_comp(\n\
    \        [&](int i, int j) { return point[i].dot(p) < point[j].dot(p); });\n \
    \   T val = point[idx].dot(p);\n    int prv = prev_idx(idx), nxt = nxt_idx(idx);\n\
    \    if (point[prv].dot(p) == val) return {val, prv, idx};\n    if (point[nxt].dot(p)\
    \ == val) return {val, idx, nxt};\n    return {val, idx, idx};\n  }\n\n  // return\
    \ {max, i, j}. i==j \u306F\u9802\u70B9, i!=j \u306F\u6700\u9069\u8FBA i -> j.\n\
    \  tuple<T, int, int> max_dot(P p) const {\n    static_assert(is_strict);\n  \
    \  assert(p != P(0, 0));\n    int idx = periodic_min_comp(\n        [&](int i,\
    \ int j) { return point[i].dot(p) > point[j].dot(p); });\n    T val = point[idx].dot(p);\n\
    \    int prv = prev_idx(idx), nxt = nxt_idx(idx);\n    if (point[prv].dot(p) ==\
    \ val) return {val, prv, idx};\n    if (point[nxt].dot(p) == val) return {val,\
    \ idx, nxt};\n    return {val, idx, idx};\n  }\n\n  pair<int, int> visible_range(P\
    \ p) const {\n    static_assert(is_strict);\n    int a = periodic_min_comp(\n\
    \        [&](int i, int j) { return (point[i] - p).det(point[j] - p) < 0; });\n\
    \    int b = periodic_min_comp(\n        [&](int i, int j) { return (point[i]\
    \ - p).det(point[j] - p) > 0; });\n    if ((p - point[a]).det(p - point[prev_idx(a)])\
    \ == T(0)) a = prev_idx(a);\n    if ((p - point[b]).det(p - point[nxt_idx(b)])\
    \ == T(0)) b = nxt_idx(b);\n    return {a, b};\n  }\n\n  bool check_cross(P A,\
    \ P B) const {\n    static_assert(is_strict);\n    FOR(2) {\n      swap(A, B);\n\
    \      auto [a, b] = visible_range(A);\n      if ((point[a] - A).det(B - A) >=\
    \ 0) return false;\n      if ((point[b] - A).det(B - A) <= 0) return false;\n\
    \    }\n    return true;\n  }\n\n  // 0: \u5171\u901A\u70B9\u306A\u3057, 1: \u4E00\
    \u610F\u306A\u5171\u901A\u70B9, 2: \u7570\u306A\u308B\u5171\u901A\u70B9\u304C\
    2\u500B,\n  // infty<int>: \u5883\u754C\u8FBA\u3068\u6B63\u306E\u9577\u3055\u3067\
    \u91CD\u306A\u308B.\n  int count_boundary_cross_line(P A, P B) const {\n    static_assert(is_strict);\n\
    \    assert(A != B);\n    P D = B - A;\n    P normal(-D.y, D.x);\n    auto [min_value,\
    \ min_i, min_j] = min_dot(normal);\n    auto [max_value, max_i, max_j] = max_dot(normal);\n\
    \    T lo = min_value - normal.dot(A);\n    T hi = max_value - normal.dot(A);\n\
    \    if (lo > T(0) || hi < T(0)) return 0;\n    if (lo == T(0) && min_i != min_j)\
    \ return infty<int>;\n    if (hi == T(0) && max_i != max_j) return infty<int>;\n\
    \    if (lo == T(0) || hi == T(0)) return 1;\n    return 2;\n  }\n\n  // return\
    \ {t, eid, s} in increasing t order.\n  // A+t*(B-A) = point[eid]*(1-s)+point[nxt_idx(eid)]*s,\
    \ 0<=s<1.\n  // \u8FBA\u3068\u306E\u6B63\u306E\u9577\u3055\u306E\u91CD\u306A\u308A\
    \u306F assert \u3067\u62D2\u5426\u3059\u308B.\n  template <typename REAL>\n  vc<tuple<REAL,\
    \ int, REAL>> boundary_cross_line(P A, P B) const {\n    static_assert(is_strict);\n\
    \    assert(A != B);\n    int cnt = count_boundary_cross_line(A, B);\n    assert(cnt\
    \ != infty<int>);\n    if (cnt == 0) return {};\n\n    P D = B - A;\n    P normal(-D.y,\
    \ D.x);\n    auto [min_value, min_i, min_j] = min_dot(normal);\n    auto [max_value,\
    \ max_i, max_j] = max_dot(normal);\n    T lo = min_value - normal.dot(A);\n\n\
    \    auto vertex_data = [&](int i) -> tuple<REAL, int, REAL> {\n      REAL t =\
    \ (D.x != T(0) ? REAL(point[i].x - A.x) / REAL(D.x)\n                        \
    \    : REAL(point[i].y - A.y) / REAL(D.y));\n      return {t, i, REAL(0)};\n \
    \   };\n    if (cnt == 1) return {lo == T(0) ? vertex_data(min_i) : vertex_data(max_i)};\n\
    \n    auto eval = [&](int i) -> T {\n      return normal.dot(point[i % n]) - normal.dot(A);\n\
    \    };\n    int a = min_i, b = max_i;\n    if (b < a) b += n;\n    int p = binary_search([&](int\
    \ i) { return eval(i) < T(0); }, a, b);\n    int q = binary_search([&](int i)\
    \ { return eval(i) > T(0); }, b, a + n);\n    auto edge_data = [&](int eid) ->\
    \ tuple<REAL, int, REAL> {\n      int j = nxt_idx(eid);\n      T x = eval(eid),\
    \ y = eval(eid + 1);\n      if (x == T(0)) return vertex_data(eid);\n      if\
    \ (y == T(0)) return vertex_data(j);\n      assert((x < T(0) && T(0) < y) || (y\
    \ < T(0) && T(0) < x));\n      REAL s = REAL(x) / (REAL(x) - REAL(y));\n     \
    \ REAL t0 = (D.x != T(0) ? REAL(point[eid].x - A.x) / REAL(D.x)\n            \
    \                 : REAL(point[eid].y - A.y) / REAL(D.y));\n      REAL t1 = (D.x\
    \ != T(0) ? REAL(point[j].x - A.x) / REAL(D.x)\n                             :\
    \ REAL(point[j].y - A.y) / REAL(D.y));\n      return {t0 * (REAL(1) - s) + t1\
    \ * s, eid, s};\n    };\n    vc<tuple<REAL, int, REAL>> ans = {edge_data(p % n),\
    \ edge_data(q % n)};\n    if (get<0>(ans[1]) < get<0>(ans[0])) swap(ans[0], ans[1]);\n\
    \    return ans;\n  }\n\n  T area_between(int i, int j) const {\n    assert(i\
    \ <= j && j <= i + n);\n    if (j == i + n) return area2;\n    i %= n, j %= n;\n\
    \    if (i > j) j += n;\n    if (AREA.empty()) build_AREA();\n    return AREA[j]\
    \ - AREA[i] + point[j % n].det(point[i]);\n  }\n\n  T left_area(Line<T> L) const\
    \ {\n    static_assert(is_strict);\n    static_assert(is_same<T, double>::value\
    \ || is_same<T, long double>::value);\n    Point<T> normal(L.a, L.b);\n    auto\
    \ [min_value, a, min_j] = min_dot(normal);\n    auto [max_value, b, max_j] = max_dot(normal);\n\
    \    if (b < a) b += n;\n    assert(L.eval(point[a % n]) < 0 && L.eval(point[b\
    \ % n]) > 0);\n    int p =\n        binary_search([&](int i) { return L.eval(point[i\
    \ % n]) < 0; }, a, b);\n    int q = binary_search(\n        [&](int i) { return\
    \ L.eval(point[i % n]) > 0; }, b, a + n);\n    T s = L.eval(point[p % n]) /\n\
    \          (L.eval(point[p % n]) - L.eval(point[(p + 1) % n]));\n    T t = L.eval(point[q\
    \ % n]) /\n          (L.eval(point[q % n]) - L.eval(point[(q + 1) % n]));\n  \
    \  P A = point[p % n], B = point[(p + 1) % n];\n    P C = point[q % n], D = point[(q\
    \ + 1) % n];\n    P X = B * s + A * (1 - s), Y = D * t + C * (1 - t);\n    T ans\
    \ = area_between(p, q);\n    ans -= (A - C).det(X - C);\n    ans += (Y - C).det(X\
    \ - C);\n    return ans;\n  }\n\n private:\n  mutable vc<T> AREA;\n\n  void build_AREA()\
    \ const {\n    AREA.resize(2 * n);\n    FOR(i, n) AREA[n + i] = AREA[i] = point[i].det(point[nxt_idx(i)]);\n\
    \    AREA = cumsum<T>(AREA);\n  }\n};\n#line 1 \"geo/count_points_in_triangles.hpp\"\
    \n\n#line 1 \"geo/angle_sort.hpp\"\n\n#line 1 \"geo/base.hpp\"\ntemplate <typename\
    \ T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename\
    \ A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A,\
    \ typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  template <typename\
    \ U>\n  Point(Point<U> p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T>\
    \ || is_integral_v<U>);\n  }\n\n  Point operator+=(const Point p) {\n    x +=\
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
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n\
    \  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\
    \u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\
    \u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n\
    \    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\
    \n  bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }\n\
    \  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }\n\
    \  bool is_same(Line other) {\n    if (a * other.b != b * other.a) return 0;\n\
    \    if (a * other.c != c * other.a) return 0;\n    if (b * other.c != c * other.b)\
    \ return 0;\n    return 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n\
    \  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T\
    \ x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det !=\
    \ 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n\
    \  }\n\n  Line<T> to_line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 3 \"geo/angle_sort.hpp\"\n\n// lower: -1, origin: 0, upper: 1, (-pi,pi]\ntemplate\
    \ <typename T> int lower_or_upper(const Point<T> &p) {\n  if (p.y != 0)\n    return\
    \ (p.y > 0 ? 1 : -1);\n  if (p.x > 0)\n    return -1;\n  if (p.x < 0)\n    return\
    \ 1;\n  return 0;\n}\n\n// L<R:-1, L==R:0, L>R:1, (-pi,pi]\ntemplate <typename\
    \ T> int angle_comp_3(const Point<T> &L, const Point<T> &R) {\n  int a = lower_or_upper(L),\
    \ b = lower_or_upper(R);\n  if (a != b)\n    return (a < b ? -1 : +1);\n  T det\
    \ = L.det(R);\n  if (det > 0)\n    return -1;\n  if (det < 0)\n    return 1;\n\
    \  return 0;\n}\n\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort,\
    \ (-pi,pi]\ntemplate <typename T> vector<int> angle_sort(vector<Point<T>> &P)\
    \ {\n  vc<int> I(len(P));\n  FOR(i, len(P)) I[i] = i;\n  sort(all(I), [&](auto\
    \ &L, auto &R) -> bool {\n    return angle_comp_3(P[L], P[R]) == -1;\n  });\n\
    \  return I;\n}\n\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort,\
    \ (-pi,pi]\ntemplate <typename T> vector<int> angle_sort(vector<pair<T, T>> &P)\
    \ {\n  vc<Point<T>> tmp(len(P));\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\n\
    \  return angle_sort<T>(tmp);\n}\n#line 1 \"geo/base.hpp\"\ntemplate <typename\
    \ T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\n  template <typename\
    \ A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n  template <typename A,\
    \ typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se) {}\n\n  template <typename\
    \ U>\n  Point(Point<U> p) : x(p.x), y(p.y) {\n    static_assert(!is_integral_v<T>\
    \ || is_integral_v<U>);\n  }\n\n  Point operator+=(const Point p) {\n    x +=\
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
    \ {}\n  Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y, b = B.x - A.x, c =\
    \ A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return U(a) * P.x + U(b) * P.y + U(c);\n  }\n\n  template <typename U>\n\
    \  T eval(U x, U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\
    \u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\
    \u3046\u306B\u3059\u308B\n  void normalize() {\n    static_assert(is_same_v<T,\
    \ int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n\
    \    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a = -a, b = -b, c = -c;\n\
    \    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b, c = -c;\n    }\n  }\n\
    \n  bool is_parallel(Line other) { return a * other.b - b * other.a == 0; }\n\
    \  bool is_orthogonal(Line other) { return a * other.a + b * other.b == 0; }\n\
    \  bool is_same(Line other) {\n    if (a * other.b != b * other.a) return 0;\n\
    \    if (a * other.c != c * other.a) return 0;\n    if (b * other.c != c * other.b)\
    \ return 0;\n    return 1;\n  }\n};\n\ntemplate <typename T>\nstruct Segment {\n\
    \  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n  Segment(T\
    \ x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\
    \n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if (det !=\
    \ 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A - B) >= 0;\n\
    \  }\n\n  Line<T> to_line() { return Line(A, B); }\n};\n\ntemplate <typename REAL>\n\
    struct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 1 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                      chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                          .count()) *\n                  10150724397891781847ULL;\n\
    \  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) {\n  assert(lim\
    \ > 0);\n  return RNG_64() % lim;\n}\n\nll RNG(ll l, ll r) {\n  assert(l < r);\n\
    \  return l + RNG_64() % (r - l);\n}\n#line 1 \"ds/fenwicktree/fenwicktree_01.hpp\"\
    \n\n#line 1 \"other/bit.hpp\"\n\nint popcnt(int x) { return __builtin_popcount(x);\
    \ }\nint popcnt(u32 x) { return __builtin_popcount(x); }\nint popcnt(ll x) { return\
    \ __builtin_popcountll(x); }\nint popcnt(u64 x) { return __builtin_popcountll(x);\
    \ }\nint popcnt_sgn(int x) { return (__builtin_parity(unsigned(x)) & 1 ? -1 :\
    \ 1); }\nint popcnt_sgn(u32 x) { return (__builtin_parity(x) & 1 ? -1 : 1); }\n\
    int popcnt_sgn(ll x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\nint popcnt_sgn(u64\
    \ x) { return (__builtin_parityll(x) & 1 ? -1 : 1); }\n// (0, 1, 2, 3, 4) -> (-1,\
    \ 0, 1, 1, 2)\nint topbit(int x) { return (x == 0 ? -1 : 31 - __builtin_clz(x));\
    \ }\nint topbit(u32 x) { return (x == 0 ? -1 : 31 - __builtin_clz(x)); }\nint\
    \ topbit(ll x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\nint topbit(u64\
    \ x) { return (x == 0 ? -1 : 63 - __builtin_clzll(x)); }\n// (0, 1, 2, 3, 4) ->\
    \ (-1, 0, 1, 0, 2)\nint lowbit(int x) { return (x == 0 ? -1 : __builtin_ctz(x));\
    \ }\nint lowbit(u32 x) { return (x == 0 ? -1 : __builtin_ctz(x)); }\nint lowbit(ll\
    \ x) { return (x == 0 ? -1 : __builtin_ctzll(x)); }\nint lowbit(u64 x) { return\
    \ (x == 0 ? -1 : __builtin_ctzll(x)); }\n\ntemplate <typename T>\nT kth_bit(int\
    \ k) {\n  assert(0 <= k && k < int(8 * sizeof(T)));\n  return T(1) << k;\n}\n\
    template <typename T>\nbool has_kth_bit(T x, int k) {\n  assert(0 <= k && k <\
    \ int(8 * sizeof(T)));\n  return x >> k & 1;\n}\n\ntemplate <typename UINT>\n\
    struct all_bit {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_bit(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s;\n    int operator*() const { return\
    \ lowbit(s); }\n    void operator++() { s &= s - 1; }\n    bool operator!=(nullptr_t)\
    \ const { return s; }\n  };\n  iter begin() const { return {s}; }\n  nullptr_t\
    \ end() const { return nullptr; }\n};\n\ntemplate <typename UINT>\nstruct all_subset\
    \ {\n  static_assert(is_unsigned<UINT>::value);\n  UINT s;\n  all_subset(UINT\
    \ s) : s(s) {}\n  struct iter {\n    UINT s, t;\n    bool done = false;\n    UINT\
    \ operator*() const { return t; }\n    void operator++() {\n      done = (t ==\
    \ 0);\n      t = (t - 1) & s;\n    }\n    bool operator!=(nullptr_t) const { return\
    \ !done; }\n  };\n  iter begin() const { return {s, s}; }\n  nullptr_t end() const\
    \ { return nullptr; }\n};\n\nconstexpr u64 full_mask(int n) {\n  assert(0 <= n\
    \ && n <= 64);\n  return n == 64 ? -1ULL : (1ULL << n) - 1;\n}\n\nu64 bit_reverse(u64\
    \ x) {\n  x = ((x & 0x5555555555555555ULL) << 1) | ((x >> 1) & 0x5555555555555555ULL);\n\
    \  x = ((x & 0x3333333333333333ULL) << 2) | ((x >> 2) & 0x3333333333333333ULL);\n\
    \  x = ((x & 0x0f0f0f0f0f0f0f0fULL) << 4) | ((x >> 4) & 0x0f0f0f0f0f0f0f0fULL);\n\
    \  x = ((x & 0x00ff00ff00ff00ffULL) << 8) | ((x >> 8) & 0x00ff00ff00ff00ffULL);\n\
    \  x = ((x & 0x0000ffff0000ffffULL) << 16) | ((x >> 16) & 0x0000ffff0000ffffULL);\n\
    \  x = (x << 32) | (x >> 32);\n  return x;\n}\n#line 1 \"alg/monoid/add.hpp\"\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/fenwicktree/fenwicktree.hpp\"\n\ntemplate <typename Monoid>\n\
    struct FenwickTree {\n  using G = Monoid;\n  using MX = Monoid;\n  using E = typename\
    \ G::value_type;\n  int n;\n  vector<E> dat;\n  E total;\n\n  FenwickTree() {}\n\
    \  FenwickTree(int n) { build(n); }\n  template <typename F>\n  FenwickTree(int\
    \ n, F f) {\n    build(n, f);\n  }\n  FenwickTree(const vc<E>& v) { build(v);\
    \ }\n\n  void build(int m) {\n    n = m;\n    dat.assign(m, G::id());\n    total\
    \ = G::id();\n  }\n  void build(const vc<E>& v) {\n    build(len(v), [&](int i)\
    \ -> E { return v[i]; });\n  }\n  template <typename F>\n  void build(int m, F\
    \ f) {\n    n = m;\n    dat.clear();\n    dat.reserve(n);\n    total = G::id();\n\
    \    FOR(i, n) { dat.eb(f(i)); }\n    for (int i = 1; i <= n; ++i) {\n      int\
    \ j = i + (i & -i);\n      if (j <= n) dat[j - 1] = G::op(dat[i - 1], dat[j -\
    \ 1]);\n    }\n    total = prefix_sum(m);\n  }\n\n  E prod_all() const { return\
    \ total; }\n  E sum_all() const { return total; }\n  E sum(int k) const { return\
    \ prefix_sum(k); }\n  E prod(int k) const { return prefix_prod(k); }\n  E prefix_sum(int\
    \ k) const { return prefix_prod(k); }\n  E prefix_prod(int k) const {\n    chmin(k,\
    \ n);\n    E ret = G::id();\n    for (; k > 0; k -= k & -k) ret = G::op(ret, dat[k\
    \ - 1]);\n    return ret;\n  }\n  E sum(int L, int R) const { return prod(L, R);\
    \ }\n  E prod(int L, int R) const {\n    chmax(L, 0), chmin(R, n);\n    if (L\
    \ == 0) return prefix_prod(R);\n    assert(0 <= L && L <= R && R <= n);\n    E\
    \ pos = G::id(), neg = G::id();\n    while (L < R) {\n      pos = G::op(pos, dat[R\
    \ - 1]), R -= R & -R;\n    }\n    while (R < L) {\n      neg = G::op(neg, dat[L\
    \ - 1]), L -= L & -L;\n    }\n    return G::op(pos, G::inverse(neg));\n  }\n\n\
    \  vc<E> get_all() const {\n    vc<E> res(n);\n    FOR(i, n) res[i] = prod(i,\
    \ i + 1);\n    return res;\n  }\n\n  void add(int k, E x) { multiply(k, x); }\n\
    \  void multiply(int k, E x) {\n    static_assert(G::commute);\n    assert(0 <=\
    \ k && k < n);\n    total = G::op(total, x);\n    for (++k; k <= n; k += k & -k)\
    \ dat[k - 1] = G::op(dat[k - 1], x);\n  }\n  void set(int k, E x) { add(k, G::op(G::inverse(prod(k,\
    \ k + 1)), x)); }\n\n  template <class F>\n  int max_right(const F check, int\
    \ L = 0) const {\n    assert(check(G::id()));\n    E s = G::id();\n    int i =\
    \ L;\n    // 2^k \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while\
    \ (1) {\n        if (i % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i -\
    \ 1])), i -= 1;\n        }\n        if (i == 0) {\n          return topbit(n)\
    \ + 1;\n        }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) >\
    \ n) return k;\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(t))\
    \ {\n          return k;\n        }\n        s = G::op(s, G::inverse(dat[i - 1])),\
    \ i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n      if (i +\
    \ (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k) - 1]);\n\
    \        if (i + (1 << k) <= L || check(t)) {\n          i += (1 << k), s = t;\n\
    \        }\n      }\n    }\n    return i;\n  }\n\n  // check(i, x)\n  template\
    \ <class F>\n  int max_right_with_index(const F check, int L = 0) const {\n  \
    \  assert(check(L, G::id()));\n    E s = G::id();\n    int i = L;\n    // 2^k\
    \ \u9032\u3080\u3068\u30C0\u30E1\n    int k = [&]() {\n      while (1) {\n   \
    \     if (i % 2 == 1) {\n          s = G::op(s, G::inverse(dat[i - 1])), i -=\
    \ 1;\n        }\n        if (i == 0) {\n          return topbit(n) + 1;\n    \
    \    }\n        int k = lowbit(i) - 1;\n        if (i + (1 << k) > n) return k;\n\
    \        E t = G::op(s, dat[i + (1 << k) - 1]);\n        if (!check(i + (1 <<\
    \ k), t)) {\n          return k;\n        }\n        s = G::op(s, G::inverse(dat[i\
    \ - 1])), i -= i & -i;\n      }\n    }();\n    while (k) {\n      --k;\n     \
    \ if (i + (1 << k) - 1 < len(dat)) {\n        E t = G::op(s, dat[i + (1 << k)\
    \ - 1]);\n        if (i + (1 << k) <= L || check(i + (1 << k), t)) {\n       \
    \   i += (1 << k), s = t;\n        }\n      }\n    }\n    return i;\n  }\n\n \
    \ template <class F>\n  int min_left(const F check, int R) const {\n    assert(check(G::id()));\n\
    \    E s = G::id();\n    int i = R;\n    // false \u306B\u306A\u308B\u3068\u3053\
    \u308D\u307E\u3067\u623B\u308B\n    int k = 0;\n    while (i > 0 && check(s))\
    \ {\n      s = G::op(s, dat[i - 1]);\n      k = lowbit(i);\n      i -= i & -i;\n\
    \    }\n    if (check(s)) {\n      assert(i == 0);\n      return 0;\n    }\n \
    \   // 2^k \u9032\u3080\u3068 ok \u306B\u306A\u308B\n    // false \u3092\u7DAD\
    \u6301\u3057\u3066\u9032\u3080\n    while (k) {\n      --k;\n      E t = G::op(s,\
    \ G::inverse(dat[i + (1 << k) - 1]));\n      if (!check(t)) {\n        i += (1\
    \ << k), s = t;\n      }\n    }\n    return i + 1;\n  }\n\n  int kth(E k, int\
    \ L = 0) const {\n    return max_right([&k](E x) -> bool { return x <= k; }, L);\n\
    \  }\n};\n#line 3 \"ds/fenwicktree/fenwicktree_01.hpp\"\n\nstruct FenwickTree_01\
    \ {\n  using MX = Monoid_Add<int>;\n  int N, n;\n  vc<u64> dat;\n  FenwickTree<Monoid_Add<int>>\
    \ bit;\n  FenwickTree_01() {}\n  FenwickTree_01(int n) { build(n); }\n  template\
    \ <typename F>\n  FenwickTree_01(int n, F f) {\n    build(n, f);\n  }\n\n  void\
    \ build(int m) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    bit.build(n);\n  }\n  void build(vc<int> dat) {\n    build(len(dat),\
    \ [&](int i) -> int { return dat[i]; });\n  }\n\n  template <typename F>\n  void\
    \ build(int m, F f) {\n    N = m;\n    n = ceil<int>(N + 1, 64);\n    dat.assign(n,\
    \ u64(0));\n    FOR(i, N) {\n      u64 x = f(i);\n      assert(x == 0 || x ==\
    \ 1);\n      dat[i / 64] |= x << (i % 64);\n    }\n    bit.build(n, [&](int i)\
    \ -> int { return popcnt(dat[i]); });\n  }\n\n  int sum_all() { return bit.sum_all();\
    \ }\n  int sum(int k) { return prefix_sum(k); }\n  int prefix_sum(int k) {\n \
    \   assert(0 <= k && k <= N);\n    int ans = bit.sum(k / 64);\n    ans += popcnt(dat[k\
    \ / 64] & ((u64(1) << (k % 64)) - 1));\n    return ans;\n  }\n  int sum(int L,\
    \ int R) {\n    assert(0 <= L && L <= R && R <= N);\n    if (L == 0) return prefix_sum(R);\n\
    \    int ans = 0;\n    ans -= popcnt(dat[L / 64] & ((u64(1) << (L % 64)) - 1));\n\
    \    ans += popcnt(dat[R / 64] & ((u64(1) << (R % 64)) - 1));\n    ans += bit.sum(L\
    \ / 64, R / 64);\n    return ans;\n  }\n  int get(int i) {\n    assert(0 <= i\
    \ && i < N);\n    return sum(i, i + 1);\n  }\n  int prod(int L, int R) { return\
    \ sum(L, R); }\n\n  void add(int k, int x) {\n    assert(0 <= k && k < N);\n \
    \   if (x == 1) {\n      assert(sum(k, k + 1) == 0);\n      dat[k / 64] |= u64(1)\
    \ << (k % 64);\n      bit.add(k / 64, 1);\n    }\n    elif (x == -1) {\n     \
    \ assert(sum(k, k + 1) == 1);\n      dat[k / 64] &= ~(u64(1) << (k % 64));\n \
    \     bit.add(k / 64, -1);\n    }\n    else assert(0);\n  }\n  void multiply(int\
    \ k, int x) { add(k, x); }\n\n  void add(int k) { add(k, 1); }\n  void remove(int\
    \ k) { add(k, -1); }\n\n  int kth(int k, int L = 0) {\n    assert(0 <= L && L\
    \ <= N);\n    assert(0 <= k && k < sum_all());\n    k += popcnt(dat[L / 64] &\
    \ ((u64(1) << (L % 64)) - 1));\n    L /= 64;\n    int mid = 0;\n    auto check\
    \ = [&](auto e) -> bool {\n      if (e <= k) chmax(mid, e);\n      return e <=\
    \ k;\n    };\n    int idx = bit.max_right(check, L);\n    if (idx == n) return\
    \ N;\n    k -= mid;\n    u64 x = dat[idx];\n    int p = popcnt(x);\n    if (p\
    \ <= k) return N;\n    k = binary_search(\n        [&](int n) -> bool { return\
    \ (p - popcnt(x >> n)) <= k; }, 0, 64, 0);\n    return 64 * idx + k;\n  }\n\n\
    \  int next(int k) {\n    assert(0 <= k && k <= N);\n    int idx = k / 64;\n \
    \   k %= 64;\n    u64 x = dat[idx] & ~((u64(1) << k) - 1);\n    if (x) return\
    \ 64 * idx + lowbit(x);\n    idx = bit.kth(0, idx + 1);\n    if (idx == n || !dat[idx])\
    \ return N;\n    return 64 * idx + lowbit(dat[idx]);\n  }\n\n  int prev(int k)\
    \ {\n    assert(0 <= k && k <= N);\n    if (k == N) --k;\n    int idx = k / 64;\n\
    \    k %= 64;\n    u64 x = dat[idx];\n    if (k < 63) x &= (u64(1) << (k + 1))\
    \ - 1;\n    if (x) return 64 * idx + topbit(x);\n    idx = bit.min_left([&](auto\
    \ e) -> bool { return e <= 0; }, idx) - 1;\n    if (idx == -1) return -1;\n  \
    \  return 64 * idx + topbit(dat[idx]);\n  }\n\n  string to_string() {\n    string\
    \ out;\n    FOR(i, N) out += '0' + (dat[i / 64] >> (i & 63) & 1);\n    return\
    \ out;\n  }\n};\n#line 6 \"geo/count_points_in_triangles.hpp\"\n\n// \u70B9\u7FA4\
    \ A, B \u3092\u5165\u529B \uFF08Point<ll>\uFF09\n// query(i,j,k)\uFF1A\u4E09\u89D2\
    \u5F62 AiAjAk \u5185\u90E8\u306E Bl \u306E\u500B\u6570\uFF08\u975E\u8CA0\uFF09\
    \u3092\u8FD4\u3059\n// \u524D\u8A08\u7B97 O(NMlogM)\u3001\u30AF\u30A8\u30EA O(1)\n\
    // https://codeforces.com/contest/13/problem/D\n// https://codeforces.com/contest/852/problem/H\n\
    struct Count_Points_in_Triangles {\n  using P = Point<ll>;\n  const int LIM =\
    \ 1'000'000'000 + 10;\n  vc<P> A, B;\n  vc<int> new_idx; // O \u304B\u3089\u898B\
    \u305F\u504F\u89D2\u30BD\u30FC\u30C8\u9806\u3092\u7BA1\u7406\n  vc<int> point;\
    \   // A[i] \u3068\u4E00\u81F4\u3059\u308B B[j] \u306E\u6570\u3048\u4E0A\u3052\
    \n  vvc<int> seg;    // \u7DDA\u5206 A[i]A[j] \u5185\u306B\u3042\u308B B[k] \u306E\
    \u6570\u3048\u4E0A\u3052\n  vvc<int> tri;    // OA[i]A[j] \u5185\u90E8\u306B\u3042\
    \u308B B[k] \u306E\u6570\u3048\u4E0A\u3052\n  Count_Points_in_Triangles(const\
    \ vc<P>& A, const vc<P>& B) : A(A), B(B) {\n    for (auto&& p: A) assert(max(abs(p.x),\
    \ abs(p.y)) < LIM);\n    for (auto&& p: B) assert(max(abs(p.x), abs(p.y)) < LIM);\n\
    \    build();\n  }\n\n  int count3(int i, int j, int k) {\n    i = new_idx[i],\
    \ j = new_idx[j], k = new_idx[k];\n    if (i > j) swap(i, j);\n    if (j > k)\
    \ swap(j, k);\n    if (i > j) swap(i, j);\n    assert(i <= j && j <= k);\n   \
    \ ll d = (A[j] - A[i]).det(A[k] - A[i]);\n    if (d == 0) return 0;\n    if (d\
    \ > 0) { return tri[i][j] + tri[j][k] - tri[i][k] - seg[i][k]; }\n    int x =\
    \ tri[i][k] - tri[i][j] - tri[j][k];\n    return x - seg[i][j] - seg[j][k] - point[j];\n\
    \  }\n\n  // segment\n  int count2(int i, int j) {\n    i = new_idx[i], j = new_idx[j];\n\
    \    if (i > j) swap(i, j);\n    return seg[i][j];\n  }\n\nprivate:\n  P take_origin()\
    \ {\n    // OAiAj, OAiBj \u304C\u540C\u4E00\u76F4\u7DDA\u4E0A\u306B\u306A\u3089\
    \u306A\u3044\u3088\u3046\u306B\u3059\u308B\n    // fail prob: at most N(N+M)/LIM\n\
    \    return P{-LIM, RNG(-LIM, LIM)};\n  }\n\n  void build() {\n    P O = take_origin();\n\
    \    for (auto&& p: A) p = p - O;\n    for (auto&& p: B) p = p - O;\n    int N\
    \ = len(A), M = len(B);\n    vc<int> I = angle_sort(A);\n    A = rearrange(A,\
    \ I);\n    new_idx.resize(N);\n    FOR(i, N) new_idx[I[i]] = i;\n\n    I = angle_sort(B);\n\
    \    B = rearrange(B, I);\n\n    point.assign(N, 0);\n    seg.assign(N, vc<int>(N));\n\
    \    tri.assign(N, vc<int>(N));\n\n    // point\n    FOR(i, N) FOR(j, M) if (A[i]\
    \ == B[j])++ point[i];\n\n    int m = 0;\n    FOR(j, N) {\n      // OA[i]A[j],\
    \ B[k]\n      while (m < M && A[j].det(B[m]) < 0) ++m;\n      vc<P> C(m);\n  \
    \    FOR(k, m) C[k] = B[k] - A[j];\n      vc<int> I(m);\n      FOR(i, m) I[i]\
    \ = i;\n      sort(all(I), [&](auto& a, auto& b) -> bool { return C[a].det(C[b])\
    \ > 0; });\n      C = rearrange(C, I);\n      vc<int> rk(m);\n      FOR(k, m)\
    \ rk[I[k]] = k;\n      FenwickTree_01 bit(m);\n\n      int k = m;\n      FOR_R(i,\
    \ j) {\n        while (k > 0 && A[i].det(B[k - 1]) > 0) { bit.add(rk[--k], 1);\
    \ }\n        P p = A[i] - A[j];\n        int lb = binary_search([&](int n) ->\
    \ bool { return (n == 0 ? true : C[n - 1].det(p) > 0); }, 0, m + 1);\n       \
    \ int ub = binary_search([&](int n) -> bool { return (n == 0 ? true : C[n - 1].det(p)\
    \ >= 0); }, 0, m + 1);\n        seg[i][j] += bit.sum(lb, ub), tri[i][j] += bit.sum(lb);\n\
    \      }\n    }\n  }\n};\n#line 7 \"random/random_polygon.hpp\"\n\nvc<Point<ll>>\
    \ random_polygon(int N, int XY_ABS_MAX = 10) {\n  using P = Point<ll>;\n  if (N\
    \ <= 2) {\n    while (1) {\n      vc<P> A(N);\n      FOR(i, N) {\n        A[i].x\
    \ = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);\n        A[i].y = RNG(-XY_ABS_MAX, XY_ABS_MAX\
    \ + 1);\n      }\n      if (N == 1) return A;\n      if (N == 2 && A[0] != A[1])\
    \ return A;\n    }\n  }\n  assert(N >= 3);\n  auto trial = [&]() -> vc<P> {\n\
    \    set<Point<ll>> S;\n    while (len(S) < N) {\n      int x = RNG(-XY_ABS_MAX,\
    \ XY_ABS_MAX + 1);\n      int y = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);\n      S.insert(Point<ll>(x,\
    \ y));\n    }\n    vc<P> point(all(S));\n    auto I = convex_hull<ll, true>(point);\n\
    \    Count_Points_in_Triangles CT(point, point);\n    vc<int> other;\n    vc<int>\
    \ done(N);\n    for (auto& i : I) done[i]++;\n    if (MAX(done) >= 2) return {};\n\
    \    FOR(i, N) if (!done[i]) other.eb(i);\n    int fail = 0;\n    while (len(other))\
    \ {\n      if (fail > 1000) return {};\n      ++fail;\n      int i = RNG(0, len(I)),\
    \ j = RNG(0, len(other));\n      swap(other[j], other.back());\n      int a =\
    \ I[i], b = I[(i + 1) % len(I)], c = other.back();\n      if ((point[b] - point[a]).det(point[c]\
    \ - point[a]) < 0) continue;\n      if (CT.count3(a, b, c)) continue;\n      if\
    \ (CT.count2(a, c) + CT.count2(b, c)) continue;\n      bool ok = 1;\n      for\
    \ (auto& v : {a, b}) {\n        FOR(i, len(I)) {\n          Segment<ll> S1(point[v],\
    \ point[c]);\n          Segment<ll> S2(point[I[i]], point[I[(i + 1) % len(I)]]);\n\
    \          if (count_cross(S1, S2, false)) ok = 0;\n        }\n      }\n     \
    \ if (!ok) continue;\n      fail = 0;\n      I.insert(I.begin() + i + 1, POP(other));\n\
    \    }\n    point = rearrange(point, I);\n    FOR(i, N) {\n      if ((point[(i\
    \ + 2) % N] - point[i]).det(point[(i + 1) % N] - point[i]) ==\n          0)\n\
    \        return {};\n    }\n    return point;\n  };\n  while (1) {\n    vc<P>\
    \ ANS = trial();\n    if (ANS.empty()) continue;\n    int k = RNG(0, len(ANS));\n\
    \    rotate(ANS.begin(), ANS.begin() + k, ANS.end());\n    return ANS;\n  }\n\
    }\n"
  code: "\n#include \"random/base.hpp\"\n#include \"geo/base.hpp\"\n#include \"geo/convex_hull.hpp\"\
    \n#include \"geo/cross_point.hpp\"\n#include \"geo/count_points_in_triangles.hpp\"\
    \n\nvc<Point<ll>> random_polygon(int N, int XY_ABS_MAX = 10) {\n  using P = Point<ll>;\n\
    \  if (N <= 2) {\n    while (1) {\n      vc<P> A(N);\n      FOR(i, N) {\n    \
    \    A[i].x = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);\n        A[i].y = RNG(-XY_ABS_MAX,\
    \ XY_ABS_MAX + 1);\n      }\n      if (N == 1) return A;\n      if (N == 2 &&\
    \ A[0] != A[1]) return A;\n    }\n  }\n  assert(N >= 3);\n  auto trial = [&]()\
    \ -> vc<P> {\n    set<Point<ll>> S;\n    while (len(S) < N) {\n      int x = RNG(-XY_ABS_MAX,\
    \ XY_ABS_MAX + 1);\n      int y = RNG(-XY_ABS_MAX, XY_ABS_MAX + 1);\n      S.insert(Point<ll>(x,\
    \ y));\n    }\n    vc<P> point(all(S));\n    auto I = convex_hull<ll, true>(point);\n\
    \    Count_Points_in_Triangles CT(point, point);\n    vc<int> other;\n    vc<int>\
    \ done(N);\n    for (auto& i : I) done[i]++;\n    if (MAX(done) >= 2) return {};\n\
    \    FOR(i, N) if (!done[i]) other.eb(i);\n    int fail = 0;\n    while (len(other))\
    \ {\n      if (fail > 1000) return {};\n      ++fail;\n      int i = RNG(0, len(I)),\
    \ j = RNG(0, len(other));\n      swap(other[j], other.back());\n      int a =\
    \ I[i], b = I[(i + 1) % len(I)], c = other.back();\n      if ((point[b] - point[a]).det(point[c]\
    \ - point[a]) < 0) continue;\n      if (CT.count3(a, b, c)) continue;\n      if\
    \ (CT.count2(a, c) + CT.count2(b, c)) continue;\n      bool ok = 1;\n      for\
    \ (auto& v : {a, b}) {\n        FOR(i, len(I)) {\n          Segment<ll> S1(point[v],\
    \ point[c]);\n          Segment<ll> S2(point[I[i]], point[I[(i + 1) % len(I)]]);\n\
    \          if (count_cross(S1, S2, false)) ok = 0;\n        }\n      }\n     \
    \ if (!ok) continue;\n      fail = 0;\n      I.insert(I.begin() + i + 1, POP(other));\n\
    \    }\n    point = rearrange(point, I);\n    FOR(i, N) {\n      if ((point[(i\
    \ + 2) % N] - point[i]).det(point[(i + 1) % N] - point[i]) ==\n          0)\n\
    \        return {};\n    }\n    return point;\n  };\n  while (1) {\n    vc<P>\
    \ ANS = trial();\n    if (ANS.empty()) continue;\n    int k = RNG(0, len(ANS));\n\
    \    rotate(ANS.begin(), ANS.begin() + k, ANS.end());\n    return ANS;\n  }\n}"
  dependsOn:
  - random/base.hpp
  - geo/base.hpp
  - geo/convex_hull.hpp
  - geo/cross_point.hpp
  - geo/count_points_in_triangles.hpp
  - geo/angle_sort.hpp
  - ds/fenwicktree/fenwicktree_01.hpp
  - ds/fenwicktree/fenwicktree.hpp
  - other/bit.hpp
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: random/random_polygon.hpp
  requiredBy: []
  timestamp: '2026-09-22 16:20:38+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/polygon_triangulation.test.cpp
documentation_of: random/random_polygon.hpp
layout: document
redirect_from:
- /library/random/random_polygon.hpp
- /library/random/random_polygon.hpp.html
title: random/random_polygon.hpp
---
