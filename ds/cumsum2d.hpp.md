---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1141_cumsum2d.test.cpp
    title: test/yukicoder/1141_cumsum2d.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"ds/cumsum2d.hpp\"\ntemplate <typename Group>\r\nstruct Cumsum2D\
    \ {\r\n  using X = typename Group::value_type;\r\n  int H, W;\r\n  vc<vc<X>> dat;\r\
    \n\r\n  Cumsum2D() {}\r\n  Cumsum2D(vc<vc<X>> &A) {\r\n    assert(Group::commute);\r\
    \n    build(A);\r\n  }\r\n\r\n  void build(vc<vc<X>> &A) {\r\n    int H = len(A);\r\
    \n    int W = (H == 0 ? 0 : len(A[0]));\r\n    dat.assign(H + 1, vc<X>(W + 1,\
    \ Group::unit()));\r\n    FOR(x, H) FOR(y, W) dat[x + 1][y + 1] = A[x][y];\r\n\
    \    FOR(x, H + 1) FOR(y, W) dat[x][y + 1] = Group::op(dat[x][y + 1], dat[x][y]);\r\
    \n    FOR(x, H) FOR(y, W + 1) dat[x + 1][y] = Group::op(dat[x + 1][y], dat[x][y]);\r\
    \n  }\r\n\r\n  X sum(int x1, int y1, int x2, int y2) {\r\n    X a = Group::op(dat[x1][y1],\
    \ dat[x2][y2]);\r\n    X b = Group::op(dat[x2][y1], dat[x1][y2]);\r\n    return\
    \ Group::op(a, Group::inverse(b));\r\n  }\r\n};\n"
  code: "template <typename Group>\r\nstruct Cumsum2D {\r\n  using X = typename Group::value_type;\r\
    \n  int H, W;\r\n  vc<vc<X>> dat;\r\n\r\n  Cumsum2D() {}\r\n  Cumsum2D(vc<vc<X>>\
    \ &A) {\r\n    assert(Group::commute);\r\n    build(A);\r\n  }\r\n\r\n  void build(vc<vc<X>>\
    \ &A) {\r\n    int H = len(A);\r\n    int W = (H == 0 ? 0 : len(A[0]));\r\n  \
    \  dat.assign(H + 1, vc<X>(W + 1, Group::unit()));\r\n    FOR(x, H) FOR(y, W)\
    \ dat[x + 1][y + 1] = A[x][y];\r\n    FOR(x, H + 1) FOR(y, W) dat[x][y + 1] =\
    \ Group::op(dat[x][y + 1], dat[x][y]);\r\n    FOR(x, H) FOR(y, W + 1) dat[x +\
    \ 1][y] = Group::op(dat[x + 1][y], dat[x][y]);\r\n  }\r\n\r\n  X sum(int x1, int\
    \ y1, int x2, int y2) {\r\n    X a = Group::op(dat[x1][y1], dat[x2][y2]);\r\n\
    \    X b = Group::op(dat[x2][y1], dat[x1][y2]);\r\n    return Group::op(a, Group::inverse(b));\r\
    \n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/cumsum2d.hpp
  requiredBy: []
  timestamp: '2022-05-19 03:01:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1141_cumsum2d.test.cpp
documentation_of: ds/cumsum2d.hpp
layout: document
redirect_from:
- /library/ds/cumsum2d.hpp
- /library/ds/cumsum2d.hpp.html
title: ds/cumsum2d.hpp
---
