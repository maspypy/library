
// O(N) time
// https://oeis.org/A003000
template <typename mint>
vc<mint> count_unbordered_string(int N, int sigma) {
  // 全体から border を持つものを引く, minimum border = unbordered
  // vc<mint> dp(N + 1);
  // FOR(n, N + 1) {
  //   dp[n] = mint(sigma).pow(n);
  //   FOR(i, 1, n / 2 + 1) dp[n] -= dp[i] * mint(sigma).pow(n - 2 * i);
  // }
  // これを O(N) に

  vc<mint> dp(N + 1);
  dp[0] = 1;
  FOR(n, 1, N + 1) {
    if (n % 2 == 0) dp[n] = mint(sigma) * dp[n - 1] - dp[n / 2];
    if (n % 2 == 1) dp[n] = mint(sigma) * dp[n - 1];
  }
  return dp;
}
