#include "flow/maxflow.hpp"
#include "graph/base.hpp"

template <typename WT, typename GT>
pair<WT, vc<int>> maximum_weighted_antichain(GT& G, vc<WT> wt) {
  int N = G.N;
  int s = 2 * N, t = 2 * N + 1;
  MaxFlow<WT> F(2 * N + 2, s, t);
  FOR(i, N) F.add(s, 2 * i + 0, wt[i]);
  FOR(i, N) F.add(2 * i + 1, t, wt[i]);
  for (auto& e: G.edges) F.add(2 * e.frm + 0, 2 * e.to + 1, infty<WT>);
  auto [ans, cut] = F.cut();
  vc<int> antichain;
  FOR(v, N) {
    if (cut[2 * v + 0] == 0 && cut[2 * v + 1] == 1) antichain.eb(v);
  }
  ans = SUM<WT>(wt) - ans;
  return {ans, antichain};
}
