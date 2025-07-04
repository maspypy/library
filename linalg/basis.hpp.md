---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/adjugate_matrix.hpp
    title: linalg/adjugate_matrix.hpp
  - icon: ':question:'
    path: linalg/frobenius.hpp
    title: linalg/frobenius.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
    title: test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/linear_algebra/pow_of_matrix_frobenius.test.cpp
    title: test/2_library_checker/linear_algebra/pow_of_matrix_frobenius.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linalg/basis.hpp\"\n\n// basis[i]: i \u756A\u76EE\u306B\u8FFD\
    \u52A0\u6210\u529F\u3057\u305F\u3082\u306E. \u5225\u306E\u30E9\u30D9\u30EB\u304C\
    \u3042\u308B\u306A\u3089\u5916\u3067\u7BA1\u7406\u3059\u308B.\n// rbasis: \u4E0A\
    \u4E09\u89D2\u5316\u3055\u308C\u305F\u57FA\u5E95. [i][i]==1.\n// way[i][j]: rbasis[i]\
    \ = sum way[i][j] basis[j]\ntemplate <typename mint>\nstruct Basis {\n  int n,\
    \ rank;\n  vvc<mint> basis;\n  vvc<mint> rbasis;\n  vvc<mint> way;\n  Basis(int\
    \ max_dim) : n(max_dim), rank(0), basis{} {\n    rbasis.assign(max_dim, vc<mint>(max_dim));\n\
    \    way.assign(max_dim, vc<mint>(max_dim));\n  }\n\n  // return : (sum==X \u306B\
    \u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5)\n  pair<bool, vc<mint>> solve(vc<mint>\
    \ X) {\n    vc<mint> CF(n);\n    FOR(i, n) {\n      if (rbasis[i][i] == mint(1))\
    \ {\n        CF[i] = X[i];\n        FOR(j, i, n) X[j] -= CF[i] * rbasis[i][j];\n\
    \      }\n    }\n    for (auto& x: X) {\n      if (x != mint(0)) { return {false,\
    \ {}}; }\n    }\n    vc<mint> ANS(rank);\n    FOR(i, n) { FOR(j, rank) ANS[j]\
    \ += CF[i] * way[i][j]; }\n    return {true, ANS};\n  }\n\n  // return : (sum==x\
    \ \u306B\u3067\u304D\u308B\u304B, \u305D\u306E\u65B9\u6CD5). false \u306E\u5834\
    \u5408\u306B\u306F\u8FFD\u52A0\u3059\u308B\n  pair<bool, vc<mint>> solve_or_add(vc<mint>\
    \ X) {\n    vc<mint> Y = X;\n    vc<mint> CF(n);\n    FOR(i, n) {\n      if (rbasis[i][i]\
    \ == mint(1)) {\n        CF[i] = X[i];\n        FOR(j, i, n) X[j] -= CF[i] * rbasis[i][j];\n\
    \      }\n    }\n    int p = [&]() -> int {\n      FOR(i, n) if (X[i] != mint(0))\
    \ return i;\n      return -1;\n    }();\n    if (p == -1) {\n      vc<mint> ANS(rank);\n\
    \      FOR(i, n) { FOR(j, rank) ANS[j] += CF[i] * way[i][j]; }\n      return {true,\
    \ ANS};\n    }\n    mint c = X[p].inverse();\n    FOR(j, p, n) X[j] *= c;\n  \
    \  FOR(i, n) CF[i] *= c;\n    basis.eb(Y), rbasis[p] = X;\n    way[p][rank] =\
    \ c;\n    FOR(i, n) { FOR(j, rank) way[p][j] -= CF[i] * way[i][j]; }\n    ++rank;\n\
    \    return {false, {}};\n  }\n\n  // rank==r \u306E\u6642\u70B9\u307E\u3067\u623B\
    \u3059. Frobenius Form \u7528.\n  void rollback(int r) {\n    while (rank > r)\
    \ {\n      --rank;\n      POP(basis);\n      FOR(i, n) if (way[i][rank] != mint(0))\
    \ {\n        fill(all(rbasis[i]), mint(0));\n        fill(all(way[i]), mint(0));\n\
    \      }\n    }\n  }\n};\n"
  code: "#pragma once\n\n// basis[i]: i \u756A\u76EE\u306B\u8FFD\u52A0\u6210\u529F\
    \u3057\u305F\u3082\u306E. \u5225\u306E\u30E9\u30D9\u30EB\u304C\u3042\u308B\u306A\
    \u3089\u5916\u3067\u7BA1\u7406\u3059\u308B.\n// rbasis: \u4E0A\u4E09\u89D2\u5316\
    \u3055\u308C\u305F\u57FA\u5E95. [i][i]==1.\n// way[i][j]: rbasis[i] = sum way[i][j]\
    \ basis[j]\ntemplate <typename mint>\nstruct Basis {\n  int n, rank;\n  vvc<mint>\
    \ basis;\n  vvc<mint> rbasis;\n  vvc<mint> way;\n  Basis(int max_dim) : n(max_dim),\
    \ rank(0), basis{} {\n    rbasis.assign(max_dim, vc<mint>(max_dim));\n    way.assign(max_dim,\
    \ vc<mint>(max_dim));\n  }\n\n  // return : (sum==X \u306B\u3067\u304D\u308B\u304B\
    , \u305D\u306E\u65B9\u6CD5)\n  pair<bool, vc<mint>> solve(vc<mint> X) {\n    vc<mint>\
    \ CF(n);\n    FOR(i, n) {\n      if (rbasis[i][i] == mint(1)) {\n        CF[i]\
    \ = X[i];\n        FOR(j, i, n) X[j] -= CF[i] * rbasis[i][j];\n      }\n    }\n\
    \    for (auto& x: X) {\n      if (x != mint(0)) { return {false, {}}; }\n   \
    \ }\n    vc<mint> ANS(rank);\n    FOR(i, n) { FOR(j, rank) ANS[j] += CF[i] * way[i][j];\
    \ }\n    return {true, ANS};\n  }\n\n  // return : (sum==x \u306B\u3067\u304D\u308B\
    \u304B, \u305D\u306E\u65B9\u6CD5). false \u306E\u5834\u5408\u306B\u306F\u8FFD\u52A0\
    \u3059\u308B\n  pair<bool, vc<mint>> solve_or_add(vc<mint> X) {\n    vc<mint>\
    \ Y = X;\n    vc<mint> CF(n);\n    FOR(i, n) {\n      if (rbasis[i][i] == mint(1))\
    \ {\n        CF[i] = X[i];\n        FOR(j, i, n) X[j] -= CF[i] * rbasis[i][j];\n\
    \      }\n    }\n    int p = [&]() -> int {\n      FOR(i, n) if (X[i] != mint(0))\
    \ return i;\n      return -1;\n    }();\n    if (p == -1) {\n      vc<mint> ANS(rank);\n\
    \      FOR(i, n) { FOR(j, rank) ANS[j] += CF[i] * way[i][j]; }\n      return {true,\
    \ ANS};\n    }\n    mint c = X[p].inverse();\n    FOR(j, p, n) X[j] *= c;\n  \
    \  FOR(i, n) CF[i] *= c;\n    basis.eb(Y), rbasis[p] = X;\n    way[p][rank] =\
    \ c;\n    FOR(i, n) { FOR(j, rank) way[p][j] -= CF[i] * way[i][j]; }\n    ++rank;\n\
    \    return {false, {}};\n  }\n\n  // rank==r \u306E\u6642\u70B9\u307E\u3067\u623B\
    \u3059. Frobenius Form \u7528.\n  void rollback(int r) {\n    while (rank > r)\
    \ {\n      --rank;\n      POP(basis);\n      FOR(i, n) if (way[i][rank] != mint(0))\
    \ {\n        fill(all(rbasis[i]), mint(0));\n        fill(all(way[i]), mint(0));\n\
    \      }\n    }\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/basis.hpp
  requiredBy:
  - linalg/adjugate_matrix.hpp
  - linalg/frobenius.hpp
  timestamp: '2024-11-01 21:56:32+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/2_library_checker/linear_algebra/pow_of_matrix_frobenius.test.cpp
  - test/2_library_checker/linear_algebra/adjugate_matrix.test.cpp
documentation_of: linalg/basis.hpp
layout: document
redirect_from:
- /library/linalg/basis.hpp
- /library/linalg/basis.hpp.html
title: linalg/basis.hpp
---
