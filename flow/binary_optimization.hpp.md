---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\n\n// \u9802\u70B9\u6570\u306F\u6E21\u3055\
    \u306A\u304F\u3066\u3088\u3044\ntemplate <typename Cap>\nstruct MaxFlowGraph {\n\
    \  const Cap INF;\n  struct Edge {\n    int frm, to;\n    Cap cap;\n    int idx;\n\
    \  };\n\n  int N;\n  vc<int> indptr;\n  vc<Edge> edges;\n  vc<Cap> edge_flow;\n\
    \n  vc<Edge> csr_edges;\n  vc<int> rev;\n  vc<int> level, deq;\n  Cap flow_ans;\n\
    \  bool calculated;\n\n  MaxFlowGraph(Cap INF) : INF(INF), N(0), calculated(0)\
    \ {}\n\n  void add(int frm, int to, Cap cap) {\n    chmax(N, frm + 1);\n    chmax(N,\
    \ to + 1);\n    edges.eb(Edge({frm, to, cap, int(edges.size())}));\n  }\n\n  Cap\
    \ flow(int source, int sink) {\n    if (calculated) return flow_ans;\n    calculated\
    \ = true;\n    _build();\n    flow_ans = 0;\n    while (set_level(source, sink))\
    \ {\n      while (1) {\n        Cap x = flow_dfs(source, sink, INF);\n       \
    \ if (x == 0) break;\n        flow_ans += x;\n        chmin(flow_ans, INF);\n\
    \        if (flow_ans == INF) return flow_ans;\n      }\n    }\n    return flow_ans;\n\
    \  }\n\n  vc<tuple<int, int, Cap>> get_edges() {\n    vc<tuple<int, int, Cap>>\
    \ res;\n    for (auto&& e: edges) {\n      Cap f = edge_flow[e.idx];\n      if\
    \ (f > Cap(0)) res.eb(e.frm, e.to, f);\n    }\n    return res;\n  }\n\n  // \u6700\
    \u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\
    \u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>> cut(int source,\
    \ int sink) {\n    Cap f = flow(source, sink);\n    set_level(source, sink);\n\
    \    vc<int> res(N);\n    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);\n    return\
    \ {f, res};\n  }\n\n  void debug() {\n    for (auto&& e: edges) print(e.frm, e.to,\
    \ e.cap);\n  }\n\nprivate:\n  void _build() {\n    indptr.resize(N + 1);\n   \
    \ level.resize(N);\n    deq.resize(N);\n    int M = len(edges);\n    for (auto&&\
    \ e: edges) { indptr[e.frm + 1]++, indptr[e.to + 1]++; }\n    FOR(v, N) indptr[v\
    \ + 1] += indptr[v];\n    auto counter = indptr;\n\n    edge_flow.resize(M);\n\
    \    csr_edges.resize(2 * M);\n    rev.resize(2 * M);\n    for (auto&& e: edges)\
    \ {\n      int i = counter[e.frm], j = counter[e.to];\n      rev[i] = j, rev[j]\
    \ = i;\n      csr_edges[i] = {e.frm, e.to, e.cap, e.idx};\n      csr_edges[j]\
    \ = {e.to, e.frm, Cap(0), ~e.idx};\n      counter[e.frm]++, counter[e.to]++;\n\
    \    }\n  }\n\n  bool set_level(int source, int sink) {\n    // bfs\n    fill(all(level),\
    \ -1);\n    int l = 0, r = 0;\n    deq[r++] = source;\n    level[source] = 0;\n\
    \    while (l < r) {\n      int v = deq[l++];\n      FOR3(i, indptr[v], indptr[v\
    \ + 1]) {\n        auto& e = csr_edges[i];\n        if (e.cap == 0 || level[e.to]\
    \ >= 0) continue;\n        level[e.to] = level[v] + 1;\n        if (e.to == sink)\
    \ return true;\n        deq[r++] = e.to;\n      }\n    }\n    return false;\n\
    \  }\n\n  Cap flow_dfs(int v, int sink, Cap lim) {\n    if (v == sink) return\
    \ lim;\n    FOR3(i, indptr[v], indptr[v + 1]) {\n      auto& e = csr_edges[i];\n\
    \      if (e.cap == 0 || level[v] >= level[e.to]) continue;\n      Cap x = flow_dfs(e.to,\
    \ sink, min(lim, e.cap));\n      if (x > Cap(0)) {\n        e.cap -= x;\n    \
    \    int j = rev[i];\n        csr_edges[j].cap += x;\n        if (e.idx >= 0)\n\
    \          edge_flow[e.idx] += x;\n        else\n          edge_flow[~e.idx] -=\
    \ x;\n        return x;\n      }\n    }\n    level[v] = -1;\n    return 0;\n \
    \ }\n};\n#line 2 \"flow/binary_optimization.hpp\"\n\ntemplate <typename T>\nstruct\
    \ Binary_Optimization {\n  int n;\n  int nxt;\n  int source, sink;\n  T base_cost;\n\
    \  T INF;\n  map<pair<int, int>, T> edges;\n\n  Binary_Optimization(int n, T INF)\
    \ : n(n), base_cost(0), INF(INF) {\n    source = n;\n    sink = n + 1;\n    nxt\
    \ = n + 2;\n  }\n\n  // xi \u3092 0, 1 \u306B\u3059\u308B\u3068\u304D\u306B\u304B\
    \u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\n  void add_1(int\
    \ i, T x0, T x1) {\n    if (x0 <= x1) {\n      base_cost += x0;\n      add_edge(source,\
    \ i, x1 - x0);\n    } else {\n      base_cost += x1;\n      add_edge(i, sink,\
    \ x0 - x1);\n    }\n  }\n\n  // (xi,xj) = (00,01,10,11) \u3068\u3059\u308B\u3068\
    \u304D\u306B\u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\
    \n  // \u52A3\u30E2 x00 + x11 <= x10 + x10 \u306B\u306A\u3063\u3066\u3044\u308B\
    \u5FC5\u8981\u304C\u3042\u308B\n  void add_2(int i, int j, T x00, T x01, T x10,\
    \ T x11) {\n    assert(i != j);\n    assert(0 <= i && i < n);\n    assert(0 <=\
    \ j && j < n);\n    assert(x00 + x11 <= x01 + x10);\n    add_1(i, x00, x10);\n\
    \    add_1(j, 0, x11 - x10);\n    add_edge(i, j, x01 + x10 - x00 - x11);\n  }\n\
    \n  // (xi,xj,xk) = (000,001,010,011,100,101,110,111)\n  // \u3068\u3059\u308B\
    \u3068\u304D\u306B\u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\
    \u308B\n  // \u52A3\u30E2\u306B\u306A\u3063\u3066\u3044\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\n  void add_3(int i, int j, int k, T x000, T x001, T x010, T x011,\
    \ T x100,\n             T x101, T x110, T x111) {\n    assert(i != j && i != k\
    \ && j != k);\n    assert(0 <= i && i < n);\n    assert(0 <= j && j < n);\n  \
    \  assert(0 <= k && k < n);\n    T p = x000 - x100 - x010 - x001 + x110 + x101\
    \ + x011 - x111;\n    if (p > 0) {\n      base_cost += x000;\n      add_1(i, 0,\
    \ x100 - x000);\n      add_1(j, 0, x010 - x000);\n      add_1(k, 0, x001 - x000);\n\
    \      add_2(i, j, 0, 0, 0, x000 + x110 - x100 - x010);\n      add_2(i, k, 0,\
    \ 0, 0, x000 + x101 - x100 - x001);\n      add_2(j, k, 0, 0, 0, x000 + x011 -\
    \ x010 - x001);\n      // \u3042\u3068\u306F\u3001111 \u306E\u3068\u304D\u306B\
    \u5229\u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      //\
    \ 111 \u4EE5\u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(i, nxt, p);\n\
    \      add_edge(j, nxt, p);\n      add_edge(k, nxt, p);\n      add_edge(nxt, sink,\
    \ p);\n      ++nxt;\n    } else {\n      p = -p;\n      base_cost += x111;\n \
    \     add_1(i, x011 - x111, 0);\n      add_1(i, x101 - x111, 0);\n      add_1(i,\
    \ x110 - x111, 0);\n      add_2(i, j, x111 + x001 - x011 - x101, 0, 0, 0);\n \
    \     add_2(i, k, x111 + x010 - x011 - x110, 0, 0, 0);\n      add_2(j, k, x111\
    \ + x100 - x101 - x110, 0, 0, 0);\n      // 000 \u306E\u3068\u304D\u306B\u5229\
    \u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      // 000 \u4EE5\
    \u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(nxt, i, p);\n      add_edge(nxt,\
    \ j, p);\n      add_edge(nxt, k, p);\n      add_edge(source, nxt, p);\n      ++nxt;\n\
    \    }\n  }\n\n  // \u6700\u5C0F\u5024\u304A\u3088\u3073\u300101 \u5217\u3092\u8FD4\
    \u3059\n  pair<T, vc<int>> calc() {\n    MaxFlowGraph<T> G(INF);\n    for (auto&&\
    \ [key, cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm, to, cap);\n\
    \    }\n    auto [val, cut] = G.cut(source, sink);\n    val += base_cost;\n  \
    \  chmin(val, INF);\n    cut.resize(n);\n    return {val, cut};\n  }\n\n  void\
    \ debug() {\n    print(\"base_cost\", base_cost);\n    print(\"source=\", source,\
    \ \"sink=\", sink);\n    for (auto&& [key, cap]: edges) print(key, cap);\n  }\n\
    \nprivate:\n  void add_edge(int i, int j, T t) {\n    assert(t >= 0);\n    if\
    \ (t == 0) return;\n    pair<int, int> key = mp(i, j);\n    edges[key] += t;\n\
    \    chmin(edges[key], INF);\n  }\n};\n"
  code: "#include \"flow/maxflow.hpp\"\n\ntemplate <typename T>\nstruct Binary_Optimization\
    \ {\n  int n;\n  int nxt;\n  int source, sink;\n  T base_cost;\n  T INF;\n  map<pair<int,\
    \ int>, T> edges;\n\n  Binary_Optimization(int n, T INF) : n(n), base_cost(0),\
    \ INF(INF) {\n    source = n;\n    sink = n + 1;\n    nxt = n + 2;\n  }\n\n  //\
    \ xi \u3092 0, 1 \u306B\u3059\u308B\u3068\u304D\u306B\u304B\u304B\u308B\u30B3\u30B9\
    \u30C8\u3092\u8FFD\u52A0\u3059\u308B\n  void add_1(int i, T x0, T x1) {\n    if\
    \ (x0 <= x1) {\n      base_cost += x0;\n      add_edge(source, i, x1 - x0);\n\
    \    } else {\n      base_cost += x1;\n      add_edge(i, sink, x0 - x1);\n   \
    \ }\n  }\n\n  // (xi,xj) = (00,01,10,11) \u3068\u3059\u308B\u3068\u304D\u306B\u304B\
    \u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\n  // \u52A3\u30E2\
    \ x00 + x11 <= x10 + x10 \u306B\u306A\u3063\u3066\u3044\u308B\u5FC5\u8981\u304C\
    \u3042\u308B\n  void add_2(int i, int j, T x00, T x01, T x10, T x11) {\n    assert(i\
    \ != j);\n    assert(0 <= i && i < n);\n    assert(0 <= j && j < n);\n    assert(x00\
    \ + x11 <= x01 + x10);\n    add_1(i, x00, x10);\n    add_1(j, 0, x11 - x10);\n\
    \    add_edge(i, j, x01 + x10 - x00 - x11);\n  }\n\n  // (xi,xj,xk) = (000,001,010,011,100,101,110,111)\n\
    \  // \u3068\u3059\u308B\u3068\u304D\u306B\u304B\u304B\u308B\u30B3\u30B9\u30C8\
    \u3092\u8FFD\u52A0\u3059\u308B\n  // \u52A3\u30E2\u306B\u306A\u3063\u3066\u3044\
    \u308B\u5FC5\u8981\u304C\u3042\u308B\n  void add_3(int i, int j, int k, T x000,\
    \ T x001, T x010, T x011, T x100,\n             T x101, T x110, T x111) {\n  \
    \  assert(i != j && i != k && j != k);\n    assert(0 <= i && i < n);\n    assert(0\
    \ <= j && j < n);\n    assert(0 <= k && k < n);\n    T p = x000 - x100 - x010\
    \ - x001 + x110 + x101 + x011 - x111;\n    if (p > 0) {\n      base_cost += x000;\n\
    \      add_1(i, 0, x100 - x000);\n      add_1(j, 0, x010 - x000);\n      add_1(k,\
    \ 0, x001 - x000);\n      add_2(i, j, 0, 0, 0, x000 + x110 - x100 - x010);\n \
    \     add_2(i, k, 0, 0, 0, x000 + x101 - x100 - x001);\n      add_2(j, k, 0, 0,\
    \ 0, x000 + x011 - x010 - x001);\n      // \u3042\u3068\u306F\u3001111 \u306E\u3068\
    \u304D\u306B\u5229\u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -=\
    \ p;\n      // 111 \u4EE5\u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(i,\
    \ nxt, p);\n      add_edge(j, nxt, p);\n      add_edge(k, nxt, p);\n      add_edge(nxt,\
    \ sink, p);\n      ++nxt;\n    } else {\n      p = -p;\n      base_cost += x111;\n\
    \      add_1(i, x011 - x111, 0);\n      add_1(i, x101 - x111, 0);\n      add_1(i,\
    \ x110 - x111, 0);\n      add_2(i, j, x111 + x001 - x011 - x101, 0, 0, 0);\n \
    \     add_2(i, k, x111 + x010 - x011 - x110, 0, 0, 0);\n      add_2(j, k, x111\
    \ + x100 - x101 - x110, 0, 0, 0);\n      // 000 \u306E\u3068\u304D\u306B\u5229\
    \u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      // 000 \u4EE5\
    \u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(nxt, i, p);\n      add_edge(nxt,\
    \ j, p);\n      add_edge(nxt, k, p);\n      add_edge(source, nxt, p);\n      ++nxt;\n\
    \    }\n  }\n\n  // \u6700\u5C0F\u5024\u304A\u3088\u3073\u300101 \u5217\u3092\u8FD4\
    \u3059\n  pair<T, vc<int>> calc() {\n    MaxFlowGraph<T> G(INF);\n    for (auto&&\
    \ [key, cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm, to, cap);\n\
    \    }\n    auto [val, cut] = G.cut(source, sink);\n    val += base_cost;\n  \
    \  chmin(val, INF);\n    cut.resize(n);\n    return {val, cut};\n  }\n\n  void\
    \ debug() {\n    print(\"base_cost\", base_cost);\n    print(\"source=\", source,\
    \ \"sink=\", sink);\n    for (auto&& [key, cap]: edges) print(key, cap);\n  }\n\
    \nprivate:\n  void add_edge(int i, int j, T t) {\n    assert(t >= 0);\n    if\
    \ (t == 0) return;\n    pair<int, int> key = mp(i, j);\n    edges[key] += t;\n\
    \    chmin(edges[key], INF);\n  }\n};\n"
  dependsOn:
  - flow/maxflow.hpp
  isVerificationFile: false
  path: flow/binary_optimization.hpp
  requiredBy: []
  timestamp: '2022-05-04 01:14:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/binary_optimization.hpp
layout: document
redirect_from:
- /library/flow/binary_optimization.hpp
- /library/flow/binary_optimization.hpp.html
title: flow/binary_optimization.hpp
---
