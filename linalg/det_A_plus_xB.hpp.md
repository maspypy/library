---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/characteristic_poly.hpp
    title: linalg/characteristic_poly.hpp
  - icon: ':x:'
    path: linalg/mat_inv.hpp
    title: linalg/mat_inv.hpp
  - icon: ':x:'
    path: linalg/mat_mul.hpp
    title: linalg/mat_mul.hpp
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
  - icon: ':x:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
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
  - icon: ':x:'
    path: poly/poly_taylor_shift.hpp
    title: poly/poly_taylor_shift.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
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
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
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
  dependsOn:
  - random/base.hpp
  - linalg/mat_mul.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - linalg/mat_inv.hpp
  - linalg/characteristic_poly.hpp
  - poly/poly_taylor_shift.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: linalg/det_A_plus_xB.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1907.test.cpp
documentation_of: linalg/det_A_plus_xB.hpp
layout: document
redirect_from:
- /library/linalg/det_A_plus_xB.hpp
- /library/linalg/det_A_plus_xB.hpp.html
title: linalg/det_A_plus_xB.hpp
---
