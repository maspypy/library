---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/fastset.hpp
    title: ds/fastset.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/outcircle.hpp
    title: geo/outcircle.hpp
  - icon: ':heavy_check_mark:'
    path: geo/triangle_area.hpp
    title: geo/triangle_area.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/shuffle.hpp
    title: random/shuffle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1984/problem/H
    - https://codeforces.com/contest/549/problem/E
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
    \  return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U x,\
    \ U y) {\n    return a * x + b * y + c;\n  }\n\n  // \u540C\u3058\u76F4\u7DDA\u304C\
    \u540C\u3058 a,b,c \u3067\u8868\u73FE\u3055\u308C\u308B\u3088\u3046\u306B\u3059\
    \u308B\n  void normalize() {\n    static_assert(is_same_v<T, int> || is_same_v<T,\
    \ long long>);\n    T g = gcd(gcd(abs(a), abs(b)), abs(c));\n    a /= g, b /=\
    \ g, c /= g;\n    if (b < 0) { a = -a, b = -b, c = -c; }\n    if (b == 0 && a\
    \ < 0) { a = -a, b = -b, c = -c; }\n  }\n\n  bool is_parallel(Line other) { return\
    \ a * other.b - b * other.a == 0; }\n  bool is_orthogonal(Line other) { return\
    \ a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct Segment\
    \ {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B) {}\n \
    \ Segment(T x1, T y1, T x2, T y2) : Segment(Point<T>(x1, y1), Point<T>(x2, y2))\
    \ {}\n\n  bool contain(Point<T> C) {\n    T det = (C - A).det(B - A);\n    if\
    \ (det != 0) return 0;\n    return (C - A).dot(B - A) >= 0 && (C - B).dot(A -\
    \ B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate\
    \ <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL r;\n  Circle() {}\n\
    \  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL x, REAL y, REAL\
    \ r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T> p) {\n\
    \    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy <= r *\
    \ r;\n  }\n};\n#line 1 \"geo/triangle_area.hpp\"\ntemplate <typename REAL, typename\
    \ T>\nREAL triangle_area(Point<T> A, Point<T> B, Point<T> C) {\n  return abs((B\
    \ - A).det(C - A)) * 0.5;\n}\n#line 4 \"geo/outcircle.hpp\"\n\ntemplate <typename\
    \ REAL, typename T>\nCircle<REAL> outcircle(Point<T> A, Point<T> B, Point<T> C)\
    \ {\n  REAL b1 = B.x - A.x, b2 = B.y - A.y;\n  REAL c1 = C.x - A.x, c2 = C.y -\
    \ A.y;\n  REAL bb = (b1 * b1 + b2 * b2) / 2;\n  REAL cc = (c1 * c1 + c2 * c2)\
    \ / 2;\n\n  REAL det = b1 * c2 - b2 * c1;\n  REAL x = (bb * c2 - b2 * cc) / det;\n\
    \  REAL y = (b1 * cc - bb * c1) / det;\n  REAL r = sqrt(x * x + y * y);\n  x +=\
    \ A.x, y += A.y;\n  return Circle<REAL>(x, y, r);\n}\n\n// ABC \u306E\u5916\u63A5\
    \u5186\u306B\u5BFE\u3057\u3066\u5185\u5916\u3069\u3061\u3089\u306B\u3042\u308B\
    \u304B\n// \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n// \u5EA7\u6A19\
    \u306E 4 \u4E57\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\
    \u3088\u3046\u306B\u3059\u308B\ntemplate <typename T>\nint outcircle_side(Point<T>\
    \ A, Point<T> B, Point<T> C, Point<T> p) {\n  T d = (B - A).det(C - A);\n  assert(d\
    \ != 0);\n  if (d < 0) swap(B, C);\n  array<Point<T>, 3> pts = {A, B, C};\n  array<array<T,\
    \ 3>, 3> mat;\n  FOR(i, 3) {\n    T dx = pts[i].x - p.x, dy = pts[i].y - p.y;\n\
    \    mat[i][0] = dx, mat[i][1] = dy, mat[i][2] = dx * dx + dy * dy;\n  }\n  T\
    \ det = 0;\n  det += mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1]);\n\
    \  det += mat[0][1] * (mat[1][2] * mat[2][0] - mat[1][0] * mat[2][2]);\n  det\
    \ += mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);\n  if (det ==\
    \ 0) return 0;\n  return (det > 0 ? 1 : -1);\n}\n#line 2 \"ds/fastset.hpp\"\n\r\
    \n// 64-ary tree\r\n// space: (N/63) * u64\r\nstruct FastSet {\r\n  static constexpr\
    \ u32 B = 64;\r\n  int n, log;\r\n  vvc<u64> seg;\r\n\r\n  FastSet() {}\r\n  FastSet(int\
    \ n) { build(n); }\r\n\r\n  int size() { return n; }\r\n\r\n  template <typename\
    \ F>\r\n  FastSet(int n, F f) {\r\n    build(n, f);\r\n  }\r\n\r\n  void build(int\
    \ m) {\r\n    seg.clear();\r\n    n = m;\r\n    do {\r\n      seg.push_back(vc<u64>((m\
    \ + B - 1) / B));\r\n      m = (m + B - 1) / B;\r\n    } while (m > 1);\r\n  \
    \  log = len(seg);\r\n  }\r\n  template <typename F>\r\n  void build(int n, F\
    \ f) {\r\n    build(n);\r\n    FOR(i, n) { seg[0][i / B] |= u64(f(i)) << (i %\
    \ B); }\r\n    FOR(h, log - 1) {\r\n      FOR(i, len(seg[h])) { seg[h + 1][i /\
    \ B] |= u64(bool(seg[h][i])) << (i % B); }\r\n    }\r\n  }\r\n\r\n  bool operator[](int\
    \ i) const { return seg[0][i / B] >> (i % B) & 1; }\r\n  void insert(int i) {\r\
    \n    assert(0 <= i && i < n);\r\n    for (int h = 0; h < log; h++) { seg[h][i\
    \ / B] |= u64(1) << (i % B), i /= B; }\r\n  }\r\n  void add(int i) { insert(i);\
    \ }\r\n  void erase(int i) {\r\n    assert(0 <= i && i < n);\r\n    u64 x = 0;\r\
    \n    for (int h = 0; h < log; h++) {\r\n      seg[h][i / B] &= ~(u64(1) << (i\
    \ % B));\r\n      seg[h][i / B] |= x << (i % B);\r\n      x = bool(seg[h][i /\
    \ B]);\r\n      i /= B;\r\n    }\r\n  }\r\n  void remove(int i) { erase(i); }\r\
    \n\r\n  // min[x,n) or n\r\n  int next(int i) {\r\n    assert(i <= n);\r\n   \
    \ chmax(i, 0);\r\n    for (int h = 0; h < log; h++) {\r\n      if (i / B == seg[h].size())\
    \ break;\r\n      u64 d = seg[h][i / B] >> (i % B);\r\n      if (!d) {\r\n   \
    \     i = i / B + 1;\r\n        continue;\r\n      }\r\n      i += lowbit(d);\r\
    \n      for (int g = h - 1; g >= 0; g--) {\r\n        i *= B;\r\n        i +=\
    \ lowbit(seg[g][i / B]);\r\n      }\r\n      return i;\r\n    }\r\n    return\
    \ n;\r\n  }\r\n\r\n  // max [0,x], or -1\r\n  int prev(int i) {\r\n    assert(i\
    \ >= -1);\r\n    if (i >= n) i = n - 1;\r\n    for (int h = 0; h < log; h++) {\r\
    \n      if (i == -1) break;\r\n      u64 d = seg[h][i / B] << (63 - i % B);\r\n\
    \      if (!d) {\r\n        i = i / B - 1;\r\n        continue;\r\n      }\r\n\
    \      i -= __builtin_clzll(d);\r\n      for (int g = h - 1; g >= 0; g--) {\r\n\
    \        i *= B;\r\n        i += topbit(seg[g][i / B]);\r\n      }\r\n      return\
    \ i;\r\n    }\r\n    return -1;\r\n  }\r\n\r\n  bool any(int l, int r) { return\
    \ next(l) < r; }\r\n\r\n  // [l, r)\r\n  template <typename F>\r\n  void enumerate(int\
    \ l, int r, F f) {\r\n    for (int x = next(l); x < r; x = next(x + 1)) f(x);\r\
    \n  }\r\n\r\n  string to_string() {\r\n    string s(n, '?');\r\n    for (int i\
    \ = 0; i < n; ++i) s[i] = ((*this)[i] ? '1' : '0');\r\n    return s;\r\n  }\r\n\
    };\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n  static u64 x_ = u64(chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count())\
    \ * 10150724397891781847ULL;\n  x_ ^= x_ << 7;\n  return x_ ^= x_ >> 9;\n}\n\n\
    u64 RNG(u64 lim) { return RNG_64() % lim; }\n\nll RNG(ll l, ll r) { return l +\
    \ RNG_64() % (r - l); }\n#line 2 \"random/shuffle.hpp\"\n\ntemplate <typename\
    \ T>\nvoid shuffle(vc<T>& A) {\n  FOR(i, len(A)) {\n    int j = RNG(0, i + 1);\n\
    \    if (i != j) swap(A[i], A[j]);\n  }\n}\n#line 4 \"geo/delaunay_triangulation_of_convex_polygon.hpp\"\
    \n\n// \u5EA7\u6A19\u306E 4 \u4E57\u304C\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\
    \u3057\u306A\u3044\n// return : array<int,3>, triangles\n// https://codeforces.com/contest/549/problem/E\n\
    // https://codeforces.com/contest/1984/problem/H\ntemplate <typename T>\nvc<array<int,\
    \ 3>> delaunay_triangulation_of_convex_polygon(vc<Point<T>> A, bool farthest)\
    \ {\n  using P = Point<T>;\n  int N = len(A);\n  if (N <= 2) return {};\n\n  FastSet\
    \ FS(N);\n\n  vc<int> I(N);\n  FOR(i, N) I[i] = i;\n  shuffle(I);\n\n  sort(I.end()\
    \ - 3, I.end());\n\n  struct E {\n    int a, b, nxt, rev;\n  };\n\n  int c = POP(I),\
    \ b = POP(I), a = POP(I);\n  vc<E> dat;\n  dat.eb(a, b, 1, -1);\n  dat.eb(b, c,\
    \ 2, -1);\n  dat.eb(c, a, 0, -1);\n  vc<int> v_to_e(N, -1);\n  v_to_e[a] = 0,\
    \ v_to_e[b] = 1, v_to_e[c] = 2;\n  FS.insert(a), FS.insert(b), FS.insert(c);\n\
    \n  auto dfs = [&](auto& dfs, int i) -> void {\n    int j = dat[i].rev;\n    if\
    \ (j == -1) return;\n    int i1 = dat[i].nxt;\n    int i2 = dat[i1].nxt;\n   \
    \ int j1 = dat[j].nxt;\n    int j2 = dat[j1].nxt;\n    int b = dat[i].a, c = dat[i1].a,\
    \ a = dat[i2].a, d = dat[j2].a;\n    int side = outcircle_side(A[a], A[b], A[c],\
    \ A[d]);\n    bool flip = (farthest ? (side == -1) : (side == 1));\n    if (!flip)\
    \ return;\n    dat[i] = {d, a, i2, j};\n    dat[j] = {a, d, j2, i};\n    dat[i1].nxt\
    \ = j, dat[i2].nxt = j1, dat[j1].nxt = i, dat[j2].nxt = i1;\n    dfs(dfs, i1),\
    \ dfs(dfs, i2), dfs(dfs, j1), dfs(dfs, j2);\n  };\n\n  while (len(I)) {\n    int\
    \ v = POP(I);\n    int l = FS.prev(v), r = FS.next(v);\n    if (l == -1) l = FS.prev(N);\n\
    \    if (r == N) r = FS.next(0);\n    FS.insert(v);\n    int k = v_to_e[l];\n\
    \    int s = len(dat);\n    v_to_e[l] = s + 1, v_to_e[v] = s + 2;\n    dat[k].rev\
    \ = s;\n    dat.eb(r, l, s + 1, k);\n    dat.eb(l, v, s + 2, -1);\n    dat.eb(v,\
    \ r, s, -1);\n    dfs(dfs, k);\n  }\n  vc<array<int, 3>> ANS;\n  FOR(i, len(dat))\
    \ {\n    int j = dat[i].nxt;\n    int k = dat[j].nxt;\n    if (i > j || i > k)\
    \ continue;\n    ANS.eb(array<int, 3>{dat[i].a, dat[j].a, dat[k].a});\n  }\n\n\
    \  return ANS;\n}\n"
  code: "#include \"geo/outcircle.hpp\"\n#include \"ds/fastset.hpp\"\n#include \"\
    random/shuffle.hpp\"\n\n// \u5EA7\u6A19\u306E 4 \u4E57\u304C\u30AA\u30FC\u30D0\
    \u30FC\u30D5\u30ED\u30FC\u3057\u306A\u3044\n// return : array<int,3>, triangles\n\
    // https://codeforces.com/contest/549/problem/E\n// https://codeforces.com/contest/1984/problem/H\n\
    template <typename T>\nvc<array<int, 3>> delaunay_triangulation_of_convex_polygon(vc<Point<T>>\
    \ A, bool farthest) {\n  using P = Point<T>;\n  int N = len(A);\n  if (N <= 2)\
    \ return {};\n\n  FastSet FS(N);\n\n  vc<int> I(N);\n  FOR(i, N) I[i] = i;\n \
    \ shuffle(I);\n\n  sort(I.end() - 3, I.end());\n\n  struct E {\n    int a, b,\
    \ nxt, rev;\n  };\n\n  int c = POP(I), b = POP(I), a = POP(I);\n  vc<E> dat;\n\
    \  dat.eb(a, b, 1, -1);\n  dat.eb(b, c, 2, -1);\n  dat.eb(c, a, 0, -1);\n  vc<int>\
    \ v_to_e(N, -1);\n  v_to_e[a] = 0, v_to_e[b] = 1, v_to_e[c] = 2;\n  FS.insert(a),\
    \ FS.insert(b), FS.insert(c);\n\n  auto dfs = [&](auto& dfs, int i) -> void {\n\
    \    int j = dat[i].rev;\n    if (j == -1) return;\n    int i1 = dat[i].nxt;\n\
    \    int i2 = dat[i1].nxt;\n    int j1 = dat[j].nxt;\n    int j2 = dat[j1].nxt;\n\
    \    int b = dat[i].a, c = dat[i1].a, a = dat[i2].a, d = dat[j2].a;\n    int side\
    \ = outcircle_side(A[a], A[b], A[c], A[d]);\n    bool flip = (farthest ? (side\
    \ == -1) : (side == 1));\n    if (!flip) return;\n    dat[i] = {d, a, i2, j};\n\
    \    dat[j] = {a, d, j2, i};\n    dat[i1].nxt = j, dat[i2].nxt = j1, dat[j1].nxt\
    \ = i, dat[j2].nxt = i1;\n    dfs(dfs, i1), dfs(dfs, i2), dfs(dfs, j1), dfs(dfs,\
    \ j2);\n  };\n\n  while (len(I)) {\n    int v = POP(I);\n    int l = FS.prev(v),\
    \ r = FS.next(v);\n    if (l == -1) l = FS.prev(N);\n    if (r == N) r = FS.next(0);\n\
    \    FS.insert(v);\n    int k = v_to_e[l];\n    int s = len(dat);\n    v_to_e[l]\
    \ = s + 1, v_to_e[v] = s + 2;\n    dat[k].rev = s;\n    dat.eb(r, l, s + 1, k);\n\
    \    dat.eb(l, v, s + 2, -1);\n    dat.eb(v, r, s, -1);\n    dfs(dfs, k);\n  }\n\
    \  vc<array<int, 3>> ANS;\n  FOR(i, len(dat)) {\n    int j = dat[i].nxt;\n   \
    \ int k = dat[j].nxt;\n    if (i > j || i > k) continue;\n    ANS.eb(array<int,\
    \ 3>{dat[i].a, dat[j].a, dat[k].a});\n  }\n\n  return ANS;\n}\n"
  dependsOn:
  - geo/outcircle.hpp
  - geo/base.hpp
  - geo/triangle_area.hpp
  - ds/fastset.hpp
  - random/shuffle.hpp
  - random/base.hpp
  isVerificationFile: false
  path: geo/delaunay_triangulation_of_convex_polygon.hpp
  requiredBy: []
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/delaunay_triangulation_of_convex_polygon.hpp
layout: document
redirect_from:
- /library/geo/delaunay_triangulation_of_convex_polygon.hpp
- /library/geo/delaunay_triangulation_of_convex_polygon.hpp.html
title: geo/delaunay_triangulation_of_convex_polygon.hpp
---
