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
    links: []
  bundledCode: "#line 1 \"linalg/solve_linear.hpp\"\n/*\r\n0 \u884C\u76EE\u306B\u89E3\
    \u306E\u3072\u3068\u3064\u3002\r\n1\uFF5E\u884C\u76EE\u306B\u89E3\u7A7A\u9593\u306E\
    \u57FA\u5E95\u304C\u884C\u30D9\u30AF\u30C8\u30EB\u3068\u3057\u3066\u5165\u308B\
    \u3002\r\n\u89E3\u306A\u3057 = empty\r\n*/\r\ntemplate <typename T>\r\nvc<vc<T>>\
    \ solve_linear(vc<vc<T>> a, vc<T> b, int n = -1, int m = -1) {\r\n  if (n == -1)\
    \ {\r\n    n = len(a);\r\n    assert(n > 0);\r\n    m = len(a[0]);\r\n  }\r\n\
    \  assert(n == len(a) && n == len(b));\r\n  int rk = 0;\r\n  FOR(j, m) {\r\n \
    \   if (rk == n) break;\r\n    FOR(i, rk, n) if (a[i][j] != 0) {\r\n      swap(a[rk],\
    \ a[i]);\r\n      swap(b[rk], b[i]);\r\n      break;\r\n    }\r\n    if (a[rk][j]\
    \ == 0) continue;\r\n    T c = T(1) / a[rk][j];\r\n    for (auto&& x: a[rk]) x\
    \ *= c;\r\n    b[rk] *= c;\r\n    FOR(i, n) if (i != rk) {\r\n      T c = a[i][j];\r\
    \n      if (c == T(0)) continue;\r\n      b[i] -= b[rk] * c;\r\n      FOR(k, j,\
    \ m) { a[i][k] -= a[rk][k] * c; }\r\n    }\r\n    ++rk;\r\n  }\r\n  FOR(i, rk,\
    \ n) if (b[i] != 0) return {};\r\n  vc<vc<T>> res(1, vc<T>(m));\r\n  vc<int> pivot(m,\
    \ -1);\r\n  int p = 0;\r\n  FOR(i, rk) {\r\n    while (a[i][p] == 0) ++p;\r\n\
    \    res[0][p] = b[i];\r\n    pivot[p] = i;\r\n  }\r\n  FOR(j, m) if (pivot[j]\
    \ == -1) {\r\n    vc<T> x(m);\r\n    x[j] = -1;\r\n    FOR(k, j) if (pivot[k]\
    \ != -1) x[k] = a[pivot[k]][j];\r\n    res.eb(x);\r\n  }\r\n  return res;\r\n\
    }\r\n"
  code: "/*\r\n0 \u884C\u76EE\u306B\u89E3\u306E\u3072\u3068\u3064\u3002\r\n1\uFF5E\
    \u884C\u76EE\u306B\u89E3\u7A7A\u9593\u306E\u57FA\u5E95\u304C\u884C\u30D9\u30AF\
    \u30C8\u30EB\u3068\u3057\u3066\u5165\u308B\u3002\r\n\u89E3\u306A\u3057 = empty\r\
    \n*/\r\ntemplate <typename T>\r\nvc<vc<T>> solve_linear(vc<vc<T>> a, vc<T> b,\
    \ int n = -1, int m = -1) {\r\n  if (n == -1) {\r\n    n = len(a);\r\n    assert(n\
    \ > 0);\r\n    m = len(a[0]);\r\n  }\r\n  assert(n == len(a) && n == len(b));\r\
    \n  int rk = 0;\r\n  FOR(j, m) {\r\n    if (rk == n) break;\r\n    FOR(i, rk,\
    \ n) if (a[i][j] != 0) {\r\n      swap(a[rk], a[i]);\r\n      swap(b[rk], b[i]);\r\
    \n      break;\r\n    }\r\n    if (a[rk][j] == 0) continue;\r\n    T c = T(1)\
    \ / a[rk][j];\r\n    for (auto&& x: a[rk]) x *= c;\r\n    b[rk] *= c;\r\n    FOR(i,\
    \ n) if (i != rk) {\r\n      T c = a[i][j];\r\n      if (c == T(0)) continue;\r\
    \n      b[i] -= b[rk] * c;\r\n      FOR(k, j, m) { a[i][k] -= a[rk][k] * c; }\r\
    \n    }\r\n    ++rk;\r\n  }\r\n  FOR(i, rk, n) if (b[i] != 0) return {};\r\n \
    \ vc<vc<T>> res(1, vc<T>(m));\r\n  vc<int> pivot(m, -1);\r\n  int p = 0;\r\n \
    \ FOR(i, rk) {\r\n    while (a[i][p] == 0) ++p;\r\n    res[0][p] = b[i];\r\n \
    \   pivot[p] = i;\r\n  }\r\n  FOR(j, m) if (pivot[j] == -1) {\r\n    vc<T> x(m);\r\
    \n    x[j] = -1;\r\n    FOR(k, j) if (pivot[k] != -1) x[k] = a[pivot[k]][j];\r\
    \n    res.eb(x);\r\n  }\r\n  return res;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/solve_linear.hpp
  requiredBy:
  - poly/from_log_differentiation.hpp
  - poly/sparse_exp_of_div.hpp
  - seq/p_recursive.hpp
  timestamp: '2023-11-16 18:26:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/502_2.test.cpp
  - test/3_yukicoder/1080_2.test.cpp
  - test/3_yukicoder/2166.test.cpp
  - test/2_library_checker/linear_algebra/solve_linear.test.cpp
documentation_of: linalg/solve_linear.hpp
layout: document
redirect_from:
- /library/linalg/solve_linear.hpp
- /library/linalg/solve_linear.hpp.html
title: linalg/solve_linear.hpp
---
