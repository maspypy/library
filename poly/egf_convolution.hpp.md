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
    - https://qoj.ac/problem/2205
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.13/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: nt/primetest.hpp:\
    \ line -1: no such header\n"
  code: "\n#include \"nt/factor.hpp\"\n#include \"mod/mod_inv.hpp\"\n#include \"mod/modint.hpp\"\
    \n#include \"mod/crt3.hpp\"\n#include \"poly/convolution.hpp\"\n\n// https://qoj.ac/problem/2205\n\
    // 4 * convolution_ntt \u7A0B\u5EA6\n// mod \u306F\u4E0A\u306E\u554F\u984C\u306E\
    \u305F\u3081\u306B u64 \u306B\u3057\u3066\u304A\u3044\u305F\u304C\u901A\u5E38\
    \ u32 \u3067\u3044\u3044\u306F\u305A\n// ANS[k] = sum_{i+j==k} A[i]B[j]\nvc<u64>\
    \ egf_convolution(vc<u64> A, vc<u64> B, u64 mod) {\n  assert(mod <= u64(1) <<\
    \ 32);\n  vc<int> P;\n  for (auto& [p, e]: factor(mod)) P.eb(p);\n  int N = len(A)\
    \ - 1, M = len(B) - 1;\n  vc<u64> R(N + M + 1, 1);\n  vc<u64> F(N + M + 1, 1);\n\
    \  vc<u64> IF(N + M + 1, 1);\n  FOR(n, 1, N + M + 1) {\n    int x = n;\n    for\
    \ (auto& p: P)\n      while (x % p == 0) x /= p;\n    R[n] = x;\n  }\n  FOR(n,\
    \ 1, N + M + 1) F[n] = F[n - 1] * R[n] % mod;\n  IF[N + M] = mod_inv(F[N + M],\
    \ mod);\n  FOR_R(n, N + M) IF[n] = IF[n + 1] * R[n + 1] % mod;\n  assert(IF[0]\
    \ == 1);\n  // IF \u306F mod \u3067\u51E6\u7406\u3059\u308B\n  FOR(i, N + 1) A[i]\
    \ = A[i] * IF[i] % mod;\n  FOR(i, M + 1) B[i] = B[i] * IF[i] % mod;\n  auto calc_mint\
    \ = [&]<typename mint>() -> vc<mint> {\n    // p-part \u306F modint \u3067\u51E6\
    \u7406\n    vc<mint> X(N + 1), Y(M + 1);\n    FOR(i, N + 1) X[i] = A[i];\n   \
    \ FOR(i, M + 1) Y[i] = B[i];\n    for (auto& p: P) {\n      mint ip = mint(p).inverse();\n\
    \      vc<mint> IF(N + M + 1, 1);\n      for (ll q = p; q <= N + M; q *= p) {\n\
    \        for (int i = q; i <= N + M; i += q) { IF[i] *= ip; }\n      }\n     \
    \ FOR(i, N + M) IF[i + 1] *= IF[i];\n      FOR(i, N + 1) X[i] *= IF[i];\n    \
    \  FOR(i, M + 1) Y[i] *= IF[i];\n    }\n    X = convolution<mint>(X, Y);\n   \
    \ for (auto& p: P) {\n      vc<mint> F(N + M + 1, 1);\n      for (ll q = p; q\
    \ <= N + M; q *= p) {\n        for (int i = q; i <= N + M; i += q) { F[i] *= p;\
    \ }\n      }\n      FOR(i, N + M) F[i + 1] *= F[i];\n      FOR(i, N + M + 1) X[i]\
    \ *= F[i];\n    }\n    return X;\n  };\n  constexpr int p0 = 469762049;\n  constexpr\
    \ int p1 = 754974721;\n  constexpr int p2 = 880803841;\n  constexpr int p3 = 998244353;\n\
    \  // \u8B0E by chatgpt\n  auto A0 = calc_mint.template operator()<modint<p0>>();\n\
    \  auto A1 = calc_mint.template operator()<modint<p1>>();\n  auto A2 = calc_mint.template\
    \ operator()<modint<p2>>();\n  auto A3 = calc_mint.template operator()<modint<p3>>();\n\
    \  vc<u64> ANS(N + M + 1);\n  FOR(i, N + M + 1) ANS[i] = CRT4<u128, p0, p1, p2,\
    \ p3>(A0[i].val, A1[i].val, A2[i].val, A3[i].val) % mod;\n  FOR(i, N + M + 1)\
    \ ANS[i] = ANS[i] * F[i] % mod;\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/egf_convolution.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/egf_convolution.hpp
layout: document
redirect_from:
- /library/poly/egf_convolution.hpp
- /library/poly/egf_convolution.hpp.html
title: poly/egf_convolution.hpp
---
