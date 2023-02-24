---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: graph/max_matching_size.hpp
    title: graph/max_matching_size.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/solve_linear.test.cpp
    title: test/library_checker/matrix/solve_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/matching_line_graph.test.cpp
    title: test/mytest/matching_line_graph.test.cpp
  - icon: ':x:'
    path: test/mytest/tutte.test.cpp
    title: test/mytest/tutte.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/matrix_rank.hpp\"\ntemplate <typename T>\nint matrix_rank(const\
    \ int n, const int m, vc<vc<T>> a) {\n  int rk = 0;\n  FOR(j, m) {\n    if (a[rk][j]\
    \ == 0) {\n      FOR3(i, rk + 1, n) if (a[i][j] != 0) {\n        swap(a[rk], a[i]);\n\
    \        break;\n      }\n    }\n    if (a[rk][j] == 0) continue;\n    T c = T(1)\
    \ / a[rk][j];\n    FOR(k, j, m) a[rk][k] *= c;\n    FOR(i, rk + 1, n) {\n    \
    \  T c = a[i][j];\n      FOR3(k, j, m) { a[i][k] -= a[rk][k] * c; }\n    }\n \
    \   ++rk;\n    if (rk == n) break;\n  }\n  return rk;\n}\n"
  code: "template <typename T>\nint matrix_rank(const int n, const int m, vc<vc<T>>\
    \ a) {\n  int rk = 0;\n  FOR(j, m) {\n    if (a[rk][j] == 0) {\n      FOR3(i,\
    \ rk + 1, n) if (a[i][j] != 0) {\n        swap(a[rk], a[i]);\n        break;\n\
    \      }\n    }\n    if (a[rk][j] == 0) continue;\n    T c = T(1) / a[rk][j];\n\
    \    FOR(k, j, m) a[rk][k] *= c;\n    FOR(i, rk + 1, n) {\n      T c = a[i][j];\n\
    \      FOR3(k, j, m) { a[i][k] -= a[rk][k] * c; }\n    }\n    ++rk;\n    if (rk\
    \ == n) break;\n  }\n  return rk;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/matrix_rank.hpp
  requiredBy:
  - graph/max_matching_size.hpp
  timestamp: '2022-11-06 01:50:09+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library_checker/matrix/solve_linear.test.cpp
  - test/mytest/matching_line_graph.test.cpp
  - test/mytest/tutte.test.cpp
documentation_of: linalg/matrix_rank.hpp
layout: document
redirect_from:
- /library/linalg/matrix_rank.hpp
- /library/linalg/matrix_rank.hpp.html
title: linalg/matrix_rank.hpp
---
