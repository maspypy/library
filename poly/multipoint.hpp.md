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
  code: "#pragma once\r\n\r\n#include \"poly/fps_inv.hpp\"\r\n#include \"poly/middle_product.hpp\"\
    \r\n\r\ntemplate <typename mint>\r\nstruct SubproductTree {\r\n  int m;\r\n  int\
    \ sz;\r\n  vc<vc<mint>> T;\r\n  SubproductTree(const vc<mint>& x) {\r\n    m =\
    \ len(x);\r\n    sz = 1;\r\n    while (sz < m) sz *= 2;\r\n    T.resize(2 * sz);\r\
    \n    FOR(i, sz) T[sz + i] = {1, (i < m ? -x[i] : 0)};\r\n    FOR3_R(i, 1, sz)\
    \ T[i] = convolution(T[2 * i], T[2 * i + 1]);\r\n  }\r\n\r\n  vc<mint> evaluation(vc<mint>\
    \ f) {\r\n    int n = len(f);\r\n    if (n == 0) return vc<mint>(m, mint(0));\r\
    \n    f.resize(2 * n - 1);\r\n    vc<vc<mint>> g(2 * sz);\r\n    g[1] = T[1];\r\
    \n    g[1].resize(n);\r\n    g[1] = fps_inv(g[1]);\r\n    g[1] = middle_product(f,\
    \ g[1]);\r\n    g[1].resize(sz);\r\n\r\n    FOR3(i, 1, sz) {\r\n      g[2 * i]\
    \ = middle_product(g[i], T[2 * i + 1]);\r\n      g[2 * i + 1] = middle_product(g[i],\
    \ T[2 * i]);\r\n    }\r\n    vc<mint> vals(m);\r\n    FOR(i, m) vals[i] = g[sz\
    \ + i][0];\r\n    return vals;\r\n  }\r\n\r\n  vc<mint> interpolation(vc<mint>&\
    \ y) {\r\n    assert(len(y) == m);\r\n    vc<mint> a(m);\r\n    FOR(i, m) a[i]\
    \ = T[1][m - i - 1] * (i + 1);\r\n\r\n    a = evaluation(a);\r\n    vc<vc<mint>>\
    \ t(2 * sz);\r\n    FOR(i, sz) t[sz + i] = {(i < m ? y[i] / a[i] : 0)};\r\n  \
    \  FOR3_R(i, 1, sz) {\r\n      t[i] = convolution(t[2 * i], T[2 * i + 1]);\r\n\
    \      auto tt = convolution(t[2 * i + 1], T[2 * i]);\r\n      FOR(k, len(t[i]))\
    \ t[i][k] += tt[k];\r\n    }\r\n    t[1].resize(m);\r\n    reverse(all(t[1]));\r\
    \n    return t[1];\r\n  }\r\n};\r\n\r\ntemplate <typename mint>\r\nvc<mint> multipoint_eval(vc<mint>&\
    \ f, vc<mint>& x) {\r\n  if (x.empty()) return {};\r\n  SubproductTree<mint> F(x);\r\
    \n  return F.evaluation(f);\r\n}\r\n\r\ntemplate <typename mint>\r\nvc<mint> multipoint_interpolate(vc<mint>&\
    \ x, vc<mint>& y) {\r\n  if (x.empty()) return {};\r\n  SubproductTree<mint> F(x);\r\
    \n  return F.interpolation(y);\r\n}\r\n\r\n// calculate f(ar^k) for 0 <= k < m\r\
    \ntemplate <typename mint>\r\nvc<mint> multipoint_eval_on_geom_seq(vc<mint> f,\
    \ mint a, mint r, int m) {\r\n  const int n = len(f);\r\n  if (m == 0) return\
    \ {};\r\n\r\n  auto eval = [&](mint x) -> mint {\r\n    mint fx = 0;\r\n    mint\
    \ pow = 1;\r\n    FOR(i, n) fx += f[i] * pow, pow *= x;\r\n    return fx;\r\n\
    \  };\r\n\r\n  if (r == mint(0)) {\r\n    vc<mint> res(m);\r\n    FOR(i, 1, m)\
    \ res[i] = f[0];\r\n    res[0] = eval(a);\r\n    return res;\r\n  }\r\n  if (n\
    \ < 60 || m < 60) {\r\n    vc<mint> res(m);\r\n    FOR(i, m) res[i] = eval(a),\
    \ a *= r;\r\n    return res;\r\n  }\r\n  assert(r != mint(0));\r\n  // a == 1\
    \ \u306B\u5E30\u7740\r\n  mint pow_a = 1;\r\n  FOR(i, n) f[i] *= pow_a, pow_a\
    \ *= a;\r\n\r\n  auto calc = [&](mint r, int m) -> vc<mint> {\r\n    // r^{t_i}\
    \ \u306E\u8A08\u7B97\r\n    vc<mint> res(m);\r\n    mint pow = 1;\r\n    res[0]\
    \ = 1;\r\n    FOR(i, m - 1) {\r\n      res[i + 1] = res[i] * pow;\r\n      pow\
    \ *= r;\r\n    }\r\n    return res;\r\n  };\r\n\r\n  vc<mint> A = calc(r, n +\
    \ m - 1), B = calc(r.inverse(), max(n, m));\r\n  FOR(i, n) f[i] *= B[i];\r\n \
    \ f = middle_product(A, f);\r\n  FOR(i, m) f[i] *= B[i];\r\n  return f;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/multipoint.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/multipoint.hpp
layout: document
redirect_from:
- /library/poly/multipoint.hpp
- /library/poly/multipoint.hpp.html
title: poly/multipoint.hpp
---
