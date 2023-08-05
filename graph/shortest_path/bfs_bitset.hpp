#include "ds/my_bitset.hpp"

// 密グラフの重みなし最短路問題
// 01 行列を vc<bitset> の形で渡す
// O(N^2/w)
// 参考：(4000,4000) を 4000 回で 2 秒以内？
template <typename BITSET>
vc<int> bfs_bitset(vc<BITSET>& G, int s) {
  const int N = len(G);
  assert(0 <= s && s < N);
  vc<int> dist(N, -1);
  BITSET unused, que;
  if constexpr (is_same_v<BITSET, My_Bitset>) {
    unused = BITSET(N, 1);
    que = BITSET(N, 0);
  }
  FOR(v, N) unused[v] = 1;
  que[s] = 1;

  int d = 0;
  while (1) {
    int p = que._Find_first();
    if (p >= N) break;
    BITSET nxt;
    if constexpr (is_same_v<BITSET, My_Bitset>) { nxt = BITSET(N); }
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
