---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/mytest/tournament.test.cpp
    title: test/mytest/tournament.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://yukicoder.me/problems/no/2085
  bundledCode: "#line 1 \"graph/tournament.hpp\"\n// https://yukicoder.me/problems/no/2085\n\
    template <typename F>\nvc<int> hamiltonian_path_in_tournament(int n, F check)\
    \ {\n  auto dfs = [&](auto& dfs, int L, int R) -> vc<int> {\n    if (R == L +\
    \ 1) return {L};\n    int M = (L + R) / 2;\n    vc<int> X = dfs(dfs, L, M);\n\
    \    vc<int> Y = dfs(dfs, M, R);\n    vc<int> P;\n    P.reserve(R - L);\n    int\
    \ i = 0, j = 0;\n    while (len(P) < R - L) {\n      if (i == len(X)) { P.eb(Y[j++]);\
    \ }\n      elif (j == len(Y)) { P.eb(X[i++]); }\n      else {\n        if (check(X[i],\
    \ Y[j])) {\n          P.eb(X[i++]);\n        } else {\n          P.eb(Y[j++]);\n\
    \        }\n      }\n    }\n    return P;\n  };\n  return dfs(dfs, 0, n);\n}\n"
  code: "// https://yukicoder.me/problems/no/2085\ntemplate <typename F>\nvc<int>\
    \ hamiltonian_path_in_tournament(int n, F check) {\n  auto dfs = [&](auto& dfs,\
    \ int L, int R) -> vc<int> {\n    if (R == L + 1) return {L};\n    int M = (L\
    \ + R) / 2;\n    vc<int> X = dfs(dfs, L, M);\n    vc<int> Y = dfs(dfs, M, R);\n\
    \    vc<int> P;\n    P.reserve(R - L);\n    int i = 0, j = 0;\n    while (len(P)\
    \ < R - L) {\n      if (i == len(X)) { P.eb(Y[j++]); }\n      elif (j == len(Y))\
    \ { P.eb(X[i++]); }\n      else {\n        if (check(X[i], Y[j])) {\n        \
    \  P.eb(X[i++]);\n        } else {\n          P.eb(Y[j++]);\n        }\n     \
    \ }\n    }\n    return P;\n  };\n  return dfs(dfs, 0, n);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/tournament.hpp
  requiredBy: []
  timestamp: '2022-10-01 14:15:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/mytest/tournament.test.cpp
documentation_of: graph/tournament.hpp
layout: document
redirect_from:
- /library/graph/tournament.hpp
- /library/graph/tournament.hpp.html
title: graph/tournament.hpp
---
