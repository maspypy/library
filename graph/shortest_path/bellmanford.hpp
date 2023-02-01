#pragma once
#include "graph/base.hpp"

// 単一始点最短路。負閉路ありでもよい。O(NM) 時間。
// 到達不可能：infty<T>
// 負閉路を経由していくらでも小さくできる：-infty<T>
template <typename T, typename GT>
pair<vc<T>, vc<int>> BellmanFord(GT& G, int s) {
  int N = G.N;
  vc<T> dist(N, infty<T>);
  vc<int> par(N, -1);
  dist[s] = 0;
  int loop = 0;
  while (1) {
    ++loop;
    bool upd = 0;
    FOR(v, N) {
      if (dist[v] == infty<T>) continue;
      for (auto&& e: G[v]) {
        T before = dist[e.to];
        T after = dist[v] + e.cost;
        chmax(after, -infty<T>);
        if (before > after) {
          par[e.to] = v;
          upd = 1;
          if (loop >= N) after = -infty<T>;
          dist[e.to] = after;
        }
      }
    }
    if (!upd) break;
  }
  return {dist, par};
}
