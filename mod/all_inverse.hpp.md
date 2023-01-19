---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: seq/famous/q_binomial.hpp
    title: seq/famous/q_binomial.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/all_inverse.test.cpp
    title: test/mytest/all_inverse.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"mod/all_inverse.hpp\"\ntemplate <typename mint>\nvc<mint>\
    \ all_inverse(vc<mint>& X) {\n  for (auto&& x: X) assert(x != mint(0));\n  int\
    \ N = len(X);\n  vc<mint> res(N + 1);\n  res[0] = mint(1);\n  FOR(i, N) res[i\
    \ + 1] = res[i] * X[i];\n  mint t = res.back().inverse();\n  res.pop_back();\n\
    \  FOR_R(i, N) {\n    res[i] *= t;\n    t *= X[i];\n  }\n  return res;\n}\n"
  code: "#pragma once\ntemplate <typename mint>\nvc<mint> all_inverse(vc<mint>& X)\
    \ {\n  for (auto&& x: X) assert(x != mint(0));\n  int N = len(X);\n  vc<mint>\
    \ res(N + 1);\n  res[0] = mint(1);\n  FOR(i, N) res[i + 1] = res[i] * X[i];\n\
    \  mint t = res.back().inverse();\n  res.pop_back();\n  FOR_R(i, N) {\n    res[i]\
    \ *= t;\n    t *= X[i];\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: mod/all_inverse.hpp
  requiredBy:
  - seq/famous/q_binomial.hpp
  timestamp: '2022-11-23 08:11:54+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/all_inverse.test.cpp
documentation_of: mod/all_inverse.hpp
layout: document
redirect_from:
- /library/mod/all_inverse.hpp
- /library/mod/all_inverse.hpp.html
title: mod/all_inverse.hpp
---
