#pragma once
#include "graph/base.hpp"
#include "enumerate/bits.hpp"

/*
return [cost, cycle]
cycle なしの場合：{-1, {}}
*/
template <typename T, typename GT>
pair<T, vc<int>> minimum_hamiltonian_cycle(GT& G) {
  assert(G.is_prepared());
  int n = G.N;
  vv(T, dist, n, n, infty<T>);
  FOR(v, n) {
    for (auto&& e: G[v]) chmin(dist[v][e.to], e.cost);
  }
  n -= 1;
  const int full = (1 << n) - 1;
  vv(T, dp, 1 << n, n, infty<T>);
  FOR(v, n) chmin(dp[1 << v][v], dist[n][v]);
  for (int s = 0; s < (1 << n); ++s) {
    FOR(frm, n) if (dp[s][frm] < infty<T>) {
      enumerate_bits(full - s, [&](int to) -> void {
        int t = s | 1 << to;
        T cost = dist[frm][to];
        if (cost < infty<T>) chmin(dp[t][to], dp[s][frm] + cost);
      });
    }
  }
  int s = (1 << n) - 1;
  T res = infty<T>;
  int best_v = -1;
  FOR(v, n) if (dist[v][n] < infty<T> && dp[s][v] < infty<T>) {
    if (chmin(res, dp[s][v] + dist[v][n])) best_v = v;
  }
  if (res == infty<T>) return {-1, {}};
  vc<int> C = {n, best_v};
  int t = s;
  while (len(C) <= n) {
    int to = C.back();
    int frm = [&]() -> int {
      FOR(frm, n) {
        int s = t ^ (1 << to);
        T inf = infty<T>;
        if (dp[s][frm] < inf && dist[frm][to] < inf
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
