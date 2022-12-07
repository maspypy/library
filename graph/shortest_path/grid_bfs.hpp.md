---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1323.test.cpp
    title: test/yukicoder/1323.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/shortest_path/grid_bfs.hpp\"\n\n// walls = \"#\" \u3084\
    \u3001walls = {-1} \u306A\u3069\u3002\ntemplate <typename STRING>\nvc<vc<int>>\
    \ grid_bfs(vc<STRING>& G, int sx, int sy, STRING walls, int INF,\n           \
    \          int dmax = 4) {\n  int H = len(G);\n  int W = len(G[0]);\n  assert(H\
    \ * W < INF);\n  auto isin = [&](int x, int y) -> bool {\n    if (x < 0 || H <=\
    \ x) return false;\n    if (y < 0 || W <= y) return false;\n    return count(all(walls),\
    \ G[x][y]) == 0;\n  };\n  int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};\n  int dy[]\
    \ = {0, 1, 0, -1, 1, 1, -1, -1};\n\n  vv(int, dist, H, W, INF);\n  deque<pair<int,\
    \ int>> que;\n  auto add = [&](int x, int y, int d) -> void {\n    if (!isin(x,\
    \ y)) return;\n    if (chmin(dist[x][y], d)) que.eb(x, y);\n  };\n  add(sx, sy,\
    \ 0);\n\n  while (!que.empty()) {\n    auto [x, y] = que.front();\n    que.pop_front();\n\
    \    FOR(d, dmax) {\n      int nx = x + dx[d], ny = y + dy[d];\n      add(nx,\
    \ ny, dist[x][y] + 1);\n    }\n  }\n  return dist;\n}\n"
  code: "#pragma once\n\n// walls = \"#\" \u3084\u3001walls = {-1} \u306A\u3069\u3002\
    \ntemplate <typename STRING>\nvc<vc<int>> grid_bfs(vc<STRING>& G, int sx, int\
    \ sy, STRING walls, int INF,\n                     int dmax = 4) {\n  int H =\
    \ len(G);\n  int W = len(G[0]);\n  assert(H * W < INF);\n  auto isin = [&](int\
    \ x, int y) -> bool {\n    if (x < 0 || H <= x) return false;\n    if (y < 0 ||\
    \ W <= y) return false;\n    return count(all(walls), G[x][y]) == 0;\n  };\n \
    \ int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};\n  int dy[] = {0, 1, 0, -1, 1, 1, -1,\
    \ -1};\n\n  vv(int, dist, H, W, INF);\n  deque<pair<int, int>> que;\n  auto add\
    \ = [&](int x, int y, int d) -> void {\n    if (!isin(x, y)) return;\n    if (chmin(dist[x][y],\
    \ d)) que.eb(x, y);\n  };\n  add(sx, sy, 0);\n\n  while (!que.empty()) {\n   \
    \ auto [x, y] = que.front();\n    que.pop_front();\n    FOR(d, dmax) {\n     \
    \ int nx = x + dx[d], ny = y + dy[d];\n      add(nx, ny, dist[x][y] + 1);\n  \
    \  }\n  }\n  return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/shortest_path/grid_bfs.hpp
  requiredBy: []
  timestamp: '2022-10-21 17:08:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1323.test.cpp
documentation_of: graph/shortest_path/grid_bfs.hpp
layout: document
redirect_from:
- /library/graph/shortest_path/grid_bfs.hpp
- /library/graph/shortest_path/grid_bfs.hpp.html
title: graph/shortest_path/grid_bfs.hpp
---
