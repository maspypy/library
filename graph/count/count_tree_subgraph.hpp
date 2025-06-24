#include "graph/base.hpp"
#include "setfunc/sps_exp.hpp"

// O(N^22^N). https://atcoder.jp/contests/abc253/tasks/abc253_h
template <typename T, int LIM>
vc<T> count_tree_subgraph(Graph<int, 0> G) {
  int N = G.N;
  vc<T> dp(1 << N);
  FOR(r, N) {
    u32 nbd = 0;
    for (auto& e: G[r])
      if (e.to < r) nbd |= 1 << e.to;
    vc<T> f(1 << r);
    FOR(s, 1 << r) f[s] = dp[s] * popcnt(nbd & s);
    f = sps_exp<T, LIM>(f);
    FOR(s, 1 << r) dp[s | 1 << r] = f[s];
  }
  return dp;
}
