#pragma once
#include "graph/base.hpp"

// 負辺があっても負閉路がなければ正しく動作する。
// 負閉路があるかどうかは、dist[v][v] < 0 となる v があるかどうかで判定。
template <typename T, typename GT>
vc<vc<T>> warshall_floyd(GT& G) {
  ll N = G.N;
  vv(T, dist, N, N, infty<T>);
  FOR(v, N) {
    dist[v][v] = 0;
    for (auto&& e: G[v]) chmin(dist[v][e.to], e.cost);
  }
  FOR(k, N) FOR(i, N) {
    if (dist[i][k] == infty<T>) continue;
    FOR(j, N) {
      if (dist[k][j] == infty<T>) continue;
      chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
  }
  return dist;
}