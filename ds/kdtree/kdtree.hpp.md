---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc234ex.test.cpp
    title: test/atcoder/abc234ex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/kdtree/kdtree.hpp\"\ntemplate <class T, typename XY>\n\
    struct KDTree {\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\
    \u3067\u6301\u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\
    \u3057\u3001\u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\
    \u4F7F\u3046\n  vc<tuple<XY, XY, XY, XY>> closed_range;\n  // \u540C\u3058\u5EA7\
    \u6A19\u306E\u70B9\u3082\u96C6\u7D04\u3057\u306A\u3044\u3088\u3046\u306B\u3057\
    \u3066\u3001\u5EA7\u6A19\u3054\u3068\u306B unique \u306A\u30C7\u30FC\u30BF\u3092\
    \u4F7F\u3046\n  vc<T> dat;\n  vc<int> size;\n  int n;\n\n  KDTree(vc<XY> xs, vc<XY>\
    \ ys, vc<T> vs) : n(len(xs)) {\n    assert(n > 0);\n    int log = 0;\n    while\
    \ ((1 << log) < n) ++log;\n    dat.resize(1 << (log + 1));\n    size.resize(1\
    \ << (log + 1));\n    closed_range.resize(1 << (log + 1));\n    build(1, xs, ys,\
    \ vs);\n  }\n\n  // [xl, xr) x [yl, yr)\n  vc<T> collect_rect(XY xl, XY xr, XY\
    \ yl, XY yr, int max_size = -1) {\n    assert(xl <= xr && yl <= yr);\n    if (max_size\
    \ == -1) max_size = n;\n    vc<T> res;\n    collect_rect_rec(1, xl, xr, yl, yr,\
    \ res, max_size);\n    return res;\n  }\n\n  // r^2 \u3092\u6E21\u3059\u3053\u3068\
    \u306B\u6C17\u3092\u4ED8\u3051\u308B\n  vc<T> collect_circle(XY x, XY y, XY r_squared,\
    \ int max_size = -1) {\n    if (max_size == -1) max_size = n;\n    vc<T> res;\n\
    \    collect_circle_rec(1, x, y, r_squared, res, max_size);\n    return res;\n\
    \  }\n\nprivate:\n  void build(int idx, vc<XY> xs, vc<XY> ys, vc<T> vs, bool divx\
    \ = true) {\n    int n = len(xs);\n    size[idx] = n;\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\n    xmin = ymin = numeric_limits<XY>::max();\n\
    \    xmax = ymax = numeric_limits<XY>::lowest();\n\n    FOR(i, n) {\n      auto\
    \ x = xs[i], y = ys[i];\n      chmin(xmin, x), chmax(xmax, x), chmin(ymin, y),\
    \ chmax(ymax, y);\n    }\n    if (n == 1) {\n      dat[idx] = vs[0];\n      return;\n\
    \    }\n\n    int m = n / 2;\n    vc<int> I(n);\n    iota(all(I), 0);\n    if\
    \ (divx) {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n           \
    \       [xs](int i, int j) { return xs[i] < xs[j]; });\n    } else {\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\n                  [ys](int i, int j) { return ys[i]\
    \ < ys[j]; });\n    }\n    xs = rearrange(xs, I), ys = rearrange(ys, I), vs =\
    \ rearrange(vs, I);\n    build(2 * idx + 0, {xs.begin(), xs.begin() + m},\n  \
    \        {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin() + m}, !divx);\n\
    \    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\n\
    \          {vs.begin() + m, vs.end()}, !divx);\n  }\n\n  void collect_rect_rec(int\
    \ i, XY x1, XY x2, XY y1, XY y2, vc<T>& res, int ms) {\n    if (len(res) == ms)\
    \ return;\n    auto& [xmin, xmax, ymin, ymax] = closed_range[i];\n    if (x2 <=\
    \ xmin || xmax < x1) return;\n    if (y2 <= ymin || ymax < y1) return;\n    if\
    \ (size[i] == 1) {\n      res.eb(dat[i]);\n      return;\n    }\n    collect_rect_rec(2\
    \ * i + 0, x1, x2, y1, y2, res, ms);\n    collect_rect_rec(2 * i + 1, x1, x2,\
    \ y1, y2, res, ms);\n  }\n};\n"
  code: "template <class T, typename XY>\nstruct KDTree {\n  // \u5C0F\u6570\u3082\
    \u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\u3064\u8A2D\u8A08\u65B9\
    \u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\u30AF\u30A8\u30EA\u306F\
    \u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\n  vc<tuple<XY, XY, XY,\
    \ XY>> closed_range;\n  // \u540C\u3058\u5EA7\u6A19\u306E\u70B9\u3082\u96C6\u7D04\
    \u3057\u306A\u3044\u3088\u3046\u306B\u3057\u3066\u3001\u5EA7\u6A19\u3054\u3068\
    \u306B unique \u306A\u30C7\u30FC\u30BF\u3092\u4F7F\u3046\n  vc<T> dat;\n  vc<int>\
    \ size;\n  int n;\n\n  KDTree(vc<XY> xs, vc<XY> ys, vc<T> vs) : n(len(xs)) {\n\
    \    assert(n > 0);\n    int log = 0;\n    while ((1 << log) < n) ++log;\n   \
    \ dat.resize(1 << (log + 1));\n    size.resize(1 << (log + 1));\n    closed_range.resize(1\
    \ << (log + 1));\n    build(1, xs, ys, vs);\n  }\n\n  // [xl, xr) x [yl, yr)\n\
    \  vc<T> collect_rect(XY xl, XY xr, XY yl, XY yr, int max_size = -1) {\n    assert(xl\
    \ <= xr && yl <= yr);\n    if (max_size == -1) max_size = n;\n    vc<T> res;\n\
    \    collect_rect_rec(1, xl, xr, yl, yr, res, max_size);\n    return res;\n  }\n\
    \n  // r^2 \u3092\u6E21\u3059\u3053\u3068\u306B\u6C17\u3092\u4ED8\u3051\u308B\n\
    \  vc<T> collect_circle(XY x, XY y, XY r_squared, int max_size = -1) {\n    if\
    \ (max_size == -1) max_size = n;\n    vc<T> res;\n    collect_circle_rec(1, x,\
    \ y, r_squared, res, max_size);\n    return res;\n  }\n\nprivate:\n  void build(int\
    \ idx, vc<XY> xs, vc<XY> ys, vc<T> vs, bool divx = true) {\n    int n = len(xs);\n\
    \    size[idx] = n;\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n\
    \    xmin = ymin = numeric_limits<XY>::max();\n    xmax = ymax = numeric_limits<XY>::lowest();\n\
    \n    FOR(i, n) {\n      auto x = xs[i], y = ys[i];\n      chmin(xmin, x), chmax(xmax,\
    \ x), chmin(ymin, y), chmax(ymax, y);\n    }\n    if (n == 1) {\n      dat[idx]\
    \ = vs[0];\n      return;\n    }\n\n    int m = n / 2;\n    vc<int> I(n);\n  \
    \  iota(all(I), 0);\n    if (divx) {\n      nth_element(I.begin(), I.begin() +\
    \ m, I.end(),\n                  [xs](int i, int j) { return xs[i] < xs[j]; });\n\
    \    } else {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n        \
    \          [ys](int i, int j) { return ys[i] < ys[j]; });\n    }\n    xs = rearrange(xs,\
    \ I), ys = rearrange(ys, I), vs = rearrange(vs, I);\n    build(2 * idx + 0, {xs.begin(),\
    \ xs.begin() + m},\n          {ys.begin(), ys.begin() + m}, {vs.begin(), vs.begin()\
    \ + m}, !divx);\n    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin()\
    \ + m, ys.end()},\n          {vs.begin() + m, vs.end()}, !divx);\n  }\n\n  void\
    \ collect_rect_rec(int i, XY x1, XY x2, XY y1, XY y2, vc<T>& res, int ms) {\n\
    \    if (len(res) == ms) return;\n    auto& [xmin, xmax, ymin, ymax] = closed_range[i];\n\
    \    if (x2 <= xmin || xmax < x1) return;\n    if (y2 <= ymin || ymax < y1) return;\n\
    \    if (size[i] == 1) {\n      res.eb(dat[i]);\n      return;\n    }\n    collect_rect_rec(2\
    \ * i + 0, x1, x2, y1, y2, res, ms);\n    collect_rect_rec(2 * i + 1, x1, x2,\
    \ y1, y2, res, ms);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/kdtree/kdtree.hpp
  requiredBy: []
  timestamp: '2022-12-05 04:45:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/atcoder/abc234ex.test.cpp
documentation_of: ds/kdtree/kdtree.hpp
layout: document
redirect_from:
- /library/ds/kdtree/kdtree.hpp
- /library/ds/kdtree/kdtree.hpp.html
title: ds/kdtree/kdtree.hpp
---
