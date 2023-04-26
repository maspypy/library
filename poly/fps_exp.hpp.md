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
  code: "#pragma once\r\n#include \"poly/convolution.hpp\"\r\n#include \"poly/integrate.hpp\"\
    \r\n#include \"poly/differentiate.hpp\"\r\n#include \"poly/count_terms.hpp\"\r\
    \n\r\ntemplate <typename mint>\r\nenable_if_t<is_same<mint, modint998>::value,\
    \ vc<mint>> fps_exp(vc<mint>& f) {\r\n  if (count_terms(f) <= 300) return fps_exp_sparse(f);\r\
    \n  return fps_exp_dense(f);\r\n}\r\n\r\ntemplate <typename mint>\r\nenable_if_t<!is_same<mint,\
    \ modint998>::value, vc<mint>> fps_exp(vc<mint>& f) {\r\n  if (count_terms(f)\
    \ <= 1000) return fps_exp_sparse(f);\r\n  return fps_exp_dense(f);\r\n}\r\n\r\n\
    template <typename mint>\r\nvc<mint> fps_exp_sparse(vc<mint>& f) {\r\n  if (len(f)\
    \ == 0) return {mint(1)};\r\n  assert(f[0] == 0);\r\n  int N = len(f);\r\n  //\
    \ df \u3092\u6301\u305F\u305B\u308B\r\n  vc<pair<int, mint>> dat;\r\n  FOR(i,\
    \ 1, N) if (f[i] != mint(0)) dat.eb(i - 1, mint(i) * f[i]);\r\n  vc<mint> F(N);\r\
    \n  F[0] = 1;\r\n  FOR(n, 1, N) {\r\n    mint rhs = 0;\r\n    for (auto&& [k,\
    \ fk]: dat) {\r\n      if (k > n - 1) break;\r\n      rhs += fk * F[n - 1 - k];\r\
    \n    }\r\n    F[n] = rhs * inv<mint>(n);\r\n  }\r\n  return F;\r\n}\r\n\r\ntemplate\
    \ <typename mint>\r\nenable_if_t<!is_same<mint, modint998>::value, vc<mint>> fps_exp_dense(\r\
    \n    vc<mint> h) {\r\n  const int L = len(h);\r\n  assert(L > 0 && h[0] == mint(0));\r\
    \n  int LOG = 0;\r\n  while (1 << LOG < L) ++LOG;\r\n  h.resize(1 << LOG);\r\n\
    \  auto dh = differentiate(h);\r\n  vc<mint> f = {1}, g = {1};\r\n  int m = 1;\r\
    \n\r\n  vc<mint> p;\r\n\r\n  FOR(LOG) {\r\n    p = convolution(f, g);\r\n    p.resize(m);\r\
    \n    p = convolution(p, g);\r\n    p.resize(m);\r\n    g.resize(m);\r\n    FOR(i,\
    \ m) g[i] += g[i] - p[i];\r\n    p = {dh.begin(), dh.begin() + m - 1};\r\n   \
    \ p = convolution(f, p);\r\n    p.resize(m + m - 1);\r\n    FOR(i, m + m - 1)\
    \ p[i] = -p[i];\r\n    FOR(i, m - 1) p[i] += mint(i + 1) * f[i + 1];\r\n    p\
    \ = convolution(p, g);\r\n\r\n    p.resize(m + m - 1);\r\n    FOR(i, m - 1) p[i]\
    \ += dh[i];\r\n    p = integrate(p);\r\n    FOR(i, m + m) p[i] = h[i] - p[i];\r\
    \n    p[0] += mint(1);\r\n    f = convolution(f, p);\r\n    f.resize(m + m);\r\
    \n    m += m;\r\n  }\r\n  f.resize(L);\r\n  return f;\r\n}\r\n\r\n// ntt \u7D20\
    \u6570\u5C02\u7528\u5B9F\u88C5\u3002\u9577\u3055 n \u306E FFT \u3092\u5229\u7528\
    \u3057\u3066 2n \u306E FFT\r\n// \u3092\u884C\u3046\u306A\u3069\u306E\u9AD8\u901F\
    \u5316\u3092\u3057\u3066\u3044\u308B\u3002\r\ntemplate <typename mint>\r\nenable_if_t<is_same<mint,\
    \ modint998>::value, vc<mint>> fps_exp_dense(\r\n    vc<mint>& f) {\r\n  const\
    \ int n = len(f);\r\n  assert(n > 0 && f[0] == mint(0));\r\n  vc<mint> b = {1,\
    \ (1 < n ? f[1] : 0)};\r\n  vc<mint> c = {1}, z1, z2 = {1, 1};\r\n  while (len(b)\
    \ < n) {\r\n    int m = len(b);\r\n    auto y = b;\r\n    y.resize(2 * m);\r\n\
    \    ntt(y, 0);\r\n    z1 = z2;\r\n    vc<mint> z(m);\r\n    FOR(i, m) z[i] =\
    \ y[i] * z1[i];\r\n    ntt(z, 1);\r\n    FOR(i, m / 2) z[i] = 0;\r\n    ntt(z,\
    \ 0);\r\n    FOR(i, m) z[i] *= -z1[i];\r\n    ntt(z, 1);\r\n    c.insert(c.end(),\
    \ z.begin() + m / 2, z.end());\r\n    z2 = c;\r\n    z2.resize(2 * m);\r\n   \
    \ ntt(z2, 0);\r\n\r\n    vc<mint> x(f.begin(), f.begin() + m);\r\n    FOR(i, len(x)\
    \ - 1) x[i] = x[i + 1] * mint(i + 1);\r\n    x.back() = 0;\r\n    ntt(x, 0);\r\
    \n    FOR(i, m) x[i] *= y[i];\r\n    ntt(x, 1);\r\n\r\n    FOR(i, m - 1) x[i]\
    \ -= b[i + 1] * mint(i + 1);\r\n\r\n    x.resize(m + m);\r\n    FOR(i, m - 1)\
    \ x[m + i] = x[i], x[i] = 0;\r\n    ntt(x, 0);\r\n    FOR(i, m + m) x[i] *= z2[i];\r\
    \n    ntt(x, 1);\r\n    FOR_R(i, len(x) - 1) x[i + 1] = x[i] * inv<mint>(i + 1);\r\
    \n    x[0] = 0;\r\n\r\n    FOR3(i, m, min(n, m + m)) x[i] += f[i];\r\n    FOR(i,\
    \ m) x[i] = 0;\r\n    ntt(x, 0);\r\n    FOR(i, m + m) x[i] *= y[i];\r\n    ntt(x,\
    \ 1);\r\n    b.insert(b.end(), x.begin() + m, x.end());\r\n  }\r\n  b.resize(n);\r\
    \n  return b;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/fps_exp.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/fps_exp.hpp
layout: document
redirect_from:
- /library/poly/fps_exp.hpp
- /library/poly/fps_exp.hpp.html
title: poly/fps_exp.hpp
---
