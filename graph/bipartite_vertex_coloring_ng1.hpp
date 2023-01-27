
// 1 辺を除いて二部グラフになるようにする
// https://codeforces.com/contest/1680/problem/F
template <typename GT>
vc<int> bipartite_vertex_coloring_ng1(GT& G) {
  assert(G.is_prepared());
  const int N = G.N, M = G.M;
  vc<int> V, par(N, -1), color(N, -1);
  V.reserve(N);
  vc<int> dp_0(N), dp_1(N);
  vc<bool> done(M);
  int odd = 0;
  auto dfs = [&](auto& dfs, int v) -> void {
    V.eb(v);
    for (auto&& e: G[v]) {
      if (done[e.id]) continue;
      done[e.id] = 1;
      if (color[e.to] == -1) {
        par[e.to] = v, color[e.to] = color[v] ^ 1;
        dfs(dfs, e.to);
      } else {
        if (color[v] != color[e.to]) dp_0[v]++, dp_0[e.to]--;
        if (color[v] == color[e.to]) dp_1[v]++, dp_1[e.to]--, odd++;
      }
    }
  };
  FOR(v, N) if (color[v] == -1) color[v] = 0, dfs(dfs, v);
  FOR_R(i, N) {
    int v = V[i], p = par[V[i]];
    if (p == -1) continue;
    dp_0[p] += dp_0[v], dp_1[p] += dp_1[v];
  }
  if (odd <= 1) return color;
  FOR(v, N) {
    if (par[v] == -1 || dp_1[v] != odd || (dp_0[v] && dp_1[v])) continue;
    for (auto&& w: V) {
      if (par[w] == -1) continue;
      color[w] = color[par[w]] ^ (w == v ? 0 : 1);
    }
    return color;
  }
  return {};
}