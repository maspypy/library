---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc266h.test.cpp
    title: test/atcoder/abc266h.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1600.test.cpp
    title: test/yukicoder/1600.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/segtree/segtree_2d.hpp\"\ntemplate <typename Monoid,\
    \ typename XY, bool SMALL = false>\r\nstruct SegTree_2D {\r\n  using MX = Monoid;\r\
    \n  using S = typename MX::value_type;\r\n  static_assert(MX::commute);\r\n  int\
    \ N, min_X;\r\n  vc<XY> keyX, keyY;\r\n  vc<int> indptr;\r\n  vc<S> dat;\r\n\r\
    \n  SegTree_2D(vc<XY>& X, vc<XY>& Y, vc<S> wt = vc<S>()) {\r\n    if (len(wt)\
    \ == 0) wt = vc<S>(len(X), MX::unit());\r\n    assert(len(X) == len(Y) && len(X)\
    \ == len(wt));\r\n    if (!SMALL) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\
    \n      N = len(keyX);\r\n      keyX.shrink_to_fit();\r\n    } else {\r\n    \
    \  min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X) == 0 ? 0 : MAX(X))\
    \ - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N) keyX[i] = min_X + i;\r\
    \n    }\r\n\r\n    vvc<XY> keyY_raw(N + N);\r\n    vvc<S> dat_raw(N + N);\r\n\
    \    for (auto&& i: argsort(Y)) {\r\n      int ix = xtoi(X[i]), y = Y[i];\r\n\
    \      ix += N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\n\
    \        if (len(KY) == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n     \
    \     dat_raw[ix].eb(wt[i]);\r\n        } else {\r\n          dat_raw[ix].back()\
    \ = MX::op(dat_raw[ix].back(), wt[i]);\r\n        }\r\n        ix >>= 1;\r\n \
    \     }\r\n    }\r\n\r\n    indptr.assign(N + N + 1, 0);\r\n    FOR(i, N + N)\
    \ indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\n    int full_N = indptr.back();\r\
    \n    keyY.resize(full_N), dat.assign(2 * full_N, MX::unit());\r\n    FOR(i, N\
    \ + N) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \      FOR(j, n) {\r\n        keyY[indptr[i] + j] = keyY_raw[i][j];\r\n      \
    \  dat[off + n + j] = dat_raw[i][j];\r\n      }\r\n      FOR_R(j, 1, n) {\r\n\
    \        dat[off + j] = MX::op(dat[off + 2 * j], dat[off + 2 * j + 1]);\r\n  \
    \    }\r\n    }\r\n  }\r\n\r\n  void multiply(XY x, XY y, S val) {\r\n    int\
    \ i = xtoi(x);\r\n    assert(keyX[i] == x);\r\n    i += N;\r\n    while (i) {\
    \ multiply_i(i, y, val), i >>= 1; }\r\n  }\r\n\r\n  S prod(XY lx, XY rx, XY ly,\
    \ XY ry) {\r\n    int L = xtoi(lx) + N, R = xtoi(rx) + N;\r\n    S val = MX::unit();\r\
    \n    while (L < R) {\r\n      if (L & 1) val = MX::op(val, prod_i(L++, ly, ry));\r\
    \n      if (R & 1) val = MX::op(prod_i(--R, ly, ry), val);\r\n      L >>= 1, R\
    \ >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\nprivate:\r\n  inline int xtoi(XY\
    \ x) {\r\n    return (SMALL ? clamp<XY>(x - min_X, 0, N) : LB(keyX, x));\r\n \
    \ }\r\n  S prod_i(int i, XY ly, XY ry) {\r\n    int LID = indptr[i], n = indptr[i\
    \ + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it,\
    \ it + n, ly) - it + n;\r\n    int R = lower_bound(it, it + n, ry) - it + n;\r\
    \n    int off = 2 * LID;\r\n    S val = MX::unit();\r\n    while (L < R) {\r\n\
    \      if (L & 1) val = MX::op(val, dat[off + (L++)]);\r\n      if (R & 1) val\
    \ = MX::op(dat[off + (--R)], val);\r\n      L >>= 1, R >>= 1;\r\n    }\r\n   \
    \ return val;\r\n  }\r\n  void multiply_i(int i, XY y, S val) {\r\n    int LID\
    \ = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() +\
    \ LID;\r\n    int j = lower_bound(it, it + n, y) - it;\r\n    assert(keyY[LID\
    \ + j] == y);\r\n    int off = 2 * LID;\r\n    j += n;\r\n    while (j) {\r\n\
    \      dat[off + j] = MX::op(dat[off + j], val);\r\n      j >>= 1;\r\n    }\r\n\
    \  }\r\n};\n"
  code: "template <typename Monoid, typename XY, bool SMALL = false>\r\nstruct SegTree_2D\
    \ {\r\n  using MX = Monoid;\r\n  using S = typename MX::value_type;\r\n  static_assert(MX::commute);\r\
    \n  int N, min_X;\r\n  vc<XY> keyX, keyY;\r\n  vc<int> indptr;\r\n  vc<S> dat;\r\
    \n\r\n  SegTree_2D(vc<XY>& X, vc<XY>& Y, vc<S> wt = vc<S>()) {\r\n    if (len(wt)\
    \ == 0) wt = vc<S>(len(X), MX::unit());\r\n    assert(len(X) == len(Y) && len(X)\
    \ == len(wt));\r\n    if (!SMALL) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\
    \n      N = len(keyX);\r\n      keyX.shrink_to_fit();\r\n    } else {\r\n    \
    \  min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X) == 0 ? 0 : MAX(X))\
    \ - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N) keyX[i] = min_X + i;\r\
    \n    }\r\n\r\n    vvc<XY> keyY_raw(N + N);\r\n    vvc<S> dat_raw(N + N);\r\n\
    \    for (auto&& i: argsort(Y)) {\r\n      int ix = xtoi(X[i]), y = Y[i];\r\n\
    \      ix += N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\n\
    \        if (len(KY) == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n     \
    \     dat_raw[ix].eb(wt[i]);\r\n        } else {\r\n          dat_raw[ix].back()\
    \ = MX::op(dat_raw[ix].back(), wt[i]);\r\n        }\r\n        ix >>= 1;\r\n \
    \     }\r\n    }\r\n\r\n    indptr.assign(N + N + 1, 0);\r\n    FOR(i, N + N)\
    \ indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\n    int full_N = indptr.back();\r\
    \n    keyY.resize(full_N), dat.assign(2 * full_N, MX::unit());\r\n    FOR(i, N\
    \ + N) {\r\n      int off = 2 * indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \      FOR(j, n) {\r\n        keyY[indptr[i] + j] = keyY_raw[i][j];\r\n      \
    \  dat[off + n + j] = dat_raw[i][j];\r\n      }\r\n      FOR_R(j, 1, n) {\r\n\
    \        dat[off + j] = MX::op(dat[off + 2 * j], dat[off + 2 * j + 1]);\r\n  \
    \    }\r\n    }\r\n  }\r\n\r\n  void multiply(XY x, XY y, S val) {\r\n    int\
    \ i = xtoi(x);\r\n    assert(keyX[i] == x);\r\n    i += N;\r\n    while (i) {\
    \ multiply_i(i, y, val), i >>= 1; }\r\n  }\r\n\r\n  S prod(XY lx, XY rx, XY ly,\
    \ XY ry) {\r\n    int L = xtoi(lx) + N, R = xtoi(rx) + N;\r\n    S val = MX::unit();\r\
    \n    while (L < R) {\r\n      if (L & 1) val = MX::op(val, prod_i(L++, ly, ry));\r\
    \n      if (R & 1) val = MX::op(prod_i(--R, ly, ry), val);\r\n      L >>= 1, R\
    \ >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\nprivate:\r\n  inline int xtoi(XY\
    \ x) {\r\n    return (SMALL ? clamp<XY>(x - min_X, 0, N) : LB(keyX, x));\r\n \
    \ }\r\n  S prod_i(int i, XY ly, XY ry) {\r\n    int LID = indptr[i], n = indptr[i\
    \ + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it,\
    \ it + n, ly) - it + n;\r\n    int R = lower_bound(it, it + n, ry) - it + n;\r\
    \n    int off = 2 * LID;\r\n    S val = MX::unit();\r\n    while (L < R) {\r\n\
    \      if (L & 1) val = MX::op(val, dat[off + (L++)]);\r\n      if (R & 1) val\
    \ = MX::op(dat[off + (--R)], val);\r\n      L >>= 1, R >>= 1;\r\n    }\r\n   \
    \ return val;\r\n  }\r\n  void multiply_i(int i, XY y, S val) {\r\n    int LID\
    \ = indptr[i], n = indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() +\
    \ LID;\r\n    int j = lower_bound(it, it + n, y) - it;\r\n    assert(keyY[LID\
    \ + j] == y);\r\n    int off = 2 * LID;\r\n    j += n;\r\n    while (j) {\r\n\
    \      dat[off + j] = MX::op(dat[off + j], val);\r\n      j >>= 1;\r\n    }\r\n\
    \  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_2d.hpp
  requiredBy: []
  timestamp: '2022-12-04 01:13:06+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1600.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_seg2d.test.cpp
  - test/atcoder/abc266h.test.cpp
documentation_of: ds/segtree/segtree_2d.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_2d.hpp
- /library/ds/segtree/segtree_2d.hpp.html
title: ds/segtree/segtree_2d.hpp
---
