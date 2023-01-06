---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geo/angle_sort.hpp
    title: geo/angle_sort.hpp
  - icon: ':heavy_check_mark:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc202_f.test.cpp
    title: test/atcoder/abc202_f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/count_points_in_triangles.test.cpp
    title: test/mytest/count_points_in_triangles.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/count_points_in_triangles.hpp\"\n\n#line 2 \"geo/angle_sort.hpp\"\
    \n\r\n#line 2 \"geo/base.hpp\"\ntemplate <typename T>\nstruct Point {\n  T x,\
    \ y;\n\n  Point() = default;\n\n  template <typename A, typename B>\n  Point(A\
    \ x, B y) : x(x), y(y) {}\n\n  template <typename A, typename B>\n  Point(pair<A,\
    \ B> p) : x(p.fi), y(p.se) {}\n\n  Point operator+(Point p) const { return {x\
    \ + p.x, y + p.y}; }\n  Point operator-(Point p) const { return {x - p.x, y -\
    \ p.y}; }\n  bool operator==(Point p) const { return x == p.x && y == p.y; }\n\
    \  Point operator-() const { return {-x, -y}; }\n\n  bool operator<(Point p) const\
    \ {\n    if (x != p.x) return x < p.x;\n    return y < p.y;\n  }\n  T dot(Point\
    \ other) { return x * other.x + y * other.y; }\n  T det(Point other) { return\
    \ x * other.y - y * other.x; }\n\n  void read() { fastio::read(x), fastio::read(y);\
    \ }\n  void write() { fastio::printer.write(pair<T, T>({x, y})); }\n};\n\ntemplate\
    \ <typename REAL, typename T>\nREAL dist(Point<T> A, Point<T> B) {\n  A = A -\
    \ B;\n  T p = A.dot(A);\n  return sqrt(REAL(p));\n}\n\ntemplate <typename T>\n\
    struct Line {\n  T a, b, c;\n\n  Line(T a, T b, T c) : a(a), b(b), c(c) {}\n \
    \ Line(Point<T> A, Point<T> B) {\n    a = A.y - B.y;\n    b = B.x - A.x;\n   \
    \ c = A.x * B.y - A.y * B.x;\n  }\n  Line(T x1, T y1, T x2, T y2) : Line(Point<T>(x1,\
    \ y1), Point<T>(x2, y2)) {}\n\n  template <typename U>\n  U eval(Point<U> P) {\n\
    \    return a * P.x + b * P.y + c;\n  }\n\n  template <typename U>\n  T eval(U\
    \ x, U y) {\n    return a * x + b * y + c;\n  }\n\n  bool is_parallel(Line other)\
    \ { return a * other.b - b * other.a == 0; }\n\n  bool is_orthogonal(Line other)\
    \ { return a * other.a + b * other.b == 0; }\n};\n\ntemplate <typename T>\nstruct\
    \ Segment {\n  Point<T> A, B;\n\n  Segment(Point<T> A, Point<T> B) : A(A), B(B)\
    \ {}\n  Segment(T x1, T y1, T x2, T y2)\n      : Segment(Point<T>(x1, y1), Point<T>(x2,\
    \ y2)) {}\n\n  Line<T> to_Line() { return Line(A, B); }\n};\n\ntemplate <typename\
    \ T>\nstruct Circle {\n  Point<T> O;\n  T r;\n  Circle(Point<T> O, T r) : O(O),\
    \ r(r) {}\n  Circle(T x, T y, T r) : O(Point<T>(x, y)), r(r) {}\n};\n\ntemplate\
    \ <typename T>\nstruct Polygon {\n  vc<Point<T>> points;\n  T a;\n\n  template\
    \ <typename A, typename B>\n  Polygon(vc<pair<A, B>> pairs) {\n    for (auto&&\
    \ [a, b]: pairs) points.eb(Point<T>(a, b));\n    build();\n  }\n  Polygon(vc<Point<T>>\
    \ points) : points(points) { build(); }\n\n  int size() { return len(points);\
    \ }\n\n  template <typename REAL>\n  REAL area() {\n    return a * 0.5;\n  }\n\
    \n  template <enable_if_t<is_integral<T>::value, int> = 0>\n  T area_2() {\n \
    \   return a;\n  }\n\n  bool is_convex() {\n    FOR(j, len(points)) {\n      int\
    \ i = (j == 0 ? len(points) - 1 : j - 1);\n      int k = (j == len(points) - 1\
    \ ? 0 : j + 1);\n      if ((points[j] - points[i]).det(points[k] - points[j])\
    \ < 0) return false;\n    }\n    return true;\n  }\n\nprivate:\n  void build()\
    \ {\n    a = 0;\n    FOR(i, len(points)) {\n      int j = (i + 1 == len(points)\
    \ ? 0 : i + 1);\n      a += points[i].det(points[j]);\n    }\n    if (a < 0) {\n\
    \      a = -a;\n      reverse(all(points));\n    }\n  }\n};\n#line 4 \"geo/angle_sort.hpp\"\
    \n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\ntemplate\
    \ <typename T>\r\nvector<int> angle_argsort(vector<Point<T>>& P) {\r\n  vector<int>\
    \ lower, origin, upper;\r\n  const Point<T> O = {0, 0};\r\n  FOR(i, len(P)) {\r\
    \n    if (P[i] == O) origin.eb(i);\r\n    elif ((P[i].y < 0) || (P[i].y == 0 &&\
    \ P[i].x > 0)) lower.eb(i);\r\n    else upper.eb(i);\r\n  }\r\n  sort(all(lower),\
    \ [&](auto& i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  sort(all(upper),\
    \ [&](auto& i, auto& j) { return P[i].det(P[j]) > 0; });\r\n  auto& I = lower;\r\
    \n  I.insert(I.end(), all(origin));\r\n  I.insert(I.end(), all(upper));\r\n  return\
    \ I;\r\n}\r\n\r\n// \u504F\u89D2\u30BD\u30FC\u30C8\u306B\u5BFE\u3059\u308B argsort\r\
    \ntemplate <typename T>\r\nvector<int> angle_argsort(vector<pair<T, T>>& P) {\r\
    \n  vc<Point<T>> tmp(len(P));\r\n  FOR(i, len(P)) tmp[i] = Point<T>(P[i]);\r\n\
    \  return angle_argsort<T>(tmp);\r\n}\r\n\r\n// inplace \u306B\u504F\u89D2\u30BD\
    \u30FC\u30C8\u3059\u308B\r\n// index \u304C\u6B32\u3057\u3044\u5834\u5408\u306F\
    \ angle_argsort\r\ntemplate <typename T>\r\nvoid angle_sort(vector<Point<T>>&\
    \ P) {\r\n  auto I = angle_argsort<T>(P);\r\n  P = rearrange(P, I);\r\n}\r\n\r\
    \n// inplace \u306B\u504F\u89D2\u30BD\u30FC\u30C8\u3059\u308B\r\n// index \u304C\
    \u6B32\u3057\u3044\u5834\u5408\u306F angle_argsort\r\ntemplate <typename T>\r\n\
    void angle_sort(vector<pair<T, T>>& P) {\r\n  auto I = angle_argsort<T>(P);\r\n\
    \  P = rearrange(P, I);\r\n}\r\n#line 2 \"random/base.hpp\"\n\nu64 RNG_64() {\n\
    \  static uint64_t x_\n      = uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                     chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                     .count())\n        * 10150724397891781847ULL;\n  x_ ^= x_\
    \ << 7;\n  return x_ ^= x_ >> 9;\n}\n\nu64 RNG(u64 lim) { return RNG_64() % lim;\
    \ }\n\nll RNG(ll l, ll r) { return l + RNG_64() % (r - l); }\n#line 5 \"geo/count_points_in_triangles.hpp\"\
    \n\n// \u70B9\u7FA4 A, B \u3092\u5165\u529B \uFF08Point<ll>\uFF09\n// query(i,j,k)\uFF1A\
    \u4E09\u89D2\u5F62 AiAjAk \u5185\u90E8\u306E Bl \u306E\u500B\u6570\uFF08\u975E\
    \u8CA0\uFF09\u3092\u8FD4\u3059\n// \u524D\u8A08\u7B97 O(N^2M)\u3001\u30AF\u30A8\
    \u30EA O(1)\nstruct Count_Points_In_Triangles {\n  using P = Point<ll>;\n  const\
    \ int LIM = 1'000'000'000 + 10;\n  vc<P> A, B;\n  vc<int> I, rk; // O \u304B\u3089\
    \u898B\u305F\u504F\u89D2\u30BD\u30FC\u30C8\u9806\u3092\u7BA1\u7406\n  vc<int>\
    \ point; // A[i] \u3068\u4E00\u81F4\u3059\u308B B[j] \u306E\u6570\u3048\u4E0A\u3052\
    \n  vvc<int> seg;  // \u7DDA\u5206 A[i]A[j] \u5185\u306B\u3042\u308B B[k] \u306E\
    \u6570\u3048\u4E0A\u3052\n  vvc<int> tri;  // OA[i]A[j] \u5185\u90E8\u306B\u3042\
    \u308B B[k] \u306E\u6570\u3048\u4E0A\u3052\n  Count_Points_In_Triangles(vc<P>\
    \ A, vc<P> B) : A(A), B(B) {\n    for (auto&& p: A) assert(-LIM < min(p.x, p.y)\
    \ && max(p.x, p.y) < LIM);\n    for (auto&& p: B) assert(-LIM < min(p.x, p.y)\
    \ && max(p.x, p.y) < LIM);\n    build();\n  }\n\n  int query(int i, int j, int\
    \ k) {\n    i = rk[i], j = rk[j], k = rk[k];\n    if (i > j) swap(i, j);\n   \
    \ if (j > k) swap(j, k);\n    if (i > j) swap(i, j);\n    assert(i <= j && j <=\
    \ k);\n\n    ll d = (A[j] - A[i]).det(A[k] - A[i]);\n    if (d == 0) return 0;\n\
    \    if (d > 0) { return tri[i][j] + tri[j][k] - tri[i][k] - seg[i][k]; }\n  \
    \  int x = tri[i][k] - tri[i][j] - tri[j][k];\n    return x - seg[i][j] - seg[j][k]\
    \ - point[j];\n  }\n\nprivate:\n  P take_origin() {\n    int N = len(A), M = len(B);\n\
    \    while (1) {\n      P O = P{-LIM, RNG(-LIM, LIM)};\n      bool ok = 1;\n \
    \     FOR(i, N) FOR(j, N) {\n        if (A[i] == A[j]) continue;\n        if ((A[i]\
    \ - O).det(A[j] - O) == 0) ok = 0;\n      }\n      FOR(i, N) FOR(j, M) {\n   \
    \     if (A[i] == B[j]) continue;\n        if ((A[i] - O).det(B[j] - O) == 0)\
    \ ok = 0;\n      }\n      if (ok) return O;\n    }\n    return P{};\n  }\n\n \
    \ void build() {\n    P O = take_origin();\n    for (auto&& p: A) p = p - O;\n\
    \    for (auto&& p: B) p = p - O;\n    int N = len(A), M = len(B);\n    I.resize(N),\
    \ rk.resize(N);\n    iota(all(I), 0);\n    sort(all(I), [&](auto& a, auto& b)\
    \ -> bool { return A[a].det(A[b]) > 0; });\n    FOR(i, N) rk[I[i]] = i;\n    A\
    \ = rearrange(A, I);\n    point.assign(N, 0);\n    seg.assign(N, vc<int>(N));\n\
    \    tri.assign(N, vc<int>(N));\n\n    FOR(i, N) FOR(j, M) if (A[i] == B[j])++\
    \ point[i];\n    FOR(i, N) FOR(j, i + 1, N) {\n      FOR(k, M) {\n        if (A[i].det(B[k])\
    \ <= 0) continue;\n        if (A[j].det(B[k]) >= 0) continue;\n        ll d =\
    \ (B[k] - A[i]).det(A[j] - A[i]);\n        if (d == 0) ++seg[i][j];\n        if\
    \ (d < 0) ++tri[i][j];\n      }\n    }\n  }\n};\n"
  code: "\n#include \"geo/angle_sort.hpp\"\n#include \"geo/base.hpp\"\n#include \"\
    random/base.hpp\"\n\n// \u70B9\u7FA4 A, B \u3092\u5165\u529B \uFF08Point<ll>\uFF09\
    \n// query(i,j,k)\uFF1A\u4E09\u89D2\u5F62 AiAjAk \u5185\u90E8\u306E Bl \u306E\u500B\
    \u6570\uFF08\u975E\u8CA0\uFF09\u3092\u8FD4\u3059\n// \u524D\u8A08\u7B97 O(N^2M)\u3001\
    \u30AF\u30A8\u30EA O(1)\nstruct Count_Points_In_Triangles {\n  using P = Point<ll>;\n\
    \  const int LIM = 1'000'000'000 + 10;\n  vc<P> A, B;\n  vc<int> I, rk; // O \u304B\
    \u3089\u898B\u305F\u504F\u89D2\u30BD\u30FC\u30C8\u9806\u3092\u7BA1\u7406\n  vc<int>\
    \ point; // A[i] \u3068\u4E00\u81F4\u3059\u308B B[j] \u306E\u6570\u3048\u4E0A\u3052\
    \n  vvc<int> seg;  // \u7DDA\u5206 A[i]A[j] \u5185\u306B\u3042\u308B B[k] \u306E\
    \u6570\u3048\u4E0A\u3052\n  vvc<int> tri;  // OA[i]A[j] \u5185\u90E8\u306B\u3042\
    \u308B B[k] \u306E\u6570\u3048\u4E0A\u3052\n  Count_Points_In_Triangles(vc<P>\
    \ A, vc<P> B) : A(A), B(B) {\n    for (auto&& p: A) assert(-LIM < min(p.x, p.y)\
    \ && max(p.x, p.y) < LIM);\n    for (auto&& p: B) assert(-LIM < min(p.x, p.y)\
    \ && max(p.x, p.y) < LIM);\n    build();\n  }\n\n  int query(int i, int j, int\
    \ k) {\n    i = rk[i], j = rk[j], k = rk[k];\n    if (i > j) swap(i, j);\n   \
    \ if (j > k) swap(j, k);\n    if (i > j) swap(i, j);\n    assert(i <= j && j <=\
    \ k);\n\n    ll d = (A[j] - A[i]).det(A[k] - A[i]);\n    if (d == 0) return 0;\n\
    \    if (d > 0) { return tri[i][j] + tri[j][k] - tri[i][k] - seg[i][k]; }\n  \
    \  int x = tri[i][k] - tri[i][j] - tri[j][k];\n    return x - seg[i][j] - seg[j][k]\
    \ - point[j];\n  }\n\nprivate:\n  P take_origin() {\n    int N = len(A), M = len(B);\n\
    \    while (1) {\n      P O = P{-LIM, RNG(-LIM, LIM)};\n      bool ok = 1;\n \
    \     FOR(i, N) FOR(j, N) {\n        if (A[i] == A[j]) continue;\n        if ((A[i]\
    \ - O).det(A[j] - O) == 0) ok = 0;\n      }\n      FOR(i, N) FOR(j, M) {\n   \
    \     if (A[i] == B[j]) continue;\n        if ((A[i] - O).det(B[j] - O) == 0)\
    \ ok = 0;\n      }\n      if (ok) return O;\n    }\n    return P{};\n  }\n\n \
    \ void build() {\n    P O = take_origin();\n    for (auto&& p: A) p = p - O;\n\
    \    for (auto&& p: B) p = p - O;\n    int N = len(A), M = len(B);\n    I.resize(N),\
    \ rk.resize(N);\n    iota(all(I), 0);\n    sort(all(I), [&](auto& a, auto& b)\
    \ -> bool { return A[a].det(A[b]) > 0; });\n    FOR(i, N) rk[I[i]] = i;\n    A\
    \ = rearrange(A, I);\n    point.assign(N, 0);\n    seg.assign(N, vc<int>(N));\n\
    \    tri.assign(N, vc<int>(N));\n\n    FOR(i, N) FOR(j, M) if (A[i] == B[j])++\
    \ point[i];\n    FOR(i, N) FOR(j, i + 1, N) {\n      FOR(k, M) {\n        if (A[i].det(B[k])\
    \ <= 0) continue;\n        if (A[j].det(B[k]) >= 0) continue;\n        ll d =\
    \ (B[k] - A[i]).det(A[j] - A[i]);\n        if (d == 0) ++seg[i][j];\n        if\
    \ (d < 0) ++tri[i][j];\n      }\n    }\n  }\n};"
  dependsOn:
  - geo/angle_sort.hpp
  - geo/base.hpp
  - random/base.hpp
  isVerificationFile: false
  path: geo/count_points_in_triangles.hpp
  requiredBy: []
  timestamp: '2022-12-11 11:11:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/count_points_in_triangles.test.cpp
  - test/atcoder/abc202_f.test.cpp
documentation_of: geo/count_points_in_triangles.hpp
layout: document
redirect_from:
- /library/geo/count_points_in_triangles.hpp
- /library/geo/count_points_in_triangles.hpp.html
title: geo/count_points_in_triangles.hpp
---
