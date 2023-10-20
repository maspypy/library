---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1541.test.cpp
    title: test/yukicoder/1541.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2320.test.cpp
    title: test/yukicoder/2320.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc193f.test.cpp
    title: test_atcoder/abc193f.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc259g.test.cpp
    title: test_atcoder/abc259g.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ 0;\n      res.eb(path);\n    }\n    return res;\n  }\n\nprivate:\n  bool set_level()\
    \ {\n    que.resize(N);\n    level.assign(N, -1);\n    level[source] = 0;\n  \
    \  int l = 0, r = 0;\n    que[r++] = source;\n    while (l < r) {\n      int v\
    \ = que[l++];\n      for (auto&& e: edges[v]) {\n        if (e.cap > 0 && level[e.to]\
    \ == -1) {\n          level[e.to] = level[v] + 1;\n          if (e.to == sink)\
    \ return true;\n          que[r++] = e.to;\n        }\n      }\n    }\n    return\
    \ false;\n  }\n\n  Cap flow_dfs(int v, Cap lim) {\n    if (v == sink) return lim;\n\
    \    Cap res = 0;\n    for (int& i = prog[v]; i < len(edges[v]); ++i) {\n    \
    \  auto& e = edges[v][i];\n      if (e.cap > 0 && level[e.to] == level[v] + 1)\
    \ {\n        Cap a = flow_dfs(e.to, min(lim, e.cap));\n        if (a > 0) {\n\
    \          e.cap -= a, e.flow += a;\n          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow\
    \ -= a;\n          res += a;\n          lim -= a;\n          if (lim == 0) break;\n\
    \        }\n      }\n    }\n    return res;\n  }\n};\n#line 2 \"flow/binary_optimization.hpp\"\
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
    \  pair<T, vc<int>> calc() {\n    MaxFlow<T> G(nxt, source, sink);\n    for (auto&&\
    \ [key, cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm, to, cap);\n\
    \    }\n\n    auto [val, cut] = G.cut();\n    val += base_cost;\n    chmin(val,\
    \ infty<T>);\n    cut.resize(n);\n    if (!MINIMIZE) val = -val;\n    return {val,\
    \ cut};\n  }\n\n  void debug() {\n    print(\"base_cost\", base_cost);\n    print(\"\
    source=\", source, \"sink=\", sink);\n    for (auto&& [key, cap]: edges) print(key,\
    \ cap);\n  }\n\nprivate:\n  void add_edge(int i, int j, T t) {\n    assert(t >=\
    \ 0);\n    if (t == 0) return;\n    pair<int, int> key = mp(i, j);\n    edges[key]\
    \ += t;\n    chmin(edges[key], infty<T>);\n  }\n\n  void _add_1(int i, T x0, T\
    \ x1) {\n    if (x0 <= x1) {\n      base_cost += x0;\n      add_edge(source, i,\
    \ x1 - x0);\n    } else {\n      base_cost += x1;\n      add_edge(i, sink, x0\
    \ - x1);\n    }\n  }\n\n  void _add_2(int i, int j, T x00, T x01, T x10, T x11)\
    \ {\n    assert(x00 + x11 <= x01 + x10);\n    _add_1(i, x00, x10);\n    _add_1(j,\
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
    \  pair<T, vc<int>> calc() {\n    MaxFlow<T> G(nxt, source, sink);\n    for (auto&&\
    \ [key, cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm, to, cap);\n\
    \    }\n\n    auto [val, cut] = G.cut();\n    val += base_cost;\n    chmin(val,\
    \ infty<T>);\n    cut.resize(n);\n    if (!MINIMIZE) val = -val;\n    return {val,\
    \ cut};\n  }\n\n  void debug() {\n    print(\"base_cost\", base_cost);\n    print(\"\
    source=\", source, \"sink=\", sink);\n    for (auto&& [key, cap]: edges) print(key,\
    \ cap);\n  }\n\nprivate:\n  void add_edge(int i, int j, T t) {\n    assert(t >=\
    \ 0);\n    if (t == 0) return;\n    pair<int, int> key = mp(i, j);\n    edges[key]\
    \ += t;\n    chmin(edges[key], infty<T>);\n  }\n\n  void _add_1(int i, T x0, T\
    \ x1) {\n    if (x0 <= x1) {\n      base_cost += x0;\n      add_edge(source, i,\
    \ x1 - x0);\n    } else {\n      base_cost += x1;\n      add_edge(i, sink, x0\
    \ - x1);\n    }\n  }\n\n  void _add_2(int i, int j, T x00, T x01, T x10, T x11)\
    \ {\n    assert(x00 + x11 <= x01 + x10);\n    _add_1(i, x00, x10);\n    _add_1(j,\
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
  timestamp: '2023-09-16 07:20:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test_atcoder/abc193f.test.cpp
  - test_atcoder/abc259g.test.cpp
  - test/yukicoder/2320.test.cpp
  - test/yukicoder/1541.test.cpp
documentation_of: flow/binary_optimization.hpp
layout: document
redirect_from:
- /library/flow/binary_optimization.hpp
- /library/flow/binary_optimization.hpp.html
title: flow/binary_optimization.hpp
---
