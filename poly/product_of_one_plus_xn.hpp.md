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
  code: "#include \"poly/fps_exp.hpp\"\r\n\r\n// prod (1 + x^a) \u3092 x^{LIM} \u307E\
    \u3067\u6C42\u3081\u308B\r\ntemplate <typename mint, typename INT>\r\nvc<mint>\
    \ product_of_one_plus_xn(vc<INT> A, int LIM) {\r\n  vc<int> CNT(LIM + 1);\r\n\
    \  for (auto&& x: A) {\r\n    if (x <= LIM) CNT[x]++;\r\n  }\r\n\r\n  vc<mint>\
    \ logf(LIM + 1);\r\n  FOR3(x, 1, LIM + 1) {\r\n    FOR3(d, 1, LIM / x + 1) {\r\
    \n      if (d & 1)\r\n        logf[d * x] += mint(CNT[x]) * inv<mint>(d);\r\n\
    \      else\r\n        logf[d * x] -= mint(CNT[x]) * inv<mint>(d);\r\n    }\r\n\
    \  }\r\n  auto f = fps_exp(logf);\r\n  mint c = mint(2).pow(CNT[0]);\r\n  for\
    \ (auto&& x: f) x *= c;\r\n  return f;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/product_of_one_plus_xn.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/product_of_one_plus_xn.hpp
layout: document
redirect_from:
- /library/poly/product_of_one_plus_xn.hpp
- /library/poly/product_of_one_plus_xn.hpp.html
title: poly/product_of_one_plus_xn.hpp
---
