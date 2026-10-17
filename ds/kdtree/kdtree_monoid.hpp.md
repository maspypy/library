---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/kdtree_monoid.test.cpp
    title: test/1_mytest/kdtree_monoid.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1625.test.cpp
    title: test/3_yukicoder/1625.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/kdtree/kdtree_monoid.hpp
  bundledCode: "#line 1 \"ds/kdtree/kdtree_monoid.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/kdtree/kdtree_monoid.hpp\n\
    template <class Monoid, typename XY>\nstruct KDTree_Monoid {\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  static_assert(MX::commute);\n\n  // \u5C0F\
    \u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\u3064\u8A2D\
    \u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\u30AF\u30A8\
    \u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\n  vc<tuple<XY,\
    \ XY, XY, XY>> closed_range;\n  vc<X> dat;\n  int n;\n\n  KDTree_Monoid(vc<XY>\
    \ xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\n    assert(n > 0);\n    int log = 0;\n\
    \    while ((1 << log) < n) ++log;\n    dat.resize(1 << (log + 1));\n    closed_range.resize(1\
    \ << (log + 1));\n    build(1, xs, ys, vs);\n  }\n\n  void multiply(XY x, XY y,\
    \ const X& v) { multiply_rec(1, x, y, v); }\n\n  // [xl, xr) x [yl, yr)\n  X prod(XY\
    \ xl, XY xr, XY yl, XY yr) {\n    assert(xl <= xr && yl <= yr);\n    return prod_rec(1,\
    \ xl, xr, yl, yr);\n  }\n\n  X prod_all() { return dat[1]; }\n\nprivate:\n  void\
    \ build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {\n    int\
    \ n = len(xs);\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n    xmin\
    \ = ymin = infty<XY>;\n    xmax = ymax = -infty<XY>;\n\n    FOR(i, n) {\n    \
    \  auto x = xs[i], y = ys[i];\n      chmin(xmin, x), chmax(xmax, x), chmin(ymin,\
    \ y), chmax(ymax, y);\n    }\n    if (xmin == xmax && ymin == ymax) {\n      X\
    \ x = MX::id();\n      for (auto&& v: vs) x = MX::op(x, v);\n      dat[idx] =\
    \ x;\n      return;\n    }\n\n    int m = n / 2;\n    vc<int> I(n);\n    iota(all(I),\
    \ 0);\n    if (divx) {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n\
    \                  [xs](int i, int j) { return xs[i] < xs[j]; });\n    } else\
    \ {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n                  [ys](int\
    \ i, int j) { return ys[i] < ys[j]; });\n    }\n    xs = rearrange(xs, I), ys\
    \ = rearrange(ys, I), vs = rearrange(vs, I);\n    build(2 * idx + 0, {xs.begin(),\
    \ xs.begin() + m},\n          {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin()\
    \ + m}, !divx);\n    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin()\
    \ + m, ys.end()},\n          {vs.begin() + m, vs.end()}, !divx);\n    dat[idx]\
    \ = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\n  }\n\n  inline bool is_leaf(int\
    \ idx) {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n    return\
    \ xmin == xmax && ymin == ymax;\n  }\n\n  inline bool isin(XY x, XY y, int idx)\
    \ {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n    return (xmin\
    \ <= x && x <= xmax && ymin <= y && y <= ymax);\n  }\n\n  bool multiply_rec(int\
    \ idx, XY x, XY y, X v) {\n    if (!isin(x, y, idx)) return false;\n    if (is_leaf(idx))\
    \ {\n      dat[idx] = MX::op(dat[idx], v);\n      return true;\n    }\n    bool\
    \ done = 0;\n    if (multiply_rec(2 * idx + 0, x, y, v)) done = 1;\n    if (!done\
    \ && multiply_rec(2 * idx + 1, x, y, v)) done = 1;\n    if (done) { dat[idx] =\
    \ MX::op(dat[2 * idx + 0], dat[2 * idx + 1]); }\n    return done;\n  }\n\n  X\
    \ prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {\n    auto& [xmin, xmax, ymin,\
    \ ymax] = closed_range[idx];\n    if (x2 <= xmin || xmax < x1) return MX::id();\n\
    \    if (y2 <= ymin || ymax < y1) return MX::id();\n    if (x1 <= xmin && xmax\
    \ < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }\n    return MX::op(prod_rec(2\
    \ * idx + 0, x1, x2, y1, y2),\n                  prod_rec(2 * idx + 1, x1, x2,\
    \ y1, y2));\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/kdtree/kdtree_monoid.hpp\n\
    template <class Monoid, typename XY>\nstruct KDTree_Monoid {\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  static_assert(MX::commute);\n\n  // \u5C0F\
    \u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\u3064\u8A2D\
    \u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\u30AF\u30A8\
    \u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\n  vc<tuple<XY,\
    \ XY, XY, XY>> closed_range;\n  vc<X> dat;\n  int n;\n\n  KDTree_Monoid(vc<XY>\
    \ xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\n    assert(n > 0);\n    int log = 0;\n\
    \    while ((1 << log) < n) ++log;\n    dat.resize(1 << (log + 1));\n    closed_range.resize(1\
    \ << (log + 1));\n    build(1, xs, ys, vs);\n  }\n\n  void multiply(XY x, XY y,\
    \ const X& v) { multiply_rec(1, x, y, v); }\n\n  // [xl, xr) x [yl, yr)\n  X prod(XY\
    \ xl, XY xr, XY yl, XY yr) {\n    assert(xl <= xr && yl <= yr);\n    return prod_rec(1,\
    \ xl, xr, yl, yr);\n  }\n\n  X prod_all() { return dat[1]; }\n\nprivate:\n  void\
    \ build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, bool divx = true) {\n    int\
    \ n = len(xs);\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n    xmin\
    \ = ymin = infty<XY>;\n    xmax = ymax = -infty<XY>;\n\n    FOR(i, n) {\n    \
    \  auto x = xs[i], y = ys[i];\n      chmin(xmin, x), chmax(xmax, x), chmin(ymin,\
    \ y), chmax(ymax, y);\n    }\n    if (xmin == xmax && ymin == ymax) {\n      X\
    \ x = MX::id();\n      for (auto&& v: vs) x = MX::op(x, v);\n      dat[idx] =\
    \ x;\n      return;\n    }\n\n    int m = n / 2;\n    vc<int> I(n);\n    iota(all(I),\
    \ 0);\n    if (divx) {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n\
    \                  [xs](int i, int j) { return xs[i] < xs[j]; });\n    } else\
    \ {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n                  [ys](int\
    \ i, int j) { return ys[i] < ys[j]; });\n    }\n    xs = rearrange(xs, I), ys\
    \ = rearrange(ys, I), vs = rearrange(vs, I);\n    build(2 * idx + 0, {xs.begin(),\
    \ xs.begin() + m},\n          {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin()\
    \ + m}, !divx);\n    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin()\
    \ + m, ys.end()},\n          {vs.begin() + m, vs.end()}, !divx);\n    dat[idx]\
    \ = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\n  }\n\n  inline bool is_leaf(int\
    \ idx) {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n    return\
    \ xmin == xmax && ymin == ymax;\n  }\n\n  inline bool isin(XY x, XY y, int idx)\
    \ {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n    return (xmin\
    \ <= x && x <= xmax && ymin <= y && y <= ymax);\n  }\n\n  bool multiply_rec(int\
    \ idx, XY x, XY y, X v) {\n    if (!isin(x, y, idx)) return false;\n    if (is_leaf(idx))\
    \ {\n      dat[idx] = MX::op(dat[idx], v);\n      return true;\n    }\n    bool\
    \ done = 0;\n    if (multiply_rec(2 * idx + 0, x, y, v)) done = 1;\n    if (!done\
    \ && multiply_rec(2 * idx + 1, x, y, v)) done = 1;\n    if (done) { dat[idx] =\
    \ MX::op(dat[2 * idx + 0], dat[2 * idx + 1]); }\n    return done;\n  }\n\n  X\
    \ prod_rec(int idx, XY x1, XY x2, XY y1, XY y2) {\n    auto& [xmin, xmax, ymin,\
    \ ymax] = closed_range[idx];\n    if (x2 <= xmin || xmax < x1) return MX::id();\n\
    \    if (y2 <= ymin || ymax < y1) return MX::id();\n    if (x1 <= xmin && xmax\
    \ < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }\n    return MX::op(prod_rec(2\
    \ * idx + 0, x1, x2, y1, y2),\n                  prod_rec(2 * idx + 1, x1, x2,\
    \ y1, y2));\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/kdtree/kdtree_monoid.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/kdtree_monoid.test.cpp
  - test/3_yukicoder/1625.test.cpp
documentation_of: ds/kdtree/kdtree_monoid.hpp
layout: document
redirect_from:
- /library/ds/kdtree/kdtree_monoid.hpp
- /library/ds/kdtree/kdtree_monoid.hpp.html
title: ds/kdtree/kdtree_monoid.hpp
---
