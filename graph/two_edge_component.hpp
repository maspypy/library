// (成分数, 成分番号の vector)
template <typename GT>
pair<int, vc<int>> two_edge_component(GT& G) {
  assert(!G.is_directed());
  int N = G.N, M = G.M, n_comp = 0;
  vc<int> V, par(N, -2), dp(N), comp(N);
  V.reserve(N);
  vc<bool> used(M);
  auto dfs = [&](auto& dfs, int v) -> void {
    V.eb(v);
    for (auto&& e: G[v]) {
      if (used[e.id]) continue;
      if (par[e.to] != -2) dp[v]++, dp[e.to]--, used[e.id] = 1;
      if (par[e.to] == -2) {
        used[e.id] = 1;
        par[e.to] = v;
        dfs(dfs, e.to);
      }
    }
  };
  FOR(v, N) if (par[v] == -2) { par[v] = -1, dfs(dfs, v); }
  FOR_R(i, N) {
    if (par[V[i]] != -1) dp[par[V[i]]] += dp[V[i]];
  }
  for (auto&& v: V) comp[v] = (dp[v] == 0 ? n_comp++ : comp[par[v]]);
  return {n_comp, comp};
}