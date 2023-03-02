int digit_sum(u64 x) {
  const int K = 100'000;
  static vc<int> dp(K);
  if (dp[1] == 0) { FOR(x, 1, K) dp[x] = dp[x / 10] + (x % 10); }
  int res = 0;
  while (x) {
    res += dp[x % K];
    x /= K;
  }
  return res;
}