#include "graph/tree.hpp"

// (成分数, 成分番号の vector)
template <typename Graph>
pair<int, vc<int>> two_edge_component(Graph& G) {
  TREE tree(G);
  int N = G.N;
  vc<int> DP(N);
  for (auto&& e: G.edges) {
    if (!tree.in_tree[e.id]) {
      int a = e.frm, b = e.to;
      if (tree.depth[a] < tree.depth[b]) swap(a, b);
      DP[a]++, DP[b]--;
    }
  }
  auto& V = hld.V;
  FOR_R(i, len(V)) {
    int v = V[i];
    int p = tree.parent[v];
    if (p != -1) DP[p] += DP[v];
  }
  int C = 0;
  vc<int> comp(N, -1);
  FOR(v, N) if (DP[v] == 0) comp[v] = C++;
  for (auto&& v: V)
    if (comp[v] == -1) comp[v] = comp[tree.parent[v]];
  return {C, comp};
}
