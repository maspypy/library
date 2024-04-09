
// G とその reverse graph に対して dfs を行う
// topo順は正しいが, 探索で見た辺を集めても scc_dag は得られないので注意
// set_used(int v, bool rev)
// find_used(int v, bool rev)
// find は set よりあとに呼ばれる
template <typename F1, typename F2>
pair<int, vc<int>> blackbox_scc(int N, F1 set_used, F2 find_unused) {
  vc<int> ord(N);
  {
    int nxt = N;
    vc<bool> vis(N);
    auto dfs = [&](auto& dfs, int v) -> void {
      assert(v < N && !vis[v]);
      vis[v] = 1, set_used(v, false);
      while (1) {
        int to = find_unused(v, false);
        assert(to < N);
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
      assert(to < N);
      if (to == -1) break;
      dfs(dfs, to);
    }
  };
  for (auto&& v: ord) {
    if (!vis[v]) dfs(dfs, v), ++nc;
  }
  return {nc, comp};
}
