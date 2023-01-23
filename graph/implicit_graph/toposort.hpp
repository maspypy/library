// https://codeforces.com/contest/798/problem/E
// toposort の候補をひとつ出力する。チェックはしない。
// 陽にグラフを作らず、何らかのデータ構造で未訪問の行き先を探す想定。
// set_used(v)：v を使用済に変更する
// find_unused(v)：v の行き先を探す。なければ -1 を返すこと。
template <typename F1, typename F2>
vc<int> toposort(int N, F1 set_used, F2 find_unused) {
  vc<int> V;
  vc<bool> done(N);
  auto dfs = [&](auto self, ll v) -> void {
    set_used(v);
    done[v] = 1;
    while (1) {
      int to = find_unused(v);
      if (to == -1) break;
      self(self, to);
    }
    V.eb(v);
  };
  FOR(v, N) if (!done[v]) dfs(dfs, v);
  return V;
}
