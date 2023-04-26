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
    path: mod/mod_sqrt.hpp
    title: mod/mod_sqrt.hpp
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
  - icon: ':x:'
    path: poly/differentiate.hpp
    title: poly/differentiate.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':x:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':x:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':x:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':x:'
    path: poly/integrate.hpp
    title: poly/integrate.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':question:'
    path: random/base.hpp
    title: random/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - icon: ':x:'
    path: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
    title: test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
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
  code: "#include \"poly/fps_inv.hpp\"\r\n#include \"poly/fps_pow.hpp\"\r\n#include\
    \ \"poly/count_terms.hpp\"\r\n#include \"mod/mod_sqrt.hpp\"\r\n\r\ntemplate <typename\
    \ mint>\r\nvc<mint> fps_sqrt_dense(vc<mint>& f) {\r\n  assert(f[0] == mint(1));\r\
    \n  int n = len(f);\r\n  vc<mint> R = {1};\r\n  while (len(R) < n) {\r\n    int\
    \ m = min(2 * int(len(R)), n);\r\n    R.resize(m);\r\n    vc<mint> tmp = {f.begin(),\
    \ f.begin() + m};\r\n    tmp = convolution(tmp, fps_inv(R));\r\n    tmp.resize(m);\r\
    \n    FOR(i, m) R[i] += tmp[i];\r\n    mint c = mint(1) / mint(2);\r\n    FOR(i,\
    \ len(R)) R[i] *= c;\r\n  }\r\n  R.resize(n);\r\n  return R;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nvc<mint> fps_sqrt_sparse(vc<mint>& f) {\r\n  return fps_pow_1_sparse(f,\
    \ inv<mint>(2));\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_sqrt(vc<mint>&\
    \ f) {\r\n  if (count_terms(f) <= 200) return fps_sqrt_sparse(f);\r\n  return\
    \ fps_sqrt_dense(f);\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_sqrt_any(vc<mint>&\
    \ f) {\r\n  int n = len(f);\r\n  int d = n;\r\n  FOR_R(i, n) if (f[i] != 0) d\
    \ = i;\r\n  if (d == n) return f;\r\n  if (d & 1) return {};\r\n  mint y = f[d];\r\
    \n  mint x = mod_sqrt(y);\r\n  if (x * x != y) return {};\r\n  mint c = mint(1)\
    \ / y;\r\n  vc<mint> g(n - d);\r\n  FOR(i, n - d) g[i] = f[d + i] * c;\r\n  g\
    \ = fps_sqrt(g);\r\n  FOR(i, len(g)) g[i] *= x;\r\n  g.resize(n);\r\n  FOR_R(i,\
    \ n) {\r\n    if (i >= d / 2)\r\n      g[i] = g[i - d / 2];\r\n    else\r\n  \
    \    g[i] = 0;\r\n  }\r\n  return g;\r\n}\r\n"
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
  - poly/fps_pow.hpp
  - poly/fps_exp.hpp
  - poly/integrate.hpp
  - poly/differentiate.hpp
  - poly/fps_log.hpp
  - mod/mod_sqrt.hpp
  - random/base.hpp
  isVerificationFile: false
  path: poly/fps_sqrt.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/polynomial/sqrt_of_fps.test.cpp
  - test/library_checker/polynomial/sqrt_of_fps_sparse.test.cpp
documentation_of: poly/fps_sqrt.hpp
layout: document
redirect_from:
- /library/poly/fps_sqrt.hpp
- /library/poly/fps_sqrt.hpp.html
title: poly/fps_sqrt.hpp
---
