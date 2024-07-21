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
    path: graph/count/count_labeled_connected.hpp
    title: graph/count/count_labeled_connected.hpp
  - icon: ':x:'
    path: graph/count/count_labeled_eulerian.hpp
    title: graph/count/count_labeled_eulerian.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/count_labeled_biconnected.test.cpp
    title: test/mytest/count_labeled_biconnected.test.cpp
  - icon: ':x:'
    path: test/mytest/count_labeled_bridgeless.test.cpp
    title: test/mytest/count_labeled_bridgeless.test.cpp
  - icon: ':x:'
    path: test/mytest/count_labeled_connected.test.cpp
    title: test/mytest/count_labeled_connected.test.cpp
  - icon: ':x:'
    path: test/mytest/count_labeled_eulerian.test.cpp
    title: test/mytest/count_labeled_eulerian.test.cpp
  - icon: ':x:'
    path: test/mytest/count_labeled_undirected.test.cpp
    title: test/mytest/count_labeled_undirected.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://oeis.org/A006125
  bundledCode: "#line 1 \"graph/count/count_labeled_undirected.hpp\"\n// https://oeis.org/A006125\n\
    template <typename mint>\nvc<mint> count_labeled_undirected(int N) {\n  vc<mint>\
    \ F(N + 1);\n  mint pow2 = 1;\n  F[0] = 1;\n  FOR(i, 1, N + 1) F[i] = F[i - 1]\
    \ * pow2, pow2 += pow2;\n  return F;\n}\n"
  code: "// https://oeis.org/A006125\ntemplate <typename mint>\nvc<mint> count_labeled_undirected(int\
    \ N) {\n  vc<mint> F(N + 1);\n  mint pow2 = 1;\n  F[0] = 1;\n  FOR(i, 1, N + 1)\
    \ F[i] = F[i - 1] * pow2, pow2 += pow2;\n  return F;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_labeled_undirected.hpp
  requiredBy:
  - graph/count/count_labeled_bridgeless.hpp
  - graph/count/count_labeled_eulerian.hpp
  - graph/count/count_labeled_connected.hpp
  - graph/count/count_labeled_biconnected.hpp
  timestamp: '2024-01-29 21:47:23+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/count_labeled_undirected.test.cpp
  - test/mytest/count_labeled_bridgeless.test.cpp
  - test/mytest/count_labeled_biconnected.test.cpp
  - test/mytest/count_labeled_connected.test.cpp
  - test/mytest/count_labeled_eulerian.test.cpp
documentation_of: graph/count/count_labeled_undirected.hpp
layout: document
redirect_from:
- /library/graph/count/count_labeled_undirected.hpp
- /library/graph/count/count_labeled_undirected.hpp.html
title: graph/count/count_labeled_undirected.hpp
---
