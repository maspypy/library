
// 誤差 O(N^{-6})
long double Harmonic(ll N) {
  using Re = long double;
  static vc<Re> dp(1000);
  static bool prepare = 0;
  if (!prepare) {
    prepare = 1;
    FOR(n, 1, 1000) dp[n] = dp[n - 1] + Re(1) / n;
  }
  if (N < 1000) return dp[N];
  Re x = logl(N);
  Re gamma = 0.577215664901532860606512090;
  x += gamma;
  x += 0.5 / N;
  x -= 1.0 / 12 / N / N;
  x += 1.0 / 120 / N / N / N / N;
  return x;
}