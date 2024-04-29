---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/count/count_labeled_biconnected.hpp
    title: graph/count/count_labeled_biconnected.hpp
  - icon: ':x:'
    path: graph/count/count_labeled_bridgeless.hpp
    title: graph/count/count_labeled_bridgeless.hpp
  - icon: ':x:'
    path: poly/compositional_inverse.hpp
    title: poly/compositional_inverse.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library_checker/polynomial/compositional_inverse.test.cpp
    title: test/library_checker/polynomial/compositional_inverse.test.cpp
  - icon: ':x:'
    path: test/mytest/compositional_inverset.test.cpp
    title: test/mytest/compositional_inverset.test.cpp
  - icon: ':x:'
    path: test/mytest/count_labeled_biconnected.test.cpp
    title: test/mytest/count_labeled_biconnected.test.cpp
  - icon: ':x:'
    path: test/mytest/count_labeled_bridgeless.test.cpp
    title: test/mytest/count_labeled_bridgeless.test.cpp
  - icon: ':x:'
    path: test/mytest/power_projection.test.cpp
    title: test/mytest/power_projection.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"poly/power_projection.hpp\"\n// \\sum_j[x^j]f^i \u3092 i=0,1,...,m\n\
    template <typename mint>\nvc<mint> power_projection(vc<mint> wt, vc<mint> f, int\
    \ m) {\n  assert(len(f) == len(wt));\n  if (f.empty()) { return vc<mint>(m + 1,\
    \ mint(0)); }\n  if (f[0] != mint(0)) {\n    mint c = f[0];\n    f[0] = 0;\n \
    \   vc<mint> A = power_projection(wt, f, m);\n    FOR(p, m + 1) A[p] *= fact_inv<mint>(p);\n\
    \    vc<mint> B(m + 1);\n    mint pow = 1;\n    FOR(q, m + 1) B[q] = pow * fact_inv<mint>(q),\
    \ pow *= c;\n    A = convolution<mint>(A, B);\n    A.resize(m + 1);\n    FOR(i,\
    \ m + 1) A[i] *= fact<mint>(i);\n    return A;\n  }\n\n  int n = 1;\n  while (n\
    \ < len(f)) n *= 2;\n\n  for (auto& x: f) x = -x;\n  f.resize(n), wt.resize(n);\n\
    \  reverse(all(wt));\n  vc<mint>&P = wt, &Q = f;\n  P.resize(4 * n), Q.resize(4\
    \ * n);\n\n  vc<mint> W(n);\n  {\n    // bit reverse order\n    vc<int> btr(n);\n\
    \    int log = topbit(n);\n    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i &\
    \ 1) << (log - 1)); }\n    int t = mint::ntt_info().fi;\n    mint r = mint::ntt_info().se;\n\
    \    mint dw = r.inverse().pow((1 << t) / (2 * n));\n    mint w = 1;\n    for\
    \ (auto& i: btr) { W[i] = w, w *= dw; }\n  }\n\n  int k = 1;\n  while (n > 1)\
    \ {\n    /*\n    FFT step\n    04.. -> 048c\n    15.. -> 159d\n    .... -> 26ae\n\
    \    .... -> 37bf\n    */\n\n    auto doubling_y = [&](vc<mint>& A, int l, int\
    \ r) -> void {\n      mint z = W[k / 2].inverse();\n      vc<mint> f(k);\n   \
    \   FOR(i, l, r) {\n        FOR(j, k) f[j] = A[2 * n * j + i];\n        ntt(f,\
    \ 1);\n        mint r = 1;\n        FOR(j, 1, k) r *= z, f[j] *= r;\n        ntt(f,\
    \ 0);\n        FOR(j, k) A[2 * n * (k + j) + i] = f[j];\n      }\n    };\n\n \
    \   auto FFT_x = [&](vc<mint>& A, int l, int r) -> void {\n      vc<mint> f(2\
    \ * n);\n      FOR(j, l, r) {\n        move(A.begin() + 2 * n * j, A.begin() +\
    \ 2 * n * (j + 1), f.begin());\n        ntt(f, 0);\n        move(all(f), A.begin()\
    \ + 2 * n * j);\n      }\n    };\n\n    if (n <= k) {\n      doubling_y(P, 0,\
    \ n), doubling_y(Q, 1, n);\n      FFT_x(P, 0, 2 * k), FFT_x(Q, 0, 2 * k);\n  \
    \  } else {\n      FFT_x(P, 0, k), FFT_x(Q, 0, k);\n      doubling_y(P, 0, 2 *\
    \ n), doubling_y(Q, 0, 2 * n);\n    }\n    FOR(i, 2 * n * k) Q[i] += 1;\n    FOR(i,\
    \ 2 * n * k, 4 * n * k) Q[i] -= 1;\n\n    /*\n    048c -> 0248????\n    159d ->\
    \ ....????\n    26ae\n    37bf\n    */\n    vc<mint> F(2 * n), G(2 * n), f(n),\
    \ g(n);\n    FOR(j, 2 * k) {\n      move(P.begin() + 2 * n * j, P.begin() + 2\
    \ * n * j + 2 * n, F.begin());\n      move(Q.begin() + 2 * n * j, Q.begin() +\
    \ 2 * n * j + 2 * n, G.begin());\n      FOR(i, n) {\n        f[i] = W[i] * (F[2\
    \ * i] * G[2 * i + 1] - F[2 * i + 1] * G[2 * i]);\n        g[i] = G[2 * i] * G[2\
    \ * i + 1];\n      }\n      ntt(f, 1), ntt(g, 1);\n      fill(f.begin() + n /\
    \ 2, f.end(), mint(0));\n      fill(g.begin() + n / 2, g.end(), mint(0));\n  \
    \    move(all(f), P.begin() + n * j);\n      move(all(g), Q.begin() + n * j);\n\
    \    }\n    fill(P.begin() + 2 * n * k, P.end(), mint(0));\n    fill(Q.begin()\
    \ + 2 * n * k, Q.end(), mint(0));\n    FOR(j, 4 * k) Q[n * j] = 0;\n    n /= 2,\
    \ k *= 2;\n  }\n  FOR(i, k) P[i] = P[2 * i];\n  P.resize(k);\n  mint c = mint(1)\
    \ / mint(k);\n  for (auto& x: P) x *= c;\n  ntt(P, 1);\n  reverse(all(P));\n \
    \ P.resize(m + 1);\n  return P;\n}\n"
  code: "// \\sum_j[x^j]f^i \u3092 i=0,1,...,m\ntemplate <typename mint>\nvc<mint>\
    \ power_projection(vc<mint> wt, vc<mint> f, int m) {\n  assert(len(f) == len(wt));\n\
    \  if (f.empty()) { return vc<mint>(m + 1, mint(0)); }\n  if (f[0] != mint(0))\
    \ {\n    mint c = f[0];\n    f[0] = 0;\n    vc<mint> A = power_projection(wt,\
    \ f, m);\n    FOR(p, m + 1) A[p] *= fact_inv<mint>(p);\n    vc<mint> B(m + 1);\n\
    \    mint pow = 1;\n    FOR(q, m + 1) B[q] = pow * fact_inv<mint>(q), pow *= c;\n\
    \    A = convolution<mint>(A, B);\n    A.resize(m + 1);\n    FOR(i, m + 1) A[i]\
    \ *= fact<mint>(i);\n    return A;\n  }\n\n  int n = 1;\n  while (n < len(f))\
    \ n *= 2;\n\n  for (auto& x: f) x = -x;\n  f.resize(n), wt.resize(n);\n  reverse(all(wt));\n\
    \  vc<mint>&P = wt, &Q = f;\n  P.resize(4 * n), Q.resize(4 * n);\n\n  vc<mint>\
    \ W(n);\n  {\n    // bit reverse order\n    vc<int> btr(n);\n    int log = topbit(n);\n\
    \    FOR(i, n) { btr[i] = (btr[i >> 1] >> 1) + ((i & 1) << (log - 1)); }\n   \
    \ int t = mint::ntt_info().fi;\n    mint r = mint::ntt_info().se;\n    mint dw\
    \ = r.inverse().pow((1 << t) / (2 * n));\n    mint w = 1;\n    for (auto& i: btr)\
    \ { W[i] = w, w *= dw; }\n  }\n\n  int k = 1;\n  while (n > 1) {\n    /*\n   \
    \ FFT step\n    04.. -> 048c\n    15.. -> 159d\n    .... -> 26ae\n    .... ->\
    \ 37bf\n    */\n\n    auto doubling_y = [&](vc<mint>& A, int l, int r) -> void\
    \ {\n      mint z = W[k / 2].inverse();\n      vc<mint> f(k);\n      FOR(i, l,\
    \ r) {\n        FOR(j, k) f[j] = A[2 * n * j + i];\n        ntt(f, 1);\n     \
    \   mint r = 1;\n        FOR(j, 1, k) r *= z, f[j] *= r;\n        ntt(f, 0);\n\
    \        FOR(j, k) A[2 * n * (k + j) + i] = f[j];\n      }\n    };\n\n    auto\
    \ FFT_x = [&](vc<mint>& A, int l, int r) -> void {\n      vc<mint> f(2 * n);\n\
    \      FOR(j, l, r) {\n        move(A.begin() + 2 * n * j, A.begin() + 2 * n *\
    \ (j + 1), f.begin());\n        ntt(f, 0);\n        move(all(f), A.begin() + 2\
    \ * n * j);\n      }\n    };\n\n    if (n <= k) {\n      doubling_y(P, 0, n),\
    \ doubling_y(Q, 1, n);\n      FFT_x(P, 0, 2 * k), FFT_x(Q, 0, 2 * k);\n    } else\
    \ {\n      FFT_x(P, 0, k), FFT_x(Q, 0, k);\n      doubling_y(P, 0, 2 * n), doubling_y(Q,\
    \ 0, 2 * n);\n    }\n    FOR(i, 2 * n * k) Q[i] += 1;\n    FOR(i, 2 * n * k, 4\
    \ * n * k) Q[i] -= 1;\n\n    /*\n    048c -> 0248????\n    159d -> ....????\n\
    \    26ae\n    37bf\n    */\n    vc<mint> F(2 * n), G(2 * n), f(n), g(n);\n  \
    \  FOR(j, 2 * k) {\n      move(P.begin() + 2 * n * j, P.begin() + 2 * n * j +\
    \ 2 * n, F.begin());\n      move(Q.begin() + 2 * n * j, Q.begin() + 2 * n * j\
    \ + 2 * n, G.begin());\n      FOR(i, n) {\n        f[i] = W[i] * (F[2 * i] * G[2\
    \ * i + 1] - F[2 * i + 1] * G[2 * i]);\n        g[i] = G[2 * i] * G[2 * i + 1];\n\
    \      }\n      ntt(f, 1), ntt(g, 1);\n      fill(f.begin() + n / 2, f.end(),\
    \ mint(0));\n      fill(g.begin() + n / 2, g.end(), mint(0));\n      move(all(f),\
    \ P.begin() + n * j);\n      move(all(g), Q.begin() + n * j);\n    }\n    fill(P.begin()\
    \ + 2 * n * k, P.end(), mint(0));\n    fill(Q.begin() + 2 * n * k, Q.end(), mint(0));\n\
    \    FOR(j, 4 * k) Q[n * j] = 0;\n    n /= 2, k *= 2;\n  }\n  FOR(i, k) P[i] =\
    \ P[2 * i];\n  P.resize(k);\n  mint c = mint(1) / mint(k);\n  for (auto& x: P)\
    \ x *= c;\n  ntt(P, 1);\n  reverse(all(P));\n  P.resize(m + 1);\n  return P;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: poly/power_projection.hpp
  requiredBy:
  - poly/compositional_inverse.hpp
  - graph/count/count_labeled_biconnected.hpp
  - graph/count/count_labeled_bridgeless.hpp
  timestamp: '2024-04-29 18:22:59+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/power_projection.test.cpp
  - test/mytest/count_labeled_bridgeless.test.cpp
  - test/mytest/count_labeled_biconnected.test.cpp
  - test/mytest/compositional_inverset.test.cpp
  - test/library_checker/polynomial/compositional_inverse.test.cpp
documentation_of: poly/power_projection.hpp
layout: document
redirect_from:
- /library/poly/power_projection.hpp
- /library/poly/power_projection.hpp.html
title: poly/power_projection.hpp
---
