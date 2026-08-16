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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/convolution.hpp\"\n#include \"mod/primitive_root.hpp\"\n\n\
    // C[k] = sum[k=ij mod p] A[i]B[j]\ntemplate <typename mint>\nvc<mint> multiplicative_convolution_mod_p(int\
    \ p, vc<mint>& A, vc<mint>& B) {\n  assert(len(A) == p && len(B) == p);\n  int\
    \ r = primitive_root(p);\n  vc<int> exp(p - 1), log(p);\n  exp[0] = 1;\n  FOR(i,\
    \ p - 2) exp[i + 1] = exp[i] * ll(r) % p;\n  FOR(i, p - 1) log[exp[i]] = i;\n\n\
    \  vc<mint> FA(p - 1), FB(p - 1);\n  FOR(i, p - 1) FA[i] = A[exp[i]], FB[i] =\
    \ B[exp[i]];\n  vc<mint> FC = convolution(FA, FB);\n  FOR(i, p - 1, len(FC)) FC[i\
    \ - (p - 1)] += FC[i];\n\n  vc<mint> C(p);\n  FOR(i, 1, p) C[i] = FC[log[i]];\n\
    \n  mint SA = SUM<mint>(A), SB = SUM<mint>(B);\n  C[0] += SA * B[0] + SB * A[0]\
    \ - A[0] * B[0];\n  return C;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/multiplicative_convolution_mod_p.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: mod/multiplicative_convolution_mod_p.hpp
layout: document
redirect_from:
- /library/mod/multiplicative_convolution_mod_p.hpp
- /library/mod/multiplicative_convolution_mod_p.hpp.html
title: mod/multiplicative_convolution_mod_p.hpp
---
