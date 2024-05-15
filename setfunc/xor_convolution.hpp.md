---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: setfunc/hadamard.hpp
    title: setfunc/hadamard.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
    title: test/library_checker/convolution/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1142.test.cpp
    title: test/yukicoder/1142.test.cpp
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
    \ A[t]);\r\n  }\r\n}\n#line 2 \"setfunc/xor_convolution.hpp\"\n\r\ntemplate <typename\
    \ T>\r\nvc<T> xor_convolution(vc<T> A, vc<T> B) {\r\n  hadamard(A);\r\n  hadamard(B);\r\
    \n  FOR(i, len(A)) A[i] *= B[i];\r\n  hadamard(A);\r\n\r\n  T c = T(1) / T(len(A));\r\
    \n  if (c != T(0)) {\r\n    FOR(i, len(A)) A[i] *= c;\r\n  } else {\r\n    FOR(i,\
    \ len(A)) A[i] /= len(A);\r\n  }\r\n  return A;\r\n}\r\n"
  code: "#include \"setfunc/hadamard.hpp\"\r\n\r\ntemplate <typename T>\r\nvc<T> xor_convolution(vc<T>\
    \ A, vc<T> B) {\r\n  hadamard(A);\r\n  hadamard(B);\r\n  FOR(i, len(A)) A[i] *=\
    \ B[i];\r\n  hadamard(A);\r\n\r\n  T c = T(1) / T(len(A));\r\n  if (c != T(0))\
    \ {\r\n    FOR(i, len(A)) A[i] *= c;\r\n  } else {\r\n    FOR(i, len(A)) A[i]\
    \ /= len(A);\r\n  }\r\n  return A;\r\n}\r\n"
  dependsOn:
  - setfunc/hadamard.hpp
  isVerificationFile: false
  path: setfunc/xor_convolution.hpp
  requiredBy: []
  timestamp: '2023-10-24 20:44:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1142.test.cpp
  - test/library_checker/convolution/bitwise_xor_convolution.test.cpp
documentation_of: setfunc/xor_convolution.hpp
layout: document
redirect_from:
- /library/setfunc/xor_convolution.hpp
- /library/setfunc/xor_convolution.hpp.html
title: setfunc/xor_convolution.hpp
---
