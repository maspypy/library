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
  code: "#pragma once\n#include \"poly/online/online_convolution.hpp\"\n\n// query(i)\uFF1A\
    a[i], b[i] \u3092\u4E0E\u3048\u3066 (f/g)[i] \u3092\u5F97\u308B\u3002\n// g[0]\
    \ == 1 \u3092\u4EEE\u5B9A\u3059\u308B\ntemplate <typename mint>\nstruct Online_Division\
    \ {\n  vc<mint> f, g, F;\n  Online_Convolution<mint> X;\n\n  mint query(int i,\
    \ mint f_i, mint g_i) {\n    assert(i == len(f));\n    f.eb(f_i);\n    g.eb(g_i);\n\
    \    if (i == 0) {\n      assert(g_i == mint(1));\n      F.eb(f_i);\n      return\
    \ F[0];\n    }\n    F.eb(f[i] - X.query(i - 1, F[i - 1], g[i]));\n    return F[i];\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: poly/online/online_division.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/online/online_division.hpp
layout: document
redirect_from:
- /library/poly/online/online_division.hpp
- /library/poly/online/online_division.hpp.html
title: poly/online/online_division.hpp
---
