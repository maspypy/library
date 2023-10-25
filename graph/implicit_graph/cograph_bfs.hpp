#include "graph/base.hpp"

template <typename GT>
pair<vc<int>, vc<int>> cograph_bfs(GT& G, int s) {
  const int N = G.N;
  vc<int> dist(N, infty<int>);
  vc<int> par(N, -1);
  dist[s] = 0;
  vc<int> yet;
  FOR(v, N) if (v != s) yet.eb(v);
  vc<int> que(N);
  vc<bool> NG(N);
  int ql = 0, qr = 1;
  while (ql < qr) {
    int v = que[ql++];
    for (auto& e: G[v]) NG[e.to] = 1;
    vc<int> rest;
    for (auto& to: yet) {
      if (NG[to]) {
        rest.eb(to);
      } else {
        dist[to] = dist[v] + 1, par[to] = v, que[qr++] = to;
      }
    }
    for (auto& e: G[v]) NG[e.to] = 0;
    yet = rest;
  }
  return {dist, par};
}