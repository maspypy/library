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
    - https://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/polynomial_matrix_prod.rs
    - https://nyaannyaan.github.io/library/matrix/polynomial-matrix-prefix-prod.hpp
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
  code: "#pragma once\n#include \"linalg/mat_mul.hpp\"\n#include \"poly/lagrange_interpolate_iota.hpp\"\
    \n\n// A[k-1]...A[0] \u3092\u8A08\u7B97\u3059\u308B\n// \u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0\u53C2\u8003\uFF1Ahttps://github.com/noshi91/n91lib_rs/blob/master/src/algorithm/polynomial_matrix_prod.rs\n\
    // \u5B9F\u88C5\u53C2\u8003\uFF1Ahttps://nyaannyaan.github.io/library/matrix/polynomial-matrix-prefix-prod.hpp\n\
    template <typename T>\nvc<vc<T>> prefix_product_of_poly_matrix(vc<vc<vc<T>>>&\
    \ A, ll k) {\n  int n = len(A);\n\n  using MAT = vc<vc<T>>;\n  auto shift = [&](vc<MAT>&\
    \ G, T x) -> vc<MAT> {\n    int d = len(G);\n    vvv(T, H, d, n, n);\n    FOR(i,\
    \ n) FOR(j, n) {\n      vc<T> g(d);\n      FOR(l, d) g[l] = G[l][i][j];\n    \
    \  auto h = lagrange_interpolate_iota(g, x, d);\n      FOR(l, d) H[l][i][j] =\
    \ h[l];\n    }\n    return H;\n  };\n\n  auto evaluate = [&](vc<T>& f, T x) ->\
    \ T {\n    T res = 0;\n    T p = 1;\n    FOR(i, len(f)) {\n      res += f[i] *\
    \ p;\n      p *= x;\n    }\n    return res;\n  };\n\n  ll deg = 1;\n  FOR(i, n)\
    \ FOR(j, n) chmax(deg, len(A[i][j]) - 1);\n\n  vc<MAT> G(deg + 1);\n  ll v = 1;\n\
    \  while (deg * v * v < k) v *= 2;\n  T iv = T(1) / T(v);\n\n  FOR(i, len(G))\
    \ {\n    T x = T(v) * T(i);\n    vv(T, mat, n, n);\n    FOR(j, n) FOR(k, n) mat[j][k]\
    \ = evaluate(A[j][k], x);\n    G[i] = mat;\n  }\n\n  for (ll w = 1; w != v; w\
    \ *= 2) {\n    T W = w;\n    auto G1 = shift(G, W * iv);\n    auto G2 = shift(G,\
    \ (W * T(deg) * T(v) + T(v)) * iv);\n    auto G3 = shift(G, (W * T(deg) * T(v)\
    \ + T(v) + W) * iv);\n    FOR(i, w * deg + 1) {\n      G[i] = mat_mul(G1[i], G[i]);\n\
    \      G2[i] = mat_mul(G3[i], G2[i]);\n    }\n    copy(G2.begin(), G2.end() -\
    \ 1, back_inserter(G));\n  }\n\n  vv(T, res, n, n);\n  FOR(i, n) res[i][i] = 1;\n\
    \  ll i = 0;\n  while (i + v <= k) res = mat_mul(G[i / v], res), i += v;\n  while\
    \ (i < k) {\n    vv(T, mat, n, n);\n    FOR(j, n) FOR(k, n) mat[j][k] = evaluate(A[j][k],\
    \ i);\n    res = mat_mul(mat, res);\n    ++i;\n  }\n  return res;\n}\n\n// f[k-1]...f[0]\
    \ \u3092\u8A08\u7B97\u3059\u308B\ntemplate <typename T>\nT prefix_product_of_poly(vc<T>&\
    \ f, ll k) {\n  vc<vc<vc<T>>> A(1);\n  A[0].resize(1);\n  A[0][0] = f;\n  auto\
    \ res = prefix_product_of_poly_matrix(A, k);\n  return res[0][0];\n}"
  dependsOn: []
  isVerificationFile: false
  path: poly/prefix_product_of_poly.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/prefix_product_of_poly.hpp
layout: document
redirect_from:
- /library/poly/prefix_product_of_poly.hpp
- /library/poly/prefix_product_of_poly.hpp.html
title: poly/prefix_product_of_poly.hpp
---
