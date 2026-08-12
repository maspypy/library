---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/convex_polygon_edge_voronoi.hpp\"\n\n#line 2 \"geo/base.hpp\"\
    \ntemplate <typename T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\
    \n  template <typename A, typename B>\n  Point(A x, B y) : x(x), y(y) {}\n\n \
    \ template <typename A, typename B>\n  Point(pair<A, B> p) : x(p.fi), y(p.se)\
    \ {}\n\n  template <typename U>\n  Point(Point<U> p) : x(p.x), y(p.y) {}\n\n \
    \ Point operator+=(const Point p) {\n    x += p.x, y += p.y;\n    return *this;\n\
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
    \ T, typename U>\nREAL dist(Point<T> A, Point<U> B) {\n  REAL dx = REAL(A.x) -\
    \ REAL(B.x);\n  REAL dy = REAL(A.y) - REAL(B.y);\n  return sqrt(dx * dx + dy *\
    \ dy);\n}\n\n// ax+by+c\ntemplate <typename T>\nstruct Line {\n  T a, b, c;\n\n\
    \  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n  Line(Point<T> A, Point<T> B) {\n\
    \    a = A.y - B.y, b = B.x - A.x, c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1,\
    \ T y1, T x2, T y2) : Line(Point<T>(x1, y1), Point<T>(x2, y2)) {}\n\n  template\
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
    \ 0 && (C - B).dot(A - B) >= 0;\n  }\n\n  Line<T> to_Line() { return Line(A, B);\
    \ }\n};\n\ntemplate <typename REAL>\nstruct Circle {\n  Point<REAL> O;\n  REAL\
    \ r;\n  Circle() {}\n  Circle(Point<REAL> O, REAL r) : O(O), r(r) {}\n  Circle(REAL\
    \ x, REAL y, REAL r) : O(x, y), r(r) {}\n  template <typename T>\n  bool contain(Point<T>\
    \ p) {\n    REAL dx = p.x - O.x, dy = p.y - O.y;\n    return dx * dx + dy * dy\
    \ <= r * r;\n  }\n};\n#line 3 \"geo/convex_polygon_edge_voronoi.hpp\"\n\n// 20260812,\
    \ written by GPT-5.6 Sol\n//\n// A: CCW convex polygon, consecutive edges should\
    \ not be collinear.\n// Voronoi diagram of the edges of a convex polygon, restricted\
    \ to its interior.\n// Each Voronoi edge is represented by\n//   center(t) = p1\
    \ + t (p2 - p1)\n//   radius(t) = r1 + t (r2 - r1), 0 <= t <= 1.\n// O(N log N)\
    \ time.\n// If a circle is tangent to 4 or more edges simultaneously,\n// the\
    \ combinatorial structure may be tie-broken arbitrarily by floating errors.\n\
    template <typename P, typename Re>\nstruct Convex_Polygon_Edge_Voronoi {\n  using\
    \ RP = Point<Re>;\n  struct Edge {\n    int i, j;\n    RP p1, p2;\n    Re r1,\
    \ r2;\n  };\n\n  int N;\n  vc<P> A;\n\n  // polygon edge i:\n  //   U[i].dot(x)\
    \ <= H[i]\n  // where U[i] is the unit outward normal.\n  vc<RP> U;\n  vc<Re>\
    \ H;\n\n  vc<Edge> edges;\n  vc<vc<int>> incident;\n\n  Convex_Polygon_Edge_Voronoi(vc<P>\
    \ A) : N(len(A)), A(A) { build(); }\n\n  RP point(const Edge& e, Re t) const {\
    \ return e.p1 + (e.p2 - e.p1) * t; }\n  Re radius(const Edge& e, Re t) const {\
    \ return e.r1 + (e.r2 - e.r1) * t; }\n  pair<RP, RP> segment(const Edge& e) const\
    \ { return {e.p1, e.p2}; }\n\n  // Voronoi cell of polygon edge i.\n  // Collinear\
    \ points on the boundary may be removed.\n  vc<RP> cell(int i) const {\n    vc<RP>\
    \ X;\n    X.eb(RP(A[i]));\n    X.eb(RP(A[(i + 1) % N]));\n\n    for (int k : incident[i])\
    \ {\n      X.eb(edges[k].p1);\n      X.eb(edges[k].p2);\n    }\n\n    sort(all(X),\
    \ [&](const RP& a, const RP& b) -> bool {\n      if (a.x != b.x) return a.x <\
    \ b.x;\n      return a.y < b.y;\n    });\n    X.erase(unique(all(X),\n       \
    \            [&](const RP& a, const RP& b) -> bool {\n                     return\
    \ a.x == b.x && a.y == b.y;\n                   }),\n            X.end());\n \
    \   if (len(X) <= 2) return X;\n    vc<RP> H;\n    auto push = [&](RP p) -> void\
    \ {\n      while (len(H) >= 2) {\n        RP a = H[len(H) - 2];\n        RP b\
    \ = H[len(H) - 1];\n        if ((b - a).det(p - b) > 0) break;\n        H.pop_back();\n\
    \      }\n      H.eb(p);\n    };\n    for (auto& p : X) push(p);\n    int k =\
    \ len(H);\n    for (int i = len(X) - 2; i >= 0; --i) push(X[i]);\n    H.pop_back();\n\
    \    return H;\n  }\n\n private:\n  void add_edge(int i, int j, RP p1, Re r1,\
    \ RP p2, Re r2) {\n    // Except for tiny errors around simultaneous events,\n\
    \    // radius is nondecreasing along a medial-axis branch.\n    if (r1 > r2)\
    \ {\n      swap(p1, p2);\n      swap(r1, r2);\n    }\n\n    int k = len(edges);\n\
    \    edges.eb(Edge{i, j, p1, p2, r1, r2});\n    incident[i].eb(k);\n    incident[j].eb(k);\n\
    \  }\n\n  // For three consecutive active polygon edges a,b,c,\n  // returns the\
    \ center and radius where b disappears.\n  pair<RP, Re> event(int a, int b, int\
    \ c) const {\n    RP p = U[a] - U[b];\n    RP q = U[b] - U[c];\n    Re s = H[a]\
    \ - H[b];\n    Re t = H[b] - H[c];\n    Re det = p.det(q);\n    assert(det !=\
    \ Re(0));\n    RP x((s * q.y - p.y * t) / det, (p.x * t - s * q.x) / det);\n \
    \   Re r = H[b] - U[b].dot(x);\n    return {x, r};\n  }\n\n  void build() {\n\
    \    assert(N >= 3);\n\n    U.resize(N);\n    H.resize(N);\n    incident.resize(N);\n\
    \n    FOR(i, N) {\n      int j = (i + 1) % N;\n      Re dx = Re(A[j].x) - Re(A[i].x);\n\
    \      Re dy = Re(A[j].y) - Re(A[i].y);\n      Re d = sqrt(dx * dx + dy * dy);\n\
    \      // A is CCW, so the right normal is outward.\n      U[i] = RP(dy / d, -dx\
    \ / d);\n      H[i] = U[i].dot(RP(A[i]));\n    }\n\n    vc<int> nxt(N), pre(N);\n\
    \    FOR(i, N) {\n      nxt[i] = (i + 1) % N;\n      pre[nxt[i]] = i;\n    }\n\
    \n    vc<bool> alive(N, true);\n\n    vc<RP> born_point(N);\n    vc<Re> born_radius(N,\
    \ Re(0));\n    FOR(i, N) { born_point[i] = RP(A[(i + 1) % N]); }\n\n    vc<Re>\
    \ rm_time(N);\n    vc<int> version(N, 0);\n\n    pq_min<tuple<Re, int, int>> que;\n\
    \n    auto upd = [&](int b) -> void {\n      if (!alive[b]) return;\n      int\
    \ a = pre[b];\n      int c = nxt[b];\n      auto [x, t] = event(a, b, c);\n  \
    \    rm_time[b] = t;\n      ++version[b];\n      que.emplace(t, b, version[b]);\n\
    \    };\n\n    FOR(i, N) upd(i);\n    int n_alive = N;\n    while (n_alive > 3)\
    \ {\n      Re t;\n      int b, ver;\n      while (1) {\n        tie(t, b, ver)\
    \ = que.top();\n        que.pop();\n        if (!alive[b]) continue;\n       \
    \ if (ver != version[b]) continue;\n        break;\n      }\n\n      int a = pre[b],\
    \ c = nxt[b];\n      auto [x, r] = event(a, b, c);\n\n      add_edge(a, b, born_point[a],\
    \ born_radius[a], x, r);\n      add_edge(b, c, born_point[b], born_radius[b],\
    \ x, r);\n\n      alive[b] = false;\n      --n_alive;\n      nxt[a] = c, pre[c]\
    \ = a;\n\n      born_point[a] = x;\n      born_radius[a] = r;\n\n      upd(a);\n\
    \      upd(c);\n    }\n\n    // three active edges remain\n    int a = -1;\n \
    \   FOR(i, N) if (alive[i]) {\n      a = i;\n      break;\n    }\n    int b =\
    \ nxt[a], c = nxt[b];\n    assert(nxt[c] == a);\n\n    auto [x, r] = event(a,\
    \ b, c);\n    add_edge(a, b, born_point[a], born_radius[a], x, r);\n    add_edge(b,\
    \ c, born_point[b], born_radius[b], x, r);\n    add_edge(c, a, born_point[c],\
    \ born_radius[c], x, r);\n  }\n};\n"
  code: "\n#include \"geo/base.hpp\"\n\n// 20260812, written by GPT-5.6 Sol\n//\n\
    // A: CCW convex polygon, consecutive edges should not be collinear.\n// Voronoi\
    \ diagram of the edges of a convex polygon, restricted to its interior.\n// Each\
    \ Voronoi edge is represented by\n//   center(t) = p1 + t (p2 - p1)\n//   radius(t)\
    \ = r1 + t (r2 - r1), 0 <= t <= 1.\n// O(N log N) time.\n// If a circle is tangent\
    \ to 4 or more edges simultaneously,\n// the combinatorial structure may be tie-broken\
    \ arbitrarily by floating errors.\ntemplate <typename P, typename Re>\nstruct\
    \ Convex_Polygon_Edge_Voronoi {\n  using RP = Point<Re>;\n  struct Edge {\n  \
    \  int i, j;\n    RP p1, p2;\n    Re r1, r2;\n  };\n\n  int N;\n  vc<P> A;\n\n\
    \  // polygon edge i:\n  //   U[i].dot(x) <= H[i]\n  // where U[i] is the unit\
    \ outward normal.\n  vc<RP> U;\n  vc<Re> H;\n\n  vc<Edge> edges;\n  vc<vc<int>>\
    \ incident;\n\n  Convex_Polygon_Edge_Voronoi(vc<P> A) : N(len(A)), A(A) { build();\
    \ }\n\n  RP point(const Edge& e, Re t) const { return e.p1 + (e.p2 - e.p1) * t;\
    \ }\n  Re radius(const Edge& e, Re t) const { return e.r1 + (e.r2 - e.r1) * t;\
    \ }\n  pair<RP, RP> segment(const Edge& e) const { return {e.p1, e.p2}; }\n\n\
    \  // Voronoi cell of polygon edge i.\n  // Collinear points on the boundary may\
    \ be removed.\n  vc<RP> cell(int i) const {\n    vc<RP> X;\n    X.eb(RP(A[i]));\n\
    \    X.eb(RP(A[(i + 1) % N]));\n\n    for (int k : incident[i]) {\n      X.eb(edges[k].p1);\n\
    \      X.eb(edges[k].p2);\n    }\n\n    sort(all(X), [&](const RP& a, const RP&\
    \ b) -> bool {\n      if (a.x != b.x) return a.x < b.x;\n      return a.y < b.y;\n\
    \    });\n    X.erase(unique(all(X),\n                   [&](const RP& a, const\
    \ RP& b) -> bool {\n                     return a.x == b.x && a.y == b.y;\n  \
    \                 }),\n            X.end());\n    if (len(X) <= 2) return X;\n\
    \    vc<RP> H;\n    auto push = [&](RP p) -> void {\n      while (len(H) >= 2)\
    \ {\n        RP a = H[len(H) - 2];\n        RP b = H[len(H) - 1];\n        if\
    \ ((b - a).det(p - b) > 0) break;\n        H.pop_back();\n      }\n      H.eb(p);\n\
    \    };\n    for (auto& p : X) push(p);\n    int k = len(H);\n    for (int i =\
    \ len(X) - 2; i >= 0; --i) push(X[i]);\n    H.pop_back();\n    return H;\n  }\n\
    \n private:\n  void add_edge(int i, int j, RP p1, Re r1, RP p2, Re r2) {\n   \
    \ // Except for tiny errors around simultaneous events,\n    // radius is nondecreasing\
    \ along a medial-axis branch.\n    if (r1 > r2) {\n      swap(p1, p2);\n     \
    \ swap(r1, r2);\n    }\n\n    int k = len(edges);\n    edges.eb(Edge{i, j, p1,\
    \ p2, r1, r2});\n    incident[i].eb(k);\n    incident[j].eb(k);\n  }\n\n  // For\
    \ three consecutive active polygon edges a,b,c,\n  // returns the center and radius\
    \ where b disappears.\n  pair<RP, Re> event(int a, int b, int c) const {\n   \
    \ RP p = U[a] - U[b];\n    RP q = U[b] - U[c];\n    Re s = H[a] - H[b];\n    Re\
    \ t = H[b] - H[c];\n    Re det = p.det(q);\n    assert(det != Re(0));\n    RP\
    \ x((s * q.y - p.y * t) / det, (p.x * t - s * q.x) / det);\n    Re r = H[b] -\
    \ U[b].dot(x);\n    return {x, r};\n  }\n\n  void build() {\n    assert(N >= 3);\n\
    \n    U.resize(N);\n    H.resize(N);\n    incident.resize(N);\n\n    FOR(i, N)\
    \ {\n      int j = (i + 1) % N;\n      Re dx = Re(A[j].x) - Re(A[i].x);\n    \
    \  Re dy = Re(A[j].y) - Re(A[i].y);\n      Re d = sqrt(dx * dx + dy * dy);\n \
    \     // A is CCW, so the right normal is outward.\n      U[i] = RP(dy / d, -dx\
    \ / d);\n      H[i] = U[i].dot(RP(A[i]));\n    }\n\n    vc<int> nxt(N), pre(N);\n\
    \    FOR(i, N) {\n      nxt[i] = (i + 1) % N;\n      pre[nxt[i]] = i;\n    }\n\
    \n    vc<bool> alive(N, true);\n\n    vc<RP> born_point(N);\n    vc<Re> born_radius(N,\
    \ Re(0));\n    FOR(i, N) { born_point[i] = RP(A[(i + 1) % N]); }\n\n    vc<Re>\
    \ rm_time(N);\n    vc<int> version(N, 0);\n\n    pq_min<tuple<Re, int, int>> que;\n\
    \n    auto upd = [&](int b) -> void {\n      if (!alive[b]) return;\n      int\
    \ a = pre[b];\n      int c = nxt[b];\n      auto [x, t] = event(a, b, c);\n  \
    \    rm_time[b] = t;\n      ++version[b];\n      que.emplace(t, b, version[b]);\n\
    \    };\n\n    FOR(i, N) upd(i);\n    int n_alive = N;\n    while (n_alive > 3)\
    \ {\n      Re t;\n      int b, ver;\n      while (1) {\n        tie(t, b, ver)\
    \ = que.top();\n        que.pop();\n        if (!alive[b]) continue;\n       \
    \ if (ver != version[b]) continue;\n        break;\n      }\n\n      int a = pre[b],\
    \ c = nxt[b];\n      auto [x, r] = event(a, b, c);\n\n      add_edge(a, b, born_point[a],\
    \ born_radius[a], x, r);\n      add_edge(b, c, born_point[b], born_radius[b],\
    \ x, r);\n\n      alive[b] = false;\n      --n_alive;\n      nxt[a] = c, pre[c]\
    \ = a;\n\n      born_point[a] = x;\n      born_radius[a] = r;\n\n      upd(a);\n\
    \      upd(c);\n    }\n\n    // three active edges remain\n    int a = -1;\n \
    \   FOR(i, N) if (alive[i]) {\n      a = i;\n      break;\n    }\n    int b =\
    \ nxt[a], c = nxt[b];\n    assert(nxt[c] == a);\n\n    auto [x, r] = event(a,\
    \ b, c);\n    add_edge(a, b, born_point[a], born_radius[a], x, r);\n    add_edge(b,\
    \ c, born_point[b], born_radius[b], x, r);\n    add_edge(c, a, born_point[c],\
    \ born_radius[c], x, r);\n  }\n};"
  dependsOn:
  - geo/base.hpp
  isVerificationFile: false
  path: geo/convex_polygon_edge_voronoi.hpp
  requiredBy: []
  timestamp: '2026-08-13 00:28:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/convex_polygon_edge_voronoi.hpp
layout: document
redirect_from:
- /library/geo/convex_polygon_edge_voronoi.hpp
- /library/geo/convex_polygon_edge_voronoi.hpp.html
title: geo/convex_polygon_edge_voronoi.hpp
---
