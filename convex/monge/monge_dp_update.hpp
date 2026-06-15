
#include "convex/monotone_minima.hpp"
#include "convex/smawk.hpp"

template <typename T, typename F>
vc<T> monge_dp_update(int N, vc<T>& dp, F f) {
  assert(len(dp) == N + 1);

  auto better = [&](int i, int j, int k) -> bool {
    if (i <= k) return false;
    if (i <= j) return true;
    return dp[j] + f(j, i) > dp[k] + f(k, i);
  };

  vc<int> I = monotone_minima(N + 1, N + 1, better);
  // vc<int> I = smawk(N + 1, N + 1, better);

  vc<T> newdp(N + 1, infty<T>);
  FOR(j, N + 1) {
    int i = I[j];
    if (i < j) newdp[j] = dp[i] + f(i, j);
  }
  return newdp;
}