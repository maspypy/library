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
  code: "#pragma once\r\n#include \"alg/monoid/mul.hpp\"\r\n#include \"ds/sliding_window_aggregation.hpp\"\
    \r\n#include \"poly/convolution.hpp\"\r\n\r\n// Input: f(0), ..., f(n-1) and c.\
    \ Return: f(c)\r\ntemplate <typename T, typename enable_if<has_mod<T>::value>::type\
    \ * = nullptr>\r\nT lagrange_interpolate_iota(vc<T> &f, T c) {\r\n  int n = len(f);\r\
    \n  if (int(c.val) < n) return f[c.val];\r\n  auto a = f;\r\n  FOR(i, n) {\r\n\
    \    a[i] = a[i] * fact_inv<T>(i) * fact_inv<T>(n - 1 - i);\r\n    if ((n - 1\
    \ - i) & 1) a[i] = -a[i];\r\n  }\r\n  vc<T> lp(n + 1), rp(n + 1);\r\n  lp[0] =\
    \ rp[n] = 1;\r\n  FOR(i, n) lp[i + 1] = lp[i] * (c - i);\r\n  FOR_R(i, n) rp[i]\
    \ = rp[i + 1] * (c - i);\r\n  T ANS = 0;\r\n  FOR(i, n) ANS += a[i] * lp[i] *\
    \ rp[i + 1];\r\n  return ANS;\r\n}\r\n\r\n// mod \u3058\u3083\u306A\u3044\u5834\
    \u5408\u3002\u304B\u306A\u308A\u4F4E\u6B21\u306E\u591A\u9805\u5F0F\u3092\u60F3\
    \u5B9A\u3057\u3066\u3044\u308B\u3002O(n^2)\r\n// Input: f(0), ..., f(n-1) and\
    \ c. Return: f(c)\r\ntemplate <typename T, typename enable_if<!has_mod<T>::value>::type\
    \ * = nullptr>\r\nT lagrange_interpolate_iota(vc<T> &f, T c) {\r\n  const int\
    \ LIM = 10;\r\n  int n = len(f);\r\n  assert(n < LIM);\r\n\r\n  // (-1)^{i-j}\
    \ binom(i,j)\r\n  static vvc<int> C;\r\n  if (C.empty()) {\r\n    C.assign(LIM,\
    \ vc<int>(LIM));\r\n    C[0][0] = 1;\r\n    FOR(n, 1, LIM) FOR(k, n + 1) {\r\n\
    \      C[n][k] += C[n - 1][k];\r\n      if (k) C[n][k] += C[n - 1][k - 1];\r\n\
    \    }\r\n    FOR(n, LIM) FOR(k, n + 1) if ((n + k) % 2) C[n][k] = -C[n][k];\r\
    \n  }\r\n  // f(x) = sum a_i binom(x,i)\r\n  vc<T> a(n);\r\n  FOR(i, n) FOR(j,\
    \ i + 1) { a[i] += f[j] * C[i][j]; }\r\n\r\n  T res = 0;\r\n  T b = 1;\r\n  FOR(i,\
    \ n) {\r\n    res += a[i] * b;\r\n    b = b * (c - i) / (1 + i);\r\n  }\r\n  return\
    \ res;\r\n}\r\n\r\n// Input: f(0), ..., f(n-1) and c, m\r\n// Return: f(c), f(c+1),\
    \ ..., f(c+m-1)\r\n// Complexity: M(n, n + m)\r\ntemplate <typename mint>\r\n\
    vc<mint> lagrange_interpolate_iota(vc<mint> &f, mint c, int m) {\r\n  if (m <=\
    \ 60) {\r\n    vc<mint> ANS(m);\r\n    FOR(i, m) ANS[i] = lagrange_interpolate_iota(f,\
    \ c + mint(i));\r\n    return ANS;\r\n  }\r\n  ll n = len(f);\r\n  auto a = f;\r\
    \n  FOR(i, n) {\r\n    a[i] = a[i] * fact_inv<mint>(i) * fact_inv<mint>(n - 1\
    \ - i);\r\n    if ((n - 1 - i) & 1) a[i] = -a[i];\r\n  }\r\n  // x = c, c+1, ...\
    \ \u306B\u5BFE\u3057\u3066 a0/x + a1/(x-1) + ... \u3092\u6C42\u3081\u3066\u304A\
    \u304F\r\n  vc<mint> b(n + m - 1);\r\n  FOR(i, n + m - 1) b[i] = mint(1) / (c\
    \ + mint(i - n + 1));\r\n  a = convolution(a, b);\r\n\r\n  Sliding_Window_Aggregation<Monoid_Mul<mint>>\
    \ swag;\r\n  vc<mint> ANS(m);\r\n  ll L = 0, R = 0;\r\n  FOR(i, m) {\r\n    while\
    \ (L < i) { swag.pop(), ++L; }\r\n    while (R - L < n) { swag.push(c + mint((R++)\
    \ - n + 1)); }\r\n    auto coef = swag.prod();\r\n    if (coef == 0) {\r\n   \
    \   ANS[i] = f[(c + i).val];\r\n    } else {\r\n      ANS[i] = a[i + n - 1] *\
    \ coef;\r\n    }\r\n  }\r\n  return ANS;\r\n}\r\n"
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
