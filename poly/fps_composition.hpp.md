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
  code: "#include \"poly/convolution.hpp\"\r\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ fps_composition(vc<mint>& Q, vc<mint>& P) {\r\n  int n = len(P);\r\n  assert(len(P)\
    \ == len(Q));\r\n  int k = 1;\r\n  while (k * k < n) ++k;\r\n  // compute powers\
    \ of P\r\n  vv(mint, pow1, k + 1);\r\n  pow1[0] = {1};\r\n  pow1[1] = P;\r\n \
    \ FOR3(i, 2, k + 1) {\r\n    pow1[i] = convolution(pow1[i - 1], pow1[1]);\r\n\
    \    pow1[i].resize(n);\r\n  }\r\n  vv(mint, pow2, k + 1);\r\n  pow2[0] = {1};\r\
    \n  pow2[1] = pow1[k];\r\n  FOR3(i, 2, k + 1) {\r\n    pow2[i] = convolution(pow2[i\
    \ - 1], pow2[1]);\r\n    pow2[i].resize(n);\r\n  }\r\n  vc<mint> ANS(n);\r\n \
    \ FOR(i, k + 1) {\r\n    vc<mint> f(n);\r\n    FOR(j, k) {\r\n      if (k * i\
    \ + j < len(Q)) {\r\n        mint coef = Q[k * i + j];\r\n        FOR(d, len(pow1[j]))\
    \ f[d] += pow1[j][d] * coef;\r\n      }\r\n    }\r\n    f = convolution(f, pow2[i]);\r\
    \n    f.resize(n);\r\n    FOR(d, n) ANS[d] += f[d];\r\n  }\r\n  return ANS;\r\n\
    }\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_composition.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_composition.hpp
layout: document
redirect_from:
- /library/poly/fps_composition.hpp
- /library/poly/fps_composition.hpp.html
title: poly/fps_composition.hpp
---
