---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':question:'
    path: ds/sliding_window_aggregation.hpp
    title: ds/sliding_window_aggregation.hpp
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
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':x:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':x:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':x:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1080_2.test.cpp
    title: test/yukicoder/1080_2.test.cpp
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
    \  [Previous line repeated 3 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"poly/from_log_differentiation.hpp\"\n\n// exp(f/g) \u3067 f,g\
    \ \u304C sparse\ntemplate <typename mint>\nvc<mint> sparse_exp_of_div(int N, const\
    \ vc<mint>& f, const vc<mint>& g) {\n  assert(f[0] == mint(0));\n  assert(g[0]\
    \ == mint(1));\n  using P = pair<int, mint>;\n  vc<P> dat_f, dat_g;\n  FOR(i,\
    \ len(f)) if (f[i] != mint(0)) dat_f.eb(i, f[i]);\n  FOR(i, len(g)) if (g[i] !=\
    \ mint(0)) dat_g.eb(i, g[i]);\n\n  vc<mint> a(len(f) + len(g) - 2), b(2 * len(g)\
    \ - 1);\n  // a = f'g-fg', b = g^2\n  for (auto&& [i, x]: dat_f) {\n    for (auto&&\
    \ [j, y]: dat_g) { a[i + j - 1] += x * y * mint(i - j); }\n  }\n  for (auto&&\
    \ [i, x]: dat_g) {\n    for (auto&& [j, y]: dat_g) { b[i + j] += x * y; }\n  }\n\
    \  return from_log_differentiation(N, a, b);\n}"
  dependsOn:
  - poly/from_log_differentiation.hpp
  - seq/kth_term_of_p_recursive.hpp
  - poly/prefix_product_of_poly.hpp
  - linalg/mat_mul.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/lagrange_interpolate_iota.hpp
  - alg/monoid/mul.hpp
  - ds/sliding_window_aggregation.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/sparse_exp_of_div.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1080_2.test.cpp
documentation_of: poly/sparse_exp_of_div.hpp
layout: document
redirect_from:
- /library/poly/sparse_exp_of_div.hpp
- /library/poly/sparse_exp_of_div.hpp.html
title: poly/sparse_exp_of_div.hpp
---
