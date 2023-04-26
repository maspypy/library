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
  - icon: ':x:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':x:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1080_2.test.cpp
    title: test/yukicoder/1080_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2166.test.cpp
    title: test/yukicoder/2166.test.cpp
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
    \  [Previous line repeated 2 more times]\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#pragma once\n\n#include \"seq/kth_term_of_p_recursive.hpp\"\n\n// \u5BFE\
    \u6570\u5FAE\u5206 F'/F = a(x)/b(x) \u304B\u3089 F \u3092\u5FA9\u5143\u3059\u308B\
    \u3002\n// a, b \u304C sparse \u3067\u3042\u308C\u3070\u3001O(N(K1+K2)) \u6642\
    \u9593\u3067\u3067\u304D\u308B\n// [0, N] \u3092\u8A08\u7B97\ntemplate <typename\
    \ mint>\nvc<mint> from_log_differentiation(int N, const vc<mint>& a, const vc<mint>&\
    \ b) {\n  assert(b[0] == mint(1));\n  using P = pair<int, mint>;\n\n  vc<P> dat_a,\
    \ dat_b;\n  FOR(i, len(a)) if (a[i] != mint(0)) dat_a.eb(i, a[i]);\n  FOR(i, 1,\
    \ len(b)) if (b[i] != mint(0)) dat_b.eb(i, b[i]);\n\n  vc<mint> f(N + 1);\n  vc<mint>\
    \ df(N);\n  f[0] = mint(1);\n  FOR(n, N) {\n    mint v = 0;\n    for (auto&& [i,\
    \ bi]: dat_b) {\n      if (i > n) break;\n      v -= bi * df[n - i];\n    }\n\
    \    for (auto&& [i, ai]: dat_a) {\n      if (i > n) break;\n      v += ai * f[n\
    \ - i];\n    }\n    df[n] = v;\n    f[n + 1] = df[n] * inv<mint>(n + 1);\n  }\n\
    \  return f;\n}\n\n// F'/F = a/b \u306E\u89E3\u306E\u3001[x^K]F \u3092\u6C42\u3081\
    \u308B\u3002\u53F3\u8FBA\u306F\u4F4E\u6B21\u306E\u6709\u7406\u5F0F\u3002\ntemplate\
    \ <typename mint>\nmint from_log_differentiation_kth(int K, vc<mint>& a, vc<mint>&\
    \ b) {\n  assert(b[0] == mint(1));\n  int r = max(len(a), len(b) - 1);\n  vvc<mint>\
    \ c(r + 1);\n  FOR(i, r + 1) {\n    mint c0 = 0, c1 = 0;\n    if (i < len(b))\
    \ c0 += mint(r - i) * b[i];\n    if (i < len(b)) c1 += b[i];\n    if (0 <= i -\
    \ 1 && i - 1 < len(b)) c0 -= a[i - 1];\n    c[i] = {c0, c1};\n  }\n  auto f =\
    \ from_log_differentiation(r - 1, a, b);\n  mint ANS = kth_term_of_p_recursive(f,\
    \ c, K);\n  return ANS;\n}"
  dependsOn:
  - seq/kth_term_of_p_recursive.hpp
  - poly/prefix_product_of_poly.hpp
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
  path: poly/from_log_differentiation.hpp
  requiredBy:
  - poly/sparse_exp_of_div.hpp
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc276_g.test.cpp
  - test_atcoder/abc222h_2.test.cpp
  - test_atcoder/abc276_g_2.test.cpp
  - test/yukicoder/1080_2.test.cpp
  - test/yukicoder/2166.test.cpp
documentation_of: poly/from_log_differentiation.hpp
layout: document
redirect_from:
- /library/poly/from_log_differentiation.hpp
- /library/poly/from_log_differentiation.hpp.html
title: poly/from_log_differentiation.hpp
---
