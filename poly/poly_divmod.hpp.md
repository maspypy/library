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
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: poly/poly_gcd.hpp
    title: poly/poly_gcd.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/polynomial/inv_of_polynomials.test.cpp
    title: test/library_checker/polynomial/inv_of_polynomials.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/polynomial_division.test.cpp
    title: test/library_checker/polynomial/polynomial_division.test.cpp
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
  code: "#include \"poly/fps_inv.hpp\"\r\ntemplate <typename mint>\r\npair<vc<mint>,\
    \ vc<mint>> poly_divmod(vc<mint> f, vc<mint> g) {\r\n  assert(g.back() != 0);\r\
    \n  if (len(f) < len(g)) { return {{}, f}; }\r\n  auto rf = f, rg = g;\r\n  reverse(all(rf)),\
    \ reverse(all(rg));\r\n  ll deg = len(rf) - len(rg) + 1;\r\n  rf.resize(deg),\
    \ rg.resize(deg);\r\n  rg = fps_inv(rg);\r\n  auto q = convolution(rf, rg);\r\n\
    \  q.resize(deg);\r\n  reverse(all(q));\r\n  auto h = convolution(q, g);\r\n \
    \ FOR(i, len(f)) f[i] -= h[i];\r\n  while (len(f) > 0 && f.back() == 0) f.pop_back();\r\
    \n  return {q, f};\r\n}\r\n"
  dependsOn:
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
  isVerificationFile: false
  path: poly/poly_divmod.hpp
  requiredBy:
  - poly/poly_gcd.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/polynomial/inv_of_polynomials.test.cpp
  - test/library_checker/polynomial/polynomial_division.test.cpp
documentation_of: poly/poly_divmod.hpp
layout: document
redirect_from:
- /library/poly/poly_divmod.hpp
- /library/poly/poly_divmod.hpp.html
title: poly/poly_divmod.hpp
---
