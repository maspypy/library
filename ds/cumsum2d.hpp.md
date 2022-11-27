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
  code: "#include \"alg/group/add.hpp\"\r\n\r\ntemplate <typename Group>\r\nstruct\
    \ Cumsum2D {\r\n  using X = typename Group::value_type;\r\n  int H, W;\r\n  vc<vc<X>>\
    \ dat;\r\n\r\n  Cumsum2D() {}\r\n  Cumsum2D(vc<vc<X>> &A) {\r\n    assert(Group::commute);\r\
    \n    build(A);\r\n  }\r\n\r\n  void build(vc<vc<X>> &A) {\r\n    int H = len(A);\r\
    \n    int W = (H == 0 ? 0 : len(A[0]));\r\n    dat.assign(H + 1, vc<X>(W + 1,\
    \ Group::unit()));\r\n    FOR(x, H) FOR(y, W) dat[x + 1][y + 1] = A[x][y];\r\n\
    \    FOR(x, H + 1) FOR(y, W) dat[x][y + 1] = Group::op(dat[x][y + 1], dat[x][y]);\r\
    \n    FOR(x, H) FOR(y, W + 1) dat[x + 1][y] = Group::op(dat[x + 1][y], dat[x][y]);\r\
    \n  }\r\n\r\n  X sum(int x1, int x2, int y1, int y2) {\r\n    X a = Group::op(dat[x1][y1],\
    \ dat[x2][y2]);\r\n    X b = Group::op(dat[x2][y1], dat[x1][y2]);\r\n    return\
    \ Group::op(a, Group::inverse(b));\r\n  }\r\n};"
  dependsOn: []
  isVerificationFile: false
  path: ds/cumsum2d.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/cumsum2d.hpp
layout: document
redirect_from:
- /library/ds/cumsum2d.hpp
- /library/ds/cumsum2d.hpp.html
title: ds/cumsum2d.hpp
---
