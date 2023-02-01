---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/QOJ5445.test.cpp
    title: test/mytest/QOJ5445.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/xor/mat_inv_xor.hpp\"\n// \u884C\u30D9\u30AF\u30C8\
    \u30EB\u3092\u6574\u6570\u578B\u3067\u8868\u73FE\ntemplate <typename UINT>\nvc<UINT>\
    \ mat_inv_xor(vc<UINT> &A, bool keep_A = 1) {\n  vc<UINT> tmp;\n  if (keep_A)\
    \ tmp = A;\n  const int N = len(A);\n  vc<UINT> B(N);\n  FOR(i, N) B[i] = u64(1)\
    \ << i;\n  FOR(i, N) {\n    FOR(k, i, N) if (A[k] >> i & 1) {\n      if (k !=\
    \ i) { swap(A[i], A[k]), swap(B[i], B[k]); }\n      break;\n    }\n    if (!(A[i]\
    \ >> i & 1)) return {};\n    FOR(k, N) if (i != k) {\n      if (!(A[k] >> i &\
    \ 1)) continue;\n      A[k] ^= A[i];\n      B[k] ^= B[i];\n    }\n  }\n  if (keep_A)\
    \ swap(A, tmp);\n  return B;\n}\n"
  code: "// \u884C\u30D9\u30AF\u30C8\u30EB\u3092\u6574\u6570\u578B\u3067\u8868\u73FE\
    \ntemplate <typename UINT>\nvc<UINT> mat_inv_xor(vc<UINT> &A, bool keep_A = 1)\
    \ {\n  vc<UINT> tmp;\n  if (keep_A) tmp = A;\n  const int N = len(A);\n  vc<UINT>\
    \ B(N);\n  FOR(i, N) B[i] = u64(1) << i;\n  FOR(i, N) {\n    FOR(k, i, N) if (A[k]\
    \ >> i & 1) {\n      if (k != i) { swap(A[i], A[k]), swap(B[i], B[k]); }\n   \
    \   break;\n    }\n    if (!(A[i] >> i & 1)) return {};\n    FOR(k, N) if (i !=\
    \ k) {\n      if (!(A[k] >> i & 1)) continue;\n      A[k] ^= A[i];\n      B[k]\
    \ ^= B[i];\n    }\n  }\n  if (keep_A) swap(A, tmp);\n  return B;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/mat_inv_xor.hpp
  requiredBy: []
  timestamp: '2023-02-01 04:25:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/mytest/QOJ5445.test.cpp
documentation_of: linalg/xor/mat_inv_xor.hpp
layout: document
redirect_from:
- /library/linalg/xor/mat_inv_xor.hpp
- /library/linalg/xor/mat_inv_xor.hpp.html
title: linalg/xor/mat_inv_xor.hpp
---
