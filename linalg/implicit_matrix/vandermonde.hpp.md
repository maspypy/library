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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: linalg/implicit_matrix/vandermonde.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/implicit_matrix/vandermonde.hpp
layout: document
redirect_from:
- /library/linalg/implicit_matrix/vandermonde.hpp
- /library/linalg/implicit_matrix/vandermonde.hpp.html
title: linalg/implicit_matrix/vandermonde.hpp
---
