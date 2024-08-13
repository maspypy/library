---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/matrix_inv.hpp
    title: linalg/matrix_inv.hpp
  - icon: ':x:'
    path: linalg/matrix_rank.hpp
    title: linalg/matrix_rank.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/1774.test.cpp
    title: test/3_yukicoder/1774.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://en.wikipedia.org/wiki/Woodbury_matrix_identity
  bundledCode: "#line 1 \"linalg/matrix_inv.hpp\"\n// (det, invA) \u3092\u304B\u3048\
    \u3059\r\ntemplate <typename T>\r\npair<T, vc<vc<T>>> matrix_inv(vc<vc<T>> A)\
    \ {\r\n  T det = 1;\r\n  int N = len(A);\r\n  vv(T, B, N, N);\r\n  FOR(n, N) B[n][n]\
    \ = 1;\r\n  FOR(i, N) {\r\n    FOR(k, i, N) if (A[k][i] != 0) {\r\n      if (k\
    \ != i) {\r\n        swap(A[i], A[k]), swap(B[i], B[k]);\r\n        det = -det;\r\
    \n      }\r\n      break;\r\n    }\r\n    if (A[i][i] == 0) return {T(0), {}};\r\
    \n    T c = T(1) / A[i][i];\r\n    det *= A[i][i];\r\n    FOR(j, i, N) A[i][j]\
    \ *= c;\r\n    FOR(j, N) B[i][j] *= c;\r\n    FOR(k, N) if (i != k) {\r\n    \
    \  T c = A[k][i];\r\n      FOR(j, i, N) A[k][j] -= A[i][j] * c;\r\n      FOR(j,\
    \ N) B[k][j] -= B[i][j] * c;\r\n    }\r\n  }\r\n  return {det, B};\r\n}\r\n#line\
    \ 1 \"linalg/matrix_rank.hpp\"\ntemplate <typename T>\nint matrix_rank(vc<vc<T>>\
    \ a, int n = -1, int m = -1) {\n  if (n == 0) return 0;\n  if (n == -1) { n =\
    \ len(a), m = len(a[0]); }\n  assert(n == len(a) && m == len(a[0]));\n  int rk\
    \ = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    if (a[rk][j] == 0) {\n   \
    \   FOR(i, rk + 1, n) if (a[i][j] != T(0)) {\n        swap(a[rk], a[i]);\n   \
    \     break;\n      }\n    }\n    if (a[rk][j] == 0) continue;\n    T c = T(1)\
    \ / a[rk][j];\n    FOR(k, j, m) a[rk][k] *= c;\n    FOR(i, rk + 1, n) {\n    \
    \  T c = a[i][j];\n      FOR3(k, j, m) { a[i][k] -= a[rk][k] * c; }\n    }\n \
    \   ++rk;\n  }\n  return rk;\n}\n#line 3 \"linalg/matrix_lowrank_update.hpp\"\n\
    \n// https://en.wikipedia.org/wiki/Woodbury_matrix_identity\ntemplate <typename\
    \ T>\nstruct Lowrank_Update {\n  int n;\n  vvc<T> A, IA;\n  Lowrank_Update() {}\n\
    \  Lowrank_Update(vvc<T> A) : A(A) {\n    n = len(A);\n    T det;\n    tie(det,\
    \ IA) = matrix_inv(A);\n    assert(det != T(0));\n  }\n\n  // A + UV \u304C\u53EF\
    \u9006\u306A\u3089\u8DB3\u3057\u3066 true, \u305D\u3046\u3067\u306A\u3044\u306A\
    \u3089\u4F55\u3082\u305B\u305A false.\n  bool update(vvc<T> &U, vvc<T> &V, bool\
    \ update_A) {\n    int r = len(V);\n    assert(len(U) == n && len(U[0]) == r);\n\
    \    assert(len(V) == r && len(V[0]) == n);\n    vc<T> X(n), Y(n);\n    FOR(k,\
    \ r) {\n      FOR(i, n) X[i] = U[i][k], Y[i] = V[k][i];\n      rank_one_update(X,\
    \ Y, update_A);\n    }\n  }\n\n  // A + c U transepose(V) \u304C\u53EF\u9006\u306A\
    \u3089\u8DB3\u3057\u3066 true, \u305D\u3046\u3067\u306A\u3044\u306A\u3089\u4F55\
    \u3082\u305B\u305A false.\n  // O(n^2)\n  bool rank_one_update(T c, vc<T> &U,\
    \ vc<T> &V, bool update_A) {\n    vc<int> I, J;\n    FOR(i, n) if (U[i] != T(0))\
    \ I.eb(i);\n    FOR(i, n) if (V[i] != T(0)) J.eb(i);\n    T x = 0;\n    for (auto\
    \ &j: J) {\n      for (auto &i: I) { x += V[j] * IA[j][i] * U[i]; }\n    }\n \
    \   x = T(1) + c * x;\n    if (x == T(0)) return false;\n    if (update_A) {\n\
    \      for (auto &i: I) {\n        T t = c * U[i];\n        for (auto &j: J) {\
    \ A[i][j] += t * V[j]; }\n      }\n    }\n    x = c / x;\n    vc<T> L(n), R(n);\n\
    \    for (auto &i: I) {\n      T u = U[i] * x;\n      FOR(j, n) L[j] += IA[j][i]\
    \ * u;\n    }\n    for (auto &j: J) { FOR(i, n) R[i] += V[j] * IA[j][i]; }\n \
    \   FOR(i, n) FOR(j, n) IA[i][j] -= L[i] * R[j];\n    return true;\n  }\n};\n\n\
    // lowrank update / rank query\ntemplate <typename mint>\nstruct Matrix_Rank_Lowrank_Update\
    \ {\n  int n;\n  bool is_prepared;\n  Lowrank_Update<mint> X;\n  vc<pair<vc<mint>,\
    \ vc<mint>>> dat;\n\n  Matrix_Rank_Lowrank_Update(int n) : n(n) {\n    vv(mint,\
    \ A, n, n, mint(0));\n    build(A, 0);\n  }\n  Matrix_Rank_Lowrank_Update(vvc<mint>\
    \ &A) : n(len(A)) { build(A); }\n\n  void build(vvc<mint> A, int r = -1) {\n \
    \   if (r == -1) r = matrix_rank(A);\n    FOR(n - r) {\n      vc<mint> x(n), y(n);\n\
    \      FOR(i, n) x[i] = RNG(0, mint::get_mod());\n      FOR(i, n) y[i] = RNG(0,\
    \ mint::get_mod());\n      dat.eb(x, y);\n      FOR(i, n) FOR(j, n) A[i][j] +=\
    \ x[i] * y[j];\n    }\n    X = Lowrank_Update(A);\n    is_prepared = 1;\n  }\n\
    \n  int rank() {\n    while (!is_prepared && !dat.empty()) {\n      auto [x, y]\
    \ = dat.back();\n      if (!X.rank_one_update(-1, x, y, false)) break;\n     \
    \ POP(dat);\n    }\n    is_prepared = 1;\n    return n - len(dat);\n  }\n\n  void\
    \ rank_one_update(mint c, vc<mint> &U, vc<mint> &V) {\n    is_prepared = 0;\n\
    \    while (!X.rank_one_update(c, U, V, false)) {\n      vc<mint> x(n), y(n);\n\
    \      FOR(i, n) x[i] = RNG(0, mint::get_mod());\n      FOR(i, n) y[i] = RNG(0,\
    \ mint::get_mod());\n      dat.eb(x, y);\n      X.rank_one_update(1, x, y, false);\n\
    \    }\n  }\n};\n"
  code: "#include \"linalg/matrix_inv.hpp\"\n#include \"linalg/matrix_rank.hpp\"\n\
    \n// https://en.wikipedia.org/wiki/Woodbury_matrix_identity\ntemplate <typename\
    \ T>\nstruct Lowrank_Update {\n  int n;\n  vvc<T> A, IA;\n  Lowrank_Update() {}\n\
    \  Lowrank_Update(vvc<T> A) : A(A) {\n    n = len(A);\n    T det;\n    tie(det,\
    \ IA) = matrix_inv(A);\n    assert(det != T(0));\n  }\n\n  // A + UV \u304C\u53EF\
    \u9006\u306A\u3089\u8DB3\u3057\u3066 true, \u305D\u3046\u3067\u306A\u3044\u306A\
    \u3089\u4F55\u3082\u305B\u305A false.\n  bool update(vvc<T> &U, vvc<T> &V, bool\
    \ update_A) {\n    int r = len(V);\n    assert(len(U) == n && len(U[0]) == r);\n\
    \    assert(len(V) == r && len(V[0]) == n);\n    vc<T> X(n), Y(n);\n    FOR(k,\
    \ r) {\n      FOR(i, n) X[i] = U[i][k], Y[i] = V[k][i];\n      rank_one_update(X,\
    \ Y, update_A);\n    }\n  }\n\n  // A + c U transepose(V) \u304C\u53EF\u9006\u306A\
    \u3089\u8DB3\u3057\u3066 true, \u305D\u3046\u3067\u306A\u3044\u306A\u3089\u4F55\
    \u3082\u305B\u305A false.\n  // O(n^2)\n  bool rank_one_update(T c, vc<T> &U,\
    \ vc<T> &V, bool update_A) {\n    vc<int> I, J;\n    FOR(i, n) if (U[i] != T(0))\
    \ I.eb(i);\n    FOR(i, n) if (V[i] != T(0)) J.eb(i);\n    T x = 0;\n    for (auto\
    \ &j: J) {\n      for (auto &i: I) { x += V[j] * IA[j][i] * U[i]; }\n    }\n \
    \   x = T(1) + c * x;\n    if (x == T(0)) return false;\n    if (update_A) {\n\
    \      for (auto &i: I) {\n        T t = c * U[i];\n        for (auto &j: J) {\
    \ A[i][j] += t * V[j]; }\n      }\n    }\n    x = c / x;\n    vc<T> L(n), R(n);\n\
    \    for (auto &i: I) {\n      T u = U[i] * x;\n      FOR(j, n) L[j] += IA[j][i]\
    \ * u;\n    }\n    for (auto &j: J) { FOR(i, n) R[i] += V[j] * IA[j][i]; }\n \
    \   FOR(i, n) FOR(j, n) IA[i][j] -= L[i] * R[j];\n    return true;\n  }\n};\n\n\
    // lowrank update / rank query\ntemplate <typename mint>\nstruct Matrix_Rank_Lowrank_Update\
    \ {\n  int n;\n  bool is_prepared;\n  Lowrank_Update<mint> X;\n  vc<pair<vc<mint>,\
    \ vc<mint>>> dat;\n\n  Matrix_Rank_Lowrank_Update(int n) : n(n) {\n    vv(mint,\
    \ A, n, n, mint(0));\n    build(A, 0);\n  }\n  Matrix_Rank_Lowrank_Update(vvc<mint>\
    \ &A) : n(len(A)) { build(A); }\n\n  void build(vvc<mint> A, int r = -1) {\n \
    \   if (r == -1) r = matrix_rank(A);\n    FOR(n - r) {\n      vc<mint> x(n), y(n);\n\
    \      FOR(i, n) x[i] = RNG(0, mint::get_mod());\n      FOR(i, n) y[i] = RNG(0,\
    \ mint::get_mod());\n      dat.eb(x, y);\n      FOR(i, n) FOR(j, n) A[i][j] +=\
    \ x[i] * y[j];\n    }\n    X = Lowrank_Update(A);\n    is_prepared = 1;\n  }\n\
    \n  int rank() {\n    while (!is_prepared && !dat.empty()) {\n      auto [x, y]\
    \ = dat.back();\n      if (!X.rank_one_update(-1, x, y, false)) break;\n     \
    \ POP(dat);\n    }\n    is_prepared = 1;\n    return n - len(dat);\n  }\n\n  void\
    \ rank_one_update(mint c, vc<mint> &U, vc<mint> &V) {\n    is_prepared = 0;\n\
    \    while (!X.rank_one_update(c, U, V, false)) {\n      vc<mint> x(n), y(n);\n\
    \      FOR(i, n) x[i] = RNG(0, mint::get_mod());\n      FOR(i, n) y[i] = RNG(0,\
    \ mint::get_mod());\n      dat.eb(x, y);\n      X.rank_one_update(1, x, y, false);\n\
    \    }\n  }\n};"
  dependsOn:
  - linalg/matrix_inv.hpp
  - linalg/matrix_rank.hpp
  isVerificationFile: false
  path: linalg/matrix_lowrank_update.hpp
  requiredBy: []
  timestamp: '2024-01-19 02:38:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1774.test.cpp
documentation_of: linalg/matrix_lowrank_update.hpp
layout: document
redirect_from:
- /library/linalg/matrix_lowrank_update.hpp
- /library/linalg/matrix_lowrank_update.hpp.html
title: linalg/matrix_lowrank_update.hpp
---
