---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C.test.cpp
    title: test/aoj/DSL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/kdtree_monoid.test.cpp
    title: test/mytest/kdtree_monoid.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1625.test.cpp
    title: test/yukicoder/1625.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/kdtree/kdtree_monoid.hpp\"\ntemplate <class Monoid, typename\
    \ XY>\r\nstruct KDTree_Monoid {\r\n  using MX = Monoid;\r\n  using X = typename\
    \ MX::value_type;\r\n  static_assert(MX::commute);\r\n\r\n  // \u5C0F\u6570\u3082\
    \u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\u3064\u8A2D\u8A08\u65B9\
    \u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\u30AF\u30A8\u30EA\u306F\
    \u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\r\n  vc<tuple<XY, XY, XY,\
    \ XY>> closed_range;\r\n  vc<X> dat;\r\n  int n;\r\n\r\n  KDTree_Monoid(vc<XY>\
    \ xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\r\n    assert(n > 0);\r\n    int log\
    \ = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1 << (log + 1));\r\
    \n    closed_range.resize(1 << (log + 1));\r\n    build(1, xs, ys, vs);\r\n  }\r\
    \n\r\n  void multiply(XY x, XY y, const X& v) { multiply_rec(1, x, y, v); }\r\n\
    \r\n  // [xl, xr) x [yl, yr)\r\n  X prod(XY xl, XY xr, XY yl, XY yr) {\r\n   \
    \ assert(xl <= xr && yl <= yr);\r\n    return prod_rec(1, xl, xr, yl, yr);\r\n\
    \  }\r\n\r\n  X prod_all() { return dat[1]; }\r\n\r\nprivate:\r\n  void build(int\
    \ idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {\r\n    int n = len(xs);\r\
    \n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    xmin = ymin =\
    \ infty<XY>;\r\n    xmax = ymax = -infty<XY>;\r\n\r\n    FOR(i, n) {\r\n     \
    \ auto x = xs[i], y = ys[i];\r\n      chmin(xmin, x), chmax(xmax, x), chmin(ymin,\
    \ y), chmax(ymax, y);\r\n    }\r\n    if (xmin == xmax && ymin == ymax) {\r\n\
    \      X x = MX::unit();\r\n      for (auto&& v: vs) x = MX::op(x, v);\r\n   \
    \   dat[idx] = x;\r\n      return;\r\n    }\r\n\r\n    int m = n / 2;\r\n    vc<int>\
    \ I(n);\r\n    iota(all(I), 0);\r\n    if (divx) {\r\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\r\n                  [xs](int i, int j) { return xs[i]\
    \ < xs[j]; });\r\n    } else {\r\n      nth_element(I.begin(), I.begin() + m,\
    \ I.end(),\r\n                  [ys](int i, int j) { return ys[i] < ys[j]; });\r\
    \n    }\r\n    xs = rearrange(xs, I), ys = rearrange(ys, I), vs = rearrange(vs,\
    \ I);\r\n    build(2 * idx + 0, {xs.begin(), xs.begin() + m},\r\n          {ys.begin(),\
    \ ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);\r\n    build(2 * idx\
    \ + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\r\n          {vs.begin()\
    \ + m, vs.end()}, !divx);\r\n    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx\
    \ + 1]);\r\n  }\r\n\r\n  inline bool is_leaf(int idx) {\r\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\r\n    return xmin == xmax && ymin == ymax;\r\
    \n  }\r\n\r\n  inline bool isin(XY x, XY y, int idx) {\r\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\r\n    return (xmin <= x && x <= xmax && ymin\
    \ <= y && y <= ymax);\r\n  }\r\n\r\n  bool multiply_rec(int idx, XY x, XY y, X\
    \ v) {\r\n    if (!isin(x, y, idx)) return false;\r\n    if (is_leaf(idx)) {\r\
    \n      dat[idx] = MX::op(dat[idx], v);\r\n      return true;\r\n    }\r\n   \
    \ bool done = 0;\r\n    if (multiply_rec(2 * idx + 0, x, y, v)) done = 1;\r\n\
    \    if (!done && multiply_rec(2 * idx + 1, x, y, v)) done = 1;\r\n    if (done)\
    \ { dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]); }\r\n    return done;\r\
    \n  }\r\n\r\n  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {\r\n    auto&\
    \ [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    if (x2 <= xmin || xmax\
    \ < x1) return MX::unit();\r\n    if (y2 <= ymin || ymax < y1) return MX::unit();\r\
    \n    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx];\
    \ }\r\n    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),\r\n          \
    \        prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\n};\r\n"
  code: "template <class Monoid, typename XY>\r\nstruct KDTree_Monoid {\r\n  using\
    \ MX = Monoid;\r\n  using X = typename MX::value_type;\r\n  static_assert(MX::commute);\r\
    \n\r\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\
    \u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\
    \u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\
    \r\n  vc<tuple<XY, XY, XY, XY>> closed_range;\r\n  vc<X> dat;\r\n  int n;\r\n\r\
    \n  KDTree_Monoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\r\n    assert(n\
    \ > 0);\r\n    int log = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1\
    \ << (log + 1));\r\n    closed_range.resize(1 << (log + 1));\r\n    build(1, xs,\
    \ ys, vs);\r\n  }\r\n\r\n  void multiply(XY x, XY y, const X& v) { multiply_rec(1,\
    \ x, y, v); }\r\n\r\n  // [xl, xr) x [yl, yr)\r\n  X prod(XY xl, XY xr, XY yl,\
    \ XY yr) {\r\n    assert(xl <= xr && yl <= yr);\r\n    return prod_rec(1, xl,\
    \ xr, yl, yr);\r\n  }\r\n\r\n  X prod_all() { return dat[1]; }\r\n\r\nprivate:\r\
    \n  void build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {\r\n\
    \    int n = len(xs);\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\
    \n    xmin = ymin = infty<XY>;\r\n    xmax = ymax = -infty<XY>;\r\n\r\n    FOR(i,\
    \ n) {\r\n      auto x = xs[i], y = ys[i];\r\n      chmin(xmin, x), chmax(xmax,\
    \ x), chmin(ymin, y), chmax(ymax, y);\r\n    }\r\n    if (xmin == xmax && ymin\
    \ == ymax) {\r\n      X x = MX::unit();\r\n      for (auto&& v: vs) x = MX::op(x,\
    \ v);\r\n      dat[idx] = x;\r\n      return;\r\n    }\r\n\r\n    int m = n /\
    \ 2;\r\n    vc<int> I(n);\r\n    iota(all(I), 0);\r\n    if (divx) {\r\n     \
    \ nth_element(I.begin(), I.begin() + m, I.end(),\r\n                  [xs](int\
    \ i, int j) { return xs[i] < xs[j]; });\r\n    } else {\r\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\r\n                  [ys](int i, int j) { return ys[i]\
    \ < ys[j]; });\r\n    }\r\n    xs = rearrange(xs, I), ys = rearrange(ys, I), vs\
    \ = rearrange(vs, I);\r\n    build(2 * idx + 0, {xs.begin(), xs.begin() + m},\r\
    \n          {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);\r\
    \n    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\r\
    \n          {vs.begin() + m, vs.end()}, !divx);\r\n    dat[idx] = MX::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  inline bool is_leaf(int idx)\
    \ {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    return xmin\
    \ == xmax && ymin == ymax;\r\n  }\r\n\r\n  inline bool isin(XY x, XY y, int idx)\
    \ {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    return (xmin\
    \ <= x && x <= xmax && ymin <= y && y <= ymax);\r\n  }\r\n\r\n  bool multiply_rec(int\
    \ idx, XY x, XY y, X v) {\r\n    if (!isin(x, y, idx)) return false;\r\n    if\
    \ (is_leaf(idx)) {\r\n      dat[idx] = MX::op(dat[idx], v);\r\n      return true;\r\
    \n    }\r\n    bool done = 0;\r\n    if (multiply_rec(2 * idx + 0, x, y, v)) done\
    \ = 1;\r\n    if (!done && multiply_rec(2 * idx + 1, x, y, v)) done = 1;\r\n \
    \   if (done) { dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]); }\r\n \
    \   return done;\r\n  }\r\n\r\n  X prod_rec(int idx, XY x1, XY x2, XY y1, XY y2)\
    \ {\r\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\r\n    if (x2 <=\
    \ xmin || xmax < x1) return MX::unit();\r\n    if (y2 <= ymin || ymax < y1) return\
    \ MX::unit();\r\n    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) {\
    \ return dat[idx]; }\r\n    return MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),\r\
    \n                  prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/kdtree/kdtree_monoid.hpp
  requiredBy: []
  timestamp: '2023-02-01 23:31:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1625.test.cpp
  - test/aoj/DSL_2_C.test.cpp
  - test/mytest/kdtree_monoid.test.cpp
documentation_of: ds/kdtree/kdtree_monoid.hpp
layout: document
redirect_from:
- /library/ds/kdtree/kdtree_monoid.hpp
- /library/ds/kdtree/kdtree_monoid.hpp.html
title: ds/kdtree/kdtree_monoid.hpp
---
