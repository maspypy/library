---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1541.test.cpp
    title: test/yukicoder/1541.test.cpp
  - icon: ':x:'
    path: test_atcoder/abc259g.test.cpp
    title: test_atcoder/abc259g.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/maxflow.hpp\"\ntemplate <typename Cap>\nstruct MaxFlowGraph\
    \ {\n  struct Edge {\n    int to, rev;\n    Cap cap;\n  };\n\n  int N;\n  vvc<Edge>\
    \ G;\n  vc<int> prog, level;\n  Cap flow_ans;\n  bool calculated;\n\n  MaxFlowGraph(int\
    \ N) : N(N), calculated(0) {}\n\n  void add(int frm, int to, Cap cap) {\n    assert(0\
    \ <= frm && frm < N);\n    assert(0 <= to && to < N);\n    assert(Cap(0) <= cap);\n\
    \    if (len(G) < N) G.resize(N);\n    G[frm].eb(Edge{to, (int)G[to].size(), cap});\n\
    \    G[to].eb(Edge{frm, (int)G[frm].size() - 1, 0});\n  }\n\n  Cap flow(int source,\
    \ int sink) {\n    if (calculated) return flow_ans;\n    calculated = true;\n\
    \    chmax(N, source + 1);\n    chmax(N, sink + 1);\n    G.resize(N);\n    flow_ans\
    \ = 0;\n    while (set_level(source, sink)) {\n      fill(all(prog), 0);\n   \
    \   prog.assign(N, 0);\n      while (1) {\n        Cap x = flow_dfs(source, sink,\
    \ infty<Cap>);\n        if (x == 0) break;\n        flow_ans += x;\n        chmin(flow_ans,\
    \ infty<Cap>);\n        if (flow_ans == infty<Cap>) return flow_ans;\n      }\n\
    \    }\n    return flow_ans;\n  }\n\n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\
    \u5024\u304A\u3088\u3073\u3001\u30AB\u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\
    \u8FD4\u3059\n  pair<Cap, vc<int>> cut(int source, int sink) {\n    Cap f = flow(source,\
    \ sink);\n    vc<int> res(N);\n    FOR(v, N) res[v] = (level[v] >= 0 ? 0 : 1);\n\
    \    return {f, res};\n  }\n\n  // \u6B8B\u4F59\u30B0\u30E9\u30D5\u306E\u8FBA\n\
    \  vc<tuple<int, int, Cap>> get_edges() {\n    vc<tuple<int, int, Cap>> edges;\n\
    \    FOR(v, N) for (auto&& e: G[v]) { edges.eb(v, e.to, e.cap); }\n    return\
    \ edges;\n  }\n\nprivate:\n  bool set_level(int source, int sink) {\n    level.assign(N,\
    \ -1);\n    level[source] = 0;\n    queue<int> que;\n    que.push(source);\n \
    \   while (!que.empty()) {\n      int v = que.front();\n      que.pop();\n   \
    \   for (auto&& e: G[v]) {\n        if (e.cap > 0 && level[e.to] == -1) {\n  \
    \        level[e.to] = level[v] + 1;\n          if (e.to == sink) return true;\n\
    \          que.push(e.to);\n        }\n      }\n    }\n    return false;\n  }\n\
    \n  Cap flow_dfs(int v, int sink, Cap lim) {\n    if (v == sink) return lim;\n\
    \    Cap res = 0;\n    for (int& i = prog[v]; i < (int)G[v].size(); ++i) {\n \
    \     auto& e = G[v][i];\n      if (e.cap > 0 && level[e.to] == level[v] + 1)\
    \ {\n        Cap a = flow_dfs(e.to, sink, min(lim, e.cap));\n        if (a > 0)\
    \ {\n          e.cap -= a;\n          G[e.to][e.rev].cap += a;\n          res\
    \ += a;\n          lim -= a;\n          if (lim == 0) break;\n        }\n    \
    \  }\n    }\n    return res;\n  }\n};\n#line 2 \"flow/binary_optimization.hpp\"\
    \n\ntemplate <typename T, bool MINIMIZE>\nstruct Binary_Optimization {\n  int\
    \ n;\n  int nxt;\n  int source, sink;\n  T base_cost;\n  map<pair<int, int>, T>\
    \ edges;\n\n  Binary_Optimization(int n) : n(n), base_cost(0) {\n    source =\
    \ n;\n    sink = n + 1;\n    nxt = n + 2;\n  }\n\n  // xi \u3092 0, 1 \u306B\u3059\
    \u308B\u3068\u304D\u306B\u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\
    \u3059\u308B\u3002\n  void add_1(int i, T x0, T x1) {\n    assert(0 <= i && i\
    \ < n);\n    if (!MINIMIZE) { x0 = -x0, x1 = -x1; }\n    _add_1(i, x0, x1);\n\
    \  }\n\n  // (xi,xj) = (00,01,10,11) \u3068\u3059\u308B\u3068\u304D\u306B\u304B\
    \u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\u3002\n  // \u30B3\
    \u30B9\u30C8\u304C\u52A3\u30E2 x00 + x11 <= x10 + x10 \u306B\u306A\u3063\u3066\
    \u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n  // \u7279\u306B\u3001\u5BFE\
    \u89D2\u6210\u5206\u306B\u5229\u5F97\u3092\u4E0E\u3048\u308B\u3053\u3068\u304C\
    \u3067\u304D\u308B\u3002\n  void add_2(int i, int j, T x00, T x01, T x10, T x11)\
    \ {\n    assert(i != j);\n    assert(0 <= i && i < n);\n    assert(0 <= j && j\
    \ < n);\n    if (!MINIMIZE) {\n      x00 = -x00, x01 = -x01;\n      x10 = -x10,\
    \ x11 = -x11;\n    }\n    _add_2(i, j, x00, x01, x10, x11);\n  }\n\n  // (xi,xj,xk)\
    \ = (000,001,010,011,100,101,110,111)\n  // \u3068\u3059\u308B\u3068\u304D\u306B\
    \u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\u3002\u52A3\
    \u30E2\u306B\u306A\u3063\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\
    \n  // \u7279\u306B\u3001000 \u3084 111 \u306B\u5229\u5F97\u3092\u4E0E\u3048\u308B\
    \u3053\u3068\u304C\u3067\u304D\u308B\u3002\n  void add_3(int i, int j, int k,\
    \ T x000, T x001, T x010, T x011, T x100,\n             T x101, T x110, T x111)\
    \ {\n    assert(i != j && i != k && j != k);\n    assert(0 <= i && i < n);\n \
    \   assert(0 <= j && j < n);\n    assert(0 <= k && k < n);\n    if (!MINIMIZE)\
    \ {\n      x000 = -x000, x001 = -x001;\n      x010 = -x010, x011 = -x011;\n  \
    \    x100 = -x100, x101 = -x101;\n      x110 = -x110, x111 = -x111;\n    }\n \
    \   _add_3(i, j, k, x000, x001, x010, x011, x100, x101, x110, x111);\n  }\n\n\
    \  // \u6700\u5C0F\u5024\u304A\u3088\u3073\u300101 \u5217\u3092\u8FD4\u3059\n\
    \  pair<T, vc<int>> calc() {\n    MaxFlowGraph<T> G(nxt);\n    for (auto&& [key,\
    \ cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm, to, cap);\n  \
    \  }\n\n    auto [val, cut] = G.cut(source, sink);\n    val += base_cost;\n  \
    \  chmin(val, infty<T>);\n    cut.resize(n);\n    if (!MINIMIZE) val = -val;\n\
    \    return {val, cut};\n  }\n\n  void debug() {\n    print(\"base_cost\", base_cost);\n\
    \    print(\"source=\", source, \"sink=\", sink);\n    for (auto&& [key, cap]:\
    \ edges) print(key, cap);\n  }\n\nprivate:\n  void add_edge(int i, int j, T t)\
    \ {\n    assert(t >= 0);\n    if (t == 0) return;\n    pair<int, int> key = mp(i,\
    \ j);\n    edges[key] += t;\n    chmin(edges[key], infty<T>);\n  }\n\n  void _add_1(int\
    \ i, T x0, T x1) {\n    if (x0 <= x1) {\n      base_cost += x0;\n      add_edge(source,\
    \ i, x1 - x0);\n    } else {\n      base_cost += x1;\n      add_edge(i, sink,\
    \ x0 - x1);\n    }\n  }\n\n  void _add_2(int i, int j, T x00, T x01, T x10, T\
    \ x11) {\n    assert(x00 + x11 <= x01 + x10);\n    _add_1(i, x00, x10);\n    _add_1(j,\
    \ 0, x11 - x10);\n    add_edge(i, j, x01 + x10 - x00 - x11);\n  }\n\n  void _add_3(int\
    \ i, int j, int k, T x000, T x001, T x010, T x011, T x100,\n              T x101,\
    \ T x110, T x111) {\n    T p = x000 - x100 - x010 - x001 + x110 + x101 + x011\
    \ - x111;\n    if (p > 0) {\n      base_cost += x000;\n      _add_1(i, 0, x100\
    \ - x000);\n      _add_1(j, 0, x010 - x000);\n      _add_1(k, 0, x001 - x000);\n\
    \      _add_2(i, j, 0, 0, 0, x000 + x110 - x100 - x010);\n      _add_2(i, k, 0,\
    \ 0, 0, x000 + x101 - x100 - x001);\n      _add_2(j, k, 0, 0, 0, x000 + x011 -\
    \ x010 - x001);\n      // \u3042\u3068\u306F\u3001111 \u306E\u3068\u304D\u306B\
    \u5229\u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      //\
    \ 111 \u4EE5\u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(i, nxt, p);\n\
    \      add_edge(j, nxt, p);\n      add_edge(k, nxt, p);\n      add_edge(nxt, sink,\
    \ p);\n      ++nxt;\n    } else {\n      p = -p;\n      base_cost += x111;\n \
    \     _add_1(i, x011 - x111, 0);\n      _add_1(i, x101 - x111, 0);\n      _add_1(i,\
    \ x110 - x111, 0);\n      _add_2(i, j, x111 + x001 - x011 - x101, 0, 0, 0);\n\
    \      _add_2(i, k, x111 + x010 - x011 - x110, 0, 0, 0);\n      _add_2(j, k, x111\
    \ + x100 - x101 - x110, 0, 0, 0);\n      // 000 \u306E\u3068\u304D\u306B\u5229\
    \u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      // 000 \u4EE5\
    \u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(nxt, i, p);\n      add_edge(nxt,\
    \ j, p);\n      add_edge(nxt, k, p);\n      add_edge(source, nxt, p);\n      ++nxt;\n\
    \    }\n  }\n};\n"
  code: "#include \"flow/maxflow.hpp\"\n\ntemplate <typename T, bool MINIMIZE>\nstruct\
    \ Binary_Optimization {\n  int n;\n  int nxt;\n  int source, sink;\n  T base_cost;\n\
    \  map<pair<int, int>, T> edges;\n\n  Binary_Optimization(int n) : n(n), base_cost(0)\
    \ {\n    source = n;\n    sink = n + 1;\n    nxt = n + 2;\n  }\n\n  // xi \u3092\
    \ 0, 1 \u306B\u3059\u308B\u3068\u304D\u306B\u304B\u304B\u308B\u30B3\u30B9\u30C8\
    \u3092\u8FFD\u52A0\u3059\u308B\u3002\n  void add_1(int i, T x0, T x1) {\n    assert(0\
    \ <= i && i < n);\n    if (!MINIMIZE) { x0 = -x0, x1 = -x1; }\n    _add_1(i, x0,\
    \ x1);\n  }\n\n  // (xi,xj) = (00,01,10,11) \u3068\u3059\u308B\u3068\u304D\u306B\
    \u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\u3002\n  //\
    \ \u30B3\u30B9\u30C8\u304C\u52A3\u30E2 x00 + x11 <= x10 + x10 \u306B\u306A\u3063\
    \u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\u308B\u3002\n  // \u7279\u306B\u3001\
    \u5BFE\u89D2\u6210\u5206\u306B\u5229\u5F97\u3092\u4E0E\u3048\u308B\u3053\u3068\
    \u304C\u3067\u304D\u308B\u3002\n  void add_2(int i, int j, T x00, T x01, T x10,\
    \ T x11) {\n    assert(i != j);\n    assert(0 <= i && i < n);\n    assert(0 <=\
    \ j && j < n);\n    if (!MINIMIZE) {\n      x00 = -x00, x01 = -x01;\n      x10\
    \ = -x10, x11 = -x11;\n    }\n    _add_2(i, j, x00, x01, x10, x11);\n  }\n\n \
    \ // (xi,xj,xk) = (000,001,010,011,100,101,110,111)\n  // \u3068\u3059\u308B\u3068\
    \u304D\u306B\u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\
    \u3002\u52A3\u30E2\u306B\u306A\u3063\u3066\u3044\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\u3002\n  // \u7279\u306B\u3001000 \u3084 111 \u306B\u5229\u5F97\u3092\u4E0E\
    \u3048\u308B\u3053\u3068\u304C\u3067\u304D\u308B\u3002\n  void add_3(int i, int\
    \ j, int k, T x000, T x001, T x010, T x011, T x100,\n             T x101, T x110,\
    \ T x111) {\n    assert(i != j && i != k && j != k);\n    assert(0 <= i && i <\
    \ n);\n    assert(0 <= j && j < n);\n    assert(0 <= k && k < n);\n    if (!MINIMIZE)\
    \ {\n      x000 = -x000, x001 = -x001;\n      x010 = -x010, x011 = -x011;\n  \
    \    x100 = -x100, x101 = -x101;\n      x110 = -x110, x111 = -x111;\n    }\n \
    \   _add_3(i, j, k, x000, x001, x010, x011, x100, x101, x110, x111);\n  }\n\n\
    \  // \u6700\u5C0F\u5024\u304A\u3088\u3073\u300101 \u5217\u3092\u8FD4\u3059\n\
    \  pair<T, vc<int>> calc() {\n    MaxFlowGraph<T> G(nxt);\n    for (auto&& [key,\
    \ cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm, to, cap);\n  \
    \  }\n\n    auto [val, cut] = G.cut(source, sink);\n    val += base_cost;\n  \
    \  chmin(val, infty<T>);\n    cut.resize(n);\n    if (!MINIMIZE) val = -val;\n\
    \    return {val, cut};\n  }\n\n  void debug() {\n    print(\"base_cost\", base_cost);\n\
    \    print(\"source=\", source, \"sink=\", sink);\n    for (auto&& [key, cap]:\
    \ edges) print(key, cap);\n  }\n\nprivate:\n  void add_edge(int i, int j, T t)\
    \ {\n    assert(t >= 0);\n    if (t == 0) return;\n    pair<int, int> key = mp(i,\
    \ j);\n    edges[key] += t;\n    chmin(edges[key], infty<T>);\n  }\n\n  void _add_1(int\
    \ i, T x0, T x1) {\n    if (x0 <= x1) {\n      base_cost += x0;\n      add_edge(source,\
    \ i, x1 - x0);\n    } else {\n      base_cost += x1;\n      add_edge(i, sink,\
    \ x0 - x1);\n    }\n  }\n\n  void _add_2(int i, int j, T x00, T x01, T x10, T\
    \ x11) {\n    assert(x00 + x11 <= x01 + x10);\n    _add_1(i, x00, x10);\n    _add_1(j,\
    \ 0, x11 - x10);\n    add_edge(i, j, x01 + x10 - x00 - x11);\n  }\n\n  void _add_3(int\
    \ i, int j, int k, T x000, T x001, T x010, T x011, T x100,\n              T x101,\
    \ T x110, T x111) {\n    T p = x000 - x100 - x010 - x001 + x110 + x101 + x011\
    \ - x111;\n    if (p > 0) {\n      base_cost += x000;\n      _add_1(i, 0, x100\
    \ - x000);\n      _add_1(j, 0, x010 - x000);\n      _add_1(k, 0, x001 - x000);\n\
    \      _add_2(i, j, 0, 0, 0, x000 + x110 - x100 - x010);\n      _add_2(i, k, 0,\
    \ 0, 0, x000 + x101 - x100 - x001);\n      _add_2(j, k, 0, 0, 0, x000 + x011 -\
    \ x010 - x001);\n      // \u3042\u3068\u306F\u3001111 \u306E\u3068\u304D\u306B\
    \u5229\u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      //\
    \ 111 \u4EE5\u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(i, nxt, p);\n\
    \      add_edge(j, nxt, p);\n      add_edge(k, nxt, p);\n      add_edge(nxt, sink,\
    \ p);\n      ++nxt;\n    } else {\n      p = -p;\n      base_cost += x111;\n \
    \     _add_1(i, x011 - x111, 0);\n      _add_1(i, x101 - x111, 0);\n      _add_1(i,\
    \ x110 - x111, 0);\n      _add_2(i, j, x111 + x001 - x011 - x101, 0, 0, 0);\n\
    \      _add_2(i, k, x111 + x010 - x011 - x110, 0, 0, 0);\n      _add_2(j, k, x111\
    \ + x100 - x101 - x110, 0, 0, 0);\n      // 000 \u306E\u3068\u304D\u306B\u5229\
    \u5F97 p \u3092\u8FFD\u52A0\u3059\u308B\n      base_cost -= p;\n      // 000 \u4EE5\
    \u5916\u3060\u3068\u30B3\u30B9\u30C8 p\n      add_edge(nxt, i, p);\n      add_edge(nxt,\
    \ j, p);\n      add_edge(nxt, k, p);\n      add_edge(source, nxt, p);\n      ++nxt;\n\
    \    }\n  }\n};\n"
  dependsOn:
  - flow/maxflow.hpp
  isVerificationFile: false
  path: flow/binary_optimization.hpp
  requiredBy: []
  timestamp: '2023-02-02 01:52:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1541.test.cpp
  - test_atcoder/abc259g.test.cpp
documentation_of: flow/binary_optimization.hpp
layout: document
redirect_from:
- /library/flow/binary_optimization.hpp
- /library/flow/binary_optimization.hpp.html
title: flow/binary_optimization.hpp
---
