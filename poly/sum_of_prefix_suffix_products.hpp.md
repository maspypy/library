---
data:
  _extendedDependsOn:
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
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test_atcoder/abc269ex.test.cpp
    title: test_atcoder/abc269ex.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_p
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
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ poly/ntt.hpp: line 2: #pragma once found in a non-first line\n"
  code: "#include \"poly/convolution.hpp\"\n\n/*\n\u591A\u9805\u5F0F\u306E\u5217 f0,\
    \ f1, ..., f{N-1} \u304A\u3088\u3073 g0, g1, ..., g{N-1} \u3092\u4E0E\u3048\u308B\
    \u3002\nf0f1f2f3 + f0f1f2g3 + f0f1g2g3 + f0g1g2g3 + g0g1g2g3\n\u306E\u3088\u3046\
    \u306A\u7DCF\u548C\u3092\u6C42\u3081\u308B\u3002\u5206\u5272\u7D71\u6CBB\u3067\
    \ O(Nlog^2N)\u3002N \u306F\u6B21\u6570\u306E\u7DCF\u548C\u3002\nhttps://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_p\n\
    */\ntemplate <typename mint>\nvc<mint> sum_of_prefix_suffix_products(vvc<mint>\
    \ F, vvc<mint> G) {\n  int n = len(F);\n  using poly = vc<mint>;\n  auto add =\
    \ [&](poly f, poly g) -> poly {\n    poly h(max(len(f), len(g)));\n    FOR(i,\
    \ len(f)) h[i] += f[i];\n    FOR(i, len(g)) h[i] += g[i];\n    return h;\n  };\n\
    \n  auto dfs = [&](auto& dfs, int l, int r) -> tuple<poly, poly, poly> {\n   \
    \ if (r == l + 1) { return {add(F[l], G[l]), F[l], G[l]}; }\n    int m = (l +\
    \ r) / 2;\n    auto [pl, fl, gl] = dfs(dfs, l, m);\n    auto [pr, fr, gr] = dfs(dfs,\
    \ m, r);\n    poly p = convolution(pl, gr);\n    FOR(i, len(gr)) pr[i] -= gr[i];\n\
    \    p = add(p, convolution(fl, pr));\n    return {p, convolution(fl, fr), convolution(gl,\
    \ gr)};\n  };\n  auto [p, f, g] = dfs(dfs, 0, n);\n  return p;\n}"
  dependsOn:
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: poly/sum_of_prefix_suffix_products.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/abc269ex.test.cpp
documentation_of: poly/sum_of_prefix_suffix_products.hpp
layout: document
redirect_from:
- /library/poly/sum_of_prefix_suffix_products.hpp
- /library/poly/sum_of_prefix_suffix_products.hpp.html
title: poly/sum_of_prefix_suffix_products.hpp
---
