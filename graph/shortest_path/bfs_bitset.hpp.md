---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1400.test.cpp
    title: test/yukicoder/1400.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/shortest_path/bfs_bitset.hpp\"\n\n// \u5BC6\u30B0\u30E9\
    \u30D5\u306E\u91CD\u307F\u306A\u3057\u6700\u77ED\u8DEF\u554F\u984C\n// 01 \u884C\
    \u5217\u3092 vc<bitset> \u306E\u5F62\u3067\u6E21\u3059\n// O(N^2/w)\n// \u53C2\
    \u8003\uFF1A(4000,4000) \u3092 4000 \u56DE\u3067 2 \u79D2\u4EE5\u5185\uFF1F\n\
    template <typename BITSET>\nvc<int> bfs_bitset(vc<BITSET>& G, int s) {\n  int\
    \ N = len(G);\n  vc<int> dist(N, -1);\n  BITSET unused;\n  FOR(v, N) unused[v]\
    \ = 1;\n  BITSET que;\n  que[s] = 1;\n\n  int d = 0;\n  while (1) {\n    int p\
    \ = que._Find_first();\n    if (p >= N) break;\n    BITSET nxt;\n    while (p\
    \ < N) {\n      dist[p] = d;\n      unused[p] = 0;\n      nxt |= G[p];\n     \
    \ p = que._Find_next(p);\n    }\n    que = nxt & unused;\n    ++d;\n  }\n  return\
    \ dist;\n}\n"
  code: "\n// \u5BC6\u30B0\u30E9\u30D5\u306E\u91CD\u307F\u306A\u3057\u6700\u77ED\u8DEF\
    \u554F\u984C\n// 01 \u884C\u5217\u3092 vc<bitset> \u306E\u5F62\u3067\u6E21\u3059\
    \n// O(N^2/w)\n// \u53C2\u8003\uFF1A(4000,4000) \u3092 4000 \u56DE\u3067 2 \u79D2\
    \u4EE5\u5185\uFF1F\ntemplate <typename BITSET>\nvc<int> bfs_bitset(vc<BITSET>&\
    \ G, int s) {\n  int N = len(G);\n  vc<int> dist(N, -1);\n  BITSET unused;\n \
    \ FOR(v, N) unused[v] = 1;\n  BITSET que;\n  que[s] = 1;\n\n  int d = 0;\n  while\
    \ (1) {\n    int p = que._Find_first();\n    if (p >= N) break;\n    BITSET nxt;\n\
    \    while (p < N) {\n      dist[p] = d;\n      unused[p] = 0;\n      nxt |= G[p];\n\
    \      p = que._Find_next(p);\n    }\n    que = nxt & unused;\n    ++d;\n  }\n\
    \  return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/bfs_bitset.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1400.test.cpp
documentation_of: graph/shortest_path/bfs_bitset.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/bfs_bitset.hpp
- /library/graph/shortest_path/bfs_bitset.hpp.html
title: graph/shortest_path/bfs_bitset.hpp
---
