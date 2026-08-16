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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/monoid/min_idx.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"random/base.hpp\"\n#include \"geo/manhattan_nns.hpp\"\n\nvoid test()\
    \ {\n  FOR(n, 1, 20) FOR(m, 1, 20) {\n    vc<pi> A, B;\n    FOR(n) {\n      int\
    \ a = RNG(0, 100);\n      int b = RNG(0, 100);\n      A.eb(a, b);\n    }\n   \
    \ FOR(m) {\n      int a = RNG(0, 100);\n      int b = RNG(0, 100);\n      B.eb(a,\
    \ b);\n    }\n    auto [dist, J] = manhattan_nns(A, B);\n    FOR(i, n) {\n   \
    \   FOR(j, m) {\n        auto [x1, y1] = A[i];\n        auto [x2, y2] = B[j];\n\
    \        int d = abs(x1 - x2) + abs(y1 - y2);\n        assert(dist[i] <= d);\n\
    \        assert(j != J[i] || dist[i] == d);\n      }\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  int a, b;\n  cin >> a >> b;\n  cout << a + b << \"\\n\";\n}\n\nsigned main()\
    \ {\n  test();\n  solve();\n  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/1_mytest/manhattan_nns.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/1_mytest/manhattan_nns.test.cpp
layout: document
redirect_from:
- /verify/test/1_mytest/manhattan_nns.test.cpp
- /verify/test/1_mytest/manhattan_nns.test.cpp.html
title: test/1_mytest/manhattan_nns.test.cpp
---
