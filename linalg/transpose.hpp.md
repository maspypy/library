---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: other/sliding_puzzle_solver.hpp
    title: other/sliding_puzzle_solver.hpp
  - icon: ':x:'
    path: poly/coef_of_rational_fps_2d.hpp
    title: poly/coef_of_rational_fps_2d.hpp
  - icon: ':warning:'
    path: test/1_mytest/equal_4square_sum_grid.cpp
    title: test/1_mytest/equal_4square_sum_grid.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/3_yukicoder/2108.test.cpp
    title: test/3_yukicoder/2108.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2907.test.cpp
    title: test/3_yukicoder/2907.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/agc058d.test.cpp
    title: test/5_atcoder/agc058d.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/transpose.hpp\"\ntemplate <typename VC>\nvc<VC> transpose(const\
    \ vc<VC>& A, int H = -1, int W = -1) {\n  if (H == -1) { H = len(A), W = (len(A)\
    \ == 0 ? 0 : len(A[0])); }\n  if (H == 0) return {};\n  vc<VC> B(W, VC(H, A[0][0]));\n\
    \  FOR(x, H) FOR(y, W) B[y][x] = A[x][y];\n  return B;\n}\n"
  code: "template <typename VC>\nvc<VC> transpose(const vc<VC>& A, int H = -1, int\
    \ W = -1) {\n  if (H == -1) { H = len(A), W = (len(A) == 0 ? 0 : len(A[0])); }\n\
    \  if (H == 0) return {};\n  vc<VC> B(W, VC(H, A[0][0]));\n  FOR(x, H) FOR(y,\
    \ W) B[y][x] = A[x][y];\n  return B;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/transpose.hpp
  requiredBy:
  - test/1_mytest/equal_4square_sum_grid.cpp
  - poly/coef_of_rational_fps_2d.hpp
  - other/sliding_puzzle_solver.hpp
  timestamp: '2024-10-22 00:27:53+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/2907.test.cpp
  - test/3_yukicoder/2108.test.cpp
  - test/5_atcoder/agc058d.test.cpp
documentation_of: linalg/transpose.hpp
layout: document
redirect_from:
- /library/linalg/transpose.hpp
- /library/linalg/transpose.hpp.html
title: linalg/transpose.hpp
---
