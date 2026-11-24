// Source: https://github.com/maspypy/library/blob/main/graph/bitset/transitive_closure.hpp
#include "ds/bit_array.hpp"
#include "graph/strongly_connected_component.hpp"

// https://codeforces.com/contest/641/problem/F
// https://atcoder.jp/contests/pakencamp-2023-day2/tasks/pakencamp_2023_day2_e
// reachability 関係にすべて辺を張る
vc<Bit_Array> transitive_closure(vc<Bit_Array> G) {
  int N = len(G);
  FOR(i, N) G[i][i] = 0;

  FOR(k, N) {
    // G[i][k] and G[k][j]
    FOR(i, N) {
      if (!G[i][k]) continue;
      G[i] |= G[k];
    }
  }
  return G;
}
