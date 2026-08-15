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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n\r\n#include \"mod/powertable.hpp\"\r\n#include \"poly/convolution.hpp\"\
    \r\n\r\n// f(x) -> f(x+c)\r\ntemplate <typename mint>\r\nvc<mint> poly_taylor_shift(vc<mint>\
    \ f, mint c) {\r\n  if (c == mint(0)) return f;\r\n  ll N = len(f);\r\n  FOR(i,\
    \ N) f[i] *= fact<mint>(i);\r\n  auto b = powertable_1<mint>(c, N);\r\n  FOR(i,\
    \ N) b[i] *= fact_inv<mint>(i);\r\n  reverse(all(f));\r\n  f = convolution(f,\
    \ b);\r\n  f.resize(N);\r\n  reverse(all(f));\r\n  FOR(i, N) f[i] *= fact_inv<mint>(i);\r\
    \n  return f;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/poly_taylor_shift.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/poly_taylor_shift.hpp
layout: document
redirect_from:
- /library/poly/poly_taylor_shift.hpp
- /library/poly/poly_taylor_shift.hpp.html
title: poly/poly_taylor_shift.hpp
---
