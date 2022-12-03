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
  bundledCode: "#line 2 \"ds/segtree/segtree_2d_dense.hpp\"\n\ntemplate <class Monoid>\n\
    struct SegTree2D_Dense {\n  using MX = Monoid;\n  using X = typename MX::value_type;\n\
    \  using value_type = X;\n  static_assert(MX::commute);\n  vc<X> dat;\n  int H,\
    \ W;\n\n  SegTree2D_Dense() : SegTree2D_Dense(0, 0) {}\n  SegTree2D_Dense(int\
    \ H, int W) : H(H), W(W), dat(4 * H * W, MX::unit()) {}\n  SegTree2D_Dense(vc<vc<X>>\
    \ &v) {\n    H = len(v), W = (H == 0 ? 0 : len(v[0]));\n    dat.assign(4 * H *\
    \ W, MX::unit());\n    FOR(x, H) FOR(y, W) { dat[idx(H + x, W + y)] = v[x][y];\
    \ }\n    FOR(y, W, W + W) FOR_R(x, H) {\n      dat[idx(x, y)] = MX::op(dat[idx(2\
    \ * x + 0, y)], dat[idx(2 * x + 1, y)]);\n    }\n    FOR(x, H + H) FOR(y, W) {\n\
    \      dat[idx(x, y)] = MX::op(dat[idx(x, 2 * y + 0)], dat[idx(x, 2 * y + 1)]);\n\
    \    }\n  }\n\n  void set(int x, int y, X e) {\n    x += H, y += W;\n    dat[idx(x,\
    \ y)] = e;\n    int i = x;\n    while (i >>= 1) {\n      dat[idx(i, y)] = MX::op(dat[idx(2\
    \ * i + 0, y)], dat[idx(2 * i + 1, y)]);\n    }\n    i = x;\n    while (i) {\n\
    \      int j = y;\n      while (j >>= 1) {\n        dat[idx(i, j)] = MX::op(dat[idx(i,\
    \ 2 * j + 0)], dat[idx(i, 2 * j + 1)]);\n      }\n      i >>= 1;\n    }\n  }\n\
    \n  X prod(int xl, int xr, int yl, int yr) {\n    assert(0 <= xl && xl <= xr &&\
    \ xr <= H);\n    assert(0 <= yl && yl <= yr && yr <= W);\n    X res = MX::unit();\n\
    \    xl += H, xr += H;\n    while (xl < xr) {\n      if (xl & 1) res = MX::op(res,\
    \ prod_x(xl++, yl, yr));\n      if (xr & 1) res = MX::op(res, prod_x(--xr, yl,\
    \ yr));\n      xl >>= 1, xr >>= 1;\n    }\n    return res;\n  }\n\nprivate:\n\
    \  inline int idx(int x, int y) { return x * 2 * W + y; }\n  X prod_x(int x, int\
    \ yl, int yr) {\n    X res = MX::unit();\n    yl += W, yr += W;\n    while (yl\
    \ < yr) {\n      if (yl & 1) res = MX::op(res, dat[idx(x, yl++)]);\n      if (yr\
    \ & 1) res = MX::op(res, dat[idx(x, --yr)]);\n      yl >>= 1, yr >>= 1;\n    }\n\
    \    return res;\n  }\n};\n"
  code: "#pragma once\n\ntemplate <class Monoid>\nstruct SegTree2D_Dense {\n  using\
    \ MX = Monoid;\n  using X = typename MX::value_type;\n  using value_type = X;\n\
    \  static_assert(MX::commute);\n  vc<X> dat;\n  int H, W;\n\n  SegTree2D_Dense()\
    \ : SegTree2D_Dense(0, 0) {}\n  SegTree2D_Dense(int H, int W) : H(H), W(W), dat(4\
    \ * H * W, MX::unit()) {}\n  SegTree2D_Dense(vc<vc<X>> &v) {\n    H = len(v),\
    \ W = (H == 0 ? 0 : len(v[0]));\n    dat.assign(4 * H * W, MX::unit());\n    FOR(x,\
    \ H) FOR(y, W) { dat[idx(H + x, W + y)] = v[x][y]; }\n    FOR(y, W, W + W) FOR_R(x,\
    \ H) {\n      dat[idx(x, y)] = MX::op(dat[idx(2 * x + 0, y)], dat[idx(2 * x +\
    \ 1, y)]);\n    }\n    FOR(x, H + H) FOR(y, W) {\n      dat[idx(x, y)] = MX::op(dat[idx(x,\
    \ 2 * y + 0)], dat[idx(x, 2 * y + 1)]);\n    }\n  }\n\n  void set(int x, int y,\
    \ X e) {\n    x += H, y += W;\n    dat[idx(x, y)] = e;\n    int i = x;\n    while\
    \ (i >>= 1) {\n      dat[idx(i, y)] = MX::op(dat[idx(2 * i + 0, y)], dat[idx(2\
    \ * i + 1, y)]);\n    }\n    i = x;\n    while (i) {\n      int j = y;\n     \
    \ while (j >>= 1) {\n        dat[idx(i, j)] = MX::op(dat[idx(i, 2 * j + 0)], dat[idx(i,\
    \ 2 * j + 1)]);\n      }\n      i >>= 1;\n    }\n  }\n\n  X prod(int xl, int xr,\
    \ int yl, int yr) {\n    assert(0 <= xl && xl <= xr && xr <= H);\n    assert(0\
    \ <= yl && yl <= yr && yr <= W);\n    X res = MX::unit();\n    xl += H, xr +=\
    \ H;\n    while (xl < xr) {\n      if (xl & 1) res = MX::op(res, prod_x(xl++,\
    \ yl, yr));\n      if (xr & 1) res = MX::op(res, prod_x(--xr, yl, yr));\n    \
    \  xl >>= 1, xr >>= 1;\n    }\n    return res;\n  }\n\nprivate:\n  inline int\
    \ idx(int x, int y) { return x * 2 * W + y; }\n  X prod_x(int x, int yl, int yr)\
    \ {\n    X res = MX::unit();\n    yl += W, yr += W;\n    while (yl < yr) {\n \
    \     if (yl & 1) res = MX::op(res, dat[idx(x, yl++)]);\n      if (yr & 1) res\
    \ = MX::op(res, dat[idx(x, --yr)]);\n      yl >>= 1, yr >>= 1;\n    }\n    return\
    \ res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_2d_dense.hpp
  requiredBy: []
  timestamp: '2022-12-03 10:36:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/segtree_2d_dense.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_2d_dense.hpp
- /library/ds/segtree/segtree_2d_dense.hpp.html
title: ds/segtree/segtree_2d_dense.hpp
---
