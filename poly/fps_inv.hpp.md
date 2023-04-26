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
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include \"poly/count_terms.hpp\"\r\n#include \"poly/convolution.hpp\"\
    \r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_inv_sparse(const vc<mint>& f)\
    \ {\r\n  assert(f[0] != mint(0));\r\n  int N = len(f);\r\n  vc<pair<int, mint>>\
    \ dat;\r\n  FOR3(i, 1, N) if (f[i] != mint(0)) dat.eb(i, f[i]);\r\n  vc<mint>\
    \ g(N);\r\n  mint g0 = mint(1) / f[0];\r\n  g[0] = g0;\r\n  FOR3(n, 1, N) {\r\n\
    \    mint rhs = 0;\r\n    for (auto&& [k, fk]: dat) {\r\n      if (k > n) break;\r\
    \n      rhs -= fk * g[n - k];\r\n    }\r\n    g[n] = rhs * g0;\r\n  }\r\n  return\
    \ g;\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<is_same<mint, modint998>::value,\
    \ vc<mint>> fps_inv_dense(\r\n    const vc<mint>& F) {\r\n  assert(F[0] != mint(0));\r\
    \n  vc<mint> G = {mint(1) / F[0]};\r\n  G.reserve(len(F));\r\n  ll N = len(F),\
    \ n = 1;\r\n  while (n < N) {\r\n    vc<mint> f(2 * n), g(2 * n);\r\n    FOR(i,\
    \ min(N, 2 * n)) f[i] = F[i];\r\n    FOR(i, n) g[i] = G[i];\r\n    ntt(f, false);\r\
    \n    ntt(g, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\n    ntt(f, true);\r\
    \n    FOR(i, n) f[i] = 0;\r\n    ntt(f, false);\r\n    FOR(i, 2 * n) f[i] *= g[i];\r\
    \n    ntt(f, true);\r\n    FOR3(i, n, 2 * n) G.eb(f[i] * mint(-1));\r\n    n *=\
    \ 2;\r\n  }\r\n  G.resize(N);\r\n  return G;\r\n}\r\n\r\ntemplate <typename mint>\r\
    \nenable_if_t<!is_same<mint, modint998>::value, vc<mint>> fps_inv_dense(\r\n \
    \   const vc<mint>& F) {\r\n  int N = len(F);\r\n  assert(F[0] != mint(0));\r\n\
    \  vc<mint> R = {mint(1) / F[0]};\r\n  vc<mint> p;\r\n  int m = 1;\r\n  while\
    \ (m < N) {\r\n    p = convolution(R, R);\r\n    p.resize(m + m);\r\n    vc<mint>\
    \ f = {F.begin(), F.begin() + min(m + m, N)};\r\n    p = convolution(p, f);\r\n\
    \    R.resize(m + m);\r\n    FOR(i, m + m) R[i] = R[i] + R[i] - p[i];\r\n    m\
    \ += m;\r\n  }\r\n  R.resize(N);\r\n  return R;\r\n}\r\n\r\n\r\ntemplate <typename\
    \ mint>\r\nenable_if_t<is_same<mint, modint998>::value, vc<mint>> fps_inv(\r\n\
    \    const vc<mint>& f) {\r\n  if (count_terms(f) <= 200) return fps_inv_sparse<mint>(f);\r\
    \n  return fps_inv_dense<mint>(f);\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> fps_inv(\r\n    const vc<mint>& f) {\r\n  if (count_terms(f)\
    \ <= 700) return fps_inv_sparse<mint>(f);\r\n  return fps_inv_dense<mint>(f);\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_inv.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_inv.hpp
layout: document
redirect_from:
- /library/poly/fps_inv.hpp
- /library/poly/fps_inv.hpp.html
title: poly/fps_inv.hpp
---
