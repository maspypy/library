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
  - icon: ':x:'
    path: poly/sum_of_rationals.hpp
    title: poly/sum_of_rationals.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: poly/composition_f_ex.hpp
    title: poly/composition_f_ex.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1875.test.cpp
    title: test/yukicoder/1875.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc154f.test.cpp
    title: test_atcoder/arc154f.test.cpp
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
  code: "#include \"poly/sum_of_rationals.hpp\"\n#include \"poly/fps_inv.hpp\"\n\n\
    // sum a e^{bx} \u3092 N \u6B21\u307E\u3067\u3002O(Mlog^2M + NlogN)\ntemplate\
    \ <typename mint>\nvc<mint> sum_of_exp_bx(int N, vc<pair<mint, mint>> AB) {\n\
    \  using poly = vc<mint>;\n  vc<pair<poly, poly>> fracs;\n  for (auto&& [a, b]:\
    \ AB) {\n    poly num = {a};\n    poly den = {mint(1), -b};\n    fracs.eb(num,\
    \ den);\n  }\n  auto [f, g] = sum_of_rationals<mint>(fracs);\n  g.resize(N + 1);\n\
    \  f = convolution(f, fps_inv(g));\n  f.resize(N + 1);\n  FOR(n, N + 1) f[n] *=\
    \ fact_inv<mint>(n);\n  return f;\n}\n"
  dependsOn:
  - poly/sum_of_rationals.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - poly/fps_inv.hpp
  - poly/count_terms.hpp
  isVerificationFile: false
  path: poly/sum_of_exp_bx.hpp
  requiredBy:
  - poly/composition_f_ex.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc154f.test.cpp
  - test/yukicoder/1875.test.cpp
documentation_of: poly/sum_of_exp_bx.hpp
layout: document
redirect_from:
- /library/poly/sum_of_exp_bx.hpp
- /library/poly/sum_of_exp_bx.hpp.html
title: poly/sum_of_exp_bx.hpp
---
