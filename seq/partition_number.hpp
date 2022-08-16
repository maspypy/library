#include "poly/fps_inv.hpp"

template <typename T>
vc<T> partition_number(int N) {
  ll M = sqrt(N) + 10;
  vc<T> f(N + 1);
  FOR3(x, -M, M) {
    ll d = x * (3 * x - 1) / 2;
    if (d > N) continue;
    f[d] += (x % 2 == 0 ? 1 : -1);
  }
  return fps_inv<T>(f);
}

// n を k 個に分割する方法 P[n][k] のテーブル
template <typename T>
vvc<T> partition_number_2d(int n_max, int k_max) {
  vv(T, dp, n_max + 1, k_max + 1);
  dp[0][0] = 1;
  FOR3(n, 1, n_max + 1) FOR3(k, 1, k_max + 1) {
    // min = 1
    dp[n][k] += dp[n - 1][k - 1];
    // min >= 2
    if (n >= k) dp[n][k] += dp[n - k][k];
  }
  return dp;
}
