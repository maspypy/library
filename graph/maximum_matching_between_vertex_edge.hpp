// (v_i, e_i)
template <typename GT>
vector<pair<int, int>> maximum_matching_between_vertex_edge(GT& G) {
  assert(!G.is_directed());
  assert(G.is_prepared());
  const int N = G.N, M = G.M;
  vc<int> match(M, -1);
  vc<int> par(N, -1); // eid
  vc<bool> used(M);
  vc<bool> vis(N);

  FOR(root, N) {
    if (vis[root]) continue;
    int back_e = -1;
    int frm = -1, to = -1;
    auto dfs = [&](auto& dfs, int v) -> void {
      for (auto&& e: G[v]) {
        if (used[e.id]) continue;
        used[e.id] = 1;
        if (vis[e.to]) {
          back_e = e.id;
          frm = v, to = e.to;
        } else {
          match[e.id] = e.to;
          vis[e.to] = 1;
          par[e.to] = e.id;
          dfs(dfs, e.to);
        }
      }
    };
    vis[root] = 1;
    dfs(dfs, root);
    if (back_e == -1) continue;
    match[back_e] = to;
    int x = to;
    while (x != root) {
      int eid = par[x];
      x = G.edges[eid].frm + G.edges[eid].to - x;
      match[eid] = x;
    }
  }
  vc<pair<int, int>> ANS;
  FOR(i, M) if (match[i] != -1) ANS.eb(match[i], i);
  return ANS;
}