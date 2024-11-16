---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: flow/maxflow.hpp
    title: flow/maxflow.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/5_atcoder/arc107.test.cpp
    title: test/5_atcoder/arc107.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/k_ary_optimization.hpp\"\n\n#line 1 \"flow/maxflow.hpp\"\
    \n// incremental \u306B\u8FBA\u3092\u8FFD\u52A0\u3057\u3066\u3088\u3044\n// \u8FBA\
    \u306E\u5BB9\u91CF\u306E\u5909\u66F4\u304C\u53EF\u80FD\n// \u5909\u66F4\u3059\u308B\
    \ capacity \u304C F \u306E\u3068\u304D\u3001O((N+M)|F|) \u6642\u9593\u3067\u66F4\
    \u65B0\ntemplate <typename Cap>\nstruct MaxFlow {\n  struct Edge {\n    int to,\
    \ rev;\n    Cap cap; // \u6B8B\u3063\u3066\u3044\u308B\u5BB9\u91CF. \u3057\u305F\
    \u304C\u3063\u3066 cap+flow \u304C\u5B9A\u6570.\n    Cap flow = 0;\n  };\n\n \
    \ const int N, source, sink;\n  vvc<Edge> edges;\n  vc<pair<int, int>> pos;\n\
    \  vc<int> prog, level;\n  vc<int> que;\n  bool calculated;\n\n  MaxFlow(int N,\
    \ int source, int sink)\n      : N(N),\n        source(source),\n        sink(sink),\n\
    \        edges(N),\n        calculated(0),\n        flow_ans(0) {}\n\n  void add(int\
    \ frm, int to, Cap cap, Cap rev_cap = 0) {\n    calculated = 0;\n    assert(0\
    \ <= frm && frm < N);\n    assert(0 <= to && to < N);\n    assert(Cap(0) <= cap);\n\
    \    int a = len(edges[frm]);\n    int b = (frm == to ? a + 1 : len(edges[to]));\n\
    \    pos.eb(frm, a);\n    edges[frm].eb(Edge{to, b, cap, 0});\n    edges[to].eb(Edge{frm,\
    \ a, rev_cap, 0});\n  }\n\n  void change_capacity(int i, Cap after) {\n    auto\
    \ [frm, idx] = pos[i];\n    auto& e = edges[frm][idx];\n    Cap before = e.cap\
    \ + e.flow;\n    if (before < after) {\n      calculated = (e.cap > 0);\n    \
    \  e.cap += after - before;\n      return;\n    }\n    e.cap = after - e.flow;\n\
    \    // \u5DEE\u5206\u3092\u62BC\u3057\u623B\u3059\u51E6\u7406\u767A\u751F\n \
    \   if (e.cap < 0) flow_push_back(e);\n  }\n\n  void flow_push_back(Edge& e0)\
    \ {\n    auto& re0 = edges[e0.to][e0.rev];\n    int a = re0.to;\n    int b = e0.to;\n\
    \    /*\n    \u8FBA e0 \u306E\u5BB9\u91CF\u304C\u6B63\u306B\u306A\u308B\u3088\u3046\
    \u306B\u623B\u3059\n    path-cycle \u5206\u89E3\u3092\u8003\u3048\u308C\u3070\u3001\
    \n    - uv \u8FBA\u3092\u542B\u3080\u30B5\u30A4\u30AF\u30EB\u3092\u6D88\u3059\n\
    \    - suvt \u30D1\u30B9\u3092\u6D88\u3059\n    \u524D\u8005\u306F\u6B8B\u4F59\
    \u30B0\u30E9\u30D5\u3067 ab \u30D1\u30B9\uFF08flow_ans \u304C\u5909\u308F\u3089\
    \u306A\u3044\uFF09\n    \u5F8C\u8005\u306F\u6B8B\u4F59\u30B0\u30E9\u30D5\u3067\
    \ tb, as \u30D1\u30B9\n    */\n\n    auto find_path = [&](int s, int t, Cap lim)\
    \ -> Cap {\n      vc<bool> vis(N);\n      prog.assign(N, 0);\n      auto dfs =\
    \ [&](auto& dfs, int v, Cap f) -> Cap {\n        if (v == t) return f;\n     \
    \   for (int& i = prog[v]; i < len(edges[v]); ++i) {\n          auto& e = edges[v][i];\n\
    \          if (vis[e.to] || e.cap <= Cap(0)) continue;\n          vis[e.to] =\
    \ 1;\n          Cap a = dfs(dfs, e.to, min(f, e.cap));\n          assert(a >=\
    \ 0);\n          if (a == Cap(0)) continue;\n          e.cap -= a, e.flow += a;\n\
    \          edges[e.to][e.rev].cap += a, edges[e.to][e.rev].flow -= a;\n      \
    \    return a;\n        }\n        return 0;\n      };\n      return dfs(dfs,\
    \ s, lim);\n    };\n\n    while (e0.cap < 0) {\n      Cap x = find_path(a, b,\
    \ -e0.cap);\n      if (x == Cap(0)) break;\n      e0.cap += x, e0.flow -= x;\n\
    \      re0.cap -= x, re0.flow += x;\n    }\n    Cap c = -e0.cap;\n    while (c\
    \ > 0 && a != source) {\n      Cap x = find_path(a, source, c);\n      assert(x\
    \ > 0);\n      c -= x;\n    }\n    c = -e0.cap;\n    while (c > 0 && b != sink)\
    \ {\n      Cap x = find_path(sink, b, c);\n      assert(x > 0);\n      c -= x;\n\
    \    }\n    c = -e0.cap;\n    e0.cap += c, e0.flow -= c;\n    re0.cap -= c, re0.flow\
    \ += c;\n    flow_ans -= c;\n  }\n\n  // frm, to, flow\n  vc<tuple<int, int, Cap>>\
    \ get_flow_edges() {\n    vc<tuple<int, int, Cap>> res;\n    FOR(frm, N) {\n \
    \     for (auto&& e: edges[frm]) {\n        if (e.flow <= 0) continue;\n     \
    \   res.eb(frm, e.to, e.flow);\n      }\n    }\n    return res;\n  }\n\n  vc<bool>\
    \ vis;\n\n  // \u5DEE\u5206\u3067\u306F\u306A\u304F\u3053\u308C\u307E\u3067\u306E\
    \u7DCF\u91CF\n  Cap flow() {\n    if (calculated) return flow_ans;\n    calculated\
    \ = true;\n    while (set_level()) {\n      prog.assign(N, 0);\n      while (1)\
    \ {\n        Cap x = flow_dfs(source, infty<Cap>);\n        if (x == 0) break;\n\
    \        flow_ans += x;\n        chmin(flow_ans, infty<Cap>);\n        if (flow_ans\
    \ == infty<Cap>) return flow_ans;\n      }\n    }\n    return flow_ans;\n  }\n\
    \n  // \u6700\u5C0F\u30AB\u30C3\u30C8\u306E\u5024\u304A\u3088\u3073\u3001\u30AB\
    \u30C3\u30C8\u3092\u8868\u3059 01 \u5217\u3092\u8FD4\u3059\n  pair<Cap, vc<int>>\
    \ cut() {\n    flow();\n    vc<int> res(N);\n    FOR(v, N) res[v] = (level[v]\
    \ >= 0 ? 0 : 1);\n    return {flow_ans, res};\n  }\n\n  // O(F(N+M)) \u304F\u3089\
    \u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  // simple path \u306B\u306A\
    \u308B\n  vvc<int> path_decomposition() {\n    flow();\n    auto edges = get_flow_edges();\n\
    \    vvc<int> TO(N);\n    for (auto&& [frm, to, flow]: edges) { FOR(flow) TO[frm].eb(to);\
    \ }\n    vvc<int> res;\n    vc<int> vis(N);\n\n    FOR(flow_ans) {\n      vc<int>\
    \ path = {source};\n      vis[source] = 1;\n      while (path.back() != sink)\
    \ {\n        int to = POP(TO[path.back()]);\n        while (vis[to]) { vis[POP(path)]\
    \ = 0; }\n        path.eb(to), vis[to] = 1;\n      }\n      for (auto&& v: path)\
    \ vis[v] = 0;\n      res.eb(path);\n    }\n    return res;\n  }\n\n  void debug()\
    \ {\n    print(\"source\", source);\n    print(\"sink\", sink);\n    print(\"\
    edges (frm, to, cap, flow)\");\n    FOR(v, N) {\n      for (auto& e: edges[v])\
    \ {\n        if (e.cap == 0 && e.flow == 0) continue;\n        print(v, e.to,\
    \ e.cap, e.flow);\n      }\n    }\n  }\n\nprivate:\n  Cap flow_ans;\n\n  bool\
    \ set_level() {\n    que.resize(N);\n    level.assign(N, -1);\n    level[source]\
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
    \  }\n};\n#line 3 \"flow/k_ary_optimization.hpp\"\n\n// ABC347G\ntemplate <typename\
    \ T, bool MINIMIZE>\nstruct K_ary_Optimization {\n  int n;\n  vc<int> ks;\n  vvc<int>\
    \ idx;\n  map<pair<int, int>, T> edges;\n  int source, sink, nxt;\n  T base_cost;\n\
    \n  // idx[i][j] \u304C cut \u306E source \u5074\uFF1Aval[i]>=j\n  K_ary_Optimization(vc<int>\
    \ ks) : n(len(ks)), ks(ks), base_cost(0) {\n    source = 0, sink = 1, nxt = 2;\n\
    \    for (auto& k: ks) {\n      assert(k >= 1);\n      vc<int> I(k + 1);\n   \
    \   I[0] = source, I[k] = sink;\n      FOR(i, 1, k) { I[i] = nxt++; }\n      idx.eb(I);\n\
    \      if (k >= 3) { FOR(j, 1, k - 1) add_edge(I[j + 1], I[j], infty<T>); }\n\
    \    }\n  }\n\n  // xi \u3092 0, 1, ..., k-1 \u306B\u3059\u308B\u3068\u304D\u306B\
    \u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\u3002\n  void\
    \ add_1(int i, vc<T> cost) {\n    assert(0 <= i && i < n && len(cost) == ks[i]);\n\
    \    if (!MINIMIZE) {\n      for (auto& x: cost) x = -x;\n    }\n    _add_1(i,\
    \ cost);\n  }\n\n  void add_2(int i, int j, vvc<T> cost) {\n    assert(0 <= i\
    \ && i < n && 0 <= j && j < n && i != j);\n    int H = ks[i], W = ks[j];\n   \
    \ assert(len(cost) == H);\n    FOR(a, H) assert(len(cost[a]) == W);\n    if (!MINIMIZE)\
    \ { FOR(a, H) FOR(b, W) cost[a][b] = -cost[a][b]; }\n    _add_2(i, j, cost);\n\
    \  }\n\n  // \u6700\u5C0F\u5024\u304A\u3088\u3073\u3001[0,k) \u5217\u3092\u8FD4\
    \u3059\n  pair<T, vc<int>> calc() {\n    MaxFlow<T> G(nxt, source, sink);\n  \
    \  for (auto&& [key, cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm,\
    \ to, cap);\n    }\n\n    auto [val, cut] = G.cut();\n    val += base_cost;\n\
    \    vc<int> ANS(n);\n    FOR(i, n) {\n      FOR(j, 1, ks[i]) { ANS[i] += 1 -\
    \ cut[idx[i][j]]; }\n    }\n    if (!MINIMIZE) val = -val;\n    return {val, ANS};\n\
    \  }\n\nprivate:\n  void add_base(T x) {\n    base_cost += x;\n    assert(-infty<T>\
    \ < base_cost && base_cost < infty<T>);\n  }\n\n  void add_edge(int i, int j,\
    \ T t) {\n    assert(t >= 0);\n    if (t == 0) return;\n    pair<int, int> key\
    \ = mp(i, j);\n    edges[key] += t;\n    assert(edges[key] <= infty<T>);\n  }\n\
    \n  void _add_1(int i, vc<T> cost) {\n    add_base(cost[0]);\n    FOR_R(j, ks[i])\
    \ cost[j] -= cost[0];\n    FOR(j, 1, ks[i]) {\n      T x = cost[j] - cost[j -\
    \ 1];\n      // j \u4EE5\u4E0A\u306B\u3059\u308B\u3068 x\n      if (x > 0) add_edge(idx[i][j],\
    \ sink, x);\n      if (x < 0) add_base(x), add_edge(source, idx[i][j], -x);\n\
    \    }\n  }\n  void _add_2(int i, int j, vvc<T> cost) {\n    int H = ks[i], W\
    \ = ks[j];\n    _add_1(j, cost[0]);\n    FOR_R(a, H) FOR(b, W) cost[a][b] -= cost[0][b];\n\
    \    vc<T> tmp(H);\n    FOR(a, H) tmp[a] = cost[a][W - 1];\n    _add_1(i, tmp);\n\
    \    FOR(a, H) FOR(b, W) cost[a][b] -= tmp[a];\n    FOR(a, 1, H) FOR(b, W - 1)\
    \ {\n      T x = cost[a][b] + cost[a - 1][b + 1] - cost[a - 1][b] - cost[a][b\
    \ + 1];\n      assert(x >= 0); // monge\n      add_edge(idx[i][a], idx[j][b +\
    \ 1], x);\n    }\n  }\n};\n"
  code: "\n#include \"flow/maxflow.hpp\"\n\n// ABC347G\ntemplate <typename T, bool\
    \ MINIMIZE>\nstruct K_ary_Optimization {\n  int n;\n  vc<int> ks;\n  vvc<int>\
    \ idx;\n  map<pair<int, int>, T> edges;\n  int source, sink, nxt;\n  T base_cost;\n\
    \n  // idx[i][j] \u304C cut \u306E source \u5074\uFF1Aval[i]>=j\n  K_ary_Optimization(vc<int>\
    \ ks) : n(len(ks)), ks(ks), base_cost(0) {\n    source = 0, sink = 1, nxt = 2;\n\
    \    for (auto& k: ks) {\n      assert(k >= 1);\n      vc<int> I(k + 1);\n   \
    \   I[0] = source, I[k] = sink;\n      FOR(i, 1, k) { I[i] = nxt++; }\n      idx.eb(I);\n\
    \      if (k >= 3) { FOR(j, 1, k - 1) add_edge(I[j + 1], I[j], infty<T>); }\n\
    \    }\n  }\n\n  // xi \u3092 0, 1, ..., k-1 \u306B\u3059\u308B\u3068\u304D\u306B\
    \u304B\u304B\u308B\u30B3\u30B9\u30C8\u3092\u8FFD\u52A0\u3059\u308B\u3002\n  void\
    \ add_1(int i, vc<T> cost) {\n    assert(0 <= i && i < n && len(cost) == ks[i]);\n\
    \    if (!MINIMIZE) {\n      for (auto& x: cost) x = -x;\n    }\n    _add_1(i,\
    \ cost);\n  }\n\n  void add_2(int i, int j, vvc<T> cost) {\n    assert(0 <= i\
    \ && i < n && 0 <= j && j < n && i != j);\n    int H = ks[i], W = ks[j];\n   \
    \ assert(len(cost) == H);\n    FOR(a, H) assert(len(cost[a]) == W);\n    if (!MINIMIZE)\
    \ { FOR(a, H) FOR(b, W) cost[a][b] = -cost[a][b]; }\n    _add_2(i, j, cost);\n\
    \  }\n\n  // \u6700\u5C0F\u5024\u304A\u3088\u3073\u3001[0,k) \u5217\u3092\u8FD4\
    \u3059\n  pair<T, vc<int>> calc() {\n    MaxFlow<T> G(nxt, source, sink);\n  \
    \  for (auto&& [key, cap]: edges) {\n      auto [frm, to] = key;\n      G.add(frm,\
    \ to, cap);\n    }\n\n    auto [val, cut] = G.cut();\n    val += base_cost;\n\
    \    vc<int> ANS(n);\n    FOR(i, n) {\n      FOR(j, 1, ks[i]) { ANS[i] += 1 -\
    \ cut[idx[i][j]]; }\n    }\n    if (!MINIMIZE) val = -val;\n    return {val, ANS};\n\
    \  }\n\nprivate:\n  void add_base(T x) {\n    base_cost += x;\n    assert(-infty<T>\
    \ < base_cost && base_cost < infty<T>);\n  }\n\n  void add_edge(int i, int j,\
    \ T t) {\n    assert(t >= 0);\n    if (t == 0) return;\n    pair<int, int> key\
    \ = mp(i, j);\n    edges[key] += t;\n    assert(edges[key] <= infty<T>);\n  }\n\
    \n  void _add_1(int i, vc<T> cost) {\n    add_base(cost[0]);\n    FOR_R(j, ks[i])\
    \ cost[j] -= cost[0];\n    FOR(j, 1, ks[i]) {\n      T x = cost[j] - cost[j -\
    \ 1];\n      // j \u4EE5\u4E0A\u306B\u3059\u308B\u3068 x\n      if (x > 0) add_edge(idx[i][j],\
    \ sink, x);\n      if (x < 0) add_base(x), add_edge(source, idx[i][j], -x);\n\
    \    }\n  }\n  void _add_2(int i, int j, vvc<T> cost) {\n    int H = ks[i], W\
    \ = ks[j];\n    _add_1(j, cost[0]);\n    FOR_R(a, H) FOR(b, W) cost[a][b] -= cost[0][b];\n\
    \    vc<T> tmp(H);\n    FOR(a, H) tmp[a] = cost[a][W - 1];\n    _add_1(i, tmp);\n\
    \    FOR(a, H) FOR(b, W) cost[a][b] -= tmp[a];\n    FOR(a, 1, H) FOR(b, W - 1)\
    \ {\n      T x = cost[a][b] + cost[a - 1][b + 1] - cost[a - 1][b] - cost[a][b\
    \ + 1];\n      assert(x >= 0); // monge\n      add_edge(idx[i][a], idx[j][b +\
    \ 1], x);\n    }\n  }\n};"
  dependsOn:
  - flow/maxflow.hpp
  isVerificationFile: false
  path: flow/k_ary_optimization.hpp
  requiredBy: []
  timestamp: '2024-04-19 22:50:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/5_atcoder/arc107.test.cpp
documentation_of: flow/k_ary_optimization.hpp
layout: document
redirect_from:
- /library/flow/k_ary_optimization.hpp
- /library/flow/k_ary_optimization.hpp.html
title: flow/k_ary_optimization.hpp
---
