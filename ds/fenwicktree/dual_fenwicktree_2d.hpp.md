---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename X>\r\nstruct\
    \ Monoid_Add {\r\n  using value_type = X;\r\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\r\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\r\n  static constexpr X power(const X &x, ll n)\
    \ noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return X(0);\
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/fenwicktree/dual_fenwicktree_2d.hpp\"\
    \n\ntemplate <typename Monoid, typename XY, bool SMALL_X = false>\nstruct Dual_FenwickTree_2D\
    \ {\n  using G = Monoid;\n  using E = typename G::value_type;\n  static_assert(G::commute);\n\
    \  int N;\n  vc<XY> keyX;\n  XY min_X;\n  vc<int> indptr;\n  vc<XY> keyY;\n  vc<E>\
    \ dat;\n\n  Dual_FenwickTree_2D(vc<XY>& X, vc<XY>& Y) { build(X, Y); }\n\n  inline\
    \ int xtoi(XY x) {\n    return (SMALL_X ? clamp<int>(x - min_X, 0, N) : LB(keyX,\
    \ x));\n  }\n  inline int nxt(int i) { return i + ((i + 1) & -(i + 1)); }\n  inline\
    \ int prev(int i) { return i - ((i + 1) & -(i + 1)); }\n\n  void build(vc<XY>&\
    \ X, vc<XY>& Y) {\n    assert(len(X) == len(Y));\n    if (!SMALL_X) {\n      keyX\
    \ = X;\n      UNIQUE(keyX);\n      N = len(keyX);\n    } else {\n      min_X =\
    \ (len(X) == 0 ? 0 : MIN(X));\n      N = (len(X) == 0 ? 0 : MAX(X)) - min_X +\
    \ 1;\n      keyX.resize(N);\n      FOR(i, N) keyX[i] = min_X + i;\n    }\n   \
    \ vvc<XY> keyY_raw(N);\n    for (auto&& i: argsort(Y)) {\n      int ix = xtoi(X[i]);\n\
    \      XY y = Y[i];\n      while (ix < N) {\n        auto& KY = keyY_raw[ix];\n\
    \        if (len(KY) == 0 || KY.back() < y) { KY.eb(y); }\n        ix = nxt(ix);\n\
    \      }\n    }\n\n    indptr.assign(N + 1, 0);\n    FOR(i, N) indptr[i + 1] =\
    \ indptr[i] + len(keyY_raw[i]);\n    keyY.resize(indptr.back());\n    dat.assign(indptr.back(),\
    \ G::unit());\n    FOR(i, N) FOR(j, indptr[i + 1] - indptr[i]) {\n      keyY[indptr[i]\
    \ + j] = keyY_raw[i][j];\n    }\n  }\n\n  E get(XY x, XY y) {\n    E val = G::unit();\n\
    \    int i = xtoi(x);\n    assert(keyX[i] == x);\n    while (i < N) { val = G::op(val,\
    \ get_i(i, y)), i = nxt(i); }\n    return val;\n  }\n\n  void apply(XY lx, XY\
    \ rx, XY ly, XY ry, E val) {\n    int L = xtoi(lx) - 1, R = xtoi(rx) - 1;\n  \
    \  E neg = G::inverse(val);\n    while (L < R) { apply_i(R, ly, ry, val), R =\
    \ prev(R); }\n    while (R < L) { apply_i(L, ly, ry, neg), L = prev(L); }\n  }\n\
    \nprivate:\n  E get_i(int i, XY y) {\n    E val = G::unit();\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin() + LID;\n    int j\
    \ = lower_bound(it, it + n, y) - it;\n    vc<int> Y_sub = {it, it + n};\n    while\
    \ (j < n) { val = G::op(val, dat[LID + j]), j = nxt(j); }\n    return val;\n \
    \ }\n\n  void apply_i(int i, XY ly, XY ry, E val) {\n    E neg = G::inverse(val);\n\
    \    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin()\
    \ + LID;\n    int L = lower_bound(it, it + n, ly) - it - 1;\n    int R = lower_bound(it,\
    \ it + n, ry) - it - 1;\n    while (L < R) { dat[LID + R] = G::op(val, dat[LID\
    \ + R]), R = prev(R); }\n    while (R < L) { dat[LID + L] = G::op(neg, dat[LID\
    \ + L]), L = prev(L); }\n  }\n};\n"
  code: "#include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid, typename XY,\
    \ bool SMALL_X = false>\nstruct Dual_FenwickTree_2D {\n  using G = Monoid;\n \
    \ using E = typename G::value_type;\n  static_assert(G::commute);\n  int N;\n\
    \  vc<XY> keyX;\n  XY min_X;\n  vc<int> indptr;\n  vc<XY> keyY;\n  vc<E> dat;\n\
    \n  Dual_FenwickTree_2D(vc<XY>& X, vc<XY>& Y) { build(X, Y); }\n\n  inline int\
    \ xtoi(XY x) {\n    return (SMALL_X ? clamp<int>(x - min_X, 0, N) : LB(keyX, x));\n\
    \  }\n  inline int nxt(int i) { return i + ((i + 1) & -(i + 1)); }\n  inline int\
    \ prev(int i) { return i - ((i + 1) & -(i + 1)); }\n\n  void build(vc<XY>& X,\
    \ vc<XY>& Y) {\n    assert(len(X) == len(Y));\n    if (!SMALL_X) {\n      keyX\
    \ = X;\n      UNIQUE(keyX);\n      N = len(keyX);\n    } else {\n      min_X =\
    \ (len(X) == 0 ? 0 : MIN(X));\n      N = (len(X) == 0 ? 0 : MAX(X)) - min_X +\
    \ 1;\n      keyX.resize(N);\n      FOR(i, N) keyX[i] = min_X + i;\n    }\n   \
    \ vvc<XY> keyY_raw(N);\n    for (auto&& i: argsort(Y)) {\n      int ix = xtoi(X[i]);\n\
    \      XY y = Y[i];\n      while (ix < N) {\n        auto& KY = keyY_raw[ix];\n\
    \        if (len(KY) == 0 || KY.back() < y) { KY.eb(y); }\n        ix = nxt(ix);\n\
    \      }\n    }\n\n    indptr.assign(N + 1, 0);\n    FOR(i, N) indptr[i + 1] =\
    \ indptr[i] + len(keyY_raw[i]);\n    keyY.resize(indptr.back());\n    dat.assign(indptr.back(),\
    \ G::unit());\n    FOR(i, N) FOR(j, indptr[i + 1] - indptr[i]) {\n      keyY[indptr[i]\
    \ + j] = keyY_raw[i][j];\n    }\n  }\n\n  E get(XY x, XY y) {\n    E val = G::unit();\n\
    \    int i = xtoi(x);\n    assert(keyX[i] == x);\n    while (i < N) { val = G::op(val,\
    \ get_i(i, y)), i = nxt(i); }\n    return val;\n  }\n\n  void apply(XY lx, XY\
    \ rx, XY ly, XY ry, E val) {\n    int L = xtoi(lx) - 1, R = xtoi(rx) - 1;\n  \
    \  E neg = G::inverse(val);\n    while (L < R) { apply_i(R, ly, ry, val), R =\
    \ prev(R); }\n    while (R < L) { apply_i(L, ly, ry, neg), L = prev(L); }\n  }\n\
    \nprivate:\n  E get_i(int i, XY y) {\n    E val = G::unit();\n    int LID = indptr[i],\
    \ n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin() + LID;\n    int j\
    \ = lower_bound(it, it + n, y) - it;\n    vc<int> Y_sub = {it, it + n};\n    while\
    \ (j < n) { val = G::op(val, dat[LID + j]), j = nxt(j); }\n    return val;\n \
    \ }\n\n  void apply_i(int i, XY ly, XY ry, E val) {\n    E neg = G::inverse(val);\n\
    \    int LID = indptr[i], n = indptr[i + 1] - indptr[i];\n    auto it = keyY.begin()\
    \ + LID;\n    int L = lower_bound(it, it + n, ly) - it - 1;\n    int R = lower_bound(it,\
    \ it + n, ry) - it - 1;\n    while (L < R) { dat[LID + R] = G::op(val, dat[LID\
    \ + R]), R = prev(R); }\n    while (R < L) { dat[LID + L] = G::op(neg, dat[LID\
    \ + L]), L = prev(L); }\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/dual_fenwicktree_2d.hpp
  requiredBy: []
  timestamp: '2023-12-22 20:53:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwicktree/dual_fenwicktree_2d.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/dual_fenwicktree_2d.hpp
- /library/ds/fenwicktree/dual_fenwicktree_2d.hpp.html
title: ds/fenwicktree/dual_fenwicktree_2d.hpp
---
