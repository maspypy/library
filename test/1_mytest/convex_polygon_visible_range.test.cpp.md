---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geo/incremental_convexhull.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n\n#include \"geo/base.hpp\"\n#include \"geo/convex_hull.hpp\"\n#include \"geo/convex_polygon.hpp\"\
    \n#include \"geo/incremental_convexhull.hpp\"\n#include \"random/base.hpp\"\n\n\
    using P = Point<ll>;\n\nvoid test() {\n  int N = RNG(3, 10);\n  vc<P> point(N);\n\
    \  FOR(i, N) point[i] = P(RNG(-5, 5), RNG(-5, 5));\n  auto I = ConvexHull(point);\n\
    \  point = rearrange(point, I);\n  N = len(point);\n  if (N <= 2) return;\n\n\
    \  ConvexPolygon<ll> X(point);\n  FOR(x, -10, 11) FOR(y, -10, 11) {\n    P p(x,\
    \ y);\n    if (X.side(p) == 1) continue;\n    auto [l, r] = X.visible_range(p);\n\
    \    vc<int> can(N);\n    {\n      int i = l;\n      while (1) {\n        can[i]\
    \ = 1;\n        if (i == r) break;\n        i = (i + 1) % N;\n      }\n    }\n\
    \    FOR(i, N) {\n      int j = (i + N - 1) % N, k = (i + 1) % N;\n      P A =\
    \ point[j], B = point[i], C = point[k];\n      int ok = 0;\n      if ((B - A).det(p\
    \ - A) <= 0) ok = 1;\n      if ((B - C).det(p - C) >= 0) ok = 1;\n      assert(can[i]\
    \ == ok);\n    }\n  }\n}\n\nvoid solve() {\n  int a, b;\n  cin >> a >> b;\n  cout\
    \ << a + b << \"\\n\";\n}\n\nsigned main() {\n  FOR(30000) test();\n  solve();\n\
    \  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/convex_polygon_visible_range.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/convex_polygon_visible_range.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/convex_polygon_visible_range.test.cpp
- /verify/test/1_mytest/convex_polygon_visible_range.test.cpp.html
title: test/1_mytest/convex_polygon_visible_range.test.cpp
---
