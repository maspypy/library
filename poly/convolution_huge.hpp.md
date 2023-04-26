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
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_huge.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_huge.hpp
layout: document
redirect_from:
- /library/poly/convolution_huge.hpp
- /library/poly/convolution_huge.hpp.html
title: poly/convolution_huge.hpp
---
