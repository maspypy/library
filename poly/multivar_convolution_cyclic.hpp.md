---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':x:'
    path: mod/mod_pow.hpp
    title: mod/mod_pow.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':x:'
    path: mod/primitive_root.hpp
    title: mod/primitive_root.hpp
  - icon: ':question:'
    path: nt/factor.hpp
    title: nt/factor.hpp
  - icon: ':question:'
    path: nt/primetest.hpp
    title: nt/primetest.hpp
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
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
    title: test/library_checker/math/multivariate_convolution_cyclic.test.cpp
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
  code: "#include \"poly/multipoint.hpp\"\n#include \"mod/primitive_root.hpp\"\n\n\
    /*\nexample : ns = (2, 3)\n[a0, a1, a2, a3, a4, a5] = [a(0,0), a(1,0), a(0,1),\
    \ a(1,1), a(0,2), a(1,2)]\n[b0, b1, b2, b3, b4, b5] = [b(0,0), b(1,0), b(0,1),\
    \ b(1,1), b(0,2), b(1,2)]\n*/\ntemplate <typename mint>\nvc<mint> multivar_convolution_cyclic(vc<int>\
    \ ns, vc<mint> f, vc<mint>& g) {\n  int p = mint::get_mod();\n  for (auto&& n:\
    \ ns) assert((p - 1) % n == 0);\n  mint r = primitive_root(p);\n  mint ir = r.inverse();\n\
    \n  int K = len(ns);\n  int N = 1;\n  for (auto&& n: ns) N *= n;\n  assert(len(f)\
    \ == N);\n  assert(len(g) == N);\n  vc<mint> root(K), iroot(K);\n\n  FOR(k, K)\
    \ { root[k] = r.pow((p - 1) / ns[k]); }\n  FOR(k, K) { iroot[k] = ir.pow((p -\
    \ 1) / ns[k]); }\n\n  int step = 1;\n  FOR(k, K) {\n    int n = ns[k];\n    FOR(i,\
    \ N) if (i % (step * n) < step) {\n      vc<mint> a(n), b(n);\n      FOR(j, n)\
    \ {\n        a[j] = f[i + step * j];\n        b[j] = g[i + step * j];\n      }\n\
    \      a = multipoint_eval_on_geom_seq(a, mint(1), root[k], n);\n      b = multipoint_eval_on_geom_seq(b,\
    \ mint(1), root[k], n);\n      FOR(j, n) {\n        f[i + step * j] = a[j];\n\
    \        g[i + step * j] = b[j];\n      }\n    }\n    step *= n;\n  }\n\n  FOR(i,\
    \ N) f[i] *= g[i];\n\n  step = 1;\n  FOR(k, K) {\n    int n = ns[k];\n    FOR(i,\
    \ N) if (i % (step * n) < step) {\n      vc<mint> a(n);\n      FOR(j, n) { a[j]\
    \ = f[i + step * j]; }\n      a = multipoint_eval_on_geom_seq(a, mint(1), iroot[k],\
    \ n);\n      FOR(j, n) { f[i + step * j] = a[j]; }\n    }\n    step *= n;\n  }\n\
    \n  mint cf = mint(N).inverse();\n  for (auto&& x: f) x *= cf;\n  return f;\n\
    }\n\ntemplate <typename mint>\nvc<vc<mint>> multivar_convolution_cyclic_2d(vc<vc<mint>>&\
    \ f, vc<vc<mint>>& g) {\n  int H = len(f);\n  int W = len(f[0]);\n  assert(len(g)\
    \ == H);\n  assert(len(g[0]) == W);\n  vc<mint> F(H * W), G(H * W);\n  FOR(x,\
    \ H) FOR(y, W) F[x + H * y] = f[x][y];\n  FOR(x, H) FOR(y, W) G[x + H * y] = g[x][y];\n\
    \  F = multivar_convolution_cyclic(vc<int>({H, W}), F, G);\n  vv(mint, h, H, W);\n\
    \  FOR(x, H) FOR(y, W) h[x][y] = F[x + H * y];\n  return h;\n}\n"
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
  - mod/primitive_root.hpp
  - nt/factor.hpp
  - nt/primetest.hpp
  - mod/mod_pow.hpp
  - random/base.hpp
  isVerificationFile: false
  path: poly/multivar_convolution_cyclic.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/multivariate_convolution_cyclic.test.cpp
documentation_of: poly/multivar_convolution_cyclic.hpp
layout: document
redirect_from:
- /library/poly/multivar_convolution_cyclic.hpp
- /library/poly/multivar_convolution_cyclic.hpp.html
title: poly/multivar_convolution_cyclic.hpp
---
