
// G とその reverse graph に対して dfs を行う
// set_used(int v, bool rev)
// find_used(int v, bool rev)
template <typename F1, typename F2>
pair<int, vc<int>> implicit_graph_scc(int N, F1 set_used, F2 find_unused) {
  vc<int> ord(N);
  {
    int nxt = N;
    vc<bool> vis(N);
    auto dfs = [&](auto& dfs, int v) -> void {
      vis[v] = 1, set_used(v, false);
      while (1) {
        int to = find_unused(v, false);
        if (to == -1) break;
        dfs(dfs, to);
      }
      ord[--nxt] = v;
    };
    FOR(v, N) if (!vis[v]) dfs(dfs, v);
  }
  vc<int> comp(N);
  int nc = 0;
  vc<bool> vis(N);
  auto dfs = [&](auto& dfs, int v) -> void {
    vis[v] = 1, comp[v] = nc, set_used(v, true);
    while (1) {
      int to = find_unused(v, true);
      if (to == -1) break;
      dfs(dfs, to);
    }
  };
  for (auto&& v: ord) {
    if (!vis[v]) dfs(dfs, v), ++nc;
  }
  return {nc, comp};
}
