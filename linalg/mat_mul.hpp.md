---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: linalg/det_A_plus_xB.hpp
    title: linalg/det_A_plus_xB.hpp
  - icon: ':x:'
    path: linalg/mat_pow.hpp
    title: linalg/mat_pow.hpp
  - icon: ':question:'
    path: poly/from_log_differentiation.hpp
    title: poly/from_log_differentiation.hpp
  - icon: ':question:'
    path: poly/prefix_product_of_poly.hpp
    title: poly/prefix_product_of_poly.hpp
  - icon: ':heavy_check_mark:'
    path: poly/sparse_exp_of_div.hpp
    title: poly/sparse_exp_of_div.hpp
  - icon: ':question:'
    path: seq/kth_term_of_p_recursive.hpp
    title: seq/kth_term_of_p_recursive.hpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/atcoder/abc276_g.test.cpp
    title: test/atcoder/abc276_g.test.cpp
  - icon: ':x:'
    path: test/atcoder/abc276_g_2.test.cpp
    title: test/atcoder/abc276_g_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/matrix/matrix_product.test.cpp
    title: test/library_checker/matrix/matrix_product.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/factorial_998.test.cpp
    title: test/mytest/factorial_998.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1080_2.test.cpp
    title: test/yukicoder/1080_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1303.test.cpp
    title: test/yukicoder/1303.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1750.test.cpp
    title: test/yukicoder/1750.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1810.test.cpp
    title: test/yukicoder/1810.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1907.test.cpp
    title: test/yukicoder/1907.test.cpp
  - icon: ':x:'
    path: test/yukicoder/426.test.cpp
    title: test/yukicoder/426.test.cpp
  - icon: ':x:'
    path: test/yukicoder/502_2.test.cpp
    title: test/yukicoder/502_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linalg/mat_mul.hpp\"\n\r\nstruct has_mod_impl {\r\n  template\
    \ <class T>\r\n  static auto check(T&& x) -> decltype(x.get_mod(), std::true_type{});\r\
    \n\r\n  template <class T>\r\n  static auto check(...) -> std::false_type;\r\n\
    };\r\n\r\ntemplate <class T>\r\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\r\n\r\ntemplate <class T, typename enable_if<has_mod<T>::value>::type* =\
    \ nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  const int mod = T::get_mod();\r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\
    \n  vv(int, b, K, M);\r\n  FOR(i, M) FOR(j, K) b[j][i] = B[i][j].val;\r\n  vv(T,\
    \ C, N, K);\r\n  FOR(i, N) {\r\n    FOR(j, K) {\r\n      i128 sm = 0;\r\n    \
    \  FOR(m, M) { sm += ll(A[i][m].val) * b[j][m]; }\r\n      C[i][j] = sm % mod;\r\
    \n    }\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  FOR(n,\
    \ N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n"
  code: "#pragma once\r\n\r\nstruct has_mod_impl {\r\n  template <class T>\r\n  static\
    \ auto check(T&& x) -> decltype(x.get_mod(), std::true_type{});\r\n\r\n  template\
    \ <class T>\r\n  static auto check(...) -> std::false_type;\r\n};\r\n\r\ntemplate\
    \ <class T>\r\nclass has_mod : public decltype(has_mod_impl::check<T>(std::declval<T>()))\
    \ {};\r\n\r\ntemplate <class T, typename enable_if<has_mod<T>::value>::type* =\
    \ nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  const int mod = T::get_mod();\r\n  auto N = len(A), M = len(B), K = len(B[0]);\r\
    \n  vv(int, b, K, M);\r\n  FOR(i, M) FOR(j, K) b[j][i] = B[i][j].val;\r\n  vv(T,\
    \ C, N, K);\r\n  FOR(i, N) {\r\n    FOR(j, K) {\r\n      i128 sm = 0;\r\n    \
    \  FOR(m, M) { sm += ll(A[i][m].val) * b[j][m]; }\r\n      C[i][j] = sm % mod;\r\
    \n    }\r\n  }\r\n  return C;\r\n}\r\n\r\ntemplate <class T, typename enable_if<!has_mod<T>::value>::type*\
    \ = nullptr>\r\nvc<vc<T>> mat_mul(const vc<vc<T>>& A, const vc<vc<T>>& B) {\r\n\
    \  auto N = len(A), M = len(B), K = len(B[0]);\r\n  vv(T, C, N, K);\r\n  FOR(n,\
    \ N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/mat_mul.hpp
  requiredBy:
  - poly/prefix_product_of_poly.hpp
  - poly/from_log_differentiation.hpp
  - poly/sparse_exp_of_div.hpp
  - seq/kth_term_of_p_recursive.hpp
  - linalg/det_A_plus_xB.hpp
  - linalg/mat_pow.hpp
  timestamp: '2022-12-02 06:10:25+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1750.test.cpp
  - test/yukicoder/1303.test.cpp
  - test/yukicoder/1907.test.cpp
  - test/yukicoder/1810.test.cpp
  - test/yukicoder/1080_2.test.cpp
  - test/yukicoder/426.test.cpp
  - test/yukicoder/502_2.test.cpp
  - test/mytest/factorial_998.test.cpp
  - test/library_checker/matrix/matrix_product.test.cpp
  - test/atcoder/abc276_g.test.cpp
  - test/atcoder/abc276_g_2.test.cpp
documentation_of: linalg/mat_mul.hpp
layout: document
redirect_from:
- /library/linalg/mat_mul.hpp
- /library/linalg/mat_mul.hpp.html
title: linalg/mat_mul.hpp
---
