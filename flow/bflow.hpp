#pragma once
template <class Flow = ll, class Cost = ll, bool MINIMIZE = 1>
struct MinCostFlow {
private:
  static constexpr int objective = (MINIMIZE ? 1 : -1);
  static constexpr int SCALING_FACTOR = 2;
  using V_id = uint32_t;
  using E_id = uint32_t;

  struct Edge {
    friend struct MinCostFlow;

  private:
    V_id frm, to;
    Flow flow, cap;
    Cost cost;
    E_id rev;

  public:
    Edge() = default;

    Edge(const V_id frm, const V_id to, const Flow cap, const Cost cost,
         const E_id rev)
        : frm(frm), to(to), flow(0), cap(cap), cost(cost), rev(rev) {}

    [[nodiscard]] Flow residual_cap() const { return cap - flow; }
  };

public:
  struct EdgePtr {
    friend struct MinCostFlow;

  private:
    const MinCostFlow *instance;
    const V_id v;
    const E_id e;

    EdgePtr(const MinCostFlow *instance, const V_id v, const E_id e)
        : instance(instance), v(v), e(e) {}

    [[nodiscard]] const Edge &edge() const { return instance->g[v][e]; }

    [[nodiscard]] const Edge &rev() const {
      const Edge &e = edge();
      return instance->g[e.to][e.rev];
    }

  public:
    [[nodiscard]] V_id frm() const { return rev().to; }

    [[nodiscard]] V_id to() const { return edge().to; }

    [[nodiscard]] Flow flow() const { return edge().flow; }

    [[nodiscard]] Flow lower() const { return -rev().cap; }

    [[nodiscard]] Flow upper() const { return edge().cap; }

    [[nodiscard]] Cost cost() const { return edge().cost; }

    [[nodiscard]] Cost gain() const { return -edge().cost; }
  };

private:
  V_id n;
  std::vector<std::vector<Edge>> g;
  std::vector<Flow> b;

public:
  MinCostFlow(int n) : n(n) {
    g.resize(n);
    b.resize(n);
  }

  V_id add_vertex() {
    ++n;
    g.resize(n);
    b.resize(n);
    return n - 1;
  }

  std::vector<V_id> add_vertices(const size_t size) {
    std::vector<V_id> ret;
    for (V_id i = 0; i < size; ++i) ret.emplace_back(n + i);
    n += size;
    g.resize(n);
    b.resize(n);
    return ret;
  }

  void add(const V_id frm, const V_id to, const Flow lo, const Flow hi,
           const Cost cost) {
    const E_id e = g[frm].size(), re = frm == to ? e + 1 : g[to].size();
    assert(lo <= hi);
    g[frm].emplace_back(Edge{frm, to, hi, cost * objective, re});
    g[to].emplace_back(Edge{to, frm, -lo, -cost * objective, e});
    edges.eb(EdgePtr{this, frm, e});
  }

  void add_source(const V_id v, const Flow amount) { b[v] += amount; }

  void add_sink(const V_id v, const Flow amount) { b[v] -= amount; }

private:
  static Cost constexpr unreachable = std::numeric_limits<Cost>::max();
  Cost farthest;
  std::vector<Cost> potential;
  std::vector<Cost> dist;
  std::vector<Edge *> parent;
  std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int>>,
                      std::greater<>>
      pq;
  std::vector<V_id> excess_vs, deficit_vs;
  std::vector<EdgePtr> edges;
  Edge &rev(const Edge &e) { return g[e.to][e.rev]; }

  void push(Edge &e, const Flow amount) {
    e.flow += amount;
    g[e.to][e.rev].flow -= amount;
  }

  Cost residual_cost(const V_id frm, const V_id to, const Edge &e) {
    return e.cost + potential[frm] - potential[to];
  }

  bool dual(const Flow delta) {
    dist.assign(n, unreachable);
    parent.assign(n, nullptr);
    excess_vs.erase(std::remove_if(std::begin(excess_vs), std::end(excess_vs),
                                   [&](const V_id v) { return b[v] < delta; }),
                    std::end(excess_vs));
    deficit_vs.erase(
        std::remove_if(std::begin(deficit_vs), std::end(deficit_vs),
                       [&](const V_id v) { return b[v] > -delta; }),
        std::end(deficit_vs));
    for (const auto v: excess_vs) pq.emplace(dist[v] = 0, v);
    farthest = 0;
    std::size_t deficit_count = 0;
    while (!pq.empty()) {
      const auto [d, u] = pq.top();
      pq.pop();
      if (dist[u] < d) continue;
      farthest = d;
      if (b[u] <= -delta) ++deficit_count;
      if (deficit_count >= deficit_vs.size()) break;
      for (auto &e: g[u]) {
        if (e.residual_cap() < delta) continue;
        const auto v = e.to;
        const auto new_dist = d + residual_cost(u, v, e);
        if (new_dist >= dist[v]) continue;
        pq.emplace(dist[v] = new_dist, v);
        parent[v] = &e;
      }
    }
    pq = decltype(pq)();
    for (V_id v = 0; v < n; ++v) {
      potential[v] += std::min(dist[v], farthest);
    }
    return deficit_count > 0;
  }

  void primal(const Flow delta) {
    for (const auto t: deficit_vs) {
      if (dist[t] > farthest) continue;
      Flow f = -b[t];
      V_id v;
      for (v = t; parent[v] != nullptr && f >= delta; v = parent[v]->frm) {
        f = std::min(f, parent[v]->residual_cap());
      }
      f = std::min(f, b[v]);
      if (f < delta) continue;
      for (v = t; parent[v] != nullptr;) {
        auto &e = *parent[v];
        push(e, f);
        const size_t u = parent[v]->frm;
        parent[v] = nullptr;
        v = u;
      }
      b[t] += f;
      b[v] -= f;
    }
  }

  void saturate_negative(const Flow delta) {
    excess_vs.clear();
    deficit_vs.clear();
    for (auto &es: g)
      for (auto &e: es) {
        const Flow rcap = e.residual_cap();
        const Cost rcost = residual_cost(e.frm, e.to, e);
        if (rcost < 0 && rcap >= delta) {
          push(e, rcap);
          b[e.frm] -= rcap;
          b[e.to] += rcap;
        }
      }
    for (V_id v = 0; v < n; ++v)
      if (b[v] != 0) { (b[v] > 0 ? excess_vs : deficit_vs).emplace_back(v); }
  }

public:
  std::pair<bool, i128> solve() {
    potential.resize(n);
    for (auto &es: g)
      for (auto &e: es) {
        const Flow rcap = e.residual_cap();
        if (rcap < 0) {
          push(e, rcap);
          b[e.frm] -= rcap;
          b[e.to] += rcap;
        }
      }

    Flow inf_flow = 1;
    for (const auto &es: g)
      for (const auto &e: es) inf_flow = std::max(inf_flow, e.residual_cap());
    Flow delta = 1;
    while (delta <= inf_flow) delta *= SCALING_FACTOR;

    for (delta /= SCALING_FACTOR; delta; delta /= SCALING_FACTOR) {
      saturate_negative(delta);
      while (dual(delta)) primal(delta);
    }

    i128 value = 0;
    for (const auto &es: g)
      for (const auto &e: es) { value += e.flow * e.cost; }
    value /= 2;

    if (excess_vs.empty() && deficit_vs.empty()) {
      return {true, value / objective};
    } else {
      return {false, value / objective};
    }
  }

  template <class T>
  T get_result_value() {
    T value = 0;
    for (const auto &es: g)
      for (const auto &e: es) { value += (T)(e.flow) * (T)(e.cost); }
    value /= (T)2;
    return value / objective;
  }

  std::vector<Cost> get_potential() {
    std::fill(potential.begin(), potential.end(), 0);
    for (int i = 0; i < (int)n; i++)
      for (const auto &es: g)
        for (const auto &e: es)
          if (e.residual_cap() > 0)
            potential[e.to]
                = std::min(potential[e.to], potential[e.frm] + e.cost);
    return potential;
  }

  std::vector<EdgePtr> get_edges() { return edges; }
};
