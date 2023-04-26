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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/agc058/tasks/agc058_d\"\n#include\
    \ \"my_template.hpp\"\n#include \"other/io.hpp\"\n\n#include \"poly/convolution.hpp\"\
    \n#include \"poly/coef_of_rational_fps_2d.hpp\"\n\nusing mint = modint998;\n\n\
    void solve() {\n  LL(A, B, C);\n  ll N = A + B + C;\n\n  using poly = vc<mint>;\n\
    \  vc<poly> F(2), G(4);\n  F[0] = {mint(3)};\n  F[1] = {mint(-1)};\n  G[0] = {mint(1)};\n\
    \  G[1] = {mint(-1)};\n  G[3] = {mint(0), mint(2)};\n\n  auto g = coef_of_rational_fps_2d(F,\
    \ G, N);\n  FOR(i, len(g)) g[i] *= inv<mint>(2);\n  g[0] = 1;\n\n  mint ANS =\
    \ 0;\n\n  FOR(t, len(g)) {\n    ll a = A - t, b = B - t, c = C - t;\n    if (min({a,\
    \ b, c}) < 0) break;\n    mint cf = fact<mint>(a + b + c) * fact_inv<mint>(a)\
    \ * fact_inv<mint>(b)\n              * fact_inv<mint>(c);\n    ANS += g[t] * cf;\n\
    \  }\n  print(ANS);\n}\n\nsigned main() {\n  cout << fixed << setprecision(15);\n\
    \n  ll T = 1;\n  // LL(T);\n  FOR(T) solve();\n\n  return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test_atcoder/agc058d.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test_atcoder/agc058d.test.cpp
layout: document
redirect_from:
- /verify/test_atcoder/agc058d.test.cpp
- /verify/test_atcoder/agc058d.test.cpp.html
title: test_atcoder/agc058d.test.cpp
---
