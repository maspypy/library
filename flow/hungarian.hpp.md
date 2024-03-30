---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/assignment.test.cpp
    title: test/library_checker/graph/assignment.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1789.test.cpp
    title: test/yukicoder/1789.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2573.test.cpp
    title: test/yukicoder/2573.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/hungarian.hpp\"\n// returns: (ans, match, X, Y)\n//\
    \ N<=M \u3092\u4EEE\u5B9A, infty \u3082 valid \u3068\u3057\u3066\u8A08\u7B97\u3057\
    \u3066\u3044\u308B, O(N^2M) time\u3002\n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\
    \u306F\u6B21\u306E\u53CC\u5BFE\u554F\u984C\u306E\u89E3\u3067\u3042\u308B\uFF1A\
    \n//   maximize \\sum x_i + \\sum y_j, subj to x_i + y_j\\leq C_{ij}\n// n \u30EB\
    \u30FC\u30D7\u3067\u6253\u3061\u5207\u3063\u3066\u3082\u5927\u304D\u3055 n \u306E\
    \u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u6700\u9069\u89E3\u3067\u306F\u306A\u3044\
    \ntemplate <typename T, bool MINIMIZE>\ntuple<T, vc<int>, vc<T>, vc<T>> hungarian(vvc<T>&\
    \ C) {\n  int N = len(C);\n  int M = len(C[0]);\n  assert(N <= M);\n  vv(T, A,\
    \ N + 1, M + 1);\n  FOR(i, N) FOR(j, M) A[1 + i][1 + j] = (MINIMIZE ? 1 : -1)\
    \ * C[i][j];\n  ++N, ++M;\n\n  vector<int> P(M), way(M);\n  vector<T> X(N), Y(M);\n\
    \  vc<T> minV;\n  vc<bool> used;\n\n  for (int i = 1; i < N; i++) {\n    P[0]\
    \ = i;\n    minV.assign(M, infty<T>);\n    used.assign(M, false);\n    int j0\
    \ = 0;\n    while (P[j0] != 0) {\n      int i0 = P[j0], j1 = 0;\n      used[j0]\
    \ = true;\n      T delta = infty<T>;\n      for (int j = 1; j < M; j++) {\n  \
    \      if (used[j]) continue;\n        T curr = A[i0][j] - X[i0] - Y[j];\n   \
    \     if (curr < minV[j]) minV[j] = curr, way[j] = j0;\n        if (minV[j] <\
    \ delta) delta = minV[j], j1 = j;\n      }\n      for (int j = 0; j < M; j++)\
    \ {\n        if (used[j])\n          X[P[j]] += delta, Y[j] -= delta;\n      \
    \  else\n          minV[j] -= delta;\n      }\n      j0 = j1;\n    }\n    do {\n\
    \      P[j0] = P[way[j0]];\n      j0 = way[j0];\n    } while (j0 != 0);\n  }\n\
    \  T res = -Y[0];\n  X.erase(X.begin());\n  Y.erase(Y.begin());\n  vc<int> match(N);\n\
    \  FOR(i, N) match[P[i]] = i;\n  match.erase(match.begin());\n  for (auto&& i:\
    \ match) --i;\n  if (!MINIMIZE) res = -res;\n  return {res, match, X, Y};\n}\n"
  code: "// returns: (ans, match, X, Y)\n// N<=M \u3092\u4EEE\u5B9A, infty \u3082\
    \ valid \u3068\u3057\u3066\u8A08\u7B97\u3057\u3066\u3044\u308B, O(N^2M) time\u3002\
    \n// \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306F\u6B21\u306E\u53CC\u5BFE\u554F\u984C\
    \u306E\u89E3\u3067\u3042\u308B\uFF1A\n//   maximize \\sum x_i + \\sum y_j, subj\
    \ to x_i + y_j\\leq C_{ij}\n// n \u30EB\u30FC\u30D7\u3067\u6253\u3061\u5207\u3063\
    \u3066\u3082\u5927\u304D\u3055 n \u306E\u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u6700\
    \u9069\u89E3\u3067\u306F\u306A\u3044\ntemplate <typename T, bool MINIMIZE>\ntuple<T,\
    \ vc<int>, vc<T>, vc<T>> hungarian(vvc<T>& C) {\n  int N = len(C);\n  int M =\
    \ len(C[0]);\n  assert(N <= M);\n  vv(T, A, N + 1, M + 1);\n  FOR(i, N) FOR(j,\
    \ M) A[1 + i][1 + j] = (MINIMIZE ? 1 : -1) * C[i][j];\n  ++N, ++M;\n\n  vector<int>\
    \ P(M), way(M);\n  vector<T> X(N), Y(M);\n  vc<T> minV;\n  vc<bool> used;\n\n\
    \  for (int i = 1; i < N; i++) {\n    P[0] = i;\n    minV.assign(M, infty<T>);\n\
    \    used.assign(M, false);\n    int j0 = 0;\n    while (P[j0] != 0) {\n     \
    \ int i0 = P[j0], j1 = 0;\n      used[j0] = true;\n      T delta = infty<T>;\n\
    \      for (int j = 1; j < M; j++) {\n        if (used[j]) continue;\n       \
    \ T curr = A[i0][j] - X[i0] - Y[j];\n        if (curr < minV[j]) minV[j] = curr,\
    \ way[j] = j0;\n        if (minV[j] < delta) delta = minV[j], j1 = j;\n      }\n\
    \      for (int j = 0; j < M; j++) {\n        if (used[j])\n          X[P[j]]\
    \ += delta, Y[j] -= delta;\n        else\n          minV[j] -= delta;\n      }\n\
    \      j0 = j1;\n    }\n    do {\n      P[j0] = P[way[j0]];\n      j0 = way[j0];\n\
    \    } while (j0 != 0);\n  }\n  T res = -Y[0];\n  X.erase(X.begin());\n  Y.erase(Y.begin());\n\
    \  vc<int> match(N);\n  FOR(i, N) match[P[i]] = i;\n  match.erase(match.begin());\n\
    \  for (auto&& i: match) --i;\n  if (!MINIMIZE) res = -res;\n  return {res, match,\
    \ X, Y};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/hungarian.hpp
  requiredBy: []
  timestamp: '2023-11-30 16:31:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/assignment.test.cpp
  - test/yukicoder/2573.test.cpp
  - test/yukicoder/1789.test.cpp
documentation_of: flow/hungarian.hpp
layout: document
redirect_from:
- /library/flow/hungarian.hpp
- /library/flow/hungarian.hpp.html
title: flow/hungarian.hpp
---
