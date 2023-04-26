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
    path: poly/integrate.hpp
    title: poly/integrate.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/math/sharp_p_subset_sum.test.cpp
    title: test/library_checker/math/sharp_p_subset_sum.test.cpp
  - icon: ':x:'
    path: test/mytest/product_of_one_pm_xn.test.cpp
    title: test/mytest/product_of_one_pm_xn.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2062.test.cpp
    title: test/yukicoder/2062.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc267h.test.cpp
    title: test_atcoder/abc267h.test.cpp
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
  code: "#include \"poly/fps_exp.hpp\"\r\n\r\n// prod (1 + x^a) \u3092 x^{LIM} \u307E\
    \u3067\u6C42\u3081\u308B\r\ntemplate <typename mint, typename INT>\r\nvc<mint>\
    \ product_of_one_plus_xn(vc<INT> A, int LIM) {\r\n  vc<int> CNT(LIM + 1);\r\n\
    \  for (auto&& x: A) {\r\n    if (x <= LIM) CNT[x]++;\r\n  }\r\n\r\n  vc<mint>\
    \ logf(LIM + 1);\r\n  FOR3(x, 1, LIM + 1) {\r\n    FOR3(d, 1, LIM / x + 1) {\r\
    \n      if (d & 1)\r\n        logf[d * x] += mint(CNT[x]) * inv<mint>(d);\r\n\
    \      else\r\n        logf[d * x] -= mint(CNT[x]) * inv<mint>(d);\r\n    }\r\n\
    \  }\r\n  auto f = fps_exp(logf);\r\n  mint c = mint(2).pow(CNT[0]);\r\n  for\
    \ (auto&& x: f) x *= c;\r\n  return f;\r\n}"
  dependsOn:
  - poly/fps_exp.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - poly/integrate.hpp
  - poly/differentiate.hpp
  - poly/count_terms.hpp
  isVerificationFile: false
  path: poly/product_of_one_plus_xn.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc267h.test.cpp
  - test/yukicoder/2062.test.cpp
  - test/library_checker/math/sharp_p_subset_sum.test.cpp
  - test/mytest/product_of_one_pm_xn.test.cpp
documentation_of: poly/product_of_one_plus_xn.hpp
layout: document
redirect_from:
- /library/poly/product_of_one_plus_xn.hpp
- /library/poly/product_of_one_plus_xn.hpp.html
title: poly/product_of_one_plus_xn.hpp
---
