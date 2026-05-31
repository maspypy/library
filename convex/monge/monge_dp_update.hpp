#pragma once
#include "convex/smawk.hpp"

// newdp[j] = min_{0 <= i < j} dp[i] + f(i, j)
template <typename T, typename F>
vc<T> monge_dp_update(int N, vc<T>& dp, F f) {
  assert(len(dp) == N + 1);

  auto select = [&](int i, int j, int k) -> int {
    // row i corresponds to destination i.
    // valid source columns are k < i.
    if (i <= k) return j;
    return (dp[j] + f(j, i) > dp[k] + f(k, i) ? k : j);
  };

  vc<int> I = smawk(N + 1, N + 1, select);

  vc<T> newdp(N + 1, infty<T>);
  FOR(j, N + 1) {
    int i = I[j];
    if (i < j) chmin(newdp[j], dp[i] + f(i, j));
  }
  return newdp;
}