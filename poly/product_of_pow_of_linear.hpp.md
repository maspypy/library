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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/sum_of_rationals.hpp\"\n#include \"poly/fps_inv.hpp\"\n#include\
    \ \"poly/fps_exp.hpp\"\n\n// (a+bx)^c \u306E\u7A4D\u3092 n \u307E\u3067\u6C42\u3081\
    \u308B\n// O(nlogn + mlog^2m)\ntemplate <typename mint>\nvc<mint> product_of_pow_of_linear(int\
    \ N, vc<mint> A, vc<mint> B, vi C) {\n  using poly = vc<mint>;\n  vc<pair<poly,\
    \ poly>> fracs;\n  mint cf = 1;\n  FOR(i, len(A)) {\n    assert(A[i] != mint(0));\n\
    \    cf *= A[i].pow(C[i]);\n    B[i] /= A[i];\n    poly num = {B[i] * mint(C[i])};\n\
    \    poly den = {1, B[i]};\n    fracs.eb(num, den);\n  }\n  auto [f, g] = sum_of_rationals(fracs);\n\
    \  g.resize(N + 1);\n  f = convolution(f, fps_inv(g));\n  f.resize(N + 1);\n \
    \ FOR_R(i, N) f[i + 1] = f[i] * inv<mint>(i + 1);\n  f[0] = 0;\n  f = fps_exp(f);\n\
    \  for (auto&& x: f) x *= cf;\n  return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/product_of_pow_of_linear.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/product_of_pow_of_linear.hpp
layout: document
redirect_from:
- /library/poly/product_of_pow_of_linear.hpp
- /library/poly/product_of_pow_of_linear.hpp.html
title: poly/product_of_pow_of_linear.hpp
---
