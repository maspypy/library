// dp[i][j] = lcp(S[i:], T[j:])
vvc<int> all_pair_lcp(string& S, string& T) {
  int N = len(S), M = len(T);
  vv(int, dp, N, M);
  FOR_R(i, N) FOR_R(j, M) {
    if (S[i] != T[j]) continue;
    dp[i][j] = 1 + (i + 1 < N && j + 1 < M ? dp[i + 1][j + 1] : 0);
  }
  return dp;
}