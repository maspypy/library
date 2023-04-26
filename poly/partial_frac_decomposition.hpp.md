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
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':x:'
    path: poly/multipoint.hpp
    title: poly/multipoint.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/partial_frac.test.cpp
    title: test/mytest/partial_frac.test.cpp
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
  code: "#include \"poly/multipoint.hpp\"\n// O(Nlog^2N)\n// \u5206\u6BCD\u306F\u76F8\
    \u7570\u306A\u308B 1 \u6B21\u5F0F\u306E\u7A4D\u9650\u5B9A\u3068\u3059\u308B\n\
    // f / prod(ax+b) = sum c/(ax+b) \u3068\u3044\u3046 C \u3092\u8FD4\u3059\ntemplate\
    \ <typename mint>\nvc<mint> partial_frac_decomposition(vc<mint> f, vc<mint> A)\
    \ {\n  assert(len(f) <= len(A));\n  if (len(f) == 0) return vc<mint>(len(A));\n\
    \  SubproductTree<mint> X(A);\n  vc<mint> g = X.T[1]; // prod(1-ax)\n  g.resize(len(A)\
    \ + 1);\n  reverse(all(g));\n  FOR(i, len(g) - 1) g[i] = g[i + 1] * mint(i + 1);\n\
    \  g.pop_back();\n\n  auto num = X.evaluation(f);\n  auto den = X.evaluation(g);\n\
    \  vc<mint> B(len(A));\n  FOR(i, len(A)) B[i] = num[i] / den[i];\n  return B;\n\
    }\n"
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
  isVerificationFile: false
  path: poly/partial_frac_decomposition.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/partial_frac.test.cpp
documentation_of: poly/partial_frac_decomposition.hpp
layout: document
redirect_from:
- /library/poly/partial_frac_decomposition.hpp
- /library/poly/partial_frac_decomposition.hpp.html
title: poly/partial_frac_decomposition.hpp
---
