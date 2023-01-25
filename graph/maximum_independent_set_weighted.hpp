#include "graph/base.hpp"

// meed in middle で O(N2^{N/2})
// 自己ループ ok（独立集合として使えない点）
template <typename T, typename GT>
vc<int> maximum_independent_set_weighted(GT& G, vc<T> weight) {
  const int N = G.N;
  assert(G.N <= 64);
  vc<u64> nbd(N);
  FOR(v, N) {
    for (auto&& e: G[v]) { nbd[v] |= u64(1) << (e.to); }
  }
  int NL = ceil(N, 2);
  int NR = N - NL;
  vc<u64> nbd_L(1 << NL);
  vc<T> wt_L(1 << NL);
  FOR(i, NL) FOR(s, 1 << i) { nbd_L[s | 1 << i] = nbd_L[s] | nbd[i]; }
  FOR(i, NL) FOR(s, 1 << i) { wt_L[s | 1 << i] = wt_L[s] + weight[i]; }
  vc<u64> nbd_R(1 << NR);
  vc<T> wt_R(1 << NR);
  FOR(i, NR) FOR(s, 1 << i) { nbd_R[s | 1 << i] = nbd_R[s] | nbd[NL + i]; }
  FOR(i, NR) FOR(s, 1 << i) { wt_R[s | 1 << i] = wt_R[s] + weight[NL + i]; }

  FOR(s, 1 << NL) if (nbd_L[s] & s) wt_L[s] = -1;
  FOR(s, 1 << NR) if (nbd_R[s] >> NL & s) wt_R[s] = -1;

  vc<T> dp = wt_R;
  FOR(i, NR) FOR(s, 1 << NR) {
    int t = s | 1 << i;
    if (s < t) chmax(dp[t], dp[s]);
  }
  reverse(all(dp));
  T best = 0;
  int best_s = 0;
  FOR(s, 1 << NL) {
    if (chmax(best, wt_L[s] + dp[(nbd_L[s] >> NL)])) best_s = s;
  }
  int s = best_s;
  int used = nbd_L[s] >> NL;
  FOR(t, 1 << NR) {
    if (used & t) continue;
    if (wt_L[s] + wt_R[t] == best) {
      vc<int> res;
      FOR(i, NL) if (s & 1 << i) res.eb(i);
      FOR(i, NR) if (t & 1 << i) res.eb(NL + i);
      return res;
    }
  }
  assert(0);
  return {};
}