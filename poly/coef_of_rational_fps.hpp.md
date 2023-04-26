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
    path: seq/famous/bell_number_large.hpp
    title: seq/famous/bell_number_large.hpp
  - icon: ':x:'
    path: seq/interpolate_linear_rec.hpp
    title: seq/interpolate_linear_rec.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
    title: test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - icon: ':x:'
    path: test/mytest/bell.test.cpp
    title: test/mytest/bell.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1500.test.cpp
    title: test/yukicoder/1500.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1516.test.cpp
    title: test/yukicoder/1516.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1547.test.cpp
    title: test/yukicoder/1547.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1561.test.cpp
    title: test/yukicoder/1561.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1844.test.cpp
    title: test/yukicoder/1844.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1962.test.cpp
    title: test/yukicoder/1962.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2122.test.cpp
    title: test/yukicoder/2122.test.cpp
  - icon: ':x:'
    path: test/yukicoder/541.test.cpp
    title: test/yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/yukicoder/578.test.cpp
    title: test/yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/yukicoder/579.test.cpp
    title: test/yukicoder/579.test.cpp
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
  code: "#include \"poly/convolution.hpp\"\r\n\r\ntemplate <typename mint>\r\nmint\
    \ coef_of_rational_fps(vector<mint> A, vector<mint> B, ll N) {\r\n  if (len(A)\
    \ == 0) return 0;\r\n  assert(len(A) < len(B));\r\n  while (len(A) + 1 < len(B))\
    \ A.eb(0);\r\n  assert(B[0] == mint(1));\r\n  assert(len(B) == len(A) + 1);\r\n\
    \  while (N) {\r\n    vc<mint> B1 = B;\r\n    FOR(i, len(B1)) if (i & 1) B1[i]\
    \ = -B1[i];\r\n    A = convolution(A, B1);\r\n    B = convolution(B, B1);\r\n\
    \    FOR(i, len(B1)) B[i] = B[2 * i];\r\n    if (N & 1) {\r\n      FOR(i, len(B1)\
    \ - 1) A[i] = A[2 * i | 1];\r\n    } else {\r\n      FOR(i, len(B1) - 1) A[i]\
    \ = A[2 * i];\r\n    }\r\n    A.resize(len(B1) - 1);\r\n    B.resize(len(B1));\r\
    \n    N /= 2;\r\n  }\r\n  return A[0];\r\n}"
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
  path: poly/coef_of_rational_fps.hpp
  requiredBy:
  - seq/interpolate_linear_rec.hpp
  - seq/famous/bell_number_large.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1844.test.cpp
  - test/yukicoder/578.test.cpp
  - test/yukicoder/1561.test.cpp
  - test/yukicoder/1962.test.cpp
  - test/yukicoder/1516.test.cpp
  - test/yukicoder/1547.test.cpp
  - test/yukicoder/579.test.cpp
  - test/yukicoder/2122.test.cpp
  - test/yukicoder/541.test.cpp
  - test/yukicoder/1500.test.cpp
  - test/library_checker/math/kth_term_of_linearly_recurrent_sequence.test.cpp
  - test/mytest/bell.test.cpp
documentation_of: poly/coef_of_rational_fps.hpp
layout: document
redirect_from:
- /library/poly/coef_of_rational_fps.hpp
- /library/poly/coef_of_rational_fps.hpp.html
title: poly/coef_of_rational_fps.hpp
---
