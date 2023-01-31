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
  bundledCode: "#line 1 \"linalg/bitset/solve_linear_F2.hpp\"\n// bitset \u3067\u9AD8\
    \u901F\u5316\u3057\u3066\u3044\u308B\n// (2000, 8000) \u3067 300ms \u7A0B\u5EA6\
    \uFF08ABC276H\uFF09\ntemplate <int MAX_M, typename T = bool>\nvvc<T> solve_linear_F2(const\
    \ int n, const int m, vvc<T> a, vc<T> b) {\n  using BS = bitset<MAX_M>;\n  vc<BS>\
    \ mat(n);\n  FOR(i, n) FOR(j, m) mat[i][j] = a[i][j];\n  int rk = 0;\n  FOR(j,\
    \ m) {\n    if (rk == n) break;\n    if (mat[rk][j] == 0) {\n      FOR(i, rk +\
    \ 1, n) if (mat[i][j] != 0) {\n        swap(mat[rk], mat[i]);\n        swap(b[rk],\
    \ b[i]);\n        break;\n      }\n    }\n    if (mat[rk][j] == 0) continue;\n\
    \    FOR(i, n) if (i != rk) {\n      bool c = mat[i][j];\n      if (c) {\n   \
    \     b[i] = b[i] ^ b[rk];\n        mat[i] ^= mat[rk];\n      }\n    }\n    ++rk;\n\
    \  }\n  FOR3(i, rk, n) if (b[i] != 0) return {};\n  vv(T, res, 1, m);\n  vc<int>\
    \ pivot(m, -1);\n  int p = 0;\n  FOR(i, rk) {\n    while (mat[i][p] == 0) ++p;\n\
    \    res[0][p] = b[i];\n    pivot[p] = i;\n  }\n  FOR(j, m) if (pivot[j] == -1)\
    \ {\n    vc<T> x(m);\n    x[j] = 1;\n    FOR(k, j) if (pivot[k] != -1) x[k] =\
    \ mat[pivot[k]][j];\n    res.eb(x);\n  }\n  return res;\n}\n"
  code: "// bitset \u3067\u9AD8\u901F\u5316\u3057\u3066\u3044\u308B\n// (2000, 8000)\
    \ \u3067 300ms \u7A0B\u5EA6\uFF08ABC276H\uFF09\ntemplate <int MAX_M, typename\
    \ T = bool>\nvvc<T> solve_linear_F2(const int n, const int m, vvc<T> a, vc<T>\
    \ b) {\n  using BS = bitset<MAX_M>;\n  vc<BS> mat(n);\n  FOR(i, n) FOR(j, m) mat[i][j]\
    \ = a[i][j];\n  int rk = 0;\n  FOR(j, m) {\n    if (rk == n) break;\n    if (mat[rk][j]\
    \ == 0) {\n      FOR(i, rk + 1, n) if (mat[i][j] != 0) {\n        swap(mat[rk],\
    \ mat[i]);\n        swap(b[rk], b[i]);\n        break;\n      }\n    }\n    if\
    \ (mat[rk][j] == 0) continue;\n    FOR(i, n) if (i != rk) {\n      bool c = mat[i][j];\n\
    \      if (c) {\n        b[i] = b[i] ^ b[rk];\n        mat[i] ^= mat[rk];\n  \
    \    }\n    }\n    ++rk;\n  }\n  FOR3(i, rk, n) if (b[i] != 0) return {};\n  vv(T,\
    \ res, 1, m);\n  vc<int> pivot(m, -1);\n  int p = 0;\n  FOR(i, rk) {\n    while\
    \ (mat[i][p] == 0) ++p;\n    res[0][p] = b[i];\n    pivot[p] = i;\n  }\n  FOR(j,\
    \ m) if (pivot[j] == -1) {\n    vc<T> x(m);\n    x[j] = 1;\n    FOR(k, j) if (pivot[k]\
    \ != -1) x[k] = mat[pivot[k]][j];\n    res.eb(x);\n  }\n  return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: linalg/bitset/solve_linear_F2.hpp
  requiredBy: []
  timestamp: '2023-01-31 19:52:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linalg/bitset/solve_linear_F2.hpp
layout: document
redirect_from:
- /library/linalg/bitset/solve_linear_F2.hpp
- /library/linalg/bitset/solve_linear_F2.hpp.html
title: linalg/bitset/solve_linear_F2.hpp
---
