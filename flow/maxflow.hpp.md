---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: flow/binary_optimization.hpp
    title: flow/binary_optimization.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1541.test.cpp
    title: test/yukicoder/1541.test.cpp
  - icon: ':x:'
    path: test/yukicoder/177.test.cpp
    title: test/yukicoder/177.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\ntemplate <typename Cap>\nstruct MaxFlowGraph\
    \ {\n  struct Edge {\n    int to, rev;\n    Cap cap;\n  };\n\n  const Cap INF;\n\
    \  int N;\n  vvc<Edge> G;\n  vc<int> prog, level;\n  Cap flow_ans;\n  bool calculated;\n\
    \n  MaxFlowGraph(int N, Cap INF) : INF(INF), N(N), calculated(0) {}\n\n  void\
    \ add(int frm, int to, Cap cap) {\n    assert(0 <= frm && frm < N);\n    assert(0\
    \ <= to && to < N);\n    assert(Cap(0) <= cap);\n    if (len(G) < N) G.resize(N);\n\
    \    G[frm].eb(Edge{to, (int)G[to].size(), cap});\n    G[to].eb(Edge{frm, (int)G[frm].size()\
    \ - 1, 0});\n  }\n\n  Cap flow(int source, int sink) {\n    if (calculated) return\
    \ flow_ans;\n    calculated = true;\n    chmax(N, source + 1);\n    chmax(N, sink\
    \ + 1);\n    G.resize(N);\n    flow_ans = 0;\n    while (set_level(source, sink))\
    \ {\n      fill(all(prog), 0);\n      prog.assign(N, 0);\n      while (1) {\n\
    \        Cap x = flow_dfs(source, sink, INF);\n        if (x == 0) break;\n  \
    \      flow_ans += x;\n        chmin(flow_ans, INF);\n        if (flow_ans ==\
    \ INF) return flow_ans;\n      }\n    }\n    return flow_ans;\n  }\n\n  // \u6700\
    \u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\
    \u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>> cut(int source,\
    \ int sink) {\n    Cap f = flow(source, sink);\n    vc<int> res(N);\n    FOR(v,\
    \ N) res[v] = (level[v] >= 0 ? 0 : 1);\n    return {f, res};\n  }\n\n  // \u6B8B\
    \u4F59\u30B0\u30E9\u30D5\u306E\u8FBA\n  vc<tuple<int, int, Cap>> get_edges() {\n\
    \    vc<tuple<int, int, Cap>> edges;\n    FOR(v, N) for (auto&& e: G[v]) { edges.eb(v,\
    \ e.to, e.cap); }\n    return edges;\n  }\n\nprivate:\n  bool set_level(int source,\
    \ int sink) {\n    level.assign(N, -1);\n    level[source] = 0;\n    queue<int>\
    \ que;\n    que.push(source);\n    while (!que.empty()) {\n      int v = que.front();\n\
    \      que.pop();\n      for (auto&& e: G[v]) {\n        if (e.cap > 0 && level[e.to]\
    \ == -1) {\n          level[e.to] = level[v] + 1;\n          if (e.to == sink)\
    \ return true;\n          que.push(e.to);\n        }\n      }\n    }\n    return\
    \ false;\n  }\n\n  Cap flow_dfs(int v, int sink, Cap lim) {\n    if (v == sink)\
    \ return lim;\n    Cap res = 0;\n    for (int& i = prog[v]; i < (int)G[v].size();\
    \ ++i) {\n      auto& e = G[v][i];\n      if (e.cap > 0 && level[e.to] == level[v]\
    \ + 1) {\n        Cap a = flow_dfs(e.to, sink, min(lim, e.cap));\n        if (a\
    \ > 0) {\n          e.cap -= a;\n          G[e.to][e.rev].cap += a;\n        \
    \  res += a;\n          lim -= a;\n          if (lim == 0) break;\n        }\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  code: "template <typename Cap>\nstruct MaxFlowGraph {\n  struct Edge {\n    int\
    \ to, rev;\n    Cap cap;\n  };\n\n  const Cap INF;\n  int N;\n  vvc<Edge> G;\n\
    \  vc<int> prog, level;\n  Cap flow_ans;\n  bool calculated;\n\n  MaxFlowGraph(int\
    \ N, Cap INF) : INF(INF), N(N), calculated(0) {}\n\n  void add(int frm, int to,\
    \ Cap cap) {\n    assert(0 <= frm && frm < N);\n    assert(0 <= to && to < N);\n\
    \    assert(Cap(0) <= cap);\n    if (len(G) < N) G.resize(N);\n    G[frm].eb(Edge{to,\
    \ (int)G[to].size(), cap});\n    G[to].eb(Edge{frm, (int)G[frm].size() - 1, 0});\n\
    \  }\n\n  Cap flow(int source, int sink) {\n    if (calculated) return flow_ans;\n\
    \    calculated = true;\n    chmax(N, source + 1);\n    chmax(N, sink + 1);\n\
    \    G.resize(N);\n    flow_ans = 0;\n    while (set_level(source, sink)) {\n\
    \      fill(all(prog), 0);\n      prog.assign(N, 0);\n      while (1) {\n    \
    \    Cap x = flow_dfs(source, sink, INF);\n        if (x == 0) break;\n      \
    \  flow_ans += x;\n        chmin(flow_ans, INF);\n        if (flow_ans == INF)\
    \ return flow_ans;\n      }\n    }\n    return flow_ans;\n  }\n\n  // \u6700\u5C0F\
    \u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\u3092\
    \u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>> cut(int source,\
    \ int sink) {\n    Cap f = flow(source, sink);\n    vc<int> res(N);\n    FOR(v,\
    \ N) res[v] = (level[v] >= 0 ? 0 : 1);\n    return {f, res};\n  }\n\n  // \u6B8B\
    \u4F59\u30B0\u30E9\u30D5\u306E\u8FBA\n  vc<tuple<int, int, Cap>> get_edges() {\n\
    \    vc<tuple<int, int, Cap>> edges;\n    FOR(v, N) for (auto&& e: G[v]) { edges.eb(v,\
    \ e.to, e.cap); }\n    return edges;\n  }\n\nprivate:\n  bool set_level(int source,\
    \ int sink) {\n    level.assign(N, -1);\n    level[source] = 0;\n    queue<int>\
    \ que;\n    que.push(source);\n    while (!que.empty()) {\n      int v = que.front();\n\
    \      que.pop();\n      for (auto&& e: G[v]) {\n        if (e.cap > 0 && level[e.to]\
    \ == -1) {\n          level[e.to] = level[v] + 1;\n          if (e.to == sink)\
    \ return true;\n          que.push(e.to);\n        }\n      }\n    }\n    return\
    \ false;\n  }\n\n  Cap flow_dfs(int v, int sink, Cap lim) {\n    if (v == sink)\
    \ return lim;\n    Cap res = 0;\n    for (int& i = prog[v]; i < (int)G[v].size();\
    \ ++i) {\n      auto& e = G[v][i];\n      if (e.cap > 0 && level[e.to] == level[v]\
    \ + 1) {\n        Cap a = flow_dfs(e.to, sink, min(lim, e.cap));\n        if (a\
    \ > 0) {\n          e.cap -= a;\n          G[e.to][e.rev].cap += a;\n        \
    \  res += a;\n          lim -= a;\n          if (lim == 0) break;\n        }\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/maxflow.hpp
  requiredBy:
  - flow/binary_optimization.hpp
  timestamp: '2022-05-22 15:15:57+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_6_A.test.cpp
  - test/yukicoder/1541.test.cpp
  - test/yukicoder/177.test.cpp
documentation_of: flow/maxflow.hpp
layout: document
redirect_from:
- /library/flow/maxflow.hpp
- /library/flow/maxflow.hpp.html
title: flow/maxflow.hpp
---
