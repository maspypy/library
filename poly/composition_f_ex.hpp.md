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
    path: poly/sum_of_exp_bx.hpp
    title: poly/sum_of_exp_bx.hpp
  - icon: ':x:'
    path: poly/sum_of_rationals.hpp
    title: poly/sum_of_rationals.hpp
  _extendedRequiredBy: []
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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"poly/sum_of_exp_bx.hpp\"\n\n// N \u6B21\u591A\u9805\u5F0F f \u306B\
    \u5BFE\u3057\u3066\u3001f(e^x) \u3092 N \u6B21\u307E\u3067\u3002O(Nlog^2N)\ntemplate\
    \ <typename mint>\nvc<mint> composition_f_ex(int N, vc<mint> f) {\n  vc<pair<mint,\
    \ mint>> AB;\n  FOR(k, len(f)) AB.eb(f[k], mint(k));\n  return sum_of_exp_bx(N,\
    \ AB);\n}"
  dependsOn:
  - poly/sum_of_exp_bx.hpp
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
  path: poly/composition_f_ex.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc154f.test.cpp
  - test/yukicoder/1875.test.cpp
documentation_of: poly/composition_f_ex.hpp
layout: document
redirect_from:
- /library/poly/composition_f_ex.hpp
- /library/poly/composition_f_ex.hpp.html
title: poly/composition_f_ex.hpp
---
