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
  bundledCode: "#line 1 \"ds/segtree/dual_segtree_2d_dense.hpp\"\n\ntemplate <class\
    \ Monoid>\nstruct DualSegTree_2D_Dense {\n  using MX = Monoid;\n  using X = typename\
    \ MX::value_type;\n  using value_type = X;\n  static_assert(MX::commute);\n  int\
    \ H, W;\n  vc<X> dat;\n\n  DualSegTree_2D_Dense() : DualSegTree_2D_Dense(0, 0)\
    \ {}\n  DualSegTree_2D_Dense(int H, int W) : H(H), W(W), dat(4 * H * W, MX::unit())\
    \ {}\n\n  X get(int x, int y) {\n    X t = MX::unit();\n    int a = x + H;\n \
    \   while (a) {\n      int b = y + W;\n      while (b) { t = MX::op(t, dat[idx(a,\
    \ b)]), b /= 2; }\n      a /= 2;\n    };\n    return t;\n  }\n\n  vvc<X> get_all()\
    \ {\n    FOR(x, 1, H) { FOR(y, W) push_x(x, y); }\n    FOR(x, 1, H) {\n      FOR(y,\
    \ 2 * W) {\n        dat[idx(2 * x + 0, y)] = MX::op(dat[idx(2 * x + 0, y)], dat[idx(x,\
    \ y)]);\n        dat[idx(2 * x + 1, y)] = MX::op(dat[idx(2 * x + 1, y)], dat[idx(x,\
    \ y)]);\n        dat[idx(x, y)] = MX::unit();\n      }\n    }\n    vv(X, res,\
    \ H, W, MX::unit());\n    FOR(x, H) FOR(y, W) { res[x][y] = dat[idx(x + H, y +\
    \ W)]; }\n    return res;\n  }\n\n  X apply(int xl, int xr, int yl, int yr, X\
    \ x) {\n    assert(0 <= xl && xl <= xr && xr <= H);\n    assert(0 <= yl && yl\
    \ <= yr && yr <= W);\n    X res = MX::unit();\n    xl += H, xr += H;\n    while\
    \ (xl < xr) {\n      if (xl & 1) apply_x(xl++, yl, yr, x);\n      if (xr & 1)\
    \ apply_x(--xr, yl, yr, x);\n      xl >>= 1, xr >>= 1;\n    }\n    return res;\n\
    \  }\n\nprivate:\n  inline int idx(int x, int y) { return x * 2 * W + y; }\n \
    \ void apply_x(int x, int yl, int yr, const X& t) {\n    yl += W, yr += W;\n \
    \   while (yl < yr) {\n      if (yl & 1) { dat[idx(x, yl)] = MX::op(dat[idx(x,\
    \ yl)], t), yl++; }\n      if (yr & 1) { --yr, dat[idx(x, yr)] = MX::op(dat[idx(x,\
    \ yr)], t); }\n      yl >>= 1, yr >>= 1;\n    }\n  }\n\n  void push_x(int x, int\
    \ k) {\n    dat[idx(x, 2 * k + 0)] = MX::op(dat[idx(x, 2 * k + 0)], dat[idx(x,\
    \ k)]);\n    dat[idx(x, 2 * k + 1)] = MX::op(dat[idx(x, 2 * k + 1)], dat[idx(x,\
    \ k)]);\n    dat[idx(x, k)] = MX::unit();\n  }\n};\n"
  code: "\ntemplate <class Monoid>\nstruct DualSegTree_2D_Dense {\n  using MX = Monoid;\n\
    \  using X = typename MX::value_type;\n  using value_type = X;\n  static_assert(MX::commute);\n\
    \  int H, W;\n  vc<X> dat;\n\n  DualSegTree_2D_Dense() : DualSegTree_2D_Dense(0,\
    \ 0) {}\n  DualSegTree_2D_Dense(int H, int W) : H(H), W(W), dat(4 * H * W, MX::unit())\
    \ {}\n\n  X get(int x, int y) {\n    X t = MX::unit();\n    int a = x + H;\n \
    \   while (a) {\n      int b = y + W;\n      while (b) { t = MX::op(t, dat[idx(a,\
    \ b)]), b /= 2; }\n      a /= 2;\n    };\n    return t;\n  }\n\n  vvc<X> get_all()\
    \ {\n    FOR(x, 1, H) { FOR(y, W) push_x(x, y); }\n    FOR(x, 1, H) {\n      FOR(y,\
    \ 2 * W) {\n        dat[idx(2 * x + 0, y)] = MX::op(dat[idx(2 * x + 0, y)], dat[idx(x,\
    \ y)]);\n        dat[idx(2 * x + 1, y)] = MX::op(dat[idx(2 * x + 1, y)], dat[idx(x,\
    \ y)]);\n        dat[idx(x, y)] = MX::unit();\n      }\n    }\n    vv(X, res,\
    \ H, W, MX::unit());\n    FOR(x, H) FOR(y, W) { res[x][y] = dat[idx(x + H, y +\
    \ W)]; }\n    return res;\n  }\n\n  X apply(int xl, int xr, int yl, int yr, X\
    \ x) {\n    assert(0 <= xl && xl <= xr && xr <= H);\n    assert(0 <= yl && yl\
    \ <= yr && yr <= W);\n    X res = MX::unit();\n    xl += H, xr += H;\n    while\
    \ (xl < xr) {\n      if (xl & 1) apply_x(xl++, yl, yr, x);\n      if (xr & 1)\
    \ apply_x(--xr, yl, yr, x);\n      xl >>= 1, xr >>= 1;\n    }\n    return res;\n\
    \  }\n\nprivate:\n  inline int idx(int x, int y) { return x * 2 * W + y; }\n \
    \ void apply_x(int x, int yl, int yr, const X& t) {\n    yl += W, yr += W;\n \
    \   while (yl < yr) {\n      if (yl & 1) { dat[idx(x, yl)] = MX::op(dat[idx(x,\
    \ yl)], t), yl++; }\n      if (yr & 1) { --yr, dat[idx(x, yr)] = MX::op(dat[idx(x,\
    \ yr)], t); }\n      yl >>= 1, yr >>= 1;\n    }\n  }\n\n  void push_x(int x, int\
    \ k) {\n    dat[idx(x, 2 * k + 0)] = MX::op(dat[idx(x, 2 * k + 0)], dat[idx(x,\
    \ k)]);\n    dat[idx(x, 2 * k + 1)] = MX::op(dat[idx(x, 2 * k + 1)], dat[idx(x,\
    \ k)]);\n    dat[idx(x, k)] = MX::unit();\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/dual_segtree_2d_dense.hpp
  requiredBy: []
  timestamp: '2024-07-23 21:51:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/dual_segtree_2d_dense.hpp
layout: document
redirect_from:
- /library/ds/segtree/dual_segtree_2d_dense.hpp
- /library/ds/segtree/dual_segtree_2d_dense.hpp.html
title: ds/segtree/dual_segtree_2d_dense.hpp
---
