---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/geometric_sequence_sum.test.cpp
    title: test/mytest/geometric_sequence_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/geometric_sequence_sum.hpp\"\n\n// sum_{i=0}^{n-1}r^i\n\
    template <typename T>\nT geometic_sequence_sum(T r, ll n) {\n  // (r^n, 1+...+r^{n-1})\n\
    \  auto dfs = [&](auto& dfs, ll n) -> pair<T, T> {\n    if (n == 0) return {r,\
    \ T(0)};\n    auto [x, y] = dfs(dfs, n / 2);\n    tie(x, y) = mp(x * x, x * y\
    \ + y);\n    if (n & 1) { tie(x, y) = mp(x * r, y + x); }\n    return {x, y};\n\
    \  };\n  return dfs(dfs, n).se;\n}\n\n// sum_{i=0}^{n-1}i^kr^i \u3092 k=0,1,...,K\n\
    template <typename T, int K>\narray<T, K + 1> geometic_sequence_sum_K(T r, ll\
    \ n) {\n  array<array<T, K + 1>, K + 1> comb{};\n  comb[0][0] = 1;\n  FOR(i, K)\
    \ {\n    FOR(j, i + 1) {\n      comb[i + 1][j] += comb[i][j], comb[i + 1][j +\
    \ 1] += comb[i][j];\n    }\n  }\n\n  // (n, r^n, sum i^kr^i)\n  using X = tuple<T,\
    \ T, array<T, K + 1>>;\n  auto mul = [&](X& l, X& r) -> X {\n    auto& [n1, r1,\
    \ A] = l;\n    auto& [n2, r2, B] = r;\n    array<T, K + 1> C;\n    FOR(k, K +\
    \ 1) {\n      C[k] = A[k];\n      T c = r1;\n      FOR(j, k + 1) { C[k] += comb[k][j]\
    \ * c * B[k - j], c *= n1; }\n    }\n    return {n1 + n2, r1 * r2, C};\n  };\n\
    \n  X res = {T(0), T(1), array<T, K + 1>{}};\n  X a = {T(1), T(r), array<T, K\
    \ + 1>{}};\n  get<2>(a)[0] = 1;\n\n  while (n) {\n    if (n & 1) res = mul(res,\
    \ a);\n    a = mul(a, a), n /= 2;\n  }\n  return get<2>(res);\n}\n"
  code: "\n// sum_{i=0}^{n-1}r^i\ntemplate <typename T>\nT geometic_sequence_sum(T\
    \ r, ll n) {\n  // (r^n, 1+...+r^{n-1})\n  auto dfs = [&](auto& dfs, ll n) ->\
    \ pair<T, T> {\n    if (n == 0) return {r, T(0)};\n    auto [x, y] = dfs(dfs,\
    \ n / 2);\n    tie(x, y) = mp(x * x, x * y + y);\n    if (n & 1) { tie(x, y) =\
    \ mp(x * r, y + x); }\n    return {x, y};\n  };\n  return dfs(dfs, n).se;\n}\n\
    \n// sum_{i=0}^{n-1}i^kr^i \u3092 k=0,1,...,K\ntemplate <typename T, int K>\n\
    array<T, K + 1> geometic_sequence_sum_K(T r, ll n) {\n  array<array<T, K + 1>,\
    \ K + 1> comb{};\n  comb[0][0] = 1;\n  FOR(i, K) {\n    FOR(j, i + 1) {\n    \
    \  comb[i + 1][j] += comb[i][j], comb[i + 1][j + 1] += comb[i][j];\n    }\n  }\n\
    \n  // (n, r^n, sum i^kr^i)\n  using X = tuple<T, T, array<T, K + 1>>;\n  auto\
    \ mul = [&](X& l, X& r) -> X {\n    auto& [n1, r1, A] = l;\n    auto& [n2, r2,\
    \ B] = r;\n    array<T, K + 1> C;\n    FOR(k, K + 1) {\n      C[k] = A[k];\n \
    \     T c = r1;\n      FOR(j, k + 1) { C[k] += comb[k][j] * c * B[k - j], c *=\
    \ n1; }\n    }\n    return {n1 + n2, r1 * r2, C};\n  };\n\n  X res = {T(0), T(1),\
    \ array<T, K + 1>{}};\n  X a = {T(1), T(r), array<T, K + 1>{}};\n  get<2>(a)[0]\
    \ = 1;\n\n  while (n) {\n    if (n & 1) res = mul(res, a);\n    a = mul(a, a),\
    \ n /= 2;\n  }\n  return get<2>(res);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/geometric_sequence_sum.hpp
  requiredBy: []
  timestamp: '2023-10-25 17:42:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/geometric_sequence_sum.test.cpp
documentation_of: seq/geometric_sequence_sum.hpp
layout: document
redirect_from:
- /library/seq/geometric_sequence_sum.hpp
- /library/seq/geometric_sequence_sum.hpp.html
title: seq/geometric_sequence_sum.hpp
---
