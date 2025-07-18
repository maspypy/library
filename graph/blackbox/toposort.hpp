// set_used(v)：v を使用済に変更する
// find_unused(v)：v の行き先を探す。なければ -1 を返すこと。
// https://codeforces.com/contest/1158/problem/C
template <typename F0, typename F1, typename F2>
vc<int> blackbox_toposort(int N, F0 init, F1 set_used, F2 find_unused,
                          bool check = true) {
  init();
  vc<int> V;
  vc<bool> done(N);
  auto dfs = [&](auto& dfs, int v) -> void {
    set_used(v);
    done[v] = 1;
    while (1) {
      int to = find_unused(v);
      if (to == -1) break;
      dfs(dfs, to);
    }
    V.eb(v);
  };
  FOR(v, N) if (!done[v]) dfs(dfs, v);
  reverse(all(V));
  if (check) {
    init();
    FOR_R(i, N) {
      int v = V[i];
      if (find_unused(v) != -1) {
        return {};
      }
      set_used(v);
    }
  }
  return V;
}
