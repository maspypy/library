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
  bundledCode: "#line 1 \"ds/segtree/segtree_2d.hpp\"\ntemplate <typename Monoid,\
    \ typename XY, bool SMALL = false>\r\nstruct SegTree2D {\r\n  using S = typename\
    \ Monoid::value_type;\r\n  int N;\r\n  int full_N;\r\n  vc<XY> keyX;\r\n  int\
    \ min_X;\r\n  vc<int> indptr;\r\n  vc<XY> keyY;\r\n  vc<S> dat;\r\n\r\n  inline\
    \ int xtoi(XY x) {\r\n    if (SMALL) return clamp<XY>(x - min_X, 0, N);\r\n  \
    \  return LB(keyX, x);\r\n  }\r\n\r\n  SegTree2D(vc<XY>& X, vc<XY>& Y, vc<S> wt\
    \ = vc<S>()) {\r\n    if (len(wt) == 0) wt = vc<S>(len(X), Monoid::unit());\r\n\
    \    assert(Monoid::commute); // \u53EF\u63DB\u30E2\u30CE\u30A4\u30C9\u306E\u307F\
    \r\n    assert(len(X) == len(Y) && len(X) == len(wt));\r\n\r\n    if (!SMALL)\
    \ {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\n      N = len(keyX);\r\n    }\
    \ else {\r\n      min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X) ==\
    \ 0 ? 0 : MAX(X)) - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N) keyX[i]\
    \ = min_X + i;\r\n    }\r\n\r\n    vc<vc<XY>> keyY_raw(N + N);\r\n    vc<vc<S>>\
    \ dat_raw(N + N);\r\n\r\n    auto I = argsort(Y);\r\n    for (auto&& i: I) {\r\
    \n      int ix = xtoi(X[i]), y = Y[i];\r\n      ix += N;\r\n      while (ix) {\r\
    \n        auto& KY = keyY_raw[ix];\r\n        if (len(KY) == 0 || KY.back() <\
    \ y) {\r\n          KY.eb(y);\r\n          dat_raw[ix].eb(wt[i]);\r\n        }\
    \ else {\r\n          dat_raw[ix].back() = Monoid::op(dat_raw[ix].back(), wt[i]);\r\
    \n        }\r\n        ix >>= 1;\r\n      }\r\n    }\r\n\r\n    indptr.assign(N\
    \ + N + 1, 0);\r\n    FOR(i, N + N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\
    \n    int full_N = indptr.back();\r\n    keyY.resize(full_N);\r\n    dat.assign(2\
    \ * full_N, Monoid::unit());\r\n    FOR(i, N + N) {\r\n      int off = 2 * indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n      FOR(j, n) {\r\n        keyY[indptr[i]\
    \ + j] = keyY_raw[i][j];\r\n        dat[off + n + j] = dat_raw[i][j];\r\n    \
    \  }\r\n      FOR3_R(j, 1, n)\r\n      dat[off + j] = Monoid::op(dat[off + 2 *\
    \ j + 0], dat[off + 2 * j + 1]);\r\n    }\r\n  }\r\n\r\n  void multiply_i(int\
    \ i, XY y, S val) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n    auto it = keyY.begin() + LID;\r\n    int j = lower_bound(it, it + n, y)\
    \ - it;\r\n    assert(keyY[LID + j] == y);\r\n    int off = 2 * LID;\r\n    j\
    \ += n;\r\n\r\n    while (j) {\r\n      dat[off + j] = Monoid::op(dat[off + j],\
    \ val);\r\n      j >>= 1;\r\n    }\r\n  }\r\n\r\n  void multiply(XY x, XY y, S\
    \ val) {\r\n    int i = xtoi(x);\r\n    assert(keyX[i] == x);\r\n    i += N;\r\
    \n    while (i) {\r\n      multiply_i(i, y, val);\r\n      i >>= 1;\r\n    }\r\
    \n  }\r\n\r\n  S prod_i(int i, XY ly, XY ry) {\r\n    int LID = indptr[i], n =\
    \ indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int L\
    \ = lower_bound(it, it + n, ly) - it;\r\n    int R = lower_bound(it, it + n, ry)\
    \ - it;\r\n    int off = 2 * LID;\r\n    L += n;\r\n    R += n;\r\n    S val =\
    \ Monoid::unit();\r\n    while (L < R) {\r\n      if (L & 1) val = Monoid::op(val,\
    \ dat[off + (L++)]);\r\n      if (R & 1) val = Monoid::op(dat[off + (--R)], val);\r\
    \n      L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n\
    \  S prod(XY lx, XY rx, XY ly, XY ry) {\r\n    int L = xtoi(lx);\r\n    int R\
    \ = xtoi(rx);\r\n    L += N;\r\n    R += N;\r\n    S val = Monoid::unit();\r\n\
    \    while (L < R) {\r\n      if (L & 1) val = Monoid::op(val, prod_i(L++, ly,\
    \ ry));\r\n      if (R & 1) val = Monoid::op(prod_i(--R, ly, ry), val);\r\n  \
    \    L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n  void\
    \ debug() {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\", indptr);\r\n\
    \    print(\"keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n};\n"
  code: "template <typename Monoid, typename XY, bool SMALL = false>\r\nstruct SegTree2D\
    \ {\r\n  using S = typename Monoid::value_type;\r\n  int N;\r\n  int full_N;\r\
    \n  vc<XY> keyX;\r\n  int min_X;\r\n  vc<int> indptr;\r\n  vc<XY> keyY;\r\n  vc<S>\
    \ dat;\r\n\r\n  inline int xtoi(XY x) {\r\n    if (SMALL) return clamp<XY>(x -\
    \ min_X, 0, N);\r\n    return LB(keyX, x);\r\n  }\r\n\r\n  SegTree2D(vc<XY>& X,\
    \ vc<XY>& Y, vc<S> wt = vc<S>()) {\r\n    if (len(wt) == 0) wt = vc<S>(len(X),\
    \ Monoid::unit());\r\n    assert(Monoid::commute); // \u53EF\u63DB\u30E2\u30CE\
    \u30A4\u30C9\u306E\u307F\r\n    assert(len(X) == len(Y) && len(X) == len(wt));\r\
    \n\r\n    if (!SMALL) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\n      N =\
    \ len(keyX);\r\n    } else {\r\n      min_X = (len(X) == 0 ? 0 : MIN(X));\r\n\
    \      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;\r\n      keyX.resize(N);\r\n\
    \      FOR(i, N) keyX[i] = min_X + i;\r\n    }\r\n\r\n    vc<vc<XY>> keyY_raw(N\
    \ + N);\r\n    vc<vc<S>> dat_raw(N + N);\r\n\r\n    auto I = argsort(Y);\r\n \
    \   for (auto&& i: I) {\r\n      int ix = xtoi(X[i]), y = Y[i];\r\n      ix +=\
    \ N;\r\n      while (ix) {\r\n        auto& KY = keyY_raw[ix];\r\n        if (len(KY)\
    \ == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n          dat_raw[ix].eb(wt[i]);\r\
    \n        } else {\r\n          dat_raw[ix].back() = Monoid::op(dat_raw[ix].back(),\
    \ wt[i]);\r\n        }\r\n        ix >>= 1;\r\n      }\r\n    }\r\n\r\n    indptr.assign(N\
    \ + N + 1, 0);\r\n    FOR(i, N + N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\
    \n    int full_N = indptr.back();\r\n    keyY.resize(full_N);\r\n    dat.assign(2\
    \ * full_N, Monoid::unit());\r\n    FOR(i, N + N) {\r\n      int off = 2 * indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\r\n      FOR(j, n) {\r\n        keyY[indptr[i]\
    \ + j] = keyY_raw[i][j];\r\n        dat[off + n + j] = dat_raw[i][j];\r\n    \
    \  }\r\n      FOR3_R(j, 1, n)\r\n      dat[off + j] = Monoid::op(dat[off + 2 *\
    \ j + 0], dat[off + 2 * j + 1]);\r\n    }\r\n  }\r\n\r\n  void multiply_i(int\
    \ i, XY y, S val) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\
    \n    auto it = keyY.begin() + LID;\r\n    int j = lower_bound(it, it + n, y)\
    \ - it;\r\n    assert(keyY[LID + j] == y);\r\n    int off = 2 * LID;\r\n    j\
    \ += n;\r\n\r\n    while (j) {\r\n      dat[off + j] = Monoid::op(dat[off + j],\
    \ val);\r\n      j >>= 1;\r\n    }\r\n  }\r\n\r\n  void multiply(XY x, XY y, S\
    \ val) {\r\n    int i = xtoi(x);\r\n    assert(keyX[i] == x);\r\n    i += N;\r\
    \n    while (i) {\r\n      multiply_i(i, y, val);\r\n      i >>= 1;\r\n    }\r\
    \n  }\r\n\r\n  S prod_i(int i, XY ly, XY ry) {\r\n    int LID = indptr[i], n =\
    \ indptr[i + 1] - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int L\
    \ = lower_bound(it, it + n, ly) - it;\r\n    int R = lower_bound(it, it + n, ry)\
    \ - it;\r\n    int off = 2 * LID;\r\n    L += n;\r\n    R += n;\r\n    S val =\
    \ Monoid::unit();\r\n    while (L < R) {\r\n      if (L & 1) val = Monoid::op(val,\
    \ dat[off + (L++)]);\r\n      if (R & 1) val = Monoid::op(dat[off + (--R)], val);\r\
    \n      L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n\
    \  S prod(XY lx, XY rx, XY ly, XY ry) {\r\n    int L = xtoi(lx);\r\n    int R\
    \ = xtoi(rx);\r\n    L += N;\r\n    R += N;\r\n    S val = Monoid::unit();\r\n\
    \    while (L < R) {\r\n      if (L & 1) val = Monoid::op(val, prod_i(L++, ly,\
    \ ry));\r\n      if (R & 1) val = Monoid::op(prod_i(--R, ly, ry), val);\r\n  \
    \    L >>= 1;\r\n      R >>= 1;\r\n    }\r\n    return val;\r\n  }\r\n\r\n  void\
    \ debug() {\r\n    print(\"keyX\", keyX);\r\n    print(\"indptr\", indptr);\r\n\
    \    print(\"keyY\", keyY);\r\n    print(\"dat\", dat);\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/segtree/segtree_2d.hpp
  requiredBy: []
  timestamp: '2022-12-03 10:20:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/segtree/segtree_2d.hpp
layout: document
redirect_from:
- /library/ds/segtree/segtree_2d.hpp
- /library/ds/segtree/segtree_2d.hpp.html
title: ds/segtree/segtree_2d.hpp
---
