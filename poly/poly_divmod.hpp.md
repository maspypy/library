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
  code: "#include \"poly/fps_inv.hpp\"\r\ntemplate <typename mint>\r\npair<vc<mint>,\
    \ vc<mint>> poly_divmod(vc<mint> f, vc<mint> g) {\r\n  assert(g.back() != 0);\r\
    \n  if (len(f) < len(g)) { return {{}, f}; }\r\n  auto rf = f, rg = g;\r\n  reverse(all(rf)),\
    \ reverse(all(rg));\r\n  ll deg = len(rf) - len(rg) + 1;\r\n  rf.resize(deg),\
    \ rg.resize(deg);\r\n  rg = fps_inv(rg);\r\n  auto q = convolution(rf, rg);\r\n\
    \  q.resize(deg);\r\n  reverse(all(q));\r\n  auto h = convolution(q, g);\r\n \
    \ FOR(i, len(f)) f[i] -= h[i];\r\n  while (len(f) > 0 && f.back() == 0) f.pop_back();\r\
    \n  return {q, f};\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/poly_divmod.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/poly_divmod.hpp
layout: document
redirect_from:
- /library/poly/poly_divmod.hpp
- /library/poly/poly_divmod.hpp.html
title: poly/poly_divmod.hpp
---
