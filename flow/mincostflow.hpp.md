---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  - icon: ':x:'
    path: test/library_checker/graph/assignment_mcf.test.cpp
    title: test/library_checker/graph/assignment_mcf.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1288.test.cpp
    title: test/yukicoder/1288.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1301.test.cpp
    title: test/yukicoder/1301.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1324.test.cpp
    title: test/yukicoder/1324.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1341.test.cpp
    title: test/yukicoder/1341.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1676.test.cpp
    title: test/yukicoder/1676.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1678.test.cpp
    title: test/yukicoder/1678.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/mincostflow.hpp\"\n\n// atcoder library \u306E\u3082\
    \u306E\u3092\u6539\u5909\n\nnamespace internal {\n\ntemplate <class E>\nstruct\
    \ csr {\n  std::vector<int> start;\n  std::vector<E> elist;\n  explicit csr(int\
    \ n, const std::vector<std::pair<int, E>>& edges)\n      : start(n + 1), elist(edges.size())\
    \ {\n    for (auto e: edges) { start[e.first + 1]++; }\n    for (int i = 1; i\
    \ <= n; i++) { start[i] += start[i - 1]; }\n    auto counter = start;\n    for\
    \ (auto e: edges) { elist[counter[e.first]++] = e.second; }\n  }\n};\n\ntemplate\
    \ <class T>\nstruct simple_queue {\n  std::vector<T> payload;\n  int pos = 0;\n\
    \  void reserve(int n) { payload.reserve(n); }\n  int size() const { return int(payload.size())\
    \ - pos; }\n  bool empty() const { return pos == int(payload.size()); }\n  void\
    \ push(const T& t) { payload.push_back(t); }\n  T& front() { return payload[pos];\
    \ }\n  void clear() {\n    payload.clear();\n    pos = 0;\n  }\n  void pop() {\
    \ pos++; }\n};\n\n} // namespace internal\n\n/*\n\u30FBatcoder library \u3092\u3059\
    \u3053\u3057\u6539\u5909\u3057\u305F\u3082\u306E\n\u30FBDAG = true \u3067\u3042\
    \u308C\u3070\u3001\u8CA0\u8FBA OK \uFF081 \u56DE\u76EE\u306E\u6700\u77ED\u8DEF\
    \u3092 dp \u3067\u884C\u3046\uFF09\n\u305F\u3060\u3057\u3001\u9802\u70B9\u756A\
    \u53F7\u306F toposort \u3055\u308C\u3066\u3044\u308B\u3053\u3068\u3092\u4EEE\u5B9A\
    \u3057\u3066\u3044\u308B\u3002\n*/\ntemplate <class Cap = int, class Cost = ll,\
    \ bool DAG = false>\nstruct mcf_graph {\npublic:\n  mcf_graph() {}\n  explicit\
    \ mcf_graph(int n) : _n(n) {}\n\n  // frm, to, cap, cost\n  int add(int frm, int\
    \ to, Cap cap, Cost cost) {\n    assert(0 <= frm && frm < _n);\n    assert(0 <=\
    \ to && to < _n);\n    assert(0 <= cap);\n    assert(DAG || 0 <= cost);\n    if\
    \ (DAG) assert(frm < to);\n    int m = int(_edges.size());\n    _edges.push_back({frm,\
    \ to, cap, 0, cost});\n    return m;\n  }\n\n  void debug() {\n    print(\"flow\
    \ graph\");\n    print(\"frm, to, cap, cost\");\n    for (auto&& [frm, to, cap,\
    \ flow, cost]: _edges) {\n      print(frm, to, cap, cost);\n    }\n  }\n\n  struct\
    \ edge {\n    int frm, to;\n    Cap cap, flow;\n    Cost cost;\n  };\n\n  edge\
    \ get_edge(int i) {\n    int m = int(_edges.size());\n    assert(0 <= i && i <\
    \ m);\n    return _edges[i];\n  }\n  std::vector<edge> edges() { return _edges;\
    \ }\n\n  std::pair<Cap, Cost> flow(int s, int t) {\n    return flow(s, t, std::numeric_limits<Cap>::max());\n\
    \  }\n  std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {\n    return\
    \ slope(s, t, flow_limit).back();\n  }\n  std::vector<std::pair<Cap, Cost>> slope(int\
    \ s, int t) {\n    return slope(s, t, std::numeric_limits<Cap>::max());\n  }\n\
    \  std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {\n \
    \   assert(0 <= s && s < _n);\n    assert(0 <= t && t < _n);\n    assert(s !=\
    \ t);\n\n    int m = int(_edges.size());\n    std::vector<int> edge_idx(m);\n\n\
    \    auto g = [&]() {\n      std::vector<int> degree(_n), redge_idx(m);\n    \
    \  std::vector<std::pair<int, _edge>> elist;\n      elist.reserve(2 * m);\n  \
    \    for (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ = degree[e.frm]++;\n        redge_idx[i] = degree[e.to]++;\n        elist.push_back({e.frm,\
    \ {e.to, -1, e.cap - e.flow, e.cost}});\n        elist.push_back({e.to, {e.frm,\
    \ -1, e.flow, -e.cost}});\n      }\n      auto _g = internal::csr<_edge>(_n, elist);\n\
    \      for (int i = 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i]\
    \ += _g.start[e.frm];\n        redge_idx[i] += _g.start[e.to];\n        _g.elist[edge_idx[i]].rev\
    \ = redge_idx[i];\n        _g.elist[redge_idx[i]].rev = edge_idx[i];\n      }\n\
    \      return _g;\n    }();\n\n    auto result = slope(g, s, t, flow_limit);\n\
    \n    for (int i = 0; i < m; i++) {\n      auto e = g.elist[edge_idx[i]];\n  \
    \    _edges[i].flow = _edges[i].cap - e.cap;\n    }\n\n    return result;\n  }\n\
    \nprivate:\n  int _n;\n  std::vector<edge> _edges;\n\n  // inside edge\n  struct\
    \ _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\n  std::vector<std::pair<Cap,\
    \ Cost>> slope(internal::csr<_edge>& g, int s, int t,\n                      \
    \                    Cap flow_limit) {\n    // variants (C = maxcost):\n    //\
    \ -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n    // reduced cost (= e.cost\
    \ + dual[e.frm] - dual[e.to]) >= 0 for all edge\n\n    // dual_dist[i] = (dual[i],\
    \ dist[i])\n    if (DAG) assert(s == 0 && t == _n - 1);\n    std::vector<std::pair<Cost,\
    \ Cost>> dual_dist(_n);\n    std::vector<int> prev_e(_n);\n    std::vector<bool>\
    \ vis(_n);\n    struct Q {\n      Cost key;\n      int to;\n      bool operator<(Q\
    \ r) const { return key > r.key; }\n    };\n    std::vector<int> que_min;\n  \
    \  std::vector<Q> que;\n    auto dual_ref = [&]() {\n      for (int i = 0; i <\
    \ _n; i++) {\n        dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \      }\n      std::fill(vis.begin(), vis.end(), false);\n      que_min.clear();\n\
    \      que.clear();\n\n      // que[0..heap_r) was heapified\n      size_t heap_r\
    \ = 0;\n\n      dual_dist[s].second = 0;\n      que_min.push_back(s);\n      while\
    \ (!que_min.empty() || !que.empty()) {\n        int v;\n        if (!que_min.empty())\
    \ {\n          v = que_min.back();\n          que_min.pop_back();\n        } else\
    \ {\n          while (heap_r < que.size()) {\n            heap_r++;\n        \
    \    std::push_heap(que.begin(), que.begin() + heap_r);\n          }\n       \
    \   v = que.front().to;\n          std::pop_heap(que.begin(), que.end());\n  \
    \        que.pop_back();\n          heap_r--;\n        }\n        if (vis[v])\
    \ continue;\n        vis[v] = true;\n        if (v == t) break;\n        // dist[v]\
    \ = shortest(s, v) + dual[s] - dual[v]\n        // dist[v] >= 0 (all reduced cost\
    \ are positive)\n        // dist[v] <= (n-1)C\n        Cost dual_v = dual_dist[v].first,\
    \ dist_v = dual_dist[v].second;\n        for (int i = g.start[v]; i < g.start[v\
    \ + 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n\
    \          // |-dual[e.to] + dual[v]| <= (n-1)C\n          // cost <= C - -(n-1)C\
    \ + 0 = nC\n          Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n \
    \         if (dual_dist[e.to].second > dist_v + cost) {\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n            if (dist_to == dist_v) {\n             \
    \ que_min.push_back(e.to);\n            } else {\n              que.push_back(Q{dist_to,\
    \ e.to});\n            }\n          }\n        }\n      }\n      if (!vis[t])\
    \ { return false; }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s,\n        //         t) + dual[t] + shortest(s,\
    \ v) = shortest(s, v) -\n        //         shortest(s, t) >= 0 - (n-1)C\n   \
    \     dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n     \
    \ }\n      return true;\n    };\n\n    auto dual_ref_dag = [&]() {\n      for\
    \ (int i = 0; i < _n; i++) {\n        dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \      }\n      dual_dist[s].second = 0;\n      std::fill(vis.begin(), vis.end(),\
    \ false);\n      vis[0] = true;\n\n      for (int v = 0; v < _n; ++v) {\n    \
    \    if (!vis[v]) continue;\n        Cost dual_v = dual_dist[v].first, dist_v\
    \ = dual_dist[v].second;\n        for (int i = g.start[v]; i < g.start[v + 1];\
    \ i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n  \
    \        Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n          if (dual_dist[e.to].second\
    \ > dist_v + cost) {\n            vis[e.to] = true;\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n          }\n        }\n      }\n      if (!vis[t])\
    \ { return false; }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s,\n        //         t) + dual[t] + shortest(s,\
    \ v) = shortest(s, v) -\n        //         shortest(s, t) >= 0 - (n-1)C\n   \
    \     dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n     \
    \ }\n      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n    std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \    while (flow < flow_limit) {\n      if (DAG && flow == 0) {\n        if (!dual_ref_dag())\
    \ break;\n      } else {\n        if (!dual_ref()) break;\n      }\n      Cap\
    \ c = flow_limit - flow;\n      for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n        c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      }\n\
    \      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {\n        auto& e =\
    \ g.elist[prev_e[v]];\n        e.cap += c;\n        g.elist[e.rev].cap -= c;\n\
    \      }\n      Cost d = -dual_dist[s].first;\n      flow += c;\n      cost +=\
    \ c * d;\n      if (prev_cost_per_flow == d) { result.pop_back(); }\n      result.push_back({flow,\
    \ cost});\n      prev_cost_per_flow = d;\n    }\n    return result;\n  }\n};\n"
  code: "#pragma once\n\n// atcoder library \u306E\u3082\u306E\u3092\u6539\u5909\n\
    \nnamespace internal {\n\ntemplate <class E>\nstruct csr {\n  std::vector<int>\
    \ start;\n  std::vector<E> elist;\n  explicit csr(int n, const std::vector<std::pair<int,\
    \ E>>& edges)\n      : start(n + 1), elist(edges.size()) {\n    for (auto e: edges)\
    \ { start[e.first + 1]++; }\n    for (int i = 1; i <= n; i++) { start[i] += start[i\
    \ - 1]; }\n    auto counter = start;\n    for (auto e: edges) { elist[counter[e.first]++]\
    \ = e.second; }\n  }\n};\n\ntemplate <class T>\nstruct simple_queue {\n  std::vector<T>\
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
    \ <class Cap = int, class Cost = ll, bool DAG = false>\nstruct mcf_graph {\npublic:\n\
    \  mcf_graph() {}\n  explicit mcf_graph(int n) : _n(n) {}\n\n  // frm, to, cap,\
    \ cost\n  int add(int frm, int to, Cap cap, Cost cost) {\n    assert(0 <= frm\
    \ && frm < _n);\n    assert(0 <= to && to < _n);\n    assert(0 <= cap);\n    assert(DAG\
    \ || 0 <= cost);\n    if (DAG) assert(frm < to);\n    int m = int(_edges.size());\n\
    \    _edges.push_back({frm, to, cap, 0, cost});\n    return m;\n  }\n\n  void\
    \ debug() {\n    print(\"flow graph\");\n    print(\"frm, to, cap, cost\");\n\
    \    for (auto&& [frm, to, cap, flow, cost]: _edges) {\n      print(frm, to, cap,\
    \ cost);\n    }\n  }\n\n  struct edge {\n    int frm, to;\n    Cap cap, flow;\n\
    \    Cost cost;\n  };\n\n  edge get_edge(int i) {\n    int m = int(_edges.size());\n\
    \    assert(0 <= i && i < m);\n    return _edges[i];\n  }\n  std::vector<edge>\
    \ edges() { return _edges; }\n\n  std::pair<Cap, Cost> flow(int s, int t) {\n\
    \    return flow(s, t, std::numeric_limits<Cap>::max());\n  }\n  std::pair<Cap,\
    \ Cost> flow(int s, int t, Cap flow_limit) {\n    return slope(s, t, flow_limit).back();\n\
    \  }\n  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {\n    return slope(s,\
    \ t, std::numeric_limits<Cap>::max());\n  }\n  std::vector<std::pair<Cap, Cost>>\
    \ slope(int s, int t, Cap flow_limit) {\n    assert(0 <= s && s < _n);\n    assert(0\
    \ <= t && t < _n);\n    assert(s != t);\n\n    int m = int(_edges.size());\n \
    \   std::vector<int> edge_idx(m);\n\n    auto g = [&]() {\n      std::vector<int>\
    \ degree(_n), redge_idx(m);\n      std::vector<std::pair<int, _edge>> elist;\n\
    \      elist.reserve(2 * m);\n      for (int i = 0; i < m; i++) {\n        auto\
    \ e = _edges[i];\n        edge_idx[i] = degree[e.frm]++;\n        redge_idx[i]\
    \ = degree[e.to]++;\n        elist.push_back({e.frm, {e.to, -1, e.cap - e.flow,\
    \ e.cost}});\n        elist.push_back({e.to, {e.frm, -1, e.flow, -e.cost}});\n\
    \      }\n      auto _g = internal::csr<_edge>(_n, elist);\n      for (int i =\
    \ 0; i < m; i++) {\n        auto e = _edges[i];\n        edge_idx[i] += _g.start[e.frm];\n\
    \        redge_idx[i] += _g.start[e.to];\n        _g.elist[edge_idx[i]].rev =\
    \ redge_idx[i];\n        _g.elist[redge_idx[i]].rev = edge_idx[i];\n      }\n\
    \      return _g;\n    }();\n\n    auto result = slope(g, s, t, flow_limit);\n\
    \n    for (int i = 0; i < m; i++) {\n      auto e = g.elist[edge_idx[i]];\n  \
    \    _edges[i].flow = _edges[i].cap - e.cap;\n    }\n\n    return result;\n  }\n\
    \nprivate:\n  int _n;\n  std::vector<edge> _edges;\n\n  // inside edge\n  struct\
    \ _edge {\n    int to, rev;\n    Cap cap;\n    Cost cost;\n  };\n\n  std::vector<std::pair<Cap,\
    \ Cost>> slope(internal::csr<_edge>& g, int s, int t,\n                      \
    \                    Cap flow_limit) {\n    // variants (C = maxcost):\n    //\
    \ -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0\n    // reduced cost (= e.cost\
    \ + dual[e.frm] - dual[e.to]) >= 0 for all edge\n\n    // dual_dist[i] = (dual[i],\
    \ dist[i])\n    if (DAG) assert(s == 0 && t == _n - 1);\n    std::vector<std::pair<Cost,\
    \ Cost>> dual_dist(_n);\n    std::vector<int> prev_e(_n);\n    std::vector<bool>\
    \ vis(_n);\n    struct Q {\n      Cost key;\n      int to;\n      bool operator<(Q\
    \ r) const { return key > r.key; }\n    };\n    std::vector<int> que_min;\n  \
    \  std::vector<Q> que;\n    auto dual_ref = [&]() {\n      for (int i = 0; i <\
    \ _n; i++) {\n        dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \      }\n      std::fill(vis.begin(), vis.end(), false);\n      que_min.clear();\n\
    \      que.clear();\n\n      // que[0..heap_r) was heapified\n      size_t heap_r\
    \ = 0;\n\n      dual_dist[s].second = 0;\n      que_min.push_back(s);\n      while\
    \ (!que_min.empty() || !que.empty()) {\n        int v;\n        if (!que_min.empty())\
    \ {\n          v = que_min.back();\n          que_min.pop_back();\n        } else\
    \ {\n          while (heap_r < que.size()) {\n            heap_r++;\n        \
    \    std::push_heap(que.begin(), que.begin() + heap_r);\n          }\n       \
    \   v = que.front().to;\n          std::pop_heap(que.begin(), que.end());\n  \
    \        que.pop_back();\n          heap_r--;\n        }\n        if (vis[v])\
    \ continue;\n        vis[v] = true;\n        if (v == t) break;\n        // dist[v]\
    \ = shortest(s, v) + dual[s] - dual[v]\n        // dist[v] >= 0 (all reduced cost\
    \ are positive)\n        // dist[v] <= (n-1)C\n        Cost dual_v = dual_dist[v].first,\
    \ dist_v = dual_dist[v].second;\n        for (int i = g.start[v]; i < g.start[v\
    \ + 1]; i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n\
    \          // |-dual[e.to] + dual[v]| <= (n-1)C\n          // cost <= C - -(n-1)C\
    \ + 0 = nC\n          Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n \
    \         if (dual_dist[e.to].second > dist_v + cost) {\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n            if (dist_to == dist_v) {\n             \
    \ que_min.push_back(e.to);\n            } else {\n              que.push_back(Q{dist_to,\
    \ e.to});\n            }\n          }\n        }\n      }\n      if (!vis[t])\
    \ { return false; }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s,\n        //         t) + dual[t] + shortest(s,\
    \ v) = shortest(s, v) -\n        //         shortest(s, t) >= 0 - (n-1)C\n   \
    \     dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n     \
    \ }\n      return true;\n    };\n\n    auto dual_ref_dag = [&]() {\n      for\
    \ (int i = 0; i < _n; i++) {\n        dual_dist[i].second = std::numeric_limits<Cost>::max();\n\
    \      }\n      dual_dist[s].second = 0;\n      std::fill(vis.begin(), vis.end(),\
    \ false);\n      vis[0] = true;\n\n      for (int v = 0; v < _n; ++v) {\n    \
    \    if (!vis[v]) continue;\n        Cost dual_v = dual_dist[v].first, dist_v\
    \ = dual_dist[v].second;\n        for (int i = g.start[v]; i < g.start[v + 1];\
    \ i++) {\n          auto e = g.elist[i];\n          if (!e.cap) continue;\n  \
    \        Cost cost = e.cost - dual_dist[e.to].first + dual_v;\n          if (dual_dist[e.to].second\
    \ > dist_v + cost) {\n            vis[e.to] = true;\n            Cost dist_to\
    \ = dist_v + cost;\n            dual_dist[e.to].second = dist_to;\n          \
    \  prev_e[e.to] = e.rev;\n          }\n        }\n      }\n      if (!vis[t])\
    \ { return false; }\n\n      for (int v = 0; v < _n; v++) {\n        if (!vis[v])\
    \ continue;\n        // dual[v] = dual[v] - dist[t] + dist[v]\n        //    \
    \     = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +\n        //         (shortest(s,\
    \ v) + dual[s] - dual[v]) = - shortest(s,\n        //         t) + dual[t] + shortest(s,\
    \ v) = shortest(s, v) -\n        //         shortest(s, t) >= 0 - (n-1)C\n   \
    \     dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;\n     \
    \ }\n      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0, prev_cost_per_flow\
    \ = -1;\n    std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};\n\
    \    while (flow < flow_limit) {\n      if (DAG && flow == 0) {\n        if (!dual_ref_dag())\
    \ break;\n      } else {\n        if (!dual_ref()) break;\n      }\n      Cap\
    \ c = flow_limit - flow;\n      for (int v = t; v != s; v = g.elist[prev_e[v]].to)\
    \ {\n        c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);\n      }\n\
    \      for (int v = t; v != s; v = g.elist[prev_e[v]].to) {\n        auto& e =\
    \ g.elist[prev_e[v]];\n        e.cap += c;\n        g.elist[e.rev].cap -= c;\n\
    \      }\n      Cost d = -dual_dist[s].first;\n      flow += c;\n      cost +=\
    \ c * d;\n      if (prev_cost_per_flow == d) { result.pop_back(); }\n      result.push_back({flow,\
    \ cost});\n      prev_cost_per_flow = d;\n    }\n    return result;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/mincostflow.hpp
  requiredBy: []
  timestamp: '2022-05-05 15:29:23+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/1324.test.cpp
  - test/yukicoder/1341.test.cpp
  - test/yukicoder/1678.test.cpp
  - test/yukicoder/1676.test.cpp
  - test/yukicoder/1288.test.cpp
  - test/yukicoder/1301.test.cpp
  - test/library_checker/graph/assignment_mcf.test.cpp
  - test/aoj/GRL_6_B.test.cpp
documentation_of: flow/mincostflow.hpp
layout: document
redirect_from:
- /library/flow/mincostflow.hpp
- /library/flow/mincostflow.hpp.html
title: flow/mincostflow.hpp
---
