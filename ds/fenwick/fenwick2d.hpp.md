---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/atcoder/abc266h_2.test.cpp
    title: test/atcoder/abc266h_2.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
    title: test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - icon: ':x:'
    path: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
    title: test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1216.test.cpp
    title: test/yukicoder/1216.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1216_2.test.cpp
    title: test/yukicoder/1216_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1919.test.cpp
    title: test/yukicoder/1919.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/fenwick/fenwick2d.hpp\"\
    \ntemplate <typename AbelGroup, typename XY, bool SMALL_X = false>\r\nstruct Fenwick2D\
    \ {\r\n  using E = typename AbelGroup::value_type;\r\n  int N;\r\n  vc<XY> keyX;\r\
    \n  XY min_X;\r\n  vc<int> indptr;\r\n  vc<XY> keyY;\r\n  vc<E> dat;\r\n\r\n \
    \ Fenwick2D(vc<XY>& X, vc<XY>& Y, vc<E>& wt) { build(X, Y, wt); }\r\n\r\n  Fenwick2D(vc<XY>&\
    \ X, vc<XY>& Y) {\r\n    vc<E> wt(len(X), AbelGroup::unit());\r\n    build(X,\
    \ Y, wt);\r\n  }\r\n\r\n  void reset_value() { fill(all(dat), AbelGroup::unit());\
    \ }\r\n\r\n  inline int xtoi(XY x) {\r\n    return (SMALL_X ? clamp<int>(x - min_X,\
    \ 0, N) : LB(keyX, x));\r\n  }\r\n\r\n  inline int nxt(int i) {\r\n    i += 1;\r\
    \n    return i + (i & -i) - 1;\r\n  }\r\n\r\n  inline int prev(int i) {\r\n  \
    \  i += 1;\r\n    return i - (i & -i) - 1;\r\n  }\r\n\r\n  void build(vc<XY>&\
    \ X, vc<XY>& Y, vc<E>& wt) {\r\n    if (!SMALL_X) {\r\n      keyX = X;\r\n   \
    \   UNIQUE(keyX);\r\n      N = len(keyX);\r\n    } else {\r\n      min_X = (len(X)\
    \ == 0 ? 0 : MIN(X));\r\n      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;\r\n\
    \      keyX.resize(N);\r\n      FOR(i, N) keyX[i] = min_X + i;\r\n    }\r\n\r\n\
    \    vvc<XY> keyY_raw(N);\r\n    vc<vc<E>> dat_raw(N);\r\n\r\n    auto I = argsort(Y);\r\
    \n    for (auto&& i: I) {\r\n      int ix = xtoi(X[i]);\r\n      ll y = Y[i];\r\
    \n      while (ix < N) {\r\n        auto& KY = keyY_raw[ix];\r\n        if (len(KY)\
    \ == 0 || KY.back() < y) {\r\n          KY.eb(y);\r\n          dat_raw[ix].eb(wt[i]);\r\
    \n        } else {\r\n          dat_raw[ix].back() = AbelGroup::op(dat_raw[ix].back(),\
    \ wt[i]);\r\n        }\r\n        ix = nxt(ix);\r\n      }\r\n    }\r\n\r\n  \
    \  indptr.assign(N + 1, 0);\r\n    FOR(i, N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\
    \n    keyY.resize(indptr.back());\r\n    dat.resize(indptr.back());\r\n    FOR(i,\
    \ N) FOR(j, indptr[i + 1] - indptr[i]) {\r\n      keyY[indptr[i] + j] = keyY_raw[i][j];\r\
    \n      dat[indptr[i] + j] = dat_raw[i][j];\r\n    }\r\n    FOR(i, N) {\r\n  \
    \    int n = indptr[i + 1] - indptr[i];\r\n      FOR(j, n - 1) {\r\n        int\
    \ k = nxt(j);\r\n        if (k < n)\r\n          dat[indptr[i] + k]\r\n      \
    \        = AbelGroup::op(dat[indptr[i] + k], dat[indptr[i] + j]);\r\n      }\r\
    \n    }\r\n  }\r\n\r\n  void multiply(XY x, XY y, E val) {\r\n    int i = xtoi(x);\r\
    \n    assert(keyX[i] == x);\r\n    while (i < N) {\r\n      multiply_i(i, y, val);\r\
    \n      i = nxt(i);\r\n    }\r\n  }\r\n\r\n  void add(XY x, XY y, E val) { multiply(x,\
    \ y, val); }\r\n\r\n  E prod(XY lx, XY rx, XY ly, XY ry) {\r\n    E pos = AbelGroup::unit();\r\
    \n    E neg = AbelGroup::unit();\r\n    int L = xtoi(lx) - 1;\r\n    int R = xtoi(rx)\
    \ - 1;\r\n    while (L < R) {\r\n      pos = AbelGroup::op(pos, prod_i(R, ly,\
    \ ry));\r\n      R = prev(R);\r\n    }\r\n    while (R < L) {\r\n      neg = AbelGroup::op(neg,\
    \ prod_i(L, ly, ry));\r\n      L = prev(L);\r\n    }\r\n    E ret = AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\r\n    return ret;\r\n  }\r\n\r\n  E prefix_prod(XY\
    \ rx, XY ry) {\r\n    E pos = AbelGroup::unit();\r\n    int R = xtoi(rx) - 1;\r\
    \n    while (R >= 0) {\r\n      pos = AbelGroup::op(pos, prefix_prod_i(R, ry));\r\
    \n      R = prev(R);\r\n    }\r\n    return pos;\r\n  }\r\n\r\n  E sum(XY lx,\
    \ XY rx, XY ly, XY ry) { return prod(lx, rx, ly, ry); }\r\n\r\n  E prefix_sum(XY\
    \ rx, XY ry) { return prefix_prod(rx, ry); }\r\n\r\n  void debug() {\r\n    print(\"\
    keyX\", keyX);\r\n    print(\"indptr\", indptr);\r\n    print(\"keyY\", keyY);\r\
    \n    print(\"dat\", dat);\r\n  }\r\n\r\nprivate:\r\n  void multiply_i(int i,\
    \ XY y, E val) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \    auto it = keyY.begin() + LID;\r\n    int j = lower_bound(it, it + n, y) -\
    \ it;\r\n    assert(keyY[LID + j] == y);\r\n    while (j < n) {\r\n      dat[LID\
    \ + j] = AbelGroup::op(dat[LID + j], val);\r\n      j = nxt(j);\r\n    }\r\n \
    \ }\r\n\r\n  E prod_i(int i, XY ly, XY ry) {\r\n    E pos = AbelGroup::unit();\r\
    \n    E neg = AbelGroup::unit();\r\n    int LID = indptr[i], n = indptr[i + 1]\
    \ - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it,\
    \ it + n, ly) - it - 1;\r\n    int R = lower_bound(it, it + n, ry) - it - 1;\r\
    \n    while (L < R) {\r\n      pos = AbelGroup::op(pos, dat[LID + R]);\r\n   \
    \   R = prev(R);\r\n    }\r\n    while (R < L) {\r\n      neg = AbelGroup::op(neg,\
    \ dat[LID + L]);\r\n      L = prev(L);\r\n    }\r\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\r\n  }\r\n\r\n  E prefix_prod_i(int i, XY ry) {\r\n\
    \    E pos = AbelGroup::unit();\r\n    int LID = indptr[i], n = indptr[i + 1]\
    \ - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int R = lower_bound(it,\
    \ it + n, ry) - it - 1;\r\n    while (R >= 0) {\r\n      pos = AbelGroup::op(pos,\
    \ dat[LID + R]);\r\n      R = prev(R);\r\n    }\r\n    return pos;\r\n  }\r\n\
    };\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\ntemplate <typename AbelGroup, typename\
    \ XY, bool SMALL_X = false>\r\nstruct Fenwick2D {\r\n  using E = typename AbelGroup::value_type;\r\
    \n  int N;\r\n  vc<XY> keyX;\r\n  XY min_X;\r\n  vc<int> indptr;\r\n  vc<XY> keyY;\r\
    \n  vc<E> dat;\r\n\r\n  Fenwick2D(vc<XY>& X, vc<XY>& Y, vc<E>& wt) { build(X,\
    \ Y, wt); }\r\n\r\n  Fenwick2D(vc<XY>& X, vc<XY>& Y) {\r\n    vc<E> wt(len(X),\
    \ AbelGroup::unit());\r\n    build(X, Y, wt);\r\n  }\r\n\r\n  void reset_value()\
    \ { fill(all(dat), AbelGroup::unit()); }\r\n\r\n  inline int xtoi(XY x) {\r\n\
    \    return (SMALL_X ? clamp<int>(x - min_X, 0, N) : LB(keyX, x));\r\n  }\r\n\r\
    \n  inline int nxt(int i) {\r\n    i += 1;\r\n    return i + (i & -i) - 1;\r\n\
    \  }\r\n\r\n  inline int prev(int i) {\r\n    i += 1;\r\n    return i - (i & -i)\
    \ - 1;\r\n  }\r\n\r\n  void build(vc<XY>& X, vc<XY>& Y, vc<E>& wt) {\r\n    if\
    \ (!SMALL_X) {\r\n      keyX = X;\r\n      UNIQUE(keyX);\r\n      N = len(keyX);\r\
    \n    } else {\r\n      min_X = (len(X) == 0 ? 0 : MIN(X));\r\n      N = (len(X)\
    \ == 0 ? 0 : MAX(X)) - min_X + 1;\r\n      keyX.resize(N);\r\n      FOR(i, N)\
    \ keyX[i] = min_X + i;\r\n    }\r\n\r\n    vvc<XY> keyY_raw(N);\r\n    vc<vc<E>>\
    \ dat_raw(N);\r\n\r\n    auto I = argsort(Y);\r\n    for (auto&& i: I) {\r\n \
    \     int ix = xtoi(X[i]);\r\n      ll y = Y[i];\r\n      while (ix < N) {\r\n\
    \        auto& KY = keyY_raw[ix];\r\n        if (len(KY) == 0 || KY.back() < y)\
    \ {\r\n          KY.eb(y);\r\n          dat_raw[ix].eb(wt[i]);\r\n        } else\
    \ {\r\n          dat_raw[ix].back() = AbelGroup::op(dat_raw[ix].back(), wt[i]);\r\
    \n        }\r\n        ix = nxt(ix);\r\n      }\r\n    }\r\n\r\n    indptr.assign(N\
    \ + 1, 0);\r\n    FOR(i, N) indptr[i + 1] = indptr[i] + len(keyY_raw[i]);\r\n\
    \    keyY.resize(indptr.back());\r\n    dat.resize(indptr.back());\r\n    FOR(i,\
    \ N) FOR(j, indptr[i + 1] - indptr[i]) {\r\n      keyY[indptr[i] + j] = keyY_raw[i][j];\r\
    \n      dat[indptr[i] + j] = dat_raw[i][j];\r\n    }\r\n    FOR(i, N) {\r\n  \
    \    int n = indptr[i + 1] - indptr[i];\r\n      FOR(j, n - 1) {\r\n        int\
    \ k = nxt(j);\r\n        if (k < n)\r\n          dat[indptr[i] + k]\r\n      \
    \        = AbelGroup::op(dat[indptr[i] + k], dat[indptr[i] + j]);\r\n      }\r\
    \n    }\r\n  }\r\n\r\n  void multiply(XY x, XY y, E val) {\r\n    int i = xtoi(x);\r\
    \n    assert(keyX[i] == x);\r\n    while (i < N) {\r\n      multiply_i(i, y, val);\r\
    \n      i = nxt(i);\r\n    }\r\n  }\r\n\r\n  void add(XY x, XY y, E val) { multiply(x,\
    \ y, val); }\r\n\r\n  E prod(XY lx, XY rx, XY ly, XY ry) {\r\n    E pos = AbelGroup::unit();\r\
    \n    E neg = AbelGroup::unit();\r\n    int L = xtoi(lx) - 1;\r\n    int R = xtoi(rx)\
    \ - 1;\r\n    while (L < R) {\r\n      pos = AbelGroup::op(pos, prod_i(R, ly,\
    \ ry));\r\n      R = prev(R);\r\n    }\r\n    while (R < L) {\r\n      neg = AbelGroup::op(neg,\
    \ prod_i(L, ly, ry));\r\n      L = prev(L);\r\n    }\r\n    E ret = AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\r\n    return ret;\r\n  }\r\n\r\n  E prefix_prod(XY\
    \ rx, XY ry) {\r\n    E pos = AbelGroup::unit();\r\n    int R = xtoi(rx) - 1;\r\
    \n    while (R >= 0) {\r\n      pos = AbelGroup::op(pos, prefix_prod_i(R, ry));\r\
    \n      R = prev(R);\r\n    }\r\n    return pos;\r\n  }\r\n\r\n  E sum(XY lx,\
    \ XY rx, XY ly, XY ry) { return prod(lx, rx, ly, ry); }\r\n\r\n  E prefix_sum(XY\
    \ rx, XY ry) { return prefix_prod(rx, ry); }\r\n\r\n  void debug() {\r\n    print(\"\
    keyX\", keyX);\r\n    print(\"indptr\", indptr);\r\n    print(\"keyY\", keyY);\r\
    \n    print(\"dat\", dat);\r\n  }\r\n\r\nprivate:\r\n  void multiply_i(int i,\
    \ XY y, E val) {\r\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\r\n\
    \    auto it = keyY.begin() + LID;\r\n    int j = lower_bound(it, it + n, y) -\
    \ it;\r\n    assert(keyY[LID + j] == y);\r\n    while (j < n) {\r\n      dat[LID\
    \ + j] = AbelGroup::op(dat[LID + j], val);\r\n      j = nxt(j);\r\n    }\r\n \
    \ }\r\n\r\n  E prod_i(int i, XY ly, XY ry) {\r\n    E pos = AbelGroup::unit();\r\
    \n    E neg = AbelGroup::unit();\r\n    int LID = indptr[i], n = indptr[i + 1]\
    \ - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int L = lower_bound(it,\
    \ it + n, ly) - it - 1;\r\n    int R = lower_bound(it, it + n, ry) - it - 1;\r\
    \n    while (L < R) {\r\n      pos = AbelGroup::op(pos, dat[LID + R]);\r\n   \
    \   R = prev(R);\r\n    }\r\n    while (R < L) {\r\n      neg = AbelGroup::op(neg,\
    \ dat[LID + L]);\r\n      L = prev(L);\r\n    }\r\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\r\n  }\r\n\r\n  E prefix_prod_i(int i, XY ry) {\r\n\
    \    E pos = AbelGroup::unit();\r\n    int LID = indptr[i], n = indptr[i + 1]\
    \ - indptr[i];\r\n    auto it = keyY.begin() + LID;\r\n    int R = lower_bound(it,\
    \ it + n, ry) - it - 1;\r\n    while (R >= 0) {\r\n      pos = AbelGroup::op(pos,\
    \ dat[LID + R]);\r\n      R = prev(R);\r\n    }\r\n    return pos;\r\n  }\r\n\
    };\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwick/fenwick2d.hpp
  requiredBy: []
  timestamp: '2022-12-01 18:20:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1216.test.cpp
  - test/yukicoder/1216_2.test.cpp
  - test/yukicoder/1919.test.cpp
  - test/library_checker/datastructure/rectangle_sum_bit2d.test.cpp
  - test/library_checker/datastructure/point_add_rectangle_sum_bit2d.test.cpp
  - test/atcoder/abc266h_2.test.cpp
documentation_of: ds/fenwick/fenwick2d.hpp
layout: document
redirect_from:
- /library/ds/fenwick/fenwick2d.hpp
- /library/ds/fenwick/fenwick2d.hpp.html
title: ds/fenwick/fenwick2d.hpp
---
