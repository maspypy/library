---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/add.hpp:\
    \ line -1: no such header\n"
  code: "#include \"alg/group/add.hpp\"\r\ntemplate <typename AbelGroup>\r\nstruct\
    \ Fenwick2D_dense {\r\n  using E = typename AbelGroup::value_type;\r\n  int H,\
    \ W;\r\n  vc<vc<E>> dat;\r\n\r\n  Fenwick2D_dense() {}\r\n  Fenwick2D_dense(int\
    \ H, int W) : H(H), W(W), dat(H + 1, vc<E>(W + 1)) {}\r\n\r\n  void add_x(int\
    \ x, int y, E val) {\r\n    ++y;\r\n    while (y <= W) {\r\n      dat[x][y] =\
    \ AbelGroup::op(dat[x][y], val);\r\n      y += y & -y;\r\n    }\r\n  }\r\n\r\n\
    \  void add(int x, int y, E val) {\r\n    ++x;\r\n    while (x <= H) {\r\n   \
    \   add_x(x, y, val);\r\n      x += x & -x;\r\n    }\r\n  }\r\n\r\n  E sum_x(int\
    \ x, int ly, int ry) {\r\n    E pos = AbelGroup::unit();\r\n    E neg = AbelGroup::unit();\r\
    \n    while (ly < ry) {\r\n      pos = AbelGroup::op(pos, dat[x][ry]);\r\n   \
    \   ry -= ry & -ry;\r\n    }\r\n    while (ry < ly) {\r\n      neg = AbelGroup::op(neg,\
    \ dat[x][ly]);\r\n      ly -= ly & -ly;\r\n    }\r\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\r\n  }\r\n\r\n  E prod(int lx, int rx, int ly, int\
    \ ry) {\r\n    E pos = AbelGroup::unit();\r\n    E neg = AbelGroup::unit();\r\n\
    \    while (lx < rx) {\r\n      pos = AbelGroup::op(pos, sum_x(rx, ly, ry));\r\
    \n      rx -= rx & -rx;\r\n    }\r\n    while (rx < lx) {\r\n      neg = AbelGroup::op(neg,\
    \ sum_x(lx, ly, ry));\r\n      lx -= lx & -lx;\r\n    }\r\n    return AbelGroup::op(pos,\
    \ AbelGroup::inverse(neg));\r\n  }\r\n\r\n  E sum(int lx, int rx, int ly, int\
    \ ry) { return prod(lx, ly, rx, ry); }\r\n\r\n  E prefix_prod(int rx, int ry)\
    \ { return prod(0, rx, 0, ry); }\r\n  E prefix_sum(int rx, int ry) { return prod(0,\
    \ rx, 0, ry); }\r\n\r\n  void debug() {\r\n    print(\"Fenwick2d dat\");\r\n \
    \   FOR(x, H + 1) print(dat[x]);\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/fenwick2d_dense.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/fenwick2d_dense.hpp
layout: document
redirect_from:
- /library/ds/fenwick2d_dense.hpp
- /library/ds/fenwick2d_dense.hpp.html
title: ds/fenwick2d_dense.hpp
---
