#pragma once
#include "graph/base.hpp"

/*
return [cost, cycle]
cycle なしの場合：{-1, {}}
*/
template <typename T, typename Graph>
pair<T, vc<int>> minimum_hamiltonian_cycle(Graph& G) {
  assert(G.is_prepared());
  T INF = numeric_limits<T>::max();
  int n = G.N;
  vv(T, dist, n, n, INF);
  FOR(v, n) {
    for (auto&& e: G[v]) chmin(dist[v][e.to], e.cost);
  }
  n -= 1;
  vv(T, dp, 1 << n, n, INF);
  FOR(v, n) chmin(dp[1 << v][v], dist[n][v]);
  FOR(s, 1 << n) FOR(frm, n) if (dp[s][frm] < INF) {
    FOR(to, n) {
      int t = s | 1 << to;
      T cost = dist[frm][to];
      if (s < t && cost < INF) chmin(dp[t][to], dp[s][frm] + cost);
    }
  }
  int s = (1 << n) - 1;
  T res = INF;
  int best_v = -1;
  FOR(v, n) if (dist[v][n] < INF && dp[s][v] < INF) {
    if (chmin(res, dp[s][v] + dist[v][n])) best_v = v;
  }
  if (res == INF) return {-1, {}};
  vc<int> C = {n, best_v};
  int t = s;
  while (len(C) <= n) {
    int to = C.back();
    int frm = [&]() -> int {
      FOR(frm, n) {
        int s = t ^ (1 << to);
        if (dp[s][frm] < INF && dist[frm][to] < INF
            && dp[s][frm] + dist[frm][to] == dp[t][to])
          return frm;
      }
      return -1;
    }();
    C.eb(frm);
    t ^= 1 << to;
  }
  reverse(all(C));
  return {res, C};
}
