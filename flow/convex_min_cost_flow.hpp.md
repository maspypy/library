---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/maspypy/library/blob/main/flow/convex_min_cost_flow.hpp
  bundledCode: "#line 1 \"flow/convex_min_cost_flow.hpp\"\n// Source: https://github.com/maspypy/library/blob/main/flow/convex_min_cost_flow.hpp\n\
    \n/*\n\u30FB\u5404\u8FBA\u306E\u8CBB\u7528\u306F flow x \u306B\u5BFE\u3057\u3066\
    \ f(x) \u3068\u3059\u308B\uFF0Ef(0)=0 \u4E0B\u51F8\uFF0E\n\u30FBDAG = true \u306A\
    \u3089\u8CA0\u306E\u5897\u5206\u8CBB\u7528\u3092\u8A31\u3057\uFF0C\u9802\u70B9\
    \u756A\u53F7\u306F topological order\uFF0E\n*/\ntemplate <class Cap = int, class\
    \ Cost = ll, bool DAG = false>\nstruct Convex_Min_Cost_Flow {\n public:\n  Convex_Min_Cost_Flow()\
    \ {}\n  explicit Convex_Min_Cost_Flow(int n, int source, int sink)\n      : n(n),\
    \ source(source), sink(sink), adj(n) {\n    assert(0 <= source && source < n);\n\
    \    assert(0 <= sink && sink < n);\n    assert(source != sink);\n  }\n\n  struct\
    \ edge {\n    int frm, to;\n    Cap cap, flow;\n  };\n\n private:\n  struct block\
    \ {\n    Cap end;\n    Cost cost;\n  };\n  struct edge_data {\n    edge e;\n \
    \   vector<block> blocks;\n    int block_idx;\n  };\n\n public:\n  int add(int\
    \ frm, int to, Cap cap, Cost cost) {\n    vector<block> blocks;\n    if (cap)\
    \ blocks.push_back({cap, cost});\n    return add_blocks(frm, to, cap, std::move(blocks));\n\
    \  }\n\n  template <class F>\n  int add_convex(int frm, int to, Cap cap, F&& f)\
    \ {\n    assert(0 <= cap);\n    Cost prev = f(Cap(0));\n    assert(prev == Cost(0));\n\
    \    vector<block> blocks;\n    for (Cap x = 0; x < cap;) {\n      ++x;\n    \
    \  Cost now = f(x);\n      Cost cost = now - prev;\n      assert(DAG || Cost(0)\
    \ <= cost);\n      if (!blocks.empty()) assert(blocks.back().cost <= cost);\n\
    \      if (!blocks.empty() && blocks.back().cost == cost)\n        ++blocks.back().end;\n\
    \      else\n        blocks.push_back({1, cost});\n      prev = now;\n    }\n\
    \    return add_blocks(frm, to, cap, std::move(blocks));\n  }\n\n  edge get_edge(int\
    \ i) const {\n    assert(0 <= i && i < int(_edges.size()));\n    return _edges[i].e;\n\
    \  }\n  vector<edge> edges() const {\n    vector<edge> res;\n    res.reserve(_edges.size());\n\
    \    for (auto&& x : _edges) res.push_back(x.e);\n    return res;\n  }\n\n  pair<Cap,\
    \ Cost> flow() { return flow(infty<Cap>); }\n  pair<Cap, Cost> flow(Cap flow_limit)\
    \ { return slope(flow_limit).back(); }\n  vector<pair<Cap, Cost>> slope() { return\
    \ slope(infty<Cap>); }\n  vector<pair<Cap, Cost>> slope(Cap flow_limit) {\n  \
    \  assert(!solved);\n    assert(0 <= flow_limit);\n    solved = true;\n    return\
    \ run_slope(flow_limit);\n  }\n\n  vvc<int> path_decomposition() const {\n   \
    \ vvc<int> TO(n);\n    for (auto&& e : edges()) FOR(e.flow) TO[e.frm].eb(e.to);\n\
    \    vvc<int> res;\n    vc<int> vis(n);\n    while (!TO[source].empty()) {\n \
    \     vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ vis[POP(path)] = 0;\n        path.eb(to), vis[to] = 1;\n      }\n      for (auto&&\
    \ v : path) vis[v] = 0;\n      res.eb(path);\n    }\n    return res;\n  }\n\n\
    \  vc<Cost> get_potentials() const { return potential; }\n\n private:\n  int n,\
    \ source, sink;\n  vector<edge_data> _edges;\n  vector<vector<pair<int, int>>>\
    \ adj;\n  bool solved = false;\n  vc<Cost> potential;\n\n  int add_blocks(int\
    \ frm, int to, Cap cap, vector<block>&& blocks) {\n    assert(!solved);\n    assert(0\
    \ <= frm && frm < n);\n    assert(0 <= to && to < n);\n    assert(0 <= cap);\n\
    \    if (DAG) assert(frm < to);\n    Cap end = 0;\n    for (auto&& b : blocks)\
    \ {\n      assert(DAG || Cost(0) <= b.cost);\n      end += b.end;\n      b.end\
    \ = end;\n    }\n    assert(end == cap);\n    int id = int(_edges.size());\n \
    \   _edges.push_back({{frm, to, cap, 0}, std::move(blocks), 0});\n    adj[frm].push_back({id,\
    \ +1});\n    adj[to].push_back({id, -1});\n    return id;\n  }\n\n  bool residual(int\
    \ id, int dir, Cap& cap, Cost& cost) const {\n    auto&& data = _edges[id];\n\
    \    auto&& e = data.e;\n    if (dir == +1) {\n      if (e.flow == e.cap) return\
    \ false;\n      auto&& b = data.blocks[data.block_idx];\n      cap = b.end - e.flow;\n\
    \      cost = b.cost;\n      return true;\n    }\n    if (e.flow == 0) return\
    \ false;\n    int i = data.block_idx;\n    if (i == int(data.blocks.size()) ||\
    \ (i && e.flow == data.blocks[i - 1].end))\n      --i;\n    auto&& b = data.blocks[i];\n\
    \    Cap begin = (i ? data.blocks[i - 1].end : 0);\n    cap = e.flow - begin;\n\
    \    cost = -b.cost;\n    return true;\n  }\n\n  void push(int id, int dir, Cap\
    \ amount) {\n    auto&& data = _edges[id];\n    if (dir == +1)\n      data.e.flow\
    \ += amount;\n    else\n      data.e.flow -= amount;\n    while (data.block_idx\
    \ < int(data.blocks.size()) &&\n           data.e.flow >= data.blocks[data.block_idx].end)\n\
    \      ++data.block_idx;\n    while (data.block_idx && data.e.flow < data.blocks[data.block_idx\
    \ - 1].end)\n      --data.block_idx;\n  }\n\n  vector<pair<Cap, Cost>> run_slope(Cap\
    \ flow_limit) {\n    if (DAG) assert(source == 0 && sink == n - 1);\n    vector<pair<Cost,\
    \ Cost>> dual_dist(n);\n    vector<pair<int, int>> parent(n);\n    vector<bool>\
    \ vis(n);\n    struct Q {\n      Cost key;\n      int to;\n      bool operator<(Q\
    \ r) const { return key > r.key; }\n    };\n    vector<int> que_min;\n    vector<Q>\
    \ que;\n    auto dual_ref = [&]() {\n      FOR(v, n) dual_dist[v].second = infty<Cost>;\n\
    \      fill(vis.begin(), vis.end(), false);\n      que_min.clear(), que.clear();\n\
    \      size_t heap_r = 0;\n      dual_dist[source].second = 0;\n      que_min.push_back(source);\n\
    \      while (!que_min.empty() || !que.empty()) {\n        int v;\n        if\
    \ (!que_min.empty())\n          v = POP(que_min);\n        else {\n          while\
    \ (heap_r < que.size())\n            push_heap(que.begin(), que.begin() + ++heap_r);\n\
    \          v = que.front().to;\n          pop_heap(que.begin(), que.end());\n\
    \          que.pop_back();\n          --heap_r;\n        }\n        if (vis[v])\
    \ continue;\n        vis[v] = true;\n        if (v == sink) break;\n        Cost\
    \ dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;\n        for (auto&&\
    \ [id, dir] : adj[v]) {\n          Cap cap;\n          Cost edge_cost;\n     \
    \     if (!residual(id, dir, cap, edge_cost)) continue;\n          auto&& e =\
    \ _edges[id].e;\n          int to = (dir == +1 ? e.to : e.frm);\n          Cost\
    \ cost = edge_cost - dual_dist[to].first + dual_v;\n          if (dual_dist[to].second\
    \ <= dist_v + cost) continue;\n          Cost dist_to = dist_v + cost;\n     \
    \     dual_dist[to].second = dist_to;\n          parent[to] = {id, dir};\n   \
    \       if (dist_to == dist_v)\n            que_min.push_back(to);\n         \
    \ else\n            que.push_back({dist_to, to});\n        }\n      }\n      if\
    \ (!vis[sink]) return false;\n      FOR(v, n)\n      if (vis[v])\n        dual_dist[v].first\
    \ -= dual_dist[sink].second - dual_dist[v].second;\n      return true;\n    };\n\
    \    auto dual_ref_dag = [&]() {\n      FOR(v, n) dual_dist[v].second = infty<Cost>;\n\
    \      dual_dist[source].second = 0;\n      fill(vis.begin(), vis.end(), false);\n\
    \      vis[0] = true;\n      FOR(v, n) {\n        if (!vis[v]) continue;\n   \
    \     Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;\n      \
    \  for (auto&& [id, dir] : adj[v]) {\n          Cap cap;\n          Cost edge_cost;\n\
    \          if (!residual(id, dir, cap, edge_cost)) continue;\n          auto&&\
    \ e = _edges[id].e;\n          int to = (dir == +1 ? e.to : e.frm);\n        \
    \  Cost cost = edge_cost - dual_dist[to].first + dual_v;\n          if (dual_dist[to].second\
    \ > dist_v + cost) {\n            vis[to] = true;\n            dual_dist[to].second\
    \ = dist_v + cost;\n            parent[to] = {id, dir};\n          }\n       \
    \ }\n      }\n      if (!vis[sink]) return false;\n      FOR(v, n)\n      if (vis[v])\n\
    \        dual_dist[v].first -= dual_dist[sink].second - dual_dist[v].second;\n\
    \      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0, prev_cost_per_flow\
    \ = 0;\n    bool has_prev_cost = false;\n    vector<pair<Cap, Cost>> result =\
    \ {{Cap(0), Cost(0)}};\n    while (flow < flow_limit) {\n      if (DAG && flow\
    \ == 0 ? !dual_ref_dag() : !dual_ref()) break;\n      Cap c = flow_limit - flow;\n\
    \      for (int v = sink; v != source;) {\n        auto [id, dir] = parent[v];\n\
    \        Cap cap;\n        Cost edge_cost;\n        bool ok = residual(id, dir,\
    \ cap, edge_cost);\n        assert(ok);\n        chmin(c, cap);\n        v = (dir\
    \ == +1 ? _edges[id].e.frm : _edges[id].e.to);\n      }\n      for (int v = sink;\
    \ v != source;) {\n        auto [id, dir] = parent[v];\n        int prv = (dir\
    \ == +1 ? _edges[id].e.frm : _edges[id].e.to);\n        push(id, dir, c);\n  \
    \      v = prv;\n      }\n      Cost d = -dual_dist[source].first;\n      flow\
    \ += c;\n      cost += c * d;\n      if (has_prev_cost && prev_cost_per_flow ==\
    \ d) result.pop_back();\n      result.push_back({flow, cost});\n      prev_cost_per_flow\
    \ = d;\n      has_prev_cost = true;\n    }\n    dual_ref();\n    potential.resize(n);\n\
    \    FOR(v, n) potential[v] = dual_dist[v].first;\n    return result;\n  }\n};\n"
  code: "// Source: https://github.com/maspypy/library/blob/main/flow/convex_min_cost_flow.hpp\n\
    \n/*\n\u30FB\u5404\u8FBA\u306E\u8CBB\u7528\u306F flow x \u306B\u5BFE\u3057\u3066\
    \ f(x) \u3068\u3059\u308B\uFF0Ef(0)=0 \u4E0B\u51F8\uFF0E\n\u30FBDAG = true \u306A\
    \u3089\u8CA0\u306E\u5897\u5206\u8CBB\u7528\u3092\u8A31\u3057\uFF0C\u9802\u70B9\
    \u756A\u53F7\u306F topological order\uFF0E\n*/\ntemplate <class Cap = int, class\
    \ Cost = ll, bool DAG = false>\nstruct Convex_Min_Cost_Flow {\n public:\n  Convex_Min_Cost_Flow()\
    \ {}\n  explicit Convex_Min_Cost_Flow(int n, int source, int sink)\n      : n(n),\
    \ source(source), sink(sink), adj(n) {\n    assert(0 <= source && source < n);\n\
    \    assert(0 <= sink && sink < n);\n    assert(source != sink);\n  }\n\n  struct\
    \ edge {\n    int frm, to;\n    Cap cap, flow;\n  };\n\n private:\n  struct block\
    \ {\n    Cap end;\n    Cost cost;\n  };\n  struct edge_data {\n    edge e;\n \
    \   vector<block> blocks;\n    int block_idx;\n  };\n\n public:\n  int add(int\
    \ frm, int to, Cap cap, Cost cost) {\n    vector<block> blocks;\n    if (cap)\
    \ blocks.push_back({cap, cost});\n    return add_blocks(frm, to, cap, std::move(blocks));\n\
    \  }\n\n  template <class F>\n  int add_convex(int frm, int to, Cap cap, F&& f)\
    \ {\n    assert(0 <= cap);\n    Cost prev = f(Cap(0));\n    assert(prev == Cost(0));\n\
    \    vector<block> blocks;\n    for (Cap x = 0; x < cap;) {\n      ++x;\n    \
    \  Cost now = f(x);\n      Cost cost = now - prev;\n      assert(DAG || Cost(0)\
    \ <= cost);\n      if (!blocks.empty()) assert(blocks.back().cost <= cost);\n\
    \      if (!blocks.empty() && blocks.back().cost == cost)\n        ++blocks.back().end;\n\
    \      else\n        blocks.push_back({1, cost});\n      prev = now;\n    }\n\
    \    return add_blocks(frm, to, cap, std::move(blocks));\n  }\n\n  edge get_edge(int\
    \ i) const {\n    assert(0 <= i && i < int(_edges.size()));\n    return _edges[i].e;\n\
    \  }\n  vector<edge> edges() const {\n    vector<edge> res;\n    res.reserve(_edges.size());\n\
    \    for (auto&& x : _edges) res.push_back(x.e);\n    return res;\n  }\n\n  pair<Cap,\
    \ Cost> flow() { return flow(infty<Cap>); }\n  pair<Cap, Cost> flow(Cap flow_limit)\
    \ { return slope(flow_limit).back(); }\n  vector<pair<Cap, Cost>> slope() { return\
    \ slope(infty<Cap>); }\n  vector<pair<Cap, Cost>> slope(Cap flow_limit) {\n  \
    \  assert(!solved);\n    assert(0 <= flow_limit);\n    solved = true;\n    return\
    \ run_slope(flow_limit);\n  }\n\n  vvc<int> path_decomposition() const {\n   \
    \ vvc<int> TO(n);\n    for (auto&& e : edges()) FOR(e.flow) TO[e.frm].eb(e.to);\n\
    \    vvc<int> res;\n    vc<int> vis(n);\n    while (!TO[source].empty()) {\n \
    \     vc<int> path = {source};\n      vis[source] = 1;\n      while (path.back()\
    \ != sink) {\n        int to = POP(TO[path.back()]);\n        while (vis[to])\
    \ vis[POP(path)] = 0;\n        path.eb(to), vis[to] = 1;\n      }\n      for (auto&&\
    \ v : path) vis[v] = 0;\n      res.eb(path);\n    }\n    return res;\n  }\n\n\
    \  vc<Cost> get_potentials() const { return potential; }\n\n private:\n  int n,\
    \ source, sink;\n  vector<edge_data> _edges;\n  vector<vector<pair<int, int>>>\
    \ adj;\n  bool solved = false;\n  vc<Cost> potential;\n\n  int add_blocks(int\
    \ frm, int to, Cap cap, vector<block>&& blocks) {\n    assert(!solved);\n    assert(0\
    \ <= frm && frm < n);\n    assert(0 <= to && to < n);\n    assert(0 <= cap);\n\
    \    if (DAG) assert(frm < to);\n    Cap end = 0;\n    for (auto&& b : blocks)\
    \ {\n      assert(DAG || Cost(0) <= b.cost);\n      end += b.end;\n      b.end\
    \ = end;\n    }\n    assert(end == cap);\n    int id = int(_edges.size());\n \
    \   _edges.push_back({{frm, to, cap, 0}, std::move(blocks), 0});\n    adj[frm].push_back({id,\
    \ +1});\n    adj[to].push_back({id, -1});\n    return id;\n  }\n\n  bool residual(int\
    \ id, int dir, Cap& cap, Cost& cost) const {\n    auto&& data = _edges[id];\n\
    \    auto&& e = data.e;\n    if (dir == +1) {\n      if (e.flow == e.cap) return\
    \ false;\n      auto&& b = data.blocks[data.block_idx];\n      cap = b.end - e.flow;\n\
    \      cost = b.cost;\n      return true;\n    }\n    if (e.flow == 0) return\
    \ false;\n    int i = data.block_idx;\n    if (i == int(data.blocks.size()) ||\
    \ (i && e.flow == data.blocks[i - 1].end))\n      --i;\n    auto&& b = data.blocks[i];\n\
    \    Cap begin = (i ? data.blocks[i - 1].end : 0);\n    cap = e.flow - begin;\n\
    \    cost = -b.cost;\n    return true;\n  }\n\n  void push(int id, int dir, Cap\
    \ amount) {\n    auto&& data = _edges[id];\n    if (dir == +1)\n      data.e.flow\
    \ += amount;\n    else\n      data.e.flow -= amount;\n    while (data.block_idx\
    \ < int(data.blocks.size()) &&\n           data.e.flow >= data.blocks[data.block_idx].end)\n\
    \      ++data.block_idx;\n    while (data.block_idx && data.e.flow < data.blocks[data.block_idx\
    \ - 1].end)\n      --data.block_idx;\n  }\n\n  vector<pair<Cap, Cost>> run_slope(Cap\
    \ flow_limit) {\n    if (DAG) assert(source == 0 && sink == n - 1);\n    vector<pair<Cost,\
    \ Cost>> dual_dist(n);\n    vector<pair<int, int>> parent(n);\n    vector<bool>\
    \ vis(n);\n    struct Q {\n      Cost key;\n      int to;\n      bool operator<(Q\
    \ r) const { return key > r.key; }\n    };\n    vector<int> que_min;\n    vector<Q>\
    \ que;\n    auto dual_ref = [&]() {\n      FOR(v, n) dual_dist[v].second = infty<Cost>;\n\
    \      fill(vis.begin(), vis.end(), false);\n      que_min.clear(), que.clear();\n\
    \      size_t heap_r = 0;\n      dual_dist[source].second = 0;\n      que_min.push_back(source);\n\
    \      while (!que_min.empty() || !que.empty()) {\n        int v;\n        if\
    \ (!que_min.empty())\n          v = POP(que_min);\n        else {\n          while\
    \ (heap_r < que.size())\n            push_heap(que.begin(), que.begin() + ++heap_r);\n\
    \          v = que.front().to;\n          pop_heap(que.begin(), que.end());\n\
    \          que.pop_back();\n          --heap_r;\n        }\n        if (vis[v])\
    \ continue;\n        vis[v] = true;\n        if (v == sink) break;\n        Cost\
    \ dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;\n        for (auto&&\
    \ [id, dir] : adj[v]) {\n          Cap cap;\n          Cost edge_cost;\n     \
    \     if (!residual(id, dir, cap, edge_cost)) continue;\n          auto&& e =\
    \ _edges[id].e;\n          int to = (dir == +1 ? e.to : e.frm);\n          Cost\
    \ cost = edge_cost - dual_dist[to].first + dual_v;\n          if (dual_dist[to].second\
    \ <= dist_v + cost) continue;\n          Cost dist_to = dist_v + cost;\n     \
    \     dual_dist[to].second = dist_to;\n          parent[to] = {id, dir};\n   \
    \       if (dist_to == dist_v)\n            que_min.push_back(to);\n         \
    \ else\n            que.push_back({dist_to, to});\n        }\n      }\n      if\
    \ (!vis[sink]) return false;\n      FOR(v, n)\n      if (vis[v])\n        dual_dist[v].first\
    \ -= dual_dist[sink].second - dual_dist[v].second;\n      return true;\n    };\n\
    \    auto dual_ref_dag = [&]() {\n      FOR(v, n) dual_dist[v].second = infty<Cost>;\n\
    \      dual_dist[source].second = 0;\n      fill(vis.begin(), vis.end(), false);\n\
    \      vis[0] = true;\n      FOR(v, n) {\n        if (!vis[v]) continue;\n   \
    \     Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;\n      \
    \  for (auto&& [id, dir] : adj[v]) {\n          Cap cap;\n          Cost edge_cost;\n\
    \          if (!residual(id, dir, cap, edge_cost)) continue;\n          auto&&\
    \ e = _edges[id].e;\n          int to = (dir == +1 ? e.to : e.frm);\n        \
    \  Cost cost = edge_cost - dual_dist[to].first + dual_v;\n          if (dual_dist[to].second\
    \ > dist_v + cost) {\n            vis[to] = true;\n            dual_dist[to].second\
    \ = dist_v + cost;\n            parent[to] = {id, dir};\n          }\n       \
    \ }\n      }\n      if (!vis[sink]) return false;\n      FOR(v, n)\n      if (vis[v])\n\
    \        dual_dist[v].first -= dual_dist[sink].second - dual_dist[v].second;\n\
    \      return true;\n    };\n\n    Cap flow = 0;\n    Cost cost = 0, prev_cost_per_flow\
    \ = 0;\n    bool has_prev_cost = false;\n    vector<pair<Cap, Cost>> result =\
    \ {{Cap(0), Cost(0)}};\n    while (flow < flow_limit) {\n      if (DAG && flow\
    \ == 0 ? !dual_ref_dag() : !dual_ref()) break;\n      Cap c = flow_limit - flow;\n\
    \      for (int v = sink; v != source;) {\n        auto [id, dir] = parent[v];\n\
    \        Cap cap;\n        Cost edge_cost;\n        bool ok = residual(id, dir,\
    \ cap, edge_cost);\n        assert(ok);\n        chmin(c, cap);\n        v = (dir\
    \ == +1 ? _edges[id].e.frm : _edges[id].e.to);\n      }\n      for (int v = sink;\
    \ v != source;) {\n        auto [id, dir] = parent[v];\n        int prv = (dir\
    \ == +1 ? _edges[id].e.frm : _edges[id].e.to);\n        push(id, dir, c);\n  \
    \      v = prv;\n      }\n      Cost d = -dual_dist[source].first;\n      flow\
    \ += c;\n      cost += c * d;\n      if (has_prev_cost && prev_cost_per_flow ==\
    \ d) result.pop_back();\n      result.push_back({flow, cost});\n      prev_cost_per_flow\
    \ = d;\n      has_prev_cost = true;\n    }\n    dual_ref();\n    potential.resize(n);\n\
    \    FOR(v, n) potential[v] = dual_dist[v].first;\n    return result;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/convex_min_cost_flow.hpp
  requiredBy: []
  timestamp: '2026-10-22 01:32:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/convex_min_cost_flow.hpp
layout: document
redirect_from:
- /library/flow/convex_min_cost_flow.hpp
- /library/flow/convex_min_cost_flow.hpp.html
title: flow/convex_min_cost_flow.hpp
---
