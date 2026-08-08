---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/xor/mat_inv.hpp\"\n// \u884C\u30D9\u30AF\u30C8\u30EB\
    \u3092\u6574\u6570\u578B\u3067\u8868\u73FE\ntemplate <typename UINT>\nvc<UINT>\
    \ mat_inv(vc<UINT> A) {\n  const int N = len(A);\n  vc<UINT> B(N);\n  FOR(i, N)\
    \ B[i] = UINT(1) << i;\n\n  FOR(k, N) {\n    int p = -1;\n    FOR(i, k, N) {\n\
    \      if (A[i] >> k & 1) {\n        p = i;\n        break;\n      }\n    }\n\
    \    assert(p != -1);\n    swap(A[k], A[p]);\n    swap(B[k], B[p]);\n\n    FOR(i,\
    \ N) {\n      if (i != k && (A[i] >> k & 1)) {\n        A[i] ^= A[k];\n      \
    \  B[i] ^= B[k];\n      }\n    }\n  }\n  return B;\n}\n"
  code: "// \u884C\u30D9\u30AF\u30C8\u30EB\u3092\u6574\u6570\u578B\u3067\u8868\u73FE\
    \ntemplate <typename UINT>\nvc<UINT> mat_inv(vc<UINT> A) {\n  const int N = len(A);\n\
    \  vc<UINT> B(N);\n  FOR(i, N) B[i] = UINT(1) << i;\n\n  FOR(k, N) {\n    int\
    \ p = -1;\n    FOR(i, k, N) {\n      if (A[i] >> k & 1) {\n        p = i;\n  \
    \      break;\n      }\n    }\n    assert(p != -1);\n    swap(A[k], A[p]);\n \
    \   swap(B[k], B[p]);\n\n    FOR(i, N) {\n      if (i != k && (A[i] >> k & 1))\
    \ {\n        A[i] ^= A[k];\n        B[i] ^= B[k];\n      }\n    }\n  }\n  return\
    \ B;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/mat_inv.hpp
  requiredBy: []
  timestamp: '2026-08-09 03:02:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xor/mat_inv.hpp
layout: document
redirect_from:
- /library/linalg/xor/mat_inv.hpp
- /library/linalg/xor/mat_inv.hpp.html
title: linalg/xor/mat_inv.hpp
---
