// dp[i] := 第 i 項で終わる lis 長の最大値（[1, LIS]）
template <typename T, bool strong = true>
pair<int, vc<int>> longest_increasing_subsequence(vector<T> A) {
  const int N = A.size();
  vc<T> dp(N, infty<T>);
  int lis = 0;
  vc<int> lis_rank(N);
  FOR(i, N) {
    int j = (strong ? LB(dp, A[i]) : UB(dp, A[i]));
    dp[j] = A[i];
    lis_rank[i] = j + 1;
    chmax(lis, j + 1);
  }
  return {lis, lis_rank};
}
