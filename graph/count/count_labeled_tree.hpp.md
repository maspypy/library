---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/count/count_labeled_forest.hpp
    title: graph/count/count_labeled_forest.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/count_labeled_forest.test.cpp
    title: test/mytest/count_labeled_forest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/graph_count.test.cpp
    title: test/mytest/graph_count.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://oeis.org/A000272
  bundledCode: "#line 2 \"graph/count/count_labeled_tree.hpp\"\n\n// https://oeis.org/A000272\n\
    template <typename mint>\nvc<mint> count_labeled_tree(ll nmax) {\n  vc<mint> f(nmax\
    \ + 1);\n  FOR(n, 1, nmax + 1) { f[n] = (n == 1 ? mint(1) : mint(n).pow(n - 2));\
    \ }\n  return f;\n}\n"
  code: "#pragma once\n\n// https://oeis.org/A000272\ntemplate <typename mint>\nvc<mint>\
    \ count_labeled_tree(ll nmax) {\n  vc<mint> f(nmax + 1);\n  FOR(n, 1, nmax + 1)\
    \ { f[n] = (n == 1 ? mint(1) : mint(n).pow(n - 2)); }\n  return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_labeled_tree.hpp
  requiredBy:
  - graph/count/count_labeled_forest.hpp
  timestamp: '2024-01-30 02:35:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/mytest/count_labeled_forest.test.cpp
  - test/mytest/graph_count.test.cpp
documentation_of: graph/count/count_labeled_tree.hpp
layout: document
redirect_from:
- /library/graph/count/count_labeled_tree.hpp
- /library/graph/count/count_labeled_tree.hpp.html
title: graph/count/count_labeled_tree.hpp
---
