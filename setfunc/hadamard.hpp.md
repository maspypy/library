---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: setfunc/xor_convolution.hpp
    title: setfunc/xor_convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1142.test.cpp
    title: test/3_yukicoder/1142.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1753.test.cpp
    title: test/3_yukicoder/1753.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"setfunc/hadamard.hpp\"\n\r\n// B[j] = sum_i (-1)^{popcnt(i&j)A[i]}\r\
    \n// 2^n \u3067\u5272\u308B\u3053\u3068\u306F\u3057\u3066\u3044\u306A\u3044\r\n\
    template <typename T>\r\nvoid hadamard(vc<T>& A) {\r\n  int log = topbit(len(A));\r\
    \n  assert(1 << log == len(A));\r\n  FOR(n, log) FOR(s, 1 << log) {\r\n    int\
    \ t = s ^ (1 << n);\r\n    if (s < t) tie(A[s], A[t]) = mp(A[s] + A[t], A[s] -\
    \ A[t]);\r\n  }\r\n}\n"
  code: "#pragma once\r\n\r\n// B[j] = sum_i (-1)^{popcnt(i&j)A[i]}\r\n// 2^n \u3067\
    \u5272\u308B\u3053\u3068\u306F\u3057\u3066\u3044\u306A\u3044\r\ntemplate <typename\
    \ T>\r\nvoid hadamard(vc<T>& A) {\r\n  int log = topbit(len(A));\r\n  assert(1\
    \ << log == len(A));\r\n  FOR(n, log) FOR(s, 1 << log) {\r\n    int t = s ^ (1\
    \ << n);\r\n    if (s < t) tie(A[s], A[t]) = mp(A[s] + A[t], A[s] - A[t]);\r\n\
    \  }\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: setfunc/hadamard.hpp
  requiredBy:
  - setfunc/xor_convolution.hpp
  timestamp: '2023-09-18 22:09:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/2_library_checker/convolution/bitwise_xor_convolution.test.cpp
  - test/3_yukicoder/1753.test.cpp
  - test/3_yukicoder/1142.test.cpp
documentation_of: setfunc/hadamard.hpp
layout: document
redirect_from:
- /library/setfunc/hadamard.hpp
- /library/setfunc/hadamard.hpp.html
title: setfunc/hadamard.hpp
---
