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
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetable.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"poly/poly_taylor_shift.hpp\"\n\n// x^nf(x+1/x), O(logN) time\n\
    // 2^17: 0.1sec, 2^20: 0.8 sec\ntemplate <typename mint>\nvc<mint> composition_f_x_plus_1x(vc<mint>\
    \ f) {\n  int n = len(f) - 1;\n  f = poly_taylor_shift<mint>(f, 2);\n  reverse(all(f));\n\
    \  f = poly_taylor_shift(f, -inv<mint>(4));\n  f.resize(2 * n + 1);\n  FOR_R(i,\
    \ n + 1) f[2 * i] = f[i];\n  FOR(i, n) f[2 * i + 1] = 0;\n  f = poly_taylor_shift(f,\
    \ inv<mint>(2));\n  reverse(all(f));\n  f = poly_taylor_shift<mint>(f, -1);\n\
    \  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/composition_f_x_plus_1x.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/composition_f_x_plus_1x.hpp
layout: document
redirect_from:
- /library/poly/composition_f_x_plus_1x.hpp
- /library/poly/composition_f_x_plus_1x.hpp.html
title: poly/composition_f_x_plus_1x.hpp
---
