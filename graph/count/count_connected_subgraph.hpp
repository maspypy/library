#include "graph/base.hpp"
#include "setfunc/sps_log.hpp"

// O(N^2 2^N)
template <typename T, int LIM>
vc<T> count_connected_subgraph(Graph<int, 0> G) {
  int N = G.N;
  assert(N <= LIM);
  vc<T> pw(G.M + 1, 1);
  FOR(i, G.M) pw[i + 1] = pw[i] + pw[i];

  // edge
  vc<int> E(1 << N);
  for (auto& e: G.edges) { E[(1 << e.frm) | (1 << e.to)]++; }
  FOR(i, N) FOR(s, 1 << N) {
    int t = s | 1 << i;
    if (s < t) E[t] += E[s];
  }

  // any graph
  vc<T> dp(1 << N);
  FOR(s, 1 << N) dp[s] = pw[E[s]];

  // connected
  return sps_log<T, LIM>(dp);
}