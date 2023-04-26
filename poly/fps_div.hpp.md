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
    path: linalg/implicit_matrix/vandermonde.hpp
    title: linalg/implicit_matrix/vandermonde.hpp
  - icon: ':warning:'
    path: poly/composed_product.hpp
    title: poly/composed_product.hpp
  - icon: ':warning:'
    path: poly/composed_sum.hpp
    title: poly/composed_sum.hpp
  - icon: ':x:'
    path: poly/slice_rational_fps.hpp
    title: poly/slice_rational_fps.hpp
  - icon: ':warning:'
    path: poly/sum_of_power_of_roots.hpp
    title: poly/sum_of_power_of_roots.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/slice_rational_fps.test.cpp
    title: test/mytest/slice_rational_fps.test.cpp
  - icon: ':x:'
    path: test/mytest/vandermonde.test.cpp
    title: test/mytest/vandermonde.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1533.test.cpp
    title: test/yukicoder/1533.test.cpp
  - icon: ':x:'
    path: test_atcoder/agc013e.test.cpp
    title: test_atcoder/agc013e.test.cpp
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
  code: "#pragma once\n\n#include \"poly/count_terms.hpp\"\n#include \"poly/fps_inv.hpp\"\
    \n\n// f/g. f \u306E\u9577\u3055\u3067\u51FA\u529B\u3055\u308C\u308B.\ntemplate\
    \ <typename mint, bool SPARSE = false>\nvc<mint> fps_div(vc<mint> f, vc<mint>\
    \ g) {\n  if (SPARSE || count_terms(g) < 200) return fps_div_sparse(f, g);\n \
    \ int n = len(f);\n  g.resize(n);\n  g = fps_inv<mint>(g);\n  f = convolution(f,\
    \ g);\n  f.resize(n);\n  return f;\n}\n\n// f/g \u305F\u3060\u3057 g \u306F sparse\n\
    template <typename mint>\nvc<mint> fps_div_sparse(vc<mint> f, vc<mint>& g) {\n\
    \  if (g[0] != mint(1)) {\n    mint cf = g[0].inverse();\n    for (auto&& x: f)\
    \ x *= cf;\n    for (auto&& x: g) x *= cf;\n  }\n\n  vc<pair<int, mint>> dat;\n\
    \  FOR(i, 1, len(g)) if (g[i] != mint(0)) dat.eb(i, -g[i]);\n  FOR(i, len(f))\
    \ {\n    for (auto&& [j, x]: dat) {\n      if (i >= j) f[i] += x * f[i - j];\n\
    \    }\n  }\n  return f;\n}"
  dependsOn:
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/fps_div.hpp
  requiredBy:
  - linalg/implicit_matrix/vandermonde.hpp
  - poly/slice_rational_fps.hpp
  - poly/composed_sum.hpp
  - poly/sum_of_power_of_roots.hpp
  - poly/composed_product.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc154f.test.cpp
  - test_atcoder/agc013e.test.cpp
  - test/yukicoder/1533.test.cpp
  - test/mytest/vandermonde.test.cpp
  - test/mytest/slice_rational_fps.test.cpp
documentation_of: poly/fps_div.hpp
layout: document
redirect_from:
- /library/poly/fps_div.hpp
- /library/poly/fps_div.hpp.html
title: poly/fps_div.hpp
---
