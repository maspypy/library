---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: geo/base.hpp
    title: geo/base.hpp
  - icon: ':x:'
    path: geo/dynamicupperhull.hpp
    title: geo/dynamicupperhull.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/2_library_checker/geometry/convex_layers.test.cpp
    title: test/2_library_checker/geometry/convex_layers.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/1599/problem/D
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
    \ r;\n  }\n};\n#line 2 \"geo/dynamicupperhull.hpp\"\n\r\n/*\r\nhttps://codeforces.com/blog/entry/75929\r\
    \n\u52D5\u7684\u51F8\u5305\u3002\r\nx \u5EA7\u6A19\u3067\u30BD\u30FC\u30C8\u3057\
    \u3066\u5B8C\u5168\u4E8C\u5206\u6728\u306E\u30BB\u30B0\u6728\u306E\u5F62\u306B\
    \u3057\u3066\u304A\u304F\u3002\r\n\u30BB\u30B0\u6728\u306E\u30DE\u30FC\u30B8\u90E8\
    \u5206\uFF08\u6B21\u306E bridge \u3092\u6C42\u3081\u308B\uFF09\u3067\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\u3002\r\nbridge \u540C\u58EB\u306E 4 \u70B9\u3067\u306E\
    \u4E0A\u5074\u51F8\u5305\u3092\u898B\u308C\u3070\u3001\u6B21\u306B\u63A2\u7D22\
    \u3059\u308B\u3079\u304D\u533A\u9593\u5BFE\u304C\u5206\u304B\u308B\u3002\r\n\r\
    \n\u69CB\u7BC9 O(NlogN)\u3001\u66F4\u65B0 O(Nlog^2N)\r\n\u5EA7\u6A19 10^9 \u4EE5\
    \u4E0B\u306E\u6574\u6570\u3092\u4EEE\u5B9A\r\n*/\r\ntemplate <typename Point>\r\
    \nstruct DynamicUpperHull {\r\n  struct node {\r\n    int l, r;   // \u7BC4\u56F2\
    \ (-1 if no vertex)\r\n    int bl, br; // bridge idx\r\n  };\r\n  int N, sz;\r\
    \n  vc<Point> P;\r\n  vc<node> seg;\r\n  // \u53D7\u3051\u53D6\u3063\u305F\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3068\u306E\u5BFE\u5FDC\r\n  vc<int> to_original_idx,\
    \ to_seg_idx;\r\n\r\n  DynamicUpperHull(vc<Point> P) : DynamicUpperHull(P, 0)\
    \ {}\r\n  DynamicUpperHull(vc<Point> P, bool b)\r\n      : DynamicUpperHull(P,\
    \ vc<bool>(len(P), b)) {}\r\n\r\n  DynamicUpperHull(vc<Point> _P, vc<bool> isin)\
    \ : N(len(_P)), P(_P) {\r\n    to_original_idx = argsort(P);\r\n    sort(all(P));\r\
    \n    sz = 1;\r\n    while (sz < N) sz *= 2;\r\n    to_seg_idx.resize(N);\r\n\
    \    seg.assign(sz + sz, {-1, -1, -1, -1});\r\n    for (int i = 0; i < N; ++i)\
    \ to_seg_idx[to_original_idx[i]] = i;\r\n    for (int i = 0; i < N; ++i)\r\n \
    \     if (isin[to_original_idx[i]]) { seg[sz + i] = {i, i + 1, i, i}; }\r\n  \
    \  FOR3_R(i, 1, sz) update(i);\r\n  }\r\n\r\n  void insert(int i) {\r\n    i =\
    \ to_seg_idx[i];\r\n    seg[sz + i] = {i, i + 1, i, i};\r\n    i = (sz + i) /\
    \ 2;\r\n    while (i) {\r\n      update(i);\r\n      i /= 2;\r\n    }\r\n  }\r\
    \n  void add(int i) { insert(i); }\r\n\r\n  void erase(int i) {\r\n    i = to_seg_idx[i];\r\
    \n    seg[sz + i] = {-1, -1, -1, -1};\r\n    i = (sz + i) / 2;\r\n    while (i)\
    \ {\r\n      update(i);\r\n      i /= 2;\r\n    }\r\n  }\r\n  void remove(int\
    \ i) { insert(i); }\r\n\r\n  inline bool exist(int i) { return seg[i].r != -1;\
    \ }\r\n\r\n  void update(int i) {\r\n    if (!exist(2 * i + 0) && !exist(2 * i\
    \ + 1)) {\r\n      seg[i].r = -1;\r\n      return;\r\n    }\r\n    if (!exist(2\
    \ * i + 0)) {\r\n      seg[i] = seg[2 * i + 1];\r\n      return;\r\n    }\r\n\
    \    if (!exist(2 * i + 1)) {\r\n      seg[i] = seg[2 * i + 0];\r\n      return;\r\
    \n    }\r\n    int p = 2 * i, q = 2 * i + 1;\r\n    ll X = P[seg[q].l].x;\r\n\
    \    while (p < sz || q < sz) {\r\n      if (p < sz && !exist(2 * p + 0)) {\r\n\
    \        p = 2 * p + 1;\r\n        continue;\r\n      }\r\n      if (p < sz &&\
    \ !exist(2 * p + 1)) {\r\n        p = 2 * p + 0;\r\n        continue;\r\n    \
    \  }\r\n      if (q < sz && !exist(2 * q + 0)) {\r\n        q = 2 * q + 1;\r\n\
    \        continue;\r\n      }\r\n      if (q < sz && !exist(2 * q + 1)) {\r\n\
    \        q = 2 * q + 0;\r\n        continue;\r\n      }\r\n      int a = seg[p].bl,\
    \ b = seg[p].br, c = seg[q].bl, d = seg[q].br;\r\n      if (a != b && (P[b] -\
    \ P[a]).det(P[c] - P[a]) > 0) p = p * 2 + 0;\r\n      elif (c != d && (P[c] -\
    \ P[b]).det(P[d] - P[b]) > 0) q = 2 * q + 1;\r\n      elif (a == b) q = 2 * q\
    \ + 0;\r\n      elif (c == d) p = 2 * p + 1;\r\n      else {\r\n        i128 c1\
    \ = (P[b] - P[a]).det(P[c] - P[a]);\r\n        i128 c2 = (P[a] - P[b]).det(P[d]\
    \ - P[b]);\r\n        if (c1 + c2 == 0 || c1 * P[d].x + c2 * P[c].x < X * (c1\
    \ + c2)) {\r\n          p = 2 * p + 1;\r\n        } else {\r\n          q = 2\
    \ * q + 0;\r\n        }\r\n      }\r\n    }\r\n    seg[i].l = seg[2 * i].l, seg[i].r\
    \ = seg[2 * i + 1].r;\r\n    seg[i].bl = seg[p].l, seg[i].br = seg[q].l;\r\n \
    \ }\r\n\r\n  vc<int> get() {\r\n    // output sensitive complexity\r\n    vc<int>\
    \ res;\r\n    auto dfs = [&](auto self, int k, int l, int r) -> void {\r\n   \
    \   if (!exist(k) || l >= r) return;\r\n      if (k >= sz) {\r\n        res.eb(seg[k].l);\r\
    \n        return;\r\n      }\r\n      if (!exist(2 * k + 0)) return self(self,\
    \ 2 * k + 1, l, r);\r\n      if (!exist(2 * k + 1)) return self(self, 2 * k +\
    \ 0, l, r);\r\n      if (r <= seg[k].bl) return self(self, 2 * k + 0, l, r);\r\
    \n      if (seg[k].br <= l) return self(self, 2 * k + 1, l, r);\r\n      self(self,\
    \ 2 * k + 0, l, seg[k].bl + 1);\r\n      self(self, 2 * k + 1, seg[k].br, r);\r\
    \n    };\r\n    dfs(dfs, 1, 0, N);\r\n    for (auto&& i: res) i = to_original_idx[i];\r\
    \n    return res;\r\n  }\r\n\r\n  void debug() {\r\n    print(\"points\");\r\n\
    \    FOR(i, len(P)) print(i, P[i].x, P[i].y);\r\n    print(\"seg\");\r\n    FOR(i,\
    \ len(seg)) print(i, seg[i].l, seg[i].r, seg[i].bl, seg[i].br);\r\n    print(\"\
    get\");\r\n    print(get());\r\n  }\r\n};\r\n#line 2 \"geo/convex_layers.hpp\"\
    \n\n// https://codeforces.com/contest/1599/problem/D\n// \u51FA\u529B\u306F\u53CD\
    \u6642\u8A08\u56DE\u308A\u3067\u3042\u308B\nvvc<int> convex_layers(vc<Point<ll>>\
    \ points) {\n  int N = len(points);\n  DynamicUpperHull<Point<ll>> DUH(points,\
    \ 1);\n  FOR(i, N) points[i] = -points[i];\n  DynamicUpperHull<Point<ll>> DLH(points,\
    \ 1);\n  vvc<int> ANS;\n  int done = 0;\n  int k = 0;\n  while (done < N) {\n\
    \    ++k;\n    auto A = DLH.get();\n    auto B = DUH.get();\n    if (len(A) >=\
    \ 2) {\n      POP(A), POP(B);\n      A.insert(A.end(), all(B));\n      reverse(all(A));\n\
    \    }\n    ANS.eb(A);\n    for (auto&& i: A) {\n      ++done;\n      DUH.erase(i);\n\
    \      DLH.erase(i);\n    }\n  }\n  return ANS;\n}\n"
  code: "#include \"geo/dynamicupperhull.hpp\"\n\n// https://codeforces.com/contest/1599/problem/D\n\
    // \u51FA\u529B\u306F\u53CD\u6642\u8A08\u56DE\u308A\u3067\u3042\u308B\nvvc<int>\
    \ convex_layers(vc<Point<ll>> points) {\n  int N = len(points);\n  DynamicUpperHull<Point<ll>>\
    \ DUH(points, 1);\n  FOR(i, N) points[i] = -points[i];\n  DynamicUpperHull<Point<ll>>\
    \ DLH(points, 1);\n  vvc<int> ANS;\n  int done = 0;\n  int k = 0;\n  while (done\
    \ < N) {\n    ++k;\n    auto A = DLH.get();\n    auto B = DUH.get();\n    if (len(A)\
    \ >= 2) {\n      POP(A), POP(B);\n      A.insert(A.end(), all(B));\n      reverse(all(A));\n\
    \    }\n    ANS.eb(A);\n    for (auto&& i: A) {\n      ++done;\n      DUH.erase(i);\n\
    \      DLH.erase(i);\n    }\n  }\n  return ANS;\n}"
  dependsOn:
  - geo/dynamicupperhull.hpp
  - geo/base.hpp
  isVerificationFile: false
  path: geo/convex_layers.hpp
  requiredBy: []
  timestamp: '2025-05-05 02:10:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/2_library_checker/geometry/convex_layers.test.cpp
documentation_of: geo/convex_layers.hpp
layout: document
redirect_from:
- /library/geo/convex_layers.hpp
- /library/geo/convex_layers.hpp.html
title: geo/convex_layers.hpp
---
