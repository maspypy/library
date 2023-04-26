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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
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
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_sqrt.hpp
layout: document
redirect_from:
- /library/poly/fps_sqrt.hpp
- /library/poly/fps_sqrt.hpp.html
title: poly/fps_sqrt.hpp
---
