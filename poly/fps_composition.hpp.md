---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/polynomial/composition_of_fps.test.cpp
    title: test/library_checker/polynomial/composition_of_fps.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
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
  dependsOn:
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/fps_composition.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/polynomial/composition_of_fps.test.cpp
documentation_of: poly/fps_composition.hpp
layout: document
redirect_from:
- /library/poly/fps_composition.hpp
- /library/poly/fps_composition.hpp.html
title: poly/fps_composition.hpp
---
