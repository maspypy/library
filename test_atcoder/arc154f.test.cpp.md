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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/arc154/tasks/arc154_f\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n#include \"mod/modint.hpp\"\n\
    #include \"poly/fps_div.hpp\"\n#include \"poly/convolution_all.hpp\"\n#include\
    \ \"poly/composition_f_ex.hpp\"\n\nusing mint = modint998;\nusing poly = vc<mint>;\n\
    \nvoid solve() {\n  LL(N, M);\n  vc<poly> DEN;\n  mint cf = 1;\n  FOR(i, N) {\n\
    \    mint p = inv<mint>(N) * mint(N - i);\n    mint q = mint(1) - p;\n    cf *=\
    \ p;\n    DEN.eb(poly{mint(1), -q});\n  }\n  poly g = convolution_all(DEN);\n\
    \  // e^{Nx}\n  poly f(M + 1);\n  mint pow = 1;\n  FOR(i, M + 1) {\n    f[i] =\
    \ fact_inv<mint>(i) * pow;\n    pow *= mint(N);\n  }\n  g = composition_f_ex(M,\
    \ g);\n  f = fps_div(f, g);\n  FOR(i, 1, M + 1) print(f[i] * fact<mint>(i) * cf);\n\
    }\n\nsigned main() {\n  cin.tie(nullptr);\n  ios::sync_with_stdio(false);\n  cout\
    \ << setprecision(15);\n\n  solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/arc154f.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/arc154f.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/arc154f.test.cpp
- /verify/test_atcoder/arc154f.test.cpp.html
title: test_atcoder/arc154f.test.cpp
---
