---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: alg/monoid/merge_vector_space.hpp
    title: alg/monoid/merge_vector_space.hpp
  - icon: ':question:'
    path: linalg/xor/vector_space.hpp
    title: linalg/xor/vector_space.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/mytest/QOJ5445.test.cpp
    title: test/mytest/QOJ5445.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/mytest/xor_transpose.test.cpp
    title: test/mytest/xor_transpose.test.cpp
  - icon: ':x:'
    path: test/yukicoder/184.test.cpp
    title: test/yukicoder/184.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc141f.test.cpp
    title: test_atcoder/abc141f.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links:
    - https://github.com/dsnet/matrix-transpose
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
    \ A;\n  swap(A, tmp);\n  return tmp;\n}\n"
  code: "#pragma once\n\n// n x m \u884C\u5217\u306E transpose\u3002O((n+m)log(n+m))\
    \ \u6642\u9593\u3002\n// https://github.com/dsnet/matrix-transpose\ntemplate <typename\
    \ UINT>\nvc<UINT> transpose(int n, int m, vc<UINT>& A, bool keep_A = 1) {\n  assert(max(n,\
    \ m) <= numeric_limits<UINT>::digits);\n  assert(len(A) == n);\n  vc<UINT> tmp;\n\
    \  if (keep_A) tmp = A;\n  int LOG = 0;\n  while ((1 << LOG) < max(n, m)) ++LOG;\n\
    \  A.resize(1 << LOG);\n  int width = 1 << LOG;\n  UINT mask = 1;\n  FOR(i, LOG)\
    \ mask = mask | (mask << (1 << i));\n  FOR(t, LOG) {\n    width >>= 1;\n    mask\
    \ = mask ^ (mask >> width);\n    FOR(i, 1 << t) {\n      FOR(j, width) {\n   \
    \     UINT* x = &A[width * (2 * i + 0) + j];\n        UINT* y = &A[width * (2\
    \ * i + 1) + j];\n        *x = ((*y << width) & mask) ^ *x;\n        *y = ((*x\
    \ & mask) >> width) ^ *y;\n        *x = ((*y << width) & mask) ^ *x;\n      }\n\
    \    }\n  }\n  A.resize(m);\n  if (!keep_A) return A;\n  swap(A, tmp);\n  return\
    \ tmp;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/transpose.hpp
  requiredBy:
  - linalg/xor/vector_space.hpp
  - alg/monoid/merge_vector_space.hpp
  timestamp: '2023-02-03 02:21:10+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc141f.test.cpp
  - test/yukicoder/184.test.cpp
  - test/mytest/xor_transpose.test.cpp
  - test/mytest/QOJ5445.test.cpp
documentation_of: linalg/xor/transpose.hpp
layout: document
redirect_from:
- /library/linalg/xor/transpose.hpp
- /library/linalg/xor/transpose.hpp.html
title: linalg/xor/transpose.hpp
---
