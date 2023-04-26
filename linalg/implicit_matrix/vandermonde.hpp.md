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
  - icon: ':x:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':x:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':x:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':x:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':x:'
    path: poly/sum_of_rationals.hpp
    title: poly/sum_of_rationals.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/vandermonde.test.cpp
    title: test/mytest/vandermonde.test.cpp
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"poly/multipoint.hpp\"\n#include \"poly/sum_of_rationals.hpp\"\n\
    #include \"poly/fps_div.hpp\"\n\n// transpose = 0\uFF1Ag[i] = sum pow(ai,j) f[j]\n\
    // transpose = 1\uFF1Ag[i] = sum pow(aj,i) f[j]\ntemplate <typename mint>\nvc<mint>\
    \ vandermonde(vc<mint> f, vc<mint> A, bool transpose, bool inverse) {\n  if (len(f)\
    \ == 0) return vc<mint>();\n  int N = len(f);\n  using poly = vc<mint>;\n  if\
    \ (!transpose) {\n    if (!inverse) { return multipoint_eval(f, A); }\n    if\
    \ (inverse) { return multipoint_interpolate(A, f); }\n  }\n  if (!inverse) {\n\
    \    vc<pair<poly, poly>> dat(N);\n    FOR(j, N) {\n      poly a{f[j]}, b{mint(1),\
    \ mint(-A[j])};\n      dat[j] = {a, b};\n    }\n    auto [num, den] = sum_of_rationals(dat);\n\
    \    num.resize(N);\n    return fps_div(num, den);\n  }\n  SubproductTree<mint>\
    \ X(A);\n  vc<mint> g = X.T[1]; // prod(1-ax)\n  g.resize(N + 1);\n  f = convolution<mint>(f,\
    \ g);\n  f.resize(N);\n  reverse(all(f));\n  reverse(all(g));\n  FOR(i, len(g)\
    \ - 1) g[i] = g[i + 1] * mint(i + 1);\n  g.pop_back();\n  auto num = X.evaluation(f);\n\
    \  auto den = X.evaluation(g);\n  vc<mint> B(len(A));\n  FOR(i, len(A)) B[i] =\
    \ num[i] / den[i];\n  return B;\n}"
  dependsOn:
  - poly/multipoint.hpp
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - poly/middle_product.hpp
  - poly/sum_of_rationals.hpp
  - poly/fps_div.hpp
  isVerificationFile: false
  path: linalg/implicit_matrix/vandermonde.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/vandermonde.test.cpp
documentation_of: linalg/implicit_matrix/vandermonde.hpp
layout: document
redirect_from:
- /library/linalg/implicit_matrix/vandermonde.hpp
- /library/linalg/implicit_matrix/vandermonde.hpp.html
title: linalg/implicit_matrix/vandermonde.hpp
---
