---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2907_2.test.cpp
    title: test/3_yukicoder/2907_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"linalg/rank_for_all_column_subset.hpp\"\n\n// return: 2^M\
    \ integers\n// time: (N+M)^3+2^M\ntemplate <typename T>\nvc<int> rank_for_all_column_subset(vvc<T>\
    \ A, int N, int M) {\n  assert(len(A) == N);\n  FOR(i, N) assert(len(A[i]) ==\
    \ M);\n  int rk = 0;\n  FOR(j, M) {\n    if (rk == N) break;\n    FOR(i, rk, N)\
    \ if (A[i][j] != 0) {\n      swap(A[rk], A[i]);\n      break;\n    }\n    if (A[rk][j]\
    \ == 0) continue;\n    T c = T(1) / A[rk][j];\n    for (auto&& x: A[rk]) x *=\
    \ c;\n    FOR(i, N) if (i != rk) {\n      T c = A[i][j];\n      FOR(k, j, M) {\
    \ A[i][k] -= A[rk][k] * c; }\n    }\n    ++rk;\n  }\n  A.resize(rk);\n\n  /*\n\
    \  \u3042\u308B\u884C\n  (M,M) matrix \u306E\u5BFE\u89D2\u306B\u7F6E\u304F\n \
    \ 1**00*0*\n  00000000\n  00000000\n  00010*0*\n  00001*0*\n  00000000\n  0000001*\n\
    \  00000000\n  \u5148\u982D\u5217\u304B\u3089\u9806\u306B\u51E6\u7406\u3059\u308B\
    .\n  */\n\n  N = M;\n  vv(T, work, N, N);\n  vvv(T, memo, N, N, N);\n  for (auto&\
    \ X: A) {\n    int p = 0;\n    FOR_R(i, N) if (X[i] != 0) p = i;\n    work[p]\
    \ = X;\n  }\n\n  vc<int> ANS(1 << M);\n  auto dfs = [&](auto& dfs, int s, int\
    \ k, int r) -> void {\n    if (k == N) {\n      ANS[s] = r;\n      return;\n \
    \   }\n    if (work[k][k] == T(0)) {\n      // \u4F7F\u3046\u306B\u3057\u3066\u3082\
    \u4F7F\u308F\u306A\u3044\u306B\u3057\u3066\u3082 rank \u306B\u306F\u5F71\u97FF\
    \u3057\u306A\u3044\n      dfs(dfs, s, k + 1, r);\n      dfs(dfs, s | 1 << k, k\
    \ + 1, r);\n      return;\n    }\n    assert(work[k][k] == T(1));\n    // \u4F7F\
    \u3046\u5834\u5408 : \u305D\u306E\u307E\u307E submatrix \u306B\u3064\u3044\u3066\
    \u89E3\u304F\n    dfs(dfs, s | 1 << k, k + 1, r + 1);\n    // \u4F7F\u308F\u306A\
    \u3044\u5834\u5408\n    int p = -1;\n    FOR(i, k + 1, N) {\n      if (work[k][i]\
    \ != T(0)) {\n        p = i;\n        break;\n      }\n    }\n    if (p == -1)\
    \ { return dfs(dfs, s, k + 1, r); }\n    // snapshot\n    FOR(i, k + 1, N) FOR(j,\
    \ k + 1, N) memo[k][i][j] = work[i][j];\n    T c = T(1) / work[k][p];\n    FOR(j,\
    \ p, N) work[p][j] = work[k][j] * c;\n    FOR(i, k + 1, p) {\n      T c = work[i][p];\n\
    \      FOR(j, p, N) work[i][j] -= c * work[p][j];\n    }\n    dfs(dfs, s, k +\
    \ 1, r);\n    // rollback\n    FOR(i, k + 1, N) FOR(j, k + 1, N) work[i][j] =\
    \ memo[k][i][j];\n  };\n  dfs(dfs, 0, 0, 0);\n  return ANS;\n}\n"
  code: "\n// return: 2^M integers\n// time: (N+M)^3+2^M\ntemplate <typename T>\n\
    vc<int> rank_for_all_column_subset(vvc<T> A, int N, int M) {\n  assert(len(A)\
    \ == N);\n  FOR(i, N) assert(len(A[i]) == M);\n  int rk = 0;\n  FOR(j, M) {\n\
    \    if (rk == N) break;\n    FOR(i, rk, N) if (A[i][j] != 0) {\n      swap(A[rk],\
    \ A[i]);\n      break;\n    }\n    if (A[rk][j] == 0) continue;\n    T c = T(1)\
    \ / A[rk][j];\n    for (auto&& x: A[rk]) x *= c;\n    FOR(i, N) if (i != rk) {\n\
    \      T c = A[i][j];\n      FOR(k, j, M) { A[i][k] -= A[rk][k] * c; }\n    }\n\
    \    ++rk;\n  }\n  A.resize(rk);\n\n  /*\n  \u3042\u308B\u884C\n  (M,M) matrix\
    \ \u306E\u5BFE\u89D2\u306B\u7F6E\u304F\n  1**00*0*\n  00000000\n  00000000\n \
    \ 00010*0*\n  00001*0*\n  00000000\n  0000001*\n  00000000\n  \u5148\u982D\u5217\
    \u304B\u3089\u9806\u306B\u51E6\u7406\u3059\u308B.\n  */\n\n  N = M;\n  vv(T, work,\
    \ N, N);\n  vvv(T, memo, N, N, N);\n  for (auto& X: A) {\n    int p = 0;\n   \
    \ FOR_R(i, N) if (X[i] != 0) p = i;\n    work[p] = X;\n  }\n\n  vc<int> ANS(1\
    \ << M);\n  auto dfs = [&](auto& dfs, int s, int k, int r) -> void {\n    if (k\
    \ == N) {\n      ANS[s] = r;\n      return;\n    }\n    if (work[k][k] == T(0))\
    \ {\n      // \u4F7F\u3046\u306B\u3057\u3066\u3082\u4F7F\u308F\u306A\u3044\u306B\
    \u3057\u3066\u3082 rank \u306B\u306F\u5F71\u97FF\u3057\u306A\u3044\n      dfs(dfs,\
    \ s, k + 1, r);\n      dfs(dfs, s | 1 << k, k + 1, r);\n      return;\n    }\n\
    \    assert(work[k][k] == T(1));\n    // \u4F7F\u3046\u5834\u5408 : \u305D\u306E\
    \u307E\u307E submatrix \u306B\u3064\u3044\u3066\u89E3\u304F\n    dfs(dfs, s |\
    \ 1 << k, k + 1, r + 1);\n    // \u4F7F\u308F\u306A\u3044\u5834\u5408\n    int\
    \ p = -1;\n    FOR(i, k + 1, N) {\n      if (work[k][i] != T(0)) {\n        p\
    \ = i;\n        break;\n      }\n    }\n    if (p == -1) { return dfs(dfs, s,\
    \ k + 1, r); }\n    // snapshot\n    FOR(i, k + 1, N) FOR(j, k + 1, N) memo[k][i][j]\
    \ = work[i][j];\n    T c = T(1) / work[k][p];\n    FOR(j, p, N) work[p][j] = work[k][j]\
    \ * c;\n    FOR(i, k + 1, p) {\n      T c = work[i][p];\n      FOR(j, p, N) work[i][j]\
    \ -= c * work[p][j];\n    }\n    dfs(dfs, s, k + 1, r);\n    // rollback\n   \
    \ FOR(i, k + 1, N) FOR(j, k + 1, N) work[i][j] = memo[k][i][j];\n  };\n  dfs(dfs,\
    \ 0, 0, 0);\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: linalg/rank_for_all_column_subset.hpp
  requiredBy: []
  timestamp: '2024-09-30 22:44:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/2907_2.test.cpp
documentation_of: linalg/rank_for_all_column_subset.hpp
layout: document
redirect_from:
- /library/linalg/rank_for_all_column_subset.hpp
- /library/linalg/rank_for_all_column_subset.hpp.html
title: linalg/rank_for_all_column_subset.hpp
---
