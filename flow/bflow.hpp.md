---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: flow/dual_mcf.hpp
    title: flow/dual_mcf.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/2_library_checker/graph/min_cost_b-flow.test.cpp
    title: test/2_library_checker/graph/min_cost_b-flow.test.cpp
  - icon: ':x:'
    path: test/5_atcoder/abc224h.test.cpp
    title: test/5_atcoder/abc224h.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/bflow.hpp\"\n\n// \u8CA0\u8FBA\u304C\u3042\u3063\u3066\
    \u3082\u52D5\u4F5C\u3059\u308B\u3088\ntemplate <class Flow = ll, class Cost =\
    \ ll>\nstruct MinCostFlow {\nprivate:\n  static constexpr int SCALING_FACTOR =\
    \ 2;\n  using V_id = uint32_t;\n  using E_id = uint32_t;\n\n  struct Edge {\n\
    \    friend struct MinCostFlow;\n\n  private:\n    V_id frm, to;\n    Flow flow,\
    \ cap;\n    Cost cost;\n    E_id rev;\n\n  public:\n    Edge() = default;\n\n\
    \    Edge(const V_id frm, const V_id to, const Flow cap, const Cost cost, const\
    \ E_id rev) : frm(frm), to(to), flow(0), cap(cap), cost(cost), rev(rev) {}\n\n\
    \    [[nodiscard]] Flow residual_cap() const { return cap - flow; }\n  };\n\n\
    public:\n  struct EdgePtr {\n    friend struct MinCostFlow;\n\n  private:\n  \
    \  const MinCostFlow *instance;\n    const V_id v;\n    const E_id e;\n\n    EdgePtr(const\
    \ MinCostFlow *instance, const V_id v, const E_id e) : instance(instance), v(v),\
    \ e(e) {}\n\n    [[nodiscard]] const Edge &edge() const { return instance->g[v][e];\
    \ }\n    [[nodiscard]] const Edge &rev() const {\n      const Edge &e = edge();\n\
    \      return instance->g[e.to][e.rev];\n    }\n\n  public:\n    [[nodiscard]]\
    \ V_id frm() const { return rev().to; }\n    [[nodiscard]] V_id to() const { return\
    \ edge().to; }\n    [[nodiscard]] Flow flow() const { return edge().flow; }\n\
    \    [[nodiscard]] Flow lower() const { return -rev().cap; }\n    [[nodiscard]]\
    \ Flow upper() const { return edge().cap; }\n    [[nodiscard]] Cost cost() const\
    \ { return edge().cost; }\n    [[nodiscard]] Cost gain() const { return -edge().cost;\
    \ }\n  };\n\nprivate:\n  V_id n;\n  std::vector<std::vector<Edge>> g;\n  std::vector<Flow>\
    \ b;\n\npublic:\n  MinCostFlow(int n) : n(n) {\n    g.resize(n);\n    b.resize(n);\n\
    \  }\n\n  V_id add_vertex() {\n    ++n;\n    g.resize(n);\n    b.resize(n);\n\
    \    return n - 1;\n  }\n\n  std::vector<V_id> add_vertices(const size_t size)\
    \ {\n    std::vector<V_id> ret;\n    for (V_id i = 0; i < size; ++i) ret.emplace_back(n\
    \ + i);\n    n += size;\n    g.resize(n);\n    b.resize(n);\n    return ret;\n\
    \  }\n\n  void add(const V_id frm, const V_id to, const Flow lo, const Flow hi,\
    \ const Cost cost) {\n    const E_id e = g[frm].size(), re = frm == to ? e + 1\
    \ : g[to].size();\n    assert(lo <= hi);\n    g[frm].emplace_back(Edge{frm, to,\
    \ hi, cost, re});\n    g[to].emplace_back(Edge{to, frm, -lo, -cost, e});\n   \
    \ edges.eb(EdgePtr{this, frm, e});\n  }\n\n  void add_source(const V_id v, const\
    \ Flow amount) { b[v] += amount; }\n  void add_sink(const V_id v, const Flow amount)\
    \ { b[v] -= amount; }\n\nprivate:\n  static Cost constexpr unreachable = std::numeric_limits<Cost>::max();\n\
    \  Cost farthest;\n  vc<Cost> potential, dist;\n  vc<Edge *> parent;\n  pqg<pair<Cost,\
    \ int>> pq;\n  vc<V_id> excess_vs, deficit_vs;\n  vc<EdgePtr> edges;\n  Edge &rev(const\
    \ Edge &e) { return g[e.to][e.rev]; }\n\n  void push(Edge &e, const Flow amount)\
    \ {\n    e.flow += amount;\n    g[e.to][e.rev].flow -= amount;\n  }\n\n  Cost\
    \ residual_cost(const V_id frm, const V_id to, const Edge &e) { return e.cost\
    \ + potential[frm] - potential[to]; }\n\n  bool dual(const Flow delta) {\n   \
    \ dist.assign(n, unreachable);\n    parent.assign(n, nullptr);\n    excess_vs.erase(remove_if(all(excess_vs),\
    \ [&](const V_id v) { return b[v] < delta; }), end(excess_vs));\n    deficit_vs.erase(remove_if(all(deficit_vs),\
    \ [&](const V_id v) { return b[v] > -delta; }), end(deficit_vs));\n    for (const\
    \ auto v: excess_vs) pq.emplace(dist[v] = 0, v);\n    farthest = 0;\n    size_t\
    \ deficit_count = 0;\n    while (!pq.empty()) {\n      const auto [d, u] = pq.top();\n\
    \      pq.pop();\n      if (dist[u] < d) continue;\n      farthest = d;\n    \
    \  if (b[u] <= -delta) ++deficit_count;\n      if (deficit_count >= deficit_vs.size())\
    \ break;\n      for (auto &e: g[u]) {\n        if (e.residual_cap() < delta) continue;\n\
    \        const auto v = e.to;\n        const auto new_dist = d + residual_cost(u,\
    \ v, e);\n        if (new_dist >= dist[v]) continue;\n        pq.emplace(dist[v]\
    \ = new_dist, v);\n        parent[v] = &e;\n      }\n    }\n    pq = decltype(pq)();\n\
    \    for (V_id v = 0; v < n; ++v) { potential[v] += std::min(dist[v], farthest);\
    \ }\n    return deficit_count > 0;\n  }\n\n  void primal(const Flow delta) {\n\
    \    for (const auto t: deficit_vs) {\n      if (dist[t] > farthest) continue;\n\
    \      Flow f = -b[t];\n      V_id v;\n      for (v = t; parent[v] != nullptr\
    \ && f >= delta; v = parent[v]->frm) { f = std::min(f, parent[v]->residual_cap());\
    \ }\n      f = std::min(f, b[v]);\n      if (f < delta) continue;\n      for (v\
    \ = t; parent[v] != nullptr;) {\n        auto &e = *parent[v];\n        push(e,\
    \ f);\n        const size_t u = parent[v]->frm;\n        parent[v] = nullptr;\n\
    \        v = u;\n      }\n      b[t] += f;\n      b[v] -= f;\n    }\n  }\n\n \
    \ void saturate_negative(const Flow delta) {\n    excess_vs.clear();\n    deficit_vs.clear();\n\
    \    for (auto &es: g)\n      for (auto &e: es) {\n        const Flow rcap = e.residual_cap();\n\
    \        const Cost rcost = residual_cost(e.frm, e.to, e);\n        if (rcost\
    \ < 0 && rcap >= delta) {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n\
    \          b[e.to] += rcap;\n        }\n      }\n    for (V_id v = 0; v < n; ++v)\n\
    \      if (b[v] != 0) { (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v); }\n\
    \  }\n\npublic:\n  std::pair<bool, i128> solve() {\n    potential.resize(n);\n\
    \    for (auto &es: g)\n      for (auto &e: es) {\n        const Flow rcap = e.residual_cap();\n\
    \        if (rcap < 0) {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n\
    \          b[e.to] += rcap;\n        }\n      }\n    Flow inf_flow = 1;\n    for\
    \ (const auto &es: g)\n      for (const auto &e: es) inf_flow = std::max(inf_flow,\
    \ e.residual_cap());\n    Flow delta = 1;\n    while (delta <= inf_flow) delta\
    \ *= SCALING_FACTOR;\n\n    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR)\
    \ {\n      saturate_negative(delta);\n      while (dual(delta)) primal(delta);\n\
    \    }\n\n    i128 value = 0;\n    for (const auto &es: g)\n      for (const auto\
    \ &e: es) { value += i128(e.flow) * e.cost; }\n    value /= 2;\n\n    if (excess_vs.empty()\
    \ && deficit_vs.empty()) {\n      return {true, value};\n    } else {\n      return\
    \ {false, value};\n    }\n  }\n\n  template <class T>\n  T get_result_value()\
    \ {\n    T value = 0;\n    for (const auto &es: g)\n      for (const auto &e:\
    \ es) { value += (T)(e.flow) * (T)(e.cost); }\n    value /= (T)2;\n    return\
    \ value;\n  }\n\n  std::vector<Cost> get_potential() {\n    std::fill(potential.begin(),\
    \ potential.end(), 0);\n    for (int i = 0; i < (int)n; i++)\n      for (const\
    \ auto &es: g)\n        for (const auto &e: es)\n          if (e.residual_cap()\
    \ > 0) potential[e.to] = std::min(potential[e.to], potential[e.frm] + e.cost);\n\
    \    return potential;\n  }\n\n  std::vector<EdgePtr> get_edges() { return edges;\
    \ }\n};\n"
  code: "#pragma once\n\n// \u8CA0\u8FBA\u304C\u3042\u3063\u3066\u3082\u52D5\u4F5C\
    \u3059\u308B\u3088\ntemplate <class Flow = ll, class Cost = ll>\nstruct MinCostFlow\
    \ {\nprivate:\n  static constexpr int SCALING_FACTOR = 2;\n  using V_id = uint32_t;\n\
    \  using E_id = uint32_t;\n\n  struct Edge {\n    friend struct MinCostFlow;\n\
    \n  private:\n    V_id frm, to;\n    Flow flow, cap;\n    Cost cost;\n    E_id\
    \ rev;\n\n  public:\n    Edge() = default;\n\n    Edge(const V_id frm, const V_id\
    \ to, const Flow cap, const Cost cost, const E_id rev) : frm(frm), to(to), flow(0),\
    \ cap(cap), cost(cost), rev(rev) {}\n\n    [[nodiscard]] Flow residual_cap() const\
    \ { return cap - flow; }\n  };\n\npublic:\n  struct EdgePtr {\n    friend struct\
    \ MinCostFlow;\n\n  private:\n    const MinCostFlow *instance;\n    const V_id\
    \ v;\n    const E_id e;\n\n    EdgePtr(const MinCostFlow *instance, const V_id\
    \ v, const E_id e) : instance(instance), v(v), e(e) {}\n\n    [[nodiscard]] const\
    \ Edge &edge() const { return instance->g[v][e]; }\n    [[nodiscard]] const Edge\
    \ &rev() const {\n      const Edge &e = edge();\n      return instance->g[e.to][e.rev];\n\
    \    }\n\n  public:\n    [[nodiscard]] V_id frm() const { return rev().to; }\n\
    \    [[nodiscard]] V_id to() const { return edge().to; }\n    [[nodiscard]] Flow\
    \ flow() const { return edge().flow; }\n    [[nodiscard]] Flow lower() const {\
    \ return -rev().cap; }\n    [[nodiscard]] Flow upper() const { return edge().cap;\
    \ }\n    [[nodiscard]] Cost cost() const { return edge().cost; }\n    [[nodiscard]]\
    \ Cost gain() const { return -edge().cost; }\n  };\n\nprivate:\n  V_id n;\n  std::vector<std::vector<Edge>>\
    \ g;\n  std::vector<Flow> b;\n\npublic:\n  MinCostFlow(int n) : n(n) {\n    g.resize(n);\n\
    \    b.resize(n);\n  }\n\n  V_id add_vertex() {\n    ++n;\n    g.resize(n);\n\
    \    b.resize(n);\n    return n - 1;\n  }\n\n  std::vector<V_id> add_vertices(const\
    \ size_t size) {\n    std::vector<V_id> ret;\n    for (V_id i = 0; i < size; ++i)\
    \ ret.emplace_back(n + i);\n    n += size;\n    g.resize(n);\n    b.resize(n);\n\
    \    return ret;\n  }\n\n  void add(const V_id frm, const V_id to, const Flow\
    \ lo, const Flow hi, const Cost cost) {\n    const E_id e = g[frm].size(), re\
    \ = frm == to ? e + 1 : g[to].size();\n    assert(lo <= hi);\n    g[frm].emplace_back(Edge{frm,\
    \ to, hi, cost, re});\n    g[to].emplace_back(Edge{to, frm, -lo, -cost, e});\n\
    \    edges.eb(EdgePtr{this, frm, e});\n  }\n\n  void add_source(const V_id v,\
    \ const Flow amount) { b[v] += amount; }\n  void add_sink(const V_id v, const\
    \ Flow amount) { b[v] -= amount; }\n\nprivate:\n  static Cost constexpr unreachable\
    \ = std::numeric_limits<Cost>::max();\n  Cost farthest;\n  vc<Cost> potential,\
    \ dist;\n  vc<Edge *> parent;\n  pqg<pair<Cost, int>> pq;\n  vc<V_id> excess_vs,\
    \ deficit_vs;\n  vc<EdgePtr> edges;\n  Edge &rev(const Edge &e) { return g[e.to][e.rev];\
    \ }\n\n  void push(Edge &e, const Flow amount) {\n    e.flow += amount;\n    g[e.to][e.rev].flow\
    \ -= amount;\n  }\n\n  Cost residual_cost(const V_id frm, const V_id to, const\
    \ Edge &e) { return e.cost + potential[frm] - potential[to]; }\n\n  bool dual(const\
    \ Flow delta) {\n    dist.assign(n, unreachable);\n    parent.assign(n, nullptr);\n\
    \    excess_vs.erase(remove_if(all(excess_vs), [&](const V_id v) { return b[v]\
    \ < delta; }), end(excess_vs));\n    deficit_vs.erase(remove_if(all(deficit_vs),\
    \ [&](const V_id v) { return b[v] > -delta; }), end(deficit_vs));\n    for (const\
    \ auto v: excess_vs) pq.emplace(dist[v] = 0, v);\n    farthest = 0;\n    size_t\
    \ deficit_count = 0;\n    while (!pq.empty()) {\n      const auto [d, u] = pq.top();\n\
    \      pq.pop();\n      if (dist[u] < d) continue;\n      farthest = d;\n    \
    \  if (b[u] <= -delta) ++deficit_count;\n      if (deficit_count >= deficit_vs.size())\
    \ break;\n      for (auto &e: g[u]) {\n        if (e.residual_cap() < delta) continue;\n\
    \        const auto v = e.to;\n        const auto new_dist = d + residual_cost(u,\
    \ v, e);\n        if (new_dist >= dist[v]) continue;\n        pq.emplace(dist[v]\
    \ = new_dist, v);\n        parent[v] = &e;\n      }\n    }\n    pq = decltype(pq)();\n\
    \    for (V_id v = 0; v < n; ++v) { potential[v] += std::min(dist[v], farthest);\
    \ }\n    return deficit_count > 0;\n  }\n\n  void primal(const Flow delta) {\n\
    \    for (const auto t: deficit_vs) {\n      if (dist[t] > farthest) continue;\n\
    \      Flow f = -b[t];\n      V_id v;\n      for (v = t; parent[v] != nullptr\
    \ && f >= delta; v = parent[v]->frm) { f = std::min(f, parent[v]->residual_cap());\
    \ }\n      f = std::min(f, b[v]);\n      if (f < delta) continue;\n      for (v\
    \ = t; parent[v] != nullptr;) {\n        auto &e = *parent[v];\n        push(e,\
    \ f);\n        const size_t u = parent[v]->frm;\n        parent[v] = nullptr;\n\
    \        v = u;\n      }\n      b[t] += f;\n      b[v] -= f;\n    }\n  }\n\n \
    \ void saturate_negative(const Flow delta) {\n    excess_vs.clear();\n    deficit_vs.clear();\n\
    \    for (auto &es: g)\n      for (auto &e: es) {\n        const Flow rcap = e.residual_cap();\n\
    \        const Cost rcost = residual_cost(e.frm, e.to, e);\n        if (rcost\
    \ < 0 && rcap >= delta) {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n\
    \          b[e.to] += rcap;\n        }\n      }\n    for (V_id v = 0; v < n; ++v)\n\
    \      if (b[v] != 0) { (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v); }\n\
    \  }\n\npublic:\n  std::pair<bool, i128> solve() {\n    potential.resize(n);\n\
    \    for (auto &es: g)\n      for (auto &e: es) {\n        const Flow rcap = e.residual_cap();\n\
    \        if (rcap < 0) {\n          push(e, rcap);\n          b[e.frm] -= rcap;\n\
    \          b[e.to] += rcap;\n        }\n      }\n    Flow inf_flow = 1;\n    for\
    \ (const auto &es: g)\n      for (const auto &e: es) inf_flow = std::max(inf_flow,\
    \ e.residual_cap());\n    Flow delta = 1;\n    while (delta <= inf_flow) delta\
    \ *= SCALING_FACTOR;\n\n    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR)\
    \ {\n      saturate_negative(delta);\n      while (dual(delta)) primal(delta);\n\
    \    }\n\n    i128 value = 0;\n    for (const auto &es: g)\n      for (const auto\
    \ &e: es) { value += i128(e.flow) * e.cost; }\n    value /= 2;\n\n    if (excess_vs.empty()\
    \ && deficit_vs.empty()) {\n      return {true, value};\n    } else {\n      return\
    \ {false, value};\n    }\n  }\n\n  template <class T>\n  T get_result_value()\
    \ {\n    T value = 0;\n    for (const auto &es: g)\n      for (const auto &e:\
    \ es) { value += (T)(e.flow) * (T)(e.cost); }\n    value /= (T)2;\n    return\
    \ value;\n  }\n\n  std::vector<Cost> get_potential() {\n    std::fill(potential.begin(),\
    \ potential.end(), 0);\n    for (int i = 0; i < (int)n; i++)\n      for (const\
    \ auto &es: g)\n        for (const auto &e: es)\n          if (e.residual_cap()\
    \ > 0) potential[e.to] = std::min(potential[e.to], potential[e.frm] + e.cost);\n\
    \    return potential;\n  }\n\n  std::vector<EdgePtr> get_edges() { return edges;\
    \ }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/bflow.hpp
  requiredBy:
  - flow/dual_mcf.hpp
  timestamp: '2024-11-20 19:40:41+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/5_atcoder/abc224h.test.cpp
  - test/2_library_checker/graph/min_cost_b-flow.test.cpp
documentation_of: flow/bflow.hpp
layout: document
redirect_from:
- /library/flow/bflow.hpp
- /library/flow/bflow.hpp.html
title: flow/bflow.hpp
---
