---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':x:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/convex_polygon_side.test.cpp
    title: test/1_mytest/convex_polygon_side.test.cpp
  - icon: ':x:'
    path: test/1_mytest/convex_polygon_visible_range.test.cpp
    title: test/1_mytest/convex_polygon_visible_range.test.cpp
  - icon: ':x:'
    path: test/1_mytest/max_dot.test.cpp
    title: test/1_mytest/max_dot.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
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
    \ REAL, typename T, typename U>\nREAL distance(Point<T> A, Point<U> B) {\n  REAL\
    \ dx = REAL(A.x) - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx\
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
    \ dx * dx + dy * dy <= r * r;\n  }\n};\n#line 1 \"geo/convex_hull.hpp\"\n\n#line\
    \ 1 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n  T x, y;\n\n  Point()\
    \ : x(0), y(0) {}\n\n  template <typename A, typename B>\n  Point(A x, B y) :\
    \ x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A, B> p)\
    \ : x(p.fi), y(p.se) {}\n\n  template <typename U>\n  Point(Point<U> p) : x(p.x),\
    \ y(p.y) {\n    static_assert(!is_integral_v<T> || is_integral_v<U>);\n  }\n\n\
    \  Point operator+=(const Point p) {\n    x += p.x, y += p.y;\n    return *this;\n\
    \  }\n  Point operator-=(const Point p) {\n    x -= p.x, y -= p.y;\n    return\
    \ *this;\n  }\n  Point operator+(Point p) const { return {x + p.x, y + p.y}; }\n\
    \  Point operator-(Point p) const { return {x - p.x, y - p.y}; }\n  bool operator==(Point\
    \ p) const { return x == p.x && y == p.y; }\n  bool operator!=(Point p) const\
    \ { return x != p.x || y != p.y; }\n  Point operator-() const { return {-x, -y};\
    \ }\n  Point operator*(T t) const { return {x * t, y * t}; }\n  Point operator/(T\
    \ t) const { return {x / t, y / t}; }\n\n  bool operator<(Point p) const {\n \
    \   if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(const Point&\
    \ other) const { return x * other.x + y * other.y; }\n  T det(const Point& other)\
    \ const { return x * other.y - y * other.x; }\n\n  double norm() { return sqrtl(x\
    \ * x + y * y); }\n  double angle() { return atan2(y, x); }\n\n  Point rotate(double\
    \ theta) {\n    static_assert(!is_integral<T>::value);\n    double c = cos(theta),\
    \ s = sin(theta);\n    return Point{c * x - s * y, s * x + c * y};\n  }\n  Point\
    \ rot90(bool ccw) { return (ccw ? Point{-y, x} : Point{y, -x}); }\n};\n\n#ifdef\
    \ FASTIO\ntemplate <typename T>\nvoid rd(Point<T>& p) {\n  fastio::rd(p.x), fastio::rd(p.y);\n\
    }\ntemplate <typename T>\nvoid wt(Point<T>& p) {\n  fastio::wt(p.x);\n  fastio::wt('\
    \ ');\n  fastio::wt(p.y);\n}\n#endif\n\n// A -> B -> C \u3068\u9032\u3080\u3068\
    \u304D\u306B\u3001\u5DE6\u306B\u66F2\u304C\u308B\u306A\u3089\u3070 +1\u3001\u53F3\
    \u306B\u66F2\u304C\u308B\u306A\u3089\u3070 -1\ntemplate <typename T>\nint ccw(Point<T>\
    \ A, Point<T> B, Point<T> C) {\n  T x = (B - A).det(C - A);\n  if (x > 0) return\
    \ 1;\n  if (x < 0) return -1;\n  return 0;\n}\n\ntemplate <typename REAL, typename\
    \ T, typename U>\nREAL distance(Point<T> A, Point<U> B) {\n  REAL dx = REAL(A.x)\
    \ - REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx * dx + dy\
    \ * dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\
    \n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B)\
    \ {\n    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n  }\n  Line(T\
    \ x1, T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template\
    \ <typename U>\n  U eval(Point<U> P) {\n    return U(a) * P.x + U(b) * P.y + U(c);\n\
    \  }\n\n  template <typename U>\n  T eval(U x, U y) {\n    return a * x + b *\
    \ y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\u540C\u3058 a,b,c \u3067\u8868\
    \u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\u308B\n  void normalize() {\n\
    \    static_assert(is_same_v<T, int> || is_same_v<T, long long>);\n    T g = gcd(gcd(abs(a),\
    \ abs(b)), abs(c));\n    a /= g, b /= g, c /= g;\n    if (b < 0) {\n      a =\
    \ -a, b = -b, c = -c;\n    }\n    if (b == 0 && a < 0) {\n      a = -a, b = -b,\
    \ c = -c;\n    }\n  }\n\n  bool is_parallel(Line other) { return a * other.b -\
    \ b * other.a == 0; }\n  bool is_orthogonal(Line other) { return a * other.a +\
    \ b * other.b == 0; }\n  bool is_same(Line other) {\n    if (a * other.b != b\
    \ * other.a) return 0;\n    if (a * other.c != c * other.a) return 0;\n    if\
    \ (b * other.c != c * other.b) return 0;\n    return 1;\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B)\
    \ : A(A), B(B) {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  bool contain(Point<T> C) {\n    T det = (C -\
    \ A).det(B - A);\n    if (det != 0) return 0;\n    return (C - A).dot(B - A) >=\
    \ 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_line() { return Line(A, B);\
    \ }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL\
    \ r;\n  Circle() {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL\
    \ x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n#line 3 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\
    \u540C\u4E00\u5EA7\u6A19\u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\
    \n// full \u306A\u3089 I[0] \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate\
    \ <typename T, bool allow_180 = false>\nvector<int> convex_hull(vector<Point<T>>&\
    \ XY, string mode = \"full\",\n                        bool sorted = false) {\n\
    \  assert(mode == \"full\" || mode == \"lower\" || mode == \"upper\");\n  ll N\
    \ = XY.size();\n  if (N == 1) return {0};\n  if (N == 2) {\n    if (XY[0] < XY[1])\
    \ return {0, 1};\n    if (XY[1] < XY[0]) return {1, 0};\n    return {0};\n  }\n\
    \  vc<int> I(N);\n  if (sorted) {\n    FOR(i, N) I[i] = i;\n  } else {\n    I\
    \ = argsort(XY);\n  }\n  if constexpr (allow_180) {\n    FOR(i, N - 1) assert(XY[i]\
    \ != XY[i + 1]);\n  }\n\n  auto check = [&](ll i, ll j, ll k) -> bool {\n    T\
    \ det = (XY[j] - XY[i]).det(XY[k] - XY[i]);\n    if constexpr (allow_180) return\
    \ det >= 0;\n    return det > T(0);\n  };\n\n  auto calc = [&]() {\n    vector<int>\
    \ P;\n    for (auto&& k : I) {\n      while (P.size() > 1) {\n        auto i =\
    \ P[P.size() - 2];\n        auto j = P[P.size() - 1];\n        if (check(i, j,\
    \ k)) break;\n        P.pop_back();\n      }\n      P.eb(k);\n    }\n    return\
    \ P;\n  };\n\n  vc<int> P;\n  if (mode == \"full\" || mode == \"lower\") {\n \
    \   vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"\
    full\" || mode == \"upper\") {\n    if (!P.empty()) P.pop_back();\n    reverse(all(I));\n\
    \    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n  if (mode == \"\
    upper\") reverse(all(P));\n  while (len(P) >= 2 && XY[P[0]] == XY[P.back()]) P.pop_back();\n\
    \  return P;\n}\n#line 3 \"geo/convex_polygon.hpp\"\n\n// strict: n>=3 \u306E\u53CD\
    \u6642\u8A08\u56DE\u308A\u72ED\u7FA9\u51F8\u591A\u89D2\u5F62\u3002\n// non-strict:\
    \ n=1 \u306E\u70B9\u3001n=2 \u306E\u7DDA\u5206\u3001\u307E\u305F\u306F n>=3 \u306E\
    \u53CD\u6642\u8A08\u56DE\u308A\u51F8\u591A\u89D2\u5F62\u3002\ntemplate <typename\
    \ T, bool is_strict = true>\nstruct Convex_Polygon {\n  using P = Point<T>;\n\
    \  int n;\n  vc<P> point;\n  T area2;\n\n  Convex_Polygon(vc<P> point_) : n(len(point_)),\
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
    \ \u306F\u6700\u9069\u8FBA i -> j\u3002\n  tuple<T, int, int> min_dot(P p) const\
    \ {\n    static_assert(is_strict);\n    assert(p != P(0, 0));\n    int idx = periodic_min_comp(\n\
    \        [&](int i, int j) { return point[i].dot(p) < point[j].dot(p); });\n \
    \   T val = point[idx].dot(p);\n    int prv = prev_idx(idx), nxt = nxt_idx(idx);\n\
    \    if (point[prv].dot(p) == val) return {val, prv, idx};\n    if (point[nxt].dot(p)\
    \ == val) return {val, idx, nxt};\n    return {val, idx, idx};\n  }\n\n  // return\
    \ {max, i, j}. i==j \u306F\u9802\u70B9, i!=j \u306F\u6700\u9069\u8FBA i -> j\u3002\
    \n  tuple<T, int, int> max_dot(P p) const {\n    static_assert(is_strict);\n \
    \   assert(p != P(0, 0));\n    int idx = periodic_min_comp(\n        [&](int i,\
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
    \ 0<=s<1.\n  // \u8FBA\u3068\u91CD\u306A\u308B\u5834\u5408\u306F\u3001\u305D\u306E\
    \u8FBA\u306E\u4E21\u7AEF\u70B9\u3092\u8FD4\u3059.\n  template <typename REAL>\n\
    \  vc<tuple<REAL, int, REAL>> boundary_cross_line(P A, P B) const {\n    static_assert(is_strict);\n\
    \    assert(A != B);\n    int cnt = count_boundary_cross_line(A, B);\n    if (cnt\
    \ == 0) return {};\n\n    P D = B - A;\n    P normal(-D.y, D.x);\n    auto [min_value,\
    \ min_i, min_j] = min_dot(normal);\n    auto [max_value, max_i, max_j] = max_dot(normal);\n\
    \    T lo = min_value - normal.dot(A);\n\n    auto vertex_data = [&](int i) ->\
    \ tuple<REAL, int, REAL> {\n      REAL t = (D.x != T(0) ? REAL(point[i].x - A.x)\
    \ / REAL(D.x)\n                            : REAL(point[i].y - A.y) / REAL(D.y));\n\
    \      return {t, i, REAL(0)};\n    };\n    if (cnt == infty<int>) {\n      int\
    \ i = (lo == T(0) ? min_i : max_i);\n      int j = (lo == T(0) ? min_j : max_j);\n\
    \      assert(j == nxt_idx(i));\n      vc<tuple<REAL, int, REAL>> ans = {vertex_data(i),\
    \ vertex_data(j)};\n      if (get<0>(ans[1]) < get<0>(ans[0])) swap(ans[0], ans[1]);\n\
    \      return ans;\n    }\n    if (cnt == 1) return {lo == T(0) ? vertex_data(min_i)\
    \ : vertex_data(max_i)};\n\n    auto eval = [&](int i) -> T {\n      return normal.dot(point[i\
    \ % n]) - normal.dot(A);\n    };\n    int a = min_i, b = max_i;\n    if (b < a)\
    \ b += n;\n    int p = binary_search([&](int i) { return eval(i) < T(0); }, a,\
    \ b);\n    int q = binary_search([&](int i) { return eval(i) > T(0); }, b, a +\
    \ n);\n    auto edge_data = [&](int eid) -> tuple<REAL, int, REAL> {\n      int\
    \ j = nxt_idx(eid);\n      T x = eval(eid), y = eval(eid + 1);\n      if (x ==\
    \ T(0)) return vertex_data(eid);\n      if (y == T(0)) return vertex_data(j);\n\
    \      assert((x < T(0) && T(0) < y) || (y < T(0) && T(0) < x));\n\n      P E\
    \ = point[eid];\n      P F = point[j] - E;\n      T den = D.det(F);\n      assert(den\
    \ != T(0));\n\n      REAL t = REAL((E - A).det(F)) / REAL(den);\n      REAL s\
    \ = REAL((E - A).det(D)) / REAL(den);\n\n      return {t, eid, s};\n    };\n \
    \   vc<tuple<REAL, int, REAL>> ans = {edge_data(p % n), edge_data(q % n)};\n \
    \   if (get<0>(ans[1]) < get<0>(ans[0])) swap(ans[0], ans[1]);\n    return ans;\n\
    \  }\n\n  T area_between(int i, int j) const {\n    assert(i <= j && j <= i +\
    \ n);\n    if (j == i + n) return area2;\n    i %= n, j %= n;\n    if (i > j)\
    \ j += n;\n    if (AREA.empty()) build_AREA();\n    return AREA[j] - AREA[i] +\
    \ point[j % n].det(point[i]);\n  }\n\n  T left_area(Line<T> L) const {\n    static_assert(is_strict);\n\
    \    static_assert(is_same<T, double>::value || is_same<T, long double>::value);\n\
    \    Point<T> normal(L.a, L.b);\n    auto [min_value, a, min_j] = min_dot(normal);\n\
    \    auto [max_value, b, max_j] = max_dot(normal);\n    if (b < a) b += n;\n \
    \   assert(L.eval(point[a % n]) < 0 && L.eval(point[b % n]) > 0);\n    int p =\n\
    \        binary_search([&](int i) { return L.eval(point[i % n]) < 0; }, a, b);\n\
    \    int q = binary_search(\n        [&](int i) { return L.eval(point[i % n])\
    \ > 0; }, b, a + n);\n    T s = L.eval(point[p % n]) /\n          (L.eval(point[p\
    \ % n]) - L.eval(point[(p + 1) % n]));\n    T t = L.eval(point[q % n]) /\n   \
    \       (L.eval(point[q % n]) - L.eval(point[(q + 1) % n]));\n    P A = point[p\
    \ % n], B = point[(p + 1) % n];\n    P C = point[q % n], D = point[(q + 1) % n];\n\
    \    P X = B * s + A * (1 - s), Y = D * t + C * (1 - t);\n    T ans = area_between(p,\
    \ q);\n    ans -= (A - C).det(X - C);\n    ans += (Y - C).det(X - C);\n    return\
    \ ans;\n  }\n\n private:\n  mutable vc<T> AREA;\n\n  void build_AREA() const {\n\
    \    AREA.resize(2 * n);\n    FOR(i, n) AREA[n + i] = AREA[i] = point[i].det(point[nxt_idx(i)]);\n\
    \    AREA = cumsum<T>(AREA);\n  }\n};\n"
  code: "#include \"geo/base.hpp\"\n#include \"geo/convex_hull.hpp\"\n\n// strict:\
    \ n>=3 \u306E\u53CD\u6642\u8A08\u56DE\u308A\u72ED\u7FA9\u51F8\u591A\u89D2\u5F62\
    \u3002\n// non-strict: n=1 \u306E\u70B9\u3001n=2 \u306E\u7DDA\u5206\u3001\u307E\
    \u305F\u306F n>=3 \u306E\u53CD\u6642\u8A08\u56DE\u308A\u51F8\u591A\u89D2\u5F62\
    \u3002\ntemplate <typename T, bool is_strict = true>\nstruct Convex_Polygon {\n\
    \  using P = Point<T>;\n  int n;\n  vc<P> point;\n  T area2;\n\n  Convex_Polygon(vc<P>\
    \ point_) : n(len(point_)), point(point_) {\n    assert(n >= 1);\n    if constexpr\
    \ (is_strict) assert(n >= 3);\n    area2 = 0;\n    FOR(i, n) {\n      int j =\
    \ nxt_idx(i);\n      if (n >= 2) assert(point[i] != point[j]);\n      area2 +=\
    \ point[i].det(point[j]);\n    }\n    assert(area2 >= T(0));\n    if (n >= 3)\
    \ assert(area2 > T(0));\n    if (n >= 3) FOR(i, n) {\n        int j = nxt_idx(i),\
    \ k = nxt_idx(j);\n        T det = (point[j] - point[i]).det(point[k] - point[i]);\n\
    \        if constexpr (is_strict)\n          assert(det > T(0));\n        else\n\
    \          assert(det >= T(0));\n      }\n  }\n\n  template <typename F>\n  int\
    \ periodic_min_comp(F comp) const {\n    static_assert(is_strict);\n    int L\
    \ = 0, M = n, R = n + n;\n    while (R - L != 2) {\n      int L1 = (L + M) / 2,\
    \ R1 = (M + R + 1) / 2;\n      if (comp(L1 % n, M % n)) R = M, M = L1;\n     \
    \ elif (comp(R1 % n, M % n)) L = M, M = R1;\n      else L = L1, R = R1;\n    }\n\
    \    return M % n;\n  }\n\n  int nxt_idx(int i) const { return (i + 1 == n ? 0\
    \ : i + 1); }\n  int prev_idx(int i) const { return (i == 0 ? n - 1 : i - 1);\
    \ }\n\n  // \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1.\n  int side(P\
    \ p) const {\n    if (n == 1) return (p == point[0] ? 0 : -1);\n    if (n == 2)\
    \ {\n      P A = point[0], B = point[1];\n      if ((B - A).det(p - A) == 0 &&\
    \ (B - A).dot(p - A) >= 0 &&\n          (A - B).dot(p - B) >= 0)\n        return\
    \ 0;\n      return -1;\n    }\n    int L = 1, R = n - 1;\n    T a = (point[L]\
    \ - point[0]).det(p - point[0]);\n    T b = (point[R] - point[0]).det(p - point[0]);\n\
    \    if (a < 0 || b > 0) return -1;\n    while (R - L >= 2) {\n      int M = (L\
    \ + R) / 2;\n      T c = (point[M] - point[0]).det(p - point[0]);\n      if (c\
    \ < 0)\n        R = M, b = c;\n      else\n        L = M, a = c;\n    }\n    T\
    \ c = (point[R] - point[L]).det(p - point[L]);\n    T x = min({a, -b, c});\n \
    \   if (x < 0) return -1;\n    if (x > 0) return 1;\n    if (p == point[0]) return\
    \ 0;\n    if (c != 0 && a == 0 && L != 1) return 1;\n    if (c != 0 && b == 0\
    \ && R != n - 1) return 1;\n    return 0;\n  }\n\n  // return {min, i, j}. i==j\
    \ \u306F\u9802\u70B9, i!=j \u306F\u6700\u9069\u8FBA i -> j\u3002\n  tuple<T, int,\
    \ int> min_dot(P p) const {\n    static_assert(is_strict);\n    assert(p != P(0,\
    \ 0));\n    int idx = periodic_min_comp(\n        [&](int i, int j) { return point[i].dot(p)\
    \ < point[j].dot(p); });\n    T val = point[idx].dot(p);\n    int prv = prev_idx(idx),\
    \ nxt = nxt_idx(idx);\n    if (point[prv].dot(p) == val) return {val, prv, idx};\n\
    \    if (point[nxt].dot(p) == val) return {val, idx, nxt};\n    return {val, idx,\
    \ idx};\n  }\n\n  // return {max, i, j}. i==j \u306F\u9802\u70B9, i!=j \u306F\u6700\
    \u9069\u8FBA i -> j\u3002\n  tuple<T, int, int> max_dot(P p) const {\n    static_assert(is_strict);\n\
    \    assert(p != P(0, 0));\n    int idx = periodic_min_comp(\n        [&](int\
    \ i, int j) { return point[i].dot(p) > point[j].dot(p); });\n    T val = point[idx].dot(p);\n\
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
    \ 0<=s<1.\n  // \u8FBA\u3068\u91CD\u306A\u308B\u5834\u5408\u306F\u3001\u305D\u306E\
    \u8FBA\u306E\u4E21\u7AEF\u70B9\u3092\u8FD4\u3059.\n  template <typename REAL>\n\
    \  vc<tuple<REAL, int, REAL>> boundary_cross_line(P A, P B) const {\n    static_assert(is_strict);\n\
    \    assert(A != B);\n    int cnt = count_boundary_cross_line(A, B);\n    if (cnt\
    \ == 0) return {};\n\n    P D = B - A;\n    P normal(-D.y, D.x);\n    auto [min_value,\
    \ min_i, min_j] = min_dot(normal);\n    auto [max_value, max_i, max_j] = max_dot(normal);\n\
    \    T lo = min_value - normal.dot(A);\n\n    auto vertex_data = [&](int i) ->\
    \ tuple<REAL, int, REAL> {\n      REAL t = (D.x != T(0) ? REAL(point[i].x - A.x)\
    \ / REAL(D.x)\n                            : REAL(point[i].y - A.y) / REAL(D.y));\n\
    \      return {t, i, REAL(0)};\n    };\n    if (cnt == infty<int>) {\n      int\
    \ i = (lo == T(0) ? min_i : max_i);\n      int j = (lo == T(0) ? min_j : max_j);\n\
    \      assert(j == nxt_idx(i));\n      vc<tuple<REAL, int, REAL>> ans = {vertex_data(i),\
    \ vertex_data(j)};\n      if (get<0>(ans[1]) < get<0>(ans[0])) swap(ans[0], ans[1]);\n\
    \      return ans;\n    }\n    if (cnt == 1) return {lo == T(0) ? vertex_data(min_i)\
    \ : vertex_data(max_i)};\n\n    auto eval = [&](int i) -> T {\n      return normal.dot(point[i\
    \ % n]) - normal.dot(A);\n    };\n    int a = min_i, b = max_i;\n    if (b < a)\
    \ b += n;\n    int p = binary_search([&](int i) { return eval(i) < T(0); }, a,\
    \ b);\n    int q = binary_search([&](int i) { return eval(i) > T(0); }, b, a +\
    \ n);\n    auto edge_data = [&](int eid) -> tuple<REAL, int, REAL> {\n      int\
    \ j = nxt_idx(eid);\n      T x = eval(eid), y = eval(eid + 1);\n      if (x ==\
    \ T(0)) return vertex_data(eid);\n      if (y == T(0)) return vertex_data(j);\n\
    \      assert((x < T(0) && T(0) < y) || (y < T(0) && T(0) < x));\n\n      P E\
    \ = point[eid];\n      P F = point[j] - E;\n      T den = D.det(F);\n      assert(den\
    \ != T(0));\n\n      REAL t = REAL((E - A).det(F)) / REAL(den);\n      REAL s\
    \ = REAL((E - A).det(D)) / REAL(den);\n\n      return {t, eid, s};\n    };\n \
    \   vc<tuple<REAL, int, REAL>> ans = {edge_data(p % n), edge_data(q % n)};\n \
    \   if (get<0>(ans[1]) < get<0>(ans[0])) swap(ans[0], ans[1]);\n    return ans;\n\
    \  }\n\n  T area_between(int i, int j) const {\n    assert(i <= j && j <= i +\
    \ n);\n    if (j == i + n) return area2;\n    i %= n, j %= n;\n    if (i > j)\
    \ j += n;\n    if (AREA.empty()) build_AREA();\n    return AREA[j] - AREA[i] +\
    \ point[j % n].det(point[i]);\n  }\n\n  T left_area(Line<T> L) const {\n    static_assert(is_strict);\n\
    \    static_assert(is_same<T, double>::value || is_same<T, long double>::value);\n\
    \    Point<T> normal(L.a, L.b);\n    auto [min_value, a, min_j] = min_dot(normal);\n\
    \    auto [max_value, b, max_j] = max_dot(normal);\n    if (b < a) b += n;\n \
    \   assert(L.eval(point[a % n]) < 0 && L.eval(point[b % n]) > 0);\n    int p =\n\
    \        binary_search([&](int i) { return L.eval(point[i % n]) < 0; }, a, b);\n\
    \    int q = binary_search(\n        [&](int i) { return L.eval(point[i % n])\
    \ > 0; }, b, a + n);\n    T s = L.eval(point[p % n]) /\n          (L.eval(point[p\
    \ % n]) - L.eval(point[(p + 1) % n]));\n    T t = L.eval(point[q % n]) /\n   \
    \       (L.eval(point[q % n]) - L.eval(point[(q + 1) % n]));\n    P A = point[p\
    \ % n], B = point[(p + 1) % n];\n    P C = point[q % n], D = point[(q + 1) % n];\n\
    \    P X = B * s + A * (1 - s), Y = D * t + C * (1 - t);\n    T ans = area_between(p,\
    \ q);\n    ans -= (A - C).det(X - C);\n    ans += (Y - C).det(X - C);\n    return\
    \ ans;\n  }\n\n private:\n  mutable vc<T> AREA;\n\n  void build_AREA() const {\n\
    \    AREA.resize(2 * n);\n    FOR(i, n) AREA[n + i] = AREA[i] = point[i].det(point[nxt_idx(i)]);\n\
    \    AREA = cumsum<T>(AREA);\n  }\n};\n"
  dependsOn:
  - geo/base.hpp
  - geo/convex_hull.hpp
  isVerificationFile: false
  path: geo/convex_polygon.hpp
  requiredBy: []
  timestamp: '2026-09-24 22:40:16+09:00'
  verificationStatus: LIBRARY_ALL_WA
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
