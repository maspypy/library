---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/count_labeled_forest.hpp
    title: graph/count/count_labeled_forest.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/count_labeled_forest.test.cpp
    title: test/1_mytest/count_labeled_forest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/graph_count.test.cpp
    title: test/1_mytest/graph_count.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://oeis.org/A000272
  bundledCode: "#line 2 \"graph/count/count_labeled_tree.hpp\"\n\n// \u5927\u304D\u3055\
    \ (a1,a2.,,,.ak) \u306E\u6210\u5206\u3092\u6728\u306B\u3059\u308B\u3068\u304D\
    : prod(a)*N^{k-2}\n// https://oeis.org/A000272\ntemplate <typename mint>\nvc<mint>\
    \ count_labeled_tree(ll nmax) {\n  vc<mint> f(nmax + 1);\n  FOR(n, 1, nmax + 1)\
    \ { f[n] = (n == 1 ? mint(1) : mint(n).pow(n - 2)); }\n  return f;\n}\n"
  code: "#pragma once\n\n// \u5927\u304D\u3055 (a1,a2.,,,.ak) \u306E\u6210\u5206\u3092\
    \u6728\u306B\u3059\u308B\u3068\u304D: prod(a)*N^{k-2}\n// https://oeis.org/A000272\n\
    template <typename mint>\nvc<mint> count_labeled_tree(ll nmax) {\n  vc<mint> f(nmax\
    \ + 1);\n  FOR(n, 1, nmax + 1) { f[n] = (n == 1 ? mint(1) : mint(n).pow(n - 2));\
    \ }\n  return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_labeled_tree.hpp
  requiredBy:
  - graph/count/count_labeled_forest.hpp
  timestamp: '2024-08-08 19:22:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/count_labeled_forest.test.cpp
  - test/1_mytest/graph_count.test.cpp
documentation_of: graph/count/count_labeled_tree.hpp
layout: document
redirect_from:
- /library/graph/count/count_labeled_tree.hpp
- /library/graph/count/count_labeled_tree.hpp.html
title: graph/count/count_labeled_tree.hpp
---
