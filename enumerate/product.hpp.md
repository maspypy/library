---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: enumerate/labeled_tree.hpp
    title: enumerate/labeled_tree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/enumerate_labeled_tree.test.cpp
    title: test/1_mytest/enumerate_labeled_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/enumerate_products.test.cpp
    title: test/1_mytest/enumerate_products.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/fibonacci_search.test.cpp
    title: test/1_mytest/fibonacci_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/prufer.test.cpp
    title: test/1_mytest/prufer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"enumerate/product.hpp\"\n\n// [0, A0) x [0, A1) x ...\n\
    template <typename F>\nvoid enumerate_product(vc<int> A, F query) {\n  int N =\
    \ len(A);\n  auto dfs = [&](auto& dfs, vc<int>& p) -> void {\n    int n = len(p);\n\
    \    if (n == N) return query(p);\n    FOR(x, A[n]) {\n      p.eb(x);\n      dfs(dfs,\
    \ p);\n      p.pop_back();\n    }\n  };\n  vc<int> p;\n  dfs(dfs, p);\n}\n"
  code: "#pragma once\n\n// [0, A0) x [0, A1) x ...\ntemplate <typename F>\nvoid enumerate_product(vc<int>\
    \ A, F query) {\n  int N = len(A);\n  auto dfs = [&](auto& dfs, vc<int>& p) ->\
    \ void {\n    int n = len(p);\n    if (n == N) return query(p);\n    FOR(x, A[n])\
    \ {\n      p.eb(x);\n      dfs(dfs, p);\n      p.pop_back();\n    }\n  };\n  vc<int>\
    \ p;\n  dfs(dfs, p);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/product.hpp
  requiredBy:
  - enumerate/labeled_tree.hpp
  timestamp: '2025-02-09 09:51:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/enumerate_products.test.cpp
  - test/1_mytest/enumerate_labeled_tree.test.cpp
  - test/1_mytest/prufer.test.cpp
  - test/1_mytest/fibonacci_search.test.cpp
documentation_of: enumerate/product.hpp
layout: document
redirect_from:
- /library/enumerate/product.hpp
- /library/enumerate/product.hpp.html
title: enumerate/product.hpp
---
