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
  code: "#include \"poly/convolution.hpp\"\r\n\r\ntemplate <typename T>\r\nvc<vc<T>>\
    \ convolution2d(vc<vc<T>>& f, vc<vc<T>>& g) {\r\n  auto shape = [&](vc<vc<T>>&\
    \ f) -> pi {\r\n    ll H = len(f);\r\n    ll W = (H == 0 ? 0 : len(f[0]));\r\n\
    \    return {H, W};\r\n  };\r\n  auto [H1, W1] = shape(f);\r\n  auto [H2, W2]\
    \ = shape(g);\r\n  ll H = H1 + H2 - 1;\r\n  ll W = W1 + W2 - 1;\r\n\r\n  vc<T>\
    \ ff(H1 * W);\r\n  vc<T> gg(H2 * W);\r\n  FOR(x, H1) FOR(y, W1) ff[W * x + y]\
    \ = f[x][y];\r\n  FOR(x, H2) FOR(y, W2) gg[W * x + y] = g[x][y];\r\n  auto hh\
    \ = convolution(ff, gg);\r\n  vc<vc<T>> h(H, vc<T>(W));\r\n  FOR(x, H) FOR(y,\
    \ W) h[x][y] = hh[W * x + y];\r\n  return h;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution2d.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution2d.hpp
layout: document
redirect_from:
- /library/poly/convolution2d.hpp
- /library/poly/convolution2d.hpp.html
title: poly/convolution2d.hpp
---
