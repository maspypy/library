---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A_maxflow.test.cpp
    title: test/aoj/GRL_6_A_maxflow.test.cpp
  - icon: ':x:'
    path: test/yukicoder/177_maxflow.test.cpp
    title: test/yukicoder/177_maxflow.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\n\n// \u9802\u70B9\u6570\u306F\u6E21\u3055\
    \u306A\u304F\u3066\u3088\u3044\ntemplate <typename Cap = int>\nstruct MaxFlowGraph\
    \ {\n  const Cap INF;\n\n  struct Edge {\n    int frm, to;\n    Cap cap;\n   \
    \ int idx;\n  };\n\n  int N;\n  vc<int> indptr;\n  vc<Edge> edges;\n  vc<Cap>\
    \ edge_flow;\n\n  vc<Edge> csr_edges;\n  vc<int> rev;\n  vc<int> level, deq;\n\
    \  bool calculated;\n\n  MaxFlowGraph() : INF(numeric_limits<Cap>::max()), N(0),\
    \ calculated(0) {}\n\n  void add(int frm, int to, Cap cap) {\n    chmax(N, frm\
    \ + 1);\n    chmax(N, to + 1);\n    edges.eb(Edge({frm, to, cap, int(edges.size())}));\n\
    \  }\n\n  void _build() {\n    indptr.resize(N + 1);\n    level.resize(N);\n \
    \   deq.resize(N);\n    int M = len(edges);\n    for (auto&& e: edges) { indptr[e.frm\
    \ + 1]++, indptr[e.to + 1]++; }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n \
    \   auto counter = indptr;\n\n    edge_flow.resize(M);\n    csr_edges.resize(2\
    \ * M);\n    rev.resize(2 * M);\n    for (auto&& e: edges) {\n      int i = counter[e.frm],\
    \ j = counter[e.to];\n      rev[i] = j, rev[j] = i;\n      csr_edges[i] = {e.frm,\
    \ e.to, e.cap, e.idx};\n      csr_edges[j] = {e.to, e.frm, Cap(0), ~e.idx};\n\
    \      counter[e.frm]++, counter[e.to]++;\n    }\n  }\n\n  bool set_level(int\
    \ source, int sink) {\n    // bfs\n    fill(all(level), -1);\n    int l = 0, r\
    \ = 0;\n    deq[r++] = source;\n    level[source] = 0;\n    while (l < r) {\n\
    \      int v = deq[l++];\n      FOR3(i, indptr[v], indptr[v + 1]) {\n        auto&\
    \ e = csr_edges[i];\n        if (e.cap == 0 || level[e.to] >= 0) continue;\n \
    \       level[e.to] = level[v] + 1;\n        if (e.to == sink) return true;\n\
    \        deq[r++] = e.to;\n      }\n    }\n    return false;\n  }\n\n  Cap flow_dfs(int\
    \ v, int sink, Cap lim) {\n    if (v == sink) return lim;\n    FOR3(i, indptr[v],\
    \ indptr[v + 1]) {\n      auto& e = csr_edges[i];\n      if (e.cap == 0 || level[v]\
    \ >= level[e.to]) continue;\n      Cap x = flow_dfs(e.to, sink, min(lim, e.cap));\n\
    \      if (x > Cap(0)) {\n        e.cap -= x;\n        int j = rev[i];\n     \
    \   csr_edges[j].cap += x;\n        if (e.idx >= 0)\n          edge_flow[e.idx]\
    \ += x;\n        else\n          edge_flow[~e.idx] -= x;\n        return x;\n\
    \      }\n    }\n    level[v] = -1;\n    return 0;\n  }\n\n  Cap flow(int source,\
    \ int sink) {\n    assert(!calculated);\n    calculated = true;\n    _build();\n\
    \    Cap f = 0;\n    while (set_level(source, sink)) {\n      while (1) {\n  \
    \      Cap x = flow_dfs(source, sink, INF);\n        if (x == 0) break;\n    \
    \    f += x;\n      }\n    }\n    return f;\n  }\n\n  vc<tuple<int, int, Cap>>\
    \ get_edges() {\n    vc<tuple<int, int, Cap>> res;\n    for (auto&& e: edges)\
    \ {\n      Cap f = edge_flow[e.idx];\n      if (f > Cap(0)) res.eb(e.frm, e.to,\
    \ f);\n    }\n    return res;\n  }\n\n  void debug() {\n    for (auto&& e: edges)\
    \ print(e.frm, e.to, e.cap);\n  }\n};\n"
  code: "\n// \u9802\u70B9\u6570\u306F\u6E21\u3055\u306A\u304F\u3066\u3088\u3044\n\
    template <typename Cap = int>\nstruct MaxFlowGraph {\n  const Cap INF;\n\n  struct\
    \ Edge {\n    int frm, to;\n    Cap cap;\n    int idx;\n  };\n\n  int N;\n  vc<int>\
    \ indptr;\n  vc<Edge> edges;\n  vc<Cap> edge_flow;\n\n  vc<Edge> csr_edges;\n\
    \  vc<int> rev;\n  vc<int> level, deq;\n  bool calculated;\n\n  MaxFlowGraph()\
    \ : INF(numeric_limits<Cap>::max()), N(0), calculated(0) {}\n\n  void add(int\
    \ frm, int to, Cap cap) {\n    chmax(N, frm + 1);\n    chmax(N, to + 1);\n   \
    \ edges.eb(Edge({frm, to, cap, int(edges.size())}));\n  }\n\n  void _build() {\n\
    \    indptr.resize(N + 1);\n    level.resize(N);\n    deq.resize(N);\n    int\
    \ M = len(edges);\n    for (auto&& e: edges) { indptr[e.frm + 1]++, indptr[e.to\
    \ + 1]++; }\n    FOR(v, N) indptr[v + 1] += indptr[v];\n    auto counter = indptr;\n\
    \n    edge_flow.resize(M);\n    csr_edges.resize(2 * M);\n    rev.resize(2 * M);\n\
    \    for (auto&& e: edges) {\n      int i = counter[e.frm], j = counter[e.to];\n\
    \      rev[i] = j, rev[j] = i;\n      csr_edges[i] = {e.frm, e.to, e.cap, e.idx};\n\
    \      csr_edges[j] = {e.to, e.frm, Cap(0), ~e.idx};\n      counter[e.frm]++,\
    \ counter[e.to]++;\n    }\n  }\n\n  bool set_level(int source, int sink) {\n \
    \   // bfs\n    fill(all(level), -1);\n    int l = 0, r = 0;\n    deq[r++] = source;\n\
    \    level[source] = 0;\n    while (l < r) {\n      int v = deq[l++];\n      FOR3(i,\
    \ indptr[v], indptr[v + 1]) {\n        auto& e = csr_edges[i];\n        if (e.cap\
    \ == 0 || level[e.to] >= 0) continue;\n        level[e.to] = level[v] + 1;\n \
    \       if (e.to == sink) return true;\n        deq[r++] = e.to;\n      }\n  \
    \  }\n    return false;\n  }\n\n  Cap flow_dfs(int v, int sink, Cap lim) {\n \
    \   if (v == sink) return lim;\n    FOR3(i, indptr[v], indptr[v + 1]) {\n    \
    \  auto& e = csr_edges[i];\n      if (e.cap == 0 || level[v] >= level[e.to]) continue;\n\
    \      Cap x = flow_dfs(e.to, sink, min(lim, e.cap));\n      if (x > Cap(0)) {\n\
    \        e.cap -= x;\n        int j = rev[i];\n        csr_edges[j].cap += x;\n\
    \        if (e.idx >= 0)\n          edge_flow[e.idx] += x;\n        else\n   \
    \       edge_flow[~e.idx] -= x;\n        return x;\n      }\n    }\n    level[v]\
    \ = -1;\n    return 0;\n  }\n\n  Cap flow(int source, int sink) {\n    assert(!calculated);\n\
    \    calculated = true;\n    _build();\n    Cap f = 0;\n    while (set_level(source,\
    \ sink)) {\n      while (1) {\n        Cap x = flow_dfs(source, sink, INF);\n\
    \        if (x == 0) break;\n        f += x;\n      }\n    }\n    return f;\n\
    \  }\n\n  vc<tuple<int, int, Cap>> get_edges() {\n    vc<tuple<int, int, Cap>>\
    \ res;\n    for (auto&& e: edges) {\n      Cap f = edge_flow[e.idx];\n      if\
    \ (f > Cap(0)) res.eb(e.frm, e.to, f);\n    }\n    return res;\n  }\n\n  void\
    \ debug() {\n    for (auto&& e: edges) print(e.frm, e.to, e.cap);\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/maxflow.hpp
  requiredBy: []
  timestamp: '2022-04-16 05:20:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/177_maxflow.test.cpp
  - test/aoj/GRL_6_A_maxflow.test.cpp
documentation_of: flow/maxflow.hpp
layout: document
redirect_from:
- /library/flow/maxflow.hpp
- /library/flow/maxflow.hpp.html
title: flow/maxflow.hpp
---
