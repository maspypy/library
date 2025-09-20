---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/binary_optimization.hpp
    title: flow/binary_optimization.hpp
  - icon: ':warning:'
    path: flow/k_ary_optimization.hpp
    title: flow/k_ary_optimization.hpp
  - icon: ':warning:'
    path: game/graph_path_game.hpp
    title: game/graph_path_game.hpp
  - icon: ':heavy_check_mark:'
    path: graph/dag_path_cover.hpp
    title: graph/dag_path_cover.hpp
  - icon: ':warning:'
    path: graph/maximum_weighted_antichain.hpp
    title: graph/maximum_weighted_antichain.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/1541.test.cpp
    title: test/3_yukicoder/1541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/177.test.cpp
    title: test/3_yukicoder/177.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/3_yukicoder/2320.test.cpp
    title: test/3_yukicoder/2320.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/2251_1.test.cpp
    title: test/4_aoj/2251_1.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/2835.test.cpp
    title: test/4_aoj/2835.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/4_aoj/GRL_6_A.test.cpp
    title: test/4_aoj/GRL_6_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\ntemplate <typename Cap>\nstruct MaxFlow\
    \ {\n  struct Edge {\n    int to, rev;\n    Cap cap;\n  };\n\n  vc<Edge> edges;\n\
    \  vc<int> indptr, level;\n  vc<Cap> init_cap;\n  vc<tuple<int, int, Cap, Cap>>\
    \ edge_pool;\n\n  const int N, source, sink;\n  bool calculated;\n  Cap flow_ans;\n\
    \  vc<int> pos;\n\n  MaxFlow(int N, int source, int sink)\n      : N(N), source(source),\
    \ sink(sink), calculated(0), flow_ans(0) {}\n\n  void add(int frm, int to, Cap\
    \ cap, Cap rev_cap = 0) {\n    calculated = 0;\n    assert(0 <= frm && frm < N);\n\
    \    assert(0 <= to && to < N);\n    assert(Cap(0) <= cap);\n    edge_pool.eb(frm,\
    \ to, cap, rev_cap);\n  }\n\n  void build_csr() {\n    int M = len(edge_pool);\n\
    \    indptr.assign(N + 1, 0);\n    for (auto [a, b, c, d] : edge_pool) indptr[a\
    \ + 1]++, indptr[b + 1]++;\n    FOR(i, N) indptr[i + 1] += indptr[i];\n    vc<int>\
    \ prog = indptr;\n    edges.resize(2 * M);\n    init_cap.resize(2 * M);\n    for\
    \ (auto [a, b, c, d] : edge_pool) {\n      int I1 = prog[a], I2 = prog[b];\n \
    \     edges[I1] = Edge{b, I2, c}, init_cap[I1] = c, prog[a]++;\n      edges[I2]\
    \ = Edge{a, I1, d}, init_cap[I2] = d, prog[b]++;\n      pos.eb(I1);\n    }\n \
    \ }\n\n  Cap flow() {\n    if (calculated) return flow_ans;\n    calculated =\
    \ true;\n    if (len(edges) != 2 * len(edge_pool)) build_csr();\n    vc<int> prog\
    \ = indptr;\n    level.resize(N);\n    vc<int> que(N);\n    auto bfs = [&]() ->\
    \ void {\n      fill(all(level), -1);\n      int ql = 0, qr = 0;\n      level[source]\
    \ = 0, que[qr++] = source;\n      while (ql < qr) {\n        int v = que[ql++];\n\
    \        FOR(i, indptr[v], indptr[v + 1]) {\n          Edge& e = edges[i];\n \
    \         if (e.cap > 0 && level[e.to] == -1) {\n            level[e.to] = level[v]\
    \ + 1;\n            que[qr++] = e.to;\n            if (e.to == sink) return;\n\
    \          }\n        }\n      }\n    };\n\n    // ACL \u53C2\u8003. v \u307E\u3067\
    \u3044\u304F\u3064\u6D41\u3057\u3066\u304F\u308B\u3068\u3044\u3046\u65B9\u5F0F\
    .\n    // source-sink\u4E0A\u306B\u3042\u308B\u3068\u3053\u308D\u3060\u3051\u63A2\
    \u7D22\u3059\u308B\u306E\u3067\u3053\u3061\u3089\u306E\u65B9\u304C\u9AD8\u901F\
    \u3068\u3044\u3046\u3053\u3068\u3060\u3068\u601D\u3046.\n    auto dfs = [&](auto&\
    \ dfs, int v, Cap lim) -> Cap {\n      if (v == source) return lim;\n      Cap\
    \ res = 0;\n      int nxt_lv = level[v] - 1;\n      for (int& i = prog[v]; i <\
    \ indptr[v + 1]; ++i) {\n        auto& e = edges[i];\n        if (level[e.to]\
    \ != nxt_lv || edges[e.rev].cap == 0) continue;\n        Cap a = dfs(dfs, e.to,\
    \ min(lim - res, edges[e.rev].cap));\n        if (a <= 0) continue;\n        e.cap\
    \ += a, edges[e.rev].cap -= a, res += a;\n        if (res == lim) return res;\n\
    \      }\n      level[v] = N;\n      return res;\n    };\n    while (1) {\n  \
    \    bfs();\n      if (level[sink] == -1) break;\n      copy(all(indptr), prog.begin());\n\
    \      Cap x = dfs(dfs, sink, infty<Cap>);\n      flow_ans += x;\n      if (flow_ans\
    \ >= infty<Cap>) return infty<Cap>;\n    }\n    return flow_ans;\n  }\n\n  void\
    \ change_capacity(int i, Cap after) {\n    i = pos[i];\n    auto& e = edges[i];\n\
    \    Cap before = init_cap[i];\n    Cap f = before - e.cap;\n    init_cap[i] =\
    \ after;\n    if (before < after) {\n      calculated = (e.cap > 0);\n      e.cap\
    \ += after - before;\n      return;\n    }\n    e.cap = after - f;\n    // \u5DEE\
    \u5206\u3092\u62BC\u3057\u623B\u3059\u51E6\u7406\u767A\u751F\n    if (e.cap <\
    \ 0) flow_push_back(e);\n  }\n\n  void flow_push_back(Edge& e0) {\n    auto& re0\
    \ = edges[e0.rev];\n    int a = re0.to;\n    int b = e0.to;\n    /*\n    \u8FBA\
    \ e0 \u306E\u5BB9\u91CF\u304C\u6B63\u306B\u306A\u308B\u3088\u3046\u306B\u623B\u3059\
    \n    path-cycle \u5206\u89E3\u3092\u8003\u3048\u308C\u3070\u3001\n    - uv \u8FBA\
    \u3092\u542B\u3080\u30B5\u30A4\u30AF\u30EB\u3092\u6D88\u3059\n    - suvt \u30D1\
    \u30B9\u3092\u6D88\u3059\n    \u524D\u8005\u306F\u6B8B\u4F59\u30B0\u30E9\u30D5\
    \u3067 ab \u30D1\u30B9\uFF08flow_ans \u304C\u5909\u308F\u3089\u306A\u3044\uFF09\
    \n    \u5F8C\u8005\u306F\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067 tb, as \u30D1\u30B9\
    \n    */\n\n    vc<int> prog(N + 1);\n    auto find_path = [&](int s, int t, Cap\
    \ lim) -> Cap {\n      vc<bool> vis(N);\n      copy(all(indptr), prog.begin());\n\
    \      auto dfs = [&](auto& dfs, int v, Cap f) -> Cap {\n        if (v == t) return\
    \ f;\n        for (int& i = prog[v]; i < indptr[v + 1]; ++i) {\n          auto&\
    \ e = edges[i];\n          if (vis[e.to] || e.cap <= Cap(0)) continue;\n     \
    \     vis[e.to] = 1;\n          Cap a = dfs(dfs, e.to, min(f, e.cap));\n     \
    \     assert(a >= 0);\n          if (a == Cap(0)) continue;\n          e.cap -=\
    \ a, edges[e.rev].cap += a;\n          return a;\n        }\n        return 0;\n\
    \      };\n      return dfs(dfs, s, lim);\n    };\n\n    while (e0.cap < 0) {\n\
    \      Cap x = find_path(a, b, -e0.cap);\n      if (x == Cap(0)) break;\n    \
    \  e0.cap += x, re0.cap -= x;\n    }\n    Cap c = -e0.cap;\n    while (c > 0 &&\
    \ a != source) {\n      Cap x = find_path(a, source, c);\n      assert(x > 0);\n\
    \      c -= x;\n    }\n    c = -e0.cap;\n    while (c > 0 && b != sink) {\n  \
    \    Cap x = find_path(sink, b, c);\n      assert(x > 0);\n      c -= x;\n   \
    \ }\n    c = -e0.cap;\n    e0.cap += c, re0.cap -= c;\n    flow_ans -= c;\n  }\n\
    \n  // frm, to, flow\n  vc<tuple<int, int, Cap>> get_flow_edges() {\n    vc<tuple<int,\
    \ int, Cap>> res;\n    FOR(v, N) {\n      FOR(i, indptr[v], indptr[v + 1]) {\n\
    \        Edge& e = edges[i];\n        Cap f = init_cap[i] - e.cap;\n        if\
    \ (f > 0) res.eb(v, e.to, f);\n      }\n    }\n    return res;\n  }\n\n  // \u6700\
    \u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\
    \u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>> cut() {\n\
    \    flow();\n    vc<int> res(N);\n    FOR(v, N) res[v] = (level[v] >= 0 ? 0 :\
    \ 1);\n    return {flow_ans, res};\n  }\n\n  // O(F(N+M)) \u304F\u3089\u3044\u4F7F\
    \u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  // simple path \u306B\u306A\u308B\n  vvc<int>\
    \ path_decomposition() {\n    flow();\n    auto edges = get_flow_edges();\n  \
    \  vvc<int> TO(N);\n    for (auto&& [frm, to, flow] : edges) {\n      FOR(flow)\
    \ TO[frm].eb(to);\n    }\n    vvc<int> res;\n    vc<int> vis(N);\n\n    FOR(flow_ans)\
    \ {\n      vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ {\n          vis[POP(path)] = 0;\n        }\n        path.eb(to), vis[to] =\
    \ 1;\n      }\n      for (auto&& v : path) vis[v] = 0;\n      res.eb(path);\n\
    \    }\n    return res;\n  }\n\n  void debug() {\n#ifdef LOCAL\n    print(\"source\"\
    , source);\n    print(\"sink\", sink);\n    print(\"edges (frm, to, cap, flow)\"\
    );\n    FOR(v, N) {\n      FOR(i, indptr[v], indptr[v + 1]) {\n        Edge& e\
    \ = edges[i];\n        Cap f = init_cap[i] - e.cap;\n        SHOW(i, v, e.to,\
    \ e.cap, f);\n      }\n    }\n#endif\n  }\n};\n"
  code: "template <typename Cap>\nstruct MaxFlow {\n  struct Edge {\n    int to, rev;\n\
    \    Cap cap;\n  };\n\n  vc<Edge> edges;\n  vc<int> indptr, level;\n  vc<Cap>\
    \ init_cap;\n  vc<tuple<int, int, Cap, Cap>> edge_pool;\n\n  const int N, source,\
    \ sink;\n  bool calculated;\n  Cap flow_ans;\n  vc<int> pos;\n\n  MaxFlow(int\
    \ N, int source, int sink)\n      : N(N), source(source), sink(sink), calculated(0),\
    \ flow_ans(0) {}\n\n  void add(int frm, int to, Cap cap, Cap rev_cap = 0) {\n\
    \    calculated = 0;\n    assert(0 <= frm && frm < N);\n    assert(0 <= to &&\
    \ to < N);\n    assert(Cap(0) <= cap);\n    edge_pool.eb(frm, to, cap, rev_cap);\n\
    \  }\n\n  void build_csr() {\n    int M = len(edge_pool);\n    indptr.assign(N\
    \ + 1, 0);\n    for (auto [a, b, c, d] : edge_pool) indptr[a + 1]++, indptr[b\
    \ + 1]++;\n    FOR(i, N) indptr[i + 1] += indptr[i];\n    vc<int> prog = indptr;\n\
    \    edges.resize(2 * M);\n    init_cap.resize(2 * M);\n    for (auto [a, b, c,\
    \ d] : edge_pool) {\n      int I1 = prog[a], I2 = prog[b];\n      edges[I1] =\
    \ Edge{b, I2, c}, init_cap[I1] = c, prog[a]++;\n      edges[I2] = Edge{a, I1,\
    \ d}, init_cap[I2] = d, prog[b]++;\n      pos.eb(I1);\n    }\n  }\n\n  Cap flow()\
    \ {\n    if (calculated) return flow_ans;\n    calculated = true;\n    if (len(edges)\
    \ != 2 * len(edge_pool)) build_csr();\n    vc<int> prog = indptr;\n    level.resize(N);\n\
    \    vc<int> que(N);\n    auto bfs = [&]() -> void {\n      fill(all(level), -1);\n\
    \      int ql = 0, qr = 0;\n      level[source] = 0, que[qr++] = source;\n   \
    \   while (ql < qr) {\n        int v = que[ql++];\n        FOR(i, indptr[v], indptr[v\
    \ + 1]) {\n          Edge& e = edges[i];\n          if (e.cap > 0 && level[e.to]\
    \ == -1) {\n            level[e.to] = level[v] + 1;\n            que[qr++] = e.to;\n\
    \            if (e.to == sink) return;\n          }\n        }\n      }\n    };\n\
    \n    // ACL \u53C2\u8003. v \u307E\u3067\u3044\u304F\u3064\u6D41\u3057\u3066\u304F\
    \u308B\u3068\u3044\u3046\u65B9\u5F0F.\n    // source-sink\u4E0A\u306B\u3042\u308B\
    \u3068\u3053\u308D\u3060\u3051\u63A2\u7D22\u3059\u308B\u306E\u3067\u3053\u3061\
    \u3089\u306E\u65B9\u304C\u9AD8\u901F\u3068\u3044\u3046\u3053\u3068\u3060\u3068\
    \u601D\u3046.\n    auto dfs = [&](auto& dfs, int v, Cap lim) -> Cap {\n      if\
    \ (v == source) return lim;\n      Cap res = 0;\n      int nxt_lv = level[v] -\
    \ 1;\n      for (int& i = prog[v]; i < indptr[v + 1]; ++i) {\n        auto& e\
    \ = edges[i];\n        if (level[e.to] != nxt_lv || edges[e.rev].cap == 0) continue;\n\
    \        Cap a = dfs(dfs, e.to, min(lim - res, edges[e.rev].cap));\n        if\
    \ (a <= 0) continue;\n        e.cap += a, edges[e.rev].cap -= a, res += a;\n \
    \       if (res == lim) return res;\n      }\n      level[v] = N;\n      return\
    \ res;\n    };\n    while (1) {\n      bfs();\n      if (level[sink] == -1) break;\n\
    \      copy(all(indptr), prog.begin());\n      Cap x = dfs(dfs, sink, infty<Cap>);\n\
    \      flow_ans += x;\n      if (flow_ans >= infty<Cap>) return infty<Cap>;\n\
    \    }\n    return flow_ans;\n  }\n\n  void change_capacity(int i, Cap after)\
    \ {\n    i = pos[i];\n    auto& e = edges[i];\n    Cap before = init_cap[i];\n\
    \    Cap f = before - e.cap;\n    init_cap[i] = after;\n    if (before < after)\
    \ {\n      calculated = (e.cap > 0);\n      e.cap += after - before;\n      return;\n\
    \    }\n    e.cap = after - f;\n    // \u5DEE\u5206\u3092\u62BC\u3057\u623B\u3059\
    \u51E6\u7406\u767A\u751F\n    if (e.cap < 0) flow_push_back(e);\n  }\n\n  void\
    \ flow_push_back(Edge& e0) {\n    auto& re0 = edges[e0.rev];\n    int a = re0.to;\n\
    \    int b = e0.to;\n    /*\n    \u8FBA e0 \u306E\u5BB9\u91CF\u304C\u6B63\u306B\
    \u306A\u308B\u3088\u3046\u306B\u623B\u3059\n    path-cycle \u5206\u89E3\u3092\u8003\
    \u3048\u308C\u3070\u3001\n    - uv \u8FBA\u3092\u542B\u3080\u30B5\u30A4\u30AF\u30EB\
    \u3092\u6D88\u3059\n    - suvt \u30D1\u30B9\u3092\u6D88\u3059\n    \u524D\u8005\
    \u306F\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067 ab \u30D1\u30B9\uFF08flow_ans \u304C\
    \u5909\u308F\u3089\u306A\u3044\uFF09\n    \u5F8C\u8005\u306F\u6B8B\u4F59\u30B0\
    \u30E9\u30D5\u3067 tb, as \u30D1\u30B9\n    */\n\n    vc<int> prog(N + 1);\n \
    \   auto find_path = [&](int s, int t, Cap lim) -> Cap {\n      vc<bool> vis(N);\n\
    \      copy(all(indptr), prog.begin());\n      auto dfs = [&](auto& dfs, int v,\
    \ Cap f) -> Cap {\n        if (v == t) return f;\n        for (int& i = prog[v];\
    \ i < indptr[v + 1]; ++i) {\n          auto& e = edges[i];\n          if (vis[e.to]\
    \ || e.cap <= Cap(0)) continue;\n          vis[e.to] = 1;\n          Cap a = dfs(dfs,\
    \ e.to, min(f, e.cap));\n          assert(a >= 0);\n          if (a == Cap(0))\
    \ continue;\n          e.cap -= a, edges[e.rev].cap += a;\n          return a;\n\
    \        }\n        return 0;\n      };\n      return dfs(dfs, s, lim);\n    };\n\
    \n    while (e0.cap < 0) {\n      Cap x = find_path(a, b, -e0.cap);\n      if\
    \ (x == Cap(0)) break;\n      e0.cap += x, re0.cap -= x;\n    }\n    Cap c = -e0.cap;\n\
    \    while (c > 0 && a != source) {\n      Cap x = find_path(a, source, c);\n\
    \      assert(x > 0);\n      c -= x;\n    }\n    c = -e0.cap;\n    while (c >\
    \ 0 && b != sink) {\n      Cap x = find_path(sink, b, c);\n      assert(x > 0);\n\
    \      c -= x;\n    }\n    c = -e0.cap;\n    e0.cap += c, re0.cap -= c;\n    flow_ans\
    \ -= c;\n  }\n\n  // frm, to, flow\n  vc<tuple<int, int, Cap>> get_flow_edges()\
    \ {\n    vc<tuple<int, int, Cap>> res;\n    FOR(v, N) {\n      FOR(i, indptr[v],\
    \ indptr[v + 1]) {\n        Edge& e = edges[i];\n        Cap f = init_cap[i] -\
    \ e.cap;\n        if (f > 0) res.eb(v, e.to, f);\n      }\n    }\n    return res;\n\
    \  }\n\n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\
    \u30AB\u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap,\
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
    \    }\n    return res;\n  }\n\n  void debug() {\n#ifdef LOCAL\n    print(\"source\"\
    , source);\n    print(\"sink\", sink);\n    print(\"edges (frm, to, cap, flow)\"\
    );\n    FOR(v, N) {\n      FOR(i, indptr[v], indptr[v + 1]) {\n        Edge& e\
    \ = edges[i];\n        Cap f = init_cap[i] - e.cap;\n        SHOW(i, v, e.to,\
    \ e.cap, f);\n      }\n    }\n#endif\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/maxflow.hpp
  requiredBy:
  - game/graph_path_game.hpp
  - flow/k_ary_optimization.hpp
  - flow/binary_optimization.hpp
  - graph/maximum_weighted_antichain.hpp
  - graph/dag_path_cover.hpp
  timestamp: '2025-09-20 19:38:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/3_yukicoder/177.test.cpp
  - test/3_yukicoder/1541.test.cpp
  - test/3_yukicoder/2320.test.cpp
  - test/4_aoj/2251_1.test.cpp
  - test/4_aoj/2835.test.cpp
  - test/4_aoj/GRL_6_A.test.cpp
documentation_of: flow/maxflow.hpp
layout: document
redirect_from:
- /library/flow/maxflow.hpp
- /library/flow/maxflow.hpp.html
title: flow/maxflow.hpp
---
