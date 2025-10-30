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
    - https://codeforces.com/contest/1423/problem/A
    - https://www.sciencedirect.com/science/article/abs/pii/0196677485900331?via%3Dihub
  bundledCode: "#line 1 \"graph/stable_roommate.hpp\"\n\n// https://codeforces.com/contest/1423/problem/A\n\
    // https://www.sciencedirect.com/science/article/abs/pii/0196677485900331?via%3Dihub\n\
    // \u9078\u597D\u30EA\u30B9\u30C8\u306F\u5DE6\u306B\u3042\u308B\u65B9\u512A\u5148\
    \n// \u5FC5\u8981\u306A\u3089 INF \u3092\u5165\u308C\u3066\u9577\u3055 N-1 \u305A\
    \u3064\u306B\u3057\u3066\u304A\u304F\u3053\u3068\nvc<pair<int, int>> stable_roommate(vvc<int>\
    \ prefer_list) {\n  vvc<int>& A = prefer_list;\n  int N = len(A);\n  FOR(i, N\
    \ - 1) assert(len(A[i]) == N - 1);\n\n  FOR(v, N) SHOW(v, A[v]);\n\n  vv(int,\
    \ rank, N, N);\n  FOR(i, N) FOR(j, N - 1) rank[i][A[i][j]] = j;\n\n  vv(bool,\
    \ exist, N, N, 1);\n  FOR(i, N) exist[i][i] = 0;\n\n  vc<int> que(N);  // propose\
    \ \u3057\u3066\u306A\u3044\u4EBA\n  FOR(i, N) que[i] = i;\n  vc<int> L(N), R(N,\
    \ N - 1);\n  vc<int> TO(N, -1), FRM(N, -1);\n\n  auto clip = [&](int i) -> void\
    \ {\n    while (L[i] < R[i] && !exist[i][A[i][L[i]]]) ++L[i];\n    while (L[i]\
    \ < R[i] && !exist[i][A[i][R[i] - 1]]) --R[i];\n  };\n\n  auto nxt = [&](int i)\
    \ -> int {\n    // 2 \u756A\u76EE\n    clip(i);\n    assert(R[i] - L[i] >= 2);\n\
    \    int a = A[i][L[i]++];\n    clip(i);\n    A[i][--L[i]] = a;\n    return FRM[A[i][L[i]\
    \ + 1]];\n  };\n\n  while (1) {\n    while (len(que)) {\n      int x = POP(que);\n\
    \      assert(TO[x] == -1);\n      while (1) {\n        clip(x);\n        if (L[x]\
    \ == R[x]) return {};\n        int y = A[x][L[x]];\n        if (FRM[y] != -1 &&\
    \ rank[y][x] > rank[y][FRM[y]]) {\n          exist[x][y] = exist[y][x] = 0, ++L[x];\n\
    \          continue;\n        }\n        if (FRM[y] != -1) {\n          que.eb(FRM[y]),\
    \ exist[FRM[y]][y] = exist[y][FRM[y]] = 0;\n          TO[FRM[y]] = -1, FRM[y]\
    \ = -1;\n        }\n        TO[x] = y, FRM[y] = x;\n        while (A[y][R[y] -\
    \ 1] != x) {\n          int z = A[y][--R[y]];\n          exist[y][z] = exist[z][y]\
    \ = 0;\n        }\n        break;\n      }\n    }\n    SHOW(FRM, TO);\n    FOR(v,\
    \ N) SHOW(v, A[v], L[v], R[v]);\n    FOR(v, N) SHOW(exist[v]);\n    int s = [&]()\
    \ -> int {\n      FOR(s, N) {\n        clip(s);\n        if (R[s] - L[s] > 1)\
    \ return s;\n      }\n      return -1;\n    }();\n    if (s == -1) break;\n  \
    \  int x = s, y = s;\n    do {\n      x = nxt(x), y = nxt(nxt(y));\n    } while\
    \ (x != y);\n    vc<int> cyc;\n    do {\n      cyc.eb(y), y = nxt(y);\n    } while\
    \ (x != y);\n    for (int x : cyc) {\n      int y = TO[x];\n      FRM[y] = -1,\
    \ TO[x] = -1, exist[x][y] = exist[y][x] = 0, que.eb(x);\n    }\n  }\n  vc<pair<int,\
    \ int>> ANS;\n  FOR(i, N) {\n    int j = TO[i];\n    assert(TO[j] == i);\n   \
    \ if (i < j) ANS.eb(i, j);\n  }\n  return ANS;\n}\n"
  code: "\n// https://codeforces.com/contest/1423/problem/A\n// https://www.sciencedirect.com/science/article/abs/pii/0196677485900331?via%3Dihub\n\
    // \u9078\u597D\u30EA\u30B9\u30C8\u306F\u5DE6\u306B\u3042\u308B\u65B9\u512A\u5148\
    \n// \u5FC5\u8981\u306A\u3089 INF \u3092\u5165\u308C\u3066\u9577\u3055 N-1 \u305A\
    \u3064\u306B\u3057\u3066\u304A\u304F\u3053\u3068\nvc<pair<int, int>> stable_roommate(vvc<int>\
    \ prefer_list) {\n  vvc<int>& A = prefer_list;\n  int N = len(A);\n  FOR(i, N\
    \ - 1) assert(len(A[i]) == N - 1);\n\n  FOR(v, N) SHOW(v, A[v]);\n\n  vv(int,\
    \ rank, N, N);\n  FOR(i, N) FOR(j, N - 1) rank[i][A[i][j]] = j;\n\n  vv(bool,\
    \ exist, N, N, 1);\n  FOR(i, N) exist[i][i] = 0;\n\n  vc<int> que(N);  // propose\
    \ \u3057\u3066\u306A\u3044\u4EBA\n  FOR(i, N) que[i] = i;\n  vc<int> L(N), R(N,\
    \ N - 1);\n  vc<int> TO(N, -1), FRM(N, -1);\n\n  auto clip = [&](int i) -> void\
    \ {\n    while (L[i] < R[i] && !exist[i][A[i][L[i]]]) ++L[i];\n    while (L[i]\
    \ < R[i] && !exist[i][A[i][R[i] - 1]]) --R[i];\n  };\n\n  auto nxt = [&](int i)\
    \ -> int {\n    // 2 \u756A\u76EE\n    clip(i);\n    assert(R[i] - L[i] >= 2);\n\
    \    int a = A[i][L[i]++];\n    clip(i);\n    A[i][--L[i]] = a;\n    return FRM[A[i][L[i]\
    \ + 1]];\n  };\n\n  while (1) {\n    while (len(que)) {\n      int x = POP(que);\n\
    \      assert(TO[x] == -1);\n      while (1) {\n        clip(x);\n        if (L[x]\
    \ == R[x]) return {};\n        int y = A[x][L[x]];\n        if (FRM[y] != -1 &&\
    \ rank[y][x] > rank[y][FRM[y]]) {\n          exist[x][y] = exist[y][x] = 0, ++L[x];\n\
    \          continue;\n        }\n        if (FRM[y] != -1) {\n          que.eb(FRM[y]),\
    \ exist[FRM[y]][y] = exist[y][FRM[y]] = 0;\n          TO[FRM[y]] = -1, FRM[y]\
    \ = -1;\n        }\n        TO[x] = y, FRM[y] = x;\n        while (A[y][R[y] -\
    \ 1] != x) {\n          int z = A[y][--R[y]];\n          exist[y][z] = exist[z][y]\
    \ = 0;\n        }\n        break;\n      }\n    }\n    SHOW(FRM, TO);\n    FOR(v,\
    \ N) SHOW(v, A[v], L[v], R[v]);\n    FOR(v, N) SHOW(exist[v]);\n    int s = [&]()\
    \ -> int {\n      FOR(s, N) {\n        clip(s);\n        if (R[s] - L[s] > 1)\
    \ return s;\n      }\n      return -1;\n    }();\n    if (s == -1) break;\n  \
    \  int x = s, y = s;\n    do {\n      x = nxt(x), y = nxt(nxt(y));\n    } while\
    \ (x != y);\n    vc<int> cyc;\n    do {\n      cyc.eb(y), y = nxt(y);\n    } while\
    \ (x != y);\n    for (int x : cyc) {\n      int y = TO[x];\n      FRM[y] = -1,\
    \ TO[x] = -1, exist[x][y] = exist[y][x] = 0, que.eb(x);\n    }\n  }\n  vc<pair<int,\
    \ int>> ANS;\n  FOR(i, N) {\n    int j = TO[i];\n    assert(TO[j] == i);\n   \
    \ if (i < j) ANS.eb(i, j);\n  }\n  return ANS;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/stable_roommate.hpp
  requiredBy: []
  timestamp: '2025-10-30 08:59:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/stable_roommate.hpp
layout: document
redirect_from:
- /library/graph/stable_roommate.hpp
- /library/graph/stable_roommate.hpp.html
title: graph/stable_roommate.hpp
---
