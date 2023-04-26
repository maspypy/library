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
  code: "#include \"random/base.hpp\"\n#include \"linalg/mat_mul.hpp\"\n#include \"\
    linalg/mat_inv.hpp\"\n#include \"linalg/characteristic_poly.hpp\"\n#include \"\
    poly/poly_taylor_shift.hpp\"\n\n// det(A + xB) = f(x) \u3068\u306A\u308B N \u6B21\
    \u591A\u9805\u5F0F f \u3092\u8FD4\u3059\n// \u78BA\u7387 N / mod \u3067\u6B63\u3057\
    \u304F\u89E3\u3051\u308B\uFF08\u4E71\u6570\u306B\u4F9D\u5B58\u3057\u306A\u3044\
    \u65B9\u6CD5\u3082\u3042\u308B\u3088\u3046\u3060\uFF09\ntemplate <typename mint>\n\
    vc<mint> det_A_plus_xB(vvc<mint> A, vvc<mint> B) {\n  int N = len(A);\n  vc<mint>\
    \ f(N + 1);\n  mint a = RNG(mint::get_mod());\n  FOR(i, N) FOR(j, N) A[i][j] +=\
    \ a * B[i][j];\n  auto [det_A, inv_A] = mat_inv(A);\n  if (det_A == 0) { return\
    \ f; }\n  B = mat_mul(B, inv_A);\n  FOR(i, N) FOR(j, N) B[i][j] = -B[i][j];\n\
    \  f = characteristic_poly(B);\n  reverse(all(f));\n  for (auto&& x: f) x *= det_A;\n\
    \  f = poly_taylor_shift(f, -a);\n  return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/det_A_plus_xB.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/det_A_plus_xB.hpp
layout: document
redirect_from:
- /library/linalg/det_A_plus_xB.hpp
- /library/linalg/det_A_plus_xB.hpp.html
title: linalg/det_A_plus_xB.hpp
---
