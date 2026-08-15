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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/powertable.hpp:\
    \ line -1: no such header\n"
  code: "#include \"seq/famous/bernoulli.hpp\"\n\n// sum_[1,n]i^k=f(n)\ntemplate <typename\
    \ mint>\nvc<mint> faulhaber_formula(int k) {\n  vc<mint> F = bernoulli_number<mint>(k\
    \ + 1);\n  if (1 <= k) F[1] = inv<mint>(2);\n  reverse(all(F));\n  F[0] = 0;\n\
    \  FOR(r, k + 1) { F[k - r + 1] *= fact<mint>(k) * fact_inv<mint>(r) * fact_inv<mint>(k\
    \ + 1 - r); }\n  return F;\n}\n\n// sum_[1,n]i^k=f(n)\ntemplate <typename mint>\n\
    vvc<mint> faulhaber_formula_2d(int n) {\n  vc<mint> B = bernoulli_number<mint>(n);\n\
    \  if (1 <= n) B[1] = inv<mint>(2);\n  vvc<mint> ANS(n + 1);\n  FOR(k, n + 1)\
    \ {\n    ANS[k].resize(k + 2);\n    FOR(j, k + 1) ANS[k][k + 1 - j] = inv<mint>(k\
    \ + 1) * C<mint>(k + 1, j) * B[j];\n  }\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/faulhaber.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/faulhaber.hpp
layout: document
redirect_from:
- /library/seq/famous/faulhaber.hpp
- /library/seq/famous/faulhaber.hpp.html
title: seq/famous/faulhaber.hpp
---
