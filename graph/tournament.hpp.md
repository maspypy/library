---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/1_mytest/tournament.test.cpp
    title: test/1_mytest/tournament.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://atcoder.jp/contests/joisp2024/tasks/joisp2024_l
    - https://codeforces.com/problemset/problem/412/D
    - https://github.com/maspypy/library/blob/main/graph/tournament.hpp
    - https://yukicoder.me/problems/no/2085
  bundledCode: "#line 1 \"graph/tournament.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/graph/tournament.hpp\n\
    // https://yukicoder.me/problems/no/2085\n// https://codeforces.com/problemset/problem/412/D\n\
    template <typename F>\nvc<int> hamiltonian_path_in_tournament(int n, F check)\
    \ {\n  auto dfs = [&](auto& dfs, int L, int R) -> vc<int> {\n    if (R == L +\
    \ 1) return {L};\n    int M = (L + R) / 2;\n    vc<int> X = dfs(dfs, L, M);\n\
    \    vc<int> Y = dfs(dfs, M, R);\n    vc<int> P;\n    P.reserve(R - L);\n    int\
    \ i = 0, j = 0;\n    while (len(P) < R - L) {\n      if (i == len(X)) {\n    \
    \    P.eb(Y[j++]);\n      }\n      elif (j == len(Y)) { P.eb(X[i++]); }\n    \
    \  else {\n        if (check(X[i], Y[j])) {\n          P.eb(X[i++]);\n       \
    \ } else {\n          P.eb(Y[j++]);\n        }\n      }\n    }\n    return P;\n\
    \  };\n  return dfs(dfs, 0, n);\n}\n\n// https://atcoder.jp/contests/joisp2024/tasks/joisp2024_l\n\
    vc<string> from_outdegrees(vc<int> A) {\n  int N = len(A);\n  FOR(i, N - 1) assert(A[i]\
    \ <= A[i + 1]);\n  for (auto x : A) {\n    if (x < 0 || x >= N) return {};\n \
    \ }\n\n  vc<int> F(N);\n  for (auto x : A) F[x]++;\n\n  vc<string> ANS(N, string(N,\
    \ '-'));\n  FOR(i, N) {\n    int lose = N - 1 - i - A[i];\n    if (lose < 0) return\
    \ {};\n\n    F[A[i]]--;\n\n    FOR(j, i + 1, N) {\n      ANS[i][j] = '1';\n  \
    \    ANS[j][i] = '0';\n    }\n\n    int p = N;\n    FOR_R(x, N) {\n      p -=\
    \ F[x];\n      if (x == 0) continue;\n      int k = min(lose, F[x]);\n      FOR(j,\
    \ p, p + k) {\n        ANS[i][j] = '0';\n        ANS[j][i] = '1';\n      }\n \
    \     lose -= k;\n    }\n    if (lose != 0) return {};\n\n    FOR(j, i + 1, N)\
    \ {\n      if (ANS[i][j] == '0') {\n        F[A[j]]--;\n        A[j]--;\n    \
    \    F[A[j]]++;\n      }\n    }\n  }\n  return ANS;\n}\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/graph/tournament.hpp\n\
    // https://yukicoder.me/problems/no/2085\n// https://codeforces.com/problemset/problem/412/D\n\
    template <typename F>\nvc<int> hamiltonian_path_in_tournament(int n, F check)\
    \ {\n  auto dfs = [&](auto& dfs, int L, int R) -> vc<int> {\n    if (R == L +\
    \ 1) return {L};\n    int M = (L + R) / 2;\n    vc<int> X = dfs(dfs, L, M);\n\
    \    vc<int> Y = dfs(dfs, M, R);\n    vc<int> P;\n    P.reserve(R - L);\n    int\
    \ i = 0, j = 0;\n    while (len(P) < R - L) {\n      if (i == len(X)) {\n    \
    \    P.eb(Y[j++]);\n      }\n      elif (j == len(Y)) { P.eb(X[i++]); }\n    \
    \  else {\n        if (check(X[i], Y[j])) {\n          P.eb(X[i++]);\n       \
    \ } else {\n          P.eb(Y[j++]);\n        }\n      }\n    }\n    return P;\n\
    \  };\n  return dfs(dfs, 0, n);\n}\n\n// https://atcoder.jp/contests/joisp2024/tasks/joisp2024_l\n\
    vc<string> from_outdegrees(vc<int> A) {\n  int N = len(A);\n  FOR(i, N - 1) assert(A[i]\
    \ <= A[i + 1]);\n  for (auto x : A) {\n    if (x < 0 || x >= N) return {};\n \
    \ }\n\n  vc<int> F(N);\n  for (auto x : A) F[x]++;\n\n  vc<string> ANS(N, string(N,\
    \ '-'));\n  FOR(i, N) {\n    int lose = N - 1 - i - A[i];\n    if (lose < 0) return\
    \ {};\n\n    F[A[i]]--;\n\n    FOR(j, i + 1, N) {\n      ANS[i][j] = '1';\n  \
    \    ANS[j][i] = '0';\n    }\n\n    int p = N;\n    FOR_R(x, N) {\n      p -=\
    \ F[x];\n      if (x == 0) continue;\n      int k = min(lose, F[x]);\n      FOR(j,\
    \ p, p + k) {\n        ANS[i][j] = '0';\n        ANS[j][i] = '1';\n      }\n \
    \     lose -= k;\n    }\n    if (lose != 0) return {};\n\n    FOR(j, i + 1, N)\
    \ {\n      if (ANS[i][j] == '0') {\n        F[A[j]]--;\n        A[j]--;\n    \
    \    F[A[j]]++;\n      }\n    }\n  }\n  return ANS;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/tournament.hpp
  requiredBy: []
  timestamp: '2026-10-15 19:54:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/1_mytest/tournament.test.cpp
documentation_of: graph/tournament.hpp
layout: document
redirect_from:
- /library/graph/tournament.hpp
- /library/graph/tournament.hpp.html
title: graph/tournament.hpp
---
