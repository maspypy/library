#include "graph/blackbox/scc.hpp"

// 密グラフのscc
// O(N^2/w)
// https://codeforces.com/contest/641/problem/F
pair<int, vc<int>> scc_bitset(vc<My_Bitset> G) {
  using BS = My_Bitset;
  const int N = len(G);
  vc<BS> RG(N, BS(N));
  FOR(i, N) FOR(j, N) RG[i][j] = 1 * G[j][i];

  BS b0(N, 1);
  BS b1(N, 1);

  auto set_used = [&](int v, bool rev) -> void {
    if (!rev) b0[v] = 0;
    if (rev) b1[v] = 0;
  };

  auto find_unused = [&](int v, bool rev) -> int {
    if (!rev) {
      BS &x = G[v];
      x &= b0.range(0, len(x));
      int p = x.prev(len(x));
      x.resize(p + 1);
      return p;
    }
    BS &x = RG[v];
    x &= b1.range(0, len(x));
    int p = x.prev(len(x));
    x.resize(p + 1);
    return p;
  };
  return blackbox_scc(N, set_used, find_unused);
}