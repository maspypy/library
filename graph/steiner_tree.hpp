#include "graph/base.hpp"

/*
(n,m): グラフ
k: terminal size
・O(3^kn + 2^k(n+m)log n)
*/
template <typename T, typename Graph>
T steiner_tree(Graph& G, vc<int> terminal, T INF) {
  int k = len(terminal);
  if (k <= 1) return 0;
  int n = G.N;
  vv(T, DP, 1 << k, n, INF);
  FOR(i, k) { DP[1 << i][terminal[i]] = 0; }
  FOR3(s, 1, 1 << k) {
    auto& dp = DP[s];
    FOR_subset(t, s) { FOR(v, n) chmin(dp[v], DP[t][v] + DP[s ^ t][v]); }
    pqg<pair<T, int>> que;
    FOR(v, n) que.emplace(dp[v], v);
    while (len(que)) {
      auto [dv, v] = que.top();
      que.pop();
      if (dv > dp[v]) continue;
      for (auto&& e: G[v]) {
        if (chmin(dp[e.to], dv + e.cost)) que.emplace(dp[e.to], e.to);
      }
    }
  }
  return MIN(DP.back());
}
