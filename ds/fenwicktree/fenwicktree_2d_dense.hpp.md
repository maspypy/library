---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/2842.test.cpp
    title: test/aoj/2842.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2003.test.cpp
    title: test/yukicoder/2003.test.cpp
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
    \ }\r\n  static constexpr bool commute = true;\r\n};\r\n#line 2 \"ds/fenwicktree/fenwicktree_2d_dense.hpp\"\
    \n\r\ntemplate <typename Monoid>\r\nstruct FenwickTree_2D_Dense {\r\n  using G\
    \ = Monoid;\r\n  using E = typename G::value_type;\r\n  static_assert(G::commute);\r\
    \n  int H, W;\r\n  vc<E> dat;\r\n\r\n  FenwickTree_2D_Dense() {}\r\n  FenwickTree_2D_Dense(int\
    \ H, int W) : H(H), W(W), dat(H * W) {}\r\n\r\n  void add(int x, int y, E val)\
    \ {\r\n    ++x;\r\n    while (x <= H) { add_x(x, y, val), x += x & -x; }\r\n \
    \ }\r\n\r\n  E sum(int lx, int rx, int ly, int ry) { return prod(lx, rx, ly, ry);\
    \ }\r\n  E prod(int lx, int rx, int ly, int ry) {\r\n    E pos = G::unit(), neg\
    \ = G::unit();\r\n    while (lx < rx) { pos = G::op(pos, sum_x(rx, ly, ry)), rx\
    \ -= rx & -rx; }\r\n    while (rx < lx) { neg = G::op(neg, sum_x(lx, ly, ry)),\
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
  code: "#include \"alg/monoid/add.hpp\"\r\n\r\ntemplate <typename Monoid>\r\nstruct\
    \ FenwickTree_2D_Dense {\r\n  using G = Monoid;\r\n  using E = typename G::value_type;\r\
    \n  static_assert(G::commute);\r\n  int H, W;\r\n  vc<E> dat;\r\n\r\n  FenwickTree_2D_Dense()\
    \ {}\r\n  FenwickTree_2D_Dense(int H, int W) : H(H), W(W), dat(H * W) {}\r\n\r\
    \n  void add(int x, int y, E val) {\r\n    ++x;\r\n    while (x <= H) { add_x(x,\
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
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/fenwicktree/fenwicktree_2d_dense.hpp
  requiredBy: []
  timestamp: '2023-03-09 02:49:26+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2003.test.cpp
  - test/aoj/2842.test.cpp
documentation_of: ds/fenwicktree/fenwicktree_2d_dense.hpp
layout: document
redirect_from:
- /library/ds/fenwicktree/fenwicktree_2d_dense.hpp
- /library/ds/fenwicktree/fenwicktree_2d_dense.hpp.html
title: ds/fenwicktree/fenwicktree_2d_dense.hpp
---
