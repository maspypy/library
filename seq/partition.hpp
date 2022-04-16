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
