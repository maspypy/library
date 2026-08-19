#include "ds/bit_array.hpp"

// https://codeforces.com/contest/641/problem/F
// DAG があるとき reachability 関係にすべて辺を張る
vc<Bit_Array> transitive_closure(vc<Bit_Array> G) {
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
