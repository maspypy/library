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
  bundledCode: "#line 1 \"ds/kdtree.hpp\"\ntemplate <class Lazy>\r\nstruct kDTree\
    \ {\r\n  using Monoid_X = typename Lazy::X_structure;\r\n  using Monoid_A = typename\
    \ Lazy::A_structure;\r\n  using X = typename Monoid_X::value_type;\r\n  using\
    \ A = typename Monoid_A::value_type;\r\n  kDTree *l = nullptr, *r = nullptr;\r\
    \n  ll xmin = LLONG_MAX, xmax = LLONG_MIN, ymin = LLONG_MAX, ymax = LLONG_MIN;\r\
    \n  X dat;\r\n  A lazy;\r\n  kDTree(vi xs, vi ys, vc<X> vs, bool divx = true)\
    \ {\r\n    dat = Monoid_X::unit;\r\n    lazy = Monoid_A::unit;\r\n    const int\
    \ n = len(xs);\r\n    FOR(i, n) {\r\n      auto x = xs[i], y = ys[i];\r\n    \
    \  chmin(xmin, x);\r\n      chmax(xmax, x);\r\n      chmin(ymin, y);\r\n     \
    \ chmax(ymax, y);\r\n      dat = Monoid_X::op(dat, vs[i]);\r\n    }\r\n    if\
    \ (n <= 1) return;\r\n    int m = n / 2;\r\n    vc<int> I(n);\r\n    iota(all(I),\
    \ 0);\r\n    if (divx) {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\
    \n                  [xs](int i, int j) { return xs[i] < xs[j]; });\r\n    } else\
    \ {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\n              \
    \    [ys](int i, int j) { return ys[i] < ys[j]; });\r\n    }\r\n    vi lxs, rxs,\
    \ lys, rys;\r\n    vc<X> lvs, rvs;\r\n    FOR(k, n) {\r\n      int i = I[k];\r\
    \n      if (k < m) {\r\n        lxs.eb(xs[i]);\r\n        lys.eb(ys[i]);\r\n \
    \       lvs.eb(vs[i]);\r\n      } else {\r\n        rxs.eb(xs[i]);\r\n       \
    \ rys.eb(ys[i]);\r\n        rvs.eb(vs[i]);\r\n      }\r\n    }\r\n    l = new\
    \ kDTree(lxs, lys, lvs, !divx);\r\n    r = new kDTree(rxs, rys, rvs, !divx);\r\
    \n  }\r\n\r\n  void prop() {\r\n    if (lazy == Monoid_A::unit) return;\r\n  \
    \  l->lazy = Monoid_A::op(l->lazy, lazy);\r\n    r->lazy = Monoid_A::op(r->lazy,\
    \ lazy);\r\n    dat = Lazy::act(dat, lazy);\r\n    lazy = Monoid_A::unit;\r\n\
    \  }\r\n\r\n  void apply_cl(ll x1, ll x2, ll y1, ll y2, A& a) {\r\n    if (x2\
    \ < xmin || xmax < x1 || y2 < ymin || ymax < y1) return;\r\n    if (x1 <= xmin\
    \ && xmax <= x2 && y1 <= ymin && ymax <= y2) {\r\n      lazy = Monoid_A::op(lazy,\
    \ a);\r\n      return;\r\n    }\r\n    prop();\r\n    l->apply_cl(x1, x2, y1,\
    \ y2, a);\r\n    r->apply_cl(x1, x2, y1, y2, a);\r\n    X vl = Lazy::act(l->dat,\
    \ l->lazy);\r\n    X vr = Lazy::act(r->dat, r->lazy);\r\n    dat = Monoid_X::op(vl,\
    \ vr);\r\n  }\r\n\r\n  X prod_cl(ll x1, ll x2, ll y1, ll y2) {\r\n    if (x2 <\
    \ xmin || xmax < x1 || y2 < ymin || ymax < y1) return Monoid_X::unit;\r\n    if\
    \ (x1 <= xmin && xmax <= x2 && y1 <= ymin && ymax <= y2) {\r\n      return Lazy::act(dat,\
    \ lazy);\r\n    }\r\n    prop();\r\n    return Monoid_X::op(l->prod_cl(x1, x2,\
    \ y1, y2), r->prod_cl(x1, x2, y1, y2));\r\n  }\r\n\r\n  void apply(ll xl, ll yl,\
    \ ll xr, ll yr, A& a) {\r\n    apply_cl(xl, xr - 1, yl, yr - 1, a);\r\n  }\r\n\
    \r\n  X prod(ll xl, ll yl, ll xr, ll yr) { return prod_cl(xl, xr - 1, yl, yr -\
    \ 1); }\r\n};\r\n"
  code: "template <class Lazy>\r\nstruct kDTree {\r\n  using Monoid_X = typename Lazy::X_structure;\r\
    \n  using Monoid_A = typename Lazy::A_structure;\r\n  using X = typename Monoid_X::value_type;\r\
    \n  using A = typename Monoid_A::value_type;\r\n  kDTree *l = nullptr, *r = nullptr;\r\
    \n  ll xmin = LLONG_MAX, xmax = LLONG_MIN, ymin = LLONG_MAX, ymax = LLONG_MIN;\r\
    \n  X dat;\r\n  A lazy;\r\n  kDTree(vi xs, vi ys, vc<X> vs, bool divx = true)\
    \ {\r\n    dat = Monoid_X::unit;\r\n    lazy = Monoid_A::unit;\r\n    const int\
    \ n = len(xs);\r\n    FOR(i, n) {\r\n      auto x = xs[i], y = ys[i];\r\n    \
    \  chmin(xmin, x);\r\n      chmax(xmax, x);\r\n      chmin(ymin, y);\r\n     \
    \ chmax(ymax, y);\r\n      dat = Monoid_X::op(dat, vs[i]);\r\n    }\r\n    if\
    \ (n <= 1) return;\r\n    int m = n / 2;\r\n    vc<int> I(n);\r\n    iota(all(I),\
    \ 0);\r\n    if (divx) {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\
    \n                  [xs](int i, int j) { return xs[i] < xs[j]; });\r\n    } else\
    \ {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\n              \
    \    [ys](int i, int j) { return ys[i] < ys[j]; });\r\n    }\r\n    vi lxs, rxs,\
    \ lys, rys;\r\n    vc<X> lvs, rvs;\r\n    FOR(k, n) {\r\n      int i = I[k];\r\
    \n      if (k < m) {\r\n        lxs.eb(xs[i]);\r\n        lys.eb(ys[i]);\r\n \
    \       lvs.eb(vs[i]);\r\n      } else {\r\n        rxs.eb(xs[i]);\r\n       \
    \ rys.eb(ys[i]);\r\n        rvs.eb(vs[i]);\r\n      }\r\n    }\r\n    l = new\
    \ kDTree(lxs, lys, lvs, !divx);\r\n    r = new kDTree(rxs, rys, rvs, !divx);\r\
    \n  }\r\n\r\n  void prop() {\r\n    if (lazy == Monoid_A::unit) return;\r\n  \
    \  l->lazy = Monoid_A::op(l->lazy, lazy);\r\n    r->lazy = Monoid_A::op(r->lazy,\
    \ lazy);\r\n    dat = Lazy::act(dat, lazy);\r\n    lazy = Monoid_A::unit;\r\n\
    \  }\r\n\r\n  void apply_cl(ll x1, ll x2, ll y1, ll y2, A& a) {\r\n    if (x2\
    \ < xmin || xmax < x1 || y2 < ymin || ymax < y1) return;\r\n    if (x1 <= xmin\
    \ && xmax <= x2 && y1 <= ymin && ymax <= y2) {\r\n      lazy = Monoid_A::op(lazy,\
    \ a);\r\n      return;\r\n    }\r\n    prop();\r\n    l->apply_cl(x1, x2, y1,\
    \ y2, a);\r\n    r->apply_cl(x1, x2, y1, y2, a);\r\n    X vl = Lazy::act(l->dat,\
    \ l->lazy);\r\n    X vr = Lazy::act(r->dat, r->lazy);\r\n    dat = Monoid_X::op(vl,\
    \ vr);\r\n  }\r\n\r\n  X prod_cl(ll x1, ll x2, ll y1, ll y2) {\r\n    if (x2 <\
    \ xmin || xmax < x1 || y2 < ymin || ymax < y1) return Monoid_X::unit;\r\n    if\
    \ (x1 <= xmin && xmax <= x2 && y1 <= ymin && ymax <= y2) {\r\n      return Lazy::act(dat,\
    \ lazy);\r\n    }\r\n    prop();\r\n    return Monoid_X::op(l->prod_cl(x1, x2,\
    \ y1, y2), r->prod_cl(x1, x2, y1, y2));\r\n  }\r\n\r\n  void apply(ll xl, ll yl,\
    \ ll xr, ll yr, A& a) {\r\n    apply_cl(xl, xr - 1, yl, yr - 1, a);\r\n  }\r\n\
    \r\n  X prod(ll xl, ll yl, ll xr, ll yr) { return prod_cl(xl, xr - 1, yl, yr -\
    \ 1); }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/kdtree.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/kdtree.hpp
layout: document
redirect_from:
- /library/ds/kdtree.hpp
- /library/ds/kdtree.hpp.html
title: ds/kdtree.hpp
---
