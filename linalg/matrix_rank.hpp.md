---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/maximum_matching_size.hpp
    title: graph/maximum_matching_size.hpp
  - icon: ':heavy_check_mark:'
    path: linalg/matrix_lowrank_update.hpp
    title: linalg/matrix_lowrank_update.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/general_matching.test.cpp
    title: test/library_checker/graph/general_matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/solve_linear.test.cpp
    title: test/library_checker/matrix/solve_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching.test.cpp
    title: test/mytest/matching.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1774.test.cpp
    title: test/yukicoder/1774.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/matrix_rank.hpp\"\ntemplate <typename T>\nint matrix_rank(vc<vc<T>>\
    \ a, int n = -1, int m = -1) {\n  if (n == 0) return 0;\n  if (n == -1) { n =\
    \ len(a), m = len(a[0]); }\n  assert(n == len(a) && m == len(a[0]));\n  int rk\
    \ = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    if (a[rk][j] == 0) {\n   \
    \   FOR(i, rk + 1, n) if (a[i][j] != T(0)) {\n        swap(a[rk], a[i]);\n   \
    \     break;\n      }\n    }\n    if (a[rk][j] == 0) continue;\n    T c = T(1)\
    \ / a[rk][j];\n    FOR(k, j, m) a[rk][k] *= c;\n    FOR(i, rk + 1, n) {\n    \
    \  T c = a[i][j];\n      FOR3(k, j, m) { a[i][k] -= a[rk][k] * c; }\n    }\n \
    \   ++rk;\n  }\n  return rk;\n}\n"
  code: "template <typename T>\nint matrix_rank(vc<vc<T>> a, int n = -1, int m = -1)\
    \ {\n  if (n == 0) return 0;\n  if (n == -1) { n = len(a), m = len(a[0]); }\n\
    \  assert(n == len(a) && m == len(a[0]));\n  int rk = 0;\n  FOR(j, m) {\n    if\
    \ (rk == n) break;\n    if (a[rk][j] == 0) {\n      FOR(i, rk + 1, n) if (a[i][j]\
    \ != T(0)) {\n        swap(a[rk], a[i]);\n        break;\n      }\n    }\n   \
    \ if (a[rk][j] == 0) continue;\n    T c = T(1) / a[rk][j];\n    FOR(k, j, m) a[rk][k]\
    \ *= c;\n    FOR(i, rk + 1, n) {\n      T c = a[i][j];\n      FOR3(k, j, m) {\
    \ a[i][k] -= a[rk][k] * c; }\n    }\n    ++rk;\n  }\n  return rk;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/matrix_rank.hpp
  requiredBy:
  - graph/maximum_matching_size.hpp
  - linalg/matrix_lowrank_update.hpp
  timestamp: '2024-01-19 02:38:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1774.test.cpp
  - test/mytest/matching.test.cpp
  - test/mytest/tutte.test.cpp
  - test/mytest/matching_line_graph.test.cpp
  - test/library_checker/graph/general_matching.test.cpp
  - test/library_checker/matrix/solve_linear.test.cpp
documentation_of: linalg/matrix_rank.hpp
layout: document
redirect_from:
- /library/linalg/matrix_rank.hpp
- /library/linalg/matrix_rank.hpp.html
title: linalg/matrix_rank.hpp
---
