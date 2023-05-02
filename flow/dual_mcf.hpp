#include "flow/bflow.hpp"

// INF 辺のオーバーフロー関連が未考察
// minimize sum b[v]p[v] + sum_{uv}c[uv]max(0, -p[u]+p[v]-w[uv]))
// sum_v b[v] = 0, c[uv] >= 0
struct Dual_MCF {
  MinCostFlow<ll, ll> G;
  Dual_MCF(int N) : G(N) {}

  // b[v]p[v]
  void add_b(int v, ll b) { G.add_source(v, b); }

  // c[uv]max(0, -p[u]+p[v]-w)
  void add_c(int u, int v, ll w, ll c) { G.add(u, v, 0, c, w); }

  // -p[u]+p[v]<=w
  void add_constraint(int u, int v, int w, ll inf = infty<int>) {
    add_c(u, v, w, inf);
  }

  // min_val, p
  // if ng: {infty<i128>, {}}
  pair<i128, vc<ll>> solve() {
    auto [ok, val] = G.solve();
    if (!ok) return {infty<i128>, {}};
    auto P = G.get_potential();
    return {-val, P};
  }
};
