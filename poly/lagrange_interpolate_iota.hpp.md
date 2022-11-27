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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.0/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: alg/group/mul.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\r\n#include \"alg/group/mul.hpp\"\r\n#include \"ds/swag.hpp\"\
    \r\n#include \"poly/convolution.hpp\"\r\n\r\ntemplate <typename mint>\r\nvc<mint>\
    \ lagrange_interpolate_iota(vc<mint> &f, mint c, int m) {\r\n  /*\r\n  Input:\
    \ f(0), ..., f(n-1) and c, m (1 default)\r\n  Return: f(c), f(c+1), ..., f(c+m-1)\r\
    \n  Complexity: M(n, n + m)\r\n  \u2192 m \u304C\u3068\u3066\u3082\u5C0F\u3055\
    \u3044\u306A\u3089\u3070 O(n) \u3092 m \u56DE\u3084\u308B\u65B9\u304C\u901F\u3044\
    \u306E\u304B\r\n  */\r\n  if (m <= 60) {\r\n    vc<mint> ANS(m);\r\n    FOR(i,\
    \ m) ANS[i] = lagrange_interpolate_iota(f, c + mint(i));\r\n    return ANS;\r\n\
    \  }\r\n  ll n = len(f);\r\n  auto a = f;\r\n  FOR(i, n) {\r\n    a[i] = a[i]\
    \ * fact_inv<mint>(i) * fact_inv<mint>(n - 1 - i);\r\n    if ((n - 1 - i) & 1)\
    \ a[i] = -a[i];\r\n  }\r\n  // x = c, c+1, ... \u306B\u5BFE\u3057\u3066 a0/x +\
    \ a1/(x-1) + ... \u3092\u6C42\u3081\u3066\u304A\u304F\r\n  vc<mint> b(n + m -\
    \ 1);\r\n  FOR(i, n + m - 1) b[i] = mint(1) / (c + mint(i - n + 1));\r\n  a =\
    \ convolution(a, b);\r\n\r\n  SWAG<Monoid_Mul<mint>> swag;\r\n  vc<mint> ANS(m);\r\
    \n  ll L = 0, R = 0;\r\n  FOR(i, m) {\r\n    while (L < i) { swag.pop(), ++L;\
    \ }\r\n    while (R - L < n) { swag.push(c + mint((R++) - n + 1)); }\r\n    auto\
    \ coef = swag.prod();\r\n    if (coef == 0) {\r\n      ANS[i] = f[(c + i).val];\r\
    \n    } else {\r\n      ANS[i] = a[i + n - 1] * coef;\r\n    }\r\n  }\r\n  return\
    \ ANS;\r\n}\r\n\r\ntemplate <typename mint>\r\nmint lagrange_interpolate_iota(vc<mint>\
    \ &f, mint c) {\r\n  /*\r\n  Input: f(0), ..., f(n-1) and c\r\n  Return: f(c)\r\
    \n  Complexity: O(n)\r\n  */\r\n  int n = len(f);\r\n  if (int(c.val) < n) return\
    \ f[c.val];\r\n  auto a = f;\r\n  FOR(i, n) {\r\n    a[i] = a[i] * fact_inv<mint>(i)\
    \ * fact_inv<mint>(n - 1 - i);\r\n    if ((n - 1 - i) & 1) a[i] = -a[i];\r\n \
    \ }\r\n  vc<mint> lp(n + 1), rp(n + 1);\r\n  lp[0] = rp[n] = 1;\r\n  FOR(i, n)\
    \ lp[i + 1] = lp[i] * (c - i);\r\n  FOR_R(i, n) rp[i] = rp[i + 1] * (c - i);\r\
    \n  mint ANS = 0;\r\n  FOR(i, n) ANS += a[i] * lp[i] * rp[i + 1];\r\n  return\
    \ ANS;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/lagrange_interpolate_iota.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/lagrange_interpolate_iota.hpp
layout: document
redirect_from:
- /library/poly/lagrange_interpolate_iota.hpp
- /library/poly/lagrange_interpolate_iota.hpp.html
title: poly/lagrange_interpolate_iota.hpp
---
