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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.8/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#include \"linalg/spmat_min_poly.hpp\"\r\n\r\ntemplate <typename T>\r\nT\
    \ spmat_det(int N, vc<tuple<int, int, T>> dat) {\r\n  vc<T> c(N);\r\n  FOR(i,\
    \ N) c[i] = RNG(1, T::get_mod());\r\n  T r = 1;\r\n  FOR(i, N) r *= c[i];\r\n\
    \  for (auto&& [i, j, x]: dat) x *= c[i];\r\n  auto f = spmat_min_poly(N, dat);\r\
    \n  f.resize(N + 1);\r\n  T det = f.back();\r\n  if (N & 1) det *= -1;\r\n  det\
    \ /= r;\r\n  return det;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/spmat_det.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/spmat_det.hpp
layout: document
redirect_from:
- /library/linalg/spmat_det.hpp
- /library/linalg/spmat_det.hpp.html
title: linalg/spmat_det.hpp
---
