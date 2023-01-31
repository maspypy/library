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
  bundledCode: "#line 1 \"linalg/bitset/mat_inv_bitset.hpp\"\ntemplate <int MAX_N,\
    \ typename T = bool>\nvvc<T> mat_inv_bitset(vvc<T> a) {\n  const int N = len(a);\n\
    \  using BS = bitset<MAX_N>;\n  vc<BS> A(N), B(N);\n  FOR(i, N) FOR(j, N) if (a[i][j])\
    \ A[i][j] = 1;\n  FOR(n, N) B[n][n] = 1;\n  FOR(i, N) {\n    FOR(k, i, N) if (A[k][i])\
    \ {\n      if (k != i) { swap(A[i], A[k]), swap(B[i], B[k]); }\n      break;\n\
    \    }\n    if (!A[i][i]) return {};\n    FOR(k, N) if (i != k) {\n      if (!A[k][i])\
    \ continue;\n      A[k] ^= A[i];\n      B[k] ^= B[i];\n    }\n  }\n  vv(T, b,\
    \ N, N);\n  FOR(i, N) FOR(j, N) if (B[i][j]) b[i][j] = 1;\n  return b;\n}\n"
  code: "template <int MAX_N, typename T = bool>\nvvc<T> mat_inv_bitset(vvc<T> a)\
    \ {\n  const int N = len(a);\n  using BS = bitset<MAX_N>;\n  vc<BS> A(N), B(N);\n\
    \  FOR(i, N) FOR(j, N) if (a[i][j]) A[i][j] = 1;\n  FOR(n, N) B[n][n] = 1;\n \
    \ FOR(i, N) {\n    FOR(k, i, N) if (A[k][i]) {\n      if (k != i) { swap(A[i],\
    \ A[k]), swap(B[i], B[k]); }\n      break;\n    }\n    if (!A[i][i]) return {};\n\
    \    FOR(k, N) if (i != k) {\n      if (!A[k][i]) continue;\n      A[k] ^= A[i];\n\
    \      B[k] ^= B[i];\n    }\n  }\n  vv(T, b, N, N);\n  FOR(i, N) FOR(j, N) if\
    \ (B[i][j]) b[i][j] = 1;\n  return b;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/bitset/mat_inv_bitset.hpp
  requiredBy: []
  timestamp: '2023-01-31 19:52:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/bitset/mat_inv_bitset.hpp
layout: document
redirect_from:
- /library/linalg/bitset/mat_inv_bitset.hpp
- /library/linalg/bitset/mat_inv_bitset.hpp.html
title: linalg/bitset/mat_inv_bitset.hpp
---
