---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: alg/monoid/add.hpp
    title: alg/monoid/add.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1141.test.cpp
    title: test/3_yukicoder/1141.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/655.test.cpp
    title: test/3_yukicoder/655.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/cumsum_2d.hpp\"\n\n#line 1 \"alg/monoid/add.hpp\"\n\n\
    template <typename E>\nstruct Monoid_Add {\n  using X = E;\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static\
    \ constexpr X power(const X &x, ll n) noexcept { return X(n) * x; }\n  static\
    \ constexpr X unit() { return X(0); }\n  static constexpr bool commute = true;\n\
    };\n#line 3 \"ds/cumsum_2d.hpp\"\n\ntemplate <typename Monoid>\nstruct Cumsum_2D\
    \ {\n  using MX = Monoid;\n  static_assert(MX::commute);\n  using X = typename\
    \ MX::value_type;\n  int H, W;\n  vc<X> dat;\n\n  Cumsum_2D() {}\n  Cumsum_2D(vvc<X>\
    \ &A) { build(A); }\n  template <typename F>\n  Cumsum_2D(int H, int W, F f) {\n\
    \    build(H, W, f);\n  }\n\n  void build(vvc<X> &A) {\n    build(len(A), len(A[0]),\
    \ [&](int x, int y) -> X { return A[x][y]; });\n  }\n  template <typename F>\n\
    \  void build(int H0, int W0, F f) {\n    H = H0, W = W0;\n    dat.assign(H *\
    \ W, MX::unit());\n    FOR(x, H) FOR(y, W) {\n      int k = W * x + y;\n     \
    \ dat[k] = (y == 0 ? f(x, y) : MX::op(dat[k - 1], f(x, y)));\n    }\n    FOR(i,\
    \ W, H * W) dat[i] = MX::op(dat[i - W], dat[i]);\n  }\n\n  // [x1,x2) x [y1,y2)\n\
    \  template <bool allow_out_of_range = false>\n  X sum(int x1, int x2, int y1,\
    \ int y2) {\n    if constexpr (allow_out_of_range) {\n      chmax(x1, 0), chmin(x2,\
    \ H), chmax(y1, 0), chmin(y2, W);\n      if (x1 >= x2 || y1 >= y2) return MX::unit();\n\
    \    }\n    if (x2 == 0 || y2 == 0) return MX::unit();\n    assert(0 <= x1 &&\
    \ x1 <= x2 && x2 <= H);\n    assert(0 <= y1 && y1 <= y2 && y2 <= W);\n    --x1,\
    \ --y1, --x2, --y2;\n    X a = (x1 >= 0 && y1 >= 0 ? dat[W * x1 + y1] : MX::unit());\n\
    \    X b = (x1 >= 0 && y2 >= 0 ? dat[W * x1 + y2] : MX::unit());\n    X c = (x2\
    \ >= 0 && y1 >= 0 ? dat[W * x2 + y1] : MX::unit());\n    X d = (x2 >= 0 && y2\
    \ >= 0 ? dat[W * x2 + y2] : MX::unit());\n    return MX::op(MX::op(a, d), MX::inverse(MX::op(b,\
    \ c)));\n  }\n\n  X prefix_sum(int x, int y) {\n    return (x == 0 || y == 0)\
    \ ? MX::unit() : dat[W * x + y - (W + 1)];\n  }\n};\n"
  code: "\n#include \"alg/monoid/add.hpp\"\n\ntemplate <typename Monoid>\nstruct Cumsum_2D\
    \ {\n  using MX = Monoid;\n  static_assert(MX::commute);\n  using X = typename\
    \ MX::value_type;\n  int H, W;\n  vc<X> dat;\n\n  Cumsum_2D() {}\n  Cumsum_2D(vvc<X>\
    \ &A) { build(A); }\n  template <typename F>\n  Cumsum_2D(int H, int W, F f) {\n\
    \    build(H, W, f);\n  }\n\n  void build(vvc<X> &A) {\n    build(len(A), len(A[0]),\
    \ [&](int x, int y) -> X { return A[x][y]; });\n  }\n  template <typename F>\n\
    \  void build(int H0, int W0, F f) {\n    H = H0, W = W0;\n    dat.assign(H *\
    \ W, MX::unit());\n    FOR(x, H) FOR(y, W) {\n      int k = W * x + y;\n     \
    \ dat[k] = (y == 0 ? f(x, y) : MX::op(dat[k - 1], f(x, y)));\n    }\n    FOR(i,\
    \ W, H * W) dat[i] = MX::op(dat[i - W], dat[i]);\n  }\n\n  // [x1,x2) x [y1,y2)\n\
    \  template <bool allow_out_of_range = false>\n  X sum(int x1, int x2, int y1,\
    \ int y2) {\n    if constexpr (allow_out_of_range) {\n      chmax(x1, 0), chmin(x2,\
    \ H), chmax(y1, 0), chmin(y2, W);\n      if (x1 >= x2 || y1 >= y2) return MX::unit();\n\
    \    }\n    if (x2 == 0 || y2 == 0) return MX::unit();\n    assert(0 <= x1 &&\
    \ x1 <= x2 && x2 <= H);\n    assert(0 <= y1 && y1 <= y2 && y2 <= W);\n    --x1,\
    \ --y1, --x2, --y2;\n    X a = (x1 >= 0 && y1 >= 0 ? dat[W * x1 + y1] : MX::unit());\n\
    \    X b = (x1 >= 0 && y2 >= 0 ? dat[W * x1 + y2] : MX::unit());\n    X c = (x2\
    \ >= 0 && y1 >= 0 ? dat[W * x2 + y1] : MX::unit());\n    X d = (x2 >= 0 && y2\
    \ >= 0 ? dat[W * x2 + y2] : MX::unit());\n    return MX::op(MX::op(a, d), MX::inverse(MX::op(b,\
    \ c)));\n  }\n\n  X prefix_sum(int x, int y) {\n    return (x == 0 || y == 0)\
    \ ? MX::unit() : dat[W * x + y - (W + 1)];\n  }\n};\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/cumsum_2d.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/1141.test.cpp
  - test/3_yukicoder/655.test.cpp
documentation_of: ds/cumsum_2d.hpp
layout: document
redirect_from:
- /library/ds/cumsum_2d.hpp
- /library/ds/cumsum_2d.hpp.html
title: ds/cumsum_2d.hpp
---
