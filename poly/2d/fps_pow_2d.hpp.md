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
  bundledCode: "#line 1 \"poly/2d/fps_pow_2d.hpp\"\n\n// \u6CE8\u610F (H+W)^2log(H+W)\
    \ \u6642\u9593\u306B\u306A\u3063\u3066\u3044\u308B\u306E\u3067\u6B63\u65B9\u5F62\
    \u3058\u3083\u306A\u3044\u3068\u30C0\u30E1\u306A\u3055\u307C\u308A\u5B9F\u88C5\
    \ntemplate <typename mint>\nvvc<mint> fps_pow_2d(vvc<mint> F, ll K) {\n  int N\
    \ = len(F) - 1, M = len(F[0]) - 1;\n  int L = 1;\n  while (L < N + M + 1) L *=\
    \ 2;\n\n  vv(mint, F1, L, N + M + 1);\n  FOR(i, N + 1) FOR(j, M + 1) F1[i][i +\
    \ j] = F[i][j];\n\n  FOR(j, N + M + 1) {\n    vc<mint> f(L);\n    FOR(i, L) f[i]\
    \ = F1[i][j];\n    ntt(f, false);\n    FOR(i, L) F1[i][j] = f[i];\n  }\n  FOR(i,\
    \ L) F1[i] = fps_pow<mint>(F1[i], K);\n  FOR(j, N + M + 1) {\n    vc<mint> f(L);\n\
    \    FOR(i, L) f[i] = F1[i][j];\n    ntt(f, true);\n    FOR(i, L) F1[i][j] = f[i];\n\
    \  }\n  FOR(i, N + 1) FOR(j, M + 1) F[i][j] = F1[i][i + j];\n  return F;\n}\n"
  code: "\n// \u6CE8\u610F (H+W)^2log(H+W) \u6642\u9593\u306B\u306A\u3063\u3066\u3044\
    \u308B\u306E\u3067\u6B63\u65B9\u5F62\u3058\u3083\u306A\u3044\u3068\u30C0\u30E1\
    \u306A\u3055\u307C\u308A\u5B9F\u88C5\ntemplate <typename mint>\nvvc<mint> fps_pow_2d(vvc<mint>\
    \ F, ll K) {\n  int N = len(F) - 1, M = len(F[0]) - 1;\n  int L = 1;\n  while\
    \ (L < N + M + 1) L *= 2;\n\n  vv(mint, F1, L, N + M + 1);\n  FOR(i, N + 1) FOR(j,\
    \ M + 1) F1[i][i + j] = F[i][j];\n\n  FOR(j, N + M + 1) {\n    vc<mint> f(L);\n\
    \    FOR(i, L) f[i] = F1[i][j];\n    ntt(f, false);\n    FOR(i, L) F1[i][j] =\
    \ f[i];\n  }\n  FOR(i, L) F1[i] = fps_pow<mint>(F1[i], K);\n  FOR(j, N + M + 1)\
    \ {\n    vc<mint> f(L);\n    FOR(i, L) f[i] = F1[i][j];\n    ntt(f, true);\n \
    \   FOR(i, L) F1[i][j] = f[i];\n  }\n  FOR(i, N + 1) FOR(j, M + 1) F[i][j] = F1[i][i\
    \ + j];\n  return F;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: poly/2d/fps_pow_2d.hpp
  requiredBy: []
  timestamp: '2025-07-18 14:23:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: poly/2d/fps_pow_2d.hpp
layout: document
redirect_from:
- /library/poly/2d/fps_pow_2d.hpp
- /library/poly/2d/fps_pow_2d.hpp.html
title: poly/2d/fps_pow_2d.hpp
---
