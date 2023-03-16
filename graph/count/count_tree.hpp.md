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
    - https://oeis.org/A000272
  bundledCode: "#line 1 \"graph/count/count_tree.hpp\"\n\n// https://oeis.org/A000272\n\
    template <typename mint>\nvc<mint> count_tree(ll nmax) {\n  vc<mint> f(nmax +\
    \ 1);\n  FOR(n, 1, nmax + 1) { f[n] = (n == 1 ? mint(1) : mint(n).pow(n - 2));\
    \ }\n  return f;\n}\n"
  code: "\n// https://oeis.org/A000272\ntemplate <typename mint>\nvc<mint> count_tree(ll\
    \ nmax) {\n  vc<mint> f(nmax + 1);\n  FOR(n, 1, nmax + 1) { f[n] = (n == 1 ? mint(1)\
    \ : mint(n).pow(n - 2)); }\n  return f;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/count/count_tree.hpp
  requiredBy: []
  timestamp: '2023-03-17 00:39:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/count/count_tree.hpp
layout: document
redirect_from:
- /library/graph/count/count_tree.hpp
- /library/graph/count/count_tree.hpp.html
title: graph/count/count_tree.hpp
---
