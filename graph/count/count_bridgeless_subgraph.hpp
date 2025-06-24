#include "graph/count/count_connected_subgraph.hpp"
#include "setfunc/subset_convolution.hpp"
#include "setfunc/sps_exp.hpp"

// O(N^3 2^N). https://loj.ac/p/6730.
template <typename T, int LIM>
vc<T> count_bridgeless_subgraph(Graph<int, 0> G, bool connected = true) {
  int N = G.N;
  auto dp = count_connected_subgraph<T, LIM>(G);

  FOR(r, 1, N) {
    u32 nbd = 0;
    for (auto& e: G[r])
      if (e.to < r) nbd |= 1 << e.to;

    // before: [0,r) に橋がない
    // after: [0,r] に橋がない
    vc<T> f(1 << (N - 1));
    vc<T> g(1 << (N - 1));
    FOR(L, 1 << r) {
      FOR(R, 1 << (N - 1 - r)) {
        f[L | R << r] = dp[L | R << (1 + r)] * popcnt(L & nbd);
        g[L | R << r] = dp[L | R << (1 + r) | (1 << r)];
      }
    }

    FOR(s, 1 << (N - 1)) f[s] = -f[s];
    f = sps_exp<T, LIM - 1>(f);
    g = subset_convolution<T, LIM - 1>(f, g);
    FOR(L, 1 << r) {
      FOR(R, 1 << (N - 1 - r)) { dp[L | R << (1 + r) | (1 << r)] = g[L | R << r]; }
    }
  }
  if (!connected) dp = sps_exp<T, LIM>(dp);
  return dp;
}
