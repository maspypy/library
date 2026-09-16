---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: ds/unionfind/unionfind.hpp
    title: ds/unionfind/unionfind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/1864/problem/I
  bundledCode: "#line 1 \"ds/unionfind/unionfind.hpp\"\n\nstruct UnionFind {\n  int\
    \ n, n_comp;\n  vc<int> dat; // par or (-size)\n  UnionFind(int n = 0) { build(n);\
    \ }\n\n  void build(int m) {\n    n = m, n_comp = m;\n    dat.assign(n, -1);\n\
    \  }\n\n  void reset() { build(n); }\n\n  int operator[](int x) {\n    while (dat[x]\
    \ >= 0) {\n      int pp = dat[dat[x]];\n      if (pp < 0) { return dat[x]; }\n\
    \      x = dat[x] = pp;\n    }\n    return x;\n  }\n\n  ll size(int x) {\n   \
    \ x = (*this)[x];\n    return -dat[x];\n  }\n\n  bool merge(int x, int y) {\n\
    \    x = (*this)[x], y = (*this)[y];\n    if (x == y) return false;\n    if (-dat[x]\
    \ < -dat[y]) swap(x, y);\n    dat[x] += dat[y], dat[y] = x, n_comp--;\n    return\
    \ true;\n  }\n\n  vc<int> get_all() {\n    vc<int> A(n);\n    FOR(i, n) A[i] =\
    \ (*this)[i];\n    return A;\n  }\n};\n#line 2 \"graph/ds/grid_decremental_connectivity.hpp\"\
    \n\n// https://codeforces.com/contest/1864/problem/I\n// \u8FBA\u306E\u524A\u9664\
    \ / \u30DE\u30B9\u306E 4 \u8FD1\u508D\u306B\u95A2\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u60C5\u5831\nstruct Grid_Decremental_Connectivity {\n  int H, W, n_comp;\n\
    \  vvc<int> A;  // \u3053\u3053\u306B\u9023\u7D50\u6210\u5206\u756A\u53F7\u3092\
    \u5165\u308C\u308B\n  vc<int> sz;\n  int dx[4] = {1, 0, -1, 0};\n  int dy[4] =\
    \ {0, 1, 0, -1};\n\n  // \u524A\u9664\u6E08\u3067\u3059\u304B\uFF1F\n  vvc<bool>\
    \ TATE;\n  vvc<bool> YOKO;\n\n  UnionFind dual_uf;\n  int bfs_time = 0;\n  vvc<int>\
    \ vis;\n\n  Grid_Decremental_Connectivity(int H, int W) : H(H), W(W), n_comp(1)\
    \ {\n    A = vvc<int>(H, vc<int>(W, 0));\n    vis = vvc<int>(H, vc<int>(W, 0));\n\
    \    TATE = vvc<bool>(H, vc<bool>(W + 1, false));\n    YOKO = vvc<bool>(H + 1,\
    \ vc<bool>(W, false));\n    dual_uf.build((H + 1) * (W + 1));\n    sz.eb(H * W);\n\
    \    // cut grid border\n    FOR(x, H) {\n      dual_uf.merge(dual_idx(x, 0),\
    \ dual_idx(x + 1, 0));\n      dual_uf.merge(dual_idx(x, W), dual_idx(x + 1, W));\n\
    \      TATE[x][0] = TATE[x][W] = true;\n    }\n    FOR(y, W) {\n      dual_uf.merge(dual_idx(0,\
    \ y), dual_idx(0, y + 1));\n      dual_uf.merge(dual_idx(H, y), dual_idx(H, y\
    \ + 1));\n      YOKO[0][y] = YOKO[H][y] = true;\n    }\n  }\n\n  int dual_idx(int\
    \ x, int y) const { return (W + 1) * x + y; }\n  int get(int x, int y) const {\
    \ return A[x][y]; }\n  bool isin(int x, int y) const { return 0 <= x && x < H\
    \ && 0 <= y && y < W; }\n\n  bool can_go(int x1, int y1, int x2, int y2) {\n \
    \   if (!isin(x1, y1) || !isin(x2, y2)) return false;\n    if (x1 + y1 > x2 +\
    \ y2) swap(x1, x2), swap(y1, y2);\n    if (x1 == x2 && y2 == y1 + 1) {\n     \
    \ return !TATE[x1][y1 + 1];\n    }\n    elif (y1 == y2 && x2 == x1 + 1) { return\
    \ !YOKO[x1 + 1][y1]; }\n    assert(false);\n    return false;\n  }\n\n  void cut(int\
    \ x1, int y1, int x2, int y2) {\n    assert(isin(x1, y1) && isin(x2, y2) && A[x1][y1]\
    \ == A[x2][y2]);\n    if (x1 + y1 > x2 + y2) swap(x1, x2), swap(y1, y2);\n   \
    \ int a1, b1, a2, b2;\n    if (x1 == x2 && y2 == y1 + 1) {\n      a1 = x1, b1\
    \ = y1 + 1, a2 = x1 + 1, b2 = y1 + 1;\n      assert(!TATE[a1][b1]);\n      TATE[a1][b1]\
    \ = true;\n    }\n    elif (y1 == y2 && x2 == x1 + 1) {\n      a1 = x1 + 1, b1\
    \ = y1, a2 = x1 + 1, b2 = y1 + 1;\n      assert(!YOKO[a1][b1]);\n      YOKO[a1][b1]\
    \ = true;\n    }\n    else {\n      assert(false);\n    }\n    if (dual_uf.merge(dual_idx(a1,\
    \ b1), dual_idx(a2, b2))) {\n      // keep connectivity\n      return;\n    }\n\
    \n    // parallel bfs\n    bfs_time++;\n    vc<pair<int, int>> Q1, Q2;\n    Q1.eb(x1,\
    \ y1), Q2.eb(x2, y2);\n    vis[x1][y1] = vis[x2][y2] = bfs_time;\n    int p1 =\
    \ 0, p2 = 0;\n    while (1) {\n      if (p1 == len(Q1)) {\n        p2 = infty<int>;\n\
    \        break;\n      }\n      if (p2 == len(Q2)) {\n        p1 = infty<int>;\n\
    \        break;\n      }\n      FOR(2) {\n        swap(p1, p2), swap(Q1, Q2);\n\
    \        auto [x, y] = Q1[p1++];\n        FOR(d, 4) {\n          int xx = x +\
    \ dx[d], yy = y + dy[d];\n          if (isin(xx, yy) && vis[xx][yy] < bfs_time\
    \ && can_go(x, y, xx, yy)) {\n            assert(A[x][y] == A[xx][yy]);\n    \
    \        vis[xx][yy] = bfs_time;\n            Q1.eb(xx, yy);\n          }\n  \
    \      }\n      }\n    }\n    if (p1 == infty<int>) {\n      swap(p1, p2), swap(Q1,\
    \ Q2), swap(x1, x2), swap(y1, y2);\n    }\n    assert(p2 == infty<int>);\n   \
    \ // Q1 to new component\n    int now = A[x1][y1];\n    sz[now] -= len(Q1);\n\
    \    for (auto& [x, y] : Q1) {\n      A[x][y] = len(sz);\n    }\n    sz.eb(len(Q1));\n\
    \    n_comp++;\n  }\n};\n"
  code: "#include \"ds/unionfind/unionfind.hpp\"\n\n// https://codeforces.com/contest/1864/problem/I\n\
    // \u8FBA\u306E\u524A\u9664 / \u30DE\u30B9\u306E 4 \u8FD1\u508D\u306B\u95A2\u3059\
    \u308B\u9023\u7D50\u6210\u5206\u60C5\u5831\nstruct Grid_Decremental_Connectivity\
    \ {\n  int H, W, n_comp;\n  vvc<int> A;  // \u3053\u3053\u306B\u9023\u7D50\u6210\
    \u5206\u756A\u53F7\u3092\u5165\u308C\u308B\n  vc<int> sz;\n  int dx[4] = {1, 0,\
    \ -1, 0};\n  int dy[4] = {0, 1, 0, -1};\n\n  // \u524A\u9664\u6E08\u3067\u3059\
    \u304B\uFF1F\n  vvc<bool> TATE;\n  vvc<bool> YOKO;\n\n  UnionFind dual_uf;\n \
    \ int bfs_time = 0;\n  vvc<int> vis;\n\n  Grid_Decremental_Connectivity(int H,\
    \ int W) : H(H), W(W), n_comp(1) {\n    A = vvc<int>(H, vc<int>(W, 0));\n    vis\
    \ = vvc<int>(H, vc<int>(W, 0));\n    TATE = vvc<bool>(H, vc<bool>(W + 1, false));\n\
    \    YOKO = vvc<bool>(H + 1, vc<bool>(W, false));\n    dual_uf.build((H + 1) *\
    \ (W + 1));\n    sz.eb(H * W);\n    // cut grid border\n    FOR(x, H) {\n    \
    \  dual_uf.merge(dual_idx(x, 0), dual_idx(x + 1, 0));\n      dual_uf.merge(dual_idx(x,\
    \ W), dual_idx(x + 1, W));\n      TATE[x][0] = TATE[x][W] = true;\n    }\n   \
    \ FOR(y, W) {\n      dual_uf.merge(dual_idx(0, y), dual_idx(0, y + 1));\n    \
    \  dual_uf.merge(dual_idx(H, y), dual_idx(H, y + 1));\n      YOKO[0][y] = YOKO[H][y]\
    \ = true;\n    }\n  }\n\n  int dual_idx(int x, int y) const { return (W + 1) *\
    \ x + y; }\n  int get(int x, int y) const { return A[x][y]; }\n  bool isin(int\
    \ x, int y) const { return 0 <= x && x < H && 0 <= y && y < W; }\n\n  bool can_go(int\
    \ x1, int y1, int x2, int y2) {\n    if (!isin(x1, y1) || !isin(x2, y2)) return\
    \ false;\n    if (x1 + y1 > x2 + y2) swap(x1, x2), swap(y1, y2);\n    if (x1 ==\
    \ x2 && y2 == y1 + 1) {\n      return !TATE[x1][y1 + 1];\n    }\n    elif (y1\
    \ == y2 && x2 == x1 + 1) { return !YOKO[x1 + 1][y1]; }\n    assert(false);\n \
    \   return false;\n  }\n\n  void cut(int x1, int y1, int x2, int y2) {\n    assert(isin(x1,\
    \ y1) && isin(x2, y2) && A[x1][y1] == A[x2][y2]);\n    if (x1 + y1 > x2 + y2)\
    \ swap(x1, x2), swap(y1, y2);\n    int a1, b1, a2, b2;\n    if (x1 == x2 && y2\
    \ == y1 + 1) {\n      a1 = x1, b1 = y1 + 1, a2 = x1 + 1, b2 = y1 + 1;\n      assert(!TATE[a1][b1]);\n\
    \      TATE[a1][b1] = true;\n    }\n    elif (y1 == y2 && x2 == x1 + 1) {\n  \
    \    a1 = x1 + 1, b1 = y1, a2 = x1 + 1, b2 = y1 + 1;\n      assert(!YOKO[a1][b1]);\n\
    \      YOKO[a1][b1] = true;\n    }\n    else {\n      assert(false);\n    }\n\
    \    if (dual_uf.merge(dual_idx(a1, b1), dual_idx(a2, b2))) {\n      // keep connectivity\n\
    \      return;\n    }\n\n    // parallel bfs\n    bfs_time++;\n    vc<pair<int,\
    \ int>> Q1, Q2;\n    Q1.eb(x1, y1), Q2.eb(x2, y2);\n    vis[x1][y1] = vis[x2][y2]\
    \ = bfs_time;\n    int p1 = 0, p2 = 0;\n    while (1) {\n      if (p1 == len(Q1))\
    \ {\n        p2 = infty<int>;\n        break;\n      }\n      if (p2 == len(Q2))\
    \ {\n        p1 = infty<int>;\n        break;\n      }\n      FOR(2) {\n     \
    \   swap(p1, p2), swap(Q1, Q2);\n        auto [x, y] = Q1[p1++];\n        FOR(d,\
    \ 4) {\n          int xx = x + dx[d], yy = y + dy[d];\n          if (isin(xx,\
    \ yy) && vis[xx][yy] < bfs_time && can_go(x, y, xx, yy)) {\n            assert(A[x][y]\
    \ == A[xx][yy]);\n            vis[xx][yy] = bfs_time;\n            Q1.eb(xx, yy);\n\
    \          }\n        }\n      }\n    }\n    if (p1 == infty<int>) {\n      swap(p1,\
    \ p2), swap(Q1, Q2), swap(x1, x2), swap(y1, y2);\n    }\n    assert(p2 == infty<int>);\n\
    \    // Q1 to new component\n    int now = A[x1][y1];\n    sz[now] -= len(Q1);\n\
    \    for (auto& [x, y] : Q1) {\n      A[x][y] = len(sz);\n    }\n    sz.eb(len(Q1));\n\
    \    n_comp++;\n  }\n};\n"
  dependsOn:
  - ds/unionfind/unionfind.hpp
  isVerificationFile: false
  path: graph/ds/grid_decremental_connectivity.hpp
  requiredBy: []
  timestamp: '2026-08-16 04:03:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/ds/grid_decremental_connectivity.hpp
layout: document
redirect_from:
- /library/graph/ds/grid_decremental_connectivity.hpp
- /library/graph/ds/grid_decremental_connectivity.hpp.html
title: graph/ds/grid_decremental_connectivity.hpp
---
