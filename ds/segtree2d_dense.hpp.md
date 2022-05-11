---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2842_seg2d_dense.test.cpp
    title: test/aoj/2842_seg2d_dense.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://codeforces.com/contest/1301/problem/E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.4/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ ds/segtree2d_dense.hpp: line 2: #pragma once found in a non-first line\n"
  code: "// https://codeforces.com/contest/1301/problem/E\n#pragma once\ntemplate\
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
    \ xl, int yl, int xr, int yr) {\n    assert(0 <= xl && xl <= xr && xr <= H);\n\
    \    assert(0 <= yl && yl <= yr && yr <= W);\n    X res = Monoid::unit();\n  \
    \  xl += H, xr += H;\n    while (xl < xr) {\n      if (xl & 1) res = Monoid::op(res,\
    \ prod_at(xl++, yl, yr));\n      if (xr & 1) res = Monoid::op(res, prod_at(--xr,\
    \ yl, yr));\n      xl >>= 1, xr >>= 1;\n    }\n    return res;\n  }\n\n  void\
    \ debug() { print(\"segtree\", dat); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree2d_dense.hpp
  requiredBy: []
  timestamp: '2022-04-16 17:44:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/2842_seg2d_dense.test.cpp
documentation_of: ds/segtree2d_dense.hpp
layout: document
redirect_from:
- /library/ds/segtree2d_dense.hpp
- /library/ds/segtree2d_dense.hpp.html
title: ds/segtree2d_dense.hpp
---
