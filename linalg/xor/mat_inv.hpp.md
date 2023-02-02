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
    \ B[i] = u64(1) << i;\n  FOR(i, N) {\n    FOR(k, i, N) if (A[k] >> i & 1) {\n\
    \      if (k != i) { swap(A[i], A[k]), swap(B[i], B[k]); }\n      break;\n   \
    \ }\n    if (!(A[i] >> i & 1)) return {};\n    FOR(k, N) if (i != k) {\n     \
    \ if (!(A[k] >> i & 1)) continue;\n      A[k] ^= A[i];\n      B[k] ^= B[i];\n\
    \    }\n  }\n  return B;\n}\n"
  code: "// \u884C\u30D9\u30AF\u30C8\u30EB\u3092\u6574\u6570\u578B\u3067\u8868\u73FE\
    \ntemplate <typename UINT>\nvc<UINT> mat_inv(vc<UINT> A) {\n  const int N = len(A);\n\
    \  vc<UINT> B(N);\n  FOR(i, N) B[i] = u64(1) << i;\n  FOR(i, N) {\n    FOR(k,\
    \ i, N) if (A[k] >> i & 1) {\n      if (k != i) { swap(A[i], A[k]), swap(B[i],\
    \ B[k]); }\n      break;\n    }\n    if (!(A[i] >> i & 1)) return {};\n    FOR(k,\
    \ N) if (i != k) {\n      if (!(A[k] >> i & 1)) continue;\n      A[k] ^= A[i];\n\
    \      B[k] ^= B[i];\n    }\n  }\n  return B;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/mat_inv.hpp
  requiredBy: []
  timestamp: '2023-02-03 02:31:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xor/mat_inv.hpp
layout: document
redirect_from:
- /library/linalg/xor/mat_inv.hpp
- /library/linalg/xor/mat_inv.hpp.html
title: linalg/xor/mat_inv.hpp
---
