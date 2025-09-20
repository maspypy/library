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
  bundledCode: "#line 1 \"flow/incremental_maxflow.hpp\"\n// \u6D41\u3057\u305F\u5F8C\
    \u3067\u8FBA\u3092\u8FFD\u52A0\u3057\u3066\u3082\u3088\u3044\ntemplate <typename\
    \ Cap>\nstruct Incremental_MaxFlow {\n  // flow \u304C\u6B32\u3057\u3044\u5834\
    \u5408\u306B\u306F init_cap \u3068\u306E\u5DEE\u5206\u304B\u3089\u6C42\u3081\u308B\
    . \u6B8B\u4F59\u30B0\u30E9\u30D5\u3060\u3051\u6301\u3064.\n  struct Edge {\n \
    \   int to;\n    Cap cap;\n  };\n\n  vc<Edge> edges;\n  vc<Cap> init_cap;\n\n\
    \  const int N, source, sink;\n  vc<int> head, nxt;\n  vc<int> prog, level;\n\
    \  bool calculated;\n  Cap flow_ans;\n\n  Incremental_MaxFlow(int N, int source,\
    \ int sink)\n      : N(N),\n        source(source),\n        sink(sink),\n   \
    \     head(N, -1),\n        prog(N, -1),\n        level(N, -1),\n        calculated(0),\n\
    \        flow_ans(0) {}\n\n  void add(int frm, int to, Cap cap, Cap rev_cap =\
    \ 0) {\n    calculated = 0;\n    assert(0 <= frm && frm < N);\n    assert(0 <=\
    \ to && to < N);\n    assert(Cap(0) <= cap);\n    if (frm == to) return;\n   \
    \ nxt.eb(head[frm]), head[frm] = len(nxt) - 1, edges.eb(Edge{to, cap});\n    nxt.eb(head[to]),\
    \ head[to] = len(nxt) - 1, edges.eb(Edge{frm, rev_cap});\n    init_cap.eb(cap),\
    \ init_cap.eb(rev_cap);\n  }\n\n  Cap flow() {\n    if (calculated) return flow_ans;\n\
    \    calculated = true;\n    vc<int> level(N, -1);\n    vc<int> que(N);\n    auto\
    \ bfs = [&]() -> void {\n      fill(all(level), -1);\n      int ql = 0, qr = 0;\n\
    \      level[source] = 0, que[qr++] = source;\n      while (ql < qr) {\n     \
    \   int v = que[ql++];\n        for (int i = head[v]; i != -1; i = nxt[i]) {\n\
    \          Edge& e = edges[i];\n          if (e.cap > 0 && level[e.to] == -1)\
    \ {\n            level[e.to] = level[v] + 1;\n            que[qr++] = e.to;\n\
    \            if (e.to == sink) return;\n          }\n        }\n      }\n    };\n\
    \    vc<int> prog = head;\n    // ACL \u53C2\u8003. v \u307E\u3067\u3044\u304F\
    \u3064\u6D41\u3057\u3066\u304F\u308B\u3068\u3044\u3046\u65B9\u5F0F.\n    // source-sink\u4E0A\
    \u306B\u3042\u308B\u3068\u3053\u308D\u3060\u3051\u63A2\u7D22\u3059\u308B\u306E\
    \u3067\u3053\u3061\u3089\u306E\u65B9\u304C\u9AD8\u901F\u3068\u3044\u3046\u3053\
    \u3068\u3060\u3068\u601D\u3046.\n    auto dfs = [&](auto& dfs, int v, Cap lim)\
    \ -> Cap {\n      if (v == source) return lim;\n      Cap res = 0;\n      int\
    \ nxt_lv = level[v] - 1;\n      for (int& i = prog[v]; i != -1; i = nxt[i]) {\n\
    \        auto& e = edges[i];\n        if (level[e.to] != nxt_lv || edges[i ^ 1].cap\
    \ == 0) continue;\n        Cap a = dfs(dfs, e.to, min(lim - res, edges[i ^ 1].cap));\n\
    \        e.cap += a, edges[i ^ 1].cap -= a, res += a;\n        if (res == lim)\
    \ return res;\n      }\n      level[v] = N;\n      return res;\n    };\n    while\
    \ (1) {\n      bfs();\n      if (level[sink] == -1) break;\n      copy(all(head),\
    \ prog.begin());\n      Cap x = dfs(dfs, sink, infty<Cap>);\n      flow_ans +=\
    \ x;\n      if (flow_ans >= infty<Cap>) return infty<Cap>;\n    }\n    return\
    \ flow_ans;\n  }  // frm, to, flow\n  vc<tuple<int, int, Cap>> get_flow_edges()\
    \ {\n    vc<tuple<int, int, Cap>> res;\n    FOR(v, N) {\n      for (int i = head[v];\
    \ i != -1; i = nxt[i]) {\n        Edge& e = edges[i];\n        Cap f = init_cap[i]\
    \ - e.cap;\n        if (f > 0) res.eb(v, e.to, f);\n      }\n    }\n    return\
    \ res;\n  }\n\n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\
    \u3001\u30AB\u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap,\
    \ vc<int>> cut() {\n    flow();\n    vc<int> res(N);\n    FOR(v, N) res[v] = (level[v]\
    \ >= 0 ? 0 : 1);\n    return {flow_ans, res};\n  }\n\n  // O(F(N+M)) \u304F\u3089\
    \u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  // simple path \u306B\u306A\
    \u308B\n  vvc<int> path_decomposition() {\n    flow();\n    auto edges = get_flow_edges();\n\
    \    vvc<int> TO(N);\n    for (auto&& [frm, to, flow] : edges) {\n      FOR(flow)\
    \ TO[frm].eb(to);\n    }\n    vvc<int> res;\n    vc<int> vis(N);\n\n    FOR(flow_ans)\
    \ {\n      vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ {\n          vis[POP(path)] = 0;\n        }\n        path.eb(to), vis[to] =\
    \ 1;\n      }\n      for (auto&& v : path) vis[v] = 0;\n      res.eb(path);\n\
    \    }\n    return res;\n  }\n};\n"
  code: "// \u6D41\u3057\u305F\u5F8C\u3067\u8FBA\u3092\u8FFD\u52A0\u3057\u3066\u3082\
    \u3088\u3044\ntemplate <typename Cap>\nstruct Incremental_MaxFlow {\n  // flow\
    \ \u304C\u6B32\u3057\u3044\u5834\u5408\u306B\u306F init_cap \u3068\u306E\u5DEE\
    \u5206\u304B\u3089\u6C42\u3081\u308B. \u6B8B\u4F59\u30B0\u30E9\u30D5\u3060\u3051\
    \u6301\u3064.\n  struct Edge {\n    int to;\n    Cap cap;\n  };\n\n  vc<Edge>\
    \ edges;\n  vc<Cap> init_cap;\n\n  const int N, source, sink;\n  vc<int> head,\
    \ nxt;\n  vc<int> prog, level;\n  bool calculated;\n  Cap flow_ans;\n\n  Incremental_MaxFlow(int\
    \ N, int source, int sink)\n      : N(N),\n        source(source),\n        sink(sink),\n\
    \        head(N, -1),\n        prog(N, -1),\n        level(N, -1),\n        calculated(0),\n\
    \        flow_ans(0) {}\n\n  void add(int frm, int to, Cap cap, Cap rev_cap =\
    \ 0) {\n    calculated = 0;\n    assert(0 <= frm && frm < N);\n    assert(0 <=\
    \ to && to < N);\n    assert(Cap(0) <= cap);\n    if (frm == to) return;\n   \
    \ nxt.eb(head[frm]), head[frm] = len(nxt) - 1, edges.eb(Edge{to, cap});\n    nxt.eb(head[to]),\
    \ head[to] = len(nxt) - 1, edges.eb(Edge{frm, rev_cap});\n    init_cap.eb(cap),\
    \ init_cap.eb(rev_cap);\n  }\n\n  Cap flow() {\n    if (calculated) return flow_ans;\n\
    \    calculated = true;\n    vc<int> level(N, -1);\n    vc<int> que(N);\n    auto\
    \ bfs = [&]() -> void {\n      fill(all(level), -1);\n      int ql = 0, qr = 0;\n\
    \      level[source] = 0, que[qr++] = source;\n      while (ql < qr) {\n     \
    \   int v = que[ql++];\n        for (int i = head[v]; i != -1; i = nxt[i]) {\n\
    \          Edge& e = edges[i];\n          if (e.cap > 0 && level[e.to] == -1)\
    \ {\n            level[e.to] = level[v] + 1;\n            que[qr++] = e.to;\n\
    \            if (e.to == sink) return;\n          }\n        }\n      }\n    };\n\
    \    vc<int> prog = head;\n    // ACL \u53C2\u8003. v \u307E\u3067\u3044\u304F\
    \u3064\u6D41\u3057\u3066\u304F\u308B\u3068\u3044\u3046\u65B9\u5F0F.\n    // source-sink\u4E0A\
    \u306B\u3042\u308B\u3068\u3053\u308D\u3060\u3051\u63A2\u7D22\u3059\u308B\u306E\
    \u3067\u3053\u3061\u3089\u306E\u65B9\u304C\u9AD8\u901F\u3068\u3044\u3046\u3053\
    \u3068\u3060\u3068\u601D\u3046.\n    auto dfs = [&](auto& dfs, int v, Cap lim)\
    \ -> Cap {\n      if (v == source) return lim;\n      Cap res = 0;\n      int\
    \ nxt_lv = level[v] - 1;\n      for (int& i = prog[v]; i != -1; i = nxt[i]) {\n\
    \        auto& e = edges[i];\n        if (level[e.to] != nxt_lv || edges[i ^ 1].cap\
    \ == 0) continue;\n        Cap a = dfs(dfs, e.to, min(lim - res, edges[i ^ 1].cap));\n\
    \        e.cap += a, edges[i ^ 1].cap -= a, res += a;\n        if (res == lim)\
    \ return res;\n      }\n      level[v] = N;\n      return res;\n    };\n    while\
    \ (1) {\n      bfs();\n      if (level[sink] == -1) break;\n      copy(all(head),\
    \ prog.begin());\n      Cap x = dfs(dfs, sink, infty<Cap>);\n      flow_ans +=\
    \ x;\n      if (flow_ans >= infty<Cap>) return infty<Cap>;\n    }\n    return\
    \ flow_ans;\n  }  // frm, to, flow\n  vc<tuple<int, int, Cap>> get_flow_edges()\
    \ {\n    vc<tuple<int, int, Cap>> res;\n    FOR(v, N) {\n      for (int i = head[v];\
    \ i != -1; i = nxt[i]) {\n        Edge& e = edges[i];\n        Cap f = init_cap[i]\
    \ - e.cap;\n        if (f > 0) res.eb(v, e.to, f);\n      }\n    }\n    return\
    \ res;\n  }\n\n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\
    \u3001\u30AB\u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap,\
    \ vc<int>> cut() {\n    flow();\n    vc<int> res(N);\n    FOR(v, N) res[v] = (level[v]\
    \ >= 0 ? 0 : 1);\n    return {flow_ans, res};\n  }\n\n  // O(F(N+M)) \u304F\u3089\
    \u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  // simple path \u306B\u306A\
    \u308B\n  vvc<int> path_decomposition() {\n    flow();\n    auto edges = get_flow_edges();\n\
    \    vvc<int> TO(N);\n    for (auto&& [frm, to, flow] : edges) {\n      FOR(flow)\
    \ TO[frm].eb(to);\n    }\n    vvc<int> res;\n    vc<int> vis(N);\n\n    FOR(flow_ans)\
    \ {\n      vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ {\n          vis[POP(path)] = 0;\n        }\n        path.eb(to), vis[to] =\
    \ 1;\n      }\n      for (auto&& v : path) vis[v] = 0;\n      res.eb(path);\n\
    \    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/incremental_maxflow.hpp
  requiredBy: []
  timestamp: '2025-09-20 13:50:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/incremental_maxflow.hpp
layout: document
redirect_from:
- /library/flow/incremental_maxflow.hpp
- /library/flow/incremental_maxflow.hpp.html
title: flow/incremental_maxflow.hpp
---
