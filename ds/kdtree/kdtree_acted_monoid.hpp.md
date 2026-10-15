---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/kdtree_am.test.cpp
    title: test/1_mytest/kdtree_am.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
    title: test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2342.test.cpp
    title: test/3_yukicoder/2342.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/kdtree/kdtree_acted_monoid.hpp
  bundledCode: "#line 1 \"ds/kdtree/kdtree_acted_monoid.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/kdtree/kdtree_acted_monoid.hpp\n\
    template <class ActedMonoid, typename XY>\nstruct KDTree_ActedMonoid {\n  using\
    \ AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA = typename\
    \ AM::Monoid_A;\n  using X = typename AM::X;\n  using A = typename AM::A;\n  static_assert(MX::commute);\n\
    \n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\
    \u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\
    \u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\
    \n  vc<tuple<XY, XY, XY, XY>> closed_range;\n  vc<X> dat;\n  vc<A> lazy;\n  vc<int>\
    \ size;\n  vc<int> pos; // raw data -> index\n  int n, log;\n\n  KDTree_ActedMonoid(vc<XY>\
    \ xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\n    assert(n > 0);\n    log = 0;\n\
    \    while ((1 << log) < n) ++log;\n    dat.resize(1 << (log + 1));\n    lazy.assign(1\
    \ << log, MA::id());\n    closed_range.assign(1 << (log + 1), {infty<XY>, -infty<XY>,\
    \ infty<XY>, -infty<XY>});\n    size.resize(1 << (log + 1));\n    vc<int> ids(n);\n\
    \    pos.resize(n);\n    FOR(i, n) ids[i] = i;\n    build(1, xs, ys, vs, ids);\n\
    \  }\n\n  void set(int i, const X& v) {\n    i = pos[i];\n    for (int k = log;\
    \ k >= 1; k--) { push(i >> k); }\n    dat[i] = v;\n    while (i > 1) i /= 2, dat[i]\
    \ = MX::op(dat[2 * i], dat[2 * i + 1]);\n  }\n  void multiply(int i, const X&\
    \ v) {\n    i = pos[i];\n    for (int k = log; k >= 1; k--) { push(i >> k); }\n\
    \    dat[i] = MX::op(dat[i], v);\n    while (i > 1) i /= 2, dat[i] = MX::op(dat[2\
    \ * i], dat[2 * i + 1]);\n  }\n\n  // [xl, xr) x [yl, yr)\n  X prod(XY xl, XY\
    \ xr, XY yl, XY yr) {\n    assert(xl <= xr && yl <= yr);\n    return prod_rec(1,\
    \ xl, xr, yl, yr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  // [xl, xr)\
    \ x [yl, yr)\n  void apply(XY xl, XY xr, XY yl, XY yr, A a) {\n    assert(xl <=\
    \ xr && yl <= yr);\n    return apply_rec(1, xl, xr, yl, yr, a);\n  }\n\nprivate:\n\
    \  void build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, vc<int> ids, bool divx\
    \ = true) {\n    int n = len(xs);\n    size[idx] = n;\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\n    xmin = ymin = infty<XY>;\n    xmax = ymax\
    \ = -infty<XY>;\n\n    FOR(i, n) {\n      auto x = xs[i], y = ys[i];\n      chmin(xmin,\
    \ x), chmax(xmax, x), chmin(ymin, y), chmax(ymax, y);\n    }\n    if (n == 1)\
    \ {\n      dat[idx] = vs[0];\n      pos[ids[0]] = idx;\n      return;\n    }\n\
    \n    int m = n / 2;\n    vc<int> I(n);\n    iota(all(I), 0);\n    if (divx) {\n\
    \      nth_element(I.begin(), I.begin() + m, I.end(), [xs](int i, int j) { return\
    \ xs[i] < xs[j]; });\n    } else {\n      nth_element(I.begin(), I.begin() + m,\
    \ I.end(), [ys](int i, int j) { return ys[i] < ys[j]; });\n    }\n    xs = rearrange(xs,\
    \ I), ys = rearrange(ys, I), vs = rearrange(vs, I), ids = rearrange(ids, I);\n\
    \    build(2 * idx + 0, {xs.begin(), xs.begin() + m}, {ys.begin(), ys.begin()\
    \ + m}, {vs.begin(), vs.begin() + m}, {ids.begin(), ids.begin() + m}, !divx);\n\
    \    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\
    \ {vs.begin() + m, vs.end()}, {ids.begin() + m, ids.end()}, !divx);\n    dat[idx]\
    \ = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\n  }\n\n  inline bool isin(XY\
    \ x, XY y, int idx) {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n\
    \    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);\n  }\n\n  void\
    \ apply_at(int idx, A a) {\n    dat[idx] = AM::act(dat[idx], a, size[idx]);\n\
    \    if (idx < (1 << log)) lazy[idx] = MA::op(lazy[idx], a);\n  }\n\n  void push(int\
    \ idx) {\n    if (lazy[idx] == MA::id()) return;\n    apply_at(2 * idx + 0, lazy[idx]),\
    \ apply_at(2 * idx + 1, lazy[idx]);\n    lazy[idx] = MA::id();\n  }\n\n  X prod_rec(int\
    \ idx, XY x1, XY x2, XY y1, XY y2) {\n    if (idx >= len(closed_range)) return\
    \ MX::id();\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n    if (xmin\
    \ > xmax) return MX::id();\n    if (x2 <= xmin || xmax < x1) return MX::id();\n\
    \    if (y2 <= ymin || ymax < y1) return MX::id();\n    if (x1 <= xmin && xmax\
    \ < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }\n    push(idx);\n    return\
    \ MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2), prod_rec(2 * idx + 1, x1, x2,\
    \ y1, y2));\n  }\n\n  void apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a)\
    \ {\n    if (idx >= len(closed_range)) return;\n    auto& [xmin, xmax, ymin, ymax]\
    \ = closed_range[idx];\n    if (xmin > xmax) return;\n    if (x2 <= xmin || xmax\
    \ < x1) return;\n    if (y2 <= ymin || ymax < y1) return;\n    if (x1 <= xmin\
    \ && xmax < x2 && y1 <= ymin && ymax < y2) { return apply_at(idx, a); }\n    push(idx);\n\
    \    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\n    apply_rec(2 * idx + 1, x1,\
    \ x2, y1, y2, a);\n    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\n\
    \  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/kdtree/kdtree_acted_monoid.hpp\n\
    template <class ActedMonoid, typename XY>\nstruct KDTree_ActedMonoid {\n  using\
    \ AM = ActedMonoid;\n  using MX = typename AM::Monoid_X;\n  using MA = typename\
    \ AM::Monoid_A;\n  using X = typename AM::X;\n  using A = typename AM::A;\n  static_assert(MX::commute);\n\
    \n  // \u5C0F\u6570\u3082\u8003\u616E\u3059\u308B\u3068\u3001\u9589\u3067\u6301\
    \u3064\u8A2D\u8A08\u65B9\u91DD\u306B\u306A\u308B\u3002\u305F\u3060\u3057\u3001\
    \u30AF\u30A8\u30EA\u306F\u3044\u3064\u3082\u306E\u534A\u958B\u3092\u4F7F\u3046\
    \n  vc<tuple<XY, XY, XY, XY>> closed_range;\n  vc<X> dat;\n  vc<A> lazy;\n  vc<int>\
    \ size;\n  vc<int> pos; // raw data -> index\n  int n, log;\n\n  KDTree_ActedMonoid(vc<XY>\
    \ xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\n    assert(n > 0);\n    log = 0;\n\
    \    while ((1 << log) < n) ++log;\n    dat.resize(1 << (log + 1));\n    lazy.assign(1\
    \ << log, MA::id());\n    closed_range.assign(1 << (log + 1), {infty<XY>, -infty<XY>,\
    \ infty<XY>, -infty<XY>});\n    size.resize(1 << (log + 1));\n    vc<int> ids(n);\n\
    \    pos.resize(n);\n    FOR(i, n) ids[i] = i;\n    build(1, xs, ys, vs, ids);\n\
    \  }\n\n  void set(int i, const X& v) {\n    i = pos[i];\n    for (int k = log;\
    \ k >= 1; k--) { push(i >> k); }\n    dat[i] = v;\n    while (i > 1) i /= 2, dat[i]\
    \ = MX::op(dat[2 * i], dat[2 * i + 1]);\n  }\n  void multiply(int i, const X&\
    \ v) {\n    i = pos[i];\n    for (int k = log; k >= 1; k--) { push(i >> k); }\n\
    \    dat[i] = MX::op(dat[i], v);\n    while (i > 1) i /= 2, dat[i] = MX::op(dat[2\
    \ * i], dat[2 * i + 1]);\n  }\n\n  // [xl, xr) x [yl, yr)\n  X prod(XY xl, XY\
    \ xr, XY yl, XY yr) {\n    assert(xl <= xr && yl <= yr);\n    return prod_rec(1,\
    \ xl, xr, yl, yr);\n  }\n\n  X prod_all() { return dat[1]; }\n\n  // [xl, xr)\
    \ x [yl, yr)\n  void apply(XY xl, XY xr, XY yl, XY yr, A a) {\n    assert(xl <=\
    \ xr && yl <= yr);\n    return apply_rec(1, xl, xr, yl, yr, a);\n  }\n\nprivate:\n\
    \  void build(int idx, vc<XY> xs, vc<XY> ys, vc<X> vs, vc<int> ids, bool divx\
    \ = true) {\n    int n = len(xs);\n    size[idx] = n;\n    auto& [xmin, xmax,\
    \ ymin, ymax] = closed_range[idx];\n    xmin = ymin = infty<XY>;\n    xmax = ymax\
    \ = -infty<XY>;\n\n    FOR(i, n) {\n      auto x = xs[i], y = ys[i];\n      chmin(xmin,\
    \ x), chmax(xmax, x), chmin(ymin, y), chmax(ymax, y);\n    }\n    if (n == 1)\
    \ {\n      dat[idx] = vs[0];\n      pos[ids[0]] = idx;\n      return;\n    }\n\
    \n    int m = n / 2;\n    vc<int> I(n);\n    iota(all(I), 0);\n    if (divx) {\n\
    \      nth_element(I.begin(), I.begin() + m, I.end(), [xs](int i, int j) { return\
    \ xs[i] < xs[j]; });\n    } else {\n      nth_element(I.begin(), I.begin() + m,\
    \ I.end(), [ys](int i, int j) { return ys[i] < ys[j]; });\n    }\n    xs = rearrange(xs,\
    \ I), ys = rearrange(ys, I), vs = rearrange(vs, I), ids = rearrange(ids, I);\n\
    \    build(2 * idx + 0, {xs.begin(), xs.begin() + m}, {ys.begin(), ys.begin()\
    \ + m}, {vs.begin(), vs.begin() + m}, {ids.begin(), ids.begin() + m}, !divx);\n\
    \    build(2 * idx + 1, {xs.begin() + m, xs.end()}, {ys.begin() + m, ys.end()},\
    \ {vs.begin() + m, vs.end()}, {ids.begin() + m, ids.end()}, !divx);\n    dat[idx]\
    \ = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\n  }\n\n  inline bool isin(XY\
    \ x, XY y, int idx) {\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n\
    \    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);\n  }\n\n  void\
    \ apply_at(int idx, A a) {\n    dat[idx] = AM::act(dat[idx], a, size[idx]);\n\
    \    if (idx < (1 << log)) lazy[idx] = MA::op(lazy[idx], a);\n  }\n\n  void push(int\
    \ idx) {\n    if (lazy[idx] == MA::id()) return;\n    apply_at(2 * idx + 0, lazy[idx]),\
    \ apply_at(2 * idx + 1, lazy[idx]);\n    lazy[idx] = MA::id();\n  }\n\n  X prod_rec(int\
    \ idx, XY x1, XY x2, XY y1, XY y2) {\n    if (idx >= len(closed_range)) return\
    \ MX::id();\n    auto& [xmin, xmax, ymin, ymax] = closed_range[idx];\n    if (xmin\
    \ > xmax) return MX::id();\n    if (x2 <= xmin || xmax < x1) return MX::id();\n\
    \    if (y2 <= ymin || ymax < y1) return MX::id();\n    if (x1 <= xmin && xmax\
    \ < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }\n    push(idx);\n    return\
    \ MX::op(prod_rec(2 * idx + 0, x1, x2, y1, y2), prod_rec(2 * idx + 1, x1, x2,\
    \ y1, y2));\n  }\n\n  void apply_rec(int idx, XY x1, XY x2, XY y1, XY y2, A a)\
    \ {\n    if (idx >= len(closed_range)) return;\n    auto& [xmin, xmax, ymin, ymax]\
    \ = closed_range[idx];\n    if (xmin > xmax) return;\n    if (x2 <= xmin || xmax\
    \ < x1) return;\n    if (y2 <= ymin || ymax < y1) return;\n    if (x1 <= xmin\
    \ && xmax < x2 && y1 <= ymin && ymax < y2) { return apply_at(idx, a); }\n    push(idx);\n\
    \    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\n    apply_rec(2 * idx + 1, x1,\
    \ x2, y1, y2, a);\n    dat[idx] = MX::op(dat[2 * idx + 0], dat[2 * idx + 1]);\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/kdtree/kdtree_acted_monoid.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/1_mytest/kdtree_am.test.cpp
  - test/3_yukicoder/2342.test.cpp
  - test/2_library_checker/data_structure/dynamic_point_rectangle_affine_rectangle_sum.test.cpp
documentation_of: ds/kdtree/kdtree_acted_monoid.hpp
layout: document
redirect_from:
- /library/ds/kdtree/kdtree_acted_monoid.hpp
- /library/ds/kdtree/kdtree_acted_monoid.hpp.html
title: ds/kdtree/kdtree_acted_monoid.hpp
---
