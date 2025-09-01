---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: linalg/diagonalize_triangular_matrix.hpp
    title: linalg/diagonalize_triangular_matrix.hpp
  - icon: ':warning:'
    path: other/sliding_puzzle_solver.hpp
    title: other/sliding_puzzle_solver.hpp
  - icon: ':warning:'
    path: poly/coef_of_rational_fps_2d.hpp
    title: poly/coef_of_rational_fps_2d.hpp
  - icon: ':warning:'
    path: test/1_mytest/equal_4square_sum_grid.cpp
    title: test/1_mytest/equal_4square_sum_grid.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2108.test.cpp
    title: test/3_yukicoder/2108.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2907.test.cpp
    title: test/3_yukicoder/2907.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/transpose.hpp\"\ntemplate <typename VC>\nvc<VC> transpose(const\
    \ vc<VC>& A, int H = -1, int W = -1) {\n  if (H == -1) { H = len(A), W = (len(A)\
    \ == 0 ? 0 : len(A[0])); }\n  vc<VC> B(W, VC(H, 0));\n  FOR(x, H) FOR(y, W) B[y][x]\
    \ = A[x][y];\n  return B;\n}\n"
  code: "template <typename VC>\nvc<VC> transpose(const vc<VC>& A, int H = -1, int\
    \ W = -1) {\n  if (H == -1) { H = len(A), W = (len(A) == 0 ? 0 : len(A[0])); }\n\
    \  vc<VC> B(W, VC(H, 0));\n  FOR(x, H) FOR(y, W) B[y][x] = A[x][y];\n  return\
    \ B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/transpose.hpp
  requiredBy:
  - other/sliding_puzzle_solver.hpp
  - poly/coef_of_rational_fps_2d.hpp
  - test/1_mytest/equal_4square_sum_grid.cpp
  - linalg/diagonalize_triangular_matrix.hpp
  timestamp: '2025-01-06 16:30:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2907.test.cpp
  - test/3_yukicoder/2108.test.cpp
documentation_of: linalg/transpose.hpp
layout: document
redirect_from:
- /library/linalg/transpose.hpp
- /library/linalg/transpose.hpp.html
title: linalg/transpose.hpp
---
