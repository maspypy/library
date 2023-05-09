---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/QOJ5445.test.cpp
    title: test/mytest/QOJ5445.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/xor/mat_inv.hpp\"\n// \u884C\u30D9\u30AF\u30C8\u30EB\
    \u3092\u6574\u6570\u578B\u3067\u8868\u73FE\ntemplate <typename UINT>\nvc<UINT>\
    \ mat_inv(vc<UINT> A) {\n  const int N = len(A);\n  vc<UINT> B(N);\n  FOR(i, N)\
    \ B[i] = u64(1) << i;\n  FOR(i, N) FOR(j, N) if (j != i) {\n    if (chmin(A[i],\
    \ A[i] ^ A[j])) B[i] ^= B[j];\n  }\n  vc<UINT> res(N);\n  FOR(i, N) res[topbit(A[i])]\
    \ = B[i];\n  return res;\n}\n"
  code: "// \u884C\u30D9\u30AF\u30C8\u30EB\u3092\u6574\u6570\u578B\u3067\u8868\u73FE\
    \ntemplate <typename UINT>\nvc<UINT> mat_inv(vc<UINT> A) {\n  const int N = len(A);\n\
    \  vc<UINT> B(N);\n  FOR(i, N) B[i] = u64(1) << i;\n  FOR(i, N) FOR(j, N) if (j\
    \ != i) {\n    if (chmin(A[i], A[i] ^ A[j])) B[i] ^= B[j];\n  }\n  vc<UINT> res(N);\n\
    \  FOR(i, N) res[topbit(A[i])] = B[i];\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/mat_inv.hpp
  requiredBy: []
  timestamp: '2023-02-03 10:57:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/QOJ5445.test.cpp
documentation_of: linalg/xor/mat_inv.hpp
layout: document
redirect_from:
- /library/linalg/xor/mat_inv.hpp
- /library/linalg/xor/mat_inv.hpp.html
title: linalg/xor/mat_inv.hpp
---
