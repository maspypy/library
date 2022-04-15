#pragma once
#include "graph/base.hpp"

// 単一始点最短路。負閉路ありでもよい。O(NM) 時間。
// 到達不可能：INF
// 負閉路を経由していくらでも小さくできる：-INF
template <typename T, T INF, typename Graph>
pair<vc<T>, vc<int>> BellmanFord(Graph& G, int s) {
  int N = G.N;
  vc<T> dist(N, INF);
  vc<int> par(N, -1);
  dist[s] = 0;
  int loop = 0;
  while (1) {
    ++loop;
    bool upd = 0;
    FOR(v, N) {
      if (dist[v] == INF) continue;
      for (auto&& e: G[v]) {
        T before = dist[e.to];
        T after = dist[v] + e.cost;
        chmax(after, -INF);
        if (before > after) {
          par[e.to] = v;
          upd = 1;
          if (loop >= N) after = -INF;
          dist[e.to] = after;
        }
      }
    }
    if (!upd) break;
  }
  return {dist, par};
}
