---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':question:'
    path: ds/sliding_window_aggregation.hpp
    title: ds/sliding_window_aggregation.hpp
  - icon: ':question:'
    path: mod/barret.hpp
    title: mod/barret.hpp
  - icon: ':question:'
    path: mod/mod_inv.hpp
    title: mod/mod_inv.hpp
  - icon: ':question:'
    path: mod/modint.hpp
    title: mod/modint.hpp
  - icon: ':question:'
    path: mod/modint_common.hpp
    title: mod/modint_common.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  - icon: ':x:'
    path: seq/interpolate_poly_exp.hpp
    title: seq/interpolate_poly_exp.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/sum_of_exp_times_poly.test.cpp
    title: test/library_checker/math/sum_of_exp_times_poly.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"poly/lagrange_interpolate_iota.hpp\"\r\n#include \"seq/interpolate_poly_exp.hpp\"\
    \r\n\r\ntemplate <typename mint>\r\nmint interpolate_poly_exp_sum(vc<mint> a,\
    \ mint r, ll n) {\r\n  /*\r\n  a[i] = (prefix sum of r^i * (polynomial of i))\
    \ \u3068\u306A\u3063\u3066\u3044\u308B\u5834\u5408\u306E\u88DC\u9593\r\n  fps\
    \ \u3067\u306F (1-rx)^d(1-x) \u306E\u5F62\u306E\u5206\u6BCD\u3092\u6301\u3064\u5834\
    \u5408\u3068\u3044\u3046\u3053\u3068\u306B\u306A\u308B\r\n  f(x) = g(x) / (1-rx)^d\
    \ + c / (1-x) \u3068\u3057\u3066\u3001c \u304C\u77E5\u308A\u305F\u3044\r\n  (1-rx)^d\
    \ \u3092\u304B\u3051\u3066\u3001d \u6B21\u306E\u4FC2\u6570\u3092\u3068\u308C\u3070\
    \u3001c \u304C\u624B\u306B\u5165\u308B\r\n  */\r\n  if (r == mint(1)) return lagrange_interpolate_iota(a,\
    \ mint(n));\r\n  mint c = 0;\r\n  int d = len(a) - 1;\r\n  mint p = 1;\r\n  FOR(i,\
    \ d + 1) {\r\n    c += a[d - i] * p * C<mint>(d, i);\r\n    p *= -r;\r\n  }\r\n\
    \  c /= (mint(1) - r).pow(d);\r\n  for (auto&& x: a) x -= c;\r\n  return interpolate_poly_exp(a,\
    \ r, n) + c;\r\n}\r\n"
  dependsOn:
  - poly/lagrange_interpolate_iota.hpp
  - alg/monoid/mul.hpp
  - ds/sliding_window_aggregation.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - seq/interpolate_poly_exp.hpp
  isVerificationFile: false
  path: seq/interpolate_poly_exp_sum.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library_checker/math/sum_of_exp_times_poly.test.cpp
documentation_of: seq/interpolate_poly_exp_sum.hpp
layout: document
redirect_from:
- /library/seq/interpolate_poly_exp_sum.hpp
- /library/seq/interpolate_poly_exp_sum.hpp.html
title: seq/interpolate_poly_exp_sum.hpp
---
