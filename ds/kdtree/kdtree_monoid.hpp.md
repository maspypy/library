---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_C.test.cpp
    title: test/aoj/DSL_2_C.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1625.test.cpp
    title: test/yukicoder/1625.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/kdtree/kdtree_monoid.hpp\"\n// \u540C\u3058\u5EA7\u6A19\
    \u306E\u8907\u6570\u306E\u70B9\u304C\u3069\u306E\u304F\u3089\u3044\u96C6\u7D04\
    \u3055\u308C\u308B\u304B\u306F\u4FDD\u8A3C\u304C\u306A\u3044\u3002\r\n// \u5B50\
    \u30CE\u30FC\u30C9\u304C 2x, 2x+1 \u306B\u306A\u308B\u3088\u3046\u306B\u3057\u3066\
    \u3001\u914D\u5217\u3067\u4F5C\u3063\u3066\u307F\u308B\u3002\r\ntemplate <class\
    \ Monoid, typename XY = long long>\r\nstruct KDTree_Monoid {\r\n  using X = typename\
    \ Monoid::value_type;\r\n  vc<tuple<XY, XY, XY, XY>> range;\r\n  vc<X> dat;\r\n\
    \  int n;\r\n\r\n  KDTree_Monoid(vc<XY> xs, vc<XY> ys, vc<X> vs) : n(len(xs))\
    \ {\r\n    assert(Monoid::commute);\r\n    int log = 0;\r\n    while ((1 << log)\
    \ < n) ++log;\r\n    dat.resize(1 << (log + 1));\r\n    range.resize(1 << (log\
    \ + 1));\r\n    build(1, xs, ys, vs);\r\n  }\r\n\r\n  void set(XY x, XY y, const\
    \ X& v) { set_rec(1, x, y, v); }\r\n\r\n  void multiply(XY x, XY y, const X& v)\
    \ { multiply_rec(1, x, y, v); }\r\n\r\n  X prod(XY xl, XY xr, XY yl, XY yr) {\r\
    \n    assert(xl <= xr && yl <= yr);\r\n    return prod_rec(1, xl, xr, yl, yr);\r\
    \n  }\r\n\r\nprivate:\r\n  void build(int idx, vc<XY>& xs, vc<XY>& ys, vc<X>&\
    \ vs, bool divx = true) {\r\n    int n = len(xs);\r\n    auto& [xmin, xmax, ymin,\
    \ ymax] = range[idx];\r\n    xmin = numeric_limits<XY>::max();\r\n    xmax = numeric_limits<XY>::lowest();\r\
    \n    ymin = numeric_limits<XY>::max();\r\n    ymax = numeric_limits<XY>::lowest();\r\
    \n\r\n    FOR(i, n) {\r\n      auto x = xs[i], y = ys[i];\r\n      chmin(xmin,\
    \ x);\r\n      chmax(xmax, x);\r\n      chmin(ymin, y);\r\n      chmax(ymax, y);\r\
    \n    }\r\n    if (xmin == xmax && ymin == ymax) {\r\n      X x = Monoid::unit();\r\
    \n      for (auto&& v: vs) x = Monoid::op(x, v);\r\n      dat[idx] = x;\r\n  \
    \    return;\r\n    }\r\n\r\n    int m = n / 2;\r\n    vc<int> I(n);\r\n    iota(all(I),\
    \ 0);\r\n    if (divx) {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\
    \n                  [xs](int i, int j) { return xs[i] < xs[j]; });\r\n    } else\
    \ {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\n              \
    \    [ys](int i, int j) { return ys[i] < ys[j]; });\r\n    }\r\n    vc<XY> lxs,\
    \ rxs, lys, rys;\r\n    vc<X> lvs, rvs;\r\n    FOR(k, m) {\r\n      int i = I[k];\r\
    \n      lxs.eb(xs[i]);\r\n      lys.eb(ys[i]);\r\n      lvs.eb(vs[i]);\r\n   \
    \ }\r\n    FOR(k, m, n) {\r\n      int i = I[k];\r\n      rxs.eb(xs[i]);\r\n \
    \     rys.eb(ys[i]);\r\n      rvs.eb(vs[i]);\r\n    }\r\n    build(2 * idx + 0,\
    \ lxs, lys, lvs, !divx);\r\n    build(2 * idx + 1, rxs, rys, rvs, !divx);\r\n\
    \    dat[idx] = Monoid::op(dat[2 * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n\
    \  bool isin(const int& idx, const XY& x, const XY& y) {\r\n    auto& [xmin, xmax,\
    \ ymin, ymax] = range[idx];\r\n    return (xmin <= x && x <= xmax && ymin <= y\
    \ && y <= ymax);\r\n  }\r\n\r\n  void set_rec(const int& idx, const XY& x, const\
    \ XY& y, const X& v) {\r\n    if (!isin(idx, x, y)) return;\r\n    auto& [xmin,\
    \ xmax, ymin, ymax] = range[idx];\r\n    if (xmin == xmax && ymin == ymax) {\r\
    \n      dat[idx] = v;\r\n      return;\r\n    }\r\n    set_rec(2 * idx + 0, x,\
    \ y, v);\r\n    set_rec(2 * idx + 1, x, y, v);\r\n    dat[idx] = Monoid::op(dat[2\
    \ * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  void multiply_rec(const int&\
    \ idx, const XY& x, const XY& y, const X& v) {\r\n    if (!isin(idx, x, y)) return;\r\
    \n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (xmin == xmax &&\
    \ ymin == ymax) {\r\n      dat[idx] = Monoid::op(dat[idx], v);\r\n      return;\r\
    \n    }\r\n    multiply_rec(2 * idx + 0, x, y, v);\r\n    multiply_rec(2 * idx\
    \ + 1, x, y, v);\r\n    dat[idx] = Monoid::op(dat[2 * idx + 0], dat[2 * idx +\
    \ 1]);\r\n  }\r\n\r\n  X prod_rec(const int& idx, const XY& x1, const XY& x2,\
    \ const XY& y1,\r\n             const XY& y2) {\r\n    auto& [xmin, xmax, ymin,\
    \ ymax] = range[idx];\r\n    if (x2 <= xmin || xmax < x1) return Monoid::unit();\r\
    \n    if (y2 <= ymin || ymax < y1) return Monoid::unit();\r\n    if (x1 <= xmin\
    \ && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx]; }\r\n    return\
    \ Monoid::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),\r\n                      prod_rec(2\
    \ * idx + 1, x1, x2, y1, y2));\r\n  }\r\n};\n"
  code: "// \u540C\u3058\u5EA7\u6A19\u306E\u8907\u6570\u306E\u70B9\u304C\u3069\u306E\
    \u304F\u3089\u3044\u96C6\u7D04\u3055\u308C\u308B\u304B\u306F\u4FDD\u8A3C\u304C\
    \u306A\u3044\u3002\r\n// \u5B50\u30CE\u30FC\u30C9\u304C 2x, 2x+1 \u306B\u306A\u308B\
    \u3088\u3046\u306B\u3057\u3066\u3001\u914D\u5217\u3067\u4F5C\u3063\u3066\u307F\
    \u308B\u3002\r\ntemplate <class Monoid, typename XY = long long>\r\nstruct KDTree_Monoid\
    \ {\r\n  using X = typename Monoid::value_type;\r\n  vc<tuple<XY, XY, XY, XY>>\
    \ range;\r\n  vc<X> dat;\r\n  int n;\r\n\r\n  KDTree_Monoid(vc<XY> xs, vc<XY>\
    \ ys, vc<X> vs) : n(len(xs)) {\r\n    assert(Monoid::commute);\r\n    int log\
    \ = 0;\r\n    while ((1 << log) < n) ++log;\r\n    dat.resize(1 << (log + 1));\r\
    \n    range.resize(1 << (log + 1));\r\n    build(1, xs, ys, vs);\r\n  }\r\n\r\n\
    \  void set(XY x, XY y, const X& v) { set_rec(1, x, y, v); }\r\n\r\n  void multiply(XY\
    \ x, XY y, const X& v) { multiply_rec(1, x, y, v); }\r\n\r\n  X prod(XY xl, XY\
    \ xr, XY yl, XY yr) {\r\n    assert(xl <= xr && yl <= yr);\r\n    return prod_rec(1,\
    \ xl, xr, yl, yr);\r\n  }\r\n\r\nprivate:\r\n  void build(int idx, vc<XY>& xs,\
    \ vc<XY>& ys, vc<X>& vs, bool divx = true) {\r\n    int n = len(xs);\r\n    auto&\
    \ [xmin, xmax, ymin, ymax] = range[idx];\r\n    xmin = numeric_limits<XY>::max();\r\
    \n    xmax = numeric_limits<XY>::lowest();\r\n    ymin = numeric_limits<XY>::max();\r\
    \n    ymax = numeric_limits<XY>::lowest();\r\n\r\n    FOR(i, n) {\r\n      auto\
    \ x = xs[i], y = ys[i];\r\n      chmin(xmin, x);\r\n      chmax(xmax, x);\r\n\
    \      chmin(ymin, y);\r\n      chmax(ymax, y);\r\n    }\r\n    if (xmin == xmax\
    \ && ymin == ymax) {\r\n      X x = Monoid::unit();\r\n      for (auto&& v: vs)\
    \ x = Monoid::op(x, v);\r\n      dat[idx] = x;\r\n      return;\r\n    }\r\n\r\
    \n    int m = n / 2;\r\n    vc<int> I(n);\r\n    iota(all(I), 0);\r\n    if (divx)\
    \ {\r\n      nth_element(I.begin(), I.begin() + m, I.end(),\r\n              \
    \    [xs](int i, int j) { return xs[i] < xs[j]; });\r\n    } else {\r\n      nth_element(I.begin(),\
    \ I.begin() + m, I.end(),\r\n                  [ys](int i, int j) { return ys[i]\
    \ < ys[j]; });\r\n    }\r\n    vc<XY> lxs, rxs, lys, rys;\r\n    vc<X> lvs, rvs;\r\
    \n    FOR(k, m) {\r\n      int i = I[k];\r\n      lxs.eb(xs[i]);\r\n      lys.eb(ys[i]);\r\
    \n      lvs.eb(vs[i]);\r\n    }\r\n    FOR(k, m, n) {\r\n      int i = I[k];\r\
    \n      rxs.eb(xs[i]);\r\n      rys.eb(ys[i]);\r\n      rvs.eb(vs[i]);\r\n   \
    \ }\r\n    build(2 * idx + 0, lxs, lys, lvs, !divx);\r\n    build(2 * idx + 1,\
    \ rxs, rys, rvs, !divx);\r\n    dat[idx] = Monoid::op(dat[2 * idx + 0], dat[2\
    \ * idx + 1]);\r\n  }\r\n\r\n  bool isin(const int& idx, const XY& x, const XY&\
    \ y) {\r\n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    return (xmin\
    \ <= x && x <= xmax && ymin <= y && y <= ymax);\r\n  }\r\n\r\n  void set_rec(const\
    \ int& idx, const XY& x, const XY& y, const X& v) {\r\n    if (!isin(idx, x, y))\
    \ return;\r\n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (xmin\
    \ == xmax && ymin == ymax) {\r\n      dat[idx] = v;\r\n      return;\r\n    }\r\
    \n    set_rec(2 * idx + 0, x, y, v);\r\n    set_rec(2 * idx + 1, x, y, v);\r\n\
    \    dat[idx] = Monoid::op(dat[2 * idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n\
    \  void multiply_rec(const int& idx, const XY& x, const XY& y, const X& v) {\r\
    \n    if (!isin(idx, x, y)) return;\r\n    auto& [xmin, xmax, ymin, ymax] = range[idx];\r\
    \n    if (xmin == xmax && ymin == ymax) {\r\n      dat[idx] = Monoid::op(dat[idx],\
    \ v);\r\n      return;\r\n    }\r\n    multiply_rec(2 * idx + 0, x, y, v);\r\n\
    \    multiply_rec(2 * idx + 1, x, y, v);\r\n    dat[idx] = Monoid::op(dat[2 *\
    \ idx + 0], dat[2 * idx + 1]);\r\n  }\r\n\r\n  X prod_rec(const int& idx, const\
    \ XY& x1, const XY& x2, const XY& y1,\r\n             const XY& y2) {\r\n    auto&\
    \ [xmin, xmax, ymin, ymax] = range[idx];\r\n    if (x2 <= xmin || xmax < x1) return\
    \ Monoid::unit();\r\n    if (y2 <= ymin || ymax < y1) return Monoid::unit();\r\
    \n    if (x1 <= xmin && xmax < x2 && y1 <= ymin && ymax < y2) { return dat[idx];\
    \ }\r\n    return Monoid::op(prod_rec(2 * idx + 0, x1, x2, y1, y2),\r\n      \
    \                prod_rec(2 * idx + 1, x1, x2, y1, y2));\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/kdtree/kdtree_monoid.hpp
  requiredBy: []
  timestamp: '2022-12-03 10:20:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1625.test.cpp
  - test/aoj/DSL_2_C.test.cpp
documentation_of: ds/kdtree/kdtree_monoid.hpp
layout: document
redirect_from:
- /library/ds/kdtree/kdtree_monoid.hpp
- /library/ds/kdtree/kdtree_monoid.hpp.html
title: ds/kdtree/kdtree_monoid.hpp
---
