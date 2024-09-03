
#include "graph/characteristic_polynomial_of_tree_adjacency_matrix.hpp"
#include "poly/convolution_all.hpp"

// ループなし：1600ms(N=10^5)
// ループあり：3300ms(N=10^5)
template <bool ALLOW_LOOP, typename mint, typename F>
pair<vc<mint>, vc<mint>> tree_walk_generating_function(Graph<int, 0>& G, int s, int t, F weight) {
  int N = G.N;
  // 分母
  auto f = characteristic_poly_of_tree_adjacency_matrix<ALLOW_LOOP, mint>(G, weight);
  // 分子
  // (s,t) パスに沿って成分をかけたものの符号調整 + 他の成分
  using poly = vc<mint>;
  vc<poly> polys;
  pair<int, mint> path_poly = {0, mint(1)};
  vc<bool> on_path(N);
  auto [dist, par] = bfs01<int>(G, s);
  on_path[t] = 1;
  while (t != s) {
    mint w = weight(par[t], t);
    t = par[t], on_path[t] = 1;
    path_poly.fi += 1, path_poly.se *= w; // +wx
  }
  UnionFind uf(N);
  for (auto& e: G.edges) {
    if (on_path[e.frm] || on_path[e.to]) continue;
    uf.merge(e.frm, e.to);
  }
  vvc<int> comp(N);
  FOR(v, N) comp[uf[v]].eb(v);
  FOR(r, N) {
    if (on_path[r] || uf[r] != r) continue;
    vc<int>& V = comp[r];
    Graph<int, 0> H = G.rearrange(V);
    poly f = characteristic_poly_of_tree_adjacency_matrix<ALLOW_LOOP, mint>(H, [&](int i, int j) -> mint { return weight(V[i], V[j]); });
    polys.eb(f);
  }
  poly B = convolution_all<mint>(polys);
  int m = path_poly.fi;
  poly g(len(B) + m);
  FOR(i, len(B)) g[m + i] = path_poly.se * B[i];
  return {g, f};
}
