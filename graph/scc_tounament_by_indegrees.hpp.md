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
  bundledCode: "#line 1 \"graph/scc_tounament_by_indegrees.hpp\"\npair<int, vc<int>>\
    \ scc_tournament_by_indegrees(vc<int> indeg) {\n  int N = len(indeg);\n  auto\
    \ I = argsort(indeg);\n  vc<int> ANS(N);\n  ll sm = 0;\n  int nxt = 0;\n  FOR(i,\
    \ N) {\n    int v = I[i];\n    ANS[v] = nxt;\n    // I[0:i] \u304C\u3072\u3068\
    \u3064\u306E\u6210\u5206\u304B\u3069\u3046\u304B\n    sm += indeg[v];\n    ll\
    \ TS = sm - (i + 1) * i / 2;\n    if (TS == 0) ++nxt;\n  }\n  return {nxt, ANS};\n\
    }\n"
  code: "pair<int, vc<int>> scc_tournament_by_indegrees(vc<int> indeg) {\n  int N\
    \ = len(indeg);\n  auto I = argsort(indeg);\n  vc<int> ANS(N);\n  ll sm = 0;\n\
    \  int nxt = 0;\n  FOR(i, N) {\n    int v = I[i];\n    ANS[v] = nxt;\n    // I[0:i]\
    \ \u304C\u3072\u3068\u3064\u306E\u6210\u5206\u304B\u3069\u3046\u304B\n    sm +=\
    \ indeg[v];\n    ll TS = sm - (i + 1) * i / 2;\n    if (TS == 0) ++nxt;\n  }\n\
    \  return {nxt, ANS};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/scc_tounament_by_indegrees.hpp
  requiredBy: []
  timestamp: '2023-03-15 22:02:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/scc_tounament_by_indegrees.hpp
layout: document
redirect_from:
- /library/graph/scc_tounament_by_indegrees.hpp
- /library/graph/scc_tounament_by_indegrees.hpp.html
title: graph/scc_tounament_by_indegrees.hpp
---
