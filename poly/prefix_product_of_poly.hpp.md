---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: alg/monoid/mul.hpp
    title: alg/monoid/mul.hpp
  - icon: ':question:'
    path: ds/sliding_window_aggregation.hpp
    title: ds/sliding_window_aggregation.hpp
  - icon: ':x:'
    path: linalg/mat_mul.hpp
    title: linalg/mat_mul.hpp
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
  - icon: ':x:'
    path: poly/lagrange_interpolate_iota.hpp
    title: poly/lagrange_interpolate_iota.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':x:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  - icon: ':x:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1080_2.test.cpp
    title: test/yukicoder/1080_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2166.test.cpp
    title: test/yukicoder/2166.test.cpp
  - icon: ':x:'
    path: test/yukicoder/502_2.test.cpp
    title: test/yukicoder/502_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc222h_2.test.cpp
    title: test_atcoder/abc222h_2.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc276_g.test.cpp
    title: test_atcoder/abc276_g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc276_g_2.test.cpp
    title: test_atcoder/abc276_g_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
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
  dependsOn:
  - linalg/mat_mul.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - poly/lagrange_interpolate_iota.hpp
  - alg/monoid/mul.hpp
  - ds/sliding_window_aggregation.hpp
  - poly/convolution.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/prefix_product_of_poly.hpp
  requiredBy:
  - seq/kth_term_of_p_recursive.hpp
  - poly/sparse_exp_of_div.hpp
  - poly/from_log_differentiation.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc276_g.test.cpp
  - test_atcoder/abc222h_2.test.cpp
  - test_atcoder/abc276_g_2.test.cpp
  - test/yukicoder/502_2.test.cpp
  - test/yukicoder/1080_2.test.cpp
  - test/yukicoder/2166.test.cpp
  - test/mytest/factorial_998.test.cpp
documentation_of: poly/prefix_product_of_poly.hpp
layout: document
redirect_from:
- /library/poly/prefix_product_of_poly.hpp
- /library/poly/prefix_product_of_poly.hpp.html
title: poly/prefix_product_of_poly.hpp
---
