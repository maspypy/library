#include "graph/base.hpp"

template <typename GT>
pair<vc<int>, vc<int>> complement_graph_bfs(GT& G, int s) {
  static vc<int> que, NG, dist, par, yet;
  const int N = G.N;
  if (len(que) < N) que.resize(N);
  if (len(NG) < N) NG.resize(N);
  if (len(yet) < N) yet.resize(N);
  dist.assign(N, infty<int>);
  par.assign(N, -1);
  int ql = 0, qr = 0;
  dist[s] = 0, que[qr++] = s;
  int p = 0;
  FOR(v, N) if (v != s) yet[p++] = v;
  while (ql < qr) {
    int v = que[ql++];
    for (auto& e: G[v]) NG[e.to] = 1;
    for (int i = p - 1; i >= 0; --i) {
      int to = yet[i];
      if (NG[to]) continue;
      dist[to] = dist[v] + 1, par[to] = v, que[qr++] = to;
      swap(yet[i], yet[--p]);
    }
    for (auto& e: G[v]) NG[e.to] = 0;
  }
  return {dist, par};
}
