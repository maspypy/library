---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  - icon: ':heavy_check_mark:'
    path: seq/p_recursive.hpp
    title: seq/p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/linear_algebra/solve_linear.test.cpp
    title: test/2_library_checker/linear_algebra/solve_linear.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1080_2.test.cpp
    title: test/3_yukicoder/1080_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2166.test.cpp
    title: test/3_yukicoder/2166.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/502_2.test.cpp
    title: test/3_yukicoder/502_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/linalg/solve_linear.hpp
  bundledCode: "#line 1 \"linalg/solve_linear.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/linalg/solve_linear.hpp\n\
    /*\n0 \u884C\u76EE\u306B\u89E3\u306E\u3072\u3068\u3064\u3002\n1\uFF5E\u884C\u76EE\
    \u306B\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u304C\u884C\u30D9\u30AF\u30C8\u30EB\
    \u3068\u3057\u3066\u5165\u308B\u3002\n\u89E3\u306A\u3057 = empty\n*/\ntemplate\
    \ <typename T>\nvc<vc<T>> solve_linear(vc<vc<T>> a, vc<T> b, int n = -1, int m\
    \ = -1) {\n  if (n == -1) {\n    n = len(a);\n    assert(n > 0);\n    m = len(a[0]);\n\
    \  }\n  assert(n == len(a) && n == len(b));\n  int rk = 0;\n  FOR(j, m) {\n  \
    \  if (rk == n) break;\n    FOR(i, rk, n) if (a[i][j] != 0) {\n      swap(a[rk],\
    \ a[i]);\n      swap(b[rk], b[i]);\n      break;\n    }\n    if (a[rk][j] == 0)\
    \ continue;\n    T c = T(1) / a[rk][j];\n    for (auto&& x: a[rk]) x *= c;\n \
    \   b[rk] *= c;\n    FOR(i, n) if (i != rk) {\n      T c = a[i][j];\n      if\
    \ (c == T(0)) continue;\n      b[i] -= b[rk] * c;\n      FOR(k, j, m) { a[i][k]\
    \ -= a[rk][k] * c; }\n    }\n    ++rk;\n  }\n  FOR(i, rk, n) if (b[i] != 0) return\
    \ {};\n  vc<vc<T>> res(1, vc<T>(m));\n  vc<int> pivot(m, -1);\n  int p = 0;\n\
    \  FOR(i, rk) {\n    while (a[i][p] == 0) ++p;\n    res[0][p] = b[i];\n    pivot[p]\
    \ = i;\n  }\n  FOR(j, m) if (pivot[j] == -1) {\n    vc<T> x(m);\n    x[j] = -1;\n\
    \    FOR(k, j) if (pivot[k] != -1) x[k] = a[pivot[k]][j];\n    res.eb(x);\n  }\n\
    \  return res;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/linalg/solve_linear.hpp\n\
    /*\n0 \u884C\u76EE\u306B\u89E3\u306E\u3072\u3068\u3064\u3002\n1\uFF5E\u884C\u76EE\
    \u306B\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u304C\u884C\u30D9\u30AF\u30C8\u30EB\
    \u3068\u3057\u3066\u5165\u308B\u3002\n\u89E3\u306A\u3057 = empty\n*/\ntemplate\
    \ <typename T>\nvc<vc<T>> solve_linear(vc<vc<T>> a, vc<T> b, int n = -1, int m\
    \ = -1) {\n  if (n == -1) {\n    n = len(a);\n    assert(n > 0);\n    m = len(a[0]);\n\
    \  }\n  assert(n == len(a) && n == len(b));\n  int rk = 0;\n  FOR(j, m) {\n  \
    \  if (rk == n) break;\n    FOR(i, rk, n) if (a[i][j] != 0) {\n      swap(a[rk],\
    \ a[i]);\n      swap(b[rk], b[i]);\n      break;\n    }\n    if (a[rk][j] == 0)\
    \ continue;\n    T c = T(1) / a[rk][j];\n    for (auto&& x: a[rk]) x *= c;\n \
    \   b[rk] *= c;\n    FOR(i, n) if (i != rk) {\n      T c = a[i][j];\n      if\
    \ (c == T(0)) continue;\n      b[i] -= b[rk] * c;\n      FOR(k, j, m) { a[i][k]\
    \ -= a[rk][k] * c; }\n    }\n    ++rk;\n  }\n  FOR(i, rk, n) if (b[i] != 0) return\
    \ {};\n  vc<vc<T>> res(1, vc<T>(m));\n  vc<int> pivot(m, -1);\n  int p = 0;\n\
    \  FOR(i, rk) {\n    while (a[i][p] == 0) ++p;\n    res[0][p] = b[i];\n    pivot[p]\
    \ = i;\n  }\n  FOR(j, m) if (pivot[j] == -1) {\n    vc<T> x(m);\n    x[j] = -1;\n\
    \    FOR(k, j) if (pivot[k] != -1) x[k] = a[pivot[k]][j];\n    res.eb(x);\n  }\n\
    \  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/solve_linear.hpp
  requiredBy:
  - poly/sparse_exp_of_div.hpp
  - poly/from_log_differentiation.hpp
  - seq/p_recursive.hpp
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2166.test.cpp
  - test/3_yukicoder/1080_2.test.cpp
  - test/3_yukicoder/502_2.test.cpp
  - test/2_library_checker/linear_algebra/solve_linear.test.cpp
documentation_of: linalg/solve_linear.hpp
layout: document
redirect_from:
- /library/linalg/solve_linear.hpp
- /library/linalg/solve_linear.hpp.html
title: linalg/solve_linear.hpp
---
