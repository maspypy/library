---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1045/problem/A
    - https://codeforces.com/contest/786/problem/E
    - https://qoj.ac/problem/6308
  bundledCode: "#line 1 \"flow/bipartite_dense.hpp\"\n\n// vc<bitset> \u3067 biadj\
    \ matrix \u3092\u6E21\u3059\n// N^3/w. (5000,5000) \u3067 300ms \u7A0B\u5EA6\u3067\
    \u52D5\u304F\u5834\u5408\u304C\u3042\u308B\n// https://qoj.ac/problem/6308\n//\
    \ (10000?, 5000) 655ms\n// https://codeforces.com/contest/1045/problem/A\n// (10000,\
    \ 20000) \u3067 3837ms\n// https://codeforces.com/contest/786/problem/E\ntemplate\
    \ <typename BS>\nstruct BipartiteMatching_Dense {\n  int N1, N2;\n  vc<BS>& adj;\n\
    \  vc<int> match_1, match_2;\n  vc<int> que;\n  vc<int> prev;\n  BS vis;\n\n \
    \ BipartiteMatching_Dense(vc<BS>& adj, int N1, int N2)\n      : N1(N1), N2(N2),\
    \ adj(adj), match_1(N1, -1), match_2(N2, -1) {\n    FOR(s, N1) bfs(s);\n  }\n\n\
    \  void bfs(int s) {\n    if (match_1[s] != -1) return;\n    que.resize(N1), prev.resize(N1);\n\
    \    int l = 0, r = 0;\n    vis.set(), prev[s] = -1;\n\n    que[r++] = s;\n  \
    \  while (l < r) {\n      int u = que[l++];\n      BS cand = vis & adj[u];\n \
    \     for (int v = cand._Find_first(); v < N2; v = cand._Find_next(v)) {\n   \
    \     vis[v] = 0;\n        if (match_2[v] != -1) {\n          que[r++] = match_2[v];\n\
    \          prev[match_2[v]] = u;\n          continue;\n        }\n        int\
    \ a = u, b = v;\n        while (a != -1) {\n          int t = match_1[a];\n  \
    \        match_1[a] = b, match_2[b] = a, a = prev[a], b = t;\n        }\n    \
    \    return;\n      }\n    }\n    return;\n  }\n\n  vc<pair<int, int>> matching()\
    \ {\n    vc<pair<int, int>> res;\n    FOR(v, N1) if (match_1[v] != -1) res.eb(v,\
    \ match_1[v]);\n    return res;\n  }\n\n  pair<vc<int>, vc<int>> vertex_cover()\
    \ {\n    vc<int> que(N1);\n    int l = 0, r = 0;\n    vis.set();\n    vc<bool>\
    \ done(N1);\n    FOR(i, N1) {\n      if (match_1[i] == -1) done[i] = 1, que[r++]\
    \ = i;\n    }\n    while (l < r) {\n      int a = que[l++];\n      BS cand = adj[a]\
    \ & vis;\n      for (int b = cand._Find_first(); b < N2; b = cand._Find_next(b))\
    \ {\n        vis[b] = 0;\n        int to = match_2[b];\n        assert(to != -1);\n\
    \        if (!done[to]) done[to] = 1, que[r++] = to;\n      }\n    }\n    vc<int>\
    \ left, right;\n    FOR(i, N1) if (!done[i]) left.eb(i);\n    FOR(i, N2) if (!vis[i])\
    \ right.eb(i);\n    return {left, right};\n  }\n};\n"
  code: "\n// vc<bitset> \u3067 biadj matrix \u3092\u6E21\u3059\n// N^3/w. (5000,5000)\
    \ \u3067 300ms \u7A0B\u5EA6\u3067\u52D5\u304F\u5834\u5408\u304C\u3042\u308B\n\
    // https://qoj.ac/problem/6308\n// (10000?, 5000) 655ms\n// https://codeforces.com/contest/1045/problem/A\n\
    // (10000, 20000) \u3067 3837ms\n// https://codeforces.com/contest/786/problem/E\n\
    template <typename BS>\nstruct BipartiteMatching_Dense {\n  int N1, N2;\n  vc<BS>&\
    \ adj;\n  vc<int> match_1, match_2;\n  vc<int> que;\n  vc<int> prev;\n  BS vis;\n\
    \n  BipartiteMatching_Dense(vc<BS>& adj, int N1, int N2)\n      : N1(N1), N2(N2),\
    \ adj(adj), match_1(N1, -1), match_2(N2, -1) {\n    FOR(s, N1) bfs(s);\n  }\n\n\
    \  void bfs(int s) {\n    if (match_1[s] != -1) return;\n    que.resize(N1), prev.resize(N1);\n\
    \    int l = 0, r = 0;\n    vis.set(), prev[s] = -1;\n\n    que[r++] = s;\n  \
    \  while (l < r) {\n      int u = que[l++];\n      BS cand = vis & adj[u];\n \
    \     for (int v = cand._Find_first(); v < N2; v = cand._Find_next(v)) {\n   \
    \     vis[v] = 0;\n        if (match_2[v] != -1) {\n          que[r++] = match_2[v];\n\
    \          prev[match_2[v]] = u;\n          continue;\n        }\n        int\
    \ a = u, b = v;\n        while (a != -1) {\n          int t = match_1[a];\n  \
    \        match_1[a] = b, match_2[b] = a, a = prev[a], b = t;\n        }\n    \
    \    return;\n      }\n    }\n    return;\n  }\n\n  vc<pair<int, int>> matching()\
    \ {\n    vc<pair<int, int>> res;\n    FOR(v, N1) if (match_1[v] != -1) res.eb(v,\
    \ match_1[v]);\n    return res;\n  }\n\n  pair<vc<int>, vc<int>> vertex_cover()\
    \ {\n    vc<int> que(N1);\n    int l = 0, r = 0;\n    vis.set();\n    vc<bool>\
    \ done(N1);\n    FOR(i, N1) {\n      if (match_1[i] == -1) done[i] = 1, que[r++]\
    \ = i;\n    }\n    while (l < r) {\n      int a = que[l++];\n      BS cand = adj[a]\
    \ & vis;\n      for (int b = cand._Find_first(); b < N2; b = cand._Find_next(b))\
    \ {\n        vis[b] = 0;\n        int to = match_2[b];\n        assert(to != -1);\n\
    \        if (!done[to]) done[to] = 1, que[r++] = to;\n      }\n    }\n    vc<int>\
    \ left, right;\n    FOR(i, N1) if (!done[i]) left.eb(i);\n    FOR(i, N2) if (!vis[i])\
    \ right.eb(i);\n    return {left, right};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: flow/bipartite_dense.hpp
  requiredBy: []
  timestamp: '2023-10-14 01:43:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/bipartite_dense.hpp
layout: document
redirect_from:
- /library/flow/bipartite_dense.hpp
- /library/flow/bipartite_dense.hpp.html
title: flow/bipartite_dense.hpp
---
