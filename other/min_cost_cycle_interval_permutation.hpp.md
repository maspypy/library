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
    - https://codeforces.com/contest/1685/problem/D2
  bundledCode: "#line 1 \"other/min_cost_cycle_interval_permutation.hpp\"\n\n// (a[i],b[i])\
    \ \u304C\u305F\u304F\u3055\u3093\u3042\u308B. \u3053\u308C\u3089\u3092\u30B5\u30A4\
    \u30AF\u30EB\u306B\u4E26\u3079\u3066\n// sum |b[i]-a[i+1]| \u3092\u6700\u5C0F\u5316\
    \u3059\u308B\n// return: {cost, order}\n// \u3068\u308A\u3042\u3048\u305A\u30B3\
    \u30B9\u30C8\u3060\u3051\u3067\u3059\n// https://codeforces.com/contest/1685/problem/D2\n\
    ll min_cost_cycle_interval_permutation(vi A, vi B) {\n  int N = len(A);\n  vi\
    \ X;\n  concat(X, A, B);\n  UNIQUE(X);\n  for (auto& x : A) x = LB(X, x);\n  for\
    \ (auto& x : B) x = LB(X, x);\n\n  int n = len(X);\n  UnionFind uf(n);\n  vc<int>\
    \ LR(n), RL(n);\n  FOR(i, N) {\n    uf.merge(A[i], B[i]);\n    if (A[i] < B[i])\
    \ {\n      LR[A[i]]++, LR[B[i]]--;\n    } else {\n      RL[B[i]]++, RL[A[i]]--;\n\
    \    }\n  }\n  vi Y(n - 1);\n  FOR(i, n - 1) Y[i] = X[i + 1] - X[i];\n  FOR(i,\
    \ n - 1) LR[i + 1] += LR[i], RL[i + 1] += RL[i];\n  ll ans = 0;\n  FOR(i, n -\
    \ 1) {\n    ll k = abs(LR[i] - RL[i]);\n    if (k > 0) uf.merge(i, i + 1);\n \
    \   ans += k * Y[i];\n  }\n  auto I = argsort(Y);\n  for (auto& i : I) {\n   \
    \ if (uf.merge(i, i + 1)) ans += 2 * Y[i];\n  }\n  return ans;\n}\n"
  code: "\n// (a[i],b[i]) \u304C\u305F\u304F\u3055\u3093\u3042\u308B. \u3053\u308C\
    \u3089\u3092\u30B5\u30A4\u30AF\u30EB\u306B\u4E26\u3079\u3066\n// sum |b[i]-a[i+1]|\
    \ \u3092\u6700\u5C0F\u5316\u3059\u308B\n// return: {cost, order}\n// \u3068\u308A\
    \u3042\u3048\u305A\u30B3\u30B9\u30C8\u3060\u3051\u3067\u3059\n// https://codeforces.com/contest/1685/problem/D2\n\
    ll min_cost_cycle_interval_permutation(vi A, vi B) {\n  int N = len(A);\n  vi\
    \ X;\n  concat(X, A, B);\n  UNIQUE(X);\n  for (auto& x : A) x = LB(X, x);\n  for\
    \ (auto& x : B) x = LB(X, x);\n\n  int n = len(X);\n  UnionFind uf(n);\n  vc<int>\
    \ LR(n), RL(n);\n  FOR(i, N) {\n    uf.merge(A[i], B[i]);\n    if (A[i] < B[i])\
    \ {\n      LR[A[i]]++, LR[B[i]]--;\n    } else {\n      RL[B[i]]++, RL[A[i]]--;\n\
    \    }\n  }\n  vi Y(n - 1);\n  FOR(i, n - 1) Y[i] = X[i + 1] - X[i];\n  FOR(i,\
    \ n - 1) LR[i + 1] += LR[i], RL[i + 1] += RL[i];\n  ll ans = 0;\n  FOR(i, n -\
    \ 1) {\n    ll k = abs(LR[i] - RL[i]);\n    if (k > 0) uf.merge(i, i + 1);\n \
    \   ans += k * Y[i];\n  }\n  auto I = argsort(Y);\n  for (auto& i : I) {\n   \
    \ if (uf.merge(i, i + 1)) ans += 2 * Y[i];\n  }\n  return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/min_cost_cycle_interval_permutation.hpp
  requiredBy: []
  timestamp: '2026-04-05 00:48:27+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: other/min_cost_cycle_interval_permutation.hpp
layout: document
redirect_from:
- /library/other/min_cost_cycle_interval_permutation.hpp
- /library/other/min_cost_cycle_interval_permutation.hpp.html
title: other/min_cost_cycle_interval_permutation.hpp
---
