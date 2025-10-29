#include "ds/my_bitset.hpp"

// https://codeforces.com/contest/641/problem/F
// DAG があるとき reachability 関係にすべて辺を張る
vc<My_Bitset> transitive_closure(vc<My_Bitset> G) {
  int N = len(G);
  FOR(i, N) G[i][i] = 1;
  FOR(k, N) {
    // G[i][k] and G[k][j]
    FOR(i, N) {
      if (!G[i][k]) continue;
      G[i] |= G[k];
    }
  }
  return G;
}
