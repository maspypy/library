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
    - https://codeforces.com/contest/863/submission/194294053
  bundledCode: "#line 1 \"graph/grid_hamiltonian_path.hpp\"\n// \u59CB\u70B9\u3092\
    \u56FA\u5B9A\u3057\u3066\u3001\u30CF\u30DF\u30EB\u30C8\u30F3\u30D1\u30B9\u3092\
    \u4F5C\u308B\u3002\u5076\u6570\u306A\u3089\u30B5\u30A4\u30AF\u30EB\u306B\u3059\
    \u308B\u3002\n// \u9AD8\u6B21\u5143\u7248\uFF1Ahttps://codeforces.com/contest/863/submission/194294053\n\
    vc<pair<int, int>> grid_hamiltonian_path(int H, int W, int sx = 0, int sy = 0)\
    \ {\n  using P = pair<int, int>;\n  if (H == 1) {\n    vc<P> path;\n    if (sy\
    \ == 0) {\n      FOR(y, W) path.eb(0, y);\n      return path;\n    }\n    if (sy\
    \ == W - 1) {\n      FOR_R(y, W) path.eb(0, y);\n      return path;\n    }\n \
    \   return {};\n  }\n  if (W == 1) {\n    vc<P> path;\n    if (sx == 0) {\n  \
    \    FOR(x, H) path.eb(x, 0);\n      return path;\n    }\n    if (sx == H - 1)\
    \ {\n      FOR_R(x, H) path.eb(x, 0);\n      return path;\n    }\n    return {};\n\
    \  }\n  if (H % 2 == 0 && W % 2 == 1) {\n    vc<P> path = grid_hamiltonian_path(W,\
    \ H, sy, sx);\n    for (auto&& x: path) swap(x.fi, x.se);\n    return path;\n\
    \  }\n  if (W % 2 == 0) {\n    vc<P> path;\n    path.reserve(H * W);\n    FOR(j,\
    \ W) path.eb(0, j);\n    FOR_R(j, W) {\n      if (j % 2 == 1) FOR(i, 1, H) path.eb(i,\
    \ j);\n      if (j % 2 == 0) FOR_R(i, 1, H) path.eb(i, j);\n    }\n    int idx\
    \ = -1;\n    FOR(i, len(path)) if (path[i].fi == sx && path[i].se == sy) idx =\
    \ i;\n    rotate(path.begin(), path.begin() + idx, path.end());\n    return path;\n\
    \  }\n\n  assert(H * W % 2 == 1);\n  if ((sx + sy) % 2 == 1) return {};\n  if\
    \ (sx % 2 == 1) {\n    vc<P> path;\n    path.reserve(H * W);\n    FOR_R(i, sx\
    \ + 1) {\n      if (i % 2 == 1) FOR_R(j, sy + 1) path.eb(i, j);\n      if (i %\
    \ 2 == 0) FOR(j, sy + 1) path.eb(i, j);\n    }\n    FOR(j, sy + 1, W) {\n    \
    \  if (j % 2 == 0) FOR(i, sx + 1) path.eb(i, j);\n      if (j % 2 == 1) FOR_R(i,\
    \ sx + 1) path.eb(i, j);\n    }\n    FOR_R(j, W) {\n      if (j % 2 == 0) FOR(i,\
    \ sx + 1, H) path.eb(i, j);\n      if (j % 2 == 1) FOR_R(i, sx + 1, H) path.eb(i,\
    \ j);\n    }\n    return path;\n  }\n  if (sx == H - 1) {\n    vc<P> path = grid_hamiltonian_path(H,\
    \ W, 0, sy);\n    for (auto&& x: path) x.fi = H - 1 - x.fi;\n    return path;\n\
    \  }\n  if (sy == W - 1) {\n    vc<P> path = grid_hamiltonian_path(H, W, sx, 0);\n\
    \    for (auto&& x: path) x.se = W - 1 - x.se;\n    return path;\n  }\n  if (sx\
    \ != 0 && sy == 0) {\n    vc<P> path = grid_hamiltonian_path(W, H, sy, sx);\n\
    \    for (auto&& x: path) swap(x.fi, x.se);\n    return path;\n  }\n  vc<P> path;\n\
    \  path.reserve(H * W);\n  if (sx == 0) {\n    FOR_R(j, sy + 1) {\n      if (j\
    \ % 2 == 0) FOR(i, H - 1) path.eb(i, j);\n      if (j % 2 == 1) FOR_R(i, H - 1)\
    \ path.eb(i, j);\n    }\n    FOR(j, W) path.eb(H - 1, j);\n    FOR_R(j, sy + 1,\
    \ W) {\n      if (j % 2 == 0) FOR_R(i, H - 1) path.eb(i, j);\n      if (j % 2\
    \ == 1) FOR(i, H - 1) path.eb(i, j);\n    }\n    return path;\n  }\n  assert(0\
    \ < sx && sx < H - 1 && 0 < sy && sy < W - 1);\n  FOR_R(j, sy + 1) path.eb(sx,\
    \ j);\n  FOR(j, sy + 1) {\n    if (j % 2 == 0) FOR_R(i, sx) path.eb(i, j);\n \
    \   if (j % 2 == 1) FOR(i, sx) path.eb(i, j);\n  }\n  FOR(i, sx + 1) {\n    if\
    \ (i % 2 == 0) FOR(j, sy + 1, W) path.eb(i, j);\n    if (i % 2 == 1) FOR_R(j,\
    \ sy + 1, W) path.eb(i, j);\n  }\n  FOR_R(j, W) {\n    if (j % 2 == 0) FOR(i,\
    \ sx + 1, H) path.eb(i, j);\n    if (j % 2 == 1) FOR_R(i, sx + 1, H) path.eb(i,\
    \ j);\n  }\n  return path;\n}\n"
  code: "// \u59CB\u70B9\u3092\u56FA\u5B9A\u3057\u3066\u3001\u30CF\u30DF\u30EB\u30C8\
    \u30F3\u30D1\u30B9\u3092\u4F5C\u308B\u3002\u5076\u6570\u306A\u3089\u30B5\u30A4\
    \u30AF\u30EB\u306B\u3059\u308B\u3002\n// \u9AD8\u6B21\u5143\u7248\uFF1Ahttps://codeforces.com/contest/863/submission/194294053\n\
    vc<pair<int, int>> grid_hamiltonian_path(int H, int W, int sx = 0, int sy = 0)\
    \ {\n  using P = pair<int, int>;\n  if (H == 1) {\n    vc<P> path;\n    if (sy\
    \ == 0) {\n      FOR(y, W) path.eb(0, y);\n      return path;\n    }\n    if (sy\
    \ == W - 1) {\n      FOR_R(y, W) path.eb(0, y);\n      return path;\n    }\n \
    \   return {};\n  }\n  if (W == 1) {\n    vc<P> path;\n    if (sx == 0) {\n  \
    \    FOR(x, H) path.eb(x, 0);\n      return path;\n    }\n    if (sx == H - 1)\
    \ {\n      FOR_R(x, H) path.eb(x, 0);\n      return path;\n    }\n    return {};\n\
    \  }\n  if (H % 2 == 0 && W % 2 == 1) {\n    vc<P> path = grid_hamiltonian_path(W,\
    \ H, sy, sx);\n    for (auto&& x: path) swap(x.fi, x.se);\n    return path;\n\
    \  }\n  if (W % 2 == 0) {\n    vc<P> path;\n    path.reserve(H * W);\n    FOR(j,\
    \ W) path.eb(0, j);\n    FOR_R(j, W) {\n      if (j % 2 == 1) FOR(i, 1, H) path.eb(i,\
    \ j);\n      if (j % 2 == 0) FOR_R(i, 1, H) path.eb(i, j);\n    }\n    int idx\
    \ = -1;\n    FOR(i, len(path)) if (path[i].fi == sx && path[i].se == sy) idx =\
    \ i;\n    rotate(path.begin(), path.begin() + idx, path.end());\n    return path;\n\
    \  }\n\n  assert(H * W % 2 == 1);\n  if ((sx + sy) % 2 == 1) return {};\n  if\
    \ (sx % 2 == 1) {\n    vc<P> path;\n    path.reserve(H * W);\n    FOR_R(i, sx\
    \ + 1) {\n      if (i % 2 == 1) FOR_R(j, sy + 1) path.eb(i, j);\n      if (i %\
    \ 2 == 0) FOR(j, sy + 1) path.eb(i, j);\n    }\n    FOR(j, sy + 1, W) {\n    \
    \  if (j % 2 == 0) FOR(i, sx + 1) path.eb(i, j);\n      if (j % 2 == 1) FOR_R(i,\
    \ sx + 1) path.eb(i, j);\n    }\n    FOR_R(j, W) {\n      if (j % 2 == 0) FOR(i,\
    \ sx + 1, H) path.eb(i, j);\n      if (j % 2 == 1) FOR_R(i, sx + 1, H) path.eb(i,\
    \ j);\n    }\n    return path;\n  }\n  if (sx == H - 1) {\n    vc<P> path = grid_hamiltonian_path(H,\
    \ W, 0, sy);\n    for (auto&& x: path) x.fi = H - 1 - x.fi;\n    return path;\n\
    \  }\n  if (sy == W - 1) {\n    vc<P> path = grid_hamiltonian_path(H, W, sx, 0);\n\
    \    for (auto&& x: path) x.se = W - 1 - x.se;\n    return path;\n  }\n  if (sx\
    \ != 0 && sy == 0) {\n    vc<P> path = grid_hamiltonian_path(W, H, sy, sx);\n\
    \    for (auto&& x: path) swap(x.fi, x.se);\n    return path;\n  }\n  vc<P> path;\n\
    \  path.reserve(H * W);\n  if (sx == 0) {\n    FOR_R(j, sy + 1) {\n      if (j\
    \ % 2 == 0) FOR(i, H - 1) path.eb(i, j);\n      if (j % 2 == 1) FOR_R(i, H - 1)\
    \ path.eb(i, j);\n    }\n    FOR(j, W) path.eb(H - 1, j);\n    FOR_R(j, sy + 1,\
    \ W) {\n      if (j % 2 == 0) FOR_R(i, H - 1) path.eb(i, j);\n      if (j % 2\
    \ == 1) FOR(i, H - 1) path.eb(i, j);\n    }\n    return path;\n  }\n  assert(0\
    \ < sx && sx < H - 1 && 0 < sy && sy < W - 1);\n  FOR_R(j, sy + 1) path.eb(sx,\
    \ j);\n  FOR(j, sy + 1) {\n    if (j % 2 == 0) FOR_R(i, sx) path.eb(i, j);\n \
    \   if (j % 2 == 1) FOR(i, sx) path.eb(i, j);\n  }\n  FOR(i, sx + 1) {\n    if\
    \ (i % 2 == 0) FOR(j, sy + 1, W) path.eb(i, j);\n    if (i % 2 == 1) FOR_R(j,\
    \ sy + 1, W) path.eb(i, j);\n  }\n  FOR_R(j, W) {\n    if (j % 2 == 0) FOR(i,\
    \ sx + 1, H) path.eb(i, j);\n    if (j % 2 == 1) FOR_R(i, sx + 1, H) path.eb(i,\
    \ j);\n  }\n  return path;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/grid_hamiltonian_path.hpp
  requiredBy: []
  timestamp: '2023-02-28 19:12:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/grid_hamiltonian_path.hpp
layout: document
redirect_from:
- /library/graph/grid_hamiltonian_path.hpp
- /library/graph/grid_hamiltonian_path.hpp.html
title: graph/grid_hamiltonian_path.hpp
---
