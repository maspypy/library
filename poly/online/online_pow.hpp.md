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
  - icon: ':x:'
    path: poly/online/online_convolution.hpp
    title: poly/online/online_convolution.hpp
  - icon: ':x:'
    path: poly/online/online_division.hpp
    title: poly/online/online_division.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/online_pow.test.cpp
    title: test/mytest/online_pow.test.cpp
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
    \  [Previous line repeated 1 more time]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"poly/online/online_division.hpp\"\n\n// query(i)\uFF1Af[i] \u3092\
    \u4E0E\u3048\u3066 (f^K)[i] \u3092\u5F97\u308B\u3002\n// f[0] == 1 \u3092\u4EEE\
    \u5B9A\u3059\u308B\u3002\ntemplate <typename mint>\nstruct Online_Pow {\n  vc<mint>\
    \ f, F;\n  vc<mint> g; // f'/f\n  const mint K;\n  Online_Division<mint> X;\n\
    \  Online_Convolution<mint> Y;\n\n  Online_Pow(mint K) : K(K) {}\n\n  mint query(int\
    \ i, mint f_i) {\n    assert(i == len(f));\n    f.eb(f_i);\n    if (i == 0) {\n\
    \      assert(f_i == mint(1));\n      F.eb(f_i);\n      return F[0];\n    }\n\
    \    g.eb(X.query(i - 1, f[i] * mint(i), f[i - 1]));\n    F.eb(Y.query(i - 1,\
    \ g[i - 1], F[i - 1]) * K * inv<mint>(i));\n    return F[i];\n  }\n};\n"
  dependsOn:
  - poly/online/online_division.hpp
  - poly/online/online_convolution.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/online/online_pow.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/online_pow.test.cpp
documentation_of: poly/online/online_pow.hpp
layout: document
redirect_from:
- /library/poly/online/online_pow.hpp
- /library/poly/online/online_pow.hpp.html
title: poly/online/online_pow.hpp
---
