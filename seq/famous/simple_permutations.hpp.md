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
  - icon: ':x:'
    path: poly/online/online_convolution.hpp
    title: poly/online/online_convolution.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/simple_perm.test.cpp
    title: test/mytest/simple_perm.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://oeis.org/A059372
    - https://oeis.org/A111111
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
  code: "#include \"poly/online/online_convolution.hpp\"\n\n// https://oeis.org/A059372\
    \ sum_{n>0} n!x^n \u306E\u9006\u95A2\u6570\ntemplate <typename mint>\nvc<mint>\
    \ revert_transform_of_factorials(const int N) {\n  // xQ' = Q^2 + (1+x)Q'Q\n \
    \ // R = Q^2 \u3068\u3057\u3066\u3001xQ' = R + 1/2 (1+x)R'\n  // [x^n] \u3092\u898B\
    \u308B\u3068\u3001nQn = Rn + 1/2(n+1)R_{n+1} + 1/2 nR_n \u306E\u5F62\n  //\n \
    \ // Q = x + x^2F \u3068\u3059\u308C\u3070 F_{n-3} \u307E\u3067\u5206\u304B\u3063\
    \u305F\u6642\u70B9\u3067\n  // Q_{n-1}, R_n \u307E\u3067\u78BA\u5B9A\u3002R =\
    \ x^2+x^4F^2+2x^3F \u3068\u3057\u3066\u3001\n  // Q_n = F_{n-2}, R_{n+1} = (\u78BA\
    \u5B9A) + 2F_{n-2} \u306E\u5F62\n  vc<mint> Q(N + 1), R(N + 2);\n  Q[1] = 1, R[2]\
    \ = 1;\n  vc<mint> F(N - 1), FF(N - 1);\n  Online_Convolution<mint> X;\n  FOR(n,\
    \ 2, N + 1) {\n    mint x = R[n] + mint(n) * inv<mint>(2) * R[n];\n    if (n >=\
    \ 3) x += mint(n + 1) * FF[n - 3] * inv<mint>(2);\n    Q[n] = F[n - 2] = -x;\n\
    \    FF[n - 2] = X.query(n - 2, x, x);\n    if (n + 1 >= 4) R[n + 1] += FF[n +\
    \ 1 - 4];\n    R[n + 1] += mint(2) * F[n - 2];\n  }\n  return Q;\n}\n\n// https://oeis.org/A111111\n\
    // \u305F\u3060\u3057\u3001n=1, 2 \u306B\u5BFE\u3057\u3066\u306F 0 \u3092\u8FD4\
    \u3059\u3088\u3046\u306B\u3057\u3066\u3044\u308B\ntemplate <typename mint>\nvc<mint>\
    \ simple_permutations(const int N) {\n  vc<mint> S = revert_transform_of_factorials<mint>(N);\n\
    \  for (auto&& x: S) x = -x;\n  S[1] += mint(1);\n  FOR(i, 2, N + 1) {\n    if\
    \ (i % 2 == 0) S[i] -= 2;\n    if (i % 2 == 1) S[i] += 2;\n  }\n  return S;\n\
    }\n"
  dependsOn:
  - poly/online/online_convolution.hpp
  - poly/convolution.hpp
  - mod/modint.hpp
  - mod/modint_common.hpp
  - mod/mod_inv.hpp
  - poly/convolution_naive.hpp
  - poly/ntt.hpp
  - mod/barret.hpp
  - poly/fft.hpp
  isVerificationFile: false
  path: seq/famous/simple_permutations.hpp
  requiredBy: []
  timestamp: '2023-04-27 03:47:30+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/simple_perm.test.cpp
documentation_of: seq/famous/simple_permutations.hpp
layout: document
redirect_from:
- /library/seq/famous/simple_permutations.hpp
- /library/seq/famous/simple_permutations.hpp.html
title: seq/famous/simple_permutations.hpp
---
