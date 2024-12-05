---
data:
  _extendedDependsOn:
  - icon: ':question:'
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
  - icon: ':heavy_check_mark:'
    path: test/5_atcoder/abc228f.test.cpp
    title: test/5_atcoder/abc228f.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ds/cumsum_2d.hpp\"\n\r\n#line 2 \"alg/monoid/add.hpp\"\n\
    \r\ntemplate <typename E>\r\nstruct Monoid_Add {\r\n  using X = E;\r\n  using\
    \ value_type = X;\r\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\r\n  static constexpr X inverse(const X &x) noexcept { return\
    \ -x; }\r\n  static constexpr X power(const X &x, ll n) noexcept { return X(n)\
    \ * x; }\r\n  static constexpr X unit() { return X(0); }\r\n  static constexpr\
    \ bool commute = true;\r\n};\r\n#line 4 \"ds/cumsum_2d.hpp\"\n\r\ntemplate <typename\
    \ Monoid>\r\nstruct Cumsum_2D {\r\n  using MX = Monoid;\r\n  static_assert(MX::commute);\r\
    \n  using X = typename MX::value_type;\r\n  int H, W;\r\n  vc<X> dat;\r\n\r\n\
    \  Cumsum_2D() {}\r\n  Cumsum_2D(vvc<X> &A) { build(A); }\r\n\r\n  void build(vvc<X>\
    \ &A) {\r\n    H = len(A);\r\n    W = (H == 0 ? 0 : len(A[0]));\r\n    dat.assign(H\
    \ * W, MX::unit());\r\n    FOR(x, H) FOR(y, W) {\r\n      int k = W * x + y;\r\
    \n      dat[k] = (y == 0 ? A[x][y] : MX::op(dat[k - 1], A[x][y]));\r\n    }\r\n\
    \    FOR(i, W, H * W) dat[i] = MX::op(dat[i - W], dat[i]);\r\n  }\r\n\r\n  //\
    \ [x1,x2) x [y1,y2)\r\n  template <bool allow_out_of_range = false>\r\n  X sum(int\
    \ x1, int x2, int y1, int y2) {\r\n    if constexpr (allow_out_of_range) {\r\n\
    \      chmax(x1, 0), chmin(x2, H), chmax(y1, 0), chmin(y2, W);\r\n      if (x1\
    \ >= x2 || y1 >= y2) return MX::unit();\r\n    }\r\n    if (x2 == 0 || y2 == 0)\
    \ return MX::unit();\r\n    assert(0 <= x1 && x1 <= x2 && x2 <= H);\r\n    assert(0\
    \ <= y1 && y1 <= y2 && y2 <= W);\r\n    --x1, --y1, --x2, --y2;\r\n    X a = (x1\
    \ >= 0 && y1 >= 0 ? dat[W * x1 + y1] : MX::unit());\r\n    X b = (x1 >= 0 && y2\
    \ >= 0 ? dat[W * x1 + y2] : MX::unit());\r\n    X c = (x2 >= 0 && y1 >= 0 ? dat[W\
    \ * x2 + y1] : MX::unit());\r\n    X d = (x2 >= 0 && y2 >= 0 ? dat[W * x2 + y2]\
    \ : MX::unit());\r\n    return MX::op(MX::op(a, d), MX::inverse(MX::op(b, c)));\r\
    \n  }\r\n\r\n  X prefix_sum(int x, int y) {\r\n    return (x == 0 || y == 0) ?\
    \ MX::unit() : dat[W * x + y - (W + 1)];\r\n  }\r\n};\r\n"
  code: "#pragma once\r\n\r\n#include \"alg/monoid/add.hpp\"\r\n\r\ntemplate <typename\
    \ Monoid>\r\nstruct Cumsum_2D {\r\n  using MX = Monoid;\r\n  static_assert(MX::commute);\r\
    \n  using X = typename MX::value_type;\r\n  int H, W;\r\n  vc<X> dat;\r\n\r\n\
    \  Cumsum_2D() {}\r\n  Cumsum_2D(vvc<X> &A) { build(A); }\r\n\r\n  void build(vvc<X>\
    \ &A) {\r\n    H = len(A);\r\n    W = (H == 0 ? 0 : len(A[0]));\r\n    dat.assign(H\
    \ * W, MX::unit());\r\n    FOR(x, H) FOR(y, W) {\r\n      int k = W * x + y;\r\
    \n      dat[k] = (y == 0 ? A[x][y] : MX::op(dat[k - 1], A[x][y]));\r\n    }\r\n\
    \    FOR(i, W, H * W) dat[i] = MX::op(dat[i - W], dat[i]);\r\n  }\r\n\r\n  //\
    \ [x1,x2) x [y1,y2)\r\n  template <bool allow_out_of_range = false>\r\n  X sum(int\
    \ x1, int x2, int y1, int y2) {\r\n    if constexpr (allow_out_of_range) {\r\n\
    \      chmax(x1, 0), chmin(x2, H), chmax(y1, 0), chmin(y2, W);\r\n      if (x1\
    \ >= x2 || y1 >= y2) return MX::unit();\r\n    }\r\n    if (x2 == 0 || y2 == 0)\
    \ return MX::unit();\r\n    assert(0 <= x1 && x1 <= x2 && x2 <= H);\r\n    assert(0\
    \ <= y1 && y1 <= y2 && y2 <= W);\r\n    --x1, --y1, --x2, --y2;\r\n    X a = (x1\
    \ >= 0 && y1 >= 0 ? dat[W * x1 + y1] : MX::unit());\r\n    X b = (x1 >= 0 && y2\
    \ >= 0 ? dat[W * x1 + y2] : MX::unit());\r\n    X c = (x2 >= 0 && y1 >= 0 ? dat[W\
    \ * x2 + y1] : MX::unit());\r\n    X d = (x2 >= 0 && y2 >= 0 ? dat[W * x2 + y2]\
    \ : MX::unit());\r\n    return MX::op(MX::op(a, d), MX::inverse(MX::op(b, c)));\r\
    \n  }\r\n\r\n  X prefix_sum(int x, int y) {\r\n    return (x == 0 || y == 0) ?\
    \ MX::unit() : dat[W * x + y - (W + 1)];\r\n  }\r\n};\r\n"
  dependsOn:
  - alg/monoid/add.hpp
  isVerificationFile: false
  path: ds/cumsum_2d.hpp
  requiredBy: []
  timestamp: '2024-01-23 05:58:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/655.test.cpp
  - test/3_yukicoder/1141.test.cpp
  - test/5_atcoder/abc228f.test.cpp
documentation_of: ds/cumsum_2d.hpp
layout: document
redirect_from:
- /library/ds/cumsum_2d.hpp
- /library/ds/cumsum_2d.hpp.html
title: ds/cumsum_2d.hpp
---
