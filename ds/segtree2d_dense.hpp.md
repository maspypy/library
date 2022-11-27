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
    - https://codeforces.com/contest/1301/problem/E
  bundledCode: "#line 2 \"ds/segtree2d_dense.hpp\"\n\n// https://codeforces.com/contest/1301/problem/E\n\
    template <class Monoid>\nstruct SegTree2D_dense {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int H, W;\n\n  int get_idx(int x, int\
    \ y) { return x * 2 * W + y; }\n\n  SegTree2D_dense() : SegTree2D_dense(0, 0)\
    \ {}\n  SegTree2D_dense(int H, int W) : H(H), W(W), dat(4 * H * W, Monoid::unit())\
    \ {}\n  SegTree2D_dense(vc<vc<X>> &v) {\n    H = len(v);\n    W = (H == 0 ? 0\
    \ : len(v[0]));\n    dat.assign(4 * H * W, Monoid::unit());\n    FOR(x, H) FOR(y,\
    \ W) { dat[get_idx(H + x, W + y)] = v[x][y]; }\n    FOR3(y, W, W + W) FOR_R(x,\
    \ H) {\n      dat[get_idx(x, y)]\n          = Monoid::op(dat[get_idx(2 * x + 0,\
    \ y)], dat[get_idx(2 * x + 1, y)]);\n    }\n    FOR(x, H + H) {\n      FOR_R(y,\
    \ W) {\n        dat[get_idx(x, y)] = Monoid::op(dat[get_idx(x, 2 * y + 0)],\n\
    \                                        dat[get_idx(x, 2 * y + 1)]);\n      }\n\
    \    }\n  }\n\n  void set(int x, int y, X e) {\n    x += H, y += W;\n    dat[get_idx(x,\
    \ y)] = e;\n    int i = x;\n    while (i >>= 1) {\n      dat[get_idx(i, y)]\n\
    \          = Monoid::op(dat[get_idx(2 * i + 0, y)], dat[get_idx(2 * i + 1, y)]);\n\
    \    }\n    i = x;\n    while (i) {\n      int j = y;\n      while (j >>= 1) {\n\
    \        dat[get_idx(i, j)] = Monoid::op(dat[get_idx(i, 2 * j + 0)],\n       \
    \                                 dat[get_idx(i, 2 * j + 1)]);\n      }\n    \
    \  i >>= 1;\n    }\n  }\n\n  X prod_at(int x, int yl, int yr) {\n    X res = Monoid::unit();\n\
    \    yl += W, yr += W;\n    while (yl < yr) {\n      if (yl & 1) res = Monoid::op(res,\
    \ dat[get_idx(x, yl++)]);\n      if (yr & 1) res = Monoid::op(res, dat[get_idx(x,\
    \ --yr)]);\n      yl >>= 1, yr >>= 1;\n    }\n    return res;\n  }\n\n  X prod(int\
    \ xl, int xr, int yl, int yr) {\n    assert(0 <= xl && xl <= xr && xr <= H);\n\
    \    assert(0 <= yl && yl <= yr && yr <= W);\n    X res = Monoid::unit();\n  \
    \  xl += H, xr += H;\n    while (xl < xr) {\n      if (xl & 1) res = Monoid::op(res,\
    \ prod_at(xl++, yl, yr));\n      if (xr & 1) res = Monoid::op(res, prod_at(--xr,\
    \ yl, yr));\n      xl >>= 1, xr >>= 1;\n    }\n    return res;\n  }\n\n  void\
    \ debug() { print(\"segtree\", dat); }\n};\n"
  code: "#pragma once\n\n// https://codeforces.com/contest/1301/problem/E\ntemplate\
    \ <class Monoid>\nstruct SegTree2D_dense {\n  using X = typename Monoid::value_type;\n\
    \  using value_type = X;\n  vc<X> dat;\n  int H, W;\n\n  int get_idx(int x, int\
    \ y) { return x * 2 * W + y; }\n\n  SegTree2D_dense() : SegTree2D_dense(0, 0)\
    \ {}\n  SegTree2D_dense(int H, int W) : H(H), W(W), dat(4 * H * W, Monoid::unit())\
    \ {}\n  SegTree2D_dense(vc<vc<X>> &v) {\n    H = len(v);\n    W = (H == 0 ? 0\
    \ : len(v[0]));\n    dat.assign(4 * H * W, Monoid::unit());\n    FOR(x, H) FOR(y,\
    \ W) { dat[get_idx(H + x, W + y)] = v[x][y]; }\n    FOR3(y, W, W + W) FOR_R(x,\
    \ H) {\n      dat[get_idx(x, y)]\n          = Monoid::op(dat[get_idx(2 * x + 0,\
    \ y)], dat[get_idx(2 * x + 1, y)]);\n    }\n    FOR(x, H + H) {\n      FOR_R(y,\
    \ W) {\n        dat[get_idx(x, y)] = Monoid::op(dat[get_idx(x, 2 * y + 0)],\n\
    \                                        dat[get_idx(x, 2 * y + 1)]);\n      }\n\
    \    }\n  }\n\n  void set(int x, int y, X e) {\n    x += H, y += W;\n    dat[get_idx(x,\
    \ y)] = e;\n    int i = x;\n    while (i >>= 1) {\n      dat[get_idx(i, y)]\n\
    \          = Monoid::op(dat[get_idx(2 * i + 0, y)], dat[get_idx(2 * i + 1, y)]);\n\
    \    }\n    i = x;\n    while (i) {\n      int j = y;\n      while (j >>= 1) {\n\
    \        dat[get_idx(i, j)] = Monoid::op(dat[get_idx(i, 2 * j + 0)],\n       \
    \                                 dat[get_idx(i, 2 * j + 1)]);\n      }\n    \
    \  i >>= 1;\n    }\n  }\n\n  X prod_at(int x, int yl, int yr) {\n    X res = Monoid::unit();\n\
    \    yl += W, yr += W;\n    while (yl < yr) {\n      if (yl & 1) res = Monoid::op(res,\
    \ dat[get_idx(x, yl++)]);\n      if (yr & 1) res = Monoid::op(res, dat[get_idx(x,\
    \ --yr)]);\n      yl >>= 1, yr >>= 1;\n    }\n    return res;\n  }\n\n  X prod(int\
    \ xl, int xr, int yl, int yr) {\n    assert(0 <= xl && xl <= xr && xr <= H);\n\
    \    assert(0 <= yl && yl <= yr && yr <= W);\n    X res = Monoid::unit();\n  \
    \  xl += H, xr += H;\n    while (xl < xr) {\n      if (xl & 1) res = Monoid::op(res,\
    \ prod_at(xl++, yl, yr));\n      if (xr & 1) res = Monoid::op(res, prod_at(--xr,\
    \ yl, yr));\n      xl >>= 1, xr >>= 1;\n    }\n    return res;\n  }\n\n  void\
    \ debug() { print(\"segtree\", dat); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree2d_dense.hpp
  requiredBy: []
  timestamp: '2022-11-14 21:12:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree2d_dense.hpp
layout: document
redirect_from:
- /library/ds/segtree2d_dense.hpp
- /library/ds/segtree2d_dense.hpp.html
title: ds/segtree2d_dense.hpp
---
