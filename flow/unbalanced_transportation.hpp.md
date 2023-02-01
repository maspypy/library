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
    - https://ac.nowcoder.com/acm/contest/33188/B
  bundledCode: "#line 1 \"flow/unbalanced_transportation.hpp\"\n/*\n\u5DE6\u5074\u306B\
    \ K \u9802\u70B9\u3001\u53F3\u5074\u306B N \u9802\u70B9\u3001\u6D41\u91CF N \u306E\
    \u4E8C\u90E8\u6700\u5C0F\u8CBB\u7528\u6D41\u3092\nO((K^2logN+K^3)N) \u3067\u89E3\
    \u304F\nhttps://ac.nowcoder.com/acm/contest/33188/B\n*/\ntemplate <typename T>\n\
    struct Unbalanced_Transportation_Problem {\n  int K, N;\n  vc<int> supply;\n \
    \ vvc<T> cost;\n  vc<int> FRM;\n  Unbalanced_Transportation_Problem(int K, int\
    \ N, vc<int>& supply)\n      : K(K), N(N), supply(supply) {\n    assert(SUM(supply)\
    \ == N);\n    cost.assign(K, vc<T>(N, infty<T>));\n    FRM.assign(N, -1);\n  }\n\
    \n  void add(int a, int b, T c) {\n    assert(0 <= a && a < K);\n    assert(0\
    \ <= b && b < N);\n    cost[a][b] = c;\n  }\n\n  // \u6D41\u91CF -> \u8CBB\u7528\
    \n  vc<T> calc() {\n    using Q = pqg<pair<T, int>>;\n    vc<T> res = {0};\n \
    \   T MCF = 0;\n    vv(Q, edge, K, K);\n    vc<Q> unused(K);\n    FOR(a, K) FOR(b,\
    \ N) {\n      T c = cost[a][b];\n      if (c == infty<T>) continue;\n      unused[a].emplace(c,\
    \ b);\n    }\n    while (1) {\n      // update prique\n      FOR(a, K) {\n   \
    \     auto& que = unused[a];\n        while (len(que)) {\n          auto [x, b]\
    \ = que.top();\n          if (FRM[b] == -1) break;\n          que.pop();\n   \
    \     }\n      }\n      FOR(a, K) FOR(b, K) {\n        auto& que = edge[a][b];\n\
    \        while (len(que)) {\n          auto [x, c] = que.top();\n          if\
    \ (FRM[c] == b) { break; }\n          que.pop();\n        }\n      }\n\n     \
    \ // \u30B0\u30E9\u30D5\u3092\u4F5C\u308B\n      vv(T, dist_0, K, K, infty<T>);\n\
    \      FOR(a, K) FOR(b, K) {\n        if (len(edge[a][b]) == 0) continue;\n  \
    \      auto [c, idx] = edge[a][b].top();\n        dist_0[a][b] = c;\n      }\n\
    \      // source \u304B\u3089\u306E\u6700\u77ED\u8DEF\n      vc<T> dist(K, infty<T>);\n\
    \      vc<bool> in_que(K);\n      queue<int> que;\n      vc<int> par(K, -1);\n\
    \      FOR(k, K) {\n        if (supply[k]) { dist[k] = 0, in_que[k] = 1, que.emplace(k);\
    \ }\n      }\n      while (!que.empty()) {\n        int v = que.front();\n   \
    \     que.pop(), in_que[v] = 0;\n        FOR(to, K) {\n          if (dist_0[v][to]\
    \ == infty<T>) continue;\n          if (chmin(dist[to], dist[v] + dist_0[v][to]))\
    \ {\n            par[to] = v;\n            if (!in_que[to]) {\n              in_que[to]\
    \ = 1;\n              que.emplace(to);\n            }\n          }\n        }\n\
    \      }\n      int best = -1;\n      T best_c = infty<T>;\n      FOR(k, K) {\n\
    \        if (dist[k] == infty<T>) continue;\n        T x = dist[k] + unused[k].top().fi;\n\
    \        if (chmin(best_c, x)) best = k;\n      }\n      if (best == -1) break;\n\
    \      auto match = [&](int a, int b) -> void {\n        int c = FRM[b];\n   \
    \     if (c != -1) MCF -= cost[c][b];\n        FRM[b] = a;\n        MCF += cost[a][b];\n\
    \        FOR(v, K) {\n          if (v == a || cost[v][b] == infty<T>) continue;\n\
    \          edge[v][a].emplace(cost[v][b] - cost[a][b], b);\n        }\n      };\n\
    \n      int v = best;\n      match(v, unused[v].top().se);\n      while (par[v]\
    \ != -1) {\n        match(par[v], edge[par[v]][v].top().se);\n        v = par[v];\n\
    \      }\n      supply[v]--;\n      res.eb(MCF);\n    }\n    return res;\n  }\n\
    };\n"
  code: "/*\n\u5DE6\u5074\u306B K \u9802\u70B9\u3001\u53F3\u5074\u306B N \u9802\u70B9\
    \u3001\u6D41\u91CF N \u306E\u4E8C\u90E8\u6700\u5C0F\u8CBB\u7528\u6D41\u3092\n\
    O((K^2logN+K^3)N) \u3067\u89E3\u304F\nhttps://ac.nowcoder.com/acm/contest/33188/B\n\
    */\ntemplate <typename T>\nstruct Unbalanced_Transportation_Problem {\n  int K,\
    \ N;\n  vc<int> supply;\n  vvc<T> cost;\n  vc<int> FRM;\n  Unbalanced_Transportation_Problem(int\
    \ K, int N, vc<int>& supply)\n      : K(K), N(N), supply(supply) {\n    assert(SUM(supply)\
    \ == N);\n    cost.assign(K, vc<T>(N, infty<T>));\n    FRM.assign(N, -1);\n  }\n\
    \n  void add(int a, int b, T c) {\n    assert(0 <= a && a < K);\n    assert(0\
    \ <= b && b < N);\n    cost[a][b] = c;\n  }\n\n  // \u6D41\u91CF -> \u8CBB\u7528\
    \n  vc<T> calc() {\n    using Q = pqg<pair<T, int>>;\n    vc<T> res = {0};\n \
    \   T MCF = 0;\n    vv(Q, edge, K, K);\n    vc<Q> unused(K);\n    FOR(a, K) FOR(b,\
    \ N) {\n      T c = cost[a][b];\n      if (c == infty<T>) continue;\n      unused[a].emplace(c,\
    \ b);\n    }\n    while (1) {\n      // update prique\n      FOR(a, K) {\n   \
    \     auto& que = unused[a];\n        while (len(que)) {\n          auto [x, b]\
    \ = que.top();\n          if (FRM[b] == -1) break;\n          que.pop();\n   \
    \     }\n      }\n      FOR(a, K) FOR(b, K) {\n        auto& que = edge[a][b];\n\
    \        while (len(que)) {\n          auto [x, c] = que.top();\n          if\
    \ (FRM[c] == b) { break; }\n          que.pop();\n        }\n      }\n\n     \
    \ // \u30B0\u30E9\u30D5\u3092\u4F5C\u308B\n      vv(T, dist_0, K, K, infty<T>);\n\
    \      FOR(a, K) FOR(b, K) {\n        if (len(edge[a][b]) == 0) continue;\n  \
    \      auto [c, idx] = edge[a][b].top();\n        dist_0[a][b] = c;\n      }\n\
    \      // source \u304B\u3089\u306E\u6700\u77ED\u8DEF\n      vc<T> dist(K, infty<T>);\n\
    \      vc<bool> in_que(K);\n      queue<int> que;\n      vc<int> par(K, -1);\n\
    \      FOR(k, K) {\n        if (supply[k]) { dist[k] = 0, in_que[k] = 1, que.emplace(k);\
    \ }\n      }\n      while (!que.empty()) {\n        int v = que.front();\n   \
    \     que.pop(), in_que[v] = 0;\n        FOR(to, K) {\n          if (dist_0[v][to]\
    \ == infty<T>) continue;\n          if (chmin(dist[to], dist[v] + dist_0[v][to]))\
    \ {\n            par[to] = v;\n            if (!in_que[to]) {\n              in_que[to]\
    \ = 1;\n              que.emplace(to);\n            }\n          }\n        }\n\
    \      }\n      int best = -1;\n      T best_c = infty<T>;\n      FOR(k, K) {\n\
    \        if (dist[k] == infty<T>) continue;\n        T x = dist[k] + unused[k].top().fi;\n\
    \        if (chmin(best_c, x)) best = k;\n      }\n      if (best == -1) break;\n\
    \      auto match = [&](int a, int b) -> void {\n        int c = FRM[b];\n   \
    \     if (c != -1) MCF -= cost[c][b];\n        FRM[b] = a;\n        MCF += cost[a][b];\n\
    \        FOR(v, K) {\n          if (v == a || cost[v][b] == infty<T>) continue;\n\
    \          edge[v][a].emplace(cost[v][b] - cost[a][b], b);\n        }\n      };\n\
    \n      int v = best;\n      match(v, unused[v].top().se);\n      while (par[v]\
    \ != -1) {\n        match(par[v], edge[par[v]][v].top().se);\n        v = par[v];\n\
    \      }\n      supply[v]--;\n      res.eb(MCF);\n    }\n    return res;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: flow/unbalanced_transportation.hpp
  requiredBy: []
  timestamp: '2023-02-02 01:33:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/unbalanced_transportation.hpp
layout: document
redirect_from:
- /library/flow/unbalanced_transportation.hpp
- /library/flow/unbalanced_transportation.hpp.html
title: flow/unbalanced_transportation.hpp
---
