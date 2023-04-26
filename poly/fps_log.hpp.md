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
  code: "#pragma once\r\n\r\n#include \"poly/fps_inv.hpp\"\r\n#include \"poly/count_terms.hpp\"\
    \r\n\r\ntemplate <typename mint>\r\nvc<mint> fps_log_dense(const vc<mint>& f)\
    \ {\r\n  assert(f[0] == mint(1));\r\n  ll N = len(f);\r\n  vc<mint> df = f;\r\n\
    \  FOR(i, N) df[i] *= mint(i);\r\n  df.erase(df.begin());\r\n  auto f_inv = fps_inv(f);\r\
    \n  auto g = convolution(df, f_inv);\r\n  g.resize(N - 1);\r\n  g.insert(g.begin(),\
    \ 0);\r\n  FOR(i, N) g[i] *= inv<mint>(i);\r\n  return g;\r\n}\r\n\r\ntemplate<typename\
    \ mint>\r\nvc<mint> fps_log_sparse(const vc<mint>& f){\r\n  int N = f.size();\r\
    \n  vc<pair<int, mint>> dat;\r\n  FOR(i, 1, N) if(f[i] != mint(0)) dat.eb(i, f[i]);\r\
    \n\r\n  vc<mint> F(N);\r\n  vc<mint> g(N - 1);\r\n  for (int n = 0; n < N - 1;\
    \ ++n) {\r\n    mint rhs = mint(n + 1) * f[n + 1];\r\n    for (auto &&[i, fi]:\
    \ dat) {\r\n      if (i > n) break;\r\n      rhs -= fi * g[n - i];\r\n    }\r\n\
    \    g[n] = rhs;\r\n    F[n + 1] = rhs * inv<mint>(n + 1);\r\n  }\r\n  return\
    \ F;\r\n}\r\n\r\ntemplate<typename mint>\r\nvc<mint> fps_log(const vc<mint>& f){\r\
    \n  assert(f[0] == mint(1));\r\n  if(count_terms(f) <= 200) return fps_log_sparse(f);\r\
    \n  return fps_log_dense(f);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_log.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_log.hpp
layout: document
redirect_from:
- /library/poly/fps_log.hpp
- /library/poly/fps_log.hpp.html
title: poly/fps_log.hpp
---
