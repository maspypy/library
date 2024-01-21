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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linalg/blackbox_matrix/min_poly.hpp:\
    \ line -1: no such header\n"
  code: "#include \"linalg/blackbox_matrix/min_poly.hpp\"\r\n\r\ntemplate <typename\
    \ mint, typename F>\r\nmint blackbox_matrix_det(int N, F apply) {\r\n  vc<mint>\
    \ c(N);\r\n  FOR(i, N) c[i] = RNG(1, mint::get_mod());\r\n  mint r = 1;\r\n  FOR(i,\
    \ N) r *= c[i];\r\n  auto g = [&](vc<mint> v) -> vc<mint> {\r\n    FOR(i, N) v[i]\
    \ *= c[i];\r\n    return apply(v);\r\n  };\r\n  auto f = implicit_matrix_min_poly<mint>(N,\
    \ g);\r\n  mint det = (len(f) == N + 1 ? f[0] : mint(0));\r\n  if (N & 1) det\
    \ *= -1;\r\n  det /= r;\r\n  return det;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/blackbox/det.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/blackbox/det.hpp
layout: document
redirect_from:
- /library/linalg/blackbox/det.hpp
- /library/linalg/blackbox/det.hpp.html
title: linalg/blackbox/det.hpp
---
