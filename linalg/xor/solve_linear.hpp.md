---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: linalg/xor/transpose.hpp
    title: linalg/xor/transpose.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"linalg/xor/transpose.hpp\"\n\n// n x m \u884C\u5217\u306E\
    \ transpose\u3002O((n+m)log(n+m)) \u6642\u9593\u3002\n// https://github.com/dsnet/matrix-transpose\n\
    template <typename UINT>\nvc<UINT> transpose(int n, int m, vc<UINT>& A, bool keep_A\
    \ = 1) {\n  assert(max(n, m) <= numeric_limits<UINT>::digits);\n  assert(len(A)\
    \ == n);\n  vc<UINT> tmp;\n  if (keep_A) tmp = A;\n  int LOG = 0;\n  while ((1\
    \ << LOG) < max(n, m)) ++LOG;\n  A.resize(1 << LOG);\n  int width = 1 << LOG;\n\
    \  UINT mask = 1;\n  FOR(i, LOG) mask = mask | (mask << (1 << i));\n  FOR(t, LOG)\
    \ {\n    width >>= 1;\n    mask = mask ^ (mask >> width);\n    FOR(i, 1 << t)\
    \ {\n      FOR(j, width) {\n        UINT* x = &A[width * (2 * i + 0) + j];\n \
    \       UINT* y = &A[width * (2 * i + 1) + j];\n        *x = ((*y << width) &\
    \ mask) ^ *x;\n        *y = ((*x & mask) >> width) ^ *y;\n        *x = ((*y <<\
    \ width) & mask) ^ *x;\n      }\n    }\n  }\n  A.resize(m);\n  if (!keep_A) return\
    \ A;\n  swap(A, tmp);\n  return tmp;\n}\n#line 2 \"linalg/xor/solve_linear.hpp\"\
    \n\ntemplate <typename UINT>\nvc<UINT> solve_linear(int n, int m, vc<UINT> A,\
    \ UINT b) {\n  vc<UINT> mat(m);\n  UINT rhs = 0;\n\n  FOR(i, len(A)) {\n    UINT\
    \ a = A[i];\n    UINT c = b >> i & 1;\n    FOR_R(j, m) {\n      if (chmin(a, a\
    \ ^ mat[j])) {\n        c ^= (rhs >> j & 1);\n      }\n    }\n    if (a == 0 &&\
    \ c) return {};\n    if (a) {\n      int k = topbit(a);\n      FOR(j, k, m) {\n\
    \        if (chmin(mat[j], mat[j] ^ a)) rhs ^= c << j;\n      }\n      mat[k]\
    \ = a, rhs |= c << k;\n    }\n  }\n\n  vc<UINT> ANS = {rhs};\n  mat = transpose(m,\
    \ m, mat, 0);\n  FOR(i, m) {\n    if (!(mat[i] >> i & 1)) ANS.eb(mat[i] | UINT(1)\
    \ << i);\n  }\n  return ANS;\n}\n"
  code: "#include \"linalg/xor/transpose.hpp\"\n\ntemplate <typename UINT>\nvc<UINT>\
    \ solve_linear(int n, int m, vc<UINT> A, UINT b) {\n  vc<UINT> mat(m);\n  UINT\
    \ rhs = 0;\n\n  FOR(i, len(A)) {\n    UINT a = A[i];\n    UINT c = b >> i & 1;\n\
    \    FOR_R(j, m) {\n      if (chmin(a, a ^ mat[j])) {\n        c ^= (rhs >> j\
    \ & 1);\n      }\n    }\n    if (a == 0 && c) return {};\n    if (a) {\n     \
    \ int k = topbit(a);\n      FOR(j, k, m) {\n        if (chmin(mat[j], mat[j] ^\
    \ a)) rhs ^= c << j;\n      }\n      mat[k] = a, rhs |= c << k;\n    }\n  }\n\n\
    \  vc<UINT> ANS = {rhs};\n  mat = transpose(m, m, mat, 0);\n  FOR(i, m) {\n  \
    \  if (!(mat[i] >> i & 1)) ANS.eb(mat[i] | UINT(1) << i);\n  }\n  return ANS;\n\
    }\n"
  dependsOn:
  - linalg/xor/transpose.hpp
  isVerificationFile: false
  path: linalg/xor/solve_linear.hpp
  requiredBy: []
  timestamp: '2025-10-13 19:02:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xor/solve_linear.hpp
layout: document
redirect_from:
- /library/linalg/xor/solve_linear.hpp
- /library/linalg/xor/solve_linear.hpp.html
title: linalg/xor/solve_linear.hpp
---
