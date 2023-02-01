#pragma once
#include "graph/base.hpp"

template <typename T, typename Graph>
pair<vc<T>, vc<int>> dijkstra(Graph& G, int v) {
  auto N = G.N;
  vector<T> dist(N, INF<T>);
  vector<int> par(N, -1);
  using P = pair<T, int>;

  priority_queue<P, vector<P>, greater<P>> que;

  dist[v] = 0;
  que.emplace(0, v);
  while (!que.empty()) {
    auto [dv, v] = que.top();
    que.pop();
    if (dv > dist[v]) continue;
    for (auto&& e: G[v]) {
      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {
        par[e.to] = e.frm;
        que.emplace(dist[e.to], e.to);
      }
    }
  }
  return {dist, par};
}

// 多点スタート。[dist, par, root]
template <typename T, typename Graph>
tuple<vc<T>, vc<int>, vc<int>> dijkstra(Graph& G, vc<int> vs) {
  assert(G.is_prepared());
  int N = G.N;
  vc<ll> dist(N, INF<T>);
  vc<int> par(N, -1);
  vc<int> root(N, -1);

  using P = pair<T, int>;

  priority_queue<P, vector<P>, greater<P>> que;

  for (auto&& v: vs) {
    dist[v] = 0;
    root[v] = v;
    que.emplace(T(0), v);
  }

  while (!que.empty()) {
    auto [dv, v] = que.top();
    que.pop();
    if (dv > dist[v]) continue;
    for (auto&& e: G[v]) {
      if (chmin(dist[e.to], dist[e.frm] + e.cost)) {
        root[e.to] = root[e.frm];
        par[e.to] = e.frm;
        que.push(mp(dist[e.to], e.to));
      }
    }
  }
  return {dist, par, root};
}
