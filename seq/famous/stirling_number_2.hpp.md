---
data:
  _extendedDependsOn:
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
  - icon: ':x:'
    path: mod/powertable.hpp
    title: mod/powertable.hpp
  - icon: ':question:'
    path: nt/primetable.hpp
    title: nt/primetable.hpp
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':x:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':x:'
    path: poly/differentiate.hpp
    title: poly/differentiate.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/fps_exp.hpp
    title: poly/fps_exp.hpp
  - icon: ':x:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':x:'
    path: poly/fps_log.hpp
    title: poly/fps_log.hpp
  - icon: ':x:'
    path: poly/fps_pow.hpp
    title: poly/fps_pow.hpp
  - icon: ':x:'
    path: poly/integrate.hpp
    title: poly/integrate.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: seq/famous/surjection.hpp
    title: seq/famous/surjection.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
    title: test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - icon: ':x:'
    path: test/mytest/bell.test.cpp
    title: test/mytest/bell.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1321.test.cpp
    title: test/yukicoder/1321.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1392.test.cpp
    title: test/yukicoder/1392.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc153f.test.cpp
    title: test_atcoder/arc153f.test.cpp
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
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
  dependsOn:
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - poly/fps_pow.hpp
  - poly/count_terms.hpp
  - poly/fps_exp.hpp
  - poly/integrate.hpp
  - poly/differentiate.hpp
  - poly/fps_log.hpp
  - poly/fps_inv.hpp
  - mod/powertable.hpp
  - nt/primetable.hpp
  isVerificationFile: false
  path: seq/famous/stirling_number_2.hpp
  requiredBy:
  - seq/famous/surjection.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/arc153f.test.cpp
  - test/yukicoder/1392.test.cpp
  - test/yukicoder/1321.test.cpp
  - test/library_checker/math/stirling_number_of_the_second_kind.test.cpp
  - test/mytest/bell.test.cpp
documentation_of: seq/famous/stirling_number_2.hpp
layout: document
redirect_from:
- /library/seq/famous/stirling_number_2.hpp
- /library/seq/famous/stirling_number_2.hpp.html
title: seq/famous/stirling_number_2.hpp
---
