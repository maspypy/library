---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/nth_element_from_sorted_matrix.test.cpp
    title: test/1_mytest/nth_element_from_sorted_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://uoj.ac/problem/891
  bundledCode: "#line 1 \"convex/nth_element_from_sorted_matrix.hpp\"\n\n// https://uoj.ac/problem/891\n\
    template <typename T, typename F>\nvi nth_element_from_sorted_matrix(ll N, ll\
    \ M, ll K, F f, int k1 = 0, int k2 = 0,\n                                  bool\
    \ tr = false) {\n  if (K == 0) return vi(N, 0);\n  if (N > M) {\n    vi A = nth_element_from_sorted_matrix<T>(M,\
    \ N, K, f, k2, k1, !tr);\n    vi B(N + 1);\n    FOR(i, M) B[0] += 1, B[A[i]] -=\
    \ 1;\n    FOR(i, N) B[i + 1] += B[i];\n    B.pop_back();\n    return B;\n  }\n\
    \  vi A(N);\n  if (K > N) {\n    A = nth_element_from_sorted_matrix<T>(N, M /\
    \ 2, (K - N) / 2, f, k1, k2 + 1,\n                                          tr);\n\
    \    for (auto &a: A) a *= 2;\n    K = K - (K - N) / 2 * 2;\n  }\n  pqg<pair<T,\
    \ int>> que;\n  auto g = [&](ll i, ll j) -> T {\n    i = ((i + 1) << k1) - 1;\n\
    \    j = ((j + 1) << k2) - 1;\n    return (tr ? f(j, i) : f(i, j));\n  };\n  if\
    \ (A[0] < M) que.emplace(g(0, A[0]), 0);\n  FOR(i, 1, N) if (A[i] < A[i - 1])\
    \ que.emplace(g(i, A[i]), i);\n  while (K) {\n    --K;\n    auto [x, i] = POP(que);\n\
    \    A[i]++;\n    if (K == 0) break;\n    if (A[i] < M && (i == 0 || A[i - 1]\
    \ > A[i])) { que.emplace(g(i, A[i]), i); }\n    if (i + 1 < N && A[i + 1] == A[i]\
    \ - 1) {\n      que.emplace(g(i + 1, A[i + 1]), i + 1);\n    }\n  }\n  return\
    \ A;\n}\n"
  code: "\n// https://uoj.ac/problem/891\ntemplate <typename T, typename F>\nvi nth_element_from_sorted_matrix(ll\
    \ N, ll M, ll K, F f, int k1 = 0, int k2 = 0,\n                              \
    \    bool tr = false) {\n  if (K == 0) return vi(N, 0);\n  if (N > M) {\n    vi\
    \ A = nth_element_from_sorted_matrix<T>(M, N, K, f, k2, k1, !tr);\n    vi B(N\
    \ + 1);\n    FOR(i, M) B[0] += 1, B[A[i]] -= 1;\n    FOR(i, N) B[i + 1] += B[i];\n\
    \    B.pop_back();\n    return B;\n  }\n  vi A(N);\n  if (K > N) {\n    A = nth_element_from_sorted_matrix<T>(N,\
    \ M / 2, (K - N) / 2, f, k1, k2 + 1,\n                                       \
    \   tr);\n    for (auto &a: A) a *= 2;\n    K = K - (K - N) / 2 * 2;\n  }\n  pqg<pair<T,\
    \ int>> que;\n  auto g = [&](ll i, ll j) -> T {\n    i = ((i + 1) << k1) - 1;\n\
    \    j = ((j + 1) << k2) - 1;\n    return (tr ? f(j, i) : f(i, j));\n  };\n  if\
    \ (A[0] < M) que.emplace(g(0, A[0]), 0);\n  FOR(i, 1, N) if (A[i] < A[i - 1])\
    \ que.emplace(g(i, A[i]), i);\n  while (K) {\n    --K;\n    auto [x, i] = POP(que);\n\
    \    A[i]++;\n    if (K == 0) break;\n    if (A[i] < M && (i == 0 || A[i - 1]\
    \ > A[i])) { que.emplace(g(i, A[i]), i); }\n    if (i + 1 < N && A[i + 1] == A[i]\
    \ - 1) {\n      que.emplace(g(i + 1, A[i + 1]), i + 1);\n    }\n  }\n  return\
    \ A;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: convex/nth_element_from_sorted_matrix.hpp
  requiredBy: []
  timestamp: '2024-07-24 17:29:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/nth_element_from_sorted_matrix.test.cpp
documentation_of: convex/nth_element_from_sorted_matrix.hpp
layout: document
redirect_from:
- /library/convex/nth_element_from_sorted_matrix.hpp
- /library/convex/nth_element_from_sorted_matrix.hpp.html
title: convex/nth_element_from_sorted_matrix.hpp
---
