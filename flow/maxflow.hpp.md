---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: flow/binary_optimization.hpp
    title: flow/binary_optimization.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1541.test.cpp
    title: test/yukicoder/1541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/177.test.cpp
    title: test/yukicoder/177.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc193f.test.cpp
    title: test_atcoder/abc193f.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc259g.test.cpp
    title: test_atcoder/abc259g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\ntemplate <typename Cap>\nstruct MaxFlowGraph\
    \ {\n  struct Edge {\n    int to, rev;\n    Cap cap;\n  };\n\n  int N;\n  vc<tuple<int,\
    \ int, Cap, Cap>> dat;\n  vc<int> prog, level;\n  vc<int> que;\n  vc<Edge> G;\n\
    \  vc<int> indptr;\n  Cap flow_ans;\n  bool calculated;\n  bool is_prepared;\n\
    \n  MaxFlowGraph(int N) : N(N), calculated(0), is_prepared(0) {}\n\n  void add(int\
    \ frm, int to, Cap cap, Cap rev_cap = 0) {\n    assert(0 <= frm && frm < N);\n\
    \    assert(0 <= to && to < N);\n    assert(Cap(0) <= cap);\n    if (frm == to)\
    \ return;\n    dat.eb(frm, to, cap, rev_cap);\n  }\n\n  void build() {\n    assert(!is_prepared);\n\
    \    int M = len(dat);\n    is_prepared = 1;\n    indptr.assign(N, 0);\n    for\
    \ (auto&& [a, b, c, d]: dat) indptr[a]++, indptr[b]++;\n    indptr = cumsum<int>(indptr);\n\
    \    vc<int> nxt_idx = indptr;\n    G.resize(2 * M);\n    for (auto&& [a, b, c,\
    \ d]: dat) {\n      int p = nxt_idx[a]++;\n      int q = nxt_idx[b]++;\n     \
    \ G[p] = Edge{b, q, c};\n      G[q] = Edge{a, p, d};\n    }\n  }\n\n  Cap flow(int\
    \ source, int sink) {\n    assert(is_prepared);\n    if (calculated) return flow_ans;\n\
    \    calculated = true;\n    flow_ans = 0;\n    while (set_level(source, sink))\
    \ {\n      prog = indptr;\n      while (1) {\n        Cap x = flow_dfs(source,\
    \ sink, infty<Cap>);\n        if (x == 0) break;\n        flow_ans += x;\n   \
    \     chmin(flow_ans, infty<Cap>);\n        if (flow_ans == infty<Cap>) return\
    \ flow_ans;\n      }\n    }\n    return flow_ans;\n  }\n\n  // \u6700\u5C0F\u30AB\
    \u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\u3092\u8868\
    \u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>> cut(int source, int sink)\
    \ {\n    Cap f = flow(source, sink);\n    vc<int> res(N);\n    FOR(v, N) res[v]\
    \ = (level[v] >= 0 ? 0 : 1);\n    return {f, res};\n  }\n\n  // \u6B8B\u4F59\u30B0\
    \u30E9\u30D5\u306E\u8FBA\n  vc<tuple<int, int, Cap>> get_edges() {\n    vc<tuple<int,\
    \ int, Cap>> edges;\n    FOR(v, N) {\n      FOR(k, indptr[v], indptr[v + 1]) {\n\
    \        auto& e = G[k];\n        edges.eb(v, e.to, e.cap);\n      }\n    }\n\
    \    return edges;\n  }\n\nprivate:\n  bool set_level(int source, int sink) {\n\
    \    que.resize(N);\n    level.assign(N, -1);\n    level[source] = 0;\n    int\
    \ l = 0, r = 0;\n    que[r++] = source;\n    while (l < r) {\n      int v = que[l++];\n\
    \      FOR(k, indptr[v], indptr[v + 1]) {\n        auto& e = G[k];\n        if\
    \ (e.cap > 0 && level[e.to] == -1) {\n          level[e.to] = level[v] + 1;\n\
    \          if (e.to == sink) return true;\n          que[r++] = e.to;\n      \
    \  }\n      }\n    }\n    return false;\n  }\n\n  Cap flow_dfs(int v, int sink,\
    \ Cap lim) {\n    if (v == sink) return lim;\n    Cap res = 0;\n    for (int&\
    \ i = prog[v]; i < indptr[v + 1]; ++i) {\n      auto& e = G[i];\n      if (e.cap\
    \ > 0 && level[e.to] == level[v] + 1) {\n        Cap a = flow_dfs(e.to, sink,\
    \ min(lim, e.cap));\n        if (a > 0) {\n          e.cap -= a;\n          G[e.rev].cap\
    \ += a;\n          res += a;\n          lim -= a;\n          if (lim == 0) break;\n\
    \        }\n      }\n    }\n    return res;\n  }\n};\n"
  code: "template <typename Cap>\nstruct MaxFlowGraph {\n  struct Edge {\n    int\
    \ to, rev;\n    Cap cap;\n  };\n\n  int N;\n  vc<tuple<int, int, Cap, Cap>> dat;\n\
    \  vc<int> prog, level;\n  vc<int> que;\n  vc<Edge> G;\n  vc<int> indptr;\n  Cap\
    \ flow_ans;\n  bool calculated;\n  bool is_prepared;\n\n  MaxFlowGraph(int N)\
    \ : N(N), calculated(0), is_prepared(0) {}\n\n  void add(int frm, int to, Cap\
    \ cap, Cap rev_cap = 0) {\n    assert(0 <= frm && frm < N);\n    assert(0 <= to\
    \ && to < N);\n    assert(Cap(0) <= cap);\n    if (frm == to) return;\n    dat.eb(frm,\
    \ to, cap, rev_cap);\n  }\n\n  void build() {\n    assert(!is_prepared);\n   \
    \ int M = len(dat);\n    is_prepared = 1;\n    indptr.assign(N, 0);\n    for (auto&&\
    \ [a, b, c, d]: dat) indptr[a]++, indptr[b]++;\n    indptr = cumsum<int>(indptr);\n\
    \    vc<int> nxt_idx = indptr;\n    G.resize(2 * M);\n    for (auto&& [a, b, c,\
    \ d]: dat) {\n      int p = nxt_idx[a]++;\n      int q = nxt_idx[b]++;\n     \
    \ G[p] = Edge{b, q, c};\n      G[q] = Edge{a, p, d};\n    }\n  }\n\n  Cap flow(int\
    \ source, int sink) {\n    assert(is_prepared);\n    if (calculated) return flow_ans;\n\
    \    calculated = true;\n    flow_ans = 0;\n    while (set_level(source, sink))\
    \ {\n      prog = indptr;\n      while (1) {\n        Cap x = flow_dfs(source,\
    \ sink, infty<Cap>);\n        if (x == 0) break;\n        flow_ans += x;\n   \
    \     chmin(flow_ans, infty<Cap>);\n        if (flow_ans == infty<Cap>) return\
    \ flow_ans;\n      }\n    }\n    return flow_ans;\n  }\n\n  // \u6700\u5C0F\u30AB\
    \u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\u3092\u8868\
    \u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>> cut(int source, int sink)\
    \ {\n    Cap f = flow(source, sink);\n    vc<int> res(N);\n    FOR(v, N) res[v]\
    \ = (level[v] >= 0 ? 0 : 1);\n    return {f, res};\n  }\n\n  // \u6B8B\u4F59\u30B0\
    \u30E9\u30D5\u306E\u8FBA\n  vc<tuple<int, int, Cap>> get_edges() {\n    vc<tuple<int,\
    \ int, Cap>> edges;\n    FOR(v, N) {\n      FOR(k, indptr[v], indptr[v + 1]) {\n\
    \        auto& e = G[k];\n        edges.eb(v, e.to, e.cap);\n      }\n    }\n\
    \    return edges;\n  }\n\nprivate:\n  bool set_level(int source, int sink) {\n\
    \    que.resize(N);\n    level.assign(N, -1);\n    level[source] = 0;\n    int\
    \ l = 0, r = 0;\n    que[r++] = source;\n    while (l < r) {\n      int v = que[l++];\n\
    \      FOR(k, indptr[v], indptr[v + 1]) {\n        auto& e = G[k];\n        if\
    \ (e.cap > 0 && level[e.to] == -1) {\n          level[e.to] = level[v] + 1;\n\
    \          if (e.to == sink) return true;\n          que[r++] = e.to;\n      \
    \  }\n      }\n    }\n    return false;\n  }\n\n  Cap flow_dfs(int v, int sink,\
    \ Cap lim) {\n    if (v == sink) return lim;\n    Cap res = 0;\n    for (int&\
    \ i = prog[v]; i < indptr[v + 1]; ++i) {\n      auto& e = G[i];\n      if (e.cap\
    \ > 0 && level[e.to] == level[v] + 1) {\n        Cap a = flow_dfs(e.to, sink,\
    \ min(lim, e.cap));\n        if (a > 0) {\n          e.cap -= a;\n          G[e.rev].cap\
    \ += a;\n          res += a;\n          lim -= a;\n          if (lim == 0) break;\n\
    \        }\n      }\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/maxflow.hpp
  requiredBy:
  - flow/binary_optimization.hpp
  timestamp: '2023-05-22 05:00:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test_atcoder/abc193f.test.cpp
  - test_atcoder/abc259g.test.cpp
  - test/yukicoder/177.test.cpp
  - test/yukicoder/1541.test.cpp
  - test/aoj/GRL_6_A.test.cpp
documentation_of: flow/maxflow.hpp
layout: document
redirect_from:
- /library/flow/maxflow.hpp
- /library/flow/maxflow.hpp.html
title: flow/maxflow.hpp
---
