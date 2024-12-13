---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: game/number_and_star.hpp
    title: game/number_and_star.hpp
  - icon: ':question:'
    path: game/solve_partizan_game.hpp
    title: game/solve_partizan_game.hpp
  - icon: ':x:'
    path: string/inverse_manacher.hpp
    title: string/inverse_manacher.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/partizan.test.cpp
    title: test/1_mytest/partizan.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc229h.test.cpp
    title: test/5_atcoder/abc229h.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc349g.test.cpp
    title: test/5_atcoder/abc349g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
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
  - game/number_and_star.hpp
  - game/solve_partizan_game.hpp
  - string/inverse_manacher.hpp
  timestamp: '2023-10-17 07:10:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/5_atcoder/abc229h.test.cpp
  - test/5_atcoder/abc349g.test.cpp
  - test/1_mytest/partizan.test.cpp
documentation_of: other/mex.hpp
layout: document
redirect_from:
- /library/other/mex.hpp
- /library/other/mex.hpp.html
title: other/mex.hpp
---
