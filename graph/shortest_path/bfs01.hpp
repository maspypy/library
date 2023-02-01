#pragma once
#include "graph/base.hpp"

template <typename T, typename GT>
pair<vc<T>, vc<int>> bfs01(GT& G, int v) {
  assert(G.is_prepared());
  int N = G.N;
  vc<T> dist(N, infty<T>);
  vc<int> par(N, -1);
  deque<int> que;

  dist[v] = 0;
  que.push_front(v);
  while (!que.empty()) {
    auto v = que.front();
    que.pop_front();
    for (auto&& e: G[v]) {
      if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {
        dist[e.to] = dist[e.frm] + e.cost;
        par[e.to] = e.frm;
        if (e.cost == 0)
          que.push_front(e.to);
        else
          que.push_back(e.to);
      }
    }
  }
  return {dist, par};
}

// 多点スタート。[dist, par, root]
template <typename T, typename GT>
tuple<vc<T>, vc<int>, vc<int>> bfs01(GT& G, vc<int> vs) {
  assert(G.is_prepared());
  int N = G.N;
  vc<T> dist(N, infty<T>);
  vc<int> par(N, -1);
  vc<int> root(N, -1);
  deque<int> que;

  for (auto&& v: vs) {
    dist[v] = 0;
    root[v] = v;
    que.push_front(v);
  }

  while (!que.empty()) {
    auto v = que.front();
    que.pop_front();
    for (auto&& e: G[v]) {
      if (dist[e.to] == infty<T> || dist[e.to] > dist[e.frm] + e.cost) {
        dist[e.to] = dist[e.frm] + e.cost;
        root[e.to] = root[e.frm];
        par[e.to] = e.frm;
        if (e.cost == 0)
          que.push_front(e.to);
        else
          que.push_back(e.to);
      }
    }
  }
  return {dist, par, root};
}
