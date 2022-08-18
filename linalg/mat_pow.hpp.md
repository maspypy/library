---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/mat_mul.hpp
    title: linalg/mat_mul.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1750_matpow.test.cpp
    title: test/yukicoder/1750_matpow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1810_matpow.test.cpp
    title: test/yukicoder/1810_matpow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ N) FOR(m, M) FOR(k, K) C[n][k] += A[n][m] * B[m][k];\r\n  return C;\r\n}\r\n\
    #line 2 \"linalg/mat_pow.hpp\"\ntemplate<typename T>\r\nvc<vc<T>> mat_pow(vc<vc<T>>\
    \ A, ll n){\r\n  int N = len(A);\r\n  vv(T, ret, N, N);\r\n  FOR(i, N) ret[i][i]\
    \ = T(1);\r\n  while(n){\r\n    if(n & 1) ret = mat_mul(ret, A);\r\n    n /= 2;\r\
    \n    if(n) A = mat_mul(A, A);\r\n  }\r\n  return ret;\r\n}\n"
  code: "#include \"linalg/mat_mul.hpp\"\r\ntemplate<typename T>\r\nvc<vc<T>> mat_pow(vc<vc<T>>\
    \ A, ll n){\r\n  int N = len(A);\r\n  vv(T, ret, N, N);\r\n  FOR(i, N) ret[i][i]\
    \ = T(1);\r\n  while(n){\r\n    if(n & 1) ret = mat_mul(ret, A);\r\n    n /= 2;\r\
    \n    if(n) A = mat_mul(A, A);\r\n  }\r\n  return ret;\r\n}"
  dependsOn:
  - linalg/mat_mul.hpp
  isVerificationFile: false
  path: linalg/mat_pow.hpp
  requiredBy: []
  timestamp: '2022-04-23 01:11:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1750_matpow.test.cpp
  - test/yukicoder/1810_matpow.test.cpp
documentation_of: linalg/mat_pow.hpp
layout: document
redirect_from:
- /library/linalg/mat_pow.hpp
- /library/linalg/mat_pow.hpp.html
title: linalg/mat_pow.hpp
---
