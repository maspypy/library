---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/maximum_matching_size.hpp
    title: graph/maximum_matching_size.hpp
  - icon: ':x:'
    path: linalg/matrix_lowrank_update.hpp
    title: linalg/matrix_lowrank_update.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/1_mytest/matching.test.cpp
    title: test/1_mytest/matching.test.cpp
  - icon: ':x:'
    path: test/1_mytest/matching_line_graph.test.cpp
    title: test/1_mytest/matching_line_graph.test.cpp
  - icon: ':x:'
    path: test/1_mytest/tutte.test.cpp
    title: test/1_mytest/tutte.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/graph/general_matching.test.cpp
    title: test/2_library_checker/graph/general_matching.test.cpp
  - icon: ':x:'
    path: test/2_library_checker/linear_algebra/solve_linear.test.cpp
    title: test/2_library_checker/linear_algebra/solve_linear.test.cpp
  - icon: ':x:'
    path: test/3_yukicoder/1774.test.cpp
    title: test/3_yukicoder/1774.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  - linalg/matrix_lowrank_update.hpp
  - graph/maximum_matching_size.hpp
  timestamp: '2024-01-19 02:38:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/3_yukicoder/1774.test.cpp
  - test/1_mytest/matching_line_graph.test.cpp
  - test/1_mytest/tutte.test.cpp
  - test/1_mytest/matching.test.cpp
  - test/2_library_checker/linear_algebra/solve_linear.test.cpp
  - test/2_library_checker/graph/general_matching.test.cpp
documentation_of: linalg/matrix_rank.hpp
layout: document
redirect_from:
- /library/linalg/matrix_rank.hpp
- /library/linalg/matrix_rank.hpp.html
title: linalg/matrix_rank.hpp
---
