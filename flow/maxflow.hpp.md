---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/binary_optimization.hpp
    title: flow/binary_optimization.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dag_path_cover.hpp
    title: graph/dag_path_cover.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2251_1.test.cpp
    title: test/aoj/2251_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1541.test.cpp
    title: test/yukicoder/1541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/177.test.cpp
    title: test/yukicoder/177.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2320.test.cpp
    title: test/yukicoder/2320.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc193f.test.cpp
    title: test_atcoder/abc193f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc259g.test.cpp
    title: test_atcoder/abc259g.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc318g.test.cpp
    title: test_atcoder/abc318g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\n// incremental \u306B\u8FBA\u3092\u8FFD\
    \u52A0\u3057\u3066\u3088\u3044\ntemplate <typename Cap>\nstruct MaxFlow {\n  struct\
    \ Edge {\n    int to, rev;\n    Cap cap;\n    Cap flow = 0;\n  };\n\n  const int\
    \ N, source, sink;\n  vvc<Edge> edges;\n  vc<int> prog, level;\n  vc<int> que;\n\
    \  bool calculated;\n  Cap flow_ans;\n\n  MaxFlow(int N, int source, int sink)\n\
    \      : N(N),\n        source(source),\n        sink(sink),\n        edges(N),\n\
    \        calculated(0),\n        flow_ans(0) {}\n\n  void add(int frm, int to,\
    \ Cap cap, Cap rev_cap = 0) {\n    calculated = 0;\n    assert(0 <= frm && frm\
    \ < N);\n    assert(0 <= to && to < N);\n    assert(frm != to);\n    assert(Cap(0)\
    \ <= cap);\n    if (frm == to) return;\n    int a = len(edges[frm]);\n    int\
    \ b = len(edges[to]);\n    edges[frm].eb(Edge{to, b, cap, 0});\n    edges[to].eb(Edge{frm,\
    \ a, rev_cap, 0});\n  }\n\n  // frm, to, flow\n  vc<tuple<int, int, Cap>> get_flow_edges()\
    \ {\n    vc<tuple<int, int, Cap>> res;\n    FOR(frm, N) {\n      for (auto&& e:\
    \ edges[frm]) {\n        if (e.flow <= 0) continue;\n        res.eb(frm, e.to,\
    \ e.flow);\n      }\n    }\n    return res;\n  }\n\n  // \u5DEE\u5206\u3067\u306F\
    \u306A\u304F\u3053\u308C\u307E\u3067\u306E\u7DCF\u91CF\n  Cap flow() {\n    if\
    \ (calculated) return flow_ans;\n    calculated = true;\n    while (set_level())\
    \ {\n      prog.assign(N, 0);\n      while (1) {\n        Cap x = flow_dfs(source,\
    \ infty<Cap>);\n        if (x == 0) break;\n        flow_ans += x;\n        chmin(flow_ans,\
    \ infty<Cap>);\n        if (flow_ans == infty<Cap>) return flow_ans;\n      }\n\
    \    }\n    return flow_ans;\n  }\n\n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\
    \u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\
    \u8FD4\u3059\n  pair<Cap, vc<int>> cut() {\n    flow();\n    vc<int> res(N);\n\
    \    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);\n    return {flow_ans, res};\n\
    \  }\n\n  // O(F(N+M)) \u304F\u3089\u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\
    \n  // simple path \u306B\u306A\u308B\n  vvc<int> path_decomposition() {\n   \
    \ flow();\n    auto edges = get_flow_edges();\n    vvc<int> TO(N);\n    for (auto&&\
    \ [frm, to, flow]: edges) { FOR(flow) TO[frm].eb(to); }\n    vvc<int> res;\n \
    \   vc<int> vis(N);\n\n    FOR(flow_ans) {\n      vc<int> path = {source};\n \
    \     vis[source] = 1;\n      while (path.back() != sink) {\n        int to =\
    \ POP(TO[path.back()]);\n        while (vis[to]) { vis[POP(path)] = 0; }\n   \
    \     path.eb(to), vis[to] = 1;\n      }\n      for (auto&& v: path) vis[v] =\
    \ 0;\n      res.eb(path);\n    }\n    return res;\n  }\n\n  void debug() {\n \
    \   print(\"source\", source);\n    print(\"sink\", sink);\n    print(\"edges\
    \ (frm, to, cap, flow)\");\n    FOR(v, N) {\n      for (auto& e: edges[v]) {\n\
    \        if (e.cap == 0 && e.flow == 0) continue;\n        print(v, e.to, e.cap,\
    \ e.flow);\n      }\n    }\n  }\n\nprivate:\n  bool set_level() {\n    que.resize(N);\n\
    \    level.assign(N, -1);\n    level[source] = 0;\n    int l = 0, r = 0;\n   \
    \ que[r++] = source;\n    while (l < r) {\n      int v = que[l++];\n      for\
    \ (auto&& e: edges[v]) {\n        if (e.cap > 0 && level[e.to] == -1) {\n    \
    \      level[e.to] = level[v] + 1;\n          if (e.to == sink) return true;\n\
    \          que[r++] = e.to;\n        }\n      }\n    }\n    return false;\n  }\n\
    \n  Cap flow_dfs(int v, Cap lim) {\n    if (v == sink) return lim;\n    Cap res\
    \ = 0;\n    for (int& i = prog[v]; i < len(edges[v]); ++i) {\n      auto& e =\
    \ edges[v][i];\n      if (e.cap > 0 && level[e.to] == level[v] + 1) {\n      \
    \  Cap a = flow_dfs(e.to, min(lim, e.cap));\n        if (a > 0) {\n          e.cap\
    \ -= a, e.flow += a;\n          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow\
    \ -= a;\n          res += a;\n          lim -= a;\n          if (lim == 0) break;\n\
    \        }\n      }\n    }\n    return res;\n  }\n};\n"
  code: "// incremental \u306B\u8FBA\u3092\u8FFD\u52A0\u3057\u3066\u3088\u3044\ntemplate\
    \ <typename Cap>\nstruct MaxFlow {\n  struct Edge {\n    int to, rev;\n    Cap\
    \ cap;\n    Cap flow = 0;\n  };\n\n  const int N, source, sink;\n  vvc<Edge> edges;\n\
    \  vc<int> prog, level;\n  vc<int> que;\n  bool calculated;\n  Cap flow_ans;\n\
    \n  MaxFlow(int N, int source, int sink)\n      : N(N),\n        source(source),\n\
    \        sink(sink),\n        edges(N),\n        calculated(0),\n        flow_ans(0)\
    \ {}\n\n  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {\n    calculated\
    \ = 0;\n    assert(0 <= frm && frm < N);\n    assert(0 <= to && to < N);\n   \
    \ assert(frm != to);\n    assert(Cap(0) <= cap);\n    if (frm == to) return;\n\
    \    int a = len(edges[frm]);\n    int b = len(edges[to]);\n    edges[frm].eb(Edge{to,\
    \ b, cap, 0});\n    edges[to].eb(Edge{frm, a, rev_cap, 0});\n  }\n\n  // frm,\
    \ to, flow\n  vc<tuple<int, int, Cap>> get_flow_edges() {\n    vc<tuple<int, int,\
    \ Cap>> res;\n    FOR(frm, N) {\n      for (auto&& e: edges[frm]) {\n        if\
    \ (e.flow <= 0) continue;\n        res.eb(frm, e.to, e.flow);\n      }\n    }\n\
    \    return res;\n  }\n\n  // \u5DEE\u5206\u3067\u306F\u306A\u304F\u3053\u308C\
    \u307E\u3067\u306E\u7DCF\u91CF\n  Cap flow() {\n    if (calculated) return flow_ans;\n\
    \    calculated = true;\n    while (set_level()) {\n      prog.assign(N, 0);\n\
    \      while (1) {\n        Cap x = flow_dfs(source, infty<Cap>);\n        if\
    \ (x == 0) break;\n        flow_ans += x;\n        chmin(flow_ans, infty<Cap>);\n\
    \        if (flow_ans == infty<Cap>) return flow_ans;\n      }\n    }\n    return\
    \ flow_ans;\n  }\n\n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\
    \u3073\u3001\u30AB\u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n\
    \  pair<Cap, vc<int>> cut() {\n    flow();\n    vc<int> res(N);\n    FOR(v, N)\
    \ res[v] = (level[v] >= 0 ? 0 : 1);\n    return {flow_ans, res};\n  }\n\n  //\
    \ O(F(N+M)) \u304F\u3089\u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  //\
    \ simple path \u306B\u306A\u308B\n  vvc<int> path_decomposition() {\n    flow();\n\
    \    auto edges = get_flow_edges();\n    vvc<int> TO(N);\n    for (auto&& [frm,\
    \ to, flow]: edges) { FOR(flow) TO[frm].eb(to); }\n    vvc<int> res;\n    vc<int>\
    \ vis(N);\n\n    FOR(flow_ans) {\n      vc<int> path = {source};\n      vis[source]\
    \ = 1;\n      while (path.back() != sink) {\n        int to = POP(TO[path.back()]);\n\
    \        while (vis[to]) { vis[POP(path)] = 0; }\n        path.eb(to), vis[to]\
    \ = 1;\n      }\n      for (auto&& v: path) vis[v] = 0;\n      res.eb(path);\n\
    \    }\n    return res;\n  }\n\n  void debug() {\n    print(\"source\", source);\n\
    \    print(\"sink\", sink);\n    print(\"edges (frm, to, cap, flow)\");\n    FOR(v,\
    \ N) {\n      for (auto& e: edges[v]) {\n        if (e.cap == 0 && e.flow == 0)\
    \ continue;\n        print(v, e.to, e.cap, e.flow);\n      }\n    }\n  }\n\nprivate:\n\
    \  bool set_level() {\n    que.resize(N);\n    level.assign(N, -1);\n    level[source]\
    \ = 0;\n    int l = 0, r = 0;\n    que[r++] = source;\n    while (l < r) {\n \
    \     int v = que[l++];\n      for (auto&& e: edges[v]) {\n        if (e.cap >\
    \ 0 && level[e.to] == -1) {\n          level[e.to] = level[v] + 1;\n         \
    \ if (e.to == sink) return true;\n          que[r++] = e.to;\n        }\n    \
    \  }\n    }\n    return false;\n  }\n\n  Cap flow_dfs(int v, Cap lim) {\n    if\
    \ (v == sink) return lim;\n    Cap res = 0;\n    for (int& i = prog[v]; i < len(edges[v]);\
    \ ++i) {\n      auto& e = edges[v][i];\n      if (e.cap > 0 && level[e.to] ==\
    \ level[v] + 1) {\n        Cap a = flow_dfs(e.to, min(lim, e.cap));\n        if\
    \ (a > 0) {\n          e.cap -= a, e.flow += a;\n          edges[e.to][e.rev].cap\
    \ += a, edges[e.to][e.rev].flow -= a;\n          res += a;\n          lim -= a;\n\
    \          if (lim == 0) break;\n        }\n      }\n    }\n    return res;\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/maxflow.hpp
  requiredBy:
  - flow/binary_optimization.hpp
  - graph/dag_path_cover.hpp
  timestamp: '2023-10-29 05:43:44+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/2320.test.cpp
  - test/yukicoder/1541.test.cpp
  - test/yukicoder/177.test.cpp
  - test/aoj/GRL_6_A.test.cpp
  - test/aoj/2251_1.test.cpp
  - test_atcoder/abc318g.test.cpp
  - test_atcoder/abc193f.test.cpp
  - test_atcoder/abc259g.test.cpp
documentation_of: flow/maxflow.hpp
layout: document
redirect_from:
- /library/flow/maxflow.hpp
- /library/flow/maxflow.hpp.html
title: flow/maxflow.hpp
---
