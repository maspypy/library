
// 密グラフの重みなし最短路問題
// 01 行列を vc<bitset> の形で渡す
// O(N^2/w)
// 参考：(4000,4000) を 4000 回で 2 秒以内？
template <typename BITSET>
vc<int> bfs_bitset(vc<BITSET>& G, int s) {
  int N = len(G);
  vc<int> dist(N, -1);
  BITSET unused;
  FOR(v, N) unused[v] = 1;
  BITSET que;
  que[s] = 1;

  int d = 0;
  while (1) {
    int p = que._Find_first();
    if (p >= N) break;
    BITSET nxt;
    while (p < N) {
      dist[p] = d;
      unused[p] = 0;
      nxt |= G[p];
      p = que._Find_next(p);
    }
    que = nxt & unused;
    ++d;
  }
  return dist;
}
