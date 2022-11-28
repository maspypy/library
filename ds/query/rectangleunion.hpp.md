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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/lazy/cntminmincnt_add.hpp:\
    \ line -1: no such header\n"
  code: "#include \"ds/lazysegtree.hpp\"\r\n#include \"alg/lazy/cntminmincnt_add.hpp\"\
    \r\n\r\ntemplate <typename XY = int>\r\nstruct RectangleUnion {\r\n  using RECT\
    \ = tuple<XY, XY, XY, XY>;\r\n  vc<RECT> rectangles;\r\n  vc<XY> X, Y;\r\n\r\n\
    \  void add_rect(int xl, int xr, int yl, int yr) {\r\n    assert(xl < xr && yl\
    \ < yr);\r\n    X.eb(xl), X.eb(xr), Y.eb(yl), Y.eb(yr);\r\n    rectangles.eb(xl,\
    \ xr, yl, yr);\r\n  }\r\n\r\n  template <typename ANS_TYPE = ll>\r\n  ANS_TYPE\
    \ calc() {\r\n    UNIQUE(X), UNIQUE(Y);\r\n    int N = len(X);\r\n    vc<vc<pair<int,\
    \ int>>> add(N), rm(N);\r\n    for (auto &&[xl, xr, yl, yr]: rectangles) {\r\n\
    \      xl = LB(X, xl), xr = LB(X, xr);\r\n      yl = LB(Y, yl), yr = LB(Y, yr);\r\
    \n      add[xl].eb(yl, yr);\r\n      rm[xr].eb(yl, yr);\r\n    }\r\n\r\n    using\
    \ Lazy = Lazy_CntMinMincnt_Add<XY>;\r\n    using T = typename Lazy::X_structure::value_type;\r\
    \n    LazySegTree<Lazy> seg(len(Y) - 1, [&](int i) -> T {\r\n      return {Y[i\
    \ + 1] - Y[i], 0, Y[i + 1] - Y[i]};\r\n    });\r\n    ANS_TYPE ANS = 0;\r\n  \
    \  FOR(i, len(X) - 1) {\r\n      ANS_TYPE dx = X[i + 1] - X[i];\r\n      for (auto\
    \ &&[yl, yr]: add[i]) seg.apply(yl, yr, 1);\r\n      for (auto &&[yl, yr]: rm[i])\
    \ seg.apply(yl, yr, -1);\r\n      auto [cnt, min, mincnt] = seg.prod_all();\r\n\
    \      ANS_TYPE n = cnt;\r\n      if (min == 0) n -= mincnt;\r\n      ANS += n\
    \ * dx;\r\n    }\r\n    return ANS;\r\n  }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: ds/query/rectangleunion.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: ds/query/rectangleunion.hpp
layout: document
redirect_from:
- /library/ds/query/rectangleunion.hpp
- /library/ds/query/rectangleunion.hpp.html
title: ds/query/rectangleunion.hpp
---
