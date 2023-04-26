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
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/eulerian_number.test.cpp
    title: test/mytest/eulerian_number.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1821.test.cpp
    title: test/yukicoder/1821.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2005.test.cpp
    title: test/yukicoder/2005.test.cpp
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
  code: "#include \"mod/powertable.hpp\"\n#include \"poly/convolution.hpp\"\n\n//\
    \ Eulerian number\n// sum n^dx^n = A_d(x) / (1-x)^{d+1} \u3068\u306A\u308B d \u6B21\
    \u591A\u9805\u5F0F\u306E\u4FC2\u6570\u5217\ntemplate <typename mint>\nvvc<mint>\
    \ eulerian_number_2d(int N, int K) {\n  vv(mint, A, N + 1, K + 1);\n  A[0][0]\
    \ = mint(1);\n  FOR(d, N) FOR(k, 1, K + 1) {\n    A[d + 1][k] = mint(k) * A[d][k]\
    \ + mint(d - k + 2) * A[d][k - 1];\n  }\n  return A;\n}\n\ntemplate <typename\
    \ mint>\nvc<mint> eulerian_number_n(int n) {\n  vc<mint> f = powertable_2<mint>(n,\
    \ n);\n  vc<mint> g(n + 1);\n  FOR(k, n + 1) g[k] = C<mint>(n + 1, k);\n  FOR(k,\
    \ 1, n + 1, 2) g[k] = -g[k];\n  f = convolution(f, g);\n  f.resize(n + 1);\n \
    \ return f;\n}"
  dependsOn:
  - mod/powertable.hpp
  - nt/primetable.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: seq/famous/eulerian_number.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2005.test.cpp
  - test/yukicoder/1821.test.cpp
  - test/mytest/eulerian_number.test.cpp
documentation_of: seq/famous/eulerian_number.hpp
layout: document
redirect_from:
- /library/seq/famous/eulerian_number.hpp
- /library/seq/famous/eulerian_number.hpp.html
title: seq/famous/eulerian_number.hpp
---
