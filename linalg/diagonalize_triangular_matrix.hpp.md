---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: linalg/matrix_inv.hpp
    title: linalg/matrix_inv.hpp
  - icon: ':question:'
    path: linalg/transpose.hpp
    title: linalg/transpose.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1540/problem/E
  bundledCode: "#line 1 \"linalg/diagonalize_triangular_matrix.hpp\"\n\n#line 1 \"\
    linalg/transpose.hpp\"\ntemplate <typename VC>\nvc<VC> transpose(const vc<VC>&\
    \ A, int H = -1, int W = -1) {\n  if (H == -1) { H = len(A), W = (len(A) == 0\
    \ ? 0 : len(A[0])); }\n  vc<VC> B(W, VC(H, 0));\n  FOR(x, H) FOR(y, W) B[y][x]\
    \ = A[x][y];\n  return B;\n}\n#line 2 \"linalg/matrix_inv.hpp\"\n\r\n// (det,\
    \ invA) \u3092\u304B\u3048\u3059\r\ntemplate <typename T>\r\npair<T, vc<vc<T>>>\
    \ matrix_inv(vc<vc<T>> A) {\r\n  T det = 1;\r\n  int N = len(A);\r\n  vv(T, B,\
    \ N, N);\r\n  FOR(n, N) B[n][n] = 1;\r\n  FOR(i, N) {\r\n    FOR(k, i, N) if (A[k][i]\
    \ != 0) {\r\n      if (k != i) {\r\n        swap(A[i], A[k]), swap(B[i], B[k]);\r\
    \n        det = -det;\r\n      }\r\n      break;\r\n    }\r\n    if (A[i][i] ==\
    \ 0) return {T(0), {}};\r\n    T c = T(1) / A[i][i];\r\n    det *= A[i][i];\r\n\
    \    FOR(j, i, N) A[i][j] *= c;\r\n    FOR(j, N) B[i][j] *= c;\r\n    FOR(k, N)\
    \ if (i != k) {\r\n      T c = A[k][i];\r\n      FOR(j, i, N) A[k][j] -= A[i][j]\
    \ * c;\r\n      FOR(j, N) B[k][j] -= B[i][j] * c;\r\n    }\r\n  }\r\n  return\
    \ {det, B};\r\n}\r\n#line 4 \"linalg/diagonalize_triangular_matrix.hpp\"\n\n//\
    \ P^{-1}AP = diag(D) \u3068\u306A\u308B (D,P,P^{-1}) \u3092\u8FD4\u3059\n// https://codeforces.com/contest/1540/problem/E\n\
    template <typename mint>\ntuple<vc<mint>, vvc<mint>, vvc<mint>> diagonalize_triangular_matrix(\n\
    \    vvc<mint> A) {\n  int N = len(A);\n  bool lower = 1, upper = 1;\n  FOR(i,\
    \ N) FOR(j, N) {\n    if (i < j) lower = lower && (A[i][j] == 0);\n    if (i >\
    \ j) upper = upper && (A[i][j] == 0);\n  }\n  assert(lower || upper);\n  if (!upper)\
    \ {\n    A = transpose(A);\n    auto [D, P, Q] = diagonalize_triangular_matrix(A);\n\
    \    return {D, transpose(Q), transpose(P)};\n  }\n  assert(upper);\n\n  vc<mint>\
    \ D(N);\n  vv(mint, P, N, N);\n  FOR(k, N) D[k] = A[k][k];\n  FOR(j, N) FOR(i,\
    \ j) assert(D[i] != D[j]);\n\n  FOR(k, N) {\n    mint d = A[k][k];\n    D[k] =\
    \ d;\n    vc<mint> X(N);\n    X[k] = 1;\n    FOR_R(i, k) {\n      mint x = 0;\n\
    \      FOR(j, i + 1, k + 1) x += A[i][j] * X[j];\n      X[i] = x / (d - D[i]);\n\
    \    }\n    FOR(i, N) P[i][k] = X[i];\n  }\n  auto Q = matrix_inv<mint>(P).se;\n\
    \  return {D, P, Q};\n}\n"
  code: "\n#include \"linalg/transpose.hpp\"\n#include \"linalg/matrix_inv.hpp\"\n\
    \n// P^{-1}AP = diag(D) \u3068\u306A\u308B (D,P,P^{-1}) \u3092\u8FD4\u3059\n//\
    \ https://codeforces.com/contest/1540/problem/E\ntemplate <typename mint>\ntuple<vc<mint>,\
    \ vvc<mint>, vvc<mint>> diagonalize_triangular_matrix(\n    vvc<mint> A) {\n \
    \ int N = len(A);\n  bool lower = 1, upper = 1;\n  FOR(i, N) FOR(j, N) {\n   \
    \ if (i < j) lower = lower && (A[i][j] == 0);\n    if (i > j) upper = upper &&\
    \ (A[i][j] == 0);\n  }\n  assert(lower || upper);\n  if (!upper) {\n    A = transpose(A);\n\
    \    auto [D, P, Q] = diagonalize_triangular_matrix(A);\n    return {D, transpose(Q),\
    \ transpose(P)};\n  }\n  assert(upper);\n\n  vc<mint> D(N);\n  vv(mint, P, N,\
    \ N);\n  FOR(k, N) D[k] = A[k][k];\n  FOR(j, N) FOR(i, j) assert(D[i] != D[j]);\n\
    \n  FOR(k, N) {\n    mint d = A[k][k];\n    D[k] = d;\n    vc<mint> X(N);\n  \
    \  X[k] = 1;\n    FOR_R(i, k) {\n      mint x = 0;\n      FOR(j, i + 1, k + 1)\
    \ x += A[i][j] * X[j];\n      X[i] = x / (d - D[i]);\n    }\n    FOR(i, N) P[i][k]\
    \ = X[i];\n  }\n  auto Q = matrix_inv<mint>(P).se;\n  return {D, P, Q};\n}\n"
  dependsOn:
  - linalg/transpose.hpp
  - linalg/matrix_inv.hpp
  isVerificationFile: false
  path: linalg/diagonalize_triangular_matrix.hpp
  requiredBy: []
  timestamp: '2025-07-02 18:15:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/diagonalize_triangular_matrix.hpp
layout: document
redirect_from:
- /library/linalg/diagonalize_triangular_matrix.hpp
- /library/linalg/diagonalize_triangular_matrix.hpp.html
title: linalg/diagonalize_triangular_matrix.hpp
---
