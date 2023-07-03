// 辺重みはすべて 1 である
// [dist, par]
template <typename F1, typename F2>
pair<vc<int>, vc<int>> implicit_graph_bfs(int N, int s, F1 set_used,
                                          F2 find_unused) {
  vc<int> que(N);
  vc<int> dist(N, infty<int>);
  vc<int> par(N, -1);
  int l = 0, r = 0;
  dist[s] = 0, set_used(s), que[r++] = s;
  while (l < r) {
    int v = que[l++];
    while (1) {
      int to = find_unused(v);
      if (to == -1) break;
      dist[to] = dist[v] + 1, par[to] = v, set_used(to), que[r++] = to;
    }
  }
  return {dist, par};
}
