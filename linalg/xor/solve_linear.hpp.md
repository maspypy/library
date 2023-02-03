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
  bundledCode: "#line 1 \"linalg/xor/solve_linear.hpp\"\n// solve Ax = b \u3092\u89E3\
    \u304F\u3002[0] \u306B\u7279\u6B8A\u89E3\u3001[1]\uFF5E \u306B Ker A \u306E\u57FA\
    \u5E95\u304C\u5165\u308B\u3002\u89E3\u306A\u3057\u306F\n// empty\u3002 A \u306E\
    \u884C\u30D9\u30AF\u30C8\u30EB\u3092 UINT \u3067\u6301\u305F\u305B\u308B\u3002\
    \ntemplate <typename UINT>\nvc<UINT> solve_linear(int n, int m, vc<UINT>& A, UINT\
    \ b) {\n  assert(max(n, m) <= numeric_limits<UINT>::digits);\n  assert(len(A)\
    \ == n);\n  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    FOR(i, rk,\
    \ n) if (A[i] >> j & 1) {\n      if (i == rk) break;\n      swap(A[rk], A[i]);\n\
    \      if ((b >> rk & 1) != (b >> i & 1)) b ^= (UINT(1) << rk) | (UINT(1) << i);\n\
    \      break;\n    }\n    if (!(A[rk] >> j & 1)) continue;\n    FOR(i, n) if (i\
    \ != rk) {\n      if (A[i] >> j & 1) {\n        A[i] ^= A[rk];\n        b ^= (b\
    \ >> rk & 1) << i;\n      }\n    }\n    ++rk;\n  }\n  if (b >> rk) { return {};\
    \ }\n  vc<UINT> res(1);\n  vc<int> pivot(m, -1);\n  int p = 0;\n  FOR(i, rk) {\n\
    \    while (!(A[i] >> p & 1)) ++p;\n    res[0] |= (b >> i & 1) << p;\n    pivot[p]\
    \ = i;\n  }\n  FOR(j, m) if (pivot[j] == -1) {\n    UINT x = 0;\n    x |= UINT(1)\
    \ << j;\n    FOR(k, j) if (pivot[k] != -1 && (A[pivot[k]] >> j & 1)) {\n     \
    \ x |= UINT(1) << k;\n    }\n    res.eb(x);\n  }\n  return res;\n}\n"
  code: "// solve Ax = b \u3092\u89E3\u304F\u3002[0] \u306B\u7279\u6B8A\u89E3\u3001\
    [1]\uFF5E \u306B Ker A \u306E\u57FA\u5E95\u304C\u5165\u308B\u3002\u89E3\u306A\u3057\
    \u306F\n// empty\u3002 A \u306E\u884C\u30D9\u30AF\u30C8\u30EB\u3092 UINT \u3067\
    \u6301\u305F\u305B\u308B\u3002\ntemplate <typename UINT>\nvc<UINT> solve_linear(int\
    \ n, int m, vc<UINT>& A, UINT b) {\n  assert(max(n, m) <= numeric_limits<UINT>::digits);\n\
    \  assert(len(A) == n);\n  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n\
    \    FOR(i, rk, n) if (A[i] >> j & 1) {\n      if (i == rk) break;\n      swap(A[rk],\
    \ A[i]);\n      if ((b >> rk & 1) != (b >> i & 1)) b ^= (UINT(1) << rk) | (UINT(1)\
    \ << i);\n      break;\n    }\n    if (!(A[rk] >> j & 1)) continue;\n    FOR(i,\
    \ n) if (i != rk) {\n      if (A[i] >> j & 1) {\n        A[i] ^= A[rk];\n    \
    \    b ^= (b >> rk & 1) << i;\n      }\n    }\n    ++rk;\n  }\n  if (b >> rk)\
    \ { return {}; }\n  vc<UINT> res(1);\n  vc<int> pivot(m, -1);\n  int p = 0;\n\
    \  FOR(i, rk) {\n    while (!(A[i] >> p & 1)) ++p;\n    res[0] |= (b >> i & 1)\
    \ << p;\n    pivot[p] = i;\n  }\n  FOR(j, m) if (pivot[j] == -1) {\n    UINT x\
    \ = 0;\n    x |= UINT(1) << j;\n    FOR(k, j) if (pivot[k] != -1 && (A[pivot[k]]\
    \ >> j & 1)) {\n      x |= UINT(1) << k;\n    }\n    res.eb(x);\n  }\n  return\
    \ res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/solve_linear.hpp
  requiredBy: []
  timestamp: '2023-02-03 02:48:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xor/solve_linear.hpp
layout: document
redirect_from:
- /library/linalg/xor/solve_linear.hpp
- /library/linalg/xor/solve_linear.hpp.html
title: linalg/xor/solve_linear.hpp
---
