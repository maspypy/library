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
  bundledCode: "#line 1 \"linalg/xor/solve_linear.hpp\"\n// \u884C\u30D9\u30AF\u30C8\
    \u30EB\n// Ax==0\nARR solve_linear_xor(ARR& mat) {\n  int n = 0, m = 64;\n  for\
    \ (auto&& x: mat)\n    if (x) ++n;\n  int rk = 0;\n  FOR(j, m) {\n    if (rk ==\
    \ n) break;\n    if (!(mat[rk] >> j & 1)) {\n      FOR(i, rk + 1, n) if (mat[i]\
    \ >> j & 1) {\n        swap(mat[rk], mat[i]);\n        break;\n      }\n    }\n\
    \    if (!(mat[rk] >> j & 1)) continue;\n    FOR(i, n) if (i != rk) {\n      if\
    \ (mat[i] >> j & 1) { mat[i] ^= mat[rk]; }\n    }\n    ++rk;\n  }\n  ARR res{};\n\
    \  vc<int> pivot(m, -1);\n  int p = 0;\n  FOR(i, rk) {\n    while (!(mat[i] >>\
    \ p & 1)) ++p;\n    pivot[p] = i;\n  }\n  int nxt = 0;\n  FOR(j, m) if (pivot[j]\
    \ == -1) {\n    u64 x = 0;\n    x |= u64(1) << j;\n    FOR(k, j) if (pivot[k]\
    \ != -1 && (mat[pivot[k]] >> j & 1)) {\n      x |= u64(1) << k;\n    }\n    res[nxt++]\
    \ = x;\n  }\n  return res;\n}\n"
  code: "// \u884C\u30D9\u30AF\u30C8\u30EB\n// Ax==0\nARR solve_linear_xor(ARR& mat)\
    \ {\n  int n = 0, m = 64;\n  for (auto&& x: mat)\n    if (x) ++n;\n  int rk =\
    \ 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    if (!(mat[rk] >> j & 1)) {\n\
    \      FOR(i, rk + 1, n) if (mat[i] >> j & 1) {\n        swap(mat[rk], mat[i]);\n\
    \        break;\n      }\n    }\n    if (!(mat[rk] >> j & 1)) continue;\n    FOR(i,\
    \ n) if (i != rk) {\n      if (mat[i] >> j & 1) { mat[i] ^= mat[rk]; }\n    }\n\
    \    ++rk;\n  }\n  ARR res{};\n  vc<int> pivot(m, -1);\n  int p = 0;\n  FOR(i,\
    \ rk) {\n    while (!(mat[i] >> p & 1)) ++p;\n    pivot[p] = i;\n  }\n  int nxt\
    \ = 0;\n  FOR(j, m) if (pivot[j] == -1) {\n    u64 x = 0;\n    x |= u64(1) <<\
    \ j;\n    FOR(k, j) if (pivot[k] != -1 && (mat[pivot[k]] >> j & 1)) {\n      x\
    \ |= u64(1) << k;\n    }\n    res[nxt++] = x;\n  }\n  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/xor/solve_linear.hpp
  requiredBy: []
  timestamp: '2023-01-31 19:52:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/xor/solve_linear.hpp
layout: document
redirect_from:
- /library/linalg/xor/solve_linear.hpp
- /library/linalg/xor/solve_linear.hpp.html
title: linalg/xor/solve_linear.hpp
---
