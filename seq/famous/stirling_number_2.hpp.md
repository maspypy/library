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
  code: "#include \"poly/convolution.hpp\"\r\n#include \"poly/fps_pow.hpp\"\r\n#include\
    \ \"mod/powertable.hpp\"\r\n\r\n// n \u500B\u306E\u3082\u306E (labeled) \u3092\
    \ k \u30B0\u30EB\u30FC\u30D7 (no label) \u306B\u5206\u3051\u308B\u65B9\u6CD5\r\
    \n// label \u3092\u3064\u3051\u308B\u3053\u3068\u3067\u3001\u5168\u5C04\u306E\u6570\
    \u3048\u4E0A\u3052\u306B\u5229\u7528\u3067\u304D\u308B\r\ntemplate <typename mint>\r\
    \nvvc<mint> stirling_number_2_2d(int nmax, int kmax) {\r\n  vv(mint, A, nmax +\
    \ 1, kmax + 1);\r\n  A[0][0] = 1;\r\n  FOR(i, 1, nmax + 1) {\r\n    FOR(j, i +\
    \ 1) {\r\n      if (j > kmax) break;\r\n      if (j) A[i][j] += A[i - 1][j - 1];\r\
    \n      if (j < i) A[i][j] += A[i - 1][j] * mint(j);\r\n    }\r\n  }\r\n  return\
    \ A;\r\n}\r\n\r\n// n \u500B\u306E\u3082\u306E (labeled) \u3092 k \u30B0\u30EB\
    \u30FC\u30D7 (no label) \u306B\u5206\u3051\u308B\u65B9\u6CD5\r\n// label \u3092\
    \u3064\u3051\u308B\u3053\u3068\u3067\u3001\u5168\u5C04\u306E\u6570\u3048\u4E0A\
    \u3052\u306B\u5229\u7528\u3067\u304D\u308B\r\ntemplate <typename mint>\r\nvc<mint>\
    \ stirling_number_2_n(int n, int k_max) {\r\n  vc<mint> a = powertable_2<mint>(n,\
    \ k_max + 1);\r\n  FOR(i, k_max + 1) a[i] *= fact_inv<mint>(i);\r\n  vc<mint>\
    \ b(k_max + 1);\r\n  FOR(i, k_max + 1) b[i] = fact_inv<mint>(i);\r\n  FOR(i, 1,\
    \ k_max + 1, 2) b[i] = -b[i];\r\n  auto f = convolution(a, b);\r\n  f.resize(k_max\
    \ + 1);\r\n  return f;\r\n}\r\n\r\n// n \u500B\u306E\u3082\u306E (labeled) \u3092\
    \ k \u30B0\u30EB\u30FC\u30D7 (no label) \u306B\u5206\u3051\u308B\u65B9\u6CD5\r\
    \n// label \u3092\u3064\u3051\u308B\u3053\u3068\u3067\u3001\u5168\u5C04\u306E\u6570\
    \u3048\u4E0A\u3052\u306B\u5229\u7528\u3067\u304D\u308B\r\ntemplate <typename mint>\r\
    \nvc<mint> stirling_number_2_k(int k, int n_max) {\r\n  if (k > n_max) { return\
    \ vc<mint>(n_max + 1); }\r\n  int LIM = n_max - k;\r\n  vc<mint> f(LIM + 1);\r\
    \n  FOR(i, LIM + 1) f[i] = fact_inv<mint>(i + 1);\r\n  f = fps_pow(f, k);\r\n\
    \  mint cf = fact_inv<mint>(k);\r\n\r\n  vc<mint> res(n_max + 1);\r\n  FOR(i,\
    \ len(f)) res[k + i] = fact<mint>(k + i) * f[i] * cf;\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/famous/stirling_number_2.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: seq/famous/stirling_number_2.hpp
layout: document
redirect_from:
- /library/seq/famous/stirling_number_2.hpp
- /library/seq/famous/stirling_number_2.hpp.html
title: seq/famous/stirling_number_2.hpp
---
