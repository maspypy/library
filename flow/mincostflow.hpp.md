---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"flow/mincostflow.hpp\"\ntemplate <typename Cap, typename\
    \ Cost>\nstruct MinCostFlow {\n protected:\n  using P = pair<Cost, int>;\n  struct\
    \ edge {\n    int to;\n    Cap cap;\n    Cost cost;\n    int rev;\n    bool isrev;\n\
    \  };\n  vector<Cost> h;\n  vector<Cost> dist;\n  vector<int> prevv, preve;\n\
    \  bool negative;\n\n public:\n  int V;\n  vector<vector<edge>> G;\n  Cost INF\
    \ = numeric_limits<Cost>::max();\n  MinCostFlow() {}\n  MinCostFlow(int v) : h(v),\
    \ dist(v), prevv(v), preve(v), negative(false), V(v), G(v) {}\n  void add(int\
    \ from, int to, Cap cap, Cost cost) {\n    assert(0 <= from && from < V);\n  \
    \  assert(0 <= to && to < V);\n    assert(0 <= cap);\n    if (cap == 0) return;\n\
    \    if (cost < 0) negative = true;\n    G[from].push_back({to, cap, cost, (int)G[to].size(),\
    \ false});\n    G[to].push_back({from, 0, -cost, (int)G[from].size() - 1, true});\n\
    \  }\n  Cost min_cost_flow(int s, int t, Cap f, bool DAG = false) {\n    assert(0\
    \ <= s && s < V);\n    assert(0 <= t && t < V);\n    assert(s != t);\n    assert(0\
    \ < f);\n    Cost res = 0;\n    fill(h.begin(), h.end(), 0);\n    auto dijkstra\
    \ = [&]() {\n      priority_queue<P, vector<P>, greater<P>> pq;\n      fill(dist.begin(),\
    \ dist.end(), INF);\n      dist[s] = 0;\n      pq.push(P(0, s));\n      while\
    \ (!pq.empty()) {\n        P p = pq.top();\n        pq.pop();\n        int v =\
    \ p.second;\n        if (dist[v] < p.first) continue;\n        for (int i = 0;\
    \ i < (int)G[v].size(); i++) {\n          edge& e = G[v][i];\n          if (e.cap\
    \ <= 0 || dist[e.to] <= dist[v] + e.cost + h[v] - h[e.to]) continue;\n       \
    \   dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n          prevv[e.to] = v;\n\
    \          preve[e.to] = i;\n          pq.push(P(dist[e.to], e.to));\n       \
    \ }\n      }\n    };\n\n    if (DAG) {\n      fill(dist.begin(), dist.end(), INF);\n\
    \      dist[s] = 0;\n      vector<int> deg_in(V);\n      for (int i = 0; i < V;\
    \ i++) {\n        for (const auto& e : G[i]) deg_in[e.to] += (e.cap > 0);\n  \
    \    }\n      vector<int> st;\n      for (int i = 0; i < V; i++)\n        if (!deg_in[i])\
    \ st.push_back(i);\n      for (int n = 0; n < V; n++) {\n        if (int(st.size())\
    \ == n) assert(false);\n        int now = st[n];\n        for (int i = 0; i <\
    \ (int)G[now].size(); i++) {\n          edge& e = G[now][i];\n          if (e.isrev)\
    \ continue;\n          deg_in[e.to]--;\n          if (deg_in[e.to] == 0) st.push_back(e.to);\n\
    \          if (e.cap <= 0 || dist[now] == INF || dist[e.to] <= dist[now] + e.cost)\
    \ continue;\n          dist[e.to] = dist[now] + e.cost;\n          prevv[e.to]\
    \ = now;\n          preve[e.to] = i;\n        }\n      }\n    } else if (!negative)\n\
    \      dijkstra();\n    else {\n      fill(dist.begin(), dist.end(), INF);\n \
    \     dist[s] = 0;\n      for (int u = 0; u < V; u++) {\n        for (int v =\
    \ 0; v < V; v++) {\n          for (int i = 0; i < (int)G[v].size(); i++) {\n \
    \           edge& e = G[v][i];\n            if (e.cap <= 0 || dist[v] == INF ||\
    \ dist[e.to] <= dist[v] + e.cost) continue;\n            dist[e.to] = dist[v]\
    \ + e.cost;\n            prevv[e.to] = v;\n            preve[e.to] = i;\n    \
    \        if (u == V - 1) assert(false);\n          }\n        }\n      }\n   \
    \ }\n    while (true) {\n      if (dist[t] == INF) return INF;\n      for (int\
    \ v = 0; v < V; v++) h[v] += dist[v];\n\n      Cap d = f;\n      for (int v =\
    \ t; v != s; v = prevv[v]) {\n        d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \      }\n      f -= d;\n      res += d * h[t];\n      for (int v = t; v != s;\
    \ v = prevv[v]) {\n        edge& e = G[prevv[v]][preve[v]];\n        e.cap -=\
    \ d;\n        G[v][e.rev].cap += d;\n      }\n      if (f == 0) break;\n     \
    \ dijkstra();\n    }\n    return res;\n  }\n};\n"
  code: "template <typename Cap, typename Cost>\nstruct MinCostFlow {\n protected:\n\
    \  using P = pair<Cost, int>;\n  struct edge {\n    int to;\n    Cap cap;\n  \
    \  Cost cost;\n    int rev;\n    bool isrev;\n  };\n  vector<Cost> h;\n  vector<Cost>\
    \ dist;\n  vector<int> prevv, preve;\n  bool negative;\n\n public:\n  int V;\n\
    \  vector<vector<edge>> G;\n  Cost INF = numeric_limits<Cost>::max();\n  MinCostFlow()\
    \ {}\n  MinCostFlow(int v) : h(v), dist(v), prevv(v), preve(v), negative(false),\
    \ V(v), G(v) {}\n  void add(int from, int to, Cap cap, Cost cost) {\n    assert(0\
    \ <= from && from < V);\n    assert(0 <= to && to < V);\n    assert(0 <= cap);\n\
    \    if (cap == 0) return;\n    if (cost < 0) negative = true;\n    G[from].push_back({to,\
    \ cap, cost, (int)G[to].size(), false});\n    G[to].push_back({from, 0, -cost,\
    \ (int)G[from].size() - 1, true});\n  }\n  Cost min_cost_flow(int s, int t, Cap\
    \ f, bool DAG = false) {\n    assert(0 <= s && s < V);\n    assert(0 <= t && t\
    \ < V);\n    assert(s != t);\n    assert(0 < f);\n    Cost res = 0;\n    fill(h.begin(),\
    \ h.end(), 0);\n    auto dijkstra = [&]() {\n      priority_queue<P, vector<P>,\
    \ greater<P>> pq;\n      fill(dist.begin(), dist.end(), INF);\n      dist[s] =\
    \ 0;\n      pq.push(P(0, s));\n      while (!pq.empty()) {\n        P p = pq.top();\n\
    \        pq.pop();\n        int v = p.second;\n        if (dist[v] < p.first)\
    \ continue;\n        for (int i = 0; i < (int)G[v].size(); i++) {\n          edge&\
    \ e = G[v][i];\n          if (e.cap <= 0 || dist[e.to] <= dist[v] + e.cost + h[v]\
    \ - h[e.to]) continue;\n          dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n\
    \          prevv[e.to] = v;\n          preve[e.to] = i;\n          pq.push(P(dist[e.to],\
    \ e.to));\n        }\n      }\n    };\n\n    if (DAG) {\n      fill(dist.begin(),\
    \ dist.end(), INF);\n      dist[s] = 0;\n      vector<int> deg_in(V);\n      for\
    \ (int i = 0; i < V; i++) {\n        for (const auto& e : G[i]) deg_in[e.to] +=\
    \ (e.cap > 0);\n      }\n      vector<int> st;\n      for (int i = 0; i < V; i++)\n\
    \        if (!deg_in[i]) st.push_back(i);\n      for (int n = 0; n < V; n++) {\n\
    \        if (int(st.size()) == n) assert(false);\n        int now = st[n];\n \
    \       for (int i = 0; i < (int)G[now].size(); i++) {\n          edge& e = G[now][i];\n\
    \          if (e.isrev) continue;\n          deg_in[e.to]--;\n          if (deg_in[e.to]\
    \ == 0) st.push_back(e.to);\n          if (e.cap <= 0 || dist[now] == INF || dist[e.to]\
    \ <= dist[now] + e.cost) continue;\n          dist[e.to] = dist[now] + e.cost;\n\
    \          prevv[e.to] = now;\n          preve[e.to] = i;\n        }\n      }\n\
    \    } else if (!negative)\n      dijkstra();\n    else {\n      fill(dist.begin(),\
    \ dist.end(), INF);\n      dist[s] = 0;\n      for (int u = 0; u < V; u++) {\n\
    \        for (int v = 0; v < V; v++) {\n          for (int i = 0; i < (int)G[v].size();\
    \ i++) {\n            edge& e = G[v][i];\n            if (e.cap <= 0 || dist[v]\
    \ == INF || dist[e.to] <= dist[v] + e.cost) continue;\n            dist[e.to]\
    \ = dist[v] + e.cost;\n            prevv[e.to] = v;\n            preve[e.to] =\
    \ i;\n            if (u == V - 1) assert(false);\n          }\n        }\n   \
    \   }\n    }\n    while (true) {\n      if (dist[t] == INF) return INF;\n    \
    \  for (int v = 0; v < V; v++) h[v] += dist[v];\n\n      Cap d = f;\n      for\
    \ (int v = t; v != s; v = prevv[v]) {\n        d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \      }\n      f -= d;\n      res += d * h[t];\n      for (int v = t; v != s;\
    \ v = prevv[v]) {\n        edge& e = G[prevv[v]][preve[v]];\n        e.cap -=\
    \ d;\n        G[v][e.rev].cap += d;\n      }\n      if (f == 0) break;\n     \
    \ dijkstra();\n    }\n    return res;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/mincostflow.hpp
  requiredBy: []
  timestamp: '2022-04-16 04:26:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/mincostflow.hpp
layout: document
redirect_from:
- /library/flow/mincostflow.hpp
- /library/flow/mincostflow.hpp.html
title: flow/mincostflow.hpp
---
