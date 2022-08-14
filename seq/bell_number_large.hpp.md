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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.6/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: seq/coef_of_rational_fps.hpp:\
    \ line -1: no such header\n"
  code: "#include \"seq/coef_of_rational_fps.hpp\"\n\n// Bell \u6570 B_n \u306E\u8A08\
    \u7B97\u3002O(p logp logn)\ntemplate <typename mint>\nmint Bell_Number_large(ll\
    \ n) {\n  int p = mint::get_mod();\n  vc<mint> f(p);\n  FOR(i, p) f[i] = fact_inv<mint>(i);\n\
    \  f[0] = 0;\n  f = fps_exp(f);\n  FOR(i, p) f[i] *= fact<mint>(i);\n  vc<mint>\
    \ g(p + 1);\n  g[0] = 1;\n  g[p - 1] = -1;\n  g[p] = -1;\n  f = convolution(f,\
    \ g);\n  f.resize(p);\n  return coef_of_rational_fps<mint>(f, g, n);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/bell_number_large.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/bell_number_large.hpp
layout: document
redirect_from:
- /library/seq/bell_number_large.hpp
- /library/seq/bell_number_large.hpp.html
title: seq/bell_number_large.hpp
---
