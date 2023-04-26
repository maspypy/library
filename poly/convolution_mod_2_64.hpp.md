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
  code: "#include \"poly/convolution.hpp\"\r\nvector<u64> convolution_mod_2_64(const\
    \ vector<u64>& a, const vector<u64>& b) {\r\n  int n = len(a), m = len(b);\r\n\
    \  if (!n || !m) return {};\r\n  if (min(n, m) <= 60) return convolution_naive(a,\
    \ b);\r\n  constexpr int P0 = 998244353;\r\n  constexpr int P1 = 754974721;\r\n\
    \  constexpr int P2 = 167772161;\r\n  constexpr int P3 = 469762049;\r\n  constexpr\
    \ int P4 = 880803841;\r\n  using M0 = modint<P0>;\r\n  using M1 = modint<P1>;\r\
    \n  using M2 = modint<P2>;\r\n  using M3 = modint<P3>;\r\n  using M4 = modint<P4>;\r\
    \n  vc<M0> a0(n), b0(m);\r\n  vc<M1> a1(n), b1(m);\r\n  vc<M2> a2(n), b2(m);\r\
    \n  vc<M3> a3(n), b3(m);\r\n  vc<M4> a4(n), b4(m);\r\n  FOR(i, n) a0[i] = a[i]\
    \ % P0;\r\n  FOR(i, m) b0[i] = b[i] % P0;\r\n  FOR(i, n) a1[i] = a[i] % P1;\r\n\
    \  FOR(i, m) b1[i] = b[i] % P1;\r\n  FOR(i, n) a2[i] = a[i] % P2;\r\n  FOR(i,\
    \ m) b2[i] = b[i] % P2;\r\n  FOR(i, n) a3[i] = a[i] % P3;\r\n  FOR(i, m) b3[i]\
    \ = b[i] % P3;\r\n  FOR(i, n) a4[i] = a[i] % P4;\r\n  FOR(i, m) b4[i] = b[i] %\
    \ P4;\r\n  a0 = convolution_ntt<M0>(a0, b0);\r\n  a1 = convolution_ntt<M1>(a1,\
    \ b1);\r\n  a2 = convolution_ntt<M2>(a2, b2);\r\n  a3 = convolution_ntt<M3>(a3,\
    \ b3);\r\n  a4 = convolution_ntt<M4>(a4, b4);\r\n  static const M1 inv10 = M1(1)\
    \ / M1(P0);\r\n  static const M2 inv21 = M2(1) / M2(P1), inv20 = inv21 / M2(P0);\r\
    \n  static const M3 inv32 = M3(1) / M3(P2), inv31 = inv32 / M3(P1),\r\n      \
    \            inv30 = inv31 / M3(P0);\r\n  static const M4 inv43 = M4(1) / M4(P3),\
    \ inv42 = inv43 / M4(P2),\r\n                  inv41 = inv42 / M4(P1), inv40 =\
    \ inv41 / M4(P0);\r\n  vc<u64> c(len(a0));\r\n  FOR(i, len(c)) {\r\n    ll x0\
    \ = a0[i].val;\r\n    ll x1 = (M1(a1[i] - x0) * inv10).val;\r\n    ll x2 = (M2(a2[i]\
    \ - x0) * inv20 - M2(x1) * inv21).val;\r\n    ll x3 = (M3(a3[i] - x0) * inv30\
    \ - M3(x1) * inv31 - M3(x2) * inv32).val;\r\n    ll x4 = (M4(a4[i] - x0) * inv40\
    \ - M4(x1) * inv41 - M4(x2) * inv42\r\n             - M4(x3) * inv43)\r\n    \
    \            .val;\r\n    c[i] = x0 + P0 * (x1 + P1 * (x2 + P2 * (x3 + P3 * u64(x4))));\r\
    \n  }\r\n  return c;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/convolution_mod_2_64.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/convolution_mod_2_64.hpp
layout: document
redirect_from:
- /library/poly/convolution_mod_2_64.hpp
- /library/poly/convolution_mod_2_64.hpp.html
title: poly/convolution_mod_2_64.hpp
---
