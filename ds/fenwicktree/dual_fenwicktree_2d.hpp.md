---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/datastructure/rect_add_pt_get.test.cpp
    title: test/library_checker/datastructure/rect_add_pt_get.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/fenwicktree/dual_fenwicktree_2d.hpp\"\
    \n\ntemplate <typename Monoid, typename XY, bool SMALL_X = false>\nstruct Dual_FenwickTree_2D\
    \ {\n  using G = Monoid;\n  using E = typename G::value_type;\n  static_assert(G::commute);\n\
    \  int N;\n  vc<XY> keyX;\n  XY min_X;\n  vc<int> indptr;\n  vc<XY> keyY;\n  vc<E>\
    \ dat;\n\n  Dual_FenwickTree_2D(vc<XY>& X, vc<XY>& Y) { build(X, Y); }\n\n  inline\
    \ int xtoi(XY x) {\n    if constexpr (SMALL_X) {\n      return clamp<int>(x -\
    \ min_X, 0, N);\n    } else {\n      return LB(keyX, x);\n    }\n  }\n  inline\
    \ int nxt(int i) { return i + ((i + 1) & -(i + 1)); }\n  inline int prev(int i)\
    \ { return i - ((i + 1) & -(i + 1)); }\n\n  void build(vc<XY> X, vc<XY> Y) {\n\
    \    assert(len(X) == len(Y));\n    if constexpr (!SMALL_X) {\n      keyX = X;\n\
    \      UNIQUE(keyX);\n      N = len(keyX);\n    } else {\n      min_X = (len(X)\
    \ == 0 ? 0 : MIN(X));\n      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;\n   \
    \   keyX.resize(N);\n      FOR(i, N) keyX[i] = min_X + i;\n    }\n\n    auto I\
    \ = argsort(Y);\n    X = rearrange(X, I), Y = rearrange(Y, I);\n\n    FOR(i, len(X))\
    \ X[i] = xtoi(X[i]);\n\n    vc<XY> last_y(N, -infty<XY> - 1);\n    indptr.assign(N\
    \ + 1, 0);\n    FOR(i, len(X)) {\n      int ix = X[i];\n      XY y = Y[i];\n \
    \     while (ix < N) {\n        if (last_y[ix] == y) break;\n        last_y[ix]\
    \ = y, indptr[ix + 1]++, ix = nxt(ix);\n      }\n    }\n    FOR(i, N) indptr[i\
    \ + 1] += indptr[i];\n    keyY.resize(indptr.back());\n    dat.assign(indptr.back(),\
    \ G::unit());\n    fill(all(last_y), -infty<XY> - 1);\n    vc<int> prog = indptr;\n\
    \    FOR(i, len(X)) {\n      int ix = X[i];\n      XY y = Y[i];\n      while (ix\
    \ < N) {\n        if (last_y[ix] == y) break;\n        last_y[ix] = y, keyY[prog[ix]++]\
    \ = y, ix = nxt(ix);\n      }\n    }\n  }\n\n  E get(XY x, XY y) {\n    E val\
    \ = G::unit();\n    int i = xtoi(x);\n    assert(keyX[i] == x);\n    while (i\
    \ < N) { val = G::op(val, get_i(i, y)), i = nxt(i); }\n    return val;\n  }\n\n\
    \  void apply(XY lx, XY rx, XY ly, XY ry, E val) {\n    int L = xtoi(lx) - 1,\
    \ R = xtoi(rx) - 1;\n    E neg = G::inverse(val);\n    while (L < R) { apply_i(R,\
    \ ly, ry, val), R = prev(R); }\n    while (R < L) { apply_i(L, ly, ry, neg), L\
    \ = prev(L); }\n  }\n\nprivate:\n  E get_i(int i, XY y) {\n    E val = G::unit();\n\
    \    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin()\
    \ + LID;\n    int j = lower_bound(it, it + n, y) - it;\n    vc<int> Y_sub = {it,\
    \ it + n};\n    while (j < n) { val = G::op(val, dat[LID + j]), j = nxt(j); }\n\
    \    return val;\n  }\n\n  void apply_i(int i, XY ly, XY ry, E val) {\n    E neg\
    \ = G::inverse(val);\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \    auto it = keyY.begin() + LID;\n    int L = lower_bound(it, it + n, ly) -\
    \ it - 1;\n    int R = lower_bound(it, it + n, ry) - it - 1;\n    while (L < R)\
    \ { dat[LID + R] = G::op(val, dat[LID + R]), R = prev(R); }\n    while (R < L)\
    \ { dat[LID + L] = G::op(neg, dat[LID + L]), L = prev(L); }\n  }\n};\n"
  code: "#include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid, typename XY,\
    \ bool SMALL_X = false>\nstruct Dual_FenwickTree_2D {\n  using G = Monoid;\n \
    \ using E = typename G::value_type;\n  static_assert(G::commute);\n  int N;\n\
    \  vc<XY> keyX;\n  XY min_X;\n  vc<int> indptr;\n  vc<XY> keyY;\n  vc<E> dat;\n\
    \n  Dual_FenwickTree_2D(vc<XY>& X, vc<XY>& Y) { build(X, Y); }\n\n  inline int\
    \ xtoi(XY x) {\n    if constexpr (SMALL_X) {\n      return clamp<int>(x - min_X,\
    \ 0, N);\n    } else {\n      return LB(keyX, x);\n    }\n  }\n  inline int nxt(int\
    \ i) { return i + ((i + 1) & -(i + 1)); }\n  inline int prev(int i) { return i\
    \ - ((i + 1) & -(i + 1)); }\n\n  void build(vc<XY> X, vc<XY> Y) {\n    assert(len(X)\
    \ == len(Y));\n    if constexpr (!SMALL_X) {\n      keyX = X;\n      UNIQUE(keyX);\n\
    \      N = len(keyX);\n    } else {\n      min_X = (len(X) == 0 ? 0 : MIN(X));\n\
    \      N = (len(X) == 0 ? 0 : MAX(X)) - min_X + 1;\n      keyX.resize(N);\n  \
    \    FOR(i, N) keyX[i] = min_X + i;\n    }\n\n    auto I = argsort(Y);\n    X\
    \ = rearrange(X, I), Y = rearrange(Y, I);\n\n    FOR(i, len(X)) X[i] = xtoi(X[i]);\n\
    \n    vc<XY> last_y(N, -infty<XY> - 1);\n    indptr.assign(N + 1, 0);\n    FOR(i,\
    \ len(X)) {\n      int ix = X[i];\n      XY y = Y[i];\n      while (ix < N) {\n\
    \        if (last_y[ix] == y) break;\n        last_y[ix] = y, indptr[ix + 1]++,\
    \ ix = nxt(ix);\n      }\n    }\n    FOR(i, N) indptr[i + 1] += indptr[i];\n \
    \   keyY.resize(indptr.back());\n    dat.assign(indptr.back(), G::unit());\n \
    \   fill(all(last_y), -infty<XY> - 1);\n    vc<int> prog = indptr;\n    FOR(i,\
    \ len(X)) {\n      int ix = X[i];\n      XY y = Y[i];\n      while (ix < N) {\n\
    \        if (last_y[ix] == y) break;\n        last_y[ix] = y, keyY[prog[ix]++]\
    \ = y, ix = nxt(ix);\n      }\n    }\n  }\n\n  E get(XY x, XY y) {\n    E val\
    \ = G::unit();\n    int i = xtoi(x);\n    assert(keyX[i] == x);\n    while (i\
    \ < N) { val = G::op(val, get_i(i, y)), i = nxt(i); }\n    return val;\n  }\n\n\
    \  void apply(XY lx, XY rx, XY ly, XY ry, E val) {\n    int L = xtoi(lx) - 1,\
    \ R = xtoi(rx) - 1;\n    E neg = G::inverse(val);\n    while (L < R) { apply_i(R,\
    \ ly, ry, val), R = prev(R); }\n    while (R < L) { apply_i(L, ly, ry, neg), L\
    \ = prev(L); }\n  }\n\nprivate:\n  E get_i(int i, XY y) {\n    E val = G::unit();\n\
    \    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin()\
    \ + LID;\n    int j = lower_bound(it, it + n, y) - it;\n    vc<int> Y_sub = {it,\
    \ it + n};\n    while (j < n) { val = G::op(val, dat[LID + j]), j = nxt(j); }\n\
    \    return val;\n  }\n\n  void apply_i(int i, XY ly, XY ry, E val) {\n    E neg\
    \ = G::inverse(val);\n    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n\
    \    auto it = keyY.begin() + LID;\n    int L = lower_bound(it, it + n, ly) -\
    \ it - 1;\n    int R = lower_bound(it, it + n, ry) - it - 1;\n    while (L < R)\
    \ { dat[LID + R] = G::op(val, dat[LID + R]), R = prev(R); }\n    while (R < L)\
    \ { dat[LID + L] = G::op(neg, dat[LID + L]), L = prev(L); }\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/dual_fenwicktree_2d.hpp
  requiredBy: []
  timestamp: '2024-02-04 22:09:44+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/datastructure/rect_add_pt_get.test.cpp
documentation_of: ds/fenwicktree/dual_fenwicktree_2d.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/dual_fenwicktree_2d.hpp
- /library/ds/fenwicktree/dual_fenwicktree_2d.hpp.html
title: ds/fenwicktree/dual_fenwicktree_2d.hpp
---
