#include "graph/base.hpp"

// (v,w) or (v,-1)
template <typename GT>
pair<int, int> find_centroids(GT& G, vi weight = {}) {
  int N = G.N;
  if (weight.empty()) weight.assign(N, 1);
  vc<int> par(N, -1);
  vc<int> V(N);
  vc<int> sz(N);
  int l = 0, r = 0;
  V[r++] = 0;
  while (l < r) {
    int v = V[l++];
    for (auto&& e : G[v])
      if (e.to != par[v]) {
        par[e.to] = v;
        V[r++] = e.to;
      }
  }
  FOR_R(i, N) {
    int v = V[i];
    sz[v] += weight[v];
    int p = par[v];
    if (p != -1) sz[p] += sz[v];
  }

  ll FULL = SUM<ll>(weight);
  ll M = FULL / 2;
  auto check = [&](int v) -> bool {
    if (FULL - sz[v] > M) return false;
    for (auto&& e : G[v]) {
      if (e.to != par[v] && sz[e.to] > M) return false;
    }
    return true;
  };
  pair<int, int> ANS = {-1, -1};
  FOR(v, N) if (check(v)) {
    if (ANS.fi != -1) {
      ANS.se = v;
    } else {
      ANS.fi = v;
    }
  }
  return ANS;
}
