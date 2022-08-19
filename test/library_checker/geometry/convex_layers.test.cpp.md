---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: geo/dynamicupperhull.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convex_layers\"\r\n#include\
    \ \"my_template.hpp\"\r\n#include \"other/io.hpp\"\r\n#include \"geo/dynamicupperhull.hpp\"\
    \r\n\r\nvoid solve() {\r\n  LL(N);\r\n  vc<Point<ll>> pts(N);\r\n  FOR(i, N) read(pts[i].x),\
    \ read(pts[i].y);\r\n  DynamicUpperHull DUH(pts, 1);\r\n  FOR(i, N) pts[i] = -pts[i];\r\
    \n  DynamicUpperHull DLH(pts, 1);\r\n  vc<int> ANS(N, -1);\r\n  int done = 0;\r\
    \n  int k = 0;\r\n  while (done < N) {\r\n    ++k;\r\n    auto A = DUH.get();\r\
    \n    auto B = DLH.get();\r\n    A.insert(A.end(), all(B));\r\n    for (auto&&\
    \ i: A)\r\n      if (ANS[i] == -1) {\r\n        ++done;\r\n        ANS[i] = k;\r\
    \n        DUH.erase(i);\r\n        DLH.erase(i);\r\n      }\r\n  }\r\n  for (auto&&\
    \ x: ANS) print(x);\r\n}\r\n\r\nsigned main() {\r\n  solve();\r\n\r\n  return\
    \ 0;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: true
  path: test/library_checker/geometry/convex_layers.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library_checker/geometry/convex_layers.test.cpp
layout: document
redirect_from:
- /verify/test/library_checker/geometry/convex_layers.test.cpp
- /verify/test/library_checker/geometry/convex_layers.test.cpp.html
title: test/library_checker/geometry/convex_layers.test.cpp
---
