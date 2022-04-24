
template <typename STRING>
ll longest_common_subsequence(STRING& A, STRING& B) {
  int N = len(B);
  vc<int> dp(N + 1);
  for (auto&& a: A) {
    FOR_R(i, N) if (a == B[i]) chmax(dp[i + 1], dp[i] + 1);
    FOR(i, N) chmax(dp[i + 1], dp[i]);
  }
  return dp[N];
}

/*
復元もする LCS dp。
(A[i], B[j]) を使うような (i, j) のペアの vector を返す。
*/
template <typename STRING>
vc<pair<int, int>> longest_common_subsequence_restore(STRING& A, STRING& B) {
  int N = len(A), M = len(B);
  vv(int, DP, N + 1, M + 1);
  FOR(i, N) {
    auto& dp = DP[i];
    auto& newdp = DP[i + 1];
    newdp = dp;
    FOR(j, M) {
      chmax(newdp[j + 1], newdp[j]);
      if (A[i] == B[j]) chmax(newdp[j + 1], dp[j] + 1);
    }
  }
  vc<pair<int, int>> res;
  int n = N, m = M;
  while (DP[n][m]) {
    if (DP[n][m] == DP[n - 1][m]) { --n; }
    elif (DP[n][m] == DP[n][m - 1]) { --m; }
    else {
      --n, --m;
      res.eb(n, m);
    }
  }
  reverse(all(res));
  return res;
}
