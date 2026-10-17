---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/point_add_rectangle_sum_bit2d.test.cpp
    title: test/2_library_checker/data_structure/point_add_rectangle_sum_bit2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/data_structure/rectangle_sum_bit2d.test.cpp
    title: test/2_library_checker/data_structure/rectangle_sum_bit2d.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1216.test.cpp
    title: test/3_yukicoder/1216.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1216_2.test.cpp
    title: test/3_yukicoder/1216_2.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1919.test.cpp
    title: test/3_yukicoder/1919.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_2d.hpp
  bundledCode: "#line 1 \"ds/fenwicktree/fenwicktree_2d.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_2d.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/fenwicktree/fenwicktree_2d.hpp\"\n\ntemplate <typename Monoid,\
    \ typename XY, bool SMALL_X = false>\nstruct FenwickTree_2D {\n  using G = Monoid;\n\
    \  using E = typename G::value_type;\n  static_assert(G::commute);\n  int N;\n\
    \  vc<XY> keyX;\n  XY min_X;\n  vc<int> indptr;\n  vc<XY> keyY;\n  vc<E> dat;\n\
    \n  FenwickTree_2D(vc<XY>& X, vc<XY>& Y, vc<E> wt) { build(X, Y, wt); }\n  FenwickTree_2D(vc<XY>&\
    \ X, vc<XY>& Y) { build(X, Y); }\n\n  inline int xtoi(XY x) {\n    if constexpr\
    \ (SMALL_X) {\n      return clamp<int>(x - min_X, 0, N);\n    } else {\n     \
    \ return LB(keyX, x);\n    }\n  }\n  inline int nxt(int i) { return i + ((i +\
    \ 1) & -(i + 1)); }\n  inline int prev(int i) { return i - ((i + 1) & -(i + 1));\
    \ }\n\n  void build(vc<XY> X, vc<XY> Y, vc<E> wt) {\n    assert(len(X) == len(Y));\n\
    \    if constexpr (!SMALL_X) {\n      keyX = X;\n      UNIQUE(keyX);\n      N\
    \ = len(keyX);\n    } else {\n      min_X = (len(X) == 0 ? 0 : MIN(X));\n    \
    \  N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;\n      keyX.resize(N);\n      FOR(i,\
    \ N) keyX[i] = min_X + i;\n    }\n\n    auto I = argsort(Y);\n    X = rearrange(X,\
    \ I), Y = rearrange(Y, I), wt = rearrange(wt, I);\n\n    FOR(i, len(X)) X[i] =\
    \ xtoi(X[i]);\n\n    vc<XY> last_y(N, -infty<XY> - 1);\n    indptr.assign(N +\
    \ 1, 0);\n    FOR(i, len(X)) {\n      int ix = X[i];\n      XY y = Y[i];\n   \
    \   while (ix < N) {\n        if (last_y[ix] == y) break;\n        last_y[ix]\
    \ = y, indptr[ix + 1]++, ix = nxt(ix);\n      }\n    }\n    FOR(i, N) indptr[i\
    \ + 1] += indptr[i];\n    keyY.resize(indptr.back());\n    dat.assign(indptr.back(),\
    \ G::id());\n    fill(all(last_y), -infty<XY> - 1);\n    vc<int> prog = indptr;\n\
    \    FOR(i, len(X)) {\n      int ix = X[i];\n      XY y = Y[i];\n      E w = wt[i];\n\
    \      while (ix < N) {\n        if (last_y[ix] != y) {\n          last_y[ix]\
    \ = y, keyY[prog[ix]] = y, dat[prog[ix]] = w;\n          prog[ix]++;\n       \
    \ } else {\n          dat[prog[ix] - 1] = G::op(dat[prog[ix] - 1], w);\n     \
    \   }\n        ix = nxt(ix);\n      }\n    }\n    FOR(i, N) {\n      int n = indptr[i\
    \ + 1] - indptr[i];\n      FOR(j, n - 1) {\n        int k = nxt(j);\n        if\
    \ (k < n)\n          dat[indptr[i] + k] = G::op(dat[indptr[i] + k], dat[indptr[i]\
    \ + j]);\n      }\n    }\n  }\n\n  void build(vc<XY> X, vc<XY> Y) {\n    assert(len(X)\
    \ == len(Y));\n    if constexpr (!SMALL_X) {\n      keyX = X;\n      UNIQUE(keyX);\n\
    \      N = len(keyX);\n    } else {\n      min_X = (len(X) == 0 ? 0 : MIN(X));\n\
    \      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;\n      keyX.resize(N);\n  \
    \    FOR(i, N) keyX[i] = min_X + i;\n    }\n\n    auto I = argsort(Y);\n    X\
    \ = rearrange(X, I), Y = rearrange(Y, I);\n\n    FOR(i, len(X)) X[i] = xtoi(X[i]);\n\
    \n    vc<XY> last_y(N, -infty<XY> - 1);\n    indptr.assign(N + 1, 0);\n    FOR(i,\
    \ len(X)) {\n      int ix = X[i];\n      XY y = Y[i];\n      while (ix < N) {\n\
    \        if (last_y[ix] == y) break;\n        last_y[ix] = y, indptr[ix + 1]++,\
    \ ix = nxt(ix);\n      }\n    }\n    FOR(i, N) indptr[i + 1] += indptr[i];\n \
    \   keyY.resize(indptr.back());\n    dat.assign(indptr.back(), G::id());\n   \
    \ fill(all(last_y), -infty<XY> - 1);\n    vc<int> prog = indptr;\n    FOR(i, len(X))\
    \ {\n      int ix = X[i];\n      XY y = Y[i];\n      while (ix < N) {\n      \
    \  if (last_y[ix] == y) break;\n        last_y[ix] = y, keyY[prog[ix]++] = y,\
    \ ix = nxt(ix);\n      }\n    }\n  }\n\n  void add(XY x, XY y, E val) { multiply(x,\
    \ y, val); }\n  void multiply(XY x, XY y, E val) {\n    int i = xtoi(x);\n   \
    \ assert(keyX[i] == x);\n    while (i < N) { multiply_i(i, y, val), i = nxt(i);\
    \ }\n  }\n\n  E sum(XY lx, XY rx, XY ly, XY ry) { return prod(lx, rx, ly, ry);\
    \ }\n  E prod(XY lx, XY rx, XY ly, XY ry) {\n    E pos = G::id(), neg = G::id();\n\
    \    int L = xtoi(lx) - 1, R = xtoi(rx) - 1;\n    while (L < R) { pos = G::op(pos,\
    \ prod_i(R, ly, ry)), R = prev(R); }\n    while (R < L) { neg = G::op(neg, prod_i(L,\
    \ ly, ry)), L = prev(L); }\n    return G::op(pos, G::inverse(neg));\n  }\n\n \
    \ E prefix_sum(XY rx, XY ry) { return prefix_prod(rx, ry); }\n  E prefix_prod(XY\
    \ rx, XY ry) {\n    E pos = G::id();\n    int R = xtoi(rx) - 1;\n    while (R\
    \ >= 0) { pos = G::op(pos, prefix_prod_i(R, ry)), R = prev(R); }\n    return pos;\n\
    \  }\n\nprivate:\n  void multiply_i(int i, XY y, E val) {\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin() + LID;\n    int j\
    \ = lower_bound(it, it + n, y) - it;\n    while (j < n) { dat[LID + j] = G::op(dat[LID\
    \ + j], val), j = nxt(j); }\n  }\n\n  E prod_i(int i, XY ly, XY ry) {\n    E pos\
    \ = G::id(), neg = G::id();\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \    auto it = keyY.begin() + LID;\n    int L = lower_bound(it, it + n, ly) -\
    \ it - 1;\n    int R = lower_bound(it, it + n, ry) - it - 1;\n    while (L < R)\
    \ { pos = G::op(pos, dat[LID + R]), R = prev(R); }\n    while (R < L) { neg =\
    \ G::op(neg, dat[LID + L]), L = prev(L); }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n\n  E prefix_prod_i(int i, XY ry) {\n    E pos = G::id();\n    int LID =\
    \ indptr[i], n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin() + LID;\n\
    \    int R = lower_bound(it, it + n, ry) - it - 1;\n    while (R >= 0) { pos =\
    \ G::op(pos, dat[LID + R]), R = prev(R); }\n    return pos;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_2d.hpp\n\
    #include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid, typename XY, bool\
    \ SMALL_X = false>\nstruct FenwickTree_2D {\n  using G = Monoid;\n  using E =\
    \ typename G::value_type;\n  static_assert(G::commute);\n  int N;\n  vc<XY> keyX;\n\
    \  XY min_X;\n  vc<int> indptr;\n  vc<XY> keyY;\n  vc<E> dat;\n\n  FenwickTree_2D(vc<XY>&\
    \ X, vc<XY>& Y, vc<E> wt) { build(X, Y, wt); }\n  FenwickTree_2D(vc<XY>& X, vc<XY>&\
    \ Y) { build(X, Y); }\n\n  inline int xtoi(XY x) {\n    if constexpr (SMALL_X)\
    \ {\n      return clamp<int>(x - min_X, 0, N);\n    } else {\n      return LB(keyX,\
    \ x);\n    }\n  }\n  inline int nxt(int i) { return i + ((i + 1) & -(i + 1));\
    \ }\n  inline int prev(int i) { return i - ((i + 1) & -(i + 1)); }\n\n  void build(vc<XY>\
    \ X, vc<XY> Y, vc<E> wt) {\n    assert(len(X) == len(Y));\n    if constexpr (!SMALL_X)\
    \ {\n      keyX = X;\n      UNIQUE(keyX);\n      N = len(keyX);\n    } else {\n\
    \      min_X = (len(X) == 0 ? 0 : MIN(X));\n      N = (len(X) == 0 ? 0 : MAX(X))\
    \ - min_X + 1;\n      keyX.resize(N);\n      FOR(i, N) keyX[i] = min_X + i;\n\
    \    }\n\n    auto I = argsort(Y);\n    X = rearrange(X, I), Y = rearrange(Y,\
    \ I), wt = rearrange(wt, I);\n\n    FOR(i, len(X)) X[i] = xtoi(X[i]);\n\n    vc<XY>\
    \ last_y(N, -infty<XY> - 1);\n    indptr.assign(N + 1, 0);\n    FOR(i, len(X))\
    \ {\n      int ix = X[i];\n      XY y = Y[i];\n      while (ix < N) {\n      \
    \  if (last_y[ix] == y) break;\n        last_y[ix] = y, indptr[ix + 1]++, ix =\
    \ nxt(ix);\n      }\n    }\n    FOR(i, N) indptr[i + 1] += indptr[i];\n    keyY.resize(indptr.back());\n\
    \    dat.assign(indptr.back(), G::id());\n    fill(all(last_y), -infty<XY> - 1);\n\
    \    vc<int> prog = indptr;\n    FOR(i, len(X)) {\n      int ix = X[i];\n    \
    \  XY y = Y[i];\n      E w = wt[i];\n      while (ix < N) {\n        if (last_y[ix]\
    \ != y) {\n          last_y[ix] = y, keyY[prog[ix]] = y, dat[prog[ix]] = w;\n\
    \          prog[ix]++;\n        } else {\n          dat[prog[ix] - 1] = G::op(dat[prog[ix]\
    \ - 1], w);\n        }\n        ix = nxt(ix);\n      }\n    }\n    FOR(i, N) {\n\
    \      int n = indptr[i + 1] - indptr[i];\n      FOR(j, n - 1) {\n        int\
    \ k = nxt(j);\n        if (k < n)\n          dat[indptr[i] + k] = G::op(dat[indptr[i]\
    \ + k], dat[indptr[i] + j]);\n      }\n    }\n  }\n\n  void build(vc<XY> X, vc<XY>\
    \ Y) {\n    assert(len(X) == len(Y));\n    if constexpr (!SMALL_X) {\n      keyX\
    \ = X;\n      UNIQUE(keyX);\n      N = len(keyX);\n    } else {\n      min_X =\
    \ (len(X) == 0 ? 0 : MIN(X));\n      N = (len(X) == 0 ? 0 : MAX(X)) - min_X +\
    \ 1;\n      keyX.resize(N);\n      FOR(i, N) keyX[i] = min_X + i;\n    }\n\n \
    \   auto I = argsort(Y);\n    X = rearrange(X, I), Y = rearrange(Y, I);\n\n  \
    \  FOR(i, len(X)) X[i] = xtoi(X[i]);\n\n    vc<XY> last_y(N, -infty<XY> - 1);\n\
    \    indptr.assign(N + 1, 0);\n    FOR(i, len(X)) {\n      int ix = X[i];\n  \
    \    XY y = Y[i];\n      while (ix < N) {\n        if (last_y[ix] == y) break;\n\
    \        last_y[ix] = y, indptr[ix + 1]++, ix = nxt(ix);\n      }\n    }\n   \
    \ FOR(i, N) indptr[i + 1] += indptr[i];\n    keyY.resize(indptr.back());\n   \
    \ dat.assign(indptr.back(), G::id());\n    fill(all(last_y), -infty<XY> - 1);\n\
    \    vc<int> prog = indptr;\n    FOR(i, len(X)) {\n      int ix = X[i];\n    \
    \  XY y = Y[i];\n      while (ix < N) {\n        if (last_y[ix] == y) break;\n\
    \        last_y[ix] = y, keyY[prog[ix]++] = y, ix = nxt(ix);\n      }\n    }\n\
    \  }\n\n  void add(XY x, XY y, E val) { multiply(x, y, val); }\n  void multiply(XY\
    \ x, XY y, E val) {\n    int i = xtoi(x);\n    assert(keyX[i] == x);\n    while\
    \ (i < N) { multiply_i(i, y, val), i = nxt(i); }\n  }\n\n  E sum(XY lx, XY rx,\
    \ XY ly, XY ry) { return prod(lx, rx, ly, ry); }\n  E prod(XY lx, XY rx, XY ly,\
    \ XY ry) {\n    E pos = G::id(), neg = G::id();\n    int L = xtoi(lx) - 1, R =\
    \ xtoi(rx) - 1;\n    while (L < R) { pos = G::op(pos, prod_i(R, ly, ry)), R =\
    \ prev(R); }\n    while (R < L) { neg = G::op(neg, prod_i(L, ly, ry)), L = prev(L);\
    \ }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  E prefix_sum(XY rx, XY\
    \ ry) { return prefix_prod(rx, ry); }\n  E prefix_prod(XY rx, XY ry) {\n    E\
    \ pos = G::id();\n    int R = xtoi(rx) - 1;\n    while (R >= 0) { pos = G::op(pos,\
    \ prefix_prod_i(R, ry)), R = prev(R); }\n    return pos;\n  }\n\nprivate:\n  void\
    \ multiply_i(int i, XY y, E val) {\n    int LID = indptr[i], n = indptr[i + 1]\
    \ - indptr[i];\n    auto it = keyY.begin() + LID;\n    int j = lower_bound(it,\
    \ it + n, y) - it;\n    while (j < n) { dat[LID + j] = G::op(dat[LID + j], val),\
    \ j = nxt(j); }\n  }\n\n  E prod_i(int i, XY ly, XY ry) {\n    E pos = G::id(),\
    \ neg = G::id();\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n  \
    \  auto it = keyY.begin() + LID;\n    int L = lower_bound(it, it + n, ly) - it\
    \ - 1;\n    int R = lower_bound(it, it + n, ry) - it - 1;\n    while (L < R) {\
    \ pos = G::op(pos, dat[LID + R]), R = prev(R); }\n    while (R < L) { neg = G::op(neg,\
    \ dat[LID + L]), L = prev(L); }\n    return G::op(pos, G::inverse(neg));\n  }\n\
    \n  E prefix_prod_i(int i, XY ry) {\n    E pos = G::id();\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin() + LID;\n    int R\
    \ = lower_bound(it, it + n, ry) - it - 1;\n    while (R >= 0) { pos = G::op(pos,\
    \ dat[LID + R]), R = prev(R); }\n    return pos;\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/fenwicktree_2d.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1216_2.test.cpp
  - test/3_yukicoder/1919.test.cpp
  - test/3_yukicoder/1216.test.cpp
  - test/2_library_checker/data_structure/point_add_rectangle_sum_bit2d.test.cpp
  - test/2_library_checker/data_structure/rectangle_sum_bit2d.test.cpp
documentation_of: ds/fenwicktree/fenwicktree_2d.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/fenwicktree_2d.hpp
- /library/ds/fenwicktree/fenwicktree_2d.hpp.html
title: ds/fenwicktree/fenwicktree_2d.hpp
---
