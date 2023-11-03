---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2342_2.test.cpp
    title: test/yukicoder/2342_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/kdtree/dual_kdtree_monoid.hpp\"\n// \u77E9\u5F62\u4F5C\
    \u7528\u3068\u70B9\u53D6\u5F97\ntemplate <class Monoid, typename XY>\nstruct Dual_KDTree_Monoid\
    \ {\n  using MA = Monoid;\n  using A = typename Monoid::value_type;\n\n  // \u5C0F\
    \u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\u3064\u8A2D\
    \u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\u30AF\u30A8\
    \u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\n  vc<tuple<XY,\
    \ XY, XY, XY>> closed_range;\n  vc<A> lazy;\n  vc<int> size;\n  vc<int> where;\n\
    \  int n, log;\n\n  Dual_KDTree_Monoid(vc<XY> xs, vc<XY> ys) : n(len(xs)) {\n\
    \    assert(n > 0);\n    log = 0;\n    while ((1 << log) < n) ++log;\n    lazy.resize(1\
    \ << (log + 1), MA::unit());\n    closed_range.resize(1 << (log + 1));\n    size.resize(1\
    \ << (log + 1));\n    where.resize(n);\n    vc<int> I(n);\n    iota(all(I), 0);\n\
    \    build(1, xs, ys, I);\n  }\n\n  // [xl, xr) x [yl, yr)\n  void apply(XY xl,\
    \ XY xr, XY yl, XY yr, A a) {\n    assert(xl <= xr && yl <= yr);\n    return apply_rec(1,\
    \ xl, xr, yl, yr, a);\n  }\n\n  // \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\
    \u6E21\u3057\u305F\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n  A get(int i) {\n   \
    \ i = where[i];\n    FOR_R(k, 1, log + 1) { push(i >> k); }\n    return lazy[i];\n\
    \  }\n\nprivate:\n  void build(int idx, vc<XY> xs, vc<XY> ys, vc<int> raw_idx,\
    \ bool divx = true) {\n    int n = len(xs);\n    size[idx] = n;\n    auto& [xmin,\
    \ xmax, ymin, ymax] = closed_range[idx];\n    xmin = ymin = infty<XY>;\n    xmax\
    \ = ymax = -infty<XY>;\n\n    FOR(i, n) {\n      auto x = xs[i], y = ys[i];\n\
    \      chmin(xmin, x), chmax(xmax, x), chmin(ymin, y), chmax(ymax, y);\n    }\n\
    \    if (xmin == xmax && ymin == ymax) {\n      assert(len(raw_idx) == 1);\n \
    \     where[raw_idx[0]] = idx;\n      return;\n    }\n\n    int m = n / 2;\n \
    \   vc<int> I(n);\n    iota(all(I), 0);\n    if (divx) {\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\n                  [xs](int i, int j) { return xs[i]\
    \ < xs[j]; });\n    } else {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n\
    \                  [ys](int i, int j) { return ys[i] < ys[j]; });\n    }\n   \
    \ xs = rearrange(xs, I), ys = rearrange(ys, I),\n    raw_idx = rearrange(raw_idx,\
    \ I);\n    build(2 * idx + 0, {xs.begin(), xs.begin() + m},\n          {ys.begin(),\
    \ ys.begin() + m}, {raw_idx.begin(), raw_idx.begin() + m},\n          !divx);\n\
    \    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\n\
    \          {raw_idx.begin() + m, raw_idx.end()}, !divx);\n  }\n\n  inline bool\
    \ is_leaf(int idx) {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n\
    \    return xmin == xmax && ymin == ymax;\n  }\n\n  inline bool isin(XY x, XY\
    \ y, int idx) {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n   \
    \ return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);\n  }\n\n  void apply_at(int\
    \ idx, A a) { lazy[idx] = MA::op(lazy[idx], a); }\n\n  void push(int idx) {\n\
    \    if (lazy[idx] == MA::unit()) return;\n    apply_at(2 * idx + 0, lazy[idx]),\
    \ apply_at(2 * idx + 1, lazy[idx]);\n    lazy[idx] = MA::unit();\n  }\n\n  void\
    \ apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a) {\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\n    if (x2 <= xmin || xmax < x1) return;\n\
    \    if (y2 <= ymin || ymax < y1) return;\n    if (x1 <= xmin && xmax < x2 &&\
    \ y1 <= ymin && ymax < y2) {\n      return apply_at(idx, a);\n    }\n    push(idx);\n\
    \    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\n    apply_rec(2 * idx + 1, x1,\
    \ x2, y1, y2, a);\n  }\n};\n"
  code: "// \u77E9\u5F62\u4F5C\u7528\u3068\u70B9\u53D6\u5F97\ntemplate <class Monoid,\
    \ typename XY>\nstruct Dual_KDTree_Monoid {\n  using MA = Monoid;\n  using A =\
    \ typename Monoid::value_type;\n\n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\
    \u3068\u3001\u9589\u3067\u6301\u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\
    \u3002\u305F\u3060\u3057\u3001\u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\
    \u534A\u958B\u3092\u4F7F\u3046\n  vc<tuple<XY, XY, XY, XY>> closed_range;\n  vc<A>\
    \ lazy;\n  vc<int> size;\n  vc<int> where;\n  int n, log;\n\n  Dual_KDTree_Monoid(vc<XY>\
    \ xs, vc<XY> ys) : n(len(xs)) {\n    assert(n > 0);\n    log = 0;\n    while ((1\
    \ << log) < n) ++log;\n    lazy.resize(1 << (log + 1), MA::unit());\n    closed_range.resize(1\
    \ << (log + 1));\n    size.resize(1 << (log + 1));\n    where.resize(n);\n   \
    \ vc<int> I(n);\n    iota(all(I), 0);\n    build(1, xs, ys, I);\n  }\n\n  // [xl,\
    \ xr) x [yl, yr)\n  void apply(XY xl, XY xr, XY yl, XY yr, A a) {\n    assert(xl\
    \ <= xr && yl <= yr);\n    return apply_rec(1, xl, xr, yl, yr, a);\n  }\n\n  //\
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u6E21\u3057\u305F\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\n  A get(int i) {\n    i = where[i];\n    FOR_R(k, 1,\
    \ log + 1) { push(i >> k); }\n    return lazy[i];\n  }\n\nprivate:\n  void build(int\
    \ idx, vc<XY> xs, vc<XY> ys, vc<int> raw_idx, bool divx = true) {\n    int n =\
    \ len(xs);\n    size[idx] = n;\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n\
    \    xmin = ymin = infty<XY>;\n    xmax = ymax = -infty<XY>;\n\n    FOR(i, n)\
    \ {\n      auto x = xs[i], y = ys[i];\n      chmin(xmin, x), chmax(xmax, x), chmin(ymin,\
    \ y), chmax(ymax, y);\n    }\n    if (xmin == xmax && ymin == ymax) {\n      assert(len(raw_idx)\
    \ == 1);\n      where[raw_idx[0]] = idx;\n      return;\n    }\n\n    int m =\
    \ n / 2;\n    vc<int> I(n);\n    iota(all(I), 0);\n    if (divx) {\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\n                  [xs](int i, int j) { return xs[i]\
    \ < xs[j]; });\n    } else {\n      nth_element(I.begin(), I.begin() + m, I.end(),\n\
    \                  [ys](int i, int j) { return ys[i] < ys[j]; });\n    }\n   \
    \ xs = rearrange(xs, I), ys = rearrange(ys, I),\n    raw_idx = rearrange(raw_idx,\
    \ I);\n    build(2 * idx + 0, {xs.begin(), xs.begin() + m},\n          {ys.begin(),\
    \ ys.begin() + m}, {raw_idx.begin(), raw_idx.begin() + m},\n          !divx);\n\
    \    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\n\
    \          {raw_idx.begin() + m, raw_idx.end()}, !divx);\n  }\n\n  inline bool\
    \ is_leaf(int idx) {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n\
    \    return xmin == xmax && ymin == ymax;\n  }\n\n  inline bool isin(XY x, XY\
    \ y, int idx) {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n   \
    \ return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);\n  }\n\n  void apply_at(int\
    \ idx, A a) { lazy[idx] = MA::op(lazy[idx], a); }\n\n  void push(int idx) {\n\
    \    if (lazy[idx] == MA::unit()) return;\n    apply_at(2 * idx + 0, lazy[idx]),\
    \ apply_at(2 * idx + 1, lazy[idx]);\n    lazy[idx] = MA::unit();\n  }\n\n  void\
    \ apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a) {\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\n    if (x2 <= xmin || xmax < x1) return;\n\
    \    if (y2 <= ymin || ymax < y1) return;\n    if (x1 <= xmin && xmax < x2 &&\
    \ y1 <= ymin && ymax < y2) {\n      return apply_at(idx, a);\n    }\n    push(idx);\n\
    \    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\n    apply_rec(2 * idx + 1, x1,\
    \ x2, y1, y2, a);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/kdtree/dual_kdtree_monoid.hpp
  requiredBy: []
  timestamp: '2023-06-03 10:19:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2342_2.test.cpp
documentation_of: ds/kdtree/dual_kdtree_monoid.hpp
layout: document
redirect_from:
- /library/ds/kdtree/dual_kdtree_monoid.hpp
- /library/ds/kdtree/dual_kdtree_monoid.hpp.html
title: ds/kdtree/dual_kdtree_monoid.hpp
---
