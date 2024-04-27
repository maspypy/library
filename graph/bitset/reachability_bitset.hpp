#include "ds/my_bitset.hpp"

// https://codeforces.com/contest/641/problem/F
vc<My_Bitset> reachability_bitset(vc<My_Bitset> G) {
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
