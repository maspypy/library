---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convex/line_min_function.hpp
    title: convex/line_min_function.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/convex_hull.hpp
    title: geo/convex_hull.hpp
  - icon: ':question:'
    path: mod/floor_sum_of_linear.hpp
    title: mod/floor_sum_of_linear.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp
    title: test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geo/convex_hull.hpp\"\n\n#line 2 \"geo/base.hpp\"\ntemplate\
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
    \ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle(Point<REAL>\
    \ O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL r) : O(x, y), r(r)\
    \ {}\n  template <typename T>\n  bool contain(Point<T> p) {\n    REAL dx = p.x\
    \ - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r * r;\n  }\n};\n#line\
    \ 4 \"geo/convex_hull.hpp\"\n\n// allow_180=true \u3067\u540C\u4E00\u5EA7\u6A19\
    \u70B9\u304C\u3042\u308B\u3068\u3053\u308F\u308C\u308B\n// full \u306A\u3089 I[0]\
    \ \u304C sorted \u3067 min \u306B\u306A\u308B\ntemplate <typename T, bool allow_180\
    \ = false>\nvector<int> ConvexHull(vector<Point<T>>& XY, string mode = \"full\"\
    , bool sorted = false) {\n  assert(mode == \"full\" || mode == \"lower\" || mode\
    \ == \"upper\");\n  ll N = XY.size();\n  if (N == 1) return {0};\n  if (N == 2)\
    \ {\n    if (XY[0] < XY[1]) return {0, 1};\n    if (XY[1] < XY[0]) return {1,\
    \ 0};\n    return {0};\n  }\n  vc<int> I(N);\n  if (sorted) {\n    FOR(i, N) I[i]\
    \ = i;\n  } else {\n    I = argsort(XY);\n  }\n  if constexpr (allow_180) { FOR(i,\
    \ N - 1) assert(XY[i] != XY[i + 1]); }\n\n  auto check = [&](ll i, ll j, ll k)\
    \ -> bool {\n    T det = (XY[j] - XY[i]).det(XY[k] - XY[i]);\n    if constexpr\
    \ (allow_180) return det >= 0;\n    return det > T(0);\n  };\n\n  auto calc =\
    \ [&]() {\n    vector<int> P;\n    for (auto&& k: I) {\n      while (P.size()\
    \ > 1) {\n        auto i = P[P.size() - 2];\n        auto j = P[P.size() - 1];\n\
    \        if (check(i, j, k)) break;\n        P.pop_back();\n      }\n      P.eb(k);\n\
    \    }\n    return P;\n  };\n\n  vc<int> P;\n  if (mode == \"full\" || mode ==\
    \ \"lower\") {\n    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n  }\n\
    \  if (mode == \"full\" || mode == \"upper\") {\n    if (!P.empty()) P.pop_back();\n\
    \    reverse(all(I));\n    vc<int> Q = calc();\n    P.insert(P.end(), all(Q));\n\
    \  }\n  if (mode == \"upper\") reverse(all(P));\n  while (len(P) >= 2 && XY[P[0]]\
    \ == XY[P.back()]) P.pop_back();\n  return P;\n}\n#line 2 \"convex/line_min_function.hpp\"\
    \n\n// 1 \u6B21\u95A2\u6570\u306E max \u3092 [L,R,a,b] \u306E\u5217\u3068\u3057\
    \u3066\u51FA\u529B\n// https://qoj.ac/contest/1576/problem/8505\ntemplate <typename\
    \ Re, typename T>\nvc<tuple<Re, Re, Re, Re>> line_min_function_real(vc<pair<T,\
    \ T>> LINE) {\n  assert(!LINE.empty());\n  using P = Point<T>;\n  vc<P> point;\n\
    \  for (auto& [x, y]: LINE) point.eb(P(x, y));\n  auto I = ConvexHull(point, \"\
    lower\");\n  point = rearrange(point, I);\n  int N = len(point);\n  if (N >= 2\
    \ && point[N - 1].x == point[N - 2].x) { POP(point), --N; }\n  reverse(all(point));\
    \ // \u50BE\u304D\u306F\u5927\u304D\u3044\u65B9\u304B\u3089\n  Re l = -infty<Re>;\n\
    \  vc<tuple<Re, Re, Re, Re>> ANS;\n  FOR(i, N) {\n    Re r = infty<Re>;\n    auto\
    \ [a, b] = point[i];\n    if (i + 1 < N) {\n      auto [c, d] = point[i + 1];\n\
    \      if (a == c) continue;\n      assert(a > c);\n      r = Re(d - b) / (a -\
    \ c);\n      chmax(r, l), chmin(r, infty<Re>);\n    }\n    if (l < r) ANS.eb(l,\
    \ r, a, b), l = r;\n  }\n  return ANS;\n}\n\n// 1 \u6B21\u95A2\u6570\u306E max\
    \ \u3092 [L,R,a,b] \u306E\u5217\u3068\u3057\u3066\u51FA\u529B\ntemplate <typename\
    \ Re, typename T>\nvc<tuple<Re, Re, Re, Re>> line_max_function_real(vc<pair<T,\
    \ T>> LINE) {\n  assert(!LINE.empty());\n  for (auto& [a, b]: LINE) a = -a, b\
    \ = -b;\n  auto ANS = line_min_function_real<Re, T>(LINE);\n  for (auto& [l, r,\
    \ a, b]: ANS) a = -a, b = -b;\n  return ANS;\n}\n\n// LINE(a,b,c): y=(ax+b)/c,\
    \ \u8A55\u4FA1\u70B9\u306F\u6574\u6570\n// 1 \u6B21\u95A2\u6570\u306E min \u3092\
    \ [L,R,a,b,c] \u306E\u5217\u3068\u3057\u3066\u51FA\u529B\n// \u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u5B89\u5168\nvc<tuple<ll, ll, ll, ll, ll>> line_min_function_rational(vc<tuple<ll,\
    \ ll, ll>> LINE, ll L, ll R) {\n  // \u50BE\u304D\u964D\u9806\n  sort(all(LINE),\
    \ [&](auto& L, auto& R) -> bool {\n    auto& [a1, b1, c1] = L;\n    auto& [a2,\
    \ b2, c2] = R;\n    return i128(a1) * c2 > i128(a2) * c1;\n  });\n  vc<tuple<ll,\
    \ ll, ll, ll, ll>> ANS;\n  for (auto& [a2, b2, c2]: LINE) {\n    while (1) {\n\
    \      if (ANS.empty()) {\n        ANS.eb(L, R, a2, b2, c2);\n        break;\n\
    \      }\n      auto& [L1, R1, a1, b1, c1] = ANS.back();\n      i128 s = i128(c2)\
    \ * a1 - i128(a2) * c1; // >= 0\n      i128 t = i128(b2) * c1 - i128(b1) * c2;\n\
    \      if (s == 0) {\n        // \u5E73\u884C\u306A\u306E\u3067\u5C0F\u3055\u3044\
    \u65B9\u3060\u3051\u3092\u6B8B\u3059\n        if (t >= 0) break;\n        ANS.pop_back();\n\
    \        if (len(ANS)) get<1>(ANS.back()) = R;\n        continue;\n      }\n \
    \     i128 x = ceil<i128>(t, s);\n      // x \u4EE5\u4E0A\u3067 2 \u306E\u65B9\
    \u304C\u4E0B\u306B\u6765\u308B\n      if (x <= L1) {\n        ANS.pop_back();\n\
    \        continue;\n      }\n      if (x < R) {\n        R1 = x;\n        ANS.eb(x,\
    \ R, a2, b2, c2);\n        break;\n      } else {\n        break;\n      }\n \
    \   }\n  }\n  return ANS;\n}\n\n// LINE(a,b,c): y=(ax+b)/c, \u8A55\u4FA1\u70B9\
    \u306F\u6574\u6570\n// 1 \u6B21\u95A2\u6570\u306E max \u3092 [L,R,a,b,c] \u306E\
    \u5217\u3068\u3057\u3066\u51FA\u529B\n// \u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u5B89\u5168\nvc<tuple<ll, ll, ll, ll, ll>> line_max_function_rational(vc<tuple<ll,\
    \ ll, ll>> LINE, ll L, ll R) {\n  for (auto& [a, b, c]: LINE) a = -a, b = -b;\n\
    \  auto ANS = line_min_function_rational(LINE, L, R);\n  for (auto& [L, R, a,\
    \ b, c]: ANS) a = -a, b = -b;\n  return ANS;\n}\n\n// LINE(a,b): y=ax+b, \u8A55\
    \u4FA1\u70B9\u306F\u6574\u6570\n// 1 \u6B21\u95A2\u6570\u306E min \u3092 [L,R,a,b]\
    \ \u306E\u5217\u3068\u3057\u3066\u51FA\u529B\n// \u30AA\u30FC\u30D0\u30FC\u30D5\
    \u30ED\u30FC\u5B89\u5168\nvc<tuple<ll, ll, ll, ll>> line_min_function_integer(vc<pair<ll,\
    \ ll>> LINE, ll L, ll R) {\n  // \u50BE\u304D\u964D\u9806\n  sort(all(LINE), [&](auto&\
    \ L, auto& R) -> bool {\n    auto& [a1, b1] = L;\n    auto& [a2, b2] = R;\n  \
    \  return a1 > a2;\n  });\n  vc<tuple<ll, ll, ll, ll>> ANS;\n  for (auto& [a2,\
    \ b2]: LINE) {\n    while (1) {\n      if (ANS.empty()) {\n        ANS.eb(L, R,\
    \ a2, b2);\n        break;\n      }\n      auto& [L1, R1, a1, b1] = ANS.back();\n\
    \      if (a1 == a2) {\n        if (b1 <= b2) break;\n        ANS.pop_back();\n\
    \        if (len(ANS)) get<1>(ANS.back()) = R;\n        continue;\n      }\n \
    \     ll x = ceil<ll>(b2 - b1, a1 - a2);\n      // x \u4EE5\u4E0A\u3067 2 \u306E\
    \u65B9\u304C\u4E0B\u306B\u6765\u308B\n      if (x <= L1) {\n        ANS.pop_back();\n\
    \        continue;\n      }\n      if (x < R) {\n        R1 = x;\n        ANS.eb(x,\
    \ R, a2, b2);\n        break;\n      } else {\n        break;\n      }\n    }\n\
    \  }\n  return ANS;\n}\n\n// LINE(a,b,c): y=(ax+b)/c, \u8A55\u4FA1\u70B9\u306F\
    \u6574\u6570\n// 1 \u6B21\u95A2\u6570\u306E min \u3092 [L,R,a,b,c] \u306E\u5217\
    \u3068\u3057\u3066\u51FA\u529B\n// c>0, (ax+b)c \u304C\u30AA\u30FC\u30D0\u30FC\
    \u30D5\u30ED\u30FC\u3057\u306A\u3044,\nvc<tuple<ll, ll, ll, ll>> line_max_function_integer(vc<pair<ll,\
    \ ll>> LINE, ll L, ll R) {\n  for (auto& [a, b]: LINE) a = -a, b = -b;\n  auto\
    \ ANS = line_min_function_integer(LINE, L, R);\n  for (auto& [L, R, a, b]: ANS)\
    \ a = -a, b = -b;\n  return ANS;\n}\n\n// (L,R,func) \u306E\u4E0B\u5074\u3068\u4E0A\
    \u5074\u3092\u30DE\u30FC\u30B8\u3059\u308B\u3068\u304D\u306A\u3069\u306B\u4F7F\
    \u3046\u7528\ntemplate <typename T>\nvc<tuple<T, T, T, T, T, T>> merge_46(vc<tuple<T,\
    \ T, T, T>> A, vc<tuple<T, T, T, T>> B) {\n  vc<tuple<T, T, T, T, T, T>> ANS;\n\
    \  reverse(all(A));\n  reverse(all(B));\n  while (len(A) && len(B)) {\n    auto&\
    \ [l1, r1, a1, b1] = A.back();\n    auto& [l2, r2, a2, b2] = B.back();\n    assert(l1\
    \ == l2);\n    T r = min(r1, r2);\n    ANS.eb(l1, r, a1, b1, a2, b2);\n    l1\
    \ = r, l2 = r;\n    if (r1 == r) POP(A);\n    if (r2 == r) POP(B);\n  };\n  return\
    \ ANS;\n}\n\n// (L,R,func) \u306E\u4E0B\u5074\u3068\u4E0A\u5074\u3092\u30DE\u30FC\
    \u30B8\u3059\u308B\u3068\u304D\u306A\u3069\u306B\u4F7F\u3046\u7528\n// f(L,R,a1,b1,a2,b2)\n\
    template <typename T, typename F>\nvoid merge_46(const vc<tuple<T, T, T, T>>&\
    \ A, const vc<tuple<T, T, T, T>>& B, F f) {\n  int i = 0, j = 0;\n  while (i <\
    \ len(A) && j < len(B)) {\n    auto& [l1, r1, a1, b1] = A[i];\n    auto& [l2,\
    \ r2, a2, b2] = B[j];\n    T l = max(l1, l2), r = min(r1, r2);\n    if (l < r)\
    \ f(l, r, a1, b1, a2, b2);\n    (r1 < r2 ? i : j)++;\n  }\n}\n\n// (L,R,func)\
    \ \u306E\u4E0B\u5074\u3068\u4E0A\u5074\u3092\u30DE\u30FC\u30B8\u3059\u308B\u3068\
    \u304D\u306A\u3069\u306B\u4F7F\u3046\u7528\n// f(L,R,a1,b1,a2,b2)\ntemplate <typename\
    \ T, typename F>\nvoid merge_58(const vc<tuple<T, T, T, T, T>>& A, const vc<tuple<T,\
    \ T, T, T, T>>& B, F f) {\n  int i = 0, j = 0;\n  while (i < len(A) && j < len(B))\
    \ {\n    auto& [l1, r1, a1, b1, c1] = A[i];\n    auto& [l2, r2, a2, b2, c2] =\
    \ B[j];\n    T l = max(l1, l2), r = min(r1, r2);\n    if (l < r) f(l, r, a1, b1,\
    \ c1, a2, b2, c2);\n    (r1 < r2 ? i : j)++;\n  }\n}\n#line 2 \"mod/floor_sum_of_linear.hpp\"\
    \n\n// sum_{x in [L,R)} floor(ax + b, mod)\n// I \u306F\u7BC4\u56F2\u5185\u3067\
    \ ax+b \u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u7A0B\
    \u5EA6\ntemplate <typename O = i128, typename I = long long>\nO floor_sum_of_linear(I\
    \ L, I R, I a, I b, I mod) {\n  assert(L <= R);\n  O res = 0;\n  b += L * a;\n\
    \  I N = R - L;\n\n  if (b < 0) {\n    I k = ceil(-b, mod);\n    b += k * mod;\n\
    \    res -= O(N) * O(k);\n  }\n\n  while (N) {\n    I q;\n    tie(q, a) = divmod(a,\
    \ mod);\n    res += (N & 1 ? O(N) * O((N - 1) / 2) * O(q) : O(N / 2) * O(N - 1)\
    \ * O(q));\n    if (b >= mod) {\n      tie(q, b) = divmod(b, mod);\n      res\
    \ += O(N) * q;\n    }\n    tie(N, b) = divmod(a * N + b, mod);\n    tie(a, mod)\
    \ = mp(mod, a);\n  }\n  return res;\n}\n#line 3 \"convex/count_lattice_point_in_convex_polygon.hpp\"\
    \n\n// L<=x<R, ax+by<=c \u3068\u3044\u3046\u534A\u5E73\u9762\u305F\u3061\n// \u6709\
    \u754C\u3067\u306A\u3044\u3068\u304D\u306F -1 \u3092\u8FD4\u3059\n// \u5165\u529B\
    \u304C pow(10,18) \u4EE5\u4E0B\u3068\u304B\u3067\u3042\u308C\u3070\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3064\u3082\u308A\ni128 count_lattice_point_in_convex_polygon(ll\
    \ L, ll R, vc<tuple<ll, ll, ll>> LINE) {\n  vc<tuple<ll, ll, ll>> LINE1, LINE2;\n\
    \  for (auto& [a, b, c]: LINE) {\n    if (b == 0) {\n      // ax<=c\n      assert(a\
    \ != 0);\n      if (a > 0) { chmin(R, floor<ll>(c, a) + 1); }\n      elif (a <\
    \ 0) { chmax(L, ceil<ll>(-c, -a)); }\n    } else {\n      if (b > 0) {\n     \
    \   LINE2.eb(-a, c, b);\n      } else {\n        LINE1.eb(a, -c, -b);\n      }\n\
    \    }\n  }\n  if (L >= R) return 0;\n  if (LINE1.empty() || LINE2.empty()) return\
    \ -1;\n\n  auto LOWER = line_max_function_rational(LINE1, L, R);\n  auto UPPER\
    \ = line_min_function_rational(LINE2, L, R);\n\n  i128 ANS = 0;\n\n  auto wk =\
    \ [&](ll L, ll R, ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) -> void {\n    //\
    \ \u4EA4\u70B9 t/s\n    i128 s = i128(a2) * c1 - i128(a1) * c2;\n    i128 t =\
    \ i128(b1) * c2 - i128(b2) * c1;\n    if (s == 0) {\n      if (t > 0) return;\n\
    \    }\n    elif (s > 0) {\n      // \u4E0A\u5074\u306E\u65B9\u304C\u50BE\u304D\
    \u304C\u5927\u304D\u3044\n      i128 x = ceil<i128>(t, s);\n      chmax(L, x);\n\
    \    }\n    else {\n      i128 x = floor<i128>(-t, -s);\n      chmin(R, x + 1);\n\
    \    }\n    if (L >= R) return;\n    ANS += floor_sum_of_linear<i128, i128>(L,\
    \ R, a2, b2, c2);\n    ANS -= floor_sum_of_linear<i128, i128>(L, R, a1, b1 - 1,\
    \ c1);\n  };\n\n  merge_58(LOWER, UPPER, wk);\n\n  // reverse(all(LOWER));\n \
    \ // reverse(all(UPPER));\n  // while (len(LOWER) && len(UPPER)) {\n  //   auto\
    \ [L1, R1, a1, b1, c1] = POP(LOWER);\n  //   auto [L2, R2, a2, b2, c2] = POP(UPPER);\n\
    \  //   assert(L1 == L2);\n  //   ll R = min(R1, R2);\n  //   wk(L1, R, a1, b1,\
    \ c1, a2, b2, c2);\n  //   if (R < R1) LOWER.eb(R, R1, a1, b1, c1);\n  //   if\
    \ (R < R2) UPPER.eb(R, R2, a2, b2, c2);\n  // }\n\n  // for (auto& [L, R, a1,\
    \ b1, c1, a2, b2, c2]: merge_58<ll>(LOWER, UPPER)) { wk(L, R, a1, b1, c1, a2,\
    \ b2, c2); }\n  return ANS;\n}\n"
  code: "#include \"convex/line_min_function.hpp\"\n#include \"mod/floor_sum_of_linear.hpp\"\
    \n\n// L<=x<R, ax+by<=c \u3068\u3044\u3046\u534A\u5E73\u9762\u305F\u3061\n// \u6709\
    \u754C\u3067\u306A\u3044\u3068\u304D\u306F -1 \u3092\u8FD4\u3059\n// \u5165\u529B\
    \u304C pow(10,18) \u4EE5\u4E0B\u3068\u304B\u3067\u3042\u308C\u3070\u30AA\u30FC\
    \u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\u3064\u3082\u308A\ni128 count_lattice_point_in_convex_polygon(ll\
    \ L, ll R, vc<tuple<ll, ll, ll>> LINE) {\n  vc<tuple<ll, ll, ll>> LINE1, LINE2;\n\
    \  for (auto& [a, b, c]: LINE) {\n    if (b == 0) {\n      // ax<=c\n      assert(a\
    \ != 0);\n      if (a > 0) { chmin(R, floor<ll>(c, a) + 1); }\n      elif (a <\
    \ 0) { chmax(L, ceil<ll>(-c, -a)); }\n    } else {\n      if (b > 0) {\n     \
    \   LINE2.eb(-a, c, b);\n      } else {\n        LINE1.eb(a, -c, -b);\n      }\n\
    \    }\n  }\n  if (L >= R) return 0;\n  if (LINE1.empty() || LINE2.empty()) return\
    \ -1;\n\n  auto LOWER = line_max_function_rational(LINE1, L, R);\n  auto UPPER\
    \ = line_min_function_rational(LINE2, L, R);\n\n  i128 ANS = 0;\n\n  auto wk =\
    \ [&](ll L, ll R, ll a1, ll b1, ll c1, ll a2, ll b2, ll c2) -> void {\n    //\
    \ \u4EA4\u70B9 t/s\n    i128 s = i128(a2) * c1 - i128(a1) * c2;\n    i128 t =\
    \ i128(b1) * c2 - i128(b2) * c1;\n    if (s == 0) {\n      if (t > 0) return;\n\
    \    }\n    elif (s > 0) {\n      // \u4E0A\u5074\u306E\u65B9\u304C\u50BE\u304D\
    \u304C\u5927\u304D\u3044\n      i128 x = ceil<i128>(t, s);\n      chmax(L, x);\n\
    \    }\n    else {\n      i128 x = floor<i128>(-t, -s);\n      chmin(R, x + 1);\n\
    \    }\n    if (L >= R) return;\n    ANS += floor_sum_of_linear<i128, i128>(L,\
    \ R, a2, b2, c2);\n    ANS -= floor_sum_of_linear<i128, i128>(L, R, a1, b1 - 1,\
    \ c1);\n  };\n\n  merge_58(LOWER, UPPER, wk);\n\n  // reverse(all(LOWER));\n \
    \ // reverse(all(UPPER));\n  // while (len(LOWER) && len(UPPER)) {\n  //   auto\
    \ [L1, R1, a1, b1, c1] = POP(LOWER);\n  //   auto [L2, R2, a2, b2, c2] = POP(UPPER);\n\
    \  //   assert(L1 == L2);\n  //   ll R = min(R1, R2);\n  //   wk(L1, R, a1, b1,\
    \ c1, a2, b2, c2);\n  //   if (R < R1) LOWER.eb(R, R1, a1, b1, c1);\n  //   if\
    \ (R < R2) UPPER.eb(R, R2, a2, b2, c2);\n  // }\n\n  // for (auto& [L, R, a1,\
    \ b1, c1, a2, b2, c2]: merge_58<ll>(LOWER, UPPER)) { wk(L, R, a1, b1, c1, a2,\
    \ b2, c2); }\n  return ANS;\n}\n"
  dependsOn:
  - convex/line_min_function.hpp
  - geo/convex_hull.hpp
  - geo/base.hpp
  - mod/floor_sum_of_linear.hpp
  isVerificationFile: false
  path: convex/count_lattice_point_in_convex_polygon.hpp
  requiredBy: []
  timestamp: '2025-01-06 23:56:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/count_lattice_point_in_convex_polygon.test.cpp
documentation_of: convex/count_lattice_point_in_convex_polygon.hpp
layout: document
redirect_from:
- /library/convex/count_lattice_point_in_convex_polygon.hpp
- /library/convex/count_lattice_point_in_convex_polygon.hpp.html
title: convex/count_lattice_point_in_convex_polygon.hpp
---
