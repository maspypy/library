// not verified
#include "graph/base.hpp"
template <typename Graph>
pair<vector<typename Graph::cost_type>, vector<int>> dial(Graph& G, int s) {
  using COST = typename Graph::cost_type;
  assert(G.is_prepared());
  ll W = 0;
  ll N = G.N;
  for (auto&& e: G.edges) chmax(W, e.cost);
  vc<int> S(N * W + 2, -1);
  vc<int> T(N * W + 2, -1);
  vc<int> prev(N);
  vc<int> nxt(N);
  vc<COST> dist(N, W * N + 1);
  vc<int> par(N, -1);
  dist[s] = 0;
  auto add = [&](ll v) -> void {
    ll d = dist[v];
    prev[v] = T[d];
    if (T[d] != -1) nxt[T[d]] = v;
    T[d] = v;
    if (S[d] == -1) S[d] = v;
    nxt[v] = -1;
  };
  auto rm = [&](ll v) -> void {
    ll d = dist[v];
    if (prev[v] != -1) nxt[prev[v]] = nxt[v];
    if (nxt[v] != -1) prev[nxt[v]] = prev[v];
    if (S[d] == v) S[d] = nxt[v];
    if (T[d] == v) T[d] = prev[v];
  };
  FOR(v, N) add(v);

  FOR(d, N * W) {
    ll v = S[d];
    while (v != -1) {
      for (auto&& e: G[v]) {
        ll w = e.to;
        ll dw = d + e.cost;
        if (dw < dist[w]) {
          par[w] = v;
          rm(w);
          dist[w] = dw;
          add(w);
        }
      }
      v = nxt[v];
    }
  }
  FOR(v, N) if (dist[v] > N * W) dist[v] = -1;
  return {dist, par};
}