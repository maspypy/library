---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/assignment_mcf.test.cpp
    title: test/library_checker/graph/assignment_mcf.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1288.test.cpp
    title: test/yukicoder/1288.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1301.test.cpp
    title: test/yukicoder/1301.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1324.test.cpp
    title: test/yukicoder/1324.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1341.test.cpp
    title: test/yukicoder/1341.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1676.test.cpp
    title: test/yukicoder/1676.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1678.test.cpp
    title: test/yukicoder/1678.test.cpp
  - icon: ':heavy_check_mark:'
    path: test_atcoder/abc214h.test.cpp
    title: test_atcoder/abc214h.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/mincostflow.hpp\"\n\n// atcoder library \u306E\u3082\
    \u306E\u3092\u6539\u5909\nnamespace internal {\ntemplate <class E>\nstruct csr\
    \ {\n  vector<int> start;\n  vector<E> elist;\n  explicit csr(int n, const vector<pair<int,\
    \ E>>& edges)\n      : start(n + 1), elist(edges.size()) {\n    for (auto e: edges)\
    \ { start[e.first + 1]++; }\n    for (int i = 1; i <= n; i++) { start[i] += start[i\
    \ - 1]; }\n    auto counter = start;\n    for (auto e: edges) { elist[counter[e.first]++]\
    \ = e.second; }\n  }\n};\n\ntemplate <class T>\nstruct simple_queue {\n  vector<T>\
    \ payload;\n  int pos = 0;\n  void reserve(int n) { payload.reserve(n); }\n  int\
    \ size() const { return int(payload.size()) - pos; }\n  bool empty() const { return\
    \ pos == int(payload.size()); }\n  void push(const T& t) { payload.push_back(t);\
    \ }\n  T& front() { return payload[pos]; }\n  void clear() {\n    payload.clear();\n\
    \    pos = 0;\n  }\n  void pop() { pos++; }\n};\n\n} // namespace internal\n\n\
    /*\n\u30FBatcoder library \u3092\u3059\u3053\u3057\u6539\u5909\u3057\u305F\u3082\
    \u306E\n\u30FBDAG = true \u3067\u3042\u308C\u3070\u3001\u8CA0\u8FBA OK \uFF08\
    1 \u56DE\u76EE\u306E\u6700\u77ED\u8DEF\u3092 dp \u3067\u884C\u3046\uFF09\n\u305F\
    \u3060\u3057\u3001\u9802\u70B9\u756A\u53F7\u306F toposort \u3055\u308C\u3066\u3044\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\u3002\n*/\ntemplate\
    \ <class Cap = int, class Cost = ll, bool DAG = false>\nstruct Min_Cost_Flow {\n\
    public:\n  Min_Cost_Flow() {}\n  explicit Min_Cost_Flow(int n, int source, int\
    \ sink)\n      : n(n), source(source), sink(sink) {\n    assert(0 <= source &&\
    \ source < n);\n    assert(0 <= sink && sink < n);\n    assert(source != sink);\n\
    \  }\n\n  // frm, to, cap, cost\n  int add(int frm, int to, Cap cap, Cost cost)\
    \ {\n    assert(0 <= frm && frm < n);\n    assert(0 <= to && to < n);\n    assert(0\
    \ <= cap);\n    assert(DAG || 0 <= cost);\n    if (DAG) assert(frm < to);\n  \
    \  int m = int(_edges.size());\n    _edges.push_back({frm, to, cap, 0, cost});\n\
    \    return m;\n  }\n\n  void debug() {\n    print(\"flow graph\");\n    print(\"\
    frm, to, cap, cost\");\n    for (auto&& [frm, to, cap, flow, cost]: _edges) {\n\
    \      print(frm, to, cap, cost);\n    }\n  }\n\n  struct edge {\n    int frm,\
    \ to;\n    Cap cap, flow;\n    Cost cost;\n  };\n\n  edge get_edge(int i) {\n\
    \    int m = int(_edges.size());\n    assert(0 <= i && i < m);\n    return _edges[i];\n\
    \  }\n  vector<edge> edges() { return _edges; }\n\n  // (\u6D41\u91CF, \u8CBB\u7528\
    )\n  pair<Cap, Cost> flow() { return flow(infty<Cap>); }\n  // (\u6D41\u91CF,\
    \ \u8CBB\u7528)\n  pair<Cap, Cost> flow(Cap flow_limit) { return slope(flow_limit).back();\
    \ }\n  vector<pair<Cap, Cost>> slope() { return slope(infty<Cap>); }\n  vector<pair<Cap,\
    \ Cost>> slope(Cap flow_limit) {\n    int m = int(_edges.size());\n    vector<int>\
    \ edge_idx(m);\n\n    auto g = [&]() {\n      vector<int> degree(n), redge_idx(m);\n\
    \      vector<pair<int, _edge>> elist;\n      elist.reserve(2 * m);\n      for\
    \ (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ = degree[e.frm]++;\n        redge_idx[i] = degree[e.to]++;\n        elist.push_back({e.frm,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n        elist.push_back({e.to, {e.frm,\
    \ -1, e.flow, -e.cost}});\n      }\n      auto _g = internal::csr<_edge>(n, elist);\n\
    \      for (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ += _g.start[e.frm];\n        redge_idx[i] += _g.start[e.to];\n        _g.elist[edge_idx[i]].rev\
    \ = redge_idx[i];\n        _g.elist[redge_idx[i]].rev = edge_idx[i];\n      }\n\
    \      return _g;\n    }();\n\n    auto result = slope(g, flow_limit);\n\n   \
    \ for (int i = 0; i < m; i++) {\n      auto e = g.elist[edge_idx[i]];\n      _edges[i].flow\
    \ = _edges[i].cap - e.cap;\n    }\n\n    return result;\n  }\n\n  // O(F(N+M))\
    \ \u304F\u3089\u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  vvc<int> path_decomposition()\
    \ {\n    vvc<int> TO(n);\n    for (auto&& e: edges()) { FOR(e.flow) TO[e.frm].eb(e.to);\
    \ }\n    vvc<int> res;\n    vc<int> vis(n);\n\n    while (!TO[source].empty())\
    \ {\n      vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ { vis[POP(path)] = 0; }\n        path.eb(to), vis[to] = 1;\n      }\n      for\
    \ (auto&& v: path) vis[v] = 0;\n      res.eb(path);\n    }\n    return res;\n\
    \  }\n\nprivate:\n  int n, source, sink;\n  vector<edge> _edges;\n\n  // inside\
    \ edge\n  struct _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\
    \n  vector<pair<Cap, Cost>> slope(internal::csr<_edge>& g, Cap flow_limit) {\n\
    \    if (DAG) assert(source == 0 && sink == n - 1);\n    vector<pair<Cost, Cost>>\
    \ dual_dist(n);\n    vector<int> prev_e(n);\n    vector<bool> vis(n);\n    struct\
    \ Q {\n      Cost key;\n      int to;\n      bool operator<(Q r) const { return\
    \ key > r.key; }\n    };\n    vector<int> que_min;\n    vector<Q> que;\n    auto\
    \ dual_ref = [&]() {\n      for (int i = 0; i < n; i++) { dual_dist[i].second\
    \ = infty<Cost>; }\n      fill(vis.begin(), vis.end(), false);\n      que_min.clear();\n\
    \      que.clear();\n\n      // que[0..heap_r) was heapified\n      size_t heap_r\
    \ = 0;\n\n      dual_dist[source].second = 0;\n      que_min.push_back(source);\n\
    \      while (!que_min.empty() || !que.empty()) {\n        int v;\n        if\
    \ (!que_min.empty()) {\n          v = que_min.back();\n          que_min.pop_back();\n\
    \        } else {\n          while (heap_r < que.size()) {\n            heap_r++;\n\
    \            push_heap(que.begin(), que.begin() + heap_r);\n          }\n    \
    \      v = que.front().to;\n          pop_heap(que.begin(), que.end());\n    \
    \      que.pop_back();\n          heap_r--;\n        }\n        if (vis[v]) continue;\n\
    \        vis[v] = true;\n        if (v == sink) break;\n        Cost dual_v =\
    \ dual_dist[v].first, dist_v = dual_dist[v].second;\n        for (int i = g.start[v];\
    \ i < g.start[v + 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap)\
    \ continue;\n          Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n\
    \          if (dual_dist[e.to].second > dist_v + cost) {\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n            if (dist_to == dist_v) {\n             \
    \ que_min.push_back(e.to);\n            } else {\n              que.push_back(Q{dist_to,\
    \ e.to});\n            }\n          }\n        }\n      }\n      if (!vis[sink])\
    \ { return false; }\n\n      for (int v = 0; v < n; v++) {\n        if (!vis[v])\
    \ continue;\n        dual_dist[v].first -= dual_dist[sink].second - dual_dist[v].second;\n\
    \      }\n      return true;\n    };\n\n    auto dual_ref_dag = [&]() {\n    \
    \  FOR(i, n) dual_dist[i].se = infty<Cost>;\n      dual_dist[source].se = 0;\n\
    \      fill(vis.begin(), vis.end(), false);\n      vis[0] = true;\n\n      FOR(v,\
    \ n) {\n        if (!vis[v]) continue;\n        Cost dual_v = dual_dist[v].fi,\
    \ dist_v = dual_dist[v].se;\n        for (int i = g.start[v]; i < g.start[v +\
    \ 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n\
    \          Cost cost = e.cost - dual_dist[e.to].fi + dual_v;\n          if (dual_dist[e.to].se\
    \ > dist_v + cost) {\n            vis[e.to] = true;\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n          }\n        }\n      }\n      if (!vis[sink])\
    \ { return false; }\n\n      for (int v = 0; v < n; v++) {\n        if (!vis[v])\
    \ continue;\n        dual_dist[v].fi -= dual_dist[sink].se - dual_dist[v].se;\n\
    \      }\n      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0,\
    \ prev_cost_per_flow = -1;\n    vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \    while (flow < flow_limit) {\n      if (DAG && flow == 0) {\n        if (!dual_ref_dag())\
    \ break;\n      } else {\n        if (!dual_ref()) break;\n      }\n      Cap\
    \ c = flow_limit - flow;\n      for (int v = sink; v != source; v = g.elist[prev_e[v]].to)\
    \ {\n        c = min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      }\n     \
    \ for (int v = sink; v != source; v = g.elist[prev_e[v]].to) {\n        auto&\
    \ e = g.elist[prev_e[v]];\n        e.cap += c;\n        g.elist[e.rev].cap -=\
    \ c;\n      }\n      Cost d = -dual_dist[source].first;\n      flow += c;\n  \
    \    cost += c * d;\n      if (prev_cost_per_flow == d) { result.pop_back(); }\n\
    \      result.push_back({flow, cost});\n      prev_cost_per_flow = d;\n    }\n\
    \    return result;\n  }\n};\n"
  code: "#pragma once\n\n// atcoder library \u306E\u3082\u306E\u3092\u6539\u5909\n\
    namespace internal {\ntemplate <class E>\nstruct csr {\n  vector<int> start;\n\
    \  vector<E> elist;\n  explicit csr(int n, const vector<pair<int, E>>& edges)\n\
    \      : start(n + 1), elist(edges.size()) {\n    for (auto e: edges) { start[e.first\
    \ + 1]++; }\n    for (int i = 1; i <= n; i++) { start[i] += start[i - 1]; }\n\
    \    auto counter = start;\n    for (auto e: edges) { elist[counter[e.first]++]\
    \ = e.second; }\n  }\n};\n\ntemplate <class T>\nstruct simple_queue {\n  vector<T>\
    \ payload;\n  int pos = 0;\n  void reserve(int n) { payload.reserve(n); }\n  int\
    \ size() const { return int(payload.size()) - pos; }\n  bool empty() const { return\
    \ pos == int(payload.size()); }\n  void push(const T& t) { payload.push_back(t);\
    \ }\n  T& front() { return payload[pos]; }\n  void clear() {\n    payload.clear();\n\
    \    pos = 0;\n  }\n  void pop() { pos++; }\n};\n\n} // namespace internal\n\n\
    /*\n\u30FBatcoder library \u3092\u3059\u3053\u3057\u6539\u5909\u3057\u305F\u3082\
    \u306E\n\u30FBDAG = true \u3067\u3042\u308C\u3070\u3001\u8CA0\u8FBA OK \uFF08\
    1 \u56DE\u76EE\u306E\u6700\u77ED\u8DEF\u3092 dp \u3067\u884C\u3046\uFF09\n\u305F\
    \u3060\u3057\u3001\u9802\u70B9\u756A\u53F7\u306F toposort \u3055\u308C\u3066\u3044\
    \u308B\u3053\u3068\u3092\u4EEE\u5B9A\u3057\u3066\u3044\u308B\u3002\n*/\ntemplate\
    \ <class Cap = int, class Cost = ll, bool DAG = false>\nstruct Min_Cost_Flow {\n\
    public:\n  Min_Cost_Flow() {}\n  explicit Min_Cost_Flow(int n, int source, int\
    \ sink)\n      : n(n), source(source), sink(sink) {\n    assert(0 <= source &&\
    \ source < n);\n    assert(0 <= sink && sink < n);\n    assert(source != sink);\n\
    \  }\n\n  // frm, to, cap, cost\n  int add(int frm, int to, Cap cap, Cost cost)\
    \ {\n    assert(0 <= frm && frm < n);\n    assert(0 <= to && to < n);\n    assert(0\
    \ <= cap);\n    assert(DAG || 0 <= cost);\n    if (DAG) assert(frm < to);\n  \
    \  int m = int(_edges.size());\n    _edges.push_back({frm, to, cap, 0, cost});\n\
    \    return m;\n  }\n\n  void debug() {\n    print(\"flow graph\");\n    print(\"\
    frm, to, cap, cost\");\n    for (auto&& [frm, to, cap, flow, cost]: _edges) {\n\
    \      print(frm, to, cap, cost);\n    }\n  }\n\n  struct edge {\n    int frm,\
    \ to;\n    Cap cap, flow;\n    Cost cost;\n  };\n\n  edge get_edge(int i) {\n\
    \    int m = int(_edges.size());\n    assert(0 <= i && i < m);\n    return _edges[i];\n\
    \  }\n  vector<edge> edges() { return _edges; }\n\n  // (\u6D41\u91CF, \u8CBB\u7528\
    )\n  pair<Cap, Cost> flow() { return flow(infty<Cap>); }\n  // (\u6D41\u91CF,\
    \ \u8CBB\u7528)\n  pair<Cap, Cost> flow(Cap flow_limit) { return slope(flow_limit).back();\
    \ }\n  vector<pair<Cap, Cost>> slope() { return slope(infty<Cap>); }\n  vector<pair<Cap,\
    \ Cost>> slope(Cap flow_limit) {\n    int m = int(_edges.size());\n    vector<int>\
    \ edge_idx(m);\n\n    auto g = [&]() {\n      vector<int> degree(n), redge_idx(m);\n\
    \      vector<pair<int, _edge>> elist;\n      elist.reserve(2 * m);\n      for\
    \ (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ = degree[e.frm]++;\n        redge_idx[i] = degree[e.to]++;\n        elist.push_back({e.frm,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n        elist.push_back({e.to, {e.frm,\
    \ -1, e.flow, -e.cost}});\n      }\n      auto _g = internal::csr<_edge>(n, elist);\n\
    \      for (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ += _g.start[e.frm];\n        redge_idx[i] += _g.start[e.to];\n        _g.elist[edge_idx[i]].rev\
    \ = redge_idx[i];\n        _g.elist[redge_idx[i]].rev = edge_idx[i];\n      }\n\
    \      return _g;\n    }();\n\n    auto result = slope(g, flow_limit);\n\n   \
    \ for (int i = 0; i < m; i++) {\n      auto e = g.elist[edge_idx[i]];\n      _edges[i].flow\
    \ = _edges[i].cap - e.cap;\n    }\n\n    return result;\n  }\n\n  // O(F(N+M))\
    \ \u304F\u3089\u3044\u4F7F\u3063\u3066\u7D4C\u8DEF\u5FA9\u5143\n  vvc<int> path_decomposition()\
    \ {\n    vvc<int> TO(n);\n    for (auto&& e: edges()) { FOR(e.flow) TO[e.frm].eb(e.to);\
    \ }\n    vvc<int> res;\n    vc<int> vis(n);\n\n    while (!TO[source].empty())\
    \ {\n      vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ { vis[POP(path)] = 0; }\n        path.eb(to), vis[to] = 1;\n      }\n      for\
    \ (auto&& v: path) vis[v] = 0;\n      res.eb(path);\n    }\n    return res;\n\
    \  }\n\nprivate:\n  int n, source, sink;\n  vector<edge> _edges;\n\n  // inside\
    \ edge\n  struct _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\
    \n  vector<pair<Cap, Cost>> slope(internal::csr<_edge>& g, Cap flow_limit) {\n\
    \    if (DAG) assert(source == 0 && sink == n - 1);\n    vector<pair<Cost, Cost>>\
    \ dual_dist(n);\n    vector<int> prev_e(n);\n    vector<bool> vis(n);\n    struct\
    \ Q {\n      Cost key;\n      int to;\n      bool operator<(Q r) const { return\
    \ key > r.key; }\n    };\n    vector<int> que_min;\n    vector<Q> que;\n    auto\
    \ dual_ref = [&]() {\n      for (int i = 0; i < n; i++) { dual_dist[i].second\
    \ = infty<Cost>; }\n      fill(vis.begin(), vis.end(), false);\n      que_min.clear();\n\
    \      que.clear();\n\n      // que[0..heap_r) was heapified\n      size_t heap_r\
    \ = 0;\n\n      dual_dist[source].second = 0;\n      que_min.push_back(source);\n\
    \      while (!que_min.empty() || !que.empty()) {\n        int v;\n        if\
    \ (!que_min.empty()) {\n          v = que_min.back();\n          que_min.pop_back();\n\
    \        } else {\n          while (heap_r < que.size()) {\n            heap_r++;\n\
    \            push_heap(que.begin(), que.begin() + heap_r);\n          }\n    \
    \      v = que.front().to;\n          pop_heap(que.begin(), que.end());\n    \
    \      que.pop_back();\n          heap_r--;\n        }\n        if (vis[v]) continue;\n\
    \        vis[v] = true;\n        if (v == sink) break;\n        Cost dual_v =\
    \ dual_dist[v].first, dist_v = dual_dist[v].second;\n        for (int i = g.start[v];\
    \ i < g.start[v + 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap)\
    \ continue;\n          Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n\
    \          if (dual_dist[e.to].second > dist_v + cost) {\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n            if (dist_to == dist_v) {\n             \
    \ que_min.push_back(e.to);\n            } else {\n              que.push_back(Q{dist_to,\
    \ e.to});\n            }\n          }\n        }\n      }\n      if (!vis[sink])\
    \ { return false; }\n\n      for (int v = 0; v < n; v++) {\n        if (!vis[v])\
    \ continue;\n        dual_dist[v].first -= dual_dist[sink].second - dual_dist[v].second;\n\
    \      }\n      return true;\n    };\n\n    auto dual_ref_dag = [&]() {\n    \
    \  FOR(i, n) dual_dist[i].se = infty<Cost>;\n      dual_dist[source].se = 0;\n\
    \      fill(vis.begin(), vis.end(), false);\n      vis[0] = true;\n\n      FOR(v,\
    \ n) {\n        if (!vis[v]) continue;\n        Cost dual_v = dual_dist[v].fi,\
    \ dist_v = dual_dist[v].se;\n        for (int i = g.start[v]; i < g.start[v +\
    \ 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n\
    \          Cost cost = e.cost - dual_dist[e.to].fi + dual_v;\n          if (dual_dist[e.to].se\
    \ > dist_v + cost) {\n            vis[e.to] = true;\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n          }\n        }\n      }\n      if (!vis[sink])\
    \ { return false; }\n\n      for (int v = 0; v < n; v++) {\n        if (!vis[v])\
    \ continue;\n        dual_dist[v].fi -= dual_dist[sink].se - dual_dist[v].se;\n\
    \      }\n      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0,\
    \ prev_cost_per_flow = -1;\n    vector<pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \    while (flow < flow_limit) {\n      if (DAG && flow == 0) {\n        if (!dual_ref_dag())\
    \ break;\n      } else {\n        if (!dual_ref()) break;\n      }\n      Cap\
    \ c = flow_limit - flow;\n      for (int v = sink; v != source; v = g.elist[prev_e[v]].to)\
    \ {\n        c = min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      }\n     \
    \ for (int v = sink; v != source; v = g.elist[prev_e[v]].to) {\n        auto&\
    \ e = g.elist[prev_e[v]];\n        e.cap += c;\n        g.elist[e.rev].cap -=\
    \ c;\n      }\n      Cost d = -dual_dist[source].first;\n      flow += c;\n  \
    \    cost += c * d;\n      if (prev_cost_per_flow == d) { result.pop_back(); }\n\
    \      result.push_back({flow, cost});\n      prev_cost_per_flow = d;\n    }\n\
    \    return result;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/mincostflow.hpp
  requiredBy: []
  timestamp: '2023-10-14 01:47:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1288.test.cpp
  - test/yukicoder/1341.test.cpp
  - test/yukicoder/1678.test.cpp
  - test/yukicoder/1301.test.cpp
  - test/yukicoder/1324.test.cpp
  - test/yukicoder/1676.test.cpp
  - test/library_checker/graph/assignment_mcf.test.cpp
  - test/aoj/GRL_6_B.test.cpp
  - test_atcoder/abc214h.test.cpp
documentation_of: flow/mincostflow.hpp
layout: document
redirect_from:
- /library/flow/mincostflow.hpp
- /library/flow/mincostflow.hpp.html
title: flow/mincostflow.hpp
---
