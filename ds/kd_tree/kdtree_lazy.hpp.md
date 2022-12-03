---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g
  bundledCode: "#line 1 \"ds/kd_tree/kdtree_lazy.hpp\"\n// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g\r\
    \ntemplate <class Lazy, typename XY>\r\nstruct KDTree_Lazy {\r\n  using Monoid_X\
    \ = typename Lazy::X_structure;\r\n  using Monoid_A = typename Lazy::A_structure;\r\
    \n  using X = typename Monoid_X::value_type;\r\n  using A = typename Monoid_A::value_type;\r\
    \n  vc<tuple<XY, XY, XY, XY>> range;\r\n  vc<X> dat;\r\n  vc<A> lazy;\r\n  int\
    \ n;\r\n\r\n  KDTree_Lazy(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs)) {\r\n \
    \   assert(Monoid_X::commute);\r\n    int log = 0;\r\n    while ((1 << log) <\
    \ n) ++log;\r\n    dat.resize(1 << (log + 1));\r\n    lazy.resize(1 << (log +\
    \ 1));\r\n    range.resize(1 << (log + 1));\r\n    build(1, xs, ys, vs);\r\n \
    \ }\r\n\r\n  void set(XY x, XY y, const X& v) { set_rec(1, x, y, v); }\r\n\r\n\
    \  void multiply(XY x, XY y, const X& v) { multiply_rec(1, x, y, v); }\r\n\r\n\
    \  X prod(XY xl, XY xr, XY yl, XY yr) {\r\n    assert(xl <= xr && yl <= yr);\r\
    \n    return prod_rec(1, xl, xr, yl, yr);\r\n  }\r\n\r\n  X prod_all() {\r\n \
    \   auto& [xmin, xmax, ymin, ymax] = range[1];\r\n    return prod(xmin, ymin,\
    \ xmax + 1, ymax + 1);\r\n  }\r\n\r\n  void apply(XY xl, XY xr, XY yl, XY yr,\
    \ A a) {\r\n    assert(xl <= xr && yl <= yr);\r\n    return apply_rec(1, xl, xr,\
    \ yl, yr, a);\r\n  }\r\n\r\n  vc<tuple<XY, XY, X>> get_all() {\r\n    vc<tuple<XY,\
    \ XY, X>> res;\r\n    auto dfs = [&](auto& dfs, int idx) -> void {\r\n      auto&\
    \ [xmin, xmax, ymin, ymax] = range[idx];\r\n      if (xmin == xmax && ymin ==\
    \ ymax) {\r\n        res.eb(xmin, ymin, dat[idx]);\r\n        return;\r\n    \
    \  }\r\n      push(idx);\r\n      dfs(dfs, 2 * idx + 0);\r\n      dfs(dfs, 2 *\
    \ idx + 1);\r\n    };\r\n    dfs(dfs, 1);\r\n    return res;\r\n  }\r\n\r\nprivate:\r\
    \n  void build(int idx, vc<XY>& xs, vc<XY>& ys, vc<X> vs, bool divx = true) {\r\
    \n    lazy[idx] = Monoid_A::unit();\r\n    int n = len(xs);\r\n    auto& [xmin,\
    \ xmax, ymin, ymax] = range[idx];\r\n    xmin = numeric_limits<XY>::max();\r\n\
    \    xmax = numeric_limits<XY>::lowest();\r\n    ymin = numeric_limits<XY>::max();\r\
    \n    ymax = numeric_limits<XY>::lowest();\r\n\r\n    FOR(i, n) {\r\n      auto\
    \ x = xs[i], y = ys[i];\r\n      chmin(xmin, x);\r\n      chmax(xmax, x);\r\n\
    \      chmin(ymin, y);\r\n      chmax(ymax, y);\r\n    }\r\n    if (xmin == xmax\
    \ && ymin == ymax) {\r\n      X x = Monoid_X::unit();\r\n      for (auto&& v:\
    \ vs) x = Monoid_X::op(x, v);\r\n      dat[idx] = x;\r\n      return;\r\n    }\r\
    \n\r\n    int m = n / 2;\r\n    vc<int> I(n);\r\n    iota(all(I), 0);\r\n    if\
    \ (divx) {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\n       \
    \           [xs](int i, int j) { return xs[i] < xs[j]; });\r\n    } else {\r\n\
    \      nth_element(I.begin(), I.begin() + m, I.end(),\r\n                  [ys](int\
    \ i, int j) { return ys[i] < ys[j]; });\r\n    }\r\n    vc<XY> lxs, rxs, lys,\
    \ rys;\r\n    vc<X> lvs, rvs;\r\n    FOR(k, m) {\r\n      int i = I[k];\r\n  \
    \    lxs.eb(xs[i]);\r\n      lys.eb(ys[i]);\r\n      lvs.eb(vs[i]);\r\n    }\r\
    \n    FOR(k, m, n) {\r\n      int i = I[k];\r\n      rxs.eb(xs[i]);\r\n      rys.eb(ys[i]);\r\
    \n      rvs.eb(vs[i]);\r\n    }\r\n    build(2 * idx + 0, lxs, lys, lvs, !divx);\r\
    \n    build(2 * idx + 1, rxs, rys, rvs, !divx);\r\n    dat[idx] = Monoid_X::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  void push(const int& idx) {\r\
    \n    A& a = lazy[idx];\r\n    if (a == Monoid_A::unit()) return;\r\n    auto&\
    \ [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (xmin != xmax || ymin != ymax)\
    \ {\r\n      dat[2 * idx + 0] = Lazy::act(dat[2 * idx + 0], a);\r\n      lazy[2\
    \ * idx + 0] = Monoid_A::op(lazy[2 * idx + 0], a);\r\n      dat[2 * idx + 1] =\
    \ Lazy::act(dat[2 * idx + 1], a);\r\n      lazy[2 * idx + 1] = Monoid_A::op(lazy[2\
    \ * idx + 1], a);\r\n    }\r\n    a = Monoid_A::unit();\r\n  }\r\n\r\n  bool isin(const\
    \ int& idx, const XY& x, const XY& y) {\r\n    auto& [xmin, xmax, ymin, ymax]\
    \ = range[idx];\r\n    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);\r\
    \n  }\r\n\r\n  void set_rec(const int& idx, const XY& x, const XY& y, const X&\
    \ v) {\r\n    if (!isin(idx, x, y)) { return; }\r\n    auto& [xmin, xmax, ymin,\
    \ ymax] = range[idx];\r\n    if (xmin == xmax && ymin == ymax) {\r\n      dat[idx]\
    \ = v;\r\n      return;\r\n    }\r\n    push(idx);\r\n    set_rec(2 * idx + 0,\
    \ x, y, v);\r\n    set_rec(2 * idx + 1, x, y, v);\r\n    dat[idx] = Monoid_X::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  void multiply_rec(const int&\
    \ idx, const XY& x, const XY& y, const X& v) {\r\n    if (!isin(idx, x, y)) return;\r\
    \n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (xmin == xmax &&\
    \ ymin == ymax) {\r\n      dat[idx] = Monoid_X::op(dat[idx], v);\r\n      lazy[idx]\
    \ = Monoid_A::unit();\r\n      return;\r\n    }\r\n    push(idx);\r\n    multiply_rec(2\
    \ * idx + 0, x, y, v);\r\n    multiply_rec(2 * idx + 1, x, y, v);\r\n    dat[idx]\
    \ = Monoid_X::op(dat[2 * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  X prod_rec(const\
    \ int& idx, const XY& x1, const XY& x2, const XY& y1,\r\n             const XY&\
    \ y2) {\r\n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (x2 <= xmin\
    \ || xmax < x1) return Monoid_X::unit();\r\n    if (y2 <= ymin || ymax < y1) return\
    \ Monoid_X::unit();\r\n    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax <\
    \ y2) { return dat[idx]; }\r\n    push(idx);\r\n    return Monoid_X::op(prod_rec(2\
    \ * idx + 0, x1, x2, y1, y2),\r\n                        prod_rec(2 * idx + 1,\
    \ x1, x2, y1, y2));\r\n  }\r\n\r\n  void apply_rec(const int& idx, const XY& x1,\
    \ const XY& x2, const XY& y1,\r\n                 const XY& y2, const A& a) {\r\
    \n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (x2 <= xmin || xmax\
    \ < x1) return;\r\n    if (y2 <= ymin || ymax < y1) return;\r\n    if (x1 <= xmin\
    \ && xmax < x2 && y1 <= ymin && ymax < y2) {\r\n      dat[idx] = Lazy::act(dat[idx],\
    \ a);\r\n      lazy[idx] = Monoid_A::op(lazy[idx], a);\r\n      return;\r\n  \
    \  }\r\n    push(idx);\r\n    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\r\n \
    \   apply_rec(2 * idx + 1, x1, x2, y1, y2, a);\r\n    dat[idx] = Monoid_X::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n};\r\n"
  code: "// https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_g\r\ntemplate <class Lazy,\
    \ typename XY>\r\nstruct KDTree_Lazy {\r\n  using Monoid_X = typename Lazy::X_structure;\r\
    \n  using Monoid_A = typename Lazy::A_structure;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  vc<tuple<XY, XY, XY, XY>> range;\r\
    \n  vc<X> dat;\r\n  vc<A> lazy;\r\n  int n;\r\n\r\n  KDTree_Lazy(vc<XY> xs, vc<XY>\
    \ ys, vc<X> vs) : n(len(xs)) {\r\n    assert(Monoid_X::commute);\r\n    int log\
    \ = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1 << (log + 1));\r\
    \n    lazy.resize(1 << (log + 1));\r\n    range.resize(1 << (log + 1));\r\n  \
    \  build(1, xs, ys, vs);\r\n  }\r\n\r\n  void set(XY x, XY y, const X& v) { set_rec(1,\
    \ x, y, v); }\r\n\r\n  void multiply(XY x, XY y, const X& v) { multiply_rec(1,\
    \ x, y, v); }\r\n\r\n  X prod(XY xl, XY xr, XY yl, XY yr) {\r\n    assert(xl <=\
    \ xr && yl <= yr);\r\n    return prod_rec(1, xl, xr, yl, yr);\r\n  }\r\n\r\n \
    \ X prod_all() {\r\n    auto& [xmin, xmax, ymin, ymax] = range[1];\r\n    return\
    \ prod(xmin, ymin, xmax + 1, ymax + 1);\r\n  }\r\n\r\n  void apply(XY xl, XY xr,\
    \ XY yl, XY yr, A a) {\r\n    assert(xl <= xr && yl <= yr);\r\n    return apply_rec(1,\
    \ xl, xr, yl, yr, a);\r\n  }\r\n\r\n  vc<tuple<XY, XY, X>> get_all() {\r\n   \
    \ vc<tuple<XY, XY, X>> res;\r\n    auto dfs = [&](auto& dfs, int idx) -> void\
    \ {\r\n      auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n      if (xmin ==\
    \ xmax && ymin == ymax) {\r\n        res.eb(xmin, ymin, dat[idx]);\r\n       \
    \ return;\r\n      }\r\n      push(idx);\r\n      dfs(dfs, 2 * idx + 0);\r\n \
    \     dfs(dfs, 2 * idx + 1);\r\n    };\r\n    dfs(dfs, 1);\r\n    return res;\r\
    \n  }\r\n\r\nprivate:\r\n  void build(int idx, vc<XY>& xs, vc<XY>& ys, vc<X> vs,\
    \ bool divx = true) {\r\n    lazy[idx] = Monoid_A::unit();\r\n    int n = len(xs);\r\
    \n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    xmin = numeric_limits<XY>::max();\r\
    \n    xmax = numeric_limits<XY>::lowest();\r\n    ymin = numeric_limits<XY>::max();\r\
    \n    ymax = numeric_limits<XY>::lowest();\r\n\r\n    FOR(i, n) {\r\n      auto\
    \ x = xs[i], y = ys[i];\r\n      chmin(xmin, x);\r\n      chmax(xmax, x);\r\n\
    \      chmin(ymin, y);\r\n      chmax(ymax, y);\r\n    }\r\n    if (xmin == xmax\
    \ && ymin == ymax) {\r\n      X x = Monoid_X::unit();\r\n      for (auto&& v:\
    \ vs) x = Monoid_X::op(x, v);\r\n      dat[idx] = x;\r\n      return;\r\n    }\r\
    \n\r\n    int m = n / 2;\r\n    vc<int> I(n);\r\n    iota(all(I), 0);\r\n    if\
    \ (divx) {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\n       \
    \           [xs](int i, int j) { return xs[i] < xs[j]; });\r\n    } else {\r\n\
    \      nth_element(I.begin(), I.begin() + m, I.end(),\r\n                  [ys](int\
    \ i, int j) { return ys[i] < ys[j]; });\r\n    }\r\n    vc<XY> lxs, rxs, lys,\
    \ rys;\r\n    vc<X> lvs, rvs;\r\n    FOR(k, m) {\r\n      int i = I[k];\r\n  \
    \    lxs.eb(xs[i]);\r\n      lys.eb(ys[i]);\r\n      lvs.eb(vs[i]);\r\n    }\r\
    \n    FOR(k, m, n) {\r\n      int i = I[k];\r\n      rxs.eb(xs[i]);\r\n      rys.eb(ys[i]);\r\
    \n      rvs.eb(vs[i]);\r\n    }\r\n    build(2 * idx + 0, lxs, lys, lvs, !divx);\r\
    \n    build(2 * idx + 1, rxs, rys, rvs, !divx);\r\n    dat[idx] = Monoid_X::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  void push(const int& idx) {\r\
    \n    A& a = lazy[idx];\r\n    if (a == Monoid_A::unit()) return;\r\n    auto&\
    \ [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (xmin != xmax || ymin != ymax)\
    \ {\r\n      dat[2 * idx + 0] = Lazy::act(dat[2 * idx + 0], a);\r\n      lazy[2\
    \ * idx + 0] = Monoid_A::op(lazy[2 * idx + 0], a);\r\n      dat[2 * idx + 1] =\
    \ Lazy::act(dat[2 * idx + 1], a);\r\n      lazy[2 * idx + 1] = Monoid_A::op(lazy[2\
    \ * idx + 1], a);\r\n    }\r\n    a = Monoid_A::unit();\r\n  }\r\n\r\n  bool isin(const\
    \ int& idx, const XY& x, const XY& y) {\r\n    auto& [xmin, xmax, ymin, ymax]\
    \ = range[idx];\r\n    return (xmin <= x && x <= xmax && ymin <= y && y <= ymax);\r\
    \n  }\r\n\r\n  void set_rec(const int& idx, const XY& x, const XY& y, const X&\
    \ v) {\r\n    if (!isin(idx, x, y)) { return; }\r\n    auto& [xmin, xmax, ymin,\
    \ ymax] = range[idx];\r\n    if (xmin == xmax && ymin == ymax) {\r\n      dat[idx]\
    \ = v;\r\n      return;\r\n    }\r\n    push(idx);\r\n    set_rec(2 * idx + 0,\
    \ x, y, v);\r\n    set_rec(2 * idx + 1, x, y, v);\r\n    dat[idx] = Monoid_X::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  void multiply_rec(const int&\
    \ idx, const XY& x, const XY& y, const X& v) {\r\n    if (!isin(idx, x, y)) return;\r\
    \n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (xmin == xmax &&\
    \ ymin == ymax) {\r\n      dat[idx] = Monoid_X::op(dat[idx], v);\r\n      lazy[idx]\
    \ = Monoid_A::unit();\r\n      return;\r\n    }\r\n    push(idx);\r\n    multiply_rec(2\
    \ * idx + 0, x, y, v);\r\n    multiply_rec(2 * idx + 1, x, y, v);\r\n    dat[idx]\
    \ = Monoid_X::op(dat[2 * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  X prod_rec(const\
    \ int& idx, const XY& x1, const XY& x2, const XY& y1,\r\n             const XY&\
    \ y2) {\r\n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (x2 <= xmin\
    \ || xmax < x1) return Monoid_X::unit();\r\n    if (y2 <= ymin || ymax < y1) return\
    \ Monoid_X::unit();\r\n    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax <\
    \ y2) { return dat[idx]; }\r\n    push(idx);\r\n    return Monoid_X::op(prod_rec(2\
    \ * idx + 0, x1, x2, y1, y2),\r\n                        prod_rec(2 * idx + 1,\
    \ x1, x2, y1, y2));\r\n  }\r\n\r\n  void apply_rec(const int& idx, const XY& x1,\
    \ const XY& x2, const XY& y1,\r\n                 const XY& y2, const A& a) {\r\
    \n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (x2 <= xmin || xmax\
    \ < x1) return;\r\n    if (y2 <= ymin || ymax < y1) return;\r\n    if (x1 <= xmin\
    \ && xmax < x2 && y1 <= ymin && ymax < y2) {\r\n      dat[idx] = Lazy::act(dat[idx],\
    \ a);\r\n      lazy[idx] = Monoid_A::op(lazy[idx], a);\r\n      return;\r\n  \
    \  }\r\n    push(idx);\r\n    apply_rec(2 * idx + 0, x1, x2, y1, y2, a);\r\n \
    \   apply_rec(2 * idx + 1, x1, x2, y1, y2, a);\r\n    dat[idx] = Monoid_X::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/kd_tree/kdtree_lazy.hpp
  requiredBy: []
  timestamp: '2022-12-03 09:41:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/kd_tree/kdtree_lazy.hpp
layout: document
redirect_from:
- /library/ds/kd_tree/kdtree_lazy.hpp
- /library/ds/kd_tree/kdtree_lazy.hpp.html
title: ds/kd_tree/kdtree_lazy.hpp
---
