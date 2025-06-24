#include "graph/count/count_connected_subgraph.hpp"
#include "setfunc/sps_log.hpp"

// O(N^32^N). https://loj.ac/s/2318552.
template <typename T, int LIM>
vc<T> count_biconnected_subgraph(Graph<int, 0> G) {
  int N = G.N;
  auto dp = count_connected_subgraph<T, LIM>(G);
  FOR(r, N) {
    // r may be art -> r is not art
    vc<T> f(1 << (N - 1));
    FOR(L, 1 << r) FOR(R, 1 << (N - 1 - r)) f[L | R << r] = dp[L | (R << (1 + r)) | (1 << r)];
    f = sps_log<T, LIM - 1>(f);
    FOR(L, 1 << r) FOR(R, 1 << (N - 1 - r)) dp[L | (R << (1 + r)) | (1 << r)] = f[L | R << r];
  }
  // なるほど？
  FOR(v, N) dp[1 << v] = 1;
  return dp;
}
