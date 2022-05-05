---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library_checker/graph/min_cost_b-flow.test.cpp
    title: test/library_checker/graph/min_cost_b-flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/bflow.hpp\"\nenum Objective {\n  MINIMIZE = 1,\n  MAXIMIZE\
    \ = -1,\n};\nenum class Status {\n  OPTIMAL,\n  INFEASIBLE,\n};\n\ntemplate <class\
    \ Flow = ll, class Cost = ll,\n          Objective objective = Objective::MINIMIZE,\
    \ Flow SCALING_FACTOR = 2>\nstruct MinCostFlow {\nprivate:\n  using V_id = uint32_t;\n\
    \  using E_id = uint32_t;\n\n  struct Edge {\n    friend struct MinCostFlow;\n\
    \n  private:\n    V_id frm, to;\n    Flow flow, cap;\n    Cost cost;\n    E_id\
    \ rev;\n\n  public:\n    Edge() = default;\n\n    Edge(const V_id frm, const V_id\
    \ to, const Flow cap, const Cost cost,\n         const E_id rev)\n        : frm(frm),\
    \ to(to), flow(0), cap(cap), cost(cost), rev(rev) {}\n\n    [[nodiscard]] Flow\
    \ residual_cap() const { return cap - flow; }\n  };\n\npublic:\n  struct EdgePtr\
    \ {\n    friend struct MinCostFlow;\n\n  private:\n    const MinCostFlow *instance;\n\
    \    const V_id v;\n    const E_id e;\n\n    EdgePtr(const MinCostFlow *instance,\
    \ const V_id v, const E_id e)\n        : instance(instance), v(v), e(e) {}\n\n\
    \    [[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }\n\n\
    \    [[nodiscard]] const Edge &rev() const {\n      const Edge &e = edge();\n\
    \      return instance->g[e.to][e.rev];\n    }\n\n  public:\n    [[nodiscard]]\
    \ V_id frm() const { return rev().to; }\n\n    [[nodiscard]] V_id to() const {\
    \ return edge().to; }\n\n    [[nodiscard]] Flow flow() const { return edge().flow;\
    \ }\n\n    [[nodiscard]] Flow lower() const { return -rev().cap; }\n\n    [[nodiscard]]\
    \ Flow upper() const { return edge().cap; }\n\n    [[nodiscard]] Cost cost() const\
    \ { return edge().cost; }\n\n    [[nodiscard]] Cost gain() const { return -edge().cost;\
    \ }\n  };\n\nprivate:\n  V_id n;\n  std::vector<std::vector<Edge>> g;\n  std::vector<Flow>\
    \ b;\n\npublic:\n  MinCostFlow(int n) : n(n) {\n    g.resize(n);\n    b.resize(n);\n\
    \  }\n\n  V_id add_vertex() {\n    ++n;\n    g.resize(n);\n    b.resize(n);\n\
    \    return n - 1;\n  }\n\n  std::vector<V_id> add_vertices(const size_t size)\
    \ {\n    std::vector<V_id> ret;\n    for (V_id i = 0; i < size; ++i) ret.emplace_back(n\
    \ + i);\n    n += size;\n    g.resize(n);\n    b.resize(n);\n    return ret;\n\
    \  }\n\n  void add(const V_id frm, const V_id to, const Flow lo, const Flow hi,\n\
    \           const Cost cost) {\n    const E_id e = g[frm].size(), re = frm ==\
    \ to ? e + 1 : g[to].size();\n    assert(lo <= hi);\n    g[frm].emplace_back(Edge{frm,\
    \ to, hi, cost * objective, re});\n    g[to].emplace_back(Edge{to, frm, -lo, -cost\
    \ * objective, e});\n    edges.eb(EdgePtr{this, frm, e});\n  }\n\n  void add_source(const\
    \ V_id v, const Flow amount) { b[v] += amount; }\n\n  void add_sink(const V_id\
    \ v, const Flow amount) { b[v] -= amount; }\n\nprivate:\n  static Cost constexpr\
    \ unreachable = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  std::vector<Cost>\
    \ potential;\n  std::vector<Cost> dist;\n  std::vector<Edge *> parent;\n  std::priority_queue<std::pair<Cost,\
    \ int>, std::vector<std::pair<Cost, int>>,\n                      std::greater<>>\n\
    \      pq;\n  std::vector<V_id> excess_vs, deficit_vs;\n  std::vector<EdgePtr>\
    \ edges;\n  Edge &rev(const Edge &e) { return g[e.to][e.rev]; }\n\n  void push(Edge\
    \ &e, const Flow amount) {\n    e.flow += amount;\n    g[e.to][e.rev].flow -=\
    \ amount;\n  }\n\n  Cost residual_cost(const V_id frm, const V_id to, const Edge\
    \ &e) {\n    return e.cost + potential[frm] - potential[to];\n  }\n\n  bool dual(const\
    \ Flow delta) {\n    dist.assign(n, unreachable);\n    parent.assign(n, nullptr);\n\
    \    excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),\n\
    \                                   [&](const V_id v) { return b[v] < delta; }),\n\
    \                    std::end(excess_vs));\n    deficit_vs.erase(\n        std::remove_if(std::begin(deficit_vs),\
    \ std::end(deficit_vs),\n                       [&](const V_id v) { return b[v]\
    \ > -delta; }),\n        std::end(deficit_vs));\n    for (const auto v: excess_vs)\
    \ pq.emplace(dist[v] = 0, v);\n    farthest = 0;\n    std::size_t deficit_count\
    \ = 0;\n    while (!pq.empty()) {\n      const auto [d, u] = pq.top();\n     \
    \ pq.pop();\n      if (dist[u] < d) continue;\n      farthest = d;\n      if (b[u]\
    \ <= -delta) ++deficit_count;\n      if (deficit_count >= deficit_vs.size()) break;\n\
    \      for (auto &e: g[u]) {\n        if (e.residual_cap() < delta) continue;\n\
    \        const auto v = e.to;\n        const auto new_dist = d + residual_cost(u,\
    \ v, e);\n        if (new_dist >= dist[v]) continue;\n        pq.emplace(dist[v]\
    \ = new_dist, v);\n        parent[v] = &e;\n      }\n    }\n    pq = decltype(pq)();\n\
    \    for (V_id v = 0; v < n; ++v) {\n      potential[v] += std::min(dist[v], farthest);\n\
    \    }\n    return deficit_count > 0;\n  }\n\n  void primal(const Flow delta)\
    \ {\n    for (const auto t: deficit_vs) {\n      if (dist[t] > farthest) continue;\n\
    \      Flow f = -b[t];\n      V_id v;\n      for (v = t; parent[v] != nullptr\
    \ && f >= delta; v = parent[v]->frm) {\n        f = std::min(f, parent[v]->residual_cap());\n\
    \      }\n      f = std::min(f, b[v]);\n      if (f < delta) continue;\n     \
    \ for (v = t; parent[v] != nullptr;) {\n        auto &e = *parent[v];\n      \
    \  push(e, f);\n        const size_t u = parent[v]->frm;\n        parent[v] =\
    \ nullptr;\n        v = u;\n      }\n      b[t] += f;\n      b[v] -= f;\n    }\n\
    \  }\n\n  void saturate_negative(const Flow delta) {\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for (auto &es: g)\n      for (auto &e: es) {\n \
    \       const Flow rcap = e.residual_cap();\n        const Cost rcost = residual_cost(e.frm,\
    \ e.to, e);\n        if (rcost < 0 && rcap >= delta) {\n          push(e, rcap);\n\
    \          b[e.frm] -= rcap;\n          b[e.to] += rcap;\n        }\n      }\n\
    \    for (V_id v = 0; v < n; ++v)\n      if (b[v] != 0) { (b[v] > 0 ? excess_vs\
    \ : deficit_vs).emplace_back(v); }\n  }\n\npublic:\n  std::pair<Status, i128>\
    \ solve() {\n    potential.resize(n);\n    for (auto &es: g)\n      for (auto\
    \ &e: es) {\n        const Flow rcap = e.residual_cap();\n        if (rcap < 0)\
    \ {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n          b[e.to]\
    \ += rcap;\n        }\n      }\n\n    Flow inf_flow = 1;\n    for (const auto\
    \ &es: g)\n      for (const auto &e: es) inf_flow = std::max(inf_flow, e.residual_cap());\n\
    \    Flow delta = 1;\n    while (delta <= inf_flow) delta *= SCALING_FACTOR;\n\
    \n    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {\n      saturate_negative(delta);\n\
    \      while (dual(delta)) primal(delta);\n    }\n\n    i128 value = 0;\n    for\
    \ (const auto &es: g)\n      for (const auto &e: es) { value += e.flow * e.cost;\
    \ }\n    value /= 2;\n\n    if (excess_vs.empty() && deficit_vs.empty()) {\n \
    \     return {Status::OPTIMAL, value / objective};\n    } else {\n      return\
    \ {Status::INFEASIBLE, value / objective};\n    }\n  }\n\n  template <class T>\n\
    \  T get_result_value() {\n    T value = 0;\n    for (const auto &es: g)\n   \
    \   for (const auto &e: es) { value += (T)(e.flow) * (T)(e.cost); }\n    value\
    \ /= (T)2;\n    return value / objective;\n  }\n\n  std::vector<Cost> get_potential()\
    \ {\n    std::fill(potential.begin(), potential.end(), 0);\n    for (int i = 0;\
    \ i < (int)n; i++)\n      for (const auto &es: g)\n        for (const auto &e:\
    \ es)\n          if (e.residual_cap() > 0)\n            potential[e.to]\n    \
    \            = std::min(potential[e.to], potential[e.frm] + e.cost);\n    return\
    \ potential;\n  }\n\n  std::vector<EdgePtr> get_edges() { return edges; }\n};\n"
  code: "#pragma once\nenum Objective {\n  MINIMIZE = 1,\n  MAXIMIZE = -1,\n};\nenum\
    \ class Status {\n  OPTIMAL,\n  INFEASIBLE,\n};\n\ntemplate <class Flow = ll,\
    \ class Cost = ll,\n          Objective objective = Objective::MINIMIZE, Flow\
    \ SCALING_FACTOR = 2>\nstruct MinCostFlow {\nprivate:\n  using V_id = uint32_t;\n\
    \  using E_id = uint32_t;\n\n  struct Edge {\n    friend struct MinCostFlow;\n\
    \n  private:\n    V_id frm, to;\n    Flow flow, cap;\n    Cost cost;\n    E_id\
    \ rev;\n\n  public:\n    Edge() = default;\n\n    Edge(const V_id frm, const V_id\
    \ to, const Flow cap, const Cost cost,\n         const E_id rev)\n        : frm(frm),\
    \ to(to), flow(0), cap(cap), cost(cost), rev(rev) {}\n\n    [[nodiscard]] Flow\
    \ residual_cap() const { return cap - flow; }\n  };\n\npublic:\n  struct EdgePtr\
    \ {\n    friend struct MinCostFlow;\n\n  private:\n    const MinCostFlow *instance;\n\
    \    const V_id v;\n    const E_id e;\n\n    EdgePtr(const MinCostFlow *instance,\
    \ const V_id v, const E_id e)\n        : instance(instance), v(v), e(e) {}\n\n\
    \    [[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }\n\n\
    \    [[nodiscard]] const Edge &rev() const {\n      const Edge &e = edge();\n\
    \      return instance->g[e.to][e.rev];\n    }\n\n  public:\n    [[nodiscard]]\
    \ V_id frm() const { return rev().to; }\n\n    [[nodiscard]] V_id to() const {\
    \ return edge().to; }\n\n    [[nodiscard]] Flow flow() const { return edge().flow;\
    \ }\n\n    [[nodiscard]] Flow lower() const { return -rev().cap; }\n\n    [[nodiscard]]\
    \ Flow upper() const { return edge().cap; }\n\n    [[nodiscard]] Cost cost() const\
    \ { return edge().cost; }\n\n    [[nodiscard]] Cost gain() const { return -edge().cost;\
    \ }\n  };\n\nprivate:\n  V_id n;\n  std::vector<std::vector<Edge>> g;\n  std::vector<Flow>\
    \ b;\n\npublic:\n  MinCostFlow(int n) : n(n) {\n    g.resize(n);\n    b.resize(n);\n\
    \  }\n\n  V_id add_vertex() {\n    ++n;\n    g.resize(n);\n    b.resize(n);\n\
    \    return n - 1;\n  }\n\n  std::vector<V_id> add_vertices(const size_t size)\
    \ {\n    std::vector<V_id> ret;\n    for (V_id i = 0; i < size; ++i) ret.emplace_back(n\
    \ + i);\n    n += size;\n    g.resize(n);\n    b.resize(n);\n    return ret;\n\
    \  }\n\n  void add(const V_id frm, const V_id to, const Flow lo, const Flow hi,\n\
    \           const Cost cost) {\n    const E_id e = g[frm].size(), re = frm ==\
    \ to ? e + 1 : g[to].size();\n    assert(lo <= hi);\n    g[frm].emplace_back(Edge{frm,\
    \ to, hi, cost * objective, re});\n    g[to].emplace_back(Edge{to, frm, -lo, -cost\
    \ * objective, e});\n    edges.eb(EdgePtr{this, frm, e});\n  }\n\n  void add_source(const\
    \ V_id v, const Flow amount) { b[v] += amount; }\n\n  void add_sink(const V_id\
    \ v, const Flow amount) { b[v] -= amount; }\n\nprivate:\n  static Cost constexpr\
    \ unreachable = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  std::vector<Cost>\
    \ potential;\n  std::vector<Cost> dist;\n  std::vector<Edge *> parent;\n  std::priority_queue<std::pair<Cost,\
    \ int>, std::vector<std::pair<Cost, int>>,\n                      std::greater<>>\n\
    \      pq;\n  std::vector<V_id> excess_vs, deficit_vs;\n  std::vector<EdgePtr>\
    \ edges;\n  Edge &rev(const Edge &e) { return g[e.to][e.rev]; }\n\n  void push(Edge\
    \ &e, const Flow amount) {\n    e.flow += amount;\n    g[e.to][e.rev].flow -=\
    \ amount;\n  }\n\n  Cost residual_cost(const V_id frm, const V_id to, const Edge\
    \ &e) {\n    return e.cost + potential[frm] - potential[to];\n  }\n\n  bool dual(const\
    \ Flow delta) {\n    dist.assign(n, unreachable);\n    parent.assign(n, nullptr);\n\
    \    excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),\n\
    \                                   [&](const V_id v) { return b[v] < delta; }),\n\
    \                    std::end(excess_vs));\n    deficit_vs.erase(\n        std::remove_if(std::begin(deficit_vs),\
    \ std::end(deficit_vs),\n                       [&](const V_id v) { return b[v]\
    \ > -delta; }),\n        std::end(deficit_vs));\n    for (const auto v: excess_vs)\
    \ pq.emplace(dist[v] = 0, v);\n    farthest = 0;\n    std::size_t deficit_count\
    \ = 0;\n    while (!pq.empty()) {\n      const auto [d, u] = pq.top();\n     \
    \ pq.pop();\n      if (dist[u] < d) continue;\n      farthest = d;\n      if (b[u]\
    \ <= -delta) ++deficit_count;\n      if (deficit_count >= deficit_vs.size()) break;\n\
    \      for (auto &e: g[u]) {\n        if (e.residual_cap() < delta) continue;\n\
    \        const auto v = e.to;\n        const auto new_dist = d + residual_cost(u,\
    \ v, e);\n        if (new_dist >= dist[v]) continue;\n        pq.emplace(dist[v]\
    \ = new_dist, v);\n        parent[v] = &e;\n      }\n    }\n    pq = decltype(pq)();\n\
    \    for (V_id v = 0; v < n; ++v) {\n      potential[v] += std::min(dist[v], farthest);\n\
    \    }\n    return deficit_count > 0;\n  }\n\n  void primal(const Flow delta)\
    \ {\n    for (const auto t: deficit_vs) {\n      if (dist[t] > farthest) continue;\n\
    \      Flow f = -b[t];\n      V_id v;\n      for (v = t; parent[v] != nullptr\
    \ && f >= delta; v = parent[v]->frm) {\n        f = std::min(f, parent[v]->residual_cap());\n\
    \      }\n      f = std::min(f, b[v]);\n      if (f < delta) continue;\n     \
    \ for (v = t; parent[v] != nullptr;) {\n        auto &e = *parent[v];\n      \
    \  push(e, f);\n        const size_t u = parent[v]->frm;\n        parent[v] =\
    \ nullptr;\n        v = u;\n      }\n      b[t] += f;\n      b[v] -= f;\n    }\n\
    \  }\n\n  void saturate_negative(const Flow delta) {\n    excess_vs.clear();\n\
    \    deficit_vs.clear();\n    for (auto &es: g)\n      for (auto &e: es) {\n \
    \       const Flow rcap = e.residual_cap();\n        const Cost rcost = residual_cost(e.frm,\
    \ e.to, e);\n        if (rcost < 0 && rcap >= delta) {\n          push(e, rcap);\n\
    \          b[e.frm] -= rcap;\n          b[e.to] += rcap;\n        }\n      }\n\
    \    for (V_id v = 0; v < n; ++v)\n      if (b[v] != 0) { (b[v] > 0 ? excess_vs\
    \ : deficit_vs).emplace_back(v); }\n  }\n\npublic:\n  std::pair<Status, i128>\
    \ solve() {\n    potential.resize(n);\n    for (auto &es: g)\n      for (auto\
    \ &e: es) {\n        const Flow rcap = e.residual_cap();\n        if (rcap < 0)\
    \ {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n          b[e.to]\
    \ += rcap;\n        }\n      }\n\n    Flow inf_flow = 1;\n    for (const auto\
    \ &es: g)\n      for (const auto &e: es) inf_flow = std::max(inf_flow, e.residual_cap());\n\
    \    Flow delta = 1;\n    while (delta <= inf_flow) delta *= SCALING_FACTOR;\n\
    \n    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {\n      saturate_negative(delta);\n\
    \      while (dual(delta)) primal(delta);\n    }\n\n    i128 value = 0;\n    for\
    \ (const auto &es: g)\n      for (const auto &e: es) { value += e.flow * e.cost;\
    \ }\n    value /= 2;\n\n    if (excess_vs.empty() && deficit_vs.empty()) {\n \
    \     return {Status::OPTIMAL, value / objective};\n    } else {\n      return\
    \ {Status::INFEASIBLE, value / objective};\n    }\n  }\n\n  template <class T>\n\
    \  T get_result_value() {\n    T value = 0;\n    for (const auto &es: g)\n   \
    \   for (const auto &e: es) { value += (T)(e.flow) * (T)(e.cost); }\n    value\
    \ /= (T)2;\n    return value / objective;\n  }\n\n  std::vector<Cost> get_potential()\
    \ {\n    std::fill(potential.begin(), potential.end(), 0);\n    for (int i = 0;\
    \ i < (int)n; i++)\n      for (const auto &es: g)\n        for (const auto &e:\
    \ es)\n          if (e.residual_cap() > 0)\n            potential[e.to]\n    \
    \            = std::min(potential[e.to], potential[e.frm] + e.cost);\n    return\
    \ potential;\n  }\n\n  std::vector<EdgePtr> get_edges() { return edges; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/bflow.hpp
  requiredBy: []
  timestamp: '2022-05-05 15:28:05+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library_checker/graph/min_cost_b-flow.test.cpp
documentation_of: flow/bflow.hpp
layout: document
redirect_from:
- /library/flow/bflow.hpp
- /library/flow/bflow.hpp.html
title: flow/bflow.hpp
---
