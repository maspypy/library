#include "graph/bitset/transitive_closure.hpp"

// 入力は DAG. reachability 関係を保つ最小辺集合を残す.
// N^3/w.
// https://codeforces.com/problemset/problem/1835/F
vc<My_Bitset> transitive_reduction(vc<My_Bitset> G) {
  using BS = My_Bitset;
  int N = len(G);
  vc<BS> H = transitive_closure(G);
  FOR(v, N) H[v][v] = 0;
  vc<BS> HH(N, BS(N));
  FOR(i, N) FOR(j, N) {
    if (H[i][j]) {
      HH[i] |= H[j];
    }
  }

  FOR_R(L, N) FOR(R, L + 1, N) {
    if (HH[L][R]) G[L][R] = 0;
  }
  return G;
}
