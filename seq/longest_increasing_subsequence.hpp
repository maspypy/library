// dp[i] := 第 i 項で終わる lis 長の最大値（[1, LIS]）
template <typename T, bool strong = true>
pair<int, vc<int>> longest_increasing_subsequence_dp(vector<T> A) {
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

template <typename T, bool strong = true>
vc<int> longest_increasing_subsequence(vector<T> A) {
  const int N = A.size();
  auto [lis, dp] = longest_increasing_subsequence_dp<T, strong>(A);
  vc<int> I;
  FOR(i, N) if (dp[i] == lis) {
    I.eb(i);
    break;
  }
  FOR(lis - 1) {
    int i = I.back();
    FOR_R(j, i) {
      bool ok = (dp[j] == dp[i] - 1) && (strong ? (A[j] < A[i]) : (A[j] <= A[i]));
      if (ok) {
        I.eb(j);
        break;
      }
    }
  }
  assert(len(I) == lis);
  reverse(all(I));
  return I;
}
