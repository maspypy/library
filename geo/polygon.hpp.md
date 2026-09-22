---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':question:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':x:'
    path: geo/cross_point.hpp
    title: geo/cross_point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/JAG2014Spring/tasks/icpc2014spring_f
    - https://atcoder.jp/contests/jag2016-domestic/tasks/jag2016secretspring_e
    - https://codeforces.com/contest/598/problem/F
    - https://github.com/maspypy/library/blob/main/geo/polygon_side.png
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
    \ dx * dx + dy * dy <= r * r;\n  }\n};\n#line 1 \"geo/base.hpp\"\ntemplate <typename\
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
    \    AREA = cumsum<T>(AREA);\n  }\n};\n#line 3 \"geo/polygon.hpp\"\n\ntemplate\
    \ <typename T>\nstruct Polygon {\n  vc<Point<T>> point;\n  T a;\n\n  Polygon(vc<Point<T>>\
    \ point) : point(point) { build(); }\n\n  int size() { return len(point); }\n\n\
    \  template <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\n  T\
    \ area_2() { return a; }\n\n  bool is_convex() {\n    FOR(j, len(point)) {\n \
    \     int i = (j == 0 ? len(point) - 1 : j - 1);\n      int k = (j == len(point)\
    \ - 1 ? 0 : j + 1);\n      if ((point[j] - point[i]).det(point[k] - point[j])\
    \ < 0) return false;\n    }\n    return true;\n  }\n\n  // \u4E2D\uFF1A1, \u5883\
    \u754C\uFF1A0, \u5916\uFF1A-1.\n  int side(Point<T> p) {\n    int n = len(point);\n\
    \    FOR(i, n) if (point[i] == p) return 0;\n    FOR(i, n) {\n      Point<T> A\
    \ = point[i], B = point[(i + 1) % n];\n      if ((p - A).det(B - A) != 0) continue;\n\
    \      if ((p - A).dot(B - A) >= 0 && (p - B).dot(A - B) >= 0) return 0;\n   \
    \ }\n    // p \u304B\u3089 x \u65B9\u5411\u306B (+1, +eps) \u65B9\u5411\u306B\u306E\
    \u3073\u308B\u534A\u76F4\u7DDA\u3068\u306E\u4EA4\u5DEE\u3092\u8003\u3048\u308B\
    \n    int cnt = 0;\n    FOR(i, n) {\n      Point<T> A = point[i], B = point[(i\
    \ + 1) % n];\n      FOR(2) {\n        swap(A, B);\n        if (A.y > p.y) continue;\n\
    \        if (B.y <= p.y) continue;\n        if ((A - p).det(B - p) > 0) ++cnt;\n\
    \      }\n    }\n    return (cnt % 2 == 0 ? -1 : 1);\n  }\n\n  // point[i] \u306E\
    \u8FD1\u508D\u3060\u3051\u3067\u898B\u305F side\n  // https://github.com/maspypy/library/blob/main/geo/polygon_side.png\n\
    \  int side_at(int i, Point<T> p) {\n    int n = len(point);\n    p -= point[i];\n\
    \    if (p.x == T(0) && p.y == T(0)) return 0;\n    Point<T> L = point[(i + 1)\
    \ % n] - point[i];\n    Point<T> R = point[(i + n - 1) % n] - point[i];\n    auto\
    \ sgn = [&](T x) -> int {\n      if (x == T(0)) return 0;\n      return (x > T(0)\
    \ ? 1 : -1);\n    };\n    int x = sgn(L.det(p)) + sgn(p.det(R)) + sgn(R.det(L));\n\
    \    if (x == 0) return x;\n    return (x > 0 ? 1 : -1);\n  }\n\n  // \u7DDA\u5206\
    \u304C\u5185\u90E8\u30FB\u5916\u90E8\u305D\u308C\u305E\u308C\u3092\u901A\u308B\
    \u304B\n  // https://atcoder.jp/contests/jag2016-domestic/tasks/jag2016secretspring_e\n\
    \  // https://atcoder.jp/contests/JAG2014Spring/tasks/icpc2014spring_f\n  pair<bool,\
    \ bool> side_segment(Point<T> L, Point<T> R) {\n    Segment<T> S(L, R);\n    //\
    \ \u307E\u305A\u7DDA\u5206\u3068\u975E\u81EA\u660E\u306B\u4EA4\u308F\u308B\u30D1\
    \u30BF\u30FC\u30F3\n    int n = len(point);\n    FOR(i, n) {\n      Segment<T>\
    \ S2(point[i], point[(i + 1) % n]);\n      if (count_cross(S, S2, false) == 1)\
    \ {\n        return {1, 1};\n      }\n    }\n    bool in = 0, out = 0;\n    if\
    \ (side(L) == 1 || side(R) == 1) in = 1;\n    if (side(L) == -1 || side(R) ==\
    \ -1) out = 1;\n    FOR(i, n) {\n      if (!S.contain(point[i])) continue;\n \
    \     for (auto& p : {L, R}) {\n        int k = side_at(i, p);\n        if (k\
    \ == 1) in = 1;\n        if (k == -1) out = 1;\n      }\n    }\n    return {in,\
    \ out};\n  }\n\n  // polygon \u3068 line \u306E\u5171\u901A\u90E8\u5206\u3092\
    \ line \u4E0A\u306E\u533A\u9593\u5217\u3068\u3057\u3066\u8FD4\u3059\u3002\n  //\
    \ return \u3055\u308C\u308B Segment\uFF1A\u9000\u5316\u30B1\u30FC\u30B9\u3082\u3042\
    \u308B\n  // https://codeforces.com/contest/598/problem/F\n  template <typename\
    \ REAL>\n  vc<Segment<REAL>> cross_line(Line<T> L, bool allow_perimeter) {\n \
    \   static_assert(is_integral_v<T>);\n    using RP = Point<REAL>;\n    int N =\
    \ len(point);\n    vc<int> side(N);\n    auto sgn = [&](T x) -> int { return (x\
    \ > 0 ? 1 : x < 0 ? -1 : 0); };\n\n    FOR(i, N) side[i] = sgn(L.eval(point[i]));\n\
    \    vc<pair<RP, int>> event;\n\n    FOR(i, N) {\n      int j = (i + 1) % N;\n\
    \n      if (side[i] == 0) {\n        int k = (i + N - 1) % N;\n        int c =\
    \ side[k] - side[j];\n        event.eb(RP(point[i]), c);\n      }\n\n      if\
    \ (side[i] * side[j] < 0) {\n        RP p = cross_point<REAL>(L, Line<T>(point[i],\
    \ point[j]));\n        int c = side[i] - side[j];\n        event.eb(p, c);\n \
    \     }\n    }\n\n    if (L.b != 0) {\n      sort(all(event), [&](auto& x, auto&\
    \ y) {\n        if (x.fi.x != y.fi.x) return x.fi.x < y.fi.x;\n        return\
    \ x.fi.y < y.fi.y;\n      });\n    } else {\n      sort(all(event), [&](auto&\
    \ x, auto& y) {\n        if (x.fi.y != y.fi.y) return x.fi.y < y.fi.y;\n     \
    \   return x.fi.x < y.fi.x;\n      });\n    }\n\n    vc<Segment<REAL>> ANS;\n\
    \    int in = 0;\n\n    if (allow_perimeter) {\n      int l = 0;\n      FOR(i,\
    \ len(event)) {\n        in += event[i].se;\n        if (i + 1 == len(event) ||\
    \ in == 0) {\n          ANS.eb(event[l].fi, event[i].fi);\n          l = i + 1;\n\
    \        }\n      }\n    } else {\n      FOR(i, len(event)) {\n        in += event[i].se;\n\
    \        if (i + 1 < len(event) && abs(in) == 2) {\n          ANS.eb(event[i].fi,\
    \ event[i + 1].fi);\n        }\n      }\n    }\n\n    assert(in == 0);\n    return\
    \ ANS;\n  }\n\n private:\n  void build() {\n    a = 0;\n    FOR(i, len(point))\
    \ {\n      int j = (i + 1 == len(point) ? 0 : i + 1);\n      a += point[i].det(point[j]);\n\
    \    }\n    if (a < 0) {\n      reverse(all(point));\n      a = -a;\n    }\n \
    \ }\n};\n"
  code: "#include \"geo/base.hpp\"\n#include \"geo/cross_point.hpp\"\n\ntemplate <typename\
    \ T>\nstruct Polygon {\n  vc<Point<T>> point;\n  T a;\n\n  Polygon(vc<Point<T>>\
    \ point) : point(point) { build(); }\n\n  int size() { return len(point); }\n\n\
    \  template <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\n  T\
    \ area_2() { return a; }\n\n  bool is_convex() {\n    FOR(j, len(point)) {\n \
    \     int i = (j == 0 ? len(point) - 1 : j - 1);\n      int k = (j == len(point)\
    \ - 1 ? 0 : j + 1);\n      if ((point[j] - point[i]).det(point[k] - point[j])\
    \ < 0) return false;\n    }\n    return true;\n  }\n\n  // \u4E2D\uFF1A1, \u5883\
    \u754C\uFF1A0, \u5916\uFF1A-1.\n  int side(Point<T> p) {\n    int n = len(point);\n\
    \    FOR(i, n) if (point[i] == p) return 0;\n    FOR(i, n) {\n      Point<T> A\
    \ = point[i], B = point[(i + 1) % n];\n      if ((p - A).det(B - A) != 0) continue;\n\
    \      if ((p - A).dot(B - A) >= 0 && (p - B).dot(A - B) >= 0) return 0;\n   \
    \ }\n    // p \u304B\u3089 x \u65B9\u5411\u306B (+1, +eps) \u65B9\u5411\u306B\u306E\
    \u3073\u308B\u534A\u76F4\u7DDA\u3068\u306E\u4EA4\u5DEE\u3092\u8003\u3048\u308B\
    \n    int cnt = 0;\n    FOR(i, n) {\n      Point<T> A = point[i], B = point[(i\
    \ + 1) % n];\n      FOR(2) {\n        swap(A, B);\n        if (A.y > p.y) continue;\n\
    \        if (B.y <= p.y) continue;\n        if ((A - p).det(B - p) > 0) ++cnt;\n\
    \      }\n    }\n    return (cnt % 2 == 0 ? -1 : 1);\n  }\n\n  // point[i] \u306E\
    \u8FD1\u508D\u3060\u3051\u3067\u898B\u305F side\n  // https://github.com/maspypy/library/blob/main/geo/polygon_side.png\n\
    \  int side_at(int i, Point<T> p) {\n    int n = len(point);\n    p -= point[i];\n\
    \    if (p.x == T(0) && p.y == T(0)) return 0;\n    Point<T> L = point[(i + 1)\
    \ % n] - point[i];\n    Point<T> R = point[(i + n - 1) % n] - point[i];\n    auto\
    \ sgn = [&](T x) -> int {\n      if (x == T(0)) return 0;\n      return (x > T(0)\
    \ ? 1 : -1);\n    };\n    int x = sgn(L.det(p)) + sgn(p.det(R)) + sgn(R.det(L));\n\
    \    if (x == 0) return x;\n    return (x > 0 ? 1 : -1);\n  }\n\n  // \u7DDA\u5206\
    \u304C\u5185\u90E8\u30FB\u5916\u90E8\u305D\u308C\u305E\u308C\u3092\u901A\u308B\
    \u304B\n  // https://atcoder.jp/contests/jag2016-domestic/tasks/jag2016secretspring_e\n\
    \  // https://atcoder.jp/contests/JAG2014Spring/tasks/icpc2014spring_f\n  pair<bool,\
    \ bool> side_segment(Point<T> L, Point<T> R) {\n    Segment<T> S(L, R);\n    //\
    \ \u307E\u305A\u7DDA\u5206\u3068\u975E\u81EA\u660E\u306B\u4EA4\u308F\u308B\u30D1\
    \u30BF\u30FC\u30F3\n    int n = len(point);\n    FOR(i, n) {\n      Segment<T>\
    \ S2(point[i], point[(i + 1) % n]);\n      if (count_cross(S, S2, false) == 1)\
    \ {\n        return {1, 1};\n      }\n    }\n    bool in = 0, out = 0;\n    if\
    \ (side(L) == 1 || side(R) == 1) in = 1;\n    if (side(L) == -1 || side(R) ==\
    \ -1) out = 1;\n    FOR(i, n) {\n      if (!S.contain(point[i])) continue;\n \
    \     for (auto& p : {L, R}) {\n        int k = side_at(i, p);\n        if (k\
    \ == 1) in = 1;\n        if (k == -1) out = 1;\n      }\n    }\n    return {in,\
    \ out};\n  }\n\n  // polygon \u3068 line \u306E\u5171\u901A\u90E8\u5206\u3092\
    \ line \u4E0A\u306E\u533A\u9593\u5217\u3068\u3057\u3066\u8FD4\u3059\u3002\n  //\
    \ return \u3055\u308C\u308B Segment\uFF1A\u9000\u5316\u30B1\u30FC\u30B9\u3082\u3042\
    \u308B\n  // https://codeforces.com/contest/598/problem/F\n  template <typename\
    \ REAL>\n  vc<Segment<REAL>> cross_line(Line<T> L, bool allow_perimeter) {\n \
    \   static_assert(is_integral_v<T>);\n    using RP = Point<REAL>;\n    int N =\
    \ len(point);\n    vc<int> side(N);\n    auto sgn = [&](T x) -> int { return (x\
    \ > 0 ? 1 : x < 0 ? -1 : 0); };\n\n    FOR(i, N) side[i] = sgn(L.eval(point[i]));\n\
    \    vc<pair<RP, int>> event;\n\n    FOR(i, N) {\n      int j = (i + 1) % N;\n\
    \n      if (side[i] == 0) {\n        int k = (i + N - 1) % N;\n        int c =\
    \ side[k] - side[j];\n        event.eb(RP(point[i]), c);\n      }\n\n      if\
    \ (side[i] * side[j] < 0) {\n        RP p = cross_point<REAL>(L, Line<T>(point[i],\
    \ point[j]));\n        int c = side[i] - side[j];\n        event.eb(p, c);\n \
    \     }\n    }\n\n    if (L.b != 0) {\n      sort(all(event), [&](auto& x, auto&\
    \ y) {\n        if (x.fi.x != y.fi.x) return x.fi.x < y.fi.x;\n        return\
    \ x.fi.y < y.fi.y;\n      });\n    } else {\n      sort(all(event), [&](auto&\
    \ x, auto& y) {\n        if (x.fi.y != y.fi.y) return x.fi.y < y.fi.y;\n     \
    \   return x.fi.x < y.fi.x;\n      });\n    }\n\n    vc<Segment<REAL>> ANS;\n\
    \    int in = 0;\n\n    if (allow_perimeter) {\n      int l = 0;\n      FOR(i,\
    \ len(event)) {\n        in += event[i].se;\n        if (i + 1 == len(event) ||\
    \ in == 0) {\n          ANS.eb(event[l].fi, event[i].fi);\n          l = i + 1;\n\
    \        }\n      }\n    } else {\n      FOR(i, len(event)) {\n        in += event[i].se;\n\
    \        if (i + 1 < len(event) && abs(in) == 2) {\n          ANS.eb(event[i].fi,\
    \ event[i + 1].fi);\n        }\n      }\n    }\n\n    assert(in == 0);\n    return\
    \ ANS;\n  }\n\n private:\n  void build() {\n    a = 0;\n    FOR(i, len(point))\
    \ {\n      int j = (i + 1 == len(point) ? 0 : i + 1);\n      a += point[i].det(point[j]);\n\
    \    }\n    if (a < 0) {\n      reverse(all(point));\n      a = -a;\n    }\n \
    \ }\n};"
  dependsOn:
  - geo/base.hpp
  - geo/cross_point.hpp
  - geo/convex_hull.hpp
  isVerificationFile: false
  path: geo/polygon.hpp
  requiredBy: []
  timestamp: '2026-09-22 16:20:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/polygon.hpp
layout: document
redirect_from:
- /library/geo/polygon.hpp
- /library/geo/polygon.hpp.html
title: geo/polygon.hpp
---
