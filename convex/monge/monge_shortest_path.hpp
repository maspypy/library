#pragma once

#include "convex/larsch.hpp"

// dp[r] = min_{0 <= l < r} dp[l] + f(l, r)
// 遷移回数を問わない
template <typename T, typename F>
vc<T> monge_shortest_path(int N, F f) {
  vc<T> dp(N + 1, infty<T>);
  dp[0] = 0;

  auto g = [&](int i, int j) -> T {
    ++i;
    if (i <= j) return infty<T>;
    return dp[j] + f(j, i);
  };

  LARSCH<T, decltype(g)> larsch(N, g);
  FOR(r, 1, N + 1) {
    int l = larsch.get_argmin();
    dp[r] = dp[l] + f(l, r);
  }
  return dp;
}
