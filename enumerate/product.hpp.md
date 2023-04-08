---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/enumerate_products.test.cpp
    title: test/mytest/enumerate_products.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/fibonacci_search.test.cpp
    title: test/mytest/fibonacci_search.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc233c.test.cpp
    title: test_atcoder/abc233c.test.cpp
  - icon: ':x:'
    path: test_atcoder/arc153f.test.cpp
    title: test_atcoder/arc153f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"enumerate/product.hpp\"\n// [0, A0) x [0, A1) x ...\ntemplate\
    \ <typename F>\nvoid enumerate_product(vc<int> A, F query) {\n  int N = len(A);\n\
    \  auto dfs = [&](auto& dfs, vc<int>& p) -> void {\n    int n = len(p);\n    if\
    \ (n == N) return query(p);\n    FOR(x, A[n]) {\n      p.eb(x);\n      dfs(dfs,\
    \ p);\n      p.pop_back();\n    }\n  };\n  vc<int> p;\n  dfs(dfs, p);\n}\n"
  code: "// [0, A0) x [0, A1) x ...\ntemplate <typename F>\nvoid enumerate_product(vc<int>\
    \ A, F query) {\n  int N = len(A);\n  auto dfs = [&](auto& dfs, vc<int>& p) ->\
    \ void {\n    int n = len(p);\n    if (n == N) return query(p);\n    FOR(x, A[n])\
    \ {\n      p.eb(x);\n      dfs(dfs, p);\n      p.pop_back();\n    }\n  };\n  vc<int>\
    \ p;\n  dfs(dfs, p);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: enumerate/product.hpp
  requiredBy: []
  timestamp: '2023-01-23 21:04:48+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/enumerate_products.test.cpp
  - test/mytest/fibonacci_search.test.cpp
  - test_atcoder/abc233c.test.cpp
  - test_atcoder/arc153f.test.cpp
documentation_of: enumerate/product.hpp
layout: document
redirect_from:
- /library/enumerate/product.hpp
- /library/enumerate/product.hpp.html
title: enumerate/product.hpp
---
