---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: linalg/mat_mul.hpp
    title: linalg/mat_mul.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1750.test.cpp
    title: test/yukicoder/1750.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1810.test.cpp
    title: test/yukicoder/1810.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
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
  timestamp: '2022-12-02 06:10:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1810.test.cpp
  - test/yukicoder/1750.test.cpp
documentation_of: linalg/mat_pow.hpp
layout: document
redirect_from:
- /library/linalg/mat_pow.hpp
- /library/linalg/mat_pow.hpp.html
title: linalg/mat_pow.hpp
---
