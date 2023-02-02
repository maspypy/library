---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1421.test.cpp
    title: test/yukicoder/1421.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/bitset/solve_linear_bitset.hpp\"\n// \u884C\u30D9\
    \u30AF\u30C8\u30EB\u3092 bitset \u306B\u3059\u308B\n// (2000, 8000) \u3067 300ms\
    \ \u7A0B\u5EA6\uFF08ABC276H\uFF09\ntemplate <typename BS, typename T>\nvc<BS>\
    \ solve_linear_bitset(int n, int m, vc<BS> A, vc<T> b) {\n  assert(len(b) == n);\n\
    \  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    FOR(i, rk, n) if (A[i][j])\
    \ {\n      if (i != rk) {\n        swap(A[rk], A[i]);\n        if (b[rk] != b[i])\
    \ b[rk] = !b[rk], b[i] = !b[i];\n      }\n      break;\n    }\n    if (!A[rk][j])\
    \ continue;\n    FOR(i, n) if (i != rk) {\n      if (A[i][j]) { b[i] = b[i] ^\
    \ b[rk], A[i] ^= A[rk]; }\n    }\n    ++rk;\n  }\n  FOR(i, rk, n) if (b[i]) return\
    \ {};\n  vc<BS> res(1);\n  vc<int> pivot(m, -1);\n  int p = 0;\n  FOR(i, rk) {\n\
    \    while (!A[i][p]) ++p;\n    res[0][p] = b[i], pivot[p] = i;\n  }\n  FOR(j,\
    \ m) if (pivot[j] == -1) {\n    BS x;\n    x[j] = 1;\n    FOR(k, j) if (pivot[k]\
    \ != -1) x[k] = A[pivot[k]][j];\n    res.eb(x);\n  }\n  return res;\n}\n"
  code: "// \u884C\u30D9\u30AF\u30C8\u30EB\u3092 bitset \u306B\u3059\u308B\n// (2000,\
    \ 8000) \u3067 300ms \u7A0B\u5EA6\uFF08ABC276H\uFF09\ntemplate <typename BS, typename\
    \ T>\nvc<BS> solve_linear_bitset(int n, int m, vc<BS> A, vc<T> b) {\n  assert(len(b)\
    \ == n);\n  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    FOR(i, rk,\
    \ n) if (A[i][j]) {\n      if (i != rk) {\n        swap(A[rk], A[i]);\n      \
    \  if (b[rk] != b[i]) b[rk] = !b[rk], b[i] = !b[i];\n      }\n      break;\n \
    \   }\n    if (!A[rk][j]) continue;\n    FOR(i, n) if (i != rk) {\n      if (A[i][j])\
    \ { b[i] = b[i] ^ b[rk], A[i] ^= A[rk]; }\n    }\n    ++rk;\n  }\n  FOR(i, rk,\
    \ n) if (b[i]) return {};\n  vc<BS> res(1);\n  vc<int> pivot(m, -1);\n  int p\
    \ = 0;\n  FOR(i, rk) {\n    while (!A[i][p]) ++p;\n    res[0][p] = b[i], pivot[p]\
    \ = i;\n  }\n  FOR(j, m) if (pivot[j] == -1) {\n    BS x;\n    x[j] = 1;\n   \
    \ FOR(k, j) if (pivot[k] != -1) x[k] = A[pivot[k]][j];\n    res.eb(x);\n  }\n\
    \  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/bitset/solve_linear_bitset.hpp
  requiredBy: []
  timestamp: '2023-02-01 02:28:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1421.test.cpp
documentation_of: linalg/bitset/solve_linear_bitset.hpp
layout: document
redirect_from:
- /library/linalg/bitset/solve_linear_bitset.hpp
- /library/linalg/bitset/solve_linear_bitset.hpp.html
title: linalg/bitset/solve_linear_bitset.hpp
---
