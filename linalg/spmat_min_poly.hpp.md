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
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: other/random.hpp:\
    \ line -1: no such header\n"
  code: "#include \"seq/find_linear_rec.hpp\"\r\n#include \"other/random.hpp\"\r\n\
    \r\ntemplate <typename mint>\r\nvc<mint> spmat_min_poly(int N, vc<tuple<int, int,\
    \ mint>> dat) {\r\n  vc<mint> S(N + N + 10);\r\n  vc<mint> c(N);\r\n  vc<mint>\
    \ v(N);\r\n  FOR(i, N) c[i] = RNG(0, mint::get_mod());\r\n  FOR(i, N) v[i] = RNG(0,\
    \ mint::get_mod());\r\n  FOR(k, N + N + 10) {\r\n    FOR(i, N) S[k] += c[i] *\
    \ v[i];\r\n    vc<mint> w(N);\r\n    for (auto&& [i, j, x]: dat) w[j] += x * v[i];\r\
    \n    swap(v, w);\r\n  }\r\n  return find_linear_rec(S);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/spmat_min_poly.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/spmat_min_poly.hpp
layout: document
redirect_from:
- /library/linalg/spmat_min_poly.hpp
- /library/linalg/spmat_min_poly.hpp.html
title: linalg/spmat_min_poly.hpp
---
