---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/count/BEST.hpp
    title: graph/count/BEST.hpp
  - icon: ':heavy_check_mark:'
    path: graph/count/count_spanning_tree.hpp
    title: graph/count/count_spanning_tree.hpp
  - icon: ':question:'
    path: linalg/blackbox/det.hpp
    title: linalg/blackbox/det.hpp
  - icon: ':question:'
    path: linalg/blackbox/min_poly.hpp
    title: linalg/blackbox/min_poly.hpp
  - icon: ':question:'
    path: seq/interpolate_linear_rec.hpp
    title: seq/interpolate_linear_rec.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/min_poly.test.cpp
    title: test/1_mytest/min_poly.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
    title: test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/counting_eulerian_dense.test.cpp
    title: test/2_library_checker/graph/counting_eulerian_dense.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
    title: test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/sparse_matrix_det.test.cpp
    title: test/2_library_checker/linear_algebra/sparse_matrix_det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/other/find_linear_recurrence.test.cpp
    title: test/2_library_checker/other/find_linear_recurrence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1500.test.cpp
    title: test/3_yukicoder/1500.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1516.test.cpp
    title: test/3_yukicoder/1516.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1547.test.cpp
    title: test/3_yukicoder/1547.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1561.test.cpp
    title: test/3_yukicoder/1561.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1755.test.cpp
    title: test/3_yukicoder/1755.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1844.test.cpp
    title: test/3_yukicoder/1844.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2305.test.cpp
    title: test/3_yukicoder/2305.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/2877.test.cpp
    title: test/3_yukicoder/2877.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/310.test.cpp
    title: test/3_yukicoder/310.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/541.test.cpp
    title: test/3_yukicoder/541.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/578.test.cpp
    title: test/3_yukicoder/578.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/579.test.cpp
    title: test/3_yukicoder/579.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"seq/find_linear_rec.hpp\"\n\r\ntemplate <typename mint>\r\
    \nvector<mint> find_linear_rec(vector<mint>& A) {\r\n  int N = len(A);\r\n  vc<mint>\
    \ B = {1}, C = {1};\r\n  int l = 0, m = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\
    \n    mint d = A[i];\r\n    FOR3(j, 1, l + 1) { d += C[j] * A[i - j]; }\r\n  \
    \  if (d == 0) {\r\n      ++m;\r\n      continue;\r\n    }\r\n    auto tmp = C;\r\
    \n    mint q = d / p;\r\n    if (len(C) < len(B) + m) C.insert(C.end(), len(B)\
    \ + m - len(C), 0);\r\n    FOR(j, len(B)) C[j + m] -= q * B[j];\r\n    if (l +\
    \ l <= i) {\r\n      B = tmp;\r\n      l = i + 1 - l, m = 1;\r\n      p = d;\r\
    \n    } else {\r\n      ++m;\r\n    }\r\n  }\r\n  return C;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <typename mint>\r\nvector<mint> find_linear_rec(vector<mint>&\
    \ A) {\r\n  int N = len(A);\r\n  vc<mint> B = {1}, C = {1};\r\n  int l = 0, m\
    \ = 1;\r\n  mint p = 1;\r\n  FOR(i, N) {\r\n    mint d = A[i];\r\n    FOR3(j,\
    \ 1, l + 1) { d += C[j] * A[i - j]; }\r\n    if (d == 0) {\r\n      ++m;\r\n \
    \     continue;\r\n    }\r\n    auto tmp = C;\r\n    mint q = d / p;\r\n    if\
    \ (len(C) < len(B) + m) C.insert(C.end(), len(B) + m - len(C), 0);\r\n    FOR(j,\
    \ len(B)) C[j + m] -= q * B[j];\r\n    if (l + l <= i) {\r\n      B = tmp;\r\n\
    \      l = i + 1 - l, m = 1;\r\n      p = d;\r\n    } else {\r\n      ++m;\r\n\
    \    }\r\n  }\r\n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/find_linear_rec.hpp
  requiredBy:
  - linalg/blackbox/min_poly.hpp
  - linalg/blackbox/det.hpp
  - graph/count/BEST.hpp
  - graph/count/count_spanning_tree.hpp
  - seq/interpolate_linear_rec.hpp
  timestamp: '2022-05-11 21:07:53+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/3_yukicoder/1500.test.cpp
  - test/3_yukicoder/1547.test.cpp
  - test/3_yukicoder/2877.test.cpp
  - test/3_yukicoder/1755.test.cpp
  - test/3_yukicoder/1516.test.cpp
  - test/3_yukicoder/1844.test.cpp
  - test/3_yukicoder/579.test.cpp
  - test/3_yukicoder/2305.test.cpp
  - test/3_yukicoder/310.test.cpp
  - test/3_yukicoder/1561.test.cpp
  - test/3_yukicoder/578.test.cpp
  - test/3_yukicoder/541.test.cpp
  - test/2_library_checker/other/find_linear_recurrence.test.cpp
  - test/2_library_checker/graph/counting_eulerian_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_undirected_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_directed_dense.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_directed_sparse.test.cpp
  - test/2_library_checker/graph/count_spanning_tree_undirected_sparse.test.cpp
  - test/2_library_checker/graph/counting_eulerian_sparse.test.cpp
  - test/2_library_checker/linear_algebra/sparse_matrix_det.test.cpp
  - test/1_mytest/min_poly.test.cpp
documentation_of: seq/find_linear_rec.hpp
layout: document
redirect_from:
- /library/seq/find_linear_rec.hpp
- /library/seq/find_linear_rec.hpp.html
title: seq/find_linear_rec.hpp
---
