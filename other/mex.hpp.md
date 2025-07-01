---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: game/number_and_star.hpp
    title: game/number_and_star.hpp
  - icon: ':x:'
    path: game/solve_partizan_game.hpp
    title: game/solve_partizan_game.hpp
  - icon: ':warning:'
    path: string/inverse_manacher.hpp
    title: string/inverse_manacher.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/partizan.test.cpp
    title: test/1_mytest/partizan.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"other/mex.hpp\"\nint mex(const vc<int>& A) {\n  int n =\
    \ len(A);\n  vc<bool> aru(n + 1);\n  for (auto& x: A)\n    if (x < n) aru[x] =\
    \ 1;\n  int mex = 0;\n  while (aru[mex]) ++mex;\n  return mex;\n}\n"
  code: "int mex(const vc<int>& A) {\n  int n = len(A);\n  vc<bool> aru(n + 1);\n\
    \  for (auto& x: A)\n    if (x < n) aru[x] = 1;\n  int mex = 0;\n  while (aru[mex])\
    \ ++mex;\n  return mex;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: other/mex.hpp
  requiredBy:
  - string/inverse_manacher.hpp
  - game/number_and_star.hpp
  - game/solve_partizan_game.hpp
  timestamp: '2023-10-17 07:10:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/1_mytest/partizan.test.cpp
documentation_of: other/mex.hpp
layout: document
redirect_from:
- /library/other/mex.hpp
- /library/other/mex.hpp.html
title: other/mex.hpp
---
