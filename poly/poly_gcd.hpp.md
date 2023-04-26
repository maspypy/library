---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://people.eecs.berkeley.edu/~fateman/282/readings/yap-2.pdf
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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: mod/barret.hpp:\
    \ line -1: no such header\n"
  code: "#include \"poly/poly_divmod.hpp\"\r\n\r\n// https://people.eecs.berkeley.edu/~fateman/282/readings/yap-2.pdf\r\
    \nnamespace half_gcd {\r\ntemplate <typename T>\r\nusing arr = array<vc<T>, 2>;\r\
    \n\r\ntemplate <typename T>\r\nusing mat = array<vc<T>, 4>;\r\n\r\ntemplate <typename\
    \ T>\r\nvoid shrink(vc<T>& a) {\r\n  while (len(a) && a.back() == 0) a.pop_back();\r\
    \n}\r\n\r\ntemplate <typename T>\r\nvc<T> operator+(const vc<T>& a, const vc<T>&\
    \ b) {\r\n  vc<T> c(max(len(a), len(b)));\r\n  FOR(i, len(a)) c[i] += a[i];\r\n\
    \  FOR(i, len(b)) c[i] += b[i];\r\n  shrink(c);\r\n  return c;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nvc<T> operator-(const vc<T>& a, const vc<T>& b) {\r\n  vc<T>\
    \ c(max(len(a), len(b)));\r\n  FOR(i, len(a)) c[i] += a[i];\r\n  FOR(i, len(b))\
    \ c[i] -= b[i];\r\n  shrink(c);\r\n  return c;\r\n}\r\n\r\ntemplate <typename\
    \ T>\r\nvc<T> operator*(const vc<T>& a, const vc<T>& b) {\r\n  return convolution(a,\
    \ b);\r\n}\r\n\r\ntemplate <typename T>\r\nmat<T> operator*(const mat<T>& A, const\
    \ mat<T>& B) {\r\n  return {A[0] * B[0] + A[1] * B[2], A[0] * B[1] + A[1] * B[3],\r\
    \n          A[2] * B[0] + A[3] * B[2], A[2] * B[1] + A[3] * B[3]};\r\n}\r\n\r\n\
    template <typename T>\r\nmat<T> step(const vc<T> q) {\r\n  mat<T> Q;\r\n  Q[1]\
    \ = {1}, Q[2] = {1};\r\n  Q[3] = Q[3] - q;\r\n  return Q;\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\narr<T> operator*(const mat<T>& A, const arr<T>& b) {\r\n  return\
    \ {A[0] * b[0] + A[1] * b[1], A[2] * b[0] + A[3] * b[1]};\r\n}\r\n\r\ntemplate\
    \ <typename T>\r\nmat<T> hgcd(arr<T> a) {\r\n  assert(len(a[0]) > len(a[1]) &&\
    \ len(a[1]) > 0);\r\n  int m = len(a[0]) / 2;\r\n  if (a[1].size() <= m) {\r\n\
    \    mat<T> M;\r\n    M[0] = {1}, M[3] = {1};\r\n    return M;\r\n  }\r\n  auto\
    \ R = hgcd(arr<T>({vc<T>(a[0].begin() + m, a[0].end()),\r\n                  \
    \      vc<T>(a[1].begin() + m, a[1].end())}));\r\n  a = R * a;\r\n  if (a[1].size()\
    \ <= m) return R;\r\n  mat<T> Q = step(poly_divmod(a[0], a[1]).fi);\r\n  R = Q\
    \ * R, a = Q * a;\r\n  if (a[1].size() <= m) return R;\r\n  int k = 2 * m + 1\
    \ - len(a[0]);\r\n  auto H = hgcd(arr<T>({vc<T>(a[0].begin() + k, a[0].end()),\r\
    \n                        vc<T>(a[1].begin() + k, a[1].end())}));\r\n  return\
    \ H * R;\r\n}\r\n\r\ntemplate <typename T>\r\nmat<T> cgcd(arr<T> a) {\r\n  assert(a[0].size()\
    \ > a[1].size() && !a[1].empty());\r\n  auto m0 = hgcd(a);\r\n  a = m0 * a;\r\n\
    \  if (a[1].empty()) return m0;\r\n  mat<T> Q = step(poly_divmod(a[0], a[1]).fi);\r\
    \n  m0 = Q * m0, a = Q * a;\r\n  if (a[1].empty()) return m0;\r\n  return cgcd(a)\
    \ * m0;\r\n}\r\n\r\n// gcd == f * fi + g * gi \u3068\u306A\u308B (gcd, fi, gi)\r\
    \ntemplate <typename T>\r\ntuple<vc<T>, vc<T>, vc<T>> poly_extgcd(const vc<T>&\
    \ f, const vc<T>& g) {\r\n  mat<T> Q = step(poly_divmod(f, g).fi);\r\n  auto m\
    \ = Q;\r\n  auto ap = Q * arr<T>{f, g};\r\n  if (!ap[1].empty()) m = cgcd(ap)\
    \ * m;\r\n  return {f * m[0] + g * m[1], m[0], m[1]};\r\n}\r\n} // namespace half_gcd\r\
    \nusing half_gcd::poly_extgcd;"
  dependsOn: []
  isVerificationFile: false
  path: poly/poly_gcd.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/poly_gcd.hpp
layout: document
redirect_from:
- /library/poly/poly_gcd.hpp
- /library/poly/poly_gcd.hpp.html
title: poly/poly_gcd.hpp
---
