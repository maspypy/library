
#include "graph/base.hpp"
#include "graph/tree.hpp"

template <typename TREE, typename Data, typename F1, typename F2, typename F3>
vc<Data> tree_dp(TREE& tree, F1 f_ee, F2 f_ev, F3 f_ve, const Data unit) {
  assert(!tree.G.is_directed());

  int N = tree.G.N;
  vc<Data> dp(N, unit);
  FOR_R(i, 1, N) {
    int v = tree.V[i];
    dp[v] = f_ev(dp[v], v);
    for (auto&& e: tree.G[v])
      if (e.to == tree.parent[v]) { dp[e.to] = f_ee(dp[e.to], f_ve(dp[v], e)); }
  }
  return dp;
};