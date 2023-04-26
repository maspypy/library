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
  - icon: ':x:'
    path: poly/count_terms.hpp
    title: poly/count_terms.hpp
  - icon: ':question:'
    path: poly/fft.hpp
    title: poly/fft.hpp
  - icon: ':x:'
    path: poly/fps_div.hpp
    title: poly/fps_div.hpp
  - icon: ':x:'
    path: poly/fps_inv.hpp
    title: poly/fps_inv.hpp
  - icon: ':x:'
    path: poly/middle_product.hpp
    title: poly/middle_product.hpp
  - icon: ':question:'
    path: poly/ntt.hpp
    title: poly/ntt.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/slice_rational_fps.test.cpp
    title: test/mytest/slice_rational_fps.test.cpp
  - icon: ':x:'
    path: test_atcoder/agc013e.test.cpp
    title: test_atcoder/agc013e.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b
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
  code: "#include \"poly/convolution.hpp\"\n#include \"poly/middle_product.hpp\"\n\
    #include \"poly/fps_div.hpp\"\n\n// P(x)/Q(x) \u306E [N, N+d] \u90E8\u5206\u3092\
    \u8A08\u7B97\n// https://qiita.com/ryuhe1/items/c18ddbb834eed724a42b\ntemplate\
    \ <typename mint>\nvc<mint> slice_rational_fps(vc<mint> P, vc<mint> Q, ll N) {\n\
    \  assert(N >= 0 && Q[0] == mint(1) && len(P) < len(Q));\n  const int d = len(Q)\
    \ - 1;\n  if (d == 0) { return vc<mint>(); }\n  P.resize(len(Q) - 1);\n\n  auto\
    \ dfs = [&](auto& dfs, ll N, vc<mint> Q) -> vc<mint> {\n    // 1/Q \u306E [N-d+1,\
    \ N]\n    if (N == 0) {\n      vc<mint> f(d);\n      f[d - 1] = 1;\n      return\
    \ f;\n    }\n    vc<mint> R = Q;\n    FOR(i, d + 1) if (i & 1) R[i] = -R[i];\n\
    \    vc<mint> V = convolution(Q, R);\n    FOR(i, d + 1) V[i] = V[2 * i];\n   \
    \ V.resize(d + 1);\n    vc<mint> W = dfs(dfs, N / 2, V);\n    vc<mint> S(d + d);\n\
    \    if (N % 2 == 0) FOR(i, d) S[2 * i + 1] = W[i];\n    if (N % 2 == 1) FOR(i,\
    \ d) S[2 * i] = W[i];\n    reverse(all(R));\n    return middle_product(S, R);\n\
    \  };\n  vc<mint> A = dfs(dfs, N, Q);\n  vc<mint> f = convolution(A, Q);\n  f\
    \ = {f.begin() + d, f.end() - 1};\n  f = fps_div(f, Q);\n  for (auto&& x: f) x\
    \ = -x;\n  A.insert(A.end(), all(f));\n  reverse(all(P));\n  return middle_product(A,\
    \ P);\n}"
  dependsOn:
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  - poly/middle_product.hpp
  - poly/fps_div.hpp
  - poly/count_terms.hpp
  - poly/fps_inv.hpp
  isVerificationFile: false
  path: poly/slice_rational_fps.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test_atcoder/agc013e.test.cpp
  - test/mytest/slice_rational_fps.test.cpp
documentation_of: poly/slice_rational_fps.hpp
layout: document
redirect_from:
- /library/poly/slice_rational_fps.hpp
- /library/poly/slice_rational_fps.hpp.html
title: poly/slice_rational_fps.hpp
---
