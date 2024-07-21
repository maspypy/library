---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geo/lower_convexhull_segtree.hpp\"\n// ALLOW_180=true \u306E\
    \u3068\u304D\u306B\u540C\u4E00\u5EA7\u6A19\u306E\u70B9\u304C\u3042\u308B\u3068\
    \u58CA\u308C\u308B\u6C17\u304C\u3059\u308B\ntemplate <typename T, bool ALLOW_180\
    \ = false>\nstruct Lower_ConvexHull_SegTree {\n  struct P {\n    T x, y;\n   \
    \ P() : x(0), y(0) {}\n    P(T x, T y) : x(x), y(y) {}\n    P operator+=(const\
    \ P p) {\n      x += p.x, y += p.y;\n      return *this;\n    }\n    P operator-=(const\
    \ P p) {\n      x -= p.x, y -= p.y;\n      return *this;\n    }\n    P operator+(P\
    \ p) const { return {x + p.x, y + p.y}; }\n    P operator-(P p) const { return\
    \ {x - p.x, y - p.y}; }\n    bool operator<(P p) const { return (x != p.x ? x\
    \ < p.x : y < p.y); }\n    bool operator==(P p) const { return (x == p.x && y\
    \ == p.y); }\n    i128 dot(T a, T b) { return a * x + b * y; }\n  };\n\n  struct\
    \ Data {\n    int L, R;\n    T max_x;\n    bool exist() { return L != -1; };\n\
    \  };\n  int n, log, size;\n  vc<P> point;\n  vc<Data> dat;\n\n  Lower_ConvexHull_SegTree()\
    \ {}\n  Lower_ConvexHull_SegTree(int n) { build(n); }\n  template <typename F>\n\
    \  Lower_ConvexHull_SegTree(int n, F f) {\n    build(n, f);\n  }\n  void build(int\
    \ m) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1 <<\
    \ log;\n    point.assign(m, P(0, 0));\n    dat.assign(2 * size, Data(-1, -1, 0));\n\
    \  }\n  template <typename F>\n  void build(int m, F f) {\n    n = m, log = 1;\n\
    \    while ((1 << log) < n) ++log;\n    size = 1 << log;\n    point.assign(m,\
    \ P(0, 0));\n    dat.assign(2 * size, Data(-1, -1, 0));\n    FOR(i, m) {\n   \
    \   auto [exist, x, y] = f(i);\n      point[i] = P(x, y);\n      dat[size + i]\
    \ = (exist ? Data(i, i, x) : Data(-1, -1, x));\n    }\n    FOR_R(i, 1, size) update(i);\n\
    \  }\n\n  void set(int i, bool exist, T x, T y) {\n    point[i] = {x, y};\n  \
    \  dat[size + i] = (exist ? Data(i, i, x) : Data(-1, -1, x));\n    i += size;\n\
    \    while (i > 1) i /= 2, update(i);\n  }\n\n  // \u4E2D\uFF1A1, \u5883\u754C\
    \uFF1A0, \u5916\uFF1A-1\n  int side(T x, T y) {\n    if (!dat[1].exist) return\
    \ -1;\n    P a(x, y);\n    int p = 1;\n    while (1) {\n      down_while_trivial(p);\n\
    \      P L = point[dat[p].L], R = point[dat[p].R];\n      if (a < L) { p = 2 *\
    \ p + 0; }\n      elif (a == L) { return 0; }\n      elif (L < a && a < R) { return\
    \ -ccw(L, a, R); }\n      elif (R == a) { return 0; }\n      else {\n        p\
    \ = 2 * p + 1;\n      }\n      if (p >= 2 * size) return -1;\n    }\n  }\n  i128\
    \ min_dot(T a, T b) { return min_dot_at(1, a, b); }\n  i128 min_dot(int L, int\
    \ R, T a, T b) {\n    L += size, R += size;\n    i128 ANS = infty<i128>;\n   \
    \ while (L < R) {\n      if (L & 1) chmin(ANS, min_dot_at(L++, a, b));\n     \
    \ if (R & 1) chmin(ANS, min_dot_at(--R, a, b));\n      L /= 2, R /= 2;\n    }\n\
    \    return ANS;\n  }\n\n  // \u540C\u4E00\u5EA7\u6A19\u306E\u70B9\u304C\u3042\
    \u308B\u3068 unique \u3055\u308C\u305F\u308A\u3055\u308C\u306A\u304B\u3063\u305F\
    \u308A\u3059\u308B\u306F\u305A\uFF1F\n  vc<int> get_hull() {\n    vc<int> res;\n\
    \    // closed range\n    auto dfs = [&](auto& dfs, int p, int lo, int hi) ->\
    \ void {\n      if (!dat[p].exist() || hi < lo) return;\n      down_while_trivial(p);\n\
    \      if (size <= p) {\n        res.eb(p - size);\n        return;\n      }\n\
    \      if (!(dat[p].L < hi)) return dfs(dfs, 2 * p + 0, lo, hi);\n      if (!(lo\
    \ < dat[p].R)) return dfs(dfs, 2 * p + 1, lo, hi);\n      dfs(dfs, 2 * p + 0,\
    \ lo, dat[p].L);\n      dfs(dfs, 2 * p + 1, dat[p].R, hi);\n    };\n    dfs(dfs,\
    \ 1, 0, n - 1);\n    return res;\n  }\n\nprivate:\n  // A,B,C \u306F\u6607\u9806\
    . \u540C\u4E00\u5EA7\u6A19\u306E\u70B9\u306F\u30BF\u30A4\u30D6\u30EC\u30A4\u30AF\
    \u3059\u308B.\n  int ccw(P A, P B, P C) {\n    auto [x1, y1] = B - A;\n    auto\
    \ [x2, y2] = C - B;\n    if (x1 == 0) y1 = 1;\n    if (x2 == 0) y2 = 1;\n    i128\
    \ d = i128(x1) * y2 - i128(x2) * y1;\n    return (d != 0 ? (d > 0 ? 1 : -1) :\
    \ 0);\n  }\n\n  inline void down_while_trivial(int& p) {\n    while (p < size)\
    \ {\n      if (!dat[2 * p + 0].exist()) p = 2 * p + 1;\n      elif (!dat[2 * p\
    \ + 1].exist()) p = 2 * p + 0;\n      else return;\n    }\n  }\n\n  void update(int\
    \ i) {\n    assert(1 <= i && i < size);\n    if (!dat[2 * i + 0].exist()) { dat[i]\
    \ = dat[2 * i + 1]; }\n    elif (!dat[2 * i + 1].exist()) { dat[i] = dat[2 * i\
    \ + 0]; }\n    else {\n      dat[i].max_x = dat[2 * i + 1].max_x;\n      tie(dat[i].L,\
    \ dat[i].R) = find_bridge(i);\n    }\n  }\n\n  pair<int, int> find_bridge(int\
    \ i) {\n    int p = 2 * i + 0, q = 2 * i + 1;\n    while (1) {\n      down_while_trivial(p),\
    \ down_while_trivial(q);\n      if (size <= p && size <= q) break;\n      P A\
    \ = point[dat[p].L], B = point[dat[p].R];\n      P C = point[dat[q].L], D = point[dat[q].R];\n\
    \      constexpr int ccw_thresh = (ALLOW_180 ? 0 : 1);\n      if (p >= size) {\n\
    \        q = (ccw(B, C, D) < ccw_thresh ? 2 * q + 1 : 2 * q + 0);\n      }\n \
    \     elif (q >= size) {\n        p = (ccw(A, B, C) < ccw_thresh ? 2 * p + 0 :\
    \ 2 * p + 1);\n      }\n      elif (ccw(A, B, C) < ccw_thresh) { p = 2 * p + 0;\
    \ }\n      elif (ccw(B, C, D) < ccw_thresh) { q = 2 * q + 1; }\n      else {\n\
    \        ll x1 = A.x, x2 = B.x, x3 = C.x, x4 = D.x;\n        ll y1 = A.y, y2 =\
    \ B.y, y3 = C.y, y4 = D.y;\n        ll num\n            = (x1 * y2 - y1 * x2)\
    \ * (x3 - x4) - (x1 - x2) * (x3 * y4 - x4 * y3);\n        ll den = (x1 - x2) *\
    \ (y3 - y4) - (y1 - y2) * (x3 - x4);\n        if (den == 0 || num <= dat[p].max_x\
    \ * den)\n          p = 2 * p + 1;\n        else\n          q = 2 * q + 0;\n \
    \     }\n    }\n    return {p - size, q - size};\n  }\n\n  i128 min_dot_at(int\
    \ p, T a, T b) {\n    assert(b >= 0);\n    if (!dat[p].exist) return infty<i128>;\n\
    \    while (1) {\n      down_while_trivial(p);\n      if (size <= p) break;\n\
    \      i128 x1 = point[dat[p].L].dot(a, b), x2 = point[dat[p].R].dot(a, b);\n\
    \      if (x1 <= x2) p = 2 * p + 0;\n      if (x1 > x2) p = 2 * p + 1;\n    }\n\
    \    return dat[p].L.dot(a, b);\n  }\n};\n"
  code: "// ALLOW_180=true \u306E\u3068\u304D\u306B\u540C\u4E00\u5EA7\u6A19\u306E\u70B9\
    \u304C\u3042\u308B\u3068\u58CA\u308C\u308B\u6C17\u304C\u3059\u308B\ntemplate <typename\
    \ T, bool ALLOW_180 = false>\nstruct Lower_ConvexHull_SegTree {\n  struct P {\n\
    \    T x, y;\n    P() : x(0), y(0) {}\n    P(T x, T y) : x(x), y(y) {}\n    P\
    \ operator+=(const P p) {\n      x += p.x, y += p.y;\n      return *this;\n  \
    \  }\n    P operator-=(const P p) {\n      x -= p.x, y -= p.y;\n      return *this;\n\
    \    }\n    P operator+(P p) const { return {x + p.x, y + p.y}; }\n    P operator-(P\
    \ p) const { return {x - p.x, y - p.y}; }\n    bool operator<(P p) const { return\
    \ (x != p.x ? x < p.x : y < p.y); }\n    bool operator==(P p) const { return (x\
    \ == p.x && y == p.y); }\n    i128 dot(T a, T b) { return a * x + b * y; }\n \
    \ };\n\n  struct Data {\n    int L, R;\n    T max_x;\n    bool exist() { return\
    \ L != -1; };\n  };\n  int n, log, size;\n  vc<P> point;\n  vc<Data> dat;\n\n\
    \  Lower_ConvexHull_SegTree() {}\n  Lower_ConvexHull_SegTree(int n) { build(n);\
    \ }\n  template <typename F>\n  Lower_ConvexHull_SegTree(int n, F f) {\n    build(n,\
    \ f);\n  }\n  void build(int m) {\n    n = m, log = 1;\n    while ((1 << log)\
    \ < n) ++log;\n    size = 1 << log;\n    point.assign(m, P(0, 0));\n    dat.assign(2\
    \ * size, Data(-1, -1, 0));\n  }\n  template <typename F>\n  void build(int m,\
    \ F f) {\n    n = m, log = 1;\n    while ((1 << log) < n) ++log;\n    size = 1\
    \ << log;\n    point.assign(m, P(0, 0));\n    dat.assign(2 * size, Data(-1, -1,\
    \ 0));\n    FOR(i, m) {\n      auto [exist, x, y] = f(i);\n      point[i] = P(x,\
    \ y);\n      dat[size + i] = (exist ? Data(i, i, x) : Data(-1, -1, x));\n    }\n\
    \    FOR_R(i, 1, size) update(i);\n  }\n\n  void set(int i, bool exist, T x, T\
    \ y) {\n    point[i] = {x, y};\n    dat[size + i] = (exist ? Data(i, i, x) : Data(-1,\
    \ -1, x));\n    i += size;\n    while (i > 1) i /= 2, update(i);\n  }\n\n  //\
    \ \u4E2D\uFF1A1, \u5883\u754C\uFF1A0, \u5916\uFF1A-1\n  int side(T x, T y) {\n\
    \    if (!dat[1].exist) return -1;\n    P a(x, y);\n    int p = 1;\n    while\
    \ (1) {\n      down_while_trivial(p);\n      P L = point[dat[p].L], R = point[dat[p].R];\n\
    \      if (a < L) { p = 2 * p + 0; }\n      elif (a == L) { return 0; }\n    \
    \  elif (L < a && a < R) { return -ccw(L, a, R); }\n      elif (R == a) { return\
    \ 0; }\n      else {\n        p = 2 * p + 1;\n      }\n      if (p >= 2 * size)\
    \ return -1;\n    }\n  }\n  i128 min_dot(T a, T b) { return min_dot_at(1, a, b);\
    \ }\n  i128 min_dot(int L, int R, T a, T b) {\n    L += size, R += size;\n   \
    \ i128 ANS = infty<i128>;\n    while (L < R) {\n      if (L & 1) chmin(ANS, min_dot_at(L++,\
    \ a, b));\n      if (R & 1) chmin(ANS, min_dot_at(--R, a, b));\n      L /= 2,\
    \ R /= 2;\n    }\n    return ANS;\n  }\n\n  // \u540C\u4E00\u5EA7\u6A19\u306E\u70B9\
    \u304C\u3042\u308B\u3068 unique \u3055\u308C\u305F\u308A\u3055\u308C\u306A\u304B\
    \u3063\u305F\u308A\u3059\u308B\u306F\u305A\uFF1F\n  vc<int> get_hull() {\n   \
    \ vc<int> res;\n    // closed range\n    auto dfs = [&](auto& dfs, int p, int\
    \ lo, int hi) -> void {\n      if (!dat[p].exist() || hi < lo) return;\n     \
    \ down_while_trivial(p);\n      if (size <= p) {\n        res.eb(p - size);\n\
    \        return;\n      }\n      if (!(dat[p].L < hi)) return dfs(dfs, 2 * p +\
    \ 0, lo, hi);\n      if (!(lo < dat[p].R)) return dfs(dfs, 2 * p + 1, lo, hi);\n\
    \      dfs(dfs, 2 * p + 0, lo, dat[p].L);\n      dfs(dfs, 2 * p + 1, dat[p].R,\
    \ hi);\n    };\n    dfs(dfs, 1, 0, n - 1);\n    return res;\n  }\n\nprivate:\n\
    \  // A,B,C \u306F\u6607\u9806. \u540C\u4E00\u5EA7\u6A19\u306E\u70B9\u306F\u30BF\
    \u30A4\u30D6\u30EC\u30A4\u30AF\u3059\u308B.\n  int ccw(P A, P B, P C) {\n    auto\
    \ [x1, y1] = B - A;\n    auto [x2, y2] = C - B;\n    if (x1 == 0) y1 = 1;\n  \
    \  if (x2 == 0) y2 = 1;\n    i128 d = i128(x1) * y2 - i128(x2) * y1;\n    return\
    \ (d != 0 ? (d > 0 ? 1 : -1) : 0);\n  }\n\n  inline void down_while_trivial(int&\
    \ p) {\n    while (p < size) {\n      if (!dat[2 * p + 0].exist()) p = 2 * p +\
    \ 1;\n      elif (!dat[2 * p + 1].exist()) p = 2 * p + 0;\n      else return;\n\
    \    }\n  }\n\n  void update(int i) {\n    assert(1 <= i && i < size);\n    if\
    \ (!dat[2 * i + 0].exist()) { dat[i] = dat[2 * i + 1]; }\n    elif (!dat[2 * i\
    \ + 1].exist()) { dat[i] = dat[2 * i + 0]; }\n    else {\n      dat[i].max_x =\
    \ dat[2 * i + 1].max_x;\n      tie(dat[i].L, dat[i].R) = find_bridge(i);\n   \
    \ }\n  }\n\n  pair<int, int> find_bridge(int i) {\n    int p = 2 * i + 0, q =\
    \ 2 * i + 1;\n    while (1) {\n      down_while_trivial(p), down_while_trivial(q);\n\
    \      if (size <= p && size <= q) break;\n      P A = point[dat[p].L], B = point[dat[p].R];\n\
    \      P C = point[dat[q].L], D = point[dat[q].R];\n      constexpr int ccw_thresh\
    \ = (ALLOW_180 ? 0 : 1);\n      if (p >= size) {\n        q = (ccw(B, C, D) <\
    \ ccw_thresh ? 2 * q + 1 : 2 * q + 0);\n      }\n      elif (q >= size) {\n  \
    \      p = (ccw(A, B, C) < ccw_thresh ? 2 * p + 0 : 2 * p + 1);\n      }\n   \
    \   elif (ccw(A, B, C) < ccw_thresh) { p = 2 * p + 0; }\n      elif (ccw(B, C,\
    \ D) < ccw_thresh) { q = 2 * q + 1; }\n      else {\n        ll x1 = A.x, x2 =\
    \ B.x, x3 = C.x, x4 = D.x;\n        ll y1 = A.y, y2 = B.y, y3 = C.y, y4 = D.y;\n\
    \        ll num\n            = (x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3\
    \ * y4 - x4 * y3);\n        ll den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 -\
    \ x4);\n        if (den == 0 || num <= dat[p].max_x * den)\n          p = 2 *\
    \ p + 1;\n        else\n          q = 2 * q + 0;\n      }\n    }\n    return {p\
    \ - size, q - size};\n  }\n\n  i128 min_dot_at(int p, T a, T b) {\n    assert(b\
    \ >= 0);\n    if (!dat[p].exist) return infty<i128>;\n    while (1) {\n      down_while_trivial(p);\n\
    \      if (size <= p) break;\n      i128 x1 = point[dat[p].L].dot(a, b), x2 =\
    \ point[dat[p].R].dot(a, b);\n      if (x1 <= x2) p = 2 * p + 0;\n      if (x1\
    \ > x2) p = 2 * p + 1;\n    }\n    return dat[p].L.dot(a, b);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: geo/lower_convexhull_segtree.hpp
  requiredBy: []
  timestamp: '2024-07-22 02:16:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geo/lower_convexhull_segtree.hpp
layout: document
redirect_from:
- /library/geo/lower_convexhull_segtree.hpp
- /library/geo/lower_convexhull_segtree.hpp.html
title: geo/lower_convexhull_segtree.hpp
---
