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
  bundledCode: "#line 1 \"graph/cactus.hpp\"\n\nvvc<int> get_cactus_cycle(Graph<int,\
    \ 0>& G, Graph<int, 0>& BCT,\n                          Tree<Graph<int, 0>>& tree)\
    \ {\n  vvc<pair<int, int>> es(BCT.N);\n  vvc<int> cs(BCT.N);\n  for (auto& e :\
    \ G.edges) {\n    int a = e.frm, b = e.to;\n    int k = tree.jump(a, b, 1);\n\
    \    es[k].eb(a, b);\n  }\n  vc<int> SM(G.N);\n\n  FOR(k, G.N, BCT.N) {\n    auto&\
    \ E = es[k];\n    if (len(E) == 1) continue;\n    for (auto& [a, b] : E) SM[a]\
    \ += b, SM[b] += a;\n    vc<int> C;\n    C.eb(E[0].fi);\n    C.eb(E[0].se);\n\
    \    while (C.back() != C[0]) {\n      int a = C[len(C) - 2], b = C[len(C) - 1];\n\
    \      C.eb(SM[b] - a);\n    }\n    POP(C);\n    cs[k] = C;\n    for (auto& [a,\
    \ b] : E) SM[a] -= b, SM[b] -= a;\n  }\n  return cs;\n}\n"
  code: "\nvvc<int> get_cactus_cycle(Graph<int, 0>& G, Graph<int, 0>& BCT,\n     \
    \                     Tree<Graph<int, 0>>& tree) {\n  vvc<pair<int, int>> es(BCT.N);\n\
    \  vvc<int> cs(BCT.N);\n  for (auto& e : G.edges) {\n    int a = e.frm, b = e.to;\n\
    \    int k = tree.jump(a, b, 1);\n    es[k].eb(a, b);\n  }\n  vc<int> SM(G.N);\n\
    \n  FOR(k, G.N, BCT.N) {\n    auto& E = es[k];\n    if (len(E) == 1) continue;\n\
    \    for (auto& [a, b] : E) SM[a] += b, SM[b] += a;\n    vc<int> C;\n    C.eb(E[0].fi);\n\
    \    C.eb(E[0].se);\n    while (C.back() != C[0]) {\n      int a = C[len(C) -\
    \ 2], b = C[len(C) - 1];\n      C.eb(SM[b] - a);\n    }\n    POP(C);\n    cs[k]\
    \ = C;\n    for (auto& [a, b] : E) SM[a] -= b, SM[b] -= a;\n  }\n  return cs;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/cactus.hpp
  requiredBy: []
  timestamp: '2026-02-03 22:59:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/cactus.hpp
layout: document
redirect_from:
- /library/graph/cactus.hpp
- /library/graph/cactus.hpp.html
title: graph/cactus.hpp
---
