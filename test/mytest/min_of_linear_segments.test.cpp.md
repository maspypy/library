---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n#include \"my_template.hpp\"\
    \n#include \"other/io.hpp\"\n#include \"other/random.hpp\"\n#include \"mod/min_of_linear_segments.hpp\"\
    \n\npair<vc<int>, vc<int>> naive(int a, int b, int mod) {\n  assert(0 <= a &&\
    \ a < mod);\n  assert(0 <= b && b < mod);\n  vc<int> A;\n  int last_y = b;\n \
    \ FOR(x, 1, mod + 1) {\n    int y = (ll(a) * x + b) % mod;\n    if (chmin(last_y,\
    \ y)) A.eb(x);\n  }\n  vc<int> X = {0};\n  vc<int> DX;\n  int dx = -1;\n  for\
    \ (auto&& x: A) {\n    if (X.back() + dx == x) {\n      X.back() = x;\n    } else\
    \ {\n      dx = x - X.back();\n      DX.eb(dx);\n      X.eb(x);\n    }\n  }\n\
    \  return {X, DX};\n}\n\nvoid test() {\n  FOR(mod, 1, 1000) {\n    FOR(10) {\n\
    \      int a = RNG(0, mod);\n      int b = RNG(0, mod);\n      auto [X1, DX1]\
    \ = naive(a, b, mod);\n      auto [X2, DX2] = min_of_linear_segments(a, b, mod);\n\
    \      assert(X1 == X2);\n      assert(DX1 == DX2);\n    }\n  }\n}\n\nvoid solve()\
    \ {\n  LL(a, b);\n  print(a + b);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  test();\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/mytest/min_of_linear_segments.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/mytest/min_of_linear_segments.test.cpp
layout: document
redirect_from:
- /verify/test/mytest/min_of_linear_segments.test.cpp
- /verify/test/mytest/min_of_linear_segments.test.cpp.html
title: test/mytest/min_of_linear_segments.test.cpp
---
