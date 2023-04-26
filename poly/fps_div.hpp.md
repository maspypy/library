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
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_div.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_div.hpp
layout: document
redirect_from:
- /library/poly/fps_div.hpp
- /library/poly/fps_div.hpp.html
title: poly/fps_div.hpp
---
