---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2003.test.cpp
    title: test/3_yukicoder/2003.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/2842.test.cpp
    title: test/4_aoj/2842.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_2d_dense.hpp
  bundledCode: "#line 1 \"ds/fenwicktree/fenwicktree_2d_dense.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_2d_dense.hpp\n\
    #line 1 \"alg/monoid/add.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/alg/monoid/add.hpp\n\
    \ntemplate <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X id() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/fenwicktree/fenwicktree_2d_dense.hpp\"\n\ntemplate <typename\
    \ Monoid>\nstruct FenwickTree_2D_Dense {\n  using G = Monoid;\n  using E = typename\
    \ G::value_type;\n  static_assert(G::commute);\n  int H, W;\n  vc<E> dat;\n\n\
    \  FenwickTree_2D_Dense() {}\n  FenwickTree_2D_Dense(int H, int W) : H(H), W(W),\
    \ dat(H * W, G::id()) {}\n  FenwickTree_2D_Dense(int H, int W, vvc<E>& dat_raw)\
    \ : H(H), W(W) {\n    build(H, W, [&](int x, int y) -> E { return dat_raw[x][y];\
    \ });\n  }\n  template <typename F>\n  FenwickTree_2D_Dense(int H, int W, F f)\
    \ : H(H), W(W) {\n    build(H, W, f);\n  }\n\n  template <typename F>\n  void\
    \ build(int H0, int W0, F f) {\n    H = H0, W = W0;\n    dat.assign(H * W);\n\
    \    FOR(x, H) FOR(y, W) { dat[W * x + y] = f(x, y); }\n    FOR(x, 1, H + 1) {\n\
    \      FOR(y, 1, W + 1) {\n        int ny = y + (y & -y);\n        if (ny <= W)\
    \ dat[idx(x, ny)] = G::op(dat[idx(x, ny)], dat[idx(x, y)]);\n      }\n    }\n\
    \    FOR(x, 1, H + 1) {\n      FOR(y, 1, W + 1) {\n        int nx = x + (x & -x);\n\
    \        if (nx <= H) dat[idx(nx, y)] = G::op(dat[idx(nx, y)], dat[idx(x, y)]);\n\
    \      }\n    }\n  }\n\n  void add(int x, int y, E val) {\n    ++x;\n    while\
    \ (x <= H) {\n      add_x(x, y, val), x += x & -x;\n    }\n  }\n\n  E sum(int\
    \ lx, int rx, int ly, int ry) { return prod(lx, rx, ly, ry); }\n  E prod(int lx,\
    \ int rx, int ly, int ry) {\n    E pos = G::id(), neg = G::id();\n    while (lx\
    \ < rx) {\n      pos = G::op(pos, sum_x(rx, ly, ry)), rx -= rx & -rx;\n    }\n\
    \    while (rx < lx) {\n      neg = G::op(neg, sum_x(lx, ly, ry)), lx -= lx &\
    \ -lx;\n    }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  E prefix_prod(int\
    \ rx, int ry) { return prod(0, rx, 0, ry); }\n  E prefix_sum(int rx, int ry) {\n\
    \    E pos = G::id();\n    while (rx) {\n      pos = G::op(pos, prefix_sum_x(rx,\
    \ ry)), rx -= rx & -rx;\n    }\n    return pos;\n  }\n\n private:\n  inline int\
    \ idx(int x, int y) { return W * (x - 1) + (y - 1); }\n\n  void add_x(int x, int\
    \ y, E val) {\n    ++y;\n    while (y <= W) {\n      dat[idx(x, y)] = G::op(dat[idx(x,\
    \ y)], val), y += y & -y;\n    }\n  }\n  E sum_x(int x, int ly, int ry) {\n  \
    \  E pos = G::id(), neg = G::id();\n    while (ly < ry) {\n      pos = G::op(pos,\
    \ dat[idx(x, ry)]), ry -= ry & -ry;\n    }\n    while (ry < ly) {\n      neg =\
    \ G::op(neg, dat[idx(x, ly)]), ly -= ly & -ly;\n    }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n  E prefix_sum_x(int x, int ry) {\n    E pos = G::id();\n    while (ry)\
    \ {\n      pos = G::op(pos, dat[idx(x, ry)]), ry -= ry & -ry;\n    }\n    return\
    \ pos;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/ds/fenwicktree/fenwicktree_2d_dense.hpp\n\
    #include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid>\nstruct FenwickTree_2D_Dense\
    \ {\n  using G = Monoid;\n  using E = typename G::value_type;\n  static_assert(G::commute);\n\
    \  int H, W;\n  vc<E> dat;\n\n  FenwickTree_2D_Dense() {}\n  FenwickTree_2D_Dense(int\
    \ H, int W) : H(H), W(W), dat(H * W, G::id()) {}\n  FenwickTree_2D_Dense(int H,\
    \ int W, vvc<E>& dat_raw) : H(H), W(W) {\n    build(H, W, [&](int x, int y) ->\
    \ E { return dat_raw[x][y]; });\n  }\n  template <typename F>\n  FenwickTree_2D_Dense(int\
    \ H, int W, F f) : H(H), W(W) {\n    build(H, W, f);\n  }\n\n  template <typename\
    \ F>\n  void build(int H0, int W0, F f) {\n    H = H0, W = W0;\n    dat.assign(H\
    \ * W);\n    FOR(x, H) FOR(y, W) { dat[W * x + y] = f(x, y); }\n    FOR(x, 1,\
    \ H + 1) {\n      FOR(y, 1, W + 1) {\n        int ny = y + (y & -y);\n       \
    \ if (ny <= W) dat[idx(x, ny)] = G::op(dat[idx(x, ny)], dat[idx(x, y)]);\n   \
    \   }\n    }\n    FOR(x, 1, H + 1) {\n      FOR(y, 1, W + 1) {\n        int nx\
    \ = x + (x & -x);\n        if (nx <= H) dat[idx(nx, y)] = G::op(dat[idx(nx, y)],\
    \ dat[idx(x, y)]);\n      }\n    }\n  }\n\n  void add(int x, int y, E val) {\n\
    \    ++x;\n    while (x <= H) {\n      add_x(x, y, val), x += x & -x;\n    }\n\
    \  }\n\n  E sum(int lx, int rx, int ly, int ry) { return prod(lx, rx, ly, ry);\
    \ }\n  E prod(int lx, int rx, int ly, int ry) {\n    E pos = G::id(), neg = G::id();\n\
    \    while (lx < rx) {\n      pos = G::op(pos, sum_x(rx, ly, ry)), rx -= rx &\
    \ -rx;\n    }\n    while (rx < lx) {\n      neg = G::op(neg, sum_x(lx, ly, ry)),\
    \ lx -= lx & -lx;\n    }\n    return G::op(pos, G::inverse(neg));\n  }\n\n  E\
    \ prefix_prod(int rx, int ry) { return prod(0, rx, 0, ry); }\n  E prefix_sum(int\
    \ rx, int ry) {\n    E pos = G::id();\n    while (rx) {\n      pos = G::op(pos,\
    \ prefix_sum_x(rx, ry)), rx -= rx & -rx;\n    }\n    return pos;\n  }\n\n private:\n\
    \  inline int idx(int x, int y) { return W * (x - 1) + (y - 1); }\n\n  void add_x(int\
    \ x, int y, E val) {\n    ++y;\n    while (y <= W) {\n      dat[idx(x, y)] = G::op(dat[idx(x,\
    \ y)], val), y += y & -y;\n    }\n  }\n  E sum_x(int x, int ly, int ry) {\n  \
    \  E pos = G::id(), neg = G::id();\n    while (ly < ry) {\n      pos = G::op(pos,\
    \ dat[idx(x, ry)]), ry -= ry & -ry;\n    }\n    while (ry < ly) {\n      neg =\
    \ G::op(neg, dat[idx(x, ly)]), ly -= ly & -ly;\n    }\n    return G::op(pos, G::inverse(neg));\n\
    \  }\n  E prefix_sum_x(int x, int ry) {\n    E pos = G::id();\n    while (ry)\
    \ {\n      pos = G::op(pos, dat[idx(x, ry)]), ry -= ry & -ry;\n    }\n    return\
    \ pos;\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/fenwicktree_2d_dense.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2003.test.cpp
  - test/4_aoj/2842.test.cpp
documentation_of: ds/fenwicktree/fenwicktree_2d_dense.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/fenwicktree_2d_dense.hpp
- /library/ds/fenwicktree/fenwicktree_2d_dense.hpp.html
title: ds/fenwicktree/fenwicktree_2d_dense.hpp
---
