---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1321_surj.test.cpp
    title: test/yukicoder/1321_surj.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"seq/surjection.hpp\"\n// n \u5143\u96C6\u5408\u304B\u3089\
    \u306E\u5168\u5C04\u306E\u6570\u3048\u4E0A\u3052\r\ntemplate <typename mint>\r\
    \nvc<mint> surjection_n(int n, int k_max) {\r\n  auto f = stirling_number_2_n<mint>(n,\
    \ k_max);\r\n  FOR(i, k_max + 1) f[i] *= fact<mint>(i);\r\n  return f;\r\n}\r\n\
    \r\n// k \u5143\u96C6\u5408\u3078\u306E\u306E\u5168\u5C04\u306E\u6570\u3048\u4E0A\
    \u3052\r\ntemplate <typename mint>\r\nvc<mint> surjection_k(int k, int n_max)\
    \ {\r\n  auto f = stirling_number_2_k<mint>(k, n_max);\r\n  FOR(i, n_max + 1)\
    \ f[i] *= fact<mint>(k);\r\n  return f;\r\n}\r\n"
  code: "// n \u5143\u96C6\u5408\u304B\u3089\u306E\u5168\u5C04\u306E\u6570\u3048\u4E0A\
    \u3052\r\ntemplate <typename mint>\r\nvc<mint> surjection_n(int n, int k_max)\
    \ {\r\n  auto f = stirling_number_2_n<mint>(n, k_max);\r\n  FOR(i, k_max + 1)\
    \ f[i] *= fact<mint>(i);\r\n  return f;\r\n}\r\n\r\n// k \u5143\u96C6\u5408\u3078\
    \u306E\u306E\u5168\u5C04\u306E\u6570\u3048\u4E0A\u3052\r\ntemplate <typename mint>\r\
    \nvc<mint> surjection_k(int k, int n_max) {\r\n  auto f = stirling_number_2_k<mint>(k,\
    \ n_max);\r\n  FOR(i, n_max + 1) f[i] *= fact<mint>(k);\r\n  return f;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: seq/surjection.hpp
  requiredBy: []
  timestamp: '2022-05-21 17:44:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1321_surj.test.cpp
documentation_of: seq/surjection.hpp
layout: document
redirect_from:
- /library/seq/surjection.hpp
- /library/seq/surjection.hpp.html
title: seq/surjection.hpp
---
