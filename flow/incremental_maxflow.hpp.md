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
  bundledCode: "#line 1 \"flow/incremental_maxflow.hpp\"\n\ntemplate <typename Cap>\n\
    struct Incremental_MaxFlow {\n  struct Edge {\n    int to, rev;\n    Cap cap;\n\
    \  };\n\n  int N;\n  int source, sink;\n  const Cap INF;\n  Cap flow_ans;\n  vvc<Edge>\
    \ G;\n  vc<int> prog, level;\n\n  Incremental_MaxFlow(int N, int source, int sink,\
    \ Cap INF)\n      : N(N), source(source), sink(sink), INF(INF), flow_ans(0) {\n\
    \    G.resize(N);\n  }\n\n  void add(int frm, int to, Cap cap) {\n    assert(0\
    \ <= frm && frm < N);\n    assert(0 <= to && to < N);\n    assert(Cap(0) <= cap);\n\
    \    if (len(G) < N) G.resize(N);\n    G[frm].eb(Edge{to, (int)G[to].size(), cap});\n\
    \    G[to].eb(Edge{frm, (int)G[frm].size() - 1, 0});\n  }\n\n  Cap flow() {\n\
    \    while (set_level(source, sink)) {\n      fill(all(prog), 0);\n      prog.assign(N,\
    \ 0);\n      while (1) {\n        Cap x = flow_dfs(source, sink, INF);\n     \
    \   if (x == 0) break;\n        flow_ans += x;\n        chmin(flow_ans, INF);\n\
    \        if (flow_ans == INF) return flow_ans;\n      }\n    }\n    return flow_ans;\n\
    \  }\n\n  // \u6B8B\u4F59\u30B0\u30E9\u30D5\u306E\u8FBA\n  vc<tuple<int, int,\
    \ Cap>> get_edges() {\n    vc<tuple<int, int, Cap>> edges;\n    FOR(v, N) for\
    \ (auto&& e: G[v]) { edges.eb(v, e.to, e.cap); }\n    return edges;\n  }\n\nprivate:\n\
    \  bool set_level(int source, int sink) {\n    level.assign(N, -1);\n    level[source]\
    \ = 0;\n    queue<int> que;\n    que.push(source);\n    while (!que.empty()) {\n\
    \      int v = que.front();\n      que.pop();\n      for (auto&& e: G[v]) {\n\
    \        if (e.cap > 0 && level[e.to] == -1) {\n          level[e.to] = level[v]\
    \ + 1;\n          if (e.to == sink) return true;\n          que.push(e.to);\n\
    \        }\n      }\n    }\n    return false;\n  }\n\n  Cap flow_dfs(int v, int\
    \ sink, Cap lim) {\n    if (v == sink) return lim;\n    Cap res = 0;\n    for\
    \ (int& i = prog[v]; i < (int)G[v].size(); ++i) {\n      auto& e = G[v][i];\n\
    \      if (e.cap > 0 && level[e.to] == level[v] + 1) {\n        Cap a = flow_dfs(e.to,\
    \ sink, min(lim, e.cap));\n        if (a > 0) {\n          e.cap -= a;\n     \
    \     G[e.to][e.rev].cap += a;\n          res += a;\n          lim -= a;\n   \
    \       if (lim == 0) break;\n        }\n      }\n    }\n    return res;\n  }\n\
    };\n"
  code: "\ntemplate <typename Cap>\nstruct Incremental_MaxFlow {\n  struct Edge {\n\
    \    int to, rev;\n    Cap cap;\n  };\n\n  int N;\n  int source, sink;\n  const\
    \ Cap INF;\n  Cap flow_ans;\n  vvc<Edge> G;\n  vc<int> prog, level;\n\n  Incremental_MaxFlow(int\
    \ N, int source, int sink, Cap INF)\n      : N(N), source(source), sink(sink),\
    \ INF(INF), flow_ans(0) {\n    G.resize(N);\n  }\n\n  void add(int frm, int to,\
    \ Cap cap) {\n    assert(0 <= frm && frm < N);\n    assert(0 <= to && to < N);\n\
    \    assert(Cap(0) <= cap);\n    if (len(G) < N) G.resize(N);\n    G[frm].eb(Edge{to,\
    \ (int)G[to].size(), cap});\n    G[to].eb(Edge{frm, (int)G[frm].size() - 1, 0});\n\
    \  }\n\n  Cap flow() {\n    while (set_level(source, sink)) {\n      fill(all(prog),\
    \ 0);\n      prog.assign(N, 0);\n      while (1) {\n        Cap x = flow_dfs(source,\
    \ sink, INF);\n        if (x == 0) break;\n        flow_ans += x;\n        chmin(flow_ans,\
    \ INF);\n        if (flow_ans == INF) return flow_ans;\n      }\n    }\n    return\
    \ flow_ans;\n  }\n\n  // \u6B8B\u4F59\u30B0\u30E9\u30D5\u306E\u8FBA\n  vc<tuple<int,\
    \ int, Cap>> get_edges() {\n    vc<tuple<int, int, Cap>> edges;\n    FOR(v, N)\
    \ for (auto&& e: G[v]) { edges.eb(v, e.to, e.cap); }\n    return edges;\n  }\n\
    \nprivate:\n  bool set_level(int source, int sink) {\n    level.assign(N, -1);\n\
    \    level[source] = 0;\n    queue<int> que;\n    que.push(source);\n    while\
    \ (!que.empty()) {\n      int v = que.front();\n      que.pop();\n      for (auto&&\
    \ e: G[v]) {\n        if (e.cap > 0 && level[e.to] == -1) {\n          level[e.to]\
    \ = level[v] + 1;\n          if (e.to == sink) return true;\n          que.push(e.to);\n\
    \        }\n      }\n    }\n    return false;\n  }\n\n  Cap flow_dfs(int v, int\
    \ sink, Cap lim) {\n    if (v == sink) return lim;\n    Cap res = 0;\n    for\
    \ (int& i = prog[v]; i < (int)G[v].size(); ++i) {\n      auto& e = G[v][i];\n\
    \      if (e.cap > 0 && level[e.to] == level[v] + 1) {\n        Cap a = flow_dfs(e.to,\
    \ sink, min(lim, e.cap));\n        if (a > 0) {\n          e.cap -= a;\n     \
    \     G[e.to][e.rev].cap += a;\n          res += a;\n          lim -= a;\n   \
    \       if (lim == 0) break;\n        }\n      }\n    }\n    return res;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: flow/incremental_maxflow.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:34:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/incremental_maxflow.hpp
layout: document
redirect_from:
- /library/flow/incremental_maxflow.hpp
- /library/flow/incremental_maxflow.hpp.html
title: flow/incremental_maxflow.hpp
---
