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
  bundledCode: "#line 1 \"graph/implicit_graph/bfs.hpp\"\n// \u8FBA\u91CD\u307F\u306F\
    \u3059\u3079\u3066 1 \u3067\u3042\u308B\n// [dist, par]\ntemplate <typename F1,\
    \ typename F2>\npair<vc<int>, vc<int>> implicit_graph_bfs(int N, int s, F1 set_used,\n\
    \                                          F2 find_unused) {\n  vc<int> que(N);\n\
    \  vc<int> dist(N, infty<int>);\n  vc<int> par(N, -1);\n  int l = 0, r = 0;\n\
    \  dist[s] = 0, set_used(s), que[r++] = s;\n  while (l < r) {\n    int v = que[l++];\n\
    \    while (1) {\n      int to = find_unused(v);\n      if (to == -1) break;\n\
    \      dist[to] = dist[v] + 1, par[to] = v, set_used(to), que[r++] = to;\n   \
    \ }\n  }\n  return {dist, par};\n}\n"
  code: "// \u8FBA\u91CD\u307F\u306F\u3059\u3079\u3066 1 \u3067\u3042\u308B\n// [dist,\
    \ par]\ntemplate <typename F1, typename F2>\npair<vc<int>, vc<int>> implicit_graph_bfs(int\
    \ N, int s, F1 set_used,\n                                          F2 find_unused)\
    \ {\n  vc<int> que(N);\n  vc<int> dist(N, infty<int>);\n  vc<int> par(N, -1);\n\
    \  int l = 0, r = 0;\n  dist[s] = 0, set_used(s), que[r++] = s;\n  while (l <\
    \ r) {\n    int v = que[l++];\n    while (1) {\n      int to = find_unused(v);\n\
    \      if (to == -1) break;\n      dist[to] = dist[v] + 1, par[to] = v, set_used(to),\
    \ que[r++] = to;\n    }\n  }\n  return {dist, par};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/implicit_graph/bfs.hpp
  requiredBy: []
  timestamp: '2023-07-03 10:15:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/implicit_graph/bfs.hpp
layout: document
redirect_from:
- /library/graph/implicit_graph/bfs.hpp
- /library/graph/implicit_graph/bfs.hpp.html
title: graph/implicit_graph/bfs.hpp
---
