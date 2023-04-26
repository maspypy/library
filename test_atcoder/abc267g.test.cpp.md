---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc267/tasks/abc267_g\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\n\
    #include \"linalg/implicit_matrix/pascal.hpp\"\n#include \"poly/convolution_all.hpp\"\
    \n#include \"poly/multipoint.hpp\"\n\nusing mint = modint998;\n\nvoid solve()\
    \ {\n  LL(N, K);\n  vc<int> CNT(N);\n  FOR(N) {\n    INT(x);\n    CNT[--x]++;\n\
    \  }\n  vvc<mint> polys;\n  for (auto&& c: CNT) {\n    FOR(i, c) {\n      vc<mint>\
    \ f = {-mint(i), mint(1)};\n      polys.eb(f);\n    }\n  }\n  auto P = convolution_all(polys);\n\
    \  vc<mint> points(N + 1);\n  FOR(i, N + 1) points[i] = mint(i);\n  auto F = multipoint_eval(P,\
    \ points);\n\n  F = pascal<mint>(F, 0, 1);\n  reverse(all(F));\n  F = pascal<mint>(F,\
    \ 1, 1);\n  reverse(all(F));\n  print(F[N - K]);\n}\n\nsigned main() {\n  solve();\n\
    \  return 0;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/abc267g.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/abc267g.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/abc267g.test.cpp
- /verify/test_atcoder/abc267g.test.cpp.html
title: test_atcoder/abc267g.test.cpp
---
