---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
    links: []
  bundledCode: "#line 2 \"alg/monoid/add.hpp\"\n\r\ntemplate <typename E>\r\nstruct\
    \ Monoid_Add {\r\n  using X = E;\r\n  using value_type = X;\r\n  static constexpr\
    \ X op(const X &x, const X &y) noexcept { return x + y; }\r\n  static constexpr\
    \ X inverse(const X &x) noexcept { return -x; }\r\n  static constexpr X power(const\
    \ X &x, ll n) noexcept { return X(n) * x; }\r\n  static constexpr X unit() { return\
    \ X(0); }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/fenwicktree/fenwicktree_2d_dense.hpp\"\
    \n\r\ntemplate <typename Monoid>\r\nstruct FenwickTree_2D_Dense {\r\n  using G\
    \ = Monoid;\r\n  using E = typename G::value_type;\r\n  static_assert(G::commute);\r\
    \n  int H, W;\r\n  vc<E> dat;\r\n\r\n  FenwickTree_2D_Dense() {}\r\n  FenwickTree_2D_Dense(int\
    \ H, int W) : H(H), W(W), dat(H * W, G::unit()) {}\r\n  FenwickTree_2D_Dense(int\
    \ H, int W, vvc<E>& dat_raw) : H(H), W(W) {\r\n    build(H, W, [&](int x, int\
    \ y) -> E { return dat_raw[x][y]; });\r\n  }\r\n  template <typename F>\r\n  FenwickTree_2D_Dense(int\
    \ H, int W, F f) : H(H), W(W) {\r\n    build(H, W, f);\r\n  }\r\n\r\n  template\
    \ <typename F>\r\n  void build(int H0, int W0, F f) {\r\n    H = H0, W = W0;\r\
    \n    dat.assign(H * W, 0);\r\n    FOR(x, H) FOR(y, W) { dat[W * x + y] = f(x,\
    \ y); }\r\n    FOR(x, 1, H + 1) {\r\n      FOR(y, 1, W + 1) {\r\n        int ny\
    \ = y + (y & -y);\r\n        if (ny <= W) dat[idx(x, ny)] = G::op(dat[idx(x, ny)],\
    \ dat[idx(x, y)]);\r\n      }\r\n    }\r\n    FOR(x, 1, H + 1) {\r\n      FOR(y,\
    \ 1, W + 1) {\r\n        int nx = x + (x & -x);\r\n        if (nx <= H) dat[idx(nx,\
    \ y)] = G::op(dat[idx(nx, y)], dat[idx(x, y)]);\r\n      }\r\n    }\r\n  }\r\n\
    \r\n  void add(int x, int y, E val) {\r\n    ++x;\r\n    while (x <= H) { add_x(x,\
    \ y, val), x += x & -x; }\r\n  }\r\n\r\n  E sum(int lx, int rx, int ly, int ry)\
    \ { return prod(lx, rx, ly, ry); }\r\n  E prod(int lx, int rx, int ly, int ry)\
    \ {\r\n    E pos = G::unit(), neg = G::unit();\r\n    while (lx < rx) { pos =\
    \ G::op(pos, sum_x(rx, ly, ry)), rx -= rx & -rx; }\r\n    while (rx < lx) { neg\
    \ = G::op(neg, sum_x(lx, ly, ry)), lx -= lx & -lx; }\r\n    return G::op(pos,\
    \ G::inverse(neg));\r\n  }\r\n\r\n  E prefix_prod(int rx, int ry) { return prod(0,\
    \ rx, 0, ry); }\r\n  E prefix_sum(int rx, int ry) {\r\n    E pos = G::unit();\r\
    \n    while (rx) { pos = G::op(pos, prefix_sum_x(rx, ry)), rx -= rx & -rx; }\r\
    \n    return pos;\r\n  }\r\n\r\nprivate:\r\n  inline int idx(int x, int y) { return\
    \ W * (x - 1) + (y - 1); }\r\n\r\n  void add_x(int x, int y, E val) {\r\n    ++y;\r\
    \n    while (y <= W) { dat[idx(x, y)] = G::op(dat[idx(x, y)], val), y += y & -y;\
    \ }\r\n  }\r\n  E sum_x(int x, int ly, int ry) {\r\n    E pos = G::unit(), neg\
    \ = G::unit();\r\n    while (ly < ry) { pos = G::op(pos, dat[idx(x, ry)]), ry\
    \ -= ry & -ry; }\r\n    while (ry < ly) { neg = G::op(neg, dat[idx(x, ly)]), ly\
    \ -= ly & -ly; }\r\n    return G::op(pos, G::inverse(neg));\r\n  }\r\n  E prefix_sum_x(int\
    \ x, int ry) {\r\n    E pos = G::unit();\r\n    while (ry) { pos = G::op(pos,\
    \ dat[idx(x, ry)]), ry -= ry & -ry; }\r\n    return pos;\r\n  }\r\n};\r\n"
  code: "#include \"alg/monoid/add.hpp\"\r\n\r\ntemplate <typename Monoid>\r\nstruct\
    \ FenwickTree_2D_Dense {\r\n  using G = Monoid;\r\n  using E = typename G::value_type;\r\
    \n  static_assert(G::commute);\r\n  int H, W;\r\n  vc<E> dat;\r\n\r\n  FenwickTree_2D_Dense()\
    \ {}\r\n  FenwickTree_2D_Dense(int H, int W) : H(H), W(W), dat(H * W, G::unit())\
    \ {}\r\n  FenwickTree_2D_Dense(int H, int W, vvc<E>& dat_raw) : H(H), W(W) {\r\
    \n    build(H, W, [&](int x, int y) -> E { return dat_raw[x][y]; });\r\n  }\r\n\
    \  template <typename F>\r\n  FenwickTree_2D_Dense(int H, int W, F f) : H(H),\
    \ W(W) {\r\n    build(H, W, f);\r\n  }\r\n\r\n  template <typename F>\r\n  void\
    \ build(int H0, int W0, F f) {\r\n    H = H0, W = W0;\r\n    dat.assign(H * W,\
    \ 0);\r\n    FOR(x, H) FOR(y, W) { dat[W * x + y] = f(x, y); }\r\n    FOR(x, 1,\
    \ H + 1) {\r\n      FOR(y, 1, W + 1) {\r\n        int ny = y + (y & -y);\r\n \
    \       if (ny <= W) dat[idx(x, ny)] = G::op(dat[idx(x, ny)], dat[idx(x, y)]);\r\
    \n      }\r\n    }\r\n    FOR(x, 1, H + 1) {\r\n      FOR(y, 1, W + 1) {\r\n \
    \       int nx = x + (x & -x);\r\n        if (nx <= H) dat[idx(nx, y)] = G::op(dat[idx(nx,\
    \ y)], dat[idx(x, y)]);\r\n      }\r\n    }\r\n  }\r\n\r\n  void add(int x, int\
    \ y, E val) {\r\n    ++x;\r\n    while (x <= H) { add_x(x, y, val), x += x & -x;\
    \ }\r\n  }\r\n\r\n  E sum(int lx, int rx, int ly, int ry) { return prod(lx, rx,\
    \ ly, ry); }\r\n  E prod(int lx, int rx, int ly, int ry) {\r\n    E pos = G::unit(),\
    \ neg = G::unit();\r\n    while (lx < rx) { pos = G::op(pos, sum_x(rx, ly, ry)),\
    \ rx -= rx & -rx; }\r\n    while (rx < lx) { neg = G::op(neg, sum_x(lx, ly, ry)),\
    \ lx -= lx & -lx; }\r\n    return G::op(pos, G::inverse(neg));\r\n  }\r\n\r\n\
    \  E prefix_prod(int rx, int ry) { return prod(0, rx, 0, ry); }\r\n  E prefix_sum(int\
    \ rx, int ry) {\r\n    E pos = G::unit();\r\n    while (rx) { pos = G::op(pos,\
    \ prefix_sum_x(rx, ry)), rx -= rx & -rx; }\r\n    return pos;\r\n  }\r\n\r\nprivate:\r\
    \n  inline int idx(int x, int y) { return W * (x - 1) + (y - 1); }\r\n\r\n  void\
    \ add_x(int x, int y, E val) {\r\n    ++y;\r\n    while (y <= W) { dat[idx(x,\
    \ y)] = G::op(dat[idx(x, y)], val), y += y & -y; }\r\n  }\r\n  E sum_x(int x,\
    \ int ly, int ry) {\r\n    E pos = G::unit(), neg = G::unit();\r\n    while (ly\
    \ < ry) { pos = G::op(pos, dat[idx(x, ry)]), ry -= ry & -ry; }\r\n    while (ry\
    \ < ly) { neg = G::op(neg, dat[idx(x, ly)]), ly -= ly & -ly; }\r\n    return G::op(pos,\
    \ G::inverse(neg));\r\n  }\r\n  E prefix_sum_x(int x, int ry) {\r\n    E pos =\
    \ G::unit();\r\n    while (ry) { pos = G::op(pos, dat[idx(x, ry)]), ry -= ry &\
    \ -ry; }\r\n    return pos;\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/fenwicktree_2d_dense.hpp
  requiredBy: []
  timestamp: '2024-01-23 05:58:02+09:00'
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
