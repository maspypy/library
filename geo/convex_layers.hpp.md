---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':heavy_check_mark:'
    path: geo/dynamic_upper_hull.hpp
    title: geo/dynamic_upper_hull.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/geometry/convex_layers.test.cpp
    title: test/2_library_checker/geometry/convex_layers.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1599/problem/D
    - https://github.com/maspypy/library/blob/main/geo/convex_layers.hpp
  bundledCode: "#line 1 \"geo/convex_layers.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/convex_layers.hpp\n\
    #line 1 \"geo/dynamic_upper_hull.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/dynamic_upper_hull.hpp\n\
    #line 1 \"geo/base.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/geo/base.hpp\n\
    template <typename T>\nstruct Point {\n  T x, y;\n\n  Point() : x(0), y(0) {}\n\
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
    \  return 0;\n}\n\ntemplate <typename REAL, typename T, typename U>\nREAL distance(Point<T>\
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
    \ 3 \"geo/dynamic_upper_hull.hpp\"\n\n/*\nhttps://codeforces.com/blog/entry/75929\n\
    \u52D5\u7684\u51F8\u5305\u3002\nx \u5EA7\u6A19\u3067\u30BD\u30FC\u30C8\u3057\u3066\
    \u5B8C\u5168\u4E8C\u5206\u6728\u306E\u30BB\u30B0\u6728\u306E\u5F62\u306B\u3057\
    \u3066\u304A\u304F\u3002\n\u30BB\u30B0\u6728\u306E\u30DE\u30FC\u30B8\u90E8\u5206\
    \uFF08\u6B21\u306E bridge \u3092\u6C42\u3081\u308B\uFF09\u3067\u4E8C\u5206\u63A2\
    \u7D22\u3059\u308B\u3002\nbridge \u540C\u58EB\u306E 4 \u70B9\u3067\u306E\u4E0A\
    \u5074\u51F8\u5305\u3092\u898B\u308C\u3070\u3001\u6B21\u306B\u63A2\u7D22\u3059\
    \u308B\u3079\u304D\u533A\u9593\u5BFE\u304C\u5206\u304B\u308B\u3002\n\n\u69CB\u7BC9\
    \ O(NlogN)\u3001\u66F4\u65B0 O(Nlog^2N)\n\u5EA7\u6A19 10^9 \u4EE5\u4E0B\u306E\u6574\
    \u6570\u3092\u4EEE\u5B9A\n*/\ntemplate <typename Point>\nstruct Dynamic_Upper_Hull\
    \ {\n  struct node {\n    int l, r;    // \u7BC4\u56F2 (-1 if no vertex)\n   \
    \ int bl, br;  // bridge idx\n  };\n  int N, sz;\n  vc<Point> P;\n  vc<node> seg;\n\
    \  // \u53D7\u3051\u53D6\u3063\u305F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3068\
    \u306E\u5BFE\u5FDC\n  vc<int> to_original_idx, to_seg_idx;\n\n  Dynamic_Upper_Hull(vc<Point>\
    \ P) : Dynamic_Upper_Hull(P, 0) {}\n  Dynamic_Upper_Hull(vc<Point> P, bool b)\n\
    \      : Dynamic_Upper_Hull(P, vc<bool>(len(P), b)) {}\n\n  Dynamic_Upper_Hull(vc<Point>\
    \ _P, vc<bool> isin) : N(len(_P)), P(_P) {\n    to_original_idx = argsort(P);\n\
    \    sort(all(P));\n    sz = 1;\n    while (sz < N) sz *= 2;\n    to_seg_idx.resize(N);\n\
    \    seg.assign(sz + sz, {-1, -1, -1, -1});\n    for (int i = 0; i < N; ++i) to_seg_idx[to_original_idx[i]]\
    \ = i;\n    for (int i = 0; i < N; ++i)\n      if (isin[to_original_idx[i]]) {\n\
    \        seg[sz + i] = {i, i + 1, i, i};\n      }\n    FOR3_R(i, 1, sz) update(i);\n\
    \  }\n\n  void insert(int i) {\n    i = to_seg_idx[i];\n    seg[sz + i] = {i,\
    \ i + 1, i, i};\n    i = (sz + i) / 2;\n    while (i) {\n      update(i);\n  \
    \    i /= 2;\n    }\n  }\n  void add(int i) { insert(i); }\n\n  void erase(int\
    \ i) {\n    i = to_seg_idx[i];\n    seg[sz + i] = {-1, -1, -1, -1};\n    i = (sz\
    \ + i) / 2;\n    while (i) {\n      update(i);\n      i /= 2;\n    }\n  }\n  void\
    \ remove(int i) { insert(i); }\n\n  inline bool exist(int i) { return seg[i].r\
    \ != -1; }\n\n  void update(int i) {\n    if (!exist(2 * i + 0) && !exist(2 *\
    \ i + 1)) {\n      seg[i].r = -1;\n      return;\n    }\n    if (!exist(2 * i\
    \ + 0)) {\n      seg[i] = seg[2 * i + 1];\n      return;\n    }\n    if (!exist(2\
    \ * i + 1)) {\n      seg[i] = seg[2 * i + 0];\n      return;\n    }\n    int p\
    \ = 2 * i, q = 2 * i + 1;\n    ll X = P[seg[q].l].x;\n    while (p < sz || q <\
    \ sz) {\n      if (p < sz && !exist(2 * p + 0)) {\n        p = 2 * p + 1;\n  \
    \      continue;\n      }\n      if (p < sz && !exist(2 * p + 1)) {\n        p\
    \ = 2 * p + 0;\n        continue;\n      }\n      if (q < sz && !exist(2 * q +\
    \ 0)) {\n        q = 2 * q + 1;\n        continue;\n      }\n      if (q < sz\
    \ && !exist(2 * q + 1)) {\n        q = 2 * q + 0;\n        continue;\n      }\n\
    \      int a = seg[p].bl, b = seg[p].br, c = seg[q].bl, d = seg[q].br;\n     \
    \ if (a != b && (P[b] - P[a]).det(P[c] - P[a]) > 0) p = p * 2 + 0;\n      elif\
    \ (c != d && (P[c] - P[b]).det(P[d] - P[b]) > 0) q = 2 * q + 1;\n      elif (a\
    \ == b) q = 2 * q + 0;\n      elif (c == d) p = 2 * p + 1;\n      else {\n   \
    \     i128 c1 = (P[b] - P[a]).det(P[c] - P[a]);\n        i128 c2 = (P[a] - P[b]).det(P[d]\
    \ - P[b]);\n        if (c1 + c2 == 0 || c1 * P[d].x + c2 * P[c].x < X * (c1 +\
    \ c2)) {\n          p = 2 * p + 1;\n        } else {\n          q = 2 * q + 0;\n\
    \        }\n      }\n    }\n    seg[i].l = seg[2 * i].l, seg[i].r = seg[2 * i\
    \ + 1].r;\n    seg[i].bl = seg[p].l, seg[i].br = seg[q].l;\n  }\n\n  vc<int> get()\
    \ {\n    // output sensitive complexity\n    vc<int> res;\n    auto dfs = [&](auto\
    \ self, int k, int l, int r) -> void {\n      if (!exist(k) || l >= r) return;\n\
    \      if (k >= sz) {\n        res.eb(seg[k].l);\n        return;\n      }\n \
    \     if (!exist(2 * k + 0)) return self(self, 2 * k + 1, l, r);\n      if (!exist(2\
    \ * k + 1)) return self(self, 2 * k + 0, l, r);\n      if (r <= seg[k].bl) return\
    \ self(self, 2 * k + 0, l, r);\n      if (seg[k].br <= l) return self(self, 2\
    \ * k + 1, l, r);\n      self(self, 2 * k + 0, l, seg[k].bl + 1);\n      self(self,\
    \ 2 * k + 1, seg[k].br, r);\n    };\n    dfs(dfs, 1, 0, N);\n    for (auto&& i\
    \ : res) i = to_original_idx[i];\n    return res;\n  }\n\n  void debug() {\n \
    \   print(\"points\");\n    FOR(i, len(P)) print(i, P[i].x, P[i].y);\n    print(\"\
    seg\");\n    FOR(i, len(seg)) print(i, seg[i].l, seg[i].r, seg[i].bl, seg[i].br);\n\
    \    print(\"get\");\n    print(get());\n  }\n};\n#line 3 \"geo/convex_layers.hpp\"\
    \n\n// https://codeforces.com/contest/1599/problem/D\n// \u51FA\u529B\u306F\u53CD\
    \u6642\u8A08\u56DE\u308A\u3067\u3042\u308B\nvvc<int> convex_layers(vc<Point<ll>>\
    \ points) {\n  int N = len(points);\n  Dynamic_Upper_Hull<Point<ll>> DUH(points,\
    \ 1);\n  FOR(i, N) points[i] = -points[i];\n  Dynamic_Upper_Hull<Point<ll>> DLH(points,\
    \ 1);\n  vvc<int> ANS;\n  int done = 0;\n  int k = 0;\n  while (done < N) {\n\
    \    ++k;\n    auto A = DLH.get();\n    auto B = DUH.get();\n    if (len(A) >=\
    \ 2) {\n      POP(A), POP(B);\n      A.insert(A.end(), all(B));\n      reverse(all(A));\n\
    \    }\n    ANS.eb(A);\n    for (auto&& i : A) {\n      ++done;\n      DUH.erase(i);\n\
    \      DLH.erase(i);\n    }\n  }\n  return ANS;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/geo/convex_layers.hpp\n\
    #include \"geo/dynamic_upper_hull.hpp\"\n\n// https://codeforces.com/contest/1599/problem/D\n\
    // \u51FA\u529B\u306F\u53CD\u6642\u8A08\u56DE\u308A\u3067\u3042\u308B\nvvc<int>\
    \ convex_layers(vc<Point<ll>> points) {\n  int N = len(points);\n  Dynamic_Upper_Hull<Point<ll>>\
    \ DUH(points, 1);\n  FOR(i, N) points[i] = -points[i];\n  Dynamic_Upper_Hull<Point<ll>>\
    \ DLH(points, 1);\n  vvc<int> ANS;\n  int done = 0;\n  int k = 0;\n  while (done\
    \ < N) {\n    ++k;\n    auto A = DLH.get();\n    auto B = DUH.get();\n    if (len(A)\
    \ >= 2) {\n      POP(A), POP(B);\n      A.insert(A.end(), all(B));\n      reverse(all(A));\n\
    \    }\n    ANS.eb(A);\n    for (auto&& i : A) {\n      ++done;\n      DUH.erase(i);\n\
    \      DLH.erase(i);\n    }\n  }\n  return ANS;\n}"
  dependsOn:
  - geo/dynamic_upper_hull.hpp
  - geo/base.hpp
  isVerificationFile: false
  path: geo/convex_layers.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/geometry/convex_layers.test.cpp
documentation_of: geo/convex_layers.hpp
layout: document
redirect_from:
- /library/geo/convex_layers.hpp
- /library/geo/convex_layers.hpp.html
title: geo/convex_layers.hpp
---
