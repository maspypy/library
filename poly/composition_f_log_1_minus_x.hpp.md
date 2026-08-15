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
  code: "\n#include \"poly/poly_taylor_shift.hpp\"\n#include \"poly/partial_frac_decomposition_1.hpp\"\
    \n#include \"seq/famous/stirling_number_1.hpp\"\n\n/*\nf(log(1-x))\n2024/05/01\
    \ noshi\u5408\u6210\u306E\u65B9\u304C\u5C11\u3057\u9AD8\u901F\u306A\u306E\u3067\
    \u4F7F\u308F\u306A\u3044\u304C\nmultipoint \u3092\u9AD8\u901F\u5316\u3059\u308B\
    \u3068\u4F7F\u3048\u308B\u304B\u3082\n*/\ntemplate <typename mint>\nvc<mint> composition_f_log_1_minus_x(vc<mint>\
    \ f) {\n  int N = len(f) - 1;\n  FOR(i, N + 1) f[i] *= fact<mint>(i);\n  vc<mint>\
    \ S = stirling_number_1_n<mint>(N + 1, true);\n  reverse(all(S));\n  f = convolution<mint>(f,\
    \ S);\n  f.resize(N + 1);\n  vc<mint> A(N + 1);\n  FOR(i, N + 1) A[i] = mint::raw(i);\n\
    \  f = partial_frac_decomposition_1(f, A);\n  FOR(i, len(f)) if (i & 1) f[i] =\
    \ -f[i];\n  f = poly_taylor_shift<mint>(f, -1);\n  return f;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/composition_f_log_1_minus_x.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/composition_f_log_1_minus_x.hpp
layout: document
redirect_from:
- /library/poly/composition_f_log_1_minus_x.hpp
- /library/poly/composition_f_log_1_minus_x.hpp.html
title: poly/composition_f_log_1_minus_x.hpp
---
