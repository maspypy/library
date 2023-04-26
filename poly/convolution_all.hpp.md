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
  - icon: ':question:'
    path: poly/convolution.hpp
    title: poly/convolution.hpp
  - icon: ':question:'
    path: poly/convolution_naive.hpp
    title: poly/convolution_naive.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: seq/sum_of_powers.hpp
    title: seq/sum_of_powers.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
    title: test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1145.test.cpp
    title: test/yukicoder/1145.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1392.test.cpp
    title: test/yukicoder/1392.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1857.test.cpp
    title: test/yukicoder/1857.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2243.test.cpp
    title: test/yukicoder/2243.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc267g.test.cpp
    title: test_atcoder/abc267g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc269ex.test.cpp
    title: test_atcoder/abc269ex.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc272_h.test.cpp
    title: test_atcoder/abc272_h.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc154f.test.cpp
    title: test_atcoder/arc154f.test.cpp
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
  code: "#pragma once\r\n\r\n#include \"poly/convolution.hpp\"\r\n\r\ntemplate <typename\
    \ T>\r\nvc<T> convolution_all(vc<vc<T>>& polys) {\r\n  if (len(polys) == 0) return\
    \ {T(1)};\r\n  while (1) {\r\n    int n = len(polys);\r\n    if (n == 1) break;\r\
    \n    int m = ceil(n, 2);\r\n    FOR(i, m) {\r\n      if (2 * i + 1 == n) {\r\n\
    \        polys[i] = polys[2 * i];\r\n      } else {\r\n        polys[i] = convolution(polys[2\
    \ * i], polys[2 * i + 1]);\r\n      }\r\n    }\r\n    polys.resize(m);\r\n  }\r\
    \n  return polys[0];\r\n}\r\n"
  dependsOn:
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/convolution_all.hpp
  requiredBy:
  - seq/sum_of_powers.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc272_h.test.cpp
  - test_atcoder/arc154f.test.cpp
  - test_atcoder/abc269ex.test.cpp
  - test_atcoder/abc267g.test.cpp
  - test/yukicoder/1392.test.cpp
  - test/yukicoder/1857.test.cpp
  - test/yukicoder/2243.test.cpp
  - test/yukicoder/1145.test.cpp
  - test/library_checker/polynomial/product_of_polynomial_sequence.test.cpp
documentation_of: poly/convolution_all.hpp
layout: document
redirect_from:
- /library/poly/convolution_all.hpp
- /library/poly/convolution_all.hpp.html
title: poly/convolution_all.hpp
---
