---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: linalg/mat_pow.hpp
    title: linalg/mat_pow.hpp
  - icon: ':x:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':x:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1810_matpow.test.cpp
    title: test/yukicoder/1810_matpow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/426.test.cpp
    title: test/yukicoder/426.test.cpp
  - icon: ':x:'
    path: test/yukicoder/502_p_rec.test.cpp
    title: test/yukicoder/502_p_rec.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linalg/mat_mul.hpp\"\n\r\ntemplate <class T, is_modint_t<T>*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  // mod \u3092\u3068\u308B\u56DE\u6570\u3092\u6E1B\u3089\u3057\u3066\u307F\u308B\
    \r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  const\
    \ u64 MOD2 = 8ull * T::get_mod() * T::get_mod();\r\n  FOR(n, N) {\r\n    vc<u64>\
    \ tmp(K);\r\n    FOR(m, M) FOR(k, K) {\r\n      tmp[k] += u64(A[n][m].val) * B[m][k].val;\r\
    \n      if (tmp[k] >= MOD2) tmp[k] -= MOD2;\r\n    }\r\n    FOR(k, K) C[n][k]\
    \ = tmp[k];\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate <class T, is_not_modint_t<T>*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  FOR(n,\
    \ N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n"
  code: "#pragma once\r\n\r\ntemplate <class T, is_modint_t<T>* = nullptr>\r\nvc<vc<T>>\
    \ mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n  // mod \u3092\u3068\u308B\
    \u56DE\u6570\u3092\u6E1B\u3089\u3057\u3066\u307F\u308B\r\n  auto N = len(A), M\
    \ = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  const u64 MOD2 = 8ull * T::get_mod()\
    \ * T::get_mod();\r\n  FOR(n, N) {\r\n    vc<u64> tmp(K);\r\n    FOR(m, M) FOR(k,\
    \ K) {\r\n      tmp[k] += u64(A[n][m].val) * B[m][k].val;\r\n      if (tmp[k]\
    \ >= MOD2) tmp[k] -= MOD2;\r\n    }\r\n    FOR(k, K) C[n][k] = tmp[k];\r\n  }\r\
    \n  return C;\r\n}\r\n\r\ntemplate <class T, is_not_modint_t<T>* = nullptr>\r\n\
    vc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n  auto N = len(A),\
    \ M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  FOR(n, N) FOR(m, M) FOR(k,\
    \ K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/mat_mul.hpp
  requiredBy:
  - linalg/mat_pow.hpp
  - poly/prefix_product_of_poly.hpp
  - seq/kth_term_of_p_recursive.hpp
  timestamp: '2022-04-23 01:11:07+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1810_matpow.test.cpp
  - test/yukicoder/502_p_rec.test.cpp
  - test/yukicoder/426.test.cpp
  - test/library_checker/matrix/matrix_product.test.cpp
documentation_of: linalg/mat_mul.hpp
layout: document
redirect_from:
- /library/linalg/mat_mul.hpp
- /library/linalg/mat_mul.hpp.html
title: linalg/mat_mul.hpp
---
