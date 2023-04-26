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
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/convolution_huge.test.cpp
    title: test/library_checker/convolution/convolution_huge.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  code: "#include \"poly/convolution.hpp\"\r\ntemplate <typename mint>\r\nvc<mint>\
    \ convolution_huge(const vc<mint>& A, const vc<mint>& B) {\r\n  int N = len(A),\
    \ M = len(B);\r\n  if (N + M - 1 <= (1 << 22)) return convolution(A, B);\r\n \
    \ ll L = 22;\r\n  vv(mint, C, 4, 2 << L);\r\n  vv(mint, D, 4, 2 << L);\r\n  int\
    \ mask = (1 << L) - 1;\r\n  FOR(i, N) C[i >> L][i & mask] = A[i];\r\n  FOR(i,\
    \ M) D[i >> L][i & mask] = B[i];\r\n  FOR(i, 4) ntt(C[i], false);\r\n  FOR(i,\
    \ 4) ntt(D[i], false);\r\n\r\n  vc<mint> ANS(8 << L);\r\n\r\n  FOR(i, 7) {\r\n\
    \    vc<mint> E(2 << L);\r\n    FOR(c, 4) FOR(d, 4) if (c + d == i) {\r\n    \
    \  FOR(k, 2 << L) E[k] += C[c][k] * D[d][k];\r\n    }\r\n    ntt(E, true);\r\n\
    \    FOR(k, 2 << L) ANS[(i << L) + k] += E[k];\r\n  }\r\n  ANS.resize(N + M -\
    \ 1);\r\n  return ANS;\r\n}\r\n"
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
  path: poly/convolution_huge.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/convolution/convolution_huge.test.cpp
documentation_of: poly/convolution_huge.hpp
layout: document
redirect_from:
- /library/poly/convolution_huge.hpp
- /library/poly/convolution_huge.hpp.html
title: poly/convolution_huge.hpp
---
