#include "graph/hld.hpp"

template <typename Graph>
pair<int, vc<int>> two_edge_component(Graph& G) {
  HLD hld(G);
  int N = G.N;
  vc<int> DP(N);
  for (auto&& e: G.edges) {
    if (!hld.in_tree[e.id]) {
      int a = e.frm, b = e.to;
      if (hld.depth[a] < hld.depth[b]) swap(a, b);
      DP[a]++, DP[b]--;
    }
  }
  auto& V = hld.V;
  FOR_R(i, len(V)) {
    int v = V[i];
    int p = hld.parent[v];
    if (p != -1) DP[p] += DP[v];
  }
  int C = 0;
  vc<int> comp(N, -1);
  FOR(v, N) if (DP[v] == 0) comp[v] = C++;
  for (auto&& v: V)
    if (comp[v] == -1) comp[v] = comp[hld.parent[v]];
  return {C, comp};
}
