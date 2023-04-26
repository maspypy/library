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
  - icon: ':x:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://oeis.org/A057500
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
  code: "#include \"poly/fps_log.hpp\"\n\n// https://oeis.org/A057500\ntemplate <typename\
    \ mint>\nvc<mint> count_unicyclic(ll nmax) {\n  // \u30B5\u30A4\u30AF\u30EB\u306E\
    \u5927\u304D\u3055\u304C k \u3067\u3042\u308B\u3082\u306E\uFF1A\u9577\u3055 k\
    \ \u306E\u6839\u4ED8\u304D\u6728\u306E\u5217\u3092 (2k) \u3067\u5272\u308B\n \
    \ // sum f^{k} / (2k) \u306E\u5F62\u306B\u306A\u308B\u306E\u3067\u3001log \u3067\
    \u6570\u3048\u3089\u308C\u308B\n  vc<mint> f(nmax + 1);\n  FOR(n, 1, nmax) {\n\
    \    f[n] = mint(n).pow(n - 1) * fact_inv<mint>(n); // rooted\n  }\n  vc<mint>\
    \ F(nmax + 1);\n  F[0] = 1;\n  FOR(i, 1, nmax + 1) F[i] = -f[i];\n  F = fps_log(F);\n\
    \  FOR(i, nmax + 1) F[i] = -F[i];\n  // k = 1\n  FOR(i, nmax + 1) F[i] -= f[i];\n\
    \  // k = 2\n  f = convolution(f, f);\n  FOR(i, nmax + 1) F[i] -= f[i] * inv<mint>(2);\n\
    \  FOR(i, nmax + 1) F[i] *= fact<mint>(i) * inv<mint>(2);\n  return F;\n}\n"
  dependsOn:
  - poly/fps_log.hpp
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
  path: graph/count/count_unicyclic.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_unicyclic.hpp
layout: document
redirect_from:
- /library/graph/count/count_unicyclic.hpp
- /library/graph/count/count_unicyclic.hpp.html
title: graph/count/count_unicyclic.hpp
---
