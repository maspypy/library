---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/knight_distance.test.cpp
    title: test/mytest/knight_distance.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/knight_distance.hpp\"\nll knight_distance(ll x, ll\
    \ y) {\n  x = abs(x), y = abs(y);\n  if (x + y == 0) return 0;\n  if (x + y ==\
    \ 1) return 3;\n  if (x == 2 && y == 2) return 4;\n  ll step = (max(x, y) + 1)\
    \ / 2;\n  chmax(step, (x + y + 2) / 3);\n  step += (step ^ x ^ y) & 1;\n  return\
    \ step;\n}\n"
  code: "ll knight_distance(ll x, ll y) {\n  x = abs(x), y = abs(y);\n  if (x + y\
    \ == 0) return 0;\n  if (x + y == 1) return 3;\n  if (x == 2 && y == 2) return\
    \ 4;\n  ll step = (max(x, y) + 1) / 2;\n  chmax(step, (x + y + 2) / 3);\n  step\
    \ += (step ^ x ^ y) & 1;\n  return step;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/knight_distance.hpp
  requiredBy: []
  timestamp: '2022-10-21 20:47:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/knight_distance.test.cpp
documentation_of: other/knight_distance.hpp
layout: document
redirect_from:
- /library/other/knight_distance.hpp
- /library/other/knight_distance.hpp.html
title: other/knight_distance.hpp
---
